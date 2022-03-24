// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclregistry.pas' rev: 10.00

#ifndef JclregistryHPP
#define JclregistryHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclstrings.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
// BCB users must typecast the HKEY values to DelphiHKEY or use the HK-values below.

namespace Jclregistry
{
//-- type declarations -------------------------------------------------------
typedef unsigned DelphiHKEY;

#pragma option push -b-
enum TExecKind { ekMachineRun, ekMachineRunOnce, ekUserRun, ekUserRunOnce, ekServiceRun, ekServiceRunOnce };
#pragma option pop

class DELPHICLASS EJclRegistryError;
class PASCALIMPLEMENTATION EJclRegistryError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclRegistryError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclRegistryError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclRegistryError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclRegistryError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclRegistryError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclRegistryError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclRegistryError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclRegistryError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclRegistryError(void) { }
	#pragma option pop
	
};


struct TRootKey
{
	
public:
	unsigned Key;
	AnsiString AnsiName;
	WideString WideName;
} ;

typedef TRootKey JclRegistry__2[14];

#pragma option push -b-
enum TJclRegWOW64Access { raDefault, raNative, ra32Key, ra64Key };
#pragma option pop

//-- var, const, procedure ---------------------------------------------------
static const unsigned HKCR = 0x80000000;
static const unsigned HKCU = 0x80000001;
static const unsigned HKLM = 0x80000002;
static const unsigned HKUS = 0x80000003;
static const unsigned HKPD = 0x80000004;
static const unsigned HKCC = 0x80000005;
static const unsigned HKDD = 0x80000006;
static const char RegKeyDelimiter = '\x5c';
#define HKCRLongName "HKEY_CLASSES_ROOT"
#define HKCULongName "HKEY_CURRENT_USER"
#define HKLMLongName "HKEY_LOCAL_MACHINE"
#define HKUSLongName "HKEY_USERS"
#define HKPDLongName "HKEY_PERFORMANCE_DATA"
#define HKCCLongName "HKEY_CURRENT_CONFIG"
#define HKDDLongName "HKEY_DYN_DATA"
#define HKCRShortName "HKCR"
#define HKCUShortName "HKCU"
#define HKLMShortName "HKLM"
#define HKUSShortName "HKUS"
#define HKPDShortName "HKPD"
#define HKCCShortName "HKCC"
#define HKDDShortName "HKDD"
extern PACKAGE TRootKey RootKeys[14];
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE TJclRegWOW64Access __fastcall RegGetWOW64AccessMode(void);
extern PACKAGE void __fastcall RegSetWOW64AccessMode(TJclRegWOW64Access Access);
extern PACKAGE int __fastcall RegCreateKey(const unsigned RootKey, const AnsiString Key)/* overload */;
extern PACKAGE int __fastcall RegCreateKey(const unsigned RootKey, const AnsiString Key, const AnsiString Value)/* overload */;
extern PACKAGE bool __fastcall RegDeleteEntry(const unsigned RootKey, const AnsiString Key, const AnsiString Name);
extern PACKAGE bool __fastcall RegDeleteKeyTree(const unsigned RootKey, const AnsiString Key);
extern PACKAGE bool __fastcall RegGetDataSize(const unsigned RootKey, const AnsiString Key, const AnsiString Name, /* out */ unsigned &DataSize);
extern PACKAGE bool __fastcall RegGetDataType(const unsigned RootKey, const AnsiString Key, const AnsiString Name, /* out */ unsigned &DataType);
extern PACKAGE bool __fastcall RegReadBool(const unsigned RootKey, const AnsiString Key, const AnsiString Name);
extern PACKAGE bool __fastcall RegReadBoolDef(const unsigned RootKey, const AnsiString Key, const AnsiString Name, bool Def);
extern PACKAGE bool __fastcall RegReadIntegerEx(const unsigned RootKey, const AnsiString Key, const AnsiString Name, /* out */ int &RetValue, bool RaiseException = false);
extern PACKAGE int __fastcall RegReadInteger(const unsigned RootKey, const AnsiString Key, const AnsiString Name);
extern PACKAGE int __fastcall RegReadIntegerDef(const unsigned RootKey, const AnsiString Key, const AnsiString Name, int Def);
extern PACKAGE bool __fastcall RegReadCardinalEx(const unsigned RootKey, const AnsiString Key, const AnsiString Name, /* out */ unsigned &RetValue, bool RaiseException = false);
extern PACKAGE unsigned __fastcall RegReadCardinal(const unsigned RootKey, const AnsiString Key, const AnsiString Name);
extern PACKAGE unsigned __fastcall RegReadCardinalDef(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned Def);
extern PACKAGE bool __fastcall RegReadDWORDEx(const unsigned RootKey, const AnsiString Key, const AnsiString Name, /* out */ unsigned &RetValue, bool RaiseException = false);
extern PACKAGE unsigned __fastcall RegReadDWORD(const unsigned RootKey, const AnsiString Key, const AnsiString Name);
extern PACKAGE unsigned __fastcall RegReadDWORDDef(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned Def);
extern PACKAGE bool __fastcall RegReadInt64Ex(const unsigned RootKey, const AnsiString Key, const AnsiString Name, /* out */ __int64 &RetValue, bool RaiseException = false);
extern PACKAGE __int64 __fastcall RegReadInt64(const unsigned RootKey, const AnsiString Key, const AnsiString Name);
extern PACKAGE __int64 __fastcall RegReadInt64Def(const unsigned RootKey, const AnsiString Key, const AnsiString Name, __int64 Def);
extern PACKAGE bool __fastcall RegReadUInt64Ex(const unsigned RootKey, const AnsiString Key, const AnsiString Name, /* out */ __int64 &RetValue, bool RaiseException = false);
extern PACKAGE __int64 __fastcall RegReadUInt64(const unsigned RootKey, const AnsiString Key, const AnsiString Name);
extern PACKAGE __int64 __fastcall RegReadUInt64Def(const unsigned RootKey, const AnsiString Key, const AnsiString Name, __int64 Def);
extern PACKAGE bool __fastcall RegReadSingleEx(const unsigned RootKey, const AnsiString Key, const AnsiString Name, /* out */ float &RetValue, bool RaiseException = false);
extern PACKAGE float __fastcall RegReadSingle(const unsigned RootKey, const AnsiString Key, const AnsiString Name);
extern PACKAGE float __fastcall RegReadSingleDef(const unsigned RootKey, const AnsiString Key, const AnsiString Name, float Def);
extern PACKAGE bool __fastcall RegReadDoubleEx(const unsigned RootKey, const AnsiString Key, const AnsiString Name, /* out */ double &RetValue, bool RaiseException = false);
extern PACKAGE double __fastcall RegReadDouble(const unsigned RootKey, const AnsiString Key, const AnsiString Name);
extern PACKAGE double __fastcall RegReadDoubleDef(const unsigned RootKey, const AnsiString Key, const AnsiString Name, double Def);
extern PACKAGE bool __fastcall RegReadExtendedEx(const unsigned RootKey, const AnsiString Key, const AnsiString Name, /* out */ Extended &RetValue, bool RaiseException = false);
extern PACKAGE Extended __fastcall RegReadExtended(const unsigned RootKey, const AnsiString Key, const AnsiString Name);
extern PACKAGE Extended __fastcall RegReadExtendedDef(const unsigned RootKey, const AnsiString Key, const AnsiString Name, Extended Def);
extern PACKAGE bool __fastcall RegReadStringEx(const unsigned RootKey, const AnsiString Key, const AnsiString Name, /* out */ AnsiString &RetValue, bool RaiseException = false);
extern PACKAGE AnsiString __fastcall RegReadString(const unsigned RootKey, const AnsiString Key, const AnsiString Name);
extern PACKAGE AnsiString __fastcall RegReadStringDef(const unsigned RootKey, const AnsiString Key, const AnsiString Name, AnsiString Def);
extern PACKAGE bool __fastcall RegReadAnsiStringEx(const unsigned RootKey, const AnsiString Key, const AnsiString Name, /* out */ AnsiString &RetValue, bool RaiseException = false);
extern PACKAGE AnsiString __fastcall RegReadAnsiString(const unsigned RootKey, const AnsiString Key, const AnsiString Name);
extern PACKAGE AnsiString __fastcall RegReadAnsiStringDef(const unsigned RootKey, const AnsiString Key, const AnsiString Name, AnsiString Def);
extern PACKAGE bool __fastcall RegReadWideStringEx(const unsigned RootKey, const AnsiString Key, const AnsiString Name, /* out */ WideString &RetValue, bool RaiseException = false);
extern PACKAGE WideString __fastcall RegReadWideString(const unsigned RootKey, const AnsiString Key, const AnsiString Name);
extern PACKAGE WideString __fastcall RegReadWideStringDef(const unsigned RootKey, const AnsiString Key, const AnsiString Name, WideString Def);
extern PACKAGE bool __fastcall RegReadMultiSzEx(const unsigned RootKey, const AnsiString Key, const AnsiString Name, Classes::TStrings* Value, bool RaiseException = false)/* overload */;
extern PACKAGE void __fastcall RegReadMultiSz(const unsigned RootKey, const AnsiString Key, const AnsiString Name, Classes::TStrings* Value)/* overload */;
extern PACKAGE void __fastcall RegReadMultiSzDef(const unsigned RootKey, const AnsiString Key, const AnsiString Name, Classes::TStrings* Value, Classes::TStrings* Def)/* overload */;
extern PACKAGE bool __fastcall RegReadMultiSzEx(const unsigned RootKey, const AnsiString Key, const AnsiString Name, /* out */ char * &RetValue, bool RaiseException = false)/* overload */;
extern PACKAGE char * __fastcall RegReadMultiSz(const unsigned RootKey, const AnsiString Key, const AnsiString Name)/* overload */;
extern PACKAGE char * __fastcall RegReadMultiSzDef(const unsigned RootKey, const AnsiString Key, const AnsiString Name, char * Def)/* overload */;
extern PACKAGE bool __fastcall RegReadAnsiMultiSzEx(const unsigned RootKey, const AnsiString Key, const AnsiString Name, Classes::TStrings* Value, bool RaiseException = false)/* overload */;
extern PACKAGE void __fastcall RegReadAnsiMultiSz(const unsigned RootKey, const AnsiString Key, const AnsiString Name, Classes::TStrings* Value)/* overload */;
extern PACKAGE void __fastcall RegReadAnsiMultiSzDef(const unsigned RootKey, const AnsiString Key, const AnsiString Name, Classes::TStrings* Value, Classes::TStrings* Def)/* overload */;
extern PACKAGE bool __fastcall RegReadAnsiMultiSzEx(const unsigned RootKey, const AnsiString Key, const AnsiString Name, /* out */ char * &RetValue, bool RaiseException = false)/* overload */;
extern PACKAGE char * __fastcall RegReadAnsiMultiSz(const unsigned RootKey, const AnsiString Key, const AnsiString Name)/* overload */;
extern PACKAGE char * __fastcall RegReadAnsiMultiSzDef(const unsigned RootKey, const AnsiString Key, const AnsiString Name, char * Def)/* overload */;
extern PACKAGE bool __fastcall RegReadWideMultiSzEx(const unsigned RootKey, const AnsiString Key, const AnsiString Name, Jclwidestrings::TJclWideStrings* Value, bool RaiseException = false)/* overload */;
extern PACKAGE void __fastcall RegReadWideMultiSz(const unsigned RootKey, const AnsiString Key, const AnsiString Name, Jclwidestrings::TJclWideStrings* Value)/* overload */;
extern PACKAGE void __fastcall RegReadWideMultiSzDef(const unsigned RootKey, const AnsiString Key, const AnsiString Name, Jclwidestrings::TJclWideStrings* Value, Jclwidestrings::TJclWideStrings* Def)/* overload */;
extern PACKAGE bool __fastcall RegReadWideMultiSzEx(const unsigned RootKey, const AnsiString Key, const AnsiString Name, /* out */ WideChar * &RetValue, bool RaiseException = false)/* overload */;
extern PACKAGE WideChar * __fastcall RegReadWideMultiSz(const unsigned RootKey, const AnsiString Key, const AnsiString Name)/* overload */;
extern PACKAGE WideChar * __fastcall RegReadWideMultiSzDef(const unsigned RootKey, const AnsiString Key, const AnsiString Name, WideChar * Def)/* overload */;
extern PACKAGE bool __fastcall RegReadBinaryEx(const unsigned RootKey, const AnsiString Key, const AnsiString Name, void *Value, const unsigned ValueSize, /* out */ unsigned &DataSize, bool RaiseException = false);
extern PACKAGE unsigned __fastcall RegReadBinary(const unsigned RootKey, const AnsiString Key, const AnsiString Name, void *Value, const unsigned ValueSize);
extern PACKAGE unsigned __fastcall RegReadBinaryDef(const unsigned RootKey, const AnsiString Key, const AnsiString Name, void *Value, const unsigned ValueSize, const Byte Def);
extern PACKAGE void __fastcall RegWriteBool(const unsigned RootKey, const AnsiString Key, const AnsiString Name, bool Value)/* overload */;
extern PACKAGE void __fastcall RegWriteBool(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned DataType, bool Value)/* overload */;
extern PACKAGE void __fastcall RegWriteInteger(const unsigned RootKey, const AnsiString Key, const AnsiString Name, int Value)/* overload */;
extern PACKAGE void __fastcall RegWriteInteger(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned DataType, int Value)/* overload */;
extern PACKAGE void __fastcall RegWriteCardinal(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned Value)/* overload */;
extern PACKAGE void __fastcall RegWriteCardinal(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned DataType, unsigned Value)/* overload */;
extern PACKAGE void __fastcall RegWriteDWORD(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned Value)/* overload */;
extern PACKAGE void __fastcall RegWriteDWORD(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned DataType, unsigned Value)/* overload */;
extern PACKAGE void __fastcall RegWriteInt64(const unsigned RootKey, const AnsiString Key, const AnsiString Name, __int64 Value)/* overload */;
extern PACKAGE void __fastcall RegWriteInt64(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned DataType, __int64 Value)/* overload */;
extern PACKAGE void __fastcall RegWriteUInt64(const unsigned RootKey, const AnsiString Key, const AnsiString Name, __int64 Value)/* overload */;
extern PACKAGE void __fastcall RegWriteUInt64(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned DataType, __int64 Value)/* overload */;
extern PACKAGE void __fastcall RegWriteSingle(const unsigned RootKey, const AnsiString Key, const AnsiString Name, float Value)/* overload */;
extern PACKAGE void __fastcall RegWriteSingle(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned DataType, float Value)/* overload */;
extern PACKAGE void __fastcall RegWriteDouble(const unsigned RootKey, const AnsiString Key, const AnsiString Name, double Value)/* overload */;
extern PACKAGE void __fastcall RegWriteDouble(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned DataType, double Value)/* overload */;
extern PACKAGE void __fastcall RegWriteExtended(const unsigned RootKey, const AnsiString Key, const AnsiString Name, Extended Value)/* overload */;
extern PACKAGE void __fastcall RegWriteExtended(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned DataType, Extended Value)/* overload */;
extern PACKAGE void __fastcall RegWriteString(const unsigned RootKey, const AnsiString Key, const AnsiString Name, const AnsiString Value)/* overload */;
extern PACKAGE void __fastcall RegWriteString(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned DataType, const AnsiString Value)/* overload */;
extern PACKAGE void __fastcall RegWriteAnsiString(const unsigned RootKey, const AnsiString Key, const AnsiString Name, const AnsiString Value)/* overload */;
extern PACKAGE void __fastcall RegWriteAnsiString(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned DataType, const AnsiString Value)/* overload */;
extern PACKAGE void __fastcall RegWriteWideString(const unsigned RootKey, const AnsiString Key, const AnsiString Name, const WideString Value)/* overload */;
extern PACKAGE void __fastcall RegWriteWideString(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned DataType, const WideString Value)/* overload */;
extern PACKAGE void __fastcall RegWriteMultiSz(const unsigned RootKey, const AnsiString Key, const AnsiString Name, char * Value)/* overload */;
extern PACKAGE void __fastcall RegWriteMultiSz(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned DataType, char * Value)/* overload */;
extern PACKAGE void __fastcall RegWriteMultiSz(const unsigned RootKey, const AnsiString Key, const AnsiString Name, const Classes::TStrings* Value)/* overload */;
extern PACKAGE void __fastcall RegWriteMultiSz(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned DataType, const Classes::TStrings* Value)/* overload */;
extern PACKAGE void __fastcall RegWriteAnsiMultiSz(const unsigned RootKey, const AnsiString Key, const AnsiString Name, char * Value)/* overload */;
extern PACKAGE void __fastcall RegWriteAnsiMultiSz(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned DataType, char * Value)/* overload */;
extern PACKAGE void __fastcall RegWriteAnsiMultiSz(const unsigned RootKey, const AnsiString Key, const AnsiString Name, const Classes::TStrings* Value)/* overload */;
extern PACKAGE void __fastcall RegWriteAnsiMultiSz(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned DataType, const Classes::TStrings* Value)/* overload */;
extern PACKAGE void __fastcall RegWriteWideMultiSz(const unsigned RootKey, const AnsiString Key, const AnsiString Name, WideChar * Value)/* overload */;
extern PACKAGE void __fastcall RegWriteWideMultiSz(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned DataType, WideChar * Value)/* overload */;
extern PACKAGE void __fastcall RegWriteWideMultiSz(const unsigned RootKey, const AnsiString Key, const AnsiString Name, const Jclwidestrings::TJclWideStrings* Value)/* overload */;
extern PACKAGE void __fastcall RegWriteWideMultiSz(const unsigned RootKey, const AnsiString Key, const AnsiString Name, unsigned DataType, const Jclwidestrings::TJclWideStrings* Value)/* overload */;
extern PACKAGE void __fastcall RegWriteBinary(const unsigned RootKey, const AnsiString Key, const AnsiString Name, const void *Value, const unsigned ValueSize);
extern PACKAGE bool __fastcall UnregisterAutoExec(TExecKind ExecKind, const AnsiString Name);
extern PACKAGE bool __fastcall RegisterAutoExec(TExecKind ExecKind, const AnsiString Name, const AnsiString Cmdline);
extern PACKAGE bool __fastcall RegGetValueNames(const unsigned RootKey, const AnsiString Key, const Classes::TStrings* List);
extern PACKAGE bool __fastcall RegGetKeyNames(const unsigned RootKey, const AnsiString Key, const Classes::TStrings* List);
extern PACKAGE bool __fastcall RegGetValueNamesAndValues(const HKEY RootKey, const AnsiString Key, const Classes::TStrings* List);
extern PACKAGE bool __fastcall RegHasSubKeys(const unsigned RootKey, const AnsiString Key);
extern PACKAGE bool __fastcall RegKeyExists(const unsigned RootKey, const AnsiString Key);
extern PACKAGE bool __fastcall RegValueExists(const unsigned RootKey, const AnsiString Key, const AnsiString Name);
extern PACKAGE bool __fastcall RegSaveList(const unsigned RootKey, const AnsiString Key, const AnsiString ListName, const Classes::TStrings* Items);
extern PACKAGE bool __fastcall RegLoadList(const unsigned RootKey, const AnsiString Key, const AnsiString ListName, const Classes::TStrings* SaveTo);
extern PACKAGE bool __fastcall RegDelList(const unsigned RootKey, const AnsiString Key, const AnsiString ListName);
extern PACKAGE bool __fastcall AllowRegKeyForEveryone(const unsigned RootKey, AnsiString Path);
extern PACKAGE bool __fastcall RegAutoExecEnabled(const TExecKind ExecKind, const AnsiString Name, /* out */ AnsiString &CmdLine);

}	/* namespace Jclregistry */
using namespace Jclregistry;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclregistry
