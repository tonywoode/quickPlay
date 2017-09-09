object DatReader: TDatReader
  Left = 274
  Top = 161
  BorderStyle = bsDialog
  Caption = 'Rename Mame Games'
  ClientHeight = 554
  ClientWidth = 711
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 17
  object BtnClose: TButton
    Left = 607
    Top = 513
    Width = 98
    Height = 32
    Caption = '&Close'
    ModalResult = 2
    TabOrder = 0
  end
  object ScanGroup: TGroupBox
    Left = 10
    Top = 314
    Width = 690
    Height = 53
    Caption = 'Scanning Options'
    TabOrder = 1
    object RadSel: TRadioButton
      Left = 42
      Top = 21
      Width = 274
      Height = 22
      Caption = 'Selected Folder'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadAll: TRadioButton
      Left = 324
      Top = 21
      Width = 295
      Height = 22
      Caption = 'All Folders'
      TabOrder = 1
    end
  end
  object GroupProgress: TGroupBox
    Left = 10
    Top = 377
    Width = 692
    Height = 126
    Caption = 'Progress'
    TabOrder = 2
    object Label2: TLabel
      Left = 8
      Top = 37
      Width = 112
      Height = 17
      Caption = 'Comparing Names'
    end
    object Label3: TLabel
      Left = 31
      Top = 78
      Width = 87
      Height = 17
      Caption = 'Total Progress'
    end
    object ProgTotal: TProgressBar
      Left = 178
      Top = 80
      Width = 506
      Height = 21
      Step = 1
      TabOrder = 0
    end
    object ProgCompare: TProgressBar
      Left = 178
      Top = 37
      Width = 506
      Height = 19
      Step = 1
      TabOrder = 1
    end
  end
  object GroupEmu: TGroupBox
    Left = 10
    Top = 10
    Width = 692
    Height = 295
    Caption = 'Emulators'
    TabOrder = 3
    object Label4: TLabel
      Left = 10
      Top = 21
      Width = 386
      Height = 17
      Caption = 'The following emulators are Mame compatible, please select one'
    end
    object VTmame: TVirtualStringTree
      Left = 10
      Top = 51
      Width = 671
      Height = 233
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
          Width = 542
          WideText = 'Path'
        end>
    end
  end
  object BtnStart: TButton
    Left = 502
    Top = 513
    Width = 98
    Height = 32
    Caption = '&Start'
    Default = True
    ModalResult = 1
    TabOrder = 4
    OnClick = BtnStartClick
  end
end
