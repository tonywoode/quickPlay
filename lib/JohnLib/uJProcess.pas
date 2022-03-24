unit uJProcess;

interface

uses SysUtils, Classes;

type
  TJProcess = class(TObject)
  protected
    _PC : String;
    _Name : String;
    _PID : Integer;
    _MemUsage : String;
    _UserName : String;
  public
    Property HostPC : String read _PC write _PC;
    Property ProcessName : String read _Name write _Name;
    Property PID : Integer read _PID write _PID;
    Property MemUsage : String read _MemUsage write _MemUsage;
    Property UserName : String read _UserName write _UserName;
    constructor Create();overload;
    constructor Create(PC : String; CSVLine : String);overload;
    procedure ImportFromCSV(CSVLine : String);
    procedure KillMe();
  end;

implementation

uses JCLShell, JCLStrings;

{---------------------------------------------------------------------------}
{   TJProcess CODE  }
{---------------------------------------------------------------------------}

constructor TJProcess.Create();
begin
  inherited Create();
end;

{---------------------------------------------------------------------------}

constructor TJProcess.Create(PC : String; CSVLine : String);
begin
  inherited Create();
  Self._PC := PC;
  Self.ImportFromCSV(CSVLine);
end;

{---------------------------------------------------------------------------}

procedure TJProcess.ImportFromCSV(CSVLine : String);
var
  SplitList : TStringList;
  TmpStr : String;
  apostrophe : Boolean;
  i  : Integer;
  valcount : integer;
begin
  //we need to create our splitlist stringlist
  if CSVLine = '' then
    Exit;
    
  SplitList := TStringList.Create;
  try
    valcount := 0;
    SplitList.Add('');
    Apostrophe := False;
    tmpStr := CSVLine;
    for i := 1 to Length(tmpStr) do
    begin

      if (tmpStr[i] = '"') and (apostrophe = false) then
      begin
        apostrophe := true;
      end
      else if (tmpStr[i] = '"') and (apostrophe = true) then
      begin
        apostrophe := false;
      end
      else if (tmpStr[i] = ',') and (apostrophe = false) then
      begin
        SplitList.Add('');
        inc(valcount);
      end
      else
      begin
        SplitList[valcount] := SplitList[valcount] + tmpStr[i];
      end;

    end;

    Self._Name := SplitList[0];
    Self._PID := StrToInt(SplitList[1]);
    Self._MemUsage := SplitList[4];
    Self._UserName := SplitList[6];
  finally
    FreeAndNil(SplitList);
  end;
end;

{---------------------------------------------------------------------------}

procedure TJProcess.KillMe();
begin
  if (Self._PC <> '') and (self._PID <> -1) then
    JCLShell.ShellExecEx('pskill', '-t \\' + self._PC + ' ' + IntToStr(Self._PID))
end;

end.
