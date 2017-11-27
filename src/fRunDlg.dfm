object FrmRunRom: TFrmRunRom
  Left = 440
  Top = 121
  BorderStyle = bsDialog
  Caption = 'ROM Launching...'
  ClientHeight = 637
  ClientWidth = 1018
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 17
  object TLabel
    Left = 8
    Top = 479
    Width = 201
    Height = 17
    Caption = 'Command Line That Will Be Run:'
  end
  object BtnRun: TButton
    Left = 804
    Top = 592
    Width = 98
    Height = 33
    Caption = '&Run'
    Default = True
    TabOrder = 2
    OnClick = BtnRunClick
  end
  object BtnCancel: TButton
    Left = 909
    Top = 592
    Width = 98
    Height = 33
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object GrpMisc: TGroupBox
    Left = 8
    Top = 367
    Width = 1000
    Height = 98
    Caption = 'Misc Options'
    TabOrder = 1
    object ChkWinKey: TCheckBox
      Left = 532
      Top = 23
      Width = 286
      Height = 22
      Caption = 'Disable Win Key'
      TabOrder = 2
    end
    object chkScrSvr: TCheckBox
      Left = 153
      Top = 25
      Width = 264
      Height = 22
      Caption = 'Disable Screensaver'
      TabOrder = 1
    end
    object ChkMini: TCheckBox
      Left = 532
      Top = 51
      Width = 290
      Height = 22
      Caption = 'Hide QuickPlay on Run'
      TabOrder = 0
    end
    object ChkAutoClose: TCheckBox
      Left = 153
      Top = 53
      Width = 284
      Height = 22
      Caption = 'Close this dialog automatically'
      Checked = True
      State = cbChecked
      TabOrder = 3
    end
  end
  object GrpEmu: TGroupBox
    Left = 10
    Top = 221
    Width = 1000
    Height = 132
    Caption = 'Emulator Options'
    TabOrder = 0
    object lblParam: TLabel
      Left = 22
      Top = 69
      Width = 69
      Height = 17
      Caption = 'Parameters'
    end
    object TLabel
      Left = 102
      Top = 100
      Width = 294
      Height = 18
      Caption = '*Any changes made here are not stored'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ChkShortEXE: TCheckBox
      Left = 530
      Top = 24
      Width = 471
      Height = 22
      Caption = 'Emulator Path in Short Format (8:3)'
      TabOrder = 1
    end
    object ChkCompress: TCheckBox
      Left = 151
      Top = 26
      Width = 267
      Height = 22
      Caption = 'Emulator Supports Compressed Files'
      TabOrder = 0
    end
    object TxtParam: TEdit
      Left = 97
      Top = 69
      Width = 880
      Height = 25
      TabOrder = 2
      OnEnter = TxtParamEnter
      OnExit = TxtParamExit
    end
  end
  object GrpROMInfo: TGroupBox
    Left = 10
    Top = 10
    Width = 1000
    Height = 199
    Caption = 'ROM Information'
    TabOrder = 4
    object TLabel
      Left = 21
      Top = 30
      Width = 68
      Height = 17
      Caption = 'ROM Name'
    end
    object TLabel
      Left = 27
      Top = 59
      Width = 61
      Height = 17
      Caption = 'ROM Path'
    end
    object lblName: TLabel
      Left = 126
      Top = 30
      Width = 4
      Height = 17
    end
    object TLabel
      Left = 35
      Top = 89
      Width = 55
      Height = 17
      Caption = 'Emulator'
    end
    object lblEmu: TLabel
      Left = 126
      Top = 89
      Width = 4
      Height = 17
    end
    object TLabel
      Left = 10
      Top = 119
      Width = 76
      Height = 17
      Caption = 'Archive Valid'
    end
    object lblArchive: TLabel
      Left = 126
      Top = 119
      Width = 4
      Height = 17
    end
    object lblZipStatus: TLabel
      Left = 12
      Top = 149
      Width = 77
      Height = 17
      Caption = 'Extracted to'
    end
    object lblPath: TEdit
      Left = 106
      Top = 55
      Width = 871
      Height = 25
      TabOrder = 0
    end
    object lblArchiveOutput: TEdit
      Left = 106
      Top = 144
      Width = 871
      Height = 25
      TabOrder = 1
    end
  end
  object lblCommand: TRichEdit
    Left = 8
    Top = 503
    Width = 1000
    Height = 73
    Hint = 'Right Click to Copy'
    ParentShowHint = False
    ReadOnly = True
    ScrollBars = ssVertical
    ShowHint = True
    TabOrder = 5
    OnMouseDown = lblCommandMouseDown
  end
end
