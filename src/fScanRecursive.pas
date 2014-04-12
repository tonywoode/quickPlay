unit fScanRecursive;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms,
  VirtualTrees, StdCtrls, Contnrs, JvBaseDlg, JvBrowseFolder,
  ComCtrls, Dialogs, JvComponent, Mask, JvExMask, JvToolEdit, fJWinFontForm;

type

  TQPScanDir = class
  private
    FName,
    FPath,
    FEmulator : String;
    FGoodMerge : Boolean;
  published
    Property Name : String Read FName Write FName;
    Property Path : String Read FPath Write FPath;
    Property Emulator : String Read FEmulator Write FEmulator;
    Property GoodMerge : Boolean read FGoodMerge write FGoodMerge;
    constructor create(name, path, emulator : String);
  end;

  TRecursiveFrm = class(TJWinFontForm)
    VTscan: TVirtualStringTree;
    ChkAutoMirror: TCheckBox;
    BtnOK: TButton;
    BtnCancel: TButton;
    Label1: TLabel;
    ProgScan: TProgressBar;
    ChkSetChild: TCheckBox;
    ComboBox1: TComboBox;
    TxtDir: TJvDirectoryEdit;
    procedure VTscanChecked(Sender: TBaseVirtualTree; Node: PVirtualNode);
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure VTscanInitNode(Sender: TBaseVirtualTree; ParentNode,
      Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
    procedure VTscanInitChildren(Sender: TBaseVirtualTree;
      Node: PVirtualNode; var ChildCount: Cardinal);
    procedure VTscanGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure VTscanCreateEditor(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex; out EditLink: IVTEditLink);
    procedure VTscanGetImageIndex(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
      var Ghosted: Boolean; var ImageIndex: Integer);
    procedure VTscanEditing(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; var Allowed: Boolean);
    procedure VTscanKeyDown(Sender: TObject; var Key: Word;
      Shift: TShiftState);
    procedure VTscanBeforeCellPaint(Sender: TBaseVirtualTree; TargetCanvas: TCanvas;
  Node: PVirtualNode; Column: TColumnIndex;  CellPaintMode: TVTCellPaintMode; CellRect: TRect);
    procedure VTscanFocusChanged(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex);
    procedure BtnOKClick(Sender: TObject);
    procedure VTscanFreeNode(Sender: TBaseVirtualTree; Node: PVirtualNode);
    procedure VTscanExit(Sender: TObject);
    procedure VTscanNewText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; NewText: WideString);
    procedure TxtDirAfterDialog(Sender: TObject; var Name: String;
      var Action: Boolean);
    procedure TxtDirKeyDown(Sender: TObject; var Key: Word;
      Shift: TShiftState);
  private
    { Private declarations }
    ScanList : TObjectList;
    RootDir : String;
    procedure InitiateTree(RootPath : String);
    procedure RemoveNodeAndData(Node : PVirtualNode);
  public
    { Public declarations }
    Property AddToDir : String Read RootDir Write RootDir;
  end;

implementation

uses JclStrings, uJVirtualTree, fMain, FindFile, IniFiles,
  uRom, uJFile, uRomList, uEmuList, uQPVTEditor, uJCompression, uQPMiscTypes,
  uQPCompObj, uEmuUtils;

{$R *.dfm}

{ TQPScanDir }

constructor TQPScanDir.create(name, path, emulator: String);
begin
  FName := name;
  FPath := Path;
  FEmulator := Emulator;
end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.InitiateTree(RootPath : String);
begin
  //now add a root node to the tree.
  VTScan.BeginUpdate;
  VTScan.Clear;
  ScanList.Clear;
  ScanList.Add(TQPScanDir.create('Root Directory', RootPath, ''));
  VTScan.RootNodeCount := 1;
  //VTScan.ValidateNode(VTScan.GetFirst, false);
  VTScan.FullExpand();
  VTScan.EndUpdate;
end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.FormCreate(Sender: TObject);
begin
  VTScan.NodeDataSize := SizeOf(Pointer);

  //create the objectlist
  ScanList := TObjectlist.Create(True);
end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.FormDestroy(Sender: TObject);
begin
  ScanList.Clear;
  FreeAndNil(ScanList);
end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.VTscanInitNode(Sender: TBaseVirtualTree;
  ParentNode, Node: PVirtualNode;
  var InitialStates: TVirtualNodeInitStates);
begin

  If VTScan.GetNodeLevel(Node) = 0 then
  Begin
    SetObject(Sender, Node, ScanList[0]);
    Include(InitialStates, ivsExpanded);
  end;

  if HasSubDirs(TQPScanDir(ScanList.Last).Path) then
  begin
    Include(InitialStates, ivsHasChildren);
    //Include(InitialStates, ivsExpanded);
  end;

  Sender.CheckType[Node] := ctCheckBox;
  Sender.CheckState[Node] := csUncheckedNormal;

end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.VTscanInitChildren(Sender: TBaseVirtualTree;
  Node: PVirtualNode; var ChildCount: Cardinal);
var
  ChildNode : PvirtualNode;
  NewName : String;
  SR: TSearchRec;
  CurDir : TQPScanDir;
begin
  If Node <> nil then
  begin
    CurDir := TQPScanDir(GetObject(Sender, Node));

  if (CurDir <> nil) and
     (FindFirst(IncludeTrailingPathDelimiter(CurDir.Path) + '*.*', faDirectory, SR) = 0) then
  begin
    try
      repeat
        if (SR.Name <> '.') and (SR.Name <> '..') then
        begin
          NewName := IncludeTrailingPathDelimiter(CurDir.Path) + SR.Name;
          if (SR.Attr and faDirectory <> 0) then
          begin
            ChildNode := Sender.AddChild(Node);
            ScanList.Add(TQPScanDir.create(SR.Name, NewName, ''));
            SetObject(Sender, ChildNode, ScanList.Last);
            Sender.ValidateNode(Node, False);
          end;
        end;
      until FindNext(SR) <> 0;
      ChildCount := Sender.ChildCount[Node];

      // finally sort node
      if ChildCount > 0 then
        Sender.Sort(Node, 0, TVirtualStringTree(Sender).Header.SortDirection, False);
    finally
      FindClose(SR);
    end;
  end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.VTscanNewText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; NewText: WideString);

  Procedure RecursiveSet(aNode : PvirtualNode; Emu : String);
  begin
    While aNode <> nil do
    begin
      TQPScanDir(GetObject(Sender, aNode)).Emulator := Emu;
      If Sender.ChildCount[aNode] > 0 then
        RecursiveSet(Sender.GetFirstChild(aNode), Emu);
      aNode := Sender.GetNextSibling(aNode);
    end;//end of WHILE
  end;

begin

  If (Node <> nil) then
  begin
    TQPScanDir(GetObject(Sender, Node)).Emulator := NewText;
    if ChkSetChild.Checked then
      RecursiveSet(Sender.GetFirstChild(Node), NewText);
  end;

end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.VTscanGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin
  Case Column of
  0: CellText := TQPScanDir(GetObject(Sender, Node)).Name;
  1: CellText := TQPScanDir(GetObject(Sender, Node)).Emulator;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.VTscanChecked(Sender: TBaseVirtualTree;
  Node: PVirtualNode);

  Procedure RecursiveSet(aNode : PvirtualNode; InGM : Boolean);
  begin
    While aNode <> nil do
    begin
      TQPScanDir(GetObject(Sender, aNode)).GoodMerge := InGM;
      if inGM then
        Sender.CheckState[aNode] := csCheckedNormal
      else
        Sender.CheckState[aNode] := csUncheckedNormal;
        
      If Sender.ChildCount[aNode] > 0 then
        RecursiveSet(Sender.GetFirstChild(aNode), InGM);
      aNode := Sender.GetNextSibling(aNode);
    end;//end of WHILE
  end;

begin

  If (Node <> nil) then
  begin
    TQPScanDir(GetObject(Sender, Node)).GoodMerge := Sender.CheckState[Node] = csCheckedNormal;
    if ChkSetChild.Checked then
    begin
      Sender.BeginUpdate;
      try
        RecursiveSet(Sender.GetFirstChild(Node), Sender.CheckState[Node] = csCheckedNormal);
      finally
        Sender.EndUpdate;
      end;
    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.VTscanCreateEditor(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; out EditLink: IVTEditLink);
begin
  { Create one of my EditLinks }
  if Column = 1 then
    EditLink := TQPVTEdit.Create(qpeComboEmu);
end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.VTscanFreeNode(Sender: TBaseVirtualTree;
  Node: PVirtualNode);
begin
  SetObject(Sender, Node, nil);
end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.VTscanGetImageIndex(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
  var Ghosted: Boolean; var ImageIndex: Integer);
begin
  If Column = 0 then
    case Kind of
      ikNormal: ImageIndex := 0;
      ikSelected: ImageIndex := 1;
    end;
end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.VTscanEditing(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; var Allowed: Boolean);
begin
  Allowed := (Column = 1);
end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.VTscanExit(Sender: TObject);
begin
  if VTScan.IsEditing then
    VTScan.EndEditNode;
end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.VTscanKeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
  If (VTScan.FocusedNode <> nil) and (Key = VK_DELETE) then
  Begin

    VTScan.BeginUpdate;

    RemoveNodeAndData(VTScan.FocusedNode);

    VTScan.EndUpdate;

  End;
end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.RemoveNodeAndData(Node: PVirtualNode);
var
  Child : PVirtualNode;
begin

  ScanList.Remove(GetObject(VTScan, Node));

  If VTScan.ChildCount[Node] > 0 then
  Begin

    Child := VTScan.GetFirstChild(Node);
    While Child <> nil do
    Begin
      RemoveNodeAndData(Child);
      Child := VTScan.GetNextSibling(Child);
    End;

  end;

  VTScan.DeleteNode(Node);
end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.VTscanBeforeCellPaint(Sender: TBaseVirtualTree; TargetCanvas: TCanvas;
  Node: PVirtualNode; Column: TColumnIndex;  CellPaintMode: TVTCellPaintMode; CellRect: TRect);
begin
  If (Column = 1) then
  begin
    ComboBox1.Width := TVirtualStringTree(Sender).Header.Columns[Column].Width;
    Windows.OffsetWindowOrgEx(TargetCanvas.Handle, -CellRect.Left, -CellRect.Top, nil);
    SendMessage(ComboBox1.Handle, WM_PRINT, wParam(TargetCanvas.Handle), PRF_CLIENT or PRF_NONCLIENT);
    Windows.OffsetWindowOrgEx(TargetCanvas.Handle, CellRect.Left, CellRect.Top, nil);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.VTscanFocusChanged(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex);
begin
  If (Node <> nil) then
  begin
    VTScan.EditNode(Node, 1);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.BtnOKClick(Sender: TObject);
var
  i : Integer;
  Ini : TMemIniFile;
  SavePath : String;
  TmpList : TQPROMlist;
  OldCursor : TCursor;
  FFilter : String;

  ForSys : String;
  FilterSave : TMemoryStream;
begin

  //time to do all the hard work.
  //by this stage we should have an objectlist full of directories
  //to scan, if the objectlist is empty then we do nothing.

  If ScanList.Count > 0 then
  Begin

    //the scanlist is not empty so begin
    //change the screen cursor
    OldCursor := Screen.Cursor;
    Screen.Cursor := crHourGlass;
    //use a try here so we can reset the cursor IF there is a problem
    try

    //now set up the progress bar
    ProgScan.Position := 0;
    ProgScan.Max := ScanList.Count;

    //ensure we got a valid directory to work with.
    If RootDir = '' then
      exit;

    //create the findfile object, and set up common settings
    TmpList := TQPROMlist.Create(MainFrm.Settings.AllowWrite);
    Try
      //now we want to loop through each of the objects
      For i := 0 to ScanList.Count-1 do
      begin

        //first thing to do is create the directory for the new data file.
        SavePath := RootDir + StrAfter(IncludeTrailingPathDelimiter(TxtDir.Text),TQPScanDir(ScanList.Items[i]).Path);

        //if the directory doesnt exist - create it.
        If not DirectoryExists(SavePath) then
          CreateDir(SavePath);

        FFilter := '';

        //works out the filter based on what is in the SysFileExtensions ini file.
        if TQPScanDir(ScanList.Items[i]).Emulator = '' then
          FFilter := uQPCompObj.Compression.SupportedFileExtsForFind
        else
        begin
          //at this point we load the file and work based on its contents.
          
          ForSys := MainFrm.EmuList[MainFrm.EmuList.IndexOfName(TQPScanDir(ScanList.Items[i]).Emulator)].System;
          fFilter := uEmuUtils.FileExtsForSystem(ForSys);
        end;

        TmpList.FileName := includeTrailingPathDelimiter(SavePath)+DefaultFileName;
        TmpList.AddFromDirs(TQPScanDir(ScanList.Items[i]).Path, FFilter, False, False,
                            TQPScanDir(ScanList.Items[i]).Emulator, '', lmNone, False);

        TmpList.Clear;

        Ini := TMemIniFile.Create(includeTrailingPathDelimiter(SavePath)+'folders.ini');
        try

          //now set up the directory mirroring if required.
          if ChkAutoMirror.Checked then
          begin

            Ini.Clear;
            Ini.WriteBool('Mirror', 'ChkMirror', true);
            Ini.WriteString('Mirror', 'TxtDir', TQPScanDir(ScanList.Items[i]).Path);
            Ini.WriteString('Mirror', 'CmbEmu', TQPScanDir(ScanList.Items[i]).Emulator);
            //save what is in FFilter into a stream and then dump into registry.
            FilterSave := TMemoryStream.Create;
            try
              JCLStrings.StrReplace(FFilter, ';', #13#10, [rfIgnoreCase, rfReplaceAll]);
              FilterSave.WriteBuffer(FFilter[1], Length(FFilter));
              FilterSave.Position := 0;
              Ini.WriteBinaryStream('Mirror', 'LstFilter', FilterSave);
              //Ini.WriteString('Mirror', 'LstFilter', '2A2E7A69700D0A');
            finally
              FreeAndNil(FilterSave);
            end;
            
            if MainFrm.Settings.AllowWrite then
              Ini.UpdateFile;

          end;  //end of Directory Mirror setup.

          if TQPScanDir(ScanList.Items[i]).GoodMerge then
          begin
            //GoodMerge Compatibility setting
            Ini.WriteBool('GoodMerge', 'GoodMergeCompat', true);
            Ini.WriteString('GoodMerge', 'pref1', '(U)');
            Ini.WriteString('GoodMerge', 'pref2', '(E)');
            Ini.WriteString('GoodMerge', 'pref3', '(J)');
            if MainFrm.Settings.AllowWrite then
              Ini.UpdateFile;
          end;

        Finally
          FreeAndNil(Ini);
        end;
        //step the progress bar
        ProgScan.StepIt;

      end; //end of FOR objectlist loop.

    Finally
      FreeAndNil(TmpList);
    end;

    //restore the cursor
    Finally
      Screen.Cursor := OldCursor;
    end;
    
  End; //end of IF scanlist.count <> 0

end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.TxtDirAfterDialog(Sender: TObject;
  var Name: String; var Action: Boolean);
begin
  if Action then
    Self.InitiateTree(Name);
end;

{-----------------------------------------------------------------------------}

procedure TRecursiveFrm.TxtDirKeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
  if (Key = VK_RETURN) and (DirectoryExists(TxtDir.Text)) then
    InitiateTree(TxtDir.Text);
end;

{-----------------------------------------------------------------------------}

end.
