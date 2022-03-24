{-----------------------------------------------------------------------------
The contents of this file are subject to the Mozilla Public License
Version 1.1 (the "License"); you may not use this file except in compliance
with the License. You may obtain a copy of the License at
http://www.mozilla.org/MPL/MPL-1.1.html

Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either expressed or implied. See the License for
the specific language governing rights and limitations under the License.

The Original Code is: JvStrToHtml.PAS, released on 2001-02-28.

The Initial Developer of the Original Code is SÈbastien Buysse [sbuysse att buypin dott com]
Portions created by SÈbastien Buysse are Copyright (C) 2001 SÈbastien Buysse.
All Rights Reserved.

Contributor(s): Michael Beck [mbeck att bigfoot dott com].
                Andreas Hausladen [Andreas dott Hausladen att gmx dott de]

You may retrieve the latest version of this file at the Project JEDI's JVCL home page,
located at http://jvcl.delphi-jedi.org

Known Issues:
-----------------------------------------------------------------------------}
// $Id: JvStrToHtml.pas 12472 2009-08-24 16:08:33Z ahuser $

unit JvStrToHtml;

{$I jvcl.inc}

interface

uses
  {$IFDEF UNITVERSIONING}
  JclUnitVersioning,
  {$ENDIF UNITVERSIONING}
  SysUtils, Classes,
  JvComponentBase;

type
  TJvStrToHtml = class(TJvComponent)
  private
    FHtml: string;
    FValue: string;
    procedure SetHtml(const Value: string);
    procedure SetValue(const Value: string);
  public
    constructor Create(AOwner: TComponent); override;
    function TextToHtml(const Text: string): string;
    function HtmlToText(const Text: string): string;
  published
    property Text: string read FValue write SetValue;
    property Html: string read FHtml write SetHtml;
  end;

function StringToHtml(const Value: string): string;
function HtmlToString(const Value: string): string;
function CharToHtml(Ch: Char): string;

{$IFDEF UNITVERSIONING}
const
  UnitVersioning: TUnitVersionInfo = (
    RCSfile: '$URL: https://jvcl.svn.sourceforge.net/svnroot/jvcl/tags/JVCL3_39/run/JvStrToHtml.pas $';
    Revision: '$Revision: 12472 $';
    Date: '$Date: 2009-08-24 18:08:33 +0200 (lun., 24 ao√ªt 2009) $';
    LogPath: 'JVCL\run'
  );
{$ENDIF UNITVERSIONING}

implementation


type
  TJvHtmlCodeRec = packed record
    Ch: Char;
    Html: PChar;
  end;

const
  { References:
      http://www.w3.org/TR/REC-html40/charset.html#h-5.3
      http://www.w3.org/TR/REC-html40/sgml/entities.html#h-24.2.1
      http://www.w3.org/TR/REC-html40/sgml/entities.html#h-24.4.1
  }
  Conversions: array [1..75] of TJvHtmlCodeRec = (
    (Ch: '"'; Html: '&quot;'),
    (Ch: '<'; Html: '&lt;'),
    (Ch: '>'; Html: '&gt;'),
    (Ch: '^'; Html: '&circ;'),
    (Ch: '~'; Html: '&tilde;'),
    (Ch: '£'; Html: '&pound;'),
    (Ch: 'ß'; Html: '&sect;'),
    (Ch: '∞'; Html: '&deg;'),
    (Ch: '≤'; Html: '&sup2;'),
    (Ch: '≥'; Html: '&sup3;'),
    (Ch: 'µ'; Html: '&micro;'),
    (Ch: '∑'; Html: '&middot;'),
    (Ch: 'º'; Html: '&frac14;'),
    (Ch: 'Ω'; Html: '&frac12;'),
    (Ch: 'ø'; Html: '&iquest;'),
    (Ch: '¿'; Html: '&Agrave;'),
    (Ch: '¡'; Html: '&Aacute;'),
    (Ch: '¬'; Html: '&Acirc;'),
    (Ch: '√'; Html: '&Atilde;'),
    (Ch: 'ƒ'; Html: '&Auml;'),
    (Ch: '≈'; Html: '&Aring;'),
    (Ch: '∆'; Html: '&AElig;'),
    (Ch: '«'; Html: '&Ccedil;'),
    (Ch: '»'; Html: '&Egrave;'),
    (Ch: '…'; Html: '&Eacute;'),
    (Ch: ' '; Html: '&Ecirc;'),
    (Ch: 'À'; Html: '&Euml;'),
    (Ch: 'Ã'; Html: '&Igrave;'),
    (Ch: 'Õ'; Html: '&Iacute;'),
    (Ch: 'Œ'; Html: '&Icirc;'),
    (Ch: 'œ'; Html: '&Iuml;'),
    (Ch: '—'; Html: '&Ntilde;'),
    (Ch: '“'; Html: '&Ograve;'),
    (Ch: '”'; Html: '&Oacute;'),
    (Ch: '‘'; Html: '&Ocirc;'),
    (Ch: '’'; Html: '&Otilde;'),
    (Ch: '÷'; Html: '&Ouml;'),
    (Ch: 'Ÿ'; Html: '&Ugrave;'),
    (Ch: '⁄'; Html: '&Uacute;'),
    (Ch: '€'; Html: '&Ucirc;'),
    (Ch: '‹'; Html: '&Uuml;'),
    (Ch: '›'; Html: '&Yacute;'),
    (Ch: 'ﬂ'; Html: '&szlig;'),
    (Ch: '·'; Html: '&aacute;'),
    (Ch: '‡'; Html: '&agrave;'),
    (Ch: '‚'; Html: '&acirc;'),
    (Ch: '„'; Html: '&atilde;'),
    (Ch: '‰'; Html: '&auml;'),
    (Ch: 'Â'; Html: '&aring;'),
    (Ch: 'Ê'; Html: '&aelig;'),
    (Ch: 'Á'; Html: '&ccedil;'),
    (Ch: 'È'; Html: '&eacute;'),
    (Ch: 'Ë'; Html: '&egrave;'),
    (Ch: 'Í'; Html: '&ecirc;'),
    (Ch: 'Î'; Html: '&euml;'),
    (Ch: 'Ï'; Html: '&igrave;'),
    (Ch: 'Ì'; Html: '&iacute;'),
    (Ch: 'Ó'; Html: '&icirc;'),
    (Ch: 'Ô'; Html: '&iuml;'),
    (Ch: 'Ò'; Html: '&ntilde;'),
    (Ch: 'Ú'; Html: '&ograve;'),
    (Ch: 'Û'; Html: '&oacute;'),
    (Ch: 'Ù'; Html: '&ocirc;'),
    (Ch: 'ı'; Html: '&otilde;'),
    (Ch: 'ˆ'; Html: '&ouml;'),
    (Ch: '˜'; Html: '&divide;'),
    (Ch: '˘'; Html: '&ugrave;'),
    (Ch: '˙'; Html: '&uacute;'),
    (Ch: '˚'; Html: '&ucirc;'),
    (Ch: '¸'; Html: '&uuml;'),
    (Ch: '˝'; Html: '&yacute;'),
    (Ch: 'ˇ'; Html: '&yuml;'),
    (Ch: '&'; Html: '&amp;'),
    (Ch: '¥'; Html: '&acute;'),
    (Ch: '`'; Html: '&grave;')
    );

constructor TJvStrToHtml.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FValue := '';
  FHtml := '';
end;

function TJvStrToHtml.HtmlToText(const Text: string): string;
begin
  Result := HtmlToString(Text);
end;

procedure TJvStrToHtml.SetHtml(const Value: string);
begin
  FValue := HtmlToText(Value);
end;

procedure TJvStrToHtml.SetValue(const Value: string);
begin
  FHtml := TextToHtml(Value);
end;

function TJvStrToHtml.TextToHtml(const Text: string): string;
begin
  Result := StringToHtml(Text);
end;

function StringToHtml(const Value: string): string;
const
  Nbsp = '&nbsp;';
var
  I, J: Integer;
  Len, AddLen, HtmlLen: Integer;
  P: PChar;
  Ch: Char;
begin
  Len := Length(Value);
  // number of chars to add
  AddLen := 0;
  for I := 1 to Len do
  begin
    Ch := Value[I];
    if Ch = ' ' then
    begin
      if (I > 1) and (Value[I - 1] = ' ') then
        Inc(AddLen, 6 {Length(Nbsp)});
    end
    else
      for J := Low(Conversions) to High(Conversions) do
        if Ch = Conversions[J].Ch then
        begin
          Inc(AddLen, StrLen(Conversions[J].Html) - 1);
          Break;
        end;
  end;

  if AddLen = 0 then
    Result := Value
  else
  begin
    SetLength(Result, Len + AddLen);
    P := Pointer(Result);
    for I := 1 to Len do
    begin
      Ch := Value[I];
      if Ch = ' ' then
      begin
        if (I > 1) and (Value[I - 1] = ' ') then
        begin
          HtmlLen := 6 {Length(Nbsp)};
          Move(Nbsp[1], P[0], HtmlLen * SizeOf(Char));
          Inc(P, HtmlLen);
          Ch := #0;
        end;
      end
      else
        for J := Low(Conversions) to High(Conversions) do
          if Ch = Conversions[J].Ch then
          begin
            HtmlLen := StrLen(Conversions[J].Html);
            Move(Conversions[J].Html[0], P[0], HtmlLen * SizeOf(Char)); // Conversions[].Html is a PChar
            Inc(P, HtmlLen);
            Ch := #0;
            Break;
          end;
      if Ch <> #0 then
      begin
        P[0] := Ch;
        Inc(P);
      end;
    end;
  end;
end;

function HtmlToString(const Value: string): string;
var
  I, Index, Len: Integer;
  Start, J: Integer;
  Ch: Char;
  ReplStr: string;
begin
  Len := Length(Value);
  SetLength(Result, Len); // worst case
  Index := 0;
  I := 1;
  while I <= Len do
  begin
    Ch := Value[I];
   // html entitiy
    if Ch = '&' then
    begin
      Start := I;
      Inc(I);
      while (I <= Len) and (Value[I] <> ';') and (I < Start + 20) do
        Inc(I);
      if Value[I] <> ';' then
        I := Start
      else
      begin
        Ch := #0;
        ReplStr := LowerCase(Copy(Value, Start, I - Start + 1));
        if ReplStr = '&nbsp;' then // special treatment for &nbsp
          Ch := ' '
        else
          for J := Low(Conversions) to High(Conversions) do
            if Conversions[J].Html = ReplStr then
            begin
              Ch := Conversions[J].Ch;
              Break;
            end;

        // if no conversion was found, it may actually be a number
        if Ch = #0 then
        begin
          if StrToIntDef(ReplStr, -1) <> -1 then
            Ch := Chr(StrToInt(ReplStr))
          else
          begin
            I := Start;
            Ch := Value[I];
          end;
        end;
      end;
    end;

    Inc(I);
    Inc(Index);
    Result[Index] := Ch;
  end;
  if Index <> Len then
    SetLength(Result, Index);
end;

function CharToHtml(Ch: Char): string;
var
  I: Integer;
begin
  for I := Low(Conversions) to High(Conversions) do
    if Conversions[I].Ch = Ch then
    begin
      Result := Conversions[I].Html;
      Exit;
    end;
  Result := Ch;
end;

{$IFDEF UNITVERSIONING}
initialization
  RegisterUnitVersion(HInstance, UnitVersioning);

finalization
  UnregisterUnitVersion(HInstance);
{$ENDIF UNITVERSIONING}

end.
