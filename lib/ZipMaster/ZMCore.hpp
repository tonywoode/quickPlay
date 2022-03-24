// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Zmcore.pas' rev: 10.00

#ifndef ZmcoreHPP
#define ZmcoreHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Zipmstr.hpp>	// Pascal unit
#include <Zmmsgstr.hpp>	// Pascal unit
#include <Zmxcpt.hpp>	// Pascal unit
#include <Zmdelzip.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Zmcore
{
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct TZipEventsRec
{
	
public:
	Zipmstr::TCheckTerminateEvent OnCheckTerminate;
	Zipmstr::TItemProgressEvent OnItemProgress;
	Zipmstr::TMessageEvent OnMessage;
	Zipmstr::TProgressEvent OnProgress;
	Zipmstr::TProgressDetailsEvent OnProgressDetails;
	Zipmstr::TTickEvent OnTick;
	Zipmstr::TTotalProgressEvent OnTotalProgress;
	Zipmstr::TZipDialogEvent OnZipDialog;
	Zipmstr::TCopyZipOverwriteEvent OnCopyZipOverwrite;
	Zipmstr::TCRC32ErrorEvent OnCRC32Error;
	Classes::TNotifyEvent OnDirUpdate;
	Zipmstr::TExtractOverwriteEvent OnExtractOverwrite;
	Zipmstr::TExtractSkippedEvent OnExtractSkipped;
	Zipmstr::TFileCommentEvent OnFileComment;
	Zipmstr::TFileExtraEvent OnFileExtra;
	Zipmstr::TNewNameEvent OnNewName;
	Zipmstr::TPasswordErrorEvent OnPasswordError;
	Zipmstr::TSetAddNameEvent OnSetAddName;
	Zipmstr::TSetExtNameEvent OnSetExtName;
	Zipmstr::TSetNewNameEvent OnSetNewName;
	Zipmstr::TGetNextDiskEvent OnGetNextDisk;
	Zipmstr::TStatusDiskEvent OnStatusDisk;
} ;
#pragma pack(pop)

typedef TZipEventsRec *pZipEventsRec;

#pragma option push -b-
enum TZipDelayedItems { zdiList, zdiComment };
#pragma option pop

typedef Set<TZipDelayedItems, zdiList, zdiComment>  TZipDelays;

#pragma option push -b-
enum TZipShowProgress { zspNone, zspFull, zspExtra };
#pragma option pop

#pragma option push -b-
enum TZipAllwaysItems { zaaYesOvrwrt };
#pragma option pop

typedef Set<TZipAllwaysItems, zaaYesOvrwrt, zaaYesOvrwrt>  TZipAnswerAlls;

class DELPHICLASS TProgDetails;
#pragma pack(push,1)
class PASCALIMPLEMENTATION TProgDetails : public Zipmstr::TProgressDetails 
{
	typedef Zipmstr::TProgressDetails inherited;
	
public:
	void __fastcall Advance(unsigned adv);
	void __fastcall AdvanceXtra(unsigned adv);
	void __fastcall Clear(void);
	void __fastcall SetCount(unsigned Count);
	void __fastcall SetEnd(void);
	void __fastcall SetItem(const AnsiString fname, unsigned fsize);
	void __fastcall SetItemXtra(const AnsiString xmsg, unsigned fsize);
	void __fastcall SetSize(__int64 FullSize);
	void __fastcall Written(__int64 bytes);
public:
	#pragma option push -w-inl
	/* TProgressDetails.Destroy */ inline __fastcall virtual ~TProgDetails(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TProgDetails(void) : Zipmstr::TProgressDetails() { }
	#pragma option pop
	
};

#pragma pack(pop)

class DELPHICLASS TZMCore;
#pragma pack(push,1)
class PASCALIMPLEMENTATION TZMCore : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int FCurWaitCount;
	#pragma pack(push,1)
	TZipEventsRec FEvents;
	#pragma pack(pop)
	Controls::TCursor FSaveCursor;
	pZipEventsRec __fastcall GetEventsRec(void);
	AnsiString __fastcall GetMessage();
	void __fastcall SetEventsRec(const pZipEventsRec Value);
	void __fastcall SetTempDir(const AnsiString Value);
	
protected:
	bool FActive;
	TZipAnswerAlls FAnswerAll;
	bool FBusy;
	bool fCancel;
	int FErrCode;
	AnsiString FEventErr;
	int fFullErrCode;
	bool fIsDestructing;
	Zipmstr::TCustomZipMaster* FMaster;
	AnsiString FMessage;
	bool FNotMainTask;
	Zipmstr::TProgressDetails* FProgDetails;
	bool FReenter;
	AnsiString FTempDir;
	bool fTrace;
	bool FUnattended;
	bool fVerbose;
	virtual bool __fastcall Call_back(Zmdelzip::ActionCodes ActionCode, int ErrorCode, AnsiString Msg, unsigned FileSize);
	virtual void __fastcall Done(void);
	__int64 __fastcall GetTotalSizeToProcess(void);
	virtual void __fastcall SetCancel(bool Value);
	virtual void __fastcall Starting(void);
	Controls::TModalResult __fastcall ZipMessageDialog(const AnsiString title, AnsiString &msg, int context, Dialogs::TMsgDlgButtons btns);
	void __fastcall ZipMessageDlg(const AnsiString msg, int context)/* overload */;
	Controls::TModalResult __fastcall ZipMessageDlgEx(const AnsiString title, const AnsiString msg, int context, Dialogs::TMsgDlgButtons btns)/* overload */;
	__property TZipEventsRec Events = {read=FEvents};
	
public:
	__fastcall TZMCore(Zipmstr::TCustomZipMaster* AMaster);
	__fastcall virtual ~TZMCore(void);
	void __fastcall Attacked(System::TObject* AnObject);
	virtual void __fastcall Clear(void);
	AnsiString __fastcall MakeTempFileName(AnsiString Prefix, AnsiString Extension);
	void __fastcall Report(Zmdelzip::ActionCodes ActionCode, int ErrorCode, AnsiString Msg, __int64 FileSize)/* overload */;
	void __fastcall ShowExceptionError(const Zmxcpt::EZipMaster* ZMExcept);
	void __fastcall ShowZipFmtMessage(int Id, System::TVarRec const * Args, const int Args_Size);
	void __fastcall ShowZipMessage(int Ident, const AnsiString UserStr);
	void __fastcall StartWaitCursor(void);
	void __fastcall StopWaitCursor(void);
	__property bool Busy = {read=FBusy, write=FBusy, nodefault};
	__property bool Cancel = {read=fCancel, write=SetCancel, nodefault};
	__property int ErrCode = {read=FErrCode, write=FErrCode, nodefault};
	__property pZipEventsRec EventsRec = {read=GetEventsRec, write=SetEventsRec};
	__property int FullErrCode = {read=fFullErrCode, nodefault};
	__property Zipmstr::TCustomZipMaster* Master = {read=FMaster, write=FMaster};
	__property AnsiString Message = {read=GetMessage, write=FMessage};
	__property bool NotMainTask = {read=FNotMainTask, write=FNotMainTask, nodefault};
	__property bool Reentry = {read=FReenter, write=FReenter, nodefault};
	__property AnsiString TempDir = {read=FTempDir, write=SetTempDir};
	__property bool Trace = {read=fTrace, write=fTrace, nodefault};
	__property bool Unattended = {read=FUnattended, write=FUnattended, nodefault};
	__property bool Verbose = {read=fVerbose, write=fVerbose, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString RESOURCE_ERROR;
static const Shortint zprFile = 0x0;
static const Shortint zprArchive = 0x1;
static const Shortint zprCopyTemp = 0x2;
static const Shortint zprSFX = 0x3;
static const Shortint zprHeader = 0x4;
static const Shortint zprFinish = 0x5;
static const Shortint zprCompressed = 0x6;
static const Shortint zprCentral = 0x7;
static const Shortint zprChecking = 0x8;
static const Shortint zprLoading = 0x9;
static const Shortint zprJoining = 0xa;
static const Shortint zprSplitting = 0xb;

}	/* namespace Zmcore */
using namespace Zmcore;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Zmcore
