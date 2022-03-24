// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclstacks.pas' rev: 10.00

#ifndef JclstacksHPP
#define JclstacksHPP

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

namespace Jclstacks
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TJclIntfStack;
class PASCALIMPLEMENTATION TJclIntfStack : public Jclabstractcontainers::TJclIntfAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntfAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<System::_di_IInterface >  FElements;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntfStack(int ACapacity);
	__fastcall virtual ~TJclIntfStack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(const System::_di_IInterface AInterface);
	bool __fastcall Empty(void);
	System::_di_IInterface __fastcall Peek();
	System::_di_IInterface __fastcall Pop();
	bool __fastcall Push(const System::_di_IInterface AInterface);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfEqualityComparer;	/* Jclcontainerintf::IJclIntfEqualityComparer */
	void *__IJclIntfStack;	/* Jclcontainerintf::IJclIntfStack */
	
public:
	operator IJclIntfStack*(void) { return (IJclIntfStack*)&__IJclIntfStack; }
	operator IJclIntfEqualityComparer*(void) { return (IJclIntfEqualityComparer*)&__IJclIntfEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfStack; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfStack; }
	
};


class DELPHICLASS TJclAnsiStrStack;
class PASCALIMPLEMENTATION TJclAnsiStrStack : public Jclabstractcontainers::TJclAnsiStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclAnsiStrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<AnsiString >  FElements;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclAnsiStrStack(int ACapacity);
	__fastcall virtual ~TJclAnsiStrStack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(const AnsiString AString);
	bool __fastcall Empty(void);
	AnsiString __fastcall Peek();
	AnsiString __fastcall Pop();
	bool __fastcall Push(const AnsiString AString);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclAnsiStrEqualityComparer;	/* Jclcontainerintf::IJclAnsiStrEqualityComparer */
	void *__IJclAnsiStrStack;	/* Jclcontainerintf::IJclAnsiStrStack */
	
public:
	operator IJclAnsiStrStack*(void) { return (IJclAnsiStrStack*)&__IJclAnsiStrStack; }
	operator IJclAnsiStrEqualityComparer*(void) { return (IJclAnsiStrEqualityComparer*)&__IJclAnsiStrEqualityComparer; }
	operator IJclAnsiStrContainer*(void) { return (IJclAnsiStrContainer*)&__IJclAnsiStrStack; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclAnsiStrStack; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclAnsiStrStack; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrStack; }
	
};


class DELPHICLASS TJclWideStrStack;
class PASCALIMPLEMENTATION TJclWideStrStack : public Jclabstractcontainers::TJclWideStrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclWideStrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<WideString >  FElements;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclWideStrStack(int ACapacity);
	__fastcall virtual ~TJclWideStrStack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(const WideString AString);
	bool __fastcall Empty(void);
	WideString __fastcall Peek();
	WideString __fastcall Pop();
	bool __fastcall Push(const WideString AString);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclWideStrEqualityComparer;	/* Jclcontainerintf::IJclWideStrEqualityComparer */
	void *__IJclWideStrStack;	/* Jclcontainerintf::IJclWideStrStack */
	
public:
	operator IJclWideStrStack*(void) { return (IJclWideStrStack*)&__IJclWideStrStack; }
	operator IJclWideStrEqualityComparer*(void) { return (IJclWideStrEqualityComparer*)&__IJclWideStrEqualityComparer; }
	operator IJclWideStrContainer*(void) { return (IJclWideStrContainer*)&__IJclWideStrStack; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclWideStrStack; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclWideStrStack; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrStack; }
	
};


typedef TJclAnsiStrStack TJclStrStack;
;

class DELPHICLASS TJclSingleStack;
class PASCALIMPLEMENTATION TJclSingleStack : public Jclabstractcontainers::TJclSingleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclSingleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<float >  FElements;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclSingleStack(int ACapacity);
	__fastcall virtual ~TJclSingleStack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(const float AValue);
	bool __fastcall Empty(void);
	float __fastcall Peek(void);
	float __fastcall Pop(void);
	bool __fastcall Push(const float AValue);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclSingleEqualityComparer;	/* Jclcontainerintf::IJclSingleEqualityComparer */
	void *__IJclSingleStack;	/* Jclcontainerintf::IJclSingleStack */
	
public:
	operator IJclSingleStack*(void) { return (IJclSingleStack*)&__IJclSingleStack; }
	operator IJclSingleEqualityComparer*(void) { return (IJclSingleEqualityComparer*)&__IJclSingleEqualityComparer; }
	operator IJclSingleContainer*(void) { return (IJclSingleContainer*)&__IJclSingleStack; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclSingleStack; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleStack; }
	
};


class DELPHICLASS TJclDoubleStack;
class PASCALIMPLEMENTATION TJclDoubleStack : public Jclabstractcontainers::TJclDoubleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclDoubleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<double >  FElements;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclDoubleStack(int ACapacity);
	__fastcall virtual ~TJclDoubleStack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(const double AValue);
	bool __fastcall Empty(void);
	double __fastcall Peek(void);
	double __fastcall Pop(void);
	bool __fastcall Push(const double AValue);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclDoubleEqualityComparer;	/* Jclcontainerintf::IJclDoubleEqualityComparer */
	void *__IJclDoubleStack;	/* Jclcontainerintf::IJclDoubleStack */
	
public:
	operator IJclDoubleStack*(void) { return (IJclDoubleStack*)&__IJclDoubleStack; }
	operator IJclDoubleEqualityComparer*(void) { return (IJclDoubleEqualityComparer*)&__IJclDoubleEqualityComparer; }
	operator IJclDoubleContainer*(void) { return (IJclDoubleContainer*)&__IJclDoubleStack; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclDoubleStack; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleStack; }
	
};


class DELPHICLASS TJclExtendedStack;
class PASCALIMPLEMENTATION TJclExtendedStack : public Jclabstractcontainers::TJclExtendedAbstractContainer 
{
	typedef Jclabstractcontainers::TJclExtendedAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<Extended >  FElements;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclExtendedStack(int ACapacity);
	__fastcall virtual ~TJclExtendedStack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(const Extended AValue);
	bool __fastcall Empty(void);
	Extended __fastcall Peek(void);
	Extended __fastcall Pop(void);
	bool __fastcall Push(const Extended AValue);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclExtendedEqualityComparer;	/* Jclcontainerintf::IJclExtendedEqualityComparer */
	void *__IJclExtendedStack;	/* Jclcontainerintf::IJclExtendedStack */
	
public:
	operator IJclExtendedStack*(void) { return (IJclExtendedStack*)&__IJclExtendedStack; }
	operator IJclExtendedEqualityComparer*(void) { return (IJclExtendedEqualityComparer*)&__IJclExtendedEqualityComparer; }
	operator IJclExtendedContainer*(void) { return (IJclExtendedContainer*)&__IJclExtendedStack; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclExtendedStack; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedStack; }
	
};


typedef TJclExtendedStack TJclFloatStack;
;

class DELPHICLASS TJclIntegerStack;
class PASCALIMPLEMENTATION TJclIntegerStack : public Jclabstractcontainers::TJclIntegerAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntegerAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<int >  FElements;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntegerStack(int ACapacity);
	__fastcall virtual ~TJclIntegerStack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(int AValue);
	bool __fastcall Empty(void);
	int __fastcall Peek(void);
	int __fastcall Pop(void);
	bool __fastcall Push(int AValue);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntegerEqualityComparer;	/* Jclcontainerintf::IJclIntegerEqualityComparer */
	void *__IJclIntegerStack;	/* Jclcontainerintf::IJclIntegerStack */
	
public:
	operator IJclIntegerStack*(void) { return (IJclIntegerStack*)&__IJclIntegerStack; }
	operator IJclIntegerEqualityComparer*(void) { return (IJclIntegerEqualityComparer*)&__IJclIntegerEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntegerStack; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerStack; }
	
};


class DELPHICLASS TJclCardinalStack;
class PASCALIMPLEMENTATION TJclCardinalStack : public Jclabstractcontainers::TJclCardinalAbstractContainer 
{
	typedef Jclabstractcontainers::TJclCardinalAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<unsigned >  FElements;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclCardinalStack(int ACapacity);
	__fastcall virtual ~TJclCardinalStack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(unsigned AValue);
	bool __fastcall Empty(void);
	unsigned __fastcall Peek(void);
	unsigned __fastcall Pop(void);
	bool __fastcall Push(unsigned AValue);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclCardinalEqualityComparer;	/* Jclcontainerintf::IJclCardinalEqualityComparer */
	void *__IJclCardinalStack;	/* Jclcontainerintf::IJclCardinalStack */
	
public:
	operator IJclCardinalStack*(void) { return (IJclCardinalStack*)&__IJclCardinalStack; }
	operator IJclCardinalEqualityComparer*(void) { return (IJclCardinalEqualityComparer*)&__IJclCardinalEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclCardinalStack; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalStack; }
	
};


class DELPHICLASS TJclInt64Stack;
class PASCALIMPLEMENTATION TJclInt64Stack : public Jclabstractcontainers::TJclInt64AbstractContainer 
{
	typedef Jclabstractcontainers::TJclInt64AbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<__int64 >  FElements;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclInt64Stack(int ACapacity);
	__fastcall virtual ~TJclInt64Stack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(const __int64 AValue);
	bool __fastcall Empty(void);
	__int64 __fastcall Peek(void);
	__int64 __fastcall Pop(void);
	bool __fastcall Push(const __int64 AValue);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclInt64EqualityComparer;	/* Jclcontainerintf::IJclInt64EqualityComparer */
	void *__IJclInt64Stack;	/* Jclcontainerintf::IJclInt64Stack */
	
public:
	operator IJclInt64Stack*(void) { return (IJclInt64Stack*)&__IJclInt64Stack; }
	operator IJclInt64EqualityComparer*(void) { return (IJclInt64EqualityComparer*)&__IJclInt64EqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclInt64Stack; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64Stack; }
	
};


class DELPHICLASS TJclPtrStack;
class PASCALIMPLEMENTATION TJclPtrStack : public Jclabstractcontainers::TJclPtrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclPtrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<void * >  FElements;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclPtrStack(int ACapacity);
	__fastcall virtual ~TJclPtrStack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(void * APtr);
	bool __fastcall Empty(void);
	void * __fastcall Peek(void);
	void * __fastcall Pop(void);
	bool __fastcall Push(void * APtr);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclPtrEqualityComparer;	/* Jclcontainerintf::IJclPtrEqualityComparer */
	void *__IJclPtrStack;	/* Jclcontainerintf::IJclPtrStack */
	
public:
	operator IJclPtrStack*(void) { return (IJclPtrStack*)&__IJclPtrStack; }
	operator IJclPtrEqualityComparer*(void) { return (IJclPtrEqualityComparer*)&__IJclPtrEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclPtrStack; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrStack; }
	
};


class DELPHICLASS TJclStack;
class PASCALIMPLEMENTATION TJclStack : public Jclabstractcontainers::TJclAbstractContainer 
{
	typedef Jclabstractcontainers::TJclAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	DynamicArray<System::TObject* >  FElements;
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclStack(int ACapacity, bool AOwnsObjects);
	__fastcall virtual ~TJclStack(void);
	virtual void __fastcall SetCapacity(int Value);
	void __fastcall Clear(void);
	bool __fastcall Contains(System::TObject* AObject);
	bool __fastcall Empty(void);
	System::TObject* __fastcall Peek(void);
	System::TObject* __fastcall Pop(void);
	bool __fastcall Push(System::TObject* AObject);
	int __fastcall Size(void);
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclEqualityComparer;	/* Jclcontainerintf::IJclEqualityComparer */
	void *__IJclObjectOwner;	/* Jclcontainerintf::IJclObjectOwner */
	void *__IJclStack;	/* Jclcontainerintf::IJclStack */
	
public:
	operator IJclStack*(void) { return (IJclStack*)&__IJclStack; }
	operator IJclObjectOwner*(void) { return (IJclObjectOwner*)&__IJclObjectOwner; }
	operator IJclEqualityComparer*(void) { return (IJclEqualityComparer*)&__IJclEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclStack; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclStack; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jclstacks */
using namespace Jclstacks;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclstacks
