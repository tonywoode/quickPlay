// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclstringconversions.pas' rev: 10.00

#ifndef JclstringconversionsHPP
#define JclstringconversionsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclstringconversions
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EJclStringConversionError;
class PASCALIMPLEMENTATION EJclStringConversionError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclStringConversionError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclStringConversionError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclStringConversionError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclStringConversionError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclStringConversionError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclStringConversionError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclStringConversionError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclStringConversionError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclStringConversionError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclUnexpectedEOSequenceError;
class PASCALIMPLEMENTATION EJclUnexpectedEOSequenceError : public EJclStringConversionError 
{
	typedef EJclStringConversionError inherited;
	
public:
	__fastcall EJclUnexpectedEOSequenceError(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclUnexpectedEOSequenceError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclStringConversionError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclUnexpectedEOSequenceError(int Ident)/* overload */ : EJclStringConversionError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclUnexpectedEOSequenceError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclStringConversionError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclUnexpectedEOSequenceError(const AnsiString Msg, int AHelpContext) : EJclStringConversionError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclUnexpectedEOSequenceError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclStringConversionError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclUnexpectedEOSequenceError(int Ident, int AHelpContext)/* overload */ : EJclStringConversionError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclUnexpectedEOSequenceError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclStringConversionError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclUnexpectedEOSequenceError(void) { }
	#pragma option pop
	
};


typedef bool __fastcall (*TJclStreamGetNextCharFunc)(Classes::TStream* S, /* out */ unsigned &Ch);

typedef bool __fastcall (*TJclStreamSkipCharsFunc)(Classes::TStream* S, int &NbSeq);

typedef bool __fastcall (*TJclStreamSetNextCharFunc)(Classes::TStream* S, unsigned Ch);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE void __fastcall ExpandASCIIString(const char * Source, WideChar * Target, int Count);
extern PACKAGE unsigned __fastcall UTF8GetNextChar(const AnsiString S, int &StrPos);
extern PACKAGE bool __fastcall UTF8GetNextCharFromStream(Classes::TStream* S, /* out */ unsigned &Ch);
extern PACKAGE bool __fastcall UTF8SkipChars(const AnsiString S, int &StrPos, int &NbSeq);
extern PACKAGE bool __fastcall UTF8SkipCharsFromStream(Classes::TStream* S, int &NbSeq);
extern PACKAGE bool __fastcall UTF8SetNextChar(AnsiString &S, int &StrPos, unsigned Ch);
extern PACKAGE bool __fastcall UTF8SetNextCharToStream(Classes::TStream* S, unsigned Ch);
extern PACKAGE unsigned __fastcall UTF16GetNextChar(const WideString S, int &StrPos)/* overload */;
extern PACKAGE bool __fastcall UTF16GetNextCharFromStream(Classes::TStream* S, /* out */ unsigned &Ch);
extern PACKAGE unsigned __fastcall UTF16GetPreviousChar(const WideString S, int &StrPos)/* overload */;
extern PACKAGE bool __fastcall UTF16SkipChars(const WideString S, int &StrPos, int &NbSeq)/* overload */;
extern PACKAGE bool __fastcall UTF16SkipCharsFromStream(Classes::TStream* S, int &NbSeq);
extern PACKAGE bool __fastcall UTF16SetNextChar(WideString &S, int &StrPos, unsigned Ch)/* overload */;
extern PACKAGE bool __fastcall UTF16SetNextCharToStream(Classes::TStream* S, unsigned Ch);
extern PACKAGE unsigned __fastcall AnsiGetNextChar(const AnsiString S, int &StrPos)/* overload */;
extern PACKAGE bool __fastcall AnsiGetNextCharFromStream(Classes::TStream* S, /* out */ unsigned &Ch)/* overload */;
extern PACKAGE unsigned __fastcall AnsiGetNextChar(const AnsiString S, Word CodePage, int &StrPos)/* overload */;
extern PACKAGE bool __fastcall AnsiGetNextCharFromStream(Classes::TStream* S, Word CodePage, /* out */ unsigned &Ch)/* overload */;
extern PACKAGE bool __fastcall AnsiSkipChars(const AnsiString S, int &StrPos, int &NbSeq);
extern PACKAGE bool __fastcall AnsiSkipCharsFromStream(Classes::TStream* S, int &NbSeq);
extern PACKAGE bool __fastcall AnsiSetNextChar(AnsiString &S, int &StrPos, unsigned Ch)/* overload */;
extern PACKAGE bool __fastcall AnsiSetNextCharToStream(Classes::TStream* S, unsigned Ch)/* overload */;
extern PACKAGE bool __fastcall AnsiSetNextChar(AnsiString &S, Word CodePage, int &StrPos, unsigned Ch)/* overload */;
extern PACKAGE bool __fastcall AnsiSetNextCharToStream(Classes::TStream* S, Word CodePage, unsigned Ch)/* overload */;
extern PACKAGE unsigned __fastcall StringGetNextChar(const AnsiString S, int &StrPos);
extern PACKAGE bool __fastcall StringSkipChars(const AnsiString S, int &StrPos, int &NbSeq);
extern PACKAGE bool __fastcall StringSetNextChar(AnsiString &S, int &StrPos, unsigned Ch);
extern PACKAGE AnsiString __fastcall WideStringToUTF8(const WideString S);
extern PACKAGE WideString __fastcall UTF8ToWideString(const AnsiString S);
extern PACKAGE Jclbase::TUCS4Array __fastcall WideStringToUCS4(const WideString S);
extern PACKAGE WideString __fastcall UCS4ToWideString(const Jclbase::TUCS4Array S);
extern PACKAGE AnsiString __fastcall AnsiStringToUTF8(const AnsiString S);
extern PACKAGE AnsiString __fastcall UTF8ToAnsiString(const AnsiString S);
extern PACKAGE WideString __fastcall AnsiStringToUTF16(const AnsiString S);
extern PACKAGE AnsiString __fastcall UTF16ToAnsiString(const WideString S);
extern PACKAGE Jclbase::TUCS4Array __fastcall AnsiStringToUCS4(const AnsiString S);
extern PACKAGE AnsiString __fastcall UCS4ToAnsiString(const Jclbase::TUCS4Array S);
extern PACKAGE AnsiString __fastcall StringToUTF8(const AnsiString S);
extern PACKAGE bool __fastcall TryStringToUTF8(const AnsiString S, /* out */ AnsiString &D);
extern PACKAGE AnsiString __fastcall UTF8ToString(const AnsiString S);
extern PACKAGE bool __fastcall TryUTF8ToString(const AnsiString S, /* out */ AnsiString &D);
extern PACKAGE WideString __fastcall StringToUTF16(const AnsiString S);
extern PACKAGE bool __fastcall TryStringToUTF16(const AnsiString S, /* out */ WideString &D);
extern PACKAGE AnsiString __fastcall UTF16ToString(const WideString S);
extern PACKAGE bool __fastcall TryUTF16ToString(const WideString S, /* out */ AnsiString &D);
extern PACKAGE Jclbase::TUCS4Array __fastcall StringToUCS4(const AnsiString S);
extern PACKAGE bool __fastcall TryStringToUCS4(const AnsiString S, /* out */ Jclbase::TUCS4Array &D);
extern PACKAGE AnsiString __fastcall UCS4ToString(const Jclbase::TUCS4Array S);
extern PACKAGE bool __fastcall TryUCS4ToString(const Jclbase::TUCS4Array S, /* out */ AnsiString &D);
extern PACKAGE WideString __fastcall UTF8ToUTF16(const AnsiString S);
extern PACKAGE bool __fastcall TryUTF8ToUTF16(const AnsiString S, /* out */ WideString &D);
extern PACKAGE AnsiString __fastcall UTF16ToUTF8(const WideString S);
extern PACKAGE bool __fastcall TryUTF16ToUTF8(const WideString S, /* out */ AnsiString &D);
extern PACKAGE Jclbase::TUCS4Array __fastcall UTF8ToUCS4(const AnsiString S);
extern PACKAGE bool __fastcall TryUTF8ToUCS4(const AnsiString S, /* out */ Jclbase::TUCS4Array &D);
extern PACKAGE AnsiString __fastcall UCS4ToUTF8(const Jclbase::TUCS4Array S);
extern PACKAGE bool __fastcall TryUCS4ToUTF8(const Jclbase::TUCS4Array S, /* out */ AnsiString &D);
extern PACKAGE Jclbase::TUCS4Array __fastcall UTF16ToUCS4(const WideString S);
extern PACKAGE bool __fastcall TryUTF16ToUCS4(const WideString S, /* out */ Jclbase::TUCS4Array &D);
extern PACKAGE WideString __fastcall UCS4ToUTF16(const Jclbase::TUCS4Array S);
extern PACKAGE bool __fastcall TryUCS4ToUTF16(const Jclbase::TUCS4Array S, /* out */ WideString &D);
extern PACKAGE int __fastcall UTF8CharCount(const AnsiString S);
extern PACKAGE int __fastcall UTF16CharCount(const WideString S);
extern PACKAGE int __fastcall UCS2CharCount(const WideString S);
extern PACKAGE int __fastcall UCS4CharCount(const Jclbase::TUCS4Array S);
extern PACKAGE bool __fastcall GetUCS4CharAt(const AnsiString UTF8Str, int Index, /* out */ unsigned &Value)/* overload */;
extern PACKAGE bool __fastcall GetUCS4CharAt(const WideString WideStr, int Index, /* out */ unsigned &Value, bool IsUTF16 = true)/* overload */;
extern PACKAGE bool __fastcall GetUCS4CharAt(const Jclbase::TUCS4Array UCS4Str, int Index, /* out */ unsigned &Value)/* overload */;
extern PACKAGE char __fastcall UCS4ToAnsiChar(unsigned Value);
extern PACKAGE WideChar __fastcall UCS4ToWideChar(unsigned Value);
extern PACKAGE char __fastcall UCS4ToChar(unsigned Value);
extern PACKAGE unsigned __fastcall AnsiCharToUCS4(char Value);
extern PACKAGE unsigned __fastcall WideCharToUCS4(WideChar Value);
extern PACKAGE unsigned __fastcall CharToUCS4(char Value);

}	/* namespace Jclstringconversions */
using namespace Jclstringconversions;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclstringconversions
