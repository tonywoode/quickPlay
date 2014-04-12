unit fZip;

interface
                    
uses
  Windows, SysUtils, Classes, Controls, Forms,
  Dialogs, ComCtrls, StdCtrls, Buttons,
  JvBaseDlg, JvBrowseFolder, JvComponent, Mask, JvExMask, JvToolEdit,
  CheckLst, fJWinFontForm;

type
  TFrmCompressionTools = class(TJWinFontForm)
    PgCompression: TPageControl;
    TabUncompress: TTabSheet;
    TabCompress: TTabSheet;
    lblOutput: TLabel;
    ChkDiffDir: TCheckBox;
    ChkExtPath: TCheckBox;
    ChkOver: TCheckBox;
    LblZipOutput: TLabel;
    GrpFilter: TGroupBox;
    ListFilter: TListBox;
    BtnFilAdd: TSpeedButton;
    BtnFilMin: TSpeedButton;
    BtnClose: TButton;
    TabRename: TTabSheet;
    TabVerify: TTabSheet;
    lblInvalid: TLabel;
    LblTotVer: TLabel;
    ProgBar: TProgressBar;
    RadFileToContent: TRadioButton;
    RadContentToFile: TRadioButton;
    TxtUncompressOutput: TJvDirectoryEdit;
    TxtCompressOutput: TJvDirectoryEdit;
    TxtVerifyOutput: TJvDirectoryEdit;
    memoErrors: TMemo;
    LblInput: TLabel;
    TxtInput: TJvDirectoryEdit;
    ChkSubdir: TCheckBox;
    CmbOperation: TComboBox;
    lblAction: TLabel;
    BtnBegin: TButton;
    cmbCompressFormat: TComboBox;
    lblCompressFormat: TLabel;
    ChkLstUncompress: TCheckListBox;
    lblUncompressFormat: TLabel;
    lblVerifyFormat: TLabel;
    chkLstVerify: TCheckListBox;
    lblRenameFormat: TLabel;
    chkLstRename: TCheckListBox;
    Label1: TLabel;
    ChkVerifyMove: TCheckBox;
    procedure FormCreate(Sender: TObject);
    procedure BtnFilAddClick(Sender: TObject);
    procedure BtnFilMinClick(Sender: TObject);
    procedure CmbOperationChange(Sender: TObject);
    procedure BtnBeginClick(Sender: TObject);
    procedure RadFileToContentClick(Sender: TObject);
    procedure RadContentToFileClick(Sender: TObject);
    procedure TxtUncompressOutputBeforeDialog(Sender: TObject;
      var Name: String; var Action: Boolean);
    procedure ChkVerifyMoveClick(Sender: TObject);
  private
    { Private declarations }
    Function GetFilterFromChkLst(ChkLst : TCheckListBox) : String;
    procedure Uncompress();
    procedure Compress();
    procedure Rename();
    procedure Verify();
  public
    { Public declarations }
    ZipRenameList: TList;
  end;

implementation

uses FindFile, shellAPI, uJFile, fMain, JCLStrings, uJUtilities, uQPConst,
  uQPCompObj, uJCompression, ujCompressResourceStrs, ujMiscResourceStrs;

{$R *.dfm}
{$WARN SYMBOL_PLATFORM OFF}

{-----------------------------------------------------------------------------}
{----------------------------   PRIVATE CODE   -------------------------------}
{-----------------------------------------------------------------------------}

Function TFrmCompressionTools.GetFilterFromChkLst(ChkLst : TCheckListBox) : String;
var
  i : integer;
  FilterEmpty : Boolean;
begin
  //check we have some compression support..
  if ChkLst.Items.Count = 0 then
    raise EJException.Create(COMP_NO_READ_SUPPORT);
  
  //get the selected compression types..
  filterEmpty := True;
  Result := '';
  for i := 0 to ChkLst.Items.Count-1 do
    if ChkLst.Checked[i] then
    begin
      FilterEmpty := False;
      Result := Result + ChkLst.Items[i] + ';';
    end;

  if FilterEmpty then
    raise EJException.Create(J_ENTER_ALL_DATA);

end;

procedure TFrmCompressionTools.Uncompress();
var
  Find : ThhFindFile;
  i : integer;
begin

  if TxtUncompressOutput.Text = '' then
  begin
    MessageDlg(J_ENTER_ALL_DATA, mtError, [mbOK], 0);
    TxtUncompressOutput.SetFocus;
    exit;
  end;
  
  if DirCheck(TxtUncompressOutput.Text, J_OUTPUT) = false then
    exit;

  Find := ThhFindFile.Create(self);
  try

    try
      Find.Filter := GetFilterFromChkLst(ChkLstUncompress);
    except
      on E: EJException do
      begin
        MessageDlg(E.Message, mtError, [mbOK], 0);
        exit;
      end;
    end;

    Find.Recurse := ChkSubDir.Checked;
    
    Find.Directory := IncludeTrailingPathDelimiter(TxtInput.Text);
    Find.Execute;

    ProgBar.Position := 0;
    ProgBar.Max := Find.TotalFile;
    for i := 0 to Find.TotalFile-1 do
    begin
      try
        uQPCompObj.Compression.UnCompressFile(Find.Files[i], TxtUncompressOutput.Text, ChkDiffDir.Checked,
          ChkExtPath.Checked, ChkOver.Checked);
      except
        MemoErrors.Lines.Add(Find.Files[i]);
      end;
      ProgBar.StepIt;
    end;

  finally
    FreeAndNil(Find);
  end;     
end;


{-----------------------------------------------------------------------------}

procedure TFrmCompressionTools.Compress();
var
  Find : ThhFindFile;
  i : integer;
  filter, FilePath, FileExt : String;
begin

  if (TxtCompressOutput.Text = '') or (cmbCompressFormat.ItemIndex = -1) then
  begin
    MessageDlg(J_ENTER_ALL_DATA, mtError, [mbOK], 0);
    exit;
  end;
  if DirCheck(TxtCompressOutput.Text, J_OUTPUT) = false then
    exit;

  Find := ThhFindFile.Create(self);
  try

    If ListFilter.Items.Count = 0 then
      Find.Filter := '*.*'
    else
    begin
      for i := 0 to (listfilter.Items.Count - 1) do
        filter := filter + ';' + listfilter.items[i];
      Find.Filter := filter;
    end;
    
    Find.Directory := TxtInput.Text;
    Find.Attributes := [ffReadOnly, ffHidden];
    Find.Recurse := ChkSubDir.Checked;
    Find.Execute;

    //get the fileExt
    FileExt := Copy(cmbCompressFormat.Text, 2, Length(cmbCompressFormat.Text));

    IF Find.totalFile > 0 then
    begin

      ProgBar.Position := 0;
      ProgBar.Max := Find.TotalFile;

      for i := 0 to Find.TotalFile-1 do
      begin
        FilePath := IncludeTrailingPathDelimiter(TxtCompressOutput.Text) + ChangeFileExt(ExtractFileName(Find.Files[i]), FileExt);
        try
          uQPCompObj.Compression.CompressSingleFile(Find.Files[i], FilePath);
        except
          MemoErrors.Lines.Add(Find.Files[i]);
        end;
        ProgBar.StepIt;
      end;


    end;

  finally
    FreeAndNil(Find);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmCompressionTools.Rename();
Var
  Find : ThhFindFile;
  i : integer;
begin

  Find := ThhFindFile.Create(self);
  try

    Find.Directory := TxtInput.Text;
    Find.Attributes := [ffReadOnly, ffHidden];
    Find.Filter := self.GetFilterFromChkLst(ChkLstRename);
    Find.Recurse := ChkSubDir.Checked;
    Find.Execute;
    SetCurrentDir(TxtInput.Text);

    ProgBar.Position := 0;
    ProgBar.Max := Find.TotalFile;

    For i := 0 to (Find.TotalFile-1) do
    begin

      try
        If RadFileToContent.Checked then
          uQPCompObj.Compression.RenameFileToContent(Find.Files[i]);
        If RadContentToFile.Checked then
          uQPCompObj.Compression.RenameContentToFile(Find.Files[i]);
      except
        MemoErrors.Lines.Add(Find.Files[i]);
      end;

      ProgBar.StepIt;

    end;

  finally
    FreeAndNil(Find);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmCompressionTools.Verify();
Var
  Find : ThhFindFile;
  i, BadCount : Integer;
  temp : String;
begin

  if (ChkVerifyMove.Checked) and (TxtVerifyOutput.Text = '') then
  begin
    MessageDlg(J_ENTER_ALL_DATA, mtError, [mbOK], 0);
    TxtVerifyOutput.SetFocus;
    exit;
  end;
  if (ChkVerifyMove.Checked) and (DirCheck(TxtVerifyOutput.Text, J_OUTPUT) = false) then
    exit;
  
  Find := ThhFindFile.Create(self);
  try

    try
      Find.Filter := GetFilterFromChkLst(ChkLstUncompress);
    except
      on E: EJException do
      begin
        MessageDlg(E.Message, mtError, [mbOK], 0);
        exit;
      end;
    end;

    lblInvalid.Caption := '';
    lblTotVer.Caption := '';
    Find.Recurse := ChkSubDir.Checked;
    Find.Directory := TxtInput.Text;
    Find.Attributes := [ffReadOnly, ffHidden];

    BadCount := 0;

    Find.Execute;

    ProgBar.Position := 0;
    ProgBar.Max := Find.TotalFile;

    for i := 0 to find.TotalFile-1 do
    begin

      // Test each zip in turn with the VerifyZip function

      if uQPCompObj.Compression.VerifyFile(Find.Files[i]) = false  then
      begin

        // If the zip file is invalid and the user wants to move it..
        if ChkVerifyMove.Checked then
        begin
          Temp := IncludeTrailingPathDelimiter(TxtVerifyOutput.Text);
          Temp := Temp + ExtractFileName(Find.Files[i]);
          FileCopy(find.Files[i], Temp, true);
        end;
        MemoErrors.Lines.Add(J_INVALID + ' - ' + Find.Files[i]);
        // Now increment the BadCount variable.
        Inc(BadCount);

      end;  

      ProgBar.StepIt;
    end;

    LblTotVer.Caption := IntToStr(Find.TotalFile);
    LblInvalid.Caption := IntToStr(BadCount);

  finally
    FreeAndNil(find);
  end;

end;

{-----------------------------------------------------------------------------}


procedure TFrmCompressionTools.FormCreate(Sender: TObject);
var
  i : Integer;
begin
  for i := 0 to pgCompression.PageCount-1 do
    pgCompression.Pages[i].TabVisible := False;

  //now setup the 'format' options
  cmbCompressFormat.Items.Text := uQPCompObj.Compression.SupportedFileExts(cmWrite);

  ChkLstUncompress.Items.Text := uQPCompObj.Compression.SupportedFileExts(cmRead);
  for i := 0 to ChkLstUncompress.Items.Count-1 do
    ChkLstUncompress.Checked[i] := True;

  ChkLstVerify.Items.Text := uQPCompObj.Compression.SupportedFileExts(cmRead);
  for i := 0 to ChkLstVerify.Items.Count-1 do
    ChkLstVerify.Checked[i] := True;

  ChkLstRename.Items.Text := uQPCompObj.Compression.SupportedFileExts(cmRead);
  for i := 0 to ChkLstRename.Items.Count-1 do
    ChkLstRename.Checked[i] := True;
end;

{-----------------------------------------------------------------------------}

procedure TFrmCompressionTools.BtnFilAddClick(Sender: TObject);
begin
  Listfilter.items.Add(inputBox(QP_FOLOPTFRM_FILE_EXT,QP_FOLOPTFRM_FILE_EXT_1,''));
end;

procedure TFrmCompressionTools.BtnFilMinClick(Sender: TObject);
begin
  If ListFilter.Items.Count > 0 then
    Listfilter.Items.Delete(Listfilter.itemindex);
end;

{-----------------------------------------------------------------------------}

procedure TFrmCompressionTools.CmbOperationChange(Sender: TObject);
begin
  pgCompression.ActivePageIndex := CmbOperation.ItemIndex;
end;

{-----------------------------------------------------------------------------}

procedure TFrmCompressionTools.BtnBeginClick(Sender: TObject);
var
  OldCursor : TCursor;
begin
  //only do the actions if a proper directory was specified.
  if DirectoryExists(TxtInput.Text) then
  begin
    if cmbOperation.ItemIndex <> -1 then
    begin

      OldCursor := Screen.Cursor;
      Screen.Cursor := crHourGlass;
      Try
        //reset the progress bar.
        ProgBar.Position := 0;
        //clear the errors log
        MemoErrors.Clear;
        Case CmbOperation.ItemIndex of
          0: Uncompress();
          1: Compress();
          2: Rename();
          3: Verify();
        end;
      finally
        Screen.Cursor := OldCursor;
      end;
    end
    else
      MessageDlg(J_ENTER_ALL_DATA, mtError, [mbOK], 0);

  end
  else
    MessageDlg(J_DIRECTORY_NOT_SPECIFIED, mtError, [mbOK], 0);
end;

procedure TFrmCompressionTools.RadFileToContentClick(Sender: TObject);
var
  i : Integer;
begin
  ChkLstRename.Items.Text := uQPCompObj.Compression.SupportedFileExts(cmRead);
  for i := 0 to ChkLstRename.Items.Count-1 do
    ChkLstRename.Checked[i] := True;
end;

procedure TFrmCompressionTools.RadContentToFileClick(Sender: TObject);
var
  i : Integer;
begin
  ChkLstRename.Items.Text := uQPCompObj.Compression.SupportedFileExts(cmWrite);
  for i := 0 to ChkLstRename.Items.Count-1 do
    ChkLstRename.Checked[i] := True;
end;

procedure TFrmCompressionTools.TxtUncompressOutputBeforeDialog(
  Sender: TObject; var Name: String; var Action: Boolean);
begin
  if DirectoryExists(TxtInput.Text) then
    TjvDirectoryEdit(Sender).InitialDir := TxtInput.Text;
end;

procedure TFrmCompressionTools.ChkVerifyMoveClick(Sender: TObject);
begin
  TxtVerifyOutput.Enabled := ChkVerifyMove.Checked;
end;

end.
