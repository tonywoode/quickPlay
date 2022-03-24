unit UDefLangs;
 
(*
  UDefLangs.pas - writer for ZMDefLangs
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

  modified 2005-11-28
---------------------------------------------------------------------------*)

interface

uses
  Classes, CheckLst;

type
  TDefLangs = class
  private
    FFileName: string;
    stamp: cardinal;
    FNames: string;
    function GetLangNames: string;
    function GetNames: string;
    procedure SetFileName(const Value: string);
  public
    constructor Create;
    destructor Destroy; override;
    function IdentStr(lst: TCheckListBox): string;
    function WriteFile(const where: string; lst: TCheckListBox): Integer;
    property FileName: string read FFileName write SetFileName;
    property Names: string read GetNames;
  end;

implementation

uses
  SysUtils, StdCtrls, UWriter;
                              
const
  lchars = ['A'..'Z', 'a'..'z', '0'..'9', '_'];
       
function LanguageIdent(const seg: string): string;
var
  i: integer;
  c: char;
begin    
  Result := '';
  for i := 1 to length(seg) do
  begin
    c := seg[i];
    if not (c in lchars) then
    begin
      if (Result <> '') or (c <> ' ') then
        break;
    end
    else
      Result := Result + c;
  end;
  Result := Uppercase(Result);
end;

constructor TDefLangs.Create;
begin
  inherited;
  stamp := 0;
  fNames := '';
end;

destructor TDefLangs.Destroy;
begin
  inherited;
end;

function TDefLangs.GetLangNames: String;
const
  USections: array [1..6] of String = (
    'UNIT', 'INTERFACE', 'TYPE', 'CONST', 'IMPLEMENTATION', 'END.');
var
  DefNames: TStringList;
  i, ln: Integer;
  l, t:  String;

  function IsSection(ln: Integer; var lt: String): Integer;
  var
    ii: Integer;
    ss: String;
  begin
    Result := -1;
    if (ln < 0) or (ln >= DefNames.Count) then
      exit;
    lt := Uppercase(Trim(DefNames[ln]));
    ii := Pos(' ', lt);
    if ii > 0 then
      ss := copy(lt, 1, pred(ii))
    else
      ss := lt;
    for Result := 1 to HIGH(USections) do
      if ss = USections[Result] then
        exit;
    Result := 0;
  end;

begin
  Result := '?';  // invalid
  try
    DefNames := TStringList.Create;
    DefNames.LoadFromFile(Filename);
    if (DefNames.Count > 10) then
    begin
      ln := -1;
      repeat
        inc(ln);
        i := IsSection(ln, l);
        if i < 0 then
          exit;
      until i = 1;
      l := copy(l, 6, length(l) - 5);
      if Trim(l) <> 'ZMDEFLANGS;' then
        exit;
      repeat
        inc(ln);
        i := IsSection(ln, l);
        if i < 0 then
          exit;
      until i <> 0;
      if i <> 2 then
        exit;
      repeat
        repeat
          inc(ln);
          i := IsSection(ln, l);
          if i < 0 then
            exit;
        until i <> 0;
        if (i <= 2) or (i > 4) then
          exit;
      until i = 4;
      inc(ln);
      if IsSection(ln, l) <> 0 then
        exit;   // invalid
      if Pos('ZIPMSGLANGIDENTS', l) <> 1 then
        exit;
      t := trim(copy(l, 17, length(l) - 17));
      if (length(t) < 1) or (t[1] <> '=') then
        exit;
      t := trim(copy(t, 2, length(t) - 1));
      repeat
        inc(ln);
        i := IsSection(ln, l);
        if i < 0 then
          exit;
      until i <> 0;
      if i <> 5 then
        exit;
      repeat
        inc(ln);
        i := IsSection(ln, l);
        if i < 0 then
          exit;
      until i <> 0;
      if i <> 6 then
        exit;
      Result := t;
    end;
  finally
    FreeAndNil(DefNames);
  end;
end;

function TDefLangs.GetNames: string;
var
  age: cardinal;
begin
  Result := '<empty>';
  if Filename <> '' then
  begin
    age := FileAge(Filename);
    if age <> stamp then
    begin
      fNames := GetLangNames;
      stamp := age;
    end; 
    Result := fNames;
  end;
end;

function TDefLangs.IdentStr(lst: TCheckListBox): string;
var
  i: integer;
  s: string;
begin 
  Result := ''; 
  for i := 0 to pred(lst.Count) do
  begin
    if lst.Checked[i] and lst.ItemEnabled[i] then
    begin
      s := LanguageIdent(lst.Items[i]);
      if (s = '') or (s = 'US') then
        continue;
      if Result = '' then
        Result := #39 + s
      else
        Result := Result + ',' + s;
    end;
  end;
  if Result <> '' then
    Result := Result + #39;
end;

procedure TDefLangs.SetFileName(const Value: string);
begin
  FFileName := Value;  
  stamp := 0;
  fNames := '';
end;

function TDefLangs.WriteFile(const where: string; lst: TCheckListBox): Integer;
var
  ustrs: TStringList;
  i: integer;
  s, t: string;
begin
  ustrs := nil;
  Result := -1;
  try
    ustrs := TStringList.Create;
    ustrs.Add('Unit zmDefLangs;');
    ustrs.Add(' ');
    ustrs.Add('(* Built by ZipResMaker');
    ustrs.Add('   DO NOT MODIFY');
    ustrs.Add('  ZMDefLangs.pas - Language enumeration');
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
    ustrs.Add('Interface');
    ustrs.Add(' ');
    ustrs.Add('Type');
    s := '  TZipMsgLanguages = (zmlDefault, zmlAuto';
    for i := 0 to pred(lst.Count) do
    begin
      if lst.Checked[i] and lst.ItemEnabled[i] then
      begin
        t := LanguageIdent(lst.Items[i]);
        if (t = '') or (t = 'US') then
          continue;
        t := 'zml' + t;
        if (length(s) + Length(t) + 2) > 60 then
        begin
          if i <> 0 then
            s := s + ',';
          ustrs.Add(s);
          s := '      ';
        end;
        if length(s) < 7 then
          s := s + t
        else
          s := s + ', ' + t;
      end;
    end;
    ustrs.Add(s + ');');
    ustrs.Add(' ');
    ustrs.Add('Const');
    s := Format('  %s = %s;',[ 'ZipMsgLangIdents', IdentStr(lst)]);
    ustrs.Add(s);
    ustrs.Add(' ');
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

