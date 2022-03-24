// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclgraphics.pas' rev: 10.00

#ifndef JclgraphicsHPP
#define JclgraphicsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Jclgraphutils.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclgraphics
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EJclGraphicsError;
class PASCALIMPLEMENTATION EJclGraphicsError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclGraphicsError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclGraphicsError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclGraphicsError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclGraphicsError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclGraphicsError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclGraphicsError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclGraphicsError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclGraphicsError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclGraphicsError(void) { }
	#pragma option pop
	
};


typedef DynamicArray<DynamicArray<int > >  TDynDynIntegerArrayArray;

typedef DynamicArray<Types::TPoint >  TDynPointArray;

typedef DynamicArray<DynamicArray<Types::TPoint > >  TDynDynPointArrayArray;

struct TPointF
{
	
public:
	float X;
	float Y;
} ;

typedef DynamicArray<TPointF >  TDynPointArrayF;

#pragma option push -b-
enum TDrawMode { dmOpaque, dmBlend };
#pragma option pop

#pragma option push -b-
enum TStretchFilter { sfNearest, sfLinear, sfSpline };
#pragma option pop

#pragma option push -b-
enum TConversionKind { ckRed, ckGreen, ckBlue, ckAlpha, ckUniformRGB, ckWeightedRGB };
#pragma option pop

#pragma option push -b-
enum TResamplingFilter { rfBox, rfTriangle, rfHermite, rfBell, rfSpline, rfLanczos3, rfMitchell };
#pragma option pop

struct TMatrix3d
{
	
public:
	Extended A[3][3];
} ;

typedef DynamicArray<DynamicArray<TPointF > >  TDynDynPointArrayArrayF;

typedef DynamicArray<int >  TScanLine;

typedef DynamicArray<DynamicArray<int > >  TScanLines;

typedef Byte TLUT8[256];

typedef Byte TGamma[256];

#pragma option push -b-
enum TColorChannel { ccRed, ccGreen, ccBlue, ccAlpha };
#pragma option pop

#pragma option push -b-
enum TGradientDirection { gdVertical, gdHorizontal };
#pragma option pop

#pragma option push -b-
enum TPolyFillMode { fmAlternate, fmWinding };
#pragma option pop

#pragma option push -b-
enum TJclRegionCombineOperator { coAnd, coDiff, coOr, coXor };
#pragma option pop

#pragma option push -b-
enum TJclRegionBitmapMode { rmInclude, rmExclude };
#pragma option pop

#pragma option push -b-
enum TJclRegionKind { rkNull, rkSimple, rkComplex, rkError };
#pragma option pop

class DELPHICLASS TJclDesktopCanvas;
class PASCALIMPLEMENTATION TJclDesktopCanvas : public Graphics::TCanvas 
{
	typedef Graphics::TCanvas inherited;
	
private:
	HDC FDesktop;
	
public:
	__fastcall TJclDesktopCanvas(void);
	__fastcall virtual ~TJclDesktopCanvas(void);
};


class DELPHICLASS TJclRegionInfo;
class DELPHICLASS TJclRegion;
class PASCALIMPLEMENTATION TJclRegionInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	void *FData;
	int FDataSize;
	Types::TRect __fastcall GetBox();
	
protected:
	int __fastcall GetCount(void);
	Types::TRect __fastcall GetRect(int index);
	
public:
	__fastcall TJclRegionInfo(TJclRegion* Region);
	__fastcall virtual ~TJclRegionInfo(void);
	__property Types::TRect Box = {read=GetBox};
	__property Types::TRect Rectangles[int Index] = {read=GetRect};
	__property int Count = {read=GetCount, nodefault};
};


class PASCALIMPLEMENTATION TJclRegion : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	HRGN FHandle;
	#pragma pack(push,1)
	Types::TRect FBoxRect;
	#pragma pack(pop)
	int FRegionType;
	bool FOwnsHandle;
	void __fastcall CheckHandle(void);
	
protected:
	HRGN __fastcall GetHandle(void);
	Types::TRect __fastcall GetBox();
	TJclRegionKind __fastcall GetRegionType(void);
	
public:
	__fastcall TJclRegion(HRGN RegionHandle, bool OwnsHandle);
	__fastcall TJclRegion(const Types::TRect &ARect)/* overload */;
	__fastcall TJclRegion(const int Top, const int Left, const int Bottom, const int Right)/* overload */;
	__fastcall TJclRegion(const TDynPointArray Points, int Count, TPolyFillMode FillMode);
	__fastcall TJclRegion(const TDynPointArray Points, const Jclbase::TDynIntegerArray Vertex, int Count, TPolyFillMode FillMode);
	__fastcall TJclRegion(const Types::TRect &ARect, bool DummyForBCB)/* overload */;
	__fastcall TJclRegion(const int Top, const int Left, const int Bottom, const int Right, Byte DummyForBCB)/* overload */;
	__fastcall TJclRegion(const Types::TRect &ARect, int CornerWidth, int CornerHeight)/* overload */;
	__fastcall TJclRegion(const int Top, const int Left, const int Bottom, const int Right, const int CornerWidth, const int CornerHeight)/* overload */;
	__fastcall TJclRegion(Graphics::TBitmap* Bitmap, Graphics::TColor RegionColor, TJclRegionBitmapMode RegionBitmapMode);
	__fastcall TJclRegion(Graphics::TCanvas* Canvas);
	__fastcall TJclRegion(TJclRegionInfo* RegionInfo);
	__fastcall TJclRegion(TJclRegion* InitialRegion, unsigned hWndFrom, unsigned hWndTo)/* overload */;
	__fastcall TJclRegion(TJclRegion* InitialRegion, Controls::TWinControl* ControlFrom, Controls::TWinControl* ControlTo)/* overload */;
	__fastcall virtual ~TJclRegion(void);
	void __fastcall Clip(Graphics::TCanvas* Canvas);
	void __fastcall Combine(TJclRegion* DestRegion, TJclRegion* SrcRegion, TJclRegionCombineOperator CombineOp)/* overload */;
	void __fastcall Combine(TJclRegion* SrcRegion, TJclRegionCombineOperator CombineOp)/* overload */;
	TJclRegion* __fastcall Copy(void);
	bool __fastcall Equals(TJclRegion* CompareRegion);
	void __fastcall Fill(Graphics::TCanvas* Canvas);
	void __fastcall FillGradient(Graphics::TCanvas* Canvas, int ColorCount, Graphics::TColor StartColor, Graphics::TColor EndColor, TGradientDirection ADirection);
	void __fastcall Frame(Graphics::TCanvas* Canvas, int FrameWidth, int FrameHeight);
	void __fastcall Invert(Graphics::TCanvas* Canvas);
	void __fastcall Offset(int X, int Y);
	void __fastcall Paint(Graphics::TCanvas* Canvas);
	bool __fastcall PointIn(int X, int Y)/* overload */;
	bool __fastcall PointIn(const Types::TPoint &Point)/* overload */;
	bool __fastcall RectIn(const Types::TRect &ARect)/* overload */;
	bool __fastcall RectIn(int Top, int Left, int Bottom, int Right)/* overload */;
	void __fastcall SetWindow(unsigned Window, bool Redraw);
	TJclRegionInfo* __fastcall GetRegionInfo(void);
	__property Types::TRect Box = {read=GetBox};
	__property HRGN Handle = {read=GetHandle, nodefault};
	__property TJclRegionKind RegionType = {read=GetRegionType, nodefault};
};


class DELPHICLASS TJclThreadPersistent;
class PASCALIMPLEMENTATION TJclThreadPersistent : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	_RTL_CRITICAL_SECTION FLock;
	int FLockCount;
	int FUpdateCount;
	Classes::TNotifyEvent FOnChanging;
	Classes::TNotifyEvent FOnChange;
	
protected:
	__property int LockCount = {read=FLockCount, nodefault};
	__property int UpdateCount = {read=FUpdateCount, nodefault};
	
public:
	__fastcall virtual TJclThreadPersistent(void);
	__fastcall virtual ~TJclThreadPersistent(void);
	virtual void __fastcall Changing(void);
	virtual void __fastcall Changed(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	void __fastcall Lock(void);
	void __fastcall Unlock(void);
	__property Classes::TNotifyEvent OnChanging = {read=FOnChanging, write=FOnChanging};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
};


class DELPHICLASS TJclCustomMap;
class PASCALIMPLEMENTATION TJclCustomMap : public TJclThreadPersistent 
{
	typedef TJclThreadPersistent inherited;
	
private:
	int FHeight;
	int FWidth;
	void __fastcall SetHeight(int NewHeight);
	void __fastcall SetWidth(int NewWidth);
	
public:
	virtual void __fastcall Delete(void);
	virtual bool __fastcall Empty(void);
	void __fastcall SetSize(Classes::TPersistent* Source)/* overload */;
	virtual void __fastcall SetSize(int NewWidth, int NewHeight)/* overload */;
	__property int Height = {read=FHeight, write=SetHeight, nodefault};
	__property int Width = {read=FWidth, write=SetWidth, nodefault};
public:
	#pragma option push -w-inl
	/* TJclThreadPersistent.Create */ inline __fastcall virtual TJclCustomMap(void) : TJclThreadPersistent() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclThreadPersistent.Destroy */ inline __fastcall virtual ~TJclCustomMap(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclBitmap32;
class PASCALIMPLEMENTATION TJclBitmap32 : public TJclCustomMap 
{
	typedef TJclCustomMap inherited;
	
private:
	#pragma pack(push,1)
	tagBITMAPINFO FBitmapInfo;
	#pragma pack(pop)
	Jclgraphutils::TColor32 *FBits;
	TDrawMode FDrawMode;
	Graphics::TFont* FFont;
	HBITMAP FHandle;
	HDC FHDC;
	Byte FMasterAlpha;
	Jclgraphutils::TColor32 FOuterColor;
	Jclgraphutils::TColor32 FPenColor;
	float FStippleCounter;
	DynamicArray<Jclgraphutils::TColor32 >  FStipplePattern;
	float FStippleStep;
	TStretchFilter FStretchFilter;
	bool FResetAlphaOnAssign;
	Jclgraphutils::TColor32 __fastcall GetPixel(int X, int Y);
	Jclgraphutils::TColor32 __fastcall GetPixelS(int X, int Y);
	Jclgraphutils::PColor32 __fastcall GetPixelPtr(int X, int Y);
	Jclgraphutils::PColor32Array __fastcall GetScanLine(int Y);
	void __fastcall SetDrawMode(TDrawMode Value);
	void __fastcall SetFont(Graphics::TFont* Value);
	void __fastcall SetMasterAlpha(Byte Value);
	void __fastcall SetPixel(int X, int Y, Jclgraphutils::TColor32 Value);
	void __fastcall SetPixelS(int X, int Y, Jclgraphutils::TColor32 Value);
	void __fastcall SetStippleStep(float Value);
	void __fastcall SetStretchFilter(TStretchFilter Value);
	
protected:
	HFONT FontHandle;
	int RasterX;
	int RasterY;
	float RasterXF;
	float RasterYF;
	virtual void __fastcall AssignTo(Classes::TPersistent* Dst);
	bool __fastcall ClipLine(int &X0, int &Y0, int &X1, int &Y1);
	/*         class method */ static bool __fastcall ClipLineF(TMetaClass* vmt, float &X0, float &Y0, float &X1, float &Y1, float MinX, float MaxX, float MinY, float MaxY);
	void __fastcall FontChanged(System::TObject* Sender);
	void __fastcall SET_T256(int X, int Y, Jclgraphutils::TColor32 C);
	void __fastcall SET_TS256(int X, int Y, Jclgraphutils::TColor32 C);
	virtual void __fastcall ReadData(Classes::TStream* Stream);
	virtual void __fastcall WriteData(Classes::TStream* Stream);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	__property float StippleCounter = {read=FStippleCounter};
	
public:
	__fastcall virtual TJclBitmap32(void);
	__fastcall virtual ~TJclBitmap32(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall SetSize(int NewWidth, int NewHeight)/* overload */;
	virtual bool __fastcall Empty(void);
	void __fastcall Clear(void)/* overload */;
	void __fastcall Clear(Jclgraphutils::TColor32 FillColor)/* overload */;
	virtual void __fastcall Delete(void);
	void __fastcall LoadFromStream(Classes::TStream* Stream);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	void __fastcall LoadFromFile(const AnsiString FileName);
	void __fastcall SaveToFile(const AnsiString FileName);
	void __fastcall ResetAlpha(void);
	void __fastcall Draw(int DstX, int DstY, TJclBitmap32* Src)/* overload */;
	void __fastcall Draw(const Types::TRect &DstRect, const Types::TRect &SrcRect, TJclBitmap32* Src)/* overload */;
	void __fastcall Draw(const Types::TRect &DstRect, const Types::TRect &SrcRect, HDC hSrc)/* overload */;
	void __fastcall DrawTo(TJclBitmap32* Dst)/* overload */;
	void __fastcall DrawTo(TJclBitmap32* Dst, int DstX, int DstY)/* overload */;
	void __fastcall DrawTo(TJclBitmap32* Dst, const Types::TRect &DstRect)/* overload */;
	void __fastcall DrawTo(TJclBitmap32* Dst, const Types::TRect &DstRect, const Types::TRect &SrcRect)/* overload */;
	void __fastcall DrawTo(HDC hDst, int DstX, int DstY)/* overload */;
	void __fastcall DrawTo(HDC hDst, const Types::TRect &DstRect, const Types::TRect &SrcRect)/* overload */;
	Jclgraphutils::TColor32 __fastcall GetPixelB(int X, int Y);
	void __fastcall SetPixelT(int X, int Y, Jclgraphutils::TColor32 Value)/* overload */;
	void __fastcall SetPixelT(Jclgraphutils::PColor32 &Ptr, Jclgraphutils::TColor32 Value)/* overload */;
	void __fastcall SetPixelTS(int X, int Y, Jclgraphutils::TColor32 Value);
	void __fastcall SetPixelF(float X, float Y, Jclgraphutils::TColor32 Value);
	void __fastcall SetPixelFS(float X, float Y, Jclgraphutils::TColor32 Value);
	void __fastcall SetStipple(Jclgraphutils::TArrayOfColor32 NewStipple)/* overload */;
	void __fastcall SetStipple(Jclgraphutils::TColor32 * NewStipple, const int NewStipple_Size)/* overload */;
	void __fastcall ResetStippleCounter(void);
	Jclgraphutils::TColor32 __fastcall GetStippleColor(void);
	void __fastcall DrawHorzLine(int X1, int Y, int X2, Jclgraphutils::TColor32 Value);
	void __fastcall DrawHorzLineS(int X1, int Y, int X2, Jclgraphutils::TColor32 Value);
	void __fastcall DrawHorzLineT(int X1, int Y, int X2, Jclgraphutils::TColor32 Value);
	void __fastcall DrawHorzLineTS(int X1, int Y, int X2, Jclgraphutils::TColor32 Value);
	void __fastcall DrawHorzLineTSP(int X1, int Y, int X2);
	void __fastcall DrawVertLine(int X, int Y1, int Y2, Jclgraphutils::TColor32 Value);
	void __fastcall DrawVertLineS(int X, int Y1, int Y2, Jclgraphutils::TColor32 Value);
	void __fastcall DrawVertLineT(int X, int Y1, int Y2, Jclgraphutils::TColor32 Value);
	void __fastcall DrawVertLineTS(int X, int Y1, int Y2, Jclgraphutils::TColor32 Value);
	void __fastcall DrawVertLineTSP(int X, int Y1, int Y2);
	void __fastcall DrawLine(int X1, int Y1, int X2, int Y2, Jclgraphutils::TColor32 Value, bool L = false);
	void __fastcall DrawLineS(int X1, int Y1, int X2, int Y2, Jclgraphutils::TColor32 Value, bool L = false);
	void __fastcall DrawLineT(int X1, int Y1, int X2, int Y2, Jclgraphutils::TColor32 Value, bool L = false);
	void __fastcall DrawLineTS(int X1, int Y1, int X2, int Y2, Jclgraphutils::TColor32 Value, bool L = false);
	void __fastcall DrawLineA(int X1, int Y1, int X2, int Y2, Jclgraphutils::TColor32 Value, bool L = false);
	void __fastcall DrawLineAS(int X1, int Y1, int X2, int Y2, Jclgraphutils::TColor32 Value, bool L = false);
	void __fastcall DrawLineF(float X1, float Y1, float X2, float Y2, Jclgraphutils::TColor32 Value, bool L = false);
	void __fastcall DrawLineFS(float X1, float Y1, float X2, float Y2, Jclgraphutils::TColor32 Value, bool L = false);
	void __fastcall DrawLineFP(float X1, float Y1, float X2, float Y2, bool L = false);
	void __fastcall DrawLineFSP(float X1, float Y1, float X2, float Y2, bool L = false);
	void __fastcall MoveTo(int X, int Y);
	void __fastcall LineToS(int X, int Y);
	void __fastcall LineToTS(int X, int Y);
	void __fastcall LineToAS(int X, int Y);
	void __fastcall MoveToF(float X, float Y);
	void __fastcall LineToFS(float X, float Y);
	void __fastcall FillRect(int X1, int Y1, int X2, int Y2, Jclgraphutils::TColor32 Value);
	void __fastcall FillRectS(int X1, int Y1, int X2, int Y2, Jclgraphutils::TColor32 Value);
	void __fastcall FillRectT(int X1, int Y1, int X2, int Y2, Jclgraphutils::TColor32 Value);
	void __fastcall FillRectTS(int X1, int Y1, int X2, int Y2, Jclgraphutils::TColor32 Value);
	void __fastcall FrameRectS(int X1, int Y1, int X2, int Y2, Jclgraphutils::TColor32 Value);
	void __fastcall FrameRectTS(int X1, int Y1, int X2, int Y2, Jclgraphutils::TColor32 Value)/* overload */;
	void __fastcall FrameRectTSP(int X1, int Y1, int X2, int Y2)/* overload */;
	void __fastcall RaiseRectTS(int X1, int Y1, int X2, int Y2, int Contrast);
	void __fastcall UpdateFont(void);
	void __fastcall TextOut(int X, int Y, const AnsiString Text)/* overload */;
	void __fastcall TextOut(int X, int Y, const Types::TRect &ClipRect, const AnsiString Text)/* overload */;
	void __fastcall TextOut(const Types::TRect &ClipRect, const unsigned Flags, const AnsiString Text)/* overload */;
	tagSIZE __fastcall TextExtent(const AnsiString Text);
	int __fastcall TextHeight(const AnsiString Text);
	int __fastcall TextWidth(const AnsiString Text);
	void __fastcall RenderText(int X, int Y, const AnsiString Text, int AALevel, Jclgraphutils::TColor32 Color);
	__property HBITMAP BitmapHandle = {read=FHandle, nodefault};
	__property tagBITMAPINFO BitmapInfo = {read=FBitmapInfo};
	__property Jclgraphutils::PColor32Array Bits = {read=FBits};
	__property Graphics::TFont* Font = {read=FFont, write=SetFont};
	__property HDC Handle = {read=FHDC, nodefault};
	__property Jclgraphutils::TColor32 PenColor = {read=FPenColor, write=FPenColor, nodefault};
	__property Jclgraphutils::TColor32 Pixel[int X][int Y] = {read=GetPixel, write=SetPixel/*, default*/};
	__property Jclgraphutils::TColor32 PixelS[int X][int Y] = {read=GetPixelS, write=SetPixelS};
	__property Jclgraphutils::PColor32 PixelPtr[int X][int Y] = {read=GetPixelPtr};
	__property Jclgraphutils::PColor32Array ScanLine[int Y] = {read=GetScanLine};
	__property float StippleStep = {read=FStippleStep, write=SetStippleStep};
	
__published:
	__property TDrawMode DrawMode = {read=FDrawMode, write=SetDrawMode, default=0};
	__property Byte MasterAlpha = {read=FMasterAlpha, write=SetMasterAlpha, default=255};
	__property Jclgraphutils::TColor32 OuterColor = {read=FOuterColor, write=FOuterColor, default=0};
	__property TStretchFilter StretchFilter = {read=FStretchFilter, write=SetStretchFilter, default=0};
	__property bool ResetAlphaOnAssign = {read=FResetAlphaOnAssign, write=FResetAlphaOnAssign, default=1};
	__property OnChanging ;
	__property OnChange ;
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  SetSize(Classes::TPersistent* Source){ TJclCustomMap::SetSize(Source); }
	
};


class DELPHICLASS TJclByteMap;
class PASCALIMPLEMENTATION TJclByteMap : public TJclCustomMap 
{
	typedef TJclCustomMap inherited;
	
private:
	DynamicArray<Byte >  FBytes;
	int FHeight;
	int FWidth;
	Byte __fastcall GetValue(int X, int Y);
	System::PByte __fastcall GetValPtr(int X, int Y);
	void __fastcall SetValue(int X, int Y, Byte Value);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dst);
	
public:
	__fastcall virtual ~TJclByteMap(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual bool __fastcall Empty(void);
	void __fastcall Clear(Byte FillValue);
	void __fastcall ReadFrom(TJclBitmap32* Source, TConversionKind Conversion);
	virtual void __fastcall SetSize(int NewWidth, int NewHeight)/* overload */;
	void __fastcall WriteTo(TJclBitmap32* Dest, TConversionKind Conversion)/* overload */;
	void __fastcall WriteTo(TJclBitmap32* Dest, Jclgraphutils::TColor32 const * Palette)/* overload */;
	__property Jclbase::TDynByteArray Bytes = {read=FBytes};
	__property System::PByte ValPtr[int X][int Y] = {read=GetValPtr};
	__property Byte Value[int X][int Y] = {read=GetValue, write=SetValue/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclThreadPersistent.Create */ inline __fastcall virtual TJclByteMap(void) : TJclCustomMap() { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  SetSize(Classes::TPersistent* Source){ TJclCustomMap::SetSize(Source); }
	
};


class DELPHICLASS TJclTransformation;
class PASCALIMPLEMENTATION TJclTransformation : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual Types::TRect __fastcall GetTransformedBounds(const Types::TRect &Src) = 0 ;
	virtual void __fastcall PrepareTransform(void) = 0 ;
	virtual void __fastcall Transform(int DstX, int DstY, /* out */ int &SrcX, /* out */ int &SrcY) = 0 ;
	virtual void __fastcall Transform256(int DstX, int DstY, /* out */ int &SrcX256, /* out */ int &SrcY256) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclTransformation(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTransformation(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclLinearTransformation;
class PASCALIMPLEMENTATION TJclLinearTransformation : public TJclTransformation 
{
	typedef TJclTransformation inherited;
	
private:
	TMatrix3d FMatrix;
	
protected:
	int A;
	int B;
	int C;
	int D;
	int E;
	int F;
	
public:
	__fastcall virtual TJclLinearTransformation(void);
	virtual Types::TRect __fastcall GetTransformedBounds(const Types::TRect &Src);
	virtual void __fastcall PrepareTransform(void);
	virtual void __fastcall Transform(int DstX, int DstY, /* out */ int &SrcX, /* out */ int &SrcY);
	virtual void __fastcall Transform256(int DstX, int DstY, /* out */ int &SrcX256, /* out */ int &SrcY256);
	void __fastcall Clear(void);
	void __fastcall Rotate(Extended Cx, Extended Cy, Extended Alpha);
	void __fastcall Skew(Extended Fx, Extended Fy);
	void __fastcall Scale(Extended Sx, Extended Sy);
	void __fastcall Translate(Extended Dx, Extended Dy);
	__property TMatrix3d Matrix = {read=FMatrix, write=FMatrix};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclLinearTransformation(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TMatrix3d IdentityMatrix;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE void __fastcall Stretch(unsigned NewWidth, unsigned NewHeight, TResamplingFilter Filter, float Radius, Graphics::TGraphic* Source, Graphics::TBitmap* Target)/* overload */;
extern PACKAGE void __fastcall Stretch(unsigned NewWidth, unsigned NewHeight, TResamplingFilter Filter, float Radius, Graphics::TBitmap* Bitmap)/* overload */;
extern PACKAGE void __fastcall BlockTransfer(TJclBitmap32* Dst, int DstX, int DstY, TJclBitmap32* Src, const Types::TRect &SrcRect, TDrawMode CombineOp);
extern PACKAGE void __fastcall StretchTransfer(TJclBitmap32* Dst, const Types::TRect &DstRect, TJclBitmap32* Src, const Types::TRect &SrcRect, TStretchFilter StretchFilter, TDrawMode CombineOp);
extern PACKAGE void __fastcall DrawBitmap(HDC DC, HBITMAP Bitmap, int X, int Y, int Width, int Height);
extern PACKAGE Graphics::TBitmap* __fastcall GetAntialiasedBitmap(const Graphics::TBitmap* Bitmap);
extern PACKAGE void __fastcall JPegToBitmap(const AnsiString FileName);
extern PACKAGE void __fastcall BitmapToJPeg(const AnsiString FileName);
extern PACKAGE int __fastcall ExtractIconCount(const AnsiString FileName);
extern PACKAGE HICON __fastcall BitmapToIcon(HBITMAP Bitmap, int cx, int cy)/* overload */;
extern PACKAGE HICON __fastcall BitmapToIcon(HBITMAP Bitmap, HBITMAP Mask, int cx, int cy)/* overload */;
extern PACKAGE HBITMAP __fastcall IconToBitmap(HICON Icon);
extern PACKAGE void __fastcall GetIconFromBitmap(Graphics::TIcon* Icon, Graphics::TBitmap* Bitmap);
extern PACKAGE void __fastcall WriteIcon(Classes::TStream* Stream, HBITMAP ColorBitmap, HBITMAP MaskBitmap, bool WriteLength = false)/* overload */;
extern PACKAGE void __fastcall WriteIcon(Classes::TStream* Stream, HICON Icon, bool WriteLength = false)/* overload */;
extern PACKAGE void __fastcall SaveIconToFile(HICON Icon, const AnsiString FileName);
extern PACKAGE void __fastcall Transform(TJclBitmap32* Dst, TJclBitmap32* Src, const Types::TRect &SrcRect, TJclTransformation* Transformation);
extern PACKAGE void __fastcall SetBorderTransparent(TJclBitmap32* ABitmap, const Types::TRect &ARect);
extern PACKAGE HRGN __fastcall CreateRegionFromBitmap(Graphics::TBitmap* Bitmap, Graphics::TColor RegionColor, TJclRegionBitmapMode RegionBitmapMode);
extern PACKAGE void __fastcall ScreenShot(Graphics::TBitmap* bm, int Left, int Top, int Width, int Height, unsigned Window = (unsigned)(0x0))/* overload */;
extern PACKAGE void __fastcall ScreenShot(Graphics::TBitmap* bm, bool IncludeTaskBar = true)/* overload */;
extern PACKAGE Types::TRect __fastcall MapWindowRect(unsigned hWndFrom, unsigned hWndTo, const Types::TRect &ARect);
extern PACKAGE bool __fastcall FillGradient(HDC DC, const Types::TRect &ARect, int ColorCount, Graphics::TColor StartColor, Graphics::TColor EndColor, TGradientDirection ADirection)/* overload */;
extern PACKAGE void __fastcall PolyLineTS(TJclBitmap32* Bitmap, const TDynPointArray Points, Jclgraphutils::TColor32 Color);
extern PACKAGE void __fastcall PolyLineAS(TJclBitmap32* Bitmap, const TDynPointArray Points, Jclgraphutils::TColor32 Color);
extern PACKAGE void __fastcall PolyLineFS(TJclBitmap32* Bitmap, const TDynPointArrayF Points, Jclgraphutils::TColor32 Color);
extern PACKAGE void __fastcall PolygonTS(TJclBitmap32* Bitmap, const TDynPointArray Points, Jclgraphutils::TColor32 Color);
extern PACKAGE void __fastcall PolygonAS(TJclBitmap32* Bitmap, const TDynPointArray Points, Jclgraphutils::TColor32 Color);
extern PACKAGE void __fastcall PolygonFS(TJclBitmap32* Bitmap, const TDynPointArrayF Points, Jclgraphutils::TColor32 Color);
extern PACKAGE void __fastcall PolyPolygonTS(TJclBitmap32* Bitmap, const TDynDynPointArrayArray Points, Jclgraphutils::TColor32 Color);
extern PACKAGE void __fastcall PolyPolygonAS(TJclBitmap32* Bitmap, const TDynDynPointArrayArray Points, Jclgraphutils::TColor32 Color);
extern PACKAGE void __fastcall PolyPolygonFS(TJclBitmap32* Bitmap, const TDynDynPointArrayArrayF Points, Jclgraphutils::TColor32 Color);
extern PACKAGE void __fastcall AlphaToGrayscale(TJclBitmap32* Dst, TJclBitmap32* Src);
extern PACKAGE void __fastcall IntensityToAlpha(TJclBitmap32* Dst, TJclBitmap32* Src);
extern PACKAGE void __fastcall Invert(TJclBitmap32* Dst, TJclBitmap32* Src);
extern PACKAGE void __fastcall InvertRGB(TJclBitmap32* Dst, TJclBitmap32* Src);
extern PACKAGE void __fastcall ColorToGrayscale(TJclBitmap32* Dst, TJclBitmap32* Src);
extern PACKAGE void __fastcall ApplyLUT(TJclBitmap32* Dst, TJclBitmap32* Src, Byte const * LUT);
extern PACKAGE void __fastcall SetGamma(float Gamma = 7.000000E-01);

}	/* namespace Jclgraphics */
using namespace Jclgraphics;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclgraphics
