
/* This version modified by Chris Vleghert and Eric W. Engler
 * for BCB/Delphi Zip, Jun 18, 2000.
 * modified R.Peters 8 September, 2005
 */

/*---------------------------------------------------------------------------
 * unzpriv.h
 * This header file contains private (internal) macros, typedefs, prototypes
 * and global-variable declarations used by all of the UnZip source files.
 * In a prior life it was part of the main unzip.h header, but now it is
 * included by that header.
 *---------------------------------------------------------------------------*/
#ifndef __unzpriv_h             /* prevent multiple inclusions */
#define __unzpriv_h

/* First thing: Signal all following code that we compile UnZip utilities! */
#define UNZIP

/* GRR 960218:  testing a new feature...definitely *not* ready for primetime */
#ifdef TIMESTAMP
#  undef TIMESTAMP
#endif

#ifdef NEVER                    // EWE: dynamic crc table isn't a good idea
#  ifndef DYNAMIC_CRC_TABLE
#    define DYNAMIC_CRC_TABLE
#  endif
#  ifndef DYNALLOC_CRCTAB
#    define DYNALLOC_CRCTAB
#  endif
#endif

#ifdef DYNAMIC_CRC_TABLE
#  undef DYNAMIC_CRC_TABLE
#endif
#ifdef DYNALLOC_CRCTAB
#  undef DYNALLOC_CRCTAB
#endif

#include <stdio.h>
#include <ctype.h>              /* skip for VMS, to use tolower() function? */
#include <errno.h>              /* used in mapname() */
#include <string.h>             /* strcpy, strcmp, memcpy, strchr/strrchr, etc. */
#include <limits.h>             /* GRR:  EXPERIMENTAL!  (can be deleted) */
#include <signal.h>             /* used in unzip.c, fileio.c */

/*---------------------------------------------------------------------------
    MS-DOS and OS/2 section:
  ---------------------------------------------------------------------------*/
#ifdef MORE
#  undef MORE
#endif

#include <sys/types.h>          /* off_t, time_t, dev_t, ... */
#include <sys/stat.h>
#include <io.h>                 /* lseek(), open(), setftime(), dup(), creat() */
#include <time.h>               /* localtime() */
#include <fcntl.h>              /* O_BINARY for open() w/o CR/LF translation */

//#include "doscfg.h"

//////////#define USE_EF_UX_TIME

/*---------------------------------------------------------------------------
    Win32 section:
  ---------------------------------------------------------------------------*/
#include "w32cfg.h"

/*************/

/*  Defines  */

/*************/
#define UNZIP_VERSION     20    /* compatible with PKUNZIP 2.0 */

/* clean up with a few defaults */
//#ifndef DIR_END
//#  define DIR_END '/'       /* last char before program name (or filename) */
//#endif
#ifndef DATE_FORMAT
#  define DATE_FORMAT   DF_MDY  /* defaults to US convention */
#endif

#ifndef S_TIME_T_MAX            /* Max. value of signed (>=32 bit) time_t */
# define S_TIME_T_MAX ((time_t)(ulg)0x7FFFFFFFL)
#endif

#ifndef U_TIME_T_MAX            /* Max. value of unsigned (>=32 bit) time_t */
# define U_TIME_T_MAX ((time_t)(ulg)0xFFFFFFFFL)
#endif

#ifdef DOSDATE_2038_01_18
# undef DOSDATE_2038_01_18
#endif
#define DOSDATE_2038_01_18 ((ush)0x7432)

/* defaults that we hope will take care of most machines in the future */
#if (!defined(PCHAR_SPRINTF) && !defined(INT_SPRINTF))
#ifdef __STDC__
#    define INT_SPRINTF         /* sprintf() returns int:  ANSI */
#endif
#ifndef INT_SPRINTF
#    define PCHAR_SPRINTF       /* sprintf() returns char *:  BSDish */
#endif
#endif

#define DIR_BLKSIZ  64          /* number of directory entries per block
*  ( should fit in 4096 bytes, usually )  */
#ifndef WSIZE
#  define WSIZE     0x8000      /* window size--must be a power of two, and */
#endif /*  at least 32K for zip's deflate method */
/* For DLL, can't be > 32K due to buffer code */

#ifndef INBUFSIZ
#if (defined(MED_MEM) || defined(SMALL_MEM))
#    define INBUFSIZ  2048      /* works for MS-DOS small model */
#else
#    define INBUFSIZ  0x8000 //8192      /* larger buffers for real OSes */
#endif
#endif

#define OUTBUFSIZ   0x8000      // EWE: 32K (for unshrink.c)
#define TRANSBUFSIZ 0x8000      // EWE: 32K
#define RAWBUFSIZ OUTBUFSIZ
typedef int shrint;

#if (defined(SFX) && !defined(NO_ZIPINFO))
#  define NO_ZIPINFO
#endif

#if (!defined(COPYRIGHT_CLEAN) && !defined(USE_SMITH_CODE))
#  define COPYRIGHT_CLEAN
#endif

#ifndef O_BINARY
#  define O_BINARY  0
#endif

#ifndef PIPE_ERROR
#  define PIPE_ERROR (errno == EPIPE)
#endif

/* File operations--use "b" for binary if allowed or fixed length 512 on VMS */
#ifndef FOPR
#  define FOPR "rb"
#endif
#ifndef FOPM
#  define FOPM "r+b"
#endif
#ifndef FOPW
#  define FOPW "wb"
#endif
#ifndef FOPWT
#  define FOPWT "wt"
#endif

/* If <limits.h> exists on most systems, should include that, since it may
 * define some or all of the following:  NAME_MAX, PATH_MAX, _POSIX_NAME_MAX,
 * _POSIX_PATH_MAX.
 */
#include <limits.h>

#ifndef PATH_MAX
#ifdef MAXPATHLEN
#    define PATH_MAX      MAXPATHLEN    /* in <sys/param.h> on some systems */
#else
#    ifdef _MAX_PATH
#      define PATH_MAX    _MAX_PATH
#    else
#      if FILENAME_MAX > 255
#        define PATH_MAX  FILENAME_MAX  /* used like PATH_MAX on some systems */
#      else
#        define PATH_MAX  1024
#      endif
#    endif /* ?_MAX_PATH */
#endif /* ?MAXPATHLEN */
#endif /* !PATH_MAX */

#define FILNAMSIZ  PATH_MAX

#define ZSUFX           ".zip"

#define CENTRAL_HDR_SIG   "\001\002"    /* the infamous "PK" signature bytes, */
#define LOCAL_HDR_SIG     "\003\004"    /*  sans "PK" (so unzip executable not */
#define END_CENTRAL_SIG   "\005\006"    /*  mistaken for zipfile itself) */
#define EXTD_LOCAL_SIG    "\007\010"    /* [ASCII "\113" == EBCDIC "\080" ??] */

#define SKIP              0     /* choice of activities for do_string() */
#define DISPLAY           1
#define DISPL_8           5     /* Display file comment (ext. ASCII)    */
#define DS_FN             2
#define EXTRA_FIELD       3
#define DS_EF             3

#define DOES_NOT_EXIST    -1    /* return values for check_for_newer() */
#define EXISTS_AND_OLDER  0
#define EXISTS_AND_NEWER  1

#define ROOT              0     /* checkdir() extract-to path:  called once */
#define INIT              1     /* allocate buildpath:  called once per member */
#define APPEND_DIR        2     /* append a dir comp.:  many times per member */
#define APPEND_NAME       3     /* append actual filename:  once per member */
#define GETPATH           4     /* retrieve the complete path and free it */
#define END               5     /* free root path prior to exiting program */

//----------------------------------------------------------

/* version_made_by codes (central dir):  make sure these */

/*  are not defined on their respective systems!! */
//----------------------------------------------------------
#define FS_FAT_           0     /* filesystem used by MS-DOS, OS/2, Win32 */
#define AMIGA_            1
#define VMS_              2
#define UNIX_             3
#define VM_CMS_           4
#define ATARI_            5     /* what if it's a minix filesystem? [cjh]     */
#define FS_HPFS_          6     /* filesystem used by OS/2, NT                */
#define MAC_              7
#define Z_SYSTEM_         8
#define CPM_              9
#define TOPS20_           10
#define FS_NTFS_          11    /* filesystem used by Windows NT              */
#define QDOS_MAYBE_       12    /* a bit premature, but somebody once started */
#define ACORN_            13    /* Archimedes Acorn RISC OS                   */
#define FS_VFAT_          14    /* filesystem used by Windows 95, NT          */
#define MVS_              15
#define BEBOX_            16
#define TANDEM_           17    /* Tandem/NSK                                 */
#define NUM_HOSTS         18    /* index of last system + 1                   */

#define STORED            0     /* compression methods                        */
#define SHRUNK            1
#define REDUCED1          2
#define REDUCED2          3
#define REDUCED3          4
#define REDUCED4          5
#define IMPLODED          6
#define TOKENIZED         7
#define DEFLATED          8
#define ENHDEFLATED       9
#define DCLIMPLODED      10
#define NUM_METHODS       9     /* index of last method + 1 */

/* don't forget to update //list_files() appropriately if NUM_METHODS changes */

/* 9 and 10 not yet implemented */

#define PK_OK             0     /* no error */
#define PK_COOL           0     /* no error */
#define PK_GNARLY         0     /* no error */
#define PK_WARN           1     /* warning error */
#define PK_ERR            2     /* error in zipfile */
#define PK_BADERR         3     /* severe error in zipfile */
#define PK_MEM            4     /* insufficient memory */
#define PK_MEM2           5     /* insufficient memory */
#define PK_MEM3           6     /* insufficient memory */
#define PK_MEM4           7     /* insufficient memory */
#define PK_MEM5           8     /* insufficient memory */
#define PK_NOZIP          9     /* zipfile not found */
#define PK_PARAM          10    /* bad or illegal parameters specified */
#define PK_FIND           11    /* no files found */
#define PK_DISK           50    /* disk full */
#define PK_EOF            51    /* unexpected EOF */

#define IZ_DIR            76    /* potential zipfile is a directory */
#define IZ_CREATED_DIR    77    /* directory created: set time and permissions */
#define IZ_VOL_LABEL      78    /* volume label, but can't set on hard disk */
#define IZ_EF_TRUNC       79    /* local extra field truncated (PKZIP'd) */
#define IZ_SKIPPED        80    // 1.75 skipped file

/* return codes of password fetches (negative = user abort; positive = error) */
#define IZ_PW_ENTERED      0    /* got some password string; use/try it */
#define IZ_PW_CANCEL      -1    /* no password available (for this entry) */
#define IZ_PW_CANCELALL   -2    /* no password, skip any further pwd. request */
#define IZ_PW_ERROR        5    /* = PK_MEM2 : failure (no mem, no tty, ...) */

#define DF_MDY            0     /* date format 10/26/91 (USA only) */
#define DF_DMY            1     /* date format 26/10/91 (most of the world) */
#define DF_YMD            2     /* date format 91/10/26 (a few countries) */

/* extra-field ID values, little-endian: */
#define EF_AV        0x0007     /* PKWARE's authenticity verification */
#define EF_OS2       0x0009     /* OS/2 extended attributes */
#define EF_PKVMS     0x000c     /* PKWARE's VMS */
#define EF_PKUNIX    0x000d     /* PKWARE's Unix */
#define EF_IZVMS     0x4d49     /* Info-ZIP's VMS ("IM") */
#define EF_IZUNIX    0x5855     /* Info-ZIP's old Unix[1] ("UX") */
#define EF_IZUNIX2   0x7855     /* Info-ZIP's new Unix[2] ("Ux") */
#define EF_TIME      0x5455     /* universal timestamp ("UT") */
#define EF_JLMAC     0x07c8     /* Johnny Lee's old Macintosh (= 1992) */
#define EF_ZIPIT     0x2605     /* Thomas Brown's Macintosh (ZipIt) */
#define EF_VMCMS     0x4704     /* Info-ZIP's VM/CMS ("\004G") */
#define EF_MVS       0x470f     /* Info-ZIP's MVS ("\017G") */
#define EF_ACL       0x4c41     /* (OS/2) access control list ("AL") */
#define EF_NTSD      0x4453     /* NT security descriptor ("SD") */
#define EF_BEOS      0x6542     /* BeOS ("Be") */
#define EF_QDOS      0xfb4a     /* SMS/QDOS ("J\373") */
#define EF_AOSVS     0x5356     /* AOS/VS ("VS") */
#define EF_SPARK     0x4341     /* David Pilling's Acorn/SparkFS ("AC") */
#define EF_MD5       0x4b46     /* Fred Kantor's MD5 ("FK") */
#define EF_ASIUNIX   0x756e     /* ASi's U */

#define EB_HEADSIZE       4     /* length of extra field block header */
#define EB_ID             0     /* offset of block ID in header */
#define EB_LEN            2     /* offset of data length field in header */
#define EB_UCSIZE_P       0     /* offset of ucsize field in compr. data */
#define EB_CMPRHEADLEN    6     /* lenght of compression header */

#define EB_UX_MINLEN      8     /* minimal "UX" field contains atime, mtime */
#define EB_UX_FULLSIZE    12    /* full "UX" field (atime, mtime, uid, gid) */
#define EB_UX_ATIME       0     /* offset of atime in "UX" extra field data */
#define EB_UX_MTIME       4     /* offset of mtime in "UX" extra field data */
#define EB_UX_UID         8     /* byte offset of UID in "UX" field data */
#define EB_UX_GID         10    /* byte offset of GID in "UX" field data */

/*---------------------------------------------------------------------------
    True sizes of the various headers, as defined by PKWARE--so it is not
    likely that these will ever change.  But if they do, make sure both these
    defines AND the typedefs below get updated accordingly.
  ---------------------------------------------------------------------------*/
#define LREC_SIZE   26          /* lengths of local file headers, central */
#define CREC_SIZE   42          /*  directory headers, and the end-of-    */
#define ECREC_SIZE  18          /*  central-dir record, respectively      */

#define MAX_BITS    13          /* used in unshrink() */
#define HSIZE       (1 << MAX_BITS)     /* size of global work area */

#define LF     10               /* '\n' on ASCII machines; must be 10 due to EBCDIC */
#define CR     13               /* '\r' on ASCII machines; must be 13 due to EBCDIC */
#define CTRLZ  26               /* DOS & OS/2 EOF marker (used in fileio.c, vms.c) */

#define ENV_UNZIP     "UNZIP"   /* the standard names */
#define ENV_ZIPINFO   "ZIPINFO"

#if (!defined(QQ) && !defined(NOQQ))
#  define QQ
#endif

#ifdef QQ                       /* Netware version:  no file         */
#  define QCOND     (!pG->qflag)        /*  comments with -vq or -vqq        */
#else /* Bill Davidsen version:  no way to */
#  define QCOND     (which_hdr) /*  kill file comments when listing  */
#endif

#ifdef OLD_QQNEVER
#  define QCOND2    (pG->qflag < 2)
#else
#  define QCOND2    (!pG->qflag)
#endif

#ifndef S_ISDIR
#ifdef CMS_MVS
#    define S_ISDIR(m)  (false)
#else
#    define S_ISDIR(m)  (((m) & S_IFMT) == S_IFDIR)
#endif
#endif

#ifndef IS_VOLID
#  define IS_VOLID(m)  ((m) & 0x08)
#endif

/**************/

/*  Typedefs  */

/**************/
#ifdef NO_UID_GID
#ifdef UID_USHORT
typedef unsigned short uid_t;   /* TI SysV.3 */
typedef unsigned short gid_t;
#else
typedef unsigned int uid_t;     /* SCO Xenix */
typedef unsigned int gid_t;
#endif
#endif

typedef struct utimbuf ztimbuf;

typedef struct chdr_info // min_info
{
  unsigned long offset;         // 1.75
  ulg compr_size;               /* compressed size (needed if extended header)  */
  ulg crc;                      /* crc (needed if extended header)   */      
  ulg uncomp_size;              /* uncompressed size (needed if extended header)  */
  int hostnum;
  //    ush chdrseq;                  /* v1.6023 added   */
  unsigned file_attr;           /* local flavor, as used by creat(), chmod()... */
  unsigned encrypted: 1;        /* file encrypted: decrypt before uncompressing */
  unsigned ExtLocHdr: 1;        /* use time instead of CRC for decrypt check  */
  unsigned textfile:  1;        /* file is text (according to zip) */
  unsigned textmode:  1;        /* file is to be extracted as text   */
  unsigned lcflag:  1;          /* convert filename to lowercase  */
  unsigned vollabel:  1;        /* "file" is an MS-DOS volume (disk) label  */
  unsigned chdrseq:  24;  /* 20 */        // uses unused bits
  char *   filename;            // 1.78.5 from central directory
}
chdr_info; // min_info;

/*---------------------------------------------------------------------------
   Zipfile work area declarations.
 ---------------------------------------------------------------------------*/
#ifdef MALLOC_WORK
#  undef MALLOC_WORK            // EWE
#endif
       
#pragma option -a1
union work {
  struct
  {                      /* unshrink(): */
    shrint Parent[ HSIZE ];       /* (8192 * sizeof(short)) == 16KB minimum   */
    uch value[ HSIZE ];           /* 8KB */
    uch Stack[ HSIZE ];           /* 8KB */
  }
  shrink;                     /* total = 32KB minimum; 80KB on Cray/Alpha */
  uch Slide[ WSIZE ];             /* explode(), inflate(), unreduce() */
};      
#pragma option -a.

#define slide      pG->area.Slide
#ifdef USE_STRM_OUTPUT
#  define redirSlide pG->redirect_pointer
#else
#  define redirSlide pG->area.Slide
#endif

/*---------------------------------------------------------------------------
 *  Zipfile layout declarations.  If these headers ever change, make sure the
 *  xxREC_SIZE defines (above) change with them!
 *---------------------------------------------------------------------------*/
typedef uch local_byte_hdr[ LREC_SIZE ];
#      define L_VERSION_NEEDED_TO_EXTRACT_0     0
#      define L_VERSION_NEEDED_TO_EXTRACT_1     1
#      define L_GENERAL_PURPOSE_BIT_FLAG        2
#      define L_COMPRESSION_METHOD              4
#      define L_LAST_MOD_FILE_TIME              6
#      define L_LAST_MOD_FILE_DATE              8
#      define L_CRC32                           10
#      define L_COMPRESSED_SIZE                 14
#      define L_UNCOMPRESSED_SIZE               18
#      define L_FILENAME_LENGTH                 22
#      define L_EXTRA_FIELD_LENGTH              24

typedef uch cdir_byte_hdr[ CREC_SIZE ];
#      define C_VERSION_MADE_BY_0               0
#      define C_VERSION_MADE_BY_1               1
#      define C_VERSION_NEEDED_TO_EXTRACT_0     2
#      define C_VERSION_NEEDED_TO_EXTRACT_1     3
#      define C_GENERAL_PURPOSE_BIT_FLAG        4
#      define C_COMPRESSION_METHOD              6
#      define C_LAST_MOD_FILE_TIME              8
#      define C_LAST_MOD_FILE_DATE              10
#      define C_CRC32                           12
#      define C_COMPRESSED_SIZE                 16
#      define C_UNCOMPRESSED_SIZE               20
#      define C_FILENAME_LENGTH                 24
#      define C_EXTRA_FIELD_LENGTH              26
#      define C_FILE_COMMENT_LENGTH             28
#      define C_DISK_NUMBER_START               30
#      define C_INTERNAL_FILE_ATTRIBUTES        32
#      define C_EXTERNAL_FILE_ATTRIBUTES        34
#      define C_RELATIVE_OFFSET_LOCAL_HEADER    38

typedef uch ec_byte_rec[ ECREC_SIZE + 4 ];

/*     define SIGNATURE                         0   space-holder only */
#      define NUMBER_THIS_DISK                  4
#      define NUM_DISK_WITH_START_CENTRAL_DIR   6
#      define NUM_ENTRIES_CENTRL_DIR_THS_DISK   8
#      define TOTAL_ENTRIES_CENTRAL_DIR         10
#      define SIZE_CENTRAL_DIRECTORY            12
#      define OFFSET_START_CENTRAL_DIRECTORY    16
#      define ZIPFILE_COMMENT_LENGTH            20

                                  
#pragma option -a1
typedef struct local_file_header
{      /* LOCAL */
  uch version_needed_to_extract[ 2 ];
  ush general_purpose_bit_flag;
  ush compression_method;
  ush last_mod_file_time;
  ush last_mod_file_date;
  ulg crc32;
  ulg csize;
  ulg ucsize;
  ush filename_length;
  ush extra_field_length;
}
local_file_hdr;   
#pragma option -a.
                            
#pragma option -a1
typedef struct end_central_dir_record
{ /* END CENTRAL */
  ush number_this_disk;
  ush num_disk_start_cdir;
  ush num_entries_centrl_dir_ths_disk;
  ush total_entries_central_dir;
  ulg size_central_directory;
  ulg offset_start_central_directory;
  ush zipfile_comment_length;
}
ecdir_rec;  
#pragma option -a.

/* Huffman code lookup table entry--this entry is four bytes for machines
 * that have 16-bit pointers (e.g. PC's in the small or medium model).
 * Valid extra bits are 0..13.  e == 15 is EOB (end of block), e == 16
 * means that v is a literal, 16 < e < 32 means that v is a pointer to
 * the next table, which codes e - 16 bits, and lastly e == 99 indicates
 * an unused code.  If a code with e == 99 is looked up, this implies an
 * error in the data. */  
#pragma option -a1
struct huft
{
  uch e;                        /* number of extra bits or operation      */
  uch b;                        /* number of bits in this code or subcode */
  union {
    ush n;                      /* literal, length base, or distance base */
    struct huft *t;             /* pointer to next level of table         */
  } v;
};      
#pragma option -a.


/*************/

/*  UGlobals  */

/*************/
#include "uglobals.h"

/*************************/

/*  Function Prototypes  */

/*************************/

/*---------------------------------------------------------------------------
 *  Functions in DllMain.c:
 *---------------------------------------------------------------------------*/
void EXIT (struct UGlobals *pG, int x );

/*---------------------------------------------------------------------------
 *  Functions in process.c (main driver routines):
 *---------------------------------------------------------------------------*/
void process_zipfiles ( struct UGlobals *pG );
int uz_end_central ( struct UGlobals *pG );
int process_cdir_file_hdr ( struct UGlobals *pG );
int get_cdir_ent ( struct UGlobals *pG );
int process_local_file_hdr ( struct UGlobals *pG );
unsigned ef_scan_for_izux ( uch * ef_buf, unsigned ef_len, ztimbuf * z_utim,
                            ush * z_uidgid );

/*---------------------------------------------------------------------------
 *  Functions in fileio.c:
 *---------------------------------------------------------------------------*/
int open_input_file ( struct UGlobals *pG );
int open_outfile ( struct UGlobals *pG );  /* also vms.c */
void undefer_input ( struct UGlobals *pG );
void defer_leftover_input ( struct UGlobals *pG );
unsigned readbuf ( struct UGlobals *pG, char *buf, register unsigned len );
int readbyte ( struct UGlobals *pG );
int fillinbuf ( struct UGlobals *pG );
int flush ( struct UGlobals *pG, uch * buf, ulg size, int unshrink );
void handler ( int signal );
time_t dos_to_unix_time ( unsigned ddate, unsigned dtime );
int check_for_newer ( struct UGlobals *pG, char *filename );       /* os2,vmcms,vms */
int do_string ( struct UGlobals *pG, unsigned int len, int option );
ush makeword ( uch * b );
ulg makelong ( uch * sig );
int zstrnicmp ( register const char *s1, register const char *s2,
                register unsigned n );
uch iso2oem ( unsigned char source );
uch oem2iso ( unsigned char source );
long vclSeek ( struct UGlobals *pG, long Offset, int FromWhere );
int vclRead ( struct UGlobals *pG, void *buf, unsigned LenToRead );
char *GetFullPath ( struct UGlobals *pG, char *Filename );

/*---------------------------------------------------------------------------
 *  Functions in extract.c:
 *---------------------------------------------------------------------------*/
int extract_or_test_files ( struct UGlobals *pG );
int MemExtract ( struct UGlobals *pG );
int MemFlush ( struct UGlobals *pG, uch * rawbuf, ulg size );

/*---------------------------------------------------------------------------
 *  Decompression functions:
 *---------------------------------------------------------------------------*/
int explode ( struct UGlobals *pG );       /* explode.c  */
int huft_free ( struct huft *t ); /* inflate.c  */
int huft_build ( struct UGlobals *pG, unsigned *b, unsigned n,
                 unsigned s, const ush * d, const ush * e, struct huft **t,
                 int *m );
int inflate ( struct UGlobals *pG );       /* inflate.c  */
int inflate_free ( struct UGlobals *pG );  /* inflate.c  */
void unreduce ( struct UGlobals *pG );     /* unreduce.c */
int unshrink ( struct UGlobals *pG );      /* unshrink.c */

/*---------------------------------------------------------------------------
 *  MSDOS-only functions:
 *---------------------------------------------------------------------------*/
#if ( (defined(MSDOS) && defined(__EMX__)) )
unsigned _dos_getcountryinfo ( void * );  /* msdos.c */
void _dos_setftime ( int, unsigned short, unsigned short );       /* msdos.c */
void _dos_setfileattr ( char *, int );    /* msdos.c */
unsigned _dos_creat ( char *, unsigned, int * );  /* msdos.c */
void _dos_getdrive ( unsigned * );        /* msdos.c */
unsigned _dos_close ( int );      /* msdos.c */
#endif

/*---------------------------------------------------------------------------
 *  Miscellaneous/shared functions:
 *---------------------------------------------------------------------------*/
int match ( char *s, char *p );
int iswild ( char *p );           /* match.c   */
ulg __fastcall crc32( ulg crc, const uch *buf, extent len );
void version ( struct UGlobals *pG );      /* local */
int mapattr ( struct UGlobals *pG );       /* local */
int mapname ( struct UGlobals *pG, int renamed );  /* local */
int checkdir ( struct UGlobals *pG, char *pathcomp, int flag );
void close_outfile ( struct UGlobals *pG );        /* local */

/************/

/*  Macros  */

/************/
#ifndef MAX
#  define MAX( a, b )   ((a) > (b) ? (a) : (b))
#endif
#ifndef MIN
#  define MIN( a, b )   ((a) < (b) ? (a) : (b))
#endif

//#define Trace( x )   MyTrace x

//#ifdef DEBUG_TIME
//#  define TTrace( x )  MyTrace x
//#else
#  define TTrace( x )
//#endif

#ifdef NO_DEBUG_IN_MACROS
#  define MTrace( x )
#else
#  define MTrace( x )  Trace( x )
#endif

#define ToLower      tolower    /* assumed "smart"; used in match() */
 
#define CRCVAL_INITIAL  0L

/*  Seek to the block boundary of the block which includes abs_offset,
 *  then read block into input buffer and set pointers appropriately.
 *  If block is already in the buffer, just set the pointers.  This macro
 *  is used by uz_end_central (process.c), zi_end_central (zipinfo.c) and
 *  do_string (fileio.c).  A slightly modified version is embedded within
 *  extract_or_test_files (extract.c).  readbyte() and readbuf() (fileio.c)
 *  are compatible.  NOTE THAT abs_offset is intended to be the "proper off-
 *  set" (i.e., if there were no extra bytes prepended); cur_zipfile_bufstart
 *  contains the corrected offset.
 *
 *  Since ZLSEEK is never used during decompression, it is safe to use the
 *  slide[] buffer for the error message.
 *
 *  The awkward "%cbs_offset" construct is provided for the obnoxious Solaris
 *  compiler, which wants to do macro substitution inside strings.
 */
int zlseek( struct UGlobals *pG, long abs_offset);
#define ZLSEEK( ofs ) {int zlr = zlseek(pG, ( ofs) ); if (zlr) return zlr;}
#ifndef ZLSEEK
// RCV Changed 29-1-99 USE_STRM_INPUT
# define _ZLS_RELOAD( abs_offset ) { \
  MTrace( (pG, "ZLSEEK: %cbs_offset = %ld, pG->extra_bytes = %ld", 'a', (abs_offset), pG->extra_bytes) ); \
  pG->cur_zipfile_bufstart = vclSeek( pG, (long)bufstart, SEEK_SET ); \
  MTrace( (pG, "       request = %ld, (abs+extra) = %ld, inbuf_offset = %ld", request, ((abs_offset)+pG->extra_bytes), inbuf_offset) ); \
  MTrace( (pG, "       bufstart = %ld, cur_zipfile_bufstart = %ld", bufstart, pG->cur_zipfile_bufstart) ); \
  if ( (pG->incnt = vclRead( pG, (char *)pG->inbuf, INBUFSIZ )) <= 0 ) \
    return( PK_EOF ); \
  pG->inptr = pG->inbuf + (int)inbuf_offset; \
  pG->incnt -= (int)inbuf_offset; \
 }

# define ZLSEEK( abs_offset ) { \
                long request = (abs_offset) + pG->extra_bytes; \
                long inbuf_offset = request % INBUFSIZ; \
  long bufstart = request - inbuf_offset; \
        \
   if ( request < 0 ) { \
   return( PK_BADERR ); \
  } else if ( bufstart != pG->cur_zipfile_bufstart ) \
  _ZLS_RELOAD( abs_offset ) \
  else { \
  pG->incnt += (pG->inptr-pG->inbuf) - (int)inbuf_offset; \
   pG->inptr = pG->inbuf + (int)inbuf_offset; \
        } \
  }
#endif /* !ZLSEEK */

#define SKIP_( length ) if( length && ((error = do_string( pG, length, SKIP )) != 0) ) \
  {error_in_archive = error; if( error > 1 ) return error;}

/*  Skip a variable-length field, and report any errors.  Used in zipinfo.c
 *  and unzip.c in several functions.
 *
 *  macro SKIP_(length)
 *      ush length;
 *  {
 *      if (length && ((error = do_string(length, SKIP)) != 0)) {
 *          error_in_archive = error;   /-* might be warning *-/
 *          if (error > 1)              /-* fatal *-/
 *              return (error);
 *      }
 *  }
 */

#  define FLUSH( w )  if ( pG->mem_mode ) MemFlush( pG, redirSlide, (ulg)(w) ); \
                      else flush( pG, redirSlide, (ulg)(w), 0 )
#  define NEXTBYTE  (--pG->incnt >= 0 ? (int)(*pG->inptr++) : readbyte( pG ))

#define READBITS( nbits, zdest ) {  \
    if( nbits>pG->bits_left )   \
    {int temp; pG->zipeof = 1; \
  while (pG->bits_left <= (int)(8 *(sizeof( pG->bitbuf )- 1)) && (temp = NEXTBYTE) != EOF) { \
  pG->bitbuf |= (ulg)temp << pG->bits_left; pG->bits_left += 8; pG->zipeof = 0;}} \
  zdest = (shrint)((ush)pG->bitbuf & mask_bits[nbits]); pG->bitbuf >>= nbits; \
  pG->bits_left -= nbits; }

/* macro READBITS( nbits, zdest )    * only used by unreduce and unshrink *
 * {
 *      if ( nbits > pG->bits_left ) {  * fill pG->bitbuf, 8*sizeof(ulg) bits *
 *          int temp;
 *
 *          pG->zipeof = 1;
 *          while ( pG->bits_left <= 8*(sizeof( pG->bitbuf )-1 ) &&
 *                 (temp = NEXTBYTE) != (int)EOF ) {
 *              pG->bitbuf |= (ulg)temp << pG->bits_left;
 *              pG->bits_left += 8;
 *              pG->zipeof = 0;
 *          }
 *      }
 *      zdest = (shrint)((ush)pG->bitbuf & mask_bits[nbits]);
 *      pG->bitbuf >>= nbits;
 *      pG->bits_left -= nbits;
 *  }
 */

/* GRR:  should change name to STRLOWER and use StringLower, if possible.
 *  Copy the zero-terminated string in str1 into str2, converting any
 *  uppercase letters to lowercase as we go.  str2 gets zero-terminated
 *  as well, of course.  str1 and str2 may be the same character array.
 */
#  define TOLOWER( str1, str2 ) { \
                char  *p, *q; \
                p = (str1)- 1; \
                q = (str2); \
                while (*++p) \
                        *q++ = (char)(isupper( (int)(*p))? tolower((int)(*p)) : *p); \
                *q = '\0'; \
        }

/* NOTES:  This macro makes no assumptions about the characteristics of
 *    the tolower() function or macro (beyond its existence), nor does it
 *    make assumptions about the structure of the character set (i.e., it
 *    should work on EBCDIC machines, too).  The fact that either or both
 *    of isupper() and tolower() may be macros has been taken into account;
 *    watch out for "side effects" (in the C sense) when modifying this
 *    macro.
 */

#ifndef native
#  define native( c )  ( c )
#  define A_TO_N( str1 )
#  define foreign( c ) ( c )
#else
#  ifndef NATIVE
#    define NATIVE     "native chars"
#  endif
#  define A_TO_N( str1 ) {register uch *p; \
     for ( p = str1; *p; p++ ) *p = native( *p );}
#endif

/*  Translate the zero-terminated string in str1 from ASCII to the native
 *  character set. The translation is performed in-place and uses the
 *  "native" macro to translate each character.
 *
 *  NOTE:  Using the "native" macro means that is it the only part of unzip
 *    which knows which translation table (if any) is actually in use to
 *    produce the native character set.  This makes adding new character set
 *    translation tables easy, insofar as all that is needed is an appropriate
 *    "native" macro definition and the translation table itself.  Currently,
 *    the only non-ASCII native character set implemented is EBCDIC, but this
 *    may not always be so.
 */

/*  Translate "extended ASCII" chars (OEM coding for DOS and OS/2; else
 *  ISO-8859-1 [ISO Latin 1, Win Ansi,...]) into the internal "native"
 *  code page.  As with A_TO_N(), conversion is done in place.
 */

#ifndef _ISO_INTERN
#  ifdef CRTL_CP_IS_OEM
#    ifndef IZ_ISO2OEM_ARRAY
#      define IZ_ISO2OEM_ARRAY
#    endif
#    define _ISO_INTERN( str1 ) {register uch *p; \
       for( p = (uch *)(str1); *p; p++ ) { \
         *p = native( (*p & 0x80) ? iso2oem( *p ) : *p ); }
#  else
#    define _ISO_INTERN( str1 )   A_TO_N( str1 )
#  endif
#endif

#ifndef _OEM_INTERN
#  ifdef CRTL_CP_IS_OEM
#    define _OEM_INTERN( str1 )   A_TO_N( str1 )
#  else
#    ifndef IZ_OEM2ISO_ARRAY
#      define IZ_OEM2ISO_ARRAY
#    endif
#    define _OEM_INTERN( str1 ) {register uch *p; \
       for( p = (uch *)(str1); *p; p++ ) \
         *p = native( (*p & 0x80) ? oem2iso( *p ) : *p ); }
#  endif
#endif

#ifndef STR_TO_ISO
#  ifdef CRTL_CP_IS_ISO
#    define STR_TO_ISO          strcpy
#  else
#    define STR_TO_ISO          str2iso
#    define NEED_STR2ISO
#  endif
#endif

#ifndef STR_TO_OEM
#  ifdef CRTL_CP_IS_OEM
#    define STR_TO_OEM          strcpy
#  else
#    define STR_TO_OEM          str2oem
#    define NEED_STR2OEM
#  endif
#endif

#if ( !defined( STR_TO_ISO ) || defined( NEED_STR2ISO ) )
extern char *str2iso ( char *dst, const char *src );
#endif
#if ( !defined( STR_TO_OEM ) || defined( NEED_STR2OEM ) )
extern char *str2oem ( char *dst, const char *src );
#endif

#if ( !defined( INTERN_TO_ISO ) && !defined( ASCII2ISO ) )
#  ifdef CRTL_CP_IS_OEM
/* know: "ASCII" is "OEM" */
#    define ASCII2ISO( c ) (((c) & 0x80) ? oem2iso( (c) ) : (c))
#    ifndef IZ_OEM2ISO_ARRAY
#      define IZ_OEM2ISO_ARRAY
#    endif
#    if ( defined( NEED_STR2ISO ) && !defined( CRYP_USES_OEM2ISO ) )
#      define CRYP_USES_OEM2ISO
#    endif
#  else
/* assume: "ASCII" is "ISO-ANSI" */
#    define ASCII2ISO( c ) ( c )
#  endif
#endif

#if ( !defined( INTERN_TO_OEM ) && !defined( ASCII2OEM ) )
#  ifdef CRTL_CP_IS_OEM
/* know: "ASCII" is "OEM" */
#    define ASCII2OEM( c ) (c)
#  else
/* assume: "ASCII" is "ISO-ANSI" */
#    define ASCII2OEM( c ) (((c) & 0x80) ? iso2oem( (c) ) : (c))
#    ifndef IZ_ISO2OEM_ARRAY
#      define IZ_ISO2OEM_ARRAY
#    endif
#    if ( defined( NEED_STR2OEM ) && !defined( CRYP_USES_ISO2OEM ) )
#      define CRYP_USES_ISO2OEM
#    endif
#  endif
#endif

/* codepage conversion setup for testp() in crypt.c */
#ifdef CRTL_CP_IS_ISO
#  ifndef STR_TO_CP2
#    define STR_TO_CP2  STR_TO_OEM
#  endif
#else
#  ifdef CRTL_CP_IS_OEM
#    ifndef STR_TO_CP2
#      define STR_TO_CP2  STR_TO_ISO
#    endif
#  else /* native internal CP is neither ISO nor OEM */
#    ifndef STR_TO_CP1
#      define STR_TO_CP1  STR_TO_ISO
#    endif
#    ifndef STR_TO_CP2
#      define STR_TO_CP2  STR_TO_OEM
#    endif
#  endif
#endif

#define cpAUTO 0
#define cpISO  1
#define cpOEM  2
extern void ExtASCII2Native ( struct UGlobals *pG, char *string, int hostnum,
                                short int hostver );

/**********************/

/*  Global constants  */

/**********************/
extern const ush mask_bits[];   /* In Const.h   */
/***********************************/

/*  Global (shared?) RTL variables */

/***********************************/

#ifdef DECLARE_ERRNO
extern const int errno;
#endif

#endif /* !__unzpriv_h */
