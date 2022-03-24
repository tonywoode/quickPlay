Unit sfxunit;

{$INCLUDE ZipVers.inc}

Interface

Uses
    Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
    StdCtrls, ExtCtrls, ZipMstr, Buttons, ComCtrls, ShlObj, ShellAPI, ImgList
//{$IFDEF VERD4+}                         // if Delphi v4.xx
//    , ImgList
//{$ENDIF}
    ;

Type
    TMakeSFX = Class(TForm)
        Panel1: TPanel;
        Panel2: TPanel;
        CmdLineCB: TCheckBox;
        FileListCB: TCheckBox;
        HideOverWriteCB: TCheckBox;
        AutoRunCB: TCheckBox;
        NoMsgShowCB: TCheckBox;
        DfltOverWriteGrp: TRadioGroup;
        OkCancelRB: TRadioButton;
        YesNoRB: TRadioButton;
        OkBttnRB: TRadioButton;
        DefIconRB: TRadioButton;
        AutoIconRB: TRadioButton;
        OrigIconRB: TRadioButton;
        ExecBut: TButton;
        CancelBut: TButton;
        BitBtn1: TBitBtn;
        BitBtn2: TBitBtn;
        SFXPage: TPageControl;
        TabSheet1: TTabSheet;
        TabSheet2: TTabSheet;
        TabSheet3: TTabSheet;
        TabSheet4: TTabSheet;
        TabSheet5: TTabSheet;
        Label9: TLabel;
        Label12: TLabel;
        Label2: TLabel;
        Label1: TLabel;
        IconIndexLabel: TLabel;
        MsgEdit: TEdit;
        CaptionEdit: TEdit;
        CommandEdit: TEdit;
        IconEdit: TEdit;
        IconIndexEdit: TEdit;
        Memo2: TMemo;
        Memo3: TMemo;
        Memo4: TMemo;
        Memo1: TMemo;
        GroupBox1: TGroupBox;
        GroupBox2: TGroupBox;
        Image1: TImage;
        OpenDialog1: TOpenDialog;
        ImageList1: TImageList;
        IconIndexUD: TUpDown;
        DirectoryEdit: TComboBox;

        Procedure FormShow(Sender: TObject);
        Procedure ExecButClick(Sender: TObject);
        Procedure BitBtn1Click(Sender: TObject);
        Procedure BitBtn2Click(Sender: TObject);
        Procedure CancelButClick(Sender: TObject);
        Procedure AutoRunCBClick(Sender: TObject);
        Procedure DefIconRBClick(Sender: TObject);
        Procedure IconEditKeyPress(Sender: TObject; Var Key: Char);
        Procedure IconIndexUDClick(Sender: TObject; Button: TUDBtnType);

    PUBLIC
        Procedure LoadCustomIcon(IconPath: String; IconIndex: Integer);
    End;

Var
    MakeSFX: TMakeSFX;
    IconDir: String;

Implementation

Uses mainunit;

{$R *.DFM}

Procedure TMakeSFX.ExecButClick(Sender: TObject);
Begin
    With Mainform.ZipMaster1 Do
    Begin
        If CmdLineCB.Checked Then
            SFXOptions := SFXOptions + [SFXAskCmdLine]
        Else
            SFXOptions := SFXOptions - [SFXAskCmdLine];
        If FileListCB.Checked Then
            SFXOptions := SFXOptions + [SFXAskFiles]
        Else
            SFXOptions := SFXOptions - [SFXAskFiles];
        If HideOverWriteCB.Checked Then
            SFXOptions := SFXOptions + [SFXHideOverWriteBox]
        Else
            SFXOptions := SFXOptions - [SFXHideOverWriteBox];
        If AutoRunCB.Checked Then
            SFXOptions := SFXOptions + [SFXAutoRun]
        Else
            SFXOptions := SFXOptions - [SFXAutoRun];
        If NoMsgShowCB.Checked Then
            SFXOptions := SFXOptions + [SFXNoSuccessMsg]
        Else
            SFXOptions := SFXOptions - [SFXNoSuccessMsg];

        If DfltOverWriteGrp.ItemIndex = 0 Then
            SFXOverWriteMode := ovrConfirm;
        If DfltOverWriteGrp.ItemIndex = 1 Then
            SFXOverWriteMode := ovrAlways;
        If DfltOverWriteGrp.ItemIndex = 2 Then
            SFXOverWriteMode := ovrNever;

        SFXCaption := CaptionEdit.Text;
        SFXDefaultDir := DirectoryEdit.Text;
        SFXCommandLine := CommandEdit.Text;
        SFXMessage := '';
        If OkCancelRB.Checked Then
            SFXMessage := #1;
        If YesNoRB.Checked Then
            SFXMessage := #2;
        SFXMessage := SFXMessage + MsgEdit.Text;
    End;
    Mainform.DoIt := True;
    Close;
End;

Procedure TMakeSFX.CancelButClick(Sender: TObject);
Begin
    Mainform.DoIt := False;
    Close;
End;

Procedure TMakeSFX.BitBtn1Click(Sender: TObject);
Var
    TempStr: String;
Begin
    TempStr := DirectoryEdit.Text;
    MainForm.AskDirDialog(MakeSFX.Handle, TempStr);
    DirectoryEdit.Text := TempStr;
End;

Procedure TMakeSFX.FormShow(Sender: TObject);
Begin
    With MainForm.ZipMaster1 Do
    Begin
        If SFXAskCmdLine In SFXOptions Then
            CMDLineCB.Checked := True
        Else
            CMDLineCB.Checked := False;
        If SFXAskFiles In SFXOptions Then
            FileListCB.Checked := True
        Else
            FileListCB.Checked := False;
        If SFXHideOverWriteBox In SFXOptions Then
            HideOverWriteCB.Checked := True
        Else
            HideOverWriteCB.Checked := False;
        If SFXAutoRun In SFXOptions Then
            AutoRunCB.Checked := True
        Else
            AutoRunCB.Checked := False;
        If SFXNoSuccessMsg In SFXOptions Then
            NoMsgShowCB.Checked := True
        Else
            NoMsgShowCB.Checked := False;

        Case SFXOverWriteMode Of
            ovrConfirm: DfltOverWriteGrp.ItemIndex := 0;
            ovrAlways: DfltOverWriteGrp.ItemIndex := 1;
            ovrNever: DfltOverWriteGrp.ItemIndex := 2;
        End;

        CaptionEdit.Text := SFXCaption;
        DirectoryEdit.Text := SFXDefaultDir;
        CommandEdit.Text := SFXCommandLine;
        If (Length(SFXMessage) > 0) And ((SFXMessage[1] = #1) Or (SFXMessage[1] = #2)) Then
        Begin
            If SFXMessage[1] = #1 Then
                OkCancelRB.Checked := True
            Else
                YesNoRB.Checked := True;
            MsgEdit.Text := Copy(SFXMessage, 2, Length(SFXMessage) - 1);
        End
        Else
        Begin
            MsgEdit.Text := SFXMessage;
            OkBttnRB.Checked := True;
        End;
    End;

    If ImageList1.Count = 3 Then
        ImageList1.Delete(2);
    If IconEdit.Text = '' Then
    Begin
        If MainForm.ZipMaster1.SFXIcon.Empty Then
        Begin
            ImageList1.GetIcon(Integer(AutoRunCB.Checked), Image1.Picture.Icon);
            MainForm.ZipMaster1.SFXIcon := Image1.Picture.Icon;
        End
        Else
        Begin
            ImageList1.AddIcon(MainForm.ZipMaster1.SFXIcon);
            OrigIconRB.Checked := True;
        End;
    End;
    If ImageList1.Count = 3 Then
        OrigIconRB.Enabled := True
    Else
        OrigIconRB.Enabled := False
End;

Procedure TMakeSFX.BitBtn2Click(Sender: TObject);
Begin
    If IconDir = '' Then
        MainForm.GetSpecialFolder(CSIDL_DESKTOPDIRECTORY, IconDir);
    With OpenDialog1 Do
    Begin
        InitialDir := IconDir;
        If Execute Then
        Begin
            IconDir := ExtractFilePath(FileName);
            IconEdit.Text := FileName;
            DefIconRB.Checked := false;
            AutoIconRB.Checked := false;
            If UpperCase(ExtractFileExt(FileName)) <> 'ICO' Then
            Begin
                LoadCustomIcon(FileName, StrToIntDef(IconIndexEdit.Text, 0));
                IconIndexLabel.Enabled := True;
                IconIndexEdit.Enabled := True;
                IconIndexUD.Enabled := True;
                IconIndexEdit.Color := clWindow;
            End
            Else
            Begin
                Image1.Picture.Icon.LoadFromFile(FileName);
                IconIndexEdit.Text := '0';
                IconIndexLabel.Enabled := False;
                IconIndexEdit.Enabled := False;
                IconIndexUD.Enabled := False;
                IconIndexEdit.Color := clBtnFace;
                MainForm.ZipMaster1.SFXIcon := Image1.Picture.Icon;
            End;
        End;
    End;
End;

Procedure TMakeSFX.AutoRunCBClick(Sender: TObject);
Begin
    If IconEdit.Text = '' Then
    Begin
        ImageList1.GetIcon(Integer(AutoRunCB.Checked), Image1.Picture.Icon);
        MainForm.ZipMaster1.SFXIcon := Image1.Picture.Icon;
    End;
End;

Procedure TMakeSFX.DefIconRBClick(Sender: TObject);
Begin
    ImageList1.GetIcon(TRadioButton(Sender).Tag, Image1.Picture.Icon);
    MainForm.ZipMaster1.SFXIcon := Image1.Picture.Icon;
    IconEdit.Text := '';
    IconIndexEdit.Text := '0';
    IconIndexLabel.Enabled := False;
    IconIndexEdit.Enabled := False;
    IconIndexUD.Enabled := False;
    IconIndexEdit.Color := clBtnFace;
End;

Procedure TMakeSFX.LoadCustomIcon(IconPath: String; IconIndex: Integer);
Var
    IconHandle: THandle;
Begin
    Image1.Picture.Icon.ReleaseHandle();
    MainForm.ZipMaster1.SFXIcon.ReleaseHandle();
    IconHandle := ExtractIcon(hInstance, PChar(IconPath), IconIndex);
    If (IconHandle <> 0) And (IconHandle <> 1) Then
    Begin
        Image1.Picture.Icon.Handle := IconHandle;
        MainForm.ZipMaster1.SFXIcon.Handle := IconHandle;
    End;
End;

Procedure TMakeSFX.IconIndexUDClick(Sender: TObject; Button: TUDBtnType);
Begin
    LoadCustomIcon(IconEdit.Text, StrToIntDef(IconIndexEdit.Text, 0));
End;

Procedure TMakeSFX.IconEditKeyPress(Sender: TObject; Var Key: Char);
Begin
    If FileExists(IconEdit.Text) Then
        LoadCustomIcon(IconEdit.Text, StrToIntDef(IconIndexEdit.Text, 0));
End;

End.
