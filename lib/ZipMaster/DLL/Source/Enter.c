//---------------------------------------------------------------------------

#include <windows.h>
#include "Enter.h"
#include <malloc.H>
#ifndef MULTITHREAD
  #error Multithread required
#endif

CRITICAL_SECTION csSync;
HINSTANCE ModuleInst = 0;
//---------------------------------------------------------------------------
/*
static int IsOpFrame(struct OpFrame * p)
{
  if (!p || heapchecknode(p) != _USEDENTRY)
	return 0;
  return p->ME == p && (p->OpTyp == ZIPOPER || p->OpTyp == UNZOPER);
}  */

#pragma argsused
int WINAPI DllEntryPoint( HINSTANCE hinst, unsigned long reason, void * lpReserved )
{
//  struct OpFrame *head;
  OutputDebugString("Entering DllEntryPoint ");
  switch ( reason )
  {
    case DLL_PROCESS_ATTACH:
      ModuleInst = hinst;
      InitializeCriticalSection(&csSync);
      Init_Process();
      // fall through
    case DLL_THREAD_ATTACH:
      break;
    case DLL_THREAD_DETACH:
      break;
    case DLL_PROCESS_DETACH:
      Cleanup_Process();
      DeleteCriticalSection(&csSync);
  }
  return 1;
}                      
int UCount = 0;
int ZCount = 0;   
unsigned int FCount = 0;
//---------------------------------------------------------------------------
void Set_Oper(Frames *Op, int typ)
{
  if (Op)
  {
    EnterCriticalSection(&csSync);
	if (typ == ZIPOPER || typ == UNZOPER)
    {
      Op->ME = Op;
      Op->OpTyp = typ;
      if (typ == ZIPOPER)
        ZCount++;
      else
        UCount++;
      FCount++;
    }
    else
    {
      Op->ME = NULL;   
      if (Op->OpTyp == ZIPOPER)
        ZCount--;
      else
        UCount--;
      Op->OpTyp = 0;
    }
    LeaveCriticalSection(&csSync);
  }
}


int Set_Oper_Abort(OperKeys key)
{
  int ret = 1;
  Frames *p = (Frames *)(key << 2);
  if (!p || heapchecknode(p) != _USEDENTRY)
    return -1;          // invalid
  EnterCriticalSection(&csSync);
  if (p->ME == p && (p->OpTyp == ZIPOPER || p->OpTyp == UNZOPER))
  {
    if (p->Abort_Flag > GA_CANCEL)
      ret--;           // could not set it
    else
      p->Abort_Flag |= GA_ABORT;
  }
  LeaveCriticalSection(&csSync);
  return ret;
}
 
