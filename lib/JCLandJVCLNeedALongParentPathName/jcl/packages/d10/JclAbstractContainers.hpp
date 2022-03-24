// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclabstractcontainers.pas' rev: 10.00

#ifndef JclabstractcontainersHPP
#define JclabstractcontainersHPP

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
#include <Jclcontainerintf.hpp>	// Pascal unit
#include <Jclsynch.hpp>	// Pascal unit
#include <Jclsysutils.hpp>	// Pascal unit
#include <Jclwidestrings.hpp>	// Pascal unit
#include <Jclansistrings.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclabstractcontainers
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TJclAbstractLockable;
class PASCALIMPLEMENTATION TJclAbstractLockable : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
protected:
	bool FThreadSafe;
	Jclsynch::TJclMultiReadExclusiveWrite* FSyncReaderWriter;
	
public:
	__fastcall TJclAbstractLockable(void);
	__fastcall virtual ~TJclAbstractLockable(void);
	__property Jclsynch::TJclMultiReadExclusiveWrite* SyncReaderWriter = {read=FSyncReaderWriter};
	void __fastcall ReadLock(void);
	void __fastcall ReadUnlock(void);
	void __fastcall WriteLock(void);
	void __fastcall WriteUnlock(void);
private:
	void *__IJclLockable;	/* Jclcontainerintf::IJclLockable */
	
public:
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclLockable; }
	
};


class DELPHICLASS TJclAbstractContainerBase;
class PASCALIMPLEMENTATION TJclAbstractContainerBase : public TJclAbstractLockable 
{
	typedef TJclAbstractLockable inherited;
	
protected:
	bool FAllowDefaultElements;
	Classes::TDuplicates FDuplicates;
	bool FRemoveSingleElement;
	bool FReturnDefaultElements;
	bool FReadOnly;
	int FCapacity;
	int FSize;
	int FAutoGrowParameter;
	Jclcontainerintf::TJclAutoGrowStrategy FAutoGrowStrategy;
	int FAutoPackParameter;
	Jclcontainerintf::TJclAutoPackStrategy FAutoPackStrategy;
	virtual void __fastcall AutoGrow(void);
	virtual void __fastcall AutoPack(void);
	bool __fastcall CheckDuplicate(void);
	virtual TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void) = 0 ;
	virtual void __fastcall AssignDataTo(TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclAbstractContainerBase(void);
	void __fastcall Assign(const Jclcontainerintf::_di_IJclContainer Source);
	void __fastcall AssignTo(const Jclcontainerintf::_di_IJclContainer Dest);
	virtual bool __fastcall GetAllowDefaultElements(void);
	System::TObject* __fastcall GetContainerReference(void);
	virtual Classes::TDuplicates __fastcall GetDuplicates(void);
	virtual bool __fastcall GetReadOnly(void);
	virtual bool __fastcall GetRemoveSingleElement(void);
	virtual bool __fastcall GetReturnDefaultElements(void);
	virtual bool __fastcall GetThreadSafe(void);
	virtual void __fastcall SetAllowDefaultElements(bool Value);
	virtual void __fastcall SetDuplicates(Classes::TDuplicates Value);
	virtual void __fastcall SetReadOnly(bool Value);
	virtual void __fastcall SetRemoveSingleElement(bool Value);
	virtual void __fastcall SetReturnDefaultElements(bool Value);
	virtual void __fastcall SetThreadSafe(bool Value);
	__property bool AllowDefaultElements = {read=GetAllowDefaultElements, write=SetAllowDefaultElements, nodefault};
	__property Classes::TDuplicates Duplicates = {read=GetDuplicates, write=SetDuplicates, nodefault};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, nodefault};
	__property bool RemoveSingleElement = {read=GetRemoveSingleElement, write=SetRemoveSingleElement, nodefault};
	__property bool ReturnDefaultElements = {read=GetReturnDefaultElements, write=SetReturnDefaultElements, nodefault};
	__property bool ThreadSafe = {read=GetThreadSafe, write=SetThreadSafe, nodefault};
	System::TObject* __fastcall ObjectClone(void);
	System::_di_IInterface __fastcall IntfClone();
	virtual int __fastcall CalcGrowCapacity(int ACapacity, int ASize);
	virtual int __fastcall GetAutoGrowParameter(void);
	virtual Jclcontainerintf::TJclAutoGrowStrategy __fastcall GetAutoGrowStrategy(void);
	virtual void __fastcall Grow(void);
	virtual void __fastcall SetAutoGrowParameter(int Value);
	virtual void __fastcall SetAutoGrowStrategy(Jclcontainerintf::TJclAutoGrowStrategy Value);
	__property int AutoGrowParameter = {read=GetAutoGrowParameter, write=SetAutoGrowParameter, nodefault};
	__property Jclcontainerintf::TJclAutoGrowStrategy AutoGrowStrategy = {read=GetAutoGrowStrategy, write=SetAutoGrowStrategy, nodefault};
	virtual int __fastcall CalcPackCapacity(int ACapacity, int ASize);
	virtual int __fastcall GetAutoPackParameter(void);
	virtual Jclcontainerintf::TJclAutoPackStrategy __fastcall GetAutoPackStrategy(void);
	virtual int __fastcall GetCapacity(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetAutoPackParameter(int Value);
	virtual void __fastcall SetAutoPackStrategy(Jclcontainerintf::TJclAutoPackStrategy Value);
	virtual void __fastcall SetCapacity(int Value);
	__property int AutoPackParameter = {read=GetAutoPackParameter, write=SetAutoPackParameter, nodefault};
	__property Jclcontainerintf::TJclAutoPackStrategy AutoPackStrategy = {read=GetAutoPackStrategy, write=SetAutoPackStrategy, nodefault};
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclAbstractContainerBase(void) { }
	#pragma option pop
	
private:
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclContainer;	/* Jclcontainerintf::IJclContainer */
	
public:
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclContainer; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclContainer; }
	
};


class DELPHICLASS TJclAbstractIterator;
class PASCALIMPLEMENTATION TJclAbstractIterator : public TJclAbstractLockable 
{
	typedef TJclAbstractLockable inherited;
	
private:
	bool FValid;
	
protected:
	void __fastcall CheckValid(void);
	virtual TJclAbstractIterator* __fastcall CreateEmptyIterator(void) = 0 ;
	virtual void __fastcall AssignPropertiesTo(TJclAbstractIterator* Dest);
	
public:
	__fastcall TJclAbstractIterator(bool AValid);
	__property bool Valid = {read=FValid, write=FValid, nodefault};
	void __fastcall Assign(const Jclcontainerintf::_di_IJclAbstractIterator Source);
	void __fastcall AssignTo(const Jclcontainerintf::_di_IJclAbstractIterator Dest);
	System::TObject* __fastcall GetIteratorReference(void);
	System::TObject* __fastcall ObjectClone(void);
	System::_di_IInterface __fastcall IntfClone();
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclAbstractIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclAbstractIterator;	/* Jclcontainerintf::IJclAbstractIterator */
	
public:
	operator IJclAbstractIterator*(void) { return (IJclAbstractIterator*)&__IJclAbstractIterator; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAbstractIterator; }
	
};


class DELPHICLASS TJclIntfAbstractContainer;
class PASCALIMPLEMENTATION TJclIntfAbstractContainer : public TJclAbstractContainerBase 
{
	typedef TJclAbstractContainerBase inherited;
	
protected:
	Jclcontainerintf::TIntfEqualityCompare FEqualityCompare;
	Jclcontainerintf::TIntfCompare FCompare;
	Jclcontainerintf::TIntfHashConvert FHashConvert;
	virtual void __fastcall AssignPropertiesTo(TJclAbstractContainerBase* Dest);
	System::_di_IInterface __fastcall FreeObject(System::_di_IInterface &AInterface);
	
public:
	virtual Jclcontainerintf::TIntfEqualityCompare __fastcall GetEqualityCompare(void);
	virtual void __fastcall SetEqualityCompare(Jclcontainerintf::TIntfEqualityCompare Value);
	virtual bool __fastcall ItemsEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	__property Jclcontainerintf::TIntfEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
	virtual Jclcontainerintf::TIntfCompare __fastcall GetCompare(void);
	virtual void __fastcall SetCompare(Jclcontainerintf::TIntfCompare Value);
	virtual int __fastcall ItemsCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	__property Jclcontainerintf::TIntfCompare Compare = {read=GetCompare, write=SetCompare};
	virtual Jclcontainerintf::TIntfHashConvert __fastcall GetHashConvert(void);
	virtual void __fastcall SetHashConvert(Jclcontainerintf::TIntfHashConvert Value);
	virtual int __fastcall Hash(const System::_di_IInterface AInterface);
	__property Jclcontainerintf::TIntfHashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
public:
	#pragma option push -w-inl
	/* TJclAbstractContainerBase.Create */ inline __fastcall TJclIntfAbstractContainer(void) : TJclAbstractContainerBase() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclIntfAbstractContainer(void) { }
	#pragma option pop
	
private:
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclContainer;	/* Jclcontainerintf::IJclContainer */
	void *__IJclIntfEqualityComparer;	/* Jclcontainerintf::IJclIntfEqualityComparer */
	void *__IJclIntfComparer;	/* Jclcontainerintf::IJclIntfComparer */
	void *__IJclIntfHashConverter;	/* Jclcontainerintf::IJclIntfHashConverter */
	
public:
	operator IJclIntfHashConverter*(void) { return (IJclIntfHashConverter*)&__IJclIntfHashConverter; }
	operator IJclIntfComparer*(void) { return (IJclIntfComparer*)&__IJclIntfComparer; }
	operator IJclIntfEqualityComparer*(void) { return (IJclIntfEqualityComparer*)&__IJclIntfEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclContainer; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclContainer; }
	
};


class DELPHICLASS TJclStrAbstractContainer;
class PASCALIMPLEMENTATION TJclStrAbstractContainer : public TJclAbstractContainerBase 
{
	typedef TJclAbstractContainerBase inherited;
	
protected:
	bool FCaseSensitive;
	virtual void __fastcall AssignPropertiesTo(TJclAbstractContainerBase* Dest);
	
public:
	virtual bool __fastcall GetCaseSensitive(void);
	virtual void __fastcall SetCaseSensitive(bool Value);
	__property bool CaseSensitive = {read=GetCaseSensitive, write=SetCaseSensitive, nodefault};
public:
	#pragma option push -w-inl
	/* TJclAbstractContainerBase.Create */ inline __fastcall TJclStrAbstractContainer(void) : TJclAbstractContainerBase() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclStrAbstractContainer(void) { }
	#pragma option pop
	
private:
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclStrContainer;	/* Jclcontainerintf::IJclStrContainer */
	
public:
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclStrContainer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclStrContainer; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclStrContainer; }
	
};


class DELPHICLASS TJclAnsiStrAbstractContainer;
class PASCALIMPLEMENTATION TJclAnsiStrAbstractContainer : public TJclStrAbstractContainer 
{
	typedef TJclStrAbstractContainer inherited;
	
protected:
	Jclcontainerintf::TJclAnsiStrEncoding FEncoding;
	Jclcontainerintf::TAnsiStrEqualityCompare FEqualityCompare;
	Jclcontainerintf::TAnsiStrCompare FCompare;
	Jclcontainerintf::TAnsiStrHashConvert FHashConvert;
	virtual void __fastcall AssignPropertiesTo(TJclAbstractContainerBase* Dest);
	AnsiString __fastcall FreeString(AnsiString &AString);
	
public:
	virtual Jclcontainerintf::TJclAnsiStrEncoding __fastcall GetEncoding(void);
	virtual void __fastcall SetEncoding(Jclcontainerintf::TJclAnsiStrEncoding Value);
	__property Jclcontainerintf::TJclAnsiStrEncoding Encoding = {read=GetEncoding, write=SetEncoding, nodefault};
	virtual Jclcontainerintf::TAnsiStrEqualityCompare __fastcall GetEqualityCompare(void);
	virtual void __fastcall SetEqualityCompare(Jclcontainerintf::TAnsiStrEqualityCompare Value);
	virtual bool __fastcall ItemsEqual(const AnsiString A, const AnsiString B);
	__property Jclcontainerintf::TAnsiStrEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
	virtual Jclcontainerintf::TAnsiStrCompare __fastcall GetCompare(void);
	virtual void __fastcall SetCompare(Jclcontainerintf::TAnsiStrCompare Value);
	virtual int __fastcall ItemsCompare(const AnsiString A, const AnsiString B);
	__property Jclcontainerintf::TAnsiStrCompare Compare = {read=GetCompare, write=SetCompare};
	virtual Jclcontainerintf::TAnsiStrHashConvert __fastcall GetHashConvert(void);
	virtual void __fastcall SetHashConvert(Jclcontainerintf::TAnsiStrHashConvert Value);
	virtual int __fastcall Hash(const AnsiString AString);
	__property Jclcontainerintf::TAnsiStrHashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
public:
	#pragma option push -w-inl
	/* TJclAbstractContainerBase.Create */ inline __fastcall TJclAnsiStrAbstractContainer(void) : TJclStrAbstractContainer() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclAnsiStrAbstractContainer(void) { }
	#pragma option pop
	
private:
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclAnsiStrContainer;	/* Jclcontainerintf::IJclAnsiStrContainer */
	void *__IJclAnsiStrEqualityComparer;	/* Jclcontainerintf::IJclAnsiStrEqualityComparer */
	void *__IJclAnsiStrComparer;	/* Jclcontainerintf::IJclAnsiStrComparer */
	void *__IJclAnsiStrHashConverter;	/* Jclcontainerintf::IJclAnsiStrHashConverter */
	
public:
	operator IJclAnsiStrHashConverter*(void) { return (IJclAnsiStrHashConverter*)&__IJclAnsiStrHashConverter; }
	operator IJclAnsiStrComparer*(void) { return (IJclAnsiStrComparer*)&__IJclAnsiStrComparer; }
	operator IJclAnsiStrEqualityComparer*(void) { return (IJclAnsiStrEqualityComparer*)&__IJclAnsiStrEqualityComparer; }
	operator IJclAnsiStrContainer*(void) { return (IJclAnsiStrContainer*)&__IJclAnsiStrContainer; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclAnsiStrContainer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclAnsiStrContainer; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrContainer; }
	
};


class DELPHICLASS TJclWideStrAbstractContainer;
class PASCALIMPLEMENTATION TJclWideStrAbstractContainer : public TJclStrAbstractContainer 
{
	typedef TJclStrAbstractContainer inherited;
	
protected:
	Jclcontainerintf::TJclWideStrEncoding FEncoding;
	Jclcontainerintf::TWideStrEqualityCompare FEqualityCompare;
	Jclcontainerintf::TWideStrCompare FCompare;
	Jclcontainerintf::TWideStrHashConvert FHashConvert;
	virtual void __fastcall AssignPropertiesTo(TJclAbstractContainerBase* Dest);
	WideString __fastcall FreeString(WideString &AString);
	
public:
	virtual Jclcontainerintf::TJclWideStrEncoding __fastcall GetEncoding(void);
	virtual void __fastcall SetEncoding(Jclcontainerintf::TJclWideStrEncoding Value);
	__property Jclcontainerintf::TJclWideStrEncoding Encoding = {read=GetEncoding, write=SetEncoding, nodefault};
	virtual Jclcontainerintf::TWideStrEqualityCompare __fastcall GetEqualityCompare(void);
	virtual void __fastcall SetEqualityCompare(Jclcontainerintf::TWideStrEqualityCompare Value);
	virtual bool __fastcall ItemsEqual(const WideString A, const WideString B);
	__property Jclcontainerintf::TWideStrEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
	virtual Jclcontainerintf::TWideStrCompare __fastcall GetCompare(void);
	virtual void __fastcall SetCompare(Jclcontainerintf::TWideStrCompare Value);
	virtual int __fastcall ItemsCompare(const WideString A, const WideString B);
	__property Jclcontainerintf::TWideStrCompare Compare = {read=GetCompare, write=SetCompare};
	virtual Jclcontainerintf::TWideStrHashConvert __fastcall GetHashConvert(void);
	virtual void __fastcall SetHashConvert(Jclcontainerintf::TWideStrHashConvert Value);
	virtual int __fastcall Hash(const WideString AString);
	__property Jclcontainerintf::TWideStrHashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
public:
	#pragma option push -w-inl
	/* TJclAbstractContainerBase.Create */ inline __fastcall TJclWideStrAbstractContainer(void) : TJclStrAbstractContainer() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclWideStrAbstractContainer(void) { }
	#pragma option pop
	
private:
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclWideStrContainer;	/* Jclcontainerintf::IJclWideStrContainer */
	void *__IJclWideStrEqualityComparer;	/* Jclcontainerintf::IJclWideStrEqualityComparer */
	void *__IJclWideStrComparer;	/* Jclcontainerintf::IJclWideStrComparer */
	void *__IJclWideStrHashConverter;	/* Jclcontainerintf::IJclWideStrHashConverter */
	
public:
	operator IJclWideStrHashConverter*(void) { return (IJclWideStrHashConverter*)&__IJclWideStrHashConverter; }
	operator IJclWideStrComparer*(void) { return (IJclWideStrComparer*)&__IJclWideStrComparer; }
	operator IJclWideStrEqualityComparer*(void) { return (IJclWideStrEqualityComparer*)&__IJclWideStrEqualityComparer; }
	operator IJclWideStrContainer*(void) { return (IJclWideStrContainer*)&__IJclWideStrContainer; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclWideStrContainer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclWideStrContainer; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrContainer; }
	
};


class DELPHICLASS TJclSingleAbstractContainer;
class PASCALIMPLEMENTATION TJclSingleAbstractContainer : public TJclAbstractContainerBase 
{
	typedef TJclAbstractContainerBase inherited;
	
protected:
	float FPrecision;
	Jclcontainerintf::TSingleEqualityCompare FEqualityCompare;
	Jclcontainerintf::TSingleCompare FCompare;
	Jclcontainerintf::TSingleHashConvert FHashConvert;
	virtual void __fastcall AssignPropertiesTo(TJclAbstractContainerBase* Dest);
	float __fastcall FreeSingle(float &AValue);
	
public:
	virtual float __fastcall GetPrecision(void);
	virtual void __fastcall SetPrecision(const float Value);
	__property float Precision = {read=GetPrecision, write=SetPrecision};
	virtual Jclcontainerintf::TSingleEqualityCompare __fastcall GetEqualityCompare(void);
	virtual void __fastcall SetEqualityCompare(Jclcontainerintf::TSingleEqualityCompare Value);
	virtual bool __fastcall ItemsEqual(const float A, const float B);
	__property Jclcontainerintf::TSingleEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
	virtual Jclcontainerintf::TSingleCompare __fastcall GetCompare(void);
	virtual void __fastcall SetCompare(Jclcontainerintf::TSingleCompare Value);
	virtual int __fastcall ItemsCompare(const float A, const float B);
	__property Jclcontainerintf::TSingleCompare Compare = {read=GetCompare, write=SetCompare};
	virtual Jclcontainerintf::TSingleHashConvert __fastcall GetHashConvert(void);
	virtual void __fastcall SetHashConvert(Jclcontainerintf::TSingleHashConvert Value);
	virtual int __fastcall Hash(const float AValue);
	__property Jclcontainerintf::TSingleHashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
public:
	#pragma option push -w-inl
	/* TJclAbstractContainerBase.Create */ inline __fastcall TJclSingleAbstractContainer(void) : TJclAbstractContainerBase() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclSingleAbstractContainer(void) { }
	#pragma option pop
	
private:
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclSingleContainer;	/* Jclcontainerintf::IJclSingleContainer */
	void *__IJclSingleEqualityComparer;	/* Jclcontainerintf::IJclSingleEqualityComparer */
	void *__IJclSingleComparer;	/* Jclcontainerintf::IJclSingleComparer */
	void *__IJclSingleHashConverter;	/* Jclcontainerintf::IJclSingleHashConverter */
	
public:
	operator IJclSingleHashConverter*(void) { return (IJclSingleHashConverter*)&__IJclSingleHashConverter; }
	operator IJclSingleComparer*(void) { return (IJclSingleComparer*)&__IJclSingleComparer; }
	operator IJclSingleEqualityComparer*(void) { return (IJclSingleEqualityComparer*)&__IJclSingleEqualityComparer; }
	operator IJclSingleContainer*(void) { return (IJclSingleContainer*)&__IJclSingleContainer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclSingleContainer; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleContainer; }
	
};


class DELPHICLASS TJclDoubleAbstractContainer;
class PASCALIMPLEMENTATION TJclDoubleAbstractContainer : public TJclAbstractContainerBase 
{
	typedef TJclAbstractContainerBase inherited;
	
protected:
	double FPrecision;
	Jclcontainerintf::TDoubleEqualityCompare FEqualityCompare;
	Jclcontainerintf::TDoubleCompare FCompare;
	Jclcontainerintf::TDoubleHashConvert FHashConvert;
	virtual void __fastcall AssignPropertiesTo(TJclAbstractContainerBase* Dest);
	double __fastcall FreeDouble(double &AValue);
	
public:
	virtual double __fastcall GetPrecision(void);
	virtual void __fastcall SetPrecision(const double Value);
	__property double Precision = {read=GetPrecision, write=SetPrecision};
	virtual Jclcontainerintf::TDoubleEqualityCompare __fastcall GetEqualityCompare(void);
	virtual void __fastcall SetEqualityCompare(Jclcontainerintf::TDoubleEqualityCompare Value);
	virtual bool __fastcall ItemsEqual(const double A, const double B);
	__property Jclcontainerintf::TDoubleEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
	virtual Jclcontainerintf::TDoubleCompare __fastcall GetCompare(void);
	virtual void __fastcall SetCompare(Jclcontainerintf::TDoubleCompare Value);
	virtual int __fastcall ItemsCompare(const double A, const double B);
	__property Jclcontainerintf::TDoubleCompare Compare = {read=GetCompare, write=SetCompare};
	virtual Jclcontainerintf::TDoubleHashConvert __fastcall GetHashConvert(void);
	virtual void __fastcall SetHashConvert(Jclcontainerintf::TDoubleHashConvert Value);
	virtual int __fastcall Hash(const double AValue);
	__property Jclcontainerintf::TDoubleHashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
public:
	#pragma option push -w-inl
	/* TJclAbstractContainerBase.Create */ inline __fastcall TJclDoubleAbstractContainer(void) : TJclAbstractContainerBase() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclDoubleAbstractContainer(void) { }
	#pragma option pop
	
private:
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclDoubleContainer;	/* Jclcontainerintf::IJclDoubleContainer */
	void *__IJclDoubleEqualityComparer;	/* Jclcontainerintf::IJclDoubleEqualityComparer */
	void *__IJclDoubleComparer;	/* Jclcontainerintf::IJclDoubleComparer */
	void *__IJclDoubleHashConverter;	/* Jclcontainerintf::IJclDoubleHashConverter */
	
public:
	operator IJclDoubleHashConverter*(void) { return (IJclDoubleHashConverter*)&__IJclDoubleHashConverter; }
	operator IJclDoubleComparer*(void) { return (IJclDoubleComparer*)&__IJclDoubleComparer; }
	operator IJclDoubleEqualityComparer*(void) { return (IJclDoubleEqualityComparer*)&__IJclDoubleEqualityComparer; }
	operator IJclDoubleContainer*(void) { return (IJclDoubleContainer*)&__IJclDoubleContainer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclDoubleContainer; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleContainer; }
	
};


class DELPHICLASS TJclExtendedAbstractContainer;
class PASCALIMPLEMENTATION TJclExtendedAbstractContainer : public TJclAbstractContainerBase 
{
	typedef TJclAbstractContainerBase inherited;
	
protected:
	Extended FPrecision;
	Jclcontainerintf::TExtendedEqualityCompare FEqualityCompare;
	Jclcontainerintf::TExtendedCompare FCompare;
	Jclcontainerintf::TExtendedHashConvert FHashConvert;
	virtual void __fastcall AssignPropertiesTo(TJclAbstractContainerBase* Dest);
	Extended __fastcall FreeExtended(Extended &AValue);
	
public:
	virtual Extended __fastcall GetPrecision(void);
	virtual void __fastcall SetPrecision(const Extended Value);
	__property Extended Precision = {read=GetPrecision, write=SetPrecision};
	virtual Jclcontainerintf::TExtendedEqualityCompare __fastcall GetEqualityCompare(void);
	virtual void __fastcall SetEqualityCompare(Jclcontainerintf::TExtendedEqualityCompare Value);
	virtual bool __fastcall ItemsEqual(const Extended A, const Extended B);
	__property Jclcontainerintf::TExtendedEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
	virtual Jclcontainerintf::TExtendedCompare __fastcall GetCompare(void);
	virtual void __fastcall SetCompare(Jclcontainerintf::TExtendedCompare Value);
	virtual int __fastcall ItemsCompare(const Extended A, const Extended B);
	__property Jclcontainerintf::TExtendedCompare Compare = {read=GetCompare, write=SetCompare};
	virtual Jclcontainerintf::TExtendedHashConvert __fastcall GetHashConvert(void);
	virtual void __fastcall SetHashConvert(Jclcontainerintf::TExtendedHashConvert Value);
	virtual int __fastcall Hash(const Extended AValue);
	__property Jclcontainerintf::TExtendedHashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
public:
	#pragma option push -w-inl
	/* TJclAbstractContainerBase.Create */ inline __fastcall TJclExtendedAbstractContainer(void) : TJclAbstractContainerBase() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclExtendedAbstractContainer(void) { }
	#pragma option pop
	
private:
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclExtendedContainer;	/* Jclcontainerintf::IJclExtendedContainer */
	void *__IJclExtendedEqualityComparer;	/* Jclcontainerintf::IJclExtendedEqualityComparer */
	void *__IJclExtendedComparer;	/* Jclcontainerintf::IJclExtendedComparer */
	void *__IJclExtendedHashConverter;	/* Jclcontainerintf::IJclExtendedHashConverter */
	
public:
	operator IJclExtendedHashConverter*(void) { return (IJclExtendedHashConverter*)&__IJclExtendedHashConverter; }
	operator IJclExtendedComparer*(void) { return (IJclExtendedComparer*)&__IJclExtendedComparer; }
	operator IJclExtendedEqualityComparer*(void) { return (IJclExtendedEqualityComparer*)&__IJclExtendedEqualityComparer; }
	operator IJclExtendedContainer*(void) { return (IJclExtendedContainer*)&__IJclExtendedContainer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclExtendedContainer; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedContainer; }
	
};


class DELPHICLASS TJclIntegerAbstractContainer;
class PASCALIMPLEMENTATION TJclIntegerAbstractContainer : public TJclAbstractContainerBase 
{
	typedef TJclAbstractContainerBase inherited;
	
protected:
	Jclcontainerintf::TIntegerEqualityCompare FEqualityCompare;
	Jclcontainerintf::TIntegerCompare FCompare;
	Jclcontainerintf::TIntegerHashConvert FHashConvert;
	virtual void __fastcall AssignPropertiesTo(TJclAbstractContainerBase* Dest);
	int __fastcall FreeInteger(int &AValue);
	
public:
	virtual Jclcontainerintf::TIntegerEqualityCompare __fastcall GetEqualityCompare(void);
	virtual void __fastcall SetEqualityCompare(Jclcontainerintf::TIntegerEqualityCompare Value);
	virtual bool __fastcall ItemsEqual(int A, int B);
	__property Jclcontainerintf::TIntegerEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
	virtual Jclcontainerintf::TIntegerCompare __fastcall GetCompare(void);
	virtual void __fastcall SetCompare(Jclcontainerintf::TIntegerCompare Value);
	virtual int __fastcall ItemsCompare(int A, int B);
	__property Jclcontainerintf::TIntegerCompare Compare = {read=GetCompare, write=SetCompare};
	virtual Jclcontainerintf::TIntegerHashConvert __fastcall GetHashConvert(void);
	virtual void __fastcall SetHashConvert(Jclcontainerintf::TIntegerHashConvert Value);
	virtual int __fastcall Hash(int AValue);
	__property Jclcontainerintf::TIntegerHashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
public:
	#pragma option push -w-inl
	/* TJclAbstractContainerBase.Create */ inline __fastcall TJclIntegerAbstractContainer(void) : TJclAbstractContainerBase() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclIntegerAbstractContainer(void) { }
	#pragma option pop
	
private:
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclContainer;	/* Jclcontainerintf::IJclContainer */
	void *__IJclIntegerEqualityComparer;	/* Jclcontainerintf::IJclIntegerEqualityComparer */
	void *__IJclIntegerComparer;	/* Jclcontainerintf::IJclIntegerComparer */
	void *__IJclIntegerHashConverter;	/* Jclcontainerintf::IJclIntegerHashConverter */
	
public:
	operator IJclIntegerHashConverter*(void) { return (IJclIntegerHashConverter*)&__IJclIntegerHashConverter; }
	operator IJclIntegerComparer*(void) { return (IJclIntegerComparer*)&__IJclIntegerComparer; }
	operator IJclIntegerEqualityComparer*(void) { return (IJclIntegerEqualityComparer*)&__IJclIntegerEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclContainer; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclContainer; }
	
};


class DELPHICLASS TJclCardinalAbstractContainer;
class PASCALIMPLEMENTATION TJclCardinalAbstractContainer : public TJclAbstractContainerBase 
{
	typedef TJclAbstractContainerBase inherited;
	
protected:
	Jclcontainerintf::TCardinalEqualityCompare FEqualityCompare;
	Jclcontainerintf::TCardinalCompare FCompare;
	Jclcontainerintf::TCardinalHashConvert FHashConvert;
	virtual void __fastcall AssignPropertiesTo(TJclAbstractContainerBase* Dest);
	unsigned __fastcall FreeCardinal(unsigned &AValue);
	
public:
	virtual Jclcontainerintf::TCardinalEqualityCompare __fastcall GetEqualityCompare(void);
	virtual void __fastcall SetEqualityCompare(Jclcontainerintf::TCardinalEqualityCompare Value);
	virtual bool __fastcall ItemsEqual(unsigned A, unsigned B);
	__property Jclcontainerintf::TCardinalEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
	virtual Jclcontainerintf::TCardinalCompare __fastcall GetCompare(void);
	virtual void __fastcall SetCompare(Jclcontainerintf::TCardinalCompare Value);
	virtual int __fastcall ItemsCompare(unsigned A, unsigned B);
	__property Jclcontainerintf::TCardinalCompare Compare = {read=GetCompare, write=SetCompare};
	virtual Jclcontainerintf::TCardinalHashConvert __fastcall GetHashConvert(void);
	virtual void __fastcall SetHashConvert(Jclcontainerintf::TCardinalHashConvert Value);
	virtual int __fastcall Hash(unsigned AValue);
	__property Jclcontainerintf::TCardinalHashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
public:
	#pragma option push -w-inl
	/* TJclAbstractContainerBase.Create */ inline __fastcall TJclCardinalAbstractContainer(void) : TJclAbstractContainerBase() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclCardinalAbstractContainer(void) { }
	#pragma option pop
	
private:
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclContainer;	/* Jclcontainerintf::IJclContainer */
	void *__IJclCardinalEqualityComparer;	/* Jclcontainerintf::IJclCardinalEqualityComparer */
	void *__IJclCardinalComparer;	/* Jclcontainerintf::IJclCardinalComparer */
	void *__IJclCardinalHashConverter;	/* Jclcontainerintf::IJclCardinalHashConverter */
	
public:
	operator IJclCardinalHashConverter*(void) { return (IJclCardinalHashConverter*)&__IJclCardinalHashConverter; }
	operator IJclCardinalComparer*(void) { return (IJclCardinalComparer*)&__IJclCardinalComparer; }
	operator IJclCardinalEqualityComparer*(void) { return (IJclCardinalEqualityComparer*)&__IJclCardinalEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclContainer; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclContainer; }
	
};


class DELPHICLASS TJclInt64AbstractContainer;
class PASCALIMPLEMENTATION TJclInt64AbstractContainer : public TJclAbstractContainerBase 
{
	typedef TJclAbstractContainerBase inherited;
	
protected:
	Jclcontainerintf::TInt64EqualityCompare FEqualityCompare;
	Jclcontainerintf::TInt64Compare FCompare;
	Jclcontainerintf::TInt64HashConvert FHashConvert;
	virtual void __fastcall AssignPropertiesTo(TJclAbstractContainerBase* Dest);
	__int64 __fastcall FreeInt64(__int64 &AValue);
	
public:
	virtual Jclcontainerintf::TInt64EqualityCompare __fastcall GetEqualityCompare(void);
	virtual void __fastcall SetEqualityCompare(Jclcontainerintf::TInt64EqualityCompare Value);
	virtual bool __fastcall ItemsEqual(const __int64 A, const __int64 B);
	__property Jclcontainerintf::TInt64EqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
	virtual Jclcontainerintf::TInt64Compare __fastcall GetCompare(void);
	virtual void __fastcall SetCompare(Jclcontainerintf::TInt64Compare Value);
	virtual int __fastcall ItemsCompare(const __int64 A, const __int64 B);
	__property Jclcontainerintf::TInt64Compare Compare = {read=GetCompare, write=SetCompare};
	virtual Jclcontainerintf::TInt64HashConvert __fastcall GetHashConvert(void);
	virtual void __fastcall SetHashConvert(Jclcontainerintf::TInt64HashConvert Value);
	virtual int __fastcall Hash(const __int64 AValue);
	__property Jclcontainerintf::TInt64HashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
public:
	#pragma option push -w-inl
	/* TJclAbstractContainerBase.Create */ inline __fastcall TJclInt64AbstractContainer(void) : TJclAbstractContainerBase() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclInt64AbstractContainer(void) { }
	#pragma option pop
	
private:
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclContainer;	/* Jclcontainerintf::IJclContainer */
	void *__IJclInt64EqualityComparer;	/* Jclcontainerintf::IJclInt64EqualityComparer */
	void *__IJclInt64Comparer;	/* Jclcontainerintf::IJclInt64Comparer */
	void *__IJclInt64HashConverter;	/* Jclcontainerintf::IJclInt64HashConverter */
	
public:
	operator IJclInt64HashConverter*(void) { return (IJclInt64HashConverter*)&__IJclInt64HashConverter; }
	operator IJclInt64Comparer*(void) { return (IJclInt64Comparer*)&__IJclInt64Comparer; }
	operator IJclInt64EqualityComparer*(void) { return (IJclInt64EqualityComparer*)&__IJclInt64EqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclContainer; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclContainer; }
	
};


class DELPHICLASS TJclPtrAbstractContainer;
class PASCALIMPLEMENTATION TJclPtrAbstractContainer : public TJclAbstractContainerBase 
{
	typedef TJclAbstractContainerBase inherited;
	
protected:
	Jclcontainerintf::TPtrEqualityCompare FEqualityCompare;
	Jclcontainerintf::TPtrCompare FCompare;
	Jclcontainerintf::TPtrHashConvert FHashConvert;
	virtual void __fastcall AssignPropertiesTo(TJclAbstractContainerBase* Dest);
	void * __fastcall FreePointer(void * &APtr);
	
public:
	virtual Jclcontainerintf::TPtrEqualityCompare __fastcall GetEqualityCompare(void);
	virtual void __fastcall SetEqualityCompare(Jclcontainerintf::TPtrEqualityCompare Value);
	virtual bool __fastcall ItemsEqual(void * A, void * B);
	__property Jclcontainerintf::TPtrEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
	virtual Jclcontainerintf::TPtrCompare __fastcall GetCompare(void);
	virtual void __fastcall SetCompare(Jclcontainerintf::TPtrCompare Value);
	virtual int __fastcall ItemsCompare(void * A, void * B);
	__property Jclcontainerintf::TPtrCompare Compare = {read=GetCompare, write=SetCompare};
	virtual Jclcontainerintf::TPtrHashConvert __fastcall GetHashConvert(void);
	virtual void __fastcall SetHashConvert(Jclcontainerintf::TPtrHashConvert Value);
	virtual int __fastcall Hash(void * APtr);
	__property Jclcontainerintf::TPtrHashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
public:
	#pragma option push -w-inl
	/* TJclAbstractContainerBase.Create */ inline __fastcall TJclPtrAbstractContainer(void) : TJclAbstractContainerBase() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPtrAbstractContainer(void) { }
	#pragma option pop
	
private:
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclContainer;	/* Jclcontainerintf::IJclContainer */
	void *__IJclPtrEqualityComparer;	/* Jclcontainerintf::IJclPtrEqualityComparer */
	void *__IJclPtrComparer;	/* Jclcontainerintf::IJclPtrComparer */
	void *__IJclPtrHashConverter;	/* Jclcontainerintf::IJclPtrHashConverter */
	
public:
	operator IJclPtrHashConverter*(void) { return (IJclPtrHashConverter*)&__IJclPtrHashConverter; }
	operator IJclPtrComparer*(void) { return (IJclPtrComparer*)&__IJclPtrComparer; }
	operator IJclPtrEqualityComparer*(void) { return (IJclPtrEqualityComparer*)&__IJclPtrEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclContainer; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclContainer; }
	
};


class DELPHICLASS TJclAbstractContainer;
class PASCALIMPLEMENTATION TJclAbstractContainer : public TJclAbstractContainerBase 
{
	typedef TJclAbstractContainerBase inherited;
	
protected:
	bool FOwnsObjects;
	Jclcontainerintf::TEqualityCompare FEqualityCompare;
	Jclcontainerintf::TCompare FCompare;
	Jclcontainerintf::THashConvert FHashConvert;
	virtual void __fastcall AssignPropertiesTo(TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclAbstractContainer(bool AOwnsObjects);
	virtual System::TObject* __fastcall FreeObject(System::TObject* &AObject);
	virtual bool __fastcall GetOwnsObjects(void);
	__property bool OwnsObjects = {read=FOwnsObjects, nodefault};
	virtual Jclcontainerintf::TEqualityCompare __fastcall GetEqualityCompare(void);
	virtual void __fastcall SetEqualityCompare(Jclcontainerintf::TEqualityCompare Value);
	virtual bool __fastcall ItemsEqual(System::TObject* A, System::TObject* B);
	__property Jclcontainerintf::TEqualityCompare EqualityCompare = {read=GetEqualityCompare, write=SetEqualityCompare};
	virtual Jclcontainerintf::TCompare __fastcall GetCompare(void);
	virtual void __fastcall SetCompare(Jclcontainerintf::TCompare Value);
	virtual int __fastcall ItemsCompare(System::TObject* A, System::TObject* B);
	__property Jclcontainerintf::TCompare Compare = {read=GetCompare, write=SetCompare};
	virtual Jclcontainerintf::THashConvert __fastcall GetHashConvert(void);
	virtual void __fastcall SetHashConvert(Jclcontainerintf::THashConvert Value);
	virtual int __fastcall Hash(System::TObject* AObject);
	__property Jclcontainerintf::THashConvert HashConvert = {read=GetHashConvert, write=SetHashConvert};
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclAbstractContainer(void) { }
	#pragma option pop
	
private:
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclContainer;	/* Jclcontainerintf::IJclContainer */
	void *__IJclObjectOwner;	/* Jclcontainerintf::IJclObjectOwner */
	void *__IJclEqualityComparer;	/* Jclcontainerintf::IJclEqualityComparer */
	void *__IJclComparer;	/* Jclcontainerintf::IJclComparer */
	void *__IJclHashConverter;	/* Jclcontainerintf::IJclHashConverter */
	
public:
	operator IJclHashConverter*(void) { return (IJclHashConverter*)&__IJclHashConverter; }
	operator IJclComparer*(void) { return (IJclComparer*)&__IJclComparer; }
	operator IJclEqualityComparer*(void) { return (IJclEqualityComparer*)&__IJclEqualityComparer; }
	operator IJclObjectOwner*(void) { return (IJclObjectOwner*)&__IJclObjectOwner; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclContainer; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclContainer; }
	
};


class DELPHICLASS TJclAnsiStrAbstractCollection;
class PASCALIMPLEMENTATION TJclAnsiStrAbstractCollection : public TJclAnsiStrAbstractContainer 
{
	typedef TJclAnsiStrAbstractContainer inherited;
	
public:
	virtual bool __fastcall Add(const AnsiString AString) = 0 ;
	virtual bool __fastcall AddAll(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const AnsiString AString) = 0 ;
	virtual bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection) = 0 ;
	virtual bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection) = 0 ;
	virtual bool __fastcall Extract(const AnsiString AString) = 0 ;
	virtual bool __fastcall ExtractAll(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection) = 0 ;
	virtual Jclcontainerintf::_di_IJclAnsiStrIterator __fastcall First(void) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual Jclcontainerintf::_di_IJclAnsiStrIterator __fastcall Last(void) = 0 ;
	virtual bool __fastcall Remove(const AnsiString AString) = 0 ;
	virtual bool __fastcall RemoveAll(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection) = 0 ;
	virtual bool __fastcall RetainAll(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual Jclcontainerintf::_di_IJclAnsiStrIterator __fastcall GetEnumerator(void) = 0 ;
	void __fastcall LoadFromStrings(Classes::TStrings* Strings);
	void __fastcall SaveToStrings(Classes::TStrings* Strings);
	void __fastcall AppendToStrings(Classes::TStrings* Strings);
	void __fastcall AppendFromStrings(Classes::TStrings* Strings);
	Classes::TStrings* __fastcall GetAsStrings(void);
	AnsiString __fastcall GetAsDelimited(const AnsiString Separator = "\r\n");
	void __fastcall AppendDelimited(const AnsiString AString, const AnsiString Separator = "\r\n");
	void __fastcall LoadDelimited(const AnsiString AString, const AnsiString Separator = "\r\n");
public:
	#pragma option push -w-inl
	/* TJclAbstractContainerBase.Create */ inline __fastcall TJclAnsiStrAbstractCollection(void) : TJclAnsiStrAbstractContainer() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclAnsiStrAbstractCollection(void) { }
	#pragma option pop
	
private:
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclAnsiStrCollection;	/* Jclcontainerintf::IJclAnsiStrCollection */
	void *__IJclAnsiStrEqualityComparer;	/* Jclcontainerintf::IJclAnsiStrEqualityComparer */
	void *__IJclAnsiStrComparer;	/* Jclcontainerintf::IJclAnsiStrComparer */
	
public:
	operator IJclAnsiStrComparer*(void) { return (IJclAnsiStrComparer*)&__IJclAnsiStrComparer; }
	operator IJclAnsiStrEqualityComparer*(void) { return (IJclAnsiStrEqualityComparer*)&__IJclAnsiStrEqualityComparer; }
	operator IJclAnsiStrCollection*(void) { return (IJclAnsiStrCollection*)&__IJclAnsiStrCollection; }
	operator IJclAnsiStrFlatContainer*(void) { return (IJclAnsiStrFlatContainer*)&__IJclAnsiStrCollection; }
	operator IJclAnsiStrContainer*(void) { return (IJclAnsiStrContainer*)&__IJclAnsiStrCollection; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclAnsiStrCollection; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclAnsiStrCollection; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrCollection; }
	
};


class DELPHICLASS TJclWideStrAbstractCollection;
class PASCALIMPLEMENTATION TJclWideStrAbstractCollection : public TJclWideStrAbstractContainer 
{
	typedef TJclWideStrAbstractContainer inherited;
	
public:
	virtual bool __fastcall Add(const WideString AString) = 0 ;
	virtual bool __fastcall AddAll(const Jclcontainerintf::_di_IJclWideStrCollection ACollection) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall Contains(const WideString AString) = 0 ;
	virtual bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclWideStrCollection ACollection) = 0 ;
	virtual bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclWideStrCollection ACollection) = 0 ;
	virtual bool __fastcall Extract(const WideString AString) = 0 ;
	virtual bool __fastcall ExtractAll(const Jclcontainerintf::_di_IJclWideStrCollection ACollection) = 0 ;
	virtual Jclcontainerintf::_di_IJclWideStrIterator __fastcall First(void) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual Jclcontainerintf::_di_IJclWideStrIterator __fastcall Last(void) = 0 ;
	virtual bool __fastcall Remove(const WideString AString) = 0 ;
	virtual bool __fastcall RemoveAll(const Jclcontainerintf::_di_IJclWideStrCollection ACollection) = 0 ;
	virtual bool __fastcall RetainAll(const Jclcontainerintf::_di_IJclWideStrCollection ACollection) = 0 ;
	virtual int __fastcall Size(void) = 0 ;
	virtual Jclcontainerintf::_di_IJclWideStrIterator __fastcall GetEnumerator(void) = 0 ;
	void __fastcall LoadFromStrings(Jclwidestrings::TJclWideStrings* Strings);
	void __fastcall SaveToStrings(Jclwidestrings::TJclWideStrings* Strings);
	void __fastcall AppendToStrings(Jclwidestrings::TJclWideStrings* Strings);
	void __fastcall AppendFromStrings(Jclwidestrings::TJclWideStrings* Strings);
	Jclwidestrings::TJclWideStrings* __fastcall GetAsStrings(void);
	WideString __fastcall GetAsDelimited(const WideString Separator = L"\r\n");
	void __fastcall AppendDelimited(const WideString AString, const WideString Separator = L"\r\n");
	void __fastcall LoadDelimited(const WideString AString, const WideString Separator = L"\r\n");
public:
	#pragma option push -w-inl
	/* TJclAbstractContainerBase.Create */ inline __fastcall TJclWideStrAbstractCollection(void) : TJclWideStrAbstractContainer() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclWideStrAbstractCollection(void) { }
	#pragma option pop
	
private:
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclWideStrCollection;	/* Jclcontainerintf::IJclWideStrCollection */
	void *__IJclWideStrEqualityComparer;	/* Jclcontainerintf::IJclWideStrEqualityComparer */
	void *__IJclWideStrComparer;	/* Jclcontainerintf::IJclWideStrComparer */
	
public:
	operator IJclWideStrComparer*(void) { return (IJclWideStrComparer*)&__IJclWideStrComparer; }
	operator IJclWideStrEqualityComparer*(void) { return (IJclWideStrEqualityComparer*)&__IJclWideStrEqualityComparer; }
	operator IJclWideStrCollection*(void) { return (IJclWideStrCollection*)&__IJclWideStrCollection; }
	operator IJclWideStrFlatContainer*(void) { return (IJclWideStrFlatContainer*)&__IJclWideStrCollection; }
	operator IJclWideStrContainer*(void) { return (IJclWideStrContainer*)&__IJclWideStrCollection; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclWideStrCollection; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclWideStrCollection; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrCollection; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Byte BytePermTable[256];
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jclabstractcontainers */
using namespace Jclabstractcontainers;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclabstractcontainers
