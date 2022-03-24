Unit extrunit;

{$I zipvers.inc}
{$IFDEF VERD6up}
{$WARN UNIT_PLATFORM OFF}
{$WARN SYMBOL_PLATFORM OFF}
{$ENDIF}

Interface

Uses
    Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
    StdCtrls, ExtCtrls, FileCtrl, ShlObj;

Type
    TExtract = Class(TForm)
        Panel1: TPanel;
        Panel2: TPanel;
        Panel3: TPanel;
        OKBut: TButton;
        CancelBut: TButton;
        RadioGroup1: TRadioGroup;
        RadioGroup2: TRadioGroup;
        RadioGroup3: TRadioGroup;
        DriveComboBox1: TDriveComboBox;
        DirectoryListBox1: TDirectoryListBox;

        Procedure OKButClick(Sender: TObject);
        Procedure CancelButClick(Sender: TObject);
        Procedure FormActivate(Sender: TObject);
        Procedure FormCreate(Sender: TObject);
    End;

Var
    Extract: TExtract;

Implementation

Uses MainUnit;

{$R *.DFM}

Procedure TExtract.OKButClick(Sender: TObject);
Begin
    MainUnit.Canceled := False;
    MainUnit.ExtractDir := DirectoryListBox1.Directory;
    If RadioGroup1.ItemIndex = 0 Then
        MainUnit.ExpandDirs := False
    Else
        MainUnit.ExpandDirs := True;
    If RadioGroup2.ItemIndex = 0 Then
        MainUnit.Overwr := False
    Else
        MainUnit.Overwr := True;
    If RadioGroup3.ItemIndex = 0 Then
        MainUnit.AllFiles := True
    Else
        MainUnit.AllFiles := False;
    Close;
End;

Procedure TExtract.CancelButClick(Sender: TObject);
Begin
    MainUnit.ExtractDir := '';
    Close;
End;

Procedure TExtract.FormActivate(Sender: TObject);
Begin
    MainUnit.Canceled := True;          { default }
End;

Procedure TExtract.FormCreate(Sender: TObject);
Var
    SpecFolder: String;
Begin
    SpecFolder := '';

    MainForm.GetSpecialFolder(CSIDL_DESKTOPDIRECTORY, SpecFolder);
    DriveComboBox1.Drive := ExtractFileDrive(SpecFolder)[1];
    DirectoryListBox1.Directory := ExtractFilePath(SpecFolder);
End;

End.
