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
    TxtMameFileManagerFilePath: TJvFilenameEdit;
    MameFileManagerLabel: TLabel;
    MFMDescLabel: TLabel;
    MFMLabel: TLabel;
    MamePrintDescLabel2: TLabel;
    XMLEdit: TEdit;
    MameXMLLabel: TLabel;
    procedure MFMLabelClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure BtnOKClick(Sender: TObject);

  private
    { Private declarations }
  public
    { Public declarations }
  end;

const
  EmuEmptyMessage = 'No MAME Emulators. Run an E-Find';

  implementation

uses fMain, uQPConst, ShellAPI, uQPMiscTypes, ujProcesses;

{$R *.dfm}

procedure TFrmMameMFMPrinter.FormShow(Sender: TObject);
begin

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
      BtnOK.Enabled := false
    end
    else CmbMame.ItemIndex := CmbMame.Items.IndexOf(Settings.MametoolMameExePath);

    //Do we have a loaded Mame Json?
    if (Settings.MameXMLVersion <> '') and FileExists(Settings.Paths.CfgDir + 'mame.json') then
    XMLEdit.Text := 'Loaded: ' + MainFrm.Settings.MameXMLVersion
    else
    begin
      XMLEdit.text := 'Use Mame Options to load Mame XML First';
      BtnOK.Enabled := false
    end;

    TxtMameFileManagerFilePath.Text := Settings.MameFileManagerFilePath;
  end;

end;

{-----------------------------------------------------------------------------}

procedure TFrmMameMFMPrinter.MFMLabelClick(Sender: TObject);
begin
  ShellExecute(Handle, 'open', PChar(MFMLabel.Caption), '', '', sw_Show);
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
     RomdataFolder := MainFrm.GetSelectedFolder;
     //other settings needed will all come from qps settings ini: mamepath, extrasdir, xmlpath, mfm path
     Flags := '--mfm --output-dir ' + '"' + ExcludeTrailingPathDelimiter(RomdataFolder) + '"';  //folder inclues trailing backslash which literals the quote
     //root the call in the appdir else node gets confused...
     RunProcess('cmd.exe /K ' + Executable + ' ' + Flags, True, MainFrm.Settings.Paths.AppDir, SW_SHOWNORMAL);
     //hoping we got a good return code, we need to refresh at the very least the roms view, and folders sidebar
     //  why not do this in the return in main? Remember there's a subsequent cancel options if roms are empty, we'd have to capture it
     //the below causes index out of bounds but so does Refresh() from main form generally
     MainFrm.ActRefreshExecute(Sender);
     end;

  //close the form with the modal result OK
  ModalResult := MrOK;
end;

end.


