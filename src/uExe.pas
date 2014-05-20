unit uExe;

interface

uses SysUtils, Classes, uROM, uExeList, ujProcesses;

Type
  TQPEXE = class(TObject)
  private
    Function PreRunROMConfigure(var ZipList : TStringList; ROMObj : TQPROM; ExtrDir : String) : String;  //returns new path to ROM.
    procedure AfterRunROMConfigure(var ZipList : TStringList; ROMObj : TQPROM; ExtrDir : String);
    Function ParamRequiresROM(Cmd : String) : Boolean;
  protected
    _name : String;             //The name of exe - PrimaryID!
    _Version : String;          //The exe version.
    _path : TFileName;          //The exe's path.
    _cfg : TFileName;           //Stores the path to the EXEs configuration file.
    _HomePage : String;         //Web address for exe, if there is one.
    _parameters : String;       //Parameters for running EXE, can use special QP variables.
    _PreLaunchCmd : String;     //Full Command to execute before running this exe.
    _AfterLaunchCmd : string;   //Full Command to execute after running this exe.
    _IconIndex : Integer;       //Index of the EXEs icon in an imagelist of icons.
    _UseLaunchApp : Boolean;    //use the QP mini launcher to run EXE
    _CmdLine : Boolean;         //The EXE supports parameters when being called.
    _ShellEx : Boolean;         //The EXE is integrated into the windows shell (file association!)
    _ShortExe : Boolean;        //Use the 8:3 EXE path when launching this tool (old exes require this)
    _Verify : Boolean;          //Verify compressed files before running.
    _WaitForEXEEnd : Boolean;   //Wait for the exe to end before continuing running QuickPlay
    _PreLaunchWait : Boolean;   //wait for the prelaunch tool to end before running exe.
    _AfterLaunchWait : Boolean; //wait for the afterlaunch tool to end before running exe.
    _CompressSupport : TStringList;  //stringlist containing support compressed formats.  Its in Name-Value mode.
    _Priority : TjPriority;     //holds the priority you want to launch the process with.

    //Media Related Options
    _ShowExeTab : Boolean;
    _ExeImage : TFilename;
    _ShowAddInfo : Boolean;
    _AddInfo : TStringList;

    Function GetCompressed(FileExt: String) : Boolean;
    procedure SetCompressed(FileExt: String; value : Boolean);
  public

    Property Name : String Read _Name Write _Name;
    Property Version : String Read _Version Write _Version;
    Property Path : TfileName Read _path Write _path;
    Property CfgFile : TFileName Read _cfg Write _cfg;
    Property HomePage : String Read _HomePage Write _HomePage;
    Property IconIndex : Integer Read _IconIndex Write _IconIndex;
    Property Parameters : String Read _parameters Write _parameters;
    Property PreLaunchCmd : String Read _PreLaunchCmd Write _PreLaunchCmd;
    Property PreLaunchWait : Boolean Read _PreLaunchWait write _PreLaunchWait;
    Property AfterLaunchCmd : String Read _AfterLaunchCmd write _AfterLaunchCmd;
    Property AfterLaunchWait : Boolean read _AfterLaunchWait write _AfterLaunchWait;
    Property CmdLine : Boolean Read _CmdLine Write _CmdLine;
    Property ShellEx : Boolean Read _ShellEx Write _ShellEx;
    Property ShortExe : Boolean Read _ShortExe Write _ShortExe;
    Property UseLaunchApp : Boolean Read _UseLaunchApp write _UseLaunchApp;
    Property WaitForEXEEnd : Boolean read _WaitForEXEEnd write _WaitForEXEEnd;
    Property Verify : Boolean Read _Verify Write _Verify;
    Property Priority :TJPriority read _Priority write _Priority;

    //Media Properties
    Property ShowExeTab : Boolean read _ShowExeTab write _ShowExeTab;
    Property ExeImage : TFileName read _ExeImage write _ExeImage;
    Property ShowAddInfo : Boolean read _ShowAddInfo write _ShowAddInfo;
    Property AdditionalInfo : TStringList read _AddInfo write _AddInfo;

    //Property for dealing with compressed file support
    property SupportsCompressed[FileExt: String]: Boolean read GetCompressed write SetCompressed;
    Property CompressStrings : TStringList read _CompressSupport write _CompressSupport;

    constructor Create;
    destructor Destroy;override;
    Procedure Assign(Source : TQPExe);
    Function DecodeParameterVariables(CmdLine : String; ROMObj : TQPROM; Tools : TQPExeList; AltROMPath : TFileName = '') : String;overload;
    Function DecodeParameterVariables(ROMObj : TQPRom; Tools : TQPExeList; AltROMPath : TFileName = '') : String;overload;
    procedure DiscoverNewCompression();
    procedure OpenHomePage();
    Procedure Run();overload;
    Procedure Run(Tools : TQPExeList; ExtrDir : String);overload;
    Procedure Run(RomObj : TQPRom; Tools : TQPExeList; ExtrDir : String);overload;
  end;

implementation

uses Windows, Forms, ShellAPI,
     JCLStrings, JCLShell,
     uQPCompObj, ujFile, uToolList, uQPConst, uTools, uQPMiscTypes, ujCompressResourceStrs,
     ujCompression, uJUtilities;

{-----------------------------------------------------------------------------}

constructor TQPEXE.Create;
begin
  inherited;
  _parameters := '"%ROM%"';
  _PreLaunchWait := True;
  _AfterLaunchWait := True;
  _CmdLine := true;
  _IconIndex := -1;
  _CompressSupport := TStringList.Create;
  _Priority := jprNormal;

  _AddInfo := TStringList.Create;
end;

{-----------------------------------------------------------------------------}

destructor TQPEXE.Destroy;
begin
  FreeAndNil(_AddInfo);
  FreeAndNil(_CompressSupport);
  inherited;
end;

{-----------------------------------------------------------------------------}

Function TQPEXE.GetCompressed(FileExt: String) : Boolean;
var
  Ext : String;
begin
  Ext := ujFile.GetVirtualFileExtension(FileExt);
  if _CompressSupport.IndexOfName(Ext) <> -1 then
    Result := StrToBool(_CompressSupport.Values[Ext])
  else
    Result := False;
end;

{-----------------------------------------------------------------------------}

procedure TQPEXE.SetCompressed(FileExt: String; value : Boolean);
var
  Ext : String;
begin
  Ext := ujFile.GetVirtualFileExtension(FileExt);
  Self._CompressSupport.Values[Ext] := BoolToStr(Value);
end;

{-----------------------------------------------------------------------------}

procedure TQPExe.DiscoverNewCompression();
var
  Exts : TStringList;
  i : Integer;
  CurExt : String;
begin
  Exts := TStringList.Create;
  try
    Exts.Text := uQPCompObj.Compression.SupportedFileExts(cmRead);
    for i := 0 to Exts.Count-1 do
    begin
      CurExt := ujFile.GetVirtualFileExtension(Exts[i]);
      if self._CompressSupport.IndexOfName(CurExt) = -1 then
        self.SupportsCompressed[CurExt] := False;
    end;
  finally
    FreeAndNil(Exts);
  end;
end;

{-----------------------------------------------------------------------------}
{  PUBLIC ROUTINES  }
{-----------------------------------------------------------------------------}

Procedure TQPEXE.Assign(Source : TQPExe);
begin
  _name := Source.Name;
  _Version := Source.Version;
  _path := Source.Path;
  _cfg := Source.CfgFile;
  _HomePage := Source.HomePage;
  _Parameters := Source.Parameters;
  _PreLaunchCmd := Source.PreLaunchCmd;
  _PreLaunchWait := Source.PreLaunchWait;
  _AfterLaunchCmd := Source.AfterLaunchCmd;
  _AfterLaunchWait := Source.AfterLaunchWait;
  _CmdLine := Source.CmdLine;
  _ShellEx := Source.ShellEx;
  _UseLaunchApp := Source.UseLaunchApp;
  _ShortExe := Source.ShortExe;
  _Verify := Source.Verify;
  _IconIndex := Source.IconIndex;
  _CompressSupport.Clear;
  _CompressSupport.AddStrings(Source._CompressSupport);
  _Priority := Source.Priority;

  //Media Options
  _ShowExeTab := Source.ShowExeTab;
  _ExeImage := Source.ExeImage;
  _ShowAddInfo := Source.ShowAddInfo;
  _AddInfo.Clear;
  _AddInfo.AddStrings(Source.AdditionalInfo);

end;

{-----------------------------------------------------------------------------}

Function TQPEXE.DecodeParameterVariables(CmdLine : String; ROMObj : TQPROM;
                        Tools : TQPExeList; AltROMPath : TFileName = '') : String;
var
  LinkTool : TQPTool;
  VarName : String;
  UsePath : String;
begin

  Result := CmdLine;

  //only do the replacements if the ROMobj has been specified.
  if ROMObj <> nil then
  begin

    if (AltROMPath <> '') then
      UsePath := AltROMPath
    else
      UsePath := ROMObj.Path;

    JCLStrings.StrReplace(Result, '%ROM%', UsePath, [rfIgnoreCase, rfReplaceAll]);
    if ROMObj.MAMEname <> '' then
      JCLStrings.StrReplace(Result, '%ROMMAME%', ROMObj.MAMEname, [rfIgnoreCase, rfReplaceAll])
    else
      JCLStrings.StrReplace(Result, '%ROMMAME%', ChangeFileExt(ExtractFileName(UsePath),''), [rfIgnoreCase, rfReplaceAll]);

    JCLStrings.StrReplace(Result, '%ROMFILENAME%', ExtractFileName(UsePath), [rfIgnoreCase, rfReplaceAll]);
    JCLStrings.StrReplace(Result, '%ROMFILENAMENOEXT%', ChangeFileExt(ExtractFileName(UsePath),''), [rfIgnoreCase, rfReplaceAll]);
    JCLStrings.StrReplace(Result, '%ROMDIR%', ExtractFilePath(UsePath), [rfIgnoreCase, rfReplaceAll]);
    JCLStrings.StrReplace(Result, '%SHORTROM%', ExtractShortPathName(UsePath), [rfIgnoreCase, rfReplaceAll]);
    JCLStrings.StrReplace(Result, '%SHORTDIR%', ExtractFilePath(ExtractShortPathName(UsePath)), [rfIgnoreCase, rfReplaceAll]);
  end;

  //Emu specific variables
  JCLStrings.StrReplace(Result, '%EXECFG%', self._cfg, [rfIgnoreCase, rfReplaceAll]);
  JCLStrings.StrReplace(Result, '%EXEPATH%', self._path, [rfIgnoreCase, rfReplaceAll]);
  JCLStrings.StrReplace(Result, '%EXEDIR%', ExtractFilePath(self._path), [rfIgnoreCase, rfReplaceAll]);

  //Tool specific variables.
  //%TOOL:toolvariable%
  if (Tools <> nil) and (JclStrings.StrIPos('%TOOL:', Result) <> 0) then
  begin
    //the cmdline contains a tool.
    VarName := JCLStrings.StrBetween(Result, ':', '%');
    LinkTool := TQPToolList(Tools).ItemsByVarName[VarName];
    if LinkTool <> nil then
    begin
      JCLStrings.StrReplace(Result, '%TOOL:'+VarName+'%', LinkTool.Path + ' '+LinkTool.DecodeParameterVariables(LinkTool.Parameters, ROMObj, nil) , [rfIgnoreCase, rfReplaceAll]);
    end;
  end;

end;

{-----------------------------------------------------------------------------}

Function TQPEXE.DecodeParameterVariables(ROMObj : TQPRom; Tools : TQPExeList; AltROMPath : TFileName = '') : String;
begin
  Result := Self.DecodeParameterVariables(Self._parameters, ROMobj, Tools, AltROMPath)
end;

{-----------------------------------------------------------------------------}

procedure TQPExe.OpenHomePage();
begin
  // this procedure loads the home page of the emulator

  //if the homepage is not a blank entry load it
  If _HomePage <> '' then
    ShellExecute(Application.Handle, 'open', PChar(_HomePage), '', '', sw_Show);
end;

{-----------------------------------------------------------------------------}

Function TQPExe.PreRunROMConfigure(var ZipList : TStringList; ROMObj : TQPROM; ExtrDir : String) : String;
var
  RPath : String;
begin
  Result := '';
  RPath := RomObj.Path;
  //First check that the emulator and rom arent blank AND they exist
  if (FileExists(RPath) or DirectoryExists(ExtractFilePath(RPath)) )
      and FileExists(_Path) then
  Begin

    //verify the integrity of the compressed archive, if it IS an archive...
    If (_Verify) and  ( uQPCompObj.Compression.SupportsFileName(RomObj.path, cmRead) ) then
      If uQPCompObj.Compression.VerifyFile(RomObj.path) = false then
        raise EJException.Create(COMP_VERIFY_FAILED);

    If RomObj.ZipName = '' then
    begin
      RPath := RomObj.path;
      {$IFDEF DEBUG}
      AddToLog('ROM NOT in Zip - ' + RomObj.path);
      {$ENDIF}
    end
    else
    begin

      //This means the rom is contained inside a zip collection and
      //needs to be extracted before it can be run.
      try
        uQPCompObj.Compression.UnCompressFile(RomObj.Path, ExtrDir, false, false, true, RomObj.ZipName);
      except
        on e: EJCompressException do Raise EJException.Create(E.Message);
      end;

      If FileExists(ExtrDir + ExtractFileName(RomObj.ZipName)) then
        RPath := ExtrDir + ExtractFileName(RomObj.ZipName)
      else
        raise EJException.Create(COMP_ARCHIVE_NOT_EXTRACTED);

      {$IFDEF DEBUG}
      AddToLog('ROM was in Zip File (' + RomObj.Path + ') extracted to ' + RPath);
      {$ENDIF}
    end;

    //if the emulator does not support zips then it needs to be extracted
    if (uQPCompObj.Compression.SupportsFileName(RPath, cmRead)) and
       (not self.SupportsCompressed[ExtractFileExt(RPath)]) then
    begin
      RPath := uQPCompObj.Compression.UnCompressROM(rPath, ExtrDir, zipList);
    end;

    Result := RPath;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TQPExe.AfterRunROMConfigure(var ZipList : TStringList; ROMObj : TQPROM; ExtrDir : String);
var
  i : Integer;
begin
  //increment the roms numplayed
  RomObj.NumPlay := RomObj.NumPlay + 1;

  For i := 0 to ZipList.Count-1 do
    If FileExists(ZipList[i]) and not (Self._UseLaunchApp) then
      SysUtils.DeleteFile(ZipList[i]);

  //if the file was part of a zip collection we need to delete it
  If (RomObj.ZipName <> '') and not (Self._UseLaunchApp) and
        (fileExists(ExtrDir + ExtractFileName(RomObj.ZipName))) then
    SysUtils.deleteFile(ExtrDir + ExtractFileName(RomObj.ZipName));

end;

{-----------------------------------------------------------------------------}

Procedure TQPExe.Run();
begin
  Self.Run(nil, nil, '');
end;

{-----------------------------------------------------------------------------}

procedure TQPExe.Run(Tools : TQPExeList; ExtrDir : String);
begin
  Self.Run(nil, nil, ExtrDir);
end;

{-----------------------------------------------------------------------------}

Procedure TQPExe.Run(ROMObj : TQPROM; Tools : TQPExeList; ExtrDir : String);
var
  RPath, HelpCmd, CmdLine, EmuPath : string;
  ZipList : TStringList;
begin

  {$IFDEF DEBUG}
  AddToLog('Start of EXE Launch Code ----------');
  {$ENDIF}
  if ROMObj = nil then
  begin
    // we dont need to setup the ROM, because there isnt one!  just run the exe with run the Pre and After cmds.
    if (Self._PreLaunchCmd <> '') and (not Self.ParamRequiresROM(Self._PreLaunchCmd)) then
      ujProcesses.RunProcess(Self.DecodeParameterVariables(Self.PreLaunchCmd, nil, Tools), Self.PreLaunchWait);

    ujProcesses.RunProcess(Self._path, Self._WaitForEXEEnd, ExtractFilePath(Self._path));

    if (Self._AfterLaunchCmd <> '') and (not Self.ParamRequiresROM(Self._PreLaunchCmd)) then
      ujProcesses.RunProcess(Self.DecodeParameterVariables(Self._AfterLaunchCmd, nil, Tools), Self.AfterLaunchWait);
  end
  else
  begin
    //configure the ROM for launching.

    // check that the found emulator supports cmd lines, if it doesnt
    // tell the user and exit
    If (not _CmdLine) and (not _ShellEx) then
    begin
      {$IFDEF DEBUG}
      AddToLog('LaunchROM - Emulator doesnt support cmd lines, ' + _Name);
      {$ENDIF}
      raise EJException.Create(QP_EMU_DOESNT_SUPPORT_CMD);
    end;

    //Create the ZipList for holding uncompressed files, even though we might not need it..
    ZipList := TStringList.Create;
    Try

      RPath := Self.PreRunROMConfigure(ZipList, ROMObj, ExtrDir);

      If (RPath = '') or ( (FileExists(RPath) = False) and (DirectoryExists(RPath) = False) ) then
        raise EJException.Create(QP_GET_ROM_PATH_FAILED);

      {$IFDEF DEBUG}
      AddToLog('-------Running Process/ShellEx-ing---------');
      {$ENDIF}

      //run the prelaunch command.
      if Self._PreLaunchCmd <> '' then
        ujProcesses.RunProcess(Self.DecodeParameterVariables(Self.PreLaunchCmd, ROMObj, Tools), Self.PreLaunchWait);

      if (ROMObj.Parameters <> '') and (Self.ClassType <> TQPTool) then
      begin
        Case ROMObj.ParameterMode of
          ParamAfter : CmdLine := Format('%s %s', [Self._parameters, ROMObj.Parameters]);
          ParamOverwrite: CmdLine := ROMObj.Parameters;
          ParamBefore : CmdLine := Format('%s %s', [ROMObj.Parameters, Self._parameters]);
          ParamAfterNoSpace : CmdLine := Format('%s%s', [Self._parameters, ROMObj.Parameters]);
          ParamBeforeNoSpace : CmdLine := Format('%s%s', [ROMObj.Parameters, Self._parameters]);
        end;
        CmdLine := DecodeParameterVariables(CmdLine, ROMObj, Tools, RPath);
      end
      else
        CmdLine := DecodeParameterVariables(Self._parameters, ROMObj, Tools, RPath);

      //launch the emulator and rom
      If _ShellEx then
        ShellExecAndWait(RPath)
      else if Self._UseLaunchApp then
      begin
        //use the launcher help application.
        HelpCmd := 'qplauncher.exe' + ' ' +
                    StringReplace(_path, ' ', '¬', [rfReplaceAll]) + ' ' +
                    StringReplace(CmdLine, ' ', '¬', [rfReplaceAll]);
        RunProcess(HelpCmd);
        raise EJNotice.Create('TERMINATE');
      end
      else
      begin
        //run with the standard RunProcess command.
        if Self._ShortExe then
          EmuPath := ExtractShortPathName(Self._path)
        else
          emuPath := Self._path;
        RunProcess(EmuPath + ' ' + CmdLine, Self._WaitForEXEEnd, ExtractFilePath(Self._path), SW_SHOWNORMAL, _Priority);
      end;

      //run the After launch command.
      if Self._AfterLaunchCmd <> '' then
        ujProcesses.RunProcess(Self.DecodeParameterVariables(Self._AfterLaunchCmd, ROMObj, Tools), Self.AfterLaunchWait);

      Self.AfterRunROMConfigure(ZipList, ROMObj, ExtrDir);

    finally
      FreeAndNil(ZipList);
    end;

  end;

  {$IFDEF DEBUG}
  AddToLog('End of Launch Code ----------');
  {$ENDIF}

end;

{-----------------------------------------------------------------------------}

Function TQPExe.ParamRequiresROM(Cmd : String) : Boolean;
begin
  if (JCLStrings.StrIPos('%ROM%', Cmd) <> 0) or
     (JCLStrings.StrIPos('%ROMMAME%', Cmd) <> 0) or
     (JCLStrings.StrIPos('%ROMFILENAME%', Cmd) <> 0) or
     (JCLStrings.StrIPos('%ROMFILENAMENOEXT%', Cmd) <> 0) or
     (JCLStrings.StrIPos('%ROMDIR%', Cmd) <> 0) or
     (JCLStrings.StrIPos('%SHORTROM%', Cmd) <> 0) or
     (JCLStrings.StrIPos('%SHORTDIR%', Cmd) <> 0) then
    Result := True
  else
    Result := False;
end;

{-----------------------------------------------------------------------------}

end.
