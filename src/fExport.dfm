object ROMexport: TROMexport
  Left = 310
  Top = 127
  BorderStyle = bsDialog
  Caption = 'Export ROMs'
  ClientHeight = 463
  ClientWidth = 438
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupOutput: TGroupBox
    Left = 5
    Top = 52
    Width = 428
    Height = 177
    Caption = 'Export Type'
    TabOrder = 1
    object RadSelDir: TRadioButton
      Left = 16
      Top = 24
      Width = 241
      Height = 17
      Caption = 'Output Selected Directory'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadEmuClick
    end
    object RadAllDir: TRadioButton
      Left = 16
      Top = 54
      Width = 241
      Height = 17
      Caption = 'Output All Directories'
      TabOrder = 1
      OnClick = RadEmuClick
    end
    object RadEmu: TRadioButton
      Left = 16
      Top = 84
      Width = 242
      Height = 17
      Caption = 'Output ROMs Linked to Emulator'
      TabOrder = 2
      OnClick = RadEmuClick
    end
    object RadMissMame: TRadioButton
      Left = 16
      Top = 144
      Width = 242
      Height = 17
      Caption = 'Output Missing Mame Games'
      TabOrder = 6
      OnClick = RadEmuClick
    end
    object CboEmu: TComboBox
      Left = 248
      Top = 82
      Width = 145
      Height = 21
      Style = csDropDownList
      Enabled = False
      ItemHeight = 13
      Sorted = True
      TabOrder = 3
    end
    object RadSys: TRadioButton
      Left = 16
      Top = 114
      Width = 242
      Height = 17
      Caption = 'Output ROMs For a Specified System'
      TabOrder = 4
      OnClick = RadEmuClick
    end
    object CboSys: TComboBox
      Left = 248
      Top = 112
      Width = 145
      Height = 21
      Style = csDropDownList
      Enabled = False
      ItemHeight = 13
      Sorted = True
      TabOrder = 5
    end
    object CboMame: TComboBox
      Left = 248
      Top = 142
      Width = 145
      Height = 21
      Style = csDropDownList
      Enabled = False
      ItemHeight = 13
      Sorted = True
      TabOrder = 7
    end
  end
  object GrpROMinfo: TGroupBox
    Left = 5
    Top = 236
    Width = 428
    Height = 129
    Caption = 'ROM info to Export'
    TabOrder = 2
    object ChkName: TCheckBox
      Left = 16
      Top = 24
      Width = 226
      Height = 17
      Caption = 'Output ROM Name'
      Checked = True
      State = cbChecked
      TabOrder = 0
    end
    object ChkPath: TCheckBox
      Left = 16
      Top = 47
      Width = 226
      Height = 17
      Caption = 'Output ROM Path'
      TabOrder = 1
    end
    object ChkEmu: TCheckBox
      Left = 16
      Top = 72
      Width = 226
      Height = 17
      Caption = 'Output Linked Emulator'
      TabOrder = 2
      OnClick = ChkEmuClick
    end
    object ChkEmuLinks: TCheckBox
      Left = 29
      Top = 93
      Width = 213
      Height = 17
      Caption = 'Include Links to Emulators'
      Enabled = False
      TabOrder = 3
    end
    object chkYear: TCheckBox
      Left = 248
      Top = 16
      Width = 169
      Height = 17
      Caption = 'Output Year'
      TabOrder = 4
    end
    object chkType: TCheckBox
      Left = 248
      Top = 38
      Width = 169
      Height = 17
      Caption = 'Output Game Type'
      TabOrder = 5
    end
    object chkLanguage: TCheckBox
      Left = 248
      Top = 60
      Width = 177
      Height = 17
      Caption = 'Output Language'
      TabOrder = 6
    end
    object chkRating: TCheckBox
      Left = 248
      Top = 82
      Width = 177
      Height = 17
      Caption = 'Output Rating'
      TabOrder = 7
    end
    object ChkPlayers: TCheckBox
      Left = 248
      Top = 104
      Width = 169
      Height = 17
      Caption = 'Output Players'
      TabOrder = 8
    end
  end
  object BtnOutput: TButton
    Left = 277
    Top = 434
    Width = 75
    Height = 25
    Caption = '&Export'
    Default = True
    TabOrder = 4
    OnClick = BtnOutputClick
  end
  object BtnClose: TButton
    Left = 357
    Top = 434
    Width = 75
    Height = 25
    Caption = '&Close'
    ModalResult = 1
    TabOrder = 5
  end
  object grpOtherOptions: TGroupBox
    Left = 8
    Top = 372
    Width = 425
    Height = 53
    Caption = 'Export Options'
    TabOrder = 3
    object ChkClose: TCheckBox
      Left = 245
      Top = 24
      Width = 169
      Height = 17
      Caption = 'Close Form when Done'
      TabOrder = 0
    end
    object ChkLaunch: TCheckBox
      Left = 16
      Top = 24
      Width = 217
      Height = 17
      Caption = 'Auto-Launch Output File'
      Checked = True
      State = cbChecked
      TabOrder = 1
    end
  end
  object GrpFormat: TGroupBox
    Left = 8
    Top = 3
    Width = 425
    Height = 45
    Caption = 'Export Format'
    TabOrder = 0
    object radhtml: TRadioButton
      Left = 16
      Top = 17
      Width = 90
      Height = 17
      Caption = 'XHTML'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = radhtmlClick
    end
    object RadXML: TRadioButton
      Left = 144
      Top = 17
      Width = 97
      Height = 17
      Caption = 'XML'
      TabOrder = 1
      OnClick = RadXMLClick
    end
    object RadText: TRadioButton
      Left = 264
      Top = 17
      Width = 137
      Height = 17
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
