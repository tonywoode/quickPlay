object FrmBackup: TFrmBackup
  Left = 359
  Top = 169
  BorderStyle = bsDialog
  Caption = 'Backup/Restore Configuration'
  ClientHeight = 272
  ClientWidth = 416
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object pgBackup: TPageControl
    Left = 0
    Top = 0
    Width = 416
    Height = 272
    ActivePage = TabWelcome
    Align = alClient
    Style = tsButtons
    TabOrder = 0
    object TabWelcome: TTabSheet
      Caption = 'TabWelcome'
      object lblTitle: TLabel
        Left = 16
        Top = 24
        Width = 282
        Height = 20
        Caption = 'Backup/Restore Configuration Tool'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object TLabel
        Left = 18
        Top = 72
        Width = 316
        Height = 13
        Caption = 
          'Using this tool you can backup and restore your QP configuration' +
          '.'
      end
      object TLabel
        Left = 18
        Top = 91
        Width = 292
        Height = 13
        Caption = 'Backups are Zip files and are stored in the '#39'backup'#39' directory.'
      end
      object RadBackup: TRadioButton
        Left = 120
        Top = 128
        Width = 209
        Height = 17
        Caption = 'Backup Configuration'
        TabOrder = 0
      end
      object RadRestore: TRadioButton
        Left = 120
        Top = 152
        Width = 252
        Height = 17
        Caption = 'Restore Configuration'
        TabOrder = 1
      end
      object BtnBegin: TButton
        Left = 144
        Top = 184
        Width = 75
        Height = 25
        Caption = 'Begin'
        TabOrder = 2
        OnClick = BtnBeginClick
      end
    end
    object TabBackupComplete: TTabSheet
      Caption = 'TabBackupComplete'
      ImageIndex = 1
      object TLabel
        Left = 48
        Top = 24
        Width = 142
        Height = 19
        Caption = 'Backup Complete'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object TLabel
        Left = 48
        Top = 80
        Width = 185
        Height = 13
        Caption = 'Your configuration has been saved as:'
      end
      object lblBackup: TLabel
        Left = 48
        Top = 112
        Width = 44
        Height = 13
        Caption = 'lblBackup'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
    end
    object TabRestore: TTabSheet
      Caption = 'TabRestore'
      ImageIndex = 2
      object VtRestore: TVirtualStringTree
        Left = 16
        Top = 16
        Width = 377
        Height = 177
        DefaultNodeHeight = 20
        Header.AutoSizeIndex = 0
        Header.Font.Charset = DEFAULT_CHARSET
        Header.Font.Color = clWindowText
        Header.Font.Height = -11
        Header.Font.Name = 'MS Sans Serif'
        Header.Font.Style = []
        Header.MainColumn = -1
        Header.Options = [hoColumnResize, hoDrag]
        TabOrder = 0
        TreeOptions.AutoOptions = [toAutoDropExpand, toAutoScrollOnExpand, toAutoTristateTracking]
        TreeOptions.MiscOptions = [toCheckSupport, toWheelPanning]
        TreeOptions.PaintOptions = [toThemeAware, toUseBlendedImages]
        OnChange = VtRestoreChange
        OnGetText = VtRestoreGetText
        OnInitNode = VtRestoreInitNode
        Columns = <>
      end
      object BtnRestore: TButton
        Left = 160
        Top = 200
        Width = 75
        Height = 25
        Caption = 'Restore'
        TabOrder = 1
        OnClick = BtnRestoreClick
      end
    end
    object TabRestoreComplete: TTabSheet
      Caption = 'TabRestoreComplete'
      ImageIndex = 3
      object TLabel
        Left = 48
        Top = 24
        Width = 147
        Height = 19
        Caption = 'Restore Complete'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object TLabel
        Left = 48
        Top = 72
        Width = 224
        Height = 13
        Caption = 'The following configuration has been restored.'
      end
      object lblRestore: TLabel
        Left = 48
        Top = 104
        Width = 48
        Height = 13
        Caption = 'lblRestore'
      end
    end
  end
  object BtnCancel: TButton
    Left = 336
    Top = 240
    Width = 75
    Height = 25
    Caption = '&Close'
    ModalResult = 2
    TabOrder = 1
  end
end
