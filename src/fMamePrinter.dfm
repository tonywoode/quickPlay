object FrmMamePrinter: TFrmMamePrinter
  Left = 269
  Top = 223
  BorderStyle = bsDialog
  Caption = 'Print MAME Romdata'
  ClientHeight = 474
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
  object MameXMLLabel: TLabel
    Left = 48
    Top = 399
    Width = 107
    Height = 16
    Caption = 'Mame XML Status'
  end
  object MamePrintDescLabel1: TLabel
    Left = 24
    Top = 16
    Width = 743
    Height = 16
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
  object MamePrintDescLabel3: TLabel
    Left = 24
    Top = 79
    Width = 437
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
    Height = 169
    Caption = 'Exclude Filters'
    TabOrder = 16
  end
  object CmbMame: TComboBox
    Left = 216
    Top = 346
    Width = 345
    Height = 24
    Style = csDropDownList
    Color = clMenu
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 16
    ParentFont = False
    TabOrder = 0
  end
  object BtnOK: TButton
    Left = 584
    Top = 421
    Width = 92
    Height = 31
    Caption = '&Go'
    TabOrder = 1
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 704
    Top = 421
    Width = 92
    Height = 31
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 2
  end
  object ChkClones: TCheckBox
    Left = 70
    Top = 240
    Width = 97
    Height = 17
    Hint = 'clones'
    Caption = 'Clones'
    Checked = True
    State = cbChecked
    TabOrder = 4
  end
  object ChkBios: TCheckBox
    Left = 70
    Top = 164
    Width = 105
    Height = 17
    Hint = 'bios'
    Caption = 'Bios'
    Checked = True
    State = cbChecked
    TabOrder = 5
  end
  object ChkMature: TCheckBox
    Left = 214
    Top = 164
    Width = 97
    Height = 17
    Hint = 'mature'
    Caption = 'Mature'
    Checked = True
    State = cbChecked
    TabOrder = 3
  end
  object ChkMess: TCheckBox
    Left = 214
    Top = 200
    Width = 97
    Height = 17
    Hint = 'mess'
    Caption = 'Mess'
    Checked = True
    State = cbChecked
    TabOrder = 6
  end
  object ChkMechanical: TCheckBox
    Left = 70
    Top = 280
    Width = 105
    Height = 17
    Hint = 'mechanical'
    Caption = 'Mechanical'
    Checked = True
    State = cbChecked
    TabOrder = 7
  end
  object GrpSubfolder: TGroupBox
    Left = 496
    Top = 72
    Width = 313
    Height = 193
    Caption = 'Subfolder Collections'
    TabOrder = 8
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
    Checked = True
    State = cbChecked
    TabOrder = 9
  end
  object ChkPrintClub: TCheckBox
    Left = 214
    Top = 280
    Width = 97
    Height = 17
    Hint = 'printclub'
    Caption = 'PrintClub'
    Checked = True
    State = cbChecked
    TabOrder = 10
  end
  object ChkSimulator: TCheckBox
    Left = 366
    Top = 200
    Width = 97
    Height = 17
    Hint = 'simulator'
    Caption = 'Simulator'
    Checked = True
    State = cbChecked
    TabOrder = 11
  end
  object ChkTableTop: TCheckBox
    Left = 366
    Top = 240
    Width = 97
    Height = 17
    Hint = 'tabletop'
    Caption = 'TableTop'
    Checked = True
    State = cbChecked
    TabOrder = 12
  end
  object ChkQuiz: TCheckBox
    Left = 366
    Top = 164
    Width = 97
    Height = 17
    Hint = 'quiz'
    Caption = 'Quiz'
    Checked = True
    State = cbChecked
    TabOrder = 13
  end
  object ChkUtilities: TCheckBox
    Left = 366
    Top = 280
    Width = 97
    Height = 17
    Hint = 'utilities'
    Caption = 'Utilities'
    Checked = True
    State = cbChecked
    TabOrder = 14
  end
  object ChkPreliminary: TCheckBox
    Left = 214
    Top = 240
    Width = 97
    Height = 17
    Hint = 'prelininary'
    Caption = 'Preliminary'
    Checked = True
    State = cbChecked
    TabOrder = 15
  end
  object XMLEdit: TEdit
    Left = 214
    Top = 389
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
    TabOrder = 17
    Text = 'not loaded'
  end
end
