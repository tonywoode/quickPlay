{-----------------------------------------------------------------------------
The contents of this file are subject to the Mozilla Public License
Version 1.1 (the "License"); you may not use this file except in compliance
with the License. You may obtain a copy of the License at
http://www.mozilla.org/MPL/MPL-1.1.html

Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either expressed or implied. See the License for
the specific language governing rights and limitations under the License.

The Original Code is: JvDBActionsEngineControlCxGrid.Pas, released on 2004-12-30.

The Initial Developer of the Original Code is Jens Fudickar [jens dott fudicker  att oratool dott de]
Portions created by Jens Fudickar are Copyright (C) 2002 Jens Fudickar.
All Rights Reserved.

Contributor(s): -

You may retrieve the latest version of this file at the Project JEDI's JVCL home page,
located at http://jvcl.delphi-jedi.org

Known Issues:
-----------------------------------------------------------------------------}
// $Id: JvControlActionsEngineCxTreeList.pas 12461 2009-08-14 17:21:33Z obones $

unit JvControlActionsEngineCxTreeList;

{$I jvcl.inc}

interface

uses
  {$IFDEF UNITVERSIONING}
  JclUnitVersioning,
  {$ENDIF UNITVERSIONING}
  Forms, Controls, Classes, DB,
  {$IFDEF USE_3RDPARTY_DEVEXPRESS_CXTREELIST}
  cxTL,
  {$ENDIF USE_3RDPARTY_DEVEXPRESS_CXTREELIST}
  JvControlActionsEngine;

{$IFDEF USE_3RDPARTY_DEVEXPRESS_CXTREELIST}
type
  TJvControlActioncxGridEngine = class(TJvControlActionEngine)
  private
  protected
    function GetSupportedOperations: TJvControlActionOperations; override;
    function GetTreeList(AActionComponent: TComponent): TcxCustomTreeList;
  public
    function ExecuteOperation(const aOperation: TJvControlActionOperation; const
        aActionControl: TControl): Boolean; override;
    function SupportsComponent(aActionComponent: TComponent): Boolean; override;
  end;

{$ENDIF USE_3RDPARTY_DEVEXPRESS_CXTREELIST}

{$IFDEF UNITVERSIONING}
const
  UnitVersioning: TUnitVersionInfo = (
    RCSfile: '$URL: https://jvcl.svn.sourceforge.net/svnroot/jvcl/tags/JVCL3_39/run/JvControlActionsEngineCxTreeList.pas $';
    Revision: '$Revision: 12461 $';
    Date: '$Date: 2009-08-14 19:21:33 +0200 (ven., 14 août 2009) $';
    LogPath: 'JVCL\run'
    );
{$ENDIF UNITVERSIONING}

implementation

uses
  {$IFDEF USE_3RDPARTY_DEVEXPRESS_CXTREELIST}
  {$ENDIF USE_3RDPARTY_DEVEXPRESS_CXTREELIST}
  Variants, SysUtils, Grids;

//=== { TJvDatabaseActionDevExpCxGridControlEngine } =========================

{$IFDEF USE_3RDPARTY_DEVEXPRESS_CXTREELIST}

function TJvControlActioncxGridEngine.ExecuteOperation(const aOperation:
    TJvControlActionOperation; const aActionControl: TControl): Boolean;
begin
  Result := false;
  if Assigned(GetTreeList(aActionControl)) then
    Case aOperation of
      caoCollapse : GetTreeList(aActionControl).FullCollapse;
      caoExpand : GetTreeList(aActionControl).FullExpand;
      caoOptimizeColumns : GetTreeList(aActionControl).ApplyBestFit;
    End;
end;

function TJvControlActioncxGridEngine.GetSupportedOperations:
    TJvControlActionOperations;
begin
  Result := [caoCollapse, caoExpand, caoOptimizeColumns];
end;

function TJvControlActioncxGridEngine.GetTreeList(AActionComponent:
    TComponent): TcxCustomTreeList;
begin
  if Assigned(AActionComponent) then
    if AActionComponent is TcxCustomTreeList then
      Result := TcxCustomTreeList(AActionComponent)
    else
      Result := nil
  else
    Result := nil;
end;

function TJvControlActioncxGridEngine.SupportsComponent(aActionComponent:
    TComponent): Boolean;
begin
  Result := Assigned(GetTreeList(AActionComponent));
end;

{$ENDIF USE_3RDPARTY_DEVEXPRESS_CXTREELIST}

procedure InitActionEngineList;
begin
  {$IFDEF USE_3RDPARTY_DEVEXPRESS_CXTREELIST}
  RegisterControlActionEngine(TJvControlActioncxGridEngine);
  {$ENDIF USE_3RDPARTY_DEVEXPRESS_CXTREELIST}
end;


initialization
  {$IFDEF UNITVERSIONING}
  RegisterUnitVersion(HInstance, UnitVersioning);
  {$ENDIF UNITVERSIONING}
  InitActionEngineList;

finalization
  {$IFDEF UNITVERSIONING}
  UnregisterUnitVersion(HInstance);
  {$ENDIF UNITVERSIONING}

end.
