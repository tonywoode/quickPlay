/* Zip.h
 * Copyright (C) 1990-1996 Mark Adler, Richard B. Wales, Jean-loup Gailly,
 * Kai Uwe Rommel, Onno van der Linden and Igor Mandrichenko.
 * Permission is granted to any individual or institution to use, copy, or
 * redistribute this software so long as all of the original files are included,
 * that it is not sold for profit, and that this copyright notice is retained.
 * This version modified by Chris Vleghert and Eric Engler for BCB/Delphi Zip.
  ** distributed under LGPL license ** see license.txt for details
*/

#ifndef __Zip_h
  #define __Zip_h

#include "common.h"

#include "windows.h"
//#include <stdarg>

#define ZIP /* for crypt.c:  include zip password functions, not unzip */
#define true  TRUE
#define false FALSE
#define bool  BOOL

#ifndef CRYPT
    #define CRYPT 1
#endif
#include <process.h>                /* For prototype of getpid()      */
#define ZCR_SEED2 getpid()          /* RCV Added; see note in Crypt.c */

//extern DWORD TgbIndex;          // RCV added, our only non-constant global.
#define MALLOC( s )         malloc( (s) )
//#define GLOBALALLOC( f, s ) GlobalAlloc( (f), (s) )
#define FREE( p )           free( ( void * )(p) )
//#define GLOBALFREE( p )     GlobalFree( (p) )

#define diag( m, g ) \
  if ( g->Frame.Verbose < 0 )    \
    Notify( PF, 0 | IVERBOSE, (m) )

extern void msgbox( char *msg, struct ZGlobals *pG );

extern int key_len;                   /* Added for password length checking */

/* Set up portability
 * Anything defined in tailor.h will cause the default in this
 * header file to be ignored.
 */
#include "Tailor.h"

#define MIN_MATCH 3
#define MAX_MATCH 258

/* The minimum and maximum match lengths */
#ifndef WSIZE
  #define WSIZE ( 0x8000 )
#endif

/* Maximum window size = 32K. If you are really short of memory, compile
 * with a smaller WSIZE but this reduces the compression ratio for files
 * of size > WSIZE. WSIZE must be a power of two in the current implementation.
 */
#define MIN_LOOKAHEAD ( MAX_MATCH + MIN_MATCH + 1 )

/* Minimum amount of lookahead, except at the end of the input file.
 * See deflate.c for comments about the MIN_MATCH + 1.
 */
#define MAX_DIST  ( WSIZE - MIN_LOOKAHEAD )

/* In order to simplify the code, particularly on 16 bit machines, match
 * distances are limited to MAX_DIST instead of WSIZE.
 */
/* Forget FILENAME_MAX (incorrectly = 14 on some System V) */
#define FNMAX 256

/* Lengths of headers after signatures in bytes */
#define LOCHEAD 26
#define CENHEAD 42
#define ENDHEAD 18

//#include "WizZip.h"
#include "Crypt.h"
#include "ZGlobals.h"

typedef struct _options
{
  unsigned dosflag:2;
  unsigned level:4;
  unsigned noext:1;
}FOpts;

/* Structures for in-memory file information */
struct zlist
{
  /* See central header in zipfile.c for what vem...off are */
  ush           vem, ver, flg, how;
  ulg           tim, crc, siz, len;
  extent        nam, ext, cext, com;  /* offset of ext must be >= LOCHEAD                 */
  ush           dsk, att, lflg;       /* offset of lflg must be >= LOCHEAD                */
  ulg           atx, off;
  char          *name;                /* File name in zip file                            */
  char          *extra;               /* Extra field (set only if ext != 0)               */
  char          *cextra;              /* Extra in central (set only if cext != 0) */
  char          *comment;             /* Comment (set only if com != 0)                   */
  char          *zname;               /* External version of internal name                */
  char          *passw;               /* Password if set on a per file base -P switch changed 1.73 */
  int           mark;                 /* Marker for files to operate on                   */
  int           trash;                /* Marker for files to delete                       */
//  int         dosflag;              /* Set to force MSDOS file attributes       */  
  FOpts         options;
  //      int      UseRoot;           /* Add current dir in FindFist and opening input*/
  struct zlist  *nxt;                 /* Pointer to next header in list                   */
};

struct flist
{
  char          *name;                /* Pointer to zero-delimited name external  */
  char          *zname;               /* Name used for zip file headers internal  */

  char          *passw;               /* Password if set on a per file base -P switch added R.Aelbrecht */

  ulg           len;                  /* Size of the file. RCV Added              */
//  int         dosflag;              /* Set to force MSDOS file attributes   */
  FOpts         options;
  struct flist  **lst;                /* Pointer to link pointing here  (last)    */
  struct flist  *nxt;                 /* Link to next name   */
};

struct plist
{
  char  *zname;               /* Name used for zip file headers                   */
  //      int   select; RCV: 1.605 always x now   Selection flag ('i' or 'x' )
};

/* internal file attribute */
#define UNKNOWN   ( -1 )
#define BINARY    0
#define ASCII     1
#define __EBCDIC  2

/* extra field definitions */
#define EF_VMCMS    0x4704  /* VM/CMS Extra Field ID ("G")  */
#define EF_MVS      0x470f  /* MVS Extra Field ID ("G")             */
#define EF_IZUNIX   0x5855  /* UNIX Extra Field ID ("UX")          */
#define EF_IZUNIX2  0x7855  /* Info-ZIP's new Unix ("Ux")                     */
#define EF_TIME     0x5455  /* universal timestamp ("UT")              */
#define EF_OS2EA    0x0009  /* OS/2 Extra Field ID (extended attributes)  */
#define EF_ACL      0x4C41  /* ACL Extra Field ID (access control list, "AL") */
#define EF_NTSD     0x4453  /* NT Security Descriptor Extra Field ID, ("SD")  */
#define EF_BEOS     0x6542  /* BeOS Extra Field ID ("Be")                    */
#define EF_QDOS     0xfb4a  /* SMS/QDOS ("J\373")          */
#define EF_AOSVS    0x5356  /* AOS/VS ("VS")                                                                                          */
#define EF_SPARK    0x4341  /* David Pilling's Acorn/SparkFS "(AC)"  */

/* Definitions for extra field handling: */
#define EB_HEADSIZE     4   /* length of a extra field block header     */
#define EB_ID           0   /* offset of block ID in header             */
#define EB_LEN          2   /* offset of data length field in header    */

#define EB_UX_MINLEN    8   /* minimal "UX" field contains atime, mtime */
#define EB_UX_ATIME     0   /* offset of atime in "UX" extra field data */
#define EB_UX_MTIME     4   /* offset of mtime in "UX" extra field data */

#define EB_UX_FULLSIZE  12  /* full "UX" field (atime, mtime, uid, gid) */
#define EB_UX_UID       8   /* byte offset of UID in "UX" field data    */
#define EB_UX_GID       10  /* byte offset of GID in "UX" field data    */

/* ASCII definitions for line terminators in text files: */
#define LF    10            /* '\n' on ASCII machines; must be 10 due to EBCDIC */
#define CR    13            /* '\r' on ASCII machines; must be 13 due to EBCDIC */
#define CTRLZ 26            /* DOS & OS/2 EOF marker (used in fileio.c)         */

/* Error return codes and PERR macro */
//#include "ZipErr.h"
/* Public globals */
//extern uch   upper[256];        /* Country dependent case map table   */
//#define BEST    - 1         /* Use best method (deflation or store)   */
#define STORE   0           /* Store method                           */
#define DEFLATE 8           /* Deflation method                          */

/* Diagnostic functions */
#ifdef DEBUG
  #ifdef MSDOS
    #undef stderr
    #define stderr  stdout
  #endif
    #define Assert( cond, msg ) \
  {                             \
    if ( !(cond) )              \
      error( msg, pG );         \
  }

#define Trace( x )      \
      Inform( pG, -1, IDEBUG, (x) );

#define Tracev( x, y ) \
  {                     \
    if ( pG->Frame.Verbose )  Inform( pG, -1, IDIAG, (x), (y) ); \
  }

#define Tracevv( x, y )    \
  {                                         \
    if ( pG->Frame.Verbose > 1 ) Inform( pG, -1, IDIAG, (x), (y) ); \
  }

#define Tracec( c, x, y )    \
  {                           \
    if ( pG->Frame.Verbose && (c) )   Inform( pG, -1, IDIAG, (x), (y) ); \
  }

#define Tracecv( c, x, y )       \
  {                               \
    if ( pG->Frame.Verbose > 1 && (c) ) Inform( pG, -1, IDIAG, (x), (y) ); \
  }

#else
  #define Assert( cond, msg )
  #define Trace( x )
  #define Tracev( x, y )
  #define Tracevv( x, y )
  #define Tracec( c, x, y )
  #define Tracecv( c, x, y )
#endif
#define A_RONLY   0x01
#define A_HIDDEN  0x02
#define A_SYSTEM  0x04
#define A_LABEL   0x08
#define A_DIR     0x10
#define A_ARCHIVE 0x20

// Local option flags
#define PURGE   0 // RCV Changed: was DELETE. (delete is also a function)
#define ADD     1
#define UPDATE  2
#define FRESHEN 3

/* Public function prototypes */
/* in DllMain.c */
int             ziperror( int c, struct ZGlobals *pG );

/* in DllZip.c */
int ZipProcess(struct ZGlobals *pG);
// select files to be processed
int ZipSelect(struct ZGlobals *pG, const ZipParms *C);
// cleanup after fail or completion
void ZipCleanup(struct ZGlobals *pG);
int             ziperr( int c, struct ZGlobals *pG );
void            error( char *h, struct ZGlobals *pG );

/* in ZipUp.c */
int             percent( ulg, ulg );
int             zipup( struct zlist *, HANDLE, struct ZGlobals *pG );
int file_read(unsigned char *buf, unsigned size, struct ZGlobals *pG );

/* in ZipFile.c */
struct zlist    *zsearch( char *, struct ZGlobals *pG );
#ifdef USE_EF_UX_TIME
int             get_ef_ux_ztime( struct zlist *, ztimbuf * );
#endif /* USE_EF_UX_TIME */

int             trash( struct ZGlobals *pG );
char            *ziptyp( char *, struct ZGlobals *pG );
int             readzipfile( struct ZGlobals *pG );

int             putlocal( struct zlist *, HANDLE, struct ZGlobals *pG );
int             putextended( struct zlist *, HANDLE, struct ZGlobals *pG );
int             putcentral( struct zlist *, HANDLE, struct ZGlobals *pG );
int             putend( int, ulg, ulg, HANDLE, struct ZGlobals *pG );
int             zipcopy( struct zlist *, HANDLE, HANDLE, struct ZGlobals *pG );

/* in FileIO.c */
struct flist    *fexpel( struct flist *, struct ZGlobals *pG );

char            *last( char *, int );
char            *DOSName( char *, struct ZGlobals *pG );
int             check_dup( struct ZGlobals *pG );
bool __fastcall filter( char *Name, struct ZGlobals *pG );
int             newname( char *n, long nSize, struct ZGlobals *pG );
time_t          dos2unixtime( ulg dostime );
ulg             dostime( int, int, int, int, int, int );
ulg             unix2dostime( time_t * );
int             issymlnk( ulg a );
#ifdef S_IFLNK
  #define rdsymlnk( p, b, n ) readlink( p, b, n )

/* extern int readlink (char *, char *, int); */
#else /* !S_IFLNK */
  #define rdsymlnk( p, b, n ) ( 0 )
#endif /* !S_IFLNK */


int EraseFile( const char *Fname, struct ZGlobals *pG );
int   destroy( const char *, struct ZGlobals *pG );
int   replace( const char *, const char *, struct ZGlobals *pG );    

//int           getfileattr( char * );
int   setfileattr( char *, int );
char  *tempname( struct ZGlobals *pG );

//int fcopy ( FILE *, FILE *, ulg );
int   fcopy( HANDLE, HANDLE, ulg, struct ZGlobals *pG );

/* in system dependent FileIO code */
int   Wild( char *, struct ZGlobals *pG );
char  *in2ex( char * );
char  *ex2in( char *, int *, struct ZGlobals *pG );
int   procname( char *, bool, struct ZGlobals *pG );
void  stamp( char *, ulg );
char *__fastcall GetFullPath ( struct ZGlobals *pG, char *Filename );
int __fastcall Close_Handle(HANDLE *h);

/* in Win32.c */                                               
int IsFileSystemOldFAT( char *dir, struct ZGlobals *pG );

/* in Win32Zip.c */
//#define ZFT_DEVICE ((unsigned long)-1L)
//#define ZFT_LABEL ((unsigned long)-2L)
//#define ZFT_SIZE ((unsigned long)-3L)
#define ZFT_DEVICE (0xFFFFFFFFu)
#define ZFT_LABEL (0xFFFFFFFEu)
#define ZFT_SIZE (0xFFFFFFFDu)
ulg   zfiletime( char *, ulg *, unsigned long *, ztimbuf *, struct ZGlobals *pG );

//int           set_extra_field( struct zlist *z, ztimbuf *z_utim );
/* in Util.c */
const char *__fastcall IsShExp ( const char * );
 
int __fastcall      dosmatch( const char *, const char * );

int _fastcall       namecmp( const char *string1, const char *string2 );
void              **search( void *, void **, extent, int (*) ( const void *, const void * ) );
void              envargs( int *Pargc, char ***Pargv, char *envstr, char *envstr2 );
void              expand_args( int *argcp, char ***argvp );
int __fastcall      SameNameExt( const char *fname, const char *oname );

/* in Deflate.c */
void              lm_init( int pack_level, ush *flags, struct ZGlobals *pG );
#ifdef DYN_ALLOC
void              lm_free( struct ZGlobals *pG );
#endif
ulg               deflate( struct ZGlobals *pG );

/* in Trees.c */
void              ct_init( ush *attr, int *method, struct ZGlobals *pG );
int __fastcall      ct_tally( int dist, int lc, struct ZGlobals *pG );
ulg               flush_block( char *buf, ulg stored_len, int eof, struct ZGlobals *pG );

/* in Bits.c */
//void bi_init ( FILE * zipfile, struct ZGlobals *pG );
void              bi_init( HANDLE zipfile, struct ZGlobals *pG );
void __fastcall     send_bits( int value, int length, struct ZGlobals *pG );
unsigned __fastcall bi_reverse( unsigned value, int length );
void __fastcall     bi_windup( struct ZGlobals *pG );
void __fastcall     copy_block( char *block, unsigned len, int header, struct ZGlobals *pG );
int seekable( struct ZGlobals *pG );
extern int ( *read_buf ) ( char *buf, unsigned size, struct ZGlobals *pG );
ulg memcompress( char *tgt, ulg tgtsize, char *src, ulg srcsize, struct ZGlobals *pG );

/* in ZCrypt.c */
void      crypthead( char *, ulg, HANDLE, struct ZGlobals *pG );
unsigned  zfwrite( void *, extent, HANDLE, struct ZGlobals *pG );
                             
int __fastcall longest_match(unsigned cur_match, struct ZGlobals * pG );

#ifdef __cplusplus
  #define min( a, b ) ( (a) < (b) ? (a) : (b) )
#endif 

#endif /* !__Zip_h */
