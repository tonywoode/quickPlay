//------------------------------------------------------------------------
// Name:        QuickPlay
// Version:     4.0
// Author:      John Scott
// Project
// Resorector:  Sean Green
// Homepage:    http://quickplay.sf.net
// new home page :http://www.quickplayfrontend.com/
// Description: QuickPlay is a multi-emulator frontend, key features include
//              extreme ease of use
//              EmuFinder for adding your emulators quickly
//              Support for ZIP, RAR, Ace and 7z files
//              FAST - thanks to Virtual Treeview component.
//              OLE and VCL drag'n'drop.
//              Enhance MAME support
//                      Support for Mamus icon set
//                      CatVer.ini file for getting gametype
//                      MAME game renamer, and year
//              Image Panel for displaying images for ROMs
//
// License:      BSD License
//
//change log: 4.0
//added new tool.ini files and support for Butterfly100's new tools files. More to do...
//change log: 3.9.1
//9-10-10:       attempted to dive in to a language I would normaly never
//              touch. Main goal is to continue this wonderfull program.
//          LOG:
//              Changed version to 3.9.1
//              Fixed home page and forum links
//              Removed update check, the way it works is, if the downloadable
//              version is not = to the current, then suggest an upgrade.
//              Instead of greater then. I dont know how to change that...
//9-20-10       Added a check for [!] if no language as found.
//              also added the option per folder to show only [!] roms if
//                so desired
//9-22-10       Fixed gif error and scrol error
//              QP now looks for noimagefound.jpg when no image was found
//              The run rom dialog box now uses edit fields for that text that
//                tends to wrap around, in some cases MESS, making it impossible to read.
//9-23-10       Added a rom Height slide bar
//9-28-10       removed image in media panel when it says welcome.
//10-16-10      Corrected readin maminfo and mamehistory files. ( clones now work ) [ creidt to tempest, member of the QP boards ]
//7-26-12       Includes many fixes from the new comunity
//                Tools sidebar now populates with all community supplied tools on first launch -
//                  tools either launch or provide docs about their use
//4-14          Updated, cleaned up and attributed icons
//              Fixed .gif not displaying
//              Added ReactOS CMD command and improved support for Start and Explorer commands
//              Updates to Arcade functionality
//                Mame Icons now show parent icon if needed and if they can
//------------------------------------------------------------------------
unit fMain;

interface
           
uses Windows, Classes, SysUtils, Graphics, Controls, Forms,
     Dialogs, Menus, ComCtrls, StdActns, ActnList, ImgList,
     activeX, ExtCtrls, StdCtrls,  Contnrs, GraphicEX,
     VirtualTrees, uSettings, JvComponent, Messages,
     JvTrayIcon, JvDragDrop, JvAppInst, ToolWin,
     uQPDir, uRomList, uEmuList, uRom, uEmu, uJCompression,
     uToolList, uMediaPanelClasses,uMediaTabClass, uQPMiscTypes, JvComponentBase,
     fjWinFontForm, uVersionCheckThread, JvJoystick ;

type

  //TTracxkBar does not have mouse events, so make them here
  TTrackBar  = class(ComCtrls.TTrackbar)
  protected
    property OnMouseUp;
  end;

  TMainFrm = class(TJWinFontForm)
    ImageList1: TImageList;
    ActionList: TActionList;
    ActNewFol: TAction;
    ActDelFol: TAction;
    ActScan: TAction;
    StatusBar: TStatusBar;
    ActClearRoms: TAction;
    ActEmuDel: TAction;
    ActAddRom: TAction;
    RomPopUp: TPopupMenu;
    popClear: TMenuItem;
    PopAdd: TMenuItem;
    ActRunRom: TAction;
    PopRunRom: TMenuItem;
    DirPopUp: TPopupMenu;
    PopNew: TMenuItem;
    PopDel: TMenuItem;
    popScan: TMenuItem;
    N3: TMenuItem;
    ActDelRom: TAction;
    PopDelRom: TMenuItem;
    N7: TMenuItem;
    ActEmuMan: TAction;
    RunWith: TMenuItem;
    ActAddFav: TAction;
    ActOrgFav: TAction;
    ActFindRom: TAction;
    ActExplore: TAction;
    PopExplore: TMenuItem;
    N10: TMenuItem;
    ActOrphans: TAction;
    PopAddtoFav: TMenuItem;
    ActRefresh: TAction;
    temp: TMenuItem;
    PanDir: TPanel;
    RomPanel: TPanel;
    ActCatVer: TAction;
    ActZip: TAction;
    SplitMain: TSplitter;
    IconList: TImageList;
    ActSelAll: TAction;
    ActEmuFind: TAction;
    ActAbout: TAction;
    ActMameRen: TAction;
    ActExport: TAction;
    ActFolOpt: TAction;
    FolderOptions1: TMenuItem;
    ActRomProp: TAction;
    RomProperties1: TMenuItem;
    SplitImage: TSplitter;
    ActColumns: TAction;
    PopHeader: TPopupMenu;
    HideShowColumns1: TMenuItem;
    ActEFindEdit: TAction;
    ActRunDlg: TAction;
    RunRomWithDialog1: TMenuItem;
    ActFileRename: TAction;
    RenameFileonDisk1: TMenuItem;
    ActHelpContents: TAction;
    PanRomTop: TPanel;
    TxtFilter: TEdit;
    lblFilter: TLabel;
    ActAddIPS: TAction;
    AddIPS1: TMenuItem;
    IPSMenu: TMenuItem;
    ActMirror: TAction;
    N2: TMenuItem;
    VTRoms: TVirtualStringTree;
    ROMicons: TImageList;
    ActRBarVisible: TAction;
    ActPref: TAction;
    MainMenu: TMainMenu;
    ActExit: TFileExit;
    File1: TMenuItem;
    Exit1: TMenuItem;
    N1: TMenuItem;
    NewFolder1: TMenuItem;
    DeleteFolder1: TMenuItem;
    View1: TMenuItem;
    N4: TMenuItem;
    HideShowColumns2: TMenuItem;
    N5: TMenuItem;
    Refresh1: TMenuItem;
    SelectAll1: TMenuItem;
    MnuFav: TMenuItem;
    AddToTop101: TMenuItem;
    OrganiseTop101: TMenuItem;
    N6: TMenuItem;
    Emulators1: TMenuItem;
    EmulatorList1: TMenuItem;
    N8: TMenuItem;
    ClearEmulators1: TMenuItem;
    N9: TMenuItem;
    LaunchEmuFinder1: TMenuItem;
    EditEmuFinderDataFiles1: TMenuItem;
    Roms1: TMenuItem;
    Mame1: TMenuItem;
    Help1: TMenuItem;
    RunROM1: TMenuItem;
    RunROMWithDialog2: TMenuItem;
    N11: TMenuItem;
    AddaROM1: TMenuItem;
    ScanForROMS1: TMenuItem;
    RescanMirroredDirectory1: TMenuItem;
    AddIPS2: TMenuItem;
    N12: TMenuItem;
    DeleteROM1: TMenuItem;
    ClearROMlist1: TMenuItem;
    N13: TMenuItem;
    ExploreROMDirectory1: TMenuItem;
    N14: TMenuItem;
    FindROM1: TMenuItem;
    RemoveOrphanedFiles1: TMenuItem;
    ZipUtilities1: TMenuItem;
    ProcessCurrentDirwithcatveriniMAMEOnly1: TMenuItem;
    RenameMameROMS1: TMenuItem;
    Tools1: TMenuItem;
    Preferences1: TMenuItem;
    HelpContents1: TMenuItem;
    About1: TMenuItem;
    TBRoms: TToolBar;
    ToolButton6: TToolButton;
    ToolButton7: TToolButton;
    ToolButton8: TToolButton;
    ToolButton9: TToolButton;
    ToolButton10: TToolButton;
    ToolButton11: TToolButton;
    ToolButton12: TToolButton;
    ToolButton13: TToolButton;
    ShowHideRomToolbar1: TMenuItem;
    ActDBarVisible: TAction;
    ShowHideDirectoryToolbar1: TMenuItem;
    PanFilter: TPanel;
    ActFilterVisible: TAction;
    ShowHideROMFilter1: TMenuItem;
    ACtHomePage: TAction;
    GotoEmulatorHomePage1: TMenuItem;
    N16: TMenuItem;
    GotoEmulatorHomePage2: TMenuItem;
    ActImgVisible: TAction;
    ShowImagePanel2: TMenuItem;
    ActMultiScan: TAction;
    MultiDirectoryScan1: TMenuItem;
    N15: TMenuItem;
    ExporttoHTML1: TMenuItem;
    ActMergedScan: TAction;
    ScanMergedROMs1: TMenuItem;
    RumRandomROM1: TMenuItem;
    ActRandomFolder: TAction;
    ActRandomAll: TAction;
    FromThisFolder1: TMenuItem;
    FromAllROMs1: TMenuItem;
    N17: TMenuItem;
    ToolButton14: TToolButton;
    ToolButton15: TToolButton;
    ToolButton16: TToolButton;
    ActResetConfig: TAction;
    ResetConfiguration1: TMenuItem;
    ActMigrate: TAction;
    DriveFolderMigrationWizard1: TMenuItem;
    EmuFolders: TImageList;
    jvTray: TJvTrayIcon;
    ActBackupRestore: TAction;
    BackupRestoreConfiguration1: TMenuItem;
    jvDropROM: TJvDropTarget;
    jvAppInst: TJvAppInstances;
    ActCustomData: TAction;
    N19: TMenuItem;
    ActNPlayers: TAction;
    ProcessNPlayersiniMAMEonly1: TMenuItem;
    ActOpenCatver: TAction;
    ActOpenNPlayers: TAction;
    GotoCatverhomepage1: TMenuItem;
    GotoNPlayersHomepage1: TMenuItem;
    N20: TMenuItem;
    N21: TMenuItem;
    ImportExportCustomROMData2: TMenuItem;
    N22: TMenuItem;
    pgSideBar: TPageControl;
    TabROMS: TTabSheet;
    TabEmus: TTabSheet;
    VTdir: TVirtualStringTree;
    TBDir: TToolBar;
    ToolButton1: TToolButton;
    ToolButton2: TToolButton;
    ToolButton3: TToolButton;
    ToolButton5: TToolButton;
    ToolButton4: TToolButton;
    VTEmus: TVirtualStringTree;
    PanEmuChk: TPanel;
    ChkEmuBySys: TCheckBox;
    CmbFilterOn: TComboBox;
    PanContent: TPanel;
    ActROMfromIPS: TAction;
    CreatenewROMusingIPSfile1: TMenuItem;
    PopupVirtual: TPopupMenu;
    actEditVirtualFolder: TAction;
    EditVirtualFolderQuery1: TMenuItem;
    TabTools: TTabSheet;
    ToolBarTools: TToolBar;
    ActUtilityNew: TAction;
    ActUtilityDelete: TAction;
    ActUtilityEdit: TAction;
    ToolButton17: TToolButton;
    ToolButton18: TToolButton;
    ToolButton19: TToolButton;
    vtTools: TVirtualStringTree;
    PopupEmu: TPopupMenu;
    Run1: TMenuItem;
    actHomePageEmuTree: TAction;
    OpenHomepage1: TMenuItem;
    PopupTools: TPopupMenu;
    Run2: TMenuItem;
    OpenHomepage2: TMenuItem;
    ActUtilityWWW: TAction;
    SendTo1: TMenuItem;
    N18: TMenuItem;
    ViewROMs1: TMenuItem;
    MnuROMsidebar: TMenuItem;
    MnuEmuSideBar: TMenuItem;
    MnuToolSidebar: TMenuItem;
    ActZiNcScan: TAction;
    N23: TMenuItem;
    ScanforZiNcROMs1: TMenuItem;
    actQPHomepage: TAction;
	actQPOriginalHomepage: TAction;
    actQPForums: TAction;
    N24: TMenuItem;
    QuickPlayHomepage1: TMenuItem;
    QuickPlayForums1: TMenuItem;
    N25: TMenuItem;
    actMediaOptions: TAction;
    actAppearanceOptions: TAction;
    N26: TMenuItem;
    AppearanceOptions1: TMenuItem;
    MediaPanelOptions1: TMenuItem;
    TabSearches: TTabSheet;
    MnuSearchSideBar: TMenuItem;
    ROMPopupMini: TPopupMenu;
    AddaROM2: TMenuItem;
    ScanForROMS2: TMenuItem;
    N27: TMenuItem;
    ClearROMList2: TMenuItem;
    RescanMirroredDirectory2: TMenuItem;
    ToolBar1: TToolBar;
    ToolButton20: TToolButton;
    VTSearches: TVirtualStringTree;
    actDeleteSearch: TAction;
    ToolButton21: TToolButton;
    actEditCfgEmuTree: TAction;
    EditEmulatorConfigurationfile1: TMenuItem;
    pgMediaPanel: TPageControl;
    CmbFilterFolder: TComboBox;
    TimerAutoMove: TTimer;
    MnuROMRating: TMenuItem;
    ROMGMPopup: TPopupMenu;
    MnuGMSetDefault: TMenuItem;
    actRandomFolderNeverPlayed: TAction;
    actRandomAllNeverPlayed: TAction;
    RunRandomROMthatsneverbeenplayed1: TMenuItem;
    Fromthisfolder2: TMenuItem;
    Fromanyfolder1: TMenuItem;
    actCheckForUpdates: TAction;
    QuickPlayOriginalHomepage: TMenuItem;
    SlideBar : TTrackBar;
    Label1: TLabel;
    JoyCntrl: TJvJoystick;
    Edit1: TEdit;
    SlideBarDir: TTrackBar;
    procedure Label1Click(Sender: TObject);
    procedure vtToolsChange(Sender: TBaseVirtualTree; Node: PVirtualNode);
    procedure pgSideBarChange(Sender: TObject);
    procedure Help1Click(Sender: TObject);
    procedure JoyCntrlJoyMove(Sender: TObject; X, Y: Integer; But1Pressed,
      But2Pressed, But3Pressed, But4Pressed: Boolean);
    procedure JoyCntrlJoyButtonDown(Sender: TObject; X, Y,
      ButtonChanged: Integer; But1Pressed, But2Pressed, But3Pressed,
      But4Pressed: Boolean);

    procedure SlideBarMouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure SlideBarDirMouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure SlideBarChange(Sender: TObject);
    procedure SlideBarDirChange(Sender: TObject);
    procedure VTRomsHeaderClick(Sender: TVTHeader; HitInfo: TVTHeaderHitInfo );
    procedure actCheckForUpdatesExecute(Sender: TObject);
    procedure actRandomAllNeverPlayedExecute(Sender: TObject);
    procedure actRandomFolderNeverPlayedExecute(Sender: TObject);
    procedure VTdirChange(Sender: TBaseVirtualTree; Node: PVirtualNode);
    procedure MnuGMSetDefaultClick(Sender: TObject);
    procedure TimerAutoMoveTimer(Sender: TObject);
    procedure actEditCfgEmuTreeExecute(Sender: TObject);
    procedure actDeleteSearchExecute(Sender: TObject);
    procedure VTSearchesNewText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; NewText: WideString);
    procedure VTSearchesEditing(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; var Allowed: Boolean);
    procedure VTSearchesExit(Sender: TObject);
    procedure VTSearchesGetPopupMenu(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex; const P: TPoint;
      var AskParent: Boolean; var PopupMenu: TPopupMenu);
    procedure VTSearchesFocusChanging(Sender: TBaseVirtualTree; OldNode,
      NewNode: PVirtualNode; OldColumn, NewColumn: TColumnIndex;
      var Allowed: Boolean);
    procedure VTSearchesGetImageIndex(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
      var Ghosted: Boolean; var ImageIndex: Integer);
    procedure VTSearchesGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType; var CellText: WideString);
    procedure MnuSearchSideBarClick(Sender: TObject);
    procedure actMediaOptionsExecute(Sender: TObject);
    procedure actAppearanceOptionsExecute(Sender: TObject);
    procedure actQPHomepageExecute(Sender: TObject);
    procedure actQPOriginalHomepageExecute(Sender: TObject);
    procedure actQPForumsExecute(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure ActClearRomsExecute(Sender: TObject);
    procedure ActEmuDelExecute(Sender: TObject);
    procedure ActDelFolExecute(Sender: TObject);
    procedure ActNewFolExecute(Sender: TObject);
    procedure ActAddRomExecute(Sender: TObject);
    procedure ActRunRomExecute(Sender: TObject);
    procedure ActDelRomExecute(Sender: TObject);
    procedure ActEmuManExecute(Sender: TObject);
    procedure ActScanExecute(Sender: TObject);
    procedure ActionListUpdate(Action: TBasicAction; var Handled: Boolean);
    procedure ActFindRomExecute(Sender: TObject);
    procedure ActExploreExecute(Sender: TObject);
    procedure ActOrphansExecute(Sender: TObject);
    procedure FavClick(Sender : TObject);
    procedure RomPopUpPopup(Sender: TObject);
    procedure RunWithClick(Sender: TObject);
    procedure ActOrgFavExecute(Sender: TObject);
    procedure ActAddFavExecute(Sender: TObject);
    procedure ActRefreshExecute(Sender: TObject);
    procedure ActCatVerExecute(Sender: TObject);
    procedure ActZipExecute(Sender: TObject);
    procedure ActPrefExecute(Sender: TObject);
    procedure ActSelAllExecute(Sender: TObject);
    procedure ActEmuFindExecute(Sender: TObject);
    procedure ActAboutExecute(Sender: TObject);
    procedure ActMameRenExecute(Sender: TObject);
    procedure ActExportExecute(Sender: TObject);
    procedure ActFolOptExecute(Sender: TObject);
    procedure VTRomsGetImageIndex(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
      var Ghosted: Boolean; var ImageIndex: Integer);
    procedure VTRomsGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure ActRomPropExecute(Sender: TObject);
    procedure ActColumnsExecute(Sender: TObject);
    procedure ActEFindEditExecute(Sender: TObject);
    procedure ActRunDlgExecute(Sender: TObject);
    procedure ActFileRenameExecute(Sender: TObject);
    procedure ActHelpContentsExecute(Sender: TObject);
    procedure TxtFilterKeyUp(Sender: TObject; var Key: Word;
      Shift: TShiftState);
    procedure ActAddIPSExecute(Sender: TObject);
    procedure ActMirrorExecute(Sender: TObject);
    procedure IPSMenuClick(Sender: TObject);
    procedure VTRomsIncrementalSearch(Sender: TBaseVirtualTree;
      Node: PVirtualNode; const SearchText: WideString;
      var Result: Integer);
    procedure VTRomsGetHint(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; var LineBreakStyle: TVTTooltipLineBreakStyle; var HintText: WideString);
    procedure VTdirInitNode(Sender: TBaseVirtualTree; ParentNode,
      Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
    procedure VTdirInitChildren(Sender: TBaseVirtualTree;
      Node: PVirtualNode; var ChildCount: Cardinal);
    procedure VTdirGetImageIndex(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
      var Ghosted: Boolean; var ImageIndex: Integer);
    procedure VTdirGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure VTdirGetHint(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; var LineBreakStyle: TVTTooltipLineBreakStyle; var HintText: WideString);
    procedure VTdirGetPopupMenu(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex; const P: TPoint;
      var AskParent: Boolean; var PopupMenu: TPopupMenu);
    procedure VTRomsCompareNodes(Sender: TBaseVirtualTree; Node1,
      Node2: PVirtualNode; Column: TColumnIndex; var Result: Integer);
    procedure ActRBarVisibleExecute(Sender: TObject);
    procedure ActDBarVisibleExecute(Sender: TObject);
    procedure ActFilterVisibleExecute(Sender: TObject);
    procedure ACtHomePageExecute(Sender: TObject);
    procedure ActImgVisibleExecute(Sender: TObject);
    procedure VTdirDragDrop(Sender: TBaseVirtualTree; Source: TObject;
      DataObject: IDataObject; Formats: TFormatArray; Shift: TShiftState;
      Pt: TPoint; var Effect: Integer; Mode: TDropMode);
    procedure VTdirDragOver(Sender: TBaseVirtualTree; Source: TObject;
      Shift: TShiftState; State: TDragState; Pt: TPoint; Mode: TDropMode;
      var Effect: Integer; var Accept: Boolean);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure VTRomsChange(Sender: TBaseVirtualTree; Node: PVirtualNode);
    procedure ActMultiScanExecute(Sender: TObject);
    procedure VTdirEditing(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; var Allowed: Boolean);
    procedure VTdirNewText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; NewText: WideString);
    procedure VTRomsKeyDown(Sender: TObject; var Key: Word;
      Shift: TShiftState);
    procedure VTdirKeyDown(Sender: TObject; var Key: Word;
      Shift: TShiftState);
    procedure VTRomsEditing(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; var Allowed: Boolean);
    procedure VTRomsNewText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; NewText: WideString);
    procedure VTRomsCreateEditor(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex; out EditLink: IVTEditLink);
    procedure ActMergedScanExecute(Sender: TObject);
    procedure ActRandomFolderExecute(Sender: TObject);
    procedure ActRandomAllExecute(Sender: TObject);
    procedure ActResetConfigExecute(Sender: TObject);
    procedure ActMigrateExecute(Sender: TObject);
    procedure VTdirCompareNodes(Sender: TBaseVirtualTree; Node1,
      Node2: PVirtualNode; Column: TColumnIndex; var Result: Integer);
    procedure ActBackupRestoreExecute(Sender: TObject);
    procedure jvDropROMDragDrop(Sender: TJvDropTarget;
      var Effect: TJvDropEffect; Shift: TShiftState; X, Y: Integer);
    procedure jvDropROMDragAccept(Sender: TJvDropTarget;
      var Accept: Boolean);
    procedure VTRomsFreeNode(Sender: TBaseVirtualTree; Node: PVirtualNode);
    procedure VTdirFreeNode(Sender: TBaseVirtualTree; Node: PVirtualNode);
    procedure ActCustomDataExecute(Sender: TObject);
    procedure ActNPlayersExecute(Sender: TObject);
    procedure VTRomsExit(Sender: TObject);
    procedure VTdirExit(Sender: TObject);
    procedure ActOpenCatverExecute(Sender: TObject);
    procedure ActOpenNPlayersExecute(Sender: TObject);
    procedure VTEmusInitNode(Sender: TBaseVirtualTree; ParentNode,
      Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
    procedure VTEmusGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure ChkEmuBySysClick(Sender: TObject);
    procedure VTEmusInitChildren(Sender: TBaseVirtualTree;
      Node: PVirtualNode; var ChildCount: Cardinal);
    procedure VTEmusGetImageIndex(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
      var Ghosted: Boolean; var ImageIndex: Integer);
    procedure VTEmusDblClick(Sender: TObject);
    procedure VTEmusCompareNodes(Sender: TBaseVirtualTree; Node1,
      Node2: PVirtualNode; Column: TColumnIndex; var Result: Integer);
    procedure actEditVirtualFolderExecute(Sender: TObject);
    procedure ActROMfromIPSExecute(Sender: TObject);
    procedure VTEmusFocusChanging(Sender: TBaseVirtualTree; OldNode,
      NewNode: PVirtualNode; OldColumn, NewColumn: TColumnIndex;
      var Allowed: Boolean);
    procedure VTRomsInitChildren(Sender: TBaseVirtualTree;
      Node: PVirtualNode; var ChildCount: Cardinal);
    procedure VTRomsMouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure VTRomsGetPopupMenu(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex; const P: TPoint;
      var AskParent: Boolean; var PopupMenu: TPopupMenu);
    procedure actHomePageEmuTreeExecute(Sender: TObject);
    procedure VTEmusGetPopupMenu(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex; const P: TPoint;
      var AskParent: Boolean; var PopupMenu: TPopupMenu);
    procedure vtToolsCompareNodes(Sender: TBaseVirtualTree; Node1,
      Node2: PVirtualNode; Column: TColumnIndex; var Result: Integer);
    procedure vtToolsMouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure vtToolsDblClick(Sender: TObject);
    procedure vtToolsGetImageIndex(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
      var Ghosted: Boolean; var ImageIndex: Integer);
    procedure vtToolsGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure ActUtilityDeleteExecute(Sender: TObject);
    procedure ActUtilityNewExecute(Sender: TObject);
    procedure ActUtilityEditExecute(Sender: TObject);
    procedure ActUtilityWWWExecute(Sender: TObject);
    procedure vtToolsGetPopupMenu(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex; const P: TPoint;
      var AskParent: Boolean; var PopupMenu: TPopupMenu);
    procedure FormShow(Sender: TObject);
    procedure MnuROMsidebarClick(Sender: TObject);
    procedure MnuEmuSideBarClick(Sender: TObject);
    procedure MnuToolSidebarClick(Sender: TObject);
    procedure ActZiNcScanExecute(Sender: TObject);


  private
    _ROMPoint : TPoint;
    _ToolPt : TPoint;
    _FontSize : Integer;

    _ShowUpdateCheckErrors : Boolean;

    //goodmerge variables
    _GoodMergeCompat : Boolean;
	  _GoodMergeEXCL : Boolean;
    _GMpref1 : String;
    _GMPref2 : String;
    _GMPref3 : String;
    _FakeOnCreate : Boolean; //hackish variable to make the OnShow fake the OnCreate.. hack mode to full.
    _KeyPress : Boolean; //hack for keeping track of a keypress.

    //Media Search Object
    _MediaSearch : TJMediaSearch;

    FFiltered : Integer;
    FFilterString : String;
    FFilterByStart : Boolean;
    FDirHeight : Integer;
    DirList : TObjectList;
    SearchList : TStringList;
    OldWindowState : TWindowState;
    SystemList : TObjectList;
    _WindowLayout : Integer;

    //Variables for using Real MAME icons support.
    _MAMEIconsPath : String;
    _MAMEIconsMode : TQPMAMEIconMode;
    _MAMEIconsList : TStringList;

    procedure ChangeLayout();
    procedure ClearAllDynMenus();
    procedure DisableMAMEIcons();
    Procedure DynRating(Sender : TObject);
    procedure DynRunwith(sender : TObject);
    Procedure DynSendTo(Sender : TObject);
    procedure FilterRoms();
    procedure GetROMToRun(var RomObj : TQPROM; TheNode : PVirtualNode);
    Procedure InitTree();
    Procedure InitEmuTree();
    procedure InitSearchTree();
    Procedure InitToolTree();
    Function InitialiseDirectory(CurFol : TQPDir; Node : PVirtualNode) : Integer;
    procedure PopmenuBuild();
    procedure PopmenuIPS();
    procedure RefreshAll();
    Procedure RunIPSGame(Sender : TObject);
    procedure SetupROMSFolder(NewFol : TQPDir; NewNode : PVirtualNode);
    procedure SetupSearchFolder(NewNode : PVirtualNode);
    function TreeImages(inifile:String) : Integer ;

    //Property Codes
    function SelectedFolder:string;
    function SelectedQPDir() : TQPDir;
    function SelectedTxtFile():String;
    function GetSplitDirVert: Integer;
    function GetSplitDirHorz: Integer;
    procedure SetSplitDirVert(const Value: Integer);
    procedure SetSplitDirHorz(const Value: Integer);
    function GetSplitImgVert: Integer;
    function GetSplitImgHorz: Integer;
    procedure SetSplitImgVert(const Value: Integer);
    procedure SetSplitImgHorz(const Value: Integer);
    procedure SetROMStatusText(value : String);
    procedure SetCompressStatusText(value : String);

    //message handling
    procedure HandleNewUpdateMsg(var Message: TMessage); message WM_UPDATE_AVAILABLE;
    procedure HandleErrUpdateMsg(var Message: TMessage); message WM_UPDATE_ERROR;
    procedure HandleNoUpdateMsg(var Message: TMessage); message WM_NO_UPDATE;

  public
    Settings : TQPSettings;
    FavList : TQPRomList;
    RomList : TQPRomList;
    EmuList : TQPEmuList;
    ToolList : TQPToolList;

    Function GetROM(cNode : PVirtualNode) : TQPRom;
    Function GetNextROM() : TQPRom;
    Function GetPreviousROM() : TQPRom;

    Property GetSelectedFolder : string read SelectedFolder;
    Property GetSelectedTxt : string read SelectedTxtFile;
    Property GetSelectedQPDir : TQPDir read SelectedQPDir;
    Property MediaSearchObj : TJMediaSearch read _MediaSearch write _MediaSearch;
    Property SplitImgHorz : Integer read GetSplitImgHorz write SetSplitImgHorz;
    Property SplitDirHorz : Integer read GetSplitDirHorz write SetSplitDirHorz;
    Property SplitDirVert : Integer Read GetSplitDirVert write SetSplitDirVert;
    Property SplitImgVert : Integer Read GetSplitImgVert write SetSplitImgVert;
    Property WindowLayout : Integer read _WindowLayout write _WindowLayout;
    Property ROMStatusBar : String write SetROMStatusText;
    Property CompressStatusBar : String write SetCompressStatusText;

    procedure BuildFavMenu();
    procedure ClearROMIcons();
    procedure fillroms(FiletoLoad : TFileName);
    Function  JumpToROM(Dir, ROM : String; SType : TQPRefresh) : Boolean;
    Procedure MinimiseQP();
    Procedure RestoreQP();
    Procedure RunROM(var aRom : TQPRom; aEmu : TQPEmu);
    Procedure SetVTWallpapers();
    procedure SetROMHeight(Minimum : Integer);
    procedure SetDIRHeight( Size : Integer);

  protected
     property OnMouseUp;

  end;

const
  QPVer = '4.0.0';
  DefaultFileName = 'ROMData.dat';
  LBreak = Chr(13) + Chr(10);

  qpwNormal = 0;
  qpwVertical = 1;
  qpwDirOnTop = 2;
  qpwImgToBottom = 3;

var
  MainFrm: TMainFrm;

implementation

uses StrUtils, FindFile, ShellAPI, IniFiles,
     JCLstrings, JCLFileUtils,
     uJVirtualTree, uJFile, uJUtilities, ujWindowsMisc,

     fScan, fAddaRom, fMameRename, fMameHolding, fFind, fFav, fOptions, fEmuFind,
     fExport, fZip, fAbout, fFolderOpt, fRomProperties,
     fColumns, fEditEmuFind, fRunDlg, fEmulators, fIPS, fScanRecursive,
     fMameMerge, fWelcome, fMigrate, fBackup,
     uRomUtils, uEmuUtils, fCustomRomData, uQPVTEditor, uQuery,
     uQPConst, uExe, fTools, uTools, fMediaPanelOptions, fAppearanceOptions,
     fTxtEditor, uMediaMiscTypes, uQPCompObj, ujMiscResourceStrs;

{$R *.DFM}

{$R ZipMsgUS.res}
{$R defaults.res}
{$WARN SYMBOL_PLATFORM OFF}
{$I Compilers.inc}

{-----------------------------------------------------------------------------}
{------------------------------ Private Routines -----------------------------}
{-----------------------------------------------------------------------------}

procedure TMainFrm.ChangeLayout();
begin

  case _WindowLayout of
    qpwNormal :   begin
                    PanDir.Align := alLeft;
                    SplitMain.Align := alLeft;
                    SplitMain.Left := PanDir.Width + 1;
                    pgMediaPanel.Align := alRight;
                    SplitImage.Align := alRight;
                  end;
    qpwVertical : begin
                    PanDir.Align := alTop;
                    splitMain.Align := alTop;
                    pgMediaPanel.Align := alBottom;
                    SplitImage.Align := alBottom;
                  end;
    qpwDirOnTop : begin
                    PanDir.Align := alTop;
                    splitMain.Align := alTop;
                    pgMediaPanel.Align := alRight;
                    SplitImage.Align := alRight;
                  end;
    qpwImgToBottom :  begin
                        pgMediaPanel.Align := alBottom;
                        SplitImage.Align := alBottom;
                        PanDir.Align := alLeft;
                        SplitMain.Align := alLeft;
                        SplitMain.Left := PanDir.Width + 1;
                      end;
  end; //end of CASE

  //now load in the new dimensions
  Settings.LoadDimensions(_WindowLayout);
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ClearAllDynMenus();
Begin 
  RunWith.Clear;
  IPSMenu.Clear;
  MnuFav.Clear;
End;

{-----------------------------------------------------------------------------}

procedure TMainFrm.DisableMAMEIcons();
begin
  _MAMEIconsMode := qmiOff;
  _MAMEIconsPath := '';
  FreeAndNil(_MAMEIconsList);
end;

{-----------------------------------------------------------------------------}

Procedure TMainFrm.DynRating(Sender : TObject);
var
  Tmp : TmenuItem;
  ROM : TQPROM;
begin
  Tmp := sender as TMenuItem;
  if (VTRoms.SelectedCount = 1) and (GetObject(VTROMs, VTROMS.FocusedNode) <> nil) then
  begin
    ROM := TQPROM(GetObject(VTROMs, VTROMS.FocusedNode));
    ROM.Rating := Tmp.Caption;
    ROMList.SaveToFile();
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.DynRunwith(sender : TObject);
var
  RDialog : TFrmRunRom;
  Tmp : TmenuItem;
  tmpRom : TQPROM;
begin

  Tmp := sender as TMenuItem;

  if VTRoms.SelectedCount = 1 then
  begin

    TmpROM := TQPROM.Create;
    try
      Self.GetROMToRun(TmpROM, VTROMS.FocusedNode);

      If Settings.UseRunDLG then
      Begin
        Rdialog := TFrmRunRom.Create(self);
        Try
          RDialog.Rom := TmpROM;
          RDialog.Emu := EmuList[Tmp.Tag];

          RDialog.ShowModal;

        finally
          FreeAndNil(RDialog);
        end;
      end
      Else
        RunROM(tmpRom, EmuList[Tmp.Tag]);

    finally
      FreeAndNil(TmpROM);
    end;

  end;
end;

{-----------------------------------------------------------------------------}

Procedure TMainFrm.DynSendTo(Sender : TObject);
var
  Tmp : TmenuItem;
  ExtrDir : String;
  ROM : TQPROM;
begin
  Tmp := sender as TMenuItem;
  if (VTRoms.SelectedCount = 1) and (GetObject(VTROMs, VTROMS.FocusedNode) <> nil) then
  begin
    ROM := TQPROM(GetObject(VTROMs, VTROMS.FocusedNode));

    if Settings.RunOptions.ExtractMode <> qemROMDir then
      ExtrDir := Settings.ExtractModeToPath(Settings.RunOptions.ExtractMode)
    else
      ExtrDir := ExtractFilePath(ROM.Path);
      
    ToolList[Tmp.Tag].Run(ROM, nil, ExtrDir);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.FilterRoms();
var
  aNode : PVirtualNode;
  Data : TQPRom;
  PosResult : Integer;
Begin
  //firstly reset all the variables.
  FFiltered := 0;

  VTRoms.BeginUpdate;

  //check if this is per folder/ or all folders mode.
  if CmbFilterFolder.ItemIndex = 0 then
  begin

    //filter by folder.

    //first thing to do is check if a filter string has been provided
    If FFilterString = '' then
    begin

      //no filter string provided, set all ROMs to be visible.
      aNode := VTRoms.GetFirst;
      While aNode <> nil do
      begin
        VTRoms.IsVisible[aNode] := True;
        aNode := VTroms.GetNextSibling(aNode);
      end;
    
    end
    else
    begin

      //there is a filter string, we need to filter ROMs.
      aNode := VTRoms.GetFirst;
      While aNode <> nil do
      begin
        data := TQPRom(GetObject(VTRoms, aNode));
        PosResult := 0;
        case CmbFilterOn.ItemIndex of
          0 : PosResult := JCLStrings.StrIPos(FFilterString, data.name);
          1 : PosResult := JCLStrings.StrIPos(FFilterString, data.Path);
          2 : PosResult := JCLStrings.StrIPos(FFilterString, data.GameType);
          3 : PosResult := JCLStrings.StrIPos(FFilterString, data.Emulator);
          4 : PosResult := JCLStrings.StrIPos(FFilterString, data.Multiplayer);
          5 : PosResult := JCLStrings.StrIPos(FFilterString, data.Company);
          6 : PosResult := JCLStrings.StrIPos(FFilterString, data.Year);
          7 : PosResult := JCLStrings.StrIPos(FFilterString, data.Rating);
        end;

        // if the ROM name contains the filter string, make sure its visible.
        if PosResult = 0 then
        begin
          Inc(FFiltered);
          VTRoms.IsVisible[aNode] := False;
        end
        else
        Begin
          VTRoms.IsVisible[aNode] := True;
        end;

        aNode := VTROMS.GetNextSibling(aNode);
      end;

    end;

  end; //end of filter in folder.

  VTRoms.EndUpdate;

End;

{-----------------------------------------------------------------------------}

procedure TMainFrm.GetROMToRun(var RomObj : TQPROM; TheNode : PVirtualNode);
var
  ParentROM : TQPROM;
begin
    //determine the selected ROM
    if VTROMs.GetNodeLevel(TheNode) =0 then
    begin
      //ok check if we are in goodmerge compatibility mode
      //if we are we need to search inside the archive for the ROM which matches users criteria.
      if _GoodMergeCompat then
      begin
        ParentROM := TQPRom(GetObject(VTRoms, TheNode));
        ParentROM.NumPlay := ParentROM.NumPlay + 1;
        RomObj.Assign(ParentROM);
        try

          //IF the rom is a compressed rom try to find the users choice.
          // if its not even compressed with a format we understand, well just try running it..
          if uQPCompObj.Compression.SupportsFileName(RomObj.path, cmRead) then
            RomObj.GuessGoodMerge(_GMpref1, _GMPref2, _GMPref3);
        except 
          on e: EJException do
          begin
            MessageDlg(e.Message, mtError, [mbOK], 0);
            exit;
          end;
        end;

      end  
      else
      begin
        //just a normal run rom operation

        //update the run count.
        TQPRom(GetObject(VTRoms, TheNode)).NumPlay := TQPRom(GetObject(VTRoms, TheNode)).NumPlay + 1;
        RomObj.Assign(TQPRom(GetObject(VTRoms, TheNode)));
      end;
    end
    else
    begin
      //this is a child node which means we are in GoodMerge compat mode.  Create a 'zipname' ROM..
      ParentROM := TQPRom(GetObject(VTRoms, VTROMs.NodeParent[TheNode]));

      //this probably isnt the best place to update this, but I have no idea where else to do it!
      ParentROM.NumPlay := ParentROM.NumPlay + 1;
      
      RomObj.Assign(ParentROM);
      RomObj.ZipName := ParentROM.CompressedFiles[TheNode.Index];
    end;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.InitEmuTree();
var
  TempSys : TStringList;
  i : Integer;
  NewSys : TQPSystem;
  NewIndex : Integer;
begin
  VTEmus.Clear;
  SystemList.Clear;
  VTEmus.StateImages := EmuList.ExeIcons;

  if ChkEmuBySys.Checked then
  begin
    //we want the emulators sorted by system
    VTEmus.DefaultNodeHeight := 18;
    TempSys := TStringList.Create;
    try
      TempSys.LoadFromFile(MainFrm.Settings.Paths.CfgDir + 'systems.dat');
   
      for i := 0 to TempSys.Count-1 do
      Begin
        NewIndex := SystemList.Add(TQPSystem.Create);
        NewSys := TQPSystem(SystemList.items[NewIndex]);

        NewSys.Name := TempSys.Strings[i];
        NewSys.TotalEmus := 0;
      End;

    Finally
      FreeAndNil(TempSys);
    end;

    VTEmus.RootNodeCount := SystemList.Count;

  end
  else
  begin
    //we want a flat listing of all emulators.
    SystemList.Clear;
    VTEmus.DefaultNodeHeight := 24;
    VTEmus.RootNodeCount := EmuList.Count;
  end;
end;

{-----------------------------------------------------------------------------}

Procedure TMainFrm.InitToolTree();
var
  aNode : PVirtualNode;
begin
  vtTools.Clear;
  vtTools.Images := ToolList.ExeIcons;
  vtTools.BeginUpdate;
  try
    vtTools.RootNodeCount := ToolList.Count;
    aNode := VTTools.GetFirst;
    while aNode <> nil do
    begin
      SetObject(VTTools, aNode, ToolList[aNode.index]);
      aNode := VTTools.GetNextSibling(aNode);
    end;
  finally
    VTTools.EndUpdate;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.InitSearchTree();
var
  SR: TSearchRec;
begin

  SearchList.Clear;
  VTSearches.Clear;
  VTSearches.DefaultNodeHeight := uJUtilities.GetFontTextHeight(VTSearches.Font);

  if FindFirst(Settings.Paths.SearchDir + '*.qpq', faAnyFile	, SR) = 0 then
  begin
    try
      //begin iteration of all files found in the directory
      repeat
        if (SR.Name <> '.') and (SR.Name <> '..') then
        begin
          //if the file found is not a directory we can add it.
          SearchList.Values[ChangeFileExt(ExtractFileName(SR.Name), '')] := Settings.Paths.SearchDir + SR.Name;
        end;
      //repeat until no more results are found.
      until FindNext(SR) <> 0;

    finally
      //remember to free the memory of the file search.
      FindClose(SR);
    end;
  end;

  SearchList.Sort;
  VTSearches.RootNodeCount := SearchList.Count;

end;

{-----------------------------------------------------------------------------}

Procedure TMainFrm.InitTree();
var
  i : Integer;
  SR: TSearchRec;
Begin

  VTDir.Clear;
  VTDir.RootNodeCount := 0;
  
  //now we clear our objectlist
  DirList.Clear;

  //we also need to clear the directory listing icon list
  //well we need to leave the original 4 intact!
  if IconList.Count > 4 then
    For i:= IconList.Count-1 downto 4 do
      IconList.Delete(i);

  //calculate the height of the nodes.
  FDirHeight := uJUtilities.GetFontTextHeight(VTDir.Font) ;

  //only show whatever is in the ROMS folder.
  if FindFirst(IncludeTrailingPathDelimiter(Settings.Paths.ROMsDir) + '*.*', faDirectory, SR) = 0 then
  begin
    try
      //begin iteration of all files found in the directory
      repeat
        if (SR.Name <> '.') and (SR.Name <> '..') then
        begin
          //if the file found is indeed a directory we can add it.
          if (SR.Attr and faDirectory <> 0) then
          begin
            DirList.Add(TQPDir.Create(SR.Name, IncludeTrailingPathDelimiter(Settings.Paths.ROMsDir + SR.Name), false, 0, 1));
          end;
        end;
      until FindNext(SR) <> 0;
    finally
      //remember to free the memory of the file search.
      FindClose(SR);
    end;
  end;//end IF FindFirst()


  VTDir.BeginUpdate;
  try
    //Set up the treeview with the available directories.
    VTdir.RootNodeCount := DirList.Count;
    //VTDir.ValidateNode(VTDir.GetFirst, true);
    //bug fix: 	0000045 - Directory not updating scrollbars.
    VTDir.ValidateNode(nil, true);
  finally
    VTDir.EndUpdate;
  end;

End;

{-----------------------------------------------------------------------------}

Function TMainFrm.InitialiseDirectory(CurFol : TQPDir; Node : PVirtualNode) : Integer;
var
  childfol : TQPDir;
  SR: TSearchRec;
  ChildNode: PVirtualNode;
  NewIcon : Integer;
begin
  //this code is for directory listing part of the tree
  //do a search for files, including directories (its directories we want!)
  if FindFirst(IncludeTrailingPathDelimiter(CurFol.FullPath) + '*.*', faDirectory, SR) = 0 then
  begin
    try
      //begin iteration of all files found in the directory
      repeat
        if (SR.Name <> '.') and (SR.Name <> '..') then
        begin
          //if the file found is indeed a directory we can add it.
          if (SR.Attr and faDirectory <> 0) then
          begin
            //fill the child nodes data record
            DirList.Add(TQPDir.Create(SR.Name, IncludeTrailingPathDelimiter(IncludeTrailingPathDelimiter(CurFol.FullPath) + SR.Name), false, 0, 1));
            ChildNode := VTDir.AddChild(Node);
            SetObject(VTDir, ChildNode, DirList.Last);
            //now work out if they require a special icon.
            ChildFol := TQPDir(GetObject(VTDir, ChildNode));
            NewIcon := TreeImages(ChildFol.FullPath+'folders.ini');
            If NewIcon <> -1 then
            begin
              ChildFol.CustomIcon := True;
              ChildFol.NormalIcon := NewIcon;
              ChildFol.SelIcon := NewIcon;
              If FDirHeight < 24 then
                VTDir.NodeHeight[ChildNode] := 24
              else
                VTDir.NodeHeight[ChildNode] := FDirHeight;
            end
            else
              VTDir.NodeHeight[ChildNode] := FDirHeight;

            VTDir.ValidateNode(Node, False);
          end;
        end;
      //repeat until no more results are found.
      until FindNext(SR) <> 0;
      //the childcount is the number of nodes we have just added above.
      Result := VTDir.ChildCount[Node];

    finally
      //remember to free the memory of the file search.
      FindClose(SR);
    end;
  end
  else
    Result := 0;
  //end of code for initialising directory view.
end;

{-----------------------------------------------------------------------------}

function TMainFrm.GetSplitDirHorz: Integer;
begin
  result := PanDir.Width;
end;

{-----------------------------------------------------------------------------}

function TMainFrm.GetSplitDirVert: Integer;
begin
  result := PanDir.Height;
end;

{-----------------------------------------------------------------------------}

function TMainFrm.GetSplitImgHorz: Integer;
begin
  result := pgMediaPanel.Width;
end;

{-----------------------------------------------------------------------------}

function TMainFrm.GetSplitImgVert: Integer;
begin
  result := pgMediaPanel.Height;
end;

{-----------------------------------------------------------------------------}
function MessageDlg(const Msg: string; DlgType: TMsgDlgType; Buttons: TMsgDlgButtons; Pos: TPosition): Integer;
begin
  with CreateMessageDialog(Msg, DlgType, Buttons) do
  begin
    Position := Pos;
    Result := ShowModal;
  end;
end;

{-----------------------------------------------------------------------------}
procedure TMainFrm.HandleErrUpdateMsg(var Message: TMessage);
begin
  if _ShowUpdateCheckErrors then
    MessageDlg('An error occurred while checking for updates.  Please ensure you have an active Internet connection before trying again.', mtError, [mbOK], poMainFormCenter);

  _ShowUpdateCheckErrors := False;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.HandleNewUpdateMsg(var Message: TMessage);

  begin
  if (MessageDlg('A new version of QuickPlay is available.  '+#13+#10+'Do you want to visit the QuickPlay homepage?', mtInformation, [mbYes, mbNo], poMainFormCenter) = mrYes) then
  begin
    ujUtilities.OpenHomePage('http://quickplay.sourceforge.net');
  end;
end;


{-----------------------------------------------------------------------------}

procedure TMainFrm.HandleNoUpdateMsg(var Message: TMessage);
begin
  if _ShowUpdateCheckErrors then  
    MessageDlg('No new versions available.', mtInformation, [mbOK], poMainFormCenter);

  _ShowUpdateCheckErrors := False;
end;

procedure TMainFrm.Help1Click(Sender: TObject);
begin

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.SetSplitDirHorz(const Value: Integer);
begin
  PanDir.Width := Value;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.SetSplitDirVert(const Value: Integer);
begin
  PanDir.Height := Value;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.SetSplitImgHorz(const Value: Integer);
begin
  pgMediaPanel.Width := Value;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.SetSplitImgVert(const Value: Integer);
begin
  pgMediaPanel.Height := Value;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.SetROMStatusText(value : String);
begin
  StatusBar.Panels[0].Text := Value;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.SetCompressStatusText(value : String);
begin
  StatusBar.Panels[1].Text := Value;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.PopmenuBuild();
var
  NewItem: TMenuItem;
  CurEmu : TQPEmu;
  i : Integer;
  TmpStr : TStringList;
begin
  //Clear any present menu entries.
  RunWith.Clear;

  //Build the menu with emulators with the same system as the rom.
  if VTRoms.selectedCount = 1 then
  begin

    if VTROMS.GetNodeLevel(VTROMS.FocusedNode) = 0 then
      CurEmu := EmuList.GetEmuForROM(TQPRom(GetObject(VTRoms, VTRoms.FocusedNode)))
    else
      CurEmu := EmuList.GetEmuForROM(TQPRom(GetObject(VTRoms, VTRoms.NodeParent[VTRoms.FocusedNode])));


    //now build the Send To Tool menu - only if its a LEVEL 0 NODE
    SendTo1.Clear;
    if VTROMS.GetNodeLevel(VTROMS.FocusedNode) = 0 then
      for i := 0 to ToolList.Count-1 do
        if ToolList[i].CmdLine then
        begin
          NewItem := TMenuItem.Create(SendTo1);
          NewItem.Caption := ToolList[i].Name;
          NewItem.Tag := i;
          NewItem.OnClick := DynSendTo;
          SendTo1.Add(NewItem);
        end;

    //now build the Ratings Menu.
    MnuROMRating.Clear;
    TmpStr := TStringList.Create;
    try
      Settings.Ratings(TStrings(tmpStr));
      For i := 0 to tmpStr.Count-1 do
      begin
        NewItem := TMenuItem.Create(MnuROMRating);
        NewItem.Caption := tmpStr[i];
        NewItem.OnClick := DynRating;
        MnuROMRating.Add(NewItem);
      end;
    finally
      FreeAndNil(TmpStr);
    end;

    if CurEmu = nil then
      exit;

    TmpStr := TStringList.Create;
    try
      TmpStr.NameValueSeparator := '¬';

      for i := 0 to EmuList.Count-1 do
        if StrCompare(CurEmu.system, EmuList[i].system) = 0 then
        begin

          if (Settings.AddVersion) AND (EmuList[i].Version <> '') then
            TmpStr.Values[EmuList[i].name +' (' + EmuList[i].Version+')'] := IntToStr(i)
          else
            TmpStr.Values[EmuList[i].Name] := IntToStr(i);
        end;

      TmpStr.Sort;

      for i := 0 to TmpStr.Count-1 do
      begin
        NewItem := TMenuItem.Create(RunWith);
        NewItem.Caption := TmpStr.Names[i];
        NewItem.Tag := StrToInt(TmpStr.ValueFromIndex[i]) ;
        NewItem.OnClick := DynRunwith;
        RunWith.Add(NewItem);
      end; //end of IF strCompare(the 2 systems)

    finally
      FreeAndNil(TmpStr);
    end;

  end; //end of Selectedcount = 1
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.PopmenuIPS();
var
  NewItem: TMenuItem;
  i: integer;
  ROM : TQProm;
begin
  //Clear any present menu entries.
  IPSMenu.Clear;
  //for i := IPSmenu.Count-1 Downto 0 do
  //  IPSmenu.Items[i].free;

  if VTRoms.FocusedNode <> nil then
  begin

      ROM := TQPRom(GetObject(VTRoms, VTRoms.FocusedNode));

      For i:= 0 to ROM.IPScount-1 do
      Begin
          NewItem := TMenuItem.Create(IPSMenu);
          NewItem.Caption := ROM.IPS[i].IPSName;
          NewItem.OnClick := RunIPSGame;
          NewItem.Tag := ROM.IPS[i].IPSIndex;
          IPSmenu.Add(NewItem);
      end;
  end;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.RefreshAll();
var
  DirPath : String;
  RomPath : String;
  SType : TQPRefresh;
  CurDir : TQPDir;
begin

  //load in the available emulators.
  EmuList.LoadFromFile(Settings.UseRealEmuIcons);
  //rebuild the emulators tree
  InitEmuTree();
  //Build the favourites
  BuildFavMenu;

  RomPath := '';
  DirPath := '';
  SType := QPRNone;

  //Store the currently selected Directory AND Rom

  If VTDir.SelectedCount = 1 then
  Begin
  
    CurDir := GetSelectedQPDir;

    if (CurDir <> nil) then
    begin
      DirPath := CurDir.FullPath;

      //get the currently selected ROM IF there is one.
      If VTRoms.SelectedCount = 1 then
      Begin
        if TQPRom(GetObject(VTRoms, VTRoms.FocusedNode)).ZipName <> '' then
        begin
          SType := QPRZip;
          RomPath := TQPRom(GetObject(VTRoms, VTRoms.FocusedNode)).ZipName;
        end
        else if TQPRom(GetObject(VTRoms, VTRoms.FocusedNode)).MAMEname <> '' then
        begin
          SType := QPRClone;
          RomPath := TQPRom(GetObject(VTRoms, VTRoms.FocusedNode)).MAMEname;
        end
        else
        begin
          SType := QPRPath;
          RomPath := TQPRom(GetObject(VTRoms, VTRoms.FocusedNode)).path;
        end;

      End;

    end;
  end;

  //Reload EVERYTHING
  InitTree();

  JumpToROM(DirPath, ROMPath, SType);

  VTRoms.SetFocus;
end;

{-----------------------------------------------------------------------------}

Procedure TMainFrm.RunIPSGame(Sender : TObject);
Var
  Tmp : TmenuITem;
  ROM : TQPRom;
  Emu : TQPEmu;
  RunOpt : TQPRunOptions;
begin

  Tmp := sender as TMenuItem;

  //only 0 Level ROMS can run IPS Games.  Any other level and its goodMerge stuff so ignore..
  if (VTRoms.SelectedCount = 1) and (VTROMS.GetNodeLevel(VTROMS.FocusedNode) = 0) then
  begin

    rom := TQPROM(GetObject(VTRoms, VTRoms.FocusedNode));
    Emu := EmuList.GetEmuForROM(Rom);

    If Emu <> nil then
    begin
      try

        if Settings.MiniOnRun then
          MinimiseQP();
        try

          RunOpt.GeneralPowerScheme := Settings.RunOptions.GeneralPowerScheme;
          if Emu.ExtractDest = qemGeneral then
            RunOpt.ExtractMode := Settings.RunOptions.ExtractMode
          else
            RunOpt.ExtractMode := Emu.ExtractDest;

          if RunOpt.ExtractMode = qemROMDir then
            RunOpt.ExtractDir := ExtractFilePath(ROM.Path)
          else
            RunOpt.ExtractDir := Settings.ExtractModeToPath(RunOpt.ExtractMode);

          Rom.RunIPS(Emu, Tmp.Tag, Self.ToolList, RunOpt);
        finally
          If Settings.MiniOnRun then
            RestoreQP();
        end; //end of Finally block
        
      except
        //this is caused by the running of the ROM.
        on EJNotice do MainFrm.Close();
        on E: EJException do MessageDlg(E.Message, mtError, [mbOK], poMainFormCenter);
      end;
    end
    else
      MessageDlg(QP_EMULATOR_NOT_FOUND, mtError, [mbOK], poMainFormCenter);

  end; //end of 1 ROM selected IF Statement

End;

{-----------------------------------------------------------------------------}

function TMainFrm.SelectedFolder():String;
var
  CurFol : TQPDir;
Begin
  //this function returns the full path of the directory
  //of the currently selected VTdir node.
  CurFol := GetSelectedQPDir;
  if (CurFol <> nil) then
    SelectedFolder := IncludeTrailingPathDelimiter(CurFol.FullPath)
  else
    SelectedFolder := '';
End;

{-----------------------------------------------------------------------------}

function TMainFrm.SelectedQPDir() : TQPDir;
begin
  Result := nil;

  If VTDir.FocusedNode <> nil then
    Result := TQPDir(GetObject(VTDir, VTDir.FocusedNode));
end;

{-----------------------------------------------------------------------------}

function TMainFrm.SelectedTxtFile():String;
var
  CurFol : TQPDir;
Begin
  //this function returns the full path for the text file
  //of the currently loaded ROM listing.
  CurFol := GetSelectedQPDir;

  if (CurFol <> nil) then
  begin
    SelectedTxtFile := IncludeTrailingPathDelimiter(CurFol.FullPath)+DefaultFileName;
  end
  else
    SelectedTxtFile := '';

End;

{-----------------------------------------------------------------------------}

{ This procedure is used if the EmuTree Icons option is enabled.
  It searches inside each data directory and if an icon is found
  then this icon is used in the treeview to represent the directory }
function TMainFrm.TreeImages(inifile:String) : Integer ;
var
  Ini : TMemIniFile;
  Ini2 : TMemIniFile;
  Icon : TIcon;
  pos : Integer;

  iconPath1 : String;  //defult
  iconPath2 : String; //ini 1
  iconPath3 : String; //ini 2
begin

  //this function determines whether a node uses a custom icon in the
  //directory listing.
  //first we check to see if an ini file exists for this node.
  //if it doesnt then set the icons to the standard folder ones.

  TreeImages := -1;

  If FileExists(IniFile) then
    Begin
    //create the Ini file object will we need
    Ini := TMemIniFile.Create(inifile);

    Ini2 := TMemIniFile.Create(MainFrm.Settings.Paths.SettingsFile);
    iconPath1 := MainFrm.Settings.Paths.AppDir + 'icons\'  ;
    iconPath2 := Ini2.ReadString('DirOptions', 'IconPath1', '') + '\';
    try
      //all these IFS just check that a icon is specified and it exists
      if Ini.ReadBool('Icon', 'ChkIcon', false) then

      begin //Start of file exist check

          //we know the icon exists so create a TICON to store it and
          //add it to the array.
          Icon := TIcon.Create;
          try
            if FileExists(iconPath1+Ini.ReadString('Icon','CmbIcon', '')) then
            begin
            Icon.LoadFromFile(iconPath1+Ini.ReadString('Icon','CmbIcon', ''));
              pos := EmuFolders.AddIcon(Icon);
              TreeImages := pos;
            end;
            if FileExists(iconPath2+Ini.ReadString('Icon','CmbIcon', '')) then
            begin
            Icon.LoadFromFile(iconPath2+Ini.ReadString('Icon','CmbIcon', ''));
              pos := EmuFolders.AddIcon(Icon);
              TreeImages := pos;
            end;
          Finally
            FreeAndNil(Icon);
          end;
        end;  //end of file exists check

    //end the try-finally block and free the ini object.
    finally
      FreeAndNil(ini);
    end;
  end;

end;

{-----------------------------------------------------------------------------}
{------------------------------Public Routines--------------------------------}
{-----------------------------------------------------------------------------}

procedure TMainFrm.BuildFavMenu;
var
  CurFav : TQPRom;
  i : Integer;
  NewItem, tmpItem: TMenuItem;
Begin
    FavList.LoadFromFile(Settings.Paths.FavsFile);

    //clear the favourites menu
    for i := MnuFav.Count-1 downto 3 do
    begin
      tmpItem := MnuFav.Items[i];
      FreeAndNil(tmpItem);
    end;

    For i := 0 to FavList.Count-1 do
    Begin
      CurFav := FavList[i];
      NewItem := TMenuItem.Create(MnuFav);
      NewItem.Caption := CurFav.Name + '   (' + CurFav.Emulator + ')';
      NewItem.OnClick := MainFrm.FavClick;
      NewItem.Tag := i;
      MainFrm.MnuFav.Add(NewItem);
    End;

End;

{-----------------------------------------------------------------------------}

//this code clears the ROMSicons imagelist, and resets all indexs to values
procedure TMainFrm.ClearROMIcons();
var
  i : Integer;
  RIcon : TResourceStream;
  TmpIcon : TIcon;
Begin
  ROMIcons.Clear;
    
  For I := 0 to ROMlist.Count-1 do
    ROMlist[i].IconIndex := -1;

  //now add the default ROM icon depending on which size it is.
  RIcon := TResourceStream.Create(HInstance, 'rom_icon', 'RT_ICON' );
  try

    TmpIcon := TIcon.Create;
    try
      //TmpIcon.LoadFromFile('Icons/missing.ico');     //failed....
      TmpIcon.LoadFromStream(RIcon);
      ROMicons.AddIcon(TmpIcon);
    Finally
      FreeAndNil(TmpIcon);
    end;

  finally
    FreeAndNil(RIcon);
  end;
End;

{-----------------------------------------------------------------------------}

//This procedure fills the listview with roms.
procedure TMainFrm.fillroms(FiletoLoad : TFileName);
var
  OldCursor : TCursor;
  Node : PVirtualNode;
  CompressExts : TStringList;
begin

  If FileToLoad = '' then
  Begin
    VTRoms.Clear;
    VTRoms.RootNodeCount := 0;
    ROMlist.Clear;
    
    //set up the actions.
    ActClearRoms.enabled := false;
    ROMStatusBar := QP_MAINFRM_NO_ROMS;
  End
  else
  begin

  //Change the cursor.
  OldCursor := Screen.Cursor;
  Screen.Cursor := crHourGlass;

  try
    //Clear the rom list of any entries.
    VTRoms.Clear;
    VTRoms.RootNodeCount := 0;
      
    //Load the roms for the selected directory.
    ClearRomIcons();
    ROMlist.LoadFromFile(FileToLoad);
    
    VTRoms.BeginUpdate;
    Try
      VTRoms.RootNodeCount := ROMlist.Count;

      //get all compressed file extensions.
      CompressExts := TStringList.Create;
      try
        uQPCompObj.Compression.SupportedFileExts(CompressExts);
        
        Node := VTRoms.GetFirst;
        while Node <> nil do
        begin
          SetObject(VTRoms, Node, ROMlist[Node.Index]);
          if (_GoodMergeCompat) and (CompressExts.IndexOf('*'+ExtractFileExt(ROMlist[Node.Index].Path)) <> -1) then
          begin
            Include(Node.States, vsHasChildren);
            Include(Node.States, vsAllChildrenHidden);
          end;
          Node := VTRoms.GetNextSibling(Node);
        end;

      finally
        FreeAndNil(CompressExts);
      end;

      //sort the tree now
      VTRoms.SortTree(VTRoms.Header.SortColumn, VTRoms.Header.SortDirection, false);
      
    Finally
      VTRoms.EndUpdate;
    end;

    if ROMlist.Count > 0 then
    begin
      ActClearRoms.enabled := true;
      ROMStatusBar := inttostr(ROMlist.Count) + QP_MAINFRM_FILTER_1 + IntToStr(FFiltered) + QP_MAINFRM_FILTER_2;
    end
    else
    begin
      ActClearRoms.enabled := false;
      ROMStatusBar := QP_MAINFRM_NO_ROMS;
    end;
    
    FilterRoms();

    ActEmuDel.Enabled := (EmuList.Count > 0);

  //Change the screen cursor back to normal.
  finally
    Screen.cursor := oldcursor;
  end;
  
  end;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.JoyCntrlJoyMove(Sender: TObject; X, Y: Integer; But1Pressed,
  But2Pressed, But3Pressed, But4Pressed: Boolean);
  var  Node: PVirtualNode;
  var wnd : TVirtualStringTree;
begin
if GetForegroundWindow = self.Handle then
begin
  if Settings.Joy then
    begin
      Edit1.Text := IntToStr(x) + ' ' + IntToStr(y);

      if x < 75 then//if its left
      Begin
        VTdir.SetFocus;
        wnd := VTdir;
      end
      else     //stick Right is the normal
        Begin
          VTROMs.SetFocus;
          wnd := VTROMs;
      end;

    if y > 225 then
    begin
      SendMessage(wnd.Handle,WM_KEYDOWN,VK_DOWN,0);
      Node := VTROMs.GetFirstSelected();
      wnd.ScrollIntoView(Node, true);
    end
    else if y < 75  then
    begin
      SendMessage(wnd.Handle,WM_KEYDOWN,VK_UP,0);
      Node := VTROMs.GetFirstSelected();
      wnd.ScrollIntoView(Node, true);
    end
  end
end;
end;


procedure TMainFrm.JoyCntrlJoyButtonDown(Sender: TObject; X, Y,
  ButtonChanged: Integer; But1Pressed, But2Pressed, But3Pressed,
  But4Pressed: Boolean);
  var  Node: PVirtualNode;
  begin
if GetForegroundWindow = self.Handle then
begin
  if Settings.Joy then
  begin
   if But2Pressed then
    begin //expand
      if VTROMs.Expanded [ VTROMs.GetFirstSelected() ] then
      begin
        VTROMs.Expanded [ VTROMs.GetFirstSelected() ] := false;
      end
      else
      begin
        VTROMs.Expanded [ VTROMs.GetFirstSelected() ] := true;
      end;
    end
    else if But1Pressed then
    begin //run
      SendMessage(VTROMs.Handle,WM_KEYDOWN,VK_RETURN,0);
    end
  end
end;
end;




Function TMainFrm.JumpToROM(Dir, ROM : String; SType : TQPRefresh) : Boolean;
var
  Sdir : TQPDir;
  RomData : TQPRom;
  DNode, RNode : PVirtualNode;
  DirFound, ROMFound : Boolean;
begin
  DirFound := False;

  //always reset the position back to the root and work from there
  VTDir.Selected[VTDir.GetFirst] := True;
  VTDir.FocusedNode := VTDir.GetFirst;

  //Set focus back to the selected Directory
  if Dir <> '' then
  Begin

    DNode := VTDir.GetFirst;
    While DNode <> nil do
    Begin

      Sdir := TQPDir(GetObject(VTDir, DNode));
      if (Sdir <> nil) and (StrCompare(Sdir.FullPath, Dir)=0) then
      begin
        VTDir.Selected[DNode] := True;
        VTDir.FocusedNode := DNode;
        DirFound := True;
        break;
      end
      else
      begin
       // bug fix : 7/6/05 - qp3.8
       //  following lines commented out to fix refresh doesnt go back to ur
       // selected node when in "dont show root node" mode.
       // if VTDir.GetNodeLevel(VTDir.GetNext(DNode)) <> 0 then
          DNode := VTDir.GetNext(DNode)
       // else
       //   Dnode := nil;
      end

    end;  //end of WHILE loop

  End;
       
  Result := DirFound;
  
  //now try to get the selected ROM
  if Dirfound then
  begin
    if (ROM <> '') and (SType <> QPRNone) then
    Begin

      RNode := VTRoms.GetFirst;
        While RNode <> nil do
        Begin
          RomData := TQPRom(GetObject(VTRoms, RNode));
          ROMFound := False;
          Case SType of
            QPRZip : ROMFound := (StrCompare(RomData.ZipName, ROM)=0);
            QPRClone : ROMFound := (StrCompare(RomData.MAMEname, ROM)=0);
            QPRPath : ROMFound := (StrCompare(RomData.path, ROM)=0);
          end;
          If ROMFound then
          Begin
            VTRoms.Selected[RNode] := true;
            VTRoms.FocusedNode := RNode;
            break;
          End
          Else
            RNode := vtROMS.GetNextSibling(Rnode);
        end;

    end; //end of if Rompath <> ''
  end;

end;
{-----------------------------------------------------------------------------}

procedure TMainFrm.MinimiseQP();
begin
  if not Settings.UseOldMini then
  begin
    //we can use the new style using the system tray component.
    jvTray.Active := True;
    jvTray.HideApplication;
  end
  else
  begin
    //use the minimise code from 3.4.3
    OldWindowState := MainFrm.WindowState;

    If MainFrm.WindowState <> wsNormal then
      MainFrm.WindowState := wsNormal;

    MainFrm.WindowState := wsMinimized;
    Application.Minimize();
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.RestoreQP();
begin

  if not Settings.UseOldMini then
  begin
    //we can use the new style using the system tray component.
    jvTray.ShowApplication;
    jvTray.Active := False;
  end
  else
  begin
    //use the minimise code from 3.4.3
    Application.Restore;

    MainFrm.WindowState := OldWindowState;

    Application.ProcessMessages;

    If Application.Active = false then
    Begin
      Application.Restore;
      Application.BringToFront;
    end;
  end;
end;

{-----------------------------------------------------------------------------}

Procedure TMainFrm.RunROM(var aRom : TQPRom; aEmu : TQPEmu);
var
  TimerOn : Boolean;
  RunOpt : TQPRunOptions;
begin
  // A wrapper for running a ROM.  Needed to minimise QP as this is UI business!
  Application.CancelHint();

  //check that the emulator was actually found.
  if aEmu <> nil then
  begin

    try

      If aEmu.IsMame then
        aEmu.MameConfigCheck();

      RunOpt.GeneralPowerScheme := Settings.RunOptions.GeneralPowerScheme;
      if aEmu.ExtractDest = qemGeneral then
        RunOpt.ExtractMode := Settings.RunOptions.ExtractMode
      else
        RunOpt.ExtractMode := aEmu.ExtractDest;

      if RunOpt.ExtractMode = qemROMDir then
        RunOpt.ExtractDir := ExtractFilePath(aROM.Path)
      else
        RunOpt.ExtractDir := Settings.ExtractModeToPath(RunOpt.ExtractMode);

      //disable the slideshow for the duration of the running
      if TimerAutoMove.Enabled then
      begin
        TimerAutoMove.Enabled := False;
        TimerOn := True;
      end
      else
        TimerOn := False;

      If Settings.MiniOnRun then
        MinimiseQP();
      try

        if aROM.DefaultIPSIndex <> -1 then
          aROM.RunIPS(aEmu, aROM.DefaultIPSIndex, Self.ToolList, RunOpt)
        else
          aEmu.Run(aRom, Self.ToolList, RunOpt);

      finally
        //Restore QP if needed.
        If Settings.MiniOnRun then
          RestoreQP();

        if TimerOn then
          TimerAutoMove.Enabled := True;
      end;

    except
      on E: EJNotice do MainFrm.Close;
      on E : Exception do MessageDlg(E.Message, mtError, [mbOK], poMainFormCenter);
    end;

    ROMlist.SaveToFile();

  end
  else
    //the emulator was not found, give an error!
    MessageDlg(QP_LINKED_EMU_NOT_FOUND, mtError, [mbOK], poMainFormCenter);
end;

{-----------------------------------------------------------------------------}

Function TMainFrm.GetROM(cNode : PVirtualNode) : TQPRom;
begin
  if cNode <> nil then
    Result := TQPROM(GetObject(VTRoms, cNode))
  else
    Result := nil;
end;

{-----------------------------------------------------------------------------}

Function TMainFrm.GetNextROM() : TQPRom;
begin
  Result := GetROM(VTROMS.GetNextSibling(VTRoms.GetFirstSelected));
end;

{-----------------------------------------------------------------------------}

Function TMainFrm.GetPreviousROM() : TQPRom;
begin
  Result := GetROM(VTROMS.GetPreviousSibling(VTRoms.GetFirstSelected));
end;

{-----------------------------------------------------------------------------}

Procedure TMainFrm.SetVTWallpapers();
begin
//we weren't freeing the background image when disabling the background option or before loading a new image
VTDir.Background := nil;
VTSearches.Background := nil;
VTTools.Background := nil;
VTEmus.Background := nil;

  if (Settings.Backgrounds.DirBG <> '') and
  (VTDir.TreeOptions.PaintOptions >= [toShowBackground]) and
  (FileExists(Settings.Backgrounds.DirBG)) then
    VTDir.Background.LoadFromFile(Settings.Backgrounds.DirBG);

  if (Settings.Backgrounds.SearchBG <> '') and
  (VTSearches.TreeOptions.PaintOptions >= [toShowBackground]) and
  (FileExists(Settings.Backgrounds.SearchBG)) then
    VTSearches.Background.LoadFromFile(Settings.Backgrounds.SearchBG);

  if (Settings.Backgrounds.ToolBG <> '') and
  (VTTools.TreeOptions.PaintOptions >= [toShowBackground]) and
  (FileExists(Settings.Backgrounds.ToolBG)) then
    VTTools.Background.LoadFromFile(Settings.Backgrounds.ToolBG);

  if (Settings.Backgrounds.EmuBG <> '') and
  (VTEmus.TreeOptions.PaintOptions >= [toShowBackground]) and
  (FileExists(Settings.Backgrounds.EmuBG)) then
    VTEmus.Background.LoadFromFile(Settings.Backgrounds.EmuBG);

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.SetROMHeight(Minimum : Integer);
var
  DC: HDC;
  Canvas: TCanvas;
  NewSize : Integer;
begin

  Canvas := TCanvas.Create;
  try
    DC := GetDC(0);
    Canvas.Handle := DC;
    Canvas.Font := VTRoms.Font;
    NewSize := Canvas.TextHeight('W');

    If NewSize > Minimum then
      VTRoms.DefaultNodeHeight := NewSize
    else
      VTRoms.DefaultNodeHeight := Minimum;

    Canvas.Handle := 0;
    ReleaseDC(0, DC);

  Finally
    FreeAndNil(Canvas);
  end;
end;

procedure TMainFrm.SetDIRHeight( Size : Integer);

begin
 VTDir.DefaultNodeHeight := 8;
  //VTDir.StateImages.Width := 8;
  //VTDir.StateImages.Height := 8;


end;
{-----------------------------------------------------------------------------}
{                              Action List Routines                           }
{                              Sorted by category                             }
{-----------------------------------------------------------------------------}

procedure TMainFrm.actEditVirtualFolderExecute(Sender: TObject);
var
  Find : TFindForm;
  InQuery : TStringList;
  QueryFile : TFileName;
  MatchAll : Boolean;
  i : Integer;
begin
  Find := TFindForm.Create(self);
  try

    //load the query
    InQuery := TStringList.Create();
    try

      QueryFile := SearchList.ValueFromIndex[VTSearches.FocusedNode.Index];

      InQuery.LoadFromFile(QueryFile);
      MatchAll := StrToBool(InQuery[0]);
      Find.Querys.Clear;
      for i := 1 to InQuery.Count-1 do
        Find.Querys.Add(TQPQuery.create(InQuery[i]));

      Find.EditQueryMode(MatchAll);
      if Find.ShowModal = mrOK then
      begin
        InQuery.Clear;
        InQuery.Add(BoolToStr(Find.MatchAllQuerys));
        for i := 0 to Find.Querys.Count-1 do
          InQuery.Add(TQPQuery(Find.Querys[i]).ToString);

        InQuery.SaveToFile(QueryFile);

        VTSearches.FocusedNode := VTSearches.FocusedNode;
        SetupSearchFolder(VTSearches.FocusedNode);
      end;
    finally
      FreeAndNil(InQuery);
    end;
  finally
    FreeAndNil(Find);
  end;
end;

{-----------------------------------------------------------------------------}


procedure TMainFrm.ActionListUpdate(Action: TBasicAction;
  var Handled: Boolean);
var
  Enab : Boolean;
begin

  Enab := (VTRoms.SelectedCount = 1);

  ActRunRom.enabled := Enab;
  ActRunDlg.Enabled := Enab;
  ActExplore.enabled := Enab;
  ActAddFav.enabled := Enab;
  ActAddIPS.Enabled := Enab;
  ActROMfromIPS.Enabled := Enab;
  ActHomePage.Enabled := Enab;
  ActFileRename.Enabled := Enab;

  if VTRoms.SelectedCount > 0 then
    ActDelRom.enabled := true
  else
    ActDelRom.enabled := false;
end;

{-----------------------------------------------------------------------------}
{                              File Menu Actions                              }
{-----------------------------------------------------------------------------}

procedure TMainFrm.ActExportExecute(Sender: TObject);
var
  RomExport : TROMexport;
begin
  VTRoms.BeginUpdate;
  try

    RomExport := TROMexport.create(self);
    try
      RomExport.ShowModal;
    finally
      FreeAndNil(RomExport);
    end;
    
  finally
    VTRoms.EndUpdate;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActMigrateExecute(Sender: TObject);
var
  Migrate : TFrmMigrate;
begin
  Migrate := TFrmMigrate.Create(Self);
  Try

    If Migrate.ShowModal = mrOK then
      RefreshAll();
      
  finally
    FreeAndNil(Migrate);
  end;
end;

{-----------------------------------------------------------------------------}
{                              Emulator Actions                               }
{-----------------------------------------------------------------------------}

procedure TMainFrm.ActEmuDelExecute(Sender: TObject);
begin

  IF (MessageDlg(QP_EMU_DELETE_ALL,
    mtConfirmation, [mbYes, mbNo], poMainFormCenter) = MrYes) then
  begin
    EmuList.DeleteAll(Settings.Paths.CfgDir);
    InitEmuTree();
    ActEmuDel.Enabled := false;
  end;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActEmuFindExecute(Sender: TObject);
var
  EFind : TEmuFinder;
begin
    EFind := TEmuFinder.create(self);
    try
      If Efind.ShowModal = mrok then
      begin
        FillRoms(GetSelectedTxt);
        //rebuild the emulators tree
        InitEmuTree();
        ActEmuDel.Enabled := (EmuList.Count > 0);
      end;
    finally
      FreeAndNil(Efind);
    end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActEFindEditExecute(Sender: TObject);
Var
  Edit : TFrmEfindEdit;
begin

  Edit := TFrmEFindEdit.Create(self);
  Try
    Edit.ShowModal;
  Finally
    FreeAndNil(Edit);
  end;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActEmuManExecute(Sender: TObject);
var
  Emu : TFrmEmuDlg;
begin

    Emu := TFrmEmuDlg.create(self);
    try

      //put a copy of the emulist into a temporary list

      Emu.EmuCopy.Assign(EmuList);

      If Emu.ShowModal = mrOk then
      begin
        Case EmuList.CopyFrom(Emu.EmuCopy, Settings.AutoDelRoms) of
          qparError : ;
          qparOK : ; //no action required - hopefully...;
          qparOKReload :
            //changes saved, reload is required as emulators have been renamed/deleted/added
            begin
              MainFrm.VTEmus.BeginUpdate;
              try
                MainFrm.VTRoms.BeginUpdate;
                InitEmuTree();
                Fillroms(GetSelectedTxt);
                ActEmuDel.Enabled := (EmuList.Count > 0);
              finally
                VTROMs.EndUpdate;
                MainFrm.VTEmus.EndUpdate;
              end;
            end;
        end;
        //  uEmuUtils.NewListDataCheck(EmuList, Emu.EmuCopy);

      end;
    finally
      FreeAndNil(Emu);
    end;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ACtHomePageExecute(Sender: TObject);
var
  TmpRom : TQPRom;
  Index : Integer;
begin

  //check that a ROM is selected.
  If VTRoms.SelectedCount = 1 then
  Begin
    if VTROMS.GetNodeLevel(VTRoms.FocusedNode)=0 then
      //its a normal ROM
      TmpRom := TQPRom(GetObject(VTRoms, VTRoms.FocusedNode))
    else
      //its a root node in GMCompat mode.
      TmpROM := TQPRom(GetObject(VTRoms, VTROMS.NodeParent[VTRoms.FocusedNode]));
      
    With MainFrm do
    begin
      Index := EmuList.IndexOfName(TmpRom.Emulator);
      if Index > -1 then
        EmuList[Index].OpenHomePage();
    end;
  End;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.actHomePageEmuTreeExecute(Sender: TObject);
var
  MyEmu : TQPEmu;
begin
  if VTEmus.FocusedNode <> nil then
  begin
    //Check what mode the vtemus tree is in.
    MyEmu := nil;
    if ChkEmuBySys.Checked then
    begin
      if (VTEmus.GetNodeLevel(VTEmus.FocusedNode)=1) then
        MyEmu := TQPEmu(GetObject(VTEmus, VTEmus.FocusedNode));
    end
    else
      MyEmu := TQPEmu(GetObject(VTEmus, VTEmus.FocusedNode));

    if MyEmu <> nil then
      MyEmu.OpenHomePage();
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.actEditCfgEmuTreeExecute(Sender: TObject);
var
  MyEmu : TQPEmu;
  edit : TeditCfgForm;
begin
  if VTEmus.FocusedNode <> nil then
  begin
    //Check what mode the vtemus tree is in.
    MyEmu := nil;
    if ChkEmuBySys.Checked then
    begin
      if (VTEmus.GetNodeLevel(VTEmus.FocusedNode)=1) then
        MyEmu := TQPEmu(GetObject(VTEmus, VTEmus.FocusedNode));
    end
    else
      MyEmu := TQPEmu(GetObject(VTEmus, VTEmus.FocusedNode));

    if MyEmu <> nil then
    begin
      edit := TEditCfgForm.create(Self);
      try
        if fileexists(MyEmu.CfgFile) then
        begin
          edit.load(MyEmu.CfgFile);
          edit.ShowModal;
        end
        else
          MessageDlg(J_FILE_NOT_EXIST, mtError, [mbOK], poMainFormCenter);
      finally
        FreeAndNil(Edit);
      end;
    end;
  end;
end;

{-----------------------------------------------------------------------------}
{                              Favourite Actions                              }
{-----------------------------------------------------------------------------}

procedure TMainFrm.ActAddFavExecute(Sender: TObject);
var
  TmpRom : TQPRom;
begin
  if (VTRoms.SelectedCount = 1) and (VTROMS.GetNodeLevel(VTRoms.FocusedNode)=0) then
  begin
      TmpRom := TQPRom(GetObject(VTRoms, VTRoms.FocusedNode));
      FavList.Add(TQPRom.Create(TmpRom.ToString));
      FavList.SaveToFile();
      BuildFavMenu;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActOrgFavExecute(Sender: TObject);
var
  Fav : TFavForm;
begin
  Fav := TFavForm.Create(self);
  try
  
    If fav.ShowModal = MrOK then
      FavList.SaveToFile
    else
      FavList.LoadFromFile(Settings.Paths.FavsFile);

  finally
    FreeAndNil(Fav);
  end;

  BuildFavMenu;
  
end;

{-----------------------------------------------------------------------------}
{                              Folder Actions                                 }
{-----------------------------------------------------------------------------}

procedure TMainFrm.ActDelFolExecute(Sender: TObject);
var
  CurFol : TQPDir;
  DelNode : PVirtualNode;
  NextDir : String;
begin
  DelNode := VTDir.GetFirstSelected;
  if (DelNode <> nil) then
  if (MessageDlg(J_DIRECTORY_VERIFY_DELETE, mtConfirmation, [mbYes, mbNo], poMainFormCenter) = mrYes) then
  begin
    CurFol := TQPDir(GetObject(VTDir, DelNode));
    if CurFol <> nil then
    begin

      //work out which mode to move to after the deletion.
      if VTDir.GetPreviousSibling(DelNode) <> nil then
        Nextdir := TQPDir(GetObject(VTDir, VTDir.GetPreviousSibling(DelNode))).FullPath
      else if VTDir.GetNodeLevel(DelNode) > 0 then
        Nextdir := TQPDir(GetObject(VTDir, VTDir.NodeParent[DelNode])).FullPath
      else
        NextDir := '';


      DelTree(CurFol.FullPath);
      InitTree;
      Self.JumpToROM(NextDir, '', QPRNone);
    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActFolOptExecute(Sender: TObject);
Var
  Opt : TFrmFolder;
  Directory : String;
begin
  //if no nodes are selected then exit the procedure
  if VTDir.FocusedNode = nil then
    exit;

  //set up the directory variable and test to see if its empty
  Directory := GetSelectedFolder;
  If Directory = '' then
    exit;

  Opt := TFrmFolder.Create(self);
  Try
    
    Opt.SelFol := Directory;

    if Opt.ShowModal = mrOK then
      //now refresh the selected directory
      RefreshAll;

  Finally
    FreeAndNil(Opt);
  end;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActMirrorExecute(Sender: TObject);
Var
  Ini : TMemIniFile;
  OldStyle : Tcursor;
begin

  //check there is a focused directory
  If VTDir.GetFirstSelected <> nil then
  begin

    OldStyle := screen.Cursor;
    Screen.Cursor := crHourGlass;

    VTRoms.BeginUpdate;
    try

      if fileExists(GetSelectedFolder + 'folders.ini') then
      begin
        Ini := TMemIniFile.Create(GetSelectedFolder + 'folders.ini');
        try

          Try
            RomList.MirrorDirectories(Ini);
          except
            on E: EJexception do MessageDlg(E.Message, mtError, [mbOK], poMainFormCenter);
          end;
          
        Finally
          FreeAndNil(Ini);
        end;
      end
      else
        MessageDlg(QP_MIRROR_NOT_ENABLED, mtWarning, [mbOK], poMainFormCenter);

    finally
      Screen.Cursor := OldStyle;
      //Finally Refresh the VTRoms window
      fillroms(GetSelectedTxt);
      VTRoms.EndUpdate;
    End;

  end;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActNewFolExecute(Sender: TObject);
var
  dir, temp: string;
begin

  //the rom listing is in Show ROMS only mode, ask the user if they want to make a
  //root node.. as the root node is no longer visible.
  if (VTDir.GetNodeLevel(VTDir.FocusedNode) = 0) and
     (MessageDlg(QP_MAINFRM_NEWFOL, mtConfirmation, [mbYes, mbNo], poMainFormCenter) = mrYes) then
    Dir := Settings.Paths.ROMsDir
  else
    Dir := GetSelectedFolder;


  //check that Dir is actually equal to something!
  if Dir = '' then
    exit;

  //set up the new folder name and path.
  temp := inputbox(QP_MAINFRM_NEW_FOL, QP_MAINFRM_NEW_FOL,'');

  if temp <> '' then
  begin

    Dir := IncludeTrailingPathDelimiter(Dir + Temp);

    if not DirectoryExists(dir) then  //check there are no directories using this name
    Begin
      if not CreateDir(dir) then //create the directory specified.
        raise Exception.Create(J_CREATE_DIR_FAILED)
      else
      begin
        RefreshAll();
      end;
    end
    Else
      raise Exception.Create(J_DIRECTORY_ALREADY_EXIST);
  end;

end;

{-----------------------------------------------------------------------------}
{                               Help Actions                                  }
{-----------------------------------------------------------------------------}

procedure TMainFrm.ActAboutExecute(Sender: TObject);
var
  About : TAboutBox;
begin
    About := TAboutBox.create(self);
    try
      About.ShowModal;
    finally
      FreeAndNil(About);
    end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActHelpContentsExecute(Sender: TObject);
begin
  ujUtilities.OpenHomePage('http://quickplay.sourceforge.net/wiki');
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.actQPForumsExecute(Sender: TObject);
begin
  ujUtilities.OpenHomePage('http://www.quickplayfrontend.com/index.php?act=idx');
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.actQPHomepageExecute(Sender: TObject);
begin
  ujUtilities.OpenHomePage('http://www.quickplayfrontend.com/');
end;

procedure TMainFrm.actQPOriginalHomepageExecute(Sender: TObject);
begin
  ujUtilities.OpenHomePage('http://quickplay.sf.net');
end;

{-----------------------------------------------------------------------------}
{                               MAME Actions                                  }
{-----------------------------------------------------------------------------}

procedure TMainFrm.ActCatVerExecute(Sender: TObject);
begin
  try
    RomList.SetMameCategories(MainFrm.Settings.Paths.CfgDir);
    VTRoms.Invalidate;
  except
    on E: EJException do MessageDlg(E.Message, mtError, [mbOK], poMainFormCenter);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.actCheckForUpdatesExecute(Sender: TObject);
begin
  _ShowUpdateCheckErrors := True;
  TVersionCheckThread.Create(Self.Handle, QPVer);
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActMameRenExecute(Sender: TObject);
var
  //The Mame fundctionality doesn't work. We need to make it work
  //For now, a holding page....
  Mame : TMameHolding; //Mame : TDatReader;

begin
    Mame := TMameHolding.create(self);  //Mame := TDatReader.create(self);
    try
      if Mame.ShowModal = mrOk then
        FillRoms(GetSelectedTxt);
    finally
      FreeAndNil(Mame);      
    end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActMergedScanExecute(Sender: TObject);
Var
   MergeFrm : TFrmMAMEMerged;
begin
   MergeFrm := TFrmMAMEMerged.Create(self);
   try
     If MergeFrm.ShowModal = MrOK then
       FillRoms(GetSelectedTxt);
   finally
     FreeAndNil(MergeFrm);
   end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActNPlayersExecute(Sender: TObject);
begin
  try
    RomList.SetMameMultiPlayer(MainFrm.Settings.Paths.CfgDir);
    VTRoms.Invalidate;
  except
    on E: EJException do MessageDlg(E.Message, mtError, [mbOK], poMainFormCenter);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActOpenCatverExecute(Sender: TObject);
begin
  ShellExecute(Handle, 'open', PChar('http://www.progettoemma.net/?catlist'), '', '', sw_Show);
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActOpenNPlayersExecute(Sender: TObject);
begin
  ShellExecute(Handle, 'open', PChar('http://nplayers.arcadebelgium.be'), '', '', sw_Show);
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActZiNcScanExecute(Sender: TObject);
Var
   MergeFrm : TFrmMAMEMerged;
begin
   MergeFrm := TFrmMAMEMerged.Create(self);
   try
    MergeFrm.EnableZincMode := True;
    
     If MergeFrm.ShowModal = MrOK then
       FillRoms(GetSelectedTxt);
       
   finally
     FreeAndNil(MergeFrm);
   end;
end;

{-----------------------------------------------------------------------------}
{                               ROM Actions                                   }
{-----------------------------------------------------------------------------}

procedure TMainFrm.ActAddIPSExecute(Sender: TObject);
Var
  IPSFrm : TFrmIPS;
  RData : TQPRom;
begin
  if (VTRoms.SelectedCount = 1) and (VTROMS.GetNodeLevel(VTRoms.FocusedNode)=0) then
  begin

    RData := TQPRom(GetObject(VTRoms, VTRoms.FocusedNode));
    IPSFrm := TFrmIPS.Create(self);
    Try
      IPSFrm.ROMName := rData.Name;
      if IPSFrm.ShowModal = mrOK then
      begin
        RData.AddIPS(IPSFrm.IPSName, IPSFrm.IPSPath, False);
      end;
      ROMlist.SaveToFile();

    Finally
      FreeAndNil(IPSFrm);
    end;

  end //end of 1 selected IF statement
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActROMfromIPSExecute(Sender: TObject);
var
  FrmIPS : TFrmIPS;
  newROM, oldROM : TQPROM;
  newIndex : Integer;
  OldCursor : TCursor;
  ExtrDir : String;
begin

  //check that a ROM is selected.
  if (VTROMs.FocusedNode <> nil) and (VTROMS.GetNodeLevel(VTROMS.FocusedNode)=0) then
  begin
    //get the selected ROM
    oldROM := TQPROM(GetObject(VTROMS, VTROMS.FocusedNode));
    FrmIPS := TFrmIPS.Create(self);
    try
      FrmIPS.ROMName := OldROM.Name;
      if (FrmIPS.ShowModal = mrOK) then
      begin

        OldCursor := Screen.Cursor;
        Screen.Cursor := crHourGlass;
        try
          newIndex := ROMList.Add(TQPROM.Create);
          newROM := ROMList[newIndex];
          //copy ALL data from the old ROM to the new one.
          newROM.Assign(oldROM);
          newROM.Name := FrmIPS.IPSName;

          if Settings.RunOptions.ExtractMode = qemROMDir then
            ExtrDir := ExtractfilePath(oldROM.Path)
          else
            ExtrDir := Settings.ExtractModeToPath(Settings.RunOptions.ExtractMode);

          newROM.Path := newROM.CreateIPSROM(oldROM.Path, FrmIPS.IPSPath, ExtrDir, FrmIPS.IPSName);

          //now zip up the newly created ROM.
          uQPCompObj.Compression.CompressSingleFile(newROM.Path, ChangeFileExt(newROM.Path, '.zip'));

          //check that the zip file exists..
          if FileExists(ChangeFileExt(newROM.Path, '.zip')) then
          begin
            //delete the existing IPS file and set the new path
            DeleteFile(newROM.Path);
            newROM.Path := ChangeFileExt(newROM.Path, '.zip')
          end;

          ROMList.SaveToFile;

        finally
          Screen.Cursor := OldCursor;
        end;

        FillROMs(ROMlist.FileName);
      end; //end of IF showmodal
    finally
      FreeAndNil(FrmIPS);
    end;

  end; //end of IF rom is selected test.

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActAddRomExecute(Sender: TObject);
var
  AddRom : TAddRomForm;
begin
    AddRom := TAddRomForm.create(Self);
    try
      AddRom.ShowModal;
    finally
      FreeAndNil(AddRom);
    end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActClearRomsExecute(Sender: TObject);
begin
  if fileexists(GetSelectedTxt) then
    If DeleteFile(GetSelectedTxt) then
      FillRoms(GetSelectedTxt);
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActDelRomExecute(Sender: TObject);
var
    aNode: PVirtualNode;
begin

  // if all the ROMs are selected then call the clear roms function to
  // delete the file itself.
  If VTRoms.SelectedCount = ROMlist.Count then
  begin
    If not ActClearRoms.Execute then
      ShowMessage(QP_MAINFRM_ERROR_CLEARING);
  end
  else //First Check if more than 1 rom is selected.
  if VTRoms.SelectedCount > 0 then
  begin
    //If more than one is selected then pass each selected rom to the delrom procedure
    // this code gets the first selected node and then begins a
    // while loop, getting the next selected node.  when the node
    // is equal to 'nil' - there is no next selected node.

    aNode := VTRoms.GetFirstSelected;
    while aNode <> nil do
    begin
      if VTROMS.GetNodeLevel(aNode)=0 then
        ROMlist.Remove(TQPRom(GetObject(VTRoms, aNode)))
      else
        VTROMS.Selected[aNode] := False;
      aNode := VTRoms.GetNextSelected(aNode);
    end;

    //Save the ROMs file to disk.
    ROMlist.SaveToFile();

    // now delete the nodes in the tree.
    VTRoms.DeleteSelectedNodes;

    // finally we need to update the counts (and actions)
    // this code is taken from the fillROMs function
    if ROMlist.Count > 0 then
    begin
      ActClearRoms.enabled := true;
      ROMStatusBar := inttostr(ROMlist.Count) + QP_MAINFRM_FILTER_1 + IntToStr(FFiltered) + QP_MAINFRM_FILTER_2
    end
    else
    begin
      ActClearRoms.enabled := false;
      ROMStatusBar := QP_MAINFRM_NO_ROMS;
    end;
    
  end;

end;

{-----------------------------------------------------------------------------}

//launch Windows Explorer at the location of the Rom
procedure TMainFrm.ActExploreExecute(Sender: TObject);
begin
  If VTRoms.SelectedCount = 1 then
  begin
    try
      if VTROMS.GetNodeLevel(VTRoms.FocusedNode)=0 then
        TQPROM(GetObject(VTRoms, VTRoms.FocusedNode)).BrowseToROM()
      else
        TQPROM(GetObject(VTRoms, VTROMS.NodeParent[VTRoms.FocusedNode])).BrowseToROM();
    except
      on E: EJException do MessageDlg(E.Message, mtError, [mbOK], poMainFormCenter);
    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActFileRenameExecute(Sender: TObject);
Var
  RData : TQPRom;
  OldName, newname : String;
begin
    //only execute if a rom is selected in the rom listings
  if (VTRoms.FocusedNode <> nil) and (VTROMS.GetNodeLevel(VTROMS.FocusedNode) = 0) then
  begin

    RData := TQPRom(GetObject(VTRoms, VTRoms.FocusedNode));

    If FileExists(RData.path) = False then
    begin
      MessageDlg(J_DIRECTORY_NOT_EXIST, mtError, [mbOK], poMainFormCenter);
      Exit;
    end;

    OldName := ExtractFileName(RData.path);

    NewName := OldName;

    If InputQuery(QP_MAINFRM_RENAME_1 + OldName, QP_MAINFRM_RENAME_2 + OldName, NewName) then
    Begin
      try
        RData.RenameFile(NewName);
        ROMList.SaveToFile();
        FilterRoms;
      except
        on E: EJException do MessageDlg(E.Message, mtError, [mbOK], poMainFormCenter);
      end;
    End;

  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActFindRomExecute(Sender: TObject);
var
  Find : TFindForm;
begin
    Find := TFindForm.create(Self);
    try
      find.ShowModal;
      if Find.NewVF then
        InitSearchTree();
    finally
      FreeAndNil(find);
    end;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActOrphansExecute(Sender: TObject);
begin

  uRomUtils.DeleteAllOrphans();

  FavList.DeleteOrphans();

  FillRoms(GetSelectedTxt);
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActRandomFolderExecute(Sender: TObject);
begin
  //We need to minimise within the UI code now.
  try
    If Settings.MiniOnRun then
      MinimiseQP();
    try
      ROMlist.RunRandom(EmuList, Self.ToolList, Settings, False);
    finally
      //Restore the minimising if need be.
      If Settings.MiniOnRun then
        RestoreQP();
    end;
  except
    on EJNotice do MainFrm.Close;  //handles the exception raised by running a rom.
    on E: EJException do MessageDlg(E.Message, mtError, [mbOK], poMainFormCenter);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActRandomAllExecute(Sender: TObject);
begin
  try
    //We need to minimise within the UI code now.
    If Settings.MiniOnRun then
      MinimiseQP();
    try
      uRomUtils.RunRandomAll(False);
    finally
      //Restore the minimising if need be.
      If Settings.MiniOnRun then
        RestoreQP();
    end;
  except
    on EJNotice do MainFrm.Close;
    on E: EJException do MessageDlg(E.Message, mtError, [mbOK], poMainFormCenter);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.actRandomFolderNeverPlayedExecute(Sender: TObject);
begin
  //We need to minimise within the UI code now.
  try
    If Settings.MiniOnRun then
      MinimiseQP();
    try
      ROMlist.RunRandom(EmuList, Self.ToolList, Settings, True);
    finally
      //Restore the minimising if need be.
      If Settings.MiniOnRun then
        RestoreQP();
    end;
  except
    on EJNotice do MainFrm.Close;  //handles the exception raised by running a rom.
    on E: EJException do MessageDlg(E.Message, mtError, [mbOK], poMainFormCenter);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.actRandomAllNeverPlayedExecute(Sender: TObject);
begin
    try
    //We need to minimise within the UI code now.
    If Settings.MiniOnRun then
      MinimiseQP();
    try
      uRomUtils.RunRandomAll(True);
    finally
      //Restore the minimising if need be.
      If Settings.MiniOnRun then
        RestoreQP();
    end;
  except
    on EJNotice do MainFrm.Close;
    on E: EJException do MessageDlg(E.Message, mtError, [mbOK], poMainFormCenter);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActRomPropExecute(Sender: TObject);
Var
  Prop : TFrmRomProp;
  aNode : PVirtualnode;
begin
  Prop := TFrmRomProp.Create(Self);
  try
    If (VTRoms.selectedCount > 0) then
    begin

      //if we are currently editting a rom we need to end that..
      if VTRoms.IsEditing then
        VTRoms.EndEditNode;

      //if there is only 1 emulator selected the user can alter all properties
      if (VTRoms.selectedcount = 1) then
      begin
        if (VTROMS.GetNodeLevel(VTROMS.GetFirstSelected) > 0) then
        begin
          MessageDlg(QP_MAINFRM_GMMERGE_CHILD_PROP, mtError, [mbOK], poMainFormCenter);
          Exit;
        end;
        Prop.ROM := TQPROM(GetObject(VTRoms, VTRoms.GetFirstSelected));
        Prop.Multi := False;
        Prop.cNode := VTRoms.GetFirstSelected;
      end
      else 
      begin
        Prop.Multi := True;

        // this code gets the first selected node and then begins a
        // while loop, getting the next selected node.  when the node
        // is equal to 'nil' - there is no next selected node.
        aNode := VTRoms.GetFirstSelected;
        while aNode <> nil do
        begin
          if VTROMS.GetNodeLevel(aNode)=0 then
            Prop.Selected.Add(TQPROM(GetObject(VTRoms, aNode)));
          aNode := VTRoms.GetNextSelected(aNode);
        end;
      end;

      If Prop.ShowModal = mrOK then
      begin
        if VTROMS.SelectedCount = 1 then
          VTROMS.InvalidateNode(VTROMS.GetFirstSelected)
        else
        begin
          //revalidate all selected nodes.
          aNode := VTRoms.GetFirstSelected;
          while aNode <> nil do
          begin
            VTROMS.InvalidateNode(aNode);
            aNode := VTRoms.GetNextSelected(aNode);
          end;
        end;
      end; //end of showmodal
    end;

  finally
    FreeAndNil(Prop);
  end;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActRunDlgExecute(Sender: TObject);
var
  RDialog : TFrmRunRom;
  tmpROM : TQPROM;
begin

  //only execute if a rom is selected in the rom listings
  if VTRoms.SelectedCount = 1 then
  begin
      Rdialog := TFrmRunRom.Create(Self);
      Try

        TmpROM := TQPROM.Create;
        try
          Self.GetROMToRun(TmpROM, VTRoms.FocusedNode);
          RDialog.Rom := TmpROM;

          RDialog.Emu := EmuList.GetEmuForROM(Rdialog.Rom);
          if RDialog.Emu = nil then
            MessageDlg(QP_EMULATOR_NOT_FOUND, mtError, [mbOK], poMainFormCenter);

          if (RDialog.Emu <> nil) and (RDialog.Rom <> nil) then
            RDialog.ShowModal;

        finally
          FreeAndNil(TmpROM);
        end;

      finally
        FreeAndNil(RDialog);
      end;
  end;
end;


{-----------------------------------------------------------------------------}

procedure TMainFrm.ActRunRomExecute(Sender: TObject);
var
  RDialog : TFrmRunRom;
  tmpROM : TQPROM;
  tmpEmu : TQPEmu;
  Hit : THitInfo;
  HitNode, theNode : PVirtualNode;
begin

  TheNode := Nil;
  if _KeyPress then
  begin
    TheNode := VTROMS.FocusedNode;
    _KeyPress := False;
  end
  else
  begin
    VTROMS.GetHitTestInfoAt(_ROMPoint.X, _ROMPoint.Y, True, Hit);
    HitNode := Hit.HitNode;
    if (HitNode <> nil) and (not (hiOnItemButton in Hit.HitPositions)) then
      TheNode := HitNode;
  end;

  if TheNode <> nil then
  //if (VTRoms.SelectedCount = 1) and (VTRoms.FocusedNode <> nil) then
  begin

    TmpROM := TQPROM.Create;
    try
      Self.GetROMToRun(TmpROM, TheNode);

      // by this stage we have the ROM object we want to run.

      If Settings.UseRunDLG then
      Begin

        Rdialog := TFrmRunRom.Create(Self);
        Try

          RDialog.Rom := tmpROM;
          RDialog.Emu := EmuList.GetEmuForROM(RDialog.Rom);

          If (RDialog.Rom <> nil) and (RDialog.Emu <> nil) then
            RDialog.ShowModal;

        finally
          FreeAndNil(RDialog);
        end;
      end
      Else
      Begin
        TmpEmu := EmuList.GetEmuForROM(tmpROM);
        RunROM(tmpRom, tmpEmu);
      End;

    // free up that ROM now.
    finally
      FreeAndNil(tmpROM);
    end;

  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActMultiScanExecute(Sender: TObject);
var
  multi : TRecursiveFrm;
begin
  Multi := TRecursiveFrm.Create(Self);
  try

    Multi.AddToDir := GetSelectedFolder;
    If Multi.ShowModal = mrOK then
      If MainFrm.Active then
        RefreshAll;

  finally
    FreeAndNil(Multi);
  end;
end;

{-----------------------------------------------------------------------------}


procedure TMainFrm.ActScanExecute(Sender: TObject);
var
  Rom : TScanForm;
begin
  VTRoms.BeginUpdate;
  try
  
    Rom := TScanForm.create(Self);
    try
      If Rom.ShowModal = mrOk then
        FillRoms(GetSelectedTxt);
    finally
      FreeAndNil(Rom);
    end;

  finally
    VTRoms.EndUpdate;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActZipExecute(Sender: TObject);
var
  zip : TFrmCompressionTools;
begin
    zip := TFrmCompressionTools.create(Self);
    try
      zip.ShowModal;
    finally
      FreeAndNil(zip);
    end;
end;

{-----------------------------------------------------------------------------}
{                             VIEW actions                                    }
{-----------------------------------------------------------------------------}

procedure TMainFrm.ActColumnsExecute(Sender: TObject);
Var
  Col : TFrmColumn;
begin
  Col := TFrmColumn.Create(Self);
  Try
    Col.ShowModal;
  Finally
    FreeAndNil(Col);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActImgVisibleExecute(Sender: TObject);
begin
  ActImgVisible.Checked := not(ActImgVisible.Checked);
  pgMediaPanel.Visible := ActImgVisible.Checked;

  if ActImgVisible.Checked then
    SPlitImage.Show
  else
    SPlitImage.Hide;
    
end;

{-----------------------------------------------------------------------------}
procedure TMainFrm.ActDBarVisibleExecute(Sender: TObject);
begin
  ActDBarVisible.Checked := not(ActDBarVisible.Checked);
  TBDir.Visible := ActDBarVisible.Checked;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActFilterVisibleExecute(Sender: TObject);
begin
  ActFilterVisible.Checked := not(ActFilterVisible.Checked);
  PanFilter.Visible := ActFilterVisible.Checked;

  //if the filter is being turned off, make sure any stored filters are reset.
  if (not PanFilter.Visible) and (RomList <> nil) and (FFilterString <> '') then
  begin
    TxtFilter.Text := '';
    FFilterString := '';
    FilterRoms;
    ROMStatusBar := inttostr(VTRoms.RootNodeCount) + QP_MAINFRM_FILTER_1 +
                          IntToStr(FFiltered) + QP_MAINFRM_FILTER_2
  end;
  
  //need to check whether we need the Panel at the top of the ROM list.
  If not PanFilter.Visible and not TBROMs.Visible then
    PanROMtop.Visible := false
  else
    PanROMtop.Visible := true;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActRBarVisibleExecute(Sender: TObject);
begin
  //ActionToolBar1.Visible := ActRomBarVisible.Checked;
  ActRBarVisible.Checked := not(ActRBarVisible.Checked);
  TBRoms.Visible := ActRBarVisible.Checked;

  //need to check whether we need the Panel at the top of the ROM list.
  If not PanFilter.Visible and not TBROMs.Visible then
    PanROMtop.Visible := false
  else
    PanROMtop.Visible := true;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActRefreshExecute(Sender: TObject);
begin
  RefreshAll();
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActSelAllExecute(Sender: TObject);
begin
  //Select all the roms in the listview.
  VTRoms.SelectAll(True);
end;

{-----------------------------------------------------------------------------}
{                              TOOLS options                                  }
{-----------------------------------------------------------------------------}

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActPrefExecute(Sender: TObject);
var
  Pref : TPrefForm;
begin
  // save the ini file now, to make sure we get all the changes on disk
  Settings.SaveUISettings;

  pref := TPrefForm.create(Self);
  try

    pref.ShowModal;

  finally
    FreeAndNil(pref);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActBackupRestoreExecute(Sender: TObject);
var
  Backup : TFrmBackup;
begin
  Backup := TFrmBackup.Create(Self);
  Try
    if Backup.ShowModal = MrOK then
      RefreshAll();
  Finally
    FreeAndNil(Backup);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActCustomDataExecute(Sender: TObject);
var
  Custom : TFrmROMData;
begin
  Custom := TFrmROMData.Create(self);
  try

    Custom.ShowModal;

  Finally
    FreeAndNil(Custom);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActResetConfigExecute(Sender: TObject);
var
  Wiz : TFrmWelcome;
begin

  if MessageDlg(J_SETTINGS_RESET_CFG, mtWarning, [mbYes,mbNo], poMainFormCenter) in [mrYes] then
  begin

    VTRoms.Clear;
    VTDir.Clear;

    EmuList.Clear;
    ROMlist.Clear;
    //FavList.ClearFavs;

    if DirectoryExists(Settings.Paths.CfgDir) then
      DelTree(Settings.Paths.CfgDir);
    if DirectoryExists(Settings.Paths.ROMsDir) then
      DelTree(Settings.Paths.ROMsDir);
    if DirectoryExists(Settings.Paths.SearchDir) then
      DelTree(Settings.Paths.SearchDir);

    Settings.PathSetup;
    Settings.LoadIni;
    
    Wiz := TFrmWelcome.Create(Self);
    try
      Wiz.ShowModal;
    Finally
      FreeAndNil(Wiz);
    end;

    RefreshAll;

  end; //end of MessageDlg IF
  
end;

{-----------------------------------------------------------------------------}
{                              Other published code                           }
{-----------------------------------------------------------------------------}

procedure TMainFrm.FavClick(Sender : TObject);
var
  mnu : TMenuItem;
  MyROM : TQPROM;
begin
  //dont delete
  mnu := sender as TMenuItem;
  MyROM := FavList[mnu.tag];
  RunROM(MyROM, EmuList.GetEmuForROM(FavList[mnu.tag]));
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.SetupROMSFolder(NewFol : TQPDir; NewNode : PVirtualNode);
var
  Ini : TMemIniFile;
  BGPath : String;
  SR: TSearchRec;
begin
  //start of directory listing code.
  Ini := TMemIniFile.Create(NewFol.FullPath + 'folders.ini');
  Try

    //determine whether this folder is going to be GoodMerge compatible.
    _GoodMergeCompat := Ini.ReadBool('GoodMerge', 'GoodMergeCompat', False);
    if _GoodMergeCompat then
    begin
      //activate goodmerge specific tree options.
      VTROMS.TreeOptions.PaintOptions := VTROMS.TreeOptions.PaintOptions + [toShowRoot, toShowButtons];
      _GoodMergeEXCL := Ini.ReadBool('GoodMerge', 'GoodMergeExclamationRoms', false);
	    _GMpref1 := Ini.ReadString('GoodMerge', 'Pref1', '(U)');
      _GMpref2 := Ini.readString('GoodMerge', 'Pref2', '(E)');
      _GMpref3 := Ini.readString('GoodMerge', 'Pref3', '(J)');
    end
    else
      //reset tree options back to normal.
      VTROMS.TreeOptions.PaintOptions := VTROMS.TreeOptions.PaintOptions - [toShowRoot, toShowButtons];

    //get the filter function type
    FFilterByStart := Ini.ReadBool('Filter', 'ByStart', true);
    Settings.HideShowCol(NewFol.FullPath);

    //related to Real MAME Icons support
    ROMIcons.Clear;

    _MAMEIconsMode := TQPMAMEIconMode(Ini.ReadInteger('RealIcon', 'ChkRealIcons', 0));

    Case _MAMEIconsMode of
      qmiDir :
      begin
        if _MAMEIconsList = nil then
          _MAMEIconsList := TStringList.Create
        else
          _MAMEIconsList.Clear; //it already existed, clear it.
          
        _MAMEIconsPath := IncludeTrailingPathDelimiter(Ini.ReadString('RealIcon', 'Directory', ''));
        if not DirectoryExists(_MAMEIconsPath) then
          DisableMAMEIcons()
        else
        begin
          //cache the contents of the directory so we dont keep searchign it.
          if FindFirst(_MAMEIconsPath + '*.ico', faAnyFile, SR) = 0 then
          begin
            try
              Repeat
                if (SR.Name <> '.') and (SR.Name <> '..') then
                begin
                  _MAMEIconsList.Add(SR.Name);
                end;
              until FindNext(SR) <> 0;
            finally
              //remember to free the memory of the file search.
              FindClose(SR);
            end;
          end;
        end;//end of DirectoryExists check.

      end;
      
      qmiZip :
      begin
        if _MAMEIconsList = nil then
          _MAMEIconsList := TStringList.Create
        else
          _MAMEIconsList.Clear; //it already existed, clear it.

        _MAMEIconsPath := Ini.ReadString('RealIcon', 'Directory', '');
        if not FileExists(_MAMEIconsPath) then
          DisableMAMEIcons()
        else
          uQPCompObj.Compression.ListContentsOfFile(TStrings(_MAMEIconsList), _MAMEIconsPath);

      end;
      
      else //disable MAME Icons and clean up.
        DisableMAMEIcons();
    end;

    If (Settings.UseImagesForROMs) and (_MAMEIconsMode <> qmiOff) then
    Begin
      VTRoms.Images := ROMicons;

      If Ini.ReadBool('RealIcon', 'ChkLargeIcons', false) then
      begin
        SetROMHeight( Settings.IconSize  + 12);
        ROMIcons.Width := 32;
        ROMIcons.Height := 32;
      end
      else
      begin
        SetROMHeight(Settings.IconSize  );
        ROMIcons.Width := 16;
        ROMIcons.Height := 16;
      end;
            
    end
    else
    begin
      VTRoms.Images := ImageList1;
      SetROMHeight(Settings.IconSize  );   //if we made this a var we coudl change the view size ( also note the above two )
    end;

    fillroms(NewFol.FullPath+DefaultFileName);
    //set the background

    //now do checking to see if a valid background has been chosen.
    if ini.ReadBool('BkGround', 'ChkBk', false) then
    Begin
      BGpath := Ini.ReadString('BkGround', 'TxtBKPath', '');
      //BGPath := ExtractFileExt(BGpath) ;
      if (BGpath <> '') and (FileExists(BGpath) ) then // this was not needed...and ( Lowercase((ExtractFileExt(BGpath) ) ) = '.bmp' ) )then
      begin
        VTRoms.TreeOptions.PaintOptions := VTRoms.TreeOptions.PaintOptions + [toShowBackground];
        VTRoms.Background.LoadFromFile(BGpath);
      end
    end
    else if (Settings.Backgrounds.DefaultROMBG) and (FileExists(Settings.Backgrounds.RomBG)) then
    begin
      //there is a DEFAULT background specified, apply it.
      VTRoms.TreeOptions.PaintOptions := VTRoms.TreeOptions.PaintOptions + [toShowBackground];
      VTRoms.Background.LoadFromFile(Settings.Backgrounds.ROMBG);
    end
    else
    begin
      //no backgrounds wanted, erase them.
      VTRoms.TreeOptions.PaintOptions := VTRoms.TreeOptions.PaintOptions - [toShowBackground];
    end;

  Finally
    FreeAndNil(Ini);
  end;

  //enable the actions now
  ActNewFol.Enabled := true;
  ActMirror.Enabled := true;
  ActScan.enabled := true;
  ActAddRom.Enabled := True;
  ActMultiScan.Enabled := True;
  ActFolOpt.Enabled := true;
  //end of directory listing code.
end;
{-----------------------------------------------------------------------------}

procedure TMainFrm.SetupSearchFolder(NewNode : PVirtualNode);
var
  InQuery : TStringList;
  Querys : TObjectList;
  QueryResults, TmpList : TQPRomList;
  MatchAll : Boolean;
  i, e : Integer;
  OldStyle : TCursor;
  QueryFile : TFileName;
begin

  If Settings.ClearFilter then
  begin
    TxtFilter.Text := '';
    FFilterString := '';
  end;

  OldStyle := Screen.Cursor;
  Screen.Cursor := crHourGlass;
  try

  if FileExists(Settings.Paths.AppDir+'find.png') then
  begin
    VTRoms.Background.LoadFromFile(Settings.Paths.AppDir+'find.png');
    VTRoms.TreeOptions.PaintOptions := VTRoms.TreeOptions.PaintOptions + [toShowBackground]
  end
  else
    VTRoms.TreeOptions.PaintOptions := VTRoms.TreeOptions.PaintOptions - [toShowBackground];

  VTRoms.Clear;
  VTRoms.RootNodeCount := 0;
  VTRoms.Images := ImageList1;
  SetROMHeight(Settings.IconSize );
  ROMIcons.Width := 16;
  ROMIcons.Height := 16;
  _MAMEIconsMode := qmiOff;
  _MAMEIconsPath := '';
  FreeAndNil(_MAMEIconsList);

  //setup the columsn
  Settings.HideShowCol('');

  QueryFile := SearchList.ValueFromIndex[NewNode.Index];

     //load the query and execute it!
    InQuery := TStringList.Create();
    try
      Querys := TObjectList.Create(True);
      InQuery.LoadFromFile( QueryFile );
      MatchAll := StrToBool(InQuery[0]);
      for i := 1 to InQuery.Count-1 do
        Querys.Add(TQPQuery.create(InQuery[i]));
      //now we have the querys objectlist set up with our query.
      QueryResults := TQPRomList.Create(Settings.AllowWrite);
      TmpList := TQPROmList.Create(Settings.AllowWrite);
      Try

        //reuse the stringlist from above to hold all possible rom files.
        GetAllROMFiles(InQuery);
        for i := 0 to InQuery.Count-1 do
        begin
          TmpList.LoadMatchesFromFile(inQuery[i], Querys, MatchAll);
          for e := 0 to TmpList.Count-1 do

            if TmpList[e].MatchesQuery(Querys, MatchAll) then
            begin
              QueryResults.Add(TQPROM.create());
              QueryResults.last.Assign(TmpList[e]);
            end;
          //free whats in the ROMs array
          TmpList.clear;
        end;

        //ok now queryresults is full of roms that match.  save teh file and then load it..
        QueryResults.FileName := ChangeFileExt(QueryFile, '.tmp');
        QueryResults.SaveToFile;
        fillroms(ChangeFileExt(QueryFile, '.tmp'));
            
      Finally
        FreeAndNil(QueryResults);
        FreeAndNil(TmpList);
      end;
    finally
      FreeAndNil(InQuery);
      FreeAndNil(Querys);
    end;

  ActScan.enabled := false;
  ActMultiScan.Enabled := False;
  ActAddRom.Enabled := False;
  ActAddRom.enabled := false;
  ActMirror.Enabled := false;
  ActFolOpt.Enabled := false;

  finally
    Screen.Cursor := OldStyle;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.FormCreate(Sender: TObject);
begin
  //MemCheckLogFileName := IncludeTrailingPathDelimiter(ExtractFilePath(ParamStr(0))) + 'memcheck.txt';
  //MemChk;

  Edit1.Hide;


  if JoyCntrl.HasJoystick1 then  //  Joy1
  begin
    JoyCntrl.CaptureJoystick1 := True;
    JoyCntrl.Joy1Move := JoyCntrlJoyMove;
    JoyCntrl.Joy1ButtonDown := JoyCntrlJoyButtonDown;
  end;
  if JoyCntrl.HasJoystick2 then //Joy2
  begin
    JoyCntrl.CaptureJoystick2 := True;
    JoyCntrl.Joy2Move := JoyCntrlJoyMove;
    JoyCntrl.Joy2ButtonDown := JoyCntrlJoyButtonDown;
  end;

  SlideBar.OnMouseUp := SlideBarMouseUp;
  SlideBarDir.OnMouseUp := SlideBarDirMouseUp;


  Application.HintPause := 750;
  Application.HintShortPause := 100;
  Application.HintHidePause := 3200;

  //{$Define DEBUG}

  {$IFDEF DEBUG}
  AddToLog('QuickPlay STARTING');
  {$ENDIF}

  Settings := TQPSettings.Create;

  if Settings.CheckForUpdatesOnStart then
  begin
    _ShowUpdateCheckErrors := False;
    TVersionCheckThread.Create(Self.Handle, QPVer);
  end;

  //rom listing icon field size
  SlideBar.Position := Settings.IconSize ;//read in from file
  SlideBarDir.Position := Settings.IconSizeDir ;//read in from file


  //create the compression wrapper object.
  uQPCompObj.Compression := TQPCompressObj.Create(Settings.Paths.CfgDir);
  CompressStatusBar := 'Compression Support - ' + uQPCompObj.Compression.ListCompressorsByName(cmRead);

  SystemList := TObjectList.Create(True);
  EmuList := TQPEmuList.Create(Settings.Paths.CfgDir + 'emulators.ini', Settings.AllowWrite);
  ToolList := TQPToolList.Create(Settings.Paths.CfgDir + 'Tools.ini', Settings.AllowWrite);
  RomList := TQPRomList.Create(Settings.AllowWrite);
  FavList := TQPRomList.Create(Settings.AllowWrite);
  //create the objectlist to store our objects for the VTDir
  DirList := TObjectList.Create(True);
  SearchList := TStringList.Create;

  //set up the media objects.
  _MediaSearch := TJMediaSearch.Create(Settings.Paths.CfgDir);
  _MediaSearch.PageControl := pgMediaPanel;
  pgMediaPanel.OnChange := _MediaSearch.DoTabChange;

  //now set up our Virtual Treeviews with their 'sizeOfs'
  VTRoms.NodeDataSize := SizeOf(Pointer);
  VTDir.NodeDataSize := SizeOf(Pointer);
  VTEmus.NodeDataSize := SizeOf(Pointer);
  vtTools.NodeDataSize := SizeOf(Pointer);
  VTSearches.NodeDataSize := SizeOf(Pointer);

  ChangeLayout();
  SetVTWallpapers();
  
  //load the available emulators
  EmuList.LoadFromFile(Settings.UseRealEmuIcons);

  //load available tools
  ToolList.LoadFromFile(Settings.UseRealToolIcons);

  {$IFDEF DEBUG}
  AddToLog('All Objects Created Successfully');
  {$ENDIF}

  MainFrm.Caption := MainFrm.Caption + ' ' + QPver;

  //Build the favourites
  BuildFavMenu;
  //set up tools tree
  InitToolTree();
  //setup searchs tree
  InitSearchTree();

  pgSideBar.ActivePageIndex := 0;

  _FakeOnCreate := True;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.FormShow(Sender: TObject);
var
  WizardFrm : TFrmWelcome;
  i : Integer;
begin
  //used because the TJVDirectoryEdit, calls Application.MainForm in the middle of onCreate,
  //which obviously wont work as the form hasnt fully created itself yet.. pants.
  if _FakeOnCreate then  //we only do this if the FakeOnCreate variable is set.
  begin

    //check for presence of VISUAL commandline parameters.
    for I := 0 to ParamCount do
    begin
      if JCLStrings.StrCompare(ParamStr(i), '/MAXIMISE')=0 then
        Self.WindowState := wsMaximized;

      if JCLStrings.StrCompare(ParamStr(i), '/NORMALSIZE')=0 then
        self.WindowState := wsNormal;

      if JCLStrings.StrCompare(ParamStr(i), '/NOMENU')=0 then
        Self.Menu := nil;

      if JCLStrings.StrCompare(ParamStr(i), '/NOSTATUSBAR')=0 then
        Self.StatusBar.Hide;

      if JCLStrings.StrCompare(ParamStr(i), '/NOBORDER')=0 then
        Self.BorderStyle := bsNone;

      if JCLStrings.StrCompare(ParamStr(i), '/HTPC')=0 then
      begin
        Self.Menu := nil;
        Self.BorderStyle := bsNone;
        Self.StatusBar.Hide;
      end;

    end;  //end of FOR through visual commandline parameters

    If Settings.NoDats then
    begin
      WizardFrm := TFrmWelcome.Create(nil);
      Try
        WizardFrm.ShowModal;
      Finally
        FreeAndNil(WizardFrm);
      end;
    end;

    Settings.NoDats := False;

    //set up the Emulators Tree
    InitEmuTree();

    //build the directory tree.
    InitTree();

    //set the initially selected node.
    VTDir.Selected[VTDir.GetFirst] := True;
    VTDir.focusedNode := VTDir.GetFirst;

    Settings.LoadLastROM;

    if _MediaSearch.AutoMove then
    begin
      TimerAutoMove.Interval := _MediaSearch.TimePerTab * 1000;
      TimerAutoMove.Enabled := True;
    end;

    _FakeOnCreate := False;

  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.SlideBarChange(Sender: TObject);
begin
//start
  if ( Settings <> nil  ) then
  if ( EmuList <> nil  ) then

  begin
    ActRefreshExecute(Sender);
    Settings.IconSize := SlideBar.Position;
  end;
end;

procedure TMainFrm.SlideBarDirChange(Sender: TObject);
begin
//start
  if ( Settings <> nil  ) then
  begin
    Settings.IconSizeDir := SlideBarDir.Position;
    SetDIRHeight(Settings.IconSizeDir  );
  end;
end;

procedure TMainFrm.SlideBarMouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
    if ( Settings <> nil  ) then
    Settings.SaveAllSettings();
end;

procedure TMainFrm.SlideBarDirMouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
    if ( Settings <> nil  ) then
    Settings.SaveAllSettings();
end;

procedure TMainFrm.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  {$IFDEF DEBUG}
  AddToLog('QuickPlay is about to shutdown');
  {$ENDIF}

  VTRoms.EndEditNode();

  //kill any hints.  yes this is done because im paranoid about shutdown code!
  Application.CancelHint;

  if (GetSelectedFolder <> '') then
    if (VTRoms.GetFirstSelected <> nil) then
    begin
      if VTROMS.GetNodeLevel(VTRoms.GetFirstSelected)=0 then
        //a ROM is selected, save it.
        Settings.SaveCurrentROM(GetSelectedFolder, GetObject(VTRoms, VTRoms.GetFirstSelected))
      else
        //a compressed contents node is selected, save its parent.
        Settings.SaveCurrentROM(GetSelectedFolder, GetObject(VTRoms, VTROMS.NodeParent[VTRoms.GetFirstSelected]))
    end
    else
      //only a folder is selected, oh well save the folder anyway! 
      Settings.SaveCurrentROM(GetSelectedFolder, nil);
  
  //wipe all the treeviews
 { VTMedia.Clear;
  VTRoms.Clear;
  VTDir.Clear;
  MediaFound.Clear;}
  
  // clear image list related stuff.
  EmuFolders.Clear;
  ROMIcons.Clear;

  //clear all our dynamic menus (IPS, Favs, RunWith)
  ClearAllDynMenus;

  {$IFDEF DEBUG}
  AddToLog('Interface elements have been cleared');
  {$ENDIF}

  //now save the current settings.
  Settings.SaveUISettings;

  {$IFDEF DEBUG}
  AddToLog('Settings Saved.');
  {$ENDIF}

  {$IFDEF DEBUG}
  AddToLog('Object Cleanup code executed, preparing to FreeAndNil');
  {$ENDIF}

  //Free the Quickplay objects we have created.
  DirList.Clear;
  ROMlist.Clear;
  FavList.Clear;
  ToolList.Clear;
  EmuList.Clear;
  SystemList.Clear;
  SearchList.Clear;

  DirList.Free;
  RomList.Free;
  FavList.Free;
  ToolList.Free;
  EmuList.Free;
  Settings.Free;
  SystemList.Free;
  FreeAndNil(SearchList);
  FreeAndNil(_MAMEIconsList);

  uQPCompObj.Compression.Free;

  {$IFDEF DEBUG}
  AddToLog('QuickPlay SHUTDOWN');
  AddToLog('-----------------------------------------------------------------');
  {$ENDIF}

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.RomPopUpPopup(Sender: TObject);
begin
  PopMenuBuild();
  if VTROMS.GetNodeLevel(VTROMS.FocusedNode) = 0 then
    PopmenuIPS();
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.RunWithClick(Sender: TObject);
begin
  //For Some reason this keeps losing its association!!!  V.Annoying!
end;

procedure TMainFrm.IPSMenuClick(Sender: TObject);
begin
  //For Some reason this keeps losing its association!!!  V.Annoying!
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.TxtFilterKeyUp(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
  FFilterString := TxtFilter.Text;
  FilterRoms;
  ROMStatusBar := inttostr(VTRoms.RootNodecount) + QP_MAINFRM_FILTER_1 +
                          IntToStr(FFiltered) + QP_MAINFRM_FILTER_2
end;

{-------------- start of code for VTRoms treeview -------------------}

procedure TMainFrm.VTRomsGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
var
  ROM : TQPRom;
  Emu : TQPEmu;
  Comment : String;
begin
{the columns are as follows:
 0-name
 1-GameType
 2-Path
 3-Emulator
 4-System
 5-Year
 6-Number of times played
 7-Language
 8-Rating
 9-Parameters
 10-number of IPS associated
 11-Company
 12-Comment
 13 - Players
 14 - Parameter Mode
}
  // A handler for the OnGetText event is always needed as it provides the tree with the string data to display.
  // Note that we are always using WideString.
  if Node = nil then
    exit;

  if Sender.GetNodeLevel(Node) = 0 then
  begin
    ROM := TQPRom(GetObject(Sender, Node));

    If ROM = nil then
      exit;

    Emu := EmuList.GetEmuForROM(Rom);

      Case Column of
        0:  If VTRoms.Header.Columns.Items[0].Options >= [coVisible] then
              CellText := ROM.name;
        1:  If VTRoms.Header.Columns.Items[1].Options >= [coVisible] then
              CellText := ROM.GameType;
        2:  If VTRoms.Header.Columns.Items[2].Options >= [coVisible] then
              CellText := ROM.path;
        3:  If VTRoms.Header.Columns.Items[3].Options >= [coVisible] then
              If (Settings.AddVersion) and
                 (Emu <> nil) and
                 (Emu.Version <> '') then
                CellText := ROM.emulator+' ('+Emu.Version+')'
              else
                CellText := ROM.emulator;
        4:  If VTRoms.Header.Columns.Items[4].Options >= [coVisible] then
            Begin
              if Emu <> nil then
                CellText := Emu.system
              else
                CellText := QP_UNKNOWN;
            end;

        5:  If VTRoms.Header.Columns.Items[5].Options >= [coVisible] then
              CellText := ROM.Year;
        6:  If VTRoms.Header.Columns.Items[6].Options >= [coVisible] then
              CellText := IntToStr(ROM.NumPlay);
        7:  If VTRoms.Header.Columns.Items[7].Options >= [coVisible] then
              CellText := ROM.Language;
        8:  If VTRoms.Header.Columns.Items[8].Options >= [coVisible] then
              CellText := ROM.Rating;
        9:  If VTRoms.Header.Columns.Items[9].Options >= [coVisible] then
              CellText := ROM.Parameters;
        10: If VTRoms.Header.Columns.Items[10].Options >= [coVisible] then
              CellText := IntToStr(ROM.IPSCount);
        11: If VTRoms.Header.Columns.Items[11].Options >= [coVisible] then
              CellText := ROM.Company;
        12: If VTRoms.Header.Columns.Items[12].Options >= [coVisible] then
            begin
              Comment := ROM.Comment;
              StrReplace(Comment, chr(13)+chr(10), ' ', [rfReplaceAll]);
              CellText := Comment;
            end;
        13: If VTRoms.Header.Columns.Items[13].Options >= [coVisible] then
              CellText := ROM.Multiplayer;
        14: If VTRoms.Header.Columns.Items[14].Options >= [coVisible] then
              CellText := uQPMiscTypes.ROMParametersStrings[ROM.ParameterMode];
        end;
  end
  else
  begin
    //its a filelist.
    ROM := TQPRom(GetObject(Sender, Sender.NodeParent[Node]));

    if (ROM <> nil) and (Column =0) then
      CellText := ROM.CompressedFiles[Node.Index]
    else
      CellText := '';
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTRomsGetImageIndex(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
  var Ghosted: Boolean; var ImageIndex: Integer);
Var
  IconName : String;
  NewIcon : TIcon;
  ROM : TQPROM;
  zStream : TMemoryStream;
begin

  if (Node <> nil) and (Sender.GetNodeLevel(Node)=0) and (Settings.UseImagesForROMs = true) and
     (Kind in [ikNormal, ikSelected]) and (Column = 0) then
  begin

    ROM := TQPRom(GetObject(Sender, Node));

    If (_MAMEIconsMode <> qmiOff ) then
    Begin

      //now check that the imagelist isnt bigger than the ROMS array
      If ROMIcons.Count > ROMlist.Count+1 then
        ClearROMIcons;

      //if the rom already has an image set, set it and then exit.
      if ROM.IconIndex <> -1 then
      Begin
        ImageIndex := ROM.IconIndex;
        exit;
      end;

      //get the filename for the associated icon.
        //Feature request #23 - alteration so we check whether Mamu made a clone icon, default to parent icon if not
      If ROM.MAMEName <> '' then
        begin
        if (_MAMEIconsList.IndexOf(ROM.MAMEName + '.ico') <> -1) then
          IconName := ROM.MAMEname + '.ico'
        //we can't really have a parent without a romname, but just in case, two conditions
        else if (ROM.ParentName <> '') and (_MAMEIconsList.IndexOf(ROM.ParentName + '.ico') <> -1) then
          IconName := ROM.ParentName + '.ico'
        end
      else //default to using filenameNoExt
          IconName := ChangeFileExt(ExtractFileName(ROM.path), '') + '.ico';

      //check to see if the icon is in the Cache.
      if (_MAMEIconsList <> nil) and (_MAMEIconsList.IndexOf(IconName) <> -1) then
      begin

        Case _MAMEIconsMode of
          qmiZip:
          begin
            zStream := TMemoryStream.Create;
            try

              uQPCompObj.Compression.UnCompressFileToStream(_MAMEIconsPath, IconName, zStream);
              if (zStream <> nil) and (zStream.Size > 0) then
              Begin

                NewIcon := TIcon.Create;
                try
                  NewIcon.LoadFromStream(zStream);
                  ROM.IconIndex := ROMIcons.AddIcon(NewIcon);
                  ImageIndex := ROM.IconIndex;
                finally
                  FreeAndNil(NewIcon);
                end;
              end
              else
              begin
                // Theres a weird bug where even though the file is in the zip
                // its not extracted first time.  But if you try again then
                // it will get extracted.. check for this bug and compensate
                // by making quickplay keep checking.
                ROM.IconIndex := -1;
                ImageIndex := -1;
              end;

            finally
              FreeAndNil(zStream);
            end;
          end; //end of qmiZip

          qmiDir:
          begin
            NewIcon := TIcon.Create;
            try
              NewIcon.LoadFromFile(_MAMEIconsPath + IconName);
              ROM.IconIndex := ROMIcons.AddIcon(NewIcon);
              ImageIndex := ROM.IconIndex;
            finally
              FreeAndNil(NewIcon);
            end;
          end; //end of qmidir.
        end;//end of CASE statement.
        
      end
      else
      begin
        //the icon is not in the cache, assign the default rom icon and leave it.
        ROM.IconIndex := 0;
        ImageIndex := 0;
      end;

    end //end of RealMAMEIcons Code.

    else
    begin // do a standard image icon based on whether or not the rom exists.
      if ROM.Exists = -1 then
        if (FileExists(ROM.path)) or ( (ROM.MAMEname <> '') and (DirectoryExists(ExtractFilePath(ROM.Path))) ) then
          ROM.Exists := 1
        else
          ROM.Exists := 0;

      if ROM.Exists = 1 then
        ImageIndex := 20
      else
        ImageIndex := 21;
    end;

  end;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTRomsGetPopupMenu(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; const P: TPoint;
  var AskParent: Boolean; var PopupMenu: TPopupMenu);
begin
  AskParent := False;
  if (Node <> nil) then
  begin
    Case Sender.GetNodeLevel(Node) of
      0:  PopupMenu := ROMPopUp; //Normal ROM popup
      1:  PopupMenu := ROMGMPopup; //GoodMerge Set Default popup
    end;
  end
  else
    PopupMenu := ROMPopupMini; // No rom selected popup.
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTRomsChange(Sender: TBaseVirtualTree;
  Node: PVirtualNode);
Var
  ROM : TQPRom;
  Emu : TQPEmu;
  NodeDown : PVirtualNode;
begin

  //center view ( fix )
  VTROMs.ScrollIntoView(Node, false);

  //lots of conditions to meet before we load any images.
  If (Node <> nil) and (pgMediaPanel.Visible) and
     (VTRoms.SelectedCount = 1) and (VTROMs.GetNodeLevel(Node) = 0) then
  Begin

    ROM := TQPRom(GetObject(Sender, Node));
    Emu := EmuList.GetEmuForROM(ROM);

    if GetSelectedFolder = '' then
      exit;

    TimerAutoMove.Enabled := False;
    _MediaSearch.BuildPageControl(@ROM, @Emu, nil);
    TimerAutoMove.Enabled := _MediaSearch.AutoMove;

  End;    
     
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTRomsHeaderClick(Sender: TVTHeader;  HitInfo: TVTHeaderHitInfo );

begin
  if HitInfo.Button = mbLeft then
  begin
    with Sender, Treeview do
    begin
      if SortColumn > NoColumn then
        Columns[SortColumn].Options := Columns[SortColumn].Options + [coParentColor];

        if (SortColumn = NoColumn) or (SortColumn <> HitInfo.Column) then
       begin
          SortColumn := HitInfo.Column;
          SortDirection := sdAscending;
        end
        else
          if SortDirection = sdAscending then
            SortDirection := sdDescending
          else
            SortDirection := sdAscending;

        SortTree(SortColumn, SortDirection, False);
    end;
  end;
end;


{-----------------------------------------------------------------------------}

procedure TMainFrm.VTRomsIncrementalSearch(Sender: TBaseVirtualTree;
  Node: PVirtualNode; const SearchText: WideString; var Result: Integer);
var
  sCompare1, sCompare2 : string;
  DisplayText : WideString;

begin
     VTRoms.IncrementalSearchDirection := sdForward;
     // Note: This code requires a proper Unicode/WideString comparation routine which I did not want to link here for
     // size and clarity reasons. For now strings are (implicitely) converted to ANSI to make the comparation work.
     // Search is not case sensitive.
      VTRomsGetText( Sender, Node, 0 {Column}, ttNormal, DisplayText );
      sCompare1 := SearchText;
      sCompare2 := DisplayText;

     // By using StrLIComp we can specify a maximum length to compare. This allows us to find also nodes
     // which match only partially. Don't forget to specify the shorter string length as search length.
     Result := StrLIComp( pchar(sCompare1), pchar(sCompare2), VTMin(Length(sCompare1), Length(sCompare2)) )

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTRomsFreeNode(Sender: TBaseVirtualTree;
  Node: PVirtualNode);
begin
  // I have NO idea if this is what im supposed to do at this point, do it anyway...
  if Sender.GetNodeLevel(Node)=0 then
    SetObject(Sender, Node,  nil);
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTRomsGetHint(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; var LineBreakStyle: TVTTooltipLineBreakStyle;
  var HintText: WideString);
var
  ROM : TQPRom;
begin
  //if the node is nil then exit and dont do anything.
  If (Node <>  nil) and (Sender.GetNodeLevel(Node)=0) then
  begin
    ROM := TQPRom(GetObject(Sender, Node));

    If ROM <> nil then
      //displays the hint for the ROM list.  Should maybe make this an option
      HintText := ROM.Summary;
  end;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTRomsCompareNodes(Sender: TBaseVirtualTree; Node1,
  Node2: PVirtualNode; Column: TColumnIndex; var Result: Integer);
var
  sys1, sys2 : TQPEmu;
  ROM1, ROM2 : TQPROM;
begin
{0-name
 1-GameType
 2-Path
 3-Emulator
 4-System
 6-Number of times played
 7-Language
 8-Rating
 9-Parameters
 10-number of IPS associated
 11-Company
 12-Comment
 13-Players
 14-Parameter Mode}
  If (Node1 <> nil) and (Node2 <> nil) and (Sender.GetNodeLevel(Node1) = 0) and (Sender.GetNodeLevel(Node2) =0)then
  begin 
  ROM1 := TQPRom(GetObject(Sender, Node1));
  ROM2 := TQPRom(GetObject(Sender, Node2));

  begin
  case Column of

    0:Result := CompareText(ROM1.name, ROM2.name);
    1:Result := CompareText(ROM1.GameType, ROM2.GameType);
    2:Result := CompareText(ROM1.path, ROM2.path);
    3:Result := CompareText(ROM1.emulator, ROM2.emulator);
    4:Begin
      Sys1 := EmuList.GetEmuForROM(ROM1);
      Sys2 := EmuList.GetEmuForROM(ROM2);
      if (Sys1 <> nil) and (Sys2 <> nil) then
        Result := CompareText(Sys1.System, Sys2.System);
      end;
    5:Result := CompareText(ROM1.Year, ROM2.Year);
    6:Result := ROM1.NumPlay - ROM2.NumPlay;
    7:Result := CompareText(ROM1.Language, ROM2.Language);
    8:Result := CompareText(ROM1.Rating, ROM2.Rating);
    9:Result := CompareText(ROM1.Parameters, ROM2.Parameters);
    10:Result := (ROM1.IPSCount)-(ROM2.IPSCount);
    11:Result := CompareText(ROM1.Company, ROM2.Company);
    12:Result := CompareText(ROM1.Comment, ROM2.Comment);
    13:Result := CompareText(Rom1.Multiplayer, ROM2.Multiplayer);
    14:Result := Integer(ROM1.ParameterMode) - Integer(ROM2.ParameterMode);
  end;
  end;//end of WITH block

  end;//end of Node<>nil check

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTRomsKeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
   var cur : smallint;
begin

  If (VTRoms.FocusedNode <> nil) then
  begin
    case key of
      VK_DELETE : if VTROMS.GetNodeLevel(VTRoms.FocusedNode)=0 then
                    ActDelROM.Execute;
      VK_RETURN : begin
                    if (VTROMS.IsEditing) then
                    begin
                      VTROMS.EndEditNode;
                      VTROMS.SetFocus;
                    end
                    else
                    begin
                      _KeyPress := True;
                      ActRunROM.Execute;
                    end;
                  end;
      VK_UP : begin

              end;

      VK_DOWN:begin
              end;
    end;

  end;

  Case key of
    VK_Home : begin
                VTRoms.Selected[VTRoms.GetFirst()] := True;
                VTRoms.FocusedNode := VTRoms.GetFirst;
              end;
    VK_End :  begin
                VTRoms.Selected[VTRoms.GetLast()] := True;
                VTRoms.FocusedNode := VTRoms.GetLast;
              end;
  end;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTRomsEditing(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; var Allowed: Boolean);
begin
  {0-name
 1-GameType
 2-Path
 3-Emulator
 4-System
 5- year
 6-Number of times played
 7-Language
 8-Rating
 9-Parameters
 10-number of IPS associated
 11-Company
 12-Comment
 13-Players
 14-Paramter Mode}
  If ( Sender.GetNodeLevel(Node)=0 ) and
     (Column in [0, 1, 2, 3, 5, 7, 8, 9, 11, 12, 13, 14]) then
    Allowed := True
  else
    Allowed := False;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTRomsInitChildren(Sender: TBaseVirtualTree;
  Node: PVirtualNode; var ChildCount: Cardinal);
var
  FileList : TStringList;
  ROM : TQPROM;
  i : Integer;
begin
  if Node <> nil then
  begin
    FileList := TStringList.Create;
    try
      ROM := TQPROM(GetObject(Sender, Node));
      if (ROM <> nil) and (FileExists(ROM.Path)) then
      begin
        uQPCompObj.Compression.ListContentsOfFile(TStrings(FileList), ROM.Path);
          //if the good merge [!] option is anabled use it
        if _GoodMergeEXCL then
          begin
           For i := FileList.Count-1 downto 0 do //loop all and look for [!]
              if JCLStrings.StrIPos('[!]', FileList[i]) = 0 then
              begin
                FileList.Delete(i); //delete items
              end;
          end;
        if FileList.Count = 0 then Filelist.Add('  There are no files in which have [!] in them... Open folder options to turn off this feature. ')  ;

        Filelist.Sort;
        ROM.CompressedFiles.AddStrings(FileList);
        for i := 0 to FileList.Count-1 do
          VTROMS.AddChild(Node);
      end;
      ChildCount := VTROMS.ChildCount[Node];

    finally
      FreeAndNil(FileList);
    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTRomsMouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  _RomPoint.X := x;
  _ROMpoint.Y := Y;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTRomsExit(Sender: TObject);
begin
  if VTRoms.IsEditing then
    VTRoms.EndEditNode;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTRomsNewText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; NewText: WideString);
begin
  If (Node <> nil) and (Sender.GetNodeLevel(Node) = 0) then
  begin

    case Column of
      0 : If NewText <> '' then
            TQPRom(GetObject(Sender,Node)).Name := NewText;
      1 : TQPRom(GetObject(Sender,Node)).GameType := NewText;
      2 : If NewText <> '' then
            TQPRom(GetObject(Sender,Node)).Path := NewText;
      3 : TQPRom(GetObject(Sender,Node)).Emulator := NewText;
      5 : TQPRom(GetObject(Sender,Node)).Year := NewText;
      7 : TQPRom(GetObject(Sender,Node)).Language := NewText;
      8 : TQPRom(GetObject(Sender,Node)).Rating := NewText;
      9 : TQPRom(GetObject(Sender,Node)).Parameters := NewText;
      11: TQPRom(GetObject(Sender,Node)).Company := NewText;
      12: TQPRom(GetObject(Sender,Node)).Comment := NewText;
      13: TQPRom(GetObject(Sender, Node)).Multiplayer := NewText;
      14: TQPROM(GetObject(Sender, Node)).ParameterMode := TROMParametersMode(StrToInt(NewText));      
    end;

    ROMlist.SaveToFile();
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTRomsCreateEditor(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; out EditLink: IVTEditLink);
begin
{0-name
 1-GameType
 2-Path
 3-Emulator
 4-System
 5-year
 6-Number of times played
 7-Language
 8-Rating
 9-Parameters
 10-number of IPS associated
 11-Company
 12-Comment
 13-Players
 14-Parameter Mode}
  Case Column of
    0:  EditLink := TQPVTEdit.Create(qpeEdit);
    1:  EditLink := TQPVTEdit.Create(qpeComboType);
    2:  EditLink := TQPVTEdit.Create(qpeFileEdit);
    3:  EditLink := TQPVTEdit.Create(qpeComboEmu);
    5:  EditLink := TQPVTEdit.Create(qpeEdit);
    7:  EditLink := TQPVTEdit.Create(qpeComboLang);
    8:  EditLink := TQPVTEdit.Create(qpeComboRating);
    9:  EditLink := TQPVTEdit.Create(qpeEdit);
    11: EditLink := TQPVTEdit.Create(qpeEdit);
    12: EditLink := TQPVTEdit.Create(qpeEdit);
    13: EditLink := TQPVTEdit.Create(qpeEdit);
    14: EditLink := TQPVTEdit.Create(qpeROMParamMode);
  end;
end;

{------------- end of code for VTRoms treeview ------------------------}

{------------------------start of code for virtual directory tree ------}

procedure TMainFrm.VTdirInitNode(Sender: TBaseVirtualTree; ParentNode,
  Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
var
  CurFol : TQPDir;
  NewIcon : Integer;
begin
  //this code initialises the VTdir Treeview nodes

  //work out what way the user wants to handle folder expands/collapsed state.

  //first check if its a root node.
  if ParentNode = nil then
  begin
    //this is a root node.
    SetObject(Sender, Node, DirList[Node.Index]);
    if Settings.FolderExpandMode <> qfeNone then
      Include(InitialStates, ivsExpanded);
  end
  else
  begin
    if Settings.FolderExpandMode = qfeFull then
      Include(InitialStates, ivsExpanded);
  end;

  CurFol := TQPDir(GetObject(Sender, Node));

  //for the directory listing we want it expanded.
  if HasSubDirs(CurFol.FullPath) then
    Include(InitialStates, ivsHasChildren);

  NewIcon := TreeImages(CurFol.FullPath+'folders.ini');
  If NewIcon <> -1 then
  begin
    CurFol.CustomIcon := True;
    CurFol.NormalIcon := NewIcon;
    CurFol.SelIcon := NewIcon;
    If FDirHeight < 24 then
      Sender.NodeHeight[Node] := 24
    else
      Sender.NodeHeight[Node] := FDirHeight;
  end
  else
    Sender.NodeHeight[Node] := FDirHeight;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTdirInitChildren(Sender: TBaseVirtualTree;
  Node: PVirtualNode; var ChildCount: Cardinal);
var
  CurFol : TQPDir;
  OldStyle : TCursor;
begin

  CurFol := TQPDir(GetObject(Sender, Node));
  //first point to consider, there are 3 parts of this tree
  //part 1 - the directory listing
  //part 2 - The Virtual Folders
  //part 3 - the 'open' emulator filtering.
  //so check for this by checking the value of emu.
  OldStyle := Screen.Cursor;
  Screen.Cursor := crHourGlass;
  VTDir.BeginUpdate;
  try
    ChildCount := InitialiseDirectory(CurFol, Node);
   // ChildCount := Sender.ChildCount[Node];

    // finally sort node
    if ChildCount > 0 then
      Sender.Sort(Node, 0, TVirtualStringTree(Sender).Header.SortDirection, False);
  finally
    VTDir.EndUpdate;
    Screen.Cursor := OldStyle;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTdirGetImageIndex(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
  var Ghosted: Boolean; var ImageIndex: Integer);
var
  CurFol : TQPDir;
begin
  If Node = nil then
    exit;

  CurFol := TQPDir(GetObject(Sender, Node));

  If not CurFol.CustomIcon then
  begin
    case Kind of
      ikNormal: ImageIndex := CurFol.NormalIcon;
      ikSelected: ImageIndex := CurFol.SelIcon;
    end;
  end
  else
  begin
    case Kind of
      ikState:ImageIndex := CurFol.NormalIcon;
    end;
  end;
  
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTdirGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin
  if node = nil then
    exit;

  //the only data output is the display for each node so no case statements needed
  CellText := TQPDir(GetObject(Sender, Node)).DisplayText;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTdirFreeNode(Sender: TBaseVirtualTree;
  Node: PVirtualNode);
begin
  // I have NO idea if this is what im supposed to do at this point, do it anyway...
  SetObject(Sender, Node,  nil);
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTdirGetHint(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; var LineBreakStyle: TVTTooltipLineBreakStyle; var HintText: WideString);
Var
  CurFol : TQPDir;
begin
  // this procedure draws the item node hint on mouseover.
  // for directories - show the directory.
  if node <> nil then
  begin
    CurFol := TQPDir(GetObject(Sender, Node));
    HintText := CurFol.FullPath
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTdirChange(Sender: TBaseVirtualTree; Node: PVirtualNode);
Var
  CurFol : TQPDir;
  OldStyle : TCursor;
  Sys : String;
  tmpROM : TQPROM;
  tmpEmu : TQPEmu;
begin

  If (Node <> nil)  then
  begin
  //center view ( fix )
  VTdir.ScrollIntoView(Node, false);

    //this code is called whenever the user changes the selected directory

    CurFol := TQPDir(GetObject(Sender, Node));

    If CurFol <> nil then
    begin

      If Settings.ClearFilter then
      begin
        TxtFilter.Text := '';
        FFilterString := '';
      end;

      OldStyle := Screen.Cursor;
      Screen.Cursor := crHourGlass;
      try

        //disable the media panel slideshow
        TimerAutoMove.Enabled := False;
        SetupROMSFolder(CurFol, Node);

        if _MediaSearch.DefaultFolderImg = jfiQPLogo then
          _MediaSearch.BuildPageControl(nil, nil, nil)
        else
        begin
          //the user wants a tab based on roms.. take the first rom and
          //try to work out the system from it.
          Sys := '';
          if VTROMS.RootNodeCount > 0 then
          begin
            tmpROM := TQPROM(GetObject(VTROMS, VTROMS.GetFirst));
            if TmpROM <> nil then
            begin
              TmpEmu := EmuList.GetEmuForROM(tmpROM);
              if TmpEmu <> nil then
                Sys := TmpEmu.System;
            end;
          end;

          _MediaSearch.BuildPageControl(Sys);
        end;
        
      finally
        Screen.Cursor := OldStyle;
      end;
    end;
  end;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTdirGetPopupMenu(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; const P: TPoint;
  var AskParent: Boolean; var PopupMenu: TPopupMenu);
begin

  If Node <> nil then
  begin
    PopupMenu := DirPopUp;
  end
  else
    PopupMenu := nil;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTdirCompareNodes(Sender: TBaseVirtualTree; Node1,
  Node2: PVirtualNode; Column: TColumnIndex; var Result: Integer);
var
  Dir1, Dir2 : TQPDir;
begin
  Dir1 := TQPDir(GetObject(Sender, Node1));
  Dir2 := TQPDir(GetObject(Sender, Node2));
  Result := CompareText(Dir1.DisplayText, Dir2.DisplayText);
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTdirDragDrop(Sender: TBaseVirtualTree;
  Source: TObject; DataObject: IDataObject; Formats: TFormatArray;
  Shift: TShiftState; Pt: TPoint; var Effect: Integer; Mode: TDropMode);
var
  DropNode, rNode : PVirtualNode;
  DropFol : TQPDir;
  Txtfile : String;
  TmpRoms, TmpList : TQPROMlist;
  I, NewIndex : integer;
begin

  if DataObject = nil then
  begin
    // VCL drag'n drop. 
    if Source = VTRoms then
    begin

      VTRoms.BeginUpdate;

      DropNode := VTdir.GetNodeAt(pt.X,Pt.Y);
      DropFol := TQPDir(GetObject(VTdir, DropNode));
      if (DropNode = nil) then
        exit;

      Effect := DROPEFFECT_COPY;
      TxtFile := DropFol.FullPath + DefaultFileName;

      TmpRoms := TQPROMlist.Create(Settings.AllowWrite);
      TmpList := TQPROMlist.Create(Settings.AllowWrite);

      //get all the selected nodes from the VTRoms and store them temporarily
      rNode := VTRoms.GetFirstSelected;

      while rNode <> nil do
      begin
        NewIndex := TmpRoms.Add(TQPRom.Create);
        TmpRoms[NewIndex].Assign(TQPRom(GetObject(VTRoms, rNode)));
        ROMlist.Remove(TQPRom(GetObject(VTroms, rNode)));
        rNode := VTRoms.GetNextSelected(rNode);
      end;

      //now write the current ROMS file to disk, to get rid of moved roms
      ROMlist.SaveToFile();
      TmpList.LoadFromFile(txtFile);

      //now copy all the roms that were dropped into the list containing
      //the destination roms.
      for i := 0 to TmpRoms.Count-1 do
      begin
        NewIndex := TmpList.Add(TQPRom.Create);
        TmpList[NewIndex].Assign(TmpRoms[i]);
      end;

      TmpRoms.Clear;
      FreeAndNil(TmpRoms);
      TmpList.FileName := txtfile;
      TmpList.SaveToFile();
      TmpList.Clear;
      FreeAndNil(TmpList);

      //now we need to redraw the current romlisting to get
      //rid of the roms we dragged and dropped.
      FillRoms(GetSelectedTxt);

      VTRoms.EndUpdate;

    end; //end of IF source = VTRoms

  end;  //end of IF dataobject = nil

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTdirDragOver(Sender: TBaseVirtualTree;
  Source: TObject; Shift: TShiftState; State: TDragState; Pt: TPoint;
  Mode: TDropMode; var Effect: Integer; var Accept: Boolean);
var
  DropNode : PVirtualNode;
  CurDir : TQPDir;
begin
  Accept := False;
  if (Source = VTRoms) then
  begin
    DropNode := Sender.GetNodeAt(PT.X, PT.Y);
    CurDir := TQPDir(GetObject(Sender, DropNode));
    if (CurDir <> nil) then
      Accept := True; 
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTdirEditing(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; var Allowed: Boolean);
begin
  If Node <> nil then
    Allowed := true;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTdirExit(Sender: TObject);
begin
  if VTDir.IsEditing then
    VTDir.EndEditNode;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTdirKeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
  If (VTDir.FocusedNode <> nil) and (Key = VK_DELETE) then
    ActDelFol.Execute;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTdirNewText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; NewText: WideString);
var
  Parent, aNode : PVirtualNode;
  CurDir : TQPDir;
  NewDir : String;
  Exists : Boolean;
begin
  If (Node <> nil) and (NewText <> '') then
  begin
    CurDir := TQPDir(GetObject(Sender, Node));
    Parent := Sender.NodeParent[Node];
    Exists := False;

    //first of all find out if the new name is already used in the parent folder.
    If Sender.ChildCount[Parent] > 1 then
    begin

      aNode := Sender.GetFirstChild(Parent);
      While aNode <> nil do
      begin
        if strCompare(TQPDir(GetObject(Sender, aNode)).DisplayText, NewText)=0 then
        Begin
          Exists := True;
          aNode := nil;
        end
        else
          aNode := Sender.GetNextSibling(aNode);
      end;

    end;

    //if the name is not already used, do the renaming.
    If not Exists then
    begin
      Sender.BeginUpdate;
      try

        //work out the new directory name.
        if Sender.GetNodeLevel(Node) = 0 then
          //the node is a root node, its parent is nil so trying to read it
          //will cause an error.
          NewDir := Settings.Paths.RomsDir
        else
          //its not a root node, we can safely use the parent node.
          NewDir := TQPDir(GetObject(Sender, Parent)).FullPath;

        NewDir := includeTrailingPathDelimiter(NewDir + NewText);

        RenameFile(CurDir.FullPath, NewDir);
        CurDir.DisplayText := NewText;
        CurDir.FullPath := NewDir;
      finally
        Sender.EndUpdate;
      end;
    end;
  end;

end;

{------------------------end of code for virtual directory tree ---------}


procedure TMainFrm.jvDropROMDragDrop(Sender: TJvDropTarget;
  var Effect: TJvDropEffect; Shift: TShiftState; X, Y: Integer);
var
  inFiles : TStringList;
begin

  Effect := deLink;

  inFiles := TStringList.Create;
  try
    Sender.GetFilenames(inFiles);
    ROMList.AddFromStrings(inFiles, '', '', lmNone, False);
    FillRoms(GetSelectedTxt);
  finally
    FreeAndNil(inFiles);
  end;
  
end;

procedure TMainFrm.Label1Click(Sender: TObject);
begin

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.jvDropROMDragAccept(Sender: TJvDropTarget;
  var Accept: Boolean);
begin
  Accept := True;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ChkEmuBySysClick(Sender: TObject);
begin
  InitEmuTree();
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTEmusInitChildren(Sender: TBaseVirtualTree;
  Node: PVirtualNode; var ChildCount: Cardinal);
var
  ChildNode: PVirtualNode;
  I : Integer;
  CurSys : TQPSystem;
  CurEmu : TQPEmu;
begin
  if Node <> nil then
  begin
  VTEmus.BeginUpdate;
  try
    CurSys := TQPSystem(GetObject(Sender, Node));

    //loop through all systems and add each one as a child.
    For i := 0 to EmuList.Count-1 do
    Begin
      CurEmu := EmuList.items[i];
      If StrCompare(CurEmu.System, CurSys.Name)=0 then
      begin

        ChildNode := Sender.AddChild(Node);
        SetObject(Sender, ChildNode, CurEmu);
        VTEmus.NodeHeight[ChildNode] := 24;
        Sender.ValidateNode(Node, False);
      end;
    end;

    //the childcount is the amount of nodes we just added
    ChildCount := Sender.ChildCount[Node];

  finally
    //end the update cycle and refresh the tree.
    VTEmus.EndUpdate;
  end;

  end;//end of Node<>nil check
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTEmusInitNode(Sender: TBaseVirtualTree; ParentNode,
  Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
var
  CurSys : TQPSystem;
begin
  If Node <> nil then  //make sure the node isnt nil.
  If ChkEmuBySys.Checked then
  begin
    //we want the emulators listed by system
    if VTEmus.GetNodeLevel(node) = 0 then
    begin
      SetObject(Sender, Node, SystemList.Items[Node.Index]);
      CurSys := TQPSystem(GetObject(Sender, Node));

      // use the GetEmulatorsFromSystem function to determine if
      // this system will have any child nodes.
      CurSys.TotalEmus := EmuList.TotalForSystem(CurSys.Name);
      If CurSys.TotalEmus <> 0 then
        Include(InitialStates, ivsHasChildren);
    end;
  end
  else
  begin
    //we want a flat emulator listing.
    SetObject(Sender, Node, EmuList[Node.Index]);
  end;

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTEmusGetPopupMenu(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; const P: TPoint;
  var AskParent: Boolean; var PopupMenu: TPopupMenu);
begin
  AskParent := False;
  PopupMenu := nil;
  if Node <> nil then
    if ChkEmuBySys.Checked then
    begin
      //its in folders mode, only show the popup if its nodelevel =1
      if Sender.GetNodeLevel(Node) = 1 then
        PopupMenu := Self.PopupEmu;
    end
    else
      PopupMenu := Self.PopupEmu;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTEmusGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
var
  CurSys : TQPSystem;
begin
  If Node <> nil then
  if ChkEmuBySys.Checked then
  begin
    If VTEmus.GetNodeLevel(node) = 0 then
    begin
      //for the system i want to output the system name AND
      //how many emulators are in this system (if its not 0)
      CurSys := TQPSystem(GetObject(Sender, Node));
      If CurSys.TotalEmus = 0 then
        CellText := CurSys.Name
      else
        CellText := CurSys.Name + ' (' + IntToStr(CurSys.TotalEmus) + ')';
    end
    Else
      CellText := TQPEmu(GetObject(Sender, Node)).Name;
  end
  else
  begin
    CellText := TQPEmu(GetObject(Sender, Node)).Name;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTEmusFocusChanging(Sender: TBaseVirtualTree; OldNode,
  NewNode: PVirtualNode; OldColumn, NewColumn: TColumnIndex;
  var Allowed: Boolean);
var
  Find : ThhFindFile;
  i : Integer;
  FileList : TStringList;
  App : TQPExe;
begin
  //adds all files in the emu/tool directory to the thumbview
  Allowed := (NewNode <> OldNode) and (NewNode <> nil);

  if (Allowed) and (pgMediaPanel.Visible) then
  begin
    if Sender = VTEmus then
    begin
        if not ChkEmuBySys.Checked then
          //flat view mode
          App := TQPExe(GetObject(Sender, NewNode))
        else
          //sorted by system.
          if Sender.GetNodeLevel(NewNode) = 1 then
            App := TQPExe(GetObject(Sender, NewNode))
          else
            App := nil; //its a folder, bomb out.
    end else if Sender = vtTools then
    begin
      App := TQPExe(GetObject(Sender, NewNode))
    end
    else
      App := nil;

    if App <> nil then
    begin
      Find := ThhFindFile.Create(Self);
      try
        Find.Filter := '*.*';
        Find.Directory := ExtractFilePath(App.Path);
        Find.Recurse := False;
        Find.Execute;
        //create the stringlist to hold the temporary filelist
        FileList := TStringList.Create;
        try
          for i := 0 to Find.TotalFile-1 do
            if StrCompare(Find.Files[i], App.Path)<>0 then
              FileList.Add(Find.files[i]);

        {  if FileList.Count > 0 then
            Self.AddToThumbView(FileList)
          else
            ResetImage();     }
            
        finally
          FreeAndNil(FileList);
        end;
        
      finally
        FreeAndNil(Find);
      end;
    end  //end of App <> nil
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTEmusGetImageIndex(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
  var Ghosted: Boolean; var ImageIndex: Integer);
Var
  CurrEmu : TQPEmu;
begin
  If Node <> nil then
  If not ChkEmuBySys.Checked then
  begin
    //flat view, all emulators are listed.
    CurrEmu := TQPEmu(GetObject(Sender, Node));
    if CurrEmu.IconIndex = -1 then
      Case Kind of
        ikNormal:ImageIndex := 2;
        ikSelected: ImageIndex := 2;
      end
    else
      case Kind of
        ikState:ImageIndex := CurrEmu.IconIndex;
      end;
  end
  else
    If VTEmus.GetNodeLevel(node) = 0 then
    begin
      //ImageIndex := 0
      Case Kind of
        ikNormal:ImageIndex := 0;
        ikSelected: ImageIndex := 1;
      end
    end
    else
    begin
      //its the emulator node in the 'folder' view.
      CurrEmu := TQPEmu(GetObject(Sender, Node));
      if CurrEmu.IconIndex = -1 then
        Case Kind of
          ikNormal:ImageIndex := 2;
          ikSelected: ImageIndex := 2;
        end
      else
        case Kind of
          ikState:ImageIndex := CurrEmu.IconIndex;
        end;
    end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTEmusDblClick(Sender: TObject);
var
  MyEmu : TQPEmu;
  TmpOpt : TQPRunOptions;
begin
  MyEmu := nil;
  If VTEmus.FocusedNode <> nil then
  begin
    if ChkEmuBySys.Checked then
    begin
      if (VTEmus.GetNodeLevel(VTEmus.FocusedNode)=1) then
        MyEmu := TQPEmu(GetObject(VTEmus, VTEmus.FocusedNode));
    end
    else
      MyEmu := TQPEmu(GetObject(VTEmus, VTEmus.FocusedNode));

    If MyEmu <> nil then
    begin
      if FileExists(MyEmu.Path) then
      begin

        TmpOpt.GeneralPowerScheme := QP_DONT_CHANGE;

        MyEmu.MameConfigCheck;
        MyEmu.WaitForEXEEnd := False;
        MyEmu.Run(nil, Self.ToolList, TmpOpt);
        MyEmu.WaitForEXEEnd := True;
      end
      else
        MessageDlg(J_FILE_NOT_EXIST, mtError, [mbOK], poMainFormCenter);
    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTEmusCompareNodes(Sender: TBaseVirtualTree; Node1,
  Node2: PVirtualNode; Column: TColumnIndex; var Result: Integer);
var
  Emu1, Emu2 : TQPEmu;
  Sys1, Sys2 : TQPSystem;
begin
  if (Node1 <> nil) and (Node2 <> nil) then
  begin
  
  if ChkEmuBySys.Checked then
  begin
    If (Sender.GetNodeLevel(Node1) = 0) and
       (Sender.GetNodeLevel(Node2) = 0) then
    begin
      Sys1 := TQPSystem(GetObject(Sender, Node1));
      Sys2 := TQPSystem(GetObject(Sender, Node2));
      Result := CompareText(Sys1.Name, Sys2.Name);
    end
    else
      If (Sender.GetNodeLevel(Node1) = 1) and
         (Sender.GetNodeLevel(Node2) = 1) then
      begin
        Emu1 := TQPEmu(GetObject(Sender, Node1));
        Emu2 := TQPEmu(GetObject(Sender, Node2));
        Result := CompareText(Emu1.Name, Emu2.Name);
      end;
  end
  else
  begin
    Emu1 := TQPEmu(GetObject(Sender, Node1));
    Emu2 := TQPEmu(GetObject(Sender, Node2));
    Result := CompareText(Emu1.Name, Emu2.Name);
  end;

  end;//end of node nil check.
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTSearchesGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin
  CellText := SearchList.Names[Node.Index];
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTSearchesGetImageIndex(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
  var Ghosted: Boolean; var ImageIndex: Integer);
begin
  if Node <> nil then
    ImageIndex := 3;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTSearchesFocusChanging(Sender: TBaseVirtualTree; OldNode,
  NewNode: PVirtualNode; OldColumn, NewColumn: TColumnIndex;
  var Allowed: Boolean);
begin
  if (NewNode <> nil) and (OldNode <> NewNode) then
  begin
    SetupSearchFolder(NewNode);
    _MediaSearch.BuildPageControl(nil, nil, nil);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTSearchesGetPopupMenu(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; const P: TPoint;
  var AskParent: Boolean; var PopupMenu: TPopupMenu);
begin
  if Node <> nil then
    PopupMenu := PopupVirtual;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTSearchesExit(Sender: TObject);
begin
  if VTSearches.IsEditing then
    VTSearches.EndEditNode;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTSearchesEditing(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; var Allowed: Boolean);
begin
  If Node <> nil then
    Allowed := true;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.VTSearchesNewText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; NewText: WideString);
var
  NewName, OldPath, NewFullPath : String;
  Exists : Boolean;
  i : Integer;
begin
  If (Node <> nil) and (NewText <> '') then
  begin
    Exists := False;

    NewName := NewText;
    OldPath := SearchList.ValueFromIndex[Node.Index];
    NewFullPath := ExtractFilePath(OldPath) + NewName + '.qpq';
    //check that the newly renamed file doesnt already exist.
    for i := 0 to SearchList.Count-1 do
    begin
      if StrCompare(NewFullPath, SearchList.ValueFromIndex[i]) = 0 then
      begin
        Exists := True;
        break;
      end;
    end;

    If not Exists then
    begin
      RenameFile(OldPath, NewFullPath);
      InitSearchTree();
      if FileExists(ChangeFileExt(OldPath, '.tmp')) then
        DeleteFile(ChangeFileExt(OldPath, '.tmp'));
    end;
  end;
end;


{-----------------------------------------------------------------------------}
{ vtTools Code }

procedure TMainFrm.vtToolsChange(Sender: TBaseVirtualTree; Node: PVirtualNode);
//the idea here was to make the tool show info in the thumb nails and info tab
// I failed!

//    var
//  tmpStrings : TStrings;
//    _TextOpt : TFont;
//    pgc : TPageControl;
//    pth,fileName : string;
//    i : Integer;
//    MediaTab : TJMediaTab;
begin
//    MediaTab.PopulateTabSimple( 0);
//not getting this...

end;

procedure TMainFrm.vtToolsCompareNodes(Sender: TBaseVirtualTree; Node1,
  Node2: PVirtualNode; Column: TColumnIndex; var Result: Integer);

begin
  if (Node1 <> nil) and (Node2 <> nil) then
    Result := CompareText(TQPTool(GetObject(Sender, Node1)).Name, TQPTool(GetObject(Sender, Node2)).Name);
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.vtToolsDblClick(Sender: TObject);
var
  HitNode : PVirtualNode;
  Hit : THitInfo;
  Tool : TQPTool;
begin
  VTTools.GetHitTestInfoAt(_ToolPt.X, _ToolPt.Y, True, Hit);
  HitNode := Hit.HitNode;
  if (HitNode <> nil) and (not (hiOnItemButton in Hit.HitPositions)) then
  begin
    Tool := TQPTool(GetObject(VTTools, HitNode));
    if FileExists(Tool.Path) then
      Tool.Run()
    else
      MessageDlg(J_FILE_NOT_EXIST, mtError, [mbOK], poMainFormCenter);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.vtToolsGetImageIndex(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
  var Ghosted: Boolean; var ImageIndex: Integer);
begin
  if Node <> nil then
    ImageIndex := TQPTool(GetObject(Sender, Node)).IconIndex;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.vtToolsGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin
  if Node <> nil then
    CellText := TQPTool(GetObject(Sender, Node)).Name;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.vtToolsMouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  _ToolPt.X := X;
  _ToolPt.Y := Y;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.vtToolsGetPopupMenu(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; const P: TPoint;
  var AskParent: Boolean; var PopupMenu: TPopupMenu);
begin
  AskParent := False;
  if Node <> nil then
    PopupMenu := PopupTools
  else
    PopupMenu := nil;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActUtilityDeleteExecute(Sender: TObject);
begin
  if VTTools.FocusedNode <> nil then
  begin
    VTTools.BeginUpdate;
    try
      ToolList.Remove(TQPTool(GetObject(VTTools, VTTools.FocusedNode)));
      ToolList.SaveToFile();
      VTTools.DeleteSelectedNodes();
    finally
      VTTools.EndUpdate;
    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActUtilityNewExecute(Sender: TObject);
var
  FrmTool : TFrmToolCfg;
  NewIndex : Integer;
begin
  FrmTool := TFrmToolCfg.Create(self);
  try
    if FrmTool.ShowModal = mrOK then
    begin
      NewIndex := ToolList.Add(TQPTool.Create);
      ToolList[NewIndex].Assign(FrmTool.EditTool);
      ToolList.SaveToFile();
      Self.InitToolTree();
    end;
  finally
    FreeAndNil(FrmTool);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActUtilityEditExecute(Sender: TObject);
var
  FrmTool : TFrmToolCfg;
begin
  if VTTools.FocusedNode <> nil then
  begin
    VTTools.BeginUpdate;
    try
      FrmTool := TFrmToolCfg.Create(Self);
      try
        FrmTool.SetEditTool(TQPTool(GetObject(VTTools, VTTools.FocusedNode)));
        if FrmTool.ShowModal = mrOK then
        begin
          TQPTool(GetObject(VTTools, VTTools.FocusedNode)).Assign(FrmTool.EditTool);
          ToolList.SaveToFile();
        end;
      Finally
        FreeAndNil(FrmTool);
      end;
    finally
      VTTools.EndUpdate;
    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.ActUtilityWWWExecute(Sender: TObject);
var
  MyTool : TQPTool;
begin
  if VTTools.FocusedNode <> nil then
  begin
    //Check what mode the vtemus tree is in.
    MyTool := TQPTool(GetObject(VTTools, VTTools.FocusedNode));

    if MyTool <> nil then
      MyTool.OpenHomePage();
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.MnuROMsidebarClick(Sender: TObject);
begin
  pgSideBar.ActivePageIndex := 0;  
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.MnuSearchSideBarClick(Sender: TObject);
begin
  pgSideBar.ActivePage := TabSearches;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.MnuEmuSideBarClick(Sender: TObject);
begin
  pgSideBar.ActivePageIndex := 2;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.MnuToolSidebarClick(Sender: TObject);
begin
  pgSideBar.ActivePageIndex := 3;
end;

procedure TMainFrm.pgSideBarChange(Sender: TObject);
begin

end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.actAppearanceOptionsExecute(Sender: TObject);
var
  Opt : TFrmAppearanceOptions;
    ROMfont, DirFont, OldLayout : Integer;
begin
  Opt := TFrmAppearanceOptions.Create(self);
  try
    ROMfont := VTRoms.Font.Size;
    DirFont := VTDir.Font.Size;
    OldLayout := _WindowLayout;

    if Opt.ShowModal = mrOK then
    begin

      If (ROMfont <> VTRoms.Font.Size) or (DirFont <> VTDir.Font.Size) then
        RefreshAll();

      if OldLayout <> _WindowLayout then
        ChangeLayout();

      SetVTWallpapers();

    end;
  finally
    FreeAndNil(Opt);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.actMediaOptionsExecute(Sender: TObject);
var
  Opt : TFrmMediaPanelOptions;
begin
  Opt := TFrmMediaPanelOptions.Create(self);
  try
    Opt.MS := _MediaSearch;

    if Opt.ShowModal = mrOK then
    begin
      //save changes
      _MediaSearch.SaveConfig();
      _MediaSearch.SaveTabs();
      _MediaSearch.SaveSystems;
    end
    else
    begin
      //the form was cancelled, reload old data.
      _MediaSearch.LoadConfig();
      _MediaSearch.LoadTabs();
      _MediaSearch.LoadSystems();
    end;

    //check if the tab automove is still enabled.
    if _MediaSearch.AutoMove then
    begin
      TimerAutoMove.Interval := _MediaSearch.TimePerTab * 1000;
      TimerAutoMove.Enabled := True;
    end
    else
      TimerAutoMove.Enabled := False;

  finally
    FreeAndNil(Opt);
  end;
end;
                                          
{-----------------------------------------------------------------------------}

procedure TMainFrm.actDeleteSearchExecute(Sender: TObject);
begin
  if (VTSearches.GetFirstSelected <> nil) then
  if (MessageDlg(J_DIRECTORY_VERIFY_DELETE, mtConfirmation, [mbYes, mbNo], poMainFormCenter) = mrYes) then
  begin

    DeleteFile(SearchList.ValueFromIndex[VTSearches.GetFirstSelected.Index]);
    if FileExists(ChangeFileExt(SearchList.ValueFromIndex[VTSearches.GetFirstSelected.Index], '.tmp')) then
      DeleteFile(ChangeFileExt(SearchList.ValueFromIndex[VTSearches.GetFirstSelected.Index], '.tmp'));
    InitSearchTree();
    VTSearches.Selected[VTSearches.GetFirst] := True;
    VTSearches.FocusedNode := VTSearches.GetFirst;

  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.TimerAutoMoveTimer(Sender: TObject);
var
  NextTab : Integer;
  CurrentTab : Integer;
begin

  if pgMediaPanel.PageCount < 2 then
    TimerAutoMove.Enabled := False
  else
  begin

    NextTab := pgMediaPanel.ActivePageIndex + 1;

    CurrentTab := pgMediaPanel.ActivePageIndex;

    if NextTab > pgMediaPanel.PageCount-1 then
      NextTab := 0;

    if CurrentTab <> NextTab then
    begin
      pgMediaPanel.ActivePageIndex := NextTab;
      _MediaSearch.DoTabChange(pgMediaPanel);
    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TMainFrm.MnuGMSetDefaultClick(Sender: TObject);
var
  theNode : PVirtualNode;
  theROM : TQPROM;
begin
  //Set the default GoodMERGE rom popup.
  theNode := VTROMS.FocusedNode;
  if (theNode <> nil) and (VTROMS.GetNodeLevel(theNode) = 1) then
  begin
    theROM := TQPROM(GetObject(VTROMS, VTROMS.NodeParent[theNode] ));
    theROM.DefaultGoodMerge := theROM.CompressedFiles[theNode.Index];
    ROMList.SaveToFile(); //update the ROMS file.
  end;
end;


end.
