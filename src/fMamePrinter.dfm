object FrmMamePrinter: TFrmMamePrinter
  Left = 269
  Top = 223
  BorderStyle = bsDialog
  Caption = 'Print MAME Romdata'
  ClientHeight = 570
  ClientWidth = 866
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
    Left = 48
    Top = 293
    Width = 132
    Height = 16
    Caption = 'Mame Emulator to call'
  end
  object MameExtrasLabel: TLabel
    Left = 48
    Top = 352
    Width = 313
    Height = 18
    Caption = 'Mame Extras Dir (required for dats, info and icons)'
    WordWrap = True
  end
  object MameXMLLabel: TLabel
    Left = 48
    Top = 423
    Width = 129
    Height = 15
    Caption = 'Mame XML Location'
    WordWrap = True
  end
  object Label2: TLabel
    Left = 216
    Top = 423
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
  object MameXMLLinkLabel: TLabel
    Left = 336
    Top = 421
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
  object MamePrintDescLabel: TLabel
    Left = 48
    Top = 8
    Width = 433
    Height = 48
    Caption = 
      'Filter the MAME XML List to make a romdata in this folder, and c' +
      'ollection romdatas in subfolders. Too many collections slows Qui' +
      'ckplay down. Please choose an empty source folder.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    WordWrap = True
  end
  object GrpFilter: TGroupBox
    Left = 48
    Top = 72
    Width = 435
    Height = 185
    Caption = 'Filters'
    TabOrder = 19
  end
  object CmbMame: TComboBox
    Left = 216
    Top = 290
    Width = 345
    Height = 24
    Style = csDropDownList
    ItemHeight = 16
    TabOrder = 0
  end
  object BtnOK: TButton
    Left = 597
    Top = 517
    Width = 92
    Height = 31
    Caption = '&Go'
    TabOrder = 1
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 749
    Top = 517
    Width = 92
    Height = 31
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 2
  end
  object TxtMameExtrasDirPath: TEdit
    Left = 385
    Top = 349
    Width = 321
    Height = 24
    TabOrder = 3
  end
  object BtnMameExtrasDirFind: TButton
    Left = 729
    Top = 348
    Width = 32
    Height = 27
    Caption = '...'
    TabOrder = 4
    OnClick = BtnMameExtrasDirFindClick
  end
  object TxtMAMEXMLFilePath: TJvFilenameEdit
    Left = 201
    Top = 458
    Width = 505
    Height = 24
    ClipboardCommands = []
    Filter = 'XML files (*.xml)|*.xml|All files (*.*)|*.*'
    ButtonWidth = 27
    TabOrder = 5
  end
  object ChkClones: TCheckBox
    Left = 72
    Top = 168
    Width = 97
    Height = 17
    Hint = 'clones'
    Caption = 'Clones'
    TabOrder = 7
  end
  object Bios: TCheckBox
    Left = 72
    Top = 92
    Width = 105
    Height = 17
    Hint = 'bios'
    Caption = 'Bios'
    TabOrder = 8
  end
  object ChkMature: TCheckBox
    Left = 216
    Top = 92
    Width = 97
    Height = 17
    Hint = 'mature'
    Caption = 'Mature'
    TabOrder = 6
  end
  object Mess: TCheckBox
    Left = 216
    Top = 128
    Width = 97
    Height = 17
    Hint = 'mess'
    Caption = 'Mess'
    TabOrder = 9
  end
  object Mechanical: TCheckBox
    Left = 72
    Top = 208
    Width = 105
    Height = 17
    Hint = 'mechanical'
    Caption = 'Mechanical'
    TabOrder = 10
  end
  object GrpSubfolder: TGroupBox
    Left = 496
    Top = 32
    Width = 345
    Height = 193
    Caption = 'Subfolder Collections'
    TabOrder = 11
    object ChkGenreSplit: TCheckBox
      Left = 32
      Top = 72
      Width = 121
      Height = 17
      Hint = 'genre'
      Caption = 'Genre'
      TabOrder = 0
    end
    object ChkNPlayersSplit: TCheckBox
      Left = 33
      Top = 113
      Width = 177
      Height = 17
      Hint = 'numplayers'
      Caption = 'Number of Players'
      TabOrder = 1
    end
    object ChkVersionSplit: TCheckBox
      Left = 224
      Top = 72
      Width = 97
      Height = 17
      Hint = 'version'
      Caption = 'Version'
      TabOrder = 2
    end
    object ChkSeriesSplit: TCheckBox
      Left = 224
      Top = 32
      Width = 97
      Height = 17
      Hint = 'series'
      Caption = 'Series'
      TabOrder = 3
    end
    object ChkRatingSplit: TCheckBox
      Left = 31
      Top = 152
      Width = 105
      Height = 17
      Hint = 'rating'
      Caption = 'Rating'
      TabOrder = 4
    end
    object ChkYearSplit: TCheckBox
      Left = 224
      Top = 113
      Width = 97
      Height = 17
      Hint = 'year'
      Caption = 'Year'
      TabOrder = 5
    end
    object ChkCompanySplit: TCheckBox
      Left = 32
      Top = 32
      Width = 129
      Height = 17
      Hint = 'company'
      Caption = 'Company'
      TabOrder = 6
    end
  end
  object Casino: TCheckBox
    Left = 72
    Top = 128
    Width = 97
    Height = 17
    Hint = 'casino'
    Caption = 'Casino'
    TabOrder = 12
  end
  object PrintClub: TCheckBox
    Left = 216
    Top = 208
    Width = 97
    Height = 17
    Hint = 'printclub'
    Caption = 'PrintClub'
    TabOrder = 13
  end
  object Simulator: TCheckBox
    Left = 368
    Top = 128
    Width = 97
    Height = 17
    Hint = 'simulator'
    Caption = 'Simulator'
    TabOrder = 14
  end
  object ChkTableTop: TCheckBox
    Left = 368
    Top = 168
    Width = 97
    Height = 17
    Hint = 'tabletop'
    Caption = 'TableTop'
    TabOrder = 15
  end
  object ChkQuiz: TCheckBox
    Left = 368
    Top = 92
    Width = 97
    Height = 17
    Hint = 'quiz'
    Caption = 'Quiz'
    TabOrder = 16
  end
  object ChkUtilities: TCheckBox
    Left = 368
    Top = 208
    Width = 97
    Height = 17
    Hint = 'utilities'
    Caption = 'Utilities'
    TabOrder = 17
  end
  object ChkPreliminary: TCheckBox
    Left = 216
    Top = 168
    Width = 97
    Height = 17
    Hint = 'prelininary'
    Caption = 'Preliminary'
    TabOrder = 18
  end
end
