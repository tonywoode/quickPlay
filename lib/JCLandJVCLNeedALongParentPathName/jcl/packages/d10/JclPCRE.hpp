// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclpcre.pas' rev: 10.00

#ifndef JclpcreHPP
#define JclpcreHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Pcre.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclstringconversions.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclpcre
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EPCREError;
class PASCALIMPLEMENTATION EPCREError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
private:
	int FErrorCode;
	
public:
	__fastcall EPCREError(System::PResStringRec ResStringRec, int ErrorCode);
	__property int ErrorCode = {read=FErrorCode, nodefault};
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EPCREError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EPCREError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EPCREError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EPCREError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EPCREError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EPCREError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EPCREError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EPCREError(void) { }
	#pragma option pop
	
};


typedef int TPCREIntArray[1];

typedef int *PPCREIntArray;

#pragma option push -b-
enum TJclRegExOption { roIgnoreCase, roMultiLine, roDotAll, roExtended, roAnchored, roDollarEndOnly, roExtra, roNotBOL, roNotEOL, roUnGreedy, roNotEmpty, roUTF8, roNoAutoCapture, roNoUTF8Check, roAutoCallout, roPartial, roDfaShortest, roDfaRestart, roDfaFirstLine, roDupNames, roNewLineCR, roNewLineLF, roNewLineCRLF, roNewLineAny, roBSRAnyCRLF, roBSRUnicode, roJavascriptCompat, roNoStartOptimize };
#pragma option pop

typedef Set<TJclRegExOption, roIgnoreCase, roNoStartOptimize>  TJclRegExOptions;

struct TJclCaptureRange
{
	
public:
	int FirstPos;
	int LastPos;
} ;

class DELPHICLASS TJclRegEx;
typedef void __fastcall (__closure *TJclRegExCallout)(TJclRegEx* Sender, int Index, int MatchStart, int SubjectPos, int LastCapture, int PatternPos, int NextItemLength, int &ErrorCode);

typedef Byte TPCRECalloutIndex;

typedef DynamicArray<AnsiString >  JclPCRE__3;

class PASCALIMPLEMENTATION TJclRegEx : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Pcre::real_pcre *FCode;
	Pcre::real_pcre_extra *FExtra;
	TJclRegExOptions FOptions;
	AnsiString FPattern;
	bool FDfaMode;
	AnsiString FSubject;
	bool FViewChanges;
	Classes::TList* FChangedCaptures;
	DynamicArray<AnsiString >  FResultValues;
	int FErrorCode;
	AnsiString FErrorMessage;
	int FErrorOffset;
	int *FVector;
	int FVectorSize;
	int FCaptureCount;
	TJclRegExCallout FOnCallout;
	AnsiString __fastcall GetResult();
	AnsiString __fastcall GetCapture(int Index);
	void __fastcall SetCapture(int Index, const AnsiString Value);
	TJclCaptureRange __fastcall GetCaptureRange(int Index);
	AnsiString __fastcall GetNamedCapture(const AnsiString Name);
	void __fastcall SetNamedCapture(const AnsiString Name, const AnsiString Value);
	int __fastcall GetCaptureNameCount(void);
	AnsiString __fastcall GetCaptureName(int Index);
	int __fastcall GetAPIOptions(bool RunTime);
	int __fastcall CalloutHandler(Pcre::pcre_callout_block &CalloutBlock);
	
public:
	__fastcall virtual ~TJclRegEx(void);
	__property TJclRegExOptions Options = {read=FOptions, write=FOptions, nodefault};
	bool __fastcall Compile(const AnsiString Pattern, bool Study, bool UserLocale = false);
	__property AnsiString Pattern = {read=FPattern};
	__property bool DfaMode = {read=FDfaMode, write=FDfaMode, nodefault};
	bool __fastcall Match(const AnsiString Subject, unsigned StartOffset = (unsigned)(0x1));
	__property AnsiString Subject = {read=FSubject};
	__property AnsiString Result = {read=GetResult};
	__property bool ViewChanges = {read=FViewChanges, write=FViewChanges, nodefault};
	__property int CaptureCount = {read=FCaptureCount, write=FCaptureCount, nodefault};
	__property AnsiString Captures[int Index] = {read=GetCapture, write=SetCapture};
	__property TJclCaptureRange CaptureRanges[int Index] = {read=GetCaptureRange};
	__property AnsiString NamedCaptures[AnsiString Name] = {read=GetNamedCapture, write=SetNamedCapture};
	__property int CaptureNameCount = {read=GetCaptureNameCount, nodefault};
	__property AnsiString CaptureNames[int Index] = {read=GetCaptureName};
	int __fastcall IndexOfName(const AnsiString Name);
	bool __fastcall IsNameValid(const AnsiString Name);
	__property int ErrorCode = {read=FErrorCode, nodefault};
	__property AnsiString ErrorMessage = {read=FErrorMessage};
	__property int ErrorOffset = {read=FErrorOffset, nodefault};
	__property TJclRegExCallout OnCallout = {read=FOnCallout, write=FOnCallout};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclRegEx(void) : System::TObject() { }
	#pragma option pop
	
};


typedef TJclRegEx TJclAnsiRegEx;
;

typedef TJclRegExOption TJclAnsiRegExOption;

typedef TJclRegExOptions TJclAnsiRegExOptions;
;

typedef TJclCaptureRange  TJclAnsiCaptureRange;

typedef void __fastcall (__closure *TJclAnsiRegExCallout)(TJclRegEx* Sender, int Index, int MatchStart, int SubjectPos, int LastCapture, int PatternPos, int NextItemLength, int &ErrorCode);

//-- var, const, procedure ---------------------------------------------------
static const Shortint JCL_PCRE_CALLOUT_NOERROR = 0x0;
static const Shortint JCL_PCRE_CALLOUT_FAILCONTINUE = 0x1;
static const short JCL_PCRE_ERROR_CALLOUTERROR = -998;
static const short JCL_PCRE_ERROR_STUDYFAILED = -999;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE void __fastcall InitializeLocaleSupport(void);
extern PACKAGE void __fastcall TerminateLocaleSupport(void);
extern PACKAGE AnsiString __fastcall StrReplaceRegEx(const AnsiString Subject, const AnsiString Pattern, System::TVarRec * Args, const int Args_Size);

}	/* namespace Jclpcre */
using namespace Jclpcre;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclpcre
