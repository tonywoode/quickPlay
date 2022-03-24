#include <windows.h>
#include "Common.h"
#pragma hdrstop
#include "Zip.h"

/* Util.c
 * Copyright (C) 1990-1996 Mark Adler, Richard B. Wales, Jean-loup Gailly,
 * Kai Uwe Rommel, Onno van der Linden and Igor Mandrichenko,
 * This version modified by Chris Vleghert and Eric Engler for BCB/Delphi Zip.
  ** distributed under LGPL license ** see license.txt for details
*/
#include <ctype.h>

// Local functions
int pat_match( const unsigned char *p, const unsigned char *s, const unsigned char *pe,
               const unsigned char *se );

// Nonrecursively compare the sh pattern p, with the string s, and return 1
//   if they match, and 0 if they don't. p :: sh pattern to match (ex: *.*). s
//   :: String to match it to (ex: FNAME.DAT). pe :: past end of pattern se ::
//   past end of string
static int
pat_match( const unsigned char *p, const unsigned char *s, const unsigned char *pe,
           const unsigned char *se )
{
  uch       c,
  cs;
  const uch *pa = 0;      // pattern position last '*' - null = none
  const uch *sa;          // string position last '*'
  for ( ;; )
  {                       // keep scanning until end or unrecoverable
    ///mismatch
    if ( s == se )
    {                     // run out of string - only '*''s allowed in
      ///pattern
      while ( *p == '*' )
        p++;
      return ( p >= pe ); // ok if end of pattern
    }

    // more string to process
    if ( (c = *p) == '*' )
    {                     // on mask
      if ( ++p >= pe )    // last char - rest of string must match
        return 1;

      // note scan point incase must back up
      pa = p;
      sa = s + 1;
      continue;
    }

    // if successful match, inc pointers and keep trying
    if ( ((cs = *s) == c) || (case_map( cs ) == case_map( c )) || (c == '?' && cs) )
    {
      p++;
      s++;
      continue;
    }

    // no match
    if ( !pa )            // any asterisk?
      return 0;           // no - no match
    p = pa;
    s = sa++;
  }
}

// This is based on dosmatch() of ZIPDLL Break the pattern and string into
//   name and extension parts and match each separately using shmatch(). s ::
//   Filename to match against wildcard pattern. p :: Dos wildcard pattern to
//   match.
int __fastcall
dosmatch( const char *p, const char *s )
{
  const uch *pe,
  *p2,
  *p2e;       // pattern sections e=end
  const uch  *se,
  *s2,
  *s2e;       // string sections 2=start of second part

  // find end of sections
  char        c;
  for ( s2e = (uch *)s; *s2e; s2e++ )
    ;

  // find end
  se = s2e - 1;
  while ( *se != '.' )
  {
    if ( *se == '\\' || *se == '/' || --se < (uch *)s )
    {
      se = 0;             // no extn
      break;
    }
  }

  if ( se )               // has second part
    s2 = se + 1;
  else
  {
    se = s2e;             // end
    s2 = s2e = 0;
  }

  for ( p2e = (uch *)p; *p2e; p2e++ )
    ;

  // find end
  pe = p2e - 1;
  while ( (c = *pe) != (char)'.' )
  {
//    if ( c == '\\' || c == '/' || --pe < (uch *)p )
    if ( c == (char)'\\' || c == (char)'/' || pe <= (uch *)p )
    {
      pe = 0;             // no extn
      break;
    }
    --pe;
  }

  if ( pe )               // has second part
    p2 = pe + 1;
  else
  {           // no period - no part 2
    pe = p2e; // end
    if ( (pe > (uch *)p) && (*(pe - 1) == (char)'*') )  // ended in '*' - match
      ///any/no s2
      return pat_match((uch *)p, (uch *)s, pe, se );
    else
      return s2 ? 0 : pat_match( (uch *)p, (uch *)s, pe, se );    // s2 must be empty
  }

  // p==>s , p2==>s2 , (.e=end section)
  if ( pat_match( (uch *)p2, (uch *)s2, p2e, s2e ) && pat_match( (uch *)p, (uch *)s, pe, se ) )
    return 1;
  return 0;
}

// EWE NOTE: a shell expression is just a wildcard used in fspec. If p is a
//   sh expression, a pointer to the first special character is returned.
//   Otherwise, NULL is returned. p :: Candidate sh expression.
const char *__fastcall IsShExp ( const char *p )
{
  if (strncmp(p, "\\\\?\\", 4) == 0)
    p+=4;
  for ( ; *p; p++ )
  {
    // dos wildcards { V1.4 removed unix '[' }
    if ( *p == (char)'?' || *p == (char)'*' )
      return p;
  }

  return NULL;        // no wildcards found
}

// Search for b in the pointer list a[0..n-1] using the compare function
//   cmp(b, c) where c is an element of a[i] and cmp() returns negative if b <
//   *c, zero if *b == *c, or positive if *b > *c. If *b is found, search
//   returns a pointer to the entry in a[], else search() returns NULL. The
//   nature and size of *b and *c (they can be different) are left up to the
//   cmp() function. A binary search is used, and it is assumed that the list
//   is sorted in ascending order. b :: Pointer to value to search for. a ::
//   Table of pointers to values, sorted. n :: Number of pointers in a[]. cmp
//   :: Comparison function.
typedef int ( *CmpFunc ) ( const void *, const void * );
void **
search( void *b, void **a, extent n, CmpFunc cmp )
{
  void  **i;          // pointer to midpoint of current range
  void  **l;          // pointer to lower end of current range
  void  **u;          // pointer to upper end of current range
  int   r;            // result of (*cmp)() call
  l = ( void ** )a;
  u = l + ( n - 1 );
  while ( u >= l )
  {
    i = l + ( ( unsigned )(u - l) >> 1 );
    if ( (r = (*cmp) (b, ( char * ) * ( struct zlist ** )i)) < 0 )
      u = i - 1;
    else
      if ( r > 0 )
        l = i + 1;
      else
        return ( void ** )i;
  }

  return NULL;        // If b were in list, it would belong at l
}

// Compare the two strings ignoring case, and correctly taking into account
//   national language characters. If equal return 0 else != 0.
int _fastcall
namecmp( const char *string1, const char *string2 )
{
  for ( ;; )
  {
    int d = ( int )case_map( *string1 ) - ( int )case_map( *string2 );

    if ( d || *string1 == 0 || *string2 == 0 )
      return d;

    string1++;
    string2++;
  }
}

// ? Extended test if string contains any extended characters
int _fastcall
Extended( const char *string )
{
  char  c;
  while ( (c = *string++) != 0 )
    if ( extend[( unsigned char )c] )
      return 1;
  return 0;
}

// ? CompNameExt compare ends of strings for name.ext
int __fastcall
SameNameExt( const char *fname, const char *oname )
{
  char        f,
  o;
  const char  *oe = oname;
  const char  *fe = fname;
  if ( !fname || !oname )
    return 0;         // cannot do it
  while ( *oe )
    oe++;
  while ( *fe )
    fe++;
  while ( --fe >= fname && --oe >= oname )
  {
    f = case_map( *fe-- );
    o = case_map( *oe-- );
    if ( f == (char)'\\' || o == (char)'\\' )
      return f != o;  // 1; // matched to last path
    ///separator
    if ( f != o )     // different ?
      return 0;

    // same - continue
  }
  return ( fe >= fname || oe >= oname ) ? 0 : 1;
}
