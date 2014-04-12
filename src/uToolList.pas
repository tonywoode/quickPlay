unit uToolList;

interface

uses SysUtils, Classes, uExeList, uTools;

type
  TQPToolList = class(TQPExeList)
  private
    function GetItem(Index: Integer): TQPTool;
    procedure SetItem(Index: Integer; AObject: TQPTool);
    Function GetItemByVar(Index : String) : TQPTool;
  public
    function last(): TQPTool;
    procedure LoadFromFile(EnableIconThread : Boolean);override;
    procedure SaveToFile();override;

    property Items[Index: Integer]: TQPTool read GetItem write SetItem; default;
    Property ItemsByVarName[Index : String] : TQPTool read GetItemByVar;
  end;


implementation

uses IniFiles, JCLStrings;

{------------------------------------------------------------------------------}
{ TQPToolList }
{------------------------------------------------------------------------------}

function TQPToolList.GetItem(Index: Integer): TQPTool;
begin
  Result := TQPTool(inherited Items[Index]);
end;

{------------------------------------------------------------------------------}

procedure TQPToolList.SetItem(Index: Integer; AObject: TQPTool);
begin
  inherited Items[Index] := AObject;
end;

{------------------------------------------------------------------------------}

Function TQPToolList.GetItemByVar(Index : String) : TQPTool;
var
  i : Integer;
begin
  Result := nil;
  for i := 0 to Self.Count-1 do
    if JCLStrings.StrCompare(Self[i].VarName, Index) = 0 then
    begin
      Result := TQPTool(inherited Items[i]);
      break;
    end;

end;

{------------------------------------------------------------------------------}

function TQPToolList.Last(): TQPTool;
begin
  Result := TQPTool(inherited Items[Count-1]);
end;

{------------------------------------------------------------------------------}


procedure TQPToolList.LoadFromFile(EnableIconThread : Boolean);
var
  Ini : TMemIniFile;
  i : integer;
  Sections : TStringList;
  NewTool : TQPTool;
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

      //take out the Internal data section.
      If Ini.SectionExists('QP Internal Data') then
        Sections.Delete(Sections.IndexOf('QP Internal Data'));

      self.Capacity := Sections.Count;

      For i := 0 to Sections.Count-1 do
      Begin
        //Now begin to set this records values from the ini file.
        self.Add(TQPTool.Create);
        NewTool := self.Last;
        NewTool.LoadFromIni(Sections[i], Ini);
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
  if (EnableIconThread) and (self.Count > 0) then
    self.ActivateEmuIconThread();
end;

{------------------------------------------------------------------------------}

procedure TQPToolList.SaveToFile();
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

{------------------------------------------------------------------------------}


end.
 