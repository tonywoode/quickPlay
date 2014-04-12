unit fRomProperties;
        
interface

uses
  Windows, SysUtils, Classes, Controls, Forms, VirtualTrees, Graphics,  
  Dialogs, StdCtrls, Buttons, Grids, ValEdit, uRomList, uRom, ComCtrls, Contnrs,
  JvExStdCtrls, JvButton, JvCtrls, fJWinFontForm;

type
  TFrmRomProp = class(TJWinFontForm)
    BtnOK: TButton;
    BtnCancel: TButton;
    pgProp: TPageControl;
    TabIPS: TTabSheet;
    TabFile: TTabSheet;
    LstContent: TListBox;
    lblValid: TLabel;
    lblIsArchive: TLabel;
    lblFileSize: TLabel;
    LblExist: TLabel;
    BtnPrevious: TButton;
    BtnNext: TButton;
    TabProperties: TTabSheet;
    VTData: TVirtualStringTree;
    VTIPS: TVirtualStringTree;
    BtnIPSAdd: TJvImgBtn;
    BtnIPSDelete: TJvImgBtn;
    BtnIPSinvalid: TJvImgBtn;
    procedure VTDataFocusChanged(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex);
    procedure FormShow(Sender: TObject);
    procedure BtnOKClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure BtnNextClick(Sender: TObject);
    procedure BtnPreviousClick(Sender: TObject);
    procedure VTDataEditing(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; var Allowed: Boolean);
    procedure VTDataGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure VTDataCreateEditor(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex; out EditLink: IVTEditLink);
    procedure VTDataNewText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; NewText: WideString);
    procedure FormDestroy(Sender: TObject);
    procedure VTIPSGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure VTIPSInitNode(Sender: TBaseVirtualTree; ParentNode,
      Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
    procedure VTIPSEditing(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; var Allowed: Boolean);
    procedure VTIPSCreateEditor(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex; out EditLink: IVTEditLink);
    procedure VTIPSFocusChanged(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex);
    procedure VTIPSNewText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; NewText: WideString);
    procedure BtnIPSAddClick(Sender: TObject);
    procedure BtnIPSinvalidClick(Sender: TObject);
    procedure BtnIPSDeleteClick(Sender: TObject);
    procedure VTIPSChecked(Sender: TBaseVirtualTree; Node: PVirtualNode);
    procedure VTDataPaintText(Sender: TBaseVirtualTree;
      const TargetCanvas: TCanvas; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType);
  private
    { Private declarations }
    _ROM : TQPROM;
    _ROMref : TQProm;
    _Changed : Boolean;
    Procedure Init;
    procedure EditROM();
    procedure Move(GoForward : Boolean);
    procedure SetROM(value : TQPROM);
  public
    { Public declarations }
    Selected : TObjectList;
    Multi : Boolean;
    cNode : PVirtualNode;

    Property ROM : TQPROM read _ROMref write SetROM;
  end;

implementation

uses JCLFileUtils, JCLStrings,
     fMain, uJUtilities, uEmuList, fIPS, uQPVTEditor, uQPConst,
     uQPCompObj, ujCompression, ujMiscResourceStrs, uQPMiscTypes;

{$R *.dfm}

{ TFrmRomProp }

{------------------------------------------------------------------------------}

procedure TFrmRomProp.SetROM(value : TQPROM);
begin
  _ROMref := value;
  _ROM.Assign(_ROMref);
  _Changed := False;
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.EditROM();
begin

  //if the tree is still editing, stop it
  if VTData.IsEditing then
    VTData.EndEditNode; 

  if (FileExists(_ROM.Path) = false) and (DirectoryExists(ExtractFilePath(_ROM.Path)) = false) then
    raise EJException.Create(QP_ROM_NOT_FOUND);

  //assign the internal ROM data to the original one.
  _ROMref.Assign(_ROM);
  
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.Init;
Var
  TmpList : TStrings;
  aNode : PVirtualNode;
begin
  with MainFrm do
  Begin  
  //Start filling the data for the roms.

  If Multi then
  begin //start of multiple selected roms

    //first of all disable the next and back buttons
    BtnNext.Enabled := False;
    BtnPrevious.Enabled := False;

    //now set up our internal _ROM object to 'unchanged' values
    _ROM.Emulator := QP_UNCHANGED;
    _ROM.Language := QP_UNCHANGED;
    _ROM.Rating := QP_UNCHANGED;
    _ROM.GameType := QP_UNCHANGED;
    _ROM.Multiplayer := QP_UNCHANGED;
    _ROM.Company := QP_UNCHANGED;
    // Added more properties BugRef:0000081
    _ROM.Year := QP_UNCHANGED;
    _ROM.Parameters := QP_UNCHANGED;
    _ROM.Comment := QP_UNCHANGED;

    //now hide the nodes we arent interested in.
    aNode := VTData.GetFirst;
    While aNode <> nil do
    begin
      if aNode.Index in [0, 1, 10] then
        VTData.IsVisible[aNode] := False;
      aNode := VTData.GetNext(aNode);
    end;
    
  end //end of multiple selected roms

  else

  begin //start of single selected rom

    //IPS data
    VTIPS.Clear;
    if _ROM.IPSCount > 0 then
      VTIPS.RootNodeCount := _ROM.IPSCount+1;

    // file values
    if FileExists(_ROM.path) then
    begin
      LblExist.Caption := J_YES;

      lblFileSize.Caption := IntToStr(GetSizeOfFile(_ROM.path))+' bytes';

      if uQPCompObj.Compression.SupportsFileName(_ROM.Path, cmRead) then
      Begin
        LblIsArchive.Caption := J_YES;

        if uQPCompObj.Compression.VerifyFile(_ROM.Path) then
        begin
          LblValid.Caption := J_YES;
          With MainFrm do
          begin

            TmpList := TStringList.Create;
            try
              uQPCompObj.Compression.ListContentsOfFile(tmpList, _ROM.Path);
              LstContent.Items.AddStrings(TmpList);
            Finally
              FreeAndNil(TmpList);
            end;

          end;  //end of WITH MainFrm
        end //end of Verifyarchive
        else
          LblValid.Caption := J_NO;

      end; //end of IS archive

    end;

  end; //end of single selected rom
  end; //end of WITH block
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.Move(GoForward : Boolean);
var
  DlgResult : Integer;
  aNode : PVirtualNode;
begin

  if VTData.IsEditing then
    VTData.EndEditNode;

  if VTIPS.IsEditing then
    VTIPS.EndEditNode;

  VTData.FocusedNode := Nil;

  if _Changed then
  begin
    DlgResult := MessageDlg(J_SAVE_CHANGES, mtConfirmation, [mbYes,mbNo,mbCancel], 0);
    if DlgResult = mrCancel then
    begin
      //Dont do anything, just result and exit;
      exit;
    end
    else if DlgResult = mrYes then
    begin
      EditROM();
      MainFrm.RomList.SaveToFile();
    end;

  end;

  //Move to the next ROM
  if GoForward then
    aNode := MainFrm.VTRoms.GetNextVisibleSibling(cNode)
  else
    aNode := MainFrm.VTRoms.GetPreviousVisibleSibling(cNode);

  if aNode <> nil then
  begin
    cNode := aNode;
    Self.ROM := MainFrm.GetROM(aNode);
    Init();
    VTData.Invalidate;
  end
  else
    //its at the end of the list.
    Raise EJException.Create(QP_ROMPROP_TOP);

end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.BtnOKClick(Sender: TObject);
Var
  I : Integer;
begin
  With MainFrm do
  Begin

  if VTData.IsEditing then
    VTData.EndEditNode;
  if VTIPS.IsEditing then
    VTIPS.EndEditNode;

  if Multi then
  Begin

    For I := 0 to Selected.Count-1 do
    Begin
        If JCLStrings.StrCompare(_ROM.Emulator, QP_UNCHANGED) <> 0 then
          TQPROM(Selected[I]).emulator := _ROM.Emulator;
        If JCLStrings.StrCompare(_ROM.GameType, QP_UNCHANGED) <> 0 then
          TQPROM(Selected[I]).GameType := _ROM.GameType;
        If JCLStrings.StrCompare(_ROM.Rating, QP_UNCHANGED) <> 0 then
          TQPROM(Selected[I]).Rating := _ROM.Rating;
        If JCLStrings.StrCompare(_ROM.Language, QP_UNCHANGED) <> 0 then
          TQPROM(Selected[I]).Language := _ROM.Language;
        If JCLStrings.StrCompare(_ROM.Company, QP_UNCHANGED) <> 0 then
          TQPROM(Selected[I]).Company := _ROM.Company;
        If JCLStrings.StrCompare(_ROM.Multiplayer, QP_UNCHANGED) <> 0 then
          TQPROM(Selected[I]).Company := _ROM.Multiplayer;
        if JCLStrings.StrCompare(_ROM.Year, QP_UNCHANGED) <> 0 then
          TQPROM(Selected[I]).Year := _ROM.Year;
        if JCLStrings.StrCompare(_ROM.Comment, QP_UNCHANGED) <> 0 then
          TQPROM(Selected[I]).Comment := _ROM.Comment;
        if JCLStrings.StrCompare(_ROM.Parameters, QP_UNCHANGED) <> 0 then
          TQPROM(Selected[I]).Parameters := _ROM.Comment;
    End;
  End

  Else //else its only one selected and we can edit its values

  Begin

    try
      EditROM();
    except
      on E: EJException do
      begin
        MessageDlg(E.Message, mtError, [mbOK], 0);
        exit;
      end;
    end;    
  End;
  
  ROMlist.SaveToFile();

  end;//end of WITH block

  ModalResult := MrOk;
  
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.FormCreate(Sender: TObject);
begin
  Selected := TObjectList.Create(False);
  _ROM := TQPROM.Create;
  pgProp.ActivePageIndex := 0;
  VTData.RootNodeCount := 12;
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.FormDestroy(Sender: TObject);
begin
  FreeAndNil(Selected);
  FreeAndNil(_ROM);
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.FormShow(Sender: TObject);
begin
  Init;
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.BtnNextClick(Sender: TObject);
begin
  try
    Move(True);
  except
    on e:EJException do MessageDlg(E.Message, mtError, [mbOK], 0);
  end;
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.BtnPreviousClick(Sender: TObject);
begin
  try
    Move(False);
  except
    on e:EJException do MessageDlg(E.Message, mtError, [mbOK], 0);
  end;
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.VTDataEditing(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; var Allowed: Boolean);
begin
  Allowed := (Column = 1);
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.VTDataGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin

  if TextType = ttNormal then
    case Column of
      0:  Case Node.Index of
            0: CellText := QP_ROM_NAME;
            1: CellText := QP_ROM_PATH;
            2: CellText := QP_ROM_EMU;
            3: CellText := QP_ROM_COMPANY;
            4: CellText := QP_ROM_YEAR;
            5: CellText := QP_ROM_LANG;
            6: CellText := QP_ROM_RATING;
            7: CellText := QP_ROM_TYPE;
            8: CellText := QP_ROM_PLAYERS;
            9: CellText := QP_ROM_PARAM;
            10: CellText := QP_ROM_OVERRIDE_PARAM;
            11: CellText := QP_ROM_COMMENT;
          end;

      1:  Case Node.Index of
            0 : CellText := _ROM.Name;
            1 : CellText := _ROM.Path;
            2 : CellText := _ROM.Emulator;
            3 : CellText := _ROM.Company;
            4 : CellText := _ROM.Year;
            5 : CellText := _ROM.Language;
            6 : CellText := _ROM.Rating;
            7 : CellText := _ROM.GameType;
            8 : CellText := _ROM.Multiplayer;
            9 : CellText := _ROM.Parameters;
            10 : CellText := uQPMiscTypes.ROMParametersStrings[_ROM.ParameterMode];
            11 : CellText := _ROM.Comment;
          end;
    end;
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.VTDataCreateEditor(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; out EditLink: IVTEditLink);
begin
  Case Node.Index of
    0: EditLink := TQPVTEdit.Create(qpeEdit);
    1:  begin
          //the path can either be a directory or a filename.
          if ExtractFileName(_ROM.Path) <> '' then
            EditLink := TQPVTEdit.Create(qpeFileEdit)
          else
            EditLink := TQPVTEdit.Create(qpeDirectoryEdit)
        end;
    2: EditLink := TQPVTEdit.Create(qpeComboEmu);
    3: EditLink := TQPVTEdit.Create(qpeEdit);
    4: EditLink := TQPVTEdit.Create(qpeEdit);
    5: EditLink := TQPVTEdit.Create(qpeComboLang);
    6: EditLink := TQPVTEdit.Create(qpeComboRating);
    7: EditLink := TQPVTEdit.Create(qpeComboType);
    8: EditLink := TQPVTEdit.Create(qpeEdit);
    9: EditLink := TQPVTEdit.Create(qpeEdit);
    10:EditLink := TQPVTEdit.Create(qpeROMParamMode);
    11:EditLink := TQPVTEdit.Create(qpeEdit);
  end;
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.VTDataNewText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; NewText: WideString);
begin
  if Node <> nil then

    Case Node.Index of
      0:  if _ROM.Name <> NewText then
          begin
            _ROM.Name := NewText;
            _Changed := True;
          end;

      1:  if _ROM.Path <> NewText then
          begin
            _ROM.Path := NewText;
            _Changed := True;
          end;
          
      2:  if _ROM.Emulator <> NewText then
          begin
            _ROM.Emulator := NewText;
            _Changed := True;
          end;

      3:  if _ROM.Company <> NewText then
          begin
            _ROM.Company := NewText;
            _Changed := True;
          end;

      4:  if _ROM.Year <> NewText then
          begin
            _ROM.Year := NewText;
            _Changed := True;
          end;

      5:  if _ROM.Language <> NewText then
          begin
            _ROM.Language := NewText;
            _Changed := True;
          end;

      6:  if _ROM.Rating <> NewText then
          begin
            _ROM.Rating := NewText;
            _Changed := True;
          end;

      7:  if _ROM.GameType <> NewText then
          begin
            _ROM.GameType := NewText;
            _Changed := True;
          end;

      8:  if _ROM.Multiplayer <> NewText then
          begin
            _ROM.Multiplayer := NewText;
            _Changed := True;
          end;

      9:  if _ROM.Parameters <> NewText then
          begin
            _ROM.Parameters := NewText;
            _Changed := True;
          end;

      10: if _ROM.ParameterMode <> TROMParametersMode(StrToInt(NewText)) then
          begin
            _ROM.ParameterMode := TROMParametersMode(StrToInt(NewText));   
            _Changed := True;
          end;

      11: if _ROM.Comment <> NewText then
          begin
            _ROM.Comment := NewText;
            _Changed := True;
          end;
    end;
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.VTDataPaintText(Sender: TBaseVirtualTree;
  const TargetCanvas: TCanvas; Node: PVirtualNode; Column: TColumnIndex;
  TextType: TVSTTextType);
begin
  If (Node <> nil) and (Column = 0) then
    TargetCanvas.Font.Style := TargetCanvas.Font.Style+[fsBold];
end;



{------------------------------------------------------------------------------}
//                         Code for IPS manager
{------------------------------------------------------------------------------}

procedure TFrmRomProp.VTIPSGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin
  Case Column of
    0 : CellText := '';
    1 : begin
          if Node.Index = 0 then
            CellText := 'No Default'
          else
            CellText := _ROM.IPS[Node.Index-1].IPSname;
        end;
    2 : begin
          if Node.Index = 0 then
            CellText := ''
          else
            CellText := _ROM.IPS[Node.Index-1].IPSpath;
        end;
  end;
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.VTIPSInitNode(Sender: TBaseVirtualTree; ParentNode,
  Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
var
  Index : Integer;
begin
  Sender.CheckType[Node] := ctRadioButton;
  Index := _ROM.DefaultIPSIndex;
  if (Node.Index = 0) and (Index = -1) then
    Sender.CheckState[Node] := csCheckedPressed
  else if Index = Integer(Node.Index)-1 then
    Sender.CheckState[Node] := csCheckedPressed;
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.VTIPSEditing(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; var Allowed: Boolean);
begin
  Allowed := (Node.Index <> 0) and (Column <> 0);
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.VTIPSCreateEditor(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; out EditLink: IVTEditLink);
begin
  Case Column of
    1 : EditLink := TQPVTEdit.Create(qpeEdit);
    2 : EditLink := TQPVTEdit.Create(qpeFileEdit);
  end;
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.VTIPSFocusChanged(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex);
begin
  with Sender do
  begin
    // Start immediate editing as soon as another node gets focused.
    if Assigned(Node) and not (tsIncrementalSearching in TreeStates) then
    begin
      // Note: the test whether a node can really be edited is done in the OnEditing event.
      EditNode(Node, Column);
    end;
  end;
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.VTIPSNewText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; NewText: WideString);
begin
  Case Column of
    1 : _ROM.IPS[Node.Index-1].IPSname := NewText;
    2 : _ROM.IPS[Node.Index-1].IPSPath := NewText;
  end;
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.BtnIPSAddClick(Sender: TObject);
Var
  IPSFrm : TFrmIPS;
begin
  if not Multi then
  begin

    IPSFrm := TFrmIPS.Create(self);
    Try
      IPSFrm.ROMName := _ROM.Name;

      if IPSFrm.ShowModal = mrOK then
      begin
        _ROM.AddIPS(IPSFrm.IPSName, IPSFrm.IPSPath, False);
        //be cheap and reinitialise the entire tree :)
        VTIPS.Clear;
        if _ROM.IPSCount > 0 then
          VTIPS.RootNodeCount := _ROM.IPSCount+1;
      end;

    Finally
      FreeAndNil(IPSFrm);
    end;

  end //end of 1 selected IF statement
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.BtnIPSinvalidClick(Sender: TObject);
Var
  I : Integer;
  Changed : Boolean;
begin
  VTIPS.BeginUpdate;
  try
    Changed := False;
    For I := _ROM.IPSCount-1 downto 0 do
      if not FileExists(_ROM.IPS[i].IPSPath) then
      begin
        _ROM.DeleteIPS(i);
        Changed := True;
      end;

    //reinit the tree.
    if Changed then
    begin
      VTIPS.Clear;
      if _ROM.IPSCount > 0 then
        VTIPS.RootNodeCount := _ROM.IPSCount+1;
    end;
  finally
    VTIPS.EndUpdate();
  end;
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.BtnIPSDeleteClick(Sender: TObject);
begin
  if VTIPS.GetFirstSelected = VTIPS.GetFirst then
    MessageDlg('You cannot delete this entry', mtError, [mbOK], 0)
  else
  begin
    VTIPS.BeginUpdate;
    try
      _ROM.DeleteIPS(VTIPS.GetFirstSelected.Index-1);
      //cancel the edit IF we are editting.
      if VTIPS.IsEditing then
        VTIPS.CancelEditNode;
      //if there are no IPS left, then we clear the whole list.
      if _ROM.IPSCount = 0 then
        VTIPS.Clear
      else
        VTIPS.DeleteSelectedNodes();
    finally
      VTIPS.EndUpdate;
    end;
  end;
end;

{------------------------------------------------------------------------------}

procedure TFrmRomProp.VTIPSChecked(Sender: TBaseVirtualTree;
  Node: PVirtualNode);
begin
  _ROM.DefaultIPSIndex := Integer(Node.Index)-1;
end;

procedure TFrmRomProp.VTDataFocusChanged(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex);
begin
  // bug fix: 18/5/05 - use Onfocuschange as OnChange doesnt work properly when you use
  // the next and back buttons.
  
  with Sender do
  begin
    // Start immediate editing as soon as another node gets focused.
    if Assigned(Node) and not (tsIncrementalSearching in TreeStates) then
    begin
      // Note: the test whether a node can really be edited is done in the OnEditing event.
      EditNode(Node, 1);
    end;
  end;
end;

{------------------------------------------------------------------------------}

end.
