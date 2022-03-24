#include <windows.h>
#include "Common.h"
#pragma hdrstop
#include "Zip.h"
#include "ZipErr.h"

// Bits.c Copyright (C) 1990-1996 Mark Adler, Richard B. Wales, Jean-loup
///* Gailly, Kai Uwe Rommel, Onno van der Linden and Igor Mandrichenko.
///* Permission is granted to any individual or institution to use, copy, or
///* redistribute this software so long as all of the original files are
///* included, that it is not sold for profit, and that this copyright notice
///* is retained. This version modified by Chris Vleghert and Eric Engler for
///* BCB/Delphi Zip. distributed under LGPL license ** see license.txt for
///* details
// bits.c by Jean-loup Gailly and Kai Uwe Rommel. This is a new version of
//   im_bits.c originally written by Richard B. Wales PURPOSE Output
//   variable-length bit strings. Compression can be done to a file or to
//   memory. DISCUSSION The PKZIP "deflate" file format interprets compressed
//   file data as a sequence of bits. Multi-bit strings in the file may cross
//   byte boundaries without restriction. The first bit of each byte is the
//   low-order bit. The routines in this file allow a variable-length bit value
//   to be output right-to-left (useful for literal values). For left-to-right
//   output (useful for code strings from the tree routines), the bits must
//   have been reversed first with bi_reverse(). For in-memory compression, the
//   compressed bit stream goes directly into the requested output buffer. The
//   input data is read in blocks by the mem_read() function. The buffer is
//   limited to 64K on 16 bit machines. INTERFACE void bi_init( FILE *zipfile )
//   Initialize the bit string routines. void send_bits( int value, int length
//   ) Write out a bit string, taking the source bits right to left. int
//   bi_reverse( int value, int length ) Reverse the bits of a bit string,
//   taking the source bits left to right and emitting them right to left. void
//   bi_windup( void ) Write out any remaining bits in an incomplete byte. void
//   copy_block( char *buf, unsigned len, int header ) Copy a stored block to
//   the zip file, storing first the length and its one's complement if
//   requested. int seekable( void ) Return true if the zip file can be seeked.
//   ulg memcompress( char *tgt, ulg tgtsize, char *src, ulg srcsize );
//   Compress the source buffer src into the target buffer tgt.
//#include "Zip.h"
//#include "ZGlobals.h"
//#include "crypt.h"
//#include "ZipErr.h"
// Number of bits used within bi_buf. (bi_buf might be implemented on more
//   than 16 bits on some systems.)
#define Buf_size  ( 8 * 2 * sizeof(char) )

// Output a 16 bit value to the bit stream, lower (oldest) byte first
/*#define xPUTSHORT( w )                                           \
 {                                                             \
  if ( pG->out_offset < pG->out_size - 1 )                    \
  {                                                           \
   pG->out_buf[pG->out_offset++] = (char)( (w) & 0xFF );      \
   pG->out_buf[pG->out_offset++] = (char)( (ush) (w) >> 8 );  \
  }                                                           \
  else                                                        \
  {                                                           \
   flush_outbuf( (w), 2, pG );                               \
  }                                                           \
  }   */
#define PUTBYTE( b )                                 \
  {                                                  \
    if ( pG->out_offset < pG->out_size )             \
    {                                                \
      pG->out_buf[pG->out_offset++] = ( char )( b ); \
    }                                                \
    else                                             \
    {                                                \
      flush_outbuf( (b), 1, pG );                    \
    }                                                \
  }

// Prototypes for local functions
static int  mem_read( unsigned char *b, unsigned bsize, struct ZGlobals *pG );
static void __fastcall  flush_outbuf( unsigned w, unsigned bytes, struct ZGlobals *pG );

// Initialize the bit string routines. zipfile :: Output zip file, NULL for
//   in-memory compression.
void
bi_init( HANDLE zipfile, struct ZGlobals *pG )
{
  pG->zfile = zipfile;
  pG->bi_buf = 0;
  pG->bi_valid = 0;
#ifdef DEBUG
  pG->bits_sent = 0L;
#endif 
  // Set the defaults for file compression. They are set by memcompress for
  //   in-memory compression.
  if ( pG->zfile > 0 )  //!= INVALID_HANDLE_VALUE )
  {
    pG->out_buf = pG->file_outbuf;
    pG->out_size = sizeof( pG->file_outbuf );
    pG->out_offset = 0;
    pG->read_buf = file_read;
  }
}

// Send a value on a given number of bits. IN assertion: length <= 16 and
//   value fits in length bits. value :: Value to send. length :: Number of
//   bits.
void __fastcall
send_bits( int value, int length, struct ZGlobals *pG )
{
#ifdef DEBUGx
  Tracevv( (" l %2d v %4x "), (length, value) );
  Assert( length > 0 && length <= 15, "invalid length" );
  pG->bits_sent += ( ulg ) length;
#endif

  // If not enough room in bi_buf, use (valid) bits from bi_buf and (16 -
  //   bi_valid) bits from value, leaving (width - (16-bi_valid)) unused bits
  //   in value.
  if ( pG->bi_valid > ( int )Buf_size - length )
  {
    pG->bi_buf |= ( ush ) ( value << pG->bi_valid );                    // RCV Added (ush)

    //  PUTSHORT( pG->bi_buf );  /*
    if ( pG->out_offset < pG->out_size - 1 )
    {
      *( ush * ) ( pG->out_buf + pG->out_offset ) = ( ush ) pG->bi_buf;
      pG->out_offset += 2;
    }
    else
    {
      flush_outbuf( (pG->bi_buf), 2, pG );
    }

    pG->bi_buf = ( ush ) ( (ush) value >> (Buf_size - pG->bi_valid) );  // RCV Added (ush)(...)
    pG->bi_valid += length - Buf_size;
  }
  else
  {
    pG->bi_buf |= ( ush ) ( value << pG->bi_valid );                    // RCV Added (ush)
    pG->bi_valid += length;
  }
}

// Reverse the first len bits of a code, using straightforward code (a
//   faster method would use a table) IN assertion: 1 <= len <= 15 code :: The
//   value to invert. len :: Its bit length.
#ifndef _USE_ASM_
unsigned __fastcall
bi_reverse( unsigned code, int len )
{
  register unsigned res = 0;
  do
  {
    res |= code & 1;
    code >>= 1, res <<= 1;
  }
  while ( --len > 0 );
  return ( res >> 1 );
}

#else
unsigned __fastcall
bi_reverse( unsigned code, int len )
{
#pragma warn - rvl
  #pragma argsused
  asm
  {                     // EAX=code EDX=len
    mov ecx, eax
    xor eax, eax
  Loop1:
    dec edx
    jl short doneit
    ror ecx, 1
    rcl eax, 1
    jmp short Loop1
  doneit:
  };
}

#endif

// Flush the current output buffer. w :: Value to flush. bytes :: Number of
//   bytes to flush (0, 1 or 2).
static void __fastcall
flush_outbuf( unsigned w, unsigned bytes, struct ZGlobals *pG )
{
  // Encrypt and write the output buffer:
  if ( pG->out_offset != 0 )
  {
    // zfwrite ( pG->out_buf, 1, ( extent ) pG->out_offset, pG->zfile, pG );
    if ( !zfwrite( pG->out_buf, /*1,*/ (extent) pG->out_offset, pG->zfile, pG ) )
      // if ( ferror ( pG->zfile ) )
      // if ( GetLastError ( ) )
    {
      diag( "Write error in flush_outbuf", pG );
      ziperr( ZEN_WRITE01, pG );
    }
  }

  pG->out_offset = 0;
  if ( bytes == 2 )
  {
    //    PUTSHORT( w ); /*
    if ( pG->out_offset < pG->out_size - 1 )
    {
      *( ush * ) ( pG->out_buf + pG->out_offset ) = ( ush ) w;
      pG->out_offset += 2;
    }
    else
    {
      flush_outbuf( (w), 2, pG );
    }
  }
  else
    if ( bytes == 1 )
      pG->out_buf[pG->out_offset++] = ( char )( w & 0xFF );
}

// Write out any remaining bits in an incomplete byte.
void __fastcall
bi_windup( struct ZGlobals *pG )
{
  if ( pG->bi_valid > 8 )
  {
    //  PUTSHORT( pG->bi_buf );
    if ( pG->out_offset < pG->out_size - 1 )
    {
      *( ush * ) ( pG->out_buf + pG->out_offset ) = ( ush ) pG->bi_buf;
      pG->out_offset += 2;
    }
    else
    {
      flush_outbuf( (pG->bi_buf), 2, pG );
    }
  }
  else
    if ( pG->bi_valid > 0 )
    {
      PUTBYTE( pG->bi_buf );
    }

  if ( pG->zfile != NULL )
    flush_outbuf( 0, 0, pG );
  pG->bi_buf = 0;
  pG->bi_valid = 0;
#ifdef DEBUG

  pG->bits_sent = ( pG->bits_sent + 7 ) &~7;
#endif
}

// Copy a stored block to the zip file, storing first the length and its
//   one's complement if requested. block :: The input data. len :: Its length.
//   header :: True if block header must be written.
void __fastcall
copy_block( char *block, unsigned len, int header, struct ZGlobals *pG )
{
  bi_windup( pG );      // align on byte boundary
  if ( header )
  {
    //    PUTSHORT( (ush) len );
    if ( pG->out_offset < pG->out_size - 1 )
    {
      *( ush * ) ( pG->out_buf + pG->out_offset ) = ( ush ) len;
      pG->out_offset += 2;
    }
    else
    {
      flush_outbuf( (len), 2, pG );
    }

    //    PUTSHORT( (ush)~len );
    if ( pG->out_offset < pG->out_size - 1 )
    {
      *( ush * ) ( pG->out_buf + pG->out_offset ) = ( ush )~len;
      pG->out_offset += 2;
    }
    else
    {
      flush_outbuf( (~len), 2, pG );
    }
#ifdef DEBUG
    pG->bits_sent += 2 * 16;
#endif
  }

  if ( pG->zfile )
  {
    flush_outbuf( 0, 0, pG );

    // zfwrite ( block, 1, len, pG->zfile, pG );
    // if ( ferror ( pG->zfile ) )
    if ( !zfwrite( block, /*1,*/ len, pG->zfile, pG ) )
      ziperr( ZEN_WRITE02, pG );
  }
  else
    if ( pG->out_offset + len > pG->out_size )
    {
      ziperr( ZEN_LOGIC01, pG );
    }
    else
    {
      memcpy( pG->out_buf + pG->out_offset, block, len );
      pG->out_offset += len;
    }

#ifdef DEBUG
  pG->bits_sent += ( ulg ) len << 3;
#endif
}

// Return true if the zip file can be seeked. This is used to check if the
//   local header can be re-rewritten. This function always returns true for
//   in-memory compression. IN assertion: the local header has already been
//   written (ftell() > 0).
int
seekable( struct ZGlobals *pG )
{
  long  hi;

  // unsigned long ul;
  // return ( pG->zfile == NULL || ( fseek ( pG->zfile, -1L, SEEK_CUR ) == 0 &
  // &
  // fseek ( pG->zfile, 1L, SEEK_CUR ) == 0 ) );
  if ( pG->zfile <= 0 ) //== INVALID_HANDLE_VALUE )
    return 1;
  hi = -1;
  if ( SetFilePointer( pG->zfile, -1, &hi, FILE_CURRENT ) == INVALID_SET_FILE_POINTER
       && GetLastError() )
  {
    diag( "seekable - failed!", pG );
    return 0;
  }

  hi = 0;
  if ( SetFilePointer( pG->zfile, 1, &hi, FILE_CURRENT ) == INVALID_SET_FILE_POINTER
       && GetLastError() )
  {
    diag( "seekable + failed", pG );
    return 0;
  }

  pG->CanSeek = 1;      // 1.75 can seek
  return 1;
}

// In-memory compression. This version can be used only if the entire input
//   fits in one memory buffer. The compression is then done in a single call
//   of memcompress(). (An extension to allow repeated calls would be possible
//   but is not needed here.) The first two bytes of the compressed output are
//   set to a short with the method used (DEFLATE or STORE). The following four
//   bytes contain the CRC. The values are stored in little-endian order on all
//   machines. This function returns the byte size of the compressed output,
//   including the first six bytes (method and crc). tgt, *src :: Target and
//   source buffers. tgtsize, srcsize :: Target and source sizes.
ulg
memcompress( char *tgt, ulg tgtsize, char *src, ulg srcsize, struct ZGlobals *pG )
{
  ush att = ( ush ) UNKNOWN;
  ush flags = 0;
  ulg crc;              // RCV Removed ...= 0;
  int method = DEFLATE;

  if ( tgtsize <= 6L )
    ziperr( ZEN_LOGIC02, pG );

  crc = crc32( 0L, (const uch * )NULL, 0 );
  crc = crc32( crc, (const uch * )src, (extent) srcsize );

  pG->read_buf = mem_read;
  pG->in_buf = src;
  pG->in_size = ( unsigned )srcsize;
  pG->in_offset = 0;

  pG->out_buf = tgt;
  pG->out_size = ( unsigned )tgtsize;
  pG->out_offset = 2 + 4;
  pG->window_size = 0L;

  bi_init( ( FILE * )NULL, pG );
  ct_init( &att, &method, pG );
  lm_init( (pG->level != 0 ? pG->level : 1), &flags, pG );
  deflate( pG );
  pG->window_size = 0L; // was updated by lm_init()

  // For portability, force little-endian order on all machines:
  tgt[0] = ( char )( method & 0xFF );
  tgt[1] = ( char )( (method >> 8) & 0xFF );
  tgt[2] = ( char )( crc & 0xFF );
  tgt[3] = ( char )( (crc >> 8) & 0xFF );
  tgt[4] = ( char )( (crc >> 16) & 0xFF );
  tgt[5] = ( char )( (crc >> 24) & 0xFF );

  return ( ulg ) pG->out_offset;
}

// In-memory read function. As opposed to file_read(), this function does
//   not perform end-of-line translation, and does not update the crc and input
//   size. Note that the size of the entire input buffer is an unsigned long,
//   but the size used in mem_read() is only an unsigned int. This makes a
//   difference on 16 bit machines. mem_read() may be called several times for
//   an in-memory compression.
static int
mem_read(unsigned char *b, unsigned bsize, struct ZGlobals *pG )
{
  if ( pG->in_offset < pG->in_size )
  {
    ulg block_size = pG->in_size - pG->in_offset;
    if ( block_size > (ulg) bsize )
      block_size = ( ulg ) bsize;
    memcpy( b, pG->in_buf + pG->in_offset, ( unsigned )block_size );
    pG->in_offset += ( unsigned )block_size;
    return ( int )block_size;
  }

  return 0;             // end of input
}



