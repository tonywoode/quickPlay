{
  Emulator Management form.
  This form is based around a VT, and a group box with the parameters
  of the emulator class.  The VT is interesting because it sorts the
  emulators by system, and actually loads in the emulators icon
  dynamically when a folder is expanded.  This can result in some
  slowdown when expanding nodes with lots of emulators.  Personally i
  like this feature, but its fairly easy to hack it out if there
  are too many complaints.
}          

unit fEmulators;

interface

uses
  Windows, Forms, ImgList, Controls, Dialogs, StdCtrls, Contnrs,
  Classes, SysUtils, Graphics, VirtualTrees, uEmu, uEmuList, uQPVTEditor,
  ExtCtrls, GraphicEx, ComCtrls, Mask, JvExMask, JvToolEdit, uQPMiscTypes,
  fParamVars, fJWinFontForm;

type

  PStringList = ^TStringList;

  TQPEmuOption = class(Tobject)
  private
    FSection : TQPEmuOptHead;
    FCaption : String;
    FEditType : TQPEditType;
    FValue : Pointer;
    FDataType : TQPDataType;
  public
    constructor Create(Section : TQPEmuOptHead; Caption : String; EditType : TQPEditType;
                Value : Pointer; DataType : TQPDataType);
    Property Section : TQPEmuOptHead read FSection write FSection;
    Property Caption : String Read FCaption write FCaption;
    Property EditType : TQPEditType read FEditType write FEditType;
    Property Value : Pointer read FValue write FValue;
    Property DataType : TQPDataType read FDataType write FDataType;
  end;


  TFrmEmuDlg = class(TJWinFontForm)
    VTEmus: TVirtualStringTree;
    VTEmuOpt: TVirtualStringTree;
    PanCtrls: TPanel;
    BtnAdd: TButton;
    BtnDelete: TButton;
    BtnOK: TButton;
    BtnCancel: TButton;
    Splitter1: TSplitter;
    pgEmuOpt: TPageControl;
    TabConfiguration: TTabSheet;
    TabMediaConfig: TTabSheet;
    MemoEmuInfo: TMemo;
    ChkShowAddInfo: TCheckBox;
    TxtEmuImage: TJvFilenameEdit;
    ChkAddEmuTab: TCheckBox;
    lblSysImage: TLabel;
    procedure VTEmusChange(Sender: TBaseVirtualTree; Node: PVirtualNode);
    procedure TxtEmuImageBeforeDialog(Sender: TObject; var Name: string;
      var Action: Boolean);
    procedure TxtEmuImageAfterDialog(Sender: TObject; var Name: string;
      var Action: Boolean);
    procedure TabMediaConfigExit(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure VTEmusInitNode(Sender: TBaseVirtualTree; ParentNode,
      Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
    procedure VTEmusGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure VTEmusInitChildren(Sender: TBaseVirtualTree;
      Node: PVirtualNode; var ChildCount: Cardinal);
    procedure VTEmusGetImageIndex(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
      var Ghosted: Boolean; var ImageIndex: Integer);
    procedure VTEmusCompareNodes(Sender: TBaseVirtualTree; Node1,
      Node2: PVirtualNode; Column: TColumnIndex; var Result: Integer);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormDestroy(Sender: TObject);
    procedure BtnAddClick(Sender: TObject);
    procedure BtnDeleteClick(Sender: TObject);
    procedure VTEmusPaintText(Sender: TBaseVirtualTree;
      const TargetCanvas: TCanvas; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType);
    procedure VTEmusFocusChanging(Sender: TBaseVirtualTree; OldNode,
      NewNode: PVirtualNode; OldColumn, NewColumn: TColumnIndex;
      var Allowed: Boolean);
    procedure VTEmusFreeNode(Sender: TBaseVirtualTree; Node: PVirtualNode);
    procedure VTEmuOptInitNode(Sender: TBaseVirtualTree; ParentNode,
      Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
    procedure VTEmuOptInitChildren(Sender: TBaseVirtualTree;
      Node: PVirtualNode; var ChildCount: Cardinal);
    procedure VTEmuOptGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure VTEmuOptGetImageIndex(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
      var Ghosted: Boolean; var ImageIndex: Integer);
    procedure VTEmuOptChange(Sender: TBaseVirtualTree; Node: PVirtualNode);
    procedure VTEmuOptCreateEditor(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex; out EditLink: IVTEditLink);
    procedure VTEmuOptEditing(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; var Allowed: Boolean);
    procedure VTEmuOptNewText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; NewText: WideString);
    procedure VTEmuOptExit(Sender: TObject);
    procedure BtnOKClick(Sender: TObject);
    procedure VTEmuOptPaintText(Sender: TBaseVirtualTree;
      const TargetCanvas: TCanvas; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType);

  private
    SysList : TObjectList;
    EmuOptList : TObjectList;
    SelectedNode : PVirtualNode;
    _CacheLastDir : String;
    _FrmVar : TFrmParamVars;

    procedure DeleteEntry(DelEmu: TQPEmu);overload;
    procedure DeleteEntry(DelNode : PVirtualNode);overload;
    Procedure DeleteSys(DelNode : PVirtualNode);
    procedure MoveToNewSystem(Node : PVirtualNode; NewSys : String);
    procedure SetupMedia(CurrEmu : TQPEmu);
    procedure SetupOptions(CurrEmu : TQPEmu);

  public
    EmuCopy : TQPEmuList;
  end;

implementation

uses fMain, fTxtEditor, uJUtilities, JCLStrings, uJVirtualTree, uJFile, uQPConst,
  uJCompression, IniFiles, ujMiscResourceStrs, ujProcesses;

const
  EmuOptHeadStr: TQPEmuOptHeadStr =
   (QP_EMUOPT_GENERAL, QP_EMUOPT_LAUNCH, QP_EMUOPT_CMDLINE, QP_EMUOPT_CMDLINEOPT,
   QP_EMUOPT_COMPRESSION, QP_EMUOPT_TOOLS, QP_EMUOPT_WIN);

  EmuOptHeadIcon  : Array[0..6] of Integer = (9, 2, 0, 9, 28, 15, 9);
  Sections : Array [0..6] of TQPEmuOptHead = (qpesStandard,
                                              qpesLaunch,
                                              qpesCmdLine,
                                              qpesCmdLineOpt,
                                              qpesCompress,
                                              qpesTools,
                                              qpesWin);

{$R *.DFM}

{-----------------------------------------------------------------------------}

constructor TQPEmuOption.Create(Section : TQPEmuOptHead; Caption : String; EditType : TQPEditType;
                      Value : Pointer; DataType : TQPDataType);
begin
  inherited create;
  FCaption := Caption;
  FEditType := EditType;
  FValue := Value;
  FSection := Section;
  FDataType := DataType;
end;

{-----------------------------------------------------------------------------}
{                              Private Routines                               }
{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.DeleteEntry(DelEmu : TQPEmu);
var
  Parent, SearchNode : PVirtualNode;
Begin
  //this procedure will delete the emulator sent as the parameter
  //and also check the tree to see if it exists in it so it can be deleted.

  //first thing we need to do is to find out whether this emulator
  //has an associated node - the only way i can think of to do this is to
  //iterate through each of the nodes and compare objects.

  SearchNode := VTEmus.GetFirst;
  While SearchNode <> nil do
    If (VTEmus.GetNodeLevel(SearchNode) = 1) and
       (TQPEmu(GetObject(VTEmus, SearchNode)) = DelEmu) then
    begin
      VTEmus.BeginUpdate;
      Try
        //we have a match, delete this node entry
        //get the nodes parent, we will need to update its caption later.
        Parent := VTEmus.NodeParent[SearchNode];

        //if this is the currently selected node we need to clear out the options screen
        If SearchNode = VTEmus.FocusedNode then
        begin
          VTEmuOpt.Clear;
          EmuOptList.Clear;
          //set the selected pointer to nil
          SelectedNode := nil;
        end;

        //delete the node in the tree.
        VTEmus.DeleteNode(SearchNode);
      Finally
        VTEmus.EndUpdate;
      end;

      //update the caption of the parent (the system folder)
      TQPSystem(GetObject(VTEmus, Parent)).TotalEmus := TQPSystem(GetObject(VTEmus, Parent)).TotalEmus-1;

      //break out of the loop
      SearchNode := nil;
    end
    else
      SearchNode := VTEmus.GetNext(SearchNode);

    //delete the actual entry in the list object.
    EmuCopy.Remove(DelEmu);

End;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.DeleteEntry(DelNode: PVirtualNode);
Var
  Parent, NewSelected : PVirtualNode;
begin
  //this procedure takes a node as a parameter and deletes that node
  //and its associated emulator value.
  VTEmus.BeginUpdate;
  try

    //get the nodes parent, we will need to update its caption later.
    Parent := VTEmus.NodeParent[DelNode];

    //get the node that will be selected after this one is deleted.
    If VTEmus.GetNextSibling(DelNode) <> nil then
      NewSelected := VTEmus.GetNextSibling(DelNode)
    else
    if VTEmus.GetPreviousSibling(DelNode) <> nil then
      NewSelected := VTEmus.GetPreviousSibling(DelNode)
    else
      NewSelected := VTEmus.NodeParent[DelNode];

    //delete the actual entry in the list object.
    EmuCopy.Remove(TQPEmu(GetObject(VTEmus, DelNode)));

    //delete the node in the tree.
    VTEmus.DeleteNode(DelNode);
    //VTEmus.DeleteSelectedNodes;

    //clear the options tree
    VTEmuOpt.Clear;
    EmuOptList.Clear;
    //set the selected pointer to nil
    SelectedNode := nil;

    //update the caption of the parent (the system folder)
    TQPSystem(GetObject(VTEmus, Parent)).TotalEmus := TQPSystem(GetObject(VTEmus, Parent)).TotalEmus-1;

  finally
    VTEmus.EndUpdate;
  end;

  //set the new selection
  VTEmus.Selected[NewSelected] := True;
  VTEmus.FocusedNode := NewSelected;

end;

{-----------------------------------------------------------------------------}

Procedure TFrmEmuDlg.DeleteSys(DelNode : PVirtualNode);
Var
  i : Integer;
begin
  //this procedure takes a node as a parameter and deletes that node
  //and its associated emulator value.
  if MessageDlg(QP_EMU_DELETE_BY_SYS, mtWarning, [mbYes,mbNo], 0) = mrYes then
  begin

    VTEmus.BeginUpdate;
    try
      //delete the actual entry in the list object.
      For i := EmuCopy.Count-1 downto 0 do
        if strCompare(EmuCopy[i].System, TQPSystem(GetObject(VTEmus, DelNode)).Name) =0 then
          EmuCopy.Delete(i);

      //delete the node in the tree.
      VTEmus.DeleteChildren(DelNode, True);

      //update the caption of the parent (the system folder)
      TQPSystem(GetObject(VTEmus, DelNode)).TotalEmus := 0;

    finally
      VTEmus.EndUpdate;
    end;
  end; //end of messagedlg if statement

end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.MoveToNewSystem(Node : PVirtualNode; NewSys : String);
var
  sNode : PVirtualNode;
  KeepLooking : Boolean;
  NodeSys, OldSys : TQPSystem;
begin
  sNode := vtEmus.GetFirst;
  KeepLooking := True;
  while (KeepLooking) and (sNode <> nil) do
  begin
    NodeSys := TQPSystem(GetObject(VTEmus, sNode));
    if (NodeSys.Name = NewSys) then
    begin
      //we have found where we want to move to!

      //change the totals for the relevant nodes
      NodeSys.TotalEmus := NodeSys.TotalEmus + 1;
      OldSys := TQPSystem(GetObject(VTEmus, VTEmus.NodeParent[Node]));
      OldSys.TotalEmus := OldSys.TotalEmus - 1;
      
      VTEmus.MoveTo(Node, sNode, amAddChildLast, False);
      KeepLooking := False;
      VTEmus.Expanded[sNode] := True;
    end
    else
      sNode := VTEmus.GetNextSibling(sNode);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.SetupMedia(CurrEmu : TQPEmu);
begin
  if CurrEmu <> nil then
  begin
    ChkAddEmuTab.Checked := CurrEmu.ShowExeTab;
    TxtEmuImage.FileName := CurrEmu.ExeImage;
    ChkShowAddinfo.Checked := CurrEmu.ShowAddInfo;
    memoEmuInfo.Clear;
    memoEmuInfo.Lines.AddStrings(CurrEmu.AdditionalInfo);
  end
  else
  begin
    //nil came in, blank out boxes
    ChkAddEmuTab.Checked := False;
    TxtEmuImage.FileName := '';
    ChkShowAddinfo.Checked := False;
    memoEmuInfo.Clear;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.SetupOptions(CurrEmu : TQPEmu);
var
  i : Integer;
begin
  EmuOptList.Add(
    TQPEmuOption.Create(qpesStandard, QP_EMU_NAME, qpeEdit, @CurrEmu.Name, qpStringNotNull)
  );
  EmuOptList.Add(
    TQPEmuOption.Create(qpesStandard, QP_EMU_VERSION, qpeEdit, @CurrEmu.Version, qpString)
  );
  EmuOptList.Add(
    TQPEmuOption.Create(qpesStandard, QP_EMU_PATH, qpeFileExeEdit, @CurrEmu.Path, qpStringNotNull)
  );
  EmuOptList.Add(
    TQPEmuOption.Create(qpesStandard, QP_EMU_CFG, qpeFileEdit, @CurrEmu.CfgFile, qpString)
  );
  EmuOptList.Add(
    TQPEmuOption.Create(qpesStandard, QP_EMU_SYS, qpeComboSys, @CurrEmu.System, qpStringNotNull)
  );
  EmuOptList.Add(
    TQPEmuOption.Create(qpesStandard, QP_EMU_WWW, qpeEdit, @CurrEmu.HomePage, qpString)
  );
  EmuOptList.Add(
    TQPEmuOption.Create(qpesLaunch, QP_EMU_CMDLINE, qpeComboBoolean, @CurrEmu.CmdLine, qpBoolean)
  );
  EmuOptList.Add(
    TQPEmuOption.Create(qpesLaunch, QP_EMU_SHELL, qpeComboBoolean, @CurrEmu.ShellEx, qpBoolean)
  );
  EmuOptList.Add(
    TQPEmuOption.Create(qpesLaunch, QP_EMU_LAUNCH_PRIORITY, qpePriority, @CurrEmu.Priority, qpPriority)
  );
  EmuOptList.Add(
    TQPEmuOption.Create(qpesCmdLine, QP_EMU_PARAM, qpeEdit, @CurrEmu.Parameters, qpString)
  );
  EmuOptList.Add(
    TQPEmuOption.Create(qpesCmdLineOpt, QP_EMU_LAUNCHER, qpeComboBoolean, @CurrEmu.UseLaunchApp, qpBoolean)
  );
  EmuOptList.Add(
    TQPEmuOption.Create(qpesCmdLineOpt, QP_EMU_VERIFY, qpeComboBoolean, @CurrEmu.Verify, qpBoolean)
  );
  EmuOptList.Add(
    TQPEmuOption.Create(qpesCmdLineOpt, QP_EMU_EXE_SHORT, qpeComboBoolean, @CurrEmu.ShortExe, qpBoolean)
  );

  EmuOptList.Add(
    TQPEmuOption.Create(qpesCompress, QP_EMU_EXTRACT_DESTINATION, qpeExtractDest, @CurrEmu.ExtractDest, qpExtractDest)
  );

  //all compression format support.
  for i := 0 to CurrEmu.CompressStrings.Count-1 do
    EmuOptList.Add(
      TQPEmuOption.Create(qpesCompress,
                          CurrEmu.CompressStrings.Names[i],
                          qpeComboBoolean,
                          @CurrEmu.CompressStrings,
                          qpEmuCompress)
    );

  //Options for the Running tools before/after launch
  EmuOptList.Add(
    TQPEmuOption.Create(qpesTools, QP_EMU_PRELAUNCH, qpeEdit, @CurrEmu.PreLaunchCmd, qpString)
  );
  EmuOptList.Add(
    TQPEmuOption.Create(qpesTools, QP_EMU_PRELAUNCH_WAIT, qpeComboBoolean, @CurrEmu.PreLaunchWait, qpBoolean)
  );
  EmuOptList.Add(
    TQPEmuOption.Create(qpesTools, QP_EMU_AFTERLAUNCH, qpeEdit, @CurrEmu.AfterLaunchCmd, qpString)
  );
  EmuOptList.Add(
    TQPEmuOption.Create(qpesTools, QP_EMU_AFTERLAUNCH_WAIT, qpeComboBoolean, @CurrEmu.AfterLaunchWait, qpBoolean)
  );

  //windows options.
  EmuOptList.Add(
    TQPEmuOption.Create(qpesWin, QP_EMU_SCREENSAVER, qpeComboBoolean, @CurrEmu.DisableScreenSaver, qpBoolean)
  );
  EmuOptList.Add(
    TQPEmuOption.Create(qpesWin, QP_EMU_WINKEY, qpeComboBoolean, @CurrEmu.DisableWinKey, qpBoolean)
  );
  EmuOptList.Add(
    TQPEmuOption.Create(qpesWin, QP_EMU_PWRSCHEME, qpePowerSchemes, @CurrEmu.ChangeToPwrScheme, qpString)
  );

  VTEmuOpt.BeginUpdate;
  try
    VTEmuOpt.RootNodeCount := Length(Sections);
    {aNode := VTEmuOpt.GetFirst;
    while aNode <> nil do
    begin
      Tmp := VTEmuOpt.GetNodeData(aNode);
      TQPEmuOptHead(Tmp^) := Sections[aNode.Index];
      aNode := VTEmuOpt.GetNextSibling(aNode);
    end;         }

    //validate the entire tree so we dont get Access Violations when we scroll down.
    VTEmuOpt.ValidateNode(nil, True);

  finally
    VTEmuOpt.EndUpdate;
  end;
end;


{----------------------------------------------------------------------------}

procedure TFrmEmuDlg.FormCreate(Sender: TObject);
Var
  FileList : TStringList;
  I : Integer;
  NewSys : TQPSystem;
  NewIndex : integer;
  Ini : TMemIniFile;
begin

  //create the parameter variables form
  _FrmVar := TFrmParamVars.Create(self);
  _FrmVar.Hide();

  //load in the cache value for the mo options
  Ini := TMemIniFile.Create(MainFrm.Settings.Paths.SettingsFile);
  Try
    _CacheLastDir := Ini.ReadString('MOCache', 'EmuLastDir', '');
  Finally
    FreeAndNil(Ini);
  end;

  pgEmuOpt.ActivePageIndex := 0;

  //create our EMUcopy objectlist to hold a copy of the emulators list
  Emucopy := TQPEmuList.Create(MainFrm.Settings.Paths.CfgDir+'emulators.ini', True);

  VTEmus.StateImages := EmuCopy.ExeIcons;

  //create the syslist stringlist to hold our list of systems
  SysList := TObjectList.create(true);
  EmuOptList := TObjecTList.Create(True);

  FileList := TStringList.Create;
  try
    FileList.LoadFromFile(MainFrm.Settings.Paths.SystemsFile);
    FileList.Sort;
    i := 0;
   
    While i < FileList.Count do
    Begin
      if FileList[i] <> '' then
      begin
        NewIndex := SysList.Add(TQPSystem.Create);
        NewSys := TQPSystem(SysList.items[NewIndex]);

        NewSys.Name := FileList.Strings[i];
        NewSys.TotalEmus := 0;
      end;
      inc(i);
    End;

  Finally
    FreeAndNil(FileList);
  end;

  VTEmus.NodeDataSize := SizeOf(Pointer);
  VTEmuOpt.NodeDataSize := SizeOf(Pointer);
  VTEmus.RootNodeCount := SysList.Count;

  if FileExists(MainFrm.Settings.Paths.AppDir + 'edit.png') then
    VTEmuOpt.Background.LoadFromFile(MainFrm.Settings.Paths.AppDir + 'edit.png');
end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.FormClose(Sender: TObject; var Action: TCloseAction);
begin

  _FrmVar.Close();

  if VTEmuOpt.IsEditing then
    VTEmuOpt.EndEditNode;
  //clear everything to be safe
  VTEmus.Clear;
  VTEmuOpt.Clear;
end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.FormDestroy(Sender: TObject);
begin

  FreeAndNil(_FrmVar);

  EmuOptList.Clear;
  FreeAndNil(EmuOptList);

  EmuCopy.Clear;
  FreeAndNil(EmuCopy);

  SysList.Clear;
  FreeAndNil(SysList);
end;

{-----------------------------------------------------------------------------}
{                        Start of Emulator VT code                            }
{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.VTEmusInitNode(Sender: TBaseVirtualTree; ParentNode,
  Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
var
  CurSys : TQPSystem;
begin

  If Node <> nil then
  if VTEmus.GetNodeLevel(node) = 0 then
  begin
    SetObject(Sender, Node, SysList.Items[Node.Index]);
    CurSys := TQPSystem(GetObject(Sender, Node));
    with MainFrm do
    Begin
    // use the GetEmulatorsFromSystem function to determine if
    // this system will have any child nodes.
    CurSys.TotalEmus := EmuCopy.TotalForSystem(CurSys.Name);
    If CurSys.TotalEmus <> 0 then
      Include(InitialStates, ivsHasChildren);
    End;  //end of WITH block

  end;

end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.VTEmusGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
var
  CurSys : TQPSystem;
begin

  If Node <> nil then
  If VTEmus.GetNodeLevel(node) = 0 then
  begin
    //for the system i want to output the system name AND
    //how many emulators are in this system (if its not 0)
    CurSys := TQPSystem(GetObject(Sender, Node));
    If CurSys.TotalEmus = 0 then
      CellText := CurSys.Name
    else
      CellText := CurSys.Name + ' (' + IntToStr(CurSys.TotalEmus) + ')';
  end
  Else
    CellText := TQPEmu(GetObject(Sender, Node)).Name;
end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.VTEmusInitChildren(Sender: TBaseVirtualTree;
  Node: PVirtualNode; var ChildCount: Cardinal);
var
  ChildNode: PVirtualNode;
  I : Integer;
  CurSys : TQPSystem;
  CurEmu : TQPEmu;
begin

  if Node <> nil then
  begin
  
  VTEmus.BeginUpdate;
  try

    CurSys := TQPSystem(GetObject(Sender, Node));

    //loop through all systems and add each one as a child.
    For i := 0 to EmuCopy.Count-1 do
    Begin
      CurEmu := EmuCopy.items[i];
      If StrCompare(CurEmu.System, CurSys.Name)=0 then
      begin

        ChildNode := Sender.AddChild(Node);
        SetObject(Sender, ChildNode, CurEmu);
      
        //since the Icons are big, make the node itself bigger.
        VTEmus.NodeHeight[ChildNode] := 24;
        Sender.ValidateNode(Node, False);
      end;
    end;

    //the childcount is the amount of nodes we just added
    ChildCount := Sender.ChildCount[Node];
    CurSys.TotalEmus := Sender.ChildCount[Node];

    // finally sort node
    if ChildCount > 0 then
      Sender.Sort(Node, 0, TVirtualStringTree(Sender).Header.SortDirection, False);

  finally
    //end the update cycle and refresh the tree.
    VTEmus.EndUpdate;
  end;

  end;//end of Node<>nil check

end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.VTEmusFreeNode(Sender: TBaseVirtualTree;
  Node: PVirtualNode);
begin
  if Node <> nil then
    SetObject(Sender, Node, nil);
end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.VTEmusGetImageIndex(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
  var Ghosted: Boolean; var ImageIndex: Integer);
Var
  CurrEmu : TQPEmu;
begin
  //we want the root nodes (the systems) to have folders
  //and the emulators to have APP icons.
  
  If Node <> nil then
  if Sender.GetNodeLevel(Node) = 0 then
    Case Kind of
      ikNormal:ImageIndex := 0;
      ikSelected: ImageIndex := 1;
    end
  else
  begin
    CurrEmu := TQPEmu(GetObject(Sender, Node));
    if CurrEmu.IconIndex = -1 then
      Case Kind of
      ikNormal:ImageIndex := 2;
      ikSelected: ImageIndex := 2;
    end
    else
      case Kind of
       ikState:ImageIndex := CurrEmu.IconIndex;
      end;

  end;

end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.VTEmusChange(Sender: TBaseVirtualTree; Node: PVirtualNode);
begin
  //center view ( fix )
  if ( Node <> nil) then
    VTEmus.ScrollIntoView(Node, false);
end;

procedure TFrmEmuDlg.VTEmusCompareNodes(Sender: TBaseVirtualTree; Node1,
  Node2: PVirtualNode; Column: TColumnIndex; var Result: Integer);
var
  Emu1, Emu2 : TQPEmu;
  Sys1, Sys2 : TQPSystem;
begin
  If (Node1 <> nil) and (Node2 <> nil) then
  If (Sender.GetNodeLevel(Node1) = 0) and
     (Sender.GetNodeLevel(Node2) = 0) then
  begin
    Sys1 := TQPSystem(GetObject(Sender, Node1));
    Sys2 := TQPSystem(GetObject(Sender, Node2));

    case Column of
      0: Result := CompareText(Sys1.Name, Sys2.Name);
    end;
  end
  else
  If (Sender.GetNodeLevel(Node1) = 1) and
     (Sender.GetNodeLevel(Node2) = 1) then
  begin
    Emu1 := TQPEmu(GetObject(Sender, Node1));
    Emu2 := TQPEmu(GetObject(Sender, Node2));
    case Column of
      0: Result := CompareText(Emu1.Name, Emu2.Name);
    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.BtnAddClick(Sender: TObject);
var
  System : String;
  SelObject : TObject;
  CurEmu : TQPEmu;
  Parent, NewNode : PVirtualNode;
begin

  //this code will add a new emulator object to the EmuCopy.
  // if a SYSTEM is selected the new emulator will be of that system
  // if an EMU is selected, the new emulator will have the same system
  // if NOTHING is selected then the emulator will have no system.

  //set the system variable to be blank.
  System := '';
  
  If VTEmus.FocusedNode <> nil then
  Begin
  
    SelObject := GetObject(VTEmus, VTEmus.FocusedNode);
    If SelObject <> nil then
    Begin
    
      If VTEmus.GetNodeLevel(VTEmus.FocusedNode) = 0 then
      begin
        // the currently focused node is a system
        System := TQPSystem(SelObject).Name;
        Parent := VTEmus.FocusedNode;
      end
      else
      begin
        // the currently focused node is an emulator
        System := TQPEmu(SelObject).System;
        Parent := VTEmus.NodeParent[VTEmus.FocusedNode];
      end;

      EmuCopy.Add(TQPEmu.Create);
      CurEmu := EmuCopy.Last;
      CurEmu.System := System;
      CurEmu.DiscoverNewCompression();

      VTEmus.BeginUpdate;
      try
        NewNode := VTEmus.AddChild(Parent);
        SetObject(VTEmus, NewNode, CurEmu);
        //now update the systems count
        TQPSystem(GetObject(VTEmus, Parent)).TotalEmus := TQPSystem(GetObject(VTEmus, Parent)).TotalEmus + 1;

      finally
        VTEmus.EndUpdate;
      end;
      VTEmus.FocusedNode := NewNode;
      VTEmus.Selected[NewNode] := True;
      //now focus the NAME option to force an edit
      VTEmuOpt.SetFocus;
      VTEmuOpt.FocusedNode := (VTEmuOpt.GetFirstChild(VTEmuOpt.GetFirst));

    end;

  End
  else
    MessageDlg(QP_EMUFRM_NO_SYS, mtError, [mbOK], 0);

end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.BtnDeleteClick(Sender: TObject);
begin

  //this code deletes the selected node as long as its an emulator
  If (VTEmus.FocusedNode <> nil) then
    if (VTEmus.GetNodeLevel(VTEmus.FocusedNode) = 1) then
      DeleteEntry(VTEmus.Focusednode)
    else
      DeleteSys(VTEmus.FocusedNode);

end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.VTEmusPaintText(Sender: TBaseVirtualTree;
  const TargetCanvas: TCanvas; Node: PVirtualNode; Column: TColumnIndex;
  TextType: TVSTTextType);
var
  MySys : TQPSystem;
begin
  If Node <> nil then
  begin

    If VTEmus.GetNodeLevel(Node) = 0 then
    Begin
      MySys := TQPSystem(GetObject(Sender, Node));
      Assert(MySys <> nil);
      If (MySys.TotalEmus > 0) then
        TargetCanvas.Font.Style := TargetCanvas.Font.Style+[fsBold];
    End;

  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.VTEmusFocusChanging(Sender: TBaseVirtualTree; OldNode,
  NewNode: PVirtualNode; OldColumn, NewColumn: TColumnIndex;
  var Allowed: Boolean);
Var
  CurrEmu : TQPEmu;
  
begin

  If (NewNode<>OldNode) and (NewNode <> nil) then
    Allowed := True
  else
    Allowed := False;

  If (Allowed) then
  begin

    //check if the options tree is currently editting.
    if VTEmuOpt.IsEditing then
      VTEmuOpt.EndEditNode;

    EmuOptList.Clear;
    VTEmuOpt.Clear;

    pgEmuOpt.ActivePageIndex := 0;

    //call the FillText Function which fills the text boxes with data
    If VTEmus.GetNodeLevel(NewNode) = 0 then
    begin
      SelectedNode := nil;
      VTEmuOpt.RootNodeCount := 0;
      setupMedia(nil);
      VTEmuOpt.TreeOptions.PaintOptions := VTEmuOpt.TreeOptions.PaintOptions + [toShowBackground];
    end
    else
    begin
      CurrEmu := TQPEmu(GetObject(Sender, NewNode));
      SelectedNode := NewNode;
      SetupMedia(CurrEmu);
      SetupOptions(CurrEmu);
      VTEmuOpt.TreeOptions.PaintOptions := VTEmuOpt.TreeOptions.PaintOptions - [toShowBackground];
    end;

  end;//end of IF allowed

end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.VTEmuOptInitNode(Sender: TBaseVirtualTree; ParentNode,
  Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
var
  Tmp : Pointer;
begin
  if Sender.GetNodeLevel(Node) = 0 then
  begin

    Tmp := Sender.GetNodeData(Node);
    TQPEmuOptHead(Tmp^) := Sections[Node.Index];

    Include(InitialStates, ivsHasChildren);
    Include(InitialStates, ivsExpanded);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.VTEmuOptInitChildren(Sender: TBaseVirtualTree;
  Node: PVirtualNode; var ChildCount: Cardinal);
var
  i : Integer;
  Phead : Pointer;
  Header : TQPEmuOptHead;
  ChildNode: PVirtualNode;
begin

  PHead := Sender.GetNodeData(Node);
  Header := TQPEmuOptHead(PHead^);

  for i := 0 to EmuOptList.Count-1 do
  begin
    if TQPEmuOption(EmuOptList[i]).Section = Header then
    begin
      ChildNode := Sender.AddChild(Node);
      SetObject(Sender, ChildNode, EmuOptList[i]);
      Sender.NodeHeight[ChildNode] := 20;
    end;
  end;
  ChildCount := Sender.ChildCount[Node];
end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.VTEmuOptGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
var
  Phead : Pointer;
  Header : TQPEmuOptHead;
  Opt : TQPEmuOption;
  PStr : PString;
  PBool : PBoolean;
  PStrings : PStringList;
  PExtractDest : PQPExtractDest;
  PPriority : PJPriority;
begin
  If Node <> nil then // make sure the node isnt nil.
  Case Sender.GetNodeLevel(Node) of
    0: //this is a section header
        begin
          If Column = 0 then
          begin
            Phead := Sender.GetNodeData(Node);
            Header := TQPEmuOptHead(PHead^);
            CellText := EmuOptHeadStr[Header];
          end
          else
            CellText := '';
        end;
    1: //this is a data entry
        begin
          Opt := TQPEmuOption(GetObject(Sender, Node));
          If Column = 0 then
          begin
            //this is the caption
            CellText := Opt.Caption;
          end
          else
          begin
            //this is the actual data value.
            Case Opt.DataType of
              qpString, qpStringNotNull :
                          begin
                            Pstr := PString(Opt.Value);
                            CellText := Pstr^;
                          end;
              qpBoolean:  begin
                            PBool := PBoolean(Opt.Value);
                            CellText := BoolToStr(PBool^, True);
                          end;
              qpEmuCompress : Begin
                                PStrings := PStringList(Opt.Value);
                                CellText := BoolToStr(StrToBool(PStrings^.Values[Opt.Caption]), True);
                              end;
              qpExtractDest : Begin
                                PExtractDest := PQPExtractDest(Opt.Value);
                                CellText := uQPMiscTypes.ExtractDestStr[PExtractDest^];
                              end;
              qpPriority    : Begin
                                PPriority := PJPriority(Opt.Value);
                                CellText := ujProcesses.PriorityStrArr[PPriority^];
                              end;
            end;
          end;
        end;
  end; //end of Node Level Case Statement
end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.VTEmuOptGetImageIndex(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
  var Ghosted: Boolean; var ImageIndex: Integer);
var
  Phead : Pointer;
  Header : TQPEmuOptHead;
begin
  if (Node <> nil) and (Sender.GetNodeLevel(Node) = 0) and (Column = 0) then
  begin
    Phead := Sender.GetNodeData(Node);
    Header := TQPEmuOptHead(PHead^);

    Case Kind of
      ikNormal : ImageIndex := EmuOptHeadIcon[Integer(Header)];
      ikSelected : ImageIndex := EmuOptHeadIcon[Integer(Header)];
    end
   { Case Kind of
      ikNormal:ImageIndex := 0;
      ikSelected: ImageIndex := 1;
    end }
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.VTEmuOptChange(Sender: TBaseVirtualTree;
  Node: PVirtualNode);
var
  Opt : TQPEmuOption;
begin
with Sender do
  begin
    // Start immediate editing as soon as another node gets focused.
    if Assigned(Node) and not (tsIncrementalSearching in TreeStates) then
    begin
      // Note: the test whether a node can really be edited is done in the OnEditing event.
      EditNode(Node, 1);

      //check if we need to display the parameter variables tool window.
      if Sender.GetNodeLevel(Node) = 1 then
      begin
        Opt := TQPEmuOption(GetObject(Sender, Node));
        if JCLStrings.StrCompare(Opt.Caption, QP_EMU_PARAM) = 0 then
        begin
          ShowWindow(_FrmVar.Handle, SW_SHOWNA);
          _FrmVar.Visible := True;
          //_FrmVar.Show();
        end
        else
          _FrmVar.Hide();
      end;

    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.VTEmuOptCreateEditor(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; out EditLink: IVTEditLink);
var
  Opt : TQPEmuOption;
begin
  if Node <> nil then
  begin
    Opt := TQPEmuOption(GetObject(Sender, Node));
    EditLink := TQPVTEdit.Create(Opt.EditType);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.VTEmuOptEditing(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; var Allowed: Boolean);
begin
  Allowed := (Sender.GetNodeLevel(Node) > 0);
end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.VTEmuOptNewText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; NewText: WideString);
var
  Opt : TQPEmuOption;
  PStr : PString;
  Pbool : PBoolean;
  PStrings : PStringList;
  PExtractDest : PQPExtractDest;
  PPriority : PJPriority;
begin
  Opt := TQPEmuOption(GetObject(Sender, Node));

  //we have a few special cases to make sure of first!

  Case Opt.DataType of
    qpString :  begin
                  Pstr := PString(Opt.Value);
                  Pstr^ := NewText;
                end;
    qpStringNotNull:
                begin
                  If NewText <> '' then
                  begin

                    //this checks that any files entered into the box MUST exist.
                    if (Opt.EditType = qpeFileExeEdit) then
                      if not FileExists(NewText) then
                      begin
                        MessageDlg(J_FILE_NOT_EXIST, mtError, [mbOK], 0);
                        exit;
                      end;

                    //check that if the PATH has changed
                    if (Opt.Caption = 'Path') then
                    begin
                      Pstr := PString(Opt.Value);
                      if pStr^ <> NewText then
                      begin
                        Pstr^ := NewText;
                        VTEmus.InvalidateNode(VTEmus.FocusedNode);
                      end;
                    end
                    else
                    //check if the user has changed the System property
                    //if they have we need to move the node into the correct system!
                    if (Opt.Caption = 'System') then
                    begin
                      Pstr := PString(Opt.Value);
                      if pStr^ <> NewText then
                      begin
                        // The system has changed, umm do something!
                        Pstr^ := NewText;
                        MoveToNewSystem(VTEmus.FocusedNode, NewText);
                      end;
                    end
                    else
                    //if its the name we are editting, the VTEmu tree wont update the text
                    // straight away - force it to!
                    if (Opt.Caption = 'Name') then
                    begin
                      Pstr := PString(Opt.Value);
                      if pStr^ <> NewText then
                      begin
                        // The system has changed, umm do something!
                        Pstr^ := NewText;
                        VTEmus.InvalidateNode(VTEmus.FocusedNode);
                      end;
                    end
                    else
                    begin
                      //do the normal default thing
                      Pstr := PString(Opt.Value);
                      Pstr^ := NewText;
                    end;
                  end
                  else
                  begin
                    //the string is required, fire up a message!

                    MessageDlg(Opt.Caption + QP_EMUFRM_NOT_EMPTY, mtError, [mbOK], 0);
                  end;
                end;
                
    qpBoolean:  begin
                  PBool := PBoolean(Opt.Value);
                  PBool^ := StrToBool(NewText);
                end;

    qpEmuCompress:  begin
                      PStrings := PStringList(Opt.Value);
                      PStrings^.Values[Opt.Caption] := NewText;
                    end;

    qpExtractDest:  begin
                      PExtractDest := PQPExtractDest(Opt.Value);
                      PExtractDest^ := TQPExtractDest(StrToInt(NewText));
                    end;
    qpPriority:     begin
                      PPriority := PJPriority(Opt.Value);
                      PPriority^ := TJPriority(StrToInt(NewText));
                    end;

  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.VTEmuOptPaintText(Sender: TBaseVirtualTree;
  const TargetCanvas: TCanvas; Node: PVirtualNode; Column: TColumnIndex;
  TextType: TVSTTextType);
begin
  If (Node <> nil) and (Sender.GetNodeLevel(Node) = 0) then
    TargetCanvas.Font.Style := TargetCanvas.Font.Style+[fsBold];
end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.VTEmuOptExit(Sender: TObject);
begin
  if VTEmuOpt.IsEditing then
    VTEmuOpt.EndEditNode;

  _FrmVar.Hide();
end;

{-----------------------------------------------------------------------------}

procedure TFrmEmuDlg.BtnOKClick(Sender: TObject);
var
  i : Integer;
  EmptyFound : Boolean;
  Info : TStringList;
  Ini : TMemIniFile;
begin

  EmptyFound := False;
  //check if there are any emulators with blank paths or names
  Info := TStringList.Create;
  try
    for i := 0 to EmuCopy.Count-1 do
      if (EmuCopy[i].Name = '') or (EmuCopy[i].Path = '') then
      begin
        EmptyFound := True;
        //try to give some info about which is blank.
        if EmuCopy[i].Name <> '' then
          Info.Add(EmuCopy[i].System + ' - ' + EmuCopy[i].Name)
        else if EmuCopy[i].Path <> '' then
          Info.Add(EmuCopy[i].System + ' - ' + EmuCopy[i].Path)
        else
          Info.Add(EmuCopy[i].System);
      end;

    if (EmptyFound) and
      (MessageDlg(QP_EMUFRM_NO_NAME_WARNING + LBreak + Info.GetText, mtWarning, [mbYes, mbNo], 0) = mrNo) then
    begin
      ModalResult := mrNone;
    end
    else
    begin
      //clear the 2 trees
      VTEmus.Clear;
      VTEmuOpt.Clear;

      //save the cachelastdir value
      Ini := TMemIniFile.Create(MainFrm.Settings.Paths.SettingsFile);
      try
        Ini.WriteString('MOCache', 'EmuLastDir', _CacheLastDir);
        Ini.UpdateFile;
      finally
        FreeAndNil(Ini);
      end;

    end;
  finally
    FreeAndNil(Info);
  end;
end;

procedure TFrmEmuDlg.TabMediaConfigExit(Sender: TObject);
var
  Emu : TQPEmu;
begin
  //save media settings.
  if SelectedNode <> nil then
  begin
    Emu := TQPEmu(GetObject(VTEmus, SelectedNode));
    Emu.ShowExeTab := ChkAddEmuTab.Checked;
    Emu.ExeImage := TxtEmuImage.FileName;
    Emu.ShowAddInfo := ChkShowAddInfo.Checked;
    Emu.AdditionalInfo.Clear;
    Emu.AdditionalInfo.AddStrings(memoEmuInfo.Lines);
  end;
end;

procedure TFrmEmuDlg.TxtEmuImageAfterDialog(Sender: TObject; var Name: string;
  var Action: Boolean);
begin
  if (Action) and (DirectoryExists(ExtractFilePath(Name))) then
    _CacheLastDir := ExtractFilePath(Name);
end;

procedure TFrmEmuDlg.TxtEmuImageBeforeDialog(Sender: TObject; var Name: string;
  var Action: Boolean);
begin
  if _CacheLastDir <> '' then
    TxtEmuImage.InitialDir := _CacheLastDir;
end;

end.
