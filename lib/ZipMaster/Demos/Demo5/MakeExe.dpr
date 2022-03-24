program MakeExe;



uses
  Forms,
  mainunit in 'mainunit.pas' {Mainform},
  Addunit in 'Addunit.pas' {AddForm};

{$R *.RES}
//{$R ZipMsgUS.res}
{$R 'res\ZMRes.res'}

begin
  Application.Initialize;
  Application.Title := 'Make Exe Archive';
  Application.CreateForm(TMainform, Mainform);
  Application.CreateForm(TAddForm, AddForm);
  Application.Run;
end.
