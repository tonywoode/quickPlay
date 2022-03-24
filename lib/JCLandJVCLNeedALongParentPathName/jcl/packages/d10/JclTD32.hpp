// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcltd32.pas' rev: 10.00

#ifndef Jcltd32HPP
#define Jcltd32HPP

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
#include <Jclpeimage.hpp>	// Pascal unit
#include <Jclfileutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jcltd32
{
//-- type declarations -------------------------------------------------------
struct TJclTD32FileSignature;
typedef TJclTD32FileSignature *PJclTD32FileSignature;

#pragma pack(push,1)
struct TJclTD32FileSignature
{
	
public:
	unsigned Signature;
	unsigned Offset;
} ;
#pragma pack(pop)

struct TDirectoryEntry;
typedef TDirectoryEntry *PDirectoryEntry;

#pragma pack(push,1)
struct TDirectoryEntry
{
	
public:
	Word SubsectionType;
	Word ModuleIndex;
	unsigned Offset;
	unsigned Size;
} ;
#pragma pack(pop)

struct TDirectoryHeader;
typedef TDirectoryHeader *PDirectoryHeader;

#pragma pack(push,1)
struct TDirectoryHeader
{
	
public:
	Word Size;
	Word DirEntrySize;
	unsigned DirEntryCount;
	unsigned lfoNextDir;
	unsigned Flags;
	TDirectoryEntry DirEntries[1];
} ;
#pragma pack(pop)

struct TSegmentInfo;
typedef TSegmentInfo *PSegmentInfo;

#pragma pack(push,1)
struct TSegmentInfo
{
	
public:
	Word Segment;
	Word Flags;
	unsigned Offset;
	unsigned Size;
} ;
#pragma pack(pop)

typedef TSegmentInfo TSegmentInfoArray[32768];

typedef TSegmentInfo *PSegmentInfoArray;

struct TModuleInfo;
typedef TModuleInfo *PModuleInfo;

#pragma pack(push,1)
struct TModuleInfo
{
	
public:
	Word OverlayNumber;
	Word LibraryIndex;
	Word SegmentCount;
	Word DebuggingStyle;
	unsigned NameIndex;
	unsigned TimeStamp;
	unsigned Reserved[3];
	TSegmentInfo Segments[1];
} ;
#pragma pack(pop)

struct TLineMappingEntry;
typedef TLineMappingEntry *PLineMappingEntry;

#pragma pack(push,1)
struct TLineMappingEntry
{
	
public:
	Word SegmentIndex;
	Word PairCount;
	unsigned Offsets[1];
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct TOffsetPair
{
	
public:
	unsigned StartOffset;
	unsigned EndOffset;
} ;
#pragma pack(pop)

typedef TOffsetPair TOffsetPairArray[32768];

typedef TOffsetPair *POffsetPairArray;

struct TSourceFileEntry;
typedef TSourceFileEntry *PSourceFileEntry;

#pragma pack(push,1)
struct TSourceFileEntry
{
	
public:
	Word SegmentCount;
	unsigned NameIndex;
	unsigned BaseSrcLines[1];
} ;
#pragma pack(pop)

struct TSourceModuleInfo;
typedef TSourceModuleInfo *PSourceModuleInfo;

#pragma pack(push,1)
struct TSourceModuleInfo
{
	
public:
	Word FileCount;
	Word SegmentCount;
	unsigned BaseSrcFiles[1];
} ;
#pragma pack(pop)

struct TGlobalTypeInfo;
typedef TGlobalTypeInfo *PGlobalTypeInfo;

#pragma pack(push,1)
struct TGlobalTypeInfo
{
	
public:
	unsigned Count;
	unsigned Offsets[1];
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct TSymbolProcInfo
{
	
public:
	unsigned pParent;
	unsigned pEnd;
	unsigned pNext;
	unsigned Size;
	unsigned DebugStart;
	unsigned DebugEnd;
	unsigned Offset;
	Word Segment;
	unsigned ProcType;
	Byte NearFar;
	Byte Reserved;
	unsigned NameIndex;
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct TSymbolObjNameInfo
{
	
public:
	unsigned Signature;
	unsigned NameIndex;
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct TSymbolDataInfo
{
	
public:
	unsigned Offset;
	Word Segment;
	Word Reserved;
	unsigned TypeIndex;
	unsigned NameIndex;
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct TSymbolWithInfo
{
	
public:
	unsigned pParent;
	unsigned pEnd;
	unsigned Size;
	unsigned Offset;
	Word Segment;
	Word Reserved;
	unsigned NameIndex;
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct TSymbolLabelInfo
{
	
public:
	unsigned Offset;
	Word Segment;
	Byte NearFar;
	Byte Reserved;
	unsigned NameIndex;
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct TSymbolConstantInfo
{
	
public:
	unsigned TypeIndex;
	unsigned NameIndex;
	unsigned Reserved;
	unsigned Value;
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct TSymbolUdtInfo
{
	
public:
	unsigned TypeIndex;
	Word Properties;
	unsigned NameIndex;
	unsigned Reserved;
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct TSymbolVftPathInfo
{
	
public:
	unsigned Offset;
	Word Segment;
	Word Reserved;
	unsigned RootIndex;
	unsigned PathIndex;
} ;
#pragma pack(pop)

struct TSymbolInfo;
typedef TSymbolInfo *PSymbolInfo;

#pragma pack(push,1)
struct TSymbolInfo
{
	
public:
	Word Size;
	Word SymbolType;
	union
	{
		struct 
		{
			TSymbolVftPathInfo VftPath;
			
		};
		struct 
		{
			TSymbolUdtInfo Udt;
			
		};
		struct 
		{
			TSymbolConstantInfo Constant;
			
		};
		struct 
		{
			TSymbolLabelInfo Label32;
			
		};
		struct 
		{
			TSymbolWithInfo With32;
			
		};
		struct 
		{
			TSymbolDataInfo Data;
			
		};
		struct 
		{
			TSymbolObjNameInfo ObjName;
			
		};
		struct 
		{
			TSymbolProcInfo Proc;
			
		};
		
	};
} ;
#pragma pack(pop)

struct TSymbolInfos;
typedef TSymbolInfos *PSymbolInfos;

#pragma pack(push,1)
struct TSymbolInfos
{
	
public:
	unsigned Signature;
	TSymbolInfo Symbols[1];
} ;
#pragma pack(pop)

class DELPHICLASS TJclTD32ModuleInfo;
class PASCALIMPLEMENTATION TJclTD32ModuleInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TSegmentInfo operator[](int Idx) { return Segment[Idx]; }
	
private:
	unsigned FNameIndex;
	TSegmentInfo *FSegments;
	int FSegmentCount;
	TSegmentInfo __fastcall GetSegment(const int Idx);
	
public:
	__fastcall TJclTD32ModuleInfo(PModuleInfo pModInfo);
	__property unsigned NameIndex = {read=FNameIndex, nodefault};
	__property int SegmentCount = {read=FSegmentCount, nodefault};
	__property TSegmentInfo Segment[int Idx] = {read=GetSegment/*, default*/};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32ModuleInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTD32LineInfo;
class PASCALIMPLEMENTATION TJclTD32LineInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	unsigned FLineNo;
	unsigned FOffset;
	
public:
	__fastcall TJclTD32LineInfo(unsigned ALineNo, unsigned AOffset);
	__property unsigned LineNo = {read=FLineNo, nodefault};
	__property unsigned Offset = {read=FOffset, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32LineInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTD32SourceModuleInfo;
class PASCALIMPLEMENTATION TJclTD32SourceModuleInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TJclTD32LineInfo* operator[](int Idx) { return Line[Idx]; }
	
private:
	Contnrs::TObjectList* FLines;
	TOffsetPair *FSegments;
	int FSegmentCount;
	unsigned FNameIndex;
	TJclTD32LineInfo* __fastcall GetLine(const int Idx);
	int __fastcall GetLineCount(void);
	TOffsetPair __fastcall GetSegment(const int Idx);
	
public:
	__fastcall TJclTD32SourceModuleInfo(PSourceFileEntry pSrcFile, unsigned Base);
	__fastcall virtual ~TJclTD32SourceModuleInfo(void);
	bool __fastcall FindLine(const unsigned AAddr, /* out */ TJclTD32LineInfo* &ALine);
	__property unsigned NameIndex = {read=FNameIndex, nodefault};
	__property int LineCount = {read=GetLineCount, nodefault};
	__property TJclTD32LineInfo* Line[int Idx] = {read=GetLine/*, default*/};
	__property int SegmentCount = {read=FSegmentCount, nodefault};
	__property TOffsetPair Segment[int Idx] = {read=GetSegment};
};


class DELPHICLASS TJclTD32SymbolInfo;
class PASCALIMPLEMENTATION TJclTD32SymbolInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Word FSymbolType;
	
public:
	__fastcall virtual TJclTD32SymbolInfo(PSymbolInfo pSymInfo);
	__property Word SymbolType = {read=FSymbolType, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32SymbolInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTD32ProcSymbolInfo;
class PASCALIMPLEMENTATION TJclTD32ProcSymbolInfo : public TJclTD32SymbolInfo 
{
	typedef TJclTD32SymbolInfo inherited;
	
private:
	unsigned FNameIndex;
	unsigned FOffset;
	unsigned FSize;
	
public:
	__fastcall virtual TJclTD32ProcSymbolInfo(PSymbolInfo pSymInfo);
	__property unsigned NameIndex = {read=FNameIndex, nodefault};
	__property unsigned Offset = {read=FOffset, nodefault};
	__property unsigned Size = {read=FSize, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32ProcSymbolInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTD32LocalProcSymbolInfo;
class PASCALIMPLEMENTATION TJclTD32LocalProcSymbolInfo : public TJclTD32ProcSymbolInfo 
{
	typedef TJclTD32ProcSymbolInfo inherited;
	
public:
	#pragma option push -w-inl
	/* TJclTD32ProcSymbolInfo.Create */ inline __fastcall virtual TJclTD32LocalProcSymbolInfo(PSymbolInfo pSymInfo) : TJclTD32ProcSymbolInfo(pSymInfo) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32LocalProcSymbolInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTD32GlobalProcSymbolInfo;
class PASCALIMPLEMENTATION TJclTD32GlobalProcSymbolInfo : public TJclTD32ProcSymbolInfo 
{
	typedef TJclTD32ProcSymbolInfo inherited;
	
public:
	#pragma option push -w-inl
	/* TJclTD32ProcSymbolInfo.Create */ inline __fastcall virtual TJclTD32GlobalProcSymbolInfo(PSymbolInfo pSymInfo) : TJclTD32ProcSymbolInfo(pSymInfo) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32GlobalProcSymbolInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTD32ObjNameSymbolInfo;
class PASCALIMPLEMENTATION TJclTD32ObjNameSymbolInfo : public TJclTD32SymbolInfo 
{
	typedef TJclTD32SymbolInfo inherited;
	
private:
	unsigned FSignature;
	unsigned FNameIndex;
	
public:
	__fastcall virtual TJclTD32ObjNameSymbolInfo(PSymbolInfo pSymInfo);
	__property unsigned NameIndex = {read=FNameIndex, nodefault};
	__property unsigned Signature = {read=FSignature, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32ObjNameSymbolInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTD32DataSymbolInfo;
class PASCALIMPLEMENTATION TJclTD32DataSymbolInfo : public TJclTD32SymbolInfo 
{
	typedef TJclTD32SymbolInfo inherited;
	
private:
	unsigned FOffset;
	unsigned FTypeIndex;
	unsigned FNameIndex;
	
public:
	__fastcall virtual TJclTD32DataSymbolInfo(PSymbolInfo pSymInfo);
	__property unsigned NameIndex = {read=FNameIndex, nodefault};
	__property unsigned TypeIndex = {read=FTypeIndex, nodefault};
	__property unsigned Offset = {read=FOffset, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32DataSymbolInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTD32LDataSymbolInfo;
class PASCALIMPLEMENTATION TJclTD32LDataSymbolInfo : public TJclTD32DataSymbolInfo 
{
	typedef TJclTD32DataSymbolInfo inherited;
	
public:
	#pragma option push -w-inl
	/* TJclTD32DataSymbolInfo.Create */ inline __fastcall virtual TJclTD32LDataSymbolInfo(PSymbolInfo pSymInfo) : TJclTD32DataSymbolInfo(pSymInfo) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32LDataSymbolInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTD32GDataSymbolInfo;
class PASCALIMPLEMENTATION TJclTD32GDataSymbolInfo : public TJclTD32DataSymbolInfo 
{
	typedef TJclTD32DataSymbolInfo inherited;
	
public:
	#pragma option push -w-inl
	/* TJclTD32DataSymbolInfo.Create */ inline __fastcall virtual TJclTD32GDataSymbolInfo(PSymbolInfo pSymInfo) : TJclTD32DataSymbolInfo(pSymInfo) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32GDataSymbolInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTD32PublicSymbolInfo;
class PASCALIMPLEMENTATION TJclTD32PublicSymbolInfo : public TJclTD32DataSymbolInfo 
{
	typedef TJclTD32DataSymbolInfo inherited;
	
public:
	#pragma option push -w-inl
	/* TJclTD32DataSymbolInfo.Create */ inline __fastcall virtual TJclTD32PublicSymbolInfo(PSymbolInfo pSymInfo) : TJclTD32DataSymbolInfo(pSymInfo) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32PublicSymbolInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTD32WithSymbolInfo;
class PASCALIMPLEMENTATION TJclTD32WithSymbolInfo : public TJclTD32SymbolInfo 
{
	typedef TJclTD32SymbolInfo inherited;
	
private:
	unsigned FOffset;
	unsigned FSize;
	unsigned FNameIndex;
	
public:
	__fastcall virtual TJclTD32WithSymbolInfo(PSymbolInfo pSymInfo);
	__property unsigned NameIndex = {read=FNameIndex, nodefault};
	__property unsigned Offset = {read=FOffset, nodefault};
	__property unsigned Size = {read=FSize, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32WithSymbolInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTD32LabelSymbolInfo;
class PASCALIMPLEMENTATION TJclTD32LabelSymbolInfo : public TJclTD32SymbolInfo 
{
	typedef TJclTD32SymbolInfo inherited;
	
private:
	unsigned FOffset;
	unsigned FNameIndex;
	
public:
	__fastcall virtual TJclTD32LabelSymbolInfo(PSymbolInfo pSymInfo);
	__property unsigned NameIndex = {read=FNameIndex, nodefault};
	__property unsigned Offset = {read=FOffset, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32LabelSymbolInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTD32ConstantSymbolInfo;
class PASCALIMPLEMENTATION TJclTD32ConstantSymbolInfo : public TJclTD32SymbolInfo 
{
	typedef TJclTD32SymbolInfo inherited;
	
private:
	unsigned FValue;
	unsigned FTypeIndex;
	unsigned FNameIndex;
	
public:
	__fastcall virtual TJclTD32ConstantSymbolInfo(PSymbolInfo pSymInfo);
	__property unsigned NameIndex = {read=FNameIndex, nodefault};
	__property unsigned TypeIndex = {read=FTypeIndex, nodefault};
	__property unsigned Value = {read=FValue, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32ConstantSymbolInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTD32UdtSymbolInfo;
class PASCALIMPLEMENTATION TJclTD32UdtSymbolInfo : public TJclTD32SymbolInfo 
{
	typedef TJclTD32SymbolInfo inherited;
	
private:
	unsigned FTypeIndex;
	unsigned FNameIndex;
	Word FProperties;
	
public:
	__fastcall virtual TJclTD32UdtSymbolInfo(PSymbolInfo pSymInfo);
	__property unsigned NameIndex = {read=FNameIndex, nodefault};
	__property unsigned TypeIndex = {read=FTypeIndex, nodefault};
	__property Word Properties = {read=FProperties, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32UdtSymbolInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTD32VftPathSymbolInfo;
class PASCALIMPLEMENTATION TJclTD32VftPathSymbolInfo : public TJclTD32SymbolInfo 
{
	typedef TJclTD32SymbolInfo inherited;
	
private:
	unsigned FRootIndex;
	unsigned FPathIndex;
	unsigned FOffset;
	
public:
	__fastcall virtual TJclTD32VftPathSymbolInfo(PSymbolInfo pSymInfo);
	__property unsigned RootIndex = {read=FRootIndex, nodefault};
	__property unsigned PathIndex = {read=FPathIndex, nodefault};
	__property unsigned Offset = {read=FOffset, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32VftPathSymbolInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTD32InfoParser;
class PASCALIMPLEMENTATION TJclTD32InfoParser : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	void *FBase;
	Classes::TCustomMemoryStream* FData;
	Classes::TList* FNames;
	Contnrs::TObjectList* FModules;
	Contnrs::TObjectList* FSourceModules;
	Contnrs::TObjectList* FSymbols;
	Classes::TList* FProcSymbols;
	bool FValidData;
	AnsiString __fastcall GetName(const int Idx);
	int __fastcall GetNameCount(void);
	TJclTD32SymbolInfo* __fastcall GetSymbol(const int Idx);
	int __fastcall GetSymbolCount(void);
	TJclTD32ProcSymbolInfo* __fastcall GetProcSymbol(const int Idx);
	int __fastcall GetProcSymbolCount(void);
	TJclTD32ModuleInfo* __fastcall GetModule(const int Idx);
	int __fastcall GetModuleCount(void);
	TJclTD32SourceModuleInfo* __fastcall GetSourceModule(const int Idx);
	int __fastcall GetSourceModuleCount(void);
	
protected:
	void __fastcall Analyse(void);
	virtual void __fastcall AnalyseNames(const void * pSubsection, const unsigned Size);
	virtual void __fastcall AnalyseGlobalTypes(const void * pTypes, const unsigned Size);
	virtual void __fastcall AnalyseAlignSymbols(PSymbolInfos pSymbols, const unsigned Size);
	virtual void __fastcall AnalyseModules(PModuleInfo pModInfo, const unsigned Size);
	virtual void __fastcall AnalyseSourceModules(PSourceModuleInfo pSrcModInfo, const unsigned Size);
	virtual void __fastcall AnalyseUnknownSubSection(const void * pSubsection, const unsigned Size);
	void * __fastcall LfaToVa(unsigned Lfa);
	
public:
	__fastcall TJclTD32InfoParser(const Classes::TCustomMemoryStream* ATD32Data);
	__fastcall virtual ~TJclTD32InfoParser(void);
	bool __fastcall FindModule(const unsigned AAddr, /* out */ TJclTD32ModuleInfo* &AMod);
	bool __fastcall FindSourceModule(const unsigned AAddr, /* out */ TJclTD32SourceModuleInfo* &ASrcMod);
	bool __fastcall FindProc(const unsigned AAddr, /* out */ TJclTD32ProcSymbolInfo* &AProc);
	/*         class method */ static bool __fastcall IsTD32Sign(TMetaClass* vmt, const TJclTD32FileSignature &Sign);
	/*         class method */ static bool __fastcall IsTD32DebugInfoValid(TMetaClass* vmt, const void * DebugData, const unsigned DebugDataSize);
	__property Classes::TCustomMemoryStream* Data = {read=FData};
	__property AnsiString Names[int Idx] = {read=GetName};
	__property int NameCount = {read=GetNameCount, nodefault};
	__property TJclTD32SymbolInfo* Symbols[int Idx] = {read=GetSymbol};
	__property int SymbolCount = {read=GetSymbolCount, nodefault};
	__property TJclTD32ProcSymbolInfo* ProcSymbols[int Idx] = {read=GetProcSymbol};
	__property int ProcSymbolCount = {read=GetProcSymbolCount, nodefault};
	__property TJclTD32ModuleInfo* Modules[int Idx] = {read=GetModule};
	__property int ModuleCount = {read=GetModuleCount, nodefault};
	__property TJclTD32SourceModuleInfo* SourceModules[int Idx] = {read=GetSourceModule};
	__property int SourceModuleCount = {read=GetSourceModuleCount, nodefault};
	__property bool ValidData = {read=FValidData, nodefault};
};


class DELPHICLASS TJclTD32InfoScanner;
class PASCALIMPLEMENTATION TJclTD32InfoScanner : public TJclTD32InfoParser 
{
	typedef TJclTD32InfoParser inherited;
	
public:
	int __fastcall LineNumberFromAddr(unsigned AAddr, /* out */ int &Offset)/* overload */;
	int __fastcall LineNumberFromAddr(unsigned AAddr)/* overload */;
	AnsiString __fastcall ProcNameFromAddr(unsigned AAddr)/* overload */;
	AnsiString __fastcall ProcNameFromAddr(unsigned AAddr, /* out */ int &Offset)/* overload */;
	AnsiString __fastcall ModuleNameFromAddr(unsigned AAddr);
	AnsiString __fastcall SourceNameFromAddr(unsigned AAddr);
public:
	#pragma option push -w-inl
	/* TJclTD32InfoParser.Create */ inline __fastcall TJclTD32InfoScanner(const Classes::TCustomMemoryStream* ATD32Data) : TJclTD32InfoParser(ATD32Data) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclTD32InfoParser.Destroy */ inline __fastcall virtual ~TJclTD32InfoScanner(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclPeBorTD32Image;
class PASCALIMPLEMENTATION TJclPeBorTD32Image : public Jclpeimage::TJclPeBorImage 
{
	typedef Jclpeimage::TJclPeBorImage inherited;
	
private:
	bool FIsTD32DebugPresent;
	Classes::TCustomMemoryStream* FTD32DebugData;
	TJclTD32InfoScanner* FTD32Scanner;
	
protected:
	DYNAMIC void __fastcall AfterOpen(void);
	DYNAMIC void __fastcall Clear(void);
	void __fastcall ClearDebugData(void);
	void __fastcall CheckDebugData(void);
	bool __fastcall IsDebugInfoInImage(Classes::TCustomMemoryStream* &DataStream);
	bool __fastcall IsDebugInfoInTds(Classes::TCustomMemoryStream* &DataStream);
	
public:
	__property bool IsTD32DebugPresent = {read=FIsTD32DebugPresent, nodefault};
	__property Classes::TCustomMemoryStream* TD32DebugData = {read=FTD32DebugData};
	__property TJclTD32InfoScanner* TD32Scanner = {read=FTD32Scanner};
public:
	#pragma option push -w-inl
	/* TJclPeBorImage.Create */ inline __fastcall virtual TJclPeBorTD32Image(bool ANoExceptions) : Jclpeimage::TJclPeBorImage(ANoExceptions) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclPeBorImage.Destroy */ inline __fastcall virtual ~TJclPeBorTD32Image(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jcltd32 */
using namespace Jcltd32;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcltd32
