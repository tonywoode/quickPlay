unit ujProxyUtils;

interface

uses SysUtils;

Procedure EnableProxy(const Server: String);
Procedure DisableProxy;
Function GetProxy() : String;

implementation

uses Registry, WinInet, ujUtilities;

{-----------------------------------------------------------------------------}

Procedure EnableProxy(const Server: String);
var
  Reg : TRegistry;
begin
  Reg := TRegistry.Create;
  try

    if Reg.OpenKey('Software\Microsoft\Windows\CurrentVersion\Internet Settings',False) then
    begin
      Reg.WriteString('ProxyServer',Server);
      Reg.WriteBool('ProxyEnable',True);
      Reg.CloseKey;
      InternetSetOption(nil, INTERNET_OPTION_SETTINGS_CHANGED, nil, 0);
      ujUtilities.DisplayMsg('Proxy Configuration', 'Proxy changed to ' + Server);
    end
    else
      ujUtilities.DisplayMsg('Proxy Configuration', 'Error changing proxy server', 0);
    
  finally
    FreeAndNil(Reg);
  end;
end;

{-----------------------------------------------------------------------------}

Procedure DisableProxy;
var
  Reg : TRegistry;
begin
  Reg := TRegistry.Create;
  try
    if Reg.OpenKey('Software\Microsoft\Windows\CurrentVersion\Internet Settings',False) then
    begin
      Reg.WriteBool('ProxyEnable',False);
      Reg.CloseKey;
      InternetSetOption(nil,INTERNET_OPTION_SETTINGS_CHANGED, nil, 0);
      ujUtilities.DisplayMsg('Proxy Configuration', 'Proxy Disabled');
    end
    else
      ujUtilities.DisplayMsg('Proxy Configuration', 'Unable to Disable Proxy server', 0);
  finally
    FreeAndNil(Reg);
  end;
end;

{-----------------------------------------------------------------------------}

Function GetProxy() : String;
var
  Reg : TRegistry;
begin
  Result := '';
  Reg := TRegistry.Create;
  try
    if Reg.OpenKey('Software\Microsoft\Windows\CurrentVersion\Internet Settings',False) then
    begin

      try
        if Reg.ReadBool('ProxyEnable') then
          Result := Reg.ReadString('ProxyServer');
      except
        Result := '';
      end;
      
    end;
  finally
    FreeAndNil(Reg);
  end;
end;

{-----------------------------------------------------------------------------}

end.
