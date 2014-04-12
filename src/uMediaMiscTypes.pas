unit uMediaMiscTypes;

interface

type

  //the values these variables are important, never change!
  // if any new types are added, make sure they are added to the UI in media options,
  ///and add new default tab form.
  TJTabType = (jtabImages = 0,
               jtabMameInfo = 1,
               jtabMameHistory = 2,
               jtabThumbnail = 3,
               jtabSystem = 4,
               jtabROMInfo = 5);

  PTabRec = ^TTabRec;
  TTabRec = packed record
    Name : String;
    DefaultType : TJTabType;
  end;

  TJSearchType = (jstExactMatch = 0,
                  jstStartsWith = 1,
                  jstInString = 2,
                  jstAllFilesInDir = 3);

  TJMediaFolderImg = (jfiQPLogo=0, jfiROMSYS=1);

  TJTabThumbNailOpt = record
    Height        : Integer;
    Width         : Integer;
    HorizontalGap : Integer;
    VerticalGap   : Integer;
    ShowCaption   : Boolean;
    CaptionOnTop  : Boolean;
  end;

  TJTabImagesOpt = record
    SlideShowEnabled : Boolean;
    SlideShowTimeout : Integer;
    ShowControlBar : Boolean;
  end;

  TJTabNavigationType = (jtnQuickplay = 0,
                         jtnWindows = 1,
                         jtnNone = 2);

implementation

end.
