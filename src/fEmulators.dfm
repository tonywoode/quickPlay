object FrmEmuDlg: TFrmEmuDlg
  Left = 245
  Top = 213
  BorderStyle = bsDialog
  Caption = 'Emulator Management'
  ClientHeight = 478
  ClientWidth = 742
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
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 191
    Top = 0
    Height = 447
  end
  object VTEmus: TVirtualStringTree
    Left = 0
    Top = 0
    Width = 191
    Height = 447
    Align = alLeft
    Header.AutoSizeIndex = 0
    Header.DefaultHeight = 17
    Header.Font.Charset = DEFAULT_CHARSET
    Header.Font.Color = clWindowText
    Header.Font.Height = -11
    Header.Font.Name = 'MS Shell Dlg 2'
    Header.Font.Style = []
    Header.MainColumn = -1
    Header.Options = [hoColumnResize, hoDrag]
    Images = MainFrm.IconList
    TabOrder = 0
    TreeOptions.AutoOptions = [toAutoDropExpand, toAutoExpand, toAutoScrollOnExpand, toAutoTristateTracking, toAutoDeleteMovedNodes, toDisableAutoscrollOnFocus]
    TreeOptions.MiscOptions = [toFullRepaintOnResize, toInitOnSave, toToggleOnDblClick, toWheelPanning]
    TreeOptions.SelectionOptions = [toFullRowSelect]
    TreeOptions.StringOptions = []
    OnChange = VTEmusChange
    OnCompareNodes = VTEmusCompareNodes
    OnFocusChanging = VTEmusFocusChanging
    OnFreeNode = VTEmusFreeNode
    OnGetText = VTEmusGetText
    OnPaintText = VTEmusPaintText
    OnGetImageIndex = VTEmusGetImageIndex
    OnInitChildren = VTEmusInitChildren
    OnInitNode = VTEmusInitNode
    Columns = <>
  end
  object PanCtrls: TPanel
    Left = 0
    Top = 447
    Width = 742
    Height = 31
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object BtnAdd: TButton
      Left = 16
      Top = 3
      Width = 75
      Height = 25
      Caption = '&Add'
      TabOrder = 0
      OnClick = BtnAddClick
    end
    object BtnDelete: TButton
      Left = 96
      Top = 3
      Width = 75
      Height = 25
      Caption = '&Delete'
      TabOrder = 1
      OnClick = BtnDeleteClick
    end
    object BtnOK: TButton
      Left = 584
      Top = 3
      Width = 75
      Height = 25
      Caption = '&OK'
      ModalResult = 1
      TabOrder = 2
      OnClick = BtnOKClick
    end
    object BtnCancel: TButton
      Left = 664
      Top = 3
      Width = 73
      Height = 25
      Caption = '&Cancel'
      ModalResult = 2
      TabOrder = 3
    end
  end
  object pgEmuOpt: TPageControl
    Left = 194
    Top = 0
    Width = 548
    Height = 447
    ActivePage = TabConfiguration
    Align = alClient
    TabOrder = 2
    object TabConfiguration: TTabSheet
      Caption = 'Emulator Configuration'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object VTEmuOpt: TVirtualStringTree
        Left = 0
        Top = 0
        Width = 540
        Height = 419
        Align = alClient
        DefaultNodeHeight = 25
        Header.AutoSizeIndex = 1
        Header.DefaultHeight = 17
        Header.Font.Charset = DEFAULT_CHARSET
        Header.Font.Color = clWindowText
        Header.Font.Height = -11
        Header.Font.Name = 'MS Sans Serif'
        Header.Font.Style = []
        Header.Options = [hoAutoResize, hoColumnResize, hoDrag]
        HintAnimation = hatNone
        Images = MainFrm.ImageList1
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        TreeOptions.AutoOptions = [toAutoDropExpand, toAutoSpanColumns, toAutoTristateTracking, toAutoDeleteMovedNodes]
        TreeOptions.MiscOptions = [toEditable, toFullRepaintOnResize, toGridExtensions, toInitOnSave, toToggleOnDblClick, toWheelPanning]
        TreeOptions.PaintOptions = [toHideFocusRect, toHideSelection, toShowBackground, toShowButtons, toShowDropmark, toShowHorzGridLines, toShowRoot, toShowVertGridLines, toThemeAware, toUseBlendedImages, toAlwaysHideSelection]
        TreeOptions.SelectionOptions = [toDisableDrawSelection, toExtendedFocus, toFullRowSelect]
        TreeOptions.StringOptions = []
        WantTabs = True
        OnChange = VTEmuOptChange
        OnCreateEditor = VTEmuOptCreateEditor
        OnEditing = VTEmuOptEditing
        OnExit = VTEmuOptExit
        OnGetText = VTEmuOptGetText
        OnPaintText = VTEmuOptPaintText
        OnGetImageIndex = VTEmuOptGetImageIndex
        OnInitChildren = VTEmuOptInitChildren
        OnInitNode = VTEmuOptInitNode
        OnNewText = VTEmuOptNewText
        Columns = <
          item
            Position = 0
            Width = 250
            WideText = 'Caption'
          end
          item
            Position = 1
            Width = 290
            WideText = 'Value'
          end>
      end
    end
    object TabMediaConfig: TTabSheet
      Caption = 'Media Configuration'
      ImageIndex = 1
      OnExit = TabMediaConfigExit
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object lblSysImage: TLabel
        Left = 8
        Top = 56
        Width = 75
        Height = 13
        Caption = 'Emulator Image'
      end
      object MemoEmuInfo: TMemo
        Left = 24
        Top = 128
        Width = 393
        Height = 217
        ScrollBars = ssBoth
        TabOrder = 0
      end
      object ChkShowAddInfo: TCheckBox
        Left = 8
        Top = 96
        Width = 273
        Height = 17
        Caption = 'Show Additional Information'
        TabOrder = 1
      end
      object TxtEmuImage: TJvFilenameEdit
        Left = 104
        Top = 54
        Width = 313
        Height = 21
        OnBeforeDialog = TxtEmuImageBeforeDialog
        OnAfterDialog = TxtEmuImageAfterDialog
        AddQuotes = False
        DialogKind = dkOpenPicture
        DialogOptions = [ofHideReadOnly, ofPathMustExist, ofFileMustExist]
        TabOrder = 2
      end
      object ChkAddEmuTab: TCheckBox
        Left = 8
        Top = 16
        Width = 265
        Height = 17
        Caption = 'Add Emulator Media Tab'
        TabOrder = 3
      end
    end
  end
end
