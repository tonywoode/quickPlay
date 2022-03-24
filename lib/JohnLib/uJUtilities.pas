unit uJUtilities;

interface

uses
  Windows, Forms, SysUtils, Graphics, ComCtrls, Dialogs, Classes, Registry;

type
  EJException = class(Exception);
  EJWarning = class(Exception);
  EJNotice = class(Exception);
  FontRec = packed record
    Color: TColor;
    LogFont: TLogFont;
  end;

  {Function Declarations}
  procedure AddPanel(Parent : TPageControl; fclass : TFormClass; NewTag : Integer);
  Procedure AddToLog(Output : String);
  Procedure DisplayMsg(Title, Msg : String; Duration : Integer = 5000);
  procedure EraseRegistrySubKeys(UseReg : TRegistry);
  procedure FontFromStream(s: TStream; Font: TFont);
  procedure FontToStream(s: TStream; Font: TFont);
  Function GetFontTextHeight(inFont : TFont) : Integer;
  function HTTPEncode(const AStr: string): string;
  procedure OpenHomePage(HomePage: String);

implementation

uses Controls, ShellAPI, JclStrings, JvBaseDlg, JvDesktopAlert;

{$I Compilers.inc}

{-----------------------------------------------------------------------------}

procedure AddPanel(Parent : TPageControl; fclass : TFormClass; NewTag : Integer);
var
  NewTab : TTabSheet;
  NewPanel: TForm;
begin
    if Assigned(fclass) then
    begin

      NewTab := TTabSheet.Create(Parent);
      NewTab.PageControl := Parent;
      NewTab.Tag := NewTag;
      NewTab.Caption := IntToStr(NewTag);
      NewTab.BorderWidth := 0;
      NewTab.TabVisible := False;
      NewPanel := fclass.Create(NewTab);
      NewPanel.Hide;
      NewPanel.BorderStyle := bsNone;
      NewPanel.Parent := NewTab;
      NewPanel.Align := alClient;
      NewPanel.Show;
    end;
end;

{---------------------------------------------------------------------------}

Procedure AddToLog(Output : String);
Var
  Filename : string;
  LogFile : TextFile;
begin
  //prepare the log file
  FileName := ChangeFileExt(Application.ExeName, '.log');
  AssignFile(LogFile, filename);
  try
    If FileExists(FileName) then
      Append(LogFile)  //Open the existing log
    else
      Rewrite(LogFile);  //Create a new log

    //Write the file and show the error
    Writeln(LogFile, DateTimeToStr(now()) + ' : ' + Output);
  Finally
    //Close the File
    CloseFile(logFile);
  end;
end;

{-----------------------------------------------------------------------------}

Procedure DisplayMsg(Title, Msg : String; Duration : Integer = 5000);
var
  DA:TJvDesktopAlert;
begin
  DA := TJvDesktopAlert.Create(nil);
  DA.AutoFree := True;
  DA.HeaderText := Title;
  DA.MessageText := Msg;
  DA.Options := [daoCanClose];
  DA.Location.AlwaysResetPosition := false;
  DA.Location.Position := dapBottomRight;
  DA.Location.Width := 0;
  DA.Location.Height := 0;
  DA.AlertStyle := asFade;
  DA.StyleHandler.DisplayDuration  := Duration; //  + Random(WaitTime);
  DA.AutoFocus := False;
  DA.Execute;
end;

{-----------------------------------------------------------------------------}

procedure EraseRegistrySubKeys(UseReg : TRegistry);
var
  SubKeys : TStringList;
  i : Integer;
begin
  SubKeys := TStringList.Create;
  Try
    //use the registry object as is
    if UseReg.HasSubKeys then
    begin
      UseReg.GetKeyNames(SubKeys);
      for I := 0 to SubKeys.Count - 1 do
        UseReg.DeleteKey(SubKeys[i]);

    end;
  finally
    FreeAndNil(SubKeys);
  end;
end;

{-----------------------------------------------------------------------------}

procedure FontFromStream(s: TStream; Font: TFont);
var
  fRec: FontRec;
  sz: integer;
begin
  s.read(sz, SizeOf(Integer));
  if sz = SizeOf(fRec.LogFont) then
  begin
    s.read(fRec, SizeOf(fRec));
    Font.Handle := CreateFontIndirect(fRec.LogFont);
    Font.Color  := fRec.Color;
  end;
end;

{-----------------------------------------------------------------------------}

procedure FontToStream(s: TStream; Font: TFont);
var
  fRec: FontRec;
  sz: integer;
begin
  sz := SizeOf(fRec.LogFont);
  if Windows.GetObject(Font.Handle, sz, @fRec.LogFont) > 0 then
  begin
    s.Write(sz, SizeOf(Integer));
    fRec.Color := Font.Color;
    s.Write(fRec, SizeOf(fRec));
  end
  else
  begin
    sz := 0;
    s.Write(sz, SizeOf(Integer));
  end;
end;

{-----------------------------------------------------------------------------}

Function GetFontTextHeight(inFont : TFont) : Integer;
var
  DC: HDC;
  Canvas: TCanvas;
begin

  Canvas := TCanvas.Create;
  try
    DC := GetDC(0);
    Canvas.Handle := DC;
    Canvas.Font := inFont;

    Result := Canvas.TextHeight('W');

    if Result < 20 then
      Result := 20;

    Canvas.Handle := 0;
    ReleaseDC(0, DC);

  Finally
    FreeAndNil(Canvas);
  end;
end;

{-----------------------------------------------------------------------------}

function HTTPEncode(const AStr: string): string;
const
  NoConversion = ['A'..'Z', 'a'..'z', '*', '@', '.', '_', '-'];
var
  Sp, Rp: PChar;
begin
  SetLength(Result, Length(AStr) * 3);
  Sp := PChar(AStr);
  Rp := PChar(Result);
  while Sp^ <> #0 do
  begin
    if Sp^ in NoConversion then
      Rp^ := Sp^
    else if Sp^ = ' ' then
      Rp^ := '+'
    else
    begin
      FormatBuf(Rp^, 3, '%%%.2x', 6, [Ord(Sp^)]);
      Inc(Rp, 2);
    end;
    Inc(Rp);
    Inc(Sp);
  end;
  SetLength(Result, Rp - PChar(Result));
end;

{-----------------------------------------------------------------------------}

procedure OpenHomePage(HomePage: String);
begin

  //this procedure opens the home page specified by the
  //string sent to the procedure

  //for security reasons we need to make sure that this is actually a URL!
  if (HomePage <> '') and
   ( (JCLStrings.StrIPos('http://', HomePage) <> 0) or
     (JCLStrings.StrIPos('www', HomePage) <> 0) or
     (JCLStrings.StrIPos('.co', HomePage) <> 0) ) then
    ShellExecute(Application.Handle, 'open', PChar(HomePage), '', '', sw_Show);

end;

{-----------------------------------------------------------------------------}

end.
