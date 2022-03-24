
/* crypt.h (full version) by Info-ZIP.   Last revised:  [see CR_VERSION_DATE]
 * This version modified by Chris Vleghert and Eric W. Engler
 * for BCB/Delphi Zip, May 27, 1999.
 *
 * This header file is not copyrighted, and non-beta versions may be
 * distributed without restriction.
 */

#ifndef __ucrypt_h               /* don't include more than once */
#define __ucrypt_h

#include "crypt.h"
 
#define PWLEN  80               /* input buffer size for reading encryption key */
#define RAND_HEAD_LEN  12       /* length of encryption random header */

int decrypt ( struct UGlobals *pG );
 
#endif /* !__crypt_h */
