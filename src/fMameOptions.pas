unit fMameOptions;

interface

uses
  Windows, SysUtils, StdCtrls, Controls, Classes, fJWinFontForm, JvSelectDirectory, JvBrowseFolder, Dialogs,
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

implementation

uses fMain, uJUtilities, ShellAPI, StrUtils, JCLstrings, uQPConst, ujProcesses;

{$R *.dfm}


procedure TFrmMameOptions.FormShow(Sender: TObject);

begin
  TxtMameExtrasDirPath.Text :=  MainFrm.Settings.MameExtrasDir;
  BtnXMLScan.Enabled := False;
  XMLEdit.Text := StatusNoExtras;
  if (TXTMameExtrasDirPath.GetTextLen > 0) then
  begin
   BtnXMLScan.Enabled := True;
   XMLEdit.Text := StatusNotLoaded
  end;
  if (MainFrm.Settings.MameXMLVersion <> '') and FileExists(MainFrm.Settings.MameXMLPath) then
    XMLEdit.Text := 'Loaded: ' + MainFrm.Settings.MameXMLVersion
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
      if (jvBrowse.execute) and (DirectoryExists(jvBrowse.Directory)) then
        begin
         if DirectoryExists(jvBrowse.Directory + '/folders/') and
            DirectoryExists(jvBrowse.Directory + '/dats/')    and
            DirectoryExists(jvBrowse.Directory + '/icons/')   then
             TxtMameExtrasDirPath.Text := jvBrowse.Directory

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
  selectedFile, Executable, Flags: string;
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

  if selectedFile <> '' then
     Flags := '--scan';
     //root the call in the appdir else node gets confused...
     Executable := MainFrm.Settings.Paths.QPNodeFile;
     RunProcess('cmd.exe /K ' + Executable + ' ' + Flags, True, MainFrm.Settings.Paths.AppDir, SW_SHOWNORMAL);
     MainFrm.Settings.MameXMLPath := selectedFile;
     XMLEdit.Text := MainFrm.Settings.MameXMLVersion;
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

