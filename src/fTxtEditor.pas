{
  Simple form which consists of a memo pad for editing files.
  Isnt fancy, just does the job.
}

unit fTxtEditor;

interface

uses
  Windows, SysUtils, Classes, Controls, Forms, Dialogs,
  StdCtrls, Buttons, ExtCtrls, Menus, ActnList, StdActns, fJWinFontForm;

type
  TEditCfgForm = class(TJWinFontForm)
    MemoCfg: TMemo;
    Panel1: TPanel;
    Panel2: TPanel;
    BtnClose: TButton;
    BtnSave: TButton;
    MainMenu1: TMainMenu;
    File1: TMenuItem;
    Edit1: TMenuItem;
    Save1: TMenuItem;
    EditActions: TActionList;
    EditCut1: TEditCut;
    EditCopy1: TEditCopy;
    EditPaste1: TEditPaste;
    EditSelectAll1: TEditSelectAll;
    Cut1: TMenuItem;
    Copy1: TMenuItem;
    Paste1: TMenuItem;
    SelectAll1: TMenuItem;
    Close1: TMenuItem;
    Format1: TMenuItem;
    ActWordWrap: TAction;
    WordWrap1: TMenuItem;
    N2: TMenuItem;
    procedure BtnSaveClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure Close1Click(Sender: TObject);
    procedure ActWordWrapExecute(Sender: TObject);
  private
    { Private declarations }
    CurrentFile : string;
  public
    { Public declarations }
    procedure Save(const FileName : String);
    Procedure load(const FileName : String);
  end;

implementation

uses fMain, ujMiscResourceStrs;

{$R *.DFM}

{-----------------------------------------------------------------------------}

procedure TEditCfgForm.Save(const FileName : String);
begin
   
  if (MemoCfg.Modified) and (MainFrm.Settings.AllowWrite) then
    MemoCfg.lines.SaveToFile(FileName);
end;

{-----------------------------------------------------------------------------}

Procedure TEditCfgForm.load(const FileName : String);
begin
  Currentfile := filename;
  MemoCfg.Clear;
  MemoCfg.Lines.LoadFromFile(FileName);
end;

{-----------------------------------------------------------------------------}

procedure TEditCfgForm.BtnSaveClick(Sender: TObject);
begin
  Save(CurrentFile);
  MemoCfg.Modified := false;
end;

{-----------------------------------------------------------------------------}

procedure TEditCfgForm.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
  if MemoCfg.Modified then
    if MessageDlg(J_SAVE_CHANGES,
                mtWarning, [mbYes, mbNo], 0) = mrYes then
      Save(currentFile);
end;

{-----------------------------------------------------------------------------}
procedure TEditCfgForm.Close1Click(Sender: TObject);
begin
  ModalResult := MROk;
end;

procedure TEditCfgForm.ActWordWrapExecute(Sender: TObject);
begin
  ActWordWrap.Checked := not(ActWordWrap.Checked);
  MemoCfg.WordWrap := ActWordWrap.Checked;
end;

end.

