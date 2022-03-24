// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcldatetime.pas' rev: 10.00

#ifndef JcldatetimeHPP
#define JcldatetimeHPP

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
#include <Jclbase.hpp>	// Pascal unit
#include <Jclresources.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jcldatetime
{
//-- type declarations -------------------------------------------------------
typedef int TDosDateTime;

typedef unsigned TJclUnixTime32;

class DELPHICLASS EJclDateTimeError;
class PASCALIMPLEMENTATION EJclDateTimeError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclDateTimeError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclDateTimeError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclDateTimeError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclDateTimeError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclDateTimeError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclDateTimeError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclDateTimeError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclDateTimeError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclDateTimeError(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word UnixTimeStart = 0x63e1;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE System::TDateTime __fastcall EncodeDate(const int Year, Word Month, Word Day)/* overload */;
extern PACKAGE void __fastcall DecodeDate(System::TDateTime Date, /* out */ Word &Year, /* out */ Word &Month, /* out */ Word &Day)/* overload */;
extern PACKAGE void __fastcall DecodeDate(System::TDateTime Date, /* out */ int &Year, /* out */ int &Month, /* out */ int &Day)/* overload */;
extern PACKAGE void __fastcall DecodeDate(System::TDateTime Date, /* out */ int &Year, /* out */ Word &Month, /* out */ Word &Day)/* overload */;
extern PACKAGE int __fastcall CenturyBaseYear(const System::TDateTime DateTime);
extern PACKAGE int __fastcall CenturyOfDate(const System::TDateTime DateTime);
extern PACKAGE int __fastcall DayOfDate(const System::TDateTime DateTime);
extern PACKAGE int __fastcall MonthOfDate(const System::TDateTime DateTime);
extern PACKAGE int __fastcall YearOfDate(const System::TDateTime DateTime);
extern PACKAGE int __fastcall DayOfTheYear(const System::TDateTime DateTime, /* out */ int &Year)/* overload */;
extern PACKAGE int __fastcall DayOfTheYear(const System::TDateTime DateTime)/* overload */;
extern PACKAGE System::TDateTime __fastcall DayOfTheYearToDateTime(const int Year, const int Day);
extern PACKAGE int __fastcall HourOfTime(const System::TDateTime DateTime);
extern PACKAGE int __fastcall MinuteOfTime(const System::TDateTime DateTime);
extern PACKAGE int __fastcall SecondOfTime(const System::TDateTime DateTime);
extern PACKAGE int __fastcall TimeOfDateTimeToSeconds(System::TDateTime DateTime);
extern PACKAGE int __fastcall TimeOfDateTimeToMSecs(System::TDateTime DateTime);
extern PACKAGE int __fastcall DaysInMonth(const System::TDateTime DateTime);
extern PACKAGE Word __fastcall ISODayOfWeek(const System::TDateTime DateTime);
extern PACKAGE bool __fastcall IsISOLongYear(const System::TDateTime DateTime)/* overload */;
extern PACKAGE bool __fastcall IsISOLongYear(const Word Year)/* overload */;
extern PACKAGE Word __fastcall GetISOYearNumberOfWeeks(const Word Year);
extern PACKAGE int __fastcall ISOWeekNumber(System::TDateTime DateTime, /* out */ int &YearOfWeekNumber, /* out */ int &WeekDay)/* overload */;
extern PACKAGE int __fastcall ISOWeekNumber(System::TDateTime DateTime, /* out */ int &YearOfWeekNumber)/* overload */;
extern PACKAGE int __fastcall ISOWeekNumber(System::TDateTime DateTime)/* overload */;
extern PACKAGE System::TDateTime __fastcall ISOWeekToDateTime(const int Year, const int Week, const int Day);
extern PACKAGE bool __fastcall IsLeapYear(const int Year)/* overload */;
extern PACKAGE bool __fastcall IsLeapYear(const System::TDateTime DateTime)/* overload */;
extern PACKAGE int __fastcall Make4DigitYear(int Year, int Pivot);
extern PACKAGE int __fastcall MakeYear4Digit(int Year, int WindowsillYear);
extern PACKAGE System::TDateTime __fastcall EasterSunday(const int Year);
extern PACKAGE System::TDateTime __fastcall DateTimeToLocalDateTime(System::TDateTime DateTime);
extern PACKAGE System::TDateTime __fastcall LocalDateTimeToDateTime(System::TDateTime DateTime);
extern PACKAGE int __fastcall HoursToMSecs(int Hours);
extern PACKAGE int __fastcall MinutesToMSecs(int Minutes);
extern PACKAGE int __fastcall SecondsToMSecs(int Seconds);
extern PACKAGE System::TDateTime __fastcall FileTimeToDateTime(const _FILETIME &FileTime);
extern PACKAGE System::TDateTime __fastcall FileTimeToLocalDateTime(const _FILETIME &FileTime);
extern PACKAGE _FILETIME __fastcall LocalDateTimeToFileTime(System::TDateTime DateTime);
extern PACKAGE _FILETIME __fastcall DateTimeToFileTime(System::TDateTime DateTime);
extern PACKAGE _SYSTEMTIME __fastcall DosDateTimeToSystemTime(const int DosTime);
extern PACKAGE int __fastcall SystemTimeToDosDateTime(const _SYSTEMTIME &SystemTime);
extern PACKAGE System::TDateTime __fastcall DosDateTimeToDateTime(const int DosTime);
extern PACKAGE int __fastcall DateTimeToDosDateTime(const System::TDateTime DateTime);
extern PACKAGE _SYSTEMTIME __fastcall FileTimeToSystemTime(const _FILETIME &FileTime)/* overload */;
extern PACKAGE void __fastcall FileTimeToSystemTime(const _FILETIME &FileTime, /* out */ _SYSTEMTIME &ST)/* overload */;
extern PACKAGE _FILETIME __fastcall SystemTimeToFileTime(const _SYSTEMTIME &SystemTime)/* overload */;
extern PACKAGE void __fastcall SystemTimeToFileTime(const _SYSTEMTIME &SystemTime, const _FILETIME &FTime)/* overload */;
extern PACKAGE _SYSTEMTIME __fastcall DateTimeToSystemTime(System::TDateTime DateTime)/* overload */;
extern PACKAGE void __fastcall DateTimeToSystemTime(System::TDateTime DateTime, /* out */ _SYSTEMTIME &SysTime)/* overload */;
extern PACKAGE _FILETIME __fastcall DosDateTimeToFileTime(int DosTime)/* overload */;
extern PACKAGE void __fastcall DosDateTimeToFileTime(Word DTH, Word DTL, const _FILETIME &FT)/* overload */;
extern PACKAGE int __fastcall FileTimeToDosDateTime(const _FILETIME &FileTime)/* overload */;
extern PACKAGE void __fastcall FileTimeToDosDateTime(const _FILETIME &FileTime, /* out */ Word &Date, /* out */ Word &Time)/* overload */;
extern PACKAGE AnsiString __fastcall FileTimeToStr(const _FILETIME &FileTime);
extern PACKAGE AnsiString __fastcall DosDateTimeToStr(int DateTime);
extern PACKAGE AnsiString __fastcall SystemTimeToStr(const _SYSTEMTIME &SystemTime);
extern PACKAGE System::TDateTime __fastcall CreationDateTimeOfFile(const Sysutils::TSearchRec &Sr);
extern PACKAGE System::TDateTime __fastcall LastAccessDateTimeOfFile(const Sysutils::TSearchRec &Sr);
extern PACKAGE System::TDateTime __fastcall LastWriteDateTimeOfFile(const Sysutils::TSearchRec &Sr);
extern PACKAGE AnsiString __fastcall FormatDateTime(AnsiString Form, System::TDateTime DateTime);
extern PACKAGE bool __fastcall FATDatesEqual(const __int64 FileTime1, const __int64 FileTime2)/* overload */;
extern PACKAGE bool __fastcall FATDatesEqual(const _FILETIME &FileTime1, const _FILETIME &FileTime2)/* overload */;
extern PACKAGE unsigned __fastcall DateTimeToUnixTime(System::TDateTime DateTime);
extern PACKAGE System::TDateTime __fastcall UnixTimeToDateTime(const unsigned UnixTime);
extern PACKAGE _FILETIME __fastcall UnixTimeToFileTime(const unsigned AValue);
extern PACKAGE unsigned __fastcall FileTimeToUnixTime(const _FILETIME &AValue);
extern PACKAGE Sysutils::TTimeStamp __fastcall NullStamp();
extern PACKAGE __int64 __fastcall CompareTimeStamps(const Sysutils::TTimeStamp &Stamp1, const Sysutils::TTimeStamp &Stamp2);
extern PACKAGE bool __fastcall EqualTimeStamps(const Sysutils::TTimeStamp &Stamp1, const Sysutils::TTimeStamp &Stamp2);
extern PACKAGE bool __fastcall IsNullTimeStamp(const Sysutils::TTimeStamp &Stamp);
extern PACKAGE int __fastcall TimeStampDOW(const Sysutils::TTimeStamp &Stamp);
extern PACKAGE int __fastcall FirstWeekDay(const int Year, const int Month, /* out */ int &DOW)/* overload */;
extern PACKAGE int __fastcall FirstWeekDay(const int Year, const int Month)/* overload */;
extern PACKAGE int __fastcall LastWeekDay(const int Year, const int Month, /* out */ int &DOW)/* overload */;
extern PACKAGE int __fastcall LastWeekDay(const int Year, const int Month)/* overload */;
extern PACKAGE int __fastcall IndexedWeekDay(const int Year, const int Month, int Index);
extern PACKAGE int __fastcall FirstWeekendDay(const int Year, const int Month, /* out */ int &DOW)/* overload */;
extern PACKAGE int __fastcall FirstWeekendDay(const int Year, const int Month)/* overload */;
extern PACKAGE int __fastcall LastWeekendDay(const int Year, const int Month, /* out */ int &DOW)/* overload */;
extern PACKAGE int __fastcall LastWeekendDay(const int Year, const int Month)/* overload */;
extern PACKAGE int __fastcall IndexedWeekendDay(const int Year, const int Month, int Index);
extern PACKAGE int __fastcall FirstDayOfWeek(const int Year, const int Month, const int DayOfWeek);
extern PACKAGE int __fastcall LastDayOfWeek(const int Year, const int Month, const int DayOfWeek);
extern PACKAGE int __fastcall IndexedDayOfWeek(const int Year, const int Month, const int DayOfWeek, const int Index);

}	/* namespace Jcldatetime */
using namespace Jcldatetime;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcldatetime
