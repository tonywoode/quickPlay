object AboutBox: TAboutBox
  Left = 200
  Top = 108
  BorderStyle = bsDialog
  Caption = 'About'
  ClientHeight = 213
  ClientWidth = 298
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = True
  Position = poScreenCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 281
    Height = 161
    BevelInner = bvRaised
    BevelOuter = bvLowered
    ParentColor = True
    TabOrder = 0
    object ProgramIcon: TImage
      Left = 8
      Top = 8
      Width = 32
      Height = 32
      AutoSize = True
      Center = True
      Picture.Data = {
        055449636F6E0000010001002020100000000000E80200001600000028000000
        2000000040000000010004000000000080020000000000000000000000000000
        0000000000000000000080000080000000808000800000008000800080800000
        80808000C0C0C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000
        FFFFFF0000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000000000000000000000000000000000000000EEEEEEEEEEEEEEEEEEEE
        EEEE00000000E6666666666666666666666E00000000E6666666666666BBBB66
        666E00000000E666666666BBBBCBBCBBBB6E00000000E666666666BBBBCBBCBB
        BB6E00000000E66666666666666BB666666E00000000E6666CCCCCCCCCCCCCC6
        666E00000000E666CCCCCCCCCCCCCCC6666E00000000E66CCC666666666BB666
        666E00000000E6CCC666666BBBBBBBBBB66E00000000E6CC6666666B888CC888
        B66E00000000E6CC66EEEEE68E8CE888666E00000000E6CC66E6666BBEBBEEEB
        B66E00000000E6CC666E66668E8CE8E8666E00000000E6CC6666E6668E8CEEE8
        666E00000000E6CC66666E6BBBBBBBBBB66E00000000E6CC666666E68E8CC888
        666E00000000E6CC66EEEEEB888CC888B66E00000000E6CCC666666BBBBBBBBB
        B66E00000000E66CCC66666666CCCC66666E00000000E666CCCCCCCCCCCCCC66
        666E00000000E6666CCCCCCCCCCCC666666E00000000E6666666666666666666
        666E00000000EEEEEEEEEEEEEEEEEEEEEEEE0000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FF000000F
        F000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000F
        F000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000F
        F000000FF000000FF000000FF000000FF000000FF000000FFFFFFFFFFFFFFFFF
        FFFFFFFF}
      Proportional = True
      Stretch = True
      IsControl = True
    end
    object ProductName: TLabel
      Left = 88
      Top = 16
      Width = 45
      Height = 13
      Caption = 'ZipConfig'
      IsControl = True
    end
    object Version: TLabel
      Left = 88
      Top = 40
      Width = 51
      Height = 13
      Caption = '1.79.00.20'
      IsControl = True
    end
    object Copyright: TLabel
      Left = 8
      Top = 80
      Width = 44
      Height = 13
      Caption = 'Copyright'
      IsControl = True
    end
    object Comments: TLabel
      Left = 8
      Top = 104
      Width = 49
      Height = 13
      Caption = 'Comments'
      WordWrap = True
      IsControl = True
    end
    object StaticText1: TStaticText
      Left = 72
      Top = 80
      Width = 114
      Height = 17
      Caption = '(C) 2007 Russell Peters'
      TabOrder = 0
    end
    object StaticText2: TStaticText
      Left = 72
      Top = 104
      Width = 167
      Height = 17
      Caption = 'ZipConfig editor for ZipMaster 1.79'
      TabOrder = 1
    end
  end
  object OKButton: TButton
    Left = 111
    Top = 180
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
end
