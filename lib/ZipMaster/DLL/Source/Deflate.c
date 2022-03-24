#include <windows.h>
#include "Common.h"
#pragma hdrstop
#include "Zip.h" 
#include "ZipErr.h"

/* Deflate.c
* Copyright (C) 1990-1996 Mark Adler, Richard B. Wales, Jean-loup Gailly,
* Kai Uwe Rommel, Onno van der Linden and Igor Mandrichenko.
* This version modified by Chris Vleghert and Eric Engler for BCB/Delphi Zip.
** distributed under LGPL license ** see license.txt for details
*/
/*  PURPOSE
*      Identify new text as repetitions of old text within a fixed-
*      length sliding window trailing behind the new text.
**  DISCUSSION
*      The "deflation" process depends on being able to identify portions
*      of the input text which are identical to earlier input (within a
*      sliding window trailing behind the input currently being processed).
*
*      The most straightforward technique turns out to be the fastest for
*      most input files: try all possible matches and select the longest.
*      The key feature of this algorithm is that insertions into the string
*      dictionary are very simple and thus fast, and deletions are avoided
*      completely. Insertions are performed at each input character, whereas
*      string matches are performed only when the previous match ends. So it
*      is preferable to spend more time in matches to allow very fast string
*      insertions and avoid deletions. The matching algorithm for small
*      strings is inspired from that of Rabin & Karp. A brute force approach
*      is used to find longer strings when a small match has been found.
*      A similar algorithm is used in comic (by Jan-Mark Wams) and freeze
*      (by Leonid Broukhis).
*         A previous version of this file used a more sophisticated algorithm
*      (by Fiala and Greene) which is guaranteed to run in linear amortized
*      time, but has a larger average cost, uses more memory and is patented.
*      However the F&G algorithm may be faster for some highly redundant
*      files if the parameter max_chain_length (described below) is too large.
 *
 *  ACKNOWLEDGEMENTS
*      The idea of lazy evaluation of matches is due to Jan-Mark Wams, and
*      I found it in 'freeze' written by Leonid Broukhis.
*      Thanks to many info-zippers for bug reports and testing.
*
*  REFERENCES
*      APPNOTE.TXT documentation file in PKZIP 1.93a distribution.
*
*      A description of the Rabin and Karp algorithm is given in the book
*         "Algorithms" by R. Sedgewick, Addison-Wesley, p252.
*
*      Fiala,E.R., and Greene,D.H.
*         Data Compression with Finite Windows, Comm.ACM, 32,4 (1989) 490-595
*
*  INTERFACE
*      void lm_init (int pack_level, ush *flags)
 *          Initialize the "longest match" routines for a new file
 *
*      ulg deflate (void)
*          Processes a new input file and return its compressed length. Sets
*          the compressed length, crc, deflate flags and internal file
 *          attributes.
 */
//#include "Zip.h"
//#include "ZGlobals.h"
// Configuration parameters
// Compile with HASH_BITS = 14 to reduce the memory requirements or with
//   HASH_BITS = 13 to use as little memory as possible. Otherwise if the
//   entire input file can be held in memory (not possible on 16 bit systems).
//   Warning: defining this symbol affects the compression ratio. The
//   compressed output is still correct, and might even be smaller in some
//   cases. For portability to 16 bit machines, do not use values above 15.
#ifndef HASH_BITS
  #define HASH_BITS 15  // Number of bits used to hash strings
#endif

//#define HASH_SIZE ( unsigned )( 1 << HASH_BITS )
//#define HASH_MASK ( HASH_SIZE - 1 )
//#define WMASK     ( WSIZE - 1 )
// HASH_SIZE and WSIZE must be powers of two
#define NIL 0

// Tail of hash chains
#define FAST  4
#define SLOW  2

// speed options for the general purpose bit flag
#ifndef TOO_FAR
  #define TOO_FAR 4096
#endif

// Matches of length 3 are discarded if their distance exceeds TOO_FAR
// Local data used by the "longest match" routines.
typedef ush Pos;
//typedef unsigned IPos;



// A Pos is an index in the character window. We use short instead of int to
//   save space in the various tables. unsigned is used only for parameter passing.
#define H_SHIFT ( (HASH_BITS + MIN_MATCH - 1) / MIN_MATCH )

// Number of bits by which ins_h and del_h must be shifted at each input
//   step. It must be such that after MIN_MATCH steps, the oldest byte no
//   longer takes part in the hash key, that is: H_SHIFT * MIN_MATCH >=
//   HASH_BITS
#define max_insert_length pG->max_lazy_match

// Insert new strings in the hash table only if the match length is not
//   greater than this length. This saves time but degrades compression.
//   max_insert_length is used only for compression levels <= 3.
// Values for max_lazy_match, good_match and max_chain_length, depending on
//   the desired pack level (0..9). The values given below have been tuned to
//   exclude worst case performance for pathological files. Better values may
//   be found for specific files.
typedef struct config
{
  ush good_length; // reduce lazy search above this match length
  ush max_lazy; // do not perform lazy search above this match length
  ush nice_length; // quit search above this match length
  ush max_chain;
}

config;



#ifdef FULL_SEARCH
  #define nice_match  MAX_MATCH
#endif
static config configuration_table[10] =
  {
    // good lazy nice chain
    // 0
    { 0, 0, 0, 0 },

    // store only
    // 1
    { 4, 4, 8, 4 },
    // maximum speed, no lazy matches
    // 2
    { 4, 5, 16, 8 },
    // 3
    { 4, 6, 32, 32 },
    // 4
    { 4, 4, 16, 16 },
    // lazy matches
    // 5
    { 8, 16, 32, 32 },
    // 6
    { 8, 16, 128, 128 },
    // 7
    { 8, 32, 128, 256 },
    // 8
    { 32, 128, 258, 1024 },
    // 9
    { 32, 258, 258, 4096 }
  }; // maximum compression

// Note: the deflate() code requires max_lazy >= MIN_MATCH and max_chain >=
//   4 For deflate_fast() (levels <= 3) good is ignored and lazy has a
//   different meaning.
#define EQUAL 0

// result of memcmp for equal strings
// Prototypes for local functions.
static void fill_window( struct ZGlobals * pG );
static ulg deflate_fast( struct ZGlobals * pG );

//extern int __fastcall longest_match( unsigned cur_match, struct ZGlobals * pG );

#ifdef DEBUG
static void check_match( unsigned start, unsigned match, int length, struct ZGlobals * pG );
#endif

// Update a hash value with the given input byte IN assertion: all calls to
//   to UPDATE_HASH are made with consecutive input characters, so that a
//   running hash key can be computed from the previous key instead of complete
//   recalculation each time.
#define UPDATE_HASH( h, c ) ( h = (((h) << H_SHIFT) ^ (c)) & HASH_MASK )

// Insert string s in the dictionary and set match_head to the previous head
//   of the hash chain (the most recent string with same hash key). Return the
//   previous length of the hash chain. IN assertion: all calls to to
//   INSERT_STRING are made with consecutive input characters and the first
//   MIN_MATCH bytes of s are valid (except for the last MIN_MATCH-1 bytes of
//   the input file).
#define INSERT_STRING( s, match_head )                                                 \
     (                                                                                  \
     UPDATE_HASH( pG->ins_h, pG->window[(s) + (MIN_MATCH - 1)] ), pG->prev[           \
     (s) & WMASK] = (ush) (match_head = pG->head[pG->ins_h]), pG->head[pG->ins_h] = \
     (ush) (s)                                                                    \
     )                                                                                  \
     \

// RCV Added 2x (ush)
// Initialize the "longest match" routines for a new file IN assertion:
//   window_size is > 0 if the input file is already read or mmap'ed in the
//   window[] array, 0 otherwise. In the first case, window_size is sufficient
//   to contain the whole input file plus MIN_LOOKAHEAD bytes (to avoid
//   referencing memory beyond the end of window[] when looking for matches
//   towards the end). pack_level :: 0: store, 1: best speed, 9: best
//   compression. flags :: General purpose bit flag.
void lm_init( int pack_level, ush * flags, struct ZGlobals * pG )
{
  register unsigned j;

  if ( pack_level < 1 || pack_level > 9 )
    ziperr( ZEN_LOGIC03, pG );

  // Do not slide the window if the whole input is already in memory
  //   (window_size > 0)
  pG->sliding = 0;
  if ( pG->window_size == 0L )
  {
    pG->sliding = 1;
    pG->window_size = ( ulg )2L * WSIZE;
  }

  // Use dynamic allocation if compiler does not like big static arrays:
#ifdef DYN_ALLOC
  if ( pG->window == NULL )
  {
    pG->window = ( uch * ) zcalloc( WSIZE, 2 * sizeof( uch ) );
    if ( pG->window == NULL )
      ziperr( ZEN_MEM02, pG );
  }

  if ( pG->prev == NULL )
  {
    pG->prev = ( Pos * ) zcalloc( WSIZE, sizeof( Pos ) );
    pG->head = ( Pos * ) zcalloc( HASH_SIZE, sizeof( Pos ) );
    if ( pG->prev == NULL || pG->head == NULL )
      ziperr( ZEN_MEM03, pG );
  }

#endif // DYN_ALLOC

  // Initialize the hash table (avoiding 64K overflow for 16 bit systems).
  //   prev[] will be initialized on the fly.
  pG->head[HASH_SIZE - 1] = NIL;
  memset( ( char * ) pG->head, NIL, ( unsigned )( HASH_SIZE - 1 ) * sizeof( * pG->head ) );

  // Set the default configuration parameters:
  pG->max_lazy_match = configuration_table[pack_level].max_lazy;
  pG->good_match = configuration_table[pack_level].good_length;
#ifndef FULL_SEARCH

  pG->nice_match = configuration_table[pack_level].nice_length;
#endif

  pG->max_chain_length = configuration_table[pack_level].max_chain;
  if ( pack_level <= 2 )
  {
    * flags |= FAST;
  }
  else
    if ( pack_level >= 8 )
    {
      * flags |= SLOW;
    }

  // ??? reduce max_chain_length for binary files
  pG->strstart = 0;
  pG->block_start = 0L;

  j = WSIZE;
  j <<= 1; // We Can read 64K in one step.
  pG->lookahead = ( * pG->read_buf ) ( (uch * ) pG->window, j, pG );

  if ( pG->lookahead == 0 || pG->lookahead == ( unsigned )EOF )
  {
    pG->eofile = 1, pG->lookahead = 0;
    return;
  }

  pG->eofile = 0;

  // Make sure that we always have enough lookahead. This is important if
  //   input comes from a device such as a tty.
  if ( pG->lookahead < MIN_LOOKAHEAD )
    fill_window( pG );

  pG->ins_h = 0;
  for ( j = 0; j < MIN_MATCH - 1; j++ )
    UPDATE_HASH( pG->ins_h, pG->window[j] );

  // If lookahead < MIN_MATCH, ins_h is garbage, but this is not important
  //   since only literal bytes will be emitted.
}

// Free the window and hash table
#ifdef DYN_ALLOC
void lm_free( struct ZGlobals * pG )
{
  if ( pG->window != NULL )
  {
    zcfree( pG->window );
    pG->window = NULL;
  }

  if ( pG->prev != NULL )
  {
    zcfree( pG->prev );
    zcfree( pG->head );
    pG->prev = pG->head = NULL;
  }
}

#endif

// Set match_start to the longest match starting at the given string and
//   return its length. Matches shorter or equal to prev_length are discarded,
//   in which case the result is equal to prev_length and match_start is
//   garbage. IN assertions: cur_match is the head of the hash chain for the
//   current string (strstart) and its distance is <= MAX_DIST, and prev_length
//   >= 1
// For 80x86 and 680x0 and ARM, an optimized version is in match.asm or
//   match.S. The code is functionally equivalent, so you can use the C version
//   if desired. cur_match :: Current match.
#if 0
int __fastcall longest_match( unsigned cur_match, struct ZGlobals * pG )
{
  unsigned chain_length = pG->max_chain_length; // max hash chain length
  register uch * scan = pG->window + pG->strstart; // current string
  register uch * match; // matched string
  register int len; // length of current match
  int best_len = pG->prev_length; // best match length so
  ///* far
  unsigned limit = pG->strstart > ( unsigned )MAX_DIST ? pG->strstart - ( unsigned )MAX_DIST : NIL;

  // Stop when cur_match becomes <= limit. To simplify the code, we prevent
  //   matches with the string of window index 0.
  // The code is optimized for HASH_BITS >= 8 and MAX_MATCH-2 multiple of
  //   16. It is easy to get rid of this optimization if necessary.
#if HASH_BITS < 8 || MAX_MATCH != 258
error:
  Code too clever
#endif
  register uch * strend = pG->window + pG->strstart + MAX_MATCH;

  register uch scan_end1 = scan[best_len - 1];
  register uch scan_end = scan[best_len];

  // Do not waste too much time if we already have a good match:
  if ( pG->prev_length >= pG->good_match )
    chain_length >>= 2;
  Assert( pG->strstart <= pG->window_size - MIN_LOOKAHEAD, "insufficient lookahead" );

  do
  {
    Assert( cur_match < pG->strstart, "no future" );
    match = pG->window + cur_match;

    // Skip to next match if the match length cannot increase or if the
    //   match length is less than 2:
    if ( match[best_len] != scan_end
         || match[best_len - 1] != scan_end1
         || *match != *scan
         || *++match != scan[1] )
      continue;

    // The check at best_len-1 can be removed because it will be made again
    //   later. (This heuristic is not always a win.) It is not necessary to
    //   compare scan[2] and match[2] since they are always equal when the
    //   other bytes match, given that the hash keys are equal and that
    //   HASH_BITS >= 8.
    scan += 2, match++;

    // We check for insufficient lookahead only every 8th comparison; the
    //   256th check will be made at strstart+258.
    do
    {}
    while
    (
      *++scan == * ++match
      && *++scan == * ++match
      && *++scan == * ++match
      && *++scan == * ++match
      && *++scan == * ++match
      && *++scan == * ++match
      && *++scan == * ++match
      && *++scan == * ++match
      && scan < strend
    );

    Assert( scan <= pG->window + ( unsigned )( pG->window_size - 1 ), "wild scan" );

    len = MAX_MATCH - ( int )( strend - scan );
    scan = strend - MAX_MATCH;

    if ( len > best_len )
    {
      pG->match_start = cur_match;
      best_len = len;
      if ( len >= pG->nice_match )
        break;
      scan_end1 = scan[best_len - 1];
      scan_end = scan[best_len];
    }
  }
  while ( ( cur_match = pG->prev[cur_match & WMASK] ) > limit && --chain_length != 0 );

  return best_len;
}

#endif
#ifdef _DEBUG
// Check that the match at match_start is indeed a match.
static void check_match( unsigned start, unsigned match, int length, struct ZGlobals * pG )
{
  // check that the match is indeed a match
  if ( memcmp( ( char * )pG->window + match, ( char * )pG->window + start, length ) != EQUAL )
  {
    Notify( PF, -1 | IERROR, "invalid match - start %d, match %d, length %d", start, match, length );
  }
}

#else
  #define check_match( start, match, length, global )
#endif

// Fill the window when the lookahead becomes insufficient. Updates strstart
//   and lookahead, and sets eofile if end of input file. IN assertion:
//   lookahead < MIN_LOOKAHEAD &
//   &
//   strstart + lookahead > 0 OUT assertions: strstart <=
//   window_size-MIN_LOOKAHEAD At least one byte has been read, or eofile is
//   set; file reads are performed for at least two bytes (required for the
//   translate_eol option).
static void fill_window( struct ZGlobals * pG )
{
  register unsigned n, m;
  unsigned more; // Amount of free space
  ///* at the end of the
  ///* window.
  do
  {
    more = ( unsigned )( pG->window_size - ( ulg )pG->lookahead - ( ulg )pG->strstart );

    // If the window is almost full and there is insufficient lookahead,
    //   move the upper half to the lower one to make room in the upper half.
    if ( more == ( unsigned )EOF )
    {
      // Very unlikely, but possible on 16 bit machine if strstart == 0 and
      //   lookahead == 1 (input done one byte at time)
      more--;

      // For MMAP or BIG_MEM, the whole input file is already in memory so
      //   we must not perform sliding. We must however call file_read in order
      //   to compute the crc, update lookahead and possibly set eofile.
    }
    else
      if ( pG->strstart >= WSIZE + MAX_DIST && pG->sliding )
      {
        // By the IN assertion, the window is not empty so we can't confuse
        //   more == 0 with more == 64K on a 16 bit machine.
        memcpy( ( char * ) pG->window, ( char * ) pG->window + WSIZE, ( unsigned )WSIZE );
        pG->match_start -= WSIZE;
        pG->strstart -= WSIZE; // we now have strstart
        ///* >= MAX_DIST:
        pG->block_start -= ( long )WSIZE;

        for ( n = 0; n < HASH_SIZE; n++ )
        {
          m = pG->head[n];
          pG->head[n] = ( Pos )( m >= WSIZE ? m - WSIZE : NIL );
        }

        for ( n = 0; n < WSIZE; n++ )
        {
          m = pG->prev[n];
          pG->prev[n] = ( Pos )( m >= WSIZE ? m - WSIZE : NIL );

          // If n is not on any hash chain, prev[n] is garbage but its value
          //   will never be used.
        }

        more += WSIZE;

        if ( pG->Frame.Abort_Flag )
          return; // UPDATE: the ziperr()
        ///* func in dllzip.c
        ///* closes file.
      }

    if ( pG->eofile )
      return;

    // If there was no sliding: strstart <= WSIZE+MAX_DIST - 1 &
    //   &
    //   lookahead <= MIN_LOOKAHEAD - 1 &
    //   &
    //   more == window_size - lookahead - strstart => more >= window_size -
    //   (MIN_LOOKAHEAD - 1 + WSIZE + MAX_DIST - 1) => more >= window_size - 2
    //   * WSIZE + 2 In the BIG_MEM or MMAP case (not yet supported in gzip),
    //   window_size == input_size + MIN_LOOKAHEAD &
    //   &
    //   strstart + lookahead <= input_size => more >= MIN_LOOKAHEAD.
    //   Otherwise, window_size == 2 * WSIZE so more >= 2. If there was
    //   sliding, more >= WSIZE. So in all cases, more >= 2.
    Assert( more >= 2, "more < 2" );

    n = ( * pG->read_buf ) ( (uch * ) pG->window + pG->strstart + pG->lookahead, more, pG );
    if ( n == 0 || n == ( unsigned )EOF )
    {
      pG->eofile = 1;
    }
    else
    {
      pG->lookahead += n;
    }
  }
  while ( pG->lookahead < MIN_LOOKAHEAD && !pG->eofile );
}

// Flush the current block, with given end-of-file flag. IN assertion:
//   strstart is set to the end of the current match.
#define FLUSH_BLOCK( eof )                                                                   \
     flush_block( pG->block_start >= 0L ? ( char * ) &pG->window[( unsigned )pG->block_start] : \
     ( char * )NULL, ( long )pG->strstart - pG->block_start, (eof), pG )

// Processes a new input file and return its compressed length. This
//   function does not perform lazy evaluationof matches and inserts new
//   strings in the dictionary only for unmatched strings or for short matches.
//   It is used only for the fast compression options.
static ulg deflate_fast( struct ZGlobals * pG )
{
  unsigned hash_head; // head of the hash chain
  int flush; // set if current block must be flushed
  unsigned match_length = 0; // length of best match
  pG->prev_length = MIN_MATCH - 1;
  while ( pG->lookahead != 0 )
  {
    // Insert the string window[strstart .. strstart+2] in the dictionary,
    //   and set hash_head to the head of the hash chain:
    INSERT_STRING( pG->strstart, hash_head );

    // Find the longest match, discarding those <= prev_length. At this
    //   point we have always match_length < MIN_MATCH
    if ( hash_head != NIL && pG->strstart - hash_head <= MAX_DIST )
    {
      // To simplify the code, we prevent matches with the string of window
      //   index 0 (in particular we have to avoid a match of the string with
      //   itself at the start of the input file).
#ifndef HUFFMAN_ONLY
      match_length = longest_match( hash_head, pG );
#endif
      // longest_match() sets match_start
      if ( match_length > pG->lookahead )
        match_length = pG->lookahead;
    }

    if ( match_length >= MIN_MATCH )
    {
#ifdef _DEBUG
      check_match( pG->strstart, pG->match_start, match_length, pG );
#endif
      flush = ct_tally( pG->strstart - pG->match_start, match_length - MIN_MATCH, pG );

      pG->lookahead -= match_length;

      // Insert new strings in the hash table only if the match length is
      //   not too large. This saves time but degrades compression.
      if ( match_length <= max_insert_length )
      {
        match_length--; // string at strstart already in hash table
        do
        {
          pG->strstart++;
          INSERT_STRING( pG->strstart, hash_head );

          // strstart never exceeds WSIZE-MAX_MATCH, so there are always
          //   MIN_MATCH bytes ahead. If lookahead < MIN_MATCH these bytes are
          //   garbage, but it does not matter since the next lookahead bytes
          //   will be emitted as literals.
        }
        while ( --match_length != 0 );
        pG->strstart++;
      }
      else
      {
        pG->strstart += match_length;
        match_length = 0;
        pG->ins_h = pG->window[pG->strstart];
        UPDATE_HASH( pG->ins_h, pG->window[pG->strstart + 1] );
#if MIN_MATCH != 3
        Call UPDATE_HASH() MIN_MATCH - 3 more times
#endif
      }
    }
    else
    {
      // No match, output a literal byte
      Tracevv( ( "%c"), (pG->window[pG->strstart] ) );
      flush = ct_tally( 0, pG->window[pG->strstart], pG );
      pG->lookahead--;
      pG->strstart++;
    }

    if ( flush )
      FLUSH_BLOCK( 0 ), pG->block_start = pG->strstart;

    // Make sure that we always have enough lookahead, except at the end of
    //   the input file. We need MAX_MATCH bytes for the next match, plus
    //   MIN_MATCH bytes to insert the string following the next match.
    if ( pG->lookahead < MIN_LOOKAHEAD )
      fill_window( pG );
    if ( pG->Frame.Abort_Flag )
    {
      // the ziperr() func in dllzip.c closes file.
      return ZEN_ABORT;
    }
  }

  return FLUSH_BLOCK( 1 ); // eof
}

// Same as above, but achieves better compression. We use a lazy evaluation
//   for matches: a match is finally adopted only if there is no better match
//   at the next window position.
ulg deflate( struct ZGlobals * pG )
{
  unsigned hash_head; // head of hash chain
  unsigned prev_match; // previous match
  int flush; // set if current block
  ///* must be flushed
  int match_available = 0; // set if previous match
  ///* exists
  register unsigned match_length = MIN_MATCH - 1; // length of best match
  if ( pG->level <= 3 )
    return deflate_fast( pG ); // optimized for speed

  // Process the input block.
  while ( pG->lookahead != 0 )
  {
    // Insert the string window[strstart .. strstart+2] in the dictionary,
    //   and set hash_head to the head of the hash chain:
    INSERT_STRING( pG->strstart, hash_head );

    // Find the longest match, discarding those <= prev_length.
    pG->prev_length = match_length, prev_match = pG->match_start;
    match_length = MIN_MATCH - 1;

    if ( hash_head != NIL && pG->prev_length < pG->max_lazy_match
         && pG->strstart - hash_head <= MAX_DIST )
    {
      // To simplify the code, we prevent matches with the string of window
      //   index 0 (in particular we have to avoid a match of the string with
      //   itself at the start of the input file).
#ifndef HUFFMAN_ONLY
      match_length = longest_match( hash_head, pG );
#endif

      // longest_match() sets match_start
      if ( match_length > pG->lookahead )
        match_length = pG->lookahead;
      /*
      #ifdef FILTERED
            // Ignore matches of length <= 5
            if ( match_length <= 5 )
            {
      #else   */
      // Ignore a length 3 match if it is too distant:
      if (
#ifdef FILTERED
        match_length <= 5 &&
#endif
        match_length == MIN_MATCH && pG->strstart - pG->match_start > TOO_FAR )
      {
        //#endif

        // If prev_match is also MIN_MATCH, match_start is garbage but we
        //   will ignore the current match anyway.
        match_length = MIN_MATCH - 1;
      }
    }

    // If there was a match at the previous step and the current match is
    //   not better, output the previous match:
    if ( pG->prev_length >= MIN_MATCH && match_length <= pG->prev_length )
    {
#ifdef _DEBUG
      check_match( pG->strstart - 1, prev_match, pG->prev_length, pG );
#endif

      flush = ct_tally( pG->strstart - 1 - prev_match, pG->prev_length - MIN_MATCH, pG );

      // Insert in hash table all strings up to the end of the match.
      //   strstart-1 and strstart are already inserted.
      pG->lookahead -= pG->prev_length - 1;
      pG->prev_length -= 2;
      do
      {
        pG->strstart++;
        INSERT_STRING( pG->strstart, hash_head );

        // strstart never exceeds WSIZE-MAX_MATCH, so there are always
        //   MIN_MATCH bytes ahead. If lookahead < MIN_MATCH these bytes are
        //   garbage, but it does not matter since the next lookahead bytes
        //   will always be emitted as literals.
      }
      while ( --pG->prev_length != 0 );
      match_available = 0;
      match_length = MIN_MATCH - 1;
      pG->strstart++;

      if ( flush )
      {
        FLUSH_BLOCK( 0 );
        pG->block_start = pG->strstart;
      }
    }
    else
      if ( match_available )
      {
        // If there was no match at the previous position, output a single
        //   literal. If there was a match but the current match is longer,
        //   truncate the previous match to a single literal.
        Tracevv( ( "%c"), (pG->window[pG->strstart - 1] ) );
        if ( ct_tally( 0, pG->window[pG->strstart - 1], pG ) )
        {
          FLUSH_BLOCK( 0 );
          pG->block_start = pG->strstart;
        }

        pG->strstart++;
        pG->lookahead--;
      }
      else
      {
        // There is no previous match to compare with, wait for the next
        //   step to decide.
        match_available = 1;
        pG->strstart++;
        pG->lookahead--;
      }

    Assert( pG->strstart <= pG->isize && pG->lookahead <= pG->isize, "a bit too far" );
#ifdef _DEBUG
    if (!( pG->strstart <= pG->isize && pG->lookahead <= pG->isize))
      Notify( PF, -1 | IERROR, "a bit too far", 0 );
#endif
    // Make sure that we always have enough lookahead, except at the end
    //   of the input file. We need MAX_MATCH bytes for the next match, plus
    //   MIN_MATCH bytes to insert the string following the next match.
    if ( pG->lookahead < MIN_LOOKAHEAD )
      fill_window( pG );
    if ( pG->Frame.Abort_Flag )
    {
      // UPDATE: the ziperr() func in dllzip.c closes file.
      return ZEN_ABORT;
    }
  }

  if ( match_available )
    ct_tally( 0, pG->window[pG->strstart - 1], pG );

  return FLUSH_BLOCK( 1 ); // eof
}

