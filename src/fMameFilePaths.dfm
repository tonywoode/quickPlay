object FrmMameFilePath: TFrmMameFilePath
  Left = 0
  Top = 0
  Caption = 'Mame File Path Options'
  ClientHeight = 687
  ClientWidth = 700
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object XMLTxtLbl: TLabel
    Left = 8
    Top = 57
    Width = 101
    Height = 16
    Caption = 'Mame XML status'
  end
  object lblMAME: TLabel
    Left = 8
    Top = 23
    Width = 128
    Height = 16
    Caption = 'Mame Emulator to call'
  end
  object RomPathLbl: TLabel
    Left = 8
    Top = 88
    Width = 90
    Height = 16
    Caption = 'Mame Rompath'
  end
  object GrpBoxArcadeSList: TGroupBox
    Left = 8
    Top = 126
    Width = 684
    Height = 201
    Caption = 'Arcade and Softlist Printing Options'
    TabOrder = 0
    object LblMameFiletypeExplain: TLabel
      Left = 13
      Top = 49
      Width = 627
      Height = 32
      Caption = 
        'A print of MAME Arcade Games or Softlists will print ROMSET file' +
        'names from the MAME XML. MAME files are usually zip compressed, ' +
        'but can be 7zip'
      WordWrap = True
    end
    object LblMameRomsTypeExplain: TLabel
      Left = 13
      Top = 121
      Width = 630
      Height = 32
      Caption = 
        'Mame Roms can be non-merged, split or merged (see MAME'#39's website' +
        '), your choice affects the filenames on disk. Merged is recommen' +
        'ded, and is the default here'
      WordWrap = True
    end
    object GBoxMergeType: TGroupBox
      Left = 407
      Top = 146
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
      Left = 407
      Top = 76
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
    object ChkBoxMameFilePaths: TCheckBox
      Left = 13
      Top = 26
      Width = 159
      Height = 17
      Caption = 'Print MAME File Paths'
      TabOrder = 0
    end
  end
  object GrpRomPathTypes: TGroupBox
    Left = 8
    Top = 333
    Width = 684
    Height = 306
    Caption = 'Rom Path Types'
    TabOrder = 1
    object RomsPathTypeLbl: TLabel
      Left = 113
      Top = 136
      Width = 32
      Height = 16
      Caption = 'Roms'
    end
    object ChdsPathTypeLbl: TLabel
      Left = 113
      Top = 176
      Width = 30
      Height = 16
      Caption = 'CHDs'
    end
    object SoftlistRomsPathTypeLbl: TLabel
      Left = 30
      Top = 216
      Width = 111
      Height = 16
      Caption = 'Software List Roms'
    end
    object SoftlistChdsPathTypeLbl: TLabel
      Left = 32
      Top = 256
      Width = 109
      Height = 16
      Caption = 'Software List CHDs'
    end
    object RomPathDescLbl: TLabel
      Left = 13
      Top = 40
      Width = 623
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
    object CmbRomsPath: TComboBox
      Left = 165
      Top = 136
      Width = 503
      Height = 24
      ItemHeight = 16
      TabOrder = 0
    end
    object CmbChdsPath: TComboBox
      Left = 165
      Top = 176
      Width = 503
      Height = 24
      ItemHeight = 16
      TabOrder = 1
    end
    object CmbSoftlistRomsPath: TComboBox
      Left = 165
      Top = 216
      Width = 501
      Height = 24
      ItemHeight = 16
      TabOrder = 2
    end
    object CmbSoftlistChdsPath: TComboBox
      Left = 165
      Top = 256
      Width = 501
      Height = 24
      ItemHeight = 16
      TabOrder = 3
    end
  end
  object BtnCancel: TButton
    Left = 600
    Top = 645
    Width = 92
    Height = 31
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 2
  end
  object MameFileOptsOk: TButton
    Left = 478
    Top = 645
    Width = 92
    Height = 31
    Caption = '&Ok'
    TabOrder = 3
    OnClick = MameFileOptsOkClick
  end
  object XMLEdit: TEdit
    Left = 329
    Top = 47
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
    TabOrder = 4
    Text = 'not loaded'
  end
  object CmbMame: TComboBox
    Left = 329
    Top = 15
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
    TabOrder = 5
  end
  object RomPathEdit: TEdit
    Left = 329
    Top = 85
    Width = 345
    Height = 24
    TabOrder = 6
  end
end
