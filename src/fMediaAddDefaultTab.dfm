object FrmAddDefaultTab: TFrmAddDefaultTab
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'New Default Tab'
  ClientHeight = 111
  ClientWidth = 253
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object lblCaption: TLabel
    Left = 33
    Top = 11
    Width = 37
    Height = 13
    Caption = 'Caption'
  end
  object lblDefaultType: TLabel
    Left = 8
    Top = 44
    Width = 62
    Height = 13
    Caption = 'Default Type'
  end
  object TxtCaption: TEdit
    Left = 104
    Top = 8
    Width = 142
    Height = 21
    TabOrder = 0
  end
  object CmbType: TComboBox
    Left = 104
    Top = 40
    Width = 145
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 1
    Text = 'Images/Slideshow'
    Items.Strings = (
      'Images/Slideshow'
      'Game info dat file'
      'Game history dat filey'
      'Thumbnails')
  end
  object BtnOK: TButton
    Left = 88
    Top = 82
    Width = 75
    Height = 25
    Caption = '&OK'
    ModalResult = 1
    TabOrder = 2
  end
  object BtnCancel: TButton
    Left = 168
    Top = 82
    Width = 75
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 3
  end
end
