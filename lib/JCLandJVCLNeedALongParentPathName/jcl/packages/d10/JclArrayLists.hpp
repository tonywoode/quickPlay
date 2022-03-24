// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclarraylists.pas' rev: 10.00

#ifndef JclarraylistsHPP
#define JclarraylistsHPP

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
#include <Jclsynch.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclarraylists
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TItrStart { isFirst, isLast };
#pragma option pop

class DELPHICLASS TJclIntfArrayList;
class PASCALIMPLEMENTATION TJclIntfArrayList : public Jclabstractcontainers::TJclIntfAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntfAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<System::_di_IInterface >  FElementData;
	System::_di_IInterface __fastcall RaiseOutOfBoundsError();
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntfArrayList(int ACapacity)/* overload */;
	__fastcall TJclIntfArrayList(const Jclcontainerintf::_di_IJclIntfCollection ACollection)/* overload */;
	__fastcall virtual ~TJclIntfArrayList(void);
	virtual void __fastcall SetCapacity(int Value);
	bool __fastcall Add(const System::_di_IInterface AInterface);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclIntfCollection ACollection);
	void __fastcall Clear(void);
	bool __fastcall Contains(const System::_di_IInterface AInterface);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclIntfCollection ACollection);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclIntfCollection ACollection);
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
	System::_di_IInterface __fastcall Delete(int Index);
	System::_di_IInterface __fastcall ExtractIndex(int Index);
	System::_di_IInterface __fastcall GetObject(int Index);
	int __fastcall IndexOf(const System::_di_IInterface AInterface);
	bool __fastcall Insert(int Index, const System::_di_IInterface AInterface);
	bool __fastcall InsertAll(int Index, const Jclcontainerintf::_di_IJclIntfCollection ACollection);
	int __fastcall LastIndexOf(const System::_di_IInterface AInterface);
	void __fastcall SetObject(int Index, const System::_di_IInterface AInterface);
	Jclcontainerintf::_di_IJclIntfList __fastcall SubList(int First, int Count);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfEqualityComparer;	/* Jclcontainerintf::IJclIntfEqualityComparer */
	void *__IJclIntfArray;	/* Jclcontainerintf::IJclIntfArray */
	
public:
	operator IJclIntfArray*(void) { return (IJclIntfArray*)&__IJclIntfArray; }
	operator IJclIntfList*(void) { return (IJclIntfList*)&__IJclIntfArray; }
	operator IJclIntfCollection*(void) { return (IJclIntfCollection*)&__IJclIntfArray; }
	operator IJclIntfEqualityComparer*(void) { return (IJclIntfEqualityComparer*)&__IJclIntfEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfArray; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfArray; }
	
};


class DELPHICLASS TJclIntfArrayIterator;
class PASCALIMPLEMENTATION TJclIntfArrayIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	int FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclIntfList FOwnList;
	
protected:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	
public:
	__fastcall TJclIntfArrayIterator(const Jclcontainerintf::_di_IJclIntfList AOwnList, int ACursor, bool AValid, TItrStart AStart);
	bool __fastcall Add(const System::_di_IInterface AInterface);
	void __fastcall Extract(void);
	System::_di_IInterface __fastcall GetObject();
	bool __fastcall HasNext(void);
	bool __fastcall HasPrevious(void);
	bool __fastcall Insert(const System::_di_IInterface AInterface);
	bool __fastcall IteratorEquals(const Jclcontainerintf::_di_IJclIntfIterator AIterator);
	System::_di_IInterface __fastcall Next();
	int __fastcall NextIndex(void);
	System::_di_IInterface __fastcall Previous();
	int __fastcall PreviousIndex(void);
	void __fastcall Remove(void);
	void __fastcall Reset(void);
	void __fastcall SetObject(const System::_di_IInterface AInterface);
	bool __fastcall MoveNext(void);
	__property System::_di_IInterface Current = {read=GetObject};
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclIntfArrayIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfIterator;	/* Jclcontainerintf::IJclIntfIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfIterator; }
	operator IJclIntfIterator*(void) { return (IJclIntfIterator*)&__IJclIntfIterator; }
	
};


class DELPHICLASS TJclAnsiStrArrayList;
class PASCALIMPLEMENTATION TJclAnsiStrArrayList : public Jclabstractcontainers::TJclAnsiStrAbstractCollection 
{
	typedef Jclabstractcontainers::TJclAnsiStrAbstractCollection inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<AnsiString >  FElementData;
	AnsiString __fastcall RaiseOutOfBoundsError();
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclAnsiStrArrayList(int ACapacity)/* overload */;
	__fastcall TJclAnsiStrArrayList(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection)/* overload */;
	__fastcall virtual ~TJclAnsiStrArrayList(void);
	virtual void __fastcall SetCapacity(int Value);
	virtual bool __fastcall Add(const AnsiString AString);
	virtual bool __fastcall AddAll(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection);
	virtual void __fastcall Clear(void);
	virtual bool __fastcall Contains(const AnsiString AString);
	virtual bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection);
	virtual bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection);
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
	AnsiString __fastcall Delete(int Index);
	AnsiString __fastcall ExtractIndex(int Index);
	AnsiString __fastcall GetString(int Index);
	int __fastcall IndexOf(const AnsiString AString);
	bool __fastcall Insert(int Index, const AnsiString AString);
	bool __fastcall InsertAll(int Index, const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection);
	int __fastcall LastIndexOf(const AnsiString AString);
	void __fastcall SetString(int Index, const AnsiString AString);
	Jclcontainerintf::_di_IJclAnsiStrList __fastcall SubList(int First, int Count);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclAnsiStrEqualityComparer;	/* Jclcontainerintf::IJclAnsiStrEqualityComparer */
	void *__IJclAnsiStrArray;	/* Jclcontainerintf::IJclAnsiStrArray */
	
public:
	operator IJclAnsiStrArray*(void) { return (IJclAnsiStrArray*)&__IJclAnsiStrArray; }
	operator IJclAnsiStrList*(void) { return (IJclAnsiStrList*)&__IJclAnsiStrArray; }
	operator IJclAnsiStrCollection*(void) { return (IJclAnsiStrCollection*)&__IJclAnsiStrArray; }
	operator IJclAnsiStrEqualityComparer*(void) { return (IJclAnsiStrEqualityComparer*)&__IJclAnsiStrEqualityComparer; }
	operator IJclAnsiStrFlatContainer*(void) { return (IJclAnsiStrFlatContainer*)&__IJclAnsiStrArray; }
	operator IJclAnsiStrContainer*(void) { return (IJclAnsiStrContainer*)&__IJclAnsiStrArray; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclAnsiStrArray; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclAnsiStrArray; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrArray; }
	
};


class DELPHICLASS TJclAnsiStrArrayIterator;
class PASCALIMPLEMENTATION TJclAnsiStrArrayIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	int FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclAnsiStrList FOwnList;
	
protected:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	
public:
	__fastcall TJclAnsiStrArrayIterator(const Jclcontainerintf::_di_IJclAnsiStrList AOwnList, int ACursor, bool AValid, TItrStart AStart);
	bool __fastcall Add(const AnsiString AString);
	void __fastcall Extract(void);
	AnsiString __fastcall GetString();
	bool __fastcall HasNext(void);
	bool __fastcall HasPrevious(void);
	bool __fastcall Insert(const AnsiString AString);
	bool __fastcall IteratorEquals(const Jclcontainerintf::_di_IJclAnsiStrIterator AIterator);
	AnsiString __fastcall Next();
	int __fastcall NextIndex(void);
	AnsiString __fastcall Previous();
	int __fastcall PreviousIndex(void);
	void __fastcall Remove(void);
	void __fastcall Reset(void);
	void __fastcall SetString(const AnsiString AString);
	bool __fastcall MoveNext(void);
	__property AnsiString Current = {read=GetString};
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclAnsiStrArrayIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclAnsiStrIterator;	/* Jclcontainerintf::IJclAnsiStrIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrIterator; }
	operator IJclAnsiStrIterator*(void) { return (IJclAnsiStrIterator*)&__IJclAnsiStrIterator; }
	
};


class DELPHICLASS TJclWideStrArrayList;
class PASCALIMPLEMENTATION TJclWideStrArrayList : public Jclabstractcontainers::TJclWideStrAbstractCollection 
{
	typedef Jclabstractcontainers::TJclWideStrAbstractCollection inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<WideString >  FElementData;
	WideString __fastcall RaiseOutOfBoundsError();
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclWideStrArrayList(int ACapacity)/* overload */;
	__fastcall TJclWideStrArrayList(const Jclcontainerintf::_di_IJclWideStrCollection ACollection)/* overload */;
	__fastcall virtual ~TJclWideStrArrayList(void);
	virtual void __fastcall SetCapacity(int Value);
	virtual bool __fastcall Add(const WideString AString);
	virtual bool __fastcall AddAll(const Jclcontainerintf::_di_IJclWideStrCollection ACollection);
	virtual void __fastcall Clear(void);
	virtual bool __fastcall Contains(const WideString AString);
	virtual bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclWideStrCollection ACollection);
	virtual bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclWideStrCollection ACollection);
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
	WideString __fastcall Delete(int Index);
	WideString __fastcall ExtractIndex(int Index);
	WideString __fastcall GetString(int Index);
	int __fastcall IndexOf(const WideString AString);
	bool __fastcall Insert(int Index, const WideString AString);
	bool __fastcall InsertAll(int Index, const Jclcontainerintf::_di_IJclWideStrCollection ACollection);
	int __fastcall LastIndexOf(const WideString AString);
	void __fastcall SetString(int Index, const WideString AString);
	Jclcontainerintf::_di_IJclWideStrList __fastcall SubList(int First, int Count);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclWideStrEqualityComparer;	/* Jclcontainerintf::IJclWideStrEqualityComparer */
	void *__IJclWideStrArray;	/* Jclcontainerintf::IJclWideStrArray */
	
public:
	operator IJclWideStrArray*(void) { return (IJclWideStrArray*)&__IJclWideStrArray; }
	operator IJclWideStrList*(void) { return (IJclWideStrList*)&__IJclWideStrArray; }
	operator IJclWideStrCollection*(void) { return (IJclWideStrCollection*)&__IJclWideStrArray; }
	operator IJclWideStrEqualityComparer*(void) { return (IJclWideStrEqualityComparer*)&__IJclWideStrEqualityComparer; }
	operator IJclWideStrFlatContainer*(void) { return (IJclWideStrFlatContainer*)&__IJclWideStrArray; }
	operator IJclWideStrContainer*(void) { return (IJclWideStrContainer*)&__IJclWideStrArray; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclWideStrArray; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclWideStrArray; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrArray; }
	
};


class DELPHICLASS TJclWideStrArrayIterator;
class PASCALIMPLEMENTATION TJclWideStrArrayIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	int FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclWideStrList FOwnList;
	
protected:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	
public:
	__fastcall TJclWideStrArrayIterator(const Jclcontainerintf::_di_IJclWideStrList AOwnList, int ACursor, bool AValid, TItrStart AStart);
	bool __fastcall Add(const WideString AString);
	void __fastcall Extract(void);
	WideString __fastcall GetString();
	bool __fastcall HasNext(void);
	bool __fastcall HasPrevious(void);
	bool __fastcall Insert(const WideString AString);
	bool __fastcall IteratorEquals(const Jclcontainerintf::_di_IJclWideStrIterator AIterator);
	WideString __fastcall Next();
	int __fastcall NextIndex(void);
	WideString __fastcall Previous();
	int __fastcall PreviousIndex(void);
	void __fastcall Remove(void);
	void __fastcall Reset(void);
	void __fastcall SetString(const WideString AString);
	bool __fastcall MoveNext(void);
	__property WideString Current = {read=GetString};
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclWideStrArrayIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclWideStrIterator;	/* Jclcontainerintf::IJclWideStrIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrIterator; }
	operator IJclWideStrIterator*(void) { return (IJclWideStrIterator*)&__IJclWideStrIterator; }
	
};


typedef TJclAnsiStrArrayList TJclStrArrayList;
;

class DELPHICLASS TJclSingleArrayList;
class PASCALIMPLEMENTATION TJclSingleArrayList : public Jclabstractcontainers::TJclSingleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclSingleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<float >  FElementData;
	float __fastcall RaiseOutOfBoundsError(void);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclSingleArrayList(int ACapacity)/* overload */;
	__fastcall TJclSingleArrayList(const Jclcontainerintf::_di_IJclSingleCollection ACollection)/* overload */;
	__fastcall virtual ~TJclSingleArrayList(void);
	virtual void __fastcall SetCapacity(int Value);
	bool __fastcall Add(const float AValue);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclSingleCollection ACollection);
	void __fastcall Clear(void);
	bool __fastcall Contains(const float AValue);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclSingleCollection ACollection);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclSingleCollection ACollection);
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
	float __fastcall Delete(int Index);
	float __fastcall ExtractIndex(int Index);
	float __fastcall GetValue(int Index);
	int __fastcall IndexOf(const float AValue);
	bool __fastcall Insert(int Index, const float AValue);
	bool __fastcall InsertAll(int Index, const Jclcontainerintf::_di_IJclSingleCollection ACollection);
	int __fastcall LastIndexOf(const float AValue);
	void __fastcall SetValue(int Index, const float AValue);
	Jclcontainerintf::_di_IJclSingleList __fastcall SubList(int First, int Count);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclSingleEqualityComparer;	/* Jclcontainerintf::IJclSingleEqualityComparer */
	void *__IJclSingleArray;	/* Jclcontainerintf::IJclSingleArray */
	
public:
	operator IJclSingleArray*(void) { return (IJclSingleArray*)&__IJclSingleArray; }
	operator IJclSingleList*(void) { return (IJclSingleList*)&__IJclSingleArray; }
	operator IJclSingleCollection*(void) { return (IJclSingleCollection*)&__IJclSingleArray; }
	operator IJclSingleEqualityComparer*(void) { return (IJclSingleEqualityComparer*)&__IJclSingleEqualityComparer; }
	operator IJclSingleContainer*(void) { return (IJclSingleContainer*)&__IJclSingleArray; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclSingleArray; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleArray; }
	
};


class DELPHICLASS TJclSingleArrayIterator;
class PASCALIMPLEMENTATION TJclSingleArrayIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	int FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclSingleList FOwnList;
	
protected:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	
public:
	__fastcall TJclSingleArrayIterator(const Jclcontainerintf::_di_IJclSingleList AOwnList, int ACursor, bool AValid, TItrStart AStart);
	bool __fastcall Add(const float AValue);
	void __fastcall Extract(void);
	float __fastcall GetValue(void);
	bool __fastcall HasNext(void);
	bool __fastcall HasPrevious(void);
	bool __fastcall Insert(const float AValue);
	bool __fastcall IteratorEquals(const Jclcontainerintf::_di_IJclSingleIterator AIterator);
	float __fastcall Next(void);
	int __fastcall NextIndex(void);
	float __fastcall Previous(void);
	int __fastcall PreviousIndex(void);
	void __fastcall Remove(void);
	void __fastcall Reset(void);
	void __fastcall SetValue(const float AValue);
	bool __fastcall MoveNext(void);
	__property float Current = {read=GetValue};
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclSingleArrayIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclSingleIterator;	/* Jclcontainerintf::IJclSingleIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleIterator; }
	operator IJclSingleIterator*(void) { return (IJclSingleIterator*)&__IJclSingleIterator; }
	
};


class DELPHICLASS TJclDoubleArrayList;
class PASCALIMPLEMENTATION TJclDoubleArrayList : public Jclabstractcontainers::TJclDoubleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclDoubleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<double >  FElementData;
	double __fastcall RaiseOutOfBoundsError(void);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclDoubleArrayList(int ACapacity)/* overload */;
	__fastcall TJclDoubleArrayList(const Jclcontainerintf::_di_IJclDoubleCollection ACollection)/* overload */;
	__fastcall virtual ~TJclDoubleArrayList(void);
	virtual void __fastcall SetCapacity(int Value);
	bool __fastcall Add(const double AValue);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclDoubleCollection ACollection);
	void __fastcall Clear(void);
	bool __fastcall Contains(const double AValue);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclDoubleCollection ACollection);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclDoubleCollection ACollection);
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
	double __fastcall Delete(int Index);
	double __fastcall ExtractIndex(int Index);
	double __fastcall GetValue(int Index);
	int __fastcall IndexOf(const double AValue);
	bool __fastcall Insert(int Index, const double AValue);
	bool __fastcall InsertAll(int Index, const Jclcontainerintf::_di_IJclDoubleCollection ACollection);
	int __fastcall LastIndexOf(const double AValue);
	void __fastcall SetValue(int Index, const double AValue);
	Jclcontainerintf::_di_IJclDoubleList __fastcall SubList(int First, int Count);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclDoubleEqualityComparer;	/* Jclcontainerintf::IJclDoubleEqualityComparer */
	void *__IJclDoubleArray;	/* Jclcontainerintf::IJclDoubleArray */
	
public:
	operator IJclDoubleArray*(void) { return (IJclDoubleArray*)&__IJclDoubleArray; }
	operator IJclDoubleList*(void) { return (IJclDoubleList*)&__IJclDoubleArray; }
	operator IJclDoubleCollection*(void) { return (IJclDoubleCollection*)&__IJclDoubleArray; }
	operator IJclDoubleEqualityComparer*(void) { return (IJclDoubleEqualityComparer*)&__IJclDoubleEqualityComparer; }
	operator IJclDoubleContainer*(void) { return (IJclDoubleContainer*)&__IJclDoubleArray; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclDoubleArray; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleArray; }
	
};


class DELPHICLASS TJclDoubleArrayIterator;
class PASCALIMPLEMENTATION TJclDoubleArrayIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	int FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclDoubleList FOwnList;
	
protected:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	
public:
	__fastcall TJclDoubleArrayIterator(const Jclcontainerintf::_di_IJclDoubleList AOwnList, int ACursor, bool AValid, TItrStart AStart);
	bool __fastcall Add(const double AValue);
	void __fastcall Extract(void);
	double __fastcall GetValue(void);
	bool __fastcall HasNext(void);
	bool __fastcall HasPrevious(void);
	bool __fastcall Insert(const double AValue);
	bool __fastcall IteratorEquals(const Jclcontainerintf::_di_IJclDoubleIterator AIterator);
	double __fastcall Next(void);
	int __fastcall NextIndex(void);
	double __fastcall Previous(void);
	int __fastcall PreviousIndex(void);
	void __fastcall Remove(void);
	void __fastcall Reset(void);
	void __fastcall SetValue(const double AValue);
	bool __fastcall MoveNext(void);
	__property double Current = {read=GetValue};
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclDoubleArrayIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclDoubleIterator;	/* Jclcontainerintf::IJclDoubleIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleIterator; }
	operator IJclDoubleIterator*(void) { return (IJclDoubleIterator*)&__IJclDoubleIterator; }
	
};


class DELPHICLASS TJclExtendedArrayList;
class PASCALIMPLEMENTATION TJclExtendedArrayList : public Jclabstractcontainers::TJclExtendedAbstractContainer 
{
	typedef Jclabstractcontainers::TJclExtendedAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<Extended >  FElementData;
	Extended __fastcall RaiseOutOfBoundsError(void);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclExtendedArrayList(int ACapacity)/* overload */;
	__fastcall TJclExtendedArrayList(const Jclcontainerintf::_di_IJclExtendedCollection ACollection)/* overload */;
	__fastcall virtual ~TJclExtendedArrayList(void);
	virtual void __fastcall SetCapacity(int Value);
	bool __fastcall Add(const Extended AValue);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclExtendedCollection ACollection);
	void __fastcall Clear(void);
	bool __fastcall Contains(const Extended AValue);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclExtendedCollection ACollection);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclExtendedCollection ACollection);
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
	Extended __fastcall Delete(int Index);
	Extended __fastcall ExtractIndex(int Index);
	Extended __fastcall GetValue(int Index);
	int __fastcall IndexOf(const Extended AValue);
	bool __fastcall Insert(int Index, const Extended AValue);
	bool __fastcall InsertAll(int Index, const Jclcontainerintf::_di_IJclExtendedCollection ACollection);
	int __fastcall LastIndexOf(const Extended AValue);
	void __fastcall SetValue(int Index, const Extended AValue);
	Jclcontainerintf::_di_IJclExtendedList __fastcall SubList(int First, int Count);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclExtendedEqualityComparer;	/* Jclcontainerintf::IJclExtendedEqualityComparer */
	void *__IJclExtendedArray;	/* Jclcontainerintf::IJclExtendedArray */
	
public:
	operator IJclExtendedArray*(void) { return (IJclExtendedArray*)&__IJclExtendedArray; }
	operator IJclExtendedList*(void) { return (IJclExtendedList*)&__IJclExtendedArray; }
	operator IJclExtendedCollection*(void) { return (IJclExtendedCollection*)&__IJclExtendedArray; }
	operator IJclExtendedEqualityComparer*(void) { return (IJclExtendedEqualityComparer*)&__IJclExtendedEqualityComparer; }
	operator IJclExtendedContainer*(void) { return (IJclExtendedContainer*)&__IJclExtendedArray; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclExtendedArray; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedArray; }
	
};


class DELPHICLASS TJclExtendedArrayIterator;
class PASCALIMPLEMENTATION TJclExtendedArrayIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	int FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclExtendedList FOwnList;
	
protected:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	
public:
	__fastcall TJclExtendedArrayIterator(const Jclcontainerintf::_di_IJclExtendedList AOwnList, int ACursor, bool AValid, TItrStart AStart);
	bool __fastcall Add(const Extended AValue);
	void __fastcall Extract(void);
	Extended __fastcall GetValue(void);
	bool __fastcall HasNext(void);
	bool __fastcall HasPrevious(void);
	bool __fastcall Insert(const Extended AValue);
	bool __fastcall IteratorEquals(const Jclcontainerintf::_di_IJclExtendedIterator AIterator);
	Extended __fastcall Next(void);
	int __fastcall NextIndex(void);
	Extended __fastcall Previous(void);
	int __fastcall PreviousIndex(void);
	void __fastcall Remove(void);
	void __fastcall Reset(void);
	void __fastcall SetValue(const Extended AValue);
	bool __fastcall MoveNext(void);
	__property Extended Current = {read=GetValue};
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclExtendedArrayIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclExtendedIterator;	/* Jclcontainerintf::IJclExtendedIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedIterator; }
	operator IJclExtendedIterator*(void) { return (IJclExtendedIterator*)&__IJclExtendedIterator; }
	
};


typedef TJclExtendedArrayList TJclFloatArrayList;
;

class DELPHICLASS TJclIntegerArrayList;
class PASCALIMPLEMENTATION TJclIntegerArrayList : public Jclabstractcontainers::TJclIntegerAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntegerAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<int >  FElementData;
	int __fastcall RaiseOutOfBoundsError(void);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntegerArrayList(int ACapacity)/* overload */;
	__fastcall TJclIntegerArrayList(const Jclcontainerintf::_di_IJclIntegerCollection ACollection)/* overload */;
	__fastcall virtual ~TJclIntegerArrayList(void);
	virtual void __fastcall SetCapacity(int Value);
	bool __fastcall Add(int AValue);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclIntegerCollection ACollection);
	void __fastcall Clear(void);
	bool __fastcall Contains(int AValue);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclIntegerCollection ACollection);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclIntegerCollection ACollection);
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
	int __fastcall Delete(int Index);
	int __fastcall ExtractIndex(int Index);
	int __fastcall GetValue(int Index);
	int __fastcall IndexOf(int AValue);
	bool __fastcall Insert(int Index, int AValue);
	bool __fastcall InsertAll(int Index, const Jclcontainerintf::_di_IJclIntegerCollection ACollection);
	int __fastcall LastIndexOf(int AValue);
	void __fastcall SetValue(int Index, int AValue);
	Jclcontainerintf::_di_IJclIntegerList __fastcall SubList(int First, int Count);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntegerEqualityComparer;	/* Jclcontainerintf::IJclIntegerEqualityComparer */
	void *__IJclIntegerArray;	/* Jclcontainerintf::IJclIntegerArray */
	
public:
	operator IJclIntegerArray*(void) { return (IJclIntegerArray*)&__IJclIntegerArray; }
	operator IJclIntegerList*(void) { return (IJclIntegerList*)&__IJclIntegerArray; }
	operator IJclIntegerCollection*(void) { return (IJclIntegerCollection*)&__IJclIntegerArray; }
	operator IJclIntegerEqualityComparer*(void) { return (IJclIntegerEqualityComparer*)&__IJclIntegerEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntegerArray; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerArray; }
	
};


class DELPHICLASS TJclIntegerArrayIterator;
class PASCALIMPLEMENTATION TJclIntegerArrayIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	int FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclIntegerList FOwnList;
	
protected:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	
public:
	__fastcall TJclIntegerArrayIterator(const Jclcontainerintf::_di_IJclIntegerList AOwnList, int ACursor, bool AValid, TItrStart AStart);
	bool __fastcall Add(int AValue);
	void __fastcall Extract(void);
	int __fastcall GetValue(void);
	bool __fastcall HasNext(void);
	bool __fastcall HasPrevious(void);
	bool __fastcall Insert(int AValue);
	bool __fastcall IteratorEquals(const Jclcontainerintf::_di_IJclIntegerIterator AIterator);
	int __fastcall Next(void);
	int __fastcall NextIndex(void);
	int __fastcall Previous(void);
	int __fastcall PreviousIndex(void);
	void __fastcall Remove(void);
	void __fastcall Reset(void);
	void __fastcall SetValue(int AValue);
	bool __fastcall MoveNext(void);
	__property int Current = {read=GetValue, nodefault};
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclIntegerArrayIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclIntegerIterator;	/* Jclcontainerintf::IJclIntegerIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerIterator; }
	operator IJclIntegerIterator*(void) { return (IJclIntegerIterator*)&__IJclIntegerIterator; }
	
};


class DELPHICLASS TJclCardinalArrayList;
class PASCALIMPLEMENTATION TJclCardinalArrayList : public Jclabstractcontainers::TJclCardinalAbstractContainer 
{
	typedef Jclabstractcontainers::TJclCardinalAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<unsigned >  FElementData;
	unsigned __fastcall RaiseOutOfBoundsError(void);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclCardinalArrayList(int ACapacity)/* overload */;
	__fastcall TJclCardinalArrayList(const Jclcontainerintf::_di_IJclCardinalCollection ACollection)/* overload */;
	__fastcall virtual ~TJclCardinalArrayList(void);
	virtual void __fastcall SetCapacity(int Value);
	bool __fastcall Add(unsigned AValue);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclCardinalCollection ACollection);
	void __fastcall Clear(void);
	bool __fastcall Contains(unsigned AValue);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclCardinalCollection ACollection);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclCardinalCollection ACollection);
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
	unsigned __fastcall Delete(int Index);
	unsigned __fastcall ExtractIndex(int Index);
	unsigned __fastcall GetValue(int Index);
	int __fastcall IndexOf(unsigned AValue);
	bool __fastcall Insert(int Index, unsigned AValue);
	bool __fastcall InsertAll(int Index, const Jclcontainerintf::_di_IJclCardinalCollection ACollection);
	int __fastcall LastIndexOf(unsigned AValue);
	void __fastcall SetValue(int Index, unsigned AValue);
	Jclcontainerintf::_di_IJclCardinalList __fastcall SubList(int First, int Count);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclCardinalEqualityComparer;	/* Jclcontainerintf::IJclCardinalEqualityComparer */
	void *__IJclCardinalArray;	/* Jclcontainerintf::IJclCardinalArray */
	
public:
	operator IJclCardinalArray*(void) { return (IJclCardinalArray*)&__IJclCardinalArray; }
	operator IJclCardinalList*(void) { return (IJclCardinalList*)&__IJclCardinalArray; }
	operator IJclCardinalCollection*(void) { return (IJclCardinalCollection*)&__IJclCardinalArray; }
	operator IJclCardinalEqualityComparer*(void) { return (IJclCardinalEqualityComparer*)&__IJclCardinalEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclCardinalArray; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalArray; }
	
};


class DELPHICLASS TJclCardinalArrayIterator;
class PASCALIMPLEMENTATION TJclCardinalArrayIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	int FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclCardinalList FOwnList;
	
protected:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	
public:
	__fastcall TJclCardinalArrayIterator(const Jclcontainerintf::_di_IJclCardinalList AOwnList, int ACursor, bool AValid, TItrStart AStart);
	bool __fastcall Add(unsigned AValue);
	void __fastcall Extract(void);
	unsigned __fastcall GetValue(void);
	bool __fastcall HasNext(void);
	bool __fastcall HasPrevious(void);
	bool __fastcall Insert(unsigned AValue);
	bool __fastcall IteratorEquals(const Jclcontainerintf::_di_IJclCardinalIterator AIterator);
	unsigned __fastcall Next(void);
	int __fastcall NextIndex(void);
	unsigned __fastcall Previous(void);
	int __fastcall PreviousIndex(void);
	void __fastcall Remove(void);
	void __fastcall Reset(void);
	void __fastcall SetValue(unsigned AValue);
	bool __fastcall MoveNext(void);
	__property unsigned Current = {read=GetValue, nodefault};
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclCardinalArrayIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclCardinalIterator;	/* Jclcontainerintf::IJclCardinalIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalIterator; }
	operator IJclCardinalIterator*(void) { return (IJclCardinalIterator*)&__IJclCardinalIterator; }
	
};


class DELPHICLASS TJclInt64ArrayList;
class PASCALIMPLEMENTATION TJclInt64ArrayList : public Jclabstractcontainers::TJclInt64AbstractContainer 
{
	typedef Jclabstractcontainers::TJclInt64AbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<__int64 >  FElementData;
	__int64 __fastcall RaiseOutOfBoundsError(void);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclInt64ArrayList(int ACapacity)/* overload */;
	__fastcall TJclInt64ArrayList(const Jclcontainerintf::_di_IJclInt64Collection ACollection)/* overload */;
	__fastcall virtual ~TJclInt64ArrayList(void);
	virtual void __fastcall SetCapacity(int Value);
	bool __fastcall Add(const __int64 AValue);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclInt64Collection ACollection);
	void __fastcall Clear(void);
	bool __fastcall Contains(const __int64 AValue);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclInt64Collection ACollection);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclInt64Collection ACollection);
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
	__int64 __fastcall Delete(int Index);
	__int64 __fastcall ExtractIndex(int Index);
	__int64 __fastcall GetValue(int Index);
	int __fastcall IndexOf(const __int64 AValue);
	bool __fastcall Insert(int Index, const __int64 AValue);
	bool __fastcall InsertAll(int Index, const Jclcontainerintf::_di_IJclInt64Collection ACollection);
	int __fastcall LastIndexOf(const __int64 AValue);
	void __fastcall SetValue(int Index, const __int64 AValue);
	Jclcontainerintf::_di_IJclInt64List __fastcall SubList(int First, int Count);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclInt64EqualityComparer;	/* Jclcontainerintf::IJclInt64EqualityComparer */
	void *__IJclInt64Array;	/* Jclcontainerintf::IJclInt64Array */
	
public:
	operator IJclInt64Array*(void) { return (IJclInt64Array*)&__IJclInt64Array; }
	operator IJclInt64List*(void) { return (IJclInt64List*)&__IJclInt64Array; }
	operator IJclInt64Collection*(void) { return (IJclInt64Collection*)&__IJclInt64Array; }
	operator IJclInt64EqualityComparer*(void) { return (IJclInt64EqualityComparer*)&__IJclInt64EqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclInt64Array; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64Array; }
	
};


class DELPHICLASS TJclInt64ArrayIterator;
class PASCALIMPLEMENTATION TJclInt64ArrayIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	int FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclInt64List FOwnList;
	
protected:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	
public:
	__fastcall TJclInt64ArrayIterator(const Jclcontainerintf::_di_IJclInt64List AOwnList, int ACursor, bool AValid, TItrStart AStart);
	bool __fastcall Add(const __int64 AValue);
	void __fastcall Extract(void);
	__int64 __fastcall GetValue(void);
	bool __fastcall HasNext(void);
	bool __fastcall HasPrevious(void);
	bool __fastcall Insert(const __int64 AValue);
	bool __fastcall IteratorEquals(const Jclcontainerintf::_di_IJclInt64Iterator AIterator);
	__int64 __fastcall Next(void);
	int __fastcall NextIndex(void);
	__int64 __fastcall Previous(void);
	int __fastcall PreviousIndex(void);
	void __fastcall Remove(void);
	void __fastcall Reset(void);
	void __fastcall SetValue(const __int64 AValue);
	bool __fastcall MoveNext(void);
	__property __int64 Current = {read=GetValue};
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclInt64ArrayIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclInt64Iterator;	/* Jclcontainerintf::IJclInt64Iterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64Iterator; }
	operator IJclInt64Iterator*(void) { return (IJclInt64Iterator*)&__IJclInt64Iterator; }
	
};


class DELPHICLASS TJclPtrArrayList;
class PASCALIMPLEMENTATION TJclPtrArrayList : public Jclabstractcontainers::TJclPtrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclPtrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<void * >  FElementData;
	void * __fastcall RaiseOutOfBoundsError(void);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclPtrArrayList(int ACapacity)/* overload */;
	__fastcall TJclPtrArrayList(const Jclcontainerintf::_di_IJclPtrCollection ACollection)/* overload */;
	__fastcall virtual ~TJclPtrArrayList(void);
	virtual void __fastcall SetCapacity(int Value);
	bool __fastcall Add(void * APtr);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	void __fastcall Clear(void);
	bool __fastcall Contains(void * APtr);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	bool __fastcall Extract(void * APtr);
	bool __fastcall ExtractAll(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	Jclcontainerintf::_di_IJclPtrIterator __fastcall First();
	bool __fastcall IsEmpty(void);
	Jclcontainerintf::_di_IJclPtrIterator __fastcall Last();
	bool __fastcall Remove(void * APtr);
	bool __fastcall RemoveAll(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	bool __fastcall RetainAll(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	int __fastcall Size(void);
	Jclcontainerintf::_di_IJclPtrIterator __fastcall GetEnumerator();
	void * __fastcall Delete(int Index);
	void * __fastcall ExtractIndex(int Index);
	void * __fastcall GetPointer(int Index);
	int __fastcall IndexOf(void * APtr);
	bool __fastcall Insert(int Index, void * APtr);
	bool __fastcall InsertAll(int Index, const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	int __fastcall LastIndexOf(void * APtr);
	void __fastcall SetPointer(int Index, void * APtr);
	Jclcontainerintf::_di_IJclPtrList __fastcall SubList(int First, int Count);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclPtrEqualityComparer;	/* Jclcontainerintf::IJclPtrEqualityComparer */
	void *__IJclPtrArray;	/* Jclcontainerintf::IJclPtrArray */
	
public:
	operator IJclPtrArray*(void) { return (IJclPtrArray*)&__IJclPtrArray; }
	operator IJclPtrList*(void) { return (IJclPtrList*)&__IJclPtrArray; }
	operator IJclPtrCollection*(void) { return (IJclPtrCollection*)&__IJclPtrArray; }
	operator IJclPtrEqualityComparer*(void) { return (IJclPtrEqualityComparer*)&__IJclPtrEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclPtrArray; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrArray; }
	
};


class DELPHICLASS TJclPtrArrayIterator;
class PASCALIMPLEMENTATION TJclPtrArrayIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	int FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclPtrList FOwnList;
	
protected:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	
public:
	__fastcall TJclPtrArrayIterator(const Jclcontainerintf::_di_IJclPtrList AOwnList, int ACursor, bool AValid, TItrStart AStart);
	bool __fastcall Add(void * APtr);
	void __fastcall Extract(void);
	void * __fastcall GetPointer(void);
	bool __fastcall HasNext(void);
	bool __fastcall HasPrevious(void);
	bool __fastcall Insert(void * APtr);
	bool __fastcall IteratorEquals(const Jclcontainerintf::_di_IJclPtrIterator AIterator);
	void * __fastcall Next(void);
	int __fastcall NextIndex(void);
	void * __fastcall Previous(void);
	int __fastcall PreviousIndex(void);
	void __fastcall Remove(void);
	void __fastcall Reset(void);
	void __fastcall SetPointer(void * APtr);
	bool __fastcall MoveNext(void);
	__property void * Current = {read=GetPointer};
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPtrArrayIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclPtrIterator;	/* Jclcontainerintf::IJclPtrIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrIterator; }
	operator IJclPtrIterator*(void) { return (IJclPtrIterator*)&__IJclPtrIterator; }
	
};


class DELPHICLASS TJclArrayList;
class PASCALIMPLEMENTATION TJclArrayList : public Jclabstractcontainers::TJclAbstractContainer 
{
	typedef Jclabstractcontainers::TJclAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<System::TObject* >  FElementData;
	System::TObject* __fastcall RaiseOutOfBoundsError(void);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclArrayList(int ACapacity, bool AOwnsObjects)/* overload */;
	__fastcall TJclArrayList(const Jclcontainerintf::_di_IJclCollection ACollection, bool AOwnsObjects)/* overload */;
	__fastcall virtual ~TJclArrayList(void);
	virtual void __fastcall SetCapacity(int Value);
	bool __fastcall Add(System::TObject* AObject);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclCollection ACollection);
	void __fastcall Clear(void);
	bool __fastcall Contains(System::TObject* AObject);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclCollection ACollection);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclCollection ACollection);
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
	System::TObject* __fastcall Delete(int Index);
	System::TObject* __fastcall ExtractIndex(int Index);
	System::TObject* __fastcall GetObject(int Index);
	int __fastcall IndexOf(System::TObject* AObject);
	bool __fastcall Insert(int Index, System::TObject* AObject);
	bool __fastcall InsertAll(int Index, const Jclcontainerintf::_di_IJclCollection ACollection);
	int __fastcall LastIndexOf(System::TObject* AObject);
	void __fastcall SetObject(int Index, System::TObject* AObject);
	Jclcontainerintf::_di_IJclList __fastcall SubList(int First, int Count);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclObjectOwner;	/* Jclcontainerintf::IJclObjectOwner */
	void *__IJclEqualityComparer;	/* Jclcontainerintf::IJclEqualityComparer */
	void *__IJclArray;	/* Jclcontainerintf::IJclArray */
	
public:
	operator IJclArray*(void) { return (IJclArray*)&__IJclArray; }
	operator IJclList*(void) { return (IJclList*)&__IJclArray; }
	operator IJclCollection*(void) { return (IJclCollection*)&__IJclArray; }
	operator IJclEqualityComparer*(void) { return (IJclEqualityComparer*)&__IJclEqualityComparer; }
	operator IJclObjectOwner*(void) { return (IJclObjectOwner*)&__IJclObjectOwner; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclArray; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclArray; }
	
};


class DELPHICLASS TJclArrayIterator;
class PASCALIMPLEMENTATION TJclArrayIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	int FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclList FOwnList;
	
protected:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	
public:
	__fastcall TJclArrayIterator(const Jclcontainerintf::_di_IJclList AOwnList, int ACursor, bool AValid, TItrStart AStart);
	bool __fastcall Add(System::TObject* AObject);
	void __fastcall Extract(void);
	System::TObject* __fastcall GetObject(void);
	bool __fastcall HasNext(void);
	bool __fastcall HasPrevious(void);
	bool __fastcall Insert(System::TObject* AObject);
	bool __fastcall IteratorEquals(const Jclcontainerintf::_di_IJclIterator AIterator);
	System::TObject* __fastcall Next(void);
	int __fastcall NextIndex(void);
	System::TObject* __fastcall Previous(void);
	int __fastcall PreviousIndex(void);
	void __fastcall Remove(void);
	void __fastcall Reset(void);
	void __fastcall SetObject(System::TObject* AObject);
	bool __fastcall MoveNext(void);
	__property System::TObject* Current = {read=GetObject};
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclArrayIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclIterator;	/* Jclcontainerintf::IJclIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIterator; }
	operator IJclIterator*(void) { return (IJclIterator*)&__IJclIterator; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jclarraylists */
using namespace Jclarraylists;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclarraylists
