unit fFind;

interface

uses
  Windows, SysUtils, Classes, Controls, Forms, Buttons, ComCtrls,
  StdCtrls, ActnList, ImgList, Menus, ExtCtrls, VirtualTrees, uRom, Contnrs, uRomList,
  Dialogs, fJWinFontForm;

type

  TQPFoundROM = class(TQPROM)
  protected
    _DirPath : String;
  public
    property DirPath : String read _DirPath write _DirPath;
    constructor create(DataFile : String; ROM : TQPROM);
  end;

  TFindForm = class(TJWinFontForm)
    FindAct: TActionList;
    ActRun: TAction;
    StatusBar: TStatusBar;
    PanControls: TPanel;
    FindPop: TPopupMenu;
    PopRun: TMenuItem;
    ActJump: TAction;
    PopJump: TMenuItem;
    ActAddFav: TAction;
    PopAdd: TMenuItem;
    VTfind: TVirtualStringTree;
    PanFilter: TPanel;
    RadMatchAll: TRadioButton;
    RadMatchAny: TRadioButton;
    VTQuery: TVirtualStringTree;
    BtnAdd: TButton;
    BtnDel: TButton;
    BtnSearch: TButton;
    BtnRun: TButton;
    BtnFavs: TButton;
    BtnJump: TButton;
    BtnClose: TButton;
    BtnVirtual: TButton;
    BtnEditOK: TButton;
    BtnEditCancel: TButton;
    procedure BtnSearchClick(Sender: TObject);
    procedure FindActUpdate(Action: TBasicAction; var Handled: Boolean);
    procedure ActRunExecute(Sender: TObject);
    procedure SearchTxtKeyDown(Sender: TObject; var Key: Word;
      Shift: TShiftState);
    procedure ActJumpExecute(Sender: TObject);
    procedure ActAddFavExecute(Sender: TObject);
    procedure VTfindGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure VTfindCompareNodes(Sender: TBaseVirtualTree; Node1,
      Node2: PVirtualNode; Column: TColumnIndex; var Result: Integer);
    procedure VTfindHeaderClick(Sender: TVTHeader; Column: TColumnIndex;
      Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure VTfindGetHint(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; var LineBreakStyle: TVTTooltipLineBreakStyle; var HintText: WideString);
    procedure VTfindIncrementalSearch(Sender: TBaseVirtualTree;
      Node: PVirtualNode; const SearchText: WideString;
      var Result: Integer);
    procedure FormCreate(Sender: TObject);
    procedure VTQueryEditing(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; var Allowed: Boolean);
    procedure VTQueryCreateEditor(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex; out EditLink: IVTEditLink);
    procedure VTQueryFocusChanged(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex);
    procedure VTQueryGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure VTQueryNewText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; NewText: WideString);
    procedure BtnAddClick(Sender: TObject);
    procedure BtnDelClick(Sender: TObject);
    procedure VTQueryFreeNode(Sender: TBaseVirtualTree;
      Node: PVirtualNode);
    procedure VTfindFreeNode(Sender: TBaseVirtualTree; Node: PVirtualNode);
    procedure BtnVirtualClick(Sender: TObject);
    procedure VTQueryExit(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
  private
    { Private declarations }
    Found : TQPROMList;
    Function GetMatchAllQuerys() : Boolean;
  public
    { Public declarations }
    Querys : TObjectList;
    NewVF : Boolean;
    procedure EditQueryMode(MatchAll : Boolean);
    Property MatchAllQuerys : Boolean read GetMatchAllQuerys;
  end;

implementation

uses fMain, fFav, uJUtilities, uJVirtualTree, JCLStrings, FindFile,
  uRomUtils, uQuery, uQPVTQueryEditor, uQPVTEditor, uQPConst, uQPMiscTypes;

{$R *.DFM}

// TQPFoundROM------------------------------------------------

constructor TQPFoundROM.create(DataFile : String; ROM : TQPROM);
begin
  _name := ROM.Name;
  _MAMEname := ROM.MAMEname;
  _ParentName := ROM.ParentName;
  _ZipName := ROM.ZipName;
  _path := ROM.Path;
  _emulator := ROM.Emulator;
  _Year := ROM.Year;
  _GameType := ROM.GameType;
  _Rating := ROM.Rating;
  _Language := ROM.Language;
  _Parameters := ROM.Parameters;
  _NumPlay := ROM.NumPlay;
  _ParamMode := ROM.ParameterMode;
  _IconIndex := ROM.IconIndex;
  _Company := ROM.Company;
  _Comment := ROM.Comment;
  _DirPath := ExtractFilePath(DataFile);
end;

// -----------------------------------------------------------

procedure TFindForm.EditQueryMode(MatchAll : Boolean);
var
  aNode : PVirtualNode;
begin
  //Querys.Clear;
  //Querys.Assign(OldQuery, laCopy);

  //hide buttons we dont need..
  BtnClose.Hide;
  BtnFavs.Hide;
  BtnJump.Hide;
  BtnRun.Hide;
  BtnVirtual.Hide;
  BtnEditCancel.Show;
  BtnEditOK.Show;

  //change the caption
  Self.Caption := 'Edit Virtual Folder Search';

  if MatchAll then
    RadMatchAll.Checked
  else
    RadMatchAny.Checked;

  //lock the queries tree..
  VTQuery.BeginUpdate;
  try
    VTQuery.Clear;
    VTQuery.RootNodeCount := Querys.Count;
    aNode := VTQuery.GetFirst;
    while aNode <> nil do
    begin
      SetObject(VTQuery, aNode, Querys[aNode.Index]);
      aNode := VTQuery.GetNextSibling(aNode);
    end;
  finally
    VTQuery.EndUpdate;
  end;

  if Querys.Count > 1 then
    BtnDel.Enabled := True;
end;

{-----------------------------------------------------------------------------}

Function TFindForm.GetMatchAllQuerys() : Boolean;
begin
  Result := (RadMatchAll.Checked);
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.BtnAddClick(Sender: TObject);
begin
  //Adds more filters to the search.
  if TQPQuery(GetObject(VTQuery, VTQuery.GetLast())).Filter <> '' then
  begin
    Querys.Add(TQPQuery.create(qfName, '', qcContain));
    VTQuery.RootNodeCount := Querys.Count;
    SetObject(VTQuery, VTQuery.GetLast, Querys.Last);
    BtnDel.Enabled := True;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.BtnDelClick(Sender: TObject);
begin
  // removes a filter, must always leave ONE filter intact.
  if VTQuery.RootNodeCount > 1 then
  begin
    Querys.Delete(VTQuery.getFirstSelected.Index);
    VTQuery.DeleteNode(VTQuery.GetFirstSelected);
    if VTQuery.RootNodeCount = 1 then
      BtnDel.Enabled := False;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.BtnSearchClick(Sender: TObject);
var
  OldCursor : TCursor;
  RomFiles : TStringList;
  TmpList : TQPROMList;
  i, e : Integer;
  Node : PVirtualNode;
  MatchAll : Boolean;
begin
    VTQuery.EndEditNode();

    Found.Clear;
    VTFind.RootNodeCount := 0;

    OldCursor := Screen.Cursor;
    Screen.Cursor := crHourGlass;

    RomFiles := TStringList.Create;
    Try
      TmpList := TQPROMlist.Create(MainFrm.Settings.AllowWrite);

      //setup the search box.
      GetAllROMFiles(RomFiles);

      if RadMatchAll.Checked then
        MatchAll := True
      else
        MatchAll := False;

      for i := 0 to RomFiles.Count-1 do
      begin
          TmpList.LoadMatchesFromFile(RomFiles[i], Querys, MatchAll);
          for e := 0 to TmpList.Count-1 do
            if TmpList[e].MatchesQuery(Querys, MatchAll) then
              Found.Add(TQPFoundROM.create(RomFiles[i], TmpList[e]));

          //free whats in the ROMs array
          TmpList.clear;

      end; //start of OVERALL for loop      

      //update the VT with the search results.
      VTFind.BeginUpdate;
      Try
        VTFind.RootNodeCount := Found.Count;

        Node := VTFind.GetFirst;
        while Node <> nil do
        begin
          SetObject(VTFind, Node, Found[Node.Index]);
          Node := VTFind.GetNextSibling(Node);
        end;
      Finally
        VTFind.EndUpdate;
      end;

      if Found.Count = 0 then
        StatusBar.SimpleText := QP_QUERY_NO_MATCHES
      ELSE
        StatusBar.SimpleText := IntToStr(Found.Count) + ' ' + QP_MATCHES;

    Finally
      FreeAndNil(RomFiles);
      FreeAndNil(TmpList);
      Screen.cursor := oldcursor;
    end;

    BtnVirtual.Enabled := True;

end;

{-----------------------------------------------------------------------------}

procedure TFindForm.BtnVirtualClick(Sender: TObject);
var
  Name : String;
  i : Integer;
  outFile : TStringList;
begin
  if Found.Count > 0 then
  begin

    Name := InputBox(QP_FINDFRM_VIRTUAL_NAME, QP_FINDFRM_VIRTUAL_NAME_LONG, '');
    if name <> '' then
    begin

      //now check if this name already exists.
      if not FileExists(MainFrm.Settings.Paths.SearchDir + Name + '.qpq') then
      begin
        outFile := TStringList.Create;
        try
          outFile.Add(BoolToStr(RadMatchAll.Checked));
          for i := 0 to Querys.Count-1 do
            OutFile.Add(TQPQuery(Querys[i]).ToString);

          outFile.SaveToFile(MainFrm.Settings.Paths.SearchDir + Name + '.qpq');
        finally
          FreeAndNil(outFile);
        end;

        NewVF := True;
      end
      else
        MessageDlg(QP_FINDFRM_NAME_TAKEN, mtError, [mbOK], 0);

    end
    else
      MessageDlg(QP_FINDFRM_NAME_BLANK, mtError, [mbOK], 0);

  end
  else
    MessageDlg(QP_FINDFRM_NO_RESULTS, mtError, [mbOK], 0);
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.FindActUpdate(Action: TBasicAction;
  var Handled: Boolean);
begin
  if Assigned(VTFind.FocusedNode) then
  begin
    ActRun.Enabled := true;
    ActJump.enabled := true;
    ActAddFav.enabled := true;
  end
  else
  begin
    ActRun.Enabled := false;
    ActJump.enabled := false;
    ActAddFav.enabled := false;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.ActRunExecute(Sender: TObject);
var
  ROMtoRun : TQPROM;
begin
  If Assigned(VTFind.FocusedNode) then
  Begin

    //get the data for the selected node
    ROMtoRun := TQPROM(GetObject(VTFind, VTFind.FocusedNode));

    Self.Visible := False;

    MainFrm.RunROM(RomToRun, MainFrm.EmuList.GetEmuForROM(RomtoRun));

    Self.Visible := True;

  End;

end;

{-----------------------------------------------------------------------------}

procedure TFindForm.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  VTQuery.CancelEditNode();
  VTQuery.RootNodeCount := 0;
  VTFind.RootNodeCount := 0;
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.FormDestroy(Sender: TObject);
begin
  FreeAndNil(Querys);
  FreeAndNil(Found);
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.FormCreate(Sender: TObject);
begin

  //if the find image exists, might as well load it.
  if FileExists(MainFrm.Settings.Paths.AppDir + 'find.png') then
  begin
    vtFind.Background.LoadFromFile(MainFrm.Settings.Paths.AppDir + 'find.png');
    vtFind.TreeOptions.PaintOptions := vtFind.TreeOptions.PaintOptions + [toShowBackground]
  end;

  NewVf := False;

  Found := TQPROMList.Create(MainFrm.Settings.AllowWrite);
  VTFind.NodeDataSize := SizeOf(Pointer);
  VTFind.RootNodeCount := 0;

  Querys := TObjectList.Create(True);
  VTQuery.NodeDataSize := SizeOf(Pointer);
  
  Querys.Add(TQPQuery.Create(qfName, '', qcContain));
  VTQuery.RootNodeCount := Querys.Count;
  SetObject(VTQuery, VTQuery.GetFirst, Querys.Last);
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.SearchTxtKeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
  if (key = VK_return) then BtnSearch.Click;
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.ActJumpExecute(Sender: TObject);
var
  SelectedRom : TQPFoundROM;
  DirFound : Boolean;
begin

  // this code will find the ROM selected in the search results
  // and then jump to that rom in the rom listing.

  //ensure a file has been selected
  if VTFind.GetFirstSelected <> nil then
  Begin

    SelectedRom := TQPFoundROM(GetObject(VTFind, VTFind.GetFirstSelected));

    If SelectedROM.ZipName <> '' then
      DirFound := MainFrm.JumpToROM(SelectedROM.DirPath, SelectedROM.ZipName, QPRZip)
    else if SelectedROM.MAMEname <> '' then
      DirFound := MainFrm.JumpToROM(SelectedROM.DirPath, SelectedROM.MAMEname, QPRClone)
    else
      DirFound := MainFrm.JumpToROM(SelectedROM.DirPath, SelectedROM.Path, QPRPath);

    //the ROM was found, close the find rom dialog.
    If DirFound then
    begin
      ModalResult := MrYes;
      MainFrm.VTRoms.SetFocus;
    end
    else
    Begin
      MainFrm.VTDir.FocusedNode := MainFrm.VTDir.GetFirst;
      MainFrm.VTDir.Selected[MainFrm.VTDir.GetFirst] := True;
      ModalResult := MrYes;
      MainFrm.VTRoms.SetFocus;
    end;
      
  End; 

end;

{-----------------------------------------------------------------------------}

procedure TFindForm.ActAddFavExecute(Sender: TObject);
var
  SelROM : TQPROM;
begin

  if Assigned(VTFind.FocusedNode) then
  Begin

    //get the data for the selected node
    SelROM := TQPROM(GetObject(VTFind, VTFind.FocusedNode));

    With MainFrm do
    Begin
      FavList.Add(TQPRom.Create(SelROM.ToString));
      FavList.SaveToFile();
      BuildFavMenu;
    End;

  End;
 
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.VTfindGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
var
  ROM : TQPROM;
begin
  //get the data for the node
  ROM := TQPROM(GetObject(Sender, Node));
  case Column of
    0: CellText := ROM.Name;
    1: Celltext := ROM.Emulator;
    2: CellText := ROM.Path;
  end;

end;

{-----------------------------------------------------------------------------}

procedure TFindForm.VTfindCompareNodes(Sender: TBaseVirtualTree; Node1,
  Node2: PVirtualNode; Column: TColumnIndex; var Result: Integer);
var
  Data1, Data2: TQPROM;
begin

  Data1 := TQPROM(GetObject(Sender, Node1));
  Data2 := TQPROM(GetObject(Sender, Node2));

  case Column of
    0:Result := CompareText(Data1.name, Data2.name);
    1:Result := CompareText(Data1.Emulator, Data2.Emulator);
    2:Result := CompareText(data1.Path, data2.Path);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.VTfindHeaderClick(Sender: TVTHeader;
  Column: TColumnIndex; Button: TMouseButton; Shift: TShiftState; X,
  Y: Integer);
begin
   with Sender,VTFind do
   begin
    // this sets column color back to what it was (not needed if not
    // highlighting sorted column)
    if SortColumn<>NoColumn then

      Columns[SortColumn].Options:=Columns[SortColumn].Options+[coParentColor];

    // first time click on a column; start a sort
    if (SortColumn=NoColumn) or (SortColumn<>Column) then
    begin
      SortColumn:=Column;
      SortDirection:=sdAscending;

    // second+ time click on a column; toggle the sort order
    end
    else
    begin
      if SortDirection=sdAscending then
        SortDirection:=sdDescending
      else
        SortDirection:=sdAscending;
    end;

    // this sets column to gray to indicate this column is sorted  (not
    // needed if not highlighting sorted column)
    Columns[SortColumn].Color:=$f7f7f7;

    // actually perform the sort
    SortTree(SortColumn,SortDirection,False);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.VTfindFreeNode(Sender: TBaseVirtualTree;
  Node: PVirtualNode);
begin
  // I have NO idea if this is what im supposed to do at this point, do it anyway...
  SetObject(Sender, Node,  nil);
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.VTfindGetHint(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; var LineBreakStyle: TVTTooltipLineBreakStyle; var HintText: WideString);
var
  ROm : TQPRom;
begin
If Node <>  nil then
  begin
    ROM := TQPRom(GetObject(Sender, Node));

    If ROM <> nil then
      //displays the hint for the ROM list.  Should maybe make this an option
      HintText := ROM.Summary;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.VTfindIncrementalSearch(Sender: TBaseVirtualTree;
  Node: PVirtualNode; const SearchText: WideString; var Result: Integer);
var
  sCompare1, sCompare2 : string;
  DisplayText : WideString;

begin
     VTFind.IncrementalSearchDirection := sdForward;
     // Note: This code requires a proper Unicode/WideString comparation routine which I did not want to link here for
     // size and clarity reasons. For now strings are (implicitely) converted to ANSI to make the comparation work.
     // Search is not case sensitive.
      VTFindGetText( Sender, Node, 0 {Column}, ttNormal, DisplayText );
      sCompare1 := SearchText;
      sCompare2 := DisplayText;

     // By using StrLIComp we can specify a maximum length to compare. This allows us to find also nodes
     // which match only partially. Don't forget to specify the shorter string length as search length.
     Result := StrLIComp( pchar(sCompare1), pchar(sCompare2), VTMin(Length(sCompare1), Length(sCompare2)) )
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.VTQueryEditing(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; var Allowed: Boolean);
begin
  Allowed := True;
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.VTQueryCreateEditor(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; out EditLink: IVTEditLink);
begin
  if Column in [0, 1] then
    EditLink :=  TFilterEditLink.Create(qpeCustom)
  else
    EditLink := TQPVTEdit.Create(qpeEdit);
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.VTQueryFocusChanged(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex);
begin
  If (Node <> nil) then
    VTQuery.EditNode(Node, Column);
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.VTQueryGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin
  if Node <> nil then
  begin
    Case Column of
      0: CellText := TQPQuery(GetObject(Sender, Node)).FieldStr;
      1: CellText := TQPQuery(GetObject(Sender, Node)).ConditionStr;
      2: CellText := TQPQuery(GetObject(Sender, Node)).Filter;
    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.VTQueryNewText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; NewText: WideString);
begin
  if (Node <> nil) and( Column = 2) then
    TQPQuery(GetObject(Sender, Node)).Filter := NewText;
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.VTQueryFreeNode(Sender: TBaseVirtualTree;
  Node: PVirtualNode);
begin
  // I have NO idea if this is what im supposed to do at this point, do it anyway...
  SetObject(Sender, Node,  nil);
end;

{-----------------------------------------------------------------------------}

procedure TFindForm.VTQueryExit(Sender: TObject);
begin
  if VTQuery.IsEditing then
    VTQuery.EndEditNode;
end;



end.
