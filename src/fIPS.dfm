object FrmIPS: TFrmIPS
  Left = 334
  Top = 496
  BorderStyle = bsDialog
  Caption = 'IPS'
  ClientHeight = 118
  ClientWidth = 343
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 46
    Height = 13
    Caption = 'IPS Name'
  end
  object Label2: TLabel
    Left = 32
    Top = 54
    Width = 22
    Height = 13
    Caption = 'Path'
  end
  object Label3: TLabel
    Left = 72
    Top = 32
    Width = 204
    Height = 13
    Caption = '(leave blank for Quickplay to create name)'
  end
  object TxtName: TEdit
    Left = 72
    Top = 5
    Width = 265
    Height = 21
    TabOrder = 0
  end
  object BtnOK: TButton
    Left = 177
    Top = 87
    Width = 76
    Height = 25
    Caption = '&OK'
    Default = True
    TabOrder = 2
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 259
    Top = 87
    Width = 76
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object TxtPath: TJvFilenameEdit
    Left = 72
    Top = 51
    Width = 265
    Height = 21
    OnAfterDialog = TxtPathAfterDialog
    ClipboardCommands = []
    AddQuotes = False
    TabOrder = 1
  end
end
