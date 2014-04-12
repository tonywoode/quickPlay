object tabThumbBrowser: TtabThumbBrowser
  Left = 0
  Top = 0
  Caption = 'ThumbBrowser'
  ClientHeight = 469
  ClientWidth = 298
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object imgViewer: TImage
    Left = 0
    Top = 0
    Width = 298
    Height = 469
    Hint = 'Double-Click to return to Thumbnail mode'
    Align = alClient
    AutoSize = True
    Center = True
    Proportional = True
    OnDblClick = imgViewerDblClick
    ExplicitHeight = 467
  end
  object jvThumb: TJvImagesViewer
    Left = 0
    Top = 0
    Width = 298
    Height = 469
    HorzScrollBar.Range = 248
    HorzScrollBar.Tracking = True
    HorzScrollBar.Visible = False
    VertScrollBar.Range = 423
    VertScrollBar.Tracking = True
    FileMask = 
      '*.gif;*.pcx;*.ani;*.jpg;*.jpeg;*.jpg;*.jpeg;*.bmp;*.ico;*.emf;*.' +
      'wmf'
    Options.AutoCenter = False
    Options.HotTrack = False
    Options.ImagePadding = 10
    Options.MultiSelect = False
    SelectedIndex = -1
    Align = alClient
    TabOrder = 0
    TabStop = True
    OnDblClick = jvThumbDblClick
  end
end
