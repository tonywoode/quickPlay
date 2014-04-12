object FrmToolCfg: TFrmToolCfg
  Left = 631
  Top = 285
  BorderStyle = bsDialog
  Caption = 'Tool Configuration'
  ClientHeight = 559
  ClientWidth = 473
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object lblFileName: TLabel
    Left = 8
    Top = 39
    Width = 41
    Height = 13
    Caption = 'File Path'
  end
  object lblName: TLabel
    Left = 24
    Top = 9
    Width = 27
    Height = 13
    Caption = 'Name'
  end
  object lblHomepage: TLabel
    Left = 8
    Top = 67
    Width = 51
    Height = 13
    Caption = 'Homepage'
  end
  object TxtFileName: TJvFilenameEdit
    Left = 72
    Top = 36
    Width = 393
    Height = 21
    ClipboardCommands = []
    AddQuotes = False
    Filter = 
      'Executable Files (*.exe,*.bat,*.com)|*.exe;*.bat;*.com|All Files' +
      '|*.*'#39
    DialogOptions = [ofHideReadOnly, ofFileMustExist]
    TabOrder = 1
  end
  object TxtName: TEdit
    Left = 72
    Top = 6
    Width = 393
    Height = 21
    TabOrder = 0
  end
  object BtnOK: TButton
    Left = 307
    Top = 528
    Width = 75
    Height = 25
    Caption = '&OK'
    ModalResult = 1
    TabOrder = 3
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 387
    Top = 528
    Width = 75
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 4
  end
  object TxtHomepage: TEdit
    Left = 72
    Top = 64
    Width = 393
    Height = 21
    TabOrder = 2
  end
  object pgToolOpt: TPageControl
    Left = 8
    Top = 96
    Width = 457
    Height = 426
    ActivePage = TabOptions
    TabOrder = 5
    object TabOptions: TTabSheet
      Caption = 'General Configuration'
      object lblParamVar: TLabel
        Left = 3
        Top = 97
        Width = 430
        Height = 213
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
        Left = 15
        Top = 335
        Width = 61
        Height = 26
        Caption = 'Compression'#13#10'Support'
      end
      object lblVarBlank: TLabel
        Left = 295
        Top = 36
        Width = 111
        Height = 13
        Caption = '(leave blank to disable)'
      end
      object lblVariable: TLabel
        Left = 8
        Top = 36
        Width = 68
        Height = 13
        Caption = 'Variable Name'
      end
      object lblParams: TLabel
        Left = 26
        Top = 65
        Width = 50
        Height = 26
        Caption = 'Parameter'#13#10'Format'
      end
      object ChkLstCompress: TCheckListBox
        Left = 101
        Top = 316
        Width = 119
        Height = 73
        ItemHeight = 13
        TabOrder = 0
      end
      object TxtVariable: TEdit
        Left = 101
        Top = 33
        Width = 185
        Height = 21
        TabOrder = 1
      end
      object TxtSpecialParam: TEdit
        Left = 101
        Top = 68
        Width = 344
        Height = 21
        TabOrder = 2
        Text = '%ROM%'
      end
      object ChkSupportsParam: TCheckBox
        Left = 8
        Top = 8
        Width = 289
        Height = 17
        Caption = 'Supports Parameters'
        TabOrder = 3
      end
    end
    object TabMedia: TTabSheet
      Caption = 'Media Options'
      ImageIndex = 1
      object lblSysImage: TLabel
        Left = 8
        Top = 56
        Width = 53
        Height = 13
        Caption = 'Tool Image'
      end
      object ChkAddToolTab: TCheckBox
        Left = 8
        Top = 16
        Width = 265
        Height = 17
        Caption = 'Add Tools Media Tab'
        TabOrder = 0
      end
      object TxtToolImage: TJvFilenameEdit
        Left = 88
        Top = 54
        Width = 305
        Height = 21
        AddQuotes = False
        DialogKind = dkOpenPicture
        DialogOptions = [ofHideReadOnly, ofPathMustExist, ofFileMustExist]
        TabOrder = 1
      end
      object ChkShowAddInfo: TCheckBox
        Left = 8
        Top = 96
        Width = 313
        Height = 17
        Caption = 'Show Additional Information'
        TabOrder = 2
      end
      object MemoToolInfo: TMemo
        Left = 40
        Top = 120
        Width = 369
        Height = 197
        ScrollBars = ssBoth
        TabOrder = 3
      end
    end
  end
end
