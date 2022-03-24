#include <windows.h>
#include "Common.h"
#pragma hdrstop
#include "Zip.h" 
#include "ZipErr.h"

/* Win32.c
 * Copyright (C) 1990-1996 Mark Adler, Richard B. Wales, Jean-loup Gailly,
 * Kai Uwe Rommel, Onno van der Linden and Igor Mandrichenko.
 * Permission is granted to any individual or institution to use, copy, or
 * redistribute this software so long as all of the original files are included,
 * that it is not sold for profit, and that this copyright notice is retained.
 * This version modified by Chris Vleghert for BCB/Delphi Zip.
  ** distributed under LGPL license ** see license.txt for details
*/
/*
 * Win32 specific functions for ZIP.
 *
 * This version of ZIP heavily relies on the MSDOS version,
 * since we have to do similar things to switch between NTFS, HPFS and FAT.
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

#include "win32zip.h"

#define EAID  0x0009

// NOTE: NTFS is handled by the HPFS code. FAT / HPFS detection.
int IsFileSystemOldFAT( char *dir, struct ZGlobals *pG )
{
  char  *fp,
  *p;
  DWORD vfnsize;
  DWORD vfsflags;

  // We separate FAT and HPFS+other file systems here. I consider other
  //   systems to be similar to HPFS/NTFS, i.e. support for long file names and
  //   being case sensitive to some extent.
  fp = GetFullPath( pG, dir );  // v1.6017
  if ( isalpha( fp[0] ) && fp[1] == (char)':' )
  {
    fp[0] = to_up( fp[0] );
    fp[1] = ':';
    fp[2] = '\\';
    fp[3] = 0;
  }

  // specify \\MyServer\MyShare as \\MyServer\MyShare\.
  if ( fp[0] == (char)'\\' && fp[1] == (char)'\\' )
  {
/*    p = &fp[2];
    if (!strncmp(fp, "\\\\?\\",4))
    {
      p+=2;
    } */
    if ( (p = strchr(/* p */ &fp[2], '\\' )) != NULL )
      p = strchr( p + 1, '\\' );
    if ( p )
      *( p + 1 ) = 0;

  }

  if ( !GetVolumeInformation( fp, NULL, 0, NULL, &vfnsize, &vfsflags, NULL, 0 ) )
  { 
    if ( pG->Frame.Verbose )
    {
      int l = GetLastError();
      Notify( PF, 0, "zip diagnostic: GetVolumeInformation failed for %s [%i]", fp, l );
    }
    return ( false );  // assume NTFS
  }

  return vfnsize <= 12;
}

// access mode bits and time stamp.
int
GetFileMode( struct ZGlobals *pG, char *name )
{
  DWORD dwAttr;

  dwAttr = GetFileAttributes( GetFullPath( pG, name ) );  // v1.6017
  if ( dwAttr == 0xFFFFFFFF )
  {                             // RCV Changed: was ...= -1
    Notify( PF, 0, "zip diagnostic: GetFileAttributes failed\n" );

    // DLLprintf ( "zip diagnostic: GetFileAttributes failed\n" );
    return ( 0x20 );            // the most likely, though why the
    ///* error? security?
  }

  return
    (
      (dwAttr & FILE_ATTRIBUTE_READONLY ? A_RONLY : 0) |
      (dwAttr & FILE_ATTRIBUTE_HIDDEN ? A_HIDDEN : 0) |
      (dwAttr & FILE_ATTRIBUTE_SYSTEM ? A_SYSTEM : 0) |
      (dwAttr & FILE_ATTRIBUTE_DIRECTORY ? A_DIR : 0) |
      (dwAttr & FILE_ATTRIBUTE_ARCHIVE ? A_ARCHIVE : 0)
    );
}

char *
GetLongPathEA( void )
{
  return ( NULL );              // volunteers ?
}

// If a volume label exists for the given drive, return its name and pretend
//   to set its time and mode. The returned name is global data. Drive = drive
//   name: 'A' .. 'Z' or '\0' for current drive
char *
getVolumeLabel( struct ZGlobals *pG, int Drive, ulg *vtime, ulg *vmode, time_t *vutim )
{                               // v1.6017
  char  RootPath[4];
  ulg   fnlen,
  flags;
  long  OldMode = SetErrorMode( SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX );
  BOOL  Result;

  *vmode = A_ARCHIVE | A_LABEL; // this is what msdos returns
  *vtime = dostime( 1980, 1, 1, 0, 0, 0 );  // no true date info available
  *vutim = dos2unixtime( *vtime );

  lstrcpy( RootPath, "x:\\" );
  RootPath[0] = ( char )Drive;
  Result = GetVolumeInformation( Drive ? RootPath : NULL, pG->vol, MAX_PATH - 1, NULL,
                                 &fnlen, &flags, NULL, 0 );
  SetErrorMode( OldMode );
  return Result ? pG->vol : NULL;
}
