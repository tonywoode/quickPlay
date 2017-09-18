unit fMameOptions;

interface

uses
  Windows, SysUtils, StdCtrls, Controls, Classes, fJWinFontForm, JvSelectDirectory, JvBrowseFolder, Dialogs;

type
  TFrmMameOptions = class(TJWinFontForm)
    BtnOK: TButton;
    BtnCancel: TButton;
    MameExtrasLabel: TLabel;
    TxtMameExtrasDirPath: TEdit;
    BtnMameExtrasDirFind: TButton;
    MameExtrasDescLabel: TLabel;
    procedure MameExtrasLabelClick(Sender: TObject);
    procedure BtnMameExtrasDirFindClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure BtnOKClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

implementation

uses fMain, uJUtilities, StrUtils, JCLstrings, uQPConst;

{$R *.dfm}


procedure TFrmMameOptions.FormShow(Sender: TObject);
begin
  TxtMameExtrasDirPath.Text :=  MainFrm.Settings.MameExtrasDir;

end;

procedure TFrmMameOptions.MameExtrasLabelClick(Sender: TObject);
begin

end;

{-----------------------------------------------------------------------------}

procedure TFrmMameOptions.BtnMameExtrasDirFindClick(Sender: TObject);
var
  jvBrowse: TJvBrowseForFolderDialog;
begin
  jvBrowse := TJvBrowseForFolderDialog.Create(self);

  try

   if DirectoryExists(MainFrm.Settings.MameExtrasDir) then
      jvBrowse.Directory := MainFrm.Settings.MameExtrasDir;
      if (jvBrowse.execute) and (DirectoryExists(jvBrowse.Directory)) then
        begin
         if DirectoryExists(jvBrowse.Directory + '/icons/') then
             TxtMameExtrasDirPath.Text := jvBrowse.Directory
           else
             MessageDlg(QP_MAMEOPT_BAD_DIR, mtError, [mbOK], 0);
         end;
  finally
    FreeAndNil(jvBrowse);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMameOptions.BtnOKClick(Sender: TObject);
begin
  MainFrm.Settings.MameExtrasDir := TxtMameExtrasDirPath.Text;
  MainFrm.Settings.SaveAllSettings();
  //close the form with the modal result OK
  ModalResult := MrOK;
end;


end.

