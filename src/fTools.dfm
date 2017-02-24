object FrmToolCfg: TFrmToolCfg
  Left = 631
  Top = 285
  BorderStyle = bsDialog
  Caption = 'Tool Configuration'
  ClientHeight = 731
  ClientWidth = 619
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 120
  TextHeight = 17
  object lblFileName: TLabel
    Left = 10
    Top = 51
    Width = 50
    Height = 17
    Caption = 'File Path'
  end
  object lblName: TLabel
    Left = 31
    Top = 12
    Width = 35
    Height = 17
    Caption = 'Name'
  end
  object lblHomepage: TLabel
    Left = 10
    Top = 88
    Width = 66
    Height = 17
    Caption = 'Homepage'
  end
  object TxtFileName: TJvFilenameEdit
    Left = 94
    Top = 47
    Width = 514
    Height = 25
    ClipboardCommands = []
    AddQuotes = False
    Filter = 
      'Executable Files (*.exe,*.bat,*.com)|*.exe;*.bat;*.com|All Files' +
      '|*.*'#39
    DialogOptions = [ofHideReadOnly, ofFileMustExist]
    ButtonWidth = 27
    TabOrder = 1
  end
  object TxtName: TEdit
    Left = 94
    Top = 8
    Width = 514
    Height = 25
    TabOrder = 0
  end
  object BtnOK: TButton
    Left = 401
    Top = 690
    Width = 99
    Height = 33
    Caption = '&OK'
    ModalResult = 1
    TabOrder = 3
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 506
    Top = 690
    Width = 98
    Height = 33
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 4
  end
  object TxtHomepage: TEdit
    Left = 94
    Top = 84
    Width = 514
    Height = 25
    TabOrder = 2
  end
  object pgToolOpt: TPageControl
    Left = 10
    Top = 126
    Width = 598
    Height = 557
    ActivePage = TabOptions
    TabOrder = 5
    object TabOptions: TTabSheet
      Caption = 'General Configuration'
      object lblParamVar: TLabel
        Left = 4
        Top = 127
        Width = 562
        Height = 278
        AutoSize = False
        Caption = 
          'Available Variables'#13#10'------------------------------------'#13#10'%ROM%' +
          ' - The full path to the selected ROM.'#13#10'%ROMFILENAME% - The filen' +
          'ame of the ROM, includes file extension.'#13#10'%ROMFILENAMENOEXT% - T' +
          'he filename of the ROM, with NO file extension.'#13#10'%ROMDIR% - The ' +
          'directory of the ROM.'#13#10'%SHORTROM% - The full path to the selecte' +
          'd ROM in (8:3) format'#13#10'%ROMMAME% - The name (or MAME name) of th' +
          'e emulator'#13#10'%TOOL:toolvariable% - Launch tool specified by '#39'tool' +
          'variable'#39#13#10#13#10'%EXECFG% - Emulator/Tool configuration file.'#13#10'%EXEP' +
          'ATH% - Full path to associated emulator/Tool '#13#10'%EXEDIR% - The as' +
          'sociated emulators/Tool directory'
        WordWrap = True
      end
      object lblCompression: TLabel
        Left = 20
        Top = 438
        Width = 79
        Height = 34
        Caption = 'Compression'#13#10'Support'
      end
      object lblVarBlank: TLabel
        Left = 386
        Top = 47
        Width = 138
        Height = 17
        Caption = '(leave blank to disable)'
      end
      object lblVariable: TLabel
        Left = 10
        Top = 47
        Width = 85
        Height = 17
        Caption = 'Variable Name'
      end
      object lblParams: TLabel
        Left = 34
        Top = 85
        Width = 63
        Height = 34
        Caption = 'Parameter'#13#10'Format'
      end
      object ChkLstCompress: TCheckListBox
        Left = 132
        Top = 413
        Width = 156
        Height = 96
        ItemHeight = 17
        TabOrder = 0
      end
      object TxtVariable: TEdit
        Left = 132
        Top = 43
        Width = 242
        Height = 25
        TabOrder = 1
      end
      object TxtSpecialParam: TEdit
        Left = 132
        Top = 89
        Width = 450
        Height = 25
        TabOrder = 2
        Text = '%ROM%'
      end
      object ChkSupportsParam: TCheckBox
        Left = 10
        Top = 10
        Width = 378
        Height = 23
        Caption = 'Supports Parameters'
        TabOrder = 3
      end
    end
    object TabMedia: TTabSheet
      Caption = 'Media Options'
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object lblSysImage: TLabel
        Left = 10
        Top = 73
        Width = 68
        Height = 17
        Caption = 'Tool Image'
      end
      object ChkAddToolTab: TCheckBox
        Left = 10
        Top = 21
        Width = 347
        Height = 22
        Caption = 'Add Tools Media Tab'
        TabOrder = 0
      end
      object TxtToolImage: TJvFilenameEdit
        Left = 115
        Top = 71
        Width = 399
        Height = 21
        AddQuotes = False
        DialogKind = dkOpenPicture
        DialogOptions = [ofHideReadOnly, ofPathMustExist, ofFileMustExist]
        ButtonWidth = 27
        TabOrder = 1
      end
      object ChkShowAddInfo: TCheckBox
        Left = 10
        Top = 126
        Width = 410
        Height = 22
        Caption = 'Show Additional Information'
        TabOrder = 2
      end
      object MemoToolInfo: TMemo
        Left = 52
        Top = 157
        Width = 483
        Height = 258
        ScrollBars = ssBoth
        TabOrder = 3
      end
    end
  end
end
