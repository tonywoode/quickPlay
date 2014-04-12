object FindForm: TFindForm
  Left = 283
  Top = 172
  BorderStyle = bsDialog
  Caption = 'Find a Rom'
  ClientHeight = 447
  ClientWidth = 519
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Icon.Data = {
    0000010001001010100000000000280100001600000028000000100000002000
    0000010004000000000000000000000000000000000010000000000000000000
    0000000080000080000000808000800000008000800080800000C0C0C0008080
    80000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    FFFFFFFFF000000FF9999999FF0000FF999999999F000FF99FFFFFFFFF000F99
    FF00000000000F99F000000000000F99FFFFFFFF00000F999999999FF0000F99
    99999999F0000F99FFFFFFFFF0000F999FF0000000000FF999F00000000000FF
    99FFFFFFF000000F99999999FF00000FF99999999F000000FFFFFFFFFF00F007
    0000E0030000C00300008003000083FF000087FF0000800F0000800700008007
    00008007000081FF000081FF0000C0070000E0030000E0030000F0030000}
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar: TStatusBar
    Left = 0
    Top = 428
    Width = 519
    Height = 19
    Panels = <>
    SimplePanel = True
  end
  object PanControls: TPanel
    Left = 0
    Top = 384
    Width = 521
    Height = 42
    BevelOuter = bvNone
    TabOrder = 2
    object BtnRun: TButton
      Left = 6
      Top = 11
      Width = 81
      Height = 25
      Action = ActRun
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
    end
    object BtnFavs: TButton
      Left = 92
      Top = 11
      Width = 88
      Height = 25
      Action = ActAddFav
      TabOrder = 1
    end
    object BtnJump: TButton
      Left = 183
      Top = 11
      Width = 91
      Height = 25
      Action = ActJump
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
    end
    object BtnClose: TButton
      Left = 440
      Top = 11
      Width = 75
      Height = 25
      Caption = '&Close'
      ModalResult = 1
      TabOrder = 4
    end
    object BtnVirtual: TButton
      Left = 280
      Top = 11
      Width = 138
      Height = 25
      Caption = 'Save as Virtual Folder'
      Enabled = False
      TabOrder = 3
      OnClick = BtnVirtualClick
    end
    object BtnEditOK: TButton
      Left = 344
      Top = 16
      Width = 75
      Height = 25
      Caption = 'OK'
      ModalResult = 1
      TabOrder = 5
      Visible = False
    end
    object BtnEditCancel: TButton
      Left = 432
      Top = 16
      Width = 75
      Height = 25
      Caption = 'Cancel'
      ModalResult = 2
      TabOrder = 6
      Visible = False
    end
  end
  object VTfind: TVirtualStringTree
    Left = 0
    Top = 184
    Width = 519
    Height = 202
    Header.AutoSizeIndex = 0
    Header.DefaultHeight = 17
    Header.Font.Charset = DEFAULT_CHARSET
    Header.Font.Color = clWindowText
    Header.Font.Height = -11
    Header.Font.Name = 'Tahoma'
    Header.Font.Style = []
    Header.Options = [hoAutoResize, hoColumnResize, hoDrag, hoVisible]
    HintAnimation = hatNone
    HintMode = hmHint
    IncrementalSearch = isAll
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    TreeOptions.MiscOptions = [toFullRepaintOnResize, toInitOnSave, toToggleOnDblClick, toWheelPanning]
    TreeOptions.PaintOptions = [toShowButtons, toShowDropmark, toShowRoot, toThemeAware, toUseBlendedImages]
    TreeOptions.SelectionOptions = [toFullRowSelect]
    OnCompareNodes = VTfindCompareNodes
    OnFreeNode = VTfindFreeNode
    OnGetText = VTfindGetText
    OnGetHint = VTfindGetHint
    OnIncrementalSearch = VTfindIncrementalSearch
    Columns = <
      item
        Position = 0
        Width = 215
        WideText = 'Name'
      end
      item
        Position = 1
        Width = 100
        WideText = 'Emulator'
      end
      item
        Position = 2
        Width = 200
        WideText = 'Path'
      end>
  end
  object PanFilter: TPanel
    Left = 1
    Top = 0
    Width = 517
    Height = 185
    BevelOuter = bvNone
    TabOrder = 0
    object RadMatchAll: TRadioButton
      Left = 5
      Top = 122
      Width = 157
      Height = 17
      Caption = 'Match All Criteria'
      Checked = True
      TabOrder = 1
      TabStop = True
    end
    object RadMatchAny: TRadioButton
      Left = 167
      Top = 122
      Width = 185
      Height = 17
      Caption = 'Match Any Criteria'
      TabOrder = 2
    end
    object VTQuery: TVirtualStringTree
      Left = 8
      Top = 16
      Width = 505
      Height = 100
      Header.AutoSizeIndex = 2
      Header.DefaultHeight = 17
      Header.Font.Charset = DEFAULT_CHARSET
      Header.Font.Color = clWindowText
      Header.Font.Height = -11
      Header.Font.Name = 'MS Sans Serif'
      Header.Font.Style = []
      Header.Options = [hoAutoResize, hoColumnResize, hoDrag]
      TabOrder = 0
      TreeOptions.AutoOptions = [toAutoScrollOnExpand]
      TreeOptions.MiscOptions = [toEditable, toFullRepaintOnResize, toGridExtensions, toInitOnSave, toReportMode, toToggleOnDblClick, toWheelPanning]
      TreeOptions.PaintOptions = [toThemeAware, toUseBlendedImages]
      TreeOptions.SelectionOptions = [toExtendedFocus, toFullRowSelect]
      OnCreateEditor = VTQueryCreateEditor
      OnEditing = VTQueryEditing
      OnExit = VTQueryExit
      OnFocusChanged = VTQueryFocusChanged
      OnFreeNode = VTQueryFreeNode
      OnGetText = VTQueryGetText
      OnNewText = VTQueryNewText
      Columns = <
        item
          Position = 0
          Width = 175
          WideText = 'Property'
        end
        item
          Position = 1
          Width = 100
          WideText = 'Contains'
        end
        item
          Position = 2
          Width = 226
          WideText = 'Query'
        end>
    end
    object BtnAdd: TButton
      Left = 358
      Top = 120
      Width = 75
      Height = 25
      Caption = 'Add'
      TabOrder = 3
      OnClick = BtnAddClick
    end
    object BtnDel: TButton
      Left = 438
      Top = 120
      Width = 75
      Height = 25
      Caption = 'Remove'
      Enabled = False
      TabOrder = 4
      OnClick = BtnDelClick
    end
    object BtnSearch: TButton
      Left = 222
      Top = 153
      Width = 75
      Height = 25
      Caption = '&Search'
      Default = True
      TabOrder = 5
      OnClick = BtnSearchClick
    end
  end
  object FindAct: TActionList
    Images = MainFrm.ImageList1
    OnUpdate = FindActUpdate
    Left = 400
    Top = 40
    object ActRun: TAction
      Caption = 'Run Rom'
      Enabled = False
      Hint = 'Run the Currently Selected Rom'
      ImageIndex = 11
      OnExecute = ActRunExecute
    end
    object ActJump: TAction
      Caption = 'Jump to Rom'
      Enabled = False
      Hint = 'Jump to the Selected Rom'
      OnExecute = ActJumpExecute
    end
    object ActAddFav: TAction
      Caption = 'Add To Favs'
      OnExecute = ActAddFavExecute
    end
  end
  object FindPop: TPopupMenu
    Images = MainFrm.ImageList1
    Left = 400
    Top = 72
    object PopRun: TMenuItem
      Action = ActRun
    end
    object PopAdd: TMenuItem
      Action = ActAddFav
      Enabled = False
    end
    object PopJump: TMenuItem
      Action = ActJump
    end
  end
end
