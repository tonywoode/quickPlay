unit ZMExtrLZ77;

(*
  ZMExtrLZ77.pas - LZ77 stream expander
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


  modified 2009-06-03
---------------------------------------------------------------------------*)

interface

uses
  Classes;

// expects src at orig_size (integer), data (bytes)
function LZ77Extract(dst, src: TStream; size: integer): integer;

implementation
   
const
  N = 4096;
  NMask = $FFF; //(N-1)
  F = 16;

function LZ77Extract(dst, src: TStream; size: integer): integer;
var
  bits, ch, i, j, len, mask: Integer;
  buffer: array of AnsiChar;
  bytes, written, filesize: integer;

  function GetByte: Integer;
  var
    ch: AnsiChar;
  begin
    Result := -1;
    if (bytes > 4) and (src.Size > src.Position) then
    begin
      dec(bytes);
      if src.Read(ch, sizeof(AnsiChar)) = sizeof(AnsiChar) then
        Result := Integer(ch)
      else
        bytes := 0;
    end;
  end;

begin
  bytes := size;
  if bytes < 0 then
    bytes := HIGH(Integer); 
  src.ReadBuffer(filesize, sizeof(integer));
  written := 0;

  SetLength(buffer, N);
  i := N - F;
  while True do
  begin
    bits := getbyte;
    if (bits < 0) then
      break;

    mask := 1;
    while mask < 256 do
    begin
      if (bits and mask) = 0 then
      begin
        j := GetByte;
        if j < 0 then
          break;
        len := GetByte;
        inc(j, (len and $F0) shl 4);
        len := (len and 15) + 3;
        while len > 0 do
        begin
          buffer[i] := buffer[j];
          dst.WriteBuffer(buffer[i], 1);
          inc(written);
          j := succ(j) and NMask;
          i := succ(i) and NMask;
          dec(len);
        end;
      end
      else
      begin
        ch := GetByte;
        if ch < 0 then
          break;
        buffer[i] := AnsiChar(ch);
        dst.WriteBuffer(ch, 1);  
        inc(written);
        i := succ(i) and NMask;
      end;
      inc(mask, mask);
    end;
  end;
  if (filesize = written) and (bytes = 4) then
    Result := 0   // good
  else
    if bytes = 4 then
      Result := -2   // wrong length
    else
      Result := -1; // invalid data 
  Buffer := nil;
end;

end.
