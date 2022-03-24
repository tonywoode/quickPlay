unit ujDomainUtils;

interface

uses SysUtils, Forms, Classes, Windows, ComCtrls;

type
  NET_API_STATUS = Integer;
  EAccessDenied = Exception;
  EInvalidOwner = Exception;
  EInsufficientBuffer = Exception;
  ELibraryNotFound = Exception;
  TJDomainType = (jdtInvalid=-1, jdtLocal=0, jdtNT=1, jdtAD=2, jdtRemote=3);

  TComputerEnumThread = class(TThread)
    List : TListView;
    CurrentPC : String;
    newItem : TListItem;
    Domain : String;
    constructor create(List : TListView;  DomainStr : String);overload;
    procedure AddNetItem;
    procedure Execute; override;
  end;

  TDomainEnumThread = class(TThread)
    List : TStrings;
    DomainName : String;
    constructor create(List : TStrings);overload;
    procedure AddDomain;
    procedure Execute; override;
    procedure GetDomains(Res: PNetResourceA);
  end;

  function AgeToString(Duration : dword):string;
  Function GetDomainType(DomainName : String) : TJDomainType;
  function GetPDC(forDomain: string): string;


implementation

uses JCLStrings, JwaLmApiBuf, jwaLMAccess, jwaLMErr;

const
  MaxEntries = 15000;
  InitialSize = $1;  // Any positive value is acceptable.
  
var
  NTNetGetDCName: function (Server, Domain: pWideChar; var DC: pWideChar): NET_API_STATUS; stdcall;
  NTNetGetDCNameA: function (Server, Domain: PChar; var DC: PChar): NET_API_STATUS; stdcall;

{-----------------------------------------------------------------------------}

procedure NetCheck(ErrCode: NET_API_STATUS);
begin
  if ErrCode <> NERR_Success then
  begin
    case ErrCode of
      ERROR_ACCESS_DENIED:
        raise EAccessDenied.Create('Access is Denied');
      ERROR_INVALID_OWNER:
        raise EInvalidOwner.Create('Cannot assign the owner of this object.');
      ERROR_INSUFFICIENT_BUFFER:
        raise EInsufficientBuffer.Create('Buffer passed was too small');
      else
        raise Exception.Create('Error Code: ' + IntToStr(ErrCode) + #13 +
          SysErrorMessage(ErrCode));
    end;
  end;
end;

{-----------------------------------------------------------------------------}

// basically looks for the domain in the domain config file and gets it type from there.
Function GetDomainType(DomainName : String) : TJDomainType;
var
  inFile : TStringList;
  i : Integer;
  Found : boolean;
begin

  Result := jdtInvalid;

  if DomainName = '' then
    exit;

  inFile := TStringList.Create;
  try

    inFile.LoadFromFile(ExtractFilePath(Application.ExeName) + 'config\UserDomains.txt');
    Found := False;

    for i := 0 to inFile.Count-1 do
    begin
      if JCLStrings.StrCompare(DomainName, inFile.Names[i]) = 0 then
      begin
        Result := TJDomainType(StrToInt(inFile.ValueFromIndex[i]));
        Found := True;
        Break;
      end;
    end;

    if not Found then
    begin
      //it hasnt been found so far.. which means its some random remote pc.
      Result := jdtRemote;
    end;

  finally
    FreeAndNil(inFile);
  end;
end;

{-----------------------------------------------------------------------------}

function GetPDC(forDomain: string): string;
  { if szSystem = '' return the PDC else return DC for that domain }
const
  NTlib = 'NETAPI32.DLL';
  Win95lib = 'RADMIN32.DLL';
var
  pAnsiDomain: PChar;
  pDomain: PWideChar;
  System: array[1..80] of WideChar;
  ErrMode: Word;
  LibHandle: THandle;
begin
  Result := '';
  LibHandle := 0;
  try
    if Win32Platform = VER_PLATFORM_WIN32_NT then
    begin
      ErrMode := SetErrorMode(SEM_NOOPENFILEERRORBOX);
      LibHandle := LoadLibrary(NTlib);
      SetErrorMode(ErrMode);
      if LibHandle = 0 then
        raise ELibraryNotFound.Create('Unable to map library: ' +
          NTlib); @NTNetGetDCName := GetProcAddress(Libhandle, 'NetGetDCName');
      try
        if forDomain <> '' then
          NetCheck(NTNetGetDCName(nil, StringToWideChar(forDomain, @System, 80), pDomain))
        else
          NetCheck(NTNetGetDCName(nil, nil, pDomain));
        Result := WideCharToString(pDomain);
      finally
        NetCheck(NetApiBufferFree(pDomain));
      end;
    end
    else
    begin
      ErrMode := SetErrorMode(SEM_NOOPENFILEERRORBOX);
      LibHandle := LoadLibrary(Win95lib);
      SetErrorMode(ErrMode);
      if LibHandle = 0 then
        raise ELibraryNotFound.Create('Unable to map library: ' +
          Win95lib); @NTNetGetDCNameA := GetProcAddress(Libhandle, 'NetGetDCNameA');
      try
        if forDomain <> '' then
          NetCheck(NTNetGetDCNameA(nil, PChar(forDomain), pAnsiDomain))
        else
          NetCheck(NTNetGetDCNameA(nil, nil, pAnsiDomain));
        Result := StrPas(pAnsiDomain);
      finally
        NetCheck(NetApiBufferFree(pAnsiDomain));
      end;
    end;
  finally
    if LibHandle <> 0 then
    begin
      FreeLibrary(Libhandle); // free handle if it has been allocated
    end;
  end;
end;

{-----------------------------------------------------------------------------}

constructor TDomainEnumThread.create(List : TStrings);
begin
  Self.List := List;
  inherited Create(false);
end;

{-----------------------------------------------------------------------------}

procedure TDomainEnumThread.AddDomain;
begin
  List.Add(DomainName);
end;

{-----------------------------------------------------------------------------}

procedure TDomainEnumThread.Execute;
begin
  GetDomains(nil);
end;

{-----------------------------------------------------------------------------}

procedure TDomainEnumThread.GetDomains(Res: PNetResourceA);
var
  hEnum : THandle;
  Count,BufSize: DWORD;
  NR,Buf : PNetResourceA;
  R: Integer;
begin
  R:=WNetOpenEnum(RESOURCE_GLOBALNET,RESOURCETYPE_DISK,RESOURCEUSAGE_CONTAINER,Res,hEnum);
    if R <> NO_ERROR then exit;

    BufSize:=InitialSize; GetMem(Buf,BufSize);
    try
        while True do
        begin
            Count:=$FFFFFFFF; // I wish to read ALL items
            R:=WNetEnumResource(hEnum,Count, Buf, BufSize);

            if R = ERROR_MORE_DATA then // Oops ! The InitialSize is too small !
            begin
                Count:=$FFFFFFFF; // I wish to read ALL items
                FreeMem(Buf); GetMem(Buf,BufSize);
                R:=WNetEnumResource(hEnum,Count, Buf, BufSize);
            end;

            if R = ERROR_NO_MORE_ITEMS then
              Break; // All items are processed
            if R <> NO_ERROR then
              Abort; // R is the error code. Process it!

            NR:=Buf;
            while Count > 0 do
            begin

              if NR.dwDisplayType = RESOURCEDISPLAYTYPE_DOMAIN then
              begin
                if NR.lpRemoteName <> nil then
                begin
                  DomainName := StrPas(NR.lpRemoteName);
                  Synchronize(AddDomain);
                end;
              end
              else
              if ( (NR.dwUsage and RESOURCEUSAGE_CONTAINER) = RESOURCEUSAGE_CONTAINER ) then
              begin
                GetDomains( NR );
              end;

              // Go to the next record
              INC(NR);
              DEC(Count);
            end;
        end;
    finally
        WNetCloseEnum(hEnum); // Close handle
        FreeMem(Buf); // Free memory1
    end;

end;

{-----------------------------------------------------------------------------}

constructor TComputerEnumThread.create(List : TListView; DomainStr : String);
begin
  Self.List := List;
  self.Domain := DomainStr;
  inherited Create(false);
end;

{-----------------------------------------------------------------------------}

procedure TComputerEnumThread.Execute;
var
  hEnum : THandle;
  Count,BufSize: DWORD;
  NR,Buf : PNetResourceA;
  R: Integer;
  ForPC: PNetResourceA;
begin

  GetMem(forPC, sizeof(_NETRESOURCEA));
  FillChar( forPC^, sizeof(_NETRESOURCEA), 0 );
  forPC^.dwScope := RESOURCE_GLOBALNET;
  forPC^.dwType := RESOURCETYPE_ANY;
  forPC^.dwDisplayType := RESOURCEDISPLAYTYPE_DOMAIN;
  forPC^.dwUsage := RESOURCEUSAGE_CONTAINER;
  forPC^.lpLocalName := nil;
  forPC^.lpRemoteName := PChar(self.Domain);

  R:=WNetOpenEnum(RESOURCE_GLOBALNET,RESOURCETYPE_ANY,0, forPC,hEnum);
    if R <> NO_ERROR then
    begin
      CurrentPC := IntToStr(GetLastERror());
      Synchronize(AddNetItem);
      exit;
    end;

    BufSize:=InitialSize; GetMem(Buf,BufSize);
    try
        while True do
        begin
            Count:=$FFFFFFFF; // I wish to read ALL items
            R:=WNetEnumResource(hEnum,Count, Buf, BufSize);

            if R = ERROR_MORE_DATA then // Oops ! The InitialSize is too small !
            begin
                Count:=$FFFFFFFF; // I wish to read ALL items
                FreeMem(Buf); GetMem(Buf,BufSize);
                R:=WNetEnumResource(hEnum,Count, Buf, BufSize);
            end;

            if R = ERROR_NO_MORE_ITEMS then Break; // All items are processed
            if R <> NO_ERROR then Abort; // R is the error code. Process it!

            NR:=Buf;
            while Count > 0 do
            begin
                if NR.lpRemoteName <> nil then
                    CurrentPC:=StrPas(NR^.lpRemoteName)
                else
                    CurrentPC:='';

                // Add new node to the tree view - and do it in the main thread
                if CurrentPC <> '' then
                begin
                  CurrentPC := Copy(CurrentPC, 3, Length(CurrentPC)-1);
                  Synchronize(AddNetItem);
                end;

                // Go to the next record
                INC(NR);
                DEC(Count);
            end;
        end;
    finally
        WNetCloseEnum(hEnum); // Close handle
        FreeMem(Buf); // Free memory1
        Self.Terminate;
    end;
end;

{-----------------------------------------------------------------------------}

procedure TComputerEnumThread.AddNetItem;
begin
  newItem := List.Items.Add;
  newItem.Caption := CurrentPC;
  newItem.ImageIndex := 0;
end;

{-----------------------------------------------------------------------------}
//following code ripped off from ALTNet user manager.. love the ripping off..
{-----------------------------------------------------------------------------}

function AgeToString(Duration : dword):string;
var
     timestring: string;
     tempstring: string;
     days    : dword;
begin
     timestring := '';

     // divide by number of seconds in a day
     days := duration div $15180;
     Str(Days,TempString);
     TimeString := TempString + ' days';

     result := timestring;
end;

{-----------------------------------------------------------------------------}
// end of ripped off code :)
{-----------------------------------------------------------------------------}


end.
