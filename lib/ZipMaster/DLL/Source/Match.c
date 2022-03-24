#include <windows.h>
#include "Common.h"
#pragma hdrstop
/* This version modified by Chris Vleghert and Eric W. Engler
 * for BCB/Delphi Zip, Jun 18, 2000.
 * Port of util.c in ZIPDLL  I didn't like the MATCH.C for unzip.
 * match() is the function that we want, the rest is support.
 * Modified by R.Peters for speed
 * iswild() is also used from outside this module.
 */

//#include <stdio.h>
//#include <stdlib.h>
#include <ctype.h>
//#include <string.h>

//typedef  unsigned char uch;
#include "unzip.h"

// force Windows like handling of filenames
// ie path - everything upto final '\', name - upto final '.', extn - to end
#define __WINDOWS_LIKE 1

/* case mapping functions. case_map is used to ignore case in comparisons */
//#define case_map( c ) upper[( c ) & 0xff]

/* Country-dependent case map table */
//unsigned char upper[ 256 ] /*, lower[256]*/;
///static int inited=0;

/* Local functions */
int   pat_match(  const unsigned char *, const unsigned char * , const unsigned char *, const unsigned char * );
void  init_upper(  void );


/* ===========================================================================
 * EWE NOTE: a shell expression is just a wildcard used in fspec.
 * If p is a sh expression, a pointer to the first special
 * character is returned.  Otherwise, NULL is returned.
  *p :: Candidate sh expression.
 */
//char *isshexp( char *p ) {
// for ( ; *p; p++ ) {
//  if ( *p == '\\' && *(p + 1) ) p++;
//  else { /* unix/dos wildcards */
//   if ( *p == '?' || *p == '*' || *p == '[' ) return p;
//  }
// }
// return NULL;  /* no wildcards found */
//}

/* ===========================================================================
  *p :: Candidate sh expression.
 */
int iswild(  char *p )
{
  char c;
  if ( p )
    while ( *p )
      if ( ( c=*p++ ) ==(char)'*' || c==(char)'?' )
        return true;
  /*
    for ( ; *p; ++p ) {
           if ( *p == '\\' && *(p + 1) ) ++p;
      else if ( *p == '?' || *p == '*' || *p == '[' ) return true;
    }              */
  return false;
}

/* ===========================================================================
 * Nonrecursively compare the sh pattern p, with the string s,
 * and return 1 if they match, and 0 if they don't.
  *p :: sh pattern to match (ex: *.*).
  *s :: String to match it to (ex: FNAME.DAT).
  pe :: past end of pattern
  se :: past end of string
 */

static int pat_match(  const unsigned char *p, const unsigned char *s,
                       const unsigned char *pe, const unsigned char *se )
{
  uch c,cs;
  const uch *pa=0;  // pattern position last '*' - null = none
  const uch *sa;   // string position last '*'
  for ( ;; )
  {   // keep scanning until end or unrecoverable mismatch
    if ( s==se )
    { // run out of string - only '*''s allowed in pattern
      while (p<=pe && *p=='*' )
        p++;
      return ( p>=pe );  // ok if end of pattern
    }      
    if ( p>=pe )
      return 0; // ran out of pattern
    // more string to process
    if ( ( c=*p ) =='*' )
    {  // on mask
      if ( ++p>=pe )  // last char - rest of string must match
        return 1;
      // note scan point incase must back up
      pa=p;
      sa=s+1;
      continue;
    }
    // if successful match, inc pointers and keep trying
    if ( ( c=='?' )  || ( ( cs=*s ) ==c )  || ( case_map( cs ) ==case_map( c ) )  ||
         ( ( cs=='\\' || cs=='/' )  && ( c=='\\' || c=='/' ) ) )
    {
      p++;
      s++;
      continue;
    }
    // no match
    if ( !pa )       // any asterisk?
      return 0;  // no - no match
    p=pa;
    s=sa++;
  }
}

/* ===========================================================================
 * This is based on dosmatch() of ZIPDLL
 * Break the pattern and string into name and extension parts and match
 * each separately using shmatch().
  *s :: Filename to match against wildcard pattern.
  *p :: Dos wildcard pattern to match.
 */
int match(  char *s, char *p )
{
  //int match( const uch *s, const uch *p ) {
  const uch *pe, *p2, *p2e;  // pattern sections e=end
  const uch *se, *s2, *s2e;  // string sections 2=start of second part

#if __WINDOWS_LIKE
  const uch *p1, *p1e;
  const uch *s1, *s1e;
  uch c;

  if ( !s || !p )
  {                          // force reinitial uppers table
//    init_upper();
    return s==p;
  }
//  if ( !inited )                     /* RP only init once */
//    init_upper();
  if ( *p==(char)';' )
  {
    p++;
    // find sections
    se=s1e=0;
    s2e=( const uch * ) s;
    while ( ( c=*s2e ) !=0 )
    {
      if ( c==(char)'/' || c==(char)'\\' )
      {
        se=s2e;                 // will be end of path
        s1e=0;                  // ignore dots in path
      }
      else
        //  if (c=='.' && !s1e) // comment out to make last dot
        s1e=s2e;        // first dot - start of ext
      s2e++;
    }
    if ( !se )
    {                               // no path
      s1=se=( const uch * ) s;
    }
    else
    {
      s1=se+1;
    }
    if ( !s1e )
    {                              // no ext
      s1e=s2=s2e;
    }
    else
    {
      s2=s1e+1;
    }
    pe=p1e=0;
    p2e=( const uch * ) p;
    while ( ( c=*p2e ) !=0 )
    {
      if ( c==(char)'/' || c==(char)'\\' )
      {
        pe=p2e;                 // will be end of path
        p1e=0;                  // ignore dots in path
      }
      else
        //      if (c=='.' && !p1e)   // last dot - start of ext
        p1e=p2e;        // first dot - start of ext
      p2e++;
    }
    if ( !pe )
    {                               // no path
      p1=pe=( const uch * ) p;
    }
    else
    {
      p1=pe+1;
    }
    if ( !p1e )
    {                              // no ext
      p1e=p2=p2e;
    }
    else
    {
      p2=p1e+1;
    }
    // p..pe - path, p1..p1e - name, p2..p2e - ext
    if ( pat_match( ( const uch * ) p2, ( const uch * ) s2, p2e, s2e )
         && pat_match( ( const uch * ) p1, ( const uch * ) s1, p1e, s1e )
         && pat_match( ( const uch * ) p, ( const uch * ) s, pe, se ) )
      return 1;
    return 0;
  }
#else
  if ( !s || !p )
  {                          // force reinitial uppers table
//    init_upper();
    return s==p;
  }
//  if ( !inited )                     /* RP only init once */
//    init_upper();
#endif

  // find end of sections
  se=0;
  for ( s2e=( uch * ) s; *s2e; s2e++ )
  {
    if ( *s2e == (char)'.' )
      se=s2e;   // at last '.'
  }
  if ( se )      // has second part
    s2=se+1;
  else
  {
    se=s2e;    // end
    s2=s2e=0;
  }
  pe=0;
  for ( p2e=( uch* ) p; *p2e; p2e++ )
  {
    if ( *p2e == (char)'.' )
      pe=p2e;
  }
  if ( pe )      // has second part
    p2=pe+1;
  else
  {   // no period - no part 2
    pe=p2e;    // end
    if ( ( pe>( uch* ) p )  && ( *( pe-1 ) ==(char)'*' ) )   // ended in '*' - match any/no s2
      return pat_match( ( const uch * ) p, ( const uch * ) s, pe, se );
    else
      return s2?0:pat_match( ( const uch * ) p, ( const uch * ) s, pe, se ); // s2 must be empty
  }
  // p==>s , p2==>s2 , (.e=end section)

  if ( pat_match( ( const uch * ) p2, ( const uch * ) s2, p2e, s2e )
       && pat_match( ( const uch * ) p, ( const uch * ) s, pe, se ) )
    return 1;
  return 0;
}


