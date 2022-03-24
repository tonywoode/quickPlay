unit ZMWrkr;

(*
  ZMWrkr.pas - Does the work
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

  modified 2009-03-21
---------------------------------------------------------------------------*)

{$INCLUDE '.\ZipConfig.inc'}
{$INCLUDE '.\ZipVers.inc'}
{$IFDEF VER180}
{$WARN SYMBOL_DEPRECATED OFF}
{$ENDIF}


interface

uses
  Forms, SysUtils, Classes, Messages,
  Dialogs, Controls,
  Graphics, Buttons, StdCtrls, FileCtrl,
  ZipMstr, ZMStructs, ZMDelZip, ZMCore, ZMHash,
{$IFDEF STATIC_LOAD_DELZIP_DLL}
  ZMSBind,
{$ELSE}
  ZMDBind,
{$ENDIF}
  ZipSFX, ZMXcpt, windows;


type
  pLargeInt = ^Int64;

//------------------------------------------------------------------------

type
  TZipNumberScheme = (znsNone, znsVolume, znsName, znsExt);

type
  TZMWorker = class(
{$IFDEF STATIC_LOAD_DELZIP_DLL}
  TZMStaticBind
{$ELSE}
  TZMDynamicBind
{$ENDIF}
  )
  private
    FAddCompLevel: Integer;
    fAddOptions: AddOpts;
    FAddStoreSuffixes: AddStoreExts;
    FCodePage: CodePageOpts;
{$IFNDEF NO_SPAN}
    fConfirmErase: Boolean;  
{$ENDIF}
    FDateStamp: Integer;
    FDelaying: TZipDelays;
    FDirOnlyCount: Integer;
    FDiskFree: LargeInt;
    FDiskNr: Integer;   
{$IFNDEF NO_SPAN}
    FDiskWritten: Cardinal;
{$ENDIF}
    FDrive: String;
    FDriveFixed: Boolean;  
{$IFNDEF NO_SPAN}
    FDriveNr: Integer;  
{$ENDIF}
    FEncrypt: Boolean;
    FEOCComment: String;
    fExtAddStoreSuffixes: String;
    FExtrBaseDir: String;
    FExtrOptions: ExtrOpts;
    FFileSize: Cardinal;
    FFreeOnAllDisks: Cardinal;
    FFreeOnDisk: LargeInt;
    FFreeOnDisk1: Cardinal;
    fFromDate: TDate;
    FFSpecArgs: TStrings;
    FFSpecArgsExcl: TStrings;
    fHandle: HWND;
    FHowToDelete: TDeleteOpts;
    FInFileHandle: Integer;
    FInFileName: String;   
{$IFNDEF NO_SPAN}
    FInteger: Integer;    
{$ENDIF}
    FIsSpanned: Boolean;
    FMaxVolumeSize: Integer;
    FMinFreeVolSize: Integer;
    FDirHashs: TZipDirHashList;
{$IFNDEF NO_SPAN}
    FNewDisk: Boolean;
    FNumbering: TZipNumberScheme;
{$ENDIF}
    FOutFileHandle: Integer; 
{$IFNDEF NO_SPAN}
    FOutFileName: String; 
{$ENDIF}
    FPassword: String;
    FPasswordReqCount: Longword;
    FRealFileSize: Cardinal;
    FRootDir: String;
    FSFX: TZipSFX;
    FSFXOffset: Cardinal;
    FShowProgress: TZipShowProgress;
    FSizeOfDisk: LargeInt;
    FSpanOptions: SpanOpts;
    FStoredExtraData: AnsiString;
    FSuccessCnt: Integer;
    FTotalDisks: Integer;
    fUnzBusy: Boolean;
    FUseDirOnlyEntries: Boolean;
    FVersionMadeBy0: Integer;
    FVersionMadeBy1: Integer;
    FVolumeName: String;
    FVolumeReadOnly: Boolean;
    FWrongZipStruct: Boolean;
    fZipBusy: Boolean;
    FZipComment: String;
    fZipContents: TList;
{$IFNDEF NO_SPAN}
    FZipDiskAction: TZipDiskAction;
    FZipDiskStatus: TZipDiskStatus;
{$ENDIF}
    FZipEOC: Cardinal;
    FZipFileName: String;
    FZipSOC: Cardinal;
    FZipStream: TZipStream;
    function GetCount: Integer;
    function GetZipComment: String;
    procedure SetActive(Value: Boolean);
  procedure SetDirHashs(const Value: TZipDirHashList);
    procedure SetExtAddStoreSuffixes(Value: String);
    procedure SetFileName(Value: String);
    procedure SetPasswordReqCount(Value: Longword);
    procedure SetZipComment(zComment: String);
  protected
    function AddStoreExtStr(Options: AddStoreExts): String;
{$IFNDEF NO_SPAN}
    procedure CheckForDisk(writing: boolean);
    procedure ClearFloppy(dir: String);       
{$ENDIF}
    function ConvertOEM(const Source: String; Direction: CodePageDirection): String;
    function CopyBuffer(InFile, OutFile: Integer; ReadLen: Int64): Integer;
    procedure CreateMVFileNameEx(var FileName: String; StripPartNbr, Compat:
        Boolean);
    procedure DiskFreeAndSize(Action: Integer);
    procedure DllCallback(ZCallBackRec: PZCallBackStruct);
    procedure ExtAdd(UseStream: Integer; StrFileDate, StrFileAttr: DWORD;
        MemStream: TMemoryStream);
    procedure ExtExtract(UseStream: Integer; MemStream: TMemoryStream);
    procedure FreeZipDirEntryRecords;
    function GetDirEntry(idx: Integer): pZipDirEntry;
    function GetDriveProps: Boolean;
{$IFNDEF NO_SPAN}
    function GetLastVolume(FileName:
        String; var EOC: ZipEndOfCentral; AllowNotExists: Boolean): Integer;
{$ENDIF}
    procedure GetNewDisk(DiskSeq: Integer);
    function GetSFXSlave: TzipSFX;
    function CheckDestWritable(const fname: String; NoExc: boolean): Boolean;
    function IsFixedDrive(drv: String): Boolean;
{$IFNDEF NO_SPAN}
    function IsRightDisk: Boolean;
//  function MakeString(Buffer: PAnsiChar; Size: Integer): String; //RP 2010-04-24
{$ENDIF}
    function OpenEOC(var EOC: ZipEndOfCentral; DoExcept: Boolean): Boolean;
    procedure ReadJoin(var Buffer; BufferSize, DSErrIdent: Integer);
    procedure RecreateMVArchive(TmpZipName: String; Recreate: Boolean);
    function RejoinMVArchive(var TmpZipName: String; Rejoin: Boolean): Integer;
{$IFNDEF NO_SPAN}
    procedure RWJoinData(var Buffer; ReadLen: Cardinal; DSErrIdent: Integer);
    procedure RWSplitData(var Buffer; ReadLen: Cardinal; ZSErrVal: Integer);
{$ENDIF}
    procedure SetCancel(Value: Boolean); override;
    procedure SetDeleteSwitches(zpParms: pZipParms);
    procedure SetUnZipSwitches(const NameOfZipFile: String; uzParms: pUnZipParms);
    procedure SetZipSwitches(const NameOfZipFile: String; zpParms: pZipParms);
    procedure WriteJoin(const Buffer; BufferSize: Cardinal; DSErrIdent: Integer);
{$IFNDEF NO_SPAN}
    procedure WriteSplit(const Buffer; Len, MinSize: Cardinal);
    function ZipFormat: Integer;
{$ENDIF}
  public
    constructor Create(AMaster: TCustomZipMaster);
    destructor Destroy; override;
    function Add: Integer;
    function AddStreamToFile(Filename: String; FileDate, FileAttr: Dword): Integer;
    function AddStreamToStream(InStream: TMemoryStream): TZipStream;
    procedure BeforeDestruction; override;
    procedure Clear; override;
    function ConvertSFX: Integer;
    function ConvertZIP: Integer;
    function CopyZippedFiles(DestZipMaster: TZMWorker; DeleteFromSource: Boolean;
        OverwriteDest: OvrOpts): Integer;
    function Copy_File(const InFileName, OutFileName: String): Integer;
    function Delete: Integer;
    procedure Done; override;
    function Extract: Integer;
    function ExtractFileToStream(Filename: String): TZipStream;
    function ExtractStreamToStream(InStream: TMemoryStream; OutSize: Longword):
        TZipStream;
    function GetAddPassword(var Response: TPasswordButton): String;
    function GetExtrPassword(var Response: TPasswordButton): String;
    function GetPassword(DialogCaption, MsgTxt: String; ctx: Integer; pwb:
        TPasswordButtons; var ResultStr: String): TPasswordButton; overload;
    function GetPassword(DialogCaption, MsgTxt: String; pwb: TPasswordButtons; var
        ResultStr: String): TPasswordButton; overload;
    function IsZipSFX(const SFXExeName: String): Integer;
    function List: Integer;
    function NewSFXFile(const ExeName: String): Integer;     
{$IFNDEF NO_SPAN}
    function ReadSpan(InFileName: String; var OutFilePath: String; useXProgress:
        Boolean): Integer;
{$ENDIF}
    //1 Changed 1.79.10.07
    function Rename(RenameList: TList; DateTime: Integer; How: TZMRenameOpts =
        htrDefault): Integer;
    procedure Starting; override;
{$IFNDEF NO_SPAN}
    function WriteSpan(InFileName, OutFileName: String; useXProgress: Boolean):
        Integer;
{$ENDIF}
    property Active: Boolean read FActive write SetActive;
    property AddCompLevel: Integer read FAddCompLevel write FAddCompLevel;
    property AddFrom: TDate read fFromDate write fFromDate;
    property AddOptions: AddOpts read FAddOptions write fAddOptions;
    property AddStoreSuffixes: AddStoreExts read FAddStoreSuffixes write
        FAddStoreSuffixes;
    property CodePage: CodePageOpts read FCodePage write FCodePage default cpAuto;  
{$IFNDEF NO_SPAN}
    property ConfirmErase: Boolean read fConfirmErase write fConfirmErase default
        True;   
{$ENDIF}
    property Count: Integer read GetCount;
    property DirEntry[idx: Integer]: pZipDirEntry read GetDirEntry; default;
  property DirHashs: TZipDirHashList read FDirHashs write SetDirHashs;
    property DirOnlyCount: Integer read FDirOnlyCount;
    property ExtAddStoreSuffixes: String read fExtAddStoreSuffixes write
        SetExtAddStoreSuffixes;
    property ExtrBaseDir: String read FExtrBaseDir write FExtrBaseDir;
    property ExtrOptions: ExtrOpts read FExtrOptions write FExtrOptions;
    property FSpecArgs: TStrings read fFSpecArgs write fFSpecArgs;
    property FSpecArgsExcl: TStrings read fFSpecArgsExcl write fFSpecArgsExcl;
    property Handle: HWND read fHandle write fHandle;
    property HowToDelete: TDeleteOpts read FHowToDelete write FHowToDelete;
    property IsSpanned: Boolean read FIsSpanned;    
{$IFNDEF NO_SPAN}
    property KeepFreeOnAllDisks: Cardinal read FFreeOnAllDisks write
        FFreeOnAllDisks;
    property KeepFreeOnDisk1: Cardinal read FFreeOnDisk1 write FFreeOnDisk1;
    property MaxVolumeSize: Integer read FMaxVolumeSize write FMaxVolumesize;
    property MinFreeVolumeSize: Integer read FMinFreeVolSize write FMinFreeVolSize
        default 65536;  
{$ENDIF}
    property Password: String read FPassword write FPassword;
    property PasswordReqCount: Longword read FPasswordReqCount write
        SetPasswordReqCount;
    property RootDir: String read FRootDir write fRootDir;
    property SFXOffset: Cardinal read FSFXOffset;
    property SFXSlave: TZipSFX read fSFX write fSFX;
{$IFNDEF NO_SPAN}
    property SpanOptions: SpanOpts read FSpanOptions write FSpanOptions;
{$ENDIF}
    property SuccessCnt: Integer read FSuccessCnt;
    property TotalSizeToProcess: Int64 read GetTotalSizeToProcess;
    property UnzBusy: Boolean read fUnzBusy;
    property UseDirOnlyEntries: Boolean read FUseDirOnlyEntries write
        FUseDirOnlyEntries default False;
    property ZipBusy: Boolean read fZipBusy;
    property ZipComment: String read GetZipComment write SetZipComment;
    property ZipContents: TList read FZipContents;
    property ZipEOC: Cardinal read FZipEOC;
    property ZipFileName: String read FZipFileName write SetFileName;
    property ZipFileSize: Cardinal read FRealFileSize;
    property ZipSOC: Cardinal read FZipSOC;
    property ZipStream: TZipStream read FZipStream;
  end;

implementation

uses
  SFXInterface, {ZMCompat,} ZMUtils, ZMDlg, ZMCtx, ZMMsgStr, ZipMsg, ZMCompat;

{$R ZipMstr.Res}

const
  BufSize = 10240;
  //8192;   // Keep under 12K to avoid Winsock problems on Win95.
  // If chunks are too large, the Winsock stack can
  // lose bytes being sent or received.
//  FlopBufSize = 65536;
  DetachMask: cardinal = $FFFFFFBF;//not $40;

 { Define the functions that are not part of the TZMWorker class. }

type
  // 1.79 10 Mar 2009 RP changed for setting new comment
  // 1.75 18 Feb 2004 RP changed for >2G
  TMDZipData = class//record                        // MyDirZipData
  private
    FComprSize: Longword;
    FCRC32: Longword;
    FDateTime: Integer;
    FDiskstart: Word;
    FFileNameA: AnsiString;
    FNComment: AnsiString;
    FRelOffLocal: Int64;
    FUnComprSize: Longword;
    FVerMade: WORD;
    function GetFileName: string;
    procedure SetFileName(const Value: string);
  public
    procedure SetName(const src: PAnsiChar; Len: Integer);
    property ComprSize: Longword read FComprSize write FComprSize;
    property CRC32: Longword read FCRC32 write FCRC32;
    property DateTime: Integer read FDateTime write FDateTime;
    property Diskstart: Word read FDiskstart write FDiskstart;
    property FileName: string read GetFileName write SetFileName;
    property FileNameA: AnsiString read FFileNameA write FFileNameA;
    property NComment: AnsiString read FNComment write FNComment;
    property RelOffLocal: Int64 read FRelOffLocal write FRelOffLocal;
    property UnComprSize: Longword read FUnComprSize write FUnComprSize;
    property VerMade: WORD read FVerMade write FVerMade;
  end;
//  pMZipData = ^MDZipData;

  TZMDataList = class (TList)
  PRIVATE
//    function GetItems(Index: Integer): pMZipData;
    function GetItems(Index: Integer): TMDZipData;
  PUBLIC
    constructor Create(TotalEntries: Integer);
    destructor Destroy; OVERRIDE;
    function IndexOf(fname: String): Integer; overload;
    function IndexOf(const hname: PAnsiChar; len: Integer): Integer; overload;
//    property Items[Index: Integer]: pMZipData READ GetItems;
    property Items[Index: Integer]: TMDZipData READ GetItems;
  end;

  {TMDZipData}
function TMDZipData.GetFileName: string;
begin
  Result := String(FileNameA);
end;

procedure TMDZipData.SetFileName(const Value: string);
begin
  FileNameA := AnsiString(Value);
end;

procedure TMDZipData.SetName(const src: PAnsiChar; Len: Integer);
var
  I: Integer;
  p: PAnsiChar;
begin
  p := src;
  SetLength(fFileNameA, Len);
  for I := 1 to Len do
  begin
    fFileNameA[I] := p^;
    inc(p);
  end;
end;

  {ZipDataList}
(*? TMZipDataList.Create
*)
constructor TZMDataList.Create(TotalEntries: Integer);
var
  i: Integer;
  zd: TMDZipData;
begin
  inherited Create;
  Capacity := TotalEntries;
  for i := 1 to TotalEntries do
  begin
    zd := TMDZipData.Create;
    Add(zd);
  end;
end;

(*? TMZipDataList.Destroy
*)
destructor TZMDataList.Destroy;
var
  i: Integer;
  zd: TMDZipData;
begin
  if Count > 0 then
    for i := (Count - 1) downto 0 do
    begin   // dispose of the memory pointed-to by this entry
      zd := Items[i];
      if Assigned(zd) then
        zd.Free;

      Delete(i);    // delete the TList pointer itself
    end;
  inherited Destroy;
end;

(*? TMZipDataList.GetItems
*)
function TZMDataList.GetItems(Index: Integer): TMDZipData;//pMZipData;
begin
  if Index >= Count then
    raise ERangeError.Create('Index out of range');
  Result := inherited Items[Index];
end;

(*? TMZipDataList.IndexOf
*)
function TZMDataList.IndexOf(fname: String): Integer;
var
  MDZDp: TMDZipData;
  Found: Boolean;
begin
  Found := False;
  for Result := 0 to (Count - 1) do
  begin
    MDZDp := Items[Result];
//    if CompareText(fname, MDZDp^.FileName) = 0 then
//    if CompareText(fname, MDZDGetName(MDZDp)) = 0 then // case insensitive compare
    if CompareText(fname, MDZDp.FileName) = 0 then // case insensitive compare
    begin
      Found := True;
      break;
    end;
//      break;
  end;
  // Should not happen, but maybe in a bad archive...
//  if Result = Count then
  if not Found then
    raise EZipMaster.CreateDisp(
      'A local header not found in internal structure', True);
  //    raise EZipMaster.CreateResDisp( DS_EntryLost, True);
end;

(*? TMZipDataList.IndexOf
*)
// find the index of an entry holding a header name
function TZMDataList.IndexOf(const hname: PAnsiChar; len: Integer): Integer;
var
  MDZDp: TMDZipData;
  Found: Boolean;
begin
  Found := False;
  for Result := 0 to (Count - 1) do
  begin
    MDZDp := Items[Result];
    if (MDZDp = nil) or (len <> Length(MDZDp.FileNameA)) then
      continue;
    if CompareMem(hname, PAnsiChar(MDZDp.FileNameA), len) then
    begin
      Found := True;
      break;
    end;
  end;
  // Should not happen, but maybe in a bad archive...
  if not Found then
    raise EZipMaster.CreateDisp(
      'A local header not found in internal structure', True);
  //    raise EZipMaster.CreateResDisp( DS_EntryLost, True);
end;
      

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


(*? FormatFloppy
*)
{$IFNDEF NO_SPAN}
function FormatFloppy(WND: HWND; Drive: String): Integer;
const
  SHFMT_ID_DEFAULT = $FFFF;
  {options}
  SHFMT_OPT_FULL = $0001;
  SHFMT_OPT_SYSONLY = $0002;
  {return values}
  SHFMT_ERROR = $FFFFFFFF;
  // -1 Error on last format, drive may be formatable
  SHFMT_CANCEL = $FFFFFFFE;    // -2 last format cancelled
  SHFMT_NOFORMAT = $FFFFFFFD;    // -3 drive is not formatable
type
  TSHFormatDrive = function(WND: HWND;
      Drive, fmtID, Options: DWORD): DWORD;
    STDCALL;
const
  SHFormatDrive: TSHFormatDrive = Nil;
var
  drv:  Integer;
  hLib: THandle;
  OldErrMode: Integer;
begin
  Result := -3;                             // error
  if not ((Length(Drive) > 1) and (Drive[2] = ':') and
//    CharInSet(Drive[1], ['A'..'Z', 'a'..'z'])) then
{$IFDEF UNICODE}
      CharInSet(Drive[1], ['A'..'Z', 'a'..'z'])) then
{$ELSE}
      (Drive[1] in ['A'..'Z', 'a'..'z'])) then
{$ENDIF}
//    (Upcase(Drive[1]) in ['A'..'Z'])) then
    exit;
  if GetDriveType(Pchar(Drive)) <> DRIVE_REMOVABLE then
    exit;
  drv := Ord(Upcase(Drive[1])) - Ord('A');
  OldErrMode := SetErrorMode(SEM_FAILCRITICALERRORS or
    SEM_NOGPFAULTERRORBOX);
  hLib := LoadLibrary('Shell32');
  if hLib <> 0 then
  begin
    @SHFormatDrive := GetProcAddress(hLib, 'SHFormatDrive');
    if @SHFormatDrive <> Nil then
      try
        Result := SHFormatDrive(WND, drv, SHFMT_ID_DEFAULT,
          SHFMT_OPT_FULL);
      finally
        FreeLibrary(hLib);
      end;
    SetErrorMode(OldErrMode);
  end;
end;
{$ENDIF}

(*? ZCallback
1.76 01 May 2004 RP change return type and value to return flag for exception
1.76 24 April 2004 RP use DllCallback
1.73 ( 1 June 2003) changed for new callback
{ Dennis Passmore (Compuserve: 71640,2464) contributed the idea of passing an
 instance handle to the DLL, and, in turn, getting it back from the callback.
 This lets us referance variables in the TZMWorker class from within the
 callback function.  Way to go Dennis!
 Modified by Russell Peters }
*)
function ZCallback(Caller: pointer; ZCallBackRec: PZCallBackStruct): Longint; STDCALL;
begin
//  if TObject(Caller) is TZMWorker then
//  with TZMWorker(TObject(Caller)) do
  with TObject(Caller) as TZMWorker do
  begin
    DllCallback(ZCallBackRec);
    if fEventErr <> '' then
      Result := Callback_Except_No        // handled exception
    else
      Result := Ord(Cancel);
  end;
end;

(*? TZMWorker.Add
*)
function TZMWorker.Add: Integer;
begin
  ExtAdd(0, 0, 0, Nil);
  Result := fErrCode;
end;

(*? TZMWorker.AddStoreExtStr
*)
function TZMWorker.AddStoreExtStr(Options: AddStoreExts): String;
const
  SuffixStrings: array[AddStoreSuffixEnum] of Pchar =
    ('gif', 'png', 'z', 'zip', 'zoo', 'arc', 'lzh', 'arj', 'taz', 'tgz',
    'lha', 'rar', 'ace', 'cab', 'gz', 'gzip', 'jar', 'exe', '',
    'jpg', 'jpeg', '7zp', 'mp3', 'wmv', 'wma', 'dvr-ms', 'avi');
var
  o: AddStoreSuffixEnum;
begin
  for o := Low(AddStoreSuffixEnum) to High(AddStoreSuffixEnum) do
  begin
    if (o <> assEXT) and (o in Options) then
      Result := Result + '.' + String(SuffixStrings[o]) + ':';
  end;
  if assExt in Options then
    Result := Result + fExtAddStoreSuffixes;
end;

(*? TZMWorker.AddStreamToFile
1.76 10 June 2004 RA fix access to FSpecArgs
1.73 14 JUly 2003 RA check wildcards & initial FSuccessCnt
// FileAttr are set to 0 as default.
// FileAttr can be one or a logical combination of the following types:
// FILE_ATTRIBUTE_ARCHIVE, FILE_ATTRIBUTE_HIDDEN, FILE_ATTRIBUTE_READONLY, FILE_ATTRIBUTE_SYSTEM.
// FileName is as default an empty string.
// FileDate is default the system date.

// EWE: I think 'Filename' is the name you want to use in the zip file to
// store the contents of the stream under.
*)
function TZMWorker.AddStreamToFile(Filename: String;
  FileDate, FileAttr: DWORD): Integer;
var
  st:  TSystemTime;
  ft:  TFileTime;
  FatDate, FatTime: Word;
begin 
  if Length(Filename) > 0 then
  begin
    FFSpecArgs.Clear();
    FFSpecArgs.Add(FileName);
  end;
  if FileDate = 0 then
  begin
    GetLocalTime(st);
    SystemTimeToFileTime(st, ft);
    FileTimeToDosDateTime(ft, FatDate, FatTime);
    FileDate := (DWORD(FatDate) shl 16) + FatTime;
  end;
  FSuccessCnt := 0;
  // Check if wildcards are set.
  if FFSpecArgs.Count > 0 then
    if IsWild(FFSpecArgs.Strings[0]) then
      ShowZipMessage(AD_InvalidName, '')
    else
      ExtAdd(1, FileDate, FileAttr, Nil)
  else
    ShowZipMessage(AD_NothingToZip, '');
  Result := fErrCode;
end;

(*? TZMWorker.AddStreamToStream
1.73 14 July 2003 RA Initial FSuccesCnt
*)
function TZMWorker.AddStreamToStream(InStream: TMemoryStream): TZipStream;
begin
  Result := Nil;
  FSuccessCnt := 0;
  if InStream = FZipStream then
  begin
    ShowZipMessage(AD_InIsOutStream, '');
    Exit;
  end;
  if assigned(InStream) and (InStream.Size > 0) then
  begin
    FZipStream.SetSize(InStream.Size + 6);
    // Call the extended Add procedure:
    ExtAdd(2, 0, 0, InStream);
    { The size of the output stream is reset by the dll in ZipParms2 in fOutStreamSize.
     Also the size is 6 bytes more than the actual output size because:
     - the first two bytes are used as flag, STORED=0 or DEFLATED=8.
     - the next four bytes are set to the calculated CRC value.
     The size is reset from Inputsize +6 to the actual data size +6.
     (you do not have to set the size yourself, in fact it won't be taken into account.
     The start of the stream is set to the actual data start. }
    if FSuccessCnt = 1 then
      FZipStream.Position := 6
    else
      FZipStream.SetSize(0);
  end
  else
    ShowZipMessage(AD_NothingToZip, '');
  Result := FZipStream;
end;

(*? TZMWorker.BeforeDestruction
1.73 3 July 2003 RP stop callbacks
*)
{$IFDEF VERD4+}
procedure TZMWorker.BeforeDestruction;
begin
  fIsDestructing := True;                   // stop callbacks
  inherited;
end;
{$ENDIF}

(*? TZMWorker.CheckForDisk
1.77 31 August 2004 RP - allow cancel on hard drive
1.77 18 Aug 2004 RA - allow unattended on hard drive
 // 1.70 changed - no longer check fZipBusy uses writing instead
 // 1.72 changed - now a procedure
 // ask for disk with required part (FDriveNr)
*)
{$IFNDEF NO_SPAN}
procedure TZMWorker.CheckForDisk(writing: boolean);
var
  Res, MsgFlag: Integer;
  SizeOfDisk: LargeInt;     // RCV150199
  MsgStr: String;
  AbortAction: Boolean;
  tmpGetNextDisk: TGetNextDiskEvent;
begin
  FDriveFixed := IsFixedDrive(FDrive);
  if FDriveFixed then
  begin
    // If it is a fixed disk we don't want a new one.
    FNewDisk := False;
    if FCancel then
      raise EZipMaster.CreateResDisp( DS_Canceled, False);
    exit;
  end;
  Report(zacTick, 0, '', 0);              // just ProcessMessages

  Res := idOk;
  MsgFlag := zmtWarning + DHC_SpanNxtW;   // or error?

  // First check if we want a new one or if there is a disk (still) present.
  while (FNewDisk or ((Res = idOk) and not GetDriveProps)) do
  begin
    if Unattended then
      raise EZipMaster.CreateResDisp( DS_NoUnattSpan, True);
    if FDiskNr < 0 then
      // -1=ReadSpan(), 0=WriteSpan()
    begin
      MsgStr := ZipLoadStr(DS_InsertDisk);
      MsgFlag := zmtError + DHC_SpanNxtR;//MsgFlag or MB_ICONERROR;
    end
    else
    if writing then
      // Are we from ReadSpan() or WriteSpan()?
    begin
      // This is an estimate, we can't know if every future disk has the same space available and
      // if there is no disk present we can't determine the size unless it's set by MaxVolumeSize.
      SizeOfDisk := FSizeOfDisk - FFreeOnAllDisks;
      if (FMaxVolumeSize <> 0) and (FMaxVolumeSize <
        FSizeOfDisk) then
        SizeOfDisk := FMaxVolumeSize;

      FTotalDisks := FDiskNr;
      if (SizeOfDisk > 0) and (FTotalDisks < Trunc((FFileSize + 4 +
        FFreeOnDisk1) / SizeOfDisk)) then // RCV150199
        FTotalDisks := Trunc(
          (FFileSize + 4 + FFreeOnDisk1) / SizeOfDisk);
      if SizeOfDisk > 0 then
        MsgStr := ZipFmtLoadStr(DS_InsertVolume,
          [FDiskNr + 1, FTotalDisks + 1])
      else
        MsgStr := ZipFmtLoadStr(DS_InsertAVolume, [FDiskNr + 1]);
    end
    else
      MsgStr := ZipFmtLoadStr(DS_InsertVolume,
        [FDiskNr + 1, FTotalDisks + 1]);
    MsgStr := MsgStr + ZipFmtLoadStr(DS_InDrive, [FDrive]);

    if not ((FDiskNr = 0) and GetDriveProps and writing) then
    begin
      tmpGetNextDisk := Events.OnGetNextDisk;
      if Assigned(tmpGetNextDisk) then
      begin
        AbortAction := False;
        tmpGetNextDisk(Master, FDiskNr + 1,
          FTotalDisks + 1, Copy(FDrive, 1, 1), AbortAction);
        if AbortAction then
          Res := idAbort
        else
          Res := idOk;
      end
      else
        Res := ZipMessageDlgEx('', MsgStr, MsgFlag, mbOkCancel);
    end;
    FNewDisk := False;
  end;

  // Check if user pressed Cancel or memory is running out.
  if Res <> idOk then
    raise EZipMaster.CreateResDisp( DS_Canceled, False);
  if Res = 0 then
    raise EZipMaster.CreateResDisp( DS_NoMem, True);
end;
{$ENDIF}

(*? TZMWorker.Clear
1.76 26 May 2004 expanded
1.73.3.4 14 January 2004 RP added
 Clears lists and strings
*)
procedure TZMWorker.Clear;
begin
  fIsDestructing := True;                   // stop callbacks
  AbortDll;
  FCancel := True;
  FreeZipDirEntryRecords;
  fReenter := False;

  FDelaying := [];
  FRealFileSize := 0;
  FIsSpanned := False;
  //  fErrCode := 0;
  FFSpecArgs.Clear;
  FFSpecArgsExcl.Clear;
  FZipFileName := '';
  FDelaying := [];
  FZipBusy := False;
  FUnzBusy := False;
  FZipFileName := '';
  FPassword := '';
  FPasswordReqCount := 1;
  FEncrypt := False;
  FSuccessCnt := 0;
  FAddCompLevel := 9;   // dflt to tightest compression
  FUnattended := False;
  FRealFileSize := 0;
  FSFXOffset := 0;
  FZipSOC := 0;
  FFreeOnDisk1 := 0;
  { Don't leave any freespace on disk 1. }
  FFreeOnAllDisks := 0;                     // use all space
  FMaxVolumeSize := 0;
  { Use the maximum disk size. }
  FMinFreeVolSize := 65536;
  { Reject disks with less free bytes than... }
  FCodePage := cpAuto;
  FIsSpanned := False;
  FZipComment := '';
  FHowToDelete := htdAllowUndo;
  FAddStoreSuffixes := DefAddStoreSuffixes;
  FUseDirOnlyEntries := False;
  FDirOnlyCount := 0;
  FSpanOptions := [];
{$IFNDEF NO_SPAN}
  fConfirmErase := True;
{$ENDIF} 
  inherited;
end;

(*? TZMWorker.ClearFloppy
   remove files from floppy disk
*)
{$IFNDEF NO_SPAN}
procedure TZMWorker.ClearFloppy(dir: String);
var
  SRec:  TSearchRec;
  Fname: String;
begin
  if FindFirst(Dir + '*.*', faAnyFile, SRec) = 0 then
    repeat
      Fname := Dir + SRec.Name;
      if ((SRec.Attr and faDirectory) <> 0) and
        (SRec.Name <> '.') and
        (SRec.Name <> '..') then
      begin
        Fname := Fname + '\';
        ClearFloppy(Fname);
        if (Trace) then
          Report(zacMessage, 0,
            ZipFmtLoadStr(TM_Erasing, [Fname]), 0)
        else
          Report(zacTick, 0, '', 0);
        //allow time for OS to delete last file
        RemoveDir(Fname);
      end
      else
      begin
        if (Trace) then
          Report(zacMessage, 0,
            ZipFmtLoadStr(TM_Deleting, [Fname]), 0)
        else
          Report(zacTick, 0, '', 0);
        SysUtils.DeleteFile(Fname);
      end;
    until FindNext(SRec) <> 0;
  SysUtils.FindClose(SRec);
end;
{$ENDIF}

(*? TZMWorker.ConvertOEM
1.73 24 July 2003 RA adjust result string length
1.73 ( 2 June 2003) RP replacement function that should be able to handle MBCS
 Convert filename (and file comment string) into 'internal' charset (ISO).
 * This function assumes that Zip entry filenames are coded in OEM (IBM DOS)
 * codepage when made on:
 *  -> DOS (this includes 16-bit Windows 3.1)  (FS_FAT_  {0} )
 *  -> OS/2                                    (FS_HPFS_ {6} )
 *  -> Win95/WinNT with Nico Mak''s WinZip      (FS_NTFS_ {11} && hostver == '5.0' {50} )
 *
 * All other ports are assumed to code zip entry filenames in ISO 8859-1.
 * But norton Zip v1.0 sets the host byte as OEM(0) but does use the ISO set,
 * thus archives made by NortonZip are not recognized as being ISO.
 * (In this case you need to set the CodePage property manualy to cpNone.)
 * When ISO is used in the zip archive there is no need for translation
 * and so we call this cpNone.
 *)
function TZMWorker.ConvertOEM(const Source: String;
  Direction: CodePageDirection): String;
const
  FS_FAT: Integer = 0;
  FS_HPFS: Integer = 6;
  FS_NTFS: Integer = 11;
var
  buf: String;
{$ifdef UNICODE}
  bufA: AnsiString;
{$endif}
begin
  Result := Source;
  if ((FCodePage = cpAuto) and (FVersionMadeBy1 = FS_FAT) or
    (FVersionMadeBy1 =
    FS_HPFS) or ((FVersionMadeBy1 = FS_NTFS) and
    (FVersionMadeBy0 = 50))) or
    (FCodePage = cpOEM) then

{$ifdef UNICODE}
  begin
//    SetLength(buf, 2 * Length(Source) + 1);
    // allow worst case - all double
    if (Direction = cpdOEM2ISO) then
    begin
      SetLength(buf, Length(Source) + 4);
      bufA := AnsiString(Source);
      OemToChar(PAnsiChar(bufA), Pchar(buf));
      Result := Pchar(buf);
    end
    else
    begin
      SetLength(bufA, Length(Source) + 4);
      bufA := AnsiString(Source);
      CharToOem(Pchar(Source), PAnsiChar(bufA));
      Result := string(PAnsiChar(bufA));
    end;
  end;
{$else}
  begin
    SetLength(buf, 2 * Length(Source) + 1);
    // allow worst case - all double
    if (Direction = cpdOEM2ISO) then
      OemToChar(Pchar(Source), Pchar(buf))
    else
      CharToOem(Pchar(Source), Pchar(buf));
    Result := Pchar(buf);
  end;
{$endif}
end;

(*? TZMWorker.ConvertSFX
1.78 23 Nov 2004 change exception reporting
1.76 10 May 2004 check file type
1.73 15 July 2003 RA handling of exceptions
*)
function TZMWorker.ConvertSFX: Integer;
var
  slave: TZipSFX;
  tmpMessage: TMessageEvent;
begin
  slave := GetSFXSlave;
  ErrCode := 0;
  FSuccessCnt := 1;

  Result := 0;
  try
    CheckDestWritable(FZipFileName, false);
//    if not CheckDestWritable(FZipFileName) then
//      raise EZipMaster.CreateResDrive( DS_NotChangeable, FZipFileName);
    with slave do
    begin
      SourceFile := FZipFileName;
      TargetFile := ChangeFileExt(FZipFileName, '.exe');
    end;
    Slave.Convert;
  except
    on E: EZipMaster do
    begin
      FErrCode := E.ResId;
      if FUnattended = False then
        ZipMessageDlg(E.Message, DHC_ExSFX2EXE);  
      tmpMessage := Events.OnMessage;
      if Assigned(tmpMessage) then
        tmpMessage(Master, ErrCode, E.Message);
      Result := -9;
      FSuccessCnt := 0;
    end;
    on E: Exception do
    begin
      FErrCode := GE_Unknown;
      if FUnattended = False then
        ZipMessageDlg(E.Message, DHC_ExSFX2EXE);  
      tmpMessage := Events.OnMessage;
      if Assigned(tmpMessage) then
        tmpMessage(Master, 0, E.Message);
      Result := -9;
      FSuccessCnt := 0;
    end;
  end;
end;

(*? TZMWorker.ConvertZIP
1.78 23 Nov 2004 change exception reporting
1.76 10 May 2004 check file type
1.73 15 July 2003 RA handling of exceptions
{ Convert an .EXE archive to a .ZIP archive. }
{ returns 0 if good, or else a negative error code }
*)
function TZMWorker.ConvertZIP: Integer;
var
  slave: TZipSFX;
  tmpMessage: TMessageEvent;
begin
  slave := GetSFXSlave;
  Result := 0;
  ErrCode := 0;
  FSuccessCnt := 1;
  try
    CheckDestWritable(FZipFileName, false);
//    if not CheckDestWritable(FZipFileName) then
//      raise EZipMaster.CreateResDrive( DS_NotChangeable, FZipFileName);
    with slave do
    begin
      SourceFile := FZipFileName;
      TargetFile := ChangeFileExt(FZipFileName, '.zip');
    end;
    Slave.Convert;
  except
    on E: EZipMaster do
    begin
      FErrCode := E.ResId;
      if FUnattended = False then
        ZipMessageDlg(E.Message, DHC_ExSFX2Zip); 
      tmpMessage := Events.OnMessage;
      if Assigned(tmpMessage) then
        tmpMessage(Master, ErrCode, E.Message);
      Result := -9;
      FSuccessCnt := 0;
    end;
    on E: Exception do
    begin
      FErrCode := GE_Unknown;
      if FUnattended = False then
        ZipMessageDlg(E.Message, DHC_ExSFX2Zip);
      tmpMessage := Events.OnMessage;
      if Assigned(tmpMessage) then
        tmpMessage(Master, 0, E.Message);
      Result := -9;
      FSuccessCnt := 0;
    end;
  end;
end;

(*? TZMWorker.Copy_File
1.79 10 December 2004 RP trap dest = source
1.75 18 February 2004 Allow >2G
// Returns 0 if good copy, or a negative error code.
*)
function TZMWorker.Copy_File(const InFileName, OutFileName: String): Integer;
const
  SE_CreateError = -1;    // Error in open or creation of OutFile.
  SE_OpenReadError = -3;  // Error in open or Seek of InFile.
  SE_SetDateError = -4;   // Error setting date/time of OutFile.
  SE_GeneralError = -9;
var
  InFile, OutFile: Integer;
  InSize, OutSize: Int64;
begin
  InSize := -1;
  OutSize := -1;
  Result := SE_OpenReadError;
  FShowProgress := zspNone; 

  if not FileExists(InFileName) then
    Exit;
  InFile := FileOpen(InFileName, fmOpenRead or fmShareDenyWrite);
  if InFile <> -1 then
  begin
    if FileExists(OutFileName) then
    begin
      OutFile := FileOpen(OutFileName, fmOpenWrite or
        fmShareExclusive);
      if OutFile = -1 then
      begin
        Result := SE_CreateError;  // might be read-only or source
        File_Close(InFile);
        exit;
      end;
      File_Close(OutFile);
      EraseFile(OutFileName, FHowToDelete = htdFinal);
    end;
    StartWaitCursor;
    OutFile := FileCreate(OutFileName);
    if OutFile <> -1 then
    begin
      Result := CopyBuffer(InFile, OutFile, -1);
      if (Result = 0) and
        (FileSetDate(OutFile, FileGetDate(InFile)) <> 0) then
        Result := SE_SetDateError;
      OutSize := FileSeek64(OutFile, Int64(0), 2);
      File_Close(OutFile);
    end
    else
      Result := SE_CreateError;
    InSize := FileSeek64(InFile, Int64(0), 2);
    File_Close(InFile);
  end;
  // An extra check if the filesizes are the same.
  if (Result = 0) and ((InSize = -1) or (OutSize = -1) or
    (InSize <> OutSize)) then
    Result := SE_GeneralError;
  // Don't leave a corrupted outfile lying around. (SetDateError is not fatal!)
  if (Result <> 0) and (Result <> SE_SetDateError) then
    SysUtils.DeleteFile(OutFileName);

  StopWaitCursor;
end;

(*? TZMWorker.CopyBuffer
1.79 3 January 2006 RP copy > 2G
1.73 15 July 2003 RP progress
1.73 10 Jul 2003 RP use String as buffer
*)
function TZMWorker.CopyBuffer(InFile, OutFile: Integer; ReadLen: Int64):
    Integer;
const
  SE_CopyError = -2;
  // Write error or no memory during copy.
var
  SizeR: Integer;
  ToRead: Cardinal;
  Buffer: array of AnsiChar;
begin
  // both files are already open
  Result := 0;
  if ReadLen = 0 then
    exit;
  ToRead := BufSize;
  try
    SetLength(Buffer, BufSize);
    repeat
      if ReadLen >= 0 then
      begin
        ToRead := BufSize;
//        ToRead := ReadLen;
        if ReadLen < ToRead then
          ToRead := ReadLen;
//        if BufSize < ReadLen then
//          ToRead := BufSize;
      end;
      SizeR := FileRead(InFile, Buffer[0], ToRead);
      if (SizeR < 0)
          or (FileWrite(OutFile, Buffer[0], SizeR) <> SizeR) then
      begin
        Result := SE_CopyError;
        Break;
      end;
      if (ReadLen > 0) then
        ReadLen := ReadLen - Cardinal(SizeR);
//        if ReadLen > 0 then
//          Dec(ReadLen, SizeR);
      case FShowProgress of
        zspFull:
          Report(zacProgress, 0, '', SizeR);
        zspExtra:
          Report(zacXProgress, 0, '', SizeR);
        else
          Report(zacTick, 0, '', 0);        // Mostly for winsock.
      end;
    until ((ReadLen = 0) or (SizeR <> Integer(ToRead)));
  except
    Result := SE_CopyError;
  end;
  // leave both files open
end;

(*? TZMWorker.CopyZippedFiles
1.79 4 December 2006 RP allow to create new dest
1.79 2 December 2006 RP clean all Flag first
1.76 9 June 2004 RA properly assign not done files to FSpecArgs
1.76 24 April 2004 RA fix FInFileHandle not closed
1.75 18 February 2004 allow >2G
1.73.2.8 2 Oct 2003 RA fix slash
1.73  1 August 2003 RA close file or error
1.73 24 July 2003 RA init OutFileHandle
1.73 13 July 2003 RA removed second OpenEOC
1.73 12 July 2003 RP string extra data
// Function to copy one or more zipped files from the zip archive to another zip archive
// FSpecArgs in source is used to hold the filename(s) to be copied.
// When this function is ready FSpecArgs contains the file(s) that where not copied.
// Return values:
// 0            All Ok.
// -6           CopyZippedFiles Busy
// -7           CopyZippedFiles errors. See ZipMsgXX.rc
// -8           Memory allocation error.
// -9           General unknown CopyZippedFiles error.
*)
function TZMWorker.CopyZippedFiles(DestZipMaster: TZMWorker;
  DeleteFromSource: Boolean; OverwriteDest: OvrOpts): Integer;
var
  EOC:  ZipEndOfCentral;
  CEH:  ZipCentralHeader;
  OutFilePath: String;
  In2FileHandle: Integer;
  Found, Overwrite: Boolean;
  DestMemCount: Integer;
  NotCopiedFiles: TStringList;
  pzd, zde: pZipDirEntry;
  s, d: Integer;
  MDZD: TZMDataList;
  MDZDp: TMDZipData;
  tmpCopyZipOverwrite: TCopyZipOverwriteEvent;
  k: cardinal;
  StrA: AnsiString;
begin
  fZipBusy := True;
  FShowProgress := zspNone;
  NotCopiedFiles := Nil;
  Result := 0;
  In2FileHandle := -1;
  FOutFileHandle := -1;
  FDateStamp := 0;
  MDZD := Nil;

  StartWaitCursor;
  try
    // Are source and destination different?
    if (DestZipMaster = Self) or (AnsiStrIComp(Pchar(ZipFileName),
      Pchar(DestZipMaster.ZipFileName)) = 0) then
      raise EZipMaster.CreateResDisp( CF_SourceIsDest, True);
    CheckDestWritable(FZipFileName, false);
//    if not CheckDestWritable(FZipFileName) then
//      raise EZipMaster.CreateResDrive( DS_NotChangeable, FZipFileName);
    // The following function a.o. open the input file no. 1.
    // new 1.7 - stop attempt to copy spanned file
    OpenEOC(EOC, True);
    if (DestZipMaster.IsSpanned or IsSpanned) then
    begin
      File_Close(FInFileHandle);
      raise EZipMaster.CreateResDisp( CF_NoCopyOnSpan, True);
    end;
    // Now check for every source file if it is in the destination archive and determine what to do.
    // we use the three most significant bits from the Flag field from ZipDirEntry to specify the action
    // None           = 000xxxxx, Destination no change. Action: Copy old Dest to New Dest
    // Add            = 001xxxxx (New).                  Action: Copy Source to New Dest
    // Overwrite      = 010xxxxx (OvrAlways)             Action: Copy Source to New Dest
    // AskToOverwrite = 011xxxxx (OvrConfirm)            Action to perform: Overwrite or NeverOverwrite
    // NeverOverwrite = 100xxxxx (OvrNever)              Action: Copy old Dest to New Dest
    // Clean Flag first   
    for d := 0 to DestZipMaster.Count - 1 do
    begin
      zde := pZipDirEntry(DestZipMaster.ZipContents.Items[d]);
      zde^.Flag := zde^.Flag and $1FFF;
    end;
    for s := 0 to FSpecArgs.Count - 1 do
    begin
      Found := False;
      for d := 0 to DestZipMaster.Count - 1 do
      begin
        zde := pZipDirEntry(DestZipMaster.ZipContents.Items[d]);
        if AnsiStrIComp(Pchar(FSpecArgs.Strings[s]),
          Pchar(zde^.FileName)) = 0 then
        begin
          Found := True;
          k := 0; // keep compiler happy
          case OverwriteDest of
            OvrAlways: k := $4000;
            OvrNever: k := $8000;
            OvrConfirm: k:= $6000;
          end;
          // Clear the three upper bits.
          zde^.Flag := (zde^.Flag and $1FFF) or k;
{          if OverwriteDest = OvrAlways then
            zde^.Flag := zde^.Flag or $4000
          else
          if OverwriteDest = OvrNever then
            zde^.Flag := zde^.Flag or $8000
          else
            zde^.Flag := zde^.Flag or $6000; }
          Break;
        end;
      end;
      if not Found then
      begin
        // Add the Filename to the list and set flag
        New(zde);
        DestZipMaster.ZipContents.Add(zde);
        FDirHashs.Add(zde);     // ignore duplicates
        zde^.FileName := FSpecArgs.Strings[s];
        zde^.FileNameLength := Length(FSpecArgs.Strings[s]);
        zde^.Flag := (zde^.Flag and $1FFF) or $2000;    // (a new entry)
        zde^.ExtraData := '';      // Needed when deleting zde
      end;
    end;
    // Make a temporary filename like: C:\...\zipxxxx.zip for the new destination
    OutFilePath := MakeTempFileName('', '');
    if OutFilePath = '' then
      raise EZipMaster.CreateResDisp( DS_NoTempFile, True);

    // Create the output file.
    FOutFileHandle := FileCreate(OutFilePath);
    if FOutFileHandle = -1 then
      raise EZipMaster.CreateResDisp( DS_NoOutFile, True);

    // Open the second input archive, i.e. the original destination.
    In2FileHandle := FileOpen(DestZipMaster.ZipFileName,
      fmShareDenyWrite or fmOpenRead);
    if In2FileHAndle > -1 then
    begin                            
  //    if In2FileHAndle = -1 then
  //      raise EZipMaster.CreateResDisp( CF_DestFileNoOpen, True);

      // Get the date-time stamp and save for later.
      FDateStamp := FileGetDate(In2FileHandle);

      // Write the SFX header if present.
      if CopyBuffer(In2FileHandle, FOutFileHandle,
        DestZipMaster.SFXOffset) <> 0 then
        raise EZipMaster.CreateResDisp( CF_SFXCopyError, True);
    end;
    NotCopiedFiles := TStringList.Create();
    // Now walk trough the destination, copying and replacing
    DestMemCount := DestZipMaster.ZipContents.Count;

    MDZD := TZMDataList.Create(DestMemCount);

    // Copy the local data and save central header info for later use.
    for d := 0 to DestMemCount - 1 do
    begin
      zde := pZipDirEntry(DestZipMaster.ZipContents.Items[d]);
      if (zde^.Flag and $E000) = $6000 then
        // Ask first if we may overwrite.
      begin
        Overwrite := False;
        // Do we have a event assigned for this then don't ask.
        tmpCopyZipOverwrite := Events.OnCopyZipOverwrite;
        if Assigned(tmpCopyZipOverwrite) then
          tmpCopyZipOverwrite(DestZipMaster, zde^.FileName, Overwrite)
        else
        if ZipMessageDlgEx('', Format(ZipLoadStr(CF_OverwriteYN),
          [zde^.FileName, DestZipMaster.ZipFileName]),
          zmtConfirmation + DHC_CpyZipOvr, [mbYes, mbNo]) =
          idYes then
          Overwrite := True;
        zde^.Flag := zde^.Flag and $1FFF;
        // Clear the three upper bits.
        if Overwrite then
          zde^.Flag := zde^.Flag or $4000
        else
          zde^.Flag := zde^.Flag or $8000;
      end;
      // Change info for later while writing the central dir in new Dest.
      MDZDp := MDZD[d];
      MDZDp.RelOffLocal := FileSeek64(FOutFileHandle, Int64(0), 1);

      if (zde^.Flag and $6000) = $0000 then
        // Copy from original dest to new dest.
      begin
        // Set the file pointer to the start of the local header.
        FileSeek64(In2FileHandle, Int64(zde^.RelOffLocalHdr), 0);
        if CopyBuffer(In2FileHandle, FOutFileHandle,
          SizeOf(ZipLocalHeader) +
          zde^.FileNameLength + zde^.ExtraFieldLength +
          zde^.CompressedSize) <> 0 then
          raise EZipMaster.CreateResFile( CF_CopyFailed,
            DestZipMaster.ZipFileName, DestZipMaster.ZipFileName);
        if zde^.Flag and $8000 <> 0 then
        begin
          NotCopiedFiles.Add(zde^.FileName);
          // Delete also from FSpecArgs, should not be deleted from source later.
          FSpecArgs.Delete(FSpecArgs.IndexOf(zde^.FileName));
        end;
      end
      else
        for s := 0 to Count - 1 do
        begin
          pzd := pZipDirEntry(ZipContents.Items[s]);
          if AnsiStrIComp(Pchar(pzd^.FileName),
            Pchar(zde^.FileName)) = 0 then
          begin
            FileSeek64(FInFileHandle, Int64(pzd^.RelOffLocalHdr), 0);
            if CopyBuffer(FInFileHandle, FOutFileHandle,
              SizeOf(ZipLocalHeader) + pzd^.FileNameLength +
              pzd^.ExtraFieldLength + pzd^.CompressedSize) <> 0 then
              raise EZipMaster.CreateResFile( CF_CopyFailed,
                ZipFileName, DestZipMaster.ZipFileName);
            Break;
          end;
        end;
      // Save the file name info in the MDZD structure.
//      MDZDp^.FileNameLen := zde^.FileNameLength;
//      MDZDSetName(MDZDp, zde^.FileName);
      MDZDp.Filename := zde^.FileName;
//      StrPLCopy(MDZDp^.FileName, zde^.FileName, zde^.FileNameLength);
    end;
    // Now we have written al entries.

    // Now write the central directory with possibly changed offsets.
    // Remember the EOC we are going to use is from the wrong input file!
    EOC.CentralSize := 0;
    for d := 0 to DestMemCount - 1 do
    begin
      zde := pZipDirEntry(DestZipMaster.ZipContents.Items[d]);
      pzd := Nil;
      Found := False;
      // Rebuild the CEH structure.
      if (zde^.Flag and $6000) = $0000 then
        // Copy from original dest to new dest.
      begin
        pzd := pZipDirEntry(DestZipMaster.ZipContents.Items[d]);
        Found := True;
      end
      else                                  // Copy from source to new dest.
        for s := 0 to Count - 1 do
        begin
          pzd := pZipDirEntry(ZipContents.Items[s]);
          if AnsiStrIComp(Pchar(pzd^.FileName),
            Pchar(zde^.FileName)) = 0 then
          begin
            Found := True;
            Break;
          end;
        end;
      if not Found then
        raise EZipMaster.CreateResFile( CF_SourceNotFound,
          zde^.FileName, ZipFileName);
      CopyMemory(@CEH.VersionMadeBy0, pzd,
        SizeOf(ZipCentralHeader) - 4);
      CEH.HeaderSig := CentralFileHeaderSig;
      CEH.Flag := CEH.Flag and $1FFF;
      MDZDp := MDZD[d];
      CEH.RelOffLocal := MDZDp.RelOffLocal;
      // Save the first Central directory offset for use in EOC record.
      if d = 0 then
        EOC.CentralOffset := FileSeek64(FOutFileHandle, Int64(0), 1);
      EOC.CentralSize :=
        EOC.CentralSize + SizeOf(CEH) + CEH.FileNameLen +
        CEH.ExtraLen + CEH.FileComLen;

      // Write this changed central header to disk
      WriteJoin(CEH, SizeOf(CEH), DS_CEHBadWrite);
      //if filename was converted OEM2ISO then we have to reconvert before copying
      FVersionMadeBy1 := CEH.VersionMadeBy1;
      FVersionMadeBy0 := CEH.VersionMadeBy0;
//      MDZDSetName(MDZDp, SetSlash(ConvertOEM(MDZDGetName(MDZDp), cpdISO2OEM),
      MDZDp.FileName := SetSlash(ConvertOEM(MDZDp.FileName, cpdISO2OEM), psdInternal);
//      StrCopy(MDZDp^.FileName,
//        Pchar(SetSlash(ConvertOEM(MDZDp^.FileName, cpdISO2OEM),
//        psdInternal)));

      // Write to destination the central filename.
//      StrA := AnsiString(pzd^.FileName);
//      WriteJoin(PAnsiChar(StrA)^, CEH.FileNameLen, DS_CEHBadWrite);
      WriteJoin(PAnsiChar(MDZDp.FileNameA)^, CEH.FileNameLen, DS_CEHBadWrite);

      // And the extra field from zde or pzd.
      if CEH.ExtraLen <> 0 then
        WriteJoin(PAnsiChar(pzd^.ExtraData)^, CEH.ExtraLen,
          DS_CEExtraLen);

      // And the file comment.
      if CEH.FileComLen <> 0 then
      begin
        StrA := AnsiString(pzd^.FileComment);
        WriteJoin(PAnsiChar(StrA)^, CEH.FileComLen, DS_CECommentLen);
//        WriteJoin(Pchar(pzd^.FileComment)^, CEH.FileComLen,
//          DS_CECommentLen);
      end;
    end;
    EOC.CentralEntries := DestMemCount;
    EOC.TotalEntries := EOC.CentralEntries;               
    if In2FileHandle > -1 then
      EOC.ZipCommentLen := Length(DestZipMaster.ZipComment)
    else
      EOC.ZipCommentLen := 0;

    // Write the changed EndOfCentral directory record.
    WriteJoin(EOC, SizeOf(EOC), DS_EOCBadWrite);

    if In2FileHandle > -1 then
    begin
      // And finally the archive comment
      FileSeek64(In2FileHandle, Int64(DestZipMaster.ZipEOC +
        SizeOf(EOC)), 0);
      if CopyBuffer(In2FileHandle, FOutFileHandle,
        Length(DestZipMaster.ZipComment)) <> 0 then
        raise EZipMaster.CreateResDisp( DS_EOArchComLen, True);
    end;
    File_Close(FInFileHandle);
    // Now delete all copied files from the source when deletion is wanted.
    if DeleteFromSource and (FSpecArgs.Count > 0) then
    begin
      fZipBusy := False;
      Delete();
      // Delete files specified in FSpecArgs and update the contents.
    end;
    FSpecArgs.Assign(NotCopiedFiles);       // Info for the caller.
  except
    on ers: EZipMaster do
      // All CopyZippedFiles specific errors..
    begin
      ShowExceptionError(ers);
      Result := -7;
    end;
    on EOutOfMemory do
      // All memory allocation errors.
    begin
      ShowZipMessage(GE_NoMem, '');
      Result := -8;
    end;
    on E: Exception do
    begin
      ShowZipMessage(DS_ErrorUnknown, E.Message);
      Result := -9;
    end;
  end;

  if Assigned(MDZD) then
    FreeAndNil(MDZD);
  FreeAndNil(NotCopiedFiles);

  File_Close(FInFileHandle);
  File_Close(In2FileHandle);
  if FOutFileHandle <> -1 then
  begin
    if FDateStamp <> 0 then
      FileSetDate(FOutFileHandle, FDateStamp);
    File_Close(FOutFileHandle);
    if Result <> 0 then
      // An error somewhere, OutFile is not reliable.
      SysUtils.DeleteFile(OutFilePath)
    else
    begin
      EraseFile(DestZipMaster.FZipFileName,
        DestZipMaster.HowToDelete = htdFinal);
      if not RenameFile(OutFilePath, DestZipMaster.FZipFileName) then
        EraseFile(OutFilePath, DestZipMaster.HowToDelete = htdFinal);
    end;
  end;
  DestZipMaster.List;
  // Update the old(possibly some entries were added temporarily) or new destination.
  StopWaitCursor;
  fZipBusy := False;
end;

(*? TZMWorker.Create
1.76 27 April 2004 - clear Active and Delaying
1.75.0.2 3 March 2004 - new event
1.75 21 February 2004 new event
// 1.73 ( 5 June 2003) - updated constructor/destructor
*)
constructor TZMWorker.Create(AMaster: TCustomZipMaster);
begin
  inherited Create(AMaster);
  fIsDestructing := False;
  FActive := False;
  fZipContents := TList.Create;
  FFSpecArgs := TStringList.Create;
  FFSpecArgsExcl := TStringList.Create;
  FDirHashs := TZipDirHashList.Create;
  fHandle := Application.Handle;
  FDelaying := [];
  FZipBusy := False;
  FUnzBusy := False;
{$IFNDEF NO_SPAN}
  fConfirmErase := True;
{$ENDIF}
  FZipFileName := '';
  FPassword := '';
  FPasswordReqCount := 1;
  FEncrypt := False;
  FSuccessCnt := 0;
  FAddCompLevel := 9;     // dflt to tightest compression
  FUnattended := False;
  FRealFileSize := 0;
  FSFXOffset := 0;
  FZipSOC := 0;
  FFreeOnDisk1 := 0;      // Don't leave any freespace on disk 1.
  FFreeOnAllDisks := 0;       //  use all space
  FMaxVolumeSize := 0;        // Use the maximum disk size.
  FMinFreeVolSize := 65536;   // Reject disks with less free bytes than...
  FCodePage := cpAuto;
  FIsSpanned := False;
  FZipComment := '';
  FHowToDelete := htdAllowUndo;
  FAddStoreSuffixes := DefAddStoreSuffixes;
  FZipStream := TZipStream.Create;
  FUseDirOnlyEntries := False;
  FDirOnlyCount := 0;
  FSpanOptions := [];
{$IFNDEF NO_SPAN}
  fConfirmErase := True;
{$ENDIF}
  FSFX := Nil;
end;

(*? TZMWorker.CreateMVFileName
1.77 21 Aug 2004 RA allow more than 99 compat parts
*)
procedure TZMWorker.CreateMVFileNameEx(var FileName: String;
  StripPartNbr, Compat: Boolean);
var
  ext: String;
  StripLen: Integer;
begin         // changes filename into multi volume filename
  if Compat then
  begin
    if (FDiskNr <> FTotalDisks) then
    begin
      if FDiskNr < 9 then
        ext := '.z0'
      else
        ext := '.z';
      ext := ext + IntToStr(succ(FDiskNr));
    end
    else
      ext := '.zip';
    FileName := ChangeFileExt(FileName, ext);
  end
  else
  begin
    StripLen := 0;
    if StripPartNbr then
      StripLen := 3;
    FileName := Copy(FileName, 1, length(FileName) -
      Length(ExtractFileExt(FileName)) - StripLen) +
      Copy(IntToStr(1001 + FDiskNr), 2, 3) +
      ExtractFileExt(FileName);
  end;
end;

(*? TZMWorker.Delete
1.79 13 March 2009 RP clear FullErrCode
1.79 25 August 2006 RP do not delete orig file on failure
1.73 16 July 2003 RA catch and display dll load errors
1.73 13 July 2003 RA for spanned archive no exception but show mesage
*)
function TZMWorker.Delete: Integer;
var
  i: Integer;
  pFDS: pFileData;
  EOC:  ZipEndOfCentral;
  pExFiles: pExcludedFileSpec;
  TmpZipName: String;    
{$IFNDEF NO_SPAN}
  Res:  Integer;
{$ENDIF}
  ZipRecP: pZipParms;
begin
  FErrCode := 0;   
  fFullErrCode := 0;
  Result := 0;
  FSuccessCnt := 0;   
  ZipRecP := Nil;
  if fFSpecArgs.Count = 0 then
  begin
    ShowZipMessage(DL_NothingToDel, '');
    Result := FErrCode;
    Exit;
  end;
{$IFNDEF NO_SPAN}
  if FileExists(FZipFileName)
        and ((QueryZip(FZipFileName) and DetachMask) = 145) then
    FInFileName := ChangeFileExt(FZipFileName, '.zip')
  else
    FInFileName := FZipFileName;
  // Locate last of multi volume or last disk of spanned
  Res := GetLastVolume(FInFileName, EOC, False);
  if Res < 0 then
  begin
    Result := FErrCode;
    exit;
  end;
  if Res = 1 then
  begin
    ShowZipMessage(DS_Canceled, '');
    Result := FErrCode;
    exit;
  end;
{$ELSE}
  if not FileExists(FZipFileName) then
  begin
    ShowZipMessage(GE_NoZipSpecified, '');
    Result := FErrCode;
    Exit;
  end;
  // new 1.7 - stop delete from spanned
  OpenEOC(EOC, False);                      //1.72 true);
  //  File_Close(fInFileHandle);                 // only needed to test it
  if (IsSpanned) then
  begin
    ShowZipMessage(DL_NoDelOnSpan, '');
    Result := FErrCode;
    exit;
  end;
{$ENDIF}       
  File_Close(FInFileHandle); // was opened by OpenEOC/GetLastVolume   
  CheckDestWritable(FZipFileName, false);
//  if not CheckDestWritable(FZipFileName) then
//    raise EZipMaster.CreateResDrive( DS_NotChangeable, FZipFileName);

  { Make sure we can't get back in here while work is going on }
  if fZipBusy then
    Exit;

  try
    DoDllLoad;
  except
    on ews: EZipMaster do
    begin
      ShowExceptionError(ews);
      Result := FErrCode;
      exit;
    end;
  end;

  fZipBusy := True; { delete uses the ZIPDLL, so it shares the FZipBusy flag }
  Cancel := False;
//  File_Close(FInFileHandle); // was opened by OpenEOC
  if not FIsSpanned then
    TmpZipName := FZipFileName //not spanned create the outfile directly
  else
  if RejoinMVArchive(TmpZipName, True) <> 0 then
  begin
    FZipBusy := False;
    Cancel := False;
    DoDllUnload;
    Result := FErrCode;
    exit;
  end;

  try
    try
      ZipRecP := AllocMem(SizeOf(ZipParms));
      SetZipSwitches(TmpZipName, ZipRecP);
      SetDeleteSwitches(ZipRecP);

      with ZipRecP^ do
      begin
        fFDS := AllocMem(SizeOf(FileData) * FFSpecArgs.Count);
        for i := 0 to (fFSpecArgs.Count - 1) do
        begin
          pFDS := fFDS;
          Inc(pFDS, i);
          pFDS.fFileSpec := MakeStrP(fFSpecArgs[i]);
//          pFDS.fFileSpec := StrAlloc(Length(fFSpecArgs[i]) + 1);
//          StrPLCopy(pFDS.fFileSpec, fFSpecArgs[i], Length(fFSpecArgs[i]) + 1);
        end;
        fArgc := fSpecArgs.Count;
        fSeven := 7;
      end;                                  { end with }
      { pass in a ptr to parms }
      FEventErr := '';
      fSuccessCnt := DoZipExec(ZipRecP);
      if IsSpanned then
      begin
        if SuccessCnt > 0 then
          RecreateMVArchive(TmpZipName, True)
        else          
          SysUtils.DeleteFile(TmpZipName);
      end;
    except
      on ews: EZipMaster do
      begin
        if FEventErr <> '' then
          ews.Message := ews.Message + FEventErr;
        ShowExceptionError(ews);
      end
      else
        ShowZipMessage(GE_FatalZip, '');
    end;
  finally
    fFSpecArgs.Clear;
    fFSpecArgsExcl.Clear;

    with ZipRecP^ do
    begin
      StrDispose(pZipFN);
      StrDispose(pZipPassword);
      StrDispose(pSuffix);
      StrDispose(fTempPath);
      StrDispose(fArchComment);
      for i := (fArgc - 1) downto 0 do
      begin
        pFDS := fFDS;
        Inc(pFDS, i);
        StrDispose(pFDS.fFileSpec);
      end;
      FreeMem(fFDS);
      for i := (fTotExFileSpecs - 1) downto 0 do
      begin
        pExFiles := fExFiles;
        Inc(pExFiles, i);
        StrDispose(pExFiles.fFileSpec);
      end;
      FreeMem(fExFiles); 
      FreeMem(ZipRecP);
    end;
  end;

  DoDllUnload;
  fZipBusy := False;

  Cancel := False;
  if (fSuccessCnt > 0)
    and ((QueryZip(FZipFileName) and DetachMask) <> 145) then
    List; // not needed for exe with detached header
  Result := FErrCode;
  { Update the Zip Directory by calling List method }
end;

(*? TZMWorker.Destroy
1.77.4.0 23 Sep 2004 use FreeAndNil
1.73  1 June 2003 RP destructing flag to stop callbacks
*)
destructor TZMWorker.Destroy;
begin
  fIsDestructing := True;                   // stop callbacks
  AbortDll;
  FreeAndNil(FZipStream);
  FreeZipDirEntryRecords;
  FreeAndNil(FZipContents);
  FreeAndNil(FFSpecArgsExcl);
  FreeAndNil(FFSpecArgs);
  FreeAndNil(FDirHashs);
  inherited Destroy;
end;

(*? TZMWorker.DiskFreeAndSize
 { Replacement for the functions DiskFree and DiskSize. }
 { This should solve problems with drives > 2Gb and UNC filenames. }
 { Path FDrive ends with a backslash. }
 { Action=1 FreeOnDisk, 2=SizeOfDisk, 3=Both }
*)
procedure TZMWorker.DiskFreeAndSize(Action: Integer); // RCV150199
type
  TDiskSpace = function(RootName: Pchar;
      var FreeForCaller, TotNoOfBytes: LargeInt;
      TotNoOfFreeBytes: pLargeInt): BOOL; STDCALL;
var
  GetDiskFreeSpaceEx: TDiskSpace;
  SectorsPCluster, BytesPSector, FreeClusters, TotalClusters: DWORD;
  LDiskFree, LSizeOfDisk: LargeInt;
  Lib: THandle;
begin
  LDiskFree := -1;
  LSizeOfDisk := -1;
  Lib := GetModuleHandle('Kernel32');
  if Lib <> 0 then
  begin
    @GetDiskFreeSpaceEx := GetProcAddress(Lib, 'GetDiskFreeSpaceExA');
    if (@GetDiskFreeSpaceEx <> Nil) then
      // We probably have W95+OSR2 or better.
      if not GetDiskFreeSpaceEx(Pchar(FDrive), LDiskFree,
        LSizeOfDisk, Nil) then
      begin
        LDiskFree := -1;
        LSizeOfDisk := -1;
      end;
    FreeLibrary(Lib);                       //v1.52i
  end;
  if (LDiskFree = -1) then
    // We have W95 original or W95+OSR1 or an error.
    if GetDiskFreeSpace(Pchar(FDrive), SectorsPCluster, BytesPSector,
      FreeClusters, TotalClusters) then
    begin
      LDiskFree := LargeInt(BytesPSector) * SectorsPCluster *
        FreeClusters;
      LSizeOfDisk := LargeInt(BytesPSector) * SectorsPCluster *
        TotalClusters;
    end;
  if (Action and 1) <> 0 then
    FFreeOnDisk := LDiskFree;
  if (Action and 2) <> 0 then
    FSizeOfDisk := LSizeOfDisk;
end; 

(*? TZMWorker.DllCallback
1.77 15 July 2004 altered callbackStruct + message format
1.77 4 July 2004 changed callbackStruct + bytes written
1.76 25 April 2004 changes to GetXXXPassword
1.76 24 April 2004
*)
procedure TZMWorker.DllCallback(ZCallBackRec: PZCallBackStruct);
var
  OldFileName, pwd, FileComment: String;
  OrigName: String;
  IsChanged, DoExtract, DoOverwrite: Boolean;
  RptCount: Longword;
  Response: TPasswordButton;
  xlen:  Integer;
  ActionCode: ActionCodes;
  XIdent: integer;
  IsZip: boolean;
  ErrorCode: Integer;
  CMsg, M: String;
  FileSize: Int64;
  tmpSetNewName: TSetNewNameEvent;
  tmpSetAddName: TSetAddNameEvent;
  tmpPasswordError: TPasswordErrorEvent;
  tmpCRC32Error: TCRC32ErrorEvent;
  tmpExtractOverwrite: TExtractOverwriteEvent;
  tmpExtractSkipped: TExtractSkippedEvent;
  tmpMessage: TMessageEvent;
  tmpFileComment: TFileCommentEvent;
  tmpFileExtra: TFileExtraEvent;
  tmpSetExtName: TSetExtNameEvent;
  tp: pAnsiChar;
  ti: integer;
  tmp: AnsiString;

  function IsPathOnly(const f: String): Boolean;
  var
    c: Char;
  begin
    Result := False;
    if f <> '' then
    begin
      c := f[length(f)];
      if (c = '\') or (c = '/') then
        Result := True;
    end;
  end;

  function Msg: String;
  begin
    Result := CMsg;
    if Result = '' then
    begin
      CMsg := string(ZCallBackRec^.MsgP);
      CMsg := SetSlash(CMsg, psdExternal);
      Result := CMsg;
    end;
  end;

begin
  if fIsDestructing then                    // in destructor return
    exit;
  CMsg := '';
  XIdent := ZCallBackRec^.ActionCode;
  ActionCode := ActionCodes(XIdent and 63);
  if ActionCode = zacKey then
  begin
    fDllOperKey := ZCallBackRec^.Arg1;
    exit;
  end;
  try
    IsZip := ZCallBackRec^.IsOperationZip;
    if (ActionCode <= zacSize) or (ActionCode = zacXItem) or
      (ActionCode = zacXProgress) then
    begin
      ErrorCode := 0;
      FileSize := 0;
      m := '';
      case ActionCode of
        zacItem..zacEndOfBatch:
          begin
            FileSize := ZCallBackRec^.FileSize;
            if ActionCode = zacItem then
              m := Msg;
            if IsZip then
              TProgDetails(FProgDetails).Written(ZCallBackRec^.Written);
          end;
        zacMessage:
          begin
            m := msg;
            ErrorCode := ZCallBackRec^.Arg1;
          end;
        zacSize:
          FileSize := ZCallBackRec^.FileSize;
        zacCount:
          FileSize := ZCallBackRec^.Arg1;
        zacXItem:
          begin
            FileSize := ZCallBackRec^.FileSize;
            m := msg;
            ErrorCode := ZCallBackRec^.Arg1;
          end;
        zacXProgress:
          begin
            FileSize := ZCallBackRec^.FileSize;
            ErrorCode := ZCallBackRec^.Arg1;
          end;
      end;
      Report(ActionCode, ErrorCode, m, FileSize);
    end
    else
    begin
      case ActionCode of
        zacNewName:
          { request for a new path+name just before zipping or extracting }
        begin
          tmpSetNewName := Events.OnSetNewName;
          tmpSetAddName := Events.OnSetAddName;
          if Assigned(tmpSetAddName) or Assigned(tmpSetNewName) then
          begin
            m := Msg;     // saves OldFileName
            tp := ZCallBackRec^.Msg2P;
            if Assigned(tmpSetNewName) then
            begin
              OldFileName := m;
              IsChanged := False;

              tmpSetNewName(Master, OldFileName, IsChanged);
              if IsChanged then
              begin
                StrPLCopy(ZCallBackRec^.Msg, AnsiString(OldFileName), 512);
                ZCallBackRec^.ActionCode := -1;
              end;
            end;
            if tp <> nil then
            begin
              if Assigned(tmpSetAddName) then
              begin
                OrigName := SetSlash(string(tp), psdExternal);
                OldFileName := m;
                IsChanged := False;

                tmpSetAddName(Master, OldFileName, OrigName, IsChanged);
                if IsChanged then
                begin
                  StrPLCopy(ZCallBackRec^.Msg, AnsiString(OldFileName), 512);
                  ZCallBackRec^.ActionCode := -1;
                end;
              end;
            end;
          end;
        end;

        zacPassword:
          { New or other password needed during Extract() }
        begin
          pwd := '';
          RptCount := ZCallBackRec^.Arg1;
          Response := mbOK;

          tmpPasswordError := Events.OnPasswordError;
          if Assigned(tmpPasswordError) then
          begin
            tmpPasswordError(Master, IsZip, pwd, Msg, RptCount, Response);
            if Response <> mbOK then
              pwd := '';
          end
          else
          if IsZip then
            pwd := GetAddPassword(Response)
          else
            pwd := GetExtrPassword(Response);

          if pwd <> '' then
          begin
            StrPLCopy(ZCallBackRec^.Msg, AnsiString(pwd), PWLEN);
            ZCallBackRec^.ActionCode := -1;
          end
          else
          begin      // no password
            RptCount := 0;
            ZCallBackRec^.ActionCode := -2;
          end;
          if RptCount > 15 then
            RptCount := 15;
          ZCallBackRec^.Arg1 := RptCount;
          if Response = mbCancel then // Cancel
            ZCallBackRec^.ActionCode := -2
          else
          if Response = mbNoToAll then // Cancel all
            ZCallBackRec^.ActionCode := -3
          else
          if Response = mbAbort then     // Abort
            Cancel := True;
        end;

        zacCRCError:
          { CRC32 error, (default action is extract/test the file) }
        begin
          DoExtract := True;
          tmpCRC32Error := Events.OnCRC32Error;
          if Assigned(tmpCRC32Error) then
          begin
            tmpCRC32Error(Master, Msg, ZCallBackRec^.Arg1, ZCallBackRec^.Arg2, DoExtract);
            if DoExtract then
              ZCallBackRec^.ActionCode := -1   // no delete
            else
              ZCallBackRec^.ActionCode := -3;
          end;
        end;

        zacOverwrite:
          { Extract(UnZip) Overwrite ask }
          begin
            tmpExtractOverwrite := Events.OnExtractOverwrite;
            if Assigned(tmpExtractOverwrite) then
            begin
              DoOverwrite := ZCallBackRec^.Arg1 <> 0;
              tmpExtractOverwrite(Master, Msg, ZCallBackRec^.Arg3 <> 2,
                      DoOverwrite, ZCallBackRec^.Arg2);
              if DoOverwrite then
                ZCallBackRec^.ActionCode := -1
              else
                ZCallBackRec^.ActionCode := -2;
            end;
          end;

        zacSkipped:
          { Extract(UnZip) and Skipped }
        begin
          ErrorCode := ZCallBackRec^.Arg1;  // error
          ti := ZCallBackRec^.Arg2;   // type
          if ErrorCode <> 0 then
          begin
            FFullErrCode := ErrorCode;
            ErrCode := Integer(ErrorCode and $FF);
          end;
          tmpExtractSkipped := Events.OnExtractSkipped;
          if Assigned(tmpExtractSkipped) then
            tmpExtractSkipped(Master, Msg, UnZipSkipTypes(pred(ti and 255)), ErrorCode)
          else
          begin
            tmpMessage := Events.OnMessage;
            if Assigned(tmpMessage) then
              tmpMessage(Master, GE_Unknown,
                ZipFmtLoadStr(GE_Skipped, [Msg, (ti and $FF) - 1]));
          end;
        end;

        zacComment:
          { Add(Zip) FileComments. }
          begin
            tmpFileComment := Events.OnFileComment;
            if Assigned(tmpFileComment) then
            begin
              FileComment := String(ZCallBackRec^.Msg2P);
              IsChanged := False;
              tmpFileComment(Master, Msg, FileComment, IsChanged);
              if IsChanged then
              begin
                tmp := AnsiString(FileComment);
                ti := Length(tmp);
                if ti > 511 then
                   ti := 511;
                if (FileComment <> '') then
                  StrPLCopy(ZCallBackRec^.Msg, tmp, ti)
//                  StrPLCopy(ZCallBackRec^.Msg, AnsiString(FileComment), 511)
                else
                  ZCallBackRec^.Msg[0] := #0;
//              if IsChanged then
//              begin
                ZCallBackRec^.ActionCode := -1;
//                ti := Length(FileComment);
//                if ti > 511 then
//                   ti := 511;
                ZCallBackRec^.Arg1 := ti;
              end;
            end;
          end;

        zacStream:
          { Stream2Stream extract.  }
        begin
          try
            FZipStream.SetSize(ZCallBackRec^.FileSize);
            ZCallBackRec^.Msg2P := FZipStream.Memory;
            ZCallBackRec^.ActionCode := -1;  // ok
          except
            ZCallBackRec^.ActionCode := -2;
            ZCallBackRec^.FileSize := 0;
          end;
        end;

        zacData:                            { Set Extra Data }
          begin
            tmpFileExtra := Events.OnFileExtra;
            if Assigned(tmpFileExtra) then
            begin
              FileSize := ZCallBackRec^.Arg1;         // old size
              SetLength(FStoredExtraData, FileSize);
              if FileSize > 0 then
                move(ZCallBackRec^.Msg2P, PAnsiChar(FStoredExtraData)^, FileSize);
              IsChanged := False;
              tmpFileExtra(Master, Msg, FStoredExtraData, IsChanged);
              if IsChanged then
              begin
                xlen := Length(FStoredExtraData);
                if (xlen > 0) then
                   if (xlen < 512) then
                     move(PAnsiChar(FStoredExtraData)^, ZCallBackRec^.Msg, xlen)
                  else
                    ZCallBackRec^.Msg2P := PAnsiChar(FStoredExtraData);
                ZCallBackRec^.Arg1 := xlen;
              ZCallBackRec^.ActionCode := -1;
              end;
            end;
          end;

        zacExtName:
          { request for a new path+name just before zipping or extracting }
          begin
            tmpSetExtName := Events.OnSetExtName;
            if Assigned(tmpSetExtName) then
            begin
              OldFileName := Msg;
              IsChanged := False;
              tmpSetExtName(Master, OldFileName, IsChanged);
              if IsChanged and (OldFileName <> Msg) and
                (IsPathOnly(OldFileName) = IsPathOnly(Msg)) then
              begin
                StrPLCopy(ZCallBackRec^.Msg, AnsiString(OldFileName), 512);
                ZCallBackRec^.ActionCode := -1;
              end;
            end;
          end;
      end;                                  {end case }
      Report(zacNone, 0, '', 0);            // process messages
    end;
  except
    on E: Exception do
    begin
      if fEventErr = '' then
        // catch first exception only
        fEventErr := ' #' + IntToStr(Ord(ActionCode)) +
          ' "' + E.Message + '"';
      Cancel := True;
    end;
  end;
end;


(*? TZMWorker.Done
*)
procedure TZMWorker.Done;
begin
  inherited;
end;  

(*? TZMWorker.ExtAdd        
1.79 13 March 2009 RP clear FullErrCode
1.79 7 Feb 2007 RP allow unattended encrypt if event handled
1.79 23 July 2005 RA avoid AV when filename did not exsists NO_SPAN
1.79 6 Dec 2004 RA allow freshen/update MV SFX
1.79 5 Dec 2004 RA - Load dll before joining mult-parts, stream to MV file
1.79 3 Dec 2004 RA allow Freshen/update in spanned archive
1.78 4 Oct 2004 RA no_sfx error message
1.76 26 May 2004 RP use shielded FSpecArgs
1.76 13 May 2004 RP change RootDir support and allow Freshen/Update with no args
1.76 24 April 2004 RP change checking no files
1.76 17 April 2004 RP change exception reporting
1.75 16 March 2004 RA only forceDir on hard drive
1.73.2.6 7 September 2003 RP allow Freshen/Update with no args
1.73  4 August 2003 RA fix removal of '< '
1.73 17 July 2003 RP reject '< ' as password ' '
1.73 16 July 2003 RA load Dll in try except
1.73 16 July 2003 RP trim filenames
1.73 15 July 2003 RA remove '<' from filename
1.73 12 July 2003 RP release held File Data  + test destination drive
1.73 27 June 2003 RP changed slplit file support
// UseStream = 0 ==> Add file to zip archive file.
// UseStream = 1 ==> Add stream to zip archive file.
// UseStream = 2 ==> Add stream to another (zipped) stream.
*)
procedure TZMWorker.ExtAdd(UseStream: Integer;
  StrFileDate, StrFileAttr: DWORD;
  MemStream: TMemoryStream);
const
  ZB_EXE_STUB = zqbStartEXE or zqbGoodComment or zqbHasEOC;  // Empty sfx stub
var
  i: Integer;
  SFXResult: Integer;
  Tmp, TmpZipName: String;
  pFDta: pFileData;
  pExFiles: pExcludedFileSpec;
  len, b, p{, RootLen}: Integer;
  FDSSpec: String;
  rdir: String;
  ZipRecP: pZipParms;
begin
  { Make sure we can't get back in here while work is going on }
  if fZipBusy then
    Exit;
  FSuccessCnt := 0;  
  FErrCode := 0;
  fFullErrCode := 0;
  FMessage := '';   
  ZipRecP := Nil;
  try
    if (UseStream = 0) and (fFSpecArgs.Count = 0) then
    begin
      if not ((AddFreshen in FAddOptions) or (AddUpdate in FAddOptions)) then
        raise EZipMaster.CreateResDisp( AD_NothingToZip, True);
      FAddOptions := (FAddOptions - [AddUpdate]) + [AddFreshen];
      FFSpecArgs.Add('*.*');                 // do freshen all
    end;

    if (AddDiskSpanErase in FAddOptions) then
    begin
      FAddOptions := FAddOptions + [AddDiskSpan]; // make certain set
      FSpanOptions := FSpanOptions + [spWipeFiles];
    end;

{$IFDEF NO_SPAN}
    if (AddDiskSpan in FAddOptions) then
      raise EZipMaster.CreateResDisp( DS_NoDiskSpan, True);
{$ENDIF}
    // We can not do an Unattended Add if we don't have a password.
//    if FUnattended and (AddEncrypt in FAddOptions) and (FPassword = '') then
    if FUnattended and (AddEncrypt in FAddOptions) and (FPassword = '')
      and (not assigned(Events.OnPasswordError)) then
      raise EZipMaster.CreateResDisp( AD_UnattPassword, True);
    // make certain destination can exist
    if (UseStream < 2) then
    begin
      { We must allow a zipfile to be specified that doesn't already exist,
        so don't check here for existance. }
      if FZipFileName = '' then    // make sure we have a zip filename
        raise EZipMaster.CreateResDisp( GE_NoZipSpecified, True);
      FDrive := ExtractFileDrive(ExpandUNCFileName(FZipFileName)) + '\';
      GetDriveProps;
//      FDriveFixed := IsFixedDrive(FDrive);
      // drive must exist and be changeable
      if FUnattended and not FDriveFixed and (AddDiskSpan in FAddOptions)then
        raise EZipMaster.CreateResDisp( DS_NoUnattSpan, True);
      if (FDriveFixed or not (AddDiskSpan in FAddOptions)) then
      begin
        if AddForceDest in FAddOptions then
          ForceDirectory(ExtractFilePath(FZipFileName));
        if not DirExists(ExtractFilePath(FZipFileName)) then
          raise EZipMaster.CreateResFmt(
            AD_NoDestDir, [ExtractFilePath(FZipFileName)]);
      end;
          
  // do not test if dest is removeable and AddDiskSpan - drive may be empty
  if (FDriveFixed or not (AddDiskSpan in FAddOptions)) then
    CheckDestWritable(FZipFileName, false);
//  if (FDriveFixed or not (AddDiskSpan in FAddOptions))
//      and not CheckDestWritable(FZipFileName) then
//        raise EZipMaster.CreateResDrive( DS_NotChangeable, FZipFileName);
    end;
    if DoDllLoad{(false)} <= 0 then
      exit;  // could not load valid dll
    // If we are using disk spanning, first create a temporary file
    if (UseStream < 2) and (AddDiskSpan in FAddOptions) then
    begin
      if RejoinMVArchive(TmpZipName, (AddFreshen in FAddOptions) or
        (AddUpdate in FAddOptions) or
        (UseStream = 1)) <> 0 then
        exit;          // probably should give reason
    end
    else
      TmpZipName := FZipFileName;
    if (UseStream < 2)
      and not (AddDiskSpan in FAddOptions)
      and (Uppercase(ExtractFileExt(FZipFileName)) = '.EXE')
      and not FileExists(FZipFileName) then
    begin
        { This is the first "add" operation following creation of a new
          .EXE archive.  We need to add the SFX code now, before we add
          the files. }
      SFXResult := NewSFXFile(FZipFileName);
      if SFXResult <> 0 then
        raise EZipMaster.CreateResDisk( AD_AutoSFXWrong, SFXResult);
    end;
  except
    on ews: EZipMaster do
    begin
      ShowExceptionError(ews);
      Exit;
    end;
    else
      exit;
  end;
  fZipBusy := True;
  Cancel := False;

  StartWaitCursor;
  try
    try
      ZipRecP := AllocMem(SizeOf(ZipParms));
      SetZipSwitches(TmpZipName, ZipRecP);

      with ZipRecP^ do
      begin
        if UseStream = 1 then
        begin
          fUseInStream := True;
          fInStream := FZipStream.Memory;
          fInStreamSize := FZipStream.Size;
          fStrFileAttr := StrFileAttr;
          fStrFileDate := StrFileDate;
        end;
        if UseStream = 2 then
        begin
          fUseOutStream := True;
          fOutStream := FZipStream.Memory;
          fOutStreamSize := MemStream.Size + 6;
          fUseInStream := True;
          fInStream := MemStream.Memory;
          fInStreamSize := MemStream.Size;
        end;
        // 1.76 set global RootDir
        if FRootDir <> '' then
        begin
          rdir := ExpandFileName(fRootDir); // allow relative root
//          RootLen := Length(rdir);
          fGRootDir := MakeStrP(rdir);
//          fGRootDir := StrAlloc(RootLen + 1);
//          StrPLCopy(fGRootDir, rdir, RootLen + 1);
        end;
        fargc := fSpecArgs.Count;
        fFDS := AllocMem(SizeOf(FileData) * FFSpecArgs.Count);
        for i := 0 to pred(FFSpecArgs.Count) do
        begin
          pFDta := ZipRecP^.fFDs;
          Inc(pFDta, i);
          FDSSpec := FFSpecArgs.Strings[i];
          len := Length(FDSSpec);
          p := 1;
          // Added to version 1.60L to support recursion and encryption on a FFileSpec basis.
          // Regardless of what AddRecurseDirs is set to, a '>' will force recursion, and a '|' will stop recursion.
          pFDta.fRecurse := Word(fRecurse);  // Set default
          if Copy(FDSSpec, 1, 1) = '>' then
          begin
            pFDta.fRecurse := $FFFF;
            Inc(p);
          end;
          if Copy(FDSSpec, 1, 1) = '|' then
          begin
            pFDta.fRecurse := 0;
            Inc(p);
          end;
          // Also it is possible to specify a password after the FFileSpec, separated by a '<'
          // If there is no other text after the '<' then, an existing password, is temporarily canceled.
          pFDta.fEncrypt := Longword(fEncrypt); // Set default
          if Length(pZipPassword) > 0 then  // v1.60L
          begin
            pFDta.fPassword := MakeStrP(string(pZipPassword));
//            pFDta.fPassword := StrAlloc(Length(pZipPassword) + 1);
//            StrLCopy(pFDta.fPassword, pZipPassword, Length(pZipPassword));
          end;
          b := AnsiPos('<', FDSSpec);
          if b <> 0 then
          begin                             // Found...
            pFDta.fEncrypt := $FFFF;         // the new default, but...
            StrDispose(pFDta.fPassword);
            pFDta.fPassword := Nil;
            tmp := Copy(FDSSpec, b + 1, 1);
            if (tmp = '') or (tmp = ' ') then
            begin
              pFDta.fEncrypt := 0;
              // No password, so cancel for this FFspecArg
              Dec(len, Length(tmp) + 1);
            end
            else
            begin
              pFDta.fPassword := MakeStrP(Copy(FDSSpec, b + 1, len - b));
//              pFDta.fPassword := StrAlloc(len - b + 1);
//              StrPLCopy(pFDta.fPassword, Copy(FDSSpec, b + 1, len - b),
//                len - b + 1);
              len := b - 1;
            end;
          end;

          // 1.76 only set if different to global
          pFDta.fRootDir := Nil;
          tmp := Trim(Copy(FDSSpec, p, len - p + 1));
          if tmp <> '' then
          begin
            pFDta.fFileSpec := MakeStrP(tmp);
//            pFDta.fFileSpec := StrAlloc(Length(tmp) + 1);
//            StrPLCopy(pFDta.fFileSpec, tmp, Length(tmp) + 1);
          end
          else
            pFDta.fFileSpec := Nil;
        end;
        ZipRecP^.fSeven := 7;
      end;                                  { end with }

      FEventErr := '';                      // added
      { pass in a ptr to parms }
      fSuccessCnt := DoZipExec(ZipRecP);
      if (UseStream < 2) and (AddDiskSpan in FAddOptions) then
      begin
        if fSuccessCnt > 0 then
          RecreateMVArchive(TmpZipName, (AddFreshen in FAddOptions) or
            (AddUpdate in FAddoptions) or (UseStream = 1))
        else
          SysUtils.DeleteFile(TmpZipName);
      end;
      if (UseStream = 2) and (FSuccessCnt = 1) then
        FZipStream.SetSize(ZipRecP.fOutStreamSize);
    except
      on ews: EZipMaster do
      begin
        if FEventErr <> '' then
          ews.Message := ews.Message + FEventErr;
        ShowExceptionError(ews);
      end
      else
        ShowZipMessage(GE_FatalZip, '');
    end;
  finally
    fFSpecArgs.Clear;
    fFSpecArgsExcl.Clear;
    with ZipRecP^ do
    begin
      { Free the memory for the zipfilename and parameters }
      { we know we had a filename, so we'll dispose it's space }
      StrDispose(pZipFN);
      StrDispose(pZipPassword);
      StrDispose(pSuffix);
      pZipPassword := Nil;

      StrDispose(fTempPath);
      StrDispose(fArchComment);
      StrDispose(fGRootDir);
      for i := (fArgc - 1) downto 0 do
      begin
        pFDta := fFDS;
        Inc(pFDta, i);
        StrDispose(pFDta.fFileSpec);
        StrDispose(pFDta.fPassword);
        StrDispose(pFDta.fRootDir);
      end;
      FreeMem(fFDS);
      for i := (fTotExFileSpecs - 1) downto 0 do
      begin
        pExFiles := fExFiles;
        Inc(pExFiles, i);
        StrDispose(pExFiles.fFileSpec);
      end;
      FreeMem(fExFiles); 
      FreeMem(ZipRecP);  
      StopWaitCursor;
    end;
  end;                                      {end try finally }

  DoDllUnload;
  FStoredExtraData := '';                   // release held data
  Cancel := False;
  fZipBusy := False;
  if (fSuccessCnt > 0)
    and ((QueryZip(FZipFileName) and DetachMask) <> 145) then
    List;
  // Update the Zip Directory by calling List method
  // not needed for spanned exe
end;

(*? TZMWorker.ExtExtract                
1.79 13 March 2009 RP clear FullErrCode
1.79 26 July 2005 RA changed error handling
1.79 16 July 2005 RA - test ExtrBaseDir writeable
1.76 19 May 2004 show exception information
1.76  5 May 2004 fix 'No Input File' on multipart extract
1.76 28 April 2004 do not check destination when testing (ExtrTest is active)
1.73.2.6 17 September 2003 RA stop duplicate 'cannot open file' messages
1.73 22 July 2003 RA exception handling for EZipMaster + fUnzBusy := False when dll load error
1.73 16 July 2003 RA catch and display dll load errors
1.73 12 July 2003 RP allow ForceDirectories
// UseStream = 0 ==> Extract file from zip archive file.
// UseStream = 1 ==> Extract stream from zip archive file.
// UseStream = 2 ==> Extract (zipped) stream from another stream.
*)
procedure TZMWorker.ExtExtract(UseStream: Integer; MemStream: TMemoryStream);
var
  i, DLLVers: Integer;
  OldPRC: Integer;
  TmpZipName, TmpBaseDir, TmpS: String;
  pUFDS:  pUnzFileData;    
  UnzRecP: pUnZipParms;
  tEntry : PZipDirEntry;
begin
  FSuccessCnt := 0;
  FErrCode := 0;     
  fFullErrCode := 0;
  FMessage := '';
  OldPRC := FPasswordReqCount;
  DLLVers := 0;
  TmpZipName := '';
  UnzRecP := nil;

  { Make sure we can't get back in here while work is going on }
  if fUnzBusy then
    Exit;
  FUnzBusy := True;
  Cancel := False;
  try
    if (UseStream < 2) then
    begin
      if (FZipFileName = '') then
        raise EZipMaster.CreateResDisp( GE_NoZipSpecified, True);
      if Count = 0 then
        List;                                 // try again
      if Count = 0 then
      begin                
        fUnzBusy := false;                    // stop from doing anything
        if FErrCode = 0 then                  // only show once
          raise EZipMaster.CreateResDisp( DS_FileOpen, True);
      end;    
      Cancel := False;          // might have been set in List
      if FUnzBusy then
      begin                         
{$IFDEF NO_SPAN}
        if FTotalDisks > 0 then
          raise EZipMaster.CreateResDisp( DS_NODISKSPAN, True);
{$ENDIF}
        TmpBaseDir := '';
        // expand and check ExtrBaseDir
        if (UseStream = 0) and (FExtrBaseDir <> '') and not
          (ExtrTest in FExtrOptions) then
        begin
          TmpBaseDir := ExpandUNCFileName(DelimitPath(FExtrBaseDir, True));
          if ExtrForceDirs in FExtrOptions then
            ForceDirectory(TmpBaseDir);
          if not DirExists(TmpBaseDir) then
            raise EZipMaster.CreateResDrive( EX_NoExtrDir, TmpBaseDir);
//          SetLength(TmpS, MAX_PATH + 2);
//          SetLastError(0);
//          if GetTempFileName(Pchar(TmpBaseDir), 'tmp', 0, Pchar(TmpS)) = 0 then
//            raise EZipMaster.CreateResMsgOS(DS_NotChangeable, TmpBaseDir, GetLastError);
////            raise EZipMaster.CreateResDrive( DS_NotChangeable, TmpBaseDir);
//          DeleteFile(Pchar(TmpS));  // use windows function with pchar
//          TmpS := '';
        end;

        TmpZipName := FZipFileName;

        // We do a check if we need UnSpanning first, this depends on
        // The number of the disk the EOC record was found on. ( provided by List() )
        // If we have a spanned set consisting of only one disk we don't use ReadSpan().
{$IFNDEF NO_SPAN}
        if FTotalDisks > 0 then
        begin
          if FTempDir = '' then
          begin                     
            SetLength(TmpS, MAX_PATH + 2);
            GetTempPath(MAX_PATH, pChar(TmpS));
            TmpZipName := pChar(TmpS);  // convert from NULL terminated
            TmpS := '';
          end;
          TmpZipName := DelimitPath(FTempDir, True);

          FUnzBusy := ReadSpan(FZipFileName, TmpZipName, True) = 0;
          // if we returned without an error, TmpZipName contains a real name.
        end;
{$ENDIF}
      end;   // if FUnzBusy then
    end;     // if (UseStream < 2) then
                                 
    if FUnzBusy then
      DllVers := DoDllLoad;
    if DLLVers > 0 then
      try
        UnzRecP := AllocMem(SizeOf(UnZipParms2));
        SetUnZipSwitches(TmpZipName, UnzRecP);

        with UnzRecP^ do
        begin
          if TmpBaseDir <> '' then
          begin
            fExtractDir := MakeStrP(TmpBaseDir);
//            fExtractDir := StrAlloc(Length(TmpBaseDir) + 1);
//            StrPLCopy(fExtractDir, TmpBaseDir, Length(TmpBaseDir));
          end
          else
            fExtractDir := Nil;

          fUFDS := AllocMem(SizeOf(UnzFileData) * FFSpecArgs.Count);
          // 1.70 added test - speeds up extract all
          if (fFSpecArgs.Count <> 0) and (fFSpecArgs[0] <> '*.*') then
          begin
            for i := 0 to (fFSpecArgs.Count - 1) do
            begin
              pUFDS := fUFDS;
              Inc(pUFDS, i);
              pUFDS.fFileSpec := MakeStrP(fFspecArgs[i]);
//              pUFDS.fFileSpec := StrAlloc(Length(fFSpecArgs[i]) + 1);
//              StrPLCopy(pUFDS.fFileSpec, fFSpecArgs[i],
//                Length(fFSpecArgs[i]) + 1);
            end;
            fArgc := FFSpecArgs.Count;
          end
          else
            fArgc := 0;
          if UseStream = 1 then
          begin
            tEntry := FDirHashs.Find(FFSpecArgs.Strings[0]);
            if Assigned(tEntry) then
              with tEntry^ do
              begin
                FZipStream.SetSize(UncompressedSize);
                fUseOutStream := True;
                fOutStream := FZipStream.Memory;
                fOutStreamSize := UncompressedSize;
                fArgc := 1;
              end;
          end;
          if UseStream = 2 then
          begin
            fUseInStream := True;
            fInStream := MemStream.Memory;
            fInStreamSize := MemStream.Size;
            fUseOutStream := True;
            fOutStream := FZipStream.Memory;
            fOutStreamSize := FZipStream.Size;
          end;
          fSeven := 7;
        end;
        FEventErr := '';                      // added
        // We have to be carefull doing an unattended Extract when a password is needed
        // for some file in the archive.
        if (UseStream < 2) and FUnattended and (FPassword = '') and not
          Assigned(Events.OnPasswordError) then
        begin
          FPasswordReqCount := 0;
          Report(zacMessage, 0, ZipLoadStr(EX_UnAttPassword),0);
        end;
        if (UseStream = 0) or ((UseStream > 0) and
          UnzRecP.fUseOutStream) then
        fSuccessCnt := DoUnzExec(UnzRecP);
      finally
        DoDllUnload;
        fUnzBusy := False;
        fFSpecArgs.Clear;
        { Remove from memory if stream is not Ok. }
        if (UseStream > 0) and (FSuccessCnt <> 1) then
          FZipStream.Clear();
        { If UnSpanned we still have this temporary file hanging around. }
        if FTotalDisks > 0 then
          SysUtils.DeleteFile(TmpZipName);
        with UnzRecP^ do
        begin
          StrDispose(pZipFN);
          StrDispose(pZipPassword);
          if (fExtractDir <> Nil) then
            StrDispose(fExtractDir);

          for i := (fArgc - 1) downto 0 do
          begin
            pUFDS := fUFDS;
            Inc(pUFDS, i);
            StrDispose(pUFDS.fFileSpec);
          end;
          FreeMem(fUFDS);
        end;
        FreeMem(UnzRecP);

        if (UseStream < 2) and FUnattended and (FPassword = '') and not
          Assigned(Events.OnPasswordError) then
          FPasswordReqCount := OldPRC;
      end;
  except
    on ews: EZipMaster do
    begin       
      fUnzBusy := False;
      if FEventErr <> '' then
        ews.Message := ews.Message + FEventErr;
      ShowExceptionError(ews);
      FSuccessCnt := 0;
    end;
  end; 
  { no need to call the List method; contents unchanged }
end;

function TZMWorker.Extract: Integer;
begin
  ExtExtract(0, Nil);
  Result := fErrCode;
end;

(*? TZMWorker.ExtractFileToStream
1.73 15 July 2003 RA add check on filename in FSpecArgs + return on busy
*)
function TZMWorker.ExtractFileToStream(FileName: String): TZipStream;
begin
  FSuccessCnt := 0;
  if FileName <> '' then
  begin
    FFSpecArgs.Clear();
    FFSpecArgs.Add(FileName);
  end;
  if (FFSpecArgs.Count <> 0) then
  begin
    FZipStream.Clear();
    ExtExtract(1, Nil);
    if FSuccessCnt <> 1 then
      Result := Nil
    else
      Result := FZipStream;
  end
  else
  begin
    ShowZipMessage(AD_NothingToZip, '');
    Result := Nil;
  end;
end;

(*? TZMWorker.ExtractStreamToStream
1.73 14 July 2003 RA initial FSuccessCnt
*)
function TZMWorker.ExtractStreamToStream(InStream: TMemoryStream;
  OutSize: Longword): TZipStream;
begin
  FSuccessCnt := 0;
  if InStream = FZipStream then
  begin
    ShowZipMessage(AD_InIsOutStream, '');
    Result := Nil;
    Exit;
  end;
  FZipStream.Clear();
  FZipStream.SetSize(OutSize);
  ExtExtract(2, InStream);
  if FSuccessCnt <> 1 then
    Result := Nil
  else
    Result := FZipStream;
end;

(*? TZMWorker.FreeZipDirEntryRecords
1.73 12 July 2003 RP string ExtraData
{ Empty fZipContents and free the storage used for dir entries }
*)
procedure TZMWorker.FreeZipDirEntryRecords;
var
  i: Integer;
begin
  if ZipContents.Count = 0 then
    Exit;
  for i := (ZipContents.Count - 1) downto 0 do
  begin
    if Assigned(ZipContents[i]) then
    begin
      pZipDirEntry(ZipContents[i]).ExtraData := '';
      // dispose of the memory pointed-to by this entry
      Dispose(pZipDirEntry(ZipContents[i]));
    end;
    ZipContents.Delete(i);
    // delete the TList pointer itself
  end;     { end for }
  FDirHashs.Clear;
  // The caller will free the FZipContents TList itself, if needed
end;

(*? TZMWorker.GetAddPassword
1.76 25 May 2004 changed
1.76 10 May 2004 change loading strings
*)
function TZMWorker.GetAddPassword(
  var Response: TPasswordButton): String;
var
  p1, p2: String;
begin
  p2 := '';
  if Unattended then
    ShowZipMessage(PW_UnatAddPWMiss, '')
  else
  begin
    Response := GetPassword(ZipLoadStr(PW_Caption),
      ZipLoadStr(PW_MessageEnter), DHC_AddPwrd1, mbOkCancel, p1);
    if (Response = mbOK) and (p1 <> '') then
    begin
      Response := GetPassword(ZipLoadStr(PW_Caption),
        ZipLoadStr(PW_MessageConfirm), DHC_AddPWrd2,
        mbOkCancel, p2);
      if (Response = mbOK) and (p2 <> '') then
        if AnsiCompareStr(p1, p2) <> 0 then
        begin
          ShowZipMessage(GE_WrongPassword, '');
          p2 := '';
        end;
    end;
  end;
  Result := p2;
end;

(*? TZMWorker.GetCount
*)
function TZMWorker.GetCount: Integer;
begin
  if ZipFileName <> '' then
    Result := ZipContents.Count
  else
    Result := 0;
end;

(*? TZMWorker.GetDirEntry
*)
function TZMWorker.GetDirEntry(idx: Integer): pZipDirEntry;
begin
  Result := pZipDirEntry(ZipContents.Items[idx]);
end;

(*? TZMWorker.GetDriveProps
1.79 21 May 2005 added test for Read-Only volume
 // Check to see if drive in FDrive is a valid drive.
 // If so, put it's volume label in FVolumeName,
 //        put it's size in FSizeOfDisk,
 //        put it's free space in FDiskFree,
 //        and return true.
 // was IsDiskPresent
 // If not valid, return false.
 // Called by _List() and CheckForDisk().
*)
function TZMWorker.GetDriveProps: Boolean;
const
  _FILE_READ_ONLY_VOLUME = $00080000;
var
  SysFlags, OldErrMode: DWord;
  NamLen: Cardinal;
  SysLen: DWord;
  VolNameAry: array[0..255] of Char;
  Num:  Integer;
  Bits: set of 0..25;
  DriveLetter: Char;
  DiskSerial: Cardinal;//Integer;
begin
  NamLen := 255;
  SysLen := 255;
  FSizeOfDisk := 0;
  FDiskFree := 0;
  FVolumeName := '';
  VolNameAry[0] := #0;
  Result := False;
  DriveLetter := UpperCase(FDrive)[1];
  //  FDriveFixed := IsFixedDrive(FDrive);

  if DriveLetter <> '\' then                // Only for local drives
  begin
    if (DriveLetter < 'A') or (DriveLetter > 'Z') then
      raise EZipMaster.CreateResDrive( DS_NotaDrive, FDrive);

    Integer(Bits) := GetLogicalDrives();
    Num := Ord(DriveLetter) - Ord('A');
    if not (Num in Bits) then
      raise EZipMaster.CreateResDrive( DS_DriveNoMount, FDrive);
  end;

  OldErrMode := SetErrorMode(SEM_FAILCRITICALERRORS);
  // Turn off critical errors:

  // Since v1.52c no exception will be raised here; moved to List() itself.
  //  if (not FDriveFixed) and
  // 1.72 only get Volume label for removable drives
  if (not GetVolumeInformation(Pchar(FDrive), VolNameAry,
    NamLen, @DiskSerial, SysLen, SysFlags, Nil, 0)) then
  begin
    // W'll get this if there is a disk but it is not or wrong formatted
    // so this disk can only be used when we also want formatting.
    if (GetLastError() = 31) and (AddDiskSpanErase in FAddOptions) then
      Result := True;
    SetErrorMode(OldErrMode);               //v1.52i
    Exit;
  end;

  FVolumeName := VolNameAry;
  FVolumeReadOnly := (SysFlags and _FILE_READ_ONLY_VOLUME) <> 0;
  { get free disk space and size. }
  DiskFreeAndSize(3);                       // RCV150199

  SetErrorMode(OldErrMode);   // Restore critical errors:

  // -1 is not very likely to happen since GetVolumeInformation catches errors.
  // But on W95(+OSR1) and a UNC filename w'll get also -1, this would prevent
  // opening the file. !!!Potential error while using spanning with a UNC filename!!!
  if (DriveLetter = '\') or ((DriveLetter <> '\') and
    (FSizeOfDisk <> -1)) then
    Result := True;
end;

(*? TZMWorker.GetExtrPassword
1.76 25 May 2004 changed
1.76 10 May 2004 change loading strings
  Same as GetAddPassword, but does NOT verify
*)
function TZMWorker.GetExtrPassword(
  var Response: TPasswordButton): String;
begin
  Result := '';
  if Unattended then
    ShowZipMessage(PW_UnatExtPWMiss, '')
  else
    Response := GetPassword(ZipLoadStr(PW_Caption),
      ZipLoadStr(PW_MessageEnter), DHC_ExtrPwrd,
      [mbOK, mbCancel, mbAll], Result);
end;

(*? TZMWorker.GetLastVolume
1.77 21 August 2004 RP improve orphan file tolerance
1.77 19 August 2004 RA Allow >99 parts with compatnames
1.76 9 June 2004 RA fix finding part of non-split file
1.75 16 March 2004 RA stop exception if unwanted file does not exist
1.73.2.7 13 September 2003 RP avoid neg part numbers
1.73  9 July 2003 RA creation of first part name corrected
1.73 28 June 2003 new fuction
*)
{$IFNDEF NO_SPAN}
function TZMWorker.GetLastVolume(FileName: String;
  var EOC: ZipEndOfCentral; AllowNotExists: Boolean): Integer;
var
  Path, Fname, Ext, sName, s: String;
  PartNbr: Integer;
//  Abort,
  FMVolume, Finding: Boolean;
//  tmpGetNextDisk: TGetNextDiskEvent;

  function NameOfPart(fn: String; compat: Boolean): String;
  var
    r, n: Integer;
    sRec: TSearchRec;
    fs: String;
  begin
    Result := '';
    if compat then
      fs := fn + '.z??*'
    else
      fs := fn + '???.zip';
    r := FindFirst(fs, faAnyFile, SRec);
    while r = 0 do
    begin
      if compat then
      begin
        fs := UpperCase(copy(ExtractFileExt(SRec.Name), 3, 20));
        if fs = 'IP' then
          n := 99999
        else
          n := StrToIntDef(fs, 0);
      end
      else
        n := StrToIntDef(copy(SRec.Name,
          Length(SRec.Name) - 6, 3), 0);
      if n > 0 then
      begin
        Result := SRec.Name;                // possible name
        break;
      end;
      r := FindNext(SRec);
    end;
    SysUtils.FindClose(SRec);
  end;

begin
  PartNbr := -1;
  FInFileHandle := -1;
  FMVolume := False;
  FDrive := ExtractFileDrive(ExpandFileName(FileName)) + '\';
  Path := ExtractFilePath(FileName);
  Ext := Uppercase(ExtractFileExt(FileName));
  FNumbering := znsNone;    // unknown as yet
  try
    FDriveFixed := IsFixedDrive(FDrive);
    GetDriveProps;                          // check valid drive
    if not FileExists(FileName) then
    begin
      Fname := copy(FileName, 1, Length(FileName) - Length(Ext));
      // remove extension
      FMVolume := True;
      // file did not exist maybe it is a multi volume
      if FDriveFixed then
        // if file not exists on harddisk then only Multi volume parts are possible
      begin
        // filename is of type ArchiveXXX.zip
        // MV files are series with consecutive partnbrs in filename, highest number has EOC
        if Ext = '.ZIP' then
        begin
          Finding := True;
          while Finding do
          begin
            s := Fname + copy(IntToStr(1002 + PartNbr),
              2, 3) + '.zip';
            if not FileExists(s) then
            begin
              PartNbr := -1;
              break;
            end;
            Inc(PartNbr);
            FInFileName := s;
            if OpenEOC(EOC, False) then
            begin
              Finding := False;
              if EOC.ThisDiskNo <> PartNbr then
                PartNbr := -1;   // not valid last part
            end;
            File_Close(FInFileHandle);
          end;
        end;
        if PartNbr = -1 then
        begin
          if not AllowNotExists then
            raise EZipMaster.CreateResDisp( DS_FileOpen, True);
          Result := 1;
          exit;                             // non found
        end;
        FileName := Fname + copy(IntToStr(1001 + PartNbr),
          2, 3) + '.zip';
        // check if filename.z01 exists then it is part of MV with compat names and cannot be used
        if (FileExists(ChangeFileExt(FileName, '.z01'))) then
          raise EZipMaster.CreateResDisp( DS_FileOpen, True);
        // cannot be used
      end
      else // if we have an MV archive copied to a removable disk
      begin
        // accept any MV filename on disk
        sName := NameOfPart(Fname, False);
        if sName = '' then
          sName := NameOfPart(Fname, True);
        if sName = '' then                  // none
          //          raise EZipMaster.CreateResDisp( DS_FileOpen, true);
        begin                               // 1.75 RA
          if not AllowNotExists then
            raise EZipMaster.CreateResDisp( DS_FileOpen, True);
          Result := 1;
          exit;
        end;
        FileName := Path + sName;
      end;
    end;                                    // if not exists
    // zip file exists or we got an acceptable part in multivolume or split archive
    FInFileName := FileName;
    // use class variable for other functions
    while not OpenEOC(EOC, False) do
      // does this part contains the central dir
    begin // it is not the disk with central dir so ask for the last disk
      File_Close(FInFileHandle); 
      fNewDisk := True;                   // new last disk
      fDiskNr := -1;                      // read operation
      CheckForDisk(False);
      // does the request for new disk
      if FDriveFixed then
      begin
        if FMVolume then
          raise EZipMaster.CreateResDisp( DS_FileOpen, True);
        // it was not a valable part
        AllowNotExists := False;  // next error needs to be displayed always
        raise EZipMaster.CreateResDisp( DS_NoValidZip, True);
        // file with EOC is not on fixed disk
      end;
(*      // for spanned archives on cdrom's or floppies
      tmpGetNextDisk := Events.OnGetNextDisk;
      if assigned(tmpGetNextDisk) then
      begin                                 // v1.60L
        Abort := False;
        tmpGetNextDisk(Master, 0, 0, copy(FDrive, 1, 1), Abort);
        if Abort then
          // we allow abort by the user
        begin
          File_Close(FInFileHandle);
          Result := 1;
          exit;
        end;
        GetDriveProps;
        // check drive spec and get volume name
      end
      else
      begin                                 // if no event handler is used
        FNewDisk := True;
        FDiskNr := -1;                      // read operation
        CheckForDisk(False);                 // ask for new disk
      end; *)
      if FMVolume then
      begin // we have removable disks with multi volume archives
        //  get the file name on this disk
        //        sName := NameOfPart(Fname, spCompatName in FSpanOptions);
        sName := NameOfPart(Fname, False);
        if sName = '' then
          sName := NameOfPart(Fname, True);
        if sName = '' then
        begin // no acceptable file on this disk so not a disk of the set
          ShowZipMessage(DS_FileOpen, '');
          Result := -1;                     //error
          exit;
        end;
        FInFileName := Path + sName;
      end;
    end;                                    // while
    if FMVolume then
      // got a multi volume part so we need more checks
    begin                                   // is this first file of a spanned
      if (not FIsSpanned) and ((EOC.ThisDiskNo = 0) and
        (PartNbr >= 0)) then
        raise EZipMaster.CreateResDisp( DS_FileOpen, True);
      // part and EOC equal?
      if FDriveFixed and (EOC.ThisDiskNo <> PartNbr) then
        raise EZipMaster.CreateResDisp( DS_NoValidZip, True);
    end;

  except
    on E: EZipMaster do
    begin
      if not AllowNotExists then
        ShowExceptionError(E);
      FInFileName := '';                    // don't use the file
      File_Close(FInFileHandle);            //close filehandle if open
      Result := -1;
      exit;
    end;
  end;
  Result := 0;
end;
{$ENDIF}

(*?  TZMWorker.GetNewDisk
1.77 19 August 2004 RP - improve logic
1.73 12 July 2003 RA clear file handle, change loop
*)
procedure TZMWorker.GetNewDisk(DiskSeq: Integer);
begin
{$IFDEF NO_SPAN}
  raise EZipMaster.CreateResDisp( DS_NODISKSPAN, True);
{$ELSE}
  File_Close(FInFileHandle);
  // Close the file on the old disk first.
  FDiskNr := DiskSeq;
  while True do
  begin
    repeat
      FNewDisk := True;
      FInFileHandle := -1;                  // 173 mark closed
      CheckForDisk(False);
    until IsRightDisk;

    if Verbose then
      Report(zacMessage, 0, ZipFmtLoadStr(TM_GetNewDisk,
        [FInFileName]), 0);
    //      'Trace : GetNewDisk Opening ' + FInFileName, 0);
    // Open the the input archive on this disk.
    FInFileHandle := FileOpen(FInFileName, fmShareDenyWrite or
      fmOpenRead);
    if FInFileHandle <> -1 then
      break;   // found
    if FDriveFixed then
      raise EZipMaster.CreateResDisp( DS_NoInFile, True)
    else
      ShowZipMessage(DS_NoInFile, ''); 
  end;
{$ENDIF}
end;

(*? TZMWorker.GetPassword
1.76 25 May 2004 no external GlobalResult
*)
function TZMWorker.GetPassword(DialogCaption, MsgTxt: String;
  ctx: Integer; pwb: TPasswordButtons;
  var ResultStr: String): TPasswordButton;
var
  GModalResult: TModalResult;
  msg: String;
begin
  msg := MsgTxt;
  ResultStr := '';
  GModalResult := ZipMessageDialog(DialogCaption, msg,
    zmtPassword + (ctx and $FFFF), pwb);
  case GModalResult of
    mrOk:
    begin
      ResultStr := msg;
      Result := mbOK;
    end;
    mrCancel:
      Result := mbCancel;
    mrAll:
      Result := mbNoToAll;
    else
      Result := mbAbort;
  end;
end;

function TZMWorker.GetPassword(DialogCaption, MsgTxt: String;
  pwb: TPasswordButtons; var ResultStr: String): TPasswordButton;
begin
  Result := GetPassword(DialogCaption, MsgTxt, DHC_Password,
    pwb, ResultStr);
end;

(*? TZMWorker.GetSFXSlave
1.73 15 Juli 2003 RA added passing message type in MessageFlags to slave
1.73 4 July 2003
*)
function TZMWorker.GetSFXSlave: TZipSFX;
begin
  Result := FSFX;
  if not assigned(Result) then
    raise EZipMaster.CreateResDisp( SF_NoSFXSupport, True);
end;

(*? TZMWorker.GetZipComment
1.73.3.2 11 Oct 2003 RP comment now converted when read
*)
function TZMWorker.GetZipComment: String;
begin
  Result := FZipComment;
end;
 
(*? TZMWorker.CheckDestWritable
1.79  2007 Feb 22 - replaces IsDestWritable
*)
function TZMWorker.CheckDestWritable(const fname: String; NoExc: boolean):
    Boolean;
var
  hFile: Integer;
  drt: Integer;
  XP:  Boolean;
  xname: String;
  sr:  TSearchRec;
begin
  Result := False;
  xname := ExpandUNCFileName(fname);
  // test if destination can be written
  FDrive := ExtractFileDrive(xname) + '\';
  drt := GetDriveType(Pchar(FDrive));
  GetDriveProps;  // check valid drive
  XP := IsWinXp;
  SetLastError(0);
//  if XP and FVolumeReadOnly then    // XP only - true if volume Read-Only
//  begin
//    if not NoExc then
//      raise EZipMaster.CreateResDrive( DS_NotChangeable, xname);
//    exit;
//  end;
  if XP or (drt <> DRIVE_CDROM) then
  begin
    if sysUtils.FindFirst(xname, faAnyFile, sr) = 0 then
    begin
      Result := (sr.Attr and faReadOnly) = 0;
      sysUtils.FindClose(sr);
      if Result then
      begin
        // exists and is not read-only - test locked
        hFile := SysUtils.FileOpen(xname, fmOpenWrite);
        Result := hFile > -1;
        if Result then
          SysUtils.FileClose(hFile);
      end;
    end//;
    else
    begin
      // file did not exist - try to create it
      hFile := FileCreate(xname);
      if hFile > -1 then
      begin
        Result := True;
        FileClose(hFile);
  //      SysUtils.DeleteFile(xname);
        if not SysUtils.DeleteFile(xname) then
          raise Exception.CreateFmt('Delete failed [%d] for: %s',
                  [GetLastError, xname]);
      end;
    end;
    if not Result and not NoExc then
      raise EZipMaster.CreateResMsgOS( DS_NotChangeable, xname, GetLastError());
  end;
end;

(*? TZMWorker.IsFixedDrive
// new 1.72 tests for 'fixed' drives
*)
function TZMWorker.IsFixedDrive(drv: String): Boolean;
var
  drt: Integer;
begin
  drt := GetDriveType(Pchar(drv));
  Result := (drt = DRIVE_FIXED) or (drt = DRIVE_REMOTE) or (drt =
    DRIVE_RAMDISK);
end;

(*? TZMWorker.IsRightDisk
1.79 15 July 2005 stop infinite loop in GetNewDisk
1.73 29 June 2003 RP amended
*)
{$IFNDEF NO_SPAN}
function TZMWorker.IsRightDisk: Boolean;
var
  fn: String;
begin
  Result := True;
  if (FNumbering < znsName) and (not FDriveFixed) and
    (FVolumeName = 'PKBACK# ' + copy(IntToStr(1001 + FDiskNr), 2,
    3)) and (FileExists(FInfileName)) then
  begin
    FNumbering := znsVolume;
    exit;
  end;
  if FNumbering = znsNone then  // not known yet
  begin
    fn := FInFileName;
    CreateMVFileNameEx(FInFileName, True, True);  // make compat name
    if FileExists(FInFileName) then
    begin
      FNumbering := znsExt;
      exit;
    end;
    FInFileName := fn;
    CreateMVFileNameEx(FInFileName, {false}True, False);
    // make numbered name
    if FileExists(FInFileName) then
    begin
      FNumbering := znsName;
      exit;
    end;
    if FDriveFixed then
      exit;       // always true - only needed name
    FInFileName := fn;      // restore
    Result := False;
    exit;
  end;
  // numbering scheme already known
  if FNumbering = znsVolume then
  begin
    Result := False;
    exit;
  end;
  CreateMVFileNameEx(FInFileName, True, FNumbering = znsExt);
  // fixed drive always true only needed new filename   
  if (not FDriveFixed) and (not FileExists(FInFileName)) then
  begin
    FInFileName := fn;      // restore
    Result := False;
  end;
end;
{$ENDIF}

(*? TZMWorker.IsZipSFX
  Return value:
 0 = The specified file is not a SFX
 1 = It is one
 -7  = Open, read or seek error
 -8  = memory error
 -9  = exception error
 -10 = all other exceptions
 *)
function TZMWorker.IsZipSFX(const SFXExeName: String): Integer;
var
  r: Integer;
begin
  r := QueryZip(SFXExeName);
  // SFX = 1 + 128 + 64
  Result := 0;
  if (r and (1 or 128 or 64)) = (1 or 128 or 64) then
    Result := 1;
end;

(*? TZMWorker.List
1.79 23 July 2005 RA mark no inFile if file does not exist
1.79  7 Dec 2004 RA allow .exe with detached header
1.79  5 Dec 2004 RP always call OnDirUpdate if no entries
1.76  9 June 2004 stop Range Error >2G
1.76 28 April 2004 test Active
1.76 25 April 2004 use GetLastVolume
1.75 13 March 2004 give progress
1.75 18 February 2004 RP allow file>2G
1.73.3.2 Oct 11 2003 RP convert saved comment
1.73.3.2 Oct 9 2003 RP don't clear ZipComment if file does not exist
1.73 15 July 2003 RP ReadJoin
1.73 13 July 2003 RP change handling part of span
1.73 12 July 2003 RP string Extra Data
1.73 27 June 2003 RP changed Split disk handling
{ New in v1.50: We are now looking at the Central zip Dir, instead of
  the local zip dir.  This change was needed so we could support
  Disk-Spanning, where the dir for the whole disk set is on the last disk.}
{ The List method reads thru all entries in the central Zip directory.
  This is triggered by an assignment to the ZipFilename, or by calling
  this method directly. }
*)
function TZMWorker.List: Integer;
  { all work is local - no DLL calls }
var
  pzd: pZipDirEntry;
  EOC, tmpEOC: ZipEndOfCentral;
  CEH: ZipCentralHeader;
  Fn: String;
  OffsetDiff: Int64;
  Fname: AnsiString;
  i, LiE: Integer;
  MadeOS, MadeVer: Byte;
  tmpDirUpdate: TNotifyEvent;
  tmpNewName: TNewNameEvent;
begin
  LiE := 1;
  // any exceptions will be error
  { zero out any previous entries }
  FreeZipDirEntryRecords;

  FRealFileSize := 0;
  FZipSOC := 0;
  FSFXOffset := 0;
  FZipComment := '';
  OffsetDiff := 0;
  FIsSpanned := False;
  FDirOnlyCount := 0;
  fErrCode := 0;                             
  MadeOS := 0;
  MadeVer := 20;
  Result := fErrCode;

  if not Active then
  begin
    FDelaying := FDelaying + [zdiList];
    exit;
  end;
  try
{$IFNDEF NO_SPAN}
    // Locate last of multi volume or last disk of split
    if (QueryZip(FZipFileName) and DetachMask) = 145 then
      FInFileName := ChangeFileExt(FZipFileName, '.zip')
    else
      FInFileName := FZipFileName;
    GetLastVolume(FInFileName, EOC, True);
{$ELSE}
    FInfileName := FZipFileName;
    if (FZipFileName <> '') and FileExists(FZipFileName) then
      OpenEOC(EOC, True)                     // exception if not
    else
      FInFileHandle := -1;
{$ENDIF}
  except
    on E: EZipMaster do
      ShowExceptionError(E);
  end;
  { let user's program know there's no entries }
  if FInFileHandle = -1 then                // was problem
  begin
    tmpDirUpdate := Events.OnDirUpdate;
    if Assigned(tmpDirUpdate) then
      tmpDirUpdate(Master);
    Exit;
  end;
  try
    StartWaitCursor;
    try
      FTotalDisks := EOC.ThisDiskNo;
      // Needed in case GetNewDisk is called.

      // This could also be set to True if it's the first and only disk.
      if EOC.ThisDiskNo > 0 then
        FIsSpanned := True;

      // Do we have to request for a previous disk first?
      if EOC.ThisDiskNo <> EOC.CentralDiskNo then
      begin
        GetNewDisk(EOC.CentralDiskNo);
        FFileSize := Cardinal(FileSeek64(FInFileHandle, Int64(0), 2));
        //v1.52i
        OffsetDiff := EOC.CentralOffset;
      end
      else
        // Due to the fact that v1.3 and v1.4x programs do not change the archives
        // EOC and CEH records in case of a SFX conversion (and back) we have to
        // make this extra check.
        OffsetDiff := Longword(FFileSize) - EOC.CentralSize -
          SizeOf(EOC) - EOC.ZipCommentLen;
      FZipSOC := OffsetDiff;
      // save the location of the Start Of Central dir
      FSFXOffset := FFileSize;
      // initialize this - we will reduce it later
      if FFileSize = 22 then
        FSFXOffset := 0;

      FWrongZipStruct := False;
      if EOC.CentralOffset <> Longword(OffsetDiff) then
      begin
        FWrongZipStruct := True;
        // We need this in the ConvertXxx functions.
        ShowZipMessage(LI_WrongZipStruct, '');
      end;

      // Now we can go to the start of the Central directory.
      if FileSeek64(FInFileHandle, OffsetDiff, 0) = -1 then
        raise EZipMaster.CreateResDisp( LI_ReadZipError, True);

      Report(zacXItem, zprLoading, ZipLoadStr(PR_Loading), EOC.TotalEntries);
      // Read every entry: The central header and save the information.
{$IFDEF DEBUG}
      if Trace then
        Report(zacMessage, 0,
          Format('List - expecting %d files', [EOC.TotalEntries]), 0);
{$ENDIF}
      ZipContents.Capacity := EOC.TotalEntries;
      FDirHashs.AutoSize(EOC.TotalEntries);  // resize appropriately
      for i := 0 to (EOC.TotalEntries - 1) do
      begin
        // Read a central header entry for 1 file
        while FileRead(FInFileHandle, CEH, SizeOf(CEH)) <>
          SizeOf(CEH) do
          //v1.52i
        begin
          // It's possible that we have the central header split up.
          if FDiskNr >= EOC.ThisDiskNo then
            raise EZipMaster.CreateResDisp( DS_CEHBadRead, True);
          // We need the next disk with central header ZipLoadStr.
          GetNewDisk(FDiskNr + 1);
        end;

        //validate the signature of the central header entry
        if CEH.HeaderSig <> CentralFileHeaderSig then
          raise EZipMaster.CreateResDisp( DS_CEHWrongSig, True);

        if CEH.FileNameLen >= MAX_PATH then
          raise EZipMaster.CreateResDisp(DS_CENameLen, true);
        // Now the filename
        SetLength(Fname, CEH.FileNameLen);
        ReadJoin(Fname[1], CEH.FileNameLen, DS_CENameLen);

        // Save version globally for use by codepage translation routine
        FVersionMadeBy0 := CEH.VersionMadeBy0;
        FVersionMadeBy1 := CEH.VersionMadeBy1;
        if FVersionMadeBy1 > 0 then         // not msdos
        begin
          MadeOs := FVersionMadeBy1;
          MadeVer := FVersionMadeBy0;
        end;
//        Fname := ConvertOEM(Fname, cpdOEM2ISO);
        Fn := ConvertOEM(string(Fname), cpdOEM2ISO);
{$IFDEF DEBUG}
        if Trace then
          Report(zacMessage, 0,
            Format('List - [%d] "%s"', [i, Fn{ame}]), 0);
{$ENDIF}
        // Create a new ZipDirEntry pointer.
        New(pzd); // These will be deleted in: FreeZipDirEntryRecords.

        // Copy the needed file info from the central header.
        CopyMemory(pzd, @CEH.VersionMadeBy0, 42);
        pzd^.FileName := SetSlash(Fn{ame}, psdExternal);
        pzd^.Encrypted := (pzd^.Flag and 1) > 0;

        pzd^.ExtraData := '';
        // Read the extra data if present new v1.6
        if pzd^.ExtraFieldLength > 0 then
        begin
          SetLength(Fname, pzd^.ExtraFieldLength);
          ReadJoin(Fname[1], CEH.ExtraLen, LI_ReadZipError);
          pzd^.ExtraData := Fname;
//          SetLength(pzd^.ExtraData, pzd^.ExtraFieldLength);
//          ReadJoin(pzd^.ExtraData[1], CEH.ExtraLen, LI_ReadZipError);
        end;

        // Read the FileComment, if present, and save.
        if CEH.FileComLen > 0 then
        begin
          // get the file comment
          SetLength(Fname, CEH.FileComLen);
          ReadJoin(Fname[1], CEH.FileComLen, DS_CECommentLen);
//          SetLength(pzd^.FileComment, CEH.FileComLen);
//          ReadJoin(pzd^.FileComment[1], CEH.FileComLen,
//            DS_CECommentLen);
          pzd^.FileComment :=
            ConvertOEM(string(Fname), cpdOEM2ISO);
//            ConvertOEM(pzd^.FileComment, cpdOEM2ISO);
        end;

        if FUseDirOnlyEntries or
          (ExtractFileName(pzd^.FileName) <> '') then
        begin                               // Add it to our contents tabel.
{$IFDEF DEBUG}
          if Trace then
            Report(zacMessage, 0,
              Format('List - adding "%s" [%s]',
              [pzd.FileName, pzd.FileComment]), 0);
{$ENDIF}
          ZipContents.Add(pzd);
          FDirHashs.Add(pzd);  // ignore duplicates
          tmpNewName := Events.OnNewName;
          // Notify user, when needed, of the next entry in the ZipDir.
          if Assigned(tmpNewName) then
            tmpNewName(Master, i + 1, pzd^);
        end
        else
        begin
          Inc(FDirOnlyCount);
{$IFDEF DEBUG}
          if Trace then
            Report(zacMessage, 0,
              Format('List - dropped dir [%d]', [FDirOnlyCount]), 0);
{$ENDIF}
          pzd^.ExtraData := '';
          pzd.FileName := '';
          pzd.FileComment := '';
          Dispose(pzd);
        end;

        // Calculate the earliest Local Header start
        if FSFXOffset > CEH.RelOffLocal then
          FSFXOffset := CEH.RelOffLocal;
        Report(zacXProgress, zprLoading, ZipLoadStr(PR_Loading), 1);
        if Cancel then
          raise EZipMaster.CreateResDisp( DS_Canceled, True);
      end;                               
        // Read the end of central header entry
      while FileRead(FInFileHandle, tmpEOC, SizeOf(tmpEOC)) <>
        SizeOf(tmpEOC) do
        //v1.52i
      begin
        // It's possible that we have the central header split up.
        if FDiskNr >= EOC.ThisDiskNo then
          raise EZipMaster.CreateResDisp( DS_CEHBadRead, True);
        // We need the next disk with central header ZipLoadStr.
        GetNewDisk(FDiskNr + 1);
      end;

      //validate the signature of the central header entry
      if tmpEOC.HeaderSig <> EndCentralDirSig then
        raise EZipMaster.CreateResDisp( DS_EOCBadRead{LI_WrongZipStruct}, True);
      FTotalDisks := EOC.ThisDiskNo;
      // We need this when we are going to extract.
      LiE := 0;                             // finished ok
    except
      on ezl: EZipMaster do
        // Catch all Zip List specific errors.
      begin
        ShowExceptionError(ezl);
      end;
      on EOutOfMemory do
      begin
        ShowZipMessage(GE_NoMem, '');
      end;
      on E: Exception do
      begin
        // the error message of an unknown error is displayed ...
        ShowZipMessage(LI_ErrorUnknown, E.Message);
      end;
    end;
  finally
    Report(zacEndOfBatch, zprLoading, '', 0);
    StopWaitCursor;
    File_Close(FInFileHandle); 
    if LiE = 1 then
    begin
      FZipFileName := '';
      FSFXOffset := 0;
    end
    else
    begin
      // Correct the offset for v1.3 and 1.4x
      FSFXOffset := FSFXOffset + Cardinal(OffsetDiff -
        Int64(EOC.CentralOffset));
      FVersionMadeBy1 := MadeOS;
      // if any not dos assume comment not oem
      FVersionMadeBy0 := MadeVer;
      FZipComment := ConvertOEM(FEOCComment, cpdOEM2ISO);
    end;

    // Let the user's program know we just refreshed the zip dir contents.
    tmpDirUpdate := Events.OnDirUpdate; 
    if Assigned(tmpDirUpdate) then
      tmpDirUpdate(Master);
  end;
  Result := fErrCode;
end;

(*? TZMWorker.MakeString
   //RP 2010-04-24 - removed
*)
//{$IFNDEF NO_SPAN}
// TODO: MakeString
//function TZMWorker.MakeString(Buffer: PAnsiChar; Size: Integer): String;
//begin
//SetLength(Result, Size);
//StrLCopy(Pchar(Result), Buffer, Size);
//end;
//{$ENDIF}

(*? TZMWorker.NewSFXFile
*)
function TZMWorker.NewSFXFile(const ExeName: String): Integer;
var
  slave: TZipSFX;
  tmpMessage: TMessageEvent;
begin
  slave := GetSFXSlave;
  Result := 0;
  try
    with slave do
    begin
      SourceFile := FZipFileName;
      TargetFile := ExeName;
    end;
    Slave.CreateNewSFX;
  except
    on E: EZipMaster do
    begin
      FErrCode := E.ResId;
      if FUnattended = False then
        ZipMessageDlg(E.Message, DHC_ExSFXNew);
      tmpMessage := Events.OnMessage;
      if Assigned(tmpMessage) then
        tmpMessage(Master, ErrCode, E.Message);
    end;
    on E: Exception do
    begin
      FErrCode := GE_Unknown;
      if FUnattended = False then
        ZipMessageDlg(E.Message, DHC_ExSFXNew);
      tmpMessage := Events.OnMessage;
      if Assigned(tmpMessage) then
        tmpMessage(Master, 0, E.Message);
    end;
  end;
end;

(*? TZMWorker.OpenEOC
1.77 19 August 2004 RA Allow >99 parts with compatnames
1.76 30 May 2004 Check file <4G
1.75 18 February 2004 allow >2G
1.73.3.2 11 October 2003 RP changed 'garbage' check and save comment
1.73.2.7 12 September 2003 RP stop Disk number < 0
1.73 13 July 2003 RP changed find EOC
// Function to find the EOC record at the end of the archive (on the last disk.)
// We can get a return value( true::Found, false::Not Found ) or an exception if not found.
 1.73 28 June 2003 RP change handling split files
*)
function TZMWorker.OpenEOC(var EOC: ZipEndOfCentral;
  DoExcept: Boolean): Boolean;
var
  Size, Sig, i{, j}: Cardinal;
  DiskNo: Integer;
//  ShowGarbageMsg: Boolean;
  First: Boolean;
  zc: AnsiString;
  ZipBuf: AnsiString;
  ext: String;
  SizeOfFile: I64Rec;
begin
{$OVERFLOWCHECKS OFF}
  FZipComment := '';
  First := False;
  FZipEOC := 0;
  FEOCComment := '';

  // Open the input archive, presumably the last disk.
  FInFileHandle := FileOpen(FInFileName, fmShareDenyWrite or
    fmOpenRead);
  if FInFileHandle = -1 then
  begin
    ShowZipMessage(DS_FileOpen, '');
    Result := False;
    if DoExcept then
      raise EZipMaster.CreateResDisp( DS_NoInFile, True);
    Exit;
  end;

  // First a check for the first disk of a spanned archive,
  // could also be the last so we don't issue a warning yet.
  if (FileRead(FInFileHandle, Sig, 4) = 4) and
    (Sig = ExtLocalSig) and
    (FileRead(FInFileHandle, Sig, 4) = 4) and
    (Sig = LocalFileHeaderSig) then
  begin
    First := True;
    FIsSpanned := True;
  end;

  // Next we do a check at the end of the file to speed things up if
  // there isn't a Zip archive comment.
  SizeOfFile.I := FileSeek64(FInFileHandle,
    -Int64(SizeOf(ZipEndOfCentral)), 2);
  if SizeOfFile.I >= 0 then
    SizeOfFile.I := SizeOfFile.I + SizeOf(ZipEndOfCentral);
  //  if (SizeOfFile < 0) or (SizeOfFile>HIGH(Cardinal)) then
  if SizeOfFile.Hi <> 0 then
  begin
    Result := False;
    File_Close(FInFileHandle);
    if Verbose then
      Report(zacMessage, 0, 'Opening EOC seek/size error ' +
        IntToStr(SizeOfFile.I div (1024 * 1024)) + 'Mb', 0);
    if DoExcept then
    begin
      if SizeOfFile.I <> -1 then
        raise EZipMaster.CreateResDisp( LI_FileTooBig, True);
      raise EZipMaster.CreateResDisp( DS_NoValidZip, True);
    end;
    exit;
  end;
  FFileSize := SizeOfFile.Lo;
  if FFileSize >= SizeOf(ZipEndOfCentral) then
  begin
    // Save the archive size as a side effect.
    FRealFileSize := FFileSize;
    // There could follow a correction on FFileSize.
    if (FileRead(FInFileHandle, EOC, SizeOf(ZipEndOfCentral)) =
      SizeOf(ZipEndOfCentral)) and (EOC.HeaderSig =
      EndCentralDirSig) then
    begin
      FZipEOC := FFileSize - SizeOf(ZipEndOfCentral);
      Result := True;
      Exit;
    end;
  end;

  // Now we try to find the EOC record within the last 65535 + sizeof( EOC ) bytes
  // of this file because we don't know the Zip archive comment length at this time.
  try
    Size := 65535 + SizeOf(ZipEndOfCentral);
    if FFileSize < Size then
      Size := FFileSize;
    SetLength(ZipBuf, Size);
    if FileSeek64(FInFileHandle, -Int64(Size), 2) = -1 then
      raise EZipMaster.CreateResDisp( DS_FailedSeek, True);
    ReadJoin(PAnsiChar(ZipBuf)^, Size, DS_EOCBadRead);
    for i := Size - SizeOf(ZipEndOfCentral) - 1 downto 0 do
      if pZipEndOfCentral(PAnsiChar(ZipBuf) + i)^.HeaderSig = EndCentralDirSig then
      begin
        FZipEOC := FFileSize - Size + i;
        Move((PAnsiChar(ZipBuf) + i)^, EOC, SizeOf(ZipEndOfCentral));
        // Copy from our buffer to the EOC record.
        // If we have ZipComment: Save it,No codepage translation yet, wait for CEH read.
        if EOC.ZipCommentLen <> 0 then
        begin
          zc := copy(ZipBuf, i + Sizeof(ZipEndOfCentral) +
            1, EOC.ZipCommentLen);
          FEOCComment := string(zc);
        end;
        // Check if we really are at the end of the file, if not correct the filesize
        // and give a warning. (It should be an error but we are nice.)   
        if i + SizeOf(ZipEndOfCentral) + EOC.ZipCommentLen <> Size then
//        if not (i + SizeOf(ZipEndOfCentral) + EOC.ZipCommentLen -
//          Size = 0) then
        begin            
          if Verbose then
            Report(zacMessage, 0, ZipLoadStr(LI_GarbageAtEOF), 0);
          Inc(FFileSize, i + SizeOf(ZipEndOfCentral) +
            Cardinal(EOC.ZipCommentLen) - Size);
//          // Now we need a check for WinZip Self Extractor which makes SFX files which
//          // allmost always have garbage at the end (Zero filled at 512 byte boundary!)
//          // In this special case 'we' don't give a warning.
//          ShowGarbageMsg := True;
//          if (FRealFileSize - Cardinal(FFileSize) < 512) then
//          begin
//            j := i + SizeOf(ZipEndOfCentral) + EOC.ZipCommentLen;
//            while (j < Size) and (ZipBuf[j] < '/' ) do
//              Inc(j);
//            if j = Size + 1 then
//              ShowGarbageMsg := False;
//          end;
//          if ShowGarbageMsg then
//            ShowZipMessage(LI_GarbageAtEOF, '');
        end;
        { // If we have ZipComment: Save it, must be after Garbage check because a #0 is set!
            if not (EOC.ZipCommentLen = 0) then
            begin
             // No codepage translation yet, wait for CEH read.
             ZipBuf[i + SizeOf(ZipEndOfCentral) + EOC.ZipCommentLen] := #0;
             FZipComment := ZipBuf + i + SizeOf(ZipEndOfCentral);
            end;}
        Result := True;
        Exit;
      end;
  except
    if DoExcept = True then
      raise;
  end;
  File_Close(FInFileHandle);
  if DoExcept = True then
  begin
    // Get the volume number if it's disk from a set. - 1.72 moved
    DiskNo := 0;
    if Pos('PKBACK# ', FVolumeName) = 1 then
      DiskNo := StrToIntDef(Copy(FVolumeName, 9, 3), 0);
    //    else
    if DiskNo <= 0 then
    begin
      ext := UpperCase(ExtractFileExt(FInFileName));
      DiskNo := 0;
      if copy(ext, 1, 2) = '.Z' then
        DiskNo := StrToIntDef(copy(ext, 2, Length(ext) - 2), 0);
      if (DiskNo <= 0) then
        DiskNo := StrToIntDef(Copy(FInFileName, length(FInFileName) -
          length(ext) - 3 + 1, 3), 0);
    end;
    if (not First) and (DiskNo  > 0) then
      raise EZipMaster.CreateResDisk( DS_NotLastInSet, DiskNo);
    if First = True then
      if DiskNo = 1 then
        raise EZipMaster.CreateResDisp( DS_FirstInSet, True)
      else
        raise EZipMaster.CreateResDisp( DS_FirstFileOnHD, True)
    else
      raise EZipMaster.CreateResDisp( DS_NoValidZip, True);
  end;
  Result := False;
end;

(*? TZMWorker.ReadJoin
1.73 15 July 2003 new function
*)
procedure TZMWorker.ReadJoin(var Buffer;
  BufferSize, DSErrIdent: Integer);
begin
  if FileRead(FInFileHandle, Buffer, BufferSize) <> BufferSize then
    raise EZipMaster.CreateResDisp( DSErrIdent, True);
end;

(*? TZMWorker.ReadSpan
1.77  1 Sep 2004 RP Allow Cancel
1.77 8 Aug 2004 RA handle normal/ eXtended progress
1.75 18 February 2004 RP Allow >2G
1.73 12 July 2003 RA made Report type zacItem for each file + handling Result from GetLastVolume
1.73 11 July 2003 RP changed split file handling
// Function to read a split up Zip source file from multiple disks and write it to one destination file.
// Return values:
// 0            All Ok.
// -7           ReadSpan errors. See ZipMsgXX.rc
// -8           Memory allocation error.
// -9           General unknown ReadSpan error.
 *)
{$IFNDEF NO_SPAN}
function TZMWorker.ReadSpan(InFileName: String; var OutFilePath: String;
  useXProgress: Boolean): Integer;
var
  Buffer: array of AnsiChar;
  FullSize: Int64;
  EOC:  ZipEndOfCentral;
  LOH:  ZipLocalHeader;
  DD:   ZipDataDescriptor;
  CEH:  ZipCentralHeader;
  i, k: Integer;
  ExtendedSig: Integer;
  MsgStr: String;
  BytesToWrite: Int64;
  MDZD: TZMDataList;
  MDZDp: TMDZipData;//pMZipData;
  BatchStarted: Boolean;
begin
  BatchStarted := False;

  fErrCode := 0;
  fUnzBusy := True;
  FDrive := ExtractFileDrive(InFileName) + '\';
  FDriveFixed := IsFixedDrive(FDrive);
  FDiskNr := -1;
  FNewDisk := False;
  FShowProgress := zspNone; 
  FInFileName := InFileName;
  FInFileHandle := -1;
  FOutFileHandle := -1;
  MDZD := Nil;

  StartWaitCursor;
  try
    SetLength(Buffer, BufSize);
    // If we don't have a filename we make one first.
    if ExtractFileName(OutFilePath) = '' then
    begin
      OutFilePath := MakeTempFileName('', '');
      if OutFilePath = '' then
        raise EZipMaster.CreateResDisp( DS_NoTempFile, True);
    end
    else
    begin
      EraseFile(OutFilePath, FHowToDelete = htdFinal);
      OutFilePath := ChangeFileExt(OutFilePath, '.zip');
    end;

    // Try to get the last disk from the user if part of Volume numbered set
    Result := GetLastVolume(FInFileName, EOC, False);
    if Result < 0 then
    begin
      StopWaitCursor;
      FUnzBusy := False;
      Result := -9;
      exit;
    end;
    if Result > 0 then
      raise EZipMaster.CreateResDisp( DS_Canceled, True);

    // Create the output file.
    FOutFileHandle := FileCreate(OutFilePath);
    if FOutFileHandle = -1 then
      raise EZipMaster.CreateResDisp( DS_NoOutFile, True);

    // Get the date-time stamp and save for later.
    FDateStamp := FileGetDate(FInFileHandle);

    // Now we now the number of zipped entries in the zip archive
    // and the starting disk number of the central directory.
    FTotalDisks := EOC.ThisDiskNo;
    if EOC.ThisDiskNo <> EOC.CentralDiskNo then
      GetNewDisk(EOC.CentralDiskNo);
    // request a previous disk first
    // We go to the start of the Central directory. v1.52i
    if FileSeek64(FInFileHandle, Int64(EOC.CentralOffset),
      0) = -1 then
      raise EZipMaster.CreateResDisp( DS_FailedSeek, True);

    MDZD := TZMDataList.Create(EOC.TotalEntries);

    FullSize := EOC.CentralSize + EOC.ZipCommentLen +
      sizeof(ZipEndOfCentral);
    // Read for every entry: The central header and save information for later use.
    for i := 0 to (EOC.TotalEntries - 1) do
    begin
      if FCancel then   // 1.77 Allow cancel
        raise EZipMaster.CreateResDisp( DS_Canceled, False);
      // Read a central header.
      while FileRead(FInFileHandle, CEH, SizeOf(CEH)) <>
        SizeOf(CEH) do
        //v1.52i
      begin
        // It's possible that we have the central header split up
        if FDiskNr >= EOC.ThisDiskNo then
          raise EZipMaster.CreateResDisp( DS_CEHBadRead, True);
        // We need the next disk with central header ZipLoadStr.
        GetNewDisk(FDiskNr + 1);
      end;

      if CEH.HeaderSig <> CentralFileHeaderSig then
        raise EZipMaster.CreateResDisp( DS_CEHWrongSig, True);

      // Now the filename.
      ReadJoin(Buffer[0], CEH.FileNameLen, DS_CENameLen);

      // Save the file name info in the MDZD structure.
      MDZDp := MDZD[i];
//      MDZDp^.FileNameLen := CEH.FileNameLen;
      MDZDp.SetName(@Buffer[0], CEH.FileNameLen);
//      MDZDSetNameP(MDZDp, @Buffer[0], CEH.FileNameLen);
//      StrLCopy(MDZDp^.FileName, @Buffer[0], CEH.FileNameLen);

      // Save the compressed size, we need this because WinZip sometimes sets this to
      // zero in the local header. New v1.52d
      MDZDp.ComprSize := CEH.ComprSize;

      // We need the total number of bytes we are going to read for the progress event.
      //      TotalBytesToRead := TotalBytesToRead + Integer(CEH.ComprSize +
      //        CEH.FileNameLen + CEH.ExtraLen + CEH.FileComLen);
      Inc(FullSize, sizeof(ZipLocalHeader) + CEH.FileNameLen +
        CEH.ExtraLen + CEH.ComprSize);
      // plus DataDescriptor if present.
      if (CEH.Flag and Word(8)) = 8 then
        Inc(FullSize, SizeOf(ZipDataDescriptor));

      // Seek past the extra field and the file comment.
      if FileSeek64(FInFileHandle,
        Int64(CEH.ExtraLen + CEH.FileComLen),
        1) = -1 then
        raise EZipMaster.CreateResDisp( DS_FailedSeek, True);
    end;

    // Now we need the first disk and start reading.
    GetNewDisk(0);

    if UseXProgress then
    begin
      Report(zacXItem, zprJoining, ZipLoadStr(PR_Joining), FullSize);
      FShowProgress := zspExtra;
    end
    else
    begin
      Report(zacCount, zprCompressed, '', EOC.TotalEntries + 1);
      Report(zacSize, zprCompressed, '', FullSize);
      FShowProgress := zspFull;
      BatchStarted := True;
    end;
    // Read extended local Sig. first; is only present if it's a spanned archive.
    ReadJoin(ExtendedSig, 4, DS_ExtWrongSig);
    if ExtendedSig <> ExtLocalSig then
      raise EZipMaster.CreateResDisp( DS_ExtWrongSig, True);

    // Read for every zipped entry: The local header, variable data, fixed data
    // and if present the Data decriptor area.
    for i := 0 to (EOC.TotalEntries - 1) do
    begin
      if FCancel then   // 1.77 Allow cancel
        raise EZipMaster.CreateResDisp( DS_Canceled, False);
      // First the local header.
      while FileRead(FInFileHandle, LOH, SizeOf(LOH)) <>
        SizeOf(LOH) do
      begin
        // Check if we are at the end of a input disk not very likely but...
        if FileSeek64(FInFileHandle, Int64(0), 1) <>
          FileSeek64(FInFileHandle, Int64(0), 2) then
          raise EZipMaster.CreateResDisp( DS_LOHBadRead, True);
        // Well it seems we are at the end, so get a next disk.
        GetNewDisk(FDiskNr + 1);
      end;
      if LOH.HeaderSig <> LocalFileHeaderSig then
        raise EZipMaster.CreateResDisp( DS_LOHWrongSig, True);

      // Now the filename, should be on the same disk as the LOH record.
      ReadJoin(Buffer[0], LOH.FileNameLen, DS_LONameLen);

      // Change some info for later while writing the central dir.
      k := MDZD.IndexOf(@Buffer[0], LOH.FileNameLen);  // RP 2010-04-24
//      k := MDZD.IndexOf(MakeString(@Buffer[0], LOH.FileNameLen));
      MDZDp := MDZD[k];
      MDZDp.DiskStart := 0;
      MDZDp.RelOffLocal := FileSeek64(FOutFileHandle, Int64(0), 1);

      // Give message and progress info on the start of this new file read.
//      MsgStr := ZipLoadStr(GE_CopyFile) + SetSlash(MDZDGetName(MDZDp), psdExternal);
      MsgStr := ZipLoadStr(GE_CopyFile) + SetSlash(MDZDp.FileName, psdExternal);
//        SetSlash(MDZDp^.FileName, psdExternal);
      Report(zacMessage, 0, MsgStr, 0);

      BytesToWrite := SizeOf(LOH) + LOH.FileNameLen + LOH.ExtraLen +
        LOH.ComprSize;
      if (LOH.Flag and Word($0008)) = 8 then
        Inc(BytesToWrite, SizeOf(DD));
      if not UseXProgress then
//        Report(zacItem, 0, MDZDGetName(MDZDp), BytesToWrite);
        Report(zacItem, 0, MDZDp.FileName, BytesToWrite);
//        Report(zacItem, 0, MDZDp^.FileName, BytesToWrite);

      // Write the local header to the destination.
      WriteJoin(LOH, SizeOf(LOH), DS_LOHBadWrite);

      // Write the filename.
      WriteJoin(Buffer[0], LOH.FileNameLen, DS_LOHBadWrite);

      // And the extra field
      RWJoinData(Buffer[0], LOH.ExtraLen, DS_LOExtraLen);

      // Read Zipped data, if the size is not known use the size from the central header.
      if LOH.ComprSize = 0 then
        LOH.ComprSize := MDZDp.ComprSize;  // New v1.52d
      RWJoinData(Buffer[0], LOH.ComprSize, DS_ZipData);

      // Read DataDescriptor if present.
      if (LOH.Flag and Word($0008)) = 8 then
        RWJoinData(DD, SizeOf(DD), DS_DataDesc);
    end; // Now we have written all entries to the (hard)disk.
    //    if not UseXProgress then
    //      Report(zacEndOfBatch, zprCompressed, '', 0);      // end of batch

    // Now write the central directory with changed offsets.
    if not UseXProgress then
      Report(zacItem, zprCentral, ZipLoadStr(PR_CentrlDir),
        EOC.CentralSize);
    for i := 0 to (EOC.TotalEntries - 1) do
    begin
      if FCancel then   // 1.77 Allow cancel
        raise EZipMaster.CreateResDisp( DS_Canceled, False);
      // Read a central header which can be span more than one disk.
      while FileRead(FInFileHandle, CEH, SizeOf(CEH)) <>
        SizeOf(CEH) do
      begin
        // Check if we are at the end of a input disk.
        if FileSeek64(FInFileHandle, Int64(0), 1) <>
          FileSeek64(FInFileHandle, Int64(0), 2) then
          raise EZipMaster.CreateResDisp( DS_CEHBadRead, True);
        // Well it seems we are at the end, so get a next disk.
        GetNewDisk(FDiskNr + 1);
      end;
      if CEH.HeaderSig <> CentralFileHeaderSig then
        raise EZipMaster.CreateResDisp( DS_CEHWrongSig, True);

      // Now the filename.
      ReadJoin(Buffer[0], CEH.FileNameLen, DS_CENameLen);

      // Save the first Central directory offset for use in EOC record.
      if i = 0 then
        EOC.CentralOffset := FileSeek64(FOutFileHandle, Int64(0), 1);

      // Change the central header info with our saved information.
      k := MDZD.IndexOf(@Buffer[0], CEH.FileNameLen); // RP 2010-04-24
//      k := MDZD.IndexOf(MakeString(@Buffer[0], CEH.FileNameLen));
      MDZDp := MDZD[k];
      CEH.RelOffLocal := MDZDp.RelOffLocal;
      CEH.DiskStart := 0;

      // Write this changed central header to disk
      // and make sure it fit's on one and the same disk.
      WriteJoin(CEH, SizeOf(CEH), DS_CEHBadWrite);

      // Write to destination the central filename and the extra field.
      WriteJoin(Buffer[0], CEH.FileNameLen, DS_CEHBadWrite);

      // And the extra field
      RWJoinData(Buffer[0], CEH.ExtraLen, DS_CEExtraLen);

      // And the file comment.
      RWJoinData(Buffer[0], CEH.FileComLen, DS_CECommentLen);
    end;

    // Write the changed EndOfCentral directory record.
    EOC.CentralDiskNo := 0;
    EOC.ThisDiskNo := 0;
    WriteJoin(EOC, SizeOf(EOC), DS_EOCBadWrite);

    // Skip past the original EOC to get to the ZipComment if present. v1.52M
    if (FileSeek64(FInFileHandle, Int64(SizeOf(EOC)), 1) = -1) then
      raise EZipMaster.CreateResDisp( DS_FailedSeek, True);

    // And finally the archive comment
    RWJoinData(Buffer[0], EOC.ZipCommentLen, DS_EOArchComLen);
  except
    on ers: EZipMaster do
      // All ReadSpan specific errors.
    begin
      ShowExceptionError(ers);
      Result := -7;
    end;
    on EOutOfMemory do
      // All memory allocation errors.
    begin
      ShowZipMessage(GE_NoMem, '');
      Result := -8;
    end;
    on E: Exception do
    begin
      // The remaining errors, should not occur.
      ShowZipMessage(DS_ErrorUnknown, E.Message);
      Result := -9;
    end;
  end;

  Buffer := Nil;
  // Give final progress info at the end.
  if BatchStarted then
    Report(zacEndOfBatch, 0, '', 0);

  if Assigned(MDZD) then
    FreeAndNil(MDZD);

  File_Close(FInFileHandle);
  if FOutFileHandle > 0 then                 
  begin
    FileSetDate(FOutFileHandle, FDateStamp);
    File_Close(FOutFileHandle);
    if Result <> 0 then
      // An error somewhere, OutFile is not reliable.
    begin
      SysUtils.DeleteFile(OutFilePath);
      OutFilePath := '';
    end;
  end;

  fUnzBusy := False;
  StopWaitCursor;
end;
{$ENDIF}

(*? TZMWorker.RecreateMVArchive
1.79 8 Dec 2004 RA New function to recreate a multi volume archive
*)
procedure TZMWorker.RecreateMVArchive(TmpZipName: String; Recreate: Boolean);
{$IFNDEF NO_SPAN}     
var
  EOC: ZipEndOfCentral;
  tmpStatusDisk: TStatusDiskEvent;
  slave: TZipSFX;
  tmpMessage: TMessageEvent;  
  Tmp, Tmp2, MsgStr: String;
  Res: Integer;
  SFXFileHandle: Integer;
{$ENDIF}
begin
{$IFDEF NO_SPAN}
  ShowZipMessage(DL_NoDelOnSpan, ''); //function not allowed in spanned archive
  exit;
{$ELSE}
  if Recreate then
  begin
    try
      GetNewDisk(0); // ask to enter the first disk again
    except
      on E: Exception do
      begin
        SysUtils.DeleteFile(TmpZipName); // delete the temp file
        raise;  // throw last exception again
      end;
    end;
    File_Close(FInFileHandle); // was opened by getnewdisk
  end;

  if UpperCase(ExtractFileExt(FZipFileName)) = '.EXE' then
  begin
    slave := GetSFXSlave;
    // create an header first to now its size
    if FTempDir <> '' then
      Tmp := DelimitPath(FTempDir, True) + ExtractFileName(FZipFileName)
    else
      Tmp := ExtractFileName(FZipFileName);
    // check if zip file with same name exists ask to delete
    // a zip file with same name will interfere with GetLastVolume
    Tmp2 := ChangeFileExt(Tmp, '.zip');
    if FileExists(Tmp2{ChangeFileExt(Tmp, '.zip')}) then
    begin
      MsgStr := ZipFmtLoadStr(DS_AskDeleteFile, [Tmp2{ChangeFileExt(Tmp, '.zip')}]);
      FZipDiskStatus := FZipDiskStatus + [zdsSameFileName];
      tmpStatusDisk := Events.OnStatusDisk;
      if assigned(tmpStatusDisk) then //1.77
      begin
        FZipDiskAction := zdaOk;          // The default action
        tmpStatusDisk(Master, FDiskNr, Tmp2{FOutFileName}, FZipDiskStatus,
          FZipDiskAction);
        if FZipDiskAction = zdaYesToAll then
          FZipDiskAction := zdaOk;
        if FZipDiskAction = zdaOk then
          Res := idYes
        else
          Res := idNo;
      end
      else
        Res := ZipMessageDlgEx(ZipLoadStr(FM_Confirm), MsgStr, 
          zmtWarning + DHC_WrtSpnDel, [mbYes, mbNo]);
      if (Res = 0) then  // report the problem
        raise EZipMaster.CreateResDisp( DS_NoMem, True);
      if (Res = idNo) then   // not allowed then we cannot make the sfx
        raise EZipMaster.CreateResDisp( DS_NoOutFile, True);
      if (Res = idYes) then
        SysUtils.DeleteFile(Tmp2{FOutFileName});   // if it exists delete
    end;
    with slave do
    begin
      SourceFile := TmpZipName;
      TargetFile := Tmp;
      Options := Options + [soDetached]; // to make it spanned
    end;
    try
      Slave.Convert;   // create the detached header
      // now open it to determine its length
      SFXFileHandle := FileOpen(Tmp, fmShareDenyWrite or fmOpenRead);
      if SFXFileHandle = -1 then
        raise EZipMaster.CreateResDisp(DS_FileOpen, True);
      FFreeOnDisk1 := FileSeek(SFXFileHandle, 0, 2);
      if FFreeOnDisk = -1 then
      begin
        FFreeOnDisk := 0;
        raise EZipMaster.CreateResDisp( DS_FailedSeek, True);
      end;
      File_Close(SFXFileHandle);
      SysUtils.DeleteFile(Tmp);
      // now create the spanned archive
      // write the temp zipfile to the right target:
      Tmp := ChangeFileExt(FZipFileName, '.zip'); // name of the zip files
      if WriteSpan(TmpZipName, Tmp, True) <> 0 then
        fSuccessCnt := 0                 // error occurred during write span
      else  // re-create the detached header with correct values
      begin
        GetLastVolume(Tmp, EOC, False);
        File_Close(FInFileHandle);
        // create the corect header on hard disc and copy later
        if FTempDir <> '' then
          Tmp := DelimitPath(FTempDir, True) + ExtractFileName(FZipFileName)
        else
          Tmp := ExtractFileName(FZipFileName);
        Slave.SourceFile := FInFileName;  // name of last part
        Slave.TargetFile := Tmp;
        Slave.Convert;
        // now ask for the first disk and copy the header
        FDrive := ExtractFileDrive(ExpandFileName(FZipFileName)) + '\';
        GetNewDisk(0);
        File_Close(FInFileHandle); // was opened by getnewdisk
        if not IsSameFile(Tmp, FZipFileName) then
        begin
          Res := Copy_File(Tmp, FZipFileName);
          if Res < 0 then
            raise EZipMaster.CreateResDisp( CF_SFXCopyError, True);
          SysUtils.DeleteFile(Tmp);
        end;
        FZipFileName := Tmp;
      end;
    except
      on E: Exception do
      begin
        if FUnattended = False then
          ZipMessageDlg(E.Message, DHC_ExSFX2EXE);
        tmpMessage := Events.OnMessage;
        if Assigned(tmpMessage) then
          tmpMessage(Master, 0, E.Message);
        FSuccessCnt := 0;
      end;
    end;
    SysUtils.DeleteFile(TmpZipName); // delete the original archive
  end
  else
  begin
    if not Recreate then
      FNumbering := znsNone; // use spanoptions
    if WriteSpan(TmpZipName, FZipFileName, True) <> 0 then
      FSuccessCnt := 0;
    SysUtils.DeleteFile(TmpZipName);
  end;
{$ENDIF}
end;

(*? TZMWorker.RejoinMVArchive
1.79 8 Dec 2004 RA New function to rejoin a multi volume archive
returns 0 if OK else FErrCode or ReadSpan errors
*)
function TZMWorker.RejoinMVArchive(var TmpZipName: String;
  Rejoin: Boolean): Integer;   
{$IFNDEF NO_SPAN}
var
  drt, Attrs: Integer;
  tmpMessage: tMessageEvent;
{$ENDIF}
begin
{$IFDEF NO_SPAN}
  ShowZipMessage(DL_NoDelOnSpan, ''); //function not allowed in spanned archive
  Result := FErrCode;
  exit;
{$ELSE}
  TmpZipName := MakeTempFileName('', '');
  if Verbose then
  begin
    tmpMessage := Events.OnMessage;
    if Assigned(tmpMessage) then
      tmpMessage(Master, 0, ZipFmtLoadStr(GE_TempZip, [TmpZipName]));
  end;

  if Rejoin then
  begin
    // test if output van eventually be produced
    FDrive := ExtractFileDrive(ExpandFileName(FZipFileName)) + '\';
    drt := GetDriveType(Pchar(FDrive));
    // we can't re-write on a CD-ROM

    if (drt = DRIVE_CDROM) then
    begin
      Attrs := FileGetAttr(FZipFileName);
      if Attrs and faReadOnly <> 0 then
      begin
        ShowZipFmtMessage(DS_NotChangeable, [FZipFileName]);
        Result := -7;
        exit;
      end;
    end;
    // rebuild a temp archive
    if FileExists(FZipFileName)
      and ((QueryZip(FZipFileName) and DetachMask) = 145) then
      FInFileName := ChangeFileExt(FZipFileName, '.zip') // detached sfx
    else
      FInFileName := FZipFileName;
    if ReadSpan(FInFileName, TmpZipName, True) < 0 then
    begin
      DoDllUnload;//(false);
      Result := FErrCode;
      exit;
    end;
    FAnswerAll := FAnswerAll + [zaaYesOvrWrt];
  end;
  Result := 0;
{$ENDIF}
end;
          
//  return true if contains chars  >#126
function StrHasExt(const astr: string): Boolean; {$IFDEF UNICODE} overload; {$ENDIF}
var
  i: integer;
begin
  Result := false;
  for i := 1 to Length(astr) do
    if astr[i] > #126 then
    begin
      Result := True;
      break;
    end;
end;

{$IFDEF UNICODE}
function StrHasExt(const astr: AnsiString): Boolean; overload;
var
  i: integer;
begin
  Result := false;
  for i := 1 to Length(astr) do
    if astr[i] > #126 then
    begin
      Result := True;
      break;
    end;
end;
{$ENDIF}

// return true if filename is obviously invalid
function NameIsBad(const astr: string): Boolean;
var
  i: integer;
begin
  Result := (astr = '') or (astr[1] = ' ') or (astr[1] = '\') or
    (Length(astr) > MAX_PATH);
  if not Result then
    for i := 1 to Length(astr) do
{$IFDEF UNICODE}
      if CharInSet(astr[i], [#0..#31, ':', '<', '>', '|', '*', '?'])  then
{$ELSE}
      if astr[i] in [#0..#31, ':', '<', '>', '|', '*', '?']  then
{$ENDIF}
      begin
        Result := True;
        break;
      end;
  if not Result then
    Result := (AnsiPos('..', astr) > 0) or
      (AnsiPos('\ ', astr) > 0) or (AnsiPos(' \', astr) > 0);
end;


(*? TZMWorker.Rename
1.79.19.09 7 MAR 09 RP expand rename to comment too
1.79.10.07 17 DEC 08 RP control match/replace
1.79.08.02 19 AUG 07 RP don't allow date/time change for encoded files
1.79 3 January 2006 RP handle files > 2G
1.79 22 Dec 2004 RA changed exception handling during opening
1.79 8 Dec 2004 RA Allow Rename in MV archive
1.77 20 August 2004 RA progress adjusted
1.77 18 Aug 2004 RP use dynamic buffer
1.75 18 February 2004 RP allow >2G
1.73.3.2 11 October 2003 RP changed comment variable
1.73.2.1 23 August 2003 RP remove use of undefined variable 'name'
1.73  8 August 2003 RA clear outFileHandle
1.73 16 July 2003 RP use SetSlash + ConvertOEM
1.73 14 July 2003 RA convertion/re-convertion of filenames with OEM chars
1.73 13 July 2003 RA test on date/time in RenRec + test for wildcards
// Function to read a Zip archive and change one or more file specifications.
// Source and Destination should be of the same type. (path or file)
// If NewDateTime is 0 then no change is made in the date/time fields.
// Return values:
// 0            All Ok.
// -7           Rename errors. See ZipMsgXX.rc
// -8           Memory allocation error.
// -9           General unknown Rename error.
// -10          Dest should also be a filename.
*)
function TZMWorker.Rename(RenameList: TList; DateTime: Integer; How:
    TZMRenameOpts = htrDefault): Integer;
var
  EOC:  ZipEndOfCentral;
  CEH:  ZipCentralHeader;
  LOH:  ZipLocalHeader;
  HeaderName: String;
  MsgStr: String;
  OutFilePath: String;
  Fname: String;
  FnameA: AnsiString;
  Buffer: array of AnsiChar;
  HasExt: Boolean;
  i, k, m: Integer;
  len: Word;
  TotalBytesToRead: Cardinal;
  TotalBytesWrite: Cardinal;
  RenRec: pZipRenameRec;
  MDZD: TZMDataList;
  MDZDp: TMDZipData;//pMZipData;
  OldComLen: WORD;          
  RenSource: string;
{$IFNDEF NO_SPAN}
  TmPZipName: String;
  RenOutFileHandle: Integer;
{$ENDIF}
begin
  Result := 0;
  TotalBytesToRead := 0;
  fZipBusy := True;
  FShowProgress := zspNone;

  SetLength(Buffer, BufSize);
  FInFileName := FZipFileName;
  FInFileHandle := -1;
  FOutFileHandle := -1;
  MDZD := Nil;

  StartWaitCursor;

  // If we only have a source path make sure the destination is also a path.
  for i := 0 to RenameList.Count - 1 do
  begin
    RenRec := RenameList.Items[i];
    RenRec^.Source := SetSlash(RenRec^.Source, psdExternal);
    RenRec^.Dest := SetSlash(RenRec^.Dest, psdExternal);
    //**new if dest is empty make same as source (no change)
    if RenRec^.Dest = '' then
      RenRec^.Dest := RenRec^.Source;
    if (AnsiPos('*', RenRec^.Source) > 0) or
      (AnsiPos('?', RenRec^.Source) > 0) or
      NameIsBad(RenRec^.Dest) then
//      (AnsiPos('*', RenRec^.Dest) > 0) or
//      (AnsiPos('?', RenRec^.Dest) > 0) then
    begin
      ShowZipMessage(AD_InvalidName, '');   // no wildcards allowed
      StopWaitCursor;
      fZipBusy := False;
      Result := -7;                         // Rename error
      exit;
    end;
    if Length(ExtractFileName(RenRec^.Source)) = 0 then // Assume it's a path.
    begin                                   // Make sure destination is a path also.
      RenRec^.Dest := DelimitPath(ExtractFilePath(RenRec^.Dest), True);
      RenRec^.Source := DelimitPath(RenRec^.Source, True);
    end
    else
    if Length(ExtractFileName(RenRec^.Dest)) = 0 then
    begin
      StopWaitCursor;
      fZipBusy := False;
      Result := -10;  // Dest should also be a filename.
      Exit;
    end;
  end;
  try    
    CheckDestWritable(FZipFileName, false);
{$IFNDEF NO_SPAN}
    if FileExists(FZipFileName)
        and ((QueryZip(FZipFileName) and DetachMask) = 145) then
      FInFileName := ChangeFileExt(FZipFileName, '.zip')
    else
      FInFileName := FZipFileName;
    // Locate last of multi volume or last disk of spanned
    if GetLastVolume(FInFileName, EOC, False) = 1 then
      raise EZipMaster.CreateResDisp( DS_Canceled, False);
{$ELSE}
    FInFileName := FZipFileName;
    // Check the input file.
    if not FileExists(FZipFileName) then
      raise EZipMaster.CreateResDisp( GE_NoZipSpecified, True);
    // The following function will read the EOC and some other stuff:
    OpenEOC(EOC, True);
    File_Close(FInFileHandle);
    if FIsSpanned then
      raise EZipMaster.CreateResDisp( RN_NoRenOnSpan, True);
    //function not allowed in spanned archive
{$ENDIF}
  except
    on ers: EZipMaster do                   // All Rename specific errors.
    begin
      ShowExceptionError(ers);
      File_Close(FInFileHandle);
    end;
  end;
  if FInFileHandle = -1 then // was problem
  begin
    StopWaitCursor;
    fZipBusy := False;
    Result := -7;
    exit;
  end;
  try
    // Make a temporary filename like: C:\...\zipxxxx.zip
    OutFilePath := MakeTempFileName('', '');
    if OutFilePath = '' then
      raise EZipMaster.CreateResDisp( DS_NoTempFile, True);

    // Create the output file.
    FOutFileHandle := FileCreate(OutFilePath);
    if FOutFileHandle = -1 then
      raise EZipMaster.CreateResDisp( DS_NoOutFile, True);

    // Get the date-time stamp and save for later.
    FDateStamp := FileGetDate(FInFileHandle);

    // Now we now the number of zipped entries in the zip archive
{$IFDEF NO_SPAN}
    FTotalDisks := EOC.ThisDiskNo;
    if EOC.ThisDiskNo <> 0 then
      raise EZipMaster.CreateResDisp( RN_NoRenOnSpan, True);
{$ELSE}
    if FIsSpanned then
    begin
      RenOutFileHandle := FOutFileHandle; // save handle
      File_Close(FInFileHandle); // was opened by OpenEOC
      if RejoinMVArchive(TmpZipName, True) <> 0 then
      begin
        File_Close(RenOutFileHandle);
        SysUtils.DeleteFile(OutFilePath);
        if FileExists(TmpZipName) then
          SysUtils.DeleteFile(TmpZipName);
        Buffer := Nil;
        StopWaitCursor;
        FZipBusy := False;
        Result := -7;
        exit;
      end;
      //open the temp file and read the EOC
      FInFileName := TmpZipName; // use the re-joined file as zipfile
      OpenEOC(EOC, True);
      FOutFileHandle := RenOutFileHandle; // restore handle
    end;
{$ENDIF}

    // Go to the start of the input file.
    if FileSeek64(FInFileHandle, Int64(0), 0) = -1 then
      raise EZipMaster.CreateResDisp( DS_FailedSeek, True);

    // Write the SFX header if present.
    if FSFXOffset = 4 then
      FSFXOffset := 0; // this is not an SFX but the ExtLocSig
    if CopyBuffer(FInFileHandle, FOutFileHandle, FSFXOffset) <> 0 then
      raise EZipMaster.CreateResDisp( RN_ZipSFXData, True);

    // Go to the start of the Central directory.
    if FileSeek64(FInFileHandle, Int64(EOC.CentralOffset), 0) = -1 then
      raise EZipMaster.CreateResDisp( DS_FailedSeek, True);

    MDZD := TZMDataList.Create(EOC.TotalEntries);

    // Read for every entry: The central header and save information for later use.
    for i := 0 to (EOC.TotalEntries - 1) do
    begin
      // Read a central header.
      ReadJoin(CEH, SizeOf(CEH), DS_CEHBadRead);

      if CEH.HeaderSig <> CentralFileHeaderSig then
        raise EZipMaster.CreateResDisp( DS_CEHWrongSig, True);

      // Now the filename.
      SetLength(FNameA, CEH.FileNameLen);
      ReadJoin(FNameA[1], CEH.FileNameLen, DS_CENameLen);
      FName := String(FNameA);
      // Save the file name info in the MDZD structure.
      MDZDp := MDZD[i];
//      MDZDp^.FileNameLen := CEH.FileNameLen;
      // convert OEM char set in original file else we don't find the file
      FVersionMadeBy1 := CEH.VersionMadeBy1;
      FVersionMadeBy0 := CEH.VersionMadeBy0;
      Fname := ConvertOEM(Fname, cpdOEM2ISO);
//      MDZDSetName(MDZDp, FName);
      MDZDp.FileName := Fname;
//      StrLCopy(MDZDp^.FileName, Pchar(Fname), 253);
      MDZDp.VerMade := (FVersionMadeBy1 shl 8) or FVersionMadeBy0;
      //DiskStart is not used in this function and we need FHostNum later
//      MDZDp^.DiskStart := (FVersionMadeBy1 shl 8) or FVersionMadeBy0;
      MDZDp.RelOffLocal := CEH.RelOffLocal;
      MDZDp.DateTime := DateTime;
      MDZDp.ComprSize := CEH.ComprSize;
      // RP may not be valid in local header

      // We need the total number of bytes we are going to read for the progress event.
      TotalBytesToRead := TotalBytesToRead + {Integer(}CEH.ComprSize +
        CEH.FileNameLen + CEH.ExtraLen;//);

      // Seek past the extra field and the file comment.
      if FileSeek64(FInFileHandle, Int64(CEH.ExtraLen + CEH.FileComLen),
        1) = -1 then
        raise EZipMaster.CreateResDisp( DS_FailedSeek, True);
    end;

    FShowProgress := zspFull;
    Report(zacCount, 0, '', EOC.TotalEntries);
    Report(zacSize, 0, '', TotalBytesToRead);

    // Read for every zipped entry: The local header, variable data, fixed data
    // and if present the Data descriptor area.
    for i := 0 to (EOC.TotalEntries - 1) do
    begin
      // Seek to the first entry.
      MDZDp := MDZD[i];
      FileSeek64(FInFileHandle, MDZDp.RelOffLocal, 0);

      // First the local header.
      ReadJoin(LOH, SizeOf(LOH), DS_LOHBadRead);
      if LOH.HeaderSig <> LocalFileHeaderSig then
        raise EZipMaster.CreateResDisp( DS_LOHWrongSig, True);

      // Now the filename.
      ReadJoin(Buffer[0], LOH.FileNameLen, DS_LONameLen);

      // Set message info on the start of this new fileread because we still have the old filename.
//      MsgStr := ZipLoadStr(RN_ProcessFile) + MDZDGetName(MDZDp);
      MsgStr := ZipLoadStr(RN_ProcessFile) + MDZDp.FileName;

      // Calculate the bytes we are going to write; we 'forget' the difference
      // between the old and new filespecification.
      TotalBytesWrite := LOH.FileNameLen + LOH.ExtraLen + MDZDp.ComprSize;
      //LOH.ComprSize;

      // Check if the original path and/or filename needs to be changed.
//      HeaderName := SetSlash(MDZDGetName(MDZDp), psdExternal);
      HeaderName := SetSlash(MDZDp.FileName, psdExternal);
      for m := 0 to RenameList.Count - 1 do
      begin
        RenRec := RenameList.Items[m];
//        k := Pos(UpperCase(RenRec^.Source), UpperCase(HeaderName));
        RenSource := RenRec^.Source;
        if how = htrFull then
        begin    
          if CompareText(RenSource, HeaderName) = 0 then
            k := 1
          else
            k := 0;
        end
        else
          k := Pos(UpperCase(RenSource), UpperCase(HeaderName));
        if k <> 0 then
        begin
//          System.Delete(HeaderName, k, Length(RenRec^.Source));
          System.Delete(HeaderName, k, Length(RenSource));
          Insert(RenRec^.Dest, HeaderName, k);
          LOH.FileNameLen := Length(HeaderName);
          for k := 1 to Length(HeaderName) do
            if HeaderName[k] = '\' then
              HeaderName[k] := '/';
          MsgStr := MsgStr + ZipLoadStr(RN_RenameTo) + HeaderName;
          //allow OEM char sets in Rename
          //**new convert the comment
          MDZDp.NComment := '';
          if RenRec^.Comment <> '' then
          begin
            if (Length(RenRec^.Comment) = 1) and (RenRec^.Comment[1] = #0) then
              MDZDp.NComment := #0//RenRec^.Comment
            else
              MDZDp.NComment := AnsiString(ConvertOEM(RenRec^.Comment, cpdISO2OEM));
//            MsgStr := MsgStr + '  ["' +
          end;
          HasExt := StrHasExt(HeaderName) or StrHasExt(MDZDp.NComment);
          //we replaced the filename/comment look if we need to reconvert it
          if (MDZDp.VerMade and $FF) <= 22 then
          begin
            if HasExt then
              MDZDp.VerMade := $0B16 // NTFS 22
            else
              MDZDp.VerMade := 20;   // DOS 20
            FVersionMadeBy1 := (MDZDp.VerMade and $FF00) shl 8;
            FVersionMadeBy0 := (MDZDp.VerMade and $FF);
          end
          else
          begin
            FVersionMadeBy1 := (MDZDp.VerMade and $FF00) shl 8;
            FVersionMadeBy0 := (MDZDp.VerMade and $FF);
          end;
//          FVersionMadeBy1 := (MDZDp^.DiskStart and $FF00) shl 8;
//          FVersionMadeBy0 := (MDZDp^.DiskStart and $FF);
          HeaderName := ConvertOEM(HeaderName, cpdISO2OEM);
//          MDZDSetName(MDZDp, HeaderName);//, Length(HeaderName) {+ 1});
          MDZDp.FileName := HeaderName;
//          StrPLCopy(MDZDp^.FileName, HeaderName, Length(HeaderName) + 1);
//          MDZDp^.FileNameLen := Length(HeaderName);
//          FNameA := AnsiString(HeaderName);
//          LOH.FileNameLen := MDZDp^.FileNameLen;//Length(FNameA);

          // Change Date and Time if needed.
          if (RenRec^.DateTime <> 0) and ((LOH.Flag and Word($1)) = 0) then
            try
              // test if valid date/time will throw error if not
              FileDateToDateTime(RenRec^.DateTime);
              MDZDp.DateTime := RenRec^.DateTime;
            except
//              ShowZipMessage(RN_InvalidDateTime, MDZDGetName(MDZDp));
              ShowZipMessage(RN_InvalidDateTime, MDZDp.FileName);
            end;

          if How <> htrDefault then
            Break;  // only allow single change
        end;
      end;
      Report(zacMessage, 0, MsgStr, 0);

      // Change Date and/or Time if needed - if not encoded.
      if (MDZDp.DateTime <> 0) and ((LOH.Flag and Word($1)) = 0) then
      begin
        LOH.ModifDate := HIWORD(MDZDp.DateTime);
        LOH.ModifTime := LOWORD(MDZDp.DateTime);
      end;
      // Change info for later while writing the central dir.
      MDZDp.RelOffLocal := FileSeek64(FOutFileHandle, Int64(0), 1);

//      Report(zacItem, 0, SetSlash(MDZDGetName(MDZDp), psdExternal),
      Report(zacItem, 0, SetSlash(MDZDp.FileName, psdExternal),
        TotalBytesWrite);

//      LOH.FileNameLen := MDZDp^.FileNameLen; // may have changed
      LOH.FileNameLen := Length(MDZDp.FileNameA); // may have changed

      // Write the local header to the destination.
      WriteJoin(LOH, SizeOf(LOH), DS_LOHBadWrite);

      // Write the filename.                                  
//      WriteJoin(MDZDp^.FileNameA, LOH.FileNameLen, DS_LOHBadWrite);
      WriteJoin(PAnsiChar(MDZDp.FileNameA)^, LOH.FileNameLen, DS_LOHBadWrite);
//      WriteJoin(MDZDp^.FileName, LOH.FileNameLen, DS_LOHBadWrite);
//      WriteJoin((@FNameA[1])^, LOH.FileNameLen, DS_LOHBadWrite);

      // And the extra field
      if (LOH.ExtraLen <> 0) and
          (CopyBuffer(FInFileHandle, FOutFileHandle, LOH.ExtraLen) <> 0) then
        raise EZipMaster.CreateResDisp( DS_LOExtraLen, True);

      // Read and write Zipped data
      if CopyBuffer(FInFileHandle, FOutFileHandle,
        MDZDp.ComprSize) <> 0 then
        raise EZipMaster.CreateResDisp( DS_ZipData, True);

      // Read DataDescriptor if present.
      if (LOH.Flag and Word($0008)) = 8 then
        if CopyBuffer(FInFileHandle, FOutFileHandle,
          SizeOf(ZipDataDescriptor)) <> 0 then
          raise EZipMaster.CreateResDisp( DS_DataDesc, True);
    end;                                    // Now we have written all entries.

    // Now write the central directory with possibly changed offsets and filename(s).
    FShowProgress := zspNone;
    for i := 0 to (EOC.TotalEntries - 1) do
    begin
      MDZDp := MDZD[i];
      // Read a central header which can be span more than one disk.
      ReadJoin(CEH, SizeOf(CEH), DS_CEHBadRead);
      if CEH.HeaderSig <> CentralFileHeaderSig then
        raise EZipMaster.CreateResDisp( DS_CEHWrongSig, True);

      // Change Date and/or Time if needed.
      if (MDZDp.DateTime <> 0) and ((CEH.Flag and Word($1)) = 0) then
      begin
        CEH.ModifDate := HIWORD(MDZDp.DateTime);
        CEH.ModifTime := LOWORD(MDZDp.DateTime);
      end;

      // Now the filename.
      ReadJoin(Buffer[0], CEH.FileNameLen, DS_CENameLen);

      // Save the first Central directory offset for use in EOC record.
      if i = 0 then
        EOC.CentralOffset := Cardinal(FileSeek64(FOutFileHandle, Int64(0), 1));

      // get Ansi filename
//      FNameA := AnsiString(String(MDZDp^.FileName));
      // Change the central header info with our saved information.
      CEH.RelOffLocal := MDZDp.RelOffLocal;
      CEH.DiskStart := 0;
      len := WORD(Length(MDZDp.FileNameA));
      EOC.CentralSize := EOC.CentralSize - CEH.FileNameLen + len;
//        MDZDp^.FileNameLen;
      CEH.FileNameLen := len; //MDZDp^.FileNameLen;
//      EOC.CentralSize := (EOC.CentralSize - CEH.FileNameLen) + Word(Length(FNameA));
//      CEH.FileNameLen := Length(FNameA);
      //**new set the comment
      OldComLen := CEH.FileComLen;
      if MDZDp.NComment <> '' then
      begin
        if (Length(MDZDp.NComment) = 1) and (MDZDp.NComment[1] = #0) then
          CEH.FileComLen := 0    // none
        else
          CEH.FileComLen := Length(MDZDp.NComment) and $FF; // limit 255 chars
        EOC.CentralSize := EOC.CentralSize - OldComLen + CEH.FileComLen;
      end;

      // Write this changed central header to disk
      WriteJoin(CEH, SizeOf(CEH), DS_CEHBadWrite);

      // Write to destination the central filename and the extra field.
//      WriteJoin(MDZDp^.FileNameA, CEH.FileNameLen, DS_CEHBadWrite);
      WriteJoin(PAnsiChar(MDZDp.FileNameA)^, CEH.FileNameLen, DS_CEHBadWrite);
//      WriteJoin((@FName[1])^, CEH.FileNameLen, DS_CEHBadWrite);

      // And the extra field
      if (CEH.ExtraLen <> 0) and
          (CopyBuffer(FInFileHandle, FOutFileHandle, CEH.ExtraLen) <> 0) then
        raise EZipMaster.CreateResDisp( DS_CEExtraLen, True);

//      // And the file comment.
//      if (CEH.FileComLen <> 0) and
//          (CopyBuffer(FInFileHandle, FOutFileHandle, CEH.FileComLen) <> 0) then
      // And the file comment.
      if MDZDp.NComment <> '' then
      begin
        if OldComLen > 0 then
        begin
          // read and discard the old comment
          if OldComLen > BufSize then
            SetLength(Buffer, OldComLen);
          ReadJoin(Buffer[0], OldComLen, DS_CECommentLen);
        end;
        if CEH.FileComLen > 0 then
          WriteJoin(PAnsiChar(MDZDp.NComment)^, CEH.FileComLen, DS_CEHBadWrite);
      end
      else
      if (OldComLen <> 0) and
           (CopyBuffer(FInFileHandle, FOutFileHandle, OldComLen) <> 0) then
        raise EZipMaster.CreateResDisp( DS_CECommentLen, True);
    end;
    // Write the changed EndOfCentral directory record.
    EOC.CentralDiskNo := 0;
    EOC.ThisDiskNo := 0;
    WriteJoin(EOC, SizeOf(EOC), DS_EOCBadWrite);

    // And finally the archive comment
    { ==================== Changed by Jin Turner ===================}
//    if (FEOCComment <> '') and
//      (FileWrite(FOutFileHandle, Pchar(FEOCComment)^,
//      Length(FEOCComment)) < 0) then
//      raise EZipMaster.CreateResDisp( DS_EOArchComLen, True);
    if (FEOCComment <> '') then
    begin
      FnameA := AnsiString(FEOCComment);
    if {(FEOCComment <> '') and}
      (FileWrite(FOutFileHandle, PAnsiChar(FNameA)^,
          Length(FEOCComment)) < 0) then
      raise EZipMaster.CreateResDisp( DS_EOArchComLen, True);
    end;
  except
    on ers: EZipMaster do                   // All Rename specific errors.
    begin
      ShowExceptionError(ers);
      Result := -7;
    end;
    on EOutOfMemory do                      // All memory allocation errors.
    begin
      ShowZipMessage(GE_NoMem, '');
      Result := -8;
    end;
    on E: Exception do
    begin
      // the error message of an unknown error is displayed ...
      ShowZipMessage(DS_ErrorUnknown, E.Message);
      Result := -9;
    end;
  end;
  if Assigned(MDZD) then
    FreeAndNil(MDZD);

  // Give final progress info at the end.
  Report(zacEndOfBatch, 0, '', 0);
  Buffer := Nil;

  //  if FInFileHandle <> -1 then
  File_Close(FInFileHandle);
  if FOutFileHandle <> -1 then
  begin
    FileSetDate(FOutFileHandle, FDateStamp);
    File_Close(FOutFileHandle);
    if Result <> 0 then
      // An error somewhere, OutFile is not reliable.
      SysUtils.DeleteFile(OutFilePath)
    else
    begin
      if IsSpanned then
      begin
{$IFNDEF NO_SPAN}
        try
          SysUtils.DeleteFile(TmpZipName); // remove the temporary input file
          FInFileName := ChangeFileExt(FZipFileName, '.zip');
          // in case of detached sfx
          if FNumbering = znsName then // have FInFilename  with a part number
            CreateMVFileNameEx(FInFileName, False, False);
          RecreateMVArchive(OutFilePath, True);
          // recreate the MV starting from the result
        except
          on ers: EZipMaster do
            // All Rename specific errors.
          begin
            ShowExceptionError(ers);
            Result := -7;
          end;
          on E: Exception do
          begin
            ShowZipMessage(DS_ErrorUnknown, E.Message);
            Result := -9;
          end;
        end;
{$ENDIF}
      end
      else
      begin
        EraseFile(FZipFileName, FHowToDelete = htdFinal);
        RenameFile(OutFilePath, FZipFileName);
        List;
      end;
    end;
  end;
  fZipBusy := False;
  StopWaitCursor;
end;

(*? TZMWorker.RWJoinData 
1.79 3 January 2006 RP copy > 2G
*)
{$IFNDEF NO_SPAN}
procedure TZMWorker.RWJoinData(var Buffer; ReadLen: Cardinal; DSErrIdent:
    Integer);
var
  ToRead, SizeR: Integer;
begin
  while ReadLen > 0 do
  begin
    ToRead := BufSize;
    if ReadLen < BufSize then
      ToRead := ReadLen;
    SizeR := FileRead(FInFileHandle, Buffer, ToRead);
    if SizeR <> ToRead then
    begin
      // Check if we are at the end of a input disk.
      if FileSeek64(FInFileHandle, 0, 1) <>
        FileSeek64(FInFileHandle, 0, 2) then
        raise EZipMaster.CreateResDisp( DSErrIdent, True);
      // It seems we are at the end, so get a next disk.
      GetNewDisk(FDiskNr + 1);
    end;
    if SizeR > 0 then
      // Fix by Scott Schmidt v1.52n
    begin
      WriteJoin(Buffer, SizeR, DSErrIdent);
      ReadLen := ReadLen - Cardinal(SizeR);
    end;
  end;
end;
{$ENDIF}

(*? TZMWorker.RWSplitData   
1.79 3 January 2006 RP copy > 2G
 // Read data from the input file with a maximum of 8192(BufSize) bytes per read
 // and write this to the output file.
 // In case of an error an Exception is raised and this will
 // be caught in WriteSpan.
*)
{$IFNDEF NO_SPAN}
procedure TZMWorker.RWSplitData(var Buffer; ReadLen: Cardinal; ZSErrVal:
    Integer);
var
  SizeR, ToRead: Cardinal;//Integer;
begin
  while ReadLen > 0 do
  begin
    ToRead := BufSize;
    if ReadLen < BufSize then
      ToRead := ReadLen;
    SizeR := FileRead(FInFileHandle, Buffer, ToRead);
    if SizeR <> ToRead then
      raise EZipMaster.CreateResDisp( ZSErrVal, True);
    WriteSplit(Buffer, SizeR, 0);
    Dec(ReadLen, SizeR);
  end;
end;
{$ENDIF}

(*? TZMWorker.SetActive
1.76
*)
procedure TZMWorker.SetActive(Value: Boolean);
begin
  if Active <> Value then
  begin
    FActive := Value;
    if FActive then
    begin                                   // do delayed action
      if zdiList in FDelaying then
        List;
      if zdiComment in FDelaying then
        SetZipComment(FZipComment);
    end;
    FDelaying := [];
  end;
end;

(*? TZMWorker.SetCancel
1.76 10 May 2004 remove AbortDlls
1.76 28 April 2004 add side effect of aborting dll when setting true
*)
procedure TZMWorker.SetCancel(Value: Boolean);
begin
  if Cancel <> Value then
    inherited;
end;

(*? TZMWorker.SetDeleteSwitches
*)
procedure TZMWorker.SetDeleteSwitches(zpParms: pZipParms);
{ override "add" behavior assumed by SetZipSwitches: }
begin
  with zpParms^ do
  begin
    fDeleteEntries := True;
    fGrow := False;
    fJunkDir := False;
    fMove := False;
    fFreshen := False;
    fUpdate := False;
    fRecurse := False;
    // bug fix per Angus Johnson
    fEncrypt := False;
    // you don't need the pwd to delete a file
  end;
end;

procedure TZMWorker.SetDirHashs(const Value: TZipDirHashList);
begin
  FDirHashs := Value;
end;

(*? TZMWorker.SetExtAddStoreSuffixes
*)
procedure TZMWorker.SetExtAddStoreSuffixes(Value: String);
var
  str: String;
  i:   Integer;
  c:   Char;
begin
  if Value <> '' then
  begin
    c := ':';
    i := 1;
    while i <= length(Value) do
    begin
      c := Value[i];
      if c <> '.' then
        str := str + '.';
      while (c <> ':') and (i <= length(Value)) do
      begin
        c := Value[i];
        if (c = ';') or (c = ':') or (c = ',') then
          c := ':';
        str := str + c;
        Inc(i);
      end;
    end;
    if c <> ':' then
      str := str + ':';
    fAddStoreSuffixes := fAddStoreSuffixes + [assEXT];
    fExtAddStoreSuffixes := Lowercase(str);
  end
  else
  begin
    fAddStoreSuffixes := fAddStoreSuffixes - [assEXT];
    fExtAddStoreSuffixes := '';
  end;
end;

(*? TZMWorker.SetFilename
1.76 27 April 2004 _List controlled by 'Inactive'
*)
procedure TZMWorker.SetFilename(Value: String);
begin
  FZipFileName := Value;
  List; { automatically build a new TLIST of contents in "ZipContents" }
end;

(*? TZMWorker.SetPasswordReqCount
*)
procedure TZMWorker.SetPasswordReqCount(Value: Longword);
begin
  if Value <> FPasswordReqCount then
  begin
    if Value > 15 then
      Value := 15;
    if Value < 1 then
      Value := 1;
    FPasswordReqCount := Value;
  end;
end;

(*? TZMWorker.SetUnZipSwitches
*)
procedure TZMWorker.SetUnZipSwitches(const NameOfZipFile: String; uzParms:
    pUnZipParms);
begin
  with uzParms^ do
  begin
    fVersion := DELZIPVERSION;   // version we expect the DLL to be
    fCaller := Self;   // point to our VCL instance; returned in Report

    fQuiet := True;
    { we'll report errors upon notification in our Report }
    { So, we don't want the DLL to issue error dialogs }

    ZCallbackFunc := ZCallback;
    // pass addr of function to be called from DLL

    fTraceEnabled := Trace;
    fVerboseEnabled := Verbose;
    if (fTraceEnabled and not fVerboseEnabled) then
      fVerboseEnabled := True;
    { if tracing, we want verbose also }

    if FUnattended then
      fHandle := 0
    else
      fHandle := Handle;
    // used for dialogs (like the pwd dialogs)

    fQuiet := True;
    { no DLL error reporting }
    fComments := False;
    { zipfile comments - not supported }
    fConvert := False;
    { ascii/EBCDIC conversion - not supported }
    fWantedCodePage := Ord(FCodePage);

    fDirectories := ExtrDirNames in fExtrOptions;
    fOverwrite := ExtrOverWrite in fExtrOptions;
    fFreshen := ExtrFreshen in fExtrOptions;
    fUpdate := ExtrUpdate in fExtrOptions;
    if fFreshen and fUpdate then
      fFreshen := False;
    { Update has precedence over freshen }

    fTest := ExtrTest in fExtrOptions;
    { allocate room for null terminated string }
    pZipFN := MakeStrP(NameOfZipFile);
//    pZipFN := StrAlloc(Length(NameOfZipFile) + 1);
//    StrPLCopy(pZipFN, NameOfZipFile, Length(NameOfZipFile) + 1);
    { name of zip file }

    uzParms.fPwdReqCount := FPasswordReqCount;
    { We have to be carefull doing an unattended Extract when a password is needed
           for some file in the archive. We set it to an unlikely password, this way
     encrypted files won't be extracted.
             From verion 1.60 and up the event OnPasswordError is called in this case. }

    pZipPassword := MakeStrP(fPassword);
//    pZipPassword := StrAlloc(Length(FPassword) + 1);
    // Allocate room for null terminated string.
//    StrPLCopy(pZipPassword, FPassword, Length(FPassword) + 1);
    // Password for encryption/decryption.
  end;                                      { end with }
end;

(*? TZMWorker.SetZipComment
1.77 4 Oct 2004 RA don't open if no file exists
1.76 27 April 2004 test Active
1.75 18 February 2004 allow >2G
1.73.3.2 11 Oct 2003 RP allow preset comment
1.73 ( 21 July 2003) RA user Get Lastvolume to add ZipComment to split archive
*)
procedure TZMWorker.SetZipComment(zComment: String);
var
  EOC: ZipEndOfCentral;
  len: Integer;
  CommentBuf: AnsiString;
  Fatal: Boolean;
  FileOfs: Int64;
begin
  FInFileHandle := -1;
  Fatal := False;
  if not Active then
  begin
    FDelaying := FDelaying + [zdiComment];
    FZipComment := zComment;
    exit;
  end;
  try
    if Length(ZipFileName) <> 0 then        // RP 1.73
{$IFNDEF NO_SPAN}
      GetLastVolume(ZipFileName, EOC, True);  // will read existing comment
{$ELSE}
    if FileExists(ZipFileName) then
      OpenEOC(EOC, True);
{$ENDIF}
    FZipComment := zComment;  // FInFileName opened by OpenEOC() only for Read
    if (FInFileHandle <> -1) then           // file exists
    begin
      File_Close(FInFileHandle);
      // must reopen for read/write
      if Length(zComment) > 0 then
        CommentBuf := AnsiString(ConvertOEM(zComment, cpdISO2OEM));
//      if CommentBuf = AnsiString(FEOCComment) then
//        exit;                               // same - nothing to do
      if CommentBuf <> AnsiString(FEOCComment) then
      begin                               // something to do
        len := Length(CommentBuf);
        if (Int64(FZipEOC) + sizeof(EOC) + len) > $FFFFFFFE then
          raise EZipMaster.CreateResDisp(LI_FileTooBig, True);
        FInFileHandle := FileOpen(FInFileName, fmShareDenyWrite or
          fmOpenReadWrite);
        if FInFileHandle = -1 then            // RP 1.60
          raise EZipMaster.CreateResDisp( DS_FileOpen, True);
        FileOfs := FZipEOC;                   // convert 64 bit
        if FileSeek64(FInFileHandle, FileOfs, 0) = -1 then
          raise EZipMaster.CreateResDisp( DS_FailedSeek, True);
        if (FileRead(FInFileHandle, EOC, SizeOf(EOC)) <> SizeOf(EOC)) or
          (EOC.HeaderSig <> EndCentralDirSig) then
          raise EZipMaster.CreateResDisp( DS_EOCBadRead, True);
        EOC.ZipCommentLen := len;
        FileOfs := -SizeOf(EOC);
        if FileSeek64(FInFileHandle, FileOfs, 1) = -1 then
          raise EZipMaster.CreateResDisp( DS_FailedSeek, True);
        Fatal := True;
        if FileWrite(FInFileHandle, EOC, SizeOf(EOC)) <>
          SizeOf(EOC) then
          raise EZipMaster.CreateResDisp( DS_EOCBadWrite, True);
        if (len > 0) and
          (FileWrite(FInFileHandle, PAnsiChar(CommentBuf)^, len) <> len) then
          raise EZipMaster.CreateResDisp( DS_NoWrite, True);
        Fatal := False;
        // if SetEOF fails we get garbage at the end of the file, not nice but
        // also not important.
        SetEndOfFile(FInFileHandle);
      end;
    end;
  except
    on ews: EZipMaster do
    begin
      ShowExceptionError(ews);
      FZipComment := '';
    end;
    on EOutOfMemory do
    begin
      ShowZipMessage(GE_NoMem, '');
      FZipComment := '';
    end;
  end;
  File_Close(FInFileHandle);
  if Fatal then  // Try to read the zipfile, maybe it still works.
    List;
end;

 (*? TZMWorker.SetZipSwitches
1.75 13 March 2004 RP - supply app window handle
1.73  1 August 2003 RP - set required dll interface version
*)
procedure TZMWorker.SetZipSwitches(const NameOfZipFile: String; zpParms:
    pZipParms);
var
  i: Integer; 
  SufStr: String;
  pExFiles: pExcludedFileSpec;
begin
  with zpParms^ do
  begin
    if Length(FZipComment) <> 0 then
    begin
      fArchComment := MakeStrP(fZipComment);
//      fArchComment := StrAlloc(Length(FZipComment) + 1);
//      StrPLCopy(fArchComment, FZipComment, Length(FZipComment) + 1);
    end;
    if AddArchiveOnly in fAddOptions then
      fArchiveFilesOnly := 1;
    if AddResetArchive in fAddOptions then
      fResetArchiveBit := 1;

    if (FFSpecArgsExcl.Count <> 0) then
    begin
      fTotExFileSpecs := FFSpecArgsExcl.Count;
      fExFiles := AllocMem(SizeOf(ExcludedFileSpec) *
        FFSpecArgsExcl.Count);
      for i := 0 to (fFSpecArgsExcl.Count - 1) do
      begin
        pExFiles := fExFiles;
        Inc(pExFiles, i);
        pExFiles.fFileSpec := MakeStrP(fFSpecArgsExcl[i]);
//          StrAlloc(Length(fFSpecArgsExcl[i]) + 1);
//        StrPLCopy(pExFiles.fFileSpec, fFSpecArgsExcl[i],
//          Length(fFSpecArgsExcl[i]) + 1);
      end;
    end;
    if FHowToDelete = htdAllowUndo then
      fHowToMove := True;
    if FCodePage = cpOEM then
      fWantedCodePage := 2;
  end;                                      { end with }

  if (Length(FTempDir) <> 0) then
  begin
    zpParms.fTempPath := MakeStrP(fTempDir);
//    zpParms.fTempPath := StrAlloc(Length(FTempDir) + 1);
//    StrPLCopy(zpParms.fTempPath, FTempDir, Length(FTempDir) + 1);
  end;

  with zpParms^ do
  begin
    fVersion := DELZIPVERSION;
    // version we expect the DLL to be
    fCaller := Self;
    // point to our VCL instance; returned in callback
    fHandle := Handle;
    fVCLVer := DELZIPVERSION;                  

    fQuiet := True;
    { we'll report errors upon notification in our callback }
    { So, we don't want the DLL to issue error dialogs }

    ZCallbackFunc := ZCallback;
    // pass addr of function to be called from DLL
    fJunkSFX := False;
    // if True, convert input .EXE file to .ZIP

    SufStr := AddStoreExtStr(fAddStoreSuffixes);
    if Length(SufStr) <> 0 then
    begin
      System.Delete(SufStr, Length(SufStr), 1);
      pSuffix := MakeStrP(SufStr);
//      pSuffix := StrAlloc(Length(SufStr) + 1);
//      StrPLCopy(pSuffix, SufStr, Length(SufStr) + 1);
    end;
    // fComprSpecial := False;     { if True, try to compr already compressed files }

    fSystem := False;
    { if True, include system and hidden files }

    fVolume := AddVolume in fAddOptions;

    fExtra := False;
    { if True, include extended file attributes-NOT SUPTED }

    fUseDate := AddFromDate in fAddOptions;
    { if True, exclude files earlier than specified date } 
    { Date to include files after; only used if fDate=TRUE }
    fDate := DateTimeToFileDate(fFromDate);

    fLevel := FAddCompLevel;
    { Compression level (0 - 9, 0=none and 9=best) }
    fCRLF_LF := False;
    { if True, translate text file CRLF to LF (if dest Unix)}
    fGrow := not (AddSafe in FAddOptions);
    { if True, Allow appending to a zip file (-g)}

    fDeleteEntries := False;
    { distinguish bet. Add and Delete }

    fTraceEnabled := Trace;
    fVerboseEnabled := Verbose;
    if (fTraceEnabled and not Verbose) then
      fVerboseEnabled := True;
    { if tracing, we want verbose also }

    { convert all filenames to 8x3 format }
    fForce := AddForceDOS in fAddOptions;
    // make zipfile's timestamp same as newest file
    fLatestTime := AddZipTime in fAddOptions;
    //   dangerous, beware!
    fMove := AddMove in fAddOptions;
    fFreshen := AddFreshen in fAddOptions;
    fUpdate := AddUpdate in fAddOptions;
    if (fFreshen and fUpdate) then
      fFreshen := False;
    { Update has precedence over freshen }

    { DLL will prompt for password }
    fEncrypt := AddEncrypt in fAddOptions;
    { NOTE: if user wants recursion, then he probably also wants
        AddDirNames, but we won't demand it. }
    fRecurse := AddRecurseDirs in fAddOptions;
    fSystem := AddHiddenFiles in fAddOptions;
    fNoDirEntries := not (AddSeparateDirs in fAddOptions);
    { don't store dirnames with filenames }
    fJunkDir := not (AddDirNames in fAddOptions);

    pZipFN := MakeStrP(NameOfZipFile);
//    pZipFN := StrAlloc(Length(NameOfZipFile) + 1);
//    // allocate room for null terminated string
//    StrPLCopy(pZipFN, NameOfZipFile, Length(NameOfZipFile) + 1);
    { name of zip file }
    if Length(FPassword) > 0 then
    begin
      pZipPassword := MakeStrP(fPassword);
//      pZipPassword := StrAlloc(Length(FPassword) + 1);
//      { allocate room for null terminated string }
//      StrPLCopy(pZipPassword, FPassword, PWLEN + 1);
      { password for encryption/decryption }
    end;
  end;                                      {end else with do }
end;

(*? TZMWorker.Starting
*)
procedure TZMWorker.Starting;
begin
  inherited;
end;

(*? TZMWorker.WriteJoin 
1.79 3 January 2006 RP copy > 2G
1.77 13 August 2004 RP progress
1.73 15 July 2003 RP progress
*)
procedure TZMWorker.WriteJoin(const Buffer; BufferSize: Cardinal; DSErrIdent:
    Integer);
begin
  if FileWrite(FOutFileHandle, Buffer, BufferSize) <> Integer(BufferSize) then
    raise EZipMaster.CreateResDisp( DSErrIdent, True);

  // Give some progress ZipLoadStr while writing.
  // While processing the central header we don't want messages.
  //  if FShowProgress <> zspNone then
  //    Report(zacProgress, 0, '', BufferSize);
  if FShowProgress = zspExtra then
    Report(zacXProgress, 0, '', BufferSize)
  else
  if FShowProgress = zspFull then
    Report(zacProgress, 0, '', BufferSize);
end;

(*? TZMWorker.WriteSpan
1.79 6 May 2007 RA fix split central count
1.79 3 January 2006 RP copy > 2G
1.79 17 Dec 2004 RA - Use FNumbering for last part renaming
1.77 1 Oct 2004 test/use YesToAll
1.77 1 Sep 2004 RP Allow Cancel
1.76 6 June 2004 RA initial InFileHandle empty
1.73.2.4 31 August 2003 don't delete last part on floppy
1.73 11 July 2003 RP buffer Central Directory writes
1.73 9 July 2003 RA changed OnMessage and OnProgress to Report calls
1.73 27 June 2003 RP changed Split file handling
// Function to read a Zip source file and write it back to one or more disks.
// Return values:
//  0           All Ok.
// -7           WriteSpan errors. See ZipMsgXX.rc
// -8           Memory allocation error.
// -9           General unknown WriteSpan error.
*)
{$IFNDEF NO_SPAN}
function TZMWorker.WriteSpan(InFileName, OutFileName: String;
  useXProgress: Boolean): Integer;
type
  pZipCentralHeader = ^ZipCentralHeader;
  pZipLocalHeader = ^ZipLocalHeader;
var
  CenDisk: Word;
  CentralEntries: Word;
  EOC:  ZipEndOfCentral;
  Res, i, k, Fix: Integer;
  LastName, MsgStr: String;
  TotalBytesWrite: Cardinal;
  StartCentral: Cardinal;
  CentralOffset: Cardinal;
  Buffer: array of AnsiChar;
  MDZD: TZMDataList;
  MDZDp: TMDZipData;//pMZipData;
  EBuf: AnsiString;
  ELen, VLen: Cardinal;
  Ebufp: PAnsiChar;
  CEHp: pZipCentralHeader;
  LOHp: pZipLocalHeader;
  Fname: String;
  BatchStarted: Boolean;
  tmpStatusDisk: tstatusDiskEvent;
begin
  BatchStarted := False;
  SetLength(Buffer, BufSize);
  Result := 0;
  FErrCode := 0;
  FMessage := '';
  fZipBusy := True;
  FDiskNr := 0;
  FFreeOnDisk := 0;
  FNewDisk := True;
  FDiskWritten := 0;
  FTotalDisks := -1;                        // 1.72 don't know number
  FInFileName := InFileName;
  FOutFileName := OutFileName;
  FOutFileHandle := -1;
  FInFileHandle := -1;
  FShowProgress := zspNone;//False;
  CentralOffset := 0;
  MDZD := Nil;

  FDrive := ExtractFileDrive(OutFileName) + '\';
  FDriveFixed := IsFixedDrive(FDrive);      // 1.72

  StartWaitCursor;
  try
    if not FileExists(InFileName) then
      raise EZipMaster.CreateResDisp( DS_NoInFile, True);
    if ExtractFileName(OutFileName) = '' then
      raise EZipMaster.CreateResDisp( DS_NoOutFile, True);
    if FDriveFixed then
      CheckDestWritable(OutFileName, false);
//    if FDriveFixed and not IsDestWritable(OutFileName) then
//      raise EZipMaster.CreateResDrive( DS_NotChangeable, OutFileName);

    // The following function will read the EOC and some other stuff:
    OpenEOC(EOC, True);

    // Get the date-time stamp and save for later.
    FDateStamp := FileGetDate(FInFileHandle);

    // go back to the start the zip archive.
    if (FileSeek64(FInFileHandle, Int64(0), 0) = -1) then
      raise EZipMaster.CreateResDisp( DS_FailedSeek, True);

    MDZD := TZMDataList.Create(EOC.TotalEntries);

    // Write extended local Sig. needed for a spanned archive.
    FInteger := ExtLocalSig;
    WriteSplit(FInteger, 4, 0);

    // Read for every zipped entry: The local header, variable data, fixed data
    // and, if present, the Data decriptor area.
    //    FShowProgress := True;
    if UseXProgress then
    begin
      Report(zacXItem, zprSplitting, '', FFileSize);//EOC.TotalEntries)
      FShowProgress := zspExtra;
    end
    else
    begin
      Report(zacCount, zprCompressed, '', EOC.TotalEntries);
      Report(zacSize, zprCompressed, '', FFileSize);
      FShowProgress := zspFull;
      BatchStarted := True;
    end;

    // 1.73 buffer writes of local header
    SetLength(EBuf, sizeof(ZipLocalHeader) + 70);
    for i := 0 to (EOC.TotalEntries - 1) do
    begin
      if FCancel then   // 1.77 Allow cancel
        raise EZipMaster.CreateResDisp( DS_Canceled, False);
      LOHp := pZipLocalHeader(PAnsiChar(EBuf));
      // First the local header.
      ReadJoin(LOHp^, SizeOf(ZipLocalHeader), DS_LOHBadRead);
      if not (LOHp^.HeaderSig = LocalFileHeaderSig) then
        raise EZipMaster.CreateResDisp( DS_LOHWrongSig, True);
      VLen := LOHp^.FileNameLen + LOHp^.ExtraLen;
      ELen := sizeof(ZipLocalHeader) + VLen;
      if ELen > Cardinal(Length(EBuf)) then
      begin
        SetLength(EBuf, ELen);
        LOHp := pZipLocalHeader(PAnsiChar(EBuf)); // moved
      end;
      EBufp := PAnsiChar(EBuf) + sizeof(ZipLocalHeader);
      // Now the variable data
      ReadJoin(EBufp^, VLen, DS_LOHBadRead);
      // Save some information for later. ( on the last disk(s) ).
      MDZDp := MDZD.Items[i];
      MDZDp.DiskStart := FDiskNr;
//      MDZDp^.FileNameLen := LOHp^.FileNameLen;

//      StrLCopy(MDZDp^.FileName, EBufp, LOHp^.FileNameLen); // like makestring
//      MDZDSetNameP(MDZDp, EBufp, LOHp^.FileNameLen); // like makestring
      MDZDp.SetName(EBufp, LOHp^.FileNameLen); // like makestring
//      Fname := SetSlash(MDZDGetName(MDZDp), psdExternal);
      Fname := SetSlash(MDZDp.FileName, psdExternal);
//      Fname := SetSlash(MakeString(pChar(MDZDGetName(MDZDp)), LOHp^.FileNameLen), psdExternal);
//      Fname := SetSlash(MakeString(EBufp, LOHp^.FileNameLen), psdExternal);
      // Give message and progress info on the start of this new file read.
      MsgStr := ZipLoadStr(GE_CopyFile) + Fname;
      Report(zacMessage, 0, MsgStr, 0);

      TotalBytesWrite := ELen + {Integer(}LOHp^.ComprSize;//);
      if (LOHp^.Flag and Word($0008)) = 8 then
        TotalBytesWrite := TotalBytesWrite + SizeOf(ZipDataDescriptor);

      if not UseXProgress then
        Report(zacItem, zprCompressed, Fname, TotalBytesWrite);

      // Write the local header to the destination.
      WriteSplit(PAnsiChar(EBuf)^, ELen, ELen);

      // Save the offset of the LOH on this disk for later.
      MDZDp.RelOffLocal := FDiskWritten - ELen;

      // Read Zipped data !!!For now assume we know the size!!!
      RWSplitData(Buffer[0], TotalBytesWrite - ELen, DS_ZipData);
    end;
    // We have written all entries to disk.
    Report(zacMessage, 0, ZipLoadStr(GE_CopyFile) +
      ZipLoadStr(DS_CopyCentral), 0);
    if not UseXProgress then
      Report(zacItem, zprCentral, ZipLoadStr(DS_CopyCentral),
        EOC.CentralSize + sizeof(EOC) + EOC.ZipCommentLen);

    // Now write the central directory with changed offsets.
    SetLength(EBuf, sizeof(ZipCentralHeader) + 30);
    StartCentral := FDiskNr;
    CentralEntries := 0;    // count entries for each part
    CenDisk := FDiskNr;     // disk central part started
    for i := 0 to (EOC.TotalEntries - 1) do
    begin
      if FCancel then   // 1.77 Allow cancel
        raise EZipMaster.CreateResDisp( DS_Canceled, False);
      // Read a central header.
      CEHp := pZipCentralHeader(PAnsiChar(EBuf));
      ReadJoin(CEHp^, SizeOf(ZipCentralHeader), DS_CEHBadRead);
      if CEHp^.HeaderSig <> CentralFileHeaderSig then
        raise EZipMaster.CreateResDisp( DS_CEHWrongSig, True);
      // 1.73 RP copy full central record to buffer then write it
      VLen := CEHp^.FileNameLen + CEHp^.ExtraLen + CEHp^.FileComLen;
      ELen := SizeOf(ZipCentralHeader) + VLen;
      if ELen > Cardinal(Length(EBuf)) then
      begin
        SetLength(EBuf, ELen);
        CEHp := pZipCentralHeader(PAnsiChar(EBuf)); // may have moved
      end;
      EBufp := PAnsiChar(CEHp) + sizeof(ZipCentralHeader);
      // Now the variable length fields.
      ReadJoin(EBufp^, VLen, DS_CEHBadRead);

      // Change the central directory with information stored previously in MDZD.
      k := MDZD.IndexOf(EBufp, CEHp^.FileNameLen);
//      k := MDZD.IndexOf(MakeString(EBufp, CEHp^.FileNameLen));
      MDZDp := MDZD[k];
      CEHp^.DiskStart := MDZDp.DiskStart;
      CEHp^.RelOffLocal := MDZDp.RelOffLocal;

      // Write this changed central header to disk
      // and make sure it fit's on one and the same disk.
      WriteSplit(PAnsiChar(EBuf)^, ELen, ELen);

      // Save the first Central directory offset for use in EOC record.
      if i = 0 then
        CentralOffset := FDiskWritten - ELen;
      // changed disk ?
      if FDiskNr <> CenDisk then
      begin
        CenDisk := FDiskNr;
        CentralEntries := 0;
      end;
      inc(CentralEntries);
    end;

    // Write the changed EndOfCentral directory record.
    EOC.CentralEntries := CentralEntries;
    EOC.CentralDiskNo := StartCentral;
    EOC.ThisDiskNo := FDiskNr;
    EOC.CentralOffset := CentralOffset;
    WriteSplit(EOC, SizeOf(EOC), SizeOf(EOC) + EOC.ZipCommentLen);

    // Skip past the original EOC to get to the ZipComment if present. v1.52j
    if (FileSeek64(FInFileHandle, Int64(SizeOf(EOC)), 1) = -1) then
      raise EZipMaster.CreateResDisp( DS_FailedSeek, True);

    // And finally the archive comment
    RWSplitData(Buffer[0], EOC.ZipCommentLen, DS_EOArchComLen);
    FShowProgress := zspNone;//False;
  except
    on ews: EZipMaster do                   // All WriteSpan specific errors.
    begin
      ShowExceptionError(ews);
      Result := -7;
    end;
    on EOutOfMemory do                      // All memory allocation errors.
    begin
      ShowZipMessage(GE_NoMem, '');
      Result := -8;
    end;
    on E: Exception do
    begin
      // The remaining errors, should not occur.
      ShowZipMessage(DS_ErrorUnknown, E.Message);
      Result := -9;
    end;
  end;

  StopWaitCursor;
  Buffer := Nil;
  // Give the last progress info on the end of this file read.
  if BatchStarted then
    Report(zacEndOfBatch, 0, '', 0);

  if Assigned(MDZD) then
    FreeAndNil(MDZD);

  FileSetDate(FOutFileHandle, FDateStamp);
  if FOutFileHandle <> -1 then
    FileClose(FOutFileHandle);
  if FInFileHandle <> -1 then
    FileClose(FInFileHandle);
  if (Result = 0) then
  begin
//    LastName := FOutFileName;
//    CreateMVFileNameEx(LastName, False, (spCompatName in FSpanOptions) or
//      (FNumbering = znsExt));
//    if FDriveFixed and ((spCompatName in FSpanOptions) or
//      (FNumbering = znsExt)) then
    Fix := 0;
    if (FNumbering = znsExt) or (spCompatName in FSpanOptions) then
    begin
      if FDriveFixed then
        Fix := 2;
    end
    else
    if (FDiskNr = 0)  // only single part
       and ((FNumbering = znsName) or (spNoVolumeName in FSpanOptions)) then
      Fix := 1;
//    if (FDiskNr = 0)  // only single part
//       and ((FNumbering = znsName) or (spNoVolumeName in FSpanOptions)) then
//      Fix := 1
//    else
//    if FDriveFixed and ((spCompatName in FSpanOptions)
//                          or (FNumbering = znsExt)) then
//      Fix := 2;
    if Fix > 0 then
    begin
      LastName := OutFileName;
      CreateMVFileNameEx(LastName, False, Fix = 2);
//      begin
      if (FileExists(OutFileName)) then
      begin
        // get permission to delete
        MsgStr := ZipFmtLoadStr(DS_AskDeleteFile, [OutFileName]);
        FZipDiskStatus := FZipDiskStatus + [zdsSameFileName];
        Res := idYes;
        if not (zaaYesOvrWrt in FAnswerAll) then
        begin
          tmpStatusDisk := Events.OnStatusDisk;
          if assigned(tmpStatusDisk) then //1.77
          begin
            FZipDiskAction := zdaOk;          // The default action
            tmpStatusDisk(Master, FDiskNr, FOutFileName,
              FZipDiskStatus, FZipDiskAction);
            if FZipDiskAction = zdaYesToAll then
            begin
              FAnswerAll := FAnswerAll + [zaaYesOvrWrt];
              FZipDiskAction := zdaOk;
            end;
            if FZipDiskAction = zdaOk then
              Res := idYes
            else
              Res := idNo;
          end
          else
            Res := ZipMessageDlgEx(ZipLoadStr(FM_Confirm), MsgStr,
              zmtWarning + DHC_WrtSpnDel, [mbYes, mbNo]);
        end;
        if (Res = 0) then
          ShowZipMessage(DS_NoMem, '');
        if (Res = idNo) then
          Report(zacMessage, DS_NoRenamePart,
            ZipFmtLoadStr(DS_NoRenamePart, [LastName]), 0);
        if (Res = idYes) then
          SysUtils.DeleteFile(FOutFileName);  // if it exists delete old one
      end;
      if FileExists(LastName) then          // should be there but ...
        RenameFile(LastName, FOutFileName);
    end;
//    end;
  end;
  FTotalDisks := FDiskNr;
  fZipBusy := False;
end;
{$ENDIF}

(*? TZMWorker.WriteSplit
1.79 3 January 2006 RP file > 2G
1.79 12 Dec 2004 RA use FNumbering
1.77 1 Oct 2004 RP - use YesToAll
1.77 18 Aug 2004 RA - allow unattended on fixed drive
1.77 15 August 2004 RP progress
1.73.3.3 15 October 2003 RP Remove duplicated code
1.73.3.2 11 October 2003 RA set KeepFreeOnDisk1 and KeepFreeOnAlldisk to sector boundaries
1.73.2.7 12 September 2003 RP stoppped disk number<0
1.73 11 July 2003 RP corrected asking disk status
1.73 9 July 2003 RA corrected use of disk status and OnStatusDisk
1.73 7 July 2003 RA changed OnMessage and OnProgress to Report calls
1.73 28 June 2003 changed Split file handling
// This function actually writes the zipped file to the destination while
// taking care of disk changes and disk boundary crossings.
// In case of an write error, or user abort, an exception is raised.
*)
{$IFNDEF NO_SPAN}
procedure TZMWorker.WriteSplit(const Buffer; Len, MinSize: Cardinal);
var
  Res: Integer;
  MaxLen: Cardinal;
  Buf: PAnsiChar; // Used if Buffer doesn't fit on the present disk.
  DiskSeq: Integer;
  DiskFile, MsgQ: String;
  SectorsPCluster, BytesPSector, FreeClusters, TotalClusters: Cardinal;

  function NewSegment: Boolean; // true to 'continue'
  var
    tmpStatusDisk: TStatusDiskEvent;
  begin
    Result := False;
    FDriveFixed := IsFixedDrive(FDrive);  // 1.72
    CheckForDisk(True);                   // 1.70 changed
    DiskFile := FOutFileName;
    // If we write on a fixed disk the filename must change.
    // We will get something like: FileNamexxx.zip where xxx is 001,002 etc.
    // if CompatNames are used we get FileName.zxx where xx is 01, 02 etc.. last .zip   
    if FNumbering = znsNone then
    begin
      if spCompatName in SpanOptions then
        FNumbering := znsExt
      else
      if FDriveFixed or (spNoVolumeName in SpanOptions) then
        FNumbering := znsName
      else
        FNumbering := znsVolume;
    end;
    if FNumbering >= znsName then
      CreateMVFileNameEx(DiskFile, False, FNumbering = znsExt);
{    case FNumbering of
      znsNone:
        if FDriveFixed or (spNoVolumeName in FSpanOptions) then
          CreateMVFileNameEx(DiskFile, False, (spCompatName in FSpanOptions));
      znsName:
        CreateMVFileNameEx(DiskFile, False, False);
      //      znsVolume:
      //  no change needed
      znsExt:
        CreateMVFileNameEx(DiskFile, False, True);
    end; }

    //    if FDriveFixed or (spNoVolumeName in FSpanOptions) then
    //      CreateMVFileName(DiskFile, False);
    // Allow clearing of removeable media even if no volume names
    if (not FDriveFixed) and (spWipeFiles in FSpanOptions) then
    begin
      if (FZipDiskAction = zdaErase) or not Assigned(Events.OnGetNextDisk) then 
      begin
        // Do we want a format first?
        FDriveNr := Ord(UpperCase(FDrive)[1]) - Ord('A');
        if (spNoVolumeName in FSpanOptions) then
          FVolumeName := 'ZipSet_' + IntToStr(succ(FDiskNr))
        // default name
        else
          FVolumeName := 'PKBACK# ' + Copy(IntToStr(1001 + FDiskNr), 2, 3);
        // Ok=6 NoFormat=-3, Cancel=-2, Error=-1
        case ZipFormat of
          // Start formating and wait until finished...
          -1:
            raise EZipMaster.CreateResDisp( DS_Canceled, True);
          -2:
            raise EZipMaster.CreateResDisp( DS_Canceled, False);
        end;
      end;
    end;
    if FDriveFixed or (spNoVolumeName in FSpanOptions) then
      DiskSeq := FDiskNr + 1
    else
    begin
      DiskSeq := StrToIntDef(Copy(FVolumeName, 9, 3), 1);
      if DiskSeq < 0 then
        DiskSeq := 1;
    end;
    FZipDiskStatus := [];                 // v1.60L
    // Do we want to overwrite an existing file?
    if FileExists(DiskFile) then
      if (FileAge(DiskFile) = FDateStamp) and (Pred(DiskSeq) < FDiskNr) then
      begin
        MsgQ := ZipFmtLoadStr(DS_AskPrevFile, [DiskSeq]);
        FZipDiskStatus := FZipDiskStatus + [zdsPreviousDisk]; // v1.60L
      end
      else
      begin
        MsgQ := ZipFmtLoadStr(DS_AskDeleteFile, [DiskFile]);
        FZipDiskStatus := FZipDiskStatus + [zdsSameFileName]; // v1.60L
      end
    else
    if not FDriveFixed then
      if (FSizeOfDisk - FFreeOnDisk) <> 0 then // v1.60L
        FZipDiskStatus :=
          FZipDiskStatus + [zdsHasFiles] // But not the same name
      else
        FZipDiskStatus := FZipDiskStatus + [zdsEmpty];
    tmpStatusDisk := Events.OnStatusDisk;
    if Assigned(tmpStatusDisk) and not (zaaYesOvrWrt in FAnswerAll) then
      // 1.77
    begin
      FZipDiskAction := zdaOk;            // The default action
      tmpStatusDisk(Master, DiskSeq, DiskFile, FZipDiskStatus, FZipDiskAction);
      case FZipDiskAction of
        zdaCancel:
          Res := idCancel;
        zdaReject:
          Res := idNo;
        zdaErase:
          Res := idOk;
        zdaYesToAll:
        begin
          Res := idOk;
          FAnswerAll := FAnswerAll + [zaaYesOvrWrt];
        end;
        zdaOk:
          Res := idOk;
        else
          Res := idOk;
      end;
    end
    else
    if ((FZipDiskStatus * [zdsPreviousDisk, zdsSameFileName]) <> []) and
      not ((zaaYesOvrwrt in FAnswerAll) or FUnattended) then
    begin
      Res := ZipMessageDlgEx(ZipLoadStr(FM_Confirm), MsgQ,
        zmtWarning + DHC_SpanOvr, [mbYes, mbNo, mbCancel, mbYesToAll]);
      if Res = mrYesToAll then
      begin
        FAnswerAll := FAnswerAll + [zaaYesOvrwrt];
        Res := idOk;
      end;
    end
    else
      Res := idOk;
    if (Res = 0) or (Res = idCancel) or ((Res = idNo) and FDriveFixed) then
      raise EZipMaster.CreateResDisp( DS_Canceled, False);

    if Res = idNo then
    begin                                 // we will try again...
      FDiskWritten := 0;
      FNewDisk := True;
      Result := True;
      exit;
    end;
    // Create the output file.
    FOutFileHandle := FileCreate(DiskFile);
    if FOutFileHandle = -1 then
      //  raise EZipMaster.CreateResDisp( DS_NoOutFile, True);
    begin                                 //change proposed by Pedro Araujo
      MsgQ := ZipLoadStr(DS_NoOutFile);      // 'Creation of output file failed');
      MsgQ := MsgQ + ' - ' + DiskFile + WinErr(0);  ///V
      Res := ZipMessageDlgEx('', MsgQ, zmtError + DHC_SpanNoOut,
        [mbRetry, mbCancel]);
      if Res = 0 then
        raise EZipMaster.CreateResDisp( DS_NoMem, True);
      if Res <> idRetry then
        raise EZipMaster.CreateResDisp( DS_Canceled, False);
      FDiskWritten := 0;
      FNewDisk := True;
      Result := True;
      exit;
    end;

    // Get the free space on this disk, correct later if neccessary.
    DiskFreeAndSize(1);                   // RCV150199

    // Set the maximum number of bytes that can be written to this disk(file).
    // Reserve space on/in all the disk/file.
    FFreeOnDisk := FFreeOnDisk - FFreeOnAllDisks;

    if (FMaxVolumeSize > 0) and (FMaxVolumeSize < FFreeOnDisk) then
      FFreeOnDisk := FMaxVolumeSize;
    // Reserve space on/in all the disk/file.
    if (FDiskNr = 0) and (FFreeOnDisk1 > 0) or (FFreeOnAllDisks > 0) then
      // only one calculation if needed
      if (GetDiskFreeSpace(Pchar(FDrive), SectorsPCluster,
        BytesPSector, FreeClusters,
        TotalClusters)) then
      begin
        if (FFreeOnDisk1 mod BytesPSector) <> 0 then
          FFreeOnDisk1 := succ(FFreeOnDisk1 div BytesPSector) * BytesPSector;
        if (FFreeOnAllDisks mod BytesPSector) <> 0 then
          FFreeOnAllDisks :=
            succ(FFreeOnAllDisks div BytesPSector) * BytesPSector;
      end;
    Dec(FFreeOnDisk, FFreeOnAllDisks);
    // Reserve space on/in the first disk(file).
    if FDiskNr = 0 then
      Dec(FFreeOnDisk, FFreeOnDisk1);

    // Do we still have enough free space on this disk.
    if FFreeOnDisk < FMinFreeVolSize then // No, too bad...
    begin
      FileClose(FOutFileHandle);
      SysUtils.DeleteFile(DiskFile);
      FOutFileHandle := -1;
      tmpStatusDisk := Events.OnStatusDisk;
      if Assigned(tmpStatusDisk) then     // v1.60L
      begin
        if spNoVolumeName in FSpanOptions then
          DiskSeq := FDiskNr + 1
        else
        begin
          DiskSeq := StrToIntDef(Copy(FVolumeName, 9, 3), 1);
          if DiskSeq < 0 then
            DiskSeq := 1;
        end;
        FZipDiskAction := zdaOk;          // The default action
        FZipDiskStatus := [zdsNotEnoughSpace];
        tmpStatusDisk(Master, DiskSeq, DiskFile, FZipDiskStatus, FZipDiskAction);
        case FZipDiskAction of
          zdaCancel:
            Res := idCancel;
          zdaOk:
            Res := idRetry;
          zdaErase:
            Res := idRetry;
          zdaReject:
            Res := idRetry;
          else
            Res := idRetry;
        end;
      end
      else
      begin
        MsgQ := ZipLoadStr(DS_NoDiskSpace);
        //            'This disk has not enough free space available');
        //        Res  := MessageBox(FHandle, PChar(MsgQ), PChar(Application.Title),
        //          MB_RETRYCANCEL or MB_ICONERROR);
        Res := ZipMessageDlgEx('', MsgQ, zmtError + DHC_SpanSpace,
          [mbRetry, mbCancel]);
      end;
      if Res = 0 then
        raise EZipMaster.CreateResDisp( DS_NoMem, True);
      if Res <> idRetry then
        raise EZipMaster.CreateResDisp( DS_Canceled, False);
      FDiskWritten := 0;
      FNewDisk := True;
      // If all this was on a HD then this would't be useful but...
      //Continue;
      Result := True;
      exit;
    end;

    // Set the volume label of this disk if it is not a fixed one.
    if not (FDriveFixed or (spNoVolumeName in FSpanOptions)) then
    begin
      FVolumeName := 'PKBACK# ' + Copy(IntToStr(1001 + FDiskNr), 2, 3);
      if not SetVolumeLabel(Pchar(FDrive), Pchar(FVolumeName)) then
        raise EZipMaster.CreateResDisp( DS_NoVolume, True);
    end;
  end;

begin  {WriteSplit}
  Buf := @Buffer;
  //  if ForegroundTask then
  //    Application.ProcessMessages;
  Report(zacTick, 0, '', 0);
  if Cancel then
    raise EZipMaster.CreateResDisp( DS_Canceled, False);

  while True do
    // Keep writing until error or buffer is empty.
  begin
    // Check if we have an output file already opened, if not: create one,
    // do checks, gather info.
    if FOutFileHandle = -1 then
      if NewSegment then
        continue;  // END OF: if FOutFileHandle = -1

    // Check if we have at least MinSize available on this disk,
    // headers are not allowed to cross disk boundaries. ( if zero than don't care.)
    if (MinSize > 0) and (MinSize > FFreeOnDisk) then
    begin
      FileSetDate(FOutFileHandle, FDateStamp);
      FileClose(FOutFileHandle);
      FOutFileHandle := -1;
      FDiskWritten := 0;
      FNewDisk := True;
      Inc(FDiskNr);                         // RCV270299
      Continue;
    end;

    // Don't try to write more bytes than allowed on this disk.
    MaxLen := HIGH(Integer);
    if FFreeOnDisk < MaxLen then
      MaxLen := Integer(FFreeOnDisk);
    if Len < MaxLen then
      MaxLen := Len;
    Res := FileWrite(FOutFileHandle, Buf^, MaxLen);
    if Res = -1 then
      raise EZipMaster.CreateResDisp( DS_NoWrite, True);
    // A write error (disk removed?)

    // Give some progress info while writing
    // While processing the central header we don't want messages.
    if FShowProgress <> zspNone then
      //      Report(zacProgress, 0, '', MaxLen);
      if FShowProgress = zspExtra then
        Report(zacXProgress, 0, '', Res)
      else
        Report(zacProgress, 0, '', Res);

    Inc(FDiskWritten, Res);
    FFreeOnDisk := FFreeOnDisk - MaxLen;    // RCV150199
    if MaxLen = Len then
      Break;

    // We still have some data left, we need a new disk.
    FileSetDate(FOutFileHandle, FDateStamp);
    FileClose(FOutFileHandle);
    FOutFileHandle := -1;
    FFreeOnDisk := 0;
    FDiskWritten := 0;
    Inc(FDiskNr);
    FNewDisk := True;
    Inc(Buf, MaxLen);
    Dec(Len, MaxLen);
  end;
end;
{$ENDIF}

(*? TZMWorker.ZipFormat
1.76 14 May 2004 check ConfirmErase
*)    
{$IFNDEF NO_SPAN}
function TZMWorker.ZipFormat: Integer;
var
  Msg, Vol: String;
  Res: Integer;
begin
  Result := -3;
  if (spTryFormat in FSpanOptions) and not FDriveFixed then
    Result := FormatFloppy(Application.Handle, FDrive);
  if Result = -3 then
  begin
    if FConfirmErase then
    begin
      Msg := ZipFmtLoadStr(FM_Erase, [FDrive]);
      Res := ZipMessageDlgEx(ZipLoadStr(FM_Confirm), Msg,
        zmtWarning + DHC_FormErase, [mbYes, mbNo]);
      if Res <> idYes then
      begin
        Result := -3;                       // no  was -2; // cancel
        Exit;
      end;
    end;
    ClearFloppy(FDrive);
    Result := 0;
  end;
  if Length(FVolumeName) > 11 then
    Vol := Copy(FVolumeName, 1, 11)
  else
    Vol := FVolumeName;
  if (Result = 0) and not (spNoVolumeName in FSpanOptions) then
    // did it
    SetVolumeLabel(Pchar(FDrive), Pchar(Vol));
end;

{$ENDIF}

end.

