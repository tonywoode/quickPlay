
/* ZipErr.h
* Copyright (C) 1990-1996 Mark Adler, Richard B. Wales, Jean-loup Gailly,
* Kai Uwe Rommel, Onno van der Linden and Igor Mandrichenko.
* Permission is granted to any individual or institution to use, copy, or
* redistribute this software so long as all of the original files are included,
* that it is not sold for profit, and that this copyright notice is retained.
* This version modified by Chris Vleghert and Eric Engler for BCB/Delphi Zip.
 ** distributed under LGPL license ** see license.txt for details

*/
#ifndef __ZipErr_h
  #define __ZipErr_h

/*
 * ZEN (Zip Error New) is composed as folows:
 * a unsigned long (32 bits) Byte4 Byte3 Byte2 Byte1
 * Byte 1       Signed; (Old <= dll version 1.502) ZE_ error class (-5 to 18) (-2,17 not used)
 *                      Error return values.  The values 0..4 and 12..18 follow the conventions
 *                              of PKZIP.   The values 4..10 are all assigned to "insufficient memory"
 *                      by PKZIP, so the codes 5, 9 and 10 are used here for other purposes.
 *                              also 6, 7, 8 and 17 are not used yet.
 *                              Return codes of password fetches (negative = user abort; positive = error)
 *                              ZEN_PW_ERROR was 5 but had to make it -5 since ZEN_LOGIC uses 5
 *                              ZEN_PW_CANCEL was -1 changed to -3 .. -1 inuse
 *                              ZEN_PW_CANCELALL was -2 changed to -4
 * Byte 2       Sequence number in the ZEN_ Error class: 1..255
 * Byte 3       Error string number in errors[] array
 * Byte 4       Not used yet.
 */
#define ZEN_PW_ERROR      - 5       /* = PK_MEM2 : failure (no mem, no tty, ...)                     */
#define ZEN_PW_CANCELALL  - 4       /* no password, skip any further pwd. request                            */
#define ZEN_PW_CANCEL     - 3       /* No password available (for this entry)                                */
#define ZEN_PW_ENTERED    0         /* got some password string; use/try it                                  */

#define ZEN_MISS          - 1       /*                                                       */
#define ZEN_MISS01        0x0001FF  /*N Tried to overwrite a dir with a file or vice-versa   */
#define ZEN_MISS02        0x0002FF  /* in Win32Zip.c Wild()                                  */
#define ZEN_MISS03        0x0003FF  /* in Win32Zip.c procname()                              */
#define ZEN_MISS04        0x0004FF  /* in Win32Zip.c procname()                              */
#define ZEN_MISS05        0x0005FF  /* in Win32Zip.c procname()                              */

#define ZEN_OK            0         /* Success                                               */

#define ZEN_EOF           2         /* Unexpected end of zip file                                    */
#define ZEN_EOF01         0x020102  /* in DllZip.c zipmain()                         */
#define ZEN_EOF02         0x020202  /* in ZipFile.c AfterError1()                    */
#define ZEN_EOF03         0x020302  /* in ZipFile.c readzipfile()                    */
#define ZEN_EOF04         0x020402  /* in ZipFile.c zipcopy()                        */
#define ZEN_EOF05         0x020502  /* in ZipFile.c zipcopy()                        */

#define ZEN_FORM          3         /* Zip file structure error                              */
#define ZEN_FORM01        0x030103  /* in ZipFile.c readzipfile()                            */
#define ZEN_FORM02        0x030203  /* in ZipFile.c readzipfile()                            */
#define ZEN_FORM03        0x030303  /* in ZipFile.c readzipfile()                            */
#define ZEN_FORM04        0x030403  /* in ZipFile.c readzipfile()                            */
#define ZEN_FORM05        0x030503  /* in ZipFile.c readzipfile()                            */
#define ZEN_FORM06        0x030603  /* in ZipFile.c readzipfile() Zip Structure Central - Local problem */
#define ZEN_FORM07        0x030703  /* in ZipFile.c readzipfile()                            */
#define ZEN_FORM08        0x030803  /* in ZipFile.c readzipfile()                            */
#define ZEN_FORM09        0x030903  /* in ZipFile.c readzipfile()                            */
#define ZEN_FORM10        0x030A03  /* in ZipFile.c readzipfile()                            */
#define ZEN_FORM11        0x030B03  /* in ZipFile.c readzipfile()                            */

#define ZEN_MEM           4         /* Out of memory                                                 */
#define ZEN_MEM01         0x040104  /* in crctab.c make_crc_table()                  */
#define ZEN_MEM02         0x040204  /* in deflate.c lm_init()                        */
#define ZEN_MEM03         0x040304  /* in deflate.c lm_init()                        */
#define ZEN_MEM04         0x040404  /* in DllMain.c ZipDllExec()                     */
#define ZEN_MEM05         0x040504  /* in ZipDll.c GetFilters()                      */
#define ZEN_MEM06         0x040604  /* ZIPDLL was not passed a password              */
#define ZEN_MEM07         0x040704  /* in ZipDll.c zipmain()                         */
#define ZEN_MEM08         0x040804  /*N Zipfile name alloc error                     */
#define ZEN_MEM09         0x040904  /*N Ziptemp path alloc error                     */
#define ZEN_MEM10         0x040A04  /*N Temppath alloc error 2                       */
#define ZEN_MEM11         0x040B04  /* in ZipDll.c zipmain()                         */
#define ZEN_MEM12         0x040C04  /* in ZipDll.c zipmain()                         */
#define ZEN_MEM13         0x040D04  /* in FileIO.c check_dup()                       */
#define ZEN_MEM14         0x040E04  /* in FileIO.c newname()                         */
#define ZEN_MEM15         0x040F04  /* in FileIO.c newname()                         */
#define ZEN_MEM16         0x041004  /* in FileIO.c newname()                         */
#define ZEN_MEM17         0x041104  /* in FileIO.c fcopy()                           */
#define ZEN_MEM18         0x041204  /* in Zipup.c zipup()                            */
#define ZEN_MEM19         0x041304  /* in Win32Zip.c Wild()                          */
#define ZEN_MEM20         0x041404  /* in Win32Zip.c Wild()                          */
#define ZEN_MEM21         0x041504  /* in Win32Zip.c Wild()                          */
#define ZEN_MEM22         0x041604  /* in Win32Zip.c procname()                      */
#define ZEN_MEM23         0x041704  /* in Win32Zip.c procname()                      */ 
#define ZEN_MEM24         0x041804  /* in FileIO.c EraseFile()                       */

//#define ZEN_MEM24                     0x041804        /* in Win32Zip.c set_extra_field()               */
#define ZEN_MEM25   0x041904        /* in ZipFile.c AfterError1()                    */
#define ZEN_MEM26   0x041A04        /* in ZipFile.c readzipfile()                    */
#define ZEN_MEM27   0x041B04        /* in ZipFile.c readzipfile()                    */
#define ZEN_MEM28   0x041C04        /* in ZipFile.c readzipfile()                    */
#define ZEN_MEM29   0x041D04        /* in ZipFile.c readzipfile()                    */
#define ZEN_MEM30   0x041E04        /* in ZipFile.c readzipfile()                    */
#define ZEN_MEM31   0x041F04        /* in ZipFile.c readzipfile()                    */
#define ZEN_MEM32   0x042004        /* in ZipFile.c readzipfile()                    */
#define ZEN_MEM33   0x042104        /* in ZipFile.c trash()                          */
#define ZEN_MEM34   0x042204        /* in Win32Zip.c processname()                   */
#define ZEN_MEM35   0x042304        /* in DllZip.c password command line alloc error */
#define ZEN_MEM36   0x042404        /* in DllMain.c CurrentDir alloc error  */
#define ZEN_MEM37   0x042504        /* in DLLZip.c ZipComment realloc error */
#define ZEN_MEM38   0x042604        /* in FileIO.c       */
#define ZEN_MEM39   0x042704        /* in ZipUp.c zipup() alloc extradata  */
#define ZEN_MEM40   0x042804        /* in ZipUp.c zipup() alloc extrastruct  */
#define ZEN_MEM41   0x042904        /* in ZipUp.c zipup() alloc z->ext  */
#define ZEN_MEM42   0x042A04        /* in ZipUp.c zipup() alloc z->cextra  */
#define ZEN_MEM43   0x042B04        // in FileIO.c replace
#define ZEN_MEM44   0x042C04        // in FileIO.c destroy
#define ZEN_MEM45   0x042D04        /* in FileIO.c newname()    */
#define ZEN_MEM46   0x042E04        /* in FileIO.c newname()     */     
#define ZEN_MEM47   0x042F04        /* in DllZip.c ZipSelect     */

#define ZEN_LOGIC   5               /* Internal logic error                  */
#define ZEN_LOGIC01 0x050105        /*      in bits.c copy_block()           */
#define ZEN_LOGIC02 0x050205        /*      in bits.c memcompress()          */
#define ZEN_LOGIC03 0x050305        /* in deflate.c lm_init()                */
#define ZEN_LOGIC04 0x050405        /* in DllZip.c error()                   */
#define ZEN_LOGIC05 0x050505        /* in FileIO.c newname()                 */
#define ZEN_LOGIC06 0x050605        /* in Zipup.c zipup()                    */
#define ZEN_LOGIC07 0x050705        /* in Tress.c flush_block()              */
#define ZEN_LOGIC08 0x050805        /* in FileIO.c newname()                 */

#define ZEN_SIZE    6
#define ZEN_SIZE01  0x060106          // destination too big
#define ZEN_SIZE02  0x060206          // source too big
#define ZEN_SIZE03  0x060306          // in Zipup.c source file too big
#define ZEN_SIZE04  0x060406          // in DllZip.c
#define ZEN_SIZE05  0x060506          // in DllZip.c - too many files 
#define ZEN_SIZE06  0x060606          // in DllZip.c - too many files
#define ZEN_SIZE07  0x060706        // in DllZip.c - too big    
#define ZEN_SIZE08  0x060806        // in DllZip.c - too big
#define ZEN_SIZE09  0x060906        // in DllZip.c - too big  
#define ZEN_SIZE10  0x060A06        // in DllZip.c - too big

#define ZEN_ABORT   0x090109        /* user interrupt or termination */
#define ZEN_ABORT01 0x070209        /* in ZGlobals.c               */
#define ZEN_ABORT02 0x080309        /* in ZGlobals.c               */
#define ZEN_ABORT03 0x090309        /* in FileIO.c        */
#define ZEN_ABORT04 0x090409        // in ZipUp.c
#define ZEN_ABORT05 0x090509        // in ZipUp.c

#define ZEN_TEMP    10              /* Error using a temp file    */
#define ZEN_TEMP01  0x0A010A        /* in DllZip.c zipmain()      */
#define ZEN_TEMP02  0x0A020A        /* in DllZip.c zipmain()      */
#define ZEN_TEMP03  0x0A030A        /* in FileIO.c replace()      */
#define ZEN_TEMP04  0x0A040A        /* in FileIO.c fcopy()        */
#define ZEN_TEMP05  0x0A050A        /* in Zipup.c zipup()         */
#define ZEN_TEMP06  0x0A060A        /* in Zipup.c zipup()         */
#define ZEN_TEMP07  0x0A070A        /* in ZipFile.c putlocal()    */
#define ZEN_TEMP08  0x0A080A        /* in ZipFile.c putcentral()  */
#define ZEN_TEMP09  0x0A090A        /* in ZipFile.c putend()      */
#define ZEN_TEMP10  0x0A0A0A        /* in ZipFile.c zipcopy()     */
#define ZEN_TEMP11  0x0A0B0A        // in FileIO.c replace()
#define ZEN_TEMP12  0x0A0C0A        // in FileIO.c replace()

#define ZEN_READ    11              /* Read or seek error         */
#define ZEN_READ01  0x0B010B        /* in DllZip.c zipmain()      */
#define ZEN_READ02  0x0B020B        /* in FileIO.c fcopy()        */
#define ZEN_READ03  0x0B030B        /* in Zipup.c zipup()         */
#define ZEN_READ04  0x0B040B        /* in ZipFile.c AfterError1() */
#define ZEN_READ05  0x0B050B        /* in ZipFile.c readzipfile() */
#define ZEN_READ06  0x0B060B        /* in ZipFile.c zipcopy()   */
#define ZEN_READ07  0x0B070B        /* in ZipFile.c zipcopy()  */
#define ZEN_READ08  0x0B080B        /* in FileIO.c filecopy   */
#define ZEN_READ09  0x0B090B        // in FileIO.c filecopy
#define ZEN_READ10  0x0B0A0B        // ZipUp.c
#define ZEN_READ11  0x0B0B0B        // ZipUp.c changed when crypt   
#define ZEN_READ12  0x0B0C0B        // ZipUp.c read error

#define ZEN_NONE    12              /* Nothing to do               */
#define ZEN_NONE01  0x0C010C        /* in DllZip.c zipmain()       */
#define ZEN_NONE02  0x0C020C        /* in DllZip.c zipmain() */
#define ZEN_NONE03  0x0C030C        // in DllZip.c zipmain()

#define ZEN_NAME    13              /* Missing or empty zip file  */
#define ZEN_NAME01  0x0D010D        /* in DllZip.c zipmain()      */
#define ZEN_NAME02  0x0D020D        /*N Zip filename open error   */
#define ZEN_NAME03  0x0D030D        /* in DllZip.c zipmain()      */

#define ZEN_WRITE   14              /* Error writing to a file    */
#define ZEN_WRITE01 0x0E010E        /* Write error in flush_outbuf */
#define ZEN_WRITE02 0x0E020E        /*      in bits.c copy_block() */
#define ZEN_WRITE03 0x0E030E        /* in DllZip.c zipmain()       */
#define ZEN_WRITE04 0x0E040E        /* in FileIO.c replace()       */
#define ZEN_WRITE05 0x0E050E        /* in Zipup.c zipup()          */
#define ZEN_WRITE06 0x0E060E        /* in Zipup.c zipup()          */
#define ZEN_WRITE07 0x0E070E        /* in FileIO.c replace()       */
#define ZEN_WRITE08 0x0E080E        /* in Zipup.c zipup()       */  
#define ZEN_WRITE09 0x0E090E        // in DllZip.c - truncate failed 
#define ZEN_WRITE10 0x0E0A0E        // in DllZip.c - truncate failed

#define ZEN_CREAT   15              /* Couldn't open to write      */
#define ZEN_CREAT01 0x0F010F        /* in FileIO.c replace()       */
#define ZEN_CREAT02 0x0F020F        /* in FileIO.c replace()       */
#define ZEN_CREAT03 0x0F030F        /* in FileIO.c replace()       */

#define ZEN_PARMS   16              /* Bad command line            */
#define ZEN_PARMS01 0x100110        /* no zip filename received, was -1  */
#define ZEN_PARMS02 0x100210        /* struct size mismatch, was -2      */
#define ZEN_PARMS03 0x100310        /*N Error with Temporary path        */
#define ZEN_PARMS04 0x100410        /*N Error with Delete (2 actions specified  */
#define ZEN_PARMS05 0x100510        /*N Crypt specified while not allowed       */
#define ZEN_PARMS06 0x100610        /*N Error with Freshen (2 actions specified */
#define ZEN_PARMS07 0x100710        /*N Error time option                       */
#define ZEN_PARMS08 0x100810        /*N Error with Update (2 actions specified  */
#define ZEN_PARMS09 0x100910        /*N no such option: %02X hex                */
#define ZEN_PARMS10 0x100A10        /* in ZipDll.c zipmain()                    */
#define ZEN_PARMS11 0x100B10        /*N Error in date parameter                 */
#define ZEN_PARMS12 0x100C10        /*N Delete specified with recurse or dispose */
#define ZEN_PARMS13 0x100D10        /*N name in zip file repeated                */
#define ZEN_PARMS14 0x100E10        /* in Zipup.c zipup()                        */
#define ZEN_PARMS15 0x100F10        /* in Win32Zip.c Wild()                      */
#define ZEN_PARMS16 0x101010        /* in Win32Zip.c Wild()                      */

#define ZEN_OPEN    18              /* Could not open a specified file to read   */
#define ZEN_OPEN01  0x120112        /* in ZipDll.c zipmain()                     */
#define ZEN_OPEN02  0x120212        /* in ZipUp.c zipup()                        */
#define ZEN_OPEN03  0x120312        /* in ZipUp.c zipup()                         */
#define ZEN_OPEN04  0x120412        /* in DllZip.c zipup() Sharing                 */
#define ZEN_OPEN05  0x120512        /* in DllZip.c zipup() Access                     */

#define ERRORLENGTH 40              /* Max length of any error message string below, used in ziperr() */
#ifdef GLOBALS

/* Error messages for the ziperr() function in the zip programs */
char *errors[] =
{
  /*  0 */
  "File not found",
  /*  1 */
  "password failed",
  /*  2 */
  "Unexpected end of zip file",
  /*  3 */
  "Zip file structure invalid",
  /*  4 */
  "Out of memory",
  /*  5 */
  "Internal logic error",
  /*  6 */
  "File > 4Gb",
  /*  7 */
  "Aborted; Global pointer missing",
  /*  8 */
  "Aborted; Global pointer not set",
  /*  9 */
  "Aborted by user",
  /* 10 */
  "Temporary file failure",
  /* 11 */
  "Error reading a file",
  /* 12 */
  "Nothing to do!",
  /* 13 */
  "Missing or empty zip file",
  /* 14 */
  "Error writing to a file",
  /* 15 */
  "Error creating file",
  /* 16 */
  "Bad zip options specified",
  /* 17 */
  "password canceled",
  /* 18 */
  "File not found or no read permission",
};
#else
extern char *errors[];
#endif
#endif
