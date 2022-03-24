unit ExtrUnit;
  
{$INCLUDE ZipVers.inc}
{$IFDEF VERD6up}
{$WARN UNIT_PLATFORM OFF}
{$WARN SYMBOL_PLATFORM OFF}
{$ENDIF}


interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ExtCtrls, FileCtrl;

type
  TExtract = class( TForm )
    Panel1:            TPanel;
    Panel2:            TPanel;
    Panel3:            TPanel;
    DirectoryListBox1: TDirectoryListBox;
    DriveComboBox1:    TDriveComboBox;
    OKBut:             TButton;
    CancelBut:         TButton;
    RadioGroup1:       TRadioGroup;
    RadioGroup2:       TRadioGroup;

    procedure OKButClick( Sender: TObject );
    procedure FormActivate( Sender: TObject );
    procedure CancelButClick( Sender: TObject );
  end;

var
  Extract: TExtract;

implementation

uses Main;

{$R *.DFM}

procedure TExtract.OKButClick( Sender: TObject );
begin
   Main.Canceled   := False;
   Main.ExtractDir := DirectoryListBox1.Directory;
   if RadioGroup1.ItemIndex = 0 then
      Main.ExpandDirs := False
   else
      Main.ExpandDirs := True;
   if RadioGroup2.ItemIndex = 0 then
      Main.Overwr     := False
   else
      Main.Overwr     := True;
   Main.AllFiles   := True;
   Close;
end;

procedure TExtract.CancelButClick( Sender: TObject );
begin
   Main.ExtractDir := '';
   Close;
end;

procedure TExtract.FormActivate( Sender: TObject );
begin
   Main.Canceled := True; { default }
end;

end.
