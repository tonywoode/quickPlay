unit fMameOptions;

interface

uses
  Windows, Graphics, SysUtils, StdCtrls, Controls, Classes, fJWinFontForm, JvSelectDirectory, JvBrowseFolder, Dialogs,
  Mask, JvExMask, JvToolEdit, ComCtrls;

type
  TStringArray = array of string;
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
    XMLTxtLbl14: TLabel;
    ChkBoxMameFilePaths: TCheckBox;
    LblMameFiletypeExplain: TLabel;
    LblMameRomsTypeExplain: TLabel;
    RadMameFileZip: TRadioButton;
    RadMameFile7z: TRadioButton;
    RadMameMergeMerged: TRadioButton;
    RadMameMergeNonMerged: TRadioButton;
    GBoxGroupFiletype: TGroupBox;
    GBoxMergeType: TGroupBox;
    FilePrintOptions: TPageControl;
    TabFilepath: TTabSheet;
    TabRomtype: TTabSheet;
    MameFilePathGroupBox: TGroupBox;
    RomPathDescLbl: TLabel;
    RomsPathTypeLbl: TLabel;
    CmbRomsPath: TComboBox;
    CmbChdsPath: TComboBox;
    ChdsPathTypeLbl: TLabel;
    SoftlistRomsPathTypeLbl: TLabel;
    CmbSoftlistRomsPath: TComboBox;
    CmbSoftlistChdsPath: TComboBox;
    SoftlistChdsPathTypeLbl: TLabel;
    RomPathLbl: TLabel;
    RomPathEdit: TEdit;
    procedure CmbMameSelect(Sender: TObject);
    procedure MameXMLLinkLabelClick(Sender: TObject);
    procedure BtnXMLScanClick(Sender: TObject);
    procedure BtnMameExtrasDirFindClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure BtnMameOptsOkClick(Sender: TObject);
    function  checkExtrasDir(const directory:String):boolean;
    function  getRompath(const directory:String): TStringArray;

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

function TFrmMameOptions.checkExtrasDir(const directory:String):boolean;
begin
    if 
       DirectoryExists(directory + '/folders/') and
       DirectoryExists(directory + '/dats/')    and
       DirectoryExists(directory + '/icons/')   then
    Result:=true
    else
    Result:=false
end;

procedure TFrmMameOptions.CmbMameSelect(Sender: TObject);
begin
// here we need to (re)populate the rompath, and invalidate the rompath-types mapping. We also need to populate rompath
//  on formshow
getRompath('not sure yet')
end;

function TFrmMameOptions.getRompath(const directory:String):TStringArray;
var
r: TStringArray;
i : Integer;
Executable : String;
Flags: String;
mameExePath: String;
romPathString: String;
Str, Delimiter : String;
// the ini path comes from the mame exe dir, but node works out what the filename is!

begin

With MainFrm do
begin
Executable := Settings.Paths.QPNodeFile;
  Flags := 'mametool --getRomPath ' + '"' + mameExePath + '"';
      //SynctoolResult := RunProcessAndReport('cmd.exe /C ' + Executable + ' ' + Flags, True, MainFrm.Settings.Paths.AppDir, SW_SHOWNORMAL);
      romPathString := GetDosOutput('cmd.exe /C' + Executable + ' ' + Flags, MainFrm.Settings.Paths.AppDir);
      // https://stackoverflow.com/questions/2625707/split-a-string-into-an-array-of-strings-based-on-a-delimiter
      begin
      With TStringList.Create Do
  try
    Text := ReplaceText(Str,Delimiter,#13#10);

    // From here on and until "finally", your desired result strings are
    // in strings[0].. strings[Count-1)
     finally
    Free; //Clean everything up, and liberate your memory ;-)
    end;
Result := r;
end;
end;
end;

procedure TFrmMameOptions.FormShow(Sender: TObject);

begin
  BtnXMLScan.Enabled := False;
  XMLEdit.Text := StatusNoExtras;

  TxtMameExtrasDirPath.Text := MainFrm.Settings.MameExtrasDir;
  if (TXTMameExtrasDirPath.GetTextLen > 0) then
  begin
   BtnXMLScan.Enabled := True;
   XMLEdit.Text := StatusNotLoaded;
  if (MainFrm.Settings.MameXMLVersion <> '') and
    FileExists(MainFrm.Settings.Paths.CfgDir + 'mame.json') then
    begin
      XMLEdit.Text := 'Loaded: ' + MainFrm.Settings.MameXMLVersion;
      BtnXMLScan.Caption := 'Choose XML File and Re-Scan'
    end;
  end;

  ChkBoxMameFilePaths.Checked := MainFrm.Settings.MameFilePaths;

  if (MainFrm.Settings.MameZipType = '7z')
  then RadMameFile7z.Checked := True
  else RadMameFileZip.Checked := True;

  if (MainFrm.Settings.MameFilePathsRomsType = 'NonMerged')
  then RadMameMergeNonMerged.Checked := True
  else RadMameMergeMerged.Checked := True;


  With MainFrm do
  begin
    EmuList.EmusToStrings(CmbMame.Items, cfMameArcade);
    if CmbMame.Items.Count = 0 then
    begin
      CmbMame.Items.Add(EmuEmptyMessage);
      CmbMame.ItemIndex := CmbMame.Items.IndexOf(EmuEmptyMessage);
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
      //we use all three of these folders heavily in what follows, so we really need them all
        begin
         if checkExtrasDir(jvBrowse.Directory) then
            begin
             TxtMameExtrasDirPath.Text := jvBrowse.Directory;
              MainFrm.Settings.MameExtrasDir := TxtMameExtrasDirPath.Text;
              BtnXMLScan.Enabled := True;
              //we don't need to save this to file, because a mame scan isn't possible without a valid saved path
            end
         else
             MessageDlg(QP_MAMEOPT_BAD_DIR, mtError, [mbOK], 0);

             if (XMLEdit.Text = StatusNoExtras) then XMLEdit.Text := StatusNotLoaded;
         end;
  finally
    FreeAndNil(jvBrowse);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMameOptions.BtnXMLScanClick(Sender: TObject);
var
  selectedFile, Executable, Flags, MameExeName, MameExePath: string;
  MameExeIndex: Integer;
  dlg: TOpenDialog;
  extrasDir : string;
  extrasDirOk : boolean;
  previousMameXMLVersion : string;

begin
  extrasDir := MainFrm.Settings.MameExtrasDir;
  extrasDirOk := checkExtrasDir(extrasDir);

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

  if (selectedFile <> '')
  and (CmbMame.ItemIndex <>-1)
  //we need to check the mame extras is STILL valid, we might have selected our mame extras dir long ago
  and extrasDirOk
  then
  begin
     With MainFrm do
     begin
       //invalidate the mame xml version in the settings, the node executable will set it for us
       // doing this does mean that if something goes wrong, we'll not be able to continue with the previous xml,
       // but not invalidating here means that we won't know if the node code failed
       // so lets remember what the setting was before we wipe it
       previousMameXMLVersion := Settings.MameXMLVersion;
       Settings.MameXMLVersion := '';
       //we need to get the executable name of the emulator selected in the dropdown, and then save it
       MameExeName := CmbMame.Items.Strings[CmbMame.ItemIndex];
       Settings.MametoolMameExeName := MameExeName;
       MameExeIndex := EmuList.IndexOfName(MameExeName);
       MameExePath := EmuList.GetItemByIndex(MameExeIndex).ExePath;
       Settings.MameToolMameExePath := MameExePath;

       Settings.MameXMLPath := selectedFile;
       Settings.SaveAllSettings(); //else how else will node read what you just did,
       //this will also save the mame extras dir for node to read, in case its newly-chosen

       Flags := 'mametool --scan';
       Executable := Settings.Paths.QPNodeFile;
       //root the call in the appdir else node gets confused...
       //change the flag of the cmd call to /C for live and /K for dev (halting)
       RunProcess('cmd.exe /C ' +  Executable + ' ' + Flags, True, Settings.Paths.AppDir, SW_SHOWNORMAL);
       //node should write the mamexml version into the settings now, so we need to reload the settings from disk
       Settings.LoadIni();
       if (Settings.MameXMLVersion <> '') and
        FileExists(Settings.Paths.CfgDir + 'mame.json') then
       begin
         XMLEdit.Text := 'Loaded: ' + Settings.MameXMLVersion;
         MessageDlg('After a successful MAME XML scan, you should run a new EFind to pick up new MAME/RetroArch-Mame Home-Computer and Console Emulators', mtInformation, [mbOK], 0);
       end
       else
       begin
         MessageDlg('The MAME XML was not read. Check source files, check mametool_logfile.txt in the root of the QuickPlay folder, try again, or call at the forums for help', mtInformation, [mbOK], 0);
         //if we didn't work things out, but we previously had a mame xml version, and we still have an json file, just restore it, give 'em a chance!
         if FileExists(Settings.Paths.CfgDir + 'mame.json') then
           begin
             Settings.MameXMLVersion := previousMameXMLVersion;
             XMLEdit.Text := 'Loaded: ' + Settings.MameXMLVersion;
           end
           //but if those things are messed up, update the status so we know things have messed up
           else XMLEdit.Text :=  StatusNotLoaded;
         end
       end;
     end
     else if Not extrasDirOk then MessageDlg(QP_MAMEOPT_BAD_DIR, mtError, [mbOK], 0);
end;
{-----------------------------------------------------------------------------}

procedure TFrmMameOptions.BtnMameOptsOkClick(Sender: TObject);
begin
  MainFrm.Settings.MameExtrasDir := TxtMameExtrasDirPath.Text;
  MainFrm.Settings.MameFilePaths := ChkBoxMameFilePaths.Checked;
  if RadMameFile7z.Checked
  then MainFrm.Settings.MameZipType := '7z'
  else MainFrm.Settings.MameZipType := 'Zip';

  if RadMameMergeNonMerged.Checked
  then MainFrm.Settings.MameFilePathsRomsType := 'NonMerged'
  else MainFrm.Settings.MameFilePathsRomsType := 'Merged';

  MainFrm.Settings.SaveAllSettings(); //in case you changed the mame extras dir but didn't do a scan
  //close the form with the modal result OK
  ModalResult := MrOK;

  //we want to refresh: sidebar icons, mame icons, info files will all now show up...
  //why not do it in the caller in the main form? just to be consistent with the other mame dialog boxes
   MainFrm.ActRefreshExecute(Sender);
  //bugfix: there's something specific about the xml scan, ini lookup and dat/efind posting that causes qp to lose current directory
  //  it was causing the first call to a mame game after a scan to fail as the game wasn't found (I suspect "./qp.exe") -  TODO: this
  //  should get called after the scan incase user presses cancel...
   setCurrentDir(MainFrm.Settings.Paths.AppDir);
end;

{-----------------------------------------------------------------------------}
  procedure TFrmMameOptions.MameXMLLinkLabelClick(Sender: TObject);
begin
  ShellExecute(Handle, 'open', PChar(MameXMLLinkLabel.Caption), '', '', sw_Show);
end;


end.



