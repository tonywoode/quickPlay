// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Zmxcpt.pas' rev: 10.00

#ifndef ZmxcptHPP
#define ZmxcptHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Zmmsgstr.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Zmxcpt
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EZipMaster;
#pragma pack(push,1)
class PASCALIMPLEMENTATION EZipMaster : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	bool FDisplayMsg;
	int FResIdent;
	__fastcall EZipMaster(const AnsiString msg);
	__fastcall EZipMaster(const AnsiString Message, const bool Display);
	__fastcall EZipMaster(int Ident, System::TVarRec const * Args, const int Args_Size);
	__fastcall EZipMaster(int Ident, const bool Display);
	__fastcall EZipMaster(int Ident, const Shortint DiskNo);
	__fastcall EZipMaster(int Ident, const AnsiString Drive);
	__fastcall EZipMaster(int Ident, const AnsiString File1, const AnsiString File2);
	__fastcall EZipMaster(int Ident, const AnsiString Msg, int err);
	__property int ResId = {read=FResIdent, write=FResIdent, nodefault};
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EZipMaster(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EZipMaster(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EZipMaster(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EZipMaster(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EZipMaster(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EZipMaster(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EZipMaster(void) { }
	#pragma option pop
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString __fastcall WinErr(int err);

}	/* namespace Zmxcpt */
using namespace Zmxcpt;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Zmxcpt
