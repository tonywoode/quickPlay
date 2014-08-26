object MameHolding: TMameHolding
  Left = 0
  Top = 0
  Caption = 'Instructions for Mame Romdata'
  ClientHeight = 209
  ClientWidth = 543
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
    Left = 8
    Top = 8
    Width = 529
    Height = 193
    TabOrder = 1
    object Link2: TLabel
      Left = 28
      Top = 74
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
      OnClick = Link2Click
      OnMouseDown = Link2MouseDown
    end
    object Link1: TLabel
      Left = 116
      Top = 30
      Width = 315
      Height = 13
      Cursor = crHandPoint
      Hint = 'right-click to copy to clipboard'
      Align = alCustom
      Caption = 'http://quickplay.sourceforge.net/wiki/index.php/MAME'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      OnClick = Link1Click
      OnMouseDown = Link1MouseDown
    end
    object Instructions1: TLabel
      Left = 79
      Top = 11
      Width = 367
      Height = 13
      Caption = 
        'To make full Mame Romlists for QuickPlay, please follow the inst' +
        'ructions here'
    end
    object Instructions2: TLabel
      Left = 103
      Top = 49
      Width = 352
      Height = 13
      Caption = 
        'Also consider the instructions here - you may wish to exclude ma' +
        'ny roms:'
    end
    object Instructions3: TLabel
      Left = 63
      Top = 106
      Width = 404
      Height = 13
      Caption = 
        'You can find the  files you need in the Tools directory in the f' +
        'older MAME PERL script'
    end
    object Label1: TLabel
      Left = 103
      Top = 130
      Width = 343
      Height = 13
      Caption = 
        'This functionality will be availbale from this menu item in the ' +
        'near future'
    end
  end
  object OKButton: TButton
    Left = 243
    Top = 168
    Width = 75
    Height = 25
    Caption = '&OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
end
