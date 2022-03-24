unit Unit1;
// Demo for reading from Zip Stream by Nikolaj Olsson (nikse@e-mail.dk)
// amended April 11, 2005 R.Peters

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  ExtCtrls, StdCtrls, Buttons, ZipMstr;

type
  TForm1 = class(TForm)
    Image1: TImage;
    StaticText1: TStaticText;
    ZipMaster1: TZipMaster;
    BtnPic1: TButton;
    BtnPic2: TButton;
    BtnPic3: TButton;
    procedure UnzipToImage(filename : string);
    procedure BtnPic3Click(Sender: TObject);
    procedure BtnPic1Click(Sender: TObject);
    procedure BtnPic2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  Stream1 : TZipstream;

implementation

{$R *.DFM}      
{$R ImageStream.Manifest.res ImageStream.Manifest.rc}

procedure TForm1.UnzipToImage(filename : string);
begin
  if not ZipMaster1.{Unz}Busy then
  begin
    ZipMaster1.ZipFileName:= 'resource.zip';
    if ZipMaster1.Count > 0 then
    begin
      ZipMaster1.Password:='password';
      Stream1 := ZipMaster1.ExtractFileToStream(filename);
      Stream1.Position := 0;      // reset to the beginning of the stream
      StaticText1.Caption:='File Size: '+ IntToStr(Stream1.Size);
      Image1.Picture.Bitmap.LoadFromStream(Stream1);
    end
    else
      StaticText1.Caption:='resource.zip not found or empty';
  end;
end;

procedure TForm1.BtnPic3Click(Sender: TObject);
begin
  UnzipToImage('eye.bmp');
end;

procedure TForm1.BtnPic1Click(Sender: TObject);
begin
  UnzipToImage('paintbrush.bmp');
end;

procedure TForm1.BtnPic2Click(Sender: TObject);
begin
  UnzipToImage('Spectrum.bmp');
end;

end.
