
/* Crypt.h (full version) by Info-ZIP.   Last revised:  [see CR_VERSION_DATE]
*
* This header file is not copyrighted, and non-beta versions may be
* distributed without restriction.
* This version modified by Chris Vleghert for BCB/Delphi Zip.
** distributed under LGPL license ** see license.txt for details

*/

#ifndef __crypt_h /* don't include more than once */
#define __crypt_h

#define CR_MAJORVER     2
#define CR_MINORVER     7
#define CR_BETA_VER     ""
#define CR_VERSION_DATE "22 April 1997" /* last public release date */
#define CR_RELEASE
 
#define PWLEN         80                /* Input buffer size for reading encryption key. */
#define RAND_HEAD_LEN 12                /* Length of encryption random header.           */
         
typedef unsigned long Keys[3];
/* encode byte c, using temp t.  Warning: c must not have side effects.       */
//#define zencode( c, t ) ( t = decrypt_byte( pG->keys ), update_keys( c, pG->keys ), t ^ (c) )

/* decode byte c in place */
//#define zdecode( c )  update_keys( c ^= decrypt_byte( pG->keys ), pG->keys )
                                             
int _fastcall decrypt_byte( Keys keys );
int  _fastcall update_keys( int c, Keys keys); 
void _fastcall init_keys( char *passwd, Keys keys );
int _fastcall zencode(int c, Keys keys);
int _fastcall zdecode(int c, Keys keys);
//int decrypt_byte ( struct ZGlobals *pG );
//int       update_keys( int c, struct ZGlobals *pG );
//void      init_keys( char *passwd, struct ZGlobals *pG );

//void crypthead ( char *, ulg, FILE *, struct ZGlobals *pG );
//unsigned zfwrite ( void *, extent, extent, FILE *, struct ZGlobals *pG );
//void      crypthead( char *, ulg, HANDLE, struct ZGlobals *pG );

//unsigned  zfwrite( void *, /*extent,*/ extent, HANDLE, struct ZGlobals *pG );
#endif /* !__crypt_h */
