program DiskSpanDemo;

uses
  Forms,
  Main in 'Main.pas' {MainForm},
  AddUnit in 'Addunit.pas' {AddFile},
  ExtrUnit in 'ExtrUnit.pas' {Extract},
  MsgUnit in 'MsgUnit.pas' {Msgform};

{$R *.RES}
//{$R ZipMsgUS.res}
{$R 'res\ZMRes.res'}

begin
  Application.Initialize;
  Application.Title := 'Disk span demo';
  Application.CreateForm(TMainForm, MainForm);
  Application.CreateForm(TAddFile, AddFile);
  Application.CreateForm(TExtract, Extract);
  Application.CreateForm(TMsgform, Msgform);
  Application.Run;
end.
