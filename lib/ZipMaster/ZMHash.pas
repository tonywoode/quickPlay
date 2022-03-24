unit ZMHash;

(*
  ZMHash.pas - Central Directory hash list
  TZipMaster VCL by Chris Vleghert and Eric W. Engler
  v1.79
  Copyright (C) 2009  Russell Peters


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

  modified 2009-04-25
---------------------------------------------------------------------------*)

interface

uses
  ZipMstr;

const
  HDEBlockEntries = 511; // number of entries per block

type
  PHashedDirEntry = ^THashedDirEntry;

  THashedDirEntry = record
    Next: PHashedDirEntry;
    ZRec: pZipDirEntry;
    Hash: Cardinal;
  end;

  // for speed and efficiency allocate blocks of entries
  PHDEBlock = ^THDEBlock;
  THDEBlock = packed record
    Entries: array [0..(HDEBlockEntries -1)] of THashedDirEntry;
    Next: PHDEBlock;
  end;

  TZipDirHashList = class(TObject)
  private
    fLastBlock: PHDEBlock;
    fNextEntry: Cardinal;
    function GetSize: Cardinal;
    procedure SetSize(const Value: Cardinal);
  protected
    fBlocks: Integer;
    Chains: array of PHashedDirEntry;
    function GetEntry: PHashedDirEntry;
    function Same(Entry: PHashedDirEntry; Hash: Cardinal; const Str: String):
        Boolean;
  public
    function Add(const Rec: pZipDirEntry): pZipDirEntry;
    procedure AfterConstruction; override;
    procedure AutoSize(Req: Cardinal);
    procedure BeforeDestruction; override;
    procedure Clear;
    function Find(const FileName: String): PZipDirEntry;
    property Size: Cardinal read GetSize write SetSize;
  end;

implementation

uses
  SysUtils, Windows;

const
  ChainsMax = 40961;
  ChainsMin = 61;

// P. J. Weinberger Hash function
function HashFunc(const Str: String): Cardinal;
var
  i: Cardinal;
  x: Cardinal;
begin
  Result := 0;
  for i := 1 to Length(Str) do
  begin
    Result := (Result shl 4) + Ord(Str[i]);
    x := Result and $F0000000;
    if (x <> 0) then
      Result := (Result xor (x shr 24)) and $0FFFFFFF;
  end;
end;

function TZipDirHashList.Add(const Rec: pZipDirEntry): pZipDirEntry;
var
  Entry: PHashedDirEntry;
  Hash: Cardinal;
  Idx: Integer;
  Parent: PHashedDirEntry;
  UpperName: String;
begin
  Assert(Rec <> nil, 'nil ZipDirEntry');
  if Chains = nil then
    Size := 1283;
  Result := nil;
  UpperName := UpperCase(Rec^.FileName);
  Hash := HashFunc(UpperName);
  Idx := Hash mod Cardinal(Length(Chains));
  Entry := Chains[Idx];
  if Entry = nil then
  begin
    Entry := GetEntry;
    Entry.Hash := Hash;
    Entry.ZRec := Rec;
    Entry.Next := nil;
    Chains[Idx] := Entry;
  end
  else
  begin
    repeat
      if Same(Entry, Hash, UpperName) then
      begin
        Result := Entry.ZRec;   // duplicate name
        exit;
      end;
      Parent := Entry;
      Entry := Entry.Next;
      if Entry = nil then
      begin
        Entry := GetEntry;
        Entry.ZRec := nil;
        Parent.Next := Entry;
      end;
    until (Entry.ZRec = nil);
    // we have an entry so fill in the details
    Entry.Hash := Hash;
    Entry.ZRec := Rec;
    Entry.Next := nil;
  end;
end;

procedure TZipDirHashList.AfterConstruction;
begin
  inherited;
  Chains := nil;
  fBlocks := 0;
  fLastBlock := nil;
  fNextEntry := HIGH(Cardinal);
end;

// set size to a reasonable prime number
procedure TZipDirHashList.AutoSize(Req: Cardinal);
const
  PrimeSizes: array[0..28] of Cardinal =
  (61, 131, 257, 389, 521, 641, 769, 1031, 1283, 1543, 2053, 2579, 3593,
   4099, 5147, 6151, 7177, 8209, 10243, 12289, 14341, 16411, 18433, 20483,
   22521, 24593, 28687, 32771, 40961);
var
  i: Integer;
begin
  if Req < 15000 then
  begin
    // use next higher size
    for i := 0 to HIGH(PrimeSizes) do
      if PrimeSizes[i] >= Req then
      begin
        Req := PrimeSizes[i];
        break;
      end;
  end
  else
  begin
    // use highest smaller size
    for i := HIGH(PrimeSizes) downto 0 do
      if PrimeSizes[i] < Req then
      begin
        Req := PrimeSizes[i];
        break;
      end;
  end;
  SetSize(Req);
end;
						   

procedure TZipDirHashList.BeforeDestruction;
begin
  Clear;
  inherited;
end;

procedure TZipDirHashList.Clear;
var
  TmpBlock: PHDEBlock;
begin
  while fLastBlock <> nil do
  begin
    TmpBlock := fLastBlock;
    fLastBlock := TmpBlock^.Next;
    Dispose(TmpBlock);
  end;
  chains := nil;
  fBlocks := 0;
  fLastBlock := nil;
  fNextEntry := HIGH(Cardinal);
end;

function TZipDirHashList.Find(const FileName: String): PZipDirEntry;
var
  Entry: PHashedDirEntry;
  Hash: Cardinal;
  idx:  Cardinal;
  UpperName: string;
begin
  Result := nil;
  if Chains = nil then
    exit;
  UpperName := UpperCase(FileName);
  Hash := HashFunc(UpperName);
  idx  := Hash mod Cardinal(Length(Chains));
  Entry := Chains[idx];
  // check entries in this chain
  while Entry <> nil do
  begin
    if Same(Entry, Hash, UpperName) then
    begin
      Result := Entry.ZRec;
      break;
    end
    else
      Entry := Entry.Next;
  end;
end;

// return address in allocated block
function TZipDirHashList.GetEntry: PHashedDirEntry;
var
  TmpBlock: PHDEBlock;
begin
  if (fBlocks < 1) or (fNextEntry >= HDEBlockEntries) then
  begin
    // we need a new block
    New(TmpBlock);
    ZeroMemory(TmpBlock, sizeof(THDEBlock));
    TmpBlock^.Next := fLastBlock;
    fLastBlock := TmpBlock;
    Inc(fBlocks);
    fNextEntry := 0;
  end;
  Result := @fLastBlock^.Entries[fNextEntry];
  Inc(fNextEntry);
end;

function TZipDirHashList.GetSize: Cardinal;
begin
  Result := Length(Chains);
end;

function TZipDirHashList.Same(Entry: PHashedDirEntry; Hash: Cardinal; const Str:
    String): Boolean;
begin
  Result := (Hash = Entry^.Hash) and (CompareText(Str, Entry^.ZRec^.FileName) = 0);
end;

procedure TZipDirHashList.SetSize(const Value: Cardinal);
var
  TableSize: Integer;
begin
  Clear;
  if Value > 0 then
  begin
    TableSize := Value;
    // keep within reasonable limits
    if TableSize < ChainsMin then
      TableSize := ChainsMin
    else
    if TableSize > ChainsMax then
      TableSize := ChainsMax;
    SetLength(Chains, TableSize);
    ZeroMemory(Chains, Size * sizeof(PHashedDirEntry));
  end;
end;

end.
