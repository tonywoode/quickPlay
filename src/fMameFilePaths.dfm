object FrmMameFilePath: TFrmMameFilePath
  Left = 0
  Top = 0
  Caption = 'Mame File Path Options'
  ClientHeight = 572
  ClientWidth = 705
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
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
  object Label5: TLabel
    Left = 8
    Top = 88
    Width = 90
    Height = 16
    Caption = 'Mame Rompath'
  end
  object GrpBoxArcadeSList: TGroupBox
    Left = 8
    Top = 126
    Width = 681
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
  object GroupBox1: TGroupBox
    Left = 8
    Top = 333
    Width = 681
    Height = 194
    Caption = 'Rom Paths'
    TabOrder = 1
    object Label1: TLabel
      Left = 13
      Top = 32
      Width = 32
      Height = 16
      Caption = 'Roms'
      OnClick = Label1Click
    end
    object Label2: TLabel
      Left = 13
      Top = 72
      Width = 30
      Height = 16
      Caption = 'CHDs'
    end
    object Label3: TLabel
      Left = 13
      Top = 112
      Width = 111
      Height = 16
      Caption = 'Software List Roms'
    end
    object Label4: TLabel
      Left = 13
      Top = 152
      Width = 109
      Height = 16
      Caption = 'Software List CHDs'
    end
    object ComboBox1: TComboBox
      Left = 146
      Top = 32
      Width = 503
      Height = 24
      ItemHeight = 16
      TabOrder = 0
      Text = 'ComboBox1'
    end
    object ComboBox2: TComboBox
      Left = 146
      Top = 72
      Width = 503
      Height = 24
      ItemHeight = 16
      TabOrder = 1
      Text = 'ComboBox1'
    end
    object ComboBox3: TComboBox
      Left = 146
      Top = 112
      Width = 501
      Height = 24
      ItemHeight = 16
      TabOrder = 2
      Text = 'ComboBox1'
    end
    object ComboBox4: TComboBox
      Left = 146
      Top = 152
      Width = 501
      Height = 24
      ItemHeight = 16
      TabOrder = 3
      Text = 'ComboBox1'
    end
  end
  object BtnCancel: TButton
    Left = 597
    Top = 533
    Width = 92
    Height = 31
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 2
  end
  object MameOptsOk: TButton
    Left = 478
    Top = 533
    Width = 92
    Height = 31
    Caption = '&Ok'
    TabOrder = 3
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
  object Edit1: TEdit
    Left = 329
    Top = 85
    Width = 345
    Height = 24
    TabOrder = 6
    Text = 'Edit1'
  end
end
