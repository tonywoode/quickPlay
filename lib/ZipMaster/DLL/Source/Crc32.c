#include <windows.h>
#include "Common.h"
#pragma hdrstop
//#ifdef _USE_ASM_
#if defined(_USE_ASM_) && (__BORLANDC__ < 0x0570)
  #pragma inline
#endif
#include "Zip.h"
//#include "ZipErr.h"
/* crc32.c -- compute the CRC-32 of a data stream
* Copyright (C) 1995 Mark Adler
* For conditions of distribution and use, see copyright notice in zlib.h
* This version modified by Chris Vleghert for BCB/Delphi Zip.
 ** distributed under LGPL license ** see license.txt for details
*/

/* $Id: crc32.c,v 1.5 1996/01/13 14:55:12 spc Exp $ */
/*$Id This is generic text from the file Header_Func.txt
It is optionally included via the Source Format utility
It can be as long and descriptive as desired.
 */
//It is optionally included via the Source Format utility
//It can be as long and descriptive as desired.
//
//#include "Zip.h"

#ifndef _USE_ASM_
  #ifdef CRC32
    #undef CRC32
  #endif
  #define CRC32( c, b ) ( crc_table[(( int )(c) ^ (b)) & 0xFF] ^ ((c) >> 8) )
  #define DO1( buf )    crc = CRC32( crc, *buf++ )
  #define DO2( buf ) \
  DO1( buf );        \
  DO1( buf )
  #define DO4( buf ) \
  DO2( buf );        \
  DO2( buf )
  #define DO8( buf ) \
  DO4( buf );        \
  DO4( buf )

// Run a set of bytes through the crc shift register. If buf is a NULL
//   pointer, then initialize the crc shift register contents instead. Return
//   the current crc in either case. crc :: crc shift register. buf :: Pointer
//   to bytes to pump through. len :: Number of bytes in buf[].
ulg __fastcall
crc32( ulg crc, const uch *buf, extent len )
{
  // register ulg *crc_table;
  if ( buf == NULL )
    return 0L;

  // crc_table = get_crc_table ();
  crc = crc ^ 0xFFFFFFFFL;
#ifndef NO_UNROLLED_LOOPS
  while ( len >= 8 )
  {
    DO8( buf );
    len -= 8;
  }
#endif
  if ( len )
    do
    {
      DO1( buf );
    }
    while ( --len );
  return crc ^ 0xFFFFFFFFL; // (instead of ~c for 64-bit machines)
}
#else
// ; These two (three) macros make up the loop body of the CRC32 cruncher.
// ; registers modified:
// ; eax : crc value "c"
// ; edx : pointer to next data byte (or dword) "buf++"
// ; registers read:
// ; esi : pointer to base of crc_table array
// ; scratch registers:
// ; ebx : index into crc_table array
#define Do_CRC        movzx ebx, al; \
  shr eax, 8;                          \
  xor eax, dword ptr[esi + 4 * ebx];
  #define Do_CRC_Byte   xor al, byte ptr[edx]; \
  inc edx;                                     \
  Do_CRC
  #define Do_CRC_DWord  xor eax, dword ptr[edx]; \
  add edx, 4;                                    \
  Do_CRC Do_CRC Do_CRC Do_CRC                    \
                                                \
  // Run a set of bytes through the crc shift register. If buf is a NULL
//   pointer, then initialize the crc shift register contents instead. Return
//   the current crc in either case. crc :: crc shift register. buf :: Pointer
//   to bytes to pump through. len :: Number of bytes in buf[].
ulg __fastcall
crc32( ulg crc, const uch *buf, extent len )
{
#pragma argsused
  asm
  {
    // ; EAX = crc, EDX = buf, ESI = &
    // crc_table, ECX = len
    // if ( buf == NULL ) return 0L;
    test  edx, edx
    jne short L2
    xor eax, eax
    jmp Empty
  L2:
    // if (!len) return crc;
    test ecx, ecx
    jz Empty
    mov esi, offset crc_table

    // ; EAX = crc, EDX = buf, ESI = &
    // crc_table, ECX = len
    // crc = crc ^ 0xFFFFFFFFL;
    not eax
  N3:
    test edx, 3                 // aligned ?
    jz short Next_Eight
    Do_CRC_Byte
    dec ecx
    jnz short N3
//  N4: // aligned
  Next_Eight:
    cmp ecx, 8
    jb NoEights

    // Next_Eight:
#if 1
    Do_CRC_DWord
    Do_CRC_DWord
    sub ecx, 8
    jnz Next_Eight
    jmp short Done

    // ja short Next_Eight
#else
    Do_CRC_Byte
    Do_CRC_Byte
    Do_CRC_Byte
    Do_CRC_Byte
    Do_CRC_Byte
    Do_CRC_Byte
    Do_CRC_Byte
    Do_CRC_Byte
    sub ecx, 8
    ja Next_Eight
#endif
    // ; EAX = crc, EDX = buf, ESI = &
    // crc_table, ECX = len
  NoEights:
    sub ecx, 1
    jb short Done

    // DoLast:
    Do_CRC_Byte
    jmp short NoEights

    // dec ecx
    // jnz short DoLast
  Done:
    xor eax, -1

    // ; EAX = crc
  Empty:
#pragma warn - rvl
  };
};
#endif // !_USE_ASM_
