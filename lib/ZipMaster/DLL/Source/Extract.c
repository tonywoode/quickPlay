#include <windows.h>
#include "Common.h"
#pragma hdrstop
/* This version modified by Chris Vleghert and Eric W. Engler * for BCB/Delphi Zip, Sep 22, 2000.
* RP - corrected resolve filenames (update bug) Jul 12, 2002 * RP - speeded up selection of files 22 Sep, 2002
* RP - eliminated need to search filespecs twice
* RP - changed store_info to return 0 = ok else reason to skip
*/

/*--------------------------------------------------------
* extract.c
* This file contains the high-level routines ("driver routines") for extrac-
* ting and testing zipfile members.  It calls the low-level routines in files
* explode.c, inflate.c, unreduce.c and unshrink.c.
* Contains:  extract_or_test_files()
*            store_info()   -> StoreInfo()
*            extract_or_test_member()
*            TestExtraField()   RCV Removed
*            MemExtract()
*            MemFlush()
*            fnfilter()
*-------------------------------------------------------------------------*/
#include "unzip.h"
#include "ucrypt.h"

static int StoreInfo( struct UGlobals * pG );
//static int store_info( struct UGlobals * pG );
static int extract_or_test_member( struct UGlobals * pG );
static void CloseOut( struct UGlobals * pG );

// static int TestExtraField( struct UGlobals *pG, uch *ef, unsigned ef_len );  // RCV Removed


// yy::Extract=01, Add=02  zz::skip reason  yyzz        RCV: 1.610
#define SKIPPED_ON_FRESHEN                              0x0101
#define SKIPPED_NO_OVERWRITE                            0x0102
#define SKIPPED_FILE_EXISTS                             0x0103
#define SKIPPED_BAD_PASSWORD                            0x0104
#define SKIPPED_NO_ENCRYPTION                           0x0105
#define SKIPPED_COMPRESSION_UNKNOWN                     0x0106
#define SKIPPED_UNKNOWN_ZIPHOST                         0x0107
#define SKIPPED_FILEFORMAT_WRONG                        0x0108
#define SKIPPED_EXTRACT_ERROR                           0x0109

union _I64
{
  unsigned __int64 i64;
  unsigned long l[2];
};

#  define NEXTBYTE  (--pG->incnt >= 0 ? (int)(*pG->inptr++) : readbyte( pG ))

/* ==================
*    Function extract_or_test_files()
*/
static int Read_Central_Member( struct UGlobals *pG, int *error_in_archive)
{
  int error;
  if ( readbuf( pG, pG->sig, 4 ) == 0 )
  {
    *error_in_archive = PK_EOF;
    return UEN_EOF02;
  }
  // validate the central hdr signature:
//  if (pG->sig != pG->central_hdr_sig)
  if ( strncmp( pG->sig, pG->central_hdr_sig, 4 ) )
  {
    /* just to make sure */
    *error_in_archive = PK_BADERR;
    return UEN_FORM01;
  }
  /* process_cdir_file_hdr() in process.c, sets pInfo->hostnum and pInfo->lcflag */
  if ( ( error = process_cdir_file_hdr( pG ) ) != PK_COOL )
  {
    if (pG->Frame.Verbose )
      Notify( PF, ITRACE, "a 'not cool' error in archive" );
    return UEN_FORM02;
  }
  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "back in extract_or_test_files" );
  if ( ( error = do_string( pG, pG->crec.filename_length, DS_FN ) ) != PK_COOL )
  {
    if ( error > *error_in_archive )
      *error_in_archive = error;
    if ( error > PK_WARN )
    {
      /* fatal:  no more left to do */
      UnzErr( pG, UEN_FORM03 );
      return UEN_FORM03;
    }
    Notify( PF, IWARNING, "error %d on file: %s", error, pG->filename );
  }
  if ( ( error = do_string( pG, pG->crec.extra_field_length, EXTRA_FIELD ) ) != 0 )
  {
    if ( error > *error_in_archive )
      *error_in_archive = error;
    if ( error > PK_WARN )
    {
      return UEN_FORM04;
    }
    Notify( PF, IWARNING,  "error %d on file: %s", error, pG->filename );
  }
  if ( ( error = do_string( pG, pG->crec.file_comment_length, SKIP ) ) != PK_COOL )
  {
    if ( error > *error_in_archive )
      *error_in_archive = error;
    if ( error > PK_WARN )
    {
      /* fatal */
      return UEN_FORM05;
    }
    Notify( PF, IWARNING,  "error %d on file: %s", error, pG->filename );
  }
  return 0;
}

int extract_or_test_files( struct UGlobals * pG )
{
  /* return PK-type error code */
  uch * cd_inptr;
  int i, j = 0, cd_incnt, filnum = ( -1 ), blknum = 0;
  int error, error_in_archive = PK_COOL;
  unsigned members_remaining, num_skipped = 0, num_bad_pwd = 0;
  int why_skipped = 0;
  unsigned long cd_bufstart, bufstart, inbuf_offset, request;
  long old_extra_bytes = 0L;
  long fsize;

//  union _I64
  _I64 TotSize;
  unsigned fspecs;

  char * SkippingArray; // array of skipped file indexes nz = skip
  char * SkipIt; // pointer to SkippingArray
  unsigned SkipArraySize; // number of entries
#define SKIPREST  {while (SkipIt<(SkippingArray+SkipArraySize)) *SkipIt++=-1;}

  int changed;
  /*---------------------------------------------------------------------------
  * Since the central directory lies at the end of the zipfile, and the
  * member files lie at the beginning or middle or wherever, it is not very
  * efficient to read a central directory entry, jump to the member file
  * and extract it, and then jump back to the central directory.
  *
  * Instead, we read from the central directory the pertinent information
  * for a block of files, then go extract/test the whole block.  Thus, this
  * routine contains two small(er) loops within a very large outer loop:
  * the first of the small ones reads a block of files from the central
  * directory; the second extracts or tests each file; and the outer one
  * loops over blocks.
  *
  * Because of this jumping around, we can afford to be lenient if an
  * error occurs in one of the member files:  we should still be able to
  * go find the other members, since we know the offset of each from the
  * beginning of the zipfile.
  *---------------------------------------------------------------------------*/
  TotSize.i64 = 0;
  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "in extract_or_test_files" );
  pG->pInfo = pG->info;
  // We're going to check each member file inside the archive
  members_remaining = pG->ecrec.total_entries_central_dir;
  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "members_remaining = %d, unmatched fspecs = %d", members_remaining, pG->filespecs   );

# ifdef CRYPT
  pG->newzip = true;
  pG->reported_backslash = false;
# endif

  SkipArraySize = ( pG->ecrec.total_entries_central_dir * sizeof( char ) ) + 1;
  if ( ( SkippingArray = (char *) MALLOC( SkipArraySize ) ) != NULL )
  {
    setmem( SkippingArray, SkipArraySize, pG->process_all_files ? 0 : -1 );
  }
  // R.Peters - change to optimise file search
  if ( !pG->process_all_files )
  {
    if ( pG->filespecs > 0 && pG->pfnames )
    {
      UnzFileData * pfn = ( UnzFileData * ) pG->pfnames;
      for ( i = 0; i < pG->filespecs; i++ )
      { // initial -1= wild, 1=check
        if (*pfn->fFileSpec)   /* log */
          pfn->fMatch = iswild( pfn->fFileSpec ) ? -1 : 1;
        else
          pfn->fMatch = 0;
        pfn++;
      }
    }
  }

  /*---------------------------------------------------------------------------
  *  RCV Added: Calculate number of files to process and the total file size.
  *---------------------------------------------------------------------------*/
  cd_bufstart = pG->cur_zipfile_bufstart;
  cd_inptr = pG->inptr;
  cd_incnt = pG->incnt;
  fspecs = pG->filespecs;
  pG->pInfo = & pG->info[0];
  /* Needed in process... */
  SkipIt = SkippingArray; //-1;    // before start
  while ( members_remaining && !pG->Frame.Abort_Flag )
  {
    int DoThisFile = false;
    //    ++SkipIt;

    members_remaining--;
    if ( readbuf( pG, pG->sig, 4 ) == 0 )
      break;
    if ( strncmp( pG->sig, pG->central_hdr_sig, 4 ) )
      break;
    if ( ( error = process_cdir_file_hdr( pG ) ) != PK_COOL )
      break;
    do_string( pG, pG->crec.filename_length, DS_FN );
    do_string( pG, pG->crec.extra_field_length + pG->crec.file_comment_length, SKIP );
    if ( pG->process_all_files )
      DoThisFile = true;
    else
    {
      UnzFileData * pfn = ( UnzFileData * ) pG->pfnames;
      int k = 0;

      // R.Peters - new search
      for ( ; k < pG->filespecs; k++, ++pfn )
      {
        if ( pfn->fMatch )
        {
          if ( match( pG->filename, pfn->fFileSpec ) )
          {
            DoThisFile = true;
            if ( ( ( pfn->fMatch &= -2 ) == 0 ) && // reset bit 0 for match
                 ( ! --fspecs ) ) // removed non-wild from search
            {
              members_remaining = 0; // none left to match
              /*              { char *skp = SkipIt;         // set to skip rest
              while (++skp<=(SkippingArray+SkipArraySize)) *skp=-1; }  */
            }
            if (pG->Frame.Verbose < 0)
              Notify( PF, ITRACE, "Matched %s", pG->filename   );
            break;
            /* found match, so stop looping */
          }
        }
      }
    }
    /* if ( DoThisFile && !StoreInfo( pG ))//store_info( pG ) ) { j++; TotSize.i64 += pG->crec.ucsize; } */
    if ( DoThisFile )
    {
      int r;
      if ( ( r = StoreInfo( pG ) ) == 0 ) // only test
      {
        j++;
        TotSize.i64 += pG->crec.ucsize;
      }
      else
      {
        _CB_.Arg1 = 0;
        _CB_.Arg2 = r;
        _CB_.MsgP = pG->filename;
        User_CB(PF, zacSkipped);
        ++num_skipped;
        if ( !why_skipped )
          why_skipped = r;
        else
          if ( why_skipped != r )
            why_skipped = -1;
      }
      * SkipIt++ = ( char )r;
    }
    else
      * SkipIt++ = -1; // not selected
  }
  _CB_.Arg1 = j;
  User_CB(PF, zacCount);
  _CB_.FileSize = TotSize;
  User_CB(PF, zacSize);

  // RCV Changed 29-1-99 USE_STREAM_INPUT
  pG->cur_zipfile_bufstart = vclSeek( pG, ( long )cd_bufstart, SEEK_SET );
  vclRead( pG, ( char * ) pG->inbuf, INBUFSIZ );

  pG->inptr = cd_inptr;
  pG->incnt = cd_incnt;

  members_remaining = pG->ecrec.total_entries_central_dir;

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "starting main loop" );

  /*---------------------------------------------------------------------------
  *    Begin main loop over blocks of member files.
  *---------------------------------------------------------------------------*/
  SkipIt = SkippingArray; // start of selected files (>0)
  while ( members_remaining && !pG->Frame.Abort_Flag )
  {
    j = 0;

    /* Loop through files in central directory, storing offsets, file
    * attributes, case-conversion and text-conversion flags until block * size is reached. */

    /* ========================================================== */
    while ( members_remaining && ( j < DIR_BLKSIZ ) && !pG->Frame.Abort_Flag )
    {
      int rr;
      --members_remaining;
      pG->pInfo = & pG->info[j];

      if (pG->Frame.Verbose  < 0)
        Notify( PF, ITRACE, "New iter: members_remaining after this pass = %d", members_remaining   );
      pG->pInfo->chdrseq = ( ush )( pG->ecrec.total_entries_central_dir - members_remaining - 1 );

      if ((rr = Read_Central_Member( pG, &error_in_archive )) != 0)
      {
        UnzErr( pG, rr );
        //        error_in_archive = PK_EOF;
        members_remaining = 0;
        SKIPREST /* ...so no more left to do */
        break;
      }
      if ( * SkipIt == 0 )
      {
        int r;
        if ( ( r = StoreInfo( pG ) ) == 0 )
        {
          char *fn = (char *) MALLOC(lstrlen(pG->filename)+1);
          lstrcpy(fn, pG->filename);
          pG->pInfo->filename = fn;
          if (pG->Frame.Verbose)// < 0)
            Notify( PF, ITRACE, "file is OK: %s", pG->filename   );
          ++j;
          /* file is OK; info[] stored; continue with next */
        }
        else
        { // should not get here
          if (pG->Frame.Verbose < 0)
            Notify( PF, ITRACE, "Skipped: %s (%d)!!", pG->filename, r   );
          ++num_skipped;
          * SkipIt = ( char )r;
        }
      }
      SkipIt++;
    }  // while ( members_remaining && ( j < DIR_BLKSIZ
    /* end while-loop (adding files to current block) */

    /* save position in central directory so can come back later */
    cd_bufstart = pG->cur_zipfile_bufstart;
    cd_inptr = pG->inptr;
    cd_incnt = pG->incnt;

    if ( pG->Frame.Verbose) //vflag > 0 || pG->global_trace_opt )
      //      DLLprintf(
      Notify( PF, IMSG,  "DLL expects to %s %d files", pG->tflag ? "test" : "extract", j );

    /*-----------------------------------------------------------------------
    *  Second loop:  process files in current block, extracting or testing
    *  each one.
    *-----------------------------------------------------------------------*/
    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "starting second loop - THIS TIME we take action." );

    for ( i = 0; i < j; ++i )
    {
      if (pG->Frame.Abort_Flag)
        break;
      filnum = i + blknum * DIR_BLKSIZ;
      pG->pInfo = & pG->info[i];

      //          NOVELL_BUG_FAILSAFE:
//      pG->dne = false;
      /* assume file exists until stat() says otherwise */

      /* if the target position is not within the current input buffer
      * (either haven't yet read far enough, or (maybe) skipping back-
      * ward), skip to the target position and reset readbuf(). */
      request = pG->pInfo->offset + pG->extra_bytes;
      inbuf_offset = request % INBUFSIZ;
      bufstart = request - inbuf_offset;

      if (pG->Frame.Verbose < 0)
        Notify( PF, ITRACE, "loc A: request = %ld, inbuf_offset = %ld", request, inbuf_offset   );
      //            if ( request < 0 )
      if ( request < pG->pInfo->offset )
      {
        UnzErr( pG, UEN_FORM06 );
        error_in_archive = PK_ERR;
        if ( filnum == 0 && pG->extra_bytes != 0L )
        {
          Notify( PF, IMSG,  "attempting to recompensate" );
          old_extra_bytes = pG->extra_bytes;
          pG->extra_bytes = 0L;
          request = pG->pInfo->offset;
          /* could also check if this != 0 */
          inbuf_offset = request % INBUFSIZ;
          bufstart = request - inbuf_offset;
          if (pG->Frame.Verbose < 0)
            Notify( PF, ITRACE, "loc B: request = %ld, inbuf_offset = %ld", request, inbuf_offset );// );
        }
        else
        {
          error_in_archive = PK_BADERR;
          if (pG->Frame.Verbose)// < 0)
            Notify( PF, ITRACE, "loc A: hosed - try next file" );
          continue;
          /* this one hosed; try next */
        }
      }

      /* try again */
      if ( request < 0 )
      {
        if (pG->Frame.Verbose < 0)
          Notify( PF, 0, "the recompensated request is still < 0");
        UnzErr( pG, UEN_FORM07 );
        error_in_archive = PK_BADERR;
        continue;
      }
      else
        if ( bufstart != pG->cur_zipfile_bufstart )
        {
          if (pG->Frame.Verbose < 0)
            Notify( PF, ITRACE, "bufstart != cur_zipfile_bufstart"   );

          // RCV Changed 29-1-99 USE_STRM_INPUT
          pG->cur_zipfile_bufstart = vclSeek( pG, ( long )bufstart, SEEK_SET );
          pG->incnt = vclRead( pG, ( char * ) pG->inbuf, INBUFSIZ );
          if ( pG->incnt <= 0 )
          {
            UnzErr( pG, UEN_FORM08 );
            error_in_archive = PK_BADERR;
            if (pG->Frame.Verbose )//< 0)
              Notify( PF, ITRACE, "B. hosed - try next file" );
            continue;
            /* can still do next file */
          }
          pG->inptr = pG->inbuf + ( int )inbuf_offset;
          pG->incnt -= ( int )inbuf_offset;
        }
        else
        {
          pG->incnt += ( int )( pG->inptr - pG->inbuf ) - ( int )inbuf_offset;
          pG->inptr = pG->inbuf + ( int )inbuf_offset;
        }
      /* should be in proper position now, so check for sig */
      if ( readbuf( pG, pG->sig, 4 ) == 0 )
      {
        /* bad offset */
        UnzErr( pG, UEN_FORM09 );
        error_in_archive = PK_BADERR;
        continue;      /* but can still try next one */

      }
      if ( strncmp( pG->sig, pG->local_hdr_sig, 4 ) )
      {
        UnzErr( pG, UEN_FORM10 );
        error_in_archive = PK_ERR;
        if ( ( filnum == 0 && pG->extra_bytes != 0L )
             || ( pG->extra_bytes == 0L && old_extra_bytes != 0L ) )
        {
          Notify( PF, IMSG,  "Attempting to Recompensate" );
          if ( pG->extra_bytes )
          {
            old_extra_bytes = pG->extra_bytes;
            pG->extra_bytes = 0L;
          }
          else
            pG->extra_bytes = old_extra_bytes;
          /* third attempt */
          ZLSEEK( pG->pInfo->offset )
          if ( readbuf( pG, pG->sig, 4 ) == 0 )
          {
            /* bad offset */
            UnzErr( pG, UEN_FORM11 );
            error_in_archive = PK_BADERR;
            continue;         /* but can still try next one */

          }
          if ( strncmp( pG->sig, pG->local_hdr_sig, 4 ) )
          {
            UnzErr( pG, UEN_FORM12 );
            error_in_archive = PK_BADERR;
            continue;
          }
        }
        else
        {
          if (pG->Frame.Verbose )//< 0)
            Notify( PF, ITRACE, "C: hosed - try next file" );
          continue;          /* this one hosed; try next */
        }
      }
      if (pG->Frame.Verbose < 0)
        Notify( PF, ITRACE, "about to process local file hdr" );
      if ( ( error = process_local_file_hdr( pG ) ) != PK_COOL )
      {
        UnzErr( pG, UEN_FORM13 );
        error_in_archive = error;
        /* only PK_EOF defined */
        if (pG->Frame.Verbose)// < 0)
          Notify( PF, ITRACE, "D. hosed - try next file" );
        continue;         /* can still try next one */
      }
      if ( ( error = do_string( pG, pG->lrec.filename_length, DS_FN ) ) != PK_COOL )
      {
        if ( error > error_in_archive )
          error_in_archive = error;
        if ( error > PK_WARN )
        {
          UnzErr( pG, UEN_FORM14 );
          if (pG->Frame.Verbose)// < 0)
            Notify( PF, ITRACE, "E. hosed - try next file" );
          continue;       /* go on to next one */
        }
      }
      //      Trace( ( pG, "Good entry for: %s", pG->filename ) );
      if (pG->Frame.Verbose)
        Notify( PF, 0, "Read local filename %s", pG->filename );

      if ( pG->extra_field != ( uch * ) NULL )
      {
        FREE( pG->extra_field );
        pG->extra_field = ( uch * ) NULL;
      }
      if ( ( error = do_string( pG, pG->lrec.extra_field_length, EXTRA_FIELD ) ) != 0 )
      {
        if ( error > error_in_archive )
          error_in_archive = error;
        if ( error > PK_WARN )
        {
          UnzErr( pG, UEN_FORM15 );
          if (pG->Frame.Verbose)// < 0)
            Notify( PF, ITRACE, "F. hosed - try next file" );
          continue;
          /* go on */
        }
      }
      /* Just about to extract file:  if extracting to disk, check if
      * already exists, and if so, take appropriate action according to
      * fflag/uflag/overwrite_all/etc. (we couldn't do this in upper
      * loop because we don't store the possibly renamed filename[] in
      * info[]) */
      // use central name
      if (lstrcmp(pG->filename, pG->pInfo->filename) != 0)
      {
        error = PK_WARN;
        Notify( PF, IWARNING, "Names do not match - using '%s' [local:%s]", pG->pInfo->filename, pG->filename);
        if ( error > error_in_archive )
          error_in_archive = error;
        lstrcpy(pG->filename, pG->pInfo->filename);
      }
      if ( !pG->tflag
# ifdef USE_STRM_OUTPUT
           && !pG->redirect_data
#endif
         )
      {
        /* for files from DOS FAT, check for use of backslash instead
        * of slash as directory separator (bug in some zipper(s); so
        * far, not a problem in HPFS, NTFS or VFAT systems) */
        if ( pG->pInfo->hostnum == FS_FAT_ && !strchr( pG->filename, '/' ) )
        {
          char * p = pG->filename - 1;

          if (pG->Frame.Verbose < 0)
            Notify( PF, ITRACE, "parsing a FAT file" );
          while ( * ++p )
          {
            if ( * p == (char)'\\' )
            {
              if ( !pG->reported_backslash )
              {
                UnzErr( pG, UEN_FORM16 );
                pG->reported_backslash = true;
                if ( !error_in_archive )
                  error_in_archive = PK_WARN;
              }
              * p = '/';
            }
          }
        }
        _CB_.MsgP2 = 0;         // no string
        _CB_.MsgP = pG->filename;
        User_CB(PF, zacExtName);

        changed = 0;
        if (_CB_.ActionCode == -1)      // changed
        {
          if (!_CB_.Msg[0])
          {
            if (pG->Frame.Verbose )//< 0)
              Notify( PF, ITRACE, "file ignored - try next file" );
            error_in_archive = PK_ERR;
            continue; // try next
          }
          lstrcpy( pG->filename, _CB_.Msg );
          changed++;
          if ( pG->Frame.Verbose)
            Notify( PF, IVERBOSE,  "filename changed to %s", pG->filename );
        }

        /* Mapname can create dirs if not freshening or if renamed */
        if ( ( error = mapname(pG, changed) ) > PK_WARN )
        {
          if ( error == IZ_CREATED_DIR )
          {
            /* GRR:  add code to set times/attribs on dirs--
            * save to list, sort when done (a la zip), set
            * times/attributes on deepest dirs first */
          }
          else
            if ( error == IZ_VOL_LABEL )
            {
              if (pG->Frame.Verbose)// < 0)
                Notify( PF, ITRACE, "file is a vol label" );
              UnzErr( pG, UEN_FORM17 );
            }
            else
              if ( error > PK_ERR && error_in_archive < PK_ERR )
              {
                if (pG->Frame.Verbose)// < 0)
                  Notify( PF, ITRACE, "pG-> hosed - try next file" );
                error_in_archive = PK_ERR;
              }
          if (pG->Frame.Verbose < 0)
            Notify( PF, ITRACE, "mapname(%s) returns error = %d", pG->filename, error   );
          continue;
          /* go on to next file */
        }

        // filename contains the name as stored in the archive if the user want
        // to extract directories too then this part of the path is also present.
        // So we only need to complement it with the currentdir or the extractbasedir.
        lstrcpy( pG->filename, GetFullPath( pG, pG->filename ) ); // v1.6024
        /* Now is the time to possibly adjust the filename and/or path v1.6016 */
        _CB_.MsgP2 = 0;         // no string
        _CB_.MsgP = pG->filename;
        User_CB(PF, zacNewName);
        // pfp = GetFullPath( pG, pG->filename);  // 1.75
        // if (pG->global_trace_opt)
        //   MyTrace( pG, "filename is %s", pfp);
        /* Now is the time to possibly adjust the filename and/or path v1.6016 */
        if (_CB_.ActionCode == -1)      // changed
        {
          lstrcpy( pG->filename, _CB_.Msg);
          if ( pG->Frame.Verbose < 0)
            Notify( PF, ITRACE, "filename changed to %s", pG->filename );
        }
//        else
//          lstrcpy( pG->filename, GetFullPath( pG, pG->filename ) );
        // v1.6024
        pG->lrec.filename_length = ( ush )lstrlen( pG->filename );
        //                }

        if ( pG->Frame.Abort_Flag )
        { // v1.6024
          UnzErr( pG, UEN_ABORT02 );
          break;
        }

        if (pG->Frame.Verbose < 0)
          Notify( PF, ITRACE, "starting switch near Novell failsafe in extract.c" );
        switch ( check_for_newer( pG, pG->filename ) )
        {
/*          case -2:
            _CB_.Arg1 = 0;//UEN_MISC06;  
            _CB_.Arg2 = 10; // bad name
            _CB_.MsgP = pG->filename;
            User_CB(PF, zacSkipped);
            if (pG->Frame.Verbose)// < 0)
                Notify( PF, ITRACE, "error: Invalid name \"%s\" occured while extracting or testing",
                   pG->filename);
              continue;
//              break;
 */
          case DOES_NOT_EXIST:
            // NOVELL_BUG_FAILSAFE:
//            pG->dne = true;
            /* stat() says file DOES NOT EXIST */
            /* if freshening, don't skip if just renamed */
            if ( pG->fflag )
            {
//              User(PF, zacSkipped, 0, SKIPPED_ON_FRESHEN, pG->filename );
              _CB_.Arg1 = 0;
              _CB_.Arg2 = SKIPPED_ON_FRESHEN;
              _CB_.MsgP = pG->filename;
              User_CB(PF, zacSkipped);
              continue;
              /* freshen (no new files):  skip */
            }
            break;

          case EXISTS_AND_OLDER:
            // Ask the user what to do, take overwrite_all as default. RCV: 1.6010
            _CB_.Arg3 = 1;
            _CB_.Arg2 = pG->pInfo->chdrseq;
            _CB_.Arg1 = pG->overwrite_all;
            _CB_.MsgP = pG->filename;
            User_CB(PF, zacOverwrite);
            if (_CB_.ActionCode >= 0)           // no response - use default
              _CB_.ActionCode = pG->overwrite_all ? -1 : -2;
            if (_CB_.ActionCode < -1)          // responded 'no'
            {
              _CB_.Arg1 = 0;
              _CB_.Arg2 = SKIPPED_NO_OVERWRITE;
              _CB_.MsgP = pG->filename;
              User_CB(PF, zacSkipped);
              if (pG->Frame.Verbose)
                Notify( PF, ITRACE, "File exists: %s, overwrite false", pG->filename   );
              continue;
              /* never overwrite:  skip file */
            }
            break;

          case EXISTS_AND_NEWER:
            /* or equal */
            // Ask the user what to do, take overwrite_all as default. RCV: 1.6010
            // If no event handler present w'll keep the default.
            _CB_.Arg3 = 2;
            _CB_.Arg2 = pG->pInfo->chdrseq;
            _CB_.Arg1 = pG->overwrite_all && !( pG->uflag || pG->fflag );
            _CB_.MsgP = pG->filename;
            User_CB(PF, zacOverwrite);
            if (_CB_.ActionCode >= 0)           // no response - use default
              _CB_.ActionCode = _CB_.Arg1 ? -1 : -2;
            if (_CB_.ActionCode == -2)			// skip
            {
              _CB_.Arg1 = 0;
              _CB_.Arg2 = SKIPPED_FILE_EXISTS;
              _CB_.MsgP = pG->filename;
              User_CB(PF, zacSkipped);
              if (pG->Frame.Verbose )//< 0)
                Notify( PF, ITRACE, "File exists: %s, skipped", pG->filename  );
              continue;
              /* skip if update/freshen & orig name */
            }
            break;
        }
        /* end switch */
      }
      /* end if (extracting to disk) */

# ifdef CRYPT
      if (pG->Frame.Verbose < 0)
      {
        Notify( PF, ITRACE, "in extract.c, about to call decrypt"   ); //EWE
        /*       if ( ( pG->pwdarg != NULL ) && ( lstrlen( pG->pwdarg ) > 0 ) )
                 Inform( pG, ITRACE, "pG->pwdarg=%s", pG->pwdarg   );
               else
                 Inform( pG, ITRACE, "pG->pwdarg is NULL, or points to zero len password"   );
        */
      }
      if ( pG->pInfo->encrypted && ( error = decrypt( pG ) ) != PK_COOL )
      {
        if ( error == PK_MEM2 )
        {
          if ( error > error_in_archive )
            error_in_archive = error;
        }
        else
        {
          // (error == PK_WARN)
          ++num_bad_pwd;
//          User(PF, zacSkipped, 0, SKIPPED_BAD_PASSWORD, pG->filename );
          _CB_.Arg1 = 0;
          _CB_.Arg2 = SKIPPED_BAD_PASSWORD;
          _CB_.MsgP = pG->filename;
          User_CB(PF, zacSkipped);
          if (pG->Frame.Verbose < 0)
            Notify( PF, ITRACE, "Skipping encrypted file %s, bad password", pG->filename   );
        }
        if ( pG->Frame.Abort_Flag )
        { // v1.6024
          UnzErr( pG, UEN_ABORT02 );
          break;
        }
        continue;
        /* go on to next file */
      }
# endif /* CRYPT */
      pG->disk_full = 0;

      if ( pG->Frame.Abort_Flag )
      {
        UnzErr( pG, UEN_ABORT01 );
        break;
      }
      fsize = pG->lrec.ucsize;
      _CB_.FileSize.i64 = fsize;
      _CB_.MsgP = pG->filename;
      User_CB(PF, zacItem);

      // ====================================================
      // Function:  extract_or_test_member() does the unzip
      // ====================================================
      if ( ( error = extract_or_test_member( pG ) ) != PK_COOL )
      {
        if ( error != PK_WARN && error & 0x09 ) // RP 1.7
        {
          /* abort check v1.6026 */
          UnzErr( pG, error );
          break;
        }
        _CB_.Arg1 = error;
        _CB_.Arg2 = SKIPPED_EXTRACT_ERROR;
        _CB_.MsgP = pG->filename;
        User_CB(PF, zacSkipped);
        if (pG->Frame.Verbose)// < 0)
          Notify( PF, ITRACE, "error occured while extracting or testing" );
        if ( error > error_in_archive )
          error_in_archive = error;
        /* ...and keep going */
        if ( pG->disk_full > 1 )
        {
          if ( SkippingArray )
            FREE( SkippingArray );
          return error_in_archive;
        }
      }
      else
      {
        //        DLLprintf(
        Notify( PF, IMSG,  "%s file %s of size %lu", pG->tflag ? "Tested  " : "Unzipped", pG->filename, fsize );
        pG->files_acted_on++;
      }
    }
    /* end for-loop (i:  files in current block) */

    /* Jump back to where we were in the central directory, then go and do
    * the next batch of files. */
    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "jump back in central dir to where we were" );
    // RCV Changed 29-1-99 USE_STRM_INPUT
    pG->cur_zipfile_bufstart = vclSeek( pG, ( long )cd_bufstart, SEEK_SET );
    vclRead( pG, ( char * ) pG->inbuf, INBUFSIZ );
    /* been here before... */

    pG->inptr = cd_inptr;
    pG->incnt = cd_incnt;
    ++blknum;
  }
  /* end while-loop (blocks of files in central directory) */

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "done with big outer block" );
//  User(PF, zacEndOfBatch, 0, 0, NULL ); // done with a batch of files
  User_CB(PF, zacEndOfBatch); // done with a batch of files

  /*---------------------------------------------------------------------------
  *  Check for unmatched filespecs on command line and print warning if any *  found.  Free allocated memory.
  *---------------------------------------------------------------------------*/
  if ( SkippingArray )
  {
    FREE( SkippingArray );
    //      SkippingArray = 0;
  }
  if ( pG->Frame.Abort_Flag )
  {
    UnzErr( pG, UEN_ABORT01 );
    return UEN_ABORT01;
  }

  // R. Peters - changed reporting fn_matched not used
  if ( pG->filespecs > 0 && pG->pfnames )
  {
    UnzFileData * pfn = ( UnzFileData * ) pG->pfnames;
    for ( i = 0; i < pG->filespecs; i++ )
    { // initial bit 0 set if not found
      if ( ( pfn++ )->fMatch & 1 )
      {
        sprintf( pG->ewemsg, "Filespec Not Matched: %s", ( ( UnzFileData * ) ( pG->pfnames ) ) [i].fFileSpec );
        UnzErr( pG, UEN_MISC03 );
        if ( error_in_archive <= PK_WARN )
          error_in_archive = PK_FIND; // some files not found
      }
    }
  }

  /*---------------------------------------------------------------------------
  * Double-check that we're back at the end-of-central-directory record, and
  * print quick summary of results, if we were just testing the archive.
  *---------------------------------------------------------------------------*/
  if ( readbuf( pG, pG->sig, 4 ) == 0 )
  {
    if (pG->Frame.Verbose )//< 0)
      Notify( PF, ITRACE, "bad signature at end of archive, or premature EOF" );
    error_in_archive = PK_EOF;
  }
  if ( strncmp( pG->sig, pG->end_central_sig, 4 ) )
  {
    /* just to make sure */
    //    DLLprintf(
    Notify( PF, IWARNING,  "Bad Ending Signature for Central dir" );
    if ( !error_in_archive ) /* don't overwrite stronger error */
      error_in_archive = PK_WARN;
  }

  ++filnum;
  /* initialized to -1, so now zero if no files found */
  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "filnum = %d", filnum  );

  if ( pG->tflag )
  {
    // testing archive
    int num = filnum - num_bad_pwd;

    if ( pG->qflag < 2 )
    {
      /* GRR 930710:  was (pG->qflag == 1) */
      if ( error_in_archive )
      {
        sprintf( pG->ewemsg, "Error In Archive %s %s", ( error_in_archive == 1 ) ? "warning-" : "", pG->zipfn );
        UnzErr( pG, UEN_TEST01 );
      }
      else
        if ( num == 0 )
        {
          sprintf( pG->ewemsg, "No Files Tested %s", pG->zipfn );
          //        user_callback( pG, 4, 0, 0, pG->ewemsg );
          Notify( PF, 0, pG->ewemsg);
        }
        else
          if ( pG->process_all_files && ( num_skipped + num_bad_pwd == 0 ) )
          {
            sprintf( pG->ewemsg, "no error in %s", pG->zipfn );
            Notify( PF, 0, pG->ewemsg);
            //        user_callback( pG, 4, 0, 0, pG->ewemsg );
          }
          else
          {
            if ( num > 1 )
              sprintf( pG->ewemsg, "No Errors Found In %d Tested Files of %s", num, pG->zipfn );
            else
              sprintf( pG->ewemsg, "No Error Found In %d Tested File of %s", num, pG->zipfn );
            //        user_callback( pG, 4, 0, 0, pG->ewemsg ); // BUG WAS HERE
            Notify( PF, 0, pG->ewemsg);
          }
    }
    if ( num_skipped > 0 )
    {
      if ( why_skipped > 0 )
        why_skipped = ( why_skipped & 63 ) - 1;
      sprintf( pG->ewemsg, "Skipped %d Files: %d", num_skipped, why_skipped );
      //        sprintf( pG->ewemsg, "Skipped %d Files"/*" of %s"*/, num_skipped);//, pG->zipfn );
      UnzErr( pG, UEN_TEST02 );
    }
#               ifdef CRYPT
    if ( num_bad_pwd > 0 )
    {
      sprintf( pG->ewemsg, "Files with bad pwd: %d", num_bad_pwd );
      UnzErr( pG, UEN_MISC05 );
    }
#               endif /* CRYPT */

    else
      if ( ( pG->qflag == 0 ) && !error_in_archive && ( num == 0 ) )
      {
        sprintf( pG->ewemsg, "Zero Files Tested %s", pG->zipfn );
        Notify( PF, 0, pG->ewemsg);
        //      user_callback( pG, 4, 0, 0, pG->ewemsg );
      }
  }

  /* give warning if files not tested or extracted (first condition can still
  * happen if zipfile is empty and no files specified on command line) */
  if ( ( filnum == 0 ) && error_in_archive <= PK_WARN )
  {
    sprintf( pG->ewemsg, "no files found" );
    UnzErr( pG, UEN_MISC04 );
    error_in_archive = PK_FIND;
    /* no files found at all */
  }
  else
    if ( ( num_skipped > 0 ) && !error_in_archive )
    {
      sprintf( pG->ewemsg, "some files skipped" );
      //    user_callback( pG, 4, 0, 0, pG->ewemsg );
      Notify( PF, 0, pG->ewemsg);
      error_in_archive = PK_WARN;
    }

#       ifdef CRYPT
    else
      if ( ( num_bad_pwd > 0 ) && !error_in_archive )
        error_in_archive = PK_WARN;
#       endif

  return error_in_archive;
}
/* end function extract_or_test_files() */


#ifdef COPYRIGHT_CLEAN          /* no reduced or tokenized files */
  #  define UNKN_COMPR  (pG->crec.compression_method > SHRUNK && \
       pG->crec.compression_method != IMPLODED && pG->crec.compression_method != DEFLATED)
#else /* !COPYRIGHT_CLEAN */
  #  define UNKN_COMPR \
       (pG->crec.compression_method > IMPLODED && pG->crec.compression_method != DEFLATED)
#endif /* ?COPYRIGHT_CLEAN */

/* ===========================================================================
*   Check central directory info for version/compatibility requirements.
*      Function store_info()
*  changed to StoreInfo - returns reason for skipping */
static int StoreInfo( struct UGlobals * pG )
{
  // remove prev filename (if any)
  char *p = pG->pInfo->filename;
  if ( p )
  {
    pG->pInfo->filename = NULL;
    FREE(p);
  }
  /* return err if skipping, 0 if OK */
  pG->pInfo->encrypted = pG->crec.general_purpose_bit_flag & 1;

  /* bit field */
  pG->pInfo->ExtLocHdr = ( pG->crec.general_purpose_bit_flag & 8 ) == 8;

  /* bit field */
  pG->pInfo->textfile = pG->crec.internal_file_attributes & 1;

  pG->pInfo->crc = pG->crec.crc32;
  pG->pInfo->compr_size = pG->crec.csize;    
  pG->pInfo->uncomp_size = pG->crec.ucsize;

  switch ( pG->aflag )
  {
    case 0:
      pG->pInfo->textmode = false;
      /* bit field */
      break;
    case 1:
      pG->pInfo->textmode = pG->pInfo->textfile;
      /* auto-convert mode */
      break;
    default:
      /* case 2: */
      pG->pInfo->textmode = true;
      break;
  }

  // EWE note: all platforms define VMS_UNZIP_VERSION (currently 42)
  if ( pG->crec.version_needed_to_extract[1] == VMS_ )
  {
    if ( pG->crec.version_needed_to_extract[0] > VMS_UNZIP_VERSION )
    {
      if (pG->Frame.Verbose)// < 0)
        Notify( PF, ITRACE, "Skipping Unsupported zip version or hosttype: %s", pG->filename );
      return SKIPPED_UNKNOWN_ZIPHOST;
    }

#ifndef VMS /* won't be able to use extra field, but still have data */
    else
      if ( !pG->tflag && !pG->overwrite_all )
      {
        /* if -o, extract regardless */
        //      user_callback( pG, 11, 0, SKIPPED_FILEFORMAT_WRONG, pG->filename ); // RCV: 1.610
        if (pG->Frame.Verbose)// < 0)
          Notify( PF, ITRACE, "Warning - file's format may be incorrect: %s", pG->filename );
        return SKIPPED_FILEFORMAT_WRONG;
      }
#endif
    /* usual file type:  don't need VMS to extract */
  }
  else
    if ( pG->crec.version_needed_to_extract[0] > UNZIP_VERSION )
    {
      if (pG->Frame.Verbose)// < 0)
        Notify( PF, ITRACE, "Skipping Unsupported zip version or hosttype: %s", pG->filename );
      return SKIPPED_UNKNOWN_ZIPHOST;
    }

  if UNKN_COMPR
  {
    // RCV: 1.610
    if (pG->Frame.Verbose)// < 0)
      Notify( PF, ITRACE, "Skipping Unsupported compression type: %s", pG->filename );
      return SKIPPED_COMPRESSION_UNKNOWN;
    }

#ifndef CRYPT
    if ( pG->pInfo->encrypted )
      {
        //    user_callback( pG, 11, 0, SKIPPED_NO_ENCRYPTION, pG->filename );      // RCV: 1.610
        if (pG->Frame.Verbose)// < 0)
          Notify( PF, ITRACE, "Skipping encrypted file: %s", pG->filename );
        return SKIPPED_NO_ENCRYPTION;
      }
#endif

  /* map whatever file attributes we have into the local format */
  mapattr( pG );

  /* GRR:  worry about return value later */
  pG->pInfo->offset = ( long )pG->crec.relative_offset_local_header;
  return 0;
}
/* end function store_info() */


/* ===========================================================================
*    Function extract_or_test_member() *
* return PK-type error code or PK_COOL.
* direct: PK_DISK (open error or full), PK_ERR, PK_WARN, PK_MEM3
* indirect caused by unshrink:
* */
static int extract_or_test_member( struct UGlobals * pG )
{
  //char *nul = "[empty] ", *txt = "[text]  ", *bin = "[binary]";  // RCV Removed
  register int b;
  int r, error = PK_COOL;
  ulg wsize;

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "Start extract_or_test_member: %s", pG->filename   );

  /*---------------------------------------------------------------------------
  *    Initialize variables, buffers, etc.
  *---------------------------------------------------------------------------*/
  pG->bits_left = 0;
  pG->bitbuf = 0L;
  /* unreduce and unshrink only */
  pG->zipeof = 0;
  pG->newfile = true;
  pG->crc32val = CRCVAL_INITIAL;
  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "initializing pG->crc32val to %08X", CRCVAL_INITIAL  );

  if ( pG->tflag )
  { // if test desired
    if ( pG->Frame.Verbose) //vflag )
    { // if Frame.Verbose
      sprintf( pG->ewemsg, "Testing %s", pG->filename );
      Notify( PF, 0, pG->ewemsg);
      //      user_callback( pG, 4, 0, 0, pG->ewemsg );
    }
  }
  else
    if ( open_outfile( pG ) )
      return PK_DISK;

  /*---------------------------------------------------------------------------
  *    Unpack the file.
  *---------------------------------------------------------------------------*/
  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "unpack the file" );
  defer_leftover_input( pG );
  /* so NEXTBYTE bounds check will work */

  switch ( pG->lrec.compression_method )
  {
    case STORED:
# ifdef USE_STRM_OUTPUT
      if ( pG->redirect_data )
      {
        wsize = pG->redirect_size + 1;
        pG->outptr = pG->redirect_buffer;
      }
      else
      {
#  endif
        wsize = WSIZE;
        pG->outptr = slide;
#  ifdef USE_STRM_OUTPUT
      }
#   endif
      pG->outcnt = 0L;
      while ( ( b = NEXTBYTE ) != EOF && !pG->disk_full )
      {
        * pG->outptr++ = ( uch )b;
        if ( ++pG->outcnt == wsize )
        { // EWE: wsize = 32K
          flush( pG, slide, pG->outcnt, 0 );
          pG->outptr = slide;
          pG->outcnt = 0L;
          if ( pG->Frame.Abort_Flag )
          {
            /* v1.6026 */
            CloseOut( pG );
            undefer_input( pG );
            return UEN_ABORT04;
          }
        }
# ifdef USE_STRM_OUTPUT
        if ( pG->redirect_data && !( pG->outcnt % 0x8000 ) ) // RCV1.6022
        {
//          User(PF, zacProgress, 0, 0x8000, NULL ); // bump up progress bar
          _CB_.Written.i64 = 0;
          _CB_.FileSize.i64 = 0x8000;
          User_CB(PF, zacProgress); // done with a batch of files
        }
# endif
      }
# ifdef USE_STRM_OUTPUT
      if ( pG->outcnt && !pG->redirect_data )
# else
      if ( pG->outcnt ) /* flush final (partial) buffer */
# endif
        flush( pG, slide, pG->outcnt, 0 );
      break;

    case SHRUNK:
      if ( ( r = unshrink( pG ) ) != PK_COOL )
      {
        Notify( PF, 0,  "Error unzipping files" );
        error = r;
      }
      break;

    case IMPLODED:
      if ( ( ( r = explode( pG ) ) != 0 ) && r != 5 )
      {
        /* treat 5 specially */
        //        DLLprintf(
        Notify( PF, 0, "Error unzipping files" );
        error = ( r == 3 ) ? PK_MEM3 : PK_ERR;
      }
      if ( r == 5 )
      {
        int warning = ( ( ulg )pG->used_csize <= pG->lrec.csize );
        //        DLLprintf(
        Notify( PF, 0, "Error unzipping files" );
        error = warning ? PK_WARN : PK_ERR;
      }
      break;

    case DEFLATED:
      if ( ( r = inflate( pG ) ) != 0 )
      {
        if ( r != 1 && r & 0x09 ) // RP 1.7
        {
          /* user want to cancel operation v 1.6026 */
          CloseOut( pG );
          undefer_input( pG );
          return r;
        }
        //        DLLprintf(
        Notify( PF, 0, "Error unzipping files" );
        error = ( r == 3 ) ? PK_MEM3 : PK_ERR;
      }
      break;

    default:
      /* should never get to this point */
      if (pG->Frame.Verbose)// < 0)
        Notify( PF, ITRACE, "should NEVER get here" );
      //      DLLprintf(
      Notify( PF, 0, "Error unzipping files - unknown method" );
      /* close and delete file before return? */
      undefer_input( pG );
      return PK_WARN;
  }
  /* end switch (compression method) */

  if ( pG->disk_full )
  {
    /* set by flush() */
    if ( pG->disk_full > 1 )
    {
      undefer_input( pG );
      return PK_DISK;
    }
    error = PK_WARN;
  }

  if ( error != PK_COOL && /* )
           if (*/  pG->Frame.Verbose)// < 0)
    Notify( PF, ITRACE, "had an error of %d before closing file", error   );

  CloseOut( pG );

  /* GRR todo: CONVERT close_outfile() TO NON-VOID:  CHECK FOR ERRORS! */

  if ( error > PK_WARN )
  {
    /* don't print redundant CRC error if error already */
    undefer_input( pG );
    return error;
  }

  if (pG->Frame.Verbose < 0)
  {
    Notify( PF, ITRACE, "After extraction, pG->crc32val = %08X", pG->crc32val  );
    Notify( PF, ITRACE, "File's CRC in local hdr = %08X", pG->lrec.crc32   );
  }
  if ( pG->crc32val != pG->lrec.crc32 )
  {
//    if ( pG->Frame.CallerVersion >= 160 )
//    { // RCV: 1.609
      // Call the component with a request for what do with with this CRC error.
//      User(PF, zacCRCError, pG->crc32val, pG->lrec.crc32, pG->filename );
    _CB_.Arg1 = pG->crc32val;
    _CB_.Arg2 = pG->lrec.crc32;
    _CB_.MsgP = pG->filename;
    User_CB(PF, zacCRCError); 
    if (_CB_.ActionCode >= 0)          // no response    
      _CB_.ActionCode = -2;             // warn
    if (_CB_.ActionCode == -3)          // responded 'delete'
    {
      DeleteFile( pG->filename );
      error = PK_ERR;
    }
    if (_CB_.ActionCode == -2)          // responded 'warn'
    {
      /* if quiet enough, we haven't output the filename yet:  do it */
      Notify( PF, 0, "After extraction, file %s had a CRC error", pG->filename );
# ifdef CRYPT
      if ( pG->pInfo->encrypted )
        Notify( PF, 0, "May be Bad Password for file: %s", pG->filename );
# endif
      error = PK_WARN;
    }
  }
  undefer_input( pG );

  if ( error != PK_COOL && /*)
           if (*/ pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "extract_or_test_member returning error: %d", error   );
  return error;
}
/* end function extract_or_test_member() */


/*---------------------------------------------------------------------------
* Close the file and set its date and time (not necessarily in that order),
* and make sure the CRC checked out OK.  Logical-AND the CRC for 64-bit * machines (redundant on 32-bit machines).
*---------------------------------------------------------------------------*/
static void CloseOut( struct UGlobals * pG )
{
#       ifdef USE_STRM_OUTPUT
  if ( !pG->tflag && ( !pG->cflag || pG->redirect_data ) )
    if ( pG->redirect_data )
      flush( pG, redirSlide, ( ulg )( pG->outcnt ), 0 );
    else
      close_outfile( pG );
#       else

  if ( !pG->tflag && !pG->cflag ) /* don't close NULL file or stdout */
    close_outfile( pG );
#       endif
}

/* ===========================================================================
*     Function TestExtraField() *
static int TestExtraField( struct UGlobals *pG, ef, ef_len) uch *ef; unsigned ef_len; {
//    ush ebID;  // RCV Removed unsigned ebLen;

// we know the regular compressed file data tested out OK, or else we
// wouldn't be here ==> print filename if any extra-field errors found // while (ef_len >= EB_HEADSIZE) {
//        ebID = makeword(ef);  // RCV Removed ebLen = (unsigned)makeword(ef+EB_LEN);

if (ebLen > (ef_len - EB_HEADSIZE)) { // Discovered some extra field inconsistency!
Inform(pG, 0, IWARNING, "Bad length on file %s", pG->filename ); return PK_ERR; } ef_len -= (ebLen + EB_HEADSIZE);
ef += (ebLen + EB_HEADSIZE); } if (!pG->qflag) Inform(pG, 0, IWARNING, "OK") ; return PK_COOL; } */


/* =========================================================================== *     Function MemExtract() *
* extract compressed stream *      Return PK-type error. */
int MemExtract( struct UGlobals * pG )
{
  uch * old_inptr = pG->inptr;
  int old_incnt = pG->incnt, error = PK_OK, r;
  ush Method = makeword( (unsigned char *)pG->InStream );
  ulg ExtraFieldCRC = makelong( ( unsigned char * ) pG->InStream + 2 );

  pG->inptr = ( unsigned char * ) pG->InStream + 2 + 4; // Method and ExtraFieldCRC
  pG->incnt = ( int )( pG->csize = ( long )( pG->InStreamSize - ( 2 + 4 ) ) );
  pG->mem_mode = true;
  pG->outbufptr = pG->redirect_buffer;
  pG->outsize = pG->buffer_size;

//  User(PF, zacCount, 0, 1, NULL );
  _CB_.Arg1 = 1;
  User_CB(PF, zacCount);
//  User(PF, zacSize, 0, pG->redirect_size, NULL );
  _CB_.FileSize.lo = pG->redirect_size;
  _CB_.FileSize.hi = 0;
  User_CB(PF, zacSize);
//  User(PF, zacItem, 0, pG->redirect_size, "InStream" );
  _CB_.FileSize.i64 = pG->redirect_size;
  _CB_.MsgP = "InStream";
  User_CB(PF, zacItem);

  switch ( Method )
  {
    case STORED:
      error = MemFlush( pG, pG->inptr, pG->incnt );
      break;

    case DEFLATED:
      pG->outcnt = 0L;
      if ( ( r = inflate( pG ) ) != 0 )
      {
        if ( !pG->tflag )
          Notify( PF, 0,   "Error unzipping stream" );
        error = ( r == 3 ) ? PK_MEM3 : PK_ERR;
      }
      break;

    default:
      if ( pG->tflag )
        error = PK_ERR | ( ( int )Method << 8 );
      else
      {
        Notify( PF, 0,  "Unsupported extract method" );
        error = PK_ERR; // GRR:  should be passed on up via SetEAs()
      }
  }
  pG->inptr = old_inptr;
  pG->incnt = old_incnt;
  pG->mem_mode = false;
  if ( !error )
  {
    register ulg crcval = crc32( CRCVAL_INITIAL, pG->redirect_buffer, ( extent )pG->outcnt );
    if ( crcval != ExtraFieldCRC )
    {
      if ( pG->tflag )
        error = PK_ERR | ( DEFLATED << 8 ); // kludge for now
      else
      {
//        User(PF, zacCRCError, crcval, ExtraFieldCRC, "InStream" );
        _CB_.Arg1 = crcval;
        _CB_.Arg2 = ExtraFieldCRC;
        _CB_.MsgP = "InStream";
        User_CB(PF, zacCRCError); 
        if (_CB_.ActionCode >= 0)          // no response
          _CB_.ActionCode = -2;             // warn
        if (_CB_.ActionCode != -1 && _CB_.ActionCode != -2)  // responded 'no extract'
        {
          Notify( PF, 0,  "Bad extra field CRC" );
          error = PK_ERR;
        }
      }
    }
  }
//  User(PF, zacStream, 0, pG->outcnt, NULL );
  _CB_.FileSize.lo = pG->outcnt;
  _CB_.FileSize.hi = 0;
  User_CB(PF, zacStream);
//  User(PF, zacEndOfBatch, 0, 0, NULL );
  User_CB(PF, zacEndOfBatch); // done with a batch of files
  if ( !error )
    pG->files_acted_on = 1;
  return error;
}
/* end function MemExtract() */


/* ===========================================================================
*    Function MemFlush() *
* rawbuf = redirSlide = pG->redirect_pointer = pG->outbuf and
* size = wsize = pG->redirect_size */
int MemFlush( struct UGlobals * pG, uch * rawbuf, ulg size )
{
  if ( size > pG->outsize )
  { // more data than output buffer can hold
    pG->buffer_size = pG->outcnt + size; // New requested stream size
    // Reset the orinaly given stream sizes
//    User(PF, zacSize, 0, pG->buffer_size, NULL );
    _CB_.Written.i64 = 0;
    _CB_.FileSize.i64 = pG->buffer_size;
    User_CB(PF, zacSize);
//    User(PF, zacItem, 0, pG->buffer_size, "InStream" );
    _CB_.FileSize.i64 = pG->buffer_size;
    _CB_.MsgP = "InStream";
    User_CB(PF, zacItem);
//    User(PF, zacProgress, 0, pG->outcnt, NULL ); // Progress upto now
    _CB_.FileSize.i64 = pG->outcnt;
    User_CB(PF, zacProgress);
//    User(PF, zacStream, 0, pG->buffer_size, NULL ); // Request new size
    _CB_.FileSize.lo = pG->buffer_size;
    _CB_.FileSize.hi = 0;
    User_CB(PF, zacStream);
    if (_CB_.ActionCode != -1)
//    if ( pG->Frame.CallBackData.ErrorCode )
      return 50;
    pG->outsize = size;
    pG->redirect_buffer = ( uch * ) _CB_.MsgP2; // Possibly new location for the buffer
//    pG->redirect_buffer = ( uch * ) pG->Frame.CallBackData.FileSize; // Possibly new location for the buffer
    pG->outbufptr = pG->redirect_buffer + pG->outcnt; // Change the pointer inside this buffer
  }
  if ( size )
  {
//    User(PF, zacProgress, 0, size, NULL ); // bump up progress bar
    _CB_.Written.i64 = 0;
    _CB_.FileSize.i64 = size;
    User_CB(PF, zacProgress);
  }

  memcpy( ( char * ) pG->outbufptr, ( char * ) rawbuf, ( extent )size );
  pG->outbufptr += ( unsigned int ) size;
  pG->outsize -= size;
  pG->outcnt += size;
  return 0;
}


