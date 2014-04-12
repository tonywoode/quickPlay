unit uRomUtils;

interface

uses
  Windows, Forms, Classes, SysUtils, Controls, FindFile,
  uEmuList, uRomList;

  Procedure DeleteAllOrphans();
  Procedure GetAllROMFiles(var AllFiles : TStringList);
  procedure RenameEmulators(OldName, NewName: String);
  procedure DeleteAllByEmulator(Emu: String);
  procedure RunRandomAll(NeverPlayed : boolean);

implementation

uses JCLFileUtils, uJUtilities, fMain, Dialogs, uQPConst;

{$I Compilers.inc}

{ TRoms }

{-----------------------------------------------------------------------------}

Procedure DeleteAllOrphans();
var
   i, Totals  : integer;
   OldCursor : TCursor;
   ROMFiles : TStringList;
   TmpList : TQPROMlist;
Begin
  OldCursor := Screen.Cursor;
  Screen.Cursor := crHourGlass;

  ROMFiles := TStringList.Create;
  try
    TmpList := TQPROMlist.Create(MainFrm.Settings.AllowWrite);
    Totals := 0;
    //get all the datafiles and load them and scan them for roms

    GetAllROMFiles(ROMFiles);

    for i := 0 to ROMFiles.Count-1 do
    begin
      TmpList.LoadFromFile(ROMFiles[i]);
      Totals := Totals + TmpList.DeleteOrphans();
    end;

    MessageDlg(IntToStr(Totals) + QP_TOTAL_INVALID_REMOVED, mtInformation, [mbOK], 0);

  finally
    Screen.Cursor := OldCursor;
    //Refresh;
    FreeAndNil(ROMFiles);
    FreeAndNil(TmpList);
  end;

End;

{-----------------------------------------------------------------------------}

Procedure GetAllROMFiles(var AllFiles : TStringList);
var
  Find : ThhFindFile;
begin
  Find := ThhFindFile.Create(nil);
  try
    Find.Directory := MainFrm.Settings.Paths.ROMsDir;
    Find.Recurse := True;
    Find.Filter := DefaultFileName;
    Find.Attributes := ([]);
    Find.Execute;
    AllFiles.Assign(Find.Files);
  finally
    FreeAndNil(Find);
  end;
end;

{-----------------------------------------------------------------------------}

Procedure RenameEmulators(OldName, NewName: String);
var
   i : integer;
   OldCursor : TCursor;
   ROMFiles : TStringList;
   TmpList : TQPROMList;
Begin
  OldCursor := Screen.Cursor;
  Screen.Cursor := crHourGlass;

  ROMFiles := TStringList.Create;
  try
    TmpList := TQPROMlist.Create(MainFrm.Settings.AllowWrite);

  //get all the datafiles and load them and scan them for roms

    GetAllROMFiles(ROMFiles);

    for i := 0 to ROMFiles.Count-1 do
    begin
      TmpList.LoadFromFile(ROMFiles[i]);
      TmpList.ChangeEmus(OldName, NewName);
    end;  //end of FOR loop

  finally
    Screen.Cursor := OldCursor;
    //Refresh;
    FreeAndNil(ROMFiles);
    FreeAndNil(TmpList);
  end;

End;

{-----------------------------------------------------------------------------}

Procedure DeleteAllByEmulator(Emu: String);
var
   i : integer;
   OldCursor : TCursor;
   ROMFiles : TStringList;
   TmpList : TQPROMlist;
Begin
  OldCursor := Screen.Cursor;
  Screen.Cursor := crHourGlass;

  ROMFiles := TStringList.Create;
  try
    TmpList := TQPROMList.Create(MainFrm.Settings.AllowWrite);

    //get all the datafiles and load them and scan them for roms

    GetAllROMFiles(ROMFiles);

    for i := 0 to ROMFiles.Count-1 do
    begin
      TmpList.LoadFromFile(ROMFiles[i]);
      TmpList.DeleteByEmu(Emu);
    end;  //end of FOR loop

  finally
    Screen.Cursor := OldCursor;
    //Refresh;
    FreeAndNil(ROMFiles);
    FreeAndNil(TmpList);
  end;

End;

{-----------------------------------------------------------------------------}

procedure RunRandomAll(NeverPlayed : boolean);
var
  UseFile : String;
  RandFol, RunAttempt, FileAttempt : Integer;
  TmpROMS : TQPROMList;
  ROMFiles : TStringList;
  ValidFile, ROMRun : Boolean;
begin
  //Initialise the random number generator.
  Randomize;

  ROMFiles := TStringList.Create;
  Try

    TmpROMS := TQPROMlist.Create(MainFrm.Settings.AllowWrite);
    Try

    GetAllROMFiles(ROMFiles);

    //Make sure there are search results
    If ROMFiles.Count < 1 then
      raise EJException.Create(QP_ROMS_DATA_FILES_NOT_FOUND);

    ROMRun := False;
    RunAttempt := 0;

    While (ROMRun = False) and (RunAttempt < 5) do
    begin

      //Set up the variables for the finding valid file
      ValidFile := False;
      //the attempt variable is to stop us going into an infinite loop!
      FileAttempt := 0;

      // we will try to find a rom file which actually has roms in it
      // the attempt variable stops us getting into an infinite loop
      While (ValidFile = False) and (FileAttempt < 5) do
      begin

        RandFol := Random(ROMFiles.Count-1);
        if GetSizeOfFile(ROMFiles[RandFol]) > 0 then
        begin
          ValidFile := True;
          UseFile := ROMFiles[RandFol];
        end
        else
          Inc(FileAttempt);
      end;

      //Check we have a file to use.
      If UseFile <> '' then
      begin
        TmpROMS.LoadFromFile(UseFile);
        Try
          TmpRoms.RunRandom(MainFrm.EmuList, MainFrm.ToolList, MainFrm.Settings, NeverPlayed);
          ROMRun := True;
        except
          inc(RunAttempt);
        end;
      end
      else
        Inc(RunAttempt);

    end; //end of while run attempt.

    if ROMRun = false then
      raise EJexception.Create(QP_RANDOM_RUN_FAILURE);

    Finally
      FreeAndNil(TmpROMS);
    end;

  Finally
    FreeAndNil(ROMFiles);
  end;
end;

{-----------------------------------------------------------------------------}


end.
