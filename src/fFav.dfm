object FavForm: TFavForm
  Left = 282
  Top = 240
  BorderStyle = bsDialog
  Caption = 'Organise Favourites'
  ClientHeight = 730
  ClientWidth = 1018
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 17
  object VTFav: TVirtualStringTree
    Left = 0
    Top = 10
    Width = 895
    Height = 673
    DragMode = dmAutomatic
    DragOperations = [doMove]
    DragType = dtVCL
    Header.AutoSizeIndex = 0
    Header.DefaultHeight = 17
    Header.Font.Charset = DEFAULT_CHARSET
    Header.Font.Color = clWindowText
    Header.Font.Height = -11
    Header.Font.Name = 'MS Sans Serif'
    Header.Font.Style = []
    Header.Options = [hoColumnResize, hoDrag, hoVisible]
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
        Width = 250
        WideText = 'Name'
      end
      item
        Options = [coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible]
        Position = 1
        Width = 461
        WideText = 'Path'
      end
      item
        Options = [coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible]
        Position = 2
        Width = 180
        WideText = 'Emulator'
      end>
  end
  object BtnMoveUp: TButton
    Left = 901
    Top = 10
    Width = 109
    Height = 200
    Hint = 'Move the selected Favourite up'
    Caption = 'Move Up'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    OnClick = BtnMoveUpClick
  end
  object BtnMoveDown: TButton
    Left = 901
    Top = 234
    Width = 109
    Height = 200
    Hint = 'Move the selected Favourite down'
    Caption = 'Move Down'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
    OnClick = BtnMoveDownClick
  end
  object BtnDel: TButton
    Left = 903
    Top = 457
    Width = 107
    Height = 200
    Caption = '&Delete Fav'
    TabOrder = 3
    OnClick = BtnDelClick
  end
  object BtnOK: TButton
    Left = 807
    Top = 689
    Width = 98
    Height = 33
    Caption = '&OK'
    Default = True
    ModalResult = 1
    TabOrder = 4
  end
  object BtnCancel: TButton
    Left = 912
    Top = 689
    Width = 98
    Height = 33
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 5
  end
end
