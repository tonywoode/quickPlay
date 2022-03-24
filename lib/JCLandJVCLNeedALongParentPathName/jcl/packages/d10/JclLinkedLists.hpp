// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcllinkedlists.pas' rev: 10.00

#ifndef JcllinkedlistsHPP
#define JcllinkedlistsHPP

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
#include <Jclabstractcontainers.hpp>	// Pascal unit
#include <Jclcontainerintf.hpp>	// Pascal unit
#include <Jclsynch.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jcllinkedlists
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TItrStart { isFirst, isLast };
#pragma option pop

class DELPHICLASS TJclIntfLinkedListItem;
class PASCALIMPLEMENTATION TJclIntfLinkedListItem : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	System::_di_IInterface Value;
	TJclIntfLinkedListItem* Next;
	TJclIntfLinkedListItem* Previous;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntfLinkedListItem(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntfLinkedListItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclIntfLinkedList;
class PASCALIMPLEMENTATION TJclIntfLinkedList : public Jclabstractcontainers::TJclIntfAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntfAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclIntfLinkedListItem* FStart;
	TJclIntfLinkedListItem* FEnd;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntfLinkedList(const Jclcontainerintf::_di_IJclIntfCollection ACollection);
	__fastcall virtual ~TJclIntfLinkedList(void);
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
	void *__IJclIntfEqualityComparer;	/* Jclcontainerintf::IJclIntfEqualityComparer */
	void *__IJclIntfList;	/* Jclcontainerintf::IJclIntfList */
	
public:
	operator IJclIntfList*(void) { return (IJclIntfList*)&__IJclIntfList; }
	operator IJclIntfCollection*(void) { return (IJclIntfCollection*)&__IJclIntfList; }
	operator IJclIntfEqualityComparer*(void) { return (IJclIntfEqualityComparer*)&__IJclIntfEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfList; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfList; }
	
};


class DELPHICLASS TJclIntfLinkedListIterator;
class PASCALIMPLEMENTATION TJclIntfLinkedListIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	TJclIntfLinkedListItem* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclIntfList FOwnList;
	Jclcontainerintf::_di_IJclIntfEqualityComparer FEqualityComparer;
	
public:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	__fastcall TJclIntfLinkedListIterator(const Jclcontainerintf::_di_IJclIntfList AOwnList, TJclIntfLinkedListItem* ACursor, bool AValid, TItrStart AStart);
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
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclIntfLinkedListIterator(void) { }
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


class DELPHICLASS TJclAnsiStrLinkedListItem;
class PASCALIMPLEMENTATION TJclAnsiStrLinkedListItem : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	AnsiString Value;
	TJclAnsiStrLinkedListItem* Next;
	TJclAnsiStrLinkedListItem* Previous;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclAnsiStrLinkedListItem(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclAnsiStrLinkedListItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclAnsiStrLinkedList;
class PASCALIMPLEMENTATION TJclAnsiStrLinkedList : public Jclabstractcontainers::TJclAnsiStrAbstractCollection 
{
	typedef Jclabstractcontainers::TJclAnsiStrAbstractCollection inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclAnsiStrLinkedListItem* FStart;
	TJclAnsiStrLinkedListItem* FEnd;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclAnsiStrLinkedList(const Jclcontainerintf::_di_IJclAnsiStrCollection ACollection);
	__fastcall virtual ~TJclAnsiStrLinkedList(void);
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
	void *__IJclAnsiStrEqualityComparer;	/* Jclcontainerintf::IJclAnsiStrEqualityComparer */
	void *__IJclAnsiStrList;	/* Jclcontainerintf::IJclAnsiStrList */
	
public:
	operator IJclAnsiStrList*(void) { return (IJclAnsiStrList*)&__IJclAnsiStrList; }
	operator IJclAnsiStrCollection*(void) { return (IJclAnsiStrCollection*)&__IJclAnsiStrList; }
	operator IJclAnsiStrEqualityComparer*(void) { return (IJclAnsiStrEqualityComparer*)&__IJclAnsiStrEqualityComparer; }
	operator IJclAnsiStrFlatContainer*(void) { return (IJclAnsiStrFlatContainer*)&__IJclAnsiStrList; }
	operator IJclAnsiStrContainer*(void) { return (IJclAnsiStrContainer*)&__IJclAnsiStrList; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclAnsiStrList; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclAnsiStrList; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrList; }
	
};


class DELPHICLASS TJclAnsiStrLinkedListIterator;
class PASCALIMPLEMENTATION TJclAnsiStrLinkedListIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	TJclAnsiStrLinkedListItem* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclAnsiStrList FOwnList;
	Jclcontainerintf::_di_IJclAnsiStrEqualityComparer FEqualityComparer;
	
public:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	__fastcall TJclAnsiStrLinkedListIterator(const Jclcontainerintf::_di_IJclAnsiStrList AOwnList, TJclAnsiStrLinkedListItem* ACursor, bool AValid, TItrStart AStart);
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
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclAnsiStrLinkedListIterator(void) { }
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


class DELPHICLASS TJclWideStrLinkedListItem;
class PASCALIMPLEMENTATION TJclWideStrLinkedListItem : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	WideString Value;
	TJclWideStrLinkedListItem* Next;
	TJclWideStrLinkedListItem* Previous;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclWideStrLinkedListItem(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclWideStrLinkedListItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclWideStrLinkedList;
class PASCALIMPLEMENTATION TJclWideStrLinkedList : public Jclabstractcontainers::TJclWideStrAbstractCollection 
{
	typedef Jclabstractcontainers::TJclWideStrAbstractCollection inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclWideStrLinkedListItem* FStart;
	TJclWideStrLinkedListItem* FEnd;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclWideStrLinkedList(const Jclcontainerintf::_di_IJclWideStrCollection ACollection);
	__fastcall virtual ~TJclWideStrLinkedList(void);
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
	void *__IJclWideStrEqualityComparer;	/* Jclcontainerintf::IJclWideStrEqualityComparer */
	void *__IJclWideStrList;	/* Jclcontainerintf::IJclWideStrList */
	
public:
	operator IJclWideStrList*(void) { return (IJclWideStrList*)&__IJclWideStrList; }
	operator IJclWideStrCollection*(void) { return (IJclWideStrCollection*)&__IJclWideStrList; }
	operator IJclWideStrEqualityComparer*(void) { return (IJclWideStrEqualityComparer*)&__IJclWideStrEqualityComparer; }
	operator IJclWideStrFlatContainer*(void) { return (IJclWideStrFlatContainer*)&__IJclWideStrList; }
	operator IJclWideStrContainer*(void) { return (IJclWideStrContainer*)&__IJclWideStrList; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclWideStrList; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclWideStrList; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrList; }
	
};


class DELPHICLASS TJclWideStrLinkedListIterator;
class PASCALIMPLEMENTATION TJclWideStrLinkedListIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	TJclWideStrLinkedListItem* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclWideStrList FOwnList;
	Jclcontainerintf::_di_IJclWideStrEqualityComparer FEqualityComparer;
	
public:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	__fastcall TJclWideStrLinkedListIterator(const Jclcontainerintf::_di_IJclWideStrList AOwnList, TJclWideStrLinkedListItem* ACursor, bool AValid, TItrStart AStart);
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
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclWideStrLinkedListIterator(void) { }
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


typedef TJclAnsiStrLinkedList TJclStrLinkedList;
;

class DELPHICLASS TJclSingleLinkedListItem;
class PASCALIMPLEMENTATION TJclSingleLinkedListItem : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	float Value;
	TJclSingleLinkedListItem* Next;
	TJclSingleLinkedListItem* Previous;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclSingleLinkedListItem(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclSingleLinkedListItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclSingleLinkedList;
class PASCALIMPLEMENTATION TJclSingleLinkedList : public Jclabstractcontainers::TJclSingleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclSingleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclSingleLinkedListItem* FStart;
	TJclSingleLinkedListItem* FEnd;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclSingleLinkedList(const Jclcontainerintf::_di_IJclSingleCollection ACollection);
	__fastcall virtual ~TJclSingleLinkedList(void);
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
	void *__IJclSingleEqualityComparer;	/* Jclcontainerintf::IJclSingleEqualityComparer */
	void *__IJclSingleList;	/* Jclcontainerintf::IJclSingleList */
	
public:
	operator IJclSingleList*(void) { return (IJclSingleList*)&__IJclSingleList; }
	operator IJclSingleCollection*(void) { return (IJclSingleCollection*)&__IJclSingleList; }
	operator IJclSingleEqualityComparer*(void) { return (IJclSingleEqualityComparer*)&__IJclSingleEqualityComparer; }
	operator IJclSingleContainer*(void) { return (IJclSingleContainer*)&__IJclSingleList; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclSingleList; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleList; }
	
};


class DELPHICLASS TJclSingleLinkedListIterator;
class PASCALIMPLEMENTATION TJclSingleLinkedListIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	TJclSingleLinkedListItem* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclSingleList FOwnList;
	Jclcontainerintf::_di_IJclSingleEqualityComparer FEqualityComparer;
	
public:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	__fastcall TJclSingleLinkedListIterator(const Jclcontainerintf::_di_IJclSingleList AOwnList, TJclSingleLinkedListItem* ACursor, bool AValid, TItrStart AStart);
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
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclSingleLinkedListIterator(void) { }
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


class DELPHICLASS TJclDoubleLinkedListItem;
class PASCALIMPLEMENTATION TJclDoubleLinkedListItem : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	double Value;
	TJclDoubleLinkedListItem* Next;
	TJclDoubleLinkedListItem* Previous;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclDoubleLinkedListItem(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclDoubleLinkedListItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclDoubleLinkedList;
class PASCALIMPLEMENTATION TJclDoubleLinkedList : public Jclabstractcontainers::TJclDoubleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclDoubleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclDoubleLinkedListItem* FStart;
	TJclDoubleLinkedListItem* FEnd;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclDoubleLinkedList(const Jclcontainerintf::_di_IJclDoubleCollection ACollection);
	__fastcall virtual ~TJclDoubleLinkedList(void);
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
	void *__IJclDoubleEqualityComparer;	/* Jclcontainerintf::IJclDoubleEqualityComparer */
	void *__IJclDoubleList;	/* Jclcontainerintf::IJclDoubleList */
	
public:
	operator IJclDoubleList*(void) { return (IJclDoubleList*)&__IJclDoubleList; }
	operator IJclDoubleCollection*(void) { return (IJclDoubleCollection*)&__IJclDoubleList; }
	operator IJclDoubleEqualityComparer*(void) { return (IJclDoubleEqualityComparer*)&__IJclDoubleEqualityComparer; }
	operator IJclDoubleContainer*(void) { return (IJclDoubleContainer*)&__IJclDoubleList; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclDoubleList; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleList; }
	
};


class DELPHICLASS TJclDoubleLinkedListIterator;
class PASCALIMPLEMENTATION TJclDoubleLinkedListIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	TJclDoubleLinkedListItem* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclDoubleList FOwnList;
	Jclcontainerintf::_di_IJclDoubleEqualityComparer FEqualityComparer;
	
public:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	__fastcall TJclDoubleLinkedListIterator(const Jclcontainerintf::_di_IJclDoubleList AOwnList, TJclDoubleLinkedListItem* ACursor, bool AValid, TItrStart AStart);
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
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclDoubleLinkedListIterator(void) { }
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


class DELPHICLASS TJclExtendedLinkedListItem;
class PASCALIMPLEMENTATION TJclExtendedLinkedListItem : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	Extended Value;
	TJclExtendedLinkedListItem* Next;
	TJclExtendedLinkedListItem* Previous;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclExtendedLinkedListItem(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclExtendedLinkedListItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclExtendedLinkedList;
class PASCALIMPLEMENTATION TJclExtendedLinkedList : public Jclabstractcontainers::TJclExtendedAbstractContainer 
{
	typedef Jclabstractcontainers::TJclExtendedAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclExtendedLinkedListItem* FStart;
	TJclExtendedLinkedListItem* FEnd;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclExtendedLinkedList(const Jclcontainerintf::_di_IJclExtendedCollection ACollection);
	__fastcall virtual ~TJclExtendedLinkedList(void);
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
	void *__IJclExtendedEqualityComparer;	/* Jclcontainerintf::IJclExtendedEqualityComparer */
	void *__IJclExtendedList;	/* Jclcontainerintf::IJclExtendedList */
	
public:
	operator IJclExtendedList*(void) { return (IJclExtendedList*)&__IJclExtendedList; }
	operator IJclExtendedCollection*(void) { return (IJclExtendedCollection*)&__IJclExtendedList; }
	operator IJclExtendedEqualityComparer*(void) { return (IJclExtendedEqualityComparer*)&__IJclExtendedEqualityComparer; }
	operator IJclExtendedContainer*(void) { return (IJclExtendedContainer*)&__IJclExtendedList; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclExtendedList; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedList; }
	
};


class DELPHICLASS TJclExtendedLinkedListIterator;
class PASCALIMPLEMENTATION TJclExtendedLinkedListIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	TJclExtendedLinkedListItem* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclExtendedList FOwnList;
	Jclcontainerintf::_di_IJclExtendedEqualityComparer FEqualityComparer;
	
public:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	__fastcall TJclExtendedLinkedListIterator(const Jclcontainerintf::_di_IJclExtendedList AOwnList, TJclExtendedLinkedListItem* ACursor, bool AValid, TItrStart AStart);
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
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclExtendedLinkedListIterator(void) { }
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


typedef TJclExtendedLinkedList TJclFloatLinkedList;
;

class DELPHICLASS TJclIntegerLinkedListItem;
class PASCALIMPLEMENTATION TJclIntegerLinkedListItem : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Value;
	TJclIntegerLinkedListItem* Next;
	TJclIntegerLinkedListItem* Previous;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntegerLinkedListItem(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntegerLinkedListItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclIntegerLinkedList;
class PASCALIMPLEMENTATION TJclIntegerLinkedList : public Jclabstractcontainers::TJclIntegerAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntegerAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclIntegerLinkedListItem* FStart;
	TJclIntegerLinkedListItem* FEnd;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntegerLinkedList(const Jclcontainerintf::_di_IJclIntegerCollection ACollection);
	__fastcall virtual ~TJclIntegerLinkedList(void);
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
	void *__IJclIntegerEqualityComparer;	/* Jclcontainerintf::IJclIntegerEqualityComparer */
	void *__IJclIntegerList;	/* Jclcontainerintf::IJclIntegerList */
	
public:
	operator IJclIntegerList*(void) { return (IJclIntegerList*)&__IJclIntegerList; }
	operator IJclIntegerCollection*(void) { return (IJclIntegerCollection*)&__IJclIntegerList; }
	operator IJclIntegerEqualityComparer*(void) { return (IJclIntegerEqualityComparer*)&__IJclIntegerEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntegerList; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerList; }
	
};


class DELPHICLASS TJclIntegerLinkedListIterator;
class PASCALIMPLEMENTATION TJclIntegerLinkedListIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	TJclIntegerLinkedListItem* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclIntegerList FOwnList;
	Jclcontainerintf::_di_IJclIntegerEqualityComparer FEqualityComparer;
	
public:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	__fastcall TJclIntegerLinkedListIterator(const Jclcontainerintf::_di_IJclIntegerList AOwnList, TJclIntegerLinkedListItem* ACursor, bool AValid, TItrStart AStart);
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
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclIntegerLinkedListIterator(void) { }
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


class DELPHICLASS TJclCardinalLinkedListItem;
class PASCALIMPLEMENTATION TJclCardinalLinkedListItem : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	unsigned Value;
	TJclCardinalLinkedListItem* Next;
	TJclCardinalLinkedListItem* Previous;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclCardinalLinkedListItem(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclCardinalLinkedListItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclCardinalLinkedList;
class PASCALIMPLEMENTATION TJclCardinalLinkedList : public Jclabstractcontainers::TJclCardinalAbstractContainer 
{
	typedef Jclabstractcontainers::TJclCardinalAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclCardinalLinkedListItem* FStart;
	TJclCardinalLinkedListItem* FEnd;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclCardinalLinkedList(const Jclcontainerintf::_di_IJclCardinalCollection ACollection);
	__fastcall virtual ~TJclCardinalLinkedList(void);
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
	void *__IJclCardinalEqualityComparer;	/* Jclcontainerintf::IJclCardinalEqualityComparer */
	void *__IJclCardinalList;	/* Jclcontainerintf::IJclCardinalList */
	
public:
	operator IJclCardinalList*(void) { return (IJclCardinalList*)&__IJclCardinalList; }
	operator IJclCardinalCollection*(void) { return (IJclCardinalCollection*)&__IJclCardinalList; }
	operator IJclCardinalEqualityComparer*(void) { return (IJclCardinalEqualityComparer*)&__IJclCardinalEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclCardinalList; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalList; }
	
};


class DELPHICLASS TJclCardinalLinkedListIterator;
class PASCALIMPLEMENTATION TJclCardinalLinkedListIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	TJclCardinalLinkedListItem* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclCardinalList FOwnList;
	Jclcontainerintf::_di_IJclCardinalEqualityComparer FEqualityComparer;
	
public:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	__fastcall TJclCardinalLinkedListIterator(const Jclcontainerintf::_di_IJclCardinalList AOwnList, TJclCardinalLinkedListItem* ACursor, bool AValid, TItrStart AStart);
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
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclCardinalLinkedListIterator(void) { }
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


class DELPHICLASS TJclInt64LinkedListItem;
class PASCALIMPLEMENTATION TJclInt64LinkedListItem : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	__int64 Value;
	TJclInt64LinkedListItem* Next;
	TJclInt64LinkedListItem* Previous;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclInt64LinkedListItem(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclInt64LinkedListItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclInt64LinkedList;
class PASCALIMPLEMENTATION TJclInt64LinkedList : public Jclabstractcontainers::TJclInt64AbstractContainer 
{
	typedef Jclabstractcontainers::TJclInt64AbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclInt64LinkedListItem* FStart;
	TJclInt64LinkedListItem* FEnd;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclInt64LinkedList(const Jclcontainerintf::_di_IJclInt64Collection ACollection);
	__fastcall virtual ~TJclInt64LinkedList(void);
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
	void *__IJclInt64EqualityComparer;	/* Jclcontainerintf::IJclInt64EqualityComparer */
	void *__IJclInt64List;	/* Jclcontainerintf::IJclInt64List */
	
public:
	operator IJclInt64List*(void) { return (IJclInt64List*)&__IJclInt64List; }
	operator IJclInt64Collection*(void) { return (IJclInt64Collection*)&__IJclInt64List; }
	operator IJclInt64EqualityComparer*(void) { return (IJclInt64EqualityComparer*)&__IJclInt64EqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclInt64List; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64List; }
	
};


class DELPHICLASS TJclInt64LinkedListIterator;
class PASCALIMPLEMENTATION TJclInt64LinkedListIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	TJclInt64LinkedListItem* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclInt64List FOwnList;
	Jclcontainerintf::_di_IJclInt64EqualityComparer FEqualityComparer;
	
public:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	__fastcall TJclInt64LinkedListIterator(const Jclcontainerintf::_di_IJclInt64List AOwnList, TJclInt64LinkedListItem* ACursor, bool AValid, TItrStart AStart);
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
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclInt64LinkedListIterator(void) { }
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


class DELPHICLASS TJclPtrLinkedListItem;
class PASCALIMPLEMENTATION TJclPtrLinkedListItem : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	void *Value;
	TJclPtrLinkedListItem* Next;
	TJclPtrLinkedListItem* Previous;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclPtrLinkedListItem(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclPtrLinkedListItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclPtrLinkedList;
class PASCALIMPLEMENTATION TJclPtrLinkedList : public Jclabstractcontainers::TJclPtrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclPtrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclPtrLinkedListItem* FStart;
	TJclPtrLinkedListItem* FEnd;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclPtrLinkedList(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	__fastcall virtual ~TJclPtrLinkedList(void);
	bool __fastcall Add(void * APtr);
	bool __fastcall AddAll(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	void __fastcall Clear(void);
	bool __fastcall CollectionEquals(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
	bool __fastcall Contains(void * APtr);
	bool __fastcall ContainsAll(const Jclcontainerintf::_di_IJclPtrCollection ACollection);
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
	void *__IJclPtrEqualityComparer;	/* Jclcontainerintf::IJclPtrEqualityComparer */
	void *__IJclPtrList;	/* Jclcontainerintf::IJclPtrList */
	
public:
	operator IJclPtrList*(void) { return (IJclPtrList*)&__IJclPtrList; }
	operator IJclPtrCollection*(void) { return (IJclPtrCollection*)&__IJclPtrList; }
	operator IJclPtrEqualityComparer*(void) { return (IJclPtrEqualityComparer*)&__IJclPtrEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclPtrList; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrList; }
	
};


class DELPHICLASS TJclPtrLinkedListIterator;
class PASCALIMPLEMENTATION TJclPtrLinkedListIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	TJclPtrLinkedListItem* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclPtrList FOwnList;
	Jclcontainerintf::_di_IJclPtrEqualityComparer FEqualityComparer;
	
public:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	__fastcall TJclPtrLinkedListIterator(const Jclcontainerintf::_di_IJclPtrList AOwnList, TJclPtrLinkedListItem* ACursor, bool AValid, TItrStart AStart);
	bool __fastcall Add(void * AValue);
	void __fastcall Extract(void);
	void * __fastcall GetPointer(void);
	bool __fastcall HasNext(void);
	bool __fastcall HasPrevious(void);
	bool __fastcall Insert(void * AValue);
	bool __fastcall IteratorEquals(const Jclcontainerintf::_di_IJclPtrIterator AIterator);
	void * __fastcall Next(void);
	int __fastcall NextIndex(void);
	void * __fastcall Previous(void);
	int __fastcall PreviousIndex(void);
	void __fastcall Remove(void);
	void __fastcall Reset(void);
	void __fastcall SetPointer(void * AValue);
	bool __fastcall MoveNext(void);
	__property void * Current = {read=GetPointer};
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPtrLinkedListIterator(void) { }
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


class DELPHICLASS TJclLinkedListItem;
class PASCALIMPLEMENTATION TJclLinkedListItem : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	System::TObject* Value;
	TJclLinkedListItem* Next;
	TJclLinkedListItem* Previous;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclLinkedListItem(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclLinkedListItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclLinkedList;
class PASCALIMPLEMENTATION TJclLinkedList : public Jclabstractcontainers::TJclAbstractContainer 
{
	typedef Jclabstractcontainers::TJclAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclLinkedListItem* FStart;
	TJclLinkedListItem* FEnd;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclLinkedList(const Jclcontainerintf::_di_IJclCollection ACollection, bool AOwnsObjects);
	__fastcall virtual ~TJclLinkedList(void);
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
	void *__IJclObjectOwner;	/* Jclcontainerintf::IJclObjectOwner */
	void *__IJclEqualityComparer;	/* Jclcontainerintf::IJclEqualityComparer */
	void *__IJclList;	/* Jclcontainerintf::IJclList */
	
public:
	operator IJclList*(void) { return (IJclList*)&__IJclList; }
	operator IJclCollection*(void) { return (IJclCollection*)&__IJclList; }
	operator IJclEqualityComparer*(void) { return (IJclEqualityComparer*)&__IJclEqualityComparer; }
	operator IJclObjectOwner*(void) { return (IJclObjectOwner*)&__IJclObjectOwner; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclList; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclList; }
	
};


class DELPHICLASS TJclLinkedListIterator;
class PASCALIMPLEMENTATION TJclLinkedListIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
private:
	TJclLinkedListItem* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclList FOwnList;
	Jclcontainerintf::_di_IJclEqualityComparer FEqualityComparer;
	
public:
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	__fastcall TJclLinkedListIterator(const Jclcontainerintf::_di_IJclList AOwnList, TJclLinkedListItem* ACursor, bool AValid, TItrStart AStart);
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
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclLinkedListIterator(void) { }
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

}	/* namespace Jcllinkedlists */
using namespace Jcllinkedlists;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcllinkedlists
