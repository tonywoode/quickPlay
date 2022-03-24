program ViewZip;

uses
  Forms,
  Unit1 in 'Unit1.pas' {Form1},
  InstUnit in 'InstUnit.pas' {InstForm};

{$R *.RES}
//{$R ZipMsgUS.res}
{$R 'RES\ZMRes.res'}

begin
  Application.Initialize;
  Application.Title := 'ViewZip';
  Application.CreateForm( TForm1, Form1 );
  Application.Run;
end.
