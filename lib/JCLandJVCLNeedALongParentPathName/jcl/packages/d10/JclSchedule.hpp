// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclschedule.pas' rev: 10.00

#ifndef JclscheduleHPP
#define JclscheduleHPP

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

namespace Jclschedule
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TScheduleRecurringKind { srkOneShot, srkDaily, srkWeekly, srkMonthly, srkYearly };
#pragma option pop

#pragma option push -b-
enum TScheduleEndKind { sekNone, sekDate, sekTriggerCount, sekDayCount };
#pragma option pop

#pragma option push -b-
enum TScheduleWeekDay { swdMonday, swdTuesday, swdWednesday, swdThursday, swdFriday, swdSaturday, swdSunday };
#pragma option pop

typedef Set<TScheduleWeekDay, swdMonday, swdSunday>  TScheduleWeekDays;

#pragma option push -b-
enum TScheduleIndexKind { sikNone, sikDay, sikWeekDay, sikWeekendDay, sikMonday, sikTuesday, sikWednesday, sikThursday, sikFriday, sikSaturday, sikSunday };
#pragma option pop

class DELPHICLASS EJclScheduleError;
class PASCALIMPLEMENTATION EJclScheduleError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclScheduleError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclScheduleError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclScheduleError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclScheduleError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclScheduleError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclScheduleError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclScheduleError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclScheduleError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclScheduleError(void) { }
	#pragma option pop
	
};


typedef EJclScheduleError ESchedule;
;

__interface IJclSchedule;
typedef System::DelphiInterface<IJclSchedule> _di_IJclSchedule;
__interface  INTERFACE_UUID("{1CC54450-7F84-4F27-B1C1-418C451DAD80}") IJclSchedule  : public IInterface 
{
	
public:
	virtual Sysutils::TTimeStamp __fastcall GetStartDate(void) = 0 ;
	virtual TScheduleRecurringKind __fastcall GetRecurringType(void) = 0 ;
	virtual TScheduleEndKind __fastcall GetEndType(void) = 0 ;
	virtual Sysutils::TTimeStamp __fastcall GetEndDate(void) = 0 ;
	virtual unsigned __fastcall GetEndCount(void) = 0 ;
	virtual void __fastcall SetStartDate(const Sysutils::TTimeStamp &Value) = 0 ;
	virtual void __fastcall SetRecurringType(TScheduleRecurringKind Value) = 0 ;
	virtual void __fastcall SetEndType(TScheduleEndKind Value) = 0 ;
	virtual void __fastcall SetEndDate(const Sysutils::TTimeStamp &Value) = 0 ;
	virtual void __fastcall SetEndCount(unsigned Value) = 0 ;
	virtual unsigned __fastcall TriggerCount(void) = 0 ;
	virtual unsigned __fastcall DayCount(void) = 0 ;
	virtual Sysutils::TTimeStamp __fastcall LastTriggered(void) = 0 ;
	virtual void __fastcall InitToSavedState(const Sysutils::TTimeStamp &LastTriggerStamp, const unsigned LastTriggerCount, const unsigned LastDayCount) = 0 ;
	virtual void __fastcall Reset(void) = 0 ;
	virtual Sysutils::TTimeStamp __fastcall NextEvent(bool CountMissedEvents = false) = 0 ;
	virtual Sysutils::TTimeStamp __fastcall NextEventFrom(const Sysutils::TTimeStamp &FromEvent, bool CountMissedEvent = false) = 0 ;
	virtual Sysutils::TTimeStamp __fastcall NextEventFromNow(bool CountMissedEvents = false) = 0 ;
	__property Sysutils::TTimeStamp StartDate = {read=GetStartDate, write=SetStartDate};
	__property TScheduleRecurringKind RecurringType = {read=GetRecurringType, write=SetRecurringType};
	__property TScheduleEndKind EndType = {read=GetEndType, write=SetEndType};
	__property Sysutils::TTimeStamp EndDate = {read=GetEndDate, write=SetEndDate};
	__property unsigned EndCount = {read=GetEndCount, write=SetEndCount};
};

__interface IJclScheduleDayFrequency;
typedef System::DelphiInterface<IJclScheduleDayFrequency> _di_IJclScheduleDayFrequency;
__interface  INTERFACE_UUID("{6CF37F0D-56F4-4AE6-BBCA-7B9DFE60F50D}") IJclScheduleDayFrequency  : public IInterface 
{
	
public:
	virtual unsigned __fastcall GetStartTime(void) = 0 ;
	virtual unsigned __fastcall GetEndTime(void) = 0 ;
	virtual unsigned __fastcall GetInterval(void) = 0 ;
	virtual void __fastcall SetStartTime(unsigned Value) = 0 ;
	virtual void __fastcall SetEndTime(unsigned Value) = 0 ;
	virtual void __fastcall SetInterval(unsigned Value) = 0 ;
	__property unsigned StartTime = {read=GetStartTime, write=SetStartTime};
	__property unsigned EndTime = {read=GetEndTime, write=SetEndTime};
	__property unsigned Interval = {read=GetInterval, write=SetInterval};
};

__interface IJclDailySchedule;
typedef System::DelphiInterface<IJclDailySchedule> _di_IJclDailySchedule;
__interface  INTERFACE_UUID("{540E22C5-BE14-4539-AFB3-E24A67C58D8A}") IJclDailySchedule  : public IInterface 
{
	
public:
	virtual bool __fastcall GetEveryWeekDay(void) = 0 ;
	virtual unsigned __fastcall GetInterval(void) = 0 ;
	virtual void __fastcall SetEveryWeekDay(bool Value) = 0 ;
	virtual void __fastcall SetInterval(unsigned Value) = 0 ;
	__property bool EveryWeekDay = {read=GetEveryWeekDay, write=SetEveryWeekDay};
	__property unsigned Interval = {read=GetInterval, write=SetInterval};
};

__interface IJclWeeklySchedule;
typedef System::DelphiInterface<IJclWeeklySchedule> _di_IJclWeeklySchedule;
__interface  INTERFACE_UUID("{73F15D99-C6A1-4526-8DE3-A2110E099BBC}") IJclWeeklySchedule  : public IInterface 
{
	
public:
	virtual TScheduleWeekDays __fastcall GetDaysOfWeek(void) = 0 ;
	virtual unsigned __fastcall GetInterval(void) = 0 ;
	virtual void __fastcall SetDaysOfWeek(TScheduleWeekDays Value) = 0 ;
	virtual void __fastcall SetInterval(unsigned Value) = 0 ;
	__property TScheduleWeekDays DaysOfWeek = {read=GetDaysOfWeek, write=SetDaysOfWeek};
	__property unsigned Interval = {read=GetInterval, write=SetInterval};
};

__interface IJclMonthlySchedule;
typedef System::DelphiInterface<IJclMonthlySchedule> _di_IJclMonthlySchedule;
__interface  INTERFACE_UUID("{705E17FC-83E6-4385-8D2D-17013052E9B3}") IJclMonthlySchedule  : public IInterface 
{
	
public:
	virtual TScheduleIndexKind __fastcall GetIndexKind(void) = 0 ;
	virtual int __fastcall GetIndexValue(void) = 0 ;
	virtual unsigned __fastcall GetDay(void) = 0 ;
	virtual unsigned __fastcall GetInterval(void) = 0 ;
	virtual void __fastcall SetIndexKind(TScheduleIndexKind Value) = 0 ;
	virtual void __fastcall SetIndexValue(int Value) = 0 ;
	virtual void __fastcall SetDay(unsigned Value) = 0 ;
	virtual void __fastcall SetInterval(unsigned Value) = 0 ;
	__property TScheduleIndexKind IndexKind = {read=GetIndexKind, write=SetIndexKind};
	__property int IndexValue = {read=GetIndexValue, write=SetIndexValue};
	__property unsigned Day = {read=GetDay, write=SetDay};
	__property unsigned Interval = {read=GetInterval, write=SetInterval};
};

__interface IJclYearlySchedule;
typedef System::DelphiInterface<IJclYearlySchedule> _di_IJclYearlySchedule;
__interface  INTERFACE_UUID("{3E5303B0-FFA0-495A-96BB-14A718A01C1B}") IJclYearlySchedule  : public IInterface 
{
	
public:
	virtual TScheduleIndexKind __fastcall GetIndexKind(void) = 0 ;
	virtual int __fastcall GetIndexValue(void) = 0 ;
	virtual unsigned __fastcall GetDay(void) = 0 ;
	virtual unsigned __fastcall GetMonth(void) = 0 ;
	virtual unsigned __fastcall GetInterval(void) = 0 ;
	virtual void __fastcall SetIndexKind(TScheduleIndexKind Value) = 0 ;
	virtual void __fastcall SetIndexValue(int Value) = 0 ;
	virtual void __fastcall SetDay(unsigned Value) = 0 ;
	virtual void __fastcall SetMonth(unsigned Value) = 0 ;
	virtual void __fastcall SetInterval(unsigned Value) = 0 ;
	__property TScheduleIndexKind IndexKind = {read=GetIndexKind, write=SetIndexKind};
	__property int IndexValue = {read=GetIndexValue, write=SetIndexValue};
	__property unsigned Day = {read=GetDay, write=SetDay};
	__property unsigned Month = {read=GetMonth, write=SetMonth};
	__property unsigned Interval = {read=GetInterval, write=SetInterval};
};

//-- var, const, procedure ---------------------------------------------------
static const Shortint sivFirst = 0x1;
static const Shortint sivSecond = 0x2;
static const Shortint sivThird = 0x3;
static const Shortint sivFourth = 0x4;
static const Shortint sivLast = -1;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE _di_IJclSchedule __fastcall CreateSchedule();

}	/* namespace Jclschedule */
using namespace Jclschedule;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclschedule
