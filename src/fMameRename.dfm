object DatReader: TDatReader
  Left = 274
  Top = 161
  BorderStyle = bsDialog
  Caption = 'Rename Mame Games'
  ClientHeight = 424
  ClientWidth = 544
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object BtnClose: TButton
    Left = 464
    Top = 392
    Width = 75
    Height = 25
    Caption = '&Close'
    ModalResult = 2
    TabOrder = 0
  end
  object ScanGroup: TGroupBox
    Left = 8
    Top = 240
    Width = 527
    Height = 41
    Caption = 'Scanning Options'
    TabOrder = 1
    object RadSel: TRadioButton
      Left = 32
      Top = 16
      Width = 210
      Height = 17
      Caption = 'Selected Folder'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadAll: TRadioButton
      Left = 248
      Top = 16
      Width = 225
      Height = 17
      Caption = 'All Folders'
      TabOrder = 1
    end
  end
  object GroupProgress: TGroupBox
    Left = 8
    Top = 288
    Width = 529
    Height = 97
    Caption = 'Progress'
    TabOrder = 2
    object Label2: TLabel
      Left = 6
      Top = 28
      Width = 86
      Height = 13
      Caption = 'Comparing Names'
    end
    object Label3: TLabel
      Left = 24
      Top = 60
      Width = 69
      Height = 13
      Caption = 'Total Progress'
    end
    object ProgTotal: TProgressBar
      Left = 136
      Top = 61
      Width = 387
      Height = 16
      Step = 1
      TabOrder = 0
    end
    object ProgCompare: TProgressBar
      Left = 136
      Top = 28
      Width = 387
      Height = 15
      Step = 1
      TabOrder = 1
    end
  end
  object GroupEmu: TGroupBox
    Left = 8
    Top = 8
    Width = 529
    Height = 225
    Caption = 'Emulators'
    TabOrder = 3
    object Label4: TLabel
      Left = 8
      Top = 16
      Width = 307
      Height = 13
      Caption = 'The following emulators are Mame compatible, please select one'
    end
    object VTmame: TVirtualStringTree
      Left = 8
      Top = 39
      Width = 513
      Height = 178
      Header.AutoSizeIndex = 1
      Header.DefaultHeight = 17
      Header.Font.Charset = DEFAULT_CHARSET
      Header.Font.Color = clWindowText
      Header.Font.Height = -11
      Header.Font.Name = 'MS Sans Serif'
      Header.Font.Style = []
      Header.Options = [hoAutoResize, hoColumnResize, hoDrag, hoVisible]
      NodeDataSize = 0
      TabOrder = 0
      TreeOptions.AutoOptions = [toAutoScrollOnExpand, toAutoTristateTracking, toAutoDeleteMovedNodes]
      TreeOptions.PaintOptions = [toThemeAware, toUseBlendedImages]
      TreeOptions.SelectionOptions = [toFullRowSelect]
      OnGetText = VTmameGetText
      Columns = <
        item
          Position = 0
          Width = 125
          WideText = 'Name'
        end
        item
          Position = 1
          Width = 384
          WideText = 'Path'
        end>
    end
  end
  object BtnStart: TButton
    Left = 384
    Top = 392
    Width = 75
    Height = 25
    Caption = '&Start'
    Default = True
    ModalResult = 1
    TabOrder = 4
    OnClick = BtnStartClick
  end
end
