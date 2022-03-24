#include <windows.h>
#include "common.h"
#include "crypt.h"
#pragma hdrstop

//#include "ZipErr.h"
/* crypt.c (full version) by Info-ZIP.      Last revised:  [see crypt.h]
 *
 * This code is not copyrighted and is put in the public domain.  The
 * encryption/decryption parts (as opposed to the non-echoing password
 * parts) were originally written in Europe; the whole file can there-
 * fore be freely distributed from any country except the USA.  If this
 * code is imported into the USA, it cannot be re-exported from from
 * there to another country.  (This restriction might seem curious, but
 * this is what US law requires.)
 */
/* This encryption code is a direct transcription of the algorithm from
 * Roger Schlafly, described by Phil Katz in the file appnote.txt.  This
 * file (appnote.txt) is distributed with the PKZIP program (even in the
 * version without encryption capabilities).
 * This version modified by Chris Vleghert and Eric Engler for BCB/Delphi Zip.
  ** distributed under LGPL license ** see license.txt for details
 */
//#include "Zip.h"
//#include "ZGlobals.h"
//#include "Crypt.h"
//#include "ttyio.h"

/* For the encoding task used in Zip (and ZipCloak), we want to initialize
 * the crypt algorithm with some reasonably unpredictable bytes, see
 * the crypthead() function. The standard rand() library function is
 * used to supply these 'random' bytes, which in turn is initialized by
 * a srand() call. The srand() function takes an "unsigned" (at least 16bit)
 * seed value as argument to determine the starting point of the rand()
 * pseudo-random number generator.
 * This seed number is constructed as "Seed = Seed1 .XOR. Seed2" with
 * Seed1 supplied by the current time (= "(unsigned)time()") and Seed2
 * as some (hopefully) nondeterministic bitmask. On many (most) systems,
 * we use some "process specific" number, as the PID or something similar,
 * but when nothing unpredictable is available, a fixed number may be
 * sufficient.
 * NOTE:
 * 1.) This implementation requires the availability of the following
 *     standard UNIX C runtime library functions: time(), rand(), srand().
 *     On systems where some of them are missing, the environment that
 *     incorporates the crypt routines must supply suitable replacement
 *     functions.
 * 2.) It is a very bad idea to use a second call to time() to set the
 *     "Seed2" number! In this case, both "Seed1" and "Seed2" would be
 *     (almost) identical, resulting in a (mostly) "zero" constant seed
 *     number passed to srand().
 *
 * The implementation environment defined in the "zip.h" header should
 * supply a reasonable definition for ZCR_SEED2 (an unsigned number; for
 * most implementations of rand() and srand(), only the lower 16 bits are
 * significant!). An example that works on many systems would be
 *      "#define ZCR_SEED2  (unsigned)getpid()".
 * The default definition for ZCR_SEED2 supplied below should be regarded
 * as a fallback to allow successful compilation in "beta state"
 * environments.
 */
//#include <time.h> // time() function supplies first part of crypt seed

// "last resort" source for second part of crypt seed pattern
#ifndef ZCR_SEED2 // RCV: Is now defined in Zip.h
  #define ZCR_SEED2 ( unsigned )3141592654L // use PI as default pattern
#endif

#define CRC32( c, b ) ( crc_table[(( int )(c) ^ (b)) & 0xFF] ^ ((c) >> 8) )

// Return the next byte in the pseudo-random sequence
int _fastcall decrypt_byte( Keys keys )
{
  unsigned  temp;
  temp = ( ( unsigned )keys[2] & 0xFFFF ) | 2;
  return ( int )( ((temp * (temp ^ 1)) >> 8) & 0xFF );
}

// Update the encryption keys with the next byte of plain text c :: Byte of
//   plain text.
int  _fastcall update_keys( int c, Keys keys)//struct ZGlobals *pG )
{
  keys[0] = CRC32( keys[0], c );
  keys[1] += keys[0] & 0xFF;
  keys[1] = keys[1] * 134775813L + 1;
  {
    register int  keyshift = ( int )( keys[1] >> 24 );
    keys[2] = CRC32( keys[2], keyshift );
  }

  return c;
}

// Initialize the encryption keys and the random header according to the
//   given password. passwd :: Password string with which to modify keys.
void _fastcall init_keys( char *passwd, Keys keys )
{
  keys[0] = 305419896L;
  keys[1] = 591751049L;
  keys[2] = 878082192L;
  while ( *passwd != (char)'\0' )
  {
    update_keys( ( int ) *passwd, keys );
    passwd++;
  }
} 

int _fastcall zencode(int c, Keys keys)
{
  int t;
  unsigned  temp;
  temp = ( ( unsigned )keys[2] & 0xFFFF ) | 2;
  t = ( int )( ((temp * (temp ^ 1)) >> 8) & 0xFF );

  keys[0] = CRC32( keys[0], c );
  keys[1] += keys[0] & 0xFF;
  keys[1] = keys[1] * 134775813L + 1;
  {
    register int  keyshift = ( int )( keys[1] >> 24 );
    keys[2] = CRC32( keys[2], keyshift );
  }

  return t^c;
}

int _fastcall zdecode(int c, Keys keys)
{
  int t;
  unsigned  temp;
  temp = ( ( unsigned )keys[2] & 0xFFFF ) | 2;
  t = ( int )( ((temp * (temp ^ 1)) >> 8) & 0xFF );
  t ^= c;
  keys[0] = CRC32( keys[0], t );
  keys[1] += keys[0] & 0xFF;
  keys[1] = keys[1] * 134775813L + 1;
  {
    register int  keyshift = ( int )( keys[1] >> 24 );
    keys[2] = CRC32( keys[2], keyshift );
  }

  return t;
}
