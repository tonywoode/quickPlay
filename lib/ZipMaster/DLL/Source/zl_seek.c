// substitute ZLSEEK macro

#include "unzip.h"
//#include "unzpriv.h"


int zlseek( struct UGlobals * pG, long abs_offset )
{
  unsigned long request = ( abs_offset ) + pG->extra_bytes;
  unsigned long inbuf_offset = request % INBUFSIZ;
  unsigned long bufstart = request - inbuf_offset;

  //  if ( request < 0 )
  if ( request < ( unsigned )abs_offset && pG->extra_bytes > 0 )
  {
    return ( PK_BADERR );
  }
  else
    if ( bufstart != pG->cur_zipfile_bufstart )
    {
      pG->cur_zipfile_bufstart = vclSeek( pG, ( long )bufstart, SEEK_SET );
      if ( ( pG->incnt = vclRead( pG, ( char * ) pG->inbuf, INBUFSIZ ) ) <= 0 )
        return ( PK_EOF );
      pG->inptr = pG->inbuf + ( int )inbuf_offset;
      pG->incnt -= ( int )inbuf_offset;
    }
    else
    {
      pG->incnt += ( pG->inptr - pG->inbuf ) - ( int )inbuf_offset;
      pG->inptr = pG->inbuf + ( int )inbuf_offset;
    }

  return 0;
}





