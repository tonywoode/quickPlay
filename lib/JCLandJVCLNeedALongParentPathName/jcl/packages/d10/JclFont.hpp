// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclfont.pas' rev: 10.00

#ifndef JclfontHPP
#define JclfontHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclfont
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TFontType { ftAuto, ftCaption, ftContent };
#pragma option pop

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall SetObjectFontToSystemFont(const System::TObject* AObject, const TFontType FontType = (TFontType)(0x0));

}	/* namespace Jclfont */
using namespace Jclfont;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclfont
