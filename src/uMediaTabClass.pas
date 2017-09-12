unit uMediaTabClass;

interface

uses SysUtils, Classes, Graphics, Comctrls, uMediaMiscTypes, uROM;

type

  TJMediaTab = class(TObject)
  Protected
    _Caption : String;
    _Enabled : Boolean;
    _Paths : TStringList;
    _Found : TStringList;
    _SearchType : TJSearchType;
    _TabType : TJTabType;
    _SearchInROMPath : Boolean;
    _MAMEUseParentForSearch : Boolean;

    _ThumbOpt : TJTabThumbNailOpt;
    _ImagesOpt : TJTabImagesOpt;
    _TextOpt : TFont;

    //versioned save to stream methods
    procedure LoadFromStreamVersion1(aStream : TStream);
    
  public
    Constructor Create();
    Destructor Destroy();override;
	  procedure PopulateTabSimple(useTab : TTabSheet);

    procedure PopulateTab(useTab : TTabSheet; ROMObj : TQPROM; SettingsPath : String);
    procedure MameDatLookup(DatType : String; useTab : TTabSheet; ROMObj : TQPROM; SettingsPath : String);
    Procedure SearchForFiles(withROM : TQPROM);


    procedure LoadFromStream(aStream : TStream);
    procedure SaveToStream(aStream : TStream);

    Property Caption : String read _Caption write _Caption;
    Property Enabled : Boolean read _Enabled write _Enabled;
    Property FilesFound : TStringList read _Found write _Found;
    Property MAMEuseParentForSearch : Boolean read _MAMEUseParentForSearch write _MAMEUseParentForSearch;
    Property Paths : TStringList read _Paths write _Paths;
    Property SearchInROMPath : Boolean read _SearchInROMPath write _SearchInROMPath;
    Property SearchType : TJSearchType read _SearchType write _SearchType;
    Property TabType : TJTabType read _TabType write _TabType;

    Property ImageOpt : TJTabImagesOpt read _ImagesOpt write _ImagesOpt;
    Property ThumbOpt : TJTabThumbNailOpt read _ThumbOpt write _ThumbOpt;
    Property TextOpt : TFont read _TextOpt write _TextOpt;

  end;

implementation

uses Windows, FindFile,
     JCLStrings,
     ftabImageViewer, ftabTextOnly, ftabThumbBrowser,
     uJFile, uJImages, uQPCompObj;

// type for saving font to stream
type
  FontRec = packed record
    Color: TColor;
    LogFont: TLogFont;
  end;

{-----------------------------------------------------------------------------}
{ TJMediaTab } 
{-----------------------------------------------------------------------------}

Constructor TJMediaTab.Create();
begin
  inherited Create();
  _Paths := TStringList.Create;
  _Found := TStringList.Create;
  _TextOpt := TFont.Create;

  //create sensible default values where appropriate.
  _Enabled := False;
  _SearchType := jstExactMatch;
  _TabType := jtabImages;

  _ThumbOpt.Width := 120;
  _ThumbOpt.Height := 120;
  _ThumbOpt.HorizontalGap := 4;
  _ThumbOpt.VerticalGap := 4;
  _ThumbOpt.ShowCaption := True;
  _ThumbOpt.CaptionOnTop := False;

  _ImagesOpt.SlideShowEnabled := True;
  _ImagesOpt.SlideShowTimeout := 2;
  _ImagesOpt.ShowControlBar := True;
end;

{-----------------------------------------------------------------------------}

Destructor TJMediaTab.Destroy();
begin
  FreeAndNil(_Paths);
  FreeAndNil(_Found);
  FreeAndNil(_TextOpt);
  inherited Destroy();
end;

{-----------------------------------------------------------------------------}

procedure TJMediaTab.LoadFromStream(aStream : TStream);
var
  Version : Integer;
begin
  //get the version information from the stream.
  aStream.ReadBuffer(Version, SizeOf(Integer));

  //now call the relevant load version code.
  Case Version of
    1: LoadFromStreamVersion1(aStream);
    else
      Exception.Create('Invalid Stream version number');
  end;
end;

{-----------------------------------------------------------------------------}

procedure TJMediaTab.LoadFromStreamVersion1(aStream : TStream);
var
  Len : Integer;
  tmpStream : TMemoryStream;
  fRec : Fontrec;
begin
  // Load version 1 type streams.  The version information has already been
  // read so start streaming in data.

  // _Caption
  aStream.ReadBuffer(Len, SizeOf(Integer));
  if Len > 0 then
  begin
    SetLength(_Caption, Len);
    aStream.ReadBuffer(_Caption[1], Len);
  end;

  aStream.ReadBuffer(_Enabled , SizeOf(Boolean));
  aStream.ReadBuffer(_MAMEUseParentForSearch , SizeOf(Boolean));
  aStream.ReadBuffer(_SearchType , SizeOf(TJSearchType));
  aStream.ReadBuffer(_TabType , SizeOf(TJTabType));
  aStream.ReadBuffer(_SearchInROMPath , SizeOf(Boolean));

  //load in the paths.
  tmpStream := TMemoryStream.Create;
  try
    _Paths.Clear;
    aStream.ReadBuffer(Len, SizeOf(Integer));
    if Len > 0 then
    begin

     // aStream.ReadBuffer(tmpStream, Len);
     tmpStream.CopyFrom(aStream, Len);
      tmpStream.Position := 0;
      _Paths.LoadFromStream(tmpStream);
    end;
  finally
    FReeAndNil(tmpStream);
  end;

  aStream.ReadBuffer(_ThumbOpt, SizeOf(TJTabThumbNailOpt));
  aStream.ReadBuffer(_ImagesOpt, SizeOf(TJTabImagesOpt));

  aStream.ReadBuffer(Len, SizeOf(Integer));
  if Len = SizeOf(fRec.LogFont) then
  begin
    aStream.ReadBuffer(fRec, SizeOf(fRec));
    _TextOpt.Handle := CreateFontIndirect(fRec.LogFont);
    _TextOpt.Color := fRec.Color;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TJMediaTab.SaveToStream(aStream : TStream);
var
  str1,str2,str3 : String;
  Version, Len, len2  : Integer;
  tmpStream : TMemoryStream;
  fRec : FontRec;
begin
  Version := 1;
  //save version information
  aStream.WriteBuffer(Version, SizeOf(Integer));

  //now stream out all the settings.
  Len := Length(_Caption);
  aStream.WriteBuffer(Len, SizeOf(Integer));
  if Len > 0 then
    aStream.WriteBuffer(_Caption[1], Len);

  aStream.WriteBuffer(_Enabled, SizeOf(Boolean));
  aStream.WriteBuffer(_MAMEUseParentForSearch, SizeOf(Boolean));
  aStream.WriteBuffer(_SearchType, SizeOf(TJSearchType));
  aStream.WriteBuffer(_TabType, SizeOf(TJTabType));
  aStream.WriteBuffer(_SearchInROMPath, SizeOf(Boolean));

  //get the paths list in a stream
  tmpStream := TMemoryStream.Create;
  try

    _Paths.SaveToStream(tmpStream);
    tmpStream.Position := 0;
    Len := tmpStream.Size;

    aStream.WriteBuffer(Len, SizeOf(Integer));
    if Len > 0 then
      aStream.CopyFrom(tmpStream, Len);
  finally
    FreeAndNil(tmpStream);
  end;

  //save the thumboptions
  aStream.WriteBuffer(_ThumbOpt, SizeOf(TJTabThumbNailOpt));

  //save the image options
  aStream.WriteBuffer(_ImagesOpt, SizeOf(TJTabImagesOpt));

  //now save the font.
  Len := SizeOf(fRec.LogFont);
  if Windows.GetObject(_TextOpt.Handle, len, @fRec.LogFont) > 0 then
  begin
    aStream.WriteBuffer(Len, SizeOf(Integer));
    fRec.Color := _TextOpt.Color;
    aStream.WriteBuffer(fRec, SizeOf(fRec));
  end
  else
  begin
    //the font is nil, dont save a thing.
    Len := 0;
    aStream.WriteBuffer(Len, SizeOf(Integer));
  end;

end;

{-----------------------------------------------------------------------------}
procedure TJMediaTab.PopulateTabSimple(useTab : TTabSheet);
var
//ok added this function. try to call it from the main then see if we can populate an image.
  TmpStrings : TStrings;
  pth,fileName : string;
  i : Integer;
  found : TStringList;
  imagesOpt : TJTabImagesOpt;

begin
  imagesOpt.SlideShowEnabled := True;
  imagesOpt.SlideShowTimeout := 2;
  imagesOpt.ShowControlBar := True;
  found := TStringList.Create;
  found.LoadFromFile('D:\quickplay\src\images\a.bmp');
	TTabImageViewer(useTab.Controls[0]).LoadImages(found, imagesOpt);
end;

procedure TJMediaTab.MameDatLookup(DatType : String; useTab : TTabSheet; ROMObj : TQPROM; SettingsPath : String);
var
   TmpStrings : TStrings;
  pth,fileName : string;
  i : Integer;
begin
 begin
      tmpStrings := TStringList.Create;
      pth := SettingsPath ;   //defult
      fileName := DatType + '.dat';//default
      if _Paths.Count > 0 then
      begin
       if (JCLStrings.Strcompare('.dat', ExtractFileExt(_Paths[i] )) =0 ) then
       begin
        fileName := ExtractFileName(_Paths[i]) ;//default   //laod the specified dat file.
        pth :=   ExtractFilePath(_Paths[i]);
       end

       // see notepad++ for reading zips    "thumb browser " see shit one

       // here is how its done, satisfy these vars.
       //       zContents.Clear;
       //       uQPCompObj.Compression.ListContentsOfFile(zContents, _Paths[i]);

       //else if (JCLStrings.Strcompare('.zip', ExtractFileExt(_Paths[i] )) =0 ) then
       //begin
       // fileName := ExtractFileName(_Paths[i]) ;
       // pth :=   ExtractFilePath(_Paths[i]);
       //end

       else
        pth := _Paths[0] + '\';    //user pref
      end;

      try

        if FileExists(pth + fileName) then
          ROMObj.GetMAMEDatEntryFromFile(DatType, tmpStrings, pth + fileName)
        else
        begin
          tmpStrings.Add( DatType + ' File not found.  You can download it from:');
          tmpStrings.Add('http://www.mameworld.info/mameinfo/');
          tmpStrings.Add('and then copy the file to the DATS directory');
        end;
        tTabTextOnly(useTab.Controls[0]).LoadText(tmpStrings, _TextOpt);
      finally
        FreeAndNil(tmpStrings);
      end;
    end;
end;

procedure TJMediaTab.PopulateTab(useTab : TTabSheet; ROMObj : TQPROM; SettingsPath : String);
var
  TmpStrings : TStrings;
  pth,fileName : string;
  i : Integer;
begin
  Case Self.TabType of
    jtabImages :
    begin
      SearchForFiles(ROMObj);
      //if its a FILE ON DISK, make sure its an image.
      for i := _Found.Count-1 downto 0 do
        if (_Found.Names[i] = '') and
           (ujImages.HasImageFileExt(_Found[i]) = False) then
          _Found.Delete(i);

       TTabImageViewer(useTab.Controls[0]).LoadImages(_Found, _ImagesOpt);
    end;

    jtabMameInfo :
    begin
        MameDatLookup('mameinfo', useTab, ROMObj, SettingsPath);
    end;

    jtabMameHistory :
    begin
        MameDatLookup('history', useTab, ROMObj, SettingsPath);
    end;

    jtabThumbnail :
    begin
      SearchForFiles(ROMObj);
      TtabThumbBrowser(useTab.Controls[0]).AddFilesToThumbnails(_Found, _ThumbOpt);
    end;
  end;
end;

{-----------------------------------------------------------------------------}

Procedure TJMediaTab.SearchForFiles(withROM : TQPROM);
var
  FindObj : ThhFindFile;
  i, e : integer;
  fl : string;
  bl : bool;
  zContents : TStrings;
begin

  _Found.Clear;
  //_Found.Add('D:\Gaming\Emulation\Media\MAME\marquees\marquees.zip=005.png');
  FindObj := ThhFindFile.Create(nil);
  try
    FindObj.Recurse := False;

    If withROM.MAMEname <> '' then
    begin
      if (_MAMEUseParentForSearch) and (withROM.ParentName <> '') then
        FindObj.Filter := withROM.ParentName
      else
        FindObj.Filter := withROM.MAMEname;
    end
    else
      FindObj.Filter := withROM.FileNameNoExt;

    Case _SearchType of
      jstExactMatch: FindObj.Filter := FindObj.Filter+'.*';
      jstStartsWith: FindObj.Filter := FindObj.Filter+'*.*';
      jstInString: FindObj.Filter := '*' + FindObj.Filter + '*.*';
      jstAllFilesInDir : FindObj.Filter := '*.*';
    end;

    zContents := TStringList.Create;
    try
      For i := 0 to _Paths.Count-1 do
      begin
        // could be used to search for a ziped screen shot, not a zip of them all
        //fl :=    _Paths[i] + '\' + withROM.name + '.zip';
        // if (FileExists( fl ) ) then

        //this is if you added a zip for a path, se we will not look in zip files.
        if (JCLStrings.Strcompare('.zip', ExtractFileExt(_Paths[i] )) =0 ) then
        begin
          //its a zip file.  check inside the archive for matches.
          zContents.Clear;
          uQPCompObj.Compression.ListContentsOfFile(zContents, _Paths[i]);
          //now we have a time consuming loop through all contents of the file.. ouch.
          for e := 0 to zContents.Count - 1 do
          begin
          //see if the zCont plus a * matches the filter.
             if CompareText (FindObj.Filter, ChangeFileExt(zContents[e], '')+'.*' ) = 0 then
             _Found.Add(_Paths[i] + '=' + zContents[e]);
          end;
        end
        else
        if DirectoryExists(_Paths[i]) then
        begin
          FindObj.Directory := _Paths[i];
          FindObj.Execute;
          _Found.AddStrings(FindObj.Files);
        end;
      end;
    finally
      FreeAndNil(zContents);
    end;

    //check if we are to search in the roms path too.
    if Self._SearchInROMPath then
    begin
      FindObj.Directory := ExtractFilePath(withROM.Path);
      if FindObj.Directory <> '' then
      begin
        FindObj.Execute;
        _Found.AddStrings(FindObj.Files);
      end;
    end;

  finally
    FreeAndNil(FindObj);
  end;
end;

{-----------------------------------------------------------------------------}

end.
