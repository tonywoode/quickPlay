unit uJCompressZip;

interface

uses SysUtils, Classes, ComCtrls, uJCompression, ZipMstr, SyncObjs;

type

  TJZip = class(TInterfacedObject, IJCompressible)
  private
  ZipOne : TCriticalSection;
    _CompressMode : TJCompressMode;
    _ZipMstr : TZipMaster;
    _origAddOpt : AddOpts;
    _origExtOpt : ExtrOpts;
    _Extracted : TStringList;
    _ZipStream : TZipStream;
    _CurrentFile : String;
    Function GetCurrentMode() : TJCompressMode;
    Function GetFullName() : String;
    procedure OpenZip(infile : String);
    procedure ResetZipMstr();
    procedure ZipProgress(Sender: TObject; ProgrType: ProgressType; Filename: String; FileSize: Int64);
  public
    constructor Create;
    destructor Destroy;override;

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

uses Windows, JCLStrings, JCLSysInfo, uJFile, ujCompressResourceStrs;

procedure TJZip.ZipProgress(Sender: TObject; ProgrType: ProgressType; Filename: String; FileSize: Int64);
begin
  Case ProgrType of
    NewFile : _Extracted.Add(FileName);
  end;
end;

{------------------------------------------------------------------------------}

constructor TJZip.Create();
begin
  inherited;
  ZipOne := TCriticalSection.Create;
  _CurrentFile := '';
  _ZipStream := TZipSTream.Create;
  _Extracted := TStringList.Create;
  _ZipMstr := TZipMaster.Create(nil);
  _ZipMstr.Unattended := True;
  _ZipMstr.OnProgress := ZipProgress;
  
  //load the DLLS and determine what level of support we have.

  // with DelphiZip 1.79 there is now only one dll for read and write.

  Try
    _ZipMstr.Dll_Load := True;
    _CompressMode := cmFull;
  Except
    _CompressMode := cmNone;
  end;

  //save the original options
  _origAddOpt := _ZipMstr.AddOptions;
  _origExtOpt := _ZipMstr.ExtrOptions;
end;

{------------------------------------------------------------------------------}

destructor TJZip.destroy();
begin
  //depending on what mode we have, unload the required dlls.
  if _ZipMstr.Dll_Load then
    _ZipMstr.Dll_Load := False;
    
  FreeAndNil(_ZipMstr);
  FreeAndNil(_Extracted);
  FreeAndNil(ZipOne);
  inherited;
end;

{------------------------------------------------------------------------------}

Function TJZip.GetCurrentMode() : TJCompressMode;
begin
  Result := _CompressMode;
end;

{------------------------------------------------------------------------------}

Function TJZip.GetFullName() : String;
begin
  Result := 'Zip Files';
end;

{------------------------------------------------------------------------------}

procedure TJZip.OpenZip(infile : String);
begin
  if JCLStrings.StrCompare(inFile, _CurrentFile) <> 0 then
  begin
    ResetZipMstr();
    _CurrentFile := inFile;
    _ZipMstr.ZipFileName := inFile;
  end
  else
  begin
    //just clear the fspecargs, the file is currently open
    //_ZipMstr.FSpecArgs.Clear;
  end;
end;

{------------------------------------------------------------------------------}

procedure TJZip.ResetZipMstr();
begin
  _CurrentFile := '';
  _ZipMstr.rootDir := '';
  _ZipMstr.FSpecArgs.Clear;
  //reset back to default *.* behaviour, I dont know if this is needed really..
  _ZipMstr.FSpecArgs.Add('*.*');
  _ZipMstr.ZipFileName := '';
  _ZipMstr.AddOptions := _OrigAddOpt;
  _ZipMstr.ExtrOptions := _OrigExtOpt;
end;

{------------------------------------------------------------------------------}
{                   Public Routines                                            }
{------------------------------------------------------------------------------}

procedure TJZip.CompressDirectory(Directory : String; FileName : TFileName; Filter : TStrings);
begin
  ResetZipMstr();
  OpenZip(FileName);
    //set up the zip component to the way we need it.
    _ZipMstr.RootDir := Directory;
    _ZipMstr.AddOptions := _ZipMstr.AddOptions + [AddForceDest];
    _ZipMstr.AddOptions := _ZipMstr.AddOptions + [AddRecurseDirs];
    _ZipMstr.AddOptions := _ZipMstr.AddOptions + [AddDirNames];
    _ZipMstr.AddOptions := _ZipMstr.AddOptions + [AddSeparateDirs];

    _ZipMstr.FSpecArgs.Clear;
    _ZipMstr.FSpecArgs.AddStrings(Filter);
    _ZipMstr.AddCompLevel := 9;

    if _ZipMstr.Add <> 0 then
      Raise EJCompressException.Create(COMP_WRITE_ERROR + ' - ' + IntToStr(_ZipMstr.ErrCode));

end;

{------------------------------------------------------------------------------}

procedure TJZip.CompressSingleFile(input, Output : TFileName);
begin
  ResetZipMstr();
  OpenZip(Output);
    _ZipMstr.FSpecArgs.Clear;
    _ZipMstr.FSpecArgs.Add(input);
    _ZipMstr.AddCompLevel := 9;
    if _ZipMstr.Add <> 0 then
      Raise EJCompressException.Create(COMP_WRITE_ERROR + ' - ' + IntToStr(_ZipMstr.ErrCode));
end;

{------------------------------------------------------------------------------}

Procedure TJZip.ListContentsOfFile(var Contents : TStrings; FileName : TFileName);
var
  i : Integer;
begin
  OpenZip(FileName);
  Contents.Clear;
  for i := 0 to _ZipMstr.Count-1 do
    Contents.Add(_ZipMstr.DirEntry[i].FileName);
end;

{------------------------------------------------------------------------------}

procedure TJZip.RenameContentToFile(FileName : TFileName);
Var
  RenRec : pZipRenameRec;
  ZipRenameList : TList;
  TmpZip : ^ZipDirEntry;
  Path, OldName, NewName : String;
  RError, i : Integer;
Begin

  OpenZip(FileName);

    if _ZipMstr.zipcontents.count = 1 then
    begin

      TmpZip := _ZipMstr.ZipContents.Items[0];

      OldName := TmpZip^.FileName;

      Path := ExtractFileExt(OldName);

      NewName := ChangeFileExt(ExtractFileName(FileName), Path);

      If StrCompare(ChangeFileExt(OldName,''), ChangeFileExt(NewName,'')) <> 0  then
      Begin
        New(RenRec);
        Try
          ZipRenameList := TList.Create;

          RenRec^.Source := OldName;
          RenRec^.Dest := NewName;
          RenRec^.DateTime := 0;

          ZipRenameList.Add(RenRec);

          RError := _ZipMstr.Rename(ZipRenameList, 0);

          if RError <> 0  then
            raise EJCompressException.Create('Error ' + IntToStr( RError ) + ' occurred in rename zip specification(s)');

        Finally
          for i := 0 to ZipRenameList.Count - 1 do
          begin
            RenRec := ZipRenameList.Items[i];
            Dispose( RenRec );
          end;

          FreeAndNil(ZipRenameList);
        end;

      End;

    end
    else
      raise EJCompressException.Create(COMP_MORE_THAN_ONE_FILE);

End;

{------------------------------------------------------------------------------}

procedure TJZip.RenameFileToContent(FileName : TFileName);
Var
  Name : String;
  TmpZip : ^ZipDirEntry;
Begin
  OpenZip(FileName);

    if _ZipMstr.zipcontents.count = 1 then
    begin
      TmpZip := _ZipMstr.ZipContents.Items[0];

      name := TmpZip^.FileName;
      name := ChangeFileExt(name,'.zip');
      if not renameFile(FileName, name) then
        raise EJCompressException.Create('Error renaming file to' + Name);
    end
    else
      Raise EJCompressException.Create(COMP_MORE_THAN_ONE_FILE);
End;

{------------------------------------------------------------------------------}

procedure TJZip.SupportedFileExts(var Exts : TStringList);
begin
  Exts.Add('*.zip');
end;

{------------------------------------------------------------------------------}

Function  TJZip.SupportsFileName(Input : TFileName; Operation : TJCompressMode) : Boolean; //based on full filename
begin
  try
    //we need to use the custom file extension function because the VCL one cant cope if the file does not exist.
    if (JCLStrings.StrCompare(ujFile.GetVirtualFileExtension(input), '.zip')=0) and
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

Procedure TJZip.UnCompressFile(input : TFileName; OutputDir : String; Opt_Diff, Opt_Path, Opt_OW : boolean;
    var FilesUncompressed : TStringList; ExtractFilter : String = '*.*');
var
  temp : string;
  Result : Integer;
begin
    FilesUncompressed.Clear;
    Openzip(input);

    with _ZipMstr do
    begin

      if Opt_Diff = true then
      begin
        temp := ExtractFileName(input);
        Temp := ChangeFileExt(Temp, '');
        temp := IncludeTrailingPathDelimiter(OutputDir) + Temp;

        if (Not DirectoryExists(Temp)) then
          CreateDir(temp);

        ExtrBaseDir := IncludeTrailingPathDelimiter(temp);
      end
      else
        ExtrBaseDir := IncludeTrailingPathDelimiter(OutputDir);
                                             
      SetCurrentDir(ExtrBaseDir);

      If Opt_OW Then
        ExtrOptions:=ExtrOptions+[ExtrOverwrite]
      else
        ExtrOptions:=ExtrOptions-[ExtrOverwrite];

      If Opt_Path Then
        ExtrOptions:=ExtrOptions+[ExtrDirNames]
      else
        ExtrOptions:=ExtrOptions-[ExtrDirNames];

      FSpecArgs.Clear;
      FSpecArgs.Add(ExtractFilter);

      //clear internal extraction list.

      _Extracted.Clear;
      Result := Extract;

      if (Result <> 0) and (Result <> 10502) then
        Raise EJCompressException.Create(COMP_ARCHIVE_NOT_EXTRACTED + IntToStr(_ZipMstr.ErrCode));

      FilesUncompressed.AddStrings(_Extracted);

    end;
end;

{------------------------------------------------------------------------------}

Procedure TJZip.UnCompressFileToStream(inZipFile : TFileName; FileInZip : String;
        var TheStream : TMemoryStream);
begin

   OpenZip(inZipFile);

    _ZipStream := _ZipMstr.ExtractFileToStream(FileInZip);
    if (_ZipStream <> nil) and (_ZipStream.Size > 0) then
    begin
      theStream.Clear;
      theStream.LoadFromStream(_ZipStream);
      theSTream.Position := 0;
    end

end;

{------------------------------------------------------------------------------}

Function  TJZip.VerifyFile(input : TFileName) : Boolean;
begin

    ResetZipMstr();
    _ZipMstr.ZipFileName := input;
    // If the zip file is invalid, then the last error message will
    // be a 11036 message.
    if _ZipMstr.ErrCode = 11036 then
      Result := False
    else
      Result := True;

end;

end.
