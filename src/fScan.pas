unit fScan;

interface

uses
  Windows, SysUtils, Classes, Controls, Forms, Dialogs,
  StdCtrls, Buttons, ComCtrls, JvBaseDlg, FindFile,
  JvBrowseFolder, JvComponent, JvComponentBase, fJWinFontForm, ExtCtrls;

type
  TScanForm = class(TJWinFontForm)
    FindFile: ThhFindFile;
    GrpOptions: TGroupBox;
    CmbEmu: TComboBox;
    GrpFolder: TGroupBox;
    ChkSubDir: TCheckBox;
    BtnScan: TButton;
    BtnCancel: TButton;
    jvBrowse: TJvBrowseForFolderDialog;
    BtnMinus: TSpeedButton;
    BtnAdd: TSpeedButton;
    ListDirs: TListBox;
    lblEmu: TLabel;
    lblSystem: TLabel;
    CmbSystem: TComboBox;
    ChkDup: TCheckBox;
    FilterGroup: TGroupBox;
    BtnAddFilter: TSpeedButton;
    BtnFilterMinus: TSpeedButton;
    FilterList: TListBox;
    GrpRatings: TGroupBox;
    RadNoRating: TRadioButton;
    RadSetRating: TRadioButton;
    CmbRating: TComboBox;
    ChkInsideZips: TCheckBox;
    RadGrpLanguage: TRadioGroup;
    procedure CmbEmuChange(Sender: TObject);
    procedure BtnScanClick(Sender: TObject);
    procedure BtnAddFilterClick(Sender: TObject);
    procedure BtnFilterMinusClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure CmbSystemChange(Sender: TObject);
    procedure RadSetRatingClick(Sender: TObject);
    procedure RadNoRatingClick(Sender: TObject);
    procedure BtnAddClick(Sender: TObject);
    procedure BtnMinusClick(Sender: TObject);

  private
    FPreviousScanDir : String;
    FCurrentDir : string;
    procedure init();
    Procedure SetupFileExts(ForSys : String);
    
  public
    { Public declarations }
  end;

implementation

uses fMain, uJUtilities, uEmuList, uRomList, inifiles, JCLStrings, uQPConst,
  uQPCompObj, uJCompression, uQPMiscTypes, ujMiscResourceStrs;

{$R *.DFM}

{-----------------------------------------------------------------------------}

Procedure TScanForm.SetupFileExts(ForSys : String);
var
  Ini : TMemIniFile;
  Values : TStrings;
  i : Integer;
begin
  FilterList.Clear;
  if (ForSys = '') or (AnsiSameText(ForSys, 'All')) then
  begin
    // no system specified - fill with just compression types.
    FilterList.Items.Text := uQPCompObj.Compression.SupportedFileExts;
  end
  else
  begin
    //check what custom filters are specified for this system in the file.
    Ini := TMemIniFile.Create(MainFrm.Settings.Paths.SysFileExtFile);
    try

      if Ini.ReadBool(ForSys, 'addCompression', True) then
        FilterList.Items.Text := uQPCompObj.Compression.SupportedFileExts;

      Values := TStringList.Create;
      try
        if Ini.SectionExists(ForSys) then
          Ini.ReadSection(ForSys, Values);

        for i := 0 to Values.Count-1 do
        begin
          if Not AnsiSameText(Values[i], 'addCompression') then
            FilterList.Items.Add(Ini.ReadString(ForSys, Values[i], ''));
        end;
      
      finally
        FreeAndNil(Values);
      end;

    finally
      FreeAndNil(Ini);
    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TScanForm.BtnAddFilterClick(Sender: TObject);
begin
  filterlist.items.Add(inputBox(QP_FOLOPTFRM_FILE_EXT,QP_FOLOPTFRM_FILE_EXT,''));
end;

{-----------------------------------------------------------------------------}

procedure TScanForm.BtnFilterMinusClick(Sender: TObject);
begin
  filterlist.DeleteSelected;
end;

{-----------------------------------------------------------------------------}

procedure TScanForm.BtnScanClick(Sender: TObject);
var
  i: integer;
  filter, Rating : string;
  Lang : TQPLanguageMode;
  Ini : TMemIniFile;
  OldStyle : Tcursor;
begin
  OldStyle := screen.Cursor;
  Screen.Cursor := crHourGlass;
  try

//This Section of code initialises + Executes FindFile.
    if (ListDirs.Count > 0) then
    begin

        //set up the search options
        if FilterList.Items.Count > 0 then
        Begin
          for i := 0 to (filterlist.Items.Count - 1) do
            filter := filter + ';' + filterlist.items[i];
        end
        else
        Begin
          MessageDlg(QP_SCAN_NO_FILTER, mtWarning, [mbOK], 0);
          ModalResult := MrNone;
          Exit;
        end;

        if RadSetRating.Checked then
          Rating := CmbRating.Text
        else
          Rating := '';

        case RadGrpLanguage.ItemIndex of
          0: Lang := lmGuess;
          1: Lang := lmEnglish;
          else
            Lang := lmNone;
        end;

        //now save whatever is left over
        MainFrm.RomList.AddFromDirs(ListDirs.Items, Filter, ChkSubDir.Checked,
        ChkInsideZips.Checked, CmbEmu.Text, Rating, Lang, ChkDup.Checked);

    end
    Else
    begin
      Screen.Cursor := OldStyle;
      MessageDlg(J_ENTER_ALL_DATA, mtError, [mbOK], 0);
      modalresult := mrNone;
    end;

    Ini := TMemIniFile.Create(MainFrm.Settings.Paths.SettingsFile);
    try

      Ini.WriteString('Scan', 'LastDir', FPreviousScanDir);

      case ChkSubDir.checked of
        false : Ini.WriteInteger('Scan','SubChk', 0);
        true : Ini.WriteInteger('Scan','SubChk', 1);
      end;

      case ChkDup.checked of
        false : Ini.WriteInteger('Scan','DupChk', 0);
        true : Ini.WriteInteger('Scan','DupChk', 1);
      end;

      Ini.WriteString('Scan','LastEmu', CmbEmu.text);

      if MainFrm.Settings.AllowWrite then
        Ini.UpdateFile;

    finally
      FreeAndNil(Ini);
    end;

  finally
    Screen.Cursor := OldStyle;
  End;
end;

{-----------------------------------------------------------------------------}
{                              Private Routines                               }
{-----------------------------------------------------------------------------}

procedure TScanForm.init();
var
  Ini : TMemIniFile;
begin

  CmbSystem.Items.LoadFromFile(MainFrm.Settings.Paths.SystemsFile);

  CmbSystem.Items.Insert(0, 'All');
  CmbSystem.ItemIndex := 0;

  //Set up the emulators Combo Box
  CmbEmu.Items.Clear;
  MainFrm.EmuList.EmusToStrings(CmbEmu.Items, cfAllEmus);

  //setup the ratings combo box.
  MainFrm.Settings.Ratings(CmbRating);

  //load in all available compression extensions for the filter.
  SetupFileExts('');
  //FilterList.Items.Text := uJCompression.Compression.SupportedFileExts;

  Ini := TMemIniFile.Create(MainFrm.Settings.Paths.SettingsFile);
  Try

    FPreviousScanDir := Ini.ReadString('Scan', 'LastDir', '');

    if Ini.ValueExists('Scan','SubChk') then
      case (Ini.ReadInteger('Scan','SubChk',0)) of
        0: ChkSubDir.checked := false;
        1: ChkSubDir.Checked := true;
      end;

    //Check whether duplicate checking is turned on
    if Ini.ValueExists('Scan','DupChk') then
      case (Ini.readInteger('Scan','DupChk',0)) of
        0: chkdup.checked := false;
        1: chkdup.checked := true;
      end;

    //Load in the last selected emulator
    if Ini.ValueExists('Scan','LastEmu') then
        CmbEmu.ItemIndex := CmbEmu.Items.IndexOf(Ini.ReadString('Scan','LastEmu',''));

  Finally
    FreeAndNil(Ini);
  end;

  FCurrentDir := MainFrm.GetSelectedTxt;

end;

{-----------------------------------------------------------------------------}

procedure TScanForm.FormCreate(Sender: TObject);
begin
  init();
end;

{-----------------------------------------------------------------------------}

procedure TScanForm.CmbSystemChange(Sender: TObject);
begin

  With MainFrm.EmuList do
  Begin
    CmbEmu.Items.Clear;
                  
    If CmbSystem.Text = J_ALL then
      EmusToStrings(CmbEmu.Items, cfAllEmus)
    else
      EmusToStrings(CmbEmu.Items, cfEmuBySys, CmbSystem.Text);

    //now load custom filters (if any)
    SetupFileExts(CmbSystem.Text);

  end;//end of WITH block
end;

{-----------------------------------------------------------------------------}

procedure TScanForm.RadSetRatingClick(Sender: TObject);
begin
  CmbRating.Enabled := RadSetRating.Checked;
end;

{-----------------------------------------------------------------------------}

procedure TScanForm.RadNoRatingClick(Sender: TObject);
begin
  CmbRating.Enabled := RadSetRating.Checked;
end;

{-----------------------------------------------------------------------------}

procedure TScanForm.BtnAddClick(Sender: TObject);
begin

  //All this code is to get the initally selected directory.
  if ListDirs.ItemIndex <> -1 then
    jvBrowse.Directory := ListDirs.Items[ListDirs.itemIndex]
  else
    jvBrowse.Directory := FPreviousScanDir;

  //now actually execute the dialog and add the result to the list.
  if (jvBrowse.execute) and (DirectoryExists(jvBrowse.Directory)) then
  begin

    //add the directory to the list
    ListDirs.Items.Add(jvBrowse.Directory);

    //change the last previous scan directory to this one
    FPreviousScanDir := jvBrowse.Directory;
    
  end;
end;

{-----------------------------------------------------------------------------}

procedure TScanForm.BtnMinusClick(Sender: TObject);
begin
  ListDirs.DeleteSelected;
end;

{-----------------------------------------------------------------------------}

procedure TScanForm.CmbEmuChange(Sender: TObject);
begin
  //now load custom filters (if any)
  SetupFileExts(MainFrm.EmuList[MainFrm.EmuList.IndexOfName(CmbEmu.Text)].System);
end;

{-----------------------------------------------------------------------------}

end.
