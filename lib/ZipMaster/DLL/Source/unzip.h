
/* This version modified by Chris Vleghert and Eric W. Engler
 * for BCB/Delphi Zip, Jun 18, 2000.
 *
 * EWE NOTE:  Everything in this file is critical!
 */

/*---------------------------------------------------------------------------
 * unzip.h
 * This header file contains the public macros and typedefs required by
 * both the UnZip sources and by any application using the UnZip API.  If
 * it includes unzpriv.h, which then includes globals.h.
 *---------------------------------------------------------------------------*/

#ifndef __unzip_h               /* prevent multiple inclusions */
  #define __unzip_h

  #include <stdio.h>
  #include <windows.h>

  #include "common.h"
  #include "unzerr.h"

  #ifndef CRYPT
    # define CRYPT 1
  #endif

  #ifndef USE_STRM_OUTPUT
    # define USE_STRM_OUTPUT
  #endif

extern void MsgBox( struct UGlobals * pG );
extern void UnzErr( struct UGlobals * gP, int c );

//  # define MALLOC( s ) malloc( (s) )
  # define GLOBALALLOC( f, s ) GlobalAlloc( (f), (s) )
//  # define FREE( p ) free( (void *)(p) )
  # define GLOBALFREE( p ) GlobalFree( (p) )

/**  */

/* Predefined, Machine-specific Macros */

/**  */
#if (!defined(DOSWILD))
  #  define DOSWILD
#endif

#if (!defined(NO_ZIPINFO))
  #  define NO_ZIPINFO
#endif

#if (!defined(MSDOS))
  #  define MSDOS
#endif

// By defining COPYRIGHT_CLEAN, we lose support for these 2 compression
// types: tokenizing (which was never popular)
//   and  reducing   (which was only used in pre-v1 beta releases of PKZIP
#ifndef COPYRIGHT_CLEAN
  #  define COPYRIGHT_CLEAN
#endif

#ifndef NO_MULTIPART
  #  define NO_MULTIPART
#endif
 

#if (defined ASM_INFLATECODES)
  # undef ASM_INFLATECODES
#endif

#ifndef EXPENTRY
  #  define UZ_EXP WINAPI
#else
  #  define UZ_EXP EXPENTRY
#endif

#ifndef UZ_EXP
  #  define UZ_EXP
#endif

typedef unsigned long POSN; // file positions

// EWE note: All platforms need this VMS version:
#define VMS_UNZIP_VERSION 42

/**  */

/* OS-Dependent Includes */

/**  */
#ifndef NO_STDDEF_H
  #  include <stddef.h>
#endif
#ifndef NO_STDLIB_H
  #  include <stdlib.h>           /* standard library prototypes, malloc(), etc. */
#endif
                
#pragma option -a1
typedef struct central_directory_file_header
{
  /* CENTRAL */
  uch version_made_by[2];
  uch version_needed_to_extract[2];
  ush general_purpose_bit_flag;
  ush compression_method;
  ush last_mod_file_time;
  ush last_mod_file_date;
  ulg crc32;
  ulg csize;
  ulg ucsize;
  ush filename_length;
  ush extra_field_length;
  ush file_comment_length;
  ush disk_number_start;
  ush internal_file_attributes;
  ulg external_file_attributes;
  ulg relative_offset_local_header;
}
cdir_file_hdr; 
#pragma option -a.

/*---------------------------------------------------------------------------
Remaining private stuff for UnZip compilation.
---------------------------------------------------------------------------*/
#include "unzpriv.h"
/*
#ifdef __cplusplus
extern "C"
{
long WINAPI UnzExec ( UnZipParms * C );
}
#else
long WINAPI UnzExec ( UnZipParms * C );
#endif
*/
#endif /* !__unzip_h */
