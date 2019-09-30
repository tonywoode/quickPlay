object FrmMameOptions: TFrmMameOptions
  Left = 269
  Top = 223
  BorderStyle = bsDialog
  Caption = 'MAME Options'
  ClientHeight = 743
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
    Top = 151
    Width = 577
    Height = 330
    Caption = 'Scan and Find Mame Games and Emulators'
    TabOrder = 5
    object XMLTxtLbl1: TLabel
      Left = 18
      Top = 105
      Width = 508
      Height = 32
      Caption = 
        'Scanning a MAME XML is required to use the MAME Printing menu op' +
        'tions. Download the MAME XML for your version of Mame from here'
      WordWrap = True
    end
    object XMLTxtLbl4: TLabel
      Left = 18
      Top = 199
      Width = 105
      Height = 16
      Caption = 'Mame XML status'
    end
    object MameXMLLinkLabel: TLabel
      Left = 188
      Top = 143
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
      Left = 40
      Top = 167
      Width = 506
      Height = 16
      Caption = 
        'Download the zip file named "mame{version number}lx.zip", unzip ' +
        'it, and scan it below'
      WordWrap = True
    end
    object lblMAME: TLabel
      Left = 36
      Top = 78
      Width = 132
      Height = 16
      Caption = 'Mame Emulator to call'
    end
    object MameScanLabel1: TLabel
      Left = 17
      Top = 24
      Width = 509
      Height = 48
      Caption = 
        'To use QuickPlay'#39's MAME features, make sure you already have a M' +
        'AME/RetroArch arcade emulator in your emulators list, Select it ' +
        'below and the XML scan will  find new emulators based on it'
      WordWrap = True
    end
    object XMLTxtLbl14: TLabel
      Left = 18
      Top = 287
      Width = 528
      Height = 32
      Caption = 
        'A successful XML Scan will also put new systems in QuickPlay'#39's l' +
        'ist of systems, and make a new EFind file, for Mame'#39's console an' +
        'd home-computer emulators'
      WordWrap = True
    end
    object XMLEdit: TEdit
      Left = 152
      Top = 199
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
      Left = 152
      Top = 240
      Width = 223
      Height = 41
      Caption = 'Choose XML File and Start Scan'
      TabOrder = 1
      OnClick = BtnXMLScanClick
    end
    object CmbMame: TComboBox
      Left = 201
      Top = 75
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
    Height = 121
    Caption = 'Set Mame Extras Dir'
    TabOrder = 4
    object ExtrasTxtLbl1: TLabel
      Left = 17
      Top = 18
      Width = 539
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
    Left = 411
    Top = 701
    Width = 92
    Height = 31
    Caption = '&Ok'
    TabOrder = 0
    OnClick = BtnMameOptsOkClick
  end
  object BtnCancel: TButton
    Left = 509
    Top = 701
    Width = 92
    Height = 31
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object TxtMameExtrasDirPath: TEdit
    Left = 41
    Top = 102
    Width = 422
    Height = 24
    TabOrder = 2
  end
  object BtnMameExtrasDirFind: TButton
    Left = 485
    Top = 101
    Width = 57
    Height = 27
    Caption = 'Select'
    TabOrder = 3
    OnClick = BtnMameExtrasDirFindClick
  end
  object GroupBox1: TGroupBox
    Left = 24
    Top = 487
    Width = 577
    Height = 202
    Caption = 'Arcade and Softlist Printing Options'
    TabOrder = 6
    object LblMameFileType: TLabel
      Left = 96
      Top = 101
      Width = 128
      Height = 16
      Caption = 'Mame Roms Filetype'
    end
    object LblMameFiletypeExplain: TLabel
      Left = 17
      Top = 55
      Width = 507
      Height = 48
      Caption = 
        'A print of MAME Arcade Games or Softlists will print ROMSET file' +
        'names based on the MAME XML. MAME files are usually compressed t' +
        'o zip, but can be compressed to 7zip'
      WordWrap = True
    end
    object LblMameRomsType: TLabel
      Left = 96
      Top = 169
      Width = 154
      Height = 16
      Caption = 'Mame Roms Merge Type'
    end
    object LblMameRomsTypeExplain: TLabel
      Left = 17
      Top = 123
      Width = 503
      Height = 32
      Caption = 
        'Mame Roms can be non-merged, split or merged (see MAME'#39's website' +
        '), your choice affects the filenames on disk. Merged is recommen' +
        'ded, and is the default here'
      WordWrap = True
    end
    object ChkBoxMameFilePaths: TCheckBox
      Left = 17
      Top = 32
      Width = 159
      Height = 17
      Caption = 'Print MAME File Paths'
      TabOrder = 0
    end
    object ComboMameFileType: TComboBox
      Left = 272
      Top = 95
      Width = 145
      Height = 24
      ItemHeight = 16
      TabOrder = 1
    end
    object ComboMameRomsType: TComboBox
      Left = 272
      Top = 168
      Width = 145
      Height = 24
      ItemHeight = 16
      TabOrder = 2
    end
  end
end
