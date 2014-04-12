object EditCfgForm: TEditCfgForm
  Left = 323
  Top = 193
  BorderIcons = [biSystemMenu, biMaximize]
  Caption = 'Edit Configuration File'
  ClientHeight = 375
  ClientWidth = 561
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object MemoCfg: TMemo
    Left = 0
    Top = 0
    Width = 561
    Height = 345
    Align = alClient
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 345
    Width = 561
    Height = 30
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object Panel2: TPanel
      Left = 376
      Top = 0
      Width = 185
      Height = 30
      Align = alRight
      BevelOuter = bvNone
      TabOrder = 0
      object BtnClose: TButton
        Left = 104
        Top = 4
        Width = 75
        Height = 25
        Caption = '&Close'
        ModalResult = 2
        TabOrder = 1
      end
      object BtnSave: TButton
        Left = 24
        Top = 4
        Width = 75
        Height = 25
        Caption = '&Save'
        Default = True
        TabOrder = 0
        OnClick = BtnSaveClick
      end
    end
  end
  object MainMenu1: TMainMenu
    AutoHotkeys = maManual
    Left = 96
    Top = 48
    object File1: TMenuItem
      Caption = '&File'
      object Save1: TMenuItem
        Caption = '&Save'
        OnClick = BtnSaveClick
      end
      object Close1: TMenuItem
        Caption = '&Close'
        OnClick = Close1Click
      end
    end
    object Edit1: TMenuItem
      Caption = '&Edit'
      object Cut1: TMenuItem
        Action = EditCut1
      end
      object Copy1: TMenuItem
        Action = EditCopy1
      end
      object Paste1: TMenuItem
        Action = EditPaste1
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object SelectAll1: TMenuItem
        Action = EditSelectAll1
      end
    end
    object Format1: TMenuItem
      Caption = 'F&ormat'
      object WordWrap1: TMenuItem
        Action = ActWordWrap
      end
    end
  end
  object EditActions: TActionList
    Left = 128
    Top = 48
    object EditCut1: TEditCut
      Category = 'Edit'
      Caption = 'Cu&t'
      Hint = 'Cut|Cuts the selection and puts it on the Clipboard'
      ImageIndex = 0
      ShortCut = 16472
    end
    object EditCopy1: TEditCopy
      Category = 'Edit'
      Caption = '&Copy'
      Hint = 'Copy|Copies the selection and puts it on the Clipboard'
      ImageIndex = 1
      ShortCut = 16451
    end
    object EditPaste1: TEditPaste
      Category = 'Edit'
      Caption = '&Paste'
      Hint = 'Paste|Inserts Clipboard contents'
      ImageIndex = 2
      ShortCut = 16470
    end
    object EditSelectAll1: TEditSelectAll
      Category = 'Edit'
      Caption = 'Select &All'
      Hint = 'Select All|Selects the entire document'
      ShortCut = 16449
    end
    object ActWordWrap: TAction
      Category = 'Format'
      Caption = '&Word Wrap'
      Checked = True
      OnExecute = ActWordWrapExecute
    end
  end
end
