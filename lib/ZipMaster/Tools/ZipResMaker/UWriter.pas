unit UWriter;

(*
  UWriter.pas - writer for message string units
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

  modified 2005-11-24
---------------------------------------------------------------------------*)

interface
 
uses
  classes, Main, Idents;

type
  WBlocks = array of Cardinal;

const
  MIN_ID = 10101;
  MAX_ID = 11620;

const
  Err_Ok = 0;
  Err_Nothing = 1;
  Err_Bad = 2;
  Err_NoIDs = 3;
  Err_BadIDs = 4;
  Err_NoStrings = 5;
  Err_BadStrings = 6;
  Err_Compression = 7;
  Err_Compile = 8;
  Err_Unknown = -1;

// CS?? compressed block All
// CX?? compressed shared and SFX
// MS?? strings ZipMaster only
// XS?? strings shared and SFX
type
  TUnitWriter = class(TObject) 
  private
    fIdents: TIdentifiers;
    fErr:  Integer;
    fposn: Integer;
    fBlock: WBlocks;
    function GetCSTot: Integer;
    function GetIDTot: Integer;
  protected
    procedure Show(const s: String);
    function FullPath(p: ZPaths; const fn: String): String;
    property Idents: TIdentifiers read fIdents;
    property Block: WBlocks read fBlock;
    property IDTot: Integer read GetIDTot;
    property CSTot: Integer read GetCSTot;
  public
    constructor Create;
    destructor Destroy; OVERRIDE;
    function Prepare: Integer;
    function WriteDefMsgs(const where: string): Integer;
    function WriteZipMsg(const where: string): integer;
    property Err: Integer read fErr write fErr;
  end;

procedure BackupFile(const where: string);
procedure RestoreFile(const where: string);     
function CompressRes(strm: TStream; const FName, lang: string): Integer;

implementation
                 
uses Windows, SysUtils, StrUtils, ZipCompLZ77;

function NormPasStr(const s: String): String;
var
  r: String;
  p: Integer;
begin
  Result := '';
  r := s;
  p := AnsiPos('\n', s);
  while p > 0 do
  begin
    Result := Result + AnsiQuotedStr(copy(r, 1, pred(p)), '''') + '#10';
    r := copy(r, p + 2, Length(r) - (p + 1));
    p := AnsiPos('\n', r);
  end;
  if r <> '' then
    Result := Result + AnsiQuotedStr(r, '''');
end;

function NormCStr(const s: String): String;
begin
  //  Result := AnsiReplaceStr(s, #10, '\n');
  Result := AnsiQuotedStr(s, '"');
end;

{ TUnitWriter }
                  
function TUnitWriter.GetCSTot: Integer;
begin
  Result := succ(High(Block));
end;


function TUnitWriter.GetIDTot: Integer;
begin
  Result := Idents.CountOf([idActive, idShared, idSfx]);
end;

constructor TUnitWriter.Create;
begin
  inherited;
  fBlock := Nil;
  fIdents := Nil;
  fErr := 0;
  fPosn := 0;
end;

destructor TUnitWriter.Destroy;
begin
  FreeAndNil(fIdents);
  fBlock := Nil;
  inherited;
end;

procedure BackupFile(const where: string);
begin
  if FileExists(where) then
  begin
    if FileExists(where + '.bak') then
      SysUtils.DeleteFile(where+'.bak');
    SysUtils.RenameFile(where, where+'.bak');
  end;
end;

procedure RestoreFile(const where: string); 
begin
  if FileExists(where + '.bak') then
  begin
    if FileExists(where) then
      SysUtils.DeleteFile(where);
    SysUtils.RenameFile(where + '.bak', where);
  end;
end;

                 
// each resource entry is of format
// lang_id: word
// comp_size: word
// name_size: word
// name[name_size]: byte
// data[comp_size]: byte  (res file)
function CompressRes(strm: TStream; const FName, lang: string): Integer;
var
  fs: TFileStream;
  lid: word;
  w: word;
  posn: Int64;
begin
  Result := 0;
  if not FileExists(FName) then
    exit;
  lid := LIdOfRes(FName);
  try
    fs := TFileStream.Create(FName, fmOpenRead);
    fs.Position := 0;
    strm.Size := 0;
    strm.WriteBuffer(lid, sizeof(word));   // language id
    w := 0;
    strm.WriteBuffer(w, sizeof(word));    // dummy compressed size
    w := Length(lang);
    strm.WriteBuffer(w, sizeof(word));    // name size
    strm.WriteBuffer(pChar(lang)^, w);    // name
    posn := strm.Position;
    if LZ77Compress(strm, fs) <> 0 then
    begin
      Form1.Show('Compression error');
      Result := -1;
      exit;
    end;
    Result := Integer(strm.Size);
    strm.Position := sizeof(word);
    w := word(strm.Size - posn);
    strm.WriteBuffer(w, sizeof(word));  // compressed size
  finally
    FreeAndNil(fs);
  end;
end;

function TUnitWriter.FullPath(p: ZPaths; const fn: String): String;
begin
  Result := Form1.FullPath(p, fn);
end;

function TUnitWriter.Prepare: Integer;
var
  blksiz: Integer;
  cs: TMemoryStream;
  rcf, rsf: string;
begin
  Result := 0;
  // remove any old lists
  FreeAndNil(fIdents);
  fBlock := Nil;
  fIdents := TIdentifiers.Create;
  if FIdents.LoadHFile(FullPath(zphLang, 'ZipMsg.h')) < 170 then
  begin
    Show('error reading identifiers');
    Err := Err_NoIDs;
    Result := Err;
    exit;
  end;                     
  rcf := FullPath(zphLang, 'ZipMsgUS.rc');
  if FIdents.ReadRCFile(rcf, True) <> 0 then
  begin
    Show('error reading identifiers');
    Err := Err_NoIDs;
    Result := Err;
    exit;
  end;    
  rsf := FullPath(zphLang, 'ZipMsgUS.res');
  if FileAge(rcf) > FileAge(rsf) then
  begin
    BackupFile(rsf);
    if not Form1.RunBRCC(rcf, rsf, '') then
    begin
      RestoreFile(rsf);
      Err := Err_Compile;
      Result := Err;
      exit;
    end;
  end;
  cs := nil;
  // block/stream format comp_size: word, size: word, data[comp_size]:bytes
  try
    cs := TMemoryStream.Create;
    blksiz := CompressRes(cs, rsf, 'US');
    blksiz := (blksiz + sizeof(Cardinal) - 1) div sizeof(Cardinal);
    SetLength(fBlock, blksiz);
    cs.Position := 0;
    if cs.Read(fBlock[0], cs.Size ) <> cs.Size then
    begin
      Show('Compression error');
      Err := Err_Unknown;
      Result := Err;
      exit;
    end;
  finally
    FreeAndNil(cs);
  end;
end;

procedure TUnitWriter.Show(const s: String);
begin
  Form1.Show(s);
end;

function TUnitWriter.WriteDefMsgs(const where: string): Integer; 
var
  ustrs: TStringList;
  idx, ix, i: integer;
  s: string;
begin
  ustrs := nil;
//  Result := -1;
  try
    ustrs := TStringList.Create;
    ustrs.Add('Unit ZMDefMsgs;');
    ustrs.Add(' ');  
    ustrs.Add('(* Built by ZipResMaker');
    ustrs.Add('   DO NOT MODIFY');
    ustrs.Add('  ZMDefMsgs.pas - default messages and compressed tables');
    ustrs.Add('  TZipMaster VCL by Chris Vleghert and Eric W. Engler');
    ustrs.Add('');
    ustrs.Add('  v1.79');
    ustrs.Add('      Copyright (C) 2005  Russell Peters');
    ustrs.Add(' ');
    ustrs.Add('  This library is free software; you can redistribute it and/or');
    ustrs.Add('  modify it under the terms of the GNU Lesser General Public');
    ustrs.Add('  License as published by the Free Software Foundation; either');
    ustrs.Add('  version 2.1 of the License, or (at your option) any later version.');
    ustrs.Add(' ');
    ustrs.Add('  This library is distributed in the hope that it will be useful,');
    ustrs.Add('  but WITHOUT ANY WARRANTY; without even the implied warranty of');
    ustrs.Add('  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU');
    ustrs.Add('  Lesser General Public License (licence.txt) for more details.');
    ustrs.Add(' ');
    ustrs.Add('  You should have received a copy of the GNU Lesser General Public');
    ustrs.Add('   License along with this library; if not, write to the Free Software ');
    ustrs.Add('  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA');
    ustrs.Add(' ');
    ustrs.Add('  contact: problems AT delphizip DOT org');
    ustrs.Add('  updates: http://www.delphizip.org ');
    ustrs.Add(' ');
    ustrs.Add('  modified '+ DateTimeToStr(Now));
    ustrs.Add('---------------------------------------------------------------------------*)');
    ustrs.Add(' ');       
    ustrs.Add('{$I ZipConfig.inc}');
    ustrs.Add(' ');
    ustrs.Add('Interface');
    ustrs.Add(' ');
    ustrs.Add('Uses');
    ustrs.Add('  ZipMsg;'); 
    ustrs.Add(' ');     
    ustrs.Add('{$IFNDEF USE_COMPRESSED_STRINGS}');
    ustrs.Add(' ');
    ustrs.Add('type');
    ustrs.Add('  TZipResRec = packed record');
    ustrs.Add('    i: Word;');
    ustrs.Add('    s: pResStringRec;');
    ustrs.Add('  end;');
    ustrs.Add(' ');
    ustrs.Add('ResourceString');
    for i := 0 to pred(IDTot) do
    begin
      ix := Idents.IndexAt(i, [idActive, idShared, idSfx]);
      s := '  _' + Idents.Name[ix] + ' = ' + NormPasStr(Idents.Msg[ix]) + ';';
      ustrs.Add(s);
    end;  
    ustrs.Add(' ');
    ustrs.Add('const');
    ustrs.Add(Format('ResTable: array [0..%d] of TZipResRec = (',[pred(IDTot{MSTot})]));
    s := '  ';
    for i := 0 to pred(IDTot) do
    begin
      ix := Idents.IndexAt(i, [idActive, idShared, idSfx]);
      s := '    (i: ' + Idents.Name[ix] + '; s: @_' + Idents.Name[ix] + ')';
      if i < pred(IDTot) then
        s := s + ','
      else
        s := s + ');';
      ustrs.Add(s);
    end;           
    ustrs.Add(' ');
    ustrs.Add('{$ELSE}');
    ustrs.Add(' ');
    ustrs.Add('const');
    ustrs.Add(Format(' CompBlok: array [0..%d] of Cardinal = (',[pred(CSTot)]));
    s := '  ';
    for idx := 0 to CSTot-2 do
    begin
      s := s + '$'+IntToHex(Block[idx], 8)+', ';
      if length(s) > 60 then
      begin
        ustrs.add(s);
        s := '  ';
      end;
    end;
    s := s + '$'+IntToHex(Block[pred(CSTot)], 8)+' );';
    if Length(s) > 4 then
        ustrs.add(s); 
    ustrs.Add('{$ENDIF}');
    Result := -1;
    ustrs.Add(' ');
    ustrs.Add('implementation');
    ustrs.Add(' ');
    ustrs.Add('end.');
    BackupFile(where);
    ustrs.SaveToFile(where);
    Result := 0;
  finally
    FreeAndNil(ustrs);
  end;
end;

function TUnitWriter.WriteZipMsg(const where: string): integer;
var
  ustrs: TStringList;
  idx, ix: integer;
  s: string;
begin
  ustrs := nil;
//  Result := -1;
  try
    ustrs := TStringList.Create;
    ustrs.Add('Unit ZipMsg;');
    ustrs.Add(' ');
    ustrs.Add('(* Built by ZipResMaker');
    ustrs.Add('   DO NOT MODIFY');
    ustrs.Add('  ZipMsg.pas - Message Identifiers');
    ustrs.Add('  TZipMaster VCL by Chris Vleghert and Eric W. Engler');
    ustrs.Add('');
    ustrs.Add('  v1.79');
    ustrs.Add('      Copyright (C) 2005  Russell Peters');
    ustrs.Add(' ');
    ustrs.Add('  This library is free software; you can redistribute it and/or');
    ustrs.Add('  modify it under the terms of the GNU Lesser General Public');
    ustrs.Add('  License as published by the Free Software Foundation; either');
    ustrs.Add('  version 2.1 of the License, or (at your option) any later version.');
    ustrs.Add(' ');
    ustrs.Add('  This library is distributed in the hope that it will be useful,');
    ustrs.Add('  but WITHOUT ANY WARRANTY; without even the implied warranty of');
    ustrs.Add('  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU');
    ustrs.Add('  Lesser General Public License (licence.txt) for more details.');
    ustrs.Add(' ');
    ustrs.Add('  You should have received a copy of the GNU Lesser General Public');
    ustrs.Add('   License along with this library; if not, write to the Free Software ');
    ustrs.Add('  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA');
    ustrs.Add(' ');
    ustrs.Add('  contact: zipmaster AT delphizip DOT net');
    ustrs.Add('  updates: http://www.delphizip.net ');
    ustrs.Add(' ');
    ustrs.Add('  modified '+ DateTimeToStr(Now));
    ustrs.Add('---------------------------------------------------------------------------*)');
    ustrs.Add(' ');
    ustrs.Add(' ');
    ustrs.Add('Interface');
    ustrs.Add(' ');
    ustrs.Add('Const');
    for idx := 0 to pred(Idents.CountOf([idActive, idShared, idSfx])) do
    begin
      ix := Idents.IndexAt(idx, [idActive, idShared, idSfx]);
      s := Format('  %s = %d;',[ Idents.Name[ix],Idents.Id[ix]]);
      ustrs.Add(s);
    end;
    ustrs.Add(' ');
    ustrs.Add('const');
    ustrs.Add('  PR_Progress = PR_Archive - 1;');
    ustrs.Add(' ');
    ustrs.Add('// name of compressed resource data');
    ustrs.Add('const ');
    ustrs.Add('  DZRES_Str = 11610;  // compressed language strings');
    ustrs.Add('  RDLL_Ver = 11612;   // stored UPX Dll version as string');
    ustrs.Add('  RDLL_Dll  = 11613;  // stored UPX Dll');
    ustrs.Add(' ');
    ustrs.Add('implementation');
    ustrs.Add(' ');
    ustrs.Add('end.'); 
    BackupFile(where);
    ustrs.SaveToFile(where);
    Result := 0;
  finally
    FreeAndNil(ustrs);
  end;
end;

end.

