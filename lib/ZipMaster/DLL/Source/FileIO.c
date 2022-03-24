#include <windows.h>
#include "Common.h"
#pragma hdrstop
#include "Zip.h" 
#include "ZipErr.h"

// FileIO.c Copyright (C) 1990-1996
//* Mark Ad\ler, Richard B. Wales, Jean-loup Gailly, Kai Uwe Rommel,
//* Onno van der Linden and Igor Mandrichenko. This version modified
//* by Chris Vleghert and Eric Engler for BCB/Delphi Zip. distributed
//* under LGPL license ** see license.txt for details
// edited 27 July 2003 R. Peters
//#include "zip.h"
//#include "ZGlobals.h"
#include <time.h>
#include <errno.h>

#define PAD     0
#define ENOTSAM 17

char * __fastcall CleanedPath(char *pth, struct ZGlobals *pG ); // note - uses ewemsg

// Local functions
static int  fqcmp( const void *, const void * );
static int  fqcmpz( const void *, const void * );

static int  filecopy( HANDLE f, HANDLE g, struct ZGlobals *pG );

// Delete the entry *f in the doubly-linked found list. Return pointer to
//   next entry to allow stepping through list. f :: Entry to delete.
struct flist *fexpel( struct flist *f, struct ZGlobals *pG )
{
  struct flist  *t;                     // temporary variable
//  if (!f)
//    return 0;
  t = f->nxt;
  *( f->lst ) = t;                      // point last to next,
  if ( t != NULL )
    t->lst = f->lst;                    // and next to last

  if ( f->name != NULL )
    FREE( f->name );                    // free memory used
  if ( f->zname != NULL )
    FREE( f->zname );
/**** Warning - do not free passw (allocated globally or externally) ****/
//  if ( f->passw != NULL )
//	FREE( f->passw );
  FREE( f );
  pG->fcount--;                         // decrement count
  return t;                             // return pointer to next
}

// 1.73 27 July 2003 RP use non-case compare Used by qsort() to compare
//   entries in the found list by name. a, *b :: Pointers to pointers to found
//   entries.
static int
fqcmp( const void *a, const void *b )
{
  return namecmp( (*( struct flist ** )a)->name, (*( struct flist ** )b)->name );
}

// 1.73 27 July 2003 RP use non-case compare Used by qsort() to compare
//   entries in the found list by zname. a, *b :: Pointers to pointers to found
//   entries.
static int
fqcmpz( const void *a, const void *b )
{
  return namecmp( (*( struct flist ** )a)->zname, (*( struct flist ** )b)->zname );
}

// Return a pointer to the start of the last path component. For a directory
//   name terminated by the character in c, the return value is an empty
//   string. p :: Sequence of path components. c :: Path components separator
//   character.
char *
last( char *p, int c )
{
  char  *t;                             // temporary variable
  if ( (t = strrchr( p, c )) != NULL )
    return ( t + 1 );
  return p;
}

// Reduce all path components to MSDOS upper case 8.3 style names.
char *
DOSName( char *n, struct ZGlobals *pG )
{
  char  *p,
  c[MAX_PATH];
  int   L1,
  L2;

  // sprintf( pG->ewemsg, "In DOSName1 =%s", n );
  // diag( pG->ewemsg, pG );
  if ( pG->WantedCodePage != 2 )
  {
    c[0] = '\0';

    // Separate the path from the wildcard.
    if ( IsShExp( n ) != NULL
         && ((p = strrchr( n, '\\' )) != NULL || (p = strrchr( n, ':' )) != NULL) )
    {
      if ( *p == (char)':' )
        p++;
      lstrcpy( c, p );
      *p = '\0';
    }

    L2 = lstrlen( n );
    L1 = GetShortPathName( n, n, L2 );  // v1.55
    if ( L1 > L2 )
    {
      char  *n1 = ( char * )MALLOC( L1 + 1 );
      if ( !n1 )
      {
        FREE( n );
        return NULL;
      }

      GetShortPathName( n, n1, L1 + 1 );
      FREE( n );
      n = n1;
    }

    lstrcat( n, c );

    // Make it all uppercase
    for ( p = n; *p; )
      *p = to_up( *p++ );
  }

  // We now the input is ISO so use the present OEM code page for this name.
  CharToOemBuff( n, n, lstrlen( n ) );
  return n;
}

// 1.75 12 March 2004 RA warn on duplicate removal
// 1.73 27 July 2003 RP use non-case compare Sort the found list and remove
//   duplicates. Return ZEN_OK, ZEN_PARMS(warning) or ZEN_MEM(error).
int
check_dup( struct ZGlobals *pG )
{
  struct flist  *f;                     // steps through found linked list
  extent        j,
  k;                      // indices for s
  struct flist  **s;                    // sorted table
  struct flist  **nodup;                // sorted table without duplicates in
  ///* the external name

  // sort found list, remove duplicates
  if ( pG->fcount )
  {
    if ( (s = ( struct flist ** )MALLOC( pG->fcount * sizeof(struct flist *) )) == NULL )
      return ZEN_MEM13;

    // Make a copy of the tabel to work with
    for ( j = 0, f = pG->found; f != NULL; f = f->nxt )
      s[j++] = f;
    qsort( ( char * )s, pG->fcount, sizeof(struct flist *), fqcmp );  // Sort it

    // Remove the duplicate external names
    for ( k = j = pG->fcount - 1; j > 0; j-- )
    {
      if ( !namecmp( s[j - 1]->name, s[j]->name ) )
      {
        // remove duplicate entry from list
        Notify( PF, IWARNING,
                "duplicate filename removed Orig name: %s ,New name : %s", s[j]->name,
                s[j]->zname );
        fexpel( s[j], pG ); // fexpel() changes fcount
      }
      else
        // copy valid entry into destination position
        s[k--] = s[j];
    }

    s[k] = s[0];            // First entry is always valid
    nodup = &s[k];          // Valid entries are at end of array s

    // sort only valid items and check for unique internal names
    qsort( ( char * )nodup, pG->fcount, sizeof(struct flist *), fqcmpz );
    for ( j = 1; j < pG->fcount; j++ )
    {
      if ( !namecmp( nodup[j - 1]->zname, nodup[j]->zname ) )
      {
        Notify( PF, IWARNING, "name in zip file repeated: %s", nodup[j]->zname );
        Notify( PF, IWARNING, "  first full name: %s", nodup[j - 1]->name );
        Notify( PF, IWARNING, " second full name: %s", nodup[j]->name );
        FREE( s );          // RCV Added.
        return ZEN_PARMS13;
      }
    }

    FREE( s );
  }

  return ZEN_OK;
}

// Scan the exclude list for a match to the given name. Return true if the
//   name must be included, false otherwise. The exclude list is 'made' in
//   zipmain in DllZip.c Name :: File to match to
bool __fastcall
filter( char *Name, struct ZGlobals *pG )
{
  register int  n;

  for ( n = 0; n < pG->pcount; n++ )
    if ( dosmatch( pG->patterns[n].zname, Name ) )
      return false;

  return true;
}

// Add (or exclude) the name of an existing disk file. Return an error code
//   in the ZEN_ class. Return ZEN_OK if OK. n :: Name to add (or exclude).
//   nSize :: Size of the file or dir(0).
int
newname( char *nme, long nSize, struct ZGlobals *pG )
{
  char          *m;
  char          *undosm = NULL;
  struct flist  *f;         // where in found, or new found entry
  struct zlist  *z;         // where in zfiles (if found)
  int           dosflag;    // force 8x3?
  int           ErrMsg = ZEN_OK;
  bool          mUsed = false;
  char          *pfp;
  char          *nn = NULL;
  int           nl;
  int           levl;       // required compression
  bool          noext = false;  // don't ignore extension

  char * n = CleanedPath(nme, pG);
  levl = pG->level;
  do
  { // Just one loop, with this w'll get a better error handling. RCV: 1.605
    if ( (m = ex2in( n, &dosflag, pG )) == NULL )
    {
      ErrMsg = ZEN_MEM14;
      break;
    }

    // Discard directory names with zip -rj
    if ( *m == (char)'\0' )
    {
      // If extensions needs to be swapped, we will have empty directory
      //   names instead of the original directory. For example, zipping 'c.',
      //   'c.main' should zip only 'main.c' while 'c.' will be converted to
      //   '\0' by ex2in.
      if ( pG->pathput )
        ziperr( ZEN_LOGIC05, pG );
      break;
    }

    undosm = m;

    if ( dosflag || !pG->pathput )
    {
      int save_dosify = pG->dosify,
                        save_pathput = pG->pathput;

      pG->dosify = 0;
      pG->pathput = 1;

      // convert external name to internal name
      if ( (undosm = ex2in( n, NULL, pG )) == NULL )
        undosm = m;
      pG->dosify = save_dosify;
      pG->pathput = save_pathput;
    }

    // check excluded before going further
    if ( pG->pcount && !filter( undosm, pG ) )
    {
      // Do not clear z->mark if "exclude", because, when "dosify ||
      //   !pathput" is in effect, two files with different filter options
      //   may hit the same z entry.
      if ( pG->Frame.Verbose )
        Notify( PF, IDIAG, "excluding %s", n );
      break;
    }
    // **** start of rename check
    // Give the user a chance to change the internal name
    if ( ((isalpha( n[0] ) && n[1] == (char)':') ||
            (n[0] == (char)'\\' && n[1] == (char)'\\')) )
      pfp = n;
    else
      pfp = GetFullPath( pG, n );
//    User(PF, zacNewName, ( int )pfp, 0, undosm); 
    _CB_.MsgP2 = pfp;
    _CB_.MsgP = undosm;
    User_CB(PF, zacNewName);
    // get length and check for level override
    if (_CB_.ActionCode == -1)  // changed
    {
      char clev;
      const char * ps;
      // check for level override
      nl = 0;
 //     clev = 0;
      for (ps = &_CB_.Msg[0]; *ps && *ps != (char)'|'; ps++)
        nl++;
      if (*ps == (char)'|')
      {
        clev = *(ps + 1);
        while (nl && *--ps == (char)' ')
            nl--;  // remove blanks
        if (clev >= (char)'0' && clev <= (char)'9'){
            levl = ((int)(clev)) & 15;  // set the level
            noext = true;               // ignore file extension
        }
        if (!nl)
            _CB_.ActionCode = 0;        // only change level
      }
    }
    if (_CB_.ActionCode == -1)  // changed
    {
      char *nnt;
      if ( undosm && undosm != m )
        FREE( undosm );
      if ( m )
        FREE( m );
      m = NULL;
      undosm = NULL;
//      nl = lstrlen( _CB_.Msg);
      if (!nl)
      {
        if ( pG->Frame.Verbose )
          Notify( PF, IDIAG, "caller excluding %s", n );
        break;
      }
      if ( (nn = ( char * )MALLOC( nl + 1 )) == NULL )
      {
        ErrMsg = ZEN_MEM45;   /// needs new error code
        break;
      }
      nnt = nn;
      for (pfp = &_CB_.Msg[0];*pfp && nl; nl--) {
        if (*pfp == (char)'/') {
            *nnt++ = '\\';
            pfp++;
        }
        else
          *nnt++ = *pfp++;
      }
      *nnt = 0;
//      lstrcpyn( nn, _CB_.Msg, nl);
//      for (pfp = nn; *pfp; pfp++)
//        if (*pfp == '/')
//          *pfp = '\\';
      if ( (m = ex2in( nn, &dosflag, pG )) == NULL )
      {
        ErrMsg = ZEN_MEM46;
        break;
      }

      // Discard directory names with zip -rj
      if ( *m == (char)'\0' )
      {
        // If extensions needs to be swapped, we will have empty directory
        //   names instead of the original directory. For example, zipping 'c.',
        //   'c.main' should zip only 'main.c' while 'c.' will be converted to
        //   '\0' by ex2in.
        if ( pG->pathput )
          ziperr( ZEN_LOGIC08, pG );
        break;
      }

      undosm = m;

      if ( dosflag || !pG->pathput )
      {
        int save_dosify = pG->dosify,
                          save_pathput = pG->pathput;

        pG->dosify = 0;
        pG->pathput = 1;

        // convert external name to internal name
        if ( (undosm = ex2in( nn, NULL, pG )) == NULL )
          undosm = m;
        pG->dosify = save_dosify;
        pG->pathput = save_pathput;
      }
    }
    // **** end of rename check

    // Search for name in zip file. If there, mark it, else add to list of
    //   new names to do (or remove from that list).
    if ( (z = zsearch( m, pG )) != NULL )
    {
      z->mark = 1;
      FREE( z->name );
      if ( ((z->name = ( char * )MALLOC( lstrlen( n ) + 1 + PAD )) == NULL) )
      {
        ErrMsg = ZEN_MEM15;
        break;
      }

      lstrcpy( z->name, n );
      z->passw = pG->key;                 // p RP 173 current password
#ifdef FORCE_NEWNAME
      FREE( z->zname );
      z->zname = m;
      mUsed = true;
#endif

      // Better keep the old name. Useful when updating on MSDOS a zip
      //   file made on Unix.
      z->options.dosflag = dosflag & 3;
      if ( pG->Frame.Verbose )
        Notify( PF, IDIAG, "including %s", n );

      if ( n == pG->label )
        pG->label = z->name;
    }
    else // not in zipfile already - add to or remove from list
      // if ( !pG->pcount || filter( undosm, pG ) ) RP cannot get here if excluded
    {
      // Check that we are not adding the zip file to itself. This catches
      //   cases like "zip -m foo ../dir/foo.zip". SLASH
      if ( SameNameExt( pG->zipfile, n ) )  // check likely same
      {
        struct stat statb;

        if ( pG->zipstate == -1 )
        {
          pG->zipstate = strcmp( pG->zipfile, "-" ) != 0
                         && stat( pG->zipfile, &pG->zipstatb ) == 0;
        }

        if ( pG->zipstate == 1
             && (statb = pG->zipstatb, stat( GetFullPath( pG, n ), &statb ) == 0
                 && pG->zipstatb.st_mode == statb.st_mode
                 && pG->zipstatb.st_ino == statb.st_ino
                 && pG->zipstatb.st_dev == statb.st_dev
                 && pG->zipstatb.st_uid == statb.st_uid
                 && pG->zipstatb.st_gid == statb.st_gid
                 && pG->zipstatb.st_size == statb.st_size
                 && pG->zipstatb.st_mtime == statb.st_mtime
                 && pG->zipstatb.st_ctime == statb.st_ctime
                ) )
        {
          // Don't compare a_time since we are reading the file
          break;                // is same
        }
      }

      // allocate space and add to list
      if ( (f = ( struct flist * )MALLOC( sizeof(struct flist) )) == NULL
           || (f->name = ( char * )MALLOC( lstrlen( n ) + 1 + PAD )) == NULL )
      {                         // RAEL added
        if ( f->name != NULL )
          FREE( f->name );      // added RAEL
        if ( f != NULL )
          FREE( f );
        ErrMsg = ZEN_MEM16;
        break;
      }

      f->passw = pG->key;       // p 173
      lstrcpy( f->name, n );
      f->zname = m;
      mUsed = true;
      f->options.dosflag = dosflag & 3;    
      f->options.level = levl & 15;
      f->options.noext = (noext || pG->NoExtChk) ? 1 : 0;
      f->len = nSize;           // RCV added.
      *( pG->fnxt ) = f;
      f->lst = pG->fnxt;
      f->nxt = NULL;
      pG->fnxt = &f->nxt;
      pG->fcount++;
      if ( n == pG->label )
        pG->label = f->name;
    }

    break;
  }
  while ( true );
  if ( undosm && undosm != m )
    FREE( undosm );
  if ( m && !mUsed )
    FREE( m );
  if ( nn )
    FREE( nn );
  return ErrMsg;
}

// Return the Unix time_t value (GMT/UTC time) for the DOS format (local)
//   time dostime, where dostime is a four byte value (date in most significant
//   word, time in least significant word), see dostime() function. dostime ::
//   DOS time to convert.
time_t
dos2unixtime( ulg dostime )
{
  struct tm     *t;             // argument for mktime()
  const time_t  clock = time( NULL );

  t = localtime( &clock );

  // Convert DOS time to UNIX time_t format
  t->tm_sec = ( (( int )dostime) << 1 ) & 0x3E;
  t->tm_min = ( (( int )dostime) >> 5 ) & 0x3F;
  t->tm_hour = ( (( int )dostime) >> 11 ) & 0x1F;
  t->tm_mday = ( int )( dostime >> 16 ) & 0x1F;
  t->tm_mon = ( ( int )(dostime >> 21) & 0x0F ) - 1;
  t->tm_year = ( ( int )(dostime >> 25) & 0x7F ) + 80;

  return mktime( t );
}

// Convert the date y/n/d and time h:m:s to a four byte DOS date and time
//   (date in high two bytes, time in low two bytes allowing magnitude
//   comparison). y :: Year. n :: Month. d :: Day. h :: Hour. m :: Minute. s ::
//   Second.
ulg
dostime( int y, int n, int d, int h, int m, int s )
{
  return y < 1980 ? dostime( 1980, 1, 1, 0, 0, 0 ) : ( ((ulg) y - 1980) << 25 ) |
         ( (ulg) n << 21 ) | ( (ulg) d << 16 ) | ( (ulg) h << 11 ) | ( (ulg) m << 5 ) |
         ( (ulg) s >> 1 );
}

// Return the Unix time t in DOS format, rounded up to the next two second
//   boundary. t :: Unix time to convert.
ulg
unix2dostime( time_t *t )
{
  time_t    t_even;
  struct tm *s;                 // result of localtime()
  t_even = ( *t + 1 ) & ( ~1 ); // Round up to even seconds.
  s = localtime( &t_even );     // Use local time since MSDOS does.
  if ( s )
  {                     // Russell Peters s can be null
    return dostime( s->tm_year + 1900, s->tm_mon + 1, s->tm_mday, s->tm_hour, s->tm_min,
                    s->tm_sec );
  }

  return dostime( 1980, 1, 1, 0, 0, 1 );
}

// Return true if the attributes are those of a symbolic link a ::
//   Attributes returned by filetime().
int
issymlnk( ulg a )
{
#ifdef S_IFLNK
  return ( (a >> 16) & S_IFMT ) == S_IFLNK;
#else
  return ( int )a & 0;  // Avoid warning on unused parameter.
#endif
}

// If we do not have a full path then FOF_ALLOWUNDO does not work!
int EraseFile( const char *Fname, struct ZGlobals *pG )
{
  int r;
  SHFILEOPSTRUCT SHF;
  char *fn = MALLOC(lstrlen(Fname) + 2);
  if (!fn) {
    return ZEN_MEM24;
  }

  lstrcpy(fn, Fname);     
  fn[lstrlen( fn ) + 1] = '\0';
  SHF.hwnd = pG->Frame.global_handle; // 1.75
  SHF.wFunc = FO_DELETE;
  SHF.pFrom = Fname;
  SHF.pTo = NULL;
  SHF.fFlags = FOF_NOCONFIRMATION | FOF_SILENT;
  if ( !pG->HowToMove )
    SHF.fFlags |= FOF_ALLOWUNDO;
//  Fname[lstrlen( Fname ) + 1] = '\0';
  r = SHFileOperation( &SHF ); // Returns zero if successful or nonzero if an error occurs.
  FREE(fn);
  return r;
}

// Delete the file *f, returning non-zero on failure. f :: File to delete.
int
destroy( const char *f, struct ZGlobals *pG )
{
  SHFILEOPSTRUCT  fop;
  char            *sb;
  int             ls,
  r;
  if ( f && *f )
  {
    if ( pG->Frame.Verbose )
      Notify( PF, IDIAG, "destroy '%s'", f );
    ls = lstrlen( f );
    if ( (sb = ( char * )MALLOC( ls + 3 )) == NULL )
      return ZEN_MEM44;
    lstrcpy( sb, f );
    sb[ls + 1] = 0;
    fop.hwnd = pG->Frame.global_handle;
    fop.wFunc = FO_DELETE;
    fop.pFrom = sb;
    fop.pTo = NULL;
    fop.fFlags = FOF_NOCONFIRMATION | FOF_NOCONFIRMMKDIR | FOF_NORECURSION;
    fop.fAnyOperationsAborted = 0;
    fop.hNameMappings = NULL;
    fop.lpszProgressTitle = NULL;
    r = SHFileOperation( &fop );
    FREE( sb );
    if ( r )
    {
      Notify( PF, ZEN_TEMP, " destroy: Delete failed [%X]", GetLastError() );
      return -1;
    }

    return ZEN_OK;
  }

  return ENOENT;
}

#if 0
int
destroy( char *f )
{
  if ( f )
    return unlink( f ); // v1.6011
  return ( ENOENT );    // v1.6011
}
#endif


int
replace( const char *d, const char *s, struct ZGlobals *pG )
//replaceOrig( const char *d, const char *s, struct ZGlobals *pG )
{
  struct stat t;        // results of stat()
  int         copy = 0;
  int         d_exists;        int ret1, eno;
                                     
  if ( pG->Frame.Verbose )
    Notify( PF, IDIAG, "replacing %s with %s", d, s );
  d_exists = ( LSTAT( d, &t ) == 0 );
  if ( d_exists )
  {
    // respect existing soft and hard links!
#ifdef S_IFLNK
    if ( t.st_nlink > 1
         || (t.st_mode & S_IFMT) == S_IFLNK )
#else
    if ( t.st_nlink > 1 )
#endif
      copy = 1;
    else
    {
      if ( pG->Frame.Verbose < 0)
         Notify( PF, IDIAG, "in replace - deleting %s", d );
      if ( unlink ( d ))
        {
          if ( pG->Frame.Verbose < 0)
             Notify( PF, IDIAG | IBAD, "replace - delete failed %s", d );
            return ZEN_CREAT01;         // Can't erase zip file--give up
        }
        Sleep(5);   // let Windows remove it
    }
  }
  if ( !copy )
  {

    if ( pG->Frame.Verbose < 0)
	  Notify( PF, IDIAG, "in replace - renaming %s to %s", s ,d );
	ret1 = rename( s, d );
	eno = errno;     
	if ( ret1)// !MoveFile( s, d ) )
//	if ( rename( s, d ))// !MoveFile( s, d ) )
	{                             // Just move s on top of d

      if ( pG->Frame.Verbose < 0)
         Notify( PF, IDIAG | IBAD, "replace - rename failed %s %d", d, eno);
      copy = 1;                   // failed ?
      if ( errno != ENOTSAM )
        return ZEN_CREAT02;
    }
  }

  if ( copy )
  {
    HANDLE  f,
    g;                    // source and destination files
    int     r;                    // temporary variable
    diag( "in replace - open for FOPR", pG );

    if ( (
           f = CreateFile( s, GENERIC_READ, 0, NULL, OPEN_EXISTING,
                           FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL )
         ) <= 0 )                     //== INVALID_HANDLE_VALUE )
    {
      diag( "in replace - bad open for Read", pG );
      Notify( PF, IBAD, " replace: can't open %s\n", s );

      return ZEN_TEMP03;
    }

    diag( "in replace - fopen for FOPW", pG );

    if ( (
           g = CreateFile( d, GENERIC_WRITE, 0, NULL, CREATE_NEW,
                           FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL )
         ) <= 0 )                     //== INVALID_HANDLE_VALUE )
    {
      Close_Handle( &f );
      diag( "in replace - bad open for Write", pG );
      return ZEN_CREAT03;
    }
                                  
    if ( pG->Frame.Verbose < 0)
      Notify( PF, IDIAG, "in replace - copying %s to %s", s, d );
    r = filecopy( f, g, pG );

    Close_Handle( &f );
    if ( !Close_Handle( &g ) || r != ZEN_OK )
    {
      DeleteFile( d );
      return r ? ( ( int ) ( char )(r & 0xFF) == ZEN_TEMP ? ZEN_WRITE07 : r ) : ZEN_WRITE04;
    }
                         
    if ( pG->Frame.Verbose < 0 )
      Notify( PF, IDIAG, "in replace - deleting temporary %s", s);
    DeleteFile( s );
  }

  return ZEN_OK;
}
#if 0
DWORD CALLBACK MoveProgress(
  LARGE_INTEGER TotalFileSize,
  LARGE_INTEGER TotalBytesTransferred,
  LARGE_INTEGER StreamSize,
  LARGE_INTEGER StreamBytesTransferred,
  DWORD dwStreamNumber,
  DWORD dwCallbackReason,
  HANDLE hSourceFile,
  HANDLE hDestinationFile,
  LPVOID lpData
)
{
  long cnt = 0;
  struct ZGlobals *pG = (struct ZGlobals *)lpData;
  if ( !pG )
    return PROGRESS_CONTINUE;
  if (TotalFileSize.QuadPart && TotalBytesTransferred.QuadPart)
  {
    cnt = (long)((100 * TotalBytesTransferred.QuadPart) / TotalFileSize.QuadPart);
  }
  if ( pG->Frame.Verbose )
    Notify( PF, IDIAG, "replace %d%%", cnt );
//  User(PF, zacXProgress, 2, cnt, "");
  _CB_.Arg1 = 2;    // type
  _CB_.FileSize.lo = cnt;
  User_CB(PF, zacXProgress);
  return pG->Frame.Abort_Flag ? PROGRESS_CANCEL : PROGRESS_CONTINUE;
#pragma argsused
}

typedef BOOL WINAPI (*MoveWithProgress)(
  LPCTSTR lpExistingFileName,
  LPCTSTR lpNewFileName,
  LPPROGRESS_ROUTINE lpProgressRoutine,
  LPVOID lpData,
  DWORD dwFlags
);
int
replace( const char *d, const char *s, struct ZGlobals *pG )
{
  int             r;
  HINSTANCE       hKernal;
  MoveWithProgress mover;

  if ( pG->Frame.Verbose )
    Notify( PF, IDIAG, "replace '%s' with '%s'", d, s );
  if ( !d || !s || !*d || !*s )
  {
    diag( "in replace - missing filename", pG );
    return ZEN_TEMP11;
  }

  hKernal = LoadLibrary("kernel32.dll");
  if (hKernal == NULL)
    return replaceOrig(d, s, pG);
  mover = (MoveWithProgress) GetProcAddress(hKernal, "MoveFileWithProgressA");
  if (mover == NULL)
  {
    FreeLibrary(hKernal);
    return replaceOrig(d, s, pG);
  }
  r = ZEN_OK;
  _CB_.Arg1 = 2;    // type
  _CB_.FileSize.lo = 100;  
  _CB_.FileSize.hi = 0;
  _CB_.MsgP = "Copying Temporary File";
  User_CB(PF, zacXItem);
  if (!((mover)( s, d, MoveProgress, pG,
                 MOVEFILE_COPY_ALLOWED | MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH)))
  {
    Notify( PF, ZEN_TEMP12, " replace: Move failed [%X]", GetLastError() );
    r = ZEN_TEMP12;//return ZEN_TEMP12;
  }

  FreeLibrary(hKernal);
  return r;//ZEN_OK;
}
#endif

// Return the file attributes for file f or 0 if failure. f :: File path.
// int getfileattr( char *f ) { struct stat s; return SSTAT( f, &
//   s ) == 0 ? s.st_mode : 0; }
// Give the file f the attributes a, return non-zero on failure. f :: file
//   path. a :: attributes returned by getfileattr().
int
setfileattr( char *f, int a )
{
  return chmod( f, a );
}

#if 1

// Return a temporary file name in its own malloc'ed space, using tempath.
char *
tempname( struct ZGlobals *pG )
{
  char        mt[1];
  char        *nname;
  char        *name = 0;
  const char  *p;
  const char  *pat = pG->tempath;
  const char  *e;
  const char  *n;
  const char  *t;
  char        *t1;
  int         lp,
  ln,
  le,
  i;

  // HANDLE fh;
  mt[0] = '\0';
  if ( !pat )
    pat = mt;
  while ( *pat == (char)' ' )
    pat++;

  /*const char  * */
  p = pat;
  while ( *p )
    p++;
  p--;
  while ( p >= pat && *p == (char)' ' )
    p--;
  if ( *pat == (char)'*' )
  {
    if ( (name = ( char * )MALLOC( MAX_PATH + 2 )) == NULL )
      return NULL;
    nname = name + GetTempPath( MAX_PATH - (lstrlen( pat ) + 15), name );
    pat++;
    while ( *pat == (char)'.' )
      pat++;
  }

  e = NULL;
  n = NULL;
  t = ++p;
  while ( --t >= pat )
  {
    if ( *t == (char)'.' )
      e = t;
    if ( *t == (char)'\\' )
    {
      if ( e )
        n = ( t + 1 );
      break;
    }
  }

  if ( t < pat && e && name )
    n = pat;
  if ( !n )
    e = NULL;

  lp = p - pat;
  ln = 0;
  le = 0;
  if ( e )
  {
    lp = n - pat;
    ln = e - n;
    le = p - e;
  }

  if ( !ln )
  {
    n = "temp";
    ln = 4;
  }

  if ( le < 1 )
  {
    e = ".zip";
    le = 4;
  }

  if ( !name )
  {
    if ( (name = ( char * )MALLOC( lp + 2 + (ln + 4) + (le < 4 ? 4 : le) )) == NULL )
      return NULL;
    nname = name;
  }
  else
    if ( *pat == (char)'\\' )
    {
      pat++;
      lp--;
    }

  if ( lp )
    strncpy( nname, pat, lp );
 
  t1 = nname + lp;
  if ( lp && *(t1 - 1) != (char)'\\' )
    *( t1++ ) = '\\';
  strncpy( t1, n, ln );
  t1 += ln;

  // allow 256 attempts
  for ( i = 0; i < 256; i++ )
  {
    WIN32_FIND_DATA fdata;
    HANDLE          fh;
    sprintf( t1, "%04.4x%.*s", rand(), le, e );

    /*HANDLE */
    fh = FindFirstFile( name, &fdata );
    if ( fh == INVALID_HANDLE_VALUE )
      return name;

    FindClose( fh );
  }

  t1 -= ln;

  // could not do it so try old way
  lstrcpy( t1, "ZipTmpXXXXXX" );  // Get a unique name.
  if ( mktemp( t1 ) == NULL )
  {
    FREE( nname );
    name = NULL;
  }

  return name;
}

#else
// Return a temporary file name in its own malloc'ed space, using tempath.
char *
tempname( struct ZGlobals *pG )
{
  char  *t;                     // Pointer for malloc'ed space for name.

  // Copy the tempath, if present, to t.
  if ( pG->tempath != NULL )
  {
    if ( (t = ( char * )MALLOC( lstrlen( pG->tempath ) + 14 )) == NULL )
      return NULL;
    lstrcpy( t, pG->tempath );
    if ( t[lstrlen( t ) - 1] != '\\' )
      lstrcat( t, "\\" );       // SLASH
  }
  else
  {
    if ( (t = ( char * )MALLOC( 14 )) == NULL )
      return NULL;
    *t = 0;
  }

  lstrcat( t, "ZipTmpXXXXXX" ); // Get a unique name.
  if ( mktemp( t ) == NULL )
  {
    FREE( t );
    return NULL;
  }

  if ( pG->Frame.Verbose )
    Notify( PF, IDIAG, "Temp filename: %s", t );
  return t;
}
#endif
char *__fastcall GetFullPath ( struct ZGlobals *pG, char *Filename )
{
  *( pG->ewetmp ) = 0;
  if ( !
       (
         (isalpha(Filename[0]) && Filename[1] == (char)':')
         || (Filename[0] == (char)'\\' && Filename[1] == (char)'\\')
       ) )
    lstrcpy( pG->ewetmp, pG->OrigCurrentDir );
  return lstrcat( pG->ewetmp, Filename );
}

#if 10
// new 1,72 Copy from file *f to file *g, until EOF Return an error code in
//   the ZEN_ class. b :: malloc'ed buffer for copying. k :: Result of fread().
//   m :: Bytes copied so far.
static int
filecopy( HANDLE f, HANDLE g, struct ZGlobals *pG )
{
  // char          *b;         // malloc'ed buffer for copying
  unsigned long cnt;            // bytes done
  ulg           m;              // bytes copied so far
  ulg           n;              // file size
  if ( pG->Frame.Verbose )
    Notify( PF, IDIAG, "Copying File" );

  n = GetFileSize( f, NULL );
  if ( n == 0xffffffff )        // 1.73.3.5
    return ZEN_READ09;

  //  if ( (b = (char *)MALLOC( CBSZ )) == NULL )
  //    return ZEN_MEM38;
  m = 0;
//  User(PF, zacXItem, 2, n, "Copying Temporary File");
  _CB_.Arg1 = 2;    // type
  _CB_.FileSize.lo = n;  
  _CB_.FileSize.hi = 0;
  _CB_.MsgP = "Copying Temporary File";
  User_CB(PF, zacXItem);  // Pass total
  ///filesize.
  while ( m < n && !pG->Frame.Abort_Flag )
  {
    //    cnt = ( n - m ) < CBSZ ? ( n - m ) : CBSZ;
    cnt = n - m;
    if ( cnt > ( unsigned long )WSIZE )
      cnt = ( unsigned long )WSIZE;

    if ( !ReadFile( f, pG->window /*b*/, cnt, &cnt, NULL ) )
    {
      //      FREE( b );
      return ZEN_READ02;
    }

    if ( !cnt )
      break;  // none read - finished
    if ( !WriteFile( g, pG->window /*b*/, cnt, &cnt, NULL ) )
    {
      //      FREE( b );
      Notify( PF, 0, " filecopy: write error\n" );
      return ZEN_TEMP04;
    }
    pG->BytesWritten += cnt;

    m += cnt;
//    User(PF, zacXProgress, 2, cnt, "");
    _CB_.Arg1 = 2;    // type
    _CB_.FileSize.lo = cnt;
    User_CB(PF, zacXProgress);
  }

  //  FREE( b );
  if ( pG->Frame.Abort_Flag )
    return ZEN_ABORT03;
  return ZEN_OK;
}
#endif  
// changed 1.71 - copies n bytes only (not to eof) Copy n bytes from file *f
//   to file *g. Return an error code in the ZEN_ class. b :: malloc'ed buffer
//   for copying. k :: Result of fread(). m :: Bytes copied so far.
int
fcopy( HANDLE f, HANDLE g, ulg n, struct ZGlobals *pG  )
{
  char  *b;   // malloc'ed buffer for copying

  // extent k; /* result of fread()
  ulg   k;
  ulg   m;    // bytes copied so far

  b = (char *) pG->window;
  m = 0;
  while ( m < n )
  {
    k = n - m;
    if ( k > ( unsigned long )WSIZE )
      k = ( unsigned long )WSIZE;
    if ( !ReadFile( f, b, k, &k, NULL ) )
    {
      return ZEN_READ02;
    }

    if ( !k )
      break;  // none read - finished
    if ( !WriteFile( g, b, k, &k, NULL ) )
    {
      //      FREE( b );
      Notify( PF, 0, " fcopy: write error\n" );
      return ZEN_TEMP04;
    }
    pG->BytesWritten += k;

    m += k;
//    User(PF, zacProgress, 0, k, NULL);//, pG );
    _CB_.Written.i64 = pG->BytesWritten;
    _CB_.FileSize.i64 = k;
    User_CB(PF, zacProgress);  // Added for progress bar support.
  }
 
  return ZEN_OK;
}


char * __fastcall CleanedPath(char *pth, struct ZGlobals *pG )
{
  char *r = pth;
  char *d = pG->ewemsg;
  const char * root = d;
  if ((*pth == (char)'\\' && pth[1] == (char)'\\') ||
        (*pth && pth[1] == (char)':'))
    root+= 2;
  for (; ;)
  {
    char c = *pth++;
    //    *d++ = c;
    if (!c)
      break;
    if (c == (char)'\\' && *pth == (char)'.')
    {
      if (pth[1] == (char)'\\')
      {
        pth+=2;
        r = pG->ewemsg;
      }
      else
        if (pth[1] == (char)'.' && pth[2] == (char)'\\')
        {
          pth+=3;
          *d = 0;
          while (d > root)
          {
            d--;
            if (*d == (char)'\\')
              break;
            *d = 0;
          }
          r = pG->ewemsg;
        }
    }
    *d++ = c;
  }
  *d = 0;
  return r;
}
