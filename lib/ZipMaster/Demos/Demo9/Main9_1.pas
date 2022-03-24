unit Main9_1;

interface

uses
  Windows, Messages, SysUtils, {Variants,} Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls;

type
  TForm1 = class(TForm)
	Memo1: TMemo;
    Panel1: TPanel;
    Button1: TButton;
    Button2: TButton;
    procedure FormCreate(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
	{ Private declarations }
	fzip: TThread;
  public
	{ Public declarations }
	property ZipThread: TThread read fzip write fzip;
  end;

var
  Form1: TForm1;

implementation
Uses
	ZThrd;

{$R *.dfm}    
{$R Demo9.Manifest.res Demo9.Manifest.rc}


procedure TForm1.FormCreate(Sender: TObject);
begin
	fzip := nil;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
	if assigned(fzip) then
		fzip.Terminate
	else
		Memo1.Lines.Add('**** Not Running ****');
end;

procedure TForm1.Button1Click(Sender: TObject);
var sl: TStringList;
begin
	if not assigned(fzip) then
	begin
		sl := TStringList.Create;
		try
			sl.Add('*.pas');
			sl.Add('*.dfm');
			sl.Add('*.bpr');
			fzip := TZipThread.Create('test.zip',sl,Memo1,false);
		finally
			sl.Free;
		end;
	end;
end;

end.

