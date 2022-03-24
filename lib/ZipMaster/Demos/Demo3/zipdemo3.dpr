program zipdemo3;

uses
  Forms,
  Unit1 in 'Unit1.pas' {Form1},
  tziplist in 'tziplist.pas' {ZipForm},
  extrunit in 'extrunit.pas' {Extract};

{$R *.RES}
//{$R ZipMsgUS.RES}
{$R 'RES\ZMRes.res'}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.CreateForm(TZipForm, ZipForm);
  Application.CreateForm(TExtract, Extract);
  Application.Run;
end.
