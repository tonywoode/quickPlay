{
This is a dopey unit which holds a Compression object.  Its main role in life
is to hold onto a compression object, so that we add this to any USES clauses
instead of the mainform.

The application is responsible for initializing AND destroying this object.
}

unit uQPCompObj;

interface

uses SysUtils, Classes, ujCompression;

Type
  TQPCompressObj = class(TJCompression)
  public
    Function UnCompressROM(input : TFileName; OutDir : String; var FilesUncompressed : TStringList) : String;
  end;

var
  Compression : TQPCompressObj;

implementation

uses JCLStrings,
     ujCompressResourceStrs, fCompressFilePicker,
     ujFile;

{-----------------------------------------------------------------------------}

Function TQPCompressObj.UnCompressROM(input : TFileName; OutDir : String; var FilesUncompressed : TStringList) : String;
var
  I : Integer;
  MyCompress : IJCompressible;
  FileExt : String;
  Contents, Picker : TStrings;
  PickerFrm : TFrmCompressPicker;
  Filter : String;
begin
  //find the compressor to use for this file.
  Result := '';
  
  MyCompress := IJCompressibleByFileName(input, cmRead);
  if MyCompress <> nil then
  begin
    if (MyCompress.CurrentMode in [cmRead, cmFull]) = False then
      raise EJCompressException.Create(MyCompress.FullName + COMP_NO_READING);
  end
  else
    raise EJCompressException.Create(COMP_FORMAT_UNSUPPORTED);   

  // if we are still in the function then we have a valid archive uncompressor.
  Contents := TStringList.Create;
  try
    Self.ListContentsOfFile(Contents, Input);

    Filter := '';
    //now work out what to do based on the contents of the archive.

    case Contents.Count of
      0 : raise EJCompressException.Create(COMP_ARCHIVE_EMPTY);
      1 : Filter := '*.*'; //only one file in the archive, uncompress it.
      else
      begin
        //more than one file, ask the user to select the ROM
        Picker := TStringList.Create;
        try
          PickerFrm := TFrmCompressPicker.Create(nil);
          PickerFrm.ArchiveName := input;

          For i := 0 to Contents.Count-1 do
          begin

            // get rid of "text-file" file extensions..
            FileExt := ujFile.GetVirtualFileExtension(Contents[i]);
           // FileExt := Lowercase(ExtractFileExt(Contents[i]));
            If (JCLStrings.StrCompare(FileExt, '.txt')=0) or
               (JCLStrings.StrCompare(FileExt, '.nfo')=0) or
               (JCLStrings.StrCompare(FileExt, '.diz')=0) then
              continue
            else
              Picker.Add(Contents[i])
          end;   //end of FOR contents.count loop

          Case Picker.Count of
            0: //this should NEVER fire, it means an archive is full of text files?
            begin
              PickerFrm.addFiles(Contents);
              if PickerFrm.ShowModal = 1 then
                Filter := PickerFrm.SelectedFileName
              else
                //user has chosen to abort.
                Filter := '';
            end;
            1 : Filter := Picker[0];
            else
            begin
              PickerFrm.addFiles(Picker);
              if PickerFrm.ShowModal = 1 then
                Filter := PickerFrm.SelectedFileName
              else
                //user has chosen to abort.
                Filter := '';
            end;
          end;//end of CASE statement

        finally
          FreeAndNil(PickerFrm);
          FreeAndNil(Picker);
        end;
      end;
    end;

    if Filter <> '' then
    begin
      Self.UnCompressFile(input, IncludeTrailingPathDelimiter(OutDir), False, False, True, FilesUncompressed, Filter);
      if FilesUncompressed.Count > 0 then
        Result := FilesUncompressed[0]
      else
        raise EJCompressException.Create(COMP_NO_FILES_EXTRACTED);
    end
    else
      Result := '';
   {
    //now check how many files got extracted
    Case FilesUncompressed.Count of
      0 : raise EJCompressException.Create(COMP_NO_FILES_EXTRACTED);
      1 : Result := OutDir + ExtractFileName(FilesUncompressed[0]);
      else  //more than 1 file was extracted try to guess which is the ROM.  Probably the biggest file will be the ROM.
      begin

        Picker := TStringList.Create;
        try
          PickerFrm := TFrmCompressPicker.Create(nil);

          For i := 0 to FilesUncompressed.Count-1 do
          begin
            // get rid of text-like file extensions..
            FileExt := Lowercase(ExtractFileExt(FilesUncompressed[i]));
            If (FileExt = '.txt') or (FileExt = '.nfo') or (FileExt = '.diz') then
              continue
            else
              Picker.Add(FilesUncompressed[i])

          end;

          Case Picker.Count of
            0:
            begin
              PickerFrm.addFiles(FilesUncompressed);
              if PickerFrm.ShowModal = 1 then
                Result := PickerFrm.SelectedFileName
              else
                //user has chosen to abort.
                Result := '';
            end;
            1 : Result := Picker[0];
            else
            begin
              PickerFrm.addFiles(Picker);
              if PickerFrm.ShowModal = 1 then
                Result := PickerFrm.SelectedFileName
              else
                //user has chosen to abort.
                Result := '';
            end;
          end;//end of CASE statement

        finally
          FreeAndNil(PickerFrm);
          FreeAndNil(Picker);
        end;

      end; //end of ELSE more than 1
    end; //end of CASE statement
                    }
  finally
    FreeAndNil(Contents);
  end;
end;     

end.
