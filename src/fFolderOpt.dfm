object FrmFolder: TFrmFolder
  Left = 322
  Top = 153
  BorderStyle = bsDialog
  Caption = 'Folder Options: '
  ClientHeight = 547
  ClientWidth = 808
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 17
  object PageFol: TPageControl
    Left = 0
    Top = 0
    Width = 808
    Height = 507
    ActivePage = TabGeneral
    Align = alClient
    TabOrder = 0
    object TabGeneral: TTabSheet
      Caption = 'General Options'
      object GrpMirror: TGroupBox
        Left = 10
        Top = 37
        Width = 389
        Height = 429
        Caption = 'Folder Mirroring'
        TabOrder = 0
        object lblDir: TLabel
          Left = 10
          Top = 120
          Width = 43
          Height = 17
          Caption = 'Folders'
          Enabled = False
        end
        object lblEmu: TLabel
          Left = 13
          Top = 284
          Width = 55
          Height = 34
          Caption = 'Default'#13#10'Emulator'
          Enabled = False
        end
        object lblFilter: TLabel
          Left = 22
          Top = 335
          Width = 43
          Height = 34
          Caption = 'Default'#13#10'filter'
          Enabled = False
        end
        object Label1: TLabel
          Left = 30
          Top = 56
          Width = 276
          Height = 51
          Caption = 
            '(Warning: if you enable folder mirroring'#13#10'any roms currently in ' +
            'your list which are NOT'#13#10'in the mirrored directory will be lost)'
        end
        object LstFilter: TListBox
          Left = 84
          Top = 335
          Width = 168
          Height = 80
          Enabled = False
          ItemHeight = 17
          TabOrder = 2
        end
        object cmbEmu: TComboBox
          Left = 84
          Top = 289
          Width = 263
          Height = 25
          Enabled = False
          ItemHeight = 17
          Sorted = True
          TabOrder = 1
          OnChange = cmbEmuChange
        end
        object ChkMirror: TCheckBox
          Left = 10
          Top = 31
          Width = 357
          Height = 23
          Caption = 'Enable Folder Mirroring'
          TabOrder = 0
          OnClick = ChkMirrorClick
        end
        object LstDirMir: TListBox
          Left = 84
          Top = 115
          Width = 263
          Height = 149
          Hint = 'Add Multiple directories by using the Add Button'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ItemHeight = 14
          ParentFont = False
          TabOrder = 3
        end
        object BtnAddMirror: TJvImgBtn
          Left = 347
          Top = 115
          Width = 35
          Height = 33
          TabOrder = 4
          OnClick = BtnAddMirrorClick
          HotTrackFont.Charset = DEFAULT_CHARSET
          HotTrackFont.Color = clWindowText
          HotTrackFont.Height = -14
          HotTrackFont.Name = 'Tahoma'
          HotTrackFont.Style = []
          Images = MainFrm.ImageList1
          ImageIndex = 0
        end
        object BtnDelMirror: TJvImgBtn
          Left = 347
          Top = 153
          Width = 35
          Height = 33
          TabOrder = 5
          OnClick = BtnDelMirrorClick
          HotTrackFont.Charset = DEFAULT_CHARSET
          HotTrackFont.Color = clWindowText
          HotTrackFont.Height = -14
          HotTrackFont.Name = 'Tahoma'
          HotTrackFont.Style = []
          Images = MainFrm.ImageList1
          ImageIndex = 3
        end
        object BtnAddFilter: TJvImgBtn
          Left = 255
          Top = 335
          Width = 35
          Height = 32
          TabOrder = 6
          OnClick = BtnAddFilterClick
          HotTrackFont.Charset = DEFAULT_CHARSET
          HotTrackFont.Color = clWindowText
          HotTrackFont.Height = -14
          HotTrackFont.Name = 'Tahoma'
          HotTrackFont.Style = []
          Images = MainFrm.ImageList1
          ImageIndex = 22
        end
        object BtnDelFilter: TJvImgBtn
          Left = 255
          Top = 371
          Width = 35
          Height = 33
          TabOrder = 7
          OnClick = BtnDelFilterClick
          HotTrackFont.Charset = DEFAULT_CHARSET
          HotTrackFont.Color = clWindowText
          HotTrackFont.Height = -14
          HotTrackFont.Name = 'Tahoma'
          HotTrackFont.Style = []
          Images = MainFrm.ImageList1
          ImageIndex = 3
        end
      end
      object GrpBackground: TGroupBox
        Left = 408
        Top = 173
        Width = 388
        Height = 126
        Caption = 'Background Image'
        TabOrder = 1
        object LblBKPath: TLabel
          Left = 16
          Top = 72
          Width = 38
          Height = 17
          Caption = 'Image'
          Enabled = False
        end
        object ChkBK: TCheckBox
          Left = 4
          Top = 38
          Width = 363
          Height = 22
          Caption = 'Use Image for Folder Background'
          TabOrder = 0
          OnClick = ChkBKClick
        end
        object TxtBKPath: TJvFilenameEdit
          Left = 73
          Top = 68
          Width = 298
          Height = 25
          ClipboardCommands = []
          AddQuotes = False
          DialogKind = dkOpenPicture
          Filter = 'Image Files (*.gif*.png,*.bmp)|*.gif;*.png;*.bmp|All Files|*.*'
          Enabled = False
          ButtonWidth = 27
          TabOrder = 1
          OnChange = TxtBKPathChange
        end
      end
      object GrpIcon: TGroupBox
        Left = 408
        Top = 37
        Width = 388
        Height = 126
        Caption = 'Folder Listing Icon'
        TabOrder = 2
        object lblIcon: TLabel
          Left = 27
          Top = 73
          Width = 27
          Height = 17
          Caption = 'Icon'
          Enabled = False
        end
        object ChkIcon: TCheckBox
          Left = 10
          Top = 31
          Width = 347
          Height = 23
          Caption = 'Use Icon for Folder Tree Icon'
          TabOrder = 0
          OnClick = ChkIconClick
        end
        object CmbIcon: TComboBoxEx
          Left = 73
          Top = 67
          Width = 263
          Height = 26
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
        Left = 63
        Top = 31
        Width = 173
        Height = 21
        Caption = 'GoodMerge Support'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -17
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblGoodMergeLink: TLabel
        Left = 260
        Top = 34
        Width = 181
        Height = 18
        Cursor = crHandPoint
        Caption = 'Visit GoodMerge Homepage'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        OnClick = lblGoodMergeLinkClick
      end
      object lblGoodMergeDesc: TLabel
        Left = 63
        Top = 73
        Width = 448
        Height = 136
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
        Left = 146
        Top = 398
        Width = 345
        Height = 17
        Caption = 'If no preferred ROM is found, ANY ROM will be launched..'
      end
      object lblGM1: TLabel
        Left = 146
        Top = 288
        Width = 64
        Height = 17
        Caption = '1st Choice'
      end
      object lblGM2: TLabel
        Left = 146
        Top = 319
        Width = 69
        Height = 17
        Caption = '2nd Choice'
      end
      object lblGM3: TLabel
        Left = 146
        Top = 350
        Width = 66
        Height = 17
        Caption = '3rd Choice'
      end
      object ChkActivateGoodMerge: TCheckBox
        Left = 146
        Top = 230
        Width = 493
        Height = 22
        Caption = 'Enable GoodMerge Support for this folder'
        TabOrder = 4
      end
      object ChkExclamationRoms: TCheckBox
        Left = 146
        Top = 254
        Width = 493
        Height = 22
        Caption = 'Show only roms with '#39'!'#39' in the list'
        Checked = True
        State = cbChecked
        TabOrder = 5
      end
      object ChkprefEXCL: TCheckBox
        Left = 230
        Top = 284
        Width = 221
        Height = 27
        Caption = 'Roms with [!]'
        Checked = True
        State = cbChecked
        TabOrder = 0
      end
      object CmbGMpref1: TComboBox
        Left = 230
        Top = 284
        Width = 221
        Height = 25
        Style = csDropDownList
        ItemHeight = 17
        TabOrder = 1
      end
      object CmbGMpref2: TComboBox
        Left = 230
        Top = 315
        Width = 221
        Height = 25
        Style = csDropDownList
        ItemHeight = 17
        TabOrder = 2
      end
      object CmbGMpref3: TComboBox
        Left = 230
        Top = 347
        Width = 221
        Height = 25
        Style = csDropDownList
        ItemHeight = 17
        TabOrder = 3
      end
    end
    object TabRealIcons: TTabSheet
      Caption = 'Real Icons'
      ImageIndex = 2
      object TLabel
        Left = 63
        Top = 31
        Width = 170
        Height = 21
        Caption = 'MAME Icon Support'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -17
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblMAMElink: TLabel
        Left = 63
        Top = 199
        Width = 672
        Height = 18
        Cursor = crHandPoint
        Caption = 
          'Download MAME icons from MAMu_'#39's sets - try here http://www.prog' +
          'ettosnaps.net/mamu_icons.html '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        OnClick = lblMAMElinkClick
      end
      object TLabel
        Left = 63
        Top = 73
        Width = 552
        Height = 102
        Caption = 
          'By downloading the MAME Icon set QuickPlay can then display each' +
          ' games '#39'proper'#39' Icon.  '#13#10'To activate this, check the box below a' +
          'nd enter in the path to your icons.  If the icons are '#13#10'uncompre' +
          'ssed into a directory, enter the path to the directory. '#13#10#13#10'Also' +
          ' now Quickplay can use a ZIP file to load the icons from.  This ' +
          'feature does not work '#13#10'with any other compression types.'
      end
      object Label2: TLabel
        Left = 94
        Top = 350
        Width = 68
        Height = 17
        Caption = 'Icon Folder'
      end
      object ChkLargeIcons: TCheckBox
        Left = 63
        Top = 268
        Width = 367
        Height = 22
        Caption = 'Use Large Icons (32x32)'
        TabOrder = 1
      end
      object ChkMAMEIcons: TCheckBox
        Left = 63
        Top = 238
        Width = 731
        Height = 22
        Caption = 
          'Enable MAME Icons for this directory (Image support MUST be turn' +
          'ed on in the main options)'
        TabOrder = 0
      end
      object TxtMAMEIconDir: TJvDirectoryEdit
        Left = 178
        Top = 345
        Width = 482
        Height = 25
        ClipboardCommands = []
        DialogKind = dkWin32
        DialogOptions = []
        ButtonWidth = 27
        TabOrder = 2
      end
      object TxtMAMEIconFile: TJvFilenameEdit
        Left = 115
        Top = 418
        Width = 483
        Height = 25
        ClipboardCommands = []
        Filter = 'ZIP files (*.zip)|*.zip|All files (*.*)|*.*'
        Enabled = False
        ButtonWidth = 27
        TabOrder = 3
      end
      object RadMAMEIconsDir: TRadioButton
        Left = 63
        Top = 315
        Width = 409
        Height = 22
        Caption = 'MAME Icons are in a directory'
        Checked = True
        TabOrder = 4
        TabStop = True
        OnClick = RadMAMEIconsDirClick
      end
      object RadMAMEIconsFile: TRadioButton
        Left = 63
        Top = 387
        Width = 409
        Height = 22
        Caption = 'MAME Icons are in a ZIP file.'
        TabOrder = 5
        OnClick = RadMAMEIconsDirClick
      end
    end
  end
  object PanCtrls: TPanel
    Left = 0
    Top = 507
    Width = 808
    Height = 40
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object BtnOK: TButton
      Left = 604
      Top = 4
      Width = 98
      Height = 33
      Caption = '&OK'
      Default = True
      TabOrder = 0
      OnClick = BtnOKClick
    end
    object BtnCancel: TButton
      Left = 709
      Top = 4
      Width = 98
      Height = 33
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
