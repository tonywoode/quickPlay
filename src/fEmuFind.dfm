object EmuFinder: TEmuFinder
  Left = 279
  Top = 164
  BorderStyle = bsDialog
  Caption = 'Emu Finder'
  ClientHeight = 428
  ClientWidth = 345
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PCWizard: TPageControl
    Left = 0
    Top = 0
    Width = 345
    Height = 428
    ActivePage = TabResults
    Align = alClient
    Style = tsButtons
    TabOrder = 0
    ExplicitHeight = 432
    object TabIntroAndFolder: TTabSheet
      Caption = 'IntroAndFolder'
      ImageIndex = 2
      ExplicitHeight = 401
      object lblHeader: TLabel
        Left = 16
        Top = 0
        Width = 108
        Height = 23
        Caption = 'Emu Finder'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object TLabel
        Left = 16
        Top = 34
        Width = 305
        Height = 58
        Caption = 
          'Emu-Finder uses QuickPlays data-files to search your '#13#10'hard-driv' +
          'e for all compatible emulators. which means '#13#10'theres no need to ' +
          'add each emulator manually.'
      end
      object GrpDir: TGroupBox
        Left = 16
        Top = 96
        Width = 305
        Height = 241
        Caption = 'Directory Selection'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object RadSetDir: TRadioButton
          Left = 8
          Top = 40
          Width = 265
          Height = 17
          Caption = 'Scan Selected Directory'
          Checked = True
          TabOrder = 0
          TabStop = True
          OnClick = RadSetDirClick
        end
        object RadAllDrive: TRadioButton
          Left = 8
          Top = 112
          Width = 281
          Height = 17
          Caption = 'Scan Entire Drive (Can take a while)'
          TabOrder = 2
          OnClick = RadAllDriveClick
        end
        object DriveBox: TJvDriveCombo
          Left = 32
          Top = 144
          Width = 145
          Height = 22
          DriveTypes = [dtFixed, dtRemote, dtCDROM]
          Offset = 4
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ItemHeight = 16
          ParentFont = False
          TabOrder = 3
        end
        object TxtPath: TJvDirectoryEdit
          Left = 32
          Top = 64
          Width = 241
          Height = 24
          OnAfterDialog = TxtPathAfterDialog
          ClipboardCommands = []
          DialogKind = dkWin32
          DialogOptions = []
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
        end
      end
    end
    object TabDatAndGo: TTabSheet
      Caption = 'DatAndGo'
      ImageIndex = 3
      ExplicitHeight = 401
      object GrpStart: TGroupBox
        Left = 16
        Top = 255
        Width = 305
        Height = 111
        Caption = 'Start Scan'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        object TLabel
          Left = 48
          Top = 31
          Width = 203
          Height = 16
          Caption = 'Scanning may take 1-2 minutes'
        end
        object btnStart: TButton
          Left = 110
          Top = 62
          Width = 75
          Height = 25
          Caption = 'Begin'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = btnStartClick
        end
      end
      object GrpDats: TGroupBox
        Left = 16
        Top = 8
        Width = 305
        Height = 241
        Caption = 'Data File Selection'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object RadAllDats: TRadioButton
          Left = 8
          Top = 24
          Width = 225
          Height = 17
          Caption = 'Use All Dat Files'
          Checked = True
          TabOrder = 0
          TabStop = True
          OnClick = RadAllDatsClick
        end
        object RadSelDats: TRadioButton
          Left = 8
          Top = 48
          Width = 257
          Height = 17
          Caption = 'Selected Dat Files'
          TabOrder = 1
          OnClick = RadSelDatsClick
        end
        object VTdats: TVirtualStringTree
          Left = 24
          Top = 72
          Width = 265
          Height = 153
          CheckImageKind = ckDarkTick
          DefaultNodeHeight = 20
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Header.AutoSizeIndex = 0
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
              Width = 261
              WideText = 'FileName'
            end>
        end
      end
    end
    object TabResults: TTabSheet
      Caption = 'TabResults'
      ImageIndex = 4
      ExplicitHeight = 401
      object TLabel
        Left = 8
        Top = 2
        Width = 163
        Height = 16
        Caption = 'Results: Emulators Found'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblFound: TLabel
        Left = 194
        Top = 2
        Width = 9
        Height = 16
        Caption = '0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblRedAlert: TLabel
        Left = 8
        Top = 24
        Width = 256
        Height = 13
        Caption = '(Emulators in red are already in QuickPlays database)'
      end
      object RadOverwrite: TRadioButton
        Left = 204
        Top = 548
        Width = 325
        Height = 17
        Caption = 'Replace Emulator list with results'
        TabOrder = 4
      end
      object RadAppend: TRadioButton
        Left = 204
        Top = 527
        Width = 293
        Height = 17
        Caption = 'Add results to Emulators List'
        Checked = True
        TabOrder = 3
        TabStop = True
      end
      object BtnOK: TButton
        Left = 535
        Top = 532
        Width = 73
        Height = 25
        Caption = '&OK'
        Enabled = False
        TabOrder = 5
        OnClick = BtnOKClick
      end
      object BtnNoSave: TButton
        Left = 615
        Top = 532
        Width = 73
        Height = 25
        Caption = '&Cancel'
        ModalResult = 2
        TabOrder = 6
      end
      object VTEFind: TVirtualStringTree
        Left = 8
        Top = 48
        Width = 681
        Height = 473
        CheckImageKind = ckDarkTick
        DefaultNodeHeight = 20
        Header.AutoSizeIndex = 0
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
            Width = 277
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
        Left = 8
        Top = 532
        Width = 87
        Height = 25
        Caption = 'Select All'
        TabOrder = 1
        OnClick = BtnSelectallClick
      end
      object BtnUnselectAll: TButton
        Left = 112
        Top = 532
        Width = 83
        Height = 25
        Caption = 'UnSelect All'
        TabOrder = 2
        OnClick = BtnSelectallClick
      end
    end
  end
  object BtnCancel: TButton
    Left = 265
    Top = 400
    Width = 75
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object BtnNext: TButton
    Left = 184
    Top = 400
    Width = 75
    Height = 25
    Caption = 'Next'
    TabOrder = 2
    OnClick = BtnNextClick
  end
  object BtnPrevious: TButton
    Left = 104
    Top = 400
    Width = 75
    Height = 25
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
