#include <windows.h>
#include "Common.h"
#pragma hdrstop
/*
* crypt.c (full version) by Info-ZIP.      Last revised:  [see crypt.h]
*
* This code is not copyrighted and is put in the public domain.  The
* encryption/decryption parts (as opposed to the non-echoing password
* parts) were originally written in Europe; the whole file can there-
* fore be freely distributed from any country except the USA.  If this
* code is imported into the USA, it cannot be re-exported from from
* there to another country.  (This restriction might seem curious, but
* this is what US law requires.) */

/* This version modified by Chris Vleghert and Eric W. Engler
* for BCB/Delphi Zip, Sep 22, 2000. */

/* This encryption code is a direct transcription of the algorithm from
* Roger Schlafly, described by Phil Katz in the file appnote.txt.  This
* file (appnote.txt) is distributed with the PKZIP program (even in the
* version without encryption capabilities). */

#define ZCRYPT_INTERNAL

#include "unzip.h"
#define ziperr( c, h ) return

#include "crypt.h"
#include "ucrypt.h"

static int testp( struct UGlobals * pG, uch * h );
static int testkey( struct UGlobals * pG, uch * h, char * key );
//#define CRC32(c, b) (crc_table[((int)(c) ^ (b)) & 0xff] ^ ((c) >> 8))

#  define NEXTBYTE  (--pG->incnt >= 0 ? (int)(*pG->inptr++) : readbyte( pG ))
/* ===========================================================================
* Get the password and set up keys for current zipfile member.  Return * PK_ class error. */
int decrypt( struct UGlobals * pG )
{
  ush b;
  int n, n1;//, r;
  uch h[RAND_HEAD_LEN];

  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE,  "in crypt.c, [incnt = %d]: ", pG->incnt ); //stout

  /* if ((pG->pwdarg != NULL) && (lstrlen(pG->pwdarg) > 0)) Trace( (pG, "pwd passed in via pG->pwdarg: %s", pG->pwdarg) );
  if (pG->P_flag == TRUE) Trace( (pG, "pG->P_flag was TRUE at beg of decrypt()") ); else
  Trace( (pG, "pG->P_flag was FALSE at beg of decrypt()") ); */

  /* get header once (turn off "encrypted" flag temporarily so we don't * try to decrypt the same data twice) */
  pG->pInfo->encrypted = false;
  defer_leftover_input( pG );
  for ( n = 0; n < RAND_HEAD_LEN; n++ )
  {
    b = ( ush )NEXTBYTE;
    /* RCV: ush added */
    h[n] = ( uch )b;
    //Trace( (pG, " (%02x)", h[n]) );  //stdout
  }
  undefer_input( pG );
  pG->pInfo->encrypted = true;

//  if (pG->Frame.Verbose < 0)
//    Notify( PF, ITRACE, "EWE - in crypt.c, near pG->newzip test"  );

  if ( !pG->PwdReqCount )
    return PK_WARN;
  if ( pG->newzip )// || pG->Frame.CallerVersion >= 160 )
  {
    pG->newzip = false;
    if (pG->Frame.Verbose < 0)
      Notify( PF, ITRACE, "newzip was set to false"  );

    if ( pG->P_flag == true )
    {
      /* user gave password on command line */
      if (pG->Frame.Verbose < 0)
        Notify( PF, ITRACE, "user set password");//=%s", pG->pwdarg);
      if ( !pG->key )
      {
        if (pG->Frame.Verbose < 0)
          Notify( PF, ITRACE, "global key was NULL"   );
        if ( ( pG->key = ( char * ) MALLOC( PWLEN + 1 ) ) == NULL )
          return PK_MEM2;
        strncpy( pG->key, pG->pwdarg, PWLEN ); // 1.6013 put back again
      }
      strncpy( pG->key, pG->pwdarg, PWLEN + 1 ); // 1.6013 ( removed !pG->Key || ... )
    } 
  }

//  if (pG->Frame.Verbose < 0)
//    Notify( PF, ITRACE, "EWE- near 'have key already' test"   );
  /* if have key already, test it; else allocate memory for it */
  if ( pG->key )
  {
    if ( !testp( pG, h ) )
    {
      if (pG->Frame.Verbose < 0)
        Notify( PF, ITRACE, "existing pwd OK"   );
      return PK_COOL;
      /* existing password OK (else prompt for new) */
    }
    else
      if ( pG->nopwd )
        return PK_WARN;
    /* user indicated no more prompting                              */
  }
  else
    if ( ( pG->key = ( char * ) MALLOC( PWLEN + 1 ) ) == ( char * ) NULL )
      return PK_MEM2;
  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "Requesting password"   );

  /* try a few keys */
  n = pG->PwdReqCount;
  n1 = 15;
  do
  {
      // Call the component with a request for a password
      _CB_.Arg1 = n;
      _CB_.MsgP = pG->filename;
      User_CB(PF, zacPassword);
      // -1 = pw, -2 = cancel, -3 = cancel all
      if (_CB_.ActionCode < -2)         // gave no password
      {
        pG->nopwd = true;
        n1 = 1;
      }
      n = min( ( int )_CB_.Arg1 & 0x0F, n1 );
      if (_CB_.ActionCode == -1)        // have password
      {
        lstrcpy( pG->key, _CB_.Msg );
        if ( !testp( pG, h ) )
          return PK_COOL;
      }
  }
  while ( --n > 0 && --n1 > 0 && !pG->Frame.Abort_Flag );

  return PK_WARN;
}
/* end function decrypt() */


/* ===========================================================================
* Test the password.  Return -1 if bad, 0 if OK. */
static int testp( struct UGlobals * pG, uch * h )
{
  int r;
#if ( defined( STR_TO_CP1 ) || defined( STR_TO_CP2 ) || defined( STR_TO_CP3 ) )
  char * key_translated;
#endif
  /* On systems with "obscure" native character coding (e.g., EBCDIC),
  * the first test translates the password to the "main standard" * character coding. */
#ifdef STR_TO_CP1
  /* allocate buffer for translated password */
  if ( ( key_translated = (char *) MALLOC( lstrlen( pG->key ) + 1 ) ) == ( char * ) NULL )
    return -1;
  /* first try, test password translated "standard" charset */
  r = testkey( pG, h, STR_TO_CP1( key_translated, pG->key ) );
#else
  /* first try, test password as supplied on the extractor's host */
  r = testkey( pG, h, pG->key );
#endif

#ifdef STR_TO_CP2
  if ( r != 0 )
  {
# ifndef STR_TO_CP1
    /* now prepare for second (and maybe third) test with translated pwd */
    if ( ( key_translated = MALLOC( lstrlen( pG->key ) + 1 ) ) == ( char * ) NULL )
      return -1;
# endif
    /* second try, password translated to alternate ("standard") charset */
    r = testkey( pG, h, STR_TO_CP2( key_translated, pG->key ) );
# ifdef STR_TO_CP3
    if ( r != 0 ) /* third try, password translated to another "standard" charset */
      r = testkey( pG, h, STR_TO_CP3( key_translated, pG->key ) );
# endif
    # ifndef STR_TO_CP1
    FREE( key_translated );
# endif
  }
#endif /* STR_TO_CP2 */

#ifdef STR_TO_CP1
  FREE( key_translated );
  if ( r != 0 )
  {
    /* last resort, test password as supplied on the extractor's host */
    r = testkey( pG, h, pG->key );
  }
#endif
  return r;
}

/* end function testp() */


/* ===========================================================================
*h   :: Decrypted header.
*key :: Decryption password to test. */
static int testkey( struct UGlobals * pG, uch * h, char * key )
{
  ush b;
#ifdef ZIP10
  ush c;
#endif

  int n;
  uch * p;
  uch hh[RAND_HEAD_LEN];
  /* decrypted header */

  /* set keys and save the encrypted header */
  init_keys( key, pG->keys );
  memcpy( hh, h, RAND_HEAD_LEN );

  /* check password */
  for ( n = 0; n < RAND_HEAD_LEN; n++ )
  {
    hh[n] = (uch) zdecode( hh[n], pG->keys ); 
  }

/*  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "  lrec.crc= %08lx  crec.crc= %08lx  pInfo->ExtLocHdr= %s",
            pG->lrec.crc32, pG->pInfo->crc,
            pG->pInfo->ExtLocHdr ? "true" : "false"  ); //stdout
  if (pG->Frame.Verbose < 0)
    Notify( PF, ITRACE, "  incnt = %d  unzip offset into zipfile = %ld", pG->incnt,
            pG->cur_zipfile_bufstart + pG->inptr - pG->inbuf   ); //stdout
*/
  /* same test as in zipbare(): */

#ifdef ZIP10                    /* check two bytes */
  c = hh[RAND_HEAD_LEN - 2], b = hh[RAND_HEAD_LEN - 1];
//  if (pG->Frame.Verbose < 0)
//    Notify( PF, ITRACE, "  (c | (b<<8)) = %04x  (crc >> 16) = %04x  lrec.time = %04x",
//            ( ush )( c | ( b << 8 ) ), ( ush )( pG->lrec.crc32 >> 16 ),
//            pG->lrec.last_mod_file_time   ); //stdout
  if ( ( ush )( c | ( b << 8 ) ) !=
       ( pG->pInfo->ExtLocHdr ? pG->lrec.last_mod_file_time : ( ush )( pG->lrec.crc32 >> 16 ) ) )
    return -1;
  /* bad */
#else
  b = hh[RAND_HEAD_LEN - 1];
//  if (pG->Frame.Verbose < 0)
//    Notify( PF, ITRACE, "  b = %02x  (crc >> 24) = %02x  (lrec.time >> 8) = %02x",
//            b, ( ush )( pG->lrec.crc32 >> 24 ),
//            ( pG->lrec.last_mod_file_time >> 8 )  ); //stdout
  if ( b != ( pG->pInfo->ExtLocHdr ? pG->lrec.last_mod_file_time >> 8 : ( ush )( pG->lrec.crc32 >> 24 ) ) )
    return -1;
  /* bad */
#endif
  /* password OK:  decrypt current buffer contents before leaving */
  for ( n = ( unsigned /*long */)pG->incnt > (unsigned) pG->csize ? ( int )pG->csize : pG->incnt, p = pG->inptr; n--; p++ )
    *p = (uch) zdecode( *p, pG->keys );
  return 0;
  /* OK */
}
/* end function testkey() */

 



