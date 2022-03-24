unit fJWinFontForm;

interface

uses
  Windows, Messages, SysUtils, Classes, Controls, Forms,
  Dialogs, ComCtrls, Graphics, Menus;

type
  TFontHack = class(TControl); 
  TJWinFontForm = class(TForm)
  Protected
    procedure ConfigureFonts;
    { Private declarations }
  public
    { Public declarations }
    constructor Create(AOwner: TComponent);override;
  end;

var
  JWinFontForm: TJWinFontForm;

implementation

{$R *.dfm}

uses ujWindowsMisc;

procedure TJWinFontForm.ConfigureFonts;
var
  myFont : TFont;
  statusFont : TFont;
  i : Integer;
begin
  myFont := TFont.Create;
  try
    ujWindowsMisc.GetWindowsFont(myFont, jwfMessage);
    self.Font.Assign(myFont);
  finally
    FreeAndNil(myFont);
  end;

  statusFont := TFont.Create;
  try
    ujWindowsMisc.GetWindowsFont(statusFont, jwfStatus);

    for i := 0 to Self.ComponentCount - 1 do
    begin
      //check for the presence of a status bar.
      if Self.Components[i] is TStatusBar then
      begin
        TStatusBar(Self.Components[i]).Font.Assign(statusFont);
        continue;
      end;

      if Self.Components[i] is TControl then
      begin
        TFontHack(Self.Components[i]).Font.Name := Self.Font.Name;
      end;
    end;
  
  finally
    FreeAndNil(StatusFont);
  end;

end;

constructor TJWinFontForm.Create(AOwner: TComponent);
begin
  inherited;

  //check for presence of Disable file before configuring Fonts
  if not FileExists(ExtractFilePath(Application.ExeName) + 'DisableSysFont.jon') then
    ConfigureFonts();
end;

end.
