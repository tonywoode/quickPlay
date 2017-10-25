unit uEmuList;

interface

uses SysUtils, Contnrs, Classes, Dialogs, uRom, uEmu, uExeList, uToolList,
     uQPMiscTypes;

type

  TQPEmuList = class(TQPExeList)
  protected
    _ToolList : TQPToolList;
    Function Add(New : TQPEmu) : Integer;
    function GetItem(Index: Integer): TQPEmu;
    procedure SetItem(Index: Integer; AObject: TQPEmu);

  public
    Function GetItemByIndex(Index : Integer) : TQPEmu;
    procedure Assign(Source : TQPEmuList);
    Function CopyFrom(new : TQPEmuList; AutoDel : boolean) : TQPEmuAssignResult;
    Procedure DeleteAll(CfgDir : String);
    Procedure DeleteByID(ID : Integer);
    procedure DeleteEmulator(Index : Integer; AutoDel : Boolean; Favs : TObjectList;
          SettingsDir : String);
    Function  EmuExists(NewName : string): boolean;
    procedure EmusToStrings(const sList: TStrings; opt : TQPEmuToStrings; sys : string = '');
    Function GenerateNextID() : Integer;
    function GetEmuForROM(ROM: Tobject): TQPEmu;
    function  IndexOfName(name : string): integer;
    function  IndexOfPath(path : string): integer;
    function  last(): TQPEmu;
    procedure LoadFromFile(EnableIconThread : Boolean);override;
    procedure SaveToFile();override;
    function TotalForSystem(System : String):Integer;
    property Items[Index: Integer]: TQPEmu read GetItem write SetItem; default;
    Property ItemsByID[Index: Integer] : TQPEmu read GetItemByIndex;
  end;

implementation

uses Windows, Controls, uQPConst, IniFiles, JCLStrings, uRomUtils, uRomList, uJFile,
  fEmuChanges, uEmuUtils;

{$I Compilers.inc}

{-----------------------------------------------------------------------------}
{ TQPEmuList }
{-----------------------------------------------------------------------------}

Function TQPEmuList.Add(New : TQPEmu) : Integer;
begin
  Result := Inherited Add(New);
  Self[Result].EmulatorID := Self.GenerateNextID;
end;

function TQPEmuList.GetItem(Index: Integer): TQPEmu;
begin
  Result := TQPEmu(inherited Items[Index]);
end;

{-----------------------------------------------------------------------------}

Function TQPEmuList.GetItemByIndex(Index : Integer) : TQPEmu;
var
  I : Integer;
begin
  Result := nil;
  For i := 0 to Self.Count-1 do
  begin
    if Self[i].EmulatorID = Index then
    begin
      Result := TQPEmu(inherited Items[i]);
      break;
    end;
  end;
end;

{-----------------------------------------------------------------------------}

function TQPEmuList.last: TQPEmu;
begin
  Result := TQPEmu(inherited Items[Count-1]);
end;

{-----------------------------------------------------------------------------}

procedure TQPEmuList.SetItem(Index: Integer; AObject: TQPEmu);
begin
  inherited Items[Index] := AObject;
end;

{-----------------------------------------------------------------------------}

procedure TQPEmuList.Assign(Source : TQPEmuList);
var
  i, Last : integer;
begin
  For i := 0 to Source.Count-1 do
  begin
    Last := Self.Add(TQPEmu.Create);
    Self[Last].Assign(Source[i]);
  end;

  //get the icons for this emulist.
  Self.ActivateEmuIconThread();

end;

{-----------------------------------------------------------------------------}

Function TQPEmuList.CopyFrom(new : TQPEmuList; AutoDel : boolean) : TQPEmuAssignResult;
var
  I, e : Integer;
  ConfirmFrm : TEmuChangeFrm;
  CurChange : TQPChange;
  LinkEmu : TQPEmu;
begin
  Result := qparOK;
  //this code takes an emulists as parameter and will compare them for
  //differences before applying changes to this emulist.

  //need to find emulators that have been deleted.
  //need to find emulators that have been renamed.

  //create our confirm form to store changes
  ConfirmFrm := TEmuChangeFrm.Create(nil);
  Try

    for i := Self.Count-1 downto 0 do
    begin

      LinkEmu := New.ItemsByID[Self[i].EmulatorID];
      if LinkEmu = nil then
      begin
        //Emulator has been deleted.
        ConfirmFrm.ChangeList.Add(TQPChange.create('"' + Self[i].Name + QP_CHANGE_DELETED, AutoDel, 2, Self[i].Name, ''));
        Self.Delete(i);
        Result := qparOKReload;
      end
      else
      begin
        //check if the emulator has been renamed.
        if StrCompare(Self[i].Name, LinkEmu.Name) <> 0 then
          ConfirmFrm.ChangeList.Add(TQPChange.create('"' + Self[i].Name + QP_CHANGE_RENAME_1 + LinkEmu.Name + QP_CHANGE_RENAME_2, true, 1, LinkEmu.Name,Self[i].Name));
        Self[i].Assign(LinkEmu);
        New.DeleteByID(Self[i].EmulatorID);
      end;

    end;

    //now add any new Emulators to the list
    for i := 0 to New.Count-1 do
      if New[i].EmulatorID = -1 then
      begin
        e:= Self.Add(TQPEmu.Create);
        Self[e].Assign(New[i]);
        Self[e].EmulatorID := Self.GenerateNextID();
        Result := qparOKReload;
      end;

    If ConfirmFrm.ChangeList.Count > 0 then
      ConfirmFrm.ShowModal;

    //now we have a list of changes to make.
    For i := 0 to ConfirmFrm.ChangeList.Count-1 do
    begin
      CurChange := TQPChange(ConfirmFrm.ChangeList[i]);
      If CurChange.Checked then
        case CurChange.FuncType of
          //rename roms
          1: Begin
               uRomUtils.RenameEmulators(CurChange.OldName, CurChange.NewName);
               //MainFrm.Favourites.FavEmuChange(CurChange.OldName, CurChange.NewName);
               uEmuUtils.EmuMirrorChange(CurChange.OldName, CurChange.NewName);
             end; 

          //delete linked roms
          2: Begin
               uRomUtils.DeleteAllByEmulator(CurChange.NewName);
               //MainFrm.Favourites.FavEmuDel(CurChange.NewName);
             end;
        end;
    end;

    //free up the changelist
    ConfirmFrm.ChangeList.Clear;
    FreeAndNil(ConfirmFrm.ChangeList);

    //Save the emulator list
    Self.SaveToFile();

    //we have finished so free the confirm form.
  Finally
    FreeAndNil(ConfirmFrm);
  end;
end;

{-----------------------------------------------------------------------------}

Procedure TQPEmuList.DeleteAll(CfgDir : String);
var
  I : Integer;
begin

   //Delete the emulator data file. 
   if fileexists(_FileName) then
      SysUtils.deletefile(_FileName);

   // There might be left over dat files from MAME renaming, remove them.
   for i := 0 to Self.Count-1 do
   begin
    if StrCompare(Self[i].system, 'arcade')=0 then
      if fileExists(CfgDir + Self[i].name + '.dat') then
        SysUtils.DeleteFile(CfgDir + Self[i].name + '.dat');
   end;

   //finally clear my list!
   Self.Clear;
end;

{-----------------------------------------------------------------------------}

Procedure TQPEmuList.DeleteByID(ID : Integer);
var
  i : Integer;
begin
  for i := Self.Count-1 downto 0 do
    if Self[i].EmulatorID = ID then
    begin
      Self.Delete(i);
      break;
    end;
end;

{-----------------------------------------------------------------------------}

procedure TQPEmuList.DeleteEmulator(Index : Integer; AutoDel : Boolean; Favs : TObjectList;
          SettingsDir : String);
Var
  CurEmu : TQPEmu;
Begin

  If Index > self.Count-1 then
    exit
  else
    CurEmu := self[Index];

  // firstly run through the linked roms delete function
  if AutoDel = true then
  Begin
    uRomUtils.DeleteAllByEmulator(CurEmu.name);
    TQPRomList(Favs).DeleteByEmu(CurEmu.name);
  end
  else
    if AutoDel = false then
    begin
      if MessageDlg(QP_DELETE_ALL_LINKED_ROMS,
             mtWarning, [mbYes, mbNo], 0) = mrYes then
      Begin
        uRomUtils.DeleteAllByEmulator(CurEmu.name);
        TQPRomList(Favs).DeleteByEmu(CurEmu.name);
      end;
    end;

  //Check if the emulator is a 'mame' to delete any dat files
  if StrCompare(CurEmu.system, 'arcade')=0 then
    if fileExists(SettingsDir+ CurEmu.name + '.dat') then
      SysUtils.DeleteFile(SettingsDir+ CurEmu.name + '.dat');

  //now do the actual deletion
  self.Delete(Index);

  //save the current list to disk.
  self.SaveToFile();

end;

{-----------------------------------------------------------------------------}

//checks to see if the emulator already exists in the array.
Function TQPEmuList.EmuExists(NewName : string): boolean;
var
  i : integer;
Begin
  result := false;

  For i := 0 to Self.Count-1 do
    if StrCompare(NewName, Self.Items[i].name)=0 then
    begin
      result := true;
      break;
    end;

end;

{-----------------------------------------------------------------------------}

procedure TQPEmuList.EmusToStrings(const sList: TStrings; opt : TQPEmuToStrings; sys : string = '');
var
  i : integer;
begin

  { Fills a combo box which is passed as a parameter with all the systems
    That are available from the system.dat file.
    cfAllEmus, cfMame, cfEmuBySys  }
    
  sList.Clear;

  Case opt of
    cfAllEmus:  begin
                  //Add all emulator names to combo box
                  for I:= 0 to self.Count-1 do
                    if Self[i].CmdLine or Self[i].ShellEx then
                      sList.add(self[i].name);
                end;

    cfMame:     begin
                //Add all Mame-mode emulators to a combo box.
                for I:= 0 to self.Count-1 do
                    If (self[i].IsMAME) and (Self[i].CmdLine or Self[i].ShellEx) then
                      sList.add(self[i].name);
                end;

    cfZinc:     begin
                //Add all Mame-mode emulators to a combo box.
                for I:= 0 to self.Count-1 do
                    If (self[i].IsZinc) and (Self[i].CmdLine or Self[i].ShellEx) then
                      sList.add(self[i].name);
                end;

   cfMameArcade:     begin
                //Add all Mame-mode emulators to a combo box.
                for I:= 0 to self.Count-1 do
                    If (self[i].IsMAMEArcade) and (Self[i].CmdLine or Self[i].ShellEx) then
                      sList.add(self[i].name);
                end;

    cfEmuBySys: Begin
                //Add emulators which belong to a specific system
                for I := 0 to self.Count-1 do
                    If (self[i].system = sys) and (Self[i].CmdLine or Self[i].ShellEx) then
                      sList.Add(self[i].name);
                End;
  end;  //end of CASE statement.
end;

{-----------------------------------------------------------------------------}

Function TQPEmuList.GenerateNextID() : Integer;
var
  i, Next : Integer;
begin
  Next := -1;

  for i := 0 to Self.Count-1 do
  begin
    if Self[i].EmulatorID > Next then
      Next := i;
  end;
  Inc(Next);
  Result := Next;
end;

{-----------------------------------------------------------------------------}

function TQPEmuList.GetEmuForROM(ROM: Tobject): TQPEmu;
var
  i : Integer;
  ROMObj : TQPROM;
begin
  result := nil;
  ROMObj := TQPROM(ROM);
  for i := 0 to self.Count-1 do
    if JCLStrings.StrCompare(self[i].name, ROMObj.Emulator)=0 then
    begin
      result := self[i];
      break;
    end;
end;

{-----------------------------------------------------------------------------}

//Function to figure out the position in the emulator array from the
//name of the emulator that is passed to it.  used for the Tree view
function TQPEmuList.IndexOfName(name : string): integer;
var
  i : integer;
begin

  result := -1;

  for i := 0 to Self.Count-1 do
    if StrCompare(Self[i].name, name)=0 then
    begin
      result := i;
      break;
    end;

end;

{-----------------------------------------------------------------------------}

function TQPEmuList.IndexOfPath(path : string): integer;
var
  i : integer;
begin
  result := -1;

  for i := 0 to Self.Count-1 do
    if StrCompare(Self[i].path, path)=0 then
    begin
      result := i;
      break;
    end;
end;

{-----------------------------------------------------------------------------}


Procedure TQPEmuList.LoadFromFile(EnableIconThread : Boolean);
var
  Ini : TMemIniFile;
  i : integer;
  Sections : TStringList;
  NewEmu : TQPEmu;
  UseLegacy : Boolean;
begin

  self.Clear;

  //if there is no emulators file, set the array to 0 and exit
  if not FileExists(_FileName) then
  begin
    Exit;
  end;

  //create the INI object.
  Ini := TMemIniFile.Create(_FileName);

  //start the try-finally block
  try

    //create a stringlist to hold the total number of sections
    Sections := TStringList.Create;
    Try
      Ini.ReadSections(Sections);

      //work out if this is an older format of emulator.ini file.
      if StrCompare(Ini.ReadString('QP Internal Data', 'Version', ''), '1.0') = 0 then
        UseLegacy := False
      else
        UseLegacy := True;
        
      //take out the Internal data section.
      If Ini.SectionExists('QP Internal Data') then
        Sections.Delete(Sections.IndexOf('QP Internal Data'));

      self.Capacity := Sections.Count;

      For i := 0 to Sections.Count-1 do
      Begin
        //Now begin to set this records values from the ini file.
        self.Add(TQPEmu.Create);
        NewEmu := self.Last;
        if UseLegacy then
          NewEmu.LegacyLoadAndConvert(Sections[i], Ini, I)
        else
          NewEmu.LoadFromIni(Sections[i], Ini, I);
      End;

    //now free the stringlist containing the sections.
    Finally
      FreeAndNil(Sections);
    end;

  //end the try-finally block and free the ini object.
  finally
    FreeAndNil(ini);
  end;

  //activate the emuicons thread to load in emulator icons.
  if (EnableIconThread) and (Self.Count > 0) then
    self.ActivateEmuIconThread();

  //if we loaded in legacy mode we should probably save the newly constructed emulators data file..
  if UseLegacy then
    SaveToFile();

end;

{-----------------------------------------------------------------------------}

Procedure TQPEmuList.SaveToFile();
var
  Ini : TMemIniFile;
  i : integer;
begin

  //check that we are 'allowed' to write to the disk
  If not _AllowWrite then
    exit;

  //now create the ini object we will be using, and open a try-finally
  ini := TMemIniFile.Create(_FileName);
  try

    //before i write anythign to the ini file, erase existing information
    Ini.Clear;

    //first thing i want to do is add versioning information to the file.
    Ini.WriteString('QP Internal Data', 'Version', '1.0');
    Ini.WriteInteger('QP Internal Data', 'Total Records', self.Count);

    //the next section of code will loop through the emulators array
    For i := 0 to self.Count-1 do
      Self[i].SaveIntoIni(Ini);

    //finally since we are using a TMemIniFile, remember to call updatefile.
    if _AllowWrite then
      Ini.UpdateFile;

  // end of ini objects life span, free the object and exit the function.
  finally
    FreeAndNil(ini);
  end;

end;

{-----------------------------------------------------------------------------}

function TQPEmuList.TotalForSystem(System : String):Integer;
Var
  I, Count : Integer;
begin
  Count := 0;

  For i := 0 to self.Count-1 do
    if StrCompare(self[i].system, System)=0 then
      Inc(Count);

  Result := Count;
end;

{-----------------------------------------------------------------------------}

end.
 
