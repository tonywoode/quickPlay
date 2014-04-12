unit uQuery;

interface

Type

  TQPQueryField = (qfName = 0,
                  qfFileName = 1,
                  qfEmu = 2,
                  qfCompany = 3,
                  qfYear = 4,
                  qfType = 5,
                  qfNumPlay = 6,
                  qfPlayers = 7,
                  qfRating = 8);

  TQPQueryCondition = (qcEqual = 0,
                       qcNotEqual = 1,
                       qcContain = 2,
                       qcNotContain = 3);

  TQPQuery = Class
    Private
      Function FieldToStr() : String;
      Function ConditionToStr : String;
      Function GetConditionAsInt() : Integer;
      procedure SetConditionFromInt(value : Integer);
    Public
      Field : TQPQueryField;
      Filter : String;
      Condition : TQPQueryCondition;

      Property FieldStr : String read FieldToStr;
      Property ConditionStr : String read ConditionToStr;
      Property ConditionInt : Integer read GetConditionAsInt write SetConditionFromInt;

      constructor create(cField : TQPQueryField; cFilter : String; cCondition : TQPQueryCondition);overload;
      constructor create(InString : String);overload;

      procedure FromString(input : String);
      function ToString() : String;
  end;

implementation

uses Classes, SysUtils, JCLStrings, uQPConst;

Constructor TQPQuery.create(cField : TQPQueryField; cFilter : String; cCondition : TQPQueryCondition);
begin
  Field := cField;
  Filter := cFilter;
  Condition := cCondition;
end;

constructor TQPQuery.create(InString : String);
begin
  FromString(inString);
end;

Function TQPQuery.FieldToStr() : String;
begin

  Case Field of
    qfName : Result := QP_ROM_NAME_SHORT;
    qfFileName : Result := QP_ROM_FILENAME;
    qfEmu : Result := QP_ROM_EMU;
    qfCompany : Result := QP_ROM_COMPANY;
    qfYear : Result := QP_ROM_YEAR;
    qfType : Result := QP_ROM_TYPE;
    qfNumPlay : Result := QP_ROM_NUM_PLAY;
    qfPlayers : result := QP_ROM_PLAYERS;
    qfRating : Result := QP_ROM_RATING;
    else
      Result := '';
  end;
end;

Function TQPQuery.ConditionToStr : String;
begin
  case Condition of
    qcEqual : Result := QP_QUERY_EQUAL;
    qcNotEqual : Result := QP_QUERY_NOT_EQUAL;
    qcContain : Result := QP_QUERY_CONTAIN;
    qcNotContain : Result := QP_QUERY_NOT_CONTAIN;
    else Result := '';
  end;
end;

Function TQPQuery.GetConditionAsInt() : Integer;
begin
  Result := Integer(Condition);
end;

procedure TQPQuery.SetConditionFromInt(value : Integer);
begin
  Condition := TQPQueryCondition(Value);
end;

procedure TQPQuery.FromString(input : String);
var
  SplitList : TStringList;
begin
  //we need to create our splitlist stringlist
  SplitList := TStringList.Create;
  try
    // this function is from jedi code library.
    StrTokenToStrings(input, '¬', SplitList);
    Field := TQPQueryField(StrToInt(SplitList[0]));
    Filter := SplitList[1];
    Condition := TQPQueryCondition(StrToInt(SplitList[2]));
  finally
    FreeAndNil(SplitList);
  end;
end;

function TQPQuery.ToString() : String;
begin
  Result := IntToStr(Integer(Field)) + '¬' + Filter + '¬' + IntToStr(Integer(Condition));
end;

end.
