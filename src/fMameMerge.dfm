object FrmMAMEMerged: TFrmMAMEMerged
  Left = 269
  Top = 223
  BorderStyle = bsDialog
  Caption = 'Scan Merged ROMs'
  ClientHeight = 354
  ClientWidth = 522
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lblMAME: TLabel
    Left = 28
    Top = 108
    Width = 46
    Height = 13
    Caption = 'Emulators'
  end
  object Label1: TLabel
    Left = 38
    Top = 270
    Width = 461
    Height = 40
    AutoSize = False
    Caption = 
      'Warning scanning make take a while depending on how many ROMs yo' +
      'u have, please be patient'
    WordWrap = True
  end
  object lblDir: TLabel
    Left = 4
    Top = 11
    Width = 78
    Height = 13
    Caption = 'Folders To Scan'
  end
  object CmbMame: TComboBox
    Left = 108
    Top = 105
    Width = 145
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 3
  end
  object BtnOK: TButton
    Left = 351
    Top = 316
    Width = 75
    Height = 25
    Caption = '&OK'
    TabOrder = 7
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 432
    Top = 316
    Width = 75
    Height = 25
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 8
  end
  object ChkCatVer: TCheckBox
    Left = 108
    Top = 136
    Width = 402
    Height = 17
    Caption = 'Scan Found ROMs with Catver.ini file for GameType and Year'
    TabOrder = 4
  end
  object ListDirs: TListBox
    Left = 108
    Top = 8
    Width = 373
    Height = 89
    ItemHeight = 13
    TabOrder = 0
  end
  object BtnAdd: TJvImgBtn
    Left = 487
    Top = 8
    Width = 27
    Height = 25
    TabOrder = 1
    OnClick = BtnAddClick
    HotTrackFont.Charset = DEFAULT_CHARSET
    HotTrackFont.Color = clWindowText
    HotTrackFont.Height = -11
    HotTrackFont.Name = 'MS Sans Serif'
    HotTrackFont.Style = []
    Images = MainFrm.ImageList1
    ImageIndex = 0
  end
  object BtnDel: TJvImgBtn
    Left = 487
    Top = 40
    Width = 27
    Height = 25
    TabOrder = 2
    OnClick = BtnDelClick
    HotTrackFont.Charset = DEFAULT_CHARSET
    HotTrackFont.Color = clWindowText
    HotTrackFont.Height = -11
    HotTrackFont.Name = 'MS Sans Serif'
    HotTrackFont.Style = []
    Images = MainFrm.ImageList1
    ImageIndex = 3
  end
  object ChkUseOldMAMEMode: TCheckBox
    Left = 108
    Top = 160
    Width = 402
    Height = 17
    Caption = 'Use older MAME command line syntax'
    TabOrder = 5
  end
  object RadGroupCurrScanInfo: TRadioGroup
    Left = 104
    Top = 183
    Width = 410
    Height = 74
    Caption = 'Currently Scanned Information'
    ItemIndex = 0
    Items.Strings = (
      'Clear List before adding ROMs (erases custom data - Fast)'
      'Refresh current ROMs with results (retains custom data - Slow)')
    TabOrder = 6
  end
  object jvBrowse: TJvBrowseForFolderDialog
    Position = fpFormCenter
    RootDirectory = fdRootFolder
    Left = 448
    Top = 56
  end
end
