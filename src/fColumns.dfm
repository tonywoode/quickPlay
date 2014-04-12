object FrmColumn: TFrmColumn
  Left = 446
  Top = 170
  BorderStyle = bsDialog
  Caption = 'Columns'
  ClientHeight = 252
  ClientWidth = 161
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object BtnOK: TButton
    Left = 2
    Top = 225
    Width = 75
    Height = 25
    Caption = '&OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 82
    Top = 225
    Width = 75
    Height = 25
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object VTCol: TVirtualStringTree
    Left = 0
    Top = 0
    Width = 161
    Height = 193
    Align = alTop
    CheckImageKind = ckDarkCheck
    DefaultNodeHeight = 16
    Header.AutoSizeIndex = 0
    Header.Font.Charset = DEFAULT_CHARSET
    Header.Font.Color = clWindowText
    Header.Font.Height = -11
    Header.Font.Name = 'MS Sans Serif'
    Header.Font.Style = []
    Header.MainColumn = -1
    Header.Options = [hoColumnResize, hoDrag]
    Margin = 0
    NodeDataSize = 0
    TabOrder = 2
    TreeOptions.AutoOptions = []
    TreeOptions.MiscOptions = [toCheckSupport, toWheelPanning]
    TreeOptions.PaintOptions = [toHideFocusRect, toHideSelection, toShowButtons, toThemeAware, toUseBlendedImages]
    TreeOptions.SelectionOptions = [toDisableDrawSelection]
    TreeOptions.StringOptions = []
    OnGetText = VTColGetText
    OnInitNode = VTColInitNode
    Columns = <>
  end
  object BtnReset: TButton
    Left = 2
    Top = 197
    Width = 155
    Height = 25
    Caption = '&Reset To Default'
    TabOrder = 3
    OnClick = BtnResetClick
  end
end
