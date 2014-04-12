unit fMediaPanelOptions;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Mask, JvExMask, JvSpin, ExtCtrls, ComCtrls, JvExStdCtrls,
  JvButton, JvCtrls, VirtualTrees, uMediaPanelClasses, JvComponent, JvBaseDlg,
  JvBrowseFolder, Spin, JvToolEdit, activeX, uMediaMiscTypes, JvComponentBase,
  fJWinFontForm;

type
  TFrmMediaPanelOptions = class(TJWinFontForm)
    BtnOK: TButton;
    BtnCancel: TButton;
    PanHeader: TPanel;
    lblHeader: TLabel;
    Image1: TImage;
    VTTabs: TVirtualStringTree;
    pgMediaOptions: TPageControl;
    VTSystems: TVirtualStringTree;
    TabGeneral: TTabSheet;
    TabPaths: TTabSheet;
    ChkEmuTab: TCheckBox;
    pgConfig: TPageControl;
    TabSystemConfig: TTabSheet;
    TabTabConfig: TTabSheet;
    pgTabOptions: TPageControl;
    TabThumbnails: TTabSheet;
    lblThumbHeight: TLabel;
    lblThumbWidth: TLabel;
    lblThbHorzGap: TLabel;
    lblThbVertGap: TLabel;
    RadThumbBottom: TRadioButton;
    RadThumbOnTop: TRadioButton;
    ChkThumbCaption: TCheckBox;
    TabImages: TTabSheet;
    GrpPaths: TGroupBox;
    LstPaths: TListBox;
    BtnAddDir: TJvImgBtn;
    BtnAddCompress: TJvImgBtn;
    BtnDelMedia: TJvImgBtn;
    ChkCloneSearch: TCheckBox;
    jvBrowse: TJvBrowseForFolderDialog;
    CmbTabType: TComboBox;
    lblSystems: TLabel;
    lblTabs: TLabel;
    ChkEnableSlideshow: TCheckBox;
    lblTimeOut: TLabel;
    lblSeconds: TLabel;
    ChkShowControlBar: TCheckBox;
    TxtImageSlideTime: TSpinEdit;
    TabTextConfig: TTabSheet;
    CmbSearchMatch: TComboBox;
    ChkSearchROMdir: TCheckBox;
    btnDeleteDefaultTab: TJvImgBtn;
    btnAddDefaultTab: TJvImgBtn;
    BtnFontChange: TButton;
    ShpFontColour: TShape;
    lblFontName: TLabel;
    lblFontSize: TLabel;
    lblFontStyle: TLabel;
    TxtThumbVertGap: TSpinEdit;
    TxtThumbHorzGap: TSpinEdit;
    TxtThumbWidth: TSpinEdit;
    TxtThumbHeight: TSpinEdit;
    TxtSysImage: TJvFilenameEdit;
    lblSysImage: TLabel;
    ChkShowAddInfo: TCheckBox;
    MemoSysInfo: TMemo;
    lblSystemConfigHeader: TLabel;
    GrpFolderImg: TRadioGroup;
    GrpAutoMove: TGroupBox;
    TxtTimePerTab: TSpinEdit;
    ChkAutoMoveThroughTabs: TCheckBox;
    procedure BtnAddCompressClick(Sender: TObject);
    procedure VTTabsCompareNodes(Sender: TBaseVirtualTree; Node1,
      Node2: PVirtualNode; Column: TColumnIndex; var Result: Integer);
    procedure VTTabsDragDrop(Sender: TBaseVirtualTree; Source: TObject;
      DataObject: IDataObject; Formats: TFormatArray; Shift: TShiftState;
      Pt: TPoint; var Effect: Integer; Mode: TDropMode);
    procedure VTTabsDragOver(Sender: TBaseVirtualTree; Source: TObject;
      Shift: TShiftState; State: TDragState; Pt: TPoint; Mode: TDropMode;
      var Effect: Integer; var Accept: Boolean);
    procedure BtnOKClick(Sender: TObject);
    procedure TabSystemConfigExit(Sender: TObject);
    procedure VTTabsChecked(Sender: TBaseVirtualTree; Node: PVirtualNode);
    procedure TabTabConfigExit(Sender: TObject);
    procedure BtnFontChangeClick(Sender: TObject);
    procedure btnAddDefaultTabClick(Sender: TObject);
    procedure btnDeleteDefaultTabClick(Sender: TObject);
    procedure BtnDelMediaClick(Sender: TObject);
    procedure BtnAddDirClick(Sender: TObject);
    procedure VTTabsFocusChanging(Sender: TBaseVirtualTree; OldNode,
      NewNode: PVirtualNode; OldColumn, NewColumn: TColumnIndex;
      var Allowed: Boolean);
    procedure VTSystemsFocusChanging(Sender: TBaseVirtualTree; OldNode,
      NewNode: PVirtualNode; OldColumn, NewColumn: TColumnIndex;
      var Allowed: Boolean);
    procedure FormCreate(Sender: TObject);
    procedure VTSystemsGetImageIndex(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
      var Ghosted: Boolean; var ImageIndex: Integer);
    procedure FormShow(Sender: TObject);
    procedure VTTabsGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType; var CellText: WideString);
    procedure VTSystemsGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType; var CellText: WideString);
    procedure VTTabsInitNode(Sender: TBaseVirtualTree; ParentNode,
      Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
  private
    { Private declarations }
    _CacheLastDir : String;
    _ms : TJMediaSearch;
    _SelectedSystem : Integer;
    _SelectedTab : Integer;
    procedure SetEnabledTabs();
    procedure LoadSystemConfig();
    procedure SaveSystemConfig();
    procedure LoadTabConfig(Tab : PTabRec);
    procedure SaveTabConfig();
    procedure UpdateTextFont(WithFont : TFont);
  public
    { Public declarations }
    Property MS : TJMediaSearch read _ms write _ms;
  end;

implementation

uses JCLStrings, IniFiles, fMain, fMediaAddDefaultTab,
     uMediaTabClass;

{$R *.dfm}

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.SetEnabledTabs();
var
  aNode : PVirtualNode;
  _TabIndex : Integer;
  TabRec : PTabRec;
begin

  //Load which tabs are enabled/disabled for this system
  VTTabs.BeginUpdate;
  try

  aNode := VTTabs.GetFirst;
  while aNode <> nil do
  begin
    TabRec := VTTabs.GetNodeData(aNode);

    _TabIndex := MS.Systems[_SelectedSystem].IndexOf(TabRec^.Name);

    if (_TabIndex <> -1) and
       (MS.Systems[_SelectedSystem].Tabs[_TabIndex].Enabled) then
      VTTabs.CheckState[aNode] := csCheckedNormal
    else
      VTTabs.CheckState[aNode] := csUncheckedNormal;
   
    aNode := VTTabs.GetNextSibling(aNode);

  end; //end of while statement

  finally
    VTTabs.EndUpdate;
  end;
  
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.LoadSystemConfig();
begin
  ChkShowAddInfo.Checked := MS.Systems[_SelectedSystem].ShowInfo;
  TxtSysImage.FileName := MS.Systems[_SelectedSystem].SystemImage;
  memoSysInfo.Clear;
  memoSysInfo.Lines.AddStrings(MS.Systems[_SelectedSystem].AdditionalInfo);
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.SaveSystemConfig();
begin
  MS.Systems[_SelectedSystem].ShowInfo := ChkShowAddInfo.Checked;
  MS.Systems[_SelectedSystem].SystemImage := TxtSysImage.FileName;
  MS.Systems[_SelectedSystem].AdditionalInfo.Clear;
  MS.Systems[_SelectedSystem].AdditionalInfo.AddStrings(memoSysInfo.Lines);
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.LoadTabConfig(Tab : PTabRec);
var
  MediaTab : TJMediaTab;
begin
  self._SelectedTab := MS.Systems[_SelectedSystem].IndexOf(Tab.Name);

  if _SelectedTab = -1 then
  begin
    //Not found, no configuration present.  Create config and set defaults.
    _SelectedTab := MS.Systems[_SelectedSystem].AddNewTab;
    MediaTab := MS.Systems[_SelectedSystem].Tabs[_SelectedTab];
    MediaTab.Caption := Tab.Name;

    if Tab.DefaultType = jTabSystem then
    begin
      MediaTab.TabType := jTabSystem;
      pgConfig.ActivePageIndex := 0;
      LoadSystemConfig();
    end
    else
    begin
      pgConfig.ActivePageIndex := 1;
      CmbTabType.ItemIndex := Integer(Tab.DefaultType);
      CmbSearchMatch.ItemIndex := 0;
      ChkCloneSearch.Checked := False;
      LstPaths.Clear;
      ChkSearchROMDir.Checked := False;
      pgTabOptions.ActivePageIndex := 0;

      //set the options values
      TxtThumbHeight.Value := 120;
      TxtThumbWidth.Value := 120;
      TxtThumbHorzGap.Value := 4;
      TxtThumbVertGap.Value := 4;
      RadThumbBottom.Checked := True;
      ChkThumbCaption.Checked := True;

      ChkEnableSlideshow.Checked := True;
      TxtImageSlideTime.Value := 5;
      ChkShowControlBar.Checked := True;

      updateTextFont(MediaTab.TextOpt);
    end;
  end
  else
  begin
    //Tab found, load configuration.
    MediaTab := MS.Systems[_SelectedSystem].Tabs[_SelectedTab];

    if MediaTab.Tabtype = jTabSystem then
    begin
      pgConfig.ActivePageIndex := 0;
      LoadSystemConfig();
    end
    else
    begin
      pgConfig.ActivePageIndex := 1;
      CmbTabType.ItemIndex := Integer(MediaTab.TabType);
      CmbSearchMatch.ItemIndex := Integer(MediaTab.SearchType);
      ChkCloneSearch.Checked := MediaTab.MAMEuseParentForSearch;
      ChkSearchROMDir.Checked := MediaTab.SearchInROMPath;
      LstPaths.Clear;
      LstPaths.Items.AddStrings(MediaTab.Paths);

      //now load the tab specific options.
      TxtThumbHeight.Value := MediaTab.ThumbOpt.Height;
      TxtThumbWidth.Value := MediaTab.ThumbOpt.Width;
      TxtThumbHorzGap.Value := MediaTab.ThumbOpt.HorizontalGap;
      TxtThumbVertGap.Value := MediaTab.ThumbOpt.VerticalGap;
      if MediaTab.ThumbOpt.CaptionOnTop then
        RadThumbOnTop.Checked := True
      else
        RadThumbBottom.Checked := True;

      ChkThumbCaption.Checked := MediaTab.ThumbOpt.ShowCaption;

      ChkEnableSlideshow.Checked := MediaTab.ImageOpt.SlideShowEnabled;
      TxtImageSlideTime.Value := MediaTab.ImageOpt.SlideShowTimeout;
      ChkShowControlBar.Checked := MediaTab.ImageOpt.ShowControlBar;

      updateTextFont(MediaTab.TextOpt);
    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.SaveTabConfig();
var
  MediaTab : TJMediaTab;
begin
  MediaTab := MS.Systems[_SelectedSystem].Tabs[_SelectedTab];

  MediaTab.TabType := TJTabType(CmbTabType.ItemIndex);
  MediaTab.SearchType := TJSearchType(CmbSearchMatch.ItemIndex);
  MediaTab.MAMEuseParentForSearch := ChkCloneSearch.Checked;
  MediaTab.SearchInROMPath := ChkSearchROMDir.Checked;
  MediaTab.Paths.Clear;
  MediaTab.Paths.AddStrings(LstPaths.Items);

  With MediaTab.ThumbOpt do
  begin
    Width := TxtThumbWidth.Value;
    Height := TxtThumbHeight.Value;
    VerticalGap := TxtThumbVertGap.Value;
    HorizontalGap := TxtThumbHorzGap.Value;
    ShowCaption := ChkThumbCaption.Checked;
    CaptionOnTop := RadThumbOnTop.Checked; 
  end;

  With MediaTab.ImageOpt do
  begin
    SlideShowEnabled := ChkEnableSlideShow.Checked;
    SlideShowTimeout := TxtImageSlideTime.Value;
    ShowControlBar := ChkShowControlBar.Checked;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.UpdateTextFont(WithFont : TFont);
begin
  lblFontName.Caption := withFont.Name;
  lblFontSize.Caption := IntToStr(withFont.Size);
  shpFontColour.Brush.Color := withFont.Color;

  lblFontStyle.Caption := '';
  if (fsBold in WithFont.Style) then
    lblFontStyle.Caption := lblFontStyle.Caption + 'Bold ';

  if (fsItalic in WithFont.Style) then
    lblFontStyle.Caption := lblFontStyle.Caption + 'Italic ';

  if (fsUnderLine in WithFont.Style) then
    lblFontStyle.Caption := lblFontStyle.Caption + 'Underline ';

  if (fsStrikeOut in WithFont.Style) then
    lblFontStyle.Caption := lblFontStyle.Caption + 'Strikethrough ';
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.FormCreate(Sender: TObject);
var
  i : Integer;
  Ini : TMemIniFile;
begin
  pgMediaOptions.ActivePageIndex := 0;

  pgConfig.ActivePageIndex := 0;
  for i := 0 to pgConfig.PageCount-1 do
    pgConfig.Pages[i].TabVisible := False;

  //load in the CacheLastDir value.
  Ini := TMemIniFile.Create(MainFrm.Settings.Paths.SettingsFile);
  try
    _CacheLastDir := Ini.ReadString('MOCache', 'LastDir', '');
  finally
    FreeAndNil(Ini);
  end;

end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.FormShow(Sender: TObject);
begin
  if MS <> nil then
  begin
    //set the configuration options.
    ChkEmuTab.Checked := MS.AddEmuTab;
    ChkAutoMoveThroughTabs.Checked := MS.AutoMove;
    TxtTimePerTab.Value := MS.TimePerTab;
    GrpFolderImg.ItemIndex := Integer(MS.DefaultFolderImg);

    VTSystems.RootNodeCount := MS.SystemCount;

    VTTabs.NodeDataSize := SizeOf(TTabRec);
    VTTabs.RootNodeCount := MS.TabCount;

    VTSystems.Selected[VTSystems.GetFirst] := True;
    VTSystems.FocusedNode := VTSystems.GetFirst;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.BtnAddDirClick(Sender: TObject);
begin
  //Set the initial directory.
  if (_CacheLastDir <> '') and (DirectoryExists(_CacheLastDir)) then
    jvBrowse.Directory := _CacheLastDir;

  if jvBrowse.execute then
    if jvBrowse.Directory <> '' then
    begin
      LstPaths.Items.Add(jvBrowse.Directory);
      _CacheLastDir := jvBrowse.Directory;
    end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.BtnDelMediaClick(Sender: TObject);
begin
  LstPaths.Items.Delete(LstPaths.itemindex);
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.VTSystemsFocusChanging(Sender: TBaseVirtualTree;
  OldNode, NewNode: PVirtualNode; OldColumn, NewColumn: TColumnIndex;
  var Allowed: Boolean);
begin
  if (NewNode <> nil) and (OldNode <> NewNode) then
  begin
    Allowed := True;
    
    Self._SelectedSystem := NewNode.Index;
    pgConfig.ActivePageIndex := 0;
    LoadSystemConfig();

    SetEnabledTabs();
    VTTabs.SortTree(0, sdAscending, True);
  end
  else
    Allowed := False;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.VTSystemsGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin
  if Node <> nil then
    CellText := MS.Systems[Node.Index].Caption;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.VTSystemsGetImageIndex(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
  var Ghosted: Boolean; var ImageIndex: Integer);
begin
  if Node <> nil then
    ImageIndex := 0;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.VTTabsInitNode(Sender: TBaseVirtualTree;
  ParentNode, Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
var
  Data : PTabRec;
begin
  Sender.CheckType[Node] := ctCheckBox;
  Data := Sender.GetNodeData(Node);
  Data.Name := MS.Tabs[Node.Index].Name;
  Data.DefaultType := MS.Tabs[Node.Index].DefaultType;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.VTTabsGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
var
  Data : PTabRec;
begin
  if Node <> nil then
  begin
    Data := Sender.GetNodeData(Node);
    CellText := Data.Name;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.VTTabsFocusChanging(Sender: TBaseVirtualTree;
  OldNode, NewNode: PVirtualNode; OldColumn, NewColumn: TColumnIndex;
  var Allowed: Boolean);
var
  Data : PTabRec;
begin
  if (NewNode <> nil) then
  begin
    Allowed := True;
    Data := Sender.GetNodeData(NewNode);
    LoadTabConfig(Data);

    SetEnabledTabs();
    VTTabs.SortTree(0, sdAscending, True);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.btnDeleteDefaultTabClick(Sender: TObject);
var
  i : Integer;
  data : PTabRec;
begin
  if VTTabs.FocusedNode <> nil then
  begin
    VTTabs.BeginUpdate;
    try
      Data := VTTabs.GetNodeData(VTTabs.FocusedNode);

      for i := 0 to MS.TabCount-1 do
        if JCLStrings.StrCompare(MS.Tabs[i].Name, Data^.Name) = 0 then
        begin
          MS.DeleteDefaultTab(i);
          VTTabs.DeleteNode(VTTabs.FocusedNode);
          Break;
        end;

    finally
      VTTabs.EndUpdate;
    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.BtnAddCompressClick(Sender: TObject);
var
  OpenDlg : TOpenDialog;
begin
  //Set the initial directory.
  OpenDlg := TopenDialog.Create(Self);
  try

    OpenDlg.Filter := 'Zip Files (*.zip)|*.zip|Dat Files (*.dat)|*.dat';
    if (_CacheLastDir <> '') and (DirectoryExists(_CacheLastDir)) then
      OpenDlg.InitialDir := _CacheLastDir;

    if (OpenDlg.execute) and (OpenDlg.FileName <> '') then
    begin
      LstPaths.Items.Add(OpenDlg.FileName);
      _CacheLastDir := ExtractfilePath(OpenDlg.FileName);
    end;
  finally
    FreeAndNil(OpenDlg);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.btnAddDefaultTabClick(Sender: TObject);
var
  Add : TFrmAddDefaultTab;
begin
  Add  := TFrmAddDefaultTab.Create(self);
  try
    if Add.ShowModal = MrOK then
    begin
      MS.AddDefaultTab(Add.TxtCaption.Text, TJTabType(Add.CmbType.ItemIndex));
      VTTabs.AddChild(nil);
    end;
  finally
    FreeAndNil(Add);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.BtnFontChangeClick(Sender: TObject);
var
  FontDlg : TFontDialog;
begin
  FontDlg := TFontDialog.Create(Self);
  try

    if (_SelectedSystem > -1) and (_SelectedTab > -1) then
      FontDlg.Font.Assign(MS.Systems[_SelectedSystem].Tabs[_SelectedTab].TextOpt);

    if FontDlg.Execute then
    begin
      MS.Systems[_SelectedSystem].Tabs[_SelectedTab].TextOpt.Assign(FontDlg.Font);
      UpdateTextFont(FontDlg.Font);
    end;

  finally
    FreeAndNil(FontDlg);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.TabTabConfigExit(Sender: TObject);
begin
  Self.SaveTabConfig();
  SetEnabledTabs();
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.VTTabsChecked(Sender: TBaseVirtualTree;
  Node: PVirtualNode);
var
  Index : Integer;
  Tab : PTabRec;
begin
  Tab := Sender.GetNodeData(Node);

  Index := MS.Systems[_SelectedSystem].IndexOf(Tab^.Name);

  if Index = -1 then
  begin
    Index := MS.Systems[_SelectedSystem].AddNewTab;
    MS.Systems[_SelectedSystem].Tabs[Index].Caption := Tab^.Name;
    MS.Systems[_SelectedSystem].Tabs[Index].TabType := Tab^.DefaultType;
  end;

  //by now index will point to either a previous tab, or a newly created one.
  if Sender.CheckState[Node] in [csCheckedNormal, csCheckedPressed] then
    MS.Systems[_SelectedSystem].Tabs[Index].Enabled := True
  else
    MS.Systems[_SelectedSystem].Tabs[Index].Enabled := False;

  Sender.Sort(Node, 0, sdAscending, true);
  //Sender.SortTree(0, sdAscending, True);

end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.TabSystemConfigExit(Sender: TObject);
begin
  Self.SaveSystemConfig();
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.BtnOKClick(Sender: TObject);
var
  ini : TMemIniFile;
begin
  //change general media settings.
  MS.AutoMove := ChkAutoMoveThroughTabs.Checked;
  MS.TimePerTab := TxtTimePerTab.Value;
  MS.AddEmuTab := ChkEmuTab.Checked;
  MS.DefaultFolderImg := TJMediaFolderImg(GrpFolderImg.ItemIndex);

  Ini := TMemIniFile.Create(MainFrm.Settings.Paths.SettingsFile);
  try
    Ini.WriteString('MOCache', 'LastDir', _CacheLastDir);
    Ini.UpdateFile();
  finally
    FreeAndNil(Ini);
  end;

end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.VTTabsDragOver(Sender: TBaseVirtualTree;
  Source: TObject; Shift: TShiftState; State: TDragState; Pt: TPoint;
  Mode: TDropMode; var Effect: Integer; var Accept: Boolean);
begin
  if (Source = VTTabs) then
    if (Sender.CheckState[Sender.FocusedNode] <> csCheckedNormal) then
      Accept :=False
    else  Accept := True;             
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.VTTabsDragDrop(Sender: TBaseVirtualTree;
  Source: TObject; DataObject: IDataObject; Formats: TFormatArray;
  Shift: TShiftState; Pt: TPoint; var Effect: Integer; Mode: TDropMode);
var
  AttachMode : TVTNodeAttachMode;
  Index, DropIndex, NewIndex : Integer;
  tab, droptab : PTabRec;
begin
  if DataObject = nil then
  begin
    // VCL drag'n drop. 
    if Source = VTTabs then
    begin

      tab := Sender.GetNodeData(Sender.FocusedNode);
      Index := MS.Systems[_Selectedsystem].IndexOf(Tab^.Name);

      if (Sender.DropTargetNode = nil) or (Index = -1) then
        exit;

      //get the droptarget tab.
      DropTab := Sender.GetNodeData(Sender.DropTargetNode);
      DropIndex := MS.Systems[_SelectedSystem].IndexOf(DropTab^.Name);

      if (DropIndex = -1) or
         (MS.Systems[_SelectedSystem].Tabs[DropIndex].Enabled = False) then
        exit;

      NewIndex := -1;

      case Mode of
      dmAbove:
      begin
        AttachMode := amInsertBefore;
        NewIndex := DropIndex;
      end;
      dmOnNode, dmBelow:
      begin
        AttachMode := amInsertAfter;
        NewIndex := DropIndex+1;
      end;
      else
        if Assigned(Source) and (Source is TBaseVirtualTree) and (Sender <> Source) then
        begin
          AttachMode := amInsertBefore;
          NewIndex := DropIndex;
        end
        else
          AttachMode := amNowhere;
      end;

      // Since we know this is a Virtual Treeview we can ignore the drop event entirely and use VT mechanisms.
      Effect := DROPEFFECT_MOVE;

      //since by this point we have ruled out moving beyond the bounds of active tabs
      // the just go ahead and do the move.
      if (NewIndex > -1) and (NewIndex < MS.Systems[_SelectedSystem].TabCount) then
      begin
        MS.Systems[_SelectedSystem].MoveTab(Index, NewIndex);
        VTTabs.MoveTo(Sender.FocusedNode, Sender.DropTargetNode, AttachMode, False);
      end;
    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMediaPanelOptions.VTTabsCompareNodes(Sender: TBaseVirtualTree;
  Node1, Node2: PVirtualNode; Column: TColumnIndex; var Result: Integer);
var
  tab1, tab2 : PTabRec;
  pos1, pos2 : Integer;
  jTab1, jTab2 : TJMediaTab;
begin

// 0 = equal, -1 = node1 before node2, 1 = node1 after node2

  if (Node1 <> nil) and (Node2 <> nil) then
  begin

    tab1 := Sender.GetNodeData(Node1);
    Tab2 := Sender.GetNodeData(Node2);
    Pos1 := MS.Systems[_SelectedSystem].IndexOf(Tab1^.Name);
    Pos2 := MS.Systems[_SelectedSystem].IndexOf(Tab2^.Name);

    if (Pos1 = -1) and (Pos2 = -1) then
    begin
      //if they are both -1 then ignore this..
      Result := 0
    end

    else if (Pos1 = -1) or (Pos2 = -1) then
    begin
      //one is set to -1 figure out which!
      if Pos1 = -1 then
        Result := 1
      else
        Result := -1;
    end

    else
    begin
      //ok if we are this far then both tabs are in the system.  perform checks.
      jtab1 := MS.Systems[_SelectedSystem].Tabs[Pos1];
      jtab2 := MS.Systems[_SelectedSystem].Tabs[Pos2];

      if ((jtab1.Enabled = False) and (jtab2.Enabled = False)) then
      begin
        //neither is active, so we can ignore them.
        Result := 0
      end
      else if ((jTab1.Enabled) and (jtab2.Enabled)) then
      begin
        //both are enabled, compare by index.
        Result := Pos1 - Pos2;
      end
      else
      begin
        //one is enabled one isnt.. find out which
        if jtab1.Enabled then
          Result := -1
        else
          Result := 1;
      end;
    end;

  end;      

end;

{-----------------------------------------------------------------------------}

end.
