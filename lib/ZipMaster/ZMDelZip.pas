unit ZMDelZip;

(*
  ZMDelZip.pas - port of DelZip.h (dll interface)
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

  modified 2005-11-05
---------------------------------------------------------------------------*)

interface

uses Windows;

type
  ActionCodes = (zacTick, zacItem, zacProgress, zacEndOfBatch, zacMessage,
    zacCount, zacSize, zacNewName, zacPassword, zacCRCError,
    zacOverwrite, zacSkipped, zacComment, zacStream, zacData,
    zacXItem, zacXProgress, zacExtName, zacKey, zacNone);

const
  Callback_Except_No = 10106;

    { All the items in the CallBackStruct are passed to the Delphi
      program from the DLL.  Note that the "Caller" value returned
      here is the same one specified earlier in ZipParms by the
      Delphi pgm. }
type
  CBFNs = (cbfnOld, cbfnNew, cbfnExtended);     // only used for definition

  ZCallBackStruct = packed record
    Caller:  Pointer;                { "self" reference of the Delphi form }
    Version: Longint;               { version no. of DLL }
    IsOperationZip: Longbool;       { True=zip, False=unzip }
    ActionCode: integer;//Cardinal;
    Arg1: cardinal;    
    MsgP: pAnsiChar;                // pointer to text
    case boolean of
      true: (Msg: array[0..511] of AnsiChar);
      false:(
        FileSize: Int64;
        Written: Int64;
        Msg2P: pAnsiChar;
        Arg2: cardinal;
        Arg3: cardinal;
      );
    end;
  PZCallBackStruct = ^ZCallBackStruct;

(* Declare a function pointer type for the BCB/Delphi callback function, to
 * be called by the DLL to pass updated status info back to BCB/Delphi.*)
type
  ZFunctionPtrType = function(Caller: Pointer; ZCallbackRec: PZCallBackStruct): Longint;
    STDCALL;

 (* These records are very critical.  Any changes in the order of items, the
    size of items, or modifying the number of items, may have disasterous
    results.  You have been warned! *)

type
  UnzFileData = packed record
    fFileSpec: PAnsiChar;
    fFileAltName: PAnsiChar;
    fPassword: PAnsiChar;
    fNotUsed: array[0..3] of Cardinal;
    fMatch: Cardinal;         // used by dll
  end;
  pUnzFileData = ^UnzFileData;

type
  UnzExFileData = packed record
    fFileSpec: PAnsiChar;
    fNotUsed:  array[0..2] of Cardinal;
  end;
  pUnzExFileData = ^UnzExFileData;

type
  UnZipParms2 = packed record
    fHandle: HWND;
    fCaller: Pointer;
    fVersion: Longint;
    ZCallbackFunc: ZFunctionPtrType;
    fTraceEnabled: Longbool;
    fWantedCodePage: Cardinal;
    fPromptToOverwrite: Cardinal;
    pZipPassword: PAnsiChar;
    fTest:  Longbool;
    fComments: Longbool;
    fConvert: Longbool;
    fQuiet: Longbool;
    fVerboseEnabled: Longbool;
    fUpdate: Longbool;
    fFreshen: Longbool;
    fDirectories: Longbool;
    fOverwrite: Longbool;
    fArgc:  Longint;
    pZipFN: PAnsiChar;
    { After this point the record is different from UnZipParms1 }
        { Pointer to an Array of UnzFileData records,
          the last pointer MUST be nil! The UnzDll requires this! }
    fUFDS:  pUnzFileData;     // Pointer to an Array of ExUnzFileData records
    fXUFDS: pUnzExFileData;
    fUseOutStream: Longbool;        // Use Memory stream as output.
    fOutStream: Pointer;            // Pointer to the start of streaam data.
    fOutStreamSize: Longint;        // Size of the output data.
    fUseInStream: Longbool;         // Use memory stream as input.
    fInStream: Pointer;
    // Pointer to the start of the input stream data.
    fInStreamSize: Longint;         // Size of the input data.
    fPwdReqCount: Cardinal;
    // PasswordRequestCount, How many times a password will be asked per file
    fExtractDir: PAnsiChar;
    fNotUsed: array[0..7] of Cardinal;
    fSeven: Longint;
  end;
  pUnZipParms = ^UnZipParms2;


type
  FileData = packed record
    fFileSpec: PAnsiChar;                 // 4
    fFileComment: PAnsiChar;              // 4
    fFileAltName: PAnsiChar;              // 4
    fPassword: PAnsiChar;                 // 4
    fEncrypt:  Longword;               // 4
    fRecurse:  Integer;             // 4
    // use unsigned(-1) for 0 - nz overrides globals
    fFromDate: Cardinal;              // 4
    // use -1 for 0 - nz overrides globals
    fLevel: Integer;                 // 4
    fnotused2: Integer;               // 4
    fRootDir: PAnsiChar;                  // 4
    fNotUsed: array[0..5] of Cardinal; // 16 * 4
  end;
  pFileData = ^FileData;


  ExcludedFileSpec = packed record
    fFileSpec: PAnsiChar;
  end;
  pExcludedFileSpec = ^ExcludedFileSpec;

  ZipParms = packed record
    fHandle: HWND;
    fCaller: Pointer;
    fVersion: Longint;
    ZCallbackFunc: ZFunctionPtrType;
    fTraceEnabled: Longbool;
    pZipPassword: PAnsiChar;
    pSuffix: PAnsiChar;
    fEncrypt: Longbool;
    fSystem: Longbool;
    fVolume: Longbool;
    fExtra: Longbool;
    fNoDirEntries: Longbool;
    fUseDate: Longbool;
    fVerboseEnabled: Longbool;
    fQuiet: Longbool;
    fLevel: Longint;
    fComprSpecial: Longbool;
    fCRLF_LF: Longbool;
    fJunkDir: Longbool;
    fRecurse: Longbool;
    fNoRecurseFiles: Cardinal;
    fGrow: Longbool;
    fForce: Longbool;
    fMove: Longbool;
    fDeleteEntries: Longbool;
    fUpdate: Longbool;
    fFreshen: Longbool;
    fJunkSFX: Longbool;
    fLatestTime: Longbool;
    fDate: Cardinal;
    fArgc: Longint;
    pZipFN: PAnsiChar;
    fTempPath: PAnsiChar;
    fArchComment: PAnsiChar;          //  ZipComment
    fArchiveFilesOnly: Integer;   // only zip when archive bit set
    fResetArchiveBit: Integer;    // reset the archive bit after a successfull zip
    fFDS: pFileData;              // pointer to Array of FileData
    fForceWin: Longbool;
    fTotExFileSpecs: Longint;     // Number of ExcludedFileSpec structures.
    fExFiles: pExcludedFileSpec;  // Array of file specs to exclude from zipping.
    fUseOutStream: Longbool;        // Use memory stream as output.
    fOutStream: Pointer;          // Pointer to the start of the output stream data.
    fOutStreamSize: Longword;       // Size of the Output data.
    fUseInStream: Longbool;         // Use memory stream as input.
    fInStream: Pointer;          // Pointer to the start of the input stream data.
    fInStreamSize: Longword;        // Size of the input data.
    fStrFileAttr: Cardinal;         // File attributes of the file stream.
    fStrFileDate: Cardinal;      // File date/time to set for the streamed file.
    fHowToMove: Longbool;
    fWantedCodePage: Cardinal;
    fWantedOS: Cardinal;
    fVCLVer: Cardinal;
    fGRootDir: PAnsiChar;               // global root directory
    fNotUsed: array[0..1] of Cardinal;
    fSeven: Integer;                // End of record (eg. 7)
  end;
  pZipParms = ^ZipParms;

type
  TUnzExecFunc = function(Rec: pUnZipParms): Integer; STDCALL;
  TZipExecFunc = function(Rec: pZipParms): Integer; STDCALL;
  TDllVersionFunc = function: Integer; STDCALL;
  TDllPrivVersionFunc = function: Integer; STDCALL;
  TAbortOperationFunc = function(Rec: Cardinal): Integer; STDCALL;
  TDllPathFunc = function: PAnsiChar; STDCALL;

const
  CRITICAL_CANCELLED =     -1;
  CRITICAL_ABORT     =     -2;
  CRITICAL_CALLBACK  =     -3;
  CRITICAL_MEMORY    =     -4;
  CRITICAL_STRUCT    =     -5;
  CRITICAL_ERROR     =     -6;

const
//  DefaultDelZipDll_Name = 'DelZip179.dll';
  DelZipDll_Unzfunc = 'DZ_UnzExec';
  DelZipDll_Zipfunc = 'DZ_ZipExec';
  DelZipDll_Abortfunc = 'DZ_Abort';
  DelZipDll_Versfunc = 'DZ_Version';
  DelZipDll_Privfunc = 'DZ_PrivVersion';
  DelZipDll_Pathfunc = 'DZ_Path';
(*
// 'static' loaded dll functions
function DZ_UnzExec(C: pUnZipParms): Integer; STDCALL; EXTERNAL DelZipDll_Name;
function DZ_ZipExec(C: pZipParms): Integer; STDCALL; EXTERNAL DelZipDll_Name;
function DZ_Abort(C: Cardinal): Integer; STDCALL; EXTERNAL DelZipDll_Name;
function DZ_Version: Integer; STDCALL; EXTERNAL DelZipDll_Name;
function DZ_PrivVersion: Integer; STDCALL; EXTERNAL DelZipDll_Name;
function DZ_Path: PAnsiChar; STDCALL; EXTERNAL DelZipDll_Name;
//function DZ_Path(buf: PAnsiChar; len: Integer): Integer; STDCALL; EXTERNAL DelZipDll_Name;
 *)

implementation

end.

