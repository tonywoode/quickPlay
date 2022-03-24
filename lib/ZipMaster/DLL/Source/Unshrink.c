#include <windows.h>
#include "Common.h"
#pragma hdrstop
/* This version modified by Chris Vleghert and Eric W. Engler
 * for BCB/Delphi Zip, Jun 18, 2000.
 */

/*---------------------------------------------------------------------------
 * unshrink.c                     version 1.21                     23 Nov 95
 *
 * Shrinking is basically a dynamic LZW algorithm with allowed code sizes of
 * up to 13 bits; in addition, there is provision for partial clearing of
 * leaf nodes.  PKWARE uses the special code 256 (decimal) to indicate a
 * change in code size or a partial clear of the code tree:  256,1 for the
 * former and 256,2 for the latter.  [Note that partial clearing can "orphan"
 * nodes:  the parent-to-be can be cleared before its new child is added,
 * but the child is added anyway (as an orphan, as though the parent still
 * exists).  When the tree fills up to the point where the parent node is
 * reused, the orphan is effectively "adopted."  Versions prior to 1.05 were
 * more affected due to their use of more pointers (to children and siblings
 * as well as parents).]
 *
 * This replacement version of unshrink.c was written from scratch.  It is
 * based only on the algorithms described in Mark Nelson's _The Data Compres-
 * sion Book_ and in Terry Welch's original paper in the June 1984 issue of
 * IEEE _Computer_; no existing source code, including any in Nelson's book,
 * was used.
 *
 * Memory requirements have been reduced in this version and are now no more
 * than the original Sam Smith code.  This is still larger than any of the
 * other algorithms:  at a minimum, 8K+8K+16K (stack+values+parents) assuming
 * 16-bit short ints, and this does not even include the output buffer (the
 * other algorithms leave the uncompressed data in the work area, typically
 * called slide[]).  For machines with a 64KB data space this is a problem,
 * particularly when text conversion is required and line endings have more
 * than one character.  UnZip's solution is to use two roughly equal halves
 * of outbuf for the ASCII conversion in such a case; the "unshrink" argument
 * to flush() signals that this is the case.
 *
 * For large-memory machines, a second outbuf is allocated for translations,
 * but only if unshrinking and only if translations are required.
 *
 *             | binary mode  |        text mode
 *   ---------------------------------------------------
 *   big mem   |  big outbuf  | big outbuf + big outbuf2  <- malloc'd here
 *   small mem | small outbuf | half + half small outbuf
 *
 * Copyright 1994, 1995 Greg Roelofs.  See the accompanying file "COPYING"
 * in UnZip 5.20 (or later) source or binary distributions.
 *---------------------------------------------------------------------------*/

#include "unzip.h"

static void partial_clear ( struct UGlobals *pG );

#ifdef DEBUG
#  define OUTDBG(c) \
   if ((c) < 32 || (c) >= 127) Notify( PF, IWARNING, "\\x%02x", (c) ); else putc( (c), stderr );
#else
#  define OUTDBG( c )
#endif

/* HSIZE is defined as 2^13 (8192) in unzip.h */
#define BOGUSCODE  256
#define FLAG_BITS  parent       /* upper bits of parent[] used as flag bits */
#define CODE_MASK  (HSIZE - 1)  /* 0x1fff (lower bits are parent's index) */
#define FREE_CODE  HSIZE        /* 0x2000 (code is unused or was cleared) */
#define HAS_CHILD  (HSIZE << 1) /* 0x4000 (code has a child--do not clear) */

#define parent pG->area.shrink.Parent
#define Value  pG->area.shrink.value    /* "value" conflicts with Pyramid ioctl.h */
#define stack  pG->area.shrink.Stack


/* ===========================================================================
 *                                                                      Function unshrink()
 */
int
unshrink ( struct UGlobals *pG )
{
#if 0
  static uch *stacktop = NULL;
#else
  uch *stacktop = stack + ( HSIZE - 1 );
#endif

  register uch *newstr;
  int codesize = 9, len, KwKwK, error;
  shrint code, oldcode, freecode, curcode;
  shrint lastfreecode;
  unsigned int outbufsiz;

  /*---------------------------------------------------------------------------
   *    Initialize various variables.
   *---------------------------------------------------------------------------*/
  lastfreecode = BOGUSCODE;

  /* non-memory-limited machines:  allocate second (large) buffer for
   * textmode conversion in flush(), but only if needed */
  if ( pG->pInfo->textmode && !pG->outbuf2 &&
       ( pG->outbuf2 = ( uch * )  MALLOC ( TRANSBUFSIZ ) )  == ( uch * )  NULL )
    return PK_MEM3;

  for ( code = 0; code < BOGUSCODE; ++code )
  {
    Value[ code ]  = ( uch )  code;
    parent[ code ]  = BOGUSCODE;
  }
  for ( code = BOGUSCODE + 1; code < HSIZE; ++code )
    parent[ code ]  = FREE_CODE;

  pG->realbuf = pG->outbuf;     /* use normal outbuf unless we're a DLL routine */
#ifdef USE_STRM_OUTPUT
  if ( pG->redirect_data )
  {
    pG->realbuf = pG->redirect_buffer;
    outbufsiz = pG->redirect_size;
  }
  else
#endif
    if ( pG->pInfo->textmode )
      outbufsiz = RAWBUFSIZ;      // unzpriv.h  (32K)
    else
      outbufsiz = OUTBUFSIZ;      // unzpriv.h  (32K)
  pG->outptr = pG->realbuf;
  pG->outcnt = 0L;

  /*---------------------------------------------------------------------------
   *     Get and output first code, then loop over remaining ones.
   *---------------------------------------------------------------------------*/
  READBITS ( codesize, oldcode )
  if ( !pG->zipeof )
  {
    *pG->outptr++ = ( uch )  oldcode;
    OUTDBG ( ( uch )  oldcode )
    ++ pG->outcnt;
  }

  do
  {
    READBITS ( codesize, code )
    if ( pG->zipeof )
      break;
    if ( code == BOGUSCODE )
    {    /* possible to have consecutive escapes? */
      READBITS ( codesize, code )
      if ( code == 1 )
      {
        ++codesize;
        if (pG->Frame.Verbose < 0)
          Notify( PF, ITRACE, " (codesize now %d bits)", codesize );
      }
      else
        if ( code == 2 )
        {
          if (pG->Frame.Verbose < 0)
            Notify( PF, ITRACE, " (partial clear code)" );
          partial_clear ( pG );     /* clear leafs (nodes with no children) */
          if (pG->Frame.Verbose < 0)
            Notify( PF, ITRACE, " (done with partial clear)"   );
          lastfreecode = BOGUSCODE;       /* reset start of free-node search */
        }
      continue;
    }

    /*-----------------------------------------------------------------------
     *      Translate code:  traverse tree from leaf back to root.
     *-----------------------------------------------------------------------*/
    newstr = stacktop;
    curcode = code;

    if ( parent[ curcode ]  == FREE_CODE )
    {
      /* or (FLAG_BITS[curcode] & FREE_CODE)? */
      KwKwK = true;
      if (pG->Frame.Verbose < 0)
        Notify( PF, ITRACE, " (found a KwKwK code %d; oldcode = %d)", code, oldcode   );
      --newstr;                 /* last character will be same as first character */
      curcode = oldcode;
    }
    else
      KwKwK = false;

    do
    {
      *newstr-- = Value[ curcode ];
      curcode = ( shrint )  ( parent[ curcode ]  & CODE_MASK );
    }
    while ( curcode != BOGUSCODE );

    len = ( int )  ( stacktop - newstr++ );
    if ( KwKwK )
      *stacktop = *newstr;

    /*-----------------------------------------------------------------------
     *        Write expanded string in reverse order to output buffer.
     *-----------------------------------------------------------------------*/
    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "code %4d; oldcode %4d; char %3d (%c); string [", code,
              oldcode, ( int )  ( *newstr ), ( *newstr < 32
                                               || *newstr >= 127 )  ? ' ' : *newstr   );
    {
      register uch *p;

      for ( p = newstr; p < newstr + len; ++p )
      {
        *pG->outptr++ = *p;
        OUTDBG ( *p )
        if ( ++pG->outcnt == outbufsiz )
        {
          if (pG->Frame.Verbose < 0)
            Notify( PF, ITRACE, "doing flush(), outcnt = %lu", pG->outcnt  );
          if ( ( error = flush ( pG, pG->realbuf, pG->outcnt, true ) )  != 0 )
            Notify( PF, 0, "unshrink:  flush() error (%d)", error );
          if (pG->Frame.Verbose < 0)
            Notify( PF, ITRACE, "done with flush()"   );
          pG->outptr = pG->realbuf;
          pG->outcnt = 0L;
        }
      }
    }

    /*-----------------------------------------------------------------------
     * Add new leaf (first character of newstr) to tree as child of oldcode.
     *-----------------------------------------------------------------------*/
    /* search for freecode */
    freecode = ( shrint )  ( lastfreecode + 1 );
    /* add if-test before loop for speed? */
    while ( parent[ freecode ]  != FREE_CODE )
      ++freecode;
    lastfreecode = freecode;
    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "]; newcode %d", freecode );

    Value[ freecode ]  = *newstr;
    parent[ freecode ]  = oldcode;
    oldcode = code;
  }
  while ( !pG->zipeof );

  /*---------------------------------------------------------------------------
   *     Flush any remaining data and return to sender...
   *---------------------------------------------------------------------------*/
  if ( pG->outcnt > 0L )
  {
    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "doing final flush(), outcnt = %lu", pG->outcnt  );
    if ( ( error = flush ( pG, pG->realbuf, pG->outcnt, true ) )  != 0 )
      Notify( PF, 0,  "unshrink:  flush() error (%d)", error );
    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "done with flush()"   );
  }
  return PK_OK;
}                               /* end function unshrink() */


/* ===========================================================================
 *      Function partial_clear()
 * No longer recursive...
 */
static void
partial_clear ( struct UGlobals *pG )
{
  register shrint code;

  /* clear all nodes which have no children (i.e., leaf nodes only) */

  /* first loop:  mark each parent as such */
  for ( code = BOGUSCODE + 1; code < HSIZE; ++code )
  {
    register shrint cparent = ( shrint )  ( parent[ code ]  & CODE_MASK );

    if ( cparent > BOGUSCODE && cparent != FREE_CODE )
      FLAG_BITS[ cparent ]  |= HAS_CHILD;  /* set parent's child-bit */
  }

  /* second loop:  clear all nodes *not* marked as parents; reset flag bits */
  for ( code = BOGUSCODE + 1; code < HSIZE; ++code )
  {
    if ( FLAG_BITS[ code ]  & HAS_CHILD )     /* just clear child-bit */
      FLAG_BITS[ code ]  &= ~HAS_CHILD;
    else
    {                      /* leaf:  lose it */
      if (pG->Frame.Verbose < 0)
        Notify( PF, ITRACE, "%d", code  );
      parent[ code ]  = FREE_CODE;
    }
  }
  return;
}
