// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclcounter.pas' rev: 10.00

#ifndef JclcounterHPP
#define JclcounterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclcounter
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TJclCounter;
class PASCALIMPLEMENTATION TJclCounter : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	bool FCounting;
	Extended FElapsedTime;
	__int64 FOverhead;
	Extended FOverallElapsedTime;
	__int64 FFrequency;
	__int64 FStart;
	__int64 FStop;
	
protected:
	Extended __fastcall GetRunElapsedTime(void);
	
public:
	__fastcall TJclCounter(const bool Compensate);
	void __fastcall Continue(void);
	void __fastcall Start(void);
	Extended __fastcall Stop(void);
	__property bool Counting = {read=FCounting, nodefault};
	__property Extended ElapsedTime = {read=FElapsedTime};
	__property __int64 Overhead = {read=FOverhead};
	__property Extended RunElapsedTime = {read=GetRunElapsedTime};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclCounter(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclCounterError;
class PASCALIMPLEMENTATION EJclCounterError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclCounterError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclCounterError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclCounterError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclCounterError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclCounterError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclCounterError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclCounterError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclCounterError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclCounterError(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE void __fastcall StartCount(TJclCounter* &Counter, const bool Compensate = false);
extern PACKAGE Extended __fastcall StopCount(TJclCounter* &Counter);
extern PACKAGE void __fastcall ContinueCount(TJclCounter* &Counter);

}	/* namespace Jclcounter */
using namespace Jclcounter;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclcounter
