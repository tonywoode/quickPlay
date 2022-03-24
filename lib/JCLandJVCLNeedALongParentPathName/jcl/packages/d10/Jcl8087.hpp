// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcl8087.pas' rev: 10.00

#ifndef Jcl8087HPP
#define Jcl8087HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jcl8087
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum T8087Precision { pcSingle, pcReserved, pcDouble, pcExtended };
#pragma option pop

#pragma option push -b-
enum T8087Rounding { rcNearestOrEven, rcDownInfinity, rcUpInfinity, rcChopOrTruncate };
#pragma option pop

#pragma option push -b-
enum T8087Infinity { icProjective, icAffine };
#pragma option pop

#pragma option push -b-
enum T8087Exception { emInvalidOp, emDenormalizedOperand, emZeroDivide, emOverflow, emUnderflow, emPrecision };
#pragma option pop

typedef Set<T8087Exception, emInvalidOp, emPrecision>  T8087Exceptions;

//-- var, const, procedure ---------------------------------------------------
#define All8087Exceptions (Set<T8087Exception, emInvalidOp, emPrecision> () << T8087Exception(0) << T8087Exception(1) << T8087Exception(2) << T8087Exception(3) << T8087Exception(4) << T8087Exception(5) )
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE Word __fastcall Get8087ControlWord(void);
extern PACKAGE T8087Infinity __fastcall Get8087Infinity(void);
extern PACKAGE T8087Precision __fastcall Get8087Precision(void);
extern PACKAGE T8087Rounding __fastcall Get8087Rounding(void);
extern PACKAGE Word __fastcall Get8087StatusWord(bool ClearExceptions);
extern PACKAGE T8087Infinity __fastcall Set8087Infinity(const T8087Infinity Infinity);
extern PACKAGE T8087Precision __fastcall Set8087Precision(const T8087Precision Precision);
extern PACKAGE T8087Rounding __fastcall Set8087Rounding(const T8087Rounding Rounding);
extern PACKAGE Word __fastcall Set8087ControlWord(const Word Control);
extern PACKAGE T8087Exceptions __fastcall ClearPending8087Exceptions(void);
extern PACKAGE T8087Exceptions __fastcall GetPending8087Exceptions(void);
extern PACKAGE T8087Exceptions __fastcall GetMasked8087Exceptions(void);
extern PACKAGE T8087Exceptions __fastcall SetMasked8087Exceptions(T8087Exceptions Exceptions, bool ClearBefore = true);
extern PACKAGE T8087Exceptions __fastcall Mask8087Exceptions(T8087Exceptions Exceptions);
extern PACKAGE T8087Exceptions __fastcall Unmask8087Exceptions(T8087Exceptions Exceptions, bool ClearBefore = true);

}	/* namespace Jcl8087 */
using namespace Jcl8087;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcl8087
