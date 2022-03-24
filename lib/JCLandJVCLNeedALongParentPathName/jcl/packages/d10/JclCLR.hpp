// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclclr.pas' rev: 10.00

#ifndef JclclrHPP
#define JclclrHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclfileutils.hpp>	// Pascal unit
#include <Jclstrings.hpp>	// Pascal unit
#include <Jclpeimage.hpp>	// Pascal unit
#include <Jclsysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclclr
{
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct _IMAGE_COR_VTABLEFIXUP
{
	
public:
	unsigned RVA;
	Word Count;
	Word Kind;
} ;
#pragma pack(pop)

typedef _IMAGE_COR_VTABLEFIXUP  IMAGE_COR_VTABLEFIXUP;

typedef _IMAGE_COR_VTABLEFIXUP  TImageCorVTableFixup;

typedef _IMAGE_COR_VTABLEFIXUP *PImageCorVTableFixup;

typedef _IMAGE_COR_VTABLEFIXUP TImageCorVTableFixupArray[65535];

typedef _IMAGE_COR_VTABLEFIXUP *PImageCorVTableFixupArray;

struct TClrStreamHeader;
typedef TClrStreamHeader *PClrStreamHeader;

#pragma pack(push,1)
struct TClrStreamHeader
{
	
public:
	unsigned Offset;
	unsigned Size;
	char Name[65536];
} ;
#pragma pack(pop)

struct TClrTableStreamHeader;
typedef TClrTableStreamHeader *PClrTableStreamHeader;

#pragma pack(push,1)
struct TClrTableStreamHeader
{
	
public:
	unsigned Reserved;
	Byte MajorVersion;
	Byte MinorVersion;
	Byte HeapSizes;
	Byte Reserved2;
	__int64 Valid;
	__int64 Sorted;
	unsigned Rows[65536];
} ;
#pragma pack(pop)

struct TClrMetadataHeader;
typedef TClrMetadataHeader *PClrMetadataHeader;

#pragma pack(push,1)
struct TClrMetadataHeader
{
	
public:
	unsigned Signature;
	Word MajorVersion;
	Word MinorVersion;
	unsigned Reserved;
	unsigned Length;
	char Version[1];
} ;
#pragma pack(pop)

#pragma option push -b-
enum TJclClrTableKind { ttModule, ttTypeRef, ttTypeDef, ttFieldPtr, ttFieldDef, ttMethodPtr, ttMethodDef, ttParamPtr, ttParamDef, ttInterfaceImpl, ttMemberRef, ttConstant, ttCustomAttribute, ttFieldMarshal, ttDeclSecurity, ttClassLayout, ttFieldLayout, ttSignature, ttEventMap, ttEventPtr, ttEventDef, ttPropertyMap, ttPropertyPtr, ttPropertyDef, ttMethodSemantics, ttMethodImpl, ttModuleRef, ttTypeSpec, ttImplMap, ttFieldRVA, ttENCLog, ttENCMap, ttAssembly, ttAssemblyProcessor, ttAssemblyOS, ttAssemblyRef, ttAssemblyRefProcessor, ttAssemblyRefOS, ttFile, ttExportedType, ttManifestResource, ttNestedClass, ttTypeTyPar, ttMethodTyPar };
#pragma option pop

typedef unsigned TJclClrToken;

typedef unsigned *PJclClrToken;

class DELPHICLASS TJclClrStream;
class DELPHICLASS TJclPeMetadata;
class DELPHICLASS TJclClrStringsStream;
class PASCALIMPLEMENTATION TJclClrStream : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TJclPeMetadata* FMetadata;
	TClrStreamHeader *FHeader;
	AnsiString __fastcall GetName();
	unsigned __fastcall GetOffset(void);
	unsigned __fastcall GetSize(void);
	void * __fastcall GetData(void);
	
public:
	__fastcall virtual TJclClrStream(const TJclPeMetadata* AMetadata, PClrStreamHeader AHeader);
	__property TJclPeMetadata* Metadata = {read=FMetadata};
	__property PClrStreamHeader Header = {read=FHeader};
	__property AnsiString Name = {read=GetName};
	__property unsigned Offset = {read=GetOffset, nodefault};
	__property unsigned Size = {read=GetSize, nodefault};
	__property void * Data = {read=GetData};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrStream(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TJclClrStringsStream : public TJclClrStream 
{
	typedef TJclClrStream inherited;
	
public:
	WideString operator[](int Idx) { return Strings[Idx]; }
	
private:
	Classes::TStringList* FStrings;
	WideString __fastcall GetString(const int Idx);
	HIDESBASE unsigned __fastcall GetOffset(const int Idx);
	int __fastcall GetStringCount(void);
	
public:
	__fastcall virtual TJclClrStringsStream(const TJclPeMetadata* AMetadata, PClrStreamHeader AHeader);
	__fastcall virtual ~TJclClrStringsStream(void);
	WideString __fastcall At(const unsigned Offset);
	__property WideString Strings[int Idx] = {read=GetString/*, default*/};
	__property unsigned Offsets[int Idx] = {read=GetOffset};
	__property int StringCount = {read=GetStringCount, nodefault};
};


class DELPHICLASS TJclClrGuidStream;
class PASCALIMPLEMENTATION TJclClrGuidStream : public TJclClrStream 
{
	typedef TJclClrStream inherited;
	
public:
	GUID operator[](int Idx) { return Guids[Idx]; }
	
private:
	DynamicArray<GUID >  FGuids;
	GUID __fastcall GetGuid(const int Idx);
	int __fastcall GetGuidCount(void);
	
public:
	__fastcall virtual TJclClrGuidStream(const TJclPeMetadata* AMetadata, PClrStreamHeader AHeader);
	__property GUID Guids[int Idx] = {read=GetGuid/*, default*/};
	__property int GuidCount = {read=GetGuidCount, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrGuidStream(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrBlobStream;
class DELPHICLASS TJclClrBlobRecord;
class PASCALIMPLEMENTATION TJclClrBlobStream : public TJclClrStream 
{
	typedef TJclClrStream inherited;
	
public:
	TJclClrBlobRecord* operator[](int Idx) { return Blobs[Idx]; }
	
private:
	Contnrs::TObjectList* FBlobs;
	TJclClrBlobRecord* __fastcall GetBlob(const int Idx);
	int __fastcall GetBlobCount(void);
	
public:
	__fastcall virtual TJclClrBlobStream(const TJclPeMetadata* AMetadata, PClrStreamHeader AHeader);
	__fastcall virtual ~TJclClrBlobStream(void);
	TJclClrBlobRecord* __fastcall At(const unsigned Offset);
	__property TJclClrBlobRecord* Blobs[int Idx] = {read=GetBlob/*, default*/};
	__property int BlobCount = {read=GetBlobCount, nodefault};
};


class DELPHICLASS TJclClrUserStringStream;
class PASCALIMPLEMENTATION TJclClrUserStringStream : public TJclClrBlobStream 
{
	typedef TJclClrBlobStream inherited;
	
public:
	WideString operator[](int Idx) { return Strings[Idx]; }
	
private:
	WideString __fastcall BlobToString(const TJclClrBlobRecord* ABlob);
	WideString __fastcall GetString(const int Idx);
	HIDESBASE unsigned __fastcall GetOffset(const int Idx);
	int __fastcall GetStringCount(void);
	
public:
	HIDESBASE WideString __fastcall At(const unsigned Offset);
	__property WideString Strings[int Idx] = {read=GetString/*, default*/};
	__property unsigned Offsets[int Idx] = {read=GetOffset};
	__property int StringCount = {read=GetStringCount, nodefault};
public:
	#pragma option push -w-inl
	/* TJclClrBlobStream.Create */ inline __fastcall virtual TJclClrUserStringStream(const TJclPeMetadata* AMetadata, PClrStreamHeader AHeader) : TJclClrBlobStream(AMetadata, AHeader) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrBlobStream.Destroy */ inline __fastcall virtual ~TJclClrUserStringStream(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableStream;
class DELPHICLASS TJclClrTable;
#pragma option push -b-
enum TJclClrHeapKind { hkString, hkGuid, hkBlob };
#pragma option pop

class PASCALIMPLEMENTATION TJclClrTableStream : public TJclClrStream 
{
	typedef TJclClrStream inherited;
	
private:
	TClrTableStreamHeader *FHeader;
	TJclClrTable* FTables[44];
	int FTableCount;
	AnsiString __fastcall GetVersionString();
	TJclClrTable* __fastcall GetTable(const TJclClrTableKind AKind);
	bool __fastcall GetBigHeap(const TJclClrHeapKind AHeapKind);
	
public:
	__fastcall virtual TJclClrTableStream(const TJclPeMetadata* AMetadata, PClrStreamHeader AHeader);
	__fastcall virtual ~TJclClrTableStream(void);
	virtual void __fastcall Update(void);
	AnsiString __fastcall DumpIL();
	bool __fastcall FindTable(const TJclClrTableKind AKind, /* out */ TJclClrTable* &ATable);
	__property PClrTableStreamHeader Header = {read=FHeader};
	__property AnsiString VersionString = {read=GetVersionString};
	__property bool BigHeap[TJclClrHeapKind AHeapKind] = {read=GetBigHeap};
	__property TJclClrTable* Tables[TJclClrTableKind AKind] = {read=GetTable};
	__property int TableCount = {read=FTableCount, nodefault};
};


class DELPHICLASS TJclClrTableRow;
typedef TMetaClass* TJclClrStreamClass;

class PASCALIMPLEMENTATION TJclPeMetadata : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TJclClrStream* operator[](int Idx) { return Streams[Idx]; }
	
private:
	Jclpeimage::TJclPeImage* FImage;
	TClrMetadataHeader *FHeader;
	Contnrs::TObjectList* FStreams;
	TJclClrStringsStream* FStringStream;
	TJclClrGuidStream* FGuidStream;
	TJclClrBlobStream* FBlobStream;
	TJclClrUserStringStream* FUserStringStream;
	TJclClrTableStream* FTableStream;
	TJclClrStream* __fastcall GetStream(const int Idx);
	int __fastcall GetStreamCount(void);
	WideString __fastcall GetString(const int Idx);
	int __fastcall GetStringCount(void);
	GUID __fastcall GetGuid(const int Idx);
	int __fastcall GetGuidCount(void);
	TJclClrBlobRecord* __fastcall GetBlob(const int Idx);
	int __fastcall GetBlobCount(void);
	TJclClrTable* __fastcall GetTable(const TJclClrTableKind AKind);
	int __fastcall GetTableCount(void);
	TJclClrTableRow* __fastcall GetToken(const unsigned AToken);
	AnsiString __fastcall GetVersion();
	WideString __fastcall GetVersionString();
	Word __fastcall GetFlags(void);
	WideString __fastcall UserGetString(const int Idx);
	int __fastcall UserGetStringCount(void);
	
public:
	__fastcall TJclPeMetadata(const Jclpeimage::TJclPeImage* AImage);
	__fastcall virtual ~TJclPeMetadata(void);
	AnsiString __fastcall DumpIL();
	bool __fastcall FindStream(const AnsiString AName, /* out */ TJclClrStream* &Stream)/* overload */;
	bool __fastcall FindStream(const TMetaClass* AClass, /* out */ TJclClrStream* &Stream)/* overload */;
	WideString __fastcall StringAt(const unsigned Offset);
	WideString __fastcall UserStringAt(const unsigned Offset);
	TJclClrBlobRecord* __fastcall BlobAt(const unsigned Offset);
	bool __fastcall TokenExists(const unsigned Token);
	/*         class method */ static TJclClrTableKind __fastcall TokenTable(TMetaClass* vmt, const unsigned Token);
	/*         class method */ static int __fastcall TokenIndex(TMetaClass* vmt, const unsigned Token);
	/*         class method */ static int __fastcall TokenCode(TMetaClass* vmt, const unsigned Token);
	/*         class method */ static unsigned __fastcall MakeToken(TMetaClass* vmt, const TJclClrTableKind Table, const int Idx);
	__property Jclpeimage::TJclPeImage* Image = {read=FImage};
	__property PClrMetadataHeader Header = {read=FHeader};
	__property AnsiString Version = {read=GetVersion};
	__property WideString VersionString = {read=GetVersionString};
	__property Word Flags = {read=GetFlags, nodefault};
	__property TJclClrStream* Streams[int Idx] = {read=GetStream/*, default*/};
	__property int StreamCount = {read=GetStreamCount, nodefault};
	__property WideString Strings[int Idx] = {read=GetString};
	__property int StringCount = {read=GetStringCount, nodefault};
	__property WideString UserStrings[int Idx] = {read=UserGetString};
	__property int UserStringCount = {read=UserGetStringCount, nodefault};
	__property GUID Guids[int Idx] = {read=GetGuid};
	__property int GuidCount = {read=GetGuidCount, nodefault};
	__property TJclClrBlobRecord* Blobs[int Idx] = {read=GetBlob};
	__property int BlobCount = {read=GetBlobCount, nodefault};
	__property TJclClrTable* Tables[TJclClrTableKind AKind] = {read=GetTable};
	__property int TableCount = {read=GetTableCount, nodefault};
	__property TJclClrTableRow* Tokens[unsigned AToken] = {read=GetToken};
};



typedef DynamicArray<GUID >  JclCLR__4;

class PASCALIMPLEMENTATION TJclClrBlobRecord : public Jclsysutils::TJclReferenceMemoryStream 
{
	typedef Jclsysutils::TJclReferenceMemoryStream inherited;
	
private:
	Byte *FPtr;
	unsigned FOffset;
	Jclbase::PJclByteArray __fastcall GetData(void);
	
public:
	__fastcall TJclClrBlobRecord(const TJclClrStream* AStream, Jclbase::PJclByteArray APtr);
	AnsiString __fastcall Dump(AnsiString Indent);
	__property Jclbase::PJclByteArray Ptr = {read=FPtr};
	__property unsigned Offset = {read=FOffset, nodefault};
	__property Jclbase::PJclByteArray Data = {read=GetData};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrBlobRecord(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TJclClrComboIndex { ciResolutionScope };
#pragma option pop

__interface ITableCanDumpIL;
typedef System::DelphiInterface<ITableCanDumpIL> _di_ITableCanDumpIL;
__interface  INTERFACE_UUID("{C7AC787B-5DCD-411A-8674-D424A61B76D1}") ITableCanDumpIL  : public IInterface 
{
	
};

class PASCALIMPLEMENTATION TJclClrTableRow : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TJclClrTable* FTable;
	int FIndex;
	unsigned __fastcall GetToken(void);
	
protected:
	virtual void __fastcall Update(void);
	TJclClrTableRow* __fastcall DecodeTypeDefOrRef(const unsigned Encoded);
	TJclClrTableRow* __fastcall DecodeResolutionScope(const unsigned Encoded);
	
public:
	__fastcall virtual TJclClrTableRow(const TJclClrTable* ATable);
	virtual AnsiString __fastcall DumpIL();
	__property TJclClrTable* Table = {read=FTable};
	__property int Index = {read=FIndex, nodefault};
	__property unsigned Token = {read=GetToken, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableRow(void) { }
	#pragma option pop
	
};


typedef TMetaClass* TJclClrTableRowClass;

class PASCALIMPLEMENTATION TJclClrTable : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	TJclClrTableRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	TJclClrTableStream* FStream;
	char *FData;
	char *FPtr;
	Contnrs::TObjectList* FRows;
	int FRowCount;
	unsigned FSize;
	unsigned __fastcall GetOffset(void);
	
protected:
	virtual void __fastcall Load(void);
	void __fastcall SetSize(const int Value);
	virtual void __fastcall Update(void);
	virtual AnsiString __fastcall DumpIL();
	TJclClrTableRow* __fastcall GetRow(const int Idx);
	int __fastcall GetRowCount(void);
	int __fastcall AddRow(const TJclClrTableRow* ARow);
	int __fastcall RealRowCount(void);
	void __fastcall Reset(void);
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTable)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__fastcall virtual TJclClrTable(const TJclClrTableStream* AStream, const void * Ptr, const int ARowCount);
	__fastcall virtual ~TJclClrTable(void);
	unsigned __fastcall ReadCompressedValue(void);
	Byte __fastcall ReadByte(void);
	Word __fastcall ReadWord(void);
	unsigned __fastcall ReadDWord(void);
	unsigned __fastcall ReadIndex(const TJclClrHeapKind HeapKind)/* overload */;
	unsigned __fastcall ReadIndex(TJclClrTableKind const * TableKinds, const int TableKinds_Size)/* overload */;
	bool __fastcall IsWideIndex(const TJclClrHeapKind HeapKind)/* overload */;
	bool __fastcall IsWideIndex(TJclClrTableKind const * TableKinds, const int TableKinds_Size)/* overload */;
	unsigned __fastcall GetCodedIndexTag(const unsigned CodedIndex, const unsigned TagWidth, const bool WideIndex);
	unsigned __fastcall GetCodedIndexValue(const unsigned CodedIndex, const unsigned TagWidth, const bool WideIndex);
	__property TJclClrTableStream* Stream = {read=FStream};
	__property char * Data = {read=FData};
	__property unsigned Size = {read=FSize, nodefault};
	__property unsigned Offset = {read=GetOffset, nodefault};
	__property TJclClrTableRow* Rows[int Idx] = {read=GetRow/*, default*/};
	__property int RowCount = {read=GetRowCount, nodefault};
};


typedef TMetaClass* TJclClrTableClass;

class DELPHICLASS TJclClrResourceRecord;
class PASCALIMPLEMENTATION TJclClrResourceRecord : public Jclsysutils::TJclReferenceMemoryStream 
{
	typedef Jclsysutils::TJclReferenceMemoryStream inherited;
	
private:
	void *FData;
	unsigned FOffset;
	unsigned FRVA;
	
public:
	__fastcall TJclClrResourceRecord(const char * AData, const unsigned AOffset, const unsigned ARVA);
	__property void * Data = {read=FData};
	__property unsigned Offset = {read=FOffset, nodefault};
	__property unsigned RVA = {read=FRVA, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrResourceRecord(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TJclClrVTableKind { vtk32Bit, vtk64Bit, vtkFromUnmanaged, vtkCallMostDerived };
#pragma option pop

typedef Set<TJclClrVTableKind, vtk32Bit, vtkCallMostDerived>  TJclClrVTableKinds;

class DELPHICLASS TJclClrVTableFixupRecord;
class PASCALIMPLEMENTATION TJclClrVTableFixupRecord : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	_IMAGE_COR_VTABLEFIXUP *FData;
	unsigned __fastcall GetCount(void);
	TJclClrVTableKinds __fastcall GetKinds(void);
	unsigned __fastcall GetRVA(void);
	
protected:
	/*         class method */ static unsigned __fastcall VTableKinds(TMetaClass* vmt, const TJclClrVTableKinds Kinds)/* overload */;
	/*         class method */ static TJclClrVTableKinds __fastcall VTableKinds(TMetaClass* vmt, const unsigned Kinds)/* overload */;
	
public:
	__fastcall TJclClrVTableFixupRecord(PImageCorVTableFixup AData);
	__property PImageCorVTableFixup Data = {read=FData};
	__property unsigned RVA = {read=GetRVA, nodefault};
	__property unsigned Count = {read=GetCount, nodefault};
	__property TJclClrVTableKinds Kinds = {read=GetKinds, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrVTableFixupRecord(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TJclClrImageFlag { cifILOnly, cif32BitRequired, cifStrongNameSinged, cifTrackDebugData };
#pragma option pop

typedef Set<TJclClrImageFlag, cifILOnly, cifTrackDebugData>  TJclClrImageFlags;

class DELPHICLASS TJclClrHeaderEx;
class PASCALIMPLEMENTATION TJclClrHeaderEx : public Jclpeimage::TJclPeCLRHeader 
{
	typedef Jclpeimage::TJclPeCLRHeader inherited;
	
private:
	TJclPeMetadata* FMetadata;
	TJclClrImageFlags FFlags;
	Classes::TCustomMemoryStream* FStrongNameSignature;
	Contnrs::TObjectList* FResources;
	Contnrs::TObjectList* FVTableFixups;
	TJclPeMetadata* __fastcall GetMetadata(void);
	Classes::TCustomMemoryStream* __fastcall GetStrongNameSignature(void);
	TJclClrTableRow* __fastcall GetEntryPointToken(void);
	TJclClrVTableFixupRecord* __fastcall GetVTableFixup(const int Idx);
	int __fastcall GetVTableFixupCount(void);
	void __fastcall UpdateResources(void);
	TJclClrResourceRecord* __fastcall GetResource(const int Idx);
	int __fastcall GetResourceCount(void);
	
public:
	__fastcall TJclClrHeaderEx(const Jclpeimage::TJclPeImage* AImage);
	__fastcall virtual ~TJclClrHeaderEx(void);
	AnsiString __fastcall DumpIL();
	bool __fastcall HasResources(void);
	bool __fastcall HasStrongNameSignature(void);
	bool __fastcall HasVTableFixup(void);
	TJclClrResourceRecord* __fastcall ResourceAt(const unsigned Offset);
	/*         class method */ static TJclClrImageFlags __fastcall ClrImageFlag(TMetaClass* vmt, const unsigned Flags)/* overload */;
	/*         class method */ static unsigned __fastcall ClrImageFlag(TMetaClass* vmt, const TJclClrImageFlags Flags)/* overload */;
	__property TJclPeMetadata* Metadata = {read=GetMetadata};
	__property TJclClrImageFlags Flags = {read=FFlags, nodefault};
	__property TJclClrTableRow* EntryPointToken = {read=GetEntryPointToken};
	__property Classes::TCustomMemoryStream* StrongNameSignature = {read=GetStrongNameSignature};
	__property TJclClrResourceRecord* Resources[int Idx] = {read=GetResource};
	__property int ResourceCount = {read=GetResourceCount, nodefault};
	__property TJclClrVTableFixupRecord* VTableFixups[int Idx] = {read=GetVTableFixup};
	__property int VTableFixupCount = {read=GetVTableFixupCount, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jclclr */
using namespace Jclclr;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclclr
