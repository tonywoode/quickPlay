object ROMexport: TROMexport
  Left = 310
  Top = 127
  BorderStyle = bsDialog
  Caption = 'Export ROMs'
  ClientHeight = 605
  ClientWidth = 573
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 17
  object GroupOutput: TGroupBox
    Left = 6
    Top = 69
    Width = 559
    Height = 231
    Caption = 'Export Type'
    TabOrder = 1
    object RadSelDir: TRadioButton
      Left = 21
      Top = 31
      Width = 315
      Height = 23
      Caption = 'Output Selected Directory'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadEmuClick
    end
    object RadAllDir: TRadioButton
      Left = 21
      Top = 71
      Width = 315
      Height = 22
      Caption = 'Output All Directories'
      TabOrder = 1
      OnClick = RadEmuClick
    end
    object RadEmu: TRadioButton
      Left = 21
      Top = 110
      Width = 316
      Height = 22
      Caption = 'Output ROMs Linked to Emulator'
      TabOrder = 2
      OnClick = RadEmuClick
    end
    object RadMissMame: TRadioButton
      Left = 21
      Top = 188
      Width = 316
      Height = 23
      Caption = 'Output Missing Mame Games'
      TabOrder = 6
      OnClick = RadEmuClick
    end
    object CboEmu: TComboBox
      Left = 324
      Top = 107
      Width = 190
      Height = 25
      Style = csDropDownList
      Enabled = False
      ItemHeight = 17
      Sorted = True
      TabOrder = 3
    end
    object RadSys: TRadioButton
      Left = 21
      Top = 149
      Width = 316
      Height = 22
      Caption = 'Output ROMs For a Specified System'
      TabOrder = 4
      OnClick = RadEmuClick
    end
    object CboSys: TComboBox
      Left = 324
      Top = 146
      Width = 190
      Height = 25
      Style = csDropDownList
      Enabled = False
      ItemHeight = 17
      Sorted = True
      TabOrder = 5
    end
    object CboMame: TComboBox
      Left = 324
      Top = 186
      Width = 190
      Height = 25
      Style = csDropDownList
      Enabled = False
      ItemHeight = 17
      Sorted = True
      TabOrder = 7
    end
  end
  object GrpROMinfo: TGroupBox
    Left = 7
    Top = 309
    Width = 559
    Height = 168
    Caption = 'ROM info to Export'
    TabOrder = 2
    object ChkName: TCheckBox
      Left = 21
      Top = 31
      Width = 295
      Height = 23
      Caption = 'Output ROM Name'
      Checked = True
      State = cbChecked
      TabOrder = 0
    end
    object ChkPath: TCheckBox
      Left = 21
      Top = 61
      Width = 295
      Height = 23
      Caption = 'Output ROM Path'
      TabOrder = 1
    end
    object ChkEmu: TCheckBox
      Left = 21
      Top = 94
      Width = 295
      Height = 22
      Caption = 'Output Linked Emulator'
      TabOrder = 2
      OnClick = ChkEmuClick
    end
    object ChkEmuLinks: TCheckBox
      Left = 38
      Top = 122
      Width = 278
      Height = 22
      Caption = 'Include Links to Emulators'
      Enabled = False
      TabOrder = 3
    end
    object chkYear: TCheckBox
      Left = 324
      Top = 21
      Width = 221
      Height = 22
      Caption = 'Output Year'
      TabOrder = 4
    end
    object chkType: TCheckBox
      Left = 324
      Top = 50
      Width = 221
      Height = 22
      Caption = 'Output Game Type'
      TabOrder = 5
    end
    object chkLanguage: TCheckBox
      Left = 324
      Top = 78
      Width = 232
      Height = 23
      Caption = 'Output Language'
      TabOrder = 6
    end
    object chkRating: TCheckBox
      Left = 324
      Top = 107
      Width = 232
      Height = 22
      Caption = 'Output Rating'
      TabOrder = 7
    end
    object ChkPlayers: TCheckBox
      Left = 324
      Top = 136
      Width = 221
      Height = 22
      Caption = 'Output Players'
      TabOrder = 8
    end
  end
  object BtnOutput: TButton
    Left = 362
    Top = 568
    Width = 98
    Height = 32
    Caption = '&Export'
    Default = True
    TabOrder = 4
    OnClick = BtnOutputClick
  end
  object BtnClose: TButton
    Left = 467
    Top = 568
    Width = 98
    Height = 32
    Caption = '&Close'
    ModalResult = 1
    TabOrder = 5
  end
  object grpOtherOptions: TGroupBox
    Left = 10
    Top = 486
    Width = 556
    Height = 70
    Caption = 'Export Options'
    TabOrder = 3
    object ChkClose: TCheckBox
      Left = 320
      Top = 31
      Width = 221
      Height = 23
      Caption = 'Close Form when Done'
      TabOrder = 0
    end
    object ChkLaunch: TCheckBox
      Left = 21
      Top = 31
      Width = 284
      Height = 23
      Caption = 'Auto-Launch Output File'
      Checked = True
      State = cbChecked
      TabOrder = 1
    end
  end
  object GrpFormat: TGroupBox
    Left = 10
    Top = 4
    Width = 556
    Height = 59
    Caption = 'Export Format'
    TabOrder = 0
    object radhtml: TRadioButton
      Left = 21
      Top = 22
      Width = 118
      Height = 22
      Caption = 'XHTML'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = radhtmlClick
    end
    object RadXML: TRadioButton
      Left = 188
      Top = 22
      Width = 127
      Height = 22
      Caption = 'XML'
      TabOrder = 1
      OnClick = RadXMLClick
    end
    object RadText: TRadioButton
      Left = 345
      Top = 22
      Width = 179
      Height = 22
      Caption = 'Text (cvs)'
      TabOrder = 2
      OnClick = RadTextClick
    end
  end
  object SaveDialog: TSaveDialog
    Filter = 'Html File (*.html)|*.html'
    Left = 296
    Top = 60
  end
end
