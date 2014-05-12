program QP;

{%ToDo 'QP.todo'}

uses
  Forms,
  fAbout in 'fAbout.pas' {AboutBox},
  fAddaRom in 'fAddaRom.pas' {AddRomForm},
  fBackup in 'fBackup.pas' {FrmBackup},
  fColumns in 'fColumns.pas' {FrmColumn},
  fCustomRomData in 'fCustomRomData.pas' {FrmROMData},
  fEditEmuFind in 'fEditEmuFind.pas' {FrmEFindEdit},
  fEmuChanges in 'fEmuChanges.pas' {EmuChangeFrm},
  fEmuFind in 'fEmuFind.pas' {EmuFinder},
  fEmulators in 'fEmulators.pas' {FrmEmuDlg},
  fExport in 'fExport.pas' {ROMexport},
  fFav in 'fFav.pas' {FavForm},
  fFind in 'fFind.pas' {FindForm},
  fFolderOpt in 'fFolderOpt.pas' {FrmFolder},
  fIPS in 'fIPS.pas' {FrmIPS},
  fMameMerge in 'fMameMerge.pas' {FrmMAMEMerged},
  fMameRename in 'fMameRename.pas' {DatReader},
  fMigrate in 'fMigrate.pas' {FrmMigrate},
  fOptions in 'fOptions.pas' {PrefForm},
  fRomProperties in 'fRomProperties.pas' {FrmRomProp},
  fRunDlg in 'fRunDlg.pas' {FrmRunRom},
  fScan in 'fScan.pas' {ScanForm},
  fScanRecursive in 'fScanRecursive.pas' {RecursiveFrm},
  fTxtEditor in 'fTxtEditor.pas' {EditCfgForm},
  fWelcome in 'fWelcome.pas' {FrmWelcome},
  fZip in 'fZip.pas' {FrmCompressionTools},
  uEmuUtils in 'uEmuUtils.pas',
  uRom in 'uRom.pas',
  uRomUtils in 'uRomUtils.pas',
  uRomList in 'uRomList.pas',
  uSettings in 'uSettings.pas',
  uEmu in 'uEmu.pas',
  uEmuList in 'uEmuList.pas',
  uQPDir in 'uQPDir.pas',
  uQuery in 'uQuery.pas',
  uQPVTEditor in 'uQPVTEditor.pas',
  uQPVTQueryEditor in 'uQPVTQueryEditor.pas',
  uQPConst in 'uQPConst.pas',
  fTools in 'fTools.pas' {FrmToolCfg},
  uEmuFindObj in 'uEmuFindObj.pas',
  uExe in 'uExe.pas',
  fCompressFilePicker in 'fCompressFilePicker.pas' {FrmCompressPicker},
  uTools in 'uTools.pas',
  uExeList in 'uExeList.pas',
  uToolList in 'uToolList.pas',
  fMediaPanelOptions in 'fMediaPanelOptions.pas' {FrmMediaPanelOptions},
  fAppearanceOptions in 'fAppearanceOptions.pas' {FrmAppearanceOptions},
  uMediaPanelClasses in 'uMediaPanelClasses.pas',
  uMediaSystemClass in 'uMediaSystemClass.pas',
  uMediaTabClass in 'uMediaTabClass.pas',
  uMediaMiscTypes in 'uMediaMiscTypes.pas',
  fMediaAddDefaultTab in 'fMediaAddDefaultTab.pas' {FrmAddDefaultTab},
  ftabThumbBrowser in 'ftabThumbBrowser.pas' {tabThumbBrowser},
  ftabImageViewer in 'ftabImageViewer.pas' {tabImageViewer},
  ftabTextOnly in 'ftabTextOnly.pas' {tabTextOnly},
  ftabQuickPlay in 'ftabQuickPlay.pas' {TabQuickplay},
  ftabSysEmu in 'ftabSysEmu.pas' {TabSysEmu},
  uQPMiscTypes in 'uQPMiscTypes.pas',
  fParamVars in 'fParamVars.pas' {FrmParamVars},
  uQPCompObj in 'uQPCompObj.pas',
  uVersionCheckThread in 'uVersionCheckThread.pas',
  fMameHolding in 'fMameHolding.pas' {MameHolding};

{$R *.RES}
{$R WindowsXP.RES}

begin
  Application.Initialize;
  Application.Title := 'Quick Play - Phoenix';
  Application.CreateForm(TMameHolding, MameHolding);
  Application.Run;
end.
