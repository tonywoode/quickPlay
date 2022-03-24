#include <windows.h>
#include "Common.h"
#pragma hdrstop
#include "Zip.h"
#include "enter.h"

/* ZGlobals.c
 * Copyright (C) 1990-1996 Mark Adler, Richard B. Wales, Jean-loup Gailly,
 * Kai Uwe Rommel, Onno van der Linden and Igor Mandrichenko.
 * Permission is granted to any individual or institution to use, copy, or
 * redistribute this software so long as all of the original files are included,
 * that it is not sold for profit, and that this copyright notice is retained.
 * This version modified by Chris Vleghert for BCB/Delphi Zip.
  ** distributed under LGPL license ** see license.txt for details
  RP 2006-03-23
*/
#define GLOBALS // Include definition of errors[] in zip.h (ZipErr.h)

#include "ZipErr.h"
#include "version.h"
         
#pragma option -a1
extern int      extra_lbits[LENGTH_CODES];  // extra bits for each length code
extern int      extra_dbits[D_CODES];       // extra bits for each distance code
extern int      extra_blbits[BL_CODES];     // extra bits for each bit length code
extern uch      bl_order[BL_CODES];
 /*
const char  upper[256] =
  {
    0
  };
const char  extend[256] =
  {
    1
  };    */
#pragma option -a.
 /*
void
Setup_upper( void )
{
  int i;
  for ( i = 0; i < 256; i++ )
    ( char )upper[i] = ( char ) ( unsigned char )i;
  CharUpperBuff( ( char * )upper + 1, 255 );
  ( char )upper[( int )'/'] = '\\'; // ignore diference
}

void
Setup_extend( void )
{
  unsigned char i;
  unsigned char *p = (unsigned char*) &extend[0];
//  int i;
  //for ( i = 0; i <= 255; i++ )
  *p++ = 0;
  for (i = 1; i; i++)
    *p++ = i;
//    ( char )extend[i] = ( char ) ( unsigned char )i;
//  CharToOemBuff( extend + 1, ( char * )extend + 1, 255 );
/*  for ( i = 0; i < 256; i++ )
    ( char )extend[i] = ( char )( extend[i] != ( char ) ( unsigned char )i );* /
}
   */
struct ZGlobals *Create_ZGlobals( ZipParms * C )
{
  struct ZGlobals *pG = ( struct ZGlobals *)MALLOC( sizeof( struct ZGlobals ) );
  if (!pG)
    return NULL;
  memset( pG, 0, sizeof( struct ZGlobals ) );
  Init_Frame((Frames *) pG);

  pG->Frame.OpKey = (OperKeys)C;
  pG->Frame.CallerVersion = C->fVersion;

  // Copy the window handle and context of caller to our global vars
  pG->Frame.global_handle = C->fHandle;
  pG->Frame.global_caller = C->fCaller;

  // point to the C++Builder/Delphi callback function
  pG->Frame.callb = C->ZCallbackFunc;

  // Static callback data
//  pG->Frame.CallBackData.Handle = pG->Frame.global_handle; // Window handle of caller
  pG->Frame.CallBackData.Caller = pG->Frame.global_caller; // object instance pointer
  ///of caller
  pG->Frame.CallBackData.Version = DELZIPVERS;
  pG->Frame.CallBackData.IsOperationZip = true;

  pG->pathput = 1;
//  pG->method = DEFLATE;
  pG->level = 9;
  pG->dirnames = 1;
  pG->noisy = 1;

  // linked list for new files to be added (not yet in ZIP)
  pG->fnxt = &pG->found;
  pG->adjust = 1;

  // mark file handles as invalid
  pG->zfile = INVALID_HANDLE_VALUE;
  pG->hTempzf = INVALID_HANDLE_VALUE;
  pG->hInz = INVALID_HANDLE_VALUE;
  pG->hOutz = INVALID_HANDLE_VALUE;
  pG->hInfile = INVALID_HANDLE_VALUE;

  // User can specify if he wants to skip compressing these types:
  // List of special suffixes
  // v1.6 removed: pG->special =
  // ".gif:.png:.Z:.zip:.zoo:.arc:.lzh:.arj:.taz:.tgz:.lha";
  pG->dll_handles_errors = 1;       // By dflt, this DLL will generate
  ///error msg boxes    
  if ( C->fQuiet || !C->fHandle )
  { // quiet operation -q
    pG->noisy = 0; // shut us up!
    pG->dll_handles_errors = 0; // All error msgs passed to caller via callback function
  }

  if ( C->fVerboseEnabled || C->fTraceEnabled ) // Frame.Verbose messages -v
  {
    pG->noisy = 1;
    pG->Frame.Verbose = C->fTraceEnabled ? -1 : 1;
  }

  // init_upper ( pG ); // build case map table
  pG->read_buf = file_read;         // a function
  pG->action = ADD;                 // Must be ADD - the default action
  pG->zipstate = -1;
  pG->wild_match_all = "*.*";

  pG->l_desc.dyn_tree = pG->dyn_ltree;
  pG->l_desc.static_tree = pG->static_ltree;
  pG->l_desc.extra_bits = extra_lbits;
  pG->l_desc.extra_base = LITERALS + 1;
  pG->l_desc.elems = L_CODES;
  pG->l_desc.max_length = MAX_BITS;

  pG->d_desc.dyn_tree = pG->dyn_dtree;
  pG->d_desc.static_tree = pG->static_dtree;
  pG->d_desc.extra_bits = extra_dbits;
  pG->d_desc.elems = D_CODES;
  pG->d_desc.max_length = MAX_BITS;

  pG->bl_desc.dyn_tree = pG->bl_tree;
  pG->bl_desc.extra_bits = extra_blbits;
  pG->bl_desc.elems = BL_CODES;
  pG->bl_desc.max_length = MAX_BL_BITS;

  return pG;
}

void Destroy_ZGlobals( struct ZGlobals *pG)
{                     
  ZipCleanup(pG);   // something may have failed
  Clean_Frame( (Frames *)pG);
  free( pG );
}
 /*
// only for non re-entrant older versions
struct ZGlobals *Current_ZGlobals( void )
{
  return (struct ZGlobals *)Get_Current_Oper();
}  */

int Clear_Oper(struct OpFrame* Op)
{
  if (!Op || Op->OpTyp != ZIPOPER)
    return -1;
  __try
  {
    Op->OpTyp = 0;
    Destroy_ZGlobals( (struct ZGlobals *)Op );   // is ZGlobals *
  }
  __except ( 1 )
  {
//    Op->ME = NULL;
  }
  return 0;
}

