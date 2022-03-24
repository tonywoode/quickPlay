unit ZipCompLZ77;
   
(*
  ZipCompLZ77.pas - LZ77 stream compressor
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
  classes;

function LZ77Compress(StrmOut, StrmIn: TStream): integer;

implementation

uses
  SysUtils;

const
  N = 4096;
  F = 16;

type
  TLZ77Compressor = class
  private
    fIns: TStream;
    fOuts: TStream;
  protected
    buffer: array [0 .. (N + F)] of Byte;
    node: array [ -1..((N * 3) + 256) ] of integer;
    function Match(var pos: integer;i, run: Integer): Integer;
    procedure Remove(z: Integer);
    function GetByte: Integer;
  public
    constructor Create;
    function Compress: Integer;
    property InStream: TStream read fIns write fIns;
    property OutStream: TStream read fOuts write fOuts;
  end;

const
  THRESHOLD = 3;
  STOP = -1;
  DADS = 1;
  LSONS = 1 + N;
  RSONS = 1 + N + N;
  ROOTS = 1 + N + N + N;

{ TLZ77Compressor }

function TLZ77Compressor.Compress: Integer;
var
  c: Cardinal;
  pos, ch, i, run, len, matched, size, mask: Integer;
  buf: array [0..17] of Byte;
begin
  Result := -1;
  if not (assigned(InStream) or assigned(OutStream)) then
    exit;
  Result := -2;
  if InStream.Size < 1 then
    exit;
  c := Cardinal(InStream.Size);
  OutStream.WriteBuffer(c, 4);

  for i := 0 to 255 do
    node[ROOTS + i] := STOP;
  node[0] := STOP;
  for i := 0 to pred(N) do
    node[DADS + i] := STOP;
  size := 1;
  mask := 1;
  buf[0] := 0;
  i := N - F - F;
  len := 0;
  while len < F do
  begin
    ch := GetByte;
    if ch = -1 then
      break;
    buffer[i + F] := Byte(ch);
    i := (i + 1) and (N - 1);
    inc(len);
  end;
  run := len;
  repeat
    ch := GetByte;
    if i >= (N - F) then
    begin
      Remove(i + F - N);
      buffer[i + F] := Byte(ch);
      buffer[i + F - N] := Byte(ch);
    end
    else
    begin
      Remove(i + F);
      buffer[i + F] := Byte(ch);
    end;
    matched := Match(pos, i, run);
    if ch = -1 then
    begin
      dec(run);
      dec(len);
    end;
    if len >= run then
    begin
      if matched >= THRESHOLD then
      begin
        buf[size] := Byte(pos);
        inc(size);
        buf[size] := Byte(((pos shr 4) and $F0) or ((matched - 3) and 15));
        inc(size);
        dec(len, matched);
      end
      else
      begin
        buf[0] := Byte(Integer(buf[0]) or mask);
        buf[size] := buffer[i];
        inc(size);
        dec(len);
      end;
      inc(mask, mask);
      if (mask and $FF) = 0 then
      begin
        OutStream.WriteBuffer(buf, size);
        mask := 1;
        size := 1;
        buf[0] := 0;
      end;
    end;
    inc(len);
    i := (i + 1) and (N - 1);
  until len <= 0;
  if size > 1 then
    OutStream.WriteBuffer(buf, size);
  Result := 0;
end;

function TLZ77Compressor.GetByte: Integer;
var
  ch: Byte;
begin
  Result := -1;
  if InStream.Read(ch, 1) = 1 then
    Result := Integer(ch);
end;

function TLZ77Compressor.Match(var pos: integer; i, run: Integer): Integer;
var
  c, j, k, l, m: Integer;
  idx: integer;
begin
  k := 1;
  l := 1;
  Result := THRESHOLD - 1;
  idx := 1 + N + N + N + Integer(buffer[i]);
  node[LSONS + i] := STOP;
  node[RSONS + i] := STOP;

  while node[idx] <> STOP do
  begin
    j := node[idx];
    if k < l then
      m := k
    else
      m := l;
    c := 11110;
    while (m < run) do
    begin
      c := Integer(buffer[j + m]) - Integer(buffer[i + m]);
       if c <> 0 then
         break;
      inc(m);
    end;

    if (m > Result) then
    begin
      Result := m;
      pos := j;
    end;

    if (c < 0) then
    begin
      idx := 1 + N + j;
      k := m;
    end
    else
    if  c > 0   then
    begin
      idx := 1 + N + N + j;
      l := m;
    end
    else   // c == 0
    begin
      node[DADS + j] := STOP;
      node[DADS + node[LSONS + j]] := 1 + N + i;
      node[DADS + node[RSONS + j]] := 1 + N + N + i;
      node[LSONS + i] := node[LSONS + j];
      node[RSONS + i] := node[RSONS + j];
      break;
    end;
  end;
  node[DADS + i] := idx;
  node[idx] := i;
end;


procedure TLZ77Compressor.Remove(z: Integer);
var
  j: Integer;
begin
  if node[DADS + z] <> STOP then
  begin
    if node[RSONS + z] = STOP then
      j := node[LSONS + z]
    else
    if node[LSONS + z] = STOP then
      j := node[RSONS + z]
    else
    begin
      j := node[LSONS + z];
      if node[RSONS + j] <> STOP then
      begin
        repeat
          j := node[RSONS + j];
        until node[RSONS + j] = STOP;
        node[node[DADS + j]] := node[LSONS + j];
        node[DADS + node[LSONS + j]] := node[DADS + j];
        node[LSONS + j] := node[LSONS + z];
        node[DADS + node[LSONS + z]] := 1 + N + j;
      end;
      node[RSONS + j] := node[RSONS + z];
      node[DADS + node[RSONS + z]] := 1 + N + N + J;
    end;
    node[DADS + j] := node[DADS + z];
    node[node[DADS + z]] := j;
    node[DADS + z] := STOP;
  end;
end;


constructor TLZ77Compressor.Create;
begin
  fIns := Nil;
  fOuts := Nil;
end;


function LZ77Compress(StrmOut, StrmIn: TStream): integer;
var
  LZ77: TLZ77Compressor;
begin
  try
    LZ77 := TLZ77Compressor.Create;
    try
      LZ77.InStream := StrmIn;
      LZ77.OutStream := StrmOut;
      Result := LZ77.Compress;
    except
      Result := -4;
    end;
  finally
    FreeAndNil(LZ77);
  end;
end;

end.
