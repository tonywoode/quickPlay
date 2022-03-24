program zipdemo2;

uses
  Forms,
  Unit1 in 'Unit1.pas' {Form1};

{$R *.RES} 
{$R 'Res\ZMRes.res'}

begin
  Application.Initialize;
  Application.Title := 'Zip Demo 2';
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
