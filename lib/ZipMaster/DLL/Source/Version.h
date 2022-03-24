/* Version.h
* This version modified by Chris Vleghert and Eric Engler for BCB/Delphi Zip.
*/
#ifndef _VERSION_H
#define _VERSION_H

#define DLLNAME "DelZip"
#define DELZIPVERSION 179

#define REVISION  11
#define PATCHLEVEL  15
#define DELZIPPRIVVERS ( (DELZIPVERSION * 10000) + (REVISION * 100) + PATCHLEVEL )

#define DELZIPVERS (DELZIPPRIVVERS / 10000)

//const char *mdate = __DATE__;

#endif /* _VERSION_H */
