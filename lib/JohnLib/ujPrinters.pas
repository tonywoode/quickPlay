{
ujPrinters is a utility unit to handle all sorts of printer related tasks.

}

unit ujPrinters;

interface

uses SysUtils, Classes, IniFiles;

Function AddPrinterPort(onPC : String; PortAddr : String) : String; //returns the name of the new port or the name of an existing one...
procedure GetInfoFromInfFile(var Version, Provider, OS : String; const infFile : String);
procedure GetModelsFromInfFile(var inStrs : TStrings; infFile: String);
function ReadInfVariable(var InfFile: TIniFile; Section,
  Value: String): String;
function ResolveInfVariable(var InfFile: TIniFile; InStr: String): String;

implementation

uses Registry, Windows,
     idStack, JCLStrings,
     ujServices;

{-----------------------------------------------------------------------------}

Function AddPrinterPort(onPC : String; PortAddr : String) : String;
var
  TheStack : TIdStack;
  IsIPPort : Boolean;
  Reg : TRegistry;
  PCNoSlash, NewKey : String;
  RestartService : Boolean;
begin
  Result := '';
  if (onPC = '') or (PortAddr = '') then
    raise Exception.Create('Invalid Parameter');

  PCNoSlash := onPC;
  JCLStrings.StrReplace(PCNoSlash, '\\', '', [rfReplaceAll]);
  RestartService := False;

  TheStack := IdStackFactory();
  try
    IsIPPort := TheStack.IsIP(PortAddr);
  finally
    FreeAndNil(TheStack);
  end;

  Reg := TRegistry.Create;
  try
    Reg.RootKey := HKEY_LOCAL_MACHINE;
    if not Reg.RegistryConnect('\\' + PCNoSlash) then
    begin
      Raise Exception.Create('Unable to connect to remote registry');
    end;

    //configure the port now.
    if IsIPPort then
    begin
      //configure the IP port
      Result := 'IP_' + PortAddr;
      NewKey := '\SYSTEM\CurrentControlSet\Control\Print\Monitors\Standard TCP/IP Port\Ports\IP_' + PortAddr;
      if not Reg.KeyExists(NewKey) then
        if (Reg.OpenKey(NewKey, True)) then
        begin
          RestartService := True;
          Reg.WriteString('HostName', '');
          Reg.WriteString('HWAddress', '');
          Reg.WriteString('IPAddress', PortAddr);
          Reg.WriteInteger('PortNumber', 9100);
          Reg.WriteInteger('Protocol', 1);
          Reg.WriteString('SNMP Community', 'public');
          Reg.WriteInteger('SNMP Enabled', 0);
          Reg.WriteInteger('SNMP Index', 1);
          Reg.WriteInteger('Version', 1);
          Reg.CloseKey;
        end
        else
          raise Exception.Create('Unable to open IP Printer Port Registry Key');

    end
    else
    begin
      //configure the share address local port.
    end;

  finally
    FreeAndNil(Reg);
  end;

  //finally restart the spooler service - if we have added a new port!
  if RestartService then
  begin
    if ujServices.ServiceStop(onPC, 'Spooler') then
      ujServices.ServiceStart(onPC, 'Spooler')
    else
      raise Exception.Create('Unable to restart Spooler service');
  end;
end;

{-----------------------------------------------------------------------------}

procedure GetInfoFromInfFile(var Version, Provider, OS : String; const infFile : String);
var
  inf : TIniFile;
begin
  if infFile <> '' then
  begin
    Inf := TIniFile.Create(InfFile);
    try
      Version := Inf.ReadString('Version', 'DriverVer', '');
      Provider := ReadInfVariable(Inf, 'Version', 'Provider');
      OS := ReadInfVariable(Inf, 'Version', 'Signature');
      if StrCompare(OS, '$Windows NT$') = 0 then
        OS := 'Windows 2000/XP/2003'
      else if StrCompare(OS, '$Windows 95$') =0 then
        OS := 'Windows 9X/ME'
      else if StrCompare(OS, '$Chicago$') = 0 then
        OS := 'All Windows Operating Systems'
      else
        OS := 'Unknown';
    finally
      FreeAndNil(Inf);
    end;
  end;

end;

{-----------------------------------------------------------------------------}

procedure GetModelsFromInfFile(var inStrs : TStrings; infFile: String);
var
  Inf : TIniFile;
  Manus, TmpStrs : TStringList;
  i, e : Integer;
begin

  if infFile <> '' then
  begin
    Inf := TIniFile.Create(InfFile);
    try

      Manus := TStringList.Create;
      try
        TmpStrs := TStringList.Create;
        try

          if Inf.SectionExists('Manufacturer') then
          begin
            Inf.ReadSectionValues('Manufacturer', Manus);
          end;

          for I := 0 to Manus.Count - 1 do
          begin
            if Inf.SectionExists(Manus.ValueFromIndex[i]) then
            begin
              
              Inf.ReadSection(Manus.ValueFromIndex[i], TmpStrs);

              for e := 0 to TmpStrs.Count - 1 do
              begin
                InStrs.Add(ExtractFileName(InfFile) + '=' +ResolveInfVariable(Inf, TmpStrs[e]));
              end;

            end;
          end;
          
        finally
          FreeAndNil(TmpStrs);
        end;

      finally
        FreeandNil(Manus);
      end;

    finally
      FreeandNil(Inf);
    end;
  end;

end;

{-----------------------------------------------------------------------------}

function ReadInfVariable(var InfFile: TIniFile; Section,
  Value: String): String;
begin

  Result := '';
  if InfFile.ValueExists(Section, Value) then
  begin
    Result := ResolveInfVariable(Inffile, InfFile.ReadString(Section, Value, ''));
  end;

end;

{-----------------------------------------------------------------------------}

function ResolveInfVariable(var InfFile: TIniFile; InStr: String): String;
var
  Tmp, Lookup : String;
begin
  Result := '';
  Tmp := inStr;
  //remove any start/end quotes.
  if JCLStrings.StrMatches('"*"', Tmp) then
  begin
    Tmp := Copy(Tmp, 2, Length(Tmp)-2);
  end;

    //resolve variables if required.
  if JCLStrings.StrMatches('%*%', Tmp) then
  begin
    Lookup := Copy(Tmp, 2, Length(Tmp)-2);
    if InfFile.ValueExists('Strings', Lookup) then
      Tmp := InfFile.ReadString('Strings', Lookup, '');
    if JCLStrings.StrMatches('"*"', Tmp) then
      Tmp := Copy(Tmp, 2, Length(Tmp)-2);

    Result := Tmp;
  end
  else
    Result := Tmp;
end;

{-----------------------------------------------------------------------------}

end.
