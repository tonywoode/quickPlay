object FrmMameMessPrinter: TFrmMameMessPrinter
  Left = 0
  Top = 0
  Caption = 'Mame Mess Softlist Romdata Printer'
  ClientHeight = 260
  ClientWidth = 468
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 120
  TextHeight = 16
  object MameMessPrinterDescLabel1: TLabel
    Left = 24
    Top = 24
    Width = 397
    Height = 32
    Caption = 
      'Print a set of MAME or Retroarch Softlist Romdata Folders in the' +
      ' current dir'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    WordWrap = True
  end
  object MameSoftlistChoiceLabel: TLabel
    Left = 160
    Top = 120
    Width = 140
    Height = 16
    Caption = 'Make a set of folders for'
  end
  object MameMessPrinterDescLabel2: TLabel
    Left = 24
    Top = 62
    Width = 397
    Height = 36
    Caption = 
      'Make sure you'#39've sucessfully done an efind scan first and have s' +
      'oftlist emualtors in your Emu list'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    WordWrap = True
  end
  object RadSoftlistMameChoice: TRadioButton
    Left = 88
    Top = 160
    Width = 65
    Height = 17
    Caption = 'MAME'
    Checked = True
    TabOrder = 0
    TabStop = True
  end
  object RadSoftlistRetroarchChoice: TRadioButton
    Left = 240
    Top = 160
    Width = 113
    Height = 17
    Caption = 'RetroArch MAME'
    TabOrder = 1
  end
  object BtnOK: TButton
    Left = 216
    Top = 200
    Width = 92
    Height = 31
    Caption = '&Go'
    TabOrder = 2
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 343
    Top = 200
    Width = 92
    Height = 31
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 3
  end
end
