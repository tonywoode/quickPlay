unit Idents;

(*
  Idents.pas - reader for ZipMsgUS.rc and ZipMsg.h
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

  modified 2005-11-05
---------------------------------------------------------------------------*)

interface

uses
  classes, windows, ZipMsg;

const
  MinID = 16 * (DT_Language div 16);
  MaxID = 15 + (16 * (TM_SystemError div 16));
  NamedRes = $40000000;
  UnknownStr = $20000000;

//const
//  MIN_ID = 10095;
//  MAX_ID = 11630;

const
  Err_Ok  = 0;
  Err_Nothing = 1;
  Err_Bad = 2;
  Err_NoIDs = 3;
  Err_BadIDs = 4;
  Err_NoStrings = 5;
  Err_BadStrings = 6;
  Err_Unknown = -1;

type
  TIdFlag = (idNone, idMissing, idDiscard, idActive, idShared, idSfx);
  TIdFlags = set of TIdFlag;

  //  PIdEntry = ^TIdEntry;

  TIdEntry = class (TObject)
  PRIVATE
    fId:  Integer;
    fFlag: TIdFlag;
    fMsg: Widestring;
  PUBLIC
    destructor Destroy; OVERRIDE;
    property Id: Integer READ fId WRITE fId;
    property Flag: TIdFlag READ fFlag WRITE fFlag;
    property Msg: Widestring READ fMsg WRITE fMsg;
  end;

type
  TIdentifiers = class
  PRIVATE
    fList: TStringList;
    function GetFlag(idx: Integer): TIdFlag;
    function GetId(idx: Integer): Integer;
    function GetMsg(idx: Integer): Widestring;
    function GetName(idx: Integer): String;
    procedure SetFlag(idx: Integer; const Value: TIdFlag);
    procedure SetId(idx: Integer; const Value: Integer);
    procedure SetMsg(idx: Integer; const Value: Widestring);
    procedure SetName(idx: Integer; const Value: String);
    function GetCount: Integer;
  PROTECTED
    procedure Clear;
    function Renumbered(id: Integer): Widestring;
//    function WriteToStream(dest: TStream; what: TidFlags;
//      wid: Boolean): Integer;
  PUBLIC
    constructor Create;
    destructor Destroy; OVERRIDE;
    function LoadHFile(const f: String): Integer;
    function ReadRESFile(const f: String): Integer;
    function ReadRCFile(const f: String; def: Boolean): Integer;
//    function SaveAsBlock(strm: TStream; wid: Boolean): Integer;
    procedure EmptyMsgs;
    function IndexAt(n: Integer; what: TidFlags): Integer;
    function IndexOfId(id: Integer): Integer;
    function NameOfId(id: Integer): String;
    function MsgOfId(id: Integer): String;
    function IndexOfName(const n: String): Integer;
    function CountOf(flgs: TIdFlags): Integer;
    function AddId(const n: String; id: Integer): Integer;
    property Count: Integer READ GetCount;
    property Flag[idx: Integer]: TIdFlag READ GetFlag WRITE SetFlag;
    property Id[idx: Integer]: Integer READ GetId WRITE SetId;
    property Name[idx: Integer]: String READ GetName WRITE SetName;
    property Msg[idx: Integer]: Widestring READ GetMsg WRITE SetMsg;
  end;

implementation

uses
  SysUtils, Main;

procedure Show(const s: String);
begin
  Form1.Show(s);
end;

{ TIdentifiers }

function TIdentifiers.AddId(const n: String; id: Integer): Integer;
var
  obj: TIdEntry;
begin
  obj := TIdEntry.Create;
  obj.Id := id;
  obj.Flag := idActive;
  obj.Msg := '';
  Result := fList.AddObject(n, obj);
end;

procedure TIdentifiers.Clear;
var
  i: Integer;
  obj: TIdEntry;
begin
  for i := 0 to pred(fList.Count) do
  begin
    obj := TIdEntry(fList.Objects[i]);
    if assigned(obj) then
    begin
      fList.Objects[i] := Nil;
      obj.Msg := '';
      obj.Free;
    end;
  end;
  fList.Clear;
end;

function TIdentifiers.CountOf(flgs: TIdFlags): Integer;
var
  obj: TIdEntry;
  i:   Integer;
begin
  Result := 0;
  for i := 0 to pred(fList.Count) do
  begin
    obj := TIdEntry(fList.Objects[i]);
    if assigned(obj) and (obj.Flag in flgs) and (obj.Msg <> '') then
      Result := Result + 1;
  end;
end;

constructor TIdentifiers.Create;
begin
  fList := TStringList.Create;
end;

destructor TIdentifiers.Destroy;
begin
  Clear;
  FreeAndNil(fList);
  inherited;
end;

procedure TIdentifiers.EmptyMsgs;
var
  i: Integer;
  obj: TIdEntry;
begin
  for i := 0 to pred(fList.Count) do
  begin
    obj := TIdEntry(fList.Objects[i]);
    if assigned(obj) then
    begin
      obj.Msg := '';
    end;
  end;
end;

function TIdentifiers.GetCount: Integer;
begin
  Result := fList.Count;
end;

function TIdentifiers.GetFlag(idx: Integer): TIdFlag;
var
  obj: TIdEntry;
begin
  Result := idNone;
  if (idx >= 0) and (idx < fList.Count) then
  begin
    obj := TIdEntry(fList.Objects[idx]);
    if assigned(obj) then
      Result := obj.Flag;
  end;
end;

function TIdentifiers.GetId(idx: Integer): Integer;
var
  obj: TIdEntry;
begin
  Result := 0;
  if (idx >= 0) and (idx < fList.Count) then
  begin
    obj := TIdEntry(fList.Objects[idx]);
    if assigned(obj) then
      Result := obj.Id;
  end;
end;

function TIdentifiers.GetMsg(idx: Integer): Widestring;
var
  obj: TIdEntry;
begin
  Result := '';
  if (idx >= 0) and (idx < fList.Count) then
  begin
    obj := TIdEntry(fList.Objects[idx]);
    if assigned(obj) then
      Result := obj.Msg;
  end;
end;

function TIdentifiers.GetName(idx: Integer): String;
begin
  Result := '';
  if (idx >= 0) and (idx < fList.Count) then
  begin
    Result := fList[idx];
  end;
end;

function TIdentifiers.IndexOfId(id: Integer): Integer;
var
  obj: TIdEntry;
  i:   Integer;
begin
  Result := -1;
  for i := 0 to pred(fList.Count) do
  begin
    obj := TIdEntry(fList.Objects[i]);
    if assigned(obj) and (obj.Id = id) then
    begin
      Result := i;
      break;
    end;
  end;
end;

function TIdentifiers.IndexOfName(const n: String): Integer;
begin
  Result := fList.IndexOf(n);
end;

function TIdentifiers.LoadHFile(const f: String): Integer;
var
  idList: TStringList;
  i, j, v, ix, slen: Integer;
  s, sn, sv: String;
  sw:  Char;
begin
  Result := 0;
  try
    Clear;
    IdList := TStringList.Create;
    IdList.LoadFromFile(f);
    // clean file
    if IdList.Count < 190 then
    begin
      Result := -1;
      exit;
    end;
    for i := 0 to pred(IdList.Count) do
    begin
      s := trim(IdList[i]);
      slen := length(s);
      if (slen < 15) or (Uppercase(copy(s, 1, 8)) <> '#DEFINE ') then
        continue;
      sn := '';
      j := 8;
      while j <= slen do
      begin
{$ifdef UNICODE}
        if CharInSet(s[j], [#9, ' ']) then
{$else}
        if s[j] in [#9, ' '] then
{$endif}
        begin
          if sn <> '' then
            break;
        end
        else
          sn := sn + s[j];
        inc(j);
      end;
      sv := '';
      while j <= slen do
      begin
{$ifdef UNICODE}
        if CharInSet(s[j], [#9, ' ']) then
{$else}
        if s[j] in [#9, ' '] then
{$endif}
        begin
          if sv <> '' then
            break;
        end
        else
          sv := sv + s[j];
        inc(j);
      end;
      v := StrToIntDef(sv, -1);
      if (sn <> '') and (v >= MINID) and (v <= MAXID) then
      begin
        ix := AddId(sn, v);
        Inc(Result);
        // check for switch
        sw := #0;
{$ifdef UNICODE}
        while (j <= (slen - 3)) and CharInSet(s[j], [#9, ' ']) do
{$else}
        while (j <= (slen - 3)) and (s[j] in [#9, ' ']) do
{$endif}
          inc(j);
        if (j <= (slen - 2)) and (s[j] = '/') and (s[j + 1] = '/') then
          sw := s[j + 2];
        case sw of
          '!':
            Flag[ix] := idShared;
          '*':
            Flag[ix] := idSFX;
          '-':
            Flag[ix] := idDiscard;
          else
            Flag[ix] := idActive;
        end;
      end;
    end;
  finally
    FreeAndNil(idList);
  end;
end;
(*
// writes id, string; id, string; ...       in order
// returns size written  (words)
function TIdentifiers.WriteToStream(dest: TStream; what: TidFlags;
  wid: Boolean): Integer;
var
  id, ix: Integer;
  w:   Word;
  ws:  Widestring;
  s:   String;
begin
  Result := 0;
  for id := MinID to MaxID do
  begin
    ix := IndexOfId(id);
    if (ix < 0) or not (Flag[ix] in what) then
      continue;
    ws := Msg[ix];
    if ws = '' then
    begin
      ws := Renumbered(id);
      if ws = '' then
        continue;
    end;
    w := Word(id);
    dest.WriteBuffer(w, sizeof(Word)); // id
    Inc(Result);
    if wid then
    begin
      w := length(ws);
      dest.WriteBuffer(w, sizeof(w));  // length + wide
      dest.Write(ws[1], w * 2);
      inc(Result, 1 + w);
    end
    else
    begin
      s := ws;  // convert to Ansi
      w := length(s);
      if (w and 1) <> 0 then
        s := s + #0;
      w := (w + 1) div 2;   // calc words
      w := w or $8000;      // set narrow
      dest.WriteBuffer(w, sizeof(w));  // length + wide
      w := w and $1ff;
      dest.Write(s[1], w * 2);
      inc(Result, 1 + w);
    end;
  end;
end;  *)

procedure TIdentifiers.SetFlag(idx: Integer; const Value: TIdFlag);
var
  obj: TIdEntry;
begin
  if (idx >= 0) and (idx < fList.Count) then
  begin
    obj := TIdEntry(fList.Objects[idx]);
    if assigned(obj) then
      Obj.Flag := Value;
  end;
end;

procedure TIdentifiers.SetId(idx: Integer; const Value: Integer);
var
  obj: TIdEntry;
begin
  if (idx >= 0) and (idx < fList.Count) then
  begin
    obj := TIdEntry(fList.Objects[idx]);
    if assigned(obj) then
      Obj.Id := Value;
  end;
end;

procedure TIdentifiers.SetMsg(idx: Integer; const Value: Widestring);
var
  obj: TIdEntry;
begin
  if (idx >= 0) and (idx < fList.Count) then
  begin
    obj := TIdEntry(fList.Objects[idx]);
    if assigned(obj) then
      Obj.Msg := Value;
  end;
end;

procedure TIdentifiers.SetName(idx: Integer; const Value: String);
begin
  if (idx >= 0) and (idx < fList.Count) then
  begin
    fList[idx] := Value;
  end;
end;

function TIdentifiers.Renumbered(id: Integer): Widestring;
var
  obj: TIdEntry;
  i:   Integer;
begin
  Result := '';
  i := 0;
  case id of
    ZB_Ok:
      i := 10152;//PW_Ok;
    ZB_Cancel:
      i := 10153;//PW_Cancel;
    ZB_CancelAll:
      i := 10157;//PW_CancelAll;
    ZB_Abort:
      i := 10158;//PW_Abort;
  end;
  if i > 0 then
  begin
    i := IndexOfId(i);
    if i > 0 then
    begin
      obj := TIdEntry(fList.Objects[i]);
      if assigned(obj) then
        Result := obj.Msg;
    end;
  end;
end;

function TIdentifiers.ReadRESFile(const f: String): Integer;
var
  fs:  TFileStream;
  head: array of Word;
  sbuf: array of Char;
  c:   array [0..1] of Cardinal;
  dat, rid, sz: Cardinal;
  i, j, l: Cardinal;
  ix:  Integer;
  fsz: Int64;
  ws:  Widestring;
  s:   String;
begin
  Result := 0;
  EmptyMsgs;
  fs := Nil;
  try
    fs := TFileStream.Create(f, fmOpenRead);
    fsz := fs.Size;
    setLength(head, 100);
    while (fs.Position + 8) < fsz do
    begin
      fs.Position := (fs.Position + 3) and $7ffffffc;  // dword align
      fs.Read(c[0], 8);
      sz := c[1] + c[0] - 8;
      if High(head) < Integer(sz div 2) then
        SetLength(head, (sz div 2) + 8);
      fs.Read(head[0], sz);
      if head[0] <> $ffff then
      begin
        Result := -1;
        Show('bad res type');
        continue;
      end;
      if head[1] <> 6 then
        continue;      // not string table
      if head[2] <> $ffff then
      begin
        Result := Result or NamedRes;
        Show('named ids');
        continue;
      end;
      rid := pred(head[3]) * 16;
      dat := (c[1] - 8) div 2;
      ws := '';
      j := 0;
      for i := 0 to 15 do
      begin
        l := head[dat + j];
        inc(j);
        if l < 1 then
          ws := ''
        else
        begin
          SetLength(ws, l);
          move(head[dat + j], ws[1], l * sizeof(Widechar));
          inc(j, l);
          ix := IndexOfId(rid + i);
          if ix < 0 then  // missing
          begin
            Result := Result or UnknownStr;
            s := '??_' + IntToStr(rid + i);
            ix := AddID(s, rid + i);
            Flag[ix] := idMissing;
          end;
          Msg[ix] := ws;
          inc(Result);
        end;
      end;
    end;
  finally
    head := Nil;
    sbuf := Nil;
    FreeAndNil(fs);
  end;
end;
 (*
// tot, siz1, tbl1, tbl2, 0
function TIdentifiers.SaveAsBlock(strm: TStream; wid: Boolean): Integer;
var
  sz1, sz2: Integer;
  ms:  TMemoryStream;
  w:   Word;
begin
  Result := -1;
  if CountOf([idActive .. idSFX]) < 1 then
    exit;
  ms := TMemoryStream.Create;
  try
    sz1 := WriteToStream(ms, [idActive], wid);
    sz2 := WriteToStream(ms, [idShared, idSFX], wid);
    w := sz1 + sz2 + 2;   // total words excluding total size
    strm.WriteBuffer(w, sizeof(Word));
    Result := w + 1;
    w := sz1;
    strm.WriteBuffer(w, sizeof(Word));
    ms.Position := 0;
    strm.CopyFrom(ms, ms.Size);
    w := 0; // end mark
    strm.WriteBuffer(w, sizeof(Word));
  finally
    FreeAndNil(ms);
  end;
end;  *)

function TIdentifiers.MsgOfId(id: Integer): String;
var
  i: Integer;
begin
  i := IndexOfId(id);
  if i < 0 then
    Result := ''
  else
    Result := Msg[i]; // converts to Ansi
end;

function TIdentifiers.NameOfId(id: Integer): String;
var
  i: Integer;
begin
  i := IndexOfId(id);
  if i < 0 then
    Result := ''
  else
    Result := Name[i];
end;

function TIdentifiers.ReadRCFile(const f: String; def: Boolean): Integer;
var
  i, j, k, d, idx, p, pb, li: Integer;
  s, ident, uident, value: String;
  rcList: TStringList;
  ps:  Pchar;
  HasBegin: Boolean;
  c:   Char;
begin
  if Count < 190 then
  begin
    Show('no identifiers');
    Result := Err_NoIDs;
    exit;
  end;
  EmptyMsgs;
  Result := 0;
  HasBegin := False;
  rcList := Nil;
  try
    rcList := TStringList.Create;
    rcList.LoadFromFile(f);
    if rcList.Count < 150 then
    begin
      Show('invalid ' + f);
      Result := Err_NoStrings;
      exit;
    end;
    i := 0;
    while i < rcList.Count do
    begin
      s := trim(rcList[i]);
      inc(i);
{$ifdef UNICODE}
      if (length(s) < 7) or not CharInSet(s[1], ['A'..'Z', 'a'..'z', '_']) then
{$else}
      if (length(s) < 7) or not (s[1] in ['A'..'Z', 'a'..'z', '_']) then
{$endif}
      begin
        if (s = '') or ((s[1] <> '{') and (s[1] <> '}')) then
          continue;
        c := s[1];
        s := copy(s, 2, length(s) - 1);
        if c = '{' then
          s := 'BEGIN ' + s
        else
          break;
        //          s := 'END' + s;
      end;
      // s should be identifier, double quoted string
      j := length(s);
      if j > 25 then
        j := 25;
      k := 2;
{$ifdef UNICODE}
      while (k <= j) and CharInSet(s[k], ['A'..'Z', 'a'..'z', '0'..'9', '_']) do
{$else}
      while (k <= j) and (s[k] in ['A'..'Z', 'a'..'z', '0'..'9', '_']) do
{$endif}
        inc(k);
      if k < 4 then
        continue;
      ident := copy(s, 1, pred(k));
      uident := Uppercase(ident);
      if uident = 'END' then
        break;
      if not HasBegin then
      begin
        // does it have 'begin' after it
        li := length(ident);
        p := AnsiPos('//', s);
        if p < 1 then
          p := length(s);
        s := Trim(copy(s, li+1, p - (li+1)));
        pb := 0;
        if s <> '' then
        begin
        pb := AnsiPos('{', s);
        if pb = 0 then
          pb := AnsiPos('BEGIN', Uppercase(s));
        end;
        if (uident = 'STRINGTABLE') then
        begin
          // ignore up to and including begin
          if pb > 0 then
            HasBegin := true;
        end
        else
        begin
          if (uident = 'BEGIN') or (pb > 0) then
            HasBegin := true;
        end;
        continue;
      end;
      idx := IndexOfName(ident);
      if idx < 0 then
      begin
        Show('unknown identifier ' + s);
        idx := AddId(ident, 11630);
        Flag[idx] := idMissing;
        Result := Err_BadStrings;
        //        exit;
        continue;
      end;
      value := '';
      while (k < length(s)) and (s[k] <> '"') do
        inc(k);
      value := copy(s, k, length(s) - pred(k));
      if value[length(value)] <> '"' then
      begin
        Show('garbage at end of line ' + IntToStr(i) + ' ' + s);
        Result := Err_BadStrings;
        //        exit;
      end;
      if def then
      begin
        for d := 1 to length(Value) do
          if ord(Value[d]) > 126 then
          begin
            Result := Err_BadStrings;
            exit;
          end;
      end;
      ps := Pchar(value);
      s := AnsiExtractQuotedStr(ps, '"');
      Msg[idx] := s;
    end;
  finally
    FreeAndNil(rcList);
  end;
end;

function TIdentifiers.IndexAt(n: Integer; what: TidFlags): Integer;
begin
  for Result := 0 to Pred(Count) do
  begin
    if (Flag[Result] in what) and (Msg[Result] <> '') then
    begin
      if n = 0 then
        exit;
      dec(n);
    end;
  end;
  Result := -1;
end;

{ TIdEntry }

destructor TIdEntry.Destroy;
begin
  fMsg := '';
  inherited;
end;

end.
                
