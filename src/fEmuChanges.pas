unit fEmuChanges;

interface

uses
  Windows, SysUtils, Classes, Controls, Forms, Graphics,
  VirtualTrees, StdCtrls, Contnrs, fJWinFontForm;

type

  TQPChange = class
  private
    FDescription : String; //the text to appear in the VT
    FChecked : Boolean; //whether to check the option or not
    FFuncType : Integer; // 1- for a rename, 2-for a delete emu
    FNewName : String; //the new name of the emulator - and name for emu delete
    FOldName : String; //the previous name of the emulator.
  published
    Property Description : String Read FDescription Write FDescription;
    Property Checked : Boolean Read FChecked Write FChecked;
    Property FuncType : Integer Read FFuncType Write FFuncType;
    Property NewName : String Read FNewName Write FNewName;
    Property OldName : String Read FOldName Write FOldName;
    constructor create(Txt : string; Checked : Boolean; FuncType : Integer; NewName, OldName : String);overload;
  end;

  TEmuChangeFrm = class(TJWinFontForm)
    VTChanges: TVirtualStringTree;
    BtnOK: TButton;
    lblDescription: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure BtnOKClick(Sender: TObject);
    procedure VTChangesGetText(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure VTChangesPaintText(Sender: TBaseVirtualTree;
      const TargetCanvas: TCanvas; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType);
    procedure VTChangesFreeNode(Sender: TBaseVirtualTree;
      Node: PVirtualNode);
  private
    { Private declarations }
  public
    { Public declarations }
    ChangeList : TObjectList;
  end;

implementation

uses uJVirtualTree;

{$R *.dfm}

{ TQPChange }

constructor TQPChange.create(Txt: string; Checked: Boolean;
  FuncType: Integer; NewName, OldName: String);
begin
  FDescription := Txt;
  FChecked := Checked;
  FFuncType := FuncType;
  FNewName := NewName;
  FOldName := OldName;
end;

procedure TEmuChangeFrm.FormCreate(Sender: TObject);
begin
  //set the data size for the virtual treeview
  VTChanges.NodeDataSize := SizeOf(Pointer);

  //create the object list
  ChangeList := TObjectList.Create(True);
end;

procedure TEmuChangeFrm.FormShow(Sender: TObject);
var
  aNode : PVirtualNode;
begin
  //fill the treeview with the current amount of changes

  VTChanges.BeginUpdate;
  try

    VTChanges.RootNodeCount := ChangeList.Count;

    aNode := VTChanges.GetFirst;
    while aNode <> nil do
    Begin
      SetObject(VTChanges, aNode, ChangeList.Items[aNode.Index]);
      VTChanges.CheckType[aNode] := ctCheckBox;
      
      If TQPChange(ChangeList.Items[aNode.Index]).Checked then
        VTChanges.CheckState[aNode] := csCheckedNormal
      else
        VTChanges.CheckState[aNode] := csUnCheckedNormal;

      aNode := VTChanges.GetNextSibling(aNode);
    End;

  finally
    VTChanges.EndUpdate;
  end;

end;

procedure TEmuChangeFrm.BtnOKClick(Sender: TObject);
var
  aNode : PVirtualNode;
begin
  //set the objectlist changes to match their checked status in VT
  aNode := VTChanges.GetFirst;
  While aNode <> nil do
  begin

    if VTChanges.CheckState[aNode] = csCheckedNormal then
      TQPChange(GetObject(VTChanges, aNode)).Checked := true
    else
      TQPChange(GetObject(VTChanges, aNode)).Checked := false;
      
    aNode := VTChanges.GetNextSibling(aNode);
  end;
end;

procedure TEmuChangeFrm.VTChangesGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin

  CellText := TQPChange(GetObject(Sender, Node)).Description;
end;

procedure TEmuChangeFrm.VTChangesPaintText(Sender: TBaseVirtualTree;
  const TargetCanvas: TCanvas; Node: PVirtualNode; Column: TColumnIndex;
  TextType: TVSTTextType);
begin

  case TQPChange(GetObject(Sender, Node)).FuncType of
  1: TargetCanvas.Font.Color := ClBlue;
  2: TargetCanvas.Font.Color := clRed;
  end;

end;

procedure TEmuChangeFrm.VTChangesFreeNode(Sender: TBaseVirtualTree;
  Node: PVirtualNode);
begin
  SetObject(Sender, Node, Nil);
end;

end.
