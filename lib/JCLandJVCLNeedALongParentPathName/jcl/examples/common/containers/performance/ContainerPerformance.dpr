program ContainerPerformance;

{$I jcl.inc}

uses
  {$IFDEF MSWINDOWS}
  Forms,
  {$ENDIF MSWINDOWS}
  ContainerPerformanceMain in 'ContainerPerformanceMain.pas' {MainForm},
  ContainerPerformanceTests in 'ContainerPerformanceTests.pas';

{$R *.res}
{$R ..\..\..\..\source\windows\JclCommCtrlAsInvoker.res}

begin
  Application.Initialize;
  Application.CreateForm(TMainForm, MainForm);
  Application.Run;
end.
