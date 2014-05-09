unit fMameHolding;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls;

type
  TMameHolding = class(TForm)
    OKButton: TButton;
    Panel1: TPanel;
    Link2: TLabel;
    Link1: TLabel;
    Instructions1: TLabel;
    Instructions2: TLabel;
    Instructions3: TLabel;
    Label1: TLabel;
    procedure Link1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  MameHolding: TMameHolding;

implementation

uses fMain, ShellAPI, Clipbrd, VirtualTrees;

{$R *.dfm}

procedure TMameHolding.Link1Click(Sender: TObject);
begin
  ShellExecute(Handle, 'open', PChar(Link1.Caption), '', '', sw_Show);
end;

end.
