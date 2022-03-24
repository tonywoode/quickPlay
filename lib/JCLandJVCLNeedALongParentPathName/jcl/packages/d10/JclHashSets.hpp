// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclhashsets.pas' rev: 10.00

#ifndef JclhashsetsHPP
#define JclhashsetsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclabstractcontainers.hpp>	// Pascal unit
#include <Jclcontainerintf.hpp>	// Pascal unit
#include <Jclhashmaps.hpp>	// Pascal unit
#include <Jclsynch.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclhashsets
{
//-- type declarations -------------------------------------------------------
typedef TInterfacedObject TRefUnique;
;

class DELPHICLASS TJclIntfHashSet;
class PASCALIMPLEMENTATION TJclIntfHashSet : public Jclabstractcontainers::TJclIntfAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntfAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
public:
	__fastcall TJclIntfHashSet(int ACapacity)/* overload */;
	
private:
	Jclcontainerintf::_di_IJclIntfMap FMap;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntfHashSet(const Jclcontainerintf::_di_IJclIntfMap AMap)/* overload */;
	__fastcall virtual ~TJclIntfHashSet(void);
	virtual int __fastcall GetAutoPackParameter(void);
	virtual Jclcontainerintf::TJclAutoPackStrategy __fastcall GetAutoPackStrategy(void);
	virtual int __fastcall GetCapacity(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetAutoPackParameter(int Value);
	virtual void __fastcall SetAutoPackStrategy(Jclcontainerintf::TJclAutoPackStrategy Value);
	virtual void __fastcall SetCapacity(int Value);
	virtual bool __fastcall GetAllowDefaultElements(void);
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
	bool __fastcall Add(const System::_di_IInterface AInterface);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclIntfCollection ACollection);
	void __fastcall Clear(void);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclIntfCollection ACollection);
	bool __fastcall Contains(const System::_di_IInterface AInterface);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclIntfCollection ACollection);
	bool __fastcall Extract(const System::_di_IInterface AInterface);
	bool __fastcall ExtractAll(const Jclcontainerintf::_di_IJclIntfCollection ACollection);
	Jclcontainerintf::_di_IJclIntfIterator __fastcall First();
	bool __fastcall IsEmpty(void);
	Jclcontainerintf::_di_IJclIntfIterator __fastcall Last();
	bool __fastcall Remove(const System::_di_IInterface AInterface);
	bool __fastcall RemoveAll(const Jclcontainerintf::_di_IJclIntfCollection ACollection);
	bool __fastcall RetainAll(const Jclcontainerintf::_di_IJclIntfCollection ACollection);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclIntfIterator __fastcall GetEnumerator();
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclIntfCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclIntfCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclIntfCollection ACollection);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclIntfEqualityComparer;	/* Jclcontainerintf::IJclIntfEqualityComparer */
	void *__IJclIntfSet;	/* Jclcontainerintf::IJclIntfSet */
	
public:
	operator IJclIntfSet*(void) { return (IJclIntfSet*)&__IJclIntfSet; }
	operator IJclIntfCollection*(void) { return (IJclIntfCollection*)&__IJclIntfSet; }
	operator IJclIntfEqualityComparer*(void) { return (IJclIntfEqualityComparer*)&__IJclIntfEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfSet; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfSet; }
	
};


class DELPHICLASS TJclAnsiStrHashSet;
class PASCALIMPLEMENTATION TJclAnsiStrHashSet : public Jclabstractcontainers::TJclAnsiStrAbstractCollection 
{
	typedef Jclabstractcontainers::TJclAnsiStrAbstractCollection inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
public:
	__fastcall TJclAnsiStrHashSet(int ACapacity)/* overload */;
	virtual bool __fastcall GetCaseSensitive(void);
	virtual void __fastcall SetCaseSensitive(bool Value);
	virtual Jclcontainerintf::TJclAnsiStrEncoding __fastcall GetEncoding(void);
	virtual void __fastcall SetEncoding(Jclcontainerintf::TJclAnsiStrEncoding Value);
	
private:
	Jclcontainerintf::_di_IJclAnsiStrMap FMap;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclAnsiStrHashSet(const Jclcontainerintf::_di_IJclAnsiStrMap AMap)/* overload */;
	__fastcall virtual ~TJclAnsiStrHashSet(void);
	virtual int __fastcall GetAutoPackParameter(void);
	virtual Jclcontainerintf::TJclAutoPackStrategy __fastcall GetAutoPackStrategy(void);
	virtual int __fastcall GetCapacity(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetAutoPackParameter(int Value);
	virtual void __fastcall SetAutoPackStrategy(Jclcontainerintf::TJclAutoPackStrategy Value);
	virtual void __fastcall SetCapacity(int Value);
	virtual bool __fastcall GetAllowDefaultElements(void);
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
	virtual bool __fastcall Add(const AnsiString AString);
	virtual bool __fastcall AddAll(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection);
	virtual void __fastcall Clear(void);
	virtual bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection);
	virtual bool __fastcall Contains(const AnsiString AString);
	virtual bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection);
	virtual bool __fastcall Extract(const AnsiString AString);
	virtual bool __fastcall ExtractAll(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection);
	virtual Jclcontainerintf::_di_IJclAnsiStrIterator __fastcall First();
	virtual bool __fastcall IsEmpty(void);
	virtual Jclcontainerintf::_di_IJclAnsiStrIterator __fastcall Last();
	virtual bool __fastcall Remove(const AnsiString AString);
	virtual bool __fastcall RemoveAll(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection);
	virtual bool __fastcall RetainAll(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection);
	virtual int __fastcall Size(void);
	virtual Jclcontainerintf::_di_IJclAnsiStrIterator __fastcall GetEnumerator();
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclAnsiStrEqualityComparer;	/* Jclcontainerintf::IJclAnsiStrEqualityComparer */
	void *__IJclAnsiStrSet;	/* Jclcontainerintf::IJclAnsiStrSet */
	
public:
	operator IJclAnsiStrSet*(void) { return (IJclAnsiStrSet*)&__IJclAnsiStrSet; }
	operator IJclAnsiStrCollection*(void) { return (IJclAnsiStrCollection*)&__IJclAnsiStrSet; }
	operator IJclAnsiStrEqualityComparer*(void) { return (IJclAnsiStrEqualityComparer*)&__IJclAnsiStrEqualityComparer; }
	operator IJclAnsiStrContainer*(void) { return (IJclAnsiStrContainer*)&__IJclAnsiStrSet; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclAnsiStrSet; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclAnsiStrSet; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrSet; }
	
};


class DELPHICLASS TJclWideStrHashSet;
class PASCALIMPLEMENTATION TJclWideStrHashSet : public Jclabstractcontainers::TJclWideStrAbstractCollection 
{
	typedef Jclabstractcontainers::TJclWideStrAbstractCollection inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
public:
	__fastcall TJclWideStrHashSet(int ACapacity)/* overload */;
	virtual bool __fastcall GetCaseSensitive(void);
	virtual void __fastcall SetCaseSensitive(bool Value);
	virtual Jclcontainerintf::TJclWideStrEncoding __fastcall GetEncoding(void);
	virtual void __fastcall SetEncoding(Jclcontainerintf::TJclWideStrEncoding Value);
	
private:
	Jclcontainerintf::_di_IJclWideStrMap FMap;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclWideStrHashSet(const Jclcontainerintf::_di_IJclWideStrMap AMap)/* overload */;
	__fastcall virtual ~TJclWideStrHashSet(void);
	virtual int __fastcall GetAutoPackParameter(void);
	virtual Jclcontainerintf::TJclAutoPackStrategy __fastcall GetAutoPackStrategy(void);
	virtual int __fastcall GetCapacity(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetAutoPackParameter(int Value);
	virtual void __fastcall SetAutoPackStrategy(Jclcontainerintf::TJclAutoPackStrategy Value);
	virtual void __fastcall SetCapacity(int Value);
	virtual bool __fastcall GetAllowDefaultElements(void);
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
	virtual bool __fastcall Add(const WideString AString);
	virtual bool __fastcall AddAll(const Jclcontainerintf::_di_IJclWideStrCollection ACollection);
	virtual void __fastcall Clear(void);
	virtual bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclWideStrCollection ACollection);
	virtual bool __fastcall Contains(const WideString AString);
	virtual bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclWideStrCollection ACollection);
	virtual bool __fastcall Extract(const WideString AString);
	virtual bool __fastcall ExtractAll(const Jclcontainerintf::_di_IJclWideStrCollection ACollection);
	virtual Jclcontainerintf::_di_IJclWideStrIterator __fastcall First();
	virtual bool __fastcall IsEmpty(void);
	virtual Jclcontainerintf::_di_IJclWideStrIterator __fastcall Last();
	virtual bool __fastcall Remove(const WideString AString);
	virtual bool __fastcall RemoveAll(const Jclcontainerintf::_di_IJclWideStrCollection ACollection);
	virtual bool __fastcall RetainAll(const Jclcontainerintf::_di_IJclWideStrCollection ACollection);
	virtual int __fastcall Size(void);
	virtual Jclcontainerintf::_di_IJclWideStrIterator __fastcall GetEnumerator();
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclWideStrCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclWideStrCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclWideStrCollection ACollection);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclWideStrEqualityComparer;	/* Jclcontainerintf::IJclWideStrEqualityComparer */
	void *__IJclWideStrSet;	/* Jclcontainerintf::IJclWideStrSet */
	
public:
	operator IJclWideStrSet*(void) { return (IJclWideStrSet*)&__IJclWideStrSet; }
	operator IJclWideStrCollection*(void) { return (IJclWideStrCollection*)&__IJclWideStrSet; }
	operator IJclWideStrEqualityComparer*(void) { return (IJclWideStrEqualityComparer*)&__IJclWideStrEqualityComparer; }
	operator IJclWideStrContainer*(void) { return (IJclWideStrContainer*)&__IJclWideStrSet; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclWideStrSet; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclWideStrSet; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrSet; }
	
};


typedef TJclAnsiStrHashSet TJclStrHashSet;
;

class DELPHICLASS TJclSingleHashSet;
class PASCALIMPLEMENTATION TJclSingleHashSet : public Jclabstractcontainers::TJclSingleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclSingleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
public:
	__fastcall TJclSingleHashSet(int ACapacity)/* overload */;
	virtual float __fastcall GetPrecision(void);
	virtual void __fastcall SetPrecision(const float Value);
	
private:
	Jclcontainerintf::_di_IJclSingleMap FMap;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclSingleHashSet(const Jclcontainerintf::_di_IJclSingleMap AMap)/* overload */;
	__fastcall virtual ~TJclSingleHashSet(void);
	virtual int __fastcall GetAutoPackParameter(void);
	virtual Jclcontainerintf::TJclAutoPackStrategy __fastcall GetAutoPackStrategy(void);
	virtual int __fastcall GetCapacity(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetAutoPackParameter(int Value);
	virtual void __fastcall SetAutoPackStrategy(Jclcontainerintf::TJclAutoPackStrategy Value);
	virtual void __fastcall SetCapacity(int Value);
	virtual bool __fastcall GetAllowDefaultElements(void);
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
	bool __fastcall Add(const float AValue);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclSingleCollection ACollection);
	void __fastcall Clear(void);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclSingleCollection ACollection);
	bool __fastcall Contains(const float AValue);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclSingleCollection ACollection);
	bool __fastcall Extract(const float AValue);
	bool __fastcall ExtractAll(const Jclcontainerintf::_di_IJclSingleCollection ACollection);
	Jclcontainerintf::_di_IJclSingleIterator __fastcall First();
	bool __fastcall IsEmpty(void);
	Jclcontainerintf::_di_IJclSingleIterator __fastcall Last();
	bool __fastcall Remove(const float AValue);
	bool __fastcall RemoveAll(const Jclcontainerintf::_di_IJclSingleCollection ACollection);
	bool __fastcall RetainAll(const Jclcontainerintf::_di_IJclSingleCollection ACollection);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclSingleIterator __fastcall GetEnumerator();
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclSingleCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclSingleCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclSingleCollection ACollection);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclSingleEqualityComparer;	/* Jclcontainerintf::IJclSingleEqualityComparer */
	void *__IJclSingleSet;	/* Jclcontainerintf::IJclSingleSet */
	
public:
	operator IJclSingleSet*(void) { return (IJclSingleSet*)&__IJclSingleSet; }
	operator IJclSingleCollection*(void) { return (IJclSingleCollection*)&__IJclSingleSet; }
	operator IJclSingleEqualityComparer*(void) { return (IJclSingleEqualityComparer*)&__IJclSingleEqualityComparer; }
	operator IJclSingleContainer*(void) { return (IJclSingleContainer*)&__IJclSingleSet; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclSingleSet; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleSet; }
	
};


class DELPHICLASS TJclDoubleHashSet;
class PASCALIMPLEMENTATION TJclDoubleHashSet : public Jclabstractcontainers::TJclDoubleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclDoubleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
public:
	__fastcall TJclDoubleHashSet(int ACapacity)/* overload */;
	virtual double __fastcall GetPrecision(void);
	virtual void __fastcall SetPrecision(const double Value);
	
private:
	Jclcontainerintf::_di_IJclDoubleMap FMap;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclDoubleHashSet(const Jclcontainerintf::_di_IJclDoubleMap AMap)/* overload */;
	__fastcall virtual ~TJclDoubleHashSet(void);
	virtual int __fastcall GetAutoPackParameter(void);
	virtual Jclcontainerintf::TJclAutoPackStrategy __fastcall GetAutoPackStrategy(void);
	virtual int __fastcall GetCapacity(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetAutoPackParameter(int Value);
	virtual void __fastcall SetAutoPackStrategy(Jclcontainerintf::TJclAutoPackStrategy Value);
	virtual void __fastcall SetCapacity(int Value);
	virtual bool __fastcall GetAllowDefaultElements(void);
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
	bool __fastcall Add(const double AValue);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclDoubleCollection ACollection);
	void __fastcall Clear(void);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclDoubleCollection ACollection);
	bool __fastcall Contains(const double AValue);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclDoubleCollection ACollection);
	bool __fastcall Extract(const double AValue);
	bool __fastcall ExtractAll(const Jclcontainerintf::_di_IJclDoubleCollection ACollection);
	Jclcontainerintf::_di_IJclDoubleIterator __fastcall First();
	bool __fastcall IsEmpty(void);
	Jclcontainerintf::_di_IJclDoubleIterator __fastcall Last();
	bool __fastcall Remove(const double AValue);
	bool __fastcall RemoveAll(const Jclcontainerintf::_di_IJclDoubleCollection ACollection);
	bool __fastcall RetainAll(const Jclcontainerintf::_di_IJclDoubleCollection ACollection);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclDoubleIterator __fastcall GetEnumerator();
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclDoubleCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclDoubleCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclDoubleCollection ACollection);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclDoubleEqualityComparer;	/* Jclcontainerintf::IJclDoubleEqualityComparer */
	void *__IJclDoubleSet;	/* Jclcontainerintf::IJclDoubleSet */
	
public:
	operator IJclDoubleSet*(void) { return (IJclDoubleSet*)&__IJclDoubleSet; }
	operator IJclDoubleCollection*(void) { return (IJclDoubleCollection*)&__IJclDoubleSet; }
	operator IJclDoubleEqualityComparer*(void) { return (IJclDoubleEqualityComparer*)&__IJclDoubleEqualityComparer; }
	operator IJclDoubleContainer*(void) { return (IJclDoubleContainer*)&__IJclDoubleSet; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclDoubleSet; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleSet; }
	
};


class DELPHICLASS TJclExtendedHashSet;
class PASCALIMPLEMENTATION TJclExtendedHashSet : public Jclabstractcontainers::TJclExtendedAbstractContainer 
{
	typedef Jclabstractcontainers::TJclExtendedAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
public:
	__fastcall TJclExtendedHashSet(int ACapacity)/* overload */;
	virtual Extended __fastcall GetPrecision(void);
	virtual void __fastcall SetPrecision(const Extended Value);
	
private:
	Jclcontainerintf::_di_IJclExtendedMap FMap;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclExtendedHashSet(const Jclcontainerintf::_di_IJclExtendedMap AMap)/* overload */;
	__fastcall virtual ~TJclExtendedHashSet(void);
	virtual int __fastcall GetAutoPackParameter(void);
	virtual Jclcontainerintf::TJclAutoPackStrategy __fastcall GetAutoPackStrategy(void);
	virtual int __fastcall GetCapacity(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetAutoPackParameter(int Value);
	virtual void __fastcall SetAutoPackStrategy(Jclcontainerintf::TJclAutoPackStrategy Value);
	virtual void __fastcall SetCapacity(int Value);
	virtual bool __fastcall GetAllowDefaultElements(void);
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
	bool __fastcall Add(const Extended AValue);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclExtendedCollection ACollection);
	void __fastcall Clear(void);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclExtendedCollection ACollection);
	bool __fastcall Contains(const Extended AValue);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclExtendedCollection ACollection);
	bool __fastcall Extract(const Extended AValue);
	bool __fastcall ExtractAll(const Jclcontainerintf::_di_IJclExtendedCollection ACollection);
	Jclcontainerintf::_di_IJclExtendedIterator __fastcall First();
	bool __fastcall IsEmpty(void);
	Jclcontainerintf::_di_IJclExtendedIterator __fastcall Last();
	bool __fastcall Remove(const Extended AValue);
	bool __fastcall RemoveAll(const Jclcontainerintf::_di_IJclExtendedCollection ACollection);
	bool __fastcall RetainAll(const Jclcontainerintf::_di_IJclExtendedCollection ACollection);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclExtendedIterator __fastcall GetEnumerator();
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclExtendedCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclExtendedCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclExtendedCollection ACollection);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclExtendedEqualityComparer;	/* Jclcontainerintf::IJclExtendedEqualityComparer */
	void *__IJclExtendedSet;	/* Jclcontainerintf::IJclExtendedSet */
	
public:
	operator IJclExtendedSet*(void) { return (IJclExtendedSet*)&__IJclExtendedSet; }
	operator IJclExtendedCollection*(void) { return (IJclExtendedCollection*)&__IJclExtendedSet; }
	operator IJclExtendedEqualityComparer*(void) { return (IJclExtendedEqualityComparer*)&__IJclExtendedEqualityComparer; }
	operator IJclExtendedContainer*(void) { return (IJclExtendedContainer*)&__IJclExtendedSet; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclExtendedSet; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedSet; }
	
};


typedef TJclExtendedHashSet TJclFloatHashSet;
;

class DELPHICLASS TJclIntegerHashSet;
class PASCALIMPLEMENTATION TJclIntegerHashSet : public Jclabstractcontainers::TJclIntegerAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntegerAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
public:
	__fastcall TJclIntegerHashSet(int ACapacity)/* overload */;
	
private:
	Jclcontainerintf::_di_IJclIntegerMap FMap;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntegerHashSet(const Jclcontainerintf::_di_IJclIntegerMap AMap)/* overload */;
	__fastcall virtual ~TJclIntegerHashSet(void);
	virtual int __fastcall GetAutoPackParameter(void);
	virtual Jclcontainerintf::TJclAutoPackStrategy __fastcall GetAutoPackStrategy(void);
	virtual int __fastcall GetCapacity(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetAutoPackParameter(int Value);
	virtual void __fastcall SetAutoPackStrategy(Jclcontainerintf::TJclAutoPackStrategy Value);
	virtual void __fastcall SetCapacity(int Value);
	virtual bool __fastcall GetAllowDefaultElements(void);
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
	bool __fastcall Add(int AValue);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclIntegerCollection ACollection);
	void __fastcall Clear(void);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclIntegerCollection ACollection);
	bool __fastcall Contains(int AValue);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclIntegerCollection ACollection);
	bool __fastcall Extract(int AValue);
	bool __fastcall ExtractAll(const Jclcontainerintf::_di_IJclIntegerCollection ACollection);
	Jclcontainerintf::_di_IJclIntegerIterator __fastcall First();
	bool __fastcall IsEmpty(void);
	Jclcontainerintf::_di_IJclIntegerIterator __fastcall Last();
	bool __fastcall Remove(int AValue);
	bool __fastcall RemoveAll(const Jclcontainerintf::_di_IJclIntegerCollection ACollection);
	bool __fastcall RetainAll(const Jclcontainerintf::_di_IJclIntegerCollection ACollection);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclIntegerIterator __fastcall GetEnumerator();
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclIntegerCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclIntegerCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclIntegerCollection ACollection);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclIntegerEqualityComparer;	/* Jclcontainerintf::IJclIntegerEqualityComparer */
	void *__IJclIntegerSet;	/* Jclcontainerintf::IJclIntegerSet */
	
public:
	operator IJclIntegerSet*(void) { return (IJclIntegerSet*)&__IJclIntegerSet; }
	operator IJclIntegerCollection*(void) { return (IJclIntegerCollection*)&__IJclIntegerSet; }
	operator IJclIntegerEqualityComparer*(void) { return (IJclIntegerEqualityComparer*)&__IJclIntegerEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntegerSet; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerSet; }
	
};


class DELPHICLASS TJclCardinalHashSet;
class PASCALIMPLEMENTATION TJclCardinalHashSet : public Jclabstractcontainers::TJclCardinalAbstractContainer 
{
	typedef Jclabstractcontainers::TJclCardinalAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
public:
	__fastcall TJclCardinalHashSet(int ACapacity)/* overload */;
	
private:
	Jclcontainerintf::_di_IJclCardinalMap FMap;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclCardinalHashSet(const Jclcontainerintf::_di_IJclCardinalMap AMap)/* overload */;
	__fastcall virtual ~TJclCardinalHashSet(void);
	virtual int __fastcall GetAutoPackParameter(void);
	virtual Jclcontainerintf::TJclAutoPackStrategy __fastcall GetAutoPackStrategy(void);
	virtual int __fastcall GetCapacity(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetAutoPackParameter(int Value);
	virtual void __fastcall SetAutoPackStrategy(Jclcontainerintf::TJclAutoPackStrategy Value);
	virtual void __fastcall SetCapacity(int Value);
	virtual bool __fastcall GetAllowDefaultElements(void);
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
	bool __fastcall Add(unsigned AValue);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclCardinalCollection ACollection);
	void __fastcall Clear(void);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclCardinalCollection ACollection);
	bool __fastcall Contains(unsigned AValue);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclCardinalCollection ACollection);
	bool __fastcall Extract(unsigned AValue);
	bool __fastcall ExtractAll(const Jclcontainerintf::_di_IJclCardinalCollection ACollection);
	Jclcontainerintf::_di_IJclCardinalIterator __fastcall First();
	bool __fastcall IsEmpty(void);
	Jclcontainerintf::_di_IJclCardinalIterator __fastcall Last();
	bool __fastcall Remove(unsigned AValue);
	bool __fastcall RemoveAll(const Jclcontainerintf::_di_IJclCardinalCollection ACollection);
	bool __fastcall RetainAll(const Jclcontainerintf::_di_IJclCardinalCollection ACollection);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclCardinalIterator __fastcall GetEnumerator();
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclCardinalCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclCardinalCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclCardinalCollection ACollection);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclCardinalEqualityComparer;	/* Jclcontainerintf::IJclCardinalEqualityComparer */
	void *__IJclCardinalSet;	/* Jclcontainerintf::IJclCardinalSet */
	
public:
	operator IJclCardinalSet*(void) { return (IJclCardinalSet*)&__IJclCardinalSet; }
	operator IJclCardinalCollection*(void) { return (IJclCardinalCollection*)&__IJclCardinalSet; }
	operator IJclCardinalEqualityComparer*(void) { return (IJclCardinalEqualityComparer*)&__IJclCardinalEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclCardinalSet; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalSet; }
	
};


class DELPHICLASS TJclInt64HashSet;
class PASCALIMPLEMENTATION TJclInt64HashSet : public Jclabstractcontainers::TJclInt64AbstractContainer 
{
	typedef Jclabstractcontainers::TJclInt64AbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
public:
	__fastcall TJclInt64HashSet(int ACapacity)/* overload */;
	
private:
	Jclcontainerintf::_di_IJclInt64Map FMap;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclInt64HashSet(const Jclcontainerintf::_di_IJclInt64Map AMap)/* overload */;
	__fastcall virtual ~TJclInt64HashSet(void);
	virtual int __fastcall GetAutoPackParameter(void);
	virtual Jclcontainerintf::TJclAutoPackStrategy __fastcall GetAutoPackStrategy(void);
	virtual int __fastcall GetCapacity(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetAutoPackParameter(int Value);
	virtual void __fastcall SetAutoPackStrategy(Jclcontainerintf::TJclAutoPackStrategy Value);
	virtual void __fastcall SetCapacity(int Value);
	virtual bool __fastcall GetAllowDefaultElements(void);
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
	bool __fastcall Add(const __int64 AValue);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclInt64Collection ACollection);
	void __fastcall Clear(void);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclInt64Collection ACollection);
	bool __fastcall Contains(const __int64 AValue);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclInt64Collection ACollection);
	bool __fastcall Extract(const __int64 AValue);
	bool __fastcall ExtractAll(const Jclcontainerintf::_di_IJclInt64Collection ACollection);
	Jclcontainerintf::_di_IJclInt64Iterator __fastcall First();
	bool __fastcall IsEmpty(void);
	Jclcontainerintf::_di_IJclInt64Iterator __fastcall Last();
	bool __fastcall Remove(const __int64 AValue);
	bool __fastcall RemoveAll(const Jclcontainerintf::_di_IJclInt64Collection ACollection);
	bool __fastcall RetainAll(const Jclcontainerintf::_di_IJclInt64Collection ACollection);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclInt64Iterator __fastcall GetEnumerator();
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclInt64Collection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclInt64Collection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclInt64Collection ACollection);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclInt64EqualityComparer;	/* Jclcontainerintf::IJclInt64EqualityComparer */
	void *__IJclInt64Set;	/* Jclcontainerintf::IJclInt64Set */
	
public:
	operator IJclInt64Set*(void) { return (IJclInt64Set*)&__IJclInt64Set; }
	operator IJclInt64Collection*(void) { return (IJclInt64Collection*)&__IJclInt64Set; }
	operator IJclInt64EqualityComparer*(void) { return (IJclInt64EqualityComparer*)&__IJclInt64EqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclInt64Set; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64Set; }
	
};


class DELPHICLASS TJclPtrHashSet;
class PASCALIMPLEMENTATION TJclPtrHashSet : public Jclabstractcontainers::TJclPtrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclPtrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
public:
	__fastcall TJclPtrHashSet(int ACapacity)/* overload */;
	
private:
	Jclcontainerintf::_di_IJclPtrMap FMap;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclPtrHashSet(const Jclcontainerintf::_di_IJclPtrMap AMap)/* overload */;
	__fastcall virtual ~TJclPtrHashSet(void);
	virtual int __fastcall GetAutoPackParameter(void);
	virtual Jclcontainerintf::TJclAutoPackStrategy __fastcall GetAutoPackStrategy(void);
	virtual int __fastcall GetCapacity(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetAutoPackParameter(int Value);
	virtual void __fastcall SetAutoPackStrategy(Jclcontainerintf::TJclAutoPackStrategy Value);
	virtual void __fastcall SetCapacity(int Value);
	virtual bool __fastcall GetAllowDefaultElements(void);
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
	bool __fastcall Add(void * AValue);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	void __fastcall Clear(void);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	bool __fastcall Contains(void * AValue);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	bool __fastcall Extract(void * AValue);
	bool __fastcall ExtractAll(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	Jclcontainerintf::_di_IJclPtrIterator __fastcall First();
	bool __fastcall IsEmpty(void);
	Jclcontainerintf::_di_IJclPtrIterator __fastcall Last();
	bool __fastcall Remove(void * AValue);
	bool __fastcall RemoveAll(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	bool __fastcall RetainAll(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclPtrIterator __fastcall GetEnumerator();
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclPtrEqualityComparer;	/* Jclcontainerintf::IJclPtrEqualityComparer */
	void *__IJclPtrSet;	/* Jclcontainerintf::IJclPtrSet */
	
public:
	operator IJclPtrSet*(void) { return (IJclPtrSet*)&__IJclPtrSet; }
	operator IJclPtrCollection*(void) { return (IJclPtrCollection*)&__IJclPtrSet; }
	operator IJclPtrEqualityComparer*(void) { return (IJclPtrEqualityComparer*)&__IJclPtrEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclPtrSet; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrSet; }
	
};


class DELPHICLASS TJclHashSet;
class PASCALIMPLEMENTATION TJclHashSet : public Jclabstractcontainers::TJclAbstractContainer 
{
	typedef Jclabstractcontainers::TJclAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
public:
	__fastcall TJclHashSet(int ACapacity, bool AOwnsObjects)/* overload */;
	virtual System::TObject* __fastcall FreeObject(System::TObject* &AObject);
	virtual bool __fastcall GetOwnsObjects(void);
	
private:
	Jclcontainerintf::_di_IJclMap FMap;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclHashSet(const Jclcontainerintf::_di_IJclMap AMap)/* overload */;
	__fastcall virtual ~TJclHashSet(void);
	virtual int __fastcall GetAutoPackParameter(void);
	virtual Jclcontainerintf::TJclAutoPackStrategy __fastcall GetAutoPackStrategy(void);
	virtual int __fastcall GetCapacity(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetAutoPackParameter(int Value);
	virtual void __fastcall SetAutoPackStrategy(Jclcontainerintf::TJclAutoPackStrategy Value);
	virtual void __fastcall SetCapacity(int Value);
	virtual bool __fastcall GetAllowDefaultElements(void);
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
	bool __fastcall Add(System::TObject* AObject);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclCollection ACollection);
	void __fastcall Clear(void);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclCollection ACollection);
	bool __fastcall Contains(System::TObject* AObject);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclCollection ACollection);
	bool __fastcall Extract(System::TObject* AObject);
	bool __fastcall ExtractAll(const Jclcontainerintf::_di_IJclCollection ACollection);
	Jclcontainerintf::_di_IJclIterator __fastcall First();
	bool __fastcall IsEmpty(void);
	Jclcontainerintf::_di_IJclIterator __fastcall Last();
	bool __fastcall Remove(System::TObject* AObject);
	bool __fastcall RemoveAll(const Jclcontainerintf::_di_IJclCollection ACollection);
	bool __fastcall RetainAll(const Jclcontainerintf::_di_IJclCollection ACollection);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclIterator __fastcall GetEnumerator();
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclCollection ACollection);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclObjectOwner;	/* Jclcontainerintf::IJclObjectOwner */
	void *__IJclEqualityComparer;	/* Jclcontainerintf::IJclEqualityComparer */
	void *__IJclSet;	/* Jclcontainerintf::IJclSet */
	
public:
	operator IJclSet*(void) { return (IJclSet*)&__IJclSet; }
	operator IJclCollection*(void) { return (IJclCollection*)&__IJclSet; }
	operator IJclEqualityComparer*(void) { return (IJclEqualityComparer*)&__IJclEqualityComparer; }
	operator IJclObjectOwner*(void) { return (IJclObjectOwner*)&__IJclObjectOwner; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclSet; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSet; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE System::TInterfacedObject* __fastcall RefUnique(void);
extern PACKAGE bool __fastcall EqualityCompareEqObjects(const System::TInterfacedObject* Obj1, const System::TInterfacedObject* Obj2);

}	/* namespace Jclhashsets */
using namespace Jclhashsets;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclhashsets
