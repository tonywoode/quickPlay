// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclqueues.pas' rev: 10.00

#ifndef JclqueuesHPP
#define JclqueuesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclabstractcontainers.hpp>	// Pascal unit
#include <Jclcontainerintf.hpp>	// Pascal unit
#include <Jclsynch.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclqueues
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TJclIntfQueue;
class PASCALIMPLEMENTATION TJclIntfQueue : public Jclabstractcontainers::TJclIntfAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntfAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<System::_di_IInterface >  FElements;
	int FHead;
	int FTail;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntfQueue(int ACapacity);
	__fastcall virtual ~TJclIntfQueue(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(const System::_di_IInterface AInterface);
	System::_di_IInterface __fastcall Dequeue();
	bool __fastcall Empty(void);
	bool __fastcall Enqueue(const System::_di_IInterface AInterface);
	System::_di_IInterface __fastcall Peek();
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfEqualityComparer;	/* Jclcontainerintf::IJclIntfEqualityComparer */
	void *__IJclIntfQueue;	/* Jclcontainerintf::IJclIntfQueue */
	
public:
	operator IJclIntfQueue*(void) { return (IJclIntfQueue*)&__IJclIntfQueue; }
	operator IJclIntfEqualityComparer*(void) { return (IJclIntfEqualityComparer*)&__IJclIntfEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfQueue; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfQueue; }
	
};


class DELPHICLASS TJclAnsiStrQueue;
class PASCALIMPLEMENTATION TJclAnsiStrQueue : public Jclabstractcontainers::TJclAnsiStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclAnsiStrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<AnsiString >  FElements;
	int FHead;
	int FTail;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclAnsiStrQueue(int ACapacity);
	__fastcall virtual ~TJclAnsiStrQueue(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(const AnsiString AString);
	AnsiString __fastcall Dequeue();
	bool __fastcall Empty(void);
	bool __fastcall Enqueue(const AnsiString AString);
	AnsiString __fastcall Peek();
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclAnsiStrEqualityComparer;	/* Jclcontainerintf::IJclAnsiStrEqualityComparer */
	void *__IJclAnsiStrQueue;	/* Jclcontainerintf::IJclAnsiStrQueue */
	
public:
	operator IJclAnsiStrQueue*(void) { return (IJclAnsiStrQueue*)&__IJclAnsiStrQueue; }
	operator IJclAnsiStrEqualityComparer*(void) { return (IJclAnsiStrEqualityComparer*)&__IJclAnsiStrEqualityComparer; }
	operator IJclAnsiStrContainer*(void) { return (IJclAnsiStrContainer*)&__IJclAnsiStrQueue; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclAnsiStrQueue; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclAnsiStrQueue; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrQueue; }
	
};


class DELPHICLASS TJclWideStrQueue;
class PASCALIMPLEMENTATION TJclWideStrQueue : public Jclabstractcontainers::TJclWideStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclWideStrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<WideString >  FElements;
	int FHead;
	int FTail;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclWideStrQueue(int ACapacity);
	__fastcall virtual ~TJclWideStrQueue(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(const WideString AString);
	WideString __fastcall Dequeue();
	bool __fastcall Empty(void);
	bool __fastcall Enqueue(const WideString AString);
	WideString __fastcall Peek();
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclWideStrEqualityComparer;	/* Jclcontainerintf::IJclWideStrEqualityComparer */
	void *__IJclWideStrQueue;	/* Jclcontainerintf::IJclWideStrQueue */
	
public:
	operator IJclWideStrQueue*(void) { return (IJclWideStrQueue*)&__IJclWideStrQueue; }
	operator IJclWideStrEqualityComparer*(void) { return (IJclWideStrEqualityComparer*)&__IJclWideStrEqualityComparer; }
	operator IJclWideStrContainer*(void) { return (IJclWideStrContainer*)&__IJclWideStrQueue; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclWideStrQueue; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclWideStrQueue; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrQueue; }
	
};


typedef TJclAnsiStrQueue TJclStrQueue;
;

class DELPHICLASS TJclSingleQueue;
class PASCALIMPLEMENTATION TJclSingleQueue : public Jclabstractcontainers::TJclSingleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclSingleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<float >  FElements;
	int FHead;
	int FTail;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclSingleQueue(int ACapacity);
	__fastcall virtual ~TJclSingleQueue(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(const float AValue);
	float __fastcall Dequeue(void);
	bool __fastcall Empty(void);
	bool __fastcall Enqueue(const float AValue);
	float __fastcall Peek(void);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclSingleEqualityComparer;	/* Jclcontainerintf::IJclSingleEqualityComparer */
	void *__IJclSingleQueue;	/* Jclcontainerintf::IJclSingleQueue */
	
public:
	operator IJclSingleQueue*(void) { return (IJclSingleQueue*)&__IJclSingleQueue; }
	operator IJclSingleEqualityComparer*(void) { return (IJclSingleEqualityComparer*)&__IJclSingleEqualityComparer; }
	operator IJclSingleContainer*(void) { return (IJclSingleContainer*)&__IJclSingleQueue; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclSingleQueue; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleQueue; }
	
};


class DELPHICLASS TJclDoubleQueue;
class PASCALIMPLEMENTATION TJclDoubleQueue : public Jclabstractcontainers::TJclDoubleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclDoubleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<double >  FElements;
	int FHead;
	int FTail;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclDoubleQueue(int ACapacity);
	__fastcall virtual ~TJclDoubleQueue(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(const double AValue);
	double __fastcall Dequeue(void);
	bool __fastcall Empty(void);
	bool __fastcall Enqueue(const double AValue);
	double __fastcall Peek(void);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclDoubleEqualityComparer;	/* Jclcontainerintf::IJclDoubleEqualityComparer */
	void *__IJclDoubleQueue;	/* Jclcontainerintf::IJclDoubleQueue */
	
public:
	operator IJclDoubleQueue*(void) { return (IJclDoubleQueue*)&__IJclDoubleQueue; }
	operator IJclDoubleEqualityComparer*(void) { return (IJclDoubleEqualityComparer*)&__IJclDoubleEqualityComparer; }
	operator IJclDoubleContainer*(void) { return (IJclDoubleContainer*)&__IJclDoubleQueue; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclDoubleQueue; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleQueue; }
	
};


class DELPHICLASS TJclExtendedQueue;
class PASCALIMPLEMENTATION TJclExtendedQueue : public Jclabstractcontainers::TJclExtendedAbstractContainer 
{
	typedef Jclabstractcontainers::TJclExtendedAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<Extended >  FElements;
	int FHead;
	int FTail;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclExtendedQueue(int ACapacity);
	__fastcall virtual ~TJclExtendedQueue(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(const Extended AValue);
	Extended __fastcall Dequeue(void);
	bool __fastcall Empty(void);
	bool __fastcall Enqueue(const Extended AValue);
	Extended __fastcall Peek(void);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclExtendedEqualityComparer;	/* Jclcontainerintf::IJclExtendedEqualityComparer */
	void *__IJclExtendedQueue;	/* Jclcontainerintf::IJclExtendedQueue */
	
public:
	operator IJclExtendedQueue*(void) { return (IJclExtendedQueue*)&__IJclExtendedQueue; }
	operator IJclExtendedEqualityComparer*(void) { return (IJclExtendedEqualityComparer*)&__IJclExtendedEqualityComparer; }
	operator IJclExtendedContainer*(void) { return (IJclExtendedContainer*)&__IJclExtendedQueue; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclExtendedQueue; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedQueue; }
	
};


typedef TJclExtendedQueue TJclFloatQueue;
;

class DELPHICLASS TJclIntegerQueue;
class PASCALIMPLEMENTATION TJclIntegerQueue : public Jclabstractcontainers::TJclIntegerAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntegerAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<int >  FElements;
	int FHead;
	int FTail;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntegerQueue(int ACapacity);
	__fastcall virtual ~TJclIntegerQueue(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(int AValue);
	int __fastcall Dequeue(void);
	bool __fastcall Empty(void);
	bool __fastcall Enqueue(int AValue);
	int __fastcall Peek(void);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntegerEqualityComparer;	/* Jclcontainerintf::IJclIntegerEqualityComparer */
	void *__IJclIntegerQueue;	/* Jclcontainerintf::IJclIntegerQueue */
	
public:
	operator IJclIntegerQueue*(void) { return (IJclIntegerQueue*)&__IJclIntegerQueue; }
	operator IJclIntegerEqualityComparer*(void) { return (IJclIntegerEqualityComparer*)&__IJclIntegerEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntegerQueue; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerQueue; }
	
};


class DELPHICLASS TJclCardinalQueue;
class PASCALIMPLEMENTATION TJclCardinalQueue : public Jclabstractcontainers::TJclCardinalAbstractContainer 
{
	typedef Jclabstractcontainers::TJclCardinalAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<unsigned >  FElements;
	int FHead;
	int FTail;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclCardinalQueue(int ACapacity);
	__fastcall virtual ~TJclCardinalQueue(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(unsigned AValue);
	unsigned __fastcall Dequeue(void);
	bool __fastcall Empty(void);
	bool __fastcall Enqueue(unsigned AValue);
	unsigned __fastcall Peek(void);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclCardinalEqualityComparer;	/* Jclcontainerintf::IJclCardinalEqualityComparer */
	void *__IJclCardinalQueue;	/* Jclcontainerintf::IJclCardinalQueue */
	
public:
	operator IJclCardinalQueue*(void) { return (IJclCardinalQueue*)&__IJclCardinalQueue; }
	operator IJclCardinalEqualityComparer*(void) { return (IJclCardinalEqualityComparer*)&__IJclCardinalEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclCardinalQueue; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalQueue; }
	
};


class DELPHICLASS TJclInt64Queue;
class PASCALIMPLEMENTATION TJclInt64Queue : public Jclabstractcontainers::TJclInt64AbstractContainer 
{
	typedef Jclabstractcontainers::TJclInt64AbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<__int64 >  FElements;
	int FHead;
	int FTail;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclInt64Queue(int ACapacity);
	__fastcall virtual ~TJclInt64Queue(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(const __int64 AValue);
	__int64 __fastcall Dequeue(void);
	bool __fastcall Empty(void);
	bool __fastcall Enqueue(const __int64 AValue);
	__int64 __fastcall Peek(void);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclInt64EqualityComparer;	/* Jclcontainerintf::IJclInt64EqualityComparer */
	void *__IJclInt64Queue;	/* Jclcontainerintf::IJclInt64Queue */
	
public:
	operator IJclInt64Queue*(void) { return (IJclInt64Queue*)&__IJclInt64Queue; }
	operator IJclInt64EqualityComparer*(void) { return (IJclInt64EqualityComparer*)&__IJclInt64EqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclInt64Queue; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64Queue; }
	
};


class DELPHICLASS TJclPtrQueue;
class PASCALIMPLEMENTATION TJclPtrQueue : public Jclabstractcontainers::TJclPtrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclPtrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<void * >  FElements;
	int FHead;
	int FTail;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclPtrQueue(int ACapacity);
	__fastcall virtual ~TJclPtrQueue(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(void * APtr);
	void * __fastcall Dequeue(void);
	bool __fastcall Empty(void);
	bool __fastcall Enqueue(void * APtr);
	void * __fastcall Peek(void);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclPtrEqualityComparer;	/* Jclcontainerintf::IJclPtrEqualityComparer */
	void *__IJclPtrQueue;	/* Jclcontainerintf::IJclPtrQueue */
	
public:
	operator IJclPtrQueue*(void) { return (IJclPtrQueue*)&__IJclPtrQueue; }
	operator IJclPtrEqualityComparer*(void) { return (IJclPtrEqualityComparer*)&__IJclPtrEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclPtrQueue; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrQueue; }
	
};


class DELPHICLASS TJclQueue;
class PASCALIMPLEMENTATION TJclQueue : public Jclabstractcontainers::TJclAbstractContainer 
{
	typedef Jclabstractcontainers::TJclAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<System::TObject* >  FElements;
	int FHead;
	int FTail;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclQueue(int ACapacity, bool AOwnsObjects);
	__fastcall virtual ~TJclQueue(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(System::TObject* AObject);
	System::TObject* __fastcall Dequeue(void);
	bool __fastcall Empty(void);
	bool __fastcall Enqueue(System::TObject* AObject);
	System::TObject* __fastcall Peek(void);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclEqualityComparer;	/* Jclcontainerintf::IJclEqualityComparer */
	void *__IJclObjectOwner;	/* Jclcontainerintf::IJclObjectOwner */
	void *__IJclQueue;	/* Jclcontainerintf::IJclQueue */
	
public:
	operator IJclQueue*(void) { return (IJclQueue*)&__IJclQueue; }
	operator IJclObjectOwner*(void) { return (IJclObjectOwner*)&__IJclObjectOwner; }
	operator IJclEqualityComparer*(void) { return (IJclEqualityComparer*)&__IJclEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclQueue; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclQueue; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jclqueues */
using namespace Jclqueues;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclqueues
