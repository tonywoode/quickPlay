{-----------------------------------------------------------------------------
The contents of this file are subject to the Mozilla Public License
Version 1.1 (the "License"); you may not use this file except in compliance
with the License. You may obtain a copy of the License at
http://www.mozilla.org/MPL/MPL-1.1.html

Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either expressed or implied. See the License for
the specific language governing rights and limitations under the License.

The Original Code is: JvDBPasswordDialogOdac.pas, released on 2006-07-21.

The Initial Developer of the Original Code is Jens Fudickar
All Rights Reserved.

Contributor(s):

You may retrieve the latest version of this file at the Project JEDI's JVCL home page,
located at http://jvcl.delphi-jedi.org

Known Issues:
-----------------------------------------------------------------------------}
// $Id: JvDBPasswordDialogOdac.pas 12461 2009-08-14 17:21:33Z obones $

unit JvDBPasswordDialogOdac;

{$I jvcl.inc}

interface

uses
  {$IFDEF UNITVERSIONING}
  JclUnitVersioning,
  {$ENDIF UNITVERSIONING}
  Classes, Menus,
  Ora, dbaccess,
  JvBaseDBPasswordDialog;

type
  TJvDBOdacPasswordDialog = class(TJvBaseDBPasswordDialog)
  private
    function GetSession: TCustomDAConnection;
    procedure SetSession(const Value: TCustomDAConnection); reintroduce;
  protected
    function ChangePasswordInSession(NewPassword: string): Boolean; override;
    function GetPasswordFromSession: string; override;
  public
  published
    property Session: TCustomDAConnection read GetSession write SetSession;
  end;

{$IFDEF UNITVERSIONING}
const
  UnitVersioning: TUnitVersionInfo = (
    RCSfile: '$URL: https://jvcl.svn.sourceforge.net/svnroot/jvcl/tags/JVCL3_39/run/JvDBPasswordDialogOdac.pas $';
    Revision: '$Revision: 12461 $';
    Date: '$Date: 2009-08-14 19:21:33 +0200 (ven., 14 août 2009) $';
    LogPath: 'JVCL\run'
    );
{$ENDIF UNITVERSIONING}

implementation

uses
  SysUtils, ExtCtrls, ComCtrls, StdCtrls, Types;

function TJvDBOdacPasswordDialog.ChangePasswordInSession(NewPassword: string): Boolean;
begin
  Result := False;
  if Assigned(Session) then
    begin
      if Session is TOraSession then
        TOraSession(Session).ChangePassword(NewPassword)
      else
        Session.ExecSQL('ALTER USER ' + Session.Username + ' IDENTIFIED BY ' + NewPassword, []);
      Session.Password := NewPassword;
      Result := True;
    end;
end;

function TJvDBOdacPasswordDialog.GetPasswordFromSession: string;
begin
   Result := Session.Password;
end;

function TJvDBOdacPasswordDialog.GetSession: TCustomDAConnection;
begin
  if (inherited Session) is TCustomDAConnection then
    Result := TCustomDAConnection(inherited Session)
  else
    Result := nil;
end;

procedure TJvDBOdacPasswordDialog.SetSession(const Value: TCustomDAConnection);
begin
  inherited SetSession(Value);
end;

{$IFDEF UNITVERSIONING}
initialization
  RegisterUnitVersion(HInstance, UnitVersioning);

finalization
  UnregisterUnitVersion(HInstance);
{$ENDIF UNITVERSIONING}

end.