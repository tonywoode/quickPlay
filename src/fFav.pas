unit fFav;

interface

uses
  Windows, SysUtils, Classes, Controls, Forms,
  StdCtrls, ExtCtrls, Buttons, VirtualTrees, activeX, uQPVTEditor,
  fjWinFontForm;

type

  TFavForm = class(TJWinFontForm)
    VTFav: TVirtualStringTree;
    BtnMoveUp: TButton;
    BtnMoveDown: TButton;
    BtnDel: TButton;
    BtnOK: TButton;
    BtnCancel: TButton;
    procedure FormShow(Sender: TObject);
    procedure BtnDelClick(Sender: TObject);
    procedure VTFavGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure VTFavKeyDown(Sender: TObject; var Key: Word;
      Shift: TShiftState);
    procedure VTFavDragDrop(Sender: TBaseVirtualTree; Source: TObject;
      DataObject: IDataObject; Formats: TFormatArray; Shift: TShiftState;
      Pt: TPoint; var Effect: Integer; Mode: TDropMode);
    procedure VTFavDragOver(Sender: TBaseVirtualTree; Source: TObject;
      Shift: TShiftState; State: TDragState; Pt: TPoint; Mode: TDropMode;
      var Effect: Integer; var Accept: Boolean);
    procedure BtnMoveUpClick(Sender: TObject);
    procedure BtnMoveDownClick(Sender: TObject);
    procedure VTFavFreeNode(Sender: TBaseVirtualTree; Node: PVirtualNode);
    procedure VTFavCreateEditor(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex; out EditLink: IVTEditLink);
    procedure VTFavNewText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; NewText: WideString);
    procedure VTFavEditing(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; var Allowed: Boolean);
    procedure VTFavFocusChanged(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex);
    procedure VTFavExit(Sender: TObject);
  private
    { Private declarations }
    procedure FillFav();
  public
    { Public declarations }
  end;

implementation

uses fMain, uJUtilities,  uJVirtualTree, uEmuList, uRom, uQPMiscTypes;

{$R *.DFM}

{-----------------------------------------------------------------------------}
{TFavForm}
{-----------------------------------------------------------------------------}

procedure TFavForm.fillfav();
Var
  Node : PVirtualNode;
begin

  With MainFrm Do
  Begin

    VTfav.RootNodeCount := FavList.Count;

    Node := VTfav.GetFirst;
    while Node <> nil do
    begin
      SetObject(VTfav, Node, FavList.Items[Node.Index]);
      Node := VTFav.GetNextSibling(Node);
    end;
                                 
  end;

end;


{-----------------------------------------------------------------------------}

procedure TFavForm.FormShow(Sender: TObject);
begin
  //set up the size of our VT
  VTFav.NodeDataSize := SizeOf(Pointer);

  FillFav;
end;                    

{-----------------------------------------------------------------------------}

procedure TFavForm.BtnDelClick(Sender: TObject);
begin
  if VTFav.SelectedCount = 1 then
  begin

    VTFav.CancelEditNode();

    MainFrm.FavList.Delete(VTFav.GetFirstSelected.Index);

    fillfav;

  end;
end;

{-----------------------------------------------------------------------------}

procedure TFavForm.BtnMoveUpClick(Sender: TObject);
begin
  If (VTFav.GetFirstSelected <> nil) and (VTFav.GetFirstSelected <> VTFav.GetFirst) then
  begin
    VTFav.EndEditNode();
    MainFrm.FavList.MoveTo(VTFav.GetFirstSelected.Index, VTFav.GetFirstSelected.Index-1);
    VTFav.MoveTo(VTFav.GetFirstSelected, vtFav.GetPreviousSibling(VTFav.GetFirstSelected), amInsertBefore, false);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFavForm.BtnMoveDownClick(Sender: TObject);
begin
  If (VTFav.GetFirstSelected <> nil) and (VTFav.GetFirstSelected <> VTFav.GetLast()) then
  begin
    VTFav.EndEditNode();
    MainFrm.FavList.MoveTo(VTFav.GetFirstSelected.Index, VTFav.GetFirstSelected.Index+1);
    VTFav.MoveTo(VTFav.GetFirstSelected, vtFav.GetNextSibling(VTFav.GetFirstSelected), amInsertAfter, false);
  end;
end;


{-----------------------------------------------------------------------------}

{                 start of VTfav Code                             }

procedure TFavForm.VTFavGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
Var
  CurFav : TQPRom;
begin

    CurFav := TQPRom(GetObject(VTFav, Node));

    case Column of
      0: CellText := CurFav.name;

      1: CellText := CurFav.path;

      2: CellText := CurFav.emulator;
    end;

end;

{-----------------------------------------------------------------------------}

procedure TFavForm.VTFavKeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin

  if (key = VK_delete) and (VTfav.GetFirstSelected <> nil) then
  begin
    //MainFrm.Favourites.FavDelOne((VTfav.GetFirstSelected.index), True);
    FillFav;
  end;
  
end;

{-----------------------------------------------------------------------------}

procedure TFavForm.VTFavDragDrop(Sender: TBaseVirtualTree; Source: TObject;
  DataObject: IDataObject; Formats: TFormatArray; Shift: TShiftState;
  Pt: TPoint; var Effect: Integer; Mode: TDropMode);
var
  Nodes: TNodeArray;
  I: Integer;
  AttachMode : TVTNodeAttachMode;
begin
  Nodes := nil;

  if DataObject = nil then
  begin
    // VCL drag'n drop. 
    if Source = VTfav then
    begin

      if Sender.DropTargetNode = nil then
        exit;
        
      case Mode of
      dmAbove:
        AttachMode := amInsertBefore;
      dmOnNode:
        AttachMode := amInsertAfter;
      dmBelow:
        AttachMode := amInsertAfter;
      else
        if Assigned(Source) and (Source is TBaseVirtualTree) and (Sender <> Source) then
          AttachMode := amInsertBefore
        else
          AttachMode := amNowhere;
      end;

      // Since we know this is a Virtual Treeview we can ignore the drop event entirely and use VT mechanisms.
      Effect := DROPEFFECT_MOVE;
      Nodes := VTfav.GetSortedSelection(True);
      for I := 0 to High(Nodes) do
      Begin
        MainFrm.FavList.MoveTo(Nodes[i].Index, Sender.DropTargetNode.Index);
        VTFav.MoveTo(Nodes[i], Sender.DropTargetNode, AttachMode, False);
      end;
      
    end;
  end;

end;

{-----------------------------------------------------------------------------}

procedure TFavForm.VTFavDragOver(Sender: TBaseVirtualTree; Source: TObject;
  Shift: TShiftState; State: TDragState; Pt: TPoint; Mode: TDropMode;
  var Effect: Integer; var Accept: Boolean);
begin
  if Source = VTfav then
    Accept := True;
end;

procedure TFavForm.VTFavFreeNode(Sender: TBaseVirtualTree;
  Node: PVirtualNode);
begin
  SetObject(Sender, Node, nil);
end;

procedure TFavForm.VTFavCreateEditor(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; out EditLink: IVTEditLink);
begin
  case Column of
      0 : EditLink := TQPVTEdit.Create(qpeEdit);
      1 : EditLink := TQPVTEdit.Create(qpeEdit);
      2 : EditLink := TQPVTEdit.Create(qpeComboEmu);
  end;
end;

procedure TFavForm.VTFavNewText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; NewText: WideString);
begin
  If (Node <> nil) and (NewText <> '') then
  begin
    case Column of
      0 : TQPROM(GetObject(Sender, Node)).Name := NewText;
      1 : TQPROM(GetObject(Sender, Node)).Path := NewText;
      2 : TQPROM(GetObject(Sender, Node)).Emulator := NewText;
    end;
  end;
end;

procedure TFavForm.VTFavEditing(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; var Allowed: Boolean);
begin
  Allowed := True;
end;

procedure TFavForm.VTFavFocusChanged(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex);
begin
  If (Node <> nil) then
    VTFav.EditNode(Node, Column);
end;

procedure TFavForm.VTFavExit(Sender: TObject);
begin
  if VTFav.IsEditing then
    VTFav.EndEditNode;
end;

end.
