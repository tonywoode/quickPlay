object RecursiveFrm: TRecursiveFrm
  Left = 494
  Top = 272
  BorderStyle = bsDialog
  Caption = 'Multi-Directory Scan'
  ClientHeight = 431
  ClientWidth = 574
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 12
    Width = 71
    Height = 13
    Caption = 'Root Directory '
  end
  object VTscan: TVirtualStringTree
    Left = 8
    Top = 87
    Width = 553
    Height = 305
    DefaultNodeHeight = 21
    EditDelay = 0
    Header.AutoSizeIndex = 0
    Header.DefaultHeight = 17
    Header.Font.Charset = DEFAULT_CHARSET
    Header.Font.Color = clWindowText
    Header.Font.Height = -11
    Header.Font.Name = 'MS Sans Serif'
    Header.Font.Style = []
    Header.Options = [hoAutoResize, hoColumnResize, hoVisible]
    Images = MainFrm.IconList
    TabOrder = 0
    TreeOptions.AutoOptions = [toAutoDropExpand, toAutoScrollOnExpand]
    TreeOptions.MiscOptions = [toCheckSupport, toEditable, toFullRepaintOnResize, toGridExtensions, toToggleOnDblClick, toWheelPanning]
    TreeOptions.PaintOptions = [toShowButtons, toShowDropmark, toShowRoot, toShowTreeLines, toShowVertGridLines, toThemeAware, toUseBlendedImages]
    TreeOptions.SelectionOptions = [toExtendedFocus]
    OnBeforeCellPaint = VTscanBeforeCellPaint
    OnChecked = VTscanChecked
    OnCreateEditor = VTscanCreateEditor
    OnEditing = VTscanEditing
    OnExit = VTscanExit
    OnFocusChanged = VTscanFocusChanged
    OnFreeNode = VTscanFreeNode
    OnGetText = VTscanGetText
    OnGetImageIndex = VTscanGetImageIndex
    OnInitChildren = VTscanInitChildren
    OnInitNode = VTscanInitNode
    OnKeyDown = VTscanKeyDown
    OnNewText = VTscanNewText
    Columns = <
      item
        Options = [coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible]
        Position = 0
        Width = 424
        WideText = 'Directory (Check box if directory contains GoodMerge ROMS)'
      end
      item
        Options = [coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible]
        Position = 1
        Width = 125
        WideText = 'Emulator'
      end>
  end
  object ChkAutoMirror: TCheckBox
    Left = 80
    Top = 41
    Width = 321
    Height = 17
    Caption = 'Automatically configure Directory Mirroring'
    Checked = True
    State = cbChecked
    TabOrder = 1
  end
  object BtnOK: TButton
    Left = 416
    Top = 398
    Width = 75
    Height = 25
    Caption = '&OK'
    ModalResult = 1
    TabOrder = 3
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 496
    Top = 398
    Width = 75
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 4
  end
  object ProgScan: TProgressBar
    Left = 8
    Top = 398
    Width = 402
    Height = 17
    Step = 1
    TabOrder = 5
  end
  object ChkSetChild: TCheckBox
    Left = 80
    Top = 64
    Width = 321
    Height = 17
    Caption = 'Set Options Recursively'
    Checked = True
    State = cbChecked
    TabOrder = 2
  end
  object ComboBox1: TComboBox
    Left = 416
    Top = 56
    Width = 145
    Height = 21
    ItemHeight = 13
    TabOrder = 6
    Text = 'ComboBox1'
    Visible = False
  end
  object TxtDir: TJvDirectoryEdit
    Left = 99
    Top = 8
    Width = 467
    Height = 21
    OnAfterDialog = TxtDirAfterDialog
    ClipboardCommands = []
    DialogKind = dkWin32
    DialogOptions = []
    TabOrder = 7
    OnKeyDown = TxtDirKeyDown
  end
end
