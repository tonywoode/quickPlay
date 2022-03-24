#include <windows.h>
#include "Common.h"
#pragma hdrstop
/* This version modified by Chris Vleghert and Eric W. Engler
 * for BCB/Delphi Zip, Jun 18, 2000.
 * RP - new GetFullPath, Jul 10, 2002.
 * RP - "fixed" dos_to_unix_time for problem with localtime Jul 10, 2002
 */

/*---------------------------------------------------------------------------
 * fileio.c
 * This file contains routines for doing direct but relatively generic input/
 * output, file-related sorts of things, plus some miscellaneous stuff.  Most
 * of the stuff has to do with opening, closing, reading and/or writing files.
 * Contains:  open_input_file()
 *            open_outfile()           (non-VMS, non-AOS/VS, non-CMS_MVS)
 *            undefer_input()
 *            defer_leftover_input()
 *            readbuf()
 *            readbyte()
 *            fillinbuf()
 *            flush()                  (non-VMS)
 *            disk_error()             (non-VMS)
 *            handler()
 *            dos_to_unix_time()       (non-VMS, non-OS/2, non-VM/CMS, non-MVS)
 *            check_for_newer()        (non-VMS, non-OS/2, non-VM/CMS, non-MVS)
 *            do_string()
 *            makeword()
 *            makelong()
 *            str2iso()
 *            str2oem()
 *            zstrnicmp()
 *            ExtASCII2Native()
 *            WriteToMemory()
 *            ShowSysMsg()
 *---------------------------------------------------------------------------
 */

#define FILEIO_C

//#include "WizUnZip.h"
#include "UnZip.h"
#include "ucrypt.h"
//#include "ttyio.h"
#include "WinUser.h"
#include <shlobj.h>

/* * Note: Under Windows, the maximum size of the buffer that can be used
* with any of the *printf calls is 16,384, so win_fprintf was used to
* feed the printf clone no more than 16K chunks at a time. This should
* be valid for anything up to 64K (and probably beyond, assuming your * buffers are that big.) */
#ifdef USE_FWRITE
  #  define WriteError( buf, len, strm ) \
       ( (extent)fwrite( (char *)(buf), 1, (extent)(len), strm ) != (extent)(len) )
#else
  #  define WriteError( buf, len, strm ) \
       ( (extent)write( fileno( strm ), (char *)(buf), (extent)(len) ) != (extent)(len) )
#endif

static int disk_error( struct UGlobals * pG );

//#ifdef USE_STRM_OUTPUT
static WriteToMemory( struct UGlobals * pG, uch * rawbuf, ulg size );

//#endif

/* ===========================================================================
*                                       Function open_input_file()
*
* Open the zipfile for reading and in BINARY mode to prevent CR/LF
* translation, which would corrupt the bitstreams.
* return 1 if open failed else 0 */
int open_input_file( struct UGlobals * pG )
{
  if (pG->Frame.Verbose)// < 0)
	Notify( PF, ITRACE, "open_input_file; fname=%s", pG->zipfn   );
//  pG->zipfdz = CreateFile( pG->zipfn, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING,
//                           FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS, NULL );
  pG->zipfdz = OpenRead(PF, pG->zipfn, FILE_ATTRIBUTE_NORMAL);// | FILE_FLAG_RANDOM_ACCESS);
//pG->zipfdz = INVALID_HANDLE_VALUE;
  // pG->zipfd = open ( pG->zipfn, O_RDONLY | O_BINARY );
  // if ( pG->zipfd == -1 )
  if ( pG->zipfdz == INVALID_HANDLE_VALUE ) //< 0 )
  {
    if (pG->Frame.Verbose < 0)
	  Notify( PF, ITRACE | IBAD, "could not open: %s [%x]", pG->zipfn, 
        GetLastError());

	//    pG->zipfdz = 0; /* RCV added 29-1-99 */
    UnzErr( pG, UEN_NAME01 );
    return 1;
  }

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "zip file %s opened OK", pG->zipfn   );
  return 0;
}

void ShowSysMsg( struct UGlobals * pG, DWORD Error )
{
  LPVOID lpMsgBuf;

  FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, Error, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),
                 ( LPTSTR ) & lpMsgBuf, 0, NULL );
  if (pG->Frame.Verbose )
    Notify( PF, 0, ( char * ) lpMsgBuf   );

  // Free the buffer.
  LocalFree( lpMsgBuf );
}

/* ===========================================================================
*                  Function open_outfile() *
* Return 0 on success and leave pG->outfile open.
* Return 1 if failed. */
int open_outfile( struct UGlobals * pG )
{
#       ifdef USE_STRM_OUTPUT
  if ( pG->redirect_data )
    return ( pG->redirect_size != pG->lrec.ucsize );
#       endif

  if ( !stat( pG->filename, & pG->statbuf ) )
  {
    if (pG->Frame.Verbose  )
      Notify( PF, IVERBOSE, "open_outfile:  stat(%s) returns file exists", pG->filename   );
    if ( !( pG->statbuf.st_mode & S_IWRITE ) )
    {
      if (pG->Frame.Verbose  )
        Notify( PF, IVERBOSE,  "open_outfile:  existing file %s is read-only", pG->filename   );
      chmod( pG->filename, S_IREAD | S_IWRITE );
    }
    if ( !DeleteFile( pG->filename ) )
    {
      if (pG->Frame.Verbose  )
        Notify( PF, IVERBOSE, "DeleteFile( %s ) failed:", pG->filename   );
      ShowSysMsg( pG, GetLastError() );
      return 1;
    }
    SHChangeNotify( SHCNE_DELETE, SHCNF_PATH, GetFullPath( pG, pG->filename ), NULL );
    if ( pG->Frame.Verbose) //vflag )
      Notify( PF, 0,  "Deleted pre-existing file %s", pG->filename );
  }
#  ifdef NOVELL_BUG_FAILSAFE
  if ( pG->dne && ( ( pG->outfile = fopen( pG->filename, FOPR ) ) != NULL ) )
  {

    Notify( PF, 0,  "File %s open failed due to Novell Bug", pG->filename );
    fclose( pG->outfile );
    return 1;
    /* with "./" fix in checkdir(), should never reach here */
  }
#  endif
  if ( ( pG->outfile = fopen( pG->filename, FOPW ) ) == NULL )
  {
    Notify( PF, IERROR | IBAD,  "Error opening file %s for write [%X]",
        pG->filename, errno);
    return 1;
  }
  //EWE SHChangeNotify( SHCNE_CREATE, SHCNF_PATH, GetFullPath( pG, pG->filename ), NULL );
  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "open_outfile:  fopen(%s) for writing succeeded", pG->filename  );
#  ifdef USE_FWRITE
  setbuf( pG->outfile, NULL );
  /* make output unbuffered */
#  endif
  return 0;
}

/* end function open_outfile() */


/* ===========================================================================
*                  function undefer_input()
* These functions allow NEXTBYTE to function without needing two bounds
* checks.  Call defer_leftover_input() if you ever have filled pG->inbuf
* by some means other than readbyte(), and you then want to start using
* NEXTBYTE.  When going back to processing bytes without NEXTBYTE, call
* undefer_input().  For example, extract_or_test_member brackets its
* central section that does the decompression with these two functions.
* If you need to check the number of bytes remaining in the current
* file while using NEXTBYTE, check (pG->csize + pG->incnt), not pG->csize. */
void undefer_input( struct UGlobals * pG )
{
  if ( pG->incnt > 0 )
    pG->csize += pG->incnt;
  if ( pG->incnt_leftover > 0 )
  {
    /* We know that "(pG->csize < MAXINT)" so we can cast pG->csize to int:
    * This condition was checked when pG->incnt_leftover was set > 0 in
    * defer_leftover_input(), and it is NOT allowed to touch pG->csize
    * before calling undefer_input() when (pG->incnt_leftover > 0)
    * (single exception: see read_byte()'s  "pG->csize <= 0" handling) !! */
    pG->incnt = pG->incnt_leftover + ( int )pG->csize;
    pG->inptr = pG->inptr_leftover - ( int )pG->csize;
    pG->incnt_leftover = 0;
  }
  else
    if ( pG->incnt < 0 )
      pG->incnt = 0;
}

/* ===========================================================================
*              function defer_leftover_input() */
void defer_leftover_input( struct UGlobals * pG )
{
//  if ( ( long )pG->incnt > pG->csize )
  if ( ( unsigned long )pG->incnt > (unsigned long)pG->csize )
  {
    /* (pG->csize < MAXINT), we can safely cast it to int !! */
    if ( pG->csize < 0L )
      pG->csize = 0L;
    pG->inptr_leftover = pG->inptr + ( int )pG->csize;
    pG->incnt_leftover = pG->incnt - ( int )pG->csize;
    pG->incnt = ( int )pG->csize;
  }
  else
    pG->incnt_leftover = 0;
  pG->csize -= pG->incnt;
}


/* ===========================================================================
*                      Function readbuf()
* Return number of bytes read into buf. */
unsigned readbuf( struct UGlobals * pG, char * buf, register unsigned size )
{
  register unsigned count;
  unsigned n;

  n = size;
  while ( size )
  {
    if ( pG->incnt <= 0 )
    {
      if ( ( pG->incnt = vclRead( pG, ( char * ) pG->inbuf, INBUFSIZ ) ) == 0 )
        return ( n - size );
      else
        if ( pG->incnt < 0 )
        {
          Notify( PF, 0, "Error reading ZIP file" );
          return 0;
          /* discard some data - better than lock-up */
        }
      /* buffer ALWAYS starts on a block boundary: */
      pG->cur_zipfile_bufstart += INBUFSIZ;
      pG->inptr = pG->inbuf;
    }
    count = MIN( size, ( unsigned )pG->incnt );
    memcpy( buf, pG->inptr, count );
    buf += count;
    pG->inptr += count;
    pG->incnt -= count;
    size -= count;
  }
  //Trace( (pG, "returning %u from readbuf", n) );
  return n;
}
/* end function readbuf() */


/* ===========================================================================
*                      Function readbyte()
* Refill inbuf and return a byte if available, else EOF. */
int readbyte( struct UGlobals * pG )
{
  if ( pG->mem_mode )
    return EOF;
//  if ( pG->csize <= 0 )
  if ( pG->csize <= 0 && pG->csize > -10 )
  {
    pG->csize = -1;//--;
    /* for tests done after exploding */
    pG->incnt = 0;
    return EOF;
  }
  if ( pG->incnt <= 0 )
  {
    if ( ( pG->incnt = vclRead( pG, ( char * ) pG->inbuf, INBUFSIZ ) ) == 0 )
    {
      pG->incnt = 0;
      /* do not allow negative value to affect stuff */
      return EOF;
    }
    else
      if ( pG->incnt < 0 )
      {
        /* "fail" (abort, retry, ...) returns this */
        Notify( PF, 0, "Error reading from ZIP file" );
        EXIT( pG, UEN_READ01 );
        /* (PK_BADERR) totally bailing; better than lock-up */
      }
    pG->cur_zipfile_bufstart += INBUFSIZ;
    /* always starts on block bndry */
    pG->inptr = pG->inbuf;
    defer_leftover_input( pG );
    /* decrements pG->csize */
  }
#ifdef CRYPT
  if ( pG->pInfo->encrypted )
  {
    uch * p;
    int n;

    /* This was previously set to decrypt one byte beyond pG->csize, when
    * incnt reached that far.  GRR said, "but it's required:  why?"  This
    * was a bug in fillinbuf() -- was it also a bug here? */
    for ( n = pG->incnt, p = pG->inptr; n--; p++ )
      *p = (uch) zdecode( *p, pG->keys );
  }
#endif /* CRYPT */
  --pG->incnt;
  return * pG->inptr++;
}

/* end function readbyte() */


/* ===========================================================================
*                     Function flush()
* cflag => always 0; 50 if write error */
int flush( struct UGlobals * pG, uch * rawbuf, ulg size, int unshrink )
{
  register uch * p, * q;
  uch * transbuf;
  //      ulg           crcwas;
  /* static int didCRlast = false;    moved to globals.h */

#ifdef USE_STRM_OUTPUT
  ulg ProgrSize = ( pG->redirect_data ) ? size % 0x8000 : size; // RCV1.6019
  if ( ProgrSize )
//    User(PF, zacProgress, 0, ProgrSize, NULL ); // bump up progress bar
  {                                  
    _CB_.Written.i64 = 0;
    _CB_.FileSize.i64 = ProgrSize;
    User_CB(PF, zacProgress);
  }
#else
  if ( size )
//    User(PF, zacProgress, 0, size, NULL );
  {                           
    _CB_.Written.i64 = 0;
    _CB_.FileSize.i64 = size;
    User_CB(PF, zacProgress);
  }
#endif
  /*---------------------------------------------------------------------------
  * Compute the CRC first; if testing or if disk is full, that's it.
  *---------------------------------------------------------------------------*/
  //crcwas = pG->crc32val;
  pG->crc32val = crc32( pG->crc32val, rawbuf, ( extent )size );
  // Trace( (pG, "fileio.c: pG->crc32val updated from: %08X to: %08X", crcwas, pG->crc32val) );

  if ( pG->tflag || !size ) /* testing or nothing to write:  all done */
    return 0;
  if ( pG->disk_full )
    return 50;
  /* disk already full:  ignore rest of file */

  /*---------------------------------------------------------------------------
  * Write the bytes rawbuf[0..size-1] to the output device, first converting
  * end-of-lines and ASCII/EBCDIC as needed.  If SMALL_MEM or MED_MEM are NOT
  * defined, outbuf is assumed to be at least as large as rawbuf and is not * necessarily checked for overflow.
  *---------------------------------------------------------------------------*/
  if ( !pG->pInfo->textmode )
  {
    /* write raw binary data */
    /* GRR:  note that for standard MS-DOS compilers, size argument to
    * fwrite() can never be more than 65534, so WriteError macro will
    * have to be rewritten if size can ever be that large.  For now,
    * never more than 32K.  Also note that write() returns an int, which
    * doesn't necessarily limit size to 32767 bytes if write() is used
    * on 16-bit systems but does make it more of a pain; however, because
    * at least MSC 5.1 has a lousy implementation of fwrite() (as does * DEC Ultrix cc), write() is used anyway. */
#ifdef USE_STRM_OUTPUT
    if ( pG->redirect_data )
      WriteToMemory( pG, rawbuf, size );
    else
#endif
      if ( !pG->cflag && WriteError( rawbuf, size, pG->outfile ) )
        return disk_error( pG );
    // else if ( pG->cflag && (*pG->message)( (void *)&G, rawbuf, size, 0) ) return 0;
  }
  else
  {
    if ( unshrink )
    {
      /* rawbuf = outbuf */
      transbuf = pG->outbuf2;
    }
    else
    {
      /* rawbuf = slide */
      transbuf = pG->outbuf;
    }
    if ( pG->newfile )
    {
      pG->didCRlast = false;
      /* no previous buffers written */
      pG->newfile = false;
    }
    p = rawbuf;
    if ( * p == LF && pG->didCRlast )
      ++p;

    /*-----------------------------------------------------------------------
    * Algorithm:  CR/LF => native; lone CR => native; lone LF => native.
    * This routine is only for non-raw-VMS, non-raw-VM/CMS files (i.e.,
    * stream-oriented files, not record-oriented).
    *-----------------------------------------------------------------------*/
    pG->didCRlast = false;
    for ( q = transbuf; p < rawbuf + ( unsigned )size; ++p )
    {
      if ( * p == CR )
      {
        /* lone CR or CR/LF: EOL either way */
        * q++ = native( CR );
        * q++ = native( LF );
        if ( p == rawbuf + ( unsigned )size - 1 ) /* last char in buffer */
          pG->didCRlast = true;
        else
          if ( p[1] == LF ) /* get rid of accompanying LF */
            ++p;
      }
      else
        if ( * p == LF )
        {
          /* lone LF */
          * q++ = native( CR );
          * q++ = native( LF );
        }
        else
          * q++ = native( * p );
    }

    /*-----------------------------------------------------------------------
    * Done translating:  write whatever we've got to file (or screen).
    *-----------------------------------------------------------------------*/
    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "p - rawbuf = %u   q-transbuf = %u   size = %lu", ( unsigned )( p - rawbuf ), ( unsigned )( q - transbuf ), size   );
    if ( q > transbuf )
#ifdef USE_STRM_OUTPUT
      if ( pG->redirect_data )
        WriteToMemory( pG, transbuf, ( unsigned )( q - transbuf ) );
      else
#endif
        if ( !pG->cflag && WriteError( transbuf, ( unsigned )( q - transbuf ), pG->outfile ) )
          return disk_error( pG );
    //  else if ( pG->cflag && (*pG->message)((void *)&G, transbuf, (ulg)(q - transbuf), 0) ) return 0;
  }
  return 0;
}
/* end function flush() */


/* ===========================================================================
*        Function disk_error() */
static int disk_error( struct UGlobals * pG )
{
  UnzErr( pG, UEN_WRITE01 );
  return PK_DISK;
  /* disk is full */
}


/* ===========================================================================
*           Function handler()
* Upon interrupt, turn on echo and exit cleanly. */

/*void handler( int signal ) { #ifdef SIGSEGV if ( signal == SIGSEGV ) { EXIT( PK_BADERR ); } #endif
/* probably ctrl-C EXIT( PK_ERR ); } */

#ifndef timezone
  #  define timezone _timezone
#endif

#define YRBASE  1970

/* ===========================================================================
*        Function dos_to_unix_time()
* only used for freshening/updating */
time_t dos_to_unix_time( unsigned ddate, unsigned dtime )
{
  time_t m_time;
  int yr, mo, dy, hh, mm, ss;
  static short yday[] =
    {
      0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
    };
  int leap;
  unsigned days;
  struct tm * lt; // RP - add

  /* dissect date */
  yr = ( ( ddate >> 9 ) & 0x7f ) + ( 1980 - YRBASE );
  mo = ( ( ddate >> 5 ) & 0x0f ) - 1;
  dy = ( ddate & 0x1f ) - 1;

  /* dissect time */
  hh = ( dtime >> 11 ) & 0x1f;
  mm = ( dtime >> 5 ) & 0x3f;
  ss = ( dtime & 0x1f ) * 2;

  /* leap = # of leap yrs from YRBASE up to but not including current year */
  leap = ( ( yr + YRBASE - 1 ) / 4 );
  /* leap year base factor */

  /* calculate days from BASE to this year and add expired days this year */
  days = ( yr * 365 ) + ( leap - 492 ) + yday[mo];

  /* if year is a leap year and month is after February, add another day */
  if ( ( mo > 1 ) && ( ( yr + YRBASE ) % 4 == 0 ) && ( ( yr + YRBASE ) != 2100 ) )
    ++days;
  /* OK through 2199 */

  /* convert date & time to seconds relative to 00:00:00, 01/01/YRBASE */
  m_time = ( time_t )( ( long )( days + dy ) * 86400L + ( long )hh * 3600L + ( long )( mm * 60 + ss ) );
  /* - 1;   MS-DOS times always rounded up to nearest even second */
  //  if (pG->Frame.Verbose < 0)
  //          Inform(NULL, ITRACE, "dos_to_unix_time:"  );
  //  if (pG->Frame.Verbose < 0)
  //          Inform(NULL, ITRACE, "  m_time before timezone = %ld", ( long )m_time  );

  /*---------------------------------------------------------------------------
  *    Adjust for local standard timezone offset.
  *-------------------------------------------------------------------------*/
  {
    TIME_ZONE_INFORMATION tzinfo;
    DWORD res = GetTimeZoneInformation( & tzinfo );

    /* account for timezone differences */
    if ( res != TIME_ZONE_ID_UNKNOWN )
      m_time += ( 60 * tzinfo.Bias );
  }

  /*---------------------------------------------------------------------------
  *    Adjust for local daylight savings (summer) time.
  *-------------------------------------------------------------------------*/
  if ( ( ddate >= ( unsigned )DOSDATE_2038_01_18 ) && ( m_time < ( time_t )0x70000000L ) )
    m_time = U_TIME_T_MAX;
  /* saturate in case of (unsigned) overflow */
  if ( m_time < ( time_t )0L ) /* a converted DOS time cannot be negative */
    m_time = S_TIME_T_MAX;
  /* -> saturate at max signed time_t value */
  //  if (localtime ((time_t *) & m_time)->tm_isdst)  // RP - replaced
  lt = localtime( ( time_t * ) & m_time ); // RP - added
  if ( lt && lt->tm_isdst ) // RP - changed
    m_time -= ( 60L * 60L );
  /* adjust for daylight savings time */
  //  if (pG->Frame.Verbose < 0)
  //          Inform( pG, ITRACE, "  m_time after DST =       %lu", ( ulg )m_time   );

  if ( ( ddate >= ( unsigned )DOSDATE_2038_01_18 ) && ( m_time < ( time_t )0x70000000L ) )
    m_time = U_TIME_T_MAX;
  /* saturate in case of (unsigned) overflow */
  if ( m_time < ( time_t )0L ) /* a converted DOS time cannot be negative */
    m_time = S_TIME_T_MAX;
  /* -> saturate at max signed time_t value */

  //  if (pG->Frame.Verbose < 0)
  //          Inform( pG, ITRACE, "  m_time returning =  %lU", ( ulg )m_time  );
  return m_time;
}
/* end function dos_to_unix_time() */

/*********************************/
/* Function NtfsFileTime2utime() */
/*********************************/
#if 0
/* scale factor and offset for conversion time_t -> FILETIME */
#define NT_QUANTA_PER_UNIX 10000000L
#define UNIX_TIME_ZERO_HI  0x019DB1DEUL
#define UNIX_TIME_ZERO_LO  0xD53E8000UL

int NtfsFileTime2utime(const FILETIME *pft, time_t *ut)
{
    unsigned __int64 NTtime;

    NTtime = ((unsigned __int64)pft->dwLowDateTime +
              ((unsigned __int64)pft->dwHighDateTime << 32));

    NTtime -= ((unsigned __int64)UNIX_TIME_ZERO_LO +
               ((unsigned __int64)UNIX_TIME_ZERO_HI << 32));
    *ut = (time_t)(NTtime / (unsigned long)NT_QUANTA_PER_UNIX);
    return TRUE;
} /* end function NtfsFileTime2utime() */
#endif

/* ===========================================================================
*       Function check_for_newer()
* Used for overwriting/freshening/updating.
* Return 1 if existing file is newer.
*
*filename :: Or equal; 0 if older; -1 if doesn't exist yet. */
int check_for_newer( struct UGlobals * pG, char * filename )
{
  time_t existing, archive;
//  time_t ut;
#ifdef USE_EF_UX_TIME
  ztimbuf z_utime;
#endif
  //Trace( (pG, "check_for_newer:  doing stat(%s)", filename) );
//    WIN32_FIND_DATA FindFileData;
//    HANDLE hFind;
//    hFind = FindFirstFile(filename, &FindFileData);
//    if (hFind == INVALID_HANDLE_VALUE)
//    {
//        unsigned err = GetLastError();
//        if (err == ERROR_INVALID_NAME)
//        {
////        if (pG->Frame.Verbose)// < 0)
////            Notify( PF, ITRACE, "Invalid file name: \"%s\" ",  filename);
//            return -2;// DOES_NOT_EXIST;
//            
//        }
//        if (pG->Frame.Verbose < 0)
//            Notify( PF, ITRACE, "check_for_newer: FindFirstFile(%s) returns %d: file does not exist",
//                filename, err);
////              stat( filename, & pG->statbuf )   );
//        return DOES_NOT_EXIST;
//    }
//    else
//    {
//        NtfsFileTime2utime(&FindFileData.ftLastWriteTime, &ut);
//        FindClose(hFind);
//    }
  if ( stat( filename, & pG->statbuf ) )
  {
    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "check_for_newer:  stat(%s) returns %d:  file does not exist", filename,
              stat( filename, & pG->statbuf )   );
    return DOES_NOT_EXIST;
  }
  //Trace( (pG, "check_for_newer:  stat(%s) returns 0:  file exists", filename) );
#ifdef USE_EF_UX_TIME
  /* The `Unix extra field mtime' should be used for comparison with the
  * time stamp of the existing file >>>ONLY<<< when the EF info is also
  * used to set the modification time of the extracted file. * Currently, this is only the case for systems that incorporate
  * the OS specific code from the "unix/" subdirectory. */
  if ( pG->extra_field && ef_scan_for_izux( pG->extra_field, pG->lrec.extra_field_length, & z_utime, NULL ) > 0 )
  {
    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "check_for_newer:  using Unix extra field mtime"   );
    existing = pG->statbuf.st_mtime;
    archive = z_utime.modtime;
  }
  else
  {
    /* round up existing filetime to nearest 2 seconds for comparison */
    existing = pG->statbuf.st_mtime & 1 ? pG->statbuf.st_mtime + 1 : pG->statbuf.st_mtime;
    archive = dos_to_unix_time( pG->lrec.last_mod_file_date, pG->lrec.last_mod_file_time );
  }
#else /* !USE_EF_UX_TIME */
  /* round up existing filetime to nearest 2 seconds for comparison */
  existing = pG->statbuf.st_mtime & 1 ? pG->statbuf.st_mtime + 1 : pG->statbuf.st_mtime;
  archive = dos_to_unix_time( pG->lrec.last_mod_file_date, pG->lrec.last_mod_file_time );
//  existing = (ut & 1) ? ut + 1 : ut;
//  archive = dos_to_unix_time( pG->lrec.last_mod_file_date, pG->lrec.last_mod_file_time );
#endif /* ?USE_EF_UX_TIME */
  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "check_for_newer:  existing %ld, archive %ld, Result %d", existing, archive, existing >= archive   );
  return ( existing >= archive );
} 
/* end function check_for_newer() */


/* =========================================================================== *            Function do_string()
* Return PK-type error code. len    :: Without prototype, ush converted to this.
option :: SKIP, DISPLAY, DS_FN or EXTRA_FIELD */
int do_string( struct UGlobals * pG, unsigned int len, int option )
{
  long comment_bytes_left, block_length;
  int error = PK_OK;
  ush extra_len;

  /*---------------------------------------------------------------------------
  * This function processes arbitrary-length (well, usually) strings.  Four
  * options are allowed:  SKIP, wherein the string is skipped (pretty logical,
  * eh?); DISPLAY, wherein the string is printed to standard output after un-
  * dergoing any necessary or unnecessary character conversions; DS_FN,
  * wherein the string is put into the filename[] array after undergoing ap-
  * propriate conversions (including case-conversion, if that is indicated:
  * see the global variable pInfo->lcflag); and EXTRA_FIELD, wherein the
  * `string' is assumed to be an extra field and is copied to the (freshly
  * malloced) buffer pG->extra_field.  The third option should be OK since
  * filename is dimensioned at 1025, but we check anyway.
  *
  * The string, by the way, is assumed to start at the current file-pointer
  * position; its length is given by len.  So start off by checking length
  * of string:  if zero, we're already done.
  *---------------------------------------------------------------------------*/
  if ( !len )
    return PK_COOL;

  switch ( option )
  {
      /* * First case:  print string on standard output.  First set loop vari-
      * ables, then loop through the comment in chunks of OUTBUFSIZ bytes,
      * converting formats and printing as we go.  The second half of the
      * loop conditional was added because the file might be truncated, in
      * which case comment_bytes_left will remain at some non-zero value for
      * all time.  outbuf and slide are used as scratch buffers because they
      * are available (we should be either before or in between any file processing). */
    case DISPLAY:
      comment_bytes_left = len;
      block_length = OUTBUFSIZ;
      /* for the while statement, first time */
      while ( comment_bytes_left > 0 && block_length > 0 )
      {
        register uch * p = pG->outbuf;
        register uch * q = pG->outbuf;

        if ( ( block_length = readbuf( pG, ( char * ) pG->outbuf,
                                       ( unsigned )MIN( ( long )OUTBUFSIZ, comment_bytes_left ) ) ) == 0 )
          return PK_EOF;
        comment_bytes_left -= block_length;

        /* this is why we allocated an extra byte for outbuf:  terminate *  with zero (ASCIIZ) */
        pG->outbuf[( unsigned )block_length] = '\0';

        /* remove all ASCII carriage returns from comment before printing
        * (since used before A_TO_N(), check for CR instead of '\r') */
        while ( * p )
        {
          while ( * p == CR )
            ++p;
          * q++ = * p++;
        }

        /* could check whether (p - outbuf) == block_length here */
        * q = '\0';

        A_TO_N( pG->outbuf );
        /* translate string to native */

#ifdef NATIVE           /* GRR:  can ANSI be used with EBCDIC? */
        // (*pG->message)( (void *)&G, pG->outbuf, (ulg)(q-pG->outbuf), 0 );
#else /* ASCII */
        p = pG->outbuf - 1;
        q = slide;
        while ( * ++p )
        {
          int pause = false;

          if ( * p == 0x1B )
          {
            /* ASCII escape char */
            * q++ = '^';
            * q++ = '[';
          }
          else
            if ( * p == 0x13 )
            {
              /* ASCII ^S (pause) */
              pause = true;
              if ( p[1] == 0x0a ) /* ASCII LF */
                * q++ = * ++p;
              else
                if ( p[1] == 0x0d && p[2] == 0x0a )
                {
                  /* ASCII CR LF */
                  * q++ = * ++p;
                  * q++ = * ++p;
                }
            }
            else
              * q++ = * p;
          if ( ( unsigned )( q - slide ) > WSIZE - 3 || pause )
          {
            /* flush */
            // (*pG->message)( (void *)&G, slide, (ulg)(q-slide), 0 );
            q = slide;
          }
        }
        // (*pG->message)( (void *)&G, slide, (ulg)(q-slide), 0 );
#endif /* ?NATIVE */
      }

      /* add '\n' if not at start of line */
      // (*pG->message)( (void *)&G, slide, 0L, 0x40 );
      break;

      /* * Second case:  read string into filename[] array.  The filename should
      * never ever be longer than FILNAMSIZ - 1 (1024), but for now we'll check,
      * just to be sure. */
    case DS_FN:
      extra_len = 0;
      if ( len >= FILNAMSIZ )
      {
        Notify( PF,  IWARNING, " filename too long; truncated" );
        error = PK_WARN;
        extra_len = ( ush )( len - FILNAMSIZ + 1 );
        len = FILNAMSIZ - 1;
      }

      if ( readbuf( pG, pG->filename, len ) == 0 )
        return PK_EOF;
      pG->filename[len] = '\0';
      /* terminate w/zero:  ASCIIZ */

      /* RCV put in (again) for accented char (i.e. Winzip/Pkzip archives.)
      * translate the Zip entry filename coded in host-dependent "extended
      * ASCII" into the compiler's (system's) internal text code page */
      ExtASCII2Native( pG, pG->filename, pG->pInfo->hostnum, pG->crec.version_made_by[0] );

      A_TO_N( pG->filename );
      /* translate string to native */

      if ( pG->pInfo->lcflag ) /* replace with lowercase filename */
        TOLOWER( pG->filename, pG->filename );

      if ( pG->pInfo->vollabel && len > 8 && pG->filename[8] == (char)'.' )
      {
        char * p = pG->filename + 8;
        while ( * p++ )
          p[-1] = * p;
        /* disk label, and 8th char is dot:  remove dot */
      }

      if ( !extra_len )
        break;
      /* we're done here */

      /* * We truncated the filename, so fall * through to the SKIP routine. */
      len = extra_len;

      /* FALL THROUGH... */
      /* * Third case:  skip string, adjusting readbuf's internal variables
      * as necessary (and possibly skipping to and reading a new block of data). */
    case SKIP:
      /* cur_zipfile_bufstart already takes account of extra_bytes, so don't
      * correct for it twice: */
      ZLSEEK( pG->cur_zipfile_bufstart - pG->extra_bytes + ( pG->inptr - pG->inbuf ) + len )
      break;

      /* * Fourth case:  assume we're at the start of an "extra field"; malloc
      * storage for it and read data into the allocated space. */
    case EXTRA_FIELD:
      if ( pG->extra_field != ( uch * ) NULL )
        FREE( pG->extra_field );
      pG->extra_field = ( uch * ) MALLOC( len );
      if ( pG->extra_field == ( uch * ) NULL )
      {
        Notify( PF, IWARNING, " extra field too long" );

        /* cur_zipfile_bufstart already takes account of extra_bytes,
        * so don't correct for it twice: */
        ZLSEEK( pG->cur_zipfile_bufstart - pG->extra_bytes + ( pG->inptr - pG->inbuf ) + len )
      }
      else
        if ( readbuf( pG, ( char * ) pG->extra_field, len ) == 0 )
          return PK_EOF;
      break;
  }
  /* end switch (option) */

  return error;
}

/* end function do_string() */


/* ===========================================================================
* Convert Intel style 'short' integer to non-Intel non-16-bit
* host format.  This routine also takes care of byte-ordering. */
ush makeword( uch * b )
{
  return ( ush )( ( b[1] << 8 ) | b[0] );
}


/* ===========================================================================
* Convert intel style 'long' variable to non-Intel non-16-bit
* host format.  This routine also takes care of byte-ordering. */
ulg makelong( uch * sig )
{
  return ( ( ( ulg )sig[3] ) << 24 ) + ( ( ( ulg )sig[2] ) << 16 ) + ( ( ( ulg )sig[1] ) << 8 ) + ( ( ulg )sig[0] );
}

#ifdef CRYPT
/* ===========================================================================
*     Function oem2iso()
*source :: Source buffer. */
unsigned char oem2iso( unsigned char Source )
{
  unsigned char Dest;

  OemToCharBuff( ( char * ) & Source, ( char * ) & Dest, 1 );
  return Dest;
}

# ifdef NEED_STR2ISO
/* ===========================================================================
*   Function str2iso()
*dst :: Destination buffer.
*src :: Source string. */
char * str2iso( char * dst, register const char * src )
{
#  ifdef INTERN_TO_ISO
  INTERN_TO_ISO( src, dst );
#  else
  register uch c;
  register char * dstp = dst;

  do
  {
    c = ( uch )foreign( * src++ );
    * dstp++ = ( char )ASCII2ISO( c );
  }
  while ( c != '\0' );
#  endif
  return dst;
}
# endif /* NEED_STR2ISO */


# ifdef NEED_STR2OEM
/* ===========================================================================
*       Function iso2oem()
*source :: Source buffer. */
unsigned char iso2oem( unsigned char Source )
{
  unsigned char Dest;

  CharToOemBuff( ( char * ) & Source, ( char * ) & Dest, 1 );
  return Dest;
}

/* ===========================================================================
*     Function str2oem()
*dst :: Destination buffer.
*src :: Source string. */
char * str2oem( char * dst, register const char * src )
{
#  ifdef INTERN_TO_OEM
  INTERN_TO_OEM( src, dst );
#  else
  register uch c;
  register char * dstp = dst;

  do
  {
    c = ( uch )foreign( * src++ );
    * dstp++ = ( char )ASCII2OEM( c );
  }
  while ( c != '\0' );
#  endif
  return dst;
}
# endif /* NEED_STR2OEM */
#endif /* CRYPT */

/* ===========================================================================
*        Function zstrnicmp() * /
int zstrnicmp( register const char * s1, register const char * s2, register unsigned n )
{
  for ( ; n > 0; --n, ++s1, ++s2 )
  {
    if ( ToLower( * s1 ) != ToLower( * s2 ) ) /* test includes early termination of one string * /
      return ( ToLower( * s1 ) < ToLower( * s2 ) ) ? -1 : 1;
 
    if ( * s1 == '\0' ) /* both strings terminate early * /
      return 0;
  }
  return 0;
}
 
/* ===========================================================================
*     Function ExtAscii2Native()
*
* Convert filename (and file comment string) into "internal" charset.
* This function assumes that Zip entry filenames are coded in OEM (IBM DOS)
* codepage when made on
*  -> DOS (this includes 16-bit Windows 3.1)  (FS_FAT_  {0} )
*  -> OS/2                                    (FS_HPFS_ {6} )
*  -> Win95/WinNT with Nico Mak's WinZip      (FS_NTFS_ {11} && hostver == "5.0" {50} )
*
* All other ports are assumed to code zip entry filenames in ISO 8859-1. */
void ExtASCII2Native( struct UGlobals * pG, char * string, int hostnum, short int hostver )
{
  if ( pG->WantedCodePage == cpAUTO
       && ( hostnum == FS_FAT_ || hostnum == FS_HPFS_ || ( hostnum == FS_NTFS_ && hostver == 50 ) )
       || pG->WantedCodePage == cpOEM )
  {
    _OEM_INTERN( ( string ) ); // Translate to ISO
  }
  else
  {
    _ISO_INTERN( ( string ) ); // Does nothing since we are already using ISO. (depends on CRTL_CP_IS_ISO/OEM)
  }
}

char * GetFullPath( struct UGlobals * pG, char * Filename )
{
  char c;
  char * e = pG->ExtractPath; //ExtractDir;
  char * p = pG->ewemsg;
  * p = 0; // in case both ExtractDir && Filename were empty
  if ( !Filename )
    return pG->ewemsg;
  if ( !( ( isalpha( Filename[0] ) && Filename[1] == (char)':' ) ||
            ( Filename[0] == (char)'\\' && Filename[1] == (char)'\\' )
          || ( Filename[0] == (char)'/' && Filename[1] == (char)'/' ) ) &&
             e && ( c = * e++ ) != 0 )
  {
    do // copy Extract Dir
      * p++ = c;
    while ( (c = *e++) != 0 );
    if ( (c = *(p - 1)) != (char)':' && c != (char)'\\' )
//    if ( (c = *(p - 1)) != (char)':' && c != (char)'\\' && c != '/' &&
//        *Filename != '/' && *Filename != '\\' )
      * p++ = '\\';
    * p = 0;
  }
  //    if ( Filename )
  //    {
//  if (*Filename != '/' || *Filename != '\\')
  if (p != pG->ewemsg && (*Filename == '/' || *Filename == '\\'))
      Filename++;
  do // copy filename
  {
    if ( ( c = * Filename++ ) == (char)'/' )
      c = '\\';
    * p++ = c;
  }
  while ( c );
  //    }

  return pG->ewemsg;
}

#ifdef USE_STRM_OUTPUT
int WriteToMemory( struct UGlobals * pG, uch * rawbuf, ulg size )
{
  if ( rawbuf != pG->redirect_pointer )
    memcpy( pG->redirect_pointer, rawbuf, size );
  pG->redirect_pointer += size;
  return 0;
}
#endif

#ifdef USE_STRM_INPUT
// SEEK_CUR     Current file pointer position
// SEEK_END     End-of-file
// SEEK_SET     File beginning
// Error then return -1 else the position in the stream from the beginning.
long vclSeek( struct UGlobals * pG, long Offset, int FromWhere )
{
  if ( pG->UseInStream )
  {
    switch ( FromWhere )
    {
      case SEEK_CUR:
        pG->StreamPos += Offset;
        break;
      case SEEK_END:
        pG->StreamPos = pG->InStreamSize - Offset;
        break;
      case SEEK_SET:
        pG->StreamPos = Offset;
    }
    if ( pG->StreamPos > pG->InStreamSize )
    {
      pG->StreamPos = 0;
      return -1L;
    }
    return pG->StreamPos;
  }
  else
  {
    long hi = 0;
    unsigned long sz = SetFilePointer( pG->zipfdz, Offset, & hi, 0 );
    if ( hi || ( sz == INVALID_SET_FILE_POINTER && GetLastError() ) )
      return -1;
    return sz;
    //    return lseek ( pG->zipfdz, Offset, FromWhere );
  }
}

// Returns 0 on end of stream.
int vclRead( struct UGlobals * pG, void * buf, unsigned LenToRead )
{
  if ( pG->UseInStream )
  {
    if ( pG->StreamPos == pG->InStreamSize )
      return 0;
    LenToRead = min( LenToRead, pG->InStreamSize - pG->StreamPos );
    memcpy( buf, pG->InStream, LenToRead );
    pG->StreamPos += LenToRead;
    return LenToRead;
  }
  else
    //    return read ( pG->zipfd, buf, LenToRead );
  {
    unsigned long cnt;
    if ( !ReadFile( pG->zipfdz, buf, LenToRead, & cnt, NULL ) )
      return 0;
    return cnt;
  }
}

#else
long vclSeek( struct UGlobals * pG, long Offset, int FromWhere )
{
  return lseek( pG->zipfd, Offset, FromWhere );
}

int vclRead( struct UGlobals * pG, void * buf, unsigned LenToRead )
{
  return read( pG->zipfd, buf, LenToRead );
}
#endif
