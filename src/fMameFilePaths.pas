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
    MameOptsOk: TButton;
    XMLEdit: TEdit;
    XMLTxtLbl: TLabel;
    CmbMame: TComboBox;
    lblMAME: TLabel;
    RomPathEdit: TEdit;
    RomPathLbl: TLabel;
    RomPathDescLbl: TLabel;
    procedure RomsPathTypeLblClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  FrmMameFilePath: TFrmMameFilePath;

implementation

{$R *.dfm}

