unit ujPowerSchemes;

interface

uses Windows, Classes, SysUtils;

Function PowerSchemeIDbyName(Name : String) : Integer;
Function PowerSchemeNameById(ID : Integer) : String;
Procedure PowerSchemesToStrings(var inStrs : TStrings);
Function GetActivePowerScheme() : String;
Function SetActivePowerScheme(Name : String) : Boolean;

implementation

uses
  JwaPowrProf,
  JwaWinBase;

var
  tmp : TStrings;

{

  TPowerPolicy = Class(TObject)
  public
    SchemeName : String;
    Index: UINT;
    Policy: POWER_POLICY;
  end;
  PPowerPolicyRec = ^TPowerPolicy;

var
  myPP : TPowerPolicy;
begin

  _Schemes.Add(TPowerPolicy.Create);
  myPP := TPowerPolicy(_Schemes.Last);
  myPP.Index := uiIndex;

  myPP.SchemeName := sName;
  myPP.Policy := pp^;

  Result := True;
end;
}

{-----------------------------------------------------------------------------}

function EnumPowerSchemesCallBack(uiIndex: UINT; dwName: DWORD; sName: LPWSTR; dwDesc: DWORD; sDesc: LPWSTR; pp: PPOWER_POLICY; lParam: LPARAM): ByteBool; stdcall;
begin
  //adds power schemes in the following way: NAME=ID
  Tmp.Add(Format('%s=%d', [sName, uiIndex]));
  Result := True;
end;

{-----------------------------------------------------------------------------}

Function PowerSchemeIDbyName(Name : String) : Integer;
begin
  Tmp := TStringList.Create;
  try
    jwaPowrProf.EnumPwrSchemes(EnumPowerSchemesCallBack, 1);
    try
      Result := StrToInt(Tmp.Values[Name]);
    except
      Result := -1;
    end;
  finally
    FreeAndNil(Tmp);
  end;
end;

{-----------------------------------------------------------------------------}

Function PowerSchemeNameById(ID : Integer) : String;
var
  i : Integer;
begin
  Tmp := TStringList.Create;
  try
    Result := '';
    jwaPowrProf.EnumPwrSchemes(EnumPowerSchemesCallBack, 1);

    for i := 0 to Tmp.Count-1 do
    begin
      if StrToInt(Tmp.ValueFromIndex[i]) = ID then
      begin
        Result := Tmp.Names[i];
        Break;
      end;
    end;
  finally
    FreeAndNil(Tmp);
  end;
end;

{-----------------------------------------------------------------------------}

Procedure PowerSchemesToStrings(var inStrs : TStrings);
var
  i : Integer;
begin
  Tmp := TStringList.Create;
  try

    inStrs.Clear;
    jwaPowrProf.EnumPwrSchemes(EnumPowerSchemesCallBack, 1);
    inStrs.Capacity := Tmp.Count;
    for i := 0 to Tmp.Count-1 do
      inStrs.Add(Tmp.Names[i]);

  finally
    FreeAndNil(Tmp);
  end;
end;

{-----------------------------------------------------------------------------}

Function GetActivePowerScheme() : String;
var
  Index : Cardinal;
begin
  if jwaPowrProf.GetActivePwrScheme(Index) then
  begin
    Result := PowerSchemeNameByID(Index);
  end
  else
    Result := '';
end;

{-----------------------------------------------------------------------------}

Function SetActivePowerScheme(Name : String) : Boolean;
var
  Id : Integer;
begin
  ID := PowerSchemeIDbyName(Name);
  if ID <> -1 then
    Result := jwaPowrProf.SetActivePwrScheme(ID, nil, nil);
end;

{-----------------------------------------------------------------------------}

end.
