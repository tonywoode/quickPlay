unit fMediaAddDefaultTab;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, fJWinFontForm;

type
  TFrmAddDefaultTab = class(TJWinFontForm)
    lblCaption: TLabel;
    lblDefaultType: TLabel;
    TxtCaption: TEdit;
    CmbType: TComboBox;
    BtnOK: TButton;
    BtnCancel: TButton;
  private
    { Private declarations }
  public
    { Public declarations }
  end;

implementation

{$R *.dfm}

end.
