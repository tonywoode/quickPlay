object FrmEFindEdit: TFrmEFindEdit
  Left = 282
  Top = 116
  BorderStyle = bsDialog
  Caption = 'Emu-Finder Data Editor'
  ClientHeight = 641
  ClientWidth = 1018
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 17
  object LstEmus: TListBox
    Left = 10
    Top = 237
    Width = 438
    Height = 361
    ItemHeight = 17
    Sorted = True
    TabOrder = 3
    OnClick = LstEmusClick
  end
  object GrpRecord: TGroupBox
    Left = 454
    Top = 9
    Width = 556
    Height = 588
    Caption = 'Record'
    TabOrder = 6
    OnExit = GrpRecordExit
    object Label1: TLabel
      Left = 72
      Top = 42
      Width = 35
      Height = 17
      Caption = 'Name'
      Enabled = False
    end
    object TLabel
      Left = 29
      Top = 77
      Width = 99
      Height = 34
      Alignment = taRightJustify
      Caption = 'EXE Name'#13#10'(with Extension)'
      Enabled = False
    end
    object TLabel
      Left = 39
      Top = 122
      Width = 89
      Height = 34
      Alignment = taRightJustify
      Caption = 'Config Name '#13#10'(no extension)'
      Enabled = False
    end
    object TLabel
      Left = 67
      Top = 177
      Width = 46
      Height = 17
      Caption = 'System'
      Enabled = False
    end
    object Label2: TLabel
      Left = 42
      Top = 221
      Width = 70
      Height = 17
      Caption = 'Home Page'
      Enabled = False
    end
    object TLabel
      Left = 42
      Top = 267
      Width = 69
      Height = 17
      Caption = 'Parameters'
      Enabled = False
    end
    object lblCompression: TLabel
      Left = 24
      Top = 502
      Width = 79
      Height = 34
      Caption = 'Compression'#13#10'Support'
    end
    object ChkShortExe: TCheckBox
      Left = 136
      Top = 392
      Width = 395
      Height = 23
      Caption = 'Use Short Name (8:3) for EXE Path'
      Enabled = False
      TabOrder = 9
    end
    object ChkVerify: TCheckBox
      Left = 136
      Top = 471
      Width = 399
      Height = 22
      Caption = 'Verify Compressed Files Before Launch'
      Enabled = False
      TabOrder = 12
    end
    object ChkScrSvr: TCheckBox
      Left = 136
      Top = 418
      Width = 405
      Height = 23
      Caption = 'Disable Screensaver on Launch'
      Enabled = False
      TabOrder = 10
    end
    object ChkWinKey: TCheckBox
      Left = 136
      Top = 445
      Width = 395
      Height = 22
      Caption = 'Disable Window Key on Launch'
      Enabled = False
      TabOrder = 11
    end
    object TxtName: TEdit
      Left = 136
      Top = 37
      Width = 384
      Height = 25
      Enabled = False
      TabOrder = 0
    end
    object TxtEXE: TEdit
      Left = 136
      Top = 81
      Width = 228
      Height = 25
      Enabled = False
      TabOrder = 1
    end
    object TxtConfig: TEdit
      Left = 136
      Top = 126
      Width = 228
      Height = 25
      Enabled = False
      TabOrder = 2
    end
    object CmbSystem: TComboBox
      Left = 136
      Top = 171
      Width = 228
      Height = 25
      Style = csDropDownList
      Enabled = False
      ItemHeight = 17
      TabOrder = 3
    end
    object TxtHomePage: TEdit
      Left = 136
      Top = 216
      Width = 384
      Height = 25
      Enabled = False
      TabOrder = 4
    end
    object chkCmdLine: TCheckBox
      Left = 136
      Top = 314
      Width = 353
      Height = 22
      Caption = 'Command lines supported'
      TabOrder = 6
    end
    object ChkShellEx: TCheckBox
      Left = 136
      Top = 340
      Width = 364
      Height = 22
      Caption = 'Shell Integrated'
      TabOrder = 7
    end
    object TxtParam: TEdit
      Left = 136
      Top = 262
      Width = 384
      Height = 25
      Hint = 
        'Available Variables'#13#10'------------------------------------'#13#10'%ROM%' +
        ' - The full path to the selected ROM.'#13#10'%ROMFILENAME% - The filen' +
        'ame of the ROM, includes file extension.'#13#10'%ROMFILENAMENOEXT% - T' +
        'he filename of the ROM, with NO file extension.'#13#10'%ROMDIR% - The ' +
        'directory of the ROM.'#13#10'%ROMMAME% - Internal MAME name variable, ' +
        'falls back to %ROMFILENAMENOEXT%'#13#10'%SHORTROM% - The full path to ' +
        'the selected ROM in (8:3) format'#13#10'%SHORTDIR% - The ROMs director' +
        'y in short format (8:3)'
      Enabled = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 5
    end
    object ChkWin32: TCheckBox
      Left = 136
      Top = 366
      Width = 364
      Height = 22
      Caption = 'Is Win32'
      TabOrder = 8
    end
    object ChkLstCompress: TCheckListBox
      Left = 136
      Top = 502
      Width = 158
      Height = 64
      ItemHeight = 17
      TabOrder = 13
    end
  end
  object LstFiles: TListBox
    Left = 10
    Top = 10
    Width = 438
    Height = 180
    ItemHeight = 17
    TabOrder = 0
    OnClick = LstFilesClick
  end
  object BtnOK: TButton
    Left = 798
    Top = 603
    Width = 98
    Height = 33
    Caption = '&OK'
    ModalResult = 1
    TabOrder = 7
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 908
    Top = 603
    Width = 98
    Height = 33
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 8
  end
  object BtnNewINI: TJvImgBtn
    Left = 10
    Top = 199
    Width = 114
    Height = 32
    Caption = 'New File'
    TabOrder = 4
    OnClick = BtnNewINIClick
    HotTrackFont.Charset = DEFAULT_CHARSET
    HotTrackFont.Color = clWindowText
    HotTrackFont.Height = -14
    HotTrackFont.Name = 'Tahoma'
    HotTrackFont.Style = []
    Images = MainFrm.ImageList1
    ImageIndex = 18
  end
  object BtnDelIni: TJvImgBtn
    Left = 132
    Top = 199
    Width = 105
    Height = 32
    Caption = 'Delete'
    TabOrder = 5
    OnClick = BtnDelIniClick
    HotTrackFont.Charset = DEFAULT_CHARSET
    HotTrackFont.Color = clWindowText
    HotTrackFont.Height = -14
    HotTrackFont.Name = 'Tahoma'
    HotTrackFont.Style = []
    Images = MainFrm.ImageList1
    ImageIndex = 3
  end
  object BtnAddEmu: TJvImgBtn
    Left = 10
    Top = 603
    Width = 114
    Height = 33
    Caption = '&Add Emu'
    TabOrder = 1
    WordWrap = False
    OnClick = BtnAddEmuClick
    HotTrackFont.Charset = DEFAULT_CHARSET
    HotTrackFont.Color = clWindowText
    HotTrackFont.Height = -14
    HotTrackFont.Name = 'Tahoma'
    HotTrackFont.Style = []
    Images = MainFrm.ImageList1
    ImageIndex = 2
  end
  object BtnDeleteEmu: TJvImgBtn
    Left = 132
    Top = 603
    Width = 103
    Height = 33
    Caption = '&Delete'
    TabOrder = 2
    WordWrap = False
    OnClick = BtnDeleteEmuClick
    HotTrackFont.Charset = DEFAULT_CHARSET
    HotTrackFont.Color = clWindowText
    HotTrackFont.Height = -14
    HotTrackFont.Name = 'Tahoma'
    HotTrackFont.Style = []
    Images = MainFrm.ImageList1
    ImageIndex = 3
  end
end
