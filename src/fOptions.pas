unit fOptions;

interface

uses
  Windows, Sysutils, Classes, Controls, Forms, graphics,
  Dialogs, StdCtrls, Buttons, ExtCtrls, ComCtrls, VirtualTrees,
  Mask, GraphicEX, JvExMask, JvSpin, Spin, Menus, fJWinFontForm;
                      
type
  TPrefForm = class(TJWinFontForm)
    BtnOk: TButton;
    BtnCancel: TButton;
    PgeOptions: TPageControl;
    TabGeneral: TTabSheet;
    GrpGeneral: TGroupBox;
    ChkRunDlg: TCheckBox;
    ChkMinimise: TCheckBox;
    ChkAutoDel: TCheckBox;
    ChkClearFilter: TCheckBox;
    ChkJoy: TCheckBox;
    GrpDefaultIni: TPanel;
    BtnDelReg: TButton;
    GrpReset: TPanel;
    LblResetTots: TLabel;
    BtnReset: TButton;
    ChkRememberROM: TCheckBox;
    ChkOldMini: TCheckBox;
    TabRatings: TTabSheet;
    radRatingsRange: TRadioButton;
    radRatingsStars: TRadioButton;
    radRatingsDefault: TRadioButton;
    RadRatingsCustom: TRadioButton;
    TxtRangeLow: TSpinEdit;
    TxtRangeHigh: TSpinEdit;
    lbllowtohigh: TLabel;
    MemoRatingsCustom: TMemo;
    lblCustomInstructions: TLabel;
    PanHeader: TPanel;
    lblHeader: TLabel;
    Image1: TImage;
    TabSheet1: TTabSheet;
    BtnSystem: TButton;
    BtnEditGoodMerge: TButton;
    BtnEditLang: TButton;
    BtnEditTypes: TButton;
    memoFile: TMemo;
    BtnTextSave: TButton;
    TabSysFileExt: TTabSheet;
    LstSysFileExt: TListBox;
    GrpSysFileExt: TGroupBox;
    MemoFileExts: TMemo;
    ChkFileExtCompression: TCheckBox;
    PopupSysFileExt: TPopupMenu;
    MnuRefresh: TMenuItem;
    BtnSysFileExtSave: TButton;
    lblSysFileEditor: TLabel;
    CmbPwrSchemes: TComboBox;
    TabEmuOpt: TTabSheet;
    CmbExtractDest: TComboBox;
    lblUncompress: TLabel;
    lblGlobalDesc: TLabel;
    lblPowerScheme: TLabel;
    chkUpdatesOnStart: TCheckBox;
    procedure chkUpdatesOnStartClick(Sender: TObject);
    procedure BtnSysFileExtSaveClick(Sender: TObject);
    procedure LstSysFileExtClick(Sender: TObject);
    procedure MnuRefreshClick(Sender: TObject);
    procedure BtnTextSaveClick(Sender: TObject);
    procedure BtnEditGoodMergeClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure BtnOKClick(Sender: TObject);
    procedure BtnSystemClick(Sender: TObject);
    procedure BtnResetClick(Sender: TObject);
    procedure BtnDelRegClick(Sender: TObject);
    procedure BtnEditLangClick(Sender: TObject);
    procedure BtnEditTypesClick(Sender: TObject);
    procedure GenericChangeForRatings(Sender : TObject);
  private
    _LoadedFile : TFileName;
    procedure LoadSystemsFileExtList();
    Procedure ShowSettings();
    { Private declarations }
  public
    { Public declarations }
    Procedure SaveSettings();
  end;

implementation

uses fMain, fTxtEditor, uJUtilities, uRomList, inifiles, uRomUtils, uQPConst,
  uSettings, uQPMiscTypes, ujPowerSchemes;

{$R *.DFM}
{-----------------------------------------------------------------------------}

procedure TPrefForm.LoadSystemsFileExtList();
begin
  LstSysFileExt.Items.Clear;
  LstSysFileExt.Items.LoadFromFile(MainFrm.Settings.Paths.SystemsFile);
end;

{-----------------------------------------------------------------------------}

Procedure TPrefForm.SaveSettings();
begin

    //General Options
    With MainFrm do
    begin
      Settings.CheckForUpdatesOnStart := chkUpdatesOnStart.Checked;
      Settings.AutoDelROMs := ChkAutoDel.Checked;
      Settings.MiniOnRun := ChkMinimise.Checked;
      Settings.UseOldMini := ChkOldMini.Checked;
      Settings.UseRunDlg := ChkRunDlg.Checked;
      Settings.ClearFilter := ChkClearFilter.Checked;
      Settings.Joy := ChkJoy.Checked;
      Settings.RememberLast := ChkRememberROM.Checked;

      Settings.RunOptions.ExtractMode := TQPExtractDest(CmbExtractDest.ItemIndex);
      Settings.RunOptions.GeneralPowerScheme := CmbPwrSchemes.Text;

      if RadRatingsDefault.Checked then
        Settings.RatingsMode := qprDefault
      else if RadRatingsStars.Checked then
        Settings.RatingsMode := qprStars
      else if RadRatingsRange.Checked then
      begin
        Settings.RatingsMode := qprNumeric;
        Settings.RatingsLow := TxtRangeLow.Value;
        Settings.RatingsHigh := TxtRangeHigh.Value;
      end
      else if RadRatingsCustom.Checked then
      begin
        Settings.RatingsMode := qprCustom;
        Settings.RatingsCustom.Clear;
        Settings.RatingsCustom.AddStrings(memoRatingsCustom.Lines);
      end
      else //it should NEVER get this far.. revert to default.
        Settings.RatingsMode := qprDefault;

      //now call the SAVE method for the settings variable.
      Settings.SaveAllSettings();
    end;
end;

{-----------------------------------------------------------------------------}

Procedure TPrefForm.ShowSettings();
var
  Tmp : TStrings;
begin

  with MainFrm do
  begin
    //general options
    CmbPwrSchemes.Clear;
    CmbPwrSchemes.Items.Add(QP_DONT_CHANGE);

    Tmp := TStringList.Create;
    try
      ujPowerSchemes.PowerSchemesToStrings(Tmp);
      CmbPwrSchemes.Items.AddStrings(Tmp);
      CmbPwrSchemes.ItemIndex := CmbPwrSchemes.Items.IndexOf(Settings.RunOptions.GeneralPowerScheme);
    finally
      FreeAndNil(Tmp);
    end;

    chkUpdatesOnStart.Checked := Settings.CheckForUpdatesOnStart;
    ChkAutoDel.Checked := Settings.AutoDelRoms;
    ChkMinimise.Checked := Settings.MiniOnRun;
    ChkOldMini.Checked := Settings.UseOldMini;
    ChkRunDlg.Checked := Settings.UseRunDlg;
    ChkClearFilter.Checked := Settings.ClearFilter;
    ChkJoy.Checked := Settings.Joy;
    ChkRememberROM.Checked := Settings.RememberLast;

    CmbExtractDest.ItemIndex := Integer(Settings.RunOptions.ExtractMode);

    Case MainFrm.Settings.RatingsMode of
      qprDefault : RadRatingsDefault.Checked := True;
      qprStars : RadRatingsStars.Checked := True;
      qprNumeric : RadRatingsRange.Checked := True;
      qprCustom : RadRatingsCustom.Checked := True;
    end;
    Self.TxtRangeLow.Value := Settings.RatingsLow;
    Self.TxtRangeHigh.Value := Settings.RatingsHigh;
    memoRatingsCustom.Lines.AddStrings(Settings.RatingsCustom);

  end; //end of WITH statement

end;

{-----------------------------------------------------------------------------}

procedure TPrefForm.BtnOKClick(Sender: TObject);
begin
  SaveSettings();
end;

{-----------------------------------------------------------------------------}

procedure TPrefForm.BtnSystemClick(Sender: TObject);
begin
  memoFile.Lines.Clear;

  if not FileExists(MainFrm.Settings.Paths.SystemsFile) then
    MainFrm.Settings.CreateSysDat(MainFrm.Settings.Paths.SystemsFile);
    
  memoFile.Lines.LoadFromFile(MainFrm.Settings.Paths.SystemsFile);
  _LoadedFile := MainFrm.Settings.Paths.SystemsFile;
end;

{-----------------------------------------------------------------------------}

procedure TPrefForm.BtnResetClick(Sender: TObject);
var
  i, e : integer;
  ROMFiles : TSTringList;
  TmpList : TQPROMList;
begin
  ROMFiles := TStringList.Create;
  Try
    uROMUtils.GetAllROMFiles(ROMFiles);

    TmpList := TQPROMlist.Create(MainFrm.Settings.AllowWrite);
    try
      for i := 0 to ROMFiles.Count-1 do
      begin

        TmpList.LoadFromFile(ROMFiles[i]);
        for e := 0 to TmpList.Count-1 do
          TmpList[e].NumPlay := 0;

        TmpList.SaveToFile();

      end;  //end of FOR block

      TmpList.Clear;
      
    finally
      FreeAndNil(TmpList);
    end;
                      
  Finally
    FreeAndNil(ROMFiles);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TPrefForm.BtnDelRegClick(Sender: TObject);
begin
  MainFrm.Settings.CreateDefaultIni(true, MainFrm.Settings.Paths.SettingsFile);
end;

{-----------------------------------------------------------------------------}

procedure TPrefForm.BtnEditLangClick(Sender: TObject);
begin
  memoFile.Lines.Clear;

  if not FileExists(MainFrm.Settings.Paths.LanguageFile) then
    MainFrm.Settings.CreateLanguage(MainFrm.Settings.Paths.LanguageFile);

  memoFile.Lines.LoadFromFile(MainFrm.Settings.Paths.LanguageFile);
  _LoadedFile := MainFrm.Settings.Paths.LanguageFile;
end;

{-----------------------------------------------------------------------------}

procedure TPrefForm.BtnEditTypesClick(Sender: TObject);
begin
  memoFile.Lines.Clear;

  if not FileExists(MainFrm.Settings.Paths.GameTypeFile) then
    MainFrm.Settings.CreateTypeDat(MainFrm.Settings.Paths.GameTypeFile);
    
  memoFile.Lines.LoadFromFile(MainFrm.Settings.Paths.GameTypeFile);
  _LoadedFile := MainFrm.Settings.Paths.GameTypeFile;
end;

{-----------------------------------------------------------------------------}

procedure TPrefForm.FormCreate(Sender: TObject);
begin
  PgeOptions.ActivePageIndex := 0;
  Self.LoadSystemsFileExtList();
  showsettings();
end;

{-----------------------------------------------------------------------------}

procedure TPrefForm.GenericChangeForRatings(Sender : TObject);
begin
  TxtRangeLow.Enabled := RadRatingsRange.Checked;
  TxtRangeHigh.Enabled := RadRatingsRange.Checked;
  memoRatingsCustom.Enabled := RadRatingsCustom.Checked;
end;

{-----------------------------------------------------------------------------}

procedure TPrefForm.BtnEditGoodMergeClick(Sender: TObject);
begin
  memoFile.Lines.Clear;

  if not FileExists(MainFrm.Settings.Paths.GoodMergeFile) then
    MainFrm.Settings.CreateGoodCodes(MainFrm.Settings.Paths.GoodMergeFile);

  memoFile.Lines.LoadFromFile(MainFrm.Settings.Paths.GoodMergeFile);
  _LoadedFile := MainFrm.Settings.Paths.GoodMergeFile;
end;

{-----------------------------------------------------------------------------}

procedure TPrefForm.BtnTextSaveClick(Sender: TObject);
begin
  if _LoadedFile <> '' then
    memoFile.Lines.SaveToFile(_LoadedFile);
end;

procedure TPrefForm.chkUpdatesOnStartClick(Sender: TObject);
begin

end;

{-----------------------------------------------------------------------------}

procedure TPrefForm.MnuRefreshClick(Sender: TObject);
begin
  Self.LoadSystemsFileExtList();
end;

{-----------------------------------------------------------------------------}

procedure TPrefForm.LstSysFileExtClick(Sender: TObject);
var
  Ini : TMemIniFile;
  Values : TStrings;
  SelSys : String;
  i : integer;
begin

  memoFileExts.Lines.Clear;
  ChkFileExtCompression.Checked := True;

  if LstSysFileExt.ItemIndex = -1 then
    exit;
    
  SelSys := LstSysFileExt.Items[LstSysFileExt.ItemIndex];

  Ini := TMemIniFile.Create(MainFrm.Settings.Paths.SysFileExtFile);
  try
    ChkFileExtCompression.Checked := Ini.ReadBool(SelSys, 'addCompression', True);

    Values := TStringList.Create;
    try
      if Ini.SectionExists(SelSys) then
        Ini.ReadSection(SelSys, Values);

      for i := 0 to Values.Count-1 do
      begin
        if Not AnsiSameText(Values[i], 'addCompression') then
          MemoFileExts.Lines.Add(Ini.ReadString(SelSys, Values[i], ''));
      end;
      
    finally
      FreeAndNil(Values);
    end;
  finally
    FreeAndNil(ini);
  end;

end;

{-----------------------------------------------------------------------------}

procedure TPrefForm.BtnSysFileExtSaveClick(Sender: TObject);
var
  Ini : TMemIniFile;
  SelSys : String;
  i : Integer;
begin

  if LstSysFileExt.ItemIndex <> -1 then
  begin

    SelSys := LstSysFileExt.Items[LstSysFileExt.ItemIndex];
    Ini := TMemIniFile.Create(MainFrm.Settings.Paths.SysFileExtFile);
    try

      Ini.EraseSection(SelSys);

      Ini.WriteBool(SelSys, 'addCompression', ChkFileExtCompression.Checked);
      for i := 0 to memoFileExts.Lines.Count-1 do
      begin
        Ini.WriteString(SelSys, IntToStr(i), MemoFileExts.Lines[i]);
      end;

      //update the file.
      Ini.UpdateFile;
    finally
      FreeandNil(ini);
    end;

  end;

end;

end.
