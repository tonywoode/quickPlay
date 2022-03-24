// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcltask.pas' rev: 10.00

#ifndef JcltaskHPP
#define JcltaskHPP

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
#include <Sysutils.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Mstask.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclsysutils.hpp>	// Pascal unit
#include <Jclsysinfo.hpp>	// Pascal unit
#include <Jclwidestrings.hpp>	// Pascal unit
#include <Jclwin32.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#define _di_ITaskScheduler ITaskScheduler*
#define _di_ITask ITask*
#define _di_ITaskTrigger ITaskTrigger*
#define _di_IScheduledWorkItem IScheduledWorkItem*

namespace Jcltask
{
//-- type declarations -------------------------------------------------------
typedef DynamicArray<System::TDateTime >  TDateTimeArray;

#pragma option push -b-
enum TJclScheduledTaskStatus { tsUnknown, tsReady, tsRunning, tsNotScheduled, tsHasNotRun };
#pragma option pop

#pragma option push -b-
enum TJclScheduledTaskFlag { tfInteractive, tfDeleteWhenDone, tfDisabled, tfStartOnlyIfIdle, tfKillOnIdleEndl, tfDontStartIfOnBatteries, tfKillIfGoingOnBatteries, tfRunOnlyIfDocked, tfHidden, tfRunIfConnectedToInternet, tfRestartOnIdleResume, tfSystemRequired, tfRunOnlyIfLoggedOn };
#pragma option pop

typedef Set<TJclScheduledTaskFlag, tfInteractive, tfRunOnlyIfLoggedOn>  TJclScheduledTaskFlags;

#pragma option push -b-
enum TJclScheduleTaskPropertyPage { ppTask, ppSchedule, ppSettings };
#pragma option pop

typedef Set<TJclScheduleTaskPropertyPage, ppTask, ppSettings>  TJclScheduleTaskPropertyPages;

class DELPHICLASS TJclTaskSchedule;
class DELPHICLASS TJclScheduledTask;
class PASCALIMPLEMENTATION TJclTaskSchedule : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TJclScheduledTask* operator[](int Idx) { return Tasks[Idx]; }
	
private:
	_di_ITaskScheduler FTaskScheduler;
	Contnrs::TObjectList* FTasks;
	WideString __fastcall GetTargetComputer();
	void __fastcall SetTargetComputer(const WideString Value);
	TJclScheduledTask* __fastcall GetTask(const int Idx);
	int __fastcall GetTaskCount(void);
	
public:
	__fastcall TJclTaskSchedule(const WideString ComputerName);
	__fastcall virtual ~TJclTaskSchedule(void);
	void __fastcall Refresh(void);
	TJclScheduledTask* __fastcall Add(const WideString TaskName);
	void __fastcall Delete(const int Idx);
	int __fastcall Remove(const WideString TaskName)/* overload */;
	int __fastcall Remove(const _di_ITask TaskIntf)/* overload */;
	int __fastcall Remove(const TJclScheduledTask* ATask)/* overload */;
	__property _di_ITaskScheduler TaskScheduler = {read=FTaskScheduler};
	__property WideString TargetComputer = {read=GetTargetComputer, write=SetTargetComputer};
	__property TJclScheduledTask* Tasks[int Idx] = {read=GetTask/*, default*/};
	__property int TaskCount = {read=GetTaskCount, nodefault};
	/*         class method */ static bool __fastcall IsRunning(TMetaClass* vmt);
	/*         class method */ static void __fastcall Start(TMetaClass* vmt);
	/*         class method */ static void __fastcall Stop(TMetaClass* vmt);
};


class DELPHICLASS TJclTaskTrigger;
class PASCALIMPLEMENTATION TJclTaskTrigger : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	_di_ITaskTrigger FTaskTrigger;
	void __fastcall SetTaskTrigger(const _di_ITaskTrigger Value);
	_TASK_TRIGGER __fastcall GetTrigger();
	void __fastcall SetTrigger(const _TASK_TRIGGER &Value);
	WideString __fastcall GetTriggerString();
	
public:
	__property _di_ITaskTrigger TaskTrigger = {read=FTaskTrigger};
	__property _TASK_TRIGGER Trigger = {read=GetTrigger, write=SetTrigger};
	__property WideString TriggerString = {read=GetTriggerString};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TJclTaskTrigger(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TJclTaskTrigger(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclTaskTriggers;
class DELPHICLASS TJclScheduledWorkItem;
class PASCALIMPLEMENTATION TJclScheduledWorkItem : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
public:
	TJclTaskTrigger* operator[](int Idx) { return Triggers[Idx]; }
	
private:
	_di_IScheduledWorkItem FScheduledWorkItem;
	WideString FTaskName;
	Classes::TMemoryStream* FData;
	TJclTaskTriggers* FTriggers;
	WideString __fastcall GetAccountName();
	void __fastcall SetAccountName(const WideString Value);
	void __fastcall SetPassword(const WideString Value);
	WideString __fastcall GetComment();
	void __fastcall SetComment(const WideString Value);
	WideString __fastcall GetCreator();
	void __fastcall SetCreator(const WideString Value);
	unsigned __fastcall GetExitCode(void);
	Word __fastcall GetDeadlineMinutes(void);
	Word __fastcall GetIdleMinutes(void);
	_SYSTEMTIME __fastcall GetMostRecentRunTime();
	_SYSTEMTIME __fastcall GetNextRunTime();
	TJclScheduledTaskStatus __fastcall GetStatus(void);
	Word __fastcall GetErrorRetryCount(void);
	void __fastcall SetErrorRetryCount(const Word Value);
	Word __fastcall GetErrorRetryInterval(void);
	void __fastcall SetErrorRetryInterval(const Word Value);
	TJclScheduledTaskFlags __fastcall GetFlags(void);
	void __fastcall SetFlags(const TJclScheduledTaskFlags Value);
	Classes::TStream* __fastcall GetData(void);
	void __fastcall SetData(const Classes::TStream* Value);
	TJclTaskTrigger* __fastcall GetTrigger(const int Idx);
	int __fastcall GetTriggerCount(void);
	
public:
	__fastcall TJclScheduledWorkItem(const WideString ATaskName, const _di_IScheduledWorkItem AScheduledWorkItem);
	__fastcall virtual ~TJclScheduledWorkItem(void);
	void __fastcall Save(void);
	void __fastcall Refresh(void);
	void __fastcall Run(void);
	void __fastcall Terminate(void);
	void __fastcall SetAccountInformation(const WideString Name, const WideString Password);
	TDateTimeArray __fastcall GetRunTimes(const System::TDateTime BeginTime, const System::TDateTime EndTime = 0.000000E+00);
	__property _di_IScheduledWorkItem ScheduledWorkItem = {read=FScheduledWorkItem};
	__property WideString TaskName = {read=FTaskName, write=FTaskName};
	__property WideString AccountName = {read=GetAccountName, write=SetAccountName};
	__property WideString Password = {write=SetPassword};
	__property WideString Comment = {read=GetComment, write=SetComment};
	__property WideString Creator = {read=GetCreator, write=SetCreator};
	__property Word ErrorRetryCount = {read=GetErrorRetryCount, write=SetErrorRetryCount, nodefault};
	__property Word ErrorRetryInterval = {read=GetErrorRetryInterval, write=SetErrorRetryInterval, nodefault};
	__property unsigned ExitCode = {read=GetExitCode, nodefault};
	__property Classes::TStream* OwnerData = {read=GetData, write=SetData};
	__property Word IdleMinutes = {read=GetIdleMinutes, nodefault};
	__property Word DeadlineMinutes = {read=GetDeadlineMinutes, nodefault};
	__property _SYSTEMTIME MostRecentRunTime = {read=GetMostRecentRunTime};
	__property _SYSTEMTIME NextRunTime = {read=GetNextRunTime};
	__property TJclScheduledTaskStatus Status = {read=GetStatus, nodefault};
	__property TJclScheduledTaskFlags Flags = {read=GetFlags, write=SetFlags, nodefault};
	__property TJclTaskTrigger* Triggers[int Idx] = {read=GetTrigger/*, default*/};
	__property int TriggerCount = {read=GetTriggerCount, nodefault};
};


class PASCALIMPLEMENTATION TJclTaskTriggers : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	TJclTaskTrigger* operator[](int Index) { return Items[Index]; }
	
public:
	TJclScheduledWorkItem* FWorkItem;
	HIDESBASE TJclTaskTrigger* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TJclTaskTrigger* Value);
	
protected:
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall TJclTaskTriggers(TJclScheduledWorkItem* AWorkItem);
	HIDESBASE TJclTaskTrigger* __fastcall Add(_di_ITaskTrigger ATrigger)/* overload */;
	HIDESBASE TJclTaskTrigger* __fastcall Add(void)/* overload */;
	TJclTaskTrigger* __fastcall AddItem(TJclTaskTrigger* Item, int Index);
	HIDESBASE TJclTaskTrigger* __fastcall Insert(int Index);
	__property TJclTaskTrigger* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TJclTaskTriggers(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TJclScheduledTask : public TJclScheduledWorkItem 
{
	typedef TJclScheduledWorkItem inherited;
	
private:
	WideString __fastcall GetApplicationName();
	void __fastcall SetApplicationName(const WideString Value);
	unsigned __fastcall GetMaxRunTime(void);
	void __fastcall SetMaxRunTime(const unsigned Value);
	WideString __fastcall GetParameters();
	void __fastcall SetParameters(const WideString Value);
	unsigned __fastcall GetPriority(void);
	void __fastcall SetPriority(const unsigned Value);
	unsigned __fastcall GetTaskFlags(void);
	void __fastcall SetTaskFlags(const unsigned Value);
	WideString __fastcall GetWorkingDirectory();
	void __fastcall SetWorkingDirectory(const WideString Value);
	_di_ITask __fastcall GetTask();
	
public:
	bool __fastcall ShowPage(TJclScheduleTaskPropertyPages Pages = (Set<TJclScheduleTaskPropertyPage, ppTask, ppSettings> () << TJclScheduleTaskPropertyPage(0) << TJclScheduleTaskPropertyPage(1) << TJclScheduleTaskPropertyPage(2) ));
	__property _di_ITask Task = {read=GetTask};
	__property WideString ApplicationName = {read=GetApplicationName, write=SetApplicationName};
	__property WideString WorkingDirectory = {read=GetWorkingDirectory, write=SetWorkingDirectory};
	__property unsigned MaxRunTime = {read=GetMaxRunTime, write=SetMaxRunTime, nodefault};
	__property WideString Parameters = {read=GetParameters, write=SetParameters};
	__property unsigned Priority = {read=GetPriority, write=SetPriority, nodefault};
	__property unsigned TaskFlags = {read=GetTaskFlags, write=SetTaskFlags, nodefault};
public:
	#pragma option push -w-inl
	/* TJclScheduledWorkItem.Create */ inline __fastcall TJclScheduledTask(const WideString ATaskName, const _di_IScheduledWorkItem AScheduledWorkItem) : TJclScheduledWorkItem(ATaskName, AScheduledWorkItem) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclScheduledWorkItem.Destroy */ inline __fastcall virtual ~TJclScheduledTask(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define JclScheduleTaskAllPages (Set<TJclScheduleTaskPropertyPage, ppTask, ppSettings> () << TJclScheduleTaskPropertyPage(0) << TJclScheduleTaskPropertyPage(1) << TJclScheduleTaskPropertyPage(2) )
#define LocalSystemAccount "SYSTEM"
#define InfiniteTime  (0.000000E+00)
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jcltask */
using namespace Jcltask;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcltask
