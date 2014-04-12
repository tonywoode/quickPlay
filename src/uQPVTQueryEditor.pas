unit uQPVTQueryEditor;

interface

uses uQPVTEditor;

type

  TFilterEditLink = class(TQPVTEdit)
  protected
    procedure DoCustomEnd();override;
    procedure DoCustomPrepare();override;
  end;

implementation

uses uQuery, uJVirtualTree, StdCtrls, uQPConst;

{ TFilterEditLink }

procedure TFilterEditLink.doCustomEnd();
begin
  With Edit as TComboBox do
  begin
    If EditColumn = 0 then
    begin
      Case ItemIndex of
        0 : TQPQuery(GetObject(EditTree, EditNode)).Field := qfName;
        1 : TQPQuery(GetObject(EditTree, EditNode)).Field := qfFileName;
        2 : TQPQuery(GetObject(EditTree, EditNode)).Field := qfEmu;
        3 : TQPQuery(GetObject(EditTree, EditNode)).Field := qfCompany;
        4 : TQPQuery(GetObject(EditTree, EditNode)).Field := qfYear;
        5 : TQPQuery(GetObject(EditTree, EditNode)).Field := qfType;
        6 : TQPQuery(GetObject(EditTree, EditNode)).Field := qfNumPlay;
        7 : TQPQuery(GetObject(EditTree, EditNode)).Field := qfPlayers;
        8 : TQPQuery(GetObject(EditTree, EditNode)).Field := qfRating;
      end;
    end
    else
    begin
      //Its the contains box.
      TQPQuery(GetObject(EditTree, EditNode)).ConditionInt := ItemIndex;
      
    end;
  end;//end of WITH statement
end;

Procedure TFilterEditLink.doCustomPrepare();
begin
  CreateCombo();
  With FEdit as TComboBox do
  begin
    Style := csDropDownList;
    case EditColumn of
      0:
      begin
        //Add the list of possible filters.
        Items.Add(QP_ROM_NAME_SHORT);
        Items.Add(QP_ROM_FILENAME);
        Items.Add(QP_ROM_EMU);
        Items.Add(QP_ROM_COMPANY);
        Items.Add(QP_ROM_YEAR);
        Items.Add(QP_ROM_TYPE);
        Items.Add(QP_ROM_NUM_PLAY);
        Items.Add(QP_ROM_PLAYERS);
        Items.Add(QP_ROM_RATING);
        ItemIndex := Integer(TQPQuery(GetObject(EditTree, EditNode)).Field);
      end;
      1:
      begin
        Items.Add(QP_QUERY_EQUAL);
        Items.Add(QP_QUERY_NOT_EQUAL);
        Items.Add(QP_QUERY_CONTAIN);
        Items.Add(QP_QUERY_NOT_CONTAIN);
        ItemIndex := TQPQuery(GetObject(EditTree, EditNode)).ConditionInt;
      end;
    end;
  end;//end of WITH statement
end;

end.
 
