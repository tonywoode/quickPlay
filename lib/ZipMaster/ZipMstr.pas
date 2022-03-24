unit ZipMstr;

(*
  ZipMstr.pas - main component
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

  contact: problems@delphizip.org
  updates: http://www.delphizip.org

  modified 2009-04-12
---------------------------------------------------------------------------*)
{$INCLUDE ZipConfig.inc}
{$INCLUDE '.\ZipVers.inc'}

// uncomment the following line to bind the resources to the package
//{$R 'res\zmres.res'}

interface

uses
  Forms, Classes, SysUtils, Graphics, Dialogs, windows, Controls,
  ZipSFX, SFXInterface, ZMXcpt, ZipMsg, ZMMsgStr;

const
  ZIPMASTERVERSION: String = '1.79';
  ZIPMASTERBUILD: String =  '1.79.10.30';
  ZIPMASTERVER: Integer = 179;
  ZIPMASTERPRIV: Integer =  1791030;
  DELZIPVERSION = 179;                     
  DelZipDll_Name = 'DelZip179.dll';
//  DelZipDll_Name = DefaultDelZipDll_Name;

const
  BUSY_ERROR: Integer = -255;
  Reentry_Error: Integer = $4000000;

const
  pwbOk = mbOK;
  pwbCancel = mbCancel;
  pwbCancelAll = mbAll;
  pwbAbort = mbAbort;

type
  LargeInt = Int64;

//type
//  Longword = Cardinal;

type
  TPasswordButton = TMsgDlgBtn;
  TPasswordButtons = TMsgDlgButtons;

const
  PWLEN = 80;

type
  AddOptsEnum = (AddDirNames, AddRecurseDirs, AddMove, AddFreshen, AddUpdate,
    AddZipTime, AddForceDOS, AddHiddenFiles, AddArchiveOnly, AddResetArchive,
    AddEncrypt, AddSeparateDirs, AddVolume, AddFromDate, AddSafe, AddForceDest,
    AddDiskSpan, AddDiskSpanErase);
  AddOpts = set of AddOptsEnum;

  SpanOptsEnum = (spNoVolumeName, spCompatName, spWipeFiles, spTryFormat);
  SpanOpts = set of SpanOptsEnum;

  // When changing this enum also change the pointer array in the function AddSuffix,
  // and the initialisation of ZipMaster.
  AddStoreSuffixEnum = (assGIF, assPNG, assZ, assZIP, assZOO, assARC,
    assLZH, assARJ, assTAZ, assTGZ, assLHA, assRAR,
    assACE, assCAB, assGZ, assGZIP, assJAR, assEXE, assEXT,
    // extra extensions 1.79
    assJPG, assJPEG, ass7Zp, assMP3, assWMV, assWMA, assDVR, assAVI);

  AddStoreExts = set of AddStoreSuffixEnum;

  ExtrOptsEnum = (ExtrDirNames, ExtrOverWrite, ExtrFreshen, ExtrUpdate,
    ExtrTest, ExtrForceDirs);
  ExtrOpts = set of ExtrOptsEnum;
                                                             
  OvrOpts = (OvrAlways, OvrNever, OvrConfirm);
  ReplaceOpts = (rplConfirm, rplAlways, rplNewer, rplNever);

  // added 1.79.10.07
  TZMRenameOpts = (htrDefault, htrOnce, htrFull);

//{$IFDEF _SFX_}
//  TDeleteOpts = THowToDeleteFile;
//{$ELSE}
  TDeleteOpts = (htdFinal, htdAllowUndo);
//{$ENDIF}
  //  TDeleteFileOpts = (dfoFinal, dfoAllowUndo);

  CodePageOpts = (cpAuto, cpNone, cpOEM);
  CodePageDirection = (cpdOEM2ISO, cpdISO2OEM);

  UnZipSkipTypes = (stOnFreshen, stNoOverwrite, stFileExists, stBadPassword,
    stNoEncryptionDLL, stCompressionUnknown, stUnknownZipHost,
    stZipFileFormatWrong, stGeneralExtractError);

  ZipDiskStatusEnum = (zdsEmpty, zdsHasFiles, zdsPreviousDisk, zdsSameFileName,
    zdsNotEnoughSpace);
  TZipDiskStatus = set of ZipDiskStatusEnum;
  TZipDiskAction = (zdaYesToAll, zdaOk, zdaErase, zdaReject, zdaCancel);


type  
{$IFDEF KEEP_BACKWARD}
  {$IFDEF ALLOW_2G}
    TProgressSize = Cardinal;// - will allow uncompressed size to almost 4G
  {$ELSE}
    TProgressSize = Integer;// - will allow uncompressed size to almost 2G
  {$ENDIF}
{$ELSE}
  TProgressSize = Int64;
{$ENDIF}

type
  ProgressType = (NewFile, ProgressUpdate, EndOfBatch, TotalFiles2Process,
    TotalSize2Process, NewExtra, ExtraUpdate);

type
  TProgressDetails = class (TObject)
  PROTECTED
    FProgType: ProgressType;
    FItemCount: Integer;
    FWritten:  Int64;
    FTotalSize: Int64;
    FTotalPosition: Int64;
    FItemSize: Cardinal;
    FItemPosition: Cardinal;
    FItemName: String;
    FItemNumber: Integer;
    function GetItemPerCent: Integer;
    function GetTotalPerCent: Integer;
  PUBLIC
    destructor Destroy; OVERRIDE;
    property ItemPerCent: Integer READ GetItemPerCent;
    property TotalPerCent: Integer READ GetTotalPerCent;
    property Order: ProgressType READ FProgType;
    property TotalCount: Integer READ FItemCount;
    property BytesWritten: Int64 READ FWritten;
    property TotalSize: Int64 READ FTotalSize;
    property TotalPosition: Int64 READ FTotalPosition;
    property ItemSize: Cardinal READ FItemSize;
    property ItemPosition: Cardinal READ FItemPosition;
    property ItemName: String READ FItemName;
    property ItemNumber: Integer READ FItemNumber;
  end;

type
  ZipDirEntry = packed record               // fixed part size = 42
    MadeByVersion: Byte;
    HostVersionNo: Byte;
    Version: Word;
    Flag:  Word;
    CompressionMethod: Word;
    DateTime: Integer;                      // Time: Word; Date: Word; 
    CRC32: Integer;
    CompressedSize: Longword;//Integer;
    UncompressedSize: Longword;//Integer;
    FileNameLength: Word;
    ExtraFieldLength: Word;
    FileCommentLen: Word;
    StartOnDisk: Word;
    IntFileAttrib: Word;
    ExtFileAttrib: Longword;
    RelOffLocalHdr: Longword;
    FileName: String;                       // variable size
    FileComment: String;                    // variable size
    Encrypted: Boolean;
    ExtraData: {$ifndef UNICODE}AnsiString{$else}RawByteString{$endif}; 
//    ExtraData: {$ifndef VERD6up}AnsiString{$else}RawByteString{$endif};
  end;
  pZipDirEntry = ^ZipDirEntry;

type
  pZipRenameRec = ^ZipRenameRec;

  ZipRenameRec = record
    Source: String;
    Dest: String;
    Comment: String;   //**new
    DateTime: Integer;
  end;


type
  TCheckTerminateEvent = procedure(Sender: TObject;
    var abort: Boolean) of object;
  TCopyZipOverwriteEvent = procedure(Sender: TObject; ForFile: String;
    var DoOverwrite: Boolean) of object;
  TCRC32ErrorEvent = procedure(Sender: TObject; ForFile: String;
    FoundCRC, ExpectedCRC: Longword; var DoExtract: Boolean) of object;
  TExtractOverwriteEvent = procedure(Sender: TObject; ForFile: String;
    IsOlder: Boolean; var DoOverwrite: Boolean; DirIndex: Integer) of object;
  TExtractSkippedEvent = procedure(Sender: TObject; ForFile: String;
    SkipType: UnZipSkipTypes; ExtError: Integer) of object;
  TFileCommentEvent = procedure(Sender: TObject; ForFile: String;
    var FileComment: String; var IsChanged: Boolean) of object;
  TFileExtraEvent = procedure(Sender: TObject; ForFile: String;
    var Data: AnsiString; var IsChanged: Boolean) of object;
  TGetNextDiskEvent = procedure(Sender: TObject;
    DiskSeqNo, DiskTotal: Integer; Drive: String;
    var AbortAction: Boolean) of object;
  TItemProgressEvent = procedure(Sender: TObject; Item: String;
    TotalSize: Cardinal; PerCent: Integer) of object;
  TMessageEvent = procedure(Sender: TObject; ErrCode: Integer;
    Message: String) of object;
  TNewNameEvent = procedure(Sender: TObject; SeqNo: Integer;
    ZipEntry: ZipDirEntry) of object;
  TPasswordErrorEvent = procedure(Sender: TObject; IsZipAction: Boolean;
    var NewPassword: String; ForFile: String; var RepeatCount: Longword;
    var Action: TMsgDlgBtn) of object;
  TProgressDetailsEvent = procedure(Sender: TObject;
    details: TProgressDetails) of object;
  TProgressEvent = procedure(Sender: TObject; ProgrType: ProgressType;
    Filename: String; FileSize: TProgressSize) of object;
  TSetAddNameEvent = procedure(Sender: TObject; var FileName: String;
    const ExtName: String; var IsChanged: Boolean) of object;
  TSetExtNameEvent = procedure(Sender: TObject; var FileName: String;
    var IsChanged: Boolean) of object;
  TSetNewNameEvent = procedure(Sender: TObject; var OldFileName: String;
    var IsChanged: Boolean) of object;
  TStatusDiskEvent = procedure(Sender: TObject; PreviousDisk: Integer;
    PreviousFile: String; Status: TZipDiskStatus;
    var Action: TZipDiskAction) of object;
  TTickEvent = procedure(Sender: TObject) of object;
  TTotalProgressEvent = procedure(Sender: TObject; TotalSize: TProgressSize;
    PerCent: Integer) of object;
  TZipDialogEvent = procedure(Sender: TObject; const title: String;
    var msg: String; var Result: Integer; btns: TMsgDlgButtons) of object;
  TZipStrEvent = ZMMsgStr.TZipStrEvent;

type
  TZipStream = class (TMemoryStream)
  PUBLIC
    constructor Create;
    destructor Destroy; OVERRIDE;
//    procedure SetPointer(Ptr: Pointer; Size: Integer); VIRTUAL;
  end;


{$IFDEF INTERNAL_SFX}
type
{  SFXOptsEnum = (sfxAskCmdLine, sfxAskFiles, sfxHideOverWriteBox, sfxAutoRun,
    sfxNoSuccessMsg, sfxExpandVariables, sfxInitiallyHideFiles, sfxForceHideFiles,
    sfxCheckAutoRunFileName, sfxCanBeCancelled, sfxDetached );
    SFXCheckSize, SFXNoSuccessMsg);
  SFXOpts = set of SFXOptsEnum;   }
  SFXOpts = SFXInterface.TSFXOptions;
const
  sfxAskCmdLine = SFXInterface.soAskCmdLine;
  sfxAskFiles = SFXInterface.soAskFiles;
  sfxHideOverWriteBox = SFXInterface.soHideOverWriteBox;
  sfxAutoRun = SFXInterface.soAutoRun;
  sfxNoSuccessMsg = SFXInterface.soNoSuccessMsg; 
{$ENDIF}

type
  TCustomZipMaster = class (TComponent)
  PRIVATE
    FActive: integer;
    FAddCompLevel: Integer;
    fAddOptions: AddOpts;
    FAddStoreSuffixes: AddStoreExts;
    FBusy: Boolean;
    FCodePage: CodePageOpts; 
{$IFNDEF NO_SPAN}
    FConfirmErase: Boolean;
{$ENDIF}
    FDLLDirectory: String;
    fDllLoad: Boolean;
    FEncrypt: Boolean;
    fExtAddStoreSuffixes: String;
    { Private versions of property variables }
    fExtrBaseDir: String;
    FExtrOptions: ExtrOpts;   
{$IFNDEF NO_SPAN}
    FFreeOnAllDisks: Cardinal;
    FFreeOnDisk1: Cardinal;
{$ENDIF}
    fFromDate: TDateTime;
    FFSpecArgs: TStrings;
    FFSpecArgsExcl: TStrings;
    fHandle: HWND;
    FHowToDelete: TDeleteOpts;
    FLanguage: string;   
{$IFNDEF NO_SPAN}
    FMaxVolumeSize: Integer;
    FMinFreeVolSize: Integer;
{$ENDIF}
    fNotMainThread: Boolean;
    FPassword: String;
    FPasswordReqCount: Longword;
    FReentry: Boolean;
    FRootDir: String;
    FSFXSlave: TZipSFX;
    FSpanOptions: SpanOpts;
    FTempDir: String;
    FTrace: Boolean;
    FUnattended: Boolean;
    FUseDirOnlyEntries: Boolean;
    FVerbose: Boolean;
    FZip: TObject;
    function GetActive: Boolean;
    { Property get/set functions }
    function GetBusy: Boolean;
    function GetCancel: Boolean;
    function GetCount: Integer;
    function GetDirEntry(idx: Integer): pZipDirEntry;
    function GetDirOnlyCount: Integer;
    function GetDLL_Build: Integer;
    function GetDll_Load: Boolean;
    function GetDll_Path: string;
    function GetDll_Version: String;
    function GetErrCode: Integer;
    function GetErrMessage: String;
    function GetFullErrCode: Integer;
    function GetIsSpanned: Boolean;
    function GetLanguage: string;
    function GetOnCheckTerminate: TCheckTerminateEvent;
    function GetOnCopyZipOverwrite: TCopyZipOverwriteEvent;
    function GetOnCRC32Error: TCRC32ErrorEvent;
    function GetOnDirUpdate: TNotifyEvent;
    function GetOnExtractOverwrite: TExtractOverwriteEvent;
    function GetOnExtractSkipped: TExtractSkippedEvent;
    function GetOnFileComment: TFileCommentEvent;
    function GetOnFileExtra: TFileExtraEvent;
{$IFNDEF NO_SPAN}
    function GetOnGetNextDisk: TGetNextDiskEvent;
{$ENDIF}
    function GetOnItemProgress: TItemProgressEvent;
    function GetOnMessage: TMessageEvent;
    function GetOnNewName: TNewNameEvent;
    function GetOnPasswordError: TPasswordErrorEvent;
    function GetOnProgress: TProgressEvent;
    function GetOnProgressDetails: TProgressDetailsEvent;
    function GetOnSetAddName: TSetAddNameEvent;
    function GetOnSetExtName: TSetExtNameEvent;
    function GetOnSetNewName: TSetNewNameEvent;
{$IFNDEF NO_SPAN}
    function GetOnStatusDisk: TStatusDiskEvent;
{$ENDIF}
    function GetOnTick: TTickEvent;
    function GetOnTotalProgress: TTotalProgressEvent;
    function GetOnZipDialog: TZipDialogEvent;
    function GetPPassword: String;
    function GetRealFileSize: Cardinal;
{$IFDEF INTERNAL_SFX}
    function GetSFXCaption: String;
    function GetSFXCommandLine: String;
    function GetSFXDefaultDir: String;
    function GetSFXIcon: TIcon;
    function GetSFXMessage: String;
{$ENDIF}
    function GetSFXOffset: Integer;
{$IFDEF INTERNAL_SFX}
    function GetSFXOptions: TSFXOptions;
    function GetSFXOverWriteMode: OvrOpts;
    function GetSFXPath: TFileName;
{$ENDIF}
    function GetSuccessCnt: Integer;
    function GetTotalSizeToProcess: Int64;
    function GetUnzBusy: Boolean;
    function GetBuild: Integer;
    function GetEntry(const Name:String): pZipDirEntry;
    function GetLanguageInfo(Index: Integer; info: cardinal): string;
    function GetVersion: String;
    function GetZipBusy: Boolean;
    function GetZipComment: String;
    function GetZipContents: TList;
    function GetZipEOC: Cardinal;
    function GetZipFileName: String;
    function GetZipSOC: Cardinal;
    function GetZipStream: TZipStream; 
{$IFDEF KEEP_BACKWARD}
    function GetUnzVers: Integer;
    function GetZipVers: Integer;
{$ENDIF}
    procedure SetActive(Value: Boolean);
    procedure SetCancel(Value: Boolean);
    procedure SetDll_Load(const Value: Boolean);
    procedure SetErrCode(Value: Integer);
    procedure SetFileName(Value: String);
    procedure SetFSpecArgs(const Value: TStrings);
    procedure SetFSpecArgsExcl(const Value: TStrings);
    procedure SetLanguage(const Value: string);
    procedure SetOnCheckTerminate(const Value: TCheckTerminateEvent);
    procedure SetOnCopyZipOverwrite(const Value: TCopyZipOverwriteEvent);
    procedure SetOnCRC32Error(const Value: TCRC32ErrorEvent);
    procedure SetOnDirUpdate(const Value: TNotifyEvent);
    procedure SetOnExtractOverwrite(const Value: TExtractOverwriteEvent);
    procedure SetOnExtractSkipped(const Value: TExtractSkippedEvent);
    procedure SetOnFileComment(const Value: TFileCommentEvent);
    procedure SetOnFileExtra(const Value: TFileExtraEvent);
{$IFNDEF NO_SPAN}
    procedure SetOnGetNextDisk(const Value: TGetNextDiskEvent);
{$ENDIF}
    procedure SetOnItemProgress(const Value: TItemProgressEvent);
    procedure SetOnMessage(const Value: TMessageEvent);
    procedure SetOnNewName(const Value: TNewNameEvent);
    procedure SetOnPasswordError(const Value: TPasswordErrorEvent);
    procedure SetOnProgress(const Value: TProgressEvent);
    procedure SetOnProgressDetails(const Value: TProgressDetailsEvent);
    procedure SetOnSetAddName(const Value: TSetAddNameEvent);
    procedure SetOnSetExtName(const Value: TSetExtNameEvent);
    procedure SetOnSetNewName(const Value: TSetNewNameEvent);
{$IFNDEF NO_SPAN}
    procedure SetOnStatusDisk(const Value: TStatusDiskEvent);
{$ENDIF}
    procedure SetOnTick(const Value: TTickEvent);
    procedure SetOnTotalProgress(const Value: TTotalProgressEvent);
    procedure SetOnZipDialog(const Value: TZipDialogEvent);
    procedure SetPassword(Value: String);
    procedure SetPasswordReqCount(Value: Longword);
{$IFDEF INTERNAL_SFX}
    procedure SetSFXCaption(Value: String);
    procedure SetSFXCommandLine(Value: String);
    procedure SetSFXDefaultDir(Value: String);
    procedure SetSFXIcon(Value: TIcon);
    procedure SetSFXMessage(Value: String);
    procedure SetSFXOptions(Value: TSFXOptions);
    procedure SetSFXOverWriteMode(Value: OvrOpts);
    procedure SetSFXPath(Value: TFilename);
{$ENDIF}
{$IFNDEF INTERNAL_SFX}
    procedure SetSFXSlave(Value: TZipSFX);
{$ENDIF}
    procedure SetVersion(Value: String);
    procedure SetZipComment(Value: String);
  PROTECTED
    function CanStart: Boolean;
    procedure Done;
{$IFNDEF INTERNAL_SFX}
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); OVERRIDE;
{$ENDIF}
    function Starting: Integer;
    function Stopped: Boolean;
    property Active: Boolean read GetActive write SetActive default True;
    property AddCompLevel: Integer READ FAddCompLevel WRITE FAddCompLevel;
    property AddFrom: TDateTime READ fFromDate WRITE fFromDate;
    property AddOptions: AddOpts READ FAddOptions WRITE fAddOptions;
    property AddStoreSuffixes: AddStoreExts
      READ FAddStoreSuffixes WRITE FAddStoreSuffixes;   
    property Build: Integer read GetBuild;
    property Busy: Boolean READ GetBusy;
    property Cancel: Boolean READ GetCancel WRITE SetCancel;
    property CodePage: CodePageOpts
      READ FCodePage WRITE FCodePage DEFAULT cpAuto;
{$IFNDEF NO_SPAN}
    property ConfirmErase: Boolean
      READ fConfirmErase WRITE fConfirmErase DEFAULT True;
{$ENDIF}
    property Count: Integer READ GetCount;
    property DirEntry[idx: Integer]: pZipDirEntry READ GetDirEntry; DEFAULT;
    property DirOnlyCount: Integer READ GetDirOnlyCount;
    property DLLDirectory: String READ FDLLDirectory WRITE FDLLDirectory;
    property DLL_Build: Integer read GetDLL_Build;
    property Dll_Load: Boolean read GetDll_Load write SetDll_Load;
    property Dll_Path: string read GetDll_Path;
    property Dll_Version: String read GetDll_Version;
    property Entry[const Name:String]: pZipDirEntry read GetEntry;
    property ErrCode: Integer READ GetErrCode WRITE SetErrCode;
    property ExtAddStoreSuffixes: String
      READ fExtAddStoreSuffixes WRITE FExtAddStoreSuffixes nodefault;
    property ExtrBaseDir: String READ FExtrBaseDir WRITE FExtrBaseDir;
    property ExtrOptions: ExtrOpts READ FExtrOptions WRITE FExtrOptions;
    property FSpecArgs: TStrings READ fFSpecArgs WRITE SetFSpecArgs;
    property FSpecArgsExcl: TStrings
      READ fFSpecArgsExcl WRITE SetFSpecArgsExcl;
    property FullErrCode: Integer READ GetFullErrCode;
    property Handle: HWND READ FHandle WRITE FHandle;
    property HowToDelete: TDeleteOpts
      READ FHowToDelete WRITE FHowToDelete DEFAULT htdAllowUndo;
    property IsSpanned: Boolean READ GetIsSpanned;
{$IFNDEF NO_SPAN}
    property KeepFreeOnAllDisks: Cardinal
      READ FFreeOnAllDisks WRITE FFreeOnAllDisks;
    property KeepFreeOnDisk1: Cardinal READ FFreeOnDisk1 WRITE FFreeOnDisk1;  
{$ENDIF}
    property Language: string read GetLanguage write SetLanguage;  
    property LanguageInfo[Index: Integer; info: cardinal]: string read GetLanguageInfo; 
{$IFNDEF NO_SPAN}
    property MaxVolumeSize: Integer READ FMaxVolumeSize WRITE FMaxVolumesize;
{$ENDIF}
    property Message: String READ GetErrMessage;    
{$IFNDEF NO_SPAN}
    property MinFreeVolumeSize: Integer READ FMinFreeVolSize
      WRITE FMinFreeVolSize DEFAULT 65536;
{$ENDIF}
    property NotMainThread: Boolean READ fNotMainThread WRITE fNotMainThread;
    property Password: String READ GetPPassword WRITE SetPassword;
    property PasswordReqCount: Longword
      READ FPasswordReqCount WRITE SetPasswordReqCount DEFAULT 1;
    property RootDir: String READ FRootDir WRITE fRootDir;
{$IFDEF INTERNAL_SFX}
    property SFXCaption: String READ GetSFXCaption WRITE SetSFXCaption;
    property SFXCommandLine: String READ GetSFXCommandLine
      WRITE SetSFXCommandLine;
    property SFXDefaultDir: String READ GetSFXDefaultDir
      WRITE SetSFXDefaultDir;
    property SFXIcon: TIcon READ GetSFXIcon WRITE SetSFXIcon;
    property SFXMessage: String READ GetSFXMessage WRITE SetSFXMessage;
{$ENDIF}
    property SFXOffset: Integer READ GetSFXOffset;
{$IFDEF INTERNAL_SFX}
    property SFXOptions: TSFXOptions READ GetSFXOptions WRITE SetSFXOptions;
    property SFXOverWriteMode: OvrOpts
      READ GetSFXOverWriteMode WRITE SetSFXOverWriteMode;
    property SFXPath: TFilename READ GetSFXPath WRITE SetSFXPath;
{$ENDIF}
{$IFNDEF INTERNAL_SFX}
    property SFXSlave: TZipSFX READ FSFXSlave WRITE SetSFXSlave;
{$ENDIF}
    property SpanOptions: SpanOpts READ FSpanOptions WRITE FSpanOptions;
    property SuccessCnt: Integer READ GetSuccessCnt;
    property TempDir: String READ FTempDir WRITE FTempDir;
    property TotalSizeToProcess: Int64 READ GetTotalSizeToProcess;
    property Trace: Boolean READ FTrace WRITE FTrace;
    property Unattended: Boolean READ FUnattended WRITE FUnattended; 
    property UnzBusy: Boolean READ GetUnzBusy;
    property UseDirOnlyEntries: Boolean
      READ FUseDirOnlyEntries WRITE FUseDirOnlyEntries DEFAULT False;
    property Verbose: Boolean READ FVerbose WRITE FVerbose;
    property Version: String read GetVersion write SetVersion;  
    property VersionInfo: String read GetVersion write SetVersion;
    property ZipBusy: Boolean READ GetZipBusy;
    property ZipComment: String READ GetZipComment WRITE SetZipComment;
    property ZipContents: TList READ GetZipContents;
    property ZipEOC: Cardinal READ GetZipEOC;
    { At runtime: every time the filename is assigned a value,
   the ZipDir will automatically be read. }
    property ZipFileName: String READ GetZipFileName WRITE SetFileName;
    property ZipFileSize: Cardinal READ GetRealFileSize;
    property ZipSOC: Cardinal READ GetZipSOC;
    property ZipStream: TZipStream READ GetZipStream; 
{$IFDEF KEEP_BACKWARD}
    property UnzVers: Integer READ GetUnzVers;
    property ZipVers: Integer READ GetZipVers;
{$ENDIF}
    { Events }
    property OnCheckTerminate: TCheckTerminateEvent
      READ GetOnCheckTerminate WRITE SetOnCheckTerminate;
    property OnCopyZipOverwrite: TCopyZipOverwriteEvent
      READ GetOnCopyZipOverwrite WRITE SetOnCopyZipOverwrite;
    property OnCRC32Error: TCRC32ErrorEvent
      READ GetOnCRC32Error WRITE SetOnCRC32Error;
    property OnDirUpdate: TNotifyEvent
      READ GetOnDirUpdate WRITE SetOnDirUpdate;
    property OnExtractOverwrite: TExtractOverwriteEvent
      READ GetOnExtractOverwrite WRITE SetOnExtractOverwrite;
    property OnExtractSkipped: TExtractSkippedEvent
      READ GetOnExtractSkipped WRITE SetOnExtractSkipped;
    property OnFileComment: TFileCommentEvent
      READ GetOnFileComment WRITE SetOnFileComment;
    property OnFileExtra: TFileExtraEvent
      READ GetOnFileExtra WRITE SetOnFileExtra;
{$IFNDEF NO_SPAN}
    property OnGetNextDisk: TGetNextDiskEvent
      READ GetOnGetNextDisk WRITE SetOnGetNextDisk;
{$ENDIF}
    property OnItemProgress: TItemProgressEvent
      READ GetOnItemProgress WRITE SetOnItemProgress;
    property OnMessage: TMessageEvent READ GetOnMessage WRITE SetOnMessage;
    property OnNewName: TNewNameEvent READ GetOnNewName WRITE SetOnNewName;
    property OnPasswordError: TPasswordErrorEvent
      READ GetOnPasswordError WRITE SetOnPasswordError;
    property OnProgress: TProgressEvent READ GetOnProgress WRITE SetOnProgress;
    property OnProgressDetails: TProgressDetailsEvent
      READ GetOnProgressDetails WRITE SetOnProgressDetails;
    property OnSetAddName: TSetAddNameEvent
      READ GetOnSetAddName WRITE SetOnSetAddName;
    property OnSetExtName: TSetExtNameEvent
      READ GetOnSetExtName WRITE SetOnSetExtName;
    property OnSetNewName: TSetNewNameEvent
      READ GetOnSetNewName WRITE SetOnSetNewName;
{$IFNDEF NO_SPAN}
    property OnStatusDisk: TStatusDiskEvent
      READ GetOnStatusDisk WRITE SetOnStatusDisk;
{$ENDIF}
    property OnTick: TTickEvent READ GetOnTick WRITE SetOnTick;
    property OnTotalProgress: TTotalProgressEvent
      READ GetOnTotalProgress WRITE SetOnTotalProgress;
    property OnZipDialog: TZipDialogEvent
      READ GetOnZipDialog WRITE SetOnZipDialog;
  PUBLIC
    constructor Create(AOwner: TComponent); OVERRIDE;
    destructor Destroy; OVERRIDE;
    procedure AbortDll;
    function Add: Integer;
    function AddStreamToFile(Filename: String;
      FileDate, FileAttr: Dword): Integer;
    function AddStreamToStream(InStream: TMemoryStream): TZipStream;
    procedure AfterConstruction; override;
    function AppendSlash(sDir: String): String;
    procedure BeforeDestruction; OVERRIDE;
    procedure Clear;
    function ConvertSFX: Integer;
    function ConvertZIP: Integer;
    function CopyZippedFiles(DestZipMaster: TCustomZipMaster;
      DeleteFromSource: Boolean; OverwriteDest: OvrOpts): Integer;
    function Copy_File(const InFileName, OutFileName: String): Integer;
    function Delete: Integer;
//    procedure EnumLanguages(dest: TStrings; info: Cardinal);
    function EraseFile(const Fname: String; How: TDeleteOpts): Integer;
    function Extract: Integer;
    function ExtractFileToStream(Filename: String): TZipStream;
    function ExtractStreamToStream(InStream: TMemoryStream;
      OutSize: Longword): TZipStream;
    function Find(const fspec: String; var idx: Integer): pZipDirEntry; overload;
    function Find(const FileName: String): pZipDirEntry; overload;
    function FullVersionString: String;
    function GetAddPassword: String; OVERLOAD;
    function GetAddPassword(var Response: TPasswordButton): String; OVERLOAD;
    function GetExtrPassword: String; OVERLOAD;
    function GetExtrPassword(var Response: TPasswordButton): String; OVERLOAD;
    function GetPassword(DialogCaption, MsgTxt: String;
      pwb: TPasswordButtons; var ResultStr: String): TPasswordButton;
    function IndexOf(const fname: String): Integer;
    function IsZipSFX(const SFXExeName: String): Integer;
    function List: Integer;
    procedure Loaded; OVERRIDE;
    function MakeTempFileName(Prefix, Extension: String): String;
    function NewSFXFile(const ExeName: String): Integer;
    function QueryZip(const fname: TFileName): Integer;
{$IFNDEF NO_SPAN}
    function ReadSpan(InFileName: String; var OutFilePath: String): Integer;
{$ENDIF}
    //1  changed 1.79.10.07
    function Rename(RenameList: TList; DateTime: Integer; How: TZMRenameOpts =
        htrDefault): Integer;
    procedure ShowExceptionError(const ZMExcept: EZipMaster);
    procedure ShowZipFmtMessage(Id: Integer; const Args: array of const);
    procedure ShowZipMessage(Ident: Integer; UserStr: String);
    function TheErrorCode(errCode: Integer): Integer;
{$IFNDEF NO_SPAN}
    function WriteSpan(InFileName, OutFileName: String): Integer;
{$ENDIF}                         
{$IFDEF KEEP_BACKWARD}      
    function Load_Unz_Dll: Integer; OVERLOAD;
    function Load_Unz_Dll(silent: Boolean): Integer; OVERLOAD;
    function Load_Zip_Dll: Integer; OVERLOAD;
    function Load_Zip_Dll(silent: Boolean): Integer; OVERLOAD;
    procedure Unload_Unz_Dll;
    procedure Unload_Zip_Dll;
    function UnzDllPath: String;
    function ZipDllPath: String;
{$ENDIF}
  published
  end;

  //type
  TZipMaster = class (TCustomZipMaster)
  PRIVATE
  PUBLIC           
    property Build;
    property Busy;
    property Cancel;
    property Count;
    property DirEntry;
    property DirOnlyCount;
    property DLL_Build;
    property Dll_Path;
    property Dll_Version;
    property ErrCode;
    property FullErrCode;
    property Handle;
    property IsSpanned;
    property LanguageInfo;
    property Message;
    property NotMainThread;
    property SFXOffset;
    property SuccessCnt;
    property TotalSizeToProcess;  
    property UnzBusy;
    property ZipBusy;
    property ZipComment;
    property ZipContents;
    property ZipEOC;
    property ZipFileSize;
    property ZipSOC;
    property ZipStream;
{$IFDEF KEEP_BACKWARD}
    property UnzVers;
    property ZipVers;
{$ENDIF}
  PUBLISHED
    property Active DEFAULT True;
    property AddCompLevel DEFAULT 9;
    property AddFrom;
    property AddOptions;
    property AddStoreSuffixes;
    property CodePage;
{$IFNDEF NO_SPAN}
    property ConfirmErase;
{$ENDIF}
    property Dll_Load;
    property DLLDirectory;
    property ExtAddStoreSuffixes;
    property ExtrBaseDir;
    property ExtrOptions;
    property FSpecArgs;
    property FSpecArgsExcl;
    property HowToDelete;
{$IFNDEF NO_SPAN}
    property KeepFreeOnAllDisks;
    property KeepFreeOnDisk1;
{$ENDIF}
    property Language;
{$IFNDEF NO_SPAN}
    property MaxVolumeSize;
    property MinFreeVolumeSize DEFAULT 65536;
{$ENDIF}
    property Password;
    property PasswordReqCount DEFAULT 3;
//    property PrefLang;
    property RootDir;
{$IFDEF INTERNAL_SFX}
    property SFXCaption;
    property SFXCommandLine;
    property SFXDefaultDir;
    property SFXIcon;
    property SFXMessage;
    property SFXOptions;
    property SFXOverWriteMode;
    property SFXPath;
{$ENDIF}
{$IFNDEF INTERNAL_SFX}
    property SFXSlave;
{$ENDIF}
{$IFNDEF NO_SPAN}
    property SpanOptions;
{$ENDIF}
    property TempDir;
    property Trace;
    property Unattended;
    property UseDirOnlyEntries;
    property Verbose;
    property Version;
    property VersionInfo;
    property ZipFileName;
    property OnCheckTerminate;
{$IFNDEF NO_SPAN}
    property OnGetNextDisk;
{$ENDIF}
    property OnItemProgress;
    property OnMessage;
    property OnProgress;
    property OnProgressDetails;
    property OnTick;
    property OnTotalProgress;
    property OnZipDialog;
    property OnCopyZipOverwrite;
    property OnCRC32Error;
    property OnDirUpdate;
    property OnExtractOverwrite;
    property OnExtractSkipped;
    property OnFileComment;
    property OnFileExtra;
    property OnNewName;
    property OnPasswordError;
    property OnSetAddName;
    property OnSetExtName;
    property OnSetNewName;
{$IFNDEF NO_SPAN}
    property OnStatusDisk;
{$ENDIF}
  end;

  // default file extensions that are best 'stored'
const
  DefAddStoreSuffixes = [assGIF..assEXE, assJPG..ass7zp, assMP3..assAVI];

procedure Register;

implementation

uses
  ZMUtils, ZMCore, ZMDlg, ZMCtx, ZMWrkr;

const
  MAX_PERCENT = MAXINT div 10000;

//const
//  RESOURCE_ERROR: String =
//    'ZipMsgXX.res is probably not linked to the executable' +
//    #10 + 'Missing String ID is: %d ';
     
procedure Register;
begin
  RegisterComponents('Delphi Zip', [TZipMaster]);
end;

  {TProgressDetails}
function TProgressDetails.GetItemPerCent: Integer;
begin
  if (ItemSize > 0) and (ItemPosition > 0) then
    if ItemSize < MAX_PERCENT then
      Result := (100 * ItemPosition) div ItemSize
    else
      Result := ItemPosition div (ItemSize div 100)
  else
    Result := 0;
end;

function TProgressDetails.GetTotalPerCent: Integer;
begin
  if (TotalSize > 0) and (TotalPosition > 0) then
    Result := (100 * TotalPosition) div TotalSize
  else
    Result := 0;
end;

destructor TProgressDetails.Destroy;
begin
  FItemName := '';
  inherited;
end;

 {TCustomZipMaster}

procedure TCustomZipMaster.AbortDll;
begin
  TZMWorker(fZip).AbortDll;
end;

function TCustomZipMaster.Add: Integer;
begin
  Result := Starting;
  if Result = 0 then
    try
      Result := TZMWorker(fZip).Add;
    finally
      Done;
    end;
end;

function TCustomZipMaster.AddStreamToFile(Filename: String;
  FileDate, FileAttr: Dword): Integer;
begin
  Result := Starting;
  if Result = 0 then
    try
      Result := TZMWorker(fZip).AddStreamToFile(Filename,
        FileDate, FileAttr);
    finally
      Done;
    end;
end;

function TCustomZipMaster.AddStreamToStream(InStream: TMemoryStream):
TZipStream;
begin
  Result := Nil;
  if Starting = 0 then
    try
      Result := TZMWorker(fZip).AddStreamToStream(InStream);
    finally
      Done;
    end;
end;

function TCustomZipMaster.AppendSlash(sDir: String): String;
begin
  Result := DelimitPath(sDir, True);
end;

procedure TCustomZipMaster.BeforeDestruction;
begin
  if assigned(FZip) then
    TZMWorker(fZip).Active := False;
  inherited;
end;

function TCustomZipMaster.CanStart: Boolean;
begin
  if (csDesigning in ComponentState) or (csLoading in ComponentState) then
    Result := False
  else
    Result := (Active and Stopped);
end;

procedure TCustomZipMaster.Clear;
begin
  if CanStart then
  begin
    TZMWorker(fZip).Clear;
    Done;
    FReentry := False;
  end;
end;

function TCustomZipMaster.ConvertSFX: Integer;
begin
  Result := BUSY_ERROR;
  if CanStart then
    Result := TZMWorker(fZip).ConvertSFX;
end;

function TCustomZipMaster.ConvertZIP: Integer;
begin
  Result := BUSY_ERROR;
  if CanStart then
    Result := TZMWorker(fZip).ConvertZIP;
end;

function TCustomZipMaster.Copy_File(
  const InFileName, OutFileName: String): Integer;
begin
  Result := Starting;
  if Result = 0 then
    try
      Result := TZMWorker(fZip).Copy_File(InFileName, OutFileName);
    finally
      Done;
    end;
end;

function TCustomZipMaster.CopyZippedFiles(DestZipMaster: TCustomZipMaster;
  DeleteFromSource: Boolean; OverwriteDest: OvrOpts): Integer;
var
  t: TCustomZipMaster;
begin
  t := nil;
  Result := Starting;
  if Result = 0 then
    try
      Result := DestZipMaster.Starting;
      if Result = 0 then
      begin
        t := DestZipMaster;
        Result := TZMWorker(fZip).CopyZippedFiles(TZMWorker(DestZipMaster.fZip),
          DeleteFromSource, OverwriteDest);
      end;
    finally
      if t <> nil then
        t.Done;
      Done;
    end;
end;

constructor TCustomZipMaster.Create(AOwner: TComponent);
begin
  inherited;
  FZip := TZMWorker.Create(Self);
  FActive := 0;
  FBusy := False;
  fNotMainThread := False;
  FFSpecArgs := TStringList.Create;
  FFSpecArgsExcl := TStringList.Create;
  FAddCompLevel := 9;         // deflt to tightest compression
  FAddStoreSuffixes := DefAddStoreSuffixes;
  FCodePage := cpAuto;
  FEncrypt := False;
{$IFNDEF NO_SPAN}
  FFreeOnAllDisks := 0;       //  use all space
  FFreeOnDisk1 := 0;          // Don't leave any freespace on disk 1.
  FMaxVolumeSize := 0;        // Use the maximum disk size.
  FMinFreeVolSize := 65536;   // Reject disks with less free bytes than...
{$ENDIF}
  FFromDate := 0;
  fHandle := Application.Handle;
  FHowToDelete := htdAllowUndo;
  FPassword := '';
  FPasswordReqCount := 1;
  FSpanOptions := [];
  FUnattended := False;
  FUseDirOnlyEntries := False;
{$IFNDEF NO_SPAN}
  fConfirmErase := True;
{$ENDIF}
  { events - cleared in TObject constructor }
//{$IFDEF INTERNAL_SFX}
//  FSFXSlave := TZipSFX.Create(self);
//{$ELSE}
  FSFXSlave := Nil;
//{$ENDIF}
(*  TZMWorker(fZip).SFXSlave := FSFXSlave;
  if csDesigning in ComponentState then
    FActive := 3
  else
  if csLoading in ComponentState then
    FActive := 2
  else
  begin
    FActive := 1;
    TZMWorker(fZip).Active := True;
  end;  *)
end;

function TCustomZipMaster.Delete: Integer;
begin
  Result := Starting;
  if Result = 0 then
    try
      Result := TZMWorker(fZip).Delete;
    finally
      Done;
    end;
end;

destructor TCustomZipMaster.Destroy;
begin
  FreeAndNil(FZip);
  FreeAndNil(FFSpecArgs);
  FreeAndNil(FFSpecArgsExcl);
  inherited;
end;

procedure TCustomZipMaster.AfterConstruction;
begin
  inherited;
{$IFDEF INTERNAL_SFX}
  FSFXSlave := TZipSFX.Create(self);
//{$ELSE}
//  FSFXSlave := Nil;
{$ENDIF}
  TZMWorker(fZip).SFXSlave := FSFXSlave;
  if csDesigning in ComponentState then
    FActive := 3
  else
  if csLoading in ComponentState then
    FActive := 2
  else
  begin
    FActive := 1;
    TZMWorker(fZip).Active := True;
  end;
end;

procedure TCustomZipMaster.Done;
var
  z: TZMWorker;
begin
  z := FZip as TZMWorker;
  z.Done;
  fBusy := False;
  if z.Reentry then
    fReentry := True;
  FFSpecArgs.Assign(z.FSpecArgs);
  FFSpecArgsExcl.Assign(z.FSpecArgsExcl); 
  if FActive < 0 then
  begin
    FActive := 0;
    z.Active := false;
  end;
end;
  {
procedure TCustomZipMaster.EnumLanguages(dest: TStrings; info: Cardinal);
begin
  EnumZipMsgLanguages(dest, info);
end;}

function TCustomZipMaster.EraseFile(const Fname: String;
  How: TDeleteOpts): Integer;
begin
  Result := ZMUtils.EraseFile(Fname, How = htdFinal);
end;

function TCustomZipMaster.Extract: Integer;
begin
  Result := Starting;
  if Result = 0 then
    try
      Result := TZMWorker(fZip).Extract;
    finally
      Done;
    end;
end;

function TCustomZipMaster.ExtractFileToStream(Filename: String): TZipStream;
begin
  Result := Nil;
  if Starting = 0 then
    try
      Result := TZMWorker(fZip).ExtractFileToStream(Filename);
    finally
      Done;
    end;
end;

function TCustomZipMaster.ExtractStreamToStream(InStream: TMemoryStream;
  OutSize: Longword): TZipStream;
begin
  Result := Nil;
  if Starting = 0 then
    try
      Result := TZMWorker(fZip).ExtractStreamToStream(InStream, OutSize);
    finally
      Done;
    end;
end;

function TCustomZipMaster.Find(const fspec: String;
  var idx: Integer): pZipDirEntry;   
var
  c: Integer;
begin
  if idx < 0 then
    idx := -1;
  c := pred(Count);
  while idx < c do
  begin
    Inc(idx);
    Result := DirEntry[idx];
    if FileNameMatch(fspec, Result.FileName) then
      exit;
  end;
  idx := -1;
  Result := Nil;
end;

function TCustomZipMaster.Find(const FileName: String): pZipDirEntry;
var
  idx: Integer;
begin
  if Active then
  begin
    idx := -1;
    if (AnsiPos('*', FileName) >0) or (AnsiPos('?', FileName) > 0) then
      Result := Find(FileName, idx)
    else
      Result := TZMWorker(fZip).DirHashs.Find(FileName);
  end
  else
    Result := Nil;
end;

function TCustomZipMaster.FullVersionString: String;
begin
  Result := 'ZipMaster ' + Version;
{$IFDEF NO_SPAN}
  Result := Result + ' -SPAN ';
{$ELSE}
  Result := Result + ' ';
{$ENDIF}
  Result := Result + ' ,SFX = ';
  if assigned(TZMWorker(fZip).SFXSlave) then
    Result := Result + TZipSFX(TZMWorker(fZip).SFXSlave).Version
  else
    Result := Result + 'none';
  Result := Result + ', DLL ' + DLL_Version;
end;

function TCustomZipMaster.GetActive: Boolean;
begin
  Result := FActive <> 0;
end;

function TCustomZipMaster.GetAddPassword: String;
var
  Resp: TPasswordButton;
begin
  Result := TZMWorker(fZip).GetAddPassword(Resp);
end;

function TCustomZipMaster.GetAddPassword(
  var Response: TPasswordButton): String;
begin
  Result := TZMWorker(fZip).GetAddPassword(Response);
end;

function TCustomZipMaster.GetBusy: Boolean;
begin
  Result := FBusy;
end;

function TCustomZipMaster.GetCancel: Boolean;
begin
  Result := TZMWorker(fZip).Cancel;
end;

function TCustomZipMaster.GetCount: Integer;
begin
  if Active then
    Result := TZMWorker(fZip).Count
  else
    Result := 0;
end;

function TCustomZipMaster.GetDirEntry(idx: Integer): pZipDirEntry;
begin
  if Active then
    Result := TZMWorker(fZip)[idx]
  else
    Result := Nil;
end;

function TCustomZipMaster.GetDirOnlyCount: Integer;
begin
  Result := TZMWorker(fZip).DirOnlyCount;
end;

function TCustomZipMaster.GetDLL_Build: Integer; 
begin
  Result := 0;
  if fBusy then
    Result := TZMWorker(fzip).Dll_Build
  else
  begin
    try
      if Starting = 0 then
        Result := TZMWorker(fzip).Dll_Build;
    finally
      Done;
    end;
  end;
end;

function TCustomZipMaster.GetDll_Load: Boolean;
begin                                  
  if (csDesigning in ComponentState) or (csLoading in ComponentState) then
    Result := fDllLoad
  else
    Result := TZMWorker(fzip).Dll_Load;
end;

function TCustomZipMaster.GetDll_Path: string;
begin
//  Result := '';
//  if TZMWorker(fzip).Dll_Load then
//    Result := TZMWorker(fzip).Dll_Path;
  Result := '';
  if fBusy then
    Result := TZMWorker(fzip).Dll_Path
  else
  begin
    try
      if Starting = 0 then
        Result := TZMWorker(fzip).Dll_Path;
    finally
      Done;
    end;
  end;
end;

function TCustomZipMaster.GetDll_Version: String;
begin
  Result := '';
  if fBusy then
  begin
    Result := TZMWorker(fzip).Dll_Version;
  end
  else
  begin
    try
      if Starting = 0 then
        Result := TZMWorker(fzip).Dll_Version;
    finally
      Done;
    end;
  end;
end;

function TCustomZipMaster.GetErrCode: Integer;
begin
  Result := TZMWorker(fZip).ErrCode;
  if FReentry then
    Result := Result or Reentry_Error
  else
  if not Active then
    Result := GE_Inactive;
end;

function TCustomZipMaster.GetErrMessage: String;
begin
  if Active then
    Result := TZMWorker(fZip).Message
  else
    Result := ZipLoadStr(GE_Inactive);
  if FReentry then
    Result := ZipFmtLoadStr(GE_WasBusy, [Result]);
end;

function TCustomZipMaster.GetExtrPassword: String;
var
  Resp: TPasswordButton;
begin
  Result := TZMWorker(fZip).GetExtrPassword(Resp);
end;

function TCustomZipMaster.GetExtrPassword(
  var Response: TPasswordButton): String;
begin
  Result := TZMWorker(fZip).GetExtrPassword(Response);
end;

function TCustomZipMaster.GetFullErrCode: Integer;
begin
  Result := TZMWorker(fZip).FullErrCode;
end;

function TCustomZipMaster.GetIsSpanned: Boolean;
begin
  Result := TZMWorker(fZip).IsSpanned;
end;

function TCustomZipMaster.GetLanguage: string;
begin
  if (csDesigning in ComponentState) or (csLoading in ComponentState) then
    Result := fLanguage
  else
    Result := GetZipMsgLanguage(0);//-1);
end;

function TCustomZipMaster.GetOnCheckTerminate: TCheckTerminateEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnCheckTerminate;
end;

function TCustomZipMaster.GetOnCopyZipOverwrite: TCopyZipOverwriteEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnCopyZipOverwrite;
end;

function TCustomZipMaster.GetOnCRC32Error: TCRC32ErrorEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnCRC32Error;
end;

function TCustomZipMaster.GetOnDirUpdate: TNotifyEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnDirUpdate;
end;

function TCustomZipMaster.GetOnExtractOverwrite: TExtractOverwriteEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnExtractOverwrite;
end;

function TCustomZipMaster.GetOnExtractSkipped: TExtractSkippedEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnExtractSkipped;
end;

function TCustomZipMaster.GetOnFileComment: TFileCommentEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnFileComment;
end;

function TCustomZipMaster.GetOnFileExtra: TFileExtraEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnFileExtra;
end;

{$IFNDEF NO_SPAN}
function TCustomZipMaster.GetOnGetNextDisk: TGetNextDiskEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnGetNextDisk;
end;
{$ENDIF}

function TCustomZipMaster.GetOnItemProgress: TItemProgressEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnItemProgress;
end;

function TCustomZipMaster.GetOnMessage: TMessageEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnMessage;
end;

function TCustomZipMaster.GetOnNewName: TNewNameEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnNewName;
end;

function TCustomZipMaster.GetOnPasswordError: TPasswordErrorEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnPasswordError;
end;

function TCustomZipMaster.GetOnProgress: TProgressEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnProgress;
end;

function TCustomZipMaster.GetOnProgressDetails: TProgressDetailsEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnProgressDetails;
end;

function TCustomZipMaster.GetOnSetAddName: TSetAddNameEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnSetAddName;
end;

function TCustomZipMaster.GetOnSetExtName: TSetExtNameEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnSetExtName;
end;

function TCustomZipMaster.GetOnSetNewName: TSetNewNameEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnSetNewName;
end;

{$IFNDEF NO_SPAN}
function TCustomZipMaster.GetOnStatusDisk: TStatusDiskEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnStatusDisk;
end;
{$ENDIF}

function TCustomZipMaster.GetOnTick: TTickEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnTick;
end;

function TCustomZipMaster.GetOnTotalProgress: TTotalProgressEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnTotalProgress;
end;

function TCustomZipMaster.GetOnZipDialog: TZipDialogEvent;
begin
  Result := TZMCore(fZip).EventsRec^.OnZipDialog;
end;

function TCustomZipMaster.GetPassword(DialogCaption, MsgTxt: String;
  pwb: TPasswordButtons; var ResultStr: String): TPasswordButton;
begin
  Result := TZMWorker(fZip).GetPassword(DialogCaption, MsgTxt,
    pwb, ResultStr);
end;

function TCustomZipMaster.GetPPassword: String;
begin
  Result := TZMWorker(fZip).Password;
end;

function TCustomZipMaster.GetRealFileSize: Cardinal;
begin
  Result := TZMWorker(fZip).ZipFileSize;
end;

{$IFDEF INTERNAL_SFX}
function TCustomZipMaster.GetSFXCaption: String;
begin
  Result := FSFXSlave.DialogTitle;
end;
{$ENDIF}

{$IFDEF INTERNAL_SFX}
function TCustomZipMaster.GetSFXCommandLine: String;
begin
  Result := FSFXSlave.CommandLine;
end;
{$ENDIF}

{$IFDEF INTERNAL_SFX}
function TCustomZipMaster.GetSFXDefaultDir: String;
begin
  Result := FSFXSlave.DefaultExtractPath;
end;
{$ENDIF}

{$IFDEF INTERNAL_SFX}
function TCustomZipMaster.GetSFXIcon: TIcon;
begin
  Result := FSFXSlave.Icon;
end;
{$ENDIF}

{$IFDEF INTERNAL_SFX}
function TCustomZipMaster.GetSFXMessage: String;
begin
  Result := FSFXSlave.Message;
end;
{$ENDIF}

function TCustomZipMaster.GetSFXOffset: Integer;
begin
  Result := TZMWorker(fZip).SFXOffset;
end;

{$IFDEF INTERNAL_SFX}
function TCustomZipMaster.GetSFXOptions: TSFXOptions;
begin
    Result := FSFXSlave.Options;
end;
{$ENDIF}

{$IFDEF INTERNAL_SFX}
function TCustomZipMaster.GetSFXOverWriteMode: OvrOpts;
begin
    Result := OvrOpts(FSFXSlave.OverWriteMode);
end;
{$ENDIF}

{$IFDEF INTERNAL_SFX}
function TCustomZipMaster.GetSFXPath: TFilename;
begin
  Result := FSFXSlave.SFXPath;
end;
{$ENDIF}

function TCustomZipMaster.GetSuccessCnt: Integer;
begin
  Result := TZMWorker(fZip).SuccessCnt;
end;

function TCustomZipMaster.GetTotalSizeToProcess: Int64;
begin
  Result := TZMWorker(fZip).TotalSizeToProcess;
end;

function TCustomZipMaster.GetUnzBusy: Boolean;
begin
  Result := TZMWorker(fZip).UnzBusy;
end;

function TCustomZipMaster.GetVersion: String;
begin
  Result := ZIPMASTERBUILD;
end;

function TCustomZipMaster.GetBuild: Integer;
begin
  Result := ZIPMASTERPRIV;
end;

function TCustomZipMaster.GetEntry(const Name:String): pZipDirEntry;
begin
  Result := Find(Name);
end;

function TCustomZipMaster.GetLanguageInfo(Index: Integer; info: cardinal): string;
begin
  Result := GetZipMsgLanguageInfo(index, info);
end;

function TCustomZipMaster.GetZipBusy: Boolean;
begin
  Result := TZMWorker(fZip).ZipBusy;
end;

function TCustomZipMaster.GetZipComment: String;
begin
  Result := TZMWorker(fZip).ZipComment;
end;

function TCustomZipMaster.GetZipContents: TList;
begin
  Result := TZMWorker(fZip).ZipContents;
end;

function TCustomZipMaster.GetZipEOC: Cardinal;
begin
  Result := TZMWorker(fZip).ZipEOC;
end;

function TCustomZipMaster.GetZipFileName: String;
begin
  Result := TZMWorker(fZip).ZipFileName;
end;

function TCustomZipMaster.GetZipSOC: Cardinal;
begin
  Result := TZMWorker(fZip).ZipSOC;
end;

function TCustomZipMaster.GetZipStream: TZipStream;
begin
  Result := TZMWorker(fZip).ZipStream;
end;

function TCustomZipMaster.IndexOf(const fname: String): Integer;
begin  
  for Result := 0 to pred(Count) do
    if FileNameMatch(fname, DirEntry[Result].FileName) then
      exit;
  Result := -1;
end;

function TCustomZipMaster.IsZipSFX(const SFXExeName: String): Integer;
begin
  {  Result   := BUSY_ERROR;
    if  Stopped then }
  Result := TZMWorker(fZip).IsZipSFX(SFXExeName);
end;

function TCustomZipMaster.List: Integer;
begin
  Result := Starting;
  if Result = 0 then
    try
      Result := TZMWorker(fZip).List;
    finally
      Done;
    end;
end;
           
{$IFDEF KEEP_BACKWARD}
function TCustomZipMaster.Load_Unz_Dll(silent: Boolean): Integer;
begin
  Result := Load_Zip_dll(silent);
end;
{$ENDIF}
            
{$IFDEF KEEP_BACKWARD}
function TCustomZipMaster.Load_Unz_Dll: Integer;
begin
  Result := Load_Zip_dll(False);
end;
{$ENDIF}
            
{$IFDEF KEEP_BACKWARD}
function TCustomZipMaster.Load_Zip_Dll(silent: Boolean): Integer;
begin
  Result := Starting;
  if Result = 0 then
    try
      TZMWorker(fZip).Dll_Load := true;
      Result := TZMWorker(fZip).Dll_Build div 10000;
      if (not silent) and (Result <> DELZIPVERSION) then
        raise EZipMaster.CreateResDrive(LD_BadDll, Dll_Path);
    finally
      Done;
    end;
end;
{$ENDIF}

{$IFDEF KEEP_BACKWARD}
function TCustomZipMaster.Load_Zip_Dll: Integer;
begin
  Result := Load_Zip_Dll(False);
end;
{$ENDIF}

procedure TCustomZipMaster.Loaded;
begin
  inherited;
  if not (csDesigning in ComponentState) then
  begin
    SetZipMsgLanguage(fLanguage);
//    TZMWorker(fZip).PrefLang := fPrefLang;
    if Active and (Starting = 0) then
      try
        TZMWorker(fZip).Active := True;
      finally
        Done;
      end
    else
      TZMWorker(fZip).Active := False;
  end;
end;

function TCustomZipMaster.MakeTempFileName(Prefix, Extension: String): String;
begin
  Result := TZMWorker(fZip).MakeTempFileName(Prefix, Extension);
end;

function TCustomZipMaster.NewSFXFile(const ExeName: String): Integer;
begin
  Result := BUSY_ERROR;
  if CanStart then
    Result := TZMWorker(fZip).NewSFXFile(ExeName);
end;

{$IFNDEF INTERNAL_SFX}
procedure TCustomZipMaster.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  if (Operation = opRemove) and (AComponent = FSFXSlave) then
    FSFXSlave := Nil;
  inherited;
end;
{$ENDIF}

function TCustomZipMaster.QueryZip(const fname: TFileName): Integer;
begin
  Result := ZMUtils.QueryZip(fname);
end;

{$IFNDEF NO_SPAN}
function TCustomZipMaster.ReadSpan(InFileName: String;
  var OutFilePath: String): Integer;
begin
  Result := Starting;
  if Result = 0 then
    try
      Result := TZMWorker(fZip).ReadSpan(InFileName, OutFilePath, False);
    finally
      Done;
    end;
end;
{$ENDIF}

function TCustomZipMaster.Rename(RenameList: TList; DateTime: Integer; How:
    TZMRenameOpts = htrDefault): Integer;
begin
  Result := Starting;
  if Result = 0 then
    try
      Result := TZMWorker(fZip).Rename(RenameList, DateTime, How);
    finally
      Done;
    end;
end;

procedure TCustomZipMaster.SetActive(Value: Boolean);
var
  was: integer;
begin
  was := FActive;
  FActive := 0;
  if csDesigning in ComponentState then
  begin
    if value then
      FActive := 3;   // set but ignored
  end
  else
  if csLoading in ComponentState then
  begin
    if value then
      FActive := 2;   // loaded will act on it
  end
  else
  if fBusy then
  begin
    if value then
      FActive := 1
    else
      FActive := -1;  // done will clear it
  end
  else  // not busy or loading or designing
  begin
    if Value then
    begin
      FActive := 1;
      if (was = 0) and (Starting = 0) then
      begin
        try
          TZMWorker(fZip).Active := True;
        finally
          Done;
        end;
      end
      else
        TZMWorker(fZip).Active := False;
    end
    else
      TZMWorker(fZip).Active := False;
  end;
end;

procedure TCustomZipMaster.SetCancel(Value: Boolean);
begin
  TZMWorker(fZip).Cancel := Value;
end;

procedure TCustomZipMaster.SetDll_Load(const Value: Boolean);
begin
  if Value <> Dll_Load then
  begin
    fDllLoad := Value;       // will be applied when Active is set
    if Active and fBusy then
    begin
      TZMWorker(fzip).Dll_Load := Value;
      fDllLoad := TZMWorker(fzip).Dll_Load;    // true if it loaded
    end
    else
    begin
      try
        if Starting = 0 then
        begin
          fDllLoad := TZMWorker(fzip).Dll_Load;   // true if it loaded
        end;
      finally
        Done;
      end;
    end;
  end; 
end;

procedure TCustomZipMaster.SetErrCode(Value: Integer);
begin
  if Stopped then
    TZMWorker(fZip).ErrCode := Value;
end;

// 1.79.06.03 RP fix won't set in designer
procedure TCustomZipMaster.SetFileName(Value: String);
begin
  if not Active or (csDesigning in ComponentState) or (csLoading in ComponentState) then
  begin
    TZMWorker(fZip).Active := False;             // stop any actions
    TZMWorker(fZip).ZipFileName := Value;
  end
  else
  if Starting = 0 then
    try
      TZMWorker(fZip).ZipFileName := Value;
    finally
      Done;
    end;
end;

procedure TCustomZipMaster.SetFSpecArgs(const Value: TStrings);
begin
  fFSpecArgs.Assign(Value);
end;

procedure TCustomZipMaster.SetFSpecArgsExcl(const Value: TStrings);
begin
  fFSpecArgsExcl.Assign(Value);
end;

procedure TCustomZipMaster.SetLanguage(const Value: string);
begin
  if (csDesigning in ComponentState) or (csLoading in ComponentState) then
    fLanguage := Value
  else
    SetZipMsgLanguage(Value);
end;

procedure TCustomZipMaster.SetOnCheckTerminate(
  const Value: TCheckTerminateEvent);
begin
  TZMCore(fZip).EventsRec^.OnCheckTerminate := Value;
end;

procedure TCustomZipMaster.SetOnCopyZipOverwrite(
  const Value: TCopyZipOverwriteEvent);
begin
  TZMCore(fZip).EventsRec^.OnCopyZipOverwrite := Value;
end;

procedure TCustomZipMaster.SetOnCRC32Error(const Value: TCRC32ErrorEvent);
begin
  TZMCore(fZip).EventsRec^.OnCRC32Error := Value;
end;

procedure TCustomZipMaster.SetOnDirUpdate(const Value: TNotifyEvent);
begin
  TZMCore(fZip).EventsRec^.OnDirUpdate := Value;
end;

procedure TCustomZipMaster.SetOnExtractOverwrite(
  const Value: TExtractOverwriteEvent);
begin
  TZMCore(fZip).EventsRec^.OnExtractOverwrite := Value;
end;

procedure TCustomZipMaster.SetOnExtractSkipped(
  const Value: TExtractSkippedEvent);
begin
  TZMCore(fZip).EventsRec^.OnExtractSkipped := Value;
end;

procedure TCustomZipMaster.SetOnFileComment(const Value: TFileCommentEvent);
begin
  TZMCore(fZip).EventsRec^.OnFileComment := Value;
end;

procedure TCustomZipMaster.SetOnFileExtra(const Value: TFileExtraEvent);
begin
  TZMCore(fZip).EventsRec^.OnFileExtra := Value;
end;
 
{$IFNDEF NO_SPAN}
procedure TCustomZipMaster.SetOnGetNextDisk(const Value: TGetNextDiskEvent);
begin
  TZMCore(fZip).EventsRec^.OnGetNextDisk := Value;
end;
{$ENDIF}

procedure TCustomZipMaster.SetOnItemProgress(const Value: TItemProgressEvent);
begin
  TZMCore(fZip).EventsRec^.OnItemProgress := Value;
end;

procedure TCustomZipMaster.SetOnMessage(const Value: TMessageEvent);
begin
  TZMCore(fZip).EventsRec^.OnMessage := Value;
end;

procedure TCustomZipMaster.SetOnNewName(const Value: TNewNameEvent);
begin
  TZMCore(fZip).EventsRec^.OnNewName := Value;
end;

procedure TCustomZipMaster.SetOnPasswordError(
  const Value: TPasswordErrorEvent);
begin
  TZMCore(fZip).EventsRec^.OnPasswordError := Value;
end;

procedure TCustomZipMaster.SetOnProgress(const Value: TProgressEvent);
begin
  TZMCore(fZip).EventsRec^.OnProgress := Value;
end;

procedure TCustomZipMaster.SetOnProgressDetails(
  const Value: TProgressDetailsEvent);
begin
  TZMCore(fZip).EventsRec^.OnProgressDetails := Value;
end;

procedure TCustomZipMaster.SetOnSetAddName(const Value: TSetAddNameEvent);
begin
  TZMCore(fZip).EventsRec^.OnSetAddName := Value;
end;

procedure TCustomZipMaster.SetOnSetExtName(const Value: TSetExtNameEvent);
begin
  TZMCore(fZip).EventsRec^.OnSetExtName := Value;
end;

procedure TCustomZipMaster.SetOnSetNewName(const Value: TSetNewNameEvent);
begin
  TZMCore(fZip).EventsRec^.OnSetNewName := Value;
end;
      
{$IFNDEF NO_SPAN}
procedure TCustomZipMaster.SetOnStatusDisk(const Value: TStatusDiskEvent);
begin
  TZMCore(fZip).EventsRec^.OnStatusDisk := Value;
end;
{$ENDIF}

procedure TCustomZipMaster.SetOnTick(const Value: TTickEvent);
begin
  TZMCore(fZip).EventsRec^.OnTick := Value;
end;

procedure TCustomZipMaster.SetOnTotalProgress(
  const Value: TTotalProgressEvent);
begin
  TZMCore(fZip).EventsRec^.OnTotalProgress := Value;
end;

procedure TCustomZipMaster.SetOnZipDialog(const Value: TZipDialogEvent);
begin
  TZMCore(fZip).EventsRec^.OnZipDialog := Value;
end;
   
procedure TCustomZipMaster.SetPassword(Value: String);
begin
  {  if Stopped then}
  TZMWorker(fZip).Password := Value;
end;

procedure TCustomZipMaster.SetPasswordReqCount(Value: Longword);
begin
  if Value <> FPasswordReqCount then
  begin
    if Value > 15 then
      Value := 15;
    FPasswordReqCount := Value;
  end; 
end;
 {
procedure TCustomZipMaster.SetPrefLang(const Value: TZipMsgLanguages);
begin
  FPrefLang := Value;
  RequestZipMsgLanguage(Value);
end;}

{$IFDEF INTERNAL_SFX}
procedure TCustomZipMaster.SetSFXCaption(Value: String);
begin
  {  if Stopped then}
  FSFXSlave.DialogTitle := Value;
end;
{$ENDIF}

{$IFDEF INTERNAL_SFX}
procedure TCustomZipMaster.SetSFXCommandLine(Value: String);
begin
  {  if Stopped then}
  FSFXSlave.CommandLine := Value;
end;
{$ENDIF}

{$IFDEF INTERNAL_SFX}
procedure TCustomZipMaster.SetSFXDefaultDir(Value: String);
begin
  {  if Stopped then}
  FSFXSlave.DefaultExtractPath := Value;
end;
{$ENDIF}

{$IFDEF INTERNAL_SFX}
procedure TCustomZipMaster.SetSFXIcon(Value: TIcon);
begin
  {  if Stopped then}
   FSFXSlave.Icon := Value;
end;
{$ENDIF}

{$IFDEF INTERNAL_SFX}
procedure TCustomZipMaster.SetSFXMessage(Value: String);
begin
  {  if Stopped then begin }
  FSFXSlave.MessageFlags := MB_OK;
  if Value <> '' then
    case Value[1] of
      #1:
      begin
         FSFXSlave.MessageFlags :=
          MB_OKCANCEL or MB_ICONINFORMATION;
        System.Delete(Value, 1, 1);
      end;
      #2:
      begin
        FSFXSlave.MessageFlags := MB_YESNO or MB_ICONQUESTION;
        System.Delete(Value, 1, 1);
      end;
    end;
  FSFXSlave.Message := Value;
  //  end;
end;
{$ENDIF}

{$IFDEF INTERNAL_SFX}
procedure TCustomZipMaster.SetSFXOptions(Value: TSFXOptions);
begin
  {  if Stopped then}
   FSFXSlave.Options := Value;
end;
{$ENDIF}

{$IFDEF INTERNAL_SFX}
procedure TCustomZipMaster.SetSFXOverWriteMode(Value: OvrOpts);
begin
   FSFXSlave.OverWriteMode := TSFXOverwriteMode(Value);
end;
{$ENDIF}

{$IFDEF INTERNAL_SFX}
procedure TCustomZipMaster.SetSFXPath(Value: TFilename);
begin
  {  if Stopped then}
  FSFXSlave.SFXPath := Value;
end;
{$ENDIF}

(*? TCustomZipMaster.SetSFXSlave
1.79 9 AUG 2005 Force slave to notify of destruction
*)
{$IFNDEF INTERNAL_SFX}
procedure TCustomZipMaster.SetSFXSlave(Value: TZipSFX);
var
  tmpSlave: TZipSFX;
begin
  if (csDestroying in ComponentState) then
  begin
    FSFXSlave := Value;
    exit;
  end;
  if ((csDesigning in ComponentState) or
    (csLoading in ComponentState) or (Active and Stopped)) and
    (Value <> FSFXSlave) then
  begin
    tmpSlave := FSFXSlave;
    if assigned(tmpSlave) then
    begin
  {$IFDEF VERD6up}
      tmpSlave.RemoveFreeNotification(self);
  {$ENDIF}
      FSFXSlave := Nil;
    end;
    FSFXSlave := Value;
    if assigned(Value) then
    begin
      Value.FreeNotification(self);
    end;
    if assigned(fZip) then
      TZMWorker(fZip).SFXSlave := Value;
  end;
end;
{$ENDIF}

procedure TCustomZipMaster.SetVersion(Value: String);
begin
  //    FZip.VersionInfo := Value;
end;
                                                     
// 1.79.06.03 RP fix won't set in designer
procedure TCustomZipMaster.SetZipComment(Value: String);
begin
  if not Active or (csDesigning in ComponentState) or (csLoading in ComponentState) then
  begin
    TZMWorker(fZip).Active := False;             // stop any actions
    TZMWorker(fZip).ZipComment := Value;
  end
  else
  if Starting = 0 then
    try
      TZMWorker(fZip).ZipComment := Value;
    finally
      Done;
    end;
end;

procedure TCustomZipMaster.ShowExceptionError(const ZMExcept: EZipMaster);
begin
  TZMWorker(fZip).ShowExceptionError(ZMExcept);
end;

procedure TCustomZipMaster.ShowZipMessage(Ident: Integer; UserStr: String);
begin
  TZMWorker(fZip).ShowZipMessage(Ident, UserStr);
end;

(*? TCustomZipMaster.ShowZipFmtMessage
1.79 added
*)
procedure TCustomZipMaster.ShowZipFmtMessage(Id: Integer;
  const Args: array of const);
begin
  TZMWorker(fZip).ShowZipFmtMessage(Id, Args);
end;

function TCustomZipMaster.Starting: Integer;
var
  z: TZMWorker;
begin
  Result := 0;
  if (csDesigning in ComponentState) or (csLoading in ComponentState) then
    Result := -256
  else
  if not (Active and Stopped) then
    Result := BUSY_ERROR;
  if Result = 0 then
    try
      z := FZip as TZMWorker;
      z.ErrCode := 0;
      z.SFXSlave := FSFXSlave;
{$IFNDEF NO_SPAN}
      z.KeepFreeOnAllDisks := KeepFreeOnAllDisks;
      z.KeepFreeOnDisk1 := KeepFreeOnDisk1;
      z.MaxVolumeSize := MaxVolumeSize;
      z.MinFreeVolumeSize := MinFreeVolumeSize;
      z.SpanOptions := SpanOptions;
      z.ConfirmErase := ConfirmErase;
{$ENDIF}
      z.AddCompLevel := AddCompLevel;
      z.AddFrom := AddFrom;
      z.AddOptions := AddOptions;
      z.AddStoreSuffixes := AddStoreSuffixes;
      z.ExtAddStoreSuffixes := ExtAddStoreSuffixes;
      z.CodePage := CodePage;
      z.ExtrBaseDir := ExtrBaseDir;
      z.ExtrOptions := ExtrOptions;
      z.Unattended := Unattended;
      z.Verbose := Verbose;
      z.Trace := Trace;
      z.NotMainTask := NotMainThread;
      z.FSpecArgs.Assign(FSpecArgs);
      z.FSpecArgsExcl.Assign(FSpecArgsExcl);
      z.Handle := Handle;
      z.HowToDelete := HowToDelete;
      z.Password := Password;
      z.PasswordReqCount := PasswordReqCount;
      z.Unattended := Unattended;
      z.UseDirOnlyEntries := UseDirOnlyEntries;
      z.RootDir := RootDir;
      z.DLLDirectory := DLLDirectory;
      z.TempDir := TempDir; 
      z.Active := true;
      z.Starting;
      fReentry := False;
      fBusy := True;   
      z.Dll_Load := fDLLLoad;
    except
      on E: EZipMaster do
      begin
        ShowExceptionError(E);
        Result := e.FResIdent;
      end;
      on E: Exception do
      begin
        //      ShowZipFmtMessage(GE_UnknownExc, E.Message);  // 'Unknown exception: %s'
        Result := -9; //?
      end;
    end;
end;

function TCustomZipMaster.Stopped: Boolean;
begin
  if not fBusy then
    Result := True
  else
  begin
    Result := False;
    fReentry := True;
    TZMWorker(fZip).Attacked(self);
  end;
end;

function TCustomZipMaster.TheErrorCode(errCode: Integer): Integer;
begin
  Result := errCode and (Reentry_Error - 1);
end;
      
{$IFDEF KEEP_BACKWARD}
procedure TCustomZipMaster.Unload_Unz_Dll;
begin
  Unload_Zip_Dll; 
end;
{$ENDIF}
       
{$IFDEF KEEP_BACKWARD}
procedure TCustomZipMaster.Unload_Zip_Dll;
begin
//  if CanStart then
    TZMWorker(fZip).Dll_Load := false;
end;
{$ENDIF}
        
{$IFDEF KEEP_BACKWARD}
function TCustomZipMaster.UnzDllPath: String;
begin
  Result := TZMWorker(fZip).Dll_Path;
end;
{$ENDIF}

{$IFNDEF NO_SPAN}
function TCustomZipMaster.WriteSpan(InFileName, OutFileName: String): Integer;
begin
  Result := Starting;
  if Result = 0 then
    try
      Result := TZMWorker(fZip).WriteSpan(InFileName, OutFileName, False);
    finally
      Done;
    end;
end;
{$ENDIF}
     
{$IFDEF KEEP_BACKWARD}
function TCustomZipMaster.ZipDllPath: String;
begin
  Result := TZMWorker(fZip).Dll_Path;
end;
{$ENDIF}

{$IFDEF KEEP_BACKWARD}
function TCustomZipMaster.GetUnzVers: Integer;
begin
  if not Busy then
    TZMWorker(fZip).DLLDirectory := DLLDirectory;
  Result := TZMWorker(fZip).Dll_Build div 10000;
end;
{$ENDIF}

{$IFDEF KEEP_BACKWARD}
function TCustomZipMaster.GetZipVers: Integer;
begin 
  Result := GetUnzVers;
end;

{$ENDIF}

{TZipStream}
constructor TZipStream.Create;
begin
  inherited Create;
  Clear();
end;

destructor TZipStream.Destroy;
begin
  inherited Destroy;
end;

  (*
procedure TZipStream.SetPointer(Ptr: Pointer; Size: Integer);
begin
  inherited SetPointer(Ptr, Size);
end;
    *)

end.

