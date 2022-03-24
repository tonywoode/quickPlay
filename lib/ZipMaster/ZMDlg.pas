unit ZMDlg;

(*
  ZMDlg.pas - DialogBox with buttons from language strings
  TZipMaster VCL by Chris Vleghert and Eric W. Engler
  v1.79
  Copyright (C) 2005  Russell Peters


  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License (licence.txt) for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  contact: problems AT delphizip DOT org
  updates: http://www.delphizip.org


  modified 2005-11-05
---------------------------------------------------------------------------*)

interface

uses
  Classes, Windows, Forms, Dialogs, Buttons, StdCtrls, Controls;

// High word = $10 or TMsgDlgType, low word = context
const
  zmtWarning  = $100000;
  zmtError    = $110000;
  zmtInformation = $120000;
  zmtConfirmation = $130000;
  zmtPassword = $140000;

type
  TZipDialogBox = class(TForm)
  private
    AvDlgUnits: TPoint;
    BeepID: integer;
    ctx: Integer;
    DxText: TLabel;
    IconID: pChar;
    PwdEdit: TEdit;
    function GetDlgType: Integer;
    function GetPWrd: string;
    procedure SetPwrd(const Value: string); 
  public
    constructor CreateNew2(Owner: TComponent; context: Integer);
        virtual;
    procedure Build(title, msg: String; btns: TMsgDlgButtons);
    function ShowModal: Integer; override;
    property DlgType: Integer read GetDlgType;
    property PWrd: string read GetPWrd write SetPwrd;
  end;

implementation

uses SysUtils, Graphics, ExtCtrls, ZipMsg, ZMMsgStr;

const
  { Maximum no. of characters in a password; Do not change! }
  PWLEN = 80;

procedure TZipDialogBox.Build(title, msg: String; btns: TMsgDlgButtons);
const
  kHMargin  = 8;
  kVMargin  = 8;
  kHSpacing = 10;
  kVSpacing = 10;
  kBWidth   = 50;
  kBHeight  = 14;
  kBSpacing = 4;
  ModalResults: array[TMsgDlgBtn] of Integer = (
    mrYes, mrNo, mrOk, mrCancel, mrAbort, mrRetry, mrIgnore, mrAll, mrNoToAll,
    mrYesToAll,
{$ifdef UNICODE}
    0,
{$endif}
     0);
var
  HMargin, VMargin, HSpacing, VSpacing, BWidth, BHeight, BSpacing,
  ButtonCount, ButtonGroupWidth, IconTextWidth, IconTextHeight, T,
  X, Y, tx, ALeft, CWidth, CHeight: Integer;
  B, DefaultButton, CancelButton: TMsgDlgBtn;
  TextRect: TRect;
  wdth, i: Integer;
  N: TButton;
begin
  BiDiMode    := Application.BiDiMode;
  BorderStyle := bsDialog;
  Canvas.Font := Font; 
  if title = '' then
    Caption := Application.Title
  else
    Caption := title;
  HMargin := MulDiv(kHMargin, AvDlgUnits.X, 4);
  VMargin  := MulDiv(kVMargin, AvDlgUnits.Y, 8);
  HSpacing := MulDiv(kHSpacing, AvDlgUnits.X, 4);
  VSpacing := MulDiv(kVSpacing, AvDlgUnits.Y, 8);
  BWidth   := MulDiv(kBWidth, AvDlgUnits.X, 4);
  if mbOK in Btns then
    DefaultButton := mbOK
  else if mbYes in Btns then
    DefaultButton := mbYes
  else
    DefaultButton := mbRetry;
  if mbCancel in Btns then
    CancelButton := mbCancel
  else if mbNo in Btns then
    CancelButton := mbNo
  else
    CancelButton := mbOK;
  ButtonCount := 0;
  T := 1;
  if DlgType = zmtPassword then
    T := 2;
  for B := Low(TMsgDlgBtn) to High(TMsgDlgBtn) do
    if (B <> mbHelp) and (B in btns) then
    begin
      Inc(ButtonCount);
      N := TButton.Create(Self);
      with N do
      begin
        Name    := Format('zmdlg%d', [ButtonCount]);
        Parent  := Self;
        Caption := ZipLoadStr(ZB_Yes + ord(B));
        ModalResult := ModalResults[B];
        if B = DefaultButton then
          Default := True;
        if B = CancelButton then
          Cancel := True;
        TabStop := True;
        TabOrder := T;
        Inc(T);
      end;
      TextRect := Rect(0, 0, 0, 0);
      Windows.DrawText(canvas.handle, PChar(N.Caption), -1,
        TextRect, DT_CALCRECT or DT_LEFT or DT_SINGLELINE or
        DrawTextBiDiModeFlagsReadingOnly);
      with TextRect do
        wdth := Right - Left + 8;
      if wdth > BWidth then
        BWidth := wdth;
    end;
  BHeight  := MulDiv(kBHeight, AvDlgUnits.Y, 8);
  BSpacing := MulDiv(kBSpacing, AvDlgUnits.X, 4);
  SetRect(TextRect, 0, 0, Screen.Width div 2, 0);
  DrawText(Canvas.Handle, PChar(Msg), Length(Msg) + 1, TextRect,
    DT_EXPANDTABS or DT_CALCRECT or DT_WORDBREAK or
    DrawTextBiDiModeFlagsReadingOnly);
  IconTextWidth := TextRect.Right;
  IconTextHeight := TextRect.Bottom;
  if IconID <> NIL then
  begin
    Inc(IconTextWidth, 32 + HSpacing);
    if IconTextHeight < 32 then
      IconTextHeight := 32;
  end;
  ButtonGroupWidth := 0;
  if ButtonCount <> 0 then
    ButtonGroupWidth := BWidth * ButtonCount +
      BSpacing * (ButtonCount - 1);
  if IconTextWidth > ButtonGroupWidth then
    CWidth := IconTextWidth
  else
    CWidth :=  ButtonGroupWidth;
  CHeight := IconTextHeight + BHeight;
  if DlgType = zmtPassword then
  begin
    if CWidth < (PWLEN * AvDlgUnits.X) then
      CWidth := PWLEN * AvDlgUnits.X;
    PwdEdit := TEdit.Create(Self);
    with PwdEdit do
    begin
      Name      := 'zmdEdit';
      Text      := '';
      Parent    := Self;
      PasswordChar := '*';
      MaxLength := PWLEN;
      TabOrder  := 1;
      TabStop   := True;
      BiDiMode  := Self.BiDiMode;
      ALeft     := IconTextWidth - TextRect.Right + HMargin;
      if UseRightToLeftAlignment then
        ALeft := CWidth - ALeft - Width;
      tx := PWLEN * AvDlgUnits.X;
      if tx < TextRect.Right then
        tx := TextRect.Right;
      SetBounds(ALeft, IconTextHeight + VMargin + VSpacing, tx, 15);
    end;
    ActiveControl := PwdEdit;
    CHeight := CHeight + PwdEdit.Height + VMargin;
  end;
  ClientWidth := CWidth + (HMargin * 2);
  ClientHeight := CHeight + VSpacing + VMargin * 2;
  Left := (Screen.Width div 2) - (Width div 2);
  Top  := (Screen.Height div 2) - (Height div 2);
  if IconID <> NIL then
    with TImage.Create(Self) do
    begin
      Name   := 'Image';
      Parent := self;
      Picture.Icon.Handle := LoadIcon(0, IconID);
      SetBounds(HMargin, VMargin, 32, 32);
    end;
  DxText := TLabel.Create(Self);
  with DxText do
  begin
    Name     := 'zmdText';
    Parent   := Self;
    WordWrap := True;
    Caption  := Msg;
    BoundsRect := TextRect;
    BiDiMode := Self.BiDiMode;
    ALeft    := IconTextWidth - TextRect.Right + HMargin;
    if UseRightToLeftAlignment then
      ALeft := Self.ClientWidth - ALeft - Width;
    SetBounds(ALeft, VMargin,
      TextRect.Right, TextRect.Bottom);
  end;
  X := (ClientWidth - ButtonGroupWidth) div 2;
  Y := IconTextHeight + VMargin + VSpacing;
  if DlgType = zmtPassword then
    Inc(Y, PwdEdit.Height + VSpacing);
  for i := 0 to pred(ComponentCount) do
    if Components[i] is TButton then
      with Components[i] as TButton do
      begin
        SetBounds(X, Y, BWidth, BHeight);
        Inc(X, BWidth + BSpacing);
      end;
end;

constructor TZipDialogBox.CreateNew2(Owner: TComponent; context: Integer);
const
  IconIDs: array[0..4] of PChar = (IDI_EXCLAMATION, IDI_HAND,
    IDI_ASTERISK, IDI_QUESTION, NIL);
  BeepIDs: array[0..4] of Integer = (MB_ICONEXCLAMATION, MB_ICONHAND,
    MB_ICONASTERISK, MB_ICONQUESTION, 0);
var
  NonClientMetrics: TNonClientMetrics;
  buf: array [0..65] of Char;
  i:   Integer;
begin 
  inherited CreateNew(Owner, 0);
  NonClientMetrics.cbSize := sizeof(NonClientMetrics);
  if SystemParametersInfo(SPI_GETNONCLIENTMETRICS, 0, @NonClientMetrics, 0) then
    Font.Handle := CreateFontIndirect(NonClientMetrics.lfMessageFont);
  ctx := context;
  if DlgType = 0 then
    ctx := ctx or zmtWarning;
  for i := 0 to 25 do
  begin
    buf[i]      := Char(Ord('A') + i);
    buf[i + 27] := Char(Ord('a') + i);
  end;
  buf[26] := ' ';
  buf[52] := ' ';
  for i := 53 to 63 do
    buf[i] := Char(Ord('0') + i - 53);
  buf[64] := #0;
  GetTextExtentPoint(Canvas.Handle, Buf, 64, TSize(AvDlgUnits));
  AvDlgUnits.X := AvDlgUnits.X div 64;
  i := (DlgType shr 16) and 7;
  if i > 4 then
    i := 4;
  IconID := IconIDs[i];
  BeepID := BeepIDs[i];
end;

function TZipDialogBox.GetDlgType: Integer;
begin
  Result := Ctx and $1F0000;
end;

function TZipDialogBox.GetPWrd: string;
begin
  if assigned(PwdEdit) then
    Result := PwdEdit.Text
  else
    Result := '';
end;

procedure TZipDialogBox.SetPwrd(const Value: string);
begin
  if assigned(PwdEdit) and (Value <> PwdEdit.Text) then
      PwdEdit.Text := Value;
end;

function TZipDialogBox.ShowModal: Integer;
begin
  if BeepId <> 0 then
    MessageBeep(BeepId);
  Result := inherited ShowModal;
end;
 
end.

