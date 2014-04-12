unit uEmuFindObj;

interface

uses SysUtils, Classes, IniFiles;

type
  //record for the structure of an Efind INI record.
  TQPEmuFindObj = class(TObject)
  public
    name,
    exe,
    cfg,
    system,
    HomePage : String;
    isWin32,
    CmdLine,
    ShellEx,
    ShortExe,
    Verify,
    DisableScreenSaver,
    DisableWinKey : Boolean;
    Param : String;
    Compress : TStringList;
    Constructor Create();
    Destructor Destroy();override;
    function IsMatch(FileName : TFileName):Boolean;
    procedure LoadFromIni(Name : String; var Ini : TMemIniFile);
  end;

implementation

uses JCLStrings, ujFile, ujMiscResourceStrs;

{-----------------------------------------------------------------------------}
{TQPEmuFindObj}
{-----------------------------------------------------------------------------}

Constructor TQPEmuFindObj.Create();
begin
  inherited;
  Compress := TStringList.Create;
end;

Destructor TQPEmuFindObj.Destroy();
begin
  FreeAndnil(Compress);
  inherited;
end;

function TQPEmuFindObj.IsMatch(FileName : TFileName):Boolean;
begin
//testing code
//  FileName  := StringReplace(FileName, 'exe', '',[rfReplaceAll, rfIgnoreCase]);   //temp remove exe
//    self.exe  := StringReplace(self.exe, 'exe', '',[rfReplaceAll, rfIgnoreCase]);

  if ( StrCompare(extractfilename(FileName), self.exe )=0 ) then   //search with exe
  begin
    if (StrCompare(ExeTypeToString(FileName), J_EXE_WIN32)=0) and (Self.isWin32) then
      Result := True
    else if (StrCompare(ExeTypeToString(FileName), J_EXE_DOS)=0) and (not Self.isWin32) then
      Result := True
    else
      Result := False;
  end
  else  Result := False;

end;

procedure TQPEmuFindObj.LoadFromIni(Name : String; var Ini : TMemIniFile);
var
  CompStream : TMemoryStream;
begin
  Self.name := Name;
  exe := Ini.ReadString(Name, 'EXE Name', '');
  cfg := Ini.ReadString(Name, 'Config Name', '');
  system := Ini.ReadString(Name, 'System', '');
  HomePage := Ini.ReadString(Name, 'HomePage', '');
  isWin32 := Ini.ReadBool(Name, 'isWin32', true);
  CmdLine := Ini.ReadBool(Name, 'CmdLine', true);
  ShellEx := Ini.ReadBool(Name, 'ShellEx', false);
  ShortExe := Ini.ReadBool(Name, 'ShortExe', False);
  DisableScreenSaver := Ini.ReadBool(Name, 'DisScrSvr', False);
  DisableWinKey := Ini.ReadBool(Name, 'DisWinKey', False);
  Verify := Ini.ReadBool(Name, 'Verify', False);
  Param := Ini.ReadString(Name, 'Param', '');

  CompStream := TMemoryStream.Create;
  try
    Ini.ReadBinaryStream(Name, 'Compression', CompStream);
    Self.Compress.LoadFromStream(CompStream);
  finally
    FreeAndnil(CompStream);
  end;

end;

end.
 