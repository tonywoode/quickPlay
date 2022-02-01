//------------------------------------------------------------------------
// UNIT information
//------------------------------------------------------------------------
{

This unit contains the Settings Class, which is used to store all of
QuickPlays variables and settings, and has code to maintain these settings.
Also contains code to create default files such as Types and System

}

unit uSettings;

interface

uses SysUtils, Classes, StdCtrls, Dialogs, forms, graphics, Inifiles, VirtualTrees,
     uQPMiscTypes;

Type

  TQPPaths = packed record
    AppDir : String;
    CfgDir : String;
    ROMSDir : String;
    SearchDir : String;
    QPTempDir : String;
    EFindDir : String;
    BinDir   : String;
    FavsFile : TFileName;
    SettingsFile : TFileName;
    GoodMergeFile : TFileName;
    SystemsFile : TFileName;
    GameTypeFile : TFileName;
    LanguageFile : TFileName;
    SysFileExtFile : TFileName;
    ToolsFile : TFileName;
    EmulatorsFile : TFileName;
    MediaPanelCfgFile : TFileName;
    QPNodeFile : TFileName;
    QPElectronFile : TFileName;

  end;

  TQPBackgroundCfg = packed record
    DirBG : TFileName;
    ROMBG : TFileName;
    SearchBG : TFileName;
    EmuBG : TFileName;
    ToolBG : TFileName;
    DefaultROMBG : Boolean;
  end;

  TQPSettings = Class
    Private

      //WallPaper settings.
      _BG : TQPBackgroundCfg;

      _bAutoDel : boolean;      //Automatically delete ROMs linked to a deleted Emu (off by default)
      _bMiniOnRun : boolean;    //Minimise on running a ROM
      _bOldMini : boolean;      //use old minimising code (depreciated, will be removed soon)
      _bUseRunDLG : boolean;    //always use the Run dialog when running a game
      _bClearFilter : boolean;  //clear the ROMs filter when changing directory.
      _bJoy : boolean;          //joystick support
      _bRememberROM : boolean;  //remember the last selected ROM when closing and reopening.

      _bUseRealEmuIcons : Boolean;
      _bUseRealToolIcons : Boolean;
      _sMameExtrasDir: string;   //root directory for mame assets like icons and ini files
      _sMameXMLPath: String;     //location of the last scanned full mame xml file path (--listxml output of mame proper)
      _sMameXMLVersion: String;  //qpNode writes this here, the version string in the xml
      _sMametoolMameExeName: String; //the emu name of the Mame executable last selected in mame options
      _sMametoolMameExePath: String; //the filename of the Mame executable last selected in mame options
      _sMameFileManagerFilePath: String; //Path to an output of the program MameFileManger, essentially a mame filter file of rommames
      _sMessIconDir : String;    //icons dir for system/romlist icons in sidebar roms panel.
      _bMameFilePaths : boolean; //print filepaths or not in MAME romdatas
      _sMameFilePathsRomsType : String; //do we have 7z or zipped MAME roms
      _sMameZipType : String; //do we have non-merged, split or merged MAME roms
      _sMameRomPath : String;

      //and here's all the checkboxes in the mame printer
      _bMameOptBios : boolean;
      _bMameOptCasino: boolean;
      _bMameOptClones: boolean;
      _bMameOptMature: boolean;
      _bMameOptMechanical: boolean;
      _bMameOptMess: boolean;
      _bMameOptPreliminary: boolean;
      _bMameOptPrintClub: boolean;
      _bMameOptSimulator: boolean;
      _bMameOptTableTop: boolean;
      _bMameOptQuiz: boolean;
      _bMameOptUtilities: boolean;
      _bMameOptCompany: boolean;
      _bMameOptGenre: boolean;
      _bMameOptNPlayers: boolean;
      _bMameOptRating: boolean;
      _bMameOptSeries: boolean;
      _bMameOptVersion: boolean;
      _bMameOptYear:  boolean;


      _bSaveCols : boolean;     //save column widths and positions.
      _bRomImages : boolean;    //allow ICONS in the ROMs listing.
      _bIncVersion : boolean;   //include an emulator version string in the rom listing.
      _iIconSize : integer;    //size for each rom in roms list view
      _iIconSizeDir : integer; //size for emu icons


      //variable to store whether QuickPlay can write to this disk
      _AllowWrite : Boolean;
      _NoDats : Boolean;
      _DatsUpToDate : Boolean;

      {Main Config Variables}
      _ShowTabsInSideBar : Boolean;
      _FolderExpandMode : TQPFolderExpandMode;

      _CheckForUpdatesOnStart : Boolean;

      // Ratings
      _qprRatingsMode : TQPRatingsMode;
      _RatingsRangeLow : Integer;
      _RatingsRangeHigh : Integer;
      _RatingsCustom : TStringList;

      procedure SetTabsInSideBar(value : Boolean);

    Public

      Paths : TQPPaths;
      RunOptions : TQPRunOptions;

      Constructor Create;
      destructor Destroy;override;
      procedure BackupData(UseName : TFileName);
      Procedure CreateDefaultIni(Reset : boolean; Path : String);
      procedure CreateGoodCodes(path : string);
      procedure CreateLanguage(path : string);
      procedure CreateSysDat(path: string);
      procedure CreateSysFileExt(path: string);
      procedure CreateTools(path: string);
      procedure CreateEmulators(path: string);
      procedure CreateMediaPanelCfg(path: string);
      procedure CreateTypeDat(path : string);
      Function ExtractModeToPath(Mode : TQPExtractDest) : String;
      Procedure HideShowCol(Directory : String);
      procedure LoadDimensions(Layout : Integer);
      procedure LoadIni();
      Procedure LoadLastROM();
      procedure RestoreData(DataFile : TFileName);
      procedure PathSetup();
      procedure Ratings(var strList : TStrings);overload;
      procedure Ratings(Cmb : TComboBox);overload;
      Procedure SaveAllSettings();
      procedure SaveDefaultColumns(cols : array of Boolean);
      procedure SaveUISettings();
      Procedure SaveCurrentROM(Dir : String; ROM : TObject);
      Procedure SetupWindow();

      //property to say whether file write access is allowed.
      Property AllowWrite : Boolean Read _AllowWrite write _AllowWrite;

      //Wallpaper setttings
      Property Backgrounds : TQPBackgroundCfg read _bg write _bg;

      //General Properties
      Property CheckForUpdatesOnStart : Boolean read _CheckForUpdatesOnStart write _CheckForUpdatesOnStart;
      Property AutoDelRoms : boolean Read _bAutoDel Write _bAutoDel;
      Property MiniOnRun : Boolean Read _bMiniOnRun Write _bMiniOnRun;
      Property UseOldMini : Boolean Read _bOldMini Write _bOldMini;
      Property UseRunDlg : Boolean Read _bUseRunDLG Write _bUseRunDLG;
      Property RememberLast : Boolean Read _bRememberROM write _bRememberROM;
      Property UseImagesForROMs : Boolean Read _bRomImages Write _bRomImages;
      Property ClearFilter : Boolean Read _bClearFilter Write _bClearFilter;
      Property Joy : Boolean Read _bJoy Write _bJoy;
      Property SaveColumnSize : Boolean Read _bSaveCols Write _bSaveCols;
      Property AddVersion : Boolean Read _bIncVersion Write _bIncVersion;
      Property IconSize : Integer Read _iIconSize Write _iIconSize;
      Property IconSizeDir : Integer Read _iIconSizeDir Write _iIconSizeDir;

      Property FolderExpandMode : TQPFolderExpandMode read _FolderExpandMode write _FolderExpandMode;
      Property ShowTabsInSideBar : Boolean read _ShowTabsInSideBar write SetTabsInSideBar;

      Property UseRealEmuIcons : Boolean read _bUseRealEmuIcons write _bUseRealEmuIcons;
      Property UseRealToolIcons : Boolean read _bUseRealToolIcons write _bUseRealToolIcons;
      Property MameExtrasDir : string read _sMameExtrasDir write _sMameExtrasDir;
      Property MameXMLPath : string read _sMameXMLPath write _sMameXMLPath;
      Property MameXMLVersion : string read _sMameXMLVersion write _sMameXMLVersion;
      Property MametoolMameExeName : string read _sMametoolMameExeName write _sMametoolMameExeName;
      Property MametoolMameExePath : string read _sMametoolMameExePath write _sMametoolMameExePath;
      Property MameFileManagerFilePath : string read _sMameFileManagerFilePath write _sMameFileManagerFilePath;
      Property MessIconDir : string read _sMessIconDir write _sMessIconDir;
      Property MameFilePaths : Boolean read _bMameFilePaths write _bMameFilePaths;
      Property MameFilePathsRomsType : string read _sMameFilePathsRomsType write _sMameFilePathsRomsType;
      Property MameZipType : string read _sMameZipType write _sMameZipType ;
      Property MameRomPath : string read _SMameRomPath write _sMameRomPath ;

      //and here's all the check boxes in the mame printer
      property MameOptBios : Boolean read _bMameOptBios write _bMameOptBios;
      property MameOptCasino : Boolean read _bMameOptCasino write _bMameOptCasino;
      property MameOptClones : Boolean read _bMameOptClones write _bMameOptClones;
      property MameOptMature : Boolean read _bMameOptMature write _bMameOptMature;
      property MameOptMechanical : Boolean read _bMameOptMechanical write _bMameOptMechanical;
      property MameOptMess : Boolean read _bMameOptMess write _bMameOptMess;
      property MameOptPreliminary : Boolean read _bMameOptPreliminary write _bMameOptPreliminary;
      property MameOptPrintClub : Boolean read _bMameOptPrintClub write _bMameOptPrintClub;
      property MameOptSimulator : Boolean read _bMameOptSimulator write _bMameOptSimulator;
      property MameOptTableTop : Boolean read _bMameOptTableTop write _bMameOptTableTop;
      property MameOptQuiz : Boolean read _bMameOptQuiz write _bMameOptQuiz;
      property MameOptUtilities : Boolean read _bMameOptUtilities write _bMameOptUtilities;
      property MameOptCompany : Boolean read _bMameOptCompany write _bMameOptCompany;
      property MameOptGenre  : Boolean read _bMameOptGenre write _bMameOptGenre;
      property MameOptNPlayers : Boolean read _bMameOptNPlayers write _bMameOptNPlayers;
      property MameOptRating : Boolean read _bMameOptRating write _bMameOptRating;
      property MameOptSeries : Boolean read _bMameOptSeries write _bMameOptSeries;
      property MameOptVersion : Boolean read _bMameOptVersion write _bMameOptVersion;
      property MameOptYear : Boolean read _bMameOptYear write _bMameOptYear;



      Property NoDats : Boolean Read _NoDats Write _NoDats;
      Property DatsCurrent : Boolean Read _DatsUpToDate write _DatsUpToDate;
      //Ratings properties.
      Property RatingsMode : TQPRatingsMode read _qprRatingsMode write _qprRatingsMode;
      Property RatingsLow : Integer read _RatingsRangeLow write _RatingsRangeLow;
      Property RatingsHigh : Integer read _RatingsRangeHigh write _RatingsRangeHigh;
      Property RatingsCustom : TStringList Read _RatingsCustom write _RatingsCustom;
  end;

implementation

uses Windows, JCLFileUtils, JCLStrings, fMain, uJFile, uRom,
     JclSysInfo, uJUtilities, uQPConst, uJCompression, uJVirtualTree,
     uQPCompObj, ujMiscResourceStrs;

{$I Compilers.inc}

{-----------------------------------------------------------------------------}

procedure TQPSettings.SetTabsInSideBar(value : Boolean);
var
  i : Integer;
begin
  Self._ShowTabsInSideBar := Value;
  for i := 0 to MainFrm.pgSideBar.PageCount-1 do
    MainFrm.pgSideBar.Pages[i].TabVisible := Value;

  MainFrm.pgSideBar.ActivePageIndex := 0;
end;

{-----------------------------------------------------------------------------}

procedure TQPSettings.BackupData(UseName : TFileName);
var
  zFilter : TStrings;
begin
  zFilter := TStringList.Create;
  try
    zFilter.Add('data\*.*');
    zFilter.Add('dats\*.*');
    zFilter.Add('search\*.*');
    uQPCompObj.Compression.CompressDirectory(Paths.AppDir, UseName, zFilter);
  finally
    FreeAndNil(zFilter);
  end;
end;
{-----------------------------------------------------------------------------}

Procedure TQPSettings.CreateDefaultIni(Reset : boolean; Path : String);
Var
  Ini : TMemIniFile;
Begin

  If (Reset = true) OR (FileExists(Path) = false) then
  Begin
    Ini := TMemIniFile.Create(Path);

    try
    Ini.Clear;

    //General Settings

    Ini.WriteBool('Main','ChkAutoDel',False);
    Ini.WriteBool('Main','ChkMinimise', True);
    Ini.WriteBool('Main', 'ChkOldMini', false);
    Ini.WriteBool('Main', 'ChkRunDlg', False);
    Ini.WriteBool('Main', 'ChkClearFilter', true);
    Ini.WriteBool('Main', 'ChkRememberROM', True);
    Ini.WriteBool('Main', 'ChkJoy', false);

    //ROM list options
    Ini.WriteBool('RomOptions','ChkCol',True);
    Ini.WriteBool('RomOptions','ChkRomGridlines',False);
    Ini.WriteBool('RomOptions','ChkRomHotTrack',False);
    Ini.WriteBool('RomOptions','ChkListImages',True);
    Ini.WriteBool('RomOptions','ChkRomRowSel',True);
    Ini.WriteBool('RomOptions','ChkRomHints', True);

    //Directory list options
    Ini.WriteBool('DirOptions', 'ChkDirGridlines', false);
    Ini.WriteBool('DirOptions', 'ChkDirHotTrack', false);
    Ini.WriteBool('DirOptions', 'ChkDirRowSel', false);
    Ini.WriteBool('DirOptions', 'ChkDirHints', true);

    //Media Options
    Ini.WriteBool('Main', 'ChkSearchROMdir', true);
    Ini.WriteBool('Main', 'ChkCloneSearch', true);
    Ini.WriteInteger('Main', 'SearchType', 1);

    //Mouse Options
    Ini.WriteBool('PadEmulation', 'ChkMouseEmu', False);
    Ini.WriteBool('PadEmulation', 'ChkPadAnalog', False);
    Ini.WriteInteger('PadEmulation', 'MouseCnt', 5);
    Ini.WriteInteger('PadEmulation', 'MouseRefresh', 10);

    //Version String
    Ini.WriteString('Version', 'QP', QPVer );
    if _AllowWrite then
      Ini.UpdateFile;

    //free the ini file object
    finally
      FreeAndNil(Ini);
    end;

  end;


End;

{-----------------------------------------------------------------------------}

procedure TQPSettings.CreateGoodCodes(path : string);
var
  lang : Tstringlist;
  tmpStream: TResourceStream;
begin

  if not _AllowWrite then
    Exit;

  lang := Tstringlist.Create;
  try

    tmpStream := TResourceStream.Create( HInstance, 'goodcodes_txt', 'TEXT' );
    try
      lang.LoadFromStream( tmpStream );
    finally
      FreeAndNil(tmpStream);
    end;

    lang.SaveToFile(path);
  finally
    FreeAndNil(lang);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TQPSettings.CreateLanguage(path : string);
var
  lang : Tstringlist;
  tmpStream: TResourceStream;
begin

  if not _AllowWrite then
    Exit;

  lang := Tstringlist.Create;
  try

    tmpStream := TResourceStream.Create( HInstance, 'language_txt', 'TEXT' );
    try
      lang.LoadFromStream( tmpStream );
    finally
      FreeAndNil(tmpStream);
    end;

    lang.SaveToFile(path);
  finally
    FreeAndNil(lang);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TQPSettings.CreateSysDat(path : string);
var
  dat : Tstringlist;
  tmpStream: TResourceStream;
begin

  if not _AllowWrite then
    Exit;

  dat := Tstringlist.Create;
  try
    tmpStream := TResourceStream.Create( HInstance, 'systems_txt', 'TEXT' );
    try
      dat.LoadFromStream( tmpStream );
    finally
      FreeAndNil(tmpStream);
    end;
    dat.SaveToFile(path);
  finally
    FreeAndNil(dat);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TQPSettings.CreateSysFileExt(path: string);
var
  dat : Tstringlist;
  tmpStream: TResourceStream;
begin

  if not _AllowWrite then
    Exit;

  dat := Tstringlist.Create;
  try
    tmpStream := TResourceStream.Create( HInstance, 'SysFileExt_txt', 'TEXT' );
    try
      dat.LoadFromStream( tmpStream );
    finally
      FreeAndNil(tmpStream);
    end;
    dat.SaveToFile(path);
  finally
    FreeAndNil(dat);
  end;
end;

{-----------------------------------------------------------------------------}
procedure TQPSettings.CreateTools(path: string);
var
  dat : Tstringlist;
  tmpStream: TResourceStream;
begin

  if not _AllowWrite then
    Exit;

  dat := Tstringlist.Create;
  try
    tmpStream := TResourceStream.Create( HInstance, 'Tools_txt', 'TEXT' );
    try
      dat.LoadFromStream( tmpStream );
    finally
      FreeAndNil(tmpStream);
    end;
    dat.SaveToFile(path);
  finally
    FreeAndNil(dat);
  end;
end;

{-----------------------------------------------------------------------------}
procedure TQPSettings.CreateEmulators(path: string);
var
  dat : Tstringlist;
  tmpStream: TResourceStream;
begin

  if not _AllowWrite then
    Exit;

  dat := Tstringlist.Create;
  try
    tmpStream := TResourceStream.Create( HInstance, 'Emulators_txt', 'TEXT' );
    try
      dat.LoadFromStream( tmpStream );
    finally
      FreeAndNil(tmpStream);
    end;
    dat.SaveToFile(path);
  finally
    FreeAndNil(dat);
  end;
end;
{-----------------------------------------------------------------------------}
procedure TQPSettings.CreateMediaPanelCfg(path: string);
var
  dat : Tstringlist;
  tmpStream: TResourceStream;
begin

  if not _AllowWrite then
    Exit;

  dat := Tstringlist.Create;
  try
    tmpStream := TResourceStream.Create( HInstance, 'Media_txt', 'TEXT' );
    try
      dat.LoadFromStream( tmpStream );
    finally
      FreeAndNil(tmpStream);
    end;
    dat.SaveToFile(path);
  finally
    FreeAndNil(dat);
  end;
end;
{-----------------------------------------------------------------------------}
procedure TQPSettings.CreateTypeDat(path : string);
var
  Types : Tstringlist;
  tmpStream: TResourceStream;
begin

  if not _AllowWrite then
    Exit;

  Types := Tstringlist.Create;
  try

    tmpStream := TResourceStream.Create( HInstance, 'type_txt', 'TEXT' );
    try
      Types.LoadFromStream( tmpStream );
    finally
      FreeAndNil(tmpStream);
    end;

    Types.SaveToFile(path);
  finally
    FreeAndNil(Types);
  end;
end;

{-----------------------------------------------------------------------------}

Function TQPSettings.ExtractModeToPath(Mode : TQPExtractDest) : String;
begin
  Case Mode of
    qemROMDir : Result := '';
    qemQPDir : Result := Self.Paths.QPTempDir;
    qemSysTempDir : Result := JCLSysInfo.GetWindowsTempFolder();
  end;
end;

{-----------------------------------------------------------------------------}

Procedure TQPSettings.HideShowCol(Directory : String);
Var
  I : Integer;
  Ini : TMemIniFile;
  ColSet : Boolean;

Begin

  ColSet := False;

  If Directory <> '' then
  begin

    Ini := TMemIniFile.Create(Directory + 'folders.ini');
    Try

     If Ini.SectionExists('ColView') then
     begin
       For i := 0 to MainFrm.VTRoms.Header.Columns.Count-1 do
         if Ini.ReadBool('ColView', IntToStr(i), true) then
           MainFrm.VTRoms.Header.Columns.Items[i].Options := MainFrm.VTRoms.Header.Columns.Items[i].Options + [coVisible]
         Else
           MainFrm.VTRoms.Header.Columns.Items[i].Options := MainFrm.VTRoms.Header.Columns.Items[i].Options - [coVisible];

       ColSet := True;
     end;

    Finally
      Ini.Free;
    end;
  end;

  If not ColSet then
  begin
    Ini := TMemIniFile.Create(Paths.SettingsFile);
    Try

     For i := 0 to MainFrm.VTRoms.Header.Columns.Count-1 do
       if Ini.ReadBool('ColView', IntToStr(i), true) then
         MainFrm.VTRoms.Header.Columns.Items[i].Options := MainFrm.VTRoms.Header.Columns.Items[i].Options + [coVisible]
       Else
         MainFrm.VTRoms.Header.Columns.Items[i].Options := MainFrm.VTRoms.Header.Columns.Items[i].Options - [coVisible];

    Finally
      Ini.Free;
    end;
  end;
  
End;

{-----------------------------------------------------------------------------}

procedure TQPSettings.LoadDimensions(Layout : Integer);
var
  Ini : TmemIniFile;
  defaults : Array [0..3] of Integer;
begin

  //create sensible defaults for the type of layout sent in.
  Case Layout of
    qpwNormal :       begin
                        Defaults[0] := 185;
                        Defaults[1] := 374;
                        Defaults[2] := 161;
                        Defaults[3] := 374;
                      end;
    qpwVertical :     begin
                        Defaults[0] := 800;
                        Defaults[1] := 100;
                        Defaults[2] := 800;
                        Defaults[3] := 150;
                      end;
    qpwDirOnTop :     begin
                        Defaults[0] := 185;
                        Defaults[1] := 374;
                        Defaults[2] := 800;
                        Defaults[3] := 150;
                      end;
    qpwImgToBottom :  Begin
                        Defaults[0] := 800;
                        Defaults[1] := 100;
                        Defaults[2] := 161;
                        Defaults[3] := 374;
                      end;
  end;

  Ini := TMemIniFile.Create(Paths.SettingsFile);
  try
    MainFrm.SplitImgHorz := Ini.ReadInteger('Layout-'+IntToStr(Layout), 'ImgHorz', Defaults[0]);
    MainFrm.SplitImgVert := Ini.ReadInteger('Layout-'+IntToStr(Layout), 'ImgVert', Defaults[1]);
    MainFrm.SplitDirHorz := Ini.ReadInteger('Layout-'+IntToStr(Layout), 'DirHorz', Defaults[2]);
    MainFrm.SplitDirVert := Ini.ReadInteger('Layout-'+IntToStr(Layout), 'DirVert', Defaults[3]);
  finally
    FreeAndNil(Ini);
  end;
end;

{-----------------------------------------------------------------------------}

//procedure to set up the window size and other related settings
procedure TQPSettings.LoadIni();
var
  Ini : TMemIniFile;
  I : Integer;
  AllPos: Boolean;
  tmpStream : TMemoryStream;
  Cfg : TJVTConfig;
begin

  with MainFrm do
  begin

    Ini := TMemIniFile.Create(Paths.SettingsFile);
    try

      //check that all dat files are up to date.
      If StrCompare(Ini.ReadString('Version', 'QP', ''), '3.8.1') = 0 then   //todo - check this
        _DatsUpToDate := False;

      MainFrm.WindowLayout := Ini.ReadInteger('Windows', 'WindowLayout', qpwNormal);

      // SET UP VARIABLES

      _CheckForUpdatesOnStart := Ini.ReadBool('Main', 'CheckForUpdatesOnStart', True);

      //Load the AutoDelete roms linked to deleted emulator option
      _bAutoDel := Ini.ReadBool('Main','ChkAutoDel', False);

      //Load the Minimise when running a rom value
      _bMiniOnRun := Ini.ReadBool('Main','ChkMinimise', True);

      //this variable allows you to use the OLD style minimising.
      _bOldMini := Ini.ReadBool('Main', 'ChkOldMini', false);

      //load the use Run Rom Dialog when launching a game
      _bUseRunDLG := Ini.ReadBool('Main', 'ChkRunDlg', True);

      //clear filter variable - boolean
      _bClearFilter := Ini.ReadBool('Main', 'ChkClearFilter', true);

      //clear joy variable - boolean
      _bJoy := Ini.ReadBool('Main', 'ChkJoy', false);

      //remember ROM variable
      _bRememberROM := Ini.ReadBool('Main', 'ChkRememberROM', True);

      // temporary directory extraction setting.
      RunOptions.ExtractMode := TQPExtractDest(Ini.ReadInteger('Main', 'TempExtrDir', 1));

      //power scheme changing setting
      RunOptions.GeneralPowerScheme := Ini.ReadString('Main', 'PwrScheme', QP_DONT_CHANGE);

      _bUseRealEmuIcons := Ini.ReadBool('IconThread', 'Emus', True);
      _bUseRealToolIcons := Ini.ReadBool('IconThread', 'Tools' , True);

      //MAME Settings
      _sMameExtrasDir := Ini.ReadString('MAME', 'MameExtrasPath', '');
      _sMameXMLPath := Ini.ReadString('MAME', 'MameXMLPath', '');
      _sMameXMLVersion := Ini.ReadString('MAME', 'MameXMLVersion', '');
      _sMametoolMameExeName := Ini.ReadString('MAME', 'MametoolMameExeName', '');
      _sMametoolMameExePath := Ini.ReadString('MAME', 'MametoolMameExePath', '');
      _sMameFileManagerFilePath := Ini.ReadString('MAME', 'MameFileManagerFilePath', '');
      _bMameFilePaths := Ini.ReadBool('MAME', 'MameFilePaths', False);
      _sMameZipType := Ini.ReadString('MAME', 'MameZipType', '');
      _sMameFilePathsRomsType := Ini.ReadString('MAME', 'MameFilePathsRomsType', '');
      _SMameRomPath := Ini.ReadString('MAME', 'MameRomPath', '')  ;

      //and here's all the checkobxes from the mame printer
      _bMameOptBios := Ini.ReadBool('MAME', 'MameOptBios', True);
      _bMameOptCasino := Ini.ReadBool('MAME', 'MameOptCasino', True);
      _bMameOptClones := Ini.ReadBool('MAME', 'MameOptClones', True);
      _bMameOptMature := Ini.ReadBool('MAME', 'MameOptMature', True);
      _bMameOptMechanical := Ini.ReadBool('MAME', 'MameOptMechanical', True);
      _bMameOptMess := Ini.ReadBool('MAME', 'MameOptMess', True);
      _bMameOptPreliminary := Ini.ReadBool('MAME', 'MameOptPreliminary', True);
      _bMameOptPrintClub := Ini.ReadBool('MAME', 'MameOptPrintClub', True);
      _bMameOptSimulator := Ini.ReadBool('MAME', 'MameOptSimulator', True);
      _bMameOptTableTop := Ini.ReadBool('MAME', 'MameOptTableTop', True);
      _bMameOptQuiz := Ini.ReadBool('MAME', 'MameOptQuiz', True);
      _bMameOptUtilities := Ini.ReadBool('MAME', 'MameOptUtilities', True);
      _bMameOptCompany := Ini.ReadBool('MAME', 'MameOptCompany', False);
      _bMameOptGenre := Ini.ReadBool('MAME', 'MameOptGenre', False);
      _bMameOptNPlayers := Ini.ReadBool('MAME', 'MameOptNPlayers', False);
      _bMameOptRating := Ini.ReadBool('MAME', 'MameOptRating', False);
      _bMameOptSeries := Ini.ReadBool('MAME', 'MameOptSeries', False);
      _bMameOptVersion := Ini.ReadBool('MAME', 'MameOptVersion', False);
      _bMameOptYear := Ini.ReadBool('MAME', 'MameOptYear', False);

      //Ratings settings
      _qprRatingsMode := TQPRatingsMode(Ini.ReadInteger('Ratings', 'Mode', 1));
      Self._RatingsRangeLow := Ini.ReadInteger('Ratings', 'low', 1);
      Self._RatingsRangeHigh := Ini.ReadInteger('Ratings', 'high', 100);
      tmpStream := TMemoryStream.Create;
      try
        Ini.ReadBinaryStream('Ratings', 'Custom', tmpStream);
        tmpStream.Position := 0;
        Self._RatingsCustom.LoadFromStream(tmpStream);
      finally
        FreeAndNil(tmpStream);
      end;

      //sidebar settings.
      Self.ShowTabsInSideBar := Ini.ReadBool('Sidebar', 'ShowTabs', True);
      Self._FolderExpandMode := TQPFolderExpandMode(Ini.ReadInteger('Main', 'DirExpandMode', 1));

      {------------------------------------}
      // Set up all the treeviews now.

      //set up the image bkgrounds
      
      _bg.DefaultROMBG := Ini.ReadBool('vtroms', 'EnableBGImage', False);

      Cfg := TJVTConfig.Create;
      try
        Cfg.VT := @MainFrm.VTRoms;
        Cfg.PBGImage := @_bg.ROMBG;
        Cfg.LoadFromIni(Ini);
        Cfg.Configure;

        Cfg.VT := @MainFrm.VTdir;
        Cfg.PBGImage := @_bg.DirBG;
        Cfg.LoadFromIni(Ini);
        Cfg.Configure;

        Cfg.VT := @MainFrm.VTSearches;
        Cfg.PBGImage := @_bg.SearchBG;
        Cfg.LoadFromIni(Ini);
        Cfg.Configure;

        Cfg.VT := @MainFrm.VTEmus;
        Cfg.PBGImage := @_bg.EmuBG;
        Cfg.LoadFromIni(Ini);
        Cfg.Configure;
        
        Cfg.VT := @MainFrm.vtTools;
        Cfg.PBGImage := @_bg.ToolBG;
        Cfg.LoadFromIni(Ini);
        Cfg.Configure;
      finally
        FreeAndNil(Cfg);
      end;

      //Load the Save Column Sizes option
      _bSaveCols := Ini.ReadBool('RomOptions','ChkCol', True);

      VTRoms.Header.SortColumn := Ini.ReadInteger('Windows', 'SortColumn', 0);
      If Ini.ReadBool('Windows', 'SortAsc', true) then
        VTRoms.Header.SortDirection := sdAscending
      else
        VTRoms.Header.SortDirection := sdDescending;

      //Set the column positions.

      with MainFrm.VTRoms do
      Begin

      //check we have a list of column positions
      AllPos := true;
      For I := 0 to Header.Columns.Count-1 do
        If Ini.ValueExists('ColPos', IntToStr(I)) = false then
          AllPos := False;

      if AllPos then
        For I := 0 to Header.Columns.Count-1 do
           Header.Columns.Items[I].Position := Ini.ReadInteger('ColPos', IntToStr(i), 0);

      //If Column Save is turned on then load the sizes from Ini
      if _bSaveCols then
        For i := 0 to Header.Columns.Count-1 do
          If Ini.ValueExists('ColSize', IntToStr(i)) then
            Header.Columns[i].Width := Ini.ReadInteger('ColSize', IntToStr(i), 50);

      //set up which columns to show and which to hide.
      HideShowCol(MainFrm.GetSelectedFolder);

      _bIncVersion := Ini.ReadBool('RomOptions', 'ChkIncVersion', false);

      _iIconSize := Ini.ReadInteger('VTRoms', 'IconSize', 20);
      _iIconSizeDir := Ini.ReadInteger('VTDir', 'IconSizeDir', 24);

      //Load the Images in listview option
      _bRomImages := Ini.ReadBool('RomOptions','ChkListImages', True);

      end; //end of With MainFrm.VTRoms

      {------------------------------------}

      // SET UP THE MISC APPEARANCE OPTIONS
      
      // set up visiblility of the Directory Toolbar
      If (not Ini.ReadBool('Windows', 'ShowDBar', true)) and
         (MainFrm.TBDir.Visible) then
        ActDBarVisible.Execute;

      //set up the visibility of the ROM toolbar
      If (not Ini.ReadBool('Windows', 'ShowRBar', true)) and
         (MainFrm.TBRoms.Visible) then
        ActRBarVisible.Execute;

      //set up the visibility of the ROM toolbar
      If (not Ini.ReadBool('Windows', 'ShowFilter', true)) and
         (MainFrm.PanFilter.Visible) then
        ActFilterVisible.Execute;

      //set up the rom image panel
      If (not Ini.ReadBool('Windows', 'ShowImg', True)) and
         (MainFrm.pgMediaPanel.Visible) then
        ActImgVisible.Execute;

    finally
      FreeAndNil(Ini);
    end;

  end; //end of WITH MainFrm statement

end;

{-----------------------------------------------------------------------------}

Procedure TQPSettings.LoadLastROM();
var
  Ini : TMemIniFile;
  Dir, ROM : String;
  SType : TQPRefresh;
begin

  If _bRememberROM then
  begin
    Ini := TMemIniFile.Create(Paths.SettingsFile);
    try
      Dir := Ini.ReadString('LastROM', 'Dir', '');
      ROM := Ini.ReadString('LastROM', 'ROM', '');
      SType := TQPRefresh(Ini.ReadInteger('LastROM', 'Type', 1));
      MainFrm.JumpToROM(Dir, ROM, SType);
    Finally
      FreeAndNil(Ini);
    end;
  end;

end;

{-----------------------------------------------------------------------------}

procedure TQPSettings.PathSetup;
//var
  //ReadOnly : Boolean;
begin

 // ReadOnly := ( DiskFree(0) = 0 );
 _AllowWrite := (not IsDriveReadOnly(Paths.AppDir));

  // The QuickPlay executable directory
  Paths.AppDir := extractfilepath(paramstr(0));

  //  The directories for the various DAT files which QuickPlay requires
  Paths.CfgDir := Paths.AppDir + 'dats\';
  //The Data directories, which contain the roms' databases
  Paths.ROMSDir := Paths.AppDir + 'data\';
  //Search Directory is were virtual folders are stored.
  Paths.SearchDir := Paths.AppDir + 'search\';

  //now check that both these directories exist AND are writeable!
  if (not _AllowWrite) and
     (DirectoryExists(Paths.CfgDir) = false) and
     (DirectoryExists(Paths.ROMSDir) = false)  then
  begin
    Paths.AppDir := IncludeTrailingPathDelimiter(GetWindowsTempFolder) + 'qp\';
    CreateDir(Paths.AppDir);
    //now CHANGE the 2 directory variables.
    Paths.CfgDir := Paths.AppDir + 'dats\';
    Paths.ROMSdir := Paths.AppDir + 'data\';
    Paths.SearchDir := Paths.AppDir + 'search\';
    //we need to move the efind files so they are writeable
    if not DirectoryExists(Paths.AppDir + 'efind\') then
      DirCopy(extractfilepath(paramstr(0))+'efind\', Paths.AppDir + 'efind\', True);
      DirCopy(extractfilepath(paramstr(0))+'bin\', Paths.AppDir + 'bin\', True); //why would these need moving from install dir? maybe this has been list in time
  end;

  Paths.BinDir := Paths.AppDir + 'bin\';
  Paths.EFindDir := Paths.AppDir + 'efind\';
  //set up the temp directory.
  Paths.QPTempDir := Paths.AppDir + 'temp\';
  if not DirectoryExists(Paths.QPTempDir) then
    CreateDir(Paths.QPTempDir);
    
  //now configure the rest of the filenames.
  Paths.FavsFile := Paths.CfgDir + 'favs.dat';
  Paths.SettingsFile := Paths.CfgDir + 'settings.ini';
  Paths.GoodMergeFile := Paths.CfgDir + 'GoodCodes.dat';
  Paths.SystemsFile := Paths.CfgDir + 'systems.dat';
  Paths.GameTypeFile := Paths.CfgDir + 'type.txt';
  Paths.LanguageFile := Paths.CfgDir + 'language.txt';
  Paths.SysFileExtFile := Paths.CfgDir + 'SystemFileExts.ini';
  Paths.ToolsFile := Paths.CfgDir + 'Tools.ini';
  Paths.EmulatorsFile := Paths.CfgDir + 'Emulators.ini';
  Paths.MediaPanelCfgFile := Paths.CfgDir + 'MediaPanelCfg.ini';
  Paths.QPNodeFile:= Paths.BinDir + 'QPNode.exe';
  Paths.QPElectronFile:= Paths.BinDir + 'QPElectron\' + 'QPElectron.exe';

  If (DirectoryExists(Paths.ROMSDir) = false) and
     (DirectoryExists(Paths.CfgDir) = false) then
    _NoDats := True
  else
    _NoDats := False;

  //If the DATs dir doesnt exist, it is created.
  if not directoryExists(Paths.CfgDir) then
    CreateDir(Paths.CfgDir);

  if not directoryExists(Paths.SearchDir) then
    CreateDir(Paths.SearchDir);

  //Check is the settings.ini file exists, if it doesnt - create it
  if not fileexists(Paths.SettingsFile) then
    CreateDefaultIni(false, Paths.SettingsFile);

  if not FileExists(Paths.GoodMergeFile) then
    CreateGoodCodes(Paths.GoodMergeFile);

  //Check is the system.dat file exists, if it doesnt - create it
  if not fileexists(Paths.SystemsFile) then
    CreateSysDat(Paths.SystemsFile);

  //check the language file exists, and if not create it
  if not FileExists(Paths.LanguageFile) then
    CreateLanguage(Paths.LanguageFile);

  //check the game type dat file exists, and if not create it
  if not FileExists(Paths.GameTypeFile) then
    CreateTypeDat(Paths.GameTypeFile);

  if not FileExists(Paths.SysFileExtFile) then
    CreateSysFileExt(Paths.SysFileExtFile);

  //Check is the Tools.ini file exists, if it doesnt - create it
  if not fileexists(Paths.ToolsFile) then
    CreateTools(Paths.ToolsFile);

  //Check is the Emulators.ini file exists, if it doesnt - create it
  if not fileexists(Paths.EmulatorsFile) then
    CreateEmulators(Paths.EmulatorsFile);

   //Check is the MediaPanelCfg.ini file exists, if it doesnt - create it
  if not fileexists(Paths.MediaPanelCfgFile) then
    CreateMediaPanelCfg(Paths.MediaPanelCfgFile);

  //make sure the Data directory exists.
  if not DirectoryExists(Paths.ROMSDir) then
  begin
    If not _NoDats then
      MessageDlg(QP_ROMS_DATA_DIR_NOT_FOUND, mtInformation, [mbOK], 0);
    if not CreateDir(Paths.ROMSDir) then //create the directory specified.
      raise Exception.Create(J_CREATE_DIR_FAILED);
    if not CreateDir(Paths.ROMSDir+'quickplay') then //create the directory specified.
      raise Exception.Create(J_CREATE_DIR_FAILED);
  end;

 end;

{-----------------------------------------------------------------------------}

constructor TQPSettings.Create;
begin

  inherited Create();

  _RatingsCustom := TStringList.Create;

  _DatsUpToDate := True;

  PathSetup;

  If not _AllowWrite then
    MessageDlg(QP_DRIVE_READ_ONLY, mtWarning, [mbOK], 0);

  //set up the window
  SetupWindow();

  //Set up the window size and other settings from the registry
  LoadIni();
end;

{-----------------------------------------------------------------------------}

destructor TQPSettings.Destroy;
begin
  FreeAndNil(_RatingsCustom);
  inherited Destroy();
end;

{-----------------------------------------------------------------------------}

procedure TQPSettings.Ratings(Cmb : TComboBox);
var
  tmpList : TStrings;
begin
  tmpList := TStringList.Create;
  try
    Self.Ratings(tmpList);
    cmb.Items.AddStrings(tmpList);
  finally
    FreeandNil(tmpList);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TQPSettings.Ratings(var strList : TStrings);
var
  i : Integer;
begin
  //first clear the list.
  strList.Clear;
  Case _qprRatingsMode of
    qprDefault :
      begin
        strList.Add(QP_RATING_5);
        strList.Add(QP_RATING_4);
        strList.Add(QP_RATING_3);
        strList.Add(QP_RATING_2);
        strList.Add(QP_RATING_1);
      end;

    qprStars :
      begin
        strList.Add('*****');
        strList.Add('****');
        strList.Add('***');
        strList.Add('**');
        strList.Add('*');
      end;

    qprNumeric :
      begin
        if _RatingsRangeLow < _RatingsRangeHigh then
        begin
          for i := Self._RatingsRangeLow to _RatingsRangeHigh do
            StrList.Add(IntToStr(i));
        end
        else
        begin
          for i := Self._RatingsRangeLow downto _RatingsRangeHigh do
            StrList.Add(IntToStr(i));
        end;
      end;

    qprCustom :
      begin
        strList.AddStrings(SElf._RatingsCustom);
      end;
      
  end;
end;

{-----------------------------------------------------------------------------}

procedure TQPSettings.RestoreData(DataFile : TFileName);
begin

  //if we cant write to disk there's no point going on
  If _AllowWrite = false then
    raise EJWarning.Create(J_DRIVE_READ_ONLY_SHORT);

  //first we delete the QP Data directories.
  DelTree(Paths.ROMSDir);
  DelTree(Paths.CfgDir);
  DelTree(Paths.SearchDir);
  uQPCompObj.Compression.UnCompressFile(DataFile, Paths.AppDir, False, True, True);

end;
{-----------------------------------------------------------------------------}

Procedure TQPSettings.SaveAllSettings();
var
  Ini : TMemIniFile;
  TmpStream : TMemoryStream;
begin
  Ini := TMemIniFile.create(Paths.SettingsFile);
  try

    Ini.EraseSection('Main');

    //General Options
    Ini.WriteBool('Main', 'CheckForUpdatesOnStart', _CheckForUpdatesOnStart);
    Ini.WriteBool('Main', 'ChkAutoDel', _bAutoDel);
    Ini.WriteBool('Main', 'ChkMinimise', _bMiniOnRun);
    Ini.WriteBool('Main', 'ChkOldMini', _bOldMini);
    Ini.WriteBool('Main', 'ChkRunDlg', _bUseRunDLG);
    Ini.WriteBool('Main', 'ChkClearFilter', _bClearFilter);
    Ini.WriteBool('Main', 'ChkRememberROM', _bRememberROM);
    Ini.WriteBool('Main', 'ChkJoy', _bJoy);

    Ini.WriteInteger('Main', 'TempExtrDir', Integer(RunOptions.ExtractMode));
    Ini.WriteString('Main', 'PwrScheme', RunOptions.GeneralPowerScheme);

    Ini.WriteBool('IconThread', 'Emus', _bUseRealEmuIcons);
    Ini.WriteBool('IconThread', 'Tools', self._bUseRealToolIcons);

    //MAME Options
    Ini.WriteString('MAME', 'MameExtrasPath', self._sMameExtrasDir);
    Ini.WriteString('MAME', 'MameXMLPath', self._sMameXMLPath);
    Ini.WriteString('MAME', 'MameXMLVersion', self._sMameXMLVersion);
    Ini.WriteString('MAME', 'MametoolMameExeName', self._sMametoolMameExeName);
    Ini.WriteString('MAME', 'MametoolMameExePath', self._sMametoolMameExePath);
    Ini.WriteString('MAME', 'MameFileManagerFilePath', self._sMameFileManagerFilePath);
    Ini.WriteBool('MAME', 'MameFilePaths', self._bMameFilePaths);
    Ini.WriteString('MAME', 'MameZipType', self._sMameZipType);
    Ini.WriteString('MAME',  'MameFilePathsRomsType', self._sMameFilePathsRomsType);
    Ini.WriteString('MAME', 'MameRomPath', self._sMameRomPath);

    //and here's all the checboxes from the mame printer
    Ini.WriteBool('MAME', 'MameOptBios', Self._bMameOptBios);
    Ini.WriteBool('MAME', 'MameOptCasino', Self._bMameOptCasino);
    Ini.WriteBool('MAME', 'MameOptClones', Self._bMameOptClones);
    Ini.WriteBool('MAME', 'MameOptMature', Self._bMameOptMature);
    Ini.WriteBool('MAME', 'MameOptMechanical', Self._bMameOptMechanical);
    Ini.WriteBool('MAME', 'MameOptMess', Self._bMameOptMess);
    Ini.WriteBool('MAME', 'MameOptPreliminary', Self._bMameOptPreliminary);
    Ini.WriteBool('MAME', 'MameOptPrintClub', Self._bMameOptPrintClub);
    Ini.WriteBool('MAME', 'MameOptSimulator', Self._bMameOptSimulator);
    Ini.WriteBool('MAME', 'MameOptTableTop', Self._bMameOptTableTop);
    Ini.WriteBool('MAME', 'MameOptQuiz', Self._bMameOptQuiz);
    Ini.WriteBool('MAME', 'MameOptUtilities', Self._bMameOptUtilities);
    Ini.WriteBool('MAME', 'MameOptCompany', Self._bMameOptCompany);
    Ini.WriteBool('MAME', 'MameOptGenre', Self._bMameOptGenre);
    Ini.WriteBool('MAME', 'MameOptNPlayers', Self._bMameOptNPlayers);
    Ini.WriteBool('MAME', 'MameOptRating', Self._bMameOptRating);
    Ini.WriteBool('MAME', 'MameOptSeries', Self._bMameOptSeries);
    Ini.WriteBool('MAME', 'MameOptVersion', Self._bMameOptVersion);
    Ini.WriteBool('MAME', 'MameOptYear', Self._bMameOptYear);

    //ROM list options
    Ini.WriteBool('RomOptions', 'chkIncVersion', _bIncVersion);
    Ini.WriteInteger('VTRoms', 'IconSize', _iIconSize);
    Ini.WriteInteger('VTDir', 'IconSizeDir', _iIconSizeDir);

    Ini.WriteBool('RomOptions', 'ChkCol', _bSaveCols);
    Ini.WriteBool('RomOptions', 'ChkListImages', _bRomImages);

    //Ratings Settings
    Ini.WriteInteger('Ratings', 'Mode', Integer(_qprRatingsMode));
    Ini.WriteInteger('Ratings', 'low', Self._RatingsRangeLow);
    Ini.WriteInteger('Ratings', 'high', Self._RatingsRangeHigh);
    tmpStream := TMemoryStream.Create;
    try
      _RatingsCustom.SaveToStream(tmpStream);
      tmpStream.Position := 0;
      Ini.WriteBinaryStream('Ratings', 'Custom', TmpStream);
    finally
      FreeAndNil(tmpStream);
    end;

 //   write wallpaper settings
    Ini.WriteString('VTDir', 'BGImage', _bg.DirBG);
    Ini.WriteString('VTROMS', 'BGImage', _bg.ROMBG);
    Ini.WriteString('VTSearch', 'BGImage', _bg.SearchBG);
    Ini.WriteString('VTEmus', 'BGImage', _bg.EmuBG);
    Ini.WriteString('VTTools', 'BGImage', _bg.ToolBG);

    Ini.WriteBool('Sidebar', 'ShowTabs', _ShowTabsInSideBar);
    Ini.WriteInteger('Main', 'DirExpandMode', Integer(_FolderExpandMode));

    // finally update the ini file on disk to reflect our changes.
    if MainFrm.Settings.AllowWrite then
      Ini.UpdateFile;
      
  finally
    FreeAndNil(Ini);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TQPSettings.SaveUISettings;
Var
  Ini : TMemIniFile;
  I : Integer;
begin

  //check that we are 'allowed' to write to the disk
  If not _AllowWrite then
    exit;

  //Create the IniFile object
  Ini := TMemIniFile.Create(Paths.SettingsFile);
  try

    //write the quickplay version to the ini file.
    Ini.WriteString('Version', 'QP', QPVer );

    With MainFrm do
    Begin

    //Write the window size.
    if WindowState <> wsMaximized then
    begin
      Ini.WriteInteger('Windows','Top', Top);
      Ini.WriteInteger('Windows','Left', Left);
      Ini.WriteInteger('Windows','Width', Width);
      Ini.WriteInteger('Windows','Height', Height);
      Ini.WriteBool('Windows', 'IsMaximised', false);
    end
    else
      Ini.WriteBool('Windows', 'IsMaximised', true);

    Ini.WriteInteger('Windows', 'WindowLayout', MainFrm.WindowLayout);
    Ini.WriteInteger('Layout-'+IntToStr(MainFrm.WindowLayout), 'DirHorz', MainFrm.SplitDirHorz);
    Ini.WriteInteger('Layout-'+IntToStr(MainFrm.WindowLayout), 'ImgHorz', MainFrm.SplitImgHorz);
    Ini.WriteInteger('Layout-'+IntToStr(MainFrm.WindowLayout), 'DirVert', MainFrm.SplitDirVert);
    Ini.WriteInteger('Layout-'+IntToStr(MainFrm.WindowLayout), 'ImgVert', MainFrm.SplitImgVert);

    //Save the column widths.
    if _bSaveCols = true then
    Begin
      Ini.EraseSection('ColSize');
      For i := 0 to VTRoms.Header.Columns.Count-1 do
        Ini.WriteInteger('ColSize', IntToStr(i), VTRoms.Header.Columns[i].Width);
    end;

    //save the currently SORTED column value and its direction
    Ini.WriteInteger('Windows', 'SortColumn', VTRoms.Header.SortColumn);
    If VTRoms.Header.SortDirection = sdAscending then
      Ini.WriteBool('Windows', 'SortAsc', true)
    else
      Ini.WriteBool('Windows', 'SortAsc', false);

    //save the column positions
    Ini.EraseSection('ColPos');
    For I := 0 to VTRoms.Header.Columns.Count-1 do
    Begin
      Ini.WriteInteger('ColPos', IntToStr(I), VTRoms.Header.Columns.Items[i].Position);
    end;

    //save the status of the image panel
    Ini.WriteBool('Windows', 'ShowImg', pgMediaPanel.Visible);

    //save whether the ROM toolbar is visible
    Ini.WriteBool('Windows', 'ShowRBar', TBRoms.Visible);

    //save whether the Dir toolbar is visible
    Ini.WriteBool('Windows', 'ShowDBar', TBDir.Visible);

    //save whether the filter txtbox is visible
    Ini.WriteBool('Windows', 'ShowFilter', PanFilter.Visible);

    Ini.UpdateFile;

    end; //end of WITH MainFrm

  finally
    FreeAndNil(ini);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TQPSettings.SaveDefaultColumns(cols : array of Boolean);
var
  Ini : TMemIniFile;
  i : Integer;
begin
  //check that we are 'allowed' to write to the disk
  If not _AllowWrite then
    exit;

  Ini := TMemIniFile.Create(Paths.SettingsFile);
  Try
    //save the default columns
    Ini.EraseSection('ColView');
    for i := 0 to Length(Cols)-1 do
      Ini.WriteBool('ColView', IntToStr(i), Cols[i]);

    Ini.UpdateFile;
    
  finally
    FreeAndNil(Ini);
  end;
end;

{-----------------------------------------------------------------------------}

Procedure TQPSettings.SaveCurrentROM(Dir : String; ROM : TObject);
var
  Ini : TMemIniFile;
begin

  //check that we are 'allowed' to write to the disk
  If not _AllowWrite then
    exit;

  Ini := TMemIniFile.Create(Paths.SettingsFile);
  Try

    If Ini.ReadBool('Main', 'ChkRememberROM', false) then
    begin

      //save the current selected directory
      Ini.WriteString('LastROM', 'Dir', Dir);

      If ROM = nil then
      begin
        Ini.WriteString('LastROM', 'ROM', '');
        Ini.WriteInteger('LastROM', 'Type', 1);
      end
      else If TQPROM(ROM).ZipName <> '' then
      begin
        Ini.WriteString('LastROM', 'ROM', TQPROM(ROM).ZipName);
        Ini.WriteInteger('LastROM', 'Type', 3);
      end
      else if TQPROM(ROM).MAMEname <> '' then
      begin
        Ini.WriteString('LastROM', 'ROM', TQPROM(ROM).MAMEname);
        Ini.WriteInteger('LastROM', 'Type', 0);
      end
      else
      begin
        Ini.WriteString('LastROM', 'ROM', TQPROM(ROM).Path);
        Ini.WriteInteger('LastROM', 'Type', 2);
      end;

      
    end //end of Save Last ROM setting.
    else
      If Ini.SectionExists('LastROM') then
        Ini.EraseSection('LastROM');

    Ini.UpdateFile;
    
  Finally
    FreeAndNil(Ini);
  end;

end;
{-----------------------------------------------------------------------------}

Procedure TQPSettings.SetupWindow();
var
  Ini : TMemIniFile;
  Top, Left, Width, Height : Integer;
begin

   Ini := TMemIniFile.Create(Paths.SettingsFile);
   try
     //Set the window size to values stored in Ini File
     Top := Ini.ReadInteger('Windows','Top', 130);
     Left := Ini.ReadInteger('Windows', 'Left', 200);
     Width := Ini.ReadInteger('Windows', 'Width', 800);
     Height := Ini.ReadInteger('Windows', 'Height', 450);
     MainFrm.SetBounds(Left, Top, Width, Height);

     If Ini.ReadBool('Windows', 'IsMaximised', false) then
       MainFrm.WindowState := wsMaximized;

   finally
     FreeAndNil(Ini);
   end;
end;

{-----------------------------------------------------------------------------}

end.
