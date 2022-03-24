// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclunitconv.pas' rev: 10.00

#ifndef JclunitconvHPP
#define JclunitconvHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclunitconv
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EUnitConversionError;
class PASCALIMPLEMENTATION EUnitConversionError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EUnitConversionError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EUnitConversionError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EUnitConversionError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EUnitConversionError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EUnitConversionError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EUnitConversionError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EUnitConversionError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EUnitConversionError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EUnitConversionError(void) { }
	#pragma option pop
	
};


class DELPHICLASS ETemperatureConversionError;
class PASCALIMPLEMENTATION ETemperatureConversionError : public EUnitConversionError 
{
	typedef EUnitConversionError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ETemperatureConversionError(const AnsiString Msg) : EUnitConversionError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ETemperatureConversionError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EUnitConversionError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ETemperatureConversionError(int Ident)/* overload */ : EUnitConversionError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ETemperatureConversionError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EUnitConversionError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ETemperatureConversionError(const AnsiString Msg, int AHelpContext) : EUnitConversionError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ETemperatureConversionError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EUnitConversionError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ETemperatureConversionError(int Ident, int AHelpContext)/* overload */ : EUnitConversionError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ETemperatureConversionError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EUnitConversionError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ETemperatureConversionError(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TTemperatureType { ttCelsius, ttFahrenheit, ttKelvin, ttRankine, ttReaumur };
#pragma option pop

//-- var, const, procedure ---------------------------------------------------
#define CelsiusFreezingPoint  (0.000000E+00)
#define FahrenheitFreezingPoint  (3.200000E+01)
#define KelvinFreezingPoint  (2.731500E+02)
#define CelsiusBoilingPoint  (1.000000E+02)
#define FahrenheitBoilingPoint  (2.120000E+02)
#define KelvinBoilingPoint  (3.731500E+02)
#define CelsiusAbsoluteZero  (-2.731500E+02)
#define FahrenheitAbsoluteZero  (-4.596700E+02)
#define KelvinAbsoluteZero  (0.000000E+00)
#define RankineAbsoluteZero  (0.000000E+00)
#define RankineAtFahrenheitZero  (4.596700E+02)
#define RankineFreezingPoint  (4.916700E+02)
static const Extended RankineBoilingPoint = 6.716700E+02;
#define ReaumurAbsoluteZero  (-2.185200E+02)
#define ReaumurFreezingPoint  (0.000000E+00)
#define ReaumurBoilingPoint  (8.000000E+01)
extern PACKAGE Extended DegPerCycle;
extern PACKAGE Extended DegPerGrad;
extern PACKAGE Extended DegPerRad;
extern PACKAGE Extended GradPerCycle;
extern PACKAGE Extended GradPerDeg;
extern PACKAGE Extended GradPerRad;
extern PACKAGE Extended RadPerCycle;
extern PACKAGE Extended RadPerDeg;
extern PACKAGE Extended RadPerGrad;
extern PACKAGE Extended CyclePerDeg;
extern PACKAGE Extended CyclePerGrad;
extern PACKAGE Extended CyclePerRad;
#define ArcMinutesPerDeg  (6.000000E+01)
#define ArcSecondsPerArcMinute  (6.000000E+01)
#define ArcSecondsPerDeg  (3.600000E+03)
static const Extended DegPerArcMinute = 1.666667E-02;
static const Extended DegPerArcSecond = 2.777778E-04;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE int __fastcall HowAOneLinerCanBiteYou(const int Step, const int Max);
extern PACKAGE int __fastcall MakePercentage(const int Step, const int Max);
extern PACKAGE Extended __fastcall CelsiusToFahrenheit(const Extended Temperature);
extern PACKAGE Extended __fastcall CelsiusToKelvin(const Extended Temperature);
extern PACKAGE Extended __fastcall CelsiusToRankine(const Extended Temperature);
extern PACKAGE Extended __fastcall CelsiusToReaumur(const Extended Temperature);
extern PACKAGE Extended __fastcall FahrenheitToCelsius(const Extended Temperature);
extern PACKAGE Extended __fastcall FahrenheitToKelvin(const Extended Temperature);
extern PACKAGE Extended __fastcall FahrenheitToRankine(const Extended Temperature);
extern PACKAGE Extended __fastcall FahrenheitToReaumur(const Extended Temperature);
extern PACKAGE Extended __fastcall KelvinToCelsius(const Extended Temperature);
extern PACKAGE Extended __fastcall KelvinToFahrenheit(const Extended Temperature);
extern PACKAGE Extended __fastcall KelvinToRankine(const Extended Temperature);
extern PACKAGE Extended __fastcall KelvinToReaumur(const Extended Temperature);
extern PACKAGE Extended __fastcall RankineToCelsius(const Extended Temperature);
extern PACKAGE Extended __fastcall RankineToFahrenheit(const Extended Temperature);
extern PACKAGE Extended __fastcall RankineToKelvin(const Extended Temperature);
extern PACKAGE Extended __fastcall RankineToReaumur(const Extended Temperature);
extern PACKAGE Extended __fastcall ReaumurToCelsius(const Extended Temperature);
extern PACKAGE Extended __fastcall ReaumurToFahrenheit(const Extended Temperature);
extern PACKAGE Extended __fastcall ReaumurToKelvin(const Extended Temperature);
extern PACKAGE Extended __fastcall ReaumurToRankine(const Extended Temperature);
extern PACKAGE Extended __fastcall ConvertTemperature(const TTemperatureType FromType, const TTemperatureType ToType, const Extended Temperature);
extern PACKAGE Extended __fastcall CelsiusTo(TTemperatureType ToType, const Extended Temperature);
extern PACKAGE Extended __fastcall FahrenheitTo(TTemperatureType ToType, const Extended Temperature);
extern PACKAGE Extended __fastcall KelvinTo(TTemperatureType ToType, const Extended Temperature);
extern PACKAGE Extended __fastcall RankineTo(TTemperatureType ToType, const Extended Temperature);
extern PACKAGE Extended __fastcall ReaumurTo(TTemperatureType ToType, const Extended Temperature);
extern PACKAGE Extended __fastcall CycleToDeg(const Extended Cycles);
extern PACKAGE Extended __fastcall CycleToGrad(const Extended Cycles);
extern PACKAGE Extended __fastcall CycleToRad(const Extended Cycles);
extern PACKAGE Extended __fastcall DegToGrad(const Extended Degrees);
extern PACKAGE Extended __fastcall DegToCycle(const Extended Degrees);
extern PACKAGE Extended __fastcall DegToRad(const Extended Degrees);
extern PACKAGE Extended __fastcall GradToCycle(const Extended Grads);
extern PACKAGE Extended __fastcall GradToDeg(const Extended Grads);
extern PACKAGE Extended __fastcall GradToRad(const Extended Grads);
extern PACKAGE Extended __fastcall RadToCycle(const Extended Radians);
extern PACKAGE Extended __fastcall RadToDeg(const Extended Radians);
extern PACKAGE Extended __fastcall RadToGrad(const Extended Radians);
extern PACKAGE Extended __fastcall DmsToDeg(const int D, const int M, const Extended S);
extern PACKAGE Extended __fastcall DmsToRad(const int D, const int M, const Extended S);
extern PACKAGE void __fastcall DegToDms(const Extended Degrees, /* out */ int &D, /* out */ int &M, /* out */ Extended &S);
extern PACKAGE AnsiString __fastcall DegToDmsStr(const Extended Degrees, const unsigned SecondPrecision = (unsigned)(0x3));
extern PACKAGE void __fastcall CartesianToCylinder(const Extended X, const Extended Y, const Extended Z, /* out */ Extended &R, /* out */ Extended &Phi, /* out */ Extended &Zeta);
extern PACKAGE void __fastcall CartesianToPolar(const Extended X, const Extended Y, /* out */ Extended &R, /* out */ Extended &Phi);
extern PACKAGE void __fastcall CartesianToSpheric(const Extended X, const Extended Y, const Extended Z, /* out */ Extended &Rho, /* out */ Extended &Phi, /* out */ Extended &Theta);
extern PACKAGE void __fastcall CylinderToCartesian(const Extended R, const Extended Phi, const Extended Zeta, /* out */ Extended &X, /* out */ Extended &Y, /* out */ Extended &Z);
extern PACKAGE void __fastcall PolarToCartesian(const Extended R, const Extended Phi, /* out */ Extended &X, /* out */ Extended &Y);
extern PACKAGE void __fastcall SphericToCartesian(const Extended Rho, const Extended Theta, const Extended Phi, /* out */ Extended &X, /* out */ Extended &Y, /* out */ Extended &Z);
extern PACKAGE Extended __fastcall CmToInch(const Extended Cm);
extern PACKAGE Extended __fastcall InchToCm(const Extended Inch);
extern PACKAGE Extended __fastcall FeetToMetre(const Extended Feet);
extern PACKAGE Extended __fastcall MetreToFeet(const Extended Metre);
extern PACKAGE Extended __fastcall YardToMetre(const Extended Yard);
extern PACKAGE Extended __fastcall MetreToYard(const Extended Metre);
extern PACKAGE Extended __fastcall NmToKm(const Extended Nm);
extern PACKAGE Extended __fastcall KmToNm(const Extended Km);
extern PACKAGE Extended __fastcall KmToSm(const Extended Km);
extern PACKAGE Extended __fastcall SmToKm(const Extended Sm);
extern PACKAGE Extended __fastcall LitreToGalUs(const Extended Litre);
extern PACKAGE Extended __fastcall GalUsToLitre(const Extended GalUs);
extern PACKAGE Extended __fastcall GalUsToGalCan(const Extended GalUs);
extern PACKAGE Extended __fastcall GalCanToGalUs(const Extended GalCan);
extern PACKAGE Extended __fastcall GalUsToGalUk(const Extended GalUs);
extern PACKAGE Extended __fastcall GalUkToGalUs(const Extended GalUk);
extern PACKAGE Extended __fastcall LitreToGalCan(const Extended Litre);
extern PACKAGE Extended __fastcall GalCanToLitre(const Extended GalCan);
extern PACKAGE Extended __fastcall LitreToGalUk(const Extended Litre);
extern PACKAGE Extended __fastcall GalUkToLitre(const Extended GalUk);
extern PACKAGE Extended __fastcall KgToLb(const Extended Kg);
extern PACKAGE Extended __fastcall LbToKg(const Extended Lb);
extern PACKAGE Extended __fastcall KgToOz(const Extended Kg);
extern PACKAGE Extended __fastcall OzToKg(const Extended Oz);
extern PACKAGE Extended __fastcall QrUsToKg(const Extended Qr);
extern PACKAGE Extended __fastcall QrUkToKg(const Extended Qr);
extern PACKAGE Extended __fastcall KgToQrUs(const Extended Kg);
extern PACKAGE Extended __fastcall KgToQrUk(const Extended Kg);
extern PACKAGE Extended __fastcall CwtUsToKg(const Extended Cwt);
extern PACKAGE Extended __fastcall CwtUkToKg(const Extended Cwt);
extern PACKAGE Extended __fastcall KgToCwtUs(const Extended Kg);
extern PACKAGE Extended __fastcall KgToCwtUk(const Extended Kg);
extern PACKAGE Extended __fastcall LtonToKg(const Extended Lton);
extern PACKAGE Extended __fastcall StonToKg(const Extended STon);
extern PACKAGE Extended __fastcall KgToLton(const Extended Kg);
extern PACKAGE Extended __fastcall KgToSton(const Extended Kg);
extern PACKAGE Extended __fastcall KgToKarat(const Extended Kg);
extern PACKAGE Extended __fastcall KaratToKg(const Extended Karat);
extern PACKAGE Extended __fastcall PascalToBar(const Extended Pa);
extern PACKAGE Extended __fastcall PascalToAt(const Extended Pa);
extern PACKAGE Extended __fastcall PascalToTorr(const Extended Pa);
extern PACKAGE Extended __fastcall BarToPascal(const Extended Bar);
extern PACKAGE Extended __fastcall AtToPascal(const Extended At);
extern PACKAGE Extended __fastcall TorrToPascal(const Extended Torr);
extern PACKAGE Extended __fastcall KnotToMs(const Extended Knot);
extern PACKAGE Extended __fastcall HpElectricToWatt(const Extended HpE);
extern PACKAGE Extended __fastcall HpMetricToWatt(const Extended HpM);
extern PACKAGE Extended __fastcall MsToKnot(const Extended Ms);
extern PACKAGE Extended __fastcall WattToHpElectric(const Extended W);
extern PACKAGE Extended __fastcall WattToHpMetric(const Extended W);

}	/* namespace Jclunitconv */
using namespace Jclunitconv;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclunitconv
