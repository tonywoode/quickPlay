object AddRomForm: TAddRomForm
  Left = 370
  Top = 252
  BorderStyle = bsDialog
  Caption = 'Add a ROM'
  ClientHeight = 122
  ClientWidth = 396
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lblPath: TLabel
    Left = 24
    Top = 12
    Width = 22
    Height = 13
    Caption = 'Path'
  end
  object lblEmu: TLabel
    Left = 5
    Top = 60
    Width = 42
    Height = 13
    Caption = 'Emulator'
  end
  object CmbEmu: TComboBox
    Left = 72
    Top = 56
    Width = 177
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    Sorted = True
    TabOrder = 1
  end
  object BtnOK: TButton
    Left = 232
    Top = 88
    Width = 75
    Height = 25
    Caption = '&OK'
    Default = True
    ModalResult = 1
    TabOrder = 2
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 312
    Top = 88
    Width = 75
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object ChkScanArchive: TCheckBox
    Left = 72
    Top = 32
    Width = 289
    Height = 17
    Caption = 'Scan inside this archive for ROMs'
    TabOrder = 0
  end
  object TxtPath: TJvFilenameEdit
    Left = 72
    Top = 8
    Width = 321
    Height = 21
    OnBeforeDialog = TxtPathBeforeDialog
    ClipboardCommands = []
    AddQuotes = False
    TabOrder = 4
  end
end
