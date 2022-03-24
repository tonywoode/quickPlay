// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclbinarytrees.pas' rev: 10.00

#ifndef JclbinarytreesHPP
#define JclbinarytreesHPP

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
#include <Jclalgorithms.hpp>	// Pascal unit
#include <Jclcontainerintf.hpp>	// Pascal unit
#include <Jclsynch.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclbinarytrees
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TItrStart { isFirst, isLast, isRoot };
#pragma option pop

class DELPHICLASS TJclIntfBinaryNode;
class PASCALIMPLEMENTATION TJclIntfBinaryNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	System::_di_IInterface Value;
	TJclIntfBinaryNode* Left;
	TJclIntfBinaryNode* Right;
	TJclIntfBinaryNode* Parent;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntfBinaryNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntfBinaryNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclIntfBinaryTree;
class PASCALIMPLEMENTATION TJclIntfBinaryTree : public Jclabstractcontainers::TJclIntfAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntfAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int FMaxDepth;
	TJclIntfBinaryNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	TJclIntfBinaryNode* __fastcall BuildTree(TJclIntfBinaryNode* const * LeafArray, const int LeafArray_Size, int Left, int Right, TJclIntfBinaryNode* Parent, int Offset);
	TJclIntfBinaryNode* __fastcall CloneNode(TJclIntfBinaryNode* Node, TJclIntfBinaryNode* Parent);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AutoPack(void);
	
public:
	__fastcall TJclIntfBinaryTree(Jclcontainerintf::TIntfCompare ACompare);
	__fastcall virtual ~TJclIntfBinaryTree(void);
	virtual void __fastcall Pack(void);
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
	Jclcontainerintf::_di_IJclIntfTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclIntfTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclIntfEqualityComparer;	/* Jclcontainerintf::IJclIntfEqualityComparer */
	void *__IJclIntfComparer;	/* Jclcontainerintf::IJclIntfComparer */
	void *__IJclIntfTree;	/* Jclcontainerintf::IJclIntfTree */
	
public:
	operator IJclIntfTree*(void) { return (IJclIntfTree*)&__IJclIntfTree; }
	operator IJclIntfCollection*(void) { return (IJclIntfCollection*)&__IJclIntfTree; }
	operator IJclIntfComparer*(void) { return (IJclIntfComparer*)&__IJclIntfComparer; }
	operator IJclIntfEqualityComparer*(void) { return (IJclIntfEqualityComparer*)&__IJclIntfEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntfTree; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfTree; }
	
};


class DELPHICLASS TJclIntfBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclIntfBinaryTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclIntfBinaryNode* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclIntfCollection FOwnTree;
	Jclcontainerintf::_di_IJclIntfEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclIntfBinaryNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclIntfBinaryNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclIntfBinaryTreeIterator(const Jclcontainerintf::_di_IJclIntfCollection AOwnTree, TJclIntfBinaryNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall HasLeft(void);
	bool __fastcall HasRight(void);
	System::_di_IInterface __fastcall Left();
	System::_di_IInterface __fastcall Right();
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclIntfBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfBinaryTreeIterator;	/* Jclcontainerintf::IJclIntfBinaryTreeIterator */
	
public:
	operator IJclIntfBinaryTreeIterator*(void) { return (IJclIntfBinaryTreeIterator*)&__IJclIntfBinaryTreeIterator; }
	operator IJclIntfTreeIterator*(void) { return (IJclIntfTreeIterator*)&__IJclIntfBinaryTreeIterator; }
	operator IJclIntfIterator*(void) { return (IJclIntfIterator*)&__IJclIntfBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderIntfBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderIntfBinaryTreeIterator : public TJclIntfBinaryTreeIterator 
{
	typedef TJclIntfBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclIntfBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclIntfBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclIntfBinaryTreeIterator.Create */ inline __fastcall TJclPreOrderIntfBinaryTreeIterator(const Jclcontainerintf::_di_IJclIntfCollection AOwnTree, TJclIntfBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclIntfBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderIntfBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfBinaryTreeIterator;	/* Jclcontainerintf::IJclIntfBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfBinaryTreeIterator; }
	operator IJclIntfBinaryTreeIterator*(void) { return (IJclIntfBinaryTreeIterator*)&__IJclIntfBinaryTreeIterator; }
	operator IJclIntfTreeIterator*(void) { return (IJclIntfTreeIterator*)&__IJclIntfBinaryTreeIterator; }
	operator IJclIntfIterator*(void) { return (IJclIntfIterator*)&__IJclIntfBinaryTreeIterator; }
	
};


class DELPHICLASS TJclInOrderIntfBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclInOrderIntfBinaryTreeIterator : public TJclIntfBinaryTreeIterator 
{
	typedef TJclIntfBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclIntfBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclIntfBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclIntfBinaryTreeIterator.Create */ inline __fastcall TJclInOrderIntfBinaryTreeIterator(const Jclcontainerintf::_di_IJclIntfCollection AOwnTree, TJclIntfBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclIntfBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclInOrderIntfBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfBinaryTreeIterator;	/* Jclcontainerintf::IJclIntfBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfBinaryTreeIterator; }
	operator IJclIntfBinaryTreeIterator*(void) { return (IJclIntfBinaryTreeIterator*)&__IJclIntfBinaryTreeIterator; }
	operator IJclIntfTreeIterator*(void) { return (IJclIntfTreeIterator*)&__IJclIntfBinaryTreeIterator; }
	operator IJclIntfIterator*(void) { return (IJclIntfIterator*)&__IJclIntfBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderIntfBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderIntfBinaryTreeIterator : public TJclIntfBinaryTreeIterator 
{
	typedef TJclIntfBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclIntfBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclIntfBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclIntfBinaryTreeIterator.Create */ inline __fastcall TJclPostOrderIntfBinaryTreeIterator(const Jclcontainerintf::_di_IJclIntfCollection AOwnTree, TJclIntfBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclIntfBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderIntfBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclIntfBinaryTreeIterator;	/* Jclcontainerintf::IJclIntfBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntfBinaryTreeIterator; }
	operator IJclIntfBinaryTreeIterator*(void) { return (IJclIntfBinaryTreeIterator*)&__IJclIntfBinaryTreeIterator; }
	operator IJclIntfTreeIterator*(void) { return (IJclIntfTreeIterator*)&__IJclIntfBinaryTreeIterator; }
	operator IJclIntfIterator*(void) { return (IJclIntfIterator*)&__IJclIntfBinaryTreeIterator; }
	
};


class DELPHICLASS TJclAnsiStrBinaryNode;
class PASCALIMPLEMENTATION TJclAnsiStrBinaryNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	AnsiString Value;
	TJclAnsiStrBinaryNode* Left;
	TJclAnsiStrBinaryNode* Right;
	TJclAnsiStrBinaryNode* Parent;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclAnsiStrBinaryNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclAnsiStrBinaryNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclAnsiStrBinaryTree;
class PASCALIMPLEMENTATION TJclAnsiStrBinaryTree : public Jclabstractcontainers::TJclAnsiStrAbstractCollection 
{
	typedef Jclabstractcontainers::TJclAnsiStrAbstractCollection inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int FMaxDepth;
	TJclAnsiStrBinaryNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	TJclAnsiStrBinaryNode* __fastcall BuildTree(TJclAnsiStrBinaryNode* const * LeafArray, const int LeafArray_Size, int Left, int Right, TJclAnsiStrBinaryNode* Parent, int Offset);
	TJclAnsiStrBinaryNode* __fastcall CloneNode(TJclAnsiStrBinaryNode* Node, TJclAnsiStrBinaryNode* Parent);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AutoPack(void);
	
public:
	__fastcall TJclAnsiStrBinaryTree(Jclcontainerintf::TAnsiStrCompare ACompare);
	__fastcall virtual ~TJclAnsiStrBinaryTree(void);
	virtual void __fastcall Pack(void);
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
	Jclcontainerintf::_di_IJclAnsiStrTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclAnsiStrTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclAnsiStrEqualityComparer;	/* Jclcontainerintf::IJclAnsiStrEqualityComparer */
	void *__IJclAnsiStrComparer;	/* Jclcontainerintf::IJclAnsiStrComparer */
	void *__IJclAnsiStrTree;	/* Jclcontainerintf::IJclAnsiStrTree */
	
public:
	operator IJclAnsiStrTree*(void) { return (IJclAnsiStrTree*)&__IJclAnsiStrTree; }
	operator IJclAnsiStrCollection*(void) { return (IJclAnsiStrCollection*)&__IJclAnsiStrTree; }
	operator IJclAnsiStrComparer*(void) { return (IJclAnsiStrComparer*)&__IJclAnsiStrComparer; }
	operator IJclAnsiStrEqualityComparer*(void) { return (IJclAnsiStrEqualityComparer*)&__IJclAnsiStrEqualityComparer; }
	operator IJclAnsiStrFlatContainer*(void) { return (IJclAnsiStrFlatContainer*)&__IJclAnsiStrTree; }
	operator IJclAnsiStrContainer*(void) { return (IJclAnsiStrContainer*)&__IJclAnsiStrTree; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclAnsiStrTree; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclAnsiStrTree; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrTree; }
	
};


class DELPHICLASS TJclAnsiStrBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclAnsiStrBinaryTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclAnsiStrBinaryNode* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclAnsiStrCollection FOwnTree;
	Jclcontainerintf::_di_IJclAnsiStrEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclAnsiStrBinaryNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclAnsiStrBinaryNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclAnsiStrBinaryTreeIterator(const Jclcontainerintf::_di_IJclAnsiStrCollection AOwnTree, TJclAnsiStrBinaryNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall HasLeft(void);
	bool __fastcall HasRight(void);
	AnsiString __fastcall Left();
	AnsiString __fastcall Right();
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclAnsiStrBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclAnsiStrBinaryTreeIterator;	/* Jclcontainerintf::IJclAnsiStrBinaryTreeIterator */
	
public:
	operator IJclAnsiStrBinaryTreeIterator*(void) { return (IJclAnsiStrBinaryTreeIterator*)&__IJclAnsiStrBinaryTreeIterator; }
	operator IJclAnsiStrTreeIterator*(void) { return (IJclAnsiStrTreeIterator*)&__IJclAnsiStrBinaryTreeIterator; }
	operator IJclAnsiStrIterator*(void) { return (IJclAnsiStrIterator*)&__IJclAnsiStrBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderAnsiStrBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderAnsiStrBinaryTreeIterator : public TJclAnsiStrBinaryTreeIterator 
{
	typedef TJclAnsiStrBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclAnsiStrBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclAnsiStrBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclAnsiStrBinaryTreeIterator.Create */ inline __fastcall TJclPreOrderAnsiStrBinaryTreeIterator(const Jclcontainerintf::_di_IJclAnsiStrCollection AOwnTree, TJclAnsiStrBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclAnsiStrBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderAnsiStrBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclAnsiStrBinaryTreeIterator;	/* Jclcontainerintf::IJclAnsiStrBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrBinaryTreeIterator; }
	operator IJclAnsiStrBinaryTreeIterator*(void) { return (IJclAnsiStrBinaryTreeIterator*)&__IJclAnsiStrBinaryTreeIterator; }
	operator IJclAnsiStrTreeIterator*(void) { return (IJclAnsiStrTreeIterator*)&__IJclAnsiStrBinaryTreeIterator; }
	operator IJclAnsiStrIterator*(void) { return (IJclAnsiStrIterator*)&__IJclAnsiStrBinaryTreeIterator; }
	
};


class DELPHICLASS TJclInOrderAnsiStrBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclInOrderAnsiStrBinaryTreeIterator : public TJclAnsiStrBinaryTreeIterator 
{
	typedef TJclAnsiStrBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclAnsiStrBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclAnsiStrBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclAnsiStrBinaryTreeIterator.Create */ inline __fastcall TJclInOrderAnsiStrBinaryTreeIterator(const Jclcontainerintf::_di_IJclAnsiStrCollection AOwnTree, TJclAnsiStrBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclAnsiStrBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclInOrderAnsiStrBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclAnsiStrBinaryTreeIterator;	/* Jclcontainerintf::IJclAnsiStrBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrBinaryTreeIterator; }
	operator IJclAnsiStrBinaryTreeIterator*(void) { return (IJclAnsiStrBinaryTreeIterator*)&__IJclAnsiStrBinaryTreeIterator; }
	operator IJclAnsiStrTreeIterator*(void) { return (IJclAnsiStrTreeIterator*)&__IJclAnsiStrBinaryTreeIterator; }
	operator IJclAnsiStrIterator*(void) { return (IJclAnsiStrIterator*)&__IJclAnsiStrBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderAnsiStrBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderAnsiStrBinaryTreeIterator : public TJclAnsiStrBinaryTreeIterator 
{
	typedef TJclAnsiStrBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclAnsiStrBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclAnsiStrBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclAnsiStrBinaryTreeIterator.Create */ inline __fastcall TJclPostOrderAnsiStrBinaryTreeIterator(const Jclcontainerintf::_di_IJclAnsiStrCollection AOwnTree, TJclAnsiStrBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclAnsiStrBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderAnsiStrBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclAnsiStrBinaryTreeIterator;	/* Jclcontainerintf::IJclAnsiStrBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclAnsiStrBinaryTreeIterator; }
	operator IJclAnsiStrBinaryTreeIterator*(void) { return (IJclAnsiStrBinaryTreeIterator*)&__IJclAnsiStrBinaryTreeIterator; }
	operator IJclAnsiStrTreeIterator*(void) { return (IJclAnsiStrTreeIterator*)&__IJclAnsiStrBinaryTreeIterator; }
	operator IJclAnsiStrIterator*(void) { return (IJclAnsiStrIterator*)&__IJclAnsiStrBinaryTreeIterator; }
	
};


class DELPHICLASS TJclWideStrBinaryNode;
class PASCALIMPLEMENTATION TJclWideStrBinaryNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	WideString Value;
	TJclWideStrBinaryNode* Left;
	TJclWideStrBinaryNode* Right;
	TJclWideStrBinaryNode* Parent;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclWideStrBinaryNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclWideStrBinaryNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclWideStrBinaryTree;
class PASCALIMPLEMENTATION TJclWideStrBinaryTree : public Jclabstractcontainers::TJclWideStrAbstractCollection 
{
	typedef Jclabstractcontainers::TJclWideStrAbstractCollection inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int FMaxDepth;
	TJclWideStrBinaryNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	TJclWideStrBinaryNode* __fastcall BuildTree(TJclWideStrBinaryNode* const * LeafArray, const int LeafArray_Size, int Left, int Right, TJclWideStrBinaryNode* Parent, int Offset);
	TJclWideStrBinaryNode* __fastcall CloneNode(TJclWideStrBinaryNode* Node, TJclWideStrBinaryNode* Parent);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AutoPack(void);
	
public:
	__fastcall TJclWideStrBinaryTree(Jclcontainerintf::TWideStrCompare ACompare);
	__fastcall virtual ~TJclWideStrBinaryTree(void);
	virtual void __fastcall Pack(void);
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
	Jclcontainerintf::_di_IJclWideStrTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclWideStrTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclWideStrEqualityComparer;	/* Jclcontainerintf::IJclWideStrEqualityComparer */
	void *__IJclWideStrComparer;	/* Jclcontainerintf::IJclWideStrComparer */
	void *__IJclWideStrTree;	/* Jclcontainerintf::IJclWideStrTree */
	
public:
	operator IJclWideStrTree*(void) { return (IJclWideStrTree*)&__IJclWideStrTree; }
	operator IJclWideStrCollection*(void) { return (IJclWideStrCollection*)&__IJclWideStrTree; }
	operator IJclWideStrComparer*(void) { return (IJclWideStrComparer*)&__IJclWideStrComparer; }
	operator IJclWideStrEqualityComparer*(void) { return (IJclWideStrEqualityComparer*)&__IJclWideStrEqualityComparer; }
	operator IJclWideStrFlatContainer*(void) { return (IJclWideStrFlatContainer*)&__IJclWideStrTree; }
	operator IJclWideStrContainer*(void) { return (IJclWideStrContainer*)&__IJclWideStrTree; }
	operator IJclStrContainer*(void) { return (IJclStrContainer*)&__IJclWideStrTree; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclWideStrTree; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrTree; }
	
};


class DELPHICLASS TJclWideStrBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclWideStrBinaryTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclWideStrBinaryNode* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclWideStrCollection FOwnTree;
	Jclcontainerintf::_di_IJclWideStrEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclWideStrBinaryNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclWideStrBinaryNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclWideStrBinaryTreeIterator(const Jclcontainerintf::_di_IJclWideStrCollection AOwnTree, TJclWideStrBinaryNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall HasLeft(void);
	bool __fastcall HasRight(void);
	WideString __fastcall Left();
	WideString __fastcall Right();
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclWideStrBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclWideStrBinaryTreeIterator;	/* Jclcontainerintf::IJclWideStrBinaryTreeIterator */
	
public:
	operator IJclWideStrBinaryTreeIterator*(void) { return (IJclWideStrBinaryTreeIterator*)&__IJclWideStrBinaryTreeIterator; }
	operator IJclWideStrTreeIterator*(void) { return (IJclWideStrTreeIterator*)&__IJclWideStrBinaryTreeIterator; }
	operator IJclWideStrIterator*(void) { return (IJclWideStrIterator*)&__IJclWideStrBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderWideStrBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderWideStrBinaryTreeIterator : public TJclWideStrBinaryTreeIterator 
{
	typedef TJclWideStrBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclWideStrBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclWideStrBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclWideStrBinaryTreeIterator.Create */ inline __fastcall TJclPreOrderWideStrBinaryTreeIterator(const Jclcontainerintf::_di_IJclWideStrCollection AOwnTree, TJclWideStrBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclWideStrBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderWideStrBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclWideStrBinaryTreeIterator;	/* Jclcontainerintf::IJclWideStrBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrBinaryTreeIterator; }
	operator IJclWideStrBinaryTreeIterator*(void) { return (IJclWideStrBinaryTreeIterator*)&__IJclWideStrBinaryTreeIterator; }
	operator IJclWideStrTreeIterator*(void) { return (IJclWideStrTreeIterator*)&__IJclWideStrBinaryTreeIterator; }
	operator IJclWideStrIterator*(void) { return (IJclWideStrIterator*)&__IJclWideStrBinaryTreeIterator; }
	
};


class DELPHICLASS TJclInOrderWideStrBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclInOrderWideStrBinaryTreeIterator : public TJclWideStrBinaryTreeIterator 
{
	typedef TJclWideStrBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclWideStrBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclWideStrBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclWideStrBinaryTreeIterator.Create */ inline __fastcall TJclInOrderWideStrBinaryTreeIterator(const Jclcontainerintf::_di_IJclWideStrCollection AOwnTree, TJclWideStrBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclWideStrBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclInOrderWideStrBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclWideStrBinaryTreeIterator;	/* Jclcontainerintf::IJclWideStrBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrBinaryTreeIterator; }
	operator IJclWideStrBinaryTreeIterator*(void) { return (IJclWideStrBinaryTreeIterator*)&__IJclWideStrBinaryTreeIterator; }
	operator IJclWideStrTreeIterator*(void) { return (IJclWideStrTreeIterator*)&__IJclWideStrBinaryTreeIterator; }
	operator IJclWideStrIterator*(void) { return (IJclWideStrIterator*)&__IJclWideStrBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderWideStrBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderWideStrBinaryTreeIterator : public TJclWideStrBinaryTreeIterator 
{
	typedef TJclWideStrBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclWideStrBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclWideStrBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclWideStrBinaryTreeIterator.Create */ inline __fastcall TJclPostOrderWideStrBinaryTreeIterator(const Jclcontainerintf::_di_IJclWideStrCollection AOwnTree, TJclWideStrBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclWideStrBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderWideStrBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclWideStrBinaryTreeIterator;	/* Jclcontainerintf::IJclWideStrBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclWideStrBinaryTreeIterator; }
	operator IJclWideStrBinaryTreeIterator*(void) { return (IJclWideStrBinaryTreeIterator*)&__IJclWideStrBinaryTreeIterator; }
	operator IJclWideStrTreeIterator*(void) { return (IJclWideStrTreeIterator*)&__IJclWideStrBinaryTreeIterator; }
	operator IJclWideStrIterator*(void) { return (IJclWideStrIterator*)&__IJclWideStrBinaryTreeIterator; }
	
};


typedef TJclAnsiStrBinaryTree TJclStrBinaryTree;
;

class DELPHICLASS TJclSingleBinaryNode;
class PASCALIMPLEMENTATION TJclSingleBinaryNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	float Value;
	TJclSingleBinaryNode* Left;
	TJclSingleBinaryNode* Right;
	TJclSingleBinaryNode* Parent;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclSingleBinaryNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclSingleBinaryNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclSingleBinaryTree;
class PASCALIMPLEMENTATION TJclSingleBinaryTree : public Jclabstractcontainers::TJclSingleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclSingleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int FMaxDepth;
	TJclSingleBinaryNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	TJclSingleBinaryNode* __fastcall BuildTree(TJclSingleBinaryNode* const * LeafArray, const int LeafArray_Size, int Left, int Right, TJclSingleBinaryNode* Parent, int Offset);
	TJclSingleBinaryNode* __fastcall CloneNode(TJclSingleBinaryNode* Node, TJclSingleBinaryNode* Parent);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AutoPack(void);
	
public:
	__fastcall TJclSingleBinaryTree(Jclcontainerintf::TSingleCompare ACompare);
	__fastcall virtual ~TJclSingleBinaryTree(void);
	virtual void __fastcall Pack(void);
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
	Jclcontainerintf::_di_IJclSingleTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclSingleTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclSingleEqualityComparer;	/* Jclcontainerintf::IJclSingleEqualityComparer */
	void *__IJclSingleComparer;	/* Jclcontainerintf::IJclSingleComparer */
	void *__IJclSingleTree;	/* Jclcontainerintf::IJclSingleTree */
	
public:
	operator IJclSingleTree*(void) { return (IJclSingleTree*)&__IJclSingleTree; }
	operator IJclSingleCollection*(void) { return (IJclSingleCollection*)&__IJclSingleTree; }
	operator IJclSingleComparer*(void) { return (IJclSingleComparer*)&__IJclSingleComparer; }
	operator IJclSingleEqualityComparer*(void) { return (IJclSingleEqualityComparer*)&__IJclSingleEqualityComparer; }
	operator IJclSingleContainer*(void) { return (IJclSingleContainer*)&__IJclSingleTree; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclSingleTree; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleTree; }
	
};


class DELPHICLASS TJclSingleBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclSingleBinaryTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclSingleBinaryNode* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclSingleCollection FOwnTree;
	Jclcontainerintf::_di_IJclSingleEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclSingleBinaryNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclSingleBinaryNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclSingleBinaryTreeIterator(const Jclcontainerintf::_di_IJclSingleCollection AOwnTree, TJclSingleBinaryNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall HasLeft(void);
	bool __fastcall HasRight(void);
	float __fastcall Left(void);
	float __fastcall Right(void);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclSingleBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclSingleBinaryTreeIterator;	/* Jclcontainerintf::IJclSingleBinaryTreeIterator */
	
public:
	operator IJclSingleBinaryTreeIterator*(void) { return (IJclSingleBinaryTreeIterator*)&__IJclSingleBinaryTreeIterator; }
	operator IJclSingleTreeIterator*(void) { return (IJclSingleTreeIterator*)&__IJclSingleBinaryTreeIterator; }
	operator IJclSingleIterator*(void) { return (IJclSingleIterator*)&__IJclSingleBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderSingleBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderSingleBinaryTreeIterator : public TJclSingleBinaryTreeIterator 
{
	typedef TJclSingleBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclSingleBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclSingleBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclSingleBinaryTreeIterator.Create */ inline __fastcall TJclPreOrderSingleBinaryTreeIterator(const Jclcontainerintf::_di_IJclSingleCollection AOwnTree, TJclSingleBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclSingleBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderSingleBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclSingleBinaryTreeIterator;	/* Jclcontainerintf::IJclSingleBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleBinaryTreeIterator; }
	operator IJclSingleBinaryTreeIterator*(void) { return (IJclSingleBinaryTreeIterator*)&__IJclSingleBinaryTreeIterator; }
	operator IJclSingleTreeIterator*(void) { return (IJclSingleTreeIterator*)&__IJclSingleBinaryTreeIterator; }
	operator IJclSingleIterator*(void) { return (IJclSingleIterator*)&__IJclSingleBinaryTreeIterator; }
	
};


class DELPHICLASS TJclInOrderSingleBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclInOrderSingleBinaryTreeIterator : public TJclSingleBinaryTreeIterator 
{
	typedef TJclSingleBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclSingleBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclSingleBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclSingleBinaryTreeIterator.Create */ inline __fastcall TJclInOrderSingleBinaryTreeIterator(const Jclcontainerintf::_di_IJclSingleCollection AOwnTree, TJclSingleBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclSingleBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclInOrderSingleBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclSingleBinaryTreeIterator;	/* Jclcontainerintf::IJclSingleBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleBinaryTreeIterator; }
	operator IJclSingleBinaryTreeIterator*(void) { return (IJclSingleBinaryTreeIterator*)&__IJclSingleBinaryTreeIterator; }
	operator IJclSingleTreeIterator*(void) { return (IJclSingleTreeIterator*)&__IJclSingleBinaryTreeIterator; }
	operator IJclSingleIterator*(void) { return (IJclSingleIterator*)&__IJclSingleBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderSingleBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderSingleBinaryTreeIterator : public TJclSingleBinaryTreeIterator 
{
	typedef TJclSingleBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclSingleBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclSingleBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclSingleBinaryTreeIterator.Create */ inline __fastcall TJclPostOrderSingleBinaryTreeIterator(const Jclcontainerintf::_di_IJclSingleCollection AOwnTree, TJclSingleBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclSingleBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderSingleBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclSingleBinaryTreeIterator;	/* Jclcontainerintf::IJclSingleBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclSingleBinaryTreeIterator; }
	operator IJclSingleBinaryTreeIterator*(void) { return (IJclSingleBinaryTreeIterator*)&__IJclSingleBinaryTreeIterator; }
	operator IJclSingleTreeIterator*(void) { return (IJclSingleTreeIterator*)&__IJclSingleBinaryTreeIterator; }
	operator IJclSingleIterator*(void) { return (IJclSingleIterator*)&__IJclSingleBinaryTreeIterator; }
	
};


class DELPHICLASS TJclDoubleBinaryNode;
class PASCALIMPLEMENTATION TJclDoubleBinaryNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	double Value;
	TJclDoubleBinaryNode* Left;
	TJclDoubleBinaryNode* Right;
	TJclDoubleBinaryNode* Parent;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclDoubleBinaryNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclDoubleBinaryNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclDoubleBinaryTree;
class PASCALIMPLEMENTATION TJclDoubleBinaryTree : public Jclabstractcontainers::TJclDoubleAbstractContainer 
{
	typedef Jclabstractcontainers::TJclDoubleAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int FMaxDepth;
	TJclDoubleBinaryNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	TJclDoubleBinaryNode* __fastcall BuildTree(TJclDoubleBinaryNode* const * LeafArray, const int LeafArray_Size, int Left, int Right, TJclDoubleBinaryNode* Parent, int Offset);
	TJclDoubleBinaryNode* __fastcall CloneNode(TJclDoubleBinaryNode* Node, TJclDoubleBinaryNode* Parent);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AutoPack(void);
	
public:
	__fastcall TJclDoubleBinaryTree(Jclcontainerintf::TDoubleCompare ACompare);
	__fastcall virtual ~TJclDoubleBinaryTree(void);
	virtual void __fastcall Pack(void);
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
	Jclcontainerintf::_di_IJclDoubleTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclDoubleTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclDoubleEqualityComparer;	/* Jclcontainerintf::IJclDoubleEqualityComparer */
	void *__IJclDoubleComparer;	/* Jclcontainerintf::IJclDoubleComparer */
	void *__IJclDoubleTree;	/* Jclcontainerintf::IJclDoubleTree */
	
public:
	operator IJclDoubleTree*(void) { return (IJclDoubleTree*)&__IJclDoubleTree; }
	operator IJclDoubleCollection*(void) { return (IJclDoubleCollection*)&__IJclDoubleTree; }
	operator IJclDoubleComparer*(void) { return (IJclDoubleComparer*)&__IJclDoubleComparer; }
	operator IJclDoubleEqualityComparer*(void) { return (IJclDoubleEqualityComparer*)&__IJclDoubleEqualityComparer; }
	operator IJclDoubleContainer*(void) { return (IJclDoubleContainer*)&__IJclDoubleTree; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclDoubleTree; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleTree; }
	
};


class DELPHICLASS TJclDoubleBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclDoubleBinaryTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclDoubleBinaryNode* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclDoubleCollection FOwnTree;
	Jclcontainerintf::_di_IJclDoubleEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclDoubleBinaryNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclDoubleBinaryNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclDoubleBinaryTreeIterator(const Jclcontainerintf::_di_IJclDoubleCollection AOwnTree, TJclDoubleBinaryNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall HasLeft(void);
	bool __fastcall HasRight(void);
	double __fastcall Left(void);
	double __fastcall Right(void);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclDoubleBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclDoubleBinaryTreeIterator;	/* Jclcontainerintf::IJclDoubleBinaryTreeIterator */
	
public:
	operator IJclDoubleBinaryTreeIterator*(void) { return (IJclDoubleBinaryTreeIterator*)&__IJclDoubleBinaryTreeIterator; }
	operator IJclDoubleTreeIterator*(void) { return (IJclDoubleTreeIterator*)&__IJclDoubleBinaryTreeIterator; }
	operator IJclDoubleIterator*(void) { return (IJclDoubleIterator*)&__IJclDoubleBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderDoubleBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderDoubleBinaryTreeIterator : public TJclDoubleBinaryTreeIterator 
{
	typedef TJclDoubleBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclDoubleBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclDoubleBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclDoubleBinaryTreeIterator.Create */ inline __fastcall TJclPreOrderDoubleBinaryTreeIterator(const Jclcontainerintf::_di_IJclDoubleCollection AOwnTree, TJclDoubleBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclDoubleBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderDoubleBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclDoubleBinaryTreeIterator;	/* Jclcontainerintf::IJclDoubleBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleBinaryTreeIterator; }
	operator IJclDoubleBinaryTreeIterator*(void) { return (IJclDoubleBinaryTreeIterator*)&__IJclDoubleBinaryTreeIterator; }
	operator IJclDoubleTreeIterator*(void) { return (IJclDoubleTreeIterator*)&__IJclDoubleBinaryTreeIterator; }
	operator IJclDoubleIterator*(void) { return (IJclDoubleIterator*)&__IJclDoubleBinaryTreeIterator; }
	
};


class DELPHICLASS TJclInOrderDoubleBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclInOrderDoubleBinaryTreeIterator : public TJclDoubleBinaryTreeIterator 
{
	typedef TJclDoubleBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclDoubleBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclDoubleBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclDoubleBinaryTreeIterator.Create */ inline __fastcall TJclInOrderDoubleBinaryTreeIterator(const Jclcontainerintf::_di_IJclDoubleCollection AOwnTree, TJclDoubleBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclDoubleBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclInOrderDoubleBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclDoubleBinaryTreeIterator;	/* Jclcontainerintf::IJclDoubleBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleBinaryTreeIterator; }
	operator IJclDoubleBinaryTreeIterator*(void) { return (IJclDoubleBinaryTreeIterator*)&__IJclDoubleBinaryTreeIterator; }
	operator IJclDoubleTreeIterator*(void) { return (IJclDoubleTreeIterator*)&__IJclDoubleBinaryTreeIterator; }
	operator IJclDoubleIterator*(void) { return (IJclDoubleIterator*)&__IJclDoubleBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderDoubleBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderDoubleBinaryTreeIterator : public TJclDoubleBinaryTreeIterator 
{
	typedef TJclDoubleBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclDoubleBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclDoubleBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclDoubleBinaryTreeIterator.Create */ inline __fastcall TJclPostOrderDoubleBinaryTreeIterator(const Jclcontainerintf::_di_IJclDoubleCollection AOwnTree, TJclDoubleBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclDoubleBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderDoubleBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclDoubleBinaryTreeIterator;	/* Jclcontainerintf::IJclDoubleBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclDoubleBinaryTreeIterator; }
	operator IJclDoubleBinaryTreeIterator*(void) { return (IJclDoubleBinaryTreeIterator*)&__IJclDoubleBinaryTreeIterator; }
	operator IJclDoubleTreeIterator*(void) { return (IJclDoubleTreeIterator*)&__IJclDoubleBinaryTreeIterator; }
	operator IJclDoubleIterator*(void) { return (IJclDoubleIterator*)&__IJclDoubleBinaryTreeIterator; }
	
};


class DELPHICLASS TJclExtendedBinaryNode;
class PASCALIMPLEMENTATION TJclExtendedBinaryNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	Extended Value;
	TJclExtendedBinaryNode* Left;
	TJclExtendedBinaryNode* Right;
	TJclExtendedBinaryNode* Parent;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclExtendedBinaryNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclExtendedBinaryNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclExtendedBinaryTree;
class PASCALIMPLEMENTATION TJclExtendedBinaryTree : public Jclabstractcontainers::TJclExtendedAbstractContainer 
{
	typedef Jclabstractcontainers::TJclExtendedAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int FMaxDepth;
	TJclExtendedBinaryNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	TJclExtendedBinaryNode* __fastcall BuildTree(TJclExtendedBinaryNode* const * LeafArray, const int LeafArray_Size, int Left, int Right, TJclExtendedBinaryNode* Parent, int Offset);
	TJclExtendedBinaryNode* __fastcall CloneNode(TJclExtendedBinaryNode* Node, TJclExtendedBinaryNode* Parent);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AutoPack(void);
	
public:
	__fastcall TJclExtendedBinaryTree(Jclcontainerintf::TExtendedCompare ACompare);
	__fastcall virtual ~TJclExtendedBinaryTree(void);
	virtual void __fastcall Pack(void);
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
	Jclcontainerintf::_di_IJclExtendedTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclExtendedTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclExtendedEqualityComparer;	/* Jclcontainerintf::IJclExtendedEqualityComparer */
	void *__IJclExtendedComparer;	/* Jclcontainerintf::IJclExtendedComparer */
	void *__IJclExtendedTree;	/* Jclcontainerintf::IJclExtendedTree */
	
public:
	operator IJclExtendedTree*(void) { return (IJclExtendedTree*)&__IJclExtendedTree; }
	operator IJclExtendedCollection*(void) { return (IJclExtendedCollection*)&__IJclExtendedTree; }
	operator IJclExtendedComparer*(void) { return (IJclExtendedComparer*)&__IJclExtendedComparer; }
	operator IJclExtendedEqualityComparer*(void) { return (IJclExtendedEqualityComparer*)&__IJclExtendedEqualityComparer; }
	operator IJclExtendedContainer*(void) { return (IJclExtendedContainer*)&__IJclExtendedTree; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclExtendedTree; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedTree; }
	
};


class DELPHICLASS TJclExtendedBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclExtendedBinaryTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclExtendedBinaryNode* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclExtendedCollection FOwnTree;
	Jclcontainerintf::_di_IJclExtendedEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclExtendedBinaryNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclExtendedBinaryNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclExtendedBinaryTreeIterator(const Jclcontainerintf::_di_IJclExtendedCollection AOwnTree, TJclExtendedBinaryNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall HasLeft(void);
	bool __fastcall HasRight(void);
	Extended __fastcall Left(void);
	Extended __fastcall Right(void);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclExtendedBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclExtendedBinaryTreeIterator;	/* Jclcontainerintf::IJclExtendedBinaryTreeIterator */
	
public:
	operator IJclExtendedBinaryTreeIterator*(void) { return (IJclExtendedBinaryTreeIterator*)&__IJclExtendedBinaryTreeIterator; }
	operator IJclExtendedTreeIterator*(void) { return (IJclExtendedTreeIterator*)&__IJclExtendedBinaryTreeIterator; }
	operator IJclExtendedIterator*(void) { return (IJclExtendedIterator*)&__IJclExtendedBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderExtendedBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderExtendedBinaryTreeIterator : public TJclExtendedBinaryTreeIterator 
{
	typedef TJclExtendedBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclExtendedBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclExtendedBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclExtendedBinaryTreeIterator.Create */ inline __fastcall TJclPreOrderExtendedBinaryTreeIterator(const Jclcontainerintf::_di_IJclExtendedCollection AOwnTree, TJclExtendedBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclExtendedBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderExtendedBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclExtendedBinaryTreeIterator;	/* Jclcontainerintf::IJclExtendedBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedBinaryTreeIterator; }
	operator IJclExtendedBinaryTreeIterator*(void) { return (IJclExtendedBinaryTreeIterator*)&__IJclExtendedBinaryTreeIterator; }
	operator IJclExtendedTreeIterator*(void) { return (IJclExtendedTreeIterator*)&__IJclExtendedBinaryTreeIterator; }
	operator IJclExtendedIterator*(void) { return (IJclExtendedIterator*)&__IJclExtendedBinaryTreeIterator; }
	
};


class DELPHICLASS TJclInOrderExtendedBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclInOrderExtendedBinaryTreeIterator : public TJclExtendedBinaryTreeIterator 
{
	typedef TJclExtendedBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclExtendedBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclExtendedBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclExtendedBinaryTreeIterator.Create */ inline __fastcall TJclInOrderExtendedBinaryTreeIterator(const Jclcontainerintf::_di_IJclExtendedCollection AOwnTree, TJclExtendedBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclExtendedBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclInOrderExtendedBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclExtendedBinaryTreeIterator;	/* Jclcontainerintf::IJclExtendedBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedBinaryTreeIterator; }
	operator IJclExtendedBinaryTreeIterator*(void) { return (IJclExtendedBinaryTreeIterator*)&__IJclExtendedBinaryTreeIterator; }
	operator IJclExtendedTreeIterator*(void) { return (IJclExtendedTreeIterator*)&__IJclExtendedBinaryTreeIterator; }
	operator IJclExtendedIterator*(void) { return (IJclExtendedIterator*)&__IJclExtendedBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderExtendedBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderExtendedBinaryTreeIterator : public TJclExtendedBinaryTreeIterator 
{
	typedef TJclExtendedBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclExtendedBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclExtendedBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclExtendedBinaryTreeIterator.Create */ inline __fastcall TJclPostOrderExtendedBinaryTreeIterator(const Jclcontainerintf::_di_IJclExtendedCollection AOwnTree, TJclExtendedBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclExtendedBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderExtendedBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclExtendedBinaryTreeIterator;	/* Jclcontainerintf::IJclExtendedBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclExtendedBinaryTreeIterator; }
	operator IJclExtendedBinaryTreeIterator*(void) { return (IJclExtendedBinaryTreeIterator*)&__IJclExtendedBinaryTreeIterator; }
	operator IJclExtendedTreeIterator*(void) { return (IJclExtendedTreeIterator*)&__IJclExtendedBinaryTreeIterator; }
	operator IJclExtendedIterator*(void) { return (IJclExtendedIterator*)&__IJclExtendedBinaryTreeIterator; }
	
};


typedef TJclExtendedBinaryTree TJclFloatBinaryTree;
;

class DELPHICLASS TJclIntegerBinaryNode;
class PASCALIMPLEMENTATION TJclIntegerBinaryNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	int Value;
	TJclIntegerBinaryNode* Left;
	TJclIntegerBinaryNode* Right;
	TJclIntegerBinaryNode* Parent;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclIntegerBinaryNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclIntegerBinaryNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclIntegerBinaryTree;
class PASCALIMPLEMENTATION TJclIntegerBinaryTree : public Jclabstractcontainers::TJclIntegerAbstractContainer 
{
	typedef Jclabstractcontainers::TJclIntegerAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int FMaxDepth;
	TJclIntegerBinaryNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	TJclIntegerBinaryNode* __fastcall BuildTree(TJclIntegerBinaryNode* const * LeafArray, const int LeafArray_Size, int Left, int Right, TJclIntegerBinaryNode* Parent, int Offset);
	TJclIntegerBinaryNode* __fastcall CloneNode(TJclIntegerBinaryNode* Node, TJclIntegerBinaryNode* Parent);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AutoPack(void);
	
public:
	__fastcall TJclIntegerBinaryTree(Jclcontainerintf::TIntegerCompare ACompare);
	__fastcall virtual ~TJclIntegerBinaryTree(void);
	virtual void __fastcall Pack(void);
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
	Jclcontainerintf::_di_IJclIntegerTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclIntegerTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclIntegerEqualityComparer;	/* Jclcontainerintf::IJclIntegerEqualityComparer */
	void *__IJclIntegerComparer;	/* Jclcontainerintf::IJclIntegerComparer */
	void *__IJclIntegerTree;	/* Jclcontainerintf::IJclIntegerTree */
	
public:
	operator IJclIntegerTree*(void) { return (IJclIntegerTree*)&__IJclIntegerTree; }
	operator IJclIntegerCollection*(void) { return (IJclIntegerCollection*)&__IJclIntegerTree; }
	operator IJclIntegerComparer*(void) { return (IJclIntegerComparer*)&__IJclIntegerComparer; }
	operator IJclIntegerEqualityComparer*(void) { return (IJclIntegerEqualityComparer*)&__IJclIntegerEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclIntegerTree; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerTree; }
	
};


class DELPHICLASS TJclIntegerBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclIntegerBinaryTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclIntegerBinaryNode* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclIntegerCollection FOwnTree;
	Jclcontainerintf::_di_IJclIntegerEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclIntegerBinaryNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclIntegerBinaryNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclIntegerBinaryTreeIterator(const Jclcontainerintf::_di_IJclIntegerCollection AOwnTree, TJclIntegerBinaryNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall HasLeft(void);
	bool __fastcall HasRight(void);
	int __fastcall Left(void);
	int __fastcall Right(void);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclIntegerBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclIntegerBinaryTreeIterator;	/* Jclcontainerintf::IJclIntegerBinaryTreeIterator */
	
public:
	operator IJclIntegerBinaryTreeIterator*(void) { return (IJclIntegerBinaryTreeIterator*)&__IJclIntegerBinaryTreeIterator; }
	operator IJclIntegerTreeIterator*(void) { return (IJclIntegerTreeIterator*)&__IJclIntegerBinaryTreeIterator; }
	operator IJclIntegerIterator*(void) { return (IJclIntegerIterator*)&__IJclIntegerBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderIntegerBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderIntegerBinaryTreeIterator : public TJclIntegerBinaryTreeIterator 
{
	typedef TJclIntegerBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclIntegerBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclIntegerBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclIntegerBinaryTreeIterator.Create */ inline __fastcall TJclPreOrderIntegerBinaryTreeIterator(const Jclcontainerintf::_di_IJclIntegerCollection AOwnTree, TJclIntegerBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclIntegerBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderIntegerBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclIntegerBinaryTreeIterator;	/* Jclcontainerintf::IJclIntegerBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerBinaryTreeIterator; }
	operator IJclIntegerBinaryTreeIterator*(void) { return (IJclIntegerBinaryTreeIterator*)&__IJclIntegerBinaryTreeIterator; }
	operator IJclIntegerTreeIterator*(void) { return (IJclIntegerTreeIterator*)&__IJclIntegerBinaryTreeIterator; }
	operator IJclIntegerIterator*(void) { return (IJclIntegerIterator*)&__IJclIntegerBinaryTreeIterator; }
	
};


class DELPHICLASS TJclInOrderIntegerBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclInOrderIntegerBinaryTreeIterator : public TJclIntegerBinaryTreeIterator 
{
	typedef TJclIntegerBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclIntegerBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclIntegerBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclIntegerBinaryTreeIterator.Create */ inline __fastcall TJclInOrderIntegerBinaryTreeIterator(const Jclcontainerintf::_di_IJclIntegerCollection AOwnTree, TJclIntegerBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclIntegerBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclInOrderIntegerBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclIntegerBinaryTreeIterator;	/* Jclcontainerintf::IJclIntegerBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerBinaryTreeIterator; }
	operator IJclIntegerBinaryTreeIterator*(void) { return (IJclIntegerBinaryTreeIterator*)&__IJclIntegerBinaryTreeIterator; }
	operator IJclIntegerTreeIterator*(void) { return (IJclIntegerTreeIterator*)&__IJclIntegerBinaryTreeIterator; }
	operator IJclIntegerIterator*(void) { return (IJclIntegerIterator*)&__IJclIntegerBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderIntegerBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderIntegerBinaryTreeIterator : public TJclIntegerBinaryTreeIterator 
{
	typedef TJclIntegerBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclIntegerBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclIntegerBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclIntegerBinaryTreeIterator.Create */ inline __fastcall TJclPostOrderIntegerBinaryTreeIterator(const Jclcontainerintf::_di_IJclIntegerCollection AOwnTree, TJclIntegerBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclIntegerBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderIntegerBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclIntegerBinaryTreeIterator;	/* Jclcontainerintf::IJclIntegerBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclIntegerBinaryTreeIterator; }
	operator IJclIntegerBinaryTreeIterator*(void) { return (IJclIntegerBinaryTreeIterator*)&__IJclIntegerBinaryTreeIterator; }
	operator IJclIntegerTreeIterator*(void) { return (IJclIntegerTreeIterator*)&__IJclIntegerBinaryTreeIterator; }
	operator IJclIntegerIterator*(void) { return (IJclIntegerIterator*)&__IJclIntegerBinaryTreeIterator; }
	
};


class DELPHICLASS TJclCardinalBinaryNode;
class PASCALIMPLEMENTATION TJclCardinalBinaryNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	unsigned Value;
	TJclCardinalBinaryNode* Left;
	TJclCardinalBinaryNode* Right;
	TJclCardinalBinaryNode* Parent;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclCardinalBinaryNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclCardinalBinaryNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclCardinalBinaryTree;
class PASCALIMPLEMENTATION TJclCardinalBinaryTree : public Jclabstractcontainers::TJclCardinalAbstractContainer 
{
	typedef Jclabstractcontainers::TJclCardinalAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int FMaxDepth;
	TJclCardinalBinaryNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	TJclCardinalBinaryNode* __fastcall BuildTree(TJclCardinalBinaryNode* const * LeafArray, const int LeafArray_Size, int Left, int Right, TJclCardinalBinaryNode* Parent, int Offset);
	TJclCardinalBinaryNode* __fastcall CloneNode(TJclCardinalBinaryNode* Node, TJclCardinalBinaryNode* Parent);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AutoPack(void);
	
public:
	__fastcall TJclCardinalBinaryTree(Jclcontainerintf::TCardinalCompare ACompare);
	__fastcall virtual ~TJclCardinalBinaryTree(void);
	virtual void __fastcall Pack(void);
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
	Jclcontainerintf::_di_IJclCardinalTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclCardinalTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclCardinalEqualityComparer;	/* Jclcontainerintf::IJclCardinalEqualityComparer */
	void *__IJclCardinalComparer;	/* Jclcontainerintf::IJclCardinalComparer */
	void *__IJclCardinalTree;	/* Jclcontainerintf::IJclCardinalTree */
	
public:
	operator IJclCardinalTree*(void) { return (IJclCardinalTree*)&__IJclCardinalTree; }
	operator IJclCardinalCollection*(void) { return (IJclCardinalCollection*)&__IJclCardinalTree; }
	operator IJclCardinalComparer*(void) { return (IJclCardinalComparer*)&__IJclCardinalComparer; }
	operator IJclCardinalEqualityComparer*(void) { return (IJclCardinalEqualityComparer*)&__IJclCardinalEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclCardinalTree; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalTree; }
	
};


class DELPHICLASS TJclCardinalBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclCardinalBinaryTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclCardinalBinaryNode* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclCardinalCollection FOwnTree;
	Jclcontainerintf::_di_IJclCardinalEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclCardinalBinaryNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclCardinalBinaryNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclCardinalBinaryTreeIterator(const Jclcontainerintf::_di_IJclCardinalCollection AOwnTree, TJclCardinalBinaryNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall HasLeft(void);
	bool __fastcall HasRight(void);
	unsigned __fastcall Left(void);
	unsigned __fastcall Right(void);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclCardinalBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclCardinalBinaryTreeIterator;	/* Jclcontainerintf::IJclCardinalBinaryTreeIterator */
	
public:
	operator IJclCardinalBinaryTreeIterator*(void) { return (IJclCardinalBinaryTreeIterator*)&__IJclCardinalBinaryTreeIterator; }
	operator IJclCardinalTreeIterator*(void) { return (IJclCardinalTreeIterator*)&__IJclCardinalBinaryTreeIterator; }
	operator IJclCardinalIterator*(void) { return (IJclCardinalIterator*)&__IJclCardinalBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderCardinalBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderCardinalBinaryTreeIterator : public TJclCardinalBinaryTreeIterator 
{
	typedef TJclCardinalBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclCardinalBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclCardinalBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclCardinalBinaryTreeIterator.Create */ inline __fastcall TJclPreOrderCardinalBinaryTreeIterator(const Jclcontainerintf::_di_IJclCardinalCollection AOwnTree, TJclCardinalBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclCardinalBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderCardinalBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclCardinalBinaryTreeIterator;	/* Jclcontainerintf::IJclCardinalBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalBinaryTreeIterator; }
	operator IJclCardinalBinaryTreeIterator*(void) { return (IJclCardinalBinaryTreeIterator*)&__IJclCardinalBinaryTreeIterator; }
	operator IJclCardinalTreeIterator*(void) { return (IJclCardinalTreeIterator*)&__IJclCardinalBinaryTreeIterator; }
	operator IJclCardinalIterator*(void) { return (IJclCardinalIterator*)&__IJclCardinalBinaryTreeIterator; }
	
};


class DELPHICLASS TJclInOrderCardinalBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclInOrderCardinalBinaryTreeIterator : public TJclCardinalBinaryTreeIterator 
{
	typedef TJclCardinalBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclCardinalBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclCardinalBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclCardinalBinaryTreeIterator.Create */ inline __fastcall TJclInOrderCardinalBinaryTreeIterator(const Jclcontainerintf::_di_IJclCardinalCollection AOwnTree, TJclCardinalBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclCardinalBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclInOrderCardinalBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclCardinalBinaryTreeIterator;	/* Jclcontainerintf::IJclCardinalBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalBinaryTreeIterator; }
	operator IJclCardinalBinaryTreeIterator*(void) { return (IJclCardinalBinaryTreeIterator*)&__IJclCardinalBinaryTreeIterator; }
	operator IJclCardinalTreeIterator*(void) { return (IJclCardinalTreeIterator*)&__IJclCardinalBinaryTreeIterator; }
	operator IJclCardinalIterator*(void) { return (IJclCardinalIterator*)&__IJclCardinalBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderCardinalBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderCardinalBinaryTreeIterator : public TJclCardinalBinaryTreeIterator 
{
	typedef TJclCardinalBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclCardinalBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclCardinalBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclCardinalBinaryTreeIterator.Create */ inline __fastcall TJclPostOrderCardinalBinaryTreeIterator(const Jclcontainerintf::_di_IJclCardinalCollection AOwnTree, TJclCardinalBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclCardinalBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderCardinalBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclCardinalBinaryTreeIterator;	/* Jclcontainerintf::IJclCardinalBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclCardinalBinaryTreeIterator; }
	operator IJclCardinalBinaryTreeIterator*(void) { return (IJclCardinalBinaryTreeIterator*)&__IJclCardinalBinaryTreeIterator; }
	operator IJclCardinalTreeIterator*(void) { return (IJclCardinalTreeIterator*)&__IJclCardinalBinaryTreeIterator; }
	operator IJclCardinalIterator*(void) { return (IJclCardinalIterator*)&__IJclCardinalBinaryTreeIterator; }
	
};


class DELPHICLASS TJclInt64BinaryNode;
class PASCALIMPLEMENTATION TJclInt64BinaryNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	__int64 Value;
	TJclInt64BinaryNode* Left;
	TJclInt64BinaryNode* Right;
	TJclInt64BinaryNode* Parent;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclInt64BinaryNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclInt64BinaryNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclInt64BinaryTree;
class PASCALIMPLEMENTATION TJclInt64BinaryTree : public Jclabstractcontainers::TJclInt64AbstractContainer 
{
	typedef Jclabstractcontainers::TJclInt64AbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int FMaxDepth;
	TJclInt64BinaryNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	TJclInt64BinaryNode* __fastcall BuildTree(TJclInt64BinaryNode* const * LeafArray, const int LeafArray_Size, int Left, int Right, TJclInt64BinaryNode* Parent, int Offset);
	TJclInt64BinaryNode* __fastcall CloneNode(TJclInt64BinaryNode* Node, TJclInt64BinaryNode* Parent);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AutoPack(void);
	
public:
	__fastcall TJclInt64BinaryTree(Jclcontainerintf::TInt64Compare ACompare);
	__fastcall virtual ~TJclInt64BinaryTree(void);
	virtual void __fastcall Pack(void);
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
	Jclcontainerintf::_di_IJclInt64TreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclInt64TreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclInt64EqualityComparer;	/* Jclcontainerintf::IJclInt64EqualityComparer */
	void *__IJclInt64Comparer;	/* Jclcontainerintf::IJclInt64Comparer */
	void *__IJclInt64Tree;	/* Jclcontainerintf::IJclInt64Tree */
	
public:
	operator IJclInt64Tree*(void) { return (IJclInt64Tree*)&__IJclInt64Tree; }
	operator IJclInt64Collection*(void) { return (IJclInt64Collection*)&__IJclInt64Tree; }
	operator IJclInt64Comparer*(void) { return (IJclInt64Comparer*)&__IJclInt64Comparer; }
	operator IJclInt64EqualityComparer*(void) { return (IJclInt64EqualityComparer*)&__IJclInt64EqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclInt64Tree; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64Tree; }
	
};


class DELPHICLASS TJclInt64BinaryTreeIterator;
class PASCALIMPLEMENTATION TJclInt64BinaryTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclInt64BinaryNode* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclInt64Collection FOwnTree;
	Jclcontainerintf::_di_IJclInt64EqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclInt64BinaryNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclInt64BinaryNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclInt64BinaryTreeIterator(const Jclcontainerintf::_di_IJclInt64Collection AOwnTree, TJclInt64BinaryNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall HasLeft(void);
	bool __fastcall HasRight(void);
	__int64 __fastcall Left(void);
	__int64 __fastcall Right(void);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclInt64BinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclInt64BinaryTreeIterator;	/* Jclcontainerintf::IJclInt64BinaryTreeIterator */
	
public:
	operator IJclInt64BinaryTreeIterator*(void) { return (IJclInt64BinaryTreeIterator*)&__IJclInt64BinaryTreeIterator; }
	operator IJclInt64TreeIterator*(void) { return (IJclInt64TreeIterator*)&__IJclInt64BinaryTreeIterator; }
	operator IJclInt64Iterator*(void) { return (IJclInt64Iterator*)&__IJclInt64BinaryTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderInt64BinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderInt64BinaryTreeIterator : public TJclInt64BinaryTreeIterator 
{
	typedef TJclInt64BinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclInt64BinaryNode* __fastcall GetNextCursor(void);
	virtual TJclInt64BinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclInt64BinaryTreeIterator.Create */ inline __fastcall TJclPreOrderInt64BinaryTreeIterator(const Jclcontainerintf::_di_IJclInt64Collection AOwnTree, TJclInt64BinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclInt64BinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderInt64BinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclInt64BinaryTreeIterator;	/* Jclcontainerintf::IJclInt64BinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64BinaryTreeIterator; }
	operator IJclInt64BinaryTreeIterator*(void) { return (IJclInt64BinaryTreeIterator*)&__IJclInt64BinaryTreeIterator; }
	operator IJclInt64TreeIterator*(void) { return (IJclInt64TreeIterator*)&__IJclInt64BinaryTreeIterator; }
	operator IJclInt64Iterator*(void) { return (IJclInt64Iterator*)&__IJclInt64BinaryTreeIterator; }
	
};


class DELPHICLASS TJclInOrderInt64BinaryTreeIterator;
class PASCALIMPLEMENTATION TJclInOrderInt64BinaryTreeIterator : public TJclInt64BinaryTreeIterator 
{
	typedef TJclInt64BinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclInt64BinaryNode* __fastcall GetNextCursor(void);
	virtual TJclInt64BinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclInt64BinaryTreeIterator.Create */ inline __fastcall TJclInOrderInt64BinaryTreeIterator(const Jclcontainerintf::_di_IJclInt64Collection AOwnTree, TJclInt64BinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclInt64BinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclInOrderInt64BinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclInt64BinaryTreeIterator;	/* Jclcontainerintf::IJclInt64BinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64BinaryTreeIterator; }
	operator IJclInt64BinaryTreeIterator*(void) { return (IJclInt64BinaryTreeIterator*)&__IJclInt64BinaryTreeIterator; }
	operator IJclInt64TreeIterator*(void) { return (IJclInt64TreeIterator*)&__IJclInt64BinaryTreeIterator; }
	operator IJclInt64Iterator*(void) { return (IJclInt64Iterator*)&__IJclInt64BinaryTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderInt64BinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderInt64BinaryTreeIterator : public TJclInt64BinaryTreeIterator 
{
	typedef TJclInt64BinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclInt64BinaryNode* __fastcall GetNextCursor(void);
	virtual TJclInt64BinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclInt64BinaryTreeIterator.Create */ inline __fastcall TJclPostOrderInt64BinaryTreeIterator(const Jclcontainerintf::_di_IJclInt64Collection AOwnTree, TJclInt64BinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclInt64BinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderInt64BinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclInt64BinaryTreeIterator;	/* Jclcontainerintf::IJclInt64BinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclInt64BinaryTreeIterator; }
	operator IJclInt64BinaryTreeIterator*(void) { return (IJclInt64BinaryTreeIterator*)&__IJclInt64BinaryTreeIterator; }
	operator IJclInt64TreeIterator*(void) { return (IJclInt64TreeIterator*)&__IJclInt64BinaryTreeIterator; }
	operator IJclInt64Iterator*(void) { return (IJclInt64Iterator*)&__IJclInt64BinaryTreeIterator; }
	
};


class DELPHICLASS TJclPtrBinaryNode;
class PASCALIMPLEMENTATION TJclPtrBinaryNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	void *Value;
	TJclPtrBinaryNode* Left;
	TJclPtrBinaryNode* Right;
	TJclPtrBinaryNode* Parent;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclPtrBinaryNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclPtrBinaryNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclPtrBinaryTree;
class PASCALIMPLEMENTATION TJclPtrBinaryTree : public Jclabstractcontainers::TJclPtrAbstractContainer 
{
	typedef Jclabstractcontainers::TJclPtrAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int FMaxDepth;
	TJclPtrBinaryNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	TJclPtrBinaryNode* __fastcall BuildTree(TJclPtrBinaryNode* const * LeafArray, const int LeafArray_Size, int Left, int Right, TJclPtrBinaryNode* Parent, int Offset);
	TJclPtrBinaryNode* __fastcall CloneNode(TJclPtrBinaryNode* Node, TJclPtrBinaryNode* Parent);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AutoPack(void);
	
public:
	__fastcall TJclPtrBinaryTree(Jclcontainerintf::TPtrCompare ACompare);
	__fastcall virtual ~TJclPtrBinaryTree(void);
	virtual void __fastcall Pack(void);
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
	Jclcontainerintf::_di_IJclPtrTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclPtrTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclPtrEqualityComparer;	/* Jclcontainerintf::IJclPtrEqualityComparer */
	void *__IJclPtrComparer;	/* Jclcontainerintf::IJclPtrComparer */
	void *__IJclPtrTree;	/* Jclcontainerintf::IJclPtrTree */
	
public:
	operator IJclPtrTree*(void) { return (IJclPtrTree*)&__IJclPtrTree; }
	operator IJclPtrCollection*(void) { return (IJclPtrCollection*)&__IJclPtrTree; }
	operator IJclPtrComparer*(void) { return (IJclPtrComparer*)&__IJclPtrComparer; }
	operator IJclPtrEqualityComparer*(void) { return (IJclPtrEqualityComparer*)&__IJclPtrEqualityComparer; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclPtrTree; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrTree; }
	
};


class DELPHICLASS TJclPtrBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPtrBinaryTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclPtrBinaryNode* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclPtrCollection FOwnTree;
	Jclcontainerintf::_di_IJclPtrEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclPtrBinaryNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclPtrBinaryNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclPtrBinaryTreeIterator(const Jclcontainerintf::_di_IJclPtrCollection AOwnTree, TJclPtrBinaryNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall HasLeft(void);
	bool __fastcall HasRight(void);
	void * __fastcall Left(void);
	void * __fastcall Right(void);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPtrBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclPtrBinaryTreeIterator;	/* Jclcontainerintf::IJclPtrBinaryTreeIterator */
	
public:
	operator IJclPtrBinaryTreeIterator*(void) { return (IJclPtrBinaryTreeIterator*)&__IJclPtrBinaryTreeIterator; }
	operator IJclPtrTreeIterator*(void) { return (IJclPtrTreeIterator*)&__IJclPtrBinaryTreeIterator; }
	operator IJclPtrIterator*(void) { return (IJclPtrIterator*)&__IJclPtrBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderPtrBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderPtrBinaryTreeIterator : public TJclPtrBinaryTreeIterator 
{
	typedef TJclPtrBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclPtrBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclPtrBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclPtrBinaryTreeIterator.Create */ inline __fastcall TJclPreOrderPtrBinaryTreeIterator(const Jclcontainerintf::_di_IJclPtrCollection AOwnTree, TJclPtrBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclPtrBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderPtrBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclPtrBinaryTreeIterator;	/* Jclcontainerintf::IJclPtrBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrBinaryTreeIterator; }
	operator IJclPtrBinaryTreeIterator*(void) { return (IJclPtrBinaryTreeIterator*)&__IJclPtrBinaryTreeIterator; }
	operator IJclPtrTreeIterator*(void) { return (IJclPtrTreeIterator*)&__IJclPtrBinaryTreeIterator; }
	operator IJclPtrIterator*(void) { return (IJclPtrIterator*)&__IJclPtrBinaryTreeIterator; }
	
};


class DELPHICLASS TJclInOrderPtrBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclInOrderPtrBinaryTreeIterator : public TJclPtrBinaryTreeIterator 
{
	typedef TJclPtrBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclPtrBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclPtrBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclPtrBinaryTreeIterator.Create */ inline __fastcall TJclInOrderPtrBinaryTreeIterator(const Jclcontainerintf::_di_IJclPtrCollection AOwnTree, TJclPtrBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclPtrBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclInOrderPtrBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclPtrBinaryTreeIterator;	/* Jclcontainerintf::IJclPtrBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrBinaryTreeIterator; }
	operator IJclPtrBinaryTreeIterator*(void) { return (IJclPtrBinaryTreeIterator*)&__IJclPtrBinaryTreeIterator; }
	operator IJclPtrTreeIterator*(void) { return (IJclPtrTreeIterator*)&__IJclPtrBinaryTreeIterator; }
	operator IJclPtrIterator*(void) { return (IJclPtrIterator*)&__IJclPtrBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderPtrBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderPtrBinaryTreeIterator : public TJclPtrBinaryTreeIterator 
{
	typedef TJclPtrBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclPtrBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclPtrBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclPtrBinaryTreeIterator.Create */ inline __fastcall TJclPostOrderPtrBinaryTreeIterator(const Jclcontainerintf::_di_IJclPtrCollection AOwnTree, TJclPtrBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclPtrBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderPtrBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclPtrBinaryTreeIterator;	/* Jclcontainerintf::IJclPtrBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclPtrBinaryTreeIterator; }
	operator IJclPtrBinaryTreeIterator*(void) { return (IJclPtrBinaryTreeIterator*)&__IJclPtrBinaryTreeIterator; }
	operator IJclPtrTreeIterator*(void) { return (IJclPtrTreeIterator*)&__IJclPtrBinaryTreeIterator; }
	operator IJclPtrIterator*(void) { return (IJclPtrIterator*)&__IJclPtrBinaryTreeIterator; }
	
};


class DELPHICLASS TJclBinaryNode;
class PASCALIMPLEMENTATION TJclBinaryNode : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	System::TObject* Value;
	TJclBinaryNode* Left;
	TJclBinaryNode* Right;
	TJclBinaryNode* Parent;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclBinaryNode(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclBinaryNode(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclBinaryTree;
class PASCALIMPLEMENTATION TJclBinaryTree : public Jclabstractcontainers::TJclAbstractContainer 
{
	typedef Jclabstractcontainers::TJclAbstractContainer inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractContainerBase* __fastcall CreateEmptyContainer(void);
	
private:
	int FMaxDepth;
	TJclBinaryNode* FRoot;
	Jclcontainerintf::TJclTraverseOrder FTraverseOrder;
	TJclBinaryNode* __fastcall BuildTree(TJclBinaryNode* const * LeafArray, const int LeafArray_Size, int Left, int Right, TJclBinaryNode* Parent, int Offset);
	TJclBinaryNode* __fastcall CloneNode(TJclBinaryNode* Node, TJclBinaryNode* Parent);
	
protected:
	virtual void __fastcall AssignDataTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractContainerBase* Dest);
	virtual void __fastcall AutoPack(void);
	
public:
	__fastcall TJclBinaryTree(Jclcontainerintf::TCompare ACompare, bool AOwnsObjects);
	__fastcall virtual ~TJclBinaryTree(void);
	virtual void __fastcall Pack(void);
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
	Jclcontainerintf::_di_IJclTreeIterator __fastcall GetRoot();
	Jclcontainerintf::TJclTraverseOrder __fastcall GetTraverseOrder(void);
	void __fastcall SetTraverseOrder(Jclcontainerintf::TJclTraverseOrder Value);
	__property Jclcontainerintf::_di_IJclTreeIterator Root = {read=GetRoot};
	__property Jclcontainerintf::TJclTraverseOrder TraverseOrder = {read=GetTraverseOrder, write=SetTraverseOrder, nodefault};
private:
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	void *__IJclPackable;	/* Jclcontainerintf::IJclPackable */
	void *__IJclObjectOwner;	/* Jclcontainerintf::IJclObjectOwner */
	void *__IJclEqualityComparer;	/* Jclcontainerintf::IJclEqualityComparer */
	void *__IJclComparer;	/* Jclcontainerintf::IJclComparer */
	void *__IJclTree;	/* Jclcontainerintf::IJclTree */
	
public:
	operator IJclTree*(void) { return (IJclTree*)&__IJclTree; }
	operator IJclCollection*(void) { return (IJclCollection*)&__IJclTree; }
	operator IJclComparer*(void) { return (IJclComparer*)&__IJclComparer; }
	operator IJclEqualityComparer*(void) { return (IJclEqualityComparer*)&__IJclEqualityComparer; }
	operator IJclObjectOwner*(void) { return (IJclObjectOwner*)&__IJclObjectOwner; }
	operator IJclContainer*(void) { return (IJclContainer*)&__IJclTree; }
	operator IJclPackable*(void) { return (IJclPackable*)&__IJclPackable; }
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclTree; }
	
};


class DELPHICLASS TJclBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclBinaryTreeIterator : public Jclabstractcontainers::TJclAbstractIterator 
{
	typedef Jclabstractcontainers::TJclAbstractIterator inherited;
	
protected:
	TJclBinaryNode* FCursor;
	TItrStart FStart;
	Jclcontainerintf::_di_IJclCollection FOwnTree;
	Jclcontainerintf::_di_IJclEqualityComparer FEqualityComparer;
	virtual void __fastcall AssignPropertiesTo(Jclabstractcontainers::TJclAbstractIterator* Dest);
	virtual TJclBinaryNode* __fastcall GetNextCursor(void) = 0 ;
	virtual TJclBinaryNode* __fastcall GetPreviousCursor(void) = 0 ;
	
public:
	__fastcall TJclBinaryTreeIterator(const Jclcontainerintf::_di_IJclCollection AOwnTree, TJclBinaryNode* ACursor, bool AValid, TItrStart AStart);
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
	bool __fastcall HasLeft(void);
	bool __fastcall HasRight(void);
	System::TObject* __fastcall Left(void);
	System::TObject* __fastcall Right(void);
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclBinaryTreeIterator;	/* Jclcontainerintf::IJclBinaryTreeIterator */
	
public:
	operator IJclBinaryTreeIterator*(void) { return (IJclBinaryTreeIterator*)&__IJclBinaryTreeIterator; }
	operator IJclTreeIterator*(void) { return (IJclTreeIterator*)&__IJclBinaryTreeIterator; }
	operator IJclIterator*(void) { return (IJclIterator*)&__IJclBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPreOrderBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPreOrderBinaryTreeIterator : public TJclBinaryTreeIterator 
{
	typedef TJclBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclBinaryTreeIterator.Create */ inline __fastcall TJclPreOrderBinaryTreeIterator(const Jclcontainerintf::_di_IJclCollection AOwnTree, TJclBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPreOrderBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclBinaryTreeIterator;	/* Jclcontainerintf::IJclBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclBinaryTreeIterator; }
	operator IJclBinaryTreeIterator*(void) { return (IJclBinaryTreeIterator*)&__IJclBinaryTreeIterator; }
	operator IJclTreeIterator*(void) { return (IJclTreeIterator*)&__IJclBinaryTreeIterator; }
	operator IJclIterator*(void) { return (IJclIterator*)&__IJclBinaryTreeIterator; }
	
};


class DELPHICLASS TJclInOrderBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclInOrderBinaryTreeIterator : public TJclBinaryTreeIterator 
{
	typedef TJclBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclBinaryTreeIterator.Create */ inline __fastcall TJclInOrderBinaryTreeIterator(const Jclcontainerintf::_di_IJclCollection AOwnTree, TJclBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclInOrderBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclBinaryTreeIterator;	/* Jclcontainerintf::IJclBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclBinaryTreeIterator; }
	operator IJclBinaryTreeIterator*(void) { return (IJclBinaryTreeIterator*)&__IJclBinaryTreeIterator; }
	operator IJclTreeIterator*(void) { return (IJclTreeIterator*)&__IJclBinaryTreeIterator; }
	operator IJclIterator*(void) { return (IJclIterator*)&__IJclBinaryTreeIterator; }
	
};


class DELPHICLASS TJclPostOrderBinaryTreeIterator;
class PASCALIMPLEMENTATION TJclPostOrderBinaryTreeIterator : public TJclBinaryTreeIterator 
{
	typedef TJclBinaryTreeIterator inherited;
	
protected:
	virtual Jclabstractcontainers::TJclAbstractIterator* __fastcall CreateEmptyIterator(void);
	virtual TJclBinaryNode* __fastcall GetNextCursor(void);
	virtual TJclBinaryNode* __fastcall GetPreviousCursor(void);
public:
	#pragma option push -w-inl
	/* TJclBinaryTreeIterator.Create */ inline __fastcall TJclPostOrderBinaryTreeIterator(const Jclcontainerintf::_di_IJclCollection AOwnTree, TJclBinaryNode* ACursor, bool AValid, TItrStart AStart) : TJclBinaryTreeIterator(AOwnTree, ACursor, AValid, AStart) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclAbstractLockable.Destroy */ inline __fastcall virtual ~TJclPostOrderBinaryTreeIterator(void) { }
	#pragma option pop
	
private:
	void *__IJclBinaryTreeIterator;	/* Jclcontainerintf::IJclBinaryTreeIterator */
	void *__IJclIntfCloneable;	/* Jclcontainerintf::IJclIntfCloneable */
	void *__IJclCloneable;	/* Jclcontainerintf::IJclCloneable */
	
public:
	operator IJclCloneable*(void) { return (IJclCloneable*)&__IJclCloneable; }
	operator IJclIntfCloneable*(void) { return (IJclIntfCloneable*)&__IJclIntfCloneable; }
	operator IJclLockable*(void) { return (IJclLockable*)&__IJclBinaryTreeIterator; }
	operator IJclBinaryTreeIterator*(void) { return (IJclBinaryTreeIterator*)&__IJclBinaryTreeIterator; }
	operator IJclTreeIterator*(void) { return (IJclTreeIterator*)&__IJclBinaryTreeIterator; }
	operator IJclIterator*(void) { return (IJclIterator*)&__IJclBinaryTreeIterator; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jclbinarytrees */
using namespace Jclbinarytrees;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclbinarytrees
