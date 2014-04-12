object FavForm: TFavForm
  Left = 282
  Top = 240
  BorderStyle = bsDialog
  Caption = 'Organise Favourites'
  ClientHeight = 261
  ClientWidth = 557
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object VTFav: TVirtualStringTree
    Left = 0
    Top = 8
    Width = 464
    Height = 221
    DragMode = dmAutomatic
    DragOperations = [doMove]
    DragType = dtVCL
    Header.AutoSizeIndex = 0
    Header.Font.Charset = DEFAULT_CHARSET
    Header.Font.Color = clWindowText
    Header.Font.Height = -11
    Header.Font.Name = 'MS Sans Serif'
    Header.Font.Style = []
    Header.Options = [hoAutoResize, hoColumnResize, hoDrag, hoVisible]
    NodeDataSize = 0
    TabOrder = 0
    TreeOptions.AutoOptions = [toAutoScrollOnExpand, toAutoTristateTracking]
    TreeOptions.MiscOptions = [toEditable, toFullRepaintOnResize, toGridExtensions, toInitOnSave, toReportMode, toToggleOnDblClick, toWheelPanning]
    TreeOptions.PaintOptions = [toThemeAware, toUseBlendedImages]
    TreeOptions.SelectionOptions = [toExtendedFocus, toFullRowSelect]
    TreeOptions.StringOptions = [toAutoAcceptEditChange]
    OnCreateEditor = VTFavCreateEditor
    OnDragOver = VTFavDragOver
    OnDragDrop = VTFavDragDrop
    OnEditing = VTFavEditing
    OnExit = VTFavExit
    OnFocusChanged = VTFavFocusChanged
    OnFreeNode = VTFavFreeNode
    OnGetText = VTFavGetText
    OnKeyDown = VTFavKeyDown
    OnNewText = VTFavNewText
    Columns = <
      item
        Options = [coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible]
        Position = 0
        Width = 160
        WideText = 'Name'
      end
      item
        Options = [coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible]
        Position = 1
        Width = 220
        WideText = 'Path'
      end
      item
        Options = [coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible]
        Position = 2
        Width = 80
        WideText = 'Emulator'
      end>
  end
  object BtnMoveUp: TButton
    Left = 470
    Top = 40
    Width = 84
    Height = 65
    Hint = 'Move the selected Favourite up'
    Caption = 'Move Up'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    OnClick = BtnMoveUpClick
  end
  object BtnMoveDown: TButton
    Left = 470
    Top = 112
    Width = 84
    Height = 65
    Hint = 'Move the selected Favourite down'
    Caption = 'Move Down'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
    OnClick = BtnMoveDownClick
  end
  object BtnDel: TButton
    Left = 470
    Top = 184
    Width = 82
    Height = 25
    Caption = '&Delete Fav'
    TabOrder = 3
    OnClick = BtnDelClick
  end
  object BtnOK: TButton
    Left = 400
    Top = 232
    Width = 75
    Height = 25
    Caption = '&OK'
    Default = True
    ModalResult = 1
    TabOrder = 4
  end
  object BtnCancel: TButton
    Left = 480
    Top = 232
    Width = 75
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 5
  end
end
