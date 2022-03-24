// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclhashmaps.pas' rev: 10.00

#ifndef JclhashmapsHPP
#define JclhashmapsHPP

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
#include <Jclcontainerintf.hpp>	// Pascal unit
#include <Jclabstractcontainers.hpp>	// Pascal unit
#include <Jclarraylists.hpp>	// Pascal unit
#include <Jclarraysets.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclhashmaps
{
//-- type declarations -------------------------------------------------------
typedef int __fastcall (*TJclHashFunction)(int Key, int Range);

struct TJclIntfIntfHashEntry
{
	
public:
	System::_di_IInterface Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclIntfIntfHashEntry >  JclHashMaps__2;

class DELPHICLASS TJclIntfIntfBucket;
class PASCALIMPLEMENTATION TJclIntfIntfBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclIntfIntfHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntfIntfBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntfIntfBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclIntfIntfBucket* >  JclHashMaps__4;

class DELPHICLASS TJclIntfIntfHashMap;
class PASCALIMPLEMENTATION TJclIntfIntfHashMap : public Jclabstractcontainers::TJclIntfAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntfAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	bool __fastcall KeysEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	bool __fastcall ValuesEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclIntfIntfBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntfIntfHashMap(int ACapacity);
	__fastcall virtual ~TJclIntfIntfHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfIntfMap;	/* Jclcontainerintf::IJclIntfIntfMap */
	
public:
	operator IJclIntfIntfMap*(void) { return (IJclIntfIntfMap*)&__IJclIntfIntfMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfIntfMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfIntfMap; }
	
};


struct TJclAnsiStrIntfHashEntry
{
	
public:
	AnsiString Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclAnsiStrIntfHashEntry >  JclHashMaps__6;

class DELPHICLASS TJclAnsiStrIntfBucket;
class PASCALIMPLEMENTATION TJclAnsiStrIntfBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclAnsiStrIntfHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclAnsiStrIntfBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclAnsiStrIntfBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclAnsiStrIntfBucket* >  JclHashMaps__8;

class DELPHICLASS TJclAnsiStrIntfHashMap;
class PASCALIMPLEMENTATION TJclAnsiStrIntfHashMap : public Jclabstractcontainers::TJclAnsiStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclAnsiStrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	AnsiString __fastcall FreeKey(AnsiString &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	bool __fastcall KeysEqual(const AnsiString A, const AnsiString B);
	bool __fastcall ValuesEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclAnsiStrIntfBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclAnsiStrIntfHashMap(int ACapacity);
	__fastcall virtual ~TJclAnsiStrIntfHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclAnsiStrIntfMap;	/* Jclcontainerintf::IJclAnsiStrIntfMap */
	
public:
	operator IJclAnsiStrIntfMap*(void) { return (IJclAnsiStrIntfMap*)&__IJclAnsiStrIntfMap; }
	operator IJclAnsiStrContainer*(void) { return (IJclAnsiStrContainer*)&__IJclAnsiStrIntfMap; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclAnsiStrIntfMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclAnsiStrIntfMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrIntfMap; }
	
};


struct TJclIntfAnsiStrHashEntry
{
	
public:
	System::_di_IInterface Key;
	AnsiString Value;
} ;

typedef DynamicArray<TJclIntfAnsiStrHashEntry >  JclHashMaps__01;

class DELPHICLASS TJclIntfAnsiStrBucket;
class PASCALIMPLEMENTATION TJclIntfAnsiStrBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclIntfAnsiStrHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntfAnsiStrBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntfAnsiStrBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclIntfAnsiStrBucket* >  JclHashMaps__21;

class DELPHICLASS TJclIntfAnsiStrHashMap;
class PASCALIMPLEMENTATION TJclIntfAnsiStrHashMap : public Jclabstractcontainers::TJclAnsiStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclAnsiStrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	AnsiString __fastcall FreeValue(AnsiString &Value);
	HIDESBASE int __fastcall Hash(const System::_di_IInterface AInterface);
	bool __fastcall KeysEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	bool __fastcall ValuesEqual(const AnsiString A, const AnsiString B);
	
private:
	DynamicArray<TJclIntfAnsiStrBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntfAnsiStrHashMap(int ACapacity);
	__fastcall virtual ~TJclIntfAnsiStrHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfAnsiStrMap;	/* Jclcontainerintf::IJclIntfAnsiStrMap */
	
public:
	operator IJclIntfAnsiStrMap*(void) { return (IJclIntfAnsiStrMap*)&__IJclIntfAnsiStrMap; }
	operator IJclAnsiStrContainer*(void) { return (IJclAnsiStrContainer*)&__IJclIntfAnsiStrMap; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclIntfAnsiStrMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfAnsiStrMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfAnsiStrMap; }
	
};


struct TJclAnsiStrAnsiStrHashEntry
{
	
public:
	AnsiString Key;
	AnsiString Value;
} ;

typedef DynamicArray<TJclAnsiStrAnsiStrHashEntry >  JclHashMaps__41;

class DELPHICLASS TJclAnsiStrAnsiStrBucket;
class PASCALIMPLEMENTATION TJclAnsiStrAnsiStrBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclAnsiStrAnsiStrHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclAnsiStrAnsiStrBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclAnsiStrAnsiStrBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclAnsiStrAnsiStrBucket* >  JclHashMaps__61;

class DELPHICLASS TJclAnsiStrAnsiStrHashMap;
class PASCALIMPLEMENTATION TJclAnsiStrAnsiStrHashMap : public Jclabstractcontainers::TJclAnsiStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclAnsiStrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	AnsiString __fastcall FreeKey(AnsiString &Key);
	AnsiString __fastcall FreeValue(AnsiString &Value);
	bool __fastcall KeysEqual(const AnsiString A, const AnsiString B);
	bool __fastcall ValuesEqual(const AnsiString A, const AnsiString B);
	
private:
	DynamicArray<TJclAnsiStrAnsiStrBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclAnsiStrAnsiStrHashMap(int ACapacity);
	__fastcall virtual ~TJclAnsiStrAnsiStrHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclAnsiStrAnsiStrMap;	/* Jclcontainerintf::IJclAnsiStrAnsiStrMap */
	
public:
	operator IJclAnsiStrAnsiStrMap*(void) { return (IJclAnsiStrAnsiStrMap*)&__IJclAnsiStrAnsiStrMap; }
	operator IJclAnsiStrContainer*(void) { return (IJclAnsiStrContainer*)&__IJclAnsiStrAnsiStrMap; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclAnsiStrAnsiStrMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclAnsiStrAnsiStrMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrAnsiStrMap; }
	
};


struct TJclWideStrIntfHashEntry
{
	
public:
	WideString Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclWideStrIntfHashEntry >  JclHashMaps__81;

class DELPHICLASS TJclWideStrIntfBucket;
class PASCALIMPLEMENTATION TJclWideStrIntfBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclWideStrIntfHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclWideStrIntfBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclWideStrIntfBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclWideStrIntfBucket* >  JclHashMaps__02;

class DELPHICLASS TJclWideStrIntfHashMap;
class PASCALIMPLEMENTATION TJclWideStrIntfHashMap : public Jclabstractcontainers::TJclWideStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclWideStrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	WideString __fastcall FreeKey(WideString &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	bool __fastcall KeysEqual(const WideString A, const WideString B);
	bool __fastcall ValuesEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclWideStrIntfBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclWideStrIntfHashMap(int ACapacity);
	__fastcall virtual ~TJclWideStrIntfHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclWideStrIntfMap;	/* Jclcontainerintf::IJclWideStrIntfMap */
	
public:
	operator IJclWideStrIntfMap*(void) { return (IJclWideStrIntfMap*)&__IJclWideStrIntfMap; }
	operator IJclWideStrContainer*(void) { return (IJclWideStrContainer*)&__IJclWideStrIntfMap; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclWideStrIntfMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclWideStrIntfMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrIntfMap; }
	
};


struct TJclIntfWideStrHashEntry
{
	
public:
	System::_di_IInterface Key;
	WideString Value;
} ;

typedef DynamicArray<TJclIntfWideStrHashEntry >  JclHashMaps__22;

class DELPHICLASS TJclIntfWideStrBucket;
class PASCALIMPLEMENTATION TJclIntfWideStrBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclIntfWideStrHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntfWideStrBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntfWideStrBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclIntfWideStrBucket* >  JclHashMaps__42;

class DELPHICLASS TJclIntfWideStrHashMap;
class PASCALIMPLEMENTATION TJclIntfWideStrHashMap : public Jclabstractcontainers::TJclWideStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclWideStrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	WideString __fastcall FreeValue(WideString &Value);
	HIDESBASE int __fastcall Hash(const System::_di_IInterface AInterface);
	bool __fastcall KeysEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	bool __fastcall ValuesEqual(const WideString A, const WideString B);
	
private:
	DynamicArray<TJclIntfWideStrBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntfWideStrHashMap(int ACapacity);
	__fastcall virtual ~TJclIntfWideStrHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfWideStrMap;	/* Jclcontainerintf::IJclIntfWideStrMap */
	
public:
	operator IJclIntfWideStrMap*(void) { return (IJclIntfWideStrMap*)&__IJclIntfWideStrMap; }
	operator IJclWideStrContainer*(void) { return (IJclWideStrContainer*)&__IJclIntfWideStrMap; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclIntfWideStrMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfWideStrMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfWideStrMap; }
	
};


struct TJclWideStrWideStrHashEntry
{
	
public:
	WideString Key;
	WideString Value;
} ;

typedef DynamicArray<TJclWideStrWideStrHashEntry >  JclHashMaps__62;

class DELPHICLASS TJclWideStrWideStrBucket;
class PASCALIMPLEMENTATION TJclWideStrWideStrBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclWideStrWideStrHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclWideStrWideStrBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclWideStrWideStrBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclWideStrWideStrBucket* >  JclHashMaps__82;

class DELPHICLASS TJclWideStrWideStrHashMap;
class PASCALIMPLEMENTATION TJclWideStrWideStrHashMap : public Jclabstractcontainers::TJclWideStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclWideStrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	WideString __fastcall FreeKey(WideString &Key);
	WideString __fastcall FreeValue(WideString &Value);
	bool __fastcall KeysEqual(const WideString A, const WideString B);
	bool __fastcall ValuesEqual(const WideString A, const WideString B);
	
private:
	DynamicArray<TJclWideStrWideStrBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclWideStrWideStrHashMap(int ACapacity);
	__fastcall virtual ~TJclWideStrWideStrHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclWideStrWideStrMap;	/* Jclcontainerintf::IJclWideStrWideStrMap */
	
public:
	operator IJclWideStrWideStrMap*(void) { return (IJclWideStrWideStrMap*)&__IJclWideStrWideStrMap; }
	operator IJclWideStrContainer*(void) { return (IJclWideStrContainer*)&__IJclWideStrWideStrMap; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclWideStrWideStrMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclWideStrWideStrMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrWideStrMap; }
	
};


typedef TJclAnsiStrIntfHashMap TJclStrIntfHashMap;
;

typedef TJclIntfAnsiStrHashMap TJclIntfStrHashMap;
;

typedef TJclAnsiStrAnsiStrHashMap TJclStrStrHashMap;
;

struct TJclSingleIntfHashEntry
{
	
public:
	float Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclSingleIntfHashEntry >  JclHashMaps__03;

class DELPHICLASS TJclSingleIntfBucket;
class PASCALIMPLEMENTATION TJclSingleIntfBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclSingleIntfHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclSingleIntfBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclSingleIntfBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclSingleIntfBucket* >  JclHashMaps__23;

class DELPHICLASS TJclSingleIntfHashMap;
class PASCALIMPLEMENTATION TJclSingleIntfHashMap : public Jclabstractcontainers::TJclSingleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclSingleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	float __fastcall FreeKey(float &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	bool __fastcall KeysEqual(const float A, const float B);
	bool __fastcall ValuesEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclSingleIntfBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclSingleIntfHashMap(int ACapacity);
	__fastcall virtual ~TJclSingleIntfHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclSingleIntfMap;	/* Jclcontainerintf::IJclSingleIntfMap */
	
public:
	operator IJclSingleIntfMap*(void) { return (IJclSingleIntfMap*)&__IJclSingleIntfMap; }
	operator IJclSingleContainer*(void) { return (IJclSingleContainer*)&__IJclSingleIntfMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclSingleIntfMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleIntfMap; }
	
};


struct TJclIntfSingleHashEntry
{
	
public:
	System::_di_IInterface Key;
	float Value;
} ;

typedef DynamicArray<TJclIntfSingleHashEntry >  JclHashMaps__43;

class DELPHICLASS TJclIntfSingleBucket;
class PASCALIMPLEMENTATION TJclIntfSingleBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclIntfSingleHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntfSingleBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntfSingleBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclIntfSingleBucket* >  JclHashMaps__63;

class DELPHICLASS TJclIntfSingleHashMap;
class PASCALIMPLEMENTATION TJclIntfSingleHashMap : public Jclabstractcontainers::TJclSingleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclSingleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	float __fastcall FreeValue(float &Value);
	HIDESBASE int __fastcall Hash(const System::_di_IInterface AInterface);
	bool __fastcall KeysEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	bool __fastcall ValuesEqual(const float A, const float B);
	
private:
	DynamicArray<TJclIntfSingleBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntfSingleHashMap(int ACapacity);
	__fastcall virtual ~TJclIntfSingleHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfSingleMap;	/* Jclcontainerintf::IJclIntfSingleMap */
	
public:
	operator IJclIntfSingleMap*(void) { return (IJclIntfSingleMap*)&__IJclIntfSingleMap; }
	operator IJclSingleContainer*(void) { return (IJclSingleContainer*)&__IJclIntfSingleMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfSingleMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfSingleMap; }
	
};


struct TJclSingleSingleHashEntry
{
	
public:
	float Key;
	float Value;
} ;

typedef DynamicArray<TJclSingleSingleHashEntry >  JclHashMaps__83;

class DELPHICLASS TJclSingleSingleBucket;
class PASCALIMPLEMENTATION TJclSingleSingleBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclSingleSingleHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclSingleSingleBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclSingleSingleBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclSingleSingleBucket* >  JclHashMaps__04;

class DELPHICLASS TJclSingleSingleHashMap;
class PASCALIMPLEMENTATION TJclSingleSingleHashMap : public Jclabstractcontainers::TJclSingleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclSingleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	float __fastcall FreeKey(float &Key);
	float __fastcall FreeValue(float &Value);
	bool __fastcall KeysEqual(const float A, const float B);
	bool __fastcall ValuesEqual(const float A, const float B);
	
private:
	DynamicArray<TJclSingleSingleBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclSingleSingleHashMap(int ACapacity);
	__fastcall virtual ~TJclSingleSingleHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclSingleSingleMap;	/* Jclcontainerintf::IJclSingleSingleMap */
	
public:
	operator IJclSingleSingleMap*(void) { return (IJclSingleSingleMap*)&__IJclSingleSingleMap; }
	operator IJclSingleContainer*(void) { return (IJclSingleContainer*)&__IJclSingleSingleMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclSingleSingleMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleSingleMap; }
	
};


struct TJclDoubleIntfHashEntry
{
	
public:
	double Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclDoubleIntfHashEntry >  JclHashMaps__24;

class DELPHICLASS TJclDoubleIntfBucket;
class PASCALIMPLEMENTATION TJclDoubleIntfBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclDoubleIntfHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclDoubleIntfBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclDoubleIntfBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclDoubleIntfBucket* >  JclHashMaps__44;

class DELPHICLASS TJclDoubleIntfHashMap;
class PASCALIMPLEMENTATION TJclDoubleIntfHashMap : public Jclabstractcontainers::TJclDoubleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclDoubleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	double __fastcall FreeKey(double &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	bool __fastcall KeysEqual(const double A, const double B);
	bool __fastcall ValuesEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclDoubleIntfBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclDoubleIntfHashMap(int ACapacity);
	__fastcall virtual ~TJclDoubleIntfHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclDoubleIntfMap;	/* Jclcontainerintf::IJclDoubleIntfMap */
	
public:
	operator IJclDoubleIntfMap*(void) { return (IJclDoubleIntfMap*)&__IJclDoubleIntfMap; }
	operator IJclDoubleContainer*(void) { return (IJclDoubleContainer*)&__IJclDoubleIntfMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclDoubleIntfMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleIntfMap; }
	
};


struct TJclIntfDoubleHashEntry
{
	
public:
	System::_di_IInterface Key;
	double Value;
} ;

typedef DynamicArray<TJclIntfDoubleHashEntry >  JclHashMaps__64;

class DELPHICLASS TJclIntfDoubleBucket;
class PASCALIMPLEMENTATION TJclIntfDoubleBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclIntfDoubleHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntfDoubleBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntfDoubleBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclIntfDoubleBucket* >  JclHashMaps__84;

class DELPHICLASS TJclIntfDoubleHashMap;
class PASCALIMPLEMENTATION TJclIntfDoubleHashMap : public Jclabstractcontainers::TJclDoubleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclDoubleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	double __fastcall FreeValue(double &Value);
	HIDESBASE int __fastcall Hash(const System::_di_IInterface AInterface);
	bool __fastcall KeysEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	bool __fastcall ValuesEqual(const double A, const double B);
	
private:
	DynamicArray<TJclIntfDoubleBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntfDoubleHashMap(int ACapacity);
	__fastcall virtual ~TJclIntfDoubleHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfDoubleMap;	/* Jclcontainerintf::IJclIntfDoubleMap */
	
public:
	operator IJclIntfDoubleMap*(void) { return (IJclIntfDoubleMap*)&__IJclIntfDoubleMap; }
	operator IJclDoubleContainer*(void) { return (IJclDoubleContainer*)&__IJclIntfDoubleMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfDoubleMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfDoubleMap; }
	
};


struct TJclDoubleDoubleHashEntry
{
	
public:
	double Key;
	double Value;
} ;

typedef DynamicArray<TJclDoubleDoubleHashEntry >  JclHashMaps__05;

class DELPHICLASS TJclDoubleDoubleBucket;
class PASCALIMPLEMENTATION TJclDoubleDoubleBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclDoubleDoubleHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclDoubleDoubleBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclDoubleDoubleBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclDoubleDoubleBucket* >  JclHashMaps__25;

class DELPHICLASS TJclDoubleDoubleHashMap;
class PASCALIMPLEMENTATION TJclDoubleDoubleHashMap : public Jclabstractcontainers::TJclDoubleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclDoubleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	double __fastcall FreeKey(double &Key);
	double __fastcall FreeValue(double &Value);
	bool __fastcall KeysEqual(const double A, const double B);
	bool __fastcall ValuesEqual(const double A, const double B);
	
private:
	DynamicArray<TJclDoubleDoubleBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclDoubleDoubleHashMap(int ACapacity);
	__fastcall virtual ~TJclDoubleDoubleHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclDoubleDoubleMap;	/* Jclcontainerintf::IJclDoubleDoubleMap */
	
public:
	operator IJclDoubleDoubleMap*(void) { return (IJclDoubleDoubleMap*)&__IJclDoubleDoubleMap; }
	operator IJclDoubleContainer*(void) { return (IJclDoubleContainer*)&__IJclDoubleDoubleMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclDoubleDoubleMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleDoubleMap; }
	
};


struct TJclExtendedIntfHashEntry
{
	
public:
	Extended Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclExtendedIntfHashEntry >  JclHashMaps__45;

class DELPHICLASS TJclExtendedIntfBucket;
class PASCALIMPLEMENTATION TJclExtendedIntfBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclExtendedIntfHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclExtendedIntfBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclExtendedIntfBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclExtendedIntfBucket* >  JclHashMaps__65;

class DELPHICLASS TJclExtendedIntfHashMap;
class PASCALIMPLEMENTATION TJclExtendedIntfHashMap : public Jclabstractcontainers::TJclExtendedAbstractContainer 
{
	typedef Jclabstractcontainers::TJclExtendedAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	Extended __fastcall FreeKey(Extended &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	bool __fastcall KeysEqual(const Extended A, const Extended B);
	bool __fastcall ValuesEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclExtendedIntfBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclExtendedIntfHashMap(int ACapacity);
	__fastcall virtual ~TJclExtendedIntfHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclExtendedIntfMap;	/* Jclcontainerintf::IJclExtendedIntfMap */
	
public:
	operator IJclExtendedIntfMap*(void) { return (IJclExtendedIntfMap*)&__IJclExtendedIntfMap; }
	operator IJclExtendedContainer*(void) { return (IJclExtendedContainer*)&__IJclExtendedIntfMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclExtendedIntfMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedIntfMap; }
	
};


struct TJclIntfExtendedHashEntry
{
	
public:
	System::_di_IInterface Key;
	Extended Value;
} ;

typedef DynamicArray<TJclIntfExtendedHashEntry >  JclHashMaps__85;

class DELPHICLASS TJclIntfExtendedBucket;
class PASCALIMPLEMENTATION TJclIntfExtendedBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclIntfExtendedHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntfExtendedBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntfExtendedBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclIntfExtendedBucket* >  JclHashMaps__06;

class DELPHICLASS TJclIntfExtendedHashMap;
class PASCALIMPLEMENTATION TJclIntfExtendedHashMap : public Jclabstractcontainers::TJclExtendedAbstractContainer 
{
	typedef Jclabstractcontainers::TJclExtendedAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	Extended __fastcall FreeValue(Extended &Value);
	HIDESBASE int __fastcall Hash(const System::_di_IInterface AInterface);
	bool __fastcall KeysEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	bool __fastcall ValuesEqual(const Extended A, const Extended B);
	
private:
	DynamicArray<TJclIntfExtendedBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntfExtendedHashMap(int ACapacity);
	__fastcall virtual ~TJclIntfExtendedHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfExtendedMap;	/* Jclcontainerintf::IJclIntfExtendedMap */
	
public:
	operator IJclIntfExtendedMap*(void) { return (IJclIntfExtendedMap*)&__IJclIntfExtendedMap; }
	operator IJclExtendedContainer*(void) { return (IJclExtendedContainer*)&__IJclIntfExtendedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfExtendedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfExtendedMap; }
	
};


struct TJclExtendedExtendedHashEntry
{
	
public:
	Extended Key;
	Extended Value;
} ;

typedef DynamicArray<TJclExtendedExtendedHashEntry >  JclHashMaps__26;

class DELPHICLASS TJclExtendedExtendedBucket;
class PASCALIMPLEMENTATION TJclExtendedExtendedBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclExtendedExtendedHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclExtendedExtendedBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclExtendedExtendedBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclExtendedExtendedBucket* >  JclHashMaps__46;

class DELPHICLASS TJclExtendedExtendedHashMap;
class PASCALIMPLEMENTATION TJclExtendedExtendedHashMap : public Jclabstractcontainers::TJclExtendedAbstractContainer 
{
	typedef Jclabstractcontainers::TJclExtendedAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	Extended __fastcall FreeKey(Extended &Key);
	Extended __fastcall FreeValue(Extended &Value);
	bool __fastcall KeysEqual(const Extended A, const Extended B);
	bool __fastcall ValuesEqual(const Extended A, const Extended B);
	
private:
	DynamicArray<TJclExtendedExtendedBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclExtendedExtendedHashMap(int ACapacity);
	__fastcall virtual ~TJclExtendedExtendedHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclExtendedExtendedMap;	/* Jclcontainerintf::IJclExtendedExtendedMap */
	
public:
	operator IJclExtendedExtendedMap*(void) { return (IJclExtendedExtendedMap*)&__IJclExtendedExtendedMap; }
	operator IJclExtendedContainer*(void) { return (IJclExtendedContainer*)&__IJclExtendedExtendedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclExtendedExtendedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedExtendedMap; }
	
};


typedef TJclExtendedIntfHashMap TJclFloatIntfHashMap;
;

typedef TJclIntfExtendedHashMap TJclIntfFloatHashMap;
;

typedef TJclExtendedExtendedHashMap TJclFloatFloatHashMap;
;

struct TJclIntegerIntfHashEntry
{
	
public:
	int Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclIntegerIntfHashEntry >  JclHashMaps__66;

class DELPHICLASS TJclIntegerIntfBucket;
class PASCALIMPLEMENTATION TJclIntegerIntfBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclIntegerIntfHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntegerIntfBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntegerIntfBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclIntegerIntfBucket* >  JclHashMaps__86;

class DELPHICLASS TJclIntegerIntfHashMap;
class PASCALIMPLEMENTATION TJclIntegerIntfHashMap : public Jclabstractcontainers::TJclIntegerAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntegerAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	int __fastcall FreeKey(int &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	bool __fastcall KeysEqual(int A, int B);
	bool __fastcall ValuesEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclIntegerIntfBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntegerIntfHashMap(int ACapacity);
	__fastcall virtual ~TJclIntegerIntfHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntegerIntfMap;	/* Jclcontainerintf::IJclIntegerIntfMap */
	
public:
	operator IJclIntegerIntfMap*(void) { return (IJclIntegerIntfMap*)&__IJclIntegerIntfMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntegerIntfMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerIntfMap; }
	
};


struct TJclIntfIntegerHashEntry
{
	
public:
	System::_di_IInterface Key;
	int Value;
} ;

typedef DynamicArray<TJclIntfIntegerHashEntry >  JclHashMaps__07;

class DELPHICLASS TJclIntfIntegerBucket;
class PASCALIMPLEMENTATION TJclIntfIntegerBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclIntfIntegerHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntfIntegerBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntfIntegerBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclIntfIntegerBucket* >  JclHashMaps__27;

class DELPHICLASS TJclIntfIntegerHashMap;
class PASCALIMPLEMENTATION TJclIntfIntegerHashMap : public Jclabstractcontainers::TJclIntegerAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntegerAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	int __fastcall FreeValue(int &Value);
	HIDESBASE int __fastcall Hash(const System::_di_IInterface AInterface);
	bool __fastcall KeysEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	bool __fastcall ValuesEqual(int A, int B);
	
private:
	DynamicArray<TJclIntfIntegerBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntfIntegerHashMap(int ACapacity);
	__fastcall virtual ~TJclIntfIntegerHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfIntegerMap;	/* Jclcontainerintf::IJclIntfIntegerMap */
	
public:
	operator IJclIntfIntegerMap*(void) { return (IJclIntfIntegerMap*)&__IJclIntfIntegerMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfIntegerMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfIntegerMap; }
	
};


struct TJclIntegerIntegerHashEntry
{
	
public:
	int Key;
	int Value;
} ;

typedef DynamicArray<TJclIntegerIntegerHashEntry >  JclHashMaps__47;

class DELPHICLASS TJclIntegerIntegerBucket;
class PASCALIMPLEMENTATION TJclIntegerIntegerBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclIntegerIntegerHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntegerIntegerBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntegerIntegerBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclIntegerIntegerBucket* >  JclHashMaps__67;

class DELPHICLASS TJclIntegerIntegerHashMap;
class PASCALIMPLEMENTATION TJclIntegerIntegerHashMap : public Jclabstractcontainers::TJclIntegerAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntegerAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	int __fastcall FreeKey(int &Key);
	int __fastcall FreeValue(int &Value);
	bool __fastcall KeysEqual(int A, int B);
	bool __fastcall ValuesEqual(int A, int B);
	
private:
	DynamicArray<TJclIntegerIntegerBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntegerIntegerHashMap(int ACapacity);
	__fastcall virtual ~TJclIntegerIntegerHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntegerIntegerMap;	/* Jclcontainerintf::IJclIntegerIntegerMap */
	
public:
	operator IJclIntegerIntegerMap*(void) { return (IJclIntegerIntegerMap*)&__IJclIntegerIntegerMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntegerIntegerMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerIntegerMap; }
	
};


struct TJclCardinalIntfHashEntry
{
	
public:
	unsigned Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclCardinalIntfHashEntry >  JclHashMaps__87;

class DELPHICLASS TJclCardinalIntfBucket;
class PASCALIMPLEMENTATION TJclCardinalIntfBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclCardinalIntfHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclCardinalIntfBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclCardinalIntfBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclCardinalIntfBucket* >  JclHashMaps__08;

class DELPHICLASS TJclCardinalIntfHashMap;
class PASCALIMPLEMENTATION TJclCardinalIntfHashMap : public Jclabstractcontainers::TJclCardinalAbstractContainer 
{
	typedef Jclabstractcontainers::TJclCardinalAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	unsigned __fastcall FreeKey(unsigned &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	bool __fastcall KeysEqual(unsigned A, unsigned B);
	bool __fastcall ValuesEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclCardinalIntfBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclCardinalIntfHashMap(int ACapacity);
	__fastcall virtual ~TJclCardinalIntfHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclCardinalIntfMap;	/* Jclcontainerintf::IJclCardinalIntfMap */
	
public:
	operator IJclCardinalIntfMap*(void) { return (IJclCardinalIntfMap*)&__IJclCardinalIntfMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclCardinalIntfMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalIntfMap; }
	
};


struct TJclIntfCardinalHashEntry
{
	
public:
	System::_di_IInterface Key;
	unsigned Value;
} ;

typedef DynamicArray<TJclIntfCardinalHashEntry >  JclHashMaps__28;

class DELPHICLASS TJclIntfCardinalBucket;
class PASCALIMPLEMENTATION TJclIntfCardinalBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclIntfCardinalHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntfCardinalBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntfCardinalBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclIntfCardinalBucket* >  JclHashMaps__48;

class DELPHICLASS TJclIntfCardinalHashMap;
class PASCALIMPLEMENTATION TJclIntfCardinalHashMap : public Jclabstractcontainers::TJclCardinalAbstractContainer 
{
	typedef Jclabstractcontainers::TJclCardinalAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	unsigned __fastcall FreeValue(unsigned &Value);
	HIDESBASE int __fastcall Hash(const System::_di_IInterface AInterface);
	bool __fastcall KeysEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	bool __fastcall ValuesEqual(unsigned A, unsigned B);
	
private:
	DynamicArray<TJclIntfCardinalBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntfCardinalHashMap(int ACapacity);
	__fastcall virtual ~TJclIntfCardinalHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfCardinalMap;	/* Jclcontainerintf::IJclIntfCardinalMap */
	
public:
	operator IJclIntfCardinalMap*(void) { return (IJclIntfCardinalMap*)&__IJclIntfCardinalMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfCardinalMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfCardinalMap; }
	
};


struct TJclCardinalCardinalHashEntry
{
	
public:
	unsigned Key;
	unsigned Value;
} ;

typedef DynamicArray<TJclCardinalCardinalHashEntry >  JclHashMaps__68;

class DELPHICLASS TJclCardinalCardinalBucket;
class PASCALIMPLEMENTATION TJclCardinalCardinalBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclCardinalCardinalHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclCardinalCardinalBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclCardinalCardinalBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclCardinalCardinalBucket* >  JclHashMaps__88;

class DELPHICLASS TJclCardinalCardinalHashMap;
class PASCALIMPLEMENTATION TJclCardinalCardinalHashMap : public Jclabstractcontainers::TJclCardinalAbstractContainer 
{
	typedef Jclabstractcontainers::TJclCardinalAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	unsigned __fastcall FreeKey(unsigned &Key);
	unsigned __fastcall FreeValue(unsigned &Value);
	bool __fastcall KeysEqual(unsigned A, unsigned B);
	bool __fastcall ValuesEqual(unsigned A, unsigned B);
	
private:
	DynamicArray<TJclCardinalCardinalBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclCardinalCardinalHashMap(int ACapacity);
	__fastcall virtual ~TJclCardinalCardinalHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclCardinalCardinalMap;	/* Jclcontainerintf::IJclCardinalCardinalMap */
	
public:
	operator IJclCardinalCardinalMap*(void) { return (IJclCardinalCardinalMap*)&__IJclCardinalCardinalMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclCardinalCardinalMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalCardinalMap; }
	
};


struct TJclInt64IntfHashEntry
{
	
public:
	__int64 Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclInt64IntfHashEntry >  JclHashMaps__09;

class DELPHICLASS TJclInt64IntfBucket;
class PASCALIMPLEMENTATION TJclInt64IntfBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclInt64IntfHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclInt64IntfBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclInt64IntfBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclInt64IntfBucket* >  JclHashMaps__29;

class DELPHICLASS TJclInt64IntfHashMap;
class PASCALIMPLEMENTATION TJclInt64IntfHashMap : public Jclabstractcontainers::TJclInt64AbstractContainer 
{
	typedef Jclabstractcontainers::TJclInt64AbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	__int64 __fastcall FreeKey(__int64 &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	bool __fastcall KeysEqual(const __int64 A, const __int64 B);
	bool __fastcall ValuesEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclInt64IntfBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclInt64IntfHashMap(int ACapacity);
	__fastcall virtual ~TJclInt64IntfHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclInt64IntfMap;	/* Jclcontainerintf::IJclInt64IntfMap */
	
public:
	operator IJclInt64IntfMap*(void) { return (IJclInt64IntfMap*)&__IJclInt64IntfMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclInt64IntfMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64IntfMap; }
	
};


struct TJclIntfInt64HashEntry
{
	
public:
	System::_di_IInterface Key;
	__int64 Value;
} ;

typedef DynamicArray<TJclIntfInt64HashEntry >  JclHashMaps__49;

class DELPHICLASS TJclIntfInt64Bucket;
class PASCALIMPLEMENTATION TJclIntfInt64Bucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclIntfInt64HashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntfInt64Bucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntfInt64Bucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclIntfInt64Bucket* >  JclHashMaps__69;

class DELPHICLASS TJclIntfInt64HashMap;
class PASCALIMPLEMENTATION TJclIntfInt64HashMap : public Jclabstractcontainers::TJclInt64AbstractContainer 
{
	typedef Jclabstractcontainers::TJclInt64AbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	__int64 __fastcall FreeValue(__int64 &Value);
	HIDESBASE int __fastcall Hash(const System::_di_IInterface AInterface);
	bool __fastcall KeysEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	bool __fastcall ValuesEqual(const __int64 A, const __int64 B);
	
private:
	DynamicArray<TJclIntfInt64Bucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntfInt64HashMap(int ACapacity);
	__fastcall virtual ~TJclIntfInt64HashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfInt64Map;	/* Jclcontainerintf::IJclIntfInt64Map */
	
public:
	operator IJclIntfInt64Map*(void) { return (IJclIntfInt64Map*)&__IJclIntfInt64Map; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfInt64Map; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfInt64Map; }
	
};


struct TJclInt64Int64HashEntry
{
	
public:
	__int64 Key;
	__int64 Value;
} ;

typedef DynamicArray<TJclInt64Int64HashEntry >  JclHashMaps__89;

class DELPHICLASS TJclInt64Int64Bucket;
class PASCALIMPLEMENTATION TJclInt64Int64Bucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclInt64Int64HashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclInt64Int64Bucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclInt64Int64Bucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclInt64Int64Bucket* >  JclHashMaps__001;

class DELPHICLASS TJclInt64Int64HashMap;
class PASCALIMPLEMENTATION TJclInt64Int64HashMap : public Jclabstractcontainers::TJclInt64AbstractContainer 
{
	typedef Jclabstractcontainers::TJclInt64AbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	__int64 __fastcall FreeKey(__int64 &Key);
	__int64 __fastcall FreeValue(__int64 &Value);
	bool __fastcall KeysEqual(const __int64 A, const __int64 B);
	bool __fastcall ValuesEqual(const __int64 A, const __int64 B);
	
private:
	DynamicArray<TJclInt64Int64Bucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclInt64Int64HashMap(int ACapacity);
	__fastcall virtual ~TJclInt64Int64HashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclInt64Int64Map;	/* Jclcontainerintf::IJclInt64Int64Map */
	
public:
	operator IJclInt64Int64Map*(void) { return (IJclInt64Int64Map*)&__IJclInt64Int64Map; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclInt64Int64Map; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64Int64Map; }
	
};


struct TJclPtrIntfHashEntry
{
	
public:
	void *Key;
	System::_di_IInterface Value;
} ;

typedef DynamicArray<TJclPtrIntfHashEntry >  JclHashMaps__201;

class DELPHICLASS TJclPtrIntfBucket;
class PASCALIMPLEMENTATION TJclPtrIntfBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclPtrIntfHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclPtrIntfBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclPtrIntfBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclPtrIntfBucket* >  JclHashMaps__401;

class DELPHICLASS TJclPtrIntfHashMap;
class PASCALIMPLEMENTATION TJclPtrIntfHashMap : public Jclabstractcontainers::TJclPtrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclPtrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	void * __fastcall FreeKey(void * &Key);
	System::_di_IInterface __fastcall FreeValue(System::_di_IInterface &Value);
	bool __fastcall KeysEqual(void * A, void * B);
	bool __fastcall ValuesEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	
private:
	DynamicArray<TJclPtrIntfBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclPtrIntfHashMap(int ACapacity);
	__fastcall virtual ~TJclPtrIntfHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclPtrIntfMap;	/* Jclcontainerintf::IJclPtrIntfMap */
	
public:
	operator IJclPtrIntfMap*(void) { return (IJclPtrIntfMap*)&__IJclPtrIntfMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclPtrIntfMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrIntfMap; }
	
};


struct TJclIntfPtrHashEntry
{
	
public:
	System::_di_IInterface Key;
	void *Value;
} ;

typedef DynamicArray<TJclIntfPtrHashEntry >  JclHashMaps__601;

class DELPHICLASS TJclIntfPtrBucket;
class PASCALIMPLEMENTATION TJclIntfPtrBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclIntfPtrHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntfPtrBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntfPtrBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclIntfPtrBucket* >  JclHashMaps__801;

class DELPHICLASS TJclIntfPtrHashMap;
class PASCALIMPLEMENTATION TJclIntfPtrHashMap : public Jclabstractcontainers::TJclPtrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclPtrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	void * __fastcall FreeValue(void * &Value);
	HIDESBASE int __fastcall Hash(const System::_di_IInterface AInterface);
	bool __fastcall KeysEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	bool __fastcall ValuesEqual(void * A, void * B);
	
private:
	DynamicArray<TJclIntfPtrBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntfPtrHashMap(int ACapacity);
	__fastcall virtual ~TJclIntfPtrHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfPtrMap;	/* Jclcontainerintf::IJclIntfPtrMap */
	
public:
	operator IJclIntfPtrMap*(void) { return (IJclIntfPtrMap*)&__IJclIntfPtrMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfPtrMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfPtrMap; }
	
};


struct TJclPtrPtrHashEntry
{
	
public:
	void *Key;
	void *Value;
} ;

typedef DynamicArray<TJclPtrPtrHashEntry >  JclHashMaps__011;

class DELPHICLASS TJclPtrPtrBucket;
class PASCALIMPLEMENTATION TJclPtrPtrBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclPtrPtrHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclPtrPtrBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclPtrPtrBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclPtrPtrBucket* >  JclHashMaps__211;

class DELPHICLASS TJclPtrPtrHashMap;
class PASCALIMPLEMENTATION TJclPtrPtrHashMap : public Jclabstractcontainers::TJclPtrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclPtrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	void * __fastcall FreeKey(void * &Key);
	void * __fastcall FreeValue(void * &Value);
	bool __fastcall KeysEqual(void * A, void * B);
	bool __fastcall ValuesEqual(void * A, void * B);
	
private:
	DynamicArray<TJclPtrPtrBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclPtrPtrHashMap(int ACapacity);
	__fastcall virtual ~TJclPtrPtrHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclPtrPtrMap;	/* Jclcontainerintf::IJclPtrPtrMap */
	
public:
	operator IJclPtrPtrMap*(void) { return (IJclPtrPtrMap*)&__IJclPtrPtrMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclPtrPtrMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrPtrMap; }
	
};


struct TJclIntfHashEntry
{
	
public:
	System::_di_IInterface Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclIntfHashEntry >  JclHashMaps__411;

class DELPHICLASS TJclIntfBucket;
class PASCALIMPLEMENTATION TJclIntfBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclIntfHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntfBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntfBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclIntfBucket* >  JclHashMaps__611;

class DELPHICLASS TJclIntfHashMap;
class PASCALIMPLEMENTATION TJclIntfHashMap : public Jclabstractcontainers::TJclAbstractContainerBase 
{
	typedef Jclabstractcontainers::TJclAbstractContainerBase inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	System::_di_IInterface __fastcall FreeKey(System::_di_IInterface &Key);
	int __fastcall Hash(const System::_di_IInterface AInterface);
	bool __fastcall KeysEqual(const System::_di_IInterface A, const System::_di_IInterface B);
	bool __fastcall ValuesEqual(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclIntfBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntfHashMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclIntfHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclIntfMap;	/* Jclcontainerintf::IJclIntfMap */
	
public:
	operator IJclIntfMap*(void) { return (IJclIntfMap*)&__IJclIntfMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfMap; }
	
};


struct TJclAnsiStrHashEntry
{
	
public:
	AnsiString Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclAnsiStrHashEntry >  JclHashMaps__811;

class DELPHICLASS TJclAnsiStrBucket;
class PASCALIMPLEMENTATION TJclAnsiStrBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclAnsiStrHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclAnsiStrBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclAnsiStrBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclAnsiStrBucket* >  JclHashMaps__021;

class DELPHICLASS TJclAnsiStrHashMap;
class PASCALIMPLEMENTATION TJclAnsiStrHashMap : public Jclabstractcontainers::TJclAnsiStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclAnsiStrAbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	AnsiString __fastcall FreeKey(AnsiString &Key);
	bool __fastcall KeysEqual(const AnsiString A, const AnsiString B);
	bool __fastcall ValuesEqual(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclAnsiStrBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclAnsiStrHashMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclAnsiStrHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclAnsiStrMap;	/* Jclcontainerintf::IJclAnsiStrMap */
	
public:
	operator IJclAnsiStrMap*(void) { return (IJclAnsiStrMap*)&__IJclAnsiStrMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclAnsiStrContainer*(void) { return (IJclAnsiStrContainer*)&__IJclAnsiStrMap; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclAnsiStrMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclAnsiStrMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrMap; }
	
};


struct TJclWideStrHashEntry
{
	
public:
	WideString Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclWideStrHashEntry >  JclHashMaps__221;

class DELPHICLASS TJclWideStrBucket;
class PASCALIMPLEMENTATION TJclWideStrBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclWideStrHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclWideStrBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclWideStrBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclWideStrBucket* >  JclHashMaps__421;

class DELPHICLASS TJclWideStrHashMap;
class PASCALIMPLEMENTATION TJclWideStrHashMap : public Jclabstractcontainers::TJclWideStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclWideStrAbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	WideString __fastcall FreeKey(WideString &Key);
	bool __fastcall KeysEqual(const WideString A, const WideString B);
	bool __fastcall ValuesEqual(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclWideStrBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclWideStrHashMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclWideStrHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclWideStrMap;	/* Jclcontainerintf::IJclWideStrMap */
	
public:
	operator IJclWideStrMap*(void) { return (IJclWideStrMap*)&__IJclWideStrMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclWideStrContainer*(void) { return (IJclWideStrContainer*)&__IJclWideStrMap; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclWideStrMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclWideStrMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrMap; }
	
};


typedef TJclAnsiStrHashMap TJclStrHashMap;
;

struct TJclSingleHashEntry
{
	
public:
	float Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclSingleHashEntry >  JclHashMaps__621;

class DELPHICLASS TJclSingleBucket;
class PASCALIMPLEMENTATION TJclSingleBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclSingleHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclSingleBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclSingleBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclSingleBucket* >  JclHashMaps__821;

class DELPHICLASS TJclSingleHashMap;
class PASCALIMPLEMENTATION TJclSingleHashMap : public Jclabstractcontainers::TJclSingleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclSingleAbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	float __fastcall FreeKey(float &Key);
	bool __fastcall KeysEqual(const float A, const float B);
	bool __fastcall ValuesEqual(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclSingleBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclSingleHashMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclSingleHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclSingleMap;	/* Jclcontainerintf::IJclSingleMap */
	
public:
	operator IJclSingleMap*(void) { return (IJclSingleMap*)&__IJclSingleMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclSingleContainer*(void) { return (IJclSingleContainer*)&__IJclSingleMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclSingleMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleMap; }
	
};


struct TJclDoubleHashEntry
{
	
public:
	double Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclDoubleHashEntry >  JclHashMaps__031;

class DELPHICLASS TJclDoubleBucket;
class PASCALIMPLEMENTATION TJclDoubleBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclDoubleHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclDoubleBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclDoubleBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclDoubleBucket* >  JclHashMaps__231;

class DELPHICLASS TJclDoubleHashMap;
class PASCALIMPLEMENTATION TJclDoubleHashMap : public Jclabstractcontainers::TJclDoubleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclDoubleAbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	double __fastcall FreeKey(double &Key);
	bool __fastcall KeysEqual(const double A, const double B);
	bool __fastcall ValuesEqual(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclDoubleBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclDoubleHashMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclDoubleHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclDoubleMap;	/* Jclcontainerintf::IJclDoubleMap */
	
public:
	operator IJclDoubleMap*(void) { return (IJclDoubleMap*)&__IJclDoubleMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclDoubleContainer*(void) { return (IJclDoubleContainer*)&__IJclDoubleMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclDoubleMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleMap; }
	
};


struct TJclExtendedHashEntry
{
	
public:
	Extended Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclExtendedHashEntry >  JclHashMaps__431;

class DELPHICLASS TJclExtendedBucket;
class PASCALIMPLEMENTATION TJclExtendedBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclExtendedHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclExtendedBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclExtendedBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclExtendedBucket* >  JclHashMaps__631;

class DELPHICLASS TJclExtendedHashMap;
class PASCALIMPLEMENTATION TJclExtendedHashMap : public Jclabstractcontainers::TJclExtendedAbstractContainer 
{
	typedef Jclabstractcontainers::TJclExtendedAbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	Extended __fastcall FreeKey(Extended &Key);
	bool __fastcall KeysEqual(const Extended A, const Extended B);
	bool __fastcall ValuesEqual(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclExtendedBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclExtendedHashMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclExtendedHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclExtendedMap;	/* Jclcontainerintf::IJclExtendedMap */
	
public:
	operator IJclExtendedMap*(void) { return (IJclExtendedMap*)&__IJclExtendedMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclExtendedContainer*(void) { return (IJclExtendedContainer*)&__IJclExtendedMap; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclExtendedMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedMap; }
	
};


typedef TJclExtendedHashMap TJclFloatHashMap;
;

struct TJclIntegerHashEntry
{
	
public:
	int Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclIntegerHashEntry >  JclHashMaps__831;

class DELPHICLASS TJclIntegerBucket;
class PASCALIMPLEMENTATION TJclIntegerBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclIntegerHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntegerBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntegerBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclIntegerBucket* >  JclHashMaps__041;

class DELPHICLASS TJclIntegerHashMap;
class PASCALIMPLEMENTATION TJclIntegerHashMap : public Jclabstractcontainers::TJclIntegerAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntegerAbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	int __fastcall FreeKey(int &Key);
	bool __fastcall KeysEqual(int A, int B);
	bool __fastcall ValuesEqual(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclIntegerBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntegerHashMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclIntegerHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclIntegerMap;	/* Jclcontainerintf::IJclIntegerMap */
	
public:
	operator IJclIntegerMap*(void) { return (IJclIntegerMap*)&__IJclIntegerMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntegerMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerMap; }
	
};


struct TJclCardinalHashEntry
{
	
public:
	unsigned Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclCardinalHashEntry >  JclHashMaps__241;

class DELPHICLASS TJclCardinalBucket;
class PASCALIMPLEMENTATION TJclCardinalBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclCardinalHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclCardinalBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclCardinalBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclCardinalBucket* >  JclHashMaps__441;

class DELPHICLASS TJclCardinalHashMap;
class PASCALIMPLEMENTATION TJclCardinalHashMap : public Jclabstractcontainers::TJclCardinalAbstractContainer 
{
	typedef Jclabstractcontainers::TJclCardinalAbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	unsigned __fastcall FreeKey(unsigned &Key);
	bool __fastcall KeysEqual(unsigned A, unsigned B);
	bool __fastcall ValuesEqual(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclCardinalBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclCardinalHashMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclCardinalHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclCardinalMap;	/* Jclcontainerintf::IJclCardinalMap */
	
public:
	operator IJclCardinalMap*(void) { return (IJclCardinalMap*)&__IJclCardinalMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclCardinalMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalMap; }
	
};


struct TJclInt64HashEntry
{
	
public:
	__int64 Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclInt64HashEntry >  JclHashMaps__641;

class DELPHICLASS TJclInt64Bucket;
class PASCALIMPLEMENTATION TJclInt64Bucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclInt64HashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclInt64Bucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclInt64Bucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclInt64Bucket* >  JclHashMaps__841;

class DELPHICLASS TJclInt64HashMap;
class PASCALIMPLEMENTATION TJclInt64HashMap : public Jclabstractcontainers::TJclInt64AbstractContainer 
{
	typedef Jclabstractcontainers::TJclInt64AbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	__int64 __fastcall FreeKey(__int64 &Key);
	bool __fastcall KeysEqual(const __int64 A, const __int64 B);
	bool __fastcall ValuesEqual(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclInt64Bucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclInt64HashMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclInt64HashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclInt64Map;	/* Jclcontainerintf::IJclInt64Map */
	
public:
	operator IJclInt64Map*(void) { return (IJclInt64Map*)&__IJclInt64Map; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclInt64Map; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64Map; }
	
};


struct TJclPtrHashEntry
{
	
public:
	void *Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclPtrHashEntry >  JclHashMaps__051;

class DELPHICLASS TJclPtrBucket;
class PASCALIMPLEMENTATION TJclPtrBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclPtrHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclPtrBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclPtrBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclPtrBucket* >  JclHashMaps__251;

class DELPHICLASS TJclPtrHashMap;
class PASCALIMPLEMENTATION TJclPtrHashMap : public Jclabstractcontainers::TJclPtrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclPtrAbstractContainer inherited;
	
private:
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	void * __fastcall FreeKey(void * &Key);
	bool __fastcall KeysEqual(void * A, void * B);
	bool __fastcall ValuesEqual(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclPtrBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclPtrHashMap(int ACapacity, bool AOwnsValues);
	__fastcall virtual ~TJclPtrHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclPtrMap;	/* Jclcontainerintf::IJclPtrMap */
	
public:
	operator IJclPtrMap*(void) { return (IJclPtrMap*)&__IJclPtrMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclPtrMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrMap; }
	
};


struct TJclHashEntry
{
	
public:
	System::TObject* Key;
	System::TObject* Value;
} ;

typedef DynamicArray<TJclHashEntry >  JclHashMaps__451;

class DELPHICLASS TJclBucket;
class PASCALIMPLEMENTATION TJclBucket : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Size;
	DynamicArray<TJclHashEntry >  Entries;
	void __fastcall MoveArray(int FromIndex, int ToIndex, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclBucket(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclBucket(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TJclBucket* >  JclHashMaps__651;

class DELPHICLASS TJclHashMap;
class PASCALIMPLEMENTATION TJclHashMap : public Jclabstractcontainers::TJclAbstractContainerBase 
{
	typedef Jclabstractcontainers::TJclAbstractContainerBase inherited;
	
private:
	bool FOwnsKeys;
	bool FOwnsValues;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	int __fastcall Hash(System::TObject* AObject);
	bool __fastcall KeysEqual(System::TObject* A, System::TObject* B);
	bool __fastcall ValuesEqual(System::TObject* A, System::TObject* B);
	
public:
	System::TObject* __fastcall FreeKey(System::TObject* &Key);
	bool __fastcall GetOwnsKeys(void);
	__property bool OwnsKeys = {read=FOwnsKeys, nodefault};
	System::TObject* __fastcall FreeValue(System::TObject* &Value);
	bool __fastcall GetOwnsValues(void);
	__property bool OwnsValues = {read=FOwnsValues, nodefault};
	
private:
	DynamicArray<TJclBucket* >  FBuckets;
	TJclHashFunction FHashFunction;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclHashMap(int ACapacity, bool AOwnsValues, bool AOwnsKeys);
	__fastcall virtual ~TJclHashMap(void);
	__property TJclHashFunction HashFunction = {read=FHashFunction, write=FHashFunction};
	virtual void __fastcall Pack(void);
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
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclKeyOwner;	/* Jclcontainerintf::IJclKeyOwner */
	void *__IJclValueOwner;	/* Jclcontainerintf::IJclValueOwner */
	void *__IJclMap;	/* Jclcontainerintf::IJclMap */
	
public:
	operator IJclMap*(void) { return (IJclMap*)&__IJclMap; }
	operator IJclValueOwner*(void) { return (IJclValueOwner*)&__IJclValueOwner; }
	operator IJclKeyOwner*(void) { return (IJclKeyOwner*)&__IJclKeyOwner; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclMap; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclMap; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE int __fastcall HashMul(int Key, int Range);

}	/* namespace Jclhashmaps */
using namespace Jclhashmaps;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclhashmaps
