{
7Zip support uses the 7-zip.dll found on http://akky.cjb.net/ (its in japanese!!)
to help me figure out how to use this file, I got some sample code from the author
of QuickZip (http://www.quickzip.org/).  This showed me sort of how to use the DLL,
although there were some long sessions of trying to figure out just what to do using only
a Japanese readme file.. and no I dont read japanese.. great... 
}

unit ujCompress7zip;

interface

uses SysUtils, Classes, ComCtrls, uJCompression;

Type
  TJSevenZip = class(TInterfacedObject, IJCompressible)
  private
    _CompressMode : TJCompressMode;
    _DllHandle : Integer;
    Function GetCurrentMode() : TJCompressMode;
    Function GetFullName() : String;
  public
    constructor Create();
    destructor Destroy(); override;

    //interface functions
    procedure CompressDirectory(Directory : String; FileName : TFileName; Filter : TStrings);
    procedure CompressSingleFile(input, Output : TFileName);
    Procedure ListContentsOfFile(var Contents : TStrings; FileName : TFileName);
    procedure RenameContentToFile(FileName : TFileName);
    procedure RenameFileToContent(FileName : TFileName);
    procedure SupportedFileExts(var Exts : TStringList);
    Function  SupportsFileName(Input : TFileName; Operation : TJCompressMode) : Boolean; //based on full filename
    Procedure UnCompressFile(input : TFileName; OutputDir : String; Opt_Diff, Opt_Path, Opt_OW : boolean;
      var FilesUncompressed : TStringList; ExtractFilter : String = '*.*');
    Procedure UnCompressFileToStream(inZipFile : TFileName; FileInZip : String; 
        var TheStream : TMemoryStream);
    Function  VerifyFile(input : TFileName) : Boolean;

    Property FullName : String read GetFullName;
  end;

implementation

uses Windows, Forms,
     JCLStrings, JCLFileUtils, JCLSysInfo,
     uJFile, ujCompressResourceStrs;

{------------------------------------------------------------------------------}
{  7-zip Constants and Types.                                                  }
{------------------------------------------------------------------------------}

const
  SEVENZIPLB = #13#10;
  FNAME_MAX32 = 512;
  M_INIT_FILE_USE          = $00000001;
  M_REGARDLESS_INIT_FILE   = $00000002;
  M_CHECK_ALL_PATH         = $00000100;
  M_CHECK_FILENAME_ONLY    = $00000200;
  M_USE_DRIVE_LETTER       = $00001000;
  M_NOT_USE_DRIVE_LETTER   = $00002000;
  M_ERROR_MESSAGE_ON       = $00400000;
  M_ERROR_MESSAGE_OFF      = $00800000;
  M_RECOVERY_ON            = $08000000;
  EXTRACT_FOUND_FILE       = $40000000;
  EXTRACT_NAMED_FILE       = $80000000;
  CHECKARCHIVE_RAPID       = $0000;
  CHECKARCHIVE_BASIC       = $0001;
  CHECKARCHIVE_FULLCRC     = $0002;
  CHECKARCHIVE_RECOVERY    = $0004;
  CHECKARCHIVE_SFX         = $0008;
  CHECKARCHIVE_ALL         = $0002;

  AoiUnAssigned            = -1;
  AosUnAssigned            = #0;
  ARCEXTRACT_BEGIN         = 0;
  ARCEXTRACT_INPROCESS     = 1;
  ARCEXTRACT_END           = 2;
  ARCEXTRACT_OPEN          = 3;
  ARCEXTRACT_COPY          = 4;


  // Errors
  ERROR_START = $8000;

  // (* WARNING *)
  ERROR_DISK_SPACE = $8005;
  ERROR_READ_ONLY = $8006;
  ERROR_USER_SKIP = $8007;
  ERROR_UNKNOWN_TYPE = $8008;
  ERROR_METHOD = $8009;
  ERROR_PASSWORD_FILE = $800A;
  ERROR_VERSION = $800B;
  ERROR_FILE_CRC = $800C;
  ERROR_FILE_OPEN = $800D;
  ERROR_MORE_FRESH = $800E;
  ERROR_NOT_EXIST = $800F;
  ERROR_ALREADY_EXIST = $8010;

  ERROR_TOO_MANY_FILES = $8011;

  // (* ERROR *)
  ERROR_MAKEDIRECTORY = $8012;
  ERROR_CANNOT_WRITE = $8013;
  ERROR_HUFFMAN_CODE = $8014;
  ERROR_COMMENT_HEADER = $8015;
  ERROR_HEADER_CRC = $8016;
  ERROR_HEADER_BROKEN = $8017;
  ERROR_ARC_FILE_OPEN = $8018;
  ERROR_NOT_ARC_FILE = $8019;
  ERROR_CANNOT_READ = $801A;
  ERROR_FILE_STYLE = $801B;
  ERROR_COMMAND_NAME = $801C;
  ERROR_MORE_HEAP_MEMORY = $801D;
  ERROR_ENOUGH_MEMORY = $801E;
  ERROR_ALREADY_RUNNING = $801F;
  ERROR_USER_CANCEL = $8020;
  ERROR_HARC_ISNOT_OPENED = $8021;
  ERROR_NOT_SEARCH_MODE = $8022;
  ERROR_NOT_SUPPORT = $8023;
  ERROR_TIME_STAMP = $8024;
  ERROR_TMP_OPEN = $8025;
  ERROR_LONG_FILE_NAME = $8026;
  ERROR_ARC_READ_ONLY = $8027;
  ERROR_SAME_NAME_FILE = $8028;
  ERROR_NOT_FIND_ARC_FILE = $8029;
  ERROR_RESPONSE_READ = $802A;
  ERROR_NOT_FILENAME = $802B;
  ERROR_TMP_COPY = $802C;
  ERROR_EOF = $802D;
  ERROR_ADD_TO_LARC = $802E;
  ERROR_TMP_BACK_SPACE = $802F;
  ERROR_SHARING = $8030;
  ERROR_NOT_FIND_FILE = $8031;
  ERROR_LOG_FILE = $8032;
  ERROR_NO_DEVICE = $8033;
  ERROR_GET_ATTRIBUTES = $8034;
  ERROR_SET_ATTRIBUTES = $8035;
  ERROR_GET_INFORMATION = $8036;
  ERROR_GET_POINT = $8037;
  ERROR_SET_POINT = $8038;
  ERROR_CONVERT_TIME = $8039;
  ERROR_GET_TIME = $803a;
  ERROR_SET_TIME = $803b;
  ERROR_CLOSE_FILE = $803c;
  ERROR_HEAP_MEMORY = $803d;
  ERROR_HANDLE = $803e;
  ERROR_TIME_STAMP_RANGE = $803f;
  ERROR_MAKE_ARCHIVE = $8040;
  ERROR_NOT_CONFIRM_NAME = $8041;
  ERROR_UNEXPECTED_EOF = $8042;
  ERROR_INVALID_END_MARK = $8043;
  ERROR_INVOLVED_LZH = $8044;
  ERROR_NO_END_MARK = $8045;
  ERROR_HDR_INVALID_SIZE = $8046;
  ERROR_UNKNOWN_LEVEL = $8047;
  ERROR_BROKEN_DATA = $8048;

  ERROR_7ZIP_START = $8100;

  ERROR_WARNING = $8101;
  ERROR_FATAL = $8102;
  ERROR_DURING_DECOMPRESSION = $8103;
  ERROR_DIR_FILE_WITH_64BIT_SIZE = $8104;
  ERROR_FILE_CHANGED_DURING_OPERATION = $8105;

type

  HARC = integer;

  TSevenZipEXTRACTINGINFO = record
    dwFileSize : DWORD;
    dwWriteSize : DWORD;
    szSourceFileName : array[ 0..FNAME_MAX32 ] of char;
    dummy1 : array[ 0..2 ] of char;
    szDestFileName : array[ 0..FNAME_MAX32 ] of char;
    dummy : array[ 0..2 ] of char;
  end;

  TSevenZipEXTRACTINGINFOEX = record
    exinfo : TSevenZipEXTRACTINGINFO;
    dwCompressedSize : DWORD;
    dwCRC : DWORD;
    uOSType : UINT;
    wRatio : WORD;
    wDate : WORD;
    wTime : WORD;
    szAttribute : array[ 0..7 ] of char;
    szMode : array[ 0..7 ] of char;
  end;

  TSevenZipINDIVIDUALINFO = record
    wOriginalSize : DWORD;
    dwCompressedSize : DWORD;
    dwCRC : DWORD;
    uFlag : UINT;
    uOSType : UINT;
    wRatio : WORD;
    wDate : WORD;
    wTime : WORD;
    szFilename : array[ 0..FNAME_MAX32 ] of char;
    dummy1 : array[ 0..2 ] of char;
    szAttribute : array[ 0..7 ] of char;
    szMode : array[ 0..7 ] of char;
  end;

  TSevenZipCommand = function (const hWnd: HWND; szCmdLine: PChar; szOutput: PChar; dwSize: DWORD): Integer; stdcall;
  TSevenZipGetVersion = function : WORD; stdcall;
  TSevenZipGetCursorMode = function : BOOL; stdcall;
  TSevenZipSetCursorMode = function( CursorMode : BOOL ) : BOOL; stdcall;
  TSevenZipGetCursorInterval = function : WORD; stdcall;
  TSevenZipSetCursorInterval = function( CursorInterval : WORD ) : WORD; stdcall; // millisecs
  TSevenZipGetBackgroundMode = function : BOOL; stdcall;
  TSevenZipSetBackgroundMode = function( BackgroundMode : BOOL ) : BOOL; stdcall;
  TSevenZipGetRunning = function : BOOL; stdcall;

  TSevenZipConfigDialog = function( hwnd : HWND; szOptionBuffer : PChar; iMode : integer ) : BOOL; stdcall;
  TSevenZipCheckArchive = function( szFilename : PChar; iMode : integer ) : BOOL; stdcall;
  TSevenZipGetFileCount = function( szArcFile : PChar ) : integer; stdcall;
  TSevenZipQueryFunctionList = function( iFunction : integer ) : BOOL; stdcall;

  TSevenZipOpenArchive = function( hwnd : HWND; szFileName : PChar; dwMode : DWORD ) : HARC; stdcall;
  TSevenZipCloseArchive = function( harc : HARC ) : integer; stdcall;
  TSevenZipFindFirst = function( harc : HARC; szFilename : PChar; var lpSubInfo : TSevenZipINDIVIDUALINFO ) : integer; stdcall;
  TSevenZipFindNext = function( harc : HARC; var lpSubInfo : TSevenZipINDIVIDUALINFO ) : integer; stdcall;
  TSevenZipGetArcFileName = function( harc : HARC; lpBuffer : pchar; nSize : integer ) : integer; stdcall;
  TSevenZipGetArcFileSize = function( harc : HARC ) : DWORD; stdcall;
  TSevenZipGetArcOriginalSize = function( harc : HARC ) : DWORD; stdcall;
  TSevenZipGetArcCompressedSize = function( harc : HARC ) : DWORD; stdcall;
  TSevenZipGetArcRatio = function( harc : HARC ) : WORD; stdcall;
  TSevenZipGetArcDate = function( harc : HARC ) : WORD; stdcall;
  TSevenZipGetArcTime = function( harc : HARC ) : WORD; stdcall;
  TSevenZipGetArcOSType = function( harc : HARC ) : UINT; stdcall;
  TSevenZipIsSFXFile = function( harc : HARC ) : integer; stdcall;
  TSevenZipGetFileName = function( harc : HARC ; lpBuffer : PChar; nsize : integer) : integer; stdcall;
  TSevenZipGetOriginalSize = function( harc : HARC ) : DWORD; stdcall;
  TSevenZipGetCompressedSize = function( harc : HARC ) : DWORD; stdcall;
  TSevenZipGetRatio = function( harc : HARC ) : WORD; stdcall;
  TSevenZipGetDate = function( harc : HARC ) : WORD; stdcall;
  TSevenZipGetTime = function( harc : HARC ) : WORD; stdcall;
  TSevenZipGetCRC = function( harc : HARC ) : DWORD; stdcall;
  TSevenZipGetAttribute = function( harc : HARC ) : integer; stdcall;
  TSevenZipGetOSType = function( harc : HARC ) : UINT; stdcall;
  TSevenZipGetMethod = function( harc : HARC ; lpBuffer : PChar; nsize : integer) : integer; stdcall;
  TSevenZipGetWriteTime = function( harc : HARC ) : DWORD; stdcall;
  TSevenZipGetWriteTimeEx = function( harc : HARC; var lpftLastWriteTime : FILETIME ) : BOOL; stdcall;
  TSevenZipGetArcCreateTimeEx = function( harc : HARC; var lpftCreationTime : FILETIME ) : BOOL; stdcall;
  TSevenZipGetArcAccessTimeEx = function( harc : HARC; var lpftLastAccessTime : FILETIME ) : BOOL; stdcall;
  TSevenZipGetArcWriteTimeEx = function( harc : HARC; var lpftLastWriteTime : FILETIME ) : BOOL; stdcall;
  TSevenZipGetArcFileSizeEx = function( harc : HARC; var lpllSize : TLargeInteger ) : BOOL; stdcall;
  TSevenZipGetArcOriginalSizeEx = function( harc : HARC; var lpllSize : TLargeInteger ) : BOOL; stdcall;
  TSevenZipGetArcCompressedSizeEx = function( harc : HARC; var lpllSize : TLargeInteger ) : BOOL; stdcall;
  TSevenZipGetOriginalSizeEx = function( harc : HARC; var lpllSize : TLargeInteger ) : BOOL; stdcall;
  TSevenZipGetCompressedSizeEx = function( harc : HARC; var lpllSize : TLargeInteger ) : BOOL; stdcall;

  // Callback func should return FALSE to cancel the archiving process, else TRUE
  TSevenZipCallbackProc = function( hWnd : HWND; uMsg, nState : UINT; var ExInfo : TSevenZipEXTRACTINGINFOEX ) : BOOL; stdcall;

  TSevenZipSetOwnerWindow = function( hwnd : HWND ) : BOOL; stdcall;
  TSevenZipClearOwnerWindow = function : BOOL; stdcall;
  TSevenZipSetOwnerWindowEx = function( hwnd : HWND; CallbackProc : TSevenZipCallbackProc ) : BOOL; stdcall;
  TSevenZipKillOwnerWindowEx = function( hwnd : HWND ) : BOOL; stdcall;

  TSevenZipGetSubVersion = function : WORD; stdcall;
  TSevenZipGetArchiveType = function( szFileName : pchar ) : integer; stdcall;
  TSevenZipSetUnicodeMode = function( bUnicode : BOOL ) : BOOL; stdcall;

{------------------------------------------------------------------------------}
{   End of 7zip constants/types                                                }
{------------------------------------------------------------------------------}

var
  OutStrings : TStringList;
  FSevenZip                 : TSevenZipCommand;
  FSevenZipOpenArchive      : TSevenZipOpenArchive;
  FSevenZipCloseArchive     : TSevenZipCloseArchive;
  FSevenZipFindFirst        : TSevenZipFindFirst;
  FSevenZipFindNext         : TSevenZipFindNext;
  FSevenZipCheckArchive     : TSevenZipCheckArchive;
  FSevenZipSetOwnerWindow   : TSevenZipSetOwnerWindow;
  FSevenZipSetOwnerWindowEx : TSevenZipSetOwnerWindowEx;
  FSevenZipKillOwnerWindowEx: TSevenZipKillOwnerWindowEx;

{------------------------------------------------------------------------------}
{   Extraction Callback                                                        }
{------------------------------------------------------------------------------}

function ExtrCallBack(hWnd : HWND; uMsg, nState : UINT; var ExInfo : TSevenZipEXTRACTINGINFOEX): BOOL; Stdcall;
begin
  Result := True;
  if (NState = 0) then
    OutStrings.Add(ExInfo.exinfo.szDestFileName);
end;

{------------------------------------------------------------------------------}
{   TJ7zip code                                                                }
{------------------------------------------------------------------------------}

Function TJSevenZip.GetCurrentMode() : TJCompressMode;
begin
  Result := Self._CompressMode;
end;

{------------------------------------------------------------------------------}

Function TJSevenZip.GetFullName() : String;
begin
  Result := '7z Files';
end;

{------------------------------------------------------------------------------}

constructor TJSevenZip.Create();
begin
  inherited;
  OutStrings := TStringList.Create;
  _DllHandle := LoadLibrary('7-zip32.dll');
  if _DllHandle = 0 then
    _CompressMode := cmNone
  else
  begin
    _CompressMode := cmFull;
    @FSevenZip := GetProcAddress(_DLLHandle, 'SevenZip');
    @FSevenZipOpenArchive := GetProcAddress(_DLLHandle, 'SevenZipOpenArchive');
    @FSevenZipCloseArchive := GetProcAddress(_DLLHandle, 'SevenZipCloseArchive');
    @FSevenZipCheckArchive := GetProcAddress(_DLLHandle, 'SevenZipCheckArchive');
    @FSevenZipFindFirst := GetProcAddress(_DLLHandle, 'SevenZipFindFirst');
    @FSevenZipFindNext := GetProcAddress(_DLLHandle, 'SevenZipFindNext');
    @FSevenZipSetOwnerWindow := GetProcAddress(_DLLHandle, 'SevenZipSetOwnerWindow');
    @FSevenZipSetOwnerWindowEx := GetProcAddress(_DLLHandle, 'SevenZipSetOwnerWindowEx');
    @FSevenZipKillOwnerWindowEx := GetProcAddress(_DLLHandle, 'SevenZipKillOwnerWindowEx');

    //check that all functions were found ok
    if (@FSevenZip = nil) or (@FSevenZipOpenArchive = nil) or (@FSevenZipCloseArchive = nil) or
       (@FSevenZipCheckArchive = nil) or (@FSevenZipFindFirst = nil) or (@FSevenZipFindNext = nil) or
       (@FSevenZipSetOwnerWindowEx = nil) or (@FSevenZipKillOwnerWindowEx = nil) then
    begin
      FreeLibrary(_DllHandle);
      _CompressMode := cmNone;
    end;
  end;
end;

{------------------------------------------------------------------------------}

destructor TJSevenZip.destroy();
begin
  FreeAndNil(OutStrings);
  FreeLibrary(_DllHandle);
  inherited;
end;

{------------------------------------------------------------------------------}

procedure TJSevenZip.CompressDirectory(Directory : String; FileName : TFileName; Filter : TStrings);
var
  S7ResultOutput : string;
  s7cmd : string;
  S7Result : Integer;
  cwd : string;
  WindowResult : boolean;
  s7Filter : TStringList;
  i : Integer;
begin

  cwd := GetCurrentDir;

  // change to base dir so relative paths work correctly
  if not SetCurrentDir( ExtractFilePath(Directory) ) then
  begin
    raise EJCompressException.Create(COMP_INVALID_DIR);
  end;

  try

    s7Filter := TStringList.Create;
    try
      s7Filter.AddStrings(Filter);

      s7Cmd := Format('a "%s" "%s"', [FileName, s7Filter[0]]);

      for i := 1 to s7Filter.Count - 1 do
      begin
        s7Cmd := s7Cmd + ' -ir!"' + s7Filter[i] + '"';
      end;

      s7Cmd := s7Cmd + ' -mx5 -ms=on -hide';
      
    finally
      FreeAndNil(s7Filter);
    end;

    WindowResult := FSevenZipSetOwnerWindow(Application.Handle);
    if WindowResult <> True then
      raise EJCompressException.Create(ACE_UNKNOWN_ERROR);
    try
    
      Try
      S7Result := FSevenZip( Application.Handle, PChar(s7cmd), PChar(s7ResultOutput), Length(s7ResultOutput));
      if s7Result <> 0 then
        raise EJCompressException.Create(COMP_WRITE_ERROR + ' - ' + IntToStr(S7Result));
      Except

      end;

    finally
      FSevenZipKillOwnerWindowEx(Application.Handle);
    end;

  finally
    SetCurrentDir( cwd ); // back to where we were
  end;
end;

{------------------------------------------------------------------------------}

procedure TJSevenZip.CompressSingleFile(input, Output : TFileName);
var
  S7ResultOutput : string;
  s7cmd : string;
  S7Result : Integer;
  cwd : string;
  WindowResult : boolean;
begin

  cwd := GetCurrentDir;

  // change to base dir so relative paths work correctly
  if not SetCurrentDir( ExtractFilePath(Input) ) then
  begin
    raise EJCompressException.Create(COMP_INVALID_DIR);
  end;

  try                       //
    s7Cmd := Format('a "%s" "%s" -mx5 -ms=on -hide', [Output, ExtractFileName(Input)]);
    WindowResult := FSevenZipSetOwnerWindow(Application.Handle);
    if WindowResult <> True then
      raise EJCompressException.Create(ACE_UNKNOWN_ERROR);
    try
    
      Try
      S7Result := FSevenZip( Application.Handle, PChar(s7cmd), PChar(s7ResultOutput), Length(s7ResultOutput));
      if s7Result <> 0 then
        raise EJCompressException.Create(COMP_WRITE_ERROR + ' - ' + IntToStr(S7Result));
      Except

      end;

    finally
      FSevenZipKillOwnerWindowEx(Application.Handle);
    end;

  //  S7ResultOutput := string(PChar(S7ResultOutput));

  finally
    SetCurrentDir( cwd ); // back to where we were
  end;
end;

{------------------------------------------------------------------------------}

Procedure TJSevenZip.ListContentsOfFile(var Contents : TStrings; FileName : TFileName);
var
  DWMode : DWord;
  Arc : HARC;
  Rec : TSevenZipINDIVIDUALINFO;
begin
  //try to open the archive.
  DWMode := M_REGARDLESS_INIT_FILE + M_ERROR_MESSAGE_OFF;
  Arc := FSevenZipOpenArchive(0, PAnsiChar(FileName), DwMode);
  try
    //begin collecting file listing.
    if FSevenZipFindFirst(Arc, PChar('*.*'), Rec) = 0 then
    begin
      Repeat
        Contents.Add(Rec.SzFileName);
      until FSevenZipFindNext(Arc, Rec) <> 0;
    end;
  finally
    FSevenZipCloseArchive(Arc);
  end;
end;

{------------------------------------------------------------------------------}

procedure TJSevenZip.RenameContentToFile(FileName : TFileName);
var
  inFiles : TStrings;
  ArcName : String;
  InName : String;
  NewName : String;
  ExtrStrs : TStringList;
  Ext : String;
begin
  //since the DLL provides no way to rename files, we have to extract then
  //re7zip up again.. sucks...
  inFiles := TStringList.Create;
  try
    Self.ListContentsOfFile(inFiles, FileName);
    if inFiles.Count = 1 then
    begin
      //extract the file and do some renaming and re-zipping...

      ArcName := ChangeFileExt(ExtractFileName(FileName), '');
      InName := inFiles[0];
      Ext := ExtractFileExt(InFiles[0]);

      if JCLStrings.StrCompare(ArcName, ChangeFileExt(InName, '')) <> 0 then
      begin
        //file names are different do some changing....

        //first of all extract the archive.
        ExtrStrs := TStringList.Create;
        try
          Self.UnCompressFile(FileName, JCLSysInfo.GetWindowsTempFolder(), False, False, False, ExtrStrs, InName);
          if ExtrStrs.Count = 1 then
          begin
            NewName := ExtractFilePath(ExtrStrs[0]) + ArcName + Ext;
            SysUtils.RenameFile(ExtrStrs[0], NewName);

            SysUtils.DeleteFile(FileName);
            Self.CompressSingleFile(NewName, FileName);
            SysUtils.DeleteFile(NewName);

          end
          else
            Raise EJCompressException.Create(ACE_UNKNOWN_ERROR);

        finally
          FreeAndNil(ExtrStrs);
        end;
      end;
      
    end
    else
      raise EJCompressException.Create(COMP_MORE_THAN_ONE_FILE);
      
  finally
    FreeAndNil(inFiles);
  end;

end;

{------------------------------------------------------------------------------}

procedure TJSevenZip.RenameFileToContent(FileName : TFileName);
var
  Contents : TStringList;
  name : String;
begin
  Contents := TStringList.Create;
  try
    Self.ListContentsOfFile(TStrings(Contents), FileName);

    if Contents.Count = 1 then
    begin
      name := ujFile.GetVirtualFileName(Contents[0]);
      name := ChangeFileExt(name, '.7z');
      if not renameFile(FileName, name) then
        raise EJCompressException.Create(COMP_RENAME_ERROR + Name);
    end
    else
      raise EJCompressException.Create(COMP_MORE_THAN_ONE_FILE);

  finally
    FreeAndNil(Contents);
  end;
end;

{------------------------------------------------------------------------------}

procedure TJSevenZip.SupportedFileExts(var Exts : TStringList);
begin
  Exts.Add('*.7z');
end;

{------------------------------------------------------------------------------}

Function  TJSevenZip.SupportsFileName(Input : TFileName; Operation : TJCompressMode) : Boolean; //based on full filename
begin
  try
    //we need to use the custom file extension function because the VCL one cant cope if the file does not exist.
    if (JCLStrings.StrCompare(ujFile.GetVirtualFileExtension(input), '.7z')=0) and
       (_CompressMode in [Operation, cmFull]) then
      Result := True
    else
      Result := False;
  except
    //if something goes wrong, return false - better safe than sorry
    Result := False;
  end;
end;

{------------------------------------------------------------------------------}

Procedure TJSevenZip.UnCompressFile(input : TFileName; OutputDir : String; Opt_Diff, Opt_Path, Opt_OW : boolean;
      var FilesUncompressed : TStringList; ExtractFilter : String = '*.*');
var
  Cmd, tempStr, NewExtrDir, MyOutput : String;
  WindowResult : boolean;
  SevenZipResult, i : Integer;
begin

  { Extracting uses the 7z CMD function.  This was pants as all the documentation I could find was in japanese..
    anyway heres the most important switches I have found (through trial and error!)
    Extract with path - 'x FILE -oDEST'
    Extract no path   - 'e FILE -oDEST'
    Always overwrite  - -aoa
    always skip       - -aos
    And heres what i *think* are all possible switches, but I have no idea what most of them do.. great..
      -ao , -hide, -i, -o, -p, -r, -x, -y, -p
  }

  FilesUncompressed.Clear;

  //for some reason the dll adds an extra \ in front of filenames, if we are looking to extract one file, and the
  //filter doesnt include the preceding \ then add it in.
  if Pos(' ', ExtractFilter) <> 0 then
    ExtractFilter := '"' + ExtractFilter + '"';

  //check if the user wants separate directories..
  if Opt_Diff then
  begin
    tempStr := ExtractFileName(input);
    tempStr := ChangeFileExt(tempStr, '');
    tempStr := IncludeTrailingPathDelimiter(OutputDir) + tempStr;
    JCLFileUtils.ForceDirectories(TempStr);
    NewExtrDir := IncludeTrailingPathDelimiter(tempStr);
  end
  else
    NewExtrDir := IncludeTrailingPathDelimiter(OutputDir);

  //Build the command based on users choices.
  if Opt_Path then
    Cmd := '-SCCDOS x '
  else
    Cmd := '-sccDOS e ';

  //now add the filename of the compressed file.
  Cmd := Format('%s "%s"', [Cmd, input]);

  //select overwrite mode, based on users choice.  both get the -hide parameter to turn off progress screen.
  if Opt_OW then
    Cmd := Cmd + ' -aoa '
  else
    Cmd := Cmd + ' -aos ';

  //now add the output path.  Its in shortname with the last \ missing, i dont know if this is required, but it works..
  //Also add the users filter.

  Cmd := Format('%s -o"%s" %s -hide', [Cmd, ExcludeTrailingPathDelimiter(NewExtrDir), ExtractFilter]);

  //now the command is built, set the callback method.
  WindowResult := FSevenZipSetOwnerWindowEx(Application.Handle, ExtrCallBack);
  if not WindowResult then
    raise EJCompressException.Create(ACE_UNKNOWN_ERROR);
  try

    //reset the OutStrings.
    OutStrings.Clear;
    //If i dont put something in this string, it all goes pear-shaped.. its all very weird..
    MyOutput := Copy(NewExtrDir, 0, Length(NewExtrDir));

    //call the extract command!
    SevenZipResult := FSevenZip(Application.Handle, PChar(Cmd), PChar(MyOutput), Length(MyOutput));
    if SevenZipResult <> 0 then
      raise EJCompressException.Create(Format('%s - The command sent to the DLL was:%s%s%s%s Press CTRL+C to copy this error to clipboard.', [ACE_UNKNOWN_ERROR, SEVENZIPLB, Cmd, SEVENZIPLB, SEVENZIPLB]));

    //now build the uncompressed filelist.  the dll returns only the NAMES of files, not the full path. so add the extrpath!
    for i := 0 to OutStrings.Count-1 do
      if (FileExists(OutStrings[i])) and (not JCLFileUtils.IsDirectory(OutStrings[i])) then
        FilesUncompressed.Add(OutStrings[i])
  
  finally
    //Always kill the SetOwnerWindow.. no i have no idea what it is either..
    FSevenZipKillOwnerWindowEx(Application.Handle);
  end;

end;

{------------------------------------------------------------------------------}

Procedure TJSevenZip.UnCompressFileToStream(inZipFile : TFileName; FileInZip : String; 
        var TheStream : TMemoryStream);
begin
  Exception.Create('Uncompress to Stream not implemented');
end;

{------------------------------------------------------------------------------}

Function  TJSevenZip.VerifyFile(input : TFileName) : Boolean;
var
  jHArc: HARC;
begin
  try
    if FSevenZipCheckArchive(PChar(input), CHECKARCHIVE_ALL) = True then
    begin
      jHArc := FSevenZipOpenArchive(0, PAnsiChar(input), M_REGARDLESS_INIT_FILE + M_ERROR_MESSAGE_OFF);
      FSevenZipCloseArchive(jHArc);
      Result := (jHArc <> 0);
    end
    else
    begin
      Result := False;
    end;  
  except
    Result := False;
   end;
end;

{------------------------------------------------------------------------------}

end.
