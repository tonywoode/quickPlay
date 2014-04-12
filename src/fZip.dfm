object FrmCompressionTools: TFrmCompressionTools
  Left = 115
  Top = 450
  BorderStyle = bsDialog
  Caption = 'Compression Utilities'
  ClientHeight = 516
  ClientWidth = 444
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object LblInput: TLabel
    Left = 8
    Top = 11
    Width = 77
    Height = 13
    Caption = 'Location of Files'
  end
  object lblAction: TLabel
    Left = 37
    Top = 59
    Width = 48
    Height = 13
    Caption = 'Operation'
  end
  object Label1: TLabel
    Left = 10
    Top = 371
    Width = 45
    Height = 13
    Caption = 'ERRORS'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object PgCompression: TPageControl
    Left = 8
    Top = 80
    Width = 425
    Height = 225
    ActivePage = TabCompress
    Style = tsButtons
    TabOrder = 0
    object TabUncompress: TTabSheet
      Caption = 'Mass File UnCompressor'
      object lblOutput: TLabel
        Left = 7
        Top = 4
        Width = 67
        Height = 13
        Caption = 'Output Folder'
      end
      object lblUncompressFormat: TLabel
        Left = 0
        Top = 96
        Width = 109
        Height = 13
        Caption = 'Uncompress File Types'
      end
      object ChkDiffDir: TCheckBox
        Left = 85
        Top = 28
        Width = 244
        Height = 17
        Caption = 'Directory for Each File'
        TabOrder = 0
      end
      object ChkExtPath: TCheckBox
        Left = 85
        Top = 48
        Width = 244
        Height = 17
        Caption = 'Extract with Path'
        Checked = True
        State = cbChecked
        TabOrder = 1
      end
      object ChkOver: TCheckBox
        Left = 85
        Top = 68
        Width = 256
        Height = 17
        Caption = 'Overwrite Existing Files'
        Checked = True
        State = cbChecked
        TabOrder = 2
      end
      object TxtUncompressOutput: TJvDirectoryEdit
        Left = 85
        Top = 0
        Width = 331
        Height = 21
        OnBeforeDialog = TxtUncompressOutputBeforeDialog
        ClipboardCommands = []
        DialogKind = dkWin32
        TabOrder = 3
      end
      object ChkLstUncompress: TCheckListBox
        Left = 84
        Top = 116
        Width = 133
        Height = 73
        ItemHeight = 13
        TabOrder = 4
      end
    end
    object TabCompress: TTabSheet
      Caption = 'Mass File Compressor'
      ImageIndex = 1
      object LblZipOutput: TLabel
        Left = 7
        Top = 4
        Width = 67
        Height = 13
        Caption = 'Output Folder'
      end
      object lblCompressFormat: TLabel
        Left = 6
        Top = 36
        Width = 60
        Height = 13
        Caption = 'Compress to'
      end
      object GrpFilter: TGroupBox
        Left = 87
        Top = 60
        Width = 122
        Height = 113
        Caption = 'Input Filter'
        TabOrder = 0
        object BtnFilAdd: TSpeedButton
          Left = 84
          Top = 16
          Width = 25
          Height = 25
          Flat = True
          Glyph.Data = {
            36030000424D3603000000000000360000002800000010000000100000000100
            18000000000000030000C30E0000C30E00000000000000000000BFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFFF
            FFFFFFFFFFFFFFFFFFFFFFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBF007F00007F00007F00007F00FFFFFFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF007F0000
            7F00007F00007F00FFFFFFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBF007F00007F00007F00007F00FFFFFFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFFFFFFFFFFFFFFFFFFF007F0000
            7F00007F00007F00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBFBFBFBFBFBFBF
            007F00007F00007F00007F00007F00007F00007F00007F00007F00007F00007F
            00007F00FFFFFFBFBFBFBFBFBFBFBFBF007F00007F00007F00007F00007F0000
            7F00007F00007F00007F00007F00007F00007F00FFFFFFBFBFBFBFBFBFBFBFBF
            007F00007F00007F00007F00007F00007F00007F00007F00007F00007F00007F
            00007F00FFFFFFBFBFBFBFBFBFBFBFBF007F00007F00007F00007F00007F0000
            7F00007F00007F00007F00007F00007F00007F00BFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBF007F00007F00007F00007F00FFFFFFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF007F0000
            7F00007F00007F00FFFFFFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBF007F00007F00007F00007F00FFFFFFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF007F0000
            7F00007F00007F00BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF}
          OnClick = BtnFilAddClick
        end
        object BtnFilMin: TSpeedButton
          Left = 84
          Top = 48
          Width = 25
          Height = 25
          Flat = True
          Glyph.Data = {
            36030000424D3603000000000000360000002800000010000000100000000100
            18000000000000030000C30E0000C30E00000000000000000000BFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFBFBFBFBFBFBFBFBF
            00007F00007F00007F00007F00007F00007F00007F00007F00007F00007F0000
            7F00007FFFFFFFBFBFBFBFBFBFBFBFBF00007F00007F00007F00007F00007F00
            007F00007F00007F00007F00007F00007F00007FFFFFFFBFBFBFBFBFBFBFBFBF
            00007F00007F00007F00007F00007F00007F00007F00007F00007F00007F0000
            7F00007FFFFFFFBFBFBFBFBFBFBFBFBF00007F00007F00007F00007F00007F00
            007F00007F00007F00007F00007F00007F00007FBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
            BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF}
          OnClick = BtnFilMinClick
        end
        object ListFilter: TListBox
          Left = 8
          Top = 16
          Width = 73
          Height = 89
          ItemHeight = 13
          TabOrder = 0
        end
      end
      object TxtCompressOutput: TJvDirectoryEdit
        Left = 93
        Top = 0
        Width = 329
        Height = 21
        OnBeforeDialog = TxtUncompressOutputBeforeDialog
        ClipboardCommands = []
        DialogKind = dkWin32
        TabOrder = 1
      end
      object cmbCompressFormat: TComboBox
        Left = 93
        Top = 32
        Width = 145
        Height = 21
        Style = csDropDownList
        ItemHeight = 13
        TabOrder = 2
      end
    end
    object TabRename: TTabSheet
      Caption = 'Rename Files'
      ImageIndex = 2
      object lblRenameFormat: TLabel
        Left = 8
        Top = 80
        Width = 90
        Height = 13
        Caption = 'Rename File Types'
      end
      object RadFileToContent: TRadioButton
        Left = 36
        Top = 8
        Width = 349
        Height = 17
        Caption = 'Rename compressed file to match content'
        Checked = True
        TabOrder = 0
        TabStop = True
        OnClick = RadFileToContentClick
      end
      object RadContentToFile: TRadioButton
        Left = 36
        Top = 40
        Width = 378
        Height = 17
        Caption = 'Rename content to match compressed filename'
        TabOrder = 1
        OnClick = RadContentToFileClick
      end
      object chkLstRename: TCheckListBox
        Left = 84
        Top = 100
        Width = 133
        Height = 73
        ItemHeight = 13
        TabOrder = 2
      end
    end
    object TabVerify: TTabSheet
      Caption = 'Verify Files'
      ImageIndex = 3
      object TLabel
        Left = -1
        Top = 159
        Width = 92
        Height = 13
        Caption = 'Total Files Scanned'
      end
      object lblInvalid: TLabel
        Left = 95
        Top = 179
        Width = 3
        Height = 13
      end
      object TLabel
        Left = 35
        Top = 179
        Width = 56
        Height = 13
        Caption = 'Invalid Files'
      end
      object LblTotVer: TLabel
        Left = 95
        Top = 159
        Width = 3
        Height = 13
      end
      object lblVerifyFormat: TLabel
        Left = 8
        Top = 0
        Width = 79
        Height = 13
        Caption = 'Verify File Types'
      end
      object TxtVerifyOutput: TJvDirectoryEdit
        Left = 85
        Top = 125
        Width = 330
        Height = 21
        OnBeforeDialog = TxtUncompressOutputBeforeDialog
        ClipboardCommands = []
        DialogKind = dkWin32
        Enabled = False
        TabOrder = 0
      end
      object chkLstVerify: TCheckListBox
        Left = 84
        Top = 20
        Width = 133
        Height = 73
        ItemHeight = 13
        TabOrder = 1
      end
      object ChkVerifyMove: TCheckBox
        Left = 84
        Top = 99
        Width = 285
        Height = 17
        Caption = 'Move invalid files to:'
        TabOrder = 2
        OnClick = ChkVerifyMoveClick
      end
    end
  end
  object BtnClose: TButton
    Left = 360
    Top = 486
    Width = 75
    Height = 25
    Caption = '&Close'
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
  object ProgBar: TProgressBar
    Left = 10
    Top = 350
    Width = 425
    Height = 17
    Smooth = True
    Step = 1
    TabOrder = 2
  end
  object memoErrors: TMemo
    Left = 8
    Top = 388
    Width = 428
    Height = 89
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 3
  end
  object TxtInput: TJvDirectoryEdit
    Left = 100
    Top = 8
    Width = 329
    Height = 21
    ClipboardCommands = []
    DialogKind = dkWin32
    DialogOptions = []
    TabOrder = 4
  end
  object ChkSubdir: TCheckBox
    Left = 100
    Top = 33
    Width = 257
    Height = 17
    Caption = 'Include Sub-Directories'
    TabOrder = 5
  end
  object CmbOperation: TComboBox
    Left = 97
    Top = 56
    Width = 145
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 6
    OnChange = CmbOperationChange
    Items.Strings = (
      'File Uncompressor'
      'File Compressor'
      'File Renamer'
      'Verify Files')
  end
  object BtnBegin: TButton
    Left = 189
    Top = 316
    Width = 75
    Height = 25
    Caption = 'Begin'
    TabOrder = 7
    OnClick = BtnBeginClick
  end
end
