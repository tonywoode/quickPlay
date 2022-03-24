{

This RAR support is based heavily on the RARArc component found at:

aberka@usa.net / xberka1@fi.muni.cz, ICQ UIN 2365308, http://telman.cjb.net/ or http://come.to/aberka

and originally written by 'BealSoft'.  So a big thanks to those guys, whos code
I totally ripped off.  I have removed a lot of extra cruft from their code, and
added in one or two new features that were required to add RAR support to QuickPlay.

}
unit ujCompressRAR;

interface

uses SysUtils, Classes, ComCtrls, ujCompression;

type
  TJRAR = class(TInterfacedObject, IJCompressible)
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

uses Windows, Dialogs, JCLStrings, JCLFileUtils, uJFile, ujCompressResourceStrs,
     ujMiscResourceStrs;

{-------------------------------------------------------------------------------}
{                      Start of RAR types/Const                                 }
{-------------------------------------------------------------------------------}

const
  UnRARdll = 'UnRAR.dll';

  rMaxCommentSize = 65535; {Modify this to change the limit of Comment size}

  erEndArchive    = 10; {End of archive}
  erNoMemory      = 11; {Not enough memory to initialize data structures}
  erBadData       = 12; {Archive header broken}
  erBadArchive    = 13; {File is not valid RAR archive}
  erUnknownFormat = 14; {UnKnown comment format}
  erEOpen         = 15; {File open error}
  erECreate       = 16; {File create error}
  erEClose        = 17; {File close error}
  erERead         = 18; {Read error}
  erEWrite        = 19; {Write error}
  erSmallBuf      = 20; {Buffer too small, comments weren't read completely}
  erDLLnotFound   = 50; {UNRAR.dll not found. Must be placed in actual dir or in WINDOWS\SYSTEM (SYSTEM32)}

  opList          =  0; {Open archive for reading file headers only}
  opExtract       =  1; {Open archive for testing and extracting files}

  doSkip          =  0; {Move to the next file in archive}
                        {Warning: If the archive is solid and opExtract mode                                  was set when the archive was opened, the
                                  current file will be processed - the operation
                                  will be performed slower than a simple seek}
  doTest          =  1; {Test the current file and move to the next file in
                         the archive. If the archive was opened with opList mode,
                         the operation is equal to doSkip}
  doExtract       =  2; {Extract the current file and move to the next file.
                         If the archive was opened with opList mode,
                         the operation is equal to doSkip}

  moVolAsk        =  0; {Required volume is absent. The function should prompt
                         user and return non-zero value to retry the operation.
                         The function may also specify a new volume name,
                         placing it to ArcName parameter}
                         {!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!}
  moVolNotify     =  1; {Required volume is successfully opened. This is a
                         notification call and ArcName modification is NOT
                         allowed. The funciton should return non-zero value
                         to continue or a zero value to terminate operation}
                         {!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!}


type
    RARHeaderData = record
                    ArcName                            : array[1..260] of char;
                    FileName                           : array[1..260] of char;
                    Flags                              : Cardinal;
                    PackSize                           : Cardinal;
                    UnpSize                            : Cardinal;
                    HostOS                             : Cardinal;
                    FileCRC                            : Cardinal;
                    FileTime                           : Cardinal;
                    UnpVer                             : Cardinal;
                    Method                             : Cardinal;
                    FileAttr                           : Cardinal;
                    CmtBuf                             : PChar;
                    CmtBufSize, CmtSize, CmtState      : Cardinal;
                  end;

  RAROpenArchiveData = record
                         ArcName                       : PChar;
                         OpenMode                      : Cardinal;
                         OpenResult                    : Cardinal;
                         CmtBuf                        : PChar;
                         CmtBufSize                    : Cardinal;
                         CmtSize                       : Cardinal;
                         CmtState                      : Cardinal;
                       end;

  TComment = record
               Size : Integer;
               Data : Array[1..rMaxCommentSize] of Char;
             end;
  {EVENTS}
  TChangeVolProcN     = function (Sender: TObject; ArcName : PChar; Mode : Integer) : Integer of object;
  TProcessDataProcN   = function (Sender: TObject; Addr : PChar; BlockSize, Position : Integer) : Integer of object;

  TErrorProc          = procedure (Sender: TObject; Error : Integer) of object;
  TCommentProc        = procedure (Sender: TObject; Comment : TComment) of object;
  TListFileProc       = procedure (Sender: TObject; ListedFile : RARHeaderData) of object;
  TFileBeingExtracted = procedure (Sender: TObject; eFile : RARHeaderData) of object;
  TFileExtracted      = procedure (Sender: TObject; eFile : RARHeaderData; Result : Boolean) of object;
  TFileBeingTested    = procedure (Sender: TObject; eFile : RARHeaderData) of object;
  TFileTested         = procedure (Sender: TObject; eFile : RARHeaderData; Result : Boolean) of object;
  TReqPassword        = procedure (Sender: TObject; eFile : RARHeaderData; var Password : String) of object;

  TChangeVolProc      = function (var ArcName : PChar; Mode : Integer) : Integer; cdecl;
  TProcessDataProc    = function (Addr : PChar; Size : Integer) : Integer; cdecl;
  
type PTRAROpenArchive = function (var ArchiveData: RAROpenArchiveData) : THandle; stdcall;
     PTRARCloseArchive = function (hArcData : THandle) : Integer; stdcall;
     PTRARReadHeader = function (hArcData : THandle; var HeaderData : RARHeaderData) : Integer; stdcall;
     PTRARProcessFile = function (hArcData : THandle; Operation : Integer; DestPath, DestName : PChar) : Integer; stdcall;
     PTRARSetChangeVolProc = procedure (hArcData : THandle; CVP : TChangeVolProc); stdcall;
     PTRARSetProcessDataProc = procedure (hArcData : THandle; PDP : TProcessDataProc); stdcall;
     PTRARSetPassword = procedure (hArcData : THandle; Password : PChar); stdcall;


{-------------------------------------------------------------------------------}
{                             END OF RAR types/const                            }
{-------------------------------------------------------------------------------}

// More RAR specific stuff.. no idea what this lot does...
var
    RAROpenArchive : PTRAROpenArchive;
    RARCloseArchive : PTRARCloseArchive;
    RARReadHeader : PTRARReadHeader;
    RARProcessFile : PTRARProcessFile;
    RARSetChangeVolProc : PTRARSetChangeVolProc;
    RARSetProcessDataProc : PTRARSetProcessDataProc;
    RARSetPassword : PTRARSetPassWord;
var xSelf : Pointer;

Constructor TJRAR.Create();
begin
  inherited;
  @RAROpenArchive:=nil;
  @RARCloseArchive:=nil;
  @RARReadHeader:=nil;
  @RARProcessFile:=nil;
  @RARSetChangeVolProc:=nil;
  @RARSetProcessDataProc:=nil;
  @RARSetPassword:=nil;
  _DllHandle := LoadLibrary(PChar(UnRARdll));
  if _DllHandle=0 then
    _CompressMode := cmNone
  else
  begin
    _CompressMode := cmRead;    
    @RAROpenArchive:=GetProcAddress(_DllHandle, PChar('RAROpenArchive'));
    @RARCloseArchive:=GetProcAddress(_DllHandle, PChar('RARCloseArchive'));
    @RARReadHeader:=GetProcAddress(_DllHandle, PChar('RARReadHeader'));
    @RARProcessFile:=GetProcAddress(_DllHandle, PChar('RARProcessFile'));
    @RARSetChangeVolProc:=GetProcAddress(_DllHandle, PChar('RARSetChangeVolProc'));
    @RARSetProcessDataProc:=GetProcAddress(_DllHandle, PChar('RARSetProcessDataProc'));
    @RARSetPassword:=GetProcAddress(_DllHandle, PChar('RARSetPassword'));

    if (@RAROpenArchive=nil) or (@RARCloseArchive=nil) or (@RARReadHeader=nil) or (@RARProcessFile=nil) or
      (@RARSetChangeVolProc=nil) or (@RARSetProcessDataProc=nil) or (@RARSetPassword=nil) then
        _CompressMode := cmNone;
  end;
end;

Destructor TJRAR.Destroy();
begin
  FreeLibrary(_DllHandle);
  inherited;
end;

Function TJRAR.GetCurrentMode() : TJCompressMode;
begin
  Result := _CompressMode;
end;

Function TJRAR.GetFullName() : String;
begin
  Result := 'RAR Files';
end;

{------------------------------------------------------------------------------}
{                   Public Routines                                            }
{------------------------------------------------------------------------------}

procedure TJRAR.CompressDirectory(Directory : String; FileName : TFileName; Filter : TStrings);
begin
  //this function doent do anything, unrar.dll doesnt have write support...
end;
procedure TJRAR.CompressSingleFile(input, Output : TFileName);
begin
  //this function doent do anything, unrar.dll doesnt have write support..
end;

{------------------------------------------------------------------------------}

Procedure TJRAR.ListContentsOfFile(var Contents : TStrings; FileName : TFileName);
var OpenArchiveData : RAROpenArchiveData;
    hArcData        : THandle;
    RHCode, PFCode  : Integer;
    HeaderData      : RARHeaderData;
    Comm            : TComment;
begin
  Contents.Clear;
  if _CompressMode = cmNone then
    raise Exception.Create(COMP_FORMAT_UNSUPPORTED);
  xSelf:=Self;
  OpenArchiveData.ArcName:=@FileName[1];
  {!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!}
  OpenArchiveData.CmtBuf:=@Comm.Data[1];
  OpenArchiveData.CmtBufSize:=SizeOf(Comm.Data);
  OpenArchiveData.OpenMode:=opList;
  hArcData:=RAROpenArchive(OpenArchiveData);
  Comm.Size:=OpenArchiveData.CmtSize;

  if OpenArchiveData.OpenResult<>0 then
  begin
    RARCloseArchive(hArcData);
    raise Exception.Create(COMP_READ_ERROR);
  end;

  try
    HeaderData.CmtBuf:=@Comm.Data[1];
    HeaderData.CmtBufSize:=SizeOf(Comm.Data);

    RHCode:=RARReadHeader(hArcData,HeaderData);
    while RHCode=0 do
    begin
      Contents.Add(Trim(HeaderData.FileName));

      PFCode:=RARProcessFile(hArcData,doSkip,NIL,NIL);
      if (PFCode<>0) then
        raise Exception.Create(COMP_READ_ERROR);

      RHCode:=RARReadHeader(hArcData,HeaderData);
    end;

    if (RHCode=erBadData) then
      raise Exception.Create(COMP_READ_ERROR);

  finally
    RARCloseArchive(hArcData);
  end;
end;

{------------------------------------------------------------------------------}

procedure TJRAR.RenameContentToFile(FileName : TFileName);
begin
  //not supported, unrar.dll cant write to file.
  raise Exception.Create(UNRARDLL + COMP_NO_WRITING);
end;

{------------------------------------------------------------------------------}

procedure TJRAR.RenameFileToContent(FileName : TFileName);
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
      name := ChangeFileExt(name, '.rar');
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

procedure TJRAR.SupportedFileExts(var Exts : TStringList);
begin
  Exts.Add('*.rar');
end;

{------------------------------------------------------------------------------}

Function  TJRAR.SupportsFileName(Input : TFileName; Operation : TJCompressMode) : Boolean; //based on full filename
begin
  try
    //we need to use the custom file extension function because the VCL one cant cope if the file does not exist.
    if (JCLStrings.StrCompare(ujFile.GetVirtualFileExtension(input), '.rar')=0) and
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

Procedure TJRAR.UnCompressFile(input : TFileName; OutputDir : String; Opt_Diff, Opt_Path, Opt_OW : boolean;
          var FilesUncompressed : TStringList; ExtractFilter : String = '*.*');
var OpenArchiveData : RAROpenArchiveData;
    hArcData        : THandle;
    RHCode, PFCode  : Integer;
    HeaderData      : RARHeaderData;
    Comm            : TComment;
    Temp            : Integer;
    CurFile         : String;
    Password        : String;
    OverwriteSkip   : boolean;
    TempStr         : STring;
    ExtrBaseDir     : String;
begin

  FilesUncompressed.Clear;
  
  if _CompressMode = cmNone then
    raise Exception.Create(UNRARDLL + COMP_NO_READING);

  if (input='') then
    raise Exception.Create('No archive specified');

  //for some reason the dll adds an extra \ in front of filenames, if we are looking to extract one file, and the
  //filter doesnt include the preceding \ then add it in.
  if Pos('*', ExtractFilter) = 0 then
    ExtractFilter := '\' + ExtractFilter;

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
    
  xSelf:=Self;
  OpenArchiveData.ArcName:=@input[1];
  {!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!}
  OpenArchiveData.CmtBuf:=@Comm.Data[1];
  OpenArchiveData.CmtBufSize:=SizeOf(Comm.Data);
  OpenArchiveData.OpenMode:=opExtract;
  hArcData:=RAROpenArchive(OpenArchiveData);
  Comm.Size:=OpenArchiveData.CmtSize;

  if OpenArchiveData.OpenResult<>0 then
  begin
    RARCloseArchive(hArcData);
    raise Exception.Create('Failed to open rar file, error code - ' + IntToStr(OpenArchiveData.OpenResult));
  end;

  HeaderData.CmtBuf:=@Comm.Data[1];
  HeaderData.CmtBufSize:=SizeOf(Comm.Data);

  RHCode:=RARReadHeader(hArcData,HeaderData);
  while RHCode=0 do
  begin
    //this bit of code loops through the filename and turns it from an array of char, into a string.  
    CurFile:='';
    for Temp:=1 to SizeOf(HeaderData.FileName) do
      if HeaderData.FileName[Temp]=#00 then
        break
      else
        CurFile := CurFile + HeaderData.FileName[Temp];
    
    // CurFile contains the filename, this will include the path part.  if the user doesnt want it, strip it off.
    if not Opt_Path then
      curFile := ExtrBaseDir + ujFile.GetVirtualFileName(CurFile)
    else
      curFile := ExtrBaseDir + CurFile;

    //by default the RAR dll will overwrite, if the user has chosen NOT to overwite then we need to reflect this.
    //check if the file already exists on disk if it does and overwrite is not desired, skip to the next file.
    if (Opt_OW = False) and (FileExists(CurFile)) then
      OverwriteSkip := True
    else
      OverwriteSkip := False;

    //try out the JEDI strMatches function for the wildcard filters..
    if (not OverWriteSkip) and ( JCLStrings.StrMatches(LowerCase(ExtractFilter), lowercase(ujFile.GetVirtualFileName(CurFile))) ) then
    begin
      if ((HeaderData.Flags and 4)=4) then
      begin
        Password := InputBox('Enter Password', HeaderData.ArcName + ' is password protected, please enter a password', '');
        if Password<>'' then RARSetPassword(hArcData,@Password[1]);
      end;

      //PFCode:=RARProcessFile(hArcData,doExtract,TDir,NiL);
      PFCode:=RARProcessFile(hArcData,doExtract, nil, PChar(CurFile));
      FilesUncompressed.Add(CurFile);
      if (PFCode<>0) and (PFCode<>erECreate) and (PFCode<>erBadData) then
      begin
        RARCloseArchive(hArcData);
        raise Exception.Create('An error occurred during extraction');
      end;
    end
    else
    begin
      PFCode:=RARProcessFile(hArcData,doSkip, nil, PChar(CurFile));
      if PFCode<>0 then
      begin
         RARCloseArchive(hArcData);
         raise Exception.Create('An error occurred during extraction');
      end;
    end;
    RHCode:=RARReadHeader(hArcData,HeaderData);
  end;

  if (RHCode=erBadData) then
    raise Exception.Create('An Error occurred during extraction, error code - ' + IntToStr(RHCode));

  RARCloseArchive(hArcData);
end;

{------------------------------------------------------------------------------}

Procedure TJRAR.UnCompressFileToStream(inZipFile : TFileName; FileInZip : String; 
        var TheStream : TMemoryStream);
begin
  Exception.Create('Uncompress to Stream not implemented');
end;

{------------------------------------------------------------------------------}

Function  TJRAR.VerifyFile(input : TFileName) : Boolean;
var OpenArchiveData : RAROpenArchiveData;
    hArcData        : THandle;
    RHCode, PFCode  : Integer;
    HeaderData      : RARHeaderData;
    Comm            : TComment;
    Temp            : Integer;
    S               : String;
    Password        : String;
begin
  if _CompressMode = cmNone then
    Raise Exception.Create(COMP_FORMAT_UNSUPPORTED);
  if (input='') then
    raise Exception.Create(J_INVALID_FILE_NAME);
    
  Result:=True;
  xSelf:=Self;
  OpenArchiveData.ArcName:=@input[1];
  {!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!}
  OpenArchiveData.CmtBuf:=@Comm.Data[1];
  OpenArchiveData.CmtBufSize:=SizeOf(Comm.Data);
  OpenArchiveData.OpenMode:=opExtract;
  hArcData:=RAROpenArchive(OpenArchiveData);
  Comm.Size:=OpenArchiveData.CmtSize;

  if OpenArchiveData.OpenResult<>0 then
  begin
    Result:=False;
    RARCloseArchive(hArcData);
    Exit;
  end;

  HeaderData.CmtBuf:=@Comm.Data[1];
  HeaderData.CmtBufSize:=SizeOf(Comm.Data);

  RHCode:=RARReadHeader(hArcData,HeaderData);
  while RHCode=0 do
  begin
    S:='';
    for Temp:=1 to SizeOf(HeaderData.FileName) do
      if HeaderData.FileName[Temp]=#00 then
        break
      else
        S:=S+HeaderData.FileName[Temp];

    if ((HeaderData.Flags and 4)=4) then
    begin
      Password := InputBox(J_PASSWORD_TITLE, J_PASSWORD_TEXT, '');
      if Password<>'' then
        RARSetPassword(hArcData,@Password[1]);
    end;

    PFCode:=RARProcessFile(hArcData,doTest,nil,niL);

    if PFCode<>0 then
    begin
      Result:=False;
      if (PFCode<>erECreate) and (PFCode<>erBadData) then
      begin
        RARCloseArchive(hArcData);
        Exit; {Serios error, exit}
      end;
    end;

    RHCode:=RARReadHeader(hArcData,HeaderData);
  end;

  if (RHCode=erBadData) then
    raise Exception.Create(COMP_READ_ERROR);
  RARCloseArchive(hArcData);
end;

{------------------------------------------------------------------------------}

end.
