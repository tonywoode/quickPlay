unit ZMMsgStr;

(*
  ZMMsgStr.pas - message string handler
  TZipMaster VCL by Chris Vleghert and Eric W. Engler
  v1.79
  Copyright (C) 2005  Russell Peters


  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License (licence.txt) for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  contact: problems AT delphizip DOT org
  updates: http://www.delphizip.org

  modified 2009-10-24
---------------------------------------------------------------------------*)

{$INCLUDE ZipConfig.inc} 
{$INCLUDE '.\ZipVers.inc'}
 
interface

uses
  Classes;

type
  TZipStrEvent = procedure(Ident: Integer; var DefStr: String) of object; 

var
  OnZipStr: TZipStrEvent;

{$IFNDEF VERD6up}
type
  pCardinal = ^Cardinal;

{$ENDIF}


function ZipLoadStr(id: Integer): String;
function ZipFmtLoadStr(Id: Integer; const Args: array of const): String;

// < '*' = Auto, '' = default US,  language  (number = language id)
function SetZipMsgLanguage(const zl: String): String;
// get language at index (<0 - default, 0 - current)
function GetZipMsgLanguage(idx: Integer): String;
// info (-1) = language id, 0 = name, other values as per windows LOCALE_
function GetZipMsgLanguageInfo(Index: Integer; info: Cardinal): String;

function LanguageIdent(const seg: AnsiString): AnsiString;
function LocaleInfo(loc: Integer; info: Cardinal): String;

implementation

uses
  Windows, SysUtils, ZMUtils, ZipMsg, ZMDefMsgs, ZMExtrLZ77;//, ZMCompat;

type
  TResBlock = array of Word;
{
type
  W_CHR = packed record
    case Boolean of
      True: (w: Word;
      );
      False: (cl: AnsiChar;
        ch: AnsiChar;
      );
  end;
}
const
  lchars = ['A'..'Z', 'a'..'z', '0'..'9', '_'];
  Uchars = ['a'..'z'];
  Digits = ['0'..'9'];

var
  DefRes: TResBlock;
  SelRes: TResBlock;
  SelId:  Cardinal;
  SelName: String;


function LanguageIdent(const seg: AnsiString): AnsiString;
var
  i: Integer;
  c: AnsiChar;
begin
  Result := '';
  for i := 1 to length(seg) do
  begin
    c := seg[i];
//{$IFDEF UNICODE}
//    if not CharInSet(c, lchars) then
//{$ELSE}
//    if not (c in lchars) then
//{$ENDIF}
    if not (c in lchars) then
    begin
      if (Result <> '') or (c <> ' ') then
        break;
    end
    else
    begin
//      if (Result = '') and //CharInSet(c, ['0'..'9']) then
//{$IFDEF UNICODE}
//          CharInSet(c, ['0'..'9']) then
//{$ELSE}
//          (c in digits) then
//{$ENDIF}
      if (Result = '') and (c in digits) then
        break;
      if c in Uchars then
        c := AnsiChar(Ord(c) - $20);
      Result := Result + c;
    end;
  end;
//  Result := Uppercase(Result);
end;

// format is
// id: word, data_size: word, label_size: word, label: char[], data: byte[];... ;0
// stream at id
function LoadFromStream(var blk: TResBlock; src: TStream): Cardinal;
var
  sz:  array [0..2] of Word; // id, dsize, nsize
  szw: Integer;
  so:  TMemoryStream;
  r:   Integer;
begin
  blk := Nil;
  Result := 0;
  if src.Read(sz[0], 3 * sizeof(Word)) <> (3 * sizeof(Word)) then
    exit;
  if src.Size < (sz[1] + sz[2] + (3 * sizeof(Word))) then
    exit;
  src.Position := src.Position + sz[2]; // skip name
  try
    so := TMemoryStream.Create;
    r := LZ77Extract(so, src, sz[1]);
    //    Assert(r = 0, 'error extracting strings');
    if (r = 0) and (so.Size < 50000) then
    begin
      szw := (Integer(so.Size) + (sizeof(Word) - 1)) div sizeof(Word); 
      SetLength(blk, szw + 1);
      so.Position := 0;
      if so.Read(blk[0], so.Size) = so.Size then
      begin
        blk[szw] := Word(-1);
        Result := sz[0];
      end
      else
        blk := nil;
    end;
  finally
    FreeAndNil(so);
  end;
end;


// format is
// id: word, data_size: word, label_size: word, label: char[], data: byte[];... ;0
// positions stream to point to id
// segname has identifier terminated by ':'
function FindInStream(src: TStream; var segname: AnsiString; var lid: Word):
    Boolean;
var
  c: AnsiChar;
  i: Word;
//  l: AnsiString;
  p: Int64;
  s: AnsiString;
  seg: AnsiString;
  ss: Int64;
  uname: AnsiString;
  w: Word;
  w3: array [0..2] of Word;
begin
  Result := False;
  if not assigned(src) then
    exit;
  seg := LanguageIdent(segname);
  if (Length(seg) < 2) and (lid = 0) then
    exit;
  uname := '';
  for i := 1 to Length(segname) do
  begin
    c := segname[i];
    if c in Uchars then
      c := AnsiChar(Ord(c) - $20);
    uname := uname + c;
  end;
  p := src.Position;
  ss := src.Size - ((3 * sizeof(Word)) + 2); //id + dlen + nlen + min 2 chars
  while (not Result) and (p < ss) do
  begin
    src.Position := p;
    src.ReadBuffer(w3[0], 3 * sizeof(Word));  // id, dsize, nsize
    w := w3[2];     // name size
    if w > 0 then
    begin
      SetLength(s, w);
      src.ReadBuffer(s[1], w);   // read name
    end;
    if lid = 0 then
    begin
      // find by name
      Result := False;
//      l := '';
      for i := 1 to w do
      begin
        c := s[i];
        if not (c in lchars) then
          break;
        if i > Length(uname) then
        begin
          Result := False;
          break;
        end;
        if c in Uchars then
          c := AnsiChar(Ord(c) - $20);
        Result := c = uname[i];
        if not Result then
          break;
//        if CharInSet(c, lchars) then
//{$IFDEF UNICODE}
//        if CharInSet(c, lchars) then
//{$ELSE}
//          if (c in lchars) then
//{$ENDIF}
//            l := l + c
//          else
//            break;
      end;
//      Result := AnsiCompareText(l, segname) = 0;
    end
    else
      Result := (lid = w3[0]) or ((lid < $400) and ((w3[0] and $3FF) = lid));
    if not result then
      p := src.Position + w3[1];  // skip data
  end;
  if Result then
  begin
    Segname := s;
    lid := w3[0];
    src.Position := p;
  end;
end;


// format is
// id: word, data_size: word, label_size: word, label: char[], data: byte[];... ;0
// positions stream to point to id
// segname has identifier terminated by ':'
function IdInStream(src: TStream; var idx: Cardinal;  var lang: String): Boolean;
var
  p, ss: Int64;
  w3:  array [0..2] of Word; // id, dsize, nsize
  s:   AnsiString;
begin
  Result := False;
  if (idx < 1) or not assigned(src) then
    exit;
  p := src.Position;
  ss := src.Size - ((3 * sizeof(Word)) + 20); //id + dlen + nlen + 20 bytes
  if p > ss then
    exit;
  repeat
    src.ReadBuffer(w3[0], 3 * sizeof(Word));  // id, dsize, nsize
    if idx <= 1 then
      break;
    dec(idx);
    p := src.Position + w3[1] + w3[2];        // after name + data
    if p < ss then
      src.Position := p
    else
      exit;
  until False;
  SetLength(s, w3[2]);
  src.ReadBuffer(s[1], w3[2]);   // read name
  lang := String(s);
  idx := w3[0];
  src.Position := p;
  Result := True;
end;
 
{$IFNDEF VERD6up}
function TryStrToInt(s: String; var v: Integer): Boolean;
begin
  if (s = '') or not (s[1] in ['0'..'9','$']) then
    Result := False
  else
  begin
    Result:= true;
    try
      v := StrToInt(s);
    except
      on EConvertError do
        Result := false;
    end;
  end;
end;
{$ENDIF}

function SetZipMsgLanguage(const zl: String): String;
var
  hFound: THandle;
  inst: cardinal;
  res: TResourceStream;
  id:  Word;
  i:   Integer;
  ln:  AnsiString;
begin
  Res := Nil;
  SelRes := Nil;   // reset to default
  SelId := 0;
  SelName := '';
  Result := '';
  id := 0;
  ln := LanguageIdent(AnsiString(zl));
  if (length(ln) < 2) then
    if zl = '*' then
      id := GetUserDefaultLCID
    else
    begin
      if (not TryStrToInt(zl, i)) or (i <= 0) or (i > $0FFFF) then
        exit;
      id := Cardinal(i);
    end;
  if (ln = 'US') or (id = $0409) then  // use default US
    exit;
  inst := HInstance;
  hFound := FindResource(inst, Pchar(DZRES_Str), RT_RCData);
  if (hFound = 0) and ModuleIsLib then
  begin
    inst := MainInstance;
    hFound := FindResource(inst, Pchar(DZRES_Str), RT_RCData);
  end;
//  if FindResource(HInstance, Pchar(DZRES_Str), RT_RCData) <> 0 then
  if hFound <> 0 then
    try
      res := TResourceStream.CreateFromID(inst, DZRES_Str, RT_RCData);
      if assigned(res) and FindInStream(res, ln, id) then
      begin
        SelId := LoadFromStream(SelRes, res);
        if SelId > 0 then
        begin
          Result := String(ln);
          SelName := String(ln);
        end;
      end;
    finally
      FreeAndNil(res);
    end;
end;

function LocaleInfo(loc: Integer; info: Cardinal): String;
var
  s:   String;
begin
  if (loc <= 0) or (loc = $400) then
    loc := LOCALE_USER_DEFAULT;
  SetLength(s, 1024); 
  GetLocaleInfo(loc and $FFFF, info, Pchar(s), 1023);
  Result := Pchar(s);  // remove any trailing #0
end;
                                                                        
// get language at index (<0 - default, 0 - current)
// info (-1) = language id, 0 = name, other values as per windows LOCALE_
function GetZipMsgLanguageInfo(Index: Integer; info: Cardinal): String;
const
  LOCALE_SLANGDISPLAYNAME = $0000006f;
var
  res: TResourceStream;
  id:  Cardinal;
  s:   String;
begin
  id := $0409;
  Result := 'US: default';  // default US English     
  if Index = 0 then
    if assigned(SelRes) then
    begin
      Result := SelName;
      id := SelID;
    end;
  if Index > 0 then
  begin
    Res := Nil;
    Result := '><';
    Id := Index and $FF;
    try
      if FindResource(HInstance, Pchar(DZRES_Str), RT_RCData) <> 0 then
      begin
        res := TResourceStream.CreateFromID(HInstance, DZRES_Str, RT_RCData);
        if assigned(res) and IdInStream(res, Id, s) then
          Result := s;
      end //;              
      else
      if ModuleIsLib and (FindResource(MainInstance, Pchar(DZRES_Str), RT_RCData) <> 0) then
      begin
        res := TResourceStream.CreateFromID(MainInstance, DZRES_Str, RT_RCData);
        if assigned(res) and IdInStream(res, Id, s) then
          Result := s;
      end;
    finally
      FreeAndNil(res);
    end;
  end;
  if Result <> '><' then
  begin
    if info = 0 then
      Result := '$' + IntToHex(id, 4)
    else
    begin
    if info <> Cardinal(-1) then
      Result := LocaleInfo(id, info)
    else
      Result := SelName;
    end;
  end;
end;

// get language at index (<0 - current, 0 - default, >0 - index)
function GetZipMsgLanguage(idx: Integer): String;
begin
  Result := GetZipMsgLanguageInfo(idx, Cardinal(-1));
end;


function FindRes(const blk: TResBlock; id: Integer): String;
var
  fid, rid: Integer;
  DatSiz, HedSiz: Cardinal;
  sz:  Cardinal;
  l:   Cardinal;
  bp, hp: Integer;
  ws:  Widestring;
begin
  Result := '';
  fid := id div 16;
  try
    bp := 0;
    while (bp + 9) < HIGH(Blk)  do
    begin
      bp := (bp + 1) and $7fffE;  // dword align
      //      DatSiz := (blk[bp+1] shl 16) + blk[bp];
      //      HedSiz := (blk[bp+3] shl 16) + blk[bp+2];
      DatSiz := pCardinal(@blk[bp])^;
      HedSiz := pCardinal(@blk[bp + 2])^;
      if (HedSiz + DatSiz) < 8 then
        break;
//      Assert((HedSiz + DatSiz) >= 8, 'header error');
      sz := (HedSiz + DatSiz) - 8;
      hp := bp + 4;
      inc(bp, 4 + (sz div 2));
      if blk[hp] <> $ffff then
        continue;  // bad res type
      if blk[hp + 1] <> 6 then
        continue;      // not string table
      if blk[hp + 2] <> $ffff then
        continue;
      rid := pred(blk[hp + 3]);
      if fid <> rid then
        continue;
      rid := rid * 16;
      inc(hp, (HedSiz - 8) div 2);
      ws := '';
      while rid < id do
      begin
        l := blk[hp];
        inc(hp, l + 1);
        inc(rid);
      end;
      l := blk[hp];
      if l <> 0 then
      begin
        SetLength(ws, l);
        move(blk[hp + 1], ws[1], l * sizeof(Widechar));
        Result := ws;
        Result := StringReplace(Result, #10, #13#10, [rfReplaceAll]);
        break;
      end;
      break;
    end;
  except
    Result := '';
  end;
end;

{$IFNDEF USE_COMPRESSED_STRINGS}
function FindConst(id: Integer): String;
var
  p: pResStringRec;

  function Find(id: Integer): pResStringRec;
  var
    wi: Word;
    i:  Integer;
  begin
    Result := Nil;
    wi := Word(id);
    for i := 0 to high(ResTable) do
      if ResTable[i].i = wi then
      begin
        Result := ResTable[i].s;
        break;
      end;
  end;

begin  {FindConst}
  Result := '';
  if id < 10000 then
    exit;
  p := find(id);
  if p <> Nil then
    Result := LoadResString(p);
end;
{$ENDIF}

// format is
// id: word, data_size: word, label_size: word, label: char[], data: byte[];... ;0
function LoadCompressedDef(const src): Integer;
var
  ms:  TMemoryStream;
  w:   Word;
  pw:  pWord;
begin
  Result := -1;
  pw := @src;
  if pw^ = $0409 then
  begin
    inc(pw);
    w := pw^;
    inc(pw);
    inc(w, pw^);
    inc(w, (3 * sizeof(Word)));
    try
      ms := TMemoryStream.Create;
      ms.Write(src, w);
      ms.Position := 0;
      Result := LoadFromStream(DefRes, ms);
    finally
      FreeAndNil(ms);
    end;
  end;
end;

function ZipLoadStr(id: Integer): String;
var
  d: String;
  tmpOnZipStr: TZipStrEvent;
begin
  Result := '';
  if SelRes <> Nil then
    Result := FindRes(SelRes, id);
{$IFDEF USE_COMPRESSED_STRINGS}
  if Result = '' then
  begin
    if DefRes = Nil then
      LoadCompressedDef(CompBlok);
    Result := FindRes(DefRes, id);
  end;
{$ELSE}
  if Result = '' then
    Result := FindConst(id);
{$ENDIF}
  //  if Result = '' then
  //    Result := loadStr(id);
  tmpOnZipStr := OnZipStr;
  if assigned(tmpOnZipStr) then
  begin
    d := Result;
    tmpOnZipStr(id, d);
    if d <> '' then
      Result := d;
  end;
  if Result = '' then
    Result := 'Resource missing for ' + IntToStr(id);
end;

function ZipFmtLoadStr(Id: Integer; const Args: array of const): String;
begin
  Result := ZipLoadStr(Id);

  if Result <> '' then
    Result := Format(Result, Args);
end;


initialization
  OnZipStr := Nil;
  DefRes := Nil;
  SelRes := Nil; 

finalization
  DefRes := Nil;      // force destruction
  SelRes := Nil;

end.

