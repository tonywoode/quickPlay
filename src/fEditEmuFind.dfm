object FrmEFindEdit: TFrmEFindEdit
  Left = 282
  Top = 116
  BorderStyle = bsDialog
  Caption = 'Emu-Finder Data Editor'
  ClientHeight = 490
  ClientWidth = 616
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object LstEmus: TListBox
    Left = 8
    Top = 181
    Width = 173
    Height = 276
    ItemHeight = 13
    Sorted = True
    TabOrder = 3
    OnClick = LstEmusClick
  end
  object GrpRecord: TGroupBox
    Left = 186
    Top = 8
    Width = 425
    Height = 449
    Caption = 'Record'
    TabOrder = 6
    OnExit = GrpRecordExit
    object Label1: TLabel
      Left = 55
      Top = 32
      Width = 27
      Height = 13
      Caption = 'Name'
      Enabled = False
    end
    object TLabel
      Left = 20
      Top = 59
      Width = 78
      Height = 26
      Alignment = taRightJustify
      Caption = 'EXE Name'#13#10'(with Extension)'
      Enabled = False
    end
    object TLabel
      Left = 28
      Top = 93
      Width = 70
      Height = 26
      Alignment = taRightJustify
      Caption = 'Config Name '#13#10'(no extension)'
      Enabled = False
    end
    object TLabel
      Left = 51
      Top = 135
      Width = 35
      Height = 13
      Caption = 'System'
      Enabled = False
    end
    object Label2: TLabel
      Left = 32
      Top = 169
      Width = 54
      Height = 13
      Caption = 'Home Page'
      Enabled = False
    end
    object TLabel
      Left = 32
      Top = 204
      Width = 55
      Height = 13
      Caption = 'Parameters'
      Enabled = False
    end
    object lblCompression: TLabel
      Left = 18
      Top = 384
      Width = 61
      Height = 26
      Caption = 'Compression'#13#10'Support'
    end
    object ChkShortExe: TCheckBox
      Left = 104
      Top = 300
      Width = 302
      Height = 17
      Caption = 'Use Short Name (8:3) for EXE Path'
      Enabled = False
      TabOrder = 9
    end
    object ChkVerify: TCheckBox
      Left = 104
      Top = 360
      Width = 305
      Height = 17
      Caption = 'Verify Compressed Files Before Launch'
      Enabled = False
      TabOrder = 12
    end
    object ChkScrSvr: TCheckBox
      Left = 104
      Top = 320
      Width = 310
      Height = 17
      Caption = 'Disable Screensaver on Launch'
      Enabled = False
      TabOrder = 10
    end
    object ChkWinKey: TCheckBox
      Left = 104
      Top = 340
      Width = 302
      Height = 17
      Caption = 'Disable Window Key on Launch'
      Enabled = False
      TabOrder = 11
    end
    object TxtName: TEdit
      Left = 104
      Top = 28
      Width = 294
      Height = 21
      Enabled = False
      TabOrder = 0
    end
    object TxtEXE: TEdit
      Left = 104
      Top = 62
      Width = 174
      Height = 21
      Enabled = False
      TabOrder = 1
    end
    object TxtConfig: TEdit
      Left = 104
      Top = 96
      Width = 174
      Height = 21
      Enabled = False
      TabOrder = 2
    end
    object CmbSystem: TComboBox
      Left = 104
      Top = 131
      Width = 174
      Height = 21
      Style = csDropDownList
      Enabled = False
      ItemHeight = 13
      TabOrder = 3
    end
    object TxtHomePage: TEdit
      Left = 104
      Top = 165
      Width = 294
      Height = 21
      Enabled = False
      TabOrder = 4
    end
    object chkCmdLine: TCheckBox
      Left = 104
      Top = 240
      Width = 270
      Height = 17
      Caption = 'Command lines supported'
      TabOrder = 6
    end
    object ChkShellEx: TCheckBox
      Left = 104
      Top = 260
      Width = 278
      Height = 17
      Caption = 'Shell Integrated'
      TabOrder = 7
    end
    object TxtParam: TEdit
      Left = 104
      Top = 200
      Width = 294
      Height = 21
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
      Left = 104
      Top = 280
      Width = 278
      Height = 17
      Caption = 'Is Win32'
      TabOrder = 8
    end
    object ChkLstCompress: TCheckListBox
      Left = 104
      Top = 384
      Width = 121
      Height = 49
      ItemHeight = 13
      TabOrder = 13
    end
  end
  object LstFiles: TListBox
    Left = 8
    Top = 8
    Width = 173
    Height = 137
    ItemHeight = 13
    TabOrder = 0
    OnClick = LstFilesClick
  end
  object BtnOK: TButton
    Left = 451
    Top = 461
    Width = 75
    Height = 25
    Caption = '&OK'
    ModalResult = 1
    TabOrder = 7
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 535
    Top = 461
    Width = 75
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 8
  end
  object BtnNewINI: TJvImgBtn
    Left = 8
    Top = 152
    Width = 87
    Height = 25
    Caption = 'New File'
    TabOrder = 4
    OnClick = BtnNewINIClick
    HotTrackFont.Charset = DEFAULT_CHARSET
    HotTrackFont.Color = clWindowText
    HotTrackFont.Height = -11
    HotTrackFont.Name = 'Tahoma'
    HotTrackFont.Style = []
    Images = MainFrm.ImageList1
    ImageIndex = 18
  end
  object BtnDelIni: TJvImgBtn
    Left = 101
    Top = 152
    Width = 80
    Height = 25
    Caption = 'Delete'
    TabOrder = 5
    OnClick = BtnDelIniClick
    HotTrackFont.Charset = DEFAULT_CHARSET
    HotTrackFont.Color = clWindowText
    HotTrackFont.Height = -11
    HotTrackFont.Name = 'Tahoma'
    HotTrackFont.Style = []
    Images = MainFrm.ImageList1
    ImageIndex = 3
  end
  object BtnAddEmu: TJvImgBtn
    Left = 8
    Top = 461
    Width = 87
    Height = 25
    Caption = '&Add Emu'
    TabOrder = 1
    WordWrap = False
    OnClick = BtnAddEmuClick
    HotTrackFont.Charset = DEFAULT_CHARSET
    HotTrackFont.Color = clWindowText
    HotTrackFont.Height = -11
    HotTrackFont.Name = 'Tahoma'
    HotTrackFont.Style = []
    Images = MainFrm.ImageList1
    ImageIndex = 2
  end
  object BtnDeleteEmu: TJvImgBtn
    Left = 101
    Top = 461
    Width = 79
    Height = 25
    Caption = '&Delete'
    TabOrder = 2
    WordWrap = False
    OnClick = BtnDeleteEmuClick
    HotTrackFont.Charset = DEFAULT_CHARSET
    HotTrackFont.Color = clWindowText
    HotTrackFont.Height = -11
    HotTrackFont.Name = 'Tahoma'
    HotTrackFont.Style = []
    Images = MainFrm.ImageList1
    ImageIndex = 3
  end
end
