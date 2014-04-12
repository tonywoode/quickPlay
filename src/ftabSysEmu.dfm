object TabSysEmu: TTabSysEmu
  Left = 0
  Top = 0
  Caption = 'Sys/Emu Info'
  ClientHeight = 531
  ClientWidth = 309
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ImgQP: TImage
    Left = 0
    Top = 0
    Width = 309
    Height = 317
    Align = alClient
    AutoSize = True
    Center = True
    Proportional = True
    ExplicitHeight = 315
  end
  object Splitter1: TSplitter
    Left = 0
    Top = 317
    Width = 309
    Height = 3
    Cursor = crVSplit
    Align = alBottom
    ExplicitTop = 315
  end
  object lblHomePage: TLabel
    Left = 0
    Top = 518
    Width = 309
    Height = 13
    Cursor = crHandPoint
    Align = alBottom
    Alignment = taCenter
    Caption = 'HOMEPAGE'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
    OnClick = lblHomePageClick
    ExplicitTop = 524
  end
  object memoInfo: TMemo
    Left = 0
    Top = 320
    Width = 309
    Height = 198
    Align = alBottom
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 0
  end
end
