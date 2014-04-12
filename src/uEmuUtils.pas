{
  Emulator Class.
  Contains code related to emulators.  Most functions are
  self-explanatory.

  Emulators are stored in a TObjectList.
}

unit uEmuUtils;

interface

Uses SysUtils, Classes, Windows, uEmuList, uEmu;

procedure EmuMirrorChange(OldName, NewName: String);
Function FileExtsForSystem(inSystem : String) : String;
function NewListDataCheck(Old, New: TQPEmuList):boolean;

implementation

uses FindFile, IniFiles, JCLStrings, fMain, fEmuChanges, uRomUtils, uQPConst,
  uQPCompObj;

Procedure EmuMirrorChange(OldName, NewName : String);
Var
  Find : ThhFindFile;
  I : Integer;
  Ini : TMemIniFile;
Begin
  Find := ThhFindFile.Create(nil);
  Try

    Find.Directory := MainFrm.Settings.Paths.ROMsDir;
    Find.Recurse := True;
    Find.Filter := 'folders.ini';
    Find.Execute;

    For i := 0 to Find.TotalFile-1 do
    Begin

      Ini := TMemIniFile.Create(Find.Files[i]);
      Try
        If StrCompare(Ini.ReadString('Mirror', 'CmbEmu', '' ), OldName)=0 then
        Begin
          Ini.WriteString('Mirror', 'CmbEmu', NewName);
          if MainFrm.Settings.AllowWrite then
            Ini.UpdateFile;
        end;
      Finally
        FreeAndNil(Ini);
      end;

    End;

  Finally
    FreeAndNil(Find);
  end;
End;

{-----------------------------------------------------------------------------}

Function FileExtsForSystem(inSystem : String) : String;
var
  IniExt : TMemIniFile;
  Values : TStringlist;
  e : Integer;
begin
   IniExt := TmemIniFile.Create(MainFrm.Settings.Paths.SysFileExtFile);
   try
    if IniExt.ReadBool(inSystem, 'addCompression', True) then
      Result := uQPCompObj.Compression.SupportedFileExtsForFind;

    Values := TStringList.Create;
    try
      if IniExt.SectionExists(inSystem) then
        IniExt.ReadSection(inSystem, Values);

      for e := 0 to Values.Count-1 do
      begin
        if Not AnsiSameText(Values[e], 'addCompression') then
          Result := Result + IniExt.ReadString(inSystem, Values[e], '') + ';'
      end;
      
    finally
      FreeAndNil(Values);
    end;
   finally
     FreeAndNil(IniExt);
   end;
end;

{-----------------------------------------------------------------------------}

function NewListDataCheck(Old, New : TQPEmuList):Boolean;
var
  I, e : Integer;
  ConfirmFrm : TEmuChangeFrm;
  CurChange : TQPChange;
  PathFound, NameSame : Boolean;
begin

  Result := False;

  //this code takes 2 emulists as parameters and will compare them for
  //differences before saving the new emulist.

  //need to find emulators that have been deleted.
  //need to find emulators that have been renamed.

  //both cases we ignore newly added emulators.

  //create our confirm form to store changes
  ConfirmFrm := TEmuChangeFrm.Create(nil);
  Try

    For i := 0 to Old.Count-1 do
    Begin

      PathFound := False;
      NameSame := False;

      //check that an emulator has been deleted - ie there is no entry
      //with the same name OR the same Path.
      For e := 0 to New.Count-1 do
      begin

        If StrCompare(Old[i].Path, New[e].Path)=0 then
        Begin
          PathFound := True;
          If StrCompare(Old[i].Name, New[e].Name)=0 then
            NameSame := True;
          break;
        end;

      end;

      If PathFound then
      Begin
        If not NameSame then
          ConfirmFrm.ChangeList.Add(TQPChange.create('"' + Old[i].Name + QP_CHANGE_RENAME_1 + New[e].Name + QP_CHANGE_RENAME_2, true, 1, New[e].Name,Old[i].Name))
      end
      else
        //the emulator has been deleted!
        ConfirmFrm.ChangeList.Add(TQPChange.create('"' + Old[i].Name + QP_CHANGE_DELETED, MainFrm.Settings.AutoDelRoms, 2, Old[i].Name, ''));

    End;

    If ConfirmFrm.ChangeList.Count > 0 then
      ConfirmFrm.ShowModal;

    //now we have a list of changes to make.
    For i := 0 to ConfirmFrm.ChangeList.Count-1 do
    begin
      Result := True;
      CurChange := TQPChange(ConfirmFrm.ChangeList[i]);
      If CurChange.Checked then
        case CurChange.FuncType of

          //rename roms
          1: Begin
               uRomUtils.RenameEmulators(CurChange.OldName, CurChange.NewName);
               //MainFrm.Favourites.FavEmuChange(CurChange.OldName, CurChange.NewName);
               EmuMirrorChange(CurChange.OldName, CurChange.NewName);
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

  //we have finished so free the confirm form.
  Finally
    FreeAndNil(ConfirmFrm);
  end;

  //and now we do the simple part - copy the new list to the old list.
  Old.Clear;
  Old.Capacity := New.Count;
  For i := 0 to New.Count-1 do
  begin
    if (New[i].Name = '') or (New[i].Path = '') then
      continue;
      
    New.Items[i].IconIndex := -1;
    Old.Add(TQPEmu.Create);
    Old.last.Assign(New.Items[i]);
  end;

  //save the changes to the emulator list.
  Old.SaveToFile();

end;

{-----------------------------------------------------------------------------}

end.
