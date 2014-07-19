object FrmFolder: TFrmFolder
  Left = 322
  Top = 153
  BorderStyle = bsDialog
  Caption = 'Folder Options: '
  ClientHeight = 418
  ClientWidth = 618
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PageFol: TPageControl
    Left = 0
    Top = 0
    Width = 618
    Height = 388
    ActivePage = TabRealIcons
    Align = alClient
    TabOrder = 0
    object TabGeneral: TTabSheet
      Caption = 'General Options'
      object GrpMirror: TGroupBox
        Left = 8
        Top = 28
        Width = 297
        Height = 328
        Caption = 'Folder Mirroring'
        TabOrder = 0
        object lblDir: TLabel
          Left = 8
          Top = 92
          Width = 35
          Height = 13
          Caption = 'Folders'
          Enabled = False
        end
        object lblEmu: TLabel
          Left = 10
          Top = 217
          Width = 42
          Height = 26
          Caption = 'Default'#13#10'Emulator'
          Enabled = False
        end
        object lblFilter: TLabel
          Left = 17
          Top = 256
          Width = 35
          Height = 26
          Caption = 'Default'#13#10'filter'
          Enabled = False
        end
        object Label1: TLabel
          Left = 23
          Top = 43
          Width = 215
          Height = 39
          Caption = 
            '(Warning: if you enable folder mirroring'#13#10'any roms currently in ' +
            'your list which are NOT'#13#10'in the mirrored directory will be lost)'
        end
        object LstFilter: TListBox
          Left = 64
          Top = 256
          Width = 129
          Height = 61
          Enabled = False
          ItemHeight = 13
          TabOrder = 2
        end
        object cmbEmu: TComboBox
          Left = 64
          Top = 221
          Width = 201
          Height = 21
          Enabled = False
          ItemHeight = 13
          Sorted = True
          TabOrder = 1
          OnChange = cmbEmuChange
        end
        object ChkMirror: TCheckBox
          Left = 8
          Top = 24
          Width = 273
          Height = 17
          Caption = 'Enable Folder Mirroring'
          TabOrder = 0
          OnClick = ChkMirrorClick
        end
        object LstDirMir: TListBox
          Left = 64
          Top = 88
          Width = 201
          Height = 114
          Hint = 'Add Multiple directories by using the Add Button'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'Tahoma'
          Font.Style = []
          ItemHeight = 11
          ParentFont = False
          TabOrder = 3
        end
        object BtnAddMirror: TJvImgBtn
          Left = 265
          Top = 88
          Width = 27
          Height = 25
          TabOrder = 4
          OnClick = BtnAddMirrorClick
          HotTrackFont.Charset = DEFAULT_CHARSET
          HotTrackFont.Color = clWindowText
          HotTrackFont.Height = -11
          HotTrackFont.Name = 'Tahoma'
          HotTrackFont.Style = []
          Images = MainFrm.ImageList1
          ImageIndex = 0
        end
        object BtnDelMirror: TJvImgBtn
          Left = 265
          Top = 117
          Width = 27
          Height = 25
          TabOrder = 5
          OnClick = BtnDelMirrorClick
          HotTrackFont.Charset = DEFAULT_CHARSET
          HotTrackFont.Color = clWindowText
          HotTrackFont.Height = -11
          HotTrackFont.Name = 'Tahoma'
          HotTrackFont.Style = []
          Images = MainFrm.ImageList1
          ImageIndex = 3
        end
        object BtnAddFilter: TJvImgBtn
          Left = 195
          Top = 256
          Width = 27
          Height = 25
          TabOrder = 6
          OnClick = BtnAddFilterClick
          HotTrackFont.Charset = DEFAULT_CHARSET
          HotTrackFont.Color = clWindowText
          HotTrackFont.Height = -11
          HotTrackFont.Name = 'Tahoma'
          HotTrackFont.Style = []
          Images = MainFrm.ImageList1
          ImageIndex = 22
        end
        object BtnDelFilter: TJvImgBtn
          Left = 195
          Top = 284
          Width = 27
          Height = 25
          TabOrder = 7
          OnClick = BtnDelFilterClick
          HotTrackFont.Charset = DEFAULT_CHARSET
          HotTrackFont.Color = clWindowText
          HotTrackFont.Height = -11
          HotTrackFont.Name = 'Tahoma'
          HotTrackFont.Style = []
          Images = MainFrm.ImageList1
          ImageIndex = 3
        end
      end
      object GrpBackground: TGroupBox
        Left = 312
        Top = 132
        Width = 297
        Height = 97
        Caption = 'Background Image'
        TabOrder = 1
        object LblBKPath: TLabel
          Left = 12
          Top = 55
          Width = 30
          Height = 13
          Caption = 'Image'
          Enabled = False
        end
        object ChkBK: TCheckBox
          Left = 3
          Top = 29
          Width = 278
          Height = 17
          Caption = 'Use Image for Folder Background'
          TabOrder = 0
          OnClick = ChkBKClick
        end
        object TxtBKPath: TJvFilenameEdit
          Left = 56
          Top = 52
          Width = 228
          Height = 21
          ClipboardCommands = []
          AddQuotes = False
          DialogKind = dkOpenPicture
          Filter = 'Image Files (*.gif*.png,*.bmp)|*.gif;*.png;*.bmp|All Files|*.*'
          Enabled = False
          TabOrder = 1
          OnChange = TxtBKPathChange
        end
      end
      object GrpIcon: TGroupBox
        Left = 312
        Top = 28
        Width = 297
        Height = 97
        Caption = 'Folder Listing Icon'
        TabOrder = 2
        object lblIcon: TLabel
          Left = 21
          Top = 56
          Width = 21
          Height = 13
          Caption = 'Icon'
          Enabled = False
        end
        object ChkIcon: TCheckBox
          Left = 8
          Top = 24
          Width = 265
          Height = 17
          Caption = 'Use Icon for Folder Tree Icon'
          TabOrder = 0
          OnClick = ChkIconClick
        end
        object CmbIcon: TComboBoxEx
          Left = 56
          Top = 51
          Width = 201
          Height = 22
          ItemsEx = <>
          Style = csExDropDownList
          Enabled = False
          ItemHeight = 16
          TabOrder = 1
          Images = IconList
        end
      end
    end
    object TabMerged: TTabSheet
      Caption = 'GoodMerge Support'
      ImageIndex = 2
      object lblMergeTitle: TLabel
        Left = 48
        Top = 24
        Width = 129
        Height = 16
        Caption = 'GoodMerge Support'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblGoodMergeLink: TLabel
        Left = 199
        Top = 26
        Width = 131
        Height = 13
        Cursor = crHandPoint
        Caption = 'Visit GoodMerge Homepage'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        OnClick = lblGoodMergeLinkClick
      end
      object lblGoodMergeDesc: TLabel
        Left = 48
        Top = 56
        Width = 353
        Height = 104
        Caption = 
          'QuickPlay now supports GoodMerge ROM sets.  To activate this sup' +
          'port, '#13#10'check the box below and enter your preferred languages. ' +
          ' QuickPlay will '#13#10'then automatically try to run your language of' +
          ' choice first, falling back to '#13#10'the other choices if necessary.' +
          '  If none of your choices are found, any '#13#10'ROM will be launched.' +
          #13#10#13#10'You can also '#39'look inside'#39' archives in the main window and s' +
          'elect to '#13#10'run any ROM you want.'
      end
      object lblPrefWarning: TLabel
        Left = 112
        Top = 304
        Width = 278
        Height = 13
        Caption = 'If no preferred ROM is found, ANY ROM will be launched..'
      end
      object lblGM1: TLabel
        Left = 112
        Top = 220
        Width = 50
        Height = 13
        Caption = '1st Choice'
      end
      object lblGM2: TLabel
        Left = 112
        Top = 244
        Width = 53
        Height = 13
        Caption = '2nd Choice'
      end
      object lblGM3: TLabel
        Left = 112
        Top = 268
        Width = 51
        Height = 13
        Caption = '3rd Choice'
      end
      object ChkActivateGoodMerge: TCheckBox
        Left = 112
        Top = 176
        Width = 377
        Height = 17
        Caption = 'Enable GoodMerge Support for this folder'
        TabOrder = 4
      end
      object ChkExclamationRoms: TCheckBox
        Left = 112
        Top = 194
        Width = 377
        Height = 17
        Caption = 'Show only roms with '#39'!'#39' in the list'
        Checked = True
        State = cbChecked
        TabOrder = 5
      end
      object ChkprefEXCL: TCheckBox
        Left = 176
        Top = 217
        Width = 169
        Height = 21
        Caption = 'Roms with [!]'
        Checked = True
        State = cbChecked
        TabOrder = 0
      end
      object CmbGMpref1: TComboBox
        Left = 176
        Top = 217
        Width = 169
        Height = 21
        Style = csDropDownList
        ItemHeight = 13
        TabOrder = 1
      end
      object CmbGMpref2: TComboBox
        Left = 176
        Top = 241
        Width = 169
        Height = 21
        Style = csDropDownList
        ItemHeight = 13
        TabOrder = 2
      end
      object CmbGMpref3: TComboBox
        Left = 176
        Top = 265
        Width = 169
        Height = 21
        Style = csDropDownList
        ItemHeight = 13
        TabOrder = 3
      end
    end
    object TabRealIcons: TTabSheet
      Caption = 'Real Icons'
      ImageIndex = 2
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object TLabel
        Left = 48
        Top = 24
        Width = 127
        Height = 16
        Caption = 'MAME Icon Support'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblMAMElink: TLabel
        Left = 48
        Top = 152
        Width = 490
        Height = 13
        Cursor = crHandPoint
        Caption = 
          'Download MAME icons from MAMu_'#39's sets - try here http://www.prog' +
          'ettosnaps.net/mamu_icons.html '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        OnClick = lblMAMElinkClick
      end
      object TLabel
        Left = 48
        Top = 56
        Width = 435
        Height = 78
        Caption = 
          'By downloading the MAME Icon set QuickPlay can then display each' +
          ' games '#39'proper'#39' Icon.  '#13#10'To activate this, check the box below a' +
          'nd enter in the path to your icons.  If the icons are '#13#10'uncompre' +
          'ssed into a directory, enter the path to the directory. '#13#10#13#10'Also' +
          ' now Quickplay can use a ZIP file to load the icons from.  This ' +
          'feature does not work '#13#10'with any other compression types.'
      end
      object Label2: TLabel
        Left = 72
        Top = 268
        Width = 54
        Height = 13
        Caption = 'Icon Folder'
      end
      object ChkLargeIcons: TCheckBox
        Left = 48
        Top = 205
        Width = 281
        Height = 17
        Caption = 'Use Large Icons (32x32)'
        TabOrder = 1
      end
      object ChkMAMEIcons: TCheckBox
        Left = 48
        Top = 182
        Width = 559
        Height = 17
        Caption = 
          'Enable MAME Icons for this directory (Image support MUST be turn' +
          'ed on in the main options)'
        TabOrder = 0
      end
      object TxtMAMEIconDir: TJvDirectoryEdit
        Left = 136
        Top = 264
        Width = 369
        Height = 21
        ClipboardCommands = []
        DialogKind = dkWin32
        DialogOptions = []
        TabOrder = 2
      end
      object TxtMAMEIconFile: TJvFilenameEdit
        Left = 88
        Top = 320
        Width = 369
        Height = 21
        ClipboardCommands = []
        Filter = 'ZIP files (*.zip)|*.zip|All files (*.*)|*.*'
        Enabled = False
        TabOrder = 3
      end
      object RadMAMEIconsDir: TRadioButton
        Left = 48
        Top = 241
        Width = 313
        Height = 17
        Caption = 'MAME Icons are in a directory'
        Checked = True
        TabOrder = 4
        TabStop = True
        OnClick = RadMAMEIconsDirClick
      end
      object RadMAMEIconsFile: TRadioButton
        Left = 48
        Top = 296
        Width = 313
        Height = 17
        Caption = 'MAME Icons are in a ZIP file.'
        TabOrder = 5
        OnClick = RadMAMEIconsDirClick
      end
    end
  end
  object PanCtrls: TPanel
    Left = 0
    Top = 388
    Width = 618
    Height = 30
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object BtnOK: TButton
      Left = 462
      Top = 3
      Width = 75
      Height = 25
      Caption = '&OK'
      Default = True
      TabOrder = 0
      OnClick = BtnOKClick
    end
    object BtnCancel: TButton
      Left = 542
      Top = 3
      Width = 75
      Height = 25
      Caption = '&Cancel'
      TabOrder = 1
      OnClick = BtnCancelClick
    end
  end
  object IconList: TImageList
    Left = 472
    Top = 8
  end
  object jvBrowse: TJvBrowseForFolderDialog
    Left = 432
    Top = 8
  end
end
