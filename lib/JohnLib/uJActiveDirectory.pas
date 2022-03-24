unit uJActiveDirectory;

interface

uses SysUtils, Classes, Windows, ActiveDs_TLB;

type
  TSearchScope = (scBase, scOneLevel, scSubtree);

Function ColumnToInteger(colName : WideString; DirSrch : IDirectorySearch; Handle : ADS_SEARCH_HANDLE) : Integer;
Function ColumnToString(colName : WideString; DirSrch : IDirectorySearch; Handle : ADS_SEARCH_HANDLE) : String;
procedure GetDomainControllers(var DCs : TStrings; BindStr : String);

implementation

uses adshlp, activeX;

{-----------------------------------------------------------------------------}

function GetADStringValue(oSrchColumn: ads_search_column): WideString;
var
  wrkPointer : PADSValue;
  oSysTime   : _SYSTEMTIME;
  dtDate,
  dtTime     : TDateTime;
begin
  Result := '';

  // advance the value pointer to the correct one of the potentially multiple
  // values in the "array of values" for this attribute
  wrkPointer := oSrchColumn.pADsValues;

  // depending on the type of the value, turning it into a string is more
  // or less straightforward
  case oSrchColumn.dwADsType of
    ADSTYPE_CASE_EXACT_STRING  : Result := wrkPointer^.__MIDL_0010.CaseExactString;
    ADSTYPE_CASE_IGNORE_STRING : Result := wrkPointer^.__MIDL_0010.CaseIgnoreString;
    ADSTYPE_DN_STRING          : Result := wrkPointer^.__MIDL_0010.DNString;
    ADSTYPE_OBJECT_CLASS       : Result := wrkPointer^.__MIDL_0010.ClassName;
    ADSTYPE_PRINTABLE_STRING   : Result := wrkPointer^.__MIDL_0010.PrintableString;
    ADSTYPE_NUMERIC_STRING     : Result := wrkPointer^.__MIDL_0010.NumericString;
    ADSTYPE_BOOLEAN            : Result := IntToStr(wrkPointer^.__MIDL_0010.Boolean);
    ADSTYPE_INTEGER            : Result := IntToStr(wrkPointer^.__MIDL_0010.Integer);
    ADSTYPE_LARGE_INTEGER      : Result := IntToStr(wrkPointer^.__MIDL_0010.LargeInteger);
    ADSTYPE_UTC_TIME:
      begin
        // ADS_UTC_TIME maps to a _SYSTEMTIME structure
        Move(wrkPointer^.__MIDL_0010.UTCTime, oSysTime, SizeOf(oSysTime));
        // create two TDateTime values for the date and the time
        dtDate := EncodeDate(oSysTime.wYear, oSysTime.wMonth, oSysTime.wDay);
        dtTime := EncodeTime(oSysTime.wHour, oSysTime.wMinute, oSysTime.wSecond, oSysTime.wMilliseconds);
        // add the two TDateTime's (really only a Float), and turn into a string
        Result := DateTimeToStr(dtDate+dtTime);
      end;
    else Result := Format('(unknown data type %d)', [oSrchColumn.dwADsType]);
  end;
end;

{-----------------------------------------------------------------------------}

function GetADIntegerValue(oSrchColumn: ads_search_column): Integer;
var
  wrkPointer : PADSValue;
begin
  // advance the value pointer to the correct one of the potentially multiple
  // values in the "array of values" for this attribute
  wrkPointer := oSrchColumn.pADsValues;

  // depending on the type of the value, turning it into a string is more
  // or less straightforward
  case oSrchColumn.dwADsType of
    ADSTYPE_NUMERIC_STRING     : Result := StrToInt(wrkPointer^.__MIDL_0010.NumericString);
    ADSTYPE_BOOLEAN            : Result := wrkPointer^.__MIDL_0010.Boolean;
    ADSTYPE_INTEGER            : Result := wrkPointer^.__MIDL_0010.Integer;
    ADSTYPE_LARGE_INTEGER      : Result := wrkPointer^.__MIDL_0010.LargeInteger;
    else Result := -1;
  end;
end;

{-----------------------------------------------------------------------------}

Function ColumnToInteger(colName : WideString; DirSrch : IDirectorySearch; Handle : ADS_SEARCH_HANDLE) : Integer;
var
  oSrchColumn : ads_search_column;
  FResult         : HRESULT;
  pwColName   : PWideChar;
begin
  // Load the column
  pwColName :=  Addr(colName[1]);
  FResult := DirSrch.GetColumn(Handle, pwColName, oSrchColumn);
  if Succeeded(FResult) then
  begin
    // single valued attributes are quite straightforward
    Result   := GetADIntegerValue(oSrchColumn);
    // free the memory associated with the search column, and the column name
    DirSrch.FreeColumn(oSrchColumn);
  end
  else
    Result := -1;
end;

{-----------------------------------------------------------------------------}

Function ColumnToString(colName : WideString; DirSrch : IDirectorySearch; Handle : ADS_SEARCH_HANDLE) : String;
var
  oSrchColumn : ads_search_column;
  FResult         : HRESULT;
begin
  // Load each data item into the memo1 box.
  FResult := DirSrch.GetColumn(Handle, @colName[1], oSrchColumn);
  if Succeeded(FResult) then
  begin
    // single valued attributes are quite straightforward
    Result   := GetADStringValue(oSrchColumn);
    // free the memory associated with the search column, and the column name
    DirSrch.FreeColumn(oSrchColumn);
  end
  else
    Result := ColName + ' not available';
end;

{-----------------------------------------------------------------------------}

procedure GetDomainControllers(var DCs : TStrings; BindStr : String);
var
  x : IADsContainer;
  e : IEnumVariant;
  hr : integer;
  varArr : OleVariant;
  lNumElements : ULONG;
  item : IADs;
  AddStr : String;
begin

 ADsGetObject(BindStr, IID_IADsContainer, x); // bind to the object
 hr := ADsBuildEnumerator(x,e); // start enumerating
 while SUCCEEDED(hr) do
 begin
  // get the next contained object
  hr := ADsEnumerateNext(e,1,varArr,lNumElements);
  if (lNumElements<=0) then // are we done?
   break;
  //varArr contains an IDispatch pointer to the contained object.
  IDispatch(varArr).QueryInterface(IADs, item) ;

  AddStr := Item.Get('name');
  //now try to add the description, some dcs dont have a description so handle exception
  try
    AddStr := Format('%s (%s)', [AddStr, Item.Get('description')]);
  except
    AddStr := AddStr + ' (No Description)';
  end;
  DCs.Add(AddStr);
  
 end;
 //if e<>nil then
 // hr := ADsFreeEnumerator(e);
end;

{-----------------------------------------------------------------------------}

end.
