unit ujWindowsMisc;

interface

uses SysUtils, Windows, Classes, Graphics;

Type
  PJInstalledApp = ^TJInstalledApp;
  TJInstalledApp = record
    Name : String;     //maps to displayname
    KeyName : String;
    InstallLocation : String; //maps to InstallLocation OR "Inno Setup: App Path"
    Publisher : String; //maps to publisher
    HomePage : String;  //Maps to URLInfoAbout
    UninstallString : String;  //maps to uninstallstring
    QuietUninstallString : String; //maps to quietuninstallstring (seems to be inno setup specific)
  end;
  TDynamicInstalledAppArray = Array of TJInstalledApp;

  TJWindowsFont = (jwfCaption, jwfSmCaption, jwfMenu, jwfStatus, jwfMessage);

Const
  OFF_2k = '9.0.0.2717';
  OFF_2K_SP1 = '9.0.0.3822';
  OFF_2K_SP2 = '9.0.0.4402';
  OFF_2K_SP3 = '9.0.0.6926';
  OFF_XP = '10.0.2627.0';
  OFF_XP_SP1 = '10.0.3416.0';
  OFF_XP_SP2 = '10.0.4219.0';
  OFF_2003 = '11.0.5604.0';
  OFF_2003_SP1 = '11.0.6359.0';
  OFF_2003_SP2 = '11.0.6568.0';

function DecodeProductKey(const HexSrc: array of Byte): string;
function GetMappedDrives(slist : TStrings ) : integer;
Function GetWindowsInstallDate(PC : String) : String;
Function GetWindowsInstallKey(PC : String) : String;
procedure GetWindowsFont( var inFont : TFont; const FontType : TJWindowsFont);
procedure GetOfficeInstallLocations(var OffStrs : TStrings; const PC : String);
Function OfficeVersionToString(ver : String) : String;
procedure GetInstalledPrograms(var inArr : TDynamicInstalledAppArray; const ForPC : String; ShowUpdates : Boolean);
Function GetWindowsProductName(PC : String) : String;
Function GetWindowsVersionNumber(PC : String) : Extended;

Function GetCurrentUserSidAsString() : String;

Function ScreensaverOnOff(Value : Boolean) : Boolean;
Procedure WinKeyOnOff(Value : Boolean);

implementation

uses Registry, DateUtils,
     jwaSDDL, JCLStrings;

type
  TTokenUser = record
    User: TSIDAndAttributes;
  end;
  PTokenUser = ^TTokenUser; 

{-----------------------------------------------------------------------}

function DecodeProductKey(const HexSrc: array of Byte): string;
const
  StartOffset: Integer = $34; { //Offset 34 = Array[52] }
  EndOffset: Integer   = $34 + 15; { //Offset 34 + 15(Bytes) = Array[64] }
  Digits: array[0..23] of CHAR = ('B', 'C', 'D', 'F', 'G', 'H', 'J',
    'K', 'M', 'P', 'Q', 'R', 'T', 'V', 'W', 'X', 'Y', '2', '3', '4', '6', '7', '8', '9');
  dLen: Integer = 29; { //Length of Decoded Product Key }
  sLen: Integer = 15;
  { //Length of Encoded Product Key in Bytes (An total of 30 in chars) }
var
  HexDigitalPID: array of CARDINAL;
  Des: array of CHAR;
  I, N: INTEGER;
  HN, Value: CARDINAL;
begin
  SetLength(HexDigitalPID, dLen);
  for I := StartOffset to EndOffset do
  begin
    HexDigitalPID[I - StartOffSet] := HexSrc[I];
  end;

  SetLength(Des, dLen + 1);

  for I := dLen - 1 downto 0 do
  begin
    if (((I + 1) mod 6) = 0) then
    begin
      Des[I] := '-';
    end
    else
    begin
      HN := 0;
      for N := sLen - 1 downto 0 do
      begin
        Value := (HN shl 8) or HexDigitalPID[N];
        HexDigitalPID[N] := Value div 24;
        HN    := Value mod 24;
      end;
      Des[I] := Digits[HN];
    end;
  end;
  Des[dLen] := Chr(0);

  for I := 0 to Length(Des)-1 do
  begin
    Result := Result + Des[I];
  end;
end;

{-----------------------------------------------------------------------}

function GetMappedDrives(slist : TStrings ) : integer;
var
  i: Char;
  ThePath: string;
  MaxNetPathLen: DWord;
begin
  SList.Clear;
  MaxNetPathLen := MAX_PATH;
  SetLength(ThePath, MAX_PATH) ;
  for i := 'A' to 'Z' do
    if WNetGetConnection(PChar('' + i + ':'),
       PChar(ThePath), MaxNetPathLen) = NO_ERROR then
       SList.Add(i + ': ' + Trim(ThePath)) ;
  Result := SList.Count;
end;

{-----------------------------------------------------------------------}

Function GetWindowsInstallDate(PC : String) : String;
var
  Reg : TRegistry;
  StartDate : TDateTime;
  ThePC : String;
begin
  Reg := TRegistry.Create();
  try

    ThePC := PC;
    if ThePC <> '' then
    begin
      JCLStrings.StrReplace(ThePC, '\\', '', [rfReplaceAll]);
      ThePC := '\\' + ThePC;
    end;

    Reg.RootKey := HKEY_LOCAL_MACHINE;
    if Reg.RegistryConnect(ThePC) then
    begin
      REG.OpenKey('SOFTWARE\Microsoft\Windows NT\CurrentVersion', False);
      StartDate := EncodeDateTime(1970,1,1,0,0,0,0);
      Result := DateToStr(IncSecond(StartDate,Reg.ReadInteger('InstallDate')));
      Reg.CloseKey;
    end;
  finally
    FreeAndNil(Reg);
  end;
end;

{-----------------------------------------------------------------------}

Function GetWindowsInstallKey(PC : String) : String;
var
  Reg : TRegistry;
  binarySize: INTEGER;
  CDkeyBuf: array of BYTE;
  ThePC : String;
begin
  Reg := TRegistry.Create();
  try

    ThePC := PC;
    if ThePC <> '' then
    begin
      JCLStrings.StrReplace(ThePC, '\\', '', [rfReplaceAll]);
      ThePC := '\\' + ThePC;
    end;

    Reg.RootKey := HKEY_LOCAL_MACHINE;
    if Reg.RegistryConnect(ThePC) then
    begin
      REG.OpenKey('SOFTWARE\Microsoft\Windows NT\CurrentVersion', False);
      binarySize := Reg.GetDataSize('DigitalProductId');
      SetLength(CDkeyBuf, binarySize);
      if binarySize > 0 then
      begin
        Reg.ReadBinaryData('DigitalProductId', CDkeyBuf[0], binarySize);
      end;
      Reg.CloseKey;
      Result := ujWindowsMisc.DecodeProductKey(CDKeyBuf);
    end;
  finally
    FreeAndNil(Reg);
  end;
end;

{-----------------------------------------------------------------------}

procedure GetWindowsFont( var inFont : TFont; const FontType : TJWindowsFont);
var
  ncMetrics: TNonClientMetrics;
begin
{
  lfCaptionFont - regular captions
  lfSmCaptionFont - small captions
  lfMenuFont - menus
  lfStatusFont - status bars
  lfMessageFont - message boxes
}

  if inFont = nil then
    raise Exception.Create('Uninitialised font passed to function');
    
  ncMetrics.cbSize := sizeof(TNonClientMetrics);
  SystemParametersInfo(SPI_GETNONCLIENTMETRICS, sizeof(TNonClientMetrics),
                       @ncMetrics, 0);

  case FontType of
    jwfCaption: inFont.Handle := CreateFontIndirect(ncMetrics.lfCaptionFont);
    jwfSmCaption: inFont.Handle := CreateFontIndirect(ncMetrics.lfSmCaptionFont);
    jwfMenu: inFont.Handle := CreateFontIndirect(ncMetrics.lfMenuFont);
    jwfStatus: inFont.Handle := CreateFontIndirect(ncMetrics.lfStatusFont);
    jwfMessage: inFont.Handle := CreateFontIndirect(ncMetrics.lfMessageFont);
  end;

end;

{-----------------------------------------------------------------------}

procedure GetOfficeInstallLocations(var OffStrs : TStrings; const PC : String);
var
  Reg : TRegistry;
  thePC : String;
begin
  Reg := TRegistry.Create();
  try

    OffStrs.Clear;
    ThePC := PC;
    if ThePC <> '' then
    begin
      JCLStrings.StrReplace(ThePC, '\\', '', [rfReplaceAll]);
      ThePC := '\\' + ThePC;
    end;

    Reg.RootKey := HKEY_LOCAL_MACHINE;
    if Reg.RegistryConnect(ThePC) then
    begin

      if Reg.KeyExists('SOFTWARE\Microsoft\Office\8.0\Common\InstallRoot') and
        REG.OpenKeyReadOnly('SOFTWARE\Microsoft\Office\8.0\Common\InstallRoot') then
      begin
        OffStrs.Add('Office97=' + Reg.ReadString('OfficeBin'));
        Reg.CloseKey;
      end;

      if Reg.KeyExists('SOFTWARE\Microsoft\Office\9.0\Common\InstallRoot') and
        REG.OpenKeyReadOnly('SOFTWARE\Microsoft\Office\9.0\Common\InstallRoot') then
      begin
        OffStrs.Add('Office2000=' + Reg.ReadString('Path'));
        Reg.CloseKey;
      end;

      if Reg.KeyExists('SOFTWARE\Microsoft\Office\10.0\Common\InstallRoot') and
        REG.OpenKeyReadOnly('SOFTWARE\Microsoft\Office\10.0\Common\InstallRoot') then
      begin
        OffStrs.Add('OfficeXP=' + Reg.ReadString('Path'));
        Reg.CloseKey;
      end;

      if Reg.KeyExists('SOFTWARE\Microsoft\Office\11.0\Common\InstallRoot') and
        REG.OpenKeyReadOnly('SOFTWARE\Microsoft\Office\11.0\Common\InstallRoot') then
      begin
        OffStrs.Add('Office2003=' + Reg.ReadString('Path'));
        Reg.CloseKey;
      end;
      
    end;
  finally
    FreeAndNil(Reg);
  end;
end;

{-----------------------------------------------------------------------}

Function OfficeVersionToString(ver : String) : String;
var
  strVers : TStringList;
begin
  //instead of loads of IF statements, load all the versions into a stringlist
  //and then use the NAMES-VALUES syntax to get our version number.

  strVers := TStringList.Create;
  try
    strVers.Add(OFF_2k + '=Microsoft Office 2000 Gold Release');
    strVers.Add(OFF_2K_SP1 + '=Microsoft Office 2000 SR1');
    strVers.Add(OFF_2K_SP2 + '=Microsoft Office 2000 SP2');
    strVers.Add(OFF_2K_SP3 + '=Microsoft Office 2000 SP3');
    strVers.Add(OFF_XP + '=Microsoft Office XP Gold Release');
    strVers.Add(OFF_XP_SP1 + '=Microsoft Office XP SP1');
    strVers.Add(OFF_XP_SP2 + '=Microsoft Office 2000 SP2');
    strVers.Add(OFF_2003 + '=Microsoft Office 2003 Gold Release');
    strVers.Add(OFF_2003_SP1 + '=Microsoft Office 2003 SP1');
    strVers.Add(OFF_2003_SP2 + '=Microsoft Office 2003 SP2');
    Try
      Result := strVers.Values[Ver];
    except
      Result := '';
    end;
    
  finally
    FreeAndNil(strVers);
  end;
end;

{-----------------------------------------------------------------------}

procedure GetInstalledPrograms(var inArr : TDynamicInstalledAppArray; const ForPC : String; ShowUpdates : Boolean);
var
  Reg : TRegistry;
  KeyNames : TStringList;
  i : Integer;
  size : Integer;
  ThePC : String;
begin

  SetLength(inArr, 0);
  Size := 0;
  Reg := TRegistry.Create;
  try
    Reg.RootKey := HKEY_LOCAL_MACHINE;
    
    ThePC := ForPC;
    if ThePC <> '' then
    begin
      JCLStrings.StrReplace(ThePC, '\\', '', [rfReplaceAll]);
      ThePC := '\\' + ThePC;
    end;

    if Reg.RegistryConnect(ThePC) and
       REG.OpenKeyReadOnly('SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall') then
    begin
      KeyNames := TStringList.Create;
      try

        Reg.GetKeyNames(KeyNames);
        Reg.CloseKey;

        KeyNames.Sort;

        for i := 0 to KeyNames.Count-1 do
        begin
          if ( REG.OpenKeyReadOnly('SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\'+KeyNames[i]) ) then
          begin
            if ( Reg.ValueExists('DisplayName') ) and
               ( Reg.ReadString('UninstallString') <> '' ) then
            begin

              if (not ShowUpdates) and (Reg.ReadString('ParentKeyName') <> '') then
              begin
                Reg.CloseKey;
                Continue;
              end;

              inc(Size);
              SetLength(inArr, Size);
              inArr[Size-1].Name := Reg.ReadString('DisplayName');
              inArr[Size-1].KeyName := KeyNames[i];
              inArr[Size-1].Publisher := Reg.ReadString('Publisher');
              inArr[Size-1].HomePage := Reg.ReadString('URLInfoAbout');
              inArr[Size-1].UninstallString := Reg.ReadString('UninstallString');
              inArr[Size-1].QuietUninstallString := Reg.ReadString('QuietUninstallString');

              if Reg.ValueExists('InstallLocation') then
                inArr[Size-1].InstallLocation := Reg.ReadString('InstallLocation')
              else if Reg.ValueExists('Inno Setup: App Path') then
                inArr[Size-1].InstallLocation := Reg.ReadString('Inno Setup: App Path');
            end;
            
            Reg.CloseKey;
          end;
        end;

      finally
        FreeAndNil(KeyNames);
      end;
    end
    else
      raise Exception.Create('Unable to read programs list from remote PC');
  finally
    FreeAndNil(Reg);
  end;
end;

{-----------------------------------------------------------------------}

Function GetWindowsProductName(PC : String) : String;
var
  Reg : TRegistry;
  ThePC : String;
begin
  Result := '';
  Reg := TRegistry.Create();
  try

    ThePC := PC;
    if ThePC <> '' then
    begin
      JCLStrings.StrReplace(ThePC, '\\', '', [rfReplaceAll]);
      ThePC := '\\' + ThePC;
    end;

    Reg.RootKey := HKEY_LOCAL_MACHINE;
    if Reg.RegistryConnect(ThePC) then
    begin
      if REG.OpenKeyReadOnly('SOFTWARE\Microsoft\Windows NT\CurrentVersion') then
      begin
        Result := Reg.ReadString('ProductName');;
        Reg.CloseKey;
      end;
    end;
  finally
    FreeAndNil(Reg);
  end;
end;

{-----------------------------------------------------------------------}

Function GetWindowsVersionNumber(PC : String) : Extended;
var
  Reg : TRegistry;
  ThePC : String;
begin
  Result := -1;
  Reg := TRegistry.Create();
  try

    Reg.RootKey := HKEY_LOCAL_MACHINE;
    ThePC := PC;
    if ThePC <> '' then
    begin
      JCLStrings.StrReplace(ThePC, '\\', '', [rfReplaceAll]);
      ThePC := '\\' + ThePC;
    end;
      
    if Reg.RegistryConnect(ThePC) then
    begin
      if REG.OpenKeyReadOnly('SOFTWARE\Microsoft\Windows NT\CurrentVersion') then
      begin
        Try
          Result := StrToFloat( Reg.ReadString('CurrentVersion') );
        except
          Result := -1;
        end;
        Reg.CloseKey;
      end;
    end;
  finally
    FreeAndNil(Reg);
  end;
end;

{-----------------------------------------------------------------------}

Function GetCurrentUserSidAsString() : String;
const
  BUFFER_SIZE = 1000;
var
  mySID : Array[0..MAX_PATH-1] of Char;
  pMySid : PAnsiChar;

  hProcessToken: THandle;
  hAccessToken: THandle;
  szBuffer: PChar;
  dwBufferSize: DWORD;
begin
  PmySid := MySid;
  Result := '';
  //Work out what the current users HKEY_User key is
  szBuffer := StrAlloc (BUFFER_SIZE);

  hProcessToken := GetCurrentProcess;
  try
    if OpenProcessToken (hProcessToken, TOKEN_READ, hAccessToken) then
      if Windows.GetTokenInformation (hAccessToken, TokenUser, szBuffer,
           BUFFER_SIZE, dwBufferSize) then
        if not ConvertSidToStringSid(PTokenUser(szBuffer)^.User.Sid, pmySID) then
          raise Exception.Create('Unable to find user SID for registry profile')
        else
          Result := pMySID;

  finally
    StrDispose (szBuffer);
  end;

end;

{-----------------------------------------------------------------------------}

Function ScreensaverOnOff(Value : Boolean) : Boolean;
Begin
  If Value then
    Result := SystemParametersInfo(SPI_SETSCREENSAVEACTIVE, 1, nil, 0)
  else
    Result := SystemParametersInfo(SPI_SETSCREENSAVEACTIVE, 0, nil, 0);
End;

{-----------------------------------------------------------------------------}

Procedure WinKeyOnOff(Value : Boolean);
Var
  Dummy : Integer;
Begin
  If Value then
  //enable the win keys
  Begin
    SystemParametersInfo( SPI_SETFASTTASKSWITCH, 0, @Dummy, 0);
    SystemParametersInfo( SPI_SCREENSAVERRUNNING, 0, @Dummy, 0);
  End

  Else
  //disable the win keys
  Begin
    SystemParametersInfo( SPI_SETFASTTASKSWITCH, 1, @Dummy, 0);
    SystemParametersInfo( SPI_SCREENSAVERRUNNING, 1, @Dummy, 0);
  End;
End;

{-----------------------------------------------------------------------------}

end.
