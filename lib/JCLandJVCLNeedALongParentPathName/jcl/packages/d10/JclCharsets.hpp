// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclcharsets.pas' rev: 10.00

#ifndef JclcharsetsHPP
#define JclcharsetsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclcharsets
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EJclCharsetError;
class PASCALIMPLEMENTATION EJclCharsetError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclCharsetError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclCharsetError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclCharsetError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclCharsetError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclCharsetError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclCharsetError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclCharsetError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclCharsetError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclCharsetError(void) { }
	#pragma option pop
	
};


struct TJclCharsetInfo
{
	
public:
	AnsiString Name;
	Word CodePage;
	Word FamilyCodePage;
} ;

typedef TJclCharsetInfo JclCharsets__2[302];

//-- var, const, procedure ---------------------------------------------------
static const Word CP_UTF16LE = 0x4b0;
extern PACKAGE TJclCharsetInfo JclCharsetInfos[302];
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE Word __fastcall FamilyCodePageFromCharsetName(const AnsiString CharsetName);
extern PACKAGE Word __fastcall CodePageFromCharsetName(const AnsiString CharsetName);
extern PACKAGE TJclCharsetInfo __fastcall CharsetInfoFromCharsetName(const AnsiString CharsetName);
extern PACKAGE Word __fastcall FamilyCodePageFromCodePage(Word CodePage);
extern PACKAGE AnsiString __fastcall CharsetNameFromCodePage(Word CodePage);

}	/* namespace Jclcharsets */
using namespace Jclcharsets;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclcharsets
