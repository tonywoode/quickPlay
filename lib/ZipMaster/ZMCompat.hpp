// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Zmcompat.pas' rev: 10.00

#ifndef ZmcompatHPP
#define ZmcompatHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Zmcompat
{
//-- type declarations -------------------------------------------------------
typedef Set<char, 0, 255>  TCharSet;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall CharInSet(char C, const TCharSet &CharSet);
extern PACKAGE char * __fastcall MakeStrP(const AnsiString str);

}	/* namespace Zmcompat */
using namespace Zmcompat;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Zmcompat
