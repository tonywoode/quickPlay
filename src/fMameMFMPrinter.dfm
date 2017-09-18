object FrmMameMFMPrinter: TFrmMameMFMPrinter
  Left = 269
  Top = 223
  BorderStyle = bsDialog
  Caption = 'Print Mame File Manager Romdata'
  ClientHeight = 439
  ClientWidth = 561
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
    Top = 136
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
    Top = 207
    Width = 159
    Height = 16
    Caption = 'Mame Extras Dir (for Icons)'
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
    Top = 283
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
    Top = 67
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
    Font.Height = 16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    WordWrap = True
  end
  object MFMLabel: TLabel
    Left = 211
    Top = 36
    Width = 327
    Height = 18
    Cursor = crHandPoint
    Hint = 'right-click to copy to clipboard'
    Align = alCustom
    Caption = 'https://github.com/phweda/MFM/releases'
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
    Left = 180
    Top = 310
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
    Left = 61
    Top = 312
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
  object CmbMame: TComboBox
    Left = 149
    Top = 165
    Width = 389
    Height = 24
    Style = csDropDownList
    ItemHeight = 16
    TabOrder = 0
  end
  object BtnOK: TButton
    Left = 325
    Top = 400
    Width = 92
    Height = 31
    Caption = '&Go'
    TabOrder = 1
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 446
    Top = 400
    Width = 92
    Height = 31
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 2
  end
  object TxtMameExtrasDirPath: TEdit
    Left = 149
    Top = 239
    Width = 332
    Height = 24
    TabOrder = 3
  end
  object BtnMameExtrasDirFind: TButton
    Left = 506
    Top = 238
    Width = 32
    Height = 27
    Caption = '...'
    TabOrder = 4
    OnClick = BtnMameExtrasDirFindClick
  end
  object TxtMAMEXMLFilePath: TJvFilenameEdit
    Left = 149
    Top = 343
    Width = 389
    Height = 24
    ClipboardCommands = []
    Filter = 'XML files (*.xml)|*.xml|All files (*.*)|*.*'
    ButtonWidth = 27
    TabOrder = 5
  end
  object TxtMameFileManagerFilePath: TJvFilenameEdit
    Left = 149
    Top = 103
    Width = 389
    Height = 24
    ClipboardCommands = []
    Filter = 'TXT files (*.txt)|*.txt|All files (*.*)|*.*'
    ButtonWidth = 27
    TabOrder = 6
  end
end
