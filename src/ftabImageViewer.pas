unit ftabImageViewer;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, uMediaMiscTypes, GraphicEx, StdCtrls, fJWinFontForm, axctrls ,JvGif;

type
  TtabImageViewer = class(TJWinFontForm)
    imgViewer: TImage;
    PanImgControls: TPanel;
    ImgBack: TImage;
    ImgNext: TImage;
    TimerImgs: TTimer;
    lblImageCount: TLabel;
    procedure ImgBackClick(Sender: TObject);
    procedure ImgNextClick(Sender: TObject);
    procedure TimerImgsTimer(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
    _CurrentIndex : Integer;
    procedure ChangePicture(Index : Integer);
  public
    { Public declarations }
    ImageList : TStringList;
    procedure LoadImages(inFiles : TStrings; Opt : TJTabImagesOpt);
  end;

implementation

uses fMain, ujImages, uQPCompObj, ujFile;

{$R *.dfm}

{-----------------------------------------------------------------------------}

procedure TtabImageViewer.ChangePicture(Index : Integer);
var
  Ext:string;
  ImgStream : TMemoryStream;
  graphic : TOleGraphic;//for gifs
  //Extended Graphicformats
  AExGraphicClass: TGraphicExGraphicClass;
  AExGraphic: TGraphicExGraphic;
  //Standard Graphicformats
  AGraphicClass : TGraphicClass;
  AGraphic : TGraphic;
begin
  if ImageList.Names[Index] <> '' then
  begin
    //the image is inside a zip file, in the format ZIPFILE=IMAGENAME
    ImgStream := TMemoryStream.Create;
    try
      uQPCompObj.Compression.UnCompressFileToStream(ImageList.Names[Index], ImageList.ValueFromIndex[Index], ImgStream);
      if ImgStream.Size > 0 then
      begin
        AExGraphicClass := GraphicEx.FileFormatList.GraphicFromContent(ImgStream);
        if AExGraphicClass <> Nil then
        begin
          AExGraphic := AExGraphicClass.Create;
          try
            //Load Extended Graphicformats
            AExGraphic.LoadFromStream(ImgStream);
            ImgViewer.Picture.Graphic := AExGraphic;
          finally
            FreeAndNil(AExGraphic);
          end;
        end
        else
        begin
          //Check for Standard Graphicformats
          AGraphicClass := GraphicEx.FileFormatList.GraphicFromExtension(ujFile.GetVirtualFileExtension(ImageList.ValueFromIndex[Index]));
          if AGraphicClass <> Nil then
          begin
            AGraphic := AGraphicClass.Create;
            try
              //Load Standard Graphicformats
              AGraphic.LoadFromStream(ImgStream);
              ImgViewer.Picture.Graphic := AGraphic;
            finally
              FreeAndNil(AGraphic);
            end;
          end;
        end;
      end;
    finally
      FreeAndNil(ImgStream);
    end;
  end
  else
  //its a straight image, just load it from disk.
  begin;
        imgViewer.Picture.LoadFromFile(ImageList[Index]);
  end;
  lblImageCount.Caption := Format('%d of %d', [Index+1, ImageList.Count]);
end;

{-----------------------------------------------------------------------------}

procedure TtabImageViewer.LoadImages(inFiles : TStrings; Opt : TJTabImagesOpt);
begin
  ImageList.Clear;
  ImageList.Assign(inFiles);

  if ImageList.Count = 0 then
  begin
    //no images found, load the 'no images thing'
    imgViewer.Picture.LoadFromFile(MainFrm.Settings.Paths.AppDir + 'noimagefound.jpg');
    PanImgControls.Hide;
    TimerImgs.Enabled := False;
  end
  else
  begin
    //load the first image found.
    _CurrentIndex := 0;
    ChangePicture(_CurrentIndex);
    if Opt.ShowControlBar then
      PanImgControls.Show
    else
      PanImgControls.Hide;

    if Opt.SlideShowEnabled then
    begin
      TimerImgs.Interval := Opt.SlideShowTimeout * 1000;
      TimerImgs.Enabled := True;
    end
    else
      TimerImgs.Enabled := False;
  end;

end;

{-----------------------------------------------------------------------------}

procedure TtabImageViewer.FormCreate(Sender: TObject);
begin
  ImageList := TStringList.Create;
end;

{-----------------------------------------------------------------------------}

procedure TtabImageViewer.FormDestroy(Sender: TObject);
begin
  FreeAndNil(ImageList);
end;

{-----------------------------------------------------------------------------}

procedure TtabImageViewer.TimerImgsTimer(Sender: TObject);
begin
  if ImageList.Count > 1 then
  begin
    //check whether moving to the next image will need to loop around in the list.
    if _CurrentIndex + 1 > ImageList.Count-1 then
      _CurrentIndex := 0
    else
      _CurrentIndex := _CurrentIndex +1;

    ChangePicture(_CurrentIndex);
  end
  else
    TimerImgs.Enabled := False;
end;

{-----------------------------------------------------------------------------}

procedure TtabImageViewer.ImgNextClick(Sender: TObject);
begin
  if ImageList.Count > 1 then
  begin
    //check whether moving to the next image will need to loop around in the list.
    if _CurrentIndex + 1 > ImageList.Count-1 then
      _CurrentIndex := 0
    else
      _CurrentIndex := _CurrentIndex +1;

    ChangePicture(_CurrentIndex);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TtabImageViewer.ImgBackClick(Sender: TObject);
begin
    if ImageList.Count > 1 then
  begin
    //check whether moving to the next image will need to loop around in the list.
    if _CurrentIndex - 1 < 0 then
      _CurrentIndex := ImageList.Count-1
    else
      _CurrentIndex := _CurrentIndex -1;

    ChangePicture(_CurrentIndex);
  end;
end;

{-----------------------------------------------------------------------------}

end.
