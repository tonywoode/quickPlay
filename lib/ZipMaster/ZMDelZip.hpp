// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Zmdelzip.pas' rev: 10.00

#ifndef ZmdelzipHPP
#define ZmdelzipHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Zmdelzip
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum ActionCodes { zacTick, zacItem, zacProgress, zacEndOfBatch, zacMessage, zacCount, zacSize, zacNewName, zacPassword, zacCRCError, zacOverwrite, zacSkipped, zacComment, zacStream, zacData, zacXItem, zacXProgress, zacExtName, zacKey, zacNone };
#pragma option pop

#pragma option push -b-
enum CBFNs { cbfnOld, cbfnNew, cbfnExtended };
#pragma option pop

#pragma pack(push,1)
struct ZCallBackStruct
{
	
public:
	void *Caller;
	int Version;
	BOOL IsOperationZip;
	int ActionCode;
	unsigned Arg1;
	char *MsgP;
	union
	{
		struct 
		{
			__int64 FileSize;
			__int64 Written;
			char *Msg2P;
			unsigned Arg2;
			unsigned Arg3;
			
		};
		struct 
		{
			char Msg[512];
			
		};
		
	};
} ;
#pragma pack(pop)

typedef ZCallBackStruct *PZCallBackStruct;

typedef int __stdcall (*ZFunctionPtrType)(void * Caller, PZCallBackStruct ZCallbackRec);

#pragma pack(push,1)
struct UnzFileData
{
	
public:
	char *fFileSpec;
	char *fFileAltName;
	char *fPassword;
	unsigned fNotUsed[4];
	unsigned fMatch;
} ;
#pragma pack(pop)

typedef UnzFileData *pUnzFileData;

#pragma pack(push,1)
struct UnzExFileData
{
	
public:
	char *fFileSpec;
	unsigned fNotUsed[3];
} ;
#pragma pack(pop)

typedef UnzExFileData *pUnzExFileData;

#pragma pack(push,1)
struct UnZipParms2
{
	
public:
	HWND fHandle;
	void *fCaller;
	int fVersion;
	ZFunctionPtrType ZCallbackFunc;
	BOOL fTraceEnabled;
	unsigned fWantedCodePage;
	unsigned fPromptToOverwrite;
	char *pZipPassword;
	BOOL fTest;
	BOOL fComments;
	BOOL fConvert;
	BOOL fQuiet;
	BOOL fVerboseEnabled;
	BOOL fUpdate;
	BOOL fFreshen;
	BOOL fDirectories;
	BOOL fOverwrite;
	int fArgc;
	char *pZipFN;
	UnzFileData *fUFDS;
	UnzExFileData *fXUFDS;
	BOOL fUseOutStream;
	void *fOutStream;
	int fOutStreamSize;
	BOOL fUseInStream;
	void *fInStream;
	int fInStreamSize;
	unsigned fPwdReqCount;
	char *fExtractDir;
	unsigned fNotUsed[8];
	int fSeven;
} ;
#pragma pack(pop)

typedef UnZipParms2 *pUnZipParms;

#pragma pack(push,1)
struct FileData
{
	
public:
	char *fFileSpec;
	char *fFileComment;
	char *fFileAltName;
	char *fPassword;
	unsigned fEncrypt;
	int fRecurse;
	unsigned fFromDate;
	int fLevel;
	int fnotused2;
	char *fRootDir;
	unsigned fNotUsed[6];
} ;
#pragma pack(pop)

typedef FileData *pFileData;

#pragma pack(push,1)
struct ExcludedFileSpec
{
	
public:
	char *fFileSpec;
} ;
#pragma pack(pop)

typedef ExcludedFileSpec *pExcludedFileSpec;

#pragma pack(push,1)
struct ZipParms
{
	
public:
	HWND fHandle;
	void *fCaller;
	int fVersion;
	ZFunctionPtrType ZCallbackFunc;
	BOOL fTraceEnabled;
	char *pZipPassword;
	char *pSuffix;
	BOOL fEncrypt;
	BOOL fSystem;
	BOOL fVolume;
	BOOL fExtra;
	BOOL fNoDirEntries;
	BOOL fUseDate;
	BOOL fVerboseEnabled;
	BOOL fQuiet;
	int fLevel;
	BOOL fComprSpecial;
	BOOL fCRLF_LF;
	BOOL fJunkDir;
	BOOL fRecurse;
	unsigned fNoRecurseFiles;
	BOOL fGrow;
	BOOL fForce;
	BOOL fMove;
	BOOL fDeleteEntries;
	BOOL fUpdate;
	BOOL fFreshen;
	BOOL fJunkSFX;
	BOOL fLatestTime;
	unsigned fDate;
	int fArgc;
	char *pZipFN;
	char *fTempPath;
	char *fArchComment;
	int fArchiveFilesOnly;
	int fResetArchiveBit;
	FileData *fFDS;
	BOOL fForceWin;
	int fTotExFileSpecs;
	ExcludedFileSpec *fExFiles;
	BOOL fUseOutStream;
	void *fOutStream;
	unsigned fOutStreamSize;
	BOOL fUseInStream;
	void *fInStream;
	unsigned fInStreamSize;
	unsigned fStrFileAttr;
	unsigned fStrFileDate;
	BOOL fHowToMove;
	unsigned fWantedCodePage;
	unsigned fWantedOS;
	unsigned fVCLVer;
	char *fGRootDir;
	unsigned fNotUsed[2];
	int fSeven;
} ;
#pragma pack(pop)

typedef ZipParms *pZipParms;

typedef int __stdcall (*TUnzExecFunc)(pUnZipParms Rec);

typedef int __stdcall (*TZipExecFunc)(pZipParms Rec);

typedef int __stdcall (*TDllVersionFunc)(void);

typedef int __stdcall (*TDllPrivVersionFunc)(void);

typedef int __stdcall (*TAbortOperationFunc)(unsigned Rec);

typedef char * __stdcall (*TDllPathFunc)(void);

//-- var, const, procedure ---------------------------------------------------
static const Word Callback_Except_No = 0x277a;
static const Shortint CRITICAL_CANCELLED = -1;
static const Shortint CRITICAL_ABORT = -2;
static const Shortint CRITICAL_CALLBACK = -3;
static const Shortint CRITICAL_MEMORY = -4;
static const Shortint CRITICAL_STRUCT = -5;
static const Shortint CRITICAL_ERROR = -6;
#define DelZipDll_Unzfunc "DZ_UnzExec"
#define DelZipDll_Zipfunc "DZ_ZipExec"
#define DelZipDll_Abortfunc "DZ_Abort"
#define DelZipDll_Versfunc "DZ_Version"
#define DelZipDll_Privfunc "DZ_PrivVersion"
#define DelZipDll_Pathfunc "DZ_Path"

}	/* namespace Zmdelzip */
using namespace Zmdelzip;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Zmdelzip
