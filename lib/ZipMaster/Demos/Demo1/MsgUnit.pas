Unit msgunit;

{$INCLUDE '..\..\ZipVers.inc'}

Interface

Uses
    Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
    StdCtrls, ExtCtrls, ComCtrls;

Type
    TMsgform = Class(TForm)
        Panel1: TPanel;
        Panel2: TPanel;
        ProgressBar1: TProgressBar;
        FileBeingZipped: TLabel;
        StatusBar1: TStatusBar;
        Button1: TButton;
        Button2: TButton;
        RichEdit1: TRichEdit;

        Procedure DismissButClick(Sender: TObject);
        Procedure CancelButClick(Sender: TObject);
        Procedure FormCreate(Sender: TObject);
        Procedure FormResize(Sender: TObject);

    PUBLIC
        { Public declarations }
        FormInitialWidth: Integer;

        ProgressBar2: TProgressBar;
    End;

Var
    Msgform: TMsgform;

Implementation

Uses mainunit;

{$R *.DFM}

Procedure TMsgform.DismissButClick(Sender: TObject);
Begin
    Hide;
End;

Procedure TMsgform.CancelButClick(Sender: TObject);
Begin
    If (MainForm.ZipMaster1.ZipBusy Or MainForm.ZipMaster1.UnzBusy) Then
        MainForm.ZipMaster1.Cancel := True
    Else
        Hide;                           { nothing to cancel - assume user wants to close msg window }
End;

Procedure TMsgform.FormCreate(Sender: TObject);
Begin
    ProgressBar2 := TProgressBar.Create(StatusBar1); // Parent will delete it.

{$IFDEF VERD4+}
    ProgressBar1.Smooth := True;
{$ENDIF}
    With ProgressBar2 Do
    Begin
        Parent := StatusBar1;
        Top := 2;
        Left := StatusBar1.Left + StatusBar1.Panels.Items[0].Width +
            StatusBar1.Panels.Items[1].Width + 2;
        Height := StatusBar1.Height - 2;
        Min := 1;
        Max := 10001;
{$IFDEF VERD4+}
        Smooth := True;
{$ENDIF}
    End;
    FormInitialWidth := MsgForm.Width;
End;

Procedure TMsgform.FormResize(Sender: TObject);
Begin
    ProgressBar2.Width := StatusBar1.Width - StatusBar1.Panels.Items[0].Width -
        StatusBar1.Panels.Items[1].Width - 18;
    ProgressBar1.Width := 177 + (MsgForm.Width - FormInitialWidth);
End;

End.

