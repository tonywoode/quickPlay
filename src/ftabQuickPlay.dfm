object TabQuickplay: TTabQuickplay
  Left = 0
  Top = 0
  Caption = 'TabQuickplay'
  ClientHeight = 514
  ClientWidth = 319
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object ImgQP: TImage
    Left = 0
    Top = 0
    Width = 319
    Height = 392
    Align = alClient
    AutoSize = True
    Center = True
    Proportional = True
  end
  object PanLinks: TPanel
    Left = 0
    Top = 392
    Width = 319
    Height = 122
    Align = alBottom
    BevelOuter = bvNone
    Color = clWhite
    TabOrder = 0
    DesignSize = (
      319
      122)
    object lblWelcome: TLabel
      Left = 8
      Top = 8
      Width = 180
      Height = 19
      Caption = 'Welcome to Quickplay'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object lblSetupMediaPaths: TLabel
      Left = 16
      Top = 48
      Width = 150
      Height = 13
      Cursor = crHandPoint
      Anchors = [akLeft, akTop, akBottom]
      Caption = 'Click here to setup media paths'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = lblSetupMediaPathsClick
    end
  end
end
