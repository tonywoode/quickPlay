object FrmMameMFMPrinter: TFrmMameMFMPrinter
  Left = 269
  Top = 223
  BorderStyle = bsDialog
  Caption = 'Print Mame File Manager Romdata'
  ClientHeight = 467
  ClientWidth = 583
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object lblMAME: TLabel
    Left = 36
    Top = 168
    Width = 132
    Height = 16
    Caption = 'Mame Emulator to call'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 14
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object MameExtrasLabel: TLabel
    Left = 36
    Top = 239
    Width = 294
    Height = 16
    Caption = 'Mame Extras Dir (required for dats, info and icons)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 14
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    WordWrap = True
  end
  object MameXMLLabel: TLabel
    Left = 36
    Top = 315
    Width = 121
    Height = 16
    Caption = 'Mame XML Location'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 14
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    WordWrap = True
  end
  object MameFileManagerLabel: TLabel
    Left = 36
    Top = 99
    Width = 213
    Height = 16
    Caption = 'Mame File Manager text file location'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 14
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    WordWrap = True
  end
  object MFMDescLabel: TLabel
    Left = 15
    Top = 8
    Width = 357
    Height = 16
    Caption = 'Import a Mame File Manager TXT file into this folder'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    WordWrap = True
  end
  object MFMLabel: TLabel
    Left = 217
    Top = 37
    Width = 336
    Height = 18
    Cursor = crHandPoint
    Hint = 'right-click to copy to clipboard'
    Align = alCustom
    Caption = 'https://github.com/phweda/MFM/releases/'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    OnClick = MFMLabelClick
  end
  object MameXMLLinkLabel: TLabel
    Left = 195
    Top = 342
    Width = 358
    Height = 18
    Cursor = crHandPoint
    Hint = 'right-click to copy to clipboard'
    Align = alCustom
    Caption = 'https://github.com/mamedev/mame/releases/'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    OnClick = MameXMLLinkLabelClick
  end
  object Label2: TLabel
    Left = 85
    Top = 344
    Width = 96
    Height = 16
    Caption = 'Download from: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 14
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    WordWrap = True
  end
  object MamePrintDescLabel2: TLabel
    Left = 15
    Top = 69
    Width = 392
    Height = 16
    Caption = 'Please make/choose an empty source folder to print into'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    WordWrap = True
  end
  object CmbMame: TComboBox
    Left = 85
    Top = 200
    Width = 348
    Height = 24
    Style = csDropDownList
    ItemHeight = 16
    TabOrder = 0
  end
  object BtnOK: TButton
    Left = 357
    Top = 419
    Width = 92
    Height = 31
    Caption = '&Go'
    TabOrder = 1
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 461
    Top = 419
    Width = 92
    Height = 31
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 2
  end
  object TxtMameExtrasDirPath: TEdit
    Left = 85
    Top = 271
    Width = 420
    Height = 24
    TabOrder = 3
  end
  object BtnMameExtrasDirFind: TButton
    Left = 521
    Top = 270
    Width = 32
    Height = 27
    Caption = '...'
    TabOrder = 4
    OnClick = BtnMameExtrasDirFindClick
  end
  object TxtMAMEXMLFilePath: TJvFilenameEdit
    Left = 85
    Top = 378
    Width = 468
    Height = 24
    ClipboardCommands = []
    AddQuotes = False
    Filter = 'XML files (*.xml)|*.xml|All files (*.*)|*.*'
    ButtonWidth = 27
    TabOrder = 5
  end
  object TxtMameFileManagerFilePath: TJvFilenameEdit
    Left = 85
    Top = 121
    Width = 468
    Height = 24
    ClipboardCommands = []
    AddQuotes = False
    Filter = 'TXT files (*.txt)|*.txt|All files (*.*)|*.*'
    ButtonWidth = 27
    TabOrder = 6
  end
end
