#ifndef DelZip_H
#define DelZip_H

typedef union
{
  __int64 i64;
  struct
  {
//    int lo;
//    unsigned hi;
    unsigned lo;
    int hi;
  };
}_I64;


enum ActionCodes
{
  zacTick, zacItem, zacProgress, zacEndOfBatch, zacMessage, zacCount, zacSize,
  zacNewName, zacPassword, zacCRCError, zacOverwrite, zacSkipped, zacComment,
  zacStream, zacData, zacXItem, zacXProgress, zacExtName, zacKey
};
#define Callback_Except_No 10106

//Callbackstructs------------------------------------------------------------- 

/* All the items in the CallBackStruct are passed to the BCB
 * program from the DLL.  Note that the "Caller" value returned
 * here is the same one specified earlier in ZipParms by the
 * BCB program. */
#pragma option -a1
struct ZCallBackStruct
{
  void  *Caller;                // 'this' reference of the ZipBuilder class
  long   Version;               // version no. of DLL.
  BOOL   IsOperationZip;        // true=zip, false=unzip
  int    ActionCode;            // returns <0 if result valid
  long   Arg1;                  // ErrorCode;
  const char *MsgP;             // pointer to text
  union
  {
    char Msg[512];              // storage for returning text
    struct
    {
      _I64 FileSize;
      _I64 Written;             // number of bytes written
      const char *MsgP2;        // additional text
      unsigned Arg2;            // additional arg
      unsigned Arg3;
    };
  }; 
};
#pragma option -a.
typedef struct ZCallBackStruct CB_Rec;
typedef struct ZCallBackStruct *PZCallBackStruct;

#define CB_USEMSG ((const char *)-1)

/* Declare a function pointer type for the BCB/Delphi callback function, to
 * be called by the DLL to pass updated status info back to BCB/Delphi.*/

typedef int __stdcall (*ZFunctionPtrType)(void *, PZCallBackStruct ZCallbackRec);

#ifndef NO_UNZIP_STRUCTS
//Unzip structs-------------------------------------------------------------------
#pragma option -a1

/* These records are very critical.  Any changes in the order of items, the
   size of items, or modifying the number of items, may have disasterous
   results.  You have been warned! */

typedef struct
{
  char          *fFileSpec;
  char          *fFileAltName;
  char          *fPassword;
  long          fNotUsed[4];
  long          fMatch;                   // used by extract for searches
}UnzFileData; 
#pragma option -a.

#pragma option -a1
struct UnzExFileData
{
  char      *fFileSpec;
  long      fNotUsed[3];
};       
#pragma option -a.
             
#pragma option -a1
typedef struct
{
  HWND                          fHandle;
  void                          *fCaller;
  long                          fVersion;
  ZFunctionPtrType              ZCallbackFunc;
  BOOL                          fTraceEnabled;
  unsigned                      fWantedCodePage;
  unsigned                      fPromptToOverwrite;
  char                          *pZipPassword;
  BOOL                          fTest;
  BOOL                          fComments;
  BOOL                          fConvert;
  BOOL                          fQuiet;
  BOOL                          fVerboseEnabled;
  BOOL                          fUpdate;
  BOOL                          fFreshen;
  BOOL                          fDirectories;
  BOOL                          fOverwrite;
  long                          fArgc;
  char                          *pZipFN;
  UnzFileData                   *fUFDS;
  struct UnzExFileData          *fXUDFS;
  BOOL                          fUseOutStream;      // Use Memory stream as output.
  void                          *fOutStream;          // Pointer to the start of streaam data.
  unsigned long                 fOutStreamSize; // Size of the output data.
  BOOL                          fUseInStream;       // Use memory stream as input.
  void                          *fInStream;           // Pointer to the start of the input stream data.
  unsigned long                 fInStreamSize;      // Size of the input data.
  unsigned long                 fPwdReqCount;       // PasswordRequestCount, How many times a password will be asked per file
  char                          *fExtractDir;
  long                          fNotUsed[8];
  long                          fSeven;
}UnZipParms;
#pragma option -a.

typedef UnZipParms *pUnZipParms;
#endif

#ifndef NO_ZIP_STRUCTS
//Zip structs---------------------------------------------------------------------
#pragma option -a1

typedef struct
{
  char*    fFileSpec;
  char*    fFileComment;     //  z->comment and z->com
  char*    fFileAltName;
  char*    fPassword;
  BOOL     fEncrypt;
  unsigned fRecurse;
  unsigned fFromDate;
  int fLevel;
  int fnotused2;
  char* fRootDir;         //  RootDir support for relative paths
  long    fNotUsed[6];
}FileData;      
#pragma option -a.
        
#pragma option -a1
struct ExcludedFileSpec
{
  char      *fFileSpec;
};  
#pragma option -a.
           
#pragma option -a1
typedef struct
{
  HWND                          fHandle;
  void                          *fCaller;
  long                          fVersion;
  ZFunctionPtrType              ZCallbackFunc;
  BOOL                          fTraceEnabled;
  char                          *pZipPassword;        // password pointer
  char                          *pSuffix;
  BOOL                          fEncrypt;           // General encrypt, if not superseded by FileData.fEncrypt
  BOOL                          fSystem;
  BOOL                          fVolume;
  BOOL                          fExtra;
  BOOL                          fNoDirEntries;
  BOOL                          fUseDate;           // General DateUsed, if not superseded by FileData.fDateUsed
  BOOL                          fVerboseEnabled;
  BOOL                          fQuiet;
  int                           fLevel;
  BOOL                          fComprSpecial;      // Not used any more. (v1.6) now fSuffix takes care of this.
  BOOL                          fCRLF_LF;
  BOOL                          fJunkDir;
  unsigned                      fRecurse;
  unsigned                      fNoRecurseFiles;
  BOOL                          fGrow;
  BOOL                          fForce;
  BOOL                          fMove;
  BOOL                          fDeleteEntries;
  BOOL                          fUpdate;
  BOOL                          fFreshen;
  BOOL                          fJunkSFX;
  BOOL                          fLatestTime;
  // General Date, if not superseded by FileData.fDate
  unsigned                      fDate;
  long                          fArgc;                  // Changed, Number of FileData structures.
  char                          *pZipFN;                // Ptr to name of zip file.
  char                          *fTempPath;             //  b option
  char                          *fArchComment;          //  zcomment and zcomlen
  int                           fArchiveFilesOnly;      //  when != 0 only zip when archive bit set
  int                           fResetArchiveBit;       //  when != 0 reset the archive bit after a successfull zip
  FileData                      *fFDS;                  //  (Actually an array of FileData's)
  BOOL                          fForceWin;              //
  int                           fTotExFileSpecs;        //  Number of ExcludedFileSpec structures.
  struct ExcludedFileSpec       *fExFiles;              //  Array of file specs to exclude from zipping.
  BOOL                          fUseOutStream;          //  Use memory stream as output.
  void                          *fOutStream;            //  Pointer to the start of the output stream data.
  unsigned long                 fOutStreamSize;         // Size of the Output data.
  BOOL                          fUseInStream;           // Use memory stream as input.
  void                          *fInStream;             // Pointer to the start of the input stream data.
  unsigned long                 fInStreamSize;          // Size of the input data.
  DWORD                         fStrFileAttr;           // File attributes of the file stream.
  DWORD                         fStrFileDate;           // File date/time to set for the streamed file.
  BOOL                          fHowToMove;
  unsigned                      fWantedCodePage;
  unsigned                      fWantedOS;
  unsigned                      fVCLVer;
  char*                         fGRootDir;
  unsigned                      fNotUsed[2];
  int                           fSeven;                 // End of structure (eg. 7)
}ZipParms;
#pragma option -a.

typedef ZipParms *PZipParms;
#endif

#define CRITICAL_CANCELLED      -1
#define CRITICAL_ABORT          -2 
#define CRITICAL_CALLBACK       -3
#define CRITICAL_MEMORY         -4
#define CRITICAL_STRUCT         -5
#define CRITICAL_ERROR          -6

#ifdef __cplusplus
extern "C"
{
#endif
extern BOOL WINAPI  DllEntryPoint( HINSTANCE hinstDll, DWORD fdwRreason,
                                     LPVOID plvReserved );
long WINAPI DZ_UnzExec( UnZipParms * C );
long WINAPI DZ_ZipExec( ZipParms * C );
long WINAPI DZ_Abort( void * C );
long WINAPI DZ_Version( void );
long WINAPI DZ_PrivVersion( void );
const char* WINAPI DZ_Path( void ); //char *buf, int len);
#ifdef __cplusplus
}
#endif

#endif
