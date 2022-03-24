// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Zmwrkr.pas' rev: 10.00

#ifndef ZmwrkrHPP
#define ZmwrkrHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Filectrl.hpp>	// Pascal unit
#include <Zipmstr.hpp>	// Pascal unit
#include <Zmstructs.hpp>	// Pascal unit
#include <Zmdelzip.hpp>	// Pascal unit
#include <Zmcore.hpp>	// Pascal unit
#include <Zmhash.hpp>	// Pascal unit
#include <Zmdbind.hpp>	// Pascal unit
#include <Zipsfx.hpp>	// Pascal unit
#include <Zmxcpt.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Zmwrkr
{
//-- type declarations -------------------------------------------------------
typedef __int64 *pLargeInt;

#pragma option push -b-
enum TZipNumberScheme { znsNone, znsVolume, znsName, znsExt };
#pragma option pop

class DELPHICLASS TZMWorker;
#pragma pack(push,1)
class PASCALIMPLEMENTATION TZMWorker : public Zmdbind::TZMDynamicBind 
{
	typedef Zmdbind::TZMDynamicBind inherited;
	
public:
	Zipmstr::pZipDirEntry operator[](int idx) { return DirEntry[idx]; }
	
private:
	int FAddCompLevel;
	Zipmstr::AddOpts fAddOptions;
	Zipmstr::AddStoreExts FAddStoreSuffixes;
	Zipmstr::CodePageOpts FCodePage;
	bool fConfirmErase;
	int FDateStamp;
	Zmcore::TZipDelays FDelaying;
	int FDirOnlyCount;
	__int64 FDiskFree;
	int FDiskNr;
	unsigned FDiskWritten;
	AnsiString FDrive;
	bool FDriveFixed;
	int FDriveNr;
	bool FEncrypt;
	AnsiString FEOCComment;
	AnsiString fExtAddStoreSuffixes;
	AnsiString FExtrBaseDir;
	Zipmstr::ExtrOpts FExtrOptions;
	unsigned FFileSize;
	unsigned FFreeOnAllDisks;
	__int64 FFreeOnDisk;
	unsigned FFreeOnDisk1;
	TDate fFromDate;
	Classes::TStrings* FFSpecArgs;
	Classes::TStrings* FFSpecArgsExcl;
	HWND fHandle;
	Zipmstr::TDeleteOpts FHowToDelete;
	int FInFileHandle;
	AnsiString FInFileName;
	int FInteger;
	bool FIsSpanned;
	int FMaxVolumeSize;
	int FMinFreeVolSize;
	Zmhash::TZipDirHashList* FDirHashs;
	bool FNewDisk;
	TZipNumberScheme FNumbering;
	int FOutFileHandle;
	AnsiString FOutFileName;
	AnsiString FPassword;
	unsigned FPasswordReqCount;
	unsigned FRealFileSize;
	AnsiString FRootDir;
	Zipsfx::TZipSFX* FSFX;
	unsigned FSFXOffset;
	Zmcore::TZipShowProgress FShowProgress;
	__int64 FSizeOfDisk;
	Zipmstr::SpanOpts FSpanOptions;
	AnsiString FStoredExtraData;
	int FSuccessCnt;
	int FTotalDisks;
	bool fUnzBusy;
	bool FUseDirOnlyEntries;
	int FVersionMadeBy0;
	int FVersionMadeBy1;
	AnsiString FVolumeName;
	bool FVolumeReadOnly;
	bool FWrongZipStruct;
	bool fZipBusy;
	AnsiString FZipComment;
	Classes::TList* fZipContents;
	Zipmstr::TZipDiskAction FZipDiskAction;
	Zipmstr::TZipDiskStatus FZipDiskStatus;
	unsigned FZipEOC;
	AnsiString FZipFileName;
	unsigned FZipSOC;
	Zipmstr::TZipStream* FZipStream;
	int __fastcall GetCount(void);
	AnsiString __fastcall GetZipComment();
	void __fastcall SetActive(bool Value);
	void __fastcall SetDirHashs(const Zmhash::TZipDirHashList* Value);
	void __fastcall SetExtAddStoreSuffixes(AnsiString Value);
	void __fastcall SetFileName(AnsiString Value);
	void __fastcall SetPasswordReqCount(unsigned Value);
	void __fastcall SetZipComment(AnsiString zComment);
	
protected:
	AnsiString __fastcall AddStoreExtStr(Zipmstr::AddStoreExts Options);
	void __fastcall CheckForDisk(bool writing);
	void __fastcall ClearFloppy(AnsiString dir);
	AnsiString __fastcall ConvertOEM(const AnsiString Source, Zipmstr::CodePageDirection Direction);
	int __fastcall CopyBuffer(int InFile, int OutFile, __int64 ReadLen);
	void __fastcall CreateMVFileNameEx(AnsiString &FileName, bool StripPartNbr, bool Compat);
	void __fastcall DiskFreeAndSize(int Action);
	void __fastcall DllCallback(Zmdelzip::PZCallBackStruct ZCallBackRec);
	void __fastcall ExtAdd(int UseStream, unsigned StrFileDate, unsigned StrFileAttr, Classes::TMemoryStream* MemStream);
	void __fastcall ExtExtract(int UseStream, Classes::TMemoryStream* MemStream);
	void __fastcall FreeZipDirEntryRecords(void);
	Zipmstr::pZipDirEntry __fastcall GetDirEntry(int idx);
	bool __fastcall GetDriveProps(void);
	int __fastcall GetLastVolume(AnsiString FileName, Zmstructs::ZipEndOfCentral &EOC, bool AllowNotExists);
	void __fastcall GetNewDisk(int DiskSeq);
	Zipsfx::TZipSFX* __fastcall GetSFXSlave(void);
	bool __fastcall CheckDestWritable(const AnsiString fname, bool NoExc);
	bool __fastcall IsFixedDrive(AnsiString drv);
	bool __fastcall IsRightDisk(void);
	bool __fastcall OpenEOC(Zmstructs::ZipEndOfCentral &EOC, bool DoExcept);
	void __fastcall ReadJoin(void *Buffer, int BufferSize, int DSErrIdent);
	void __fastcall RecreateMVArchive(AnsiString TmpZipName, bool Recreate);
	int __fastcall RejoinMVArchive(AnsiString &TmpZipName, bool Rejoin);
	void __fastcall RWJoinData(void *Buffer, unsigned ReadLen, int DSErrIdent);
	void __fastcall RWSplitData(void *Buffer, unsigned ReadLen, int ZSErrVal);
	virtual void __fastcall SetCancel(bool Value);
	void __fastcall SetDeleteSwitches(Zmdelzip::pZipParms zpParms);
	void __fastcall SetUnZipSwitches(const AnsiString NameOfZipFile, Zmdelzip::pUnZipParms uzParms);
	void __fastcall SetZipSwitches(const AnsiString NameOfZipFile, Zmdelzip::pZipParms zpParms);
	void __fastcall WriteJoin(const void *Buffer, unsigned BufferSize, int DSErrIdent);
	void __fastcall WriteSplit(const void *Buffer, unsigned Len, unsigned MinSize);
	int __fastcall ZipFormat(void);
	
public:
	__fastcall TZMWorker(Zipmstr::TCustomZipMaster* AMaster);
	__fastcall virtual ~TZMWorker(void);
	int __fastcall Add(void);
	int __fastcall AddStreamToFile(AnsiString Filename, unsigned FileDate, unsigned FileAttr);
	Zipmstr::TZipStream* __fastcall AddStreamToStream(Classes::TMemoryStream* InStream);
	virtual void __fastcall BeforeDestruction(void);
	virtual void __fastcall Clear(void);
	int __fastcall ConvertSFX(void);
	int __fastcall ConvertZIP(void);
	int __fastcall CopyZippedFiles(TZMWorker* DestZipMaster, bool DeleteFromSource, Zipmstr::OvrOpts OverwriteDest);
	int __fastcall Copy_File(const AnsiString InFileName, const AnsiString OutFileName);
	int __fastcall Delete(void);
	virtual void __fastcall Done(void);
	int __fastcall Extract(void);
	Zipmstr::TZipStream* __fastcall ExtractFileToStream(AnsiString Filename);
	Zipmstr::TZipStream* __fastcall ExtractStreamToStream(Classes::TMemoryStream* InStream, unsigned OutSize);
	AnsiString __fastcall GetAddPassword(Dialogs::TMsgDlgBtn &Response);
	AnsiString __fastcall GetExtrPassword(Dialogs::TMsgDlgBtn &Response);
	Dialogs::TMsgDlgBtn __fastcall GetPassword(AnsiString DialogCaption, AnsiString MsgTxt, int ctx, Dialogs::TMsgDlgButtons pwb, AnsiString &ResultStr)/* overload */;
	Dialogs::TMsgDlgBtn __fastcall GetPassword(AnsiString DialogCaption, AnsiString MsgTxt, Dialogs::TMsgDlgButtons pwb, AnsiString &ResultStr)/* overload */;
	int __fastcall IsZipSFX(const AnsiString SFXExeName);
	int __fastcall List(void);
	int __fastcall NewSFXFile(const AnsiString ExeName);
	int __fastcall ReadSpan(AnsiString InFileName, AnsiString &OutFilePath, bool useXProgress);
	int __fastcall Rename(Classes::TList* RenameList, int DateTime, Zipmstr::TZMRenameOpts How = (Zipmstr::TZMRenameOpts)(0x0));
	virtual void __fastcall Starting(void);
	int __fastcall WriteSpan(AnsiString InFileName, AnsiString OutFileName, bool useXProgress);
	__property bool Active = {read=FActive, write=SetActive, nodefault};
	__property int AddCompLevel = {read=FAddCompLevel, write=FAddCompLevel, nodefault};
	__property TDate AddFrom = {read=fFromDate, write=fFromDate};
	__property Zipmstr::AddOpts AddOptions = {read=fAddOptions, write=fAddOptions, nodefault};
	__property Zipmstr::AddStoreExts AddStoreSuffixes = {read=FAddStoreSuffixes, write=FAddStoreSuffixes, nodefault};
	__property Zipmstr::CodePageOpts CodePage = {read=FCodePage, write=FCodePage, default=0};
	__property bool ConfirmErase = {read=fConfirmErase, write=fConfirmErase, default=1};
	__property int Count = {read=GetCount, nodefault};
	__property Zipmstr::pZipDirEntry DirEntry[int idx] = {read=GetDirEntry/*, default*/};
	__property Zmhash::TZipDirHashList* DirHashs = {read=FDirHashs, write=SetDirHashs};
	__property int DirOnlyCount = {read=FDirOnlyCount, nodefault};
	__property AnsiString ExtAddStoreSuffixes = {read=fExtAddStoreSuffixes, write=SetExtAddStoreSuffixes};
	__property AnsiString ExtrBaseDir = {read=FExtrBaseDir, write=FExtrBaseDir};
	__property Zipmstr::ExtrOpts ExtrOptions = {read=FExtrOptions, write=FExtrOptions, nodefault};
	__property Classes::TStrings* FSpecArgs = {read=FFSpecArgs, write=FFSpecArgs};
	__property Classes::TStrings* FSpecArgsExcl = {read=FFSpecArgsExcl, write=FFSpecArgsExcl};
	__property HWND Handle = {read=fHandle, write=fHandle, nodefault};
	__property Zipmstr::TDeleteOpts HowToDelete = {read=FHowToDelete, write=FHowToDelete, nodefault};
	__property bool IsSpanned = {read=FIsSpanned, nodefault};
	__property unsigned KeepFreeOnAllDisks = {read=FFreeOnAllDisks, write=FFreeOnAllDisks, nodefault};
	__property unsigned KeepFreeOnDisk1 = {read=FFreeOnDisk1, write=FFreeOnDisk1, nodefault};
	__property int MaxVolumeSize = {read=FMaxVolumeSize, write=FMaxVolumeSize, nodefault};
	__property int MinFreeVolumeSize = {read=FMinFreeVolSize, write=FMinFreeVolSize, default=65536};
	__property AnsiString Password = {read=FPassword, write=FPassword};
	__property unsigned PasswordReqCount = {read=FPasswordReqCount, write=SetPasswordReqCount, nodefault};
	__property AnsiString RootDir = {read=FRootDir, write=FRootDir};
	__property unsigned SFXOffset = {read=FSFXOffset, nodefault};
	__property Zipsfx::TZipSFX* SFXSlave = {read=FSFX, write=FSFX};
	__property Zipmstr::SpanOpts SpanOptions = {read=FSpanOptions, write=FSpanOptions, nodefault};
	__property int SuccessCnt = {read=FSuccessCnt, nodefault};
	__property __int64 TotalSizeToProcess = {read=GetTotalSizeToProcess};
	__property bool UnzBusy = {read=fUnzBusy, nodefault};
	__property bool UseDirOnlyEntries = {read=FUseDirOnlyEntries, write=FUseDirOnlyEntries, default=0};
	__property bool ZipBusy = {read=fZipBusy, nodefault};
	__property AnsiString ZipComment = {read=GetZipComment, write=SetZipComment};
	__property Classes::TList* ZipContents = {read=fZipContents};
	__property unsigned ZipEOC = {read=FZipEOC, nodefault};
	__property AnsiString ZipFileName = {read=FZipFileName, write=SetFileName};
	__property unsigned ZipFileSize = {read=FRealFileSize, nodefault};
	__property unsigned ZipSOC = {read=FZipSOC, nodefault};
	__property Zipmstr::TZipStream* ZipStream = {read=FZipStream};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Zmwrkr */
using namespace Zmwrkr;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Zmwrkr
