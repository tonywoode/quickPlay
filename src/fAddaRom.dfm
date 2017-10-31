object AddRomForm: TAddRomForm
  Left = 370
  Top = 252
  BorderStyle = bsDialog
  Caption = 'Add a ROM'
  ClientHeight = 160
  ClientWidth = 694
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 17
  object lblPath: TLabel
    Left = 31
    Top = 16
    Width = 28
    Height = 17
    Caption = 'Path'
  end
  object lblEmu: TLabel
    Left = 7
    Top = 78
    Width = 55
    Height = 17
    Caption = 'Emulator'
  end
  object CmbEmu: TComboBox
    Left = 94
    Top = 73
    Width = 571
    Height = 25
    Style = csDropDownList
    ItemHeight = 17
    Sorted = True
    TabOrder = 1
  end
  object BtnOK: TButton
    Left = 455
    Top = 115
    Width = 98
    Height = 33
    Caption = '&OK'
    Default = True
    ModalResult = 1
    TabOrder = 2
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 567
    Top = 115
    Width = 98
    Height = 33
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object ChkScanArchive: TCheckBox
    Left = 94
    Top = 42
    Width = 378
    Height = 22
    Caption = 'Scan inside this archive for ROMs'
    TabOrder = 0
  end
  object TxtPath: TJvFilenameEdit
    Left = 94
    Top = 10
    Width = 571
    Height = 25
    OnBeforeDialog = TxtPathBeforeDialog
    ClipboardCommands = []
    AddQuotes = False
    ButtonWidth = 27
    TabOrder = 4
  end
end
