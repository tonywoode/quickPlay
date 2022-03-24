// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclappinst.pas' rev: 10.00

#ifndef JclappinstHPP
#define JclappinstHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Jclfileutils.hpp>	// Pascal unit
#include <Jclsynch.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclappinst
{
//-- type declarations -------------------------------------------------------
typedef int TJclAppInstDataKind;

class DELPHICLASS TJclAppInstances;
class PASCALIMPLEMENTATION TJclAppInstances : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	unsigned FCPID;
	Jclfileutils::TJclSwapFileMapping* FMapping;
	Jclfileutils::TJclFileMappingView* FMappingView;
	unsigned FMessageID;
	Jclsynch::TJclOptex* FOptex;
	unsigned __fastcall GetAppWnds(int Index);
	int __fastcall GetInstanceCount(void);
	unsigned __fastcall GetProcessIDs(int Index);
	int __fastcall GetInstanceIndex(unsigned ProcessID);
	
protected:
	void __fastcall InitData(void);
	void __fastcall NotifyInstances(const int W, const int L);
	void __fastcall RemoveInstance(void);
	
public:
	__fastcall TJclAppInstances(void);
	__fastcall virtual ~TJclAppInstances(void);
	/*         class method */ static bool __fastcall BringAppWindowToFront(TMetaClass* vmt, const unsigned Wnd);
	/*         class method */ static unsigned __fastcall GetApplicationWnd(TMetaClass* vmt, const unsigned ProcessID);
	/*         class method */ static void __fastcall KillInstance(TMetaClass* vmt);
	/*         class method */ static bool __fastcall SetForegroundWindow98(TMetaClass* vmt, const unsigned Wnd);
	bool __fastcall CheckInstance(const Word MaxInstances);
	void __fastcall CheckMultipleInstances(const Word MaxInstances);
	void __fastcall CheckSingleInstance(void);
	bool __fastcall SendCmdLineParams(const AnsiString WindowClassName, const unsigned OriginatorWnd);
	bool __fastcall SendData(const AnsiString WindowClassName, const int DataKind, void * Data, const int Size, unsigned OriginatorWnd);
	bool __fastcall SendString(const AnsiString WindowClassName, const int DataKind, const AnsiString S, unsigned OriginatorWnd);
	bool __fastcall SendStrings(const AnsiString WindowClassName, const int DataKind, const Classes::TStrings* Strings, unsigned OriginatorWnd);
	bool __fastcall SwitchTo(const int Index);
	void __fastcall UserNotify(const int Param);
	__property unsigned AppWnds[int Index] = {read=GetAppWnds};
	__property int InstanceIndex[unsigned ProcessID] = {read=GetInstanceIndex};
	__property int InstanceCount = {read=GetInstanceCount, nodefault};
	__property unsigned MessageID = {read=FMessageID, nodefault};
	__property unsigned ProcessIDs[int Index] = {read=GetProcessIDs};
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint AI_INSTANCECREATED = 0x1;
static const Shortint AI_INSTANCEDESTROYED = 0x2;
static const Shortint AI_USERMSG = 0x3;
static const Shortint AppInstDataKindNoData = -1;
static const Shortint AppInstCmdLineDataKind = 0x1;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE TJclAppInstances* __fastcall JclAppInstances(void)/* overload */;
extern PACKAGE TJclAppInstances* __fastcall JclAppInstances(const AnsiString UniqueAppIdGuidStr)/* overload */;
extern PACKAGE int __fastcall ReadMessageCheck(Messages::TMessage &Message, const unsigned IgnoredOriginatorWnd);
extern PACKAGE void __fastcall ReadMessageData(const Messages::TMessage &Message, void * &Data, int &Size);
extern PACKAGE void __fastcall ReadMessageString(const Messages::TMessage &Message, /* out */ AnsiString &S);
extern PACKAGE void __fastcall ReadMessageStrings(const Messages::TMessage &Message, const Classes::TStrings* Strings);
extern PACKAGE bool __fastcall SendData(const HWND Wnd, const HWND OriginatorWnd, const int DataKind, const void * Data, const int Size);
extern PACKAGE bool __fastcall SendStrings(const HWND Wnd, const HWND OriginatorWnd, const int DataKind, const Classes::TStrings* Strings);
extern PACKAGE bool __fastcall SendCmdLineParams(const HWND Wnd, const HWND OriginatorWnd);
extern PACKAGE bool __fastcall SendString(const HWND Wnd, const HWND OriginatorWnd, const int DataKind, const AnsiString S);

}	/* namespace Jclappinst */
using namespace Jclappinst;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclappinst
