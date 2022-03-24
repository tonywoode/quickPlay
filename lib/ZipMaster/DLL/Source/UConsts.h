
/* This version modified by Chris Vleghert and Eric W. Engler
 * for BCB/Delphi Zip, Mar 11, 1998.
 */

/*---------------------------------------------------------------------------
 * consts.h
 * This file contains global, initialized variables that never change.  It is
 * included by unzip.c.
 *-------------------------------------------------------------------------*/

/* And'ing with mask_bits[n] masks the lower n bits */
ush const mask_bits[]  =
  {
    0x0000,
    0x0001, 0x0003, 0x0007, 0x000f, 0x001f, 0x003f, 0x007f, 0x00ff,
    0x01ff, 0x03ff, 0x07ff, 0x0fff, 0x1fff, 0x3fff, 0x7fff, 0xffff
  };
