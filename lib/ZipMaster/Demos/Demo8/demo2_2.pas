unit demo2_2;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls, ZipSFXPlus, SFXInterface, Buttons, FileCtrl,
  ZipSFXBase;//, DZUtils;

type
  TdlgConvertToSFX = class(TForm)
    Panel1: TPanel;
    Button1: TButton;
    lbHeader: TLabel;
    btnPrev: TButton;
    btnNext: TButton;
    Panel2: TPanel;
    Notebook1: TNotebook;
    dlgOpenZip: TOpenDialog;
    dlgSaveSFX: TSaveDialog;
    ZipSFX1: TZipSFXPlus;
    dlgOpenSettings: TOpenDialog;
    rgOverwriteMode: TRadioGroup;
    GroupBox1: TGroupBox;
    cbAskCmdLine: TCheckBox;
    cbAskFiles: TCheckBox;
    cbHideOverwriteBox: TCheckBox;
    cbAutorun: TCheckBox;
    cbNoSuccessMsg: TCheckBox;
    cbExpandVariables: TCheckBox;
    cbInitiallyHideFiles: TCheckBox;
    cbForceHideFiles: TCheckBox;
    cbCanBeCancelled: TCheckBox;
    cbCheckAutoRunFileName: TCheckBox;
    GroupBox2: TGroupBox;
    imgIcon: TImage;
    btnSelectIcon: TButton;
    GroupBox3: TGroupBox;
    edTitle: TEdit;
    GroupBox4: TGroupBox;
    Label4: TLabel;
    edMessage: TEdit;
    Label3: TLabel;
    cbMessageFlags: TComboBox;
    lbDefaultIcon: TLabel;
    btnUseDefaultIcon: TButton;
    GroupBox5: TGroupBox;
    Label1: TLabel;
    edSource: TEdit;
    btnSource: TButton;
    Label2: TLabel;
    edTarget: TEdit;
    btnTarget: TButton;
    GroupBox6: TGroupBox;
    cbDefPath: TComboBox;
    btnLoadSettings: TSpeedButton;
    btnStoreSettings: TSpeedButton;
    dlgSaveSettings: TSaveDialog;
    Label5: TLabel;
    edFailPath: TEdit;
    btnSelPath1: TButton;
    btnSelPath2: TButton;
    GroupBox7: TGroupBox;
    edCommandline: TEdit;
    btnFinish: TButton;
    GroupBox8: TGroupBox;
    cbLanguages: TComboBox;
    cbDetached: TCheckBox;
    procedure Button1Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure Notebook1PageChanged(Sender: TObject);
    procedure btnSourceClick(Sender: TObject);
    procedure btnTargetClick(Sender: TObject);
    procedure btnNextClick(Sender: TObject);
    procedure btnPrevClick(Sender: TObject);
    procedure btnLoadSettingsClick(Sender: TObject);
    procedure btnSelectIconClick(Sender: TObject);
    procedure btnUseDefaultIconClick(Sender: TObject);
    procedure btnStoreSettingsClick(Sender: TObject);
    procedure btnSelPath1Click(Sender: TObject);
    procedure btnSelPath2Click(Sender: TObject);
    procedure btnFinishClick(Sender: TObject);
  private
    { Private-Deklarationen }
    FIconIndex: Integer;
    FIconEXE: string;
    FMakeNew : Boolean;
    procedure GotoPage(const iPage: Integer);
    procedure SetZipSFXFromControls;
    procedure SetControlsFromZipSFX;
    procedure Finish;
  public
    { Public-Deklarationen }
    procedure PrepareMakeNew;
  end;

var
  dlgConvertToSFX: TdlgConvertToSFX;

implementation

{$I DELVER.INC}

uses ShellAPI, demo2_1;

{$R *.dfm}

procedure TdlgConvertToSFX.Button1Click(Sender: TObject);
begin
  Close;
end;

procedure TdlgConvertToSFX.FormCreate(Sender: TObject);
begin
  // Enumerate all compiled languages
  cbLanguages.Items.Text := TZipSFXPlus.GetSupportedSFXLanguages;

  FMakeNew := False;
  SetControlsFromZipSFX;
  GotoPage(0);
end;

procedure TdlgConvertToSFX.GotoPage(const iPage: Integer);
begin
  if NoteBook1.PageIndex = iPage
  then
    Notebook1PageChanged(NoteBook1)
  else
    NoteBook1.PageIndex := iPage;

  lbHeader.Caption := '  '+NoteBook1.ActivePage;
  btnPrev.Enabled := NoteBook1.PageIndex > 0;
  if (NoteBook1.PageIndex < Pred(NoteBook1.Pages.Count))
  then
    btnNext.Caption := '&Next >>'
  else
    btnNext.Caption := '&Finish';
end;

procedure TdlgConvertToSFX.Notebook1PageChanged(Sender: TObject);
begin
  case NoteBook1.PageIndex of
    0:
    begin
      btnNext.Enabled := (FMakeNew or (edSource.Text <> '')) and (edTarget.Text <> '');
      btnFinish.Enabled := btnNext.Enabled;
    end;
  end;
end;

procedure TdlgConvertToSFX.btnSourceClick(Sender: TObject);
begin
  with dlgOpenZip do
  begin
    if FileExists(edSource.Text)
    then
      FileName := edSource.Text;
    if Execute
    then
      edSource.Text := FileName;
  end;
end;

procedure TdlgConvertToSFX.btnTargetClick(Sender: TObject);
begin
  with dlgSaveSFX do
  begin
    if FileExists(edSource.Text) and (edTarget.Text = '')
    then
      FileName := ChangeFileExt(edSource.Text, '.exe')
    else
      if edTarget.Text <> ''
      then
        FileName := edTarget.Text;

    if Execute
    then
      edTarget.Text := FileName;
  end;

end;

procedure TdlgConvertToSFX.btnNextClick(Sender: TObject);
begin
  if Notebook1.PageIndex = Pred(NoteBook1.Pages.Count)
  then
    Finish
  else
    GotoPage(NoteBook1.PageIndex +1);
end;

procedure TdlgConvertToSFX.btnPrevClick(Sender: TObject);
begin
  GotoPage(NoteBook1.PageIndex -1);
end;

procedure TdlgConvertToSFX.btnLoadSettingsClick(Sender: TObject);
begin
  with dlgOpenSettings
  do
    if Execute then
    begin
      SetZipSFXFromControls;
      try
        ZipSFX1.LoadFromFile(FileName);
      finally
        SetControlsFromZipSFX;
      end;
    end;
end;

procedure TdlgConvertToSFX.SetControlsFromZipSFX;
begin
  with ZipSFX1 do
  begin
    edSource.Text := SourceFile;
    edTarget.Text := TargetFile;

    rgOverwriteMode.ItemIndex := Integer(OverwriteMode);

    cbAskCmdLine.Checked := soAskCmdLine in Options;
    cbAskFiles.Checked := soAskFiles in Options;
    cbHideOverWriteBox.Checked := soHideOverWriteBox in Options;
    cbAutoRun.Checked := soAutoRun in Options;
    cbNoSuccessMsg.Checked := soNoSuccessMsg in Options;
    cbExpandVariables.Checked := soExpandVariables in Options;
    cbInitiallyHideFiles.Checked := soInitiallyHideFiles in Options;
    cbForceHideFiles.Checked := soForceHideFiles in Options;
    cbCheckAutoRunFileName.Checked := soCheckAutoRunFileName in Options;
    cbDetached.Checked := soDetached in Options;
    cbCanBeCancelled.Checked := soCanBeCancelled in Options;

    imgIcon.Picture.Icon.Assign(Icon);
    lbDefaultIcon.Visible := imgIcon.Picture.Icon.Empty;
    btnUseDefaultIcon.Enabled := not lbDefaultIcon.Visible;

    edTitle.Text := DialogTitle;
    cbDefPath.Text := DefaultExtractPath;
    edFailPath.Text := FallbackExtractPath;
    edCommandline.Text := CommandLine;

    // show language
    cbLanguages.Text := SFXLanguage;

    edMessage.Text := Message;
    case MessageFlags of
      MB_OK: cbMessageFlags.ItemIndex := 0;
      MB_ICONINFORMATION or MB_OKCANCEL: cbMessageFlags.ItemIndex := 2;
      MB_ICONQUESTION or MB_YESNO: cbMessageFlags.ItemIndex := 1;
    else
      cbMessageFlags.Text := IntToStr(MessageFlags);
    end;
  end;
end;

procedure TdlgConvertToSFX.SetZipSFXFromControls;
var
  FOpts: TSFXOptions;
begin
  with ZipSFX1 do
  begin
    SourceFile := edSource.Text;
    TargetFile := edTarget.Text;

    OverwriteMode := TSFXOverwriteMode(rgOverwriteMode.ItemIndex);

    FOpts := [];
    if cbAskCmdLine.Checked then Include(FOpts,  soAskCmdLine);
    if cbAskFiles.Checked then Include(FOpts,  soAskFiles);
    if cbHideOverWriteBox.Checked then Include(FOpts,  soHideOverWriteBox);
    if cbAutoRun.Checked then Include(FOpts,  soAutoRun);
    if cbNoSuccessMsg.Checked then Include(FOpts,  soNoSuccessMsg);
    if cbExpandVariables.Checked then Include(FOpts,  soExpandVariables);
    if cbInitiallyHideFiles.Checked then Include(FOpts,  soInitiallyHideFiles);
    if cbForceHideFiles.Checked then Include(FOpts,  soForceHideFiles);
    if cbCheckAutoRunFileName.Checked then Include(FOpts,  soCheckAutoRunFileName);
    if cbDetached.Checked then Include(FOpts, soDetached);
    if cbCanBeCancelled.Checked then Include(FOpts,  soCanBeCancelled);
    Options := FOpts;

    Icon.Assign(imgIcon.Picture.Icon);

    DialogTitle := edTitle.Text;
    DefaultExtractPath := cbDefPath.Text;
    FallbackExtractPath := edFailPath.Text;
    CommandLine := edCommandline.Text;

    // set language
    SFXLanguage := cbLanguages.Text;

    Message := edMessage.Text;
    case cbMessageFlags.Items.IndexOf(cbMessageFlags.Text) of
      0: MessageFlags := MB_OK;
      1: MessageFlags := MB_ICONQUESTION or MB_YESNO;
      2: MessageFlags := MB_ICONINFORMATION or MB_OKCANCEL;
    else
      try
        MessageFlags := {$IFDEF DELPHI4UP}StrToInt64{$ELSE}StrToInt{$ENDIF}(cbMessageFlags.Text);
      except
        GoToPage(2);
        cbMessageFlags.SetFocus;
        raise;
      end;
    end;
  end;
end;

procedure TdlgConvertToSFX.btnSelectIconClick(Sender: TObject);
var
  hIco: HICON;
begin
  if PickIcon(Handle, FIconExe, FIconIndex) then
  begin
    hIco := ExtractIcon(HInstance, PChar(FIconExe), FIconIndex);
    if hIco < 2
    then
      {$IFDEF DELPHI4UP}
      RaiseLastWin32Error
      {$ELSE}
      Raise Exception.Create(SysErrorMessage(GetLastError))
      {$ENDIF}
    else
    begin
      imgIcon.Picture.Icon.Handle := hIco;
      lbDefaultIcon.Visible := False;
      btnUseDefaultIcon.Enabled := not lbDefaultIcon.Visible
    end;
  end;
end;

procedure TdlgConvertToSFX.btnUseDefaultIconClick(Sender: TObject);
begin
  imgIcon.Picture.Bitmap.FreeImage;
  imgIcon.Picture.Icon.ReleaseHandle;
  lbDefaultIcon.Visible := True;
  btnUseDefaultIcon.Enabled := not lbDefaultIcon.Visible
end;

procedure TdlgConvertToSFX.btnStoreSettingsClick(Sender: TObject);
begin
  with dlgSaveSettings
  do
    if Execute then
    begin
      SetZipSFXFromControls;
      ZipSFX1.SaveToFile(FileName);
    end;
end;

procedure TdlgConvertToSFX.btnSelPath1Click(Sender: TObject);
var
  s: string;
begin
  s := cbDefPath.Text;
  {$IFDEF DELPHI4UP}
  if SelectDirectory('Select default extraction path','',s)
  {$ELSE}
  if SelectDirectory(s,[],0)
  {$ENDIF}
  then
    cbDefPath.Text := s;
end;

procedure TdlgConvertToSFX.btnSelPath2Click(Sender: TObject);
var
  s: string;
begin
  s := edFailPath.Text;
  {$IFDEF DELPHI4UP}
  if SelectDirectory('Select default fallback extraction path','',s)
  {$ELSE}
  if SelectDirectory(s,[],0)
  {$ENDIF}
  then
    edFailPath.Text := s;
end;

procedure TdlgConvertToSFX.btnFinishClick(Sender: TObject);
begin
  Finish;
end;

procedure TdlgConvertToSFX.Finish;
begin
  SetZipSFXFromControls;
  ZipSFX1.StartWaitCursor;
  try
    if not FMakeNew
    then
      ZipSFX1.ConvertToSFX
    else
      ZipSFX1.CreateNewSFX;
  finally
    ZipSFX1.StopWaitCursor;
  end;

  if MessageDlg('Self extracting archive '+ZipSFX1.TargetFile+#13#10+
    'has been created. Do you want to test it?', mtConfirmation, [mbYes, mbNo], 0) = mrYes
  then
    if WinExec(PChar(ZipSFX1.TargetFile) , SW_SHOW) < 32
    then
      {$IFDEF DELPHI4UP}
      RaiseLastWin32Error;
      {$ELSE}
      Raise Exception.Create(SysErrorMessage(GetLastError));
      {$ENDIF}

  Close; 
end;

procedure TdlgConvertToSFX.PrepareMakeNew;
begin
  Caption := 'Create an empty .EXE SFX';
  FMakeNew := True;
  edTarget.Left := edSource.Left;
  Label2.Left := Label1.Left;
  btnTarget.Left := btnSource.Left;
  edSource.Hide;
  Label1.Hide;
  btnSource.Hide;
end;

end.
