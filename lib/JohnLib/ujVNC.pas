unit ujVNC;

interface

type
  TVNCConnectionType = (vncAskPermission = 0,
                        vncTakeOver = 1,
                        vncSpyOnUser = 2,
                        vncTakeOverDisableInput = 3,
                        vncRemoveLeaveDriver=4, //removes VNC, but leaves the driver
                        vncRemoveAll=5); //removes VNC AND Driver

  TVNCOptions = record
    ConnectionType : TVNCConnectionType;
    RemoveWallpaper : Boolean;
    QuickMode : Integer;
    OnPort : Integer;
    AllowDriverInstall : Boolean;
  end;

  TVNCStatusCallBack = procedure(statusmsg : String) of object;

Function HasISUVNCRunning(PC : String) : Boolean;
Function HasAnyVNCRunning(PC : String) : Boolean;

procedure InstallDriver(PC, DrvDir : String; CallBack : TVNCStatusCallBack);
procedure UninstallDriver(PC, DrvDir : String; CallBack : TVNCStatusCallBack);

Procedure InstallVNC(PC : String; Opt : TVNCOptions; SrcDir : String;
                  CallBack : TVNCStatusCallBack);
procedure UninstallVNC(PC : String; RemoveFiles : Boolean; CallBack : TVNCStatusCallBack);

var
  ConnStrs : Array[TVNCConnectionType] of String = (
                     'Install VNC and Ask user for Permission.',
                     'Install VNC and Take Control.',
                     'Install VNC in view-only mode, useful for spying.',
                     'Install VNC and disable input on the remote PC',
                     'Remove any left-over VNC files, but leave the video driver',
                     'Remove any left-over VNC files including the video driver');

implementation

uses SysUtils, Classes, Windows, Registry,
     JCLShell, JvSHFileOperation, JCLFileUtils,
     ujServices, ujFile;

const
  VNCLOCALPATH = 'c:\Program Files\ISUVNC\';
  VNCREMOTEPATH = '\\%s\c$\program files\ISUVNC\';

var
    //VNC Password.
  pass : Array[0..7] of Byte = ($98, $CE, $11, $81, $9F, $6C, $B8, $9C);


{------------------------------------------------------------------------------}

Function HasISUVNCRunning(PC : String) : Boolean;
begin
  if (ujServices.ServiceExists('\\'+PC, 'ISUVNC')) and
     (uJServices.ServiceRunning(PChar('\\'+ PC), PChar('ISUVNC'))) then
    Result := True
  else
    Result := False;
end;

{------------------------------------------------------------------------------}

Function HasAnyVNCRunning(PC : String) : Boolean;
begin
  if (ujServices.ServiceExists('\\'+PC, 'winvnc')) and
     (uJServices.ServiceRunning(PChar('\\'+ PC), PChar('winvnc'))) then
    Result := True
  else
    Result := False;
end;

{------------------------------------------------------------------------------}

procedure InstallDriver(PC, DrvDir : String; CallBack : TVNCStatusCallBack);
var
  Cmd : String;
  RDir : String;
begin
  //runs the silent installer to install the VNC video driver.

  //check that the driver isnt already on the system.
  If Assigned(CallBack) then
    CallBack('Starting Driver install');

  rDir := Format(VNCREMOTEPATH + 'driver\', [PC]);

  if not DirectoryExists(rDir) then
  begin

    if DirectoryExists(DrvDir) then
    begin
      If Assigned(CallBack) then
        CallBack('Executing Driver install on PC, hold on to your socks');

      //copy the driver to teh remote PC.
      ujFile.DirCopy(DrvDir, rDir, True);

      Cmd := Format('-c -i -s \\%s "%sISUDriverInstall.bat"', [PC, DrvDir]);

      If Assigned(CallBack) then
        CallBack('Driver install cmd: ' + Cmd);

      JCLShell.ShellExecAndWait('psexec.exe', Cmd, '', SW_HIDE);
    end
    else
      If Assigned(CallBack) then
        CallBack('Driver setup does not exist');
      
  end
  else
    If Assigned(CallBack) then
      CallBack('VNC Driver is already installed on PC');
end;

{------------------------------------------------------------------------------}

procedure UninstallDriver(PC, DrvDir : String; CallBack : TVNCStatusCallBack);
var
  Cmd : String;
begin
  //Runs the silent uninstaller.  A reboot is necessary on the remote PC to
  //completely remove the driver.

  if Assigned(Callback) then
    CallBack('Starting Driver Uninstall');

  //check that the VNC Driver is actually installed on the target.
  if DirectoryExists(Format(VNCREMOTEPATH + 'driver', [PC])) then
  begin

    Cmd := Format('-c -s \\%s "%sISUDriverUninstall.bat"', [PC, DrvDir]);
    if Assigned(Callback) then
      CallBack('Driver Uninstall Cmd - ' + Cmd);
    JCLShell.ShellExecAndWait('psexec', Cmd, '', SW_SHOW);

    JCLFileUtils.DelTree(Format(VNCREMOTEPATH + 'driver\', [PC]));

    //do a manual clean up.
    SysUtils.DeleteFile('\\' + PC + '\admin$\system32\drivers\vnccom.sys');
    SysUtils.DeleteFile('\\' + PC + '\admin$\system32\drivers\vncdrv.sys');
    if ujServices.ServiceExists(PC, 'vncdrv') then
      ujServices.ServiceDelete(PC, 'vncdrv');

    if ujServices.ServiceExists(PC, 'vnccom') then
      ujServices.ServiceDelete(PC, 'vnccom');

  end
  else
  begin
    if Assigned(Callback) then
      CallBack('VNC Driver not installed on Remote PC');
  end;
end;

{------------------------------------------------------------------------------}

Procedure InstallVNC(PC : String; Opt : TVNCOptions; SrcDir : String;
                  CallBack : TVNCStatusCallBack);
var
  Reg : TRegistry;
  FileOp : TJvSHFileOperation;  //JVCL File Operation Helper component.
  VNCDir : String;
  RemoteDir : String;
begin

  // make sure the remote registry service is running, if not then bomb out.
  if Assigned(Callback) then
      CallBack('Starting Remote Registry Service');

  if not ujServices.ServiceForceStart(PC, 'RemoteRegistry') then
  begin
    Raise Exception.Create('Unable to start Remote Registry service, VNC connection aborted');
  end;

  if Assigned(Callback) then
      CallBack('Remote Registry service started');

  Reg := TRegistry.Create();
  try

    Reg.RootKey := HKEY_LOCAL_MACHINE;
    if not Reg.RegistryConnect('\\' + PC) then
    begin
      Raise Exception.Create('Unable to connect to remote registry');
    end;

    if Assigned(Callback) then
      CallBack('Connected to remote registry');

    RemoteDir := Format(VNCREMOTEPATH, [PC]);

      //copy the 2 VNC files to the remote PC, i want a progress bar so use the SHFileOperation wrapper
      FileOp := TJvSHFileOperation.Create(nil);
      try

        VNCDir := IncludeTrailingPathDelimiter(SrcDir);

        //configure the FileOp
        FileOp.Options := FileOp.Options + [fofNoConfirmation, fofNoConfirmMkDir];
        FileOp.Options := FileOp.Options - [fofMultiDestFiles];

        if (FileExists(RemoteDir + 'winVNC.exe') = False) or
           (ujFile.FilesSameVersion(RemoteDir + 'winVNC.exe', VNCDir + 'winVNC.exe') = False) then
        begin
          FileOp.SourceFiles.Add(VNCDir + 'winVNC.exe');
          FileOp.SourceFiles.Add(VNCDir + 'VNCHooks.dll');
        end;

        if (FileExists(RemoteDir + 'VNCHooks.dll') = False) then
        begin
          FileOp.SourceFiles.Add(VNCDir + 'VNCHooks.dll');
        end;

        FileOp.DestFiles.Add(RemoteDir);

        if FileOp.SourceFiles.Count > 0 then
        begin
          if Assigned(Callback) then
            CallBack('Starting copying of VNC files to remote PC');
          FileOp.Execute;
        end
        else
          if Assigned(Callback) then
            CallBack('No files need copied to remote PC');

      finally
        FreeAndNil(FileOp);
      end;

      //check the files now exist on the remote PC, from either the copy op, or if
      // they were there before
      if (FileExists(RemoteDir + 'winVNC.exe') ) and
         (FileExists(RemoteDir + 'VNCHooks.dll') ) then
      begin
        //try and hide the files..
        FileSetAttr(RemoteDir + 'winVNC.exe', faHidden);
        FileSetAttr(RemoteDir + 'VNCHooks.dll', faHidden);
      end
      else
      begin
        Raise Exception.Create('VNC files not found on remote PC');
      end;

      if Assigned(Callback) then
        CallBack('Starting registry configuration');

      //if we are still here the remote registry connection is in place.
      //configure the standard settings.
      REG.OpenKey('SOFTWARE\ORL\WinVNC3\', True);
      reg.WriteInteger('AuthRequired', 1);
      reg.WriteInteger('ConnectPriority', 1);
      reg.WriteInteger('EnableHTTPDaemon', 0);
      reg.WriteInteger('EnableURLParams', 0);
      reg.WriteInteger('AllowLoopback', 1);
      reg.WriteInteger('DebugMode', 0);
      reg.WriteInteger('DebugLevel', 0);
      reg.WriteInteger('DisableTrayIcon', 1);
      reg.WriteInteger('MSLogonRequired', 0);
      reg.WriteInteger('NewMSLogon', 0);
      reg.WriteInteger('UseDSMPlugin', 0);

      REG.CloseKey;

      //now configure the default profile settings.
      REG.OpenKey('SOFTWARE\ORL\WinVNC3\default', True);
      reg.WriteInteger('AllowProperties', 0);
      reg.WriteInteger('AllowEditClients', 0);
      reg.WriteInteger('AllowShutdown', 0);
      reg.WriteInteger('AutoPortSelect', 0);
      reg.WriteInteger('SocketConnect', 1);
      reg.WriteInteger('PortNumber', Opt.onPort);

      if Opt.ConnectionType = vncSpyOnUser then
        //spy on user.
        reg.WriteInteger('InputsEnabled', 0)
      else
        //allow input.
        reg.WriteInteger('InputsEnabled', 1);

      if Opt.RemoveWallpaper then
        reg.WriteInteger('RemoveWallpaper', 1)
      else
        reg.WriteInteger('RemoveWallpaper', 0);

      if Opt.ConnectionType = vncTakeOverDisableInput then
        reg.WriteInteger('LocalInputsDisabled', 1)
      else
        reg.WriteInteger('LocalInputsDisabled', 0);

      reg.WriteInteger('LockSetting', 0);
      reg.WriteInteger('EnableFileTransfers', 0);
      reg.WriteInteger('DontSetHooks', 0);
      reg.WriteInteger('PollUnderCursor', 0);
      reg.WriteInteger('PollForeground', 1);
      reg.WriteInteger('PollFullScreen', 1);  //1 for ultravnc, 0 for other servers
      reg.WriteInteger('OnlyPollConsole', 0); //0 for ultravnc, 1 for other servers
      reg.WriteInteger('OnlyPollOnEvent', 1); //1 for ultravnc, 0 for other servers

{QuerySetting
The QuerySetting allows individual users to tailor the degree of paranoia expressed by the per-machine AuthHosts setting. It is a DWORD value ranging from zero (maximum availability) to four (maximum security). The following table indicates how the value affects the AuthHosts behaviour:
0 - +:Accept, ?:Accept, -:Query
1 - +:Accept, ?:Accept, -:Reject
2 - +:Accept, ?:Query, -:Reject [Default]
3 - +:Query, ?:Query, -:Reject
4 - +:Query, ?:Reject, -:Reject
By default, value 2 (Obey AuthHosts) will be assumed. Local & global per-user setting. }

      if Opt.ConnectionType = vncAskPermission then
        reg.WriteInteger('QuerySetting', 3)
      else
        Reg.WriteInteger('QuerySetting', 0);
      
      reg.WriteInteger('QueryTimeout', 15);
      reg.WriteInteger('QueryAccept', 0);
    
      //write password (its m1ll1sle)
      reg.WriteBinaryData('Password', pass[0], 8);
      reg.WriteBinaryData('PasswordViewOnly', Pass[0], 8);

      //specific UltraVNC settings.
      Reg.WriteInteger('TurboMode', 0);

      //always use the driver if it is available
      reg.WriteInteger('DontUseDriver', 0);
      Reg.WriteInteger('EnableDriver', 1);

      Reg.WriteInteger('EnableHook', 1);
      Reg.WriteInteger('EnableVirtual', 0);
      Reg.WriteInteger('FTUserImpersonation', 0);
      Reg.WriteInteger('FileTransferEnabled', 0);
      Reg.WriteInteger('BlankMonitorEnabled', 1);
      Reg.WriteInteger('CaptureAlphaBlending', 0);
      Reg.WriteInteger('BlackAlphaBlending', 0);
      Reg.WriteInteger('XDMCPConnect', 0);
      Reg.WriteInteger('UseDSMPlugin', 0);
      Reg.WriteInteger('DefaultScale', 1);
      Reg.WriteInteger('HTTPConnect', 0);

      REG.CloseKey;

      if Assigned(Callback) then
        CallBack('End of registry configuration');

      if not ujServices.ServiceExists('\\'+ PC, 'ISUVNC') then
      begin
        if Assigned(Callback) then
          CallBack('Registering VNC as a system service');
        uJServices.ServiceVNCCreate('\\'+ PC);
      end;

      //now install the driver if required.
      if Opt.AllowDriverInstall then
      begin
        if Assigned(Callback) then
          CallBack('Checking to see if driver needs installed');
        InstallDriver(PC, VNCDir + 'driver\', CallBack);
      end;

      if Assigned(Callback) then
        CallBack('Starting VNC Service on remote PC');

      if ( not uJServices.ServiceRunning(PChar('\\'+ PC), PChar('ISUVNC')) ) and
       (not uJServices.ServiceStart('\\'+ PC, 'ISUVNC')) then
      begin
        Raise Exception.Create('Unable to start VNC service');
      end;

      if Assigned(Callback) then
        CallBack('VNC Service Started');

      if Opt.ConnectionType = vncAskPermission then
      begin
        if Assigned(Callback) then
          CallBack('Starting VNC Service Helper');
      //to ask permission we need to start the servicehelper on the remote pc
        JCLShell.ShellExecAndWait(Format('%spsexec.exe', [VNCDir]), Format('-s -i \\%s "%swinvnc.exe" -servicehelper', [PC, VNCLOCALPATH]), '', SW_HIDE);
      end;

      if Assigned(Callback) then
        CallBack('VNC Server installation complete');

  finally
    FreeAndNil(Reg);
  end;

end;

{------------------------------------------------------------------------------}

procedure UninstallVNC(PC : String; RemoveFiles : Boolean; CallBack : TVNCStatusCallBack);
var
  reg : TRegistry;
  rDir : String;
begin

  if Assigned(CallBack) then
    Callback('Starting VNC Uninstall');
    
  //stop and delete the service.
  ServiceStop('\\' + PC, 'ISUVNC');

  if ujServices.ServiceExists('\\'+ PC, 'ISUVNC') then
    ServiceDelete('\\'+ PC, 'ISUVNC');

  //now remove registry settings
  Reg := TRegistry.Create;
  try

    Reg.RootKey := HKEY_LOCAL_MACHINE;
    if Reg.RegistryConnect('\\' + PC) then
    begin
      Reg.DeleteKey('SOFTWARE\ORL\');
      Reg.DeleteKey('SOFTWARE\UltraVNC\');
    end;
    
  finally
    FreeAndNil(Reg);
  end;

  if RemoveFiles then
  begin
    if Assigned(CallBack) then
      Callback('Removing VNC Files');

    rDir := Format(VNCREMOTEPATH, [PC]);

    //delete the 2 VNC files from the remote PC
    SysUtils.DeleteFile(rDir + 'WinVNC.exe');

    //VNC hooks can be annoying and not want to delete, in this case rename the file and then delete it
    if not SysUtils.DeleteFile(rDir + 'VNCHooks.dll') then
    begin
      //unable to delete the hooks try renaming and then deleting..
      if RenameFile(rDir + 'VNCHooks.dll', rDir + 'DELETEME.OLD') then
        SysUtils.DeleteFile(rDir + 'DELETEME.OLD');
    end;
  end;

  If Assigned(CallBack) then
    CallBack('Finished Uninstalling VNC Server');

end;

{------------------------------------------------------------------------------}

end.
