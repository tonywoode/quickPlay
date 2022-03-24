// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclstrings.pas' rev: 10.00

#ifndef JclstringsHPP
#define JclstringsHPP

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
#include <Jclansistrings.hpp>	// Pascal unit
#include <Jclwidestrings.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclstrings
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EJclStringError;
class PASCALIMPLEMENTATION EJclStringError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclStringError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclStringError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclStringError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclStringError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclStringError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclStringError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclStringError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclStringError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclStringError(void) { }
	#pragma option pop
	
};


typedef bool __fastcall (*TCharValidator)(const char C);

typedef char * *PCharVector;

typedef char *PMultiSz;

typedef char *PAnsiMultiSz;

typedef WideChar *PWideMultiSz;

typedef TStrings TAnsiStrings;
;

typedef TJclWideStrings TWideStrings;
;

typedef TStringList TAnsiStringList;
;

typedef TJclWideStringList TWideStringList;
;

class DELPHICLASS FormatException;
class PASCALIMPLEMENTATION FormatException : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall FormatException(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall FormatException(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall FormatException(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall FormatException(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall FormatException(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall FormatException(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall FormatException(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall FormatException(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~FormatException(void) { }
	#pragma option pop
	
};


class DELPHICLASS ArgumentException;
class PASCALIMPLEMENTATION ArgumentException : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ArgumentException(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ArgumentException(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ArgumentException(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ArgumentException(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ArgumentException(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ArgumentException(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ArgumentException(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ArgumentException(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ArgumentException(void) { }
	#pragma option pop
	
};


class DELPHICLASS ArgumentNullException;
class PASCALIMPLEMENTATION ArgumentNullException : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ArgumentNullException(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ArgumentNullException(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ArgumentNullException(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ArgumentNullException(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ArgumentNullException(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ArgumentNullException(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ArgumentNullException(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ArgumentNullException(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ArgumentNullException(void) { }
	#pragma option pop
	
};


class DELPHICLASS ArgumentOutOfRangeException;
class PASCALIMPLEMENTATION ArgumentOutOfRangeException : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ArgumentOutOfRangeException(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ArgumentOutOfRangeException(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ArgumentOutOfRangeException(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ArgumentOutOfRangeException(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ArgumentOutOfRangeException(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ArgumentOutOfRangeException(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ArgumentOutOfRangeException(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ArgumentOutOfRangeException(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ArgumentOutOfRangeException(void) { }
	#pragma option pop
	
};


__interface IToString;
typedef System::DelphiInterface<IToString> _di_IToString;
__interface  INTERFACE_UUID("{C4ABABB4-1029-46E7-B5FA-99800F130C05}") IToString  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall ToString(void) = 0 ;
};

typedef DynamicArray<char >  TCharDynArray;

class DELPHICLASS TJclStringBuilder;
class PASCALIMPLEMENTATION TJclStringBuilder : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	char operator[](int Index) { return __Chars__[Index]; }
	
private:
	DynamicArray<char >  FChars;
	int FLength;
	int FMaxCapacity;
	int __fastcall GetCapacity(void);
	void __fastcall SetCapacity(const int Value);
	char __fastcall GetChars(int Index);
	void __fastcall SetChars(int Index, const char Value);
	void __fastcall Set_Length(const int Value);
	
protected:
	TJclStringBuilder* __fastcall AppendPChar(char * Value, int Count, int RepeatCount = 0x1);
	TJclStringBuilder* __fastcall InsertPChar(int Index, char * Value, int Count, int RepeatCount = 0x1);
	
public:
	__fastcall TJclStringBuilder(const AnsiString Value, int Capacity)/* overload */;
	__fastcall TJclStringBuilder(int Capacity, int MaxCapacity)/* overload */;
	__fastcall TJclStringBuilder(const AnsiString Value, int StartIndex, int Length, int Capacity)/* overload */;
	TJclStringBuilder* __fastcall Append(const AnsiString Value)/* overload */;
	TJclStringBuilder* __fastcall Append(const AnsiString Value, int StartIndex, int Length)/* overload */;
	TJclStringBuilder* __fastcall Append(bool Value)/* overload */;
	TJclStringBuilder* __fastcall Append(char Value, int RepeatCount = 0x1)/* overload */;
	TJclStringBuilder* __fastcall Append(char const * Value, const int Value_Size)/* overload */;
	TJclStringBuilder* __fastcall Append(char const * Value, const int Value_Size, int StartIndex, int Length)/* overload */;
	TJclStringBuilder* __fastcall Append(unsigned Value)/* overload */;
	TJclStringBuilder* __fastcall Append(int Value)/* overload */;
	TJclStringBuilder* __fastcall Append(double Value)/* overload */;
	TJclStringBuilder* __fastcall Append(__int64 Value)/* overload */;
	TJclStringBuilder* __fastcall Append(System::TObject* Obj)/* overload */;
	TJclStringBuilder* __fastcall AppendFormat(const AnsiString Fmt, System::TVarRec const * Args, const int Args_Size)/* overload */;
	TJclStringBuilder* __fastcall AppendFormat(const AnsiString Fmt, const Variant &Arg0)/* overload */;
	TJclStringBuilder* __fastcall AppendFormat(const AnsiString Fmt, const Variant &Arg0, const Variant &Arg1)/* overload */;
	TJclStringBuilder* __fastcall AppendFormat(const AnsiString Fmt, const Variant &Arg0, const Variant &Arg1, const Variant &Arg2)/* overload */;
	TJclStringBuilder* __fastcall Insert(int Index, const AnsiString Value, int Count = 0x1)/* overload */;
	TJclStringBuilder* __fastcall Insert(int Index, bool Value)/* overload */;
	TJclStringBuilder* __fastcall Insert(int Index, char const * Value, const int Value_Size)/* overload */;
	TJclStringBuilder* __fastcall Insert(int Index, char const * Value, const int Value_Size, int StartIndex, int Length)/* overload */;
	TJclStringBuilder* __fastcall Insert(int Index, unsigned Value)/* overload */;
	TJclStringBuilder* __fastcall Insert(int Index, int Value)/* overload */;
	TJclStringBuilder* __fastcall Insert(int Index, double Value)/* overload */;
	TJclStringBuilder* __fastcall Insert(int Index, __int64 Value)/* overload */;
	TJclStringBuilder* __fastcall Insert(int Index, System::TObject* Obj)/* overload */;
	TJclStringBuilder* __fastcall Replace(char OldChar, char NewChar, int StartIndex = 0x0, int Count = 0xffffffff)/* overload */;
	TJclStringBuilder* __fastcall Replace(AnsiString OldValue, AnsiString NewValue, int StartIndex = 0x0, int Count = 0xffffffff)/* overload */;
	TJclStringBuilder* __fastcall Remove(int StartIndex, int Length);
	int __fastcall EnsureCapacity(int Capacity);
	AnsiString __fastcall ToString();
	__property char __Chars__[int Index] = {read=GetChars, write=SetChars/*, default*/};
	__property TCharDynArray Chars = {read=FChars};
	__property int Length = {read=FLength, write=Set_Length, nodefault};
	__property int Capacity = {read=GetCapacity, write=SetCapacity, nodefault};
	__property int MaxCapacity = {read=FMaxCapacity, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclStringBuilder(void) { }
	#pragma option pop
	
private:
	void *__IToString;	/* Jclstrings::IToString */
	
public:
	operator IToString*(void) { return (IToString*)&__IToString; }
	
};


typedef TJclStringBuilder TStringBuilder;
;

class DELPHICLASS TJclTabSet;
class PASCALIMPLEMENTATION TJclTabSet : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	int operator[](int Index) { return TabStops[Index]; }
	
private:
	System::TObject* FData;
	int __fastcall GetCount(void);
	int __fastcall GetStops(int Index);
	int __fastcall GetTabWidth(void);
	bool __fastcall GetZeroBased(void);
	void __fastcall SetStops(int Index, int Value);
	void __fastcall SetTabWidth(int Value);
	void __fastcall SetZeroBased(bool Value);
	
protected:
	int __fastcall FindStop(int Column);
	Jclbase::TDynSizeIntArray __fastcall InternalTabStops();
	int __fastcall InternalTabWidth(void);
	void __fastcall RemoveAt(int Index);
	
public:
	__fastcall TJclTabSet(void)/* overload */;
	__fastcall TJclTabSet(System::TObject* Data)/* overload */;
	__fastcall TJclTabSet(int TabWidth)/* overload */;
	__fastcall TJclTabSet(int const * Tabstops, const int Tabstops_Size, bool ZeroBased)/* overload */;
	__fastcall TJclTabSet(int const * Tabstops, const int Tabstops_Size, bool ZeroBased, int TabWidth)/* overload */;
	__fastcall virtual ~TJclTabSet(void);
	TJclTabSet* __fastcall Clone(void);
	TJclTabSet* __fastcall NewReference(void);
	int __fastcall Add(int Column);
	int __fastcall Delete(int Column);
	AnsiString __fastcall Expand(const AnsiString S)/* overload */;
	AnsiString __fastcall Expand(const AnsiString S, int Column)/* overload */;
	void __fastcall OptimalFillInfo(int StartColumn, int TargetColumn, /* out */ int &TabsNeeded, /* out */ int &SpacesNeeded);
	AnsiString __fastcall Optimize(const AnsiString S)/* overload */;
	AnsiString __fastcall Optimize(const AnsiString S, int Column)/* overload */;
	int __fastcall StartColumn(void);
	int __fastcall TabFrom(int Column);
	int __fastcall UpdatePosition(const AnsiString S)/* overload */;
	int __fastcall UpdatePosition(const AnsiString S, int Column)/* overload */;
	int __fastcall UpdatePosition(const AnsiString S, int &Column, int &Line)/* overload */;
	AnsiString __fastcall ToString()/* overload */;
	AnsiString __fastcall ToString(int FormattingOptions)/* overload */;
	/*         class method */ static TJclTabSet* __fastcall FromString(const AnsiString S);
	__property int ActualTabWidth = {read=InternalTabWidth, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property int TabStops[int Index] = {read=GetStops, write=SetStops/*, default*/};
	__property int TabWidth = {read=GetTabWidth, write=SetTabWidth, nodefault};
	__property bool ZeroBased = {read=GetZeroBased, write=SetZeroBased, nodefault};
private:
	void *__IToString;	/* Jclstrings::IToString */
	
public:
	operator IToString*(void) { return (IToString*)&__IToString; }
	
};


class DELPHICLASS NullReferenceException;
class PASCALIMPLEMENTATION NullReferenceException : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	__fastcall NullReferenceException(void)/* overload */;
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall NullReferenceException(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall NullReferenceException(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall NullReferenceException(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall NullReferenceException(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall NullReferenceException(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall NullReferenceException(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall NullReferenceException(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~NullReferenceException(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const char NativeNull = '\x0';
static const char NativeSoh = '\x1';
static const char NativeStx = '\x2';
static const char NativeEtx = '\x3';
static const char NativeEot = '\x4';
static const char NativeEnq = '\x5';
static const char NativeAck = '\x6';
static const char NativeBell = '\x7';
static const char NativeBackspace = '\x8';
static const char NativeTab = '\x9';
static const char NativeLineFeed = '\xa';
static const char NativeVerticalTab = '\xb';
static const char NativeFormFeed = '\xc';
static const char NativeCarriageReturn = '\xd';
#define NativeCrLf "\r\n"
static const char NativeSo = '\xe';
static const char NativeSi = '\xf';
static const char NativeDle = '\x10';
static const char NativeDc1 = '\x11';
static const char NativeDc2 = '\x12';
static const char NativeDc3 = '\x13';
static const char NativeDc4 = '\x14';
static const char NativeNak = '\x15';
static const char NativeSyn = '\x16';
static const char NativeEtb = '\x17';
static const char NativeCan = '\x18';
static const char NativeEm = '\x19';
static const char NativeEndOfFile = '\x1a';
static const char NativeEscape = '\x1b';
static const char NativeFs = '\x1c';
static const char NativeGs = '\x1d';
static const char NativeRs = '\x1e';
static const char NativeUs = '\x1f';
static const char NativeSpace = '\x20';
static const char NativeComma = '\x2c';
static const char NativeBackslash = '\x5c';
static const char NativeForwardSlash = '\x2f';
static const char NativeDoubleQuote = '\x22';
static const char NativeSingleQuote = '\x27';
#define NativeLineBreak "\r\n"
static const Shortint TabSetFormatting_SurroundStopsWithBrackets = 0x1;
static const Shortint TabSetFormatting_EmptyBracketsIfNoStops = 0x2;
static const Shortint TabSetFormatting_NoTabStops = 0x4;
static const Shortint TabSetFormatting_NoTabWidth = 0x8;
static const Shortint TabSetFormatting_AutoTabWidth = 0x10;
static const Shortint TabSetFormatting_Default = 0x0;
static const Shortint TabSetFormatting_AlwaysUseBrackets = 0x3;
static const Shortint TabSetFormatting_Full = 0x13;
static const Shortint TabSetFormatting_StopsOnly = 0x8;
static const Shortint TabSetFormatting_TabWidthOnly = 0x4;
static const Shortint TabSetFormatting_StopsWithoutBracketsAndTabWidth = 0x0;
static const Word MaxStrCharCount = 0x100;
static const Shortint StrLoOffset = 0x0;
static const Word StrUpOffset = 0x100;
static const Word StrReOffset = 0x200;
static const Word StrCaseMapSize = 0x300;
extern PACKAGE char StrCaseMap[768];
extern PACKAGE bool StrCaseMapReady;
extern PACKAGE Word StrCharTypes[256];
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE bool __fastcall ArrayContainsChar(char const * Chars, const int Chars_Size, const char C)/* overload */;
extern PACKAGE bool __fastcall ArrayContainsChar(char const * Chars, const int Chars_Size, const char C, /* out */ int &Index)/* overload */;
extern PACKAGE bool __fastcall StrIsAlpha(const AnsiString S);
extern PACKAGE bool __fastcall StrIsAlphaNum(const AnsiString S);
extern PACKAGE bool __fastcall StrConsistsOfNumberChars(const AnsiString S);
extern PACKAGE bool __fastcall StrContainsChars(const AnsiString S, const TCharValidator Chars, bool CheckAll)/* overload */;
extern PACKAGE bool __fastcall StrContainsChars(const AnsiString S, char const * Chars, const int Chars_Size, bool CheckAll)/* overload */;
extern PACKAGE bool __fastcall StrIsAlphaNumUnderscore(const AnsiString S);
extern PACKAGE bool __fastcall StrIsDigit(const AnsiString S);
extern PACKAGE bool __fastcall StrIsSubset(const AnsiString S, const TCharValidator ValidChars)/* overload */;
extern PACKAGE bool __fastcall StrIsSubset(const AnsiString S, char const * ValidChars, const int ValidChars_Size)/* overload */;
extern PACKAGE bool __fastcall StrSame(const AnsiString S1, const AnsiString S2, bool CaseSensitive = false);
extern PACKAGE AnsiString __fastcall StrCenter(const AnsiString S, int L, char C = '\x20');
extern PACKAGE AnsiString __fastcall StrCharPosLower(const AnsiString S, int CharPos);
extern PACKAGE AnsiString __fastcall StrCharPosUpper(const AnsiString S, int CharPos);
extern PACKAGE AnsiString __fastcall StrDoubleQuote(const AnsiString S);
extern PACKAGE AnsiString __fastcall StrEnsureNoPrefix(const AnsiString Prefix, const AnsiString Text);
extern PACKAGE AnsiString __fastcall StrEnsureNoSuffix(const AnsiString Suffix, const AnsiString Text);
extern PACKAGE AnsiString __fastcall StrEnsurePrefix(const AnsiString Prefix, const AnsiString Text);
extern PACKAGE AnsiString __fastcall StrEnsureSuffix(const AnsiString Suffix, const AnsiString Text);
extern PACKAGE AnsiString __fastcall StrEscapedToString(const AnsiString S);
extern PACKAGE AnsiString __fastcall StrLower(const AnsiString S);
extern PACKAGE void __fastcall StrLowerInPlace(AnsiString &S);
extern PACKAGE void __fastcall StrLowerBuff(char * S);
extern PACKAGE void __fastcall StrMove(AnsiString &Dest, const AnsiString Source, const int ToIndex, const int FromIndex, const int Count);
extern PACKAGE AnsiString __fastcall StrPadLeft(const AnsiString S, int Len, char C = '\x20');
extern PACKAGE AnsiString __fastcall StrPadRight(const AnsiString S, int Len, char C = '\x20');
extern PACKAGE AnsiString __fastcall StrProper(const AnsiString S);
extern PACKAGE void __fastcall StrProperBuff(char * S);
extern PACKAGE AnsiString __fastcall StrQuote(const AnsiString S, char C);
extern PACKAGE AnsiString __fastcall StrRemoveChars(const AnsiString S, const TCharValidator Chars)/* overload */;
extern PACKAGE AnsiString __fastcall StrRemoveChars(const AnsiString S, char const * Chars, const int Chars_Size)/* overload */;
extern PACKAGE AnsiString __fastcall StrRemoveLeadingChars(const AnsiString S, const TCharValidator Chars)/* overload */;
extern PACKAGE AnsiString __fastcall StrRemoveLeadingChars(const AnsiString S, char const * Chars, const int Chars_Size)/* overload */;
extern PACKAGE AnsiString __fastcall StrRemoveEndChars(const AnsiString S, const TCharValidator Chars)/* overload */;
extern PACKAGE AnsiString __fastcall StrRemoveEndChars(const AnsiString S, char const * Chars, const int Chars_Size)/* overload */;
extern PACKAGE AnsiString __fastcall StrKeepChars(const AnsiString S, const TCharValidator Chars)/* overload */;
extern PACKAGE AnsiString __fastcall StrKeepChars(const AnsiString S, char const * Chars, const int Chars_Size)/* overload */;
extern PACKAGE AnsiString __fastcall StrRepeat(const AnsiString S, int Count);
extern PACKAGE AnsiString __fastcall StrRepeatLength(const AnsiString S, int L);
extern PACKAGE void __fastcall StrReplace(AnsiString &S, const AnsiString Search, const AnsiString Replace, Sysutils::TReplaceFlags Flags = Set<Sysutils::SysUtils__94, rfReplaceAll, rfIgnoreCase> () );
extern PACKAGE AnsiString __fastcall StrReplaceChar(const AnsiString S, const char Source, const char Replace);
extern PACKAGE AnsiString __fastcall StrReplaceChars(const AnsiString S, const TCharValidator Chars, char Replace)/* overload */;
extern PACKAGE AnsiString __fastcall StrReplaceChars(const AnsiString S, char const * Chars, const int Chars_Size, char Replace)/* overload */;
extern PACKAGE AnsiString __fastcall StrReplaceButChars(const AnsiString S, const TCharValidator Chars, char Replace)/* overload */;
extern PACKAGE AnsiString __fastcall StrReplaceButChars(const AnsiString S, char const * Chars, const int Chars_Size, char Replace)/* overload */;
extern PACKAGE AnsiString __fastcall StrReverse(const AnsiString S);
extern PACKAGE void __fastcall StrReverseInPlace(AnsiString &S);
extern PACKAGE AnsiString __fastcall StrSingleQuote(const AnsiString S);
extern PACKAGE AnsiString __fastcall StrSmartCase(const AnsiString S, const TCharValidator Delimiters)/* overload */;
extern PACKAGE AnsiString __fastcall StrSmartCase(const AnsiString S, char const * Delimiters, const int Delimiters_Size)/* overload */;
extern PACKAGE AnsiString __fastcall StrStringToEscaped(const AnsiString S);
extern PACKAGE AnsiString __fastcall StrStripNonNumberChars(const AnsiString S);
extern PACKAGE AnsiString __fastcall StrToHex(const AnsiString Source);
extern PACKAGE AnsiString __fastcall StrTrimCharLeft(const AnsiString S, char C);
extern PACKAGE AnsiString __fastcall StrTrimCharsLeft(const AnsiString S, const TCharValidator Chars)/* overload */;
extern PACKAGE AnsiString __fastcall StrTrimCharsLeft(const AnsiString S, char const * Chars, const int Chars_Size)/* overload */;
extern PACKAGE AnsiString __fastcall StrTrimCharRight(const AnsiString S, char C);
extern PACKAGE AnsiString __fastcall StrTrimCharsRight(const AnsiString S, const TCharValidator Chars)/* overload */;
extern PACKAGE AnsiString __fastcall StrTrimCharsRight(const AnsiString S, char const * Chars, const int Chars_Size)/* overload */;
extern PACKAGE AnsiString __fastcall StrTrimQuotes(const AnsiString S);
extern PACKAGE AnsiString __fastcall StrUpper(const AnsiString S);
extern PACKAGE void __fastcall StrUpperInPlace(AnsiString &S);
extern PACKAGE void __fastcall StrUpperBuff(char * S);
extern PACKAGE void __fastcall StrAddRef(AnsiString &S);
extern PACKAGE void __fastcall StrDecRef(AnsiString &S);
extern PACKAGE int __fastcall StrLength(const AnsiString S);
extern PACKAGE int __fastcall StrRefCount(const AnsiString S);
extern PACKAGE void __fastcall StrResetLength(WideString &S)/* overload */;
extern PACKAGE void __fastcall StrResetLength(AnsiString &S)/* overload */;
extern PACKAGE void __fastcall StrResetLength(TJclStringBuilder* S)/* overload */;
extern PACKAGE int __fastcall StrCharCount(const AnsiString S, char C)/* overload */;
extern PACKAGE int __fastcall StrCharsCount(const AnsiString S, const TCharValidator Chars)/* overload */;
extern PACKAGE int __fastcall StrCharsCount(const AnsiString S, char const * Chars, const int Chars_Size)/* overload */;
extern PACKAGE int __fastcall StrStrCount(const AnsiString S, const AnsiString SubS);
extern PACKAGE int __fastcall StrCompareRangeEx(const AnsiString S1, const AnsiString S2, int Index, int Count, bool CaseSensitive);
extern PACKAGE int __fastcall StrCompare(const AnsiString S1, const AnsiString S2, bool CaseSensitive = false);
extern PACKAGE int __fastcall StrCompareRange(const AnsiString S1, const AnsiString S2, int Index, int Count, bool CaseSensitive = true);
extern PACKAGE void __fastcall StrFillChar(void *S, int Count, char C);
extern PACKAGE AnsiString __fastcall StrRepeatChar(char C, int Count);
extern PACKAGE int __fastcall StrFind(const AnsiString Substr, const AnsiString S, const int Index = 0x1);
extern PACKAGE bool __fastcall StrHasPrefix(const AnsiString S, AnsiString const * Prefixes, const int Prefixes_Size);
extern PACKAGE int __fastcall StrIndex(const AnsiString S, AnsiString const * List, const int List_Size, bool CaseSensitive = false);
extern PACKAGE bool __fastcall StrIHasPrefix(const AnsiString S, AnsiString const * Prefixes, const int Prefixes_Size);
extern PACKAGE int __fastcall StrILastPos(const AnsiString SubStr, const AnsiString S);
extern PACKAGE int __fastcall StrIPos(const AnsiString SubStr, const AnsiString S);
extern PACKAGE int __fastcall StrIPrefixIndex(const AnsiString S, AnsiString const * Prefixes, const int Prefixes_Size);
extern PACKAGE bool __fastcall StrIsOneOf(const AnsiString S, AnsiString const * List, const int List_Size);
extern PACKAGE int __fastcall StrLastPos(const AnsiString SubStr, const AnsiString S);
extern PACKAGE int __fastcall StrMatch(const AnsiString Substr, const AnsiString S, int Index = 0x1);
extern PACKAGE bool __fastcall StrMatches(const AnsiString Substr, const AnsiString S, const int Index = 0x1);
extern PACKAGE int __fastcall StrNPos(const AnsiString S, const AnsiString SubStr, int N);
extern PACKAGE int __fastcall StrNIPos(const AnsiString S, const AnsiString SubStr, int N);
extern PACKAGE int __fastcall StrPrefixIndex(const AnsiString S, AnsiString const * Prefixes, const int Prefixes_Size);
extern PACKAGE int __fastcall StrSearch(const AnsiString Substr, const AnsiString S, const int Index = 0x1);
extern PACKAGE AnsiString __fastcall StrAfter(const AnsiString SubStr, const AnsiString S);
extern PACKAGE AnsiString __fastcall StrBefore(const AnsiString SubStr, const AnsiString S);
extern PACKAGE AnsiString __fastcall StrBetween(const AnsiString S, const char Start, const char Stop);
extern PACKAGE AnsiString __fastcall StrChopRight(const AnsiString S, int N);
extern PACKAGE AnsiString __fastcall StrLeft(const AnsiString S, int Count);
extern PACKAGE AnsiString __fastcall StrMid(const AnsiString S, int Start, int Count);
extern PACKAGE AnsiString __fastcall StrRestOf(const AnsiString S, int N);
extern PACKAGE AnsiString __fastcall StrRight(const AnsiString S, int Count);
extern PACKAGE bool __fastcall CharEqualNoCase(const char C1, const char C2);
extern PACKAGE bool __fastcall CharIsAlpha(const char C);
extern PACKAGE bool __fastcall CharIsAlphaNum(const char C);
extern PACKAGE bool __fastcall CharIsBlank(const char C);
extern PACKAGE bool __fastcall CharIsControl(const char C);
extern PACKAGE bool __fastcall CharIsDelete(const char C);
extern PACKAGE bool __fastcall CharIsDigit(const char C);
extern PACKAGE bool __fastcall CharIsFracDigit(const char C);
extern PACKAGE bool __fastcall CharIsHexDigit(const char C);
extern PACKAGE bool __fastcall CharIsLower(const char C);
extern PACKAGE bool __fastcall CharIsNumberChar(const char C);
extern PACKAGE bool __fastcall CharIsNumber(const char C);
extern PACKAGE bool __fastcall CharIsPrintable(const char C);
extern PACKAGE bool __fastcall CharIsPunctuation(const char C);
extern PACKAGE bool __fastcall CharIsReturn(const char C);
extern PACKAGE bool __fastcall CharIsSpace(const char C);
extern PACKAGE bool __fastcall CharIsUpper(const char C);
extern PACKAGE bool __fastcall CharIsValidIdentifierLetter(const char C);
extern PACKAGE bool __fastcall CharIsWhiteSpace(const char C);
extern PACKAGE bool __fastcall CharIsWildcard(const char C);
extern PACKAGE Word __fastcall CharType(const char C);
extern PACKAGE PCharVector __fastcall StringsToPCharVector(PCharVector &Dest, const Classes::TStrings* Source);
extern PACKAGE int __fastcall PCharVectorCount(PCharVector Source);
extern PACKAGE void __fastcall PCharVectorToStrings(const Classes::TStrings* Dest, PCharVector Source);
extern PACKAGE void __fastcall FreePCharVector(PCharVector &Dest);
extern PACKAGE Byte __fastcall CharHex(const char C);
extern PACKAGE char __fastcall CharLower(const char C);
extern PACKAGE char __fastcall CharToggleCase(const char C);
extern PACKAGE char __fastcall CharUpper(const char C);
extern PACKAGE int __fastcall CharLastPos(const AnsiString S, const char C, const int Index = 0x1);
extern PACKAGE int __fastcall CharPos(const AnsiString S, const char C, const int Index = 0x1);
extern PACKAGE int __fastcall CharIPos(const AnsiString S, char C, const int Index = 0x1);
extern PACKAGE int __fastcall CharReplace(AnsiString &S, const char Search, const char Replace);
extern PACKAGE char * __fastcall StringsToMultiSz(char * &Dest, const Classes::TStrings* Source);
extern PACKAGE void __fastcall MultiSzToStrings(const Classes::TStrings* Dest, const char * Source);
extern PACKAGE int __fastcall MultiSzLength(const char * Source);
extern PACKAGE void __fastcall AllocateMultiSz(char * &Dest, int Len);
extern PACKAGE void __fastcall FreeMultiSz(char * &Dest);
extern PACKAGE char * __fastcall MultiSzDup(const char * Source);
extern PACKAGE char * __fastcall AnsiStringsToAnsiMultiSz(char * &Dest, const Classes::TStrings* Source);
extern PACKAGE void __fastcall AnsiMultiSzToAnsiStrings(const Classes::TStrings* Dest, const char * Source);
extern PACKAGE int __fastcall AnsiMultiSzLength(const char * Source);
extern PACKAGE void __fastcall AllocateAnsiMultiSz(char * &Dest, int Len);
extern PACKAGE void __fastcall FreeAnsiMultiSz(char * &Dest);
extern PACKAGE char * __fastcall AnsiMultiSzDup(const char * Source);
extern PACKAGE WideChar * __fastcall WideStringsToWideMultiSz(WideChar * &Dest, const Jclwidestrings::TJclWideStrings* Source);
extern PACKAGE void __fastcall WideMultiSzToWideStrings(const Jclwidestrings::TJclWideStrings* Dest, const WideChar * Source);
extern PACKAGE int __fastcall WideMultiSzLength(const WideChar * Source);
extern PACKAGE void __fastcall AllocateWideMultiSz(WideChar * &Dest, int Len);
extern PACKAGE void __fastcall FreeWideMultiSz(WideChar * &Dest);
extern PACKAGE WideChar * __fastcall WideMultiSzDup(const WideChar * Source);
extern PACKAGE void __fastcall StrToStrings(AnsiString S, AnsiString Sep, const Classes::TStrings* List, const bool AllowEmptyString = true);
extern PACKAGE void __fastcall StrIToStrings(AnsiString S, AnsiString Sep, const Classes::TStrings* List, const bool AllowEmptyString = true);
extern PACKAGE AnsiString __fastcall StringsToStr(const Classes::TStrings* List, const AnsiString Sep, const bool AllowEmptyString = true);
extern PACKAGE void __fastcall TrimStrings(const Classes::TStrings* List, bool DeleteIfEmpty = true);
extern PACKAGE void __fastcall TrimStringsRight(const Classes::TStrings* List, bool DeleteIfEmpty = true);
extern PACKAGE void __fastcall TrimStringsLeft(const Classes::TStrings* List, bool DeleteIfEmpty = true);
extern PACKAGE bool __fastcall AddStringToStrings(const AnsiString S, Classes::TStrings* Strings, const bool Unique);
extern PACKAGE AnsiString __fastcall FileToString(const AnsiString FileName);
extern PACKAGE void __fastcall StringToFile(const AnsiString FileName, const AnsiString Contents, bool Append = false);
extern PACKAGE AnsiString __fastcall StrToken(AnsiString &S, char Separator);
extern PACKAGE void __fastcall StrTokens(const AnsiString S, const Classes::TStrings* List);
extern PACKAGE bool __fastcall StrWord(const AnsiString S, int &Index, /* out */ AnsiString &Word)/* overload */;
extern PACKAGE bool __fastcall StrWord(char * &S, /* out */ AnsiString &Word)/* overload */;
extern PACKAGE void __fastcall StrTokenToStrings(AnsiString S, char Separator, const Classes::TStrings* List);
extern PACKAGE Extended __fastcall StrToFloatSafe(const AnsiString S);
extern PACKAGE int __fastcall StrToIntSafe(const AnsiString S);
extern PACKAGE void __fastcall StrNormIndex(const int StrLen, int &Index, int &Count)/* overload */;
extern PACKAGE Jclbase::TDynStringArray __fastcall ArrayOf(Classes::TStrings* List)/* overload */;
extern PACKAGE AnsiString __fastcall DotNetFormat(const AnsiString Fmt, const Variant &Arg0)/* overload */;
extern PACKAGE AnsiString __fastcall DotNetFormat(const AnsiString Fmt, const Variant &Arg0, const Variant &Arg1)/* overload */;
extern PACKAGE AnsiString __fastcall DotNetFormat(const AnsiString Fmt, const Variant &Arg0, const Variant &Arg1, const Variant &Arg2)/* overload */;
extern PACKAGE AnsiString __fastcall DotNetFormat(const AnsiString Fmt, System::TVarRec const * Args, const int Args_Size)/* overload */;
extern PACKAGE AnsiString __fastcall StrExpandTabs(AnsiString S)/* overload */;
extern PACKAGE AnsiString __fastcall StrExpandTabs(AnsiString S, int TabWidth)/* overload */;
extern PACKAGE AnsiString __fastcall StrExpandTabs(AnsiString S, TJclTabSet* TabSet)/* overload */;
extern PACKAGE AnsiString __fastcall StrOptimizeTabs(AnsiString S)/* overload */;
extern PACKAGE AnsiString __fastcall StrOptimizeTabs(AnsiString S, int TabWidth)/* overload */;
extern PACKAGE AnsiString __fastcall StrOptimizeTabs(AnsiString S, TJclTabSet* TabSet)/* overload */;
extern PACKAGE int __fastcall CompareNaturalStr(const AnsiString S1, const AnsiString S2)/* overload */;
extern PACKAGE int __fastcall CompareNaturalText(const AnsiString S1, const AnsiString S2)/* overload */;

}	/* namespace Jclstrings */
using namespace Jclstrings;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclstrings
