unit ftabThumbBrowser;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, GraphicEx, Controls, Forms,
  Dialogs, ExtCtrls, JvExForms, JvCustomItemViewer,
  JCLStrings,
  JvImagesViewer, uMediaMiscTypes, fJWinFontForm;

type
  TtabThumbBrowser = class(TJWinFontForm)
    jvThumb: TJvImagesViewer;
    imgViewer: TImage;
    procedure imgViewerDblClick(Sender: TObject);
    procedure jvThumbDblClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
    Procedure AddFilesToThumbnails(FileList : TStrings; Opt : TJTabThumbNailOpt);
  end;

implementation

uses StdCtrls, ShellAPI, ujFile, uJImages, fMain, uQPCompObj;

{$R *.dfm}

Procedure TtabThumbBrowser.AddFilesToThumbnails(FileList : TStrings; Opt : TJTabThumbNailOpt);
var
  i : Integer;
  NewImg : TjvPictureItem;
  MyBmp : TBitmap;
  ImgStream : TMemoryStream;
  //Extended Graphicformats
  AExGraphicClass: TGraphicExGraphicClass;
  AExGraphic: TGraphicExGraphic;
  //Standard Graphicformats
  AGraphicClass : TGraphicClass;
  AGraphic : TGraphic;
  zipName, ImgName : String;
begin
  ImgViewer.Proportional := True;
  ImgViewer.Stretch := True;
  //clear existing images.
  if FileList.Count = 0 then
  begin
    //no files were found.. shit one.
    jvThumb.Clear;
    imgViewer.Picture.LoadFromFile(MainFrm.Settings.Paths.AppDir + 'noimagefound.jpg');
    ImgViewer.Show;
    jvThumb.Hide;
  end
  else
  if (FileList.Count = 1) and (ujimages.HasImageFileExt(FileList[0])) and (JCLStrings.Strcompare('.zip', ExtractFileExt(FileList.Names[i])) <> 0 ) then
  begin
    //theres only ONE image, display this.

    ImgViewer.OnDblClick := nil;  //disable the dblclick handler, no point in it.
    ImgViewer.Picture.LoadFromFile(FileList[0]);
    jvThumb.Hide;
    imgViewer.Show;
  end
  else
    if (FileList.Count > 0) then
    begin

      //configure the thumbnail viewer.
      jvThumb.Options.Height := Opt.Height;
      jvThumb.Options.Width := Opt.Width;
      jvThumb.Options.ShowCaptions := Opt.ShowCaption;
      jvThumb.Options.HorzSpacing := Opt.HorizontalGap;
      jvThumb.Options.VertSpacing := Opt.VerticalGap;
      if Opt.CaptionOnTop then
        jvThumb.Options.Layout := tlTop
      else
        jvThumb.Options.Layout := tlBottom;

      ImgViewer.OnDblClick := imgViewerDblClick; //re-enable the dbl click handler.
      jvThumb.BeginUpdate;
      try
        jvThumb.Count := FileList.Count;

        for i := 0 to FileList.Count-1 do
        begin
          if FileList.Names[i] <> '' then
          begin
            //the image is inside a zip file, in the format ZIPFILE=IMAGENAME
            ImgStream := TMemoryStream.Create;
            try
              ZipName := FileList.Names[i];
              ImgName := FileList.ValueFromIndex[i];
              uQPCompObj.Compression.UnCompressFileToStream(zipName, ImgName, ImgStream);
              if ImgStream.Size > 0 then
              begin
                AExGraphicClass := GraphicEx.FileFormatList.GraphicFromContent(ImgStream);
                if AExGraphicClass <> Nil then
                begin
                  AExGraphic := AExGraphicClass.Create;
                  try
                    //Load Extended Graphicformats
                    AExGraphic.LoadFromStream(ImgStream);
                    NewImg := jvThumb.Items[i];
                    // the full path is stored in Hint, this is a hack because when you try to set the filename
                    // the component tries to load it as a picture - and its not a picture!
                    NewImg.Hint := ImgName;
                    NewImg.Picture.Graphic := AExGraphic;
                    newImg.Caption := ImgName;
                  finally
                    FreeAndNil(AExGraphic);
                  end;
                end
                else
                begin
                  //Check for Standard Graphicformats
                  AGraphicClass := GraphicEx.FileFormatList.GraphicFromExtension(ujFile.GetVirtualFileExtension(ImgName));
                  if AGraphicClass <> Nil then
                  begin
                    AGraphic := AGraphicClass.Create;
                    try
                      //Load Standard Graphicformats
                      AGraphic.LoadFromStream(ImgStream);
                      NewImg := jvThumb.Items[i];
                      // the full path is stored in Hint, this is a hack because when you try to set the filename
                      // the component tries to load it as a picture - and its not a picture!
                      NewImg.Hint := ImgName;
                      NewImg.Picture.Graphic := AExGraphic;
                      newImg.Caption := ImgName;
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
          begin

            if ujImages.HasImageFileExt(FileList[i]) then
            begin
              //Add the image to the thumbs tree
              NewImg := jvThumb.Items[i];
              NewImg.Hint := FileList[i];
              NewImg.FileName := FileList[i];
            end
            else
            begin
              MyBmp := TBitmap.Create;
              try
                if ujFile.GetEXEIconAsBmp(MyBmp, FileList[i]) then
                begin
                  NewImg := jvThumb.Items[i];
                  // the full path is stored in Hint, this is a hack because when you try to set the filename
                  // the component tries to load it as a picture - and its not a picture!
                  NewImg.Hint := FileList[i];
                  NewImg.Picture.Bitmap.Assign(myBmp);
                  newImg.Caption := ExtractFileName(FileList[i]);
                end;
              finally
                FreeAndNil(MyBmp);
              end;
            end; //end of if file has image extension.

          end; //end of IF file in zip file

        end;

      finally
        //always make sure endupdate is called.
        jvThumb.EndUpdate;
      end;
      
    imgViewer.Hide;
    jvThumb.Show;
  end;        
end;


procedure TtabThumbBrowser.FormCreate(Sender: TObject);
begin
  jvThumb.Clear;
end;

procedure TtabThumbBrowser.jvThumbDblClick(Sender: TObject);
var
  theFile : String;
begin
  if jvThumb.SelectedIndex <> -1 then
  begin
    theFile := jvThumb.Items[jvThumb.SelectedIndex].Hint;
    if ujImages.HasImageFileExt(theFile) then
    begin
      //ImgViewer.Picture.LoadFromFile(theFile);
      ImgViewer.Picture.Assign(jvThumb.Items[jvThumb.SelectedIndex].Picture);
      jvThumb.Hide;
      ImgViewer.Show;
    end
    else
      ShellExecute(Handle, 'open', PChar(theFile), '', '', sw_Show);
  end;
end;

procedure TtabThumbBrowser.imgViewerDblClick(Sender: TObject);
begin
  ImgViewer.Hide;
  jvThumb.Show;
end;

end.
