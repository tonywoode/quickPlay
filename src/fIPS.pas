{
  This is the form for adding a new IPS for a game.
  Basic form which allows you to select a file (extension .ips), and
  if you havent picked a name already, it will take the filename and use
  that.
}

unit fIPS;

interface

uses
  Windows, SysUtils, Classes, Controls, Forms, Dialogs, StdCtrls, Mask,
  JvExMask, JvToolEdit, fjWinFontForm;

type
  TFrmIPS = class(TJWinFontForm)
    TxtName: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    BtnOK: TButton;
    BtnCancel: TButton;
    Label3: TLabel;
    TxtPath: TJvFilenameEdit;
    procedure BtnOKClick(Sender: TObject);
    procedure TxtPathAfterDialog(Sender: TObject; var Name: String;
      var Action: Boolean);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
    ROMName, IPSName, IPSPath : String;
  end;

implementation

uses uJUtilities, ujMiscResourcestrs, uQPCompObj;

{$R *.dfm}

procedure TFrmIPS.BtnOKClick(Sender: TObject);
begin
  If (FileExists(TxtPath.Text)) And (TxtName.Text <> '') then
  Begin
    IPSName := TxtName.Text;
    IPSPath := TxtPath.Text;
    ModalResult := MrOk;
  End
  else
    MessageDlg(J_INVALID_INPUT, mtError, [mbOK], 0);
end;

procedure TFrmIPS.TxtPathAfterDialog(Sender: TObject; var Name: String;
  var Action: Boolean);
begin
  If (Action) and (TxtName.Text = '') then
    TxtName.Text := Format('%s [IPS - %s]', [ROMName, ChangeFileExt(ExtractFileName(Name), '')]);
end;

procedure TFrmIPS.FormCreate(Sender: TObject);
begin
  TxtPath.Filter := uQPCompObj.Compression.SupportedFileExtsForOpenDlg('*.ips', True);
end;

end.
