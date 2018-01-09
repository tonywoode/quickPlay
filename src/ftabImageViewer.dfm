object tabImageViewer: TtabImageViewer
  Left = 0
  Top = 0
  Caption = 'tabImageViewer'
  ClientHeight = 646
  ClientWidth = 413
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 120
  TextHeight = 17
  object imgViewer: TImage
    Left = 0
    Top = 0
    Width = 413
    Height = 609
    Align = alClient
    AutoSize = True
    Center = True
    Proportional = True
    Stretch = True
  end
  object PanImgControls: TPanel
    Left = 0
    Top = 609
    Width = 413
    Height = 37
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object ImgBack: TImage
      Left = 0
      Top = 0
      Width = 18
      Height = 37
      Cursor = crHandPoint
      Align = alLeft
      AutoSize = True
      Center = True
      OnClick = ImgBackClick
    end
    object ImgNext: TImage
      Left = 395
      Top = 0
      Width = 18
      Height = 37
      Cursor = crHandPoint
      Align = alRight
      AutoSize = True
      Center = True
      OnClick = ImgNextClick
    end
    object lblImageCount: TLabel
      Left = 18
      Top = 0
      Width = 377
      Height = 37
      Align = alClient
      Alignment = taCenter
      Caption = 'X OF X'
      Layout = tlCenter
      ExplicitWidth = 41
      ExplicitHeight = 17
    end
  end
  object TimerImgs: TTimer
    Enabled = False
    OnTimer = TimerImgsTimer
    Left = 152
    Top = 288
  end
end
