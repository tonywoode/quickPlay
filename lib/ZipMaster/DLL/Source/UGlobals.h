
/* This version modified by Chris Vleghert and Eric W. Engler
 * for BCB/Delphi Zip
 */

/* ---------------------------------------------------------------------------
 * globals.h
 * There is usually no need to include this file since unzip.h includes it
 * (via unzpriv.h).
 *
 * This header file is used by all of the UnZip source files.  It contains
 * a struct definition that is used to "house" all of the global variables.
 * This is done to allow for multithreaded environments as NT and Win95,
 * to call UnZip through an API without a semaphore.  REENTRANT should
 * be defined.
 *
 * ADDING VARIABLES TO THE STRUCTURE
 * ---------------------------------
 * If you make the inclusion of any variables conditional, be sure to only
 * check macros that are GUARANTEED to be included in every module.  For
 * instance newzip is only needed if CRYPT is defined, but this is defined
 * after unzip.h has been read.  If you are not careful, some modules will
 * expect your variable to be part of this struct while others won't.  This
 * will cause BIG problems. (Inexplicable crashes at strange times, car fires,
 * etc.)  When in doubt, always include it!
 *
 * ---------------------------------------------------------------------------
 */

#ifndef __uglobals_h
#define __uglobals_h

//#include "Enter.h"
//#include "Common.h"
//#include "WizUnZip.h"
//#include "unzip.h"
#include "Crypt.h"

#define SAFE_MAX_PATH ((MAX_PATH * 3) / 2)
#define SAFE_FILNAMSIZ (FILNAMSIZ + (FILNAMSIZ / 4))
  
#ifndef USE_STRM_OUTPUT
# define USE_STRM_OUTPUT
#endif

#ifndef USE_STRM_INPUT
#define USE_STRM_INPUT
#endif

/*************/
/*  UGlobals  */
/*************/
struct UGlobals
{
    struct OpFrame Frame;       // must be first element
    int zipinfo_mode;             /* behave like ZipInfo or like normal UnZip? */
    int aflag;                    /* -a: do ASCII-EBCDIC and/or end-of-line translation */
    int cflag;                    /* -c: output to stdout   */
    int C_flag;                   /* -C: match filenames case-insensitively  */
    int dflag;                    /* -d: all args are files/dirs to be extracted */
    int fflag;                    /* -f: "freshen" (extract only newer files) */
    int jflag;                    /* -j: junk pathnames (unzip) */
    int lflag;                    /* -12slmv: listing format (zipinfo)*/
    int L_flag;                   /* -L: convert filenames from some OSes to lowercase */
    int overwrite_all;            /* -o combined with -n: Ok to overwrite used as default */
    int qflag;                    /* -q: produce a lot less output */
    int sflag;                    /* -s: convert spaces in filenames to underscores */
    int volflag;                  /* -$: extract volume labels */
    int tflag;                    /* -t: test (unzip) or totals line (zipinfo) */
    int T_flag;                   /* -T: timestamps (unzip) or dec. time fmt (zipinfo) */
    int uflag;                    /* -u: "update" (extract only newer/brand-new files) */
    int V_flag;                   /* -V: don't strip VMS version numbers */
    int zflag;                    /* -z: display the zipfile comment (only, for unzip) */
    int P_flag;                   /* -P: give password on command line (ARGH!) */

    int filespecs;                /* number of real file specifications to be matched */
    int process_all_files;
    int create_dirs;              /* used by main(), mapname(), checkdir() */
    int extract_flag;
    int newzip;                   /* used in extract.c, crypt.c, zipinfo.c */

    // ecrec = End of Central directory Record
    long real_ecrec_offset;
    long expect_ecrec_offset;

    long csize;                   /* used by list_files(), NEXTBYTE: must be signed   */
    long ucsize;                  /* used by list_files(), unReduce(), explode() */
    long used_csize;              /* used by extract_or_test_member(), explode() */

    bool redirect_data;           /* redirect data to memory buffer                                                     */
    // int                          redirect_text;  /* redirect text output to buffer */
    unsigned _wsize;
    uch *redirect_pointer;
    uch *redirect_buffer;
    unsigned redirect_size;
    unsigned buffer_size;

    UnzFileData ( *pfnames ) [];     /* RCV changed: was char **pfnames; */
    char sig[ 5 ];
    /*min_info*/ chdr_info info[ DIR_BLKSIZ ];
    /*min_info*/ chdr_info *pInfo;
    union work area;              /* see unzpriv.h for definition of work */

    ulg *crc_32_tab;
    ulg crc32val;                 /* CRC shift reg. (was static in funzip) */

    uch *inbuf;                   /* input buffer (any size is OK) */
    uch *inptr;                   /* pointer into input buffer  */
    int incnt;
    ulg bitbuf;
    int bits_left;                /* unreduce and unshrink only */
    int zipeof; 
    char *zipfn;                  /* GRR:  MSWIN:  must nuke any malloc'd zipfn... */
    bool UseInStream;             /* NEW Use memory stream as input.  */
    void *InStream;               /* NEW Pointer to the start of the input stream data. */
    unsigned long InStreamSize;   /* NEW Size of the input data. */
    unsigned long StreamPos;      /* NEW The present position in the stream */
    HANDLE zipfdz;                    /* zipfile file handle */

    POSN ziplen;
    POSN cur_zipfile_bufstart;    /* extract_or_test, readbuf, ReadByte */
    long extra_bytes;             /* used in unzip.c, misc.c */
    uch *extra_field;             /* Unix, VMS, Mac, OS/2, Acorn, ... */
    uch *hold;
    char local_hdr_sig[ 5 ];        /* initialize sigs at runtime so unzip */
    char central_hdr_sig[ 5 ];      /*  executable won't look like a zipfile */
    char end_central_sig[ 5 ];

    local_file_hdr lrec;          /* used in unzip.c, extract.c */
    cdir_file_hdr crec;           /* used in unzip.c, extract.c, misc.c */
    ecdir_rec ecrec;              /* used in unzip.c, extract.c */
    struct stat statbuf;          /* used by main, mapname, check_for_newer */

    int mem_mode;
    uch *outbufptr;               /* extract.c static */
    ulg outsize;                  /* extract.c static */
    int reported_backslash;       /* extract.c static */
    int disk_full;
    int newfile;

    int didCRlast;                /* fileio static */
    int sol;                      /* fileio static: at start of line */
    int no_ecrec;                 /* process static */
#ifdef NOVELL_BUG_FAILSAFE
    int dne;                      /* true if stat() says file doesn't exist */
#endif 
    FILE *outfile;
    uch *outbuf;
    uch *realbuf;

    uch *outbuf2;                 /*  main() (never changes); else malloc'd */
    uch *outptr;
    ulg outcnt;                   /* number of chars stored in outbuf */

    int nopwd;                    /* crypt static */
    Keys keys;                /* crypt static: keys defining pseudo-random sequence */
    char *key;                    /* crypt static: decryption password or NULL */
    char *pwdarg;                 /* pointer to command-line password (-P option) */

    unsigned hufts;               /* track memory usage */

    struct huft *fixed_tl;        /* inflate static */
    struct huft *fixed_td;        /* inflate static */
    int fixed_bl;                 /* inflate static */
    int fixed_bd;                 /* inflate static */
    unsigned wp;                  /* inflate static: current position in slide */
    ulg bb;                       /* inflate static: bit buffer */
    unsigned bk;                  /* inflate static: bits in bit buffer */

    int incnt_leftover;           /* so improved NEXTBYTE does not waste input */
    uch *inptr_leftover;

    /* Static variables that we have to add to struct UGlobals: */
    /* created_dir, renamed_fullpath, fnlen, and nLabelDrive are used by   */
    /*    both mapname() and checkdir().                                   */
    int created_dir;
    int renamed_fullpath;
    int fnlen;
    unsigned nLabelDrive;
    char *endHPFS;
    char *endFAT;
    char *ExtractPathEnd;       // new 1.78.2.0
    char *dirname;
    char *wildname;
    char matchname[ FILNAMSIZ ];
    int rootlen;
    int have_dirname;
    int dirnamelen;
    int notfirstcall;
    void *wild_dir;

    char ewemsg[ 2048 ];
    int global_error_code;        // in UnzErr() in dllmain
    int files_acted_on;
    int dll_handles_errors;
    int user_notified_of_abort;   // in UnzErr() in dllmain
    char ZipFNbuf[SAFE_FILNAMSIZ];
    char filename[SAFE_MAX_PATH];
    char rootpath[SAFE_MAX_PATH];
    char buildpathHPFS[SAFE_MAX_PATH];
    char buildpathFAT[SAFE_MAX_PATH];
    char ExtractPath[SAFE_MAX_PATH];
    char TempPath[SAFE_MAX_PATH];
    int PwdReqCount;
    HANDLE hFileDat;
    UnzFileData ( *FileDat ) [];
    unsigned /*short*/ WantedCodePage; 
#ifdef CRYPT                    /* If no crypt don't use */
    char lpszPassword[ PWLEN + 1 ]; /* Used in PassMsg.c                                                                                             */
    WORD cchPassword;
    bool pwork;
    int rcode;
#endif
};                              /* end of struct UGlobals */


/***************************************************************************/
extern struct UGlobals *Create_UGlobals( UnZipParms * C );
extern void Destroy_UGlobals( struct UGlobals *pG);
extern struct UGlobals *Current_UGlobals( void );

#endif /* __uglobals_h */
