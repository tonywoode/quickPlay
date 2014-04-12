{
  This form consists of a VirtualTreeView and is used to edit
  which columns on the MainFrm are visible.  At the minute it is
  linked to the MainFrm quite closely, however it could (with a small
  amount of effort) be changed to work with ANY VT in the application,
  but this isnt really needed - maybe useful for other projects though.
}       

unit fColumns;

interface

uses
  Windows, SysUtils, Classes, Controls, Forms, StdCtrls, VirtualTrees,
  fjWinFontForm;

type
  TFrmColumn = class(TjWinFontForm)
    BtnOK: TButton;
    BtnCancel: TButton;
    VTCol: TVirtualStringTree;
    BtnReset: TButton;
    procedure FormShow(Sender: TObject);
    procedure BtnOKClick(Sender: TObject);
    procedure VTColInitNode(Sender: TBaseVirtualTree; ParentNode,
      Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
    procedure VTColGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure BtnResetClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

implementation

uses fMain, IniFiles;

{$R *.dfm}

procedure TFrmColumn.FormShow(Sender: TObject);
begin

    VTCol.RootNodeCount := MainFrm.VTRoms.Header.Columns.Count;

end;

procedure TFrmColumn.BtnOKClick(Sender: TObject);
Var
  Ini : TMemIniFile;
  aNode : PVirtualNode;
  Directory : String;
begin

  Directory := MainFrm.GetSelectedFolder;

  //check we have a valid directory.
  If Directory = '' then
    exit;

  Ini := TMemIniFile.Create(Directory + 'folders.ini');
  Try

    Ini.EraseSection('ColView');

    aNode := VTcol.GetFirst;
    while aNode <> nil do
    begin
      If VTCol.CheckState[aNode] = csCheckedNormal then
        Ini.WriteBool('ColView', IntToStr(aNode.Index), True)
      else
        Ini.WriteBool('ColView', IntToStr(aNode.Index), false);
      aNode := VTcol.GetNext(aNode);
    end;

    if MainFrm.Settings.AllowWrite then
      Ini.UpdateFile;

    //call the procedure to hide or show the column headings.
    MainFrm.Settings.HideShowCol(MainFrm.GetSelectedFolder);

  Finally
    FreeAndNil(Ini);
  end;

end;

procedure TFrmColumn.VTColInitNode(Sender: TBaseVirtualTree; ParentNode,
  Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
begin
  VTCol.CheckType[Node] := ctCheckBox;
  If MainFrm.VTRoms.Header.Columns.Items[Node.Index].Options >= [coVisible] then
    VTCol.CheckState[Node] := csCheckedNormal;
end;

procedure TFrmColumn.VTColGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin
  CellText := MainFrm.VTRoms.Header.Columns.Items[Node.Index].Text;
end;

procedure TFrmColumn.BtnResetClick(Sender: TObject);
Var
  Ini : TMemIniFile;
  Directory : String;
begin

  Directory := MainFrm.GetSelectedFolder;

  //check we have a valid directory.
  If Directory = '' then
    exit;

  Ini := TMemIniFile.Create(Directory + 'folders.ini');
  Try

    Ini.EraseSection('ColView');

    if MainFrm.Settings.AllowWrite then
      Ini.UpdateFile;

    //call the procedure to hide or show the column headings.
    MainFrm.Settings.HideShowCol(MainFrm.GetSelectedFolder);

  Finally
    FreeAndNil(Ini);
  end;
  ModalResult := MrOK;
end;

end.



