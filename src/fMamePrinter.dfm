object FrmMamePrinter: TFrmMamePrinter
  Left = 269
  Top = 223
  BorderStyle = bsDialog
  Caption = 'Print MAME Romdata'
  ClientHeight = 598
  ClientWidth = 830
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
    Top = 349
    Width = 132
    Height = 16
    Caption = 'Mame Emulator to call'
  end
  object MameExtrasLabel: TLabel
    Left = 48
    Top = 408
    Width = 294
    Height = 16
    Caption = 'Mame Extras Dir (required for dats, info and icons)'
    WordWrap = True
  end
  object MameXMLLabel: TLabel
    Left = 48
    Top = 463
    Width = 121
    Height = 16
    Caption = 'Mame XML Location'
    WordWrap = True
  end
  object Label2: TLabel
    Left = 215
    Top = 463
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
    Left = 331
    Top = 461
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
  object MamePrintDescLabel1: TLabel
    Left = 24
    Top = 16
    Width = 747
    Height = 32
    Caption = 
      'Filter the MAME XML List to make a romdata in this folder, and o' +
      'ptional collections of romdatas in subfolders'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    WordWrap = True
  end
  object MamePrintDescLabel2: TLabel
    Left = 24
    Top = 47
    Width = 466
    Height = 19
    Caption = 'Please make/choose an empty source folder to print into'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    WordWrap = True
  end
  object MamePrintDescLabel3: TLabel
    Left = 24
    Top = 79
    Width = 457
    Height = 48
    Caption = 
      'You can run this a number of times in different source folders o' +
      'r subfolders, But don'#39't run this too many times or the number of' +
      ' collections will slow QuickPlay down'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    WordWrap = True
  end
  object GrpFilter: TGroupBox
    Left = 46
    Top = 144
    Width = 435
    Height = 185
    Caption = 'Filters'
    TabOrder = 19
  end
  object CmbMame: TComboBox
    Left = 216
    Top = 346
    Width = 345
    Height = 24
    Style = csDropDownList
    ItemHeight = 16
    TabOrder = 0
  end
  object BtnOK: TButton
    Left = 597
    Top = 549
    Width = 92
    Height = 31
    Caption = '&Go'
    TabOrder = 1
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 720
    Top = 549
    Width = 92
    Height = 31
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 2
  end
  object TxtMameExtrasDirPath: TEdit
    Left = 385
    Top = 405
    Width = 321
    Height = 24
    TabOrder = 3
  end
  object BtnMameExtrasDirFind: TButton
    Left = 729
    Top = 404
    Width = 32
    Height = 27
    Caption = '...'
    TabOrder = 4
    OnClick = BtnMameExtrasDirFindClick
  end
  object TxtMAMEXMLFilePath: TJvFilenameEdit
    Left = 256
    Top = 503
    Width = 505
    Height = 24
    ClipboardCommands = []
    Filter = 'XML files (*.xml)|*.xml|All files (*.*)|*.*'
    ButtonWidth = 27
    TabOrder = 5
  end
  object ChkClones: TCheckBox
    Left = 70
    Top = 240
    Width = 97
    Height = 17
    Hint = 'clones'
    Caption = 'Clones'
    TabOrder = 7
  end
  object ChkBios: TCheckBox
    Left = 70
    Top = 164
    Width = 105
    Height = 17
    Hint = 'bios'
    Caption = 'Bios'
    TabOrder = 8
  end
  object ChkMature: TCheckBox
    Left = 214
    Top = 164
    Width = 97
    Height = 17
    Hint = 'mature'
    Caption = 'Mature'
    TabOrder = 6
  end
  object ChkMess: TCheckBox
    Left = 214
    Top = 200
    Width = 97
    Height = 17
    Hint = 'mess'
    Caption = 'Mess'
    TabOrder = 9
  end
  object ChkMechanical: TCheckBox
    Left = 70
    Top = 280
    Width = 105
    Height = 17
    Hint = 'mechanical'
    Caption = 'Mechanical'
    TabOrder = 10
  end
  object GrpSubfolder: TGroupBox
    Left = 496
    Top = 72
    Width = 313
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
  object ChkCasino: TCheckBox
    Left = 70
    Top = 200
    Width = 97
    Height = 17
    Hint = 'casino'
    Caption = 'Casino'
    TabOrder = 12
  end
  object ChkPrintClub: TCheckBox
    Left = 214
    Top = 280
    Width = 97
    Height = 17
    Hint = 'printclub'
    Caption = 'PrintClub'
    TabOrder = 13
  end
  object ChkSimulator: TCheckBox
    Left = 366
    Top = 200
    Width = 97
    Height = 17
    Hint = 'simulator'
    Caption = 'Simulator'
    TabOrder = 14
  end
  object ChkTableTop: TCheckBox
    Left = 366
    Top = 240
    Width = 97
    Height = 17
    Hint = 'tabletop'
    Caption = 'TableTop'
    TabOrder = 15
  end
  object ChkQuiz: TCheckBox
    Left = 366
    Top = 164
    Width = 97
    Height = 17
    Hint = 'quiz'
    Caption = 'Quiz'
    TabOrder = 16
  end
  object ChkUtilities: TCheckBox
    Left = 366
    Top = 280
    Width = 97
    Height = 17
    Hint = 'utilities'
    Caption = 'Utilities'
    TabOrder = 17
  end
  object ChkPreliminary: TCheckBox
    Left = 214
    Top = 240
    Width = 97
    Height = 17
    Hint = 'prelininary'
    Caption = 'Preliminary'
    TabOrder = 18
  end
end
