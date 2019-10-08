unit fMameMessPrinter;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ShellAPI;

type
  TFrmMameMessPrinter = class(TForm)
    BtnGo: TButton;
    BtnCancel: TButton;
    MameMessPrinterDescLabel1: TLabel;
    MameMessPrinterDescLabel2: TLabel;
    lblMAME: TLabel;
    CmbMame: TComboBox;
    MameMessPrinterDescLabel3: TLabel;
    XMLTxtLbl: TLabel;
    XMLEdit: TEdit;
    procedure FormShow(Sender: TObject);
    procedure BtnGoClick(Sender: TObject);
  private
    MameType : String;
  public
    { Public declarations }
  end;

  const
  EmuEmptyMessage = 'No MAME Emulators. Run an E-Find';

implementation

uses fMain, uJFile, uQPConst, uQPMiscTypes,ujProcesses, strUtils;

{$R *.dfm}



procedure TFrmMameMessPrinter.FormShow(Sender: TObject);
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
      BtnGo.Enabled := false
    end
    else CmbMame.ItemIndex := CmbMame.Items.IndexOf(Settings.MametoolMameExeName);

    //Do we have a loaded Mame Json?
    if (Settings.MameXMLVersion <> '') and FileExists(Settings.MameXMLPath) then
      XMLEdit.Text := 'Loaded: ' + MainFrm.Settings.MameXMLVersion
    else
    begin
      XMLEdit.text := 'Load an XML in Mame Options First';
      BtnGo.Enabled := false
    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMameMessPrinter.BtnGoClick(Sender: TObject);
var
 RomdataFolder, binDir, softlistRootDirPath, MameExeName : String;
 MameExePath, Flags, Executable, softlistFolderName : String;
 MameExeIndex : Integer;
 Process: Boolean;

begin
  Process := True;

  //for the other Mame Printers, we check whether the folder the user chose was empty
  // but the root of the romdatas is a folder not a romdata.dat, so it won't overwrite anything but an existing set
  //instead, if the selected dir is one in from the root, check the user wants this in root (which is likely)
  if (MainFrm.VTDir.GetNodeLevel(MainFrm.VTDir.FocusedNode) = 0) and
    (MessageDlg(QP_MAINFRM_NEWFOL, mtConfirmation, [mbYes, mbNo], 0) = mrYes) then
    RomdataFolder := MainFrm.Settings.Paths.ROMsDir
  else
    RomdataFolder := MainFrm.GetSelectedFolder;
  //todo: if user cancels out of that dialog at this point, they're going to get the copy into the selected roms folder

  //if the folder exists, check that's the intention
  //take a bit of care here as the logic that follows expects these names to be folder names of SUBFOLDERS in the src, so
 //both src and dest folders must be the same name
 //nah since we lost mame type this no longer works
 if AnsiContainsText(CmbMame.Items.Strings[CmbMame.ItemIndex], 'RetroArch')
   then softlistFolderName := 'RetroArch Softlists' else softlistFolderName := 'MAME Softlists';
   if (DirectoryExists(RomdataFolder + '\' + softlistFolderName)) and
     (MessageDlg(QP_MAME_SOFTLISTS_EXIST_IN_SRC_DIR, mtConfirmation, [mbYes, mbNo], 0) = mrNo) then Process := False;

  //check that Dir is actually equal to something!
  if RomdataFolder = '' then Process := False;

  if (Process = True) then
   begin

     With MainFrm do
     begin
       if CmbMame.ItemIndex <>-1 then
          Settings.MametoolMameExeName := CmbMame.Items.Strings[CmbMame.ItemIndex];
          //To be consistent with the mame options mame exe, we don't need the filename of the mame exe here, but if
          // we don't save it, the settings will end up inconsistent, and we need to save it in the mame options because mametool needs to read it
          MameExeName := CmbMame.Items.Strings[CmbMame.ItemIndex];
          Settings.MametoolMameExeName := MameExeName;
          MameExeIndex := EmuList.IndexOfName(MameExeName);
          MameExePath := EmuList.GetItemByIndex(MameExeIndex).ExePath;
          Settings.MameToolMameExePath := MameExePath;

          Settings.SaveAllSettings();
     end;

     Executable := MainFrm.Settings.Paths.QPNodeFile;
     //other settings needed will all come from qps settings ini: mamepath, extrasdir, xmlpath, mfm path
     Flags := 'mametool --softlists --output-dir ' + '"' + ExcludeTrailingPathDelimiter(RomdataFolder) + '"';  //folder inclues trailing backslash which literals the quote
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
