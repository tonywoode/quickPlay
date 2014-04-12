unit uMediaPanelClasses;

interface

uses Forms, SysUtils, Classes, ComCtrls, Contnrs, uMediaMiscTypes, uMediaSystemClass,
     uROM, uEmu, uTools;

const
  TABEMU = 8500;
  TABTOOL = 8250;
  TABSYS = 8000;
  TABQUICKPLAY = 9000;

type

  TJMediaSearch = class(TObject)
  protected
    _pgc : TPageControl;
    _Systems : TObjectList;
    _TabArray : array of TTabRec;

    //Cache and internal search variables.
    _CacheLoadedSystem : String;
    _CacheLoadedEmu : String;
    _CacheROM : TQPROM;
    _CacheEmu : TQPEmu;
    _CacheTool : TQPTool;

    _CfgDir : String;
    _SystemsFile : TFileName;
    _SystemsCfg : TFileName;

    _AddEmuTab : Boolean;
    _TabFile : TFileName;
    _TabNavigation : TJTabNavigationType;
    _AutoMove : Boolean;
    _TimePerTab : Integer;
    _DefaultFolderImg : TJMediaFolderImg;

    procedure AddPanel(fclass : TFormClass; NewTag : Integer; Caption : String);

    //Functions for properties
    Function GetSystem(Index : Integer) : TJMediaSystem;
    procedure SetSystem(Index : Integer; value : TJMediaSystem);
    Function GetTab(Index : Integer) : TTabRec;
    procedure SetTab(Index : Integer; aTab : TTabRec);
    Function GetSystemCount() : Integer;
    Function GetTabCount() : Integer;
  public
    constructor Create(StorageDir : String);
    destructor Destroy();override;

    //tab handling functions.
    procedure AddDefaultTab(Caption : String; DefaultType : TJTabType);
    procedure BuildPageControl(SysOnly : String);overload;
    procedure BuildPageControl(ROM : PQPROM; EMU : PQPEmu; Tool : pQPtool);overload;
    procedure DoTabChange(Sender : TObject);
    procedure DoResize(Sender: TObject);
    procedure CreateDefaultTabFile(aFile : TFileName);
    procedure DeleteDefaultTab(Index : Integer);
    procedure PopulateTab(ActiveTab : Integer; TabIndex : Integer);
    procedure LoadTabs();
    procedure SaveTabs();

    //system handling functions
    Function SystemIndexOf(Sys : String) : Integer;
    procedure LoadSystems();
    procedure SaveSystems();

    // media core functions
    procedure LoadConfig();
    procedure SaveConfig();

    property Systems[Index: Integer]: TJMediaSystem read GetSystem write SetSystem; default;
    property Tabs[Index: Integer]: TTabRec read GetTab write SetTab;

    Property AddEmuTab : Boolean read _AddEmuTab write _AddEmuTab;
    Property AutoMove : Boolean read _AutoMove write _AutoMove;
    Property TimePerTab : Integer read _TimePerTab write _TimePerTab;

    Property PageControl : TPageControl read _pgc write _pgc;
    Property SystemCount : Integer read GetSystemCount;
    Property TabCount : Integer read GetTabCount;
    Property TabNavigation : TJTabNavigationType read _TabNavigation write _TabNavigation;
    Property DefaultFolderImg : TJMediaFolderImg read _DefaultFolderImg write _DefaultFolderImg;
  end;

implementation

uses Controls, IniFiles, JCLStrings, ftabImageViewer, ftabTextOnly,
  ftabThumbBrowser, ftabQuickPlay, ftabSysEmu;

{-----------------------------------------------------------------------------}

constructor TJMediaSearch.Create(StorageDir : String);
begin
  inherited Create();

  _cfgDir := StorageDir;
  _SystemsFile := StorageDir + 'systems.dat';
  _SystemsCfg := StorageDir + 'MediaPanelCfg.ini';

  _CacheLoadedSystem := 'FUCKINGNULL';
  _CacheLoadedEmu := 'FUCKINGNULL';

  _Tabfile := StorageDir + 'DefaultTabs.dat';
  if Not FileExists(_TabFile) then
    Self.CreateDefaultTabFile(_TabFile);

  _Systems := TObjectList.Create(True);

  LoadConfig();
  LoadTabs();
  LoadSystems();


end;

{-----------------------------------------------------------------------------}

destructor TJMediaSearch.Destroy();
begin
  FreeAndNil(_CacheROM);
  FreeAndNil(_CacheEmu);
  FreeAndNil(_CacheTool);
  SetLength(_TabArray, 0);
  _TabArray := nil;
  FreeAndNil(_Systems);
  inherited Destroy();
end;

{-----------------------------------------------------------------------------}
// Code for properties.
{-----------------------------------------------------------------------------}

Function TJMediaSearch.GetSystem(Index : Integer) : TJMediaSystem;
begin
  Result := TJMediaSystem(_Systems[Index]);
end;

{-----------------------------------------------------------------------------}

procedure TJMediaSearch.SetSystem(Index : Integer; value : TJMediaSystem);
begin
  _Systems[Index] := Value;
end;

{-----------------------------------------------------------------------------}

Function TJMediaSearch.GetTab(Index : Integer) : TTabRec;
begin
  Result := _TabArray[Index];
end;
{-----------------------------------------------------------------------------}

procedure TJMediaSearch.SetTab(Index : Integer; aTab : TTabRec);
begin
  _TabArray[Index] := aTab;
end;

{-----------------------------------------------------------------------------}

Function TJMediaSearch.GetSystemCount() : Integer;
begin
  Result := _Systems.Count;
end;

{-----------------------------------------------------------------------------}

Function TJMediaSearch.GetTabCount() : Integer;
begin
  Result := Length(_TabArray);
end;

{-----------------------------------------------------------------------------}
// Core code.
{-----------------------------------------------------------------------------}

//Adds a new tab record to the internal tablist.
procedure TJMediaSearch.AddDefaultTab(Caption : String; DefaultType : TJTabType);
var
  i : Integer;
  Exists : Boolean;
begin
  //check that the name isnt currently in use.
  Exists := False;
  for i := 0 to High(_TabArray) do
    if JCLStrings.StrCompare( _TabArray[i].Name, Caption ) = 0 then
    begin
      Exists := True;
      break;
    end;

  if not Exists then
  begin
    //expand the array
    SetLength(_TabArray, Length(_TabArray)+1);
    i := High(_TabArray);
    _TabArray[i].Name := Caption;
    _TabArray[i].DefaultType := DefaultType;   
  end 
  else
    Exception.Create('A tab with this name already exists');
end;

{-----------------------------------------------------------------------------}

// Adds a tab to the page control
procedure TJMediaSearch.AddPanel(fclass : TFormClass; NewTag : Integer; Caption : String);
var
  NewTab : TTabSheet;
  NewPanel: TForm;
begin
    if Assigned(fclass) then
    begin

      NewTab := TTabSheet.Create(_pgc);
      NewTab.PageControl := _pgc;
      NewTab.Tag := NewTag;
      NewTab.Caption := Caption;
      NewTab.BorderWidth := 0;
      NewTab.TabVisible := True;   
      NewPanel := fclass.Create(NewTab);
      NewPanel.Hide;
      NewPanel.BorderStyle := bsNone;
      NewPanel.Parent := NewTab;
      NewPanel.Align := alClient;
      NewPanel.Show;
    end;
end;

{-----------------------------------------------------------------------------}

procedure TJMediaSearch.BuildPageControl(SysOnly : String);
var
  i : Integer;
  SysIndex : Integer;
  Sys : TJMediaSystem;
begin
  if _pgc = nil then
  begin
    Exception.Create('Page Control not specified');
    exit;
  end;

  //first step is to erase all current tabs.
  for i := _pgc.PageCount-1 downto 0 do
    _pgc.Pages[i].Free;

  _CacheLoadedSystem := '';
  _CacheLoadedEmu := '';
  FreeAndNil(_CacheEmu);
  FreeAndNil(_CacheROM);
  FreeAndNil(_CacheTool);

  SysIndex := Self.SystemIndexOf(SysOnly);
  if SysIndex <> -1 then
  begin
    Sys := TJMediaSystem(_Systems[SysIndex]);
    if FileExists(Sys.SystemImage) then
    begin
      AddPanel(tTabSysEmu, TABSYS, 'System');
      tTabSysEmu(_pgc.Pages[0].Controls[0]).Configure(Sys.SystemImage, Sys.ShowInfo, Sys.AdditionalInfo, '');
    end
    else
      AddPanel(TTabQuickPlay, TABQUICKPLAY, 'QuickPlay');
  end
  else
    //this system wasnt found, use the default Quickplay Logo
    AddPanel(TTabQuickPlay, TABQUICKPLAY, 'QuickPlay');

  _pgc.Pages[0].TabVisible := False;
  //initialise the first tab.
  PopulateTab(0, _pgc.Pages[0].Tag);
  _pgc.ActivePageIndex := 0;
end;

{-----------------------------------------------------------------------------}

procedure TJMediaSearch.BuildPageControl(ROM : PQPROM; EMU : PQPEmu; Tool : pQPtool);
var
  SysIndex, i : Integer;
  Sys : TJMediaSystem;
  UseQPTab : Boolean;
  CurrentTab : String;
  Moveto : Integer;
begin
  if _pgc = nil then
  begin
    Exception.Create('Page Control not specified');
    exit;
  end;

  UseQPTab := True;

  CurrentTab := _pgc.ActivePage.Caption;

  if (Emu = nil) or (Emu^ = nil) then
  begin

    //if the 'QP' tab is currently loaded, no need to carry on.
    if (_CacheLoadedSystem = '') and (_CacheLoadedEmu = '') then
      Exit;

    _CacheLoadedSystem := '';
    _CacheLoadedEmu := '';
    FreeAndNil(_CacheEmu);
    FreeAndNil(_CacheROM);
    FreeAndNil(_CacheTool);

    //first step is to erase all current tabs.
    for i := _pgc.PageCount-1 downto 0 do
      _pgc.Pages[i].Free;

  end
  else
  begin

    //first of all get the system for this emulator.
    SysIndex := Self.SystemIndexOf(Emu^.System);

    if SysIndex > -1 then
    begin
      Sys := TJMediaSystem(_Systems[SysIndex]);

      if (JCLStrings.StrCompare(_CacheLoadedSystem, Sys.Caption) <> 0) or
         (JCLStrings.StrCompare(_CacheLoadedEmu, Emu^.Name) <> 0) then
      begin
        //erase all current tabs.
        for i := _pgc.PageCount-1 downto 0 do
          _pgc.Pages[i].Free;

        if Emu^.ShowExeTab then
          AddPanel(tTabSysEmu, TABEMU, Emu^.Name);

        if (tool <> nil) and (tool^.ShowExeTab) then
          AddPanel(tTabSysEmu, TABTOOL, Tool^.Name);

        for i := 0 to Sys.TabCount-1 do
          if Sys.Tabs[i].Enabled then
          begin
            UseQPTab := False;
            Case Sys.Tabs[i].TabType of
              jtabImages: AddPanel(tTabImageViewer, i, Sys.Tabs[i].Caption);
              jtabMameInfo: AddPanel(tTabTextOnly, i, Sys.Tabs[i].Caption);
              jtabMameHistory: AddPanel(tTabTextOnly, i, Sys.Tabs[i].Caption);
              jtabThumbnail: AddPanel(TtabThumbBrowser, i, Sys.Tabs[i].Caption);
              jtabSystem :
              begin
                AddPanel(tTabSysEmu, TABSYS, 'System');
                tTabSysEmu(_pgc.Pages[_PGC.PageCount-1].Controls[0]).Configure(Sys.SystemImage, Sys.ShowInfo, Sys.AdditionalInfo, '');
              end;
            end;//end of CASE statment

          end;

      end  //end of if emu has changed check
      else
        UseQPTab := False; //we arent changing the tabs, so it should already be there

      //populate the cache variables.

      _CacheLoadedSystem := Sys.Caption;
      _CacheLoadedEmu := Emu^.Name;

      if (Rom <> nil) and (ROM^ <> nil) then
      begin
        if _CacheROM = nil then
          _CacheROM := TQPROM.Create;
        _CacheROM.Assign(ROM^);
      end
      else
        FreeAndNil(_cacheROM);

      if _CacheEmu = nil then
        _CacheEmu := TQPEmu.Create;

      _CacheEmu.Assign(Emu^);

      if (Tool <> nil) and (Tool^ <> nil) then
      begin
        if _CacheTool = nil then
          _CacheTool := TQPTool.Create;
        _CacheTool.Assign(Tool^);
      end
      else
        FreeAndNil(_cacheTool);

    end; //end of valid sysindex found.

  end;  //end of if Emu^ = nil ELSE!

  //after checking for above tabs, check that SOME tab is added
  if (UseQPTab) and (_pgc.PageCount = 0) then
    AddPanel(TTabQuickPlay, TABQUICKPLAY, 'QuickPlay');

  if _pgc.PageCount = 1 then
  begin
    //no need for the tabs, or control bar
    _pgc.Pages[0].TabVisible := False;
  end;

  //initialise the first tab.
  Moveto := 0;
  for i := 0 to _pgc.PageCount - 1 do
  begin
    if JCLStrings.StrCompare(_pgc.Pages[i].Caption, CurrentTab)=0 then
    begin
      Moveto := i;
      Break;
    end;
  end;

  PopulateTab(Moveto, _pgc.Pages[Moveto].Tag);

  _pgc.ActivePageIndex := Moveto;

end;

{-----------------------------------------------------------------------------}

procedure TJMediaSearch.CreateDefaultTabFile(aFile : TFileName);
var
  tmpStr : TStringList;
begin

  tmpStr := TStringList.Create;
  try
    tmpStr.Capacity := 8;
    tmpStr.Add('System Info=4');
    tmpStr.Add('General=3');
    tmpStr.Add('Box=0');
    tmpStr.Add('Cart=0');
    tmpStr.Add('Flyers=0');
    tmpStr.Add('Game History=2');
    tmpStr.Add('Game Info=1');
    tmpStr.Add('Marquees=0');
    tmpStr.Add('Samples=0');
    tmpStr.Add('ScreenShots=0');
    tmpStr.Add('Titles=0');
    tmpStr.SaveToFile(aFile);
  finally
    FreeAndNil(tmpStr);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TJMediaSearch.DeleteDefaultTab(Index : Integer);
var
  i, ix : Integer;
  sys : TJMediaSystem;
begin
  //if the index passed isnt in the array, drop out.
  if (Index > High(_TabArray)) or (Index < Low(_TabArray)) then Exit;

  //loop through each system and remove the Tab if its present.
  for i := 0 to Self._Systems.Count-1 do
  begin
    Sys :=  TJMediaSystem(_Systems[i]);
    for ix := 0 to Sys.TabCount-1 do
    begin
      if JCLStrings.StrCompare(Sys.Tabs[ix].Caption, _TabArray[Index].Name) = 0 then
      begin
        Sys.DeleteTab(ix);
        Break;
      end;
    end;
  end;

  //if the index is last in the array, just chop it off the end.
  if Index = High(_TabArray) then
  begin
    SetLength(_TabArray, Length(_TabArray) - 1);
  end
  else
  begin
    //other remove the array element and move the array around a bit.
    Finalize(_TabArray[Index]);
    System.Move(_TabArray[Index +1], _TabArray[Index],
    (Length(_TabArray) - Index -1) * SizeOf(TTabRec) + 1);
    SetLength(_TabArray, Length(_TabArray) - 1);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TJMediaSearch.DoTabChange(Sender : TObject);
begin
  PopulateTab(_pgc.ActivePageIndex, _Pgc.Pages[_pgc.ActivePageIndex].Tag);
end;

{-----------------------------------------------------------------------------}
procedure TJMediaSearch.DoResize(Sender: TObject);
var test : TPageControl;
 test1 : Integer;
 test2 : TtabThumbBrowser;
 windowWidth : Integer;
 windowHeight : Integer;
 i  : integer ;

begin
//well the idea here was to get the image zize and media panel size.
//then if greater resize the image
// I can no get to the imaee?


//image := self.
//the media panel has change check the image size.

//   test1 := test.GetTabCount();
//  test := self.PageControl;
//    for i := 0 to test.PageCount -1  do
//    begin
//      //test1 := test.Pages[i].Height; // not the file size hight... just the page.
//       test1 := test.Pages[i].ImageIndex;
//        test1 :=    test.ParentWindow ;



      // test1 := test.Images[i]. ;
//      if  test.ExplicitHeight > test.Pages[i].Height then
//      begin
//       test1 := 0;
//      end;

//    end;


//  windowWidth := test.ExplicitWidth;   //width of the media window.
//  windowHeight := test.ExplicitHeight;   //hieght of the media window.
//   test1 := Sender.InstanceSize;


end;
{-----------------------------------------------------------------------------}

procedure TJMediaSearch.LoadConfig();
var
  Ini : TMemIniFile;
begin
  Ini := TMemIniFile.Create(_SystemsCfg);
  try

    _AddEmuTab := Ini.ReadBool('MediaSettings', 'AddEmuTab', True);
    _AutoMove := Ini.ReadBool('MediaSettings', 'AutoMove', True);
    _TimePerTab := Ini.ReadInteger('MediaSettings', 'TimePerTab', 10);
    _DefaultFolderImg := TJMediaFolderImg(Ini.ReadInteger('MediaSettings', 'DefaultFolderImg', 0));
    //_TabNavigation := TJTabNavigationType(Ini.readInteger('MediaSettings', 'TabNavigation', 0));

    //_CacheLoadedEmu := '';
    //_CacheLoadedSystem := '';
  finally
    FreeAndNil(Ini);
  end;

end;

{-----------------------------------------------------------------------------}

procedure TJMediaSearch.LoadSystems();
var
  Ini : TMemIniFile;
  inSys : TStringList;
  i, NewIndex : Integer;
begin

  _Systems.Clear;
  
  Ini := TMemIniFile.Create(_SystemsCfg);
  try

    inSys := TStringList.Create;
    try
      if FileExists(_SystemsFile) then
        inSys.LoadFromFile(_SystemsFile);

      _Systems.Capacity := InSys.Count;
    
      for i := 0 to inSys.Count-1 do
      begin
        newIndex := _Systems.Add(TJMediaSystem.Create(inSys[i]));
        TJMediaSystem(_Systems[newIndex]).LoadFromIni(ini);
      end;
      
    finally
      FreeAndNil(inSys);
    end;
    
  finally
    FreeAndNil(ini);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TJMediaSearch.LoadTabs();
var
  inFile : TStringList;
  i : Integer;
begin
  inFile := TStringList.Create;
  try
    if FileExists(_Tabfile) then
      inFile.LoadFromFile(_Tabfile);

    //get rid of any blank lines from the file.
    for i := inFile.Count-1 downto 0 do
      if inFile[i] = '' then
        inFile.Delete(i);

    //check for the existance of the system tab.  it should ALWAYS be in the file.
    if infile.IndexOf('System Info=4') = -1 then
    begin
      infile.Add('System Info=4');
      infile.SaveToFile(_Tabfile);
    end;

    //set the size of the tabs array.
    SetLength(_TabArray, inFile.Count);
    for i := 0 to inFile.Count-1 do
    begin
      _TabArray[i].Name := inFile.Names[i];
      _TabArray[i].DefaultType := TJTabType(StrToInt(inFile.ValueFromIndex[i]));
    end;
    
  finally
    FreeAndNil(inFile);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TJMediaSearch.PopulateTab(ActiveTab : Integer; TabIndex : Integer);
var
  SystemIndex : Integer;
begin
  // populate the tab with *WHATEVER* data it uses.
  // basically check the tabs array for what type of tab it is, and then
  // use that tab object to do the work.

  //we ignore system info tabs as these are populated when created.
  if (TabIndex = TABSYS) or (TabIndex = TABQUICKPLAY) then
    exit;

  if (tabIndex = TABTOOL) then
  begin
        tTabSysEmu(_pgc.Pages[ActiveTab].Controls[0]).Configure(_CacheTool.ExeImage, _CacheTool.ShowAddInfo, _CacheTool.AdditionalInfo, _CacheTool.HomePage)
  end;
  //check if the tab is a emulator or tools tab.
  if TabIndex = TABTOOL then
    tTabSysEmu(_pgc.Pages[ActiveTab].Controls[0]).Configure(_CacheTool.ExeImage, _CacheTool.ShowAddInfo, _CacheTool.AdditionalInfo, _CacheTool.HomePage)
  else if TabIndex = TABEMU then
    tTabSysEmu(_pgc.Pages[ActiveTab].Controls[0]).Configure(_CacheEmu.ExeImage, _CacheEmu.ShowAddInfo, _CacheEmu.AdditionalInfo, _CacheEmu.HomePage)
  else
  begin
    //its a rom tab.

    //get the system first.
    SystemIndex := SystemIndexOf(_CacheEmu.System);
    if SystemIndex <> -1 then
      TJMediaSystem(_Systems[SystemIndex]).Tabs[TabIndex].PopulateTab(_pgc.Pages[ActiveTab], _CacheROM, Self._CfgDir);

  end;
end;

{-----------------------------------------------------------------------------}

procedure TJMediaSearch.SaveConfig();
var
  Ini : TMemIniFile;
begin
  Ini := TMemIniFile.Create(_SystemsCfg);
  try

    Ini.WriteBool('MediaSettings', 'AddEmuTab', _AddEmuTab);
    Ini.WriteBool('MediaSettings', 'AutoMove', _AutoMove);
    Ini.WriteInteger('MediaSettings', 'TimePerTab', _TimePerTab);
    Ini.WriteInteger('MediaSettings', 'DefaultFolderImg', Integer(_DefaultFolderImg));
    //Ini.WriteInteger('MediaSettings', 'TabNavigation', Integer(_TabNavigation));

    Ini.UpdateFile;

    _CacheLoadedEmu := '';
    _CacheLoadedSystem := '';

  finally
    FreeAndNil(Ini);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TJMediaSearch.SaveSystems();
var
  i : Integer;
  ini : TMemIniFile;
begin
  ini := TMemIniFile.Create(_SystemsCfg);
  try

    for i := 0 to _Systems.Count-1 do
      TJMediaSystem(_Systems[i]).SaveToIni(Ini);

    Ini.UpdateFile;
    
  finally
    FreeAndNil(Ini);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TJMediaSearch.SaveTabs();
var
  outFile : TStringList;
  i : Integer;
begin

  outFile := TStringList.Create;
  Try

    OutFile.Capacity := Length(_TabArray);
    for i := 0 to High(_TabArray) do
      OutFile.Add(_TabArray[i].Name + '=' + IntToStr( Integer(_TabArray[i].DefaultType) ) );

    OutFile.SaveToFile(_Tabfile);

  Finally
    FreeAndNil(outFile);
  end;
end;

{-----------------------------------------------------------------------------}

Function TJMediaSearch.SystemIndexOf(Sys : String) : Integer;
var
  i : Integer;
begin
  Result := -1;
  for i := 0 to _Systems.Count-1 do
    if JCLSTrings.StrCompare(Sys, TJMediaSystem(_Systems[i]).Caption) = 0 then
    begin
      Result := i;
      Break;
    end;
end;

{-----------------------------------------------------------------------------}


end.
