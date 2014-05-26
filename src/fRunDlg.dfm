object FrmRunRom: TFrmRunRom
  Left = 440
  Top = 121
  BorderStyle = bsDialog
  Caption = 'ROM Launching...'
  ClientHeight = 564
  ClientWidth = 409
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object TLabel
    Left = 8
    Top = 434
    Width = 154
    Height = 13
    Caption = 'Command Line That Will Be Run:'
  end
  object BtnRun: TButton
    Left = 248
    Top = 533
    Width = 75
    Height = 25
    Caption = '&Run'
    Default = True
    TabOrder = 2
    OnClick = BtnRunClick
  end
  object BtnCancel: TButton
    Left = 328
    Top = 533
    Width = 75
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object GrpMisc: TGroupBox
    Left = 8
    Top = 305
    Width = 392
    Height = 120
    Caption = 'Misc Options'
    TabOrder = 1
    object ChkWinKey: TCheckBox
      Left = 13
      Top = 48
      Width = 219
      Height = 17
      Caption = 'Disable Win Key'
      TabOrder = 2
    end
    object chkScrSvr: TCheckBox
      Left = 13
      Top = 25
      Width = 214
      Height = 17
      Caption = 'Disable Screensaver'
      TabOrder = 1
    end
    object ChkMini: TCheckBox
      Left = 13
      Top = 94
      Width = 222
      Height = 17
      Caption = 'Hide QuickPlay on Run'
      TabOrder = 0
    end
    object ChkAutoClose: TCheckBox
      Left = 13
      Top = 71
      Width = 217
      Height = 17
      Caption = 'Close this dialog automatically'
      Checked = True
      State = cbChecked
      TabOrder = 3
    end
  end
  object GrpEmu: TGroupBox
    Left = 8
    Top = 175
    Width = 392
    Height = 124
    Caption = 'Emulator Options'
    TabOrder = 0
    object lblParam: TLabel
      Left = 11
      Top = 77
      Width = 55
      Height = 13
      Caption = 'Parameters'
    end
    object TLabel
      Left = 72
      Top = 101
      Width = 227
      Height = 13
      Caption = '*Any changes made here are not stored'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ChkShortEXE: TCheckBox
      Left = 17
      Top = 49
      Width = 360
      Height = 17
      Caption = 'Emulator Path in Short Format (8:3)'
      TabOrder = 1
    end
    object ChkCompress: TCheckBox
      Left = 17
      Top = 26
      Width = 360
      Height = 17
      Caption = 'Emulator Supports Compressed Files'
      TabOrder = 0
    end
    object TxtParam: TEdit
      Left = 72
      Top = 74
      Width = 308
      Height = 21
      TabOrder = 2
      OnEnter = TxtParamEnter
      OnExit = TxtParamExit
    end
  end
  object GrpROMInfo: TGroupBox
    Left = 8
    Top = 8
    Width = 392
    Height = 161
    Caption = 'ROM Information'
    TabOrder = 4
    object TLabel
      Left = 16
      Top = 23
      Width = 53
      Height = 13
      Caption = 'ROM Name'
    end
    object TLabel
      Left = 21
      Top = 45
      Width = 48
      Height = 13
      Caption = 'ROM Path'
    end
    object lblName: TLabel
      Left = 96
      Top = 23
      Width = 3
      Height = 13
    end
    object TLabel
      Left = 27
      Top = 68
      Width = 42
      Height = 13
      Caption = 'Emulator'
    end
    object lblEmu: TLabel
      Left = 96
      Top = 68
      Width = 3
      Height = 13
    end
    object TLabel
      Left = 8
      Top = 91
      Width = 61
      Height = 13
      Caption = 'Archive Valid'
    end
    object lblArchive: TLabel
      Left = 96
      Top = 91
      Width = 3
      Height = 13
    end
    object lblZipStatus: TLabel
      Left = 9
      Top = 114
      Width = 60
      Height = 13
      Caption = 'Extracted to'
    end
    object lblPath: TEdit
      Left = 81
      Top = 42
      Width = 308
      Height = 21
      TabOrder = 0
    end
    object lblArchiveOutput: TEdit
      Left = 81
      Top = 110
      Width = 308
      Height = 21
      TabOrder = 1
    end
  end
  object lblCommand: TRichEdit
    Left = 8
    Top = 453
    Width = 393
    Height = 74
    Hint = 'Right Click to Copy'
    ParentShowHint = False
    ReadOnly = True
    ScrollBars = ssVertical
    ShowHint = True
    TabOrder = 5
    OnMouseDown = lblCommandMouseDown
  end
end
