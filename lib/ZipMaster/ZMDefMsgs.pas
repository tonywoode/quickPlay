Unit ZMDefMsgs;
 
(* Built by ZipResMaker
   DO NOT MODIFY
  ZMDefMsgs.pas - default messages and compressed tables
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
 
{$I ZipConfig.inc} 
{$INCLUDE '.\ZipVers.inc'}
 
Interface
 
Uses
  ZipMsg;
 
{$IFNDEF USE_COMPRESSED_STRINGS}
 
type
  TZipResRec = packed record
    i: Word;
    s: pResStringRec;
  end;
 
ResourceString
  _DT_Language = 'US: default';
  _DT_Author = 'R.Peters';
  _DT_Desc = 'Language Neutral';
  _GE_FatalZip = 'Fatal Error in DLL: abort exception';
  _GE_NoZipSpecified = 'Error - no zip file specified!';
  _GE_NoMem = 'Requested memory not available';
  _GE_WrongPassword = 'Error - passwords do NOT match'#10'Password ignored';
  _GE_CopyFile = 'Copying: ';
  _GE_Except = 'Exception in Event handler ';
  _GE_Reentered = 'Was busy, Instructions may have been lost!';
  _GE_Busy = ' Busy, Please wait';
  _GE_Inactive = 'not Active';
  _GE_RangeError = 'Index (%d) outside range 1..%d';
  _GE_TempZip = 'Temporary zipfile: %s';
  _GE_WasBusy = 'Busy + %s';
  _GE_EventEx = 'Exception in Event ';
  _GE_DLLAbort = 'DLL Error - Aborting';
  _GE_DLLBusy = 'DLL Error - Busy';
  _GE_DLLCancel = 'DLL Error - User Cancelled';
  _GE_DLLMem = 'DLL Error - Not enough memory';
  _GE_DLLStruct = 'DLL Error - Invalid structure';
  _GE_DLLEvent = 'DLL Error - Exception in handler ';
  _GE_DLLCritical = 'critical DLL Error %d';
  _GE_Unknown = ' Unknown error %d';
  _GE_Skipped = 'Skipped %s %d';
  _RN_ZipSFXData = 'Error while copying the SFX header';
  _RN_NoRenOnSpan = 'Rename is not implemented for a spanned zip file';
  _RN_ProcessFile = 'Processing: ';
  _RN_RenameTo = ' renamed to: ';
  _RN_InvalidDateTime = 'Invalid date/time argument for file: ';
  _PW_UnatAddPWMiss = 'Error - no add password given';
  _PW_UnatExtPWMiss = 'Error - no extract password given';
  _PW_Caption = 'Password';
  _PW_MessageEnter = 'Enter Password ';
  _PW_MessageConfirm = 'Confirm Password ';
  _PW_ForFile = ' for file: ';
  _CF_SourceIsDest = 'Source archive is the same as the destination archive!';
  _CF_OverwriteYN = 'Overwrite file ''%s'' in ''%s'' ?';
  _CF_CopyFailed = 'Copying a file from ''%s'' to ''%s'' failed';
  _CF_SourceNotFound = 'File ''%s'' is not present in ''%s''!';
  _CF_SFXCopyError = 'Error while copying the SFX data';
  _CF_DestFileNoOpen = 'Destination zip archive could not be opened!';
  _CF_NoCopyOnSpan = 'CopyZippedFiles is not implemented for a spanned zip file';
  _LI_ReadZipError = 'Seek error reading Zip archive!';
  _LI_ErrorUnknown = 'Unknown error in List() function'#10;
  _LI_WrongZipStruct = 'Warning - Error in zip structure!';
  _LI_GarbageAtEOF = 'Warning - Garbage at the end of the zipfile!';
  _LI_FileTooBig = 'File larger than 4GB';
  _LI_MethodUnknown = 'Unknown Compression Method';
  _ZB_Yes = '&Yes';
  _ZB_No = '&No';
  _ZB_OK = '&OK';
  _ZB_Cancel = '&Cancel';
  _ZB_Abort = '&Abort';
  _ZB_Retry = '&Retry';
  _ZB_Ignore = '&Ignore';
  _ZB_CancelAll = 'CancelAll';
  _ZB_NoToAll = 'NoToAll';
  _ZB_YesToAll = 'YesToAll';
  _AD_NothingToZip = 'Error - no files to zip!';
  _AD_UnattPassword = 'Unattended action not possible without a password';
  _AD_NoFreshenUpdate = 'AddFreshen or AddUpdate not possible on a spanned archive';
  _AD_AutoSFXWrong = 'Error %.1d occurred during Auto SFX creation.';
  _AD_InIsOutStream = 'Input stream may not be set to the output stream';
  _AD_InvalidName = 'Wildcards are not allowed in Filename or file specification';
  _AD_NoDestDir = 'Destination directory ''%s'' must exist!';
  _DL_NothingToDel = 'Error - no files selected for deletion';
  _DL_NoDelOnSpan = 'Delete Files from archive is not implemented for a spanned zip file';
  _EX_FatalUnZip = 'Fatal Error in UnzDLL.DLL: abort exception';
  _EX_UnAttPassword = 'Warning - Unattended Extract: possible not all files extracted';
  _EX_NoExtrDir = 'Extract directory ''%s'' must exist';
  _LD_NoDll = 'Failed to load %s';
  _LD_BadDll = 'Unable to load %s - It is old or corrupt';
  _LD_DllLoaded = 'Loaded %s';
  _LD_DllUnloaded = 'Unloaded %s';
  _SF_StringTooLong = 'Error - On or more of the 4 property strings mentioned below exceeds 255 characters!';
  _SF_NoZipSFXBin = 'Error: SFX stub ''%s'' not found!';
  _SF_InputIsNoZip = 'Error: input file is not a zip file';
  _SF_NoSFXSupport = 'SFX Functions not supported';
  _SF_MsgTooLong = 'SFX Message string exceeds 255 characters!';
  _SF_DefPathTooLong = 'SFX Default path exceeds 255 characters!';
  _SF_DlgTitleTooLong = 'SFX Dialog title exceeds 255 characters!';
  _SF_CmdLineTooLong = 'SFX Command line exceeds 255 characters!';
  _SF_FBkPathTooLong = 'SFX Fallback path exceeds 255 characters!';
  _CZ_NoExeSpecified = 'Error - no .EXE file specified';
  _CZ_InputNotExe = 'Error: input file is not an .EXE file';
  _CZ_SFXTypeUnknown = 'Error determining the type of SFX archive';
  _CZ_WrongConvert = 'Can only convert ZIP to EXE or EXE to ZIP';
  _CZ_UnknownHeader = 'Unknown SFX header format in %s';
  _CZ_BrowseError = 'Error while browsing resources.';
  _CZ_NoExeResource = 'No resources found in executable.';
  _CZ_ExeSections = 'Error while reading executable sections.';
  _CZ_NoExeIcon = 'No icon resources found in executable.';
  _CZ_NoIcon = 'No icon found.';
  _CZ_NoCopyIcon = 'Cannot copy icon.';
  _CZ_NoIconFound = 'No matching icon found.';
  _DS_NoInFile = 'Input file does not exist';
  _DS_FileOpen = 'Zip file could not be opened';
  _DS_NotaDrive = 'Not a valid drive: %s';
  _DS_DriveNoMount = 'Drive %s is NOT defined';
  _DS_NoVolume = 'Volume label could not be set';
  _DS_NoMem = 'Not enough memory to display MsgBox';
  _DS_Canceled = 'User canceled operation';
  _DS_FailedSeek = 'Seek error in input file';
  _DS_NoOutFile = 'Creation of output file failed';
  _DS_NoWrite = 'Write error in output file';
  _DS_EOCBadRead = 'Error while reading the End Of Central Directory';
  _DS_LOHBadRead = 'Error while reading a local header';
  _DS_CEHBadRead = 'Error while reading a central header';
  _DS_LOHWrongSig = 'A local header signature is wrong';
  _DS_CEHWrongSig = 'A central header signature is wrong';
  _DS_LONameLen = 'Error while reading a local file name';
  _DS_CENameLen = 'Error while reading a central file name';
  _DS_LOExtraLen = 'Error while reading a local extra field';
  _DS_CEExtraLen = 'Error while reading a central extra field';
  _DS_DataDesc = 'Error while reading/writing a data descriptor area';
  _DS_ZipData = 'Error while reading zipped data';
  _DS_CECommentLen = 'Error while reading a file comment';
  _DS_EOArchComLen = 'Error while reading the archive comment';
  _DS_ErrorUnknown = 'UnKnown error in function ReadSpan(), WriteSpan(), ChangeFileDetails() or CopyZippedFiles()'#10;
  _DS_NoUnattSpan = 'Unattended disk spanning not implemented';
  _DS_EntryLost = 'A local header not found in internal structure';
  _DS_NoTempFile = 'Temporary file could not be created';
  _DS_LOHBadWrite = 'Error while writing a local header';
  _DS_CEHBadWrite = 'Error while writing a central header';
  _DS_EOCBadWrite = 'Error while writing the End Of Central Directory';
  _DS_ExtWrongSig = 'Error while reading a Extended Local signature';
  _DS_NoDiskSpace = 'This disk has not enough free space available';
  _DS_InsertDisk = 'Please insert last disk';
  _DS_InsertVolume = 'Please insert disk volume %.1d of %.1d';
  _DS_InDrive = ''#10'in drive: %s';
  _DS_NoValidZip = 'This archive is not a valid Zip archive';
  _DS_FirstInSet = 'This is the first disk in a backup set,'#10'please insert the last disk of this set';
  _DS_NotLastInSet = 'This is the %dth disk in a backup set,'#10'please insert the last disk of this set';
  _DS_AskDeleteFile = 'There is already a file %s'#10'Do you want to overwrite this file';
  _DS_AskPrevFile = 'ATTENTION: This is previous disk no %d!!!'#10'Are you sure you want to overwrite the contents';
  _DS_NoSFXSpan = 'Error - Self extracting archives(.exe) can not be spanned';
  _DS_CEHBadCopy = 'Error while copying a filename of a CEH structure';
  _DS_EOCBadSeek = 'Seek error while skipping a EOC structure';
  _DS_EOCBadCopy = 'Error while copying the zip archive comment';
  _DS_FirstFileOnHD = 'This is the first file in a backup set,'#10'please choose the last file of this set';
  _DS_InsertAVolume = 'Please insert disk volume %.1d';
  _DS_CopyCentral = 'Central directory';
  _DS_NoDiskSpan = 'DiskSpanning not supported';
  _DS_UnknownError = 'Unknown Error';
  _DS_NoRenamePart = 'Last part left as : %s';
  _DS_NotChangeable = 'Cannot write to %s';
  _FM_Erase = 'Erase %s';
  _FM_Confirm = 'Confirm';
  _CD_NoCDOnSpan = 'ChangeFileDetails is not implemented for a spanned zip file';
  _CD_NoEventHndlr = 'No Event Handler found to Change File Details';
  _CD_LOExtraLen = 'Error while writing a local extra field';
  _CD_CEExtraLen = 'Error while writing a central extra field';
  _CD_CEComLen = 'Error while writing a file comment';
  _CD_CEHDataSize = 'The combined length of CEH + FileName + FileComment + ExtraData exceeds 65535';
  _CD_Changing = 'Changing details of: ';
  _CD_DuplFileName = 'Duplicate Filename: %s';
  _CD_NoProtected = 'Cannot change details of Excrypted file';
  _CD_InvalidFileName = 'Invalid Filename: ''%s''';
  _CD_NoChangeDir = 'Cannot change path';
  _CD_FileSpecSkip = 'Filespec ''%s'' skipped';
  _DU_InvalidName = 'Invalid name ''%s''';
  _DU_WrongMethod = 'unsupported compression for ''%s''';
  _PR_Archive = '*Resetting Archive bit';
  _PR_CopyZipFile = '*Copying Zip File';
  _PR_SFX = '*SFX';
  _PR_Header = '*??';
  _PR_Finish = '*Finalising';
  _PR_Copying = '*Copying';
  _PR_CentrlDir = '*Central Directory';
  _PR_Checking = '*Checking';
  _PR_Loading = '*Loading Directory';
  _PR_Joining = '*Joining split zip file';
  _PR_Splitting = '*Splitting zip file';
  _DZ_Skipped = 'Filespec ''%s'' skipped';
  _DZ_InUse = 'Can not open in-use file ''%s''';
  _DZ_Refused = 'not permitted to open ''%s''';
  _DZ_NoOpen = 'Can not open ''%s''';
  _DZ_NoFiles = 'no files found';
  _DZ_SizeChanged = 'size of ''%s'' changed';
  _DZ_InvalidName = '''%s'' is not valid name';
  _DZ_TooBig = 'file is too big';
  _WZ_DropDirOnly = 'Dropping %d empty directory entries';
  _WZ_NothingToWrite = 'Nothing to write';
  _TM_Erasing = 'EraseFloppy - Removing %s';
  _TM_Deleting = 'EraseFloppy - Deleting %s';
  _TM_GetNewDisk = 'Trace : GetNewDisk Opening: %s';
  _TM_SystemError = 'System error: %d';
 
const
ResTable: array [0..187] of TZipResRec = (
    (i: DT_Language; s: @_DT_Language),
    (i: DT_Author; s: @_DT_Author),
    (i: DT_Desc; s: @_DT_Desc),
    (i: GE_FatalZip; s: @_GE_FatalZip),
    (i: GE_NoZipSpecified; s: @_GE_NoZipSpecified),
    (i: GE_NoMem; s: @_GE_NoMem),
    (i: GE_WrongPassword; s: @_GE_WrongPassword),
    (i: GE_CopyFile; s: @_GE_CopyFile),
    (i: GE_Except; s: @_GE_Except),
    (i: GE_Reentered; s: @_GE_Reentered),
    (i: GE_Busy; s: @_GE_Busy),
    (i: GE_Inactive; s: @_GE_Inactive),
    (i: GE_RangeError; s: @_GE_RangeError),
    (i: GE_TempZip; s: @_GE_TempZip),
    (i: GE_WasBusy; s: @_GE_WasBusy),
    (i: GE_EventEx; s: @_GE_EventEx),
    (i: GE_DLLAbort; s: @_GE_DLLAbort),
    (i: GE_DLLBusy; s: @_GE_DLLBusy),
    (i: GE_DLLCancel; s: @_GE_DLLCancel),
    (i: GE_DLLMem; s: @_GE_DLLMem),
    (i: GE_DLLStruct; s: @_GE_DLLStruct),
    (i: GE_DLLEvent; s: @_GE_DLLEvent),
    (i: GE_DLLCritical; s: @_GE_DLLCritical),
    (i: GE_Unknown; s: @_GE_Unknown),
    (i: GE_Skipped; s: @_GE_Skipped),
    (i: RN_ZipSFXData; s: @_RN_ZipSFXData),
    (i: RN_NoRenOnSpan; s: @_RN_NoRenOnSpan),
    (i: RN_ProcessFile; s: @_RN_ProcessFile),
    (i: RN_RenameTo; s: @_RN_RenameTo),
    (i: RN_InvalidDateTime; s: @_RN_InvalidDateTime),
    (i: PW_UnatAddPWMiss; s: @_PW_UnatAddPWMiss),
    (i: PW_UnatExtPWMiss; s: @_PW_UnatExtPWMiss),
    (i: PW_Caption; s: @_PW_Caption),
    (i: PW_MessageEnter; s: @_PW_MessageEnter),
    (i: PW_MessageConfirm; s: @_PW_MessageConfirm),
    (i: PW_ForFile; s: @_PW_ForFile),
    (i: CF_SourceIsDest; s: @_CF_SourceIsDest),
    (i: CF_OverwriteYN; s: @_CF_OverwriteYN),
    (i: CF_CopyFailed; s: @_CF_CopyFailed),
    (i: CF_SourceNotFound; s: @_CF_SourceNotFound),
    (i: CF_SFXCopyError; s: @_CF_SFXCopyError),
    (i: CF_DestFileNoOpen; s: @_CF_DestFileNoOpen),
    (i: CF_NoCopyOnSpan; s: @_CF_NoCopyOnSpan),
    (i: LI_ReadZipError; s: @_LI_ReadZipError),
    (i: LI_ErrorUnknown; s: @_LI_ErrorUnknown),
    (i: LI_WrongZipStruct; s: @_LI_WrongZipStruct),
    (i: LI_GarbageAtEOF; s: @_LI_GarbageAtEOF),
    (i: LI_FileTooBig; s: @_LI_FileTooBig),
    (i: LI_MethodUnknown; s: @_LI_MethodUnknown),
    (i: ZB_Yes; s: @_ZB_Yes),
    (i: ZB_No; s: @_ZB_No),
    (i: ZB_OK; s: @_ZB_OK),
    (i: ZB_Cancel; s: @_ZB_Cancel),
    (i: ZB_Abort; s: @_ZB_Abort),
    (i: ZB_Retry; s: @_ZB_Retry),
    (i: ZB_Ignore; s: @_ZB_Ignore),
    (i: ZB_CancelAll; s: @_ZB_CancelAll),
    (i: ZB_NoToAll; s: @_ZB_NoToAll),
    (i: ZB_YesToAll; s: @_ZB_YesToAll),
    (i: AD_NothingToZip; s: @_AD_NothingToZip),
    (i: AD_UnattPassword; s: @_AD_UnattPassword),
    (i: AD_NoFreshenUpdate; s: @_AD_NoFreshenUpdate),
    (i: AD_AutoSFXWrong; s: @_AD_AutoSFXWrong),
    (i: AD_InIsOutStream; s: @_AD_InIsOutStream),
    (i: AD_InvalidName; s: @_AD_InvalidName),
    (i: AD_NoDestDir; s: @_AD_NoDestDir),
    (i: DL_NothingToDel; s: @_DL_NothingToDel),
    (i: DL_NoDelOnSpan; s: @_DL_NoDelOnSpan),
    (i: EX_FatalUnZip; s: @_EX_FatalUnZip),
    (i: EX_UnAttPassword; s: @_EX_UnAttPassword),
    (i: EX_NoExtrDir; s: @_EX_NoExtrDir),
    (i: LD_NoDll; s: @_LD_NoDll),
    (i: LD_BadDll; s: @_LD_BadDll),
    (i: LD_DllLoaded; s: @_LD_DllLoaded),
    (i: LD_DllUnloaded; s: @_LD_DllUnloaded),
    (i: SF_StringTooLong; s: @_SF_StringTooLong),
    (i: SF_NoZipSFXBin; s: @_SF_NoZipSFXBin),
    (i: SF_InputIsNoZip; s: @_SF_InputIsNoZip),
    (i: SF_NoSFXSupport; s: @_SF_NoSFXSupport),
    (i: SF_MsgTooLong; s: @_SF_MsgTooLong),
    (i: SF_DefPathTooLong; s: @_SF_DefPathTooLong),
    (i: SF_DlgTitleTooLong; s: @_SF_DlgTitleTooLong),
    (i: SF_CmdLineTooLong; s: @_SF_CmdLineTooLong),
    (i: SF_FBkPathTooLong; s: @_SF_FBkPathTooLong),
    (i: CZ_NoExeSpecified; s: @_CZ_NoExeSpecified),
    (i: CZ_InputNotExe; s: @_CZ_InputNotExe),
    (i: CZ_SFXTypeUnknown; s: @_CZ_SFXTypeUnknown),
    (i: CZ_WrongConvert; s: @_CZ_WrongConvert),
    (i: CZ_UnknownHeader; s: @_CZ_UnknownHeader),
    (i: CZ_BrowseError; s: @_CZ_BrowseError),
    (i: CZ_NoExeResource; s: @_CZ_NoExeResource),
    (i: CZ_ExeSections; s: @_CZ_ExeSections),
    (i: CZ_NoExeIcon; s: @_CZ_NoExeIcon),
    (i: CZ_NoIcon; s: @_CZ_NoIcon),
    (i: CZ_NoCopyIcon; s: @_CZ_NoCopyIcon),
    (i: CZ_NoIconFound; s: @_CZ_NoIconFound),
    (i: DS_NoInFile; s: @_DS_NoInFile),
    (i: DS_FileOpen; s: @_DS_FileOpen),
    (i: DS_NotaDrive; s: @_DS_NotaDrive),
    (i: DS_DriveNoMount; s: @_DS_DriveNoMount),
    (i: DS_NoVolume; s: @_DS_NoVolume),
    (i: DS_NoMem; s: @_DS_NoMem),
    (i: DS_Canceled; s: @_DS_Canceled),
    (i: DS_FailedSeek; s: @_DS_FailedSeek),
    (i: DS_NoOutFile; s: @_DS_NoOutFile),
    (i: DS_NoWrite; s: @_DS_NoWrite),
    (i: DS_EOCBadRead; s: @_DS_EOCBadRead),
    (i: DS_LOHBadRead; s: @_DS_LOHBadRead),
    (i: DS_CEHBadRead; s: @_DS_CEHBadRead),
    (i: DS_LOHWrongSig; s: @_DS_LOHWrongSig),
    (i: DS_CEHWrongSig; s: @_DS_CEHWrongSig),
    (i: DS_LONameLen; s: @_DS_LONameLen),
    (i: DS_CENameLen; s: @_DS_CENameLen),
    (i: DS_LOExtraLen; s: @_DS_LOExtraLen),
    (i: DS_CEExtraLen; s: @_DS_CEExtraLen),
    (i: DS_DataDesc; s: @_DS_DataDesc),
    (i: DS_ZipData; s: @_DS_ZipData),
    (i: DS_CECommentLen; s: @_DS_CECommentLen),
    (i: DS_EOArchComLen; s: @_DS_EOArchComLen),
    (i: DS_ErrorUnknown; s: @_DS_ErrorUnknown),
    (i: DS_NoUnattSpan; s: @_DS_NoUnattSpan),
    (i: DS_EntryLost; s: @_DS_EntryLost),
    (i: DS_NoTempFile; s: @_DS_NoTempFile),
    (i: DS_LOHBadWrite; s: @_DS_LOHBadWrite),
    (i: DS_CEHBadWrite; s: @_DS_CEHBadWrite),
    (i: DS_EOCBadWrite; s: @_DS_EOCBadWrite),
    (i: DS_ExtWrongSig; s: @_DS_ExtWrongSig),
    (i: DS_NoDiskSpace; s: @_DS_NoDiskSpace),
    (i: DS_InsertDisk; s: @_DS_InsertDisk),
    (i: DS_InsertVolume; s: @_DS_InsertVolume),
    (i: DS_InDrive; s: @_DS_InDrive),
    (i: DS_NoValidZip; s: @_DS_NoValidZip),
    (i: DS_FirstInSet; s: @_DS_FirstInSet),
    (i: DS_NotLastInSet; s: @_DS_NotLastInSet),
    (i: DS_AskDeleteFile; s: @_DS_AskDeleteFile),
    (i: DS_AskPrevFile; s: @_DS_AskPrevFile),
    (i: DS_NoSFXSpan; s: @_DS_NoSFXSpan),
    (i: DS_CEHBadCopy; s: @_DS_CEHBadCopy),
    (i: DS_EOCBadSeek; s: @_DS_EOCBadSeek),
    (i: DS_EOCBadCopy; s: @_DS_EOCBadCopy),
    (i: DS_FirstFileOnHD; s: @_DS_FirstFileOnHD),
    (i: DS_InsertAVolume; s: @_DS_InsertAVolume),
    (i: DS_CopyCentral; s: @_DS_CopyCentral),
    (i: DS_NoDiskSpan; s: @_DS_NoDiskSpan),
    (i: DS_UnknownError; s: @_DS_UnknownError),
    (i: DS_NoRenamePart; s: @_DS_NoRenamePart),
    (i: DS_NotChangeable; s: @_DS_NotChangeable),
    (i: FM_Erase; s: @_FM_Erase),
    (i: FM_Confirm; s: @_FM_Confirm),
    (i: CD_NoCDOnSpan; s: @_CD_NoCDOnSpan),
    (i: CD_NoEventHndlr; s: @_CD_NoEventHndlr),
    (i: CD_LOExtraLen; s: @_CD_LOExtraLen),
    (i: CD_CEExtraLen; s: @_CD_CEExtraLen),
    (i: CD_CEComLen; s: @_CD_CEComLen),
    (i: CD_CEHDataSize; s: @_CD_CEHDataSize),
    (i: CD_Changing; s: @_CD_Changing),
    (i: CD_DuplFileName; s: @_CD_DuplFileName),
    (i: CD_NoProtected; s: @_CD_NoProtected),
    (i: CD_InvalidFileName; s: @_CD_InvalidFileName),
    (i: CD_NoChangeDir; s: @_CD_NoChangeDir),
    (i: CD_FileSpecSkip; s: @_CD_FileSpecSkip),
    (i: DU_InvalidName; s: @_DU_InvalidName),
    (i: DU_WrongMethod; s: @_DU_WrongMethod),
    (i: PR_Archive; s: @_PR_Archive),
    (i: PR_CopyZipFile; s: @_PR_CopyZipFile),
    (i: PR_SFX; s: @_PR_SFX),
    (i: PR_Header; s: @_PR_Header),
    (i: PR_Finish; s: @_PR_Finish),
    (i: PR_Copying; s: @_PR_Copying),
    (i: PR_CentrlDir; s: @_PR_CentrlDir),
    (i: PR_Checking; s: @_PR_Checking),
    (i: PR_Loading; s: @_PR_Loading),
    (i: PR_Joining; s: @_PR_Joining),
    (i: PR_Splitting; s: @_PR_Splitting),
    (i: DZ_Skipped; s: @_DZ_Skipped),
    (i: DZ_InUse; s: @_DZ_InUse),
    (i: DZ_Refused; s: @_DZ_Refused),
    (i: DZ_NoOpen; s: @_DZ_NoOpen),
    (i: DZ_NoFiles; s: @_DZ_NoFiles),
    (i: DZ_SizeChanged; s: @_DZ_SizeChanged),
    (i: DZ_InvalidName; s: @_DZ_InvalidName),
    (i: DZ_TooBig; s: @_DZ_TooBig),
    (i: WZ_DropDirOnly; s: @_WZ_DropDirOnly),
    (i: WZ_NothingToWrite; s: @_WZ_NothingToWrite),
    (i: TM_Erasing; s: @_TM_Erasing),
    (i: TM_Deleting; s: @_TM_Deleting),
    (i: TM_GetNewDisk; s: @_TM_GetNewDisk),
    (i: TM_SystemError; s: @_TM_SystemError));
 
{$ELSE}
 
const
 CompBlok: array [0..1037] of Cardinal = (
  $102D0409, $53550002, $00003514, $F0F00035, $FFF0F020, $FFF3F6FF, 
  $02BCABFD, $F706F5F2, $001178F0, $3000DF00, $00040910, $DF000B05, 
  $00530055, $64F0F33A, $0065FF00, $00610066, $6CFF0075, $08007400, 
  $D7005200, $3B50002E, $003B7400, $73DF0072, $4C001000, $006E003F, 
  $00416755, $65006161, $3B4EF0F3, $4575D500, $003F7200, $2302006C, 
  $3F467500, $02777400, $55450020, $00727700, $2000556F, $005F6900, 
  $440020D7, $354C005B, $F5006102, $74029362, $0065F0F3, $63D50078, 
  $4570003B, $00936900, $1ED5006E, $F32D0A8D, $00936EF0, $7A550020, 
  $F3700099, $009966F0, $5502696C, $6500BD73, $E76900B9, $00396502, 
  $00C72155, $71003B52, $57650041, $0152AA00, $6DF0F364, $936D003B, 
  $D71C7902, $6101B204, $003F7600, $01AA01EA, $2F01ECD2, $00BD0DC9, 
  $73005761, $9377C500, $00576402, $01DC0138, $4FE7004E, $12195400, 
  $00630184, $0A00A368, $1B58004D, $D9670198, $FF2E7202, $43000902, 
  $25700093, $45019A10, $1B023567, $0DB8008D, $33450598, $5F652910, 
  $6801B200, $EB64025D, $57019602, $5757002A, $00AB2012, $97005775, 
  $F32C0079, $005F49F0, $02721112, $BF630041, $78116606, $E0112611, 
  $AA11D611, $D76511F8, $00432012, $2112116F, $F312002B, $18FB42F0, 
  $5802EB50, $016A4A11, $74123577, $152A1081, $D2241141, $051E11D6, 
  $78013A22, $0028F0F3, $00392555, $6FF0F329, $99730271, $013AA200, 
  $60027520, $31016A01, $522E004B, $73152291, $70111E10, $23610293, 
  $03E06814, $013605E8, $F0005725, $71091201, $A30D1F79, $20254A10, 
  $24E52B00, $1DB91321, $14D91DC9, $9F140500, $120B8C04, $AB4101D6, 
  $1013AE06, $06D13D51, $1A49254A, $06D13D7B, $96225D55, $025D4301, 
  $6C01BA3A, $006402EB, $D13D9D1D, $2B4E1106, $9A11D814, $107F6721, 
  $3DD21B1A, $0607D088, $6C113421, $01F022A1, $8275270C, $0F21129D, 
  $2206D14D, $E037323D, $B90A151D, $22677200, $8800B969, $964D4C03, 
  $2192BA01, $6E32B311, $02D96B00, $029B2877, $49AE0154, $6B00330D, 
  $01F402E1, $E8111838, $0043B421, $F6F1F600, $7A51011A, $5D1A2DFB, 
  $8D225624, $107F770A, $6305EAAA, $45201AA7, $02696800, $0081E253, 
  $5A427B58, $72013A21, $07823000, $003F6E12, $0198111C, $152A1166, 
  $22C5A069, $111C01EC, $131611DA, $61049366, $5E04EF24, $14156E01, 
  $4D0C0DE0, $88019200, $115A01BA, $A70D17AE, $18577E22, $935C7411, 
  $00013600, $2AED4C00, $045D0B7B, $4D282091, $42028364, $8401C011, 
  $2021CE53, $55A20162, $29DC57AE, $531D5724, $4804D94D, $11185172, 
  $61201D56, $6E237C00, $8C001003, $B603DA6D, $12037401, $B86DA821, 
  $0DF1F06B, $001D8308, $A6008D0F, $10019653, $B920297D, $6E11A640, 
  $1B7202E7, $507D2C10, $032C1118, $23E26D6A, $7D0A1160, $98126D23, 
  $00333676, $B972219A, $7E635802, $237C0811, $555E5588, $F4568173, 
  $3A555E13, $1112A001, $0184019A, $7BB8352E, $4F400D21, $7212D542, 
  $4392105D, $07E8016A, $0922E727, $36069727, $80353F87, $53B61BA6, 
  $660107E8, $714E0291, $610A8736, $013E8934, $020203EA, $8D2D4611, 
  $00BD5D87, $215E119E, $408213DA, $0C8B218B, $5D525D42, $63465962, 
  $20010261, $2F7DEF44, $B855CC34, $4291007D, $1118C001, $2132152A, 
  $01F42198, $002153C4, $16A53905, $A448E35A, $8A116685, $A85D9A5D, 
  $5DBA5DAA, $98655DCA, $2AED9678, $7D8F487E, $F0F0AD1E, $3400331F, 
  $4CCB6B21, $72119E20, $8C950851, $219D4893, $4DBE1003, $9A49CE94, 
  $92A34C03, $96208F74, $41486621, $C031C400, $10030A05, $5F7211F2, 
  $95084000, $AD864360, $4D3895E6, $B72C4148, $02D50AAD, $6222CD47, 
  $01840665, $11D8970E, $6F111822, $970E003D, $4F212BD6, $E087A430, 
  $615C113A, $911013EA, $0020015E, $B00F0234, $74309B42, $C611A6AD, 
  $A083C821, $33304A21, $68024F4D, $41F80093, $E2204900, $0F7F0912, 
  $E0BDD6AD, $260004B6, $0F59008B, $B0F10312, $B1FA31EC, $4B004F4F, 
  $B0F10700, $330039C0, $09121A10, $00BDC780, $6AB0F106, $14C13C37, 
  $01741108, $49C20979, $11A41897, $419537C2, $EB0732C9, $00935432, 
  $5008C376, $C782B4F3, $C3A4CD9D, $842AED24, $D204CD2B, $18C8DECD, 
  $04D96DC7, $73CA05E8, $210107DC, $B18020B5, $01520184, $11182386, 
  $2E0063E6, $3E87BE35, $3E21A021, $68216213, $48B1AE21, $93D00172, 
  $75396DEE, $4661A420, $601084C7, $94019C51, $55D38603, $654600BD, 
  $5450DD44, $D48500D9, $9CAD609D, $C3852AED, $00D524CD, $B52E4BAA, 
  $63B33220, $414400B9, $38139E10, $08414401, $02714195, $556601DC, 
  $5A419048, $2E05C021, $22050121, $00D46970, $215A230A, $2520714E, 
  $215E9B66, $01DCB322, $9A951090, $82ED7C23, $10F13B51, $406401EA, 
  $15624299, $D9B221CE, $213C0178, $80141577, $85A4039A, $7B6E5780, 
  $419A0DF0, $802605C0, $362D9D29, $119EA150, $15222112, $486D8736, 
  $05B212FB, $DE21A398, $F2F4A4CD, $8B094AFD, $F0F0ED07, $FFCDEF26, 
  $30E4A5CD, $211220F1, $013A9BC4, $05C0F130, $18F25143, $016A0003, 
  $87729998, $9DA49D4A, $9DC49DB4, $E4B8DDD8, $B599F49D, $3200000D, 
  $04912AED, $08E2FDC3, $2280A32A, $CC419E93, $0543BCAD, $2E44A17A, 
  $11B444A1, $336E113C, $6802F390, $ADFB3E4B, $DD2434B1, $41649162, 
  $B44067E2, $F4DDBE11, $DEDB04ED, $00917C6B, $E0D062C5, $7AFD6A6B, 
  $74FD8AFD, $BA000DE2, $9A4AFD22, $2D3A0DD7, $F3112240, $10859A02, 
  $F1028584, $23E65172, $90145D28, $102D6015, $432443F0, $013C0364, 
  $8A945F6F, $8A9100A3, $6B751102, $A0950942, $47EA2368, $125D500B, 
  $47EA2566, $FE03C4E8, $2D2BA449, $54503002, $8017FDD7, $4306D798, 
  $B9389370, $84C33401, $C1469374, $A3E6E196, $41F2A3C0, $A0656200, 
  $6E6304B3, $34F30291, $F2917C17, $00328741, $FE30A735, $BA417E81, 
  $F1827217, $A0312140, $717C1700, $F1565566, $C0414075, $95668944, 
  $A1A60180, $C523917E, $F10E403C, $F72CE5C4, $01880B5A, $591B0D9C, 
  $A54609E6, $73095CAC, $118622BF, $917CC146, $E6592A01, $D1C2B1A8, 
  $3966B518, $3DA43D94, $283DB402, $0126E659, $915E8196, $B16E65EA, 
  $BA4DAA50, $DA4DCA4D, $02F96949, $00940B6F, $F3308124, $5D0E4DFE, 
  $35D45D1E, $E192B390, $3EB33040, $4ED1E261, $6E5D5E5D, $484D295D, 
  $1613A004, $A23963B1, $5DA84DF4, $35BC5DB8, $E229404A, $07AA7A81, 
  $1E684A3D, $9B0A3D1B, $00FF2E64, $2A00FF58, $7CF73AFD, $05258191, 
  $254D154D, $10D2354D, $656D72F1, $00A09F10, $26011419, $F20D6D73, 
  $31609D08, $40919290, $4A35D435, $C40D290B, $A46CD3CE, $9100E295, 
  $6C84196E, $209D5AD1, $86834050, $A38A65D4, $838665D4, $7F1F735C, 
  $E65900BD, $23E471E8, $A18AF328, $87D2E192, $C4142194, $628BF239, 
  $9D77A287, $C8A3C2B2, $915C0883, $F154014C, $FE80E32E, $3A7DF6B1, 
  $35FA4005, $1136F50C, $D16A0100, $9D2E257A, $7DCE80A0, $AD4A657E, 
  $65808D3A, $45600300, $B4FB802E, $734CF10C, $8D228D12, $8B428D32, 
  $8DA3040E, $4F2E38F7, $66C30E20, $8821B895, $87A8D491, $B94EE172, 
  $6D3FABBA, $0D001700, $4E73BA84, $F8A3C203, $8393088D, $459D939D, 
  $B0AA0190, $9DC29D43, $7719C0B0, $677C42EA, $F4A08964, $92E59AF3, 
  $A6591CF7, $B8677C80, $2C41EC21, $58EB9AE1, $15D3E233, $6CB2FD14, 
  $02F976D5, $46E43D69, $840154E1, $21941126, $60002517, $5A2592A5, 
  $05E24E03, $041154C0, $D3E2F140, $8256001D, $1F7522A9, $8AB160F4, 
  $9CAD1C33, $031074ED, $96A54640, $6781CAD1, $017252F1, $96403338, 
  $707364E1, $60018C81, $4DE196B1, $67152095, $376FB07B, $105D1710, 
  $23B4F1FA, $96C71090, $5E355803, $E00FA0F7, $04B1B7BC, $C0ED9DB3, 
  $E852FB53, $04611C51, $026DA81B, $231E6180, $40EB6400, $7CEBBE35, 
  $0241E867, $D91A2556, $2EE146E0, $BEBD8003, $41657CBD, $618D5130, 
  $FF7D018D, $4F539200, $43413243, $117A0473, $513601FC, $1B221BDE, 
  $CD2B80CD, $01881651, $E1E2F102, $79A6C166, $CD7D4024, $CA9DCD8D, 
  $C95E113A, $852179A6, $CDA888D0, $D15479A8, $44145F67, $7767BAE1, 
  $54120304, $D20D2311, $DD1ECDF0, $DD3EDD2E, $6A976781, $CDDECDCE, 
  $677CDB10, $0027F51C, $DDA9DD99, $CA5DCDE3, $DDE2DDD2, $ED02DDF2, 
  $B4D91210, $B6637A17, $6CE364A1, $ED52ED42, $6EED1288, $32E37EED, 
  $ED95ED85, $482F1451, $5146D245, $F564E956, $73031204, $6A00F043, 
  $82113E31, $CCE39E05, $70EDE87D, $00433C87, $A35A315A, $CD7C03F6, 
  $EB54FD4E, $518CAB14, $340374C0, $3AFD8EED, $B47D28CD, $5A0602FD, 
  $63B209CA, $5D5C00BD, $78934B12, $7ABDF2B8, $204B5861, $846B5200, 
  $048D8A53, $2C703728, $B7E600CB, $04430D72, $1154620F, $7E405565, 
  $8441E463, $02617E81, $6F292172, $22518876, $6EA30C91, $0205A8F3, 
  $730A03BC, $081D6426, $8651E8B3, $04931261, $45301552, $0E508D69, 
  $78A1F6B1, $01619433, $A5DD0D2E, $D03DF07C, $F681D487, $24E12C63, 
  $439EC166, $8012E175, $301923D3, $7800A1F6, $62F1F643, $C2AD1431, 
  $AA13BAAD, $006194B5, $F7D4FD7E, $ED5EFD02, $1DEACDB6, $EDA81DFA, 
  $ACDD5C00, $3CCD1A73, $44F7082D, $64CD54CD, $C57420CD, $2D7A61D2, 
  $270AFDD8, $FAE2C345, $634C2909, $65DD74E8, $E7546067, $10610222, 
  $61101706, $A9E89BF4, $82129966, $10611665, $A152F3F2, $8586617E, 
  $80708917, $40314E61, $416463BA, $A1B07554, $1704A106, $543D9326, 
  $17063AA3, $25AAA376, $3D319081, $711E44B4, $EB0D35F8, $5E83D400, 
  $F0C373AD, $F6373800, $506DBEFD, $38A50CAB, $3AA18C4B, $D3880035, 
  $619025A0, $3BDC611E, $415683D4, $750955E2, $A3D6A20F, $2E00EB2C, 
  $563DCA13, $25A08073, $51E83DB0, $21A0731C, $A3D6D388, $4D7D044E, 
  $AB25269F, $A253F070, $C24DB24D, $4DD2204D, $4DF24DE2, $57125D02, 
  $2A32373D, $474440B1, $25F2E1BC, $FBA8A1FE, $C50AA17E, $71828220, 
  $E4325F79, $84911221, $6F718253, $907451E0, $3A730E25, $00657C35, 
  $03B5E800, $23B39936, $5159000D, $9F2A54D0, $521B4510, $4EA08B49, 
  $5D1E62A3, $12997015, $75B2B176, $61C43C3D, $21455334, $510A62A5, 
  $F8D382D0, $D67F7355, $085DF8C0, $BA6D186D, $BA133815, $05007321, 
  $2D2AD939, $A1B6729B, $E7C2B1BC, $FC08035E, $E6497025, $84D92E01, 
  $B33001C0, $10041DC8, $31113C17, $1AB52DD9, $FDA09122, $2C28218A, 
  $564500E5, $70814341, $991D8948, $75299112, $CF7D87BD, $F4696B72, 
  $084F2BFA, $7DD0900F, $812B119A, $977D917D, $00F4672D, $0D047D3C, 
  $4D8C4D7C, $E72233B4, $5D5A5D4A, $625D6A04, $004B6F91, $5D885374, 
  $5DA4E920, $1EA3D642, $3DD33DC3, $3AF33DE3, $042DB511, $CB6EF2E3, 
  $0A22C51A, $18058C11, $2863BC1D, $014CF16C, $EF0D133A, $083B6B02, 
  $1601873A, $55923017, $35AA0174, $4352A194, $6882A186, $906F12A5, 
  $435093A0, $639E6BE8, $B56C2673, $60483E00, $47B6B758, $A2AD5E6D, 
  $3908A86A, $28953882, $02C90741, $44952A6E, $88B26C6D, $4FBDAA41, 
  $05A0B0AD, $6970E534, $77BCF067, $330605A8, $441121BE, $D388F617, 
  $A3723188, $A0014E02, $735E9021, $F5F23D80, $6A7921BE, $3EBA38AD, 
  $C36A3912, $B862ADAF, $AB0D9B3B, $8068750D, $1B321D22, $F3321366, 
  $87687D70, $A42DC512, $61DC6069, $D4827B45, $62D14863, $22890064, 
  $1968014E, $B974A32E, $21C4A7D2, $C40009B2, $062D86FD, $C8ED642D, 
  $56ED84ED, $002D4CCD, $CD82EDB4, $1DE6C192, $FB08CDA6, $050CFDAC, 
  $4D000027, $D52054BB, $70025162, $73B2A2F3, $02543967, $2B75CA43, 
  $004EA8D1, $D96A76B7, $070A01CA, $ADDCD368, $C1D44156, $3CC1C4B8, 
  $3651CA11, $D0C53500, $D0C50233, $B8B87315, $8C1158C5, $244102B9, 
  $C5160141, $5E81D220, $EE211841, $2CB58063, $472400E5, $8176AB14, 
  $DDE2C724, $31064302, $7951F126, $B5B8F22B, $6516C3FC, $4A596E60, 
  $24ED1094, $44272741, $1690A300, $5720C409, $37AD11BD, $A00174EC, 
  $08DD1521, $6341F16E, $8906E89B, $FD19113C, $4182FB28, $B7C609AA, 
  $11FA54ED, $78B5ED79, $116CF702, $709DB610, $80F3B611, $32237363, 
  $B5BE0364, $CBE79E14, $AA41C6FD, $FAFD47C9, $07F0ECFD, $692A0016, 
  $0A83D802, $7661AED7, $D1420A89, $2A906D74, $C5B806C9, $B5804566, 
  $000F0475, $58B07F53, $000F0300, $006D3F05, $80000F0B, $441384B1, 
  $C1C3B831, $C70D3D08, $B8018CE0, $009D822D, $41AA3500, $FDEBCAAA, 
  $028B0900, $CEA01152, $18079681, $B029F631, $3091790D, $4A00032A, 
  $1174C0F1, $3174C5B8, $4152415E, $13BDDA02, $15340261, $1D3ED70A, 
  $17801D75, $3A011E0B, $0DD3CC69, $A2BA1DAE, $FE04EDEE, $1DF90EED, 
  $7762A413, $D1500190, $2D21933E, $85A6628B, $E59EC3FE, $D076631A, 
  $A1980011, $E36A1358, $250465DA, $916EE59E, $52421DF4, $649B0E2D, 
  $632A75AE, $2314C510, $A9C85032, $E93817D8, $416AF118, $1D9FCDAA, 
  $D890E320, $6A4B4817, $0F71BAFD, $839E8AB5, $3481F4A4, $1DB46703, 
  $41863C4C, $DF08CFAA, $373D7A2D, $100B23A6, $890EC1F0, $D2045136, 
  $74B1A8C1, $9D8052D9, $05A251DA, $7307C18E, $B2EB1000, $855C6324, 
  $67E861DC, $E0A3BA6A, $6BD6AA41, $7B19003D, $734641A8, $DA810EC2, 
  $12711A51, $62DF6D01, $7337A002, $4C334D23, $C1FEB188, $51ECD70A, 
  $D0331EA1, $D11E732E, $1747E19A, $45846554, $20959480, $2304801F, 
  $A50AC3B8, $70E50210, $AE529379, $0A79EEB1, $F9FD18A3, $00000047 );
{$ENDIF}
 
implementation
 
end.
