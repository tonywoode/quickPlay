// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclmath.pas' rev: 10.00

#ifndef JclmathHPP
#define JclmathHPP

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
static const Infinity    =  1.0 / 0.0;
static const NaN         =  0.0 / 0.0;
static const NegInfinity = -1.0 / 0.0;

namespace Jclmath
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TPrimalityTestMethod { ptTrialDivision, ptRabinMiller };
#pragma option pop

#pragma option push -b-
enum TFloatingPointClass { fpZero, fpNormal, fpDenormal, fpInfinite, fpNaN, fpInvalid, fpEmpty };
#pragma option pop

typedef int TNaNTag;

class DELPHICLASS TJclASet;
class PASCALIMPLEMENTATION TJclASet : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual bool __fastcall GetBit(const int Idx) = 0 ;
	virtual void __fastcall SetBit(const int Idx, const bool Value) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual void __fastcall Invert(void) = 0 ;
	virtual bool __fastcall GetRange(const int Low, const int High, const bool Value) = 0 ;
	virtual void __fastcall SetRange(const int Low, const int High, const bool Value) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclASet(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclASet(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclFlatSet;
class PASCALIMPLEMENTATION TJclFlatSet : public TJclASet 
{
	typedef TJclASet inherited;
	
private:
	Classes::TBits* FBits;
	
public:
	__fastcall TJclFlatSet(void);
	__fastcall virtual ~TJclFlatSet(void);
	virtual void __fastcall Clear(void);
	virtual void __fastcall Invert(void);
	virtual void __fastcall SetRange(const int Low, const int High, const bool Value);
	virtual bool __fastcall GetBit(const int Idx);
	virtual bool __fastcall GetRange(const int Low, const int High, const bool Value);
	virtual void __fastcall SetBit(const int Idx, const bool Value);
};


typedef void *TPointerArray[8388608];

typedef void * *PPointerArray;

typedef Set<Byte, 0, 255>  TDelphiSet;

typedef TDelphiSet *PDelphiSet;

class DELPHICLASS TJclSparseFlatSet;
class PASCALIMPLEMENTATION TJclSparseFlatSet : public TJclASet 
{
	typedef TJclASet inherited;
	
private:
	void * *FSetList;
	int FSetListEntries;
	
public:
	__fastcall virtual ~TJclSparseFlatSet(void);
	virtual void __fastcall Clear(void);
	virtual void __fastcall Invert(void);
	virtual bool __fastcall GetBit(const int Idx);
	virtual void __fastcall SetBit(const int Idx, const bool Value);
	virtual void __fastcall SetRange(const int Low, const int High, const bool Value);
	virtual bool __fastcall GetRange(const int Low, const int High, const bool Value);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclSparseFlatSet(void) : TJclASet() { }
	#pragma option pop
	
};


class DELPHICLASS TJclRational;
class PASCALIMPLEMENTATION TJclRational : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int FT;
	int FN;
	AnsiString __fastcall GetAsString();
	void __fastcall SetAsString(const AnsiString S);
	Extended __fastcall GetAsFloat(void);
	void __fastcall SetAsFloat(const Extended R);
	
protected:
	void __fastcall Simplify(void);
	
public:
	__fastcall TJclRational(void)/* overload */;
	__fastcall TJclRational(const Extended R)/* overload */;
	__fastcall TJclRational(const int Numerator, const int Denominator)/* overload */;
	__property int Numerator = {read=FT, nodefault};
	__property int Denominator = {read=FN, nodefault};
	__property AnsiString AsString = {read=GetAsString, write=SetAsString};
	__property Extended AsFloat = {read=GetAsFloat, write=SetAsFloat};
	void __fastcall Assign(const TJclRational* R)/* overload */;
	void __fastcall Assign(const Extended R)/* overload */;
	void __fastcall Assign(const int Numerator, const int Denominator = 0x1)/* overload */;
	void __fastcall AssignZero(void);
	void __fastcall AssignOne(void);
	TJclRational* __fastcall Duplicate(void);
	bool __fastcall IsEqual(const TJclRational* R)/* overload */;
	bool __fastcall IsEqual(const int Numerator, const int Denominator = 0x1)/* overload */;
	bool __fastcall IsEqual(const Extended R)/* overload */;
	bool __fastcall IsZero(void);
	bool __fastcall IsOne(void);
	void __fastcall Add(const TJclRational* R)/* overload */;
	void __fastcall Add(const Extended V)/* overload */;
	void __fastcall Add(const int V)/* overload */;
	void __fastcall Subtract(const TJclRational* R)/* overload */;
	void __fastcall Subtract(const Extended V)/* overload */;
	void __fastcall Subtract(const int V)/* overload */;
	void __fastcall Negate(void);
	void __fastcall Abs(void);
	int __fastcall Sgn(void);
	void __fastcall Multiply(const TJclRational* R)/* overload */;
	void __fastcall Multiply(const Extended V)/* overload */;
	void __fastcall Multiply(const int V)/* overload */;
	void __fastcall Reciprocal(void);
	void __fastcall Divide(const TJclRational* R)/* overload */;
	void __fastcall Divide(const Extended V)/* overload */;
	void __fastcall Divide(const int V)/* overload */;
	void __fastcall Sqrt(void);
	void __fastcall Sqr(void);
	void __fastcall Power(const TJclRational* R)/* overload */;
	void __fastcall Power(const int V)/* overload */;
	void __fastcall Power(const Extended V)/* overload */;
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclRational(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclMathError;
class PASCALIMPLEMENTATION EJclMathError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclMathError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclMathError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclMathError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclMathError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclMathError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclMathError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclMathError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclMathError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclMathError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclNaNSignal;
class PASCALIMPLEMENTATION EJclNaNSignal : public EJclMathError 
{
	typedef EJclMathError inherited;
	
private:
	TNaNTag FTag;
	
public:
	__fastcall EJclNaNSignal(TNaNTag ATag, bool Dummy);
	__property TNaNTag Tag = {read=FTag, nodefault};
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclNaNSignal(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclMathError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclNaNSignal(int Ident)/* overload */ : EJclMathError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclNaNSignal(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclMathError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclNaNSignal(const AnsiString Msg, int AHelpContext) : EJclMathError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclNaNSignal(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclMathError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclNaNSignal(int Ident, int AHelpContext)/* overload */ : EJclMathError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclNaNSignal(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclMathError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclNaNSignal(void) { }
	#pragma option pop
	
};


typedef Word TCrc16Table[256];

typedef unsigned TCrc32Table[256];

struct TRectComplex;
struct TRectComplex
{
	
public:
	Extended Re;
	Extended Im;
	AnsiString __fastcall AsString();
	TRectComplex __fastcall Conjugate();
	bool __fastcall IsZero(void);
	bool __fastcall IsInfinite(void);
} ;

struct TPolarComplex;
struct TPolarComplex
{
	
public:
	Extended Radius;
	Extended Angle;
	AnsiString __fastcall AsString();
	TPolarComplex __fastcall Conjugate();
	bool __fastcall IsZero(void);
	bool __fastcall IsInfinite(void);
	TPolarComplex __fastcall Power(const TRectComplex &Exponent)/* overload */;
	TPolarComplex __fastcall Power(const Extended Exponent)/* overload */;
	TPolarComplex __fastcall Power(const int Exponent)/* overload */;
	TPolarComplex __fastcall Root(const unsigned K, const unsigned N);
} ;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Extended Bernstein;
extern PACKAGE Extended Cbrt2;
extern PACKAGE Extended Cbrt3;
extern PACKAGE Extended Cbrt10;
extern PACKAGE Extended Cbrt100;
extern PACKAGE Extended CbrtPi;
extern PACKAGE Extended Catalan;
extern PACKAGE Extended Pi;
extern PACKAGE Extended PiOn2;
extern PACKAGE Extended PiOn3;
extern PACKAGE Extended PiOn4;
extern PACKAGE Extended Sqrt2;
extern PACKAGE Extended Sqrt3;
extern PACKAGE Extended Sqrt5;
extern PACKAGE Extended Sqrt10;
extern PACKAGE Extended SqrtPi;
extern PACKAGE Extended Sqrt2Pi;
extern PACKAGE Extended TwoPi;
extern PACKAGE Extended ThreePi;
extern PACKAGE Extended Ln2;
extern PACKAGE Extended Ln10;
extern PACKAGE Extended LnPi;
extern PACKAGE Extended Log2;
extern PACKAGE Extended Log3;
extern PACKAGE Extended LogPi;
extern PACKAGE Extended LogE;
extern PACKAGE Extended E;
extern PACKAGE Extended hLn2Pi;
extern PACKAGE Extended inv2Pi;
extern PACKAGE Extended TwoToPower63;
extern PACKAGE Extended GoldenMean;
extern PACKAGE Extended EulerMascheroni;
extern PACKAGE Extended MaxAngle;
extern PACKAGE Extended MaxTanH;
static const Word MaxFactorial = 0x6da;
extern PACKAGE Extended MaxFloatingPoint;
extern PACKAGE Extended MinFloatingPoint;
static const Extended PiExt = 3.141593E+00;
extern PACKAGE Extended RatioDegToRad;
extern PACKAGE Extended RatioRadToDeg;
extern PACKAGE Extended RatioGradToRad;
extern PACKAGE Extended RatioRadToGrad;
extern PACKAGE Extended RatioDegToGrad;
extern PACKAGE Extended RatioGradToDeg;
extern PACKAGE Extended PrecisionTolerance;
extern PACKAGE float EpsSingle;
extern PACKAGE double EpsDouble;
extern PACKAGE Extended EpsExtended;
extern PACKAGE Extended Epsilon;
extern PACKAGE float ThreeEpsSingle;
extern PACKAGE double ThreeEpsDouble;
extern PACKAGE Extended ThreeEpsExtended;
extern PACKAGE Extended ThreeEpsilon;
extern PACKAGE bool __fastcall (*IsPrime)(unsigned N);
static const int LowValidNaNTag = -4194303;
static const int HighValidNaNTag = 0x3ffffe;
extern PACKAGE TDelphiSet EmptyDelphiSet;
extern PACKAGE TDelphiSet CompleteDelphiSet;
extern PACKAGE Word Crc16DefaultTable[256];
extern PACKAGE unsigned Crc16DefaultStart;
static const Word Crc16PolynomCCITT = 0x1021;
static const Word Crc16PolynomIBM = 0x8005;
static const Shortint Crc16Bits = 0x10;
static const Shortint Crc16Bytes = 0x2;
static const Word Crc16HighBit = 0x8000;
static const Word NotCrc16HighBit = 0x7fff;
extern PACKAGE unsigned Crc32DefaultTable[256];
extern PACKAGE unsigned Crc32DefaultStart;
static const int Crc32PolynomIEEE = 0x4c11db7;
static const int Crc32PolynomCastagnoli = 0x1edc6f41;
static const int Crc32Koopman = 0x741b8cd7;
static const Shortint Crc32Bits = 0x20;
static const Shortint Crc32Bytes = 0x4;
static const unsigned Crc32HighBit = 0x80000000;
static const int NotCrc32HighBit = 0x7fffffff;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE void __fastcall SwapOrd(int &X, int &Y);
extern PACKAGE AnsiString __fastcall DoubleToHex(const double D);
extern PACKAGE double __fastcall HexToDouble(const AnsiString Hex);
extern PACKAGE Extended __fastcall DegToRad(const Extended Value)/* overload */;
extern PACKAGE double __fastcall DegToRad(const double Value)/* overload */;
extern PACKAGE float __fastcall DegToRad(const float Value)/* overload */;
extern PACKAGE void __fastcall FastDegToRad(void);
extern PACKAGE Extended __fastcall RadToDeg(const Extended Value)/* overload */;
extern PACKAGE double __fastcall RadToDeg(const double Value)/* overload */;
extern PACKAGE float __fastcall RadToDeg(const float Value)/* overload */;
extern PACKAGE void __fastcall FastRadToDeg(void);
extern PACKAGE Extended __fastcall GradToRad(const Extended Value)/* overload */;
extern PACKAGE double __fastcall GradToRad(const double Value)/* overload */;
extern PACKAGE float __fastcall GradToRad(const float Value)/* overload */;
extern PACKAGE void __fastcall FastGradToRad(void);
extern PACKAGE Extended __fastcall RadToGrad(const Extended Value)/* overload */;
extern PACKAGE double __fastcall RadToGrad(const double Value)/* overload */;
extern PACKAGE float __fastcall RadToGrad(const float Value)/* overload */;
extern PACKAGE void __fastcall FastRadToGrad(void);
extern PACKAGE Extended __fastcall DegToGrad(const Extended Value)/* overload */;
extern PACKAGE double __fastcall DegToGrad(const double Value)/* overload */;
extern PACKAGE float __fastcall DegToGrad(const float Value)/* overload */;
extern PACKAGE void __fastcall FastDegToGrad(void);
extern PACKAGE Extended __fastcall GradToDeg(const Extended Value)/* overload */;
extern PACKAGE double __fastcall GradToDeg(const double Value)/* overload */;
extern PACKAGE float __fastcall GradToDeg(const float Value)/* overload */;
extern PACKAGE void __fastcall FastGradToDeg(void);
extern PACKAGE void __fastcall DomainCheck(bool Err);
extern PACKAGE Extended __fastcall LogBase10(Extended X);
extern PACKAGE Extended __fastcall LogBase2(Extended X);
extern PACKAGE Extended __fastcall LogBaseN(Extended Base, Extended X);
extern PACKAGE Extended __fastcall ArcCos(Extended X);
extern PACKAGE Extended __fastcall ArcCot(Extended X);
extern PACKAGE Extended __fastcall ArcCsc(Extended X);
extern PACKAGE Extended __fastcall ArcSec(Extended X);
extern PACKAGE Extended __fastcall ArcSin(Extended X);
extern PACKAGE Extended __fastcall ArcTan(Extended X);
extern PACKAGE Extended __fastcall ArcTan2(Extended Y, Extended X);
extern PACKAGE Extended __fastcall Cos(Extended X)/* overload */;
extern PACKAGE Extended __fastcall Cot(Extended X)/* overload */;
extern PACKAGE Extended __fastcall Coversine(Extended X);
extern PACKAGE Extended __fastcall Csc(Extended X)/* overload */;
extern PACKAGE Extended __fastcall Exsecans(Extended X);
extern PACKAGE Extended __fastcall Haversine(Extended X);
extern PACKAGE Extended __fastcall Sec(Extended X)/* overload */;
extern PACKAGE Extended __fastcall Sin(Extended X)/* overload */;
extern PACKAGE void __fastcall SinCos(Extended X, /* out */ Extended &Sin, /* out */ Extended &Cos)/* overload */;
extern PACKAGE void __fastcall SinCos(double X, /* out */ double &Sin, /* out */ double &Cos)/* overload */;
extern PACKAGE void __fastcall SinCos(float X, /* out */ float &Sin, /* out */ float &Cos)/* overload */;
extern PACKAGE Extended __fastcall Tan(Extended X)/* overload */;
extern PACKAGE Extended __fastcall Versine(Extended X);
extern PACKAGE Extended __fastcall ArcCosH(Extended X);
extern PACKAGE Extended __fastcall ArcCotH(Extended X);
extern PACKAGE Extended __fastcall ArcCscH(Extended X);
extern PACKAGE Extended __fastcall ArcSecH(Extended X);
extern PACKAGE Extended __fastcall ArcSinH(Extended X);
extern PACKAGE Extended __fastcall ArcTanH(Extended X);
extern PACKAGE Extended __fastcall CosH(Extended X)/* overload */;
extern PACKAGE Extended __fastcall CotH(Extended X)/* overload */;
extern PACKAGE Extended __fastcall CscH(Extended X)/* overload */;
extern PACKAGE Extended __fastcall SecH(Extended X)/* overload */;
extern PACKAGE Extended __fastcall SinH(Extended X)/* overload */;
extern PACKAGE Extended __fastcall TanH(Extended X)/* overload */;
extern PACKAGE Extended __fastcall DegMinSecToFloat(const Extended Degs, const Extended Mins, const Extended Secs);
extern PACKAGE void __fastcall FloatToDegMinSec(const Extended X, Extended &Degs, Extended &Mins, Extended &Secs);
extern PACKAGE Extended __fastcall Exp(const Extended X)/* overload */;
extern PACKAGE Extended __fastcall Power(const Extended Base, const Extended Exponent)/* overload */;
extern PACKAGE Extended __fastcall PowerInt(const Extended X, int N)/* overload */;
extern PACKAGE Extended __fastcall TenToY(const Extended Y);
extern PACKAGE Extended __fastcall TruncPower(const Extended Base, const Extended Exponent);
extern PACKAGE Extended __fastcall TwoToY(const Extended Y);
extern PACKAGE bool __fastcall IsFloatZero(const Extended X);
extern PACKAGE bool __fastcall FloatsEqual(const Extended X, const Extended Y);
extern PACKAGE Extended __fastcall MaxFloat(const Extended X, const Extended Y);
extern PACKAGE Extended __fastcall MinFloat(const Extended X, const Extended Y);
extern PACKAGE Extended __fastcall ModFloat(const Extended X, const Extended Y);
extern PACKAGE Extended __fastcall RemainderFloat(const Extended X, const Extended Y);
extern PACKAGE void __fastcall SwapFloats(Extended &X, Extended &Y);
extern PACKAGE void __fastcall CalcMachineEpsSingle(void);
extern PACKAGE void __fastcall CalcMachineEpsDouble(void);
extern PACKAGE void __fastcall CalcMachineEpsExtended(void);
extern PACKAGE void __fastcall CalcMachineEps(void);
extern PACKAGE void __fastcall SetPrecisionToleranceToEpsilon(void);
extern PACKAGE Extended __fastcall SetPrecisionTolerance(Extended NewTolerance);
extern PACKAGE int __fastcall Ceiling(const Extended X);
extern PACKAGE __int64 __fastcall CommercialRound(const Extended X);
extern PACKAGE Extended __fastcall Factorial(const int N);
extern PACKAGE int __fastcall Floor(const Extended X);
extern PACKAGE unsigned __fastcall GCD(unsigned X, unsigned Y);
extern PACKAGE short __fastcall ISqrt(const short I);
extern PACKAGE unsigned __fastcall LCM(const unsigned X, const unsigned Y);
extern PACKAGE Extended __fastcall NormalizeAngle(const Extended Angle);
extern PACKAGE Extended __fastcall Pythagoras(const Extended X, const Extended Y);
extern PACKAGE int __fastcall Sgn(const Extended X);
extern PACKAGE Extended __fastcall Signe(const Extended X, const Extended Y);
extern PACKAGE int __fastcall Ackermann(const int A, const int B);
extern PACKAGE int __fastcall Fibonacci(const int N);
extern PACKAGE int __fastcall EnsureRange(const int AValue, const int AMin, const int AMax)/* overload */;
extern PACKAGE __int64 __fastcall EnsureRange(const __int64 AValue, const __int64 AMin, const __int64 AMax)/* overload */;
extern PACKAGE double __fastcall EnsureRange(const double AValue, const double AMin, const double AMax)/* overload */;
extern PACKAGE bool __fastcall IsPrimeTD(unsigned N);
extern PACKAGE bool __fastcall IsPrimeRM(unsigned N);
extern PACKAGE Jclbase::TDynCardinalArray __fastcall PrimeFactors(unsigned N);
extern PACKAGE bool __fastcall IsPrimeFactor(const unsigned F, const unsigned N);
extern PACKAGE bool __fastcall IsRelativePrime(const unsigned X, const unsigned Y);
extern PACKAGE void __fastcall SetPrimalityTest(const TPrimalityTestMethod Method);
extern PACKAGE TFloatingPointClass __fastcall FloatingPointClass(const float Value)/* overload */;
extern PACKAGE TFloatingPointClass __fastcall FloatingPointClass(const double Value)/* overload */;
extern PACKAGE TFloatingPointClass __fastcall FloatingPointClass(const Extended Value)/* overload */;
extern PACKAGE bool __fastcall IsInfinite(const float Value)/* overload */;
extern PACKAGE bool __fastcall IsInfinite(const double Value)/* overload */;
extern PACKAGE bool __fastcall IsInfinite(const Extended Value)/* overload */;
extern PACKAGE bool __fastcall IsNaN(const float Value)/* overload */;
extern PACKAGE bool __fastcall IsNaN(const double Value)/* overload */;
extern PACKAGE bool __fastcall IsNaN(const Extended Value)/* overload */;
extern PACKAGE TNaNTag __fastcall GetNaNTag(const float NaN)/* overload */;
extern PACKAGE TNaNTag __fastcall GetNaNTag(const double NaN)/* overload */;
extern PACKAGE TNaNTag __fastcall GetNaNTag(const Extended NaN)/* overload */;
extern PACKAGE void __fastcall MakeQuietNaN(float &X, TNaNTag Tag = (TNaNTag)(0x0))/* overload */;
extern PACKAGE void __fastcall MakeQuietNaN(double &X, TNaNTag Tag = (TNaNTag)(0x0))/* overload */;
extern PACKAGE void __fastcall MakeQuietNaN(Extended &X, TNaNTag Tag = (TNaNTag)(0x0))/* overload */;
extern PACKAGE void __fastcall MakeSignalingNaN(float &X, TNaNTag Tag = (TNaNTag)(0x0))/* overload */;
extern PACKAGE void __fastcall MakeSignalingNaN(double &X, TNaNTag Tag = (TNaNTag)(0x0))/* overload */;
extern PACKAGE void __fastcall MakeSignalingNaN(Extended &X, TNaNTag Tag = (TNaNTag)(0x0))/* overload */;
extern PACKAGE void __fastcall MineSingleBuffer(void *Buffer, int Count, TNaNTag StartTag = (TNaNTag)(0x0));
extern PACKAGE void __fastcall MineDoubleBuffer(void *Buffer, int Count, TNaNTag StartTag = (TNaNTag)(0x0));
extern PACKAGE Jclbase::TDynSingleArray __fastcall MinedSingleArray(int Length);
extern PACKAGE Jclbase::TDynDoubleArray __fastcall MinedDoubleArray(int Length);
extern PACKAGE bool __fastcall IsSpecialValue(const Extended X);
extern PACKAGE bool __fastcall GetParity(Jclbase::TDynByteArray Buffer, int Len)/* overload */;
extern PACKAGE bool __fastcall GetParity(System::PByte Buffer, int Len)/* overload */;
extern PACKAGE Word __fastcall Crc16_P(Word const * Crc16Table, Jclbase::PJclByteArray X, int N, Word Crc = (Word)(0x0))/* overload */;
extern PACKAGE Word __fastcall Crc16_P(Jclbase::PJclByteArray X, int N, Word Crc = (Word)(0x0))/* overload */;
extern PACKAGE int __fastcall CheckCrc16_P(Word const * Crc16Table, Jclbase::PJclByteArray X, int N, Word Crc)/* overload */;
extern PACKAGE int __fastcall CheckCrc16_P(Jclbase::PJclByteArray X, int N, Word Crc)/* overload */;
extern PACKAGE Word __fastcall Crc16(Word const * Crc16Table, Byte const * X, const int X_Size, int N, Word Crc = (Word)(0x0))/* overload */;
extern PACKAGE Word __fastcall Crc16(Byte const * X, const int X_Size, int N, Word Crc = (Word)(0x0))/* overload */;
extern PACKAGE int __fastcall CheckCrc16(Word const * Crc16Table, Byte * X, const int X_Size, int N, Word Crc)/* overload */;
extern PACKAGE int __fastcall CheckCrc16(Byte * X, const int X_Size, int N, Word Crc)/* overload */;
extern PACKAGE Word __fastcall Crc16_A(Word const * Crc16Table, Byte const * X, const int X_Size, Word Crc = (Word)(0x0))/* overload */;
extern PACKAGE Word __fastcall Crc16_A(Byte const * X, const int X_Size, Word Crc = (Word)(0x0))/* overload */;
extern PACKAGE int __fastcall CheckCrc16_A(Word const * Crc16Table, Byte * X, const int X_Size, Word Crc)/* overload */;
extern PACKAGE int __fastcall CheckCrc16_A(Byte * X, const int X_Size, Word Crc)/* overload */;
extern PACKAGE void __fastcall InitCrc16(Word Polynom, Word Start, /* out */ Word * Crc16Table)/* overload */;
extern PACKAGE void __fastcall InitCrc16(Word Polynom, Word Start)/* overload */;
extern PACKAGE unsigned __fastcall Crc32_P(unsigned const * Crc32Table, Jclbase::PJclByteArray X, int N, unsigned Crc = (unsigned)(0x0))/* overload */;
extern PACKAGE unsigned __fastcall Crc32_P(Jclbase::PJclByteArray X, int N, unsigned Crc = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall CheckCrc32_P(unsigned const * Crc32Table, Jclbase::PJclByteArray X, int N, unsigned Crc)/* overload */;
extern PACKAGE int __fastcall CheckCrc32_P(Jclbase::PJclByteArray X, int N, unsigned Crc)/* overload */;
extern PACKAGE unsigned __fastcall Crc32(unsigned const * Crc32Table, Byte const * X, const int X_Size, int N, unsigned Crc = (unsigned)(0x0))/* overload */;
extern PACKAGE unsigned __fastcall Crc32(Byte const * X, const int X_Size, int N, unsigned Crc = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall CheckCrc32(unsigned const * Crc32Table, Byte * X, const int X_Size, int N, unsigned Crc)/* overload */;
extern PACKAGE int __fastcall CheckCrc32(Byte * X, const int X_Size, int N, unsigned Crc)/* overload */;
extern PACKAGE unsigned __fastcall Crc32_A(unsigned const * Crc32Table, Byte const * X, const int X_Size, unsigned Crc = (unsigned)(0x0))/* overload */;
extern PACKAGE unsigned __fastcall Crc32_A(Byte const * X, const int X_Size, unsigned Crc = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall CheckCrc32_A(unsigned const * Crc32Table, Byte * X, const int X_Size, unsigned Crc)/* overload */;
extern PACKAGE int __fastcall CheckCrc32_A(Byte * X, const int X_Size, unsigned Crc)/* overload */;
extern PACKAGE void __fastcall InitCrc32(unsigned Polynom, unsigned Start, /* out */ unsigned * Crc32Table)/* overload */;
extern PACKAGE void __fastcall InitCrc32(unsigned Polynom, unsigned Start)/* overload */;
extern PACKAGE void __fastcall SetRectComplexFormatStr(const AnsiString S);
extern PACKAGE void __fastcall SetPolarComplexFormatStr(const AnsiString S);
extern PACKAGE AnsiString __fastcall ComplexToStr(const TRectComplex &Z)/* overload */;
extern PACKAGE AnsiString __fastcall ComplexToStr(const TPolarComplex &Z)/* overload */;
extern PACKAGE TRectComplex __fastcall RectComplex(const Extended Re, const Extended Im = 0.000000E+00)/* overload */;
extern PACKAGE TRectComplex __fastcall RectComplex(const TPolarComplex &Z)/* overload */;
extern PACKAGE TPolarComplex __fastcall PolarComplex(const Extended Radius, const Extended Angle = 0.000000E+00)/* overload */;
extern PACKAGE TPolarComplex __fastcall PolarComplex(const TRectComplex &Z)/* overload */;
extern PACKAGE bool __fastcall Equal(const TRectComplex &Z1, const TRectComplex &Z2)/* overload */;
extern PACKAGE bool __fastcall Equal(const TPolarComplex &Z1, const TPolarComplex &Z2)/* overload */;
extern PACKAGE bool __fastcall IsZero(const TRectComplex &Z)/* overload */;
extern PACKAGE bool __fastcall IsZero(const TPolarComplex &Z)/* overload */;
extern PACKAGE bool __fastcall IsInfinite(const TRectComplex &Z)/* overload */;
extern PACKAGE bool __fastcall IsInfinite(const TPolarComplex &Z)/* overload */;
extern PACKAGE Extended __fastcall Norm(const TRectComplex &Z)/* overload */;
extern PACKAGE Extended __fastcall Norm(const TPolarComplex &Z)/* overload */;
extern PACKAGE Extended __fastcall AbsSqr(const TRectComplex &Z)/* overload */;
extern PACKAGE Extended __fastcall AbsSqr(const TPolarComplex &Z)/* overload */;
extern PACKAGE TRectComplex __fastcall Conjugate(const TRectComplex &Z)/* overload */;
extern PACKAGE TPolarComplex __fastcall Conjugate(const TPolarComplex &Z)/* overload */;
extern PACKAGE TRectComplex __fastcall Inv(const TRectComplex &Z)/* overload */;
extern PACKAGE TPolarComplex __fastcall Inv(const TPolarComplex &Z)/* overload */;
extern PACKAGE TRectComplex __fastcall Neg(const TRectComplex &Z)/* overload */;
extern PACKAGE TPolarComplex __fastcall Neg(const TPolarComplex &Z)/* overload */;
extern PACKAGE TRectComplex __fastcall Sum(const TRectComplex &Z1, const TRectComplex &Z2)/* overload */;
extern PACKAGE TRectComplex __fastcall Sum(TRectComplex const * Z, const int Z_Size)/* overload */;
extern PACKAGE TRectComplex __fastcall Diff(const TRectComplex &Z1, const TRectComplex &Z2);
extern PACKAGE TRectComplex __fastcall Product(const TRectComplex &Z1, const TRectComplex &Z2)/* overload */;
extern PACKAGE TPolarComplex __fastcall Product(const TPolarComplex &Z1, const TPolarComplex &Z2)/* overload */;
extern PACKAGE TPolarComplex __fastcall Product(TPolarComplex const * Z, const int Z_Size)/* overload */;
extern PACKAGE TRectComplex __fastcall Quotient(const TRectComplex &Z1, const TRectComplex &Z2)/* overload */;
extern PACKAGE TPolarComplex __fastcall Quotient(const TPolarComplex &Z1, const TPolarComplex &Z2)/* overload */;
extern PACKAGE TRectComplex __fastcall Ln(const TPolarComplex &Z);
extern PACKAGE TPolarComplex __fastcall Exp(const TRectComplex &Z)/* overload */;
extern PACKAGE TPolarComplex __fastcall Power(const TPolarComplex &Z, const Extended Exponent)/* overload */;
extern PACKAGE TPolarComplex __fastcall Power(const TPolarComplex &Z, const TRectComplex &Exponent)/* overload */;
extern PACKAGE TPolarComplex __fastcall PowerInt(const TPolarComplex &Z, const int Exponent)/* overload */;
extern PACKAGE TPolarComplex __fastcall Root(const TPolarComplex &Z, const unsigned K, const unsigned N);
extern PACKAGE TRectComplex __fastcall Cos(const TRectComplex &Z)/* overload */;
extern PACKAGE TRectComplex __fastcall Sin(const TRectComplex &Z)/* overload */;
extern PACKAGE TRectComplex __fastcall Tan(const TRectComplex &Z)/* overload */;
extern PACKAGE TRectComplex __fastcall Cot(const TRectComplex &Z)/* overload */;
extern PACKAGE TRectComplex __fastcall Sec(const TRectComplex &Z)/* overload */;
extern PACKAGE TRectComplex __fastcall Csc(const TRectComplex &Z)/* overload */;
extern PACKAGE TRectComplex __fastcall CosH(const TRectComplex &Z)/* overload */;
extern PACKAGE TRectComplex __fastcall SinH(const TRectComplex &Z)/* overload */;
extern PACKAGE TRectComplex __fastcall TanH(const TRectComplex &Z)/* overload */;
extern PACKAGE TRectComplex __fastcall CotH(const TRectComplex &Z)/* overload */;
extern PACKAGE TRectComplex __fastcall SecH(const TRectComplex &Z)/* overload */;
extern PACKAGE TRectComplex __fastcall CscH(const TRectComplex &Z)/* overload */;

}	/* namespace Jclmath */
using namespace Jclmath;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclmath
