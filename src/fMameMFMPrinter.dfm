object FrmMameMFMPrinter: TFrmMameMFMPrinter
  Left = 269
  Top = 223
  BorderStyle = bsDialog
  Caption = 'Print Mame File Manager Romdata'
  ClientHeight = 331
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
  end
  object MameXMLLabel: TLabel
    Left = 33
    Top = 255
    Width = 107
    Height = 16
    Caption = 'Mame XML Status'
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
    Top = 278
    Width = 92
    Height = 31
    Caption = '&Go'
    TabOrder = 1
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 461
    Top = 278
    Width = 92
    Height = 31
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 2
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
    TabOrder = 3
  end
  object XMLEdit: TEdit
    Left = 199
    Top = 245
    Width = 354
    Height = 27
    AutoSelect = False
    BevelInner = bvNone
    BorderStyle = bsNone
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = 25
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentColor = True
    ParentFont = False
    ReadOnly = True
    TabOrder = 4
    Text = 'not loaded'
  end
end
