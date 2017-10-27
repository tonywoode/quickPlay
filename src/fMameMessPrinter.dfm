object FrmMameMessPrinter: TFrmMameMessPrinter
  Left = 0
  Top = 0
  Caption = 'Mame Mess Softlist Romdata Printer'
  ClientHeight = 357
  ClientWidth = 557
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
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
  object MameMessPrinterDescLabel2: TLabel
    Left = 24
    Top = 186
    Width = 379
    Height = 32
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
  object lblMAME: TLabel
    Left = 24
    Top = 254
    Width = 128
    Height = 16
    Caption = 'Mame Emulator to call'
  end
  object MameMessPrinterDescLabel3: TLabel
    Left = 24
    Top = 79
    Width = 443
    Height = 32
    Caption = 
      'it'#39's non destructive to run this in a folder that already has ro' +
      'mdata and folders (e.g.: your existing MAME folder)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    WordWrap = True
  end
  object XMLTxtLbl: TLabel
    Left = 24
    Top = 134
    Width = 101
    Height = 16
    Caption = 'Mame XML status'
  end
  object BtnOK: TButton
    Left = 329
    Top = 305
    Width = 92
    Height = 31
    Caption = '&Go'
    TabOrder = 0
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 438
    Top = 305
    Width = 92
    Height = 31
    Cancel = True
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object CmbMame: TComboBox
    Left = 185
    Top = 251
    Width = 345
    Height = 24
    Style = csDropDownList
    Color = clMenu
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 16
    ParentFont = False
    TabOrder = 2
  end
  object XMLEdit: TEdit
    Left = 165
    Top = 131
    Width = 354
    Height = 27
    AutoSelect = False
    BevelInner = bvNone
    BorderStyle = bsNone
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = 25
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentColor = True
    ParentFont = False
    ReadOnly = True
    TabOrder = 3
    Text = 'not loaded'
  end
end
