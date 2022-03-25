{-----------------------------------------------------------------------------
The contents of this file are subject to the Mozilla Public License
Version 1.1 (the "License"); you may not use this file except in compliance
with the License. You may obtain a copy of the License at
http://www.mozilla.org/MPL/MPL-1.1.html

Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either expressed or implied. See the License for
the specific language governing rights and limitations under the License.

The Original Code is: JvScrollText.PAS, released on 2001-02-28.

The Initial Developer of the Original Code is S�bastien Buysse [sbuysse att buypin dott com]
Portions created by S�bastien Buysse are Copyright (C) 2001 S�bastien Buysse.
All Rights Reserved.

Contributor(s): Michael Beck [mbeck att bigfoot dott com]
                Michael Freislich [mikef att korbi dott net]
                Gianpiero Caretti [gpcaretti+delphi att gmail dott com]

You may retrieve the latest version of this file at the Project JEDI's JVCL home page,
located at http://jvcl.delphi-jedi.org

Known Issues:
-----------------------------------------------------------------------------}
// $Id: JvScrollText.pas 12576 2009-10-25 17:49:40Z ahuser $

unit JvScrollText;

{$I jvcl.inc}

interface

uses
  {$IFDEF UNITVERSIONING}
  JclUnitVersioning,
  {$ENDIF UNITVERSIONING}
  SysUtils, Classes, Windows, Messages, Graphics, Controls, Forms, StdCtrls,
  JvStaticText, JvTypes, JvImageDrawThread, JvComponent;

type
  TJvScrollTextDirection = (drFromLeft, drFromRight, drFromTop, drFromBottom); // also in JvMoveableBevel, JvAppearingLabel
  TJvScrollText = class(TJvCustomControl)
  private
    FText: TJvStaticText;
    FTimerTag: Integer;
    FActive: Boolean;
    FDelay: Cardinal;
    FPixel: Integer;
    FCurrPos: Integer;
    FSelectable: Boolean;
    FScrollDirection: TJvScrollTextDirection;
    FScrollSaved: Integer;
    FItems: TStringList;
    FDefaultAppHintPause: Cardinal;
    FScroll: TJvImageDrawThread;
    FFont: TFont;
    FStartY: Integer;
    FDown: Boolean;
    FOldMouseMovePt: TPoint;
    FOnScrollEnd: TNotifyEvent;
    function GetItems: TStrings;
    procedure SetItems(const Value: TStrings);
    procedure OnScroll(Sender: TObject);
    procedure SetActive(const Value: Boolean);
    procedure SetDelay(const Value: Cardinal);
    procedure SetPixel(const Value: Integer);
    procedure SetScrollDirection(const Value: TJvScrollTextDirection);
    procedure CalculateText(Sender: TObject);
    function GetAlignment: TAlignment;
    procedure SetAlignment(const Value: TAlignment);
    function GetColor: TColor;
    procedure SetColor(const Value: TColor);
    procedure FontChange(Sender: TObject);
    procedure SetFont(const Value: TFont);
    procedure TextMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure TextMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure TextMouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure TextMouseClick(Sender: TObject);
    procedure TextMouseDblClick(Sender: TObject);
    function GetWordWrap: Boolean;
    procedure SetWordWrap(const Value: Boolean);
    procedure DoScrollEnd;
  protected
    procedure Loaded; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  published
    property Alignment: TAlignment read GetAlignment write SetAlignment;
    property Items: TStrings read GetItems write SetItems;
    property Active: Boolean read FActive write SetActive default False;
    property Delay: Cardinal read FDelay write SetDelay default 50;
    property ScrollPixels: Integer read FPixel write SetPixel default 1;
    property ScrollDirection: TJvScrollTextDirection read FScrollDirection write SetScrollDirection default drFromBottom;
    property BackgroundColor: TColor read GetColor write SetColor;
    property Font: TFont read FFont write SetFont;
    procedure Pause;
    procedure Unpause;
    procedure Reset;
    property Align;
    property ShowHint;
    property ParentShowHint;
    property Height default 150;
    property Width default 200;
    {$IFDEF JVCLThemesEnabled}
    property ParentBackground default True;
    {$ENDIF JVCLThemesEnabled}
    property WordWrap: Boolean read GetWordWrap write SetWordWrap;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnMouseEnter;
    property OnMouseLeave;
    property OnClick;
    property OnDblClick;

    // Triggered when the scroll has reached its end and is about to restart from its source
    property OnScrollEnd: TNotifyEvent read FOnScrollEnd write FOnScrollEnd;
  end;

{$IFDEF UNITVERSIONING}
const
  UnitVersioning: TUnitVersionInfo = (
    RCSfile: '$URL: https://jvcl.svn.sourceforge.net/svnroot/jvcl/tags/JVCL3_39/run/JvScrollText.pas $';
    Revision: '$Revision: 12576 $';
    Date: '$Date: 2009-10-25 18:49:40 +0100 (dim., 25 oct. 2009) $';
    LogPath: 'JVCL\run'
  );
{$ENDIF UNITVERSIONING}

implementation

uses
  JvJVCLUtils, JvThemes, JvResources;

constructor TJvScrollText.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  IncludeThemeStyle(Self, [csParentBackground]);
  Width := 200;
  Height := 150;
  FActive := False;
  FDelay := 50;
  FPixel := 1;
  FCurrPos := 0;
  FSelectable := True;
  FScrollDirection := drFromBottom;
  FItems := TStringList.Create;

  FText := TJvStaticText.Create(Self);
  FText.Parent := Self;
  FText.Width := Width;
  FText.Height := Height;
  FText.BorderStyle := sbsNone;
  FText.TabStop := False;
  FText.Enabled := FSelectable;
  FText.AutoSize := False;
  FText.OnMouseDown := TextMouseDown;
  FText.OnMouseMove := TextMouseMove;
  FText.OnMouseUp := TextMouseUp;
  FText.OnClick := TextMouseClick;
  FText.OnDblClick := TextMouseDblClick;

  FFont := TFont.Create;
  FFont.Assign(FText.Font);
  FFont.OnChange := FontChange;

  FTimerTag := 0;
  FDown := False;
  FDefaultAppHintPause := Application.HintPause;

  if not (csDesigning in ComponentState) then
  begin
    FScroll := TJvImageDrawThread.Create(True);
    FScroll.FreeOnTerminate := False;
    FScroll.Delay := FDelay;
    FScroll.OnDraw := OnScroll;
  end;
end;

destructor TJvScrollText.Destroy;
begin
  if not (csDesigning in ComponentState) then
  begin
    FScroll.OnDraw := nil;
    FScroll.Free;
  end;
  Application.HintPause := FDefaultAppHintPause;
  FItems.Free;
  FText.Free;
  FFont.OnChange := nil;
  FFont.Free;
  inherited Destroy;
end;

procedure TJvScrollText.DoScrollEnd;
begin
  if Assigned(OnScrollEnd) then
    OnScrollEnd(Self);
end;

procedure TJvScrollText.Loaded;
begin
  inherited Loaded;
  if csDesigning in ComponentState then
    SetItems(FItems);
end;

procedure TJvScrollText.SetFont(const Value: TFont);
var
  Al: TAlignment;
begin
  FFont.Assign(Value);
  FText.Font.Assign(FFont);
  CalculateText(Self);
  Al := FText.Alignment;
  if FText.Alignment = taCenter then
    FText.Alignment := taLeftJustify
  else
    FText.Alignment := taCenter;
  FText.Alignment := Al;
end;

procedure TJvScrollText.TextMouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
var
  P: TPoint;
begin
  P.X := X;
  P.Y := Y;
  P := FText.ClientToScreen(P);

  if ScrollDirection in [drFromTop, drFromBottom] then
    FStartY := P.Y
  else
    FStartY := P.X;
  if not (csDesigning in ComponentState) then
    FScroll.OnDraw := nil;
  FDown := True;

  if Assigned(OnMouseDown) then
  begin
    P := ScreenToClient(P);
    OnMouseDown(Self, Button, Shift, P.X, P.Y);
  end;
end;

procedure TJvScrollText.TextMouseMove(Sender: TObject; Shift: TShiftState; X, Y: Integer);
var
  NewY: Integer;
  P: TPoint;
begin
  P.X := X;
  P.Y := Y;
  P := FText.ClientToScreen(P);

  if FDown then
  begin
    //if NewY>0, going up, NewY<0, going down

    if ScrollDirection in [drFromTop, drFromBottom] then
    begin
      NewY := FStartY - P.Y;
      FStartY := P.Y;
      FCurrPos := FCurrPos - NewY;

      if FCurrPos < -FText.Height then
        FCurrPos := Height
      else
      if FCurrPos > Height then
        FCurrPos := -FText.Height;

      FText.Top := FCurrPos;
    end
    else
    begin
      NewY := FStartY - P.X;
      FStartY := P.X;
      FCurrPos := FCurrPos - NewY;

      if FCurrPos < -FText.Width then
        FCurrPos := Width
      else
      if FCurrPos > Width then
        FCurrPos := -FText.Width;

      FText.Left := FCurrPos;
    end;
  end;

  if Assigned(OnMouseMove) then
  begin
    P := ScreenToClient(P);
    if (P.X <> FOldMouseMovePt.X) or (P.Y <> FOldMouseMovePt.Y) then
    begin
      FOldMouseMovePt := P;
      OnMouseMove(Self, Shift, P.X, P.Y);
    end;
  end;
end;

procedure TJvScrollText.TextMouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
var
  P: TPoint;
begin
  if not (csDesigning in ComponentState) then
    FScroll.OnDraw := OnScroll;
  FDown := False;

  if Assigned(OnMouseUp) then
  begin
    P.X := X;
    P.Y := Y;
    P := Self.ScreenToClient( FText.ClientToScreen(P) );
    OnMouseUp(Self, Button, Shift, P.X, P.Y);
  end;
end;

procedure TJvScrollText.TextMouseClick(Sender: TObject);
begin
  // forward the event of the inner FText to the same event of the scroller
  if Assigned(OnClick) then
    OnClick(Self);
end;

procedure TJvScrollText.TextMouseDblClick(Sender: TObject);
begin
  // forward the double click event of the inner FText to the same event of the scroller
  if Assigned(OnDblClick) then
    OnDblClick(Self);
end;

procedure TJvScrollText.OnScroll(Sender: TObject);
var
  Offset: Integer;
  ScrollEnd: Boolean;
begin
  // Must exit because we are "Synchronized" and our parent is already
  // partly destroyed. If we did not exit, we would get an AV.
  if csDestroying in ComponentState then
    Exit;

  //tag=1 pause
  if FTimerTag = 1 then
  begin
    if FScrollSaved <= 0 then
    begin
      SetActive(False);
      FTimerTag := 0;
      Exit;
    end
    else
    begin
      Offset := FScrollSaved;
      Dec(FScrollSaved);
    end;
  end
  else
  if FTimerTag = 2 then
  begin
    if FScrollSaved >= FPixel then
    begin
      FTimerTag := 0;
      Offset := FPixel;
    end
    else
    begin
      Offset := FScrollSaved;
      Inc(FScrollSaved);
    end;
  end
  else
    Offset := FPixel;

  //tag=2 unpause
  //FScrollDirection

  ScrollEnd := False;
  case ScrollDirection of
    drFromTop:
      begin
        if FCurrPos > Height then
        begin
          FCurrPos := -FText.Height;
          ScrollEnd := True;
        end
        else
          FCurrPos := FCurrPos + Offset;
        FText.Top := FCurrPos;
      end;
    drFromRight:
      begin
        if - FCurrPos > FText.Width then
        begin
          FCurrPos := Width;
          ScrollEnd := True;
        end
        else
          FCurrPos := FCurrPos - Offset;
        FText.Left := FCurrPos;
      end;
    drFromLeft:
      begin
        if FCurrPos > Width then
        begin
          FCurrPos := -FText.Width;
          ScrollEnd := True;
        end
        else
          FCurrPos := FCurrPos + Offset;
        FText.Left := FCurrPos;
      end;
    drFromBottom:
      begin
        if - FCurrPos > FText.Height then
        begin
          FCurrPos := Height;
          ScrollEnd := True;
        end
        else
          FCurrPos := FCurrPos - Offset;
        FText.Top := FCurrPos;
      end;
  end;

  // As OnScroll is called from the draw thread's context, we
  // must synchronize the event call
  if ScrollEnd then
    FScroll.Synchronize(DoScrollEnd);
end;

procedure TJvScrollText.Pause;
begin
  if FActive then
  begin
    FScrollSaved := FPixel;
    FTimerTag := 1;
  end;
end;

procedure TJvScrollText.SetActive(const Value: Boolean);
begin
  SetItems(FItems);
  FActive := Value;
  if not (csDesigning in ComponentState) then
    FScroll.Paused := not Value;
end;

procedure TJvScrollText.SetDelay(const Value: Cardinal);
begin
  if Value > FDefaultAppHintPause then
    Application.HintPause := FDefaultAppHintPause
  else
  if Value > 10 then
    Application.HintPause := Value - 10
  else
    Application.HintPause := Abs(Value - 1);
  FDelay := Value;
  if not (csDesigning in ComponentState) then
    FScroll.Delay := Value;
end;

procedure TJvScrollText.SetScrollDirection(const Value: TJvScrollTextDirection);
begin
  FScrollDirection := Value;
  FText.Left := 0;
  FText.Top := 0;
  Reset;
end;

procedure TJvScrollText.CalculateText(Sender: TObject);
var
  I, J, K, W: Integer;
  Ts: TStringList;
  DesktopCanvas: TCanvas;
begin
  // calculate the Size of the memo (vertically)
  DesktopCanvas := TCanvas.Create;
  try
    DesktopCanvas.Handle := GetDC(HWND_DESKTOP);
    DesktopCanvas.Font.Assign(FText.Font);
    J := 0;
    K := 0;
    Ts := TStringList.Create;
    try
      Ts.Text := FText.Caption;
      for I := 0 to Ts.Count - 1 do
      try
        W := DesktopCanvas.TextWidth(Ts[I]);
        if K < W then
          K := W;
        if Ts[I] <> '' then
          J := J + DesktopCanvas.TextHeight(Ts[I]) * ((W div Width) + 1)
        else
          J := J + CanvasMaxTextHeight(DesktopCanvas);
      except
      end;
      if J <= 0 then
        J := Height;
      FText.Height := J;
      if K <= 0 then
        K := Width;
      FText.Width := K;
      DesktopCanvas.Handle := 0;
      ReleaseDC(HWND_DESKTOP, Handle);
    finally
      Ts.Free;
    end;
  finally
    DesktopCanvas.Free;
  end;
  Reset;
end;

function TJvScrollText.GetItems: TStrings;
begin
  Result := FItems;
end;

procedure TJvScrollText.SetItems(const Value: TStrings);
begin
  FItems.Text := Value.Text;
  FText.Caption := Value.Text;
  CalculateText(Self);
end;

function TJvScrollText.GetColor: TColor;
begin
  Result := FText.Color;
end;

procedure TJvScrollText.SetColor(const Value: TColor);
begin
  FText.Color := Value;
  Color := Value;
  Invalidate;
end;

procedure TJvScrollText.FontChange(Sender: TObject);
var
  Al: TAlignment;
begin
  FText.Font.Assign(FFont);
  CalculateText(Self);
  Al := FText.Alignment;
  if FText.Alignment = taCenter then
    FText.Alignment := taLeftJustify
  else
    FText.Alignment := taCenter;
  FText.Alignment := Al;
end;

procedure TJvScrollText.SetPixel(const Value: Integer);
begin
  FPixel := Value;
end;

procedure TJvScrollText.Reset;
begin
  case ScrollDirection of
    drFromTop:
      FCurrPos := -FText.Height;
    drFromLeft:
      FCurrPos := -FText.Width;
    drFromRight:
      FCurrPos := Width;
    drFromBottom:
      FCurrPos := Height;
  end;
end;

procedure TJvScrollText.Unpause;
begin
  if not FActive then
  begin
    FScrollSaved := 0;
    FTimerTag := 2;
    SetActive(True);
  end;
end;

function TJvScrollText.GetAlignment: TAlignment;
begin
  Result := FText.Alignment;
end;

procedure TJvScrollText.SetAlignment(const Value: TAlignment);
begin
  FText.Alignment := Value;
end;

function TJvScrollText.GetWordWrap: Boolean;
begin
  Result := FText.WordWrap;
end;

procedure TJvScrollText.SetWordWrap(const Value: Boolean);
begin
  FText.WordWrap := Value;
end;

{$IFDEF UNITVERSIONING}
initialization
  RegisterUnitVersion(HInstance, UnitVersioning);

finalization
  UnregisterUnitVersion(HInstance);
{$ENDIF UNITVERSIONING}

end.
