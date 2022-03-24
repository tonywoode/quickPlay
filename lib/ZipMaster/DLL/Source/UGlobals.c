#include <windows.h>
#include "Common.h"
#pragma hdrstop
/* This version by Chris Vleghert and Eric W. Engler
 * for BCB/Delphi Zip, Jun 18, 2000.
 */

/*---------------------------------------------------------------------------
 * uglobals.c
 * Routines to allocate and initialize globals, with or without threads.
 * Contents:  Create_UGlobals()
 *            Destrop_UGlobals()
 *            Current_UGlobals()
 *---------------------------------------------------------------------------*/

#include "enter.h" 
#include "unzip.h"
#include "process.h"  
#include "version.h"
#include <malloc.h>

const UnzFileData inames[2] =
  {
    {
      "*.*"
    },
    {
      NULL
    }
  };
/*
const fExFileData xnames[1] =
  {
    {
      NULL
    }
  };  */

struct UGlobals *Create_UGlobals( UnZipParms * C )
{
  struct UGlobals *pG = ( struct UGlobals * ) MALLOC( sizeof( struct UGlobals ) );
  if (!pG)
    return NULL;
  memset( pG, 0, sizeof( struct UGlobals ) );  
  Init_Frame((Frames *) pG);

  pG->Frame.OpKey = (OperKeys)C;
  pG->lflag = ( -1 );
  pG->pfnames = ( UnzFileData( * ) [] ) inames; //RCV was: (char **)fnames;
  pG->pInfo = pG->info;
  pG->sol = true;      // At start of line.  
  pG->Frame.global_handle = C->fHandle; // Application handle; can be NULL.
  pG->Frame.global_caller = C->fCaller; // We just give this back in the callback call.
  pG->Frame.callb = C->ZCallbackFunc; // Point to the BCB/Delphi callback function.
  pG->Frame.Verbose = C->fTraceEnabled ? -1 : C->fVerboseEnabled ?  1 : 0; 
  pG->qflag = C->fQuiet; // quiet flag
  pG->WantedCodePage = C->fWantedCodePage;
  pG->Frame.CallerVersion = C->fVersion;
  // setup for calback
//  pG->Frame.CallBackData.Handle = pG->Frame.global_handle; // Window handle of caller
  pG->Frame.CallBackData.Caller = pG->Frame.global_caller; // Object instance pointer of caller
  pG->Frame.CallBackData.Version = DELZIPVERS;
  pG->Frame.CallBackData.IsOperationZip = false; // true=zip, false=unzip

  return pG;
}

void Destroy_UGlobals( struct UGlobals *pG)
{
  Clean_Frame((Frames *)pG);
  free( pG );
}
/*
// only for non re-entrant older versions
struct UGlobals *Current_UGlobals( void )
{
  return (struct UGlobals *)Get_Current_Oper();
}
  */
 /*
int Init_Process(void)
{
  return 0;
}   */

int Clear_Oper1(struct OpFrame* Op)
{
  if (!Op || Op->OpTyp != UNZOPER)
    return -1;
  __try
  {     
//    Op->ME = NULL;
    Op->OpTyp = 0;
    Destroy_UGlobals( (struct UGlobals *)Op );   // is UGlobals *
  }
  __except ( 1 )
  {
//    do nothing - just swallow exception
  }
  return 0;
}

