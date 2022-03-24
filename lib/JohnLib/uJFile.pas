unit uJFile;

interface

uses Windows, Classes, SysUtils, Graphics;

  Function DirCheck(Dir : String; DirType : String) : Boolean;
  procedure DirCopy(FromDir, ToDir : string; OverWriteExisting : boolean);
  function ExeTypeToString(const fName: string): String;
  Function FileCopy(Source, Destination : String; DelSource : Boolean = false) : Boolean;
  function GetEXEIcon(var myIcon : TIcon; filename : String) : Boolean;
  function GetEXEIconAsBmp(var myBmp : TBitmap; filename : String) : Boolean;
  Function GetFileVersion(forFile : String) : String;
  function GetVirtualFileExtension(FileName : TFileName) : String;
  function GetVirtualFileName(FileName : TFileName) : String;
  function GetVirtualShortName(FileName : TFileName) : String;
  function HasSubDirs(const Folder: string): Boolean;
  function IsDriveReadOnly(Path : String) : Boolean;
  Function FilesSameVersion(File1 : String; File2 : String) : Boolean;

implementation

{$I Compilers.inc}

uses jvSHFileOperation, JCLShell, ShellAPI, JCLStrings, uJUtilities, Dialogs,
     ujMiscResourceStrs;

{-----------------------------------------------------------------------------}

Function DirCheck(Dir : String; DirType : String) : Boolean;
begin

  Result := true;
  If Not DirectoryExists(Dir) then
  begin

    If DirType = J_INPUT then
    begin
      MessageDlg(J_DIRCHECK_1 + DirType + J_DIRECTORY_NOT_EXIST, mtError, [mbOK], 0);
      Result := False;
    end

    else

    if DirType = J_OUTPUT then

      If NOT (CreateDir(Dir)) Then
      begin
        MessageDlg(J_CREATE_DIR_FAILED + ' : ' + Dir, mtError, [mbOK], 0);
        Result := False;
      end;

  end;
end;

{-----------------------------------------------------------------------------}

// copy a directory tree
procedure DirCopy(FromDir, ToDir : string; OverWriteExisting : boolean);
var
  FOS : TJvSHFileOperation;
begin
  FromDir := Trim(FromDir);
  if FromDir[Length(FromDir)] <> '\' then FromDir := FromDir + '\';
    ToDir := Trim(ToDir);
  FOS := TjvSHFileOperation.Create(nil);
  try
    FOS.Operation := FOCOPY;
    FOS.SourceFiles.Add(FromDir+'*.*');
    FOS.DestFiles.Add(ToDir);
    FOS.Options := [FOFALLOWUNDO, FOFMULTIDESTFILES, FOFNOCONFIRMMKDIR];
    if OverWriteExisting then
      FOS.Options := FOS.Options + [fofNoConfirmation];
    FOS.Execute;
  Finally
    FreeAndNil(FOS);
  end;
end;

{-----------------------------------------------------------------------------}

//Function to get the type of EXE - WIN or DOS.  Wrapper for the JCL function
// GetFileExeType - and converts its result to a string.
function ExeTypeToString(const fName: string): String;
begin
  Result := '';
  Case GetFileExeType(fName) of
    etError : Result := J_ERROR;
    etMSDos : Result := J_EXE_DOS;
    etWin16 : Result := J_EXE_WIN16;
    etWin32Gui,
    etWin32Con : Result := J_EXE_WIN32;
  end;

end;

{-----------------------------------------------------------------------------}

Function FileCopy(Source, Destination : String; DelSource : Boolean = false) : Boolean;
begin
  Result := CopyFile(PChar(Source), PChar(Destination), False);

  if Delsource = true then
    SysUtils.DeleteFile(Source);
end;

{-----------------------------------------------------------------------------}

function GetEXEIcon(var myIcon : TIcon; filename : String) : Boolean;
var
  IconIndex: word;
  Buffer: array[0..2048] of char;
  IconHandle: HIcon;
begin

  Result := False;
  //if the file doesnt exist leave the iconindex at -1
  if not FileExists(filename) then
    exit;

  //get the associated icon for this file
  StrCopy(@Buffer, pchar(filename));
  IconIndex := 0;
  IconHandle := ExtractAssociatedIcon(HInstance, Buffer, IconIndex);

  if IconHandle = 0 then
    result := False
  else
  begin
    myIcon.Handle := IconHandle;
    Result := True;
  end;

end;

function GetEXEIconAsBmp(var myBmp : TBitmap; filename : String) : Boolean;
var
  TmpIcon : TIcon;
begin
  Result := False;
  TmpIcon := TIcon.Create;
  try
    if GetEXEIcon(TmpIcon, FileName) then
    begin
      MyBmp.Width := TmpIcon.Width;
      MyBmp.Height := TmpIcon.Height;
      MyBmp.Canvas.Draw(0,0, TmpIcon);
      Result := True;
    end;
  finally
    FreeAndNil(TmpIcon);
  end;
end;

{-----------------------------------------------------------------------------}

Function GetFileVersion(forFile : String) : String;
var
  dwInfoSize,           // Size of VERSIONINFO structure
  dwVerSize,            // Size of Version Info Data
  dwWnd: DWORD;         // Handle for the size call.
  FI: PVSFixedFileInfo; // Delphi structure; see WINDOWS.PAS
  ptrVerBuf: Pointer;   // pointer to a version buffer
  strFileName,          // Name of the file to check
  strVersion : string;  // Holds parsed version number
begin
  strFileName := forFile;
  dwInfoSize := getFileVersionInfoSize( pChar( strFileName ), dwWnd);
  strVersion := '';
  
  if ( dwInfoSize = 0 ) then
    result := ''
  else
  begin

    getMem( ptrVerBuf, dwInfoSize );
    try

      if getFileVersionInfo( pChar( strFileName ), dwWnd, dwInfoSize, ptrVerBuf ) then
        if verQueryValue( ptrVerBuf, '\', pointer(FI), dwVerSize ) then
          strVersion := format( '%d.%d.%d.%d',
                       [ hiWord( FI.dwFileVersionMS ),
                         loWord( FI.dwFileVersionMS ),
                         hiWord( FI.dwFileVersionLS ),
                         loWord( FI.dwFileVersionLS ) ] );
    finally
      freeMem( ptrVerBuf );
    end;
  end;
  Result := strVersion;
end;

{-----------------------------------------------------------------------------}

function GetShortForm(Part : String) : String;
begin

  //Helper function for  GetVirtualShortName.
  //basically this function turns the parts of a file path into short form.

  Result := StrRemoveChars(part, [' ']);

  {$IFDEF DEBUG}
  AddToLog('After Removing spaces - ' + Result);
  {$ENDIF}

  If Length(Result) > 8 then
  begin
    Result := Copy(Result, 1, 6) + '~1' + ExtractFileExt(Part);
  end;

  {$IFDEF DEBUG}
  AddToLog('Making 8 characters long - ' + Result);
  {$ENDIF}

end;

{-----------------------------------------------------------------------------}

function GetVirtualFileName(FileName : TFileName) : String;
var
  LastSep : String[1];
  PosBack, PosForward : Integer;
begin
  //look for both \ and / in the filename
  PosBack := JCLStrings.StrLastPos('\', FileName);
  PosForward := JCLStrings.StrLastPos('/', FileName);

  if (PosBack = 0) and (PosForward = 0) then
    //there are no path seperators found, return the string unchanged.
    result := Filename
  else
  begin
    if PosBack > PosForward then
      LastSep := '\'
    else
      LastSep := '/';
      
    Result := Copy(FileName, JCLStrings.StrLastPos(LastSep, FileName), Length(FileName)-1)
  end;
end;

function GetVirtualFileExtension(FileName : TFileName) : String;
begin
  Result := Copy(FileName, JCLStrings.StrLastPos('.', FileName), Length(FileName));  
end;

{-----------------------------------------------------------------------------}

function GetVirtualShortName(FileName : TFileName) : String;
var
  Split : TStringList;
  Seperator : char;
  I : Integer;
begin

  //function to get the short name of a VIRTUAL file - ie a file that doesnt exist.

  Result := '';

  Split := TStringList.Create;
  Try

    //try to work out what seperator is used in this string.
    If CharPos(FileName, '/') <> 0 then
      Seperator := '/'
    else
      Seperator := '\';

    StrTokenToStrings(FileName, Seperator, Split);

    For i := 0 to Split.Count-1 do
      Result := Result + '\' + GetShortForm(Split[i]);

    //need to get rid of the starting '\'
    Result := Copy(Result, 2, Length(Result));

  Finally
    FreeAndNil(Split);
  end;
end;

{-----------------------------------------------------------------------------}

function HasSubDirs(const Folder: string): Boolean;
// Determines whether folder contains other file objects.
var
  SR: TSearchRec;
begin

  Result := FindFirst(IncludeTrailingPathDelimiter(Folder)+'*.*', faDirectory, SR) = 0;
  if Result then
    FindClose(SR);

end;

{-----------------------------------------------------------------------------}

function IsDriveReadOnly(Path : String) : Boolean;
var
  OldDir : String;
begin
  OldDir := GetCurrentDir();
  Try
    SetCurrentDir(Path);
    Result := (DiskFree(0) = 0);
  Finally
    SetCurrentDir(OldDir);
  end;
end;

{-----------------------------------------------------------------------------}

Function FilesSameVersion(File1 : String; File2 : String) : Boolean;
var
  Ver1, Ver2 : String;
begin
  if FileExists(File1) then
    Ver1 := GetFileVersion(File1);

  if FileExists(File2) then
    Ver2 := GetFileVersion(File2);

  if JCLStrings.StrCompare(Ver1, Ver2) = 0 then
    Result := true
  else
    Result := False;
  
end;

end.
