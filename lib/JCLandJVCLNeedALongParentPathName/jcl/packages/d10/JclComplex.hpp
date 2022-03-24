// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclcomplex.pas' rev: 10.00

#ifndef JclcomplexHPP
#define JclcomplexHPP

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
#include <Jclmath.hpp>	// Pascal unit
#include <Jclresources.hpp>	// Pascal unit
#include <Jclstrings.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclcomplex
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TComplexKind { crRectangular, crPolar };
#pragma option pop

struct TCoords
{
	
public:
	Extended X;
	Extended Y;
	Extended R;
	Extended Theta;
} ;

struct TRectCoord
{
	
public:
	Extended X;
	Extended Y;
} ;

class DELPHICLASS TJclComplex;
class PASCALIMPLEMENTATION TJclComplex : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TCoords FCoord;
	Byte FFracLen;
	Extended __fastcall MiscalcFloat(const Extended X);
	void __fastcall MiscalcComplex(void);
	void __fastcall FillCoords(const TComplexKind ComplexType);
	AnsiString __fastcall GetRectangularString();
	AnsiString __fastcall GetPolarString();
	void __fastcall SetRectangularString(AnsiString StrToParse);
	void __fastcall SetPolarString(AnsiString StrToParse);
	void __fastcall SetFracLen(const Byte X);
	Extended __fastcall GetRadius(void);
	Extended __fastcall GetAngle(void);
	Extended __fastcall NormalizeAngle(const Extended Value);
	
protected:
	TJclComplex* __fastcall Assign(const TCoords &Coord, const TComplexKind ComplexType = (TComplexKind)(0x0))/* overload */;
	TRectCoord __fastcall CoreAdd(const TRectCoord &First, const TRectCoord &Second);
	TRectCoord __fastcall CoreDiv(const TRectCoord &First, const TRectCoord &Second);
	TRectCoord __fastcall CoreMul(const TRectCoord &First, const TRectCoord &Second);
	TRectCoord __fastcall CoreSub(const TRectCoord &First, const TRectCoord &Second);
	TRectCoord __fastcall CoreLn(const TRectCoord &LnValue);
	TRectCoord __fastcall CoreExp(const TRectCoord &ExpValue);
	TRectCoord __fastcall CorePwr(const TRectCoord &First, const TRectCoord &Second, const TRectCoord &Polar);
	TRectCoord __fastcall CoreIntPwr(const TRectCoord &First, const TRectCoord &Polar, const int Pwr);
	TRectCoord __fastcall CoreRealPwr(const TRectCoord &First, const TRectCoord &Polar, const Extended Pwr);
	TRectCoord __fastcall CoreRoot(const TRectCoord &First, const TRectCoord &Polar, const Word K, const Word N);
	TRectCoord __fastcall CoreCos(const TRectCoord &Value);
	TRectCoord __fastcall CoreSin(const TRectCoord &Value);
	TRectCoord __fastcall CoreTan(const TRectCoord &Value);
	TRectCoord __fastcall CoreCot(const TRectCoord &Value);
	TRectCoord __fastcall CoreSec(const TRectCoord &Value);
	TRectCoord __fastcall CoreCsc(const TRectCoord &Value);
	TRectCoord __fastcall CoreCosH(const TRectCoord &Value);
	TRectCoord __fastcall CoreSinH(const TRectCoord &Value);
	TRectCoord __fastcall CoreTanH(const TRectCoord &Value);
	TRectCoord __fastcall CoreCotH(const TRectCoord &Value);
	TRectCoord __fastcall CoreSecH(const TRectCoord &Value);
	TRectCoord __fastcall CoreCscH(const TRectCoord &Value);
	TRectCoord __fastcall CoreI0(const TRectCoord &Value);
	TRectCoord __fastcall CoreJ0(const TRectCoord &Value);
	TRectCoord __fastcall CoreApproxLnGamma(const TRectCoord &Value);
	TRectCoord __fastcall CoreLnGamma(const TRectCoord &Value);
	TRectCoord __fastcall CoreGamma(const TRectCoord &Value);
	
public:
	__fastcall TJclComplex(void)/* overload */;
	__fastcall TJclComplex(const Extended X, const Extended Y, const TComplexKind ComplexType)/* overload */;
	TJclComplex* __fastcall Assign(const Extended X, const Extended Y, const TComplexKind ComplexType = (TComplexKind)(0x0))/* overload */;
	TJclComplex* __fastcall AssignZero(void);
	TJclComplex* __fastcall AssignOne(void);
	TJclComplex* __fastcall Duplicate(void);
	TJclComplex* __fastcall CAdd(const TJclComplex* AddValue)/* overload */;
	TJclComplex* __fastcall CAdd(const Extended X, const Extended Y, const TComplexKind ComplexType = (TComplexKind)(0x0))/* overload */;
	TJclComplex* __fastcall CDiv(const TJclComplex* DivValue)/* overload */;
	TJclComplex* __fastcall CDiv(const Extended X, const Extended Y, const TComplexKind ComplexType = (TComplexKind)(0x0))/* overload */;
	TJclComplex* __fastcall CMul(const TJclComplex* MulValue)/* overload */;
	TJclComplex* __fastcall CMul(const Extended X, const Extended Y, const TComplexKind ComplexType = (TComplexKind)(0x0))/* overload */;
	TJclComplex* __fastcall CSub(const TJclComplex* SubValue)/* overload */;
	TJclComplex* __fastcall CSub(const Extended X, const Extended Y, const TComplexKind ComplexType = (TComplexKind)(0x0))/* overload */;
	TJclComplex* __fastcall CNeg(void);
	TJclComplex* __fastcall CConjugate(void);
	TJclComplex* __fastcall CNewAdd(const TJclComplex* AddValue)/* overload */;
	TJclComplex* __fastcall CNewAdd(const Extended X, const Extended Y, const TComplexKind ComplexType = (TComplexKind)(0x0))/* overload */;
	TJclComplex* __fastcall CNewDiv(const TJclComplex* DivValue)/* overload */;
	TJclComplex* __fastcall CNewDiv(const Extended X, const Extended Y, const TComplexKind ComplexType = (TComplexKind)(0x0))/* overload */;
	TJclComplex* __fastcall CNewMul(const TJclComplex* MulValue)/* overload */;
	TJclComplex* __fastcall CNewMul(const Extended X, const Extended Y, const TComplexKind ComplexType = (TComplexKind)(0x0))/* overload */;
	TJclComplex* __fastcall CNewSub(const TJclComplex* SubValue)/* overload */;
	TJclComplex* __fastcall CNewSub(const Extended X, const Extended Y, const TComplexKind ComplexType = (TComplexKind)(0x0))/* overload */;
	TJclComplex* __fastcall CNewNeg(void);
	TJclComplex* __fastcall CNewConjugate(void);
	TJclComplex* __fastcall CLn(void);
	TJclComplex* __fastcall CExp(void);
	TJclComplex* __fastcall CPwr(const TJclComplex* PwrValue)/* overload */;
	TJclComplex* __fastcall CPwr(const Extended X, const Extended Y, const TComplexKind ComplexType = (TComplexKind)(0x0))/* overload */;
	TJclComplex* __fastcall CIntPwr(const int Pwr);
	TJclComplex* __fastcall CRealPwr(const Extended Pwr);
	TJclComplex* __fastcall CRoot(const Word K, const Word N);
	TJclComplex* __fastcall CSqrt(void);
	TJclComplex* __fastcall CNewLn(void);
	TJclComplex* __fastcall CNewExp(void);
	TJclComplex* __fastcall CNewPwr(TJclComplex* PwrValue)/* overload */;
	TJclComplex* __fastcall CNewPwr(const Extended X, const Extended Y, const TComplexKind ComplexType = (TComplexKind)(0x0))/* overload */;
	TJclComplex* __fastcall CNewIntPwr(const int Pwr);
	TJclComplex* __fastcall CNewRealPwr(const Extended Pwr);
	TJclComplex* __fastcall CNewRoot(const Word K, const Word N);
	TJclComplex* __fastcall CNewSqrt(void);
	TJclComplex* __fastcall CCos(void);
	TJclComplex* __fastcall CSin(void);
	TJclComplex* __fastcall CTan(void);
	TJclComplex* __fastcall CCot(void);
	TJclComplex* __fastcall CSec(void);
	TJclComplex* __fastcall CCsc(void);
	TJclComplex* __fastcall CNewCsc(void);
	TJclComplex* __fastcall CNewCos(void);
	TJclComplex* __fastcall CNewSin(void);
	TJclComplex* __fastcall CNewTan(void);
	TJclComplex* __fastcall CNewCot(void);
	TJclComplex* __fastcall CNewSec(void);
	TJclComplex* __fastcall CCosH(void);
	TJclComplex* __fastcall CSinH(void);
	TJclComplex* __fastcall CTanH(void);
	TJclComplex* __fastcall CCotH(void);
	TJclComplex* __fastcall CSecH(void);
	TJclComplex* __fastcall CCscH(void);
	TJclComplex* __fastcall CNewCosH(void);
	TJclComplex* __fastcall CNewSinH(void);
	TJclComplex* __fastcall CNewTanH(void);
	TJclComplex* __fastcall CNewCotH(void);
	TJclComplex* __fastcall CNewSecH(void);
	TJclComplex* __fastcall CNewCscH(void);
	TJclComplex* __fastcall CI0(void);
	TJclComplex* __fastcall CJ0(void);
	TJclComplex* __fastcall CNewI0(void);
	TJclComplex* __fastcall CNewJ0(void);
	TJclComplex* __fastcall CApproxLnGamma(void);
	TJclComplex* __fastcall CLnGamma(void);
	TJclComplex* __fastcall CGamma(void);
	TJclComplex* __fastcall CNewApproxLnGamma(void);
	TJclComplex* __fastcall CNewLnGamma(void);
	TJclComplex* __fastcall CNewGamma(void);
	Extended __fastcall AbsoluteValue(void)/* overload */;
	Extended __fastcall AbsoluteValue(const TRectCoord &Coord)/* overload */;
	Extended __fastcall AbsoluteValueSqr(void)/* overload */;
	Extended __fastcall AbsoluteValueSqr(const TRectCoord &Coord)/* overload */;
	AnsiString __fastcall FormatExtended(const Extended X);
	__property Byte FracLength = {read=FFracLen, write=SetFracLen, default=8};
	__property Extended RealPart = {read=FCoord.X};
	__property Extended ImaginaryPart = {read=FCoord.Y};
	__property Extended Radius = {read=GetRadius};
	__property Extended Angle = {read=GetAngle};
	__property AnsiString AsString = {read=GetRectangularString, write=SetRectangularString};
	__property AnsiString AsPolarString = {read=GetPolarString, write=SetPolarString};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclComplex(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define TComplex_VERSION  (5.010000E+00)
extern PACKAGE Extended ComplexPrecision;
extern PACKAGE Byte MaxTerm;
extern PACKAGE Extended EpsilonSqr;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jclcomplex */
using namespace Jclcomplex;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclcomplex
