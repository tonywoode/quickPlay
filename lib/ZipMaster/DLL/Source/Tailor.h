
/* Tailor.h -- Not copyrighted 1993 Mark Adler
* This version modified by Chris Vleghert for BCB/Delphi Zip.
** distributed under LGPL license ** see license.txt for details
1.73 11 July 2003
1.73.2.6 21 September 2003
*/

//#include "osdep.h"
#ifndef MSDOS

/* Windows 95 (and Windows NT) file systems are (to some extent)
 *  extensions of MSDOS. Common features include for example:
 *      FAT or (FAT like) file systems,
 *      '\\' as directory separator in paths,
 *      "\r\n" as record (line) terminator in text files, ...
 */
#define MSDOS       /* Inherit MS-DOS file system etc. stuff. */
#endif
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>

typedef size_t extent;

/* System independent replacement for "struct utimbuf",
 * which is missing in many older OS environments.
 */
typedef struct  ztimbuf
{
  time_t  actime;     /* new access time */
  time_t  modtime;    /* new modification time */
}

ztimbuf;

/* Some systems define S_IFLNK but do not support symbolic links */
#if defined( S_IFLNK )
  #undef S_IFLNK
#endif
#if defined( _MBCS )
  #undef _MBCS
#endif

/* Open the old zip file in exclusive mode if possible
 * (to avoid adding zip file to itself).
 */
//#define FOPR_EX FOPR
/* MSDOS file attribute for directories */
#define MSDOS_DIR_ATTR  0x10

/* Define this symbol if your target allows access to unaligned data.
 * This is not mandatory, just a speed optimization. The compressed
 * output is strictly identical.
 */
#ifndef CBSZ
  #define CBSZ  16384 /* buffer size for copying files      */
  #define ZBSZ  16384 /* buffer size for temporary zip file */
#endif
#ifndef SSTAT
  #define SSTAT stat
#endif
#ifdef S_IFLNK
  #define LSTAT           lstat
  #define LSSTAT( n, s )  ( linkput ? lstat( (n), (s) ) : SSTAT( (n), (s) ) )
#else
  #define LSTAT   SSTAT
  #define LSSTAT  SSTAT
#endif

/* The following OS code is defined in pkzip appnote.txt */
#define OS_CODE   0xB00
#define NUM_HOSTS 16

/* Number of operating systems. Should be updated when new ports are made */
#define zcalloc( items, size ) \
  ( void * )calloc( ( unsigned )(items), ( unsigned )(size) )
#define zcfree            FREE

#define CLEN( ptr )       1
#define PREINCSTR( ptr )  ( ++(ptr) )
#define POSTINCSTR( ptr ) ( (ptr)++ )
#define lastchar( ptr )   ( (*(ptr) == '\0') ? '\0' : ptr[lstrlen( ptr ) - 1] )
#define MBSCHR( str, c )  strchr( str, c )
#define MBSRCHR( str, c ) strrchr( str, c )
#define SETLOCALE( category, locale )
#define INCSTR( ptr ) PREINCSTR( ptr )
