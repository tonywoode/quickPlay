// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcltimezones.pas' rev: 10.00

#ifndef JcltimezonesHPP
#define JcltimezonesHPP

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
#include <Contnrs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jcltimezones
{
//-- type declarations -------------------------------------------------------
struct TJclTZIValueInfo
{
	
public:
	int Bias;
	int StandardBias;
	int DaylightBias;
	_SYSTEMTIME StandardDate;
	_SYSTEMTIME DaylightDate;
} ;

struct TJclTimeZoneRegInfo;
typedef TJclTimeZoneRegInfo *PJclTimeZoneRegInfo;

struct TJclTimeZoneRegInfo
{
	
public:
	AnsiString DisplayDesc;
	AnsiString StandardName;
	AnsiString DaylightName;
	int SortIndex;
	AnsiString MapID;
	TJclTZIValueInfo TZI;
} ;

typedef bool __fastcall (__closure *TJclTimeZoneCallBackFunc)(const TJclTimeZoneRegInfo &TimeZoneRec);

class DELPHICLASS TJclTimeZoneInfo;
class PASCALIMPLEMENTATION TJclTimeZoneInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FStandardName;
	AnsiString FDaylightName;
	AnsiString FTZDescription;
	int FSortIndex;
	AnsiString FMapID;
	TJclTZIValueInfo FBiasInfo;
	int __fastcall GetActiveBias(void);
	System::TDateTime __fastcall GetCurrentDateTime(void);
	System::TDateTime __fastcall GetDaylightSavingsStartDate(void);
	AnsiString __fastcall GetGMTOffset();
	System::TDateTime __fastcall GetStandardStartDate(void);
	bool __fastcall GetSupportsDaylightSavings(void);
	unsigned __fastcall GetTimeZoneType(const TJclTZIValueInfo &TZI);
	
public:
	void __fastcall Assign(const TJclTimeZoneRegInfo &Source);
	void __fastcall ApplyTimeZone(void);
	AnsiString __fastcall DayLightSavingsPeriod();
	bool __fastcall DateTimeIsInDaylightSavings(System::TDateTime ADateTime);
	System::TDateTime __fastcall StandardStartDateInYear(const int AYear);
	System::TDateTime __fastcall DaylightStartDateInYear(const int AYear);
	__property int ActiveBias = {read=GetActiveBias, nodefault};
	__property System::TDateTime CurrentDateTime = {read=GetCurrentDateTime};
	__property AnsiString DaylightName = {read=FDaylightName};
	__property System::TDateTime DaylightSavingsStartDate = {read=GetDaylightSavingsStartDate};
	__property AnsiString DisplayDescription = {read=FTZDescription};
	__property AnsiString GMTOffset = {read=GetGMTOffset};
	__property AnsiString MapID = {read=FMapID};
	__property int SortIndex = {read=FSortIndex, nodefault};
	__property AnsiString StandardName = {read=FStandardName};
	__property System::TDateTime StandardStartDate = {read=GetStandardStartDate};
	__property bool SupportsDaylightSavings = {read=GetSupportsDaylightSavings, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclTimeZoneInfo(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTimeZoneInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTimeZones;
class PASCALIMPLEMENTATION TJclTimeZones : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TJclTimeZoneInfo* operator[](int Index) { return Items[Index]; }
	
private:
	int FActiveTimeZoneIndex;
	Contnrs::TObjectList* FTimeZones;
	bool FAutoAdjustEnabled;
	bool __fastcall GetAutoAdjustEnabled(void);
	TJclTimeZoneInfo* __fastcall GetActiveTimeZoneInfo(void);
	int __fastcall GetCount(void);
	TJclTimeZoneInfo* __fastcall GetItem(int Index);
	void __fastcall LoadTimeZones(void);
	bool __fastcall TimeZoneCallback(const TJclTimeZoneRegInfo &TimeZoneRec);
	
public:
	__fastcall TJclTimeZones(void);
	__fastcall virtual ~TJclTimeZones(void);
	bool __fastcall SetDateTime(System::TDateTime DateTime);
	void __fastcall SetAutoAdjustEnabled(bool Value);
	__property int Count = {read=GetCount, nodefault};
	__property TJclTimeZoneInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property TJclTimeZoneInfo* ActiveTimeZone = {read=GetActiveTimeZoneInfo};
	__property bool AutoAdjustEnabled = {read=FAutoAdjustEnabled, write=FAutoAdjustEnabled, nodefault};
};


class DELPHICLASS EDaylightSavingsNotSupported;
class PASCALIMPLEMENTATION EDaylightSavingsNotSupported : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EDaylightSavingsNotSupported(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EDaylightSavingsNotSupported(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EDaylightSavingsNotSupported(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EDaylightSavingsNotSupported(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EDaylightSavingsNotSupported(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EDaylightSavingsNotSupported(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EDaylightSavingsNotSupported(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EDaylightSavingsNotSupported(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EDaylightSavingsNotSupported(void) { }
	#pragma option pop
	
};


class DELPHICLASS EAutoAdjustNotEnabled;
class PASCALIMPLEMENTATION EAutoAdjustNotEnabled : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EAutoAdjustNotEnabled(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EAutoAdjustNotEnabled(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EAutoAdjustNotEnabled(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EAutoAdjustNotEnabled(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EAutoAdjustNotEnabled(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EAutoAdjustNotEnabled(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EAutoAdjustNotEnabled(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EAutoAdjustNotEnabled(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EAutoAdjustNotEnabled(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE bool __fastcall EnumTimeZones(TJclTimeZoneCallBackFunc CallBackFunc);
extern PACKAGE bool __fastcall CurrentTimeZoneSupportsDaylightSavings(void);
extern PACKAGE System::TDateTime __fastcall DateCurrentTimeZoneClocksChangeToDaylightSavings(void);
extern PACKAGE System::TDateTime __fastcall DateCurrentTimeZoneClocksChangeToStandard(void);
extern PACKAGE AnsiString __fastcall GetCurrentTimeZoneDescription();
extern PACKAGE AnsiString __fastcall GetCurrentTimeZoneDaylightSavingsPeriod();
extern PACKAGE AnsiString __fastcall GetCurrentTimeZoneGMTOffset();
extern PACKAGE int __fastcall GetCurrentTimeZoneUTCBias(void);
extern PACKAGE System::TDateTime __fastcall UTCNow(void);
extern PACKAGE AnsiString __fastcall GetWMIScheduledJobUTCTime(System::TDateTime Time);
extern PACKAGE bool __fastcall IsAutoAdjustEnabled(void);

}	/* namespace Jcltimezones */
using namespace Jcltimezones;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcltimezones
