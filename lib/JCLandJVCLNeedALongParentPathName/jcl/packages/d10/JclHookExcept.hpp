// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclhookexcept.pas' rev: 10.00

#ifndef JclhookexceptHPP
#define JclhookexceptHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclhookexcept
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (*TJclExceptNotifyProc)(System::TObject* ExceptObj, void * ExceptAddr, bool OSException);

typedef void __fastcall (*TJclExceptNotifyProcEx)(System::TObject* ExceptObj, void * ExceptAddr, bool OSException, void * StackPointer);

typedef void __fastcall (__closure *TJclExceptNotifyMethod)(System::TObject* ExceptObj, void * ExceptAddr, bool OSException);

#pragma option push -b-
enum TJclExceptNotifyPriority { npNormal, npFirstChain };
#pragma option pop

typedef DynamicArray<unsigned >  TJclModuleArray;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE bool __fastcall JclBelongsHookedCode(void * Address);
extern PACKAGE bool __fastcall JclAddExceptNotifier(const TJclExceptNotifyProc NotifyProc, TJclExceptNotifyPriority Priority = (TJclExceptNotifyPriority)(0x0))/* overload */;
extern PACKAGE bool __fastcall JclAddExceptNotifier(const TJclExceptNotifyProcEx NotifyProc, TJclExceptNotifyPriority Priority = (TJclExceptNotifyPriority)(0x0))/* overload */;
extern PACKAGE bool __fastcall JclAddExceptNotifier(const TJclExceptNotifyMethod NotifyMethod, TJclExceptNotifyPriority Priority = (TJclExceptNotifyPriority)(0x0))/* overload */;
extern PACKAGE bool __fastcall JclRemoveExceptNotifier(const TJclExceptNotifyProc NotifyProc)/* overload */;
extern PACKAGE bool __fastcall JclRemoveExceptNotifier(const TJclExceptNotifyProcEx NotifyProc)/* overload */;
extern PACKAGE bool __fastcall JclRemoveExceptNotifier(const TJclExceptNotifyMethod NotifyMethod)/* overload */;
extern PACKAGE void __fastcall JclReplaceExceptObj(Sysutils::Exception* NewExceptObj);
extern PACKAGE bool __fastcall JclHookExceptions(void);
extern PACKAGE bool __fastcall JclUnhookExceptions(void);
extern PACKAGE bool __fastcall JclExceptionsHooked(void);
extern PACKAGE bool __fastcall JclHookExceptionsInModule(unsigned Module);
extern PACKAGE bool __fastcall JclUnkookExceptionsInModule(unsigned Module);
extern PACKAGE bool __fastcall JclInitializeLibrariesHookExcept(void);
extern PACKAGE bool __fastcall JclHookedExceptModulesList(/* out */ TJclModuleArray &ModulesList);

}	/* namespace Jclhookexcept */
using namespace Jclhookexcept;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclhookexcept
