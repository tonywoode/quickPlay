unit fFolderOpt;

interface

uses
  Windows, SysUtils, Classes, Controls, Forms, graphics, JvBaseDlg,
  JvBrowseFolder, ImgList, Dialogs, ExtDlgs, ComCtrls, StdCtrls, Buttons,
  JvComponent, Mask, JvExMask, JvToolEdit, JvExStdCtrls, JvButton, JvCtrls,
  ExtCtrls, GraphicEX, JvComponentBase, fJWinFontForm;

type
  TFrmFolder = class(TJWinFontForm)
    IconList: TImageList;
    PageFol: TPageControl;
    TabGeneral: TTabSheet;
    GrpMirror: TGroupBox;
    lblDir: TLabel;
    lblEmu: TLabel;
    lblFilter: TLabel;
    Label1: TLabel;
    LstFilter: TListBox;
    cmbEmu: TComboBox;
    ChkMirror: TCheckBox;
    TabRealIcons: TTabSheet;
    lblMAMElink: TLabel;
    ChkLargeIcons: TCheckBox;
    ChkMAMEIcons: TCheckBox;
    LstDirMir: TListBox;
    GrpBackground: TGroupBox;
    LblBKPath: TLabel;
    ChkBK: TCheckBox;
    GrpIcon: TGroupBox;
    lblIcon: TLabel;
    ChkIcon: TCheckBox;
    CmbIcon: TComboBoxEx;
    TxtBKPath: TJvFilenameEdit;
    TxtMAMEIconDir: TJvDirectoryEdit;
    jvBrowse: TJvBrowseForFolderDialog;
    BtnAddMirror: TJvImgBtn;
    BtnDelMirror: TJvImgBtn;
    BtnAddFilter: TJvImgBtn;
    BtnDelFilter: TJvImgBtn;
    TxtMAMEIconFile: TJvFilenameEdit;
    RadMAMEIconsDir: TRadioButton;
    RadMAMEIconsFile: TRadioButton;
    PanCtrls: TPanel;
    BtnOK: TButton;
    BtnCancel: TButton;
    TabMerged: TTabSheet;
    lblMergeTitle: TLabel;
    lblGoodMergeLink: TLabel;
    lblGoodMergeDesc: TLabel;
    ChkActivateGoodMerge: TCheckBox;
    ChkExclamationRoms: TCheckBox;
    CmbGMpref1: TComboBox;
    CmbGMpref2: TComboBox;
    CmbGMpref3: TComboBox;
    lblPrefWarning: TLabel;
    lblGM1: TLabel;
    lblGM2: TLabel;
    lblGM3: TLabel;
    Label2: TLabel;
    procedure TxtBKPathChange(Sender: TObject);
    procedure cmbEmuChange(Sender: TObject);
    procedure BtnCancelClick(Sender: TObject);
    procedure BtnOKClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure ChkBKClick(Sender: TObject);
    procedure ChkIconClick(Sender: TObject);
    procedure ChkMirrorClick(Sender: TObject);
    procedure lblMAMElinkClick(Sender: TObject);
    procedure BtnDelMirrorClick(Sender: TObject);
    procedure BtnAddMirrorClick(Sender: TObject);
    procedure BtnAddFilterClick(Sender: TObject);
    procedure BtnDelFilterClick(Sender: TObject);
    procedure RadMAMEIconsDirClick(Sender: TObject);
    procedure lblGoodMergeLinkClick(Sender: TObject);
  private
    procedure Init;
    Procedure SetupFileExts(ForSys : String);
    { Private declarations }
    Procedure SetGMPref(Cmb : TComboBox; Input : String);
    Function GetGMPref(Cmb : TComboBox) : String;

  public
    { Public declarations }
    SelFol : String;
  end;

implementation

uses JCLStrings, IniFiles, FindFile, ShellAPI, fMain, uJUtilities,
  uQPCompObj, uEmuList, uQPConst, uJCompression, uQPMiscTypes;

{$R *.dfm}

{-----------------------------------------------------------------------------}

Procedure TFrmFolder.SetGMPref(Cmb : TComboBox; Input : String);
var
  i : Integer;
begin
  for i := 0 to Cmb.Items.Count-1 do
    if Pos(Input, Cmb.Items[i]) <> 0 then
    begin
      Cmb.ItemIndex := i;
      break;
    end;
end;

{-----------------------------------------------------------------------------}

Function TFrmFolder.GetGMPref(Cmb : TComboBox) : String;
var
  TmpString : String;
  EndOfCode : Integer;
begin
  TmpString := Cmb.Text;
  EndOfCode := Pos(' ', TmpString);
  TmpString := Copy(TmpString, 0, EndOfCode);
  Result := TmpString;
end;

{-----------------------------------------------------------------------------}

Procedure TFrmFolder.SetupFileExts(ForSys : String);
var
  Ini : TMemIniFile;
  Values : TStrings;
  i : Integer;
begin
  LstFilter.Clear;
  if (ForSys = '') or (AnsiSameText(ForSys, 'All')) then
  begin
    // no system specified - fill with just compression types.
    LstFilter.Items.Text := uQPCompObj.Compression.SupportedFileExts;
  end
  else
  begin
    //check what custom filters are specified for this system in the file.
    Ini := TMemIniFile.Create(MainFrm.Settings.Paths.SysFileExtFile);
    try

      if Ini.ReadBool(ForSys, 'addCompression', True) then
        LstFilter.Items.Text := uQPCompObj.Compression.SupportedFileExts;

      Values := TStringList.Create;
      try
        if Ini.SectionExists(ForSys) then
          Ini.ReadSection(ForSys, Values);

        for i := 0 to Values.Count-1 do
        begin
          if Not AnsiSameText(Values[i], 'addCompression') then
            LstFilter.Items.Add(Ini.ReadString(ForSys, Values[i], ''));
        end;
      
      finally
        FreeAndNil(Values);
      end;

    finally
      FreeAndNil(Ini);
    end;
  end;
end;

procedure TFrmFolder.TxtBKPathChange(Sender: TObject);
begin

end;

{-----------------------------------------------------------------------------}

Procedure TFrmFolder.Init();
Var
  I : Integer;
  temp1, TempLbl : String;
  Image : TIcon;
  Find : ThhFindFile;
  Ini : TMemIniFile;
  List : TMemoryStream;
  tmpStrings : TStringList;
  iconPath1 : String;
  iconPath2 : String;
  iconPath3 : String;
  oldSize : Integer;
begin

  {-----------------------------------------------}
  {Set up the Folder Name at forms caption}

  Temp1 := SelFol;
  Temp1 := Trim(Temp1);
  Temp1 := ExcludeTrailingPathDelimiter(Temp1);

  For i := Length(Temp1)-1 Downto 0 do
  begin
    if Temp1[i] = '\' then break;
  end;

  TempLbl := Copy(Temp1, i+1, Length(Temp1)-1);
  Self.Caption := Self.Caption + TempLbl;

  {------------------------------------------------}
  { Add all available emulators to mirror combo box}
  MainFrm.EmuList.EmusToStrings(CmbEmu.Items, cfAllEmus);

  //set up the GOOD merge language combo boxes
  tmpStrings:= TStringList.Create;
  try 
    tmpStrings.LoadFromFile(MainFrm.Settings.Paths.GoodMergeFile);
    CmbGMPref1.Items.Assign(tmpStrings);
    cmbGMPref1.ItemIndex := 20;
    CmbGMpref2.Items.Assign(tmpStrings);
    CmbGMpref2.ItemIndex := 5;
    CmbGMpref3.Items.Assign(tmpStrings);
    CmbGMpref3.ItemIndex := 14;
  finally
    FreeAndNil(tmpStrings);
  end;
  
  {------------------------------------------------}
  {Set up the combo box with the icons}

  Image := nil;
  Find := ThhFindFile.Create(Self);
  try
    Image := TIcon.Create;
	  Ini := TMemIniFile.Create(MainFrm.Settings.Paths.SettingsFile);
    iconPath1 := MainFrm.Settings.Paths.AppDir + 'icons\'   ;
    iconPath2 := Ini.ReadString('DirOptions', 'IconPath1', '') + '\';

    Find.Directory := IconPath1;
    find.Filter := '*.ico';
    Find.Recurse := False;
    Find.Execute;

    tmpStrings := TStringList.Create;
    try
      For i := 0 to Find.TotalFile-1 do
      begin

        try
          //if this fails then the specified file is not really an icon.
          Image.LoadFromFile(Find.Files[i]);
          //if it didnt fail then we can add it to the icon list and combo
          IconList.AddIcon(Image);
          CmbIcon.ItemsEx.AddItem(ExtractFileName(Find.files[i]),i,i,i,0,nil)
        //if it failed, add it to the failure stringlist
        except
          tmpStrings.Add(ExtractFileName(Find.Files[i]));
        end;
      end;

      Find.Directory := IconPath2;
      Find.Execute;
      oldSize := i;//grab the size of the first path
      For i := 0 to Find.TotalFile-1 do
      begin
        try
          //if this fails then the specified file is not really an icon.
          Image.LoadFromFile(Find.Files[i]);
          //if it didnt fail then we can add it to the icon list and combo
          IconList.AddIcon(Image);
          CmbIcon.ItemsEx.AddItem(ExtractFileName(Find.files[i]),i+oldSize,i+oldSize,i+oldSize,0,nil)
        //if it failed, add it to the failure stringlist
        except
          tmpStrings.Add(ExtractFileName(Find.Files[i+oldSize]));
        end;
      end;
      If tmpStrings.Count > 0 then
        MessageDlg(QP_FOLOPTFRM_BAD_ICONS + tmpStrings.GetText, mtError, [mbOK], 0);

    Finally
      FreeAndNil(tmpStrings);
    end;

  finally
    FreeAndNil(Find);
    FreeAndNil(Image);
  end;

  {------------------------------------------------}
  {Set up the options if the settings have been written}

  Ini := TMemIniFile.Create(SelFol + 'folders.ini');
  Try

      //GoodMerge
	    ChkExclamationRoms.Checked := Ini.ReadBool('GoodMerge', 'GoodMergeExclamationRoms', False);
      ChkActivateGoodMerge.Checked := Ini.ReadBool('GoodMerge', 'GoodMergeCompat', False);
      Self.SetGMPref(CmbGMPref1, Ini.readString('GoodMerge', 'Pref1', '(U)'));
      Self.SetGMPref(CmbGMPref2, Ini.readString('GoodMerge', 'Pref2', '(E)'));
      Self.SetGMPref(CmbGMPref3, Ini.readString('GoodMerge', 'Pref3', '(J)')); 

      //Mirroring Options
      ChkMirror.Checked := Ini.ReadBool('Mirror', 'ChkMirror', False);

      tmpStrings := TStringList.Create;
      try
        StrTokenToStrings(Ini.ReadString('Mirror', 'TxtDir', ''),';', tmpStrings);
        For i := 0 to tmpStrings.Count-1 do
          LstDirMir.Items.Add(tmpStrings.Strings[i])
      Finally
        FreeAndNil(tmpStrings);
      end;
      //TxtDir.Text := Ini.ReadString('Mirror', 'TxtDir', '');

      CmbEmu.ItemIndex := CmbEmu.Items.IndexOf(Ini.ReadString('Mirror','CmbEmu', ''));

      List := TMemoryStream.Create;
      try
        Ini.ReadBinaryStream('Mirror','LstFilter',List);
        LstFilter.Items.LoadFromStream(List);
      finally
        FreeAndNil(List);
      end;

      if Lstfilter.Items.Count = 0 then
        SetupFileExts('');

      BtnAddfilter.Enabled := ChkMirror.Checked;
      BtnDelFilter.Enabled := ChkMirror.Checked;
      CmbEmu.Enabled := ChkMirror.Checked;
      lblDir.Enabled := ChkMirror.Checked;
      lblEmu.Enabled := ChkMirror.Checked;
      lblFilter.Enabled := ChkMirror.Checked;
      LstFilter.Enabled := ChkMirror.Checked;
      LstDirMir.Enabled := ChkMirror.Checked;
      BtnAddMirror.Enabled := ChkMirror.Checked;
      BtnDelMirror.Enabled := ChkMirror.Checked;

      //Rom Listing Background
      ChkBk.Checked := Ini.ReadBool('BkGround', 'ChkBk', False);
      TxtBKPath.Text := Ini.ReadString('BkGround', 'TxtBKPath', '');

      TxtBKPath.Enabled := ChkBk.Checked;
      LblBKPath.Enabled := ChkBK.Checked;

      //Folder List Icon
      ChkIcon.Checked := Ini.ReadBool('Icon', 'ChkIcon', False);
      CmbIcon.ItemIndex := CmbIcon.Items.IndexOf(Ini.ReadString('Icon','CmbIcon', ''));
      CmbIcon.Enabled := ChkIcon.Checked;
      LblIcon.Enabled := ChkIcon.Checked;

      // Real Icons settings
      i := Ini.ReadInteger('RealIcon', 'ChkRealIcons', 0);
      if i = 0 then
        ChkMAMEIcons.Checked := False
      else
      begin
        ChkMAMEIcons.Checked := true;
        if i = 1 then
        begin
          RadMAMEIconsDir.Checked := True;
          TxtMAMEIconDir.Text := Ini.ReadString('RealIcon', 'Directory', '');
        end
        else if i = 2 then
        begin
          RadMAMEIconsFile.Checked := True;
          TxtMAMEIconFile.Text := Ini.ReadString('RealIcon', 'Directory', '');
        end
      end;

      ChkLargeIcons.Checked := Ini.ReadBool('RealIcon', 'ChkLargeIcons', false);
  Finally
    FreeAndNil(Ini);
  end;

end;

{-----------------------------------------------------------------------------}

procedure TFrmFolder.BtnCancelClick(Sender: TObject);
begin
  ModalResult := MrCancel;
end;

{-----------------------------------------------------------------------------}

procedure TFrmFolder.BtnOKClick(Sender: TObject);
Var
  Ini : TMemIniFile;
  List : TMemoryStream;
  DirOutput : String;
  i : Integer;
begin

  Ini := TMemInifile.create(SelFol + 'folders.ini');
  Try

    //GoodMerge Compatibility setting
	  Ini.WriteBool('GoodMerge', 'GoodMergeExclamationRoms', ChkExclamationRoms.Checked);
    Ini.WriteBool('GoodMerge', 'GoodMergeCompat', ChkActivateGoodMerge.Checked);
    Ini.WriteString('GoodMerge', 'pref1', Self.GetGMPref(CmbGMPref1));
    Ini.WriteString('GoodMerge', 'pref2', Self.GetGMPref(CmbGMPref2));
    Ini.WriteString('GoodMerge', 'pref3', Self.GetGMPref(CmbGMPref3));

    //Mirroring Options
    Ini.WriteBool('Mirror', 'ChkMirror', ChkMirror.Checked);
    DirOutput := '';
    For i := 0 to LstDirMir.Count-1 do
      If DirectoryExists(LstDirMir.Items.Strings[i]) then
        DirOutput := DirOutput + LstDirMir.Items.Strings[i] + ';';

    Ini.WriteString('Mirror', 'TxtDir', DirOutput);

    if CmbEmu.ItemIndex <>-1 then
      Ini.WriteString('Mirror', 'CmbEmu', CmbEmu.Items.Strings[CmbEmu.ItemIndex]);

    //Media Paths
    List := TMemoryStream.Create;
    try

      LstFilter.Items.SaveToStream(List);
      List.Position := 0;
      Ini.WriteBinaryStream('Mirror','LstFilter', List);

    finally
      FreeAndNil(List);
    end;

    // Real Icon Support

    if ChkMAMEIcons.Checked then
    begin
      if RadMAMEIconsDir.Checked then
      begin
        Ini.WriteInteger('RealIcon', 'ChkRealIcons', Integer(qmiDir));
        If DirectoryExists(TxtMAMEIconDir.Text) then
          Ini.WriteString('RealIcon', 'Directory', TxtMAMEIconDir.Text);
      end
      else if RadMAMEIConsFile.Checked then
      begin
        Ini.WriteInteger('RealIcon', 'ChkRealIcons', Integer(qmiZip));
        If FileExists(TxtMAMEIconFile.Text) then
          Ini.WriteString('RealIcon', 'Directory', TxtMAMEIconFile.Text);
      end
      else
        //this should never happen, but disable anyway
        Ini.WriteInteger('RealIcon', 'ChkRealIcons', Integer(qmiOff));
    end
    else
      Ini.WriteInteger('RealIcon', 'ChkRealIcons', Integer(qmiOff));

    Ini.WriteBool('RealIcon', 'ChkLargeIcons', ChkLargeIcons.Checked);

    //Background options
    Ini.WriteBool('BkGround', 'ChkBk', ChkBK.Checked);
    Ini.WriteString('BkGround', 'TxtBKPath', TxtBKPath.Text);

    //Folder List Icon
    Ini.WriteBool('Icon', 'ChkIcon', ChkIcon.Checked);
    if CmbIcon.ItemIndex <>-1 then
      Ini.WriteString('Icon', 'CmbIcon', CmbIcon.Items.Strings[CmbIcon.ItemIndex]);

    if MainFrm.Settings.AllowWrite then
      Ini.UpdateFile;
    
  Finally
    FreeAndNil(Ini);
  end;

  ModalResult := MrOK;
end;

{-----------------------------------------------------------------------------}

procedure TFrmFolder.FormShow(Sender: TObject);
begin
  PageFol.ActivePageIndex := 0;
  Init();
  if DirectoryExists(MainFrm.Settings.Paths.AppDir + 'images') then
    TxtBKPath.InitialDir := MainFrm.Settings.Paths.AppDir + 'images';
end;

{-----------------------------------------------------------------------------}

procedure TFrmFolder.ChkBKClick(Sender: TObject);
begin
    TxtBKPath.Enabled := ChkBk.Checked;
    LblBKPath.Enabled := ChkBK.Checked;
end;

{-----------------------------------------------------------------------------}

procedure TFrmFolder.ChkIconClick(Sender: TObject);
begin
  CmbIcon.Enabled := ChkIcon.Checked;
  LblIcon.Enabled := ChkIcon.Checked;
end;

{-----------------------------------------------------------------------------}

procedure TFrmFolder.ChkMirrorClick(Sender: TObject);
begin
  BtnAddfilter.Enabled := ChkMirror.Checked;
  BtnDelFilter.Enabled := ChkMirror.Checked;
  CmbEmu.Enabled := ChkMirror.Checked;
  lblDir.Enabled := ChkMirror.Checked;
  lblEmu.Enabled := ChkMirror.Checked;
  lblFilter.Enabled := ChkMirror.Checked;
  LstFilter.Enabled := ChkMirror.Checked;
  LstDirMir.Enabled := ChkMirror.Checked;
  BtnAddMirror.Enabled := ChkMirror.Checked;
  BtnDelMirror.Enabled := ChkMirror.Checked;
end;

{-----------------------------------------------------------------------------}

procedure TFrmFolder.lblMAMElinkClick(Sender: TObject);
begin
  ShellExecute(Handle, 'open', PChar('http://www.mameworld.net/icons/'), '', '', sw_Show);
end;

{-----------------------------------------------------------------------------}

procedure TFrmFolder.BtnDelMirrorClick(Sender: TObject);
begin
  LstDirMir.Items.Delete(LstDirMir.itemindex);
end;

{-----------------------------------------------------------------------------}

procedure TFrmFolder.BtnAddMirrorClick(Sender: TObject);
begin
  if jvBrowse.execute then
    if jvBrowse.Directory <> '' then
      LstDirMir.Items.Add(jvBrowse.Directory);
end;

{-----------------------------------------------------------------------------}

procedure TFrmFolder.BtnAddFilterClick(Sender: TObject);
begin
  LstFilter.items.Add(inputBox(QP_FOLOPTFRM_FILE_EXT,QP_FOLOPTFRM_FILE_EXT,''));
end;

{-----------------------------------------------------------------------------}

procedure TFrmFolder.BtnDelFilterClick(Sender: TObject);
begin
  LstFilter.Items.Delete(LstFilter.itemindex);
end;

{-----------------------------------------------------------------------------}

procedure TFrmFolder.RadMAMEIconsDirClick(Sender: TObject);
begin
  TxtMAMEIconFile.Enabled := RadMAMEIconsFile.Checked;
  TxtMAMEIconDir.Enabled := RadMAMEIconsDir.Checked;
end;

{-----------------------------------------------------------------------------}

procedure TFrmFolder.lblGoodMergeLinkClick(Sender: TObject);
begin
  ShellExecute(Handle, 'open', PChar('http://goodmerge.sourceforge.net/'), '', '', sw_Show);
end;

{-----------------------------------------------------------------------------}

procedure TFrmFolder.cmbEmuChange(Sender: TObject);
begin
  With MainFrm do
  begin
    SetupFileExts(EmuList[EmuList.IndexOfName(CmbEmu.Text)].System);
  end;
end;

{-----------------------------------------------------------------------------}

end.
