unit ujImages;

interface

uses SysUtils;

procedure Bmp2Jpeg(const BmpFileName, JpgFileName: string);
procedure Jpeg2Bmp(const BmpFileName, JpgFileName: string);
Function HasImageFileExt(InFile : TFileName) : Boolean;

implementation

uses Graphics, Jpeg,
     JCLStrings;

{-----------------------------------------------------------------------------}

procedure Bmp2Jpeg(const BmpFileName, JpgFileName: string);
var
  Bmp: TBitmap;
  Jpg: TJPEGImage;
begin
  Bmp := TBitmap.Create;
  Jpg := TJPEGImage.Create;
  try
    Bmp.LoadFromFile(BmpFileName);
    Jpg.Assign(Bmp);
    Jpg.SaveToFile(JpgFileName);
  finally
    Jpg.Free;
    Bmp.Free;
  end;
end;

{-----------------------------------------------------------------------------}

procedure Jpeg2Bmp(const BmpFileName, JpgFileName: string);
var
  Bmp: TBitmap;
  Jpg: TJPEGImage;
begin
  Bmp := TBitmap.Create;
  Jpg := TJPEGImage.Create;
  try
    Jpg.LoadFromFile(JpgFileName);
    Bmp.Assign(Jpg);
    Bmp.SaveToFile(BmpFileName);
  finally
    Jpg.Free;
    Bmp.Free;
  end;
end;

{-----------------------------------------------------------------------------}

Function HasImageFileExt(InFile : TFileName) : Boolean;
const
  ImageExts : Array [0..11] of string = ('.png', '.gif', '.jpg', '.jpeg', '.jpe', '.jif', '.jfif', '.bmp', '.dib', '.rle', '.tiff', '.wmf');
var
  i : Integer;
begin
  Result := False;
  For i := 0 to 11 do
    if JCLStrings.StrCompare(ExtractFileExt(InFile), ImageExts[i]) = 0 then
    begin
      Result := True;
      break;
    end;
end;

{-----------------------------------------------------------------------------}

end.
