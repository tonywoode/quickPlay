unit fAppearanceOptions;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms,
  Dialogs, ExtDlgs, StdCtrls, ExtCtrls, VirtualTrees, ComCtrls, Contnrs, Spin,
  fjWinFontForm, JvBrowseFolder;

type
  TFrmAppearanceOptions = class(TjWinFontForm)
    pgAppearance: TPageControl;
    TabLayout: TTabSheet;
    ChkSidebarTabs: TCheckBox;
    grpLayout: TGroupBox;
    ImgNormal: TImage;
    ImgPanBottom: TImage;
    ImgDirOnTop: TImage;
    ImgVertical: TImage;
    RadNormal: TRadioButton;
    RadVertical: TRadioButton;
    RadDirOnTop: TRadioButton;
    RadImgToBottom: TRadioButton;
    BtnOK: TButton;
    BtnCancel: TButton;
    TabTreeConfig: TTabSheet;
    GrpColours: TGroupBox;
    colHotTrack: TColorBox;
    colUnSelected: TColorBox;
    colSelected: TColorBox;
    colBackground: TColorBox;
    BtnColourDefaults: TButton;
    GrpOptions: TGroupBox;
    Label4: TLabel;
    ChkGridlines: TCheckBox;
    ChkHotTrack: TCheckBox;
    ChkRowSelect: TCheckBox;
    chkShowHints: TCheckBox;
    TxtBGImagePath: TEdit;
    chkBGImage: TCheckBox;
    BtnImageFind: TButton;
    PanHeader: TPanel;
    Image1: TImage;
    lblHeader: TLabel;
    GrpFont: TGroupBox;
    lblFontStyle: TLabel;
    lblFontSize: TLabel;
    lblFontName: TLabel;
    ShpFontColour: TShape;
    BtnFontChange: TButton;
    VTTrees: TVirtualStringTree;
    TxtSelectionCurve: TSpinEdit;
    ChkEmuRealIcons: TCheckBox;
    lblRealEmuIcons: TLabel;
    GrpROMOptions: TGroupBox;
    ChkCol: TCheckBox;
    ChkIncVersion: TCheckBox;
    ChkListImages: TCheckBox;
    GrpColView: TGroupBox;
    VTShowCols: TVirtualStringTree;
    ChkToolRealIcons: TCheckBox;
    TxtMameExtrasDirPath: TEdit;
    BtnMameExtrasDirFind: TButton;
    MameExtrasLabel: TLabel;
    RadGrpDirExpand: TRadioGroup;
    procedure MameExtrasLabelClick(Sender: TObject);

    procedure VTTreesFocusChanging(Sender: TBaseVirtualTree; OldNode,
      NewNode: PVirtualNode; OldColumn, NewColumn: TColumnIndex;
      var Allowed: Boolean);
    procedure VTTreesGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType; var CellText: WideString);
    procedure BtnColourDefaultsClick(Sender: TObject);
    procedure BtnImageFindClick(Sender: TObject);
    procedure BtnMameExtrasDirFindClick(Sender: TObject);
    procedure BtnFontChangeClick(Sender: TObject);
    procedure BtnOKClick(Sender: TObject);
    procedure VTShowColsGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType; var CellText: WideString);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
    _Trees : TObjectList;
    procedure FontChange(Own: TComponent; Name, Size, Style: TLabel;
      Colour: TShape);
    Procedure LoadVTConfig(Index : Integer);
    Procedure SaveVTConfig(Index : Integer);
  public
    { Public declarations }
  end;

implementation

uses JCLStrings, fMain, IniFiles, uJVirtualTree, uQPMiscTypes;

{$R *.dfm}

{-----------------------------------------------------------------------------}

procedure TFrmAppearanceOptions.FontChange(Own : TComponent; Name, Size, Style : TLabel; Colour : TShape);
var
  FontD : TFontDialog;
begin
  FontD := TFontDialog.Create(Self);
  try
    if Name.Caption <> '' then
      FontD.Font.Name := name.Caption
    else
      FontD.Font.Name := 'Tahoma';

    if Size.Caption <> '' then
      FontD.Font.Size := StrToInt(Size.Caption)
    else
      FontD.Font.Size := 8;

    FontD.Font.Color := Colour.Brush.Color;

    if pos('Bold', style.caption) <> 0 then
      FontD.Font.Style := FontD.font.Style + [fsbold];

    if pos('Italic', style.caption) <> 0 then
      FontD.Font.Style := FontD.font.Style + [fsItalic];

    if pos('Underline', style.caption) <> 0 then
      FontD.Font.Style := FontD.font.Style + [fsUnderLine];

    if pos('Strikethrough', style.caption) <> 0 then
      FontD.Font.Style := FontD.font.Style + [fsstrikeout];

    If FontD.Execute then
    Begin
      name.Caption := FontD.Font.Name;
      size.Caption := IntToStr(FontD.Font.Size);
      Colour.Brush.Color := FontD.Font.Color;

      Style.Caption := '';


      if FontD.Font.Style >= [fsBold] then
        style.Caption := Style.Caption + 'Bold ';

      if FontD.Font.Style >= [fsItalic] = true then
        Style.Caption := Style.Caption + 'Italic ';

      if FontD.Font.Style >= [fsUnderLine] = true then
        Style.Caption := Style.Caption + 'Underline ';

      if FontD.Font.Style >= [fsstrikeout] = true then
        Style.Caption := Style.Caption + 'Strikethrough';
    end;

  finally
    FreeAndNil(FontD);
  end;
end;

{-----------------------------------------------------------------------------}

Procedure TFrmAppearanceOptions.LoadVTConfig(Index : Integer);
var
  Cfg : TJVTConfig;
begin
  Cfg := TJVTConfig(_Trees[Index]);

  ChkBGImage.Checked := Cfg.EnableBGImage;
  TxtBGImagePath.Text := Cfg.BGImageValue;

  ChkShowHints.Checked := Cfg.ShowHints;
  ChkRowSelect.Checked := Cfg.RowSelect;
  ChkHotTrack.Checked := cfg.HotTrack;
  ChkGridlines.Checked := Cfg.ShowGridlines;

  TxtSelectionCurve.Value := Cfg.SelectionCurve;

  //Colour Setup
  ColBackground.Selected := Cfg.ColourBackground;
  ColSelected.Selected := cfg.ColourFocus;
  ColUnSelected.Selected := cfg.ColourUnfocus;
  ColHotTrack.Selected := cfg.ColourHotTrack;

  //font setup
  lblFontName.Caption := Cfg.VTFont.Name;
  shpFontColour.Brush.Color := Cfg.VTFont.Color;
  lblFontSize.Caption := IntToStr(Cfg.VTFont.Size);

  lblFontStyle.caption := '';
  if (fsBold in Cfg.VTFont.Style) then
    lblFontStyle.Caption := lblFontStyle.Caption + 'Bold ';

  if (fsItalic in Cfg.VTFont.Style) then
    lblFontStyle.Caption := lblFontStyle.Caption + 'Italic ';

  if (fsUnderLine in Cfg.VTFont.Style) then
    lblFontStyle.Caption := lblFontStyle.Caption + 'Underline ';

  if (fsStrikeOut in Cfg.VTFont.Style) then
    lblFontStyle.Caption := lblFontStyle.Caption + 'Strikethrough ';
    // end of ROM list setup code
end;

procedure TFrmAppearanceOptions.MameExtrasLabelClick(Sender: TObject);
begin

end;

{-----------------------------------------------------------------------------}

Procedure TFrmAppearanceOptions.SaveVTConfig(Index : Integer);
var
  Cfg : TJVTConfig;
  PBool : PBoolean;
begin
  Cfg := TJVTConfig(_Trees[Index]);

  Cfg.EnableBGImage := ChkBGImage.Checked;
  Cfg.BGImageValue := TxtBGImagePath.Text;

  if JCLStrings.StrCompare(CFG.VT.Name, 'VTRoms') = 0 then
  begin
    pBool := @MainFrm.Settings.Backgrounds.DefaultROMBG;
    pBool^ := Cfg.EnableBGImage;
  end;

  Cfg.ShowHints := ChkShowHints.Checked;
  Cfg.RowSelect := ChkRowSelect.Checked;
  cfg.HotTrack := ChkHotTrack.Checked;
  Cfg.ShowGridlines := ChkGridlines.Checked;

  Cfg.SelectionCurve := TxtSelectionCurve.Value;

  //Colour Setup
  Cfg.ColourBackground := ColBackground.Selected;
  cfg.ColourFocus := ColSelected.Selected;
  cfg.ColourUnfocus := ColUnSelected.Selected;
  cfg.ColourHotTrack := ColHotTrack.Selected;

  //font setup
  Cfg.VTFont.Name := lblFontName.Caption;
  Cfg.VTFont.Color := shpFontColour.Brush.Color;
  Cfg.VTFont.Size := StrToInt(lblFontSize.Caption);

  Cfg.VTFont.Style := [];
  if pos('Bold', lblFontStyle.Caption) <> 0 then
    Cfg.VTFont.Style := Cfg.VTFont.Style + [fsbold];

  if pos('Italic', lblFontStyle.Caption) <> 0 then
    Cfg.VTFont.Style := Cfg.VTFont.Style + [fsItalic];

  if pos('Underline', lblFontStyle.Caption) <> 0 then
    Cfg.VTFont.Style := Cfg.VTFont.Style + [fsUnderLine];

  if pos('Strikethrough', lblFontStyle.Caption) <> 0 then
    Cfg.VTFont.Style := Cfg.VTFont.Style + [fsstrikeout];

end;

{-----------------------------------------------------------------------------}

procedure TFrmAppearanceOptions.FormCreate(Sender: TObject);
var
  Ini : TMemInifile;
  Node : PVirtualNode;
  i : Integer;
begin

  _Trees := TObjectList.Create(True);

  With MainFrm do
  begin
    _Trees.Add(TJVTConfig.Create(@VTRoms, 'ROM List', @Settings.Backgrounds.RomBG));
    _Trees.Add(TJVTConfig.Create(@VTdir, 'Folder List', @Settings.Backgrounds.DirBG));
    _Trees.Add(TJVTConfig.Create(@VTSearches, 'Searches List', @Settings.Backgrounds.SearchBG));
    _Trees.Add(TJVTConfig.Create(@VTEmus, 'Emulators List', @Settings.Backgrounds.EmuBG));
    _Trees.Add(TJVTConfig.Create(@vtTools, 'Tools List', @Settings.Backgrounds.ToolBG));
  end;

  for i := 0 to _Trees.Count-1 do
    TJVTConfig(_Trees[i]).LoadFromTree();

  VTTrees.RootNodeCount := _Trees.Count;
  VTTrees.FocusedNode := VTTrees.GetFirst;
  VTTrees.Selected[VTTrees.GetFirst] := True;

  Ini := TMemInifile.create(MainFrm.Settings.Paths.SettingsFile);
  try

    //set up the columns treeview
    VTShowCols.RootNodeCount := MainFrm.VTRoms.Header.Columns.Count;

    Node := VTShowCols.GetFirst;
    while Node <> nil do
    begin
      VTShowCols.CheckType[Node] := ctCheckBox;
      If Ini.ReadBool('ColView', IntToStr(Node.Index), true) then
        VTShowCols.CheckState[Node] := csCheckedNormal;
      Node := VTShowCols.GetNextSibling(Node);
    end;

  finally
    FreeAndNil(Ini);
  end;

  with MainFrm do
  begin
    // ROM list options
    ChkListImages.Checked := Settings.UseImagesForROMs;
    ChkIncVersion.Checked := Settings.AddVersion;
    ChkCol.Checked := Settings.SaveColumnSize;

    ChkSidebarTabs.Checked := Settings.ShowTabsInSideBar;
    ChkEmuRealIcons.Checked := Settings.UseRealEmuIcons;
    ChkToolRealIcons.Checked := Settings.UseRealToolIcons;
    TxtMameExtrasDirPath.Text :=  Settings.MameExtrasDir;


    // UI settings
    Case WindowLayout of
      qpwVertical : RadVertical.Checked := True;
      qpwDirOnTop : RadDirOnTop.Checked := True;
      qpwImgToBottom : RadImgToBottom.Checked := True;
      else
        RadNormal.Checked := True;
    end;

    Settings.ShowTabsInSideBar := ChkSidebarTabs.Checked;
    RadGrpDirExpand.ItemIndex := Integer(Settings.FolderExpandMode);

  end; //end of WITH block

end;

{-----------------------------------------------------------------------------}

procedure TFrmAppearanceOptions.VTShowColsGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin
  CellText := MainFrm.VTRoms.Header.Columns.Items[Node.Index].Text;
end;

{-----------------------------------------------------------------------------}

procedure TFrmAppearanceOptions.BtnOKClick(Sender: TObject);
var
  aNode : PVirtualNode;
  Cols : Array of Boolean;
  i : Integer;
  Ini : TMemIniFile;
begin

  //save the currently selected tree options
  SaveVTConfig(VTTrees.FocusedNode.Index);

  with MainFrm do
  begin

    //configure and save all the trees

    ini := TMemIniFile.Create(Settings.Paths.SettingsFile);
    try
      for i := 0 to _Trees.Count-1 do
      begin
        TJVTConfig(_trees[i]).Configure;
        TJVTConfig(_trees[i]).SaveToIni(Ini);
      end;

      if Settings.AllowWrite then
        Ini.UpdateFile();
    finally
      FreeAndNil(Ini);
    end;

    //ROM list options
      
    Settings.SaveColumnSize := ChkCol.Checked;
    Settings.UseImagesForROMs := ChkListImages.Checked;
    Settings.AddVersion := ChkIncVersion.Checked;
    Settings.ShowTabsInSideBar := ChkSidebarTabs.Checked;
    Settings.FolderExpandMode := TQPFolderExpandMode(RadGrpDirExpand.ItemIndex);

    Settings.UseRealEmuIcons := ChkEmuRealIcons.Checked;
    Settings.UseRealToolIcons := ChkToolRealIcons.Checked;
    Settings.MameExtrasDir := TxtMameExtrasDirPath.Text;

    //Save the default columns, put them in an array and save them
    SetLength(Cols, VTRoms.Header.Columns.Count);

    aNode := VTShowCols.GetFirst;
    while aNode <> nil do
    begin
      If VTShowCols.CheckState[aNode] = csCheckedNormal then
        Cols[aNode.Index] :=  True
      else
        Cols[aNode.Index] :=  false;
        aNode := VTShowCols.GetNext(aNode);
    end;

    Settings.SaveDefaultColumns(Cols);

      //UI settings

    if RadNormal.Checked then
      WindowLayout := qpwNormal
    else if RadVertical.Checked then
      WindowLayout := qpwVertical
    else if RadDirOnTop.Checked then
      WindowLayout := qpwDirOnTop
    else if RadImgToBottom.Checked then
      WindowLayout := qpwImgToBottom
    else
      WindowLayout := qpwNormal; //something went wrong put it back to normal..

    //now save the settings
    Settings.SaveAllSettings();

  end;//end of WITH block
end;

{-----------------------------------------------------------------------------}

procedure TFrmAppearanceOptions.BtnFontChangeClick(Sender: TObject);
begin
  FontChange(Self, LblFontName, lblFontSize, lblFontStyle, ShpFontColour);
end;

{-----------------------------------------------------------------------------}

procedure TFrmAppearanceOptions.BtnImageFindClick(Sender: TObject);
var
  PicDlg : TOpenPictureDialog;
begin

  PicDlg := TOpenPictureDialog.Create(self);
  try

    if DirectoryExists(MainFrm.Settings.Paths.AppDir + 'images') then
      PicDlg.InitialDir := MainFrm.Settings.Paths.AppDir + 'images';

    PicDlg.Filter := 'GIF Images (*.gif)|*.gif|PNG Images (*.png)|*.png|Bitmap Images|*.bmp|All Files|*.*';
    if PicDlg.Execute then
      if (PicDlg.FileName <> '') AND (fileexists(PicDlg.FileName)) then
        TxtBGImagePath.Text := PicDlg.FileName;

  finally
    FreeAndNil(PicDlg);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmAppearanceOptions.BtnMameExtrasDirFindClick(Sender: TObject);
var
  jvBrowse: TJvBrowseForFolderDialog;
begin

  jvBrowse := TJvBrowseForFolderDialog.Create(self);

  try

   if DirectoryExists(MainFrm.Settings.MameExtrasDir) then
      jvBrowse.Directory := MainFrm.Settings.MameExtrasDir;

      if (jvBrowse.execute) and (DirectoryExists(jvBrowse.Directory)) then
        begin
        //put it in the text box
        TxtMameExtrasDirPath.Text := jvBrowse.Directory;
        //add the directory to the ini in the right section
        //ListDirs.Items.Add(jvBrowse.Directory);
        end;
  finally
    FreeAndNil(jvBrowse);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmAppearanceOptions.BtnColourDefaultsClick(Sender: TObject);
begin
  ColBackground.Selected := clWindow;
  ColSelected.Selected := clHighlight;
  ColUnselected.Selected := clBtnFace;
  ColHotTrack.Selected := clBlue;
end;

{-----------------------------------------------------------------------------}

procedure TFrmAppearanceOptions.VTTreesGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin
  if (Node <> nil) and (Column=0) then
    CellText := TJVTConfig(_Trees[Node.Index]).Caption;
end;

{-----------------------------------------------------------------------------}

procedure TFrmAppearanceOptions.VTTreesFocusChanging(Sender: TBaseVirtualTree;
  OldNode, NewNode: PVirtualNode; OldColumn, NewColumn: TColumnIndex;
  var Allowed: Boolean);
begin
  if OldNode <> NewNode then
  begin
    if OldNode <> nil then
      Self.SaveVTConfig(OldNode.Index);
    Self.LoadVTConfig(NewNode.Index);
  end;
end;

{-----------------------------------------------------------------------------}

end.
