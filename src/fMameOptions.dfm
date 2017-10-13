object FrmMameOptions: TFrmMameOptions
  Left = 269
  Top = 223
  BorderStyle = bsDialog
  Caption = 'MAME Options'
  ClientHeight = 619
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
    Top = 280
    Width = 561
    Height = 260
    Caption = 'Set Mame XML Location'
    TabOrder = 7
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
      Width = 128
      Height = 19
      Caption = 'Mame XML status:'
      WordWrap = True
    end
    object XMLTxtLbl2: TLabel
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
    end
    object XMLTxtLbl13: TLabel
      Left = 34
      Top = 114
      Width = 454
      Height = 16
      Caption = 
        '(download the zip file named "mame{version number}lx.zip" and th' +
        'en unzip it)'
    end
    object XMLEdit: TEdit
      Left = 172
      Top = 150
      Width = 365
      Height = 44
      AutoSelect = False
      BevelInner = bvNone
      BorderStyle = bsNone
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -30
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentColor = True
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
      Text = 'not loaded'
    end
  end
  object ExtrasGroupBox: TGroupBox
    Left = 24
    Top = 17
    Width = 561
    Height = 257
    Caption = 'Set Mame Extras Dir'
    TabOrder = 6
    object ExtrasTxtLbl1: TLabel
      Left = 10
      Top = 42
      Width = 478
      Height = 32
      Caption = 
        'Setting the location of the MAME extras directory will allow you' +
        ' to use MAME dats and icons in QuickPlay, and is required by the' +
        ' MAME Printing menu items'
      WordWrap = True
    end
    object ExtrasTxtLbl2: TLabel
      Left = 17
      Top = 110
      Width = 184
      Height = 19
      Caption = 'Mame Extras Directory status:'
      WordWrap = True
    end
    object ExtrasEdit: TEdit
      Left = 227
      Top = 99
      Width = 212
      Height = 44
      AutoSelect = False
      BevelInner = bvNone
      BorderStyle = bsNone
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -30
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentColor = True
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
      Text = 'not loaded'
    end
  end
  object ExtrasBtnSet: TButton
    Left = 471
    Top = 226
    Width = 92
    Height = 31
    Caption = '&Set'
    TabOrder = 0
    OnClick = ExtrasBtnSetClick
  end
  object BtnCancel: TButton
    Left = 493
    Top = 565
    Width = 92
    Height = 31
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object TxtMameExtrasDirPath: TEdit
    Left = 41
    Top = 181
    Width = 422
    Height = 24
    TabOrder = 2
  end
  object BtnMameExtrasDirFind: TButton
    Left = 493
    Top = 180
    Width = 32
    Height = 27
    Caption = '...'
    TabOrder = 3
    OnClick = BtnMameExtrasDirFindClick
  end
  object TxtMAMEXMLFilePath: TJvFilenameEdit
    Left = 34
    Top = 492
    Width = 415
    Height = 24
    ClipboardCommands = []
    Filter = 'XML files (*.xml)|*.xml|All files (*.*)|*.*'
    ButtonWidth = 27
    TabOrder = 4
  end
  object XMLBtnScan: TButton
    Left = 471
    Top = 489
    Width = 92
    Height = 31
    Caption = '&Scan'
    TabOrder = 5
    OnClick = ExtrasBtnSetClick
  end
  object BtnOk: TButton
    Left = 376
    Top = 565
    Width = 98
    Height = 33
    Caption = '&OK'
    Default = True
    TabOrder = 8
    OnClick = ExtrasBtnSetClick
  end
end
