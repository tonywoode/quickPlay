unit ftabSysEmu;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls, fJWinFontForm;

type
  TTabSysEmu = class(TJWinFontForm)
    ImgQP: TImage;
    memoInfo: TMemo;
    Splitter1: TSplitter;
    lblHomePage: TLabel;
    procedure lblHomePageClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
    procedure Configure(Img : TFileName; ShowInfo : Boolean;
                        Text : TStrings; Url : String);
  end;

implementation

uses ujImages, uJUtilities;

{$R *.dfm}

procedure TTabSysEmu.Configure(Img : TFileName; ShowInfo : Boolean; Text : TStrings; Url : String);
begin
  if FileExists(Img) and ujImages.HasImageFileExt(Img) then
    ImgQP.Picture.LoadFromFile(Img);

  if ShowInfo then
  begin
    MemoInfo.Lines.Assign(Text);
    memoInfo.ScrollBars := ssVertical;  //feature request #25 - word wrap history and info....
    memoInfo.WordWrap := True;
  end
  else
    MemoInfo.Hide;

  if URL <> '' then
    LblHomePage.Caption := URL
  else
    LblHomePage.Hide;
end;

procedure TTabSysEmu.lblHomePageClick(Sender: TObject);
begin
  ujUtilities.OpenHomePage(LblHomePage.Caption);
end;

end.
