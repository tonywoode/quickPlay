{**************************************************************************************************}
{                                                                                                  }
{ Project JEDI Code Library (JCL)                                                                  }
{                                                                                                  }
{ The contents of this file are subject to the Mozilla Public License Version 1.1 (the "License"); }
{ you may not use this file except in compliance with the License. You may obtain a copy of the    }
{ License at http://www.mozilla.org/MPL/                                                           }
{                                                                                                  }
{ Software distributed under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF   }
{ ANY KIND, either express or implied. See the License for the specific language governing rights  }
{ and limitations under the License.                                                               }
{                                                                                                  }
{ The Original Code is JclOtaExcDlgIgnoreFrame.pas.                                                }
{                                                                                                  }
{ The Initial Developer of the Original Code is Florent Ouchet                                     }
{         <outchy att users dott sourceforge dott net>                                             }
{ Portions created by Florent Ouchet are Copyright (C) of Florent Ouchet. All rights reserved.     }
{                                                                                                  }
{ Contributors:                                                                                    }
{                                                                                                  }
{**************************************************************************************************}
{                                                                                                  }
{ Last modified: $Date:: 2009-09-14 18:00:50 +0200 (lun., 14 sept. 2009)                         $ }
{ Revision:      $Rev:: 3012                                                                     $ }
{ Author:        $Author:: outchy                                                                $ }
{                                                                                                  }
{**************************************************************************************************}

unit JclOtaExcDlgIgnoreFrame;

interface

{$I jcl.inc}

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls,
  {$IFDEF UNITVERSIONING}
  JclUnitVersioning,
  {$ENDIF UNITVERSIONING}
  JclOtaExcDlgRepository, JclOtaWizardFrame;

type
  TJclOtaExcDlgIgnorePage = class(TJclWizardFrame)
    CheckBoxTraceAllExceptions: TCheckBox;
    CheckBoxTraceEAbort: TCheckBox;
    LabelIgnoredExceptions: TLabel;
    MemoIgnoredExceptions: TMemo;
    procedure CheckBoxTraceAllExceptionsClick(Sender: TObject);
  private
    FParams: TJclOtaExcDlgParams;
    procedure UpdateControls;
  public
    constructor Create(AOwner: TComponent; AParams: TJclOtaExcDlgParams); reintroduce;

    procedure PageActivated(Direction: TJclWizardDirection); override;
    procedure PageDesactivated(Direction: TJclWizardDirection); override;

    property Params: TJclOtaExcDlgParams read FParams write FParams;
  end;

{$IFDEF UNITVERSIONING}
const
  UnitVersioning: TUnitVersionInfo = (
    RCSfile: '$URL: https://jcl.svn.sourceforge.net/svnroot/jcl/tags/JCL-2.1-Build3536/jcl/experts/repository/JclOtaExcDlgIgnoreFrame.pas $';
    Revision: '$Revision: 3012 $';
    Date: '$Date: 2009-09-14 18:00:50 +0200 (lun., 14 sept. 2009) $';
    LogPath: 'JCL\experts\repository';
    Extra: '';
    Data: nil
    );
{$ENDIF UNITVERSIONING}

implementation

{$R *.dfm}

uses
  JclOtaResources;

//=== { TJclOtaExcDlgIgnorePage } ============================================

procedure TJclOtaExcDlgIgnorePage.CheckBoxTraceAllExceptionsClick(
  Sender: TObject);
begin
  UpdateControls;
end;

constructor TJclOtaExcDlgIgnorePage.Create(AOwner: TComponent;
  AParams: TJclOtaExcDlgParams);
begin
  FParams := AParams;
  inherited Create(AOwner);

  Caption := LoadResString(@RsExcDlgIgnoreOptions);
  CheckBoxTraceAllExceptions.Caption := LoadResString(@RsTraceAllExceptions);
  CheckBoxTraceEAbort.Caption := LoadResString(@RsTraceEAbort);
  LabelIgnoredExceptions.Caption := LoadResString(@RsIgnoredExceptions);
end;

procedure TJclOtaExcDlgIgnorePage.PageActivated(Direction: TJclWizardDirection);
begin
  inherited PageActivated(Direction);

  CheckBoxTraceAllExceptions.Checked := Params.TraceAllExceptions;
  CheckBoxTraceEAbort.Checked := Params.TraceEAbort;
  MemoIgnoredExceptions.Lines.Assign(Params.IgnoredExceptions);
  UpdateControls;
end;

procedure TJclOtaExcDlgIgnorePage.PageDesactivated(
  Direction: TJclWizardDirection);
begin
  inherited PageDesactivated(Direction);

  Params.TraceAllExceptions := CheckBoxTraceAllExceptions.Checked;
  Params.TraceEAbort := CheckBoxTraceEAbort.Checked;
  Params.IgnoredExceptions.Assign(MemoIgnoredExceptions.Lines);
end;

procedure TJclOtaExcDlgIgnorePage.UpdateControls;
begin
  if CheckBoxTraceAllExceptions.Checked then
  begin
    CheckBoxTraceEAbort.Enabled := False;
    MemoIgnoredExceptions.Enabled := False;
    LabelIgnoredExceptions.Enabled := False;
    MemoIgnoredExceptions.ParentColor := True;
  end
  else
  begin
    CheckBoxTraceEAbort.Enabled := True;
    MemoIgnoredExceptions.Enabled := True;
    LabelIgnoredExceptions.Enabled := True;
    MemoIgnoredExceptions.Color := clWindow;
  end;
end;

{$IFDEF UNITVERSIONING}
initialization
  RegisterUnitVersion(HInstance, UnitVersioning);

finalization
  UnregisterUnitVersion(HInstance);
{$ENDIF UNITVERSIONING}

end.
