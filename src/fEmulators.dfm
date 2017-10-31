object FrmEmuDlg: TFrmEmuDlg
  Left = 245
  Top = 213
  BorderStyle = bsDialog
  Caption = 'Emulator Management'
  ClientHeight = 625
  ClientWidth = 970
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 120
  TextHeight = 17
  object Splitter1: TSplitter
    Left = 250
    Top = 0
    Width = 4
    Height = 585
  end
  object VTEmus: TVirtualStringTree
    Left = 0
    Top = 0
    Width = 250
    Height = 585
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
    Top = 585
    Width = 970
    Height = 40
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object BtnAdd: TButton
      Left = 21
      Top = 4
      Width = 98
      Height = 33
      Caption = '&Add'
      TabOrder = 0
      OnClick = BtnAddClick
    end
    object BtnDelete: TButton
      Left = 126
      Top = 4
      Width = 98
      Height = 33
      Caption = '&Delete'
      TabOrder = 1
      OnClick = BtnDeleteClick
    end
    object BtnOK: TButton
      Left = 764
      Top = 4
      Width = 98
      Height = 33
      Caption = '&OK'
      ModalResult = 1
      TabOrder = 2
      OnClick = BtnOKClick
    end
    object BtnCancel: TButton
      Left = 868
      Top = 4
      Width = 96
      Height = 33
      Caption = '&Cancel'
      ModalResult = 2
      TabOrder = 3
    end
  end
  object pgEmuOpt: TPageControl
    Left = 254
    Top = 0
    Width = 716
    Height = 585
    ActivePage = TabConfiguration
    Align = alClient
    TabOrder = 2
    object TabConfiguration: TTabSheet
      Caption = 'Emulator Configuration'
      object VTEmuOpt: TVirtualStringTree
        Left = 0
        Top = 0
        Width = 708
        Height = 553
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
            Width = 454
            WideText = 'Value'
          end>
      end
    end
    object TabMediaConfig: TTabSheet
      Caption = 'Media Configuration'
      ImageIndex = 1
      OnExit = TabMediaConfigExit
      object lblSysImage: TLabel
        Left = 10
        Top = 73
        Width = 97
        Height = 17
        Caption = 'Emulator Image'
      end
      object MemoEmuInfo: TMemo
        Left = 31
        Top = 167
        Width = 514
        Height = 284
        ScrollBars = ssBoth
        TabOrder = 0
      end
      object ChkShowAddInfo: TCheckBox
        Left = 10
        Top = 126
        Width = 357
        Height = 22
        Caption = 'Show Additional Information'
        TabOrder = 1
      end
      object TxtEmuImage: TJvFilenameEdit
        Left = 136
        Top = 71
        Width = 409
        Height = 25
        OnBeforeDialog = TxtEmuImageBeforeDialog
        OnAfterDialog = TxtEmuImageAfterDialog
        AddQuotes = False
        DialogKind = dkOpenPicture
        DialogOptions = [ofHideReadOnly, ofPathMustExist, ofFileMustExist]
        ButtonWidth = 27
        TabOrder = 2
      end
      object ChkAddEmuTab: TCheckBox
        Left = 10
        Top = 21
        Width = 347
        Height = 22
        Caption = 'Add Emulator Media Tab'
        TabOrder = 3
      end
    end
  end
end
