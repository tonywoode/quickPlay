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
    GroupBox1: TGroupBox;
    ComboBox1: TComboBox;
    ComboBox2: TComboBox;
    ComboBox3: TComboBox;
    ComboBox4: TComboBox;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    BtnCancel: TButton;
    MameOptsOk: TButton;
    XMLEdit: TEdit;
    XMLTxtLbl: TLabel;
    CmbMame: TComboBox;
    lblMAME: TLabel;
    Edit1: TEdit;
    Label5: TLabel;
    procedure Label1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  FrmMameFilePath: TFrmMameFilePath;

implementation

{$R *.dfm}

