unit uEmu;

interface

uses Windows, SysUtils, Dialogs, Controls, Classes, IniFiles, uEXE, uRom,
     uEmuFindObj, uExeList, uQPMiscTypes;

type

  TQPSystem = class
  Protected
    Fname : string;
    FTotalEmus : Integer;
  Public
    Property Name : String Read FName Write Fname;
    Property TotalEmus : Integer read FTotalEmus Write FTotalEmus;
  end;

  TQPEmu = Class(TQPExe)
  Private
    _EmulatorID : Integer;
    _system : String;      //Stores the emulators system.
    _ExtractDest : TQPExtractDest;
    _ChangeToPwrScheme : String;
    _DisableScreenSaver,        //Disable the screensaver while running games
    _DisableWinKey : Boolean;   //Disable the windows key while running games
    Function GetIsMAME() : Boolean;
    Function GetIsMAMEArcade() : Boolean;
    Function GetIsZinc() : Boolean;
  public
    property ExePath : TFileName Read _path; //added so the mame scanner can get the user selected mame exe's filename
    Property EmulatorID : Integer read _EmulatorID write _EmulatorID;
    Property System : String Read _system Write _system;
    Property ExtractDest : TQPExtractDest read _ExtractDest Write _ExtractDest;
    Property ChangeToPwrScheme : String read _ChangeToPwrScheme write _ChangeToPwrScheme;
    Property DisableScreenSaver : Boolean Read _DisableScreenSaver Write _DisableScreenSaver;
    Property DisableWinKey : Boolean Read _DisableWinKey Write _DisableWinKey;
    
    // IsMAME simply does a check on the emulator filename and sees if it includes the word 'MAME'.. cheap..
    Property IsMAME : Boolean Read GetIsMAME;
    Property IsMAMEArcade : Boolean Read GetIsMAMEArcade;
    Property IsZinc : Boolean read GetIsZinc;

    constructor Create;
    destructor Destroy;override;
    procedure Assign(Source : TQPEmu);
    procedure ImportEmuFindObj(EFindObj : TQPEmuFindObj; EmuPath : TFileName);
    procedure LegacyLoadAndConvert(SectionName : String; var Ini : TMemIniFile; ID : Integer);
    procedure LoadFromIni(SectionName : String; var Ini : TMemIniFile; ID : Integer);
    procedure MameConfigCheck();
    procedure MameCreateDataFile(DataDir : String);
    Procedure Run(ROMObj : TQPROM; Tools : TQPExeList; RunOpt : TQPRunOptions);
    procedure SaveIntoIni(var Ini : TMemIniFile);
    Procedure ZincSupportedGames(WorkDir : String);
  end;

  pQPEmu = ^TQPEmu;

implementation

{$I Compilers.inc}

uses JCLStrings, JCLShell, 
     uQPConst, ujMiscResourceStrs, ujProcesses, uJFile, ujPowerSchemes,
     ujUtilities, ujWindowsMisc;

{-----------------------------------------------------------------------------}
{TQPEmu}
{-----------------------------------------------------------------------------}

constructor TQPEmu.Create;
Begin
  inherited;
  _EmulatorID := -1;
  _WaitForEXEEnd := True;
  _DisableScreenSaver := true;
  _DisableWinKey := true;
  _ExtractDest := qemGeneral;
  _ChangeToPwrScheme := QP_USE_GENERAL_SETTING;
End;

{-----------------------------------------------------------------------------}

destructor TQPEmu.Destroy;
begin
  inherited;
end;

{-----------------------------------------------------------------------------}

procedure TQPEmu.Assign(Source: TQPEmu);
begin
  //call the assign method of TQPExe which takes care of the inherited properties.
  inherited Assign(TQPExe(Source));
  _EmulatorID := Source.EmulatorID;
  _system := Source.System;
  _DisableScreenSaver := Source.DisableScreenSaver;
  _DisableWinKey := Source.DisableWinKey;
  _ChangeToPwrScheme  := Source.ChangeToPwrScheme;
  _ExtractDest := Source.ExtractDest;
end;

{-----------------------------------------------------------------------------}
// Following functions are for properties..

Function TQPEmu.GetIsMAME() : Boolean;
begin
  //a simple check to see if this emulator can be considered to 'be' MAME.
  Result := (JCLStrings.StrIPos('mame', ExtractFileName(Self._path)) <> 0)
end;

Function TQPEmu.GetIsZinc() : Boolean;
begin
  Result := (JCLStrings.StrCompare('zinc.exe', ExtractFileName(Self._path))=0);
end;

Function TQPEmu.GetIsMAMEArcade() : Boolean;
begin
  //a simple check to see if this emulator can be considered to 'be' MAME.
  //later a more complex check to narrow down on possible arcade emus
  //an alternative to modifcation is extension with a GetISMAMEArcade boolean...
  Result := (
    (JCLStrings.StrIPos('mame', ExtractFileName(Self._path)) <> 0)
    or (JCLStrings.StrIPos('retroarch', ExtractFileName(Self._path)) <> 0)
  ) and (Self._system = 'Arcade')
end;

{-----------------------------------------------------------------------------}


procedure TQPEmu.ImportEmuFindObj(EFindObj : TQPEmuFindObj; EmuPath : TFileName);
var
  ExeType : String;
begin
  //If its an arcade emulator then stick a DOS or WIN on the end
  //of the name.  Why?  Because I want to..
  if StrCompare(EFindObj.system, 'arcade')=0 then
  begin
    ExeType := ExeTypeToString(EmuPath);
    if ExeType = J_EXE_WIN32 then
      _name := EFindObj.name + ' ' + J_EXE_WIN32
    else if ExeType = J_EXE_DOS then
      _name := EFindObj.name + ' ' + J_EXE_DOS
    else
      _name := EFindObj.name;

  end
  else
    _name := EFindObj.name;

  _Path := EmuPath;
  _System := EFindObj.system;
  _cfg := '';

  If FileExists(extractfilepath(EmuPath) + EFindObj.cfg + '.cfg') then
    _cfg := extractfilepath(EmuPath) + EFindObj.cfg + '.cfg'
  else If FileExists(extractfilepath(EmuPath) + EFindObj.cfg + '.ini') then
      _cfg := extractfilepath(EmuPath) + EFindObj.cfg + '.ini';

  Self._HomePage := EFindObj.HomePage;
  _CmdLine := EFindObj.CmdLine;
  _ShellEx := EFindObj.ShellEx;
  _ShortEXE := EFindObj.ShortExe;
  _CompressSupport.AddStrings(EFindObj.Compress);
  _Verify := EFindObj.Verify;
  _DisableScreenSaver := EFindObj.DisableScreenSaver;
  _DisableWinKey := EFindObj.DisableWinKey;
  _ChangeToPwrScheme := QP_USE_GENERAL_SETTING;
  _parameters := EFindObj.Param;
  _ExtractDest := qemGeneral;
end;

{-----------------------------------------------------------------------------}

procedure TQPEmu.LegacyLoadAndConvert(SectionName : String; var Ini : TMemIniFile; ID : Integer);
begin
  // This function will load an old emulator and TRY to convert it into
  // the new format (using the parameter to do all the hard work)
  // The conversion will probably work fine, but its HIGHLY recommended the user rescan their emulators.
  _EmulatorID := ID;
  _name := SectionName;
  _Version := Ini.ReadString(SectionName, 'Version', '');
  _path := Ini.ReadString(SectionName, 'Path','');
  _cfg := Ini.ReadString(SectionName, 'cfg','');
  _system := Ini.ReadString(SectionName, 'system','');
  _HomePage := Ini.ReadString(SectionName, 'HomePage','');
  _CmdLine := Ini.ReadBool(SectionName, 'CmdLine', true);
  _UseLaunchApp := Ini.ReadBool(SectionName, 'UseLaunchApp', False);
  _ShellEx := Ini.ReadBool(SectionName, 'ShellEx', false);
  _ShortExe := Ini.ReadBool(SectionName, 'ShortExe', false);
  _DisableScreenSaver := Ini.ReadBool(SectionName, 'DisScrSvr', false);
  _DisableWinKey := Ini.ReadBool(SectionName, 'DisWinKey', false);
  _Verify := Ini.ReadBool(SectionName, 'Verify', false);

  Self.SupportsCompressed['.zip'] := Ini.ReadBool(SectionName, 'zip', false);
  DiscoverNewCompression();

  //ok the decision is to just dump whatever is in the parameters field at the minute.
  _parameters := '';

  if Ini.ReadBool(SectionName, 'UseSpeechMarks', false) then
    _Parameters := '"';

  if Ini.ReadBool(SectionName, 'ShortRom', false) then
    _Parameters := _Parameters + '%SHORTROM%'
  else
    _Parameters := _Parameters + '%ROM%';
    
  //check if we need to close the speech marks
  if Ini.ReadBool(SectionName, 'UseSpeechMarks', false) then
    _Parameters := _Parameters + '"';

  if Ini.ReadBool(SectionName, 'mame' , false) then
    _Parameters := '%ROMMAME% -rompath %SHORTDIR%';

  _IconIndex := -1;
end;
{-----------------------------------------------------------------------------}

procedure TQPEmu.LoadFromIni(SectionName : String; var Ini : TMemIniFile; ID : Integer);
var
  CompStream : TMemoryStream;
begin
  //the unique ID should ALWAYS stay throughout ALL of the runtime.
  _EmulatorID := ID;
  _name := SectionName;
  _Version := Ini.ReadString(SectionName, 'Version', '');
  _path := Ini.ReadString(SectionName, 'Path','');
  _cfg := Ini.ReadString(SectionName, 'cfg','');
  _system := Ini.ReadString(SectionName, 'system','');
  _HomePage := Ini.ReadString(SectionName, 'HomePage','');
  _parameters := Ini.ReadString(SectionName, 'parameters','');
  _PreLaunchCmd := Ini.ReadString(SectionName, 'PreLaunchCmd', '');
  _PreLaunchWait := Ini.ReadBool(SectionName, 'PreLaunchWait', True);
  _AfterLaunchCmd := Ini.ReadString(SectionName, 'AfterLaunchCmd', '');
  _AfterLaunchWait := Ini.ReadBool(SectionName, 'AfterLaunchWait', True);
  _CmdLine := Ini.ReadBool(SectionName, 'CmdLine', true);
  _UseLaunchApp := Ini.ReadBool(SectionName, 'UseLaunchApp', False);
  _ShellEx := Ini.ReadBool(SectionName, 'ShellEx', false);
  _ShortExe := Ini.ReadBool(SectionName, 'ShortExe', false);
  _DisableScreenSaver := Ini.ReadBool(SectionName, 'DisScrSvr', false);
  _DisableWinKey := Ini.ReadBool(SectionName, 'DisWinKey', false);
  _ChangeToPwrScheme := Ini.ReadString(SectionName, 'PwrScheme', QP_USE_GENERAL_SETTING);
  _Verify := Ini.ReadBool(SectionName, 'Verify', false);
  _ExtractDest := TQPExtractDest(Ini.ReadInteger(SectionName, 'ExtractDest', 3));
  _Priority := TJPriority(Ini.ReadInteger(SectionName, 'Priority', 3));

  _IconIndex := -1;

  //media settings
  _ShowExeTab := Ini.ReadBool(SectionName, 'ShowExeTab', False);
  _ExeImage := Ini.ReadString(SectionName, 'ExeImage', '');
  _ShowAddInfo := Ini.ReadBool(SectionName, 'ShowAddInfo', False);

  CompStream := TMemoryStream.Create;
  try

    Ini.ReadBinaryStream(SectionName, 'AddInfo', CompStream);
    _AddInfo.LoadFromStream(CompStream);
    CompStream.Clear;

    Ini.ReadBinaryStream(SectionName, 'Compression', CompStream);
    _CompressSupport.LoadFromStream(CompStream);
    DiscoverNewCompression();
  finally
    FreeAndNil(CompStream);
  end;

end;

{-----------------------------------------------------------------------------}

Procedure TQPEmu.MameConfigCheck();
Var
  CommandLine, pathToWrite : String;
Begin
  If IsMame then
    If not FileExists(ChangeFileExt(_Path, '.ini')) and
       not FileExists(ExtractFilePath(_Path) + 'mame.ini') and   //bugfix - we weren't looking for mame's primary ini lookup - a file called mame.ini. But amusingly we WERE creating it if we didn't find 'emu.ini'
       not FileExists(ExtractFilePath(_Path) + 'ini\mame.ini') and      //and remember this ini if its mameui
       not FileExists(ChangeFileExt(_Path, '.cfg')) then
      if MessageDlg(QP_MAME_INI_NOT_FOUND,
            mtConfirmation, [mbYes, mbNo], 0) = mrYes then
      begin
        CommandLine := ExtractShortPathName(_Path) + ' -createconfig';
        //assume that if emu is a mame type, and has an ini FOLDER, its mameUI or similar, and mame.ini wants to be in there not in root
        if DirectoryExists(ExtractFilePath(_Path) + 'ini\') then
            begin
            pathToWrite := ExtractFilePath(_Path);
            pathToWrite := pathToWrite + 'ini\';
            end
        else
            pathToWrite := ExtractFilePath(_Path);

        case Win32Platform of
        0,1: RunProcess('command.com /c '+CommandLine, True, pathToWrite, SW_SHOWMINIMIZED); //Win32s and Win95
        2: RunProcess('cmd.exe /c '+CommandLine, True, pathToWrite,SW_SHOWMINIMIZED); // WinNT and Win2000
        end;

      end;

End;

{-----------------------------------------------------------------------------}

Procedure TQPEmu.MameCreateDataFile(DataDir : String);
var
  GameDoc,
  NameDoc,
  commandline,
  RealName, IniName, Err : String;
  I, e, gpos : Integer;
  InputName, InputGame, OutputFile : TStringList;
  temp : String[8];
Begin
  // this is a complicated function - basically it will create a MAME.ini file
  // it needs the name of the ini file - based on the name of the emulator
  // and the path to MAME

  IniName := DataDir + _name + '.ini';

    // the process of creating the QP MAME.ini file is 2 fold
    // firstly we need to create the 2 temp files which hold ROM information
    // secondly we convert these 2 files into our final product.

    // get our temporary names and delete the files if they already exist
    NameDoc := ExtractShortPathName(DataDir) + 'name.tmp';
    GameDoc := ExtractShortPathName(DataDir) + 'game.tmp';

    If FileExists(NameDoc) then
      DeleteFile(NameDoc);
    If FileExists(GameDoc) then
      DeleteFile(GameDoc);

    //generate the listfull txt document
    commandline := extractshortpathname(Self._path) +' -listfull > "' + namedoc + '"';
    case Win32Platform of
      0,1: Err := RunProcess('command.com /c '+CommandLine, True,'', SW_SHOWMINNOACTIVE	); //Win32s and Win95
      2: Err := RunProcess('cmd.exe /c '+CommandLine, True,'',SW_SHOWMINNOACTIVE	); // WinNT and Win2000
    end;

    if Err <> '' then
      raise EJException.Create(QP_MAME_GENERATE_DATA_ERR + ' - ' + Err);

    //generate the listgames txt document - for year information.
    commandline := extractshortpathname(Self._path) +' -listgames -sortname > ' + gamedoc;
    case Win32Platform of
      0,1: Err := RunProcess('command.com /c '+CommandLine, True,'', SW_SHOWMINNOACTIVE	); //Win32s and Win95
      2: Err := RunProcess('cmd.exe /c '+CommandLine, True,'',SW_SHOWMINNOACTIVE	); // WinNT and Win2000
    end;

    if Err <> '' then
      raise EJException.Create(QP_MAME_GENERATE_DATA_ERR + ' - ' + Err);

    //now we have 2 tmp files containing MAME rom information
    //create our Ini object to store our new data

    InputName := TStringList.Create;
    try
      InputGame := TStringList.Create;
      OutputFile := TStringList.Create;
      //load the first MAME tmp file into our stringlist
      InputName.LoadFromFile(NameDoc);
      InputGame.LoadFromFile(GameDoc);

      //add in some custom QP information
      OutputFile.Add('[Quickplay Internal Data]');
      OutputFile.Add('Version=3.6 Generated File');
      OutputFile.Add('MamePath=' + _path);
      OutputFile.Add('');

      //skip the first line of the file
      For i := 1 to InputName.Count-1 do
      Begin
        temp := InputName.Strings[i];
        RealName := Copy(InputName.Strings[i], 12, Length(InputName.Strings[i])-12 );
        OutputFile.Add('['+ trim(temp) +']');
        OutputFile.Add('name=' + RealName);

        gpos := -1;
        //now we need to find the year of the game?
        for e := 0 to InputGame.Count-1 do
        begin
          if Pos(RealName, InputGame.Strings[e]) <> 0 then
          begin
            gpos := e;
            break;
          end;
        end;

        if gpos <> -1 then
        begin
          OutputFile.Add('year='+Copy(InputGame.Strings[gpos],0,4));
          InputGame.Delete(gpos);
        end
        else
          OutputFile.Add('year=unknown');

        //add in the spacer
        OutputFile.Add('');

      end;

      //save our output file to disk
      OutputFile.SaveToFile(IniName);

    finally
      FreeAndNil(InputName);
      FreeAndNil(InputGame);
      FreeAndNil(OutputFile);
    end;

    // time to clean up any files we have left around!
    If FileExists(GameDoc) then
      DeleteFile(GameDoc);
    If FileExists(NameDoc) then
      DeleteFile(NameDoc);

    // and give one final check that the ini exists before ending the function
    If not FileExists(IniName) then
      raise EJException.Create(QP_MAME_GENERATE_DATA_ERR);

End;

{-----------------------------------------------------------------------------}

Procedure TQPEmu.Run(ROMObj : TQPROM; Tools : TQPExeList; RunOpt : TQPRunOptions);
var
  RevertScheme : Boolean;
  NewScheme, OldScheme : String;
begin
  //disable the winkeys if required
  If _DisableWinKey then
    WinKeyOnOff(false);

  //disable the screensaver if required
  If _DisableScreenSaver  then
    ScreenSaverOnOff(False);

  //work out what to do about power schemes
  if (JCLStrings.StrCompare(_ChangeToPwrScheme, QP_USE_GENERAL_SETTING)=0) then
    NewScheme := RunOpt.GeneralPowerScheme
  else
    NewScheme := Self._ChangeToPwrScheme;

  if JCLStrings.StrCompare( NewScheme, QP_DONT_CHANGE) <> 0 then
  begin
    RevertScheme := True;
    OldScheme := ujPowerSchemes.GetActivePowerScheme();
    ujPowerSchemes.SetActivePowerScheme(NewScheme);
  end
  else
    RevertScheme := False;

  try
    Inherited Run(ROMObj, Tools, IncludeTrailingPathDelimiter(RunOpt.ExtractDir));    
  finally

    if RevertScheme then
      ujPowerSchemes.SetActivePowerScheme(OldScheme);

    //re-enable the screensaver if required
    If _DisableScreenSaver then
      ScreenSaverOnOff(True);

    //re-enable the win keys if required
    If _DisableWinKey then
      WinKeyOnOff(true);
  end;
end;

{-----------------------------------------------------------------------------}


procedure TQPEmu.SaveIntoIni(var Ini : TMemIniFile);
var
  CompStream : TMemoryStream;
begin
  //check that the emulator has a valid name AND a valid Path
  if (_Name = '') or (_Path = '') then
    exit;
  Ini.EraseSection(_Name);
  Ini.WriteString(_Name, 'Version', _Version);
  Ini.WriteString(_Name, 'path', _path);
  Ini.WriteString(_Name, 'cfg', _cfg);
  Ini.WriteString(_Name, 'system', _system);
  Ini.WriteString(_Name, 'HomePage', _HomePage);
  Ini.WriteString(_Name, 'PreLaunchCmd', _PreLaunchCmd);
  Ini.WriteBool(_Name, 'PreLaunchWait', _PreLaunchWait);
  Ini.WriteString(_Name, 'AfterLaunchCmd', _AfterLaunchCmd);
  Ini.WriteBool(_Name, 'AfterLaunchWait', _AfterLaunchWait);
  Ini.WriteString(_Name, 'parameters', _parameters);
  Ini.WriteBool(_Name, 'CmdLine', _CmdLine);
  Ini.WriteBool(_Name, 'UseLaunchApp', _UseLaunchApp);
  Ini.writeBool(_Name, 'ShellEx', _ShellEx);
  Ini.writeBool(_Name, 'ShortExe', _ShortExe);
  Ini.writeBool(_Name, 'DisScrSvr', _DisableScreenSaver);
  Ini.writeBool(_Name, 'DisWinKey', _DisableWinKey);
  Ini.WriteString(_Name, 'PwrScheme', _ChangeToPwrScheme);
  Ini.writeBool(_Name, 'Verify', _Verify);
  Ini.WriteInteger(_Name, 'ExtractDest', Integer(_ExtractDest));
  Ini.WriteInteger(_Name, 'Priority', Integer(_Priority));

  //Media Settings
  Ini.WriteBool(_Name, 'ShowExeTab', _ShowExeTab);
  Ini.WriteString(_Name, 'ExeImage', _ExeImage);
  Ini.WriteBool(_Name, 'ShowAddInfo', _ShowAddInfo);

  CompStream := TMemoryStream.Create;
  try
    _CompressSupport.SaveToStream(CompStream);
    CompStream.Position := 0;
    Ini.WriteBinaryStream(_Name,'Compression', CompStream);

    CompStream.Clear;
    _AddInfo.SaveToStream(CompStream);
    CompStream.Position := 0;
    Ini.WriteBinaryStream(_Name, 'AddInfo', CompStream);
  finally
    FreeAndNil(CompStream);
  end;
end;

{-----------------------------------------------------------------------------}

Procedure TQPEmu.ZincSupportedGames(WorkDir : String);
var
  i : Integer;
  TmpStrings : TStringList;
  TmpFileName, IniFileName : String;
  NewIni : TStringList;
  TmpStr, CommandLine, Err : String;
begin

  IniFileName := IncludeTrailingPathDelimiter(WorkDir) + Self._name + '.ini';

  if not FileExists(IniFileName) then
  begin
    TmpFileName := extractshortpathname(WorkDir) + 'games.txt';
    //if this file already exists, dont bother re-creating it.
    if FileExists(TmpFileName) then
      DeleteFile(TmpFileName);

    //generate the listgames txt document
    commandline := extractshortpathname(Self._path) +' --list-games > ' + TmpFileName;
    case Win32Platform of
      0,1: Err := RunProcess('command.com /c '+CommandLine, True,'', SW_SHOWMINNOACTIVE	); //Win32s and Win95
      2: Err := RunProcess('cmd.exe /c '+CommandLine, True,'',SW_SHOWMINNOACTIVE	); // WinNT and Win2000
    end;

    if Err <> '' then
      raise EJException.Create(QP_MAME_GENERATE_DATA_ERR + ' - ' + Err);

    TmpStrings := TStringList.Create;
    try

      TmpStrings.LoadFromFile(TmpFileName);

      //now we have the list loaded into memory.
      NewIni := TStringList.Create;
      try

        //now we have to turn the ugly output from zinc into something usuable...
        //zinc sample output
        //  "  1 Star Gladiator (US 960627) [starglad, BIOS cpzn1]"
        //   <  ><                         ><        >
        For i := 1 to TmpStrings.Count-1 do
        begin
          //firstly get the name of this ROM

          //usually the name of the ROM can be found between a [ and a '
          TmpStr := JCLStrings.StrBetween(TmpStrings[i], '[', ',');
          // but on some roms its between a [ and a ].. craptastic..
          if TmpStr = '' then
            TmpStr := JCLStrings.StrBetween(TmpStrings[i], '[', ']');
          NewIni.Add('[' + Trim(TmpStr) + ']');

          //now get the number ID for this game
          TmpStr := Copy(TmpStrings[i], 0, 4);
          NewIni.Add('ID='+Trim(TmpStr));

          //now get the proper name for this game
          TmpStr := Copy(TmpStrings[i], 5, Pos('[', TmpStrings[i])-5);
          NewIni.Add('name=' + Trim(TmpStr));

          NewIni.Add('');
          NewIni.SaveToFile(IniFileName);
        end;

      finally
        FreeAndNil(NewIni);
      end;


    finally
      FreeAndNil(TmpStrings);
    end;

    if FileExists(TmpFileName) then
      DeleteFile(TmpFileName);

  end;
end;

end.
 
