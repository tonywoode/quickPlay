unit fCustomRomData;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ComCtrls, StdCtrls, VirtualTrees, Mask, JvExMask, JvToolEdit,
  fjWinFontForm;

type
  TFrmROMData = class(TJWinFontForm)
    PGCustom: TPageControl;
    lblTitle: TLabel;
    TabIntro: TTabSheet;
    RadImport: TRadioButton;
    RadExport: TRadioButton;
    lblDescription: TLabel;
    BtnBegin: TButton;
    TabWork: TTabSheet;
    TabDone: TTabSheet;
    VTOpt: TVirtualStringTree;
    lblWork: TLabel;
    ChkOverwrite: TCheckBox;
    BtnClose: TButton;
    lblDataFile: TLabel;
    lblDone: TLabel;
    lblDataOpt: TLabel;
    BtnStartWork: TButton;
    OpenDlg: TOpenDialog;
    lblEnd: TLabel;
    TxtDataFile: TJvFilenameEdit;
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure VTOptGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure BtnBeginClick(Sender: TObject);
    procedure VTOptInitNode(Sender: TBaseVirtualTree; ParentNode,
      Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
    procedure BtnStartWorkClick(Sender: TObject);
    procedure TxtDataFileButtonClick(Sender: TObject);
  private
    { Private declarations }
    _Options : TStringList;
    _ImportMode : Boolean;
  public
    { Public declarations }
  end;

implementation

uses uJUtilities, fMain, uQPConst, ujMiscResourceStrs;

{$R *.dfm}

procedure TFrmROMData.FormCreate(Sender: TObject);
var
  i : Integer;
begin
  //turn off all the silly tabs
  for i := 0 to PgCustom.PageCount-1 do
    PgCustom.Pages[i].TabVisible := False;

  //set the active page index.
  pgCustom.ActivePageIndex := 0;

  //Create the options stringlist
  _Options := TStringList.Create;

  //add all the options.
  _Options.Add(QP_ROM_NAME);
  _Options.Add(QP_ROM_COMPANY);
  _Options.Add(QP_ROM_LANG);
  _Options.Add(QP_ROM_RATING);
  _Options.Add(QP_ROM_TYPE);
  _Options.Add(QP_ROM_YEAR);
  _Options.Add(QP_ROM_PLAYERS);
  _Options.Add(QP_ROM_COMMENT);
end;

procedure TFrmROMData.FormDestroy(Sender: TObject);
begin
  //free the options list
  FreeAndNil(_Options);
end;

procedure TFrmROMData.VTOptGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin
  CellText := _Options[Node.Index];
end;

procedure TFrmROMData.BtnBeginClick(Sender: TObject);
begin
  if RadExport.Checked or RadImport.Checked then
  begin

    if RadExport.Checked then
    begin
      //put the form into export mode.
      lblWork.Caption := QP_CUSTOM_EXPORT;
      _ImportMode := False;
    end
    else
    begin
      //put the form into import mode.
      lblWork.Caption := QP_CUSTOM_IMPORT;
      _ImportMode := True;
      ChkOverWrite.Visible := True;
    end;

    //move to the next 'page'
    pgCustom.ActivePageIndex := 1;

  end
  else
    MessageDlg(QP_CUSTOM_SELECT, mtError, [mbOK], 0);
    
end;

procedure TFrmROMData.VTOptInitNode(Sender: TBaseVirtualTree; ParentNode,
  Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
begin
  Sender.CheckType[Node] := ctCheckBox;
  Sender.CheckState[Node] := csCheckedNormal;
end;

procedure TFrmROMData.BtnStartWorkClick(Sender: TObject);
var
  IncName, IncRating, IncCompany, IncLang, IncYear, IncType, IncPlayers, IncComment : Boolean;
  aNode : PVirtualNode;
  OldCursor : TCursor;
begin

  if TxtDataFile.Text <> '' then
  begin

    OldCursor := Screen.Cursor;
    Screen.Cursor := crHourGlass;
    try

    //do some damn butt ugly code to get checked states in the VT.
    aNode := VTOpt.GetFirst;
    if VTOpt.CheckState[aNode] = csCheckedNormal then
      IncName := True
    else
      IncName := False;

    aNode := VTOpt.GetFirst;
    if VTOpt.CheckState[aNode] = csCheckedNormal then
      IncCompany := True
    else
      IncCompany := False;

    aNode := VTOpt.GetNext(aNode);
    if VTOpt.CheckState[aNode] = csCheckedNormal then
      IncLang := True
    else
      IncLang := False;

    aNode := VTOpt.GetNext(aNode);
    if VTOpt.CheckState[aNode] = csCheckedNormal then
      IncRating := True
    else
      IncRating := False;

    aNode := VTOpt.GetNext(aNode);
    if VTOpt.CheckState[aNode] = csCheckedNormal then
      IncType := True
    else
      IncType := False;
      
    aNode := VTOpt.GetNext(aNode);
    if VTOpt.CheckState[aNode] = csCheckedNormal then
      IncYear := True
    else
      IncYear := False;

    aNode := VTOpt.GetNext(aNode);
    if VTOpt.CheckState[aNode] = csCheckedNormal then
      IncPlayers := True
    else
      IncPlayers := False;

    aNode := VTOpt.GetNext(aNode);
    if VTOpt.CheckState[aNode] = csCheckedNormal then
      IncComment := True
    else
      IncComment := False;

    if _ImportMode then
    begin
      //import mode.
      MainFrm.RomList.ImportCustomData(TxtDataFile.Text, ChkOverWrite.Checked, IncName, IncCompany,
        IncType, IncLang, IncYear, IncRating, IncPlayers, IncComment);
      lblDone.Caption := QP_CUSTOM_IMPORT_COMPLETE;
      pgCustom.ActivePageIndex := 2;
    end
    else
    begin
      //export mode.
      //for the export mode we need to make sure that the directory exists that the file is going to.
      if DirectoryExists(ExtractFilePath(TxtDataFile.Text)) then
      begin
        MainFrm.RomList.ExportCustomData(TxtDatafile.Text, IncName, IncCompany, Inctype, IncLang,
          IncYear, IncRating, IncPlayers, IncComment);
        lblDone.Caption := QP_CUSTOM_EXPORT_COMPLETE;
        pgCustom.ActivePageIndex := 2;
      end
      else
        MessageDlg(QP_CUSTOM_BAD_DIR, mtError, [mbOK], 0);
    end;

    finally
      Screen.Cursor := OldCursor;
    end;
    
  end
  else
    MessageDlg(J_FILE_NOT_SELECTED, mtError, [mbOK], 0);
end;

procedure TFrmROMData.TxtDataFileButtonClick(Sender: TObject);
begin
  if _ImportMode then
    TxtDataFile.DialogKind := dkOpen
  else
    TxtDataFile.DialogKind := dkSave;
end;

end.
