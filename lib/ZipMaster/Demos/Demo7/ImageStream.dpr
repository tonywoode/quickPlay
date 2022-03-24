program ImageStream;

uses
  Forms,
  Unit1 in 'Unit1.pas' {Form1};

{$R *.RES}
//{$R ZipMsgUS.RES}
{$R 'res\ZMRes.res'}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
