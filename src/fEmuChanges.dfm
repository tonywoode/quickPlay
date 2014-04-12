object EmuChangeFrm: TEmuChangeFrm
  Left = 192
  Top = 114
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'Suggested Data Changes'
  ClientHeight = 300
  ClientWidth = 618
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lblDescription: TLabel
    Left = 8
    Top = 8
    Width = 335
    Height = 13
    Caption = 
      'The following changes are recommended to keep your data up to da' +
      'te.'
  end
  object VTChanges: TVirtualStringTree
    Left = 5
    Top = 26
    Width = 609
    Height = 243
    CheckImageKind = ckDarkTick
    DefaultNodeHeight = 20
    DragType = dtVCL
    Header.AutoSizeIndex = 0
    Header.Font.Charset = DEFAULT_CHARSET
    Header.Font.Color = clWindowText
    Header.Font.Height = -11
    Header.Font.Name = 'MS Sans Serif'
    Header.Font.Style = []
    Header.MainColumn = -1
    Header.Options = [hoColumnResize, hoDrag]
    TabOrder = 0
    TreeOptions.AutoOptions = []
    TreeOptions.MiscOptions = [toCheckSupport, toFullRepaintOnResize, toWheelPanning]
    TreeOptions.PaintOptions = [toHideFocusRect, toHideSelection, toThemeAware, toUseBlendedImages]
    TreeOptions.SelectionOptions = [toDisableDrawSelection]
    TreeOptions.StringOptions = []
    OnFreeNode = VTChangesFreeNode
    OnGetText = VTChangesGetText
    OnPaintText = VTChangesPaintText
    Columns = <>
  end
  object BtnOK: TButton
    Left = 539
    Top = 272
    Width = 75
    Height = 25
    Caption = '&OK'
    Default = True
    ModalResult = 1
    TabOrder = 1
    OnClick = BtnOKClick
  end
end
