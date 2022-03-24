Unit ZipFix;

//---------------------------------------------------------------------
// Component:        TZipFix
// Author:           Angus Johnson
// Version:          1.1
// Delphi:           Versions 3 - 5.
// C++ Builder:      Versions 1, 3 and 4 (5 Untested).
// Date:             30 May 2000
// Copyright:        © 1999-2000 Angus Johnson
// Email:            ajohnson@rpi.net.au
// Distribution:     Freeware.
//
// Component to repair a Zip archive when the archive's
// directory structure has been damaged.
// It will *not* fix damaged zipped data nor will it
// solve 'forgotten' passwords.
// If some zipped data has been damaged, the remaining undamaged
// data can be rebuilt into a new archive.
// Multi-disk archives can also be repaired if the disks are first
// concatenated (maintaining order) into a single InStream.
// Can also extract a zip archive which has been embedded
// in another file (eg a self-extracting zip archive).
//
// 21-06-2000 Added ZipFix.res RCV
//---------------------------------------------------------------------

// Acknowledgements for suggestions can be found within code.

{$IfDef VER110}
   {$ObjExportAll On}
   {$DEFINE CBUILDER3}
{$EndIf}
{$IfDef VER125}
   {$ObjExportAll On}
   {$DEFINE CBUILDER4}
{$EndIf}
{$IfDef VER130}
 {$IfDef BCB}
   {$ObjExportAll On}
   {$DEFINE CBUILDER5}
 {$EndIf}
{$EndIf}

Interface

uses
  Windows, Messages, SysUtils, Classes;

type

  TOnFileFoundEvent = procedure (Sender: TObject;
    const Filename: string; FileInfoIsOK: boolean) of object;

  TZipFix = class(TComponent)
  private
    fBuffer: pchar;
    fBufferSize: integer;
    fFileList: TList;
    fOutStream: TStream;
    fOnFileFound: TOnFileFoundEvent;
    fJumpValue: array[#0..#255] of integer; //used to find Local Header records
    fJumpValue2: array[#0..#255] of integer; //used to find DataDescriptor records
    procedure InitializeArrays;
    procedure GetLocalHeaderInfo;
    procedure DoZipFix;
  public
    procedure Execute(InStream: TMemoryStream; OutStream: TStream); {$IFDEF VER130} overload;
    procedure Execute(const InFilename, OutFilename: string); overload; {$ENDIF}
  published
    //30 May 2000 - OnFileFound event moved to published
    property OnFileFound: TOnFileFoundEvent read fOnFileFound write fOnFileFound;
  end;

  procedure Register;

Implementation

{$R ZipFix.Res}

type

//---------------------------------------------------------------------
//Record structures used in Zip files...
//---------------------------------------------------------------------
  TLocalHeader = packed record
    HeaderSig          : Cardinal; // $04034b50 (4)
    VersionNeed        : Word;
    Flag               : Word;
    ComprMethod        : Word;
    FileTime           : Word;
    FileDate           : Word;
    CRC32              : Cardinal;
    ComprSize          : Cardinal;
    UnComprSize        : Cardinal;
    FileNameLen        : Word;
    ExtraLen           : Word;
  end;

  TDataDescriptor = packed record  //Exists only if bit 3 of LocalHeader.Flag is set.
    DescriptorSig      : Cardinal; //field not defined in PKWare's docs but used by WinZip
    CRC32              : Cardinal;
    ComprSize          : Cardinal;
    UnComprSize        : Cardinal;
  end;

(*
  CentralDirectory =
    array [1..N] of TCentralFileHeader;
    TEndOfCentralHeader;
*)

  //array of TCentralFileHeaders constitute the Central Header directory...
  TCentralFileHeader = packed record  // fixed part size = 42 bytes
    HeaderSig          : Cardinal; // $02014b50 { 'PK'#1#2 } (4)
    MadeByVersion      : Byte;    //(1)
    HostVersionNo      : Byte;    //(1)
    Version            : Word;    //(2) version needed to extract(2)
    Flag               : Word;    //(2)
    CompressionMethod  : Word;    //(2)
    FileDate           : Integer; //modification date & time (4)
    CRC32              : Integer; //(4)
    CompressedSize     : Integer; //(4)
    UncompressedSize   : Integer; //(4)
    FileNameLength     : Word;    //(2)
    ExtraFieldLength   : Word;    //(2)
    FileCommentLen     : Word;    //(2)
    StartOnDisk        : Word;    //disk # on which file starts (2)
    IntFileAttrib      : Word;    //internal file attributes ie: Text/Binary(2)
    ExtFileAttrib      : Cardinal;//external file attributes(4)
    RelOffLocalHdr     : Cardinal;//relative offset of local file header(4)
    //FileName         variable size
    //ExtraField       variable size
    //FileComment      variable size
  end;

  TEndOfCentralHeader = packed record  //Fixed part size = 22 bytes
    HeaderSig          : Cardinal; //$06054B50 (4)
    ThisDiskNo         : Word;     //This disk's number (zero based) (2)
    CentralDiskNo      : Word;     //Disk number on which central dir starts (2)
    ThisDiskEntries    : Word;     //Number of central dir entries on this disk (2)
    TotalEntries       : Word;     //Total entries in central dir (2)
    CentralSize        : Cardinal; //Size of central directory (4)
    CentralOffset      : Cardinal; //offset of central dir on CentralDiskNo (4)
    ZipCommentLen      : Word;     //(2)
    // ZipComment       variable size
  end;

//---------------------------------------------------------------------
//Record structure used internally by the TZipFix 
//---------------------------------------------------------------------

  pFileInfo = ^TFileInfo;
  TFileInfo = packed record //first 42 bytes identical to the Central Header File record
    MadeByVersion      : Byte;    //(1)
    HostVersionNo      : Byte;    //(1)
    Version            : Word;    //(2)
    Flag               : Word;    //(2)
    CompressionMethod  : Word;    //(2)
    FileDate           : Integer; //modification datetime (4)
    CRC32              : Integer; //(4)
    CompressedSize     : Integer; //(4)
    UncompressedSize   : Integer; //(4)
    FileNameLength     : Word;    //(2)
    ExtraFieldLength   : Word;    //(2)
    FileCommentLen     : Word;    //(2)
    StartOnDisk        : Word;    //disk # on which file starts (2)
    IntFileAttrib      : Word;    //internal file attributes ie: Text/Binary(2)
    ExtFileAttrib      : Cardinal;//external file attributes(4)
    RelOffLocalHdr     : Cardinal;//relative offset of local file header(4)
    //42 bytes above plus...
    Filename: string;
    //ExtraField: string;
    //Comment: string;
  end;

const
  MULTIPLE_DISK_SIG      = $08074b50; // 'PK'#7#8
  DATA_DESCRIPT_SIG      = MULTIPLE_DISK_SIG; //!!
  LOCAL_HEADERSIG        = $04034b50; // 'PK'#3#4
  CENTRAL_HEADERSIG      = $02014b50; // 'PK'#1#2
  EOC_HEADERSIG          = $06054b50; // 'PK'#5#6

  MAX_FILENAME_LEN       = 80;

procedure Register;
begin
  RegisterComponents('Samples', [TZipFix]);
end;

//------------------------------------------------------------------------------
// TZipFix Methods
//------------------------------------------------------------------------------

//fill fFileList with records containing info from the Local Headers
procedure TZipFix.GetLocalHeaderInfo;
var
  fileInfo: pFileInfo;
  CurrentPos: integer;
  i, HeaderStartPos: integer;
  DataStart,DataEnd: integer;
label
  LocalHeaderError;
  //-------------------------------

  //positions CurrentPos at start of LocalHeaderSig...
  function FindNextHeader: boolean;
  var
    n,HeaderSig: integer;
  begin
    result := false;
    while CurrentPos < fBufferSize do
    begin
      n := fJumpValue[fBuffer[CurrentPos]];
      if n = 0 then //looking for 'PK'#3#4, a #4 found at least...
      begin
        dec(CurrentPos,3);
        move(fBuffer[CurrentPos],HeaderSig,4);
        if (HeaderSig = LOCAL_HEADERSIG) and
          (CurrentPos + Sizeof(TLocalHeader) < fBufferSize) then
        begin
          result := true;
          exit;
        end
        else
          inc(CurrentPos,7);
      end
      else
        inc(CurrentPos,n);
    end;
  end;
  //-------------------------------

  //positions fCurrentPos at start of DataDescriptorSig...
  function FindDataDescriptor: boolean;
  var
    n,HeaderSig: integer;
  begin
    result := false;
    while CurrentPos < fBufferSize do
    begin
      n := fJumpValue2[fBuffer[CurrentPos]];
      if n = 0 then //looking for 'PK'#7#8, a #8 found at least...
      begin
        dec(CurrentPos,3);
        move(fBuffer[CurrentPos],HeaderSig,4);
        if (HeaderSig = DATA_DESCRIPT_SIG) and
          (CurrentPos + Sizeof(TDataDescriptor) < fBufferSize) then
        begin
          result := true;
          exit;
        end
        else
          inc(CurrentPos,7);
      end
      else
        inc(CurrentPos,n);
    end;
  end;
//-------------------------------

begin

  //prepare for boyer-moore-horspool searches...
  //this will be more than 3 times faster than a brute-force search
  if fJumpValue[#0] = 0 then InitializeArrays;

  CurrentPos := 3;
  
  //get all local header info...
  while FindNextHeader do
  begin
    HeaderStartPos := CurrentPos;
    new(fileInfo);
    with fileInfo^ do
    begin
      //ignore the following values, so zero initialize them.
      //we could try and match them to the dud central directory records
      //but i'm not sure it's worth the trouble.
      MadeByVersion := $0;
      HostVersionNo := $0;
      IntFileAttrib := $0;
      ExtFileAttrib := $0;
      StartOnDisk   := $0;
      FileCommentLen := $0;

      //copy - Version, Flag, CompressionMethod, FileDate, CRC32,
      //  CompressedSize, UncompressedSize, FileNameLength, ExtraFieldLength
      move(fBuffer[HeaderStartPos+4],Version,Sizeof(TLocalHeader)-4);
      //save current Local Header offset which will be updated later...
      RelOffLocalHdr := HeaderStartPos;
      if (fileInfo.FileNameLength < 1) or
          (FileNameLength > MAX_FILENAME_LEN) then
        goto LocalHeaderError;
      inc(CurrentPos, Sizeof(TLocalHeader));
      setlength(Filename,FileNameLength);
      move(fBuffer[CurrentPos],Filename[1],FileNameLength);
      //and do an extra check to make sure the name is valid...
      for i := 1 to FileNameLength do
        if Filename[i] < #32 then
        begin
          Filename := '';
          goto LocalHeaderError;
        end;
      inc(CurrentPos, FileNameLength + ExtraFieldLength);
      if (Flag and $8) = $8 then
      begin
        //a bit of a bummer but a TDataDescriptor record is used
        //so we don't yet know the size of the data block.
        //it's a little bit slower but it still works...
        DataStart:= CurrentPos;
        if not FindDataDescriptor then goto LocalHeaderError;
        DataEnd:= CurrentPos;
        //now update: CRC32, CompressedSize, UncompressedSize
        move(fBuffer[CurrentPos+4],CRC32,12);
        inc(CurrentPos, sizeof(TDataDescriptor)); //get ready for next LocalHeader
        if (CompressedSize <> DataEnd - DataStart) then 
          goto LocalHeaderError;
      end
      else
        inc(CurrentPos,CompressedSize);
    end; //with fileInfo^ 
    //check for corrupted CompressedSize - suggested by Ramon Speets
    if (CurrentPos > fBufferSize) or 
       (fileInfo.CompressedSize > fileInfo.UncompressedSize) then
      goto LocalHeaderError;
    fFileList.add(fileInfo);
    if assigned(fOnFileFound) then fOnFileFound(self,fileInfo.filename,true);
    continue; //avoid LocalHeaderError below

LocalHeaderError:
    if assigned(fOnFileFound) then fOnFileFound(self,fileInfo.filename,false);
    dispose(fileInfo);
    CurrentPos := HeaderStartPos + 4; //ie: skip over this dud record
  end; //while FindNextHeader
end;
//------------------------------------------------------------------------------

procedure TZipFix.InitializeArrays; 
var
  i: AnsiChar;
begin
  for i := #0 to #255 do fJumpValue[i] := 4;
  fJumpValue['P'] := 3;
  fJumpValue['K'] := 2;
  fJumpValue[#3] := 1;
  fJumpValue[#4] := 0;

  for i := #0 to #255 do fJumpValue2[i] := 4;
  fJumpValue2['P'] := 3;
  fJumpValue2['K'] := 2;
  fJumpValue2[#7] := 1;
  fJumpValue2[#8] := 0;
end;
//---------------------------------------------------------------------

procedure TZipFix.DoZipFix;
var
  i,CurrentPos, StartOfCentral: integer;
  Eoc: TEndOfCentralHeader;
  HeaderSig: Cardinal;
begin
  //fOutStream.position := 0; //not essential...
                              //could theoretically append an SFX stub.
  GetLocalHeaderInfo;
  if fFileList.count = 0 then exit; //no files can be restored :(

  //write all the local headers and data...
  for i := 0 to fFileList.count-1 do
    with pFileInfo(fFileList[i])^ do
    begin
      CurrentPos := RelOffLocalHdr;
      RelOffLocalHdr := fOutStream.Position; //now update RelOffLocalHdr
      fOutStream.write(fbuffer[CurrentPos],
        sizeof(TLocalHeader)+FileNameLength+ExtraFieldLength+CompressedSize);
      //i'm almost certain the Central Directory ExtraField is different
      //from the local ExtraField so zero this out for the Central Directory.
      ExtraFieldLength := 0;
    end;
  StartOfCentral := fOutStream.position;
  //recreate the central directory...
  HeaderSig := CENTRAL_HEADERSIG;
  for i := 0 to fFileList.count-1 do
    with pFileInfo(fFileList[i])^ do
    begin
      fOutStream.write(HeaderSig,sizeof(HeaderSig));
      //copy first 42 bytes starting at MadeByVersion...
      fOutStream.write(MadeByVersion,42);
      fOutStream.write(Filename[1],length(Filename));
    end;
  //finally write the EndOfCentral header...
  Eoc.HeaderSig := EOC_HEADERSIG;
  Eoc.ThisDiskNo := 0;
  Eoc.CentralDiskNo := 0;
  Eoc.ThisDiskEntries := fFileList.count;
  Eoc.TotalEntries := Eoc.ThisDiskEntries;
  Eoc.CentralSize := fOutStream.position - StartOfCentral;
  Eoc.CentralOffset := StartOfCentral;
  Eoc.ZipCommentLen := 0;
  fOutStream.write(Eoc,sizeof(Eoc));
end;
//---------------------------------------------------------------------

procedure TZipFix.Execute(InStream: TMemoryStream; OutStream: TStream);
var
  i: integer;
begin
  if (InStream = nil) or (OutStream = nil) then
    raise Exception.create('No input or no output stream has been defined');
  fBuffer := InStream.memory;
  fBufferSize := InStream.size;
  fOutStream := OutStream;

  fFileList:= TList.create;
  try
    DoZipFix; //do it here!!
  finally
    //cleanup...
    for i := 0 to fFileList.count -1 do
      dispose(pFileInfo(fFileList[i]));
    fFileList.free;
  end;
end;
//------------------------------------------------------------------------------

{$IFDEF VER130}
procedure TZipFix.Execute(const InFilename, OutFilename: string);
var
  InStream: TMemoryStream;
  OutStream: TFileStream;
begin
  OutStream:= TFileStream.create(OutFilename,fmCreate);
  InStream := TMemoryStream.create;
  try
    Instream.LoadFromFile(InFilename);
    Execute(InStream, OutStream);
  finally
    InStream.free;
    OutStream.free;
  end;
end;

//------------------------------------------------------------------------------
{$ENDIF}
End.

