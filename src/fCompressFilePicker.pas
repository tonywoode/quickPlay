unit fCompressFilePicker;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, VirtualTrees, fjWinFontForm;

type
  TFrmCompressPicker = class(TJWinFontForm)
    lblCaption: TLabel;
    VTFiles: TVirtualStringTree;
    BtnOK: TButton;
    BtnCancel: TButton;
    procedure VTFilesKeyDown(Sender: TObject; var Key: Word;
      Shift: TShiftState);
    procedure VTFilesDblClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure VTFilesGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure BtnOKClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
  private
    { Private declarations }
    _MiniOnFree : Boolean;
    _SelectedIndex : Integer;
    _FileList : TStringList;
    _FileName : String;
    procedure SetFormCaption(Value : String);
    Function GetSelectedFile(): String;
    procedure ReadLastSelected();
    procedure SaveLastSelected();
  public
    { Public declarations }
    Property FormCaption : String write SetFormCaption;
    Property SelectedIndex : Integer read _SelectedIndex;
    Property SelectedFileName : String read GetSelectedFile;
    Property ArchiveName : String read _FileName write _FileName;
    Procedure addFiles(inFiles : TStrings);
  end;

var
  FrmCompressPicker: TFrmCompressPicker;

implementation

uses ujMiscResourceStrs, fMain;

{$R *.dfm}

{-----------------------------------------------------------------------------}

Procedure TFrmCompressPicker.addFiles(inFiles : TStrings);
begin
  _FileList.Assign(inFiles);
  VTFiles.RootNodeCount := _FileList.Count;
end;

{-----------------------------------------------------------------------------}

Function TFrmCompressPicker.GetSelectedFile(): String;
begin
  if _SelectedIndex <> -1 then
    Result := _FileList[_SelectedIndex]
  else
    Result := '';
end;

{-----------------------------------------------------------------------------}

procedure TFrmCompressPicker.ReadLastSelected;
var
  LastStrs : TStringList;
  DBFile : String;
  LastFile : String;
  NewIndex : Integer;
  aNode : PVirtualNode;
  found : Boolean;
begin
  //reads the last selected ROM inside this archive from the database file.
  LastStrs := TStringList.Create;
  try
    DBFile := MainFrm.Settings.Paths.CfgDir + 'ArchivePickerDB.dat';

    NewIndex := -1;
    
    if (_FileName <> '') and (FileExists(DBFile)) then
    begin

      LastStrs.LoadFromFile(DBFile);
      LastFile := LastStrs.Values[_FileName];

      NewIndex := _FileList.IndexOf(LastFile);
    end;

    if NewIndex <> -1 then
    begin
      aNode := VTFiles.GetFirst;
      Found := False;
      while (aNode <> nil) or (Found = False) do
      begin
        if (aNode.Index = NewIndex) then
        begin
          VTFiles.Selected[aNode] := True;
          VTFiles.FocusedNode := aNode;
          Found := True;
        end;
        aNode := VTFiles.GetNext(aNode);
      end;
    end
    else
    begin
      VTFiles.Selected[VTFiles.GetFirst] := True;
      VTFiles.FocusedNode := VTFiles.GetFirst;
    end;
    
  finally
    FreeAndNil(LastStrs);
  end;  
end;

{-----------------------------------------------------------------------------}

procedure TFrmCompressPicker.SaveLastSelected;
var
  lastStrs : TStringList;
  DBFile : String;
begin
  DBFile := MainFrm.Settings.Paths.CfgDir + 'ArchivePickerDB.dat';

  //only save the last selected if the archive filename is passed in.
  if _FileName = '' then
    exit;

  lastStrs := TStringList.Create;
  try

    if FileExists(DBFile) then
    begin
      LastStrs.LoadFromFile(DBFile);
    end;

    LastStrs.Values[_FileName] := _FileList[_SelectedIndex];
    LastStrs.SaveToFile(DBFile);
  finally
    FreeAndNil(lastStrs);
  end;
end;

{-----------------------------------------------------------------------------}

Procedure TFrmCompressPicker.SetFormCaption(Value : String);
begin
  lblCaption.Caption := Value;
end;

{-----------------------------------------------------------------------------}

procedure TFrmCompressPicker.FormCreate(Sender: TObject);
begin
  _SelectedIndex := -1;
  _FileList := TStringList.Create;
  _minionFree := False;
end;

{-----------------------------------------------------------------------------}

procedure TFrmCompressPicker.FormDestroy(Sender: TObject);
begin
  if _MiniOnFree then
    MainFrm.MinimiseQP();
  FreeAndNil(_FileList);
end;

{-----------------------------------------------------------------------------}

procedure TFrmCompressPicker.VTFilesDblClick(Sender: TObject);
begin
  if VTFiles.FocusedNode <> nil then
  begin
    _SelectedIndex := VTFiles.FocusedNode.Index;
    SaveLastSelected();
    ModalResult := mrOK;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmCompressPicker.VTFilesGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin
  if Node <> nil then
    CellText := _FileList[Node.index];
end;

{-----------------------------------------------------------------------------}

procedure TFrmCompressPicker.VTFilesKeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
  if key = VK_Return then
    BtnOK.Click;
end;

{-----------------------------------------------------------------------------}

procedure TFrmCompressPicker.BtnOKClick(Sender: TObject);
begin
  if VTFiles.SelectedCount = 1 then
  begin
    _SelectedIndex := VTFiles.GetFirstSelected.Index;
  end;

  //if its still -1 then no node was selected, complain!
  if _SelectedIndex = -1 then
  begin
    MessageDlg(J_FILE_NOT_SELECTED, mtError, [mbOK], 0);
    ModalResult := mrNone;
  end
  else
  begin
    SaveLastSelected();
  end;

end;

{-----------------------------------------------------------------------------}

procedure TFrmCompressPicker.FormShow(Sender: TObject);
begin
  if MainFrm.jvTray.Active then
  begin
    MainFrm.RestoreQP();
    _MiniOnFree := True;
    ReadLastSelected();
    VTFiles.SetFocus;
  end;
end;

{-----------------------------------------------------------------------------}

end.
