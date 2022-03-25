{-----------------------------------------------------------------------------
The contents of this file are subject to the Mozilla Public License
Version 1.1 (the "License"); you may not use this file except in compliance
with the License. You may obtain a copy of the License at
http://www.mozilla.org/MPL/MPL-1.1.html

Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either expressed or implied. See the License for
the specific language governing rights and limitations under the License.

The Original Code is: JvDBActionsEngineDatasetDoa.Pas, released on 2004-12-30.

The Initial Developer of the Original Code is Jens Fudickar [jens dott fudicker  att oratool dott de]
Portions created by Jens Fudickar are Copyright (C) 2002 Jens Fudickar.
All Rights Reserved.

Contributor(s): -

You may retrieve the latest version of this file at the Project JEDI's JVCL home page,
located at http://jvcl.delphi-jedi.org

Known Issues:
-----------------------------------------------------------------------------}
// $Id: JvDBActionsEngineDatasetDoa.pas 12461 2009-08-14 17:21:33Z obones $

unit JvDBActionsEngineDatasetDoa;

{$I jvcl.inc}

interface

uses
  {$IFDEF UNITVERSIONING}
  JclUnitVersioning,
  {$ENDIF UNITVERSIONING}
  Classes, DB,
  JvDBActionsEngine;

{$IFDEF USE_3RDPARTY_DOA}
type
  TJvDatabaseActionDoaDatasetEngine = class(TJvDatabaseActionBaseDatasetEngine)
  public
    function GetSQL(AActionComponent : TComponent): string; override;
    function SupportsComponent(AActionComponent : TComponent): Boolean; override;
    function SupportsGetSQL(AActionComponent : TComponent): Boolean; override;
  end;
{$ENDIF USE_3RDPARTY_DOA}

{$IFDEF UNITVERSIONING}
const
  UnitVersioning: TUnitVersionInfo = (
    RCSfile: '$URL: https://jvcl.svn.sourceforge.net/svnroot/jvcl/tags/JVCL3_39/run/JvDBActionsEngineDatasetDoa.pas $';
    Revision: '$Revision: 12461 $';
    Date: '$Date: 2009-08-14 19:21:33 +0200 (ven., 14 août 2009) $';
    LogPath: 'JVCL\run'
    );
{$ENDIF UNITVERSIONING}

implementation

{$IFDEF USE_3RDPARTY_DOA}
uses
  OracleData;
{$ENDIF USE_3RDPARTY_DOA}

{$IFDEF USE_3RDPARTY_DOA}

function TJvDatabaseActionDoaDatasetEngine.GetSQL(AActionComponent :
    TComponent): string;
begin
  Result := TOracleDataset(AActionComponent).SQL.Text;
end;

function TJvDatabaseActionDoaDatasetEngine.SupportsComponent(AActionComponent :
    TComponent): Boolean;
begin
  Result := (AActionComponent is TOracleDataset);
end;

function TJvDatabaseActionDoaDatasetEngine.SupportsGetSQL(AActionComponent :
    TComponent): Boolean;
begin
  Result := True;
end;

{$ENDIF USE_3RDPARTY_DOA}

procedure InitActionEngineList;
begin
  {$IFDEF USE_3RDPARTY_DOA}
  RegisterDatabaseActionEngine(TJvDatabaseActionDoaDatasetEngine);
  {$ENDIF USE_3RDPARTY_DOA}
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
