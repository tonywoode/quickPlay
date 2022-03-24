#include <windows.h>
#include "Common.h"
#pragma hdrstop
#include "ZipErr.h" 
#include "Zip.h"
#include "enter.h"

/* DLLmain.c * Copyright (C) 1997 Mike White and Eric W. Engler
* Permission is granted to any individual or institution to use, copy, or
* redistribute this software so long as all of the original files are included,
* that it is not sold for profit, and that this copyright notice is retained.
* This version modified by Chris Vleghert BCB/Delphi Zip.
** distributed under LGPL license
** see license.txt for details
1.73 12 July 2003 RP encryption
1.73.2.6 21 September 2003 trap exceptions in callbacks */
//#include "ZGlobals.h"
//#include "crypt.h"
//#include <process.h>
#include <signal.h>
#include <stdarg.h>
#include <direct.h>

//#include "WizZip.h"
#include "version.h"
//#include "ttyio.h"

extern int ZipProcess( struct ZGlobals * pG );
extern int ZipSelect( struct ZGlobals * pG, const ZipParms * C );

static int ZipSetParam( ZipParms * C, struct ZGlobals * pG );
static long ZipDllExec2( ZipParms * C, struct ZGlobals * pG );
static void GiveTime( struct ZGlobals * pG );
static void GiveGlobals( struct ZGlobals * pG );
/*
#define CRITICAL_ABORT      - 1
#define CRITICAL_ABORT2     - 2
#define CRITICAL_REENTER    - 3
#define CRITICAL_CANCELLED  - 4
#define CRITICAL_MEMORY     - 5
#define CRITICAL_STRUCT     - 6
#define CRITICAL_ERROR      - 7
#define CRITICAL_CALLBACK   - 8
  */        

 
// Add, update, freshen, move, or delete zip entries in a zip file. SEE THE
//   FILE "SWITCHES.TXT" FOR MORE INFO. ON PROCESSING
long WINAPI DZ_ZipExec( ZipParms * C )
{
//  int Error = 0;
  struct ZGlobals * pG;
  long RetVal;

  if (!C)
    return -9;
  pG = Create_ZGlobals( C );
  if (!pG)
    return CRITICAL_MEMORY;  
  _CB_.Arg1 = ((unsigned) pG) >> 2;
  Set_Oper(PF, ZIPOPER);
  User_CB(PF, zacKey);
  QueryINI((Frames *)pG, true);

  RetVal = ZipDllExec2( C, pG );

  if ( pG->Frame.Verbose )
    GiveTime( pG );
  if ( pG->Frame.Verbose < 0 )
    Notify( PF, IDIAG, "RetVal = %d ", RetVal );
  Set_Oper(PF, 0);
  _CB_.Arg1 = 0;
  User_CB(PF, zacKey);

  Destroy_ZGlobals(pG);
  return RetVal;
}


// New entry function for components version >= 1.5
long ZipDllExec2( ZipParms * C, struct ZGlobals * pG )
{ 
  char *cd;
  char  *tp;
  int r, len;

  if ( C->fSeven != 7 )
  { // This Seven is at another place as in ZCL!
	Notify( PF, ZEN_PARMS02, "Structure size mismatch" );

    return CRITICAL_STRUCT;
  }
                           
  if (pG->Frame.Verbose < 0)
    Notify( PF, 0,  "trace is on, function=ZipDllExec2 [%d %d %d]", FCount, ZCount, UCount);

  cd = (char *)C->fGRootDir;
  if ( cd && cd)
  {
    len = lstrlen(cd);
    if (len > MAX_PATH -20)
    {
	  Notify( PF, ZEN_MEM36, "CurrentDir allocation error" );

      return CRITICAL_ERROR;
    }
    if (len > 1 && cd[len-1] != (char)'\\' && cd[len -1] != (char)':')
    {
      cd = pG->ewetmp;
      lstrcpy(cd, C->fGRootDir);
      cd[len++] = '\\';
      cd[len] = 0;
    }
  }
  else
    cd = ".\\";    // use current
  if (!GetFullPathName(cd, MAX_PATH, pG->file_outbuf, &tp))
  {
	Notify( PF, ZEN_MEM36, "CurrentDir allocation error 2" );

    return CRITICAL_ERROR;
  }

  pG->OCDlength = lstrlen( pG->file_outbuf );
  if ( ( pG->OrigCurrentDir = ( char * ) MALLOC( pG->OCDlength + 2 ) ) == NULL )
  { // RP allow space for '\'
	Notify( PF, ZEN_MEM36, "CurrentDir allocation error 3" );
    return CRITICAL_MEMORY;
  }

  lstrcpy( pG->OrigCurrentDir, pG->file_outbuf );

  pG->zcomment = C->fArchComment;
  if ( C->fArchComment )
    pG->zcomlen = lstrlen( C->fArchComment );
  if ( C->fArchiveFilesOnly )
    pG->ArchiveFiles = 1;
  if ( C->fResetArchiveBit )
    pG->ResetArchiveBit = 1;
  if ( C->fHowToMove )
    pG->HowToMove = true;

  r = ZipSetParam( C, pG );
  if ( r > 0 )
    return -12; // password error (<160)
  if ( r < 0 )
    return r; // critical error

  if ( C->fTempPath )
  { // Temporary path -b
    pG->tempdir = 1;
    if ( ( pG->tempath = ( char * ) MALLOC( lstrlen( C->fTempPath ) + 1 ) ) == NULL )
      return CRITICAL_MEMORY;
    lstrcpy( pG->tempath, C->fTempPath );
  }
  // in this state, we need the name of the zip file
  if ( ( pG->zipfile = ziptyp( C->pZipFN, pG ) ) == NULL )
    return CRITICAL_MEMORY;
  pG->WantedCodePage = C->fWantedCodePage;
  pG->WantedOS = C->fWantedOS; // v1.74
  if ( C->fVerboseEnabled )
  {
    Notify( PF, IDIAG, "Using ZIPDLL.dll version %i.%02i.%i.%i %s", DELZIPVERS / 100, DELZIPVERS % 100,
            REVISION, PATCHLEVEL, __DATE__ );
    Notify( PF, IDIAG, "root = %s", pG->OrigCurrentDir);
  }
  if ( pG->Frame.Verbose )
    GiveTime( pG );
  if ( pG->Frame.Verbose < 0 )
    GiveGlobals( pG );
//Notify(PF, IBAD | IERROR, "a quick test");
#ifdef USE_STRM_INPUT
  if (C->fUseInStream )
  {
    pG->UseOutStream = C->fUseOutStream; // In memory compression.
    pG->OutStream = C->fOutStream;
    pG->OutStreamSize = C->fOutStreamSize;
    pG->UseInStream = C->fUseInStream;
    pG->InStream = C->fInStream;
    pG->InStreamSize = C->fInStreamSize;
    pG->StrFileAttr = C->fStrFileAttr;
    pG->StrFileDate = C->fStrFileDate;
    if ( pG->UseOutStream )
    { // In-memory compression.
      // Pass total number of files always 1
//      User(PF, zacCount, 0, 1, NULL);
      _CB_.Arg1 = 1;
      User_CB(PF, zacCount);
      // keep debugging happy
      pG->isize = pG->InStreamSize;

      // Pass total filesize.
//      User(PF, zacSize, 0, pG->InStreamSize, NULL);  
      _CB_.FileSize.i64 = pG->InStreamSize;
      User_CB(PF, zacSize);
      pG->OutStreamSize =
        memcompress( ( char * ) pG->OutStream, pG->OutStreamSize, ( char * ) pG->InStream, pG->InStreamSize, pG );
      pG->files_acted_on++;
//      User(PF, zacEndOfBatch, 0, 0, NULL); // done with this in-memory compression.
      _CB_.Written.i64 = pG->BytesWritten;
      User_CB(PF, zacEndOfBatch); // done with in-memory compression
    }
  }

  if (!( C->fUseInStream && pG->UseOutStream))
  {  
    if ( !ZipSelect( pG, C ) )
    {
      if ( ZipProcess( pG ) != 0 )
        pG->files_acted_on = 0;
      if ( pG->BatchStarted )
      {
//        User(PF, zacEndOfBatch, 0, 0, NULL);//, pG ); // done with a batch of files
        _CB_.Written.i64 = pG->BytesWritten;
        User_CB(PF, zacEndOfBatch); // done with a batch of files
      }
      diag( "*** BACK FROM CALL TO ZipProcess ***", pG );
    }
    if ( C->fVerboseEnabled )
      Notify( PF, 0, "Files acted on = %d", pG->files_acted_on );
  }   
#else
  if ( !ZipSelect( pG, C ) )
  {
    if (pG->Frame.Abort_Flag || ZipProcess( pG ) != 0 )
      pG->files_acted_on = 0;
    if ( pG->BatchStarted )
    {
//      User(PF, zacEndOfBatch, 0, 0, NULL); // done with a batch of files
       _CB_.Written = pG->BytesWritten;
       User_CB(PF, zacEndOfBatch); // done with a batch of files
    }
    diag( "*** BACK FROM CALL TO ZipProcess ***", pG );
  }
  if ( C->fVerbose )
    Notify( PF, 0, "Files acted on = %d", pG->files_acted_on );
#endif
  if ( pG->OrigCurrentDir )
    FREE( pG->OrigCurrentDir );
#ifdef USE_STRM_INPUT
  if ( pG->UseInStream && pG->UseOutStream )
    C->fOutStreamSize = pG->OutStreamSize;
#endif
  if ( pG->Frame.Abort_Flag )
  {
    if ( pG->Frame.Abort_Flag & (GA_EXCEPT | GA_EXCEPT2))
      return CRITICAL_CALLBACK;
    if ( pG->Frame.Abort_Flag & GA_ABORT)
      return CRITICAL_ABORT;
    if ( pG->Frame.Abort_Flag & GA_CANCEL)
      return CRITICAL_CANCELLED;
  }
  return pG->files_acted_on;
}

int ZipSetParam( ZipParms * C, struct ZGlobals * pG )
{
  int ii;
//  if ( C->fQuiet || !C->fHandle )
//  { // quiet operation -q
//    pG->noisy = 0; // shut us up!
//    pG->dll_handles_errors = 0; // All error msgs passed to caller via callback function
//  }
//
//  if ( C->fVerboseEnabled || C->fTraceEnabled ) // Frame.Verbose messages -v
//  {
//    pG->noisy = 1;
//    pG->Frame.Verbose |= C->fTraceEnabled ? -1 : 1;
//  }
//  if ( pG->Frame.Verbose )
//    diag( "trace is on in DelZip.DLL - ZIP", pG );
  if ( C->pZipFN == NULL )
  { // Something screwed up, we don't have a filename
    Notify( PF, ZEN_PARMS01, "No zip filename received" );
    return CRITICAL_ERROR;
  }

  if ( C->fVersion != DELZIPVERS )
  { // see version.h
    wsprintf( pG->ewemsg, "Warning: ZIPDLL.dll version %i.%02i.%i.%i %s is %s", DELZIPVERS / 100, DELZIPVERS % 100, REVISION,
              PATCHLEVEL, __DATE__, ( C->fVersion < DELZIPVERS ) ? "newer" : "older\nPlease get an update" );

    // This message won't appear if user did pass us a zero Window handle.
    if ( !C->fQuiet )
      msgbox( pG->ewemsg, pG ); // Only a warning

    // Also report this fact via the C++Builder/Delphi callback.
    Notify( PF, IWARNING, pG->ewemsg );
  }

  ii = C->fLevel;
  if ( ii < 0 )
    ii = 0;
  else
    if ( ii > 9 )
      ii = 9;
//  pG->method = ii ? DEFLATE : STORE;
  pG->level = ii;
  if ( pG->Frame.Verbose ) // < 0)
  {
    Notify( PF, IDIAG, "setting compression level to %d", pG->level );
  }

  pG->action = C->fDeleteEntries ? PURGE : ADD;
  if ( C->fFreshen ) // Freshen zip file--overwrite only -f
  {
    if ( pG->action != ADD )
    {
      Notify( PF, ZEN_PARMS06, "invalid options" );
      return CRITICAL_ERROR;
    }
    pG->action = FRESHEN;
  }
  if ( C->fUpdate ) // Update zip file--overwrite only if newer -u
  {
    if ( pG->action != ADD )
    {
      Notify( PF, ZEN_PARMS08, "invalid options" );
      return CRITICAL_ERROR;
    }
    pG->action = UPDATE;
  }
  // build the conventional cmd line switches
  if ( C->fNoDirEntries ) // Do not add directory entries -D
    pG->dirnames = 0;
  if ( C->fGrow ) // Allow appending to a zip file -g Normally TRUE
    pG->AllowGrow = 255;
  if ( C->fJunkDir ) // Junk directory names -j
    pG->pathput = 0;
  if ( C->fJunkSFX ) // Junk sfx prefix
    pG->junk_sfx = 1;
  if ( C->fForce ) // Make entries using DOS names (k for Katz) -k
    pG->dosify = 1;
  if ( C->fCRLF_LF ) // Translate end-of-line -l
    pG->translate_eol++;
  if ( C->fMove ) // Delete files added or updated in zip file -m
    pG->dispose = 1;
  if ( C->fLatestTime ) // Set zip file time to time of latest file in it -o
    pG->latest = 1;
 
  // Not a command line option but we set the global var directly
  if ( C->fNoRecurseFiles == 2 )
    pG->norecursefiles = 1;
  if ( C->fSystem ) // include system and hidden files -S
    pG->hidden_files = 1;
  if ( C->fUseDate )
  { // Exclude files earlier than specified date -t
    pG->before = C->fDate;
    // Date must follow the -t switch
  }

  if ( C->fVolume ) // Include volume label -$
    pG->volume_label = 1;
  if ( C->fExtra ) // Include extra attributes -X
    pG->extra_fields = 0;
  pG->special = C->pSuffix; // specify the extensions that will not be compressed
  // Pass the excluded file spec. list.
  pG->pcount =  C->fTotExFileSpecs;
  pG->ExternalList = ( struct plist * ) ( C->fExFiles );

  return 0;
}
 
// ziperr() is the preferred error msg function!!!
void msgbox( char * msg, struct ZGlobals * pG )
{
  // Did user pass us a window handle?
  if ( pG->Frame.global_handle )
  { // RCV changed: was exit if no handle;
    lstrcpy( pG->ewetmp, "Msg From DELZIP DLL: " );
    lstrcat( pG->ewetmp, msg );
    MessageBox( pG->Frame.global_handle, pG->ewetmp, "Msg From DELZIP DLL (zip)", MB_OK );
  }
}


static void GiveTime( struct ZGlobals * pG )
{
  SYSTEMTIME SystemT;

  if ( !pG->Frame.Verbose )
    return;
  GetSystemTime( & SystemT );
  Notify( PF, IDIAG, "Time Hour %d, min %d, sec %d msec %d", SystemT.wHour, SystemT.wMinute, SystemT.wSecond,
          SystemT.wMilliseconds );
}

char w( bool v )
{
  if ( v )
    return '+';
  return '-';
}

static void GiveGlobals( struct ZGlobals * pG )
{
  if ( !pG->Frame.Verbose )
    return;

  Notify( PF, IDIAG, "g%c j%c J%c k%c m%c o%c S%c t%c", w( pG->AllowGrow ), w( pG->pathput ), w( pG->junk_sfx ), w( pG->dosify ), w( pG->dispose ), w( pG->latest ),
          w( pG->hidden_files ), w( pG->before ) );
}


// Issue a message for an error, clean up files and memory, and exit. return
//   value is the the same as 'c'. c :: Error code from the ZEN_ class.
int ziperror( int c, struct ZGlobals * pG )
{
  char errmsg[ERRORLENGTH];
  int i;

  if ( pG->user_notified_of_abort )
    return c;
  pG->user_notified_of_abort = 1;

  pG->global_error_code = c; // Last error code
  pG->Frame.Abort_Flag |= GA_ERROR; // RCV Added; if we are here it's
  ///* serious we can't continue.
  if ( c != ZEN_OK )
  {
    i = ( c & 0xFF0000 ) >> 16;
    if ( c == ZEN_PW_ERROR )
      i = 1;
    else
      if ( c == ZEN_PW_CANCEL || c == ZEN_PW_CANCELALL )
        i = 17;
    lstrcpy( errmsg, errors[i] );
  }

  if ( pG->dll_handles_errors )
  {
    // I'm passing the error via the callback just to get it logged in the
    //   status box - I'm sending it in with a 0 error code to avoid a dialog
    //   box from the application program.
//    User(PF, zacMessage, ( pG->Frame.global_handle ) ? 0 : c, 0, errmsg);
//    _CB_.Arg1 = ( pG->Frame.global_handle ) ? 0 : c;    // error
//    _CB_.MsgP = errmsg;
//    User_CB(PF, zacMessage);
    Notify(PF, IBAD | (( pG->Frame.global_handle ) ? 0 : c), errmsg);
    sprintf( pG->ewemsg, "%s   code=%8.8X", errmsg, c );
    msgbox( pG->ewemsg, pG );
  }
  else
  {
    Notify(PF, IBAD | c, errmsg);
//    User(PF, zacMessage, c, 0, errmsg);//, pG ); // applic pgm handles errors (showing)
//    _CB_.Arg1 = c;    // error
//    _CB_.MsgP = errmsg;
//    User_CB(PF, zacMessage);
  }
  if ( pG->tempath != NULL )
  {
    FREE( pG->tempath );
    pG->tempath = NULL;
  }

#ifdef CRYPT
  if ( pG->user_key ) // p release user password
  {
    FREE( pG->user_key );
    pG->user_key = NULL;
  }
#endif
  return c;
}




