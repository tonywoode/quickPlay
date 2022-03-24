#include <windows.h>
#include "Common.h"
#pragma hdrstop
/* This version modified by Chris Vleghert and Eric W. Engler
 * for BCB/Delphi Zip, Jun 18, 2000.
 */

/* WARNING: Don't pull any OS/2 or HPFS code without great care.  Much of
 * it is also used for NTFS, although it doesn't always have comments to
 * that effect. */

/*---------------------------------------------------------------------------
 * win32.c
 * 32-bit Windows-specific (NT/95) routines for use with Info-ZIP's UnZip 5.2
 * and later.  (Borrowed, pilfered and plundered code from OS/2 and MS-DOS
 * versions and from ZIP; modified as necessary.)
 * Contains:  GetLoadPath()
 *            mapattr()
 *            getNTfiletime()
 *            close_outfile()
 *            isfloppy()
 *            IsVolumeOldFAT()   RCV Removed.
 *            IsFileNameValid()  RP Removed
 *            IsInvalidFileName()
 *            map2fat()
 *            checkdir()
 *            mapname()
 *            version()
 *---------------------------------------------------------------------------*/
#include "unzip.h"
//#include <windows.h>            /* must be AFTER unzip.h to avoid struct G problems */
#include <shlobj.h>

#define MKDIR( path, mode )   mkdir( path )

#ifdef USE_EF_UX_TIME
static void utime2FileTime( time_t ut, FILETIME * ft );
#endif
static int getNTfiletime( struct UGlobals *pG, FILETIME * ft );
static void map2fat( char *pathcomp, char **pEndFAT );


/* ===========================================================================
 *                 Function mapattr()
 * Identical to MS-DOS, OS/2 versions.
 * However, NT has a lot of extra permission stuff, so this function should
 *  probably be extended in the future.
 */
int
mapattr( struct UGlobals *pG )
{
  /* Set archive bit (file is not backed up): */
  pG->pInfo->file_attr =
    ( unsigned ) ( pG->crec.external_file_attributes | 32 )  & 0xff;
  return 0;
}                               /* end function mapattr() */


#ifdef USE_EF_UX_TIME
/* ===========================================================================
 *                Function utime2FileTime()
 * Convert Unix time_t format into the form used by SetFileTime() in NT/95.
 */
#  define UNIX_TIME_ZERO_HI  0x019DB1DE
#  define UNIX_TIME_ZERO_LO  0xD53E8000
#  define NT_QUANTA_PER_UNIX 10000000
static void utime2FileTime( time_t ut, FILETIME * ft )
{
  unsigned int b1, b2, carry = 0;
  unsigned long r0, r1, r2, r3, r4;

  b1 = ut & 0xFFFF;
  b2 =( ut >> 16 )  & 0xFFFF;     /* if ut is over 32 bits, too bad */
  r1 = b1 * ( NT_QUANTA_PER_UNIX & 0xFFFF );
  r2 = b1 * ( NT_QUANTA_PER_UNIX >> 16 );
  r3 = b2 * ( NT_QUANTA_PER_UNIX & 0xFFFF );
  r4 = b2 * ( NT_QUANTA_PER_UNIX >> 16 );
  r0 = ( r1 + ( r2 << 16 ) )  & 0xFFFFFFFF;
  if ( r0 < r1 )
    carry++;
  r1 = r0;
  r0 = ( r0 + ( r3 << 16 ) )  & 0xFFFFFFFF;
  if ( r0 < r1 )
    carry++;
  ft->dwLowDateTime = r0 + UNIX_TIME_ZERO_LO;
  if ( ft->dwLowDateTime < r0 )
    carry++;
  ft->dwHighDateTime =
    r4 + ( r2 >> 16 )  + ( r3 >> 16 )  + UNIX_TIME_ZERO_HI + carry;
}
#endif /* USE_EF_UX_TIME */


/* ===========================================================================
 *             Function getNTfiletime()
 * Get the file time in a format that can be used by SetFileTime() in NT.
 */
static int getNTfiletime( struct UGlobals *pG, FILETIME * ft )
{
  FILETIME lft;                 /* 64-bit value made up of two 32 bit [low & high] */
  WORD wDOSDate;                /* for converting from DOS date to Windows NT      */
  WORD wDOSTime;
#ifdef USE_EF_UX_TIME

  ztimbuf z_utime;              /* structure for Unix style actime and modtime     */
#endif

  /* Copy and/or convert time and date variables, if necessary;   */
  /* then set the file time/date.                                 */
#ifdef USE_EF_UX_TIME

  if ( pG->extra_field && ef_scan_for_izux( pG->extra_field,
       pG->lrec.extra_field_length,
       &z_utime, NULL )  > 0 )
  {
    TTrace(( pG, "close_outfile:  Unix e.f. modif. time = %ld",
             z_utime.modtime ) );
    utime2FileTime( z_utime.modtime, ft );
    return true;
  }
#endif /* USE_EF_UX_TIME */
  wDOSTime = ( WORD )  pG->lrec.last_mod_file_time;
  wDOSDate = ( WORD )  pG->lrec.last_mod_file_date;

  /* The DosDateTimeToFileTime() function converts a DOS date/time    */
  /* into a 64 bit Windows NT file time                               */
  if ( !DosDateTimeToFileTime( wDOSDate, wDOSTime, &lft ) )
  {
    Notify( PF, 0,  "DosDateTime failed: %d", GetLastError() );
    return false;
  }
  if ( !LocalFileTimeToFileTime( &lft, ft ) )
  {
    Notify( PF, 0,  "LocalFileTime failed: %d", GetLastError() );
    *ft = lft;
  }
  return true;
}


/* ===========================================================================
 *        Function close_outfile()
 */
void close_outfile( struct UGlobals *pG )
{
  FILETIME ft;                  /* File time type defined in NT */
  HANDLE hFile;                 /* File handle defined in NT    */
  int gotTime;

  /* don't set the time stamp on standard output */
  if ( pG->cflag )
  {
    fclose( pG->outfile );
    return;
  }

  gotTime = getNTfiletime( pG, &ft );

  /* Close the file and then re-open it using the Win32
   * CreateFile call, so that the file can be created
   * with GENERIC_WRITE access, otherwise the SetFileTime
   * call will fail. */
  fclose( pG->outfile );

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "setting date/time in close_outfile of win32.c" );
  hFile =
    CreateFile( pG->filename, GENERIC_WRITE, 0, NULL, OPEN_EXISTING,
                FILE_ATTRIBUTE_NORMAL, NULL );
  if ( hFile == INVALID_HANDLE_VALUE )
    Notify( PF, 0, "CreateFile error %d when trying set filetime",
           GetLastError() );
  else
  {
    if ( gotTime )
      if ( !SetFileTime( hFile, NULL, NULL, &ft ) )
        Notify( PF, 0,  "SetFileTime failed: %d", GetLastError() );
    CloseHandle( hFile );
  }

  /* HG: I think this could be done in the CreateFile call above - just  */
  /*     replace 'FILE_ATTRIBUTE_NORMAL' with 'pG->pInfo->file_attr & 0x7F'  */
  if ( !SetFileAttributes( pG->filename, pG->pInfo->file_attr & 0x7F ) )
    Notify( PF, IWARNING, "(%d): could not set file attributes",
           GetLastError() );
  else
    SHChangeNotify( SHCNE_ATTRIBUTES, SHCNF_PATH,
                    GetFullPath( pG, pG->filename ), NULL );
  return;
}                               /* end function close_outfile() */


/* ===========================================================================
 *                    Function isfloppy()
 * more precisely, is it removable?
 */
static int isfloppy( int nDrive )
{                               /* 1 == A:, 2 == B:, etc. */
  char rootPathName[ 4 ];

  rootPathName[ 0 ]  = ( char )  ( 'A' + nDrive - 1 );  /* build the root path */
  rootPathName[ 1 ]  = ':';        /*  name, e.g. "A:/"   */
  rootPathName[ 2 ]  = '/';
  rootPathName[ 3 ]  = '\0';
  return( GetDriveType( rootPathName )  == DRIVE_REMOVABLE );
}                               /* end function isfloppy() */


/* ===========================================================================
 *        Function IsVolumeOldFAT()
 */

/* Note:  8.3 limits on filenames apply only to old-style FAT filesystems.
 *        More recent versions of Windows (Windows NT 3.5 / Windows 4.0)
 *        can support long filenames (LFN) on FAT filesystems.  Check the
 *        filesystem maximum component length field to detect LFN support.
 *        [GRR:  this routine is only used to determine whether spaces in
 *        filenames are supported...]
 */

/*
static int IsVolumeOldFAT( char *name ) {
        char     *tmp0;
        char      rootPathName[4];
        char      tmp1[MAX_PATH], tmp2[MAX_PATH];
        unsigned  volSerNo, maxCompLen, fileSysFlags;
 
        if ( isalpha( name[0] ) && (name[1] == ':') )
                tmp0 = name;
        else {
                GetFullPathName( name, MAX_PATH, tmp1, &tmp0 );
                tmp0 = &tmp1[0];
        }
        strncpy( rootPathName, tmp0, 3 );   // Build the root path name,
        rootPathName[3] = '\0';           // e.g. "A:/"
        GetVolumeInformation( (LPCTSTR)rootPathName, (LPTSTR)tmp1, (DWORD)MAX_PATH,
                                  (LPDWORD)&volSerNo, (LPDWORD)&maxCompLen,
                                  (LPDWORD)&fileSysFlags, (LPTSTR)tmp2, (DWORD)MAX_PATH );
        // Long Filenames (LFNs) are available if the component length is > 12
        return maxCompLen <= 12;
}
* /
char lastN = 0;
int lastRet = 0;
int IsVolumeNTFS(struct UGlobals *pG, char *name)
{
    int ret;
    char *fullname;
    char      rootPathName[4];
    char      tmp1[MAX_PATH], fsname[MAX_PATH];
    unsigned  volSerNo, maxCompLen, fileSysFlags;

    if (!name || !*name)// || (name[0] == '/' && name[1] == '/'))
        return 2;  // default true

    fullname = GetFullPath(pG, name);            
    if (name[0] == '/' && name[1] == '/')
        return 2;  // default true
//    if (isalpha(name[0]) && (name[1] == ':'))
//        tmp0 = name;
//    else
//    {
//        GetFullPathName((LPCTSTR)name, MAX_PATH, tmp1, &tmp0);
//        tmp0 = &tmp1[0];
//    }
    if (*fullname == lastN)
        return lastRet;

    strncpy(rootPathName, fullname, 3);   // Build the root path name,
    rootPathName[3] = '\0';           // e.g. "A:/"
    GetVolumeInformation((LPCTSTR)rootPathName, (LPTSTR)tmp1, (DWORD)MAX_PATH,
                              (LPDWORD)&volSerNo, (LPDWORD)&maxCompLen,
                              (LPDWORD)&fileSysFlags, (LPTSTR)fsname, (DWORD)MAX_PATH);
    // Long Filenames (LFNs) are available if the component length is > 12
//        return maxCompLen <= 12;
    if (pG->Frame.Verbose < 0)
        Notify( PF, ITRACE, "Volume type for %s = %s", rootPathName, fsname);
    ret = strncmpi(fsname, "NTFS", 4) == 0;
    lastN = *fullname;
    lastRet = ret;  // cache it
    return ret;
}

/* ===========================================================================
 *         Function IsFileNameValid()
 * /
static int IsFileNameValid( char *name )
{
  HFILE hf;
  OFSTRUCT of;

  hf = OpenFile( name, &of, OF_READ | OF_SHARE_DENY_NONE );
  if ( hf == HFILE_ERROR )
    switch( GetLastError () )
    {
      case ERROR_INVALID_NAME:
      case ERROR_FILENAME_EXCED_RANGE:
        return false;
      default:
        return true;
    }
  else
    _lclose( hf );
  return true;
} */

/* ===========================================================================
 *         Function IsInvalidFileName()
 */
static int IsInvalidFileName(struct UGlobals *pG, const char *name )
{        
  HANDLE hfn = CreateFile(name, GENERIC_READ, 0,// FILE_SHARE_READ | FILE_SHARE_WRITE,
                NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
  if (hfn == INVALID_HANDLE_VALUE)
  {
    int err = GetLastError();
    if (err == ERROR_INVALID_NAME) {
      if (pG->Frame.Verbose)// < 0)
        Notify( PF, IWARNING, "invalid filename [%s]", name );
      return 1;
    }
    if (err == ERROR_FILENAME_EXCED_RANGE) {
      if (pG->Frame.Verbose)// < 0)
        Notify( PF, IWARNING, "filename too long [%s] = %d", name, lstrlen(name));
      return 2;
    }
    return 0;
  }
//  else
   CloseHandle( hfn );
  return 0;
}

/* ===========================================================================
 *           Function map2fat()
 * Not quite identical to OS/2 version
 */
static void map2fat( char *pathcomp, char **pEndFAT )
{
  char *ppc = pathcomp;         /* variable pointer to pathcomp                 */
  char *pEnd = *pEndFAT;        /* variable pointer to buildpathFAT             */
  char *pBegin = *pEndFAT;      /* constant pointer to start of this comp.      */
  char *last_dot = NULL;        /* last dot not converted to underscore         */
  int dotname = false;          /* flag:  path component begins with dot        */
  /*  ("." and ".." don't count)                                       */
  register unsigned workch;     /* hold the character being tested              */

  /* Only need check those characters which are legal in NTFS but not
   * in FAT:  to get here, must already have passed through mapname.
   * Also must truncate path component to ensure 8.3 compliance.
   */
  while ( ( workch = ( uch )  * ppc++ )  != 0 )
  {
    switch ( workch )
    {
      case '[':
      case ']':
      case '+':
      case ',':
      case ';':
      case '=':
        *pEnd++ = '_';            /* convert brackets to underscores */
        break;

      case '.':
        if ( pEnd == *pEndFAT )
        {   /* nothing appended yet...     */
          if ( *ppc == (char)'\0' )        /* don't bother appending a    */
            break;                /* "./" component to the path  */
          else
            if ( *ppc == (char)'.' && ppc[ 1 ]  == (char)'\0' )
            {       /* "../"  */
              *pEnd++ = '.';        /* add first dot, unchanged... */
              ++ppc;                /* skip second dot, since it will  */
            }
            else
            {                  /* be "added" at end of if-block   */
              *pEnd++ = '_';        /* FAT doesn't allow null filename */
              dotname = true;       /* bodies, so map .exrc -> _.exrc  */
            }                       /* (extra '_' now, "dot" below)   */
        }
        else
          if ( dotname )
          {       /* found a second dot, but still  */
            dotname = false;        /* have extra leading underscore: */
            *pEnd = '\0';           /* remove it by shifting chars   */
            pEnd = *pEndFAT + 1;    /* left one space (e.g., .p1.p2: */
            while ( pEnd[ 1 ] )
            {       /* __p1 -> _p1_p2 -> _p1.p2 when */
              *pEnd = pEnd[ 1 ];      /* finished) [opt.:  since first */
              ++pEnd;               /* two chars are same, can start */
            }                       /* shifting at second position]  */
          }
        last_dot = pEnd;          /* point at last dot so far... */
        *pEnd++ = '_';            /* convert dot to underscore for now */
        break;

      default:
        *pEnd++ = ( char )  workch;

    }                           /* end switch */
  }                             /* end while loop */

  *pEnd = '\0';                 /* terminate buildpathFAT */

  /* NOTE:  keep in mind that pEnd points to the end of the path
   * component, and *pEndFAT still points to the *beginning* of it...
   * Also note that the algorithm does not try to get too fancy:
   * if there are no dots already, the name either gets truncated
   * at 8 characters or the last underscore is converted to a dot
   * (only if more characters are saved that way).  In no case is
   * a dot inserted between existing characters.
   */
  if ( last_dot == NULL )
  {       /* no dots:  check for underscores... */
    char *plu = strrchr( pBegin, '_' );  /* pointer to last underscore */

    if ( plu == NULL )
    {          /* no dots, no underscores:  truncate at 8 chars */
      *pEndFAT += 8;            /* (or could insert '.' and keep 11...?)  */
      if ( *pEndFAT > pEnd )
        *pEndFAT = pEnd;        /* oops...didn't have 8 chars to truncate */
      else
        **pEndFAT = '\0';
    }
    else
      if ( MIN ( plu - pBegin, 8 )  + MIN( pEnd - plu - 1, 3 )  > 8 )
      {
        last_dot = plu;           /* be lazy:  drop through to next if-blk */
      }
      else
        if ( ( pEnd - *pEndFAT )  > 8 )
        {
          *pEndFAT += 8;            /* more fits into just basename than if  */
          **pEndFAT = '\0';         /*  convert last underscore to dot       */
        }
        else
          *pEndFAT = pEnd;          /* whole thing fits into 8 chars or less */
  }

  if ( last_dot != NULL )
  {       /* one dot (or two, in the case of */
    *last_dot = '.';            /*  "..") is OK:  put it back in   */

    if ( ( last_dot - pBegin )  > 8 )
    {
      char *p = last_dot, *q = pBegin + 8;
      int i;

      for ( i = 0; ( i < 4 )  && *p; ++i )    /* too many chars in basename: */
        *q++ = *p++;            /*  shift .ext left and trun-  */
      *q = '\0';                /*  cate/terminate it */
      *pEndFAT = q;
    }
    else
      if ( ( pEnd - last_dot )  > 4 )
      {   /* too many chars in extension */
        *pEndFAT = last_dot + 4;
        **pEndFAT = '\0';
      }
      else
        *pEndFAT = pEnd;          /* filename is fine; point at terminating zero */
  }
}                               /* end function map2fat() */

/* ===========================================================================
 *          Function checkdir()
 *
 * returns:  1 - (on APPEND_NAME) truncated filename
 *           2 - path doesn't exist, not allowed to create
 *           3 - path doesn't exist, tried to create and failed; or
 *               path exists and is not a directory, but is supposed to be
 *           4 - path is too long
 *          10 - can't allocate memory for filename buffers
 *
 * Borrowed from os2.c for UnZip 5.1.
 * Difference: no EA stuff
 * HPFS stuff works on NTFS too
 */
int checkdir( struct UGlobals *pG, char *pathcomp, int flag )
{                               /* see w32cfg.h */

  /* static int rootlen = 0;     *//* length of rootpath */
  /* static char *rootpath;      *//* user's "extract-to" directory */
  /* static char *buildpathHPFS; *//* full path (so far) to extracted file, */
  /* static char *buildpathFAT;  *//*  both HPFS/EA (main) and FAT versions */
  /* static char *endHPFS;       *//* corresponding pointers to end of */
  /* static char *endFAT;        *//*  buildpath ('\0') */
  char path2[ FILNAMSIZ ];        /* Fullpath-component buffer */

#  define FN_MASK   7
#  define FUNCTION  (flag & FN_MASK)

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "checkdir of win32.c" );

  /*---------------------------------------------------------------------------
   * APPEND_DIR:  append the path component to the path being built and check
   * for its existence.  If doesn't exist and we are creating directories, do
   * so for this one; else signal success or error as appropriate.
   *---------------------------------------------------------------------------*/
  if ( FUNCTION == APPEND_DIR )
  {
    DWORD flags;
    char *p = pathcomp;
    int too_long = false;
    int unc = 0;        // 0 = no -1 = need machine

    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "appending dir segment [%s]", pathcomp);
    // check for UNC
    if (pG->buildpathHPFS[0] == (char)'/' && pG->buildpathHPFS[1] == (char)'/')
      unc = pG->buildpathHPFS[2] ? 1 : -1;

    while ( ( *pG->endHPFS = *p++ )  != (char)'\0' )        /* copy to HPFS filename */
      ++pG->endHPFS;
//    if (unc || IsFileNameValid( GetFullPath( pG, pG->buildpathHPFS ) ) )
    if (unc || !IsInvalidFileName(pG, GetFullPath( pG, pG->buildpathHPFS ) ) )
    {
      p = pathcomp;
      while ( ( *pG->endFAT = *p++ )  != (char)'\0' )       /* copy to FAT filename, too */
        ++pG->endFAT;
    }
    else
    {
      if (pG->Frame.Verbose < 0)
        Notify( PF, IWARNING, "mapping to FAT [%s]", pathcomp);
      map2fat( pathcomp, &pG->endFAT );  /* map into FAT fn, update endFAT */
    }

    /* GRR:  could do better check, see if overrunning buffer as we go:
     * check endHPFS-buildpathHPFS after each append, set warning variable
     * if within 20 of FILNAMSIZ; then if var set, do careful check when
     * appending.  Clear variable when begin new path. */

    /* next check:  need to append '/', at least one-char name, '\0' */
    if ( ( pG->endHPFS - pG->buildpathHPFS )  > FILNAMSIZ - 3 )       // v1.6025
      too_long = true;          /* check if extracting dir? */

    lstrcpy( path2, GetFullPath( pG, pG->buildpathFAT ) );        // v1.6025
    // don't attempt test/create machine name
    if (unc >= 0)
    {
      flags = GetFileAttributes(path2);  // do quick directory check
      if (flags == 0xFFFFFFFF || !(flags & FILE_ATTRIBUTE_DIRECTORY))
      {    // no such dir - check filename
        if ( stat( path2, &pG->statbuf ) )
        {   /* path doesn't exist   // v1.6025 */
          if ( !pG->create_dirs )
          {   /* told not to create (freshening) */
            // 1.75                FREE ( pG->buildpathHPFS );
            // 1.75                FREE ( pG->buildpathFAT );
            return 2;               /* path doesn't exist:  nothing to do */
          }
          if ( too_long )
          {           /* GRR:  should allow FAT extraction w/o EAs */
            Notify( PF, 0,  "checkdir error:  path too long: %s", pG->buildpathHPFS );
            // 1.75                FREE ( pG->buildpathHPFS );
            // 1.75                FREE ( pG->buildpathFAT );
            return 4;               /* no room for filenames:  fatal */
          }
          if ( MKDIR ( path2, 0777 )  == -1 )
          {  /* create the directory   // v1.6025 */
            Notify( PF, 0, "checkdir error:  can't create %s, unable to process %s.", path2, pG->filename );     // v1.6025
            // 1.75                FREE ( pG->buildpathHPFS );
            // 1.75                FREE ( pG->buildpathFAT );
            return 3;               /* path didn't exist, tried to create, failed */
          }
          //EWE SHChangeNotify( SHCNE_MKDIR, SHCNF_PATH, path2, NULL );  // v1.6025
          pG->created_dir = true;
        }
        else
          if ( !S_ISDIR( pG->statbuf.st_mode ) )
          {
            Notify( PF, 0,  "checkdir error: %s exists but is not directory. unable to process %s.", path2, pG->filename ); // v1.6025
            // 1.75                FREE ( pG->buildpathHPFS );
            // 1.75                FREE ( pG->buildpathFAT );
            return 3;                 /* path existed but wasn't dir */
          }
      }
    }
    if ( too_long )
    {
      Notify( PF, 0,  "checkdir error:  path too long: %s", pG->buildpathHPFS );
      // 1.75            FREE ( pG->buildpathHPFS );
      // 1.75            FREE ( pG->buildpathFAT );
      return 4;                 /* no room for filenames:  fatal */
    }
    *pG->endHPFS++ = '/';
    *pG->endFAT++ = '/';
    *pG->endHPFS = *pG->endFAT = '\0';
    if (pG->Frame.Verbose < 0)
    {
      Notify( PF, ITRACE, "buildpathHPFS now = [%s]", pG->buildpathHPFS  );
      Notify( PF, ITRACE, "buildpathFAT now =  [%s]", pG->buildpathFAT   );
    }
    return 0;
  }                             /* end if (FUNCTION == APPEND_DIR) */

  /*---------------------------------------------------------------------------
   *  GETPATH:  copy full FAT path to the string pointed at by pathcomp (want
   *  filename to reflect name used on disk, not EAs; if full path is HPFS,
   *  buildpathFAT and buildpathHPFS will be identical).  Also free both paths.
   *---------------------------------------------------------------------------*/
  if ( FUNCTION == GETPATH )
  {
/*    if (pG->Frame.Verbose < 0)
    {
      Notify( PF, ITRACE, "getting and freeing FAT path [%s]", pG->buildpathFAT   );
      Notify( PF, ITRACE, "freeing HPFS path [%s]", pG->buildpathHPFS   );
    }  */
    lstrcpy( pathcomp, pG->buildpathFAT );
    // 1.75        FREE ( pG->buildpathFAT );
    // 1.75    FREE( pG->buildpathHPFS ); 
    *pG->buildpathHPFS = 0;
    *pG->buildpathFAT = 0;
//    pG->buildpathHPFS = pG->buildpathFAT =
    pG->endHPFS = pG->endFAT = NULL;
    return 0;
  }

  /*---------------------------------------------------------------------------
   *  APPEND_NAME:  assume the path component is the filename; append it and
   *  return without checking for existence.
   *---------------------------------------------------------------------------*/
  if ( FUNCTION == APPEND_NAME )
  {
    char *p = pathcomp;
    int error = 0;

    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "appending filename [%s]", pathcomp);
    while ( ( *pG->endHPFS = *p++ )  != (char)'\0' )
    {     /* copy to HPFS filename */
      ++pG->endHPFS;
      if ( ( pG->endHPFS - pG->buildpathHPFS )  >= FILNAMSIZ )
      {
        *--pG->endHPFS = '\0';
        Notify( PF, 0,  "checkdir warning:  path too long; truncating %s -> %s",
               pG->filename, pG->buildpathHPFS );
        error = 1;              /* filename truncated */
      }
    }

//    if ( pG->pInfo->vollabel || IsFileNameValid( pG->buildpathHPFS ) )
    if ( pG->pInfo->vollabel || !IsInvalidFileName(pG, pG->buildpathHPFS ) )
    {
      p = pathcomp;
      while ( ( *pG->endFAT = *p++ )  != (char)'\0' )       /* copy to FAT filename, too */
        ++pG->endFAT;
    }
    else                                          
    {
      if (pG->Frame.Verbose < 0)
        Notify( PF, IWARNING, "mapping to FAT [%s]", pathcomp);
      map2fat( pathcomp, &pG->endFAT );  /* map into FAT fn, update endFAT */
    }
    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "buildpathHPFS: %s  buildpathFAT: %s", pG->buildpathHPFS,
              pG->buildpathFAT   );

    return error;               /* could check for existence, prompt for new name... */
  }                             /* end if (FUNCTION == APPEND_NAME) */

  /*---------------------------------------------------------------------------
   *  INIT:  allocate and initialize buffer space for the file currently being
   *  extracted.  If file was renamed with an absolute path, don't prepend the
   *  extract-to path.
   *---------------------------------------------------------------------------*/
  if ( FUNCTION == INIT )
  {
    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "A. initializing buildpathHPFS and buildpathFAT"   );
    *pG->rootpath = 0;
    *pG->buildpathHPFS = 0;
    *pG->buildpathFAT = 0;

    if ( pG->pInfo->vollabel )
    {  /* use root or renamed path, but don't store */
      /* GRR:  for network drives, do strchr() and return IZ_VOL_LABEL if not [1] */
      if ( pG->renamed_fullpath && pathcomp[ 1 ]  == (char)':' )
        *pG->buildpathHPFS = ( char )  ToLower( *pathcomp );
      else
        if ( !pG->renamed_fullpath && pG->rootlen > 1
             && pG->rootpath[ 1 ]  == (char)':' )
          *pG->buildpathHPFS = ( char )  ToLower( *pG->rootpath );
        else
        {
          char tmpN[ MAX_PATH ], *tmpP;
          if ( GetFullPathName( ".", MAX_PATH, tmpN, &tmpP )  > MAX_PATH )
          {
            /* by definition of MAX_PATH we should never get here */
            Notify( PF, IWARNING, " current dir path too long" );
            return 1;             /* can't get drive letter */
          }
          pG->nLabelDrive = *tmpN - 'a' + 1;
          *pG->buildpathHPFS = ( char )  ( pG->nLabelDrive - 1 + 'a' );
        }
      pG->nLabelDrive = *pG->buildpathHPFS - 'a' + 1;   /* save for mapname() */
      if ( pG->volflag == 0 || *pG->buildpathHPFS < (char)'a'  /* no labels/bogus? */
           || ( pG->volflag == 1 && !isfloppy( pG->nLabelDrive ) ) )
      {       /* !fixed */
        // 1.75                FREE ( pG->buildpathHPFS );
        // 1.75                FREE( pG->buildpathFAT );
        return IZ_VOL_LABEL;    /* skipping with message */
      }
      *pG->buildpathHPFS = '\0';
    }
    else
      if ( pG->renamed_fullpath )       /* pathcomp = valid data */
        lstrcpy( pG->buildpathHPFS, pathcomp );
      else
        if ( pG->rootlen > 0 )
          lstrcpy( pG->buildpathHPFS, pG->rootpath );
        else
          *pG->buildpathHPFS = '\0';
    pG->endHPFS = pG->buildpathHPFS;
    pG->endFAT = pG->buildpathFAT;

    while ( ( *pG->endFAT = *pG->endHPFS )  != (char)'\0' )
    {
      ++pG->endFAT;
      ++pG->endHPFS;
    }
    // Trace( (pG, "[%s]", pG->buildpathHPFS) );
    return 0;
  }

  /*---------------------------------------------------------------------------
   * ROOT:  if appropriate, store the path in rootpath and create it if neces-
   * sary; else assume it's a zipfile member and return.  This path segment
   * gets used in extracting all members from every zipfile specified on the
   * command line.  Note that under OS/2 and MS-DOS, if a candidate extract-to
   * directory specification includes a drive letter (leading "x:"), it is
   * treated just as if it had a trailing '/'--that is, one directory level
   * will be created if the path doesn't exist, unless this is otherwise pro-
   * hibited (e.g., freshening).
   *---------------------------------------------------------------------------*/
  if ( FUNCTION == ROOT )
  {
    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "initializing root path to [%s]", pathcomp );
    if ( pathcomp == NULL )
    {
      pG->rootlen = 0;
      return 0;
    }
    if ( ( pG->rootlen = lstrlen( pathcomp ) )  > 0 )
    {
      int had_trailing_pathsep = false, has_drive = false, xtra = 2;

      if ( isalpha( pathcomp[ 0 ] )  && pathcomp[ 1 ]  == (char)':' )
        has_drive = true;       /* drive designator */
      if ( pathcomp[ pG->rootlen - 1 ]  == (char)'/' )
      {
        pathcomp[ --pG->rootlen ]  = '\0';
        had_trailing_pathsep = true;
      }
      if ( has_drive && ( pG->rootlen == 2 ) )
      {
        if ( !had_trailing_pathsep )       /* i.e., original wasn't "x:/" */
          xtra = 3;             /* room for '.' + '/' + 0 at end of "x:" */
      }
      else
        if ( pG->rootlen > 0 )
        {       /* need not check "x:." and "x:/" */
          if ( stat( pathcomp, &pG->statbuf )  || !S_ISDIR( pG->statbuf.st_mode ) )
          {
            /* path does not exist */
            if ( !pG->create_dirs /* || iswild( pathcomp ) */ )
            {
              pG->rootlen = 0;
              return 2;           /* treat as stored file */
            }
            /* create directory (could add loop here to scan pathcomp
             * and create more than one level, but really necessary?) */
            if ( MKDIR( pathcomp, 0777 )  == -1 )
            {
              Notify( PF, 0,  "can't create extraction directory: %s", pathcomp );
              pG->rootlen = 0;    /* path didn't exist, tried to create, */
              return 3;           /* failed:  file exists, or need 2+ levels */
            }
            //EWE SHChangeNotify( SHCNE_MKDIR, SHCNF_PATH, GetFullPath( pG, pG->buildpathFAT ), NULL );
          }
        }
      /* rootpath now fixed size
         if ( ( pG->rootpath = ( char * )  MALLOC ( pG->rootlen + xtra ) )  == NULL )
         {
            pG->rootlen = 0;
          return 10;
                      }     */

      lstrcpy( pG->rootpath, pathcomp );
      if ( xtra == 3 )             /* had just "x:", make "x:." */
        pG->rootpath[ pG->rootlen++ ]  = '.';
      pG->rootpath[ pG->rootlen++ ]  = '/';
      pG->rootpath[ pG->rootlen ]  = '\0';
      if (pG->Frame.Verbose < 0)
        Notify( PF, ITRACE, "rootpath now = [%s]", pG->rootpath  );
    }
    return 0;
  }

  /*---------------------------------------------------------------------------
   *   END:  free rootpath, immediately prior to program exit.
   *---------------------------------------------------------------------------*/
  if ( FUNCTION == END )
  {
//    if (pG->Frame.Verbose < 0)
//      Inform( pG, ITRACE, "freeing rootpath"   );
    /* 1.75 fixed allocation
        if ( pG->rootlen > 0 )
          FREE ( pG->rootpath );   */
    return 0;
  }
  return 99;                    /* should never reach */
}                               /* end function checkdir() */

/* ===========================================================================
 *             Function mapname()
 * There are presently two possibilities in OS/2:  the output filesystem is
 * FAT, or it is HPFS.  If the former, we need to map to FAT, obviously, but
 * we *also* must map to HPFS and store that version of the name in extended
 * attributes.  Either way, we need to map to HPFS, so the main mapname
 * routine does that.  In the case that the output file system is FAT, an
 * extra filename-mapping routine is called in checkdir().  While it should
 * be possible to determine the filesystem immediately upon entry to mapname(),
 * it is conceivable that the DOS APPEND utility could be added to OS/2 some-
 * day, allowing a FAT directory to be APPENDed to an HPFS drive/path.  There-
 * fore we simply check the filesystem at each path component.
 *
 * Note that when alternative IFS's become available/popular, everything will
 * become immensely more complicated.  For example, a Minix filesystem would
 * have limited filename lengths like FAT but no extended attributes in which
 * to store the longer versions of the names.  A BSD Unix filesystem would
 * support paths of length 1024 bytes or more, but it is not clear that FAT
 * EAs would allow such long .LONGNAME fields or that OS/2 would properly
 * restore such fields when moving files from FAT to the new filesystem.
 *
 * GRR:  some or all of the following chars should be checked in either
 *       mapname (HPFS) or map2fat (FAT), depending:  ,=^+'"[]<>|\t&
 *
 * return 0 if no error, 1 if caution (filename trunc),
        renamed :: 2 if warning (skip file because dir doesn't exist),
                   3 if error (skip file), 10 if no memory (skip file),
                   IZ_VOL_LABEL if can't do vol label, IZ_CREATED_DIR
 */
int mapname( struct UGlobals *pG, int renamed )
{
  char pathcomp[ FILNAMSIZ ];     /* path-component buffer */
  char *pp, *cp = NULL;         /* character pointers    */
//  char *lastsemi = NULL;        /* pointer to last semi-colon in pathcomp */
  int error;
//  register unsigned
  char workch;     /* hold the character being tested */
  int Ddot;           // double dot error count

  /*---------------------------------------------------------------------------
   *    Initialize various pointers and counters and stuff.
   *---------------------------------------------------------------------------*/
  /* can create path as long as not just freshening, or if user told us */
  pG->create_dirs = ( !pG->fflag || renamed );

  pG->created_dir = false;      /* not yet */
  pG->renamed_fullpath = false;
  pG->fnlen = lstrlen( pG->filename );
//Ddot = IsVolumeNTFS(pG, pG->filename);
  if ( renamed )
  {
    cp = pG->filename - 1;      /* point to beginning of renamed name... */
    while ( *++cp )
      if ( *cp == (char)'\\' )           /* convert backslashes to forward */
        *cp = '/';
    cp = pG->filename;
    /* use temporary rootpath if user gave full pathname */
    if ( pG->filename[ 0 ]  == (char)'/' &&  pG->filename[ 1 ]  == (char)'/' )
    {
      pG->renamed_fullpath = true;
      pp = pathcomp;
      *pp++ = *cp++;            /* copy the "//" */
      *pp++ = *cp++;
      *pp = '\0';
    }
    else
      if ( pG->filename[ 0 ]  == (char)'/' )
      {
        pG->renamed_fullpath = true;
        pathcomp[ 0 ]  = '/';        /* copy the '/' and terminate */
        pathcomp[ 1 ]  = '\0';
        ++cp;
      }
      else
        if ( isalpha( pG->filename[ 0 ] )  && pG->filename[ 1 ]  == (char)':' )
        {
          pG->renamed_fullpath = true;
          pp = pathcomp;
          *pp++ = *cp++;            /* copy the "d:" (+ '/', possibly) */
          *pp++ = *cp++;
          if ( *cp == (char)'/' )
            *pp++ = *cp++;          /* otherwise add "./"? */
          *pp = '\0';
        }
  }
  /* pathcomp is ignored unless renamed_fullpath is true: */
  if ( ( error = checkdir( pG, pathcomp, INIT ) )  != 0 )      /* init path buffer */
    return error;               /* ...unless no mem or vol label on hard disk */

  *pathcomp = '\0';             /* initialize translation buffer */
  pp = pathcomp;                /* point to translation buffer */
  if ( !renamed )
  {               /* cp already set if renamed */
    if ( pG->jflag )               /* junking directories */
      cp = ( char * )  strrchr( pG->filename, '/' );
    if ( cp == NULL )              /* no '/' or not junking dirs */
      cp = pG->filename;        /* point to internal zipfile-member pathname */
    else
      ++cp;                     /* point to start of last component of path */
  }

  /*---------------------------------------------------------------------------
   *       Begin main loop through characters in filename.
   *---------------------------------------------------------------------------*/
  Ddot = 0;   // 1.75
  while ( ( workch = ( uch )  * cp++ )  != 0 )
  {
    if (workch == '\\')
        workch = '/';

    switch ( workch )
    {
      case '/':                   /* can assume -j flag not given */
        *pp = '\0';
        if (strcmp(pathcomp, ".") == 0)
        {
          /* don't bother appending "./" to the path */
          *pathcomp = '\0';
        }
        else
          if (strcmp(pathcomp, "..") == 0)
          {
            /* "../" dir traversal detected, skip over it */
            *pathcomp = '\0';
            Ddot++;     /* set "show message" flag */
          }
        if (pathcomp[0] &&( error = checkdir(pG, pathcomp, APPEND_DIR) )  > 1 )
          return error;
        pp = pathcomp;            /* reset conversion buffer for next piece */
//        lastsemi = NULL;          /* leave directory semi-colons alone */
        break;
      case ':':                   /* drive names not stored in zipfile, */
      case '<':                   /*  so no colons allowed */
      case '>':                   /* no redirection symbols allowed either */
      case '|':                   /* no pipe signs allowed */
      case '"':                   /* no double quotes allowed */
      case '?':                   /* no wildcards allowed */
      case '*':
//      case ';':
        *pp++ = '_';              /* these rules apply equally to FAT and NTFS */
        break;
//      case ';':                   /* start of VMS version? */
//        lastsemi = pp;            /* remove VMS version later... */
//        *pp++ = ';';              /*  but keep semicolon for now */
//        break;  
//      case ';':
//      case ' ':                   /* keep spaces unless specifically */
//        /* NT cannot create filenames with spaces on FAT volumes */
//        /* EWE: win95 can use spaces in fnames, and so can NT on NTFS.
//         * So, I'll allow it. */
//        //   if ( pG->sflag || IsVolumeOldFAT( pG->filename ) )
//        //        *pp++ = '_';
//        //   else
//        if (IsVolumeNTFS(pG, pG->filename))
//            *pp++ = workch;
//        else
//            *pp++ = '_';
//        break;
      default:
        /* allow European characters in filenames: */ 
//        if (isprint(workch)  || workch >= 127)
        if (workch < 0  || isprint(workch))
          *pp++ = (char)workch;
    }                           /* end switch */
  }                             /* end while loop */

  *pp = '\0';                   /* terminate it */

  if ( Ddot )
  {
    Notify( PF, IWARNING, "mapname: directory traversal BUG detected %s failed", pG->filename );
    return IZ_SKIPPED;//3;
  }
//  /* if not saving them, remove VMS version numbers (appended "###") */
//  if ( !pG->V_flag && lastsemi )
//  {
//    pp = lastsemi + 1;          /* semi-colon was kept:  expect #'s after */
//    while ( isdigit( ( uch )  ( *pp ) ) )
//      ++pp;
//    if ( *pp == '\0' )             /* only digits between ';' and end:  nuke */
//      *lastsemi = '\0';
//  }

  /*---------------------------------------------------------------------------
   * Report if directory was created (and no file to create:  filename ended
   * in '/'), check name to be sure it exists, and combine path and name be-
   * fore exiting.
   *---------------------------------------------------------------------------*/
  if ( pG->filename[ pG->fnlen - 1 ]  == (char)'/' )
  {
    //-----------------------------------------------------------
    // BUG FIX since v1.4: bump up the file count when we extract
    // a dirname (whether or not it already existed).
    // This keeps SuccessCnt in line with TZipContents.Count
    pG->files_acted_on++;
    //-----------------------------------------------------------
    checkdir( pG, pG->filename, GETPATH );
    if ( pG->created_dir )
    {
      Notify( PF, 0,  "   creating: %-22s", pG->filename );
      /* HG: are we setting the date & time on a newly created   */
      /*     dir?  Not quite sure how to do this.  It does not   */
      /*     seem to be done in the MS-DOS version of mapname(). */
      return IZ_CREATED_DIR;    /* dir time already set */
    }
    return 2;                   /* dir existed already; don't look for data to extract */
  }

  if ( *pathcomp == (char)'\0' )
  {
    Notify( PF, 0,  "mapname: conversion of %s failed", pG->filename );
    return 3;
  }
  checkdir( pG, pathcomp, APPEND_NAME ); /* returns 1 if truncated:  care? */
  checkdir( pG, pG->filename, GETPATH );
  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "mapname returns with filename = [%s] (error = %d)",
            pG->filename, error   );
  return error;                 // not necessarily an error, depends on value
}                               /* end function mapname() */

