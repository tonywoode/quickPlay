unit ujAlcohol;

interface

uses SysUtils, Classes, Windows;

procedure AvailableImages(var inStrs : TStrings);
procedure MountImage(Img : TFileName; onDrive : Char);
Procedure UnMountImg(OnDrive : Char);

implementation

Uses JCLShell, Registry;

{---------------------------------------------------------------------------}

procedure AvailableImages(var inStrs : TStrings);
var
  RegName, RegLoc : TRegistry;
  i : Integer;
  TmpStrs : TStrings;
begin

  //gets all available images in alcohol from the registry.
  // they are stored in the registry in a weird way, one key has a name and a number
  // a different key has the image location and they are matched by number.

  RegName := TRegistry.Create;
  try
    RegLoc := TRegistry.Create;

    RegName.RootKey := HKEY_CURRENT_USER;
    RegLoc.RootKey := HKEY_CURRENT_USER;
    
    if (RegName.OpenKey('Software\Alcohol Soft\Alcohol 52%\Images', false)) and
       (RegLoc.OpenKey('Software\Alcohol Soft\Alcohol 52%\Images\Location', False)) then
    begin

      TmpStrs := TStringList.Create;
      try
        RegName.GetKeyNames(TmpStrs);

        //get rid of the 'count' registry entry, we dont need it.
        TmpStrs.Delete(TmpStrs.IndexOf('Count'));

        for i := 0 to TmpStrs.Count-1 do
        begin
          inStrs.Add( Format('%s=%s', [RegName.ReadString(TmpStrs[i]), RegLoc.ReadString(Tmpstrs[i])]) );
        end;

      finally
        FreeAndNil(TmpStrs);
      end;

      RegName.CloseKey;
      RegLoc.CloseKey;

    end;

  finally
    FreeAndNil(RegLoc);
    FreeAndNil(RegName);
  end;
end;

{---------------------------------------------------------------------------}

procedure MountImage(Img : TFileName; onDrive : Char);
var
  App, Param : String;
begin
  If FileExists(Img) then
  begin
    App := 'C:\Program Files\Alcohol Soft\Alcohol 52\axcmd.exe';
    if FileExists(App) then
    begin
      Param := Format('%s: /M:%s', [onDrive, Img]);
      JCLShell.ShellExecEx(App, Param, '', SW_HIDE);
    end
    else
      Raise Exception.Create('Unable to find AxCMD.exe');
  end
  else
    Raise Exception.Create('Image File does not exist');
end;

{---------------------------------------------------------------------------}

Procedure UnMountImg(OnDrive : Char);
var
  App, Param : String;
begin
  App := 'C:\Program Files\Alcohol Soft\Alcohol 52\axcmd.exe';
  if FileExists(App) then
  begin
    Param := Format('%s: /U', [onDrive]);
    JCLShell.ShellExecEx(App, Param, '', SW_HIDE);
  end
  else
    Raise Exception.Create('Unable to find AxCMD.exe');
end;

{---------------------------------------------------------------------------}

end.
