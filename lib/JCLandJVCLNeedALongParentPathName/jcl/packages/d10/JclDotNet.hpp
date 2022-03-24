// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcldotnet.pas' rev: 10.00

#ifndef JcldotnetHPP
#define JcldotnetHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Activex.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclwidestrings.hpp>	// Pascal unit
#include <Mscoree_tlb.hpp>	// Pascal unit
#include <Mscorlib_tlb.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jcldotnet
{
//-- type declarations -------------------------------------------------------
typedef TInterfacedObject TJclClrBase;
;

#pragma option push -b-
enum TJclClrHostFlavor { hfServer, hfWorkStation };
#pragma option pop

#pragma option push -b-
enum TJclClrHostLoaderFlag { hlOptSingleDomain, hlOptMultiDomain, hlOptMultiDomainHost, hlSafeMode, hlSetPreference };
#pragma option pop

typedef Set<TJclClrHostLoaderFlag, hlOptSingleDomain, hlSetPreference>  TJclClrHostLoaderFlags;

class DELPHICLASS EJclClrException;
class PASCALIMPLEMENTATION EJclClrException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclClrException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclClrException(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclClrException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclClrException(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclClrException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclClrException(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclClrException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclClrException(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclClrException(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrHost;
class DELPHICLASS TJclClrAppDomain;
class DELPHICLASS TJclClrAppDomainSetup;
class PASCALIMPLEMENTATION TJclClrHost : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	TJclClrAppDomain* operator[](int Idx) { return AppDomains[Idx]; }
	
private:
	Mscoree_tlb::_di_ICorRuntimeHost FDefaultInterface;
	Contnrs::TObjectList* FAppDomains;
	void __fastcall EnumAppDomains(void);
	TJclClrAppDomain* __fastcall GetAppDomain(const int Idx);
	int __fastcall GetAppDomainCount(void);
	Mscorlib_tlb::_di__AppDomain __fastcall GetDefaultAppDomain();
	Mscorlib_tlb::_di__AppDomain __fastcall GetCurrentAppDomain();
	
protected:
	int __fastcall AddAppDomain(const TJclClrAppDomain* AppDomain);
	int __fastcall RemoveAppDomain(const TJclClrAppDomain* AppDomain);
	
public:
	__fastcall TJclClrHost(const WideString ClrVer, const TJclClrHostFlavor Flavor, const bool ConcurrentGC, const TJclClrHostLoaderFlags LoaderFlags);
	__fastcall virtual ~TJclClrHost(void);
	void __fastcall Start(void);
	void __fastcall Stop(void);
	void __fastcall Refresh(void);
	TJclClrAppDomainSetup* __fastcall CreateDomainSetup(void);
	TJclClrAppDomain* __fastcall CreateAppDomain(const WideString Name, const TJclClrAppDomainSetup* Setup = (TJclClrAppDomainSetup*)(0x0), const Mscorlib_tlb::_di__Evidence Evidence = (void *)(0x0));
	bool __fastcall FindAppDomain(const Mscorlib_tlb::_di__AppDomain Intf, TJclClrAppDomain* &Ret)/* overload */;
	bool __fastcall FindAppDomain(const WideString Name, TJclClrAppDomain* &Ret)/* overload */;
	/*         class method */ static WideString __fastcall CorSystemDirectory(TMetaClass* vmt);
	/*         class method */ static WideString __fastcall CorVersion(TMetaClass* vmt);
	/*         class method */ static WideString __fastcall CorRequiredVersion(TMetaClass* vmt);
	/*         class method */ static void __fastcall GetClrVersions(TMetaClass* vmt, Jclwidestrings::TJclWideStrings* VersionNames)/* overload */;
	/*         class method */ static void __fastcall GetClrVersions(TMetaClass* vmt, Classes::TStrings* VersionNames)/* overload */;
	__property TJclClrAppDomain* AppDomains[int Idx] = {read=GetAppDomain/*, default*/};
	__property int AppDomainCount = {read=GetAppDomainCount, nodefault};
	__property Mscorlib_tlb::_di__AppDomain DefaultAppDomain = {read=GetDefaultAppDomain};
	__property Mscorlib_tlb::_di__AppDomain CurrentAppDomain = {read=GetCurrentAppDomain};
	__property Mscoree_tlb::_di_ICorRuntimeHost DefaultInterface = {read=FDefaultInterface};
private:
	void *__ICorRuntimeHost;	/* Mscoree_tlb::ICorRuntimeHost */
	
public:
	operator ICorRuntimeHost*(void) { return (ICorRuntimeHost*)&__ICorRuntimeHost; }
	
};


typedef DynamicArray<WideString >  TJclClrAssemblyArguments;

class DELPHICLASS TJclClrAssembly;
class PASCALIMPLEMENTATION TJclClrAppDomain : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	TJclClrHost* FHost;
	Mscorlib_tlb::_di__AppDomain FDefaultInterface;
	
public:
	__fastcall TJclClrAppDomain(const TJclClrHost* AHost, const Mscorlib_tlb::_di__AppDomain AAppDomain);
	TJclClrAssembly* __fastcall Load(const WideString AssemblyString, const Mscorlib_tlb::_di__Evidence AssemblySecurity = (void *)(0x0))/* overload */;
	TJclClrAssembly* __fastcall Load(const Classes::TStream* RawAssemblyStream, const Classes::TStream* RawSymbolStoreStream = (Classes::TStream*)(0x0), const Mscorlib_tlb::_di__Evidence AssemblySecurity = (void *)(0x0))/* overload */;
	int __fastcall Execute(const AnsiString AssemblyFile, const Mscorlib_tlb::_di__Evidence AssemblySecurity = (void *)(0x0))/* overload */;
	int __fastcall Execute(const AnsiString AssemblyFile, const TJclClrAssemblyArguments Arguments, const Mscorlib_tlb::_di__Evidence AssemblySecurity = (void *)(0x0))/* overload */;
	int __fastcall Execute(const AnsiString AssemblyFile, const Classes::TStrings* Arguments, const Mscorlib_tlb::_di__Evidence AssemblySecurity = (void *)(0x0))/* overload */;
	void __fastcall Unload(void);
	__property TJclClrHost* Host = {read=FHost};
	__property Mscorlib_tlb::_di__AppDomain DefaultInterface = {read=FDefaultInterface};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrAppDomain(void) { }
	#pragma option pop
	
private:
	void *___AppDomain;	/* Mscorlib_tlb::_AppDomain */
	
public:
	operator _AppDomain*(void) { return (_AppDomain*)&___AppDomain; }
	
};


class PASCALIMPLEMENTATION TJclClrAppDomainSetup : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Mscorlib_tlb::_di_IAppDomainSetup FDefaultInterface;
	WideString __fastcall GetApplicationBase();
	WideString __fastcall GetApplicationName();
	WideString __fastcall GetCachePath();
	WideString __fastcall GetConfigurationFile();
	WideString __fastcall GetDynamicBase();
	WideString __fastcall GetLicenseFile();
	WideString __fastcall GetPrivateBinPath();
	WideString __fastcall GetPrivateBinPathProbe();
	WideString __fastcall GetShadowCopyDirectories();
	WideString __fastcall GetShadowCopyFiles();
	void __fastcall SetApplicationBase(const WideString Value);
	void __fastcall SetApplicationName(const WideString Value);
	void __fastcall SetCachePath(const WideString Value);
	void __fastcall SetConfigurationFile(const WideString Value);
	void __fastcall SetDynamicBase(const WideString Value);
	void __fastcall SetLicenseFile(const WideString Value);
	void __fastcall SetPrivateBinPath(const WideString Value);
	void __fastcall SetPrivateBinPathProbe(const WideString Value);
	void __fastcall SetShadowCopyDirectories(const WideString Value);
	void __fastcall SetShadowCopyFiles(const WideString Value);
	
public:
	__fastcall TJclClrAppDomainSetup(Mscorlib_tlb::_di_IAppDomainSetup Intf);
	__property WideString ApplicationBase = {read=GetApplicationBase, write=SetApplicationBase};
	__property WideString ApplicationName = {read=GetApplicationName, write=SetApplicationName};
	__property WideString CachePath = {read=GetCachePath, write=SetCachePath};
	__property WideString ConfigurationFile = {read=GetConfigurationFile, write=SetConfigurationFile};
	__property WideString DynamicBase = {read=GetDynamicBase, write=SetDynamicBase};
	__property WideString LicenseFile = {read=GetLicenseFile, write=SetLicenseFile};
	__property WideString PrivateBinPath = {read=GetPrivateBinPath, write=SetPrivateBinPath};
	__property WideString PrivateBinPathProbe = {read=GetPrivateBinPathProbe, write=SetPrivateBinPathProbe};
	__property WideString ShadowCopyDirectories = {read=GetShadowCopyDirectories, write=SetShadowCopyDirectories};
	__property WideString ShadowCopyFiles = {read=GetShadowCopyFiles, write=SetShadowCopyFiles};
	__property Mscorlib_tlb::_di_IAppDomainSetup DefaultInterface = {read=FDefaultInterface};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrAppDomainSetup(void) { }
	#pragma option pop
	
private:
	void *__IAppDomainSetup;	/* Mscorlib_tlb::IAppDomainSetup */
	
public:
	operator IAppDomainSetup*(void) { return (IAppDomainSetup*)&__IAppDomainSetup; }
	
};


class PASCALIMPLEMENTATION TJclClrAssembly : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Mscorlib_tlb::_di__Assembly FDefaultInterface;
	
public:
	__fastcall TJclClrAssembly(Mscorlib_tlb::_di__Assembly Intf);
	__property Mscorlib_tlb::_di__Assembly DefaultInterface = {read=FDefaultInterface};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrAssembly(void) { }
	#pragma option pop
	
private:
	void *___Assembly;	/* Mscorlib_tlb::_Assembly */
	
public:
	operator _Assembly*(void) { return (_Assembly*)&___Assembly; }
	
};


class DELPHICLASS TJclClrField;
class PASCALIMPLEMENTATION TJclClrField : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclClrField(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrProperty;
class PASCALIMPLEMENTATION TJclClrProperty : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclClrProperty(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrMethod;
class PASCALIMPLEMENTATION TJclClrMethod : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Mscorlib_tlb::_di__MethodInfo FDefaultInterface;
	
public:
	__property Mscorlib_tlb::_di__MethodInfo DefaultInterface = {read=FDefaultInterface};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclClrMethod(void) : System::TInterfacedObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrMethod(void) { }
	#pragma option pop
	
private:
	void *___MethodInfo;	/* Mscorlib_tlb::_MethodInfo */
	
public:
	operator _MethodInfo*(void) { return (_MethodInfo*)&___MethodInfo; }
	
};


class DELPHICLASS TJclClrObject;
class PASCALIMPLEMENTATION TJclClrObject : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TJclClrMethod* __fastcall GetMethod(const WideString Name);
	TJclClrField* __fastcall GetField(const WideString Name);
	TJclClrProperty* __fastcall GetProperty(const WideString Name);
	
public:
	__fastcall TJclClrObject(const WideString AssemblyName, const WideString NamespaceName, const WideString ClassName, System::TVarRec const * Parameters, const int Parameters_Size)/* overload */;
	__fastcall TJclClrObject(const WideString AssemblyName, const WideString NamespaceName, const WideString ClassName, const bool NewInstance)/* overload */;
	__property TJclClrField* Fields[WideString Name] = {read=GetField};
	__property TJclClrProperty* Properties[WideString Name] = {read=GetProperty};
	__property TJclClrMethod* Methods[WideString Name] = {read=GetMethod};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrObject(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint STARTUP_CONCURRENT_GC = 0x1;
static const Shortint STARTUP_LOADER_OPTIMIZATION_MASK = 0x6;
static const Shortint STARTUP_LOADER_OPTIMIZATION_SINGLE_DOMAIN = 0x2;
static const Shortint STARTUP_LOADER_OPTIMIZATION_MULTI_DOMAIN = 0x4;
static const Shortint STARTUP_LOADER_OPTIMIZATION_MULTI_DOMAIN_HOST = 0x6;
static const Shortint STARTUP_LOADER_SAFEMODE = 0x10;
static const Word STARTUP_LOADER_SETPREFERENCE = 0x100;
static const Shortint RUNTIME_INFO_UPGRADE_VERSION = 0x1;
static const Shortint RUNTIME_INFO_REQUEST_IA64 = 0x2;
static const Shortint RUNTIME_INFO_REQUEST_AMD64 = 0x4;
static const Shortint RUNTIME_INFO_REQUEST_X86 = 0x8;
static const Shortint RUNTIME_INFO_DONT_RETURN_DIRECTORY = 0x10;
static const Shortint RUNTIME_INFO_DONT_RETURN_VERSION = 0x20;
static const Shortint RUNTIME_INFO_DONT_SHOW_ERROR_DIALOG = 0x40;
#define mscoree_dll "mscoree.dll"
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE int __fastcall CompareCLRVersions(const AnsiString LeftVersion, const AnsiString RightVersion);

}	/* namespace Jcldotnet */
using namespace Jcldotnet;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcldotnet
