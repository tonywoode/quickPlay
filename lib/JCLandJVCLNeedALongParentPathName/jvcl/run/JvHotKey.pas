{-----------------------------------------------------------------------------
The contents of this file are subject to the Mozilla Public License
Version 1.1 (the "License"); you may not use this file except in compliance
with the License. You may obtain a copy of the License at
http://www.mozilla.org/MPL/MPL-1.1.html

Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either expressed or implied. See the License for
the specific language governing rights and limitations under the License.

The Original Code is: JvHotKey.PAS, released on 2001-02-28.

The Initial Developer of the Original Code is SÈbastien Buysse [sbuysse att buypin dott com]
Portions created by SÈbastien Buysse are Copyright (C) 2001 SÈbastien Buysse.
All Rights Reserved.

Contributor(s): Michael Beck [mbeck att bigfoot dott com].

You may retrieve the latest version of this file at the Project JEDI's JVCL home page,
located at http://jvcl.delphi-jedi.org

Known Issues:
-----------------------------------------------------------------------------}
// $Id: JvHotKey.pas 12461 2009-08-14 17:21:33Z obones $

unit JvHotKey;

{$I jvcl.inc}
{$I vclonly.inc}

interface

uses
  Controls,
  {$IFDEF UNITVERSIONING}
  JclUnitVersioning,
  {$ENDIF UNITVERSIONING}
  JvExComCtrls;

type
  TJvHotKey = class(TJvExHotKey)
  published
    property BevelEdges;
    property BevelInner;
    property BevelKind default bkNone;
    property BevelOuter;
    property HintColor;
    property OnMouseEnter;
    property OnMouseLeave;
    property OnParentColorChange;
    property Color;
    property Font;
    property ParentFont;
    property ParentColor;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyUp;
    property OnClick;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnStartDrag;
    property OnResize;
  end;

{$IFDEF UNITVERSIONING}
const
  UnitVersioning: TUnitVersionInfo = (
    RCSfile: '$URL: https://jvcl.svn.sourceforge.net/svnroot/jvcl/tags/JVCL3_39/run/JvHotKey.pas $';
    Revision: '$Revision: 12461 $';
    Date: '$Date: 2009-08-14 19:21:33 +0200 (ven., 14 ao√ªt 2009) $';
    LogPath: 'JVCL\run'
  );
{$ENDIF UNITVERSIONING}

implementation


{$IFDEF UNITVERSIONING}
initialization
  RegisterUnitVersion(HInstance, UnitVersioning);

finalization
  UnregisterUnitVersion(HInstance);
{$ENDIF UNITVERSIONING}

end.
