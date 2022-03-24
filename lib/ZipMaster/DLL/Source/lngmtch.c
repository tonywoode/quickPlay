#include <windows.h>
#include "Common.h"
#pragma hdrstop   
//#ifdef _USE_ASM_    
#if defined(_USE_ASM_) && (__BORLANDC__ < 0x0570)
  #pragma inline
#endif
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
 *
 *  DISCUSSION
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
//#ifdef _USE_ASM_
//  #pragma inline
//#endif

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

//#define HASH_SIZE (unsigned)(1<<HASH_BITS)
//#define HASH_MASK (HASH_SIZE-1)
//#define WMASK     (WSIZE-1)
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
typedef ush       Pos;
typedef unsigned  IPos;

// Set match_start to the longest match starting at the given string and
//   return its length. Matches shorter or equal to prev_length are discarded,
//   in which case the result is equal to prev_length and match_start is
//   garbage. IN assertions: cur_match is the head of the hash chain for the
//   current string (strstart) and its distance is <= MAX_DIST, and prev_length
//   >= 1
#ifndef _USE_ASM_
int __fastcall longest_match(unsigned cur_match, struct ZGlobals *pG )
{
  unsigned      chain_length = pG->max_chain_length;  // max hash chain length
  register uch  *scan = pG->window + pG->strstart;    // current string
  register uch  *match;                     // matched string
  register int  len;                        // length of current match
  int           best_len = pG->prev_length; // best match length so far
  IPos          limit = pG->strstart > ( IPos ) MAX_DIST ? pG->strstart -
                        ( IPos ) MAX_DIST : NIL;

  // Stop when cur_match becomes <= limit. To simplify the code, we prevent
  //   matches with the string of window index 0.
  // The code is optimized for HASH_BITS >= 8 and MAX_MATCH-2 multiple of
  //   16. It is easy to get rid of this optimization if necessary.
#if HASH_BITS < 8 || MAX_MATCH != 258

error :
  Code too clever
#endif
  register uch * strend = pG->window + pG->strstart + MAX_MATCH;

  register uch  scan_end1 = scan[best_len - 1];
  register uch  scan_end = scan[best_len];

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

    Assert( scan <= pG->window + ( unsigned )(pG->window_size - 1), "wild scan" );

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
  while ( (cur_match = pG->prev[cur_match & WMASK]) > limit && --chain_length != 0 );

  return best_len;
}

#else

// The code is optimized for HASH_BITS >= 8 and MAX_MATCH-2 multiple of 16.
//   It is easy to get rid of this optimization if necessary.
#if HASH_BITS < 8 || MAX_MATCH != 258
error :
Code too clever
#endif
// esp cur_match (D) +4 chain_length (D) +8 limit (D) +12 scan_end (W)
int __fastcall longest_match(unsigned cur_match, struct ZGlobals * pG )
{
#pragma warn - rvl
  #pragma argsused
  asm
  {
    add esp, -16
    mov dword ptr[esp], eax

    // unsigned chain_length = pG->max_chain_length; /* max hash chain length
    // ; EDX = pG
    mov eax, dword ptr[edx +.max_chain_length];
    mov dword         ptr[esp + 4], eax

    // register uch *scan = pG->window + pG->strstart; /* current string
    // register uch *match; /* matched string
    // register int len; /* length of current match
    mov eax, dword ptr[edx +.strstart];
    mov ecx, eax
    add ecx, edx
    add ecx, .window;

        // int best_len = pG->prev_length; /* best match length so far
        // ; ECX = scan, EDX = pG, EAX = @temp11
    mov edi, dword ptr[edx +.prev_length];

    // IPos limit =
    // pG->strstart > ( IPos ) MAX_DIST ? pG->strstart - ( IPos ) MAX_DIST : NIL;
    // Stop when cur_match becomes <= limit. To simplify the code, we
    //   prevent matches with the string of window index 0.
    // ; ECX = scan, EDX = pG, EDI = best_len, EAX = @temp11
    cmp eax, MAX_DIST;
    jbe short L2
    mov  eax, dword ptr[edx +.strstart];
    sub  eax, MAX_DIST;
    jmp short L3
  L2:
    xor eax, eax
  L3:
    mov dword ptr[esp + 8], eax

    // register uch *strend = pG->window + pG->strstart + MAX_MATCH;
    // ; ECX = scan, EDX = pG, EDI = best_len
    // register uch scan_end1 = scan[ best_len - 1 ];
    // register uch scan_end = scan[ best_len ];
    // ; ECX = scan, EDX = pG, EDI = best_len, EAX = strendXX
    mov bx, word ptr[ecx + edi - 1]
    mov word ptr[esp + 12], bx

    // ; ECX = scan, EDX = pG, EDI = best_len, EAX =
    // Do not waste too much time if we already have a good match:
    // if ( pG->prev_length >= pG->good_match )
    // chain_length >>= 2;
    mov ebx, dword ptr[edx +.prev_length];
    cmp ebx, dword ptr[edx +.good_match];
    jb short L4
    shr dword ptr[esp + 4], 2   // chain_length
  L4:
  L5:
    // match = pG->window + cur_match;
    mov esi, dword ptr[esp]                 // cur_match
    add esi, edx
    add esi, .window;

    // Skip to next match if the match length cannot increase or if the
    //   match length is less than 2:
    // if ( match[ best_len ] != scan_end ||
    // match[ best_len - 1 ] != scan_end1 ||
    // *match != *scan || *++match != scan[ 1 ] )
    // continue;
    // ; ECX = scan, ESI = match, EDX = pG, EDI = best_len, EAX = ??
    mov  bx, word ptr[esi + edi - 1]
    cmp bx, word ptr[esp + 12]  // scan_end
    jne L8
    mov bx, word ptr[esi]
    cmp bx, word ptr[ecx]
    jne short L8

    // The check at best_len-1 can be removed because it will be made again
    //   later. (This heuristic is not always a win.) It is not necessary to
    //   compare scan[2] and match[2] since they are always equal when the
    //   other bytes match, given that the hash keys are equal and that
    //   HASH_BITS >= 8.
    // scan += 2, match++;
    // ; ECX = scan, EDX = pG, EDI = best_len, EAX = len
    // add ecx,2
    // add esi,2// inc esi
    mov eax, 2  // start 3rd byte

    // We check for insufficient lookahead only every 8th comparison; the
    //   256th check will be made at strstart+258.
    // ; ECX = scan, ESI = match, EDX = pG, EDI = best_len, EAX = len
  L9:
    inc eax
    mov ebx, [ecx + eax]
    xor ebx, [esi + eax]
    test ebx, 0xFF // byte 0
    jnz short L10
    inc eax
    test ebx, 0xFF00    // byte 1
    jnz short L10
    inc eax
    test ebx, 0xFF0000  // byte 2
    jnz short L10
    inc eax
    test ebx, ebx       // byte 3
    jnz short L10
    inc eax
    mov ebx, [ecx + eax]
    xor ebx, [esi + eax]
    test ebx, 0xFF  // byte 0
    jnz short L10
    inc eax
    test ebx, 0xFF00    // byte 1
    jnz short L10
    inc eax
    test ebx, 0xFF0000  // byte 2
    jnz short L10
    inc eax
    test ebx, ebx       // byte 3
    jnz short L10

    // inc eax
    cmp eax, MAX_MATCH
    jb short L9
  L10:
    // ; ECX = scan, ESI = match, EDX = pG, EDI = best_len, EAX = len
    // free EBX , ESI = match
    // if ( len > best_len )
    cmp eax, edi
    jl short L11

    // pG->match_start = cur_match;
    // ; ECX = scan, EDX = pG, EAX = strend, EBX = len
    mov esi, dword ptr[esp]
    mov dword ptr[edx +.match_start], esi

    // best_len = len;
    mov edi, eax

    // if ( len >= pG->nice_match )
    // break;
    // ; ECX = scan, EDX = pG, EDI = best_len, EAX = len, EBX = ??
    cmp eax, dword ptr[edx +.nice_match];
    jge short L14 // break

    // scan_end1 = scan[ best_len - 1 ];
    // ; EDI = best_len
    mov bx, word ptr[ecx + edi - 1]
    mov word ptr[esp + 12], bx  // scan_end
  L11:
    // while ( ( cur_match = pG->prev[ cur_match & WMASK ] ) > limit && --chain_length != 0 );
  L8:
    mov ebx, dword ptr[esp]
    and ebx, WMASK;
    movzx ebx, word ptr[edx + 2 * ebx +.prev];
    mov dword ptr[esp], ebx // cur_match
    cmp ebx, dword ptr[esp + 8]
    jbe short L14
    dec dword ptr[esp + 4]  // chain_length
    jne L5

    // ; EDI = best_len
  L14:
      // return best_len;
      mov eax, edi
      add esp, 16
  };
};
#endif

