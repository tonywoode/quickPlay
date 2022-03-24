unit ZMCompat;

(*
  ZMCompat20.pas - Types and utility functions required for some compilers
  TZipMaster20 VCL by Chris Vleghert and Eric W. Engler
  v2.0
  Copyright (C) 2008  Russell Peters


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

  modified 2009-02-09
---------------------------------------------------------------------------*)

interface

//{$INCLUDE '.\ZipVers.inc'}

{$ifndef UNICODE}
type
  TCharSet = set of AnsiChar;

  function CharInSet(C: AnsiChar; const CharSet: TCharSet): Boolean;
{$endif}

  function MakeStrP(const str: String): PAnsiChar;

implementation

uses
{$ifdef UNICODE}
  AnsiStrings, SysUtils;
{$else}
  SysUtils;
{$endif}

{$ifndef UNICODE}
function CharInSet(C: AnsiChar; const CharSet: TCharSet): Boolean;
begin
  Result := c in CharSet;
end;
{$endif}

function MakeStrP(const str: String): PAnsiChar;
{$ifdef UNICODE}
var
  StrA: AnsiString;
{$endif}
begin
{$ifdef UNICODE}
  StrA := AnsiString(str);
  Result := AnsiStrAlloc(Length(StrA) + 1);
  StrPLCopy(Result, StrA, Length(StrA) + 1);
{$else}
  Result := StrAlloc(Length(Str) + 1);
  StrPLCopy(Result, Str, Length(Str) + 1);
{$endif}
end;

end.

