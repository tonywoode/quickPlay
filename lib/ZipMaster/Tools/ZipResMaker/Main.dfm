object Form1: TForm1
  Left = 192
  Top = 107
  Caption = 'Delphi Zip Resource Maker'
  ClientHeight = 445
  ClientWidth = 369
  Color = clBtnFace
  Constraints.MinHeight = 375
  Constraints.MinWidth = 370
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 404
    Width = 369
    Height = 41
    Align = alBottom
    TabOrder = 0
    object btnBuildRes: TButton
      Left = 120
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Build &Res'
      TabOrder = 0
      OnClick = btnBuildResClick
    end
  end
  object Pages: TPageControl
    Left = 0
    Top = 0
    Width = 369
    Height = 404
    ActivePage = TabSheet5
    Align = alClient
    Constraints.MinHeight = 280
    Constraints.MinWidth = 345
    TabOrder = 1
    OnChange = PagesChange
    object TabSheet1: TTabSheet
      Caption = '&Paths'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      DesignSize = (
        361
        376)
      object Label1: TLabel
        Left = 169
        Top = 8
        Width = 23
        Height = 13
        Caption = 'Root'
      end
      object Label2: TLabel
        Left = 154
        Top = 56
        Width = 53
        Height = 13
        Caption = 'Destination'
      end
      object Label3: TLabel
        Left = 172
        Top = 104
        Width = 12
        Height = 13
        Caption = 'Dll'
      end
      object Label4: TLabel
        Left = 156
        Top = 152
        Width = 48
        Height = 13
        Caption = 'Language'
      end
      object Label6: TLabel
        Left = 162
        Top = 200
        Width = 34
        Height = 13
        Caption = 'Source'
      end
      object Label5: TLabel
        Left = 169
        Top = 248
        Width = 22
        Height = 13
        Caption = 'UPX'
      end
      object edRoot: TEdit
        Left = 8
        Top = 32
        Width = 309
        Height = 21
        Anchors = [akLeft, akTop, akRight]
        BevelInner = bvLowered
        BevelOuter = bvRaised
        TabOrder = 0
        Text = '..\..'
        OnChange = edRootChange
      end
      object edDest: TEdit
        Left = 8
        Top = 80
        Width = 309
        Height = 21
        Anchors = [akLeft, akTop, akRight]
        BevelInner = bvLowered
        BevelOuter = bvRaised
        TabOrder = 1
        Text = 'RES'
        OnChange = edDestChange
      end
      object edDll: TEdit
        Left = 8
        Top = 128
        Width = 309
        Height = 21
        Anchors = [akLeft, akTop, akRight]
        BevelInner = bvLowered
        BevelOuter = bvRaised
        TabOrder = 2
        Text = 'DLL'
        OnChange = edDllChange
      end
      object edLang: TEdit
        Left = 8
        Top = 176
        Width = 309
        Height = 21
        Anchors = [akLeft, akTop, akRight]
        BevelInner = bvLowered
        BevelOuter = bvRaised
        TabOrder = 3
        Text = 'Lang'
        OnChange = edLangChange
      end
      object edVCL: TEdit
        Left = 8
        Top = 224
        Width = 309
        Height = 21
        Anchors = [akLeft, akTop, akRight]
        BevelInner = bvLowered
        BevelOuter = bvRaised
        TabOrder = 4
        Text = 'VCL'
      end
      object btnBrowseRoot: TButton
        Left = 329
        Top = 34
        Width = 25
        Height = 19
        Anchors = [akTop, akRight]
        Caption = '...'
        TabOrder = 5
        OnClick = btnBrowseRootClick
      end
      object btnBrowsDest: TButton
        Left = 329
        Top = 82
        Width = 25
        Height = 19
        Anchors = [akTop, akRight]
        Caption = '...'
        TabOrder = 6
        OnClick = btnBrowsDestClick
      end
      object btnBrowseDll: TButton
        Left = 329
        Top = 130
        Width = 25
        Height = 19
        Anchors = [akTop, akRight]
        Caption = '...'
        TabOrder = 7
        OnClick = btnBrowseDllClick
      end
      object btnBrowseLang: TButton
        Left = 329
        Top = 178
        Width = 25
        Height = 19
        Anchors = [akTop, akRight]
        Caption = '...'
        TabOrder = 8
        OnClick = btnBrowseLangClick
      end
      object btnBrowseVCL: TButton
        Left = 329
        Top = 226
        Width = 25
        Height = 19
        Anchors = [akTop, akRight]
        Caption = '...'
        TabOrder = 9
        OnClick = btnBrowseVCLClick
      end
      object edUPX: TEdit
        Left = 8
        Top = 272
        Width = 309
        Height = 21
        Anchors = [akLeft, akTop, akRight]
        TabOrder = 10
        Text = 'UPX'
        OnChange = edUPXChange
      end
      object btnBrowseUPX: TButton
        Left = 328
        Top = 270
        Width = 25
        Height = 19
        Anchors = [akTop, akRight]
        Caption = '...'
        TabOrder = 11
        OnClick = btnBrowseUPXClick
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'DLL'
      ImageIndex = 4
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Label7: TLabel
        Left = 24
        Top = 64
        Width = 99
        Height = 13
        Caption = 'DelZipxxx..dll version'
      end
      object cbDlls: TCheckBox
        Left = 24
        Top = 16
        Width = 167
        Height = 17
        Caption = 'Compressed copy of dll'
        Checked = True
        State = cbChecked
        TabOrder = 0
      end
      object edDllVer: TEdit
        Left = 168
        Top = 56
        Width = 121
        Height = 21
        ReadOnly = True
        TabOrder = 1
      end
      object pnlDllUPX: TPanel
        Left = 16
        Top = 176
        Width = 329
        Height = 121
        TabOrder = 2
        Visible = False
        object cbUseUPX: TCheckBox
          Left = 8
          Top = 9
          Width = 209
          Height = 17
          Caption = 'Compress with UPX'
          TabOrder = 0
        end
        object StaticText9: TStaticText
          Left = 112
          Top = 32
          Width = 76
          Height = 20
          Caption = 'WARNING'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
        end
        object StaticText10: TStaticText
          Left = 24
          Top = 56
          Width = 278
          Height = 17
          Caption = 'Compressing the dll with UPX may cause loading problems'
          TabOrder = 2
        end
        object StaticText11: TStaticText
          Left = 32
          Top = 80
          Width = 267
          Height = 17
          Caption = ' in the debugger and some alerts from Security Software'
          TabOrder = 3
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Languages'
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object lbLangs: TCheckListBox
        Left = 0
        Top = 0
        Width = 361
        Height = 348
        Align = alClient
        AutoComplete = False
        Columns = 2
        ItemHeight = 13
        Sorted = True
        TabOrder = 0
      end
      object Panel2: TPanel
        Left = 0
        Top = 348
        Width = 361
        Height = 28
        Align = alBottom
        TabOrder = 1
        object btnAllLang: TButton
          Left = 37
          Top = 3
          Width = 75
          Height = 20
          Caption = 'All'
          TabOrder = 0
          OnClick = btnAllLangClick
        end
        object btnNoneLang: TButton
          Left = 129
          Top = 3
          Width = 75
          Height = 20
          Caption = 'None'
          TabOrder = 1
          OnClick = btnNoneLangClick
        end
        object btnRefreshLang: TButton
          Left = 221
          Top = 3
          Width = 75
          Height = 20
          Caption = 'Refresh'
          TabOrder = 2
          OnClick = btnRefreshLangClick
        end
      end
    end
    object TabSheet6: TTabSheet
      Caption = 'Default Strings'
      ImageIndex = 5
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object StaticText1: TStaticText
        Left = 0
        Top = 0
        Width = 90
        Height = 24
        Align = alTop
        Alignment = taCenter
        Caption = '  Warning  '
        Color = clHotLight
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clHighlightText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold, fsUnderline]
        ParentColor = False
        ParentFont = False
        ShowAccelChar = False
        TabOrder = 0
      end
      object StaticText2: TStaticText
        Left = 40
        Top = 56
        Width = 69
        Height = 17
        Caption = 'ZipMsg.pas'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
      end
      object StaticText3: TStaticText
        Left = 8
        Top = 32
        Width = 320
        Height = 20
        Caption = 'This will replace (overwrite) the following units'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object StaticText4: TStaticText
        Left = 40
        Top = 80
        Width = 95
        Height = 17
        Caption = 'ZMDefMsgs.pas'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
      end
      object StaticText5: TStaticText
        Left = 16
        Top = 120
        Width = 245
        Height = 17
        Caption = 'Only needs to be done if default language strings in'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
      end
      object StaticText6: TStaticText
        Left = 16
        Top = 136
        Width = 66
        Height = 17
        Caption = 'ZipMsgUS.rc'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 5
      end
      object StaticText7: TStaticText
        Left = 16
        Top = 152
        Width = 48
        Height = 17
        Caption = 'ZipMsg.h'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 6
      end
      object StaticText8: TStaticText
        Left = 16
        Top = 168
        Width = 64
        Height = 17
        Caption = 'are modified.'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 7
      end
      object btnMakeUnits: TButton
        Left = 136
        Top = 216
        Width = 75
        Height = 25
        Caption = 'Build Units'
        TabOrder = 8
        OnClick = btnMakeUnitsClick
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Information'
      ImageIndex = 3
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 361
        Height = 376
        Align = alClient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Courier New'
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 296
    Top = 336
    object File1: TMenuItem
      Caption = '&File'
      object Exit1: TMenuItem
        Caption = '&Exit'
      end
    end
    object Build1: TMenuItem
      Caption = '&Build'
      object Script1: TMenuItem
        Caption = '&Script'
        Hint = 'build resource script'
      end
      object Resources1: TMenuItem
        Caption = '&Resources'
        Hint = 'build and compile resources'
        OnClick = btnBuildResClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object DefTags: TMenuItem
        Caption = '&Default Strings'
        Hint = 'Build default strings'
        OnClick = DefTagsClick
      end
    end
    object Help1: TMenuItem
      Caption = '&Help'
      object A1: TMenuItem
        Caption = 'About'
        OnClick = A1Click
      end
    end
  end
end
