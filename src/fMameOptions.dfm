object FrmMameOptions: TFrmMameOptions
  Left = 269
  Top = 223
  BorderStyle = bsDialog
  Caption = 'MAME Options'
  ClientHeight = 561
  ClientWidth = 610
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
    Top = 232
    Width = 561
    Height = 260
    Caption = 'Set Mame XML Location'
    TabOrder = 5
    object XMLTxtLbl1: TLabel
      Left = 10
      Top = 32
      Width = 508
      Height = 32
      Caption = 
        'Scanning a MAME XML is requried to use the MAME Printing menu op' +
        'tions. Download the MAME XML for your version of Mame from here'
      WordWrap = True
    end
    object XMLTxtLbl4: TLabel
      Left = 17
      Top = 158
      Width = 105
      Height = 16
      Caption = 'Mame XML status'
    end
    object MameXMLLinkLabel: TLabel
      Left = 92
      Top = 78
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
      Left = 10
      Top = 114
      Width = 504
      Height = 16
      Caption = 
        'download the zip file named "mame{version number}lx.zip", unzip ' +
        'it, and scan it below'
    end
    object XMLEdit: TEdit
      Left = 164
      Top = 155
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
      Left = 164
      Top = 200
      Width = 205
      Height = 41
      Caption = 'Choose XML File and Scan'
      TabOrder = 1
      OnClick = BtnXMLScanClick
    end
  end
  object ExtrasGroupBox: TGroupBox
    Left = 24
    Top = 24
    Width = 561
    Height = 185
    Caption = 'Set Mame Extras Dir'
    TabOrder = 4
    object ExtrasTxtLbl1: TLabel
      Left = 3
      Top = 34
      Width = 478
      Height = 32
      Caption = 
        'Setting the location of the MAME extras directory will allow you' +
        ' to use MAME dats and icons in QuickPlay, and is needed by the M' +
        'ame XML Scanner'
      WordWrap = True
    end
    object ExtrasTxtLbl2: TLabel
      Left = 10
      Top = 86
      Width = 135
      Height = 16
      Caption = 'Mame Extras Directory'
      WordWrap = True
    end
  end
  object MameOptsOk: TButton
    Left = 382
    Top = 509
    Width = 92
    Height = 31
    Caption = '&Ok'
    TabOrder = 0
    OnClick = BtnMameOptsOkClick
  end
  object BtnCancel: TButton
    Left = 493
    Top = 509
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
