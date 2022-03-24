// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcltrees.pas' rev: 10.00

#ifndef JcltreesHPP
#define JcltreesHPP

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

namespace Jcltrees
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TItrStart { isFirst, isLast, isRoot };
#pragma option pop

class DELPHICLASS TJclIntfTreeNode;
class PASCALIMPLEMENTATION TJclIntfTreeNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	System::_di_IInterface Value;
	DynamicArray<System::TObject* >  Children;
	int ChildrenCount;
	TJclIntfTreeNode* Parent;
	int __fastcall IndexOfChild(TJclIntfTreeNode* AChild);
	int __fastcall IndexOfValue(const System::_di_IInterface AInterface, const Jclcontainerintf::_di_IJclIntfEqualityComparer AEqualityComparer);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntfTreeNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntfTreeNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclIntfTree;
class PASCALIMPLEMENTATION TJclIntfTree : public Jclabstractcontainers::TJclIntfAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntfAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclIntfTreeNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	
protected:
	void __fastcall ExtractNode(TJclIntfTreeNode* &ANode);
	void __fastcall RemoveNode(TJclIntfTreeNode* &ANode);
	TJclIntfTreeNode* __fastcall CloneNode(TJclIntfTreeNode* Node, TJclIntfTreeNode* Parent);
	bool __fastcall NodeContains(TJclIntfTreeNode* ANode, const System::_di_IInterface AInterface);
	void __fastcall PackNode(TJclIntfTreeNode* ANode);
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntfTree(void);
	__fastcall virtual ~TJclIntfTree(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
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
	Jclcontainerintf::_di_IJclIntfTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclIntfTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntfEqualityComparer;	/* Jclcontainerintf::IJclIntfEqualityComparer */
	void *__IJclIntfTree;	/* Jclcontainerintf::IJclIntfTree */
	
public:
	operator IJclIntfTree*(void) { return (IJclIntfTree*)&__IJclIntfTree; }
	operator IJclIntfCollection*(void) { return (IJclIntfCollection*)&__IJclIntfTree; }
	operator IJclIntfEqualityComparer*(void) { return (IJclIntfEqualityComparer*)&__IJclIntfEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfTree; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfTree; }
	
};


class DELPHICLASS TJclIntfTreeIterator;
class PASCALIMPLEMENTATION TJclIntfTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclIntfTreeNode* FCursor;
	TItrStart FStart;
	TJclIntfTree* FOwnTree;
	Jclcontainerintf::_di_IJclIntfEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclIntfTreeNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclIntfTreeNode* __fastcall GetNextSibling(void) = 0 ;
	virtual TJclIntfTreeNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclIntfTreeIterator(TJclIntfTree* OwnTree, TJclIntfTreeNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall AddChild(const System::_di_IInterface AInterface);
	int __fastcall ChildrenCount(void);
	void __fastcall DeleteChild(int Index);
	void __fastcall DeleteChildren(void);
	void __fastcall ExtractChild(int Index);
	void __fastcall ExtractChildren(void);
	System::_di_IInterface __fastcall GetChild(int Index);
	bool __fastcall HasChild(int Index);
	bool __fastcall HasParent(void);
	int __fastcall IndexOfChild(const System::_di_IInterface AInterface);
	bool __fastcall InsertChild(int Index, const System::_di_IInterface AInterface);
	System::_di_IInterface __fastcall Parent();
	void __fastcall SetChild(int Index, const System::_di_IInterface AInterface);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclIntfTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfTreeIterator;	/* Jclcontainerintf::IJclIntfTreeIterator */
	
public:
	operator IJclIntfTreeIterator*(void) { return (IJclIntfTreeIterator*)&__IJclIntfTreeIterator; }
	operator IJclIntfIterator*(void) { return (IJclIntfIterator*)&__IJclIntfTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderIntfTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderIntfTreeIterator : public TJclIntfTreeIterator 
{
	typedef TJclIntfTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclIntfTreeNode* __fastcall GetNextCursor(void);
	virtual TJclIntfTreeNode* __fastcall GetNextSibling(void);
	virtual TJclIntfTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclIntfTreeIterator.Create */ inline __fastcall TJclPreOrderIntfTreeIterator(TJclIntfTree* OwnTree, TJclIntfTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclIntfTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderIntfTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfTreeIterator;	/* Jclcontainerintf::IJclIntfTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfTreeIterator; }
	operator IJclIntfTreeIterator*(void) { return (IJclIntfTreeIterator*)&__IJclIntfTreeIterator; }
	operator IJclIntfIterator*(void) { return (IJclIntfIterator*)&__IJclIntfTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderIntfTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderIntfTreeIterator : public TJclIntfTreeIterator 
{
	typedef TJclIntfTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclIntfTreeNode* __fastcall GetNextCursor(void);
	virtual TJclIntfTreeNode* __fastcall GetNextSibling(void);
	virtual TJclIntfTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclIntfTreeIterator.Create */ inline __fastcall TJclPostOrderIntfTreeIterator(TJclIntfTree* OwnTree, TJclIntfTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclIntfTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderIntfTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfTreeIterator;	/* Jclcontainerintf::IJclIntfTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfTreeIterator; }
	operator IJclIntfTreeIterator*(void) { return (IJclIntfTreeIterator*)&__IJclIntfTreeIterator; }
	operator IJclIntfIterator*(void) { return (IJclIntfIterator*)&__IJclIntfTreeIterator; }
	
};


class DELPHICLASS TJclAnsiStrTreeNode;
class PASCALIMPLEMENTATION TJclAnsiStrTreeNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	AnsiString Value;
	DynamicArray<System::TObject* >  Children;
	int ChildrenCount;
	TJclAnsiStrTreeNode* Parent;
	int __fastcall IndexOfChild(TJclAnsiStrTreeNode* AChild);
	int __fastcall IndexOfValue(const AnsiString AString, const Jclcontainerintf::_di_IJclAnsiStrEqualityComparer AEqualityComparer);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclAnsiStrTreeNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclAnsiStrTreeNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclAnsiStrTree;
class PASCALIMPLEMENTATION TJclAnsiStrTree : public Jclabstractcontainers::TJclAnsiStrAbstractCollection 
{
	typedef Jclabstractcontainers::TJclAnsiStrAbstractCollection inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclAnsiStrTreeNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	
protected:
	void __fastcall ExtractNode(TJclAnsiStrTreeNode* &ANode);
	void __fastcall RemoveNode(TJclAnsiStrTreeNode* &ANode);
	TJclAnsiStrTreeNode* __fastcall CloneNode(TJclAnsiStrTreeNode* Node, TJclAnsiStrTreeNode* Parent);
	bool __fastcall NodeContains(TJclAnsiStrTreeNode* ANode, const AnsiString AString);
	void __fastcall PackNode(TJclAnsiStrTreeNode* ANode);
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclAnsiStrTree(void);
	__fastcall virtual ~TJclAnsiStrTree(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
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
	Jclcontainerintf::_di_IJclAnsiStrTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclAnsiStrTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclAnsiStrEqualityComparer;	/* Jclcontainerintf::IJclAnsiStrEqualityComparer */
	void *__IJclAnsiStrTree;	/* Jclcontainerintf::IJclAnsiStrTree */
	
public:
	operator IJclAnsiStrTree*(void) { return (IJclAnsiStrTree*)&__IJclAnsiStrTree; }
	operator IJclAnsiStrCollection*(void) { return (IJclAnsiStrCollection*)&__IJclAnsiStrTree; }
	operator IJclAnsiStrContainer*(void) { return (IJclAnsiStrContainer*)&__IJclAnsiStrTree; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclAnsiStrTree; }
	operator IJclAnsiStrEqualityComparer*(void) { return (IJclAnsiStrEqualityComparer*)&__IJclAnsiStrEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclAnsiStrTree; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrTree; }
	
};


class DELPHICLASS TJclAnsiStrTreeIterator;
class PASCALIMPLEMENTATION TJclAnsiStrTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclAnsiStrTreeNode* FCursor;
	TItrStart FStart;
	TJclAnsiStrTree* FOwnTree;
	Jclcontainerintf::_di_IJclAnsiStrEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclAnsiStrTreeNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclAnsiStrTreeNode* __fastcall GetNextSibling(void) = 0 ;
	virtual TJclAnsiStrTreeNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclAnsiStrTreeIterator(TJclAnsiStrTree* OwnTree, TJclAnsiStrTreeNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall AddChild(const AnsiString AString);
	int __fastcall ChildrenCount(void);
	void __fastcall DeleteChild(int Index);
	void __fastcall DeleteChildren(void);
	void __fastcall ExtractChild(int Index);
	void __fastcall ExtractChildren(void);
	AnsiString __fastcall GetChild(int Index);
	bool __fastcall HasChild(int Index);
	bool __fastcall HasParent(void);
	int __fastcall IndexOfChild(const AnsiString AString);
	bool __fastcall InsertChild(int Index, const AnsiString AString);
	AnsiString __fastcall Parent();
	void __fastcall SetChild(int Index, const AnsiString AString);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclAnsiStrTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclAnsiStrTreeIterator;	/* Jclcontainerintf::IJclAnsiStrTreeIterator */
	
public:
	operator IJclAnsiStrTreeIterator*(void) { return (IJclAnsiStrTreeIterator*)&__IJclAnsiStrTreeIterator; }
	operator IJclAnsiStrIterator*(void) { return (IJclAnsiStrIterator*)&__IJclAnsiStrTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderAnsiStrTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderAnsiStrTreeIterator : public TJclAnsiStrTreeIterator 
{
	typedef TJclAnsiStrTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclAnsiStrTreeNode* __fastcall GetNextCursor(void);
	virtual TJclAnsiStrTreeNode* __fastcall GetNextSibling(void);
	virtual TJclAnsiStrTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclAnsiStrTreeIterator.Create */ inline __fastcall TJclPreOrderAnsiStrTreeIterator(TJclAnsiStrTree* OwnTree, TJclAnsiStrTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclAnsiStrTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderAnsiStrTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclAnsiStrTreeIterator;	/* Jclcontainerintf::IJclAnsiStrTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrTreeIterator; }
	operator IJclAnsiStrTreeIterator*(void) { return (IJclAnsiStrTreeIterator*)&__IJclAnsiStrTreeIterator; }
	operator IJclAnsiStrIterator*(void) { return (IJclAnsiStrIterator*)&__IJclAnsiStrTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderAnsiStrTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderAnsiStrTreeIterator : public TJclAnsiStrTreeIterator 
{
	typedef TJclAnsiStrTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclAnsiStrTreeNode* __fastcall GetNextCursor(void);
	virtual TJclAnsiStrTreeNode* __fastcall GetNextSibling(void);
	virtual TJclAnsiStrTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclAnsiStrTreeIterator.Create */ inline __fastcall TJclPostOrderAnsiStrTreeIterator(TJclAnsiStrTree* OwnTree, TJclAnsiStrTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclAnsiStrTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderAnsiStrTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclAnsiStrTreeIterator;	/* Jclcontainerintf::IJclAnsiStrTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrTreeIterator; }
	operator IJclAnsiStrTreeIterator*(void) { return (IJclAnsiStrTreeIterator*)&__IJclAnsiStrTreeIterator; }
	operator IJclAnsiStrIterator*(void) { return (IJclAnsiStrIterator*)&__IJclAnsiStrTreeIterator; }
	
};


class DELPHICLASS TJclWideStrTreeNode;
class PASCALIMPLEMENTATION TJclWideStrTreeNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	WideString Value;
	DynamicArray<System::TObject* >  Children;
	int ChildrenCount;
	TJclWideStrTreeNode* Parent;
	int __fastcall IndexOfChild(TJclWideStrTreeNode* AChild);
	int __fastcall IndexOfValue(const WideString AString, const Jclcontainerintf::_di_IJclWideStrEqualityComparer AEqualityComparer);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclWideStrTreeNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclWideStrTreeNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclWideStrTree;
class PASCALIMPLEMENTATION TJclWideStrTree : public Jclabstractcontainers::TJclWideStrAbstractCollection 
{
	typedef Jclabstractcontainers::TJclWideStrAbstractCollection inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclWideStrTreeNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	
protected:
	void __fastcall ExtractNode(TJclWideStrTreeNode* &ANode);
	void __fastcall RemoveNode(TJclWideStrTreeNode* &ANode);
	TJclWideStrTreeNode* __fastcall CloneNode(TJclWideStrTreeNode* Node, TJclWideStrTreeNode* Parent);
	bool __fastcall NodeContains(TJclWideStrTreeNode* ANode, const WideString AString);
	void __fastcall PackNode(TJclWideStrTreeNode* ANode);
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclWideStrTree(void);
	__fastcall virtual ~TJclWideStrTree(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
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
	Jclcontainerintf::_di_IJclWideStrTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclWideStrTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclWideStrEqualityComparer;	/* Jclcontainerintf::IJclWideStrEqualityComparer */
	void *__IJclWideStrTree;	/* Jclcontainerintf::IJclWideStrTree */
	
public:
	operator IJclWideStrTree*(void) { return (IJclWideStrTree*)&__IJclWideStrTree; }
	operator IJclWideStrCollection*(void) { return (IJclWideStrCollection*)&__IJclWideStrTree; }
	operator IJclWideStrContainer*(void) { return (IJclWideStrContainer*)&__IJclWideStrTree; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclWideStrTree; }
	operator IJclWideStrEqualityComparer*(void) { return (IJclWideStrEqualityComparer*)&__IJclWideStrEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclWideStrTree; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrTree; }
	
};


class DELPHICLASS TJclWideStrTreeIterator;
class PASCALIMPLEMENTATION TJclWideStrTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclWideStrTreeNode* FCursor;
	TItrStart FStart;
	TJclWideStrTree* FOwnTree;
	Jclcontainerintf::_di_IJclWideStrEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclWideStrTreeNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclWideStrTreeNode* __fastcall GetNextSibling(void) = 0 ;
	virtual TJclWideStrTreeNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclWideStrTreeIterator(TJclWideStrTree* OwnTree, TJclWideStrTreeNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall AddChild(const WideString AString);
	int __fastcall ChildrenCount(void);
	void __fastcall DeleteChild(int Index);
	void __fastcall DeleteChildren(void);
	void __fastcall ExtractChild(int Index);
	void __fastcall ExtractChildren(void);
	WideString __fastcall GetChild(int Index);
	bool __fastcall HasChild(int Index);
	bool __fastcall HasParent(void);
	int __fastcall IndexOfChild(const WideString AString);
	bool __fastcall InsertChild(int Index, const WideString AString);
	WideString __fastcall Parent();
	void __fastcall SetChild(int Index, const WideString AString);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclWideStrTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclWideStrTreeIterator;	/* Jclcontainerintf::IJclWideStrTreeIterator */
	
public:
	operator IJclWideStrTreeIterator*(void) { return (IJclWideStrTreeIterator*)&__IJclWideStrTreeIterator; }
	operator IJclWideStrIterator*(void) { return (IJclWideStrIterator*)&__IJclWideStrTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderWideStrTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderWideStrTreeIterator : public TJclWideStrTreeIterator 
{
	typedef TJclWideStrTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclWideStrTreeNode* __fastcall GetNextCursor(void);
	virtual TJclWideStrTreeNode* __fastcall GetNextSibling(void);
	virtual TJclWideStrTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclWideStrTreeIterator.Create */ inline __fastcall TJclPreOrderWideStrTreeIterator(TJclWideStrTree* OwnTree, TJclWideStrTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclWideStrTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderWideStrTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclWideStrTreeIterator;	/* Jclcontainerintf::IJclWideStrTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrTreeIterator; }
	operator IJclWideStrTreeIterator*(void) { return (IJclWideStrTreeIterator*)&__IJclWideStrTreeIterator; }
	operator IJclWideStrIterator*(void) { return (IJclWideStrIterator*)&__IJclWideStrTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderWideStrTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderWideStrTreeIterator : public TJclWideStrTreeIterator 
{
	typedef TJclWideStrTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclWideStrTreeNode* __fastcall GetNextCursor(void);
	virtual TJclWideStrTreeNode* __fastcall GetNextSibling(void);
	virtual TJclWideStrTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclWideStrTreeIterator.Create */ inline __fastcall TJclPostOrderWideStrTreeIterator(TJclWideStrTree* OwnTree, TJclWideStrTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclWideStrTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderWideStrTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclWideStrTreeIterator;	/* Jclcontainerintf::IJclWideStrTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrTreeIterator; }
	operator IJclWideStrTreeIterator*(void) { return (IJclWideStrTreeIterator*)&__IJclWideStrTreeIterator; }
	operator IJclWideStrIterator*(void) { return (IJclWideStrIterator*)&__IJclWideStrTreeIterator; }
	
};


typedef TJclAnsiStrTree TJclStrTree;
;

class DELPHICLASS TJclSingleTreeNode;
class PASCALIMPLEMENTATION TJclSingleTreeNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	float Value;
	DynamicArray<System::TObject* >  Children;
	int ChildrenCount;
	TJclSingleTreeNode* Parent;
	int __fastcall IndexOfChild(TJclSingleTreeNode* AChild);
	int __fastcall IndexOfValue(const float AValue, const Jclcontainerintf::_di_IJclSingleEqualityComparer AEqualityComparer);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclSingleTreeNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclSingleTreeNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclSingleTree;
class PASCALIMPLEMENTATION TJclSingleTree : public Jclabstractcontainers::TJclSingleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclSingleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclSingleTreeNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	
protected:
	void __fastcall ExtractNode(TJclSingleTreeNode* &ANode);
	void __fastcall RemoveNode(TJclSingleTreeNode* &ANode);
	TJclSingleTreeNode* __fastcall CloneNode(TJclSingleTreeNode* Node, TJclSingleTreeNode* Parent);
	bool __fastcall NodeContains(TJclSingleTreeNode* ANode, const float AValue);
	void __fastcall PackNode(TJclSingleTreeNode* ANode);
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclSingleTree(void);
	__fastcall virtual ~TJclSingleTree(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
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
	Jclcontainerintf::_di_IJclSingleTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclSingleTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclSingleEqualityComparer;	/* Jclcontainerintf::IJclSingleEqualityComparer */
	void *__IJclSingleTree;	/* Jclcontainerintf::IJclSingleTree */
	
public:
	operator IJclSingleTree*(void) { return (IJclSingleTree*)&__IJclSingleTree; }
	operator IJclSingleCollection*(void) { return (IJclSingleCollection*)&__IJclSingleTree; }
	operator IJclSingleContainer*(void) { return (IJclSingleContainer*)&__IJclSingleTree; }
	operator IJclSingleEqualityComparer*(void) { return (IJclSingleEqualityComparer*)&__IJclSingleEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclSingleTree; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleTree; }
	
};


class DELPHICLASS TJclSingleTreeIterator;
class PASCALIMPLEMENTATION TJclSingleTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclSingleTreeNode* FCursor;
	TItrStart FStart;
	TJclSingleTree* FOwnTree;
	Jclcontainerintf::_di_IJclSingleEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclSingleTreeNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclSingleTreeNode* __fastcall GetNextSibling(void) = 0 ;
	virtual TJclSingleTreeNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclSingleTreeIterator(TJclSingleTree* OwnTree, TJclSingleTreeNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall AddChild(const float AValue);
	int __fastcall ChildrenCount(void);
	void __fastcall DeleteChild(int Index);
	void __fastcall DeleteChildren(void);
	void __fastcall ExtractChild(int Index);
	void __fastcall ExtractChildren(void);
	float __fastcall GetChild(int Index);
	bool __fastcall HasChild(int Index);
	bool __fastcall HasParent(void);
	int __fastcall IndexOfChild(const float AValue);
	bool __fastcall InsertChild(int Index, const float AValue);
	float __fastcall Parent(void);
	void __fastcall SetChild(int Index, const float AValue);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclSingleTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclSingleTreeIterator;	/* Jclcontainerintf::IJclSingleTreeIterator */
	
public:
	operator IJclSingleTreeIterator*(void) { return (IJclSingleTreeIterator*)&__IJclSingleTreeIterator; }
	operator IJclSingleIterator*(void) { return (IJclSingleIterator*)&__IJclSingleTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderSingleTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderSingleTreeIterator : public TJclSingleTreeIterator 
{
	typedef TJclSingleTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclSingleTreeNode* __fastcall GetNextCursor(void);
	virtual TJclSingleTreeNode* __fastcall GetNextSibling(void);
	virtual TJclSingleTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclSingleTreeIterator.Create */ inline __fastcall TJclPreOrderSingleTreeIterator(TJclSingleTree* OwnTree, TJclSingleTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclSingleTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderSingleTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclSingleTreeIterator;	/* Jclcontainerintf::IJclSingleTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleTreeIterator; }
	operator IJclSingleTreeIterator*(void) { return (IJclSingleTreeIterator*)&__IJclSingleTreeIterator; }
	operator IJclSingleIterator*(void) { return (IJclSingleIterator*)&__IJclSingleTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderSingleTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderSingleTreeIterator : public TJclSingleTreeIterator 
{
	typedef TJclSingleTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclSingleTreeNode* __fastcall GetNextCursor(void);
	virtual TJclSingleTreeNode* __fastcall GetNextSibling(void);
	virtual TJclSingleTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclSingleTreeIterator.Create */ inline __fastcall TJclPostOrderSingleTreeIterator(TJclSingleTree* OwnTree, TJclSingleTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclSingleTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderSingleTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclSingleTreeIterator;	/* Jclcontainerintf::IJclSingleTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleTreeIterator; }
	operator IJclSingleTreeIterator*(void) { return (IJclSingleTreeIterator*)&__IJclSingleTreeIterator; }
	operator IJclSingleIterator*(void) { return (IJclSingleIterator*)&__IJclSingleTreeIterator; }
	
};


class DELPHICLASS TJclDoubleTreeNode;
class PASCALIMPLEMENTATION TJclDoubleTreeNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	double Value;
	DynamicArray<System::TObject* >  Children;
	int ChildrenCount;
	TJclDoubleTreeNode* Parent;
	int __fastcall IndexOfChild(TJclDoubleTreeNode* AChild);
	int __fastcall IndexOfValue(const double AValue, const Jclcontainerintf::_di_IJclDoubleEqualityComparer AEqualityComparer);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclDoubleTreeNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclDoubleTreeNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclDoubleTree;
class PASCALIMPLEMENTATION TJclDoubleTree : public Jclabstractcontainers::TJclDoubleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclDoubleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclDoubleTreeNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	
protected:
	void __fastcall ExtractNode(TJclDoubleTreeNode* &ANode);
	void __fastcall RemoveNode(TJclDoubleTreeNode* &ANode);
	TJclDoubleTreeNode* __fastcall CloneNode(TJclDoubleTreeNode* Node, TJclDoubleTreeNode* Parent);
	bool __fastcall NodeContains(TJclDoubleTreeNode* ANode, const double AValue);
	void __fastcall PackNode(TJclDoubleTreeNode* ANode);
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclDoubleTree(void);
	__fastcall virtual ~TJclDoubleTree(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
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
	Jclcontainerintf::_di_IJclDoubleTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclDoubleTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclDoubleEqualityComparer;	/* Jclcontainerintf::IJclDoubleEqualityComparer */
	void *__IJclDoubleTree;	/* Jclcontainerintf::IJclDoubleTree */
	
public:
	operator IJclDoubleTree*(void) { return (IJclDoubleTree*)&__IJclDoubleTree; }
	operator IJclDoubleCollection*(void) { return (IJclDoubleCollection*)&__IJclDoubleTree; }
	operator IJclDoubleContainer*(void) { return (IJclDoubleContainer*)&__IJclDoubleTree; }
	operator IJclDoubleEqualityComparer*(void) { return (IJclDoubleEqualityComparer*)&__IJclDoubleEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclDoubleTree; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleTree; }
	
};


class DELPHICLASS TJclDoubleTreeIterator;
class PASCALIMPLEMENTATION TJclDoubleTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclDoubleTreeNode* FCursor;
	TItrStart FStart;
	TJclDoubleTree* FOwnTree;
	Jclcontainerintf::_di_IJclDoubleEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclDoubleTreeNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclDoubleTreeNode* __fastcall GetNextSibling(void) = 0 ;
	virtual TJclDoubleTreeNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclDoubleTreeIterator(TJclDoubleTree* OwnTree, TJclDoubleTreeNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall AddChild(const double AValue);
	int __fastcall ChildrenCount(void);
	void __fastcall DeleteChild(int Index);
	void __fastcall DeleteChildren(void);
	void __fastcall ExtractChild(int Index);
	void __fastcall ExtractChildren(void);
	double __fastcall GetChild(int Index);
	bool __fastcall HasChild(int Index);
	bool __fastcall HasParent(void);
	int __fastcall IndexOfChild(const double AValue);
	bool __fastcall InsertChild(int Index, const double AValue);
	double __fastcall Parent(void);
	void __fastcall SetChild(int Index, const double AValue);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclDoubleTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclDoubleTreeIterator;	/* Jclcontainerintf::IJclDoubleTreeIterator */
	
public:
	operator IJclDoubleTreeIterator*(void) { return (IJclDoubleTreeIterator*)&__IJclDoubleTreeIterator; }
	operator IJclDoubleIterator*(void) { return (IJclDoubleIterator*)&__IJclDoubleTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderDoubleTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderDoubleTreeIterator : public TJclDoubleTreeIterator 
{
	typedef TJclDoubleTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclDoubleTreeNode* __fastcall GetNextCursor(void);
	virtual TJclDoubleTreeNode* __fastcall GetNextSibling(void);
	virtual TJclDoubleTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclDoubleTreeIterator.Create */ inline __fastcall TJclPreOrderDoubleTreeIterator(TJclDoubleTree* OwnTree, TJclDoubleTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclDoubleTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderDoubleTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclDoubleTreeIterator;	/* Jclcontainerintf::IJclDoubleTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleTreeIterator; }
	operator IJclDoubleTreeIterator*(void) { return (IJclDoubleTreeIterator*)&__IJclDoubleTreeIterator; }
	operator IJclDoubleIterator*(void) { return (IJclDoubleIterator*)&__IJclDoubleTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderDoubleTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderDoubleTreeIterator : public TJclDoubleTreeIterator 
{
	typedef TJclDoubleTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclDoubleTreeNode* __fastcall GetNextCursor(void);
	virtual TJclDoubleTreeNode* __fastcall GetNextSibling(void);
	virtual TJclDoubleTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclDoubleTreeIterator.Create */ inline __fastcall TJclPostOrderDoubleTreeIterator(TJclDoubleTree* OwnTree, TJclDoubleTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclDoubleTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderDoubleTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclDoubleTreeIterator;	/* Jclcontainerintf::IJclDoubleTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleTreeIterator; }
	operator IJclDoubleTreeIterator*(void) { return (IJclDoubleTreeIterator*)&__IJclDoubleTreeIterator; }
	operator IJclDoubleIterator*(void) { return (IJclDoubleIterator*)&__IJclDoubleTreeIterator; }
	
};


class DELPHICLASS TJclExtendedTreeNode;
class PASCALIMPLEMENTATION TJclExtendedTreeNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	Extended Value;
	DynamicArray<System::TObject* >  Children;
	int ChildrenCount;
	TJclExtendedTreeNode* Parent;
	int __fastcall IndexOfChild(TJclExtendedTreeNode* AChild);
	int __fastcall IndexOfValue(const Extended AValue, const Jclcontainerintf::_di_IJclExtendedEqualityComparer AEqualityComparer);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclExtendedTreeNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclExtendedTreeNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclExtendedTree;
class PASCALIMPLEMENTATION TJclExtendedTree : public Jclabstractcontainers::TJclExtendedAbstractContainer 
{
	typedef Jclabstractcontainers::TJclExtendedAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclExtendedTreeNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	
protected:
	void __fastcall ExtractNode(TJclExtendedTreeNode* &ANode);
	void __fastcall RemoveNode(TJclExtendedTreeNode* &ANode);
	TJclExtendedTreeNode* __fastcall CloneNode(TJclExtendedTreeNode* Node, TJclExtendedTreeNode* Parent);
	bool __fastcall NodeContains(TJclExtendedTreeNode* ANode, const Extended AValue);
	void __fastcall PackNode(TJclExtendedTreeNode* ANode);
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclExtendedTree(void);
	__fastcall virtual ~TJclExtendedTree(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
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
	Jclcontainerintf::_di_IJclExtendedTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclExtendedTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclExtendedEqualityComparer;	/* Jclcontainerintf::IJclExtendedEqualityComparer */
	void *__IJclExtendedTree;	/* Jclcontainerintf::IJclExtendedTree */
	
public:
	operator IJclExtendedTree*(void) { return (IJclExtendedTree*)&__IJclExtendedTree; }
	operator IJclExtendedCollection*(void) { return (IJclExtendedCollection*)&__IJclExtendedTree; }
	operator IJclExtendedContainer*(void) { return (IJclExtendedContainer*)&__IJclExtendedTree; }
	operator IJclExtendedEqualityComparer*(void) { return (IJclExtendedEqualityComparer*)&__IJclExtendedEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclExtendedTree; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedTree; }
	
};


class DELPHICLASS TJclExtendedTreeIterator;
class PASCALIMPLEMENTATION TJclExtendedTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclExtendedTreeNode* FCursor;
	TItrStart FStart;
	TJclExtendedTree* FOwnTree;
	Jclcontainerintf::_di_IJclExtendedEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclExtendedTreeNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclExtendedTreeNode* __fastcall GetNextSibling(void) = 0 ;
	virtual TJclExtendedTreeNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclExtendedTreeIterator(TJclExtendedTree* OwnTree, TJclExtendedTreeNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall AddChild(const Extended AValue);
	int __fastcall ChildrenCount(void);
	void __fastcall DeleteChild(int Index);
	void __fastcall DeleteChildren(void);
	void __fastcall ExtractChild(int Index);
	void __fastcall ExtractChildren(void);
	Extended __fastcall GetChild(int Index);
	bool __fastcall HasChild(int Index);
	bool __fastcall HasParent(void);
	int __fastcall IndexOfChild(const Extended AValue);
	bool __fastcall InsertChild(int Index, const Extended AValue);
	Extended __fastcall Parent(void);
	void __fastcall SetChild(int Index, const Extended AValue);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclExtendedTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclExtendedTreeIterator;	/* Jclcontainerintf::IJclExtendedTreeIterator */
	
public:
	operator IJclExtendedTreeIterator*(void) { return (IJclExtendedTreeIterator*)&__IJclExtendedTreeIterator; }
	operator IJclExtendedIterator*(void) { return (IJclExtendedIterator*)&__IJclExtendedTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderExtendedTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderExtendedTreeIterator : public TJclExtendedTreeIterator 
{
	typedef TJclExtendedTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclExtendedTreeNode* __fastcall GetNextCursor(void);
	virtual TJclExtendedTreeNode* __fastcall GetNextSibling(void);
	virtual TJclExtendedTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclExtendedTreeIterator.Create */ inline __fastcall TJclPreOrderExtendedTreeIterator(TJclExtendedTree* OwnTree, TJclExtendedTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclExtendedTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderExtendedTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclExtendedTreeIterator;	/* Jclcontainerintf::IJclExtendedTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedTreeIterator; }
	operator IJclExtendedTreeIterator*(void) { return (IJclExtendedTreeIterator*)&__IJclExtendedTreeIterator; }
	operator IJclExtendedIterator*(void) { return (IJclExtendedIterator*)&__IJclExtendedTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderExtendedTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderExtendedTreeIterator : public TJclExtendedTreeIterator 
{
	typedef TJclExtendedTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclExtendedTreeNode* __fastcall GetNextCursor(void);
	virtual TJclExtendedTreeNode* __fastcall GetNextSibling(void);
	virtual TJclExtendedTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclExtendedTreeIterator.Create */ inline __fastcall TJclPostOrderExtendedTreeIterator(TJclExtendedTree* OwnTree, TJclExtendedTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclExtendedTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderExtendedTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclExtendedTreeIterator;	/* Jclcontainerintf::IJclExtendedTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedTreeIterator; }
	operator IJclExtendedTreeIterator*(void) { return (IJclExtendedTreeIterator*)&__IJclExtendedTreeIterator; }
	operator IJclExtendedIterator*(void) { return (IJclExtendedIterator*)&__IJclExtendedTreeIterator; }
	
};


typedef TJclExtendedTree TJclFloatTree;
;

class DELPHICLASS TJclIntegerTreeNode;
class PASCALIMPLEMENTATION TJclIntegerTreeNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Value;
	DynamicArray<System::TObject* >  Children;
	int ChildrenCount;
	TJclIntegerTreeNode* Parent;
	int __fastcall IndexOfChild(TJclIntegerTreeNode* AChild);
	int __fastcall IndexOfValue(int AValue, const Jclcontainerintf::_di_IJclIntegerEqualityComparer AEqualityComparer);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntegerTreeNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntegerTreeNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclIntegerTree;
class PASCALIMPLEMENTATION TJclIntegerTree : public Jclabstractcontainers::TJclIntegerAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntegerAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclIntegerTreeNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	
protected:
	void __fastcall ExtractNode(TJclIntegerTreeNode* &ANode);
	void __fastcall RemoveNode(TJclIntegerTreeNode* &ANode);
	TJclIntegerTreeNode* __fastcall CloneNode(TJclIntegerTreeNode* Node, TJclIntegerTreeNode* Parent);
	bool __fastcall NodeContains(TJclIntegerTreeNode* ANode, int AValue);
	void __fastcall PackNode(TJclIntegerTreeNode* ANode);
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclIntegerTree(void);
	__fastcall virtual ~TJclIntegerTree(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
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
	Jclcontainerintf::_di_IJclIntegerTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclIntegerTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclIntegerEqualityComparer;	/* Jclcontainerintf::IJclIntegerEqualityComparer */
	void *__IJclIntegerTree;	/* Jclcontainerintf::IJclIntegerTree */
	
public:
	operator IJclIntegerTree*(void) { return (IJclIntegerTree*)&__IJclIntegerTree; }
	operator IJclIntegerCollection*(void) { return (IJclIntegerCollection*)&__IJclIntegerTree; }
	operator IJclIntegerEqualityComparer*(void) { return (IJclIntegerEqualityComparer*)&__IJclIntegerEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntegerTree; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerTree; }
	
};


class DELPHICLASS TJclIntegerTreeIterator;
class PASCALIMPLEMENTATION TJclIntegerTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclIntegerTreeNode* FCursor;
	TItrStart FStart;
	TJclIntegerTree* FOwnTree;
	Jclcontainerintf::_di_IJclIntegerEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclIntegerTreeNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclIntegerTreeNode* __fastcall GetNextSibling(void) = 0 ;
	virtual TJclIntegerTreeNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclIntegerTreeIterator(TJclIntegerTree* OwnTree, TJclIntegerTreeNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall AddChild(int AValue);
	int __fastcall ChildrenCount(void);
	void __fastcall DeleteChild(int Index);
	void __fastcall DeleteChildren(void);
	void __fastcall ExtractChild(int Index);
	void __fastcall ExtractChildren(void);
	int __fastcall GetChild(int Index);
	bool __fastcall HasChild(int Index);
	bool __fastcall HasParent(void);
	int __fastcall IndexOfChild(int AValue);
	bool __fastcall InsertChild(int Index, int AValue);
	int __fastcall Parent(void);
	void __fastcall SetChild(int Index, int AValue);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclIntegerTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclIntegerTreeIterator;	/* Jclcontainerintf::IJclIntegerTreeIterator */
	
public:
	operator IJclIntegerTreeIterator*(void) { return (IJclIntegerTreeIterator*)&__IJclIntegerTreeIterator; }
	operator IJclIntegerIterator*(void) { return (IJclIntegerIterator*)&__IJclIntegerTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderIntegerTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderIntegerTreeIterator : public TJclIntegerTreeIterator 
{
	typedef TJclIntegerTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclIntegerTreeNode* __fastcall GetNextCursor(void);
	virtual TJclIntegerTreeNode* __fastcall GetNextSibling(void);
	virtual TJclIntegerTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclIntegerTreeIterator.Create */ inline __fastcall TJclPreOrderIntegerTreeIterator(TJclIntegerTree* OwnTree, TJclIntegerTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclIntegerTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderIntegerTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclIntegerTreeIterator;	/* Jclcontainerintf::IJclIntegerTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerTreeIterator; }
	operator IJclIntegerTreeIterator*(void) { return (IJclIntegerTreeIterator*)&__IJclIntegerTreeIterator; }
	operator IJclIntegerIterator*(void) { return (IJclIntegerIterator*)&__IJclIntegerTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderIntegerTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderIntegerTreeIterator : public TJclIntegerTreeIterator 
{
	typedef TJclIntegerTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclIntegerTreeNode* __fastcall GetNextCursor(void);
	virtual TJclIntegerTreeNode* __fastcall GetNextSibling(void);
	virtual TJclIntegerTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclIntegerTreeIterator.Create */ inline __fastcall TJclPostOrderIntegerTreeIterator(TJclIntegerTree* OwnTree, TJclIntegerTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclIntegerTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderIntegerTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclIntegerTreeIterator;	/* Jclcontainerintf::IJclIntegerTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerTreeIterator; }
	operator IJclIntegerTreeIterator*(void) { return (IJclIntegerTreeIterator*)&__IJclIntegerTreeIterator; }
	operator IJclIntegerIterator*(void) { return (IJclIntegerIterator*)&__IJclIntegerTreeIterator; }
	
};


class DELPHICLASS TJclCardinalTreeNode;
class PASCALIMPLEMENTATION TJclCardinalTreeNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	unsigned Value;
	DynamicArray<System::TObject* >  Children;
	int ChildrenCount;
	TJclCardinalTreeNode* Parent;
	int __fastcall IndexOfChild(TJclCardinalTreeNode* AChild);
	int __fastcall IndexOfValue(unsigned AValue, const Jclcontainerintf::_di_IJclCardinalEqualityComparer AEqualityComparer);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclCardinalTreeNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclCardinalTreeNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclCardinalTree;
class PASCALIMPLEMENTATION TJclCardinalTree : public Jclabstractcontainers::TJclCardinalAbstractContainer 
{
	typedef Jclabstractcontainers::TJclCardinalAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclCardinalTreeNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	
protected:
	void __fastcall ExtractNode(TJclCardinalTreeNode* &ANode);
	void __fastcall RemoveNode(TJclCardinalTreeNode* &ANode);
	TJclCardinalTreeNode* __fastcall CloneNode(TJclCardinalTreeNode* Node, TJclCardinalTreeNode* Parent);
	bool __fastcall NodeContains(TJclCardinalTreeNode* ANode, unsigned AValue);
	void __fastcall PackNode(TJclCardinalTreeNode* ANode);
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclCardinalTree(void);
	__fastcall virtual ~TJclCardinalTree(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
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
	Jclcontainerintf::_di_IJclCardinalTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclCardinalTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclCardinalEqualityComparer;	/* Jclcontainerintf::IJclCardinalEqualityComparer */
	void *__IJclCardinalTree;	/* Jclcontainerintf::IJclCardinalTree */
	
public:
	operator IJclCardinalTree*(void) { return (IJclCardinalTree*)&__IJclCardinalTree; }
	operator IJclCardinalCollection*(void) { return (IJclCardinalCollection*)&__IJclCardinalTree; }
	operator IJclCardinalEqualityComparer*(void) { return (IJclCardinalEqualityComparer*)&__IJclCardinalEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclCardinalTree; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalTree; }
	
};


class DELPHICLASS TJclCardinalTreeIterator;
class PASCALIMPLEMENTATION TJclCardinalTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclCardinalTreeNode* FCursor;
	TItrStart FStart;
	TJclCardinalTree* FOwnTree;
	Jclcontainerintf::_di_IJclCardinalEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclCardinalTreeNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclCardinalTreeNode* __fastcall GetNextSibling(void) = 0 ;
	virtual TJclCardinalTreeNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclCardinalTreeIterator(TJclCardinalTree* OwnTree, TJclCardinalTreeNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall AddChild(unsigned AValue);
	int __fastcall ChildrenCount(void);
	void __fastcall DeleteChild(int Index);
	void __fastcall DeleteChildren(void);
	void __fastcall ExtractChild(int Index);
	void __fastcall ExtractChildren(void);
	unsigned __fastcall GetChild(int Index);
	bool __fastcall HasChild(int Index);
	bool __fastcall HasParent(void);
	int __fastcall IndexOfChild(unsigned AValue);
	bool __fastcall InsertChild(int Index, unsigned AValue);
	unsigned __fastcall Parent(void);
	void __fastcall SetChild(int Index, unsigned AValue);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclCardinalTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclCardinalTreeIterator;	/* Jclcontainerintf::IJclCardinalTreeIterator */
	
public:
	operator IJclCardinalTreeIterator*(void) { return (IJclCardinalTreeIterator*)&__IJclCardinalTreeIterator; }
	operator IJclCardinalIterator*(void) { return (IJclCardinalIterator*)&__IJclCardinalTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderCardinalTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderCardinalTreeIterator : public TJclCardinalTreeIterator 
{
	typedef TJclCardinalTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclCardinalTreeNode* __fastcall GetNextCursor(void);
	virtual TJclCardinalTreeNode* __fastcall GetNextSibling(void);
	virtual TJclCardinalTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclCardinalTreeIterator.Create */ inline __fastcall TJclPreOrderCardinalTreeIterator(TJclCardinalTree* OwnTree, TJclCardinalTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclCardinalTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderCardinalTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclCardinalTreeIterator;	/* Jclcontainerintf::IJclCardinalTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalTreeIterator; }
	operator IJclCardinalTreeIterator*(void) { return (IJclCardinalTreeIterator*)&__IJclCardinalTreeIterator; }
	operator IJclCardinalIterator*(void) { return (IJclCardinalIterator*)&__IJclCardinalTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderCardinalTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderCardinalTreeIterator : public TJclCardinalTreeIterator 
{
	typedef TJclCardinalTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclCardinalTreeNode* __fastcall GetNextCursor(void);
	virtual TJclCardinalTreeNode* __fastcall GetNextSibling(void);
	virtual TJclCardinalTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclCardinalTreeIterator.Create */ inline __fastcall TJclPostOrderCardinalTreeIterator(TJclCardinalTree* OwnTree, TJclCardinalTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclCardinalTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderCardinalTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclCardinalTreeIterator;	/* Jclcontainerintf::IJclCardinalTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalTreeIterator; }
	operator IJclCardinalTreeIterator*(void) { return (IJclCardinalTreeIterator*)&__IJclCardinalTreeIterator; }
	operator IJclCardinalIterator*(void) { return (IJclCardinalIterator*)&__IJclCardinalTreeIterator; }
	
};


class DELPHICLASS TJclInt64TreeNode;
class PASCALIMPLEMENTATION TJclInt64TreeNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	__int64 Value;
	DynamicArray<System::TObject* >  Children;
	int ChildrenCount;
	TJclInt64TreeNode* Parent;
	int __fastcall IndexOfChild(TJclInt64TreeNode* AChild);
	int __fastcall IndexOfValue(const __int64 AValue, const Jclcontainerintf::_di_IJclInt64EqualityComparer AEqualityComparer);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclInt64TreeNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclInt64TreeNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclInt64Tree;
class PASCALIMPLEMENTATION TJclInt64Tree : public Jclabstractcontainers::TJclInt64AbstractContainer 
{
	typedef Jclabstractcontainers::TJclInt64AbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclInt64TreeNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	
protected:
	void __fastcall ExtractNode(TJclInt64TreeNode* &ANode);
	void __fastcall RemoveNode(TJclInt64TreeNode* &ANode);
	TJclInt64TreeNode* __fastcall CloneNode(TJclInt64TreeNode* Node, TJclInt64TreeNode* Parent);
	bool __fastcall NodeContains(TJclInt64TreeNode* ANode, const __int64 AValue);
	void __fastcall PackNode(TJclInt64TreeNode* ANode);
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclInt64Tree(void);
	__fastcall virtual ~TJclInt64Tree(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
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
	Jclcontainerintf::_di_IJclInt64TreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclInt64TreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclInt64EqualityComparer;	/* Jclcontainerintf::IJclInt64EqualityComparer */
	void *__IJclInt64Tree;	/* Jclcontainerintf::IJclInt64Tree */
	
public:
	operator IJclInt64Tree*(void) { return (IJclInt64Tree*)&__IJclInt64Tree; }
	operator IJclInt64Collection*(void) { return (IJclInt64Collection*)&__IJclInt64Tree; }
	operator IJclInt64EqualityComparer*(void) { return (IJclInt64EqualityComparer*)&__IJclInt64EqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclInt64Tree; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64Tree; }
	
};


class DELPHICLASS TJclInt64TreeIterator;
class PASCALIMPLEMENTATION TJclInt64TreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclInt64TreeNode* FCursor;
	TItrStart FStart;
	TJclInt64Tree* FOwnTree;
	Jclcontainerintf::_di_IJclInt64EqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclInt64TreeNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclInt64TreeNode* __fastcall GetNextSibling(void) = 0 ;
	virtual TJclInt64TreeNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclInt64TreeIterator(TJclInt64Tree* OwnTree, TJclInt64TreeNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall AddChild(const __int64 AValue);
	int __fastcall ChildrenCount(void);
	void __fastcall DeleteChild(int Index);
	void __fastcall DeleteChildren(void);
	void __fastcall ExtractChild(int Index);
	void __fastcall ExtractChildren(void);
	__int64 __fastcall GetChild(int Index);
	bool __fastcall HasChild(int Index);
	bool __fastcall HasParent(void);
	int __fastcall IndexOfChild(const __int64 AValue);
	bool __fastcall InsertChild(int Index, const __int64 AValue);
	__int64 __fastcall Parent(void);
	void __fastcall SetChild(int Index, const __int64 AValue);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclInt64TreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclInt64TreeIterator;	/* Jclcontainerintf::IJclInt64TreeIterator */
	
public:
	operator IJclInt64TreeIterator*(void) { return (IJclInt64TreeIterator*)&__IJclInt64TreeIterator; }
	operator IJclInt64Iterator*(void) { return (IJclInt64Iterator*)&__IJclInt64TreeIterator; }
	
};


class DELPHICLASS TJclPreOrderInt64TreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderInt64TreeIterator : public TJclInt64TreeIterator 
{
	typedef TJclInt64TreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclInt64TreeNode* __fastcall GetNextCursor(void);
	virtual TJclInt64TreeNode* __fastcall GetNextSibling(void);
	virtual TJclInt64TreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclInt64TreeIterator.Create */ inline __fastcall TJclPreOrderInt64TreeIterator(TJclInt64Tree* OwnTree, TJclInt64TreeNode* ACursor, bool AValid, TItrStart AStart) : TJclInt64TreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderInt64TreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclInt64TreeIterator;	/* Jclcontainerintf::IJclInt64TreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64TreeIterator; }
	operator IJclInt64TreeIterator*(void) { return (IJclInt64TreeIterator*)&__IJclInt64TreeIterator; }
	operator IJclInt64Iterator*(void) { return (IJclInt64Iterator*)&__IJclInt64TreeIterator; }
	
};


class DELPHICLASS TJclPostOrderInt64TreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderInt64TreeIterator : public TJclInt64TreeIterator 
{
	typedef TJclInt64TreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclInt64TreeNode* __fastcall GetNextCursor(void);
	virtual TJclInt64TreeNode* __fastcall GetNextSibling(void);
	virtual TJclInt64TreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclInt64TreeIterator.Create */ inline __fastcall TJclPostOrderInt64TreeIterator(TJclInt64Tree* OwnTree, TJclInt64TreeNode* ACursor, bool AValid, TItrStart AStart) : TJclInt64TreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderInt64TreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclInt64TreeIterator;	/* Jclcontainerintf::IJclInt64TreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64TreeIterator; }
	operator IJclInt64TreeIterator*(void) { return (IJclInt64TreeIterator*)&__IJclInt64TreeIterator; }
	operator IJclInt64Iterator*(void) { return (IJclInt64Iterator*)&__IJclInt64TreeIterator; }
	
};


class DELPHICLASS TJclPtrTreeNode;
class PASCALIMPLEMENTATION TJclPtrTreeNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	void *Value;
	DynamicArray<System::TObject* >  Children;
	int ChildrenCount;
	TJclPtrTreeNode* Parent;
	int __fastcall IndexOfChild(TJclPtrTreeNode* AChild);
	int __fastcall IndexOfValue(void * APtr, const Jclcontainerintf::_di_IJclPtrEqualityComparer AEqualityComparer);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclPtrTreeNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclPtrTreeNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclPtrTree;
class PASCALIMPLEMENTATION TJclPtrTree : public Jclabstractcontainers::TJclPtrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclPtrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclPtrTreeNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	
protected:
	void __fastcall ExtractNode(TJclPtrTreeNode* &ANode);
	void __fastcall RemoveNode(TJclPtrTreeNode* &ANode);
	TJclPtrTreeNode* __fastcall CloneNode(TJclPtrTreeNode* Node, TJclPtrTreeNode* Parent);
	bool __fastcall NodeContains(TJclPtrTreeNode* ANode, void * APtr);
	void __fastcall PackNode(TJclPtrTreeNode* ANode);
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclPtrTree(void);
	__fastcall virtual ~TJclPtrTree(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
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
	Jclcontainerintf::_di_IJclPtrTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclPtrTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclPtrEqualityComparer;	/* Jclcontainerintf::IJclPtrEqualityComparer */
	void *__IJclPtrTree;	/* Jclcontainerintf::IJclPtrTree */
	
public:
	operator IJclPtrTree*(void) { return (IJclPtrTree*)&__IJclPtrTree; }
	operator IJclPtrCollection*(void) { return (IJclPtrCollection*)&__IJclPtrTree; }
	operator IJclPtrEqualityComparer*(void) { return (IJclPtrEqualityComparer*)&__IJclPtrEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclPtrTree; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrTree; }
	
};


class DELPHICLASS TJclPtrTreeIterator;
class PASCALIMPLEMENTATION TJclPtrTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclPtrTreeNode* FCursor;
	TItrStart FStart;
	TJclPtrTree* FOwnTree;
	Jclcontainerintf::_di_IJclPtrEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclPtrTreeNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclPtrTreeNode* __fastcall GetNextSibling(void) = 0 ;
	virtual TJclPtrTreeNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclPtrTreeIterator(TJclPtrTree* OwnTree, TJclPtrTreeNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall AddChild(void * APtr);
	int __fastcall ChildrenCount(void);
	void __fastcall DeleteChild(int Index);
	void __fastcall DeleteChildren(void);
	void __fastcall ExtractChild(int Index);
	void __fastcall ExtractChildren(void);
	void * __fastcall GetChild(int Index);
	bool __fastcall HasChild(int Index);
	bool __fastcall HasParent(void);
	int __fastcall IndexOfChild(void * APtr);
	bool __fastcall InsertChild(int Index, void * APtr);
	void * __fastcall Parent(void);
	void __fastcall SetChild(int Index, void * APtr);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPtrTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclPtrTreeIterator;	/* Jclcontainerintf::IJclPtrTreeIterator */
	
public:
	operator IJclPtrTreeIterator*(void) { return (IJclPtrTreeIterator*)&__IJclPtrTreeIterator; }
	operator IJclPtrIterator*(void) { return (IJclPtrIterator*)&__IJclPtrTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderPtrTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderPtrTreeIterator : public TJclPtrTreeIterator 
{
	typedef TJclPtrTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclPtrTreeNode* __fastcall GetNextCursor(void);
	virtual TJclPtrTreeNode* __fastcall GetNextSibling(void);
	virtual TJclPtrTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclPtrTreeIterator.Create */ inline __fastcall TJclPreOrderPtrTreeIterator(TJclPtrTree* OwnTree, TJclPtrTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclPtrTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderPtrTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclPtrTreeIterator;	/* Jclcontainerintf::IJclPtrTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrTreeIterator; }
	operator IJclPtrTreeIterator*(void) { return (IJclPtrTreeIterator*)&__IJclPtrTreeIterator; }
	operator IJclPtrIterator*(void) { return (IJclPtrIterator*)&__IJclPtrTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderPtrTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderPtrTreeIterator : public TJclPtrTreeIterator 
{
	typedef TJclPtrTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclPtrTreeNode* __fastcall GetNextCursor(void);
	virtual TJclPtrTreeNode* __fastcall GetNextSibling(void);
	virtual TJclPtrTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclPtrTreeIterator.Create */ inline __fastcall TJclPostOrderPtrTreeIterator(TJclPtrTree* OwnTree, TJclPtrTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclPtrTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderPtrTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclPtrTreeIterator;	/* Jclcontainerintf::IJclPtrTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrTreeIterator; }
	operator IJclPtrTreeIterator*(void) { return (IJclPtrTreeIterator*)&__IJclPtrTreeIterator; }
	operator IJclPtrIterator*(void) { return (IJclPtrIterator*)&__IJclPtrTreeIterator; }
	
};


class DELPHICLASS TJclTreeNode;
class PASCALIMPLEMENTATION TJclTreeNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	System::TObject* Value;
	DynamicArray<System::TObject* >  Children;
	int ChildrenCount;
	TJclTreeNode* Parent;
	int __fastcall IndexOfChild(TJclTreeNode* AChild);
	int __fastcall IndexOfValue(System::TObject* AObject, const Jclcontainerintf::_di_IJclEqualityComparer AEqualityComparer);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclTreeNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTreeNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTree;
class PASCALIMPLEMENTATION TJclTree : public Jclabstractcontainers::TJclAbstractContainer 
{
	typedef Jclabstractcontainers::TJclAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	TJclTreeNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	
protected:
	void __fastcall ExtractNode(TJclTreeNode* &ANode);
	void __fastcall RemoveNode(TJclTreeNode* &ANode);
	TJclTreeNode* __fastcall CloneNode(TJclTreeNode* Node, TJclTreeNode* Parent);
	bool __fastcall NodeContains(TJclTreeNode* ANode, System::TObject* AObject);
	void __fastcall PackNode(TJclTreeNode* ANode);
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	
public:
	__fastcall TJclTree(bool AOwnsObjects);
	__fastcall virtual ~TJclTree(void);
	virtual void __fastcall Pack(void);
	virtual void __fastcall SetCapacity(int Value);
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
	Jclcontainerintf::_di_IJclTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclGrowable;	/* Jclcontainerintf::IJclGrowable */
	void *__IJclEqualityComparer;	/* Jclcontainerintf::IJclEqualityComparer */
	void *__IJclObjectOwner;	/* Jclcontainerintf::IJclObjectOwner */
	void *__IJclTree;	/* Jclcontainerintf::IJclTree */
	
public:
	operator IJclTree*(void) { return (IJclTree*)&__IJclTree; }
	operator IJclCollection*(void) { return (IJclCollection*)&__IJclTree; }
	operator IJclObjectOwner*(void) { return (IJclObjectOwner*)&__IJclObjectOwner; }
	operator IJclEqualityComparer*(void) { return (IJclEqualityComparer*)&__IJclEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclTree; }
	operator IJclGrowable*(void) { return (IJclGrowable*)&__IJclGrowable; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclGrowable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclTree; }
	
};


class DELPHICLASS TJclTreeIterator;
class PASCALIMPLEMENTATION TJclTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclTreeNode* FCursor;
	TItrStart FStart;
	TJclTree* FOwnTree;
	Jclcontainerintf::_di_IJclEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclTreeNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclTreeNode* __fastcall GetNextSibling(void) = 0 ;
	virtual TJclTreeNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclTreeIterator(TJclTree* OwnTree, TJclTreeNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall AddChild(System::TObject* AObject);
	int __fastcall ChildrenCount(void);
	void __fastcall DeleteChild(int Index);
	void __fastcall DeleteChildren(void);
	void __fastcall ExtractChild(int Index);
	void __fastcall ExtractChildren(void);
	System::TObject* __fastcall GetChild(int Index);
	bool __fastcall HasChild(int Index);
	bool __fastcall HasParent(void);
	int __fastcall IndexOfChild(System::TObject* AObject);
	bool __fastcall InsertChild(int Index, System::TObject* AObject);
	System::TObject* __fastcall Parent(void);
	void __fastcall SetChild(int Index, System::TObject* AObject);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclTreeIterator;	/* Jclcontainerintf::IJclTreeIterator */
	
public:
	operator IJclTreeIterator*(void) { return (IJclTreeIterator*)&__IJclTreeIterator; }
	operator IJclIterator*(void) { return (IJclIterator*)&__IJclTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderTreeIterator : public TJclTreeIterator 
{
	typedef TJclTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclTreeNode* __fastcall GetNextCursor(void);
	virtual TJclTreeNode* __fastcall GetNextSibling(void);
	virtual TJclTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclTreeIterator.Create */ inline __fastcall TJclPreOrderTreeIterator(TJclTree* OwnTree, TJclTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclTreeIterator;	/* Jclcontainerintf::IJclTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclTreeIterator; }
	operator IJclTreeIterator*(void) { return (IJclTreeIterator*)&__IJclTreeIterator; }
	operator IJclIterator*(void) { return (IJclIterator*)&__IJclTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderTreeIterator : public TJclTreeIterator 
{
	typedef TJclTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclTreeNode* __fastcall GetNextCursor(void);
	virtual TJclTreeNode* __fastcall GetNextSibling(void);
	virtual TJclTreeNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclTreeIterator.Create */ inline __fastcall TJclPostOrderTreeIterator(TJclTree* OwnTree, TJclTreeNode* ACursor, bool AValid, TItrStart AStart) : TJclTreeIterator(OwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclTreeIterator;	/* Jclcontainerintf::IJclTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclTreeIterator; }
	operator IJclTreeIterator*(void) { return (IJclTreeIterator*)&__IJclTreeIterator; }
	operator IJclIterator*(void) { return (IJclIterator*)&__IJclTreeIterator; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jcltrees */
using namespace Jcltrees;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcltrees
