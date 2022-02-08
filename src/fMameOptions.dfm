object FrmMameOptions: TFrmMameOptions
  Left = 269
  Top = 223
  BorderStyle = bsDialog
  Caption = 'MAME Options'
  ClientHeight = 803
  ClientWidth = 727
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
    Top = 119
    Width = 681
    Height = 298
    Caption = 'Scan and Find Mame Games and Emulators'
    TabOrder = 5
    object XMLTxtLbl1: TLabel
      Left = 20
      Top = 105
      Width = 645
      Height = 32
      Caption = 
        'Scanning a MAME XML is required to use the MAME Printing menu op' +
        'tions. Download the MAME XML for your version of Mame from here'
      WordWrap = True
    end
    object XMLTxtLbl4: TLabel
      Left = 20
      Top = 191
      Width = 105
      Height = 16
      Caption = 'Mame XML status'
    end
    object MameXMLLinkLabel: TLabel
      Left = 305
      Top = 135
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
      Top = 159
      Width = 486
      Height = 16
      Caption = 
        'Download the zip named "mame{version number}lx.zip", unzip it, a' +
        'nd scan it below'
      WordWrap = True
    end
    object lblMAME: TLabel
      Left = 20
      Top = 65
      Width = 132
      Height = 16
      Caption = 'Mame Emulator to call'
    end
    object MameScanLabel1: TLabel
      Left = 17
      Top = 24
      Width = 623
      Height = 32
      Caption = 
        'To use QuickPlay'#39's MAME features, make sure you already have a M' +
        'AME/RetroArch arcade emulator in your emulators list, Select it ' +
        'below and the XML scan will  find new emulators based on it'
      WordWrap = True
    end
    object XMLTxtLbl14: TLabel
      Left = 17
      Top = 232
      Width = 379
      Height = 48
      Caption = 
        'A successful XML Scan will also put new systems in QuickPlay'#39's l' +
        'ist of systems, and make a new EFind file, for Mame'#39's console an' +
        'd home-computer emulators'
      WordWrap = True
    end
    object XMLEdit: TEdit
      Left = 305
      Top = 191
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
      Top = 224
      Width = 223
      Height = 65
      Caption = 'Choose XML File and Start Scan'
      TabOrder = 1
      OnClick = BtnXMLScanClick
    end
    object CmbMame: TComboBox
      Left = 255
      Top = 62
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
      OnChange = CmbMameSelect
      OnSelect = CmbMameSelect
    end
  end
  object ExtrasGroupBox: TGroupBox
    Left = 24
    Top = 14
    Width = 681
    Height = 99
    Caption = 'Set Mame Extras Dir'
    TabOrder = 4
    object ExtrasTxtLbl1: TLabel
      Left = 17
      Top = 18
      Width = 645
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
    Left = 191
    Top = 70
    Width = 400
    Height = 24
    TabOrder = 2
  end
  object BtnMameExtrasDirFind: TButton
    Left = 613
    Top = 70
    Width = 60
    Height = 27
    Caption = 'Select'
    TabOrder = 3
    OnClick = BtnMameExtrasDirFindClick
  end
  object MameFilePathGroupBox: TGroupBox
    Left = 24
    Top = 423
    Width = 681
    Height = 322
    Caption = 'Arcade and  Softlist Path Printing Options (Optional)'
    TabOrder = 6
    object FilePrintOptions: TPageControl
      Left = 2
      Top = 18
      Width = 677
      Height = 300
      ActivePage = TabFilepath
      Align = alTop
      TabOrder = 0
      object TabFilepath: TTabSheet
        Caption = 'Filepath Options'
        object RomPathLbl: TLabel
          Left = 3
          Top = 31
          Width = 96
          Height = 16
          Caption = 'Mame Rompath'
        end
        object ChdsPathTypeLbl: TLabel
          Left = 123
          Top = 162
          Width = 36
          Height = 16
          Caption = 'CHDs'
        end
        object RomPathDescLbl: TLabel
          Left = 3
          Top = 62
          Width = 616
          Height = 64
          Caption = 
            'We need to match each of the types of Rom MAME deals with to exa' +
            'ctly one of the MAME Paths you'#39've put in your MAME Rompath in MA' +
            'ME'#39's mame.ini. If you have more than one path for each type, you' +
            ' can use symlinks on your filesystem to link them all into one f' +
            'older. If you'#39're unsure what to do here, just select '#39'roms'#39' for ' +
            'all the below'
          WordWrap = True
        end
        object RomsPathTypeLbl: TLabel
          Left = 123
          Top = 132
          Width = 36
          Height = 16
          Caption = 'Roms'
        end
        object SoftlistChdsPathTypeLbl: TLabel
          Left = 45
          Top = 222
          Width = 114
          Height = 16
          Caption = 'Software List CHDs'
        end
        object SoftlistRomsPathTypeLbl: TLabel
          Left = 45
          Top = 192
          Width = 114
          Height = 16
          Caption = 'Software List Roms'
        end
        object ChkBoxMameFilePaths: TCheckBox
          Left = 3
          Top = 3
          Width = 159
          Height = 17
          Caption = 'Print MAME File Paths'
          TabOrder = 0
        end
        object RomPathEdit: TEdit
          Left = 165
          Top = 31
          Width = 501
          Height = 24
          TabOrder = 1
        end
        object CmbChdsPath: TComboBox
          Left = 165
          Top = 162
          Width = 501
          Height = 24
          Hint = 'Select a Rompath from your Mame Ini for this romtype'
          ItemHeight = 16
          ParentShowHint = False
          ShowHint = True
          TabOrder = 2
        end
        object CmbRomsPath: TComboBox
          Left = 165
          Top = 132
          Width = 501
          Height = 24
          Hint = 'Select a Rompath from your Mame Ini for this romtype'
          ItemHeight = 16
          ParentShowHint = False
          ShowHint = True
          TabOrder = 3
        end
        object CmbSoftlistChdsPath: TComboBox
          Left = 165
          Top = 222
          Width = 501
          Height = 24
          Hint = 'Select a Rompath from your Mame Ini for this romtype'
          ItemHeight = 16
          ParentShowHint = False
          ShowHint = True
          TabOrder = 4
        end
        object CmbSoftlistRomsPath: TComboBox
          Left = 165
          Top = 192
          Width = 501
          Height = 24
          Hint = 'Select a Rompath from your Mame Ini for this romtype'
          ItemHeight = 16
          ParentShowHint = False
          ShowHint = True
          TabOrder = 5
        end
      end
      object TabRomtype: TTabSheet
        Caption = 'Romtype Options'
        ImageIndex = 4
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object LblMameFiletypeExplain: TLabel
          Left = 17
          Top = 153
          Width = 644
          Height = 32
          Caption = 
            'A print of MAME Arcade Games or Softlists will print ROMSET file' +
            'names from the MAME XML. MAME files are usually zip compressed, ' +
            'but can be 7zip'
          WordWrap = True
        end
        object LblMameRomsTypeExplain: TLabel
          Left = 17
          Top = 22
          Width = 630
          Height = 32
          Caption = 
            'Mame Roms can be non-merged, split or merged (see MAME'#39's website' +
            '), your choice affects the filenames on disk. Merged is recommen' +
            'ded, and is the default here'
          WordWrap = True
        end
        object GBoxMergeType: TGroupBox
          Left = 396
          Top = 60
          Width = 261
          Height = 47
          Caption = 'Mame Roms Merge Type'
          TabOrder = 0
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
          Left = 396
          Top = 191
          Width = 261
          Height = 42
          Caption = 'Mame Roms Filetype'
          TabOrder = 1
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
      end
    end
  end
end
