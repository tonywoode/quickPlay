// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclwin32ex.pas' rev: 10.00

#ifndef Jclwin32exHPP
#define Jclwin32exHPP

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

//-- user supplied -----------------------------------------------------------

namespace Jclwin32ex
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TJclWin32ExFunction { jwfTryEnterCriticalSection, jwfSignalObjectAndWait, jwfSetCriticalSectionSpinCount, jwfOpenWaitableTimer, jwfInitializeCriticalSectionAndSpinCount, jwfGetFileAttributesEx, jwfCreateWaitableTimer, jwfCancelWaitableTimer, jwfglGetString, jwfglGetError, jwfwglCreateContext, jwfwglDeleteContext, jwfwglMakeCurrent, jwfgluErrorString };
#pragma option pop

typedef Set<TJclWin32ExFunction, jwfTryEnterCriticalSection, jwfgluErrorString>  TJclWin32ExFunctions;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE bool __fastcall JclTryEnterCriticalSection(const _RTL_CRITICAL_SECTION &lpCriticalSection);
extern PACKAGE unsigned __fastcall JclSignalObjectAndWait(unsigned hObjectToSignal, unsigned hObjectToWaitOn, unsigned dwMilliseconds, bool bAlertable);
extern PACKAGE unsigned __fastcall JclSetCriticalSectionSpinCount(const _RTL_CRITICAL_SECTION &lpCriticalSection, unsigned dwSpinCount);
extern PACKAGE unsigned __fastcall JclOpenWaitableTimer(unsigned dwDesiredAccess, bool bInheritHandle, const AnsiString lpTimerName);
extern PACKAGE bool __fastcall JclInitializeCriticalSectionAndSpinCount(const _RTL_CRITICAL_SECTION &lpCriticalSection, unsigned dwSpinCount);
extern PACKAGE bool __fastcall JclGetFileAttributesEx(const AnsiString lpFileName, _GET_FILEEX_INFO_LEVELS fInfoLevelId, void * lpFileInformation);
extern PACKAGE unsigned __fastcall JclCreateWaitableTimer(Windows::PSecurityAttributes lpTimerAttributes, bool bManualReset, const AnsiString lpTimerName);
extern PACKAGE bool __fastcall JclCancelWaitableTimer(unsigned hTimer);
extern PACKAGE char * __fastcall JclglGetString(unsigned name);
extern PACKAGE unsigned __fastcall JclglGetError(void);
extern PACKAGE HGLRC __fastcall JclwglCreateContext(HDC hdc);
extern PACKAGE BOOL __fastcall JclwglDeleteContext(HGLRC hglrc);
extern PACKAGE BOOL __fastcall JclwglMakeCurrent(HDC hdc, HGLRC hglrc);
extern PACKAGE char * __fastcall JclgluErrorString(unsigned errCode);
extern PACKAGE TJclWin32ExFunctions __fastcall JclWin32ExFunctions(void);
extern PACKAGE void __fastcall JclCheckAndInitializeOpenGL(void);

}	/* namespace Jclwin32ex */
using namespace Jclwin32ex;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclwin32ex
