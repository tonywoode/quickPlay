unit uRom;

interface

uses SysUtils, IniFiles, Classes, Contnrs, uExeList, uQPConst, uQPMiscTypes;

type

  TQPIPS = class(TObject)
  private
    _Index : Integer;
    _Name : string;
    _Path : TFileName;
    _Default : Boolean;
  Published
    Property ipsIndex : Integer read _Index write _Index;
    Property IPSname : String read _Name write _Name;
    Property IPSpath : TFileName read _Path write _Path;
    Property IsDefault : boolean read _Default write _Default;
  end;

  TQPExportOpt = Record
    AddName : Boolean;
    AddPath : Boolean;
    AddEmu : Boolean;
    AddWWW : Boolean;
    AddYear : Boolean;
    AddType : Boolean;
    AddLanguage : Boolean;
    AddRating : Boolean;                        
    AddPlayers : Boolean;
  end;

  TQPRom = class(TObject)
  protected
    _name, //this is the name used for display purposes
    _MAMEName, //Used Internally mainly for managing MAME clones.
    _ParentName, //Used Internally for storing the Parent of a Clone.
    _ZipName, //Used Internally to store which file inside a zip file is the ROM
    _path, //the path to the rom.
    _emulator, //the Emulator this rom is linked to
    _Company, //The company who made the game.
    _Year,     //the year this ROM first came out
    _GameType, //The type of game
    _MultiPlayer,  //The type of Multiplayer game.
    _Rating,   //A user rating.
    _Language, //The language of this ROM
    _Comment, //Any miscellaneous comments you might want to store.
    _Parameters : String; //Any additional paramters to be used when running
    _ParamMode : TROMParametersMode; //type of parameter mode
    _NumPlay : integer;   //The amount of times this rom has been played
    _DefaultGoodMerge : String; //The user selected default GoodMerge ROM

    _IPS : TObjectList;

    //the following are only used internally and are not saved.  No direct editing is allowed!
    _CompressedFiles : TStringList;
    _IconIndex : Integer; //Used Internally to manage the ROMs iconindex - for MAME roms mostly.
    _Exists : Integer; //Used Internally to speed up VTRom Image finding. 1 - Exists 0 - No -1 - Not set.

    Function GetFileNameNoExt() : String;
    Function GetSummary() : String;
    Function GetDefaultIPSIndex() : Integer;
    procedure SetDefaultIPSIndex(value : Integer);
    function GetIPS(Index: Integer): TQPIPS;
    procedure SetIPS(Index: Integer; AObject: TQPIPS);
    Function GetIPSCount() : Integer;

  public
    Constructor Create(); overload;
    Constructor Create(asString : String);overload;
    Constructor Create(asString : String; LegacyConvert : Boolean);overload;
    destructor Destroy();override;

    property Name:String read _Name write _Name;
    Property MAMEName : String read _MAMEName write _MAMEName;
    Property ParentName : String Read _ParentName write _ParentName;
    Property ZipName : String Read _ZipName write _ZipName;
    property Path:String read _Path write _path;
    property Emulator:String read _emulator write _emulator;
    Property Company : String read _Company write _Company;
    property Year:String read _Year write _Year;
    property GameType:String read _GameType write _GameType;
    Property Multiplayer : String Read _Multiplayer write _Multiplayer;
    property Rating:String read _Rating write _Rating;
    property Language:String read _Language write _Language;
    property Parameters:String read _Parameters write _Parameters;
    Property ParameterMode : TROMParametersMode read _ParamMode write _ParamMode;
    Property Comment : String read _Comment write _Comment;
    property NumPlay:Integer read _NumPlay write _NumPlay;
    Property DefaultGoodMerge : String read _DefaultGoodMerge write _DefaultGoodMerge; 

    //IPS related
    Property DefaultIPSIndex : Integer read GetDefaultIPSIndex write SetDefaultIPSIndex;
    property IPS[index: Integer]: TQPIPS read GetIPS write SetIPS;
    Property IPSCount : Integer read GetIPSCount;

    Property FileNameNoExt : String Read GetFileNameNoExt;

    //Internally used properties
    property IconIndex:Integer read _IconIndex write _IconIndex;
    Property Exists : Integer read _Exists write _Exists;
    Property CompressedFiles : TStringList read _CompressedFiles write _CompressedFiles;
    //This returns a nicely formatted description of the ROMs properties.  for use in a hint *)
    Property Summary : String Read GetSummary;

    procedure Assign(Source : TQPRom);
    Function AddIPS(Name : String; Path : TFileName; Default : Boolean) : Integer;
    procedure BrowseToROM();
    Function CreateIPSROM(ROMPath, IPSPath : TFileName; ExtrDir : String; CustomName : String = '') : TFileName;
    procedure DeleteIPS(Index : Integer);
    procedure FromString(strRom : String);
    Procedure GetMAMEHistoryFromFile(var Output : TStrings; HistoryFile : TFileName);
    Procedure GetMAMEInfoFromFile(var Output : TStrings; MAMEInfoFile : TFileName);
    procedure GuessGoodMerge( Pref1, Pref2, Pref3 : String);
    procedure LegacyFromString(strRom : String);
    Function MatchesQuery(Query : TObjectList; MatchAll : Boolean) : Boolean;
    procedure RenameFile(NewName : String);
    procedure RunIPS(Emu : TObject; IPSIndex : Integer; Tools : TQPExeList; RunOpt :TQPRunOptions);
    Procedure SetLanguage(); 
    Procedure SetMameGameCategory(Ini : TMemIniFile);
    Procedure SetMameGameLanguage(Ini : TMemIniFile);
    procedure SetMameMultiplayer(Ini : TMemIniFile);
    Procedure ToCSV(var CodeList : TStrings; Opt : TQPExportOpt);
    Procedure ToHTML(var CodeList : TStrings; EList : TObjectList; Opt : TQPExportOpt);
    Function ToString() : String;
    Procedure ToXML(var CodeList : TStrings; EList : TObjectList; Opt : TQPExportOpt);

  end;

  PQPROM = ^TQPROM;

implementation

{$I Compilers.inc}

uses Windows, Controls, JCLShell, JCLStrings, uIPSpatch, uJUtilities,
      uJFile, uEmu, FindFile, uEmuList, uQuery, uJCompression,
      fCompressFilePicker, uQPCompObj, ujMiscResourceStrs, ujCompressResourceStrs;

{ TQPRom }

constructor TQPROM.Create();
begin
  inherited Create();
  _IPS := TObjectList.Create(True);
  _CompressedFiles := TStringList.Create;
  _ParamMode := ParamAfter;
end;

Constructor TQPRom.Create(asString : String);
begin
  inherited Create();
  _IPS := TObjectList.Create(True);
  Self.FromString(asString);
  _CompressedFiles := TStringList.Create;
end;

Constructor TQPRom.Create(asString : String; LegacyConvert : Boolean);
begin
  inherited Create();
  //if we are here then its a legacy load job... use the specific LegacyFROMString code
  _IPS := TObjectList.Create(True);
  _CompressedFiles := TStringList.Create;
  Self.LegacyFromString(asString);
end;

destructor TQPROM.Destroy();
begin
  FreeAndNil(_CompressedFiles);
  FreeAndNil(_IPS);
  inherited Destroy;
end;

procedure TQPRom.Assign(Source : TQPRom);
var
  i, New : Integer;
begin
  _name := Source.Name;
  _MAMEname := Source.MAMEname;
  _ParentName := Source.ParentName;
  _ZipName := Source.ZipName;
  _path := Source.Path;
  _emulator := Source.Emulator;
  _Year := Source.Year;
  _GameType := Source.GameType;
  _MultiPlayer := Source.Multiplayer;
  _Rating := Source.Rating;
  _Language := Source.Language;
  _Parameters := Source.Parameters;
  _ParamMode := Source.ParameterMode;
  _NumPlay := Source.NumPlay;
  _ParamMode := Source.ParameterMode;
  _IconIndex := Source.IconIndex;
  _Exists := Source.Exists;
  _Company := Source.Company;
  _Comment := Source.Comment;
  _DefaultGoodMerge := Source.DefaultGoodMerge;
  //IPS := Copy(Source.IPS);  for some reason this line caused a L681 internal error

  _IPS.Clear;
  _IPS.Capacity := Source.IPSCount;
  for i := 0 to Source.IPSCount-1 do
  begin
    New := _IPS.Add(TQPIPS.Create);
    Self.IPS[New].IPSIndex := Source.IPS[i].IPSIndex;
    Self.IPS[New].IPSName := Source.IPS[i].IPSName;
    Self.IPS[New].IPSPath := Source.IPS[i].IPSPath;
    Self.IPS[New].IsDefault := Source.IPS[i].IsDefault;
  end;    
end;

{-----------------------------------------------------------------------------}

Function TQPROM.AddIPS(Name : String; Path : TFileName; Default : Boolean) : Integer;
var
  NewIndex : Integer;
begin
  NewIndex := _IPS.Add(TQPIPS.Create);
  IPS[NewIndex].ipsIndex := NewIndex;
  IPS[NewIndex].IPSname := Name;
  IPS[NewIndex].IPSpath := Path;
  IPS[NewIndex].IsDefault := Default;
  Result := NewIndex;
end;

{-----------------------------------------------------------------------------}

procedure TQPROM.BrowseToROM();
begin
  if DirectoryExists(ExtractFilePath(_Path)) then
    JCLShell.ShellExecEx(ExtractFilePath(_path))
  else
    raise EJException.create(J_DIRECTORY_NOT_EXIST);
end;

{-----------------------------------------------------------------------------}

Function TQPROM.CreateIPSROM(ROMPath, IPSPath : TFileName; ExtrDir : String; CustomName : String = '') : TFileName;
var
  rContents, iContents : TStringList;
  newROM, newIPS, newName : TFileName;
  iFilter : String;
  Patcher : TIPSPatcher;
  i : integer;
  Pick : TFrmCompressPicker;
begin

  //check that IPS file actually exists!
  if not FileExists(IPSPath) then
    raise EJException.Create(QP_IPS_NOT_FOUND);

  //check that the ROM file exists.
  if not FileExists(ROMPath) then
    raise EJException.Create(QP_ROM_NOT_FOUND);

  //create the stringlists for holding uncompressed ROMS/IPS if needed
  rContents := TStringList.Create;
  try
    iContents := TStringList.Create;

    //check if the ROM is compressed.
    if uQPCompObj.Compression.SupportsFileName(ROMPath, cmRead) then
      newROM := uQPCompObj.Compression.UnCompressROM(ROMPath, ExtrDir, rContents)
    else
      newROM := ROMPath;

    //check if the IPS patch is compressed.
    if uQPCompObj.Compression.SupportsFileName(IPSPath, cmRead) then
    begin
      //get the contents of the compressed IPS file.
      uQPCompObj.Compression.ListContentsOfFile(TStrings(iContents), IPSPath);

      if iContents.Count = 1 then
        //if theres only one file, then uncompress it.
        uQPCompObj.Compression.UnCompressFile(IPSPath, ExtractFilePath(IPSPath), false, false, true, iContents, '*.ips')
      else
      begin
        //theres more than one file inside this archive.  determine if there is more than one IPS file.
        for i := iContents.Count-1 downto 0 do
          if JCLStrings.StrCompare(ujFile.GetVirtualFileExtension(iContents[i]), '.ips') <> 0 then
            iContents.Delete(i);

        //now see how many IPS files are left.
        iFilter := '';
        Case iContents.Count of
          0 : raise EJException.Create(QP_IPS_NONE_IN_COMPRESSED);
          1 : iFilter := iContents[0];
          else
          begin
            //archive contains more than one ips file, ask the user to select which one they want to use.
            Pick := TFrmCompressPicker.Create(nil);
            try
              Pick.FormCaption := 'Please choose an IPS file to use.';
              Pick.addFiles(iContents);
              if Pick.ShowModal = mrOK then
              begin
                iFilter := Pick.SelectedFileName;
              end
              else
                //user has chosen to abort.
                raise EJException.Create(J_OPERATION_CANCELLED);
            finally
              FreeAndNil(Pick);
            end;
          end;
        end;

        //check the filter one more time!
        iContents.Clear;

        if iFilter <> '' then
          uQPCompObj.Compression.UnCompressFile(IPSPath, ExtractFilePath(IPSPath), false, false, true, iContents, iFilter)
      end;
      
      if iContents.Count = 1 then
        newIPS := iContents[0]
      else
        raise EJException.Create(QP_IPS_NOT_FOUND);
    end
    else
      newIPS := IPSPath;

    //now newROM and newIPS hold the locations of unextracted ROMS and IPS files respectively.

    // get the new name of the ROM file.
    if CustomName = '' then
    begin
      NewName := Format('%s [IPS - %s]%s', [ChangeFileExt(ExtractFileName(newROM), ''), ChangeFileExt(ExtractFileName(NewIPS), '') , ExtractFileExt(newROM)]);
    end
    else
      NewName := CustomName + ExtractFileExt(newROM);

    //copy the ROM to a new version with a proper [IPS] tag in its name.
    uJFile.FileCopy(NewROM, ExtractFilePath(NewROM) + NewName);
    newROM := ExtractFilePath(NewROM) + NewName;

    // now finally patch the file!
    Patcher := TIPSPatcher.Create(newIPS, newROM);
    try
      Patcher.Execute;
    finally
      FreeAndNil(Patcher);
    end;

    //set the result of the function to be the newROM created
    Result := newROM;

    //delete any zip files now.  we dont need ANY of them.
    for i := 0 to iContents.Count-1 do
      if FileExists(iContents[i]) then
        SysUtils.DeleteFile(iContents[i]);
    for i := 0 to rContents.Count-1 do
      if FileExists(rContents[i]) then
        SysUtils.DeleteFile(rContents[i]);
    
  finally
    FreeAndNil(iContents);
    FreeAndNil(rContents);
  end;

end;

{-----------------------------------------------------------------------------}

procedure TQPROM.DeleteIPS(Index : Integer);
begin
  _IPS.Delete(Index);
end;

{-----------------------------------------------------------------------------}

Function TQPROM.GetIPSCount() : Integer;
begin
  Result := _IPS.Count;
end;

{-----------------------------------------------------------------------------}

Function TQPROM.GetDefaultIPSIndex() : Integer;
var
  i : Integer;
begin
  Result := -1;
  for i := 0 to _IPS.Count-1 do
    if IPS[i].IsDefault then
    begin
      Result := i;
      Break;
    end;
end;

{-----------------------------------------------------------------------------}

procedure TQPROM.SetDefaultIPSIndex(value : Integer);
var
  i : Integer;
begin
  //value can be anything, if its -1 then turn off ALL defaults.
  //first of all disable ALL elements.
  for i := 0 to _IPS.Count-1 do
    IPS[i].IsDefault := False;

  //now set the default, if need be!
  if (value <> -1) and (Value < _IPS.Count) then
    IPS[value].IsDefault := True;

end;

{-----------------------------------------------------------------------------}

Function TQPROM.GetFileNameNoExt() : String;
begin
  if Self._ZipName <> '' then
    //this rom is inside a zip file and its real name is hidden, we need to use this.
    Result := ExtractFileName(ChangeFileExt(_ZipName, ''))
  else if Self._MAMEname <> '' then
      //this rom was scanned using MAME, just return its 'clonename'
      Result := Self._MAMEname
  else
    //just return whatever is in the path field.
    Result := ExtractFileName(ChangeFileExt(self._path, ''));
end;

{-----------------------------------------------------------------------------}

function TQPROM.GetIPS(Index: Integer): TQPIPS;
begin
  Result := TQPIPS(_IPS.Items[Index]);
end;

{-----------------------------------------------------------------------------}

procedure TQPROM.SetIPS(Index: Integer; AObject: TQPIPS);
begin
  _IPS.Items[Index] := AObject;
end;

{-----------------------------------------------------------------------------}

Function TQPROM.GetSummary() : String;
begin

  Result := QP_ROM_NAME + ' : ' + _name + #13 +
            QP_ROM_PATH + ' : ' + _path + #13 +
            QP_ROM_EMU + ' : ' + _emulator;

  If _Comment <> '' then
    Result := Result + #13 + QP_ROM_COMMENT + ' : ' + #13 + _Comment;

end;

procedure TQPROM.FromString(strRom : String);
var
  SplitList : TStringList;
  IPSpos, New : integer;
  Comment : String;
begin

  //set our internal data
  _IconIndex := -1;
  _Exists := -1;

  //we need to create our splitlist stringlist
  SplitList := TStringList.Create;
  try
    // this function is from jedi code library.
    StrTokenToStrings(strRom, '¬', SplitList);
    if SplitList.Count > 6 then
    begin
      //exception handler which catches any attempts to read data that doesnt exist in the string.
      try
        _name := SplitList[0];
        _MAMEname := SplitList[1];
        _ParentName := SplitList[2];
        _ZipName := SplitList[3];
        //now process the rest of the rom information
        _path := SplitList[4];
        _emulator := SplitList[5];
        _Company := SplitList[6];
        _year := SplitList[7];
        _GameType := SplitList[8];
        _Rating := SplitList[9];
        _Language := SplitList[10];
        _Parameters := SplitList[11];

        //the comment needs to be processed to add in any '#13#10'.
        Comment := SplitList[12];
        StrReplace(Comment, '#13', chr(13), [rfReplaceAll]);
        StrReplace(Comment, '#10', chr(10), [rfReplaceAll]);
        _Comment := Comment;

        _NumPlay := StrToInt(SplitList[13]);
        _ParamMode := TROMParametersMode(StrToInt(SplitList[14]));
                                                                    
        IPSpos := 16;
        while StrCompare(SplitList[IPSpos], '</IPS>') <> 0 do
        begin
          new := _IPS.Add(TQPIPS.Create);
          IPS[new].IPSIndex := new;
          IPS[new].IPSName := SplitList[IPSpos];
          inc(IPSpos);
          self.IPS[new].IPSPath := SplitList[IPSpos];
          inc(IPSpos);
          Self.IPS[new].IsDefault := StrToBool(SplitList[IPSPos]);
          inc(IPSpos);
        end;

        _Multiplayer := SplitList[IPSpos + 1];
        _DefaultGoodMerge := SplitList[IPSPos + 2];

      except
        Exit; //ignore any errors we get in here.. 
      end;

    end;

  finally
    FreeAndNil(SplitList);
  end;

end;

{-----------------------------------------------------------------------------}

Procedure TQPRom.GetMAMEHistoryFromFile(var Output : TStrings; HistoryFile : TFileName);
var
  inList, matches : TStringList;
  start, i , j, k, l: Integer;
  fileType, GameName, line , test: String;
begin
  inList := TStringList.Create;
  matches := TStringList.Create;
  Start := -1;//defult to -1 for not found
  try

    if _MAMEName <> '' then
      GameName := _MameName
    else
      GameName := ExtractFileName(ChangeFileExt(_Path, ''));
     // Delete( GameName, pos('(',GameName)-1, Length(GameName) );
      //Delete( GameName, pos('[',GameName)-1, Length(GameName) );
      inList.LoadFromFile(HistoryFile);
     fileType :=   inList[0];
     fileType :=   AnsiLowerCase(fileType); //fixes bug in mameHistory0153 - commas otherwise won't deliniate
     if JCLStrings.StrSearch('## history.dat', fileType ) > 0 then
          fileType := 'mame'
        else
          fileType := 'other';  //we could always look for more detail i.e ##  Good2600

    //we need to look at all games in the $info= not just one, so bust by commas
	    for k := 1 to inList.Count-1 do
        begin
         if JCLStrings.StrSearch('$info=', inList[k] ) > 0 then
         begin
          line := inList[k];
          JCLStrings.StrReplace( line, '$info=', '');
          if fileType='other' then     //if we see a comma followed by a space this is not a mame dat. it is
                                                                  //important to seach for this because a comman is part of the rom name
            JCLStrings.StrTokenToStrings(line,'?',matches )
          else
            JCLStrings.StrTokenToStrings(line,',',matches );

          for l := 0 to matches.Count-1 do
          begin
              test := matches[l];


              if JCLStrings.StrCompare(matches[l], GameName) = 0 then
            begin
              Start := k;  //the index of the line, not the list
              Break//we are done.
            end;

            //I could not figure out how to or an if, so do another check to see if there is a
            //comma at the end. This will be the for all non mame sets
              if JCLStrings.StrCompare(matches[l], GameName+',') = 0 then   //the "other case"
            begin
              Start := k;  //the index of the line, not the list
              Break//we are done.
            end;

           end;
          end;
         end;

    Output.BeginUpdate;
    if Start <> -1 then
    begin
      //find bio from that point.
      for j := Start to inList.Count-1 do
      begin
        if JCLStrings.StrCompare(inList[j], '$bio') = 0 then
        begin
          start := j+1; //this is the line that has $bio on it.
         Break//we are done.
       end;
     end;

      for i := Start to inList.Count-1 do
      begin
        if JCLStrings.StrCompare(inList[i], '$end') = 0 then
          Break
        else
          Output.Add(inList[i]);
      end;
    end;
    Output.EndUpdate;
  finally
    FreeAndNil(inList);
  end;
end;

{-----------------------------------------------------------------------------}

Procedure TQPRom.GetMAMEInfoFromFile(var Output : TStrings; MAMEInfoFile : TFileName);
var
  inList, matches : TStringList;
  start, i , k, l: Integer;
  fileType, GameName, line , test: String;
begin
  inList := TStringList.Create;
  matches := TStringList.Create;
  Start := -1;//defult to -1 for not found
  try

    if _MAMEName <> '' then
      GameName := _MameName
    else
      GameName := ExtractFileName(ChangeFileExt(_Path, ''));
     // Delete( GameName, pos('(',GameName)-1, Length(GameName) );
      //Delete( GameName, pos('[',GameName)-1, Length(GameName) );

    inList.LoadFromFile(MAMEInfoFile);
     fileType :=   inList[0];
     if JCLStrings.StrSearch('# MAMEINFO.DAT', fileType ) > 0 then
          fileType := 'mame'
        else
          fileType := 'other';  //we could always look for more detail i.e ##  Good2600

     //we need to look at all games in the $info= not just one, so bust by commas
	    for k := 1 to inList.Count-1 do
        begin
         if JCLStrings.StrSearch('$info=', inList[k] ) > 0 then
         begin
          line := inList[k];
          JCLStrings.StrReplace( line, '$info=', '');
          if fileType='other' then     //if we see a comma followed by a space this is not a mame dat. it is
                                                                  //important to seach for this because a comman is part of the rom name
            JCLStrings.StrTokenToStrings(line,'?',matches )
          else
            JCLStrings.StrTokenToStrings(line,',',matches );


          for l := 0 to matches.Count-1 do
          begin
          test :=   matches[l];
            if JCLStrings.StrCompare(matches[l], GameName) = 0 then
            begin
              Start := k +2;  //the index of the line, not the list (pluss add two to skip the identifiers )
              Break//we are done.
           end;

            //I could not figure out how to or an if, so do another check to see if there is a
            //comma at the end. This will be the for all non mame sets
              if JCLStrings.StrCompare(matches[l], GameName+',') = 0 then   //the "other case"
            begin
              Start := k;  //the index of the line, not the list
              Break//we are done.
            end;

          end;
         end;
        end;

    Output.BeginUpdate;
    if Start <> -1 then
      for i := Start to inList.Count-1 do
      begin
        if JCLStrings.StrCompare(inList[i], '$end') = 0 then
          Break
        else
          Output.Add(inList[i]);
      end;
    Output.EndUpdate;
  finally
    FreeAndNil(inList);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TQPRom.GuessGoodMerge(Pref1, Pref2, Pref3 : String);
var
  FileList : TStringList;
  i, Choice : Integer;
  FileExt : String;
         fl : String;
begin
  //create a stringlist to hold the compressed listings.
  FileList := TStringList.Create;
  try

    if Self.CompressedFiles.Count > 0 then
      FileList.AddStrings(Self.CompressedFiles)
    else
    begin
      //get the contents of the compressed file.
      if FileExists(Self.Path) then
        uQPCompObj.Compression.ListContentsOfFile(TStrings(FileList), Self.Path)
      else
        raise EJException.Create(J_FILE_NOT_EXIST);
    end;

    //now filelist is full of files, try to find the users preferred choice.
    Choice := -1;
    Case FileList.Count of
      0 : raise EJException.Create(COMP_ARCHIVE_EMPTY);
      1 : Choice := 0; //only one file in archive, must be the ROM.. i hope..

      else
      begin
      //find users choice
        //check any user-set default ROMS
        if _DefaultGoodMerge <> '' then
          for i := 0 to FileList.Count-1 do
            if JCLStrings.StrIPos(_DefaultGoodMerge, FileList[i]) <> 0 then
            begin
              Choice := i;
              break;
            end;

        //Try the first preference
        if Choice = -1 then
          for i := 0 to FileList.Count-1 do
            if JCLStrings.StrIPos(Pref1, FileList[i]) <> 0 then
            begin
              Choice := i;
               fl :=    FileList[Choice];
              break;
            end;

        // if we still havent got a choice, try the second preference.
        if Choice = -1 then
          for i := 0 to FileList.Count-1 do
            if JCLStrings.StrIPos(Pref2, FileList[i]) <> 0 then
            begin
              Choice := i;
              break;
            end;

        // if we still have got a choice try the 3rd preference.
        if Choice = -1 then
          for i := 0 to FileList.Count-1 do
            if JCLStrings.StrIPos(Pref3, FileList[i]) <> 0 then
            begin
              Choice := i;
              break;
            end;

        //Ok, Try for [!] roms
         if Choice = -1 then
          for i := 0 to FileList.Count-1 do
              if JCLStrings.StrIPos('[!]', FileList[i]) <> 0 then
              begin
               Choice := i;
               break;
              end;

        // if there is STILL no match, just return any old crap..
        if Choice = -1 then
          for i := 0 to FileList.Count-1 do
          begin
            FileExt := Lowercase(ExtractFileExt(FileList[i]));
            If (FileExt = '.txt') or (FileExt = '.nfo') or (FileExt = '.diz') then
              continue
            else
            begin
              Choice := i;
              break;
            end;
          end
      end;
    end; //end of CASE statement

    if Choice <> -1 then
      Self.ZipName := FileList[Choice]
    else
      raise EJException.Create(QP_GM_CHOICE_ERROR);

  finally
       fl :=    FileList[Choice];
    FreeAndNil(FileList);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TQPRom.LegacyFromString(strRom : String);
var
  SplitList : TStringList;
  IPSpos, New : integer;
  Comment : String;
begin

  //set our internal data
  _IconIndex := -1;
  _Exists := -1;

  //we need to create our splitlist stringlist
  SplitList := TStringList.Create;
  try
    // this function is from jedi code library.
    StrTokenToStrings(strRom, '¬', SplitList);
    if SplitList.Count > 6 then
    begin
      //exception handler which catches any attempts to read data that doesnt exist in the string.
      try
        _name := SplitList[0];
        _MAMEname := SplitList[1];
        _ParentName := SplitList[2];
        _ZipName := SplitList[3];
        //now process the rest of the rom information
        _path := SplitList[4];
        _emulator := SplitList[5];
        _Company := SplitList[6];
        _year := SplitList[7];
        _GameType := SplitList[8];
        _Rating := SplitList[9];
        _Language := SplitList[10];
        _Parameters := SplitList[11];

        //the comment needs to be processed to add in any '#13#10'.
        Comment := SplitList[12];
        StrReplace(Comment, '#13', chr(13), [rfReplaceAll]);
        StrReplace(Comment, '#10', chr(10), [rfReplaceAll]);
        _Comment := Comment;

        _NumPlay := StrToInt(SplitList[13]);
        _ParamMode := TROMParametersMode(StrToInt(SplitList[14]));
                                                                    
        IPSpos := 16;
        while StrCompare(SplitList[IPSpos], '</IPS>') <> 0 do
        begin
          new := _IPS.Add(TQPIPS.Create);
          IPS[new].IPSIndex := new;
          IPS[new].IPSName := SplitList[IPSpos];
          inc(IPSpos);
          self.IPS[new].IPSPath := SplitList[IPSpos];
          inc(IPSpos);
          Self.IPS[new].IsDefault := StrToBool(SplitList[IPSPos]);
          inc(IPSpos);
        end;

        _Multiplayer := SplitList[IPSpos + 1];

      except
        Exit; //ignore any errors we get in here.. 
      end;

    end;

  finally
    FreeAndNil(SplitList);
  end;

end;

{-----------------------------------------------------------------------------}

Function TQPRom.MatchesQuery(Query : TObjectList; MatchAll : Boolean) : Boolean;
var
  I : Integer;
  iQuery : TQPQuery;

      Function RomCmp(searchStr, MainStr : String; _Condition : TQPQueryCondition) : Boolean;
      begin
        Result := False;
        case _Condition of
          qcEqual : Result := (StrCompare(searchStr, MainStr) = 0);
          qcNotEqual : Result := (StrCompare(searchStr, MainStr) <> 0);
          qcContain : Result := (StrIPos(searchStr, MainStr) <> 0);
          qcNotContain : Result := (StrIPos(searchStr, MainStr) = 0);
        end;
      end;
begin
  Result := False;
  For i := 0 to Query.count-1 do
  begin
    iQuery := TQPQuery(Query[i]);
  
    Case iQuery.Field of
      qfName : Result := RomCmp(iQuery.Filter, _name, iQuery.Condition);
      qfFileName : Result := RomCmp(iQuery.Filter, ExtractFileName(_path), iQuery.Condition);
      qfEmu : Result := RomCmp(iQuery.Filter, _emulator, iQuery.Condition);
      qfCompany : Result := RomCmp(iQuery.Filter, _company, iQuery.Condition);
      qfYear : Result := RomCmp(iQuery.Filter, _year, iQuery.Condition);
      qfType : Result := RomCmp(iQuery.Filter, _GameType, iQuery.Condition);
      qfNumPlay : Result := RomCmp(iQuery.Filter, IntToStr(_NumPlay), iQuery.Condition);
      qfPlayers : Result := RomCmp(iQuery.Filter, _MultiPlayer, iQuery.Condition);
      qfRating : Result := RomCmp(iQuery.Filter, _Rating, iQuery.Condition);
    end;

    //If we only need to match one element and its found then exit.
    if (Result) and (not MatchAll) then
      Exit;

    //we need to match all the criteria, and it hasnt (hence the false), so no
    //need to carry on in the loop.  
    if (not Result) and (MatchAll) then
      Exit;

  end;
end;

{-----------------------------------------------------------------------------}

procedure TQPRom.RenameFile(NewName : String);
var
  Find : ThhFindFile;
  i : Integer;
begin
  If NewName <> '' then
  begin

    //we need to rename all the 'extra' files for this ROM.  Save state etc..
    Find := ThhFindFile.Create(nil);
    Try

      Find.Directory := ExtractFilePath(_path);
      Find.Filter := ExtractFileName(ChangeFileExt(_Path, '')) + '.*';
      Find.Recurse := False;

      find.Execute;

      For I := 0 to Find.TotalFile-1 do
        SysUtils.RenameFile(Find.Files[i], ExtractFilePath(Find.Files[i]) + ChangeFileExt(NewName, ExtractFileExt(Find.Files[i])));

      SysUtils.RenameFile(_path, ExtractFilePath(_path)+ NewName);

      _path := ExtractFilePath(_path)+ NewName;

    Finally
      FreeAndNil(Find);
    end;

  end
  else
    raise EJException.create(J_INVALID_FILE_NAME);
end;

{-----------------------------------------------------------------------------}

procedure TQPRom.RunIPS(Emu : TObject; IPSIndex : Integer; Tools : TQPExeList; RunOpt :TQPRunOptions);
Var
  RPath, IPSpath : String;
  tmpRom : TQPRom;
begin

  IPSPath := self.IPS[IPSIndex].IPSPath;
  RPath := CreateIPSROM(_path, IPSPath, RunOpt.ExtractDir);
  
  try
    //Now run the IPS game
    tmpRom := TQPRom.Create();
    Try
      tmpRom.Path := rPath;
      //This can throw exceptions...
      TQPEmu(Emu).Run(tmpRom, Tools, RunOpt);
    Finally
      FreeAndNil(tmpRom);
    end;

  finally
    //delete the temporary file.
    SysUtils.DeleteFile(Rpath);
  end;

end;

{-----------------------------------------------------------------------------}

Procedure TQPRom.SetLanguage();
Const
  CCode: Array [0..33] of String =
  ('(1)', '(A)', '(C)', '(F)', '(FC)', '(FN)', '(G)', '(GR)', '(HK)', '(H)', '(J)', '(K)', '(NL)', '(S)', '(SW)', '(U)', '(US)', '(UK)', '(I)', '(UnK)'
  , '(Japan)', '(USA)', '(China)', '(France)', '(Finland)', '(Germany)', '(Dutch)', '(Korea)', '(Netherlands)', '(Spain)', '(Sweden)', '(Italy)', '(Australia)', '(Europe)' );
  Lang : Array [0..33] of String =
  (J_JAP, J_ENG, J_CHI, J_FRE,  J_FRE, J_FIN, J_GER, J_GRE, J_CHI, J_DUT, J_JAP, J_KOR, J_DUT, J_SPA, J_SWE, J_ENG, J_ENG,J_ENG, J_ITA, J_ENG,
   J_JAP, J_ENG, J_CHI, J_FRE,  J_FIN, J_GER, J_DUT, J_KOR, J_DUT, J_SPA, J_SWE, J_ITA, J_ENG, J_ENG);
var
  I : Integer;
Begin
  //this code attempts to guess the language of a filename
  //by scanning the filename for any known country codes
  //obviously if the file name has no country code - it wont work :-)

  _Language := J_ENG;
  
  For I := 0 to 33 do
    If Pos(lowercase(CCode[i]), lowercase(ExtractFileName(_path))) <> 0 then
    Begin
      _Language := Lang[i];
      Break;
    end;

End;

{-----------------------------------------------------------------------------}

procedure TQPRom.SetMameMultiplayer(Ini : TMemIniFile);
var
  Temp : String;  // Variable for holding search criteria.
Begin

  //This function determines a games multiplayer mode. For MAME only!!

  // if it has a shortname then use this to search with
  // if it doesnt then try to extract the zip file name and work from that.
  If _MAMEname <> '' then
    Temp := _MAMEname
  else
    Temp := ChangeFileExt(Extractfilename(_path), '');

  Temp := ini.ReadString('NPlayers', temp , 'Unknown');

  _Multiplayer := Temp;
end;

{-----------------------------------------------------------------------------}

Procedure TQPRom.SetMameGameCategory(Ini : TMemIniFile);
var
  Temp : String;  // Variable for holding search criteria.
Begin

  //This function determines a games category. For MAME only!!

  // if it has a shortname then use this to search with
  // if it doesnt then try to extract the zip file name and work from that.
  If _MAMEname <> '' then
    Temp := _MAMEname
  else
    Temp := ChangeFileExt(Extractfilename(_path), '');

  Temp := ini.ReadString('Category', temp , 'Unknown');

  StrReplace(Temp, ' / ','/');

  _GameType := Temp;
End;

{-----------------------------------------------------------------------------}

Procedure TQPRom.SetMameGameLanguage(Ini : TMemIniFile);
var
  Temp : String;  // Variable for holding search criteria.
  ThisRom : String;
  IniRom : String;
  Sections : TStringList;
  RomsInSection : TStringList;
  I : integer;
  J : integer;
Begin

  //This function determines a games language. For MAME only!!

  // if it has a shortname then use this to search with
  // if it doesnt then try to extract the zip file name and work from that.

  // we only want to mess with language if it hasn't already been set, or we suspect
  // its at default. Why the caution here and not in other Mame ini's? Because
  // Language.ini isn't perfect and Orfax's Perl script also attempts to set language
  // Using a different mechanism
  if (_Language = J_ENG) or (_Language = '') then

    Begin
      If (_MAMEname <> '') then
        Temp := _MAMEname
      else
        Temp := ChangeFileExt(Extractfilename(_path), '');
		
	 ThisRom := Temp;

     Sections := TStringList.Create;
     RomsInSection := TStringList.create;

     ini.ReadSections(Sections);  //Get the section names for each section into an array

      //then for each section go through the roms in each section getting those into an array
       for I := 0 to (Sections.Count - 1) do
         Begin
         ini.ReadSectionValues(Sections[I], RomsInSection);
         //we now have an array of roms in this section, so for each rom, check for a match to our rom
         for J := 0 to (RomsInSection.Count -1) do
              Begin
                  IniRom := RomsInSection[J];
                  if Temp = IniRom then     //compare this romname with what we have
                  Begin
                    Temp := Sections[I]; //if its a match set it
                    break; //and leave the loop immediately - first rom wins....
                 end;
             end;
         end;

       if (Temp <> ThisRom) then //hope we never get a mame rom called the same as its language...
      _Language := Temp; 
	  //else: leave it as it was
      FreeAndNil(Sections);
      FreeAndNil(RomsInSection);
    End;

 End;
{-----------------------------------------------------------------------------}
Procedure TQPROM.ToCSV(var CodeList : TStrings; Opt : TQPExportOpt);
var
  Line : String;
begin

  if Opt.AddName then
    Line := _name + ',';

  if (Opt.AddEmu) then
    Line := Line + _emulator + ',';

  if (Opt.AddPath) then
    Line := Line + _path + ',';

  if (Opt.AddType) then
    Line := Line + _GameType + ',';

  if (Opt.AddLanguage) then
    Line := Line + _Language + ',';

  if (Opt.AddRating) then
    Line := Line + _Rating + ',';

  if (Opt.AddYear) then
    Line := Line + _Year + ',';

  if (Opt.AddPlayers) then
    Line := Line + _Multiplayer + ',';

  CodeList.add(Line);
end;

Procedure TQPROM.ToHTML(var CodeList : TStrings; EList : TObjectList; Opt : TQPExportOpt);
var
  emu : TQPEmu;
begin
  CodeList.add('<div class="ROM">');

  if Opt.AddName then
    CodeList.add('<div class="name">' + _name + '</div>');

  if (Opt.AddEmu) and (_Emulator <> '') then
    if Opt.AddWWW then
    begin
      emu := TQPEmuList(EList).GetEmuForROM(Self);
      If (emu <> nil) and (emu.HomePage <> '') then
        CodeList.Add('<div class="info">' + QP_ROM_EMU + ': <a href="' + emu.HomePage + '">' + _emulator + '</a></div>')
      else
        CodeList.add('<div class="info">' + QP_ROM_EMU + ': ' + _emulator + '</div>');
    end
    else
      CodeList.add('<div class="info">' + QP_ROM_EMU + ': ' + _emulator + '</div>');

  if (Opt.AddPath) and (_path <> '') then
    CodeList.add('<div class="info">' + QP_ROM_PATH + ': ' + _path + '</div>');

  if (Opt.AddType) and (_GameType <> '') then
    CodeList.add('<div class="info">' + QP_ROM_TYPE + ': ' + _GameType + '</div>');

  if (Opt.AddLanguage) and (_Language <> '') then
    CodeList.add('<div class="info">' + QP_ROM_LANG + ': ' + _Language + '</div>');

  if (Opt.AddRating) and (_Rating <> '') then
    CodeList.add('<div class="info">' + QP_ROM_RATING + ': ' + _Rating + '</div>');

  if (Opt.AddYear) and (_Year <> '') then
    CodeList.add('<div class="info">' + QP_ROM_YEAR + ': ' + _Year + '</div>');

  if (Opt.AddPlayers) and (_Multiplayer <> '') then
    CodeList.add('<div class="info">' + QP_ROM_PLAYERS + ': ' + _Multiplayer + '</div>');

  CodeList.add('</div>');
end;

{-----------------------------------------------------------------------------}

Function TQPROM.ToString() : String;
var
  ROMstring, Comment : String;
  I : Integer;
Begin
  RomString := _Name + '¬';
  RomString := RomString + _MAMEname + '¬';
  RomString := RomString + _ParentName + '¬';
  RomString := RomString + _ZipName + '¬';
  RomString := RomString + _path + '¬';
  RomString := RomString + _emulator + '¬';
  RomString := RomString + _Company + '¬';
  RomString := RomString + _Year + '¬';
  RomString := RomString + _GameType + '¬';
  RomString := RomString + _Rating + '¬';
  RomString := RomString + _Language + '¬';
  RomString := RomString + _Parameters + '¬';
  //we need to convert returns to a numeric display
  Comment := _Comment;
  StrReplace(Comment, chr(10), '#10', [rfReplaceAll]);
  StrReplace(Comment, chr(13), '#13', [rfReplaceAll]);
  RomString := RomString + Comment + '¬';

  RomString := RomString + IntToStr(_NumPlay) + '¬';
  RomString := RomString + IntToStr(Integer(_ParamMode)) + '¬';
  RomString := RomString + '<IPS>' + '¬';

  For I := 0 to _IPS.Count-1 do
    if (IPS[i].IPSName <> '') AND (IPS[i].IPSPath <> '') then
    Begin
      RomString := RomString + IPS[i].IPSName + '¬';
      RomString := RomString + IPS[i].IPSPath + '¬';
      ROMString := ROMString + BoolToStr(IPS[i].IsDefault) + '¬';
    end;

  RomString := RomString + '</IPS>';

  RomString := RomString + '¬' + _MultiPlayer;
  RomString := RomString + '¬' + _DefaultGoodMerge + '¬';

  //there should ALWAYS be an extra ¬ at the end of the string, otherwise performance goes through the floor.

  Result := ROMString;
End;

{-----------------------------------------------------------------------------}
Procedure TQPROM.ToXML(var CodeList : TStrings; EList : TObjectList; Opt : TQPExportOpt);
var
  emu : TQPEmu;
  temp : string;
begin
  CodeList.add('<rom>');

  if Opt.AddName then
  begin
    temp := _name;
    StrReplace(temp, '&', '&amp;', [rfReplaceAll]);
    CodeList.add('<name>' + temp + '</name>');
  end;

  if (Opt.AddEmu) and (_Emulator <> '') then
    if Opt.AddWWW then
    begin
      emu := TQPEmuList(EList).GetEmuForROM(self);
      If (emu <> nil) and (emu.HomePage <> '') then
        CodeList.Add('<emulator>' + _emulator + '<homepage>' + emu.HomePage + '</homepage></emulator>')
      else
        CodeList.add('<emulator>' + _emulator + '</emulator>');
    end
    else
      CodeList.add('<emulator>' + _emulator + '</emulator>');

  if (Opt.AddPath) and (_path <> '') then
    CodeList.add('<path>' + _path + '</path>');

  if (Opt.AddType) and (_GameType <> '') then
  begin
    temp := _GameType;
    StrReplace(temp, '&', '&amp;', [rfReplaceAll]);
    CodeList.add('<type>' + temp + '</type>');
  end;

  if (Opt.AddLanguage) and (_Language <> '') then
    CodeList.add('<language>' + _Language + '</language>');

  if (Opt.AddRating) and (_Rating <> '') then
    CodeList.add('<rating>' + _Rating + '</rating>');

  if (Opt.AddYear) and (_Year <> '') then
    CodeList.add('<year>' + _Year + '</year>');

  if (Opt.AddPlayers) and (_Multiplayer <> '') then
    CodeList.add('<players>' + _Multiplayer + '</players>');

  CodeList.add('</rom>');
end;

end.
