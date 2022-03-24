// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclansistrings.pas' rev: 10.00

#ifndef JclansistringsHPP
#define JclansistringsHPP

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
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclansistrings
{
//-- type declarations -------------------------------------------------------
typedef TStrings TJclAnsiStrings;
;

typedef TStringList TJclAnsiStringList;
;

typedef TStrings TAnsiStrings;
;

typedef TStringList TAnsiStringList;
;

class DELPHICLASS EJclAnsiStringError;
class PASCALIMPLEMENTATION EJclAnsiStringError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclAnsiStringError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclAnsiStringError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclAnsiStringError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclAnsiStringError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclAnsiStringError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclAnsiStringError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclAnsiStringError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclAnsiStringError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclAnsiStringError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclAnsiStringListError;
class PASCALIMPLEMENTATION EJclAnsiStringListError : public EJclAnsiStringError 
{
	typedef EJclAnsiStringError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclAnsiStringListError(const AnsiString Msg) : EJclAnsiStringError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclAnsiStringListError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclAnsiStringError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclAnsiStringListError(int Ident)/* overload */ : EJclAnsiStringError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclAnsiStringListError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclAnsiStringError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclAnsiStringListError(const AnsiString Msg, int AHelpContext) : EJclAnsiStringError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclAnsiStringListError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclAnsiStringError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclAnsiStringListError(int Ident, int AHelpContext)/* overload */ : EJclAnsiStringError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclAnsiStringListError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclAnsiStringError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclAnsiStringListError(void) { }
	#pragma option pop
	
};


typedef char * *PAnsiCharVector;

typedef char *PAnsiMultiSz;

//-- var, const, procedure ---------------------------------------------------
static const char AnsiNull = '\x0';
static const char AnsiSoh = '\x1';
static const char AnsiStx = '\x2';
static const char AnsiEtx = '\x3';
static const char AnsiEot = '\x4';
static const char AnsiEnq = '\x5';
static const char AnsiAck = '\x6';
static const char AnsiBell = '\x7';
static const char AnsiBackspace = '\x8';
static const char AnsiTab = '\x9';
static const char AnsiLineFeed = '\xa';
static const char AnsiVerticalTab = '\xb';
static const char AnsiFormFeed = '\xc';
static const char AnsiCarriageReturn = '\xd';
#define AnsiCrLf "\r\n"
static const char AnsiSo = '\xe';
static const char AnsiSi = '\xf';
static const char AnsiDle = '\x10';
static const char AnsiDc1 = '\x11';
static const char AnsiDc2 = '\x12';
static const char AnsiDc3 = '\x13';
static const char AnsiDc4 = '\x14';
static const char AnsiNak = '\x15';
static const char AnsiSyn = '\x16';
static const char AnsiEtb = '\x17';
static const char AnsiCan = '\x18';
static const char AnsiEm = '\x19';
static const char AnsiEndOfFile = '\x1a';
static const char AnsiEscape = '\x1b';
static const char AnsiFs = '\x1c';
static const char AnsiGs = '\x1d';
static const char AnsiRs = '\x1e';
static const char AnsiUs = '\x1f';
static const char AnsiSpace = '\x20';
static const char AnsiComma = '\x2c';
static const char AnsiBackslash = '\x5c';
static const char AnsiForwardSlash = '\x2f';
static const char AnsiDoubleQuote = '\x22';
static const char AnsiSingleQuote = '\x27';
#define AnsiLineBreak "\r\n"
static const char AnsiSignMinus = '\x2d';
static const char AnsiSignPlus = '\x2b';
#define AnsiWhiteSpace (Set<char, 0, 255> () << '\x9' << '\xa' << '\xb' << '\xc' << '\xd' << '\x20' )
#define AnsiSigns (Set<char, 0, 255> () << '\x2b' << '\x2d' )
#define AnsiUppercaseLetters (Set<char, 0, 255> () << '\x41' << '\x42' << '\x43' << '\x44' << '\x45' << '\x46' << '\x47' << '\x48' << '\x49' << '\x4a' << '\x4b' << '\x4c' << '\x4d' << '\x4e' << '\x4f' << '\x50' << '\x51' << '\x52' << '\x53' << '\x54' << '\x55' << '\x56' << '\x57' << '\x58' << '\x59' << '\x5a' )
#define AnsiLowercaseLetters (Set<char, 0, 255> () << '\x61' << '\x62' << '\x63' << '\x64' << '\x65' << '\x66' << '\x67' << '\x68' << '\x69' << '\x6a' << '\x6b' << '\x6c' << '\x6d' << '\x6e' << '\x6f' << '\x70' << '\x71' << '\x72' << '\x73' << '\x74' << '\x75' << '\x76' << '\x77' << '\x78' << '\x79' << '\x7a' )
#define AnsiLetters (Set<char, 0, 255> () << '\x41' << '\x42' << '\x43' << '\x44' << '\x45' << '\x46' << '\x47' << '\x48' << '\x49' << '\x4a' << '\x4b' << '\x4c' << '\x4d' << '\x4e' << '\x4f' << '\x50' << '\x51' << '\x52' << '\x53' << '\x54' << '\x55' << '\x56' << '\x57' << '\x58' << '\x59' << '\x5a' << '\x61' << '\x62' << '\x63' << '\x64' << '\x65' << '\x66' << '\x67' << '\x68' << '\x69' << '\x6a' << '\x6b' << '\x6c' << '\x6d' << '\x6e' << '\x6f' << '\x70' << '\x71' << '\x72' << '\x73' << '\x74' << '\x75' << '\x76' << '\x77' << '\x78' << '\x79' << '\x7a' )
#define AnsiDecDigits (Set<char, 0, 255> () << '\x30' << '\x31' << '\x32' << '\x33' << '\x34' << '\x35' << '\x36' << '\x37' << '\x38' << '\x39' )
#define AnsiOctDigits (Set<char, 0, 255> () << '\x30' << '\x31' << '\x32' << '\x33' << '\x34' << '\x35' << '\x36' << '\x37' )
#define AnsiHexDigits (Set<char, 0, 255> () << '\x30' << '\x31' << '\x32' << '\x33' << '\x34' << '\x35' << '\x36' << '\x37' << '\x38' << '\x39' << '\x41' << '\x42' << '\x43' << '\x44' << '\x45' << '\x46' << '\x50' << '\x51' << '\x52' << '\x53' << '\x54' << '\x55' << '\x56' << '\x57' << '\x58' << '\x59' << '\x61' << '\x62' << '\x63' << '\x64' << '\x65' << '\x66' )
#define AnsiValidIdentifierLetters (Set<char, 0, 255> () << '\x30' << '\x31' << '\x32' << '\x33' << '\x34' << '\x35' << '\x36' << '\x37' << '\x38' << '\x39' << '\x41' << '\x42' << '\x43' << '\x44' << '\x45' << '\x46' << '\x47' << '\x48' << '\x49' << '\x4a' << '\x4b' << '\x4c' << '\x4d' << '\x4e' << '\x4f' << '\x50' << '\x51' << '\x52' << '\x53' << '\x54' << '\x55' << '\x56' << '\x57' << '\x58' << '\x59' << '\x61' << '\x62' << '\x63' << '\x64' << '\x65' << '\x66' << '\x67' << '\x68' << '\x69' << '\x6a' << '\x6b' << '\x6c' << '\x6d' << '\x6e' << '\x6f' << '\x70' << '\x71' << '\x72' << '\x73' << '\x74' << '\x75' << '\x76' << '\x77' << '\x78' << '\x79' )
static const Word AnsiCharCount = 0x100;
static const Shortint AnsiLoOffset = 0x0;
static const Word AnsiUpOffset = 0x100;
static const Word AnsiReOffset = 0x200;
static const Word AnsiCaseMapSize = 0x300;
extern PACKAGE char AnsiCaseMap[768];
extern PACKAGE bool AnsiCaseMapReady;
extern PACKAGE Word AnsiCharTypes[256];
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE bool __fastcall StrIsAlpha(const AnsiString S);
extern PACKAGE bool __fastcall StrIsAlphaNum(const AnsiString S);
extern PACKAGE bool __fastcall StrConsistsOfNumberChars(const AnsiString S);
extern PACKAGE bool __fastcall StrContainsChars(const AnsiString S, const Sysutils::TSysCharSet &Chars, bool CheckAll);
extern PACKAGE bool __fastcall StrIsAlphaNumUnderscore(const AnsiString S);
extern PACKAGE bool __fastcall StrIsDigit(const AnsiString S);
extern PACKAGE bool __fastcall StrIsSubset(const AnsiString S, const Sysutils::TSysCharSet &ValidChars);
extern PACKAGE bool __fastcall StrSame(const AnsiString S1, const AnsiString S2);
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
extern PACKAGE AnsiString __fastcall StrRemoveChars(const AnsiString S, const Sysutils::TSysCharSet &Chars);
extern PACKAGE AnsiString __fastcall StrKeepChars(const AnsiString S, const Sysutils::TSysCharSet &Chars);
extern PACKAGE AnsiString __fastcall StrRepeat(const AnsiString S, int Count);
extern PACKAGE AnsiString __fastcall StrRepeatLength(const AnsiString S, const int L);
extern PACKAGE void __fastcall StrReplace(AnsiString &S, const AnsiString Search, const AnsiString Replace, Sysutils::TReplaceFlags Flags = Set<Sysutils::SysUtils__94, rfReplaceAll, rfIgnoreCase> () );
extern PACKAGE AnsiString __fastcall StrReplaceChar(const AnsiString S, const char Source, const char Replace);
extern PACKAGE AnsiString __fastcall StrReplaceChars(const AnsiString S, const Sysutils::TSysCharSet &Chars, char Replace);
extern PACKAGE AnsiString __fastcall StrReplaceButChars(const AnsiString S, const Sysutils::TSysCharSet &Chars, char Replace);
extern PACKAGE AnsiString __fastcall StrReverse(const AnsiString S);
extern PACKAGE void __fastcall StrReverseInPlace(AnsiString &S);
extern PACKAGE AnsiString __fastcall StrSingleQuote(const AnsiString S);
extern PACKAGE AnsiString __fastcall StrSmartCase(const AnsiString S, const Sysutils::TSysCharSet &Delimiters);
extern PACKAGE AnsiString __fastcall StrStringToEscaped(const AnsiString S);
extern PACKAGE AnsiString __fastcall StrStripNonNumberChars(const AnsiString S);
extern PACKAGE AnsiString __fastcall StrToHex(const AnsiString Source);
extern PACKAGE AnsiString __fastcall StrTrimCharLeft(const AnsiString S, char C);
extern PACKAGE AnsiString __fastcall StrTrimCharsLeft(const AnsiString S, const Sysutils::TSysCharSet &Chars);
extern PACKAGE AnsiString __fastcall StrTrimCharsRight(const AnsiString S, const Sysutils::TSysCharSet &Chars);
extern PACKAGE AnsiString __fastcall StrTrimCharRight(const AnsiString S, char C);
extern PACKAGE AnsiString __fastcall StrTrimQuotes(const AnsiString S);
extern PACKAGE AnsiString __fastcall StrUpper(const AnsiString S);
extern PACKAGE void __fastcall StrUpperInPlace(AnsiString &S);
extern PACKAGE void __fastcall StrUpperBuff(char * S);
extern PACKAGE AnsiString __fastcall StrOemToAnsi(const AnsiString S);
extern PACKAGE AnsiString __fastcall StrAnsiToOem(const AnsiString S);
extern PACKAGE void __fastcall StrAddRef(AnsiString &S);
extern PACKAGE void __fastcall StrDecRef(AnsiString &S);
extern PACKAGE int __fastcall StrLength(const AnsiString S);
extern PACKAGE int __fastcall StrRefCount(const AnsiString S);
extern PACKAGE void __fastcall StrResetLength(AnsiString &S);
extern PACKAGE int __fastcall StrCharCount(const AnsiString S, char C);
extern PACKAGE int __fastcall StrCharsCount(const AnsiString S, const Sysutils::TSysCharSet &Chars);
extern PACKAGE int __fastcall StrStrCount(const AnsiString S, const AnsiString SubS);
extern PACKAGE int __fastcall StrCompareRangeEx(const AnsiString S1, const AnsiString S2, int Index, int Count, bool CaseSensitive = false);
extern PACKAGE int __fastcall StrCompare(const AnsiString S1, const AnsiString S2, bool CaseSensitive = false);
extern PACKAGE int __fastcall StrCompareRange(const AnsiString S1, const AnsiString S2, int Index, int Count, bool CaseSensitive = true);
extern PACKAGE AnsiString __fastcall StrRepeatChar(char C, int Count);
extern PACKAGE int __fastcall StrFind(const AnsiString Substr, const AnsiString S, const int Index = 0x1);
extern PACKAGE bool __fastcall StrHasPrefix(const AnsiString S, AnsiString const * Prefixes, const int Prefixes_Size);
extern PACKAGE int __fastcall StrIndex(const AnsiString S, AnsiString const * List, const int List_Size);
extern PACKAGE int __fastcall StrILastPos(const AnsiString SubStr, const AnsiString S);
extern PACKAGE int __fastcall StrIPos(const AnsiString SubStr, const AnsiString S);
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
extern PACKAGE PAnsiCharVector __fastcall StringsToPCharVector(PAnsiCharVector &Dest, const Classes::TStrings* Source);
extern PACKAGE int __fastcall PCharVectorCount(PAnsiCharVector Source);
extern PACKAGE void __fastcall PCharVectorToStrings(const Classes::TStrings* Dest, PAnsiCharVector Source);
extern PACKAGE void __fastcall FreePCharVector(PAnsiCharVector &Dest);
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
extern PACKAGE void __fastcall StrTokenToStrings(AnsiString S, char Separator, const Classes::TStrings* List);
extern PACKAGE bool __fastcall StrWord(char * &S, /* out */ AnsiString &Word);
extern PACKAGE Extended __fastcall StrToFloatSafe(const AnsiString S);
extern PACKAGE int __fastcall StrToIntSafe(const AnsiString S);
extern PACKAGE void __fastcall StrNormIndex(const int StrLen, int &Index, int &Count)/* overload */;
extern PACKAGE Jclbase::TDynStringArray __fastcall ArrayOf(Classes::TStrings* List)/* overload */;
extern PACKAGE int __fastcall AnsiCompareNaturalStr(const AnsiString S1, const AnsiString S2)/* overload */;
extern PACKAGE int __fastcall AnsiCompareNaturalText(const AnsiString S1, const AnsiString S2)/* overload */;

}	/* namespace Jclansistrings */
using namespace Jclansistrings;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclansistrings
