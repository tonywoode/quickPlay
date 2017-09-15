unit uMediaMiscTypes;

interface

type

  //the values these variables are important, never change!
  // if any new types are added, make sure they are added to the UI in media options,
  ///and add new default tab form.
  ///
  ///  what does the above mean?
  ///  its because the addDefaultTab dialogue box is specified in the form text in both
  ///  fMediaAddDefaultTab AND fMediaPanelOptions - there's an index in the stringlist that
  ///  has to match the index numbers specified here. And its worse: I suspect it also determines
  ///  the indexes of the tabs saved in the users MediaPanelCfg.ini (they are keyed by index)
  ///  therefore to change these would require versioning and an updating function.
  //
  ///  a leser reason is that in umediapanelclasses theres a check for
  ///  if infile.IndexOf('System Info=4') = -1 then
  ///
  ///
  TJTabType = (jtabImages = 0,
               jtabMameInfo = 1,
               jtabMameHistory = 2,
               jtabThumbnail = 3,
               jtabSystem = 4,
               jtabROMInfo = 5,
               //whilst it isn't terribly sensible to create these new types that all call the
               //same imp but with different string config vars, the alternative is to rewrite a lot
               //of the way media panel options work eg: linking to files not folders and a new form
               //specifically for creating mame dat types that will let you choose the call
               jtabMameCommand = 6,
               jtabMameGameInit = 7,
               jtabMameMessInfo = 8,
               jtabMameStory = 9,
               jtabMameSysinfo = 10
               );

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
