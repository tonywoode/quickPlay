{

Simple form for an About Box.  Nothing special about this file,
only slightly interesting thing is the link which is clickable.

}
unit fAbout;

interface

uses Windows, SysUtils, Classes, Graphics, Forms, Controls, StdCtrls,
  Buttons, ExtCtrls, fjWinFontForm;

type
  TAboutBox = class(TjWinFontForm)
    Panel1: TPanel;
    ProgramIcon: TImage;
    ProductName: TLabel;
    Version: TLabel;
    lblWrittenIn: TLabel;
    OKButton: TButton;
    LblLink: TLabel;
    Label2: TLabel;
    Label1: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    ffv: TLabel;
    procedure LblLinkClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure LblLinkMouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

implementation

uses fMain, ShellAPI, Clipbrd, VirtualTrees;

{$R *.dfm}

procedure TAboutBox.LblLinkClick(Sender: TObject);
begin
  ShellExecute(Handle, 'open', PChar(lblLink.Caption), '', '', sw_Show);
end;

procedure TAboutBox.FormCreate(Sender: TObject);
begin
  Version.Caption := QPVer;
  //lblVTVer.Caption := VirtualTrees.VTVersion;
end;

procedure TAboutBox.LblLinkMouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
var
  Clip : TClipBoard;
begin
  If Button = mbRight then
  begin
    Clip := ClipBoard;
    Clip.AsText := 'http://www.quickplayfrontend.com/';
  end;
end;

end.

