// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclarraysets.pas' rev: 10.00

#ifndef JclarraysetsHPP
#define JclarraysetsHPP

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
#include <Jclabstractcontainers.hpp>	// Pascal unit
#include <Jclcontainerintf.hpp>	// Pascal unit
#include <Jclarraylists.hpp>	// Pascal unit
#include <Jclsynch.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclarraysets
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TJclIntfArraySet;
class PASCALIMPLEMENTATION TJclIntfArraySet : public Jclarraylists::TJclIntfArrayList 
{
	typedef Jclarraylists::TJclIntfArrayList inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int __fastcall BinarySearch(const System::_di_IInterface AInterface);
	
public:
	HIDESBASE bool __fastcall Add(const System::_di_IInterface AInterface);
	HIDESBASE bool __fastcall AddAll(const Jclcontainerintf::_di_IJclIntfCollection ACollection);
	HIDESBASE bool __fastcall Contains(const System::_di_IInterface AInterface);
	HIDESBASE bool __fastcall Insert(int Index, const System::_di_IInterface AInterface);
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclIntfCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclIntfCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclIntfCollection ACollection);
public:
	#pragma option push -w-inl
	/* TJclIntfArrayList.Create */ inline __fastcall TJclIntfArraySet(int ACapacity)/* overload */ : Jclarraylists::TJclIntfArrayList(ACapacity) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclIntfArrayList.Destroy */ inline __fastcall virtual ~TJclIntfArraySet(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfEqualityComparer;	/* Jclcontainerintf::IJclIntfEqualityComparer */
	void *__IJclIntfComparer;	/* Jclcontainerintf::IJclIntfComparer */
	void *__IJclIntfArray;	/* Jclcontainerintf::IJclIntfArray */
	void *__IJclIntfSet;	/* Jclcontainerintf::IJclIntfSet */
	
public:
	operator IJclIntfSet*(void) { return (IJclIntfSet*)&__IJclIntfSet; }
	operator IJclIntfArray*(void) { return (IJclIntfArray*)&__IJclIntfArray; }
	operator IJclIntfList*(void) { return (IJclIntfList*)&__IJclIntfArray; }
	operator IJclIntfCollection*(void) { return (IJclIntfCollection*)&__IJclIntfSet; }
	operator IJclIntfComparer*(void) { return (IJclIntfComparer*)&__IJclIntfComparer; }
	operator IJclIntfEqualityComparer*(void) { return (IJclIntfEqualityComparer*)&__IJclIntfEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfSet; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfSet; }
	
};


class DELPHICLASS TJclAnsiStrArraySet;
class PASCALIMPLEMENTATION TJclAnsiStrArraySet : public Jclarraylists::TJclAnsiStrArrayList 
{
	typedef Jclarraylists::TJclAnsiStrArrayList inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int __fastcall BinarySearch(const AnsiString AString);
	
public:
	virtual bool __fastcall Add(const AnsiString AString);
	virtual bool __fastcall AddAll(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection);
	virtual bool __fastcall Contains(const AnsiString AString);
	HIDESBASE bool __fastcall Insert(int Index, const AnsiString AString);
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection);
public:
	#pragma option push -w-inl
	/* TJclAnsiStrArrayList.Create */ inline __fastcall TJclAnsiStrArraySet(int ACapacity)/* overload */ : Jclarraylists::TJclAnsiStrArrayList(ACapacity) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclAnsiStrArrayList.Destroy */ inline __fastcall virtual ~TJclAnsiStrArraySet(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclAnsiStrEqualityComparer;	/* Jclcontainerintf::IJclAnsiStrEqualityComparer */
	void *__IJclAnsiStrComparer;	/* Jclcontainerintf::IJclAnsiStrComparer */
	void *__IJclAnsiStrArray;	/* Jclcontainerintf::IJclAnsiStrArray */
	void *__IJclAnsiStrSet;	/* Jclcontainerintf::IJclAnsiStrSet */
	
public:
	operator IJclAnsiStrSet*(void) { return (IJclAnsiStrSet*)&__IJclAnsiStrSet; }
	operator IJclAnsiStrArray*(void) { return (IJclAnsiStrArray*)&__IJclAnsiStrArray; }
	operator IJclAnsiStrList*(void) { return (IJclAnsiStrList*)&__IJclAnsiStrArray; }
	operator IJclAnsiStrCollection*(void) { return (IJclAnsiStrCollection*)&__IJclAnsiStrSet; }
	operator IJclAnsiStrComparer*(void) { return (IJclAnsiStrComparer*)&__IJclAnsiStrComparer; }
	operator IJclAnsiStrEqualityComparer*(void) { return (IJclAnsiStrEqualityComparer*)&__IJclAnsiStrEqualityComparer; }
	operator IJclAnsiStrFlatContainer*(void) { return (IJclAnsiStrFlatContainer*)&__IJclAnsiStrSet; }
	operator IJclAnsiStrContainer*(void) { return (IJclAnsiStrContainer*)&__IJclAnsiStrSet; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclAnsiStrSet; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclAnsiStrSet; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrSet; }
	
};


class DELPHICLASS TJclWideStrArraySet;
class PASCALIMPLEMENTATION TJclWideStrArraySet : public Jclarraylists::TJclWideStrArrayList 
{
	typedef Jclarraylists::TJclWideStrArrayList inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int __fastcall BinarySearch(const WideString AString);
	
public:
	virtual bool __fastcall Add(const WideString AString);
	virtual bool __fastcall AddAll(const Jclcontainerintf::_di_IJclWideStrCollection ACollection);
	virtual bool __fastcall Contains(const WideString AString);
	HIDESBASE bool __fastcall Insert(int Index, const WideString AString);
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclWideStrCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclWideStrCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclWideStrCollection ACollection);
public:
	#pragma option push -w-inl
	/* TJclWideStrArrayList.Create */ inline __fastcall TJclWideStrArraySet(int ACapacity)/* overload */ : Jclarraylists::TJclWideStrArrayList(ACapacity) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclWideStrArrayList.Destroy */ inline __fastcall virtual ~TJclWideStrArraySet(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclWideStrEqualityComparer;	/* Jclcontainerintf::IJclWideStrEqualityComparer */
	void *__IJclWideStrComparer;	/* Jclcontainerintf::IJclWideStrComparer */
	void *__IJclWideStrArray;	/* Jclcontainerintf::IJclWideStrArray */
	void *__IJclWideStrSet;	/* Jclcontainerintf::IJclWideStrSet */
	
public:
	operator IJclWideStrSet*(void) { return (IJclWideStrSet*)&__IJclWideStrSet; }
	operator IJclWideStrArray*(void) { return (IJclWideStrArray*)&__IJclWideStrArray; }
	operator IJclWideStrList*(void) { return (IJclWideStrList*)&__IJclWideStrArray; }
	operator IJclWideStrCollection*(void) { return (IJclWideStrCollection*)&__IJclWideStrSet; }
	operator IJclWideStrComparer*(void) { return (IJclWideStrComparer*)&__IJclWideStrComparer; }
	operator IJclWideStrEqualityComparer*(void) { return (IJclWideStrEqualityComparer*)&__IJclWideStrEqualityComparer; }
	operator IJclWideStrFlatContainer*(void) { return (IJclWideStrFlatContainer*)&__IJclWideStrSet; }
	operator IJclWideStrContainer*(void) { return (IJclWideStrContainer*)&__IJclWideStrSet; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclWideStrSet; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclWideStrSet; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrSet; }
	
};


typedef TJclAnsiStrArraySet TJclStrArraySet;
;

class DELPHICLASS TJclSingleArraySet;
class PASCALIMPLEMENTATION TJclSingleArraySet : public Jclarraylists::TJclSingleArrayList 
{
	typedef Jclarraylists::TJclSingleArrayList inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int __fastcall BinarySearch(const float AValue);
	
public:
	HIDESBASE bool __fastcall Add(const float AValue);
	HIDESBASE bool __fastcall AddAll(const Jclcontainerintf::_di_IJclSingleCollection ACollection);
	HIDESBASE bool __fastcall Contains(const float AValue);
	HIDESBASE bool __fastcall Insert(int Index, const float AValue);
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclSingleCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclSingleCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclSingleCollection ACollection);
public:
	#pragma option push -w-inl
	/* TJclSingleArrayList.Create */ inline __fastcall TJclSingleArraySet(int ACapacity)/* overload */ : Jclarraylists::TJclSingleArrayList(ACapacity) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclSingleArrayList.Destroy */ inline __fastcall virtual ~TJclSingleArraySet(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclSingleEqualityComparer;	/* Jclcontainerintf::IJclSingleEqualityComparer */
	void *__IJclSingleComparer;	/* Jclcontainerintf::IJclSingleComparer */
	void *__IJclSingleArray;	/* Jclcontainerintf::IJclSingleArray */
	void *__IJclSingleSet;	/* Jclcontainerintf::IJclSingleSet */
	
public:
	operator IJclSingleSet*(void) { return (IJclSingleSet*)&__IJclSingleSet; }
	operator IJclSingleArray*(void) { return (IJclSingleArray*)&__IJclSingleArray; }
	operator IJclSingleList*(void) { return (IJclSingleList*)&__IJclSingleArray; }
	operator IJclSingleCollection*(void) { return (IJclSingleCollection*)&__IJclSingleSet; }
	operator IJclSingleComparer*(void) { return (IJclSingleComparer*)&__IJclSingleComparer; }
	operator IJclSingleEqualityComparer*(void) { return (IJclSingleEqualityComparer*)&__IJclSingleEqualityComparer; }
	operator IJclSingleContainer*(void) { return (IJclSingleContainer*)&__IJclSingleSet; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclSingleSet; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleSet; }
	
};


class DELPHICLASS TJclDoubleArraySet;
class PASCALIMPLEMENTATION TJclDoubleArraySet : public Jclarraylists::TJclDoubleArrayList 
{
	typedef Jclarraylists::TJclDoubleArrayList inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int __fastcall BinarySearch(const double AValue);
	
public:
	HIDESBASE bool __fastcall Add(const double AValue);
	HIDESBASE bool __fastcall AddAll(const Jclcontainerintf::_di_IJclDoubleCollection ACollection);
	HIDESBASE bool __fastcall Contains(const double AValue);
	HIDESBASE bool __fastcall Insert(int Index, const double AValue);
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclDoubleCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclDoubleCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclDoubleCollection ACollection);
public:
	#pragma option push -w-inl
	/* TJclDoubleArrayList.Create */ inline __fastcall TJclDoubleArraySet(int ACapacity)/* overload */ : Jclarraylists::TJclDoubleArrayList(ACapacity) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclDoubleArrayList.Destroy */ inline __fastcall virtual ~TJclDoubleArraySet(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclDoubleEqualityComparer;	/* Jclcontainerintf::IJclDoubleEqualityComparer */
	void *__IJclDoubleComparer;	/* Jclcontainerintf::IJclDoubleComparer */
	void *__IJclDoubleArray;	/* Jclcontainerintf::IJclDoubleArray */
	void *__IJclDoubleSet;	/* Jclcontainerintf::IJclDoubleSet */
	
public:
	operator IJclDoubleSet*(void) { return (IJclDoubleSet*)&__IJclDoubleSet; }
	operator IJclDoubleArray*(void) { return (IJclDoubleArray*)&__IJclDoubleArray; }
	operator IJclDoubleList*(void) { return (IJclDoubleList*)&__IJclDoubleArray; }
	operator IJclDoubleCollection*(void) { return (IJclDoubleCollection*)&__IJclDoubleSet; }
	operator IJclDoubleComparer*(void) { return (IJclDoubleComparer*)&__IJclDoubleComparer; }
	operator IJclDoubleEqualityComparer*(void) { return (IJclDoubleEqualityComparer*)&__IJclDoubleEqualityComparer; }
	operator IJclDoubleContainer*(void) { return (IJclDoubleContainer*)&__IJclDoubleSet; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclDoubleSet; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleSet; }
	
};


class DELPHICLASS TJclExtendedArraySet;
class PASCALIMPLEMENTATION TJclExtendedArraySet : public Jclarraylists::TJclExtendedArrayList 
{
	typedef Jclarraylists::TJclExtendedArrayList inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int __fastcall BinarySearch(const Extended AValue);
	
public:
	HIDESBASE bool __fastcall Add(const Extended AValue);
	HIDESBASE bool __fastcall AddAll(const Jclcontainerintf::_di_IJclExtendedCollection ACollection);
	HIDESBASE bool __fastcall Contains(const Extended AValue);
	HIDESBASE bool __fastcall Insert(int Index, const Extended AValue);
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclExtendedCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclExtendedCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclExtendedCollection ACollection);
public:
	#pragma option push -w-inl
	/* TJclExtendedArrayList.Create */ inline __fastcall TJclExtendedArraySet(int ACapacity)/* overload */ : Jclarraylists::TJclExtendedArrayList(ACapacity) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclExtendedArrayList.Destroy */ inline __fastcall virtual ~TJclExtendedArraySet(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclExtendedEqualityComparer;	/* Jclcontainerintf::IJclExtendedEqualityComparer */
	void *__IJclExtendedComparer;	/* Jclcontainerintf::IJclExtendedComparer */
	void *__IJclExtendedArray;	/* Jclcontainerintf::IJclExtendedArray */
	void *__IJclExtendedSet;	/* Jclcontainerintf::IJclExtendedSet */
	
public:
	operator IJclExtendedSet*(void) { return (IJclExtendedSet*)&__IJclExtendedSet; }
	operator IJclExtendedArray*(void) { return (IJclExtendedArray*)&__IJclExtendedArray; }
	operator IJclExtendedList*(void) { return (IJclExtendedList*)&__IJclExtendedArray; }
	operator IJclExtendedCollection*(void) { return (IJclExtendedCollection*)&__IJclExtendedSet; }
	operator IJclExtendedComparer*(void) { return (IJclExtendedComparer*)&__IJclExtendedComparer; }
	operator IJclExtendedEqualityComparer*(void) { return (IJclExtendedEqualityComparer*)&__IJclExtendedEqualityComparer; }
	operator IJclExtendedContainer*(void) { return (IJclExtendedContainer*)&__IJclExtendedSet; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclExtendedSet; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedSet; }
	
};


typedef TJclExtendedArraySet TJclFloatArraySet;
;

class DELPHICLASS TJclIntegerArraySet;
class PASCALIMPLEMENTATION TJclIntegerArraySet : public Jclarraylists::TJclIntegerArrayList 
{
	typedef Jclarraylists::TJclIntegerArrayList inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int __fastcall BinarySearch(int AValue);
	
public:
	HIDESBASE bool __fastcall Add(int AValue);
	HIDESBASE bool __fastcall AddAll(const Jclcontainerintf::_di_IJclIntegerCollection ACollection);
	HIDESBASE bool __fastcall Contains(int AValue);
	HIDESBASE bool __fastcall Insert(int Index, int AValue);
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclIntegerCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclIntegerCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclIntegerCollection ACollection);
public:
	#pragma option push -w-inl
	/* TJclIntegerArrayList.Create */ inline __fastcall TJclIntegerArraySet(int ACapacity)/* overload */ : Jclarraylists::TJclIntegerArrayList(ACapacity) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclIntegerArrayList.Destroy */ inline __fastcall virtual ~TJclIntegerArraySet(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntegerEqualityComparer;	/* Jclcontainerintf::IJclIntegerEqualityComparer */
	void *__IJclIntegerComparer;	/* Jclcontainerintf::IJclIntegerComparer */
	void *__IJclIntegerArray;	/* Jclcontainerintf::IJclIntegerArray */
	void *__IJclIntegerSet;	/* Jclcontainerintf::IJclIntegerSet */
	
public:
	operator IJclIntegerSet*(void) { return (IJclIntegerSet*)&__IJclIntegerSet; }
	operator IJclIntegerArray*(void) { return (IJclIntegerArray*)&__IJclIntegerArray; }
	operator IJclIntegerList*(void) { return (IJclIntegerList*)&__IJclIntegerArray; }
	operator IJclIntegerCollection*(void) { return (IJclIntegerCollection*)&__IJclIntegerSet; }
	operator IJclIntegerComparer*(void) { return (IJclIntegerComparer*)&__IJclIntegerComparer; }
	operator IJclIntegerEqualityComparer*(void) { return (IJclIntegerEqualityComparer*)&__IJclIntegerEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntegerSet; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerSet; }
	
};


class DELPHICLASS TJclCardinalArraySet;
class PASCALIMPLEMENTATION TJclCardinalArraySet : public Jclarraylists::TJclCardinalArrayList 
{
	typedef Jclarraylists::TJclCardinalArrayList inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int __fastcall BinarySearch(unsigned AValue);
	
public:
	HIDESBASE bool __fastcall Add(unsigned AValue);
	HIDESBASE bool __fastcall AddAll(const Jclcontainerintf::_di_IJclCardinalCollection ACollection);
	HIDESBASE bool __fastcall Contains(unsigned AValue);
	HIDESBASE bool __fastcall Insert(int Index, unsigned AValue);
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclCardinalCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclCardinalCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclCardinalCollection ACollection);
public:
	#pragma option push -w-inl
	/* TJclCardinalArrayList.Create */ inline __fastcall TJclCardinalArraySet(int ACapacity)/* overload */ : Jclarraylists::TJclCardinalArrayList(ACapacity) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclCardinalArrayList.Destroy */ inline __fastcall virtual ~TJclCardinalArraySet(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclCardinalEqualityComparer;	/* Jclcontainerintf::IJclCardinalEqualityComparer */
	void *__IJclCardinalComparer;	/* Jclcontainerintf::IJclCardinalComparer */
	void *__IJclCardinalArray;	/* Jclcontainerintf::IJclCardinalArray */
	void *__IJclCardinalSet;	/* Jclcontainerintf::IJclCardinalSet */
	
public:
	operator IJclCardinalSet*(void) { return (IJclCardinalSet*)&__IJclCardinalSet; }
	operator IJclCardinalArray*(void) { return (IJclCardinalArray*)&__IJclCardinalArray; }
	operator IJclCardinalList*(void) { return (IJclCardinalList*)&__IJclCardinalArray; }
	operator IJclCardinalCollection*(void) { return (IJclCardinalCollection*)&__IJclCardinalSet; }
	operator IJclCardinalComparer*(void) { return (IJclCardinalComparer*)&__IJclCardinalComparer; }
	operator IJclCardinalEqualityComparer*(void) { return (IJclCardinalEqualityComparer*)&__IJclCardinalEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclCardinalSet; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalSet; }
	
};


class DELPHICLASS TJclInt64ArraySet;
class PASCALIMPLEMENTATION TJclInt64ArraySet : public Jclarraylists::TJclInt64ArrayList 
{
	typedef Jclarraylists::TJclInt64ArrayList inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int __fastcall BinarySearch(const __int64 AValue);
	
public:
	HIDESBASE bool __fastcall Add(const __int64 AValue);
	HIDESBASE bool __fastcall AddAll(const Jclcontainerintf::_di_IJclInt64Collection ACollection);
	HIDESBASE bool __fastcall Contains(const __int64 AValue);
	HIDESBASE bool __fastcall Insert(int Index, const __int64 AValue);
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclInt64Collection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclInt64Collection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclInt64Collection ACollection);
public:
	#pragma option push -w-inl
	/* TJclInt64ArrayList.Create */ inline __fastcall TJclInt64ArraySet(int ACapacity)/* overload */ : Jclarraylists::TJclInt64ArrayList(ACapacity) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclInt64ArrayList.Destroy */ inline __fastcall virtual ~TJclInt64ArraySet(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclInt64EqualityComparer;	/* Jclcontainerintf::IJclInt64EqualityComparer */
	void *__IJclInt64Comparer;	/* Jclcontainerintf::IJclInt64Comparer */
	void *__IJclInt64Array;	/* Jclcontainerintf::IJclInt64Array */
	void *__IJclInt64Set;	/* Jclcontainerintf::IJclInt64Set */
	
public:
	operator IJclInt64Set*(void) { return (IJclInt64Set*)&__IJclInt64Set; }
	operator IJclInt64Array*(void) { return (IJclInt64Array*)&__IJclInt64Array; }
	operator IJclInt64List*(void) { return (IJclInt64List*)&__IJclInt64Array; }
	operator IJclInt64Collection*(void) { return (IJclInt64Collection*)&__IJclInt64Set; }
	operator IJclInt64Comparer*(void) { return (IJclInt64Comparer*)&__IJclInt64Comparer; }
	operator IJclInt64EqualityComparer*(void) { return (IJclInt64EqualityComparer*)&__IJclInt64EqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclInt64Set; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64Set; }
	
};


class DELPHICLASS TJclPtrArraySet;
class PASCALIMPLEMENTATION TJclPtrArraySet : public Jclarraylists::TJclPtrArrayList 
{
	typedef Jclarraylists::TJclPtrArrayList inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int __fastcall BinarySearch(void * APtr);
	
public:
	HIDESBASE bool __fastcall Add(void * APtr);
	HIDESBASE bool __fastcall AddAll(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	HIDESBASE bool __fastcall Contains(void * APtr);
	HIDESBASE bool __fastcall Insert(int Index, void * APtr);
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
public:
	#pragma option push -w-inl
	/* TJclPtrArrayList.Create */ inline __fastcall TJclPtrArraySet(int ACapacity)/* overload */ : Jclarraylists::TJclPtrArrayList(ACapacity) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclPtrArrayList.Destroy */ inline __fastcall virtual ~TJclPtrArraySet(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclPtrEqualityComparer;	/* Jclcontainerintf::IJclPtrEqualityComparer */
	void *__IJclPtrComparer;	/* Jclcontainerintf::IJclPtrComparer */
	void *__IJclPtrArray;	/* Jclcontainerintf::IJclPtrArray */
	void *__IJclPtrSet;	/* Jclcontainerintf::IJclPtrSet */
	
public:
	operator IJclPtrSet*(void) { return (IJclPtrSet*)&__IJclPtrSet; }
	operator IJclPtrArray*(void) { return (IJclPtrArray*)&__IJclPtrArray; }
	operator IJclPtrList*(void) { return (IJclPtrList*)&__IJclPtrArray; }
	operator IJclPtrCollection*(void) { return (IJclPtrCollection*)&__IJclPtrSet; }
	operator IJclPtrComparer*(void) { return (IJclPtrComparer*)&__IJclPtrComparer; }
	operator IJclPtrEqualityComparer*(void) { return (IJclPtrEqualityComparer*)&__IJclPtrEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclPtrSet; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrSet; }
	
};


class DELPHICLASS TJclArraySet;
class PASCALIMPLEMENTATION TJclArraySet : public Jclarraylists::TJclArrayList 
{
	typedef Jclarraylists::TJclArrayList inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int __fastcall BinarySearch(System::TObject* AObject);
	
public:
	HIDESBASE bool __fastcall Add(System::TObject* AObject);
	HIDESBASE bool __fastcall AddAll(const Jclcontainerintf::_di_IJclCollection ACollection);
	HIDESBASE bool __fastcall Contains(System::TObject* AObject);
	HIDESBASE bool __fastcall Insert(int Index, System::TObject* AObject);
	void __fastcall Intersect(const Jclcontainerintf::_di_IJclCollection ACollection);
	void __fastcall Subtract(const Jclcontainerintf::_di_IJclCollection ACollection);
	void __fastcall Union(const Jclcontainerintf::_di_IJclCollection ACollection);
public:
	#pragma option push -w-inl
	/* TJclArrayList.Create */ inline __fastcall TJclArraySet(int ACapacity, bool AOwnsObjects)/* overload */ : Jclarraylists::TJclArrayList(ACapacity, AOwnsObjects) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclArrayList.Destroy */ inline __fastcall virtual ~TJclArraySet(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclObjectOwner;	/* Jclcontainerintf::IJclObjectOwner */
	void *__IJclEqualityComparer;	/* Jclcontainerintf::IJclEqualityComparer */
	void *__IJclComparer;	/* Jclcontainerintf::IJclComparer */
	void *__IJclArray;	/* Jclcontainerintf::IJclArray */
	void *__IJclSet;	/* Jclcontainerintf::IJclSet */
	
public:
	operator IJclSet*(void) { return (IJclSet*)&__IJclSet; }
	operator IJclArray*(void) { return (IJclArray*)&__IJclArray; }
	operator IJclList*(void) { return (IJclList*)&__IJclArray; }
	operator IJclCollection*(void) { return (IJclCollection*)&__IJclSet; }
	operator IJclComparer*(void) { return (IJclComparer*)&__IJclComparer; }
	operator IJclEqualityComparer*(void) { return (IJclEqualityComparer*)&__IJclEqualityComparer; }
	operator IJclObjectOwner*(void) { return (IJclObjectOwner*)&__IJclObjectOwner; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclSet; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSet; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jclarraysets */
using namespace Jclarraysets;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclarraysets
