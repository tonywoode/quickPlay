#include <windows.h>
#include "Common.h"
#pragma hdrstop
#include "Zip.h" 
#include "ZipErr.h"

/* Trees.c
 * Copyright (C) 1990-1996 Mark Adler, Richard B. Wales, Jean-loup Gailly,
 * Kai Uwe Rommel, Onno van der Linden and Igor Mandrichenko.
 * This version modified by Chris Vleghert and Eric Engler for BCB/Delphi Zip.
  ** distributed under LGPL license ** see license.txt for details
 */
/*  Trees.c by Jean-loup Gailly
 *  This is a new version of im_ctree.c originally written by Richard B. Wales
 *  for the defunct implosion method.
 *
 *  PURPOSE
 *      Encode various sets of source values using variable-length
 *      binary code trees.
 *
 *  DISCUSSION
 *      The PKZIP "deflation" process uses several Huffman trees. The more
 *      common source values are represented by shorter bit sequences.
 *
 *      Each code tree is stored in the ZIP file in a compressed form
 *      which is itself a Huffman encoding of the lengths of
 *      all the code strings (in ascending order by source values).
 *      The actual code strings are reconstructed from the lengths in
 *      the UNZIP process, as described in the "application note"
 *      (APPNOTE.TXT) distributed as part of PKWARE's PKZIP program.
 *
 *  REFERENCES
 *      Lynch, Thomas J.
 *          Data Compression:  Techniques and Applications, pp. 53-55.
 *          Lifetime Learning Publications, 1985.  ISBN 0-534-03418-7.
 *
 *      Storer, James A.
 *          Data Compression:  Methods and Theory, pp. 49-50.
 *          Computer Science Press, 1988.  ISBN 0-7167-8156-5.
 *
 *      Sedgewick, R.
 *          Algorithms, p290.
 *          Addison-Wesley, 1983. ISBN 0-201-06672-6.
 *
 *  INTERFACE
 *      void ct_init( ush *attr, int *method )
 *          Allocate the match buffer, initialize the various tables and save
 *          the location of the internal file attribute (ascii/binary) and
 *          method (DEFLATE/STORE)
 *
 *      void ct_tally( int dist, int lc );
 *          Save the match info and tally the frequency counts.
 *
 *      long flush_block( char *buf, ulg stored_len, int eof )
 *          Determine the best encoding for the current block: dynamic trees,
 *          static trees or store, and output the encoded block to the zip
 *          file. Returns the total compressed length for the file so far.
 */
#include <ctype.h>

//#include "Zip.h"
//#include "ZGlobals.h"
#define d_code( dist ) \
    ( (dist) < 256 ? pG->dist_code[dist] : pG->dist_code[256 + ((dist) >> 7)] )

// Local (static) data
int         extra_lbits[LENGTH_CODES] // extra bits for each length code
=
  {
    0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  2,  2,  2,  2,
    3,  3,  3,  3,  4,  4,  4,  4,  5,  5,  5,  5,  0};

int         extra_dbits[D_CODES]      // extra bits for each distance code
=
  {
    0,  0,  0,  0,  1,  1,  2,  2,  3,  3,  4,  4,  5,  5,  6,  6,
    7,  7,  8,  8,  9,  9,  10,  10,  11,  11,  12,  12,  13,  13
  };

int         extra_blbits[BL_CODES]    // extra bits for each bit length code
= { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 7 };

static uch  bl_order[BL_CODES] =
  {
    16,  17,  18,  0,  8,  7,  9,  6,  10,  5,  11,  4,  12,  3,
    13,  2,  14,  1,  15
  };

// The lengths of the bit length codes are sent in order of decreasing
//   probability, to avoid transmitting the lengths for unused bit length
//   codes.
// Local (static) routines in this file.
static void init_block( struct ZGlobals *pG );
static void __fastcall  pqdownheap( ct_data *tree, int k, struct ZGlobals *pG );
static void __fastcall  gen_bitlen( tree_desc *desc, struct ZGlobals *pG );
static void __fastcall  gen_codes( ct_data *tree, int max_code, struct ZGlobals *pG );
static void __fastcall  build_tree( tree_desc *desc, struct ZGlobals *pG );
static void __fastcall  scan_tree( ct_data *tree, int max_code, struct ZGlobals *pG );
static void __fastcall  send_tree( ct_data *tree, int max_code, struct ZGlobals *pG );
static int __fastcall   build_bl_tree( struct ZGlobals *pG );
static void             send_all_trees( int lcodes, int dcodes, int blcodes,
                                        struct ZGlobals *pG );
static void             compress_block( ct_data *ltree, ct_data *dtree, struct ZGlobals *pG );
static void             set_file_type( struct ZGlobals *pG );

// Allocate the match buffer, initialize the various tables and save the
//   location of the internal file attribute (ascii/binary) and method
//   (DEFLATE/STORE). attr :: Pointer to internal file attribute. method ::
//   Pointer to compression method.
void
ct_init( ush *attr, int *method, struct ZGlobals *pG )
{
  int n;      // iterates over tree elements
  int bits;   // bit counter
  int length; // length value
  int code;   // code value
  int dist;   // distance index
  pG->file_type = attr;
  pG->file_method = method;
  pG->compressed_len = 0ui64;  // v1.6018
  pG->input_len = 0L;

  if ( pG->static_dtree[0].Len != 0 )
    return;                     // ct_init already called
#ifdef DYN_ALLOC

  pG->d_buf = ( ush * )zcalloc( DIST_BUFSIZE, sizeof(ush) );
  pG->l_buf = ( uch * )zcalloc( LIT_BUFSIZE / 2, 2 );

  // Avoid using the value 64K on 16 bit machines
  if ( pG->l_buf == NULL || pG->d_buf == NULL )
    error( "ct_init: out of memory", pG );
#endif

  // Initialize the mapping length (0..255) -> length code (0..28)
  length = 0;
  for ( code = 0; code < LENGTH_CODES - 1; code++ )
  {
    pG->base_length[code] = length;
    for ( n = 0; n < (1 << extra_lbits[code]); n++ )
      pG->length_code[length++] = ( uch ) code;
  }

  Assert( length == 256, "ct_init: length != 256" );

  // Note that the length 255 (match length 258) can be represented in two
  //   different ways: code 284 + 5 bits or code 285, so we overwrite
  //   length_code[255] to use the best encoding:
  pG->length_code[length - 1] = ( uch ) code;

  // Initialize the mapping dist (0..32K) -> dist code (0..29)
  dist = 0;
  for ( code = 0; code < 16; code++ )
  {
    pG->base_dist[code] = dist;
    for ( n = 0; n < (1 << extra_dbits[code]); n++ )
      pG->dist_code[dist++] = ( uch ) code;
  }

  Assert( dist == 256, "ct_init: dist != 256" );
  dist >>= 7;                   // from now on, all distances are divided by 128
  for ( ; code < D_CODES; code++ )
  {
    pG->base_dist[code] = dist << 7;
    for ( n = 0; n < (1 << (extra_dbits[code] - 7)); n++ )
      pG->dist_code[256 + dist++] = ( uch ) code;
  }

  Assert( dist == 256, "ct_init: 256 + dist != 512" );

  // Construct the codes of the static literal tree
  for ( bits = 0; bits <= MAX_BITS; bits++ )
    pG->bl_count[bits] = 0;
  n = 0;
  while ( n <= 143 )
    pG->static_ltree[n++].Len = 8, pG->bl_count[8]++;
  while ( n <= 255 )
    pG->static_ltree[n++].Len = 9, pG->bl_count[9]++;
  while ( n <= 279 )
    pG->static_ltree[n++].Len = 7, pG->bl_count[7]++;
  while ( n <= 287 )
    pG->static_ltree[n++].Len = 8, pG->bl_count[8]++;

  // Codes 286 and 287 do not exist, but we must include them in the tree
  //   construction to get a canonical Huffman tree (longest code all ones)
  gen_codes( ( ct_data * )pG->static_ltree, L_CODES + 1, pG );

  // The static distance tree is trivial:
  for ( n = 0; n < D_CODES; n++ )
  {
    pG->static_dtree[n].Len = 5;
    pG->static_dtree[n].Code = ( ush ) ( bi_reverse( n, 5 ) );  // RCV Added (ush)
  }

  // Initialize the first block of the first file:
  init_block( pG );
}

// Initialize a new block.
static void
init_block( struct ZGlobals *pG )
{
  int n;                // iterates over tree elements

  // Initialize the trees.
  for ( n = 0; n < L_CODES; n++ )
    pG->dyn_ltree[n].Freq = 0;
  for ( n = 0; n < D_CODES; n++ )
    pG->dyn_dtree[n].Freq = 0;
  for ( n = 0; n < BL_CODES; n++ )
    pG->bl_tree[n].Freq = 0;

  pG->dyn_ltree[END_BLOCK].Freq = 1;
  pG->opt_len = pG->static_len = 0L;
  pG->last_lit = pG->last_dist = pG->last_flags = 0;
  pG->flags = 0;
  pG->flag_bit = 1;
}

#define SMALLEST  1

// Index within the heap array of least frequent node in the Huffman tree
// Remove the smallest element from the heap and recreate the heap with one
//   less element. Updates heap and heap_len.
#define pqremove( tree, top )                      \
  {                                                \
    top = pG->heap[SMALLEST];                      \
    pG->heap[SMALLEST] = pG->heap[pG->heap_len--]; \
    pqdownheap( tree, SMALLEST, pG );              \
  }

// Compares to subtrees, using the tree depth as tie breaker when the
//   subtrees have equal frequency. This minimizes the worst case length.
#define smaller( tree, n, m )                                         \
    (                                                                 \
      tree[n].Freq < tree[m].Freq                                     \
    || (tree[n].Freq == tree[m].Freq && pG->depth[n] <= pG->depth[m]) \
    )

// Restore the heap property by moving down the tree starting at node k,
//   exchanging a node with the smallest of its two sons if necessary, stopping
//   when the heap property is re-established (each father smaller than its two
//   sons). tree :: The tree to restore. k :: Node to move down.
static void __fastcall
pqdownheap( ct_data *tree, int k, struct ZGlobals *pG )
{
  int v = pG->heap[k];
  int j = k << 1;       // left son of k
  int htemp;            // required because of bug in SASC compiler
  while ( j <= pG->heap_len )
  {
    // Set j to the smallest of the two sons:
    if ( j < pG->heap_len && smaller( tree, pG->heap[j + 1], pG->heap[j] ) )
      j++;

    // Exit if v is smaller than both sons
    htemp = pG->heap[j];
    if ( smaller( tree, v, htemp ) )
      break;

    // Exchange v with the smallest son
    pG->heap[k] = htemp;
    k = j;

    // And continue down the tree, setting j to the left son of k
    j <<= 1;
  }

  pG->heap[k] = v;
}

// Compute the optimal bit lengths for a tree and update the total bit
//   length for the current block. IN assertion: the fields freq and dad are
//   set, heap[heap_max] and above are the tree nodes sorted by increasing
//   frequency. OUT assertions: the field len is set to the optimal bit length,
//   the array bl_count contains the frequencies for each bit length. The
//   length opt_len is updated; static_len is also updated if stree is not
//   null. desc :: The tree descriptor.
static void __fastcall
gen_bitlen( tree_desc *desc, struct ZGlobals *pG )
{
  ct_data *tree = desc->dyn_tree;
  int     *extra = desc->extra_bits;
  int     base = desc->extra_base;
  int     max_code = desc->max_code;
  int     max_length = desc->max_length;
  ct_data *stree = desc->static_tree;
  int     h;            // heap index
  int     n,
  m;            // iterate over the tree elements
  int     bits;         // bit length
  int     xbits;        // extra bits
  ush     f;            // frequency
  int     overflow = 0; // number of elements with bit length too large
  for ( bits = 0; bits <= MAX_BITS; bits++ )
    pG->bl_count[bits] = 0;

  // In a first pass, compute the optimal bit lengths (which may overflow in
  //   the case of the bit length tree).
  tree[pG->heap[pG->heap_max]].Len = 0; // root of the heap
  for ( h = pG->heap_max + 1; h < HEAP_SIZE; h++ )
  {
    n = pG->heap[h];
    bits = tree[tree[n].Dad].Len + 1;
    if ( bits > max_length )
      bits = max_length, overflow++;
    tree[n].Len = ( ush ) bits;         // RCV Added (ush)

    // We overwrite tree[n].Dad which is no longer needed
    if ( n > max_code )
      continue;           // not a leaf node
    pG->bl_count[bits]++;
    xbits = 0;
    if ( n >= base )
      xbits = extra[n - base];
    f = tree[n].Freq;
    pG->opt_len += ( ulg ) f * ( bits + xbits );
    if ( stree )
      pG->static_len += ( ulg ) f * ( stree[n].Len + xbits );
  }

  if ( overflow == 0 )
    return;

  Trace( ("\nbit length overflow\n", 0) );

  // This happens for example on obj2 and pic of the Calgary corpus
  // Find the first bit length which could increase:
  do
  {
    bits = max_length - 1;
    while ( pG->bl_count[bits] == 0 )
      bits--;
    pG->bl_count[bits]--; // move one leaf down the tree
    pG->bl_count[bits + 1] += ( ush ) 2;  // move one overflow item as its brother
    pG->bl_count[max_length]--;

    // The brother of the overflow item also moves one step up, but this
    //   does not affect bl_count[max_length]
    overflow -= 2;
  }
  while ( overflow > 0 );

  // Now recompute all bit lengths, scanning in increasing frequency. h is
  //   still equal to HEAP_SIZE. (It is simpler to reconstruct all lengths
  //   instead of fixing only the wrong ones. This idea is taken from 'ar'
  //   written by Haruhiko Okumura.)
  for ( bits = max_length; bits != 0; bits-- )
  {
    n = pG->bl_count[bits];
    while ( n != 0 )
    {
      m = pG->heap[--h];
      if ( m > max_code )
        continue;
      if ( tree[m].Len != (ush) bits )
      { // RCV Changed (unsigned) in (ush)
        Trace(("code %d bits %d->%d", m, tree[m].Len, bits ));
        pG->opt_len += ( ( long )bits - ( long )tree[m].Len ) * ( long )tree[m].Freq;
        tree[m].Len = ( ush ) bits; // RCV Added (ush)
      }

      n--;
    }
  }
}

// Generate the codes for a given tree and bit counts (which need not be
//   optimal). IN assertion: the array bl_count contains the bit length
//   statistics for the given tree and the field len is set for all tree
//   elements. OUT assertion: the field code is set for all tree elements of
//   non zero code length. tree :: The tree to decorate max_code :: Largest
//   code with non zero frequency.
static void __fastcall
gen_codes( ct_data *tree, int max_code, struct ZGlobals *pG )
{
  ush next_code[MAX_BITS + 1];      // next code value for each bit length
  ush code = 0;                     // running code value
  int bits; // bit index
  int n;    // code index

  // The distribution counts are first used to generate the code values
  //   without bit reversal.
  for ( bits = 1; bits <= MAX_BITS; bits++ )
  {
    next_code[bits] = code = ( ush ) ( (code + pG->bl_count[bits - 1]) << 1 );  // RCV Added (ush)
  }

  // Check that the bit counts in bl_count are consistent. The last code
  //   must be all ones.
  Assert( code + pG->bl_count[MAX_BITS] - 1 == (1 << MAX_BITS) - 1,
          "inconsistent bit counts" );
  //  Tracev( ("\ngen_codes: max_code %d "), (max_code) );

  for ( n = 0; n <= max_code; n++ )
  {
    int len = tree[n].Len;

    if ( len == 0 )
      continue;

    // Now reverse the bits
    tree[n].Code = ( ush ) ( bi_reverse( next_code[len]++, len ) );             // RCV Added (ush)
    //    Tracec( tree != pG->static_ltree, ("\nn %3d %c l %2d c %4x (%x) "),( n,
    //              (isgraph( n ) ? n : ' '), len, tree[n].Code, next_code[len] - 1) );
  }
}

// Construct one Huffman tree and assigns the code bit strings and lengths.
//   Update the total bit length for the current block. IN assertion: the field
//   freq is set for all tree elements. OUT assertions: the fields len and code
//   are set to the optimal bit length and corresponding code. The length
//   opt_len is updated; static_len is also updated if stree is not null. The
//   field max_code is set. desc :: The tree descriptor.
static void __fastcall
build_tree( tree_desc *desc, struct ZGlobals *pG )
{
  ct_data *tree = desc->dyn_tree;
  ct_data *stree = desc->static_tree;
  int     elems = desc->elems;
  int     n,
  m;                      // iterate over heap elements
  int     max_code = -1;          // largest code with non zero frequency
  int     node = elems;           // next internal node of the tree

  // Construct the initial heap, with least frequent element in
  //   heap[SMALLEST]. The sons of heap[n] are heap[2*n] and heap[2*n+1].
  //   heap[0] is not used.
  pG->heap_len = 0, pG->heap_max = HEAP_SIZE;

  for ( n = 0; n < elems; n++ )
  {
    if ( tree[n].Freq != 0 )
    {
      pG->heap[++pG->heap_len] = max_code = n;
      pG->depth[n] = 0;
    }
    else
      tree[n].Len = 0;
  }

  // The pkzip format requires that at least one distance code exists, and
  //   that at least one bit should be sent even if there is only one possible
  //   code. So to avoid special checks later on we force at least two codes of
  //   non zero frequency.
  while ( pG->heap_len < 2 )
  {
    int nw = pG->heap[++pG->heap_len] = ( (max_code < 2) ? ++max_code : 0 );

    tree[nw].Freq = 1;
    pG->depth[nw] = 0;
    pG->opt_len--;
    if ( stree )
      pG->static_len -= stree[nw].Len;

    // new is 0 or 1 so it does not have extra bits
  }

  desc->max_code = max_code;

  // The elements heap[heap_len/2+1 .. heap_len] are leaves of the tree,
  //   establish sub-heaps of increasing lengths:
  for ( n = pG->heap_len / 2; n >= 1; n-- )
    pqdownheap( tree, n, pG );

  // Construct the Huffman tree by repeatedly combining the least two
  //   frequent nodes.
  do
  {
    pqremove( tree, n );          // n = node of least frequency
    m = pG->heap[SMALLEST];       // m = node of next least frequency
    pG->heap[--pG->heap_max] = n; // keep the nodes sorted by frequency
    pG->heap[--pG->heap_max] = m;

    // Create a new node father of n and m
    tree[node].Freq = ( ush ) ( tree[n].Freq + tree[m].Freq );  // RCV Added (ush)
    pG->depth[node] = ( uch ) ( Max( pG->depth[n], pG->depth[m] ) + 1 );
    tree[n].Dad = tree[m].Dad = ( ush ) node;                   // RCV Added (ush)
#ifdef DUMP_BL_TREE

    if ( tree == bl_tree )
    {
      DLLprintf( "\nnode %d(%d), sons %d(%d) %d(%d)", node, tree[node].Freq, n,
                 tree[n].Freq, m, tree[m].Freq );
    }

#endif

    // and insert the new node in the heap
    pG->heap[SMALLEST] = node++;
    pqdownheap( tree, SMALLEST, pG );
  }
  while ( pG->heap_len >= 2 );

  pG->heap[--pG->heap_max] = pG->heap[SMALLEST];

  // At this point, the fields freq and dad are set. We can now generate the
  //   bit lengths.
  gen_bitlen( ( tree_desc * )desc, pG );

  // The field len is now set, we can generate the bit codes
  gen_codes( ( ct_data * )tree, max_code, pG );
}

// Scan a literal or distance tree to determine the frequencies of the codes
//   in the bit length tree. Updates opt_len to take into account the repeat
//   counts. (The contribution of the bit length codes will be added later
//   during the construction of bl_tree.) tree :: The tree to be scanned.
//   max_code :: And its largest code of non zero frequency.
static void __fastcall
scan_tree( ct_data *tree, int max_code, struct ZGlobals *pG )
{
  int n;                      // iterates over all tree elements
  int prevlen = -1;           // last emitted length
  int curlen;                 // length of current code
  int nextlen = tree[0].Len;  // length of next code
  int count = 0;              // repeat count of the current code
  int max_count = 7;          // max repeat count
  int min_count = 4;          // min repeat count
  if ( nextlen == 0 )
    max_count = 138, min_count = 3;
  tree[max_code + 1].Len = ( ush ) - 1;           // guard
  for ( n = 0; n <= max_code; n++ )
  {
    curlen = nextlen;
    nextlen = tree[n + 1].Len;
    if ( ++count < max_count && curlen == nextlen )
    {
      continue;
    }
    else
      if ( count < min_count )
      {
        pG->bl_tree[curlen].Freq += ( ush ) count;  // RCV Added (ush)
      }
      else
        if ( curlen != 0 )
        {
          if ( curlen != prevlen )
            pG->bl_tree[curlen].Freq++;
          pG->bl_tree[REP_3_6].Freq++;
        }
        else
          if ( count <= 10 )
          {
            pG->bl_tree[REPZ_3_10].Freq++;
          }
          else
          {
            pG->bl_tree[REPZ_11_138].Freq++;
          }

    count = 0;
    prevlen = curlen;
    if ( nextlen == 0 )
    {
      max_count = 138, min_count = 3;
    }
    else
      if ( curlen == nextlen )
      {
        max_count = 6, min_count = 3;
      }
      else
      {
        max_count = 7, min_count = 4;
      }
  }
}

// Send a literal or distance tree in compressed form, using the codes in
//   bl_tree. tree :: The tree to be scanned. max_code :: And its largest code
//   of non zero frequency.
static void __fastcall
send_tree( ct_data *tree, int max_code, struct ZGlobals *pG )
{
  int n;                      // iterates over all tree elements
  int prevlen = -1;           // last emitted length
  int curlen;                 // length of current code
  int nextlen = tree[0].Len;  // length of next code
  int count = 0;              // repeat count of the current code
  int max_count = 7;          // max repeat count
  int min_count = 4;          // min repeat count

  // tree[max_code+1].Len = -1;
  // guard already set
  if ( !nextlen )
    max_count = 138, min_count = 3;

  for ( n = 0; n <= max_code; n++ )
  {
    curlen = nextlen;
    nextlen = tree[n + 1].Len;
    if ( ++count < max_count && curlen == nextlen )
    {
      continue;
    }
    else
      if ( count < min_count )
      {
        do
        {
          send_code( curlen, pG->bl_tree, pG );
        }
        while ( --count != 0 );
      }
      else
        if ( curlen != 0 )
        {
          if ( curlen != prevlen )
          {
            send_code( curlen, pG->bl_tree, pG );
            count--;
          }

          Assert( count >= 3 && count <= 6, " 3_6?" );
          send_code( REP_3_6, pG->bl_tree, pG );
          send_bits( count - 3, 2, pG );
        }
        else
          if ( count <= 10 )
          {
            send_code( REPZ_3_10, pG->bl_tree, pG );
            send_bits( count - 3, 3, pG );
          }
          else
          {
            send_code( REPZ_11_138, pG->bl_tree, pG );
            send_bits( count - 11, 7, pG );
          }

    count = 0;
    prevlen = curlen;
    if ( !nextlen )
    {
      max_count = 138, min_count = 3;
    }
    else
      if ( curlen == nextlen )
      {
        max_count = 6, min_count = 3;
      }
      else
      {
        max_count = 7, min_count = 4;
      }
  }
}

// Construct the Huffman tree for the bit lengths and return the index in
//   bl_order of the last bit length code to send.
static int __fastcall
build_bl_tree( struct ZGlobals *pG )
{
  int max_blindex;            // index of last bit length code of non zero freq

  // Determine the bit length frequencies for literal and distance trees
  scan_tree( ( ct_data * )pG->dyn_ltree, pG->l_desc.max_code, pG );
  scan_tree( ( ct_data * )pG->dyn_dtree, pG->d_desc.max_code, pG );

  // Build the bit length tree:
  build_tree( (tree_desc *) (&pG->bl_desc), pG );

  // opt_len now includes the length of the tree representations, except the
  //   lengths of the bit lengths codes and the 5+5+4 bits for the counts.
  // Determine the number of bit length codes to send. The pkzip format
  //   requires that at least 4 bit length codes be sent. (appnote.txt says 3
  //   but the actual value used is 4.)
  for ( max_blindex = BL_CODES - 1; max_blindex >= 3; max_blindex-- )
  {
    if ( pG->bl_tree[bl_order[max_blindex]].Len != 0 )
      break;
  }

  // Update opt_len to include the bit length tree and counts
  pG->opt_len += 3 * ( max_blindex + 1 ) + 5 + 5 + 4;
  //  Tracev( ("\ndyn trees: dyn %ld, stat %ld"), (pG->opt_len, pG->static_len) );

  return max_blindex;
}

// Send the header for a block using dynamic Huffman trees: the counts, the
//   lengths of the bit length codes, the literal tree and the distance tree.
//   IN assertion: lcodes >= 257, dcodes >= 1, blcodes >= 4. lcodes, dcodes,
//   blcodes :: Number of codes for each tree.
static void
send_all_trees( int lcodes, int dcodes, int blcodes, struct ZGlobals *pG )
{
  int rank;                   // index in bl_order
  /*  Assert( lcodes >= 257 && dcodes >= 1 && blcodes >= 4, "not enough codes" );
    Assert( lcodes <= L_CODES && dcodes <= D_CODES && blcodes <= BL_CODES,
            "too many codes" );
    Tracev( ("\nbl counts: "), 0 );   */
  send_bits( lcodes - 257, 5, pG );

  // not +255 as stated in appnote.txt 1.93a or -256 in 2.04c
  send_bits( dcodes - 1, 5, pG );
  send_bits( blcodes - 4, 4, pG );  // not -3 as stated in appnote.txt
  for ( rank = 0; rank < blcodes; rank++ )
  {
    //    Tracev( ("\nbl code %2d "), (bl_order[rank]) );
    send_bits( pG->bl_tree[bl_order[rank]].Len, 3, pG );
  }

  //  Tracev( ("\nbl tree: sent %ld"), (pG->bits_sent) );

  send_tree( ( ct_data * )pG->dyn_ltree, lcodes - 1, pG );  // send the literal tree
  //  Tracev( ("\nlit tree: sent %ld"), (pG->bits_sent) );

  send_tree( ( ct_data * )pG->dyn_dtree, dcodes - 1, pG );  // send the distance tree
  //  Tracev( ("\ndist tree: sent %ld"), (pG->bits_sent) );
}

// Determine the best encoding for the current block: dynamic trees, static
//   trees or store, and output the encoded block to the zip file. This
//   function returns the total compressed length for the file so far. buf ::
//   Input block, or NULL if too old. stored_len :: Length of input block. eof;
//   :: true if this is the last block for a file.
ulg
flush_block( char *buf, ulg stored_len, int eof, struct ZGlobals *pG )
{
  ulg opt_lenb, static_lenb;                // opt_len and static_len in bytes
  int max_blindex;                          // index of last bit length code of non zero freq
  pG->flag_buf[pG->last_flags] = pG->flags; // Save the flags for the last 8 items

  // Check if the file is ascii or binary
  if ( *pG->file_type == (ush) UNKNOWN )
    set_file_type( pG );

  // Construct the literal and distance trees
  build_tree( (tree_desc *) (&pG->l_desc), pG );
  Tracev( ("\nlit data: dyn %ld, stat %ld"), (pG->opt_len, pG->static_len) );

  build_tree( (tree_desc *) (&pG->d_desc), pG );
  Tracev( ("\ndist data: dyn %ld, stat %ld"), (pG->opt_len, pG->static_len) );

  // At this point, opt_len and static_len are the total bit lengths of the
  //   compressed block data, excluding the tree representations.
  // Build the bit length tree for the above two trees, and get the index in
  //   bl_order of the last bit length code to send.
  max_blindex = build_bl_tree( pG );

  // Determine the best encoding. Compute first the block length in bytes
  opt_lenb = ( pG->opt_len + 3 + 7 ) >> 3;
  static_lenb = ( pG->static_len + 3 + 7 ) >> 3;
  pG->input_len += stored_len;              // for debugging only
  Trace(("\nopt %lu(%lu) stat %lu(%lu) stored %lu lit %u dist %u ",
         opt_lenb, pG->opt_len, static_lenb, pG->static_len,
         stored_len, pG->last_lit, pG->last_dist));

  if ( static_lenb <= opt_lenb )
    opt_lenb = static_lenb;

  // If compression failed and this is the first and last block, and if the
  //   zip file can be seeked (to rewrite the local header), the whole file is
  //   transformed into a stored file:
#ifdef FORCE_METHOD

  if ( pG->level == 1 && eof && pG->compressed_len == 0u i64 )
  { // force stored file v1.6018
#else
  if ( stored_len <= opt_lenb
       && eof
       && pG->compressed_len == 0ui64
       && (pG->CanSeek || seekable(pG)) ) // 1.75 only need to check once
  { // v1.6018
#endif

    // Since LIT_BUFSIZE <= 2 * WSIZE, the input data must be there:
    if ( buf == NULL )
      ziperr( ZEN_LOGIC07, pG );

    copy_block( buf, ( unsigned )stored_len, 0, pG );                   // without header
    pG->compressed_len = ( ( unsigned __int64 )stored_len ) << 3ui64;  // v1.6018
    *pG->file_method = STORE;
  }
  else
#ifdef FORCE_METHOD

    if ( pG->level == 2 && buf != ( char * )NULL )
    { // force stored block
#else
    if ( stored_len + 4 <= opt_lenb && buf != ( char * )NULL )
    {
      // 4: two words for the lengths
#endif

      // The test buf != NULL is only necessary if LIT_BUFSIZE > WSIZE.
      //   Otherwise we can't have processed more than WSIZE input bytes
      //   since the last block flush, because compression would have been
      //   successful. If LIT_BUFSIZE <= WSIZE, it is never too late to
      //   transform a block into a stored block.
      send_bits( (STORED_BLOCK << 1) + eof, 3, pG );                // send block type
      pG->compressed_len = ( pG->compressed_len + 3 + 7 ) &~7ui64; // v1.6018
      pG->compressed_len += ( ( unsigned __int64 )(stored_len + 4) ) << 3;  // v1.6018
      copy_block( buf, ( unsigned )stored_len, 1, pG );                     // with header
#ifdef FORCE_METHOD

    }
    else
      if ( pG->level == 3 )
      { // force static trees
#else

    }
    else
      if ( static_lenb == opt_lenb )
      {
#endif
        send_bits( (STATIC_TREES << 1) + eof, 3, pG );
        compress_block( ( ct_data * )pG->static_ltree, ( ct_data * )pG->static_dtree, pG );
        pG->compressed_len += 3 + pG->static_len;
      }
      else
      {
        send_bits( (DYN_TREES << 1) + eof, 3, pG );
        send_all_trees( pG->l_desc.max_code + 1, pG->d_desc.max_code + 1, max_blindex + 1, pG );
        compress_block( ( ct_data * )pG->dyn_ltree, ( ct_data * )pG->dyn_dtree, pG );
        pG->compressed_len += 3 + pG->opt_len;
      }

  Assert( pG->compressed_len == ( unsigned __int64 )pG->bits_sent, "bad compressed size");
  init_block( pG );

  if ( eof )
  {
    Assert( pG->input_len == pG->isize, "bad input size" );
    bi_windup( pG );
    pG->compressed_len += 7;                  // align on byte boundary
  }

  Tracev( ( "\ncomprlen %lu(%lu) "), (pG->compressed_len >> 3,
                                      pG->compressed_len - 7 * eof ));

  return ( ulg ) ( pG->compressed_len >> 3 );
}

// Save the match info and tally the frequency counts. Return true if
//   the current block must be flushed. dist :: Distance of matched string.
//   lc :: Match length-MIN_MATCH or unmatched char (if dist==0)
int __fastcall
ct_tally( int dist, int lc, struct ZGlobals *pG )
{
  pG->l_buf[pG->last_lit++] = ( uch ) lc;
  if ( !dist )
  {
    // lc is the unmatched char
    pG->dyn_ltree[lc].Freq++;
  }
  else
  {
    // Here, lc is the match length - MIN_MATCH
    dist--;                                     // dist = match distance - 1
    Assert( (ush) dist < (ush) MAX_DIST && (ush) lc <= (ush) (MAX_MATCH - MIN_MATCH)
            && (ush) d_code( dist ) < (ush) D_CODES, "ct_tally: bad match" );

    pG->dyn_ltree[pG->length_code[lc] + LITERALS + 1].Freq++;
    pG->dyn_dtree[d_code( dist )].Freq++;

    pG->d_buf[pG->last_dist++] = ( ush ) dist;  // RCV Added (ush)
    pG->flags |= pG->flag_bit;
  }

  pG->flag_bit <<= 1;

  // Output the flags if they fill a byte:
  if ( (pG->last_lit & 7) == 0 )
  {
    pG->flag_buf[pG->last_flags++] = pG->flags;
    pG->flags = 0, pG->flag_bit = 1;
  }

  // Try to guess if it is profitable to stop the current block here
  if ( pG->level > 2 && (pG->last_lit & 0xFFF) == 0 )
  {
    // Compute an upper bound for the compressed length
    ulg out_length = ( ulg ) pG->last_lit * 8L;
    ulg in_length = ( ulg ) pG->strstart - pG->block_start;
    int dcode;

    for ( dcode = 0; dcode < D_CODES; dcode++ )
    {
      out_length += ( ulg ) pG->dyn_dtree[dcode].Freq * ( 5L + extra_dbits[dcode] );
    }

    out_length >>= 3;
    /*    Trace( ("\nlast_lit %u, last_dist %u, in %ld, out ~%ld(%ld%%) "), (pG->last_lit, pG->
                 last_dist, in_length, out_length, 100L - out_length * 100L / in_length
             ) );*/
    if ( pG->last_dist < pG->last_lit / 2 && out_length < in_length / 2 )
      return 1;
  }

  return ( pG->last_lit == LIT_BUFSIZE - 1 || pG->last_dist == DIST_BUFSIZE );

  // We avoid equality with LIT_BUFSIZE because of wraparound at 64K on
  //   16 bit machines and because stored blocks are restricted to 64K-1
  //   bytes.
}

// Send the block data compressed using the given Huffman trees ltree ::
//   Literal tree. dtree :: Distance tree.
static void
compress_block( ct_data *ltree, ct_data *dtree, struct ZGlobals *pG )
{
  unsigned  dist;                   // distance of matched string
  int       lc;                     // match length or unmatched char (if dist == 0)
  unsigned  lx = 0;                 // running index in l_buf
  unsigned  dx = 0;                 // running index in d_buf
  unsigned  fx = 0;                 // running index in flag_buf
  uch       flag = 0;               // current flags
  unsigned  code;                   // the code to send
  int       extra;                  // number of extra bits to send
  if ( pG->last_lit != 0 )
  {
    do
    {
      if ( (lx & 7) == 0 )
        flag = pG->flag_buf[fx++];
      lc = pG->l_buf[lx++];
      if ( (flag & 1) == 0 )
      {
        send_code( lc, ltree, pG ); // send a literal byte
        //        Tracecv( isgraph( lc ), (" '%c' "), (lc));
      }
      else
      {
        // Here, lc is the match length - MIN_MATCH
        code = pG->length_code[lc];
        send_code( code + LITERALS + 1, ltree, pG );  // send the length code
        extra = extra_lbits[code];
        if ( extra != 0 )
        {
          lc -= pG->base_length[code];
          send_bits( lc, extra, pG );                 // send the extra length bits
        }

        dist = pG->d_buf[dx++];

        // Here, dist is the match distance - 1
        code = d_code( dist );
        Assert( code < D_CODES, "bad d_code" );

        send_code( code, dtree, pG );                 // send the distance code
        extra = extra_dbits[code];
        if ( extra != 0 )
        {
          dist -= pG->base_dist[code];
          send_bits( dist, extra, pG );               // send the extra distance bits
        }
      } // literal or match pair ?

      flag >>= 1;
    }
    while ( lx < pG->last_lit );
  }

  send_code( END_BLOCK, ltree, pG );
}

// Set the file type to ASCII or BINARY, using a crude approximation:
//   binary if more than 20% of the bytes are <= 6 or >= 128, ascii
//   otherwise. IN assertion: the fields freq of dyn_ltree are set and the
//   total of all frequencies does not exceed 64K (to fit in an int on 16
//   bit machines).
static void
set_file_type( struct ZGlobals *pG )
{
  unsigned  ascii_freq = 0;
  unsigned  bin_freq = 0;
  int       n = 0;

  while ( n < 7 )
    bin_freq += pG->dyn_ltree[n++].Freq;
  while ( n < 128 )
    ascii_freq += pG->dyn_ltree[n++].Freq;
  while ( n < LITERALS )
    bin_freq += pG->dyn_ltree[n++].Freq;
  *pG->file_type = ( ush ) ( (bin_freq > (ascii_freq >> 2)) ? BINARY : ASCII ); // RCV Added
  ///* (ush)
  if ( *pG->file_type == BINARY && pG->translate_eol )
  {
    Notify( PF, IWARNING, "-l used on binary file" ); 
  }
}
