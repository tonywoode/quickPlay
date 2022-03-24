// Common.h

#ifndef __COMMON_H__
#define __COMMON_H__

#ifndef USE_STRM_OUTPUT
  #define USE_STRM_OUTPUT
#endif
#ifndef USE_STRM_INPUT
  #define USE_STRM_INPUT
#endif

#ifndef CRYPT
  # define CRYPT 1
#endif


#ifdef __MT__
  #define MULTITHREAD
#else
  #undef MULTITHREAD
  #error no Multithread
#endif

#ifndef true
  #define true  TRUE
#endif
#ifndef false
  #define false FALSE
#endif

#define bool  BOOL

#include "DelZip.h"


typedef unsigned char   uch;          /* unsigned 8-bit value */
typedef unsigned short  ush;          /* unsigned 16-bit value */
typedef unsigned long   ulg;          /* unsigned 32-bit value */
typedef size_t  extent;

typedef unsigned long OperKeys;

#define ZIPOPER 0x01010101
#define UNZOPER 0x02020202

#define MAX_FILE_SIZE 0xFFFFFFFE
#define MAX_FILE_COUNT 65534

// abort flag values
#define GA_NONE 0               // no error
#define GA_ERROR 1              // processing error
#define GA_CANCEL 2             // callback signalled cancel
#define GA_ABORT 4              // Abort requested
#define GA_EXCEPT 0x10          // callback caught exception
#define GA_EXCEPT2 0x20         // callback caused exception

typedef struct OpFrame
{
  struct ZCallBackStruct CallBackData;
  unsigned Abort_Flag;
  OperKeys OpKey;
//  struct OpFrame* Prev;
  int OpTyp;
  struct OpFrame* ME;  // validity check
  int Verbose;
  HWND global_handle;
  void *global_caller;
  int CallerVersion;
  ZFunctionPtrType callb;              // Function address for callback purposes.
  char InfoBuf[1024];
  const char *LogName;          // new 178.5.0
  HANDLE hLogFile;              // new 178.5.0
}Frames;

void Init_Frame( Frames *pf );
void Clean_Frame( Frames *pf );
//void
//User(Frames *fp, long action, long error_code, long fsize, const char *name_or_msg);
#define PF (Frames *)pG

#define _CB_ pG->Frame.CallBackData
int __fastcall User_CB(Frames *pf, unsigned Action);

#define IMSG      0
#define IWARNING  0x01000000
#define IERROR    0x02000000
#define IVERBOSE  0x03000000
#define ITRACE    0x04000000
//#define IDEBUG    0x05000000
#define IBAD	  0x08000000
#define IDIAG     IVERBOSE
int __cdecl  Notify( Frames *fp, int err, const char *format, ... );

extern const ulg crc_table[];

ulg __fastcall crc32(ulg crc, const uch *buf, extent len );

int _fastcall       Extended( const char *str );

int __fastcall IsPrefix(const char* fn);

/*
 * case mapping functions. case_map is used to ignore case in comparisons,
 * to_up is used to force upper case.
 */
#pragma option -a1
extern const char upper[256];
extern const char extend[256];
#pragma option -a.

#define case_map( c ) upper[( ( unsigned char )c )]
#define to_up( c )    upper[( ( unsigned char )c )]
#define is_ext( c ) extend[( ( unsigned char )(c) )]
extern void Setup_upper( void );
extern void Setup_extend( void );

#ifdef __cplusplus
  #define min( a, b ) ( (a) < (b) ? (a) : (b) )
#endif

// disguised signitures
extern unsigned LOCSIG;//    0x04034b50L
extern unsigned CENSIG;//    0x02014b50L
extern unsigned ENDSIG;//    0x06054b50L
extern unsigned EXTLOCSIG;// 0x08074b50L

#pragma pack( push, 1 )

/*  The zipfile format is defined as below:
 *
 *   [Extra Extended Signature]
 *   NumberOfFiles *{ local header + Filename + [extra data] + [file data] + [data_descriptor] }
 *   NumberOfFiles *{ central directory + Filename + [extra data] + [filecomment] }
 *   End Of Central directory + [ZipFile comment]
 */
struct ZipLocalHeader
{
  unsigned long   HeaderSig;        // Should be 0x04034B50
  unsigned short  VersionNeed;
  unsigned short  Flag;
  unsigned short  ComprMethod;
  union
  {
    struct
    {
      unsigned short  ModifTime;
      unsigned short  ModifDate;
    };
    unsigned long ModifStamp;
  };
  unsigned long   CRC32;
  unsigned long   ComprSize;
  unsigned long   UnComprSize;
  unsigned short  FileNameLen;
  unsigned short  ExtraLen;

  //	... and the filename itself,
  // ... and the extra data.
};

struct ZipDataDescriptor
{
  unsigned long DataDescSig;        // Should be 0x08074B50
  unsigned long CRC32;
  unsigned long ComprSize;
  unsigned long UnComprSize;
};

struct ZipCentralHeader
{
  unsigned long HeaderSig;          // Should be 0x02014B50
  union
  {
    struct
    {
      unsigned char MadeByVersion;  // Made by version number
      unsigned char MadeByHost;     // Made by host number
    };
    unsigned short  MadeBy;
  };
  unsigned short  VersionNeed;
  unsigned short  Flag;
  unsigned short  ComprMethod;
  union
  {
    struct
    {
      unsigned short  ModifTime;
      unsigned short  ModifDate;
    };
    unsigned long ModifStamp;
  };
  unsigned long   CRC32;
  unsigned long   ComprSize;
  unsigned long   UnComprSize;
  unsigned short  FileNameLen;
  unsigned short  ExtraLen;
  unsigned short  FileComLen;
  unsigned short  DiskStart;        // The number of the disk on which this file begins.
  unsigned short  IntFileAtt;
  unsigned long   ExtFileAtt;
  unsigned long   RelOffLocal;      // This is the offset from the start of the first disk on

  // which this file appears, to where the local header
  // should be found.
  //	... and the filename itself,
  // ... and the extra data,
  // ... and the file comment.
};

struct ZipEndOfCentral
{
  unsigned long   HeaderSig;        // Should be 0x06054B50
  unsigned short  ThisDiskNo;
  unsigned short  CentralDiskNo;
  unsigned short  CentralEntries;   // Total number of entries in the central dir on this disk.
  unsigned short  TotalEntries;     // Total number of entries in the central dir.
  unsigned long   CentralSize;
  unsigned long   CentralOffset;    // Offset of start of central directory with respect to the starting disk number.
  unsigned short  ZipCommentLen;
  // And the comment itself.
};
#pragma pack( pop )

int __fastcall Close_Handle(HANDLE *h);
HANDLE __fastcall OpenRead(Frames *fp, LPCTSTR FileName, DWORD flags);
//void __fastcall FreeAndNil(void **p);

#define MALLOC( s )         malloc( (s) )
#define FREE( p )           free( ( void * )(p) )
//#define FREEANDNIL( p )     FreeAndNil( (void **) (p))
#define FREEANDNIL( p )     {if (p){ free((void *)(p)); (p) = NULL;}}

bool QueryINI(Frames * pf, bool IsZip);
void LogString(Frames *fp, int err, const char *msg);

#endif

