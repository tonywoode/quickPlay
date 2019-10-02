object FrmMameOptions: TFrmMameOptions
  Left = 269
  Top = 223
  BorderStyle = bsDialog
  Caption = 'MAME Options'
  ClientHeight = 800
  ClientWidth = 724
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
    Top = 151
    Width = 681
    Height = 358
    Caption = 'Scan and Find Mame Games and Emulators'
    TabOrder = 5
    object XMLTxtLbl1: TLabel
      Left = 20
      Top = 129
      Width = 647
      Height = 32
      Caption = 
        'Scanning a MAME XML is required to use the MAME Printing menu op' +
        'tions. Download the MAME XML for your version of Mame from here'
      WordWrap = True
    end
    object XMLTxtLbl4: TLabel
      Left = 17
      Top = 237
      Width = 105
      Height = 16
      Caption = 'Mame XML status'
    end
    object MameXMLLinkLabel: TLabel
      Left = 236
      Top = 167
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
      Left = 20
      Top = 201
      Width = 637
      Height = 16
      Caption = 
        'Download the zip named "mame{version number}lx.zip", unzip it, a' +
        'nd scan it below'
      WordWrap = True
    end
    object lblMAME: TLabel
      Left = 20
      Top = 78
      Width = 132
      Height = 16
      Caption = 'Mame Emulator to call'
    end
    object MameScanLabel1: TLabel
      Left = 17
      Top = 24
      Width = 648
      Height = 48
      Caption = 
        'To use QuickPlay'#39's MAME features, make sure you already have a M' +
        'AME/RetroArch arcade emulator in your emulators list, Select it ' +
        'below and the XML scan will  find new emulators based on it'
      WordWrap = True
    end
    object XMLTxtLbl14: TLabel
      Left = 17
      Top = 295
      Width = 379
      Height = 32
      Caption = 
        'A successful XML Scan will also put new systems in QuickPlay'#39's l' +
        'ist of systems, and make a new EFind file, for Mame'#39's console an' +
        'd home-computer emulators'
      WordWrap = True
    end
    object XMLEdit: TEdit
      Left = 152
      Top = 231
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
      Left = 426
      Top = 280
      Width = 223
      Height = 65
      Caption = 'Choose XML File and Start Scan'
      TabOrder = 1
      OnClick = BtnXMLScanClick
    end
    object CmbMame: TComboBox
      Left = 173
      Top = 78
      Width = 394
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
    Top = 14
    Width = 681
    Height = 121
    Caption = 'Set Mame Extras Dir'
    TabOrder = 4
    object ExtrasTxtLbl1: TLabel
      Left = 17
      Top = 18
      Width = 648
      Height = 32
      Caption = 
        'Setting the location of the MAME extras directory will allow you' +
        ' to use MAME dats and icons in QuickPlay, and is needed by the M' +
        'ame XML Scanner'
      WordWrap = True
    end
    object ExtrasTxtLbl2: TLabel
      Left = 17
      Top = 56
      Width = 135
      Height = 16
      Caption = 'Mame Extras Directory'
    end
  end
  object MameOptsOk: TButton
    Left = 499
    Top = 761
    Width = 92
    Height = 31
    Caption = '&Ok'
    TabOrder = 0
    OnClick = BtnMameOptsOkClick
  end
  object BtnCancel: TButton
    Left = 613
    Top = 761
    Width = 92
    Height = 31
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object TxtMameExtrasDirPath: TEdit
    Left = 143
    Top = 100
    Width = 448
    Height = 24
    TabOrder = 2
  end
  object BtnMameExtrasDirFind: TButton
    Left = 613
    Top = 99
    Width = 60
    Height = 27
    Caption = 'Select'
    TabOrder = 3
    OnClick = BtnMameExtrasDirFindClick
  end
  object GrpBoxArcadeSList: TGroupBox
    Left = 24
    Top = 515
    Width = 681
    Height = 240
    Caption = 'Arcade and Softlist Printing Options'
    TabOrder = 6
    object LblMameFiletypeExplain: TLabel
      Left = 13
      Top = 54
      Width = 652
      Height = 32
      Caption = 
        'A print of MAME Arcade Games or Softlists will print ROMSET file' +
        'names from the MAME XML. MAME files are usually zip compressed, ' +
        'but can be 7zip'
      WordWrap = True
    end
    object LblMameRomsTypeExplain: TLabel
      Left = 17
      Top = 140
      Width = 640
      Height = 32
      Caption = 
        'Mame Roms can be non-merged, split or merged (see MAME'#39's website' +
        '), your choice affects the filenames on disk. Merged is recommen' +
        'ded, and is the default here'
      WordWrap = True
    end
    object GBoxMergeType: TGroupBox
      Left = 388
      Top = 178
      Width = 261
      Height = 47
      Caption = 'Mame Roms Merge Type'
      TabOrder = 2
      object RadMameMergeMerged: TRadioButton
        Left = 20
        Top = 18
        Width = 89
        Height = 17
        Caption = 'Merged'
        TabOrder = 0
      end
      object RadMameMergeNonMerged: TRadioButton
        Left = 115
        Top = 18
        Width = 153
        Height = 17
        Caption = 'Split/Non-Merged'
        TabOrder = 1
      end
    end
    object GBoxGroupFiletype: TGroupBox
      Left = 388
      Top = 84
      Width = 261
      Height = 42
      Caption = 'Mame Roms Filetype'
      TabOrder = 1
      OnClick = GBoxGroupFiletypeClick
      object RadMameFileZip: TRadioButton
        Left = 23
        Top = 22
        Width = 113
        Height = 17
        Caption = 'Zip'
        TabOrder = 0
      end
      object RadMameFile7z: TRadioButton
        Left = 118
        Top = 22
        Width = 113
        Height = 17
        Caption = '7Zip'
        TabOrder = 1
      end
    end
    object ChkBoxMameFilePaths: TCheckBox
      Left = 13
      Top = 26
      Width = 159
      Height = 17
      Caption = 'Print MAME File Paths'
      TabOrder = 0
    end
  end
end
