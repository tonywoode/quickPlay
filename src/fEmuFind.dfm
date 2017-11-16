object EmuFinder: TEmuFinder
  Left = 279
  Top = 164
  AutoSize = True
  BorderStyle = bsDialog
  Caption = 'Emu Finder'
  ClientHeight = 771
  ClientWidth = 1018
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
    Width = 1018
    Height = 771
    ActivePage = TabIntroAndFolder
    Align = alClient
    Style = tsButtons
    TabOrder = 0
    OnChange = PCWizardChange
    object TabIntroAndFolder: TTabSheet
      Caption = 'IntroAndFolder'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ImageIndex = 2
      ParentFont = False
      object lblHeader: TLabel
        Left = 343
        Top = 0
        Width = 126
        Height = 27
        Caption = 'Emu Finder'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -22
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object TLabel
        Left = 29
        Top = 49
        Width = 624
        Height = 36
        Alignment = taCenter
        BiDiMode = bdLeftToRight
        Caption = 
          'Emu-Finder uses QuickPlay'#39's data-files to search your hard-drive' +
          ' for all compatible '#13#10' emulators. which means theres no need to ' +
          'add each emulator manually.'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentBiDiMode = False
        ParentFont = False
      end
      object lblEmuFind2: TLabel
        Left = 27
        Top = 113
        Width = 884
        Height = 54
        Alignment = taCenter
        BiDiMode = bdLeftToRight
        Caption = 
          'One way to use the EFinder is, if you have a single location for' +
          ' all of your emulators, you can choose to '#39'add all'#39' each time, o' +
          'verrwriting/refreshing your old emulators list. Another way is t' +
          'o add newly-found Emulators to your Emulators list and manage th' +
          'em in QuickPlay'#39's Emulators menu'
        ParentBiDiMode = False
        WordWrap = True
      end
      object LblEfind3: TLabel
        Left = 29
        Top = 179
        Width = 878
        Height = 36
        Alignment = taCenter
        BiDiMode = bdLeftToRight
        Caption = 
          'QuickPlay will automatically setup 2 emulators for you: CMD and ' +
          'Start - this is so you can open Winows games and other folder ba' +
          'sed applications'
        ParentBiDiMode = False
        WordWrap = True
      end
      object GrpDir: TGroupBox
        Left = 115
        Top = 251
        Width = 766
        Height = 385
        Caption = 'Directory Selection'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -18
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object RadSetDir: TRadioButton
          Left = 43
          Top = 68
          Width = 346
          Height = 23
          Caption = 'Scan Selected Directory'
          Checked = True
          TabOrder = 0
          TabStop = True
          OnClick = RadSetDirClick
        end
        object RadAllDrive: TRadioButton
          Left = 43
          Top = 219
          Width = 368
          Height = 22
          Caption = 'Scan Entire Drive (Can take a while)'
          TabOrder = 2
          OnClick = RadAllDriveClick
        end
        object DriveBox: TJvDriveCombo
          Left = 51
          Top = 332
          Width = 654
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
          Left = 51
          Top = 156
          Width = 654
          Height = 30
          OnAfterDialog = TxtPathAfterDialog
          ClipboardCommands = []
          DialogKind = dkWin32
          DialogOptions = []
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -18
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
      object GrpStart: TGroupBox
        Left = 104
        Top = 501
        Width = 801
        Height = 146
        Caption = 'Start Scan'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -18
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        object TLabel
          Left = 264
          Top = 41
          Width = 285
          Height = 22
          Caption = 'Scanning may take 1-2 minutes'
        end
        object btnStart: TButton
          Left = 328
          Top = 80
          Width = 177
          Height = 43
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
        Left = 104
        Top = 19
        Width = 801
        Height = 454
        Caption = 'Data File Selection'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -18
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object RadAllDats: TRadioButton
          Left = 11
          Top = 31
          Width = 294
          Height = 24
          Caption = 'Use All Dat Files'
          Checked = True
          TabOrder = 0
          TabStop = True
          OnClick = RadAllDatsClick
        end
        object RadSelDats: TRadioButton
          Left = 11
          Top = 63
          Width = 336
          Height = 22
          Caption = 'Selected Dat Files'
          TabOrder = 1
          OnClick = RadSelDatsClick
        end
        object VTdats: TVirtualStringTree
          Left = 11
          Top = 91
          Width = 766
          Height = 342
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
              Width = 762
              WideText = 'FileName'
            end>
        end
      end
    end
    object TabResults: TTabSheet
      Caption = 'TabResults'
      ImageIndex = 4
      object TLabel
        Left = 11
        Top = 3
        Width = 230
        Height = 22
        Caption = 'Results: Emulators Found'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -18
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblFound: TLabel
        Left = 255
        Top = 3
        Width = 11
        Height = 22
        Caption = '0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -18
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblRedAlert: TLabel
        Left = 11
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
        Width = 384
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
        Left = 17
        Top = 53
        Width = 980
        Height = 630
        CheckImageKind = ckDarkTick
        DefaultNodeHeight = 20
        Header.AutoSizeIndex = 0
        Header.DefaultHeight = 17
        Header.Font.Charset = DEFAULT_CHARSET
        Header.Font.Color = clWindowText
        Header.Font.Height = -11
        Header.Font.Name = 'MS Sans Serif'
        Header.Font.Style = []
        Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
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
            Width = 468
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
            Width = 350
            WideText = 'System'
          end>
      end
      object BtnSelectall: TButton
        Left = 11
        Top = 696
        Width = 113
        Height = 32
        Caption = 'Select All'
        TabOrder = 1
        OnClick = BtnSelectallClick
      end
      object BtnUnselectAll: TButton
        Left = 147
        Top = 696
        Width = 108
        Height = 32
        Caption = 'UnSelect All'
        TabOrder = 2
        OnClick = BtnSelectallClick
      end
    end
  end
  object BtnCancel: TButton
    Left = 602
    Top = 699
    Width = 98
    Height = 33
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object BtnNext: TButton
    Left = 420
    Top = 699
    Width = 98
    Height = 33
    Caption = 'Next'
    TabOrder = 2
    OnClick = BtnNextClick
  end
  object BtnPrevious: TButton
    Left = 241
    Top = 699
    Width = 99
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
