object EmuFinder: TEmuFinder
  Left = 279
  Top = 164
  AutoSize = True
  BorderStyle = bsDialog
  Caption = 'Emu Finder'
  ClientHeight = 560
  ClientWidth = 451
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object PCWizard: TPageControl
    Left = 0
    Top = 0
    Width = 451
    Height = 560
    ActivePage = TabIntroAndFolder
    Align = alClient
    Style = tsButtons
    TabOrder = 0
    object TabIntroAndFolder: TTabSheet
      Caption = 'IntroAndFolder'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ImageIndex = 2
      ParentFont = False
      ExplicitLeft = 2
      object lblHeader: TLabel
        Left = 21
        Top = 0
        Width = 131
        Height = 28
        Caption = 'Emu Finder'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -23
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object TLabel
        Left = 21
        Top = 44
        Width = 310
        Height = 48
        Caption = 
          'Emu-Finder uses QuickPlays data-files to search your '#13#10'hard-driv' +
          'e for all compatible emulators. which means '#13#10'theres no need to ' +
          'add each emulator manually.'
      end
      object GrpDir: TGroupBox
        Left = 21
        Top = 126
        Width = 399
        Height = 315
        Caption = 'Directory Selection'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -17
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object RadSetDir: TRadioButton
          Left = 10
          Top = 52
          Width = 347
          Height = 23
          Caption = 'Scan Selected Directory'
          Checked = True
          TabOrder = 0
          TabStop = True
          OnClick = RadSetDirClick
        end
        object RadAllDrive: TRadioButton
          Left = 10
          Top = 146
          Width = 368
          Height = 23
          Caption = 'Scan Entire Drive (Can take a while)'
          TabOrder = 2
          OnClick = RadAllDriveClick
        end
        object DriveBox: TJvDriveCombo
          Left = 42
          Top = 188
          Width = 189
          Height = 24
          DriveTypes = [dtFixed, dtRemote, dtCDROM]
          Offset = 4
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = []
          ItemHeight = 18
          ParentFont = False
          TabOrder = 3
        end
        object TxtPath: TJvDirectoryEdit
          Left = 42
          Top = 84
          Width = 315
          Height = 29
          OnAfterDialog = TxtPathAfterDialog
          ClipboardCommands = []
          DialogKind = dkWin32
          DialogOptions = []
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -17
          Font.Name = 'Tahoma'
          Font.Style = []
          ButtonWidth = 27
          ParentFont = False
          TabOrder = 1
        end
      end
    end
    object TabDatAndGo: TTabSheet
      Caption = 'DatAndGo'
      ImageIndex = 3
      ExplicitTop = 31
      ExplicitHeight = 525
      object GrpStart: TGroupBox
        Left = 21
        Top = 333
        Width = 399
        Height = 146
        Caption = 'Start Scan'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -17
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        object TLabel
          Left = 63
          Top = 41
          Width = 270
          Height = 21
          Caption = 'Scanning may take 1-2 minutes'
        end
        object btnStart: TButton
          Left = 144
          Top = 81
          Width = 98
          Height = 33
          Caption = 'Begin'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = btnStartClick
        end
      end
      object GrpDats: TGroupBox
        Left = 21
        Top = 10
        Width = 399
        Height = 316
        Caption = 'Data File Selection'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -17
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object RadAllDats: TRadioButton
          Left = 10
          Top = 31
          Width = 295
          Height = 23
          Caption = 'Use All Dat Files'
          Checked = True
          TabOrder = 0
          TabStop = True
          OnClick = RadAllDatsClick
        end
        object RadSelDats: TRadioButton
          Left = 10
          Top = 63
          Width = 337
          Height = 22
          Caption = 'Selected Dat Files'
          TabOrder = 1
          OnClick = RadSelDatsClick
        end
        object VTdats: TVirtualStringTree
          Left = 31
          Top = 94
          Width = 347
          Height = 200
          CheckImageKind = ckDarkTick
          DefaultNodeHeight = 20
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = []
          Header.AutoSizeIndex = 0
          Header.DefaultHeight = 17
          Header.Font.Charset = DEFAULT_CHARSET
          Header.Font.Color = clWindowText
          Header.Font.Height = -11
          Header.Font.Name = 'MS Sans Serif'
          Header.Font.Style = []
          Header.Options = [hoAutoResize, hoColumnResize, hoDrag]
          NodeDataSize = 0
          ParentFont = False
          TabOrder = 2
          TreeOptions.MiscOptions = [toCheckSupport, toFullRepaintOnResize, toInitOnSave, toToggleOnDblClick, toWheelPanning]
          TreeOptions.PaintOptions = [toShowHorzGridLines, toThemeAware, toUseBlendedImages]
          TreeOptions.SelectionOptions = [toFullRowSelect]
          OnGetText = VTdatsGetText
          OnInitNode = VTdatsInitNode
          Columns = <
            item
              Position = 0
              Width = 343
              WideText = 'FileName'
            end>
        end
      end
    end
    object TabResults: TTabSheet
      Caption = 'TabResults'
      ImageIndex = 4
      ExplicitTop = 31
      ExplicitHeight = 525
      object TLabel
        Left = 10
        Top = 3
        Width = 219
        Height = 21
        Caption = 'Results: Emulators Found'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -17
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblFound: TLabel
        Left = 254
        Top = 3
        Width = 11
        Height = 21
        Caption = '0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -17
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblRedAlert: TLabel
        Left = 10
        Top = 31
        Width = 307
        Height = 16
        Caption = '(Emulators in red are already in QuickPlays database)'
      end
      object RadOverwrite: TRadioButton
        Left = 267
        Top = 717
        Width = 425
        Height = 22
        Caption = 'Replace Emulator list with results'
        TabOrder = 4
      end
      object RadAppend: TRadioButton
        Left = 267
        Top = 689
        Width = 383
        Height = 22
        Caption = 'Add results to Emulators List'
        Checked = True
        TabOrder = 3
        TabStop = True
      end
      object BtnOK: TButton
        Left = 700
        Top = 696
        Width = 95
        Height = 32
        Caption = '&OK'
        Enabled = False
        TabOrder = 5
        OnClick = BtnOKClick
      end
      object BtnNoSave: TButton
        Left = 804
        Top = 696
        Width = 96
        Height = 32
        Caption = '&Cancel'
        ModalResult = 2
        TabOrder = 6
      end
      object VTEFind: TVirtualStringTree
        Left = 10
        Top = 63
        Width = 891
        Height = 618
        CheckImageKind = ckDarkTick
        DefaultNodeHeight = 20
        Header.AutoSizeIndex = 0
        Header.DefaultHeight = 17
        Header.Font.Charset = DEFAULT_CHARSET
        Header.Font.Color = clWindowText
        Header.Font.Height = -11
        Header.Font.Name = 'MS Sans Serif'
        Header.Font.Style = []
        Header.Options = [hoAutoResize, hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
        Header.SortColumn = 0
        TabOrder = 0
        TreeOptions.AutoOptions = [toAutoDropExpand, toAutoScrollOnExpand, toAutoSort, toAutoTristateTracking, toAutoDeleteMovedNodes]
        TreeOptions.MiscOptions = [toCheckSupport, toEditable, toFullRepaintOnResize, toGridExtensions, toInitOnSave, toToggleOnDblClick, toWheelPanning]
        TreeOptions.PaintOptions = [toShowHorzGridLines, toThemeAware, toUseBlendedImages]
        TreeOptions.SelectionOptions = [toFullRowSelect]
        OnCompareNodes = VTEFindCompareNodes
        OnEditing = VTEFindEditing
        OnExit = VTEFindExit
        OnFreeNode = VTEFindFreeNode
        OnGetText = VTEFindGetText
        OnPaintText = VTEFindPaintText
        OnHeaderClick = VTEFindHeaderClick
        OnNewText = VTEFindNewText
        Columns = <
          item
            Options = [coAllowClick, coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible]
            Position = 0
            Width = 487
            WideText = 'Name'
          end
          item
            Options = [coAllowClick, coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible]
            Position = 1
            Width = 300
            WideText = 'Path'
          end
          item
            Options = [coAllowClick, coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible]
            Position = 2
            Width = 100
            WideText = 'System'
          end>
      end
      object BtnSelectall: TButton
        Left = 10
        Top = 696
        Width = 114
        Height = 32
        Caption = 'Select All'
        TabOrder = 1
        OnClick = BtnSelectallClick
      end
      object BtnUnselectAll: TButton
        Left = 146
        Top = 696
        Width = 109
        Height = 32
        Caption = 'UnSelect All'
        TabOrder = 2
        OnClick = BtnSelectallClick
      end
    end
  end
  object BtnCancel: TButton
    Left = 347
    Top = 523
    Width = 98
    Height = 33
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object BtnNext: TButton
    Left = 241
    Top = 523
    Width = 98
    Height = 33
    Caption = 'Next'
    TabOrder = 2
    OnClick = BtnNextClick
  end
  object BtnPrevious: TButton
    Left = 136
    Top = 523
    Width = 98
    Height = 33
    Caption = 'Previous'
    Enabled = False
    TabOrder = 1
    OnClick = BtnPreviousClick
  end
  object FindEmu: ThhFindFile
    Filter = '*.exe'
    Recurse = True
    Left = 608
    Top = 56
  end
  object jvBrowse: TJvBrowseForFolderDialog
    Position = fpFormCenter
    RootDirectory = fdDesktop
    StatusText = 'Choose Directory to search for Emulators'
    Left = 608
    Top = 104
  end
end
