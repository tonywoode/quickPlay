// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclsecurity.pas' rev: 10.00

#ifndef JclsecurityHPP
#define JclsecurityHPP

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
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#define TTokenInformationClass TOKEN_INFORMATION_CLASS

namespace Jclsecurity
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EJclSecurityError;
class PASCALIMPLEMENTATION EJclSecurityError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclSecurityError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclSecurityError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclSecurityError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclSecurityError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclSecurityError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclSecurityError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclSecurityError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclSecurityError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclSecurityError(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE Windows::PSecurityAttributes __fastcall CreateNullDacl(/* out */ _SECURITY_ATTRIBUTES &Sa, const bool Inheritable);
extern PACKAGE Windows::PSecurityAttributes __fastcall CreateInheritable(/* out */ _SECURITY_ATTRIBUTES &Sa);
extern PACKAGE bool __fastcall IsAdministrator(void);
extern PACKAGE bool __fastcall EnableProcessPrivilege(const bool Enable, const AnsiString Privilege);
extern PACKAGE bool __fastcall EnableThreadPrivilege(const bool Enable, const AnsiString Privilege);
extern PACKAGE bool __fastcall IsPrivilegeEnabled(const AnsiString Privilege);
extern PACKAGE AnsiString __fastcall GetPrivilegeDisplayName(const AnsiString PrivilegeName);
extern PACKAGE bool __fastcall SetUserObjectFullAccess(unsigned hUserObject);
extern PACKAGE AnsiString __fastcall GetUserObjectName(unsigned hUserObject);
extern PACKAGE void __fastcall LookupAccountBySid(void * Sid, /* out */ AnsiString &Name, /* out */ AnsiString &Domain)/* overload */;
extern PACKAGE void __fastcall LookupAccountBySid(void * Sid, /* out */ WideString &Name, /* out */ WideString &Domain)/* overload */;
extern PACKAGE void __fastcall QueryTokenInformation(unsigned Token, TTokenInformationClass InformationClass, void * &Buffer);
extern PACKAGE void __fastcall FreeTokenInformation(void * &Buffer);
extern PACKAGE AnsiString __fastcall GetInteractiveUserName();
extern PACKAGE AnsiString __fastcall SIDToString(void * ASID);
extern PACKAGE void __fastcall StringToSID(const AnsiString SIDString, void * SID, unsigned cbSID);
extern PACKAGE bool __fastcall GetComputerSID(void * SID, unsigned cbSID);
extern PACKAGE bool __fastcall IsUACEnabled(void);
extern PACKAGE bool __fastcall IsElevated(void);

}	/* namespace Jclsecurity */
using namespace Jclsecurity;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclsecurity
