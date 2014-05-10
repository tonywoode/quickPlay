unit fMameHolding;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls;

type
  TMameHolding = class(TForm)
    OKButton: TButton;
    Panel1: TPanel;
    Link1: TLabel;
    Link2: TLabel;
    Instructions1: TLabel;
    Instructions2: TLabel;
    Instructions3: TLabel;
    Label1: TLabel;
    procedure Link2Click(Sender: TObject);
    procedure Link1Click(Sender: TObject);
    procedure Link1MouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure Link2MouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
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

procedure TMameHolding.Link2Click(Sender: TObject);
begin
     ShellExecute(Handle, 'open', PChar(Link2.Caption), '', '', sw_Show);
end;

procedure TMameHolding.Link1MouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
var
  Clip : TClipBoard;
begin
  If Button = mbRight then
  begin
    Clip := ClipBoard;
    Clip.AsText := Link1.Caption;
  end;
end;

procedure TMameHolding.Link2MouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
var
  Clip : TClipBoard;
begin
  If Button = mbRight then
  begin
    Clip := ClipBoard;
    Clip.AsText := Link2.Caption;
  end;
end;

end.
