object FindForm: TFindForm
  Left = 283
  Top = 172
  BorderStyle = bsDialog
  Caption = 'Find a Rom'
  ClientHeight = 730
  ClientWidth = 1018
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
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
  PixelsPerInch = 120
  TextHeight = 17
  object StatusBar: TStatusBar
    Left = 0
    Top = 711
    Width = 1018
    Height = 19
    Panels = <>
    SimplePanel = True
    ExplicitTop = 566
    ExplicitWidth = 679
  end
  object PanControls: TPanel
    Left = 0
    Top = 650
    Width = 1018
    Height = 55
    BevelOuter = bvNone
    TabOrder = 2
    object BtnRun: TButton
      Left = 8
      Top = 14
      Width = 106
      Height = 33
      Action = ActRun
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
    end
    object BtnFavs: TButton
      Left = 170
      Top = 14
      Width = 115
      Height = 33
      Action = ActAddFav
      TabOrder = 1
    end
    object BtnJump: TButton
      Left = 343
      Top = 14
      Width = 119
      Height = 33
      Action = ActJump
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
    end
    object BtnClose: TButton
      Left = 903
      Top = 22
      Width = 98
      Height = 33
      Caption = '&Close'
      ModalResult = 1
      TabOrder = 4
    end
    object BtnVirtual: TButton
      Left = 542
      Top = 14
      Width = 181
      Height = 33
      Caption = 'Save as Virtual Folder'
      Enabled = False
      TabOrder = 3
      OnClick = BtnVirtualClick
    end
    object BtnEditOK: TButton
      Left = 450
      Top = 21
      Width = 98
      Height = 33
      Caption = 'OK'
      ModalResult = 1
      TabOrder = 5
      Visible = False
    end
    object BtnEditCancel: TButton
      Left = 565
      Top = 21
      Width = 98
      Height = 33
      Caption = 'Cancel'
      ModalResult = 2
      TabOrder = 6
      Visible = False
    end
  end
  object VTfind: TVirtualStringTree
    Left = 0
    Top = 235
    Width = 1018
    Height = 423
    Header.AutoSizeIndex = 0
    Header.DefaultHeight = 17
    Header.Font.Charset = DEFAULT_CHARSET
    Header.Font.Color = clWindowText
    Header.Font.Height = -11
    Header.Font.Name = 'Tahoma'
    Header.Font.Style = []
    Header.Options = [hoColumnResize, hoDrag, hoVisible]
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
        Width = 380
        WideText = 'Name'
      end
      item
        Position = 1
        Width = 480
        WideText = 'Emulator'
      end
      item
        Position = 2
        Width = 154
        WideText = 'Path'
      end>
  end
  object PanFilter: TPanel
    Left = 0
    Top = -8
    Width = 1017
    Height = 242
    BevelOuter = bvNone
    TabOrder = 0
    object RadMatchAll: TRadioButton
      Left = 79
      Top = 179
      Width = 205
      Height = 22
      Caption = 'Match All Criteria'
      Checked = True
      TabOrder = 1
      TabStop = True
    end
    object RadMatchAny: TRadioButton
      Left = 290
      Top = 179
      Width = 242
      Height = 22
      Caption = 'Match Any Criteria'
      TabOrder = 2
    end
    object VTQuery: TVirtualStringTree
      Left = 10
      Top = 21
      Width = 991
      Height = 131
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
          Width = 275
          WideText = 'Property'
        end
        item
          Position = 1
          Width = 200
          WideText = 'Contains'
        end
        item
          Position = 2
          Width = 512
          WideText = 'Query'
        end>
    end
    object BtnAdd: TButton
      Left = 610
      Top = 173
      Width = 98
      Height = 33
      Caption = 'Add'
      TabOrder = 3
      OnClick = BtnAddClick
    end
    object BtnDel: TButton
      Left = 715
      Top = 173
      Width = 98
      Height = 33
      Caption = 'Remove'
      Enabled = False
      TabOrder = 4
      OnClick = BtnDelClick
    end
    object BtnSearch: TButton
      Left = 903
      Top = 173
      Width = 98
      Height = 33
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
