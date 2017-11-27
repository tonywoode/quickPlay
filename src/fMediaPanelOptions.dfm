object FrmMediaPanelOptions: TFrmMediaPanelOptions
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Media Panel Options'
  ClientHeight = 787
  ClientWidth = 1018
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 17
  object BtnOK: TButton
    Left = 807
    Top = 750
    Width = 98
    Height = 33
    Caption = '&OK'
    ModalResult = 1
    TabOrder = 2
    OnClick = BtnOKClick
  end
  object BtnCancel: TButton
    Left = 912
    Top = 750
    Width = 98
    Height = 33
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object PanHeader: TPanel
    Left = 0
    Top = 0
    Width = 1018
    Height = 68
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    ExplicitWidth = 930
    object lblHeader: TLabel
      Left = 84
      Top = 21
      Width = 239
      Height = 28
      Caption = 'Media Panel Options'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Image1: TImage
      Left = 10
      Top = 5
      Width = 48
      Height = 48
      AutoSize = True
      Picture.Data = {
        07544269746D6170361B0000424D361B00000000000036000000280000003000
        0000300000000100180000000000001B0000120B0000120B0000000000000000
        00000000FF0000FF0000FF0000FF0000FF0000FF808080414141515151808080
        B0B0B0D0D0D00000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000
        FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF00
        00FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF
        0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000
        FF80808001010101010101010101010101010101010101010131313151515180
        8080B0B0B0D0D0D00000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF
        0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000
        FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF00
        00FF0000FF0000FF0000FF0000FF0000FF313131010101010101010101010101
        0101010101010101010101010101010101010101010101010101013131315151
        51808080A0A0A0C0C0C00000FF0000FF0000FF0000FF0000FF0000FF0000FF00
        00FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF
        0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000
        FF010101010101F8F8F8D9D9D9BBBBBB7E7E7E5E5E5E3F3F3F01010101010101
        0101010101010101010101010101010101010101010101010101010101212121
        414141808080A0A0A0C0C0C00000FF0000FF0000FF0000FF0000FF0000FF0000
        FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF00
        00FF0000FF0000FF0000FF0000FFB0B0B00101013F3F3FF8F8F8F8F8F8F8F8F8
        F9F9F9F9F9F9F9F9F9F9F9F9EAEAEABCBCBC8D8D8D6E6E6E4040401111110101
        0101010101010101010101010101010101010101010101010101010101010121
        2121414141808080A0A0A0C0C0C00000FF0000FF0000FF0000FF0000FF0000FF
        0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF7171
        710101017D7D7DF7F7F7F8F8F8F8F8F8F8F8F8F8F8F8F9F9F9F9F9F9F9F9F9F9
        F9F9FAFAFAFAFAFAFAFAFAFAFAFAEBEBEBBCBCBC8D8D8D6F6F6F404040111111
        0101010101010101010101010101010101010101010101010101010101010101
        01111111414141717171909090C0C0C00000FF0000FF0000FF0000FF0000FF00
        00FF0000FF0000FF0000FF0000FF414141010101B9B9B9F7F7F7F7F7F7F7F7F7
        F8F8F8F8F8F8F8F8F8F8F8F8F9F9F9F9F9F9F9F9F9F9F9F9FAFAFAFAFAFAFAFA
        FAFBFBFBFBFBFBFBFBFBFBFBFBFCFCFCECECECBDBDBD9E9E9E7F7F7F40404021
        2121010101010101010101010101010101010101010101010101010101010101
        010101111111414141717171A0A0A00000FF0000FF0000FF0000FF0000FF0101
        01010101F6F6F6F6F6F6F7F7F7F7F7F7F7F7F7F7F7F7F8F8F8F8F8F8F8F8F8F8
        F8F8F9F9F9F9F9F9F9F9F9FAFAFAFAFAFAFAFAFAFAFAFAFBFBFBFBFBFBFBFBFB
        FBFBFBFCFCFCFCFCFCFCFCFCFCFCFCFDFDFDFDFDFDBEBEBE9E9E9E8080804141
        4121212101010101010101010101010101010101010101010101010101010180
        80800000FF0000FF0000FFC0C0C00101012F2F2FF6F6F6F6F6F6F6F6F6F6F6F6
        F7F7F7F7F7F7F7F7F7F7F7F7F8F8F8F8F8F8F8F8F8F9F9F9F9F9F9F9F9F9F9F9
        F9FAFAFAFAFAFAFAFAFAFAFAFAFBFBFBFBFBFBFBFBFBFBFBFBFCFCFCFCFCFCFC
        FCFCFDFDFDFDFDFDFDFDFDFDFDFDFEFEFEFEFEFEFEFEFEBFBFBF9F9F9F818181
        5151513131310101010101010101014141410000FF0000FF0000FF9090900101
        016C6C6CF5F5F5F5F5F5F6F6F6E9F0E9D0E3D0F6F6F6F7F7F7F7F7F7F7F7F7F8
        F8F8F8F8F8F8F8F8F8F8F8F9F9F9F9F9F9F9F9F9F9F9F9FAFAFAFAFAFAFAFAFA
        FAFAFAFBFBFBFBFBFBFBFBFBFCFCFCFCFCFCFCFCFCFCFCFCFDFDFDFDFDFDFDFD
        FDFDFDFDFEFEFEFEFEFEFEFEFEFFFFFFFFFFFFFFFFFFFFFFFF41414101010161
        61610000FF0000FF0000FF616161010101999999F5F5F5F5F5F5F5F5F592C692
        2F952F2D932D52A4526AB06A8FC38FB6D6B6D0E3D0F8F8F8F8F8F8F8F8F8F8F8
        F8F9F9F9F9F9F9F9F9F9F9F9F9FAFAFAFAFAFAFAFAFAFBFBFBFBFBFBFBFBFBFB
        FBFBFCFCFCFCFCFCFCFCFCFCFCFCFDFDFDFDFDFDFDFDFDFEFEFEFEFEFEFEFEFE
        FEFEFEFFFFFFFFFFFF010101010101A0A0A00000FF0000FF0000FF3131310101
        01C6C6C6F4F4F4F4F4F4F5F5F564B2643299323097302F962F2D932D2B912B2A
        8F2A288D28268B264D9F4D73B2738DBF8DC2DBC2DDEADDF9F9F9F9F9F9F9F9F9
        FAFAFAFAFAFAFAFAFAFAFAFAFBFBFBFBFBFBFBFBFBFBFBFBFCFCFCFCFCFCFCFC
        FCFDFDFDFDFDFDFDFDFDFDFDFDFEFEFEFEFEFEFEFEFEAFAFAF01010101010100
        00FF0000FF0000FF0000FF010101010101F3F3F3F4F4F4F4F4F4F4F4F443A543
        359D35339B33329A323098302F962F2D942D2B912B2A8F2A288E28278C27258A
        2523882321862120832056A05670AE7098C398C1DAC1ECF2ECFAFAFAFAFAFAFA
        FAFAFBFBFBFBFBFBFBFBFBFCFCFCFCFCFCFCFCFCFCFCFCFDFDFDFDFDFDFDFDFD
        FDFDFDFEFEFE7070700101014141410000FF0000FF0000FFD0D0D00101013E3E
        3EF3F3F3F3F3F3F4F4F4D1E5D13AA43A39A139379F37359D35349C34329A3231
        98312F962F2D942D2B922B2A902A288E28278C27258A25238823218621208420
        1E821E1C811C1B7F1B278427519A517BB17B95C195C1D9C1ECF3ECFBFBFBFBFB
        FBFCFCFCFCFCFCFCFCFCFCFCFCFDFDFDFDFDFDFDFDFD21212101010190909000
        00FF0000FF0000FFB0B0B00101015C5C5CF3F3F3F3F3F3F3F3F3BBDCBB3EA83E
        3CA63C3AA43A39A13937A037369E36349C34329A323198312F962F2D942D2B92
        2B2A902A288E28278C27258A252388232186212084201E821E1C811C1B7F1B19
        7D19187B181679161477143085304C954C85B685A2C7A2CFE1CFFCFCFCFCFCFC
        FCFCFCDDDDDD010101010101D0D0D00000FF0000FF0000FF8080800101017A7A
        7AF2F2F2F2F2F2F3F3F39AD09A41AC4140AA403EA83E3CA63C3AA43A39A23937
        A037369E36349C34329A323198312F962F2D942D2B922B2A902A288E28278C27
        258A252388232286222084201F821F1D811D1B7F1B197D19187B181679161477
        1412751211731168A468FBFBFBFCFCFCFCFCFC8E8E8E0101011111110000FF00
        00FF0000FF0000FF515151010101B5B5B5F2F2F2F2F2F2F2F2F271C27145B045
        43AE4341AC4140AA403EA83E3CA63C3AA43A39A23938A038369E36349C34329A
        323198312F962F2D942D2B922B2A902A288E28278C27258A2523882322862220
        84201F821F1D811D1B7F1B197D19187B18167916147714A3C8A3FBFBFBFBFBFB
        FCFCFC5050500101015151510000FF0000FF0000FF0000FF313131010101D3D3
        D3F1F1F1F1F1F1F2F2F2B6D18F48B44847B24745B04543AE4341AC4140AA403E
        A83E3CA63C3BA43B39A23938A038369E36349C34329A323198312F962F2E942E
        2C922C2A902A298E29278C27258A252388232286222084201F821F1D811D1B7F
        1B197D19187B18DEEADEFBFBFBFBFBFBFBFBFB111111010101A0A0A00000FF00
        00FF0000FF0000FF010101010101F0F0F0F1F1F1F1F1F1F1F1F1FADCAACED291
        55B85048B44847B24745B04543AE4341AC4140AA403EA83E3CA63C3BA43B39A2
        3938A038369E36349C34329A323198312F962F2E942E2C922C2A902A298E2927
        8C27258A252388232286222084201F821F1D811D378E37FAFAFAFAFAFAFAFAFA
        CCCCCC010101010101E0E0E00000FF0000FF0000FFE0E0E00101013D3D3DF0F0
        F0F0F0F0F0F0F0F3EBDFFAD9A7FAD9A7D9D3966CBE5C4AB64A48B44847B24745
        B04543AE4342AC4240AA403EA83E3DA63D3BA43B51A9475CAA4C369E36349C34
        329A323198313096302E942E2C922C2A902A298E29278C27258A252388232286
        2220842063A763F9F9F9FAFAFAFAFAFA8D8D8D0101012121210000FF0000FF00
        00FF0000FFC0C0C00101014C4C4CEFEFEFF0F0F0F0F0F0F3E7D4F9D8A5F9D8A5
        F9D8A5EED69F97C6734BB84B4AB64A48B44847B24745B04543AE4359B14E90BD
        6CD6CE91F9D8A5F9D8A5B0C37D38A038369E36349C34329A323198313096302E
        942E2C922C2A902A298E29278C27258A252388239AC79AF9F9F9F9F9F9F9F9F9
        4F4F4F0101015151510000FF0000FF0000FF0000FF909090010101797979EFEF
        EFEFEFEFF0F0F0F4E3C9F9D5A2F9D5A2F9D5A2F9D5A2F9D5A2CECE8D8CC36D77
        BF618AC16BABC67BD7CE90F9D5A2F9D5A2F9D5A2F9D5A2F9D5A2F9D5A299BC6E
        39A23938A038369E36349C34339A333198313097302E942E2C922C2A902A298E
        29278C27C3DDC3F8F8F8F9F9F9F9F9F92020200101019090900000FF0000FF00
        00FF0000FF808080010101868686EFEFEFEFEFEFEFEFEFF5DBB8F8D29FF8D29F
        F8D29FF8D29FF8D29FF8D29FF8D29FF8D29FF8D29FF8D29FF8D29FF8D29FF8D2
        9FF8D29FF8D29FF8D29FF8D29FF8D29F82B6613BA53B39A23938A038369E3634
        9C34339A333199313097302E952E2C922C2A902AF8F8F8F8F8F8F8F8F8D9D9D9
        010101010101D0D0D00000FF0000FF0000FF0000FF515151010101B3B3B3EEEE
        EEEEEEEEEFEFEFF5D8B1F7D19DF7D19DF7D19DF7D19DF7D19DF7D19DF7D19DF7
        D19DF7D19DF7D19DF7D19DF7D19DF7D19DF7D19DF7D19DF7D19DF7D19DF7D19D
        ECCE9761B0503DA73D3BA53B3AA33A38A038369E36359D35339B333199313097
        3061AD61F7F7F7F7F7F7F8F8F89B9B9B0101010101010000FF0000FF0000FF00
        00FF0000FF414141010101C1C1C1EEEEEEEEEEEEEEEEEEF6D09FF7CE9AF7CE9A
        F7CE9AF7CE9AF7CE9AF7CE9AF7CE9AF7CE9AF7CE9AF7CE9AF7CE9AF7CE9AF7CE
        9AF7CE9AF7CE9AF7CE9AF7CE9AF7CE9AF7CE9AE0CA8F4CAD463FA93F3DA73D3B
        A53B3AA33A38A138379F37359D35339B3387C287F7F7F7F7F7F7F7F7F76D6D6D
        0101014141410000FF0000FF0000FF0000FF0000FF111111010101EDEDEDEDED
        EDEDEDEDEEEEEEF6CC97F6CC97F6CC97F6CC97F6CC97F6CC97F6CC97F6CC97F6
        CC97F6CC97F6CC97F6CC97F6CC97F6CC97F6CC97F6CC97F6CC97F6CC97F6CC97
        F6CC97F6CC97BEC27D42AD4241AB413FA93F3DA73D3BA53B3AA33A38A138379F
        37ADD5ADF6F6F6F7F7F7F7F7F73F3F3F0101017171710000FF0000FF0000FF00
        00FF0000FF010101010101ECECECEDEDEDEDEDEDEEE9E2F6CA94F6CA94F6CA94
        F6CA94F6CA94F6CA94F6CA94F6CA94F6CA94F6CA94F6CA94F6CA94F6CA94F6CA
        94F6CA94F6CA94F6CA94F6CA94F6CA94F6CA94F6CA94F6CA949DBD6D44AF4442
        AD4241AB413FA93F3DA73D3BA53B3AA33AD2E6D2F6F6F6F6F6F6F6F6F6010101
        010101B0B0B00000FF0000FF0000FF0000FF0000FF0101013C3C3CECECECECEC
        ECECECECEFE3D6F5C791F5C791F5C791F5C791F5C791F5C791F5C791F5C791F5
        C791F5C791F5C791F5C791F5C791F5C791F5C791F5C791F5C791F5C791F5C791
        F5C791F5C791F5C791F5C7917EB95E46B14644AF4442AD4241AB413FA93F3DA7
        3DF5F5F5F5F5F5F6F6F6C8C8C8010101010101E0E0E00000FF0000FF0000FF00
        00FFC0C0C00101013C3C3CEBEBEBECECECECECECEFE0CFF5C58EF5C58EF5C58E
        F5C58EE5C8958ADEC07CE2C78ADEC0D6CC9DF5C58EF5C58EF5C58EF5C58EF5C5
        8EF5C58EF5C58EF5C58EF5C58EF5C58EF5C58EF5C58EF5C58EF5C58EEAC48A69
        B85648B34846B14644AF4442AD4263B963F5F5F5F5F5F5F5F5F5999999010101
        1111110000FF0000FF0000FF0000FF0000FFC0C0C0010101686868EBEBEBEBEB
        EBECECECF0D7BCF4C38CF4C38CF4C38CE5C7932FF4EA01FFFF01FFFF01FFFF10
        FBF8C6CEA2F4C38CF4C38CF4C38CF4C38CF4C38CF4C38CF4C38CF4C38CF4C38C
        F4C38CF4C38CF4C38CF4C38CF4C38CE9C2886AB95749B54952B44C86B760D3D1
        A5F4F4F4F4F4F4F5F5F56C6C6C0101014141410000FF0000FF0000FF0000FF00
        00FFA0A0A0010101767676EBEBEBEBEBEBEBEBEBEFD6BAF3C089F3C089F3C089
        7BE0C401FFFF01FFFF01FFFF01FFFF01FFFF4DEBDAF3C089F3C089F3C089F3C0
        89F3C089F3C089F3C089F3C089F3C089F3C089F3C089F3C089F3C089F3C089F3
        C089F3C089F3C089F3C089F3C089F3DABEF4F4F4F4F4F4F4F4F43E3E3E010101
        7171710000FF0000FF0000FF0000FF0000FF808080010101767676EAEAEAEAEA
        EAEBEBEBF0D1B2F3BE86F3BE86F3BE863EEFE101FFFF01FFFF01FFFF01FFFF01
        FFFF01FFFFF3BE86F3BE86F3BE86F3BE86F3BE86F3BE86F3BE86F3BE86F3BE86
        F3BE86F3BE86F3BE86F3BE86F3BE86F3BE86F3BE86F3BE86F3BE86F3BE86F3E6
        D8F3F3F3F3F3F3F4F4F4010101010101A0A0A00000FF0000FF0000FF0000FF00
        00FF808080010101A0A0A0EAEAEAEAEAEAEAEAEAF0C79DF2BC84F2BC84F2BC84
        5CE6D101FFFF01FFFF01FFFF01FFFF01FFFF1FF7F0F2BC84F2BC84F2BC84F2BC
        84F2BC84F2BC84F2BC84F2BC84F2BC84F2BC84F2BC84F2BC84F2BC84F2BC84F2
        BC84F2BC84F2BC84F2BC84F2BC84F2ECE5F3F3F3F3F3F3D5D5D5010101010101
        C0C0C00000FF0000FF0000FF0000FF0000FF717171010101AFAFAFE9E9E9E9E9
        E9EAEAEAF0C59BF2B981F2B981F2B981B5CAA001FFFF01FFFF01FFFF01FFFF01
        FFFF7ADCC0F2B981F2B981F2B981F2B981F2B981F2B981F2B981F2B981F2B981
        F2B981F2B981F2B981F2B981F2B981F2B981F2B981F2B981F2B981F2B981F2F2
        F2F2F2F2F3F3F3B6B6B60101010101010000FF0000FF0000FF0000FF0000FF00
        00FF414141010101AEAEAEE9E9E9E9E9E9E9E9E9EFC399F1B77FF1B77FF1B77F
        F1B77F97D2AE1FF6EF01FFFF10FAF77ADBBEF1B77FF1B77FF1B77FF1B77FF1B7
        7FF1B77FF1B77FF1B77FF1B77FF1B77FF1B77FF1B77FF1B77FF1B77FF1B77FF1
        B77FF1B77FF1B77FF1B77FF1C294F2F2F2F2F2F2F2F2F27A7A7A010101212121
        0000FF0000FF0000FF0000FF0000FF0000FF414141010101BDBDBDE8E8E8E9E9
        E9E9E9E9F0BB89F1B57DF1B57DF1B57DF1B57DF1B57DF1B57DF1B57DF1B57DF1
        B57DF1B57DF1B57DF1B57DF1B57DF1B57DF1B57DF1B57DF1B57DF1B57DF1B57D
        F1B57DF1B57DF1B57DF1B57DF1B57DF1B57DF1B57DF1B57DF1B57DF1C499F1F1
        F1F1F1F1F2F2F25C5C5C0101014141410000FF0000FF0000FF0000FF0000FF00
        00FF414141010101E7E7E7E8E8E8E8E8E8E8E8E8F0B27AF0B27AF0B27AF0B27A
        F0B27AF0B27AF0B27AF0B27AF0B27AF0B27AF0B27AF0B27AF0B27AF0B27AF0B2
        7AF0B27AF0B27AF0B27AF0B27AF0B27AF0B27AF0B27AF0B27AF0B27AF0B27AF0
        B27AF0B27AF0B27AF0B27AF0D1B5F1F1F1F1F1F1F1F1F13D3D3D010101717171
        0000FF0000FF0000FF0000FF0000FF0000FF414141010101E7E7E7E7E7E7E8E8
        E8E8E8E8EBD7C5ECCCB0EDC29AEEBB8CF0B077F0B077F0B077F0B077F0B077F0
        B077F0B077F0B077F0B077F0B077F0B077F0B077F0B077F0B077F0B077F0B077
        F0B077F0B077F0B077F0B077F0B077F0B077F0B077F0B077F0B077F0D4BBF0F0
        F0F0F0F0F1F1F11010100101018080800000FF0000FF0000FF0000FF0000FF00
        00FF212121010101E6E6E6E7E7E7E7E7E7E7E7E7E8E8E8E8E8E8E8E8E8E8E8E8
        E9E9E9EADED3EBD7C5ECCCAFEDC199EEB98AEFAE75EFAE75EFAE75EFAE75EFAE
        75EFAE75EFAE75EFAE75EFAE75EFAE75EFAE75EFAE75EFAE75EFAE75EFAE75EF
        AE75EFAE75EFAE75EFAE75EFDFD0F0F0F0F0F0F0F0F0F0010101010101C0C0C0
        0000FF0000FF0000FF0000FF0000FF0000FF010101010101E5E5E5E5E5E5E7E7
        E7E7E7E7E7E7E7E7E7E7E8E8E8E8E8E8E8E8E8E9E9E9E9E9E9E9E9E9E9E9E9EA
        EAEAEAEAEAEBDED4EBD7C4ECCBAEEDBF97EDB788EEAB72EEAB72EEAB72EEAB72
        EEAB72EEAB72EEAB72EEAB72EEAB72EEAB72EEAB72EEAB72EEAB72EFE2D7EFEF
        EFEFEFEFB4B4B4010101010101D0D0D00000FF0000FF0000FF0000FF0000FF00
        00FF3131310101017474749D9D9DBABABAE6E6E6E7E7E7E7E7E7E7E7E7E8E8E8
        E8E8E8E8E8E8E8E8E8E9E9E9E9E9E9E9E9E9E9E9E9EAEAEAEAEAEAEAEAEAEAEA
        EAEBEBEBEBEBEBECDFD4ECD7C4EDCBAEEDBE96EEB686EEA96FEEA96FEEA96FEE
        A96FEEA96FEEA96FEEA96FEEEEEEEFEFEFEFEFEFB3B3B30101010101010000FF
        0000FF0000FF0000FF0000FF0000FF0000FFD0D0D02121210101010101010101
        010101012C2C2C4949497575759F9F9FBCBCBCE8E8E8E8E8E8E8E8E8E8E8E8E9
        E9E9E9E9E9E9E9E9E9E9E9EAEAEAEAEAEAEAEAEAEBEBEBEBEBEBEBEBEBEBEBEB
        ECECECECECECECECECECDFD4EDD7C5EDCAADEDBD94EDB484EDA76DEEEEEEEEEE
        EEEFEFEF7979790101010101010000FF0000FF0000FF0000FF0000FF0000FF00
        00FF0000FF0000FF0000FFC0C0C0A0A0A0808080414141212121010101010101
        0101010101012D2D2D4A4A4A757575A0A0A0BDBDBDE9E9E9E9E9E9E9E9E9EAEA
        EAEAEAEAEAEAEAEAEAEAEBEBEBEBEBEBEBEBEBEBEBEBECECECECECECECECECEC
        ECECEDEDEDEDEDEDEDEDEDEEEEEEEEEEEEEEEEEE7878780101014141410000FF
        0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000
        FF0000FF0000FF0000FF0000FFC0C0C0A0A0A080808041414121212101010101
        01010101010101012D2D2D4A4A4A767676A0A0A0AFAFAFEAEAEAEAEAEAEAEAEA
        EBEBEBEBEBEBEBEBEBEBEBEBECECECECECECECECECEDEDEDEDEDEDEDEDEDEDED
        EDEEEEEE4B4B4B0101014141410000FF0000FF0000FF0000FF0000FF0000FF00
        00FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF
        0000FF0000FF0000FF0000FF0000FFC0C0C0A0A0A08080804141412121210101
        010101010101010101011E1E1E3C3C3C767676939393B0B0B0EBEBEBEBEBEBEC
        ECECECECECECECECECECECEDEDEDEDEDEDEDEDED3C3C3C0101017171710000FF
        0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000
        FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF00
        00FF0000FF0000FF0000FF0000FF0000FFD0D0D0B0B0B0808080515151313131
        0101010101010101010101011E1E1E3C3C3C777777949494B1B1B1ECECECECEC
        ECEDEDED2D2D2D0101018080800000FF0000FF0000FF0000FF0000FF0000FF00
        00FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF
        0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000
        FF0000FF0000FF0000FF0000FF0000FF0000FFD0D0D0B0B0B080808051515131
        31310101010101010101010101011F1F1F3C3C3C010101010101A0A0A00000FF
        0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000
        FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF00
        00FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF
        0000FF0000FF0000FF0000FF0000FF0000FF0000FFD0D0D0B0B0B08080805151
        513131311111117171710000FF0000FF0000FF0000FF0000FF0000FF0000FF00
        00FF}
      Transparent = True
    end
  end
  object pgMediaOptions: TPageControl
    Left = 0
    Top = 68
    Width = 1018
    Height = 676
    ActivePage = TabGeneral
    Align = alTop
    TabOrder = 1
    ExplicitWidth = 930
    object TabGeneral: TTabSheet
      Caption = 'Media Options'
      object ChkEmuTab: TCheckBox
        Left = 565
        Top = 167
        Width = 388
        Height = 23
        Caption = 'Add Tab for emulators with media settings'
        Checked = True
        State = cbChecked
        TabOrder = 0
      end
      object GrpFolderImg: TRadioGroup
        Left = 565
        Top = 21
        Width = 336
        Height = 137
        Caption = 'Default Folder Image'
        ItemIndex = 0
        Items.Strings = (
          'QuickPlay Logo'
          'System Image Based On ROMs')
        TabOrder = 1
      end
      object GrpAutoMove: TGroupBox
        Left = 31
        Top = 21
        Width = 336
        Height = 169
        Caption = 'Auto Move Through Tabs'
        TabOrder = 2
        object TLabel
          Left = 42
          Top = 99
          Width = 80
          Height = 17
          Caption = 'Time Per Tab'
        end
        object TLabel
          Left = 211
          Top = 99
          Width = 52
          Height = 17
          Caption = 'Seconds'
        end
        object TxtTimePerTab: TSpinEdit
          Left = 146
          Top = 93
          Width = 54
          Height = 27
          MaxValue = 0
          MinValue = 0
          TabOrder = 0
          Value = 10
        end
        object ChkAutoMoveThroughTabs: TCheckBox
          Left = 10
          Top = 42
          Width = 305
          Height = 22
          Caption = 'Automatically move through tabs'
          Checked = True
          State = cbChecked
          TabOrder = 1
        end
      end
    end
    object TabPaths: TTabSheet
      Caption = 'Path Configuration'
      ImageIndex = 1
      ExplicitWidth = 922
      object lblSystems: TLabel
        Left = 0
        Top = 21
        Width = 63
        Height = 18
        Caption = 'Systems'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblTabs: TLabel
        Left = 290
        Top = 21
        Width = 35
        Height = 18
        Caption = 'Tabs'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object VTSystems: TVirtualStringTree
        Left = 0
        Top = 42
        Width = 281
        Height = 587
        DefaultNodeHeight = 20
        Header.AutoSizeIndex = 0
        Header.DefaultHeight = 17
        Header.Font.Charset = DEFAULT_CHARSET
        Header.Font.Color = clWindowText
        Header.Font.Height = -11
        Header.Font.Name = 'Tahoma'
        Header.Font.Style = []
        Header.MainColumn = -1
        Header.Options = [hoColumnResize, hoDrag]
        Images = MainFrm.IconList
        TabOrder = 0
        TreeOptions.AutoOptions = [toDisableAutoscrollOnFocus]
        TreeOptions.MiscOptions = [toFullRepaintOnResize, toInitOnSave, toToggleOnDblClick, toWheelPanning]
        TreeOptions.PaintOptions = [toThemeAware, toUseBlendedImages]
        TreeOptions.SelectionOptions = [toExtendedFocus, toFullRowSelect]
        OnFocusChanging = VTSystemsFocusChanging
        OnGetText = VTSystemsGetText
        OnGetImageIndex = VTSystemsGetImageIndex
        Columns = <>
      end
      object VTTabs: TVirtualStringTree
        Left = 287
        Top = 42
        Width = 187
        Height = 587
        DefaultNodeHeight = 24
        DragMode = dmAutomatic
        DragOperations = [doMove]
        DragType = dtVCL
        Header.AutoSizeIndex = 0
        Header.DefaultHeight = 17
        Header.Font.Charset = DEFAULT_CHARSET
        Header.Font.Color = clWindowText
        Header.Font.Height = -11
        Header.Font.Name = 'Tahoma'
        Header.Font.Style = []
        Header.MainColumn = -1
        Header.Options = [hoColumnResize, hoDrag]
        TabOrder = 1
        TreeOptions.AutoOptions = [toDisableAutoscrollOnFocus]
        TreeOptions.MiscOptions = [toCheckSupport, toFullRepaintOnResize, toInitOnSave, toToggleOnDblClick, toWheelPanning, toFullRowDrag]
        TreeOptions.PaintOptions = [toHideFocusRect, toShowDropmark, toThemeAware, toUseBlendedImages]
        OnChecked = VTTabsChecked
        OnCompareNodes = VTTabsCompareNodes
        OnDragOver = VTTabsDragOver
        OnDragDrop = VTTabsDragDrop
        OnFocusChanging = VTTabsFocusChanging
        OnGetText = VTTabsGetText
        OnInitNode = VTTabsInitNode
        Columns = <>
      end
      object pgConfig: TPageControl
        Left = 480
        Top = 42
        Width = 527
        Height = 584
        ActivePage = TabTabConfig
        TabOrder = 4
        object TabSystemConfig: TTabSheet
          Caption = 'TabSystemConfig'
          OnExit = TabSystemConfigExit
          ExplicitWidth = 537
          object lblSysImage: TLabel
            Left = 10
            Top = 52
            Width = 88
            Height = 17
            Caption = 'System Image'
          end
          object lblSystemConfigHeader: TLabel
            Left = 10
            Top = 0
            Width = 240
            Height = 27
            Caption = 'System Configuration'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -22
            Font.Name = 'Tahoma'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object TxtSysImage: TJvFilenameEdit
            Left = 128
            Top = 50
            Width = 305
            Height = 25
            AddQuotes = False
            DialogKind = dkOpenPicture
            DialogOptions = [ofHideReadOnly, ofPathMustExist, ofFileMustExist]
            ButtonWidth = 27
            TabOrder = 0
          end
          object ChkShowAddInfo: TCheckBox
            Left = 10
            Top = 94
            Width = 410
            Height = 22
            Caption = 'Show Additional Information'
            TabOrder = 1
          end
          object MemoSysInfo: TMemo
            Left = 31
            Top = 136
            Width = 483
            Height = 388
            ScrollBars = ssBoth
            TabOrder = 2
          end
        end
        object TabTabConfig: TTabSheet
          Caption = 'TabTabConfig'
          ImageIndex = 1
          OnExit = TabTabConfigExit
          ExplicitWidth = 537
          object TLabel
            Left = 44
            Top = 21
            Width = 58
            Height = 17
            Caption = 'Tab Type'
          end
          object TLabel
            Left = 10
            Top = 61
            Width = 88
            Height = 17
            Caption = 'Search Criteria'
          end
          object pgTabOptions: TPageControl
            Left = 7
            Top = 355
            Width = 503
            Height = 194
            ActivePage = TabTextConfig
            TabOrder = 4
            object TabThumbnails: TTabSheet
              Caption = 'Thumbnail'
              object lblThumbHeight: TLabel
                Left = 51
                Top = 18
                Width = 39
                Height = 17
                Caption = 'Height'
              end
              object lblThumbWidth: TLabel
                Left = 55
                Top = 52
                Width = 37
                Height = 17
                Caption = 'Width'
              end
              object lblThbHorzGap: TLabel
                Left = 0
                Top = 93
                Width = 88
                Height = 17
                Caption = 'Horizontal Gap'
              end
              object lblThbVertGap: TLabel
                Left = 17
                Top = 128
                Width = 71
                Height = 17
                Caption = 'Vertical Gap'
              end
              object RadThumbBottom: TRadioButton
                Left = 230
                Top = 12
                Width = 221
                Height = 22
                Caption = 'Caption on Bottom'
                Checked = True
                TabOrder = 4
                TabStop = True
              end
              object RadThumbOnTop: TRadioButton
                Left = 230
                Top = 43
                Width = 242
                Height = 22
                Caption = 'Caption On Top'
                TabOrder = 5
              end
              object ChkThumbCaption: TCheckBox
                Left = 230
                Top = 75
                Width = 259
                Height = 22
                Caption = 'Show Caption (Filename)'
                Checked = True
                State = cbChecked
                TabOrder = 6
              end
              object TxtThumbVertGap: TSpinEdit
                Left = 115
                Top = 122
                Width = 75
                Height = 27
                MaxValue = 0
                MinValue = 0
                TabOrder = 3
                Value = 4
              end
              object TxtThumbHorzGap: TSpinEdit
                Left = 115
                Top = 86
                Width = 75
                Height = 27
                MaxValue = 0
                MinValue = 0
                TabOrder = 2
                Value = 4
              end
              object TxtThumbWidth: TSpinEdit
                Left = 115
                Top = 46
                Width = 75
                Height = 27
                MaxValue = 0
                MinValue = 0
                TabOrder = 1
                Value = 120
              end
              object TxtThumbHeight: TSpinEdit
                Left = 115
                Top = 12
                Width = 75
                Height = 27
                MaxValue = 0
                MinValue = 0
                TabOrder = 0
                Value = 120
              end
            end
            object TabImages: TTabSheet
              Caption = 'Images'
              ImageIndex = 1
              object lblTimeOut: TLabel
                Left = 10
                Top = 48
                Width = 84
                Height = 17
                Caption = 'Time Per Slide'
              end
              object lblSeconds: TLabel
                Left = 184
                Top = 48
                Width = 52
                Height = 17
                Caption = 'Seconds'
              end
              object ChkEnableSlideshow: TCheckBox
                Left = 10
                Top = 10
                Width = 357
                Height = 23
                Caption = 'Enable SlideShow'
                Checked = True
                State = cbChecked
                TabOrder = 0
              end
              object ChkShowControlBar: TCheckBox
                Left = 10
                Top = 94
                Width = 378
                Height = 22
                Caption = 'Show Control Bar'
                Checked = True
                State = cbChecked
                TabOrder = 2
              end
              object TxtImageSlideTime: TSpinEdit
                Left = 122
                Top = 42
                Width = 53
                Height = 27
                MaxValue = 0
                MinValue = 0
                TabOrder = 1
                Value = 5
              end
            end
            object TabTextConfig: TTabSheet
              Caption = 'Text'
              ImageIndex = 2
              object ShpFontColour: TShape
                Left = 63
                Top = 61
                Width = 64
                Height = 23
                Brush.Color = clBlack
              end
              object TLabel
                Left = 10
                Top = 10
                Width = 35
                Height = 17
                Caption = 'Name'
              end
              object TLabel
                Left = 10
                Top = 34
                Width = 23
                Height = 17
                Caption = 'Size'
              end
              object TLabel
                Left = 10
                Top = 64
                Width = 40
                Height = 17
                Caption = 'Colour'
              end
              object TLabel
                Left = 10
                Top = 94
                Width = 30
                Height = 17
                Caption = 'Style'
              end
              object lblFontName: TLabel
                Left = 63
                Top = 10
                Width = 50
                Height = 17
                Caption = 'Tahoma'
              end
              object lblFontSize: TLabel
                Left = 63
                Top = 34
                Width = 8
                Height = 17
                Caption = '8'
              end
              object lblFontStyle: TLabel
                Left = 63
                Top = 94
                Width = 4
                Height = 17
              end
              object BtnFontChange: TButton
                Left = 370
                Top = 115
                Width = 116
                Height = 33
                Caption = 'Change Font'
                TabOrder = 0
                OnClick = BtnFontChangeClick
              end
            end
          end
          object GrpPaths: TGroupBox
            Left = 11
            Top = 120
            Width = 502
            Height = 229
            Caption = 'Media Paths'
            TabOrder = 3
            object LstPaths: TListBox
              Left = 8
              Top = 27
              Width = 486
              Height = 155
              TabStop = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ItemHeight = 14
              ParentFont = False
              TabOrder = 0
            end
            object BtnAddDir: TJvImgBtn
              Left = 376
              Top = 188
              Width = 35
              Height = 33
              TabOrder = 1
              OnClick = BtnAddDirClick
              HotTrackFont.Charset = DEFAULT_CHARSET
              HotTrackFont.Color = clWindowText
              HotTrackFont.Height = -14
              HotTrackFont.Name = 'Tahoma'
              HotTrackFont.Style = []
              Images = MainFrm.ImageList1
              ImageIndex = 0
            end
            object BtnAddCompress: TJvImgBtn
              Left = 417
              Top = 188
              Width = 35
              Height = 32
              TabOrder = 2
              OnClick = BtnAddCompressClick
              HotTrackFont.Charset = DEFAULT_CHARSET
              HotTrackFont.Color = clWindowText
              HotTrackFont.Height = -14
              HotTrackFont.Name = 'Tahoma'
              HotTrackFont.Style = []
              Images = MainFrm.ImageList1
              ImageIndex = 28
            end
            object BtnDelMedia: TJvImgBtn
              Left = 458
              Top = 188
              Width = 35
              Height = 33
              TabOrder = 3
              OnClick = BtnDelMediaClick
              HotTrackFont.Charset = DEFAULT_CHARSET
              HotTrackFont.Color = clWindowText
              HotTrackFont.Height = -14
              HotTrackFont.Name = 'Tahoma'
              HotTrackFont.Style = []
              Images = MainFrm.ImageList1
              ImageIndex = 3
            end
            object ChkSearchROMdir: TCheckBox
              Left = 8
              Top = 196
              Width = 309
              Height = 22
              Hint = 
                'If enabled the directory which contains the ROM will be searched' +
                #13#10'for media.  If disabled this directory won'#39't be searched unles' +
                's it is'#13#10'configured by the user.'
              Caption = 'Include ROM directory in search'
              ParentShowHint = False
              ShowHint = True
              TabOrder = 4
            end
          end
          object ChkCloneSearch: TCheckBox
            Left = 127
            Top = 98
            Width = 376
            Height = 22
            Hint = 
              'If enabled media searchs for MAME roms will use the parent ROM (' +
              'only applicable if you scanned ROMs using the '#39'scan merged roms'#39 +
              ')'
            Caption = 'For MAME clones use Parent ROM for scan'
            ParentShowHint = False
            ShowHint = True
            TabOrder = 2
          end
          object CmbTabType: TComboBox
            Left = 124
            Top = 16
            Width = 190
            Height = 25
            Style = csDropDownList
            ItemHeight = 17
            ItemIndex = 0
            TabOrder = 0
            Text = 'Images/Slideshow'
            Items.Strings = (
              'Images/Slideshow'
              'Game info dat file'
              'Game history dat file'
              'Thumbnails'
              'System'
              'Rom Info'
              'Mame Command dat file'
              'Mame Game init file'
              'Mame Mess info file'
              'Mame Story file'
              'Mame Mess sysInfo file')
          end
          object CmbSearchMatch: TComboBox
            Left = 127
            Top = 56
            Width = 305
            Height = 25
            Style = csDropDownList
            ItemHeight = 17
            ItemIndex = 0
            TabOrder = 1
            Text = 'Filename must match ROM filename'
            Items.Strings = (
              'Filename must match ROM filename'
              'Filename must start with ROM filename'
              'Filename must include ROM filename'
              'All Files From Directory')
          end
        end
      end
      object btnDeleteDefaultTab: TJvImgBtn
        Left = 368
        Top = 9
        Width = 33
        Height = 33
        TabOrder = 3
        OnClick = btnDeleteDefaultTabClick
        HotTrackFont.Charset = DEFAULT_CHARSET
        HotTrackFont.Color = clWindowText
        HotTrackFont.Height = -14
        HotTrackFont.Name = 'Tahoma'
        HotTrackFont.Style = []
        Images = MainFrm.ImageList1
        ImageIndex = 3
      end
      object btnAddDefaultTab: TJvImgBtn
        Left = 334
        Top = 9
        Width = 33
        Height = 33
        TabOrder = 2
        OnClick = btnAddDefaultTabClick
        HotTrackFont.Charset = DEFAULT_CHARSET
        HotTrackFont.Color = clWindowText
        HotTrackFont.Height = -14
        HotTrackFont.Name = 'Tahoma'
        HotTrackFont.Style = []
        Images = MainFrm.ImageList1
        ImageIndex = 22
      end
    end
  end
  object jvBrowse: TJvBrowseForFolderDialog
    Left = 432
    Top = 8
  end
end
