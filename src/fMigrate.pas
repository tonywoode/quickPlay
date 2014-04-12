unit fMigrate;

interface

uses
  Windows, SysUtils, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ComCtrls, Contnrs, FindFile, VirtualTrees,
  IniFiles, fJWinFontForm;

type

  TQPArea = (TaROM, TaEmu, TaFav, TaMirror, TaMedia, TaFolderOpts, TaIPS);

  TQPProblem = class
  Private
    FProbDir : String;
    FFixDir : String;
    FArea : TQPArea;
  public
    Property ProbDir : String Read FProbDir Write FProbDir;
    Property FixDir : String Read FFixDir Write FFixDir;
    Property Area : TQPArea Read FArea Write FArea;
    Constructor create(Area : TQPArea; ProbDir, FixDir : String);
  end;

  TQPProbList = class(TObjectList)
  protected
    function GetItem(Index: Integer): TQPProblem;
    procedure SetItem(Index: Integer; AObject: TQPProblem);
    function GetROMCount():Integer;
    function GetEmuCount():Integer;
    function GetFavCount():Integer;
    function GetFolderOptCount():Integer;
    function GetMediaCount():Integer;
    function GetMirrorCount():Integer;
    function GetIPSCount: Integer;
  public
    property Items[Index: Integer]: TQPProblem read GetItem write SetItem; default;
    Property ROMcount : Integer Read GetROMCount;
    Property EmuCount : Integer Read GetEmuCount;
    Property FavCount : Integer Read GetFavCount;
    Property FolderOptCount : Integer read GetFolderOptCount;
    Property MirrorCount : Integer Read GetMirrorCount;
    Property MediaCount : Integer Read GetMediaCount;
    Property IPSCount : Integer read GetIPSCount;
  end;

  TFrmMigrate = class(TJWinFontForm)
    PCMigrate: TPageControl;
    TabWelcome: TTabSheet;
    TabResults: TTabSheet;
    lblWelcome: TLabel;
    lblDescription: TLabel;
    BtnScan: TButton;
    BtnCancel: TButton;
    VTMigrate: TVirtualStringTree;
    BtnOK: TButton;
    procedure VTMigrateInitNode(Sender: TBaseVirtualTree; ParentNode,
      Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
    procedure VTMigratePaintText(Sender: TBaseVirtualTree;
      const TargetCanvas: TCanvas; Node: PVirtualNode; Column: TColumnIndex;
      TextType: TVSTTextType);
    procedure FormCreate(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure BtnScanClick(Sender: TObject);
    procedure VTMigrateGetText(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure VTMigrateGetImageIndex(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
      var Ghosted: Boolean; var ImageIndex: Integer);
    procedure VTMigrateChange(Sender: TBaseVirtualTree;
      Node: PVirtualNode);
    procedure VTMigrateEditing(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex; var Allowed: Boolean);
    procedure VTMigrateNewText(Sender: TBaseVirtualTree;
      Node: PVirtualNode; Column: TColumnIndex; NewText: WideString);
    procedure BtnOKClick(Sender: TObject);
    procedure VTMigrateFreeNode(Sender: TBaseVirtualTree;
      Node: PVirtualNode);
    procedure VTMigrateExit(Sender: TObject);
  private
    { Private declarations }
    _Cached : Integer;
    ProbList : TQPProbList;
    procedure FixIPSPaths;

    procedure FixEmuPaths();
    procedure FixFavPaths();
    procedure FixFolOptPaths();
    procedure FixMediaPaths();
    procedure FixROMPaths();

    Function GetFixedString(inStr : String; ForType : TQPArea) : String;

    Procedure PathsToProblems(Paths : TStringList; PType : TQPArea);
    Procedure SetupTree();
  public
    { Public declarations }
  end;

implementation

uses fMain, uRom, JclFileUtils, StrUtils,
  uJVirtualTree, JCLStrings, uRomList, uRomUtils, uQPConst, uQPVTEditor, uJFile,
  uMediaSystemClass;

{$R *.dfm}

{-----------------------------------------------------------------------------}
{TQPProblem}
{-----------------------------------------------------------------------------}

Constructor TQPProblem.create(Area : TQPArea; ProbDir, FixDir : String);
begin
  FArea := Area;
  FProbDir := ProbDir;
  FFixDir := FixDir;
end;

{-----------------------------------------------------------------------------}
{TQPProbList}
{-----------------------------------------------------------------------------}

function TQPProbList.GetItem(Index: Integer): TQPProblem;
begin
  Result := TQPProblem(inherited Items[Index]);
end;

procedure TQPProbList.SetItem(Index: Integer; AObject: TQPProblem);
begin
  inherited Items[Index] := AObject;
end;

function TQPProbList.GetIPSCount: Integer;
var
  i : Integer;
begin
  Result := 0;
  For i := 0 to Count-1 do
    if Items[i].Area = taIPS then
      inc(Result);
end;

function TQPProbList.GetROMCount():Integer;
var
  i : Integer;
begin
  Result := 0;
  For i := 0 to Count-1 do
    if Items[i].Area = TaROM then
      inc(Result);
end;

function TQPProbList.GetEmuCount():Integer;
var
  i : Integer;
begin
  Result := 0;
  For i := 0 to Count-1 do
    if Items[i].Area = TaEmu then
      inc(Result);
end;

function TQPProbList.GetFavCount():Integer;
var
  i : Integer;
begin
  Result := 0;
  For i := 0 to Count-1 do
    if Items[i].Area = TaFav then
      inc(Result);
end;

function TQPProbList.GetMirrorCount():Integer;
var
  i : Integer;
begin
  Result := 0;
  For i := 0 to Count-1 do
    if Items[i].Area = TaMirror then
      inc(Result);
end;

function TQPProbList.GetMediaCount():Integer;
var
  i : Integer;
begin
  Result := 0;
  For i := 0 to Count-1 do
    if Items[i].Area = TaMedia then
      inc(Result);
end;

function TQPProbList.GetFolderOptCount():Integer;
var
  i : Integer;
begin
  Result := 0;
  For i := 0 to Count-1 do
    if Items[i].Area = TaFolderOpts then
      inc(Result);
end;

{-----------------------------------------------------------------------------}
{TFrmMigrate}
{-----------------------------------------------------------------------------}

{-----------------------------------------------------------------------------
  Cached variable explanation..

  Ok the cached variable.  Basically it CAN save us looping through all the problems,
  it works like this..  on the first run, all the problems are looped through to find
  the current path we want to modify.  the cached variable holds the result from this
  loop - in the hope that we can just use the same 'answer'.
-----------------------------------------------------------------------------}

Function TFrmMigrate.GetFixedString(inStr : String; ForType : TQPArea) : String;
var
  f : Integer;
begin

  //check to see if we can use the cached value.
  if (_cached > -1) and (AnsiContainsText(inStr, Problist[_cached].ProbDir)) then
  begin
    //change the path.
    Result := AnsiReplaceText(inStr, Problist[_cached].ProbDir, Problist[_cached].FixDir);
  end
  else
  For f := 0 to ProbList.Count-1 do
    if (Problist[f].Area = ForType) and (AnsiContainsText(inStr, Problist[f].ProbDir)) then
    begin
      //change the path
      Result := AnsiReplaceText(inStr, Problist[f].ProbDir, Problist[f].FixDir);
      _cached := f;
      break;
    end;

end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.FixEmuPaths();
var
  i : Integer;
begin
  //fix any emulators problems
  If Problist.EmuCount > 0 then
  begin

    With MainFrm do
    begin
      _Cached := -1;
      For i := 0 to EmuList.Count-1 do
        EmuList[i].Path := GetFixedString(EmuList[i].Path, taEmu);

      EmuList.SaveToFile(); //save the changes

    end;//end of with MainFrms.emulators

  end; // end check that there are emulators to fix.
end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.FixFavPaths();
var
  i : Integer;
begin
  //fix any fav problems
  If ProbList.FavCount > 0 then
  begin

    With MainFrm do
    begin

      _Cached := -1;
      For i := 0 to FavList.Count-1 do
        FavList[i].Path := GetFixedString(FavList[i].Path, taFav);

      //save the changes to disk.
      FavList.SaveToFile();

    end;//end of WITH MainFrm.favourites

  end;  //end of check that there are favourites to fix.
end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.FixFolOptPaths();
var
  i, e : Integer;
  Find : ThhFindFile;
  ini : TMemIniFile;
  TmpString : String;
begin
  //check if there any FOLDER OPTs OR mirror paths to fix.
  If (Problist.GetFolderOptCount > 0) or (ProbList.GetMirrorCount > 0) then
  begin

    Find := ThhFindFile.Create(Self);
    Try
      //set up the search parameters
      Find.Directory := MainFrm.Settings.Paths.ROMsDir;
      Find.Recurse := True;
      Find.Filter := 'folders.ini';

      //start the search
      Find.Execute;

      For i := 0 to Find.TotalFile-1 do
      begin

        Ini := TMemIniFile.Create(Find.Files[i]);
        try
          //sort out all the mirror parts first
          For e := 0 to ProbList.Count-1 do
          begin

              //if this problem is a mirror deal with it!
            If (ProbList[e].Area = TaMirror) and
               (Ini.ValueExists('Mirror', 'TxtDir')) and
               (AnsiContainsText(Ini.ReadString('Mirror', 'TxtDir',''), Problist[e].ProbDir)) then
            begin
              TmpString := AnsiReplaceText(Ini.ReadString('Mirror', 'TxtDir',''), Problist[e].ProbDir, Problist[e].FixDir);
              Ini.WriteString('Mirror', 'TxtDir', TmpString);
            end;

            //if this problem is a Folderopts DEAL with it!
            If (ProbList[e].Area = taFolderOpts) then
            begin

              //see if we need to change the Background path first.
              If (Ini.ValueExists('BkGround', 'TxtBKPath')) and
                 (AnsiContainsText(Ini.ReadString('BkGround', 'TxtBKPath',''), Problist[e].ProbDir)) then
              begin
                TmpString := AnsiReplaceText(Ini.ReadString('BkGround', 'TxtBKPath',''), Problist[e].ProbDir, Problist[e].FixDir);
                Ini.WriteString('BkGround', 'TxtBKPath', TmpString);
              end;

              //see if we need to change the Real Icon path.
              If (Ini.ValueExists('RealIcon', 'Directory')) and
                 (AnsiContainsText(Ini.ReadString('RealIcon', 'Directory',''), Problist[e].ProbDir)) then
              begin
                TmpString := AnsiReplaceText(Ini.ReadString('RealIcon', 'Directory',''), Problist[e].ProbDir, Problist[e].FixDir);
                Ini.WriteString('RealIcon', 'Directory', TmpString);
              end;

            end;

          end; //end of sorting out the mirror parts.

          //remember we need to update the inifile as this is a MEM one.
          Ini.UpdateFile;

        finally
          FreeAndNil(Ini);
        end;

      end; //end of Find file for loop

    Finally
      FreeAndNil(Find);
    end;

  end; //end of check that there are folder options/mirrors to fix.

end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.FixMediaPaths();
var
  i, ix, e : Integer;
  Sys : TJMediaSystem;
begin
  if ProbList.MediaCount > 0 then
  begin
    With MainFrm do
    begin

      //first off fix the emulator media paths.

      _Cached := -1;
      For i := 0 to EmuList.Count-1 do
        EmuList[i].ExeImage := GetFixedString(EmuList[i].ExeImage, taMedia);

      EmuList.SaveToFile(); //save the changes

      _Cached := -1;
      //now fix the tools media paths.
      For i := 0 to ToolList.Count-1 do
        ToolList[i].ExeImage := GetFixedString(ToolList[i].ExeImage, taMedia);
      ToolList.SaveToFile();

      _Cached := -1;
      //and now fix the actual media object paths.
      for i := 0 to MediaSearchObj.SystemCount-1 do
      begin
        Sys := MediaSearchObj.Systems[i];
        if Sys.SystemImage <> '' then
          Sys.SystemImage := GetFixedString(Sys.SystemImage, taMedia);

        for ix := 0 to sys.TabCount-1 do
          for e := 0 to sys.Tabs[ix].Paths.Count-1 do
            sys.Tabs[ix].Paths[e] := GetFixedString(sys.Tabs[ix].Paths[e], taMedia);

      end;
      MediaSearchObj.SaveSystems();

    end;//end of with MainFrm

  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.FixIPSPaths();
var
  i, e, f : Integer;
  TmpROMs : TQPROMList;
  RomFiles : TStringList;
begin
  If ProbList.IPSCount > 0 then
  begin
    //first we will fix the ROMs
    RomFiles := TStringList.Create;
    Try

      //set up our find object to get all the ROMs data files.
      uROMUtils.GetAllROMFiles(RomFiles);

      //create our temporary ROMs list, we will need it!
      TmpROMs := TQPROMlist.Create(MainFrm.Settings.AllowWrite);
      Try

        //begin looping through all the rom files.
        For i := 0 to RomFiles.Count-1 do
        begin

          //load this file into the tmproms objectlist.
          TmpROMS.LoadFromFile(RomFiles[i]);
          _Cached := -1;
          
          //now loop through each of the roms to get our list of incorrect paths.
          For e := 0 to TmpROMS.Count-1 do
          begin
            for f := 0 to TmpROMS[e].IPSCount - 1 do
              TmpROMS[e].IPS[f].IPSpath := GetFixedString(TmpROMS[e].IPS[f].IPSpath, taIPS);
          end;

          TmpRoms.FileName := RomFiles[i];
          TmpROMS.SaveToFile(); //save the changes to disk.

        end; //end of loop through all files.

      //free the tmproms romlist object.
      Finally
        FreeAndNil(TmpROMs);
      end;

    //free the find object.
    Finally
      FreeAndNil(RomFiles);
    end;

  end; //end of IPSCount check.
end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.FixROMPaths();
var
  i, e : Integer;
  TmpROMs : TQPROMList;
  RomFiles : TStringList;
begin
  If ProbList.ROMcount > 0 then
  begin
    //first we will fix the ROMs
    RomFiles := TStringList.Create;
    Try

      //set up our find object to get all the ROMs data files.
      uROMUtils.GetAllROMFiles(RomFiles);

      //create our temporary ROMs list, we will need it!
      TmpROMs := TQPROMlist.Create(MainFrm.Settings.AllowWrite);
      Try

        //begin looping through all the rom files.
        For i := 0 to RomFiles.Count-1 do
        begin

          //load this file into the tmproms objectlist.
          TmpROMS.LoadFromFile(RomFiles[i]);
          _Cached := -1;
          
          //now loop through each of the roms to get our list of incorrect paths.
          For e := 0 to TmpROMS.Count-1 do
            TmpROMS[e].Path := GetFixedString(TmpROMS[e].Path, taROM);

          TmpRoms.FileName := RomFiles[i];
          TmpROMS.SaveToFile(); //save the changes to disk.

        end; //end of loop through all files.

      //free the tmproms romlist object.
      Finally
        FreeAndNil(TmpROMs);
      end;

    //free the find object.
    Finally
      FreeAndNil(RomFiles);
    end;

  end; //end of ROMcount check.
end;

{-----------------------------------------------------------------------------}

//Give a list of paths, this function loops through the paths, pulls out the
//common paths and adds only those common paths to the internet problem list.

Procedure TFrmMigrate.PathsToProblems(Paths : TStringList; PType : TQPArea);
var
  Tmp : TStringList;
  TempDir : String;
  I, e, SamePos : Integer;
begin
  //now we need our second stringlist to hold common paths.
  Tmp := TStringList.Create;
  Try
    //set it up to ignore duplicate entries.
    Tmp.Sorted := True;
    Tmp.Duplicates := dupIgnore;

    //loop through all the paths found in the roms.
    For i := 0 to Paths.Count-1 do
    begin

      //first check that this isnt blank
      If Paths[i] = '' then
        continue;

      //set the tempdir variable equal to the current path.
      TempDir := Paths[i];

      //now loop through all the paths (again)
      For e := 0 to Paths.Count-1 do
      begin
        //we are trying to find the common start between our variable
        //and each entry in the paths stringlist.
        SamePos := PathCommonPrefix(TempDir, Paths[e]);
        //if there is a match then overwrite the temp variable with this match.
        If SamePos > 3 then
          TempDir := Copy(TempDir, 0, SamePos);

      end; //end of for loop

      //finally add the tempdir variable to our tmp stringlist.
      Tmp.Add(TempDir);

    end;

    //now loop through each entry in the tmp stringlist and create object.
    For i := 0 to Tmp.Count-1 do
      ProbList.Add(TQPProblem.create(PType, Tmp[i], Tmp[i]));

  Finally
    FreeAndNil(Tmp);
  end;
end;

{-----------------------------------------------------------------------------}

Procedure TFrmMigrate.SetupTree();
var
  Rnode, FNode, ENode, MirNode, MedNode, FolNode, CNode, IPSNode : PVirtualNode;
  I : Integer;
begin
  VTMigrate.BeginUpdate;

  VTMigrate.RootNodeCount := 7;
  //the ROM node is the first
  RNode := VTMigrate.GetFirst;
  //second is the Favourites
  FNode := VTMigrate.GetNext(RNode);
  //Emulators is next
  ENode := VTMigrate.GetNext(FNode);
  // Folder Options are next
  FolNode := VTMigrate.GetNext(Enode);
  //Media is Next
  MedNode := VTMigrate.GetNext(FolNode);
  //Mirrors are last
  MirNode := VTMigrate.GetNext(MedNode);
  //IPS Paths are last.
  IPSNode := VTMigrate.GetNext(mirNode);

  For i := 0 to Problist.Count-1 do
  begin

    case Problist[i].Area of
      TaROM    : CNode := VTMigrate.AddChild(RNode);
      TaFav    : CNode := VTMigrate.AddChild(FNode);
      TaEmu    : CNode := VTMigrate.AddChild(ENode);
      TaFolderOpts : CNode := VTMigrate.AddChild(FolNode);
      TaMedia  : CNode := VTMigrate.AddChild(MedNode);
      TaMirror : CNode := VTMigrate.AddChild(MirNode);
      taIPS    : CNode := VTMigrate.AddChild(IPSNode);
    else
      Cnode := nil;
    end;

    if CNode <> nil then
      SetObject(VTMigrate, CNode, Problist[i]);
  end;

  VTMigrate.FullExpand();

  VTMigrate.EndUpdate;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.FormCreate(Sender: TObject);
begin
  //create the objectlist for storing 'problems'
  ProbList := TQPProbList.Create(True);
  _Cached := -1;
  //set the node data size fo the virtual tree
  VTMigrate.NodeDataSize := SizeOf(Pointer);

  //set up the page control.
  TabWelcome.TabVisible := False;
  TabResults.TabVisible := False;

  PCMigrate.ActivePage := TabWelcome;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  FreeAndNil(ProbList);
end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.BtnOKClick(Sender: TObject);
var
  i : Integer;
  OldCursor : TCursor;
begin

  //First change the hourglass - this could take a while!
  OldCursor := Screen.Cursor;
  Screen.Cursor := crHourGlass;
  Try

    //the first step is to go through our problems and see if the user has fixed any
    //if they havent fixed the problem, then delete it.
    For i := Problist.Count-1 downto 0 do
      if strCompare(Problist[i].ProbDir, Problist[i].FixDir)=0 then
        Problist.Delete(i); 

    //check to see if there are any problems left, if not then exit.
    //also there is no point continuing if the disk cannot be written to.
    If (Problist.Count = 0) or (MainFrm.Settings.AllowWrite = False) then
      Exit;

    FixROMPaths();
    FixEmuPaths();
    FixFavPaths();
    FixFolOptPaths();
    FixMediaPaths();
    FixIPSPaths();

  //return the cursor to normal
  Finally
    Screen.Cursor := OldCursor;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.BtnScanClick(Sender: TObject);
var
  Find : ThhFindFile;
  TmpROMs : TQPROMList;
  i, e, f : Integer;
  OldCursor : TCursor;
  Paths, MirTmp, IPS : TStringList;
  Ini : TMemIniFile;
begin

  //clear the problist objectlist
  ProbList.Clear;

  //First change the hourglass - this could take a while!
  OldCursor := Screen.Cursor;
  Screen.Cursor := crHourGlass;
  Try

    Paths := TStringList.Create;
    Try

      //disable duplicates so we dont fill our stringlist with the same thing!
      Paths.Sorted := True;
      Paths.CaseSensitive := False;
      Paths.Duplicates := dupIgnore;

      //first we will check the ROMs for any invalid directories.
      Find := thhFindFile.Create(Self);
      Try

        //set up our find object to get all the ROMs data files.
        Find.Directory := MainFrm.Settings.Paths.ROMsDir;
        Find.Recurse := True;
        Find.Filter := DefaultFileName;
        Find.Attributes := ([]);
        Find.Execute;

        //create our temporary ROMs list, we will need it!
        TmpROMs := TQPROMlist.Create(MainFrm.Settings.AllowWrite);
        Try
          IPS := TStringList.Create;
          try
          //begin looping through all the rom files.
          For i := 0 to Find.TotalFile-1 do
          begin

            //load this file into the tmproms objectlist.
            TmpROMS.LoadFromFile(Find.Files[i]);
            //now loop through each of the roms to get our list of incorrect paths.
            For e := 0 to TmpROMS.Count-1 do
            begin
              Paths.Add(ExtractFilePath(TmpROMS[e].Path));
              for f := 0 to TmpROMs[e].IPSCount - 1 do
                IPS.Add(ExtractFilePath(TmpROMS[e].IPS[f].IPSpath));
            end;

          end;

          PathsToProblems(Paths, TaROM);
          PathsToProblems(IPS, taIPS);
          finally
            FreeAndNil(IPS);
          end;
          
        //we have finished with teh tmproms objectlist.
        Finally
          FreeAndNil(TmpROMS);
        end;

        //END of ROMs checking.

        //now check the folder options.

        //Reuse the find file object to search for Ini Files.

        //clear the stringlist.
        Paths.Clear;

        //-------------------------------------------

         //now check the emulators for any problems in it.
        For i := 0 to MainFrm.EmuList.Count-1 do
        Paths.Add(ExtractFilePath(MainFrm.EmuList[i].Path));

        PathsToProblems(Paths, TaEmu);

        //clear teh paths stringlist
        Paths.Clear;

        //-------------------------------------------
        // now check folder options

        Find.Filter := 'folders.ini';
        Find.Execute;

        //we need to create a seperate stringlist to hold mirror results,
        //the media results will be held in our 'paths' stringlist.
        MirTmp := TStringList.Create;
        try

          For i := 0 to Find.TotalFile-1 do
          begin
            Ini := TMemIniFile.Create(Find.Files[i]);
            Try

              Paths.Add(Ini.ReadString('BkGround', 'TxtBKPath', ''));
              Paths.Add(Ini.ReadString('RealIcon', 'Directory', ''));
              MirTmp.Add(Ini.ReadString('Mirror', 'TxtDir', ''));

            Finally
              FreeAndNil(Ini);
            end;
          end;

          //now convert both stringlists into 'problems'
          PathsToProblems(Paths, taFolderOpts);
          PathsToProblems(MirTmp, TaMirror);
          
        finally
          FreeAndNil(MirTmp);
        end;

      //Free our find object.
      Finally
        FreeAndNil(Find);
      end;

      //end of Folder Options scanning

      //clear the Paths stringlist.
      Paths.Clear;

      //-------------------------------------------

      //now check the favourites.
      For i := 0 to MainFrm.FavList.Count-1 do
        Paths.Add(ExtractFilePath(MainFrm.FavList[i].Path));

      PathsToProblems(Paths, taFav);

      Paths.Clear;

      //-------------------------------------------
      //now check the media panel paths.

      for i := 0 to Mainfrm.MediaSearchObj.SystemCount-1 do
      begin
        //add the system image.
        Paths.Add(MainFrm.MediaSearchObj.Systems[i].SystemImage);
        for e := 0 to MainFrm.MediaSearchObj.Systems[i].TabCount-1 do
          Paths.AddStrings(MainFrm.MediaSearchObj.Systems[i].Tabs[e].Paths);
      end;

      //check any media paths specified for emulators
      for i := 0 to MainFrm.EmuList.Count-1 do
        Paths.Add(MainFrm.EmuList[i].ExeImage);

      //finally check for any tools media paths.
      for i := 0 to MainFrm.ToolList.Count-1 do
        Paths.Add(MainFrm.ToolList[i].ExeImage);

      PathsToProblems(Paths, taMedia);

      //end of checking media paths.

    //free the paths stringlist
    Finally
      FreeAndNil(Paths);
    end;

    SetupTree();

    PcMigrate.ActivePage := TabResults;
    BtnOK.Visible := True;

  //put the cursor back.
  Finally
    Screen.Cursor := OldCursor;
  end;

end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.VTMigrateFreeNode(Sender: TBaseVirtualTree;
  Node: PVirtualNode);
begin
  SetObject(Sender, Node, nil);
end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.VTMigrateGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin
  if TextType = ttNormal then
    case Column of
      0:
        if Sender.GetNodeLevel(node) = 0 then
        begin
          // root nodes
          Case Node.Index of
            0 : CellText := QP_ROMS;
            1 : CellText := QP_FAV;
            2 : CellText := QP_EMU;
            3 : CellText := QP_MIGRATE_MISC;
            4 : CellText := QP_MIGRATE_MEDIA;
            5 : CellText := QP_MIGRATE_MIRROR;
            6 : CellText := QP_MIGRATE_IPS;
          end;
            
        end
        else
          CellText := TQPProblem(GetObject(Sender, Node)).ProbDir;

      1: if Sender.GetNodeLevel(node) = 0 then
           CellText := ''
         else
           CellText := TQPProblem(GetObject(Sender, Node)).FixDir;
    end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.VTMigrateGetImageIndex(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Kind: TVTImageKind; Column: TColumnIndex;
  var Ghosted: Boolean; var ImageIndex: Integer);
begin
  if (Column = 0) and (Sender.GetNodeLevel(node) = 0) then
  begin
    // root nodes
    if (Kind = ikNormal) or (Kind = ikSelected) then
    Case Node.Index of
      0: ImageIndex := 0;
      1: ImageIndex := 13;
      2: ImageIndex := 2;
      3: ImageIndex := 15;
      4: ImageIndex := 31;
      5: ImageIndex := 0;
      6: ImageIndex := 20;
    end;

  end
  else
    ImageIndex := -1;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.VTMigrateChange(Sender: TBaseVirtualTree;
  Node: PVirtualNode);
begin
  with Sender do
  begin
    // Start immediate editing as soon as another node gets focused.
    if Assigned(Node) and (Sender.GetNodeLevel(node) > 0) and not (tsIncrementalSearching in TreeStates) then
    begin
      // Note: the test whether a node can really be edited is done in the OnEditing event.
      EditNode(Node, 1);
    end;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.VTMigrateEditing(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; var Allowed: Boolean);
begin
  Allowed := (Column = 1);
end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.VTMigrateNewText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; NewText: WideString);
var
  Prob : TQPProblem;
begin
  If (Assigned(Node)) and (NewText <> '') then
  begin
    //assign the selected node to a temporary variable.
    Prob := TQPProblem(GetObject(Sender, Node));

    //if the fix dir ends with a delimiter we need to make sure the
    //users selected directory also does AND vice versa.
    If (IsPathDelimiter(Prob.ProbDir, Length(Prob.ProbDir)) ) then
      Prob.FixDir := IncludeTrailingPathDelimiter(NewText)
    else
      Prob.FixDir := ExcludeTrailingPathDelimiter(NewText);

  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.VTMigrateExit(Sender: TObject);
begin
  if VTMigrate.IsEditing then
    VTMigrate.EndEditNode;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.VTMigratePaintText(Sender: TBaseVirtualTree;
  const TargetCanvas: TCanvas; Node: PVirtualNode; Column: TColumnIndex;
  TextType: TVSTTextType);
begin
  if (Node <> nil) and (Sender.GetNodeLevel(Node) = 0 ) then
  begin
    TargetCanvas.Font.Style := [fsBold];
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMigrate.VTMigrateInitNode(Sender: TBaseVirtualTree; ParentNode,
  Node: PVirtualNode; var InitialStates: TVirtualNodeInitStates);
begin
  if Node <> nil then
    if Sender.GetNodeLevel(Node) = 0 then
      Sender.NodeHeight[Node] := 24
    else
      Sender.NodeHeight[Node] := 20;
end;

{-----------------------------------------------------------------------------}

end.
