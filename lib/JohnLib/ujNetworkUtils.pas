unit ujNetworkUtils;

interface

uses SysUtils, Classes, Windows, StdCtrls, Contnrs,IdIcmpClient,
     IdBaseComponent, IdComponent, IdRawBase, IdRawClient;

Function ComputerPings(PC : String) : Boolean;
procedure LoggedOnToStrings(var oUsers : TStrings; const ServerName: string; AddKeyNames : Boolean);

implementation

uses JCLStrings, idStack, uJUtilities;

{-----------------------------------------------------------------------------}

Function ComputerPings(PC : String) : Boolean;
var
  ICMP : TidICMPClient;
begin
  ICMP := TidICMPClient.Create;
  Try

    ICMP.ReceiveTimeout := 1500;
    ICMP.Host := PC;

    try
      ICMP.Ping();

      case ICMP.ReplyStatus.ReplyStatusType of

          rsEcho: Result := True;
          rsError : Result := False;
          rsTimeOut : Result := False;
          rsErrorUnreachable : Result := False;
          rsErrorTTLExceeded : Result := False;
          else
            Result := False;

      end; //end of Case statement
    except
      on e: EIdSocketError do
        Result := False;
    end;

  Finally
    FreeAndNil(ICMP);
  end;
end;

{-----------------------------------------------------------------------------}

procedure LoggedOnToStrings(var oUsers : TStrings; const ServerName: string; AddKeyNames : Boolean);
const
  MAX_NAME_STRING = 1024;
var 
  userName, domainName: array[0..MAX_NAME_STRING] of Char;
  subKeyName: array[0..MAX_PATH] of Char;
  subKeyNameSize: DWORD;
  Index: DWORD;
  userNameSize: DWORD;
  domainNameSize: DWORD;
  lastWriteTime: FILETIME;
  usersKey: HKEY;
  sid: PSID;
  sidType: SID_NAME_USE;
  authority: SID_IDENTIFIER_AUTHORITY;
  subAuthorityCount: BYTE;
  authorityVal: DWORD;
  revision: DWORD;
  subAuthorityVal: array[0..7] of DWORD;

  function GetVals(s: string): Integer;
  var 
    i, j, k, l: integer;
    tmp: string;
  begin
    Delete(s, 1, 2);
    j   := Pos('-', s);
    tmp := Copy(s, 1, j - 1);
    val(tmp, revision, k);
    Delete(s, 1, j);
    j := Pos('-', s);
    tmp := Copy(s, 1, j - 1);
    val('$' + tmp, authorityVal, k);
    Delete(s, 1, j);
    i := 2;
    s := s + '-';
    for l := 0 to 7 do 
    begin
      j := Pos('-', s);
      if j > 0 then 
      begin
        tmp := Copy(s, 1, j - 1);
        val(tmp, subAuthorityVal[l], k);
        Delete(s, 1, j);
        Inc(i);
      end 
      else 
        break;
    end;
    Result := i;
  end;

begin
  //initialise variables.
  oUsers.Clear;
  revision := 0;
  authorityVal := 0;
  FillChar(subAuthorityVal, SizeOf(subAuthorityVal), #0);
  FillChar(userName, SizeOf(userName), #0);
  FillChar(domainName, SizeOf(domainName), #0);
  FillChar(subKeyName, SizeOf(subKeyName), #0);

  //check if the this is the local PC or a remote one.
  if ServerName <> '' then 
  begin
    usersKey := 0;
    if (RegConnectRegistry(PChar(ServerName), HKEY_USERS, usersKey) <> 0) then
    begin
      raise Exception.Create('Unable to connect to remote registry');
      Exit;
    end;
  end 
  else 
  begin
    if (RegOpenKey(HKEY_USERS, nil, usersKey) <> ERROR_SUCCESS) then
    begin
      raise Exception.Create('Unable to read HKEY_USERS on local PC');
      Exit;
    end;
  end;
  
  Index := 0;
  subKeyNameSize := SizeOf(subKeyName);
  while (RegEnumKeyEx(usersKey, Index, subKeyName, subKeyNameSize,
    nil, nil, nil, @lastWriteTime) = ERROR_SUCCESS) do 
  begin
    if (lstrcmpi(subKeyName, '.default') <> 0) and (Pos('Classes', string(subKeyName)) = 0) then
    begin
      subAuthorityCount := getvals(subKeyName);
      if (subAuthorityCount >= 3) then 
      begin
        subAuthorityCount := subAuthorityCount - 2;
        if (subAuthorityCount < 2) then subAuthorityCount := 2;
        authority.Value[5] := PByte(@authorityVal)^;
        authority.Value[4] := PByte(DWORD(@authorityVal) + 1)^;
        authority.Value[3] := PByte(DWORD(@authorityVal) + 2)^;
        authority.Value[2] := PByte(DWORD(@authorityVal) + 3)^;
        authority.Value[1] := 0;
        authority.Value[0] := 0;
        sid := nil;
        userNameSize := MAX_NAME_STRING;
        domainNameSize := MAX_NAME_STRING;
        if AllocateAndInitializeSid(authority, subAuthorityCount,
          subAuthorityVal[0], subAuthorityVal[1], subAuthorityVal[2],
          subAuthorityVal[3], subAuthorityVal[4], subAuthorityVal[5],
          subAuthorityVal[6], subAuthorityVal[7], sid) then 
        begin
          if LookupAccountSid(PChar(ServerName), sid, userName, userNameSize,
            domainName, domainNameSize, sidType) then 
          begin
            if AddKeyNames then
              oUsers.Add(string(domainName) + '\' + string(userName) + '=' + subKeyName)
            else
              oUsers.Add(string(domainName) + '\' + string(userName));
          end;
        end;
        if Assigned(sid) then
          FreeSid(sid);
      end;
    end;
    subKeyNameSize := SizeOf(subKeyName);
    Inc(Index);
  end;
  RegCloseKey(usersKey);
end;

{-----------------------------------------------------------------------------}

end.
