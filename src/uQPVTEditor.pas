unit uQPVTEditor;

interface

uses Controls, VirtualTrees, StdCtrls, Messages, Types, Classes, Windows,
     uQPMiscTypes;

type

  TQPVTEdit = class(TInterfacedObject, IVTEditLink)
  protected
    FEditType : TQPEditType;
    FEdit : TWinControl;
    FEditing: Boolean;
    FEditColumn: integer;
    FEditNode: PVirtualNode;
    FEditTree: TVirtualStringTree;
    FNodeRect: TRect;

    //override the next 2 functions to do your 'work'
    procedure DoCustomEnd();virtual;
    procedure DoCustomPrepare();virtual;
    
    procedure EditKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    Procedure CreateCombo();
    Procedure CreateEdit();
    Procedure CreateFileEdit();
    Procedure CreateDirectoryEdit();
  public
    constructor Create(EditType : TQPEditType);
    destructor Destroy; override;

    function BeginEdit: Boolean; stdcall; // called when editing actually starts
    function CancelEdit: Boolean; stdcall; // called when editing has been cancelled by the tree
    function EndEdit: Boolean; stdcall; // called when editing has been finished by the tree
    function PrepareEdit(Tree: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex): Boolean; stdcall; // called after creation to allow a setup
    function GetBounds: TRect; stdcall; // called to get the current size of the edit window (only important if the edit resizes itself)
    procedure ProcessMessage(var Message: TMessage); stdcall; // used to forward messages to the edit window(s)
    procedure SetBounds(R: TRect); stdcall;

    property EditType : TQPEditType read FEditType write FEditType;
    property Edit: TWinControl read FEdit write FEdit;
    property EditColumn: integer read FEditColumn write FEditColumn;
    property EditNode: PVirtualNode read FEditNode write FEditNode;
    property EditTree: TVirtualStringTree read FEditTree write FEditTree;
    property Editing: Boolean read FEditing write FEditing;
    property NodeRect: TRect read FNodeRect write FNodeRect;
  end;


implementation

uses JvExMask, JvToolEdit, SysUtils, fMain, uEmuList, uQPConst,
     ujMiscResourceStrs, ujPowerSchemes, ujProcesses;

procedure TQPVTEdit.DoCustomEnd();
begin
end;

procedure TQPVTEdit.DoCustomPrepare();
begin
end;

function TQPVTEdit.BeginEdit: Boolean;
begin
  if Assigned(Edit) then
  begin
    Result := True;
    Edit.Show;
    Edit.SetFocus;
    Editing := True;
  end else
    Result := False;
end;

function TQPVTEdit.CancelEdit: Boolean;
begin
  Result := True;  // Always allow a cancel
  if Editing then
  begin
    Editing := False;
    Edit.Hide;
    EditTree.SetFocus;
    EditTree := nil;
    EditColumn := -1;
    EditNode := nil;
  end
end;

constructor TQPVTEdit.Create(EditType : TQPEditType);
begin
  Self.EditType := EditType;
end;

Procedure TQPVTEdit.CreateCombo();
begin
  FEdit := TComboBox.Create(nil);
  with FEdit as TComboBox do
  begin
    Visible := False;
    Parent := EditTree;
    OnKeyDown := EditKeyDown;
    TCombobox(FEdit).Style := csDropDownList;
  end;
end;

Procedure TQPVTEdit.CreateEdit();
begin
  FEdit := TEdit.Create(nil); // Nobody owns it
  with FEdit as TEdit do
  begin
    Visible := False;
    Parent := EditTree;
    OnKeyDown := EditKeyDown;
  end;
end;

Procedure TQPVTEdit.CreateFileEdit();
begin
  FEdit := TJvFilenameEdit.Create(nil);
  with FEdit as TJvFilenameEdit do
  begin
    AddQuotes := False;
    Visible := False;
    Parent := EditTree;
    OnKeyDown := EditKeyDown;
  end;
end;

Procedure TQPVTEdit.CreateDirectoryEdit();
begin
  FEdit := TJvDirectoryEdit.Create(nil);
  with FEdit as TJvDirectoryEdit do
  begin
    Visible := False;
    Parent := EditTree;
    OnKeyDown := EditKeyDown;
  end;
end;

destructor TQPVTEdit.Destroy;
begin
  Edit.Free;
  inherited;
end;

procedure TQPVTEdit.EditKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
var
  CanAdvance: Boolean;
begin
  case Key of
    VK_RETURN,
    VK_UP,
    VK_DOWN:
      begin
        // Consider special cases before finishing edit mode.
        CanAdvance := Shift = [];
        if FEdit is TComboBox then
          CanAdvance := CanAdvance and not TComboBox(FEdit).DroppedDown;
        
        if CanAdvance then
        begin
          PostMessage(EditTree.Handle, WM_KEYDOWN, Key, 0);
          Key := 0;
          EditTree.SetFocus;
        end;
      end;
  end;
end;

function TQPVTEdit.EndEdit: Boolean;
begin
  Result := True;  // Always allow end
  if Editing then
  begin

    if EditType = qpeCustom then
      DoCustomEnd
    else if (EditType in [qpeROMParamMode, qpePriority, qpeExtractDest]) then
      //for the parameter mode return the itemindex, obviously NEVER sort these!
      EditTree.Text[EditNode, EditColumn] := IntToStr(TComboBox(FEdit).ItemIndex)
    else if FEdit is TEdit then
      EditTree.Text[EditNode, EditColumn] := TEdit(FEdit).Text
    else if FEdit is TComboBox then
      EditTree.Text[EditNode, EditColumn] := TComboBox(FEdit).Text
    else if FEdit is TJvFilenameEdit then
      EditTree.Text[EditNode, EditColumn] := TJvFilenameEdit(FEdit).FileName
    else if FEdit is TJvDirectoryEdit then
      EditTree.Text[EditNode, EditColumn] := TJvDirectoryEdit(FEdit).Text;


    EditTree := nil;
    EditColumn := -1;
    EditNode := nil;
  end
end;

function TQPVTEdit.GetBounds: TRect;
begin
  Result := Edit.BoundsRect
end;

function TQPVTEdit.PrepareEdit(Tree: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex): Boolean;
var
  Pwr : TStrings;
  pri : TStrings;
begin
    Result := True;
    EditTree := TVirtualStringTree(Tree);
    EditNode := Node;
    EditColumn := Column;

    //Create whatever type of control we require.

    case EditType of
      qpeEdit : //creates a standard text edit.
                Begin
                  CreateEdit();
                  TEdit(FEdit).Text := EditTree.Text[EditNode, EditColumn];
                end; //end of qpeEdit setup.
                
      qpeCombo: //creates a combo, and calls DoCustomPrepare to get items
                begin
                  CreateCombo();
                  DoCustomPrepare();  
                end; //end of qpeCombo setup.

      qpeComboEmu:     //creates combo with emulators preloaded
                begin
                  CreateCombo();
                  with FEdit as TComboBox do
                  begin
                    Sorted := true;
                    MainFrm.EmuList.EmusToStrings(items, cfAllEmus);
                    ItemIndex := Items.IndexOf(EditTree.Text[EditNode, EditColumn]);
                  end;
                end;
                
      qpeComboSys:     //creates combo with systems preloaded
                begin
                  CreateCombo();
                  with FEdit as TComboBox do
                  begin
                    Sorted := true;
                    If not FileExists(MainFrm.Settings.Paths.SystemsFile) then
                      MainFrm.Settings.CreateLanguage(MainFrm.Settings.Paths.SystemsFile);

                    items.loadFromFile(MainFrm.Settings.Paths.SystemsFile);
                    ItemIndex := Items.IndexOf(EditTree.Text[EditNode, EditColumn]);
                  end;
                end;

      qpeComboRating:  //creates combo with ratings preloaded
                begin
                  CreateCombo();
                  with FEdit as TComboBox do
                  begin
                    MainFrm.Settings.Ratings(TComboBox(FEdit));
                    ItemIndex := Items.IndexOf(EditTree.Text[EditNode, EditColumn]);
                  end;
                end;

      qpeComboLang:    //creates combo with languages preloaded
                begin
                  CreateCombo();
                  with FEdit as TComboBox do
                  begin
                    Sorted := true;
                    If not FileExists(MainFrm.Settings.Paths.LanguageFile) then
                      MainFrm.Settings.CreateLanguage(MainFrm.Settings.Paths.LanguageFile);
                    Items.LoadFromFile(MainFrm.Settings.Paths.LanguageFile);
                    ItemIndex := Items.IndexOf(EditTree.Text[EditNode, EditColumn]);
                  end;
                end;

      qpeComboType:    //creates combo with game types preloaded
                begin
                  CreateCombo();
                  with FEdit as TComboBox do
                  begin
                    Sorted := true;
                    if not FileExists(MainFrm.Settings.Paths.GameTypeFile) then
                      MainFrm.Settings.CreateTypeDat(MainFrm.Settings.Paths.GameTypeFile);
                    Items.LoadFromFile(MainFrm.Settings.Paths.GameTypeFile);
                    ItemIndex := Items.IndexOf(EditTree.Text[EditNode, EditColumn]);
                  end;
                end;

      qpeComboBoolean: //creates combo with boolean values preloaded
                begin
                  CreateCombo();
                  with FEdit as TComboBox do
                  begin
                    Items.Add(J_TRUE);
                    Items.Add(J_FALSE);
                    ItemIndex := Items.IndexOf(EditTree.Text[EditNode, EditColumn]);
                  end;
                end;

      qpeCustom:      //calls DoCustomPrepare and loads whatever it finds.}
                DoCustomPrepare();

      qpeFileEdit:    //creates the filename select thing.
                begin
                  CreateFileEdit();
                  TJvFilenameEdit(FEdit).FileName := EditTree.Text[EditNode, EditColumn];
                  TJvFilenameEdit(FEdit).InitialDir := ExtractFilePath(EditTree.Text[EditNode, EditColumn]);
                end;

      qpeFileExeEdit:    //creates the filename select thing.
                begin
                  CreateFileEdit();
                  TJvFilenameEdit(FEdit).FileName := EditTree.Text[EditNode, EditColumn];
                  TJvFilenameEdit(FEdit).InitialDir := ExtractFilePath(EditTree.Text[EditNode, EditColumn]);
                  TJvFilenameEdit(FEdit).Filter := 'Executable Files (*.exe,*.bat,*.com)|*.exe;*.bat;*.com|All Files|*.*';
                end;

      qpeDirectoryEdit:    //creates the Directory select thing.
                begin
                  CreateDirectoryEdit();
                  TJvDirectoryEdit(FEdit).Text := EditTree.Text[EditNode, EditColumn];
                  TJvDirectoryEdit(FEdit).InitialDir := EditTree.Text[EditNode, EditColumn];
                end;

      qpeROMParamMode: //creates combo with rom parameter types added
                begin
                  CreateCombo();
                  with FEdit as TComboBox do
                  begin
                    Items.Add(QP_ROM_PARAM_AFTER);
                    Items.Add(QP_ROM_PARAM_OVERWRITE);
                    Items.Add(QP_ROM_PARAM_BEFORE);
                    Items.Add(QP_ROM_PARAM_AFTER_NOSPACE);
                    Items.Add(QP_ROM_PARAM_BEFORE_NOSPACE);
                    ItemIndex := Items.IndexOf(EditTree.Text[EditNode, EditColumn]);
                  end;
                end;

      qpePowerSchemes:
                begin
                  CreateCombo();
                  with FEdit as TComboBox do
                  begin
                    Pwr := TStringList.Create;
                    try
                      ujPowerSchemes.PowerSchemesToStrings(Pwr);
                      Items.Add(QP_USE_GENERAL_SETTING);
                      Items.Add(QP_DONT_CHANGE);
                      Items.AddStrings(Pwr);
                      ItemIndex := Items.IndexOf(EditTree.Text[EditNode, EditColumn]);
                    finally
                      FreeAndNil(Pwr);
                    end;
                  end;
                end;

      qpeExtractDest:
                begin
                  CreateCombo();
                  with FEdit as TComboBox do
                  begin
                    Items.Add(QP_EXTRACT_ROM_DIR);
                    Items.Add(QP_EXTRACT_QP_TEMP);
                    Items.Add(QP_EXTRACT_SYS_TEMP);
                    Items.Add(QP_EXTRACT_GENERAL);
                    ItemIndex := Items.IndexOf(EditTree.Text[EditNode, EditColumn]);
                  end;
                end;

      qpePriority:
                begin
                  CreateCombo();
                  with FEdit as TComboBox do
                  begin
                    pri := TStringList.Create;
                    Try
                      ujProcesses.GetAllPriorityStrings(pri);
                      Items.AddStrings(Pri);
                    finally
                      FreeAndNil(Pri);
                    end;
                    ItemIndex := Items.IndexOf(EditTree.Text[EditNode, EditColumn]);
                  end;
                end;
                
    end; //end of case statement.

    NodeRect := Tree.GetDisplayRect(Node, Column, False, False);
    Edit.Top := NodeRect.Top;
    Edit.Left := NodeRect.Left;
    Edit.Width := NodeRect.Right - NodeRect.Left;
    Edit.Height := 100;
end;

procedure TQPVTEdit.ProcessMessage(var Message: TMessage);
begin
  Edit.WindowProc(Message);
end;

procedure TQPVTEdit.SetBounds(R: TRect);
begin
  Edit.BoundsRect := R
end;


end.
