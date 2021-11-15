unit fMameFilePaths;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  TFrmMameFilePath = class(TForm)
    GrpBoxArcadeSList: TGroupBox;
    LblMameFiletypeExplain: TLabel;
    LblMameRomsTypeExplain: TLabel;
    GBoxMergeType: TGroupBox;
    RadMameMergeMerged: TRadioButton;
    RadMameMergeNonMerged: TRadioButton;
    GBoxGroupFiletype: TGroupBox;
    RadMameFileZip: TRadioButton;
    RadMameFile7z: TRadioButton;
    ChkBoxMameFilePaths: TCheckBox;
    GrpRomPathTypes: TGroupBox;
    CmbRomsPath: TComboBox;
    CmbChdsPath: TComboBox;
    CmbSoftlistRomsPath: TComboBox;
    CmbSoftlistChdsPath: TComboBox;
    RomsPathTypeLbl: TLabel;
    ChdsPathTypeLbl: TLabel;
    SoftlistRomsPathTypeLbl: TLabel;
    SoftlistChdsPathTypeLbl: TLabel;
    BtnCancel: TButton;
    MameFileOptsOk: TButton;
    XMLEdit: TEdit;
    XMLTxtLbl: TLabel;
    CmbMame: TComboBox;
    lblMAME: TLabel;
    RomPathEdit: TEdit;
    RomPathLbl: TLabel;
    RomPathDescLbl: TLabel;
    procedure MameFileOptsOkClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  FrmMameFilePath: TFrmMameFilePath;

implementation

uses fMain, uQPMiscTypes;

{$R *.dfm}

  const
  EmuEmptyMessage = 'No MAME Emulators. Run an E-Find';


procedure TFrmMameFilePath.FormShow(Sender: TObject);
begin

With MainFrm do
  begin
  EmuList.EmusToStrings(CmbMame.Items, cfMameArcade);
if CmbMame.Items.Count = 0 then
    begin
      CmbMame.Items.Add(EmuEmptyMessage );
      CmbMame.ItemIndex := CmbMame.Items.IndexOf(EmuEmptyMessage );
      CmbMame.Color := clInactiveBorder;
      CmbMame.Font.Color := clMaroon;
      CmbMame.Font.Style := [fsBold];
      CmbMame.Font.Size := 10;
    end
    else CmbMame.ItemIndex := CmbMame.Items.IndexOf(Settings.MametoolMameExeName);
    end ;



ChkBoxMameFilePaths.Checked := MainFrm.Settings.MameFilePaths;

  if (MainFrm.Settings.MameZipType = '7z')
  then RadMameFile7z.Checked := True
  else RadMameFileZip.Checked := True;

  if (MainFrm.Settings.MameFilePathsRomsType = 'NonMerged')
  then RadMameMergeNonMerged.Checked := True
  else RadMameMergeMerged.Checked := True;

end;



procedure TFrmMameFilePath.MameFileOptsOkClick(Sender: TObject);
begin
MainFrm.Settings.MameFilePaths := ChkBoxMameFilePaths.Checked;
  if RadMameFile7z.Checked
  then MainFrm.Settings.MameZipType := '7z'
  else MainFrm.Settings.MameZipType := 'Zip';

  if RadMameMergeNonMerged.Checked
  then MainFrm.Settings.MameFilePathsRomsType := 'NonMerged'
  else MainFrm.Settings.MameFilePathsRomsType := 'Merged';

  MainFrm.Settings.SaveAllSettings(); //in case you changed the mame extras dir but didn't do a scan
  //close the form with the modal result OK
  ModalResult := MrOK;

  //we want to refresh: sidebar icons, mame icons, info files will all now show up...
  //why not do it in the caller in the main form? just to be consistent with the other mame dialog boxes
   MainFrm.ActRefreshExecute(Sender);
  //bugfix: there's something specific about the xml scan, ini lookup and dat/efind posting that causes qp to lose current directory
  //  it was causing the first call to a mame game after a scan to fail as the game wasn't found (I suspect "./qp.exe") -  TODO: this
  //  should get called after the scan incase user presses cancel...
   setCurrentDir(MainFrm.Settings.Paths.AppDir);
end;

end.
