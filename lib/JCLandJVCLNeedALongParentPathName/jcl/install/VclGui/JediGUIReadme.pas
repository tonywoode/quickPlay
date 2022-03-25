{**************************************************************************************************}
{                                                                                                  }
{ Project JEDI Code Library (JCL) extension                                                        }
{                                                                                                  }
{ The contents of this file are subject to the Mozilla Public License Version 1.1 (the "License"); }
{ you may not use this file except in compliance with the License. You may obtain a copy of the    }
{ License at http://www.mozilla.org/MPL/                                                           }
{                                                                                                  }
{ Software distributed under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF   }
{ ANY KIND, either express or implied. See the License for the specific language governing rights  }
{ and limitations under the License.                                                               }
{                                                                                                  }
{ The Original Code is JediGUIReadme.pas.                                                          }
{                                                                                                  }
{ The Initial Developer of the Original Code is Florent Ouchet. Portions created by Florent Ouchet }
{ are Copyright (C) of Florent Ouchet. All Rights Reserved.                                        }
{                                                                                                  }
{ Contributors:                                                                                    }
{                                                                                                  }
{**************************************************************************************************}
{                                                                                                  }
{ Last modified: $Date:: 2009-08-21 17:40:34 +0200 (ven., 21 août 2009)                         $ }
{ Revision:      $Rev:: 2954                                                                     $ }
{ Author:        $Author:: outchy                                                                $ }
{                                                                                                  }
{**************************************************************************************************}

unit JediGUIReadme;

{$I jcl.inc}
{$I crossplatform.inc}

interface

uses
  Windows, Messages,
  SysUtils, Classes,
  Graphics, Controls, Forms, Dialogs, StdCtrls, ComCtrls,
  JediInstall;

type
  TReadmeFrame = class(TFrame, IJediReadmePage, IJediPage)
    ReadmePane: TRichEdit;
    procedure ReadmePaneDblClick(Sender: TObject);
  private
    FReadmeFileName: string;
  public
    // IJediPage
    function GetCaption: string;
    procedure SetCaption(const Value: string);
    function GetHintAtPos(ScreenX, ScreenY: Integer): string;
    procedure Show;
    // IJediReadmePage
    procedure SetReadmeFileName(const Value: string);
    function GetReadmeFileName: string;

    property ReadmeFileName: string read GetReadmeFileName write SetReadmeFileName;
  end;

implementation

{$R *.dfm}

uses
  JclShell;

function TReadmeFrame.GetCaption: string;
begin
  Result := (Parent as TTabSheet).Caption;
end;

function TReadmeFrame.GetReadmeFileName: string;
begin
  Result := FReadmeFileName;
end;

procedure TReadmeFrame.ReadmePaneDblClick(Sender: TObject);
begin
  { TODO: implement for Unix }
  ShellExecEx(ReadmeFileName);
end;

procedure TReadmeFrame.SetCaption(const Value: string);
begin
  (Parent as TTabSheet).Caption := Value;
end;

function TReadmeFrame.GetHintAtPos(ScreenX, ScreenY: Integer): string;
begin
  Result := '';
end;

procedure TReadmeFrame.SetReadmeFileName(const Value: string);
begin
  FReadmeFileName := Value;
  if FileExists(Value) then
    ReadmePane.Lines.LoadFromFile(Value);
end;

procedure TReadmeFrame.Show;
var
  ATabSheet: TTabSheet;
begin
  ATabSheet := Parent as TTabSheet;
  (ATabSheet.Parent as TPageControl).ActivePage := ATabSheet;
end;

end.
