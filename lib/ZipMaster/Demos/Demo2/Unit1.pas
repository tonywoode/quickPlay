unit Unit1;   { DEMO 2 for Delphi Zip by Eric W. Engler }

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ZipMstr;

type
  TForm1 = class(TForm)
    ZipBut: TButton;
    UnzipBut: TButton;
    ExitBut: TButton;
    DelBut: TButton;
    VersionBut: TButton;
    ZipMaster1: TZipMaster;
    procedure ZipButClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure ExitButClick(Sender: TObject);
    procedure ZipMaster1Message(Sender: TObject; ErrCode: Integer;
      Message: string);
    procedure UnzipButClick(Sender: TObject);
    procedure DelButClick(Sender: TObject);
    procedure VersionButClick(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.DFM} 
{$R ZipDemo2.Manifest.res ZipDemo2.Manifest.rc}

procedure TForm1.FormCreate(Sender: TObject);
begin
   { SetCurrentDir('C:\ZIP\DEMO2'); }
   Caption:='ZIP Demo 2 - ' + GetCurrentDir;
   ZipMaster1.ZipFileName:='test.zip';
   ZipMaster1.Dll_Load := true;
//   ZipMaster1.Load_Zip_Dll;
//   ZipMaster1.Load_Unz_Dll;
end;

{ Add one file to the zipfile }
procedure TForm1.ZipButClick(Sender: TObject);
begin
   if not FileExists('TEST.DAT') then
   begin
      ShowMessage('Error - test.dat not found');
      Exit;
   end;
   ZipMaster1.FSpecArgs.Add('TEST.DAT');
   ZipMaster1.Add;
   ShowMessage('Files added = ' + IntToStr(ZipMaster1.SuccessCnt));
end;

{ expand all files from the zipfile }
procedure TForm1.UnzipButClick(Sender: TObject);
begin
  with ZipMaster1 do
  begin
     if Count = 0 then
     begin
        ShowMessage('Error - no files in the Zip file');
        Exit;
     end;
     { If we don't specify filenames, we will extract them all. }
     { Of course, in this little demo there is only 1 file in the ZIP. }
     FSpecArgs.Add('*.*');
     ExtrBaseDir:=GetCurrentDir;
     { if the file to be extracted already exists, overwrite it }
     ExtrOptions:=ExtrOptions+[ExtrOverwrite];
     Extract;
     ShowMessage('Files extracted = ' + IntToStr(SuccessCnt));
  end;
end;

{ delete one file from the zipfile }
procedure TForm1.DelButClick(Sender: TObject);
begin
   ZipMaster1.FSpecArgs.Add('TEST.DAT');
   ZipMaster1.Delete;
   ShowMessage('Files deleted = ' + IntToStr(ZipMaster1.SuccessCnt));
end;

procedure TForm1.VersionButClick(Sender: TObject);
begin                                                                 
   ShowMessage('DelZip179.DLL version: ' + ZipMaster1.Dll_Version
      + #13#10 + 'Loaded from: ' + ZipMaster1.Dll_Path
   + #13#10 + 'ZipMaster version: ' + ZipMaster1.VersionInfo);
end;

procedure TForm1.ExitButClick(Sender: TObject);
begin
   Close;
end;

{ This procedure displays messages received from the DLLs.  If you really
  want to minimize the amount of messages you show the user, you don't
  even need to assign this event handler.  However, I'd still recommend
  that you assign this to catch errors.  You can test the ErrCode
  before you display the message - if ErrCode is non-zero, make sure you
  display the message.  If it's 0, then you can ignore the message.
    Also, if ZipMaster1's "Verbose" property is true, you'll get more
  informational message callbacks here. By default, it's false to
  minimize user messages. }
procedure TForm1.ZipMaster1Message(Sender: TObject; ErrCode: Integer;
  Message: string);
begin
   { if ErrCode <> 0 then }   { uncomment this line to show errors ONLY }
   ShowMessage(Message);
end;

procedure TForm1.FormDestroy(Sender: TObject);
begin
  ZipMaster1.Dll_Load := false;
//   ZipMaster1.Unload_Zip_Dll;
//   ZipMaster1.Unload_Unz_Dll;
end;

end.
