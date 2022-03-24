unit ZMUtils;

(*
  ZMUtils.pas - Some utility functions
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

{$INCLUDE ZipVers.inc}
 
{$IFDEF VERD6up}
{$WARN UNIT_PLATFORM OFF}
{$WARN SYMBOL_PLATFORM OFF}
{$ENDIF}

interface

type
  TPathSlashDirection = (psdExternal, psdInternal);
//  DeleteOpts = (htdFinal, htdAllowUndo);

type
  I64Rec = packed record
    case Integer of
      0: (I: Int64);
      1: (Lo, Hi: Cardinal);
//      2: (Cardinals: array[0..1] of Cardinal);
//      3: (Words: array[0..3] of Word);
//      4: (Bytes: array[0..7] of Byte);
  end;

const           // QueryZip return bit values and errors
  zqbStartEXE = 1;      // is EXE file may be SFX
  zqbStartLocal = 2;    // normal zip file start
  zqbStartSpan = 4;     // first part of span
  zqbStartCentral = 8;  // continuing Central Header
  zqbGoodComment = 16;  // comment length good (no junk at end)
  zqbHasLocal = 32;     // first Central entry points to local header
  zqbHasCentral = 64;   // Central entry where it should be
  zqbHasEOC = 128;      // End of Central entry
  zqFileError = -7;     // file handling error
  zqGeneralError = -9;  // unspecified failure


function PathConcat(const path, extra: String): String;
function FileNameMatch(const pat: String; const str: String): Boolean;

function ForceDirectory(const Dir: String): Boolean;
function SetSlash(const path: String; dir: TPathSlashDirection): String;

function DelimitPath(const path: String; sep: Boolean): String;
function DirExists(const Fname: String): Boolean;
function IsWild(const fspec: String): Boolean;
function EraseFile(const Fname: String; permanent: Boolean): Integer;
function QueryZip(const Fname: String): Integer; 
function FileSeek64(Handle: Integer; const Offset: Int64;  Origin: Integer): Int64;
function GetVolumeLabel(const drive: String): String;
function IsSameFile(const Fname1, Fname2: String): Boolean; 
procedure File_Close(var fh: Integer);   
//  true we're running under XP or later.
function IsWinXP : Boolean;
function FileDateToLocalDateTime(stamp: Integer): TDateTime;

{$IFDEF VER90}// if Delphi 2
function AnsiStrPos(S1, S2: Pchar): Pchar;
function AnsiStrIComp(S1, S2: Pchar): Integer;
function AnsiPos(const Substr, S: String): Integer;
{$ENDIF}
{$IFDEF VERD5-}
procedure FreeAndNil(var obj);
{$ENDIF}
function Lo64(i: Int64): Cardinal;
function Hi64(i: Int64): Cardinal;
// -------------------------- ------------ -------------------------
implementation

uses SysUtils, ZMStructs, ShellApi, Windows, Forms;

//--------------------------------------------------------
function Lo64(i: Int64): Cardinal;
var
  r: I64Rec;
begin
  r.I    := i;
  Result := r.Lo;
end;

function Hi64(i: Int64): Cardinal;
var
  r: I64Rec;
begin
  r.I    := i;
  Result := r.Hi;
end;

//--------------------------------------------------------
{$IFDEF VER90}// if Delphi 2

function AnsiStrPos(S1, S2: Pchar): Pchar;
begin
  Result := StrPos(S1, S2);                 // not will not work with MBCS

end;

function AnsiStrIComp(S1, S2: Pchar): Integer;
begin
  Result := CompareString(LOCALE_USER_DEFAULT, NORM_IGNORECASE, S1, -1, S2, -1) - 2;

end;

function AnsiPos(const Substr, S: String): Integer;
begin
  Result := Pos(Substr, S);
end;
{$ENDIF}

{$IFDEF VERD5-}
procedure FreeAndNil(var obj);
var
  o: TObject;
begin
  o := TObject(obj);
  TObject(obj) := NIL;
  if assigned(o) then
    o.Free;
end;
{$ENDIF}

{$IFDEF Delphi6up}
function FileSeek64(Handle: Integer; const Offset: Int64;  Origin: Integer): Int64;
begin
  Result := FileSeek(Handle, Offset, Origin);
end;
{$ELSE}
function FileSeek64(Handle: Integer; const Offset: Int64;  Origin: Integer): Int64;
var
  r: I64Rec; 
begin
  r.I    := Offset;
  r.Lo := SetFilePointer(Handle, Integer(r.Lo), @r.Hi, Origin);
  if (r.Lo = Cardinal(-1)) and (GetLastError <> 0) then
    r.I := -1;
  Result := r.i;
end;
{$ENDIF}
// -------------------------- ------------ -------------------------

(*? FilenameMatch
1.80 9 February 2004 RP trap (and reject) empty args
// 1.73 (31 May 2003) RP - Filename Match similar to dll
*)
function FileNameMatch(const pat: String; const str: String): Boolean;

var
  pl, px, sl, sx: Cardinal;
  c: Char;
{$R-}
  function pat_match(ps, pe: Cardinal; ss, se: Cardinal): Boolean;
  var
    c, cs:  Char;
    pa, sa: Cardinal;     // position of current '*'
  begin
    pa := 0;                                // no '*'
    sa := 0;
    repeat                                  // scan till end or unrecoverable error

      if ss > se then
        // run out of string - only '*' allowed in pattern
      begin
        while (ps <= pe) and (pat[ps] = '*') do
          Inc(ps);
        Result := (ps > pe);                // ok end of pattern
        exit;
      end;                
      if ps > se then
        // run out of  pattern
      begin
        Result := False;                // no match
        exit;
      end;
      // more string to process
      c := pat[ps];
      if c = '*' then
      begin                                 // on mask
        Inc(ps);
        if (ps > pe) then                   // last char - matches rest of string
        begin
          Result := True;
          exit;
        end;
        // note scan point incase must back up
        pa := ps;
        sa := ss;
      end
      else
      begin
        // if successful match, inc pointers and keep trying
        cs := str[ss];
        if (cs = c) or (UpCase(cs) = UpCase(c)) or          ((c = '\') and (cs = '/')) or
          ((c = '/') and (cs = '\')) or          ((c = '?') and (cs <> Char(0))) then
        begin
          Inc(ps);
          Inc(ss);
        end
        else                                // no match
        begin
          if (pa = 0) then                  // any asterisk?
          begin
            Result := False;                // no - no match
            exit;
          end;
          ps := pa;                         // backup
          Inc(sa);
          ss := sa;
        end;
      end;
    until False;
  end;

begin
  //  Result := false;
  pl := length(pat);                        // find start of ext
  sl := length(str);
  if (pl = 0) or (sl = 0) then
  begin
    Result := sl = pl;                      // both empty is match
    exit;
  end;
  px := pl;
  while px >= 1 do
  begin
    c := pat[px];
    if (c = '\') or (c = '/') then
      px := 0
    // no name left - skip path
    else
    if c = '.' then
      break
    else
      Dec(px);
  end;
  if px = 0 then
  begin
    Result := pat_match(1, pl, 1, sl);
    exit;
  end;
  sx := sl;
  while sx >= 1 do
  begin
    c := str[sx];
    if (c = '\') or (c = '/') then
      sx := 0
    // no name left - skip path
    else
    if c <> '.' then
      Dec(sx)
    else
      break;
  end;
  if (sx = 0) then
    sx := succ(sl);                         // past end

  Result := pat_match(1, pred(px), 1, pred(sx));
  if Result and ((px <> pred(pl)) or (pat[pl] <> '*')) then
    Result := pat_match(px, pl, sx, sl);    // test exts
end;
//? FilenameMatch

(*? IsWild
1.73.4
 returns true if filespec contains wildcard(s)
*)

function IsWild(const fspec: String): Boolean;
begin
  Result := (pos('*', fspec) > 0) or (pos('?', fspec) > 0);
end;
//? IsWild

(*? ForceDirectory
1.73 RP utilities
*)
function ForceDirectory(const Dir: String): Boolean;
var
  sDir: String;
begin
  Result := True;
  if Dir <> '' then
  begin
    sDir := DelimitPath(Dir, False);
    if DirExists(sDir) or (ExtractFilePath(sDir) = sDir) then
      exit;                                 // avoid 'c:\xyz:\' problem.

    if ForceDirectory(ExtractFilePath(sDir)) then
      Result := CreateDirectory(Pchar(sDir), NIL)
    else
      Result := False;
  end;
end;
//? ForceDirectory

(*? DirExists
1.73 12 July 2003 return true empty string (current directory)
*)
function DirExists(const Fname: String): Boolean;
var
  Code: DWORD;
begin
  Result := True;                           // current directory exists

  if Fname <> '' then
  begin
    Code   := GetFileAttributes(Pchar(Fname));
    Result := (Code <> $FFFFFFFF) and ((FILE_ATTRIBUTE_DIRECTORY and Code) <> 0);

  end;
end;
//? DirExists

(*? SetSlash
1.76 use enum  TPathSlashDirection = (psdExternal, psdInternal)
1.73
forwardSlash = false = Windows normal backslash '\'
forwardSlash = true = forward slash '/'
*) 
function SetSlash(const path: String; dir: TPathSlashDirection): String;

var
  c, f, r: Char;
  i, len:  Integer;
begin
  Result := path;
  len    := Length(path);
  if dir = psdInternal then
  begin
    f := '\';
    r := '/';
  end
  else
  begin
    f := '/';
    r := '\';
  end;
  i := 1;
  while i <= len do
  begin
    c := path[i];
{$ifndef UNICODE}
    if c in LeadBytes then
    begin
      Inc(i, 2);
      continue;
    end;
{$endif}
    if c = f then
      Result[i] := r;
    Inc(i);
  end;
end;
//? SetSlash

function DelimitPath(const path: String; sep: Boolean): String;
var
  c, used: Char;
  i: Integer;
begin
  Result := path;
  if Length(path) = 0 then
  begin
    if sep then
      Result := '\';
    exit;
  end;
  used := '\';
  c    := #0;
  i    := 1;
  // find last char
  while i <= Length(path) do
  begin
    c := path[i];
    Inc(i);
{$ifndef UNICODE}
    if c in LeadBytes then
    begin
      Inc(i);
      continue;
    end;
{$endif}
    if (c = '/') or (c = '\') then
      used := c;
  end;
  // is last delimiter
  if ((c = '/') or (c = '\')) <> sep then
    if sep then
      Result := path + used                 // append delim
    else
      Result := copy(path, 1, pred(Length(path)));
end;

 //---------------------------------------------------------------------------
 // concat path

function PathConcat(const path, extra: String): String;
var
  pathLst: Char;
  pathLen: Integer;
begin
  pathLen := Length(path);
  Result  := path;
  if pathLen > 0 then
  begin
    pathLst := path[pathLen];
    if (pathLst <> ':') and (Length(extra) > 0) then
      if (extra[1] = '\') = (pathLst = '\') then
        if pathLst = '\' then
          Result := Copy(path, 1, pathLen - 1) // remove trailing
        else
          Result := path + '\';
  end;
  Result := Result + extra;
end;

(*? EraseFile
1.77 moved from ZMaster
 Delete a file and put it in the recyclebin on demand.
*)
function EraseFile(const Fname: String; permanent: Boolean): Integer;
var
  SHF: TSHFileOpStruct;
  DelFileName: String;
begin
  // If we do not have a full path then FOF_ALLOWUNDO does not work!?
  DelFileName := Fname;
  if ExtractFilePath(Fname) = '' then
    DelFileName := GetCurrentDir() + '\' + Fname;

  Result := -1;
  // We need to be able to 'Delete' without getting an error
  // if the file does not exists as in ReadSpan() can occur.
  if not FileExists(DelFileName) then
    Exit;
  with SHF do
  begin
    Wnd    := Application.Handle;
    wFunc  := FO_DELETE;
    pFrom  := Pchar(DelFileName + #0);
    pTo    := NIL;
    fFlags := FOF_SILENT or FOF_NOCONFIRMATION;
    if not permanent then
      fFlags := fFlags or FOF_ALLOWUNDO;
  end;
  Result := SHFileOperation(SHF);
end;
//? EraseFile

(*? QueryZip
1.79.0.2 30 December 2005 RP fix range error
1.75.0.5 10 March 2004 RA change filesize to int64
1.75 18 February 2004 allow >2G
1.73 05 July 2003 RP
 Return value:
 Bit Mapped result (if > 0)
 bits 0..3 = S L P D     - start of file
 S 1 = EXE file
 L 2 = Local Header
 P 4 = first part of split archive
 D 8 = Central Header
 bit 4 = Correct comment length (clear if junk at end of file)
 bits  5..7 = Loc Cen End
End 128 = end of central found (must be set for any chance at archive)
Cen 64 = linked Central Directory start (should be set unless split directory)
Loc 32 = Local Header linked to first Central (should be set unless split file)
 -7  = Open, read or seek error
 -9  = exception error
 Good file results    All cases 16 less if comment length (or file length) is wrong
 Zip = 128+64+32+16+2 = 242
 SFX = 128+64+32+16+1 = 241
 Last Part Span = 128+16 (144 - only EOC)
        = 128+16+8 (152 - split directory)
        = 128+64+16 (208 - split file)
*)
function QueryZip(const Fname: String): Integer;
var
  EOC:  ZipEndOfCentral;
  pEOC: pZipEndOfCentral;
  CentralHead: ZipCentralHeader;
  Sig:  Cardinal;
  pBuf: PAnsiChar;
  EOCpossible: Boolean;
  ReadPos, bufPos: Cardinal;
  res, {fileSize,} fileHandle, Size: Integer;
  fileSize, fs: Int64;
begin
  EOCPossible := False;
  fileHandle := -1;
  res    := 0;
  Result := -7;
  pBuf   := NIL;
  try
    try
      // Open the input archive, presumably the last disk.
      fileHandle := FileOpen(Fname, fmShareDenyWrite or fmOpenRead);
      if fileHandle = -1 then
        exit;
      Result := 0;      // rest errors normally file too small

      // first we check if the start of the file has an IMAGE_DOS_SIGNATURE
      if (FileRead(fileHandle, Sig, 4) <> 4) then
        exit;
      if LongRec(Sig).Lo = IMAGE_DOS_SIGNATURE then
        res := 1
      else
      if Sig = LocalFileHeaderSig then
        res := 2
      else
      if Sig = CentralFileHeaderSig then
        res := 8
      // part of split Central Directory
      else
      if Sig = ExtLocalSig then
        res := 4;                           // first part of span

      // A test for a zip archive without a ZipComment.
      fs := FileSeek64(fileHandle, -Int64(sizeof(EOC)), 2);
      if fs = -1 then
        exit;                               // not zip - too small
      filesize := fs;
      // try no comment
      if (FileRead(fileHandle, EOC, sizeof(EOC)) = sizeof(EOC)) and
        (EOC.HeaderSig = EndCentralDirSig) then
      begin
        EOCPossible := True;
        res := res or 128;                  // EOC
        if EOC.ZipCommentLen = 0 then
          res := res or 16;                 // good comment length
        if EOC.CentralDiskNo = EOC.ThisDiskNo then
        begin                               // verify start of central
          if (FileSeek64(fileHandle, Int64(EOC.CentralOffset), 0) <> -1) and
            (FileRead(fileHandle, CentralHead, sizeof(CentralHead)) =
            sizeof(CentralHead)) and (CentralHead.HeaderSig = CentralFileHeaderSig) then

          begin
            res := res or 64;               // has linked Central
            if (CentralHead.DiskStart = EOC.ThisDiskNo) and
              (FileSeek64(fileHandle, Int64(CentralHead.RelOffLocal), 0) <> -1) and
              (FileRead(fileHandle, Sig, sizeof(Sig)) = sizeof(Sig)) and
              (Sig = LocalFileHeaderSig) then
              res := Res or 32;             // linked local
          end;
          exit;
        end;
        res := res and $01F;                // remove rest
      end;
      // try to locate EOC
      Inc(fileSize, sizeof(EOC));
      Size := 65535 + sizeof(EOC);
      if Size > fileSize then
        Size := fileSize;
      GetMem(pBuf, Size);
      ReadPos := filesize - Size;
      if (FileSeek64(fileHandle, Int64(ReadPos), 0) <> -1) and
        (FileRead(fileHandle, pBuf^, size) = size) then
      begin
        // Finally try to find the EOC record within the last 65K...
        pEOC := pZipEndOfCentral(pBuf + Size - sizeof(EOC));
        while PAnsiChar(pEOC) > pBuf do         // reverse search
        begin
          Dec(PAnsiChar(pEOC));
          if pZipEndOfCentral(pEOC)^.HeaderSig = EndCentralDirSig then
          begin                             // possible EOC found
            res    := res or 128;              // EOC
            // check correct length comment
            BufPos := ReadPos + Cardinal(PAnsiChar(pEOC) - pBuf);
            if (BufPos + sizeof(EOC) + pEOC^.ZipCommentLen) = Cardinal(filesize) then
              res := res or 16;             // good comment length
            if pEOC^.CentralDiskNo = pEOC^.ThisDiskNo then
            begin                           // verify start of central
              if (FileSeek64(fileHandle, Int64(pEOC^.CentralOffset), 0) <>
                -1) and (FileRead(fileHandle, CentralHead, sizeof(CentralHead)) =
                sizeof(CentralHead)) and                (CentralHead.HeaderSig =
                CentralFileHeaderSig) then
              begin
                res := res or 64;           // has linked Central
                if (CentralHead.DiskStart = pEOC^.ThisDiskNo) and
                  (FileSeek64(fileHandle, Int64(CentralHead.RelOffLocal), 0) <> -1) and
                  (FileRead(fileHandle, Sig, sizeof(Sig)) = sizeof(Sig)) and
                  (Sig = LocalFileHeaderSig) then
                  res := Res or 32;         // linked local
              end;
              break;
            end;
            res := res and $01F;            // remove rest
          end;
        end;                                // while
      end;
      if EOCPossible and ((res and 128) = 0) then
        res := res or 128;
    except
      Result := -9;                         // exception
    end;
  finally
//    if (fileHandle <> -1) then
    File_Close(fileHandle);
    if Result = 0 then
      Result := res;
    if assigned(pBuf) then
      FreeMem(pBuf);
  end;
end;
//? QueryZip

function GetVolumeLabel(const drive: String): String;
var
  SysFlags, OldErrMode: DWord;
  NamLen: Cardinal;
  SysLen: DWord;
  drv: String;
  VolNameAry: array[0..255] of Char;
  Num: Integer;
  Bits: set of 0..25;
  DriveLetter: Char;
//  DiskSerial: Integer;
begin
  Result := '';
  NamLen := 255;
  SysLen := 255;
  VolNameAry[0] := #0;
  drv := UpperCase(ExpandFileName(drive));
  DriveLetter := drv[1];
  if DriveLetter <> '\' then                // Only for local drives
  begin
    if (DriveLetter < 'A') or (DriveLetter > 'Z') then
      exit;
    Integer(Bits) := GetLogicalDrives();
    Num := Ord(DriveLetter) - Ord('A');
    if not (Num in Bits) then
      exit;
  end;
  OldErrMode := SetErrorMode(SEM_FAILCRITICALERRORS);
  // Turn off critical errors:
  if GetVolumeInformation(Pchar(drv), VolNameAry,    NamLen, Nil{@DiskSerial},
    SysLen, SysFlags, NIL, 0) then
    Result := VolNameAry;
  SetErrorMode(OldErrMode);
  // Restore critical errors:
end;

function IsSameFile(const Fname1, Fname2: String): Boolean;
var
  sr1, sr2: TSearchRec;
  ff1, ff2: Boolean;
begin
  if CompareText(ExpandFileName(Fname1), ExpandFileName(Fname2)) = 0 then
  begin
    Result := true;
    exit;
  end;
  Result := false;
  // in windows no alias so names must match
  if CompareText(ExtractFileName(Fname1), ExtractFileName(Fname2)) = 0 then
  begin
    ff1 := FindFirst(Fname1, faAnyFile, sr1) = 0;
    ff2 := FindFirst(Fname2, faAnyFile, sr2) = 0;
    if (ff1 = ff2) and not ff1 then
      exit// neither found assume different
//      Result := CompareText(Fname1, Fname2) = 0;
    ;
{ $WARN SYMBOL_PLATFORM OFF}
    if ff1 = ff2 then
      Result := CompareMem(@sr1.FindData, @sr2.FindData, 2 + (4 * 4))// both exist
    ;
    if ff1 then
      SysUtils.FindClose(sr1);
    if ff2 then
      SysUtils.FindClose(sr2);
  end;
end;
 
procedure File_Close(var fh: Integer);
var
  h: Integer;
begin
  if fh <> -1 then
  begin
    h := fh;
    fh := -1;
    FileClose(h);
  end;
end;

//  Returns a boolean indicating whether or not we're running under XP or later.
function IsWinXP : Boolean;
var
  osv : TOSVERSIONINFO;
begin
  osv.dwOSVersionInfoSize := sizeOf( OSVERSIONINFO );
  GetVersionEx(osv);
  result := (osv.dwMajorVersion > 5)        or
    ((osv.dwMajorVersion = 5) and (osv.dwMinorVersion >= 1));
end;

function FileDateToLocalDateTime(stamp: Integer): TDateTime;
var
  LocTime, FTime: TFileTime;
  SysTime: TSystemTime;
begin
  Result := 0;
  if DosDateTimeToFileTime(LongRec(stamp).Hi, LongRec(stamp).Lo, LocTime) and
    LocalFileTimeToFileTime(LocTime, FTime) and
    FileTimeToSystemTime(FTime, SysTime) then
    Result := SystemTimeToDateTime(SysTime);
end;

end.

