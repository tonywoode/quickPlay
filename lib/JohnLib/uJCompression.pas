{
 This unit is the main compression wrapper around the various objects for
 each type of compression format.  This unit has some QuickPlay specific
 compression utilities that take advantage of the routines exposed by each
 compression object.  
}

unit uJCompression;

interface

uses SysUtils, Classes, ComCtrls, contnrs;

type

  { this is what type of support the compression object has
    cmNone = No zip support available (most likely required DLLs were not found)
    cmRead = Read only/Extract support is only available
    cmWrite = Write/Create File support is only available
    cmFull = Full support of extraction and creation of files is available
  }
  TJCompressMode = (cmNone, cmRead, cmWrite, cmFull);

  EJCompressException = class(Exception); //generic compression exception

  IJCompressible = interface
    ['{08F3CA94-6C39-41E0-841D-85F376AEE959}']
    Function  GetCurrentMode(): TJCompressMode;
    Function GetFullName() : String;

    procedure CompressDirectory(Directory : String; FileName : TFileName; Filter : TStrings); //compresses an entire directory to filename
    procedure CompressSingleFile(input, Output : TFileName); //compresses a single file to a compressed file of the same name with different file extension
    Procedure ListContentsOfFile(var Contents : TStrings; FileName : TFileName); //fills contents of archive into the stringlist provided
    procedure RenameContentToFile(FileName : TFileName); //renames the SINGLE content of the archive to the same name as the archive
    procedure RenameFileToContent(FileName : TFileName); //renames the ARCHIVE to the name of the SINGLE file inside.
    procedure SupportedFileExts(var Exts : TStringList);
    Function  SupportsFileName(Input : TFileName; Operation : TJCompressMode) : Boolean; //based on full filename
    Procedure UnCompressFile(input : TFileName; OutDir : String; Opt_Diff, Opt_Path, Opt_OW : boolean;
        var FilesUncompressed : TStringList; ExtractFilter : String = '*.*');
    Procedure UnCompressFileToStream(inZipFile : TFileName; FileInZip : String; 
        var TheStream : TMemoryStream);
    Function  VerifyFile(input : TFileName) : Boolean;

    Property FullName : String read GetFullName;
    Property CurrentMode : TJCompressMode read GetCurrentMode;
  end;

  TJCompression = class(Tobject)
  Protected
    _compressors : TInterfaceList;
    _FileExts : TStringList;
    _CfgDir : String;
    Function IJCompressibleByFileName(FileName : String; Operation : TJCompressMode) : IJCompressible;
    Function IndexByFileName(FileName : String; Operation : TJCompressMode) : Integer;
  public
    constructor Create(CfgDir : String);
    destructor Destroy(); override;

    //interface functions
    procedure CompressDirectory(Directory : String; FileName : TFileName; Filter : TStrings);
    procedure CompressSingleFile(input, Output : TFileName);
    procedure ListCompressorsByName(var output : TStringList);overload;
    Function ListCompressorsByName() : String;overload;
    Function ListCompressorsByName(ForMode : TJCompressMode) : String;overload;
    Procedure ListContentsOfFile(var Contents : TStrings; FileName : TFileName);
    procedure RenameContentToFile(FileName : TFileName);
    procedure RenameFileToContent(FileName : TFileName);
    procedure SupportedFileExts(var Exts : TStringList); overload;
    function SupportedFileExts(): String; overload;
    Function SupportedFileExts(ForMode : TJCompressMode) : String; overload;
    Function SupportedFileExtsForFind() : String;
    Function SupportedFileExtsForOpenDlg(AddExts : String; AddAllFiles : Boolean) : String;
    Function  SupportsFileName(Input : TFileName; Operation : TJCompressMode) : Boolean; //based on full filename
    Procedure UnCompressFile(input : TFileName; OutDir : String; Opt_Diff, Opt_Path, Opt_OW : boolean;
        var FilesUncompressed : TStringList; ExtrFilter : String = '*.*');overload;
    Procedure UnCompressFile(input : TFileName; OutDir : String; Opt_Diff, Opt_Path, Opt_OW : boolean;
        ExtrFilter : String = '*.*');overload;
    Procedure UnCompressFileToStream(inZipFile : TFileName; FileInZip : String; 
        var TheStream : TMemoryStream);
    Function  VerifyFile(input : TFileName) : Boolean;

    Property CfgDir : String read _CfgDir write _CfgDir;
  end;

implementation

uses JCLStrings, JCLFileUtils, uJCompressZip, ujCompressRAR, ujCompressAce,
     ujCompress7zip, ujCompressResourceStrs, ujMiscResourceStrs;

{-----------------------------------------------------------------------------}

Constructor TJCompression.Create(CfgDir : String);
var
  i : Integer;
  MyCompress : IJCompressible;
begin
  _cfgDir := CfgDir;
  _Compressors := TInterfaceList.Create;
  _Compressors.Add(IJCompressible(TJZip.Create()));
  _Compressors.Add(IJCompressible(TJRAR.Create()));
  _Compressors.Add(IJCompressible(TJAce.Create()));
  _Compressors.Add(IJCompressible(TJSevenZip.Create()));
  _FileExts := TStringList.Create;

  for i := 0 to _compressors.Count-1 do
  begin
    MyCompress := IJCompressible(_Compressors[i]);
    //ignore any compressors that have no support..
    if MyCompress.CurrentMode <> cmNone then
      MyCompress.SupportedFileExts(_FileExts);
  end;
end;

{-----------------------------------------------------------------------------}

destructor TJCompression.destroy();
begin
  _Compressors.Clear;
  _Compressors.Free;
  inherited;
end;

{-----------------------------------------------------------------------------}
// Private Routines

Function TJCompression.IJCompressibleByFileName(FileName : String; Operation : TJCompressMode) : IJCompressible;
var
  I : Integer;
  MyCompress : IJCompressible;
begin
  Result := nil;
  for i := 0 to _compressors.Count-1 do
  begin
    MyCompress := IJCompressible(_Compressors[i]);
    if (MyCompress <> nil) and (MyCompress.SupportsFileName(FileName, Operation)) then
    begin
      Result := MyCompress;
      break;
    end
    else
      continue;
  end;
end;

{-----------------------------------------------------------------------------}

Function TJCompression.IndexByFileName(FileName : String; Operation : TJCompressMode) : Integer;
var
  I : Integer;
  MyCompress : IJCompressible;
begin
  Result := -1;
  for i := 0 to _compressors.Count-1 do
  begin
    //_Compressors[i].GetInterface(IJCompressible, MyCompress);
    MyCompress := IJCompressible(_Compressors[i]);
    if (MyCompress <> nil) and (MyCompress.SupportsFileName(FileName, Operation)) then
    begin
      Result := i;
      break;
    end
    else
      continue;
  end;
end;

{-----------------------------------------------------------------------------}
// PUBLIC ROUTINES

procedure TJCompression.SupportedFileExts(var Exts : TStringList);
begin
  Exts.Clear;
  Exts.AddStrings(_FileExts);
end;

{-----------------------------------------------------------------------------}

function TJCompression.SupportedFileExts(): String;
begin
  Result := _FileExts.GetText;
end;

{-----------------------------------------------------------------------------}

Function TJCompression.SupportedFileExts(ForMode : TJCompressMode) : String;
var
  i : Integer;
  MyCompress : IJCompressible;
  Exts : TStringList;
begin
  Exts := TStringList.Create;
  try
    for i := 0 to _compressors.Count-1 do
    begin
      MyCompress := IJCompressible(_Compressors[i]);
      if MyCompress.CurrentMode in [ForMode, cmFull] then
        MyCompress.SupportedFileExts(Exts);
    end;
    Result := Exts.GetText;
  finally
    FreeAndNil(Exts);
  end;
end;

{-----------------------------------------------------------------------------}

Function TJCompression.SupportedFileExtsForFind() : String;
var
  i : Integer;
begin
  Result := '';
  for i := 0 to _fileExts.Count-1 do
    Result := Result + _fileExts[i] + ';';
end;

{-----------------------------------------------------------------------------}

Function TJCompression.SupportedFileExtsForOpenDlg(AddExts : String; AddAllFiles : Boolean) : String;
var
  i, e : Integer;
  MyCompress : IJCompressible;
  Exts : TStringList;
begin
  Result := '';

  Exts := TStringList.Create;
  try
    Result := 'All Supported Formats|';

    if AddExts <> '' then
      Result := Result + AddExts + ';';

    for i := 0 to _compressors.Count-1 do
    begin
      Exts.Clear;
      MyCompress := IJCompressible(_Compressors[i]);
      MyCompress.SupportedFileExts(Exts);

      for e := 0 to Exts.Count-1 do
        Result := Result + Exts[e] + ';';
    end;
    if AddAllFiles then
        Result := Result + '|All Files (*.*)|*.*';
  finally
    FreeAndNil(Exts);
  end;
end;

{-----------------------------------------------------------------------------}

Function  TJCompression.SupportsFileName(Input : TFileName; Operation : TJCompressMode) : Boolean; //based on full filename
begin
  if Self.IndexByFileName(Input, Operation) <> -1 then
    Result := True
  else
    Result := False;
end;

{-----------------------------------------------------------------------------}

procedure TJCompression.ListCompressorsByName(var output : TStringList);
var
  i : Integer;
  MyCompress : IJCompressible;
begin
  Output.Clear;
  
  for i := 0 to _compressors.Count-1 do
  begin
    MyCompress := IJCompressible(_Compressors[i]);
    Output.Add(MyCompress.FullName);
  end;
end;

{-----------------------------------------------------------------------------}

Function TJCompression.ListCompressorsByName() : String;
var
  i : Integer;
  MyCompress : IJCompressible;
begin
  Result := '';
  for i := 0 to _compressors.Count-1 do
  begin
    MyCompress := IJCompressible(_Compressors[i]);
    Result := Result + MyCompress.FullName + ', ';
  end;
  Result := Copy(Result, 1, Length(Result)-2);
end;

{-----------------------------------------------------------------------------}

Function TJCompression.ListCompressorsByName(ForMode : TJCompressMode) : String;
var
  i : Integer;
  MyCompress : IJCompressible;
begin
  Result := '';
  for i := 0 to _compressors.Count-1 do
  begin
    MyCompress := IJCompressible(_Compressors[i]);
    if MyCompress.CurrentMode in [ForMode, cmFull] then
      Result := Result + MyCompress.FullName + ', ';
  end;
  Result := Copy(Result, 1, Length(Result)-2);
end;

{-----------------------------------------------------------------------------}

Procedure TJCompression.ListContentsOfFile(var Contents : TStrings; FileName : TFileName);
var
  MyCompress : IJCompressible;
begin
  if not FileExists(FileName) then
    raise EJCompressException.Create(J_FILE_NOT_EXIST);
    
  MyCompress := IJCompressibleByFileName(FileName, cmRead);
  if MyCompress <> nil then
  begin
    if MyCompress.CurrentMode in [cmRead, cmFull] then
      MyCompress.ListContentsOfFile(Contents, FileName)
    else
      raise EJCompressException.Create(MyCompress.FullName + COMP_NO_READING);
  end
  else
    raise EJCompressException.Create(COMP_FORMAT_UNSUPPORTED);
end;

{-----------------------------------------------------------------------------}

procedure TJCompression.RenameContentToFile(FileName : TFileName);
var
  MyCompress : IJCompressible;
begin
  MyCompress := IJCompressibleByFileName(FileName, cmWrite);
  if MyCompress <> nil then
  begin
    if MyCompress.CurrentMode in [cmWrite, cmFull] then
      MyCompress.RenameContentToFile(FileName)
    else
      raise EJCompressException.Create(MyCompress.FullName + COMP_NO_WRITING);
  end
  else
    raise EJCompressException.Create(COMP_FORMAT_UNSUPPORTED);
end;

{-----------------------------------------------------------------------------}

procedure TJCompression.RenameFileToContent(FileName : TFileName);
var
  MyCompress : IJCompressible;
begin
  MyCompress := IJCompressibleByFileName(FileName, cmRead);
  if MyCompress <> nil then
  begin
    if MyCompress.CurrentMode in [cmRead, cmFull] then
      MyCompress.RenameFileToContent(FileName)
    else
      raise EJCompressException.Create(MyCompress.FullName + COMP_NO_READING);
  end
  else
    raise EJCompressException.Create(COMP_FORMAT_UNSUPPORTED);
end;

{-----------------------------------------------------------------------------}

Procedure TJCompression.UnCompressFile(input : TFileName; OutDir : String; Opt_Diff, Opt_Path, Opt_OW : boolean;
          var FilesUncompressed : TStringList; ExtrFilter : String = '*.*');
var
  MyCompress : IJCompressible;
begin
  MyCompress := IJCompressibleByFileName(input, cmRead);
  if MyCompress <> nil then
  begin
    if MyCompress.CurrentMode in [cmRead, cmFull] then
      MyCompress.UnCompressFile(input, IncludeTrailingPathDelimiter(outdir), opt_diff, opt_path, opt_ow, FilesUncompressed, ExtrFilter)
    else
      raise EJCompressException.Create(MyCompress.FullName + COMP_NO_READING);
  end
  else
    raise EJCompressException.Create(COMP_FORMAT_UNSUPPORTED);
end;

{-----------------------------------------------------------------------------}

Procedure TJCompression.UnCompressFile(input : TFileName; OutDir : String; Opt_Diff, Opt_Path, Opt_OW : boolean; ExtrFilter : String = '*.*');
var
  MyCompress : IJCompressible;
  useless : TStringList;
begin
  MyCompress := IJCompressibleByFileName(input, cmRead);
  if MyCompress <> nil then
  begin
    if MyCompress.CurrentMode in [cmRead, cmFull] then
    begin
      useless := TStringList.Create;
      try
        MyCompress.UnCompressFile(input, IncludeTrailingPathDelimiter(outdir), opt_diff, opt_path, opt_ow, useless, ExtrFilter)
      finally
        FreeAndNil(useless);
      end;
    end
    else
      raise EJCompressException.Create(MyCompress.FullName + COMP_NO_READING);
  end
  else
    raise EJCompressException.Create(COMP_FORMAT_UNSUPPORTED);
end;

Procedure TJCompression.UnCompressFileToStream(inZipFile : TFileName; FileInZip : String; 
        var TheStream : TMemoryStream);
var
  MyCompress : IJCompressible;
begin
  MyCompress := IJCompressibleByFileName(inZipFile, cmRead);
  if MyCompress <> nil then
  begin
    if MyCompress.CurrentMode in [cmRead, cmFull] then
    begin
      MyCompress.UnCompressFileToStream(inZipFile, FileInZip, TheStream);
    end
    else
      raise EJCompressException.Create(MyCompress.FullName + COMP_NO_READING);
  end
  else
    raise EJCompressException.Create(COMP_FORMAT_UNSUPPORTED);
end;

{-----------------------------------------------------------------------------}

Function  TJCompression.VerifyFile(input : TFileName) : Boolean;
var
  MyCompress : IJCompressible;
begin
  MyCompress := IJCompressibleByFileName(input, cmRead);
  if MyCompress <> nil then
  begin
    if MyCompress.CurrentMode in [cmRead, cmFull] then
      Result := MyCompress.VerifyFile(input)
    else
      raise EJCompressException.Create(MyCompress.FullName + COMP_NO_READING);
  end
  else
    raise EJCompressException.Create(COMP_FORMAT_UNSUPPORTED);
end;

{-----------------------------------------------------------------------------}

procedure TJCompression.CompressDirectory(Directory : String; FileName : TFileName; Filter : TStrings);
var
  MyCompress : IJCompressible;
begin
  MyCompress := IJCompressibleByFileName(FileName, cmWrite);
  if MyCompress <> nil then
  begin
    if MyCompress.CurrentMode in [cmWrite, cmFull] then
      MyCompress.CompressDirectory(Directory, FileName, Filter)
    else
      raise EJCompressException.Create(MyCompress.FullName + COMP_NO_WRITING);
  end
  else
    raise EJCompressException.Create(COMP_FORMAT_UNSUPPORTED);
end;

{-----------------------------------------------------------------------------}

procedure TJCompression.CompressSingleFile(input, Output : TFileName);
var
  MyCompress : IJCompressible;
begin
  MyCompress := IJCompressibleByFileName(output, cmWrite);
  if MyCompress <> nil then
  begin
    if MyCompress.CurrentMode in [cmWrite, cmFull] then
      MyCompress.CompressSingleFile(input, Output)
    ELSE
      raise EJCompressException.Create(MyCompress.FullName + COMP_NO_WRITING);
  end
  else
    raise EJCompressException.Create(COMP_FORMAT_UNSUPPORTED);
end;

{-----------------------------------------------------------------------------}

end.
