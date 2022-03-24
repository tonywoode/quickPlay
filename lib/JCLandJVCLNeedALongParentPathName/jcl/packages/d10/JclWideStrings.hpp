// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclwidestrings.pas' rev: 10.00

#ifndef JclwidestringsHPP
#define JclwidestringsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclwidestrings
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EJclWideStringError;
class PASCALIMPLEMENTATION EJclWideStringError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclWideStringError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclWideStringError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclWideStringError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclWideStringError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclWideStringError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclWideStringError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclWideStringError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclWideStringError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclWideStringError(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TWideFileOptionsType { foAnsiFile, foUnicodeLB };
#pragma option pop

typedef Set<TWideFileOptionsType, foAnsiFile, foUnicodeLB>  TWideFileOptions;

#pragma option push -b-
enum TSearchFlag { sfCaseSensitive, sfIgnoreNonSpacing, sfSpaceCompress, sfWholeWordOnly };
#pragma option pop

typedef Set<TSearchFlag, sfCaseSensitive, sfWholeWordOnly>  TSearchFlags;

class DELPHICLASS TJclWideStringList;
typedef int __fastcall (*TJclWideStringListSortCompare)(TJclWideStringList* List, int Index1, int Index2);

class DELPHICLASS TJclWideStrings;
class PASCALIMPLEMENTATION TJclWideStrings : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
public:
	WideString operator[](int Index) { return Strings[Index]; }
	
private:
	WideChar FDelimiter;
	WideChar FQuoteChar;
	WideChar FNameValueSeparator;
	WideString FLineSeparator;
	int FUpdateCount;
	WideString __fastcall GetCommaText();
	WideString __fastcall GetDelimitedText();
	WideString __fastcall GetName(int Index);
	WideString __fastcall GetValue(const WideString Name);
	void __fastcall ReadData(Classes::TReader* Reader);
	void __fastcall SetCommaText(const WideString Value);
	void __fastcall SetDelimitedText(const WideString Value);
	void __fastcall SetValue(const WideString Name, const WideString Value);
	void __fastcall WriteData(Classes::TWriter* Writer);
	WideString __fastcall GetValueFromIndex(int Index);
	void __fastcall SetValueFromIndex(int Index, const WideString Value);
	
protected:
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	WideString __fastcall ExtractName(const WideString S);
	virtual System::PWideString __fastcall GetP(int Index) = 0 ;
	WideString __fastcall Get(int Index);
	virtual int __fastcall GetCapacity(void);
	virtual int __fastcall GetCount(void) = 0 ;
	virtual System::TObject* __fastcall GetObject(int Index);
	virtual WideString __fastcall GetTextStr();
	virtual void __fastcall Put(int Index, const WideString S) = 0 ;
	virtual void __fastcall PutObject(int Index, System::TObject* AObject) = 0 ;
	virtual void __fastcall SetCapacity(int NewCapacity);
	virtual void __fastcall SetTextStr(const WideString Value);
	virtual void __fastcall SetUpdateState(bool Updating);
	__property int UpdateCount = {read=FUpdateCount, nodefault};
	virtual int __fastcall CompareStrings(const WideString S1, const WideString S2);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	__fastcall TJclWideStrings(void);
	virtual int __fastcall Add(const WideString S);
	virtual int __fastcall AddObject(const WideString S, System::TObject* AObject);
	void __fastcall Append(const WideString S);
	virtual void __fastcall AddStrings(TJclWideStrings* Strings)/* overload */;
	virtual void __fastcall AddStrings(Classes::TStrings* Strings)/* overload */;
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	Classes::TStrings* __fastcall CreateAnsiStringList(void);
	virtual void __fastcall AddStringsTo(Classes::TStrings* Dest);
	void __fastcall BeginUpdate(void);
	virtual void __fastcall Clear(void) = 0 ;
	virtual void __fastcall Delete(int Index) = 0 ;
	void __fastcall EndUpdate(void);
	bool __fastcall Equals(TJclWideStrings* Strings)/* overload */;
	bool __fastcall Equals(Classes::TStrings* Strings)/* overload */;
	virtual void __fastcall Exchange(int Index1, int Index2);
	virtual WideChar * __fastcall GetText(void);
	virtual int __fastcall IndexOf(const WideString S);
	virtual int __fastcall IndexOfName(const WideString Name);
	virtual int __fastcall IndexOfObject(System::TObject* AObject);
	virtual void __fastcall Insert(int Index, const WideString S);
	virtual void __fastcall InsertObject(int Index, const WideString S, System::TObject* AObject);
	virtual void __fastcall LoadFromFile(const AnsiString FileName, TWideFileOptions WideFileOptions = Set<TWideFileOptionsType, foAnsiFile, foUnicodeLB> () );
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream, TWideFileOptions WideFileOptions = Set<TWideFileOptionsType, foAnsiFile, foUnicodeLB> () );
	virtual void __fastcall Move(int CurIndex, int NewIndex);
	virtual void __fastcall SaveToFile(const AnsiString FileName, TWideFileOptions WideFileOptions = Set<TWideFileOptionsType, foAnsiFile, foUnicodeLB> () );
	virtual void __fastcall SaveToStream(Classes::TStream* Stream, TWideFileOptions WideFileOptions = Set<TWideFileOptionsType, foAnsiFile, foUnicodeLB> () );
	virtual void __fastcall SetText(WideChar * Text);
	WideString __fastcall GetDelimitedTextEx(WideChar ADelimiter, WideChar AQuoteChar);
	void __fastcall SetDelimitedTextEx(WideChar ADelimiter, WideChar AQuoteChar, const WideString Value);
	__property int Capacity = {read=GetCapacity, write=SetCapacity, nodefault};
	__property WideString CommaText = {read=GetCommaText, write=SetCommaText};
	__property int Count = {read=GetCount, nodefault};
	__property WideChar Delimiter = {read=FDelimiter, write=FDelimiter, nodefault};
	__property WideString DelimitedText = {read=GetDelimitedText, write=SetDelimitedText};
	__property WideString Names[int Index] = {read=GetName};
	__property System::TObject* Objects[int Index] = {read=GetObject, write=PutObject};
	__property WideChar QuoteChar = {read=FQuoteChar, write=FQuoteChar, nodefault};
	__property WideString Values[WideString Name] = {read=GetValue, write=SetValue};
	__property WideString ValueFromIndex[int Index] = {read=GetValueFromIndex, write=SetValueFromIndex};
	__property WideChar NameValueSeparator = {read=FNameValueSeparator, write=FNameValueSeparator, nodefault};
	__property WideString LineSeparator = {read=FLineSeparator, write=FLineSeparator};
	__property System::PWideString PStrings[int Index] = {read=GetP};
	__property WideString Strings[int Index] = {read=Get, write=Put/*, default*/};
	__property WideString Text = {read=GetTextStr, write=SetTextStr};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TJclWideStrings(void) { }
	#pragma option pop
	
};


struct TWStringItem;
typedef TWStringItem *PWStringItem;

struct TWStringItem
{
	
public:
	WideString FString;
	System::TObject* FObject;
} ;

class PASCALIMPLEMENTATION TJclWideStringList : public TJclWideStrings 
{
	typedef TJclWideStrings inherited;
	
private:
	Classes::TList* FList;
	bool FSorted;
	Classes::TDuplicates FDuplicates;
	bool FCaseSensitive;
	Classes::TNotifyEvent FOnChange;
	Classes::TNotifyEvent FOnChanging;
	void __fastcall SetSorted(bool Value);
	void __fastcall SetCaseSensitive(const bool Value);
	
protected:
	PWStringItem __fastcall GetItem(int Index);
	virtual void __fastcall Changed(void);
	virtual void __fastcall Changing(void);
	virtual System::PWideString __fastcall GetP(int Index);
	virtual int __fastcall GetCapacity(void);
	virtual int __fastcall GetCount(void);
	virtual System::TObject* __fastcall GetObject(int Index);
	virtual void __fastcall Put(int Index, const WideString Value);
	virtual void __fastcall PutObject(int Index, System::TObject* AObject);
	virtual void __fastcall SetCapacity(int NewCapacity);
	virtual void __fastcall SetUpdateState(bool Updating);
	virtual int __fastcall CompareStrings(const WideString S1, const WideString S2);
	
public:
	__fastcall TJclWideStringList(void);
	__fastcall virtual ~TJclWideStringList(void);
	virtual int __fastcall AddObject(const WideString S, System::TObject* AObject);
	virtual void __fastcall Clear(void);
	virtual void __fastcall Delete(int Index);
	virtual void __fastcall Exchange(int Index1, int Index2);
	virtual bool __fastcall Find(const WideString S, int &Index);
	virtual int __fastcall IndexOf(const WideString S);
	virtual void __fastcall InsertObject(int Index, const WideString S, System::TObject* AObject);
	virtual void __fastcall Sort(void);
	virtual void __fastcall CustomSort(TJclWideStringListSortCompare Compare);
	__property Classes::TDuplicates Duplicates = {read=FDuplicates, write=FDuplicates, nodefault};
	__property bool Sorted = {read=FSorted, write=SetSorted, nodefault};
	__property bool CaseSensitive = {read=FCaseSensitive, write=SetCaseSensitive, nodefault};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Classes::TNotifyEvent OnChanging = {read=FOnChanging, write=FOnChanging};
};


typedef TJclWideStringList TWideStringList;
;

typedef TJclWideStrings TWideStrings;
;

typedef TJclWideStringList TJclUnicodeStringList;
;

typedef TJclWideStrings TJclUnicodeStrings;
;

typedef TJclWideStringList TWStringList;
;

typedef TJclWideStrings TWStrings;
;

typedef WideChar *PWideMultiSz;

//-- var, const, procedure ---------------------------------------------------
static const WideChar WideNull = WideChar(0x0);
static const WideChar WideTabulator = WideChar(0x9);
static const WideChar WideSpace = WideChar(0x20);
static const WideChar WideLF = WideChar(0xa);
static const WideChar WideLineFeed = WideChar(0xa);
static const WideChar WideVerticalTab = WideChar(0xb);
static const WideChar WideFormFeed = WideChar(0xc);
static const WideChar WideCR = WideChar(0xd);
static const WideChar WideCarriageReturn = WideChar(0xd);
#define WideCRLF L"\r\n"
static const WideChar WideLineSeparator = WideChar(0x2028);
static const WideChar WideParagraphSeparator = WideChar(0x2029);
#define WideLineBreak L"\r\n"
static const WideChar BOM_LSB_FIRST = WideChar(0xfeff);
static const WideChar BOM_MSB_FIRST = WideChar(0xfffe);
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE WideChar __fastcall CharToWideChar(char Ch);
extern PACKAGE char __fastcall WideCharToChar(WideChar Ch);
extern PACKAGE void __fastcall MoveWideChar(const void *Source, void *Dest, int Count);
extern PACKAGE WideChar * __fastcall StrAllocW(int WideSize);
extern PACKAGE WideChar * __fastcall StrNewW(const WideChar * Str)/* overload */;
extern PACKAGE WideChar * __fastcall StrNewW(const WideString Str)/* overload */;
extern PACKAGE void __fastcall StrDisposeW(WideChar * Str);
extern PACKAGE void __fastcall StrDisposeAndNilW(WideChar * &Str);
extern PACKAGE int __fastcall StrCompW(const WideChar * Str1, const WideChar * Str2);
extern PACKAGE int __fastcall StrLCompW(const WideChar * Str1, const WideChar * Str2, int MaxLen);
extern PACKAGE int __fastcall StrICompW(const WideChar * Str1, const WideChar * Str2);
extern PACKAGE int __fastcall StrLICompW(const WideChar * Str1, const WideChar * Str2, int MaxLen);
extern PACKAGE int __fastcall StrLICompW2(const WideChar * Str1, const WideChar * Str2, int MaxLen);
extern PACKAGE WideChar * __fastcall StrPosW(const WideChar * Str, const WideChar * SubStr);
extern PACKAGE int __fastcall StrLenW(const WideChar * Str);
extern PACKAGE WideChar * __fastcall StrScanW(const WideChar * Str, WideChar Ch)/* overload */;
extern PACKAGE WideChar * __fastcall StrEndW(const WideChar * Str);
extern PACKAGE WideChar * __fastcall StrCopyW(WideChar * Dest, const WideChar * Source);
extern PACKAGE WideChar * __fastcall StrECopyW(WideChar * Dest, const WideChar * Source);
extern PACKAGE WideChar * __fastcall StrLCopyW(WideChar * Dest, const WideChar * Source, int MaxLen);
extern PACKAGE WideChar * __fastcall StrCatW(WideChar * Dest, const WideChar * Source);
extern PACKAGE WideChar * __fastcall StrLCatW(WideChar * Dest, const WideChar * Source, int MaxLen);
extern PACKAGE WideChar * __fastcall StrMoveW(WideChar * Dest, const WideChar * Source, int Count);
extern PACKAGE WideChar * __fastcall StrPCopyWW(WideChar * Dest, const WideString Source);
extern PACKAGE WideChar * __fastcall StrPLCopyWW(WideChar * Dest, const WideString Source, int MaxLen);
extern PACKAGE WideChar * __fastcall StrRScanW(const WideChar * Str, WideChar Chr);
extern PACKAGE void __fastcall StrSwapByteOrder(WideChar * Str);
extern PACKAGE int __fastcall StrNScanW(const WideChar * Str1, const WideChar * Str2);
extern PACKAGE int __fastcall StrRNScanW(const WideChar * Str1, const WideChar * Str2);
extern PACKAGE WideChar * __fastcall StrScanW(WideChar * Str, WideChar Chr, int StrLen)/* overload */;
extern PACKAGE int __fastcall StrBufSizeW(const WideChar * Str);
extern PACKAGE WideChar * __fastcall StrPCopyW(WideChar * Dest, const AnsiString Source);
extern PACKAGE WideChar * __fastcall StrPLCopyW(WideChar * Dest, const AnsiString Source, int MaxLen);
extern PACKAGE int __fastcall WidePos(const WideString SubStr, const WideString S);
extern PACKAGE WideString __fastcall WideQuotedStr(const WideString S, WideChar Quote);
extern PACKAGE WideString __fastcall WideExtractQuotedStr(WideChar * &Src, WideChar Quote);
extern PACKAGE WideString __fastcall TrimW(const WideString S);
extern PACKAGE WideString __fastcall TrimLeftW(const WideString S);
extern PACKAGE WideString __fastcall TrimRightW(const WideString S);
extern PACKAGE WideString __fastcall WideReverse(const WideString AText);
extern PACKAGE void __fastcall WideReverseInPlace(WideString &S);
extern PACKAGE int __fastcall WideCompareText(const WideString S1, const WideString S2);
extern PACKAGE int __fastcall WideCompareStr(const WideString S1, const WideString S2);
extern PACKAGE WideString __fastcall WideUpperCase(const WideString S);
extern PACKAGE WideString __fastcall WideLowerCase(const WideString S);
extern PACKAGE int __fastcall TrimLeftLengthW(const WideString S);
extern PACKAGE int __fastcall TrimRightLengthW(const WideString S);
extern PACKAGE bool __fastcall WideStartsText(const WideString SubStr, const WideString S);
extern PACKAGE bool __fastcall WideStartsStr(const WideString SubStr, const WideString S);
extern PACKAGE WideChar * __fastcall StringsToMultiSz(WideChar * &Dest, const TJclWideStrings* Source);
extern PACKAGE void __fastcall MultiSzToStrings(const TJclWideStrings* Dest, const WideChar * Source);
extern PACKAGE int __fastcall MultiSzLength(const WideChar * Source);
extern PACKAGE void __fastcall AllocateMultiSz(WideChar * &Dest, int Len);
extern PACKAGE void __fastcall FreeMultiSz(WideChar * &Dest);
extern PACKAGE WideChar * __fastcall MultiSzDup(const WideChar * Source);

}	/* namespace Jclwidestrings */
using namespace Jclwidestrings;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclwidestrings
