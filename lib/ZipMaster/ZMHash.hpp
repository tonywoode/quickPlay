// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Zmhash.pas' rev: 10.00

#ifndef ZmhashHPP
#define ZmhashHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Zipmstr.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Zmhash
{
//-- type declarations -------------------------------------------------------
struct THashedDirEntry;
typedef THashedDirEntry *PHashedDirEntry;

#pragma pack(push,1)
struct THashedDirEntry
{
	
public:
	THashedDirEntry *Next;
	Zipmstr::ZipDirEntry *ZRec;
	unsigned Hash;
} ;
#pragma pack(pop)

struct THDEBlock;
typedef THDEBlock *PHDEBlock;

#pragma pack(push,1)
struct THDEBlock
{
	
public:
	THashedDirEntry Entries[511];
	THDEBlock *Next;
} ;
#pragma pack(pop)

typedef DynamicArray<PHashedDirEntry >  ZMHash__2;

class DELPHICLASS TZipDirHashList;
#pragma pack(push,1)
class PASCALIMPLEMENTATION TZipDirHashList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	THDEBlock *fLastBlock;
	unsigned fNextEntry;
	unsigned __fastcall GetSize(void);
	void __fastcall SetSize(const unsigned Value);
	
protected:
	int fBlocks;
	DynamicArray<PHashedDirEntry >  Chains;
	PHashedDirEntry __fastcall GetEntry(void);
	bool __fastcall Same(PHashedDirEntry Entry, unsigned Hash, const AnsiString Str);
	
public:
	Zipmstr::pZipDirEntry __fastcall Add(const Zipmstr::pZipDirEntry Rec);
	virtual void __fastcall AfterConstruction(void);
	void __fastcall AutoSize(unsigned Req);
	virtual void __fastcall BeforeDestruction(void);
	void __fastcall Clear(void);
	Zipmstr::pZipDirEntry __fastcall Find(const AnsiString FileName);
	__property unsigned Size = {read=GetSize, write=SetSize, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TZipDirHashList(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TZipDirHashList(void) { }
	#pragma option pop
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const Word HDEBlockEntries = 0x1ff;

}	/* namespace Zmhash */
using namespace Zmhash;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Zmhash
