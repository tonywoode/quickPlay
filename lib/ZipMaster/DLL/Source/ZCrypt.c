#include <windows.h>
#include "common.h"
#include "zip.h"
#include "crypt.h"

//#define zencode( c, t )  (t = decrypt_byte( pG ), update_keys( c ), t^(c) )
#define zencode( c, t, k )  (t = decrypt_byte( k ), update_keys( c, k ), t^(c) )

// Write encryption header to file zfile using the password passwd and the
//   cyclic redundancy check crc. passwd :: Password string. crc :: Crc of file
//   being encrypted. zfile :: Where to write header.
#define Putc( c, f )  ( temp[tcnt++] = (c) )
void
crypthead( char *passwd, ulg crc, HANDLE zfile, struct ZGlobals *pG )
{
  int           n;      // Index in random header.
  int           t;      // Temporary.
  int           c;      // Random byte.
  int           ztemp;  // Temporary for zencoded value.
  uch           header[RAND_HEAD_LEN - 2];  // Random header.
  uch           temp[RAND_HEAD_LEN + 2];
  int           tcnt = 0;
  unsigned long k;

  // First generate RAND_HEAD_LEN - 2 random bytes. We encrypt the output of
  //   rand() to get less predictability, since rand() is often poorly
  //   implemented.
  if ( ++pG->calls == 1 )
  {
    srand( ( unsigned )time( NULL ) ^ ZCR_SEED2 );
  }

  init_keys( passwd, pG->keys );
  for ( n = 0; n < RAND_HEAD_LEN - 2; n++ )
  {
    c = ( rand() >> 7 ) & 0xFF;
    header[n] = ( uch ) zencode( c, t, pG->keys );
  }

  // Encrypt random header (last two bytes is high word of crc)
  init_keys( passwd, pG->keys );
  for ( n = 0; n < RAND_HEAD_LEN - 2; n++ )
  {
    ztemp = zencode( header[n], t, pG->keys );
    Putc( (uch) ztemp, zfile );             // V1.5 Added (uch)
  }

  ztemp = zencode( ( int )(crc >> 16) & 0xFF, t, pG->keys );
  Putc( (uch) ztemp, zfile );               // V1.5 Added (uch)
  ztemp = zencode( ( int )(crc >> 24) & 0xFF, t, pG->keys );
  Putc( (uch) ztemp, zfile );               // V1.5 Added (uch)
  WriteFile( zfile, temp, tcnt, &k, NULL );
  //  Assert(k < (RAND_HEAD_LEN + 2), "temp buffer overflow");
  pG->BytesWritten += k;
}

// If requested, encrypt the data in buf, and in any case call fwrite() with
//   the arguments to zfwrite(). Return what fwrite() returns. buf :: Data
//   buffer. item_size :: Size of each item in bytes. nb :: Number of items. f
//   :: File to write to.
unsigned
zfwrite( void *buf, extent nb, HANDLE f, struct ZGlobals *pG )
{
  unsigned long k;
  int           t;            // temporary
  unsigned      r;

  if ( pG->key )
  {                           // key is the global password pointer
    ulg   size;               // buffer size
    char  *p = ( char * )buf; // steps through buffer
    while (nb)
    {
      ulg tw = sizeof(pG->ewetmp);
      char *d = pG->ewetmp;
      if (tw > nb)
        tw = nb;
      // Encrypt data in buffer
      for ( size = tw; size != 0; p++, size-- )
      {
        *d++ = ( char )zencode( *p, t, pG->keys );
      }
      r = WriteFile( f, pG->ewetmp, tw, &k, NULL );
      pG->BytesWritten += k;
      nb -= k;
      if ( !r )
      {
        diag( "zfwrite failed", pG );
        return r;
      }
    }
    return 1;
  }
  // Write the buffer out
  r = WriteFile( f, buf, nb, &k, NULL );
  if ( !r )
    diag( "zfwrite failed", pG );
  pG->BytesWritten += k;
  return r;
}
 
