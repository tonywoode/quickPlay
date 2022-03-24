// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Zipmstr.pas' rev: 10.00

#ifndef ZipmstrHPP
#define ZipmstrHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Zipsfx.hpp>	// Pascal unit
#include <Sfxinterface.hpp>	// Pascal unit
#include <Zmxcpt.hpp>	// Pascal unit
#include <Zipmsg.hpp>	// Pascal unit
#include <Zmmsgstr.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Zipmstr
{
//-- type declarations -------------------------------------------------------
typedef __int64 LargeInt;

typedef Dialogs::TMsgDlgBtn TPasswordButton;

typedef TMsgDlgButtons TPasswordButtons;
;

#pragma option push -b-
enum AddOptsEnum { AddDirNames, AddRecurseDirs, AddMove, AddFreshen, AddUpdate, AddZipTime, AddForceDOS, AddHiddenFiles, AddArchiveOnly, AddResetArchive, AddEncrypt, AddSeparateDirs, AddVolume, AddFromDate, AddSafe, AddForceDest, AddDiskSpan, AddDiskSpanErase };
#pragma option pop

typedef Set<AddOptsEnum, AddDirNames, AddDiskSpanErase>  AddOpts;

#pragma option push -b-
enum SpanOptsEnum { spNoVolumeName, spCompatName, spWipeFiles, spTryFormat };
#pragma option pop

typedef Set<SpanOptsEnum, spNoVolumeName, spTryFormat>  SpanOpts;

#pragma option push -b-
enum AddStoreSuffixEnum { assGIF, assPNG, assZ, assZIP, assZOO, assARC, assLZH, assARJ, assTAZ, assTGZ, assLHA, assRAR, assACE, assCAB, assGZ, assGZIP, assJAR, assEXE, assEXT, assJPG, assJPEG, ass7Zp, assMP3, assWMV, assWMA, assDVR, assAVI };
#pragma option pop

typedef Set<AddStoreSuffixEnum, assGIF, assAVI>  AddStoreExts;

#pragma option push -b-
enum ExtrOptsEnum { ExtrDirNames, ExtrOverWrite, ExtrFreshen, ExtrUpdate, ExtrTest, ExtrForceDirs };
#pragma option pop

typedef Set<ExtrOptsEnum, ExtrDirNames, ExtrForceDirs>  ExtrOpts;

#pragma option push -b-
enum OvrOpts { OvrAlways, OvrNever, OvrConfirm };
#pragma option pop

#pragma option push -b-
enum ReplaceOpts { rplConfirm, rplAlways, rplNewer, rplNever };
#pragma option pop

#pragma option push -b-
enum TZMRenameOpts { htrDefault, htrOnce, htrFull };
#pragma option pop

#pragma option push -b-
enum TDeleteOpts { htdFinal, htdAllowUndo };
#pragma option pop

#pragma option push -b-
enum CodePageOpts { cpAuto, cpNone, cpOEM };
#pragma option pop

#pragma option push -b-
enum CodePageDirection { cpdOEM2ISO, cpdISO2OEM };
#pragma option pop

#pragma option push -b-
enum UnZipSkipTypes { stOnFreshen, stNoOverwrite, stFileExists, stBadPassword, stNoEncryptionDLL, stCompressionUnknown, stUnknownZipHost, stZipFileFormatWrong, stGeneralExtractError };
#pragma option pop

#pragma option push -b-
enum ZipDiskStatusEnum { zdsEmpty, zdsHasFiles, zdsPreviousDisk, zdsSameFileName, zdsNotEnoughSpace };
#pragma option pop

typedef Set<ZipDiskStatusEnum, zdsEmpty, zdsNotEnoughSpace>  TZipDiskStatus;

#pragma option push -b-
enum TZipDiskAction { zdaYesToAll, zdaOk, zdaErase, zdaReject, zdaCancel };
#pragma option pop

typedef __int64 TProgressSize;

#pragma option push -b-
enum ProgressType { NewFile, ProgressUpdate, EndOfBatch, TotalFiles2Process, TotalSize2Process, NewExtra, ExtraUpdate };
#pragma option pop

class DELPHICLASS TProgressDetails;
#pragma pack(push,1)
class PASCALIMPLEMENTATION TProgressDetails : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	ProgressType FProgType;
	int FItemCount;
	__int64 FWritten;
	__int64 FTotalSize;
	__int64 FTotalPosition;
	unsigned FItemSize;
	unsigned FItemPosition;
	AnsiString FItemName;
	int FItemNumber;
	int __fastcall GetItemPerCent(void);
	int __fastcall GetTotalPerCent(void);
	
public:
	__fastcall virtual ~TProgressDetails(void);
	__property int ItemPerCent = {read=GetItemPerCent, nodefault};
	__property int TotalPerCent = {read=GetTotalPerCent, nodefault};
	__property ProgressType Order = {read=FProgType, nodefault};
	__property int TotalCount = {read=FItemCount, nodefault};
	__property __int64 BytesWritten = {read=FWritten};
	__property __int64 TotalSize = {read=FTotalSize};
	__property __int64 TotalPosition = {read=FTotalPosition};
	__property unsigned ItemSize = {read=FItemSize, nodefault};
	__property unsigned ItemPosition = {read=FItemPosition, nodefault};
	__property AnsiString ItemName = {read=FItemName};
	__property int ItemNumber = {read=FItemNumber, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TProgressDetails(void) : System::TObject() { }
	#pragma option pop
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct ZipDirEntry
{
	
public:
	Byte MadeByVersion;
	Byte HostVersionNo;
	Word Version;
	Word Flag;
	Word CompressionMethod;
	int DateTime;
	int CRC32;
	unsigned CompressedSize;
	unsigned UncompressedSize;
	Word FileNameLength;
	Word ExtraFieldLength;
	Word FileCommentLen;
	Word StartOnDisk;
	Word IntFileAttrib;
	unsigned ExtFileAttrib;
	unsigned RelOffLocalHdr;
	AnsiString FileName;
	AnsiString FileComment;
	bool Encrypted;
	AnsiString ExtraData;
} ;
#pragma pack(pop)

typedef ZipDirEntry *pZipDirEntry;

struct ZipRenameRec;
typedef ZipRenameRec *pZipRenameRec;

#pragma pack(push,1)
struct ZipRenameRec
{
	
public:
	AnsiString Source;
	AnsiString Dest;
	AnsiString Comment;
	int DateTime;
} ;
#pragma pack(pop)

typedef void __fastcall (__closure *TCheckTerminateEvent)(System::TObject* Sender, bool &abort);

typedef void __fastcall (__closure *TCopyZipOverwriteEvent)(System::TObject* Sender, AnsiString ForFile, bool &DoOverwrite);

typedef void __fastcall (__closure *TCRC32ErrorEvent)(System::TObject* Sender, AnsiString ForFile, unsigned FoundCRC, unsigned ExpectedCRC, bool &DoExtract);

typedef void __fastcall (__closure *TExtractOverwriteEvent)(System::TObject* Sender, AnsiString ForFile, bool IsOlder, bool &DoOverwrite, int DirIndex);

typedef void __fastcall (__closure *TExtractSkippedEvent)(System::TObject* Sender, AnsiString ForFile, UnZipSkipTypes SkipType, int ExtError);

typedef void __fastcall (__closure *TFileCommentEvent)(System::TObject* Sender, AnsiString ForFile, AnsiString &FileComment, bool &IsChanged);

typedef void __fastcall (__closure *TFileExtraEvent)(System::TObject* Sender, AnsiString ForFile, AnsiString &Data, bool &IsChanged);

typedef void __fastcall (__closure *TGetNextDiskEvent)(System::TObject* Sender, int DiskSeqNo, int DiskTotal, AnsiString Drive, bool &AbortAction);

typedef void __fastcall (__closure *TItemProgressEvent)(System::TObject* Sender, AnsiString Item, unsigned TotalSize, int PerCent);

typedef void __fastcall (__closure *TMessageEvent)(System::TObject* Sender, int ErrCode, AnsiString Message);

typedef void __fastcall (__closure *TNewNameEvent)(System::TObject* Sender, int SeqNo, const ZipDirEntry &ZipEntry);

typedef void __fastcall (__closure *TPasswordErrorEvent)(System::TObject* Sender, bool IsZipAction, AnsiString &NewPassword, AnsiString ForFile, unsigned &RepeatCount, Dialogs::TMsgDlgBtn &Action);

typedef void __fastcall (__closure *TProgressDetailsEvent)(System::TObject* Sender, TProgressDetails* details);

typedef void __fastcall (__closure *TProgressEvent)(System::TObject* Sender, ProgressType ProgrType, AnsiString Filename, __int64 FileSize);

typedef void __fastcall (__closure *TSetAddNameEvent)(System::TObject* Sender, AnsiString &FileName, const AnsiString ExtName, bool &IsChanged);

typedef void __fastcall (__closure *TSetExtNameEvent)(System::TObject* Sender, AnsiString &FileName, bool &IsChanged);

typedef void __fastcall (__closure *TSetNewNameEvent)(System::TObject* Sender, AnsiString &OldFileName, bool &IsChanged);

typedef void __fastcall (__closure *TStatusDiskEvent)(System::TObject* Sender, int PreviousDisk, AnsiString PreviousFile, TZipDiskStatus Status, TZipDiskAction &Action);

typedef void __fastcall (__closure *TTickEvent)(System::TObject* Sender);

typedef void __fastcall (__closure *TTotalProgressEvent)(System::TObject* Sender, __int64 TotalSize, int PerCent);

typedef void __fastcall (__closure *TZipDialogEvent)(System::TObject* Sender, const AnsiString title, AnsiString &msg, int &Result, Dialogs::TMsgDlgButtons btns);

typedef void __fastcall (__closure *TZipStrEvent)(int Ident, AnsiString &DefStr);

class DELPHICLASS TZipStream;
#pragma pack(push,1)
class PASCALIMPLEMENTATION TZipStream : public Classes::TMemoryStream 
{
	typedef Classes::TMemoryStream inherited;
	
public:
	__fastcall TZipStream(void);
	__fastcall virtual ~TZipStream(void);
};

#pragma pack(pop)

typedef TSFXOptions SFXOpts;
;

class DELPHICLASS TCustomZipMaster;
#pragma pack(push,1)
class PASCALIMPLEMENTATION TCustomZipMaster : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
public:
	pZipDirEntry operator[](int idx) { return DirEntry[idx]; }
	
private:
	int FActive;
	int FAddCompLevel;
	AddOpts fAddOptions;
	AddStoreExts FAddStoreSuffixes;
	bool FBusy;
	CodePageOpts FCodePage;
	bool FConfirmErase;
	AnsiString FDLLDirectory;
	bool fDllLoad;
	bool FEncrypt;
	AnsiString fExtAddStoreSuffixes;
	AnsiString fExtrBaseDir;
	ExtrOpts FExtrOptions;
	unsigned FFreeOnAllDisks;
	unsigned FFreeOnDisk1;
	System::TDateTime fFromDate;
	Classes::TStrings* FFSpecArgs;
	Classes::TStrings* FFSpecArgsExcl;
	HWND fHandle;
	TDeleteOpts FHowToDelete;
	AnsiString FLanguage;
	int FMaxVolumeSize;
	int FMinFreeVolSize;
	bool fNotMainThread;
	AnsiString FPassword;
	unsigned FPasswordReqCount;
	bool FReentry;
	AnsiString FRootDir;
	Zipsfx::TZipSFX* FSFXSlave;
	SpanOpts FSpanOptions;
	AnsiString FTempDir;
	bool FTrace;
	bool FUnattended;
	bool FUseDirOnlyEntries;
	bool FVerbose;
	System::TObject* FZip;
	bool __fastcall GetActive(void);
	bool __fastcall GetBusy(void);
	bool __fastcall GetCancel(void);
	int __fastcall GetCount(void);
	pZipDirEntry __fastcall GetDirEntry(int idx);
	int __fastcall GetDirOnlyCount(void);
	int __fastcall GetDLL_Build(void);
	bool __fastcall GetDll_Load(void);
	AnsiString __fastcall GetDll_Path();
	AnsiString __fastcall GetDll_Version();
	int __fastcall GetErrCode(void);
	AnsiString __fastcall GetErrMessage();
	int __fastcall GetFullErrCode(void);
	bool __fastcall GetIsSpanned(void);
	AnsiString __fastcall GetLanguage();
	TCheckTerminateEvent __fastcall GetOnCheckTerminate();
	TCopyZipOverwriteEvent __fastcall GetOnCopyZipOverwrite();
	TCRC32ErrorEvent __fastcall GetOnCRC32Error();
	Classes::TNotifyEvent __fastcall GetOnDirUpdate();
	TExtractOverwriteEvent __fastcall GetOnExtractOverwrite();
	TExtractSkippedEvent __fastcall GetOnExtractSkipped();
	TFileCommentEvent __fastcall GetOnFileComment();
	TFileExtraEvent __fastcall GetOnFileExtra();
	TGetNextDiskEvent __fastcall GetOnGetNextDisk();
	TItemProgressEvent __fastcall GetOnItemProgress();
	TMessageEvent __fastcall GetOnMessage();
	TNewNameEvent __fastcall GetOnNewName();
	TPasswordErrorEvent __fastcall GetOnPasswordError();
	TProgressEvent __fastcall GetOnProgress();
	TProgressDetailsEvent __fastcall GetOnProgressDetails();
	TSetAddNameEvent __fastcall GetOnSetAddName();
	TSetExtNameEvent __fastcall GetOnSetExtName();
	TSetNewNameEvent __fastcall GetOnSetNewName();
	TStatusDiskEvent __fastcall GetOnStatusDisk();
	TTickEvent __fastcall GetOnTick();
	TTotalProgressEvent __fastcall GetOnTotalProgress();
	TZipDialogEvent __fastcall GetOnZipDialog();
	AnsiString __fastcall GetPPassword();
	unsigned __fastcall GetRealFileSize(void);
	AnsiString __fastcall GetSFXCaption();
	AnsiString __fastcall GetSFXCommandLine();
	AnsiString __fastcall GetSFXDefaultDir();
	Graphics::TIcon* __fastcall GetSFXIcon(void);
	AnsiString __fastcall GetSFXMessage();
	int __fastcall GetSFXOffset(void);
	Sfxinterface::TSFXOptions __fastcall GetSFXOptions(void);
	OvrOpts __fastcall GetSFXOverWriteMode(void);
	AnsiString __fastcall GetSFXPath();
	int __fastcall GetSuccessCnt(void);
	__int64 __fastcall GetTotalSizeToProcess(void);
	bool __fastcall GetUnzBusy(void);
	int __fastcall GetBuild(void);
	pZipDirEntry __fastcall GetEntry(const AnsiString Name);
	AnsiString __fastcall GetLanguageInfo(int Index, unsigned info);
	AnsiString __fastcall GetVersion();
	bool __fastcall GetZipBusy(void);
	AnsiString __fastcall GetZipComment();
	Classes::TList* __fastcall GetZipContents(void);
	unsigned __fastcall GetZipEOC(void);
	AnsiString __fastcall GetZipFileName();
	unsigned __fastcall GetZipSOC(void);
	TZipStream* __fastcall GetZipStream(void);
	void __fastcall SetActive(bool Value);
	void __fastcall SetCancel(bool Value);
	void __fastcall SetDll_Load(const bool Value);
	void __fastcall SetErrCode(int Value);
	void __fastcall SetFileName(AnsiString Value);
	void __fastcall SetFSpecArgs(const Classes::TStrings* Value);
	void __fastcall SetFSpecArgsExcl(const Classes::TStrings* Value);
	void __fastcall SetLanguage(const AnsiString Value);
	void __fastcall SetOnCheckTerminate(const TCheckTerminateEvent Value);
	void __fastcall SetOnCopyZipOverwrite(const TCopyZipOverwriteEvent Value);
	void __fastcall SetOnCRC32Error(const TCRC32ErrorEvent Value);
	void __fastcall SetOnDirUpdate(const Classes::TNotifyEvent Value);
	void __fastcall SetOnExtractOverwrite(const TExtractOverwriteEvent Value);
	void __fastcall SetOnExtractSkipped(const TExtractSkippedEvent Value);
	void __fastcall SetOnFileComment(const TFileCommentEvent Value);
	void __fastcall SetOnFileExtra(const TFileExtraEvent Value);
	void __fastcall SetOnGetNextDisk(const TGetNextDiskEvent Value);
	void __fastcall SetOnItemProgress(const TItemProgressEvent Value);
	void __fastcall SetOnMessage(const TMessageEvent Value);
	void __fastcall SetOnNewName(const TNewNameEvent Value);
	void __fastcall SetOnPasswordError(const TPasswordErrorEvent Value);
	void __fastcall SetOnProgress(const TProgressEvent Value);
	void __fastcall SetOnProgressDetails(const TProgressDetailsEvent Value);
	void __fastcall SetOnSetAddName(const TSetAddNameEvent Value);
	void __fastcall SetOnSetExtName(const TSetExtNameEvent Value);
	void __fastcall SetOnSetNewName(const TSetNewNameEvent Value);
	void __fastcall SetOnStatusDisk(const TStatusDiskEvent Value);
	void __fastcall SetOnTick(const TTickEvent Value);
	void __fastcall SetOnTotalProgress(const TTotalProgressEvent Value);
	void __fastcall SetOnZipDialog(const TZipDialogEvent Value);
	void __fastcall SetPassword(AnsiString Value);
	void __fastcall SetPasswordReqCount(unsigned Value);
	void __fastcall SetSFXCaption(AnsiString Value);
	void __fastcall SetSFXCommandLine(AnsiString Value);
	void __fastcall SetSFXDefaultDir(AnsiString Value);
	void __fastcall SetSFXIcon(Graphics::TIcon* Value);
	void __fastcall SetSFXMessage(AnsiString Value);
	void __fastcall SetSFXOptions(Sfxinterface::TSFXOptions Value);
	void __fastcall SetSFXOverWriteMode(OvrOpts Value);
	void __fastcall SetSFXPath(AnsiString Value);
	void __fastcall SetVersion(AnsiString Value);
	void __fastcall SetZipComment(AnsiString Value);
	
protected:
	bool __fastcall CanStart(void);
	void __fastcall Done(void);
	int __fastcall Starting(void);
	bool __fastcall Stopped(void);
	__property bool Active = {read=GetActive, write=SetActive, default=1};
	__property int AddCompLevel = {read=FAddCompLevel, write=FAddCompLevel, nodefault};
	__property System::TDateTime AddFrom = {read=fFromDate, write=fFromDate};
	__property AddOpts AddOptions = {read=fAddOptions, write=fAddOptions, nodefault};
	__property AddStoreExts AddStoreSuffixes = {read=FAddStoreSuffixes, write=FAddStoreSuffixes, nodefault};
	__property int Build = {read=GetBuild, nodefault};
	__property bool Busy = {read=GetBusy, nodefault};
	__property bool Cancel = {read=GetCancel, write=SetCancel, nodefault};
	__property CodePageOpts CodePage = {read=FCodePage, write=FCodePage, default=0};
	__property bool ConfirmErase = {read=FConfirmErase, write=FConfirmErase, default=1};
	__property int Count = {read=GetCount, nodefault};
	__property pZipDirEntry DirEntry[int idx] = {read=GetDirEntry/*, default*/};
	__property int DirOnlyCount = {read=GetDirOnlyCount, nodefault};
	__property AnsiString DLLDirectory = {read=FDLLDirectory, write=FDLLDirectory};
	__property int DLL_Build = {read=GetDLL_Build, nodefault};
	__property bool Dll_Load = {read=GetDll_Load, write=SetDll_Load, nodefault};
	__property AnsiString Dll_Path = {read=GetDll_Path};
	__property AnsiString Dll_Version = {read=GetDll_Version};
	__property pZipDirEntry Entry[AnsiString Name] = {read=GetEntry};
	__property int ErrCode = {read=GetErrCode, write=SetErrCode, nodefault};
	__property AnsiString ExtAddStoreSuffixes = {read=fExtAddStoreSuffixes, write=fExtAddStoreSuffixes};
	__property AnsiString ExtrBaseDir = {read=fExtrBaseDir, write=fExtrBaseDir};
	__property ExtrOpts ExtrOptions = {read=FExtrOptions, write=FExtrOptions, nodefault};
	__property Classes::TStrings* FSpecArgs = {read=FFSpecArgs, write=SetFSpecArgs};
	__property Classes::TStrings* FSpecArgsExcl = {read=FFSpecArgsExcl, write=SetFSpecArgsExcl};
	__property int FullErrCode = {read=GetFullErrCode, nodefault};
	__property HWND Handle = {read=fHandle, write=fHandle, nodefault};
	__property TDeleteOpts HowToDelete = {read=FHowToDelete, write=FHowToDelete, default=1};
	__property bool IsSpanned = {read=GetIsSpanned, nodefault};
	__property unsigned KeepFreeOnAllDisks = {read=FFreeOnAllDisks, write=FFreeOnAllDisks, nodefault};
	__property unsigned KeepFreeOnDisk1 = {read=FFreeOnDisk1, write=FFreeOnDisk1, nodefault};
	__property AnsiString Language = {read=GetLanguage, write=SetLanguage};
	__property AnsiString LanguageInfo[int Index][unsigned info] = {read=GetLanguageInfo};
	__property int MaxVolumeSize = {read=FMaxVolumeSize, write=FMaxVolumeSize, nodefault};
	__property AnsiString Message = {read=GetErrMessage};
	__property int MinFreeVolumeSize = {read=FMinFreeVolSize, write=FMinFreeVolSize, default=65536};
	__property bool NotMainThread = {read=fNotMainThread, write=fNotMainThread, nodefault};
	__property AnsiString Password = {read=GetPPassword, write=SetPassword};
	__property unsigned PasswordReqCount = {read=FPasswordReqCount, write=SetPasswordReqCount, default=1};
	__property AnsiString RootDir = {read=FRootDir, write=FRootDir};
	__property AnsiString SFXCaption = {read=GetSFXCaption, write=SetSFXCaption};
	__property AnsiString SFXCommandLine = {read=GetSFXCommandLine, write=SetSFXCommandLine};
	__property AnsiString SFXDefaultDir = {read=GetSFXDefaultDir, write=SetSFXDefaultDir};
	__property Graphics::TIcon* SFXIcon = {read=GetSFXIcon, write=SetSFXIcon};
	__property AnsiString SFXMessage = {read=GetSFXMessage, write=SetSFXMessage};
	__property int SFXOffset = {read=GetSFXOffset, nodefault};
	__property Sfxinterface::TSFXOptions SFXOptions = {read=GetSFXOptions, write=SetSFXOptions, nodefault};
	__property OvrOpts SFXOverWriteMode = {read=GetSFXOverWriteMode, write=SetSFXOverWriteMode, nodefault};
	__property AnsiString SFXPath = {read=GetSFXPath, write=SetSFXPath};
	__property SpanOpts SpanOptions = {read=FSpanOptions, write=FSpanOptions, nodefault};
	__property int SuccessCnt = {read=GetSuccessCnt, nodefault};
	__property AnsiString TempDir = {read=FTempDir, write=FTempDir};
	__property __int64 TotalSizeToProcess = {read=GetTotalSizeToProcess};
	__property bool Trace = {read=FTrace, write=FTrace, nodefault};
	__property bool Unattended = {read=FUnattended, write=FUnattended, nodefault};
	__property bool UnzBusy = {read=GetUnzBusy, nodefault};
	__property bool UseDirOnlyEntries = {read=FUseDirOnlyEntries, write=FUseDirOnlyEntries, default=0};
	__property bool Verbose = {read=FVerbose, write=FVerbose, nodefault};
	__property AnsiString Version = {read=GetVersion, write=SetVersion};
	__property AnsiString VersionInfo = {read=GetVersion, write=SetVersion};
	__property bool ZipBusy = {read=GetZipBusy, nodefault};
	__property AnsiString ZipComment = {read=GetZipComment, write=SetZipComment};
	__property Classes::TList* ZipContents = {read=GetZipContents};
	__property unsigned ZipEOC = {read=GetZipEOC, nodefault};
	__property AnsiString ZipFileName = {read=GetZipFileName, write=SetFileName};
	__property unsigned ZipFileSize = {read=GetRealFileSize, nodefault};
	__property unsigned ZipSOC = {read=GetZipSOC, nodefault};
	__property TZipStream* ZipStream = {read=GetZipStream};
	__property TCheckTerminateEvent OnCheckTerminate = {read=GetOnCheckTerminate, write=SetOnCheckTerminate};
	__property TCopyZipOverwriteEvent OnCopyZipOverwrite = {read=GetOnCopyZipOverwrite, write=SetOnCopyZipOverwrite};
	__property TCRC32ErrorEvent OnCRC32Error = {read=GetOnCRC32Error, write=SetOnCRC32Error};
	__property Classes::TNotifyEvent OnDirUpdate = {read=GetOnDirUpdate, write=SetOnDirUpdate};
	__property TExtractOverwriteEvent OnExtractOverwrite = {read=GetOnExtractOverwrite, write=SetOnExtractOverwrite};
	__property TExtractSkippedEvent OnExtractSkipped = {read=GetOnExtractSkipped, write=SetOnExtractSkipped};
	__property TFileCommentEvent OnFileComment = {read=GetOnFileComment, write=SetOnFileComment};
	__property TFileExtraEvent OnFileExtra = {read=GetOnFileExtra, write=SetOnFileExtra};
	__property TGetNextDiskEvent OnGetNextDisk = {read=GetOnGetNextDisk, write=SetOnGetNextDisk};
	__property TItemProgressEvent OnItemProgress = {read=GetOnItemProgress, write=SetOnItemProgress};
	__property TMessageEvent OnMessage = {read=GetOnMessage, write=SetOnMessage};
	__property TNewNameEvent OnNewName = {read=GetOnNewName, write=SetOnNewName};
	__property TPasswordErrorEvent OnPasswordError = {read=GetOnPasswordError, write=SetOnPasswordError};
	__property TProgressEvent OnProgress = {read=GetOnProgress, write=SetOnProgress};
	__property TProgressDetailsEvent OnProgressDetails = {read=GetOnProgressDetails, write=SetOnProgressDetails};
	__property TSetAddNameEvent OnSetAddName = {read=GetOnSetAddName, write=SetOnSetAddName};
	__property TSetExtNameEvent OnSetExtName = {read=GetOnSetExtName, write=SetOnSetExtName};
	__property TSetNewNameEvent OnSetNewName = {read=GetOnSetNewName, write=SetOnSetNewName};
	__property TStatusDiskEvent OnStatusDisk = {read=GetOnStatusDisk, write=SetOnStatusDisk};
	__property TTickEvent OnTick = {read=GetOnTick, write=SetOnTick};
	__property TTotalProgressEvent OnTotalProgress = {read=GetOnTotalProgress, write=SetOnTotalProgress};
	__property TZipDialogEvent OnZipDialog = {read=GetOnZipDialog, write=SetOnZipDialog};
	
public:
	__fastcall virtual TCustomZipMaster(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomZipMaster(void);
	void __fastcall AbortDll(void);
	int __fastcall Add(void);
	int __fastcall AddStreamToFile(AnsiString Filename, unsigned FileDate, unsigned FileAttr);
	TZipStream* __fastcall AddStreamToStream(Classes::TMemoryStream* InStream);
	virtual void __fastcall AfterConstruction(void);
	AnsiString __fastcall AppendSlash(AnsiString sDir);
	virtual void __fastcall BeforeDestruction(void);
	void __fastcall Clear(void);
	int __fastcall ConvertSFX(void);
	int __fastcall ConvertZIP(void);
	int __fastcall CopyZippedFiles(TCustomZipMaster* DestZipMaster, bool DeleteFromSource, OvrOpts OverwriteDest);
	int __fastcall Copy_File(const AnsiString InFileName, const AnsiString OutFileName);
	int __fastcall Delete(void);
	int __fastcall EraseFile(const AnsiString Fname, TDeleteOpts How);
	int __fastcall Extract(void);
	TZipStream* __fastcall ExtractFileToStream(AnsiString Filename);
	TZipStream* __fastcall ExtractStreamToStream(Classes::TMemoryStream* InStream, unsigned OutSize);
	pZipDirEntry __fastcall Find(const AnsiString fspec, int &idx)/* overload */;
	pZipDirEntry __fastcall Find(const AnsiString FileName)/* overload */;
	AnsiString __fastcall FullVersionString();
	AnsiString __fastcall GetAddPassword()/* overload */;
	AnsiString __fastcall GetAddPassword(Dialogs::TMsgDlgBtn &Response)/* overload */;
	AnsiString __fastcall GetExtrPassword()/* overload */;
	AnsiString __fastcall GetExtrPassword(Dialogs::TMsgDlgBtn &Response)/* overload */;
	Dialogs::TMsgDlgBtn __fastcall GetPassword(AnsiString DialogCaption, AnsiString MsgTxt, Dialogs::TMsgDlgButtons pwb, AnsiString &ResultStr);
	int __fastcall IndexOf(const AnsiString fname);
	int __fastcall IsZipSFX(const AnsiString SFXExeName);
	int __fastcall List(void);
	virtual void __fastcall Loaded(void);
	AnsiString __fastcall MakeTempFileName(AnsiString Prefix, AnsiString Extension);
	int __fastcall NewSFXFile(const AnsiString ExeName);
	int __fastcall QueryZip(const AnsiString fname);
	int __fastcall ReadSpan(AnsiString InFileName, AnsiString &OutFilePath);
	int __fastcall Rename(Classes::TList* RenameList, int DateTime, TZMRenameOpts How = (TZMRenameOpts)(0x0));
	void __fastcall ShowExceptionError(const Zmxcpt::EZipMaster* ZMExcept);
	void __fastcall ShowZipFmtMessage(int Id, System::TVarRec const * Args, const int Args_Size);
	void __fastcall ShowZipMessage(int Ident, AnsiString UserStr);
	int __fastcall TheErrorCode(int errCode);
	int __fastcall WriteSpan(AnsiString InFileName, AnsiString OutFileName);
};

#pragma pack(pop)

class DELPHICLASS TZipMaster;
#pragma pack(push,1)
class PASCALIMPLEMENTATION TZipMaster : public TCustomZipMaster 
{
	typedef TCustomZipMaster inherited;
	
public:
	__property Build ;
	__property Busy ;
	__property Cancel ;
	__property Count ;
	__property DirEntry ;
	__property DirOnlyCount ;
	__property DLL_Build ;
	__property Dll_Path ;
	__property Dll_Version ;
	__property ErrCode ;
	__property FullErrCode ;
	__property Handle ;
	__property IsSpanned ;
	__property LanguageInfo ;
	__property Message ;
	__property NotMainThread ;
	__property SFXOffset ;
	__property SuccessCnt ;
	__property TotalSizeToProcess ;
	__property UnzBusy ;
	__property ZipBusy ;
	__property ZipComment ;
	__property ZipContents ;
	__property ZipEOC ;
	__property ZipFileSize ;
	__property ZipSOC ;
	__property ZipStream ;
	
__published:
	__property Active  = {default=1};
	__property AddCompLevel  = {default=9};
	__property AddFrom ;
	__property AddOptions ;
	__property AddStoreSuffixes ;
	__property CodePage  = {default=0};
	__property ConfirmErase  = {default=1};
	__property Dll_Load ;
	__property DLLDirectory ;
	__property ExtAddStoreSuffixes ;
	__property ExtrBaseDir ;
	__property ExtrOptions ;
	__property FSpecArgs ;
	__property FSpecArgsExcl ;
	__property HowToDelete  = {default=1};
	__property KeepFreeOnAllDisks ;
	__property KeepFreeOnDisk1 ;
	__property Language ;
	__property MaxVolumeSize ;
	__property MinFreeVolumeSize  = {default=65536};
	__property Password ;
	__property PasswordReqCount  = {default=3};
	__property RootDir ;
	__property SFXCaption ;
	__property SFXCommandLine ;
	__property SFXDefaultDir ;
	__property SFXIcon ;
	__property SFXMessage ;
	__property SFXOptions ;
	__property SFXOverWriteMode ;
	__property SFXPath ;
	__property SpanOptions ;
	__property TempDir ;
	__property Trace ;
	__property Unattended ;
	__property UseDirOnlyEntries  = {default=0};
	__property Verbose ;
	__property Version ;
	__property VersionInfo ;
	__property ZipFileName ;
	__property OnCheckTerminate ;
	__property OnGetNextDisk ;
	__property OnItemProgress ;
	__property OnMessage ;
	__property OnProgress ;
	__property OnProgressDetails ;
	__property OnTick ;
	__property OnTotalProgress ;
	__property OnZipDialog ;
	__property OnCopyZipOverwrite ;
	__property OnCRC32Error ;
	__property OnDirUpdate ;
	__property OnExtractOverwrite ;
	__property OnExtractSkipped ;
	__property OnFileComment ;
	__property OnFileExtra ;
	__property OnNewName ;
	__property OnPasswordError ;
	__property OnSetAddName ;
	__property OnSetExtName ;
	__property OnSetNewName ;
	__property OnStatusDisk ;
public:
	#pragma option push -w-inl
	/* TCustomZipMaster.Create */ inline __fastcall virtual TZipMaster(Classes::TComponent* AOwner) : TCustomZipMaster(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomZipMaster.Destroy */ inline __fastcall virtual ~TZipMaster(void) { }
	#pragma option pop
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString ZIPMASTERVERSION;
extern PACKAGE AnsiString ZIPMASTERBUILD;
extern PACKAGE int ZIPMASTERVER;
extern PACKAGE int ZIPMASTERPRIV;
static const Byte DELZIPVERSION = 0xb3;
#define DelZipDll_Name "DelZip179.dll"
extern PACKAGE int BUSY_ERROR;
extern PACKAGE int Reentry_Error;
#define pwbOk (Dialogs::TMsgDlgBtn)(2)
#define pwbCancel (Dialogs::TMsgDlgBtn)(3)
#define pwbCancelAll (Dialogs::TMsgDlgBtn)(7)
#define pwbAbort (Dialogs::TMsgDlgBtn)(4)
static const Shortint PWLEN = 0x50;
#define sfxAskCmdLine (Sfxinterface::TSFXOption)(0)
#define sfxAskFiles (Sfxinterface::TSFXOption)(1)
#define sfxHideOverWriteBox (Sfxinterface::TSFXOption)(2)
#define sfxAutoRun (Sfxinterface::TSFXOption)(3)
#define sfxNoSuccessMsg (Sfxinterface::TSFXOption)(4)
#define DefAddStoreSuffixes (Set<AddStoreSuffixEnum, assGIF, assAVI> () << AddStoreSuffixEnum(0) << AddStoreSuffixEnum(1) << AddStoreSuffixEnum(2) << AddStoreSuffixEnum(3) << AddStoreSuffixEnum(4) << AddStoreSuffixEnum(5) << AddStoreSuffixEnum(6) << AddStoreSuffixEnum(7) << AddStoreSuffixEnum(8) << AddStoreSuffixEnum(9) << AddStoreSuffixEnum(10) << AddStoreSuffixEnum(11) << AddStoreSuffixEnum(12) << AddStoreSuffixEnum(13) << AddStoreSuffixEnum(14) << AddStoreSuffixEnum(15) << AddStoreSuffixEnum(16) << AddStoreSuffixEnum(17) << AddStoreSuffixEnum(19) << AddStoreSuffixEnum(20) << AddStoreSuffixEnum(21) << AddStoreSuffixEnum(22) << AddStoreSuffixEnum(23) << AddStoreSuffixEnum(24) << AddStoreSuffixEnum(25) << AddStoreSuffixEnum(26) )
extern PACKAGE void __fastcall Register(void);

}	/* namespace Zipmstr */
using namespace Zipmstr;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Zipmstr
