object FrmMigrate: TFrmMigrate
  Left = 187
  Top = 157
  BorderStyle = bsDialog
  Caption = 'Drive/Folder Migration Wizard'
  ClientHeight = 370
  ClientWidth = 708
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PCMigrate: TPageControl
    Left = 0
    Top = 0
    Width = 708
    Height = 370
    ActivePage = TabWelcome
    Align = alClient
    TabOrder = 0
    object TabWelcome: TTabSheet
      Caption = 'TabWelcome'
      object lblWelcome: TLabel
        Left = 56
        Top = 32
        Width = 248
        Height = 19
        Caption = 'Drive/Folder Migration Wizard'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblDescription: TLabel
        Left = 56
        Top = 80
        Width = 585
        Height = 170
        AutoSize = False
        Caption = 
          'The folder migration wizard allows you to change the paths of al' +
          'l your ROMs, Emulators and Favourites in one go.  Why would you ' +
          'want to do this?  Well a good example would be if you got a new ' +
          'Hard Drive and wanted to copy all your emulation files onto this' +
          ' drive.  Normally you would need to rescan all your Data back in' +
          'to QuickPlay - this wizard should eliminate that need!'#13#10#13#10'Simply' +
          ' move all your files to their new location, start Quickplay and ' +
          'run this wizard, then click the '#39'Scan'#39' button and Quickplay will' +
          ' check its data files for problems and allow you to fix these pr' +
          'oblems.'
        WordWrap = True
      end
      object BtnScan: TButton
        Left = 288
        Top = 256
        Width = 105
        Height = 25
        Caption = 'Scan QP Data'
        TabOrder = 0
        OnClick = BtnScanClick
      end
    end
    object TabResults: TTabSheet
      Caption = 'TabResults'
      ImageIndex = 1
      object VTMigrate: TVirtualStringTree
        Left = 8
        Top = 3
        Width = 680
        Height = 311
        DefaultNodeHeight = 20
        Header.AutoSizeIndex = 0
        Header.Font.Charset = DEFAULT_CHARSET
        Header.Font.Color = clWindowText
        Header.Font.Height = -11
        Header.Font.Name = 'MS Sans Serif'
        Header.Font.Style = []
        Header.Options = [hoColumnResize, hoDrag, hoVisible]
        Images = MainFrm.ImageList1
        TabOrder = 0
        TreeOptions.AutoOptions = [toAutoDropExpand, toAutoTristateTracking, toAutoDeleteMovedNodes]
        TreeOptions.MiscOptions = [toEditable, toGridExtensions, toInitOnSave, toToggleOnDblClick, toWheelPanning]
        TreeOptions.PaintOptions = [toHideFocusRect, toHideSelection, toShowHorzGridLines, toThemeAware, toUseBlendedImages, toAlwaysHideSelection]
        TreeOptions.SelectionOptions = [toDisableDrawSelection, toExtendedFocus, toFullRowSelect]
        OnChange = VTMigrateChange
        OnEditing = VTMigrateEditing
        OnExit = VTMigrateExit
        OnFreeNode = VTMigrateFreeNode
        OnGetText = VTMigrateGetText
        OnPaintText = VTMigratePaintText
        OnGetImageIndex = VTMigrateGetImageIndex
        OnInitNode = VTMigrateInitNode
        OnNewText = VTMigrateNewText
        Columns = <
          item
            Options = [coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible]
            Position = 0
            Width = 338
            WideText = 'Original Path'
          end
          item
            Options = [coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coVisible]
            Position = 1
            Width = 338
            WideText = 'New Path'
          end>
      end
    end
  end
  object BtnCancel: TButton
    Left = 616
    Top = 341
    Width = 75
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object BtnOK: TButton
    Left = 536
    Top = 341
    Width = 75
    Height = 25
    Caption = '&OK'
    ModalResult = 1
    TabOrder = 2
    Visible = False
    OnClick = BtnOKClick
  end
end
