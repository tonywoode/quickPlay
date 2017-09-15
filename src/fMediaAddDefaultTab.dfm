object FrmAddDefaultTab: TFrmAddDefaultTab
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'New Default Tab'
  ClientHeight = 145
  ClientWidth = 331
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 120
  TextHeight = 17
  object lblCaption: TLabel
    Left = 43
    Top = 14
    Width = 47
    Height = 17
    Caption = 'Caption'
  end
  object lblDefaultType: TLabel
    Left = 10
    Top = 58
    Width = 78
    Height = 17
    Caption = 'Default Type'
  end
  object TxtCaption: TEdit
    Left = 136
    Top = 10
    Width = 186
    Height = 25
    TabOrder = 0
  end
  object CmbType: TComboBox
    Left = 136
    Top = 52
    Width = 190
    Height = 25
    Style = csDropDownList
    ItemHeight = 17
    ItemIndex = 0
    TabOrder = 1
    Text = 'Images/Slideshow'
    Items.Strings = (
      'Images/Slideshow'
      'Game info dat file'
      'Game history dat file'
      'Thumbnails'
      'System'
      'Rom Info'
      'Mame Command dat file')
  end
  object BtnOK: TButton
    Left = 115
    Top = 107
    Width = 98
    Height = 33
    Caption = '&OK'
    ModalResult = 1
    TabOrder = 2
  end
  object BtnCancel: TButton
    Left = 220
    Top = 107
    Width = 98
    Height = 33
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 3
  end
end
