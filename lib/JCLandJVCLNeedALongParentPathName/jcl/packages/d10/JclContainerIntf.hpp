// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclcontainerintf.pas' rev: 10.00

#ifndef JclcontainerintfHPP
#define JclcontainerintfHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclansistrings.hpp>	// Pascal unit
#include <Jclwidestrings.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclcontainerintf
{
//-- type declarations -------------------------------------------------------
typedef System::_di_IInterface __fastcall (*TIntfApplyFunction)(const System::_di_IInterface AInterface);

typedef AnsiString __fastcall (*TAnsiStrApplyFunction)(const AnsiString AString);

typedef WideString __fastcall (*TWideStrApplyFunction)(const WideString AString);

typedef AnsiString __fastcall (*TStrApplyFunction)(const AnsiString AString);

typedef float __fastcall (*TSingleApplyFunction)(const float AValue);

typedef double __fastcall (*TDoubleApplyFunction)(const double AValue);

typedef Extended __fastcall (*TExtendedApplyFunction)(const Extended AValue);

typedef Extended __fastcall (*TFloatApplyFunction)(const Extended AValue);

typedef int __fastcall (*TIntegerApplyFunction)(int AValue);

typedef unsigned __fastcall (*TCardinalApplyFunction)(unsigned AValue);

typedef __int64 __fastcall (*TInt64ApplyFunction)(const __int64 AValue);

typedef void * __fastcall (*TPtrApplyFunction)(void * APtr);

typedef System::TObject* __fastcall (*TApplyFunction)(System::TObject* AObject);

typedef int __fastcall (*TIntfCompare)(const System::_di_IInterface Obj1, const System::_di_IInterface Obj2);

typedef int __fastcall (*TAnsiStrCompare)(const AnsiString Obj1, const AnsiString Obj2);

typedef int __fastcall (*TWideStrCompare)(const WideString Obj1, const WideString Obj2);

typedef int __fastcall (*TStrCompare)(const AnsiString Obj1, const AnsiString Obj2);

typedef int __fastcall (*TSingleCompare)(const float Obj1, const float Obj2);

typedef int __fastcall (*TDoubleCompare)(const double Obj1, const double Obj2);

typedef int __fastcall (*TExtendedCompare)(const Extended Obj1, const Extended Obj2);

typedef int __fastcall (*TFloatCompare)(const Extended Obj1, const Extended Obj2);

typedef int __fastcall (*TIntegerCompare)(int Obj1, int Obj2);

typedef int __fastcall (*TCardinalCompare)(unsigned Obj1, unsigned Obj2);

typedef int __fastcall (*TInt64Compare)(__int64 Obj1, __int64 Obj2);

typedef int __fastcall (*TPtrCompare)(void * Obj1, void * Obj2);

typedef int __fastcall (*TCompare)(System::TObject* Obj1, System::TObject* Obj2);

typedef bool __fastcall (*TIntfEqualityCompare)(const System::_di_IInterface Obj1, const System::_di_IInterface Obj2);

typedef bool __fastcall (*TAnsiStrEqualityCompare)(const AnsiString Obj1, const AnsiString Obj2);

typedef bool __fastcall (*TWideStrEqualityCompare)(const WideString Obj1, const WideString Obj2);

typedef bool __fastcall (*TStrEqualityCompare)(const AnsiString Obj1, const AnsiString Obj2);

typedef bool __fastcall (*TSingleEqualityCompare)(const float Obj1, const float Obj2);

typedef bool __fastcall (*TDoubleEqualityCompare)(const double Obj1, const double Obj2);

typedef bool __fastcall (*TExtendedEqualityCompare)(const Extended Obj1, const Extended Obj2);

typedef bool __fastcall (*TFloatEqualityCompare)(const Extended Obj1, const Extended Obj2);

typedef bool __fastcall (*TIntegerEqualityCompare)(int Obj1, int Obj2);

typedef bool __fastcall (*TCardinalEqualityCompare)(unsigned Obj1, unsigned Obj2);

typedef bool __fastcall (*TInt64EqualityCompare)(const __int64 Obj1, const __int64 Obj2);

typedef bool __fastcall (*TPtrEqualityCompare)(void * Obj1, void * Obj2);

typedef bool __fastcall (*TEqualityCompare)(System::TObject* Obj1, System::TObject* Obj2);

typedef int __fastcall (*TIntfHashConvert)(const System::_di_IInterface AInterface);

typedef int __fastcall (*TAnsiStrHashConvert)(const AnsiString AString);

typedef int __fastcall (*TWideStrHashConvert)(const WideString AString);

typedef int __fastcall (*TStrHashConvert)(const AnsiString AString);

typedef int __fastcall (*TSingleHashConvert)(const float AValue);

typedef int __fastcall (*TDoubleHashConvert)(const double AValue);

typedef int __fastcall (*TExtendedHashConvert)(const Extended AValue);

typedef int __fastcall (*TFloatHashConvert)(const Extended AValue);

typedef int __fastcall (*TIntegerHashConvert)(int AValue);

typedef int __fastcall (*TCardinalHashConvert)(unsigned AValue);

typedef int __fastcall (*TInt64HashConvert)(const __int64 AValue);

typedef int __fastcall (*TPtrHashConvert)(void * APtr);

typedef int __fastcall (*THashConvert)(System::TObject* AObject);

__interface IJclLockable;
typedef System::DelphiInterface<IJclLockable> _di_IJclLockable;
__interface  INTERFACE_UUID("{524AD65E-AE1B-4BC6-91C8-8181F0198BA9}") IJclLockable  : public IInterface 
{
	
public:
	virtual void __fastcall ReadLock(void) = 0 ;
	virtual void __fastcall ReadUnlock(void) = 0 ;
	virtual void __fastcall WriteLock(void) = 0 ;
	virtual void __fastcall WriteUnlock(void) = 0 ;
};

__interface IJclAbstractIterator;
typedef System::DelphiInterface<IJclAbstractIterator> _di_IJclAbstractIterator;
__interface  INTERFACE_UUID("{1064D0B4-D9FC-475D-88BE-520490013B46}") IJclAbstractIterator  : public IJclLockable 
{
	
public:
	virtual void __fastcall Assign(const _di_IJclAbstractIterator Source) = 0 ;
	virtual void __fastcall AssignTo(const _di_IJclAbstractIterator Dest) = 0 ;
	virtual System::TObject* __fastcall GetIteratorReference(void) = 0 ;
};

__interface IJclContainer;
typedef System::DelphiInterface<IJclContainer> _di_IJclContainer;
__interface  INTERFACE_UUID("{C517175A-028E-486A-BF27-5EF7FC3101D9}") IJclContainer  : public IJclLockable 
{
	
public:
	virtual void __fastcall Assign(const _di_IJclContainer Source) = 0 ;
	virtual void __fastcall AssignTo(const _di_IJclContainer Dest) = 0 ;
	virtual bool __fastcall GetAllowDefaultElements(void) = 0 ;
	virtual System::TObject* __fastcall GetContainerReference(void) = 0 ;
	virtual Classes::TDuplicates __fastcall GetDuplicates(void) = 0 ;
	virtual bool __fastcall GetReadOnly(void) = 0 ;
	virtual bool __fastcall GetRemoveSingleElement(void) = 0 ;
	virtual bool __fastcall GetReturnDefaultElements(void) = 0 ;
	virtual bool __fastcall GetThreadSafe(void) = 0 ;
	virtual void __fastcall SetAllowDefaultElements(bool Value) = 0 ;
	virtual void __fastcall SetDuplicates(Classes::TDuplicates Value) = 0 ;
	virtual void __fastcall SetReadOnly(bool Value) = 0 ;
	virtual void __fastcall SetRemoveSingleElement(bool Value) = 0 ;
	virtual void __fastcall SetReturnDefaultElements(bool Value) = 0 ;
	virtual void __fastcall SetThreadSafe(bool Value) = 0 ;
	__property bool AllowDefaultElements = {read=GetAllowDefaultElements, write=SetAllowDefaultElements};
	__property Classes::TDuplicates Duplicates = {read=GetDuplicates, write=SetDuplicates};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly};
	__property bool RemoveSingleElement = {read=GetRemoveSingleElement, write=SetRemoveSingleElement};
	__property bool ReturnDefaultElements = {read=GetReturnDefaultElements, write=SetReturnDefaultElements};
	__property bool ThreadSafe = {read=GetThreadSafe, write=SetThreadSafe};
};

__interface IJclStrContainer;
typedef System::DelphiInterface<IJclStrContainer> _di_IJclStrContainer;
__interface  INTERFACE_UUID("{9753E1D7-F093-4D5C-8B32-40403F6F700E}") IJclStrContainer  : public IJclContainer 
{
	
public:
	virtual bool __fastcall GetCaseSensitive(void) = 0 ;
	virtual void __fastcall SetCaseSensitive(bool Value) = 0 ;
	__property bool CaseSensitive = {read=GetCaseSensitive, write=SetCaseSensitive};
};

#pragma option push -b-
enum TJclAnsiStrEncoding { seISO, seUTF8 };
#pragma option pop

__interface IJclAnsiStrContainer;
typedef System::DelphiInterface<IJclAnsiStrContainer> _di_IJclAnsiStrContainer;
__interface  INTERFACE_UUID("{F8239357-B96F-46F1-A48E-B5DF25B5F1FA}") IJclAnsiStrContainer  : public IJclStrContainer 
{
	
public:
	virtual TJclAnsiStrEncoding __fastcall GetEncoding(void) = 0 ;
	virtual void __fastcall SetEncoding(TJclAnsiStrEncoding Value) = 0 ;
	__property TJclAnsiStrEncoding Encoding = {read=GetEncoding, write=SetEncoding};
};

__interface IJclAnsiStrFlatContainer;
typedef System::DelphiInterface<IJclAnsiStrFlatContainer> _di_IJclAnsiStrFlatContainer;
__interface  INTERFACE_UUID("{8A45A4D4-6317-4CDF-8314-C3E5CC6899F4}") IJclAnsiStrFlatContainer  : public IJclAnsiStrContainer 
{
	
public:
	virtual void __fastcall LoadFromStrings(Classes::TStrings* Strings) = 0 ;
	virtual void __fastcall SaveToStrings(Classes::TStrings* Strings) = 0 ;
	virtual void __fastcall AppendToStrings(Classes::TStrings* Strings) = 0 ;
	virtual void __fastcall AppendFromStrings(Classes::TStrings* Strings) = 0 ;
	virtual Classes::TStrings* __fastcall GetAsStrings(void) = 0 ;
	virtual AnsiString __fastcall GetAsDelimited(const AnsiString Separator = "\r\n") = 0 ;
	virtual void __fastcall AppendDelimited(const AnsiString AString, const AnsiString Separator = "\r\n") = 0 ;
	virtual void __fastcall LoadDelimited(const AnsiString AString, const AnsiString Separator = "\r\n") = 0 ;
};

#pragma option push -b-
enum TJclWideStrEncoding { seUTF16 };
#pragma option pop

__interface IJclWideStrContainer;
typedef System::DelphiInterface<IJclWideStrContainer> _di_IJclWideStrContainer;
__interface  INTERFACE_UUID("{875E1AC4-CA22-46BC-8999-048E5B9BF11D}") IJclWideStrContainer  : public IJclStrContainer 
{
	
public:
	virtual TJclWideStrEncoding __fastcall GetEncoding(void) = 0 ;
	virtual void __fastcall SetEncoding(TJclWideStrEncoding Value) = 0 ;
	__property TJclWideStrEncoding Encoding = {read=GetEncoding, write=SetEncoding};
};

__interface IJclWideStrFlatContainer;
typedef System::DelphiInterface<IJclWideStrFlatContainer> _di_IJclWideStrFlatContainer;
__interface  INTERFACE_UUID("{5B001B93-CA1C-47A8-98B8-451CCB444930}") IJclWideStrFlatContainer  : public IJclWideStrContainer 
{
	
public:
	virtual void __fastcall LoadFromStrings(Jclwidestrings::TJclWideStrings* Strings) = 0 ;
	virtual void __fastcall SaveToStrings(Jclwidestrings::TJclWideStrings* Strings) = 0 ;
	virtual void __fastcall AppendToStrings(Jclwidestrings::TJclWideStrings* Strings) = 0 ;
	virtual void __fastcall AppendFromStrings(Jclwidestrings::TJclWideStrings* Strings) = 0 ;
	virtual Jclwidestrings::TJclWideStrings* __fastcall GetAsStrings(void) = 0 ;
	virtual WideString __fastcall GetAsDelimited(const WideString Separator = L"\r\n") = 0 ;
	virtual void __fastcall AppendDelimited(const WideString AString, const WideString Separator = L"\r\n") = 0 ;
	virtual void __fastcall LoadDelimited(const WideString AString, const WideString Separator = L"\r\n") = 0 ;
};

__interface IJclSingleContainer;
typedef System::DelphiInterface<IJclSingleContainer> _di_IJclSingleContainer;
__interface  INTERFACE_UUID("{22BE88BD-87D1-4B4D-9FAB-F1B6D555C6A9}") IJclSingleContainer  : public IJclContainer 
{
	
public:
	virtual float __fastcall GetPrecision(void) = 0 ;
	virtual void __fastcall SetPrecision(const float Value) = 0 ;
	__property float Precision = {read=GetPrecision, write=SetPrecision};
};

__interface IJclDoubleContainer;
typedef System::DelphiInterface<IJclDoubleContainer> _di_IJclDoubleContainer;
__interface  INTERFACE_UUID("{372B9354-DF6D-4CAA-A5A9-C50E1FEE5525}") IJclDoubleContainer  : public IJclContainer 
{
	
public:
	virtual double __fastcall GetPrecision(void) = 0 ;
	virtual void __fastcall SetPrecision(const double Value) = 0 ;
	__property double Precision = {read=GetPrecision, write=SetPrecision};
};

__interface IJclExtendedContainer;
typedef System::DelphiInterface<IJclExtendedContainer> _di_IJclExtendedContainer;
__interface  INTERFACE_UUID("{431A6482-FD5C-45A7-BE53-339A3CF75AC9}") IJclExtendedContainer  : public IJclContainer 
{
	
public:
	virtual Extended __fastcall GetPrecision(void) = 0 ;
	virtual void __fastcall SetPrecision(const Extended Value) = 0 ;
	__property Extended Precision = {read=GetPrecision, write=SetPrecision};
};

typedef IJclExtendedContainer IJclFloatContainer;
;

__interface IJclIntfEqualityComparer;
typedef System::DelphiInterface<IJclIntfEqualityComparer> _di_IJclIntfEqualityComparer;
__interface  INTERFACE_UUID("{5CC2DF51-BE56-4D02-A171-31BAAC097632}") IJclIntfEqualityComparer  : public IInterface 
{
	
public:
	virtual TIntfEqualityCompare __fastcall GetEqualityCompare(void) = 0 ;
	virtual void __fastcall SetEqualityCompare(TIntfEqualityCompare Value) = 0 ;
	virtual bool __fastcall ItemsEqual(const System::_di_IInterface A, const System::_di_IInterface B) = 0 ;
	__property TIntfEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
};

__interface IJclAnsiStrEqualityComparer;
typedef System::DelphiInterface<IJclAnsiStrEqualityComparer> _di_IJclAnsiStrEqualityComparer;
__interface  INTERFACE_UUID("{E3DB9016-F0D0-4CE0-B156-4C5DCA47FD3B}") IJclAnsiStrEqualityComparer  : public IInterface 
{
	
public:
	virtual TAnsiStrEqualityCompare __fastcall GetEqualityCompare(void) = 0 ;
	virtual void __fastcall SetEqualityCompare(TAnsiStrEqualityCompare Value) = 0 ;
	virtual bool __fastcall ItemsEqual(const AnsiString A, const AnsiString B) = 0 ;
	__property TAnsiStrEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
};

__interface IJclWideStrEqualityComparer;
typedef System::DelphiInterface<IJclWideStrEqualityComparer> _di_IJclWideStrEqualityComparer;
__interface  INTERFACE_UUID("{2E5696C9-8374-4347-9DC9-B3722F47F5FB}") IJclWideStrEqualityComparer  : public IInterface 
{
	
public:
	virtual TWideStrEqualityCompare __fastcall GetEqualityCompare(void) = 0 ;
	virtual void __fastcall SetEqualityCompare(TWideStrEqualityCompare Value) = 0 ;
	virtual bool __fastcall ItemsEqual(const WideString A, const WideString B) = 0 ;
	__property TWideStrEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
};

typedef IJclAnsiStrEqualityComparer IJclStrEqualityComparer;
;

__interface IJclSingleEqualityComparer;
typedef System::DelphiInterface<IJclSingleEqualityComparer> _di_IJclSingleEqualityComparer;
__interface  INTERFACE_UUID("{4835BC5B-1A87-4864-BFE1-778F3BAF26B1}") IJclSingleEqualityComparer  : public IInterface 
{
	
public:
	virtual TSingleEqualityCompare __fastcall GetEqualityCompare(void) = 0 ;
	virtual void __fastcall SetEqualityCompare(TSingleEqualityCompare Value) = 0 ;
	virtual bool __fastcall ItemsEqual(const float A, const float B) = 0 ;
	__property TSingleEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
};

__interface IJclDoubleEqualityComparer;
typedef System::DelphiInterface<IJclDoubleEqualityComparer> _di_IJclDoubleEqualityComparer;
__interface  INTERFACE_UUID("{15F0A9F0-D5DC-4978-8CDB-53B6E510262C}") IJclDoubleEqualityComparer  : public IInterface 
{
	
public:
	virtual TDoubleEqualityCompare __fastcall GetEqualityCompare(void) = 0 ;
	virtual void __fastcall SetEqualityCompare(TDoubleEqualityCompare Value) = 0 ;
	virtual bool __fastcall ItemsEqual(const double A, const double B) = 0 ;
	__property TDoubleEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
};

__interface IJclExtendedEqualityComparer;
typedef System::DelphiInterface<IJclExtendedEqualityComparer> _di_IJclExtendedEqualityComparer;
__interface  INTERFACE_UUID("{149883D5-4138-4570-8C5C-99F186B7E646}") IJclExtendedEqualityComparer  : public IInterface 
{
	
public:
	virtual TExtendedEqualityCompare __fastcall GetEqualityCompare(void) = 0 ;
	virtual void __fastcall SetEqualityCompare(TExtendedEqualityCompare Value) = 0 ;
	virtual bool __fastcall ItemsEqual(const Extended A, const Extended B) = 0 ;
	__property TExtendedEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
};

typedef IJclExtendedEqualityComparer IJclFloatEqualityComparer;
;

__interface IJclIntegerEqualityComparer;
typedef System::DelphiInterface<IJclIntegerEqualityComparer> _di_IJclIntegerEqualityComparer;
__interface  INTERFACE_UUID("{AABC35E6-A779-4A44-B748-27BFCB34FDFB}") IJclIntegerEqualityComparer  : public IInterface 
{
	
public:
	virtual TIntegerEqualityCompare __fastcall GetEqualityCompare(void) = 0 ;
	virtual void __fastcall SetEqualityCompare(TIntegerEqualityCompare Value) = 0 ;
	virtual bool __fastcall ItemsEqual(int A, int B) = 0 ;
	__property TIntegerEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
};

__interface IJclCardinalEqualityComparer;
typedef System::DelphiInterface<IJclCardinalEqualityComparer> _di_IJclCardinalEqualityComparer;
__interface  INTERFACE_UUID("{B2DECF81-6ECE-4D9F-80E1-C8C884DB407C}") IJclCardinalEqualityComparer  : public IInterface 
{
	
public:
	virtual TCardinalEqualityCompare __fastcall GetEqualityCompare(void) = 0 ;
	virtual void __fastcall SetEqualityCompare(TCardinalEqualityCompare Value) = 0 ;
	virtual bool __fastcall ItemsEqual(unsigned A, unsigned B) = 0 ;
	__property TCardinalEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
};

__interface IJclInt64EqualityComparer;
typedef System::DelphiInterface<IJclInt64EqualityComparer> _di_IJclInt64EqualityComparer;
__interface  INTERFACE_UUID("{8B2825E2-0C81-42BA-AC0D-104344CE7E56}") IJclInt64EqualityComparer  : public IInterface 
{
	
public:
	virtual TInt64EqualityCompare __fastcall GetEqualityCompare(void) = 0 ;
	virtual void __fastcall SetEqualityCompare(TInt64EqualityCompare Value) = 0 ;
	virtual bool __fastcall ItemsEqual(const __int64 A, const __int64 B) = 0 ;
	__property TInt64EqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
};

__interface IJclPtrEqualityComparer;
typedef System::DelphiInterface<IJclPtrEqualityComparer> _di_IJclPtrEqualityComparer;
__interface  INTERFACE_UUID("{C6B7CBF9-ECD9-4D70-85CC-4E2367A1D806}") IJclPtrEqualityComparer  : public IInterface 
{
	
public:
	virtual TPtrEqualityCompare __fastcall GetEqualityCompare(void) = 0 ;
	virtual void __fastcall SetEqualityCompare(TPtrEqualityCompare Value) = 0 ;
	virtual bool __fastcall ItemsEqual(void * A, void * B) = 0 ;
	__property TPtrEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
};

__interface IJclEqualityComparer;
typedef System::DelphiInterface<IJclEqualityComparer> _di_IJclEqualityComparer;
__interface  INTERFACE_UUID("{82C67986-8365-44AB-8D56-7B0CF4F6B918}") IJclEqualityComparer  : public IInterface 
{
	
public:
	virtual TEqualityCompare __fastcall GetEqualityCompare(void) = 0 ;
	virtual void __fastcall SetEqualityCompare(TEqualityCompare Value) = 0 ;
	virtual bool __fastcall ItemsEqual(System::TObject* A, System::TObject* B) = 0 ;
	__property TEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
};

__interface IJclIntfComparer;
typedef System::DelphiInterface<IJclIntfComparer> _di_IJclIntfComparer;
__interface  INTERFACE_UUID("{EB41B843-184B-420D-B5DA-27D055B4CD55}") IJclIntfComparer  : public IInterface 
{
	
public:
	virtual TIntfCompare __fastcall GetCompare(void) = 0 ;
	virtual void __fastcall SetCompare(TIntfCompare Value) = 0 ;
	virtual int __fastcall ItemsCompare(const System::_di_IInterface A, const System::_di_IInterface B) = 0 ;
	__property TIntfCompare Compare = {read=GetCompare, write=SetCompare};
};

__interface IJclAnsiStrComparer;
typedef System::DelphiInterface<IJclAnsiStrComparer> _di_IJclAnsiStrComparer;
__interface  INTERFACE_UUID("{09063CBB-9226-4734-B2A0-A178C2343176}") IJclAnsiStrComparer  : public IInterface 
{
	
public:
	virtual TAnsiStrCompare __fastcall GetCompare(void) = 0 ;
	virtual void __fastcall SetCompare(TAnsiStrCompare Value) = 0 ;
	virtual int __fastcall ItemsCompare(const AnsiString A, const AnsiString B) = 0 ;
	__property TAnsiStrCompare Compare = {read=GetCompare, write=SetCompare};
};

__interface IJclWideStrComparer;
typedef System::DelphiInterface<IJclWideStrComparer> _di_IJclWideStrComparer;
__interface  INTERFACE_UUID("{7A24AEDA-25B1-4E73-B2E9-5D74011E4C9C}") IJclWideStrComparer  : public IInterface 
{
	
public:
	virtual TWideStrCompare __fastcall GetCompare(void) = 0 ;
	virtual void __fastcall SetCompare(TWideStrCompare Value) = 0 ;
	virtual int __fastcall ItemsCompare(const WideString A, const WideString B) = 0 ;
	__property TWideStrCompare Compare = {read=GetCompare, write=SetCompare};
};

typedef IJclAnsiStrComparer IJclStrComparer;
;

__interface IJclSingleComparer;
typedef System::DelphiInterface<IJclSingleComparer> _di_IJclSingleComparer;
__interface  INTERFACE_UUID("{008225CE-075E-4450-B9DE-9863CB6D347C}") IJclSingleComparer  : public IInterface 
{
	
public:
	virtual TSingleCompare __fastcall GetCompare(void) = 0 ;
	virtual void __fastcall SetCompare(TSingleCompare Value) = 0 ;
	virtual int __fastcall ItemsCompare(const float A, const float B) = 0 ;
	__property TSingleCompare Compare = {read=GetCompare, write=SetCompare};
};

__interface IJclDoubleComparer;
typedef System::DelphiInterface<IJclDoubleComparer> _di_IJclDoubleComparer;
__interface  INTERFACE_UUID("{BC245D7F-7EB9-43D0-81B4-EE215486A5AA}") IJclDoubleComparer  : public IInterface 
{
	
public:
	virtual TDoubleCompare __fastcall GetCompare(void) = 0 ;
	virtual void __fastcall SetCompare(TDoubleCompare Value) = 0 ;
	virtual int __fastcall ItemsCompare(const double A, const double B) = 0 ;
	__property TDoubleCompare Compare = {read=GetCompare, write=SetCompare};
};

__interface IJclExtendedComparer;
typedef System::DelphiInterface<IJclExtendedComparer> _di_IJclExtendedComparer;
__interface  INTERFACE_UUID("{92657C66-C18D-4BF8-A538-A3B0140320BB}") IJclExtendedComparer  : public IInterface 
{
	
public:
	virtual TExtendedCompare __fastcall GetCompare(void) = 0 ;
	virtual void __fastcall SetCompare(TExtendedCompare Value) = 0 ;
	virtual int __fastcall ItemsCompare(const Extended A, const Extended B) = 0 ;
	__property TExtendedCompare Compare = {read=GetCompare, write=SetCompare};
};

typedef IJclExtendedComparer IJclFloatComparer;
;

__interface IJclIntegerComparer;
typedef System::DelphiInterface<IJclIntegerComparer> _di_IJclIntegerComparer;
__interface  INTERFACE_UUID("{362C3A6A-CBC1-4D5F-8652-158913DC9865}") IJclIntegerComparer  : public IInterface 
{
	
public:
	virtual TIntegerCompare __fastcall GetCompare(void) = 0 ;
	virtual void __fastcall SetCompare(TIntegerCompare Value) = 0 ;
	virtual int __fastcall ItemsCompare(int A, int B) = 0 ;
	__property TIntegerCompare Compare = {read=GetCompare, write=SetCompare};
};

__interface IJclCardinalComparer;
typedef System::DelphiInterface<IJclCardinalComparer> _di_IJclCardinalComparer;
__interface  INTERFACE_UUID("{56E44725-00B9-4530-8CC2-72DCA9171EE0}") IJclCardinalComparer  : public IInterface 
{
	
public:
	virtual TCardinalCompare __fastcall GetCompare(void) = 0 ;
	virtual void __fastcall SetCompare(TCardinalCompare Value) = 0 ;
	virtual int __fastcall ItemsCompare(unsigned A, unsigned B) = 0 ;
	__property TCardinalCompare Compare = {read=GetCompare, write=SetCompare};
};

__interface IJclInt64Comparer;
typedef System::DelphiInterface<IJclInt64Comparer> _di_IJclInt64Comparer;
__interface  INTERFACE_UUID("{87C935BF-3A42-4F1F-A474-9C823939EE1C}") IJclInt64Comparer  : public IInterface 
{
	
public:
	virtual TInt64Compare __fastcall GetCompare(void) = 0 ;
	virtual void __fastcall SetCompare(TInt64Compare Value) = 0 ;
	virtual int __fastcall ItemsCompare(const __int64 A, const __int64 B) = 0 ;
	__property TInt64Compare Compare = {read=GetCompare, write=SetCompare};
};

__interface IJclPtrComparer;
typedef System::DelphiInterface<IJclPtrComparer> _di_IJclPtrComparer;
__interface  INTERFACE_UUID("{85557D4C-A036-477E-BA73-B5EEF43A8696}") IJclPtrComparer  : public IInterface 
{
	
public:
	virtual TPtrCompare __fastcall GetCompare(void) = 0 ;
	virtual void __fastcall SetCompare(TPtrCompare Value) = 0 ;
	virtual int __fastcall ItemsCompare(void * A, void * B) = 0 ;
	__property TPtrCompare Compare = {read=GetCompare, write=SetCompare};
};

__interface IJclComparer;
typedef System::DelphiInterface<IJclComparer> _di_IJclComparer;
__interface  INTERFACE_UUID("{7B376028-56DC-4C4A-86A9-1AC19E3EDF75}") IJclComparer  : public IInterface 
{
	
public:
	virtual TCompare __fastcall GetCompare(void) = 0 ;
	virtual void __fastcall SetCompare(TCompare Value) = 0 ;
	virtual int __fastcall ItemsCompare(System::TObject* A, System::TObject* B) = 0 ;
	__property TCompare Compare = {read=GetCompare, write=SetCompare};
};

__interface IJclIntfHashConverter;
typedef System::DelphiInterface<IJclIntfHashConverter> _di_IJclIntfHashConverter;
__interface  INTERFACE_UUID("{7BAA0791-3B45-4D0F-9CD8-D13B81694786}") IJclIntfHashConverter  : public IInterface 
{
	
public:
	virtual TIntfHashConvert __fastcall GetHashConvert(void) = 0 ;
	virtual void __fastcall SetHashConvert(TIntfHashConvert Value) = 0 ;
	virtual int __fastcall Hash(const System::_di_IInterface AInterface) = 0 ;
	__property TIntfHashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
};

__interface IJclAnsiStrHashConverter;
typedef System::DelphiInterface<IJclAnsiStrHashConverter> _di_IJclAnsiStrHashConverter;
__interface  INTERFACE_UUID("{9841014E-8A31-4C79-8AD5-EB03C4E85533}") IJclAnsiStrHashConverter  : public IInterface 
{
	
public:
	virtual TAnsiStrHashConvert __fastcall GetHashConvert(void) = 0 ;
	virtual void __fastcall SetHashConvert(TAnsiStrHashConvert Value) = 0 ;
	virtual int __fastcall Hash(const AnsiString AString) = 0 ;
	__property TAnsiStrHashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
};

__interface IJclWideStrHashConverter;
typedef System::DelphiInterface<IJclWideStrHashConverter> _di_IJclWideStrHashConverter;
__interface  INTERFACE_UUID("{2584118F-19AE-443E-939B-0DB18BCD0117}") IJclWideStrHashConverter  : public IInterface 
{
	
public:
	virtual TWideStrHashConvert __fastcall GetHashConvert(void) = 0 ;
	virtual void __fastcall SetHashConvert(TWideStrHashConvert Value) = 0 ;
	virtual int __fastcall Hash(const WideString AString) = 0 ;
	__property TWideStrHashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
};

typedef IJclAnsiStrHashConverter IJclStrHashConverter;
;

__interface IJclSingleHashConverter;
typedef System::DelphiInterface<IJclSingleHashConverter> _di_IJclSingleHashConverter;
__interface  INTERFACE_UUID("{20F0E481-F1D2-48B6-A95D-FBB56AF119F5}") IJclSingleHashConverter  : public IInterface 
{
	
public:
	virtual TSingleHashConvert __fastcall GetHashConvert(void) = 0 ;
	virtual void __fastcall SetHashConvert(TSingleHashConvert Value) = 0 ;
	virtual int __fastcall Hash(const float AValue) = 0 ;
	__property TSingleHashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
};

__interface IJclDoubleHashConverter;
typedef System::DelphiInterface<IJclDoubleHashConverter> _di_IJclDoubleHashConverter;
__interface  INTERFACE_UUID("{193A2881-535B-4AF4-B0C3-6845A2800F80}") IJclDoubleHashConverter  : public IInterface 
{
	
public:
	virtual TDoubleHashConvert __fastcall GetHashConvert(void) = 0 ;
	virtual void __fastcall SetHashConvert(TDoubleHashConvert Value) = 0 ;
	virtual int __fastcall Hash(const double AValue) = 0 ;
	__property TDoubleHashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
};

__interface IJclExtendedHashConverter;
typedef System::DelphiInterface<IJclExtendedHashConverter> _di_IJclExtendedHashConverter;
__interface  INTERFACE_UUID("{77CECDB9-2774-4FDC-8E5A-A80325626434}") IJclExtendedHashConverter  : public IInterface 
{
	
public:
	virtual TExtendedHashConvert __fastcall GetHashConvert(void) = 0 ;
	virtual void __fastcall SetHashConvert(TExtendedHashConvert Value) = 0 ;
	virtual int __fastcall Hash(const Extended AValue) = 0 ;
	__property TExtendedHashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
};

typedef IJclExtendedHashConverter IJclFloatHashConverter;
;

__interface IJclIntegerHashConverter;
typedef System::DelphiInterface<IJclIntegerHashConverter> _di_IJclIntegerHashConverter;
__interface  INTERFACE_UUID("{92C540B2-C16C-47E4-995A-644BE71878B1}") IJclIntegerHashConverter  : public IInterface 
{
	
public:
	virtual TIntegerHashConvert __fastcall GetHashConvert(void) = 0 ;
	virtual void __fastcall SetHashConvert(TIntegerHashConvert Value) = 0 ;
	virtual int __fastcall Hash(int AValue) = 0 ;
	__property TIntegerHashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
};

__interface IJclCardinalHashConverter;
typedef System::DelphiInterface<IJclCardinalHashConverter> _di_IJclCardinalHashConverter;
__interface  INTERFACE_UUID("{2DF04C8A-16B8-4712-BC5D-AD35014EC9F7}") IJclCardinalHashConverter  : public IInterface 
{
	
public:
	virtual TCardinalHashConvert __fastcall GetHashConvert(void) = 0 ;
	virtual void __fastcall SetHashConvert(TCardinalHashConvert Value) = 0 ;
	virtual int __fastcall Hash(unsigned AValue) = 0 ;
	__property TCardinalHashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
};

__interface IJclInt64HashConverter;
typedef System::DelphiInterface<IJclInt64HashConverter> _di_IJclInt64HashConverter;
__interface  INTERFACE_UUID("{96CF2A71-9185-4E26-B283-457ABC3584E7}") IJclInt64HashConverter  : public IInterface 
{
	
public:
	virtual TInt64HashConvert __fastcall GetHashConvert(void) = 0 ;
	virtual void __fastcall SetHashConvert(TInt64HashConvert Value) = 0 ;
	virtual int __fastcall Hash(const __int64 AValue) = 0 ;
	__property TInt64HashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
};

__interface IJclPtrHashConverter;
typedef System::DelphiInterface<IJclPtrHashConverter> _di_IJclPtrHashConverter;
__interface  INTERFACE_UUID("{D704CC67-CFED-44E6-9504-65D5E468FCAF}") IJclPtrHashConverter  : public IInterface 
{
	
public:
	virtual TPtrHashConvert __fastcall GetHashConvert(void) = 0 ;
	virtual void __fastcall SetHashConvert(TPtrHashConvert Value) = 0 ;
	virtual int __fastcall Hash(void * Ptr) = 0 ;
	__property TPtrHashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
};

__interface IJclHashConverter;
typedef System::DelphiInterface<IJclHashConverter> _di_IJclHashConverter;
__interface  INTERFACE_UUID("{2D0DD6F4-162E-41D6-8A34-489E7EACABCD}") IJclHashConverter  : public IInterface 
{
	
public:
	virtual THashConvert __fastcall GetHashConvert(void) = 0 ;
	virtual void __fastcall SetHashConvert(THashConvert Value) = 0 ;
	virtual int __fastcall Hash(System::TObject* AObject) = 0 ;
	__property THashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
};

__interface IJclIntfCloneable;
typedef System::DelphiInterface<IJclIntfCloneable> _di_IJclIntfCloneable;
__interface  INTERFACE_UUID("{BCF77740-FB60-4306-9BD1-448AADE5FF4E}") IJclIntfCloneable  : public IInterface 
{
	
public:
	virtual System::_di_IInterface __fastcall IntfClone(void) = 0 ;
};

__interface IJclCloneable;
typedef System::DelphiInterface<IJclCloneable> _di_IJclCloneable;
__interface  INTERFACE_UUID("{D224AE70-2C93-4998-9479-1D513D75F2B2}") IJclCloneable  : public IInterface 
{
	
public:
	virtual System::TObject* __fastcall ObjectClone(void) = 0 ;
};

#pragma option push -b-
enum TJclAutoPackStrategy { apsDisabled, apsAgressive, apsProportional, apsIncremental };
#pragma option pop

__interface IJclPackable;
typedef System::DelphiInterface<IJclPackable> _di_IJclPackable;
__interface  INTERFACE_UUID("{03802D2B-E0AB-4300-A777-0B8A2BD993DF}") IJclPackable  : public IInterface 
{
	
public:
	virtual int __fastcall CalcGrowCapacity(int ACapacity, int ASize) = 0 ;
	virtual int __fastcall GetAutoPackParameter(void) = 0 ;
	virtual TJclAutoPackStrategy __fastcall GetAutoPackStrategy(void) = 0 ;
	virtual int __fastcall GetCapacity(void) = 0 ;
	virtual void __fastcall Pack(void) = 0 ;
	virtual void __fastcall SetAutoPackParameter(int Value) = 0 ;
	virtual void __fastcall SetAutoPackStrategy(TJclAutoPackStrategy Value) = 0 ;
	virtual void __fastcall SetCapacity(int Value) = 0 ;
	__property int AutoPackParameter = {read=GetAutoPackParameter, write=SetAutoPackParameter};
	__property TJclAutoPackStrategy AutoPackStrategy = {read=GetAutoPackStrategy, write=SetAutoPackStrategy};
	__property int Capacity = {read=GetCapacity, write=SetCapacity};
};

#pragma option push -b-
enum TJclAutoGrowStrategy { agsDisabled, agsAgressive, agsProportional, agsIncremental };
#pragma option pop

__interface IJclGrowable;
typedef System::DelphiInterface<IJclGrowable> _di_IJclGrowable;
__interface  INTERFACE_UUID("{C71E8586-5688-444C-9BDD-9969D988123B}") IJclGrowable  : public IJclPackable 
{
	
public:
	virtual int __fastcall CalcPackCapacity(int ACapacity, int ASize) = 0 ;
	virtual int __fastcall GetAutoGrowParameter(void) = 0 ;
	virtual TJclAutoGrowStrategy __fastcall GetAutoGrowStrategy(void) = 0 ;
	virtual void __fastcall Grow(void) = 0 ;
	virtual void __fastcall SetAutoGrowParameter(int Value) = 0 ;
	virtual void __fastcall SetAutoGrowStrategy(TJclAutoGrowStrategy Value) = 0 ;
	__property int AutoGrowParameter = {read=GetAutoGrowParameter, write=SetAutoGrowParameter};
	__property TJclAutoGrowStrategy AutoGrowStrategy = {read=GetAutoGrowStrategy, write=SetAutoGrowStrategy};
};

__interface IJclObjectOwner;
typedef System::DelphiInterface<IJclObjectOwner> _di_IJclObjectOwner;
__interface  INTERFACE_UUID("{5157EA13-924E-4A56-995D-36956441025C}") IJclObjectOwner  : public IInterface 
{
	
public:
	virtual System::TObject* __fastcall FreeObject(System::TObject* &AObject) = 0 ;
	virtual bool __fastcall GetOwnsObjects(void) = 0 ;
	__property bool OwnsObjects = {read=GetOwnsObjects};
};

__interface IJclKeyOwner;
typedef System::DelphiInterface<IJclKeyOwner> _di_IJclKeyOwner;
__interface  INTERFACE_UUID("{8BE209E6-2F85-44FD-B0CD-A8363C95349A}") IJclKeyOwner  : public IInterface 
{
	
public:
	virtual System::TObject* __fastcall FreeKey(System::TObject* &Key) = 0 ;
	virtual bool __fastcall GetOwnsKeys(void) = 0 ;
	__property bool OwnsKeys = {read=GetOwnsKeys};
};

__interface IJclValueOwner;
typedef System::DelphiInterface<IJclValueOwner> _di_IJclValueOwner;
__interface  INTERFACE_UUID("{3BCD98CE-7056-416A-A9E7-AE3AB2A62E54}") IJclValueOwner  : public IInterface 
{
	
public:
	virtual System::TObject* __fastcall FreeValue(System::TObject* &Value) = 0 ;
	virtual bool __fastcall GetOwnsValues(void) = 0 ;
	__property bool OwnsValues = {read=GetOwnsValues};
};

__interface IJclIntfIterator;
typedef System::DelphiInterface<IJclIntfIterator> _di_IJclIntfIterator;
__interface  INTERFACE_UUID("{E121A98A-7C43-4587-806B-9189E8B2F106}") IJclIntfIterator  : public IJclAbstractIterator 
{
	
public:
	virtual bool __fastcall Add(const System::_di_IInterface AInterface) = 0 ;
	virtual void __fastcall Extract(void) = 0 ;
	virtual System::_di_IInterface __fastcall GetObject(void) = 0 ;
	virtual bool __fastcall HasNext(void) = 0 ;
	virtual bool __fastcall HasPrevious(void) = 0 ;
	virtual bool __fastcall Insert(const System::_di_IInterface AInterface) = 0 ;
	virtual bool __fastcall IteratorEquals(const _di_IJclIntfIterator AIterator) = 0 ;
	virtual System::_di_IInterface __fastcall Next(void) = 0 ;
	virtual int __fastcall NextIndex(void) = 0 ;
	virtual System::_di_IInterface __fastcall Previous(void) = 0 ;
	virtual int __fastcall PreviousIndex(void) = 0 ;
	virtual void __fastcall Remove(void) = 0 ;
	virtual void __fastcall Reset(void) = 0 ;
	virtual void __fastcall SetObject(const System::_di_IInterface AInterface) = 0 ;
	virtual bool __fastcall MoveNext(void) = 0 ;
	__property System::_di_IInterface Current = {read=GetObject};
};

__interface IJclAnsiStrIterator;
typedef System::DelphiInterface<IJclAnsiStrIterator> _di_IJclAnsiStrIterator;
__interface  INTERFACE_UUID("{D5D4B681-F902-49C7-B9E1-73007C9D64F0}") IJclAnsiStrIterator  : public IJclAbstractIterator 
{
	
public:
	virtual bool __fastcall Add(const AnsiString AString) = 0 ;
	virtual void __fastcall Extract(void) = 0 ;
	virtual AnsiString __fastcall GetString(void) = 0 ;
	virtual bool __fastcall HasNext(void) = 0 ;
	virtual bool __fastcall HasPrevious(void) = 0 ;
	virtual bool __fastcall Insert(const AnsiString AString) = 0 ;
	virtual bool __fastcall IteratorEquals(const _di_IJclAnsiStrIterator AIterator) = 0 ;
	virtual AnsiString __fastcall Next(void) = 0 ;
	virtual int __fastcall NextIndex(void) = 0 ;
	virtual AnsiString __fastcall Previous(void) = 0 ;
	virtual int __fastcall PreviousIndex(void) = 0 ;
	virtual void __fastcall Remove(void) = 0 ;
	virtual void __fastcall Reset(void) = 0 ;
	virtual void __fastcall SetString(const AnsiString AString) = 0 ;
	virtual bool __fastcall MoveNext(void) = 0 ;
	__property AnsiString Current = {read=GetString};
};

__interface IJclWideStrIterator;
typedef System::DelphiInterface<IJclWideStrIterator> _di_IJclWideStrIterator;
__interface  INTERFACE_UUID("{F03BC7D4-CCDA-4C4A-AF3A-E51FDCDE8ADE}") IJclWideStrIterator  : public IJclAbstractIterator 
{
	
public:
	virtual bool __fastcall Add(const WideString AString) = 0 ;
	virtual void __fastcall Extract(void) = 0 ;
	virtual WideString __fastcall GetString(void) = 0 ;
	virtual bool __fastcall HasNext(void) = 0 ;
	virtual bool __fastcall HasPrevious(void) = 0 ;
	virtual bool __fastcall Insert(const WideString AString) = 0 ;
	virtual bool __fastcall IteratorEquals(const _di_IJclWideStrIterator AIterator) = 0 ;
	virtual WideString __fastcall Next(void) = 0 ;
	virtual int __fastcall NextIndex(void) = 0 ;
	virtual WideString __fastcall Previous(void) = 0 ;
	virtual int __fastcall PreviousIndex(void) = 0 ;
	virtual void __fastcall Remove(void) = 0 ;
	virtual void __fastcall Reset(void) = 0 ;
	virtual void __fastcall SetString(const WideString AString) = 0 ;
	virtual bool __fastcall MoveNext(void) = 0 ;
	__property WideString Current = {read=GetString};
};

typedef IJclAnsiStrIterator IJclStrIterator;
;

__interface IJclSingleIterator;
typedef System::DelphiInterface<IJclSingleIterator> _di_IJclSingleIterator;
__interface  INTERFACE_UUID("{FD1124F8-CB2B-4AD7-B12D-C05702F4204B}") IJclSingleIterator  : public IJclAbstractIterator 
{
	
public:
	virtual bool __fastcall Add(const float AValue) = 0 ;
	virtual void __fastcall Extract(void) = 0 ;
	virtual float __fastcall GetValue(void) = 0 ;
	virtual bool __fastcall HasNext(void) = 0 ;
	virtual bool __fastcall HasPrevious(void) = 0 ;
	virtual bool __fastcall Insert(const float AValue) = 0 ;
	virtual bool __fastcall IteratorEquals(const _di_IJclSingleIterator AIterator) = 0 ;
	virtual float __fastcall Next(void) = 0 ;
	virtual int __fastcall NextIndex(void) = 0 ;
	virtual float __fastcall Previous(void) = 0 ;
	virtual int __fastcall PreviousIndex(void) = 0 ;
	virtual void __fastcall Remove(void) = 0 ;
	virtual void __fastcall Reset(void) = 0 ;
	virtual void __fastcall SetValue(const float AValue) = 0 ;
	virtual bool __fastcall MoveNext(void) = 0 ;
	__property float Current = {read=GetValue};
};

__interface IJclDoubleIterator;
typedef System::DelphiInterface<IJclDoubleIterator> _di_IJclDoubleIterator;
__interface  INTERFACE_UUID("{004C154A-281C-4DA7-BF64-F3EE80ACF640}") IJclDoubleIterator  : public IJclAbstractIterator 
{
	
public:
	virtual bool __fastcall Add(const double AValue) = 0 ;
	virtual void __fastcall Extract(void) = 0 ;
	virtual double __fastcall GetValue(void) = 0 ;
	virtual bool __fastcall HasNext(void) = 0 ;
	virtual bool __fastcall HasPrevious(void) = 0 ;
	virtual bool __fastcall Insert(const double AValue) = 0 ;
	virtual bool __fastcall IteratorEquals(const _di_IJclDoubleIterator AIterator) = 0 ;
	virtual double __fastcall Next(void) = 0 ;
	virtual int __fastcall NextIndex(void) = 0 ;
	virtual double __fastcall Previous(void) = 0 ;
	virtual int __fastcall PreviousIndex(void) = 0 ;
	virtual void __fastcall Remove(void) = 0 ;
	virtual void __fastcall Reset(void) = 0 ;
	virtual void __fastcall SetValue(const double AValue) = 0 ;
	virtual bool __fastcall MoveNext(void) = 0 ;
	__property double Current = {read=GetValue};
};

__interface IJclExtendedIterator;
typedef System::DelphiInterface<IJclExtendedIterator> _di_IJclExtendedIterator;
__interface  INTERFACE_UUID("{B89877A5-DED4-4CD9-AB90-C7D062111DE0}") IJclExtendedIterator  : public IJclAbstractIterator 
{
	
public:
	virtual bool __fastcall Add(const Extended AValue) = 0 ;
	virtual void __fastcall Extract(void) = 0 ;
	virtual Extended __fastcall GetValue(void) = 0 ;
	virtual bool __fastcall HasNext(void) = 0 ;
	virtual bool __fastcall HasPrevious(void) = 0 ;
	virtual bool __fastcall Insert(const Extended AValue) = 0 ;
	virtual bool __fastcall IteratorEquals(const _di_IJclExtendedIterator AIterator) = 0 ;
	virtual Extended __fastcall Next(void) = 0 ;
	virtual int __fastcall NextIndex(void) = 0 ;
	virtual Extended __fastcall Previous(void) = 0 ;
	virtual int __fastcall PreviousIndex(void) = 0 ;
	virtual void __fastcall Remove(void) = 0 ;
	virtual void __fastcall Reset(void) = 0 ;
	virtual void __fastcall SetValue(const Extended AValue) = 0 ;
	virtual bool __fastcall MoveNext(void) = 0 ;
	__property Extended Current = {read=GetValue};
};

typedef IJclExtendedIterator IJclFloatIterator;
;

__interface IJclIntegerIterator;
typedef System::DelphiInterface<IJclIntegerIterator> _di_IJclIntegerIterator;
__interface  INTERFACE_UUID("{1406A991-4574-48A1-83FE-2EDCA03908BE}") IJclIntegerIterator  : public IJclAbstractIterator 
{
	
public:
	virtual bool __fastcall Add(int AValue) = 0 ;
	virtual void __fastcall Extract(void) = 0 ;
	virtual int __fastcall GetValue(void) = 0 ;
	virtual bool __fastcall HasNext(void) = 0 ;
	virtual bool __fastcall HasPrevious(void) = 0 ;
	virtual bool __fastcall Insert(int AValue) = 0 ;
	virtual bool __fastcall IteratorEquals(const _di_IJclIntegerIterator AIterator) = 0 ;
	virtual int __fastcall Next(void) = 0 ;
	virtual int __fastcall NextIndex(void) = 0 ;
	virtual int __fastcall Previous(void) = 0 ;
	virtual int __fastcall PreviousIndex(void) = 0 ;
	virtual void __fastcall Remove(void) = 0 ;
	virtual void __fastcall Reset(void) = 0 ;
	virtual void __fastcall SetValue(int AValue) = 0 ;
	virtual bool __fastcall MoveNext(void) = 0 ;
	__property int Current = {read=GetValue};
};

__interface IJclCardinalIterator;
typedef System::DelphiInterface<IJclCardinalIterator> _di_IJclCardinalIterator;
__interface  INTERFACE_UUID("{72847A34-C8C4-4592-9447-CEB8161E33AD}") IJclCardinalIterator  : public IJclAbstractIterator 
{
	
public:
	virtual bool __fastcall Add(unsigned AValue) = 0 ;
	virtual void __fastcall Extract(void) = 0 ;
	virtual unsigned __fastcall GetValue(void) = 0 ;
	virtual bool __fastcall HasNext(void) = 0 ;
	virtual bool __fastcall HasPrevious(void) = 0 ;
	virtual bool __fastcall Insert(unsigned AValue) = 0 ;
	virtual bool __fastcall IteratorEquals(const _di_IJclCardinalIterator AIterator) = 0 ;
	virtual unsigned __fastcall Next(void) = 0 ;
	virtual int __fastcall NextIndex(void) = 0 ;
	virtual unsigned __fastcall Previous(void) = 0 ;
	virtual int __fastcall PreviousIndex(void) = 0 ;
	virtual void __fastcall Remove(void) = 0 ;
	virtual void __fastcall Reset(void) = 0 ;
	virtual void __fastcall SetValue(unsigned AValue) = 0 ;
	virtual bool __fastcall MoveNext(void) = 0 ;
	__property unsigned Current = {read=GetValue};
};

__interface IJclInt64Iterator;
typedef System::DelphiInterface<IJclInt64Iterator> _di_IJclInt64Iterator;
__interface  INTERFACE_UUID("{573E5A51-BF76-43D7-9F93-46305BED20A8}") IJclInt64Iterator  : public IJclAbstractIterator 
{
	
public:
	virtual bool __fastcall Add(const __int64 AValue) = 0 ;
	virtual void __fastcall Extract(void) = 0 ;
	virtual __int64 __fastcall GetValue(void) = 0 ;
	virtual bool __fastcall HasNext(void) = 0 ;
	virtual bool __fastcall HasPrevious(void) = 0 ;
	virtual bool __fastcall Insert(const __int64 AValue) = 0 ;
	virtual bool __fastcall IteratorEquals(const _di_IJclInt64Iterator AIterator) = 0 ;
	virtual __int64 __fastcall Next(void) = 0 ;
	virtual int __fastcall NextIndex(void) = 0 ;
	virtual __int64 __fastcall Previous(void) = 0 ;
	virtual int __fastcall PreviousIndex(void) = 0 ;
	virtual void __fastcall Remove(void) = 0 ;
	virtual void __fastcall Reset(void) = 0 ;
	virtual void __fastcall SetValue(const __int64 AValue) = 0 ;
	virtual bool __fastcall MoveNext(void) = 0 ;
	__property __int64 Current = {read=GetValue};
};

__interface IJclPtrIterator;
typedef System::DelphiInterface<IJclPtrIterator> _di_IJclPtrIterator;
__interface  INTERFACE_UUID("{62B5501C-07AA-4D00-A85B-713B39912CDF}") IJclPtrIterator  : public IJclAbstractIterator 
{
	
public:
	virtual bool __fastcall Add(void * APtr) = 0 ;
	virtual void __fastcall Extract(void) = 0 ;
	virtual void * __fastcall GetPointer(void) = 0 ;
	virtual bool __fastcall HasNext(void) = 0 ;
	virtual bool __fastcall HasPrevious(void) = 0 ;
	virtual bool __fastcall Insert(void * APtr) = 0 ;
	virtual bool __fastcall IteratorEquals(const _di_IJclPtrIterator AIterator) = 0 ;
	virtual void * __fastcall Next(void) = 0 ;
	virtual int __fastcall NextIndex(void) = 0 ;
	virtual void * __fastcall Previous(void) = 0 ;
	virtual int __fastcall PreviousIndex(void) = 0 ;
	virtual void __fastcall Remove(void) = 0 ;
	virtual void __fastcall Reset(void) = 0 ;
	virtual void __fastcall SetPointer(void * APtr) = 0 ;
	virtual bool __fastcall MoveNext(void) = 0 ;
	__property void * Current = {read=GetPointer};
};

__interface IJclIterator;
typedef System::DelphiInterface<IJclIterator> _di_IJclIterator;
__interface  INTERFACE_UUID("{997DF9B7-9AA2-4239-8B94-14DFFD26D790}") IJclIterator  : public IJclAbstractIterator 
{
	
public:
	virtual bool __fastcall Add(System::TObject* AObject) = 0 ;
	virtual void __fastcall Extract(void) = 0 ;
	virtual System::TObject* __fastcall GetObject(void) = 0 ;
	virtual bool __fastcall HasNext(void) = 0 ;
	virtual bool __fastcall HasPrevious(void) = 0 ;
	virtual bool __fastcall Insert(System::TObject* AObject) = 0 ;
	virtual bool __fastcall IteratorEquals(const _di_IJclIterator AIterator) = 0 ;
	virtual System::TObject* __fastcall Next(void) = 0 ;
	virtual int __fastcall NextIndex(void) = 0 ;
	virtual System::TObject* __fastcall Previous(void) = 0 ;
	virtual int __fastcall PreviousIndex(void) = 0 ;
	virtual void __fastcall Remove(void) = 0 ;
	virtual void __fastcall Reset(void) = 0 ;
	virtual void __fastcall SetObject(System::TObject* AObject) = 0 ;
	virtual bool __fastcall MoveNext(void) = 0 ;
	__property System::TObject* Current = {read=GetObject};
};

__interface IJclIntfTreeIterator;
typedef System::DelphiInterface<IJclIntfTreeIterator> _di_IJclIntfTreeIterator;
__interface  INTERFACE_UUID("{C97379BF-C6A9-4A90-9D7A-152E9BAD314F}") IJclIntfTreeIterator  : public IJclIntfIterator 
{
	
public:
	virtual bool __fastcall AddChild(const System::_di_IInterface AInterface) = 0 ;
	virtual int __fastcall ChildrenCount(void) = 0 ;
	virtual void __fastcall DeleteChild(int Index) = 0 ;
	virtual void __fastcall DeleteChildren(void) = 0 ;
	virtual void __fastcall ExtractChild(int Index) = 0 ;
	virtual void __fastcall ExtractChildren(void) = 0 ;
	virtual System::_di_IInterface __fastcall GetChild(int Index) = 0 ;
	virtual bool __fastcall HasChild(int Index) = 0 ;
	virtual bool __fastcall HasParent(void) = 0 ;
	virtual int __fastcall IndexOfChild(const System::_di_IInterface AInterface) = 0 ;
	virtual bool __fastcall InsertChild(int Index, const System::_di_IInterface AInterface) = 0 ;
	virtual System::_di_IInterface __fastcall Parent(void) = 0 ;
	virtual void __fastcall SetChild(int Index, const System::_di_IInterface AInterface) = 0 ;
	__property System::_di_IInterface Children[int Index] = {read=GetChild, write=SetChild};
};

__interface IJclAnsiStrTreeIterator;
typedef System::DelphiInterface<IJclAnsiStrTreeIterator> _di_IJclAnsiStrTreeIterator;
__interface  INTERFACE_UUID("{66BC5C76-758C-4E72-ABF1-EB02CF851C6D}") IJclAnsiStrTreeIterator  : public IJclAnsiStrIterator 
{
	
public:
	virtual bool __fastcall AddChild(const AnsiString AString) = 0 ;
	virtual int __fastcall ChildrenCount(void) = 0 ;
	virtual void __fastcall DeleteChild(int Index) = 0 ;
	virtual void __fastcall DeleteChildren(void) = 0 ;
	virtual void __fastcall ExtractChild(int Index) = 0 ;
	virtual void __fastcall ExtractChildren(void) = 0 ;
	virtual AnsiString __fastcall GetChild(int Index) = 0 ;
	virtual bool __fastcall HasChild(int Index) = 0 ;
	virtual bool __fastcall HasParent(void) = 0 ;
	virtual int __fastcall IndexOfChild(const AnsiString AString) = 0 ;
	virtual bool __fastcall InsertChild(int Index, const AnsiString AString) = 0 ;
	virtual AnsiString __fastcall Parent(void) = 0 ;
	virtual void __fastcall SetChild(int Index, const AnsiString AString) = 0 ;
	__property AnsiString Children[int Index] = {read=GetChild, write=SetChild};
};

__interface IJclWideStrTreeIterator;
typedef System::DelphiInterface<IJclWideStrTreeIterator> _di_IJclWideStrTreeIterator;
__interface  INTERFACE_UUID("{B3168A3B-5A90-4ABF-855F-3D2B3AB6EE7F}") IJclWideStrTreeIterator  : public IJclWideStrIterator 
{
	
public:
	virtual bool __fastcall AddChild(const WideString AString) = 0 ;
	virtual int __fastcall ChildrenCount(void) = 0 ;
	virtual void __fastcall DeleteChild(int Index) = 0 ;
	virtual void __fastcall DeleteChildren(void) = 0 ;
	virtual void __fastcall ExtractChild(int Index) = 0 ;
	virtual void __fastcall ExtractChildren(void) = 0 ;
	virtual WideString __fastcall GetChild(int Index) = 0 ;
	virtual bool __fastcall HasChild(int Index) = 0 ;
	virtual bool __fastcall HasParent(void) = 0 ;
	virtual int __fastcall IndexOfChild(const WideString AString) = 0 ;
	virtual bool __fastcall InsertChild(int Index, const WideString AString) = 0 ;
	virtual WideString __fastcall Parent(void) = 0 ;
	virtual void __fastcall SetChild(int Index, const WideString AString) = 0 ;
	__property WideString Children[int Index] = {read=GetChild, write=SetChild};
};

typedef IJclAnsiStrTreeIterator IJclStrTreeIterator;
;

__interface IJclSingleTreeIterator;
typedef System::DelphiInterface<IJclSingleTreeIterator> _di_IJclSingleTreeIterator;
__interface  INTERFACE_UUID("{17BFDE9D-DBF7-4DC8-AC74-919C717B4726}") IJclSingleTreeIterator  : public IJclSingleIterator 
{
	
public:
	virtual bool __fastcall AddChild(const float AValue) = 0 ;
	virtual int __fastcall ChildrenCount(void) = 0 ;
	virtual void __fastcall DeleteChild(int Index) = 0 ;
	virtual void __fastcall DeleteChildren(void) = 0 ;
	virtual void __fastcall ExtractChild(int Index) = 0 ;
	virtual void __fastcall ExtractChildren(void) = 0 ;
	virtual float __fastcall GetChild(int Index) = 0 ;
	virtual bool __fastcall HasChild(int Index) = 0 ;
	virtual bool __fastcall HasParent(void) = 0 ;
	virtual int __fastcall IndexOfChild(const float AValue) = 0 ;
	virtual bool __fastcall InsertChild(int Index, const float AValue) = 0 ;
	virtual float __fastcall Parent(void) = 0 ;
	virtual void __fastcall SetChild(int Index, const float AValue) = 0 ;
	__property float Children[int Index] = {read=GetChild, write=SetChild};
};

__interface IJclDoubleTreeIterator;
typedef System::DelphiInterface<IJclDoubleTreeIterator> _di_IJclDoubleTreeIterator;
__interface  INTERFACE_UUID("{EB39B84E-D3C5-496E-A521-B8BF24579252}") IJclDoubleTreeIterator  : public IJclDoubleIterator 
{
	
public:
	virtual bool __fastcall AddChild(const double AValue) = 0 ;
	virtual int __fastcall ChildrenCount(void) = 0 ;
	virtual void __fastcall DeleteChild(int Index) = 0 ;
	virtual void __fastcall DeleteChildren(void) = 0 ;
	virtual void __fastcall ExtractChild(int Index) = 0 ;
	virtual void __fastcall ExtractChildren(void) = 0 ;
	virtual double __fastcall GetChild(int Index) = 0 ;
	virtual bool __fastcall HasChild(int Index) = 0 ;
	virtual bool __fastcall HasParent(void) = 0 ;
	virtual int __fastcall IndexOfChild(const double AValue) = 0 ;
	virtual bool __fastcall InsertChild(int Index, const double AValue) = 0 ;
	virtual double __fastcall Parent(void) = 0 ;
	virtual void __fastcall SetChild(int Index, const double AValue) = 0 ;
	__property double Children[int Index] = {read=GetChild, write=SetChild};
};

__interface IJclExtendedTreeIterator;
typedef System::DelphiInterface<IJclExtendedTreeIterator> _di_IJclExtendedTreeIterator;
__interface  INTERFACE_UUID("{1B40A544-FC5D-454C-8E42-CE17B015E65C}") IJclExtendedTreeIterator  : public IJclExtendedIterator 
{
	
public:
	virtual bool __fastcall AddChild(const Extended AValue) = 0 ;
	virtual int __fastcall ChildrenCount(void) = 0 ;
	virtual void __fastcall DeleteChild(int Index) = 0 ;
	virtual void __fastcall DeleteChildren(void) = 0 ;
	virtual void __fastcall ExtractChild(int Index) = 0 ;
	virtual void __fastcall ExtractChildren(void) = 0 ;
	virtual Extended __fastcall GetChild(int Index) = 0 ;
	virtual bool __fastcall HasChild(int Index) = 0 ;
	virtual bool __fastcall HasParent(void) = 0 ;
	virtual int __fastcall IndexOfChild(const Extended AValue) = 0 ;
	virtual bool __fastcall InsertChild(int Index, const Extended AValue) = 0 ;
	virtual Extended __fastcall Parent(void) = 0 ;
	virtual void __fastcall SetChild(int Index, const Extended AValue) = 0 ;
	__property Extended Children[int Index] = {read=GetChild, write=SetChild};
};

typedef IJclExtendedTreeIterator IJclFloatTreeIterator;
;

__interface IJclIntegerTreeIterator;
typedef System::DelphiInterface<IJclIntegerTreeIterator> _di_IJclIntegerTreeIterator;
__interface  INTERFACE_UUID("{88EDC5C5-CA41-41AF-9838-AA19D07E69F5}") IJclIntegerTreeIterator  : public IJclIntegerIterator 
{
	
public:
	virtual bool __fastcall AddChild(int AValue) = 0 ;
	virtual int __fastcall ChildrenCount(void) = 0 ;
	virtual void __fastcall DeleteChild(int Index) = 0 ;
	virtual void __fastcall DeleteChildren(void) = 0 ;
	virtual void __fastcall ExtractChild(int Index) = 0 ;
	virtual void __fastcall ExtractChildren(void) = 0 ;
	virtual int __fastcall GetChild(int Index) = 0 ;
	virtual bool __fastcall HasChild(int Index) = 0 ;
	virtual bool __fastcall HasParent(void) = 0 ;
	virtual int __fastcall IndexOfChild(int AValue) = 0 ;
	virtual bool __fastcall InsertChild(int Index, int AValue) = 0 ;
	virtual int __fastcall Parent(void) = 0 ;
	virtual void __fastcall SetChild(int Index, int AValue) = 0 ;
	__property int Children[int Index] = {read=GetChild, write=SetChild};
};

__interface IJclCardinalTreeIterator;
typedef System::DelphiInterface<IJclCardinalTreeIterator> _di_IJclCardinalTreeIterator;
__interface  INTERFACE_UUID("{FDBF493F-F79D-46EB-A59D-7193B6E6A860}") IJclCardinalTreeIterator  : public IJclCardinalIterator 
{
	
public:
	virtual bool __fastcall AddChild(unsigned AValue) = 0 ;
	virtual int __fastcall ChildrenCount(void) = 0 ;
	virtual void __fastcall DeleteChild(int Index) = 0 ;
	virtual void __fastcall DeleteChildren(void) = 0 ;
	virtual void __fastcall ExtractChild(int Index) = 0 ;
	virtual void __fastcall ExtractChildren(void) = 0 ;
	virtual unsigned __fastcall GetChild(int Index) = 0 ;
	virtual bool __fastcall HasChild(int Index) = 0 ;
	virtual bool __fastcall HasParent(void) = 0 ;
	virtual int __fastcall IndexOfChild(unsigned AValue) = 0 ;
	virtual bool __fastcall InsertChild(int Index, unsigned AValue) = 0 ;
	virtual unsigned __fastcall Parent(void) = 0 ;
	virtual void __fastcall SetChild(int Index, unsigned AValue) = 0 ;
	__property unsigned Children[int Index] = {read=GetChild, write=SetChild};
};

__interface IJclInt64TreeIterator;
typedef System::DelphiInterface<IJclInt64TreeIterator> _di_IJclInt64TreeIterator;
__interface  INTERFACE_UUID("{C5A5E504-E19B-43AC-90B9-E4B8984BFA23}") IJclInt64TreeIterator  : public IJclInt64Iterator 
{
	
public:
	virtual bool __fastcall AddChild(const __int64 AValue) = 0 ;
	virtual int __fastcall ChildrenCount(void) = 0 ;
	virtual void __fastcall DeleteChild(int Index) = 0 ;
	virtual void __fastcall DeleteChildren(void) = 0 ;
	virtual void __fastcall ExtractChild(int Index) = 0 ;
	virtual void __fastcall ExtractChildren(void) = 0 ;
	virtual __int64 __fastcall GetChild(int Index) = 0 ;
	virtual bool __fastcall HasChild(int Index) = 0 ;
	virtual bool __fastcall HasParent(void) = 0 ;
	virtual int __fastcall IndexOfChild(const __int64 AValue) = 0 ;
	virtual bool __fastcall InsertChild(int Index, const __int64 AValue) = 0 ;
	virtual __int64 __fastcall Parent(void) = 0 ;
	virtual void __fastcall SetChild(int Index, const __int64 AValue) = 0 ;
	__property __int64 Children[int Index] = {read=GetChild, write=SetChild};
};

__interface IJclPtrTreeIterator;
typedef System::DelphiInterface<IJclPtrTreeIterator> _di_IJclPtrTreeIterator;
__interface  INTERFACE_UUID("{ED4C08E6-60FC-4ED3-BD19-E6605B9BD943}") IJclPtrTreeIterator  : public IJclPtrIterator 
{
	
public:
	virtual bool __fastcall AddChild(void * APtr) = 0 ;
	virtual int __fastcall ChildrenCount(void) = 0 ;
	virtual void __fastcall DeleteChild(int Index) = 0 ;
	virtual void __fastcall DeleteChildren(void) = 0 ;
	virtual void __fastcall ExtractChild(int Index) = 0 ;
	virtual void __fastcall ExtractChildren(void) = 0 ;
	virtual void * __fastcall GetChild(int Index) = 0 ;
	virtual bool __fastcall HasChild(int Index) = 0 ;
	virtual bool __fastcall HasParent(void) = 0 ;
	virtual int __fastcall IndexOfChild(void * APtr) = 0 ;
	virtual bool __fastcall InsertChild(int Index, void * APtr) = 0 ;
	virtual void * __fastcall Parent(void) = 0 ;
	virtual void __fastcall SetChild(int Index, void * APtr) = 0 ;
	__property void * Children[int Index] = {read=GetChild, write=SetChild};
};

__interface IJclTreeIterator;
typedef System::DelphiInterface<IJclTreeIterator> _di_IJclTreeIterator;
__interface  INTERFACE_UUID("{8B4863B0-B6B9-426E-B5B8-7AF71D264237}") IJclTreeIterator  : public IJclIterator 
{
	
public:
	virtual bool __fastcall AddChild(System::TObject* AObject) = 0 ;
	virtual int __fastcall ChildrenCount(void) = 0 ;
	virtual void __fastcall DeleteChild(int Index) = 0 ;
	virtual void __fastcall DeleteChildren(void) = 0 ;
	virtual void __fastcall ExtractChild(int Index) = 0 ;
	virtual void __fastcall ExtractChildren(void) = 0 ;
	virtual System::TObject* __fastcall GetChild(int Index) = 0 ;
	virtual bool __fastcall HasChild(int Index) = 0 ;
	virtual bool __fastcall HasParent(void) = 0 ;
	virtual int __fastcall IndexOfChild(System::TObject* AObject) = 0 ;
	virtual bool __fastcall InsertChild(int Index, System::TObject* AObject) = 0 ;
	virtual System::TObject* __fastcall Parent(void) = 0 ;
	virtual void __fastcall SetChild(int Index, System::TObject* AObject) = 0 ;
	__property System::TObject* Children[int Index] = {read=GetChild, write=SetChild};
};

__interface IJclIntfBinaryTreeIterator;
typedef System::DelphiInterface<IJclIntfBinaryTreeIterator> _di_IJclIntfBinaryTreeIterator;
__interface  INTERFACE_UUID("{8BE874B2-0075-4EE0-8F49-665FC894D923}") IJclIntfBinaryTreeIterator  : public IJclIntfTreeIterator 
{
	
public:
	virtual bool __fastcall HasLeft(void) = 0 ;
	virtual bool __fastcall HasRight(void) = 0 ;
	virtual System::_di_IInterface __fastcall Left(void) = 0 ;
	virtual System::_di_IInterface __fastcall Right(void) = 0 ;
};

__interface IJclAnsiStrBinaryTreeIterator;
typedef System::DelphiInterface<IJclAnsiStrBinaryTreeIterator> _di_IJclAnsiStrBinaryTreeIterator;
__interface  INTERFACE_UUID("{34A4A300-042C-43A9-AC23-8FC1B76BFB25}") IJclAnsiStrBinaryTreeIterator  : public IJclAnsiStrTreeIterator 
{
	
public:
	virtual bool __fastcall HasLeft(void) = 0 ;
	virtual bool __fastcall HasRight(void) = 0 ;
	virtual AnsiString __fastcall Left(void) = 0 ;
	virtual AnsiString __fastcall Right(void) = 0 ;
};

__interface IJclWideStrBinaryTreeIterator;
typedef System::DelphiInterface<IJclWideStrBinaryTreeIterator> _di_IJclWideStrBinaryTreeIterator;
__interface  INTERFACE_UUID("{17C08EB9-6880-469E-878A-8F5EBFE905B1}") IJclWideStrBinaryTreeIterator  : public IJclWideStrTreeIterator 
{
	
public:
	virtual bool __fastcall HasLeft(void) = 0 ;
	virtual bool __fastcall HasRight(void) = 0 ;
	virtual WideString __fastcall Left(void) = 0 ;
	virtual WideString __fastcall Right(void) = 0 ;
};

typedef IJclAnsiStrBinaryTreeIterator IJclStrBinaryTreeIterator;
;

__interface IJclSingleBinaryTreeIterator;
typedef System::DelphiInterface<IJclSingleBinaryTreeIterator> _di_IJclSingleBinaryTreeIterator;
__interface  INTERFACE_UUID("{BC6FFB13-FA1C-4077-8273-F25A3119168B}") IJclSingleBinaryTreeIterator  : public IJclSingleTreeIterator 
{
	
public:
	virtual bool __fastcall HasLeft(void) = 0 ;
	virtual bool __fastcall HasRight(void) = 0 ;
	virtual float __fastcall Left(void) = 0 ;
	virtual float __fastcall Right(void) = 0 ;
};

__interface IJclDoubleBinaryTreeIterator;
typedef System::DelphiInterface<IJclDoubleBinaryTreeIterator> _di_IJclDoubleBinaryTreeIterator;
__interface  INTERFACE_UUID("{CE48083C-D60C-4315-BC14-8CE77AC3269E}") IJclDoubleBinaryTreeIterator  : public IJclDoubleTreeIterator 
{
	
public:
	virtual bool __fastcall HasLeft(void) = 0 ;
	virtual bool __fastcall HasRight(void) = 0 ;
	virtual double __fastcall Left(void) = 0 ;
	virtual double __fastcall Right(void) = 0 ;
};

__interface IJclExtendedBinaryTreeIterator;
typedef System::DelphiInterface<IJclExtendedBinaryTreeIterator> _di_IJclExtendedBinaryTreeIterator;
__interface  INTERFACE_UUID("{8A9FAE2A-5EF5-4165-8E8D-51F2102A4580}") IJclExtendedBinaryTreeIterator  : public IJclExtendedTreeIterator 
{
	
public:
	virtual bool __fastcall HasLeft(void) = 0 ;
	virtual bool __fastcall HasRight(void) = 0 ;
	virtual Extended __fastcall Left(void) = 0 ;
	virtual Extended __fastcall Right(void) = 0 ;
};

typedef IJclExtendedBinaryTreeIterator IJclFloatBinaryTreeIterator;
;

__interface IJclIntegerBinaryTreeIterator;
typedef System::DelphiInterface<IJclIntegerBinaryTreeIterator> _di_IJclIntegerBinaryTreeIterator;
__interface  INTERFACE_UUID("{FE2BF57D-D10D-4B0C-903D-BB61700FBA0A}") IJclIntegerBinaryTreeIterator  : public IJclIntegerTreeIterator 
{
	
public:
	virtual bool __fastcall HasLeft(void) = 0 ;
	virtual bool __fastcall HasRight(void) = 0 ;
	virtual int __fastcall Left(void) = 0 ;
	virtual int __fastcall Right(void) = 0 ;
};

__interface IJclCardinalBinaryTreeIterator;
typedef System::DelphiInterface<IJclCardinalBinaryTreeIterator> _di_IJclCardinalBinaryTreeIterator;
__interface  INTERFACE_UUID("{AAA358F5-95A1-480F-8E2A-09028BA6C397}") IJclCardinalBinaryTreeIterator  : public IJclCardinalTreeIterator 
{
	
public:
	virtual bool __fastcall HasLeft(void) = 0 ;
	virtual bool __fastcall HasRight(void) = 0 ;
	virtual unsigned __fastcall Left(void) = 0 ;
	virtual unsigned __fastcall Right(void) = 0 ;
};

__interface IJclInt64BinaryTreeIterator;
typedef System::DelphiInterface<IJclInt64BinaryTreeIterator> _di_IJclInt64BinaryTreeIterator;
__interface  INTERFACE_UUID("{5605E164-5CDD-40B1-9323-DE1CB584E289}") IJclInt64BinaryTreeIterator  : public IJclInt64TreeIterator 
{
	
public:
	virtual bool __fastcall HasLeft(void) = 0 ;
	virtual bool __fastcall HasRight(void) = 0 ;
	virtual __int64 __fastcall Left(void) = 0 ;
	virtual __int64 __fastcall Right(void) = 0 ;
};

__interface IJclPtrBinaryTreeIterator;
typedef System::DelphiInterface<IJclPtrBinaryTreeIterator> _di_IJclPtrBinaryTreeIterator;
__interface  INTERFACE_UUID("{75D3DF0D-C491-43F7-B078-E658197E8051}") IJclPtrBinaryTreeIterator  : public IJclPtrTreeIterator 
{
	
public:
	virtual bool __fastcall HasLeft(void) = 0 ;
	virtual bool __fastcall HasRight(void) = 0 ;
	virtual void * __fastcall Left(void) = 0 ;
	virtual void * __fastcall Right(void) = 0 ;
};

__interface IJclBinaryTreeIterator;
typedef System::DelphiInterface<IJclBinaryTreeIterator> _di_IJclBinaryTreeIterator;
__interface  INTERFACE_UUID("{821DE28D-631C-4F23-A0B2-CC0F35B4C64D}") IJclBinaryTreeIterator  : public IJclTreeIterator 
{
	
public:
	virtual bool __fastcall HasLeft(void) = 0 ;
	virtual bool __fastcall HasRight(void) = 0 ;
	virtual System::TObject* __fastcall Left(void) = 0 ;
	virtual System::TObject* __fastcall Right(void) = 0 ;
};

__interface IJclIntfCollection;
typedef System::DelphiInterface<IJclIntfCollection> _di_IJclIntfCollection;
__interface  INTERFACE_UUID("{8E178463-4575-487A-B4D5-DC2AED3C7ACA}") IJclIntfCollection  : public IJclContainer 
{
	
public:
	virtual bool __fastcall Add(const System::_di_IInterface AInterface) = 0 ;
	virtual bool __fastcall AddAll(const _di_IJclIntfCollection ACollection) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const System::_di_IInterface AInterface) = 0 ;
	virtual bool __fastcall ContainsAll(const _di_IJclIntfCollection ACollection) = 0 ;
	virtual bool __fastcall CollectionEquals(const _di_IJclIntfCollection ACollection) = 0 ;
	virtual bool __fastcall Extract(const System::_di_IInterface AInterface) = 0 ;
	virtual bool __fastcall ExtractAll(const _di_IJclIntfCollection ACollection) = 0 ;
	virtual _di_IJclIntfIterator __fastcall First(void) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual _di_IJclIntfIterator __fastcall Last(void) = 0 ;
	virtual bool __fastcall Remove(const System::_di_IInterface AInterface) = 0 ;
	virtual bool __fastcall RemoveAll(const _di_IJclIntfCollection ACollection) = 0 ;
	virtual bool __fastcall RetainAll(const _di_IJclIntfCollection ACollection) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclIntfIterator __fastcall GetEnumerator(void) = 0 ;
};

__interface IJclAnsiStrCollection;
typedef System::DelphiInterface<IJclAnsiStrCollection> _di_IJclAnsiStrCollection;
__interface  INTERFACE_UUID("{3E3CFC19-E8AF-4DD7-91FA-2DF2895FC7B9}") IJclAnsiStrCollection  : public IJclAnsiStrFlatContainer 
{
	
public:
	virtual bool __fastcall Add(const AnsiString AString) = 0 ;
	virtual bool __fastcall AddAll(const _di_IJclAnsiStrCollection ACollection) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const AnsiString AString) = 0 ;
	virtual bool __fastcall ContainsAll(const _di_IJclAnsiStrCollection ACollection) = 0 ;
	virtual bool __fastcall CollectionEquals(const _di_IJclAnsiStrCollection ACollection) = 0 ;
	virtual bool __fastcall Extract(const AnsiString AString) = 0 ;
	virtual bool __fastcall ExtractAll(const _di_IJclAnsiStrCollection ACollection) = 0 ;
	virtual _di_IJclAnsiStrIterator __fastcall First(void) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual _di_IJclAnsiStrIterator __fastcall Last(void) = 0 ;
	virtual bool __fastcall Remove(const AnsiString AString) = 0 ;
	virtual bool __fastcall RemoveAll(const _di_IJclAnsiStrCollection ACollection) = 0 ;
	virtual bool __fastcall RetainAll(const _di_IJclAnsiStrCollection ACollection) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclAnsiStrIterator __fastcall GetEnumerator(void) = 0 ;
};

__interface IJclWideStrCollection;
typedef System::DelphiInterface<IJclWideStrCollection> _di_IJclWideStrCollection;
__interface  INTERFACE_UUID("{CDCC0F94-4DD0-4F25-B441-6AE55D5C7466}") IJclWideStrCollection  : public IJclWideStrFlatContainer 
{
	
public:
	virtual bool __fastcall Add(const WideString AString) = 0 ;
	virtual bool __fastcall AddAll(const _di_IJclWideStrCollection ACollection) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const WideString AString) = 0 ;
	virtual bool __fastcall ContainsAll(const _di_IJclWideStrCollection ACollection) = 0 ;
	virtual bool __fastcall CollectionEquals(const _di_IJclWideStrCollection ACollection) = 0 ;
	virtual bool __fastcall Extract(const WideString AString) = 0 ;
	virtual bool __fastcall ExtractAll(const _di_IJclWideStrCollection ACollection) = 0 ;
	virtual _di_IJclWideStrIterator __fastcall First(void) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual _di_IJclWideStrIterator __fastcall Last(void) = 0 ;
	virtual bool __fastcall Remove(const WideString AString) = 0 ;
	virtual bool __fastcall RemoveAll(const _di_IJclWideStrCollection ACollection) = 0 ;
	virtual bool __fastcall RetainAll(const _di_IJclWideStrCollection ACollection) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclWideStrIterator __fastcall GetEnumerator(void) = 0 ;
};

typedef IJclAnsiStrCollection IJclStrCollection;
;

__interface IJclSingleCollection;
typedef System::DelphiInterface<IJclSingleCollection> _di_IJclSingleCollection;
__interface  INTERFACE_UUID("{1D34D474-6588-441E-B2B3-8C021A37ED89}") IJclSingleCollection  : public IJclSingleContainer 
{
	
public:
	virtual bool __fastcall Add(const float AValue) = 0 ;
	virtual bool __fastcall AddAll(const _di_IJclSingleCollection ACollection) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const float AValue) = 0 ;
	virtual bool __fastcall ContainsAll(const _di_IJclSingleCollection ACollection) = 0 ;
	virtual bool __fastcall CollectionEquals(const _di_IJclSingleCollection ACollection) = 0 ;
	virtual bool __fastcall Extract(const float AValue) = 0 ;
	virtual bool __fastcall ExtractAll(const _di_IJclSingleCollection ACollection) = 0 ;
	virtual _di_IJclSingleIterator __fastcall First(void) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual _di_IJclSingleIterator __fastcall Last(void) = 0 ;
	virtual bool __fastcall Remove(const float AValue) = 0 ;
	virtual bool __fastcall RemoveAll(const _di_IJclSingleCollection ACollection) = 0 ;
	virtual bool __fastcall RetainAll(const _di_IJclSingleCollection ACollection) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclSingleIterator __fastcall GetEnumerator(void) = 0 ;
};

__interface IJclDoubleCollection;
typedef System::DelphiInterface<IJclDoubleCollection> _di_IJclDoubleCollection;
__interface  INTERFACE_UUID("{E54C7717-C33A-4F1B-860C-4F60F303EAD3}") IJclDoubleCollection  : public IJclDoubleContainer 
{
	
public:
	virtual bool __fastcall Add(const double AValue) = 0 ;
	virtual bool __fastcall AddAll(const _di_IJclDoubleCollection ACollection) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const double AValue) = 0 ;
	virtual bool __fastcall ContainsAll(const _di_IJclDoubleCollection ACollection) = 0 ;
	virtual bool __fastcall CollectionEquals(const _di_IJclDoubleCollection ACollection) = 0 ;
	virtual bool __fastcall Extract(const double AValue) = 0 ;
	virtual bool __fastcall ExtractAll(const _di_IJclDoubleCollection ACollection) = 0 ;
	virtual _di_IJclDoubleIterator __fastcall First(void) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual _di_IJclDoubleIterator __fastcall Last(void) = 0 ;
	virtual bool __fastcall Remove(const double AValue) = 0 ;
	virtual bool __fastcall RemoveAll(const _di_IJclDoubleCollection ACollection) = 0 ;
	virtual bool __fastcall RetainAll(const _di_IJclDoubleCollection ACollection) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclDoubleIterator __fastcall GetEnumerator(void) = 0 ;
};

__interface IJclExtendedCollection;
typedef System::DelphiInterface<IJclExtendedCollection> _di_IJclExtendedCollection;
__interface  INTERFACE_UUID("{2A1341CB-B997-4E3B-B1CA-6D60AE853C55}") IJclExtendedCollection  : public IJclExtendedContainer 
{
	
public:
	virtual bool __fastcall Add(const Extended AValue) = 0 ;
	virtual bool __fastcall AddAll(const _di_IJclExtendedCollection ACollection) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const Extended AValue) = 0 ;
	virtual bool __fastcall ContainsAll(const _di_IJclExtendedCollection ACollection) = 0 ;
	virtual bool __fastcall CollectionEquals(const _di_IJclExtendedCollection ACollection) = 0 ;
	virtual bool __fastcall Extract(const Extended AValue) = 0 ;
	virtual bool __fastcall ExtractAll(const _di_IJclExtendedCollection ACollection) = 0 ;
	virtual _di_IJclExtendedIterator __fastcall First(void) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual _di_IJclExtendedIterator __fastcall Last(void) = 0 ;
	virtual bool __fastcall Remove(const Extended AValue) = 0 ;
	virtual bool __fastcall RemoveAll(const _di_IJclExtendedCollection ACollection) = 0 ;
	virtual bool __fastcall RetainAll(const _di_IJclExtendedCollection ACollection) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclExtendedIterator __fastcall GetEnumerator(void) = 0 ;
};

typedef IJclExtendedCollection IJclFloatCollection;
;

__interface IJclIntegerCollection;
typedef System::DelphiInterface<IJclIntegerCollection> _di_IJclIntegerCollection;
__interface  INTERFACE_UUID("{AF69890D-22D1-4D89-8FFD-5FAD7E0638BA}") IJclIntegerCollection  : public IJclContainer 
{
	
public:
	virtual bool __fastcall Add(int AValue) = 0 ;
	virtual bool __fastcall AddAll(const _di_IJclIntegerCollection ACollection) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(int AValue) = 0 ;
	virtual bool __fastcall ContainsAll(const _di_IJclIntegerCollection ACollection) = 0 ;
	virtual bool __fastcall CollectionEquals(const _di_IJclIntegerCollection ACollection) = 0 ;
	virtual bool __fastcall Extract(int AValue) = 0 ;
	virtual bool __fastcall ExtractAll(const _di_IJclIntegerCollection ACollection) = 0 ;
	virtual _di_IJclIntegerIterator __fastcall First(void) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual _di_IJclIntegerIterator __fastcall Last(void) = 0 ;
	virtual bool __fastcall Remove(int AValue) = 0 ;
	virtual bool __fastcall RemoveAll(const _di_IJclIntegerCollection ACollection) = 0 ;
	virtual bool __fastcall RetainAll(const _di_IJclIntegerCollection ACollection) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclIntegerIterator __fastcall GetEnumerator(void) = 0 ;
};

__interface IJclCardinalCollection;
typedef System::DelphiInterface<IJclCardinalCollection> _di_IJclCardinalCollection;
__interface  INTERFACE_UUID("{CFBD0344-58C8-4FA2-B4D7-D21D77DFBF80}") IJclCardinalCollection  : public IJclContainer 
{
	
public:
	virtual bool __fastcall Add(unsigned AValue) = 0 ;
	virtual bool __fastcall AddAll(const _di_IJclCardinalCollection ACollection) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(unsigned AValue) = 0 ;
	virtual bool __fastcall ContainsAll(const _di_IJclCardinalCollection ACollection) = 0 ;
	virtual bool __fastcall CollectionEquals(const _di_IJclCardinalCollection ACollection) = 0 ;
	virtual bool __fastcall Extract(unsigned AValue) = 0 ;
	virtual bool __fastcall ExtractAll(const _di_IJclCardinalCollection ACollection) = 0 ;
	virtual _di_IJclCardinalIterator __fastcall First(void) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual _di_IJclCardinalIterator __fastcall Last(void) = 0 ;
	virtual bool __fastcall Remove(unsigned AValue) = 0 ;
	virtual bool __fastcall RemoveAll(const _di_IJclCardinalCollection ACollection) = 0 ;
	virtual bool __fastcall RetainAll(const _di_IJclCardinalCollection ACollection) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclCardinalIterator __fastcall GetEnumerator(void) = 0 ;
};

__interface IJclInt64Collection;
typedef System::DelphiInterface<IJclInt64Collection> _di_IJclInt64Collection;
__interface  INTERFACE_UUID("{93A45BDE-3C4C-48D6-9874-5322914DFDDA}") IJclInt64Collection  : public IJclContainer 
{
	
public:
	virtual bool __fastcall Add(const __int64 AValue) = 0 ;
	virtual bool __fastcall AddAll(const _di_IJclInt64Collection ACollection) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const __int64 AValue) = 0 ;
	virtual bool __fastcall ContainsAll(const _di_IJclInt64Collection ACollection) = 0 ;
	virtual bool __fastcall CollectionEquals(const _di_IJclInt64Collection ACollection) = 0 ;
	virtual bool __fastcall Extract(const __int64 AValue) = 0 ;
	virtual bool __fastcall ExtractAll(const _di_IJclInt64Collection ACollection) = 0 ;
	virtual _di_IJclInt64Iterator __fastcall First(void) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual _di_IJclInt64Iterator __fastcall Last(void) = 0 ;
	virtual bool __fastcall Remove(const __int64 AValue) = 0 ;
	virtual bool __fastcall RemoveAll(const _di_IJclInt64Collection ACollection) = 0 ;
	virtual bool __fastcall RetainAll(const _di_IJclInt64Collection ACollection) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclInt64Iterator __fastcall GetEnumerator(void) = 0 ;
};

__interface IJclPtrCollection;
typedef System::DelphiInterface<IJclPtrCollection> _di_IJclPtrCollection;
__interface  INTERFACE_UUID("{02E909A7-5B1D-40D4-82EA-A0CD97D5C811}") IJclPtrCollection  : public IJclContainer 
{
	
public:
	virtual bool __fastcall Add(void * APtr) = 0 ;
	virtual bool __fastcall AddAll(const _di_IJclPtrCollection ACollection) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(void * APtr) = 0 ;
	virtual bool __fastcall ContainsAll(const _di_IJclPtrCollection ACollection) = 0 ;
	virtual bool __fastcall CollectionEquals(const _di_IJclPtrCollection ACollection) = 0 ;
	virtual bool __fastcall Extract(void * APtr) = 0 ;
	virtual bool __fastcall ExtractAll(const _di_IJclPtrCollection ACollection) = 0 ;
	virtual _di_IJclPtrIterator __fastcall First(void) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual _di_IJclPtrIterator __fastcall Last(void) = 0 ;
	virtual bool __fastcall Remove(void * APtr) = 0 ;
	virtual bool __fastcall RemoveAll(const _di_IJclPtrCollection ACollection) = 0 ;
	virtual bool __fastcall RetainAll(const _di_IJclPtrCollection ACollection) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclPtrIterator __fastcall GetEnumerator(void) = 0 ;
};

__interface IJclCollection;
typedef System::DelphiInterface<IJclCollection> _di_IJclCollection;
__interface  INTERFACE_UUID("{58947EF1-CD21-4DD1-AE3D-225C3AAD7EE5}") IJclCollection  : public IJclContainer 
{
	
public:
	virtual bool __fastcall Add(System::TObject* AObject) = 0 ;
	virtual bool __fastcall AddAll(const _di_IJclCollection ACollection) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(System::TObject* AObject) = 0 ;
	virtual bool __fastcall ContainsAll(const _di_IJclCollection ACollection) = 0 ;
	virtual bool __fastcall CollectionEquals(const _di_IJclCollection ACollection) = 0 ;
	virtual bool __fastcall Extract(System::TObject* AObject) = 0 ;
	virtual bool __fastcall ExtractAll(const _di_IJclCollection ACollection) = 0 ;
	virtual _di_IJclIterator __fastcall First(void) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual _di_IJclIterator __fastcall Last(void) = 0 ;
	virtual bool __fastcall Remove(System::TObject* AObject) = 0 ;
	virtual bool __fastcall RemoveAll(const _di_IJclCollection ACollection) = 0 ;
	virtual bool __fastcall RetainAll(const _di_IJclCollection ACollection) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclIterator __fastcall GetEnumerator(void) = 0 ;
};

__interface IJclIntfList;
typedef System::DelphiInterface<IJclIntfList> _di_IJclIntfList;
__interface  INTERFACE_UUID("{E14EDA4B-1DAA-4013-9E6C-CDCB365C7CF9}") IJclIntfList  : public IJclIntfCollection 
{
	
public:
	System::_di_IInterface operator[](int Key) { return Objects[Key]; }
	
public:
	virtual System::_di_IInterface __fastcall Delete(int Index) = 0 ;
	virtual System::_di_IInterface __fastcall ExtractIndex(int Index) = 0 ;
	virtual System::_di_IInterface __fastcall GetObject(int Index) = 0 ;
	virtual int __fastcall IndexOf(const System::_di_IInterface AInterface) = 0 ;
	virtual bool __fastcall Insert(int Index, const System::_di_IInterface AInterface) = 0 ;
	virtual bool __fastcall InsertAll(int Index, const _di_IJclIntfCollection ACollection) = 0 ;
	virtual int __fastcall LastIndexOf(const System::_di_IInterface AInterface) = 0 ;
	virtual void __fastcall SetObject(int Index, const System::_di_IInterface AInterface) = 0 ;
	virtual _di_IJclIntfList __fastcall SubList(int First, int Count) = 0 ;
	__property System::_di_IInterface Objects[int Key] = {read=GetObject, write=SetObject/*, default*/};
};

__interface IJclAnsiStrList;
typedef System::DelphiInterface<IJclAnsiStrList> _di_IJclAnsiStrList;
__interface  INTERFACE_UUID("{07DD7644-EAC6-4059-99FC-BEB7FBB73186}") IJclAnsiStrList  : public IJclAnsiStrCollection 
{
	
public:
	AnsiString operator[](int Key) { return Strings[Key]; }
	
public:
	virtual AnsiString __fastcall Delete(int Index) = 0 ;
	virtual AnsiString __fastcall ExtractIndex(int Index) = 0 ;
	virtual AnsiString __fastcall GetString(int Index) = 0 ;
	virtual int __fastcall IndexOf(const AnsiString AString) = 0 ;
	virtual bool __fastcall Insert(int Index, const AnsiString AString) = 0 ;
	virtual bool __fastcall InsertAll(int Index, const _di_IJclAnsiStrCollection ACollection) = 0 ;
	virtual int __fastcall LastIndexOf(const AnsiString AString) = 0 ;
	virtual void __fastcall SetString(int Index, const AnsiString AString) = 0 ;
	virtual _di_IJclAnsiStrList __fastcall SubList(int First, int Count) = 0 ;
	__property AnsiString Strings[int Key] = {read=GetString, write=SetString/*, default*/};
};

__interface IJclWideStrList;
typedef System::DelphiInterface<IJclWideStrList> _di_IJclWideStrList;
__interface  INTERFACE_UUID("{C9955874-6AC0-4CE0-8CC0-606A3F1702C6}") IJclWideStrList  : public IJclWideStrCollection 
{
	
public:
	WideString operator[](int Key) { return Strings[Key]; }
	
public:
	virtual WideString __fastcall Delete(int Index) = 0 ;
	virtual WideString __fastcall ExtractIndex(int Index) = 0 ;
	virtual WideString __fastcall GetString(int Index) = 0 ;
	virtual int __fastcall IndexOf(const WideString AString) = 0 ;
	virtual bool __fastcall Insert(int Index, const WideString AString) = 0 ;
	virtual bool __fastcall InsertAll(int Index, const _di_IJclWideStrCollection ACollection) = 0 ;
	virtual int __fastcall LastIndexOf(const WideString AString) = 0 ;
	virtual void __fastcall SetString(int Index, const WideString AString) = 0 ;
	virtual _di_IJclWideStrList __fastcall SubList(int First, int Count) = 0 ;
	__property WideString Strings[int Key] = {read=GetString, write=SetString/*, default*/};
};

typedef IJclAnsiStrList IJclStrList;
;

__interface IJclSingleList;
typedef System::DelphiInterface<IJclSingleList> _di_IJclSingleList;
__interface  INTERFACE_UUID("{D081324C-70A4-4AAC-BA42-7557F0262826}") IJclSingleList  : public IJclSingleCollection 
{
	
public:
	float operator[](int Key) { return Values[Key]; }
	
public:
	virtual float __fastcall Delete(int Index) = 0 ;
	virtual float __fastcall ExtractIndex(int Index) = 0 ;
	virtual float __fastcall GetValue(int Index) = 0 ;
	virtual int __fastcall IndexOf(const float AValue) = 0 ;
	virtual bool __fastcall Insert(int Index, const float AValue) = 0 ;
	virtual bool __fastcall InsertAll(int Index, const _di_IJclSingleCollection ACollection) = 0 ;
	virtual int __fastcall LastIndexOf(const float AValue) = 0 ;
	virtual void __fastcall SetValue(int Index, const float AValue) = 0 ;
	virtual _di_IJclSingleList __fastcall SubList(int First, int Count) = 0 ;
	__property float Values[int Key] = {read=GetValue, write=SetValue/*, default*/};
};

__interface IJclDoubleList;
typedef System::DelphiInterface<IJclDoubleList> _di_IJclDoubleList;
__interface  INTERFACE_UUID("{ECA58515-3903-4312-9486-3214E03F35AB}") IJclDoubleList  : public IJclDoubleCollection 
{
	
public:
	double operator[](int Key) { return Values[Key]; }
	
public:
	virtual double __fastcall Delete(int Index) = 0 ;
	virtual double __fastcall ExtractIndex(int Index) = 0 ;
	virtual double __fastcall GetValue(int Index) = 0 ;
	virtual int __fastcall IndexOf(const double AValue) = 0 ;
	virtual bool __fastcall Insert(int Index, const double AValue) = 0 ;
	virtual bool __fastcall InsertAll(int Index, const _di_IJclDoubleCollection ACollection) = 0 ;
	virtual int __fastcall LastIndexOf(const double AValue) = 0 ;
	virtual void __fastcall SetValue(int Index, const double AValue) = 0 ;
	virtual _di_IJclDoubleList __fastcall SubList(int First, int Count) = 0 ;
	__property double Values[int Key] = {read=GetValue, write=SetValue/*, default*/};
};

__interface IJclExtendedList;
typedef System::DelphiInterface<IJclExtendedList> _di_IJclExtendedList;
__interface  INTERFACE_UUID("{7463F954-F8DF-4B02-A284-FCB98746248E}") IJclExtendedList  : public IJclExtendedCollection 
{
	
public:
	Extended operator[](int Key) { return Values[Key]; }
	
public:
	virtual Extended __fastcall Delete(int Index) = 0 ;
	virtual Extended __fastcall ExtractIndex(int Index) = 0 ;
	virtual Extended __fastcall GetValue(int Index) = 0 ;
	virtual int __fastcall IndexOf(const Extended AValue) = 0 ;
	virtual bool __fastcall Insert(int Index, const Extended AValue) = 0 ;
	virtual bool __fastcall InsertAll(int Index, const _di_IJclExtendedCollection ACollection) = 0 ;
	virtual int __fastcall LastIndexOf(const Extended AValue) = 0 ;
	virtual void __fastcall SetValue(int Index, const Extended AValue) = 0 ;
	virtual _di_IJclExtendedList __fastcall SubList(int First, int Count) = 0 ;
	__property Extended Values[int Key] = {read=GetValue, write=SetValue/*, default*/};
};

typedef IJclExtendedList IJclFloatList;
;

__interface IJclIntegerList;
typedef System::DelphiInterface<IJclIntegerList> _di_IJclIntegerList;
__interface  INTERFACE_UUID("{339BE91B-557D-4CE0-A854-1CBD4FE31725}") IJclIntegerList  : public IJclIntegerCollection 
{
	
public:
	int operator[](int Key) { return Values[Key]; }
	
public:
	virtual int __fastcall Delete(int Index) = 0 ;
	virtual int __fastcall ExtractIndex(int Index) = 0 ;
	virtual int __fastcall GetValue(int Index) = 0 ;
	virtual int __fastcall IndexOf(int AValue) = 0 ;
	virtual bool __fastcall Insert(int Index, int AValue) = 0 ;
	virtual bool __fastcall InsertAll(int Index, const _di_IJclIntegerCollection ACollection) = 0 ;
	virtual int __fastcall LastIndexOf(int AValue) = 0 ;
	virtual void __fastcall SetValue(int Index, int AValue) = 0 ;
	virtual _di_IJclIntegerList __fastcall SubList(int First, int Count) = 0 ;
	__property int Values[int Key] = {read=GetValue, write=SetValue/*, default*/};
};

__interface IJclCardinalList;
typedef System::DelphiInterface<IJclCardinalList> _di_IJclCardinalList;
__interface  INTERFACE_UUID("{02B09EA8-DE6F-4A18-AA57-C3533E6AC4E3}") IJclCardinalList  : public IJclCardinalCollection 
{
	
public:
	unsigned operator[](int Key) { return Values[Key]; }
	
public:
	virtual unsigned __fastcall Delete(int Index) = 0 ;
	virtual unsigned __fastcall ExtractIndex(int Index) = 0 ;
	virtual unsigned __fastcall GetValue(int Index) = 0 ;
	virtual int __fastcall IndexOf(unsigned AValue) = 0 ;
	virtual bool __fastcall Insert(int Index, unsigned AValue) = 0 ;
	virtual bool __fastcall InsertAll(int Index, const _di_IJclCardinalCollection ACollection) = 0 ;
	virtual int __fastcall LastIndexOf(unsigned AValue) = 0 ;
	virtual void __fastcall SetValue(int Index, unsigned AValue) = 0 ;
	virtual _di_IJclCardinalList __fastcall SubList(int First, int Count) = 0 ;
	__property unsigned Values[int Key] = {read=GetValue, write=SetValue/*, default*/};
};

__interface IJclInt64List;
typedef System::DelphiInterface<IJclInt64List> _di_IJclInt64List;
__interface  INTERFACE_UUID("{E8D49200-91D3-4BD0-A59B-B93EC7E2074B}") IJclInt64List  : public IJclInt64Collection 
{
	
public:
	__int64 operator[](int Key) { return Values[Key]; }
	
public:
	virtual __int64 __fastcall Delete(int Index) = 0 ;
	virtual __int64 __fastcall ExtractIndex(int Index) = 0 ;
	virtual __int64 __fastcall GetValue(int Index) = 0 ;
	virtual int __fastcall IndexOf(const __int64 AValue) = 0 ;
	virtual bool __fastcall Insert(int Index, const __int64 AValue) = 0 ;
	virtual bool __fastcall InsertAll(int Index, const _di_IJclInt64Collection ACollection) = 0 ;
	virtual int __fastcall LastIndexOf(const __int64 AValue) = 0 ;
	virtual void __fastcall SetValue(int Index, const __int64 AValue) = 0 ;
	virtual _di_IJclInt64List __fastcall SubList(int First, int Count) = 0 ;
	__property __int64 Values[int Key] = {read=GetValue, write=SetValue/*, default*/};
};

__interface IJclPtrList;
typedef System::DelphiInterface<IJclPtrList> _di_IJclPtrList;
__interface  INTERFACE_UUID("{2CF5CF1F-C012-480C-A4CE-38BDAFB15D05}") IJclPtrList  : public IJclPtrCollection 
{
	
public:
	void * operator[](int Key) { return Pointers[Key]; }
	
public:
	virtual void * __fastcall Delete(int Index) = 0 ;
	virtual void * __fastcall ExtractIndex(int Index) = 0 ;
	virtual void * __fastcall GetPointer(int Index) = 0 ;
	virtual int __fastcall IndexOf(void * APtr) = 0 ;
	virtual bool __fastcall Insert(int Index, void * APtr) = 0 ;
	virtual bool __fastcall InsertAll(int Index, const _di_IJclPtrCollection ACollection) = 0 ;
	virtual int __fastcall LastIndexOf(void * APtr) = 0 ;
	virtual void __fastcall SetPointer(int Index, void * APtr) = 0 ;
	virtual _di_IJclPtrList __fastcall SubList(int First, int Count) = 0 ;
	__property void * Pointers[int Key] = {read=GetPointer, write=SetPointer/*, default*/};
};

__interface IJclList;
typedef System::DelphiInterface<IJclList> _di_IJclList;
__interface  INTERFACE_UUID("{8ABC70AC-5C06-43EA-AFE0-D066379BCC28}") IJclList  : public IJclCollection 
{
	
public:
	System::TObject* operator[](int Key) { return Objects[Key]; }
	
public:
	virtual System::TObject* __fastcall Delete(int Index) = 0 ;
	virtual System::TObject* __fastcall ExtractIndex(int Index) = 0 ;
	virtual System::TObject* __fastcall GetObject(int Index) = 0 ;
	virtual int __fastcall IndexOf(System::TObject* AObject) = 0 ;
	virtual bool __fastcall Insert(int Index, System::TObject* AObject) = 0 ;
	virtual bool __fastcall InsertAll(int Index, const _di_IJclCollection ACollection) = 0 ;
	virtual int __fastcall LastIndexOf(System::TObject* AObject) = 0 ;
	virtual void __fastcall SetObject(int Index, System::TObject* AObject) = 0 ;
	virtual _di_IJclList __fastcall SubList(int First, int Count) = 0 ;
	__property System::TObject* Objects[int Key] = {read=GetObject, write=SetObject/*, default*/};
};

typedef void __fastcall (*TIntfSortProc)(const _di_IJclIntfList AList, int L, int R, TIntfCompare AComparator);

typedef void __fastcall (*TAnsiStrSortProc)(const _di_IJclAnsiStrList AList, int L, int R, TAnsiStrCompare AComparator);

typedef void __fastcall (*TWideStrSortProc)(const _di_IJclWideStrList AList, int L, int R, TWideStrCompare AComparator);

typedef void __fastcall (*TStrSortProc)(const _di_IJclAnsiStrList AList, int L, int R, TAnsiStrCompare AComparator);

typedef void __fastcall (*TSingleSortProc)(const _di_IJclSingleList AList, int L, int R, TSingleCompare AComparator);

typedef void __fastcall (*TDoubleSortProc)(const _di_IJclDoubleList AList, int L, int R, TDoubleCompare AComparator);

typedef void __fastcall (*TExtendedSortProc)(const _di_IJclExtendedList AList, int L, int R, TExtendedCompare AComparator);

typedef void __fastcall (*TIntegerSortProc)(const _di_IJclIntegerList AList, int L, int R, TIntegerCompare AComparator);

typedef void __fastcall (*TCardinalSortProc)(const _di_IJclCardinalList AList, int L, int R, TCardinalCompare AComparator);

typedef void __fastcall (*TInt64SortProc)(const _di_IJclInt64List AList, int L, int R, TInt64Compare AComparator);

typedef void __fastcall (*TPtrSortProc)(const _di_IJclPtrList AList, int L, int R, TPtrCompare AComparator);

typedef void __fastcall (*TSortProc)(const _di_IJclList AList, int L, int R, TCompare AComparator);

__interface IJclIntfArray;
typedef System::DelphiInterface<IJclIntfArray> _di_IJclIntfArray;
__interface  INTERFACE_UUID("{B055B427-7817-43FC-97D4-AD1845643D63}") IJclIntfArray  : public IJclIntfList 
{
	
public:
	System::_di_IInterface operator[](int Index) { return Objects[Index]; }
	
public:
	HIDESBASE virtual System::_di_IInterface __fastcall GetObject(int Index) = 0 ;
	HIDESBASE virtual void __fastcall SetObject(int Index, const System::_di_IInterface AInterface) = 0 ;
	__property System::_di_IInterface Objects[int Index] = {read=GetObject, write=SetObject/*, default*/};
};

__interface IJclAnsiStrArray;
typedef System::DelphiInterface<IJclAnsiStrArray> _di_IJclAnsiStrArray;
__interface  INTERFACE_UUID("{4953EA83-9288-4537-9D10-544D1C992B62}") IJclAnsiStrArray  : public IJclAnsiStrList 
{
	
public:
	AnsiString operator[](int Index) { return Strings[Index]; }
	
public:
	HIDESBASE virtual AnsiString __fastcall GetString(int Index) = 0 ;
	HIDESBASE virtual void __fastcall SetString(int Index, const AnsiString AString) = 0 ;
	__property AnsiString Strings[int Index] = {read=GetString, write=SetString/*, default*/};
};

__interface IJclWideStrArray;
typedef System::DelphiInterface<IJclWideStrArray> _di_IJclWideStrArray;
__interface  INTERFACE_UUID("{3CE09F9A-5CB4-4867-80D5-C2313D278D69}") IJclWideStrArray  : public IJclWideStrList 
{
	
public:
	WideString operator[](int Index) { return Strings[Index]; }
	
public:
	HIDESBASE virtual WideString __fastcall GetString(int Index) = 0 ;
	HIDESBASE virtual void __fastcall SetString(int Index, const WideString AString) = 0 ;
	__property WideString Strings[int Index] = {read=GetString, write=SetString/*, default*/};
};

typedef IJclAnsiStrArray IJclStrArray;
;

__interface IJclSingleArray;
typedef System::DelphiInterface<IJclSingleArray> _di_IJclSingleArray;
__interface  INTERFACE_UUID("{B96E2A4D-D750-4B65-B975-C619A05A29F6}") IJclSingleArray  : public IJclSingleList 
{
	
public:
	float operator[](int Index) { return Values[Index]; }
	
public:
	HIDESBASE virtual float __fastcall GetValue(int Index) = 0 ;
	HIDESBASE virtual void __fastcall SetValue(int Index, const float AValue) = 0 ;
	__property float Values[int Index] = {read=GetValue, write=SetValue/*, default*/};
};

__interface IJclDoubleArray;
typedef System::DelphiInterface<IJclDoubleArray> _di_IJclDoubleArray;
__interface  INTERFACE_UUID("{67E66324-9757-4E85-8ECD-53396910FB39}") IJclDoubleArray  : public IJclDoubleList 
{
	
public:
	double operator[](int Index) { return Values[Index]; }
	
public:
	HIDESBASE virtual double __fastcall GetValue(int Index) = 0 ;
	HIDESBASE virtual void __fastcall SetValue(int Index, const double AValue) = 0 ;
	__property double Values[int Index] = {read=GetValue, write=SetValue/*, default*/};
};

__interface IJclExtendedArray;
typedef System::DelphiInterface<IJclExtendedArray> _di_IJclExtendedArray;
__interface  INTERFACE_UUID("{D43E8D18-26B3-41A2-8D52-ED7EA2FE1AB7}") IJclExtendedArray  : public IJclExtendedList 
{
	
public:
	Extended operator[](int Index) { return Values[Index]; }
	
public:
	HIDESBASE virtual Extended __fastcall GetValue(int Index) = 0 ;
	HIDESBASE virtual void __fastcall SetValue(int Index, const Extended AValue) = 0 ;
	__property Extended Values[int Index] = {read=GetValue, write=SetValue/*, default*/};
};

typedef IJclExtendedArray IJclFloatArray;
;

__interface IJclIntegerArray;
typedef System::DelphiInterface<IJclIntegerArray> _di_IJclIntegerArray;
__interface  INTERFACE_UUID("{2B7C8B33-C0BD-4EC3-9764-63866E174781}") IJclIntegerArray  : public IJclIntegerList 
{
	
public:
	int operator[](int Index) { return Values[Index]; }
	
public:
	HIDESBASE virtual int __fastcall GetValue(int Index) = 0 ;
	HIDESBASE virtual void __fastcall SetValue(int Index, int AValue) = 0 ;
	__property int Values[int Index] = {read=GetValue, write=SetValue/*, default*/};
};

__interface IJclCardinalArray;
typedef System::DelphiInterface<IJclCardinalArray> _di_IJclCardinalArray;
__interface  INTERFACE_UUID("{C451F2F8-65C6-4C29-99A0-CC9C15356418}") IJclCardinalArray  : public IJclCardinalList 
{
	
public:
	unsigned operator[](int Index) { return Values[Index]; }
	
public:
	HIDESBASE virtual unsigned __fastcall GetValue(int Index) = 0 ;
	HIDESBASE virtual void __fastcall SetValue(int Index, unsigned AValue) = 0 ;
	__property unsigned Values[int Index] = {read=GetValue, write=SetValue/*, default*/};
};

__interface IJclInt64Array;
typedef System::DelphiInterface<IJclInt64Array> _di_IJclInt64Array;
__interface  INTERFACE_UUID("{D947C43D-2D04-442A-A707-39EDE7D96FC9}") IJclInt64Array  : public IJclInt64List 
{
	
public:
	__int64 operator[](int Index) { return Values[Index]; }
	
public:
	HIDESBASE virtual __int64 __fastcall GetValue(int Index) = 0 ;
	HIDESBASE virtual void __fastcall SetValue(int Index, const __int64 AValue) = 0 ;
	__property __int64 Values[int Index] = {read=GetValue, write=SetValue/*, default*/};
};

__interface IJclPtrArray;
typedef System::DelphiInterface<IJclPtrArray> _di_IJclPtrArray;
__interface  INTERFACE_UUID("{D43E8D18-26B3-41A2-8D52-ED7EA2FE1AB7}") IJclPtrArray  : public IJclPtrList 
{
	
public:
	void * operator[](int Index) { return Pointers[Index]; }
	
public:
	HIDESBASE virtual void * __fastcall GetPointer(int Index) = 0 ;
	HIDESBASE virtual void __fastcall SetPointer(int Index, void * APtr) = 0 ;
	__property void * Pointers[int Index] = {read=GetPointer, write=SetPointer/*, default*/};
};

__interface IJclArray;
typedef System::DelphiInterface<IJclArray> _di_IJclArray;
__interface  INTERFACE_UUID("{A69F6D35-54B2-4361-852E-097ED75E648A}") IJclArray  : public IJclList 
{
	
public:
	System::TObject* operator[](int Index) { return Objects[Index]; }
	
public:
	HIDESBASE virtual System::TObject* __fastcall GetObject(int Index) = 0 ;
	HIDESBASE virtual void __fastcall SetObject(int Index, System::TObject* AObject) = 0 ;
	__property System::TObject* Objects[int Index] = {read=GetObject, write=SetObject/*, default*/};
};

__interface IJclIntfSet;
typedef System::DelphiInterface<IJclIntfSet> _di_IJclIntfSet;
__interface  INTERFACE_UUID("{E2D28852-9774-49B7-A739-5DBA2B705924}") IJclIntfSet  : public IJclIntfCollection 
{
	
public:
	virtual void __fastcall Intersect(const _di_IJclIntfCollection ACollection) = 0 ;
	virtual void __fastcall Subtract(const _di_IJclIntfCollection ACollection) = 0 ;
	virtual void __fastcall Union(const _di_IJclIntfCollection ACollection) = 0 ;
};

__interface IJclAnsiStrSet;
typedef System::DelphiInterface<IJclAnsiStrSet> _di_IJclAnsiStrSet;
__interface  INTERFACE_UUID("{72204D85-2B68-4914-B9F2-09E5180C12E9}") IJclAnsiStrSet  : public IJclAnsiStrCollection 
{
	
public:
	virtual void __fastcall Intersect(const _di_IJclAnsiStrCollection ACollection) = 0 ;
	virtual void __fastcall Subtract(const _di_IJclAnsiStrCollection ACollection) = 0 ;
	virtual void __fastcall Union(const _di_IJclAnsiStrCollection ACollection) = 0 ;
};

__interface IJclWideStrSet;
typedef System::DelphiInterface<IJclWideStrSet> _di_IJclWideStrSet;
__interface  INTERFACE_UUID("{08009E0A-ABDD-46AB-8CEE-407D4723E17C}") IJclWideStrSet  : public IJclWideStrCollection 
{
	
public:
	virtual void __fastcall Intersect(const _di_IJclWideStrCollection ACollection) = 0 ;
	virtual void __fastcall Subtract(const _di_IJclWideStrCollection ACollection) = 0 ;
	virtual void __fastcall Union(const _di_IJclWideStrCollection ACollection) = 0 ;
};

typedef IJclAnsiStrSet IJclStrSet;
;

__interface IJclSingleSet;
typedef System::DelphiInterface<IJclSingleSet> _di_IJclSingleSet;
__interface  INTERFACE_UUID("{36E34A78-6A29-4503-97D5-4BF53538CEC0}") IJclSingleSet  : public IJclSingleCollection 
{
	
public:
	virtual void __fastcall Intersect(const _di_IJclSingleCollection ACollection) = 0 ;
	virtual void __fastcall Subtract(const _di_IJclSingleCollection ACollection) = 0 ;
	virtual void __fastcall Union(const _di_IJclSingleCollection ACollection) = 0 ;
};

__interface IJclDoubleSet;
typedef System::DelphiInterface<IJclDoubleSet> _di_IJclDoubleSet;
__interface  INTERFACE_UUID("{4E1E4847-E934-4811-A26C-5FC8E772A623}") IJclDoubleSet  : public IJclDoubleCollection 
{
	
public:
	virtual void __fastcall Intersect(const _di_IJclDoubleCollection ACollection) = 0 ;
	virtual void __fastcall Subtract(const _di_IJclDoubleCollection ACollection) = 0 ;
	virtual void __fastcall Union(const _di_IJclDoubleCollection ACollection) = 0 ;
};

__interface IJclExtendedSet;
typedef System::DelphiInterface<IJclExtendedSet> _di_IJclExtendedSet;
__interface  INTERFACE_UUID("{3B9CF52D-1C49-4388-A7B3-9BEE1821FFD4}") IJclExtendedSet  : public IJclExtendedCollection 
{
	
public:
	virtual void __fastcall Intersect(const _di_IJclExtendedCollection ACollection) = 0 ;
	virtual void __fastcall Subtract(const _di_IJclExtendedCollection ACollection) = 0 ;
	virtual void __fastcall Union(const _di_IJclExtendedCollection ACollection) = 0 ;
};

typedef IJclExtendedSet IJclFloatSet;
;

__interface IJclIntegerSet;
typedef System::DelphiInterface<IJclIntegerSet> _di_IJclIntegerSet;
__interface  INTERFACE_UUID("{5E4D29AF-F508-465B-9008-D11FF82F25FE}") IJclIntegerSet  : public IJclIntegerCollection 
{
	
public:
	virtual void __fastcall Intersect(const _di_IJclIntegerCollection ACollection) = 0 ;
	virtual void __fastcall Subtract(const _di_IJclIntegerCollection ACollection) = 0 ;
	virtual void __fastcall Union(const _di_IJclIntegerCollection ACollection) = 0 ;
};

__interface IJclCardinalSet;
typedef System::DelphiInterface<IJclCardinalSet> _di_IJclCardinalSet;
__interface  INTERFACE_UUID("{09858637-CE8F-42E6-97E0-2786CD68387B}") IJclCardinalSet  : public IJclCardinalCollection 
{
	
public:
	virtual void __fastcall Intersect(const _di_IJclCardinalCollection ACollection) = 0 ;
	virtual void __fastcall Subtract(const _di_IJclCardinalCollection ACollection) = 0 ;
	virtual void __fastcall Union(const _di_IJclCardinalCollection ACollection) = 0 ;
};

__interface IJclInt64Set;
typedef System::DelphiInterface<IJclInt64Set> _di_IJclInt64Set;
__interface  INTERFACE_UUID("{ACB3127A-48EE-4F9F-B988-6AE9057780E9}") IJclInt64Set  : public IJclInt64Collection 
{
	
public:
	virtual void __fastcall Intersect(const _di_IJclInt64Collection ACollection) = 0 ;
	virtual void __fastcall Subtract(const _di_IJclInt64Collection ACollection) = 0 ;
	virtual void __fastcall Union(const _di_IJclInt64Collection ACollection) = 0 ;
};

__interface IJclPtrSet;
typedef System::DelphiInterface<IJclPtrSet> _di_IJclPtrSet;
__interface  INTERFACE_UUID("{26717C68-4F83-4CCB-973A-7324FBD09632}") IJclPtrSet  : public IJclPtrCollection 
{
	
public:
	virtual void __fastcall Intersect(const _di_IJclPtrCollection ACollection) = 0 ;
	virtual void __fastcall Subtract(const _di_IJclPtrCollection ACollection) = 0 ;
	virtual void __fastcall Union(const _di_IJclPtrCollection ACollection) = 0 ;
};

__interface IJclSet;
typedef System::DelphiInterface<IJclSet> _di_IJclSet;
__interface  INTERFACE_UUID("{0B7CDB90-8588-4260-A54C-D87101C669EA}") IJclSet  : public IJclCollection 
{
	
public:
	virtual void __fastcall Intersect(const _di_IJclCollection ACollection) = 0 ;
	virtual void __fastcall Subtract(const _di_IJclCollection ACollection) = 0 ;
	virtual void __fastcall Union(const _di_IJclCollection ACollection) = 0 ;
};

#pragma option push -b-
enum TJclTraverseOrder { toPreOrder, toOrder, toPostOrder };
#pragma option pop

__interface IJclIntfTree;
typedef System::DelphiInterface<IJclIntfTree> _di_IJclIntfTree;
__interface  INTERFACE_UUID("{5A21688F-113D-41B4-A17C-54BDB0BD6559}") IJclIntfTree  : public IJclIntfCollection 
{
	
public:
	virtual _di_IJclIntfTreeIterator __fastcall GetRoot(void) = 0 ;
	virtual TJclTraverseOrder __fastcall GetTraverseOrder(void) = 0 ;
	virtual void __fastcall SetTraverseOrder(TJclTraverseOrder Value) = 0 ;
	__property _di_IJclIntfTreeIterator Root = {read=GetRoot};
	__property TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder};
};

__interface IJclAnsiStrTree;
typedef System::DelphiInterface<IJclAnsiStrTree> _di_IJclAnsiStrTree;
__interface  INTERFACE_UUID("{1E1896C0-0497-47DF-83AF-A9422084636C}") IJclAnsiStrTree  : public IJclAnsiStrCollection 
{
	
public:
	virtual _di_IJclAnsiStrTreeIterator __fastcall GetRoot(void) = 0 ;
	virtual TJclTraverseOrder __fastcall GetTraverseOrder(void) = 0 ;
	virtual void __fastcall SetTraverseOrder(TJclTraverseOrder Value) = 0 ;
	__property _di_IJclAnsiStrTreeIterator Root = {read=GetRoot};
	__property TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder};
};

__interface IJclWideStrTree;
typedef System::DelphiInterface<IJclWideStrTree> _di_IJclWideStrTree;
__interface  INTERFACE_UUID("{E325615A-7A20-4788-87FA-9051002CCD91}") IJclWideStrTree  : public IJclWideStrCollection 
{
	
public:
	virtual _di_IJclWideStrTreeIterator __fastcall GetRoot(void) = 0 ;
	virtual TJclTraverseOrder __fastcall GetTraverseOrder(void) = 0 ;
	virtual void __fastcall SetTraverseOrder(TJclTraverseOrder Value) = 0 ;
	__property _di_IJclWideStrTreeIterator Root = {read=GetRoot};
	__property TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder};
};

typedef IJclAnsiStrTree IJclStrTree;
;

__interface IJclSingleTree;
typedef System::DelphiInterface<IJclSingleTree> _di_IJclSingleTree;
__interface  INTERFACE_UUID("{A90A51BC-EBD7-40D3-B0A0-C9987E7A83D0}") IJclSingleTree  : public IJclSingleCollection 
{
	
public:
	virtual _di_IJclSingleTreeIterator __fastcall GetRoot(void) = 0 ;
	virtual TJclTraverseOrder __fastcall GetTraverseOrder(void) = 0 ;
	virtual void __fastcall SetTraverseOrder(TJclTraverseOrder Value) = 0 ;
	__property _di_IJclSingleTreeIterator Root = {read=GetRoot};
	__property TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder};
};

__interface IJclDoubleTree;
typedef System::DelphiInterface<IJclDoubleTree> _di_IJclDoubleTree;
__interface  INTERFACE_UUID("{69DA85B1-A0DD-407B-B5CF-5EB7C6D4B82D}") IJclDoubleTree  : public IJclDoubleCollection 
{
	
public:
	virtual _di_IJclDoubleTreeIterator __fastcall GetRoot(void) = 0 ;
	virtual TJclTraverseOrder __fastcall GetTraverseOrder(void) = 0 ;
	virtual void __fastcall SetTraverseOrder(TJclTraverseOrder Value) = 0 ;
	__property _di_IJclDoubleTreeIterator Root = {read=GetRoot};
	__property TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder};
};

__interface IJclExtendedTree;
typedef System::DelphiInterface<IJclExtendedTree> _di_IJclExtendedTree;
__interface  INTERFACE_UUID("{9ACCCAFD-B617-43DC-AAF9-916BE324A17E}") IJclExtendedTree  : public IJclExtendedCollection 
{
	
public:
	virtual _di_IJclExtendedTreeIterator __fastcall GetRoot(void) = 0 ;
	virtual TJclTraverseOrder __fastcall GetTraverseOrder(void) = 0 ;
	virtual void __fastcall SetTraverseOrder(TJclTraverseOrder Value) = 0 ;
	__property _di_IJclExtendedTreeIterator Root = {read=GetRoot};
	__property TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder};
};

typedef IJclExtendedTree IJclFloatTree;
;

__interface IJclIntegerTree;
typedef System::DelphiInterface<IJclIntegerTree> _di_IJclIntegerTree;
__interface  INTERFACE_UUID("{40A6F934-E5F3-4C74-AC02-227035C8C3C6}") IJclIntegerTree  : public IJclIntegerCollection 
{
	
public:
	virtual _di_IJclIntegerTreeIterator __fastcall GetRoot(void) = 0 ;
	virtual TJclTraverseOrder __fastcall GetTraverseOrder(void) = 0 ;
	virtual void __fastcall SetTraverseOrder(TJclTraverseOrder Value) = 0 ;
	__property _di_IJclIntegerTreeIterator Root = {read=GetRoot};
	__property TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder};
};

__interface IJclCardinalTree;
typedef System::DelphiInterface<IJclCardinalTree> _di_IJclCardinalTree;
__interface  INTERFACE_UUID("{6C76C668-50C8-42A2-B72B-79BF102E270D}") IJclCardinalTree  : public IJclCardinalCollection 
{
	
public:
	virtual _di_IJclCardinalTreeIterator __fastcall GetRoot(void) = 0 ;
	virtual TJclTraverseOrder __fastcall GetTraverseOrder(void) = 0 ;
	virtual void __fastcall SetTraverseOrder(TJclTraverseOrder Value) = 0 ;
	__property _di_IJclCardinalTreeIterator Root = {read=GetRoot};
	__property TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder};
};

__interface IJclInt64Tree;
typedef System::DelphiInterface<IJclInt64Tree> _di_IJclInt64Tree;
__interface  INTERFACE_UUID("{1925B973-8B75-4A79-A993-DF2598FF19BE}") IJclInt64Tree  : public IJclInt64Collection 
{
	
public:
	virtual _di_IJclInt64TreeIterator __fastcall GetRoot(void) = 0 ;
	virtual TJclTraverseOrder __fastcall GetTraverseOrder(void) = 0 ;
	virtual void __fastcall SetTraverseOrder(TJclTraverseOrder Value) = 0 ;
	__property _di_IJclInt64TreeIterator Root = {read=GetRoot};
	__property TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder};
};

__interface IJclPtrTree;
typedef System::DelphiInterface<IJclPtrTree> _di_IJclPtrTree;
__interface  INTERFACE_UUID("{2C1ACA3E-3F23-4E3C-984D-151CF9776E14}") IJclPtrTree  : public IJclPtrCollection 
{
	
public:
	virtual _di_IJclPtrTreeIterator __fastcall GetRoot(void) = 0 ;
	virtual TJclTraverseOrder __fastcall GetTraverseOrder(void) = 0 ;
	virtual void __fastcall SetTraverseOrder(TJclTraverseOrder Value) = 0 ;
	__property _di_IJclPtrTreeIterator Root = {read=GetRoot};
	__property TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder};
};

__interface IJclTree;
typedef System::DelphiInterface<IJclTree> _di_IJclTree;
__interface  INTERFACE_UUID("{B0C658CC-FEF5-4178-A4C5-442C0DEDE207}") IJclTree  : public IJclCollection 
{
	
public:
	virtual _di_IJclTreeIterator __fastcall GetRoot(void) = 0 ;
	virtual TJclTraverseOrder __fastcall GetTraverseOrder(void) = 0 ;
	virtual void __fastcall SetTraverseOrder(TJclTraverseOrder Value) = 0 ;
	__property _di_IJclTreeIterator Root = {read=GetRoot};
	__property TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder};
};

__interface IJclIntfIntfMap;
typedef System::DelphiInterface<IJclIntfIntfMap> _di_IJclIntfIntfMap;
__interface  INTERFACE_UUID("{01D05399-4A05-4F3E-92F4-0C236BE77019}") IJclIntfIntfMap  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall ContainsValue(const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Extract(const System::_di_IInterface Key) = 0 ;
	virtual System::_di_IInterface __fastcall GetValue(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual System::_di_IInterface __fastcall KeyOfValue(const System::_di_IInterface Value) = 0 ;
	virtual _di_IJclIntfSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclIntfIntfMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclIntfIntfMap AMap) = 0 ;
	virtual void __fastcall PutValue(const System::_di_IInterface Key, const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Remove(const System::_di_IInterface Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclIntfCollection __fastcall Values(void) = 0 ;
	__property System::_di_IInterface Items[System::_di_IInterface Key] = {read=GetValue, write=PutValue};
};

__interface IJclAnsiStrIntfMap;
typedef System::DelphiInterface<IJclAnsiStrIntfMap> _di_IJclAnsiStrIntfMap;
__interface  INTERFACE_UUID("{A4788A96-281A-4924-AA24-03776DDAAD8A}") IJclAnsiStrIntfMap  : public IJclAnsiStrContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const AnsiString Key) = 0 ;
	virtual bool __fastcall ContainsValue(const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Extract(const AnsiString Key) = 0 ;
	virtual System::_di_IInterface __fastcall GetValue(const AnsiString Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual AnsiString __fastcall KeyOfValue(const System::_di_IInterface Value) = 0 ;
	virtual _di_IJclAnsiStrSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclAnsiStrIntfMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclAnsiStrIntfMap AMap) = 0 ;
	virtual void __fastcall PutValue(const AnsiString Key, const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Remove(const AnsiString Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclIntfCollection __fastcall Values(void) = 0 ;
	__property System::_di_IInterface Items[AnsiString Key] = {read=GetValue, write=PutValue};
};

__interface IJclWideStrIntfMap;
typedef System::DelphiInterface<IJclWideStrIntfMap> _di_IJclWideStrIntfMap;
__interface  INTERFACE_UUID("{C959AB76-9CF0-4C2C-A2C6-8A1846563FAF}") IJclWideStrIntfMap  : public IJclWideStrContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const WideString Key) = 0 ;
	virtual bool __fastcall ContainsValue(const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Extract(const WideString Key) = 0 ;
	virtual System::_di_IInterface __fastcall GetValue(const WideString Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual WideString __fastcall KeyOfValue(const System::_di_IInterface Value) = 0 ;
	virtual _di_IJclWideStrSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclWideStrIntfMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclWideStrIntfMap AMap) = 0 ;
	virtual void __fastcall PutValue(const WideString Key, const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Remove(const WideString Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclIntfCollection __fastcall Values(void) = 0 ;
	__property System::_di_IInterface Items[WideString Key] = {read=GetValue, write=PutValue};
};

typedef IJclAnsiStrIntfMap IJclStrIntfMap;
;

__interface IJclIntfAnsiStrMap;
typedef System::DelphiInterface<IJclIntfAnsiStrMap> _di_IJclIntfAnsiStrMap;
__interface  INTERFACE_UUID("{B10E324A-1D98-42FF-B9B4-7F99044591B2}") IJclIntfAnsiStrMap  : public IJclAnsiStrContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall ContainsValue(const AnsiString Value) = 0 ;
	virtual AnsiString __fastcall Extract(const System::_di_IInterface Key) = 0 ;
	virtual AnsiString __fastcall GetValue(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual System::_di_IInterface __fastcall KeyOfValue(const AnsiString Value) = 0 ;
	virtual _di_IJclIntfSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclIntfAnsiStrMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclIntfAnsiStrMap AMap) = 0 ;
	virtual void __fastcall PutValue(const System::_di_IInterface Key, const AnsiString Value) = 0 ;
	virtual AnsiString __fastcall Remove(const System::_di_IInterface Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclAnsiStrCollection __fastcall Values(void) = 0 ;
	__property AnsiString Items[System::_di_IInterface Key] = {read=GetValue, write=PutValue};
};

__interface IJclIntfWideStrMap;
typedef System::DelphiInterface<IJclIntfWideStrMap> _di_IJclIntfWideStrMap;
__interface  INTERFACE_UUID("{D9FD7887-B840-4636-8A8F-E586663E332C}") IJclIntfWideStrMap  : public IJclWideStrContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall ContainsValue(const WideString Value) = 0 ;
	virtual WideString __fastcall Extract(const System::_di_IInterface Key) = 0 ;
	virtual WideString __fastcall GetValue(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual System::_di_IInterface __fastcall KeyOfValue(const WideString Value) = 0 ;
	virtual _di_IJclIntfSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclIntfWideStrMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclIntfWideStrMap AMap) = 0 ;
	virtual void __fastcall PutValue(const System::_di_IInterface Key, const WideString Value) = 0 ;
	virtual WideString __fastcall Remove(const System::_di_IInterface Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclWideStrCollection __fastcall Values(void) = 0 ;
	__property WideString Items[System::_di_IInterface Key] = {read=GetValue, write=PutValue};
};

typedef IJclIntfAnsiStrMap IJclIntfStrMap;
;

__interface IJclAnsiStrAnsiStrMap;
typedef System::DelphiInterface<IJclAnsiStrAnsiStrMap> _di_IJclAnsiStrAnsiStrMap;
__interface  INTERFACE_UUID("{A4788A96-281A-4924-AA24-03776DDAAD8A}") IJclAnsiStrAnsiStrMap  : public IJclAnsiStrContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const AnsiString Key) = 0 ;
	virtual bool __fastcall ContainsValue(const AnsiString Value) = 0 ;
	virtual AnsiString __fastcall Extract(const AnsiString Key) = 0 ;
	virtual AnsiString __fastcall GetValue(const AnsiString Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual AnsiString __fastcall KeyOfValue(const AnsiString Value) = 0 ;
	virtual _di_IJclAnsiStrSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclAnsiStrAnsiStrMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclAnsiStrAnsiStrMap AMap) = 0 ;
	virtual void __fastcall PutValue(const AnsiString Key, const AnsiString Value) = 0 ;
	virtual AnsiString __fastcall Remove(const AnsiString Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclAnsiStrCollection __fastcall Values(void) = 0 ;
	__property AnsiString Items[AnsiString Key] = {read=GetValue, write=PutValue};
};

__interface IJclWideStrWideStrMap;
typedef System::DelphiInterface<IJclWideStrWideStrMap> _di_IJclWideStrWideStrMap;
__interface  INTERFACE_UUID("{8E8D2735-C4FB-4F00-8802-B2102BCE3644}") IJclWideStrWideStrMap  : public IJclWideStrContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const WideString Key) = 0 ;
	virtual bool __fastcall ContainsValue(const WideString Value) = 0 ;
	virtual WideString __fastcall Extract(const WideString Key) = 0 ;
	virtual WideString __fastcall GetValue(const WideString Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual WideString __fastcall KeyOfValue(const WideString Value) = 0 ;
	virtual _di_IJclWideStrSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclWideStrWideStrMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclWideStrWideStrMap AMap) = 0 ;
	virtual void __fastcall PutValue(const WideString Key, const WideString Value) = 0 ;
	virtual WideString __fastcall Remove(const WideString Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclWideStrCollection __fastcall Values(void) = 0 ;
	__property WideString Items[WideString Key] = {read=GetValue, write=PutValue};
};

typedef IJclAnsiStrAnsiStrMap IJclStrStrMap;
;

__interface IJclSingleIntfMap;
typedef System::DelphiInterface<IJclSingleIntfMap> _di_IJclSingleIntfMap;
__interface  INTERFACE_UUID("{5F5E9E8B-E648-450B-B6C0-0EC65CC2D0BA}") IJclSingleIntfMap  : public IJclSingleContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const float Key) = 0 ;
	virtual bool __fastcall ContainsValue(const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Extract(const float Key) = 0 ;
	virtual System::_di_IInterface __fastcall GetValue(const float Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual float __fastcall KeyOfValue(const System::_di_IInterface Value) = 0 ;
	virtual _di_IJclSingleSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclSingleIntfMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclSingleIntfMap AMap) = 0 ;
	virtual void __fastcall PutValue(const float Key, const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Remove(const float Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclIntfCollection __fastcall Values(void) = 0 ;
	__property System::_di_IInterface Items[float Key] = {read=GetValue, write=PutValue};
};

__interface IJclIntfSingleMap;
typedef System::DelphiInterface<IJclIntfSingleMap> _di_IJclIntfSingleMap;
__interface  INTERFACE_UUID("{234D1618-FB0E-46F5-A70D-5106163A90F7}") IJclIntfSingleMap  : public IJclSingleContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall ContainsValue(const float Value) = 0 ;
	virtual float __fastcall Extract(const System::_di_IInterface Key) = 0 ;
	virtual float __fastcall GetValue(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual System::_di_IInterface __fastcall KeyOfValue(const float Value) = 0 ;
	virtual _di_IJclIntfSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclIntfSingleMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclIntfSingleMap AMap) = 0 ;
	virtual void __fastcall PutValue(const System::_di_IInterface Key, const float Value) = 0 ;
	virtual float __fastcall Remove(const System::_di_IInterface Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclSingleCollection __fastcall Values(void) = 0 ;
	__property float Items[System::_di_IInterface Key] = {read=GetValue, write=PutValue};
};

__interface IJclSingleSingleMap;
typedef System::DelphiInterface<IJclSingleSingleMap> _di_IJclSingleSingleMap;
__interface  INTERFACE_UUID("{AEB0008F-F3CF-4055-A7F3-A330D312F03F}") IJclSingleSingleMap  : public IJclSingleContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const float Key) = 0 ;
	virtual bool __fastcall ContainsValue(const float Value) = 0 ;
	virtual float __fastcall Extract(const float Key) = 0 ;
	virtual float __fastcall GetValue(const float Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual float __fastcall KeyOfValue(const float Value) = 0 ;
	virtual _di_IJclSingleSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclSingleSingleMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclSingleSingleMap AMap) = 0 ;
	virtual void __fastcall PutValue(const float Key, const float Value) = 0 ;
	virtual float __fastcall Remove(const float Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclSingleCollection __fastcall Values(void) = 0 ;
	__property float Items[float Key] = {read=GetValue, write=PutValue};
};

__interface IJclDoubleIntfMap;
typedef System::DelphiInterface<IJclDoubleIntfMap> _di_IJclDoubleIntfMap;
__interface  INTERFACE_UUID("{08968FFB-36C6-4FBA-BC09-3DCA2B5D7A50}") IJclDoubleIntfMap  : public IJclDoubleContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const double Key) = 0 ;
	virtual bool __fastcall ContainsValue(const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Extract(const double Key) = 0 ;
	virtual System::_di_IInterface __fastcall GetValue(const double Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual double __fastcall KeyOfValue(const System::_di_IInterface Value) = 0 ;
	virtual _di_IJclDoubleSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclDoubleIntfMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclDoubleIntfMap AMap) = 0 ;
	virtual void __fastcall PutValue(const double Key, const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Remove(const double Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclIntfCollection __fastcall Values(void) = 0 ;
	__property System::_di_IInterface Items[double Key] = {read=GetValue, write=PutValue};
};

__interface IJclIntfDoubleMap;
typedef System::DelphiInterface<IJclIntfDoubleMap> _di_IJclIntfDoubleMap;
__interface  INTERFACE_UUID("{B23DAF6A-6DC5-4DDD-835C-CD4633DDA010}") IJclIntfDoubleMap  : public IJclDoubleContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall ContainsValue(const double Value) = 0 ;
	virtual double __fastcall Extract(const System::_di_IInterface Key) = 0 ;
	virtual double __fastcall GetValue(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual System::_di_IInterface __fastcall KeyOfValue(const double Value) = 0 ;
	virtual _di_IJclIntfSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclIntfDoubleMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclIntfDoubleMap AMap) = 0 ;
	virtual void __fastcall PutValue(const System::_di_IInterface Key, const double Value) = 0 ;
	virtual double __fastcall Remove(const System::_di_IInterface Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclDoubleCollection __fastcall Values(void) = 0 ;
	__property double Items[System::_di_IInterface Key] = {read=GetValue, write=PutValue};
};

__interface IJclDoubleDoubleMap;
typedef System::DelphiInterface<IJclDoubleDoubleMap> _di_IJclDoubleDoubleMap;
__interface  INTERFACE_UUID("{329A03B8-0B6B-4FE3-87C5-4B63447A5FFD}") IJclDoubleDoubleMap  : public IJclDoubleContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const double Key) = 0 ;
	virtual bool __fastcall ContainsValue(const double Value) = 0 ;
	virtual double __fastcall Extract(const double Key) = 0 ;
	virtual double __fastcall GetValue(const double Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual double __fastcall KeyOfValue(const double Value) = 0 ;
	virtual _di_IJclDoubleSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclDoubleDoubleMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclDoubleDoubleMap AMap) = 0 ;
	virtual void __fastcall PutValue(const double Key, const double Value) = 0 ;
	virtual double __fastcall Remove(const double Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclDoubleCollection __fastcall Values(void) = 0 ;
	__property double Items[double Key] = {read=GetValue, write=PutValue};
};

__interface IJclExtendedIntfMap;
typedef System::DelphiInterface<IJclExtendedIntfMap> _di_IJclExtendedIntfMap;
__interface  INTERFACE_UUID("{7C0731E0-C9AB-4378-B1B0-8CE3DD60AD41}") IJclExtendedIntfMap  : public IJclExtendedContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const Extended Key) = 0 ;
	virtual bool __fastcall ContainsValue(const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Extract(const Extended Key) = 0 ;
	virtual System::_di_IInterface __fastcall GetValue(const Extended Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual Extended __fastcall KeyOfValue(const System::_di_IInterface Value) = 0 ;
	virtual _di_IJclExtendedSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclExtendedIntfMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclExtendedIntfMap AMap) = 0 ;
	virtual void __fastcall PutValue(const Extended Key, const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Remove(const Extended Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclIntfCollection __fastcall Values(void) = 0 ;
	__property System::_di_IInterface Items[Extended Key] = {read=GetValue, write=PutValue};
};

__interface IJclIntfExtendedMap;
typedef System::DelphiInterface<IJclIntfExtendedMap> _di_IJclIntfExtendedMap;
__interface  INTERFACE_UUID("{479FCE5A-2D8A-44EE-96BC-E8DA3187DBD8}") IJclIntfExtendedMap  : public IJclExtendedContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall ContainsValue(const Extended Value) = 0 ;
	virtual Extended __fastcall Extract(const System::_di_IInterface Key) = 0 ;
	virtual Extended __fastcall GetValue(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual System::_di_IInterface __fastcall KeyOfValue(const Extended Value) = 0 ;
	virtual _di_IJclIntfSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclIntfExtendedMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclIntfExtendedMap AMap) = 0 ;
	virtual void __fastcall PutValue(const System::_di_IInterface Key, const Extended Value) = 0 ;
	virtual Extended __fastcall Remove(const System::_di_IInterface Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclExtendedCollection __fastcall Values(void) = 0 ;
	__property Extended Items[System::_di_IInterface Key] = {read=GetValue, write=PutValue};
};

__interface IJclExtendedExtendedMap;
typedef System::DelphiInterface<IJclExtendedExtendedMap> _di_IJclExtendedExtendedMap;
__interface  INTERFACE_UUID("{962C2B09-8CF5-44E8-A21A-4A7DAFB72A11}") IJclExtendedExtendedMap  : public IJclExtendedContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const Extended Key) = 0 ;
	virtual bool __fastcall ContainsValue(const Extended Value) = 0 ;
	virtual Extended __fastcall Extract(const Extended Key) = 0 ;
	virtual Extended __fastcall GetValue(const Extended Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual Extended __fastcall KeyOfValue(const Extended Value) = 0 ;
	virtual _di_IJclExtendedSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclExtendedExtendedMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclExtendedExtendedMap AMap) = 0 ;
	virtual void __fastcall PutValue(const Extended Key, const Extended Value) = 0 ;
	virtual Extended __fastcall Remove(const Extended Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclExtendedCollection __fastcall Values(void) = 0 ;
	__property Extended Items[Extended Key] = {read=GetValue, write=PutValue};
};

typedef IJclExtendedIntfMap IJclFloatIntfMap;
;

typedef IJclIntfExtendedMap IJclIntfFloatMap;
;

typedef IJclExtendedExtendedMap IJclFloatFloatMap;
;

__interface IJclIntegerIntfMap;
typedef System::DelphiInterface<IJclIntegerIntfMap> _di_IJclIntegerIntfMap;
__interface  INTERFACE_UUID("{E535FE65-AC88-49D3-BEF2-FB30D92C2FA6}") IJclIntegerIntfMap  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(int Key) = 0 ;
	virtual bool __fastcall ContainsValue(const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Extract(int Key) = 0 ;
	virtual System::_di_IInterface __fastcall GetValue(int Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual int __fastcall KeyOfValue(const System::_di_IInterface Value) = 0 ;
	virtual _di_IJclIntegerSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclIntegerIntfMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclIntegerIntfMap AMap) = 0 ;
	virtual void __fastcall PutValue(int Key, const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Remove(int Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclIntfCollection __fastcall Values(void) = 0 ;
	__property System::_di_IInterface Items[int Key] = {read=GetValue, write=PutValue};
};

__interface IJclIntfIntegerMap;
typedef System::DelphiInterface<IJclIntfIntegerMap> _di_IJclIntfIntegerMap;
__interface  INTERFACE_UUID("{E01DA012-BEE0-4259-8E30-0A7A1A87BED0}") IJclIntfIntegerMap  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall ContainsValue(int Value) = 0 ;
	virtual int __fastcall Extract(const System::_di_IInterface Key) = 0 ;
	virtual int __fastcall GetValue(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual System::_di_IInterface __fastcall KeyOfValue(int Value) = 0 ;
	virtual _di_IJclIntfSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclIntfIntegerMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclIntfIntegerMap AMap) = 0 ;
	virtual void __fastcall PutValue(const System::_di_IInterface Key, int Value) = 0 ;
	virtual int __fastcall Remove(const System::_di_IInterface Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclIntegerCollection __fastcall Values(void) = 0 ;
	__property int Items[System::_di_IInterface Key] = {read=GetValue, write=PutValue};
};

__interface IJclIntegerIntegerMap;
typedef System::DelphiInterface<IJclIntegerIntegerMap> _di_IJclIntegerIntegerMap;
__interface  INTERFACE_UUID("{23A46BC0-DF8D-4BD2-89D2-4DACF1EC73A1}") IJclIntegerIntegerMap  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(int Key) = 0 ;
	virtual bool __fastcall ContainsValue(int Value) = 0 ;
	virtual int __fastcall Extract(int Key) = 0 ;
	virtual int __fastcall GetValue(int Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual int __fastcall KeyOfValue(int Value) = 0 ;
	virtual _di_IJclIntegerSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclIntegerIntegerMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclIntegerIntegerMap AMap) = 0 ;
	virtual void __fastcall PutValue(int Key, int Value) = 0 ;
	virtual int __fastcall Remove(int Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclIntegerCollection __fastcall Values(void) = 0 ;
	__property int Items[int Key] = {read=GetValue, write=PutValue};
};

__interface IJclCardinalIntfMap;
typedef System::DelphiInterface<IJclCardinalIntfMap> _di_IJclCardinalIntfMap;
__interface  INTERFACE_UUID("{80D39FB1-0D10-49CE-8AF3-1CD98A1D4F6C}") IJclCardinalIntfMap  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(unsigned Key) = 0 ;
	virtual bool __fastcall ContainsValue(const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Extract(unsigned Key) = 0 ;
	virtual System::_di_IInterface __fastcall GetValue(unsigned Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual unsigned __fastcall KeyOfValue(const System::_di_IInterface Value) = 0 ;
	virtual _di_IJclCardinalSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclCardinalIntfMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclCardinalIntfMap AMap) = 0 ;
	virtual void __fastcall PutValue(unsigned Key, const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Remove(unsigned Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclIntfCollection __fastcall Values(void) = 0 ;
	__property System::_di_IInterface Items[unsigned Key] = {read=GetValue, write=PutValue};
};

__interface IJclIntfCardinalMap;
typedef System::DelphiInterface<IJclIntfCardinalMap> _di_IJclIntfCardinalMap;
__interface  INTERFACE_UUID("{E1A724AB-6BDA-45F0-AE21-5E7E789A751B}") IJclIntfCardinalMap  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall ContainsValue(unsigned Value) = 0 ;
	virtual unsigned __fastcall Extract(const System::_di_IInterface Key) = 0 ;
	virtual unsigned __fastcall GetValue(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual System::_di_IInterface __fastcall KeyOfValue(unsigned Value) = 0 ;
	virtual _di_IJclIntfSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclIntfCardinalMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclIntfCardinalMap AMap) = 0 ;
	virtual void __fastcall PutValue(const System::_di_IInterface Key, unsigned Value) = 0 ;
	virtual unsigned __fastcall Remove(const System::_di_IInterface Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclCardinalCollection __fastcall Values(void) = 0 ;
	__property unsigned Items[System::_di_IInterface Key] = {read=GetValue, write=PutValue};
};

__interface IJclCardinalCardinalMap;
typedef System::DelphiInterface<IJclCardinalCardinalMap> _di_IJclCardinalCardinalMap;
__interface  INTERFACE_UUID("{1CD3F54C-F92F-4AF4-82B2-0829C08AA83B}") IJclCardinalCardinalMap  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(unsigned Key) = 0 ;
	virtual bool __fastcall ContainsValue(unsigned Value) = 0 ;
	virtual unsigned __fastcall Extract(unsigned Key) = 0 ;
	virtual unsigned __fastcall GetValue(unsigned Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual unsigned __fastcall KeyOfValue(unsigned Value) = 0 ;
	virtual _di_IJclCardinalSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclCardinalCardinalMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclCardinalCardinalMap AMap) = 0 ;
	virtual void __fastcall PutValue(unsigned Key, unsigned Value) = 0 ;
	virtual unsigned __fastcall Remove(unsigned Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclCardinalCollection __fastcall Values(void) = 0 ;
	__property unsigned Items[unsigned Key] = {read=GetValue, write=PutValue};
};

__interface IJclInt64IntfMap;
typedef System::DelphiInterface<IJclInt64IntfMap> _di_IJclInt64IntfMap;
__interface  INTERFACE_UUID("{B64FB2D1-8D45-4367-B950-98D3D05AC6A0}") IJclInt64IntfMap  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const __int64 Key) = 0 ;
	virtual bool __fastcall ContainsValue(const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Extract(const __int64 Key) = 0 ;
	virtual System::_di_IInterface __fastcall GetValue(const __int64 Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual __int64 __fastcall KeyOfValue(const System::_di_IInterface Value) = 0 ;
	virtual _di_IJclInt64Set __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclInt64IntfMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclInt64IntfMap AMap) = 0 ;
	virtual void __fastcall PutValue(const __int64 Key, const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Remove(const __int64 Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclIntfCollection __fastcall Values(void) = 0 ;
	__property System::_di_IInterface Items[__int64 Key] = {read=GetValue, write=PutValue};
};

__interface IJclIntfInt64Map;
typedef System::DelphiInterface<IJclIntfInt64Map> _di_IJclIntfInt64Map;
__interface  INTERFACE_UUID("{9886BEE3-D15B-45D2-A3FB-4D3A0ADEC8AC}") IJclIntfInt64Map  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall ContainsValue(const __int64 Value) = 0 ;
	virtual __int64 __fastcall Extract(const System::_di_IInterface Key) = 0 ;
	virtual __int64 __fastcall GetValue(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual System::_di_IInterface __fastcall KeyOfValue(const __int64 Value) = 0 ;
	virtual _di_IJclIntfSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclIntfInt64Map AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclIntfInt64Map AMap) = 0 ;
	virtual void __fastcall PutValue(const System::_di_IInterface Key, const __int64 Value) = 0 ;
	virtual __int64 __fastcall Remove(const System::_di_IInterface Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclInt64Collection __fastcall Values(void) = 0 ;
	__property __int64 Items[System::_di_IInterface Key] = {read=GetValue, write=PutValue};
};

__interface IJclInt64Int64Map;
typedef System::DelphiInterface<IJclInt64Int64Map> _di_IJclInt64Int64Map;
__interface  INTERFACE_UUID("{EF2A2726-408A-4984-9971-DDC1B6EFC9F5}") IJclInt64Int64Map  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const __int64 Key) = 0 ;
	virtual bool __fastcall ContainsValue(const __int64 Value) = 0 ;
	virtual __int64 __fastcall Extract(const __int64 Key) = 0 ;
	virtual __int64 __fastcall GetValue(const __int64 Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual __int64 __fastcall KeyOfValue(const __int64 Value) = 0 ;
	virtual _di_IJclInt64Set __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclInt64Int64Map AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclInt64Int64Map AMap) = 0 ;
	virtual void __fastcall PutValue(const __int64 Key, const __int64 Value) = 0 ;
	virtual __int64 __fastcall Remove(const __int64 Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclInt64Collection __fastcall Values(void) = 0 ;
	__property __int64 Items[__int64 Key] = {read=GetValue, write=PutValue};
};

__interface IJclPtrIntfMap;
typedef System::DelphiInterface<IJclPtrIntfMap> _di_IJclPtrIntfMap;
__interface  INTERFACE_UUID("{B7C48542-39A0-453F-8F03-8C8CFAB0DCCF}") IJclPtrIntfMap  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(void * Key) = 0 ;
	virtual bool __fastcall ContainsValue(const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Extract(void * Key) = 0 ;
	virtual System::_di_IInterface __fastcall GetValue(void * Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual void * __fastcall KeyOfValue(const System::_di_IInterface Value) = 0 ;
	virtual _di_IJclPtrSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclPtrIntfMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclPtrIntfMap AMap) = 0 ;
	virtual void __fastcall PutValue(void * Key, const System::_di_IInterface Value) = 0 ;
	virtual System::_di_IInterface __fastcall Remove(void * Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclIntfCollection __fastcall Values(void) = 0 ;
	__property System::_di_IInterface Items[void * Key] = {read=GetValue, write=PutValue};
};

__interface IJclIntfPtrMap;
typedef System::DelphiInterface<IJclIntfPtrMap> _di_IJclIntfPtrMap;
__interface  INTERFACE_UUID("{DA51D823-58DB-4D7C-9B8E-07E0FD560B57}") IJclIntfPtrMap  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall ContainsValue(void * Value) = 0 ;
	virtual void * __fastcall Extract(const System::_di_IInterface Key) = 0 ;
	virtual void * __fastcall GetValue(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual System::_di_IInterface __fastcall KeyOfValue(void * Value) = 0 ;
	virtual _di_IJclIntfSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclIntfPtrMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclIntfPtrMap AMap) = 0 ;
	virtual void __fastcall PutValue(const System::_di_IInterface Key, void * Value) = 0 ;
	virtual void * __fastcall Remove(const System::_di_IInterface Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclPtrCollection __fastcall Values(void) = 0 ;
	__property void * Items[System::_di_IInterface Key] = {read=GetValue, write=PutValue};
};

__interface IJclPtrPtrMap;
typedef System::DelphiInterface<IJclPtrPtrMap> _di_IJclPtrPtrMap;
__interface  INTERFACE_UUID("{1200CB0F-A766-443F-9030-5A804C11B798}") IJclPtrPtrMap  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(void * Key) = 0 ;
	virtual bool __fastcall ContainsValue(void * Value) = 0 ;
	virtual void * __fastcall Extract(void * Key) = 0 ;
	virtual void * __fastcall GetValue(void * Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual void * __fastcall KeyOfValue(void * Value) = 0 ;
	virtual _di_IJclPtrSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclPtrPtrMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclPtrPtrMap AMap) = 0 ;
	virtual void __fastcall PutValue(void * Key, void * Value) = 0 ;
	virtual void * __fastcall Remove(void * Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclPtrCollection __fastcall Values(void) = 0 ;
	__property void * Items[void * Key] = {read=GetValue, write=PutValue};
};

__interface IJclIntfMap;
typedef System::DelphiInterface<IJclIntfMap> _di_IJclIntfMap;
__interface  INTERFACE_UUID("{C70570C6-EDDB-47B4-9003-C637B486731D}") IJclIntfMap  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall ContainsValue(System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Extract(const System::_di_IInterface Key) = 0 ;
	virtual System::TObject* __fastcall GetValue(const System::_di_IInterface Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual System::_di_IInterface __fastcall KeyOfValue(System::TObject* Value) = 0 ;
	virtual _di_IJclIntfSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclIntfMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclIntfMap AMap) = 0 ;
	virtual void __fastcall PutValue(const System::_di_IInterface Key, System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Remove(const System::_di_IInterface Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclCollection __fastcall Values(void) = 0 ;
	__property System::TObject* Items[System::_di_IInterface Key] = {read=GetValue, write=PutValue};
};

__interface IJclAnsiStrMap;
typedef System::DelphiInterface<IJclAnsiStrMap> _di_IJclAnsiStrMap;
__interface  INTERFACE_UUID("{A7D0A882-6952-496D-A258-23D47DDCCBC4}") IJclAnsiStrMap  : public IJclAnsiStrContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const AnsiString Key) = 0 ;
	virtual bool __fastcall ContainsValue(System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Extract(const AnsiString Key) = 0 ;
	virtual System::TObject* __fastcall GetValue(const AnsiString Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual AnsiString __fastcall KeyOfValue(System::TObject* Value) = 0 ;
	virtual _di_IJclAnsiStrSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclAnsiStrMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclAnsiStrMap AMap) = 0 ;
	virtual void __fastcall PutValue(const AnsiString Key, System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Remove(const AnsiString Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclCollection __fastcall Values(void) = 0 ;
	__property System::TObject* Items[AnsiString Key] = {read=GetValue, write=PutValue};
};

__interface IJclWideStrMap;
typedef System::DelphiInterface<IJclWideStrMap> _di_IJclWideStrMap;
__interface  INTERFACE_UUID("{ACE8E6B4-5A56-4753-A2C6-BAE195A56B63}") IJclWideStrMap  : public IJclWideStrContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const WideString Key) = 0 ;
	virtual bool __fastcall ContainsValue(System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Extract(const WideString Key) = 0 ;
	virtual System::TObject* __fastcall GetValue(const WideString Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual WideString __fastcall KeyOfValue(System::TObject* Value) = 0 ;
	virtual _di_IJclWideStrSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclWideStrMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclWideStrMap AMap) = 0 ;
	virtual void __fastcall PutValue(const WideString Key, System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Remove(const WideString Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclCollection __fastcall Values(void) = 0 ;
	__property System::TObject* Items[WideString Key] = {read=GetValue, write=PutValue};
};

typedef IJclAnsiStrMap IJclStrMap;
;

__interface IJclSingleMap;
typedef System::DelphiInterface<IJclSingleMap> _di_IJclSingleMap;
__interface  INTERFACE_UUID("{C501920A-F252-4F94-B142-1F05AE06C3D2}") IJclSingleMap  : public IJclSingleContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const float Key) = 0 ;
	virtual bool __fastcall ContainsValue(System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Extract(const float Key) = 0 ;
	virtual System::TObject* __fastcall GetValue(const float Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual float __fastcall KeyOfValue(System::TObject* Value) = 0 ;
	virtual _di_IJclSingleSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclSingleMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclSingleMap AMap) = 0 ;
	virtual void __fastcall PutValue(const float Key, System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Remove(const float Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclCollection __fastcall Values(void) = 0 ;
	__property System::TObject* Items[float Key] = {read=GetValue, write=PutValue};
};

__interface IJclDoubleMap;
typedef System::DelphiInterface<IJclDoubleMap> _di_IJclDoubleMap;
__interface  INTERFACE_UUID("{B1B994AC-49C9-418B-814B-43BAD706F355}") IJclDoubleMap  : public IJclDoubleContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const double Key) = 0 ;
	virtual bool __fastcall ContainsValue(System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Extract(const double Key) = 0 ;
	virtual System::TObject* __fastcall GetValue(const double Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual double __fastcall KeyOfValue(System::TObject* Value) = 0 ;
	virtual _di_IJclDoubleSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclDoubleMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclDoubleMap AMap) = 0 ;
	virtual void __fastcall PutValue(const double Key, System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Remove(const double Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclCollection __fastcall Values(void) = 0 ;
	__property System::TObject* Items[double Key] = {read=GetValue, write=PutValue};
};

__interface IJclExtendedMap;
typedef System::DelphiInterface<IJclExtendedMap> _di_IJclExtendedMap;
__interface  INTERFACE_UUID("{3BCC8C87-A186-45E8-9B37-0B8E85120434}") IJclExtendedMap  : public IJclExtendedContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const Extended Key) = 0 ;
	virtual bool __fastcall ContainsValue(System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Extract(const Extended Key) = 0 ;
	virtual System::TObject* __fastcall GetValue(const Extended Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual Extended __fastcall KeyOfValue(System::TObject* Value) = 0 ;
	virtual _di_IJclExtendedSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclExtendedMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclExtendedMap AMap) = 0 ;
	virtual void __fastcall PutValue(const Extended Key, System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Remove(const Extended Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclCollection __fastcall Values(void) = 0 ;
	__property System::TObject* Items[Extended Key] = {read=GetValue, write=PutValue};
};

typedef IJclExtendedMap IJclFloatMap;
;

__interface IJclIntegerMap;
typedef System::DelphiInterface<IJclIntegerMap> _di_IJclIntegerMap;
__interface  INTERFACE_UUID("{D6FA5D64-A4AF-4419-9981-56BA79BF8770}") IJclIntegerMap  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(int Key) = 0 ;
	virtual bool __fastcall ContainsValue(System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Extract(int Key) = 0 ;
	virtual System::TObject* __fastcall GetValue(int Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual int __fastcall KeyOfValue(System::TObject* Value) = 0 ;
	virtual _di_IJclIntegerSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclIntegerMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclIntegerMap AMap) = 0 ;
	virtual void __fastcall PutValue(int Key, System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Remove(int Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclCollection __fastcall Values(void) = 0 ;
	__property System::TObject* Items[int Key] = {read=GetValue, write=PutValue};
};

__interface IJclCardinalMap;
typedef System::DelphiInterface<IJclCardinalMap> _di_IJclCardinalMap;
__interface  INTERFACE_UUID("{A2F92F4F-11CB-4DB2-932F-F10A14237126}") IJclCardinalMap  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(unsigned Key) = 0 ;
	virtual bool __fastcall ContainsValue(System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Extract(unsigned Key) = 0 ;
	virtual System::TObject* __fastcall GetValue(unsigned Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual unsigned __fastcall KeyOfValue(System::TObject* Value) = 0 ;
	virtual _di_IJclCardinalSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclCardinalMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclCardinalMap AMap) = 0 ;
	virtual void __fastcall PutValue(unsigned Key, System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Remove(unsigned Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclCollection __fastcall Values(void) = 0 ;
	__property System::TObject* Items[unsigned Key] = {read=GetValue, write=PutValue};
};

__interface IJclInt64Map;
typedef System::DelphiInterface<IJclInt64Map> _di_IJclInt64Map;
__interface  INTERFACE_UUID("{4C720CE0-7A7C-41D5-BFC1-8D58A47E648F}") IJclInt64Map  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(const __int64 Key) = 0 ;
	virtual bool __fastcall ContainsValue(System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Extract(const __int64 Key) = 0 ;
	virtual System::TObject* __fastcall GetValue(const __int64 Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual __int64 __fastcall KeyOfValue(System::TObject* Value) = 0 ;
	virtual _di_IJclInt64Set __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclInt64Map AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclInt64Map AMap) = 0 ;
	virtual void __fastcall PutValue(const __int64 Key, System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Remove(const __int64 Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclCollection __fastcall Values(void) = 0 ;
	__property System::TObject* Items[__int64 Key] = {read=GetValue, write=PutValue};
};

__interface IJclPtrMap;
typedef System::DelphiInterface<IJclPtrMap> _di_IJclPtrMap;
__interface  INTERFACE_UUID("{2FE029A9-026C-487D-8204-AD3A28BD2FA2}") IJclPtrMap  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(void * Key) = 0 ;
	virtual bool __fastcall ContainsValue(System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Extract(void * Key) = 0 ;
	virtual System::TObject* __fastcall GetValue(void * Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual void * __fastcall KeyOfValue(System::TObject* Value) = 0 ;
	virtual _di_IJclPtrSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclPtrMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclPtrMap AMap) = 0 ;
	virtual void __fastcall PutValue(void * Key, System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Remove(void * Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclCollection __fastcall Values(void) = 0 ;
	__property System::TObject* Items[void * Key] = {read=GetValue, write=PutValue};
};

__interface IJclMap;
typedef System::DelphiInterface<IJclMap> _di_IJclMap;
__interface  INTERFACE_UUID("{A7D0A882-6952-496D-A258-23D47DDCCBC4}") IJclMap  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall ContainsKey(System::TObject* Key) = 0 ;
	virtual bool __fastcall ContainsValue(System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Extract(System::TObject* Key) = 0 ;
	virtual System::TObject* __fastcall GetValue(System::TObject* Key) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual System::TObject* __fastcall KeyOfValue(System::TObject* Value) = 0 ;
	virtual _di_IJclSet __fastcall KeySet(void) = 0 ;
	virtual bool __fastcall MapEquals(const _di_IJclMap AMap) = 0 ;
	virtual void __fastcall PutAll(const _di_IJclMap AMap) = 0 ;
	virtual void __fastcall PutValue(System::TObject* Key, System::TObject* Value) = 0 ;
	virtual System::TObject* __fastcall Remove(System::TObject* Key) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual _di_IJclCollection __fastcall Values(void) = 0 ;
	__property System::TObject* Items[System::TObject* Key] = {read=GetValue, write=PutValue};
};

__interface IJclIntfQueue;
typedef System::DelphiInterface<IJclIntfQueue> _di_IJclIntfQueue;
__interface  INTERFACE_UUID("{B88756FE-5553-4106-957E-3E33120BFA99}") IJclIntfQueue  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const System::_di_IInterface AInterface) = 0 ;
	virtual System::_di_IInterface __fastcall Dequeue(void) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual bool __fastcall Enqueue(const System::_di_IInterface AInterface) = 0 ;
	virtual System::_di_IInterface __fastcall Peek(void) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

__interface IJclAnsiStrQueue;
typedef System::DelphiInterface<IJclAnsiStrQueue> _di_IJclAnsiStrQueue;
__interface  INTERFACE_UUID("{5BA0ED9A-5AF3-4F79-9D80-34FA7FF15D1F}") IJclAnsiStrQueue  : public IJclAnsiStrContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const AnsiString AString) = 0 ;
	virtual AnsiString __fastcall Dequeue(void) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual bool __fastcall Enqueue(const AnsiString AString) = 0 ;
	virtual AnsiString __fastcall Peek(void) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

__interface IJclWideStrQueue;
typedef System::DelphiInterface<IJclWideStrQueue> _di_IJclWideStrQueue;
__interface  INTERFACE_UUID("{058BBFB7-E9B9-44B5-B676-D5B5B9A79BEF}") IJclWideStrQueue  : public IJclWideStrContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const WideString AString) = 0 ;
	virtual WideString __fastcall Dequeue(void) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual bool __fastcall Enqueue(const WideString AString) = 0 ;
	virtual WideString __fastcall Peek(void) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

typedef IJclAnsiStrQueue IJclStrQueue;
;

__interface IJclSingleQueue;
typedef System::DelphiInterface<IJclSingleQueue> _di_IJclSingleQueue;
__interface  INTERFACE_UUID("{67D74314-9967-4C99-8A48-6E0ADD73EC29}") IJclSingleQueue  : public IJclSingleContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const float AValue) = 0 ;
	virtual float __fastcall Dequeue(void) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual bool __fastcall Enqueue(const float AValue) = 0 ;
	virtual float __fastcall Peek(void) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

__interface IJclDoubleQueue;
typedef System::DelphiInterface<IJclDoubleQueue> _di_IJclDoubleQueue;
__interface  INTERFACE_UUID("{FA1B6D25-3456-4963-87DC-5A2E53B2963F}") IJclDoubleQueue  : public IJclDoubleContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const double AValue) = 0 ;
	virtual double __fastcall Dequeue(void) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual bool __fastcall Enqueue(const double AValue) = 0 ;
	virtual double __fastcall Peek(void) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

__interface IJclExtendedQueue;
typedef System::DelphiInterface<IJclExtendedQueue> _di_IJclExtendedQueue;
__interface  INTERFACE_UUID("{76F349C0-7681-4BE8-9E94-280C962780D8}") IJclExtendedQueue  : public IJclExtendedContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const Extended AValue) = 0 ;
	virtual Extended __fastcall Dequeue(void) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual bool __fastcall Enqueue(const Extended AValue) = 0 ;
	virtual Extended __fastcall Peek(void) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

typedef IJclExtendedQueue IJclFloatQueue;
;

__interface IJclIntegerQueue;
typedef System::DelphiInterface<IJclIntegerQueue> _di_IJclIntegerQueue;
__interface  INTERFACE_UUID("{4C4E174E-5D19-44CE-A248-B5589A9B68DF}") IJclIntegerQueue  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(int AValue) = 0 ;
	virtual int __fastcall Dequeue(void) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual bool __fastcall Enqueue(int AValue) = 0 ;
	virtual int __fastcall Peek(void) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

__interface IJclCardinalQueue;
typedef System::DelphiInterface<IJclCardinalQueue> _di_IJclCardinalQueue;
__interface  INTERFACE_UUID("{CC1D4358-E259-4FB0-BA83-5180A0F8A6C0}") IJclCardinalQueue  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(unsigned AValue) = 0 ;
	virtual unsigned __fastcall Dequeue(void) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual bool __fastcall Enqueue(unsigned AValue) = 0 ;
	virtual unsigned __fastcall Peek(void) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

__interface IJclInt64Queue;
typedef System::DelphiInterface<IJclInt64Queue> _di_IJclInt64Queue;
__interface  INTERFACE_UUID("{96B620BB-9A90-43D5-82A7-2D818A11C8E1}") IJclInt64Queue  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const __int64 AValue) = 0 ;
	virtual __int64 __fastcall Dequeue(void) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual bool __fastcall Enqueue(const __int64 AValue) = 0 ;
	virtual __int64 __fastcall Peek(void) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

__interface IJclPtrQueue;
typedef System::DelphiInterface<IJclPtrQueue> _di_IJclPtrQueue;
__interface  INTERFACE_UUID("{1052DD37-3035-4C44-A793-54AC4B9C0B29}") IJclPtrQueue  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(void * APtr) = 0 ;
	virtual void * __fastcall Dequeue(void) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual bool __fastcall Enqueue(void * APtr) = 0 ;
	virtual void * __fastcall Peek(void) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

__interface IJclQueue;
typedef System::DelphiInterface<IJclQueue> _di_IJclQueue;
__interface  INTERFACE_UUID("{7D0F9DE4-71EA-46EF-B879-88BCFD5D9610}") IJclQueue  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(System::TObject* AObject) = 0 ;
	virtual System::TObject* __fastcall Dequeue(void) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual bool __fastcall Enqueue(System::TObject* AObject) = 0 ;
	virtual System::TObject* __fastcall Peek(void) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

__interface IJclIntfIntfSortedMap;
typedef System::DelphiInterface<IJclIntfIntfSortedMap> _di_IJclIntfIntfSortedMap;
__interface  INTERFACE_UUID("{265A6EB2-4BB3-459F-8813-360FD32A4971}") IJclIntfIntfSortedMap  : public IJclIntfIntfMap 
{
	
public:
	virtual System::_di_IInterface __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclIntfIntfSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey) = 0 ;
	virtual System::_di_IInterface __fastcall LastKey(void) = 0 ;
	virtual _di_IJclIntfIntfSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey) = 0 ;
	virtual _di_IJclIntfIntfSortedMap __fastcall TailMap(const System::_di_IInterface FromKey) = 0 ;
};

__interface IJclAnsiStrIntfSortedMap;
typedef System::DelphiInterface<IJclAnsiStrIntfSortedMap> _di_IJclAnsiStrIntfSortedMap;
__interface  INTERFACE_UUID("{706D1C91-5416-4FDC-B6B1-F4C1E8CFCD38}") IJclAnsiStrIntfSortedMap  : public IJclAnsiStrIntfMap 
{
	
public:
	virtual AnsiString __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclAnsiStrIntfSortedMap __fastcall HeadMap(const AnsiString ToKey) = 0 ;
	virtual AnsiString __fastcall LastKey(void) = 0 ;
	virtual _di_IJclAnsiStrIntfSortedMap __fastcall SubMap(const AnsiString FromKey, const AnsiString ToKey) = 0 ;
	virtual _di_IJclAnsiStrIntfSortedMap __fastcall TailMap(const AnsiString FromKey) = 0 ;
};

__interface IJclWideStrIntfSortedMap;
typedef System::DelphiInterface<IJclWideStrIntfSortedMap> _di_IJclWideStrIntfSortedMap;
__interface  INTERFACE_UUID("{299FDCFD-2DB7-4D64-BF18-EE3668316430}") IJclWideStrIntfSortedMap  : public IJclWideStrIntfMap 
{
	
public:
	virtual WideString __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclWideStrIntfSortedMap __fastcall HeadMap(const WideString ToKey) = 0 ;
	virtual WideString __fastcall LastKey(void) = 0 ;
	virtual _di_IJclWideStrIntfSortedMap __fastcall SubMap(const WideString FromKey, const WideString ToKey) = 0 ;
	virtual _di_IJclWideStrIntfSortedMap __fastcall TailMap(const WideString FromKey) = 0 ;
};

typedef IJclAnsiStrIntfSortedMap IJclStrIntfSortedMap;
;

__interface IJclIntfAnsiStrSortedMap;
typedef System::DelphiInterface<IJclIntfAnsiStrSortedMap> _di_IJclIntfAnsiStrSortedMap;
__interface  INTERFACE_UUID("{96E6AC5E-8C40-4795-9C8A-CFD098B58680}") IJclIntfAnsiStrSortedMap  : public IJclIntfAnsiStrMap 
{
	
public:
	virtual System::_di_IInterface __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclIntfAnsiStrSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey) = 0 ;
	virtual System::_di_IInterface __fastcall LastKey(void) = 0 ;
	virtual _di_IJclIntfAnsiStrSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey) = 0 ;
	virtual _di_IJclIntfAnsiStrSortedMap __fastcall TailMap(const System::_di_IInterface FromKey) = 0 ;
};

__interface IJclIntfWideStrSortedMap;
typedef System::DelphiInterface<IJclIntfWideStrSortedMap> _di_IJclIntfWideStrSortedMap;
__interface  INTERFACE_UUID("{FBE3AD2E-2781-4DC0-9E80-027027380E21}") IJclIntfWideStrSortedMap  : public IJclIntfWideStrMap 
{
	
public:
	virtual System::_di_IInterface __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclIntfWideStrSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey) = 0 ;
	virtual System::_di_IInterface __fastcall LastKey(void) = 0 ;
	virtual _di_IJclIntfWideStrSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey) = 0 ;
	virtual _di_IJclIntfWideStrSortedMap __fastcall TailMap(const System::_di_IInterface FromKey) = 0 ;
};

typedef IJclIntfAnsiStrSortedMap IJclIntfStrSortedMap;
;

__interface IJclAnsiStrAnsiStrSortedMap;
typedef System::DelphiInterface<IJclAnsiStrAnsiStrSortedMap> _di_IJclAnsiStrAnsiStrSortedMap;
__interface  INTERFACE_UUID("{4F457799-5D03-413D-A46C-067DC4200CC3}") IJclAnsiStrAnsiStrSortedMap  : public IJclAnsiStrAnsiStrMap 
{
	
public:
	virtual AnsiString __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclAnsiStrAnsiStrSortedMap __fastcall HeadMap(const AnsiString ToKey) = 0 ;
	virtual AnsiString __fastcall LastKey(void) = 0 ;
	virtual _di_IJclAnsiStrAnsiStrSortedMap __fastcall SubMap(const AnsiString FromKey, const AnsiString ToKey) = 0 ;
	virtual _di_IJclAnsiStrAnsiStrSortedMap __fastcall TailMap(const AnsiString FromKey) = 0 ;
};

__interface IJclWideStrWideStrSortedMap;
typedef System::DelphiInterface<IJclWideStrWideStrSortedMap> _di_IJclWideStrWideStrSortedMap;
__interface  INTERFACE_UUID("{3B0757B2-2290-4AFA-880D-F9BA600E501E}") IJclWideStrWideStrSortedMap  : public IJclWideStrWideStrMap 
{
	
public:
	virtual WideString __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclWideStrWideStrSortedMap __fastcall HeadMap(const WideString ToKey) = 0 ;
	virtual WideString __fastcall LastKey(void) = 0 ;
	virtual _di_IJclWideStrWideStrSortedMap __fastcall SubMap(const WideString FromKey, const WideString ToKey) = 0 ;
	virtual _di_IJclWideStrWideStrSortedMap __fastcall TailMap(const WideString FromKey) = 0 ;
};

typedef IJclAnsiStrAnsiStrSortedMap IJclStrStrSortedMap;
;

__interface IJclSingleIntfSortedMap;
typedef System::DelphiInterface<IJclSingleIntfSortedMap> _di_IJclSingleIntfSortedMap;
__interface  INTERFACE_UUID("{83D57068-7B8E-453E-B35B-2AB4B594A7A9}") IJclSingleIntfSortedMap  : public IJclSingleIntfMap 
{
	
public:
	virtual float __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclSingleIntfSortedMap __fastcall HeadMap(const float ToKey) = 0 ;
	virtual float __fastcall LastKey(void) = 0 ;
	virtual _di_IJclSingleIntfSortedMap __fastcall SubMap(const float FromKey, const float ToKey) = 0 ;
	virtual _di_IJclSingleIntfSortedMap __fastcall TailMap(const float FromKey) = 0 ;
};

__interface IJclIntfSingleSortedMap;
typedef System::DelphiInterface<IJclIntfSingleSortedMap> _di_IJclIntfSingleSortedMap;
__interface  INTERFACE_UUID("{B07FA192-3466-4F2A-BBF0-2DC0100B08A8}") IJclIntfSingleSortedMap  : public IJclIntfSingleMap 
{
	
public:
	virtual System::_di_IInterface __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclIntfSingleSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey) = 0 ;
	virtual System::_di_IInterface __fastcall LastKey(void) = 0 ;
	virtual _di_IJclIntfSingleSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey) = 0 ;
	virtual _di_IJclIntfSingleSortedMap __fastcall TailMap(const System::_di_IInterface FromKey) = 0 ;
};

__interface IJclSingleSingleSortedMap;
typedef System::DelphiInterface<IJclSingleSingleSortedMap> _di_IJclSingleSingleSortedMap;
__interface  INTERFACE_UUID("{7C6EA0B4-959D-44D5-915F-99DFC1753B00}") IJclSingleSingleSortedMap  : public IJclSingleSingleMap 
{
	
public:
	virtual float __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclSingleSingleSortedMap __fastcall HeadMap(const float ToKey) = 0 ;
	virtual float __fastcall LastKey(void) = 0 ;
	virtual _di_IJclSingleSingleSortedMap __fastcall SubMap(const float FromKey, const float ToKey) = 0 ;
	virtual _di_IJclSingleSingleSortedMap __fastcall TailMap(const float FromKey) = 0 ;
};

__interface IJclDoubleIntfSortedMap;
typedef System::DelphiInterface<IJclDoubleIntfSortedMap> _di_IJclDoubleIntfSortedMap;
__interface  INTERFACE_UUID("{F36C5F4F-4F8C-4943-AA35-41623D3C21E9}") IJclDoubleIntfSortedMap  : public IJclDoubleIntfMap 
{
	
public:
	virtual double __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclDoubleIntfSortedMap __fastcall HeadMap(const double ToKey) = 0 ;
	virtual double __fastcall LastKey(void) = 0 ;
	virtual _di_IJclDoubleIntfSortedMap __fastcall SubMap(const double FromKey, const double ToKey) = 0 ;
	virtual _di_IJclDoubleIntfSortedMap __fastcall TailMap(const double FromKey) = 0 ;
};

__interface IJclIntfDoubleSortedMap;
typedef System::DelphiInterface<IJclIntfDoubleSortedMap> _di_IJclIntfDoubleSortedMap;
__interface  INTERFACE_UUID("{0F16ADAE-F499-4857-B5EA-6F3CC9009DBA}") IJclIntfDoubleSortedMap  : public IJclIntfDoubleMap 
{
	
public:
	virtual System::_di_IInterface __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclIntfDoubleSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey) = 0 ;
	virtual System::_di_IInterface __fastcall LastKey(void) = 0 ;
	virtual _di_IJclIntfDoubleSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey) = 0 ;
	virtual _di_IJclIntfDoubleSortedMap __fastcall TailMap(const System::_di_IInterface FromKey) = 0 ;
};

__interface IJclDoubleDoubleSortedMap;
typedef System::DelphiInterface<IJclDoubleDoubleSortedMap> _di_IJclDoubleDoubleSortedMap;
__interface  INTERFACE_UUID("{855C858B-74CF-4338-872B-AF88A02DB537}") IJclDoubleDoubleSortedMap  : public IJclDoubleDoubleMap 
{
	
public:
	virtual double __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclDoubleDoubleSortedMap __fastcall HeadMap(const double ToKey) = 0 ;
	virtual double __fastcall LastKey(void) = 0 ;
	virtual _di_IJclDoubleDoubleSortedMap __fastcall SubMap(const double FromKey, const double ToKey) = 0 ;
	virtual _di_IJclDoubleDoubleSortedMap __fastcall TailMap(const double FromKey) = 0 ;
};

__interface IJclExtendedIntfSortedMap;
typedef System::DelphiInterface<IJclExtendedIntfSortedMap> _di_IJclExtendedIntfSortedMap;
__interface  INTERFACE_UUID("{A30B8835-A319-4776-9A11-D1EEF60B9C26}") IJclExtendedIntfSortedMap  : public IJclExtendedIntfMap 
{
	
public:
	virtual Extended __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclExtendedIntfSortedMap __fastcall HeadMap(const Extended ToKey) = 0 ;
	virtual Extended __fastcall LastKey(void) = 0 ;
	virtual _di_IJclExtendedIntfSortedMap __fastcall SubMap(const Extended FromKey, const Extended ToKey) = 0 ;
	virtual _di_IJclExtendedIntfSortedMap __fastcall TailMap(const Extended FromKey) = 0 ;
};

__interface IJclIntfExtendedSortedMap;
typedef System::DelphiInterface<IJclIntfExtendedSortedMap> _di_IJclIntfExtendedSortedMap;
__interface  INTERFACE_UUID("{3493D6C4-3075-48B6-8E99-CB0000D3978C}") IJclIntfExtendedSortedMap  : public IJclIntfExtendedMap 
{
	
public:
	virtual System::_di_IInterface __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclIntfExtendedSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey) = 0 ;
	virtual System::_di_IInterface __fastcall LastKey(void) = 0 ;
	virtual _di_IJclIntfExtendedSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey) = 0 ;
	virtual _di_IJclIntfExtendedSortedMap __fastcall TailMap(const System::_di_IInterface FromKey) = 0 ;
};

__interface IJclExtendedExtendedSortedMap;
typedef System::DelphiInterface<IJclExtendedExtendedSortedMap> _di_IJclExtendedExtendedSortedMap;
__interface  INTERFACE_UUID("{8CAA505C-D9BB-47E7-92EC-6043DC4AF42C}") IJclExtendedExtendedSortedMap  : public IJclExtendedExtendedMap 
{
	
public:
	virtual Extended __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclExtendedExtendedSortedMap __fastcall HeadMap(const Extended ToKey) = 0 ;
	virtual Extended __fastcall LastKey(void) = 0 ;
	virtual _di_IJclExtendedExtendedSortedMap __fastcall SubMap(const Extended FromKey, const Extended ToKey) = 0 ;
	virtual _di_IJclExtendedExtendedSortedMap __fastcall TailMap(const Extended FromKey) = 0 ;
};

typedef IJclExtendedIntfSortedMap IJclFloatIntfSortedMap;
;

typedef IJclIntfExtendedSortedMap IJclIntfFloatSortedMap;
;

typedef IJclExtendedExtendedSortedMap IJclFloatFloatSortedMap;
;

__interface IJclIntegerIntfSortedMap;
typedef System::DelphiInterface<IJclIntegerIntfSortedMap> _di_IJclIntegerIntfSortedMap;
__interface  INTERFACE_UUID("{8B22802C-61F2-4DA5-B1E9-DBB7840E7996}") IJclIntegerIntfSortedMap  : public IJclIntegerIntfMap 
{
	
public:
	virtual int __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclIntegerIntfSortedMap __fastcall HeadMap(int ToKey) = 0 ;
	virtual int __fastcall LastKey(void) = 0 ;
	virtual _di_IJclIntegerIntfSortedMap __fastcall SubMap(int FromKey, int ToKey) = 0 ;
	virtual _di_IJclIntegerIntfSortedMap __fastcall TailMap(int FromKey) = 0 ;
};

__interface IJclIntfIntegerSortedMap;
typedef System::DelphiInterface<IJclIntfIntegerSortedMap> _di_IJclIntfIntegerSortedMap;
__interface  INTERFACE_UUID("{8D3C9B7E-772D-409B-A58C-0CABFAFDEFF0}") IJclIntfIntegerSortedMap  : public IJclIntfIntegerMap 
{
	
public:
	virtual System::_di_IInterface __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclIntfIntegerSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey) = 0 ;
	virtual System::_di_IInterface __fastcall LastKey(void) = 0 ;
	virtual _di_IJclIntfIntegerSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey) = 0 ;
	virtual _di_IJclIntfIntegerSortedMap __fastcall TailMap(const System::_di_IInterface FromKey) = 0 ;
};

__interface IJclIntegerIntegerSortedMap;
typedef System::DelphiInterface<IJclIntegerIntegerSortedMap> _di_IJclIntegerIntegerSortedMap;
__interface  INTERFACE_UUID("{8A8BA17A-F468-469C-AF99-77D64C802F7A}") IJclIntegerIntegerSortedMap  : public IJclIntegerIntegerMap 
{
	
public:
	virtual int __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclIntegerIntegerSortedMap __fastcall HeadMap(int ToKey) = 0 ;
	virtual int __fastcall LastKey(void) = 0 ;
	virtual _di_IJclIntegerIntegerSortedMap __fastcall SubMap(int FromKey, int ToKey) = 0 ;
	virtual _di_IJclIntegerIntegerSortedMap __fastcall TailMap(int FromKey) = 0 ;
};

__interface IJclCardinalIntfSortedMap;
typedef System::DelphiInterface<IJclCardinalIntfSortedMap> _di_IJclCardinalIntfSortedMap;
__interface  INTERFACE_UUID("{BAE97425-4F2E-461B-88DD-F83D27657AFA}") IJclCardinalIntfSortedMap  : public IJclCardinalIntfMap 
{
	
public:
	virtual unsigned __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclCardinalIntfSortedMap __fastcall HeadMap(unsigned ToKey) = 0 ;
	virtual unsigned __fastcall LastKey(void) = 0 ;
	virtual _di_IJclCardinalIntfSortedMap __fastcall SubMap(unsigned FromKey, unsigned ToKey) = 0 ;
	virtual _di_IJclCardinalIntfSortedMap __fastcall TailMap(unsigned FromKey) = 0 ;
};

__interface IJclIntfCardinalSortedMap;
typedef System::DelphiInterface<IJclIntfCardinalSortedMap> _di_IJclIntfCardinalSortedMap;
__interface  INTERFACE_UUID("{BC66BACF-23AE-48C4-9573-EDC3B5110BE7}") IJclIntfCardinalSortedMap  : public IJclIntfCardinalMap 
{
	
public:
	virtual System::_di_IInterface __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclIntfCardinalSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey) = 0 ;
	virtual System::_di_IInterface __fastcall LastKey(void) = 0 ;
	virtual _di_IJclIntfCardinalSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey) = 0 ;
	virtual _di_IJclIntfCardinalSortedMap __fastcall TailMap(const System::_di_IInterface FromKey) = 0 ;
};

__interface IJclCardinalCardinalSortedMap;
typedef System::DelphiInterface<IJclCardinalCardinalSortedMap> _di_IJclCardinalCardinalSortedMap;
__interface  INTERFACE_UUID("{182ACDA4-7D74-4D29-BB5C-4C8189DA774E}") IJclCardinalCardinalSortedMap  : public IJclCardinalCardinalMap 
{
	
public:
	virtual unsigned __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclCardinalCardinalSortedMap __fastcall HeadMap(unsigned ToKey) = 0 ;
	virtual unsigned __fastcall LastKey(void) = 0 ;
	virtual _di_IJclCardinalCardinalSortedMap __fastcall SubMap(unsigned FromKey, unsigned ToKey) = 0 ;
	virtual _di_IJclCardinalCardinalSortedMap __fastcall TailMap(unsigned FromKey) = 0 ;
};

__interface IJclInt64IntfSortedMap;
typedef System::DelphiInterface<IJclInt64IntfSortedMap> _di_IJclInt64IntfSortedMap;
__interface  INTERFACE_UUID("{24391756-FB02-4901-81E3-A37738B73DAD}") IJclInt64IntfSortedMap  : public IJclInt64IntfMap 
{
	
public:
	virtual __int64 __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclInt64IntfSortedMap __fastcall HeadMap(const __int64 ToKey) = 0 ;
	virtual __int64 __fastcall LastKey(void) = 0 ;
	virtual _di_IJclInt64IntfSortedMap __fastcall SubMap(const __int64 FromKey, const __int64 ToKey) = 0 ;
	virtual _di_IJclInt64IntfSortedMap __fastcall TailMap(const __int64 FromKey) = 0 ;
};

__interface IJclIntfInt64SortedMap;
typedef System::DelphiInterface<IJclIntfInt64SortedMap> _di_IJclIntfInt64SortedMap;
__interface  INTERFACE_UUID("{6E2AB647-59CC-4609-82E8-6AE75AED80CA}") IJclIntfInt64SortedMap  : public IJclIntfInt64Map 
{
	
public:
	virtual System::_di_IInterface __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclIntfInt64SortedMap __fastcall HeadMap(const System::_di_IInterface ToKey) = 0 ;
	virtual System::_di_IInterface __fastcall LastKey(void) = 0 ;
	virtual _di_IJclIntfInt64SortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey) = 0 ;
	virtual _di_IJclIntfInt64SortedMap __fastcall TailMap(const System::_di_IInterface FromKey) = 0 ;
};

__interface IJclInt64Int64SortedMap;
typedef System::DelphiInterface<IJclInt64Int64SortedMap> _di_IJclInt64Int64SortedMap;
__interface  INTERFACE_UUID("{168581D2-9DD3-46D0-934E-EA0CCE5E3C0C}") IJclInt64Int64SortedMap  : public IJclInt64Int64Map 
{
	
public:
	virtual __int64 __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclInt64Int64SortedMap __fastcall HeadMap(const __int64 ToKey) = 0 ;
	virtual __int64 __fastcall LastKey(void) = 0 ;
	virtual _di_IJclInt64Int64SortedMap __fastcall SubMap(const __int64 FromKey, const __int64 ToKey) = 0 ;
	virtual _di_IJclInt64Int64SortedMap __fastcall TailMap(const __int64 FromKey) = 0 ;
};

__interface IJclPtrIntfSortedMap;
typedef System::DelphiInterface<IJclPtrIntfSortedMap> _di_IJclPtrIntfSortedMap;
__interface  INTERFACE_UUID("{6D7B8042-3CBC-4C8F-98B5-69AFAA104532}") IJclPtrIntfSortedMap  : public IJclPtrIntfMap 
{
	
public:
	virtual void * __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclPtrIntfSortedMap __fastcall HeadMap(void * ToKey) = 0 ;
	virtual void * __fastcall LastKey(void) = 0 ;
	virtual _di_IJclPtrIntfSortedMap __fastcall SubMap(void * FromKey, void * ToKey) = 0 ;
	virtual _di_IJclPtrIntfSortedMap __fastcall TailMap(void * FromKey) = 0 ;
};

__interface IJclIntfPtrSortedMap;
typedef System::DelphiInterface<IJclIntfPtrSortedMap> _di_IJclIntfPtrSortedMap;
__interface  INTERFACE_UUID("{B054BDA2-536F-4C16-B6BB-BB64FA0818B3}") IJclIntfPtrSortedMap  : public IJclIntfPtrMap 
{
	
public:
	virtual System::_di_IInterface __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclIntfPtrSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey) = 0 ;
	virtual System::_di_IInterface __fastcall LastKey(void) = 0 ;
	virtual _di_IJclIntfPtrSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey) = 0 ;
	virtual _di_IJclIntfPtrSortedMap __fastcall TailMap(const System::_di_IInterface FromKey) = 0 ;
};

__interface IJclPtrPtrSortedMap;
typedef System::DelphiInterface<IJclPtrPtrSortedMap> _di_IJclPtrPtrSortedMap;
__interface  INTERFACE_UUID("{F1FAE922-0212-41D0-BB4E-76A8AB2CAB86}") IJclPtrPtrSortedMap  : public IJclPtrPtrMap 
{
	
public:
	virtual void * __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclPtrPtrSortedMap __fastcall HeadMap(void * ToKey) = 0 ;
	virtual void * __fastcall LastKey(void) = 0 ;
	virtual _di_IJclPtrPtrSortedMap __fastcall SubMap(void * FromKey, void * ToKey) = 0 ;
	virtual _di_IJclPtrPtrSortedMap __fastcall TailMap(void * FromKey) = 0 ;
};

__interface IJclIntfSortedMap;
typedef System::DelphiInterface<IJclIntfSortedMap> _di_IJclIntfSortedMap;
__interface  INTERFACE_UUID("{3CED1477-B958-4109-9BDA-7C84B9E063B2}") IJclIntfSortedMap  : public IJclIntfMap 
{
	
public:
	virtual System::_di_IInterface __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclIntfSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey) = 0 ;
	virtual System::_di_IInterface __fastcall LastKey(void) = 0 ;
	virtual _di_IJclIntfSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey) = 0 ;
	virtual _di_IJclIntfSortedMap __fastcall TailMap(const System::_di_IInterface FromKey) = 0 ;
};

__interface IJclAnsiStrSortedMap;
typedef System::DelphiInterface<IJclAnsiStrSortedMap> _di_IJclAnsiStrSortedMap;
__interface  INTERFACE_UUID("{573F98E3-EBCD-4F28-8F35-96A7366CBF47}") IJclAnsiStrSortedMap  : public IJclAnsiStrMap 
{
	
public:
	virtual AnsiString __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclAnsiStrSortedMap __fastcall HeadMap(const AnsiString ToKey) = 0 ;
	virtual AnsiString __fastcall LastKey(void) = 0 ;
	virtual _di_IJclAnsiStrSortedMap __fastcall SubMap(const AnsiString FromKey, const AnsiString ToKey) = 0 ;
	virtual _di_IJclAnsiStrSortedMap __fastcall TailMap(const AnsiString FromKey) = 0 ;
};

__interface IJclWideStrSortedMap;
typedef System::DelphiInterface<IJclWideStrSortedMap> _di_IJclWideStrSortedMap;
__interface  INTERFACE_UUID("{B3021EFC-DE25-4B4B-A896-ACE823CD5C01}") IJclWideStrSortedMap  : public IJclWideStrMap 
{
	
public:
	virtual WideString __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclWideStrSortedMap __fastcall HeadMap(const WideString ToKey) = 0 ;
	virtual WideString __fastcall LastKey(void) = 0 ;
	virtual _di_IJclWideStrSortedMap __fastcall SubMap(const WideString FromKey, const WideString ToKey) = 0 ;
	virtual _di_IJclWideStrSortedMap __fastcall TailMap(const WideString FromKey) = 0 ;
};

typedef IJclAnsiStrSortedMap IJclStrSortedMap;
;

__interface IJclSingleSortedMap;
typedef System::DelphiInterface<IJclSingleSortedMap> _di_IJclSingleSortedMap;
__interface  INTERFACE_UUID("{8C1A12BE-A7F2-4351-90B7-25DB0AAF5F94}") IJclSingleSortedMap  : public IJclSingleMap 
{
	
public:
	virtual float __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclSingleSortedMap __fastcall HeadMap(const float ToKey) = 0 ;
	virtual float __fastcall LastKey(void) = 0 ;
	virtual _di_IJclSingleSortedMap __fastcall SubMap(const float FromKey, const float ToKey) = 0 ;
	virtual _di_IJclSingleSortedMap __fastcall TailMap(const float FromKey) = 0 ;
};

__interface IJclDoubleSortedMap;
typedef System::DelphiInterface<IJclDoubleSortedMap> _di_IJclDoubleSortedMap;
__interface  INTERFACE_UUID("{8018D66B-AA54-4016-84FC-3E780FFCC38B}") IJclDoubleSortedMap  : public IJclDoubleMap 
{
	
public:
	virtual double __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclDoubleSortedMap __fastcall HeadMap(const double ToKey) = 0 ;
	virtual double __fastcall LastKey(void) = 0 ;
	virtual _di_IJclDoubleSortedMap __fastcall SubMap(const double FromKey, const double ToKey) = 0 ;
	virtual _di_IJclDoubleSortedMap __fastcall TailMap(const double FromKey) = 0 ;
};

__interface IJclExtendedSortedMap;
typedef System::DelphiInterface<IJclExtendedSortedMap> _di_IJclExtendedSortedMap;
__interface  INTERFACE_UUID("{2B82C65A-B3EF-477D-BEC0-3D8620A226B1}") IJclExtendedSortedMap  : public IJclExtendedMap 
{
	
public:
	virtual Extended __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclExtendedSortedMap __fastcall HeadMap(const Extended ToKey) = 0 ;
	virtual Extended __fastcall LastKey(void) = 0 ;
	virtual _di_IJclExtendedSortedMap __fastcall SubMap(const Extended FromKey, const Extended ToKey) = 0 ;
	virtual _di_IJclExtendedSortedMap __fastcall TailMap(const Extended FromKey) = 0 ;
};

typedef IJclExtendedSortedMap IJclFloatSortedMap;
;

__interface IJclIntegerSortedMap;
typedef System::DelphiInterface<IJclIntegerSortedMap> _di_IJclIntegerSortedMap;
__interface  INTERFACE_UUID("{DD7B4C5E-6D51-44CC-9328-B38396A7E1C9}") IJclIntegerSortedMap  : public IJclIntegerMap 
{
	
public:
	virtual int __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclIntegerSortedMap __fastcall HeadMap(int ToKey) = 0 ;
	virtual int __fastcall LastKey(void) = 0 ;
	virtual _di_IJclIntegerSortedMap __fastcall SubMap(int FromKey, int ToKey) = 0 ;
	virtual _di_IJclIntegerSortedMap __fastcall TailMap(int FromKey) = 0 ;
};

__interface IJclCardinalSortedMap;
typedef System::DelphiInterface<IJclCardinalSortedMap> _di_IJclCardinalSortedMap;
__interface  INTERFACE_UUID("{4AEAF81F-D72E-4499-B10E-3D017F39915E}") IJclCardinalSortedMap  : public IJclCardinalMap 
{
	
public:
	virtual unsigned __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclCardinalSortedMap __fastcall HeadMap(unsigned ToKey) = 0 ;
	virtual unsigned __fastcall LastKey(void) = 0 ;
	virtual _di_IJclCardinalSortedMap __fastcall SubMap(unsigned FromKey, unsigned ToKey) = 0 ;
	virtual _di_IJclCardinalSortedMap __fastcall TailMap(unsigned FromKey) = 0 ;
};

__interface IJclInt64SortedMap;
typedef System::DelphiInterface<IJclInt64SortedMap> _di_IJclInt64SortedMap;
__interface  INTERFACE_UUID("{06C03F90-7DE9-4043-AA56-AAE071D8BD50}") IJclInt64SortedMap  : public IJclInt64Map 
{
	
public:
	virtual __int64 __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclInt64SortedMap __fastcall HeadMap(const __int64 ToKey) = 0 ;
	virtual __int64 __fastcall LastKey(void) = 0 ;
	virtual _di_IJclInt64SortedMap __fastcall SubMap(const __int64 FromKey, const __int64 ToKey) = 0 ;
	virtual _di_IJclInt64SortedMap __fastcall TailMap(const __int64 FromKey) = 0 ;
};

__interface IJclPtrSortedMap;
typedef System::DelphiInterface<IJclPtrSortedMap> _di_IJclPtrSortedMap;
__interface  INTERFACE_UUID("{578918DB-6A4A-4A9D-B44E-AE3E8FF70818}") IJclPtrSortedMap  : public IJclPtrMap 
{
	
public:
	virtual void * __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclPtrSortedMap __fastcall HeadMap(void * ToKey) = 0 ;
	virtual void * __fastcall LastKey(void) = 0 ;
	virtual _di_IJclPtrSortedMap __fastcall SubMap(void * FromKey, void * ToKey) = 0 ;
	virtual _di_IJclPtrSortedMap __fastcall TailMap(void * FromKey) = 0 ;
};

__interface IJclSortedMap;
typedef System::DelphiInterface<IJclSortedMap> _di_IJclSortedMap;
__interface  INTERFACE_UUID("{F317A70F-7851-49C2-9DCF-092D8F4D4F98}") IJclSortedMap  : public IJclMap 
{
	
public:
	virtual System::TObject* __fastcall FirstKey(void) = 0 ;
	virtual _di_IJclSortedMap __fastcall HeadMap(System::TObject* ToKey) = 0 ;
	virtual System::TObject* __fastcall LastKey(void) = 0 ;
	virtual _di_IJclSortedMap __fastcall SubMap(System::TObject* FromKey, System::TObject* ToKey) = 0 ;
	virtual _di_IJclSortedMap __fastcall TailMap(System::TObject* FromKey) = 0 ;
};

__interface IJclIntfSortedSet;
typedef System::DelphiInterface<IJclIntfSortedSet> _di_IJclIntfSortedSet;
__interface  INTERFACE_UUID("{159BE5A7-7349-42FF-BE55-9CA1B9DBA991}") IJclIntfSortedSet  : public IJclIntfSet 
{
	
public:
	virtual _di_IJclIntfSortedSet __fastcall HeadSet(const System::_di_IInterface Finish) = 0 ;
	virtual _di_IJclIntfSortedSet __fastcall SubSet(const System::_di_IInterface Start, const System::_di_IInterface Finish) = 0 ;
	virtual _di_IJclIntfSortedSet __fastcall TailSet(const System::_di_IInterface Start) = 0 ;
};

__interface IJclAnsiStrSortedSet;
typedef System::DelphiInterface<IJclAnsiStrSortedSet> _di_IJclAnsiStrSortedSet;
__interface  INTERFACE_UUID("{03198146-F967-4310-868B-7AD3D52D5CBE}") IJclAnsiStrSortedSet  : public IJclAnsiStrSet 
{
	
public:
	virtual _di_IJclAnsiStrSortedSet __fastcall HeadSet(const AnsiString Finish) = 0 ;
	virtual _di_IJclAnsiStrSortedSet __fastcall SubSet(const AnsiString Start, const AnsiString Finish) = 0 ;
	virtual _di_IJclAnsiStrSortedSet __fastcall TailSet(const AnsiString Start) = 0 ;
};

__interface IJclWideStrSortedSet;
typedef System::DelphiInterface<IJclWideStrSortedSet> _di_IJclWideStrSortedSet;
__interface  INTERFACE_UUID("{ED9567E2-C1D3-4C00-A1D4-90D5C7E27C2D}") IJclWideStrSortedSet  : public IJclWideStrSet 
{
	
public:
	virtual _di_IJclWideStrSortedSet __fastcall HeadSet(const WideString Finish) = 0 ;
	virtual _di_IJclWideStrSortedSet __fastcall SubSet(const WideString Start, const WideString Finish) = 0 ;
	virtual _di_IJclWideStrSortedSet __fastcall TailSet(const WideString Start) = 0 ;
};

typedef IJclAnsiStrSortedSet IJclStrSortedSet;
;

__interface IJclSingleSortedSet;
typedef System::DelphiInterface<IJclSingleSortedSet> _di_IJclSingleSortedSet;
__interface  INTERFACE_UUID("{65EDA801-9E04-4119-BF9E-D7DD4AF82144}") IJclSingleSortedSet  : public IJclSingleSet 
{
	
public:
	virtual _di_IJclSingleSortedSet __fastcall HeadSet(const float Finish) = 0 ;
	virtual _di_IJclSingleSortedSet __fastcall SubSet(const float Start, const float Finish) = 0 ;
	virtual _di_IJclSingleSortedSet __fastcall TailSet(const float Start) = 0 ;
};

__interface IJclDoubleSortedSet;
typedef System::DelphiInterface<IJclDoubleSortedSet> _di_IJclDoubleSortedSet;
__interface  INTERFACE_UUID("{DA0E689F-BAFE-4BCE-85E4-C38E780BC84C}") IJclDoubleSortedSet  : public IJclDoubleSet 
{
	
public:
	virtual _di_IJclDoubleSortedSet __fastcall HeadSet(const double Finish) = 0 ;
	virtual _di_IJclDoubleSortedSet __fastcall SubSet(const double Start, const double Finish) = 0 ;
	virtual _di_IJclDoubleSortedSet __fastcall TailSet(const double Start) = 0 ;
};

__interface IJclExtendedSortedSet;
typedef System::DelphiInterface<IJclExtendedSortedSet> _di_IJclExtendedSortedSet;
__interface  INTERFACE_UUID("{A9875ED3-81A4-43A3-86BB-3429F51B278B}") IJclExtendedSortedSet  : public IJclExtendedSet 
{
	
public:
	virtual _di_IJclExtendedSortedSet __fastcall HeadSet(const Extended Finish) = 0 ;
	virtual _di_IJclExtendedSortedSet __fastcall SubSet(const Extended Start, const Extended Finish) = 0 ;
	virtual _di_IJclExtendedSortedSet __fastcall TailSet(const Extended Start) = 0 ;
};

typedef IJclExtendedSortedSet IJclFloatSortedSet;
;

__interface IJclIntegerSortedSet;
typedef System::DelphiInterface<IJclIntegerSortedSet> _di_IJclIntegerSortedSet;
__interface  INTERFACE_UUID("{E086C54B-4FA3-426D-AC4E-FF8E8CA3D663}") IJclIntegerSortedSet  : public IJclIntegerSet 
{
	
public:
	virtual _di_IJclIntegerSortedSet __fastcall HeadSet(int Finish) = 0 ;
	virtual _di_IJclIntegerSortedSet __fastcall SubSet(int Start, int Finish) = 0 ;
	virtual _di_IJclIntegerSortedSet __fastcall TailSet(int Start) = 0 ;
};

__interface IJclCardinalSortedSet;
typedef System::DelphiInterface<IJclCardinalSortedSet> _di_IJclCardinalSortedSet;
__interface  INTERFACE_UUID("{2D7995C6-A784-48B6-87E9-55D394A72362}") IJclCardinalSortedSet  : public IJclCardinalSet 
{
	
public:
	virtual _di_IJclCardinalSortedSet __fastcall HeadSet(unsigned Finish) = 0 ;
	virtual _di_IJclCardinalSortedSet __fastcall SubSet(unsigned Start, unsigned Finish) = 0 ;
	virtual _di_IJclCardinalSortedSet __fastcall TailSet(unsigned Start) = 0 ;
};

__interface IJclInt64SortedSet;
typedef System::DelphiInterface<IJclInt64SortedSet> _di_IJclInt64SortedSet;
__interface  INTERFACE_UUID("{4C1C3FCA-6169-4A2F-B044-91AC2AA2E954}") IJclInt64SortedSet  : public IJclInt64Set 
{
	
public:
	virtual _di_IJclInt64SortedSet __fastcall HeadSet(const __int64 Finish) = 0 ;
	virtual _di_IJclInt64SortedSet __fastcall SubSet(const __int64 Start, const __int64 Finish) = 0 ;
	virtual _di_IJclInt64SortedSet __fastcall TailSet(const __int64 Start) = 0 ;
};

__interface IJclPtrSortedSet;
typedef System::DelphiInterface<IJclPtrSortedSet> _di_IJclPtrSortedSet;
__interface  INTERFACE_UUID("{F3A3183C-0820-425C-9446-E0838F0ADAD8}") IJclPtrSortedSet  : public IJclPtrSet 
{
	
public:
	virtual _di_IJclPtrSortedSet __fastcall HeadSet(void * Finish) = 0 ;
	virtual _di_IJclPtrSortedSet __fastcall SubSet(void * Start, void * Finish) = 0 ;
	virtual _di_IJclPtrSortedSet __fastcall TailSet(void * Start) = 0 ;
};

__interface IJclSortedSet;
typedef System::DelphiInterface<IJclSortedSet> _di_IJclSortedSet;
__interface  INTERFACE_UUID("{A3D23E76-ADE9-446C-9B97-F49FCE895D9F}") IJclSortedSet  : public IJclSet 
{
	
public:
	virtual _di_IJclSortedSet __fastcall HeadSet(System::TObject* Finish) = 0 ;
	virtual _di_IJclSortedSet __fastcall SubSet(System::TObject* Start, System::TObject* Finish) = 0 ;
	virtual _di_IJclSortedSet __fastcall TailSet(System::TObject* Start) = 0 ;
};

__interface IJclIntfStack;
typedef System::DelphiInterface<IJclIntfStack> _di_IJclIntfStack;
__interface  INTERFACE_UUID("{CA1DC7A1-8D8F-4A5D-81D1-0FE32E9A4E84}") IJclIntfStack  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const System::_di_IInterface AInterface) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual System::_di_IInterface __fastcall Peek(void) = 0 ;
	virtual System::_di_IInterface __fastcall Pop(void) = 0 ;
	virtual bool __fastcall Push(const System::_di_IInterface AInterface) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

__interface IJclAnsiStrStack;
typedef System::DelphiInterface<IJclAnsiStrStack> _di_IJclAnsiStrStack;
__interface  INTERFACE_UUID("{649BB74C-D7BE-40D9-9F4E-32DDC3F13F3B}") IJclAnsiStrStack  : public IJclAnsiStrContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const AnsiString AString) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual AnsiString __fastcall Peek(void) = 0 ;
	virtual AnsiString __fastcall Pop(void) = 0 ;
	virtual bool __fastcall Push(const AnsiString AString) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

__interface IJclWideStrStack;
typedef System::DelphiInterface<IJclWideStrStack> _di_IJclWideStrStack;
__interface  INTERFACE_UUID("{B2C3B165-33F1-4B7D-A2EC-0B19D12CE33C}") IJclWideStrStack  : public IJclWideStrContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const WideString AString) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual WideString __fastcall Peek(void) = 0 ;
	virtual WideString __fastcall Pop(void) = 0 ;
	virtual bool __fastcall Push(const WideString AString) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

typedef IJclAnsiStrStack IJclStrStack;
;

__interface IJclSingleStack;
typedef System::DelphiInterface<IJclSingleStack> _di_IJclSingleStack;
__interface  INTERFACE_UUID("{8DCE45C8-B5B3-43AB-BA08-DAD531CEB9CF}") IJclSingleStack  : public IJclSingleContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const float AValue) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual float __fastcall Peek(void) = 0 ;
	virtual float __fastcall Pop(void) = 0 ;
	virtual bool __fastcall Push(const float AValue) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

__interface IJclDoubleStack;
typedef System::DelphiInterface<IJclDoubleStack> _di_IJclDoubleStack;
__interface  INTERFACE_UUID("{46DF2701-16F0-453C-B938-F04E9C1CEBF8}") IJclDoubleStack  : public IJclDoubleContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const double AValue) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual double __fastcall Peek(void) = 0 ;
	virtual double __fastcall Pop(void) = 0 ;
	virtual bool __fastcall Push(const double AValue) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

__interface IJclExtendedStack;
typedef System::DelphiInterface<IJclExtendedStack> _di_IJclExtendedStack;
__interface  INTERFACE_UUID("{A2A30585-F561-4757-ABE1-CA511AE72CC5}") IJclExtendedStack  : public IJclExtendedContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const Extended AValue) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual Extended __fastcall Peek(void) = 0 ;
	virtual Extended __fastcall Pop(void) = 0 ;
	virtual bool __fastcall Push(const Extended AValue) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

typedef IJclExtendedStack IJclFloatStack;
;

__interface IJclIntegerStack;
typedef System::DelphiInterface<IJclIntegerStack> _di_IJclIntegerStack;
__interface  INTERFACE_UUID("{9190BF0E-5B0C-4D6C-A107-20A933C9B56A}") IJclIntegerStack  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(int AValue) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual int __fastcall Peek(void) = 0 ;
	virtual int __fastcall Pop(void) = 0 ;
	virtual bool __fastcall Push(int AValue) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

__interface IJclCardinalStack;
typedef System::DelphiInterface<IJclCardinalStack> _di_IJclCardinalStack;
__interface  INTERFACE_UUID("{94F9EDB3-602B-49CE-9990-0AFDAC556F83}") IJclCardinalStack  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(unsigned AValue) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual unsigned __fastcall Peek(void) = 0 ;
	virtual unsigned __fastcall Pop(void) = 0 ;
	virtual bool __fastcall Push(unsigned AValue) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

__interface IJclInt64Stack;
typedef System::DelphiInterface<IJclInt64Stack> _di_IJclInt64Stack;
__interface  INTERFACE_UUID("{D689EB8F-2746-40E9-AD1B-7E656475FC64}") IJclInt64Stack  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const __int64 AValue) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual __int64 __fastcall Peek(void) = 0 ;
	virtual __int64 __fastcall Pop(void) = 0 ;
	virtual bool __fastcall Push(const __int64 AValue) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

__interface IJclPtrStack;
typedef System::DelphiInterface<IJclPtrStack> _di_IJclPtrStack;
__interface  INTERFACE_UUID("{AD11D06C-E0E1-4EDE-AA2F-BC8BDD972B73}") IJclPtrStack  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(void * APtr) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual void * __fastcall Peek(void) = 0 ;
	virtual void * __fastcall Pop(void) = 0 ;
	virtual bool __fastcall Push(void * APtr) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

__interface IJclStack;
typedef System::DelphiInterface<IJclStack> _di_IJclStack;
__interface  INTERFACE_UUID("{E07E0BD8-A831-41B9-B9A0-7199BD4873B9}") IJclStack  : public IJclContainer 
{
	
public:
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(System::TObject* AObject) = 0 ;
	virtual bool __fastcall Empty(void) = 0 ;
	virtual System::TObject* __fastcall Peek(void) = 0 ;
	virtual System::TObject* __fastcall Pop(void) = 0 ;
	virtual bool __fastcall Push(System::TObject* AObject) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
};

class DELPHICLASS EJclContainerError;
class PASCALIMPLEMENTATION EJclContainerError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclContainerError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclContainerError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclContainerError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclContainerError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclContainerError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclContainerError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclContainerError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclContainerError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclContainerError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclOutOfBoundsError;
class PASCALIMPLEMENTATION EJclOutOfBoundsError : public EJclContainerError 
{
	typedef EJclContainerError inherited;
	
public:
	__fastcall EJclOutOfBoundsError(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclOutOfBoundsError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclContainerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclOutOfBoundsError(int Ident)/* overload */ : EJclContainerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclOutOfBoundsError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclContainerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclOutOfBoundsError(const AnsiString Msg, int AHelpContext) : EJclContainerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclOutOfBoundsError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclContainerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclOutOfBoundsError(int Ident, int AHelpContext)/* overload */ : EJclContainerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclOutOfBoundsError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclContainerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclOutOfBoundsError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclNoSuchElementError;
class PASCALIMPLEMENTATION EJclNoSuchElementError : public EJclContainerError 
{
	typedef EJclContainerError inherited;
	
public:
	__fastcall EJclNoSuchElementError(const AnsiString Value);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclNoSuchElementError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclContainerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclNoSuchElementError(int Ident)/* overload */ : EJclContainerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclNoSuchElementError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclContainerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclNoSuchElementError(const AnsiString Msg, int AHelpContext) : EJclContainerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclNoSuchElementError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclContainerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclNoSuchElementError(int Ident, int AHelpContext)/* overload */ : EJclContainerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclNoSuchElementError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclContainerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclNoSuchElementError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclDuplicateElementError;
class PASCALIMPLEMENTATION EJclDuplicateElementError : public EJclContainerError 
{
	typedef EJclContainerError inherited;
	
public:
	__fastcall EJclDuplicateElementError(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclDuplicateElementError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclContainerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclDuplicateElementError(int Ident)/* overload */ : EJclContainerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclDuplicateElementError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclContainerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclDuplicateElementError(const AnsiString Msg, int AHelpContext) : EJclContainerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclDuplicateElementError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclContainerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclDuplicateElementError(int Ident, int AHelpContext)/* overload */ : EJclContainerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclDuplicateElementError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclContainerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclDuplicateElementError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclIllegalArgumentError;
class PASCALIMPLEMENTATION EJclIllegalArgumentError : public EJclContainerError 
{
	typedef EJclContainerError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclIllegalArgumentError(const AnsiString Msg) : EJclContainerError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclIllegalArgumentError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclContainerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclIllegalArgumentError(int Ident)/* overload */ : EJclContainerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclIllegalArgumentError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclContainerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclIllegalArgumentError(const AnsiString Msg, int AHelpContext) : EJclContainerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclIllegalArgumentError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclContainerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclIllegalArgumentError(int Ident, int AHelpContext)/* overload */ : EJclContainerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclIllegalArgumentError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclContainerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclIllegalArgumentError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclNoCollectionError;
class PASCALIMPLEMENTATION EJclNoCollectionError : public EJclIllegalArgumentError 
{
	typedef EJclIllegalArgumentError inherited;
	
public:
	__fastcall EJclNoCollectionError(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclNoCollectionError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclIllegalArgumentError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclNoCollectionError(int Ident)/* overload */ : EJclIllegalArgumentError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclNoCollectionError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclIllegalArgumentError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclNoCollectionError(const AnsiString Msg, int AHelpContext) : EJclIllegalArgumentError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclNoCollectionError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclIllegalArgumentError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclNoCollectionError(int Ident, int AHelpContext)/* overload */ : EJclIllegalArgumentError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclNoCollectionError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclIllegalArgumentError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclNoCollectionError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclIllegalQueueCapacityError;
class PASCALIMPLEMENTATION EJclIllegalQueueCapacityError : public EJclIllegalArgumentError 
{
	typedef EJclIllegalArgumentError inherited;
	
public:
	__fastcall EJclIllegalQueueCapacityError(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclIllegalQueueCapacityError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclIllegalArgumentError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclIllegalQueueCapacityError(int Ident)/* overload */ : EJclIllegalArgumentError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclIllegalQueueCapacityError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclIllegalArgumentError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclIllegalQueueCapacityError(const AnsiString Msg, int AHelpContext) : EJclIllegalArgumentError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclIllegalQueueCapacityError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclIllegalArgumentError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclIllegalQueueCapacityError(int Ident, int AHelpContext)/* overload */ : EJclIllegalArgumentError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclIllegalQueueCapacityError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclIllegalArgumentError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclIllegalQueueCapacityError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclOperationNotSupportedError;
class PASCALIMPLEMENTATION EJclOperationNotSupportedError : public EJclContainerError 
{
	typedef EJclContainerError inherited;
	
public:
	__fastcall EJclOperationNotSupportedError(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclOperationNotSupportedError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclContainerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclOperationNotSupportedError(int Ident)/* overload */ : EJclContainerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclOperationNotSupportedError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclContainerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclOperationNotSupportedError(const AnsiString Msg, int AHelpContext) : EJclContainerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclOperationNotSupportedError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclContainerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclOperationNotSupportedError(int Ident, int AHelpContext)/* overload */ : EJclContainerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclOperationNotSupportedError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclContainerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclOperationNotSupportedError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclNoEqualityComparerError;
class PASCALIMPLEMENTATION EJclNoEqualityComparerError : public EJclContainerError 
{
	typedef EJclContainerError inherited;
	
public:
	__fastcall EJclNoEqualityComparerError(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclNoEqualityComparerError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclContainerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclNoEqualityComparerError(int Ident)/* overload */ : EJclContainerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclNoEqualityComparerError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclContainerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclNoEqualityComparerError(const AnsiString Msg, int AHelpContext) : EJclContainerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclNoEqualityComparerError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclContainerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclNoEqualityComparerError(int Ident, int AHelpContext)/* overload */ : EJclContainerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclNoEqualityComparerError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclContainerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclNoEqualityComparerError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclNoComparerError;
class PASCALIMPLEMENTATION EJclNoComparerError : public EJclContainerError 
{
	typedef EJclContainerError inherited;
	
public:
	__fastcall EJclNoComparerError(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclNoComparerError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclContainerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclNoComparerError(int Ident)/* overload */ : EJclContainerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclNoComparerError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclContainerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclNoComparerError(const AnsiString Msg, int AHelpContext) : EJclContainerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclNoComparerError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclContainerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclNoComparerError(int Ident, int AHelpContext)/* overload */ : EJclContainerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclNoComparerError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclContainerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclNoComparerError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclNoHashConverterError;
class PASCALIMPLEMENTATION EJclNoHashConverterError : public EJclContainerError 
{
	typedef EJclContainerError inherited;
	
public:
	__fastcall EJclNoHashConverterError(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclNoHashConverterError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclContainerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclNoHashConverterError(int Ident)/* overload */ : EJclContainerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclNoHashConverterError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclContainerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclNoHashConverterError(const AnsiString Msg, int AHelpContext) : EJclContainerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclNoHashConverterError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclContainerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclNoHashConverterError(int Ident, int AHelpContext)/* overload */ : EJclContainerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclNoHashConverterError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclContainerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclNoHashConverterError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclIllegalStateOperationError;
class PASCALIMPLEMENTATION EJclIllegalStateOperationError : public EJclContainerError 
{
	typedef EJclContainerError inherited;
	
public:
	__fastcall EJclIllegalStateOperationError(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclIllegalStateOperationError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclContainerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclIllegalStateOperationError(int Ident)/* overload */ : EJclContainerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclIllegalStateOperationError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclContainerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclIllegalStateOperationError(const AnsiString Msg, int AHelpContext) : EJclContainerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclIllegalStateOperationError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclContainerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclIllegalStateOperationError(int Ident, int AHelpContext)/* overload */ : EJclContainerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclIllegalStateOperationError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclContainerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclIllegalStateOperationError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclAssignError;
class PASCALIMPLEMENTATION EJclAssignError : public EJclContainerError 
{
	typedef EJclContainerError inherited;
	
public:
	__fastcall EJclAssignError(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclAssignError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclContainerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclAssignError(int Ident)/* overload */ : EJclContainerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclAssignError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclContainerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclAssignError(const AnsiString Msg, int AHelpContext) : EJclContainerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclAssignError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclContainerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclAssignError(int Ident, int AHelpContext)/* overload */ : EJclContainerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclAssignError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclContainerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclAssignError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclReadOnlyError;
class PASCALIMPLEMENTATION EJclReadOnlyError : public EJclContainerError 
{
	typedef EJclContainerError inherited;
	
public:
	__fastcall EJclReadOnlyError(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclReadOnlyError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclContainerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclReadOnlyError(int Ident)/* overload */ : EJclContainerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclReadOnlyError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclContainerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclReadOnlyError(const AnsiString Msg, int AHelpContext) : EJclContainerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclReadOnlyError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclContainerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclReadOnlyError(int Ident, int AHelpContext)/* overload */ : EJclContainerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclReadOnlyError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclContainerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclReadOnlyError(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint DefaultContainerCapacity = 0x10;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jclcontainerintf */
using namespace Jclcontainerintf;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclcontainerintf
