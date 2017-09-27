unit fMameMFMPrinter;

interface

uses
  Windows, SysUtils, Classes, Graphics, Controls, Forms, Dialogs, StdCtrls,
  JvBrowseFolder, JvCtrls, fJWinFontForm, JvToolEdit, Mask, JvExMask;

type
  TFrmMameMFMPrinter = class(TJWinFontForm)
    CmbMame: TComboBox;
    lblMAME: TLabel;
    BtnOK: TButton;
    BtnCancel: TButton;
    MameExtrasLabel: TLabel;
    TxtMameExtrasDirPath: TEdit;
    BtnMameExtrasDirFind: TButton;
    TxtMAMEXMLFilePath: TJvFilenameEdit;
    TxtMameFileManagerFilePath: TJvFilenameEdit;
    MameFileManagerLabel: TLabel;
    MFMDescLabel: TLabel;
    MFMLabel: TLabel;
    MameXMLLinkLabel: TLabel;
    Label2: TLabel;
    MamePrintDescLabel2: TLabel;
    procedure MameXMLLinkLabelClick(Sender: TObject);
    procedure MFMLabelClick(Sender: TObject);
    procedure BtnMameExtrasDirFindClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure BtnOKClick(Sender: TObject);

  private
    { Private declarations }
  public
    { Public declarations }
  end;

implementation

uses fMain, uQPConst, ShellAPI, uQPMiscTypes, ujProcesses;

{$R *.dfm}

procedure TFrmMameMFMPrinter.FormShow(Sender: TObject);
begin

  With MainFrm do
  begin
    EmuList.EmusToStrings(CmbMame.Items, cfMameArcade);
    CmbMame.ItemIndex := CmbMame.Items.IndexOf(Settings.MametoolMameExePath);

    TxtMameExtrasDirPath.Text :=  Settings.MameExtrasDir;
    //Path to Mame XML - why don't we query the mame executatble for the xml? because
    // retroarch MAME doesn't have this ability....
    TxtMAMEXMLFilePath.Text := Settings.MameXMLPath;
    TxtMameFileManagerFilePath.Text := Settings.MameFileManagerFilePath;
  end;

end;

{-----------------------------------------------------------------------------}

procedure TFrmMameMFMPrinter.MameXMLLinkLabelClick(Sender: TObject);
begin
  ShellExecute(Handle, 'open', PChar(MameXMLLinkLabel.Caption), '', '', sw_Show);
end;

{-----------------------------------------------------------------------------}

procedure TFrmMameMFMPrinter.MFMLabelClick(Sender: TObject);
begin
  ShellExecute(Handle, 'open', PChar(MFMLabel.Caption), '', '', sw_Show);
end;

{-----------------------------------------------------------------------------}

procedure TFrmMameMFMPrinter.BtnMameExtrasDirFindClick(Sender: TObject);
var
  jvBrowse: TJvBrowseForFolderDialog;
begin
  jvBrowse := TJvBrowseForFolderDialog.Create(self);

  try

   if DirectoryExists(MainFrm.Settings.MameExtrasDir) then
      jvBrowse.Directory := MainFrm.Settings.MameExtrasDir;
      if (jvBrowse.execute) and (DirectoryExists(jvBrowse.Directory)) then
        begin
         if DirectoryExists(jvBrowse.Directory + '/icons/') then
             TxtMameExtrasDirPath.Text := jvBrowse.Directory
           else
             MessageDlg(QP_MAMEOPT_BAD_DIR, mtError, [mbOK], 0);
         end;
  finally
    FreeAndNil(jvBrowse);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMameMFMPrinter.BtnOKClick(Sender: TObject);
var
  Executable: String;
  RomdataFolder: String;
  MameExecutablePath: String;
  MameExtrasDir: String;
  MameXMLPath: String;
  MameFileManagerFilePath: String;
  Flags: String;
  Process: Boolean;

begin
   Process := True;
   With MainFrm do
   begin
     if CmbMame.ItemIndex <>-1 then
        Settings.MametoolMameExePath := CmbMame.Items.Strings[CmbMame.ItemIndex];
        Settings.MameExtrasDir := TxtMameExtrasDirPath.Text;
        Settings.MameXMLPath := TxtMAMEXMLFilePath.Text;
        Settings.MameFileManagerFilePath := TxtMameFileManagerFilePath.Text;
        Settings.SaveAllSettings();
   end;

   Executable := MainFrm.Settings.Paths.QPNodeFile;
   //we need to know what romdata directory the user is sitting in, and if its not empty that may
   // indicate they don't know it'll get overwritten
   if (MainFrm.RomList.Count > 0) then
     if (MessageDlg(QP_MAMEOPT_ROMS_EXIST_IN_SRC_DIR, mtInformation, [mbYes, mbNo], 0) = mrNo) then Process := False;

   if (Process = True) then
     begin
     //RomdataFolder := '"' + MainFrm.GetSelectedFolder + '"';
     RomdataFolder := MainFrm.GetSelectedFolder;
     //other settings needed will all come from qps settings ini: mamepath, extrasdir, xmlpath, mfm path
     Flags := '--mfm --output-dir ' + '"' + ExcludeTrailingPathDelimiter(RomdataFolder) + '"';  //folder inclues trailing backslash which literals the quote
     RunProcess('cmd.exe /K ' + Executable + ' ' + Flags, True, MainFrm.Settings.Paths.AppDir, SW_SHOWNORMAL);
     //RunProcess('cmd.exe /K ' + Executable, True, '', SW_SHOWMINIMIZED);
     //hoping we got a good return code, we need to refresh at the very least the roms view, and folders sidebar
     //  why not do this in the return in main? Remember there's a subsequent cancel options if roms are empty, we'd have to capture it
     //the below causes index out of bounds but so does Refresh() from main form generally
     MainFrm.ActRefreshExecute(Sender);
     end;

  //close the form with the modal result OK
  ModalResult := MrOK;
end;

end.


