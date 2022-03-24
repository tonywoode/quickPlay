unit MainUnit;

interface

uses
  Windows, Messages, SysUtils, {Variants,} Classes, Graphics, Controls, Forms,
  Dialogs, Menus, ExtCtrls, StdCtrls, Tabs;//, AppEvnts;

type
  TConfigs = (cfUseCompressed, cfIntSFX,
    cfKeepBackward, cfAllow2G, cfNoSpan, cfStaticLoad, cfNone);

type
  TForm1 = class(TForm)
    About1:  TMenuItem;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    CheckBox1: TCheckBox;
    edFile:  TEdit;
    Edit1:   TMenuItem;
    Exit1:   TMenuItem;
    Files1:  TMenuItem;
    Label1:  TLabel;
    lblDefault: TLabel;
    MainMenu1: TMainMenu;
    Memo1:   TMemo;
    N1:      TMenuItem;
    Open1:   TMenuItem;
    Panel1:  TPanel;
    Panel2:  TPanel;
    Panel3:  TPanel;
    Save1:   TMenuItem;
    TabSet1: TTabSet;
    lblChanged: TLabel;
    OpenDialog1: TOpenDialog;
    Language1: TMenuItem;
    Open2:   TMenuItem;
    about2:  TMenuItem;
    procedure about2Click(Sender: TObject);
    procedure ApplicationIdle(Sender: TObject; var Done: boolean);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure edFileChange(Sender: TObject);
    procedure Exit1Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure Open1Click(Sender: TObject);
    procedure Open2Click(Sender: TObject);
  private
    FConfigLoaded: boolean;
    FDefinitions: TStringList;
    NStt:     array[TConfigs] of integer;
    fOrig:    array[TConfigs] of boolean;
    FShowing: TConfigs;
    fVals:    array[TConfigs] of boolean;
    function GetConfig(Index: TConfigs): boolean;
    function GetConfigDefault(Index: TConfigs): boolean;
    function GetConfigOrig(Index: TConfigs): boolean;
    function GetConfigStr(Index: TConfigs): string;
    function GetDefinitions: TStringList;
    function GetDefinitionStart(Index: TConfigs): integer;
    procedure SetConfig(Index: TConfigs; const Value: boolean);
    procedure SetConfigOrig(Index: TConfigs; const Value: boolean);
    property Showing: TConfigs Read FShowing Write FShowing;
  protected
    fConfFile: TStringList;
    TabIdx:    integer;
    function Dirty: boolean;
    function IsConfig(const str: string): integer;
    function IsHeading(const txt: string): TConfigs;
    procedure NoConfig;
    procedure NoDefinitions;
    function NotDefault: boolean;
    function ReadConfigFile(const fname: string): integer;
    function ReadDefinitions(const fname: string): integer;
    procedure ShowDefinitions(Idx: TConfigs);
    procedure UpdateSettings(tabNo: TConfigs);
    function WriteConfigFile(const fname: string): integer;
    property ConfigLoaded: boolean Read FConfigLoaded Write FConfigLoaded;
    property Definitions: TStringList Read GetDefinitions;
    property DefinitionStart[Index: TConfigs]: integer Read GetDefinitionStart;
  public
    property Config[Index: TConfigs]: boolean Read GetConfig Write SetConfig;
    property ConfigDefault[Index: TConfigs]: boolean Read GetConfigDefault;
    property ConfigOrig[Index: TConfigs]: boolean
      Read GetConfigOrig Write SetConfigOrig;
    property ConfigStr[Index: TConfigs]: string Read GetConfigStr;
  end;

var
  Form1: TForm1;

implementation

uses About;

{$R *.dfm}

const
  confStr: array [cfUseCompressed .. cfNone{cfStaticLoad}] of string =
    ('USE_COMPRESSED_STRINGS', 'INTERNAL_SFX',
    'KEEP_BACKWARD', 'ALLOW_2G', 'NO_SPAN', 'STATIC_LOAD_DLL', ' ');
  prefStr: array [cfUseCompressed .. cfNone{cfStaticLoad}] of string =
    (
    '//__ USE_COMPRESSED_STRINGS - undefine to use ResourceStrings',
    '//__ INTERNAL_SFX - define to include internal SFX support',
    '//__ KEEP_BACKWARD - define to keep compatable with previous versions',
    '//__ ALLOW_2G - define to allow OnProgress to work with files > 2G',
    '//__ NO_SPAN - define to remove support for multi-part zip files',
    '//__ STATIC_LOAD_DELZIP_DLL - define to statically load dll',
    ''
    );
  ConfigTitle: string = '// ZipMaster configuration 1.79';
  ConfigName: string ='ZipConfig.inc';
  DefDefinitions: string = 'ZMDefsUS.txt';
  BackupExt: string = '.bak';
               
procedure BackupFile(const where: string);
var
  bakname: string;
begin
  bakname :=where+BackupExt;
  if FileExists(where) then
  begin
    if FileExists(bakname) then
      SysUtils.DeleteFile(bakname);
    SysUtils.RenameFile(where, bakname);
  end;
end;

procedure TForm1.about2Click(Sender: TObject);
begin
  AboutBox.ShowModal;
end;

procedure TForm1.ApplicationIdle(Sender: TObject; var Done: boolean);
const
  defStr: array[boolean] of string = ('undefined', 'defined');
var
  cf: TConfigs;
  ck: boolean;
begin
  if TabIdx < 0 then
    exit;
  if TabIdx <= Ord(cfStaticLoad) then
  begin
    if TabIdx <> TabSet1.TabIndex then
    begin
      Config[TConfigs(TabIdx)] := CheckBox1.Checked;
      TabIdx := TabSet1.TabIndex;
      UpdateSettings(TConfigs(TabIdx));
    end;
    cf := TConfigs(TabIdx);
    ck := CheckBox1.Checked;
    Config[cf] := ck;
    lblDefault.Visible := ck = ConfigDefault[cf];
    lblChanged.Visible := ck <> ConfigOrig[cf];
  end;
  Button4.Enabled := Dirty;
  Button3.Enabled := Dirty;
  Button2.Enabled := NotDefault;
  if ConfigLoaded then
    edFile.Font.Style := []
  else
    edFile.Font.Style := [fsItalic];
end;

// set to defaults
procedure TForm1.Button2Click(Sender: TObject);
var
  cf: TConfigs;
begin
  if NotDefault then
  begin
    for cf := cfUseCompressed to cfStaticLoad do
      Config[cf] := ConfigDefault[cf];
    UpdateSettings(TConfigs(TabIdx));
  end;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
  WriteConfigFile(edFile.Text);
end;

// cancel changes
procedure TForm1.Button4Click(Sender: TObject);
var
  cf: TConfigs;
begin
  if Dirty then
  begin
    for cf := cfUseCompressed to cfStaticLoad do
      Config[cf] := ConfigOrig[cf];
    UpdateSettings(TConfigs(TabIdx));
  end;
end;

function TForm1.Dirty: boolean;
var
  cf: TConfigs;
begin
  Result := True;
  for cf := cfUseCompressed to cfStaticLoad do
    if Config[cf] <> ConfigOrig[cf] then
      exit;
  Result := False;
end;

procedure TForm1.edFileChange(Sender: TObject);
var
  cf: TConfigs;
begin
  //  NoConfig;
  ShowDefinitions(cfNone);
  if ReadConfigFile(edFile.Text) >= 0 then
  begin
    for cf := cfUseCompressed to cfStaticLoad do
      Config[cf] := ConfigOrig[cf];
    TabIdx := 9;
    UpdateSettings(TConfigs(0));
  end;
end;

procedure TForm1.Exit1Click(Sender: TObject);
begin
  Close;
end;

procedure TForm1.FormCreate(Sender: TObject);
var
  cf:   TConfigs;
  root: string;
begin
  ConfigLoaded := False;
  FDefinitions := TStringList.Create;
  TabIdx := -1;   // no updates
  TabSet1.Tabs.Clear;
  for cf := cfUseCompressed to cfStaticLoad do
  begin
    TabSet1.Tabs.Add(ConfigStr[cf]);
    NStt[cf] := -1;
  end;
  ReadDefinitions(DefDefinitions);
  root   := ExpandFileName(ExtractFilePath(Application.ExeName)+ '\..\..');
  TabSet1.TabIndex := 0;
  TabIdx := 0;
  edFile.Text := root + '\' + ConfigName;
  Application.OnIdle := ApplicationIdle;
end;

procedure TForm1.FormDestroy(Sender: TObject);
begin
  if assigned(FDefinitions) then
    FDefinitions.Free;
end;

function TForm1.GetConfig(Index: TConfigs): boolean;
begin
  Result := fVals[Index];
end;

function TForm1.GetConfigDefault(Index: TConfigs): boolean;
begin
  Result := Index in [cfUseCompressed, cfIntSFX, cfAllow2G];
end;

function TForm1.GetConfigOrig(Index: TConfigs): boolean;
begin
  Result := fOrig[Index];
end;

function TForm1.GetConfigStr(Index: TConfigs): string;
begin
  Result := confstr[Index];
end;

function TForm1.GetDefinitions: TStringList;
begin
  Result := FDefinitions;
end;

function TForm1.GetDefinitionStart(Index: TConfigs): integer;
begin
  Result := NStt[Index];
end;

function TForm1.IsConfig(const str: string): integer;
var
  cf: TConfigs;
begin
  Result := -1;
  for cf := cfUseCompressed to cfStaticLoad do
    if str = ConfigStr[cf] then
    begin
      Result := Ord(cf);
      break;
    end;
end;

function TForm1.IsHeading(const txt: string): TConfigs;
var
  cf: TConfigs;
  s:  string;
begin
  Result := cfNone;
  s      := Trim(txt);
  if (S <> '') and (s[1] = '[') and (s[Length(s)] = ']') then
  begin
    s := Trim(copy(s, 2, length(s) - 2));
    for cf := cfUseCompressed to cfStaticLoad do
      if AnsiCompareStr(s, ConfigStr[cf]) = 0 then
      begin
        Result := cf;
        exit;
      end;
  end;
end;

procedure TForm1.NoConfig;
begin
  //    ShowDefinitions(cfNone);
  UpdateSettings(cfNone);
end;

procedure TForm1.NoDefinitions;
var
  cf: TConfigs;
begin
  for cf := cfUseCompressed to cfNone do
    NStt[cf] := -1;
  Memo1.Clear;
  Memo1.Lines.Add(' 1. Select Definitions file (ZMDefs??.txt)');
  Memo1.Lines.Add(' 2. Select ZipConfig.inc file');
  Memo1.Lines.Add(' 3. Setup required defines');
  Memo1.Lines.Add(' 4. Save');
  Showing := cfNone;
end;

function TForm1.NotDefault: boolean;
var
  cf: TConfigs;
begin
  Result := True;
  for cf := cfUseCompressed to cfStaticLoad do
    if Config[cf] <> ConfigDefault[cf] then
      exit;
  Result := False;
end;

procedure TForm1.Open1Click(Sender: TObject);
begin
  OpenDialog1.Filter     := 'ConfigFiles (*.inc)|*.inc';
  OpenDialog1.DefaultExt := '.inc';
  OpenDialog1.FileName   := ConfigName;
  if OpenDialog1.Execute then
  begin
    ShowDefinitions(cfNone);
    edFile.Text := OpenDialog1.FileName;
    //    ReadConfigFile(OpenDialog1.FileName);
  end;
end;

procedure TForm1.Open2Click(Sender: TObject);
begin
  NoDefinitions;
  OpenDialog1.Filter     := 'TextFiles (*.txt)|*.txt';
  OpenDialog1.DefaultExt := '.txt';
  OpenDialog1.FileName   := DefDefinitions;
  if OpenDialog1.Execute then
  begin
    ReadDefinitions(OpenDialog1.FileName);
  end;
end;

// return < 0 on error
function TForm1.ReadConfigFile(const fname: string): integer;
var
  p:    integer;
  l:    string;
  dno, lno: integer;
  cf:   TConfigs;
  opts: TStringList;
begin
  try
    Result := -1;
    ConfigLoaded := False;
    for cf := cfUseCompressed to cfNone {cfStaticLoad} do
      fOrig[cf] := False;
    ShowDefinitions(cfNone);
    if FileExists(fname) then
    begin
      opts := TStringList.Create;
      try
        opts.LoadFromFile(fname);
        // verify
        if AnsiCompareText(opts[0], ConfigTitle) = 0 then
        begin
          // clear any old values
          Result := 0;
          for lno := 0 to pred(opts.Count) do
          begin
            l := Trim(opts.Strings[lno]);
            if AnsiCompareText(Copy(l, 1, 9), '{$define ') <> 0 then
              continue;
            p := AnsiPos('}', l);
            if p <= 16 then
              continue;
            l   := Trim(Copy(l, 9, p - 9));
            // in theory l = name of define
            dno := IsConfig(l);
            if dno < 0 then
              continue;   // not valid
            cf := TConfigs(dno);
            fOrig[cf] := True;
            Inc(Result);
          end;
          ConfigLoaded := True;
          ShowDefinitions(cfUseCompressed);
        end;
      finally
        opts.Free;
      end;
    end
    else
    begin
      //      ShowDefinitions(cfNone);
      Result := -3;
    end;
  except
    //    ShowDefinitions(cfNone);
    Result := -2;
  end;
end;

function TForm1.ReadDefinitions(const fname: string): integer;
var
  t:  string;
  cf: TConfigs;
  i:  integer;
begin
  Result := -1;
  for cf := cfUseCompressed to cfNone do
    NStt[cf] := -1;
  try
    if FileExists(fname) then
    begin
      FDefinitions.LoadFromFile(fname);
      for i := 0 to FDefinitions.Count - 1 do
      begin
        t  := Definitions[i];
        cf := ISHeading(t);
        if cf <> cfNone then
          NStt[cf] := i;
      end;
    end
    else
      NoDefinitions;
  except
    NoDefinitions;
  end;
end;

procedure TForm1.SetConfig(Index: TConfigs; const Value: boolean);
begin
  if Value <> Config[Index] then
  begin
    fVals[Index] := Value;
  end;
end;

procedure TForm1.SetConfigOrig(Index: TConfigs; const Value: boolean);
begin
  if Value <> ConfigOrig[Index] then
  begin
    fOrig[Index] := Value;
  end;
end;

procedure TForm1.ShowDefinitions(Idx: TConfigs);
var
  t:  string;
  ls: integer;
begin
  if idx = Showing then
    exit;
  if DefinitionStart[cfUseCompressed] < 0 then
  begin
    NoDefinitions;
    exit;
  end;
  Memo1.Clear;
  ls := DefinitionStart[Idx];
  //  if ls < 0 then
  //    exit;
  //    Memo1.Lines.Add(Definitions[ls]);
  Inc(ls);
  while ls < Definitions.Count do
  begin
    t := Definitions[ls];
    if IsHeading(t) <> cfNone then
      break;
    Memo1.Lines.Add(t);
    Inc(ls);
  end;
  Memo1.SelStart := 1;
  Memo1.SelLength := 1;
  Memo1.SelLength := 0;
  Showing := idx;
end;

procedure TForm1.UpdateSettings(tabNo: TConfigs);
begin
  TabIdx := Ord(tabNo);
  if tabNo <> cfNone then
  begin
    CheckBox1.Caption := ConfigStr[tabNo];
    CheckBox1.Checked := Config[tabNo];
  end
  else
  begin
    CheckBox1.Caption := '';
    CheckBox1.Checked := False;
  end;
  ShowDefinitions(tabNo);
end;

function TForm1.WriteConfigFile(const fname: string): integer;
var
  opf: TStringList;
  cf:  TConfigs;
  s:   string;
begin
  //  Result := -1;
  opf := TStringList.Create;
  try
    opf.Add(ConfigTitle);
    for cf := cfUseCompressed to cfStaticLoad do
    begin
      opf.Add(' ');
      opf.Add(prefStr[cf]);
      s := '{$Define ' + confStr[cf] + '}';
      if not Config[cf] then
        s := '// ' + s;
      opf.Add(s);
    end;
    BackupFile(fname);
    opf.SaveToFile(fname);
    for cf := cfUseCompressed to cfStaticLoad do
      ConfigOrig[cf] := Config[cf];
    ConfigLoaded := True;
    Result := 0;
  finally
    opf.Free;
  end;
end;

end.
