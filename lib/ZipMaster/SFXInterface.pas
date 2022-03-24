(******************************************************************)
(* SFX for DelZip v1.7                                            *)
(* Copyright 2002-2005                                            *)
(*                                                                *)
(* written by Markus Stephany                                     *)
(* mailto:delphizip@mirkes.de                                     *)
(* http://delphizip.mirkes.de                                     *)
(*                                                                *)
(* last changed: 09/19/2005                                       *)
(*                                                                *)
(******************************************************************)
unit SFXInterface;

{
this unit contains those definitions used by delzipsfx which
may be used by 3rd party units (like TZipMaster) too.

}

interface

uses
  Windows;

const
  // 'DZ'#0#1;  // header signature
  SFX_HEADER_SIG = $01005A44;
  // 'DZ'#10#1; // end of header signature
  SFX_HEADER_END_SIG = $010A5A44;

  // 'DZ'#20#1; // detached header signature
  SFX_DETACHED_HEADER_SIG = $01145A44;
  // 'DZ'#20#2; // end of detached header signature
  SFX_DETACHED_HEADER_END_SIG = $02145A44;

type
  { file overwrite modes }
  TSFXOverwriteMode = (somOverwrite, somSkip, somAsk);

  { options }
  TSFXOption = (
    soAskCmdLine, // allow user to prevent execution of the command line
    soAskFiles, // allow user to prevent certain files from extraction
    soHideOverWriteBox, // do not allow user to choose the overwrite mode
    soAutoRun, // start extraction + evtl. command line automatically
                // only if sfx filename starts with "!" or is "setup.exe"
    soNoSuccessMsg, // don't show success message after extraction
    soExpandVariables, // expand environment variables in path/cmd line...
    soInitiallyHideFiles, // dont show file listview on startup
    soForceHideFiles, // do not allow user to show files list
                      // (no effect if shfInitiallyShowFiles is set)
    soCheckAutoRunFileName, // can only autorun if !... or setup.exe
    soCanBeCancelled, // extraction can be cancelled
    soDetached, // tells the stub that it has been created separate from the archive
    soCreateEmptyDirs // recreate empty directories
    );

  // set of TSFXOption
  TSFXOptions = set of TSFXOption;

  { sfx file header }
  PSFXFileHeader = ^TSFXFileHeader;
  TSFXFileHeader = packed record
    // signature: DZ#0#1 = version 01
    Signature: Cardinal;
    // overall header size (must be DWORD-Aligned!)
    Size: word;
    // flags
    Options: TSFXOptions;
    // default overwrite mode
    DefOVW: TSFXOverwriteMode;
    // length of the sfx dialog caption (0=default caption)
    CaptionSize,
    // length of the sfx default extraction path (0=current dir)
    PathSize,
    // length of the command line (0=no command line)
    CmdLineSize,
    // length of the extract path to be used if HK... failed (0=%temp%)
    RegFailPathSize,
    // length of the startup message (0=no message)
    StartMsgSize: byte;
    // MB_... (only used if StartMsgSize > 0)
    StartMsgType: Cardinal;
    {
    Caption: string;    if CaptionSize > 0, contains the caption of the sfx dialog (not #0-terminated)

                        + will be expanded if it contains % signs and soExpandEnvStrings is set

    Path: string;       if PathSize > 0, contains the default extraction path (not #0-terminated)

                        + will be expanded if it contains % signs and soExpandEnvStrings is set

                        + if set to "><", then use  temp-dir

                        + If the first two characters are "HK" the extraction-path //##FR
                          will be read from the registry. If the registry-key doesn't exist, the
                          default path will be set to the temp path. Either full names
                          (HKEY_CURRENT_USER\...) or abbreviations (as known from INF-files)
                          for the root keys HKCU, HKLM and HKU are supported.
                          examples:
                            "HKEY_CURRENT_USER\Software\Borland\Delphi\2.0\Library\SearchPath"
                            "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\ProgramFilesDir"
                            "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders\Personal"
                            "HKCU\Software\Microsoft\Office\8.0\Excel\Microsoft Excel\AddIn Path"
                          For subdirectories to be created use the pipe symbol "|", e.g.
                            "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\SystemRoot|NewDir"
                          will parse to : "C:\Windows\NewDir" (or whereever your system root is).

    CmdLine: string;    if CmdLineSize > 0, contains a command to execute after extraction completed
                        (not #0-terminated)

                        + will be expanded if it contains % signs and soExpandEnvStrings is set

                        + CmdLine has a special format:
                          all occurrences of  "><" (greather than+less than) in this string will be replaced by
                          the actual extraction path, e.g. :
                          if the archive has been extracted to "c:\Program Files\foo", a CmdLine
                          of "><bar\some.txt" will parse to "c:\Progra~1\foo\bar\some.txt"
                          (because of limitations of the ShellExecute API on some platforms when using long
                          filenames the short filename is generated by delzipsfx)

                          if the pipe char "|" is found in the CmdLine, the part to the left of it is used as
                          the application to run and the part to the right as its command line, e.g.:

                          extraction path = "d:\unpack", CmdLine = "><setup.exe|><install.inf"
                          -> exec "d:\unpack\setup.exe" with args "d:\unpack\install.inf"

                          extraction path = "d:\unpack", CmdLine = "><readme.txt":
                          -> open "d:\unpack\readme.txt" with its associated program, if there is any.

                          extraction path = "d:\unpack", CmdLine = "><setup.exe":
                          -> exec "d:\unpack\setup.exe" without special parameters.

                          additionally, if soExpandEnvStrings is set in the Options field:
                          extraction path = "d:\unpack", CmdLine = "%windir%notepad.exe|><readme.txt",
                          Windows Dir="c:\Windows"
                          -> exec "c:\windows\notepad.exe" with args "d:\unpack\readme.txt"

                        + INF-scripts are accepted as well //##FR
                          "><setup.inf" will run the [DefaultInstall] section of "d:\unpack\setup.inf".
                          "><setup.inf|.ntx86" will run the [DefaultInstall] section if Win95 (98?),
                          but [DefaultInstall.ntx86] section if WinNT.

    RegFailPath:        string if RegFailPathSize > 0, contains the default extraction path,
                        if reading path from registry failed (not #0-terminated)

                        + will be expanded if it contains % signs and soExpandEnvStrings is set

                        + if set to "><", then use  temp-dir

    StartMsg: string;   if StartMsgSize > 0, contains a message to display before showing the main dialog.
                        (not #0-terminated)

                        + will be expanded if it contains % signs and soExpandEnvStrings is set

                        if this messagebox is closed by pressing either IDCANCEL, IDABORT, IDNO or IDCLOSE button,
                        sfx terminates.

    }
  end;

  // the following record is only used by TZipSFX and TZipMasterSFX to quickly find the
  // TSFXFileHeader in the file, it's not used by the sfx itself.
  // it's immediately stored after the TSFXFileHeader record
  PSFXFileEndOfHeader= ^TSFXFileEndOfHeader;
  TSFXFileEndOfHeader= packed record
    Signature: DWORD;    //must be SFX_HEADER_END_SIG
    HeaderSize: DWORD;   //must be equal to TSFXFileHeader.Size (dword for alignment issuses)
  end;

  // in detached sfx archives, the sfx contains an additional record following the header
  PSFXDetachedHeader= ^TSFXDetachedHeader;
  TSFXDetachedHeader= packed record
    Signature: DWORD; // must be SFX_DETACHED_HEADER_SIG or SFX_DETACHED_HEADER_END_SIG
    NameLen,
    ExtLen: Cardinal; // contains the length of the filename/fileext of the archive (without path)
    {
    Name: string      if NameLen > 0, Name contains the file name (without extension) of
                          the detached archive
    Ext: string      if ExtLen > 0, Ext contains the file Ext (without leading .) of
                          the detached archive
    }
  end;

implementation

  (* the structure of a zipsfx-file :

  - zipsfx-executable code (0-xxxxx)
  - TSFXFileHeader record (see above)
  - possibly one or more strings (depending on the headers' properties) (not #0 terminated)
  Caption                             sfx dialog caption
  Path                                sfx default extraction path
  CmdLine                             command line to execute after extraction
  RegFailPath                         default extract path if Path could not be read from registry
  StartMsg                            startup message

  NOTE: the complete header (including the strings) must be DWORD-aligned!

  if not detached from the archive:
  - the zip archive

  if detached from the archive:
  - TSFXDetachedHeader + filename + TSFXDetachedHeader
  - centraldirectories[] + endofcentraldir of the zip archive


  *)

end.
