unit fMameOptions;

interface

uses
  Windows, Graphics, SysUtils, StdCtrls, Controls, Classes, fJWinFontForm, JvSelectDirectory, JvBrowseFolder, Dialogs,
  Mask, JvExMask, JvToolEdit;

type
  TFrmMameOptions = class(TJWinFontForm)
    MameOptsOk: TButton;
    BtnCancel: TButton;
    TxtMameExtrasDirPath: TEdit;
    BtnMameExtrasDirFind: TButton;
    ExtrasGroupBox: TGroupBox;
    ExtrasTxtLbl1: TLabel;
    XMLGroupBox: TGroupBox;
    XMLTxtLbl1: TLabel;
    XMLTxtLbl4: TLabel;
    MameXMLLinkLabel: TLabel;
    XMLEdit: TEdit;
    ExtrasTxtLbl2: TLabel;
    XMLTxtLbl13: TLabel;
    BtnXMLScan: TButton;
    CmbMame: TComboBox;
    lblMAME: TLabel;
    MameScanLabel1: TLabel;
    procedure MameXMLLinkLabelClick(Sender: TObject);
    procedure BtnXMLScanClick(Sender: TObject);
    procedure BtnMameExtrasDirFindClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure BtnMameOptsOkClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

const
  StatusNoExtras = 'select Mame Extras dir first';
  StatusNotLoaded = 'not loaded';
  EmuEmptyMessage = 'No MAME Emulators. Run an E-Find';

implementation

uses fMain, uJUtilities, ShellAPI, StrUtils, JCLstrings, uQPMiscTypes, uQPConst, ujProcesses, uEmu;

{$R *.dfm}


procedure TFrmMameOptions.FormShow(Sender: TObject);

begin
  TxtMameExtrasDirPath.Text :=  MainFrm.Settings.MameExtrasDir;
  BtnXMLScan.Enabled := False;
  XMLEdit.Text := StatusNoExtras;
  if (TXTMameExtrasDirPath.GetTextLen > 0) then
  begin
   BtnXMLScan.Enabled := True;
   XMLEdit.Text := StatusNotLoaded;
  if (MainFrm.Settings.MameXMLVersion <> '') and
    FileExists(MainFrm.Settings.MameXMLPath) then
    begin
      XMLEdit.Text := 'Loaded: ' + MainFrm.Settings.MameXMLVersion;
      BtnXMLScan.Caption := 'Choose XML File and Re-Scan'
    end;
  end;

  With MainFrm do
  begin
    EmuList.EmusToStrings(CmbMame.Items, cfMameArcade);
    if CmbMame.Items.Count = 0 then
    begin
      CmbMame.Items.Add(EmuEmptyMessage );
      CmbMame.ItemIndex := CmbMame.Items.IndexOf(EmuEmptyMessage );
      CmbMame.Color := clInactiveBorder;
      CmbMame.Font.Color := clMaroon;
      CmbMame.Font.Style := [fsBold];
      CmbMame.Font.Size := 10;
      MameOptsOK.Enabled := false
    end
    else CmbMame.ItemIndex := CmbMame.Items.IndexOf(Settings.MametoolMameExeName);
   end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMameOptions.BtnMameExtrasDirFindClick(Sender: TObject);
var
  jvBrowse: TJvBrowseForFolderDialog;
begin
  jvBrowse := TJvBrowseForFolderDialog.Create(self);

  try

   if DirectoryExists(MainFrm.Settings.MameExtrasDir) then
      jvBrowse.Directory := MainFrm.Settings.MameExtrasDir;
      if (jvBrowse.execute) then
        begin
         if DirectoryExists(jvBrowse.Directory + '/folders/') and
            DirectoryExists(jvBrowse.Directory + '/dats/')    and
            DirectoryExists(jvBrowse.Directory + '/icons/')   then
            begin
             TxtMameExtrasDirPath.Text := jvBrowse.Directory;
              MainFrm.Settings.MameExtrasDir := TxtMameExtrasDirPath.Text
            end
         else
             MessageDlg(QP_MAMEOPT_BAD_DIR, mtError, [mbOK], 0);
             BtnXMLScan.Enabled := True;
             if (XMLEdit.Text = StatusNoExtras) then XMLEdit.Text := StatusNotLoaded;
         end;
  finally
    FreeAndNil(jvBrowse);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMameOptions.BtnXMLScanClick(Sender: TObject);
var
  selectedFile, Executable, Flags, MameExeName, MameExeFileName: string;
  MameExeIndex: Integer;

  dlg: TOpenDialog;
begin
  selectedFile := '';
  dlg := TOpenDialog.Create(nil);
  try
    dlg.InitialDir := MainFrm.Settings.MameXMLPath;
    dlg.Filter := 'XML files (*.xml)|*.XML';
    if dlg.Execute(Handle) then
      selectedFile := dlg.FileName;
  finally
     dlg.Free;
  end;

  if (selectedFile <> '') and (CmbMame.ItemIndex <>-1) then
  begin
     With MainFrm do
     begin
       //we need to get the executable name of the emulator selected in the dropdown, and then save it
       MameExeName := CmbMame.Items.Strings[CmbMame.ItemIndex];
       Settings.MametoolMameExeName := MameExeName;
       MameExeIndex := EmuList.IndexOfName(MameExeName);
       MameExeFileName := ExtractFileName(EmuList.GetItemByIndex(MameExeIndex).ExePath);
       Settings.MameToolMameExeFileName := MameExeFileName;

       Settings.MameXMLPath := selectedFile;
       Settings.SaveAllSettings(); //else how else will node read what you just did

       Flags := '--scan';
       //root the call in the appdir else node gets confused...
       Executable := Settings.Paths.QPNodeFile;
       RunProcess('cmd.exe /K ' +  Executable + ' ' + Flags, True, Settings.Paths.AppDir, SW_SHOWNORMAL);
       //node should write the mamexml version into the settings now,  so we need to reload the settings from disk
       Settings.LoadIni();
       if (Settings.MameXMLVersion <> '') then
       begin
         XMLEdit.Text := Settings.MameXMLVersion;
         MessageDlg('After a successful MAME XML scan, you should run a new EFind to pick up new MAME/RetroArch-Mame Home-Computer and Console Emulators', mtInformation, [mbOK], 0);
       end;
     end;
  end;
end;
{-----------------------------------------------------------------------------}

procedure TFrmMameOptions.BtnMameOptsOkClick(Sender: TObject);
begin
  MainFrm.Settings.MameExtrasDir := TxtMameExtrasDirPath.Text;
  MainFrm.Settings.SaveAllSettings();
  //close the form with the modal result OK
  ModalResult := MrOK;

  //we want to refresh: sidebar icons, mame icons, info files will all now show up...
  //why not do it in the caller in the main form? just to be consistent with the other mame dialog boxes
   MainFrm.ActRefreshExecute(Sender);
end;

{-----------------------------------------------------------------------------}
  procedure TFrmMameOptions.MameXMLLinkLabelClick(Sender: TObject);
begin
  ShellExecute(Handle, 'open', PChar(MameXMLLinkLabel.Caption), '', '', sw_Show);
end;


end.

