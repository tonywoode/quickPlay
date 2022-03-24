// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Zipmsg.pas' rev: 10.00

#ifndef ZipmsgHPP
#define ZipmsgHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Zipmsg
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
static const Word DT_Language = 0x2770;
static const Word DT_Author = 0x2771;
static const Word DT_Desc = 0x2772;
static const Word GE_FatalZip = 0x2775;
static const Word GE_NoZipSpecified = 0x2776;
static const Word GE_NoMem = 0x2777;
static const Word GE_WrongPassword = 0x2778;
static const Word GE_CopyFile = 0x2779;
static const Word GE_Except = 0x277a;
static const Word GE_Reentered = 0x277b;
static const Word GE_Busy = 0x277c;
static const Word GE_Inactive = 0x277d;
static const Word GE_RangeError = 0x277e;
static const Word GE_TempZip = 0x277f;
static const Word GE_WasBusy = 0x2780;
static const Word GE_EventEx = 0x2781;
static const Word GE_DLLAbort = 0x2786;
static const Word GE_DLLBusy = 0x2787;
static const Word GE_DLLCancel = 0x2788;
static const Word GE_DLLMem = 0x2789;
static const Word GE_DLLStruct = 0x278a;
static const Word GE_DLLEvent = 0x278b;
static const Word GE_DLLCritical = 0x278c;
static const Word GE_Unknown = 0x278d;
static const Word GE_Skipped = 0x278e;
static const Word RN_ZipSFXData = 0x279c;
static const Word RN_NoRenOnSpan = 0x279d;
static const Word RN_ProcessFile = 0x279e;
static const Word RN_RenameTo = 0x279f;
static const Word RN_InvalidDateTime = 0x27a0;
static const Word PW_UnatAddPWMiss = 0x27a6;
static const Word PW_UnatExtPWMiss = 0x27a7;
static const Word PW_Caption = 0x27aa;
static const Word PW_MessageEnter = 0x27ab;
static const Word PW_MessageConfirm = 0x27ac;
static const Word PW_ForFile = 0x27af;
static const Word CF_SourceIsDest = 0x27c4;
static const Word CF_OverwriteYN = 0x27c5;
static const Word CF_CopyFailed = 0x27c6;
static const Word CF_SourceNotFound = 0x27c7;
static const Word CF_SFXCopyError = 0x27c8;
static const Word CF_DestFileNoOpen = 0x27c9;
static const Word CF_NoCopyOnSpan = 0x27ca;
static const Word LI_ReadZipError = 0x27d9;
static const Word LI_ErrorUnknown = 0x27da;
static const Word LI_WrongZipStruct = 0x27db;
static const Word LI_GarbageAtEOF = 0x27dc;
static const Word LI_FileTooBig = 0x27dd;
static const Word LI_MethodUnknown = 0x27de;
static const Word ZB_Yes = 0x27ec;
static const Word ZB_No = 0x27ed;
static const Word ZB_OK = 0x27ee;
static const Word ZB_Cancel = 0x27ef;
static const Word ZB_Abort = 0x27f0;
static const Word ZB_Retry = 0x27f1;
static const Word ZB_Ignore = 0x27f2;
static const Word ZB_CancelAll = 0x27f3;
static const Word ZB_NoToAll = 0x27f4;
static const Word ZB_YesToAll = 0x27f5;
static const Word AD_NothingToZip = 0x283d;
static const Word AD_UnattPassword = 0x283e;
static const Word AD_NoFreshenUpdate = 0x283f;
static const Word AD_AutoSFXWrong = 0x2840;
static const Word AD_InIsOutStream = 0x2842;
static const Word AD_InvalidName = 0x2843;
static const Word AD_NoDestDir = 0x2844;
static const Word DL_NothingToDel = 0x28a1;
static const Word DL_NoDelOnSpan = 0x28a2;
static const Word EX_FatalUnZip = 0x2905;
static const Word EX_UnAttPassword = 0x2906;
static const Word EX_NoExtrDir = 0x2908;
static const Word LD_NoDll = 0x299a;
static const Word LD_BadDll = 0x299b;
static const Word LD_DllLoaded = 0x299c;
static const Word LD_DllUnloaded = 0x299d;
static const Word SF_StringTooLong = 0x2a31;
static const Word SF_NoZipSFXBin = 0x2a32;
static const Word SF_InputIsNoZip = 0x2a33;
static const Word SF_NoSFXSupport = 0x2a34;
static const Word SF_MsgTooLong = 0x2a35;
static const Word SF_DefPathTooLong = 0x2a36;
static const Word SF_DlgTitleTooLong = 0x2a37;
static const Word SF_CmdLineTooLong = 0x2a38;
static const Word SF_FBkPathTooLong = 0x2a39;
static const Word CZ_NoExeSpecified = 0x2a95;
static const Word CZ_InputNotExe = 0x2a96;
static const Word CZ_SFXTypeUnknown = 0x2a97;
static const Word CZ_WrongConvert = 0x2a98;
static const Word CZ_UnknownHeader = 0x2a99;
static const Word CZ_BrowseError = 0x2a9a;
static const Word CZ_NoExeResource = 0x2a9b;
static const Word CZ_ExeSections = 0x2a9c;
static const Word CZ_NoExeIcon = 0x2a9d;
static const Word CZ_NoIcon = 0x2a9e;
static const Word CZ_NoCopyIcon = 0x2a9f;
static const Word CZ_NoIconFound = 0x2aa0;
static const Word DS_NoInFile = 0x2af9;
static const Word DS_FileOpen = 0x2afa;
static const Word DS_NotaDrive = 0x2afb;
static const Word DS_DriveNoMount = 0x2afc;
static const Word DS_NoVolume = 0x2afd;
static const Word DS_NoMem = 0x2afe;
static const Word DS_Canceled = 0x2aff;
static const Word DS_FailedSeek = 0x2b00;
static const Word DS_NoOutFile = 0x2b01;
static const Word DS_NoWrite = 0x2b02;
static const Word DS_EOCBadRead = 0x2b03;
static const Word DS_LOHBadRead = 0x2b04;
static const Word DS_CEHBadRead = 0x2b05;
static const Word DS_LOHWrongSig = 0x2b06;
static const Word DS_CEHWrongSig = 0x2b07;
static const Word DS_LONameLen = 0x2b08;
static const Word DS_CENameLen = 0x2b09;
static const Word DS_LOExtraLen = 0x2b0a;
static const Word DS_CEExtraLen = 0x2b0b;
static const Word DS_DataDesc = 0x2b0c;
static const Word DS_ZipData = 0x2b0d;
static const Word DS_CECommentLen = 0x2b0e;
static const Word DS_EOArchComLen = 0x2b0f;
static const Word DS_ErrorUnknown = 0x2b10;
static const Word DS_NoUnattSpan = 0x2b11;
static const Word DS_EntryLost = 0x2b12;
static const Word DS_NoTempFile = 0x2b13;
static const Word DS_LOHBadWrite = 0x2b14;
static const Word DS_CEHBadWrite = 0x2b15;
static const Word DS_EOCBadWrite = 0x2b16;
static const Word DS_ExtWrongSig = 0x2b17;
static const Word DS_NoDiskSpace = 0x2b18;
static const Word DS_InsertDisk = 0x2b19;
static const Word DS_InsertVolume = 0x2b1a;
static const Word DS_InDrive = 0x2b1b;
static const Word DS_NoValidZip = 0x2b1c;
static const Word DS_FirstInSet = 0x2b1d;
static const Word DS_NotLastInSet = 0x2b1e;
static const Word DS_AskDeleteFile = 0x2b1f;
static const Word DS_AskPrevFile = 0x2b20;
static const Word DS_NoSFXSpan = 0x2b21;
static const Word DS_CEHBadCopy = 0x2b22;
static const Word DS_EOCBadSeek = 0x2b23;
static const Word DS_EOCBadCopy = 0x2b24;
static const Word DS_FirstFileOnHD = 0x2b25;
static const Word DS_InsertAVolume = 0x2b26;
static const Word DS_CopyCentral = 0x2b27;
static const Word DS_NoDiskSpan = 0x2b28;
static const Word DS_UnknownError = 0x2b29;
static const Word DS_NoRenamePart = 0x2b2a;
static const Word DS_NotChangeable = 0x2b2b;
static const Word FM_Erase = 0x2b5d;
static const Word FM_Confirm = 0x2b5e;
static const Word CD_NoCDOnSpan = 0x2c25;
static const Word CD_NoEventHndlr = 0x2c26;
static const Word CD_LOExtraLen = 0x2c27;
static const Word CD_CEExtraLen = 0x2c28;
static const Word CD_CEComLen = 0x2c29;
static const Word CD_CEHDataSize = 0x2c2b;
static const Word CD_Changing = 0x2c2c;
static const Word CD_DuplFileName = 0x2c2d;
static const Word CD_NoProtected = 0x2c2e;
static const Word CD_InvalidFileName = 0x2c2f;
static const Word CD_NoChangeDir = 0x2c30;
static const Word CD_FileSpecSkip = 0x2c31;
static const Word DU_InvalidName = 0x2c56;
static const Word DU_WrongMethod = 0x2c57;
static const Word PR_Archive = 0x2c89;
static const Word PR_CopyZipFile = 0x2c8a;
static const Word PR_SFX = 0x2c8b;
static const Word PR_Header = 0x2c8c;
static const Word PR_Finish = 0x2c8d;
static const Word PR_Copying = 0x2c8e;
static const Word PR_CentrlDir = 0x2c8f;
static const Word PR_Checking = 0x2c90;
static const Word PR_Loading = 0x2c91;
static const Word PR_Joining = 0x2c92;
static const Word PR_Splitting = 0x2c93;
static const Word DZ_Skipped = 0x2cba;
static const Word DZ_InUse = 0x2cbb;
static const Word DZ_Refused = 0x2cbc;
static const Word DZ_NoOpen = 0x2cbd;
static const Word DZ_NoFiles = 0x2cbe;
static const Word DZ_SizeChanged = 0x2cbf;
static const Word DZ_InvalidName = 0x2cc0;
static const Word DZ_TooBig = 0x2cc1;
static const Word WZ_DropDirOnly = 0x2cec;
static const Word WZ_NothingToWrite = 0x2ced;
static const Word TM_Erasing = 0x2d50;
static const Word TM_Deleting = 0x2d51;
static const Word TM_GetNewDisk = 0x2d52;
static const Word TM_SystemError = 0x2d53;
static const Word PR_Progress = 0x2c88;
static const Word DZRES_Str = 0x2d5a;
static const Word RDLL_Ver = 0x2d5c;
static const Word RDLL_Dll = 0x2d5d;

}	/* namespace Zipmsg */
using namespace Zipmsg;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Zipmsg
