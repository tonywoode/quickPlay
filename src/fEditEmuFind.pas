{
  This is the editor for the EFind Data files.  Can create new files,
  delete files, or add/edit/delete an entry in the file.  It 'automatically'
  saves all changes when you exit the groupbox containing the text fields.
  Although this may cause problems if you balls up when editing a record,
  as it will be automatically saved - and there is nothign you can do about
  it!  Might implement a 'Reset' button to fix the balls up..
}

unit fEditEmuFind;
                                                         
interface

uses
  Windows, SysUtils, Classes, Controls, Forms, StdCtrls, Dialogs, Contnrs,
  CheckLst, JvExStdCtrls, JvButton, JvCtrls, fJWinFontForm;

type
  TFrmEFindEdit = class(TJWinFontForm)
    LstEmus: TListBox;
    GrpRecord: TGroupBox;
    Label1: TLabel;
    ChkShortExe: TCheckBox;
    ChkVerify: TCheckBox;
    ChkScrSvr: TCheckBox;
    ChkWinKey: TCheckBox;
    TxtName: TEdit;
    TxtEXE: TEdit;
    TxtConfig: TEdit;
    CmbSystem: TComboBox;
    LstFiles: TListBox;
    TxtHomePage: TEdit;
    Label2: TLabel;
    chkCmdLine: TCheckBox;
    ChkShellEx: TCheckBox;
    TxtParam: TEdit;
    ChkWin32: TCheckBox;
    BtnOK: TButton;
    BtnCancel: TButton;
    ChkLstCompress: TCheckListBox;
    lblCompression: TLabel;
    BtnNewINI: TJvImgBtn;
    BtnDelIni: TJvImgBtn;
    BtnAddEmu: TJvImgBtn;
    BtnDeleteEmu: TJvImgBtn;
    procedure FormShow(Sender: TObject);
    procedure BtnDeleteEmuClick(Sender: TObject);
    procedure BtnAddEmuClick(Sender: TObject);
    procedure BtnNewINIClick(Sender: TObject);
    procedure LstFilesClick(Sender: TObject);
    procedure LstEmusClick(Sender: TObject);
    procedure GrpRecordExit(Sender: TObject);
    procedure BtnDelIniClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure BtnOKClick(Sender: TObject);
  private
    { Private declarations }
    IniList : TObjectList;
    CurName, OldName : String;
    procedure DataLoad(Rec : String);
    procedure RecordSetup(OnOff, Clear: Boolean);
    Function IniFileInList(FilePath : TFileName) : Boolean;
  public
    { Public declarations }
  end;

implementation

uses JCLStrings, fMain, uJUtilities, FindFile, IniFiles, uQPConst,
  uJCompression, uJFile, ujMiscResourceStrs, uQPCompObj;

{$R *.dfm}

Function TFrmEFindEdit.IniFileInList(FilePath : TFileName) : Boolean;
var
  i : integer;
begin
  Result := False;
  for i := 0 to IniList.Count-1 do
    if JCLStrings.StrCompare(FilePath, TMemIniFile(IniList[i]).FileName) = 0 then
    begin
      Result := True;
      break;
    end;
end;

Procedure TFrmEFindEdit.RecordSetup(OnOff, Clear : Boolean);
Var
  I : Integer;
Begin

  //Code to disable or enable all the controls in the record box
  For I := 0 to GrpRecord.ControlCount-1 do
    (GrpRecord.Controls[i] as TControl).Enabled := OnOff;

  //Clear Text Code
  If Clear then
  For I := 0 to GrpRecord.ControlCount-1 do
  Begin

    If GrpRecord.Controls[i] is TEdit then
    Begin
      (GrpRecord.Controls[i] as TEdit).Text :='';
       Continue;
    end;

    If GrpRecord.Controls[i] is TCheckBox then
    Begin
      (GrpRecord.Controls[i] as TCheckBox).Checked := False;
      Continue;
    end;

    If GrpRecord.Controls[i] is TComboBox then
    Begin
      (GrpRecord.Controls[i] as TComboBox).ItemIndex := -1;
      Continue;
    end;

    ChkLstCompress.Items.Clear;

  End; //end of FOR loop

End;

{-----------------------------------------------------------------------------}

procedure TFrmEFindEdit.FormCreate(Sender: TObject);
begin
  IniList := TObjectList.Create(True);
  CmbSystem.Items.LoadFromFile(MainFrm.Settings.Paths.SystemsFile);
end;

{-----------------------------------------------------------------------------}

procedure TFrmEFindEdit.FormDestroy(Sender: TObject);
begin
  IniList.Clear;
  FreeAndNil(IniList);
end;

{-----------------------------------------------------------------------------}

procedure TFrmEFindEdit.FormShow(Sender: TObject);
Var
  Find : ThhFindFile;
  I : Integer;
begin
  RecordSetup(False, True);
  Find := ThhFindFile.create(Self);
  Try

    Find.Directory := MainFrm.Settings.Paths.EfindDir;
    find.Filter := '*.ini';
    Find.Sorted := False;
    Find.Execute;

    LstFiles.Items.Clear;
    LstEmus.Items.Clear;
    For I := 0 to Find.TotalFile-1 do
    begin
      IniList.Add(TMemIniFile.Create(Find.Files[i]));
      LstFiles.Items.Add(ChangeFileExt(ExtractFileName(Find.Files[i]),''));
    end;

  Finally
    FreeAndNil(Find);
  end;
end;

{-----------------------------------------------------------------------------}        

procedure TFrmEFindEdit.BtnDeleteEmuClick(Sender: TObject);
Var
  Ini : TMemIniFile;
begin

  If LstEmus.ItemIndex = -1 then Exit;

  if MessageDlg(J_DELETE_REC_VERIFY,
    mtConfirmation, [mbYes, mbNo], 0) = mrYes then
  Begin

    Ini := TMemIniFile(IniList[Lstfiles.ItemIndex]);
    If Ini.SectionExists(LstEmus.Items.Strings[LstEmus.itemIndex]) Then
      Ini.EraseSection(LstEmus.Items.Strings[LstEmus.itemIndex]);

    //reload the listing
    LstEmus.Clear;
    Ini.ReadSections(LstEmus.Items);

  End;  //end of prompt IF

end;

{-----------------------------------------------------------------------------}

procedure TFrmEFindEdit.BtnAddEmuClick(Sender: TObject);
var
  InStrings : TStringList;
  i : Integer;
begin
  If LstFiles.ItemIndex = -1 then
  Begin
    MessageDlg(J_FILE_NOT_SELECTED, mtError, [mbOK], 0);
    Exit;
  End;
  LstEmus.ItemIndex := -1;
  OldName := '';
  RecordSetup(True, True);
  //add compression formats
  InStrings := TStringList.Create;
  try
    InStrings.Text := uQPCompObj.Compression.SupportedFileExts(cmRead);
    for i := 0 to InStrings.Count-1 do
      ChkLstCompress.Items.add(ujFile.GetVirtualFileExtension(InStrings[i]));
  finally
    FreeAndNil(InStrings);
  end;
  TxtName.SetFocus;
end;

{-----------------------------------------------------------------------------}

procedure TFrmEFindEdit.LstFilesClick(Sender: TObject);
begin
  TMemIniFile(IniList[LstFiles.ItemIndex]).ReadSections(LstEmus.Items);
  RecordSetup(false, true);
end;

{-----------------------------------------------------------------------------}

procedure TFrmEFindEdit.DataLoad(Rec: String);
Var
  Ini : TMemIniFile;
  CompStream : TMemoryStream;
  InStrings : TStringList;
  i : Integer;
  CurExt : String;
begin
  Ini := TMemIniFile(IniList[LstFiles.ItemIndex]);

  RecordSetup(true, true);
  TxtName.Text := Rec;
  OldName := TxtName.Text;

  TxtExe.Text := Ini.ReadString(Rec, 'EXE Name', '');
  TxtConfig.Text := Ini.ReadString(Rec, 'Config Name', '');
  CmbSystem.ItemIndex := CmbSystem.Items.IndexOf(Ini.ReadString(Rec, 'System', ''));
  TxtHomePage.Text := Ini.ReadString(Rec, 'HomePage', '');
  TxtParam.Text := Ini.ReadString(Rec, 'param', '');
  ChkWin32.Checked := Ini.ReadBool(Rec, 'isWin32', True);
  ChkCmdLine.Checked := Ini.ReadBool(Rec, 'CmdLine', true);
  ChkShellEx.Checked := Ini.ReadBool(Rec, 'ShellEx', false);
  ChkVerify.Checked := Ini.ReadBool(Rec, 'Verify', false);
  ChkShortExe.Checked := Ini.ReadBool(Rec, 'ShortExe', false);
  ChkWinKey.Checked := Ini.ReadBool(Rec, 'DisWinKey', false);
  ChkScrSvr.Checked := Ini.ReadBool(Rec, 'DisScrSvr', false);

  //load compression support
  CompStream := TMemoryStream.Create;
  try
    //Firstly add in whats currently stored in the Ini File.
    Ini.ReadBinaryStream(Rec, 'Compression', CompStream);
    InStrings := TStringList.Create;
    try
      InStrings.LoadFromStream(CompStream);
      for i := 0 to InStrings.Count-1 do
      begin
        ChkLstCompress.Items.add(trim(InStrings.Names[i]));
        ChkLstCompress.Checked[i] := StrToBool(InStrings.ValueFromIndex[i]);
      end;

      //now add in any new supported formats that arent in the INI file.
      InStrings.Clear;
      InStrings.Text := uQPCompObj.Compression.SupportedFileExts(cmRead);
      for i := 0 to InStrings.Count-1 do
      begin
        CurExt := ujFile.GetVirtualFileExtension(InStrings[i]);
        if ChkLstCompress.Items.IndexOf(CurExt) = -1 then
          ChkLstCompress.Items.add(CurExt);
      end;

    finally
      FreeAndNil(InStrings);
    end;

  finally
    FreeAndNil(CompStream);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmEFindEdit.LstEmusClick(Sender: TObject);
begin
  If LstEmus.ItemIndex = -1 then
    exit;
  DataLoad(LstEmus.Items.Strings[LstEmus.ItemIndex]);
end;

{-----------------------------------------------------------------------------}

procedure TFrmEFindEdit.GrpRecordExit(Sender: TObject);
Var
  Ini : TMemIniFile;
  Reload : Boolean;
  i : Integer;
  OutStrings : TStringList;
  OutStream : TMemoryStream;
begin

  //first thing to do is to validate the data
  If TxtName.Text = '' then
  Begin
    if MessageDlg(QP_EDITEFIND_BAD_NAME,
    mtConfirmation, [mbYes, mbNo], 0) = mrYes then
    TxtName.SetFocus;
    Exit;
  End;
  If TxtExe.Text = '' then
  Begin
    if MessageDlg(QP_EDITEFIND_BAD_EXE,
    mtConfirmation, [mbYes, mbNo], 0) = mrYes then
      Txtexe.SetFocus;
    Exit;
  End;
  if CmbSystem.Text = '' then
  Begin
    if MessageDlg(QP_EDITEFIND_BAD_SYS,
    mtConfirmation, [mbYes, mbNo], 0) = mrYes then
      CmbSystem.SetFocus;
    Exit;
  End;

  CurName := TxtName.Text;
  Reload := False;

  Ini := TMemIniFile(iniList[LstFiles.ItemIndex]);

  If (OldName <> '') AND (OldName <> CurName) then
  Begin
    Ini.EraseSection(OldName);
    Reload := True;
  end;

  If (OldName = '') then
    Reload := True;

  Ini.WriteString(CurName, 'Exe Name',TxtEXE.Text);
  Ini.WriteString(CurName, 'Config Name', TxtConfig.Text);
  Ini.WriteString(CurName, 'System', CmbSystem.Text);
  Ini.WriteString(CurName, 'HomePage', TxtHomePage.Text);
  Ini.WriteString(CurName, 'param', TxtParam.Text);
  Ini.WriteBool(CurName, 'isWin32', ChkWin32.Checked);
  Ini.WriteBool(CurName, 'CmdLine', ChkCmdLine.Checked);
  Ini.WriteBool(CurName, 'ShellEx', ChkShellEx.Checked);
  Ini.WriteBool(CurName, 'Verify', ChkVerify.Checked);
  Ini.WriteBool(CurName, 'ShortExe', ChkShortExe.Checked);
  Ini.WriteBool(CurName, 'DisWinKey', ChkWinKey.Checked);
  Ini.WriteBool(CurName, 'DisScrSvr', ChkScrSvr.Checked);

  OutStream := TMemoryStream.Create;
  try
    OutStrings := TStringList.Create;
    for i := 0 to ChkLstCompress.Count-1 do
      OutStrings.Values[ChkLstCompress.Items[i]] := boolToStr(ChkLstCompress.Checked[i]);
      
    OutStrings.SaveToStream(OutStream);
    OutStream.Position := 0;
    Ini.WriteBinaryStream(CurName, 'Compression', OutStream);
  finally
    FreeAndnil(OutStrings);
    FreeAndNil(OutStream);
  end;

  If Reload then
  Begin
    LstEmus.Clear;
    Ini.ReadSections(LstEmus.Items);
  end;
    
end;

{-----------------------------------------------------------------------------}

procedure TFrmEFindEdit.BtnOKClick(Sender: TObject);
var
  Find : ThhFindFile;
  I : Integer;
begin

  Find := ThhFindFile.create(Self);
  Try

    Find.Directory := MainFrm.Settings.Paths.EfindDir;
    find.Filter := '*.ini';
    Find.Execute;
    For I := Find.TotalFile-1 downto 0 do
    begin
      if not IniFileInList(Find.Files[i]) then
        DeleteFile(Find.Files[i]);  
    end;

    if MainFrm.Settings.AllowWrite then
      For i := 0 to IniList.Count-1 do
        TMemIniFile(IniList[i]).UpdateFile;

  Finally
    FreeAndNil(Find);
  end;
  
end;

{-----------------------------------------------------------------------------}

procedure TFrmEFindEdit.BtnNewINIClick(Sender: TObject);
Var
  Fini : String;
  NewIndex : Integer;
begin

  FIni := InputBox(J_FILE_ENTER_NAME, J_FILE_ENTER_NAME_NO_EXT, '') + '.ini';
  If Fini <> '' then
  Begin
    NewIndex := LstFiles.Items.Add(ChangeFileExt(Fini, ''));
    IniList.Insert(NewIndex, TMemIniFile.Create(MainFrm.Settings.Paths.EfindDir + FIni));
  End;
end;

{-----------------------------------------------------------------------------}

procedure TFrmEFindEdit.BtnDelIniClick(Sender: TObject);
begin
  If LstFiles.ItemIndex = -1 then
    Exit;

  if MessageDlg(J_FILE_VERIFY_DELETE,
    mtConfirmation, [mbYes, mbNo], 0) = mrYes then
  Begin
    IniList.Delete(LstFiles.ItemIndex);
    LstFiles.DeleteSelected;
    LstEmus.Clear;
  End;
end;

end.
