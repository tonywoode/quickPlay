{-----------------------------------------------------------------------------
The contents of this file are subject to the Mozilla Public License
Version 1.1 (the "License"); you may not use this file except in compliance
with the License. You may obtain a copy of the License at
http://www.mozilla.org/MPL/MPL-1.1.html

Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either expressed or implied. See the License for
the specific language governing rights and limitations under the License.

The Original Code is: JvDBActions.Pas, released on 2007-03-11.

The Initial Developer of the Original Code is Jens Fudickar [jens dott fudicker  att oratool dott de]
Portions created by Jens Fudickar are Copyright (C) 2002 Jens Fudickar.
All Rights Reserved.

Contributor(s): -

You may retrieve the latest version of this file at the Project JEDI's JVCL home page,
located at http://jvcl.delphi-jedi.org

Known Issues:
-----------------------------------------------------------------------------}
// $Id: JvControlActions.pas 12461 2009-08-14 17:21:33Z obones $

unit JvControlActions;

{$I jvcl.inc}

interface

uses
  {$IFDEF UNITVERSIONING}
  JclUnitVersioning,
  {$ENDIF UNITVERSIONING}
  {$IFDEF MSWINDOWS}
  Windows, ActnList, ImgList, Graphics,
  {$ENDIF MSWINDOWS}
  {$IFDEF UNIX}
  QActnList, QWindows, QImgList, QGraphics,
  {$ENDIF UNIX}
  Forms, Controls, Classes, JvActionsEngine, JvControlActionsEngine;


type

  TJvControlActionExecuteEvent = procedure(Sender: TObject; const aOperation: TJvControlActionOperation; const
        aActionControl: TControl) of object;

  TJvControlActionCheckEnabledEvent = procedure(aActionControl : TControl;
      aControlOperation: TJvControlActionOperation; var aEnabled : Boolean)
      of object;

  TJvControlBaseAction = class(TJvActionEngineBaseAction)
  private
    FControlOperation: TJvControlActionOperation;
    FOnCheckEnabled: TJvControlActionCheckEnabledEvent;
    FOnExecute: TJvControlActionExecuteEvent;
    FAfterExecute: TJvControlActionExecuteEvent;
    function GetActionControl: TControl;
    function GetControlEngine: TJvControlActionEngine;
    procedure SetActionControl(const Value: TControl); virtual;
    procedure SetControlOperation(const Value: TJvControlActionOperation);
  protected
    procedure CheckEnabled(var AEnabled: Boolean); override;
    function GetEngineList: TJvActionEngineList; override;
    procedure SetActionComponent(const Value: TComponent); override;
    property ControlEngine: TJvControlActionEngine read GetControlEngine;
  public
    constructor Create(AOwner: TComponent); override;
    function Execute: Boolean; override;
    procedure UpdateTarget(Target: TObject); override;
    function HandlesTarget(Target: TObject): Boolean; override;
    procedure ExecuteTarget(Target: TObject); override;
    property ActionControl: TControl read GetActionControl write SetActionControl;
    property ControlOperation: TJvControlActionOperation read FControlOperation
        write SetControlOperation;
  published
    property OnCheckEnabled: TJvControlActionCheckEnabledEvent read FOnCheckEnabled
        write FOnCheckEnabled;                          
    property OnExecute: TJvControlActionExecuteEvent read FOnExecute write
        FOnExecute;
    property AfterExecute: TJvControlActionExecuteEvent read FAfterExecute write
        FAfterExecute;
  end;

  TJvControlCommonAction = class(TJvControlBaseAction)
  published
    property ControlOperation;
  end;

  TJvControlCollapseAction = class (TJvControlBaseAction)
  public
    constructor Create(AOwner: TComponent); override;
  published
  end;

type
  TJvControlExpandAction = class(TJvControlBaseAction)
  public
    constructor Create(AOwner: TComponent); override;
  published
  end;

type
  TJvControlExportAction = class(TJvControlBaseAction)
  public
    constructor Create(AOwner: TComponent); override;
  published
  end;

type
  TJvControlOptimizeColumnsAction = class(TJvControlBaseAction)
  public
    constructor Create(AOwner: TComponent); override;
  published
  end;

type
  TJvControlCustomizeColumnsAction = class(TJvControlBaseAction)
  public
    constructor Create(AOwner: TComponent); override;
  published
  end;

type
  TJvControlPrintAction = class(TJvControlBaseAction)
  public
    constructor Create(AOwner: TComponent); override;
  published
  end;

type
  TJvControlCustomizeAction = class(TJvControlBaseAction)
  public
    constructor Create(AOwner: TComponent); override;
  published
  end;


{$IFDEF UNITVERSIONING}
const
  UnitVersioning: TUnitVersionInfo = (
    RCSfile: '$URL: https://jvcl.svn.sourceforge.net/svnroot/jvcl/tags/JVCL3_39/run/JvControlActions.pas $';
    Revision: '$Revision: 12461 $';
    Date: '$Date: 2009-08-14 19:21:33 +0200 (ven., 14 août 2009) $';
    LogPath: 'JVCL\run'
    );
{$ENDIF UNITVERSIONING}

implementation

uses
  SysUtils, Grids, TypInfo, StrUtils, Variants,
  Dialogs, StdCtrls, Clipbrd;

//=== { TJvControlBaseAction } ==============================================

constructor TJvControlBaseAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
end;

procedure TJvControlBaseAction.CheckEnabled(var AEnabled: Boolean);
begin
  if Assigned(fOnCheckEnabled) then
    fOnCheckEnabled (ActionControl, ControlOperation, aEnabled);
end;

function TJvControlBaseAction.Execute: Boolean;
begin
  Result := inherited Execute;
  if Result and Assigned(FAfterExecute) then
    FAfterExecute(Self, ControlOperation, ActionControl)
end;

procedure TJvControlBaseAction.ExecuteTarget(Target: TObject);
begin
  if Assigned(FOnExecute) then
    FOnExecute(Self, ControlOperation, ActionControl)
  else
    if Assigned(ControlEngine) then
      ControlEngine.ExecuteOperation(ControlOperation, ActionControl)
    else                                                  
      inherited ExecuteTarget(Target);
end;

function TJvControlBaseAction.GetActionControl: TControl;
begin
  Result := TControl(ActionComponent);
end;

function TJvControlBaseAction.GetControlEngine: TJvControlActionEngine;
begin
  Result := TJvControlActionEngine(inherited ControlEngine);
end;

function TJvControlBaseAction.GetEngineList: TJvActionEngineList;
begin
  Result := RegisteredControlActionEngineList;
end;

function TJvControlBaseAction.HandlesTarget(Target: TObject): Boolean;
begin
  if Target is TWinControl then
    if TwinControl(Target).Focused then
      Result := inherited HandlesTarget(Target)
    else
      Result := False
  else
    Result := False;
end;

procedure TJvControlBaseAction.SetActionComponent(const Value: TComponent);
begin
  inherited SetActionComponent(Value);
end;

procedure TJvControlBaseAction.SetActionControl(const Value: TControl);
begin
  ActionComponent := Value;
end;

procedure TJvControlBaseAction.SetControlOperation(const Value:
    TJvControlActionOperation);
begin
  if FControlOperation <> Value then
  begin
    FControlOperation := Value;
    DetectControlEngine(ActionComponent);
  end;
end;

procedure TJvControlBaseAction.UpdateTarget(Target: TObject);
begin
  if Assigned(ControlEngine) then
    SetEnabled(True)
  else
    SetEnabled(False);
end;

constructor TJvControlCollapseAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlOperation := caoCollapse;
end;

constructor TJvControlExpandAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlOperation := caoExpand;
end;

constructor TJvControlExportAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlOperation := caoExport;
end;

constructor TJvControlOptimizeColumnsAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlOperation := caoOptimizeColumns;
end;

constructor TJvControlCustomizeColumnsAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlOperation := caoCustomizeColumns;
end;

constructor TJvControlPrintAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlOperation := caoPrint;
end;

constructor TJvControlCustomizeAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlOperation := caoCustomize;
end;



initialization
  {$IFDEF UNITVERSIONING}
  RegisterUnitVersion(HInstance, UnitVersioning);
  {$ENDIF UNITVERSIONING}

finalization
  {$IFDEF UNITVERSIONING}
  UnregisterUnitVersion(HInstance);
  {$ENDIF UNITVERSIONING}

end.