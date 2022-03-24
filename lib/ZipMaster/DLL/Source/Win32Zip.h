
/* Win32Zip.h
* Copyright (C) 1990-1996 Mark Adler, Richard B. Wales, Jean-loup Gailly,
* Kai Uwe Rommel, Onno van der Linden and Igor Mandrichenko.
* This version modified by Chris Vleghert and Eric Engler for BCB/Delphi Zip.
 ** distributed under LGPL license ** see license.txt for details

*/

/*
 * Win32 specific functions for ZIP.
 */
//long  GetTheFileTime( char *name );
int GetFileMode ( struct ZGlobals *pG, char *name );

int   IsFileSystemOldFAT( char *dir, struct ZGlobals *pG );

//void  ChangeNameForFAT( char *name );
//int   IsFileNameValid( char *name );
char  *getVolumeLabel( struct ZGlobals *pG, int Drive, ulg *vtime, ulg *vmode,
                       time_t *vutim );

char  *GetLongPathEA( void );

//char *StringLower( char * );
