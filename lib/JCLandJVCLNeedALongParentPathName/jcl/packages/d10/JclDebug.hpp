// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcldebug.pas' rev: 10.00

#ifndef JcldebugHPP
#define JcldebugHPP

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
#include <Jclpeimage.hpp>	// Pascal unit
#include <Jcltd32.hpp>	// Pascal unit
#include <Jclsynch.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jcldebug
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TJclModuleInfo;
class PASCALIMPLEMENTATION TJclModuleInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	unsigned FSize;
	void *FEndAddr;
	void *FStartAddr;
	bool FSystemModule;
	
public:
	__property void * EndAddr = {read=FEndAddr};
	__property unsigned Size = {read=FSize, nodefault};
	__property void * StartAddr = {read=FStartAddr};
	__property bool SystemModule = {read=FSystemModule, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclModuleInfo(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclModuleInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclModuleInfoList;
class PASCALIMPLEMENTATION TJclModuleInfoList : public Contnrs::TObjectList 
{
	typedef Contnrs::TObjectList inherited;
	
private:
	bool FDynamicBuild;
	bool FSystemModulesOnly;
	TJclModuleInfo* __fastcall GetItems(int Index);
	TJclModuleInfo* __fastcall GetModuleFromAddress(void * Addr);
	
protected:
	void __fastcall BuildModulesList(void);
	TJclModuleInfo* __fastcall CreateItemForAddress(void * Addr, bool SystemModule);
	
public:
	__fastcall TJclModuleInfoList(bool ADynamicBuild, bool ASystemModulesOnly);
	bool __fastcall AddModule(unsigned Module, bool SystemModule);
	bool __fastcall IsSystemModuleAddress(void * Addr);
	bool __fastcall IsValidModuleAddress(void * Addr);
	__property bool DynamicBuild = {read=FDynamicBuild, nodefault};
	__property TJclModuleInfo* Items[int Index] = {read=GetItems};
	__property TJclModuleInfo* ModuleFromAddress[void * Addr] = {read=GetModuleFromAddress};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TJclModuleInfoList(void) { }
	#pragma option pop
	
};


struct TJclMapAddress;
typedef TJclMapAddress *PJclMapAddress;

#pragma pack(push,1)
struct TJclMapAddress
{
	
public:
	Word Segment;
	unsigned Offset;
} ;
#pragma pack(pop)

typedef char *PJclMapString;

class DELPHICLASS TJclAbstractMapParser;
class PASCALIMPLEMENTATION TJclAbstractMapParser : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	bool FLinkerBug;
	char *FLinkerBugUnitName;
	Jclfileutils::TJclFileMappingStream* FStream;
	AnsiString __fastcall GetLinkerBugUnitName();
	
protected:
	unsigned FModule;
	char *FLastUnitName;
	char *FLastUnitFileName;
	virtual void __fastcall ClassTableItem(const TJclMapAddress &Address, int Len, char * SectionName, char * GroupName) = 0 ;
	virtual void __fastcall SegmentItem(const TJclMapAddress &Address, int Len, char * GroupName, char * UnitName) = 0 ;
	virtual void __fastcall PublicsByNameItem(const TJclMapAddress &Address, char * Name) = 0 ;
	virtual void __fastcall PublicsByValueItem(const TJclMapAddress &Address, char * Name) = 0 ;
	virtual void __fastcall LineNumberUnitItem(char * UnitName, char * UnitFileName) = 0 ;
	virtual void __fastcall LineNumbersItem(int LineNumber, const TJclMapAddress &Address) = 0 ;
	
public:
	__fastcall virtual TJclAbstractMapParser(const AnsiString MapFileName, unsigned Module)/* overload */;
	__fastcall TJclAbstractMapParser(const AnsiString MapFileName)/* overload */;
	__fastcall virtual ~TJclAbstractMapParser(void);
	void __fastcall Parse(void);
	/*         class method */ static AnsiString __fastcall MapStringToFileName(TMetaClass* vmt, char * MapString);
	/*         class method */ static AnsiString __fastcall MapStringToModuleName(TMetaClass* vmt, char * MapString);
	/*         class method */ static AnsiString __fastcall MapStringToStr(TMetaClass* vmt, char * MapString, bool IgnoreSpaces = false);
	__property bool LinkerBug = {read=FLinkerBug, nodefault};
	__property AnsiString LinkerBugUnitName = {read=GetLinkerBugUnitName};
	__property Jclfileutils::TJclFileMappingStream* Stream = {read=FStream};
};


typedef void __fastcall (__closure *TJclMapClassTableEvent)(System::TObject* Sender, const TJclMapAddress &Address, int Len, const AnsiString SectionName, const AnsiString GroupName);

typedef void __fastcall (__closure *TJclMapSegmentEvent)(System::TObject* Sender, const TJclMapAddress &Address, int Len, const AnsiString GroupName, const AnsiString UnitName);

typedef void __fastcall (__closure *TJclMapPublicsEvent)(System::TObject* Sender, const TJclMapAddress &Address, const AnsiString Name);

typedef void __fastcall (__closure *TJclMapLineNumberUnitEvent)(System::TObject* Sender, const AnsiString UnitName, const AnsiString UnitFileName);

typedef void __fastcall (__closure *TJclMapLineNumbersEvent)(System::TObject* Sender, int LineNumber, const TJclMapAddress &Address);

class DELPHICLASS TJclMapParser;
class PASCALIMPLEMENTATION TJclMapParser : public TJclAbstractMapParser 
{
	typedef TJclAbstractMapParser inherited;
	
private:
	TJclMapClassTableEvent FOnClassTable;
	TJclMapLineNumbersEvent FOnLineNumbers;
	TJclMapLineNumberUnitEvent FOnLineNumberUnit;
	TJclMapPublicsEvent FOnPublicsByValue;
	TJclMapPublicsEvent FOnPublicsByName;
	TJclMapSegmentEvent FOnSegmentItem;
	
protected:
	virtual void __fastcall ClassTableItem(const TJclMapAddress &Address, int Len, char * SectionName, char * GroupName);
	virtual void __fastcall SegmentItem(const TJclMapAddress &Address, int Len, char * GroupName, char * UnitName);
	virtual void __fastcall PublicsByNameItem(const TJclMapAddress &Address, char * Name);
	virtual void __fastcall PublicsByValueItem(const TJclMapAddress &Address, char * Name);
	virtual void __fastcall LineNumberUnitItem(char * UnitName, char * UnitFileName);
	virtual void __fastcall LineNumbersItem(int LineNumber, const TJclMapAddress &Address);
	
public:
	__property TJclMapClassTableEvent OnClassTable = {read=FOnClassTable, write=FOnClassTable};
	__property TJclMapSegmentEvent OnSegment = {read=FOnSegmentItem, write=FOnSegmentItem};
	__property TJclMapPublicsEvent OnPublicsByName = {read=FOnPublicsByName, write=FOnPublicsByName};
	__property TJclMapPublicsEvent OnPublicsByValue = {read=FOnPublicsByValue, write=FOnPublicsByValue};
	__property TJclMapLineNumberUnitEvent OnLineNumberUnit = {read=FOnLineNumberUnit, write=FOnLineNumberUnit};
	__property TJclMapLineNumbersEvent OnLineNumbers = {read=FOnLineNumbers, write=FOnLineNumbers};
public:
	#pragma option push -w-inl
	/* TJclAbstractMapParser.Create */ inline __fastcall virtual TJclMapParser(const AnsiString MapFileName, unsigned Module)/* overload */ : TJclAbstractMapParser(MapFileName, Module) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclAbstractMapParser.Destroy */ inline __fastcall virtual ~TJclMapParser(void) { }
	#pragma option pop
	
};


struct TJclMapSegmentClass;
typedef TJclMapSegmentClass *PJclMapSegmentClass;

struct TJclMapSegmentClass
{
	
public:
	Word Segment;
	unsigned Addr;
	unsigned VA;
	unsigned Len;
	char *SectionName;
	char *GroupName;
} ;

struct TJclMapSegment;
typedef TJclMapSegment *PJclMapSegment;

struct TJclMapSegment
{
	
public:
	Word Segment;
	unsigned StartVA;
	unsigned EndVA;
	char *UnitName;
} ;

struct TJclMapProcName;
typedef TJclMapProcName *PJclMapProcName;

struct TJclMapProcName
{
	
public:
	Word Segment;
	unsigned VA;
	char *ProcName;
} ;

struct TJclMapLineNumber;
typedef TJclMapLineNumber *PJclMapLineNumber;

struct TJclMapLineNumber
{
	
public:
	Word Segment;
	unsigned VA;
	int LineNumber;
} ;

typedef DynamicArray<TJclMapSegmentClass >  JclDebug__6;

typedef DynamicArray<TJclMapLineNumber >  JclDebug__7;

typedef DynamicArray<TJclMapProcName >  JclDebug__8;

typedef DynamicArray<TJclMapSegment >  JclDebug__9;

typedef DynamicArray<TJclMapProcName >  JclDebug__01;

class DELPHICLASS TJclMapScanner;
class PASCALIMPLEMENTATION TJclMapScanner : public TJclAbstractMapParser 
{
	typedef TJclAbstractMapParser inherited;
	
private:
	DynamicArray<TJclMapSegmentClass >  FSegmentClasses;
	DynamicArray<TJclMapLineNumber >  FLineNumbers;
	DynamicArray<TJclMapProcName >  FProcNames;
	DynamicArray<TJclMapSegment >  FSegments;
	DynamicArray<TJclMapProcName >  FSourceNames;
	int FLineNumbersCnt;
	int FLineNumberErrors;
	char *FNewUnitFileName;
	int FProcNamesCnt;
	int FSegmentCnt;
	
protected:
	unsigned __fastcall AddrToVA(const unsigned Addr);
	virtual void __fastcall ClassTableItem(const TJclMapAddress &Address, int Len, char * SectionName, char * GroupName);
	virtual void __fastcall SegmentItem(const TJclMapAddress &Address, int Len, char * GroupName, char * UnitName);
	virtual void __fastcall PublicsByNameItem(const TJclMapAddress &Address, char * Name);
	virtual void __fastcall PublicsByValueItem(const TJclMapAddress &Address, char * Name);
	virtual void __fastcall LineNumbersItem(int LineNumber, const TJclMapAddress &Address);
	virtual void __fastcall LineNumberUnitItem(char * UnitName, char * UnitFileName);
	void __fastcall Scan(void);
	
public:
	__fastcall virtual TJclMapScanner(const AnsiString MapFileName, unsigned Module)/* overload */;
	int __fastcall LineNumberFromAddr(unsigned Addr)/* overload */;
	int __fastcall LineNumberFromAddr(unsigned Addr, /* out */ int &Offset)/* overload */;
	AnsiString __fastcall ModuleNameFromAddr(unsigned Addr);
	unsigned __fastcall ModuleStartFromAddr(unsigned Addr);
	AnsiString __fastcall ProcNameFromAddr(unsigned Addr)/* overload */;
	AnsiString __fastcall ProcNameFromAddr(unsigned Addr, /* out */ int &Offset)/* overload */;
	AnsiString __fastcall SourceNameFromAddr(unsigned Addr);
	__property int LineNumberErrors = {read=FLineNumberErrors, nodefault};
public:
	#pragma option push -w-inl
	/* TJclAbstractMapParser.Destroy */ inline __fastcall virtual ~TJclMapScanner(void) { }
	#pragma option pop
	
};


struct TJclDbgHeader;
typedef TJclDbgHeader *PJclDbgHeader;

#pragma pack(push,1)
struct TJclDbgHeader
{
	
public:
	unsigned Signature;
	Byte Version;
	int Units;
	int SourceNames;
	int Symbols;
	int LineNumbers;
	int Words;
	int ModuleName;
	int CheckSum;
	bool CheckSumValid;
} ;
#pragma pack(pop)

class DELPHICLASS TJclBinDebugGenerator;
class PASCALIMPLEMENTATION TJclBinDebugGenerator : public TJclMapScanner 
{
	typedef TJclMapScanner inherited;
	
private:
	Classes::TMemoryStream* FDataStream;
	AnsiString FMapFileName;
	
protected:
	void __fastcall CreateData(void);
	
public:
	__fastcall virtual TJclBinDebugGenerator(const AnsiString MapFileName, unsigned Module)/* overload */;
	__fastcall virtual ~TJclBinDebugGenerator(void);
	bool __fastcall CalculateCheckSum(void);
	__property Classes::TMemoryStream* DataStream = {read=FDataStream};
};


struct TJclBinDbgNameCache
{
	
public:
	unsigned Addr;
	int FirstWord;
	int SecondWord;
} ;

typedef DynamicArray<TJclMapLineNumber >  JclDebug__31;

typedef DynamicArray<TJclBinDbgNameCache >  JclDebug__41;

class DELPHICLASS TJclBinDebugScanner;
class PASCALIMPLEMENTATION TJclBinDebugScanner : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	bool FCacheData;
	Classes::TCustomMemoryStream* FStream;
	bool FValidFormat;
	DynamicArray<TJclMapLineNumber >  FLineNumbers;
	DynamicArray<TJclBinDbgNameCache >  FProcNames;
	AnsiString __fastcall GetModuleName();
	
protected:
	void __fastcall CacheLineNumbers(void);
	void __fastcall CacheProcNames(void);
	void __fastcall CheckFormat(void);
	AnsiString __fastcall DataToStr(int A);
	void * __fastcall MakePtr(int A);
	bool __fastcall ReadValue(void * &P, int &Value);
	
public:
	__fastcall TJclBinDebugScanner(Classes::TCustomMemoryStream* AStream, bool CacheData);
	bool __fastcall IsModuleNameValid(const AnsiString Name);
	int __fastcall LineNumberFromAddr(unsigned Addr)/* overload */;
	int __fastcall LineNumberFromAddr(unsigned Addr, /* out */ int &Offset)/* overload */;
	AnsiString __fastcall ProcNameFromAddr(unsigned Addr)/* overload */;
	AnsiString __fastcall ProcNameFromAddr(unsigned Addr, /* out */ int &Offset)/* overload */;
	AnsiString __fastcall ModuleNameFromAddr(unsigned Addr);
	unsigned __fastcall ModuleStartFromAddr(unsigned Addr);
	AnsiString __fastcall SourceNameFromAddr(unsigned Addr);
	__property AnsiString ModuleName = {read=GetModuleName};
	__property bool ValidFormat = {read=FValidFormat, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclBinDebugScanner(void) { }
	#pragma option pop
	
};


struct TJclLocationInfo;
typedef TJclLocationInfo *PJclLocationInfo;

class DELPHICLASS TJclDebugInfoSource;
class PASCALIMPLEMENTATION TJclDebugInfoSource : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	unsigned FModule;
	AnsiString __fastcall GetFileName();
	
protected:
	virtual unsigned __fastcall VAFromAddr(const void * Addr);
	
public:
	__fastcall virtual TJclDebugInfoSource(unsigned AModule);
	virtual bool __fastcall InitializeSource(void) = 0 ;
	virtual bool __fastcall GetLocationInfo(const void * Addr, /* out */ TJclLocationInfo &Info) = 0 ;
	__property unsigned Module = {read=FModule, nodefault};
	__property AnsiString FileName = {read=GetFileName};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclDebugInfoSource(void) { }
	#pragma option pop
	
};


struct TJclLocationInfo
{
	
public:
	void *Address;
	AnsiString UnitName;
	AnsiString ProcedureName;
	int OffsetFromProcName;
	int LineNumber;
	int OffsetFromLineNumber;
	AnsiString SourceName;
	TJclDebugInfoSource* DebugInfo;
	AnsiString BinaryFileName;
} ;

#pragma option push -b-
enum JclDebug__51 { lievLocationInfo, lievProcedureStartLocationInfo, lievUnitVersionInfo };
#pragma option pop

typedef Set<JclDebug__51, lievLocationInfo, lievUnitVersionInfo>  TJclLocationInfoExValues;

#pragma option push -b-
enum JclDebug__61 { liloAutoGetAddressInfo, liloAutoGetLocationInfo, liloAutoGetUnitVersionInfo };
#pragma option pop

typedef Set<JclDebug__61, liloAutoGetAddressInfo, liloAutoGetUnitVersionInfo>  TJclLocationInfoListOptions;

class DELPHICLASS TJclLocationInfoEx;
class DELPHICLASS TJclCustomLocationInfoList;
typedef TMetaClass* TJclLocationInfoClass;

class PASCALIMPLEMENTATION TJclCustomLocationInfoList : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
protected:
	TMetaClass* FItemClass;
	Contnrs::TObjectList* FItems;
	TJclLocationInfoListOptions FOptions;
	AnsiString __fastcall GetAsString();
	int __fastcall GetCount(void);
	TJclLocationInfoEx* __fastcall InternalAdd(void * Addr);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	__fastcall virtual TJclCustomLocationInfoList(void);
	__fastcall virtual ~TJclCustomLocationInfoList(void);
	void __fastcall AddStackInfoList(System::TObject* AStackInfoList);
	void __fastcall Clear(void);
	__property AnsiString AsString = {read=GetAsString};
	__property int Count = {read=GetCount, nodefault};
	__property TJclLocationInfoListOptions Options = {read=FOptions, write=FOptions, nodefault};
};


class PASCALIMPLEMENTATION TJclLocationInfoEx : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	void *FAddress;
	AnsiString FBinaryFileName;
	TJclDebugInfoSource* FDebugInfo;
	int FLineNumber;
	int FLineNumberOffsetFromProcedureStart;
	AnsiString FModuleName;
	int FOffsetFromLineNumber;
	int FOffsetFromProcName;
	TJclCustomLocationInfoList* FParent;
	AnsiString FProcedureName;
	AnsiString FSourceName;
	AnsiString FSourceUnitName;
	System::TDateTime FUnitVersionDateTime;
	AnsiString FUnitVersionExtra;
	AnsiString FUnitVersionLogPath;
	AnsiString FUnitVersionRCSfile;
	AnsiString FUnitVersionRevision;
	void *FVAddress;
	TJclLocationInfoExValues FValues;
	void __fastcall Fill(TJclLocationInfoListOptions AOptions);
	AnsiString __fastcall GetAsString();
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	__fastcall TJclLocationInfoEx(TJclCustomLocationInfoList* AParent, void * Address);
	virtual void __fastcall Clear(void);
	__property void * Address = {read=FAddress, write=FAddress};
	__property AnsiString AsString = {read=GetAsString};
	__property AnsiString BinaryFileName = {read=FBinaryFileName, write=FBinaryFileName};
	__property TJclDebugInfoSource* DebugInfo = {read=FDebugInfo, write=FDebugInfo};
	__property int LineNumber = {read=FLineNumber, write=FLineNumber, nodefault};
	__property int LineNumberOffsetFromProcedureStart = {read=FLineNumberOffsetFromProcedureStart, write=FLineNumberOffsetFromProcedureStart, nodefault};
	__property AnsiString ModuleName = {read=FModuleName, write=FModuleName};
	__property int OffsetFromLineNumber = {read=FOffsetFromLineNumber, write=FOffsetFromLineNumber, nodefault};
	__property int OffsetFromProcName = {read=FOffsetFromProcName, write=FOffsetFromProcName, nodefault};
	__property AnsiString ProcedureName = {read=FProcedureName, write=FProcedureName};
	__property AnsiString SourceName = {read=FSourceName, write=FSourceName};
	__property AnsiString SourceUnitName = {read=FSourceUnitName, write=FSourceUnitName};
	__property System::TDateTime UnitVersionDateTime = {read=FUnitVersionDateTime, write=FUnitVersionDateTime};
	__property AnsiString UnitVersionExtra = {read=FUnitVersionExtra, write=FUnitVersionExtra};
	__property AnsiString UnitVersionLogPath = {read=FUnitVersionLogPath, write=FUnitVersionLogPath};
	__property AnsiString UnitVersionRCSfile = {read=FUnitVersionRCSfile, write=FUnitVersionRCSfile};
	__property AnsiString UnitVersionRevision = {read=FUnitVersionRevision, write=FUnitVersionRevision};
	__property void * VAddress = {read=FVAddress, write=FVAddress};
	__property TJclLocationInfoExValues Values = {read=FValues, write=FValues, nodefault};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TJclLocationInfoEx(void) { }
	#pragma option pop
	
};


typedef TMetaClass* TJclCustomLocationInfoListClass;

class DELPHICLASS TJclLocationInfoList;
class PASCALIMPLEMENTATION TJclLocationInfoList : public TJclCustomLocationInfoList 
{
	typedef TJclCustomLocationInfoList inherited;
	
public:
	TJclLocationInfoEx* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	TJclLocationInfoEx* __fastcall GetItems(int AIndex);
	
public:
	__fastcall virtual TJclLocationInfoList(void);
	TJclLocationInfoEx* __fastcall Add(void * Addr);
	__property TJclLocationInfoEx* Items[int AIndex] = {read=GetItems/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclCustomLocationInfoList.Destroy */ inline __fastcall virtual ~TJclLocationInfoList(void) { }
	#pragma option pop
	
};


typedef TMetaClass* TJclDebugInfoSourceClass;

class DELPHICLASS TJclDebugInfoList;
class PASCALIMPLEMENTATION TJclDebugInfoList : public Contnrs::TObjectList 
{
	typedef Contnrs::TObjectList inherited;
	
private:
	TJclDebugInfoSource* __fastcall GetItemFromModule(const unsigned Module);
	TJclDebugInfoSource* __fastcall GetItems(int Index);
	
protected:
	TJclDebugInfoSource* __fastcall CreateDebugInfo(const unsigned Module);
	
public:
	/*         class method */ static void __fastcall RegisterDebugInfoSource(TMetaClass* vmt, const TMetaClass* InfoSourceClass);
	/*         class method */ static void __fastcall UnRegisterDebugInfoSource(TMetaClass* vmt, const TMetaClass* InfoSourceClass);
	/*         class method */ static void __fastcall RegisterDebugInfoSourceFirst(TMetaClass* vmt, const TMetaClass* InfoSourceClass);
	/*         class method */ static void __fastcall NeedInfoSourceClassList(TMetaClass* vmt);
	bool __fastcall GetLocationInfo(const void * Addr, /* out */ TJclLocationInfo &Info);
	__property TJclDebugInfoSource* ItemFromModule[unsigned Module] = {read=GetItemFromModule};
	__property TJclDebugInfoSource* Items[int Index] = {read=GetItems};
public:
	#pragma option push -w-inl
	/* TObjectList.Create */ inline __fastcall TJclDebugInfoList(void)/* overload */ : Contnrs::TObjectList() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TJclDebugInfoList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclDebugInfoMap;
class PASCALIMPLEMENTATION TJclDebugInfoMap : public TJclDebugInfoSource 
{
	typedef TJclDebugInfoSource inherited;
	
private:
	TJclMapScanner* FScanner;
	
public:
	__fastcall virtual ~TJclDebugInfoMap(void);
	virtual bool __fastcall InitializeSource(void);
	virtual bool __fastcall GetLocationInfo(const void * Addr, /* out */ TJclLocationInfo &Info);
public:
	#pragma option push -w-inl
	/* TJclDebugInfoSource.Create */ inline __fastcall virtual TJclDebugInfoMap(unsigned AModule) : TJclDebugInfoSource(AModule) { }
	#pragma option pop
	
};


class DELPHICLASS TJclDebugInfoBinary;
class PASCALIMPLEMENTATION TJclDebugInfoBinary : public TJclDebugInfoSource 
{
	typedef TJclDebugInfoSource inherited;
	
private:
	TJclBinDebugScanner* FScanner;
	Classes::TCustomMemoryStream* FStream;
	
public:
	__fastcall virtual ~TJclDebugInfoBinary(void);
	virtual bool __fastcall InitializeSource(void);
	virtual bool __fastcall GetLocationInfo(const void * Addr, /* out */ TJclLocationInfo &Info);
public:
	#pragma option push -w-inl
	/* TJclDebugInfoSource.Create */ inline __fastcall virtual TJclDebugInfoBinary(unsigned AModule) : TJclDebugInfoSource(AModule) { }
	#pragma option pop
	
};


class DELPHICLASS TJclDebugInfoExports;
class PASCALIMPLEMENTATION TJclDebugInfoExports : public TJclDebugInfoSource 
{
	typedef TJclDebugInfoSource inherited;
	
private:
	Jclpeimage::TJclPeBorImage* FImage;
	bool __fastcall IsAddressInThisExportedFunction(Sysutils::PByteArray Addr, unsigned FunctionStartAddr);
	
public:
	__fastcall virtual ~TJclDebugInfoExports(void);
	virtual bool __fastcall InitializeSource(void);
	virtual bool __fastcall GetLocationInfo(const void * Addr, /* out */ TJclLocationInfo &Info);
public:
	#pragma option push -w-inl
	/* TJclDebugInfoSource.Create */ inline __fastcall virtual TJclDebugInfoExports(unsigned AModule) : TJclDebugInfoSource(AModule) { }
	#pragma option pop
	
};


class DELPHICLASS TJclDebugInfoTD32;
class PASCALIMPLEMENTATION TJclDebugInfoTD32 : public TJclDebugInfoSource 
{
	typedef TJclDebugInfoSource inherited;
	
private:
	Jcltd32::TJclPeBorTD32Image* FImage;
	
public:
	__fastcall virtual ~TJclDebugInfoTD32(void);
	virtual bool __fastcall InitializeSource(void);
	virtual bool __fastcall GetLocationInfo(const void * Addr, /* out */ TJclLocationInfo &Info);
public:
	#pragma option push -w-inl
	/* TJclDebugInfoSource.Create */ inline __fastcall virtual TJclDebugInfoTD32(unsigned AModule) : TJclDebugInfoSource(AModule) { }
	#pragma option pop
	
};


class DELPHICLASS TJclDebugInfoSymbols;
class PASCALIMPLEMENTATION TJclDebugInfoSymbols : public TJclDebugInfoSource 
{
	typedef TJclDebugInfoSource inherited;
	
public:
	/*         class method */ static bool __fastcall LoadDebugFunctions(TMetaClass* vmt);
	/*         class method */ static bool __fastcall UnloadDebugFunctions(TMetaClass* vmt);
	/*         class method */ static bool __fastcall InitializeDebugSymbols(TMetaClass* vmt);
	/*         class method */ static bool __fastcall CleanupDebugSymbols(TMetaClass* vmt);
	virtual bool __fastcall InitializeSource(void);
	virtual bool __fastcall GetLocationInfo(const void * Addr, /* out */ TJclLocationInfo &Info);
public:
	#pragma option push -w-inl
	/* TJclDebugInfoSource.Create */ inline __fastcall virtual TJclDebugInfoSymbols(unsigned AModule) : TJclDebugInfoSource(AModule) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclDebugInfoSymbols(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclStackBaseList;
class PASCALIMPLEMENTATION TJclStackBaseList : public Contnrs::TObjectList 
{
	typedef Contnrs::TObjectList inherited;
	
private:
	unsigned FThreadID;
	System::TDateTime FTimeStamp;
	
protected:
	Classes::TNotifyEvent FOnDestroy;
	
public:
	__fastcall TJclStackBaseList(void);
	__fastcall virtual ~TJclStackBaseList(void);
	__property unsigned ThreadID = {read=FThreadID, nodefault};
	__property System::TDateTime TimeStamp = {read=FTimeStamp};
};


typedef unsigned TDWORD_PTRArray[536870909];

typedef unsigned *PDWORD_PTRArray;

typedef unsigned *PDWORD_PTR;

struct TStackFrame;
typedef TStackFrame *PStackFrame;

struct TStackFrame
{
	
public:
	unsigned CallerFrame;
	unsigned CallerAddr;
} ;

struct TStackInfo;
typedef TStackInfo *PStackInfo;

struct TStackInfo
{
	
public:
	unsigned CallerAddr;
	unsigned Level;
	unsigned CallerFrame;
	unsigned DumpSize;
	unsigned ParamSize;
	unsigned *ParamPtr;
	union
	{
		struct 
		{
			Byte *DumpPtr;
			
		};
		struct 
		{
			TStackFrame *StackFrame;
			
		};
		
	};
} ;

class DELPHICLASS TJclStackInfoItem;
class PASCALIMPLEMENTATION TJclStackInfoItem : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TStackInfo FStackInfo;
	void * __fastcall GetCallerAddr(void);
	unsigned __fastcall GetLogicalAddress(void);
	
public:
	__property void * CallerAddr = {read=GetCallerAddr};
	__property unsigned LogicalAddress = {read=GetLogicalAddress, nodefault};
	__property TStackInfo StackInfo = {read=FStackInfo};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclStackInfoItem(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclStackInfoItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclStackInfoList;
class PASCALIMPLEMENTATION TJclStackInfoList : public TJclStackBaseList 
{
	typedef TJclStackBaseList inherited;
	
public:
	TJclStackInfoItem* operator[](int Index) { return Items[Index]; }
	
private:
	unsigned FIgnoreLevels;
	unsigned TopOfStack;
	unsigned BaseOfStack;
	void * *FStackData;
	void *FFramePointer;
	TJclModuleInfoList* FModuleInfoList;
	bool FCorrectOnAccess;
	bool FSkipFirstItem;
	bool FDelayedTrace;
	bool FInStackTracing;
	bool FRaw;
	unsigned FStackOffset;
	TJclStackInfoItem* __fastcall GetItems(int Index);
	bool __fastcall NextStackFrame(PStackFrame &StackFrame, TStackInfo &StackInfo);
	void __fastcall StoreToList(const TStackInfo &StackInfo);
	void __fastcall TraceStackFrames(void);
	void __fastcall TraceStackRaw(void);
	void __fastcall DelayStoreStack(void);
	bool __fastcall ValidCallSite(unsigned CodeAddr, /* out */ unsigned &CallInstructionSize);
	bool __fastcall ValidStackAddr(unsigned StackAddr);
	int __fastcall GetCount(void);
	void __fastcall CorrectOnAccess(bool ASkipFirstItem);
	
public:
	__fastcall TJclStackInfoList(bool ARaw, unsigned AIgnoreLevels, void * AFirstCaller)/* overload */;
	__fastcall TJclStackInfoList(bool ARaw, unsigned AIgnoreLevels, void * AFirstCaller, bool ADelayedTrace)/* overload */;
	__fastcall TJclStackInfoList(bool ARaw, unsigned AIgnoreLevels, void * AFirstCaller, bool ADelayedTrace, void * ABaseOfStack)/* overload */;
	__fastcall TJclStackInfoList(bool ARaw, unsigned AIgnoreLevels, void * AFirstCaller, bool ADelayedTrace, void * ABaseOfStack, void * ATopOfStack)/* overload */;
	__fastcall virtual ~TJclStackInfoList(void);
	void __fastcall ForceStackTracing(void);
	void __fastcall AddToStrings(Classes::TStrings* Strings, bool IncludeModuleName = false, bool IncludeAddressOffset = false, bool IncludeStartProcLineOffset = false, bool IncludeVAddress = false);
	__property bool DelayedTrace = {read=FDelayedTrace, nodefault};
	__property TJclStackInfoItem* Items[int Index] = {read=GetItems/*, default*/};
	__property unsigned IgnoreLevels = {read=FIgnoreLevels, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property bool Raw = {read=FRaw, nodefault};
};


struct TJmpInstruction;
typedef TJmpInstruction *PJmpInstruction;

#pragma pack(push,1)
struct TJmpInstruction
{
	
public:
	Byte OpCode;
	int Distance;
} ;
#pragma pack(pop)

struct TExcDescEntry
{
	
public:
	void *VTable;
	void *Handler;
} ;

struct TExcDesc;
typedef TExcDesc *PExcDesc;

#pragma pack(push,1)
struct TExcDesc
{
	
public:
	#pragma pack(push,1)
	TJmpInstruction JMP;
	#pragma pack(pop)
	union
	{
		struct 
		{
			int Cnt;
			TExcDescEntry ExcTab[1];
			
		};
		struct 
		{
			Byte Instructions[1];
			
		};
		
	};
} ;
#pragma pack(pop)

struct TExcFrame;
typedef TExcFrame *PExcFrame;

struct TExcFrame
{
	
public:
	TExcFrame *Next;
	TExcDesc *Desc;
	void *FramePointer;
	union
	{
		struct 
		{
			void *SelfOfMethod;
			
		};
		struct 
		{
			void *ConstructedObject;
			
		};
		
	};
} ;

struct TJmpTable;
typedef TJmpTable *PJmpTable;

#pragma pack(push,1)
struct TJmpTable
{
	
public:
	Word OPCode;
	void *Ptr;
} ;
#pragma pack(pop)

#pragma option push -b-
enum TExceptFrameKind { efkUnknown, efkFinally, efkAnyException, efkOnException, efkAutoException };
#pragma option pop

typedef DynamicArray<TExcDescEntry >  JclDebug__13;

class DELPHICLASS TJclExceptFrame;
class PASCALIMPLEMENTATION TJclExceptFrame : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TExceptFrameKind FFrameKind;
	void *FFrameLocation;
	void *FCodeLocation;
	DynamicArray<TExcDescEntry >  FExcTab;
	
protected:
	void __fastcall AnalyseExceptFrame(PExcDesc AExcDesc);
	
public:
	__fastcall TJclExceptFrame(void * AFrameLocation, PExcDesc AExcDesc);
	bool __fastcall Handles(System::TObject* ExceptObj);
	bool __fastcall HandlerInfo(System::TObject* ExceptObj, /* out */ void * &HandlerAt);
	__property void * CodeLocation = {read=FCodeLocation};
	__property void * FrameLocation = {read=FFrameLocation};
	__property TExceptFrameKind FrameKind = {read=FFrameKind, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclExceptFrame(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclExceptFrameList;
class PASCALIMPLEMENTATION TJclExceptFrameList : public TJclStackBaseList 
{
	typedef TJclStackBaseList inherited;
	
private:
	int FIgnoreLevels;
	TJclExceptFrame* __fastcall GetItems(int Index);
	
protected:
	TJclExceptFrame* __fastcall AddFrame(PExcFrame AFrame);
	
public:
	__fastcall TJclExceptFrameList(int AIgnoreLevels);
	void __fastcall TraceExceptionFrames(void);
	__property TJclExceptFrame* Items[int Index] = {read=GetItems};
	__property int IgnoreLevels = {read=FIgnoreLevels, write=FIgnoreLevels, nodefault};
public:
	#pragma option push -w-inl
	/* TJclStackBaseList.Destroy */ inline __fastcall virtual ~TJclExceptFrameList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclDebugThread;
class PASCALIMPLEMENTATION TJclDebugThread : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
private:
	System::TObject* FSyncException;
	AnsiString FThreadName;
	void __fastcall DoHandleException(void);
	AnsiString __fastcall GetThreadInfo();
	
protected:
	void __fastcall DoNotify(void);
	DYNAMIC void __fastcall DoSyncHandleException(void);
	void __fastcall HandleException(System::TObject* Sender = (System::TObject*)(0x0));
	
public:
	__fastcall TJclDebugThread(bool ASuspended, const AnsiString AThreadName);
	__fastcall virtual ~TJclDebugThread(void);
	__property System::TObject* SyncException = {read=FSyncException};
	__property AnsiString ThreadInfo = {read=GetThreadInfo};
	__property AnsiString ThreadName = {read=FThreadName};
};


typedef void __fastcall (__closure *TJclDebugThreadNotifyEvent)(TJclDebugThread* Thread);

typedef void __fastcall (__closure *TJclThreadIDNotifyEvent)(unsigned ThreadID);

class DELPHICLASS TJclDebugThreadList;
class PASCALIMPLEMENTATION TJclDebugThreadList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Contnrs::TObjectList* FList;
	Jclsynch::TJclCriticalSection* FLock;
	Jclsynch::TJclCriticalSection* FReadLock;
	unsigned FRegSyncThreadID;
	bool FSaveCreationStack;
	unsigned FUnregSyncThreadID;
	TJclDebugThreadNotifyEvent FOnSyncException;
	TJclThreadIDNotifyEvent FOnThreadRegistered;
	TJclThreadIDNotifyEvent FOnThreadUnregistered;
	AnsiString __fastcall GetThreadClassNames(unsigned ThreadID);
	AnsiString __fastcall GetThreadInfos(unsigned ThreadID);
	AnsiString __fastcall GetThreadNames(unsigned ThreadID);
	void __fastcall DoSyncThreadRegistered(void);
	void __fastcall DoSyncThreadUnregistered(void);
	System::TDateTime __fastcall GetThreadCreationTime(unsigned ThreadID);
	unsigned __fastcall GetThreadHandle(int Index);
	unsigned __fastcall GetThreadID(int Index);
	int __fastcall GetThreadIDCount(void);
	unsigned __fastcall GetThreadParentID(unsigned ThreadID);
	AnsiString __fastcall GetThreadValues(unsigned ThreadID, int Index);
	int __fastcall IndexOfThreadID(unsigned ThreadID);
	
protected:
	void __fastcall DoSyncException(TJclDebugThread* Thread);
	void __fastcall DoThreadRegistered(Classes::TThread* Thread);
	void __fastcall DoThreadUnregistered(Classes::TThread* Thread);
	void __fastcall InternalRegisterThread(Classes::TThread* Thread, unsigned ThreadID, const AnsiString ThreadName);
	void __fastcall InternalUnregisterThread(Classes::TThread* Thread, unsigned ThreadID);
	
public:
	__fastcall TJclDebugThreadList(void);
	__fastcall virtual ~TJclDebugThreadList(void);
	bool __fastcall AddStackListToLocationInfoList(unsigned ThreadID, TJclLocationInfoList* AList);
	void __fastcall RegisterThread(Classes::TThread* Thread, const AnsiString ThreadName);
	void __fastcall RegisterThreadID(unsigned AThreadID);
	void __fastcall UnregisterThread(Classes::TThread* Thread);
	void __fastcall UnregisterThreadID(unsigned AThreadID);
	__property Jclsynch::TJclCriticalSection* Lock = {read=FLock};
	__property bool SaveCreationStack = {read=FSaveCreationStack, write=FSaveCreationStack, nodefault};
	__property AnsiString ThreadClassNames[unsigned ThreadID] = {read=GetThreadClassNames};
	__property System::TDateTime ThreadCreationTime[unsigned ThreadID] = {read=GetThreadCreationTime};
	__property unsigned ThreadHandles[int Index] = {read=GetThreadHandle};
	__property unsigned ThreadIDs[int Index] = {read=GetThreadID};
	__property int ThreadIDCount = {read=GetThreadIDCount, nodefault};
	__property AnsiString ThreadInfos[unsigned ThreadID] = {read=GetThreadInfos};
	__property AnsiString ThreadNames[unsigned ThreadID] = {read=GetThreadNames};
	__property unsigned ThreadParentIDs[unsigned ThreadID] = {read=GetThreadParentID};
	__property TJclDebugThreadNotifyEvent OnSyncException = {read=FOnSyncException, write=FOnSyncException};
	__property TJclThreadIDNotifyEvent OnThreadRegistered = {read=FOnThreadRegistered, write=FOnThreadRegistered};
	__property TJclThreadIDNotifyEvent OnThreadUnregistered = {read=FOnThreadUnregistered, write=FOnThreadUnregistered};
};


class DELPHICLASS TJclDebugThreadInfo;
class PASCALIMPLEMENTATION TJclDebugThreadInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	System::TDateTime FCreationTime;
	unsigned FParentThreadID;
	TJclStackInfoList* FStackList;
	AnsiString FThreadClassName;
	unsigned FThreadID;
	unsigned FThreadHandle;
	AnsiString FThreadName;
	
public:
	__fastcall TJclDebugThreadInfo(unsigned AParentThreadID, unsigned AThreadID, bool AStack);
	__fastcall virtual ~TJclDebugThreadInfo(void);
	__property System::TDateTime CreationTime = {read=FCreationTime};
	__property unsigned ParentThreadID = {read=FParentThreadID, nodefault};
	__property TJclStackInfoList* StackList = {read=FStackList};
	__property AnsiString ThreadClassName = {read=FThreadClassName, write=FThreadClassName};
	__property unsigned ThreadID = {read=FThreadID, nodefault};
	__property unsigned ThreadHandle = {read=FThreadHandle, write=FThreadHandle, nodefault};
	__property AnsiString ThreadName = {read=FThreadName, write=FThreadName};
};


#pragma option push -b-
enum JclDebug__63 { tioIsMainThread, tioName, tioCreationTime, tioParentThreadID, tioStack, tioCreationStack };
#pragma option pop

typedef Set<JclDebug__63, tioIsMainThread, tioCreationStack>  TJclThreadInfoOptions;

class DELPHICLASS TJclCustomThreadInfo;
class PASCALIMPLEMENTATION TJclCustomThreadInfo : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
protected:
	System::TDateTime FCreationTime;
	TJclCustomLocationInfoList* FCreationStack;
	AnsiString FName;
	unsigned FParentThreadID;
	TJclCustomLocationInfoList* FStack;
	unsigned FThreadID;
	TJclThreadInfoOptions FValues;
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual TMetaClass* __fastcall GetStackClass(void);
	
public:
	__fastcall TJclCustomThreadInfo(void);
	__fastcall virtual ~TJclCustomThreadInfo(void);
	__property System::TDateTime CreationTime = {read=FCreationTime, write=FCreationTime};
	__property AnsiString Name = {read=FName, write=FName};
	__property unsigned ParentThreadID = {read=FParentThreadID, write=FParentThreadID, nodefault};
	__property unsigned ThreadID = {read=FThreadID, write=FThreadID, nodefault};
	__property TJclThreadInfoOptions Values = {read=FValues, write=FValues, nodefault};
};


class DELPHICLASS TJclThreadInfo;
class PASCALIMPLEMENTATION TJclThreadInfo : public TJclCustomThreadInfo 
{
	typedef TJclCustomThreadInfo inherited;
	
private:
	AnsiString __fastcall GetAsString();
	void __fastcall InternalFill(unsigned AThreadHandle, unsigned AThreadID, TJclThreadInfoOptions AGatherOptions, bool AExceptThread);
	TJclLocationInfoList* __fastcall GetStack(const int AIndex);
	
protected:
	virtual TMetaClass* __fastcall GetStackClass(void);
	
public:
	void __fastcall Fill(unsigned AThreadHandle, unsigned AThreadID, TJclThreadInfoOptions AGatherOptions);
	void __fastcall FillFromExceptThread(TJclThreadInfoOptions AGatherOptions);
	__property AnsiString AsString = {read=GetAsString};
	__property TJclLocationInfoList* CreationStack = {read=GetStack, index=1};
	__property TJclLocationInfoList* Stack = {read=GetStack, index=2};
public:
	#pragma option push -w-inl
	/* TJclCustomThreadInfo.Create */ inline __fastcall TJclThreadInfo(void) : TJclCustomThreadInfo() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclCustomThreadInfo.Destroy */ inline __fastcall virtual ~TJclThreadInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclThreadInfoList;
class PASCALIMPLEMENTATION TJclThreadInfoList : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
public:
	TJclThreadInfo* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	TJclThreadInfoOptions FGatherOptions;
	Contnrs::TObjectList* FItems;
	AnsiString __fastcall GetAsString();
	int __fastcall GetCount(void);
	TJclThreadInfo* __fastcall GetItems(int AIndex);
	void __fastcall InternalGather(unsigned * AIncludeThreadIDs, const int AIncludeThreadIDs_Size, unsigned * AExcludeThreadIDs, const int AExcludeThreadIDs_Size);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	__fastcall TJclThreadInfoList(void);
	__fastcall virtual ~TJclThreadInfoList(void);
	TJclThreadInfo* __fastcall Add(void);
	void __fastcall Clear(void);
	void __fastcall Gather(unsigned AExceptThreadID);
	void __fastcall GatherExclude(unsigned * AThreadIDs, const int AThreadIDs_Size);
	void __fastcall GatherInclude(unsigned * AThreadIDs, const int AThreadIDs_Size);
	__property AnsiString AsString = {read=GetAsString};
	__property int Count = {read=GetCount, nodefault};
	__property TJclThreadInfoOptions GatherOptions = {read=FGatherOptions, write=FGatherOptions, nodefault};
	__property TJclThreadInfo* Items[int AIndex] = {read=GetItems/*, default*/};
};


#pragma option push -b-
enum TJclStackTrackingOption { stStack, stExceptFrame, stRawMode, stAllModules, stStaticModuleList, stDelayedTrace, stTraceAllExceptions, stMainThreadOnly, stDisableIfDebuggerAttached };
#pragma option pop

typedef Set<TJclStackTrackingOption, stStack, stDisableIfDebuggerAttached>  TJclStackTrackingOptions;

//-- var, const, procedure ---------------------------------------------------
#define EnvironmentVarNtSymbolPath "_NT_SYMBOL_PATH"
#define EnvironmentVarAlternateNtSymbolPath "_NT_ALTERNATE_SYMBOL_PATH"
static const Word MaxStackTraceItems = 0x1000;
static const int JclDbgDataSignature = 0x4742444a;
#define JclDbgDataResName "JCLDEBUG"
static const Shortint JclDbgHeaderVersion = 0x1;
#define JclDbgFileExtension ".jdbg"
#define JclMapFileExtension ".map"
#define DrcFileExtension ".drc"
extern PACKAGE TJclStackTrackingOptions JclStackTrackingOptions;
extern PACKAGE AnsiString JclDebugInfoSymbolPaths;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE void __fastcall AssertKindOf(const AnsiString ClassName, const System::TObject* Obj)/* overload */;
extern PACKAGE void __fastcall AssertKindOf(const TMetaClass* ClassType, const System::TObject* Obj)/* overload */;
extern PACKAGE void __fastcall TraceMsg(const AnsiString Msg);
extern PACKAGE void __fastcall TraceFmt(const AnsiString Fmt, System::TVarRec const * Args, const int Args_Size);
extern PACKAGE void __fastcall TraceLoc(const AnsiString Msg);
extern PACKAGE void __fastcall TraceLocFmt(const AnsiString Fmt, System::TVarRec const * Args, const int Args_Size);
extern PACKAGE bool __fastcall ConvertMapFileToJdbgFile(const AnsiString MapFileName)/* overload */;
extern PACKAGE bool __fastcall ConvertMapFileToJdbgFile(const AnsiString MapFileName, /* out */ AnsiString &LinkerBugUnit, /* out */ int &LineNumberErrors)/* overload */;
extern PACKAGE bool __fastcall ConvertMapFileToJdbgFile(const AnsiString MapFileName, /* out */ AnsiString &LinkerBugUnit, /* out */ int &LineNumberErrors, /* out */ int &MapFileSize, /* out */ int &JdbgFileSize)/* overload */;
extern PACKAGE bool __fastcall InsertDebugDataIntoExecutableFile(const AnsiString ExecutableFileName, const AnsiString MapFileName, /* out */ AnsiString &LinkerBugUnit, /* out */ int &MapFileSize, /* out */ int &JclDebugDataSize)/* overload */;
extern PACKAGE bool __fastcall InsertDebugDataIntoExecutableFile(const AnsiString ExecutableFileName, const AnsiString MapFileName, /* out */ AnsiString &LinkerBugUnit, /* out */ int &MapFileSize, /* out */ int &JclDebugDataSize, /* out */ int &LineNumberErrors)/* overload */;
extern PACKAGE bool __fastcall InsertDebugDataIntoExecutableFile(const AnsiString ExecutableFileName, TJclBinDebugGenerator* BinDebug, /* out */ AnsiString &LinkerBugUnit, /* out */ int &MapFileSize, /* out */ int &JclDebugDataSize)/* overload */;
extern PACKAGE bool __fastcall InsertDebugDataIntoExecutableFile(const AnsiString ExecutableFileName, TJclBinDebugGenerator* BinDebug, /* out */ AnsiString &LinkerBugUnit, /* out */ int &MapFileSize, /* out */ int &JclDebugDataSize, /* out */ int &LineNumberErrors)/* overload */;
extern PACKAGE void * __fastcall Caller(int Level = 0x0, bool FastStackWalk = false);
extern PACKAGE TJclLocationInfo __fastcall GetLocationInfo(const void * Addr)/* overload */;
extern PACKAGE bool __fastcall GetLocationInfo(const void * Addr, /* out */ TJclLocationInfo &Info)/* overload */;
extern PACKAGE AnsiString __fastcall GetLocationInfoStr(const void * Addr, bool IncludeModuleName = false, bool IncludeAddressOffset = false, bool IncludeStartProcLineOffset = false, bool IncludeVAddress = false);
extern PACKAGE bool __fastcall DebugInfoAvailable(const unsigned Module);
extern PACKAGE void __fastcall ClearLocationData(void);
extern PACKAGE AnsiString __fastcall FileByLevel(const int Level = 0x0);
extern PACKAGE AnsiString __fastcall ModuleByLevel(const int Level = 0x0);
extern PACKAGE AnsiString __fastcall ProcByLevel(const int Level = 0x0);
extern PACKAGE int __fastcall LineByLevel(const int Level = 0x0);
extern PACKAGE bool __fastcall MapByLevel(const int Level, AnsiString &File_, AnsiString &Module_, AnsiString &Proc_, int &Line_);
extern PACKAGE AnsiString __fastcall ExtractClassName(const AnsiString ProcedureName);
extern PACKAGE AnsiString __fastcall ExtractMethodName(const AnsiString ProcedureName);
extern PACKAGE AnsiString __fastcall __MODULE__(const int Level = 0x0);
extern PACKAGE AnsiString __fastcall __PROC__(const int Level = 0x0);
extern PACKAGE bool __fastcall __MAP__(const int Level, AnsiString &_File, AnsiString &_Module, AnsiString &_Proc, int &_Line);
extern PACKAGE AnsiString __fastcall FileOfAddr(const void * Addr);
extern PACKAGE AnsiString __fastcall ModuleOfAddr(const void * Addr);
extern PACKAGE AnsiString __fastcall ProcOfAddr(const void * Addr);
extern PACKAGE int __fastcall LineOfAddr(const void * Addr);
extern PACKAGE bool __fastcall MapOfAddr(const void * Addr, AnsiString &File_, AnsiString &Module_, AnsiString &Proc_, int &Line_);
extern PACKAGE AnsiString __fastcall __FILE_OF_ADDR__(const void * Addr);
extern PACKAGE AnsiString __fastcall __MODULE_OF_ADDR__(const void * Addr);
extern PACKAGE AnsiString __fastcall __PROC_OF_ADDR__(const void * Addr);
extern PACKAGE int __fastcall __LINE_OF_ADDR__(const void * Addr);
extern PACKAGE bool __fastcall __MAP_OF_ADDR__(const void * Addr, AnsiString &_File, AnsiString &_Module, AnsiString &_Proc, int &_Line);
extern PACKAGE bool __fastcall JclValidateModuleAddress(void * Addr);
extern PACKAGE TJclStackInfoList* __fastcall JclLastExceptStackList(void);
extern PACKAGE bool __fastcall JclLastExceptStackListToStrings(Classes::TStrings* Strings, bool IncludeModuleName = false, bool IncludeAddressOffset = false, bool IncludeStartProcLineOffset = false, bool IncludeVAddress = false);
extern PACKAGE TJclStackInfoList* __fastcall JclGetExceptStackList(unsigned ThreadID);
extern PACKAGE bool __fastcall JclGetExceptStackListToStrings(unsigned ThreadID, Classes::TStrings* Strings, bool IncludeModuleName = false, bool IncludeAddressOffset = false, bool IncludeStartProcLineOffset = false, bool IncludeVAddress = false);
extern PACKAGE TJclStackInfoList* __fastcall JclCreateStackList(bool Raw, unsigned AIgnoreLevels, void * FirstCaller)/* overload */;
extern PACKAGE TJclStackInfoList* __fastcall JclCreateStackList(bool Raw, unsigned AIgnoreLevels, void * FirstCaller, bool DelayedTrace)/* overload */;
extern PACKAGE TJclStackInfoList* __fastcall JclCreateStackList(bool Raw, unsigned AIgnoreLevels, void * FirstCaller, bool DelayedTrace, void * BaseOfStack)/* overload */;
extern PACKAGE TJclStackInfoList* __fastcall JclCreateStackList(bool Raw, unsigned AIgnoreLevels, void * FirstCaller, bool DelayedTrace, void * BaseOfStack, void * TopOfStack)/* overload */;
extern PACKAGE TJclStackInfoList* __fastcall JclCreateThreadStackTrace(bool Raw, const unsigned ThreadHandle);
extern PACKAGE TJclStackInfoList* __fastcall JclCreateThreadStackTraceFromID(bool Raw, unsigned ThreadID);
extern PACKAGE TJclExceptFrameList* __fastcall JclCreateExceptFrameList(int AIgnoreLevels);
extern PACKAGE TJclExceptFrameList* __fastcall JclLastExceptFrameList(void);
extern PACKAGE TJclExceptFrameList* __fastcall JclGetExceptFrameList(unsigned ThreadID);
extern PACKAGE void __fastcall AddIgnoredException(const TMetaClass* ExceptionClass);
extern PACKAGE void __fastcall AddIgnoredExceptionByName(const AnsiString AExceptionClassName);
extern PACKAGE void __fastcall RemoveIgnoredException(const TMetaClass* ExceptionClass);
extern PACKAGE void __fastcall RemoveIgnoredExceptionByName(const AnsiString AExceptionClassName);
extern PACKAGE bool __fastcall IsIgnoredException(const TMetaClass* ExceptionClass);
extern PACKAGE bool __fastcall JclStartExceptionTracking(void);
extern PACKAGE bool __fastcall JclStopExceptionTracking(void);
extern PACKAGE bool __fastcall JclExceptionTrackingActive(void);
extern PACKAGE bool __fastcall JclTrackExceptionsFromLibraries(void);
extern PACKAGE TJclDebugThreadList* __fastcall JclDebugThreadList(void);
extern PACKAGE bool __fastcall JclHookThreads(void);
extern PACKAGE bool __fastcall JclUnhookThreads(void);
extern PACKAGE bool __fastcall JclThreadsHooked(void);
extern PACKAGE bool __fastcall EnableCrashOnCtrlScroll(const bool Enable);
extern PACKAGE bool __fastcall IsDebuggerAttached(void);
extern PACKAGE bool __fastcall IsHandleValid(unsigned Handle);

}	/* namespace Jcldebug */
using namespace Jcldebug;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcldebug
