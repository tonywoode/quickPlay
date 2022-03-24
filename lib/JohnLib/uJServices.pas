unit uJServices;

interface

Function ServiceChangeStartType(Machine, ServiceName : String; StartType : Integer) : Boolean;
function ServiceDelete(Machine, ServiceName : String): boolean;
Function ServiceDisabled(SMachine, ServiceName : String) : Boolean;
function ServiceExists(Machine, ServiceName : String): boolean;
function ServiceForceStart(Machine, ServiceName : String) : Boolean;
function ServiceRunning(sMachine, sService: PChar): Boolean;
function ServiceStart(Machine, ServiceName: string): Boolean;
function ServiceStop(Machine, ServiceName: string): Boolean;
function ServiceVNCCreate(Machine : String): Boolean;
Function ServiceVNCRepeaterCreate(Machine : String) : Boolean;

implementation

uses
  windows, WinSvc;

////////////////////////////////////////////////////////////////////////////////
// Procedure : ServiceGetStatus
// Comment   : Author: DieHardMan

function ServiceGetStatus(sMachine, sService: PChar): DWORD;
  {******************************************}
  {*** Parameters: ***} 
  {*** sService: specifies the name of the service to open 
  {*** sMachine: specifies the name of the target computer 
  {*** ***} 
  {*** Return Values: ***} 
  {*** -1 = Error opening service ***} 
  {*** 1 = SERVICE_STOPPED ***} 
  {*** 2 = SERVICE_START_PENDING ***} 
  {*** 3 = SERVICE_STOP_PENDING ***} 
  {*** 4 = SERVICE_RUNNING ***} 
  {*** 5 = SERVICE_CONTINUE_PENDING ***} 
  {*** 6 = SERVICE_PAUSE_PENDING ***} 
  {*** 7 = SERVICE_PAUSED ***} 
  {******************************************} 
var 
  SCManHandle, SvcHandle: SC_Handle; 
  SS: TServiceStatus; 
  dwStat: DWORD; 
begin 
  dwStat := 0; 
  // Open service manager handle. 
  SCManHandle := OpenSCManager(sMachine, nil, SC_MANAGER_CONNECT); 
  if (SCManHandle > 0) then 
  begin 
    SvcHandle := OpenService(SCManHandle, sService, SERVICE_QUERY_STATUS); 
    // if Service installed 
    if (SvcHandle > 0) then 
    begin 
      // SS structure holds the service status (TServiceStatus); 
      if (QueryServiceStatus(SvcHandle, SS)) then 
        dwStat := ss.dwCurrentState; 
      CloseServiceHandle(SvcHandle); 
    end; 
    CloseServiceHandle(SCManHandle); 
  end; 
  Result := dwStat; 
end; 

{-----------------------------------------------------------------------}

Function ServiceChangeStartType(Machine, ServiceName : String; StartType : Integer) : Boolean;
{ START TYPE SETTINGS.

SERVICE_BOOT_START = 0
SERVICE_SYSTEM_START =1
SERVICE_AUTO_START = 2
SERVICE_DEMAND_START = 3
SERVICE_DISABLED = 4
}
var
  h_manager, h_svc: SC_Handle;
begin
  Result := False;
  h_manager := OpenSCManager(PChar(Machine), nil, SC_MANAGER_CONNECT);
  if h_manager > 0 then
  begin
    h_svc := OpenService(h_manager, PChar(ServiceName),SERVICE_CHANGE_CONFIG);
    if h_svc > 0 then
    begin

      if ChangeServiceConfig(h_svc, SERVICE_NO_CHANGE, StartType, SERVICE_NO_CHANGE,
                              nil, nil, nil, nil, nil, nil, nil) then
        Result := True
      else
        Result := False;

      CloseServiceHandle(h_svc);
    end;
    CloseServiceHandle(h_manager);
  end;

end;

{-----------------------------------------------------------------------}

Function ServiceDisabled(SMachine, ServiceName : String) : Boolean;
var
  h_manager, h_svc: SC_Handle;
  PConfig : PQueryServiceConfigA;
  iSize : Cardinal;
begin
  Result := True;
  h_manager := OpenSCManager(PChar(SMachine), nil, SC_MANAGER_CONNECT);
  if h_manager > 0 then
  begin
    h_svc := OpenService(h_manager, PChar(ServiceName),SERVICE_QUERY_CONFIG);
    if h_svc > 0 then
    begin
      iSize := 0;
      PConfig := nil;
      if not QueryServiceConfig( h_svc, PConfig, 0, iSize ) then
      begin
        if iSize > 0 then
        begin
          GetMem(PConfig, iSize +1);
          if QueryServiceConfig( h_svc, PConfig, iSize, iSize ) then
            Result := (SERVICE_DISABLED = PConfig^.dwStartType);

        end
      end;

      CloseServiceHandle(h_svc);
    end;
    CloseServiceHandle(h_manager);
  end;
end;

{-----------------------------------------------------------------------}

function ServiceRunning(sMachine, sService: PChar): Boolean;
begin 
  Result := SERVICE_RUNNING = ServiceGetStatus(sMachine, sService); 
end; 

{-----------------------------------------------------------------------}

function ServiceForceStart(Machine, ServiceName : String) : Boolean;
begin
  if not ujServices.ServiceRunning( PChar(Machine), PChar(ServiceName) ) then
  begin
    //check that the service isnt disabled, if it is then enable it.
    if uJServices.ServiceDisabled(Machine, ServiceName) then
    begin
      if not UJServices.ServiceChangeStartType(Machine, ServiceName, 3) then
      begin
        Result := False;
        exit;
      end;
    end;

    //start the service.
    if ujServices.ServiceStart(Machine, ServiceName) then
      Result := True
    else
      Result := False;
    
  end
  else
    Result := True;
end;

{-----------------------------------------------------------------------}

function ServiceStart(Machine, ServiceName: string): Boolean;
// Machine is UNC path or local machine if empty
var
  h_manager, h_svc: SC_Handle;
  ServiceStatus: TServiceStatus;
  dwCheckPoint: DWORD;
    ServiceArgVectors: PChar;
begin
  h_manager := OpenSCManager(PChar(Machine), nil, SC_MANAGER_CONNECT);
  if h_manager > 0 then
  begin
    h_svc := OpenService(h_manager, PChar(ServiceName),
      SERVICE_START or SERVICE_QUERY_STATUS);
    if h_svc > 0 then
    begin
      if (StartService(h_svc, 0, ServiceArgVectors)) then { succeeded }
      begin
        if (QueryServiceStatus(h_svc, ServiceStatus)) then
        begin
          while (SERVICE_RUNNING <> ServiceStatus.dwCurrentState) do
          begin
            dwCheckPoint := ServiceStatus.dwCheckPoint;
            Sleep(ServiceStatus.dwWaitHint);
            if (not QueryServiceStatus(h_svc, ServiceStatus)) then
              // couldn't check status
              break;
            if (ServiceStatus.dwCheckPoint < dwCheckPoint) then
              break;
          end;
        end;
      end;
      CloseServiceHandle(h_svc);
    end;
    CloseServiceHandle(h_manager);
  end;

  Result := (SERVICE_RUNNING = ServiceStatus.dwCurrentState);
end;

{-----------------------------------------------------------------------}

function ServiceStop(Machine, ServiceName: string): Boolean;
// Machine is UNC path or local machine if empty
var
  h_manager, h_svc: SC_Handle;
  ServiceStatus: TServiceStatus;
  dwCheckPoint: DWORD;
begin
  h_manager := OpenSCManager(PChar(Machine), nil, SC_MANAGER_CONNECT);
  if h_manager > 0 then
  begin
    h_svc := OpenService(h_manager, PChar(ServiceName),
      SERVICE_STOP or SERVICE_QUERY_STATUS);
    if h_svc > 0 then
    begin
      if (ControlService(h_svc, SERVICE_CONTROL_STOP, ServiceStatus)) then
      begin
        if (QueryServiceStatus(h_svc, ServiceStatus)) then
        begin
          while (SERVICE_STOPPED <> ServiceStatus.dwCurrentState) do
          begin
            dwCheckPoint := ServiceStatus.dwCheckPoint;
            Sleep(ServiceStatus.dwWaitHint);
            if (not QueryServiceStatus(h_svc, ServiceStatus)) then
              // couldn't check status
              break;
            if (ServiceStatus.dwCheckPoint < dwCheckPoint) then
              break;
          end;
        end;
      end;
      CloseServiceHandle(h_svc);
    end;
    CloseServiceHandle(h_manager);
  end;

  Result := (SERVICE_STOPPED = ServiceStatus.dwCurrentState);
end;

{-----------------------------------------------------------------------}

function ServiceDelete(Machine, ServiceName : String): boolean;
var
  h_manager, h_svc: SC_Handle;
begin
  Result := False;
  h_manager := OpenSCManager(PChar(Machine), nil, SC_MANAGER_ALL_ACCESS);
  if h_manager > 0 then
  begin
    h_svc := OpenService(h_manager, PChar(ServiceName), STANDARD_RIGHTS_REQUIRED);
    if h_svc > 0 then
    begin
      Result := DeleteService(h_svc);
      CloseServiceHandle(h_svc);
    end;
    CloseServiceHandle(h_manager);
  end;

end;

{-----------------------------------------------------------------------}

function ServiceExists(Machine, ServiceName : String): boolean;
var
  h_manager, h_svc: SC_Handle;
begin
  Result := False;
  h_manager := OpenSCManager(PChar(Machine), nil, SC_MANAGER_CONNECT);
  if H_manager > 0 then
  begin
    h_svc := OpenService(h_manager, PChar(ServiceName), STANDARD_RIGHTS_REQUIRED);
    if H_Svc > 0 then
    begin
      Result := True;
      CloseServiceHandle(h_svc);
    end;
    CloseServiceHandle(h_manager);
  end;
end;

//--------------------------------------------------------------------
//  Now theres my code, this creates the VNC service :D

function ServiceVNCCreate(Machine : String): Boolean;
// Machine is UNC path or local machine if empty
var
  h_manager, h_svc: SC_Handle;
begin
  Result := False;
  h_manager := OpenSCManager(PChar(Machine), nil, SC_MANAGER_ALL_ACCESS);

    if h_manager > 0 then
    begin
      h_svc := CreateService(h_manager, PChar('ISUVNC'), PChar('ISU Temporary VNC'),
             SERVICE_ALL_ACCESS, SERVICE_WIN32_OWN_PROCESS or SERVICE_INTERACTIVE_PROCESS,
             SERVICE_DEMAND_START, SERVICE_ERROR_NORMAL, PChar('"c:\Program Files\ISUVNC\WinVNC.exe" -service'),
             nil, nil, nil, nil,PChar(''));
      if h_svc > 0 then
      begin
        CloseServiceHandle(h_svc);
        Result := True;
      end;

      CloseServiceHandle(h_manager);

    end;
end;

{-----------------------------------------------------------------------}

Function ServiceVNCRepeaterCreate(Machine : String) : Boolean;
var
  h_manager, h_svc: SC_Handle;
begin
  Result := False;
  h_manager := OpenSCManager(PChar(Machine), nil, SC_MANAGER_ALL_ACCESS);

    if h_manager > 0 then
    begin
      h_svc := CreateService(h_manager, PChar('repeater_service'), PChar('VNC Repeater Service'),
             SERVICE_ALL_ACCESS, SERVICE_WIN32_OWN_PROCESS,
             SERVICE_DEMAND_START, SERVICE_ERROR_NORMAL, PChar('c:\repeater.exe -service'),
             nil, nil, nil, nil,PChar(''));
      if h_svc > 0 then
      begin
        CloseServiceHandle(h_svc);
        Result := True;
      end;

      CloseServiceHandle(h_manager);

    end;
end;

{-----------------------------------------------------------------------}

end.
