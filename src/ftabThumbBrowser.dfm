object tabThumbBrowser: TtabThumbBrowser
  Left = 0
  Top = 0
  Caption = 'ThumbBrowser'
  ClientHeight = 613
  ClientWidth = 390
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 17
  object imgViewer: TImage
    Left = 0
    Top = 0
    Width = 390
    Height = 613
    Hint = 'Double-Click to return to Thumbnail mode'
    Align = alClient
    AutoSize = True
    Center = True
    Proportional = True
    OnDblClick = imgViewerDblClick
  end
  object jvThumb: TJvImagesViewer
    Left = 0
    Top = 0
    Width = 390
    Height = 613
    HorzScrollBar.Range = 372
    HorzScrollBar.Tracking = True
    HorzScrollBar.Visible = False
    VertScrollBar.Range = 288
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
