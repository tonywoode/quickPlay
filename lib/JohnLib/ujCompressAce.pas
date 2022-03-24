{

Unit for ACE support.  This unit is heavily based on the examples downloadable from
the winace website.  You require the unacev2.dll for this unit to work!

}

unit ujCompressAce;

interface

uses SysUtils, Classes, ComCtrls, ujCompression, ujCompressAceConst;

type

  TJACE = class(TInterfacedObject, IJCompressible)
  private
    _DllHandle : Integer;
    _CompressMode : TJCompressMode;
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

uses Windows, Dialogs, Controls, JCLFileUtils, JCLStrings, ujFile,
     ujCompressResourceStrs, ujMiscResourceStrs;

const   FILELISTSIZE=   32768;  // pretty much for this this example:
                                // only the commandline can be used to
                                // specify files..
        COMMENTBUFSIZE= 8192;   // comments may be up to 32k in size
                                // increase it if you want to put that
                                // large comments to archives, or if
                                // you want to receive all of these large
                                // comments (ACE_COMMENT_SMALLBUF returned
                                // if comment does not fit into buffer)

var
  FileList:array[0..FILELISTSIZE-1] of char;
  CommentBuf:array[0..COMMENTBUFSIZE-1] of char;
  _CallBackStrings : TStringList;
  _DoOverwrite : Boolean;
  _ErrorStr : String;
  
  ACEInitDll         : TACEInitDll;
  ACEReadArchiveData : TACEReadArchiveData;
  ACEList            : TACEList;
  ACETest            : TACETest;
  ACEExtract         : TACEExtract;

{------------------------------------------------------------------------------}
//    ACE CALLBACKS
{------------------------------------------------------------------------------}

{-----------------HandleStateStartArchive-------------------------------}

function HandleStateStartArchive(Archive:pACECallbackArchiveStruc):integer;
begin
  result:=ACE_CALLBACK_RETURN_OK;
end;

{-----------------HandleStateStartFile----------------------------------}

function HandleStateStartFile(ArchivedFile:pACECallbackArchivedFileStruc):integer;
begin
  case ArchivedFile^.Operation of
    ACE_CALLBACK_OPERATION_LIST:
      if ArchivedFile^.FileData^.Attributes <> faDirectory then
        _CallBackStrings.Add(ArchivedFile^.FileData^.SourceFileName);
   // ACE_CALLBACK_OPERATION_TEST: ActionStr := 'Testing';
  end;


  result:=ACE_CALLBACK_RETURN_OK;
end;

{-----------------InfoProc callback-------------------------------------}

function InfoProc(Info:pACEInfoCallbackProcStruc):integer; stdcall;
begin
  result:=ACE_CALLBACK_RETURN_OK;
end;

{-----------------HandleErrorGlobal-------------------------------------}

function HandleErrorGlobal(Error:pACECallbackGlobalStruc):integer;
begin
  Result:=ACE_CALLBACK_RETURN_OK;
  case Error^.Code of
    ACE_CALLBACK_ERROR_MEMORY : _ErrorStr := ACE_NO_MEMORY;
    ACE_CALLBACK_ERROR_UNCSPACE : _ErrorStr := ACE_NETWORK_DRIVE;
  else
    _ErrorStr:= ACE_UNKNOWN_ERROR;
    Result:= ACE_CALLBACK_RETURN_CANCEL;
  end;
end;

{-----------------HandleErrorArchive------------------------------------}

function HandleErrorArchive(Error:pACECallbackArchiveStruc):integer;
begin
  Result:=ACE_CALLBACK_RETURN_OK;

  case Error^.Code of
    ACE_CALLBACK_ERROR_AV : _ErrorStr := ACE_INVALID_AV;
    ACE_CALLBACK_ERROR_OPENARCHIVEREAD : _ErrorStr := ACE_OPEN_ERROR;
    ACE_CALLBACK_ERROR_READARCHIVE : _ErrorStr := ACE_READ_ERROR;
    ACE_CALLBACK_ERROR_ARCHIVEBROKEN : _ErrorStr := ACE_BROKEN_ERROR;
    //no files specified means no files inside the archive matched the filter, this is NOT an error..
    ACE_CALLBACK_ERROR_NOFILES : Result:=ACE_CALLBACK_RETURN_OK;
    ACE_CALLBACK_ERROR_ISNOTANARCHIVE : _ErrorStr := ACE_FILE_NOT_ACE;
    ACE_CALLBACK_ERROR_HIGHERVERSION : _ErrorStr := ACE_WRONG_DLL_VERSION;
  else
    _ErrorStr := ACE_UNKNOWN_ERROR;
    Result   := ACE_CALLBACK_RETURN_CANCEL;
  end;
end;

{-----------------HandleErrorArchivedFile-------------------------------}

function HandleErrorArchivedFile(Error:pACECallbackArchivedFileStruc):integer;
begin
  Result   := ACE_CALLBACK_RETURN_OK;
  case Error^.Code of
    ACE_CALLBACK_ERROR_CREATIONNAMEINUSE : _ErrorStr := ACE_ERROR_DIR_NAME;
    ACE_CALLBACK_ERROR_WRITE : _ErrorStr := ACE_ERROR_WRITE;
    ACE_CALLBACK_ERROR_OPENWRITE : _ErrorStr := ACE_ERROR_OPEN_WRITE;
    ACE_CALLBACK_ERROR_METHOD : _ErrorStr := ACE_WRONG_DLL_VERSION;
    ACE_CALLBACK_ERROR_EXTRACTSPACE : _ErrorStr := ACE_ERROR_SPACE;
    ACE_CALLBACK_ERROR_CREATION : _ErrorStr := ACE_ERROR_CREATE_FAILED;
  else
    _ErrorStr:= ACE_UNKNOWN_ERROR;
    Result:= ACE_CALLBACK_RETURN_CANCEL;
  end;
end;

{-----------------HandleErrorRealFile-----------------------------------}

function HandleErrorRealFile(Error:pACECallbackRealFileStruc):integer;
begin
  Result   := ACE_CALLBACK_RETURN_CANCEL;
  _ErrorStr := ACE_UNKNOWN_ERROR;
end;

{-----------------HandleErrorSpace--------------------------------------}

function HandleErrorSpace(Error:pACECallbackSpaceStruc):integer;
begin
  Result   := ACE_CALLBACK_RETURN_CANCEL;
  _ErrorStr := ACE_UNKNOWN_ERROR;
end;

{-----------------HandleErrorSFXFile------------------------------------}

function HandleErrorSFXFile(Error:pACECallbackSFXFileStruc):integer;
begin
  Result   := ACE_CALLBACK_RETURN_CANCEL;
  _ErrorStr := ACE_UNKNOWN_ERROR;
end;

{-----------------HandleRequestGlobal-----------------------------------}

function HandleRequestGlobal(Request:pACECallbackGlobalStruc):integer;
begin
  Result   := ACE_CALLBACK_RETURN_CANCEL;
  _ErrorStr := ACE_UNKNOWN_ERROR;
end;

{-----------------HandleRequestArchive----------------------------------}

function HandleRequestArchive(Request:pACECallbackArchiveStruc):integer;
begin
  case Request^.Code of
    ACE_CALLBACK_REQUEST_CHANGEVOLUME :
    Begin
      _ErrorStr := ACE_VOLUME_CHANGE;
      result:=ACE_CALLBACK_RETURN_CANCEL;
      exit;
    end;
    else
    begin
      _ErrorStr := ACE_UNKNOWN_ERROR;
      result:=ACE_CALLBACK_RETURN_CANCEL;
      exit;
    end;
  end;

end;

{-----------------HandleRequestArchivedFile-----------------------------}

function HandleRequestArchivedFile(Request:pACECallbackArchivedFileStruc):integer;
var
  PassWord : String;
begin
  result:=ACE_CALLBACK_RETURN_OK;
  case Request^.Code of
    ACE_CALLBACK_REQUEST_OVERWRITE:
      if _DoOverwrite then
        Result := ACE_CALLBACK_RETURN_OK
      else
        Result := ACE_CALLBACK_RETURN_NO;

    ACE_CALLBACK_REQUEST_PASSWORD:
      begin
        Password := InputBox(J_PASSWORD_TITLE, J_PASSWORD_TEXT, '');
        if Password<>'' then
          Request^.GlobalData^.DecryptPassword := PChar(Password);
      end

    else
    begin
      _ErrorStr := ACE_UNKNOWN_ERROR;
      result:=ACE_CALLBACK_RETURN_CANCEL;
    end;
  end;
end;

{-----------------HandleRequestRealFile---------------------------------}

function HandleRequestRealFile(Request:pACECallbackRealFileStruc):integer;
begin
  _ErrorStr := ACE_UNKNOWN_ERROR;
  result:=ACE_CALLBACK_RETURN_CANCEL;
  exit;
end;

{-----------------ErrorProc callback------------------------------------}

function ErrorProc(Error:pACEErrorCallbackProcStruc):integer; stdcall;
begin
  case Error^.StructureType of
    ACE_CALLBACK_TYPE_GLOBAL:result:=HandleErrorGlobal(@Error^.Global);
    ACE_CALLBACK_TYPE_ARCHIVE:result:=HandleErrorArchive(@Error^.Archive);
    ACE_CALLBACK_TYPE_ARCHIVEDFILE:result:=HandleErrorArchivedFile(@Error^.ArchivedFile);
    ACE_CALLBACK_TYPE_REALFILE:result:=HandleErrorRealFile(@Error^.RealFile);
    ACE_CALLBACK_TYPE_SPACE:result:=HandleErrorSpace(@Error^.Space);
    ACE_CALLBACK_TYPE_SFXFILE:result:=HandleErrorSFXFile(@Error^.SFXFile);
  else
    result:=ACE_CALLBACK_RETURN_CANCEL;
  end;
end;

{-----------------RequestProc callback----------------------------------}

function RequestProc(Request:pACERequestCallbackProcStruc):integer; stdcall;
begin
  case Request^.StructureType of
    ACE_CALLBACK_TYPE_GLOBAL:result:=HandleRequestGlobal(@(Request^.Global));
    ACE_CALLBACK_TYPE_ARCHIVE:result:=HandleRequestArchive(@(Request^.Archive));
    ACE_CALLBACK_TYPE_ARCHIVEDFILE:result:=HandleRequestArchivedFile(@(Request^.ArchivedFile));
    ACE_CALLBACK_TYPE_REALFILE:result:=HandleRequestRealFile(@(Request^.RealFile));
  else
    result:=ACE_CALLBACK_RETURN_CANCEL;
  end;
end;

{-----------------StateProc callback------------------------------------}

function StateProc(State:pACEStateCallbackProcStruc):integer; stdcall;
begin
  case State^.StructureType of
    ACE_CALLBACK_TYPE_ARCHIVE:
    begin
      if (State^.Archive.Code = ACE_CALLBACK_STATE_STARTARCHIVE) then begin
        result:=HandleStateStartArchive(@State^.Archive);
        exit
      end;
    end;
    ACE_CALLBACK_TYPE_ARCHIVEDFILE:
    begin
      case State^.ArchivedFile.Code of
        ACE_CALLBACK_STATE_STARTFILE: begin
          result:=HandleStateStartFile(@State^.ArchivedFile);
          exit
        end;
      end;
    end;
    ACE_CALLBACK_TYPE_CRCCHECK:
      if (State^.CRCCheck.Code = ACE_CALLBACK_STATE_ENDCRCCHECK) then
        if State^.CRCCheck.CRCOk then
          _CallBackStrings.Add(State^.ArchivedFile.FileData^.DestinationFileName);
  end;
  result:=ACE_CALLBACK_RETURN_OK;
end;

{------------------------------------------------------------------------------}
{ TJAce code                                                                   }
{------------------------------------------------------------------------------}

constructor TJACE.Create();
var
  DllData  : tACEInitDllStruc;
  zTempDir : array[0..255] of char;
begin
  inherited;
  _CallBackStrings := TStringList.Create;
  _DllHandle := LoadLibrary('UnAceV2.Dll');
  if _DllHandle = 0 then
    _CompressMode := cmNone
  else
  begin
    _CompressMode := cmRead;

    @ACEInitDll := GetProcAddress(_DllHandle, 'ACEInitDll');
    @ACEReadArchiveData := GetProcAddress(_DllHandle, 'ACEReadArchiveData');
    @ACEList := GetProcAddress(_DllHandle, 'ACEList');
    @ACETest := GetProcAddress(_DllHandle, 'ACETest');
    @ACEExtract := GetProcAddress(_DllHandle, 'ACEExtract');

    if (@ACEInitDll=nil) or (@ACEReadArchiveData=nil)
        or (@ACEList=nil) or (@ACETest=nil) or (@ACEExtract=nil) then
    begin
      FreeLibrary(_DllHandle);
      _CompressMode := cmNone;
    end
    else
    begin
      //begin the setup of the DLL
      
      FillChar(DllData, SizeOf(DllData), 0);                 // set all fields to zero
      DllData.GlobalData.MaxArchiveTestBytes := $1ffFF;      // search for archive
                                                         // header in first 128k
                                                         // of file
      DllData.GlobalData.MaxFileBufSize      := $2ffFF;      // read/write buffer size
                                                         // is 256k
      DllData.GlobalData.Comment.BufSize     := SizeOf(CommentBuf)-1;
      DllData.GlobalData.Comment.Buf         := @CommentBuf; // set comment bufffer
      GetTempPath(255, @zTempDir);
      DllData.GlobalData.TempDir             := @zTempDir;

      // set callback function pointers
      DllData.GlobalData.InfoCallbackProc    := @InfoProc;
      DllData.GlobalData.ErrorCallbackProc   := @ErrorProc;
      DllData.GlobalData.RequestCallbackProc := @RequestProc;
      DllData.GlobalData.StateCallbackProc   := @StateProc;

      if ACEInitDll(@DllData) <> 0 then
        _CompressMode := cmNone;

    end;
  end;
end;

{------------------------------------------------------------------------------}

Destructor TJAce.Destroy();
begin
  FreeAndNil(_CallBackStrings);
  FreeLibrary(_DllHandle);
  inherited;
end;

{------------------------------------------------------------------------------}

Function TJAce.GetCurrentMode() : TJCompressMode;
begin
  Result := _CompressMode;
end;

{------------------------------------------------------------------------------}

Function TJAce.GetFullName() : String;
Begin
  Result := 'ACE Files';
end;

{------------------------------------------------------------------------------}
{                   Public Routines                                            }
{------------------------------------------------------------------------------}

procedure TJAce.CompressDirectory(Directory : String; FileName : TFileName; Filter : TStrings);
begin
  //this function doent do anything, unrar.dll doesnt have write support...
end;

{------------------------------------------------------------------------------}

procedure TJAce.CompressSingleFile(input, Output : TFileName);
begin
  //this function doent do anything, unrar.dll doesnt have write support..
end;

{------------------------------------------------------------------------------}

Procedure TJAce.ListContentsOfFile(var Contents : TStrings; FileName : TFileName);
var
  List:tACEListStruc;
begin
  fillchar(List, sizeof(List),#0);   // set all fields to zero

  List.Files.SourceDir   := '';        // archive main directory is
                                       // base directory for FileList
  List.Files.FileList    := FileList;  // set FileList
  List.Files.ExcludeList := '';        // no files to exclude
  List.Files.FullMatch   := false;     // also list files partially matching
                                       // (for instance: list DIR1\TEST.DAT
                                       //  if FileList specifies TEST.DAT)

  _ErrorStr := '';
  ACEList(PChar(FileName), @List);
  //check there wasnt an error
  if _ErrorStr <> '' then
    raise EJCompressException.Create(_ErrorStr);
    
  //now assign the callback strings into the contents strings.
  Contents.Clear;
  Contents.AddStrings(_CallBackStrings);
  _CallBackStrings.Clear;

end;

{------------------------------------------------------------------------------}

procedure TJAce.RenameContentToFile(FileName : TFileName);
begin
  //not supported, unace.dll cant write to file.
  raise Exception.Create('Unace.dll' + COMP_NO_WRITING);
end;

{------------------------------------------------------------------------------}

procedure TJAce.RenameFileToContent(FileName : TFileName);
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
      name := ChangeFileExt(name, '.ace');
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

procedure TJAce.SupportedFileExts(var Exts : TStringList);
begin
  Exts.Add('*.ace');
end;

{------------------------------------------------------------------------------}

function TJAce.SupportsFileName(Input : TFileName; Operation : TJCompressMode) : Boolean; //based on full filename
begin
  try
    //we need to use the custom file extension function because the VCL one cant cope if the file does not exist.
    if (JCLStrings.StrCompare(ujFile.GetVirtualFileExtension(input), '.ace')=0) and
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

Procedure TJAce.UnCompressFile(input : TFileName; OutputDir : String; Opt_Diff, Opt_Path, Opt_OW : boolean;
      var FilesUncompressed : TStringList; ExtractFilter : String = '*.*');
var
  Extract          : tACEExtractStruc;
  zDestinationDir  : array[0..255] of char;
  TempStr, ExtrBaseDir : String;
begin

  FilesUncompressed.Clear;
  
  //check if the user wants separate directories..
  if Opt_Diff then
  begin
    tempStr := ExtractFileName(input);
    tempStr := ChangeFileExt(tempStr, '');
    tempStr := IncludeTrailingPathDelimiter(OutputDir) + tempStr;
    JCLFileUtils.ForceDirectories(TempStr);
    ExtrBaseDir := IncludeTrailingPathDelimiter(tempStr);
  end
  else
    ExtrBaseDir := IncludeTrailingPathDelimiter(OutputDir);

//  memset(&Extract, 0, sizeof(Extract));         // set all fields to zero
  FillChar(Extract, SizeOf(Extract), 0);          // set all fields to zero
  Extract.Files.SourceDir      := '';             // archive main directory is
                                                  // base dir for FileList
  Extract.Files.FileList       := PAnsiChar(ExtractFilter);       // set FileList
  Extract.Files.ExcludeList    := '';             // no files to exclude
  Extract.Files.FullMatch      := False;          // also extract files
                                                  // partially matching

  Extract.DestinationDir       := StrPCopy(zDestinationDir, ExtrBaseDir); // directory to extract to
  Extract.ExcludePath          := not Opt_Path;  // extract files with path?
  Extract.DecryptPassword      := '';

  _DoOverwrite := Opt_OW;

  _ErrorStr := '';
  ACEExtract(PChar(Input), @Extract);
  if _ErrorStr <> '' then
    raise EJCompressException.Create(_ErrorStr);

  //now assign the callback strings into the contents strings.
  FilesUncompressed.AddStrings(_CallBackStrings);
  _CallBackStrings.Clear;
end;

{------------------------------------------------------------------------------}

Procedure TJAce.UnCompressFileToStream(inZipFile : TFileName; FileInZip : String; 
        var TheStream : TMemoryStream);
begin
  Exception.Create('Uncompress to Stream not implemented');
end;

{------------------------------------------------------------------------------}

Function  TJAce.VerifyFile(input : TFileName) : Boolean;
var
  ArchiveData : tACEReadArchiveDataStruc;
  Test:tACETestStruc;
begin
  if _CompressMode = cmNone then
    Raise Exception.Create(COMP_FORMAT_UNSUPPORTED);
  if (input='') then
    raise Exception.Create(J_INVALID_FILE_NAME);

  //first test if this is actually an ACE archive.
  ACEReadArchiveData(PAnsiChar(input), @ArchiveData);
  if ArchiveData.ArchiveData=nil then
  begin
    Result := False;
    exit;
  end;

  fillchar(Test, sizeof(Test),#0);    // set all fields to zero

  Test.Files.SourceDir  := '';        // archive main directory is
                                      // base directory for FileList
  Test.Files.FileList:=FileList;      // set FileList
  Test.Files.ExcludeList :='';        // no files to exclude
  Test.Files.FullMatch  := false;     // also test files partially matching
  Test.DecryptPassword  := '';        // no encrypted file expected
  //if we are here then this is an ACE file, verify each file inside it.
  _ErrorStr := '';
  ACETest(PAnsiChar(Input), @Test);
  if _ErrorStr <> '' then
    Result := False
  else
    Result := True;

  _ErrorStr := '';
  _CallBackStrings.Clear;
  
end;

{------------------------------------------------------------------------------}

end.
 