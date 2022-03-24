#include <windows.h>
#include "Common.h"
#pragma hdrstop
#include "enter.h"
/* Main UnZip DLL module
* This version modified by Chris Vleghert and Eric W. Engler
* for BCB/Delphi Zip.
* Based on Mike White's DLL, but is dissimilar in many ways.
* This module has the entry point for the two calls from BCB and Delphi. */

// EWE note: we get globals.h from this path:
// unzip.h -> unzpriv.h -> uglobals.h
//#include "wizunzip.h"
#include "unzip.h"
#include "version.h"
#include "uconsts.h"
#include <excpt.h>

bool FSetUpToProcessZipFile( struct UGlobals * pG, UnZipParms * C );
void TakeDownFromProcessZipFile( struct UGlobals * pG );

static void GiveTime( struct UGlobals * pG );
static void GiveGlobals( struct UGlobals * pG );

#define PWLEN 80

// Not all values here are used
static const char * uerrors[] =
  {
    "", // 0=File not found
    "", // 1=password failed
    "", // 2=Unexpected end of zip file
    "Zip file structure invalid", // 3
    "Out of memory", // 4
    "", //5=Internal logic error
    "Central dir not in ZIP file", // 6
    "No multi-disk archives supported", // 7
    "Can't find start of central dir", // 8
    "Aborted by user", // 9
    "", // 10=Temporary file failure
    "Error reading a file", // 11
    "", // 12=Nothing to do!
    "Error opening ZIP file: %s", // 13
    "Error writing to a file", // 14
    "", // 15=Error creating file
    "Bad unzip options specified", // 16
    "", // 17=Password canceled
    "", // 18=File not found or no read permission
    "Fatal Error: central dir signature not found", // 19
    "Premature eof in archive" // 20
  };

/* ===================================================== * /

/* =====================================================
* Main entry point to unzip files.
*/
static long UnzExec1(struct UGlobals* pG, UnZipParms * C );

long WINAPI DZ_UnzExec(UnZipParms * C )
{
  long RetVal;
  struct UGlobals* pG;
  if (!C)
    return -9;
  pG = Create_UGlobals( C );
  if (!pG)
    return CRITICAL_MEMORY;     
//  pG->Frame.ME = (Frames*) pG;    // allow abort
  Set_Oper(PF, UNZOPER);
  _CB_.Arg1 = ((unsigned) pG) >> 2;
  User_CB(PF, zacKey);
  QueryINI((Frames *)pG, false);
//  Add_Oper((struct OpFrame*)pG, UNZOPER);
  RetVal = UnzExec1(pG, C); 
//  pG->Frame.ME = 0;     // stop abort
  Set_Oper(PF, UNZOPER);
  _CB_.Arg1 = 0;
  User_CB(PF, zacKey);
//  Remove_Oper((struct OpFrame*)pG);
  Destroy_UGlobals(pG);
  return RetVal;
}

static long UnzExec1(struct UGlobals* pG, UnZipParms * C )
{
  int FilesActedOn;
//  int abort_val;

  if (C->fSeven != 7 ) // look in new struct if we are on a newer version
    return CRITICAL_STRUCT;
 
  if (pG->Frame.Verbose < 0)
    Notify( PF, 0,  "trace is on, function=UnzDllExec [%d %d %d]", FCount, 
      ZCount, UCount);

  if ( !C->pZipFN )
  {
    /* Something screwed up, we don't have a filename */
    Notify( PF, UEN_PARMS01, "No zip filename received" );
    return CRITICAL_ERROR;
  }

  /* ---------------------------------------------------------------- */
  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "ready to setup" );
  if ( FSetUpToProcessZipFile( pG, C ) )
  {
    if ( pG->Frame.Verbose)
      Notify( PF, 0, "Using DelZip.dll version %i.%02i.%i.%i %s", DELZIPVERS / 100, DELZIPVERS % 100, REVISION, PATCHLEVEL, __DATE__ );

#ifdef USE_STRM_INPUT
    if ( pG->UseInStream )
      MemExtract( pG );
    else
#endif
    {
      process_zipfiles( pG ); // Pass ptr to global bufs.
      if (pG->Frame.Verbose < 0)
        Notify( PF, ITRACE, "*** BACK FROM CALL TO process_zipfiles ***" );
    }

    if ( pG->Frame.Verbose)  
    {
      Notify( PF, IMSG, "Files acted on = %d", pG->files_acted_on );
    }
  }
  FilesActedOn = pG->files_acted_on;
  inflate_free( pG );
  TakeDownFromProcessZipFile( pG ); 

  if (pG->Frame.Verbose)
    GiveTime(pG);
                 
  if ( pG->Frame.Abort_Flag )
  {
    if ( pG->Frame.Abort_Flag & (GA_EXCEPT | GA_EXCEPT2))
      return CRITICAL_CALLBACK;
    if ( pG->Frame.Abort_Flag & GA_ABORT)
      return CRITICAL_ABORT;
    if ( pG->Frame.Abort_Flag & GA_CANCEL)
      return CRITICAL_CANCELLED;
  }
  return FilesActedOn;
}

/* =========================================================================== */
bool FSetUpToProcessZipFile( struct UGlobals * pG, UnZipParms * C )
{
  char * ExtDir, *tp;
  int len;

  pG->qflag = C->fQuiet; // quiet flag
  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "FSetUpToProcessZipFile" );

  /* These flags all have a fixed value in this version. */
  pG->extract_flag = 1;
  pG->C_flag = 1;     /* if true, match filenames case-insensitively */
  pG->tflag = C->fTest;     /* if true, test zipfile */
  pG->T_flag = 1;     /* -T: timestamps (unzip) or dec. time fmt (zipinfo) */

  // set options from caller
  pG->create_dirs = C->fDirectories; // used by main(), mapname(), checkdir()
  pG->dflag = C->fDirectories; // "recreate dir structure"
  pG->jflag = !( pG->dflag ); // "junk pathnames"

  pG->aflag = C->fConvert; // do ASCII/EBCDIC or EOL conversions
  if ( C->fHandle == 0 ) // if we don't have a window handle, then
    pG->qflag = true; // we need to be quiet (no dialog boxes)

  pG->uflag = C->fUpdate; // "Update" - extract only newer files & brand new files
  pG->fflag = C->fFreshen; // "freshen" (extract only newer files)

  if ( C->fOverwrite )
    pG->overwrite_all = true; // Don't ask, always overwrite else Don't overwrite; skip that file.

  pG->filespecs = C->fArgc; // number of fspecs

  pG->local_hdr_sig[0] = pG->central_hdr_sig[0] = pG->end_central_sig[0] = '\120'; // 'P'

  pG->zipfn = pG->ZipFNbuf;
  lstrcpy( pG->zipfn, C->pZipFN );

#ifdef CRYPT
  /* IMPORTANT! For ZIPDLL, the password is malloc'd, and then pointed-to
  * by the global "key",  However, in UNZDLL, this is done:
  * - "key" and "pG->key" must remain NULL
  * - pG->pwdarg must point to the password passed-in, or else must be NULL
  * - pG->P_flag must be set to true if a password was passed-in */

  /* if no password, we will prompt user later (only if encrypted file found) */
  if ( C->pZipPassword && lstrlen( C->pZipPassword ) > 0 )
  {
    /* allocate memory for the password, and point the * global password pointer to it */
    if ( ( pG->pwdarg = (char *) MALLOC( PWLEN + 1 ) ) == NULL )
      return 0;

    lstrcpy( pG->pwdarg, C->pZipPassword ); // copy password to global buf
    pG->P_flag = true;
    /* command line password given */
  }    
  pG->PwdReqCount = C->fPwdReqCount & 0x0F; 
#endif

#ifdef USE_STRM_INPUT
  if ( !C->fUseInStream )
  {
    if ( stat( pG->zipfn, & pG->statbuf ) || ( pG->statbuf.st_mode & S_IFMT ) == S_IFDIR )
      lstrcat( pG->zipfn, ZSUFX );
    if ( stat( pG->zipfn, & pG->statbuf ) )
    {
      Notify( PF, IERROR, " can't find zipfile [ %s ]", pG->zipfn );
      return false;
    }
    else
      pG->ziplen = pG->statbuf.st_size;
  }
#else
  if ( stat( pG->zipfn, & pG->statbuf ) || ( pG->statbuf.st_mode & S_IFMT ) == S_IFDIR )
    lstrcat( pG->zipfn, ZSUFX );
  if ( stat( pG->zipfn, & pG->statbuf ) )
  {
    Notify( PF, IERROR, " can't find zipfile [ %s ]", pG->zipfn );
    return false;
  }
  else
    pG->ziplen = pG->statbuf.st_size;
#endif

  if ( !C->fArgc )
    pG->process_all_files = true; // Skip fspec matching for speed.
  else
  {
    // Just copy the pointer to the FileData array.
    pG->pfnames = (UnzFileData (*)[])C->fUFDS;
  }

  if (pG->Frame.Verbose)
    GiveTime(pG);

  //    pG->ExtractDir = ( ( DCL2 * )  C ) ->fExtractDir;   // v1.6024
  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "argc = %d, process_all_files = %d", C->fArgc, pG->process_all_files   );

  /*---------------------------------------------------------------------------
  *     Ok, we have everything we need to get started.
  *---------------------------------------------------------------------------*/
  if ((pG->outbuf = (uch *)MALLOC( OUTBUFSIZ + 1 )) == NULL)
  {
      Notify( PF, IERROR | UEN_MEM01, " out of memory");
      return false;
  }                    
  if ((pG->inbuf = (uch *)MALLOC( INBUFSIZ + 4 )) == NULL)
  {
      Notify( PF, IERROR | UEN_MEM03, " out of memory");
      FREE(pG->outbuf);
      pG->outbuf = NULL;
      return false;
  }
    pG->rootlen = 0;
    * pG->buildpathHPFS = 0;
    * pG->buildpathFAT = 0;
    * pG->ExtractPath = 0;
    pG->ExtractPathEnd = pG->ExtractPath;
    
  ExtDir = C->fExtractDir; // v1.6024
  // RP allow relative extract path
  if ( ExtDir && * ExtDir )
  {
    lstrcpy(pG->TempPath, ExtDir);
    ExtDir = pG->TempPath;
    len = lstrlen( ExtDir );

    if ( len && ExtDir[len - 1] != (char)'\\' && ExtDir[len - 1] != (char)':' )
    {
      ExtDir[len] = '\\';
      ExtDir[++len] = 0;
    }
  }
  else
    ExtDir = ".\\";     // use current
  if (!GetFullPathName(ExtDir, MAX_PATH, pG->ExtractPath, &tp))
    return false;

  len = lstrlen( pG->ExtractPath );
  pG->ExtractPathEnd = pG->ExtractPath + len;
  if ( len > ( MAX_PATH - 20 ) )
    return false;

  pG->hold = & pG->inbuf[INBUFSIZ];
  /* to check for boundary-spanning signatures */

#ifdef USE_STRM_INPUT
  if ( /*C->fVersion >= 160 &&*/ C->fUseInStream )
  {
    pG->UseInStream = C->fUseInStream;
    pG->InStream = C->fInStream;
    pG->InStreamSize = C->fInStreamSize;
  }
#endif
#ifdef USE_STRM_OUTPUT
  if (/* C->fVersion >= 160 &&*/ C->fUseOutStream )
  {
    pG->redirect_data = true;
    pG->buffer_size = C->fOutStreamSize;
    pG->redirect_buffer = (unsigned char *) C->fOutStream;
#ifdef USE_STRM_INPUT
    if ( pG->UseInStream )
    {
      pG->redirect_pointer = pG->outbuf; // Circular buffer inside DLL
      pG->redirect_size = OUTBUFSIZ;
    }
    else
    {
#endif
      pG->redirect_pointer = pG->redirect_buffer;
      pG->redirect_size = C->fOutStreamSize;
#ifdef USE_STRM_INPUT
    }
#endif
    if ( !pG->redirect_buffer )
      return false;
  }
#endif
  return true;
  /* set up was OK */
}


/* ============================================================ */
void TakeDownFromProcessZipFile( struct UGlobals * pG )
{
  int i;
  chdr_info *pInfo = pG->info;
  // free any filenames not yet freed
  for (i = 0; i < DIR_BLKSIZ; i++)
  {
    char *p = pInfo->filename;
    if ( p )
    {
      pInfo->filename = NULL;
      FREE(p);
    }
    pInfo++;
  }
  if ( pG->hFileDat )
  {
    if ( pG->FileDat )
      GlobalUnlock( pG->hFileDat );
    GLOBALFREE( pG->hFileDat );
  }

  if ( pG->inbuf )
  {
    FREE(pG->inbuf);
    pG->inbuf = NULL;
  }
  if ( pG->outbuf )
  {
    FREE(pG->outbuf);
    pG->outbuf = NULL;
  }
  if ( pG->key ) // RCV 1.608 Added
    FREE( pG->key );
}

/* ===================================================================== */
void MsgBox( struct UGlobals * pG )
{
  char ewetmp[2048];
  HWND wHandle = pG->Frame.global_handle;

  /* Did the user pass us a good window handle? if not, we can't pop-up a box. */
  if ( !wHandle )
    wHandle = GetDesktopWindow(); // v1.6021
  /* bring up a dialog box */
  lstrcpy( ewetmp, "Msg From UNZIP DLL: " );
  strncat( ewetmp, pG->ewemsg, 2027 );
  MessageBox( wHandle, ewetmp, "Message From UNZIP DLL", MB_OK );
}



/* ===========================================================================
* Custom version of ziperr as used by InfoZip's UNZIP program. c :: Error code from the UEN_ class - UnzErr.h */
void UnzErr( struct UGlobals * pG, int c )
{
  char errmsg[256];
  int oldC = ( c & 0xFF0000 ) >> 16;

  if ( pG->user_notified_of_abort )
    return;
  pG->user_notified_of_abort = 1;

  pG->global_error_code = oldC;
  /* last error code */

  if ( oldC == 0x7F )
    lstrcpyn( errmsg, pG->ewemsg, 256 ); // User defined message (NOT present in errors[]! )
  else
    if ( c == UEN_NAME01 )
      sprintf( errmsg, uerrors[oldC], pG->zipfn );
    else
      lstrcpy( errmsg, uerrors[oldC] );

  if ( pG->dll_handles_errors )
  {
    /* I'm passing the error via the callback just to get it logged in
    * the status box - I'm sending it in with a 0 error code to avoid
    * a dialog box from the application program. */
//    User(PF, zacMessage, 0, 0, errmsg );    
    Notify(PF, IBAD, errmsg);
//    _CB_.Arg1 = 0;    // error
//    _CB_.MsgP = errmsg;
//    User_CB(PF, zacMessage);
    sprintf( pG->ewemsg, "%s   code=%d", errmsg, c );
    MsgBox( pG );
  }
  else
  {                                       
    Notify(PF, IBAD | c, errmsg);
//    User(PF, zacMessage, c, 0, errmsg );
//    _CB_.Arg1 = c;    // error
//    _CB_.MsgP = errmsg;
//    User_CB(PF, zacMessage);
  }
  /* Only application program handles errors. */
}

/* Replacement for the EXIT macro, so application program will get an error and won't be aborted v1.6021. */
void EXIT(struct UGlobals *pG, int x )
{
//  struct UGlobals * pG = GetGlobalPointer();

  UnzErr( pG, x );
  RaiseException( x, 0, 0, NULL );
}

/* static int x_filter( EXCEPTION_POINTERS *xp )
{
  int rc;
  EXCEPTION_RECORD *xr = xp->ExceptionRecord;
//CONTEXT          *xc = xp->ContextRecord;
 
  switch( xr->ExceptionCode )
  {
    case UEN_READ01: rc = EXCEPTION_EXECUTE_HANDLER; break;
 
    default:                // give up rc = EXCEPTION_CONTINUE_SEARCH;
  };
  return rc;
} */



static void GiveTime( struct UGlobals * pG )
{
  SYSTEMTIME SystemT;

  if ( !pG->Frame.Verbose )
    return;
  GetSystemTime( & SystemT );
  Notify( PF, 0, "Time Hour %d, min %d, sec %d msec %d", SystemT.wHour, SystemT.wMinute, SystemT.wSecond,
          SystemT.wMilliseconds );
}
 
/* ------------------------------------------------------------------- */
 
