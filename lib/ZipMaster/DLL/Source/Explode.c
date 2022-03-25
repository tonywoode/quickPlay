
/* explode.c -- put in the public domain by Mark Adler
 * version c14, 22 November 1995
 * This version modified by Chris Vleghert and Eric W. Engler
 * for BCB/Delphi Zip, Jun 18, 2000.
 */

/* Explode imploded (PKZIP method 6 compressed) data.  This compression
 * method searches for as much of the current string of bytes (up to a length
 * of ~320) in the previous 4K or 8K bytes.  If it doesn't find any matches
 * (of at least length 2 or 3), it codes the next byte.  Otherwise, it codes
 * the length of the matched string and its distance backwards from the
 * current position.  Single bytes ("literals") are preceded by a one (a
 * single bit) and are either uncoded (the eight bits go directly into the
 * compressed stream for a total of nine bits) or Huffman coded with a
 * supplied literal code tree.  If literals are coded, then the minimum match
 * length is three, otherwise it is two.
 *
 * There are therefore four kinds of imploded streams: 8K search with coded
 * literals (min match = 3), 4K search with coded literals (min match = 3),
 * 8K with uncoded literals (min match = 2), and 4K with uncoded literals
 * (min match = 2).  The kind of stream is identified in two bits of a
 * general purpose bit flag that is outside of the compressed stream.
 *
 * Distance-length pairs for matched strings are preceded by a zero bit (to
 * distinguish them from literals) and are always coded.  The distance comes
 * first and is either the low six (4K) or low seven (8K) bits of the
 * distance (uncoded), followed by the high six bits of the distance coded.
 * Then the length is six bits coded (0..63 + min match length), and if the
 * maximum such length is coded, then it's followed by another eight bits
 * (uncoded) to be added to the coded length.  This gives a match length
 * range of 2..320 or 3..321 bytes.
 *
 * The literal, length, and distance codes are all represented in a slightly
 * compressed form themselves.  What is sent are the lengths of the codes for
 * each value, which is sufficient to construct the codes.  Each byte of the
 * code representation is the code length (the low four bits representing
 * 1..16), and the number of values sequentially with that length (the high
 * four bits also representing 1..16).  There are 256 literal code values (if
 * literals are coded), 64 length code values, and 64 distance code values,
 * in that order at the beginning of the compressed stream.  Each set of code
 * values is preceded (redundantly) with a byte indicating how many bytes are
 * in the code description that follows, in the range 1..256.
 *
 * The codes themselves are decoded using tables made by huft_build() from
 * the bit lengths.  That routine and its comments are in the inflate.c
 * module.
 */

#include "UnZip.h"              /* must supply slide[] (uch) array and NEXTBYTE macro */
#include "WinBase.h"

//EWE: WSIZE must be exactly 32K
#ifndef WSIZE
  #  define WSIZE 0x8000          /* window size--must be a power of two, and */
#endif /* at least 8K for zip's implode method */

#ifdef USE_STRM_OUTPUT
  #  define wsize pG->_wsize
#else
  #  define wsize WSIZE
#endif

/* routines here */
static int get_tree( struct UGlobals * pG, unsigned * l, unsigned n );
static int explode_lit8( struct UGlobals * pG, struct huft * tb, struct huft * tl, struct huft * td, int bb, int bl, int bd );
static int explode_lit4( struct UGlobals * pG, struct huft * tb, struct huft * tl, struct huft * td, int bb, int bl, int bd );
static int explode_nolit8( struct UGlobals * pG, struct huft * tl, struct huft * td, int bl, int bd );
static int explode_nolit4( struct UGlobals * pG, struct huft * tl, struct huft * td, int bl, int bd );
int explode( struct UGlobals * pG );

/* The implode algorithm uses a sliding 4K or 8K byte window on the
* uncompressed stream to find repeated byte strings.  This is implemented
* here as a circular buffer.  The index is updated simply by incrementing
* and then and'ing with 0x0fff (4K-1) or 0x1fff (8K-1).  Here, the 32K
* buffer of inflate is used, and it works just as well to always have
* a 32K circular buffer, so the index is anded with 0x7fff.  This is
* done to allow the window to also be used as the output buffer. */

/* This must be supplied in an external module useable like "uch slide[8192];"
* or "uch *slide;", where the latter would be malloc'ed.  In unzip, slide[]
* is actually a 32K area for use by inflate, which uses a 32K sliding window. */

/* Tables for length and distance */
static const ush cplen2[] =
  {
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
    35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58,
    59, 60, 61, 62, 63, 64, 65
  };
static const ush cplen3[] =
  {
    3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
    36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
    60, 61, 62, 63, 64, 65, 66
  };
static const ush extra[] =
  {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8
  };
static const ush cpdist4[] =
  {
    1, 65, 129, 193, 257, 321, 385, 449, 513, 577, 641, 705, 769, 833, 897, 961, 1025, 1089, 1153, 1217, 1281, 1345, 1409, 1473,
    1537, 1601, 1665, 1729, 1793, 1857, 1921, 1985, 2049, 2113, 2177, 2241, 2305, 2369, 2433, 2497, 2561, 2625, 2689, 2753,
    2817, 2881, 2945, 3009, 3073, 3137, 3201, 3265, 3329, 3393, 3457, 3521, 3585, 3649, 3713, 3777, 3841, 3905, 3969, 4033
  };
static const ush cpdist8[] =
  {
    1, 129, 257, 385, 513, 641, 769, 897, 1025, 1153, 1281, 1409, 1537, 1665, 1793, 1921, 2049, 2177, 2305, 2433, 2561, 2689,
    2817, 2945, 3073, 3201, 3329, 3457, 3585, 3713, 3841, 3969, 4097, 4225, 4353, 4481, 4609, 4737, 4865, 4993, 5121, 5249,
    5377, 5505, 5633, 5761, 5889, 6017, 6145, 6273, 6401, 6529, 6657, 6785, 6913, 7041, 7169, 7297, 7425,
    7553, 7681, 7809, 7937, 8065
  };

/* Macros for inflate() bit peeking and grabbing.
* The usage is:
*
*      NEEDBITS( j )
*      x = b & mask_bits[j];
*      DUMPBITS( j )
*
* where NEEDBITS makes sure that b has at least j bits in it, and
* DUMPBITS removes the bits from b.  The macros use the variable k
* for the number of bits in b.  Normally, b and k are register
* variables for speed. */
#define NEEDBITS( n ) {while( k < (n) ){b |= ((ulg)NEXTBYTE) << k;k += 8;}}
#define DUMPBITS( n ) {b >>= (n);k -= (n);}

#define NEXTBYTE  (--pG->incnt >= 0 ? (int)(*pG->inptr++) : readbyte( pG ))

/* ===========================================================================
* Get the bit lengths for a code representation from the compressed
* stream.  If get_tree() returns 4, then there is an error in the data. * Otherwise zero is returned.
*l :: Bit lengths. n :: Number expected. */
static int get_tree( struct UGlobals * pG, unsigned * l, unsigned n )
{
  unsigned i;
  /* bytes remaining in list */
  unsigned k;
  /* lengths entered */
  unsigned j;
  /* number of codes */
  unsigned b;
  /* bit length for those codes */

  /* get bit lengths */
  i = NEXTBYTE + 1;
  /* length/count pairs to read */
  k = 0;
  /* next code */
  do
  {
    b = ( ( j = NEXTBYTE ) & 0xf ) + 1;
    /* bits in code (1..16) */
    j = ( ( j & 0xf0 ) >> 4 ) + 1;
    /* codes with those bits (1..16) */
    if ( k + j > n )
      return 4;
    /* don't overflow l[] */
    do
    {
      l[k++] = b;
    }
    while ( --j );
  }
  while ( --i );
  return k != n ? 4 : 0;
  /* should have read n of them */
}


/* ===========================================================================
* Decompress the imploded data using coded literals and an 8K sliding *  window.
*tb, *tl, *td :: Literal, length, and distance tables. bb, bl, bd   :: Number of bits decoded by those */
static int explode_lit8( struct UGlobals * pG, struct huft * tb, struct huft * tl, struct huft * td, int bb, int bl, int bd )
{
  long s;
  /* bytes to decompress */
  register unsigned e;
  /* table entry flag/number of extra bits */
  unsigned n, d;
  /* length and index for copy */
  unsigned w;
  /* current window position */
  struct huft * t;
  /* pointer to table entry */
  unsigned mb, ml, md;
  /* masks for bb, bl, and bd bits */
  register ulg b;
  /* bit buffer */
  register unsigned k;
  /* number of bits in bit buffer */
  unsigned u;
  /* true if unflushed */

  /* explode the coded data */
  b = k = w = 0;
  /* initialize bit buffer, window */
  u = 1;
  /* buffer unflushed */
  mb = mask_bits[bb];
  /* precompute masks for speed */
  ml = mask_bits[bl];
  md = mask_bits[bd];
  s = pG->ucsize;
  while ( s > 0 )
  {
    /* do until ucsize bytes uncompressed */
    NEEDBITS( 1 )
    if ( b & 1 )
    {
      /* then literal--decode it */
      DUMPBITS( 1 ) s--;
      NEEDBITS( ( unsigned )bb ) /* get coded literal */
      if ( ( e = ( t = tb + ( ( ~( unsigned )b ) & mb ) )->e ) > 16 )
        do
        {
          if ( e == 99 )
            return 1;
          DUMPBITS( t->b ) e -= 16;
          NEEDBITS( e )
        }
        while ( ( e = ( t = t->v.t + ( ( ~( unsigned )b ) & mask_bits[e] ) )->e ) > 16 );
      DUMPBITS( t->b ) redirSlide[w++] = ( uch )t->v.n;
      if ( w == wsize )
      {
        flush( pG, redirSlide, w, 0 );
        w = u = 0;
      }
    }
    else
    {
      /* else distance/length */
      DUMPBITS( 1 ) NEEDBITS( 7 ) /* get distance low bits */
      d = ( unsigned )b & 0x7f;
      DUMPBITS( 7 ) NEEDBITS( ( unsigned )bd ) /* get coded distance high bits */
      if ( ( e = ( t = td + ( ( ~( unsigned )b ) & md ) )->e ) > 16 )
        do
        {
          if ( e == 99 )
            return 1;
          DUMPBITS( t->b ) e -= 16;
          NEEDBITS( e )
        }
        while ( ( e = ( t = t->v.t + ( ( ~( unsigned )b ) & mask_bits[e] ) )->e ) > 16 );
      DUMPBITS( t->b ) d = w - d - t->v.n;
      /* construct offset */
      NEEDBITS( ( unsigned )bl ) /* get coded length */
      if ( ( e = ( t = tl + ( ( ~( unsigned )b ) & ml ) )->e ) > 16 )
        do
        {
          if ( e == 99 )
            return 1;
          DUMPBITS( t->b ) e -= 16;
          NEEDBITS( e )
        }
        while ( ( e = ( t = t->v.t + ( ( ~( unsigned )b ) & mask_bits[e] ) )->e ) > 16 );
      DUMPBITS( t->b ) n = t->v.n;
      if ( e )
      {
        /* get length extra bits */
        NEEDBITS( 8 ) n += ( unsigned )b & 0xff;
        DUMPBITS( 8 )
      }
      /* do the copy */
      s -= n;
      do
      {
#                               ifdef USE_STRM_OUTPUT
        if ( pG->redirect_data ) /* &= w/ wsize not needed and wrong if redirect */
          n -= ( e = ( e = wsize - ( d > w ? d : w ) ) > n ? n : e );
        else
#                               endif

          n -= ( e = ( e = wsize - ( ( d &= wsize - 1 ) > w ? d : w ) ) > n ? n : e );
        if ( u && w <= d )
        {
          ZeroMemory( redirSlide + w, e );
          w += e;
          d += e;
        }
        else
#                               ifndef NOMEMCPY

          if ( w - d >= e )
          {
            /* (this test assumes unsigned comparison) */
            memcpy( redirSlide + w, redirSlide + d, e );
            w += e;
            d += e;
          }
          else /* do it slow to avoid memcpy() overlap */
#                               endif /* !NOMEMCPY */

            do
            {
              redirSlide[w++] = redirSlide[d++];
            }
            while ( --e );
        if ( w == wsize )
        {
          flush( pG, redirSlide, w, 0 );
          w = u = 0;
        }
      }
      while ( n );
    }
  }
  /* flush out redirSlide */
  flush( pG, redirSlide, w, 0 );
  /* should have read csize bytes, but */
  /* sometimes read one too many:  k >> 3 compensates */
  if ( pG->csize + pG->incnt + ( k >> 3 ) )
  {
    pG->used_csize = pG->lrec.csize - pG->csize - pG->incnt - ( k >> 3 );
    return 5;
  }
  return 0;
}


/* ===========================================================================
* Decompress the imploded data using coded literals and a 4K sliding * window.
*tb, *tl, *td :: Literal, length, and distance tables. bb, bl, bd   :: Number of bits decoded by those. */
static int explode_lit4( struct UGlobals * pG, struct huft * tb, struct huft * tl, struct huft * td, int bb, int bl, int bd )
{
  long s;
  /* bytes to decompress */
  register unsigned e;
  /* table entry flag/number of extra bits */
  unsigned n, d;
  /* length and index for copy */
  unsigned w;
  /* current window position */
  struct huft * t;
  /* pointer to table entry */
  unsigned mb, ml, md;
  /* masks for bb, bl, and bd bits */
  register ulg b;
  /* bit buffer */
  register unsigned k;
  /* number of bits in bit buffer */
  unsigned u;
  /* true if unflushed */

  /* explode the coded data */
  b = k = w = 0;
  /* initialize bit buffer, window */
  u = 1;
  /* buffer unflushed */
  mb = mask_bits[bb];
  /* precompute masks for speed */
  ml = mask_bits[bl];
  md = mask_bits[bd];
  s = pG->ucsize;
  while ( s > 0 )
  {
    /* do until ucsize bytes uncompressed */
    NEEDBITS( 1 )
    if ( b & 1 )
    {
      /* then literal--decode it */
      DUMPBITS( 1 ) s--;
      NEEDBITS( ( unsigned )bb ) /* get coded literal */
      if ( ( e = ( t = tb + ( ( ~( unsigned )b ) & mb ) )->e ) > 16 )
        do
        {
          if ( e == 99 )
            return 1;
          DUMPBITS( t->b ) e -= 16;
          NEEDBITS( e )
        }
        while ( ( e = ( t = t->v.t + ( ( ~( unsigned )b ) & mask_bits[e] ) )->e ) > 16 );
      DUMPBITS( t->b ) redirSlide[w++] = ( uch )t->v.n;
      if ( w == wsize )
      {
        flush( pG, redirSlide, w, 0 );
        w = u = 0;
      }
    }
    else
    {
      /* else distance/length */
      DUMPBITS( 1 ) NEEDBITS( 6 ) /* get distance low bits */
      d = ( unsigned )b & 0x3f;
      DUMPBITS( 6 ) NEEDBITS( ( unsigned )bd ) /* get coded distance high bits */
      if ( ( e = ( t = td + ( ( ~( unsigned )b ) & md ) )->e ) > 16 )
        do
        {
          if ( e == 99 )
            return 1;
          DUMPBITS( t->b ) e -= 16;
          NEEDBITS( e )
        }
        while ( ( e = ( t = t->v.t + ( ( ~( unsigned )b ) & mask_bits[e] ) )->e ) > 16 );
      DUMPBITS( t->b ) d = w - d - t->v.n;
      /* construct offset */
      NEEDBITS( ( unsigned )bl ) /* get coded length */
      if ( ( e = ( t = tl + ( ( ~( unsigned )b ) & ml ) )->e ) > 16 )
        do
        {
          if ( e == 99 )
            return 1;
          DUMPBITS( t->b ) e -= 16;
          NEEDBITS( e )
        }
        while ( ( e = ( t = t->v.t + ( ( ~( unsigned )b ) & mask_bits[e] ) )->e ) > 16 );
      DUMPBITS( t->b ) n = t->v.n;
      if ( e )
      {
        /* get length extra bits */
        NEEDBITS( 8 ) n += ( unsigned )b & 0xff;
        DUMPBITS( 8 )
      }
      /* do the copy */
      s -= n;
      do
      {
#                               ifdef USE_STRM_OUTPUT
        if ( pG->redirect_data ) /* &= w/ wsize not needed and wrong if redirect */
          n -= ( e = ( e = wsize - ( d > w ? d : w ) ) > n ? n : e );
        else
#                               endif

          n -= ( e = ( e = wsize - ( ( d &= wsize - 1 ) > w ? d : w ) ) > n ? n : e );
        if ( u && w <= d )
        {
          ZeroMemory( redirSlide + w, e );
          w += e;
          d += e;
        }
        else
#                               ifndef NOMEMCPY

          if ( w - d >= e )
          {
            /* (this test assumes unsigned comparison) */
            memcpy( redirSlide + w, redirSlide + d, e );
            w += e;
            d += e;
          }
          else /* do it slow to avoid memcpy() overlap */
#                               endif /* !NOMEMCPY */

            do
            {
              redirSlide[w++] = redirSlide[d++];
            }
            while ( --e );
        if ( w == wsize )
        {
          flush( pG, redirSlide, w, 0 );
          w = u = 0;
        }
      }
      while ( n );
    }
  }
  /* flush out redirSlide */
  flush( pG, redirSlide, w, 0 );
  /* should have read csize bytes, but */
  /* sometimes read one too many:  k>>3 compensates */
  if ( pG->csize + pG->incnt + ( k >> 3 ) )
  {
    pG->used_csize = pG->lrec.csize - pG->csize - pG->incnt - ( k >> 3 );
    return 5;
  }
  return 0;
}


/* ===========================================================================
* Decompress the imploded data using uncoded literals and an 8K sliding * window.
*tl, *td :: Length and distance decoder tables. bl, bd  :: Number of bits decoded by tl[] and td[]. */
static int explode_nolit8( struct UGlobals * pG, struct huft * tl, struct huft * td, int bl, int bd )
{
  long s;
  /* bytes to decompress */
  register unsigned e;
  /* table entry flag/number of extra bits */
  unsigned n, d;
  /* length and index for copy */
  unsigned w;
  /* current window position */
  struct huft * t;
  /* pointer to table entry */
  unsigned ml, md;
  /* masks for bl and bd bits */
  register ulg b;
  /* bit buffer */
  register unsigned k;
  /* number of bits in bit buffer */
  unsigned u;
  /* true if unflushed */

  /* explode the coded data */
  b = k = w = 0;
  /* initialize bit buffer, window */
  u = 1;
  /* buffer unflushed */
  ml = mask_bits[bl];
  /* precompute masks for speed */
  md = mask_bits[bd];
  s = pG->ucsize;
  while ( s > 0 )
  {
    /* do until ucsize bytes uncompressed */
    NEEDBITS( 1 )
    if ( b & 1 )
    {
      /* then literal--get eight bits */
      DUMPBITS( 1 ) s--;
      NEEDBITS( 8 ) redirSlide[w++] = ( uch )b;
      if ( w == wsize )
      {
        flush( pG, redirSlide, w, 0 );
        w = u = 0;
      }
      DUMPBITS( 8 )
    }
    else
    {
      /* else distance/length */
      DUMPBITS( 1 ) NEEDBITS( 7 ) /* get distance low bits */
      d = ( unsigned )b & 0x7f;
      DUMPBITS( 7 ) NEEDBITS( ( unsigned )bd ) /* get coded distance high bits */
      if ( ( e = ( t = td + ( ( ~( unsigned )b ) & md ) )->e ) > 16 )
        do
        {
          if ( e == 99 )
            return 1;
          DUMPBITS( t->b ) e -= 16;
          NEEDBITS( e )
        }
        while ( ( e = ( t = t->v.t + ( ( ~( unsigned )b ) & mask_bits[e] ) )->e ) > 16 );
      DUMPBITS( t->b ) d = w - d - t->v.n;
      /* construct offset */
      NEEDBITS( ( unsigned )bl ) /* get coded length */
      if ( ( e = ( t = tl + ( ( ~( unsigned )b ) & ml ) )->e ) > 16 )
        do
        {
          if ( e == 99 )
            return 1;
          DUMPBITS( t->b ) e -= 16;
          NEEDBITS( e )
        }
        while ( ( e = ( t = t->v.t + ( ( ~( unsigned )b ) & mask_bits[e] ) )->e ) > 16 );
      DUMPBITS( t->b ) n = t->v.n;
      if ( e )
      {
        /* get length extra bits */
        NEEDBITS( 8 ) n += ( unsigned )b & 0xff;
        DUMPBITS( 8 )
      }
      /* do the copy */
      s -= n;
      do
      {
#                               ifdef USE_STRM_OUTPUT
        if ( pG->redirect_data ) /* &= w/ wsize not needed and wrong if redirect */
          n -= ( e = ( e = wsize - ( d > w ? d : w ) ) > n ? n : e );
        else
#                               endif

          n -= ( e = ( e = wsize - ( ( d &= wsize - 1 ) > w ? d : w ) ) > n ? n : e );
        if ( u && w <= d )
        {
          ZeroMemory( redirSlide + w, e );
          w += e;
          d += e;
        }
        else
#                               ifndef NOMEMCPY

          if ( w - d >= e )
          {
            /* (this test assumes unsigned comparison) */
            memcpy( redirSlide + w, redirSlide + d, e );
            w += e;
            d += e;
          }
          else /* do it slow to avoid memcpy() overlap */
#                               endif /* !NOMEMCPY */

            do
            {
              redirSlide[w++] = redirSlide[d++];
            }
            while ( --e );
        if ( w == wsize )
        {
          flush( pG, redirSlide, w, 0 );
          w = u = 0;
        }
      }
      while ( n );
    }
  }
  /* flush out redirSlide */
  flush( pG, redirSlide, w, 0 );
  /* should have read csize bytes, but */
  /* sometimes read one too many:  k>>3 compensates */
  if ( pG->csize + pG->incnt + ( k >> 3 ) )
  {
    pG->used_csize = pG->lrec.csize - pG->csize - pG->incnt - ( k >> 3 );
    return 5;
  }
  return 0;
}


/* ===========================================================================
* Decompress the imploded data using uncoded literals and a 4K sliding * window.
*tl, *td :: Length and distance decoder tables. bl, bd  :: Number of bits decoded by tl[] and td[]. */
static int explode_nolit4( struct UGlobals * pG, struct huft * tl, struct huft * td, int bl, int bd )
{
  long s;
  /* bytes to decompress */
  register unsigned e;
  /* table entry flag/number of extra bits */
  unsigned n, d;
  /* length and index for copy */
  unsigned w;
  /* current window position */
  struct huft * t;
  /* pointer to table entry */
  unsigned ml, md;
  /* masks for bl and bd bits */
  register ulg b;
  /* bit buffer */
  register unsigned k;
  /* number of bits in bit buffer */
  unsigned u;
  /* true if unflushed */

  /* explode the coded data */
  b = k = w = 0;
  /* initialize bit buffer, window */
  u = 1;
  /* buffer unflushed */
  ml = mask_bits[bl];
  /* precompute masks for speed */
  md = mask_bits[bd];
  s = pG->ucsize;
  while ( s > 0 )
  {
    /* do until ucsize bytes uncompressed */
    NEEDBITS( 1 )
    if ( b & 1 )
    {
      /* then literal--get eight bits */
      DUMPBITS( 1 ) s--;
      NEEDBITS( 8 ) redirSlide[w++] = ( uch )b;
      if ( w == wsize )
      {
        flush( pG, redirSlide, w, 0 );
        w = u = 0;
      }
      DUMPBITS( 8 )
    }
    else
    {
      /* else distance/length */
      DUMPBITS( 1 ) NEEDBITS( 6 ) /* get distance low bits */
      d = ( unsigned )b & 0x3f;
      DUMPBITS( 6 ) NEEDBITS( ( unsigned )bd ) /* get coded distance high bits */
      if ( ( e = ( t = td + ( ( ~( unsigned )b ) & md ) )->e ) > 16 )
        do
        {
          if ( e == 99 )
            return 1;
          DUMPBITS( t->b ) e -= 16;
          NEEDBITS( e )
        }
        while ( ( e = ( t = t->v.t + ( ( ~( unsigned )b ) & mask_bits[e] ) )->e ) > 16 );
      DUMPBITS( t->b ) d = w - d - t->v.n;
      /* construct offset */
      NEEDBITS( ( unsigned )bl ) /* get coded length */
      if ( ( e = ( t = tl + ( ( ~( unsigned )b ) & ml ) )->e ) > 16 )
        do
        {
          if ( e == 99 )
            return 1;
          DUMPBITS( t->b ) e -= 16;
          NEEDBITS( e )
        }
        while ( ( e = ( t = t->v.t + ( ( ~( unsigned )b ) & mask_bits[e] ) )->e ) > 16 );
      DUMPBITS( t->b ) n = t->v.n;
      if ( e )
      {
        /* get length extra bits */
        NEEDBITS( 8 ) n += ( unsigned )b & 0xff;
        DUMPBITS( 8 )
      }
      /* do the copy */
      s -= n;
      do
      {
#                               ifdef USE_STRM_OUTPUT
        if ( pG->redirect_data ) /* &= w/ wsize not needed and wrong if redirect */
          n -= ( e = ( e = wsize - ( d > w ? d : w ) ) > n ? n : e );
        else
#                               endif

          n -= ( e = ( e = wsize - ( ( d &= wsize - 1 ) > w ? d : w ) ) > n ? n : e );
        if ( u && w <= d )
        {
          ZeroMemory( redirSlide + w, e );
          w += e;
          d += e;
        }
        else
#                               ifndef NOMEMCPY

          if ( w - d >= e )
          {
            /* (this test assumes unsigned comparison) */
            memcpy( redirSlide + w, redirSlide + d, e );
            w += e;
            d += e;
          }
          else /* do it slow to avoid memcpy() overlap */
#                               endif /* !NOMEMCPY */

            do
            {
              redirSlide[w++] = redirSlide[d++];
            }
            while ( --e );
        if ( w == wsize )
        {
          flush( pG, redirSlide, w, 0 );
          w = u = 0;
        }
      }
      while ( n );
    }
  }
  /* flush out redirSlide */
  flush( pG, redirSlide, w, 0 );
  /* should have read csize bytes, but */
  /* sometimes read one too many:  k >> 3 compensates */
  if ( pG->csize + pG->incnt + ( k >> 3 ) )
  {
    pG->used_csize = pG->lrec.csize - pG->csize - pG->incnt - ( k >> 3 );
    return 5;
  }
  return 0;
}


/* ===========================================================================
* Explode an imploded compressed stream.  Based on the general purpose
* bit flag, decide on coded or uncoded literals, and an 8K or 4K sliding
* window.  Construct the literal (if any), length, and distance codes and
* the tables needed to decode them (using huft_build() from inflate.c),
* and call the appropriate routine for the type of data in the remainder
* of the stream.  The four routines are nearly identical, differing only
* in whether the literal is decoded or simply read in, and in how many
* bits are read in, uncoded, for the low distance bits. */
int explode( struct UGlobals * pG )
{
  unsigned r;
  /* return codes */
  struct huft * tb;
  /* literal code table */
  struct huft * tl;
  /* length code table */
  struct huft * td;
  /* distance code table */
  int bb;
  /* bits for tb */
  int bl;
  /* bits for tl */
  int bd;
  /* bits for td */
  unsigned l[256];
  /* bit lengths for codes */

#       ifdef USE_STRM_OUTPUT

  if ( pG->redirect_data )
    wsize = pG->redirect_size, redirSlide = pG->redirect_buffer;
  else
    wsize = WSIZE, redirSlide = slide;
#       endif

  /* Tune base table sizes.  Note: I thought that to truly optimize speed,
  * I would have to select different bl, bd, and bb values for different
  * compressed file sizes.  I was suprised to find out the the values of
  * 7, 7, and 9 worked best over a very wide range of sizes, except that
  * bd = 8 worked marginally better for large compressed sizes. */
  bl = 7;
//  bd = ( pG->csize + pG->incnt ) > 200000L ? 8 : 7;
  bd = (unsigned long)( pG->csize + pG->incnt ) > 200000L ? 8 : 7;

  /* With literal tree--minimum match length is 3 */
  pG->hufts = 0;
  /* initialize huft's malloc'ed */
  if ( pG->lrec.general_purpose_bit_flag & 4 )
  {
    bb = 9;
    /* base table size for literals */
    if ( ( r = get_tree( pG, l, 256 ) ) != 0 )
      return ( int )r;
    if ( ( r = huft_build( pG, l, 256, 256, NULL, NULL, & tb, & bb ) ) != 0 )
    {
      if ( r == 1 )
        huft_free( tb );
      return ( int )r;
    }
    if ( ( r = get_tree( pG, l, 64 ) ) != 0 )
      return ( int )r;
    if ( ( r = huft_build( pG, l, 64, 0, cplen3, extra, & tl, & bl ) ) != 0 )
    {
      if ( r == 1 )
        huft_free( tl );
      huft_free( tb );
      return ( int )r;
    }
    if ( ( r = get_tree( pG, l, 64 ) ) != 0 )
      return ( int )r;
    if ( pG->lrec.general_purpose_bit_flag & 2 )
    {
      /* true if 8K */
      if ( ( r = huft_build( pG, l, 64, 0, cpdist8, extra, & td, & bd ) ) != 0 )
      {
        if ( r == 1 )
          huft_free( td );
        huft_free( tl );
        huft_free( tb );
        return ( int )r;
      }
      r = explode_lit8( pG, tb, tl, td, bb, bl, bd );
    }
    else
    {
      /* else 4K */
      if ( ( r = huft_build( pG, l, 64, 0, cpdist4, extra, & td, & bd ) ) != 0 )
      {
        if ( r == 1 )
          huft_free( td );
        huft_free( tl );
        huft_free( tb );
        return ( int )r;
      }
      r = explode_lit4( pG, tb, tl, td, bb, bl, bd );
    }
    huft_free( td );
    huft_free( tl );
    huft_free( tb );
  }
  else
  {
    /* No literal tree--minimum match length is 2 */
    if ( ( r = get_tree( pG, l, 64 ) ) != 0 )
      return ( int )r;
    if ( ( r = huft_build( pG, l, 64, 0, cplen2, extra, & tl, & bl ) ) != 0 )
    {
      if ( r == 1 )
        huft_free( tl );
      return ( int )r;
    }
    if ( ( r = get_tree( pG, l, 64 ) ) != 0 )
      return ( int )r;
    if ( pG->lrec.general_purpose_bit_flag & 2 )
    {
      /* true if 8K */
      if ( ( r = huft_build( pG, l, 64, 0, cpdist8, extra, & td, & bd ) ) != 0 )
      {
        if ( r == 1 )
          huft_free( td );
        huft_free( tl );
        return ( int )r;
      }
      r = explode_nolit8( pG, tl, td, bl, bd );
    }
    else
    {
      /* else 4K */
      if ( ( r = huft_build( pG, l, 64, 0, cpdist4, extra, & td, & bd ) ) != 0 )
      {
        if ( r == 1 )
          huft_free( td );
        huft_free( tl );
        return ( int )r;
      }
      r = explode_nolit4( pG, tl, td, bl, bd );
    }
    huft_free( td );
    huft_free( tl );
  }
  return ( int )r;
}

/* so explode.c and inflate.c can be compiled together into one object: */
#undef NEXTBYTE
#undef NEEDBITS
#undef DUMPBITS
