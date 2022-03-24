// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclmiscel.pas' rev: 10.00

#ifndef JclmiscelHPP
#define JclmiscelHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Jclwin32.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclmiscel
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TJclKillLevel { klNormal, klNoSignal, klTimeOut };
#pragma option pop

#pragma option push -b-
enum TJclAllowedPowerOperation { apoHibernate, apoShutdown, apoSuspend };
#pragma option pop

typedef Set<TJclAllowedPowerOperation, apoHibernate, apoSuspend>  TJclAllowedPowerOperations;

class DELPHICLASS EJclCreateProcessError;
class PASCALIMPLEMENTATION EJclCreateProcessError : public Jclwin32::EJclWin32Error 
{
	typedef Jclwin32::EJclWin32Error inherited;
	
public:
	#pragma option push -w-inl
	/* EJclWin32Error.Create */ inline __fastcall EJclCreateProcessError(const AnsiString Msg) : Jclwin32::EJclWin32Error(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* EJclWin32Error.CreateFmt */ inline __fastcall EJclCreateProcessError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclwin32::EJclWin32Error(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* EJclWin32Error.CreateRes */ inline __fastcall EJclCreateProcessError(int Ident)/* overload */ : Jclwin32::EJclWin32Error(Ident) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclCreateProcessError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclwin32::EJclWin32Error(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclCreateProcessError(const AnsiString Msg, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclCreateProcessError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclCreateProcessError(int Ident, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclCreateProcessError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclCreateProcessError(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE int __fastcall SetDisplayResolution(const unsigned XRes, const unsigned YRes);
extern PACKAGE bool __fastcall CreateDOSProcessRedirected(AnsiString CommandLine, const AnsiString InputFile, const AnsiString OutputFile);
extern PACKAGE bool __fastcall WinExec32(AnsiString Cmd, const int CmdShow);
extern PACKAGE unsigned __fastcall WinExec32AndWait(AnsiString Cmd, const int CmdShow);
extern PACKAGE unsigned __fastcall WinExec32AndRedirectOutput(const AnsiString Cmd, AnsiString &Output, bool RawOutput = false);
extern PACKAGE bool __fastcall LogOffOS(TJclKillLevel KillLevel = (TJclKillLevel)(0x0));
extern PACKAGE bool __fastcall PowerOffOS(TJclKillLevel KillLevel = (TJclKillLevel)(0x0));
extern PACKAGE bool __fastcall ShutDownOS(TJclKillLevel KillLevel = (TJclKillLevel)(0x0));
extern PACKAGE bool __fastcall RebootOS(TJclKillLevel KillLevel = (TJclKillLevel)(0x0));
extern PACKAGE bool __fastcall HibernateOS(bool Force, bool DisableWakeEvents);
extern PACKAGE bool __fastcall SuspendOS(bool Force, bool DisableWakeEvents);
extern PACKAGE bool __fastcall ShutDownDialog(const AnsiString DialogMessage, unsigned TimeOut, bool Force, bool Reboot)/* overload */;
extern PACKAGE bool __fastcall ShutDownDialog(const AnsiString MachineName, const AnsiString DialogMessage, unsigned TimeOut, bool Force, bool Reboot)/* overload */;
extern PACKAGE bool __fastcall AbortShutDown(void)/* overload */;
extern PACKAGE bool __fastcall AbortShutDown(const AnsiString MachineName)/* overload */;
extern PACKAGE TJclAllowedPowerOperations __fastcall GetAllowedPowerOperations(void);
extern PACKAGE void __fastcall CreateProcAsUser(const AnsiString UserDomain, const AnsiString UserName, const AnsiString PassWord, const AnsiString CommandLine);
extern PACKAGE void __fastcall CreateProcAsUserEx(const AnsiString UserDomain, const AnsiString UserName, const AnsiString Password, const AnsiString CommandLine, const char * Environment);

}	/* namespace Jclmiscel */
using namespace Jclmiscel;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclmiscel
