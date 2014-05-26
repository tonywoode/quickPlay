object FrmParamVars: TFrmParamVars
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = 'Parameter Variables'
  ClientHeight = 224
  ClientWidth = 437
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object VTVars: TVirtualStringTree
    Left = 0
    Top = 0
    Width = 437
    Height = 224
    Align = alClient
    DefaultNodeHeight = 20
    Header.AutoSizeIndex = 1
    Header.DefaultHeight = 17
    Header.Font.Charset = DEFAULT_CHARSET
    Header.Font.Color = clWindowText
    Header.Font.Height = -11
    Header.Font.Name = 'Tahoma'
    Header.Font.Style = []
    Header.Options = [hoAutoResize]
    TabOrder = 0
    TreeOptions.AutoOptions = [toDisableAutoscrollOnFocus]
    TreeOptions.MiscOptions = [toFullRepaintOnResize, toInitOnSave, toToggleOnDblClick, toWheelPanning]
    TreeOptions.PaintOptions = [toHideFocusRect, toHideSelection, toShowHorzGridLines, toShowVertGridLines, toThemeAware, toUseBlendedImages, toFullVertGridLines, toAlwaysHideSelection]
    TreeOptions.SelectionOptions = [toDisableDrawSelection]
    OnGetText = VTVarsGetText
    OnPaintText = VTVarsPaintText
    ExplicitHeight = 204
    Columns = <
      item
        Position = 0
        Width = 165
        WideText = 'Variable'
      end
      item
        Position = 1
        Width = 268
        WideText = 'Desc'
      end>
  end
end
