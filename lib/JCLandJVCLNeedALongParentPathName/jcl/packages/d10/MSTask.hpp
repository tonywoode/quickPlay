// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Mstask.pas' rev: 10.00

#ifndef MstaskHPP
#define MstaskHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Activex.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <MSTask.h>

namespace Mstask
{
//-- type declarations -------------------------------------------------------
typedef _TASK_TRIGGER_TYPE TTaskTriggerType;

typedef _TASK_TRIGGER_TYPE *PTaskTriggerType;

typedef _DAILY  TDaily;

typedef _WEEKLY  TWeekly;

typedef _MONTHLYDATE  TMonthlyDate;

typedef _MONTHLYDOW  TMonthlyDOW;

typedef _TRIGGER_TYPE_UNION  TTriggerTypeUnion;

typedef _TASK_TRIGGER  TTaskTrigger;

typedef _TASK_TRIGGER *PTaskTrigger;

typedef _TASKPAGE TTaskPage;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Mstask */
using namespace Mstask;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Mstask
