object FrmMamePrinter: TFrmMamePrinter
  Left = 269
  Top = 223
  BorderStyle = bsDialog
  Caption = 'MAME Print Set'
  ClientHeight = 436
  ClientWidth = 642
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
    Left = 34
    Top = 125
    Width = 132
    Height = 16
    Caption = 'Mame Emulator to call'
  end
  object MameExtrasLabel: TLabel
    Left = 34
    Top = 196
    Width = 123
    Height = 48
    Caption = 'Mame Extras Dir (for system Icons, MameTool etc)'
    WordWrap = True
  end
  object MameXMLLabel: TLabel
    Left = 34
    Top = 260
    Width = 507
    Height = 16
    Caption = 
      'Mame XML Location (download from https://github.com/mamedev/mame' +
      '/releases/)'
    WordWrap = True
  end
  object MameFileManagerLabel: TLabel
    Left = 34
    Top = 337
    Width = 280
    Height = 16
    Caption = 'Optional location of Mame File Manager text file'
    WordWrap = True
  end
  object CmbMame: TComboBox
    Left = 172
    Top = 125
    Width = 315
    Height = 24
    Style = csDropDownList
    ItemHeight = 16
    TabOrder = 0
  end
  object BtnOK: TButton
    Left = 434
    Top = 389
    Width = 92
    Height = 31
    Caption = '&Go'
    TabOrder = 1
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 532
    Top = 389
    Width = 92
    Height = 31
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 2
  end
  object TxtMameExtrasDirPath: TEdit
    Left = 172
    Top = 203
    Width = 269
    Height = 24
    TabOrder = 3
  end
  object BtnMameExtrasDirFind: TButton
    Left = 455
    Top = 202
    Width = 32
    Height = 27
    Caption = '...'
    TabOrder = 4
    OnClick = BtnMameExtrasDirFindClick
  end
  object TxtMAMEXMLFilePath: TJvFilenameEdit
    Left = 133
    Top = 282
    Width = 398
    Height = 24
    ClipboardCommands = []
    Filter = 'XML files (*.xml)|*.xml|All files (*.*)|*.*'
    ButtonWidth = 27
    TabOrder = 5
  end
  object TxtMameFileManagerFilePath: TJvFilenameEdit
    Left = 133
    Top = 359
    Width = 398
    Height = 24
    ClipboardCommands = []
    Filter = 'TXT files (*.txt)|*.txt|All files (*.*)|*.*'
    ButtonWidth = 27
    TabOrder = 6
  end
end
