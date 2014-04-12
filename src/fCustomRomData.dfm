object FrmROMData: TFrmROMData
  Left = 306
  Top = 406
  BorderStyle = bsDialog
  Caption = 'Import/Export Custom ROM Data'
  ClientHeight = 308
  ClientWidth = 429
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
  PixelsPerInch = 96
  TextHeight = 13
  object PGCustom: TPageControl
    Left = 0
    Top = 0
    Width = 429
    Height = 308
    ActivePage = TabIntro
    Align = alClient
    Style = tsButtons
    TabOrder = 0
    object TabIntro: TTabSheet
      Caption = 'Intro'
      object lblTitle: TLabel
        Left = 8
        Top = 0
        Width = 322
        Height = 23
        Caption = 'Import/Export Custom ROM Data'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblDescription: TLabel
        Left = 16
        Top = 40
        Width = 402
        Height = 120
        Caption = 
          'The custom data importer/exporter can create a file containing '#13 +
          #10'custom data for a ROM, such as company, year, etc.  The '#13#10'custo' +
          'm data can be backed up or distributed to other Quickplay '#13#10'user' +
          's.'#13#10#13#10'The custom data is matched by filename, so it is important' +
          ' your'#13#10'ROMS are named consistently.'
      end
      object RadImport: TRadioButton
        Left = 136
        Top = 166
        Width = 194
        Height = 17
        Caption = 'Import Custom Data'
        TabOrder = 0
      end
      object RadExport: TRadioButton
        Left = 136
        Top = 190
        Width = 209
        Height = 17
        Caption = 'Export Custom Data'
        TabOrder = 1
      end
      object BtnBegin: TButton
        Left = 160
        Top = 222
        Width = 75
        Height = 25
        Caption = '&Begin'
        TabOrder = 2
        OnClick = BtnBeginClick
      end
    end
    object TabWork: TTabSheet
      Caption = 'Worker'
      ImageIndex = 1
      object lblWork: TLabel
        Left = 67
        Top = 16
        Width = 63
        Height = 19
        Caption = 'lblWork'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblDataFile: TLabel
        Left = 8
        Top = 60
        Width = 42
        Height = 13
        Caption = 'Data File'
      end
      object lblDataOpt: TLabel
        Left = 67
        Top = 88
        Width = 101
        Height = 13
        Caption = 'Custom Data Options'
      end
      object VTOpt: TVirtualStringTree
        Left = 67
        Top = 104
        Width = 152
        Height = 113
        Header.AutoSizeIndex = 0
        Header.Font.Charset = DEFAULT_CHARSET
        Header.Font.Color = clWindowText
        Header.Font.Height = -11
        Header.Font.Name = 'MS Sans Serif'
        Header.Font.Style = []
        Header.MainColumn = -1
        Header.Options = [hoColumnResize, hoDrag]
        RootNodeCount = 6
        TabOrder = 0
        TreeOptions.AutoOptions = []
        TreeOptions.MiscOptions = [toCheckSupport, toFullRepaintOnResize, toInitOnSave, toToggleOnDblClick, toWheelPanning]
        TreeOptions.PaintOptions = [toHideFocusRect, toHideSelection, toThemeAware, toUseBlendedImages]
        TreeOptions.SelectionOptions = [toFullRowSelect]
        TreeOptions.StringOptions = []
        OnGetText = VTOptGetText
        OnInitNode = VTOptInitNode
        Columns = <>
      end
      object ChkOverwrite: TCheckBox
        Left = 224
        Top = 144
        Width = 194
        Height = 17
        Caption = 'Overwrite Existing Data'
        TabOrder = 1
        Visible = False
      end
      object BtnStartWork: TButton
        Left = 168
        Top = 224
        Width = 75
        Height = 25
        Caption = 'Start'
        TabOrder = 2
        OnClick = BtnStartWorkClick
      end
      object TxtDataFile: TJvFilenameEdit
        Left = 67
        Top = 56
        Width = 353
        Height = 21
        OnButtonClick = TxtDataFileButtonClick
        ClipboardCommands = []
        AddQuotes = False
        DefaultExt = '.ini'
        Filter = 'Ini Files (*.ini)|*.ini'
        TabOrder = 3
      end
    end
    object TabDone: TTabSheet
      Caption = 'Done'
      ImageIndex = 3
      object lblDone: TLabel
        Left = 128
        Top = 48
        Width = 79
        Height = 25
        Caption = 'lblDone'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblEnd: TLabel
        Left = 64
        Top = 112
        Width = 283
        Height = 13
        Caption = 'Press the close button in the corner to return to QuickPlay.'
      end
    end
  end
  object BtnClose: TButton
    Left = 349
    Top = 280
    Width = 75
    Height = 25
    Caption = '&Close'
    ModalResult = 2
    TabOrder = 1
  end
  object OpenDlg: TOpenDialog
    DefaultExt = 'ini'
    Filter = 'Ini File|*.ini'
    Title = 'Find Data File'
    Left = 260
    Top = 19
  end
end
