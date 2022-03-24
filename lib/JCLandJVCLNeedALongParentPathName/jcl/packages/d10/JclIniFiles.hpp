// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclinifiles.pas' rev: 10.00

#ifndef JclinifilesHPP
#define JclinifilesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Inifiles.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclinifiles
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE bool __fastcall IniReadBool(const AnsiString FileName, const AnsiString Section, const AnsiString Line);
extern PACKAGE int __fastcall IniReadInteger(const AnsiString FileName, const AnsiString Section, const AnsiString Line);
extern PACKAGE AnsiString __fastcall IniReadString(const AnsiString FileName, const AnsiString Section, const AnsiString Line);
extern PACKAGE void __fastcall IniWriteBool(const AnsiString FileName, const AnsiString Section, const AnsiString Line, bool Value);
extern PACKAGE void __fastcall IniWriteInteger(const AnsiString FileName, const AnsiString Section, const AnsiString Line, int Value);
extern PACKAGE void __fastcall IniWriteString(const AnsiString FileName, const AnsiString Section, const AnsiString Line, const AnsiString Value);
extern PACKAGE void __fastcall IniReadStrings(Inifiles::TCustomIniFile* IniFile, const AnsiString Section, Classes::TStrings* Strings);
extern PACKAGE void __fastcall IniWriteStrings(Inifiles::TCustomIniFile* IniFile, const AnsiString Section, Classes::TStrings* Strings);

}	/* namespace Jclinifiles */
using namespace Jclinifiles;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclinifiles
