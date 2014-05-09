object MameHolding: TMameHolding
  Left = 0
  Top = 0
  Caption = 'MameHolding'
  ClientHeight = 312
  ClientWidth = 553
  Color = clBtnFace
  UseDockManager = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 24
    Top = 16
    Width = 505
    Height = 273
    TabOrder = 1
    object Link2: TLabel
      Left = 12
      Top = 123
      Width = 478
      Height = 13
      Cursor = crHandPoint
      Hint = 'right-click to copy to clipboard'
      Caption = 
        'http://www.quickplayfrontend.com/index.php?showtopic=474&view=fi' +
        'ndpost&p=1954'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
    end
    object Link1: TLabel
      Left = 28
      Top = 51
      Width = 464
      Height = 13
      Cursor = crHandPoint
      Hint = 'right-click to copy to clipboard'
      Align = alCustom
      Caption = 
        'http://www.quickplayfrontend.com/index.php?showtopic=48&view=fin' +
        'dpost&p=739'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      OnClick = Link1Click
    end
    object Instructions1: TLabel
      Left = 79
      Top = 19
      Width = 370
      Height = 13
      Caption = 
        'To make full Mame Romlists for QuickPlay , please follow the ins' +
        'tructions here'
    end
    object Instructions2: TLabel
      Left = 122
      Top = 88
      Width = 279
      Height = 13
      Caption = 'And you might want to consider  the instructions here also'
    end
    object Instructions3: TLabel
      Left = 63
      Top = 156
      Width = 404
      Height = 13
      Caption = 
        'You can find the  files you need in the Tools directory in the f' +
        'older MAME PERL script'
    end
    object Label1: TLabel
      Left = 106
      Top = 188
      Width = 343
      Height = 13
      Caption = 
        'This functionality will be availbale from this menu item in the ' +
        'near future'
    end
  end
  object OKButton: TButton
    Left = 243
    Top = 239
    Width = 75
    Height = 25
    Caption = '&OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
end
