unit demo2_1;

interface

{$I DELVER.INC}

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms,
  Dialogs, Buttons, ExtCtrls, StdCtrls, ZipSFXPlus, ZipSFXBase;//, DZUtils;

type
  TForm1 = class(TForm)
    Panel3: TPanel;
    Image1: TImage;
    Panel1: TPanel;
    Button1: TButton;
    btnToSFX: TButton;
    btnToEXE: TButton;
    btnNewSFX: TButton;
    Bevel1: TBevel;
    dlgOpenSFX: TOpenDialog;
    dlgSaveZIP: TSaveDialog;
    ZipSFX1: TZipSFXPlus;
    procedure Button1Click(Sender: TObject);
    procedure btnToSFXClick(Sender: TObject);
    procedure btnNewSFXClick(Sender: TObject);
    procedure btnToEXEClick(Sender: TObject);
  private
    { Private-Deklarationen }
  public
    { Public-Deklarationen }
  end;

var
  Form1: TForm1;

// pick an icon via shell's PickIconDlg
function PickIcon(const hwndOwner: HWND; var sIconFile: string; var iIconNum: Integer): Boolean;

implementation

uses demo2_2;

{$R *.dfm}

// include all available sfx.bin modules
{$R dzsfx_all.res}
//{$R zipmsgus.res}
{$R '..\res\delzip.res'}

procedure TForm1.Button1Click(Sender: TObject);
begin
  Close;
end;


procedure TForm1.btnToSFXClick(Sender: TObject);
begin
  with TdlgConvertToSFX.Create(self) do
  try
    ShowModal;
  finally
    Free;
  end;
end;

function PickIconDlgA(hwndOwner: HWND; lpstrFile: PChar; nMaxFile: Word; var lpdwIconIndex: DWORD): Bool;
  stdcall external 'shell32.dll' index 62;

function PickIconDlgW(hwndOwner: HWND; lpstrFile: PWideChar; nMaxFile: Word; var lpdwIconIndex: DWORD): Bool;
  stdcall external 'shell32.dll' index 62;

// pick an icon via shell's PickIconDlg
function PickIcon(const hwndOwner: HWND; var sIconFile: string; var iIconNum: Integer): Boolean;
var
  pch: PChar;
  pwch: PWideChar;
  {$IFDEF DELPHI3UP}
  c: Cardinal;
  {$ELSE}
  c: Integer;
  {$ENDIF}
begin
  c := iIconNum;
  if Win32Platform = VER_PLATFORM_WIN32_NT then
  begin
    GetMem(pwch, MAX_PATH * sizeof(WideChar));
    try
      StringToWideChar(sIconFile, pwch, MAX_PATH);
      Result := PickIconDlgW(hwndOwner, pwch, MAX_PATH, DWORD(c));
      if Result then
      begin
        iIconNum := c;
        sIconFile := WideCharToString(pwch);
      end;
    finally
      FreeMem(pwch);
    end;
  end
  else
  begin
    GetMem(pch, MAX_PATH);
    try
      StrPCopy(pch, sIconFile);
      Result := PickIconDlgA(hwndOwner, pch, MAX_PATH , DWORD(c));
      if Result then
      begin
        iIconNum := c;
        sIconFile := pch;
      end;
    finally
      FreeMem(pch);
    end;
  end;
end;

procedure TForm1.btnNewSFXClick(Sender: TObject);
begin
  with TdlgConvertToSFX.Create(self) do
  try
    PrepareMakeNew;
    ShowModal;
  finally
    Free;
  end;
end;

procedure TForm1.btnToEXEClick(Sender: TObject);
begin
  with dlgOpenSFX
  do
    if Execute then
    begin
      ZipSFX1.SourceFile := FileName;
      with dlgSaveZip do
      begin
        FileName := ChangeFileExt(ZipSFX1.SourceFile,'.zip');
        if Execute then
        begin
          ZipSFX1.TargetFile := FileName;
          ZipSFX1.StartWaitCursor;
          try
            ZipSFX1.ConvertToZip;
            MessageDlg('ZIP archive '+ZipSFX1.TargetFile+#13#10+
              'has been created.', mtInformation, [mbOK], 0);
          finally
            ZipSFX1.StopWaitCursor;
          end;
        end;
      end;
    end;

end;

end.
