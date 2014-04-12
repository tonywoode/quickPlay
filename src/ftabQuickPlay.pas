unit ftabQuickPlay;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, StdCtrls, GraphicEX, fJWinFontForm;

type
  TTabQuickplay = class(TJWinFontForm)
    ImgQP: TImage;
    PanLinks: TPanel;
    lblWelcome: TLabel;
    lblSetupMediaPaths: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure lblSetupMediaPathsClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

implementation

{$R *.dfm}

uses fMain;

procedure TTabQuickplay.lblSetupMediaPathsClick(Sender: TObject);
begin
  MainFrm.actMediaOptionsExecute(Sender);
end;

procedure TTabQuickplay.FormCreate(Sender: TObject);
begin
  //cause issue, why do this anyways
  ImgQP.Picture.LoadFromFile(MainFrm.Settings.Paths.AppDir + 'newlogo.png');
end;

end.
