#include <windows.h>
#include "common.h"
#pragma hdrstop
//#include <stdarg.h>
//#include "UserCB.h"

/* DLLClBk.c
 * Copyright (C) 1997 Mike White and Eric W. Engler
 * Permission is granted to any individual or institution to use, copy, or
 * redistribute this software so long as all of the original files are included,
 * that it is not sold for profit, and that this copyright notice is retained.
 * This version modified by Chris Vleghert BCB/Delphi Zip.
 * modified R. Peters
 ** distributed under LGPL license ** see license.txt for details
 * 1.79.00.00
*/


/* This provides the calling program with updated info on what the DLL
 * is doing.  Regardless of the type of call being made, the user's
 * function must have a spin of the Windows message loop.  In fact, even
 * if user isn't using a progress bar, he should still spin the msg
 * loop upon getting these callbacks (but he doesn't need to do anything
 * else).  In Delphi, "Application.ProcessMessages;" or
 *         in BCPPB   "Application->ProcessMessages(); spins the loop.
 * Here are the types of calls:
 *
 *
 *   ActionCode = 0, zacTick, just roll the loop
 *
 *   ActionCode = 1, zacItem,
 *      we're starting a zip operation on a new file
 *   (O) FileSize(u64) = filesize of file we're going to operate on
 *   (O) MsgP = pathname of file
 *   (O) Written (u64) = [Zip] Bytes written
 *   IMPORTANT: The user's function must do the math for the progress
 *   bar upon getting this call.  See the Delphi sample application.
 *
 *   ActionCode = 2, zacProgress,
 *      increment the progress bar
 *      These calls will occur after every 32K of input file has been
 *      processed. One additional call is made at the end of each file,
 *      just to make sure the progress bar is max'ed out - this is also
 *      critical for files less than 32K in size (this last one will be
 *      their only one).
 *   (O) FileSize(u64) = filesize of file we're going to operate on
 *   (O) Written (u64) = [Zip] Bytes written
 *
 *   ActionCode = 3, zacEndOfBatch,
 *      we're done with a batch of files
 *          - program flow will quickly return to the user's program.
 *   NOTE: the end of a every file will always be followed by an
 *         action of 1 or 3, so a separate call for end of one file
 *         isn't needed.
 *   (O) Written (u64) = [Zip] Bytes written
 *
 *   ActionCode = 4, zacComment, a routine message is being passed
 *   (O) Arg1 = error_code - code corresponding to message (not widely used yet)
 *   (O) MsgP = text of message
 *
 *   ActionCode = 5, zacCount,
 *          the total number of files is being passed.
 *   (O) Arg1 = The total number of files.
 *
 *   ActionCode = 6, zacSize,
 *      the total file size is being passed.
 *   (O) FileSize (u64) = The total file size
 *
 *   ActionCode = 7, zacNewName,
 *      the internal filename is being passed.
 *   (O) MsgP2 = pointer to full filespec
 *   (O) MsgP = the internal filename as the dll thinks it should be.
 *   (I) ActionCode = -1 if changed
 *   (I) Msg = the new internal filename
 *
 *   ActionCode = 8, zacPassword,
 *      get Password
 *   (O) Arg1 = request count
 *   (O) MsgP = filename
 *   (I) ActionCode = -1 if has password
 *       (I) Msg = password
 *       (I) Arg1 = request count
 *   (I) ActionCode = -2 if responded 'cancel'
 *       (I) Arg1 = request count   
 *   (I) ActionCode = -3 if responded 'cancel all'
 *       (I) Arg1 = request count
 *
 *   Actioncode = 9, zacCRCError,
 *      CRC32 error during Extract
 *   (O) Arg1 = Found CRC
 *   (O) Arg2 = Stored/Expected CRC
 *   (O) MsgP = File for which the CRC check went wrong.
 *   (I) ActionCode -1 = extract quietly
 *                  -2 = extract with warning [default]
 *                  -3 = delete
 *
 *   Actioncode = 10, zacOverwrite,
 *      Extract(UnZip) Overwrite ask.
 *   (O) Arg3 = 'older'
 *   (O) Arg2 = Index
 *   (O) Arg1 = Overwrite_All
 *   (O) MsgP = filename
 *   (I) ActionCode -1 = overwrite
 *          -2 = don't overwrite
 *
 *   Actioncode = 11, zacSkipped,
 *      Skipped during Extract
 *   (O) Arg1 = error code
 *   (O) Arg2 = type
 *   (O) MsgP = filename
 *
 *   Actioncode = 12, zacComment,
 *      FileComment while adding ( ZipDll only )
 *   (O) MsgP = filename
 *   (O) MsgP2 = old comment
 *   (I) ActionCode = -1 if comment changed
 *       (I) Arg1 = length of new comment
 *       (I) Msg = new comment
 *
 *   Actioncode = 13, zacStream,
 *      Adjust unzip stream size
 *   (O) FileSize (u64) = required size
 *   (I) ActionCode = -1 if ok
 *       (I) Msg2P = Memory
 *
 *   Actioncode = 14, zacData,
 *      Set Extra Data  or Compression level
 *   (O) Arg1 = size of data
 *   (O) Arg2 = Compression level
 *   (O) MsgP = filename
 *   (O) MsgP2 = pointer to data
 *   (I) ActionCode & 0xff0f = 0xff0f if data changed
 *       (I) Arg1 = new size of data
 *       (I) Msg = new data (< 512 bytes)
 *       (I) MsgP2 = new data (> 512 bytes) (data must remain until next callback)
 *   (I) ActionCode &0xff0e = 0xff0e if level changed
 *       (I) (ActionCode & 0xf0) >> 4 = new level (0..9)
 *
 *   ActionCode = 15, zacXItem, we're starting a zip operation on a new file
 *   (O) Arg1 = type - 1 = archive bit 2 = move file
 *   (O) Filesize = filesize of file we're going to operate on
 *   (O) MsgP = pathname of file
 *
 *   ActionCode = 16, zacXProgress, increment the progress bar
 *      These calls will occur after every 32K of input file has been
 *      processed. One additional call is made at the end of each file,
 *      just to make sure the progress bar is max'ed out - this is also
 *      critical for files less than 32K in size (this last one will be
 *      their only one).
 *   (O) Arg1 = type
 *   (O) FileSize (u64) = size
 *
 *   ActionCode = 17, zacExtName,
 *      change extract name
 *   (O) MsgP2 = ? null
 *   (O) MsgP = filename
 *   (I) ActionCode = -1 if changed
 *      (I) Msg = new name
 *
 *   ActionCode = 17, zacKey
 *      set or clear operation key
 *   (O) Arg1 = key
 *
 *
*/

/* ===========================================================================
 * This calls the application program and passes status info.
 */
int __fastcall User_CB(Frames *pf, unsigned Action)
{
  unsigned /*i, */ ret;
  struct ZCallBackStruct *cb;
  if ( pf->callb && pf->Abort_Flag <= GA_ABORT )
  {
    cb = &pf->CallBackData;
    cb->ActionCode = Action;
    __try
    {
      ret = pf->callb(cb->Caller, cb ); // call user's program
    }
    __except( 1 )
    {
      pf->Abort_Flag = GA_EXCEPT2;
    }

    if ( ret )    // vcl asked to abort
      pf->Abort_Flag |= (ret == Callback_Except_No? GA_EXCEPT : GA_CANCEL);

    if (pf->Abort_Flag &&  pf->CallBackData.ActionCode < 0)
      pf->CallBackData.ActionCode = 255;  // invalid but > 0
  }
  return pf->Abort_Flag;
}
