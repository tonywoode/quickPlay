unit fMameMFMPrinter;

interface

uses
  Windows, SysUtils, Classes, Graphics, Controls, Forms, Dialogs, StdCtrls,
  JvBrowseFolder, JvCtrls, fJWinFontForm, JvToolEdit, Mask, JvExMask;

type
  TFrmMameMFMPrinter = class(TJWinFontForm)
    lblMAME: TLabel;
    BtnGo: TButton;
    BtnCancel: TButton;
    TxtMameFileManagerFilePath: TJvFilenameEdit;
    MameFileManagerLabel: TLabel;
    MFMDescLabel: TLabel;
    MFMLabel: TLabel;
    MamePrintDescLabel2: TLabel;
    XMLEdit: TEdit;
    MameXMLLabel: TLabel;
    EditMameEmu: TEdit;
    procedure TxtMameFileManagerFilePathChange(Sender: TObject);
    procedure MFMLabelClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure BtnGoClick(Sender: TObject);

  private
    { Private declarations }
  public
    { Public declarations }
  end;

const
  EmuEmptyMessage = 'No MAME Emulators. Run an E-Find';
  EmuNotSelected =  'Select MAME Emulator in Mame Options';

  implementation

uses fMain, uQPConst, ShellAPI, uQPMiscTypes, ujProcesses;

{$R *.dfm}

procedure TFrmMameMFMPrinter.FormShow(Sender: TObject);
var strList : TStringlist;
begin
  With MainFrm do
  begin
  // If there's no mame emu, distinguish between not having done and efind yet, and not having selected
  //  a mame emu in mame options form. We're using a method intended for comboboxes hence the temp stringlist
    strList := TStringList.Create;
    try
    EmuList.EmusToStrings(strList, cfMameArcade);
    if strList.Count = 0 then
    begin
      EditMameEmu.Text := EmuEmptyMessage;
      EditMameEmu.Color := clInactiveBorder;
      EditMameEmu.Font.Color := clMaroon;
      EditMameEmu.Font.Style := [fsBold];
      EditMameEmu.Font.Size := 10;
      BtnGo.Enabled := false;
    end
    else if Settings.MametoolMameExeName = '' then
    begin
      EditMameEmu.Text := EmuNotSelected;
      EditMameEmu.Color := clInactiveBorder;
      EditMameEmu.Font.Color := clMaroon;
      EditMameEmu.Font.Style := [fsBold];
      EditMameEmu.Font.Size := 10;
      BtnGo.Enabled := false;
    end
    else EditMameEmu.Text := Settings.MametoolMameExeName;
    finally
    strList.Free;
    end;

    //Do we have a loaded Mame Json?
    if TXTMameFileManagerFilePath.Text = '' then BtnGo.Enabled := false;
    
    if (Settings.MameXMLVersion <> '') and FileExists(Settings.MameXMLPath) then
      XMLEdit.Text := 'Loaded: ' + MainFrm.Settings.MameXMLVersion
    else
    begin
      XMLEdit.text := 'Load an XML in Mame Options First';
      EditMameEmu.Font.Color := clMaroon;
      BtnGo.Enabled := false
    end;

    if (Settings.MameXMLVersion = '') or (EditMameEmu.Text = EmuEmptyMessage) or (EditMameEmu.Text = EmuNotSelected) then
      TxtMameFileManagerFilePath.Enabled := False;


    TxtMameFileManagerFilePath.Text := Settings.MameFileManagerFilePath;
  end;

end;

{-----------------------------------------------------------------------------}

procedure TFrmMameMFMPrinter.MFMLabelClick(Sender: TObject);
begin
  ShellExecute(Handle, 'open', PChar(MFMLabel.Caption), '', '', sw_Show);
end;

procedure TFrmMameMFMPrinter.TxtMameFileManagerFilePathChange(Sender: TObject);
begin
 if (BtnGo.Enabled = false) and
    (TXTMameFileManagerFilePath.Text <> '') and
    (MainFrm.Settings.MameXMLVersion <> '') and
    (EditMameEmu.Text <> EmuEmptyMessage) and
    (EditMameEmu.Text <> EmuNotSelected) then
    BtnGo.Enabled := True;
 
end;

{-----------------------------------------------------------------------------}

procedure TFrmMameMFMPrinter.BtnGoClick(Sender: TObject);
var
  Executable, MameExeName, MameExePath : String;
  MameExeIndex: Integer;
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
        Settings.MameFileManagerFilePath := TxtMameFileManagerFilePath.Text;
        Settings.SaveAllSettings();
   end;

   Executable := MainFrm.Settings.Paths.QPNodeFile;
   //we need to know what romdata directory the user is sitting in, and if its not empty that may
   // indicate they don't know it'll get overwritten
   if (MainFrm.RomList.Count > 0) then
     if (MessageDlg(QP_MAMEOPT_ROMS_EXIST_IN_SRC_DIR, mtInformation, [mbYes, mbNo], 0) = mrNo) then Process := False;

    RomdataFolder := MainFrm.GetSelectedFolder;
   //having only the dats root available causes no folder to be passed
   if RomdataFolder = '' then
   begin
   MessageDlg(QP_MAME_NO_ROMDATA_IN_ROOT, mtError, [mbOK], 0);
   process := False;
   end;


   if (Process = True) then
     begin
     //other settings needed will all come from qps settings ini: mamepath, extrasdir, xmlpath, mfm path
     Flags := 'mametool --mfm --output-dir ' + '"' + ExcludeTrailingPathDelimiter(RomdataFolder) + '"';  //folder inclues trailing backslash which literals the quote
     //root the call in the appdir else node gets confused...
     //change the flag of the cmd call to /C for live and /K for dev (halting)
     RunProcess('cmd.exe /C ' + Executable + ' ' + Flags, True, MainFrm.Settings.Paths.AppDir, SW_SHOWNORMAL);
     //hoping we got a good return code, we need to refresh at the very least the roms view, and folders sidebar
     //  why not do this in the return in main? Remember there's a subsequent cancel options if roms are empty, we'd have to capture it
     //the below causes index out of bounds but so does Refresh() from main form generally
     MainFrm.ActRefreshExecute(Sender);
     //I managed to get the first call to an MFM rom not work, so this in an attempt to ensure dir is correct after processing
     setCurrentDir(MainFrm.Settings.Paths.AppDir);
     end;

  //close the form with the modal result OK
  ModalResult := MrOK;
end;

end.


