unit fMameOptions;

interface

uses
  Windows, SysUtils, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, JvBaseDlg, JvSelectDirectory, JvBrowseFolder, Buttons,
  uRomList, JvComponent, JvExStdCtrls, JvButton, JvCtrls, ExtCtrls,
  JvComponentBase, fJWinFontForm;

type
  TFrmMameOptions = class(TJWinFontForm)
    CmbMame: TComboBox;
    lblMAME: TLabel;
    BtnOK: TButton;
    BtnCancel: TButton;
    Label1: TLabel;
    lblDir: TLabel;
    jvBrowse: TJvBrowseForFolderDialog;
    ChkCatVer: TCheckBox;
    ListDirs: TListBox;
    BtnAdd: TJvImgBtn;
    BtnDel: TJvImgBtn;
    ChkUseOldMAMEMode: TCheckBox;
    RadGroupCurrScanInfo: TRadioGroup;
    procedure FormShow(Sender: TObject);
    procedure BtnOKClick(Sender: TObject);
    procedure BtnAddClick(Sender: TObject);
    procedure BtnDelClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
    _ZincMode : Boolean;
    procedure SetupZincMode(value : Boolean);
  public
    { Public declarations }
    Property EnableZincMode : boolean read _ZincMode write SetupZincMode;
  end;

implementation

uses fMain, uJUtilities, StrUtils, JCLstrings, IniFiles, uRom, uEmuList, uQPConst,
  uEmu, uQPMiscTypes;

{$R *.dfm}

procedure TFrmMameOptions.SetupZincMode(value : Boolean);
begin
  Self.Caption := 'Scan ZiNc ROMs';
  _ZincMode := True;
end;

procedure TFrmMameOptions.FormCreate(Sender: TObject);
begin
  _ZincMode := False;
end;

procedure TFrmMameOptions.FormShow(Sender: TObject);
var
  Ini : TMemIniFile;
  Dirs : TStringList;
  I : Integer;
begin
  if _ZincMode then
    MainFrm.EmuList.EmusToStrings(CmbMame.Items, cfZiNc)
  else
    MainFrm.EmuList.EmusToStrings(CmbMame.Items, cfMame);

  Ini := TMemIniFile.Create(MainFrm.Settings.Paths.SettingsFile);
  Try

    //Load in the Directories.
    Dirs := TStringList.Create;
    try
      StrTokenToStrings(Ini.ReadString('MAMEScan', 'Dirs', ''),';', Dirs);
      For i := 0 to Dirs.Count-1 do
        ListDirs.Items.Add(Dirs.Strings[i])
    Finally
      FreeAndNil(Dirs);
    end;

    CmbMAME.ItemIndex := -1;
    ChkCatVer.Checked := Ini.ReadBool('MAMEScan', 'CatVer', false);

    RadGroupCurrScanInfo.ItemIndex :=  Ini.ReadInteger('MAMEScan', 'ScanType', 0);

  Finally
    FreeAndNil(Ini);
  end;

end;

{-----------------------------------------------------------------------------}

procedure TFrmMameOptions.BtnOKClick(Sender: TObject);
var
  DirOutput : String;
  i  : Integer;
  Ini : TMemIniFile;
  Emu : TQPEmu;
  Clear : boolean;
begin

  If (CmbMame.ItemIndex = -1) or (ListDirs.Count = 0) then
  begin
    MessageDlg(QP_MAMEM_BAD_DATA, mtError, [mbOK], 0);
    exit;
  end;

  //if the user has asked to catver this scan, make sure the catver file is there!
  if (ChkCatVer.Checked) then
    if not FileExists(MainFrm.Settings.Paths.CfgDir + 'catver.ini') then
    begin
      MessageDlg(QP_NO_CATVER, mtError, [mbOK], 0);
      exit;
    end;


  Emu := MainFrm.EmuList[MainFrm.EmuList.IndexOfName(CmbMAME.Text)];

  Clear := (RadGroupCurrScanInfo.ItemIndex = 0);

  if _ZincMode then
    MainFrm.RomList.AddZincROMS(ListDirs.Items, Emu, MainFrm.Settings.Paths.CfgDir, Clear, ChkCatVer.Checked)
  else
    MainFrm.RomList.AddMAMEScanned(ListDirs.Items, Emu, MainFrm.Settings.Paths.CfgDir, Clear, ChkCatVer.Checked, ChkUseOldMAMEMode.Checked);

  //now we need to reload the ROMs list.
    MainFrm.ClearROMIcons();
    MainFrm.ROMlist.LoadFromFile(MainFrm.GetSelectedTxt);

  //now save the users input data.
  Ini := TMemIniFile.Create(MainFrm.Settings.Paths.SettingsFile);
  Try

    For i := 0 to ListDirs.Count-1 do
      If DirectoryExists(ListDirs.Items.Strings[i]) then
        DirOutput := DirOutput + ListDirs.Items.Strings[i] + ';';

    Ini.WriteString('MAMEScan', 'Dirs', DirOutput);
    Ini.WriteString('MAMEScan', 'MAME', CmbMAME.Text);
    Ini.WriteBool('MAMEScan', 'CatVer', ChkCatVer.Checked);
    Ini.WriteInteger('MAMEScan', 'ScanType', RadGroupCurrScanInfo.ItemIndex);

    if MainFrm.Settings.AllowWrite then
      Ini.UpdateFile;

  Finally
    FreeAndNil(Ini);
  end;

  //close the form with the modal result OK
  ModalResult := MrOK;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMameOptions.BtnAddClick(Sender: TObject);
begin
  if (jvBrowse.execute) and (jvBrowse.Directory <> '') then
    ListDirs.Items.Add(jvBrowse.Directory);
end;

{-----------------------------------------------------------------------------}

procedure TFrmMameOptions.BtnDelClick(Sender: TObject);
begin
  ListDirs.DeleteSelected;
end;

end.
