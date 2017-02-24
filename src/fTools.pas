unit fTools;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Mask, JvExMask, JvToolEdit, CheckLst, uTools, ComCtrls,
  fJWinFontForm;

type
  TFrmToolCfg = class(TJWinFontForm)
    TxtFileName: TJvFilenameEdit;
    lblFileName: TLabel;
    lblName: TLabel;
    TxtName: TEdit;
    BtnOK: TButton;
    BtnCancel: TButton;
    TxtHomepage: TEdit;
    lblHomepage: TLabel;
    pgToolOpt: TPageControl;
    TabOptions: TTabSheet;
    TabMedia: TTabSheet;
    lblSysImage: TLabel;
    ChkAddToolTab: TCheckBox;
    TxtToolImage: TJvFilenameEdit;
    ChkShowAddInfo: TCheckBox;
    MemoToolInfo: TMemo;
    ChkLstCompress: TCheckListBox;
    TxtVariable: TEdit;
    TxtSpecialParam: TEdit;
    lblParamVar: TLabel;
    lblCompression: TLabel;
    lblVarBlank: TLabel;
    lblVariable: TLabel;
    lblParams: TLabel;
    ChkSupportsParam: TCheckBox;
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure BtnOKClick(Sender: TObject);
  private
    { Private declarations }
    _Tool : TQPTool;
  public
    { Public declarations }
    Property EditTool : TQPTool read _Tool;
    procedure SetEditTool(Tool : TQPTool);
  end;

var
  FrmToolCfg: TFrmToolCfg;

implementation

uses JclStrings, uJCompression, uQPCompObj, uJFile, uQPConst, ujMiscResourceStrs;

{$R *.dfm}

{-----------------------------------------------------------------------------}

procedure TFrmToolCfg.SetEditTool(Tool : TQPTool);
var
  InStrings : TStringList;
  i : Integer;
  CurExt : String;
begin
  _Tool.Assign(Tool);
  TxtName.Text := _Tool.Name;
  TxtFileName.Text := _Tool.Path;
  if (Tool.RelativePath <> '') then TxtFileName.Text := Tool.RelativePath;
  TxtHomePage.Text := _Tool.HomePage;
  ChkSupportsParam.Checked := _Tool.CmdLine;
  TxtVariable.Text := _Tool.VarName;
  TxtSpecialParam.Text := _Tool.Parameters;

  ChkLstCompress.Clear;

  for i := 0 to _Tool.CompressStrings.Count-1 do
  begin
    ChkLstCompress.Items.add(trim(_Tool.CompressStrings.Names[i]));
    ChkLstCompress.Checked[i] := StrToBool(_Tool.CompressStrings.ValueFromIndex[i]);
  end;

  //now add in any new supported formats that arent in the INI file.
  InStrings := TStringList.Create;
  try
    InStrings.Text := uQPCompObj.Compression.SupportedFileExts(cmRead);
    for i := 0 to InStrings.Count-1 do
    begin
      CurExt := ujFile.GetVirtualFileExtension(InStrings[i]);
      if ChkLstCompress.Items.IndexOf(CurExt) = -1 then
        ChkLstCompress.Items.add(CurExt);
    end;
  finally
    FreeAndNil(InStrings);
  end;

  //load media settings
  ChkAddToolTab.Checked := _Tool.ShowExeTab;
  TxtToolImage.FileName := _Tool.ExeImage;
  ChkShowAddInfo.Checked := _Tool.ShowAddInfo;
  memoToolInfo.Clear;
  memoToolInfo.Lines.AddStrings(_Tool.AdditionalInfo);
end;

{-----------------------------------------------------------------------------}

procedure TFrmToolCfg.FormCreate(Sender: TObject);
var
  InStrings : TStringList;
  i : Integer;
  CurExt : String;
begin
  pgToolOpt.ActivePageIndex := 0;
  
  _Tool := TQPTool.Create;

  //now add in any new supported formats that arent in the INI file.
  InStrings := TStringList.Create;
  try
    InStrings.Text := uQPCompObj.Compression.SupportedFileExts(cmRead);
    for i := 0 to InStrings.Count-1 do
    begin
      CurExt := ujFile.GetVirtualFileExtension(InStrings[i]);
      ChkLstCompress.Items.add(CurExt);
    end;
  finally
    FreeAndNil(InStrings);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmToolCfg.FormDestroy(Sender: TObject);
begin
  FreeAndNil(_Tool);
end;

{-----------------------------------------------------------------------------}

procedure TFrmToolCfg.BtnOKClick(Sender: TObject);
var
  i : integer;
begin
  if TxtName.Text <> '' then
    _Tool.Name := TxtName.Text
  else
  begin
    ModalResult := MrNone;
    MessageDlg(J_ENTER_ALL_DATA, mtError, [mbOK], 0);
    TxtName.SetFocus;
    exit;
  end;

  if FileExists(TxtFileName.Text) then   //a relative path is caught by this somehow
    _Tool.Path := TxtFileName.Text;


  //if you've changed a relative path to something else, invalidate the relative path setting
  if (TxtFileName.Text <> _Tool.RelativePath) then
    _Tool.RelativePath := '';

  //if you haven't changed the relative path, keep the full path in memory
  if (_Tool.RelativePath <> '') and (TxtFileName.Text = _Tool.RelativePath) then
    _Tool.Path := getCurrentDir() + '\' + TxtFileName.Text;

  //if you just changed to a relative path, store it as full and mark it as relative
  if (FileExists(getCurrentDir() + '\' + TxtFileName.Text)) then
    begin
      _Tool.RelativePath := TxtFileName.Text;
      _Tool.Path  := getCurrentDir() + '\' + TxtFileName.Text;
    end;


  if not FileExists(TxtFileName.Text) then
  begin
    ModalResult := MrNone;
    MessageDlg(J_FILE_NOT_EXIST, mtError, [mbOK], 0);
    TxtFileName.SetFocus;
    exit;
  end;
  
  _Tool.HomePage := TxtHomepage.Text;
  _Tool.CmdLine := ChkSupportsParam.Checked;
  _Tool.Parameters := TxtSpecialParam.Text;

  if (ChkSupportsParam.Checked) and (TxtVariable.Text <> '') then
    if (Pos(' ', TxtVariable.Text) = 0 ) then
      _Tool.VarName := TxtVariable.Text
    else
    begin
      ModalResult := MrNone;
      MessageDlg(J_VAR_SPACES, mtError, [mbOK], 0);
      TxtVariable.SetFocus;
      exit;
    end;

  _Tool.CompressStrings.Clear;
  for i := 0 to ChkLstCompress.Count-1 do
      _Tool.CompressStrings.Values[ChkLstCompress.Items[i]] := boolToStr(ChkLstCompress.Checked[i]);

  //save media settings
  _Tool.ShowExeTab := ChkAddToolTab.Checked;
  _Tool.ExeImage := TxtToolImage.FileName;
  _Tool.ShowAddInfo := ChkShowAddInfo.Checked;
  _Tool.AdditionalInfo.Clear;
  _Tool.AdditionalInfo.AddStrings(memoToolInfo.Lines);
end;

{-----------------------------------------------------------------------------}

end.
