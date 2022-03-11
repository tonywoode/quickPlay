object FrmROMData: TFrmROMData
  Left = 306
  Top = 406
  BorderStyle = bsDialog
  Caption = 'Import/Export Custom ROM Data'
  ClientHeight = 403
  ClientWidth = 561
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
  PixelsPerInch = 120
  TextHeight = 17
  object PGCustom: TPageControl
    Left = 0
    Top = 0
    Width = 561
    Height = 403
    ActivePage = TabWork
    Align = alClient
    Style = tsButtons
    TabOrder = 0
    object TabIntro: TTabSheet
      Caption = 'Intro'
      object lblTitle: TLabel
        Left = 10
        Top = 0
        Width = 390
        Height = 28
        Caption = 'Import/Export Custom ROM Data'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -23
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblDescription: TLabel
        Left = 21
        Top = 52
        Width = 396
        Height = 119
        Caption = 
          'The custom data importer/exporter can create a file containing '#13 +
          #10'custom data for a ROM, such as company, year, etc.  The '#13#10'custo' +
          'm data can be backed up or distributed to other Quickplay '#13#10'user' +
          's.'#13#10#13#10'The custom data is matched by filename, so it is important' +
          ' your'#13#10'ROMS are named consistently.'
      end
      object RadImport: TRadioButton
        Left = 178
        Top = 217
        Width = 254
        Height = 22
        Caption = 'Import Custom Data'
        TabOrder = 0
      end
      object RadExport: TRadioButton
        Left = 178
        Top = 248
        Width = 273
        Height = 23
        Caption = 'Export Custom Data'
        TabOrder = 1
      end
      object BtnBegin: TButton
        Left = 209
        Top = 290
        Width = 98
        Height = 33
        Caption = '&Begin'
        TabOrder = 2
        OnClick = BtnBeginClick
      end
    end
    object TabWork: TTabSheet
      Caption = 'Worker'
      ImageIndex = 1
      object lblWork: TLabel
        Left = 88
        Top = 21
        Width = 88
        Height = 27
        Caption = 'lblWork'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -22
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblDataFile: TLabel
        Left = 10
        Top = 78
        Width = 51
        Height = 17
        Caption = 'Data File'
      end
      object lblDataOpt: TLabel
        Left = 88
        Top = 115
        Width = 132
        Height = 17
        Caption = 'Custom Data Options'
      end
      object VTOpt: TVirtualStringTree
        Left = 88
        Top = 136
        Width = 198
        Height = 148
        Header.AutoSizeIndex = 0
        Header.DefaultHeight = 17
        Header.Font.Charset = DEFAULT_CHARSET
        Header.Font.Color = clWindowText
        Header.Font.Height = -11
        Header.Font.Name = 'MS Sans Serif'
        Header.Font.Style = []
        Header.MainColumn = -1
        Header.Options = [hoColumnResize, hoDrag]
        RootNodeCount = 8
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
        Left = 293
        Top = 188
        Width = 254
        Height = 23
        Caption = 'Overwrite Existing Data'
        TabOrder = 1
        Visible = False
      end
      object BtnStartWork: TButton
        Left = 220
        Top = 293
        Width = 98
        Height = 33
        Caption = 'Start'
        TabOrder = 2
        OnClick = BtnStartWorkClick
      end
      object TxtDataFile: TJvFilenameEdit
        Left = 88
        Top = 73
        Width = 461
        Height = 25
        OnButtonClick = TxtDataFileButtonClick
        ClipboardCommands = []
        AddQuotes = False
        DefaultExt = '.ini'
        Filter = 'Ini Files (*.ini)|*.ini'
        ButtonWidth = 27
        TabOrder = 3
      end
    end
    object TabDone: TTabSheet
      Caption = 'Done'
      ImageIndex = 3
      object lblDone: TLabel
        Left = 167
        Top = 63
        Width = 107
        Height = 34
        Caption = 'lblDone'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -28
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblEnd: TLabel
        Left = 84
        Top = 146
        Width = 361
        Height = 17
        Caption = 'Press the close button in the corner to return to QuickPlay.'
      end
    end
  end
  object BtnClose: TButton
    Left = 456
    Top = 366
    Width = 98
    Height = 33
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
