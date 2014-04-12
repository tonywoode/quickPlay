unit ftabTextOnly;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, fJWinFontForm;

type
  TtabTextOnly = class(TJWinFontForm)
    memoText: TMemo;
  private
    { Private declarations }
  public
    { Public declarations }
    Procedure LoadText(inText : TStrings; useFont : TFont);
  end;

implementation

{$R *.dfm}

Procedure TtabTextOnly.LoadText(inText : TStrings; useFont : TFont);
begin
  memoText.Font.Assign(useFont);

  if inText.Text <> '' then
    memoText.Lines.Assign(inText)
  else
  begin
    memoText.Lines.Clear;
    memoText.Lines.Add('No Information Found');
  end;
end;

end.
