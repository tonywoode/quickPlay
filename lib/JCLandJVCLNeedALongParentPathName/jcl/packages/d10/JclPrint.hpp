// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclprint.pas' rev: 10.00

#ifndef JclprintHPP
#define JclprintHPP

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
#include <Stdctrls.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclprint
{
//-- type declarations -------------------------------------------------------
typedef Word TWordArray[256];

typedef Word *PWordArray;

class DELPHICLASS EJclPrinterError;
class PASCALIMPLEMENTATION EJclPrinterError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclPrinterError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclPrinterError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclPrinterError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclPrinterError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclPrinterError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclPrinterError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclPrinterError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclPrinterError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclPrinterError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclPrintSet;
class PASCALIMPLEMENTATION TJclPrintSet : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	char *FDevice;
	char *FDriver;
	char *FPort;
	unsigned FHandle;
	_devicemodeA *FDeviceMode;
	int FPrinter;
	Word *FBinArray;
	Byte FNumBins;
	Word *FPaperArray;
	Byte FNumPapers;
	int FDpiX;
	int FiDpiY;
	void __fastcall CheckPrinter(void);
	void __fastcall SetBinArray(void);
	void __fastcall SetPaperArray(void);
	AnsiString __fastcall DefaultPaperName(const Word PaperID);
	
protected:
	void __fastcall SetOrientation(int Orientation);
	int __fastcall GetOrientation(void);
	void __fastcall SetPaperSize(int Size);
	int __fastcall GetPaperSize(void);
	void __fastcall SetPaperLength(int Length);
	int __fastcall GetPaperLength(void);
	void __fastcall SetPaperWidth(int Width);
	int __fastcall GetPaperWidth(void);
	void __fastcall SetScale(int Scale);
	int __fastcall GetScale(void);
	void __fastcall SetCopies(int Copies);
	int __fastcall GetCopies(void);
	void __fastcall SetBin(int Bin);
	int __fastcall GetBin(void);
	void __fastcall SetPrintQuality(int Quality);
	int __fastcall GetPrintQuality(void);
	void __fastcall SetColor(int Color);
	int __fastcall GetColor(void);
	void __fastcall SetDuplex(int Duplex);
	int __fastcall GetDuplex(void);
	void __fastcall SetYResolution(int YRes);
	int __fastcall GetYResolution(void);
	void __fastcall SetTrueTypeOption(int Option);
	int __fastcall GetTrueTypeOption(void);
	AnsiString __fastcall GetPrinterName();
	AnsiString __fastcall GetPrinterPort();
	AnsiString __fastcall GetPrinterDriver();
	void __fastcall SetBinFromList(Byte BinNum);
	Byte __fastcall GetBinIndex(void);
	void __fastcall SetPaperFromList(Byte PaperNum);
	Byte __fastcall GetPaperIndex(void);
	void __fastcall SetPort(AnsiString Port);
	
public:
	__fastcall virtual TJclPrintSet(void);
	__fastcall virtual ~TJclPrintSet(void);
	void __fastcall GetBinSourceList(Classes::TStrings* List)/* overload */;
	void __fastcall GetPaperList(Classes::TStrings* List)/* overload */;
	void __fastcall SetDeviceMode(bool Creating);
	void __fastcall UpdateDeviceMode(void);
	void __fastcall SaveToDefaults(void);
	void __fastcall SavePrinterAsDefault(void);
	void __fastcall ResetPrinterDialogs(void);
	int __fastcall XInchToDot(const double Inches);
	int __fastcall YInchToDot(const double Inches);
	int __fastcall XCmToDot(const double Cm);
	int __fastcall YCmToDot(const double Cm);
	int __fastcall CpiToDot(const double Cpi, const double Chars);
	int __fastcall LpiToDot(const double Lpi, const double Lines);
	void __fastcall TextOutInch(const double X, const double Y, const AnsiString Text);
	void __fastcall TextOutCm(const double X, const double Y, const AnsiString Text);
	void __fastcall TextOutCpiLpi(const double Cpi, const double Chars, const double Lpi, const double Lines, const AnsiString Text);
	void __fastcall CustomPageSetup(const double Width, const double Height);
	void __fastcall SaveToIniFile(const AnsiString IniFileName, const AnsiString Section);
	bool __fastcall ReadFromIniFile(const AnsiString IniFileName, const AnsiString Section);
	__property int Orientation = {read=GetOrientation, write=SetOrientation, nodefault};
	__property int PaperSize = {read=GetPaperSize, write=SetPaperSize, nodefault};
	__property int PaperLength = {read=GetPaperLength, write=SetPaperLength, nodefault};
	__property int PaperWidth = {read=GetPaperWidth, write=SetPaperWidth, nodefault};
	__property int Scale = {read=GetScale, write=SetScale, nodefault};
	__property int Copies = {read=GetCopies, write=SetCopies, nodefault};
	__property int DefaultSource = {read=GetBin, write=SetBin, nodefault};
	__property int PrintQuality = {read=GetPrintQuality, write=SetPrintQuality, nodefault};
	__property int Color = {read=GetColor, write=SetColor, nodefault};
	__property int Duplex = {read=GetDuplex, write=SetDuplex, nodefault};
	__property int YResolution = {read=GetYResolution, write=SetYResolution, nodefault};
	__property int TrueTypeOption = {read=GetTrueTypeOption, write=SetTrueTypeOption, nodefault};
	__property AnsiString PrinterName = {read=GetPrinterName};
	__property AnsiString PrinterPort = {read=GetPrinterPort, write=SetPort};
	__property AnsiString PrinterDriver = {read=GetPrinterDriver};
	__property Byte BinIndex = {read=GetBinIndex, write=SetBinFromList, nodefault};
	__property Byte PaperIndex = {read=GetPaperIndex, write=SetPaperFromList, nodefault};
	__property int DpiX = {read=FDpiX, write=FDpiX, nodefault};
	__property int DpiY = {read=FiDpiY, write=FiDpiY, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint CCHBinName = 0x18;
static const Shortint CCHPaperName = 0x40;
static const Word CBinMax = 0x100;
static const Word CPaperNames = 0x100;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE void __fastcall DirectPrint(const AnsiString Printer, const AnsiString Data, const AnsiString DocumentName = "");
extern PACKAGE void __fastcall SetPrinterPixelsPerInch(void);
extern PACKAGE Types::TPoint __fastcall GetPrinterResolution();
extern PACKAGE int __fastcall CharFitsWithinDots(const AnsiString Text, const int Dots);
extern PACKAGE void __fastcall PrintMemo(const Stdctrls::TMemo* Memo, const Types::TRect &Rect);
extern PACKAGE AnsiString __fastcall GetDefaultPrinterName();
extern PACKAGE bool __fastcall DPGetDefaultPrinter(/* out */ AnsiString &PrinterName);
extern PACKAGE bool __fastcall DPSetDefaultPrinter(const AnsiString PrinterName);

}	/* namespace Jclprint */
using namespace Jclprint;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclprint
