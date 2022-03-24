// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Zmmsgstr.pas' rev: 10.00

#ifndef ZmmsgstrHPP
#define ZmmsgstrHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Zmmsgstr
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TZipStrEvent)(int Ident, AnsiString &DefStr);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TZipStrEvent OnZipStr;
extern PACKAGE AnsiString __fastcall LanguageIdent(const AnsiString seg);
extern PACKAGE AnsiString __fastcall SetZipMsgLanguage(const AnsiString zl);
extern PACKAGE AnsiString __fastcall LocaleInfo(int loc, unsigned info);
extern PACKAGE AnsiString __fastcall GetZipMsgLanguageInfo(int Index, unsigned info);
extern PACKAGE AnsiString __fastcall GetZipMsgLanguage(int idx);
extern PACKAGE AnsiString __fastcall ZipLoadStr(int id);
extern PACKAGE AnsiString __fastcall ZipFmtLoadStr(int Id, System::TVarRec const * Args, const int Args_Size);

}	/* namespace Zmmsgstr */
using namespace Zmmsgstr;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Zmmsgstr
