// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclsysutils.pas' rev: 10.00

#ifndef JclsysutilsHPP
#define JclsysutilsHPP

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
#include <Classes.hpp>	// Pascal unit
#include <Typinfo.hpp>	// Pascal unit
#include <Syncobjs.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
namespace Jclsysutils
{
  // For some reason, the generator puts this interface after its first
  // usage, resulting in an unusable header file. We fix this by forward
  // declaring the interface.
  __interface IJclCommandLineTool;
}

namespace Jclsysutils
{
//-- type declarations -------------------------------------------------------
__interface ISafeGuard;
typedef System::DelphiInterface<ISafeGuard> _di_ISafeGuard;
__interface ISafeGuard  : public IInterface 
{
	
public:
	virtual void * __fastcall ReleaseItem(void) = 0 ;
	virtual void * __fastcall GetItem(void) = 0 ;
	virtual void __fastcall FreeItem(void) = 0 ;
	__property void * Item = {read=GetItem};
};

__interface IMultiSafeGuard;
typedef System::DelphiInterface<IMultiSafeGuard> _di_IMultiSafeGuard;
__interface IMultiSafeGuard  : public IInterface 
{
	
public:
	virtual void * __fastcall AddItem(void * Item) = 0 ;
	virtual void __fastcall FreeItem(int Index) = 0 ;
	virtual int __fastcall GetCount(void) = 0 ;
	virtual void * __fastcall GetItem(int Index) = 0 ;
	virtual void * __fastcall ReleaseItem(int Index) = 0 ;
	__property int Count = {read=GetCount};
	__property void * Items[int Index] = {read=GetItem};
};

class DELPHICLASS TJclSafeGuard;
class PASCALIMPLEMENTATION TJclSafeGuard : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	void *FItem;
	
public:
	__fastcall TJclSafeGuard(void * Mem);
	__fastcall virtual ~TJclSafeGuard(void);
	void * __fastcall ReleaseItem(void);
	void * __fastcall GetItem(void);
	virtual void __fastcall FreeItem(void);
	__property void * Item = {read=GetItem};
private:
	void *__ISafeGuard;	/* Jclsysutils::ISafeGuard */
	
public:
	operator ISafeGuard*(void) { return (ISafeGuard*)&__ISafeGuard; }
	
};


class DELPHICLASS TJclObjSafeGuard;
class PASCALIMPLEMENTATION TJclObjSafeGuard : public TJclSafeGuard 
{
	typedef TJclSafeGuard inherited;
	
public:
	__fastcall TJclObjSafeGuard(System::TObject* Obj);
	virtual void __fastcall FreeItem(void);
public:
	#pragma option push -w-inl
	/* TJclSafeGuard.Destroy */ inline __fastcall virtual ~TJclObjSafeGuard(void) { }
	#pragma option pop
	
private:
	void *__ISafeGuard;	/* Jclsysutils::ISafeGuard */
	
public:
	operator ISafeGuard*(void) { return (ISafeGuard*)&__ISafeGuard; }
	
};


class DELPHICLASS TJclMultiSafeGuard;
class PASCALIMPLEMENTATION TJclMultiSafeGuard : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Classes::TList* FItems;
	
public:
	__fastcall TJclMultiSafeGuard(void);
	__fastcall virtual ~TJclMultiSafeGuard(void);
	void * __fastcall AddItem(void * Item);
	virtual void __fastcall FreeItem(int Index);
	int __fastcall GetCount(void);
	void * __fastcall GetItem(int Index);
	void * __fastcall ReleaseItem(int Index);
	__property int Count = {read=GetCount, nodefault};
	__property void * Items[int Index] = {read=GetItem};
private:
	void *__IMultiSafeGuard;	/* Jclsysutils::IMultiSafeGuard */
	
public:
	operator IMultiSafeGuard*(void) { return (IMultiSafeGuard*)&__IMultiSafeGuard; }
	
};


class DELPHICLASS TJclObjMultiSafeGuard;
class PASCALIMPLEMENTATION TJclObjMultiSafeGuard : public TJclMultiSafeGuard 
{
	typedef TJclMultiSafeGuard inherited;
	
public:
	virtual void __fastcall FreeItem(int Index);
public:
	#pragma option push -w-inl
	/* TJclMultiSafeGuard.Create */ inline __fastcall TJclObjMultiSafeGuard(void) : TJclMultiSafeGuard() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclMultiSafeGuard.Destroy */ inline __fastcall virtual ~TJclObjMultiSafeGuard(void) { }
	#pragma option pop
	
private:
	void *__IMultiSafeGuard;	/* Jclsysutils::IMultiSafeGuard */
	
public:
	operator IMultiSafeGuard*(void) { return (IMultiSafeGuard*)&__IMultiSafeGuard; }
	
};


class DELPHICLASS ESharedMemError;
class PASCALIMPLEMENTATION ESharedMemError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ESharedMemError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ESharedMemError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ESharedMemError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ESharedMemError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ESharedMemError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ESharedMemError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ESharedMemError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ESharedMemError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ESharedMemError(void) { }
	#pragma option pop
	
};


typedef int __fastcall (*TUntypedSearchCompare)(void * Param, int ItemIndex, const void *Value);

typedef int __fastcall (*TDynArraySortCompare)(void * Item1, void * Item2);

class DELPHICLASS TJclReferenceMemoryStream;
class PASCALIMPLEMENTATION TJclReferenceMemoryStream : public Classes::TCustomMemoryStream 
{
	typedef Classes::TCustomMemoryStream inherited;
	
public:
	__fastcall TJclReferenceMemoryStream(const void * Ptr, int Size);
	virtual int __fastcall Write(const void *Buffer, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclReferenceMemoryStream(void) { }
	#pragma option pop
	
};


__interface IAutoPtr;
typedef System::DelphiInterface<IAutoPtr> _di_IAutoPtr;
__interface IAutoPtr  : public IInterface 
{
	
public:
	virtual void * __fastcall AsPointer(void) = 0 ;
	virtual System::TObject* __fastcall AsObject(void) = 0 ;
	virtual System::TObject* __fastcall ReleaseObject(void) = 0 ;
};

class DELPHICLASS TJclAutoPtr;
class PASCALIMPLEMENTATION TJclAutoPtr : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	System::TObject* FValue;
	
public:
	__fastcall TJclAutoPtr(System::TObject* AValue);
	__fastcall virtual ~TJclAutoPtr(void);
	void * __fastcall AsPointer(void);
	System::TObject* __fastcall AsObject(void);
	System::TObject* __fastcall ReleaseObject(void);
private:
	void *__IAutoPtr;	/* Jclsysutils::IAutoPtr */
	
public:
	operator IAutoPtr*(void) { return (IAutoPtr*)&__IAutoPtr; }
	
};


class DELPHICLASS EJclVMTError;
class PASCALIMPLEMENTATION EJclVMTError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclVMTError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclVMTError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclVMTError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclVMTError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclVMTError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclVMTError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclVMTError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclVMTError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclVMTError(void) { }
	#pragma option pop
	
};


typedef Word TDynamicIndexList[134217728];

typedef Word *PDynamicIndexList;

typedef void *TDynamicAddressList[134217728];

typedef void * *PDynamicAddressList;

struct TFieldEntry;
typedef TFieldEntry *PFieldEntry;

#pragma pack(push,1)
struct TFieldEntry
{
	
public:
	int OffSet;
	Word IDX;
	System::ShortString Name;
} ;
#pragma pack(pop)

struct TFieldClassTable;
typedef TFieldClassTable *PFieldClassTable;

#pragma pack(push,1)
struct TFieldClassTable
{
	
public:
	short Count;
	TMetaClass* *Classes[8192];
} ;
#pragma pack(pop)

struct TFieldTable;
typedef TFieldTable *PFieldTable;

#pragma pack(push,1)
struct TFieldTable
{
	
public:
	Word EntryCount;
	TFieldClassTable *FieldClassTable;
	#pragma pack(push,1)
	TFieldEntry FirstEntry;
	#pragma pack(pop)
} ;
#pragma pack(pop)

struct TMethodEntry;
typedef TMethodEntry *PMethodEntry;

#pragma pack(push,1)
struct TMethodEntry
{
	
public:
	Word EntrySize;
	void *Address;
	System::ShortString Name;
} ;
#pragma pack(pop)

struct TMethodTable;
typedef TMethodTable *PMethodTable;

#pragma pack(push,1)
struct TMethodTable
{
	
public:
	Word Count;
	#pragma pack(push,1)
	TMethodEntry FirstEntry;
	#pragma pack(pop)
} ;
#pragma pack(pop)

typedef Byte TDigitCount;

typedef Shortint TDigitValue;

typedef Shortint TNumericSystemBase;

class DELPHICLASS TJclNumericFormat;
class PASCALIMPLEMENTATION TJclNumericFormat : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TDigitCount FWantedPrecision;
	TDigitCount FPrecision;
	TDigitCount FNumberOfFractionalDigits;
	int FExpDivision;
	TDigitCount FDigitBlockSize;
	TDigitCount FWidth;
	char FSignChars[2];
	TNumericSystemBase FBase;
	char FFractionalPartSeparator;
	char FDigitBlockSeparator;
	bool FShowPositiveSign;
	char FPaddingChar;
	AnsiString FMultiplier;
	int __fastcall GetDigitValue(char Digit);
	char __fastcall GetNegativeSign(void);
	char __fastcall GetPositiveSign(void);
	void __fastcall InvalidDigit(char Digit);
	void __fastcall SetPrecision(const TDigitCount Value);
	void __fastcall SetBase(const TNumericSystemBase Value);
	void __fastcall SetNegativeSign(const char Value);
	void __fastcall SetPositiveSign(const char Value);
	void __fastcall SetExpDivision(const int Value);
	
protected:
	AnsiString __fastcall IntToStr(const __int64 Value, /* out */ int &FirstDigitPos)/* overload */;
	bool __fastcall ShowSign(const Extended Value)/* overload */;
	bool __fastcall ShowSign(const __int64 Value)/* overload */;
	char __fastcall SignChar(const Extended Value)/* overload */;
	char __fastcall SignChar(const __int64 Value)/* overload */;
	__property TDigitCount WantedPrecision = {read=FWantedPrecision, nodefault};
	
public:
	__fastcall TJclNumericFormat(void);
	char __fastcall Digit(TDigitValue DigitValue);
	TDigitValue __fastcall DigitValue(char Digit);
	bool __fastcall IsDigit(char Value);
	int __fastcall Sign(char Value);
	void __fastcall GetMantissaExp(const Extended Value, /* out */ AnsiString &Mantissa, /* out */ int &Exponent);
	AnsiString __fastcall FloatToHTML(const Extended Value);
	AnsiString __fastcall IntToStr(const __int64 Value)/* overload */;
	AnsiString __fastcall FloatToStr(const Extended Value)/* overload */;
	__int64 __fastcall StrToInt(const AnsiString Value);
	__property TNumericSystemBase Base = {read=FBase, write=SetBase, nodefault};
	__property TDigitCount Precision = {read=FPrecision, write=SetPrecision, nodefault};
	__property TDigitCount NumberOfFractionalDigits = {read=FNumberOfFractionalDigits, write=FNumberOfFractionalDigits, nodefault};
	__property int ExponentDivision = {read=FExpDivision, write=SetExpDivision, nodefault};
	__property TDigitCount DigitBlockSize = {read=FDigitBlockSize, write=FDigitBlockSize, nodefault};
	__property char DigitBlockSeparator = {read=FDigitBlockSeparator, write=FDigitBlockSeparator, nodefault};
	__property char FractionalPartSeparator = {read=FFractionalPartSeparator, write=FFractionalPartSeparator, nodefault};
	__property AnsiString Multiplier = {read=FMultiplier, write=FMultiplier};
	__property char PaddingChar = {read=FPaddingChar, write=FPaddingChar, nodefault};
	__property bool ShowPositiveSign = {read=FShowPositiveSign, write=FShowPositiveSign, nodefault};
	__property TDigitCount Width = {read=FWidth, write=FWidth, nodefault};
	__property char NegativeSign = {read=GetNegativeSign, write=SetNegativeSign, nodefault};
	__property char PositiveSign = {read=GetPositiveSign, write=SetPositiveSign, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclNumericFormat(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TTextHandler)(const AnsiString Text);

__interface IJclCommandLineTool;
typedef System::DelphiInterface<IJclCommandLineTool> _di_IJclCommandLineTool;
__interface  INTERFACE_UUID("{A0034B09-A074-D811-847D-0030849E4592}") IJclCommandLineTool  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetExeName(void) = 0 ;
	virtual Classes::TStrings* __fastcall GetOptions(void) = 0 ;
	virtual AnsiString __fastcall GetOutput(void) = 0 ;
	virtual TTextHandler __fastcall GetOutputCallback(void) = 0 ;
	virtual void __fastcall AddPathOption(const AnsiString Option, const AnsiString Path) = 0 ;
	virtual bool __fastcall Execute(const AnsiString CommandLine) = 0 ;
	virtual void __fastcall SetOutputCallback(const TTextHandler CallbackMethod) = 0 ;
	__property AnsiString ExeName = {read=GetExeName};
	__property Classes::TStrings* Options = {read=GetOptions};
	__property TTextHandler OutputCallback = {read=GetOutputCallback, write=SetOutputCallback};
	__property AnsiString Output = {read=GetOutput};
};

class DELPHICLASS EJclCommandLineToolError;
class PASCALIMPLEMENTATION EJclCommandLineToolError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclCommandLineToolError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclCommandLineToolError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclCommandLineToolError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclCommandLineToolError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclCommandLineToolError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclCommandLineToolError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclCommandLineToolError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclCommandLineToolError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclCommandLineToolError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclCommandLineTool;
class PASCALIMPLEMENTATION TJclCommandLineTool : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	AnsiString FExeName;
	Classes::TStringList* FOptions;
	AnsiString FOutput;
	TTextHandler FOutputCallback;
	
public:
	__fastcall TJclCommandLineTool(const AnsiString AExeName);
	__fastcall virtual ~TJclCommandLineTool(void);
	AnsiString __fastcall GetExeName();
	Classes::TStrings* __fastcall GetOptions(void);
	AnsiString __fastcall GetOutput();
	TTextHandler __fastcall GetOutputCallback();
	void __fastcall AddPathOption(const AnsiString Option, const AnsiString Path);
	bool __fastcall Execute(const AnsiString CommandLine);
	void __fastcall SetOutputCallback(const TTextHandler CallbackMethod);
	__property AnsiString ExeName = {read=GetExeName};
	__property Classes::TStrings* Options = {read=GetOptions};
	__property TTextHandler OutputCallback = {read=GetOutputCallback, write=SetOutputCallback};
	__property AnsiString Output = {read=GetOutput};
private:
	void *__IJclCommandLineTool;	/* Jclsysutils::IJclCommandLineTool */
	
public:
	operator IJclCommandLineTool*(void) { return (IJclCommandLineTool*)&__IJclCommandLineTool; }
	
};


typedef unsigned TModuleHandle;

class DELPHICLASS EJclConversionError;
class PASCALIMPLEMENTATION EJclConversionError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclConversionError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclConversionError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclConversionError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclConversionError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclConversionError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclConversionError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclConversionError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclConversionError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclConversionError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclIntfCriticalSection;
class PASCALIMPLEMENTATION TJclIntfCriticalSection : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Syncobjs::TCriticalSection* FCriticalSection;
	
public:
	__fastcall TJclIntfCriticalSection(void);
	__fastcall virtual ~TJclIntfCriticalSection(void);
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclSimpleLog;
class PASCALIMPLEMENTATION TJclSimpleLog : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FDateTimeFormatStr;
	int FLogFileHandle;
	AnsiString FLogFileName;
	bool FLoggingActive;
	bool FLogWasEmpty;
	bool __fastcall GetLogOpen(void);
	
protected:
	AnsiString __fastcall CreateDefaultFileName();
	
public:
	__fastcall TJclSimpleLog(const AnsiString ALogFileName);
	__fastcall virtual ~TJclSimpleLog(void);
	void __fastcall ClearLog(void);
	void __fastcall CloseLog(void);
	void __fastcall OpenLog(void);
	void __fastcall Write(const AnsiString Text, int Indent = 0x0, bool KeepOpen = true)/* overload */;
	void __fastcall Write(Classes::TStrings* Strings, int Indent = 0x0, bool KeepOpen = true)/* overload */;
	void __fastcall TimeWrite(const AnsiString Text, int Indent = 0x0, bool KeepOpen = true)/* overload */;
	void __fastcall TimeWrite(Classes::TStrings* Strings, int Indent = 0x0, bool KeepOpen = true)/* overload */;
	void __fastcall WriteStamp(int SeparatorLen = 0x0, bool KeepOpen = true);
	__property AnsiString DateTimeFormatStr = {read=FDateTimeFormatStr, write=FDateTimeFormatStr};
	__property AnsiString LogFileName = {read=FLogFileName};
	__property bool LoggingActive = {read=FLoggingActive, write=FLoggingActive, default=1};
	__property bool LogOpen = {read=GetLogOpen, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static const Word ABORT_EXIT_CODE = 0x4c7;
static const unsigned INVALID_MODULEHANDLE_VALUE = 0x0;
static const char ListSeparator = '\x3b';
extern PACKAGE TJclSimpleLog* SimpleLog;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE void __fastcall ResetMemory(/* out */ void *P, int Size);
extern PACKAGE void __fastcall GetAndFillMem(void * &P, const int Size, const Byte Value);
extern PACKAGE void __fastcall FreeMemAndNil(void * &P);
extern PACKAGE char * __fastcall PCharOrNil(const AnsiString S);
extern PACKAGE char * __fastcall PAnsiCharOrNil(const AnsiString S);
extern PACKAGE WideChar * __fastcall PWideCharOrNil(const WideString W);
extern PACKAGE int __fastcall SizeOfMem(const void * APointer);
extern PACKAGE bool __fastcall WriteProtectedMemory(void * BaseAddress, void * Buffer, unsigned Size, /* out */ unsigned &WrittenBytes);
extern PACKAGE void * __fastcall Guard(void * Mem, _di_IMultiSafeGuard &SafeGuard)/* overload */;
extern PACKAGE System::TObject* __fastcall Guard(System::TObject* Obj, _di_IMultiSafeGuard &SafeGuard)/* overload */;
extern PACKAGE void * __fastcall Guard(void * Mem, /* out */ _di_ISafeGuard &SafeGuard)/* overload */;
extern PACKAGE System::TObject* __fastcall Guard(System::TObject* Obj, /* out */ _di_ISafeGuard &SafeGuard)/* overload */;
extern PACKAGE void * __fastcall GuardGetMem(unsigned Size, /* out */ _di_ISafeGuard &SafeGuard);
extern PACKAGE void * __fastcall GuardAllocMem(unsigned Size, /* out */ _di_ISafeGuard &SafeGuard);
extern PACKAGE int __fastcall SharedGetMem(void *P, const AnsiString Name, unsigned Size, unsigned DesiredAccess = (unsigned)(0xf001f));
extern PACKAGE void * __fastcall SharedAllocMem(const AnsiString Name, unsigned Size, unsigned DesiredAccess = (unsigned)(0xf001f));
extern PACKAGE bool __fastcall SharedFreeMem(void *P);
extern PACKAGE bool __fastcall SharedOpenMem(void *P, const AnsiString Name, unsigned DesiredAccess = (unsigned)(0xf001f))/* overload */;
extern PACKAGE void * __fastcall SharedOpenMem(const AnsiString Name, unsigned DesiredAccess = (unsigned)(0xf001f))/* overload */;
extern PACKAGE bool __fastcall SharedCloseMem(void *P);
extern PACKAGE int __fastcall SearchSortedList(Classes::TList* List, Classes::TListSortCompare SortFunc, void * Item, bool Nearest = false);
extern PACKAGE int __fastcall SearchSortedUntyped(void * Param, int ItemCount, TUntypedSearchCompare SearchFunc, const void *Value, bool Nearest = false);
extern PACKAGE void __fastcall SortDynArray(const void * ArrayPtr, unsigned ElementSize, TDynArraySortCompare SortFunc);
extern PACKAGE int __fastcall SearchDynArray(const void * ArrayPtr, unsigned ElementSize, TDynArraySortCompare SortFunc, void * ValuePtr, bool Nearest = false);
extern PACKAGE int __fastcall DynArrayCompareByte(void * Item1, void * Item2);
extern PACKAGE int __fastcall DynArrayCompareShortInt(void * Item1, void * Item2);
extern PACKAGE int __fastcall DynArrayCompareWord(void * Item1, void * Item2);
extern PACKAGE int __fastcall DynArrayCompareSmallInt(void * Item1, void * Item2);
extern PACKAGE int __fastcall DynArrayCompareInteger(void * Item1, void * Item2);
extern PACKAGE int __fastcall DynArrayCompareCardinal(void * Item1, void * Item2);
extern PACKAGE int __fastcall DynArrayCompareInt64(void * Item1, void * Item2);
extern PACKAGE int __fastcall DynArrayCompareSingle(void * Item1, void * Item2);
extern PACKAGE int __fastcall DynArrayCompareDouble(void * Item1, void * Item2);
extern PACKAGE int __fastcall DynArrayCompareExtended(void * Item1, void * Item2);
extern PACKAGE int __fastcall DynArrayCompareFloat(void * Item1, void * Item2);
extern PACKAGE int __fastcall DynArrayCompareAnsiString(void * Item1, void * Item2);
extern PACKAGE int __fastcall DynArrayCompareAnsiText(void * Item1, void * Item2);
extern PACKAGE int __fastcall DynArrayCompareWideString(void * Item1, void * Item2);
extern PACKAGE int __fastcall DynArrayCompareWideText(void * Item1, void * Item2);
extern PACKAGE int __fastcall DynArrayCompareString(void * Item1, void * Item2);
extern PACKAGE int __fastcall DynArrayCompareText(void * Item1, void * Item2);
extern PACKAGE void __fastcall ClearObjectList(Classes::TList* List);
extern PACKAGE void __fastcall FreeObjectList(Classes::TList* &List);
extern PACKAGE _di_IAutoPtr __fastcall CreateAutoPtr(System::TObject* Value);
extern PACKAGE AnsiString __fastcall Iff(const bool Condition, const AnsiString TruePart, const AnsiString FalsePart)/* overload */;
extern PACKAGE char __fastcall Iff(const bool Condition, const char TruePart, const char FalsePart)/* overload */;
extern PACKAGE Byte __fastcall Iff(const bool Condition, const Byte TruePart, const Byte FalsePart)/* overload */;
extern PACKAGE int __fastcall Iff(const bool Condition, const int TruePart, const int FalsePart)/* overload */;
extern PACKAGE unsigned __fastcall Iff(const bool Condition, const unsigned TruePart, const unsigned FalsePart)/* overload */;
extern PACKAGE Extended __fastcall Iff(const bool Condition, const Extended TruePart, const Extended FalsePart)/* overload */;
extern PACKAGE bool __fastcall Iff(const bool Condition, const bool TruePart, const bool FalsePart)/* overload */;
extern PACKAGE void * __fastcall Iff(const bool Condition, const void * TruePart, const void * FalsePart)/* overload */;
extern PACKAGE __int64 __fastcall Iff(const bool Condition, const __int64 TruePart, const __int64 FalsePart)/* overload */;
extern PACKAGE Variant __fastcall Iff(const bool Condition, const Variant &TruePart, const Variant &FalsePart)/* overload */;
extern PACKAGE int __fastcall GetVirtualMethodCount(TMetaClass* AClass);
extern PACKAGE void * __fastcall GetVirtualMethod(TMetaClass* AClass, const int Index);
extern PACKAGE void __fastcall SetVirtualMethod(TMetaClass* AClass, const int Index, const void * Method);
extern PACKAGE int __fastcall GetDynamicMethodCount(TMetaClass* AClass);
extern PACKAGE PDynamicIndexList __fastcall GetDynamicIndexList(TMetaClass* AClass);
extern PACKAGE PDynamicAddressList __fastcall GetDynamicAddressList(TMetaClass* AClass);
extern PACKAGE bool __fastcall HasDynamicMethod(TMetaClass* AClass, int Index);
extern PACKAGE void * __fastcall GetDynamicMethod(TMetaClass* AClass, int Index);
extern PACKAGE Typinfo::PTypeInfo __fastcall GetInitTable(TMetaClass* AClass);
extern PACKAGE PFieldTable __fastcall GetFieldTable(TMetaClass* AClass);
extern PACKAGE PMethodTable __fastcall GetMethodTable(TMetaClass* AClass);
extern PACKAGE PMethodEntry __fastcall GetMethodEntry(PMethodTable MethodTable, int Index);
extern PACKAGE void __fastcall SetClassParent(TMetaClass* AClass, TMetaClass* NewClassParent);
extern PACKAGE TMetaClass* __fastcall GetClassParent(TMetaClass* AClass);
extern PACKAGE bool __fastcall IsClass(void * Address);
extern PACKAGE bool __fastcall IsObject(void * Address);
extern PACKAGE bool __fastcall InheritsFromByName(TMetaClass* AClass, const AnsiString AClassName);
extern PACKAGE System::TObject* __fastcall GetImplementorOfInterface(const System::_di_IInterface I);
extern PACKAGE AnsiString __fastcall IntToStrZeroPad(int Value, int Count);
extern PACKAGE unsigned __fastcall Execute(const AnsiString CommandLine, AnsiString &Output, bool RawOutput = false, System::PBoolean AbortPtr = (void *)(0x0))/* overload */;
extern PACKAGE unsigned __fastcall Execute(const AnsiString CommandLine, TTextHandler OutputLineCallback, bool RawOutput = false, System::PBoolean AbortPtr = (void *)(0x0))/* overload */;
extern PACKAGE char __fastcall ReadKey(void);
extern PACKAGE bool __fastcall LoadModule(unsigned &Module, AnsiString FileName);
extern PACKAGE bool __fastcall LoadModuleEx(unsigned &Module, AnsiString FileName, unsigned Flags);
extern PACKAGE void __fastcall UnloadModule(unsigned &Module);
extern PACKAGE void * __fastcall GetModuleSymbol(unsigned Module, AnsiString SymbolName);
extern PACKAGE void * __fastcall GetModuleSymbolEx(unsigned Module, AnsiString SymbolName, bool &Accu);
extern PACKAGE bool __fastcall ReadModuleData(unsigned Module, AnsiString SymbolName, void *Buffer, unsigned Size);
extern PACKAGE bool __fastcall WriteModuleData(unsigned Module, AnsiString SymbolName, void *Buffer, unsigned Size);
extern PACKAGE bool __fastcall StrToBoolean(const AnsiString S);
extern PACKAGE AnsiString __fastcall BooleanToStr(bool B);
extern PACKAGE bool __fastcall IntToBool(int I);
extern PACKAGE int __fastcall BoolToInt(bool B);
extern PACKAGE unsigned __fastcall SystemTObjectInstance(void);
extern PACKAGE bool __fastcall IsCompiledWithPackages(void);
extern PACKAGE AnsiString __fastcall JclGUIDToString(const GUID &GUID);
extern PACKAGE GUID __fastcall JclStringToGUID(const AnsiString S);
extern PACKAGE void __fastcall ListAddItems(AnsiString &List, const AnsiString Separator, const AnsiString Items);
extern PACKAGE void __fastcall ListIncludeItems(AnsiString &List, const AnsiString Separator, const AnsiString Items);
extern PACKAGE void __fastcall ListRemoveItems(AnsiString &List, const AnsiString Separator, const AnsiString Items);
extern PACKAGE void __fastcall ListDelItem(AnsiString &List, const AnsiString Separator, const int Index);
extern PACKAGE int __fastcall ListItemCount(const AnsiString List, const AnsiString Separator);
extern PACKAGE AnsiString __fastcall ListGetItem(const AnsiString List, const AnsiString Separator, const int Index);
extern PACKAGE void __fastcall ListSetItem(AnsiString &List, const AnsiString Separator, const int Index, const AnsiString Value);
extern PACKAGE int __fastcall ListItemIndex(const AnsiString List, const AnsiString Separator, const AnsiString Item);
extern PACKAGE void __fastcall InitSimpleLog(const AnsiString ALogFileName = "", bool AOpenLog = true);

}	/* namespace Jclsysutils */
using namespace Jclsysutils;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclsysutils
