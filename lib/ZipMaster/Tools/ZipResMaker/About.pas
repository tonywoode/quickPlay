unit About;

interface

uses Windows, SysUtils, Classes, Graphics, Forms, Controls, StdCtrls,
  Buttons, ExtCtrls;

type
  TAboutBox = class(TForm)
    Panel1: TPanel;
    ProgramIcon: TImage;
    ProductName: TLabel;
    Version: TLabel;
    Copyright: TLabel;
    Comments: TLabel;
    OKButton: TButton;
    StaticText1: TStaticText;
    StaticText2: TStaticText;
    procedure FormActivate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  AboutBox: TAboutBox;

implementation

{$R *.dfm}
   
function VerInfoFileVersion(const fname: string): integer;
var
  dwInfoSize,           // Size of VERSIONINFO structure
  dwVerSize,            // Size of Version Info Data
  dwWnd: DWORD;         // Handle for the size call.
  FI: PVSFixedFileInfo; // Delphi structure; see WINDOWS.PAS
  ptrVerBuf: Pointer;   // pointer to a version buffer
begin
  Result := 0;
  dwInfoSize :=
    getFileVersionInfoSize(PChar(fname), dwWnd);

  if (dwInfoSize = 0) then
    Result := 0
  else
  begin
    getMem(ptrVerBuf, dwInfoSize);
    try

      if getFileVersionInfo(PChar(fname), dwWnd,
        dwInfoSize, ptrVerBuf) then
        if verQueryValue(ptrVerBuf, '\', pointer(FI),
          dwVerSize) then
          if dwVerSize = SizeOf(TVSFixedFileInfo) then
            Result := (hiWord(cardinal(FI.dwFileVersionMS)) *
              1000000) +
              ((FI.dwFileVersionMS and $FF) * 10000) +
              (hiWord(cardinal(FI.dwFileVersionLS)) * 100) +
              (FI.dwFileVersionLS and $FF);
    finally
      freeMem(ptrVerBuf);
    end;
  end;
end;

function VerToStr(ver: integer; Comma: boolean = false): string;
const
   fmt: array [boolean] of string = ('%d.%d.%2.2d.%2.2d', '%d,%d,%d,%d');
begin
  Result := Format(fmt[Comma], [Ver div 1000000,
    (Ver mod 1000000) div 10000, (Ver mod 10000) div 100, Ver mod 100]);
end;

procedure TAboutBox.FormActivate(Sender: TObject);
begin
  Version.Caption := VerToStr(VerInfoFileVersion(Application.ExeName));
end;


end.
 
