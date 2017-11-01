{
  Emu-Finder Form
  This form contains the code behind the emu-finder.  has 2 VTs.
  Essentially the user provides a directory and choice of data files
  Load these datafiles into an array
  perform search of users directory.
  match any filenames with the names in our array
  add these results to a temporary record
  display the results in a VT, and allow user to check appropriate ones
  save/or dont save!
}

unit fEmuFind;

interface

uses
  Windows, SysUtils, Classes, Controls, Forms, Dialogs,
  StdCtrls, Buttons, ComCtrls,Contnrs, Graphics,
  VirtualTrees, FindFile, JvBaseDlg, JvBrowseFolder,
  JvCombobox, JvDriveCtrls, JvComponent, JvExStdCtrls, uEmu, Mask,
  JvExMask, JvToolEdit, ExtCtrls, JvComponentBase, fJWinFontForm;

type

  TEmuFinder = class(TJWinFontForm)
    FindEmu: ThhFindFile;
    PCWizard: TPageControl;
    TabResults: TTabSheet;
    RadOverwrite: TRadioButton;
    RadAppend: TRadioButton;
    BtnOK: TButton;
    BtnNoSave: TButton;
    VTEFind: TVirtualStringTree;
    lblFound: TLabel;
    jvBrowse: TJvBrowseForFolderDialog;
    BtnSelectall: TButton;
    BtnUnselectAll: TButton;
    lblRedAlert: TLabel;
    TabIntroAndFolder: TTabSheet;
    TabDatAndGo: TTabSheet;
    GrpDir: TGroupBox;
    RadSetDir: TRadioButton;
    RadAllDrive: TRadioButton;
    DriveBox: TJvDriveCombo;
    TxtPath: TJvDirectoryEdit;
    GrpStart: TGroupBox;
    btnStart: TButton;
    GrpDats: TGroupBox;
    RadAllDats: TRadioButton;
    RadSelDats: TRadioButton;
    VTdats: TVirtualStringTree;
    lblHeader: TLabel;
    BtnCancel: TButton;
    BtnNext: TButton;
    BtnPrevious: TButton;
    lblEmuFind2: TLabel;
    LblEfind3: TLabel;
    procedure BtnPreviousClick(Sender: TObject);
    procedure BtnNextClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure RadAllDriveClick(Sender: TObject);
    procedure RadSetDirClick(Sender: TObject);
    procedure btnStartClick(Sender: TObject);
    procedure RadAllDatsClick(Sender: TObject);
    procedure RadSelDatsClick(Sender: TObject);
    procedure BtnOKClick(Sender: TObject);
    procedure VTEFindGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure VTEFindCompareNodes(Sender: TBaseVirtualTree; Node1,
      Node2: PVirtualNode; Column: TColumnIndex; var Result: Integer);
    procedure VTEFindHeaderClick(Sender: TVTHeader; HitInfo: TVTHeaderHitInfo);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure VTdatsInitNode(Sender: TBaseVirtualTree; ParentNode,
      Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
    procedure VTdatsGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure FormCreate(Sender: TObject);
    procedure VTEFindEditing(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; var Allowed: Boolean);
    procedure VTEFindNewText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; NewText: WideString);
    procedure VTEFindFreeNode(Sender: TBaseVirtualTree;
      Node: PVirtualNode);
    procedure VTEFindExit(Sender: TObject);
    procedure TxtPathAfterDialog(Sender: TObject; var Name: String;
      var Action: Boolean);
    procedure VTEFindPaintText(Sender: TBaseVirtualTree;
      const TargetCanvas: TCanvas; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType);
    procedure BtnSelectallClick(Sender: TObject);

  private
    { Private declarations }
    DatFileList : TStringList;
    EFindData : TObjectList;
    ResultList : TObjectList;
    Function FindDats(): boolean;
    procedure LoadDats;
    
  end;

implementation

uses fMain, uJUtilities, JCLStrings, IniFiles, uEmuFindObj, uJFile,
     uJVirtualTree, uQPConst, ujMiscResourceStrs;

{$R *.DFM}
{$WARN SYMBOL_PLATFORM OFF}

{-----------------------------------------------------------------------------}
{TEmuFinder}
{-----------------------------------------------------------------------------}

procedure TEmuFinder.FormCreate(Sender: TObject);
var
  Ini : TMemIniFile;
  NewDir : String;
  i : integer;
begin

  Self.SetBounds(Self.Left, Self.Top, 351, 464);

  for i := 0 to PCWizard.PageCount-1 do
    pcWizard.Pages[i].TabVisible := False;

  pcWizard.ActivePageIndex := 0;

  VTEfind.NodeDataSize := SizeOf(Pointer);
  ResultList := TObjectList.Create(True);
  DatFileList := TStringList.Create;
  EFindData := TObjectList.Create(True);

  Ini := TMemInifile.create(MainFrm.Settings.Paths.SettingsFile);
  try
    NewDir := Ini.ReadString('eFind','LastDir','');
    if NewDir <> '' then
    begin
      //txtPath.InitialDir := NewDir;
      TxtPath.Text := Newdir;
    end
    else
    begin
      //txtPath.InitialDir := MainFrm.Settings.QPDirectory;
      txtPath.Text := MainFrm.Settings.Paths.AppDir;
    end;
  Finally
    FreeAndnil(Ini);
  end;

end;

{-----------------------------------------------------------------------------}

procedure TEmuFinder.FormShow(Sender: TObject);
begin
  FindDats;
end;

{-----------------------------------------------------------------------------}

procedure TEmuFinder.FormClose(Sender: TObject; var Action: TCloseAction);
begin

  if DatFileList <> nil then
    FreeAndNil(DatFileList);

  ResultList.Clear;
  FreeAndNil(ResultList);

  FreeAndNil(EFindData);
  
  action := caFree;
end;

{-----------------------------------------------------------------------------}

procedure TEmuFinder.RadAllDriveClick(Sender: TObject);
begin
  TxtPath.enabled := false;
  DriveBox.enabled := true;
end;

{-----------------------------------------------------------------------------}

procedure TEmuFinder.RadSetDirClick(Sender: TObject);
begin
  TxtPath.enabled := true;
  DriveBox.enabled := false;
end;

{-----------------------------------------------------------------------------}

procedure TEmuFinder.btnStartClick(Sender: TObject);
var
  oldstyle : TCursor;
  i, c : integer;
  NewResult : TQPEmu;
  Node : PVirtualNode;
  NewIndex : Integer;
  aLeft, aTop : Integer; //variables for centering form.
begin

  //get rid of the buttons.
  BtnNext.Visible := False;
  BtnCancel.Visible := False;
  BtnPrevious.Visible := False;

  //Firstly change the cursor to the hourglass.
  oldstyle := screen.cursor;
  screen.cursor := crHourGlass;
  Try
    loadDats;

  //now figure out whether to scan the entire drive or a directory.
  if RadAllDrive.checked = true then
    FindEmu.Directory := drivebox.Drive + ':\';
  if RadSetDir.checked = true then
  begin
    if TxtPath.text <> '' then
      FindEmu.directory := TxtPath.text
    else
    begin
      MessageDlg(J_DIRECTORY_NOT_SPECIFIED, mtError, [mbOK], 0);
      screen.cursor := oldstyle;
      exit;
    end;
  end;

  //start the search
  FindEmu.Execute;

  If FindEmu.TotalFile > 0 then
    ResultList.Clear;

  for i := 0 to FindEmu.TotalFile-1 do
  begin  //start of iteration through find results

    for c := 0 to EFindData.Count-1 do
    begin //start of iteration through the emu data files

      if TQPEmuFindObj(EFindData[c]).IsMatch(FindEmu.Files[i]) then
      begin
        NewIndex := ResultList.Add(TQPEmu.Create);
	      NewResult := TQPEmu(ResultList.items[NewIndex]);
        NewResult.ImportEmuFindObj(TQPEmuFindObj(EFindData[c]), FindEmu.Files[i]);
       // Break; removed so duplicate entries with the same filename can be found.
       end; //end of WITH block

    end; // end of iteration through emu data files

  end; //end of iteration through find results

  //we dont need the emuDats array anymore so clear it
  EFindData.Clear;

  //if resultslist.Items.Count > 0 then
  If ResultList.Count > 0 then
  begin
    BtnOK.Enabled := true;
    VTEfind.RootNodeCount := ResultList.Count;

    Node := VTEfind.GetFirst;
    while Node <> nil do
    begin
      SetObject(VTEfind, Node, ResultList.Items[Node.Index]);
      VTEfind.CheckType[Node] := ctCheckBox;
      if MainFrm.EmuList.IndexOfPath(TQPEmu(ResultList.Items[Node.Index]).Path) = -1 then
        //emulator doesnt already exist
        VTEfind.CheckState[Node] := csCheckedNormal
      else
        //path is already in the emulist, dont check it by default.
        VTEfind.CheckState[Node] := csUnCheckedNormal;
      Node := VTEfind.GetNextSibling(Node);
    end;

    lblFound.Caption := IntToStr(ResultList.Count);
  end;

  Finally
    screen.cursor := oldstyle;
  end;

  ALeft := (Screen.Width - Self.Width) div 2;
  ATop  := (Screen.Height - Self.Height) div 2;
  { prevents form being twice repainted! }
  Self.SetBounds (ALeft, ATop, 711, 605);
  //move to results tab.
  PCWizard.ActivePage := TabResults;
  
end;
{-----------------------------------------------------------------------------}

//Procedure to find all available Dat Files for the EmuFinder.
Function TemuFinder.FindDats(): boolean;
var
  Datfind : ThhFindFile;
  i : integer;
  error : boolean;
begin
  //initialise the datFound array to 0
  VTdats.Clear;
  
  error := false;

  DatFind := ThhFindFile.create(self);
  try

    if directoryexists(MainFrm.Settings.Paths.EfindDir) then
    begin
      datfind.Directory := MainFrm.Settings.Paths.EfindDir;
      datFind.Filter := '*.ini';
      datfind.execute;

      if datfind.TotalFile > 0 then
      begin

        for i := 0 to datfind.totalfile-1 do
          DatFileList.Add(datfind.files[i]);

        VTdats.RootNodeCount := DatFileList.Count;
        
      end //end of IF statement

      else
      begin
        MessageDlg(QP_EFIND_NO_FILES, mtError, [mbOK], 0);
        error := true;
      end;

    end

    else
    begin
      MessageDlg(QP_EFIND_NO_DIR, mtError, [mbOK], 0);
      error := true;
    end;

  finally
    FreeAndNil(datfind);
  end;
  result := error;
end;

{-----------------------------------------------------------------------------}

procedure TEmuFinder.LoadDats();
var
  Ini : TMemIniFile;
  Sections : TStringList;
  i : integer;
  aNode : PVirtualNode;
  CurData : TQPEmuFindObj;
begin
  //Find out whether to use all Dat Files or not.

  aNode := VTdats.GetFirst;
  while aNode <> nil do
  begin

    //if the node is checked OR we are using all data files load the file.
    if (radAllDats.checked = true) OR (VTDats.CheckState[aNode] = csCheckedNormal) then
    begin
      Sections := nil;
      Ini := TMemInifile.Create(DatFileList[aNode.Index]);
      try
        Sections := TStringList.Create;
        Ini.ReadSections(Sections);

        for i := 0 to Sections.Count-1 do
        begin
          EFindData.Add(TQPEmuFindObj.Create);
          CurData := TQPEmuFindObj(EFindData.Last);
          CurData.LoadFromIni(Sections.strings[i], Ini);
        end;

      finally
        FreeAndNil(Ini);
        FreeAndNil(Sections);
      end;

    end;

    //get the next node
    aNode := VTdats.GetNext(aNode);
  end;

  //we have now finished with the DATS array and treelist so clear it
  VTdats.Clear;
  FreeAndNil(DatFileList);

end;

{-----------------------------------------------------------------------------}

procedure TEmuFinder.RadAllDatsClick(Sender: TObject);
begin
  Vtdats.enabled := false;
end;

{-----------------------------------------------------------------------------}

procedure TEmuFinder.RadSelDatsClick(Sender: TObject);
begin
  VTdats.enabled := true;
end;

{-----------------------------------------------------------------------------}

//This procedure adds the Search results to the emulator Array.
procedure TEmuFinder.BtnOKClick(Sender: TObject);
var                    
  oldstyle : TCursor;
  e, n, NewIndex : integer;
  dup : boolean;
  tempName : string;
  aNode : PVirtualNode;
  CurResult : TQPEmu;
begin

  //firstly set the cursor to the hourglass - this cud be a while!
  oldstyle := screen.cursor;
  screen.cursor := crHourGlass;
  Try

    // determine which method the user wants to use to SAVE results
    With MainFrm do
    Begin
      // If the user wishes to overwrite the existing array then
      // clear the emulator list.

      if radOverWrite.checked = true then
        EmuList.Clear;

      //If the user wishes to add the results to the array then prepare this
      if radAppend.checked = true then
        EmuList.LoadFromFile(False);   

      // start iterating through all the nodes in the treeview
      aNode := VTefind.GetFirst;
      while aNode <> nil do
      Begin
  
        // if the node is checked then we will add it - unchecked we dont.
        if VTefind.CheckState[aNode] <> csUncheckedNormal then
        Begin
          CurResult := TQPEmu(GetObject(VTEfind, aNode));

          TempName := CurResult.name;

          n := 0;

          //Check if the emulator name already exists.
          for e := 0 to EmuList.Count-1 do
          begin

            repeat
              dup := false;
              if strCompare(CurResult.name, EmuList.Items[e].name)=0 then
              begin
                inc(n);
                CurResult.name := TempName + ' ' + IntToStr(n);
                dup := true;
              end;
            until dup = false;

          end;  //end of FOR loop through emulators

          NewIndex := Emulist.Add(TQPEmu.Create);
          Emulist.Items[NewIndex].Assign(CurResult);
          Emulist.Items[NewIndex].EmulatorID := EmuList.GenerateNextID;  

          tempName := '';

        End; //end of if checkstate

        //get the next node
        aNode := VTefind.GetNext(aNode);

      End; // end of WHILE loop

      EmuList.SaveToFile;
      EmuList.ActivateEmuIconThread();
      ResultList.Clear;
    end;

   // end;  //end of WITH block
    
  //set the cursor back to normal.
  Finally
    screen.cursor := OldStyle;
    modalresult := MrOk;
  end;
  
end;

{-----------------------------------------------------------------------------}

{-------------------- code for VTefind -------------------------------}

{-----------------------------------------------------------------------------}

procedure TEmuFinder.VTEFindGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
var
  data : TQPEmu;
begin
  data := TQPEmu(GetObject(Sender, Node));

  Case Column of
    0: CellText := Data.name;
    1: CellText := Data.path;
    2: CellText := Data.system;
  end;

end;

{-----------------------------------------------------------------------------}

procedure TEmuFinder.VTEFindCompareNodes(Sender: TBaseVirtualTree; Node1,
  Node2: PVirtualNode; Column: TColumnIndex; var Result: Integer);
var
  data1, data2 : TQPEmu;
begin

  Data1 := TQPEmu(GetObject(Sender, Node1));
  Data2 := TQPEmu(GetObject(Sender, Node2));

  if (Data1 = nil) or (Data2 = nil) then
    exit;
    
  case Column of
    0:Result := CompareText(Data1.name, Data2.name);
    1:Result := CompareText(Data1.path, Data2.path);
    2:Result := CompareText(Data1.system, Data2.system);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TEmuFinder.VTEFindHeaderClick(Sender: TVTHeader;HitInfo: TVTHeaderHitInfo);
var temp : TColumnIndex;
begin
if HitInfo.Button = mbLeft then
  begin
    with Sender, Treeview do
    begin
    temp := SortColumn;
      if SortColumn > NoColumn then
        Columns[SortColumn].Options := Columns[SortColumn].Options + [coParentColor];

        if (SortColumn = NoColumn) or (SortColumn <> HitInfo.Column) then
        begin
          //bug in VTreeView here: HitInfo.Column sometimes goes invisibly out of bounds,
          // (not when debugging, only live). also the fix has no ill effect tho it should
          if (HitInfo.Column > -1) then SortColumn := HitInfo.Column;
          SortDirection := sdAscending;
        end
        else
          if SortDirection = sdAscending then
            SortDirection := sdDescending
          else
            SortDirection := sdAscending;

        Columns[SortColumn].Color := $F7F7F7;
        SortTree(SortColumn, SortDirection, False);
    end;
  end;
end;

procedure TEmuFinder.VTEFindEditing(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; var Allowed: Boolean);
begin
  Allowed := (Column = 0)
end;

procedure TEmuFinder.VTEFindFreeNode(Sender: TBaseVirtualTree;
  Node: PVirtualNode);
begin
  SetObject(Sender, Node, nil);
end;

procedure TEmuFinder.VTEFindNewText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; NewText: WideString);
begin
  If (Node <> nil) and (NewText <> '') then
    TQPEmu(GetObject(sender, node)).name := NewText;
end;

procedure TEmuFinder.VTEFindPaintText(Sender: TBaseVirtualTree;
  const TargetCanvas: TCanvas; Node: PVirtualNode; Column: TColumnIndex;
  TextType: TVSTTextType);
var
  CurEmu : TQPEmu;
begin
  if Node <> nil then
  begin
    CurEmu := TQPEmu(GetObject(Sender, Node));
    //Check if the emulator already exists
    if MainFrm.EmuList.IndexOfPath(CurEmu.Path) <> -1 then
      TargetCanvas.Font.Color := clRed;
  end;
end;

{----------------------- end of code for VTefind -------------------------}

{ ----------------------  Code for VTdats --------------------------------}

procedure TEmuFinder.VTdatsInitNode(Sender: TBaseVirtualTree; ParentNode,
  Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
begin
  VTDats.CheckType[Node] := ctCheckBox;
  VTDats.CheckState[Node] := csUnCheckedNormal;
end;

{-----------------------------------------------------------------------------}

procedure TEmuFinder.VTdatsGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin
  if node <> nil then
    CellText := ExtractFileName(ChangeFileExt(DatFileList[Node.Index], ''));
end;

{-----------------------------------------------------------------------------}

procedure TEmuFinder.VTEFindExit(Sender: TObject);
begin
  if VTEfind.IsEditing then
    VTEfind.EndEditNode;
end;

{-----------------------------------------------------------------------------}

procedure TEmuFinder.TxtPathAfterDialog(Sender: TObject; var Name: String;
  var Action: Boolean);
var
  Ini : TMemIniFile;
begin
  if Action then
  begin
    Ini := TMemIniFile.Create(MainFrm.Settings.Paths.SettingsFile);
    try
      Ini.WriteString('eFind','LastDir', Name );
      if MainFrm.Settings.AllowWrite then
        ini.UpdateFile;
    finally
      FreeAndNil(Ini);
    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TEmuFinder.BtnSelectallClick(Sender: TObject);
var
  aNode : PVirtualNode;
begin

  aNode := VTEFind.GetFirst;
  While aNode <> nil do
  begin
    if Sender = BtnSelectAll then
      VTEFind.CheckState[aNode] := csCheckedNormal
    else
      VTEFind.CheckState[aNode] := csUnCheckedNormal;
    aNode := VTEFind.GetNextSibling(aNode);
  end;

end;

{-----------------------------------------------------------------------------}

procedure TEmuFinder.BtnNextClick(Sender: TObject);
begin
  if pcWizard.ActivePageIndex = 0 then
  begin
    pcWizard.ActivePageIndex := 1;
    BtnNext.Enabled := False;
    BtnPrevious.Enabled := True;
  end;
end;

procedure TEmuFinder.BtnPreviousClick(Sender: TObject);
begin
  if PCWizard.ActivePageIndex = 1 then
  begin
    pcWizard.ActivePageIndex := 0;
    BtnNext.Enabled := True;
    BtnPrevious.Enabled := False;
  end;
end;

end.
