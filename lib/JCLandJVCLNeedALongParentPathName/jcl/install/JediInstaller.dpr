{**************************************************************************************************}
{                                                                                                  }
{ Last modified: $Date:: 2009-09-18 15:53:34 +0200 (ven., 18 sept. 2009)                         $ }
{ Revision:      $Rev:: 3014                                                                     $ }
{ Author:        $Author:: outchy                                                                $ }
{                                                                                                  }
{**************************************************************************************************}

program JediInstaller;

{$I jcl.inc}

uses
  Forms,
  JclInstall in 'JclInstall.pas',
  JediInstall in 'JediInstall.pas',
  JediInstallConfigIni in 'JediInstallConfigIni.pas',
  JclBorlandTools in '..\source\common\JclBorlandTools.pas',
  JclResources in '..\source\common\JclResources.pas',
  JediRegInfo in 'JediRegInfo.pas',
  JclDotNet in '..\source\windows\JclDotNet.pas',
  FrmCompile in 'VclGui\FrmCompile.pas' {FormCompile},
  JediGUIReadme in 'VclGui\JediGUIReadme.pas' {ReadmeFrame: TFrame},
  JediGUIInstall in 'VclGui\JediGUIInstall.pas' {InstallFrame: TFrame},
  JediGUIMain in 'VclGui\JediGUIMain.pas' {MainForm},
  JediGUIProfiles in 'VclGui\JediGUIProfiles.pas' {ProfilesFrame: TFrame},
  JediProfiles in 'JediProfiles.pas',
  JclInstallResources in 'JclInstallResources.pas',
  JediInstallResources in 'JediInstallResources.pas';

{$R *.res}
{$R ..\source\windows\JclCommCtrlAsInvoker.res}

begin
  Application.Initialize;
  Application.Title := 'JEDI Installer';
  InstallCore.Execute;
end.
