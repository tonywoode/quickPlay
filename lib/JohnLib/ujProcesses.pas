unit ujProcesses;

interface

uses SysUtils, Classes, Forms, Windows, stdCtrls;

Type
  TjPriority = (jprRealtime=0,
               jprHigh=1,
               jprAboveNormal=2,
               jprNormal=3,
               jprBelowNormal=4,
               jprIdle=5);
  PJPriority = ^TJPriority;
  TJPriorityStr = Array[TjPriority] of String;

procedure GetAllPriorityStrings(var inStrs : TStrings);
procedure GetProcessList(List: TstringList);
function IsApplicationRunning(FileName: string; bFullpath: Boolean): Boolean;
procedure KillApplication(ExeFileName : String);
procedure KillProcess(PID : Cardinal);
Function GetDosOutput(CommandLine: string; Work: string = 'C:\'): string;
procedure CaptureConsoleOutput(const ACommand, AParameters: String; AMemo: TMemo);
Function RunProcess(const AppPath:String; MustWait: Boolean=FALSE; CurrDir:String='';
    Visibility: Word=SW_SHOWNORMAL; Priority: TjPriority=jprNormal) : String;
Function RunProcessAndReport(const AppPath:String; MustWait: Boolean=FALSE; CurrDir:String='';
    Visibility: Word=SW_SHOWNORMAL; Priority: TjPriority=jprNormal) : Boolean;
function RunProcessAsUser(Domain, Username, Password, ExeName,
    Param: string): Boolean;

ResourceString
  JPRI_REALTIME = 'Real-Time (Not Recommended)';
  JPRI_HIGH = 'High';
  JPRI_ABOVENORMAL = 'Above Normal (Win 2000 + XP Only)';
  JPRI_NORMAL = 'Normal';
  JPRI_BELOWNORMAL = 'Below Normal (Win 2000 + XP Only)';
  JPRI_IDLE = 'Idle (Not Recommended)';

const
  PriorityStrArr : TJPriorityStr = (JPRI_REALTIME,
                                    JPRI_HIGH,
                                    JPRI_ABOVENORMAL,
                                    JPRI_NORMAL,
                                    JPRI_BELOWNORMAL,
                                    JPRI_IDLE);

implementation

uses Psapi, 
     jwaWinBase, JCLStrings;

procedure GetProcessList(List: TstringList);
var
  PIDArray: array [0..1023] of DWORD;
  cb: DWORD;
  I: Integer;
  ProcCount: Integer;
  hMod: HMODULE;
  hProcess: THandle;
  ModuleName: array [0..300] of Char;
begin
  if List = nil then Exit;
  EnumProcesses(@PIDArray, SizeOf(PIDArray), cb);
  ProcCount := cb div SizeOf(DWORD);
  for I := 0 to ProcCount - 1 do
  begin
    hProcess := OpenProcess(PROCESS_QUERY_INFORMATION or
      PROCESS_VM_READ,
      False,
      PIDArray[I]);
    if (hProcess <> 0) then
    begin
      EnumProcessModules(hProcess, @hMod, SizeOf(hMod), cb);
      GetModuleFilenameEx(hProcess, hMod, ModuleName, SizeOf(ModuleName));
      List.Add(ModuleName);
      CloseHandle(hProcess);
    end;
  end;
end;

{-----------------------------------------------------------------------------}

function IsApplicationRunning(FileName: string; bFullpath: Boolean): Boolean;
var
  i: Integer;
  MyProcList: TstringList;
begin
  MyProcList := TStringList.Create;
  try
    GetProcessList(MyProcList);
    Result := False;
    if MyProcList = nil then Exit;
    for i := 0 to MyProcList.Count - 1 do
    begin
      if not bFullpath then
      begin
        if CompareText(ExtractFileName(MyProcList.Strings[i]), FileName) = 0 then
          Result := True
      end
      else if CompareText(MyProcList.strings[i], FileName) = 0 then Result := True;
      if Result then Break;
    end;
  finally
    FreeAndNil(MyProcList);
  end;
end;

{-----------------------------------------------------------------------------}

procedure KillApplication(ExeFileName : String);
var
  PIDArray: array [0..1023] of DWORD;
  cb: DWORD;
  I: Integer;
  ProcCount: Integer;
  hMod: HMODULE;
  hProcess: THandle;
  ModuleName: array [0..300] of Char;
begin
  EnumProcesses(@PIDArray, SizeOf(PIDArray), cb);
  ProcCount := cb div SizeOf(DWORD);
  for I := 0 to ProcCount - 1 do
  begin
    hProcess := OpenProcess(PROCESS_QUERY_INFORMATION or
      PROCESS_VM_READ,
      False,
      PIDArray[I]);
    if (hProcess <> 0) then
    begin
      EnumProcessModules(hProcess, @hMod, SizeOf(hMod), cb);
      GetModuleFilenameEx(hProcess, hMod, ModuleName, SizeOf(ModuleName));
      if JCLSTrings.StrCompare(ExeFileName, ExtractFileName(ModuleName)) = 0 then
        KillProcess(PIDArray[I]);
      CloseHandle(hProcess);
    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure KillProcess(PID : Cardinal);
var
  x : THandle;
begin
  x:=Openprocess(PROCESS_TERMINATE,false,PID);
  if x <> 0 then
  begin
    try
      TerminateProcess(x, 0);
    finally
      CloseHandle(x);
    end;
  end;
end;

{-----------------------------------------------------------------------------}
 // https://stackoverflow.com/questions/1454501/how-do-i-run-a-command-line-program-in-delphi
 // note the note there if you ever upgrade anything
 //For Variant 1, in the newer versions of Delphi (eg. 10.3) remove the "windows." prefix in the line starting "WasOK := windows.ReadFile" otherwise it fails to compile. – gurpal2000 Dec 15 '18 at 10:29
 // @gurpal2000 - maybe you need to have "winapi.windows.readfile" ?
 //also note theres a Variant2 which is called CaptureConsoleOutput
function GetDosOutput(CommandLine: string; Work: string = 'C:\'): string;  { Run a DOS program and retrieve its output dynamically while it is running. }
var
  SecAtrrs: TSecurityAttributes;
  StartupInfo: TStartupInfo;
  ProcessInfo: TProcessInformation;
  StdOutPipeRead, StdOutPipeWrite: THandle;
  WasOK: Boolean;
  pCommandLine: array[0..255] of AnsiChar;
  BytesRead: Cardinal;
  WorkDir: string;
  Handle: Boolean;
begin
  Result := '';
  with SecAtrrs do begin
    nLength := SizeOf(SecAtrrs);
    bInheritHandle := True;
    lpSecurityDescriptor := nil;
  end;
  CreatePipe(StdOutPipeRead, StdOutPipeWrite, @SecAtrrs, 0);
  try
    with StartupInfo do
    begin
      FillChar(StartupInfo, SizeOf(StartupInfo), 0);
      cb := SizeOf(StartupInfo);
      dwFlags := STARTF_USESHOWWINDOW or STARTF_USESTDHANDLES;
      wShowWindow := SW_HIDE;
      hStdInput := GetStdHandle(STD_INPUT_HANDLE); // don't redirect stdin
      hStdOutput := StdOutPipeWrite;
      hStdError := StdOutPipeWrite;
    end;
    WorkDir := Work;
    Handle := CreateProcess(nil, PChar(CommandLine),
                            nil, nil, True, 0, nil,
                            PChar(WorkDir), StartupInfo, ProcessInfo);
    CloseHandle(StdOutPipeWrite);
    if Handle then
      try
        repeat
          WasOK := windows.ReadFile(StdOutPipeRead, pCommandLine, 255, BytesRead, nil);
          if BytesRead > 0 then
          begin
            pCommandLine[BytesRead] := #0;
            Result := Result + pCommandLine;
          end;
        until not WasOK or (BytesRead = 0);
        WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
      finally
        CloseHandle(ProcessInfo.hThread);
        CloseHandle(ProcessInfo.hProcess);
      end;
  finally
    CloseHandle(StdOutPipeRead);
  end;
end;
{ ------}
//variant 2 of the same stack answer, this just pauses on my node code, not sure why

procedure CaptureConsoleOutput(const ACommand, AParameters: String; AMemo: TMemo);
 const
   CReadBuffer = 2400;
 var
   saSecurity: TSecurityAttributes;
   hRead: THandle;
   hWrite: THandle;
   suiStartup: TStartupInfo;
   piProcess: TProcessInformation;
   pBuffer: array[0..CReadBuffer] of AnsiChar;
   dRead: DWord;
   dRunning: DWord;
 begin
   saSecurity.nLength := SizeOf(TSecurityAttributes);
   saSecurity.bInheritHandle := True;  
   saSecurity.lpSecurityDescriptor := nil; 

   if CreatePipe(hRead, hWrite, @saSecurity, 0) then
   begin    
     FillChar(suiStartup, SizeOf(TStartupInfo), #0);
     suiStartup.cb := SizeOf(TStartupInfo);
     suiStartup.hStdInput := hRead;
     suiStartup.hStdOutput := hWrite;
     suiStartup.hStdError := hWrite;
     suiStartup.dwFlags := STARTF_USESTDHANDLES or STARTF_USESHOWWINDOW;    
     suiStartup.wShowWindow := SW_HIDE; 

     if CreateProcess(nil, PChar(ACommand + ' ' + AParameters), @saSecurity,
       @saSecurity, True, NORMAL_PRIORITY_CLASS, nil, nil, suiStartup, piProcess)
       then
     begin
       repeat
         dRunning  := WaitForSingleObject(piProcess.hProcess, 100);        
         Application.ProcessMessages(); 
         repeat
           dRead := 0;
           windows.ReadFile(hRead, pBuffer[0], CReadBuffer, dRead, nil);          
           pBuffer[dRead] := #0; 

           OemToAnsi(pBuffer, pBuffer);
           AMemo.Lines.Add(String(pBuffer));
         until (dRead < CReadBuffer);      
       until (dRunning <> WAIT_TIMEOUT);
       CloseHandle(piProcess.hProcess);
       CloseHandle(piProcess.hThread);    
     end; 

     CloseHandle(hRead);
     CloseHandle(hWrite);
   end;
end;

{-----------------------------}
// John's original:
//Procedure to run a process - Dont know why i need this but i do.
function RunProcess(const AppPath:String; MustWait: Boolean=FALSE; CurrDir:String='';
  Visibility: Word=SW_SHOWNORMAL; Priority: TjPriority=jprNormal) : String;
var
  SI: TStartupInfo;
  PI: TProcessInformation;
  Proc: THandle;
  zFileName: array[0..255] of Char;
  zCurrPath: array[0..255] of Char;
  PResult : Dword;
  PriorInt : Integer;
begin

  Result := '';
  
  if AppPath = '' then
    Result := 'No application specified'
  else
  Begin
  
  FillChar(SI, SizeOf(SI), 0);
  SI.cb := SizeOf(SI);
  SI.dwFlags:= StartF_UseShowWindow;
  SI.wShowWindow := Visibility;
  StrPCopy(zFileName, AppPath);

  case Priority of
    jprRealtime    : PriorInt := REALTIME_PRIORITY_CLASS;
    jprHigh        : PriorInt := HIGH_PRIORITY_CLASS;
    jprAboveNormal : PriorInt := ABOVE_NORMAL_PRIORITY_CLASS;
    jprNormal      : PriorInt := NORMAL_PRIORITY_CLASS;
    jprBelowNormal : PriorInt := BELOW_NORMAL_PRIORITY_CLASS;
    jprIdle        : PriorInt := IDLE_PRIORITY_CLASS;
    else
      PriorInt := NORMAL_PRIORITY_CLASS;
  end;

  if CurrDir <> '' then
  Begin
    StrPCopy(zCurrPath, CurrDir);
    if not CreateProcess(nil, zFileName,
        nil, nil, false, CREATE_NEW_PROCESS_GROUP+PriorInt, nil, zCurrPath, SI, PI) then
      Result := 'Create process failed';
  end
  else
    if not CreateProcess(nil, zFileName,
        nil, nil, false, CREATE_NEW_PROCESS_GROUP+PriorInt, nil, nil, SI, PI) then
      Result := 'Create process failed';

  Proc := PI.hProcess;
  CloseHandle(PI.hThread);

  if MustWait then
  begin
    // it will wait 10 seconds (10000)
    if WaitForSingleObject(Proc, 10000) <> Wait_Failed then
    begin
      GetExitCodeProcess(Proc, PResult);
      while PResult = STILL_ACTIVE do
        begin
          Application.ProcessMessages;
          if WaitForSingleObject(Proc, 10000) <> Wait_Failed then
            GetExitCodeProcess(Proc, PResult);
        end;
    end;
  end;

  CloseHandle(Proc);

  end;
end;

{--------------------------------}
function RunProcessAndReport(const AppPath:String; MustWait: Boolean=FALSE; CurrDir:String='';
  Visibility: Word=SW_SHOWNORMAL; Priority: TjPriority=jprNormal) : Boolean;
var
  SI: TStartupInfo;
  PI: TProcessInformation;
  Proc: THandle;
  zFileName: array[0..255] of Char;
  zCurrPath: array[0..255] of Char;
  PResult : Dword;
  PriorInt : Integer;
begin

  Result := False;

  if AppPath = '' then
    Result := False
  else
  Begin
  
  FillChar(SI, SizeOf(SI), 0);
  SI.cb := SizeOf(SI);
  SI.dwFlags:= StartF_UseShowWindow;
  SI.wShowWindow := Visibility;
  StrPCopy(zFileName, AppPath);

  case Priority of
    jprRealtime    : PriorInt := REALTIME_PRIORITY_CLASS;
    jprHigh        : PriorInt := HIGH_PRIORITY_CLASS;
    jprAboveNormal : PriorInt := ABOVE_NORMAL_PRIORITY_CLASS;
    jprNormal      : PriorInt := NORMAL_PRIORITY_CLASS;
    jprBelowNormal : PriorInt := BELOW_NORMAL_PRIORITY_CLASS;
    jprIdle        : PriorInt := IDLE_PRIORITY_CLASS;
    else
      PriorInt := NORMAL_PRIORITY_CLASS;
  end;

  if CurrDir <> '' then
  Begin
    StrPCopy(zCurrPath, CurrDir);
    if not CreateProcess(nil, zFileName,
        nil, nil, false, CREATE_NEW_PROCESS_GROUP+PriorInt, nil, zCurrPath, SI, PI) then
      Result := False;
  end
  else
    if not CreateProcess(nil, zFileName,
        nil, nil, false, CREATE_NEW_PROCESS_GROUP+PriorInt, nil, nil, SI, PI) then
      Result := False;

  Proc := PI.hProcess;
  CloseHandle(PI.hThread);

  if MustWait then
  begin
    // it will wait 10 seconds (10000)
    if WaitForSingleObject(Proc, 10000) <> Wait_Failed then
    begin
      GetExitCodeProcess(Proc, PResult);
      while PResult = STILL_ACTIVE do
        begin
          Application.ProcessMessages;
          if WaitForSingleObject(Proc, 10000) <> Wait_Failed then
            GetExitCodeProcess(Proc, PResult);
            if PResult = 0 then
              Result := True;
        end;
    end;
  end;
      GetExitCodeProcess(Proc, PResult);
            if PResult = 0 then
              Result := True;
  CloseHandle(Proc);

  end;
end;

{-----------------------------------------------------------------------------}

function RunProcessAsUser(Domain, Username, Password, ExeName, Param: string):
Boolean;
var
  StartupInfo: TStartupInfoW;
  ProcessInfo: TProcessInformation;
  tmpParam : String;
  wExeName, wParam, wDomain, wUsername, wPassword: PWideChar;
begin
  FillChar (StartupInfo, SizeOf(StartupInfo), #0);
  StartupInfo.cb := SizeOf(StartupInfo);
  StartupInfo.dwFlags := STARTF_USESHOWWINDOW;
  StartupInfo.wShowWindow := SW_SHOWNORMAL;

  if ExeName <> '' then
    tmpParam := Format('"%s" %s', [ExeName, Param])
  else
    tmpParam := Param;

  GetMem(wDomain,   Length(Domain)   * SizeOf(WideChar) +
SizeOf(WideChar));
  GetMem(wUsername, length(Username) * SizeOf(WideChar) +
SizeOf(WideChar));
  GetMem(wPassword, length(Password) * SizeOf(WideChar) +
SizeOf(WideChar));
  GetMem(wExeName, Length(ExeName) * SizeOf(WideChar) +
SizeOf(WideChar));
  GetMem(wParam, Length(tmpParam) * SizeOf(WideChar) +
SizeOf(WideChar));

  StringToWideChar(Domain,   wDomain,   Length(Domain)   * SizeOf(WideChar)
+ SizeOf(WideChar));
  StringToWideChar(Username, wUsername, Length(Username) * SizeOf(WideChar)
+ SizeOf(WideChar));
  StringToWideChar(Password, wPassword, Length(Password) * SizeOf(WideChar)
+ SizeOf(WideChar));
  StringToWideChar(ExeName, wExeName, Length(ExeName) * SizeOf(WideChar)
+ SizeOf(WideChar));
  StringToWideChar(tmpParam, wParam, Length(tmpParam) * SizeOf(WideChar)
+ SizeOf(WideChar));

  Result := CreateProcessWithLogonW(
    wUsername,
    wDomain,
    wPassword,
    0,
    wExeName,
    wParam,
    0,
    nil,
    nil,
    StartupInfo,
    ProcessInfo);

  if Result then
  begin
    WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
    CloseHandle(ProcessInfo.hProcess);
    CloseHandle(ProcessInfo.hThread);
  end else
    RaiseLastOSError;

  FreeMem(wDomain);
  FreeMem(wUsername);
  FreeMem(wPassword);
  FreeMem(wExeName);
  FreeMem(wParam);
end;

{-----------------------------------------------------------------------------}

procedure GetAllPriorityStrings(var inStrs : TStrings);
begin
  if inStrs = nil then
    Exit;
  InStrs.Add(JPRI_REALTIME);
  InStrs.Add(JPRI_HIGH);
  InStrs.Add(JPRI_ABOVENORMAL);
  InStrs.Add(JPRI_NORMAL);
  InStrs.Add(JPRI_BELOWNORMAL);
  InStrs.Add(JPRI_IDLE);
end;

{-----------------------------------------------------------------------------}

end.
