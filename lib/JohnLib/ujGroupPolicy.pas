{
This unit deals with managing - and removing - group policy on PCs.
Group Policy is basically a couple of settings in the Registry which are
read when explorer starts up and applied.  This works to our benefit as its
possible to erase these settings and then kill and reload explorer and as
these settings arent in the registry anymore no group policy is applied.

Originally I had thought this process may be able to run remotely but there is
one problem with this - the registry settings can be removed no problem but
killing and restarting explorer is a problem.  If you start explorer remotely
it will be running with YOUR credentials and NOT the users.  This sounds like
a world of hurt... so I dont recommend it at all.

Therefore this unit should only be used in applications that are run
ON THE CLIENT

One more point of notice, the group policy registry key can only be modified
by an administrator so you NEED admin rights to do this.  If a user is not
an administrator then they cant remove group policy.  Client side applications
should allow admin account details to be entered.

}


unit ujGroupPolicy;

interface

uses SysUtils, Windows;

Procedure LockPolicyKeys(onPC : String; UserRootKey : String);
procedure RestartExplorer();
Procedure RemoveUserPolicyFromRegistry(OnPC : String; UserKey : String);
Procedure UnLockPolicyKeys(onPC : String; UserRootKey : String);

implementation

Uses Registry, unitNTSecurity,
     JCLShell, JCLStrings,
     ujUtilities, ujProcesses, ujWindowsMisc;

{-----------------------------------------------------------------------------}


{-----------------------------------------------------------------------------}

procedure RestartExplorer();
begin
  ujProcesses.KillApplication('Explorer.exe');
  if not ujProcesses.IsApplicationRunning('explorer.exe', False) then
    JCLShell.ShellExecEx('Explorer.exe');
end;

{-----------------------------------------------------------------------------}

Procedure RemoveUserPolicyFromRegistry(OnPC : String; UserKey : String);
var
  Reg : TRegistry;
  ThePC : String;
begin
  Reg := TRegistry.Create();
  try

    ThePC := onPC;
    if ThePC <> '' then
    begin
      JCLStrings.StrReplace(ThePC, '\\', '', [rfReplaceAll]);
      ThePC := '\\' + ThePC;
    end;

    Reg.RootKey := HKEY_USERS;
    if Reg.RegistryConnect(ThePC) then
    begin

      //Delete all polices from Users software\policies folder.
      if Reg.OpenKey(Format('%s\Software\Policies', [UserKey]), False) then
      begin
        ujUtilities.EraseRegistrySubKeys(Reg);
        Reg.CloseKey;
      end;

      //delete all policies from users ms\windows\cv\policies
      if Reg.OpenKey(Format('%s\Software\Microsoft\Windows\CurrentVersion\Policies', [UserKey]), False) then
      Begin
        ujUtilities.EraseRegistrySubKeys(Reg);
        Reg.CloseKey;
      end;

      //if you dont delete the following key you can restore group policy?
      Reg.DeleteKey(Format('%s\Software\Microsoft\Windows\CurrentVersion\Group Policy\History', [UserKey]));

    end;
  finally
    FreeAndNil(Reg);
  end;
end;

{-----------------------------------------------------------------------------}

Procedure LockPolicyKeys(onPC : String; UserRootKey : String);

    procedure LockKey(Key : HKEY);
    var
      f : TNTRegistryObject;
      acl, new : TAccessControlList;
      i : Integer;
    begin
      f := TNTRegistryObject.Create (Key);
      try
        acl := TAccessControlList.Create;
        New := TAccessControlList.Create;
        f.GetDiscretionaryAccessList(acl);

        for i := 0 to ACL.ElementCount - 1 do
        begin
          New.AddElement(TAccessControlElement.Create(ACL.Element[i].Name,
            ACL.Element[i].Type_, OBJECT_INHERIT_ACE or CONTAINER_INHERIT_ACE, GENERIC_READ));
        end;

        f.SetOwner('Administrators');
        f.SetDiscretionaryAccessList(New);
      finally
        FreeAndNil(New);
        FreeAndNil(acl);
        FreeAndNil(f);
      end;
    end;
var
  myKey : HKey;
begin
  if (RegOpenKey(HKEY_USERS, PChar(UserRootKey + '\SOFTWARE\Policies'), myKey) = ERROR_SUCCESS) then
  begin
    LockKey(myKey);
    RegCloseKey(myKey);
  end;
  
  if (RegOpenKey(HKEY_USERS, PChar(UserRootKey + '\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies'), myKey) = ERROR_SUCCESS) then
  begin
    LockKey(myKey);
    RegCloseKey(myKey);
  end;

end;

{-----------------------------------------------------------------------------}

Procedure UnLockPolicyKeys(onPC : String; UserRootKey : String);

    procedure UnLockKey(Key : HKEY);
    var
      f : TNTRegistryObject;
      acl, new : TAccessControlList;
      i : Integer;
      Perm : Cardinal;
    begin
      f := TNTRegistryObject.Create (Key);
      try
        acl := TAccessControlList.Create;
        New := TAccessControlList.Create;
        f.GetDiscretionaryAccessList(acl);

        for i := 0 to ACL.ElementCount - 1 do
        begin
          if (JCLSTrings.StrCompare('BUILTIN\Administrators', ACL.Element[i].Name)=0) or
             (JCLSTrings.StrCompare('NT AUTHORITY\SYSTEM', ACL.Element[i].Name)=0) then
            //change to full control
            Perm := GENERIC_ALL
          else
            Perm := GENERIC_READ;

          New.AddElement(TAccessControlElement.Create(ACL.Element[i].Name,
              ACL.Element[i].Type_, OBJECT_INHERIT_ACE or CONTAINER_INHERIT_ACE, Perm));
        end;

        f.SetDiscretionaryAccessList(New);
      finally
        FreeAndNil(New);
        FreeAndNil(acl);
        FreeAndNil(f);
      end;
    end;
var
  myKey : HKey;
begin
  if (RegOpenKey(HKEY_USERS, PChar(UserRootKey + '\SOFTWARE\Policies'), myKey) = ERROR_SUCCESS) then
  begin
    UnLockKey(myKey);
    RegCloseKey(myKey);
  end;
  
  if (RegOpenKey(HKEY_USERS, PChar(UserRootKey + '\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies'), myKey) = ERROR_SUCCESS) then
  begin
    UnLockKey(myKey);
    RegCloseKey(myKey);
  end;

end;

{-----------------------------------------------------------------------------}

end.
