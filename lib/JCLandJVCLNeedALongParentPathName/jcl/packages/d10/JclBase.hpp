// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclbase.pas' rev: 10.00

#ifndef JclbaseHPP
#define JclbaseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclbase
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EJclError;
class PASCALIMPLEMENTATION EJclError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclInternalError;
class PASCALIMPLEMENTATION EJclInternalError : public EJclError 
{
	typedef EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclInternalError(const AnsiString Msg) : EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclInternalError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclInternalError(int Ident)/* overload */ : EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclInternalError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclInternalError(const AnsiString Msg, int AHelpContext) : EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclInternalError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclInternalError(int Ident, int AHelpContext)/* overload */ : EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclInternalError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclInternalError(void) { }
	#pragma option pop
	
};


typedef Extended Float;

typedef Extended *PFloat;

typedef int SizeInt;

typedef int *PSizeInt;

typedef void * *PPointer;

typedef Byte *PByte;

typedef Shortint Int8;

typedef short Int16;

typedef int Int32;

typedef Byte UInt8;

typedef Word UInt16;

typedef unsigned UInt32;

typedef unsigned *PCardinal;

typedef WideChar *PWideChar;

typedef WideChar * *PPWideChar;

typedef char * *PPAnsiChar;

typedef __int64 *PInt64;

typedef PInt64 *PPInt64;

typedef PPAnsiChar *PPPAnsiChar;

typedef __int64 *PLargeInteger;

typedef __int64 TLargeInteger;

typedef DynamicArray<Byte >  TBytes;

typedef Byte TJclByteArray[2147483647];

typedef Byte *PJclByteArray;

typedef void *TJclBytes;

typedef ULARGE_INTEGER  TJclULargeInteger;

typedef ULARGE_INTEGER *PJclULargeInteger;

typedef DynamicArray<Byte >  TDynByteArray;

typedef DynamicArray<Shortint >  TDynShortIntArray;

typedef DynamicArray<Word >  TDynWordArray;

typedef DynamicArray<short >  TDynSmallIntArray;

typedef DynamicArray<int >  TDynLongIntArray;

typedef DynamicArray<__int64 >  TDynInt64Array;

typedef DynamicArray<unsigned >  TDynCardinalArray;

typedef DynamicArray<int >  TDynIntegerArray;

typedef DynamicArray<int >  TDynSizeIntArray;

typedef DynamicArray<Extended >  TDynExtendedArray;

typedef DynamicArray<double >  TDynDoubleArray;

typedef DynamicArray<float >  TDynSingleArray;

typedef DynamicArray<Extended >  TDynFloatArray;

typedef DynamicArray<void * >  TDynPointerArray;

typedef DynamicArray<AnsiString >  TDynStringArray;

typedef DynamicArray<AnsiString >  TDynAnsiStringArray;

typedef DynamicArray<WideString >  TDynWideStringArray;

typedef DynamicArray<System::_di_IInterface >  TDynIInterfaceArray;

typedef DynamicArray<System::TObject* >  TDynObjectArray;

typedef DynamicArray<char >  TDynCharArray;

typedef DynamicArray<char >  TDynAnsiCharArray;

typedef DynamicArray<WideChar >  TDynWideCharArray;

typedef char *PUTF7;

typedef char UTF7;

typedef char *PUTF8;

typedef char UTF8;

typedef WideChar *PUTF16;

typedef WideChar UTF16;

typedef unsigned *PUTF32;

typedef unsigned UTF32;

typedef unsigned *PUCS4;

typedef unsigned UCS4;

typedef WideChar *PUCS2;

typedef WideChar UCS2;

typedef DynamicArray<WideChar >  TUCS2Array;

typedef DynamicArray<unsigned >  TUCS4Array;

typedef AnsiString TUTF8String;

typedef WideString TUTF16String;

typedef WideString TUCS2String;

typedef Set<char, 0, 255>  TSetOfAnsiChar;

typedef unsigned TJclAddr32;

typedef __int64 TJclAddr64;

typedef unsigned TJclAddr;

typedef unsigned *PJclAddr;

class DELPHICLASS EJclAddr64Exception;
class PASCALIMPLEMENTATION EJclAddr64Exception : public EJclError 
{
	typedef EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclAddr64Exception(const AnsiString Msg) : EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclAddr64Exception(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclAddr64Exception(int Ident)/* overload */ : EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclAddr64Exception(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclAddr64Exception(const AnsiString Msg, int AHelpContext) : EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclAddr64Exception(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclAddr64Exception(int Ident, int AHelpContext)/* overload */ : EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclAddr64Exception(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclAddr64Exception(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint JclVersionMajor = 0x2;
static const Shortint JclVersionMinor = 0x1;
static const Shortint JclVersionRelease = 0x1;
static const Word JclVersionBuild = 0xdd0;
static const int JclVersion = 0x2018dd0;
static const char NativeLineFeed = '\xa';
static const char NativeCarriageReturn = '\xd';
#define NativeCrLf "\r\n"
#define NativeLineBreak "\r\n"
#define HexPrefixPascal "$"
#define HexPrefixC "0x"
#define HexPrefix "0x"
extern PACKAGE Byte BOM_UTF16_LSB[2];
extern PACKAGE Byte BOM_UTF16_MSB[2];
extern PACKAGE Byte BOM_UTF8[3];
extern PACKAGE Byte BOM_UTF32_LSB[4];
extern PACKAGE Byte BOM_UTF32_MSB[4];
extern PACKAGE char AnsiReplacementCharacter;
extern PACKAGE unsigned UCS4ReplacementCharacter;
extern PACKAGE unsigned MaximumUCS2;
extern PACKAGE unsigned MaximumUTF16;
extern PACKAGE unsigned MaximumUCS4;
static const unsigned SurrogateHighStart = 0xd800;
static const unsigned SurrogateHighEnd = 0xdbff;
static const unsigned SurrogateLowStart = 0xdc00;
static const unsigned SurrogateLowEnd = 0xdfff;
static const char AWSuffix = '\x41';
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE void __fastcall MoveArray(TDynIInterfaceArray &List, int FromIndex, int ToIndex, int Count)/* overload */;
extern PACKAGE void __fastcall MoveArray(TDynStringArray &List, int FromIndex, int ToIndex, int Count)/* overload */;
extern PACKAGE void __fastcall MoveArray(TDynFloatArray &List, int FromIndex, int ToIndex, int Count)/* overload */;
extern PACKAGE void __fastcall MoveArray(TDynPointerArray &List, int FromIndex, int ToIndex, int Count)/* overload */;
extern PACKAGE void __fastcall MoveArray(TDynAnsiStringArray &List, int FromIndex, int ToIndex, int Count)/* overload */;
extern PACKAGE void __fastcall MoveArray(TDynWideStringArray &List, int FromIndex, int ToIndex, int Count)/* overload */;
extern PACKAGE void __fastcall MoveArray(TDynObjectArray &List, int FromIndex, int ToIndex, int Count)/* overload */;
extern PACKAGE void __fastcall MoveArray(TDynSingleArray &List, int FromIndex, int ToIndex, int Count)/* overload */;
extern PACKAGE void __fastcall MoveArray(TDynDoubleArray &List, int FromIndex, int ToIndex, int Count)/* overload */;
extern PACKAGE void __fastcall MoveArray(TDynExtendedArray &List, int FromIndex, int ToIndex, int Count)/* overload */;
extern PACKAGE void __fastcall MoveArray(TDynIntegerArray &List, int FromIndex, int ToIndex, int Count)/* overload */;
extern PACKAGE void __fastcall MoveArray(TDynCardinalArray &List, int FromIndex, int ToIndex, int Count)/* overload */;
extern PACKAGE void __fastcall MoveArray(TDynInt64Array &List, int FromIndex, int ToIndex, int Count)/* overload */;
extern PACKAGE void __fastcall MoveArray(TDynSizeIntArray &List, int FromIndex, int ToIndex, int Count)/* overload */;
extern PACKAGE void __fastcall MoveChar(const AnsiString Source, int FromIndex, AnsiString &Dest, int ToIndex, int Count)/* overload */;
extern PACKAGE int __fastcall AnsiByteArrayStringLen(TBytes Data);
extern PACKAGE TBytes __fastcall StringToAnsiByteArray(const AnsiString S);
extern PACKAGE AnsiString __fastcall AnsiByteArrayToString(const TBytes Data, int Count);
extern PACKAGE TBytes __fastcall BytesOf(const AnsiString Value)/* overload */;
extern PACKAGE TBytes __fastcall BytesOf(const WideString Value)/* overload */;
extern PACKAGE TBytes __fastcall BytesOf(const WideChar Value)/* overload */;
extern PACKAGE TBytes __fastcall BytesOf(const char Value)/* overload */;
extern PACKAGE AnsiString __fastcall StringOf(Byte const * Bytes, const int Bytes_Size)/* overload */;
extern PACKAGE AnsiString __fastcall StringOf(const void * Bytes, unsigned Size)/* overload */;
extern PACKAGE void __fastcall I64ToCardinals(__int64 I, /* out */ unsigned &LowPart, /* out */ unsigned &HighPart);
extern PACKAGE void __fastcall CardinalsToI64(/* out */ __int64 &I, const unsigned LowPart, const unsigned HighPart);
extern PACKAGE unsigned __fastcall Addr64ToAddr32(const __int64 Value);
extern PACKAGE __int64 __fastcall Addr32ToAddr64(const unsigned Value);

}	/* namespace Jclbase */
using namespace Jclbase;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclbase
