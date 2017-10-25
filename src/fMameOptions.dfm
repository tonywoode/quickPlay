object FrmMameOptions: TFrmMameOptions
  Left = 269
  Top = 223
  BorderStyle = bsDialog
  Caption = 'MAME Options'
  ClientHeight = 694
  ClientWidth = 624
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
  object XMLGroupBox: TGroupBox
    Left = 24
    Top = 230
    Width = 577
    Height = 395
    Caption = 'Scan and Find Mame Games and Emulators'
    TabOrder = 5
    object XMLTxtLbl1: TLabel
      Left = 17
      Top = 160
      Width = 544
      Height = 32
      Caption = 
        'Scanning a MAME XML is requried to use the MAME Printing menu op' +
        'tions. Download the MAME XML for your version of Mame from here'
      WordWrap = True
    end
    object XMLTxtLbl4: TLabel
      Left = 19
      Top = 302
      Width = 105
      Height = 16
      Caption = 'Mame XML status'
    end
    object MameXMLLinkLabel: TLabel
      Left = 160
      Top = 214
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
    object XMLTxtLbl13: TLabel
      Left = 17
      Top = 250
      Width = 536
      Height = 23
      Caption = 
        'Download the zip file named "mame{version number}lx.zip", unzip ' +
        'it, and scan it below'
      WordWrap = True
    end
    object lblMAME: TLabel
      Left = 20
      Top = 109
      Width = 132
      Height = 16
      Caption = 'Mame Emulator to call'
    end
    object MameScanLabel1: TLabel
      Left = 19
      Top = 40
      Width = 534
      Height = 49
      Caption = 
        'To use QuickPlay'#39's MAME features, make sure you already have a M' +
        'AME/RetroArch arcade emulator in your emulators list, Select it ' +
        'below to scan and find new emiulators based on it'
      WordWrap = True
    end
    object XMLEdit: TEdit
      Left = 160
      Top = 299
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
      TabOrder = 0
      Text = 'not loaded'
    end
    object BtnXMLScan: TButton
      Left = 178
      Top = 344
      Width = 223
      Height = 41
      Caption = 'Choose XML File and Start Scan'
      TabOrder = 1
      OnClick = BtnXMLScanClick
    end
    object CmbMame: TComboBox
      Left = 173
      Top = 106
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
      TabOrder = 2
    end
  end
  object ExtrasGroupBox: TGroupBox
    Left = 24
    Top = 24
    Width = 577
    Height = 185
    Caption = 'Set Mame Extras Dir'
    TabOrder = 4
    object ExtrasTxtLbl1: TLabel
      Left = 17
      Top = 34
      Width = 543
      Height = 32
      Caption = 
        'Setting the location of the MAME extras directory will allow you' +
        ' to use MAME dats and icons in QuickPlay, and is needed by the M' +
        'ame XML Scanner'
      WordWrap = True
    end
    object ExtrasTxtLbl2: TLabel
      Left = 17
      Top = 94
      Width = 135
      Height = 16
      Caption = 'Mame Extras Directory'
    end
  end
  object MameOptsOk: TButton
    Left = 390
    Top = 645
    Width = 92
    Height = 31
    Caption = '&Ok'
    TabOrder = 0
    OnClick = BtnMameOptsOkClick
  end
  object BtnCancel: TButton
    Left = 509
    Top = 645
    Width = 92
    Height = 31
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object TxtMameExtrasDirPath: TEdit
    Left = 41
    Top = 157
    Width = 422
    Height = 24
    TabOrder = 2
  end
  object BtnMameExtrasDirFind: TButton
    Left = 485
    Top = 156
    Width = 57
    Height = 27
    Caption = 'Select'
    TabOrder = 3
    OnClick = BtnMameExtrasDirFindClick
  end
end
