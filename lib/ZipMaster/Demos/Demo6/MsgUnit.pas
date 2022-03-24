unit MsgUnit;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ExtCtrls, ComCtrls;

type
  TMsgform = class( TForm )
    Panel1:          TPanel;
    Panel2:          TPanel;
    DismissBut:      TButton;
    CancelBut:       TButton;
    FileBeingZipped: TLabel;
    ProgressBar1:    TProgressBar;
    RichEdit1:       TRichEdit;
    StatusBar1:      TStatusBar;

    procedure DismissButClick( Sender: TObject );
    procedure CancelButClick( Sender: TObject );
    procedure FormCreate( Sender: TObject );
    procedure FormResize( Sender: TObject );

  public
    { Public declarations }
    FormInitialWidth: Integer;

    ProgressBar2: TProgressBar;
  end;

var
  Msgform: TMsgform;

implementation

uses main;

{$R *.DFM}

procedure TMsgform.DismissButClick( Sender: TObject );
begin
   Hide;
end;

procedure TMsgform.CancelButClick( Sender: TObject );
begin
   if (MainForm.ZipMaster1.ZipBusy or MainForm.ZipMaster1.UnzBusy) then
      MainForm.ZipMaster1.Cancel := True
   else
      Hide; { nothing to cancel - assume user wants to close msg window }
end;

procedure TMsgform.FormCreate( Sender: TObject );
begin
   ProgressBar2 := TProgressBar.Create( StatusBar1 );	// Parent will delete it.

   {$IfDef VER120}
   ProgressBar1.Smooth := True;
   {$EndIf}
   with ProgressBar2 do
   begin
      Parent  := StatusBar1;
      Top     := 2;
      Left    := StatusBar1.Left + StatusBar1.Panels.Items[0].Width +
                 StatusBar1.Panels.Items[1].Width + 2;
      Height  := StatusBar1.Height - 2;
      Min     := 1;
      Max     := 10001;
      {$IfDef VER120}
      Smooth  := True;
      {$EndIf}
   end;
   FormInitialWidth := MsgForm.Width;
end;

procedure TMsgform.FormResize( Sender: TObject );
begin
   ProgressBar2.Width := StatusBar1.Width - StatusBar1.Panels.Items[0].Width -
                         StatusBar1.Panels.Items[1].Width - 18;
   ProgressBar1.Width := 177 + (MsgForm.Width - FormInitialWidth);
end;

end.

