unit uMediaSystemClass;

interface

uses SysUtils, Classes, Contnrs, IniFiles, uMediaTabClass;

type
  TJMediaSystem = class(Tobject)
  Protected
    _Caption : String;
    _ShowAddInfo : Boolean;
    _SysImage : TFilename;
    _AddInfo : TStringList;
    
    _Tabs : TObjectList;

    Function GetTabCount() : Integer;
    Function GetTab(index : Integer) : TJMediaTab;
    procedure SetTab(index : Integer; aTab : TJMediaTab);
  public
    Constructor Create();overload;
    Constructor Create(inCaption : String);overload;
    Destructor Destroy();override;

    Function AddNewTab() : Integer;
    procedure DeleteTab(dIndex : Integer);
    Function IndexOf(TabName : String) : Integer;
    procedure MoveTab(CurIndex : Integer; NewIndex : Integer);

    procedure LoadFromIni(Ini : TMemIniFile);
    procedure SaveToIni(Ini : TMemIniFile);

    //tab handling code.
    Property TabCount : Integer read GetTabCount;
    property Tabs[Index: Integer]: TJMediaTab read GetTab write SetTab;

    Property Caption : String read _Caption write _Caption;
    Property ShowInfo : Boolean read _ShowAddInfo write _ShowAddInfo;
    Property SystemImage : TFileName read _SysImage write _SysImage;
    Property AdditionalInfo : TStringList read _AddInfo write _AddInfo;
  end;

implementation

uses JCLStrings;

{-----------------------------------------------------------------------------}
{ TJMediaSystem }
{-----------------------------------------------------------------------------}

Constructor TJMediaSystem.Create();
begin
  inherited create();
  _AddInfo := TStringList.Create;
  _Tabs := TObjectList.Create(True);
end;

{-----------------------------------------------------------------------------}

Constructor TJMediaSystem.Create(inCaption : String);
begin
  inherited create();
  _AddInfo := TStringList.Create;
  _Tabs := TObjectList.Create(True);
  _Caption := inCaption;
end;

{-----------------------------------------------------------------------------}

Destructor TJMediaSystem.Destroy();
begin
  FreeAndNil(_AddInfo);
  FreeAndNil(_Tabs);
  inherited Destroy();
end;

{-----------------------------------------------------------------------------}

Function TJMediaSystem.GetTabCount() : Integer;
begin
  Result := _Tabs.Count;
end;

{-----------------------------------------------------------------------------}

Function TJMediaSystem.GetTab(index : Integer) : TJMediaTab;
begin
  Result := TJMediaTab(_Tabs[Index]);
end;

{-----------------------------------------------------------------------------}

procedure TJMediaSystem.SetTab(index : Integer; aTab : TJMediaTab);
begin
  _Tabs[Index] := aTab;
end;

{-----------------------------------------------------------------------------}

Function TJMediaSystem.AddNewTab() : Integer;
begin
  Result := _Tabs.Add(TJMediaTab.Create);
end;

procedure TJMediaSystem.DeleteTab(dIndex : Integer);
begin
  _Tabs.Delete(dIndex);
end;

{-----------------------------------------------------------------------------}

Function TJMediaSystem.IndexOf(TabName : String) : Integer;
var
  i : Integer;
begin

  Result := -1;
  for i := 0 to _Tabs.Count-1 do
    if JCLStrings.StrCompare(TabName, TJMediaTab(_Tabs[i]).Caption)=0 then
    begin
      Result := i;
      Break;
    end;

end;

{-----------------------------------------------------------------------------}

procedure TJMediaSystem.MoveTab(CurIndex : Integer; NewIndex : Integer);
begin
  _Tabs.Move(CurIndex, NewIndex);
end;

{-----------------------------------------------------------------------------}

procedure TJMediaSystem.LoadFromIni(Ini : TMemIniFile);
var
  tmpStream : TMemoryStream;
  tmpNames : TStringList;
  i, newIndex : Integer;
  cfgSection, TabSection : String;
begin

  cfgSection := _Caption+'-CFG';
  tabSection := _Caption+'-TABS';

  //load system configuration information
  _ShowAddInfo := Ini.ReadBool(cfgSection, 'ShowAddInfo', False);
  _SysImage := Ini.ReadString(cfgSection, 'SysImage', '');
  _AddInfo.Clear;
  tmpStream := TMemoryStream.Create;
  try
    Ini.ReadBinaryStream(cfgSection, 'AddInfo', tmpStream);
    tmpStream.Position := 0;
    if tmpStream.Size > 0 then
      _AddInfo.LoadFromStream(tmpStream);
  finally
    FreeAndNil(tmpStream);
  end;

  //load TAB settings
  _Tabs.Clear;

  if Ini.SectionExists(tabSection) then
  begin

    tmpNames := TStringList.Create;
    try

      ini.ReadSection(tabSection, tmpNames);

      tmpStream := TMemoryStream.Create;
      try

        for i := 0 to tmpNames.Count-1 do
        begin
          NewIndex := _Tabs.Add(TJMediaTab.Create);
          Ini.ReadBinaryStream(tabSection, tmpNames[i], tmpStream);
          tmpStream.Position := 0;
          TJMediaTab(_Tabs[NewIndex]).LoadFromStream(tmpStream);
          tmpStream.Clear;
        end;

      finally
        FreeAndNil(tmpStream);
      end;


    finally
      FreeAndNil(tmpNames);
    end;
    
  end;

end;

{-----------------------------------------------------------------------------}

procedure TJMediaSystem.SaveToIni(Ini : TMemIniFile);
var
  i : Integer;
  tmpStream : TMemoryStream;
  cfgSection, tabSection : String;
begin

  cfgSection := _Caption+'-CFG';
  tabSection := _Caption+'-TABS';

  //save system configuration information
  Ini.WriteBool(cfgSection, 'ShowAddInfo', _ShowAddInfo);
  Ini.WriteString(cfgSection, 'SysImage', _SysImage);

  tmpStream := TMemoryStream.Create;
  try
    _AddInfo.SaveToStream(tmpStream);
    tmpStream.Position := 0;
    if tmpStream.Size > 0 then
      Ini.WriteBinaryStream(cfgSection, 'AddInfo', tmpStream);
  finally
    FreeAndNil(tmpStream);
  end;

  //Save Tab information
  if Ini.SectionExists(tabSection) then
    Ini.EraseSection(tabSection);

  tmpStream := TMemoryStream.Create;
  try

    for i := 0 to _Tabs.Count-1 do
    begin
      TJMediaTab(_Tabs[i]).SaveToStream(tmpStream);
      tmpStream.Position := 0;
      Ini.WriteBinaryStream(tabSection, IntToStr(i), tmpStream);
      tmpStream.Clear;
    end;

  finally
    FreeAndNil(tmpStream);
  end;

end;

{-----------------------------------------------------------------------------}
    
end.
