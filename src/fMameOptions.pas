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
    procedure clearRompathSettings();
    procedure FormShow(Sender: TObject);
    procedure BtnMameOptsOkClick(Sender: TObject);
    procedure InitialiseMameRompathSelects(const RomPathsListSerial:String);
    function checkExtrasDir(const directory:String):Boolean;
    function getRompath(const directory:String): String; //TStringArray;
    function splitStringToArray(const serialisedArr:String; const delimiter:Char): TStrings;
    function StringInArrayOrBlank(const dir:String; arr: TStrings):String;
    function AreMameRomPathTypesValid():Boolean;

  private
    _MameExeName, _MameExePath, _MameExtrasDir : String;
  public
    { Public declarations }
  end;

const
  StatusNoExeOrExtras = 'select Mame Exe and Extras dir first';
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

{-----------------------------------------------------------------------------}
procedure TFrmMameOptions.clearRompathSettings();
begin
  With MainFrm do
    begin
      Settings.MameRomPath := '';
      Settings.MameRomPathTypeRomsPath:= '';
      Settings.MameRomPathTypeChdsPath := '';
      Settings.MameRomPathTypeSoftlistRomsPath := '';
      Settings.MameRomPathTypeSoftlistChdsPath := '';
    end;
end;


{-----------------------------------------------------------------------------}

//function  TFrmMameOptions.splitStringToArray(const serialisedArr, Delimiter:String): String;
function  TFrmMameOptions.splitStringToArray(const serialisedArr:String; const delimiter:Char): TStrings;
var
   ListOfStrings: TStringList;
begin
   ListOfStrings := TStringList.Create;
   ListOfStrings.Clear;
   ListOfStrings.Delimiter       := Delimiter;
   ListOfStrings.StrictDelimiter := True; // Requires D2006 or newer.
   ListOfStrings.DelimitedText   := serialisedArr;
   Result:=ListOfStrings;
   end;

{-----------------------------------------------------------------------------}


procedure TFrmMameOptions.CmbMameSelect(Sender: TObject);
var
  RomPathsListSerial: string;
  MameExeIndex: Integer;
begin
  With MainFrm do
Begin
  //we need to get the executable name of the emulator selected in the dropdown, and then save it
  _MameExeName := CmbMame.Items.Strings[CmbMame.ItemIndex];
  MameExeIndex := EmuList.IndexOfName(_MameExeName);
  _MameExePath := EmuList.GetItemByIndex(MameExeIndex).ExePath;
  RomPathsListSerial := getRompath(_MameExePath);
  InitialiseMameRompathSelects(RomPathsListSerial);
  //we have a potentially valid mame emu, if we also have a potentially valid exrtras dir, we can do a scan
  if (_MameExtrasDir <> '') and (XMLEdit.Text = StatusNoExeOrExtras) then
  begin
    XMLEdit.Text := StatusNotLoaded;
    BtnXMLScan.Enabled := True;
  end;
end;

// here we need to (re)populate the rompath, and invalidate the rompath-types mapping.
//    We also need to populate rompath on formshow

end;

{-----------------------------------------------------------------------------}

function TFrmMameOptions.getRompath(const directory:String):String; //TStringArray;
var
r: TStringArray;
i : Integer;
Executable : String;
Flags: String;
mameExePath: String;
romPathString: String;
Str, Delimiter: String;
// the ini path comes from the mame exe dir, but node works out what the filename is!

begin

With MainFrm do
begin
Executable := Settings.Paths.QPNodeFile;
  Flags := 'mametool --getRomPath ' + '"' + directory + '"'; //+ '"' + mameExePath + '"';
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
//TODO: did we do some impure munging there? its very unclear, nevermind
//  what we should do here is check if the rompath is the same as our saved setting
// for rompath, and if it isn't, refresh it and invalidate the selection dropdowns

Result := romPathString;//r;
end;
end;
end;
{-----------------------------------------------------------------------------}
function TFrmMameOptions.StringInArrayOrBlank(const dir:String; arr: TStrings):String;
var
  rompathBlank : String;
  IsStringInArray: Boolean;
  idx: Integer;
begin
    rompathBlank := '';
    idx := arr.IndexOf(dir);
    if idx <> -1 then
      Result := dir
    else
      Result := rompathBlank;
end;
{-----------------------------------------------------------------------------}
procedure TFrmMameOptions.InitialiseMameRompathSelects(const RomPathsListSerial:String);
var
  romPathsList: TStrings;
  rompathBlank : String;
begin
with MainFrm do
begin
rompathBlank := '';
RomPathEdit.Text := RomPathsListSerial;
    RomPathsList := splitStringToArray(RomPathsListSerial, ';');
    CmbRomsPath.Items := RomPathsList;
    CmbRomsPath.Text := StringInArrayOrBlank(Settings.MameRomPathTypeRomsPath, RomPathsList);
    CmbChdsPath.Items := RomPathsList;
    CmbChdsPath.Text := StringInArrayOrBlank(Settings.MameRomPathTypeChdsPath, RomPathsList);
    CmbSoftlistRomsPath.Items := RomPathsList;
    CmbSoftlistRomsPath.Text := StringInArrayOrBlank(Settings.MameRomPathTypeSoftlistRomsPath, RomPathsList);
    CmbSoftlistChdsPath.Items := RomPathsList;
    CmbSoftlistChdsPath.Text := StringInArrayOrBlank(Settings.MameRomPathTypeSoftlistChdsPath, RomPathsList);
 end;


end;

{-------------------------------------------------------------------------}

procedure TFrmMameOptions.FormShow(Sender: TObject);
var
  rompathsListSerial: String;
begin
  BtnXMLScan.Enabled := False;
  XMLEdit.Text := StatusNoExeOrExtras;
  //grab these as we might want to send 'em to the xml scanner
  _MameExeName := MainFrm.Settings.MametoolMameExeName;
  _MameExePath := MainFrm.Settings.MametoolMameExePath;
  _MameExtrasDir := MainFrm.Settings.MameExtrasDir;

  TxtMameExtrasDirPath.Text := _MameExtrasDir;
  if (TXTMameExtrasDirPath.GetTextLen > 0) and (MainFrm.Settings.MametoolMameExePath <> '') then
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
      RomPathEdit.Text := '';
      MameOptsOK.Enabled := false;
      //no one's going to be printing any filetypes in this state
      ChkBoxMameFilePaths.Checked := false;
      Settings.MameFilePaths := ChkBoxMameFilePaths.Checked;
      clearRompathSettings();
    end
    else
    begin
      CmbMame.ItemIndex := CmbMame.Items.IndexOf(Settings.MametoolMameExeName);
      if CmbMame.ItemIndex <> -1 then
      begin
        RomPathsListSerial := getRomPath(Settings.MametoolMameExePath);
        InitialiseMameRompathSelects(RomPathsListSerial);

      end;
    end;
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
              _MameExtrasDir := TxtMameExtrasDirPath.Text;
              //we don't need to save this to file, because a mame scan isn't possible without a valid saved path

              //if we also have a mame exe path, we can do a scan
              if (XMLEdit.Text = StatusNoExeOrExtras) and (_MameExePath <> '') then
              begin
                XMLEdit.Text := StatusNotLoaded;
                BtnXMLScan.Enabled := True;
              end;

            end
         else
             MessageDlg(QP_MAMEOPT_BAD_DIR, mtError, [mbOK], 0);


         end;
  finally
    FreeAndNil(jvBrowse);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMameOptions.BtnXMLScanClick(Sender: TObject);
var
  selectedFile, Executable, Flags: string;
  MameExeIndex: Integer;
  dlg: TOpenDialog;
  extrasDir : string;
  extrasDirOk : boolean;
  previousMameXMLVersion : string;

begin
  extrasDir := _MameExtrasDir;
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
       Settings.MameXMLPath := selectedFile;

       //We'll need to save these now, node needs 'em
       Settings.MametoolMameExeName := _MameExeName;
       Settings.MametoolMameExePath := _MameExePath;
       Settings.MameExtrasDir := _MameExtrasDir;
       Settings.SaveAllSettings(); //else how else will node read what you just did,
       //this will also save the mame extras dir for node to read, in case its newly-chosen
       //and we also need Settings.MametoolMameExePath for node, but we assume we have it, or else this button wouldn't be selectable

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
with MainFrm do
begin
  //if they want mame filepath printing, but some of the 4 rompath types haven't been chosen or became
  //  invalid, don't let them leave the form till they've chosen
  if not AreMameRomPathTypesValid() then
  begin
    MessageDlg('Some Rompath Type mappings not valid, please rechoose or disable Mame Filepath printing', mtError, [mbOK], 0);
    Exit;
  end;

  //save the state of these dropdowns off now (in case you didn't run an xml scan and save 'em then)
  Settings.MameExtrasDir := _MameExtrasDir;
  Settings.MametoolMameExeName := _MameExeName;
  Settings.MametoolMameExePath := _MameExePath;

  Settings.MameFilePaths := ChkBoxMameFilePaths.Checked;
  //save the mameRomPath (we don't want to do this unless you've made selections tbh)
  //note we have to do the whole call again
  //there's a line break here, which goes through to the text settings file, remove it. I think it only matters when we persist it
  Settings.MameRomPath := StringReplace(StringReplace(getRomPath(Settings.MametoolMameExePath), #10, ' ', [rfReplaceAll]), #13, ' ', [rfReplaceAll]);
  //Save the four rompathtype settings
  Settings.MameRomPathTypeRomsPath:= CmbRomsPath.Text;
  Settings.MameRomPathTypeChdsPath := CmbChdsPath.Text;
  Settings.MameRomPathTypeSoftlistRomsPath := CmbSoftlistRomsPath.Text;
  Settings.MameRomPathTypeSoftlistChdsPath := CmbSoftlistChdsPath.Text;


  if RadMameFile7z.Checked
  then Settings.MameZipType := '7z'
  else Settings.MameZipType := 'Zip';

  if RadMameMergeNonMerged.Checked
  then Settings.MameFilePathsRomsType := 'NonMerged'
  else Settings.MameFilePathsRomsType := 'Merged';

  Settings.SaveAllSettings(); //in case you changed the mame extras dir but didn't do a scan
  //close the form with the modal result OK
end;
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
// ok-ing the mame options dialog will allow us to print rompaths, this will mess up
// if you have invalid rompathtypes. we can simply disallow exiting the form unless these options are valid
// note here that we don't check that any of the type mappings fail to agree with the mame ini's rompath, because
// the mame emu selection dropdown does that for us, and its a gatekeeper to get to this point
function TFrmMameOptions.AreMameRomPathTypesValid():Boolean;
var valid: Boolean;
begin
  valid := false;
  if (ChkBoxMameFilePaths.checked) and
  (CmbRomsPath.Text <> '') and
  (CmbChdsPath.Text <> '') and
  (CmbSoftlistRomsPath.Text <> '') and
  (CmbSoftlistChdsPath.Text <> '')
  then
  valid := true;
  Result := valid
end;



{-----------------------------------------------------------------------------}
  procedure TFrmMameOptions.MameXMLLinkLabelClick(Sender: TObject);
begin
  ShellExecute(Handle, 'open', PChar(MameXMLLinkLabel.Caption), '', '', sw_Show);
end;


end.



