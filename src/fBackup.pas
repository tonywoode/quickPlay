unit fBackup;

interface

uses
  Windows, SysUtils, Classes, Graphics, Controls, Forms,
  Dialogs, ComCtrls, StdCtrls, VirtualTrees, fjWinFontForm;

type
  TFrmBackup = class(TjWinFontForm)
    pgBackup: TPageControl;
    TabWelcome: TTabSheet;
    TabBackupComplete: TTabSheet;
    TabRestore: TTabSheet;
    TabRestoreComplete: TTabSheet;
    lblTitle: TLabel;
    RadBackup: TRadioButton;
    RadRestore: TRadioButton;
    BtnCancel: TButton;
    BtnBegin: TButton;
    lblBackup: TLabel;
    lblRestore: TLabel;
    VtRestore: TVirtualStringTree;
    BtnRestore: TButton;
    procedure BtnBeginClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure VtRestoreGetText(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure VtRestoreInitNode(Sender: TBaseVirtualTree; ParentNode,
      Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
    procedure VtRestoreChange(Sender: TBaseVirtualTree;
      Node: PVirtualNode);
    procedure BtnRestoreClick(Sender: TObject);
  private
    { Private declarations }
    RestoreList : TStringList; //stringlist to hold the found restore files.
  public
    { Public declarations }
  end;

implementation

uses fMain, uJUtilities, FindFile, uQPConst, ujMiscResourceStrs;

{$R *.dfm}

procedure TFrmBackup.FormCreate(Sender: TObject);
var
  i : integer;
begin
  //create the stringlist to hold the files found
  RestoreList := TStringList.Create;

  //disable all the tabs.
  For i := 0 to pgBackup.PageCount-1 do
    pgBackup.Pages[i].TabVisible := False;

  pgBackup.ActivePage := TabWelcome;
end;

{-----------------------------------------------------------------------------}

procedure TFrmBackup.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  //remember to free the restore list!
  FreeAndNil(RestoreList);
end;

{-----------------------------------------------------------------------------}

procedure TFrmBackup.BtnBeginClick(Sender: TObject);
var
  TmpName : String;
  OldCursor : TCursor;
  Find : ThhFindFile;
begin

  //first check that the user HAS checked something!
  If (not RadBackup.Checked) and (not RadRestore.Checked) then
  begin
    MessageDlg(QP_BACKUP_MAKE_SELECTION, mtWarning, [mbOK], 0);
    exit;
  end;

  //the user has checked something - begin either process.
  if RadBackup.Checked then
  begin
    //First change the hourglass - this could take a while!
    OldCursor := Screen.Cursor;
    Screen.Cursor := crHourGlass;
    Try
      //the first step is to build a filename
      DateTimeToString(TmpName, 'dd-mm-yyyy hh-nn-ss', Now());

      TmpName := MainFrm.Settings.Paths.AppDir + 'backup\backup - ' + TmpName + '.zip';

      try
        MainFrm.Settings.BackupData(TmpName);
      except
        on E: EJException do MessageDlg(E.Message, mtError, [mbOK], 0);
      end;

      //now set the pagecontrol to the backup finished page.
      lblBackup.Caption := ExtractFileName(TmpName);
      PgBackup.ActivePage := TabBackupComplete;
    finally
      Screen.Cursor := OldCursor;
    end;

  end
  else
  begin
    //the user wants to restore from a specified file

    If DirectoryExists(MainFrm.Settings.Paths.AppDir + 'backup\') then
    begin

      //populate the RestoreList.
      Find := ThhFindFile.Create(Self);
      Try
        Find.Directory := MainFrm.Settings.Paths.AppDir + 'backup\';
        Find.Filter := '*.zip';
        Find.Sorted := True;
        Find.Execute;

        RestoreList.Assign(Find.Files);

        VTRestore.RootNodeCount := RestoreList.Count+1;
        
      Finally
        FreeAndNil(Find);
      end;
    end;

    //now load the tab
    pgBackup.ActivePage := TabRestore;

  end; //end of RESTORE optoin code
end;

{-----------------------------------------------------------------------------}

procedure TFrmBackup.VtRestoreGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin
  if Integer(Node.Index) < RestoreList.Count then
    CellText := ExtractFileName(RestoreList[Node.Index])
  else
    CellText := QP_BACKUP_CHOOSE_DIFF_FILE;
end;

procedure TFrmBackup.VtRestoreInitNode(Sender: TBaseVirtualTree;
  ParentNode, Node: PVirtualNode;
  var InitialStates: TVirtualNodeInitStates);
begin
  Sender.CheckType[Node] := ctRadioButton;
end;

procedure TFrmBackup.VtRestoreChange(Sender: TBaseVirtualTree;
  Node: PVirtualNode);
begin
  If (Assigned(Node)) and  (not (tsIncrementalSearching in Sender.TreeStates)) then
  begin
    Sender.CheckState[Node] := csCheckedNormal;
  end;
end;

procedure TFrmBackup.BtnRestoreClick(Sender: TObject);
var
  OldCursor : TCursor;
  aNode : PVirtualNode;
  SelectedFile : String;
  Picker : TOpenDialog;
begin

  //First change the hourglass - this could take a while!
  OldCursor := Screen.Cursor;
  Screen.Cursor := crHourGlass;
  Try

    //first we need to figure out what file the user wants to use.
    aNode := VTRestore.GetFirst;
    while aNode <> nil do
    begin
      If VTRestore.CheckState[aNode] = csCheckedNormal then
        if Integer(aNode.Index) < RestoreList.Count then
          SelectedFile := RestoreList[aNode.Index]
        else
          SelectedFile := QP_BACKUP_CHOOSE;

      aNode := VTRestore.GetNext(aNode);
    end;

    //if its blank then we alert the user and allow them to pick an option
    If SelectedFile = '' then
    begin
      MessageDlg(QP_BACKUP_NO_RESTORE, mtWarning, [mbOK], 0);
      exit;
    end
    else
      if SelectedFile = QP_BACKUP_CHOOSE then
      begin
        //the user wants to choose a different file, show them a file picker dialog.
        Picker := TOpenDialog.Create(Self);
        try

          Picker.Filter := 'Zip Files (*.zip)|*.zip';
          if Picker.Execute and FileExists(Picker.FileName) then
            SelectedFile := Picker.FileName
          else
          begin
            //they either didnt specify a file or it doesnt exist
            MessageDlg(J_FILE_NOT_EXIST, mtError, [mbOK], 0);
            exit;
          end;

        Finally
          FreeAndNil(Picker);
        end;
      end;

    //finally restore the users configuration
    try
      MainFrm.Settings.RestoreData(SelectedFile);
    except
      on E: EJWarning Do MessageDlg(E.Message, mtError, [mbOK], 0);
      on E: EJException Do MessageDlg(E.Message, mtError, [mbOK], 0);
    end;

    //change the selected FORM and change what the close button returns
    lblRestore.Caption := ExtractFileName(SelectedFile);
    BtnCancel.ModalResult := MrOk;
    pgBackup.ActivePage := TabRestoreComplete;

  //put the cursor back.
  Finally
    Screen.Cursor := OldCursor;
  end;
  
end;

end.
