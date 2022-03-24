// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclstrhashmap.pas' rev: 10.00

#ifndef JclstrhashmapHPP
#define JclstrhashmapHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclresources.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclstrhashmap
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EJclStringHashMapError;
class PASCALIMPLEMENTATION EJclStringHashMapError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclStringHashMapError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclStringHashMapError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclStringHashMapError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclStringHashMapError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclStringHashMapError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclStringHashMapError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclStringHashMapError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclStringHashMapError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclStringHashMapError(void) { }
	#pragma option pop
	
};


typedef unsigned THashValue;

class DELPHICLASS TStringHashMapTraits;
class PASCALIMPLEMENTATION TStringHashMapTraits : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual unsigned __fastcall Hash(const AnsiString S) = 0 ;
	virtual int __fastcall Compare(const AnsiString L, const AnsiString R) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TStringHashMapTraits(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TStringHashMapTraits(void) { }
	#pragma option pop
	
};


typedef void *PUserData;

typedef void *PData;

typedef bool __fastcall (*TIterateFunc)(void * AUserData, const AnsiString AStr, void * &APtr);

typedef bool __fastcall (__closure *TIterateMethod)(void * AUserData, const AnsiString AStr, void * &APtr);

struct THashNode;
typedef THashNode *PHashNode;

typedef PHashNode *PPHashNode;

struct THashNode
{
	
public:
	AnsiString Str;
	void *Ptr;
	THashNode *Left;
	THashNode *Right;
} ;

typedef void __fastcall (*TNodeIterateFunc)(void * AUserData, PPHashNode ANode);

typedef THashNode *THashArray[536870911];

typedef PHashNode *PHashArray;

class DELPHICLASS TStringHashMap;
class PASCALIMPLEMENTATION TStringHashMap : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	void * operator[](AnsiString S) { return Data[S]; }
	
private:
	unsigned FHashSize;
	unsigned FCount;
	PHashNode *FList;
	bool FLeftDelete;
	TStringHashMapTraits* FTraits;
	bool __fastcall IterateNode(PHashNode ANode, void * AUserData, TIterateFunc AIterateFunc);
	bool __fastcall IterateMethodNode(PHashNode ANode, void * AUserData, TIterateMethod AIterateMethod);
	void __fastcall NodeIterate(PPHashNode ANode, void * AUserData, TNodeIterateFunc AIterateFunc);
	void __fastcall SetHashSize(unsigned AHashSize);
	void __fastcall DeleteNodes(PHashNode &Q);
	void __fastcall DeleteNode(PHashNode &Q);
	
protected:
	PPHashNode __fastcall FindNode(const AnsiString S);
	virtual PHashNode __fastcall AllocNode(void);
	virtual void __fastcall FreeNode(PHashNode ANode);
	void * __fastcall GetData(const AnsiString S);
	void __fastcall SetData(const AnsiString S, void * P);
	
public:
	__fastcall TStringHashMap(TStringHashMapTraits* ATraits, unsigned AHashSize);
	__fastcall virtual ~TStringHashMap(void);
	void __fastcall Add(const AnsiString S, const void *P);
	void * __fastcall Remove(const AnsiString S);
	void __fastcall RemoveData(const void *P);
	void __fastcall Iterate(void * AUserData, TIterateFunc AIterateFunc);
	void __fastcall IterateMethod(void * AUserData, TIterateMethod AIterateMethod);
	bool __fastcall Has(const AnsiString S);
	bool __fastcall Find(const AnsiString S, void *P);
	bool __fastcall FindData(const void *P, AnsiString &S);
	void __fastcall Clear(void);
	__property unsigned Count = {read=FCount, nodefault};
	__property void * Data[AnsiString S] = {read=GetData, write=SetData/*, default*/};
	__property TStringHashMapTraits* Traits = {read=FTraits};
	__property unsigned HashSize = {read=FHashSize, write=SetHashSize, nodefault};
};


class DELPHICLASS TCaseSensitiveTraits;
class PASCALIMPLEMENTATION TCaseSensitiveTraits : public TStringHashMapTraits 
{
	typedef TStringHashMapTraits inherited;
	
public:
	virtual unsigned __fastcall Hash(const AnsiString S);
	virtual int __fastcall Compare(const AnsiString L, const AnsiString R);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TCaseSensitiveTraits(void) : TStringHashMapTraits() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TCaseSensitiveTraits(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCaseInsensitiveTraits;
class PASCALIMPLEMENTATION TCaseInsensitiveTraits : public TStringHashMapTraits 
{
	typedef TStringHashMapTraits inherited;
	
public:
	virtual unsigned __fastcall Hash(const AnsiString S);
	virtual int __fastcall Compare(const AnsiString L, const AnsiString R);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TCaseInsensitiveTraits(void) : TStringHashMapTraits() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TCaseInsensitiveTraits(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE TStringHashMapTraits* __fastcall CaseSensitiveTraits(void);
extern PACKAGE TStringHashMapTraits* __fastcall CaseInsensitiveTraits(void);
extern PACKAGE bool __fastcall Iterate_FreeObjects(void * AUserData, const AnsiString AStr, void * &AData);
extern PACKAGE bool __fastcall Iterate_Dispose(void * AUserData, const AnsiString AStr, void * &AData);
extern PACKAGE bool __fastcall Iterate_FreeMem(void * AUserData, const AnsiString AStr, void * &AData);
extern PACKAGE unsigned __fastcall StrHash(const AnsiString S);
extern PACKAGE unsigned __fastcall TextHash(const AnsiString S);
extern PACKAGE unsigned __fastcall DataHash(void *AValue, unsigned ASize);

}	/* namespace Jclstrhashmap */
using namespace Jclstrhashmap;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclstrhashmap
