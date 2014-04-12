unit uRomList;

interface

uses Contnrs, Classes, SysUtils, ComCtrls, IniFiles, uRom, uToolList, uEmuList,
     uEmu, uQPMiscTypes, uSettings;

Type

  { List Of TQPRom Objects }
  TQPROMlist = class(TObjectList)
  protected
    _FileName : String;
    _AllowWrite : Boolean;
    function GetItem(Index: Integer): TQPRom;
    procedure SetItem(Index: Integer; AObject: TQPRom);
    function ROMIsIn(Clone, Path: String; Searchlist: TQPROMlist): Integer;
  public
    Constructor Create(AllowWrite : Boolean);
    Procedure AddFromDirs(lstDirs : TStrings; ff_Filter : String;
          ff_Recurse : Boolean; ScanZips : Boolean; EmuName : String;
          Rating : String; Language : TQPLanguageMode; NoDuplicates : Boolean);overload;
    procedure AddFromDirs(Dir : String; ff_Filter : String;
          ff_Recurse : Boolean; ScanZips : Boolean; EmuName : String;
          Rating : String; Language : TQPLanguageMode; NoDuplicates : Boolean);overload;
    Procedure AddFromStrings(RomStrings : TStrings; EmuName : String;
          Rating : String; Language : TQPLanguageMode; NoDuplicates : Boolean);
    procedure AddFromArchive(CompressedFile : TFileName; EmuName : String; Rating : String;
          Language : TQPLanguageMode; NoDuplicates : Boolean);
    Procedure AddMAMEScanned(lstDirs : TStrings; Emu : TQPEmu; WorkDir : String;
          ClearExisting, CatVer : Boolean; OldMAMECompatMode : Boolean);
    Procedure AddZincROMS(lstDirs : TStrings; Emu : TQPEmu; WorkDir : String; ClearExisting, CatVer : Boolean);
    Function ChangeEmus(OldEmu, NewEmu : String): Integer;
    Function DeleteByEmu(EmuStr : String) : Integer;
    Function DeleteOrphans() : Integer;
    Procedure ExportCustomData(outFile : TFileName; IncCompany, IncType, IncLang, IncYear,
          IncRating, IncPlayers : Boolean);
    Function ExportRoms(CList : TStrings; Format : TQPExportFormat; Opt : TQPExportOpt;
          EList : TQPEmuList; Mode : TQPExportMode; Filter : String = '') : Integer;
    procedure ImportCustomData(inFile : TFileName; Overwrite, IncCompany, IncType, IncLang,
          IncYear, IncRating, IncPlayers : Boolean);
    function last(): TQPRom;
    procedure LoadFromFile(In_file : TFileName);
    procedure LoadMatchesFromFile(In_file : TFileName; Query : TObjectList;
          MatchAll : Boolean);
    Procedure MameCompareNames(Ini : TMemIniFile; Prog : TProgressBar=nil);
    procedure MirrorDirectories(Ini : TMemIniFile);
    procedure MoveTo(Source, Destination: Integer);
    Procedure Query(var MatchList : TObjectList; smArray : TObjectList; MatchAll : Boolean);
    Function ROMExists(Path : String; zipname : string = ''):boolean;
    procedure RunRandom(EList : TQPEmuList; Tools : TQPToolList; Settings : TQPSettings; NeverPlayed : boolean);
    procedure SaveToFile();
    procedure SetMameCategories(SettingsDir : String);
    procedure SetMameMultiPlayer(SettingsDir : String);

    property Items[Index: Integer]: TQPRom read GetItem write SetItem; default;
    Property FileName : String Read _FileName write _FileName;
    Property AllowWrite : Boolean Read _AllowWrite write _AllowWrite;
  end;

implementation

{$I Compilers.inc}

uses Windows, StrUtils, FindFile,
     JclFileUtils, JCLStrings,
     uJUtilities, uQuery, uQPConst, uQPCompObj, ujCompression,
     ujMiscResourceStrs, ujProcesses;

{ TQPROMlist }

Constructor TQPROMlist.Create(AllowWrite : Boolean);
begin
  OwnsObjects := True;
  _AllowWrite := AllowWrite;
end;

function TQPROMlist.GetItem(Index: Integer): TQPRom;
begin
  Result := TQPRom(inherited Items[Index]);
end;

{-----------------------------------------------------------------------------}

function TQPROMlist.last: TQPRom;
begin
  Result := TQPROM(inherited Items[Count-1]);
end;

{-----------------------------------------------------------------------------}

procedure TQPROMlist.SetItem(Index: Integer; AObject: TQPRom);
begin
  inherited Items[Index] := AObject;
end;

{-----------------------------------------------------------------------------}

Procedure TQPROMList.AddFromDirs(Dir : String; ff_Filter : String;
          ff_Recurse : Boolean; ScanZips : Boolean; EmuName : String;
          Rating : String; Language : TQPLanguageMode; NoDuplicates : Boolean);
var
  LstDirs : TStringList;  
begin
  //This is just a wrapper for the other version, which takes a string for a directory
  //name.  The string is added to a stringlist and then the other version is called.
  LstDirs := TStringList.Create;
  try
    LstDirs.Add(Dir);
    AddFromDirs(LstDirs, ff_Filter, ff_Recurse, ScanZips, EmuName, Rating, Language,
                NoDuplicates);
  finally
    FreeAndNil(LstDirs);
  end;
end;

Procedure TQPRomList.AddFromDirs(lstDirs : TStrings; ff_Filter : String;
          ff_Recurse : Boolean; ScanZips : Boolean; EmuName : String;
          Rating : String; Language : TQPLanguageMode; NoDuplicates : Boolean);
var
  Find : THHFindFile;
  LstFound : TStringList;
  i : Integer;
begin
  if (lstDirs.Count > 0) then
  begin

      LstFound := TStringList.Create;
      try

        //set the sorted property to true.
        LstFound.Sorted := True;

        Find := THHFindFile.Create(nil);
        try
        
          //set up the search options
          Find.filter := ff_filter;
          Find.recurse := ff_Recurse;

          for i := 0 to lstDirs.Count-1 do
          begin
            Find.Directory := lstDirs[i];
            Find.execute;
            //add the results to our stringlist.
            LstFound.AddStrings(Find.Files);
          end;

        Finally
          FreeAndNil(Find);
        end;

        //now we have a list of search results, we can save them

        If ScanZips then
          For i := LstFound.Count-1 downto 0 do
          begin
            Self.AddFromArchive(LstFound[i], EmuName, Rating, Language, NoDuplicates);
            LstFound.Delete(i);
          end;

        //now save whatever is left over
        Self.AddFromStrings(LstFound, EmuName, Rating, Language, NoDuplicates);
      Finally
        FreeAndNil(LstFound);
      end;
  end;

end;

Procedure TQPROMlist.AddFromStrings(RomStrings : TStrings; EmuName : String;
          Rating : String; Language : TQPLanguageMode; NoDuplicates : Boolean);
var
  i :integer;
  NewRom : TQPRom;
Begin
  // Add all Roms in the stringlist to the current list.
  Self.Capacity := Self.Count + RomStrings.Count;
  
  for i := 0 to RomStrings.Count-1 do
  begin

    If NoDuplicates then
        if Self.ROMExists(RomStrings[i]) then
          Continue;

    Self.add(TQPRom.Create);
    NewROM := Self.Last();

    NewROM.name := ChangeFileExt(ExtractFileName(RomStrings[i]), '');
    NewROM.path := trim(RomStrings[i]);
    NewROM.emulator := EmuName;
    NewROM.Year := '';
    NewROM.NumPlay := 0;
    NewROM.gametype := '';
    NewROM.Parameters := '';
    NewROM.ParameterMode := ParamAfter;
    NewROM.ZipName := '';

    NewROM.Rating := Rating;

    case Language of
      lmEnglish : NewRom.Language := J_ENG;
      lmNone : NewRom.Language := '';
      lmGuess : NewRom.SetLanguage();
    end;

  end;  //End of FOR loop

  // save the data
  Self.SaveToFile();

End;

{-----------------------------------------------------------------------------}

procedure TQPROMlist.AddFromArchive(CompressedFile : TFileName;
          EmuName : String; Rating : String; Language : TQPLanguageMode;
          NoDuplicates : Boolean);
var
  i :integer;
  NewRom : TQPRom;
  ROMname : String;
  ZipContents : TStrings;
Begin

  //first make sure that this file is indeed a supported archive format.
  if uQPCompObj.Compression.SupportsFileName(CompressedFile, cmRead) then
  begin
    ZipContents := TStringList.Create;
    try

    uQPCompObj.Compression.ListContentsOfFile(ZipContents, CompressedFile);

    for i := 0 to ZipContents.Count-1 do
    begin

      ROMname := ChangeFileExt(ExtractFileName(ZipContents[i]), '');

      If NoDuplicates then
        if Self.ROMExists(CompressedFile, ZipContents[i]) = True then
          Continue;

      Self.add(TQPRom.Create);
      NewROM := Self.Last();

      NewROM.name := ROMname;
      NewROM.path := CompressedFile;
      NewROM.ZipName := ZipContents[i];
      NewROM.emulator := EmuName;
      NewROM.Year := '';
      NewROM.NumPlay := 0;
      NewROM.gametype := '';
      NewROM.Parameters := '';
      NewROM.ParameterMode := ParamAfter; 

      NewROM.Rating := Rating;

      case Language of
        lmEnglish : NewRom.Language := J_ENG;
        lmNone : NewRom.Language := '';
        lmGuess : NewRom.SetLanguage();
      end;
      
    end;  //End of FOR loop

    Finally
      FreeAndNil(ZipContents);
    end;

  end;//end of IF is a zip file statement

  // save the data
  Self.SaveToFile();
End;

{-----------------------------------------------------------------------------}

Procedure TQPROMlist.AddMAMEScanned(lstDirs : TStrings; Emu : TQPEmu;
     WorkDir : String; ClearExisting, CatVer : Boolean; OldMAMECompatMode : Boolean);
var
  CommandLine, Name : String;
  I, Dirs, FIndex : Integer;
  Flist : TStringList;
  TmpROMs : TQPROMlist;
begin
  //first stage is to scan all the directories and get a full
  //listing of all ROMS we need to add.
  TmpROMs := TQPROMlist.Create(True);
  try

    //check that there isnt a vset file.  If there is, delete it.
    If FileExists(WorkDir + 'vset.txt') then
      SysUtils.DeleteFile(WorkDir + 'vset.txt');

    For Dirs := 0 to lstDirs.Count-1 do
    begin
      //set up the commandline for MAME to process the directory
      commandline := extractshortpathname(Emu.Path);

      if OldMAMECompatMode then
        commandline := Format('%s -verifysets  -rompath %s > %svset.txt', [commandline, ExtractShortPathName(lstDirs[Dirs]), extractshortpathname(WorkDir)])
      else
        CommandLine := Format('%s -verifyroms  -rompath %s > %svset.txt', [commandline, ExtractShortPathName(lstDirs[Dirs]), extractshortpathname(WorkDir)]);

      case Win32Platform of
        0,1: RunProcess('command.com /c '+CommandLine, True,'', SW_SHOWNORMAL); //Win32s and Win95
        2: RunProcess('cmd.exe /c '+CommandLine, True,'',SW_SHOWNORMAL); // WinNT and Win2000
      end;

      FList := TStringList.Create;
      try

        //load the game txt file into a stringlist.
        Flist.LoadFromFile(WorkDir + 'vset.txt');
        For i := 0 to FList.Count-1 do
        begin
          //if the text doesnt start with 'romset' go to the next line
          If not AnsiStartsText('romset' , FList.Strings[i]) then
            continue;

          Name := StrBefore(' ', StrAfter('romset ', FList.Strings[i]));
          TmpROMs.Add( TQPROM.Create() );
          TmpROMs.last.Name := Name;
          TmpROMs.last.MAMEName := Name;
          TmpROMs.last.ParentName := StrBetween(FList.Strings[i], '[', ']');
          TmpROMs.last.Path := IncludeTrailingPathDelimiter(lstDirs[Dirs]);
          TmpROMs.last.Emulator := Emu.Name;
        end;

      finally
        FreeAndNil(Flist);
      end;

      SysUtils.DeleteFile(WorkDir + 'vset.txt');

    end; //end of FOR loop


    //now tmpROMs is full of our search results.  We need to move
    //tmpROMs into the 'proper' ROMlist in the manner the user wants.
    If ClearExisting then
    begin
      //Clear the rom list - nice and fast!
      Self.Clear;
      TmpRoms.FileName := Self.FileName;
      TmpRoms.SaveToFile();
      Self.LoadFromFile(TmpROMS.FileName);
    end
    else
    Begin

      //the user wants to retain their existing data.  
      //this is more difficult (and slower)

        //the first step is to delete entries from the TmpROMs that already exist
        For i := Self.Count-1 downto 0 do
        begin
          FIndex := ROMisIn(Self[i].MAMEname, Self[i].Path, TmpROMS);
          If FIndex = -1 then
            Self.Delete(i)
          else
            TmpROMs.Delete(Findex);
        end;

        //now we just need to add the leftover entries from tmpROMs to the ROMlist
        For i := 0 to TmpRoms.Count-1 do
        begin
          Self.Add(TQPROM.Create);
          Self.last.Assign(TmpROMS[i]);
        end;

        //Now save the ROMs objectlist
        Self.SaveToFile();
    end;

  Finally
    FreeAndnil(TmpROMs);
  end;

  //if the CATver option is checked then process the romlist.
  If CatVer then
    Self.SetMameCategories(WorkDir);

end;

{-----------------------------------------------------------------------------}

Procedure TQPROMlist.AddZincROMS(lstDirs : TStrings; Emu : TQPEmu; WorkDir : String; ClearExisting, CatVer : Boolean);
var
  i, e, FIndex : Integer;
  TmpROMS : TQPROMList;
  Find : ThhFindFile;
  ZincIni : TMemIniFile;
  CurSection : String;
begin

  TmpROMS := TQPROMList.Create(True);
  try

    Emu.ZincSupportedGames(WorkDir);

    if FileExists(WorkDir + Emu.Name + '.ini') then
    begin

      Find := ThhFindFile.Create(nil);
      try

        ZincIni := TMemIniFile.Create(WorkDir + Emu.Name + '.ini');
        try
          for i := 0 to LstDirs.Count-1 do
          begin

            Find.Directory := LstDirs[i];
            Find.Filter := '*.zip';
            Find.Recurse := False;
            Find.Sorted := True;
            Find.Execute;

            //now process the results from the search.
            for e := 0 to Find.TotalFile-1 do
            begin
              CurSection := ExtractFileName(ChangeFileExt(Find.Files[e], ''));
              if ZincIni.SectionExists(CurSection) then
              begin
                //this file has a section in the Zinc Ini file, add it to the roms list
                TmpROMS.Add(TQPROM.Create);
                TmpROMS.last.Name := ZincIni.ReadString(CurSection, 'name', CurSection);
                TmpROMS.last.ParentName := CurSection;
                TmpROMS.last.MAMEName := ZincIni.ReadString(CurSection, 'ID', '');
                TmpROMS.last.Emulator := Emu.Name;
                TmpROMS.last.Path := Find.Files[e];
              end;

            end; //end of FOR find.totalfile loop

          end; //end of FOR LstDirs Loop

        finally
          FreeAndNil(ZincIni);
        end;

      finally
        FreeAndNil(Find);
      end;

    //now tmpROMs is full of our search results.  We need to move
    //tmpROMs into the 'proper' ROMlist in the manner the user wants.
    If ClearExisting then
    begin
      //Clear the rom list - nice and fast!
      Self.Clear;
      TmpRoms.FileName := Self.FileName;
      TmpRoms.SaveToFile();
      Self.LoadFromFile(TmpROMS.FileName);
    end
    else
    Begin

      //the user wants to retain their existing data.  
      //this is more difficult (and slower)

        //the first step is to delete entries from the TmpROMs that already exist
        For i := Self.Count-1 downto 0 do
        begin
          FIndex := ROMisIn(Self[i].MAMEname, Self[i].Path, TmpROMS);
          If FIndex = -1 then
            Self.Delete(i)
          else
            TmpROMs.Delete(Findex);
        end;

        //now we just need to add the leftover entries from tmpROMs to the ROMlist
        For i := 0 to TmpRoms.Count-1 do
        begin
          Self.Add(TQPROM.Create);
          Self.last.Assign(TmpROMS[i]);
        end;

        //Now save the ROMs objectlist
        Self.SaveToFile();
    end;

    end;//end of fileexist check

  Finally
    FreeAndnil(TmpROMs);
  end;

  //if the CATver option is checked then process the romlist.
  If CatVer then
    Self.SetMameCategories(WorkDir);

end;

{-----------------------------------------------------------------------------}

Function TQPROMlist.ChangeEmus(OldEmu, NewEmu : String): Integer;
var
  i : Integer;
  Changed : boolean;
begin
  // Function to change associated emulator for entire list.

  Changed := False;
  Result := 0;

  for i := 0 to self.Count-1 do
    if StrCompare(self[i].emulator, OldEmu)=0 then
    begin
      self[i].emulator := NewEmu;
      changed := True;
    end;

  //If the list has been altered then write to disk.
  if changed then
    Self.SaveToFile();
end;

{-----------------------------------------------------------------------------}

Function TQPROMlist.DeleteByEmu(EmuStr : String) : Integer;
var
  I : Integer;
  Changed : Boolean;
begin
  // Function to Delete all roms in the list if they use a specified emulator.

  changed := False;
  Result := 0;
  for i := self.Count-1 downto 0 do
    //Find Roms linked to the deleted emulator and delete
    if StrCompare(self[i].emulator, EmuStr)=0 then
    begin
      self.Delete(i);
      changed := True;
    end;

  //If the roms have been altered then write the array to disk.
  if changed then
    Self.SaveToFile();
end;

{-----------------------------------------------------------------------------}

Function TQPROMlist.DeleteOrphans() : Integer;
var
   i : integer;
   Changed : Boolean;
Begin

  Changed := False;
  Result := 0;

  For i := Self.Count-1 downto 0 do
  if (not fileExists(Self[i].path)) and (not DirectoryExists(Self[i].Path)) then
  begin
    Self.Delete(i);
    inc(Result);
    changed := true;
  end;

  //If the roms have been altered then write the array to disk.
  if (changed) then
    Self.SaveToFile();

End;

{-----------------------------------------------------------------------------}

Procedure TQPROMlist.ExportCustomData(outFile : TFileName; IncCompany, IncType,
          IncLang, IncYear, IncRating, IncPlayers : Boolean);
var
  i : Integer;
  data : TStringList;
begin
  //This function outputs a ROMs information as an ini file for scanning in QP
  data := TStringList.Create;
  try

    for i := 0 to Self.Count-1 do
    begin

      Data.Add('[' + Self[i].FileNameNoExt + ']');
      if (IncCompany) and (Self[i].Company <> '') then
        Data.Add('Company=' + Self[i].Company);

      if (IncType) and (Self[i].GameType <> '') then
        Data.Add('Type=' + Self[i].GameType);

      if (IncLang) and (Self[i].Language <> '') then
        Data.Add('Language=' + Self[i].Language);

      if (IncYear) and (Self[i].Year <> '') then
        Data.Add('Year=' + Self[i].Year);

      if (IncRating) and (Self[i].Rating <> '') then
        Data.Add('Rating=' + Self[i].Rating);

      if (incPlayers) and (Self[i].Multiplayer <> '') then
        Data.Add('Players=' + Self[i].Multiplayer);

      Data.Add('');
    end;

    Data.SaveToFile(outFile);

  Finally
    FreeAndNil(Data);
  end;
end;

{-----------------------------------------------------------------------------}

Function TQPROMlist.ExportRoms(CList : TStrings; Format : TQPExportFormat; Opt : TQPExportOpt;
          EList : TQPEmuList; Mode : TQPExportMode; Filter : String = '') : Integer;
var
  i, e : Integer;
begin

  Result := 0;
  
  Case Mode of
    emAll, emAllDirs : //export all ROMs in the list.
      Begin
        Result := Self.Count;
        For i := 0 to Self.Count-1 do
        begin
          Case Format of
            efHTML : Self[i].ToHTML(CList, EList, Opt);
            efXML : Self[i].ToXML(CList, EList, Opt);
            efText : Self[i].ToCSV(CList, Opt);
          end;
        end;
      end;

    emSys : //export ROMs that are in the specific system.
      Begin
        if Filter <> '' then
          for i := 0 to Self.Count-1 do
            for e := 0 to EList.Count-1 do
              if StrCompare(Self[i].emulator, EList[e].name)=0 then
                if StrCompare(EList[e].system, Filter)=0 then
                begin
                  Case Format of
                    efHTML : Self[i].ToHTML(CList, EList, Opt);
                    efXML : Self[i].ToXML(CList, EList, Opt);
                    efText : Self[i].ToCSV(CList, Opt);
                  end;
                  Inc(Result);
                  break;
                end;
      end;

    emEmu : //Export ROMS associated to specific emulator.
      Begin
        if Filter <> '' then
          For i := 0 to Self.Count-1 do
            if StrCompare(Self[i].emulator, filter)=0 then
            begin
              Case Format of
                efHTML : Self[i].ToHTML(CList, EList, Opt);
                efXML : Self[i].ToXML(CList, EList, Opt);
                efText : Self[i].ToCSV(CList, Opt);
              end;
              Inc(Result);
            end;
      End;
  end;
  
end;

{-----------------------------------------------------------------------------}

procedure TQPROMlist.ImportCustomData(inFile : TFileName; Overwrite, IncCompany, IncType, IncLang,
          IncYear, IncRating, IncPlayers : Boolean);
var
  i : Integer;
  ini : TMemIniFile;
begin
  if FileExists(inFile) then
  begin

    ini := TMemIniFile.Create(inFile);
    try

      for i := 0 to Self.Count-1 do
      begin

        if (IncCompany) and ((Self[i].Company = '') or (overwrite)) then
          Self[i].Company := Ini.ReadString(Self[i].FileNameNoExt, 'Company', Self[i].Company);
        if (IncType) and ((Self[i].GameType = '') or (overwrite)) then
          Self[i].GameType := Ini.ReadString(Self[i].FileNameNoExt, 'Type', Self[i].GameType);
        if (IncLang) and ((Self[i].Language = '') or (overwrite)) then
          Self[i].Language := Ini.ReadString(Self[i].FileNameNoExt, 'Language', Self[i].Language);
        if (IncYear) and ((Self[i].Year = '') or (overwrite)) then
          Self[i].Year := Ini.ReadString(Self[i].FileNameNoExt, 'Year', Self[i].Year);
        if (IncRating) and ((Self[i].Rating = '') or (overwrite)) then
          Self[i].Rating := Ini.ReadString(Self[i].FileNameNoExt, 'Rating', Self[i].Rating);
        if (IncPlayers) and ((Self[i].Multiplayer = '') or (overwrite)) then
          Self[i].Multiplayer := Ini.ReadString(Self[i].FileNameNoExt, 'Players', Self[i].Rating);

      end;

      //save the updated list
      Self.SaveToFile;

    finally
      FreeAndNil(ini);
    end;

  end;
end;

{-----------------------------------------------------------------------------}

procedure TQPROMlist.LoadFromFile(In_file : TFileName);
var
  i : integer;
  filelist : TStringList;
begin

  //to start with we clear the ROM list.
  Self.Clear;
  Self.Pack;
  _FileName := In_file;

  if fileExists(In_file) AND (GetSizeOfFile(In_file) > 0) then
  begin

    filelist := TStringList.create;
    try
      filelist.LoadFromFile(In_file);

      //set the capacity of the ROM list to improve performance.
      Self.Capacity := FileList.Count;
      if StrCompare(FileList[0], 'ROM DataFile Version : 1.1') = 0 then
      begin
        For i := 1 to FileList.Count-1 do
          Self.Add(TQPRom.Create(FileList[i]));
      end
      else
      begin
        For i := 1 to FileList.Count-1 do
          Self.Add(TQPROM.Create(FileList[i], True));
        Self.SaveToFile;
      end;

    finally
      FreeAndNil(filelist);
    end;

  end;

  {$IFDEF DEBUG}
    filelist := TStringList.Create;
    try
      For i := 0 to Self.Count-1 do
        FileList.Add(Self[i].Name + ' - ' + Self[i].CloneName + ' - ' + Self[i].ParentName);

      FileList.SaveToFile(ParamStr(0) + 'DebugROMS.txt');
    Finally
      FreeAndNil(FileList);
    end;

  {$ENDIF}

end;

procedure TQPROMlist.LoadMatchesFromFile(In_file : TFileName; Query : TObjectList;
          MatchAll : Boolean);
var
  i, e : integer;
  filelist : TStringList;
  iQuery : TQPQuery;
  qResult : Boolean;
begin

  //to start with we clear the ROM list.
  Self.Clear;
  Self.Pack;
  qResult := False;
  _FileName := In_file;

  if fileExists(In_file) AND (GetSizeOfFile(In_file) > 0) then
  begin

    filelist := TStringList.create;
    try
      filelist.LoadFromFile(In_file);

      //set the capacity of the ROM list to improve performance.
      Self.Capacity := FileList.Count;

      //if this data file needs converted first, we need to do this... although its going to slow down the search MASSIVELY
      if StrCompare(FileList[0], 'ROM DataFile Version : 1.1') <> 0 then
      begin
        For i := 0 to FileList.Count-1 do
          Self.Add(TQPROM.Create(FileList[i], True));
        Self.SaveToFile;
        Self.Clear;
      end;

      For i := 1 to FileList.Count-1 do
      begin

        //now we do a quick String Comparison to see if any of the matches are in this line
        //before we turn it into a ROM.
        For e := 0 to Query.count-1 do
        begin
          iQuery := TQPQuery(Query[e]);

          //basically do a different search depending on whether this query wants a NOT
          if iQuery.ConditionInt in [0, 2] then
            qResult := JCLStrings.StrIPos(iQuery.Filter, FileList[i]) <> 0
          else
            qResult := JCLStrings.StrIPos(iQuery.Filter, FileList[i]) = 0;

          //If we only need to match one element and its found then exit.
          if (qResult) and (not MatchAll) then
            Break;
          //we need to match all the criteria, and it hasnt (hence the false), so no
          //need to carry on in the loop.
          if (not qResult) and (MatchAll) then
            Break;
        end;

        // now add our new rom to the list.
        if qResult then
          Self.Add(TQPRom.Create(FileList[i]));
      end;

    finally
      FreeAndNil(filelist);
    end;

  end;
end;

{-----------------------------------------------------------------------------}
Procedure TQPROMlist.MameCompareNames(Ini : TMemIniFile; Prog : TProgressBar=nil);
var
  i : Integer;
  Temp : String;
begin

  //initialise the progress bar if there is one.
  if Prog <> nil then
  begin
    Prog.Position := 0;
    Prog.Max := Self.Count;
  end;

  //loop through every ROM looking for a rename
  for i := 0 to Self.Count-1 do
  begin

    //get the name of the ROM -without extension or path
    If Self[i].MAMEname <> '' then
      Temp := Self[i].MAMEname
    else
    begin
      Temp := Self[i].Name;
      Self[i].MAMEname := Self[i].Name;
    end;
    //all MAME file names must be under 8 characters, this is a

    //simple to check to speed up the process a bit.
    if Length(Temp) <= 8 then
    begin
      Self[i].name := ini.ReadString(trim(temp), 'name' , Self[i].name);
      Self[i].Year := ini.ReadString(trim(temp), 'year' , Self[i].year);
    end;

    if Prog <> nil then
      //we have completed a ROM so step the progress bar
      Prog.StepIt;

  end; //end of FOR loop

  //now save this updated Emufile
  Self.SaveToFile();
end;

procedure TQPROMlist.MirrorDirectories(Ini : TMemIniFile);
var
  Find : ThhFindFile;
  I, FIndex : Integer;
  Directory, Emulator : string;
  FilterList, FindList, DirList : TStringlist;
  FilterStream : TMemoryStream;
begin

  Find := ThhFindFile.Create(nil);
  Try

    //check that mirroring is enabled, if its not then exit
    If Ini.ReadBool('Mirror', 'ChkMirror', false)=false then
      raise EJException.Create(QP_MIRROR_NOT_ENABLED);

    Directory := Ini.ReadString('Mirror', 'TxtDir', '');
    If Directory = '' then
      raise EJException.Create(QP_MIRROR_NO_DIRECTORIES);

    //now we need the filter string(!)
    FilterStream := TMemoryStream.Create;
    Try
      FilterList := TStringList.Create;
      Ini.ReadBinaryStream('Mirror', 'LstFilter', FilterStream);
      FilterList.LoadFromStream(FilterStream);
      Find.Filter := '';
      for i := 0 to (filterlist.Count - 1) do
        Find.Filter := Find.Filter + ';' + filterlist.Strings[i];

    Finally
      FreeAndNil(FilterStream);
      FreeAndNil(FilterList);
    end;

    //finally get the emulator
    Emulator := Ini.ReadString('Mirror', 'CmbEmu', '');

    //now finalise the Find setup and run it
    Find.Recurse := False;

    //create a stringlist to hold ALL found files from our scans
    FindList := TStringList.Create;
    try

      //create a stringlist to hold all the directories to scan
      DirList := TStringList.Create;
      try

        //parse the directory string into seperate - usuable directories.
        StrTokenToStrings(Directory,';', DirList);

        //now execute a search on each directory and
        //amalgamate all the results into one stringlist.
        For i := 0 to DirList.Count-1 do
        begin
          Find.Directory := DirList.Strings[i];
          Find.Execute;
          FindList.AddStrings(Find.Files);
        end;

      Finally
        FreeAndNil(DirList);
      end;

      //now we have all the files found in the directories in findlist
      //loop through all the roms and see if it occurs in the findlist
      //if it doesnt then remove the rom, if it does then remove
      //the entry in the findlist.
      For i := Self.Count-1 downto 0 do
      begin

        //while we are looping, check that the emulator matches.
        if JCLStrings.StrCompare(Emulator, Self[i].Emulator) <> 0 then
          Self[i].Emulator := Emulator;

        FIndex := FindList.IndexOf(Self[i].Path);
        if (FIndex = -1) then
          Self.Delete(i)
        else
          FindList.Delete(FIndex);
      end;

      //by now we have eliminated any entry in the ROMS array that
      //isnt in the findlist.  and any entry in FindList that was
      //already in the ROMlist has been removed also, so finally
      //just loop through and add the results in findlist to romlist.
      AddFromStrings(FindList, Emulator, '', lmNone, False);

    Finally
      FreeAndNil(FindList);
    end;

  Finally
    FreeAndNil(Find);
  end;

  Self.SaveToFile();
end;

{-----------------------------------------------------------------------------}

procedure TQPROMlist.MoveTo(Source, Destination : Integer);
begin

  //Wrapper for the move function, which checks users arent doing daft things.

  If (Source < 0) or (Source > self.Count) then
    exit;
  If (Destination < 0) or (Destination > self.Count) then
    exit;

  If Source <> Destination then
    self.Move(Source, Destination);

end;

{-----------------------------------------------------------------------------}

Procedure TQPROMlist.Query(var MatchList : TObjectList; smArray : TObjectList; MatchAll : Boolean);
var
  i : Integer;
begin

  for i := 0 to Self.Count-1 do
    if Self[i].MatchesQuery(smArray, MatchAll) then
      MatchList.Add(Self[i]);

end;

{-----------------------------------------------------------------------------}

// checks to see if this rom already exists in the currently loaded ROMSlist.
// This is done by filepath.  Also needs to take into account roms inside a
// zip file, as roms inside a zip can have the same path (to the zip)
// but will have a different internal ROM name.
function TQPROMlist.ROMExists(Path : String; zipname : string = ''):boolean;
var
  i : integer;
begin

  result := false;

  //If a zipname parameter was supplied, this means we need to check for
  //duplicates which are inside a zip file (thus the filepaths will be the same)
  If ZipName = '' then
  begin
    for i:= 0 to self.Count-1 do
      if (StrCompare(path, self[i].path) = 0) then
      Begin
        result := true;
        Break;
      End;
  end
  else
  begin
    for i := 0 to self.Count-1 do
      if StrCompare(ZipName, self[i].ZipName) = 0 then
      begin
        result := true;
        break;
      end;
  end;

end;

{-----------------------------------------------------------------------------}

function TQPROMlist.ROMIsIn(Clone, Path: String; Searchlist: TQPROMlist): Integer;
var
  I : Integer;
begin
  Result := -1;

  For i := 0 to SearchList.Count-1 do
  begin
    if ( StrCompare(Clone, SearchList[i].MAMEname) = 0 ) and ( strCompare(Path, SearchList[i].Path) = 0 ) then
    begin
      Result := i;
      break;
    end;
  end;

end;

{-----------------------------------------------------------------------------}

procedure TQPROMlist.RunRandom(EList : TQPEmuList; Tools : TQPToolList; Settings : TQPSettings; NeverPlayed : boolean);
var
  RandROM : Integer;
  Emu : TQPEmu;
  RunOpt : TQPRunOptions;
  Attempt : Integer;
begin

  //Check that the ROMS array actually has entries.
  If Self.Count > 0 then
  begin

    //Initialise the random number generator.
    Randomize;

    Attempt := 0;
    Emu := nil;

    While (Emu = nil) and (Attempt < 5) do
    begin
      RandROM := Random(Self.Count);

      if (NeverPlayed = True) and (Self[RandROM].NumPlay > 0) then
        // the user wants a rom thats never been played.. this has been - try again!
        Emu := nil
      else
        Emu := EList.GetEmuForROM(Self[RandROM]);
      
      Inc(Attempt);
    end;

    If Emu <> nil then
    begin

      RunOpt.GeneralPowerScheme := Settings.RunOptions.GeneralPowerScheme;
      if Emu.ExtractDest = qemGeneral then
        RunOpt.ExtractMode := Settings.RunOptions.ExtractMode
      else
        RunOpt.ExtractMode := Emu.ExtractDest;

      if RunOpt.ExtractMode = qemROMDir then
        RunOpt.ExtractDir := ExtractFilePath(Self[RandROM].Path)
      else
        RunOpt.ExtractDir := Settings.ExtractModeToPath(RunOpt.ExtractMode);

      // the run options will have paths filled in, except if its a ROM
      if RunOpt.ExtractMode = qemROMDir then
        RunOpt.ExtractDir := ExtractFilePath(Self[RandROM].Path);

      Emu.Run(Self[RandROM], Tools, RunOpt);

      //Save the ROM Data
      Self.SaveToFile();
    end
    else
      raise EJException.Create(QP_RANDOM_RUN_FAILURE);
      
  end
  else
    raise EJException.Create(QP_MAINFRM_NO_ROMS);

end;

{-----------------------------------------------------------------------------}

Procedure TQPROMlist.SaveToFile();
var
  z : integer;
  StrList : TStrings;
  ROM : TQPRom;
begin

  //need to check if the RomFile parameter is blank or not
  if _FileName = '' then
    exit;

  //check that we are 'allowed' to write to the disk
  If not _AllowWrite then
    exit;

  StrList := TStringList.Create;
  Try

    StrList.Clear;
    StrList.Capacity := self.Count;
    StrList.Add('ROM DataFile Version : 1.1');

    For z := 0 to self.Count-1 do
    Begin

      Rom := self[z];
      If (Rom <> nil) and (ROM.name <> '') AND (ROM.path <>'') then
        StrList.Add(ROM.ToString);

    end;

    StrList.SaveToFile(_FileName);
  Finally
    FreeAndNil(StrList);
  end;
    
end;

{-----------------------------------------------------------------------------}

procedure TQPROMlist.SetMameCategories(SettingsDir : String);
Var
  I : integer;
  ini : TMemIniFile;
begin

  if fileexists(SettingsDir + 'catver.ini') then
  begin
    ini := TMemIniFile.Create(SettingsDir+'catver.ini');
    try

      for i := 0 to self.Count-1 do
        self[i].SetMameGameCategory(Ini);

      self.SaveToFile();

    finally
      FreeAndNil(ini);
    end;
  end
  else
    raise EJException.Create(QP_NO_CATVER);

end;

procedure TQPROMlist.SetMameMultiPlayer(SettingsDir : String);
Var
  I : integer;
  ini : TMemIniFile;
begin

  if fileexists(SettingsDir + 'nplayers.ini') then
  begin
    ini := TMemIniFile.Create(SettingsDir+'nplayers.ini');
    try

      for i := 0 to self.Count-1 do
        self[i].SetMameMultiplayer(Ini);

      self.SaveToFile();

    finally
      FreeAndNil(ini);
    end;
  end
  else
    raise EJException.Create(QP_NO_NPLAYERS);

end;


end.
