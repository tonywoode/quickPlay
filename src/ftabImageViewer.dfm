object tabImageViewer: TtabImageViewer
  Left = 0
  Top = 0
  Caption = 'tabImageViewer'
  ClientHeight = 494
  ClientWidth = 316
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object imgViewer: TImage
    Left = 0
    Top = 0
    Width = 316
    Height = 466
    Align = alClient
    AutoSize = True
    Center = True
    Proportional = True
    ExplicitHeight = 464
  end
  object PanImgControls: TPanel
    Left = 0
    Top = 466
    Width = 316
    Height = 28
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object ImgBack: TImage
      Left = 0
      Top = 0
      Width = 14
      Height = 28
      Cursor = crHandPoint
      Align = alLeft
      AutoSize = True
      Center = True
      OnClick = ImgBackClick
    end
    object ImgNext: TImage
      Left = 302
      Top = 0
      Width = 14
      Height = 28
      Cursor = crHandPoint
      Align = alRight
      AutoSize = True
      Center = True
      OnClick = ImgNextClick
    end
    object lblImageCount: TLabel
      Left = 14
      Top = 0
      Width = 32
      Height = 13
      Align = alClient
      Alignment = taCenter
      Caption = 'X OF X'
      Layout = tlCenter
    end
  end
  object TimerImgs: TTimer
    Enabled = False
    OnTimer = TimerImgsTimer
    Left = 152
    Top = 288
  end
end
