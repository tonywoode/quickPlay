#include <windows.h>
#include "Common.h"
#pragma hdrstop
/* This version modified by Chris Vleghert and Eric W. Engler
 * for BCB/Delphi Zip, Jun 18, 2000.
 */

/*---------------------------------------------------------------------------
 * process.c
 * This file contains the top-level routines for processing multiple zipfiles.
 * Contains:  process_zipfiles()
 *            do_seekable()
 *            find_ecrec()
 *            uz_end_central()
 *            process_cdir_file_hdr()
 *            get_cdir_ent()
 *            process_local_file_hdr()
 *            ef_scan_for_izux()
 *---------------------------------------------------------------------------*/


#include "unzip.h"

#include <windows.h>

static int do_seekable( struct UGlobals * pG, int lastchance );
static int find_ecrec( struct UGlobals * pG, long searchlen );


/* ===========================================================================
*                     Function process_zipfiles()
* return PK-type error code
*/
void process_zipfiles( struct UGlobals * pG )
{
  char * p;
  char * lastzipfn;// = ( char * ) NULL;
  int NumWinFiles, NumLoseFiles, NumWarnFiles;
  int NumMissDirs, NumMissFiles;
  int error; //,       error_in_archive = 0;

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "In process_zipfiles" );

  /*---------------------------------------------------------------------------
  * Start by allocating buffers and (re)constructing the various PK signature
  * strings.
  *---------------------------------------------------------------------------*/
//  pG->inbuf = ( uch * ) MALLOC( INBUFSIZ + 4 );
  /* 4 extra for hold[] (below) */
  if ( pG->inbuf == NULL )
  {
    UnzErr( pG, UEN_MEM03 );
    return;
  }

  /* Normally realbuf and outbuf will be the same.  However, if the data
  * are redirected to a large memory buffer, realbuf will point to the
  * new location while outbuf will remain pointing to the malloc'd
  * memory buffer.  (The extra "1" is for string termination.) */
//  pG->realbuf = pG->outbuf = ( uch * ) MALLOC( OUTBUFSIZ + 1 );
  if ( pG->outbuf == NULL )
  {
//    FREE( pG->inbuf );
    UnzErr( pG, UEN_MEM01 );
    return;
  }
  pG->hold = pG->inbuf + INBUFSIZ;
  /* to check for boundary-spanning sigs */

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "two" );
  pG->local_hdr_sig[0] /* = extd_local_sig[0] */ = 0x50;
  /* ASCII 'P', */
  pG->central_hdr_sig[0] = pG->end_central_sig[0] = 0x50;
  /* not EBCDIC */

  pG->local_hdr_sig[1] /* = extd_local_sig[1] */ = 0x4B;
  /* ASCII 'K', */
  pG->central_hdr_sig[1] = pG->end_central_sig[1] = 0x4B;
  /* not EBCDIC */

  /* GRR FIX:  no need for these to be in global struct; OK to "overwrite" */
  lstrcpy( pG->local_hdr_sig + 2, LOCAL_HDR_SIG );
  lstrcpy( pG->central_hdr_sig + 2, CENTRAL_HDR_SIG );
  lstrcpy( pG->end_central_sig + 2, END_CENTRAL_SIG );

  /*---------------------------------------------------------------------------
  * Match (possible) wildcard zipfile specification with existing files and
  * attempt to process each.  If no hits, try again after appending ".zip"
  * suffix.  If still no luck, give up.
  *---------------------------------------------------------------------------*/
  NumWinFiles = NumLoseFiles = NumWarnFiles = 0;
  NumMissDirs = NumMissFiles = 0;
  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "four in process.c");// - ready to dowild" );

  // dowild() gives us the real name of zipfile, in case wildcard was used.
//  while ( ( pG->zipfn = do_wild( pG, pG->wildzipfn ) ) != NULL )
//  {
//    if (pG->Frame.Verbose < 0)
//      Inform( pG, ITRACE, "back from do_wild( %s ) returned %s", pG->wildzipfn, pG->zipfn   );
    lastzipfn = pG->zipfn;

    if ( ( error = do_seekable( pG, 0 ) ) == PK_WARN )
      ++NumWarnFiles;
    else
      if ( error == IZ_DIR )
        ++NumMissDirs;
      else
        if ( error == PK_NOZIP )
          ++NumMissFiles;
        else
          if ( error )
            ++NumLoseFiles;
          else
            ++NumWinFiles;

    if (pG->Frame.Verbose < 0)
    {
      Notify( PF, ITRACE, "after do_seekable, warn=%d   missdir=%d  missfi=%d  losefi=%d  winfi=%d", NumWarnFiles, NumMissDirs,
              NumMissFiles, NumLoseFiles, NumWinFiles );

      Notify( PF, ITRACE, "do_seekable(0) returns %d (see unzpriv.h, PK_*)", error   );
    }
  /* end while-loop (wildcard zipfiles) */

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "five in process.c" );
  if ( ( NumWinFiles + NumWarnFiles + NumLoseFiles ) == 0 && ( NumMissDirs + NumMissFiles ) == 1
       && lastzipfn != ( char * ) NULL )
  {
    NumMissDirs = NumMissFiles = 0;
    p = lastzipfn + lstrlen( lastzipfn );
    pG->zipfn = lastzipfn;
    lstrcpy( p, ZSUFX );

    error = do_seekable( pG, 1 );
    if ( error == PK_WARN ) /* GRR: make this a switch/case stmt ... */
      ++NumWarnFiles;
    else
      if ( error == IZ_DIR )
        ++NumMissDirs;
      else
        if ( error == PK_NOZIP ) /* increment again => bug: "1 file had no zipfile directory." */
          /* ++NumMissFiles */
          ;
        else
          if ( error )
            ++NumLoseFiles;
          else
            ++NumWinFiles;
    //                      if ( error > error_in_archive ) error_in_archive = error;
    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "do_seekable(1) returns %d", error  );
  }

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "six" );

  /*---------------------------------------------------------------------------
  * Print summary of all zipfiles, assuming zipfile spec was a wildcard (no
  * need for a summary if just one zipfile).
  *---------------------------------------------------------------------------*/
  if ( ( NumWinFiles > 1 ) || ( NumWinFiles == 1 && NumMissDirs + NumMissFiles + NumLoseFiles + NumWarnFiles > 0 ) )
    Notify( PF, 0,  "files processed OK" );
  if ( NumWarnFiles > 0 )
    Notify( PF, 0,  "warnings were given" );
  if ( NumLoseFiles > 0 || NumMissFiles > 0 )
    Notify( PF, 0,  "file(s) not found" );
  if ( NumMissDirs == 1 )
    Notify( PF, 0,  "zip file was dir" );
  else
    if ( NumMissDirs > 0 )
      Notify( PF, 0,  "many zip file were dirs" );
  if ( NumWinFiles + NumLoseFiles + NumWarnFiles == 0 )
    Notify( PF, 0,  "no files found" );

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "seven" );
  /* free allocated memory */
  inflate_free( pG );
  checkdir( pG, ( char * ) NULL, END );

  if ( pG->outbuf2 )
    FREE( pG->outbuf2 );
  return;
}
/* end function process_zipfiles() */


/* ===========================================================================
*                     Function do_seekable()
* return PK-type error code */
static int do_seekable( struct UGlobals * pG, int lastchance )
{
  /* static int no_ecrec = FALSE;  SKM: moved to globals.h */
  int maybe_exe = false;
  int too_weird_to_continue = false;
  int error = 0, error_in_archive;

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "starting do_seekable" );

  /*---------------------------------------------------------------------------
  * Open the zipfile for reading in BINARY mode to prevent CR/LF translation,
  * which would corrupt the bit streams.
  *---------------------------------------------------------------------------*/
  if ( stat( pG->zipfn, & pG->statbuf ) || ( error = S_ISDIR( pG->statbuf.st_mode ) ) != 0 )
  {
    if ( lastchance )
    {
      if ( pG->no_ecrec )
        Notify( PF, 0, "can't find zip file dir" );
      else
        Notify( PF, 0, "can't find either zip file" );
    }

    return error ? IZ_DIR : PK_NOZIP;
  }

  pG->ziplen = pG->statbuf.st_size;

  if ( pG->statbuf.st_mode & S_IEXEC )
    maybe_exe = true;
  /* might find unzip, not unzip.zip; etc. */

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "do_seekable, loc 2" );
  if ( open_input_file( pG ) ) /* this should never happen, given */
    return PK_NOZIP;
  /* the stat() test above, but... */
  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "do_seekable, loc 3" );

  /*---------------------------------------------------------------------------
  * Find and process the end-of-central-directory header.  UnZip need only
  * check last 65557 bytes of zipfile:  comment may be up to 65535, end-of-
  * central-directory record is 18 bytes, and signature itself is 4 bytes;
  * add some to allow for appended garbage.
  *---------------------------------------------------------------------------*/

  pG->cur_zipfile_bufstart = 0;
  pG->inptr = pG->inbuf;

#ifdef TIMESTAMP
  if ( !pG->qflag && !pG->T_flag && !pG->zipinfo_mode )
#else
  if ( !pG->qflag && !pG->zipinfo_mode )
#endif

    Notify( PF, 0, "Archive:  %s", pG->zipfn );

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "do_seekable, loc 4" );
  if ( ( ( ( error_in_archive = find_ecrec( pG, MIN( pG->ziplen, 66000L ) ) ) != 0
           || ( error_in_archive = uz_end_central( pG ) ) > PK_WARN ) ) )
  {
    //    close ( pG->zipfd );
    CloseHandle( pG->zipfdz );
    pG->zipfdz = INVALID_HANDLE_VALUE; //0;

    //        pG->zipfd = 0;              /* RCV added 29-1-99 */
    if ( maybe_exe )
      Notify( PF, 0,  "maybe an EXE file: %s", pG->zipfn );
    if ( lastchance )
      return error_in_archive;
    else
    {
      pG->no_ecrec = true;
      /* assume we found wrong file:  e.g., */
      return PK_NOZIP;
      /* unzip instead of unzip.zip */
    }
  }

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "do_seekable, loc 5" );
  if ( pG->zflag > 0 && !pG->zipinfo_mode )
  {
    /* unzip: zflag = comment ONLY */
    CloseHandle( pG->zipfdz );
    pG->zipfdz = INVALID_HANDLE_VALUE; //0;

    //        close ( pG->zipfd );
    //        pG->zipfd = 0;              /* RCV added 29-1-99 */
    return error_in_archive;
  }

  /*---------------------------------------------------------------------------
  * Test the end-of-central-directory info for incompatibilities (multi-disk
  * archives) or inconsistencies (missing or extra bytes in zipfile).
  *---------------------------------------------------------------------------*/
#ifdef NO_MULTIPART
  error = !pG->zipinfo_mode && ( pG->ecrec.number_this_disk == 1 ) && ( pG->ecrec.num_disk_start_cdir == 1 );
#else
  error = !pG->zipinfo_mode && ( pG->ecrec.number_this_disk != 0 );
#endif

  if ( pG->zipinfo_mode && pG->ecrec.number_this_disk != pG->ecrec.num_disk_start_cdir )
  {
    if ( pG->ecrec.number_this_disk > pG->ecrec.num_disk_start_cdir )
    {
      UnzErr( pG, UEN_MISC01 );
      error_in_archive = PK_FIND;
      too_weird_to_continue = true;
    }
    else
    {
      Notify( PF, 0,  "Central dir bogus" );
      error_in_archive = PK_WARN;
    }

#ifdef NO_MULTIPART /* concatenation of multiple parts works in some cases */
  }
  else
    if ( !pG->zipinfo_mode && !error && pG->ecrec.number_this_disk != 0 )
    {
      UnzErr( pG, UEN_MISC02 );
      error_in_archive = PK_FIND;
      too_weird_to_continue = true;
#endif
    }

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "do_seekable, loc 6" );
  if ( !too_weird_to_continue )
  {
    /* (relatively) normal zipfile:  go for it */
    if ( error )
    {
      Notify( PF, 0,  "maybe a pak bug in %s", pG->zipfn );
      error_in_archive = PK_WARN;
    }

    if ( ( pG->extra_bytes = pG->real_ecrec_offset - pG->expect_ecrec_offset ) < 0L )
    {
      Notify( PF, 0,  "missing bytes in zipfile" );
      error_in_archive = PK_ERR;
    }
    else
      if ( pG->extra_bytes > 0 )
      {
        if ( ( pG->ecrec.offset_start_central_directory == 0 ) && ( pG->ecrec.size_central_directory != 0 ) )
        {
          /* zip 1.5 -go bug */
          Notify( PF, 0,  "NULL central dir" );
          pG->ecrec.offset_start_central_directory = pG->extra_bytes;
          pG->extra_bytes = 0;
          error_in_archive = PK_ERR;
        }
        else
        {
          Notify( PF, 0,  "Warning: extra bytes at start of zipfile" );
          error_in_archive = PK_WARN;
        }
      }

    /*-----------------------------------------------------------------------
    *       Check for empty zipfile and exit now if so.
    *-----------------------------------------------------------------------*/
    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "do_seekable, loc 7" );
    if ( pG->expect_ecrec_offset == 0L && pG->ecrec.size_central_directory == 0 )
    {
      Notify( PF, 0,  "Empty zipfile" );
      CloseHandle( pG->zipfdz );
      pG->zipfdz = INVALID_HANDLE_VALUE; //0;

      //      close ( pG->zipfd );
      //            pG->zipfd = 0;            /* RCV added 29-1-99 */
      return ( error_in_archive > PK_WARN ) ? error_in_archive : PK_WARN;
    }

    /*-----------------------------------------------------------------------
    * Compensate for missing or extra bytes, and seek to where the start
    * of central directory should be.  If header not found, uncompensate
    * and try again (necessary for at least some Atari archives created
    * with STZip, as well as archives created by J.H. Holm's ZIPSPLIT 1.1).
    *-----------------------------------------------------------------------*/
    ZLSEEK( pG->ecrec.offset_start_central_directory )
#ifdef OLD_SEEK_TEST
    if ( readbuf( pG->sig, 4 ) == 0 )
    {
      close( pG->zipfd );
      pG->zipfd = 0;
      /* RCV added 29-1-99 */
      return PK_ERR;
      /* file may be locked, or possibly disk error(?) */
    }

    if ( strncmp( pG->sig, pG->central_hdr_sig, 4 ) )
#else
    if ( ( readbuf( pG, pG->sig, 4 ) == 0 ) || strncmp( pG->sig, pG->central_hdr_sig, 4 ) )
#endif

    {
      // long tmp = pG->extra_bytes;
      if (pG->Frame.Verbose < 0)
        Notify( PF, ITRACE, "central dir found" );
      pG->extra_bytes = 0;
      ZLSEEK( pG->ecrec.offset_start_central_directory )
      if ( ( readbuf( pG, pG->sig, 4 ) == 0 ) || strncmp( pG->sig, pG->central_hdr_sig, 4 ) )
      {
        UnzErr( pG, UEN_FORM18 );
        CloseHandle( pG->zipfdz );
        pG->zipfdz = INVALID_HANDLE_VALUE; //0;

        //   close ( pG->zipfd );
        //                pG->zipfd = 0;          /* RCV added 29-1-99 */
        return PK_BADERR;
      }

      Notify( PF, 0,  "central dir too long" );
      error_in_archive = PK_ERR;
    }

    /*-----------------------------------------------------------------------
    * Seek to the start of the central directory one last time, since we
    * have just read the first entry's signature bytes; then list, extract
    * or test member files as instructed, and close the zipfile.
    *-----------------------------------------------------------------------*/
    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "about to extract/list files (error = %d)", error_in_archive   );
    ZLSEEK( pG->ecrec.offset_start_central_directory )
#ifdef TIMESTAMP
    // EWE  do some work here???
    // How can you timestamp a file before you extract it?
    //          if ( pG->T_flag )
    //              error = time_stamp( pG );              /* TIME-STAMP 'EM */
    //          else
#endif

    //          if ( pG->vflag && !pG->tflag && !pG->cflag )
    //              error = //list_files( pG );              /* LIST 'EM */
    //          else
    //              GO DO EXTRACT OR TEST
    error = extract_or_test_files( pG );
    /* EXTRACT OR TEST 'EM */

    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "Done with extract/list files (error = %d)", error  );
    if ( error > error_in_archive ) /* don't overwrite stronger error */
      error_in_archive = error;
    /* with (for example) a warning */
  }
  /* end if (!too_weird_to_continue) */

  CloseHandle( pG->zipfdz );
  pG->zipfdz = INVALID_HANDLE_VALUE; //0;

  //  close ( pG->zipfd );
  //    pG->zipfd = 0;                /* RCV added 29-1-99 */
  return error_in_archive;
}
/* end function do_seekable() */


/* ===========================================================================
*                    Function find_ecrec()
*/
static int find_ecrec( struct UGlobals * pG, long searchlen )
{
  /* return PK-class error */
  int i, numblks, found = false;
  long tail_len;
  ec_byte_rec byterec;

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "in find_ecrec (end of central dir)" );

  /*---------------------------------------------------------------------------
  *    Treat case of short zipfile separately.
  *--------------------------------------------------------------------------*/
  if ( pG->ziplen <= INBUFSIZ )
  {
    vclSeek( pG, 0L, SEEK_SET );
    if ( ( pG->incnt = vclRead( pG, ( char * ) pG->inbuf, ( unsigned int ) pG->ziplen ) ) == ( int )pG->ziplen )
      /* 'P' must be at least 22 bytes from end of zipfile */
      for ( pG->inptr = pG->inbuf + ( int )pG->ziplen - 22; pG->inptr >= pG->inbuf; --pG->inptr )
        if ( ( native( * pG->inptr ) == 'P' ) && !strncmp( ( char * ) pG->inptr, pG->end_central_sig, 4 ) )
        {
          pG->incnt -= ( int )( pG->inptr - pG->inbuf );
          found = true;
          break;
        }

    /*---------------------------------------------------------------------------
    *  Zipfile is longer than INBUFSIZ:  may need to loop.  Start with short
    *  block at end of zipfile (if not TOO short).
    *---------------------------------------------------------------------------*/
  }
  else
  {
    if ( ( tail_len = pG->ziplen % INBUFSIZ ) > ECREC_SIZE )
    {
      // RCV Changed 29-1-99 USE_STREAM_INPUT
      pG->cur_zipfile_bufstart = vclSeek( pG, pG->ziplen - tail_len, SEEK_SET );
      if ( ( pG->incnt = vclRead( pG, ( char * ) pG->inbuf, ( unsigned int ) tail_len ) ) != ( int )tail_len )
        goto fail;
      /* it's expedient... */
      /* 'P' must be at least 22 bytes from end of zipfile */
      for ( pG->inptr = pG->inbuf + ( int )tail_len - 22; pG->inptr >= pG->inbuf; --pG->inptr )
        if ( ( native( * pG->inptr ) == 'P' ) && !strncmp( ( char * ) pG->inptr, pG->end_central_sig, 4 ) )
        {
          pG->incnt -= ( int )( pG->inptr - pG->inbuf );
          found = true;
          break;
        }
      /* sig may span block boundary: */
      strncpy( ( char * ) pG->hold, ( char * ) pG->inbuf, 3 );
    }
    else
      pG->cur_zipfile_bufstart = pG->ziplen - tail_len;

    /*-----------------------------------------------------------------------
    * Loop through blocks of zipfile data, starting at the end and going
    * toward the beginning.  In general, need not check whole zipfile for
    * signature, but may want to do so if testing.
    *-----------------------------------------------------------------------*/
    numblks = ( int )( ( searchlen - tail_len + ( INBUFSIZ - 1 ) ) / INBUFSIZ );
    /* ==amount=   ==done==    ==rounding==     =blksiz= */

    for ( i = 1; !found && ( i <= numblks ); ++i )
    {
      pG->cur_zipfile_bufstart -= INBUFSIZ;
      vclSeek( pG, pG->cur_zipfile_bufstart, SEEK_SET );
      if ( ( pG->incnt = vclRead( pG, ( char * ) pG->inbuf, INBUFSIZ ) ) != INBUFSIZ )
        break;
      /* fall through and fail */

      for ( pG->inptr = pG->inbuf + INBUFSIZ - 1; pG->inptr >= pG->inbuf; --pG->inptr )
        if ( ( native( * pG->inptr ) == 'P' ) && !strncmp( ( char * ) pG->inptr, pG->end_central_sig, 4 ) )
        {
          pG->incnt -= ( int )( pG->inptr - pG->inbuf );
          found = true;
          break;
        }
      /* signature may span block boundary: */
      strncpy( ( char * ) pG->hold, ( char * ) pG->inbuf, 3 );
    }
  }
  /* end if ( ziplen > INBUFSIZ ) */

  /*---------------------------------------------------------------------------
  * Searched through whole region where signature should be without finding
  * it.  Print informational message and die a horrible death.
  *---------------------------------------------------------------------------*/
fail:
  if ( !found )
  {
    UnzErr( pG, UEN_EOF01 );
    return PK_ERR;
    /* failed */
  }

  /*---------------------------------------------------------------------------
  * Found the signature, so get the end-central data before returning.  Do
  * any necessary machine-type conversions (byte ordering, structure padding
  * compensation) by reading data into character array and copying to struct.
  *---------------------------------------------------------------------------*/
  pG->real_ecrec_offset = pG->cur_zipfile_bufstart + ( pG->inptr - pG->inbuf );

  if (pG->Frame.Verbose < 0)
  {
    Notify( PF, ITRACE, "Found end-of-central-dir signature at offset %ld (%.8lXh)",
            pG->real_ecrec_offset, pG->real_ecrec_offset   );
    Notify( PF, ITRACE, "    from beginning of file; offset %d (%.4Xh) within block",
            pG->inptr - pG->inbuf, pG->inptr - pG->inbuf  );
  }

  if ( readbuf( pG, ( char * ) byterec, ECREC_SIZE + 4 ) == 0 )
    return PK_EOF;
  pG->ecrec.number_this_disk = makeword( & byterec[NUMBER_THIS_DISK] );
  pG->ecrec.num_disk_start_cdir = makeword( & byterec[NUM_DISK_WITH_START_CENTRAL_DIR] );
  pG->ecrec.num_entries_centrl_dir_ths_disk = makeword( & byterec[NUM_ENTRIES_CENTRL_DIR_THS_DISK] );
  pG->ecrec.total_entries_central_dir = makeword( & byterec[TOTAL_ENTRIES_CENTRAL_DIR] );
  pG->ecrec.size_central_directory = makelong( & byterec[SIZE_CENTRAL_DIRECTORY] );
  pG->ecrec.offset_start_central_directory = makelong( & byterec[OFFSET_START_CENTRAL_DIRECTORY] );
  pG->ecrec.zipfile_comment_length = makeword( & byterec[ZIPFILE_COMMENT_LENGTH] );
  pG->expect_ecrec_offset = pG->ecrec.offset_start_central_directory + pG->ecrec.size_central_directory;
  return PK_COOL;
}

/* end function find_ecrec() */


/* ===========================================================================
*                    Function uz_end_central()
* Get the zipfile comment (up to 64KB long), if any, and print it out.
* Then position the file pointer to the beginning of the central directory
* and fill buffer.
* Return PK-type error code.
*/
int uz_end_central( struct UGlobals * pG )
{
  int error = PK_COOL;

  if ( pG->ecrec.zipfile_comment_length && ( pG->zflag > 0 || ( pG->zflag == 0 &&
#ifdef TIMESTAMP
       !pG->T_flag &&
#endif
       !pG->qflag ) ) )
  {
    if ( do_string( pG, pG->ecrec.zipfile_comment_length, DISPLAY ) )
    {
      Notify( PF, 0,  "zip file comment too long" );
      error = PK_WARN;
    }
  }
  return error;
}

/* end function uz_end_central() */


/* ===========================================================================
*                      Function process_cdir_file_hdr()
* Return PK-type error code.
* cdir = central dir of zipfile.
*/
int process_cdir_file_hdr( struct UGlobals * pG )
{
  int error;

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "in process_cdir_file_hdr()" );

  /*---------------------------------------------------------------------------
  * Get central directory info, save host and method numbers, and set flag
  * for lowercase conversion of filename, depending on the OS from which the
  * file is coming.
  *---------------------------------------------------------------------------*/
  if ( ( error = get_cdir_ent( pG ) ) != 0 )
  {
    if (pG->Frame.Verbose)// < 0)
      Notify( PF, ITRACE, "Error returned by get_cdir_ent call" );
    return error;
  }
  pG->pInfo->hostnum = MIN( pG->crec.version_made_by[1], NUM_HOSTS );
  pG->pInfo->lcflag = 0;

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "Good entry; hostnum of file = %d", pG->pInfo->hostnum   );
  if ( pG->L_flag ) /* if user specified case-conversion */
    switch ( pG->pInfo->hostnum )
    {
      case FS_FAT_:
        /* PKZIP and zip -k store in uppercase */
      case CPM_:
        /* like MS-DOS, right? */
      case VM_CMS_:
        /* all caps? */
      case MVS_:
        /* all caps? */
      case TOPS20_:
      case VMS_:
        /* our Zip uses lowercase, but asi's doesn't */
        pG->pInfo->lcflag = 1;
        /* convert filename to lowercase */
        break;

      default:
        /* AMIGA_, FS_HPFS_, FS_NTFS_, MAC_, UNIX_, ATARI_, */
        break;
        /* FS_VFAT_, BEBOX_ (Z_SYSTEM_):  no conversion */
    }

  /* is there a volume label? */
  if ( IS_VOLID( pG->crec.external_file_attributes )
       && ( pG->pInfo->hostnum == FS_FAT_ || pG->pInfo->hostnum == FS_HPFS_ || pG->pInfo->hostnum == FS_NTFS_
            || pG->pInfo->hostnum == ATARI_ ) )
  {
    pG->pInfo->vollabel = true;
    pG->pInfo->lcflag = 0;
    /* preserve case of volume labels */
  }
  else
    pG->pInfo->vollabel = false;
  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "process_cdir_file_hdr returning PK_COOL" );
  return PK_COOL;
}

/* end function process_cdir_file_hdr() */


/* ===========================================================================
*                          Function get_cdir_ent()
* Return PK-type error code.
*/
int get_cdir_ent( struct UGlobals * pG )
{
  cdir_byte_hdr byterec;

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "in get_cdir_ent" );

  /*---------------------------------------------------------------------------
  * Read the next central directory entry and do any necessary machine-type
  * conversions (byte ordering, structure padding compensation--do so by
  * copying the data from the array into which it was read (byterec) to the
  * usable struct (crec)).
  *---------------------------------------------------------------------------*/
  if ( readbuf( pG, ( char * ) byterec, CREC_SIZE ) == 0 )
  {
    if (pG->Frame.Verbose)// < 0)
      Notify( PF, ITRACE, "no name found" );
    return PK_EOF;
  }

  pG->crec.version_made_by[0] = byterec[C_VERSION_MADE_BY_0];
  pG->crec.version_made_by[1] = byterec[C_VERSION_MADE_BY_1];
  pG->crec.version_needed_to_extract[0] = byterec[C_VERSION_NEEDED_TO_EXTRACT_0];
  pG->crec.version_needed_to_extract[1] = byterec[C_VERSION_NEEDED_TO_EXTRACT_1];

  pG->crec.general_purpose_bit_flag = makeword( & byterec[C_GENERAL_PURPOSE_BIT_FLAG] );
  pG->crec.compression_method = makeword( & byterec[C_COMPRESSION_METHOD] );
  pG->crec.last_mod_file_time = makeword( & byterec[C_LAST_MOD_FILE_TIME] );
  pG->crec.last_mod_file_date = makeword( & byterec[C_LAST_MOD_FILE_DATE] );
  pG->crec.crc32 = makelong( & byterec[C_CRC32] );
  pG->crec.csize = makelong( & byterec[C_COMPRESSED_SIZE] );
  pG->crec.ucsize = makelong( & byterec[C_UNCOMPRESSED_SIZE] );
  pG->crec.filename_length = makeword( & byterec[C_FILENAME_LENGTH] );
  pG->crec.extra_field_length = makeword( & byterec[C_EXTRA_FIELD_LENGTH] );
  pG->crec.file_comment_length = makeword( & byterec[C_FILE_COMMENT_LENGTH] );
  pG->crec.disk_number_start = makeword( & byterec[C_DISK_NUMBER_START] );
  pG->crec.internal_file_attributes = makeword( & byterec[C_INTERNAL_FILE_ATTRIBUTES] );
  pG->crec.external_file_attributes = makelong( & byterec[C_EXTERNAL_FILE_ATTRIBUTES] );
  /* LONG, not word! */
  pG->crec.relative_offset_local_header = makelong( & byterec[C_RELATIVE_OFFSET_LOCAL_HEADER] );

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "End of get_cdir_ent in process.c. Found filename of len %d", pG->crec.filename_length  );

  return PK_COOL;
}

/* end function get_cdir_ent() */


/* ===========================================================================
*                           Function process_local_file_hdr()
*/
int process_local_file_hdr( struct UGlobals * pG )
{
  /* return PK-type error code */
  local_byte_hdr byterec;

  /*---------------------------------------------------------------------------
  * Read the next local file header and do any necessary machine-type con-
  * versions (byte ordering, structure padding compensation--do so by copy-
  * ing the data from the array into which it was read (byterec) to the
  * usable struct (lrec)).
  *---------------------------------------------------------------------------*/
  if ( readbuf( pG, ( char * ) byterec, LREC_SIZE ) == 0 )
    return PK_EOF;

  pG->lrec.version_needed_to_extract[0] = byterec[L_VERSION_NEEDED_TO_EXTRACT_0];
  pG->lrec.version_needed_to_extract[1] = byterec[L_VERSION_NEEDED_TO_EXTRACT_1];

  pG->lrec.general_purpose_bit_flag = makeword( & byterec[L_GENERAL_PURPOSE_BIT_FLAG] );
  pG->lrec.compression_method = makeword( & byterec[L_COMPRESSION_METHOD] );
  pG->lrec.last_mod_file_time = makeword( & byterec[L_LAST_MOD_FILE_TIME] );
  pG->lrec.last_mod_file_date = makeword( & byterec[L_LAST_MOD_FILE_DATE] );
  pG->lrec.crc32 = makelong( & byterec[L_CRC32] );
  pG->lrec.csize = makelong( & byterec[L_COMPRESSED_SIZE] );
  pG->lrec.ucsize = makelong( & byterec[L_UNCOMPRESSED_SIZE] );
  pG->lrec.filename_length = makeword( & byterec[L_FILENAME_LENGTH] );
  pG->lrec.extra_field_length = makeword( & byterec[L_EXTRA_FIELD_LENGTH] );

  pG->csize = ( long )pG->lrec.csize;
  pG->ucsize = ( long )pG->lrec.ucsize;

  if ( ( pG->lrec.general_purpose_bit_flag & 8 ) != 0 )
  {
    /* can't trust local header, use central directory: */
    pG->lrec.crc32 = pG->pInfo->crc;
    pG->csize = ( long )( pG->lrec.csize = pG->pInfo->compr_size );   
    pG->ucsize = ( long )( pG->lrec.ucsize = pG->pInfo->uncomp_size );
  }
  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "process_local_file_hdr of process.c found fname len of %d", pG->lrec.filename_length   );
  return PK_COOL;
}

/* end function process_local_file_hdr() */


#ifdef USE_EF_UX_TIME
/* ===========================================================================
*                               Function ef_scan_for_izux()
* This function scans the extra field for a IZUNIX block containing
* Unix style time_t (GMT) values for the entry's access and modification
* time.  If a valid block is found, both time stamps are copied to the
* ztimebuf structure (provided the z_utim pointer is not NULL).
* If the IZUNIX block contains UID/GID fields and the z_uidgid array
* pointer is valid (!= NULL), the owner info is transfered as well.
* The return value is the size of the IZUNIX block found, or 0 in case
* of failure.
*
*ef_buf   :: Buffer containing extra field. ef_len   :: Total length of extra field.
*z_utim   :: Return storage: atime and mtime.
*z_uidgid :: Return storage: uid and gid. */
unsigned ef_scan_for_izux( uch * ef_buf, unsigned ef_len, ztimbuf * z_utim, ush * z_uidgid )
{
  unsigned r = 0;
  unsigned eb_id;
  unsigned eb_len;

  if ( ef_len == 0 || ef_buf == NULL )
    return 0;

  //  TTrace( ( pG, "ef_scan_ux_: scanning extra field of length %u", ef_len ) );
  while ( ef_len >= EB_HEADSIZE )
  {
    eb_id = makeword( EB_ID + ef_buf );
    eb_len = makeword( EB_LEN + ef_buf );
    if ( eb_len > ( ef_len - EB_HEADSIZE ) )
    {
      /* Discovered some extra field inconsistency! */
      //      TTrace( ( pG, "ef_scan_for_izux: block length %u > rest ef_size %u", eb_len, ef_len - EB_HEADSIZE ) );
      break;
    }
    if ( eb_id == EF_IZUNIX && eb_len >= EB_UX_MINLEN )
    {
      //      TTrace( ( pG, "ef_scan_ux_time: Found IZUNIX extra field" ) );
      if ( z_utim != NULL )
      {
        z_utim->actime = makelong( ( EB_HEADSIZE + EB_UX_ATIME ) + ef_buf );
        z_utim->modtime = makelong( ( EB_HEADSIZE + EB_UX_MTIME ) + ef_buf );
        //        TTrace( ( pG, "  Unix EF access time = %ld", z_utim->actime ) );
        //        TTrace( ( pG, "  Unix EF modif. time = %ld", z_utim->modtime ) );
      }
      if ( eb_len >= EB_UX_FULLSIZE && z_uidgid != NULL )
      {
        z_uidgid[0] = makeword( ( EB_HEADSIZE + EB_UX_UID ) + ef_buf );
        z_uidgid[1] = makeword( ( EB_HEADSIZE + EB_UX_GID ) + ef_buf );
      }
      r = eb_len;
      /* signal success */
      break;
    }
    /* Skip this extra field block */
    ef_buf += ( eb_len + EB_HEADSIZE );
    ef_len -= ( eb_len + EB_HEADSIZE );
  }
  return r;
}
#endif /* USE_EF_UX_TIME */
