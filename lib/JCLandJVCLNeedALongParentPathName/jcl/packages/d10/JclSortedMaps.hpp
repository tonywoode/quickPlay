// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclsortedmaps.pas' rev: 10.00

#ifndef JclsortedmapsHPP
#define JclsortedmapsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclsynch.hpp>	// Pascal unit
#include <Jclabstractcontainers.hpp>	// Pascal unit
#include <Jclcontainerintf.hpp>	// Pascal unit
#include <Jclarraylists.hpp>	// Pascal unit
#include <Jclarraysets.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclsortedmaps
{
//-- type declarations -------------------------------------------------------
struct TJclIntfIntfSortedEntry
{
	
public:
	System::_di_IInterface Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclIntfIntfSortedEntry >  JclSortedMaps__2;

class DELPHICLASS TJclIntfIntfSortedMap;
class PASCALIMPLEMENTATION TJclIntfIntfSortedMap : public Jclabstractcontainers::TJclIntfAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntfAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	int __fastcall KeysCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	int __fastcall ValuesCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclIntfIntfSortedEntry >  FEntries;
	int __fastcall BinarySearch(const System::_di_IInterface Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclIntfIntfSortedMap(int ACapacity);
	__fastcall virtual ~TJclIntfIntfSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const System::_di_IInterface Key);
	bool __fastcall ContainsValue(const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Extract(const System::_di_IInterface Key);
	System::_di_IInterface __fastcall GetValue(const System::_di_IInterface Key);
	bool __fastcall IsEmpty(void);
	System::_di_IInterface __fastcall KeyOfValue(const System::_di_IInterface Value);
	Jclcontainerintf::_di_IJclIntfSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclIntfIntfMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclIntfIntfMap AMap);
	void __fastcall PutValue(const System::_di_IInterface Key, const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Remove(const System::_di_IInterface Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclIntfCollection __fastcall Values();
	System::_di_IInterface __fastcall FirstKey();
	Jclcontainerintf::_di_IJclIntfIntfSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey);
	System::_di_IInterface __fastcall LastKey();
	Jclcontainerintf::_di_IJclIntfIntfSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey);
	Jclcontainerintf::_di_IJclIntfIntfSortedMap __fastcall TailMap(const System::_di_IInterface FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfIntfSortedMap;	/* Jclcontainerintf::IJclIntfIntfSortedMap */
	
public:
	operator IJclIntfIntfSortedMap*(void) { return (IJclIntfIntfSortedMap*)&__IJclIntfIntfSortedMap; }
	operator IJclIntfIntfMap*(void) { return (IJclIntfIntfMap*)&__IJclIntfIntfSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfIntfSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfIntfSortedMap; }
	
};


struct TJclAnsiStrIntfSortedEntry
{
	
public:
	AnsiString Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclAnsiStrIntfSortedEntry >  JclSortedMaps__4;

class DELPHICLASS TJclAnsiStrIntfSortedMap;
class PASCALIMPLEMENTATION TJclAnsiStrIntfSortedMap : public Jclabstractcontainers::TJclAnsiStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclAnsiStrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	AnsiString __fastcall FreeKey(AnsiString &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	int __fastcall KeysCompare(const AnsiString A, const AnsiString B);
	int __fastcall ValuesCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclAnsiStrIntfSortedEntry >  FEntries;
	int __fastcall BinarySearch(const AnsiString Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclAnsiStrIntfSortedMap(int ACapacity);
	__fastcall virtual ~TJclAnsiStrIntfSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const AnsiString Key);
	bool __fastcall ContainsValue(const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Extract(const AnsiString Key);
	System::_di_IInterface __fastcall GetValue(const AnsiString Key);
	bool __fastcall IsEmpty(void);
	AnsiString __fastcall KeyOfValue(const System::_di_IInterface Value);
	Jclcontainerintf::_di_IJclAnsiStrSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclAnsiStrIntfMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclAnsiStrIntfMap AMap);
	void __fastcall PutValue(const AnsiString Key, const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Remove(const AnsiString Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclIntfCollection __fastcall Values();
	AnsiString __fastcall FirstKey();
	Jclcontainerintf::_di_IJclAnsiStrIntfSortedMap __fastcall HeadMap(const AnsiString ToKey);
	AnsiString __fastcall LastKey();
	Jclcontainerintf::_di_IJclAnsiStrIntfSortedMap __fastcall SubMap(const AnsiString FromKey, const AnsiString ToKey);
	Jclcontainerintf::_di_IJclAnsiStrIntfSortedMap __fastcall TailMap(const AnsiString FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclAnsiStrIntfSortedMap;	/* Jclcontainerintf::IJclAnsiStrIntfSortedMap */
	
public:
	operator IJclAnsiStrIntfSortedMap*(void) { return (IJclAnsiStrIntfSortedMap*)&__IJclAnsiStrIntfSortedMap; }
	operator IJclAnsiStrIntfMap*(void) { return (IJclAnsiStrIntfMap*)&__IJclAnsiStrIntfSortedMap; }
	operator IJclAnsiStrContainer*(void) { return (IJclAnsiStrContainer*)&__IJclAnsiStrIntfSortedMap; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclAnsiStrIntfSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclAnsiStrIntfSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrIntfSortedMap; }
	
};


struct TJclIntfAnsiStrSortedEntry
{
	
public:
	System::_di_IInterface Key;
	AnsiString Value;
} ;

typedef DynamicArray<TJclIntfAnsiStrSortedEntry >  JclSortedMaps__6;

class DELPHICLASS TJclIntfAnsiStrSortedMap;
class PASCALIMPLEMENTATION TJclIntfAnsiStrSortedMap : public Jclabstractcontainers::TJclAnsiStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclAnsiStrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	AnsiString __fastcall FreeValue(AnsiString &Value);
	int __fastcall KeysCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	int __fastcall ValuesCompare(const AnsiString A, const AnsiString B);
	
private:
	DynamicArray<TJclIntfAnsiStrSortedEntry >  FEntries;
	int __fastcall BinarySearch(const System::_di_IInterface Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclIntfAnsiStrSortedMap(int ACapacity);
	__fastcall virtual ~TJclIntfAnsiStrSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const System::_di_IInterface Key);
	bool __fastcall ContainsValue(const AnsiString Value);
	AnsiString __fastcall Extract(const System::_di_IInterface Key);
	AnsiString __fastcall GetValue(const System::_di_IInterface Key);
	bool __fastcall IsEmpty(void);
	System::_di_IInterface __fastcall KeyOfValue(const AnsiString Value);
	Jclcontainerintf::_di_IJclIntfSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclIntfAnsiStrMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclIntfAnsiStrMap AMap);
	void __fastcall PutValue(const System::_di_IInterface Key, const AnsiString Value);
	AnsiString __fastcall Remove(const System::_di_IInterface Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclAnsiStrCollection __fastcall Values();
	System::_di_IInterface __fastcall FirstKey();
	Jclcontainerintf::_di_IJclIntfAnsiStrSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey);
	System::_di_IInterface __fastcall LastKey();
	Jclcontainerintf::_di_IJclIntfAnsiStrSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey);
	Jclcontainerintf::_di_IJclIntfAnsiStrSortedMap __fastcall TailMap(const System::_di_IInterface FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfAnsiStrSortedMap;	/* Jclcontainerintf::IJclIntfAnsiStrSortedMap */
	
public:
	operator IJclIntfAnsiStrSortedMap*(void) { return (IJclIntfAnsiStrSortedMap*)&__IJclIntfAnsiStrSortedMap; }
	operator IJclIntfAnsiStrMap*(void) { return (IJclIntfAnsiStrMap*)&__IJclIntfAnsiStrSortedMap; }
	operator IJclAnsiStrContainer*(void) { return (IJclAnsiStrContainer*)&__IJclIntfAnsiStrSortedMap; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclIntfAnsiStrSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfAnsiStrSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfAnsiStrSortedMap; }
	
};


struct TJclAnsiStrAnsiStrSortedEntry
{
	
public:
	AnsiString Key;
	AnsiString Value;
} ;

typedef DynamicArray<TJclAnsiStrAnsiStrSortedEntry >  JclSortedMaps__8;

class DELPHICLASS TJclAnsiStrAnsiStrSortedMap;
class PASCALIMPLEMENTATION TJclAnsiStrAnsiStrSortedMap : public Jclabstractcontainers::TJclAnsiStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclAnsiStrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	AnsiString __fastcall FreeKey(AnsiString &Key);
	AnsiString __fastcall FreeValue(AnsiString &Value);
	int __fastcall KeysCompare(const AnsiString A, const AnsiString B);
	int __fastcall ValuesCompare(const AnsiString A, const AnsiString B);
	
private:
	DynamicArray<TJclAnsiStrAnsiStrSortedEntry >  FEntries;
	int __fastcall BinarySearch(const AnsiString Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclAnsiStrAnsiStrSortedMap(int ACapacity);
	__fastcall virtual ~TJclAnsiStrAnsiStrSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const AnsiString Key);
	bool __fastcall ContainsValue(const AnsiString Value);
	AnsiString __fastcall Extract(const AnsiString Key);
	AnsiString __fastcall GetValue(const AnsiString Key);
	bool __fastcall IsEmpty(void);
	AnsiString __fastcall KeyOfValue(const AnsiString Value);
	Jclcontainerintf::_di_IJclAnsiStrSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclAnsiStrAnsiStrMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclAnsiStrAnsiStrMap AMap);
	void __fastcall PutValue(const AnsiString Key, const AnsiString Value);
	AnsiString __fastcall Remove(const AnsiString Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclAnsiStrCollection __fastcall Values();
	AnsiString __fastcall FirstKey();
	Jclcontainerintf::_di_IJclAnsiStrAnsiStrSortedMap __fastcall HeadMap(const AnsiString ToKey);
	AnsiString __fastcall LastKey();
	Jclcontainerintf::_di_IJclAnsiStrAnsiStrSortedMap __fastcall SubMap(const AnsiString FromKey, const AnsiString ToKey);
	Jclcontainerintf::_di_IJclAnsiStrAnsiStrSortedMap __fastcall TailMap(const AnsiString FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclAnsiStrAnsiStrSortedMap;	/* Jclcontainerintf::IJclAnsiStrAnsiStrSortedMap */
	
public:
	operator IJclAnsiStrAnsiStrSortedMap*(void) { return (IJclAnsiStrAnsiStrSortedMap*)&__IJclAnsiStrAnsiStrSortedMap; }
	operator IJclAnsiStrAnsiStrMap*(void) { return (IJclAnsiStrAnsiStrMap*)&__IJclAnsiStrAnsiStrSortedMap; }
	operator IJclAnsiStrContainer*(void) { return (IJclAnsiStrContainer*)&__IJclAnsiStrAnsiStrSortedMap; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclAnsiStrAnsiStrSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclAnsiStrAnsiStrSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrAnsiStrSortedMap; }
	
};


struct TJclWideStrIntfSortedEntry
{
	
public:
	WideString Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclWideStrIntfSortedEntry >  JclSortedMaps__01;

class DELPHICLASS TJclWideStrIntfSortedMap;
class PASCALIMPLEMENTATION TJclWideStrIntfSortedMap : public Jclabstractcontainers::TJclWideStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclWideStrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	WideString __fastcall FreeKey(WideString &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	int __fastcall KeysCompare(const WideString A, const WideString B);
	int __fastcall ValuesCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclWideStrIntfSortedEntry >  FEntries;
	int __fastcall BinarySearch(const WideString Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclWideStrIntfSortedMap(int ACapacity);
	__fastcall virtual ~TJclWideStrIntfSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const WideString Key);
	bool __fastcall ContainsValue(const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Extract(const WideString Key);
	System::_di_IInterface __fastcall GetValue(const WideString Key);
	bool __fastcall IsEmpty(void);
	WideString __fastcall KeyOfValue(const System::_di_IInterface Value);
	Jclcontainerintf::_di_IJclWideStrSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclWideStrIntfMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclWideStrIntfMap AMap);
	void __fastcall PutValue(const WideString Key, const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Remove(const WideString Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclIntfCollection __fastcall Values();
	WideString __fastcall FirstKey();
	Jclcontainerintf::_di_IJclWideStrIntfSortedMap __fastcall HeadMap(const WideString ToKey);
	WideString __fastcall LastKey();
	Jclcontainerintf::_di_IJclWideStrIntfSortedMap __fastcall SubMap(const WideString FromKey, const WideString ToKey);
	Jclcontainerintf::_di_IJclWideStrIntfSortedMap __fastcall TailMap(const WideString FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclWideStrIntfSortedMap;	/* Jclcontainerintf::IJclWideStrIntfSortedMap */
	
public:
	operator IJclWideStrIntfSortedMap*(void) { return (IJclWideStrIntfSortedMap*)&__IJclWideStrIntfSortedMap; }
	operator IJclWideStrIntfMap*(void) { return (IJclWideStrIntfMap*)&__IJclWideStrIntfSortedMap; }
	operator IJclWideStrContainer*(void) { return (IJclWideStrContainer*)&__IJclWideStrIntfSortedMap; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclWideStrIntfSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclWideStrIntfSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrIntfSortedMap; }
	
};


struct TJclIntfWideStrSortedEntry
{
	
public:
	System::_di_IInterface Key;
	WideString Value;
} ;

typedef DynamicArray<TJclIntfWideStrSortedEntry >  JclSortedMaps__21;

class DELPHICLASS TJclIntfWideStrSortedMap;
class PASCALIMPLEMENTATION TJclIntfWideStrSortedMap : public Jclabstractcontainers::TJclWideStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclWideStrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	WideString __fastcall FreeValue(WideString &Value);
	int __fastcall KeysCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	int __fastcall ValuesCompare(const WideString A, const WideString B);
	
private:
	DynamicArray<TJclIntfWideStrSortedEntry >  FEntries;
	int __fastcall BinarySearch(const System::_di_IInterface Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclIntfWideStrSortedMap(int ACapacity);
	__fastcall virtual ~TJclIntfWideStrSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const System::_di_IInterface Key);
	bool __fastcall ContainsValue(const WideString Value);
	WideString __fastcall Extract(const System::_di_IInterface Key);
	WideString __fastcall GetValue(const System::_di_IInterface Key);
	bool __fastcall IsEmpty(void);
	System::_di_IInterface __fastcall KeyOfValue(const WideString Value);
	Jclcontainerintf::_di_IJclIntfSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclIntfWideStrMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclIntfWideStrMap AMap);
	void __fastcall PutValue(const System::_di_IInterface Key, const WideString Value);
	WideString __fastcall Remove(const System::_di_IInterface Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclWideStrCollection __fastcall Values();
	System::_di_IInterface __fastcall FirstKey();
	Jclcontainerintf::_di_IJclIntfWideStrSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey);
	System::_di_IInterface __fastcall LastKey();
	Jclcontainerintf::_di_IJclIntfWideStrSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey);
	Jclcontainerintf::_di_IJclIntfWideStrSortedMap __fastcall TailMap(const System::_di_IInterface FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfWideStrSortedMap;	/* Jclcontainerintf::IJclIntfWideStrSortedMap */
	
public:
	operator IJclIntfWideStrSortedMap*(void) { return (IJclIntfWideStrSortedMap*)&__IJclIntfWideStrSortedMap; }
	operator IJclIntfWideStrMap*(void) { return (IJclIntfWideStrMap*)&__IJclIntfWideStrSortedMap; }
	operator IJclWideStrContainer*(void) { return (IJclWideStrContainer*)&__IJclIntfWideStrSortedMap; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclIntfWideStrSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfWideStrSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfWideStrSortedMap; }
	
};


struct TJclWideStrWideStrSortedEntry
{
	
public:
	WideString Key;
	WideString Value;
} ;

typedef DynamicArray<TJclWideStrWideStrSortedEntry >  JclSortedMaps__41;

class DELPHICLASS TJclWideStrWideStrSortedMap;
class PASCALIMPLEMENTATION TJclWideStrWideStrSortedMap : public Jclabstractcontainers::TJclWideStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclWideStrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	WideString __fastcall FreeKey(WideString &Key);
	WideString __fastcall FreeValue(WideString &Value);
	int __fastcall KeysCompare(const WideString A, const WideString B);
	int __fastcall ValuesCompare(const WideString A, const WideString B);
	
private:
	DynamicArray<TJclWideStrWideStrSortedEntry >  FEntries;
	int __fastcall BinarySearch(const WideString Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclWideStrWideStrSortedMap(int ACapacity);
	__fastcall virtual ~TJclWideStrWideStrSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const WideString Key);
	bool __fastcall ContainsValue(const WideString Value);
	WideString __fastcall Extract(const WideString Key);
	WideString __fastcall GetValue(const WideString Key);
	bool __fastcall IsEmpty(void);
	WideString __fastcall KeyOfValue(const WideString Value);
	Jclcontainerintf::_di_IJclWideStrSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclWideStrWideStrMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclWideStrWideStrMap AMap);
	void __fastcall PutValue(const WideString Key, const WideString Value);
	WideString __fastcall Remove(const WideString Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclWideStrCollection __fastcall Values();
	WideString __fastcall FirstKey();
	Jclcontainerintf::_di_IJclWideStrWideStrSortedMap __fastcall HeadMap(const WideString ToKey);
	WideString __fastcall LastKey();
	Jclcontainerintf::_di_IJclWideStrWideStrSortedMap __fastcall SubMap(const WideString FromKey, const WideString ToKey);
	Jclcontainerintf::_di_IJclWideStrWideStrSortedMap __fastcall TailMap(const WideString FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclWideStrWideStrSortedMap;	/* Jclcontainerintf::IJclWideStrWideStrSortedMap */
	
public:
	operator IJclWideStrWideStrSortedMap*(void) { return (IJclWideStrWideStrSortedMap*)&__IJclWideStrWideStrSortedMap; }
	operator IJclWideStrWideStrMap*(void) { return (IJclWideStrWideStrMap*)&__IJclWideStrWideStrSortedMap; }
	operator IJclWideStrContainer*(void) { return (IJclWideStrContainer*)&__IJclWideStrWideStrSortedMap; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclWideStrWideStrSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclWideStrWideStrSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrWideStrSortedMap; }
	
};


typedef TJclAnsiStrIntfSortedMap TJclStrIntfSortedMap;
;

typedef TJclIntfAnsiStrSortedMap TJclIntfStrSortedMap;
;

typedef TJclAnsiStrAnsiStrSortedMap TJclStrStrSortedMap;
;

struct TJclSingleIntfSortedEntry
{
	
public:
	float Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclSingleIntfSortedEntry >  JclSortedMaps__61;

class DELPHICLASS TJclSingleIntfSortedMap;
class PASCALIMPLEMENTATION TJclSingleIntfSortedMap : public Jclabstractcontainers::TJclSingleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclSingleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	float __fastcall FreeKey(float &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	int __fastcall KeysCompare(const float A, const float B);
	int __fastcall ValuesCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclSingleIntfSortedEntry >  FEntries;
	int __fastcall BinarySearch(const float Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclSingleIntfSortedMap(int ACapacity);
	__fastcall virtual ~TJclSingleIntfSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const float Key);
	bool __fastcall ContainsValue(const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Extract(const float Key);
	System::_di_IInterface __fastcall GetValue(const float Key);
	bool __fastcall IsEmpty(void);
	float __fastcall KeyOfValue(const System::_di_IInterface Value);
	Jclcontainerintf::_di_IJclSingleSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclSingleIntfMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclSingleIntfMap AMap);
	void __fastcall PutValue(const float Key, const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Remove(const float Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclIntfCollection __fastcall Values();
	float __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclSingleIntfSortedMap __fastcall HeadMap(const float ToKey);
	float __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclSingleIntfSortedMap __fastcall SubMap(const float FromKey, const float ToKey);
	Jclcontainerintf::_di_IJclSingleIntfSortedMap __fastcall TailMap(const float FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclSingleIntfSortedMap;	/* Jclcontainerintf::IJclSingleIntfSortedMap */
	
public:
	operator IJclSingleIntfSortedMap*(void) { return (IJclSingleIntfSortedMap*)&__IJclSingleIntfSortedMap; }
	operator IJclSingleIntfMap*(void) { return (IJclSingleIntfMap*)&__IJclSingleIntfSortedMap; }
	operator IJclSingleContainer*(void) { return (IJclSingleContainer*)&__IJclSingleIntfSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclSingleIntfSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleIntfSortedMap; }
	
};


struct TJclIntfSingleSortedEntry
{
	
public:
	System::_di_IInterface Key;
	float Value;
} ;

typedef DynamicArray<TJclIntfSingleSortedEntry >  JclSortedMaps__81;

class DELPHICLASS TJclIntfSingleSortedMap;
class PASCALIMPLEMENTATION TJclIntfSingleSortedMap : public Jclabstractcontainers::TJclSingleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclSingleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	float __fastcall FreeValue(float &Value);
	int __fastcall KeysCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	int __fastcall ValuesCompare(const float A, const float B);
	
private:
	DynamicArray<TJclIntfSingleSortedEntry >  FEntries;
	int __fastcall BinarySearch(const System::_di_IInterface Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclIntfSingleSortedMap(int ACapacity);
	__fastcall virtual ~TJclIntfSingleSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const System::_di_IInterface Key);
	bool __fastcall ContainsValue(const float Value);
	float __fastcall Extract(const System::_di_IInterface Key);
	float __fastcall GetValue(const System::_di_IInterface Key);
	bool __fastcall IsEmpty(void);
	System::_di_IInterface __fastcall KeyOfValue(const float Value);
	Jclcontainerintf::_di_IJclIntfSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclIntfSingleMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclIntfSingleMap AMap);
	void __fastcall PutValue(const System::_di_IInterface Key, const float Value);
	float __fastcall Remove(const System::_di_IInterface Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclSingleCollection __fastcall Values();
	System::_di_IInterface __fastcall FirstKey();
	Jclcontainerintf::_di_IJclIntfSingleSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey);
	System::_di_IInterface __fastcall LastKey();
	Jclcontainerintf::_di_IJclIntfSingleSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey);
	Jclcontainerintf::_di_IJclIntfSingleSortedMap __fastcall TailMap(const System::_di_IInterface FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfSingleSortedMap;	/* Jclcontainerintf::IJclIntfSingleSortedMap */
	
public:
	operator IJclIntfSingleSortedMap*(void) { return (IJclIntfSingleSortedMap*)&__IJclIntfSingleSortedMap; }
	operator IJclIntfSingleMap*(void) { return (IJclIntfSingleMap*)&__IJclIntfSingleSortedMap; }
	operator IJclSingleContainer*(void) { return (IJclSingleContainer*)&__IJclIntfSingleSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfSingleSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfSingleSortedMap; }
	
};


struct TJclSingleSingleSortedEntry
{
	
public:
	float Key;
	float Value;
} ;

typedef DynamicArray<TJclSingleSingleSortedEntry >  JclSortedMaps__02;

class DELPHICLASS TJclSingleSingleSortedMap;
class PASCALIMPLEMENTATION TJclSingleSingleSortedMap : public Jclabstractcontainers::TJclSingleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclSingleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	float __fastcall FreeKey(float &Key);
	float __fastcall FreeValue(float &Value);
	int __fastcall KeysCompare(const float A, const float B);
	int __fastcall ValuesCompare(const float A, const float B);
	
private:
	DynamicArray<TJclSingleSingleSortedEntry >  FEntries;
	int __fastcall BinarySearch(const float Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclSingleSingleSortedMap(int ACapacity);
	__fastcall virtual ~TJclSingleSingleSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const float Key);
	bool __fastcall ContainsValue(const float Value);
	float __fastcall Extract(const float Key);
	float __fastcall GetValue(const float Key);
	bool __fastcall IsEmpty(void);
	float __fastcall KeyOfValue(const float Value);
	Jclcontainerintf::_di_IJclSingleSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclSingleSingleMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclSingleSingleMap AMap);
	void __fastcall PutValue(const float Key, const float Value);
	float __fastcall Remove(const float Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclSingleCollection __fastcall Values();
	float __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclSingleSingleSortedMap __fastcall HeadMap(const float ToKey);
	float __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclSingleSingleSortedMap __fastcall SubMap(const float FromKey, const float ToKey);
	Jclcontainerintf::_di_IJclSingleSingleSortedMap __fastcall TailMap(const float FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclSingleSingleSortedMap;	/* Jclcontainerintf::IJclSingleSingleSortedMap */
	
public:
	operator IJclSingleSingleSortedMap*(void) { return (IJclSingleSingleSortedMap*)&__IJclSingleSingleSortedMap; }
	operator IJclSingleSingleMap*(void) { return (IJclSingleSingleMap*)&__IJclSingleSingleSortedMap; }
	operator IJclSingleContainer*(void) { return (IJclSingleContainer*)&__IJclSingleSingleSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclSingleSingleSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleSingleSortedMap; }
	
};


struct TJclDoubleIntfSortedEntry
{
	
public:
	double Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclDoubleIntfSortedEntry >  JclSortedMaps__22;

class DELPHICLASS TJclDoubleIntfSortedMap;
class PASCALIMPLEMENTATION TJclDoubleIntfSortedMap : public Jclabstractcontainers::TJclDoubleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclDoubleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	double __fastcall FreeKey(double &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	int __fastcall KeysCompare(const double A, const double B);
	int __fastcall ValuesCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclDoubleIntfSortedEntry >  FEntries;
	int __fastcall BinarySearch(const double Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclDoubleIntfSortedMap(int ACapacity);
	__fastcall virtual ~TJclDoubleIntfSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const double Key);
	bool __fastcall ContainsValue(const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Extract(const double Key);
	System::_di_IInterface __fastcall GetValue(const double Key);
	bool __fastcall IsEmpty(void);
	double __fastcall KeyOfValue(const System::_di_IInterface Value);
	Jclcontainerintf::_di_IJclDoubleSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclDoubleIntfMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclDoubleIntfMap AMap);
	void __fastcall PutValue(const double Key, const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Remove(const double Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclIntfCollection __fastcall Values();
	double __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclDoubleIntfSortedMap __fastcall HeadMap(const double ToKey);
	double __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclDoubleIntfSortedMap __fastcall SubMap(const double FromKey, const double ToKey);
	Jclcontainerintf::_di_IJclDoubleIntfSortedMap __fastcall TailMap(const double FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclDoubleIntfSortedMap;	/* Jclcontainerintf::IJclDoubleIntfSortedMap */
	
public:
	operator IJclDoubleIntfSortedMap*(void) { return (IJclDoubleIntfSortedMap*)&__IJclDoubleIntfSortedMap; }
	operator IJclDoubleIntfMap*(void) { return (IJclDoubleIntfMap*)&__IJclDoubleIntfSortedMap; }
	operator IJclDoubleContainer*(void) { return (IJclDoubleContainer*)&__IJclDoubleIntfSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclDoubleIntfSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleIntfSortedMap; }
	
};


struct TJclIntfDoubleSortedEntry
{
	
public:
	System::_di_IInterface Key;
	double Value;
} ;

typedef DynamicArray<TJclIntfDoubleSortedEntry >  JclSortedMaps__42;

class DELPHICLASS TJclIntfDoubleSortedMap;
class PASCALIMPLEMENTATION TJclIntfDoubleSortedMap : public Jclabstractcontainers::TJclDoubleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclDoubleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	double __fastcall FreeValue(double &Value);
	int __fastcall KeysCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	int __fastcall ValuesCompare(const double A, const double B);
	
private:
	DynamicArray<TJclIntfDoubleSortedEntry >  FEntries;
	int __fastcall BinarySearch(const System::_di_IInterface Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclIntfDoubleSortedMap(int ACapacity);
	__fastcall virtual ~TJclIntfDoubleSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const System::_di_IInterface Key);
	bool __fastcall ContainsValue(const double Value);
	double __fastcall Extract(const System::_di_IInterface Key);
	double __fastcall GetValue(const System::_di_IInterface Key);
	bool __fastcall IsEmpty(void);
	System::_di_IInterface __fastcall KeyOfValue(const double Value);
	Jclcontainerintf::_di_IJclIntfSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclIntfDoubleMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclIntfDoubleMap AMap);
	void __fastcall PutValue(const System::_di_IInterface Key, const double Value);
	double __fastcall Remove(const System::_di_IInterface Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclDoubleCollection __fastcall Values();
	System::_di_IInterface __fastcall FirstKey();
	Jclcontainerintf::_di_IJclIntfDoubleSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey);
	System::_di_IInterface __fastcall LastKey();
	Jclcontainerintf::_di_IJclIntfDoubleSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey);
	Jclcontainerintf::_di_IJclIntfDoubleSortedMap __fastcall TailMap(const System::_di_IInterface FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfDoubleSortedMap;	/* Jclcontainerintf::IJclIntfDoubleSortedMap */
	
public:
	operator IJclIntfDoubleSortedMap*(void) { return (IJclIntfDoubleSortedMap*)&__IJclIntfDoubleSortedMap; }
	operator IJclIntfDoubleMap*(void) { return (IJclIntfDoubleMap*)&__IJclIntfDoubleSortedMap; }
	operator IJclDoubleContainer*(void) { return (IJclDoubleContainer*)&__IJclIntfDoubleSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfDoubleSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfDoubleSortedMap; }
	
};


struct TJclDoubleDoubleSortedEntry
{
	
public:
	double Key;
	double Value;
} ;

typedef DynamicArray<TJclDoubleDoubleSortedEntry >  JclSortedMaps__62;

class DELPHICLASS TJclDoubleDoubleSortedMap;
class PASCALIMPLEMENTATION TJclDoubleDoubleSortedMap : public Jclabstractcontainers::TJclDoubleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclDoubleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	double __fastcall FreeKey(double &Key);
	double __fastcall FreeValue(double &Value);
	int __fastcall KeysCompare(const double A, const double B);
	int __fastcall ValuesCompare(const double A, const double B);
	
private:
	DynamicArray<TJclDoubleDoubleSortedEntry >  FEntries;
	int __fastcall BinarySearch(const double Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclDoubleDoubleSortedMap(int ACapacity);
	__fastcall virtual ~TJclDoubleDoubleSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const double Key);
	bool __fastcall ContainsValue(const double Value);
	double __fastcall Extract(const double Key);
	double __fastcall GetValue(const double Key);
	bool __fastcall IsEmpty(void);
	double __fastcall KeyOfValue(const double Value);
	Jclcontainerintf::_di_IJclDoubleSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclDoubleDoubleMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclDoubleDoubleMap AMap);
	void __fastcall PutValue(const double Key, const double Value);
	double __fastcall Remove(const double Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclDoubleCollection __fastcall Values();
	double __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclDoubleDoubleSortedMap __fastcall HeadMap(const double ToKey);
	double __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclDoubleDoubleSortedMap __fastcall SubMap(const double FromKey, const double ToKey);
	Jclcontainerintf::_di_IJclDoubleDoubleSortedMap __fastcall TailMap(const double FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclDoubleDoubleSortedMap;	/* Jclcontainerintf::IJclDoubleDoubleSortedMap */
	
public:
	operator IJclDoubleDoubleSortedMap*(void) { return (IJclDoubleDoubleSortedMap*)&__IJclDoubleDoubleSortedMap; }
	operator IJclDoubleDoubleMap*(void) { return (IJclDoubleDoubleMap*)&__IJclDoubleDoubleSortedMap; }
	operator IJclDoubleContainer*(void) { return (IJclDoubleContainer*)&__IJclDoubleDoubleSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclDoubleDoubleSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleDoubleSortedMap; }
	
};


struct TJclExtendedIntfSortedEntry
{
	
public:
	Extended Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclExtendedIntfSortedEntry >  JclSortedMaps__82;

class DELPHICLASS TJclExtendedIntfSortedMap;
class PASCALIMPLEMENTATION TJclExtendedIntfSortedMap : public Jclabstractcontainers::TJclExtendedAbstractContainer 
{
	typedef Jclabstractcontainers::TJclExtendedAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	Extended __fastcall FreeKey(Extended &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	int __fastcall KeysCompare(const Extended A, const Extended B);
	int __fastcall ValuesCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclExtendedIntfSortedEntry >  FEntries;
	int __fastcall BinarySearch(const Extended Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclExtendedIntfSortedMap(int ACapacity);
	__fastcall virtual ~TJclExtendedIntfSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const Extended Key);
	bool __fastcall ContainsValue(const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Extract(const Extended Key);
	System::_di_IInterface __fastcall GetValue(const Extended Key);
	bool __fastcall IsEmpty(void);
	Extended __fastcall KeyOfValue(const System::_di_IInterface Value);
	Jclcontainerintf::_di_IJclExtendedSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclExtendedIntfMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclExtendedIntfMap AMap);
	void __fastcall PutValue(const Extended Key, const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Remove(const Extended Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclIntfCollection __fastcall Values();
	Extended __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclExtendedIntfSortedMap __fastcall HeadMap(const Extended ToKey);
	Extended __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclExtendedIntfSortedMap __fastcall SubMap(const Extended FromKey, const Extended ToKey);
	Jclcontainerintf::_di_IJclExtendedIntfSortedMap __fastcall TailMap(const Extended FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclExtendedIntfSortedMap;	/* Jclcontainerintf::IJclExtendedIntfSortedMap */
	
public:
	operator IJclExtendedIntfSortedMap*(void) { return (IJclExtendedIntfSortedMap*)&__IJclExtendedIntfSortedMap; }
	operator IJclExtendedIntfMap*(void) { return (IJclExtendedIntfMap*)&__IJclExtendedIntfSortedMap; }
	operator IJclExtendedContainer*(void) { return (IJclExtendedContainer*)&__IJclExtendedIntfSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclExtendedIntfSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedIntfSortedMap; }
	
};


struct TJclIntfExtendedSortedEntry
{
	
public:
	System::_di_IInterface Key;
	Extended Value;
} ;

typedef DynamicArray<TJclIntfExtendedSortedEntry >  JclSortedMaps__03;

class DELPHICLASS TJclIntfExtendedSortedMap;
class PASCALIMPLEMENTATION TJclIntfExtendedSortedMap : public Jclabstractcontainers::TJclExtendedAbstractContainer 
{
	typedef Jclabstractcontainers::TJclExtendedAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	Extended __fastcall FreeValue(Extended &Value);
	int __fastcall KeysCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	int __fastcall ValuesCompare(const Extended A, const Extended B);
	
private:
	DynamicArray<TJclIntfExtendedSortedEntry >  FEntries;
	int __fastcall BinarySearch(const System::_di_IInterface Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclIntfExtendedSortedMap(int ACapacity);
	__fastcall virtual ~TJclIntfExtendedSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const System::_di_IInterface Key);
	bool __fastcall ContainsValue(const Extended Value);
	Extended __fastcall Extract(const System::_di_IInterface Key);
	Extended __fastcall GetValue(const System::_di_IInterface Key);
	bool __fastcall IsEmpty(void);
	System::_di_IInterface __fastcall KeyOfValue(const Extended Value);
	Jclcontainerintf::_di_IJclIntfSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclIntfExtendedMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclIntfExtendedMap AMap);
	void __fastcall PutValue(const System::_di_IInterface Key, const Extended Value);
	Extended __fastcall Remove(const System::_di_IInterface Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclExtendedCollection __fastcall Values();
	System::_di_IInterface __fastcall FirstKey();
	Jclcontainerintf::_di_IJclIntfExtendedSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey);
	System::_di_IInterface __fastcall LastKey();
	Jclcontainerintf::_di_IJclIntfExtendedSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey);
	Jclcontainerintf::_di_IJclIntfExtendedSortedMap __fastcall TailMap(const System::_di_IInterface FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfExtendedSortedMap;	/* Jclcontainerintf::IJclIntfExtendedSortedMap */
	
public:
	operator IJclIntfExtendedSortedMap*(void) { return (IJclIntfExtendedSortedMap*)&__IJclIntfExtendedSortedMap; }
	operator IJclIntfExtendedMap*(void) { return (IJclIntfExtendedMap*)&__IJclIntfExtendedSortedMap; }
	operator IJclExtendedContainer*(void) { return (IJclExtendedContainer*)&__IJclIntfExtendedSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfExtendedSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfExtendedSortedMap; }
	
};


struct TJclExtendedExtendedSortedEntry
{
	
public:
	Extended Key;
	Extended Value;
} ;

typedef DynamicArray<TJclExtendedExtendedSortedEntry >  JclSortedMaps__23;

class DELPHICLASS TJclExtendedExtendedSortedMap;
class PASCALIMPLEMENTATION TJclExtendedExtendedSortedMap : public Jclabstractcontainers::TJclExtendedAbstractContainer 
{
	typedef Jclabstractcontainers::TJclExtendedAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	Extended __fastcall FreeKey(Extended &Key);
	Extended __fastcall FreeValue(Extended &Value);
	int __fastcall KeysCompare(const Extended A, const Extended B);
	int __fastcall ValuesCompare(const Extended A, const Extended B);
	
private:
	DynamicArray<TJclExtendedExtendedSortedEntry >  FEntries;
	int __fastcall BinarySearch(const Extended Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclExtendedExtendedSortedMap(int ACapacity);
	__fastcall virtual ~TJclExtendedExtendedSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const Extended Key);
	bool __fastcall ContainsValue(const Extended Value);
	Extended __fastcall Extract(const Extended Key);
	Extended __fastcall GetValue(const Extended Key);
	bool __fastcall IsEmpty(void);
	Extended __fastcall KeyOfValue(const Extended Value);
	Jclcontainerintf::_di_IJclExtendedSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclExtendedExtendedMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclExtendedExtendedMap AMap);
	void __fastcall PutValue(const Extended Key, const Extended Value);
	Extended __fastcall Remove(const Extended Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclExtendedCollection __fastcall Values();
	Extended __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclExtendedExtendedSortedMap __fastcall HeadMap(const Extended ToKey);
	Extended __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclExtendedExtendedSortedMap __fastcall SubMap(const Extended FromKey, const Extended ToKey);
	Jclcontainerintf::_di_IJclExtendedExtendedSortedMap __fastcall TailMap(const Extended FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclExtendedExtendedSortedMap;	/* Jclcontainerintf::IJclExtendedExtendedSortedMap */
	
public:
	operator IJclExtendedExtendedSortedMap*(void) { return (IJclExtendedExtendedSortedMap*)&__IJclExtendedExtendedSortedMap; }
	operator IJclExtendedExtendedMap*(void) { return (IJclExtendedExtendedMap*)&__IJclExtendedExtendedSortedMap; }
	operator IJclExtendedContainer*(void) { return (IJclExtendedContainer*)&__IJclExtendedExtendedSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclExtendedExtendedSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedExtendedSortedMap; }
	
};


typedef TJclExtendedIntfSortedMap TJclFloatIntfSortedMap;
;

typedef TJclIntfExtendedSortedMap TJclIntfFloatSortedMap;
;

typedef TJclExtendedExtendedSortedMap TJclFloatFloatSortedMap;
;

struct TJclIntegerIntfSortedEntry
{
	
public:
	int Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclIntegerIntfSortedEntry >  JclSortedMaps__43;

class DELPHICLASS TJclIntegerIntfSortedMap;
class PASCALIMPLEMENTATION TJclIntegerIntfSortedMap : public Jclabstractcontainers::TJclIntegerAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntegerAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	int __fastcall FreeKey(int &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	int __fastcall KeysCompare(int A, int B);
	int __fastcall ValuesCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclIntegerIntfSortedEntry >  FEntries;
	int __fastcall BinarySearch(int Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclIntegerIntfSortedMap(int ACapacity);
	__fastcall virtual ~TJclIntegerIntfSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(int Key);
	bool __fastcall ContainsValue(const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Extract(int Key);
	System::_di_IInterface __fastcall GetValue(int Key);
	bool __fastcall IsEmpty(void);
	int __fastcall KeyOfValue(const System::_di_IInterface Value);
	Jclcontainerintf::_di_IJclIntegerSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclIntegerIntfMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclIntegerIntfMap AMap);
	void __fastcall PutValue(int Key, const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Remove(int Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclIntfCollection __fastcall Values();
	int __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclIntegerIntfSortedMap __fastcall HeadMap(int ToKey);
	int __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclIntegerIntfSortedMap __fastcall SubMap(int FromKey, int ToKey);
	Jclcontainerintf::_di_IJclIntegerIntfSortedMap __fastcall TailMap(int FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntegerIntfSortedMap;	/* Jclcontainerintf::IJclIntegerIntfSortedMap */
	
public:
	operator IJclIntegerIntfSortedMap*(void) { return (IJclIntegerIntfSortedMap*)&__IJclIntegerIntfSortedMap; }
	operator IJclIntegerIntfMap*(void) { return (IJclIntegerIntfMap*)&__IJclIntegerIntfSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntegerIntfSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerIntfSortedMap; }
	
};


struct TJclIntfIntegerSortedEntry
{
	
public:
	System::_di_IInterface Key;
	int Value;
} ;

typedef DynamicArray<TJclIntfIntegerSortedEntry >  JclSortedMaps__63;

class DELPHICLASS TJclIntfIntegerSortedMap;
class PASCALIMPLEMENTATION TJclIntfIntegerSortedMap : public Jclabstractcontainers::TJclIntegerAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntegerAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	int __fastcall FreeValue(int &Value);
	int __fastcall KeysCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	int __fastcall ValuesCompare(int A, int B);
	
private:
	DynamicArray<TJclIntfIntegerSortedEntry >  FEntries;
	int __fastcall BinarySearch(const System::_di_IInterface Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclIntfIntegerSortedMap(int ACapacity);
	__fastcall virtual ~TJclIntfIntegerSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const System::_di_IInterface Key);
	bool __fastcall ContainsValue(int Value);
	int __fastcall Extract(const System::_di_IInterface Key);
	int __fastcall GetValue(const System::_di_IInterface Key);
	bool __fastcall IsEmpty(void);
	System::_di_IInterface __fastcall KeyOfValue(int Value);
	Jclcontainerintf::_di_IJclIntfSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclIntfIntegerMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclIntfIntegerMap AMap);
	void __fastcall PutValue(const System::_di_IInterface Key, int Value);
	int __fastcall Remove(const System::_di_IInterface Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclIntegerCollection __fastcall Values();
	System::_di_IInterface __fastcall FirstKey();
	Jclcontainerintf::_di_IJclIntfIntegerSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey);
	System::_di_IInterface __fastcall LastKey();
	Jclcontainerintf::_di_IJclIntfIntegerSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey);
	Jclcontainerintf::_di_IJclIntfIntegerSortedMap __fastcall TailMap(const System::_di_IInterface FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfIntegerSortedMap;	/* Jclcontainerintf::IJclIntfIntegerSortedMap */
	
public:
	operator IJclIntfIntegerSortedMap*(void) { return (IJclIntfIntegerSortedMap*)&__IJclIntfIntegerSortedMap; }
	operator IJclIntfIntegerMap*(void) { return (IJclIntfIntegerMap*)&__IJclIntfIntegerSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfIntegerSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfIntegerSortedMap; }
	
};


struct TJclIntegerIntegerSortedEntry
{
	
public:
	int Key;
	int Value;
} ;

typedef DynamicArray<TJclIntegerIntegerSortedEntry >  JclSortedMaps__83;

class DELPHICLASS TJclIntegerIntegerSortedMap;
class PASCALIMPLEMENTATION TJclIntegerIntegerSortedMap : public Jclabstractcontainers::TJclIntegerAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntegerAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	int __fastcall FreeKey(int &Key);
	int __fastcall FreeValue(int &Value);
	int __fastcall KeysCompare(int A, int B);
	int __fastcall ValuesCompare(int A, int B);
	
private:
	DynamicArray<TJclIntegerIntegerSortedEntry >  FEntries;
	int __fastcall BinarySearch(int Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclIntegerIntegerSortedMap(int ACapacity);
	__fastcall virtual ~TJclIntegerIntegerSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(int Key);
	bool __fastcall ContainsValue(int Value);
	int __fastcall Extract(int Key);
	int __fastcall GetValue(int Key);
	bool __fastcall IsEmpty(void);
	int __fastcall KeyOfValue(int Value);
	Jclcontainerintf::_di_IJclIntegerSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclIntegerIntegerMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclIntegerIntegerMap AMap);
	void __fastcall PutValue(int Key, int Value);
	int __fastcall Remove(int Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclIntegerCollection __fastcall Values();
	int __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclIntegerIntegerSortedMap __fastcall HeadMap(int ToKey);
	int __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclIntegerIntegerSortedMap __fastcall SubMap(int FromKey, int ToKey);
	Jclcontainerintf::_di_IJclIntegerIntegerSortedMap __fastcall TailMap(int FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntegerIntegerSortedMap;	/* Jclcontainerintf::IJclIntegerIntegerSortedMap */
	
public:
	operator IJclIntegerIntegerSortedMap*(void) { return (IJclIntegerIntegerSortedMap*)&__IJclIntegerIntegerSortedMap; }
	operator IJclIntegerIntegerMap*(void) { return (IJclIntegerIntegerMap*)&__IJclIntegerIntegerSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntegerIntegerSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerIntegerSortedMap; }
	
};


struct TJclCardinalIntfSortedEntry
{
	
public:
	unsigned Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclCardinalIntfSortedEntry >  JclSortedMaps__04;

class DELPHICLASS TJclCardinalIntfSortedMap;
class PASCALIMPLEMENTATION TJclCardinalIntfSortedMap : public Jclabstractcontainers::TJclCardinalAbstractContainer 
{
	typedef Jclabstractcontainers::TJclCardinalAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	unsigned __fastcall FreeKey(unsigned &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	int __fastcall KeysCompare(unsigned A, unsigned B);
	int __fastcall ValuesCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclCardinalIntfSortedEntry >  FEntries;
	int __fastcall BinarySearch(unsigned Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclCardinalIntfSortedMap(int ACapacity);
	__fastcall virtual ~TJclCardinalIntfSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(unsigned Key);
	bool __fastcall ContainsValue(const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Extract(unsigned Key);
	System::_di_IInterface __fastcall GetValue(unsigned Key);
	bool __fastcall IsEmpty(void);
	unsigned __fastcall KeyOfValue(const System::_di_IInterface Value);
	Jclcontainerintf::_di_IJclCardinalSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclCardinalIntfMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclCardinalIntfMap AMap);
	void __fastcall PutValue(unsigned Key, const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Remove(unsigned Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclIntfCollection __fastcall Values();
	unsigned __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclCardinalIntfSortedMap __fastcall HeadMap(unsigned ToKey);
	unsigned __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclCardinalIntfSortedMap __fastcall SubMap(unsigned FromKey, unsigned ToKey);
	Jclcontainerintf::_di_IJclCardinalIntfSortedMap __fastcall TailMap(unsigned FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclCardinalIntfSortedMap;	/* Jclcontainerintf::IJclCardinalIntfSortedMap */
	
public:
	operator IJclCardinalIntfSortedMap*(void) { return (IJclCardinalIntfSortedMap*)&__IJclCardinalIntfSortedMap; }
	operator IJclCardinalIntfMap*(void) { return (IJclCardinalIntfMap*)&__IJclCardinalIntfSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclCardinalIntfSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalIntfSortedMap; }
	
};


struct TJclIntfCardinalSortedEntry
{
	
public:
	System::_di_IInterface Key;
	unsigned Value;
} ;

typedef DynamicArray<TJclIntfCardinalSortedEntry >  JclSortedMaps__24;

class DELPHICLASS TJclIntfCardinalSortedMap;
class PASCALIMPLEMENTATION TJclIntfCardinalSortedMap : public Jclabstractcontainers::TJclCardinalAbstractContainer 
{
	typedef Jclabstractcontainers::TJclCardinalAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	unsigned __fastcall FreeValue(unsigned &Value);
	int __fastcall KeysCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	int __fastcall ValuesCompare(unsigned A, unsigned B);
	
private:
	DynamicArray<TJclIntfCardinalSortedEntry >  FEntries;
	int __fastcall BinarySearch(const System::_di_IInterface Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclIntfCardinalSortedMap(int ACapacity);
	__fastcall virtual ~TJclIntfCardinalSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const System::_di_IInterface Key);
	bool __fastcall ContainsValue(unsigned Value);
	unsigned __fastcall Extract(const System::_di_IInterface Key);
	unsigned __fastcall GetValue(const System::_di_IInterface Key);
	bool __fastcall IsEmpty(void);
	System::_di_IInterface __fastcall KeyOfValue(unsigned Value);
	Jclcontainerintf::_di_IJclIntfSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclIntfCardinalMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclIntfCardinalMap AMap);
	void __fastcall PutValue(const System::_di_IInterface Key, unsigned Value);
	unsigned __fastcall Remove(const System::_di_IInterface Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclCardinalCollection __fastcall Values();
	System::_di_IInterface __fastcall FirstKey();
	Jclcontainerintf::_di_IJclIntfCardinalSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey);
	System::_di_IInterface __fastcall LastKey();
	Jclcontainerintf::_di_IJclIntfCardinalSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey);
	Jclcontainerintf::_di_IJclIntfCardinalSortedMap __fastcall TailMap(const System::_di_IInterface FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfCardinalSortedMap;	/* Jclcontainerintf::IJclIntfCardinalSortedMap */
	
public:
	operator IJclIntfCardinalSortedMap*(void) { return (IJclIntfCardinalSortedMap*)&__IJclIntfCardinalSortedMap; }
	operator IJclIntfCardinalMap*(void) { return (IJclIntfCardinalMap*)&__IJclIntfCardinalSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfCardinalSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfCardinalSortedMap; }
	
};


struct TJclCardinalCardinalSortedEntry
{
	
public:
	unsigned Key;
	unsigned Value;
} ;

typedef DynamicArray<TJclCardinalCardinalSortedEntry >  JclSortedMaps__44;

class DELPHICLASS TJclCardinalCardinalSortedMap;
class PASCALIMPLEMENTATION TJclCardinalCardinalSortedMap : public Jclabstractcontainers::TJclCardinalAbstractContainer 
{
	typedef Jclabstractcontainers::TJclCardinalAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	unsigned __fastcall FreeKey(unsigned &Key);
	unsigned __fastcall FreeValue(unsigned &Value);
	int __fastcall KeysCompare(unsigned A, unsigned B);
	int __fastcall ValuesCompare(unsigned A, unsigned B);
	
private:
	DynamicArray<TJclCardinalCardinalSortedEntry >  FEntries;
	int __fastcall BinarySearch(unsigned Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclCardinalCardinalSortedMap(int ACapacity);
	__fastcall virtual ~TJclCardinalCardinalSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(unsigned Key);
	bool __fastcall ContainsValue(unsigned Value);
	unsigned __fastcall Extract(unsigned Key);
	unsigned __fastcall GetValue(unsigned Key);
	bool __fastcall IsEmpty(void);
	unsigned __fastcall KeyOfValue(unsigned Value);
	Jclcontainerintf::_di_IJclCardinalSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclCardinalCardinalMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclCardinalCardinalMap AMap);
	void __fastcall PutValue(unsigned Key, unsigned Value);
	unsigned __fastcall Remove(unsigned Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclCardinalCollection __fastcall Values();
	unsigned __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclCardinalCardinalSortedMap __fastcall HeadMap(unsigned ToKey);
	unsigned __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclCardinalCardinalSortedMap __fastcall SubMap(unsigned FromKey, unsigned ToKey);
	Jclcontainerintf::_di_IJclCardinalCardinalSortedMap __fastcall TailMap(unsigned FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclCardinalCardinalSortedMap;	/* Jclcontainerintf::IJclCardinalCardinalSortedMap */
	
public:
	operator IJclCardinalCardinalSortedMap*(void) { return (IJclCardinalCardinalSortedMap*)&__IJclCardinalCardinalSortedMap; }
	operator IJclCardinalCardinalMap*(void) { return (IJclCardinalCardinalMap*)&__IJclCardinalCardinalSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclCardinalCardinalSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalCardinalSortedMap; }
	
};


struct TJclInt64IntfSortedEntry
{
	
public:
	__int64 Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclInt64IntfSortedEntry >  JclSortedMaps__64;

class DELPHICLASS TJclInt64IntfSortedMap;
class PASCALIMPLEMENTATION TJclInt64IntfSortedMap : public Jclabstractcontainers::TJclInt64AbstractContainer 
{
	typedef Jclabstractcontainers::TJclInt64AbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	__int64 __fastcall FreeKey(__int64 &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	int __fastcall KeysCompare(const __int64 A, const __int64 B);
	int __fastcall ValuesCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclInt64IntfSortedEntry >  FEntries;
	int __fastcall BinarySearch(const __int64 Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclInt64IntfSortedMap(int ACapacity);
	__fastcall virtual ~TJclInt64IntfSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const __int64 Key);
	bool __fastcall ContainsValue(const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Extract(const __int64 Key);
	System::_di_IInterface __fastcall GetValue(const __int64 Key);
	bool __fastcall IsEmpty(void);
	__int64 __fastcall KeyOfValue(const System::_di_IInterface Value);
	Jclcontainerintf::_di_IJclInt64Set __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclInt64IntfMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclInt64IntfMap AMap);
	void __fastcall PutValue(const __int64 Key, const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Remove(const __int64 Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclIntfCollection __fastcall Values();
	__int64 __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclInt64IntfSortedMap __fastcall HeadMap(const __int64 ToKey);
	__int64 __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclInt64IntfSortedMap __fastcall SubMap(const __int64 FromKey, const __int64 ToKey);
	Jclcontainerintf::_di_IJclInt64IntfSortedMap __fastcall TailMap(const __int64 FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclInt64IntfSortedMap;	/* Jclcontainerintf::IJclInt64IntfSortedMap */
	
public:
	operator IJclInt64IntfSortedMap*(void) { return (IJclInt64IntfSortedMap*)&__IJclInt64IntfSortedMap; }
	operator IJclInt64IntfMap*(void) { return (IJclInt64IntfMap*)&__IJclInt64IntfSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclInt64IntfSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64IntfSortedMap; }
	
};


struct TJclIntfInt64SortedEntry
{
	
public:
	System::_di_IInterface Key;
	__int64 Value;
} ;

typedef DynamicArray<TJclIntfInt64SortedEntry >  JclSortedMaps__84;

class DELPHICLASS TJclIntfInt64SortedMap;
class PASCALIMPLEMENTATION TJclIntfInt64SortedMap : public Jclabstractcontainers::TJclInt64AbstractContainer 
{
	typedef Jclabstractcontainers::TJclInt64AbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	__int64 __fastcall FreeValue(__int64 &Value);
	int __fastcall KeysCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	int __fastcall ValuesCompare(const __int64 A, const __int64 B);
	
private:
	DynamicArray<TJclIntfInt64SortedEntry >  FEntries;
	int __fastcall BinarySearch(const System::_di_IInterface Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclIntfInt64SortedMap(int ACapacity);
	__fastcall virtual ~TJclIntfInt64SortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const System::_di_IInterface Key);
	bool __fastcall ContainsValue(const __int64 Value);
	__int64 __fastcall Extract(const System::_di_IInterface Key);
	__int64 __fastcall GetValue(const System::_di_IInterface Key);
	bool __fastcall IsEmpty(void);
	System::_di_IInterface __fastcall KeyOfValue(const __int64 Value);
	Jclcontainerintf::_di_IJclIntfSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclIntfInt64Map AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclIntfInt64Map AMap);
	void __fastcall PutValue(const System::_di_IInterface Key, const __int64 Value);
	__int64 __fastcall Remove(const System::_di_IInterface Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclInt64Collection __fastcall Values();
	System::_di_IInterface __fastcall FirstKey();
	Jclcontainerintf::_di_IJclIntfInt64SortedMap __fastcall HeadMap(const System::_di_IInterface ToKey);
	System::_di_IInterface __fastcall LastKey();
	Jclcontainerintf::_di_IJclIntfInt64SortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey);
	Jclcontainerintf::_di_IJclIntfInt64SortedMap __fastcall TailMap(const System::_di_IInterface FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfInt64SortedMap;	/* Jclcontainerintf::IJclIntfInt64SortedMap */
	
public:
	operator IJclIntfInt64SortedMap*(void) { return (IJclIntfInt64SortedMap*)&__IJclIntfInt64SortedMap; }
	operator IJclIntfInt64Map*(void) { return (IJclIntfInt64Map*)&__IJclIntfInt64SortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfInt64SortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfInt64SortedMap; }
	
};


struct TJclInt64Int64SortedEntry
{
	
public:
	__int64 Key;
	__int64 Value;
} ;

typedef DynamicArray<TJclInt64Int64SortedEntry >  JclSortedMaps__05;

class DELPHICLASS TJclInt64Int64SortedMap;
class PASCALIMPLEMENTATION TJclInt64Int64SortedMap : public Jclabstractcontainers::TJclInt64AbstractContainer 
{
	typedef Jclabstractcontainers::TJclInt64AbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	__int64 __fastcall FreeKey(__int64 &Key);
	__int64 __fastcall FreeValue(__int64 &Value);
	int __fastcall KeysCompare(const __int64 A, const __int64 B);
	int __fastcall ValuesCompare(const __int64 A, const __int64 B);
	
private:
	DynamicArray<TJclInt64Int64SortedEntry >  FEntries;
	int __fastcall BinarySearch(const __int64 Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclInt64Int64SortedMap(int ACapacity);
	__fastcall virtual ~TJclInt64Int64SortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const __int64 Key);
	bool __fastcall ContainsValue(const __int64 Value);
	__int64 __fastcall Extract(const __int64 Key);
	__int64 __fastcall GetValue(const __int64 Key);
	bool __fastcall IsEmpty(void);
	__int64 __fastcall KeyOfValue(const __int64 Value);
	Jclcontainerintf::_di_IJclInt64Set __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclInt64Int64Map AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclInt64Int64Map AMap);
	void __fastcall PutValue(const __int64 Key, const __int64 Value);
	__int64 __fastcall Remove(const __int64 Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclInt64Collection __fastcall Values();
	__int64 __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclInt64Int64SortedMap __fastcall HeadMap(const __int64 ToKey);
	__int64 __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclInt64Int64SortedMap __fastcall SubMap(const __int64 FromKey, const __int64 ToKey);
	Jclcontainerintf::_di_IJclInt64Int64SortedMap __fastcall TailMap(const __int64 FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclInt64Int64SortedMap;	/* Jclcontainerintf::IJclInt64Int64SortedMap */
	
public:
	operator IJclInt64Int64SortedMap*(void) { return (IJclInt64Int64SortedMap*)&__IJclInt64Int64SortedMap; }
	operator IJclInt64Int64Map*(void) { return (IJclInt64Int64Map*)&__IJclInt64Int64SortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclInt64Int64SortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64Int64SortedMap; }
	
};


struct TJclPtrIntfSortedEntry
{
	
public:
	void *Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclPtrIntfSortedEntry >  JclSortedMaps__25;

class DELPHICLASS TJclPtrIntfSortedMap;
class PASCALIMPLEMENTATION TJclPtrIntfSortedMap : public Jclabstractcontainers::TJclPtrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclPtrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	void * __fastcall FreeKey(void * &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	int __fastcall KeysCompare(void * A, void * B);
	int __fastcall ValuesCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclPtrIntfSortedEntry >  FEntries;
	int __fastcall BinarySearch(void * Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclPtrIntfSortedMap(int ACapacity);
	__fastcall virtual ~TJclPtrIntfSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(void * Key);
	bool __fastcall ContainsValue(const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Extract(void * Key);
	System::_di_IInterface __fastcall GetValue(void * Key);
	bool __fastcall IsEmpty(void);
	void * __fastcall KeyOfValue(const System::_di_IInterface Value);
	Jclcontainerintf::_di_IJclPtrSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclPtrIntfMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclPtrIntfMap AMap);
	void __fastcall PutValue(void * Key, const System::_di_IInterface Value);
	System::_di_IInterface __fastcall Remove(void * Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclIntfCollection __fastcall Values();
	void * __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclPtrIntfSortedMap __fastcall HeadMap(void * ToKey);
	void * __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclPtrIntfSortedMap __fastcall SubMap(void * FromKey, void * ToKey);
	Jclcontainerintf::_di_IJclPtrIntfSortedMap __fastcall TailMap(void * FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclPtrIntfSortedMap;	/* Jclcontainerintf::IJclPtrIntfSortedMap */
	
public:
	operator IJclPtrIntfSortedMap*(void) { return (IJclPtrIntfSortedMap*)&__IJclPtrIntfSortedMap; }
	operator IJclPtrIntfMap*(void) { return (IJclPtrIntfMap*)&__IJclPtrIntfSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclPtrIntfSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrIntfSortedMap; }
	
};


struct TJclIntfPtrSortedEntry
{
	
public:
	System::_di_IInterface Key;
	void *Value;
} ;

typedef DynamicArray<TJclIntfPtrSortedEntry >  JclSortedMaps__45;

class DELPHICLASS TJclIntfPtrSortedMap;
class PASCALIMPLEMENTATION TJclIntfPtrSortedMap : public Jclabstractcontainers::TJclPtrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclPtrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	void * __fastcall FreeValue(void * &Value);
	int __fastcall KeysCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	int __fastcall ValuesCompare(void * A, void * B);
	
private:
	DynamicArray<TJclIntfPtrSortedEntry >  FEntries;
	int __fastcall BinarySearch(const System::_di_IInterface Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclIntfPtrSortedMap(int ACapacity);
	__fastcall virtual ~TJclIntfPtrSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const System::_di_IInterface Key);
	bool __fastcall ContainsValue(void * Value);
	void * __fastcall Extract(const System::_di_IInterface Key);
	void * __fastcall GetValue(const System::_di_IInterface Key);
	bool __fastcall IsEmpty(void);
	System::_di_IInterface __fastcall KeyOfValue(void * Value);
	Jclcontainerintf::_di_IJclIntfSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclIntfPtrMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclIntfPtrMap AMap);
	void __fastcall PutValue(const System::_di_IInterface Key, void * Value);
	void * __fastcall Remove(const System::_di_IInterface Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclPtrCollection __fastcall Values();
	System::_di_IInterface __fastcall FirstKey();
	Jclcontainerintf::_di_IJclIntfPtrSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey);
	System::_di_IInterface __fastcall LastKey();
	Jclcontainerintf::_di_IJclIntfPtrSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey);
	Jclcontainerintf::_di_IJclIntfPtrSortedMap __fastcall TailMap(const System::_di_IInterface FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfPtrSortedMap;	/* Jclcontainerintf::IJclIntfPtrSortedMap */
	
public:
	operator IJclIntfPtrSortedMap*(void) { return (IJclIntfPtrSortedMap*)&__IJclIntfPtrSortedMap; }
	operator IJclIntfPtrMap*(void) { return (IJclIntfPtrMap*)&__IJclIntfPtrSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfPtrSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfPtrSortedMap; }
	
};


struct TJclPtrPtrSortedEntry
{
	
public:
	void *Key;
	void *Value;
} ;

typedef DynamicArray<TJclPtrPtrSortedEntry >  JclSortedMaps__65;

class DELPHICLASS TJclPtrPtrSortedMap;
class PASCALIMPLEMENTATION TJclPtrPtrSortedMap : public Jclabstractcontainers::TJclPtrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclPtrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	void * __fastcall FreeKey(void * &Key);
	void * __fastcall FreeValue(void * &Value);
	int __fastcall KeysCompare(void * A, void * B);
	int __fastcall ValuesCompare(void * A, void * B);
	
private:
	DynamicArray<TJclPtrPtrSortedEntry >  FEntries;
	int __fastcall BinarySearch(void * Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclPtrPtrSortedMap(int ACapacity);
	__fastcall virtual ~TJclPtrPtrSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(void * Key);
	bool __fastcall ContainsValue(void * Value);
	void * __fastcall Extract(void * Key);
	void * __fastcall GetValue(void * Key);
	bool __fastcall IsEmpty(void);
	void * __fastcall KeyOfValue(void * Value);
	Jclcontainerintf::_di_IJclPtrSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclPtrPtrMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclPtrPtrMap AMap);
	void __fastcall PutValue(void * Key, void * Value);
	void * __fastcall Remove(void * Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclPtrCollection __fastcall Values();
	void * __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclPtrPtrSortedMap __fastcall HeadMap(void * ToKey);
	void * __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclPtrPtrSortedMap __fastcall SubMap(void * FromKey, void * ToKey);
	Jclcontainerintf::_di_IJclPtrPtrSortedMap __fastcall TailMap(void * FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclPtrPtrSortedMap;	/* Jclcontainerintf::IJclPtrPtrSortedMap */
	
public:
	operator IJclPtrPtrSortedMap*(void) { return (IJclPtrPtrSortedMap*)&__IJclPtrPtrSortedMap; }
	operator IJclPtrPtrMap*(void) { return (IJclPtrPtrMap*)&__IJclPtrPtrSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclPtrPtrSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrPtrSortedMap; }
	
};


struct TJclIntfSortedEntry
{
	
public:
	System::_di_IInterface Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclIntfSortedEntry >  JclSortedMaps__85;

class DELPHICLASS TJclIntfSortedMap;
class PASCALIMPLEMENTATION TJclIntfSortedMap : public Jclabstractcontainers::TJclIntfAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntfAbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	int __fastcall KeysCompare(const System::_di_IInterface A, const System::_di_IInterface B);
	int __fastcall ValuesCompare(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclIntfSortedEntry >  FEntries;
	int __fastcall BinarySearch(const System::_di_IInterface Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclIntfSortedMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclIntfSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const System::_di_IInterface Key);
	bool __fastcall ContainsValue(System::TObject* Value);
	System::TObject* __fastcall Extract(const System::_di_IInterface Key);
	System::TObject* __fastcall GetValue(const System::_di_IInterface Key);
	bool __fastcall IsEmpty(void);
	System::_di_IInterface __fastcall KeyOfValue(System::TObject* Value);
	Jclcontainerintf::_di_IJclIntfSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclIntfMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclIntfMap AMap);
	void __fastcall PutValue(const System::_di_IInterface Key, System::TObject* Value);
	System::TObject* __fastcall Remove(const System::_di_IInterface Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclCollection __fastcall Values();
	System::_di_IInterface __fastcall FirstKey();
	Jclcontainerintf::_di_IJclIntfSortedMap __fastcall HeadMap(const System::_di_IInterface ToKey);
	System::_di_IInterface __fastcall LastKey();
	Jclcontainerintf::_di_IJclIntfSortedMap __fastcall SubMap(const System::_di_IInterface FromKey, const System::_di_IInterface ToKey);
	Jclcontainerintf::_di_IJclIntfSortedMap __fastcall TailMap(const System::_di_IInterface FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclIntfSortedMap;	/* Jclcontainerintf::IJclIntfSortedMap */
	
public:
	operator IJclIntfSortedMap*(void) { return (IJclIntfSortedMap*)&__IJclIntfSortedMap; }
	operator IJclIntfMap*(void) { return (IJclIntfMap*)&__IJclIntfSortedMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfSortedMap; }
	
};


struct TJclAnsiStrSortedEntry
{
	
public:
	AnsiString Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclAnsiStrSortedEntry >  JclSortedMaps__06;

class DELPHICLASS TJclAnsiStrSortedMap;
class PASCALIMPLEMENTATION TJclAnsiStrSortedMap : public Jclabstractcontainers::TJclAnsiStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclAnsiStrAbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	AnsiString __fastcall FreeKey(AnsiString &Key);
	int __fastcall KeysCompare(const AnsiString A, const AnsiString B);
	int __fastcall ValuesCompare(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclAnsiStrSortedEntry >  FEntries;
	int __fastcall BinarySearch(const AnsiString Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclAnsiStrSortedMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclAnsiStrSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const AnsiString Key);
	bool __fastcall ContainsValue(System::TObject* Value);
	System::TObject* __fastcall Extract(const AnsiString Key);
	System::TObject* __fastcall GetValue(const AnsiString Key);
	bool __fastcall IsEmpty(void);
	AnsiString __fastcall KeyOfValue(System::TObject* Value);
	Jclcontainerintf::_di_IJclAnsiStrSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclAnsiStrMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclAnsiStrMap AMap);
	void __fastcall PutValue(const AnsiString Key, System::TObject* Value);
	System::TObject* __fastcall Remove(const AnsiString Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclCollection __fastcall Values();
	AnsiString __fastcall FirstKey();
	Jclcontainerintf::_di_IJclAnsiStrSortedMap __fastcall HeadMap(const AnsiString ToKey);
	AnsiString __fastcall LastKey();
	Jclcontainerintf::_di_IJclAnsiStrSortedMap __fastcall SubMap(const AnsiString FromKey, const AnsiString ToKey);
	Jclcontainerintf::_di_IJclAnsiStrSortedMap __fastcall TailMap(const AnsiString FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclAnsiStrSortedMap;	/* Jclcontainerintf::IJclAnsiStrSortedMap */
	
public:
	operator IJclAnsiStrSortedMap*(void) { return (IJclAnsiStrSortedMap*)&__IJclAnsiStrSortedMap; }
	operator IJclAnsiStrMap*(void) { return (IJclAnsiStrMap*)&__IJclAnsiStrSortedMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclAnsiStrContainer*(void) { return (IJclAnsiStrContainer*)&__IJclAnsiStrSortedMap; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclAnsiStrSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclAnsiStrSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrSortedMap; }
	
};


struct TJclWideStrSortedEntry
{
	
public:
	WideString Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclWideStrSortedEntry >  JclSortedMaps__26;

class DELPHICLASS TJclWideStrSortedMap;
class PASCALIMPLEMENTATION TJclWideStrSortedMap : public Jclabstractcontainers::TJclWideStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclWideStrAbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	WideString __fastcall FreeKey(WideString &Key);
	int __fastcall KeysCompare(const WideString A, const WideString B);
	int __fastcall ValuesCompare(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclWideStrSortedEntry >  FEntries;
	int __fastcall BinarySearch(const WideString Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclWideStrSortedMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclWideStrSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const WideString Key);
	bool __fastcall ContainsValue(System::TObject* Value);
	System::TObject* __fastcall Extract(const WideString Key);
	System::TObject* __fastcall GetValue(const WideString Key);
	bool __fastcall IsEmpty(void);
	WideString __fastcall KeyOfValue(System::TObject* Value);
	Jclcontainerintf::_di_IJclWideStrSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclWideStrMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclWideStrMap AMap);
	void __fastcall PutValue(const WideString Key, System::TObject* Value);
	System::TObject* __fastcall Remove(const WideString Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclCollection __fastcall Values();
	WideString __fastcall FirstKey();
	Jclcontainerintf::_di_IJclWideStrSortedMap __fastcall HeadMap(const WideString ToKey);
	WideString __fastcall LastKey();
	Jclcontainerintf::_di_IJclWideStrSortedMap __fastcall SubMap(const WideString FromKey, const WideString ToKey);
	Jclcontainerintf::_di_IJclWideStrSortedMap __fastcall TailMap(const WideString FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclWideStrSortedMap;	/* Jclcontainerintf::IJclWideStrSortedMap */
	
public:
	operator IJclWideStrSortedMap*(void) { return (IJclWideStrSortedMap*)&__IJclWideStrSortedMap; }
	operator IJclWideStrMap*(void) { return (IJclWideStrMap*)&__IJclWideStrSortedMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclWideStrContainer*(void) { return (IJclWideStrContainer*)&__IJclWideStrSortedMap; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclWideStrSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclWideStrSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrSortedMap; }
	
};


typedef TJclAnsiStrSortedMap TJclStrSortedMap;
;

struct TJclSingleSortedEntry
{
	
public:
	float Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclSingleSortedEntry >  JclSortedMaps__46;

class DELPHICLASS TJclSingleSortedMap;
class PASCALIMPLEMENTATION TJclSingleSortedMap : public Jclabstractcontainers::TJclSingleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclSingleAbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	float __fastcall FreeKey(float &Key);
	int __fastcall KeysCompare(const float A, const float B);
	int __fastcall ValuesCompare(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclSingleSortedEntry >  FEntries;
	int __fastcall BinarySearch(const float Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclSingleSortedMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclSingleSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const float Key);
	bool __fastcall ContainsValue(System::TObject* Value);
	System::TObject* __fastcall Extract(const float Key);
	System::TObject* __fastcall GetValue(const float Key);
	bool __fastcall IsEmpty(void);
	float __fastcall KeyOfValue(System::TObject* Value);
	Jclcontainerintf::_di_IJclSingleSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclSingleMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclSingleMap AMap);
	void __fastcall PutValue(const float Key, System::TObject* Value);
	System::TObject* __fastcall Remove(const float Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclCollection __fastcall Values();
	float __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclSingleSortedMap __fastcall HeadMap(const float ToKey);
	float __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclSingleSortedMap __fastcall SubMap(const float FromKey, const float ToKey);
	Jclcontainerintf::_di_IJclSingleSortedMap __fastcall TailMap(const float FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclSingleSortedMap;	/* Jclcontainerintf::IJclSingleSortedMap */
	
public:
	operator IJclSingleSortedMap*(void) { return (IJclSingleSortedMap*)&__IJclSingleSortedMap; }
	operator IJclSingleMap*(void) { return (IJclSingleMap*)&__IJclSingleSortedMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclSingleContainer*(void) { return (IJclSingleContainer*)&__IJclSingleSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclSingleSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleSortedMap; }
	
};


struct TJclDoubleSortedEntry
{
	
public:
	double Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclDoubleSortedEntry >  JclSortedMaps__66;

class DELPHICLASS TJclDoubleSortedMap;
class PASCALIMPLEMENTATION TJclDoubleSortedMap : public Jclabstractcontainers::TJclDoubleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclDoubleAbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	double __fastcall FreeKey(double &Key);
	int __fastcall KeysCompare(const double A, const double B);
	int __fastcall ValuesCompare(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclDoubleSortedEntry >  FEntries;
	int __fastcall BinarySearch(const double Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclDoubleSortedMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclDoubleSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const double Key);
	bool __fastcall ContainsValue(System::TObject* Value);
	System::TObject* __fastcall Extract(const double Key);
	System::TObject* __fastcall GetValue(const double Key);
	bool __fastcall IsEmpty(void);
	double __fastcall KeyOfValue(System::TObject* Value);
	Jclcontainerintf::_di_IJclDoubleSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclDoubleMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclDoubleMap AMap);
	void __fastcall PutValue(const double Key, System::TObject* Value);
	System::TObject* __fastcall Remove(const double Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclCollection __fastcall Values();
	double __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclDoubleSortedMap __fastcall HeadMap(const double ToKey);
	double __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclDoubleSortedMap __fastcall SubMap(const double FromKey, const double ToKey);
	Jclcontainerintf::_di_IJclDoubleSortedMap __fastcall TailMap(const double FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclDoubleSortedMap;	/* Jclcontainerintf::IJclDoubleSortedMap */
	
public:
	operator IJclDoubleSortedMap*(void) { return (IJclDoubleSortedMap*)&__IJclDoubleSortedMap; }
	operator IJclDoubleMap*(void) { return (IJclDoubleMap*)&__IJclDoubleSortedMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclDoubleContainer*(void) { return (IJclDoubleContainer*)&__IJclDoubleSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclDoubleSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleSortedMap; }
	
};


struct TJclExtendedSortedEntry
{
	
public:
	Extended Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclExtendedSortedEntry >  JclSortedMaps__86;

class DELPHICLASS TJclExtendedSortedMap;
class PASCALIMPLEMENTATION TJclExtendedSortedMap : public Jclabstractcontainers::TJclExtendedAbstractContainer 
{
	typedef Jclabstractcontainers::TJclExtendedAbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	Extended __fastcall FreeKey(Extended &Key);
	int __fastcall KeysCompare(const Extended A, const Extended B);
	int __fastcall ValuesCompare(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclExtendedSortedEntry >  FEntries;
	int __fastcall BinarySearch(const Extended Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclExtendedSortedMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclExtendedSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const Extended Key);
	bool __fastcall ContainsValue(System::TObject* Value);
	System::TObject* __fastcall Extract(const Extended Key);
	System::TObject* __fastcall GetValue(const Extended Key);
	bool __fastcall IsEmpty(void);
	Extended __fastcall KeyOfValue(System::TObject* Value);
	Jclcontainerintf::_di_IJclExtendedSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclExtendedMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclExtendedMap AMap);
	void __fastcall PutValue(const Extended Key, System::TObject* Value);
	System::TObject* __fastcall Remove(const Extended Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclCollection __fastcall Values();
	Extended __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclExtendedSortedMap __fastcall HeadMap(const Extended ToKey);
	Extended __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclExtendedSortedMap __fastcall SubMap(const Extended FromKey, const Extended ToKey);
	Jclcontainerintf::_di_IJclExtendedSortedMap __fastcall TailMap(const Extended FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclExtendedSortedMap;	/* Jclcontainerintf::IJclExtendedSortedMap */
	
public:
	operator IJclExtendedSortedMap*(void) { return (IJclExtendedSortedMap*)&__IJclExtendedSortedMap; }
	operator IJclExtendedMap*(void) { return (IJclExtendedMap*)&__IJclExtendedSortedMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclExtendedContainer*(void) { return (IJclExtendedContainer*)&__IJclExtendedSortedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclExtendedSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedSortedMap; }
	
};


typedef TJclExtendedSortedMap TJclFloatSortedMap;
;

struct TJclIntegerSortedEntry
{
	
public:
	int Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclIntegerSortedEntry >  JclSortedMaps__07;

class DELPHICLASS TJclIntegerSortedMap;
class PASCALIMPLEMENTATION TJclIntegerSortedMap : public Jclabstractcontainers::TJclIntegerAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntegerAbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	int __fastcall FreeKey(int &Key);
	int __fastcall KeysCompare(int A, int B);
	int __fastcall ValuesCompare(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclIntegerSortedEntry >  FEntries;
	int __fastcall BinarySearch(int Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclIntegerSortedMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclIntegerSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(int Key);
	bool __fastcall ContainsValue(System::TObject* Value);
	System::TObject* __fastcall Extract(int Key);
	System::TObject* __fastcall GetValue(int Key);
	bool __fastcall IsEmpty(void);
	int __fastcall KeyOfValue(System::TObject* Value);
	Jclcontainerintf::_di_IJclIntegerSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclIntegerMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclIntegerMap AMap);
	void __fastcall PutValue(int Key, System::TObject* Value);
	System::TObject* __fastcall Remove(int Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclCollection __fastcall Values();
	int __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclIntegerSortedMap __fastcall HeadMap(int ToKey);
	int __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclIntegerSortedMap __fastcall SubMap(int FromKey, int ToKey);
	Jclcontainerintf::_di_IJclIntegerSortedMap __fastcall TailMap(int FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclIntegerSortedMap;	/* Jclcontainerintf::IJclIntegerSortedMap */
	
public:
	operator IJclIntegerSortedMap*(void) { return (IJclIntegerSortedMap*)&__IJclIntegerSortedMap; }
	operator IJclIntegerMap*(void) { return (IJclIntegerMap*)&__IJclIntegerSortedMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntegerSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerSortedMap; }
	
};


struct TJclCardinalSortedEntry
{
	
public:
	unsigned Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclCardinalSortedEntry >  JclSortedMaps__27;

class DELPHICLASS TJclCardinalSortedMap;
class PASCALIMPLEMENTATION TJclCardinalSortedMap : public Jclabstractcontainers::TJclCardinalAbstractContainer 
{
	typedef Jclabstractcontainers::TJclCardinalAbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	unsigned __fastcall FreeKey(unsigned &Key);
	int __fastcall KeysCompare(unsigned A, unsigned B);
	int __fastcall ValuesCompare(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclCardinalSortedEntry >  FEntries;
	int __fastcall BinarySearch(unsigned Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclCardinalSortedMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclCardinalSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(unsigned Key);
	bool __fastcall ContainsValue(System::TObject* Value);
	System::TObject* __fastcall Extract(unsigned Key);
	System::TObject* __fastcall GetValue(unsigned Key);
	bool __fastcall IsEmpty(void);
	unsigned __fastcall KeyOfValue(System::TObject* Value);
	Jclcontainerintf::_di_IJclCardinalSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclCardinalMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclCardinalMap AMap);
	void __fastcall PutValue(unsigned Key, System::TObject* Value);
	System::TObject* __fastcall Remove(unsigned Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclCollection __fastcall Values();
	unsigned __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclCardinalSortedMap __fastcall HeadMap(unsigned ToKey);
	unsigned __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclCardinalSortedMap __fastcall SubMap(unsigned FromKey, unsigned ToKey);
	Jclcontainerintf::_di_IJclCardinalSortedMap __fastcall TailMap(unsigned FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclCardinalSortedMap;	/* Jclcontainerintf::IJclCardinalSortedMap */
	
public:
	operator IJclCardinalSortedMap*(void) { return (IJclCardinalSortedMap*)&__IJclCardinalSortedMap; }
	operator IJclCardinalMap*(void) { return (IJclCardinalMap*)&__IJclCardinalSortedMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclCardinalSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalSortedMap; }
	
};


struct TJclInt64SortedEntry
{
	
public:
	__int64 Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclInt64SortedEntry >  JclSortedMaps__47;

class DELPHICLASS TJclInt64SortedMap;
class PASCALIMPLEMENTATION TJclInt64SortedMap : public Jclabstractcontainers::TJclInt64AbstractContainer 
{
	typedef Jclabstractcontainers::TJclInt64AbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	__int64 __fastcall FreeKey(__int64 &Key);
	int __fastcall KeysCompare(const __int64 A, const __int64 B);
	int __fastcall ValuesCompare(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclInt64SortedEntry >  FEntries;
	int __fastcall BinarySearch(const __int64 Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclInt64SortedMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclInt64SortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const __int64 Key);
	bool __fastcall ContainsValue(System::TObject* Value);
	System::TObject* __fastcall Extract(const __int64 Key);
	System::TObject* __fastcall GetValue(const __int64 Key);
	bool __fastcall IsEmpty(void);
	__int64 __fastcall KeyOfValue(System::TObject* Value);
	Jclcontainerintf::_di_IJclInt64Set __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclInt64Map AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclInt64Map AMap);
	void __fastcall PutValue(const __int64 Key, System::TObject* Value);
	System::TObject* __fastcall Remove(const __int64 Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclCollection __fastcall Values();
	__int64 __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclInt64SortedMap __fastcall HeadMap(const __int64 ToKey);
	__int64 __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclInt64SortedMap __fastcall SubMap(const __int64 FromKey, const __int64 ToKey);
	Jclcontainerintf::_di_IJclInt64SortedMap __fastcall TailMap(const __int64 FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclInt64SortedMap;	/* Jclcontainerintf::IJclInt64SortedMap */
	
public:
	operator IJclInt64SortedMap*(void) { return (IJclInt64SortedMap*)&__IJclInt64SortedMap; }
	operator IJclInt64Map*(void) { return (IJclInt64Map*)&__IJclInt64SortedMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclInt64SortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64SortedMap; }
	
};


struct TJclPtrSortedEntry
{
	
public:
	void *Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclPtrSortedEntry >  JclSortedMaps__67;

class DELPHICLASS TJclPtrSortedMap;
class PASCALIMPLEMENTATION TJclPtrSortedMap : public Jclabstractcontainers::TJclPtrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclPtrAbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	void * __fastcall FreeKey(void * &Key);
	int __fastcall KeysCompare(void * A, void * B);
	int __fastcall ValuesCompare(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclPtrSortedEntry >  FEntries;
	int __fastcall BinarySearch(void * Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclPtrSortedMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclPtrSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(void * Key);
	bool __fastcall ContainsValue(System::TObject* Value);
	System::TObject* __fastcall Extract(void * Key);
	System::TObject* __fastcall GetValue(void * Key);
	bool __fastcall IsEmpty(void);
	void * __fastcall KeyOfValue(System::TObject* Value);
	Jclcontainerintf::_di_IJclPtrSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclPtrMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclPtrMap AMap);
	void __fastcall PutValue(void * Key, System::TObject* Value);
	System::TObject* __fastcall Remove(void * Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclCollection __fastcall Values();
	void * __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclPtrSortedMap __fastcall HeadMap(void * ToKey);
	void * __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclPtrSortedMap __fastcall SubMap(void * FromKey, void * ToKey);
	Jclcontainerintf::_di_IJclPtrSortedMap __fastcall TailMap(void * FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclPtrSortedMap;	/* Jclcontainerintf::IJclPtrSortedMap */
	
public:
	operator IJclPtrSortedMap*(void) { return (IJclPtrSortedMap*)&__IJclPtrSortedMap; }
	operator IJclPtrMap*(void) { return (IJclPtrMap*)&__IJclPtrSortedMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclPtrSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrSortedMap; }
	
};


struct TJclSortedEntry
{
	
public:
	System::TObject* Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclSortedEntry >  JclSortedMaps__87;

class DELPHICLASS TJclSortedMap;
class PASCALIMPLEMENTATION TJclSortedMap : public Jclabstractcontainers::TJclAbstractContainerBase 
{
	typedef Jclabstractcontainers::TJclAbstractContainerBase inherited;
	
private:
	bool FOwnsKeys;
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	int __fastcall KeysCompare(System::TObject* A, System::TObject* B);
	int __fastcall ValuesCompare(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeKey(System::TObject* &Key);
	bool __fastcall GetOwnsKeys(void);
	__property bool OwnsKeys = {read=FOwnsKeys, nodefault};
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclSortedEntry >  FEntries;
	int __fastcall BinarySearch(System::TObject* Key);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
	
public:
	__fastcall TJclSortedMap(int ACapacity, bool AOwnsValues, bool AOwnsKeys);
	__fastcall virtual ~TJclSortedMap(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(System::TObject* Key);
	bool __fastcall ContainsValue(System::TObject* Value);
	System::TObject* __fastcall Extract(System::TObject* Key);
	System::TObject* __fastcall GetValue(System::TObject* Key);
	bool __fastcall IsEmpty(void);
	System::TObject* __fastcall KeyOfValue(System::TObject* Value);
	Jclcontainerintf::_di_IJclSet __fastcall KeySet();
	bool __fastcall MapEquals(const Jclcontainerintf::_di_IJclMap AMap);
	void __fastcall PutAll(const Jclcontainerintf::_di_IJclMap AMap);
	void __fastcall PutValue(System::TObject* Key, System::TObject* Value);
	System::TObject* __fastcall Remove(System::TObject* Key);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclCollection __fastcall Values();
	System::TObject* __fastcall FirstKey(void);
	Jclcontainerintf::_di_IJclSortedMap __fastcall HeadMap(System::TObject* ToKey);
	System::TObject* __fastcall LastKey(void);
	Jclcontainerintf::_di_IJclSortedMap __fastcall SubMap(System::TObject* FromKey, System::TObject* ToKey);
	Jclcontainerintf::_di_IJclSortedMap __fastcall TailMap(System::TObject* FromKey);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclKeyOwner;	/* Jclcontainerintf::IJclKeyOwner */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclSortedMap;	/* Jclcontainerintf::IJclSortedMap */
	
public:
	operator IJclSortedMap*(void) { return (IJclSortedMap*)&__IJclSortedMap; }
	operator IJclMap*(void) { return (IJclMap*)&__IJclSortedMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclKeyOwner*(void) { return (IJclKeyOwner*)&__IJclKeyOwner; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclSortedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSortedMap; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jclsortedmaps */
using namespace Jclsortedmaps;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclsortedmaps
