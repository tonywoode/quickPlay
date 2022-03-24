unit extrunit;
 
{$INCLUDE ZipVers.inc}
{$IFDEF VERD6up}
	{$WARN UNIT_PLATFORM OFF}
	{$WARN SYMBOL_PLATFORM OFF}
{$endif}

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ExtCtrls, FileCtrl;

type
  TExtract = class(TForm)
    Panel1: TPanel;
    Panel2: TPanel;
    OKBut: TButton;
    CancelBut: TButton;
    DirectoryListBox1: TDirectoryListBox;
    RadioGroup1: TRadioGroup;
    RadioGroup2: TRadioGroup;
    Panel3: TPanel;
    DriveComboBox1: TDriveComboBox;
    procedure OKButClick(Sender: TObject);
    procedure CancelButClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Extract: TExtract;

implementation

uses Unit1;

{$R *.DFM}

procedure TExtract.OKButClick(Sender: TObject);
begin
   Form1.ExtractDir:=DirectoryListBox1.Directory;
   if RadioGroup1.ItemIndex = 0 then
      Form1.ExpandDirs:=False
   else
      Form1.ExpandDirs:=True;
   if RadioGroup2.ItemIndex = 0 then
      Form1.Overwrite:=False
   else
      Form1.Overwrite:=True;
   Close;
end;

procedure TExtract.CancelButClick(Sender: TObject);
begin
   Form1.ExtractDir:='';
   Close;
end;

procedure TExtract.FormCreate(Sender: TObject);
begin
   RadioGroup1.ItemIndex := 0;  // dflt: do not expand dirs
   RadioGroup2.ItemIndex := 1;  // dflt: overwrite existing files
end;

end.
