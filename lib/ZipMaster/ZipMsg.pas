Unit ZipMsg;
 
(* Built by ZipResMaker
   DO NOT MODIFY
  ZipMsg.pas - Message Identifiers
  TZipMaster VCL by Chris Vleghert and Eric W. Engler

  v1.79
      Copyright (C) 2005  Russell Peters
 
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
 
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License (licence.txt) for more details.
 
  You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software 
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 
  contact: problems AT delphizip DOT org
  updates: http://www.delphizip.org

  modified 6/12/2005 9:41:56 AM
---------------------------------------------------------------------------*)
 
 
Interface
 
Const
  DT_Language = 10096;
  DT_Author = 10097;
  DT_Desc = 10098;
  GE_FatalZip = 10101;
  GE_NoZipSpecified = 10102;
  GE_NoMem = 10103;
  GE_WrongPassword = 10104;
  GE_CopyFile = 10105;
  GE_Except = 10106;
  GE_Reentered = 10107;
  GE_Busy = 10108;
  GE_Inactive = 10109;
  GE_RangeError = 10110;
  GE_TempZip = 10111;
  GE_WasBusy = 10112;
  GE_EventEx = 10113;
  GE_DLLAbort = 10118;
  GE_DLLBusy = 10119;
  GE_DLLCancel = 10120;
  GE_DLLMem = 10121;
  GE_DLLStruct = 10122;
  GE_DLLEvent = 10123;
  GE_DLLCritical = 10124;
  GE_Unknown = 10125;
  GE_Skipped = 10126;
  RN_ZipSFXData = 10140;
  RN_NoRenOnSpan = 10141;
  RN_ProcessFile = 10142;
  RN_RenameTo = 10143;
  RN_InvalidDateTime = 10144;
  PW_UnatAddPWMiss = 10150;
  PW_UnatExtPWMiss = 10151;
  PW_Caption = 10154;
  PW_MessageEnter = 10155;
  PW_MessageConfirm = 10156;
  PW_ForFile = 10159;
  CF_SourceIsDest = 10180;
  CF_OverwriteYN = 10181;
  CF_CopyFailed = 10182;
  CF_SourceNotFound = 10183;
  CF_SFXCopyError = 10184;
  CF_DestFileNoOpen = 10185;
  CF_NoCopyOnSpan = 10186;
  LI_ReadZipError = 10201;
  LI_ErrorUnknown = 10202;
  LI_WrongZipStruct = 10203;
  LI_GarbageAtEOF = 10204;
  LI_FileTooBig = 10205;
  LI_MethodUnknown = 10206;
  ZB_Yes = 10220;
  ZB_No = 10221;
  ZB_OK = 10222;
  ZB_Cancel = 10223;
  ZB_Abort = 10224;
  ZB_Retry = 10225;
  ZB_Ignore = 10226;
  ZB_CancelAll = 10227;
  ZB_NoToAll = 10228;
  ZB_YesToAll = 10229;
  AD_NothingToZip = 10301;
  AD_UnattPassword = 10302;
  AD_NoFreshenUpdate = 10303;
  AD_AutoSFXWrong = 10304;
  AD_InIsOutStream = 10306;
  AD_InvalidName = 10307;
  AD_NoDestDir = 10308;
  DL_NothingToDel = 10401;
  DL_NoDelOnSpan = 10402;
  EX_FatalUnZip = 10501;
  EX_UnAttPassword = 10502;
  EX_NoExtrDir = 10504;
  LD_NoDll = 10650;
  LD_BadDll = 10651;
  LD_DllLoaded = 10652;
  LD_DllUnloaded = 10653;
  SF_StringTooLong = 10801;
  SF_NoZipSFXBin = 10802;
  SF_InputIsNoZip = 10803;
  SF_NoSFXSupport = 10804;
  SF_MsgTooLong = 10805;
  SF_DefPathTooLong = 10806;
  SF_DlgTitleTooLong = 10807;
  SF_CmdLineTooLong = 10808;
  SF_FBkPathTooLong = 10809;
  CZ_NoExeSpecified = 10901;
  CZ_InputNotExe = 10902;
  CZ_SFXTypeUnknown = 10903;
  CZ_WrongConvert = 10904;
  CZ_UnknownHeader = 10905;
  CZ_BrowseError = 10906;
  CZ_NoExeResource = 10907;
  CZ_ExeSections = 10908;
  CZ_NoExeIcon = 10909;
  CZ_NoIcon = 10910;
  CZ_NoCopyIcon = 10911;
  CZ_NoIconFound = 10912;
  DS_NoInFile = 11001;
  DS_FileOpen = 11002;
  DS_NotaDrive = 11003;
  DS_DriveNoMount = 11004;
  DS_NoVolume = 11005;
  DS_NoMem = 11006;
  DS_Canceled = 11007;
  DS_FailedSeek = 11008;
  DS_NoOutFile = 11009;
  DS_NoWrite = 11010;
  DS_EOCBadRead = 11011;
  DS_LOHBadRead = 11012;
  DS_CEHBadRead = 11013;
  DS_LOHWrongSig = 11014;
  DS_CEHWrongSig = 11015;
  DS_LONameLen = 11016;
  DS_CENameLen = 11017;
  DS_LOExtraLen = 11018;
  DS_CEExtraLen = 11019;
  DS_DataDesc = 11020;
  DS_ZipData = 11021;
  DS_CECommentLen = 11022;
  DS_EOArchComLen = 11023;
  DS_ErrorUnknown = 11024;
  DS_NoUnattSpan = 11025;
  DS_EntryLost = 11026;
  DS_NoTempFile = 11027;
  DS_LOHBadWrite = 11028;
  DS_CEHBadWrite = 11029;
  DS_EOCBadWrite = 11030;
  DS_ExtWrongSig = 11031;
  DS_NoDiskSpace = 11032;
  DS_InsertDisk = 11033;
  DS_InsertVolume = 11034;
  DS_InDrive = 11035;
  DS_NoValidZip = 11036;
  DS_FirstInSet = 11037;
  DS_NotLastInSet = 11038;
  DS_AskDeleteFile = 11039;
  DS_AskPrevFile = 11040;
  DS_NoSFXSpan = 11041;
  DS_CEHBadCopy = 11042;
  DS_EOCBadSeek = 11043;
  DS_EOCBadCopy = 11044;
  DS_FirstFileOnHD = 11045;
  DS_InsertAVolume = 11046;
  DS_CopyCentral = 11047;
  DS_NoDiskSpan = 11048;
  DS_UnknownError = 11049;
  DS_NoRenamePart = 11050;
  DS_NotChangeable = 11051;
  FM_Erase = 11101;
  FM_Confirm = 11102;
  CD_NoCDOnSpan = 11301;
  CD_NoEventHndlr = 11302;
  CD_LOExtraLen = 11303;
  CD_CEExtraLen = 11304;
  CD_CEComLen = 11305;
  CD_CEHDataSize = 11307;
  CD_Changing = 11308;
  CD_DuplFileName = 11309;
  CD_NoProtected = 11310;
  CD_InvalidFileName = 11311;
  CD_NoChangeDir = 11312;
  CD_FileSpecSkip = 11313;
  DU_InvalidName = 11350;
  DU_WrongMethod = 11351;
  PR_Archive = 11401;
  PR_CopyZipFile = 11402;
  PR_SFX = 11403;
  PR_Header = 11404;
  PR_Finish = 11405;
  PR_Copying = 11406;
  PR_CentrlDir = 11407;
  PR_Checking = 11408;
  PR_Loading = 11409;
  PR_Joining = 11410;
  PR_Splitting = 11411;
  DZ_Skipped = 11450;
  DZ_InUse = 11451;
  DZ_Refused = 11452;
  DZ_NoOpen = 11453;
  DZ_NoFiles = 11454;
  DZ_SizeChanged = 11455;
  DZ_InvalidName = 11456;
  DZ_TooBig = 11457;
  WZ_DropDirOnly = 11500;
  WZ_NothingToWrite = 11501;
  TM_Erasing = 11600;
  TM_Deleting = 11601;
  TM_GetNewDisk = 11602;
  TM_SystemError = 11603;
 
const
  PR_Progress = PR_Archive - 1;
 
// name of compressed resource data
const 
  DZRES_Str = 11610;  // compressed language strings
  RDLL_Ver = 11612;   // stored UPX Dll version as string
  RDLL_Dll  = 11613;  // stored UPX Dll
 
implementation
 
end.
