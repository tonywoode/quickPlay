object FrmCompressPicker: TFrmCompressPicker
  Left = 459
  Top = 321
  BorderStyle = bsDialog
  Caption = 'Choose File'
  ClientHeight = 239
  ClientWidth = 575
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lblCaption: TLabel
    Left = 8
    Top = 8
    Width = 61
    Height = 13
    Caption = 'Choose a file'
  end
  object VTFiles: TVirtualStringTree
    Left = 4
    Top = 24
    Width = 565
    Height = 177
    DefaultNodeHeight = 34
    Header.AutoSizeIndex = 0
    Header.Font.Charset = DEFAULT_CHARSET
    Header.Font.Color = clWindowText
    Header.Font.Height = -11
    Header.Font.Name = 'MS Sans Serif'
    Header.Font.Style = []
    Header.MainColumn = -1
    Header.Options = [hoColumnResize, hoDrag]
    SelectionCurveRadius = 10
    TabOrder = 0
    TreeOptions.MiscOptions = [toFullRepaintOnResize, toInitOnSave, toToggleOnDblClick, toWheelPanning]
    TreeOptions.PaintOptions = [toThemeAware, toUseBlendedImages]
    TreeOptions.SelectionOptions = [toFullRowSelect]
    OnDblClick = VTFilesDblClick
    OnGetText = VTFilesGetText
    OnKeyDown = VTFilesKeyDown
    Columns = <>
  end
  object BtnOK: TButton
    Left = 410
    Top = 208
    Width = 75
    Height = 25
    Caption = '&OK'
    Default = True
    ModalResult = 1
    TabOrder = 1
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 490
    Top = 208
    Width = 75
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 2
  end
end
