object FrmMameOptions: TFrmMameOptions
  Left = 269
  Top = 223
  BorderStyle = bsDialog
  Caption = 'MAME Options'
  ClientHeight = 240
  ClientWidth = 454
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object MameExtrasLabel: TLabel
    Left = 34
    Top = 28
    Width = 174
    Height = 20
    Caption = 'Set Mame Extras Dir'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    WordWrap = True
    OnClick = MameExtrasLabelClick
  end
  object MameExtrasDescLabel: TLabel
    Left = 34
    Top = 68
    Width = 311
    Height = 64
    Caption = 
      'Setting the location of the MAME extras directory will allow you' +
      ' to use MAME dats and icons in QuickPlay, and is used by the MAM' +
      'E Printing menu items to link assets to roms'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 14
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    WordWrap = True
  end
  object BtnOK: TButton
    Left = 234
    Top = 189
    Width = 92
    Height = 31
    Caption = '&Set'
    TabOrder = 0
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 339
    Top = 189
    Width = 92
    Height = 31
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object TxtMameExtrasDirPath: TEdit
    Left = 34
    Top = 147
    Width = 351
    Height = 24
    TabOrder = 2
  end
  object BtnMameExtrasDirFind: TButton
    Left = 399
    Top = 146
    Width = 32
    Height = 27
    Caption = '...'
    TabOrder = 3
    OnClick = BtnMameExtrasDirFindClick
  end
end
