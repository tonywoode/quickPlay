#include <windows.h>
#include "Common.h"
#pragma hdrstop
#include "Zip.h" 
#include "ZipErr.h"

// ZipFile.c Copyright (C) 1990-1996
// Mark Adler, Richard B. Wales, Jean-loup Gailly, Kai Uwe Rommel,
// Onno van der Linden and Igor Mandrichenko.
// This version modified by Chris Vleghert and Eric Engler for BCB/Delphi Zip.
//* distributed under LGPL license ** see license.txt for details
// edited 19 October 2003 RP
//#include "zip.h"
//#include "ZGlobals.h"
#include "direct.h"

// Macros for converting integers in little-endian to machine format
// RCV Aded (ush)( ... ) to remove conversion warnings
#define SH( a ) ( ush ) ( ((ush) (uch) (a)[0]) | (((ush) (uch) (a)[1]) << 8) )
#define LG( a ) ( (ulg) SH( a ) | ((ulg) SH( (a) + 2 ) << 16) )

// Macros for writing machine integers to little-endian format
// define PUTSH( a, f ) {putc( (char)((a) &
// 0xFF),(f) ); putc( (char)((a) >> 8),(f) );}
// define PUTLG( a, f ) {PUTSH( (a) &
// 0xFFFF,(f) ) PUTSH( (a) >> 16,(f) )}
// -- Structure of a ZIP file --
// Signatures for zip file information headers
#define LOCSIG    0x04034b50L
#define CENSIG    0x02014b50L
#define ENDSIG    0x06054b50L
#define EXTLOCSIG 0x08074b50L

// Offsets of values in headers
#define LOCVER  0                     // version needed to extract
#define LOCFLG  2                     // encrypt, deflate flags
#define LOCHOW  4                     // compression method
#define LOCTIM  6                     // last modified file time, DOS format
#define LOCDAT  8                     // last modified file date, DOS format
#define LOCCRC  10                    // uncompressed crc-32 for file
#define LOCSIZ  14                    // compressed size in zip file
#define LOCLEN  18                    // uncompressed size
#define LOCNAM  22                    // length of filename
#define LOCEXT  24                    // length of extra field
#define EXTCRC  0                     // uncompressed crc-32 for file
#define EXTSIZ  4                     // compressed size in zip file
#define EXTLEN  8                     // uncompressed size
#define CENVEM  0                     // version made by
#define CENVER  2                     // version needed to extract
#define CENFLG  4                     // encrypt, deflate flags
#define CENHOW  6                     // compression method
#define CENTIM  8                     // last modified file time, DOS format
#define CENDAT  10                    // last modified file date, DOS format
#define CENCRC  12                    // uncompressed crc-32 for file
#define CENSIZ  16                    // compressed size in zip file
#define CENLEN  20                    // uncompressed size
#define CENNAM  24                    // length of filename
#define CENEXT  26                    // length of extra field
#define CENCOM  28                    // file comment length
#define CENDSK  30                    // disk number start
#define CENATT  32                    // internal file attributes
#define CENATX  34                    // external file attributes
#define CENOFF  38                    // relative offset of local header
#define ENDDSK  0                     // number of this disk
#define ENDBEG  2                     // number of the starting disk
#define ENDSUB  4                     // entries on this disk
#define ENDTOT  6                     // total number of entries
#define ENDSIZ  8                     // size of entire central directory
#define ENDOFF  12                    // offset of central on starting disk
#define ENDCOM  16                    // length of zip file comment

// Added R. Aelbrecht for OEM2ISO conversion
#define cpAUTO    0
#define cpISO     1
#define cpOEM     2

#define FS_FAT_   0                   // filesystem used by MS-DOS, OS/2, Win32
#define FS_HPFS_  6                   // filesystem used by OS/2, NT
#define FS_NTFS_  11                  // filesystem used by Windows NT

// Local functions
static int zqcmp( const void *, const void* );
static int rqcmp( const void *, const void* );
static int zbcmp( const void *, const void* );

#ifdef USE_EF_UX_TIME
static int ef_scan_ux_time( char *ef_buf, extent ef_len, ztimbuf *z_utim );
#endif
static void cutpath( char *p );

// Used by qsort() to compare entries in the zfile list. Compares the
//   internal names z->zname a, *b :: Pointers to pointers to zip entries.
static int zqcmp( const void *a, const void *b )
{
  return namecmp(( *( struct zlist ** )a )->zname, ( *( struct zlist ** )b )
                 ->zname );
}

// Used by qsort() to compare entries in the zfile list. Compare the
//   internal names z->zname, but in reverse order. a, *b :: Pointers to
//   pointers to zip entries.
static int rqcmp( const void *a, const void *b )
{
  return namecmp(( *( struct zlist ** )b )->zname, ( *( struct zlist ** )a )
                 ->zname );
}

// Used by search() to compare a target to an entry in the zfile list. n ::
//   String to search for. z :: Pointer to a pointer to a zip entry.
static int zbcmp( const void *n, const void *z )
{
  return namecmp(( char* )n, (( struct zlist* )z )->zname );
}

// Return a pointer to the entry in zfile with the name n, or NULL if not
//   found. n :: Name to find.
struct zlist *zsearch( char *n, struct ZGlobals *pG )
{
  void **p; // result of search()
  if ( pG->zcount && ( p = search( n, ( void ** )pG->zsort, pG->zcount, zbcmp ))
       != NULL )
    return *( struct zlist ** )p;
  return NULL;
}

#define PATHCUT '\\' \
\
// SLASH
// If the file name *s has a dot (other than the first char), or if the -A
//   option is used (adjust self-extracting file) then return the name,
//   otherwise append .zip to the name. Allocate the space for the name in
//   either case. Return a pointer to the new name, or NULL if malloc() fails.
//   s :: File name to force to zip.
char *ziptyp( char *s, struct ZGlobals *pG )
{
  char *q; // temporary pointer
  char *t; // pointer to malloc'ed string
  unsigned res = GetFullPathName( s, 2047, pG->ewemsg, &q );

  if (( t = ( char* )MALLOC( res + 5 )) == NULL )
    return NULL;

  lstrcpy( t, pG->ewemsg );

  if ( pG->adjust )
    return t;
  if ( strrchr(( q = strrchr( t, PATHCUT )) == NULL ? t : q + 1, '.' ) == NULL )
    lstrcat( t, ".zip" );
  return t;
}
/*
// RCV added; readzipfile didn't close the Zip archive in case of an error
//   this would prevent deletion of such a file until the application ended.
int
//AfterError2( int f, int Res )
AfterError( HANDLE *hf, int Res )
{
Close_Handle( hf );
if (Res < 0)
Res = GetLastError() ? ZEN_READ04 : ZEN_EOF02;
return Res;
}  */

/*
int
//AfterError1( int f )
AfterError1( HANDLE *hf )
{
//  int Res =  ferror ( f ) ? ZEN_READ04 : ZEN_EOF02;
//  int Res = errno  ? ZEN_READ04 : ZEN_EOF02;
int Res = GetLastError() ? ZEN_READ04 : ZEN_EOF02;
return AfterError2( hf, Res );
}   */

// Make first pass through zip file, reading information from local file
//   headers and then verifying that information with the central file headers.
//   Any deviation from the expected zip file format returns an error. At the
//   end, a sorted list of file names in the zip file is made to facilitate
//   searching by name. The name of the zip file is pointed to by the global
//   "zipfile". The globals zfiles, zcount, zcomlen, zcomment, and zsort are
//   filled in. Return an error code in the ZEN_xxx class.
static int readzipfile1( struct ZGlobals *pG, HANDLE hInz );
int readzipfile( struct ZGlobals *pG )
{
  HANDLE hInz;
  int r = 0;
  // If zip file exists, read headers and check structure
  if ( pG->zipfile != NULL )
  {
    if ( pG->Frame.Verbose )
    {
      Notify( PF, IDIAG, "ready to open: %s for read only", pG->zipfile );
    }
  }

  if ( pG->zipfile != NULL &&  *pG->zipfile && strcmp( pG->zipfile, "-" ) && (
         hInz = CreateFile( pG->zipfile, GENERIC_READ, 0, NULL, OPEN_EXISTING,
                            FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL ) ) !=
       INVALID_HANDLE_VALUE )
  {
    diag( "zip archive is now open", pG );
    r = readzipfile1( pG, hInz );
    Close_Handle( &hInz );
    if ( r < 0 )
      r = GetLastError() ? ZEN_READ04 : ZEN_EOF02;
  }
  return r;
}

//-------------------------------------------------------------------------

int readzipfile1( struct ZGlobals *pG, HANDLE hInz )
{
  ulg a = 0L; // attributes returned by filetime()
  char b[CENHEAD]; // buffer for central headers

  BY_HANDLE_FILE_INFORMATION finfo; // 1.75
  long w; // 1.75
  ush flg; // general purpose bit flag
  int m; // mismatch flag
  extent n; // length of name
  ulg p; // current file offset
  char r; // holds reserved bits during memcmp()
  ulg s; // size of data, start of central
  char *t; // temporary variable
  char *u; // temporary variable
  char *ptr; // temporary variable
  struct zlist **x; // pointer last entry's link
  struct zlist *z; // current zip entry structure
  ulg temp; // required to avoid Coherent compiler bug
  int zcomlentmp; // tmp var v1.60
  char *zcommenttmp = NULL; // tmp var v1.60

  // added R. Aelbrecht for OEM2ISO conversion
  char hostnum;
  char hostver;

  // Initialize zip file info
  pG->zipbeg = 0;
  pG->zfiles = NULL; // Points to first header

  // pG->zcomlen = 0; /* zip file comment length RCV removed v1.60
  // Get any file attribute valid for this OS, to set in the central
  //   directory when fixing the archive:
  if ( pG->fix && GetFileInformationByHandle( hInz, &finfo ))
  {
    a = finfo.dwFileAttributes;
  }

  x = &pG->zfiles; // first link
  p = 0; // starting file offset
  pG->zcount = 0; // number of files

  // Find start of zip structures
  for ( ;; )
  {
    while ( ReadFile( hInz, b, 1, (ulg*)&w, NULL ) && w == 1 && b[0] != 0x50 )
      p++;
    // 0x50 == 'P'
    if ( !ReadFile( hInz, b + 1, 3, (ulg*)&w, NULL )
            || w != 3 || ( s = LG( b )) == LOCSIG || s == ENDSIG )
      break;
    w =  - 1;

    // 1.75.2.2 RA fix count
    p += 4;
    if ( b[1] == 0x50 || b[2] == 0x50 || b[3] == 0x50 )
    {
      if ( SetFilePointer( hInz,  - 3, &w, SEEK_CUR ) ==
           INVALID_SET_FILE_POINTER && GetLastError())
        return  - 1;
      // AfterError1( &hInz );
      p -= 3;
    }

    // p++;
  }

  pG->zipbeg = p;

  // Read local headers
  while ( LG( b ) == LOCSIG )
  {
    // Read local header raw to compare later with central header (this
    //   requires that the offest of ext in the zlist structure be greater
    //   than or equal to LOCHEAD)
    if (( z = ( struct zlist* )MALLOC( sizeof( struct zlist ))) == NULL )
      //        return AfterError2( f, ZEN_MEM25 );
      return ZEN_MEM25;
    // AfterError2( &hInz, ZEN_MEM25 );

    // 1.73 RP clear all fields
    memset( z, 0, sizeof( struct zlist ));

    //   if ( read( f, b, LOCHEAD ) != LOCHEAD )
    if ( !ReadFile( hInz, b, LOCHEAD, (ulg*)&w, NULL ) || w != LOCHEAD )
    {
      if ( pG->fix )
        break;
      else
        return  - 1;
      //AfterError1( &hInz ); //f );
    }

    if ( pG->fix )
    {
      z->ver = SH( LOCVER + b );

      // RCV Added below (ush)( ... )
      z->vem = ( ush )( pG->dosify ? 20 : OS_CODE + 22 ); // 22 = REVISION
      z->options.dosflag = pG->dosify ? 1 : 0;
      flg = z->flg = z->lflg = SH( LOCFLG + b );
      z->how = SH( LOCHOW + b );
      z->tim = LG( LOCTIM + b ); // time and date into one long
      z->crc = LG( LOCCRC + b );
      z->siz = LG( LOCSIZ + b );
      z->len = LG( LOCLEN + b );
      n = z->nam = SH( LOCNAM + b );
      z->cext = z->ext = SH( LOCEXT + b );
      z->com = 0;
      z->passw = z->comment = 0; // RP173
      z->dsk = 0;
      z->att = 0;
      z->atx = pG->dosify ? a &0xFF: a; // Attributes from filetime()
      z->mark = 0;
      z->trash = 0;
      s = pG->fix > 1 ? 0L : z->siz; // discard compressed size with -FF
    }
    else
    {
      t = b;
      u = ( char* )z;
      n = LOCHEAD;
      do
      {
        *u++ =  *t++;
      }
      while ( --n );
      z->ext = SH( LOCEXT + ( uch* )z )
               ;
      n = SH( LOCNAM + ( uch* )z );
      flg = SH( b + LOCFLG );
      s = LG( LOCSIZ + ( uch* )z );
    }

    // Link into list
    *x = z;
    z->nxt = NULL;
    x = &z->nxt;

    // Read file name and extra field and skip data
    if ( n == 0 )
    {
      Notify( PF, IWARNING, "zero-length name for entry #%d", ( ulg )pG
              ->zcount + 1 );
#ifndef DEBUG
      //        return AfterError2( f, ZEN_FORM01 );
      return ZEN_FORM01; //AfterError2( &hInz, ZEN_FORM01 );
#endif

    }

    if (( z->zname = ( char* )MALLOC( n + 1 )) == NULL || ( z->ext && ( z
        ->extra = ( char* )MALLOC( z->ext )) == NULL ))
      //     return AfterError2( f, ZEN_MEM26 );
      return ZEN_MEM16;
    //AfterError2( &hInz, ZEN_MEM26 );

    //   if ( read( f, z->zname, n ) != (int)n
    //         || (z->ext && read( f, z->extra, z->ext ) != (int)z->ext)
    //     || (s && lseek( f, s, SEEK_CUR ) == -1) )
    //     return AfterError1( hInz );//f );
    if ( !ReadFile( hInz, z->zname, n, (ulg*)&w, NULL ) || w != ( long )n || (
           z->ext && ( !ReadFile( hInz, z->extra, z->ext, (ulg*)&w, NULL ) || (
                         ulg )w != z->ext ) ))
      return  - 1;
    //AfterError1( &hInz );
    w = 0;
    if ( s && SetFilePointer( hInz, s, &w, SEEK_CUR ) ==
         INVALID_SET_FILE_POINTER && GetLastError())
      return  - 1;
    // AfterError1( &hInz );

    // If there is an extended local header, s is either 0 or the correct
    //   compressed size.
    z->zname[n] = 0; // terminate name
    for ( ptr = z->zname;  *ptr; ptr++ )
      if ( *ptr == (char)'/' )
        *ptr = '\\';
    // SLASH ADDED
    if ( pG->fix )
    {
      z->cextra = z->extra;
      if ( pG->noisy )
        Notify( PF, 0, "zip: reading %s\n", z->zname );
    }

    z->name = in2ex( z->zname ); // convert to external name
    if ( z->name == NULL )
      //        return AfterError2( f, ZEN_MEM27 );
      return ZEN_MEM27;
    //AfterError2( &hInz, ZEN_MEM27 );       
//Notify( PF, 0, "zip: read local %s", z->zname );

    // Save offset, update for next header
    z->off = p;
    p += 4+LOCHEAD + n + z->ext + s;
    pG->zcount++;

    // Skip extended local header if there is one
    if (( flg &8 ) != 0 )
    {
      // Skip the compressed data if compressed size is unknown. For
      //   safety, we should use the central directory.
      if ( s == 0 )
      {
        ulg sfp;
        for ( ;; )
        {
          //   while ( read( f, b, 1 ) == 1 && b[0] != 0x50 )
          //              ;                                 // 0x50 == 'P'
          while ( ReadFile(hInz, b, 1, (ulg*)&w, NULL ) && w == 1 && b[0] !=
                  0x50 )
            ;

          //   if ( read( f, b + 1, 15 ) != 15 || LG( b ) == EXTLOCSIG )
          if ( !ReadFile( hInz, b + 1, 15, (ulg*)&w, NULL ) || w != 15 || LG(
                 b ) == EXTLOCSIG )
            break;
          w =  - 1;

          //      if ( lseek( f, -15L, SEEK_CUR ) == -1 )
          if ( SetFilePointer( hInz,  - 15L, &w, SEEK_CUR ) ==
               INVALID_SET_FILE_POINTER && GetLastError())
            return  - 1;
          //AfterError1( &hInz );  //f );
        }

        s = LG( 4+EXTSIZ + b );
        p += s;

        //          if ( (ulg) lseek( f, 0, SEEK_CUR ) != p + 16L )
        w = 0;
        sfp = SetFilePointer( hInz, 0, &w, FILE_CURRENT );
        if ( sfp == INVALID_SET_FILE_POINTER && GetLastError())
          w =  - 1;
        if (( sfp != p + 16L ) || w )
        {
          Notify( PF, IWARNING, "bad extended local header for : %s", z
                  ->zname );

          //            return AfterError2( f, ZEN_FORM02 );
          return ZEN_FORM02; // AfterError2( &hInz, ZEN_FORM02 );
        }
      }
      else
      {
        // compressed size non zero, assume that it is valid:
        //     Assert(p == (ulg) lseek( f, 0, SEEK_CUR ), // ftell ( f ),
        w = 0;
        //        Assert(( p == ( ulg )SetFilePointer( f, 0, &w, SEEK_CUR ) && !w &&
        //               !GetLastError()), ("bad compressed size with extended header"), (0) );

        //          if ( lseek( f, p, SEEK_SET ) == -1 || read( f, b, 16 ) != 16 )
        //      return AfterError1( f );
        w = 0;
        if ( SetFilePointer( hInz, p, &w, SEEK_SET ) ==
             INVALID_SET_FILE_POINTER && GetLastError())
          return  - 1;
        // AfterError1( &hInz );
        if ( !ReadFile( hInz, b, 16, (ulg*)&w, NULL ) || w != 16 )
          return  - 1;
        // AfterError1( &hInz );
        if ( LG( b ) != EXTLOCSIG )
        {
          Notify( PF, IWARNING, "extended local header not found for :%s", z
                  ->zname );

          //            return AfterError2( f, ZEN_FORM03 );
          return ZEN_FORM03; // AfterError2( &hInz, ZEN_FORM03 );
        }
      }

      // overwrite the unknown values of the local header:
      if ( pG->fix )
      {
        // already in host format
        z->crc = LG( 4+EXTCRC + b );
        z->siz = s;
        z->len = LG( 4+EXTLEN + b );
      }
      else
      {
        // Keep in Intel format for comparison with central header
        t = b + 4;
        u = ( char* )z + LOCCRC;
        n = 12;
        do
        {
          *u++ =  *t++;
        }
        while ( --n );
      }

      p += 16L;
    }
    else
      if ( pG->fix > 1 )
      {
        // Don't trust the compressed size
        for ( ;; )
        {
          //          while ( read( f, b, 1 ) == 1 && b[0] != 0x50 )
          while ( ReadFile( hInz, b, 1, (ulg*)&w, NULL ) && w == 1 && b[0] !=
                  0x50 )
            p++;
          // 0x50 == 'P'

          //          if ( read( f, b + 1, 3 ) != 3 || (s = LG( b )) == LOCSIG || s == CENSIG )
          if ( !ReadFile( hInz, b + 1, 3, (ulg*)&w, NULL ) || w != 3 || ( s = LG
               ( b )) == LOCSIG || s == CENSIG )
            break;

          //     if ( lseek( f, -3L, SEEK_CUR ) == -1 )
          //      return AfterError1( f );
          w =  - 1;
          if ( SetFilePointer( hInz,  - 3, &w, SEEK_CUR ) ==
               INVALID_SET_FILE_POINTER && GetLastError())
            return  - 1;
          //AfterError1( &hInz );
          p++;
        }

        s = p - ( z->off + 4+LOCHEAD + n + z->ext );
        if ( s != z->siz )
        {
          Notify( PF, 0, " compressed size %ld, actual size %ld for %s\n", z
                  ->siz, s, z->zname );
          z->siz = s;
        }

        // next LOCSIG already read at this point, don't read it again:
        continue;
      }

    // Read next signature
    //      if ( read( f, b, 4 ) != 4 )
    if ( !ReadFile( hInz, b, 4, (ulg*)&w, NULL ) || w != 4 )
    {
      if ( pG->fix )
        break;
      else
        return  - 1;
      //AfterError1( &hInz ); //f );
    }
  }

  // Point to start of header list and read central headers
  z = pG->zfiles;
  s = p; // save start of central
  if ( pG->fix )
  {
    if ( LG( b ) != CENSIG && pG->noisy )
    {
      Notify( PF, 0, "zip warning: %s %s truncated.\n", pG->zipfile, pG->fix
              > 1 ? "has been" : "would be" );
      if ( pG->fix == 1 )
      {
        ziperr( ZEN_FORM04, pG );
      }
    }
  }
  else
  {
    while ( LG( b ) == CENSIG )
    {
      if ( z == NULL )
      {
        Notify( PF, IWARNING, "extraneous central header signature" );

        //          return AfterError2( f, ZEN_FORM05 );
        return ZEN_FORM05; // AfterError2( &hInz, ZEN_FORM05 );
      }

//Notify( PF, IWARNING, "Reading Central entry for: %s", z->zname );  /* TODO : remove */
      // Read central header
      //    if ( read( f, b, CENHEAD ) != CENHEAD )
      if ( !ReadFile( hInz, b, CENHEAD, (ulg*)&w, NULL ) || w != CENHEAD )
        return  - 1;
      // AfterError1( &hInz );               //f );

      // Compare local header with that part of central header (except for
      //   the reserved bits in the general purpose flags and except for
      //   length of extra fields--authentication can make these different in
      //   central and local headers)
      z->lflg = SH( LOCFLG + ( uch* )z ); // Save reserved bits
      r = b[CENFLG + 1];
      (( uch* )z )[LOCFLG + 1] &= 0x1f; // Zero out reserved bits
      b[CENFLG + 1] &= 0x1f;
      for ( m = 0, u = ( char* )z, n = 0; n < LOCHEAD - 2; n++ )
      {
        if ( u[n] != b[n + 2] )
        {
          if ( !m && pG->noisy )
          {
            Notify( PF, IWARNING, "local and central headers differ for :%s",
                    z->zname );
          }

          m = 1;
          if ( pG->noisy )
          {
            Notify( PF, IWARNING, " offset %d--local = %02x, central = %02x",
                    ( int )n, ( uch )u[n], ( uch )b[n + 2] );
          }

          b[n + 2] = u[n]; // fix the zipfile
        }
      }

      if ( m )
        return ZEN_FORM06;
      // AfterError2( &hInz, ZEN_FORM06 );
      b[CENFLG + 1] = r; // Restore reserved bits

      // Overwrite local header with translated central header
      z->vem = SH( CENVEM + b );
      z->ver = SH( CENVER + b );
      z->flg = SH( CENFLG + b ); // may be different from z->lflg
      z->how = SH( CENHOW + b );
      z->tim = LG( CENTIM + b ); // time and date into one long
      z->crc = LG( CENCRC + b );
      z->siz = LG( CENSIZ + b );
      z->len = LG( CENLEN + b );
      z->nam = SH( CENNAM + b );
      z->cext = SH( CENEXT + b ); // may be different from z->ext
      z->com = SH( CENCOM + b );
      z->dsk = SH( CENDSK + b );
      z->att = SH( CENATT + b );
      z->atx = LG( CENATX + b );
      z->options.dosflag = (( z->vem &0xFF00 ) == 0)? 1 : 0;
      z->options.level = pG->level;
      z->options.noext = 0;
      temp = LG( CENOFF + b ); // to avoid Coherent compiler bug
      if ( z->off != temp )
        // && !pG->adjust )
      {
        if ( !pG->adjust )
        {
          Notify( PF, IWARNING,
                  "local offset in central header incorrect for :%s", z->zname );
          return ZEN_FORM07; //AfterError2( &hInz, ZEN_FORM07 );
        }

        pG->adjust =  - 1;
        if ( pG->noisy )
        {
          Notify( PF, IWARNING,
                  " Will adjust local offset in central header for SFX stub change" );
        }
      }

      // Compare name and extra fields and read comment field
      if (( t = ( char* )MALLOC( z->nam )) == NULL )
        return ZEN_MEM28;
      //AfterError2( hInz, ZEN_MEM28 );

      if ( !ReadFile( hInz, t, z->nam, (ulg*)&w, NULL ) || w != ( int )z->nam )
      {
        FREE( t );
        return  - 1; // AfterError1( &hInz );
      }

      // BUG fix 1.54
      for ( ptr = t; ( ulg )( ptr - t ) < z->nam; ptr++ )
        if ( *ptr == (char)'/' )
          *ptr = '\\';
      // SLASH Added
      if ( memcmp( t, z->zname, z->nam ))
      {
        FREE( t );
        Notify( PF, IWARNING, "names in local and central differ for :%s", z
                ->zname );

        return ZEN_FORM08; // AfterError2( &hInz, ZEN_FORM08 );
      }

      // added R. Aelbrecht to allow delete with OEM2ISO conversion
      // we check if name is from OEM char set convert if needed
      hostnum = ( b + CENVEM )[1];
      hostver = ( b + CENVEM )[0];
      if ( pG->WantedCodePage == cpAUTO && ( hostnum == FS_FAT_ || hostnum ==
                                             FS_HPFS_ || ( hostnum == FS_NTFS_ && hostver == 50 ) ) || pG
           ->WantedCodePage == cpOEM )
        OemToCharBuff( z->zname, z->zname, strlen( z->zname ));

      // end add
      FREE( t );
      if ( z->cext )
      {
        if (( z->cextra = ( char* )MALLOC( z->cext )) == NULL )
          return ZEN_MEM29;
        //AfterError2( &hInz, ZEN_MEM29 );  // 1.75 was just return error no
        if ( !ReadFile( hInz, z->cextra, z->cext, (ulg*)&w, NULL ) || w != (
               int )z->cext )
        {
          FREE( z->cextra );
          return  - 1; //AfterError1( &hInz );             //f );
        }

        if ( z->ext == z->cext && memcmp( z->extra, z->cextra, z->ext ) == 0 )
        {
          FREE( z->cextra );
          z->cextra = z->extra;
        }
      }

      if ( z->com )
      {
//        if (( z->comment = ( char* )MALLOC( z->com )) == NULL )
        if (( z->comment = ( char* )MALLOC( z->com + 1)) == NULL )
          return ZEN_MEM30;
        //AfterError2( &hInz, ZEN_MEM30 );

        if ( !ReadFile( hInz, z->comment, z->com, (ulg*)&w, NULL ) || w != (
               int )z->com )
        {
          FREE( z->comment );
          return  - 1; // AfterError1( &hInz );             //f );
        }
        z->comment[z->com] = 0;
      }

      // Note oddities
      if ( pG->Frame.Verbose )
      {
        if (( n = z->vem >> 8 ) >= NUM_HOSTS )
        {
          Notify( PF, IWARNING,
                  "%s made by version %d.%d on system type %d: ", z->zname, (
                    ush )( z->vem &0xFF ) / ( ush )10, ( ush )( z->vem &0xFF ) % (
                    ush )10, z->vem >> 8 );
        }

        if ( z->ver != 10 && z->ver != 11 && z->ver != 20 )
        {
          Notify( PF, IWARNING, "%s needs unzip %d.%d on system type %d: ",
                  z->zname, ( ush )( z->ver &0xFF ) / ( ush )10, ( ush )( z->ver
                      &0xFF ) % ( ush )10, z->ver >> 8 );
        }

        if ( z->how > DEFLATE )
        {
          Notify( PF, IWARNING, "unknown compression method %u: :%s", z->how,
                  z->zname );
        }

        if ( z->dsk )
        {
          Notify( PF, IWARNING, "starts on disk %u: %s", z->dsk, z->zname );
        }

        if ( z->att &~1 )
        {
          Notify( PF, IWARNING, "unknown internal attributes = 0x%04x: %s",
                  z->att, z->zname );
        }
      }

      // Clear actions
      z->mark = 0;
      z->trash = 0;

      // Update file offset
      p += 4+CENHEAD + z->nam + z->cext + z->com;

      // Advance to next header structure
      z = z->nxt;

      // Read next signature
      if ( !ReadFile( hInz, b, 4, (ulg*)&w, NULL ) || w != 4 )
        return  - 1;
      //AfterError1( &hInz );
    }
  }

  // Read end header
  if ( !pG->fix )
  {
//if ( /*z != NULL ||*/ LG( b ) != ENDSIG )
//  Notify( PF, IWARNING, "missing end signature %x ",  LG( b ));
    if ( z != NULL || LG( b ) != ENDSIG )
    {
      Notify( PF, IWARNING, "missing end signature");
//              "missing end signature--probably not a zip file (did you " );
//      Notify( PF, IWARNING,
//              "remember to use binary mode when you transferred it?)" );

      return ZEN_FORM09; //AfterError2( &hInz, ZEN_FORM09 );
    }

    if ( !ReadFile( hInz, b, ENDHEAD, (ulg*)&w, NULL ) || w != ENDHEAD )
      return  /*AfterError2( &hInz,*/GetLastError ? ZEN_READ05 : ZEN_EOF03;
    // );
    if ( SH( ENDDSK + b ) || SH( ENDBEG + b ) || SH( ENDSUB + b ) != SH( ENDTOT
         + b ))
      Notify( PF, IWARNING, "multiple disk information ignored" );
    if ( pG->zcount != ( extent )( SH( ENDSUB + b )))
    {
      Notify( PF, IWARNING, "count in end of central directory incorrect" );

      return ZEN_FORM10; //AfterError2( &hInz, ZEN_FORM10 );
    }

    temp = LG( ENDSIZ + b );
    if ( temp != p - s )
    {
      Notify( PF, IWARNING,
              "central directory size is incorrect (made by stzip?)" );

      // stzip 0.9 gets this wrong, so be tolerant
      // return ZEN_FORM??;
    }

    temp = LG( ENDOFF + b );
    if ( temp != s )
      // && !pG->adjust )
    {
      if ( !pG->adjust )
      {
        Notify( PF, IWARNING, "central directory start is incorrect", z
                ->zname );
        return ZEN_FORM01; // AfterError2( &hInz, ZEN_FORM07 );
      }

      pG->adjust =  - 1;
      if ( pG->noisy )
      {
        Notify( PF, IWARNING,
                " Will adjust central directory start for SFX stub change" );
      }

      return ZEN_FORM11; //AfterError2( &hInz, ZEN_FORM11 );
    }
  }

  pG->cenbeg = s;

  // Not needed anymore since the archive comment is read in the component
  //   but we need to skip the filecomment if present v1.60
  zcomlentmp = pG->fix ? 0 : SH( ENDCOM + b );
  if ( zcomlentmp )
  {
    if (( zcommenttmp = ( char* )MALLOC( zcomlentmp )) == NULL )
      return ZEN_MEM31;
    //AfterError2( &hInz, ZEN_MEM31 );

    if ( !ReadFile( hInz, zcommenttmp, zcomlentmp, (ulg*)&w, NULL ) || w !=
         zcomlentmp )
    {
      FREE( zcommenttmp );
      return  - 1; // AfterError1( &hInz ); //f );
    }
  }

  if ( zcommenttmp )
    FREE( zcommenttmp );

  // pG->zcomlen = pG->fix ? 0 : SH( ENDCOM + b );
  // if ( pG->zcomlen )
  //{
  //   if ( (pG->zcomment = MALLOC( pG->zcomlen )) == NULL )
  //      return AfterError2(f, ZEN_MEM31 );
  //   if ( fread( pG->zcomment, pG->zcomlen, 1, f ) != 1 )
  //   {
  //      FREE( pG->zcomment );
  //      return AfterError1( f );
  //   }
  //}
  if ( pG->zipbeg && pG->Frame.Verbose )
  {
    // This is most likely the size of the self-extracting code
    Notify( PF, IWARNING, "%s has a preamble of %lu bytes", pG->zipfile, pG
            ->zipbeg );
  }

  if ( !pG->fix && ReadFile( hInz, b, 1, (ulg*)&w, NULL ) && w == 1 )
    Notify( PF, IWARNING, "garbage at end of zip file ignored" );

  // Done with zip file for now
  //    Close_Handle( &hInz );

  // If one or more files, sort by name
  if ( pG->zcount )
  {
    if (( x = pG->zsort = ( struct zlist ** )MALLOC( pG->zcount *sizeof( struct
                          zlist* ))) == NULL )
      return ZEN_MEM32;
    for ( z = pG->zfiles; z != NULL; z = z->nxt )
      *x++ = z;
    qsort(( char* )pG->zsort, pG->zcount, sizeof( struct zlist* ), zqcmp );
  }
  //  } // End of if ( zipfile != NULL...

  return ZEN_OK;
}

// This will put the filename fn with '\' changed into '/' in fnamebuf used
//   for output to the zipfile. fn :: Filename with possible backward slashes
//   in it.
static char *ChangeBWSlash( char *fn, struct ZGlobals *pG )
{
  unsigned int i;

  strncpy( pG->fnamebuf, fn, MAX_PATH );
  pG->fnamebuf[MAX_PATH - 1] = '\0'; // truncate the name if longer than
  ///MAX_PATH.
  for ( i = 0; pG->fnamebuf[i]; i++ )
    if ( pG->fnamebuf[i] == (char)'\\' )
      pG->fnamebuf[i] = '/';
  return pG->fnamebuf;
}

// Write a local header described by *z to file *f. Return ZEN_OK or
//   ZEN_TEMP07. z :: Zip entry to write local header for. f :: File to write
//   to.
int putlocal( struct zlist *z, HANDLE f, struct ZGlobals *pG )
{
  unsigned long k;
  struct ZipLocalHeader zlh;
  if ( pG->Frame.Verbose < 0 )
  {
    Notify( PF, IDIAG, "writing Local Header: %s", z->name );
  }

  zlh.HeaderSig = LOCSIG; // Should be 0x04034B50
  zlh.VersionNeed = z->ver;
  zlh.Flag = z->lflg;
  zlh.ComprMethod = z->how;
  zlh.ModifStamp = z->tim;
  zlh.CRC32 = z->crc;
  zlh.ComprSize = z->siz;
  zlh.UnComprSize = z->len;
  zlh.FileNameLen = ( ush )z->nam;
  zlh.ExtraLen = ( ush )z->ext;
  if ( !WriteFile( f, &zlh, sizeof( struct ZipLocalHeader ), &k, NULL ) || k !=
       sizeof( struct ZipLocalHeader ))
    return ZEN_TEMP07;
  pG->BytesWritten += k;
  if ( !WriteFile( f, ChangeBWSlash( z->zname, pG ), z->nam, &k, NULL ) || k !=
       z->nam )
    return ZEN_TEMP07;
  pG->BytesWritten += k;
  if ( z->ext )
  {
    if ( !WriteFile( f, z->cextra, z->ext, &k, NULL ) || k != z->ext )
      return ZEN_TEMP07;
    pG->BytesWritten += k;
  }
  return ZEN_OK;
}

// Write an extended local header described by *z to file *f. Return an
//   error code in the ZEN_ class. z :: Zip entry to write local header for. f
//   :: File to write to.
int putextended( struct zlist *z, HANDLE f, struct ZGlobals *pG )
{
  unsigned long k;
  struct ZipDataDescriptor zdd;
  zdd.DataDescSig = EXTLOCSIG;
  zdd.CRC32 = z->crc;
  zdd.ComprSize = z->siz;
  zdd.UnComprSize = z->len;
  if ( !WriteFile( f, &zdd, sizeof( struct ZipDataDescriptor ), &k, NULL ) || k
       != sizeof( struct ZipDataDescriptor ))
    return ZEN_TEMP09;
  pG->BytesWritten += k;
  return ZEN_OK;
}

// Write a central header described by *z to file *f. Return an error code
//   in the ZEN_ class. z :: Zip entry to write central header for. f :: File
//   to write to.
int putcentral( struct zlist *z, HANDLE f, struct ZGlobals *pG )
{
  unsigned long k;
  struct ZipCentralHeader zch;
  zch.HeaderSig = CENSIG;
  zch.MadeBy = z->vem;
  zch.VersionNeed = z->ver;
  zch.Flag = z->flg;
  zch.ComprMethod = z->how;
  zch.ModifStamp = z->tim;
  zch.CRC32 = z->crc;
  zch.ComprSize = z->siz;
  zch.UnComprSize = z->len;
  zch.FileNameLen = ( ush )z->nam;
  zch.ExtraLen = ( ush )z->cext;
  zch.FileComLen = ( ush )z->com;
  zch.DiskStart = z->dsk;
  zch.IntFileAtt = z->att;
  zch.ExtFileAtt = z->atx;
  zch.RelOffLocal = z->off;
  if ( !WriteFile( f, &zch, sizeof( struct ZipCentralHeader ), &k, NULL ) || k
       != sizeof( struct ZipCentralHeader ))
    return ZEN_TEMP08;
  pG->BytesWritten += k;
  if ( !WriteFile( f, ChangeBWSlash( z->zname, pG ), z->nam, &k, NULL ) || k !=
       z->nam )
    return ZEN_TEMP08;
  pG->BytesWritten += k;
  if ( z->cext )
  {
    if ( !WriteFile( f, z->cextra, z->cext, &k, NULL ) || k != z->cext )
      return ZEN_TEMP08;
    pG->BytesWritten += k;
  }
  if ( z->com )
  {
    if ( !WriteFile( f, z->comment, z->com, &k, NULL ) || k != z->com )
      return ZEN_TEMP08;
    pG->BytesWritten += k;
  }
  return ZEN_OK;
}

// Write the end of central directory data to file *f. Return ZEN_OK or
//   ZEN_TEMP09. n :: Number of entries in central directory. s :: Size of
//   central directory. c :: Offset of central directory. m :: Length of zip
//   file comment (0 if none). z :: Zip file comment if m != 0. f :: File to
//   write to.
int
//putend( int n, ulg s, ulg c, extent m, char *z, HANDLE f )
putend( int n, ulg s, ulg c, HANDLE f, struct ZGlobals *pG )
{
  unsigned long k;
  struct ZipEndOfCentral eoc;
  eoc.HeaderSig = ENDSIG;
  eoc.CentralDiskNo = eoc.ThisDiskNo = 0;
  eoc.CentralEntries = ( ush )n;
  eoc.TotalEntries = ( ush )n;
  eoc.CentralSize = s;
  eoc.CentralOffset = c;
  eoc.ZipCommentLen = ( ush )pG->zcomlen;
  if ( !WriteFile( f, &eoc, sizeof( struct ZipEndOfCentral ), &k, NULL ) || k
       != sizeof( struct ZipEndOfCentral ))
    return ZEN_TEMP09;
  pG->BytesWritten += k;
  if ( pG->zcomlen && pG->zcomment )
  {
    if ( !WriteFile( f, pG->zcomment, pG->zcomlen, &k, NULL ) || k != (
           unsigned )pG->zcomlen )
      return ZEN_TEMP09;
    pG->BytesWritten += k;
  }
  return ZEN_OK;
}

// Note: a zip "entry" includes a local header (which includes the file
//   name), an encryption header if encrypting, the compressed data and
//   possibly an extended local header.
// Copy the zip entry described by *z from file *x to file *y. Return an
//   error code in the ZEN_ class. Also update tempzn by the number of bytes
//   copied. z :: Zip entry to copy. x, *y :: Source and destination files.
int zipcopy( struct zlist *z, HANDLE x, HANDLE y, struct ZGlobals *pG )
{
  // added R. Aelbrecht for OEM2ISO conversion
  int hostnum;
  int hostver;
  ulg n; // holds local header offset
  Trace(( "zipcopy %s\n", z->zname ));
  n = ( ulg )( 4+LOCHEAD ) + ( ulg )z->nam + ( ulg )z->ext;

  if ( pG->fix > 1 )
  {
    unsigned bw;
    // if ( fseek ( x, z->off + n, SEEK_SET ) ) /* seek to compressed data
    // return ferror ( x ) ? ZEN_READ06 : ZEN_EOF04;
    // seek to compressed data
    long hi = 0;
    if ( SetFilePointer( x, z->off + n, &hi, FILE_BEGIN ) ==
         INVALID_SET_FILE_POINTER && GetLastError())
      return ZEN_READ06;

    //      return GetLastError() ? ZEN_READ06 : ZEN_EOF04;
    if ( pG->fix > 2 )
    {
      // Update length of entry's name, it may have been changed. This is
      //   needed to support the ZipNote ability to rename archive entries.
      z->nam = lstrlen( z->zname );
      n = ( ulg )( 4+LOCHEAD ) + ( ulg )z->nam + ( ulg )z->ext;
    }
    bw = pG->BytesWritten;
    // do not trust the old compressed size
    if ( putlocal( z, y, pG ) != ZEN_OK )
      return ZEN_TEMP10;
    pG->BytesWritten = bw;
    z->off = (unsigned)pG->tempzn;
    pG->tempzn += n;
    n = z->siz;
  }
  else
  {
    // if ( fseek ( x, z->off, SEEK_SET ) ) /* seek to local header
    // return ferror ( x ) ? ZEN_READ07 : ZEN_EOF05;
    // seek to local header
    long hi = 0;
    if ( SetFilePointer( x, z->off, &hi, FILE_BEGIN ) ==
         INVALID_SET_FILE_POINTER && GetLastError())
      return ZEN_READ07;

    //      return GetLastError() ? ZEN_READ07 : ZEN_EOF04;
    z->off = (unsigned)pG->tempzn;
    n += z->siz;
  }

  // copy the compressed data and the extended local header if there is one
  if ( z->lflg &8 )
    n += 16;
  pG->tempzn += n;

  // added R. Aelbrecht to allow delete with OEM2ISO conversion
  // check if original was made with OEM charset reconvert name if it was
  hostnum = ( z->vem &0xFF00 ) >> 8;
  hostver = z->vem &0xFF;

  if ( pG->WantedCodePage == cpAUTO && ( hostnum == FS_FAT_ || hostnum ==
                                         FS_HPFS_ || ( hostnum == FS_NTFS_ && hostver == 50 ) ) || pG
       ->WantedCodePage == cpOEM )
    CharToOemBuff( z->zname, z->zname, strlen( z->zname ));

//  User(PF, zacItem, 0, n /*z->siz*/, z->name);
    _CB_.Written.i64 = pG->BytesWritten;
    _CB_.FileSize.i64 = n;
    _CB_.MsgP = z->zname;
    User_CB(PF, zacItem);
  // end add
  return fcopy( x, y, n, pG );
}

//-------------------------------------------------------------------------

#ifdef USE_EF_UX_TIME

// This function scans the extra field for a IZUNIX block containing Unix
//   style time_t (GMT) values for the entry's access and modification time. If
//   a valid block is found, both time stamps are copied to the ztimebuf
//   structure. The return value is 1 (TRUE) in case of success, 0 otherwise.
//   ef_buf :: Buffer containing extra field. ef_len :: Total length of extra
//   field. z_utim :: Return storage: atime and mtime.
static int ef_scan_ux_time( char *ef_buf, extent ef_len, ztimbuf *z_utim )
{
  int r = 0;
  unsigned eb_id;
  extent eb_len;

  if ( ef_len == 0 || ef_buf == NULL )
    return 0;

  Trace(( "ef_scan_ux_time: scanning extra field of length %u\n", ef_len ));
  while ( ef_len >= EB_HEADSIZE )
  {
    eb_id = SH( EB_ID + ef_buf );
    eb_len = SH( EB_LEN + ef_buf );

    if ( eb_len > ( ef_len - EB_HEADSIZE ))
    {
      // Discovered some extra field inconsistency!
      Trace(( "ef_scan_ux_time: block length %u > rest ef_size %u\n", eb_len,
              ef_len - EB_HEADSIZE ));
      break;
    }

    if ( eb_id == EF_IZUNIX && eb_len >= EB_UX_MINLEN )
    {
      Trace(( "ef_scan_ux_time: Found IZUNIX extra field\n" ));
      z_utim->actime = LG(( EB_HEADSIZE + EB_UX_ATIME ) + ef_buf );
      z_utim->modtime = LG(( EB_HEADSIZE + EB_UX_MTIME ) + ef_buf );
      Trace(( "  Unix EF access time = %ld\n", z_utim->actime ));
      Trace(( "  Unix EF modif. time = %ld\n", z_utim->modtime ));
      r = 1; // signal success
      break;
    }

    // Skip this extra field block
    ef_buf += ( eb_len + EB_HEADSIZE );
    ef_len -= ( eb_len + EB_HEADSIZE );
  }

  return r;
}

//-------------------------------------------------------------------------

int get_ef_ux_ztime( struct zlist *z, ztimbuf *z_utim )
{
  int r;

  // First, scan local extra field.
  r = ef_scan_ux_time( z->extra, z->ext, z_utim );

  // If this was not successful, try central extra field, but only if is
  //   really different.
  if ( !r && z->cext > 0 && z->cextra != z->extra )
    r = ef_scan_ux_time( z->cextra, z->cext, z_utim );

  return r;
}

#endif

// USE_EF_UX_TIME
// If we do not have a full path then FOF_ALLOWUNDO does not work!
int Erase_File( struct ZGlobals *pG, char *Fname )
{
  SHFILEOPSTRUCT SHF;
  struct stat   StatRes;

  if (SSTAT(Fname, &StatRes))
      return ENOENT;

  SHF.hwnd = pG->Frame.global_handle; // 1.75
  SHF.wFunc = FO_DELETE;
  SHF.pFrom = Fname;
  SHF.pTo = NULL;
  SHF.fFlags = FOF_NOCONFIRMATION | FOF_SILENT | FOF_NORECURSION;
  if ( pG->HowToMove )
    SHF.fFlags |= FOF_ALLOWUNDO;
  Fname[lstrlen( Fname ) + 1] = '\0';
  return SHFileOperation( &SHF ); // Returns zero if successful or
  ///nonzero if an error occurs.
}

// Cut the last path component off the name *p in place. This should work on
//   both internal and external names. p :: Path string.
static void cutpath( char *p )
{
  char *r; // pointer to last path delimiter
  if (( r = strrchr( p, '\\' )) != NULL )
    // SLASH
    *r = 0;
  else
    *p = 0;
}

// Delete the compressed files and the directories that contained the
//   deleted files, if empty. Return an error code in the ZEN_ class. Failure
//   of destroy() or rmdir() is ignored.
int trash( struct ZGlobals *pG )
{
  extent i; // counter on deleted names
  extent n; // number of directories to delete
  struct zlist **s; // table of zip entries to handle,
  ///* sorted
  struct zlist *z; // current zip entry
  int ret;
  char* toKill;

  // Delete marked names and count directories
  n = 0;
  for ( z = pG->zfiles; z != NULL; z = z->nxt )
  {
    if ( z->mark == 1 || z->trash )
    {
      z->mark = 1;
      if ( z->zname[z->nam - 1] != (char)'\\' )
      {
        toKill = GetFullPath(pG, z->name );
        // don't unlink directory SLASH
        if ( pG->Frame.Verbose )
          Notify(PF, 0, "deleting file %s", toKill);//z->name );
        ret = Erase_File(pG, toKill);
        if (ret) //GetFullPath( pG, z->name )))
//        if ( Erase_File( pG, GetFullPath( pG, z->name )))
        {
          // v1.6017
          // if ( destroy( z->name ) ) {
          // zipwarn ( "error deleting", z->name );
          Notify(PF, IWARNING, "error deleting %s [%X]", toKill, ret);
        }

        // Try to delete all paths that lead up to marked names. This is
        //   necessary only with the -D option.
        if ( !pG->dirnames )
        {
          diag( "no dirnames will be kept", pG );
          cutpath( z->name );
          cutpath( z->zname );
          if ( z->zname[0] != (char)'\0' )
          {
            lstrcat( z->zname, "\\" ); // SLASH
          }

          z->nam = lstrlen( z->zname );
          if ( z->nam > 0 )
            n++;
        }
      }
      else
      {
        n++;
      }
    }
  }

  // Construct the list of all marked directories. Some may be duplicated if
  //   -D was used.
  if ( n )
  {
    if (( s = ( struct zlist ** )MALLOC( n *sizeof( struct zlist* ))) == NULL )
      return ZEN_MEM33;
    n = 0;
    for ( z = pG->zfiles; z != NULL; z = z->nxt )
    {
      if ( z->mark && z->nam > 0 && z->zname[z->nam - 1] == (char)'\\' // SLASH
           && ( n == 0 || strcmp( z->zname, s[n - 1]->zname ) != 0 ))
      {
        s[n++] = z;
      }
    }

    // Sort the files in reverse order to get subdirectories first. To avoid
    //   problems with strange naming conventions.(as in VMS), we sort on the
    //   internal names, so x/y/z will always be removed before x/y. On VMS,
    //   x/y/z > x/y but [x.y.z] < [x.y]
    qsort(( char* )s, n, sizeof( struct zlist* ), rqcmp );

    for ( i = 0; i < n; i++ )
    {
      char *p = s[i]->name;
      if ( *p == (char)'\0' )
        continue;
      if ( p[lstrlen( p ) - 1] == (char)'\\' )
      {
        // keep VMS [x.y]z.dir;1 intact SLASH
        p[lstrlen( p ) - 1] = '\0';
      }

      if ( i == 0 || strcmp( s[i]->zname, s[i - 1]->zname ) != 0 )
      {
        toKill = GetFullPath( pG, s[i]->name);
        if ( pG->Frame.Verbose )
          Notify( PF, 0, "trashing directory %s (if empty)", toKill);//s[i]->name );

//        rmdir( s[i]->name );         
        ret = Erase_File(pG, toKill);
        if (ret && pG->Frame.Verbose)          
          Notify(PF, IWARNING, "error deleting %s [%X]", toKill, ret);
//        if (_rmdir(toKill) /*== -1*/ && pG->Frame.Verbose)
//          Notify(PF, IWARNING, "error deleting %s [%X]", toKill, errno);
      }
    }

    FREE( s );
  }

  return ZEN_OK;
}
