object FrmRomProp: TFrmRomProp
  Left = 281
  Top = 141
  BorderStyle = bsDialog
  Caption = 'ROM Properties'
  ClientHeight = 406
  ClientWidth = 465
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
  object BtnOK: TButton
    Left = 302
    Top = 376
    Width = 75
    Height = 25
    Caption = '&OK'
    Default = True
    TabOrder = 0
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 382
    Top = 376
    Width = 75
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object pgProp: TPageControl
    Left = 4
    Top = 2
    Width = 457
    Height = 369
    ActivePage = TabProperties
    TabOrder = 2
    object TabProperties: TTabSheet
      Caption = 'ROM Properties'
      ImageIndex = 3
      object VTData: TVirtualStringTree
        Left = 0
        Top = 0
        Width = 449
        Height = 341
        Align = alClient
        DefaultNodeHeight = 20
        Header.AutoSizeIndex = 1
        Header.Font.Charset = DEFAULT_CHARSET
        Header.Font.Color = clWindowText
        Header.Font.Height = -11
        Header.Font.Name = 'MS Sans Serif'
        Header.Font.Style = []
        Header.Options = [hoAutoResize, hoColumnResize, hoDrag]
        HintAnimation = hatNone
        HintMode = hmHint
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        TreeOptions.MiscOptions = [toEditable, toFullRepaintOnResize, toGridExtensions, toInitOnSave, toToggleOnDblClick, toWheelPanning]
        TreeOptions.PaintOptions = [toHideFocusRect, toHideSelection, toShowHorzGridLines, toShowVertGridLines, toThemeAware, toUseBlendedImages, toAlwaysHideSelection]
        TreeOptions.SelectionOptions = [toDisableDrawSelection, toExtendedFocus, toFullRowSelect]
        TreeOptions.StringOptions = []
        WantTabs = True
        OnCreateEditor = VTDataCreateEditor
        OnEditing = VTDataEditing
        OnFocusChanged = VTDataFocusChanged
        OnGetText = VTDataGetText
        OnPaintText = VTDataPaintText
        OnNewText = VTDataNewText
        Columns = <
          item
            Position = 0
            Width = 125
            WideText = 'Caption'
          end
          item
            Position = 1
            Width = 320
            WideText = 'Value'
          end>
      end
    end
    object TabIPS: TTabSheet
      Caption = 'IPS Manager'
      ImageIndex = 1
      object VTIPS: TVirtualStringTree
        Left = 8
        Top = 8
        Width = 433
        Height = 301
        Header.AutoSizeIndex = -1
        Header.Font.Charset = DEFAULT_CHARSET
        Header.Font.Color = clWindowText
        Header.Font.Height = -11
        Header.Font.Name = 'MS Sans Serif'
        Header.Font.Style = []
        Header.Options = [hoAutoResize, hoColumnResize, hoDrag, hoVisible]
        TabOrder = 0
        TreeOptions.MiscOptions = [toCheckSupport, toEditable, toFullRepaintOnResize, toGridExtensions, toInitOnSave, toToggleOnDblClick, toWheelPanning]
        TreeOptions.PaintOptions = [toHideFocusRect, toThemeAware, toUseBlendedImages, toAlwaysHideSelection]
        TreeOptions.SelectionOptions = [toDisableDrawSelection, toExtendedFocus]
        OnChecked = VTIPSChecked
        OnCreateEditor = VTIPSCreateEditor
        OnEditing = VTIPSEditing
        OnFocusChanged = VTIPSFocusChanged
        OnGetText = VTIPSGetText
        OnInitNode = VTIPSInitNode
        OnNewText = VTIPSNewText
        Columns = <
          item
            Position = 0
            Width = 20
          end
          item
            Position = 1
            Width = 100
            WideText = 'IPS Name'
          end
          item
            Position = 2
            Width = 309
            WideText = 'IPS Path'
          end>
      end
      object BtnIPSAdd: TJvImgBtn
        Left = 8
        Top = 312
        Width = 92
        Height = 25
        Caption = 'Add IPS'
        TabOrder = 1
        OnClick = BtnIPSAddClick
        HotTrackFont.Charset = DEFAULT_CHARSET
        HotTrackFont.Color = clWindowText
        HotTrackFont.Height = -11
        HotTrackFont.Name = 'Tahoma'
        HotTrackFont.Style = []
        Images = MainFrm.ImageList1
        ImageIndex = 22
      end
      object BtnIPSDelete: TJvImgBtn
        Left = 105
        Top = 312
        Width = 105
        Height = 25
        Caption = 'Delete IPS'
        TabOrder = 2
        OnClick = BtnIPSDeleteClick
        HotTrackFont.Charset = DEFAULT_CHARSET
        HotTrackFont.Color = clWindowText
        HotTrackFont.Height = -11
        HotTrackFont.Name = 'Tahoma'
        HotTrackFont.Style = []
        Images = MainFrm.ImageList1
        ImageIndex = 3
      end
      object BtnIPSinvalid: TJvImgBtn
        Left = 240
        Top = 312
        Width = 129
        Height = 25
        Caption = 'Remove invalid'
        TabOrder = 3
        OnClick = BtnIPSinvalidClick
        HotTrackFont.Charset = DEFAULT_CHARSET
        HotTrackFont.Color = clWindowText
        HotTrackFont.Height = -11
        HotTrackFont.Name = 'Tahoma'
        HotTrackFont.Style = []
        Images = MainFrm.ImageList1
        ImageIndex = 3
      end
    end
    object TabFile: TTabSheet
      Caption = 'File Information'
      ImageIndex = 2
      object lblValid: TLabel
        Left = 303
        Top = 52
        Width = 3
        Height = 13
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblIsArchive: TLabel
        Left = 303
        Top = 15
        Width = 14
        Height = 13
        Caption = 'No'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblFileSize: TLabel
        Left = 75
        Top = 52
        Width = 42
        Height = 13
        Caption = '0 bytes'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LblExist: TLabel
        Left = 76
        Top = 15
        Width = 14
        Height = 14
        Caption = 'No'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object TLabel
        Left = 16
        Top = 52
        Width = 38
        Height = 13
        Caption = 'File Size'
      end
      object TLabel
        Left = 8
        Top = 16
        Width = 47
        Height = 13
        Caption = 'File Exists'
      end
      object TLabel
        Left = 228
        Top = 15
        Width = 48
        Height = 13
        Caption = 'Is Archive'
      end
      object TLabel
        Left = 216
        Top = 52
        Width = 61
        Height = 13
        Caption = 'Archive Valid'
      end
      object TLabel
        Left = 10
        Top = 80
        Width = 83
        Height = 13
        Caption = 'Archive Contents'
      end
      object LstContent: TListBox
        Left = 8
        Top = 96
        Width = 433
        Height = 233
        ItemHeight = 13
        TabOrder = 0
      end
    end
  end
  object BtnPrevious: TButton
    Left = 8
    Top = 376
    Width = 75
    Height = 25
    Caption = 'Previous'
    TabOrder = 3
    OnClick = BtnPreviousClick
  end
  object BtnNext: TButton
    Left = 88
    Top = 376
    Width = 75
    Height = 25
    Caption = 'Next'
    TabOrder = 4
    OnClick = BtnNextClick
  end
end
