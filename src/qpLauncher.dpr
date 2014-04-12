program qpLauncher;

{$APPTYPE CONSOLE}

uses
  SysUtils, Windows, ShellAPI;

var
  Param, WorkDir, Exe : String;

function ShellExecAndWait(const FileName: string; const Parameters: string;
  const dir: string; CmdShow: Integer=SW_SHOWNORMAL): Boolean;
var
  Sei: TShellExecuteInfo;
begin
  FillChar(Sei, SizeOf(Sei), #0);
  Sei.cbSize := SizeOf(Sei);
  Sei.fMask := SEE_MASK_DOENVSUBST or SEE_MASK_FLAG_NO_UI or SEE_MASK_NOCLOSEPROCESS;
  Sei.lpFile := PChar(FileName);
  Sei.lpParameters := PChar(Parameters);
  Sei.lpdirectory := PChar(dir);
  Sei.nShow := CmdShow;
  Result := ShellExecuteEx(@Sei);
  if Result then
  begin
    WaitForInputIdle(Sei.hProcess, INFINITE);
    WaitForSingleObject(Sei.hProcess, INFINITE);
    CloseHandle(Sei.hProcess);
  end;
end;

Procedure ShellExec(const FileName: string; const Parameters: string;
  const dir: string; CmdShow: Integer=SW_SHOWNORMAL);
begin
  ShellExecute(GetDesktopWindow(), nil, PChar(FileName), nil, PChar(dir), CmdShow);
end;
{-----------------------------------------------------------------------------}


begin
  if (ParamStr(1) <> '') and (ParamStr(2) <> '') then
  begin

    Exe :=  StringReplace(ParamStr(1) , '¬', ' ', [rfReplaceAll]);
    Param := StringReplace(ParamStr(2) , '¬', ' ', [rfReplaceAll]);
    WorkDir := ExtractFilePath(Exe);

    try
      ShellExecAndWait(Exe, Param, WorkDir, SW_SHOWNORMAL);
    finally
      //now relaunch the program.
      ShellExec('qp.exe', '', '', SW_SHOWNORMAL);
    end;

  end;
  
end.
