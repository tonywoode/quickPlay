unit uTools;

interface

uses SysUtils, Classes, Contnrs, IniFiles, uExe;

type

  TQPTool = Class(TQPExe)
  private
    _VarName : String;
    _ToolRelativePath : String;
    _ToolStatedPath : String;
    _QPFolder : String;
    _ToolPathIsRelative : Boolean;

  public
    constructor Create;
    procedure Assign(InTool : TQPTool);
    procedure LoadFromIni(SectionName : String; var Ini : TMemIniFile);
    procedure SaveIntoIni(var Ini : TMemIniFile);

    Property VarName : String read _VarName write _VarName;
  end;

  PQPTool = ^TQPTool;

implementation

{------------------------------------------------------------------------------}
{ TQPTool }
{------------------------------------------------------------------------------}

constructor TQPTool.Create;
begin
  inherited Create();
  _WaitForEXEEnd := False;
  _ShellEx := False;
end;

{------------------------------------------------------------------------------}

procedure TQPTool.Assign(InTool : TQPTool);
begin
  inherited Assign(TQPExe(InTool));
  _VarName := InTool.VarName;
end;

{------------------------------------------------------------------------------}

procedure TQPTool.LoadFromIni(SectionName : String; var Ini : TMemIniFile);
var
  CompStream : TMemoryStream;
begin
  //bugfix #38 - You can't have a batch file tool with a relative path in tools.ini as
  //  omitting fullpath confuses current dir for bats vis a vis CreateProcess in Delphi's sysUtils
  _QPFolder := getCurrentDir();
  _ToolStatedPath := Ini.ReadString(SectionName, 'Path','');
  _ToolRelativePath := ExtractRelativePath(_QPFolder, _ToolStatedPath);
  _ToolPathIsRelative := _ToolRelativePath = _ToolStatedPath;
  _path := _ToolStatedPath;
  if _ToolPathIsRelative then
    _path := _QPFolder + '\' + _ToolStatedPath;

  _name := SectionName;

  //getCurrentDir() + '\' + Ini.ReadString(SectionName, 'Path','');
  _HomePage := Ini.ReadString(SectionName, 'HomePage','');
  _parameters := Ini.ReadString(SectionName, 'parameters', '');
  _CmdLine := Ini.ReadBool(SectionName, 'CmdLine', true);
  _VarName := Ini.ReadString(SectionName, 'VarName', '');
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

{------------------------------------------------------------------------------}

procedure TQPTool.SaveIntoIni(var Ini : TMemIniFile);
var
  CompStream : TMemoryStream;
begin
  //check that the emulator has a valid name AND a valid Path
  if (_Name = '') or (_Path = '') then
    exit;
  Ini.EraseSection(_Name);
  Ini.WriteString(_Name, 'Version', _Version);

  //if the toolpath was relative to QP's dir,
  //and if you haven't changed it in this session
  //write the original relative path back to disk
  if ( _ToolPathIsRelative ) and (_path = _QPFolder + '\' + _ToolStatedPath )
  then
    Ini.WriteString(_Name, 'path', _ToolStatedPath)
  else
    Ini.WriteString(_Name, 'path', _path);

  Ini.WriteString(_Name, 'HomePage', _HomePage);
  Ini.WriteString(_Name, 'parameters', _parameters);
  Ini.WriteBool(_Name, 'CmdLine', _CmdLine);
  Ini.WriteString(_Name, 'VarName', _VarName);

  //Media Settings
  Ini.WriteBool(_Name, 'ShowExeTab', _ShowExeTab);
  Ini.WriteString(_Name, 'ExeImage', _ExeImage);
  Ini.WriteBool(_Name, 'ShowAddInfo', _ShowAddInfo);

  CompStream := TMemoryStream.Create;
  try
    Self._CompressSupport.SaveToStream(CompStream);
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

end.
