unit fParamVars;

interface

uses
  Windows, SysUtils, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, VirtualTrees, fJWinFontForm;

type
  TFrmParamVars = class(TJWinFontForm)
    VTVars: TVirtualStringTree;
    procedure FormShow(Sender: TObject);
    procedure VTVarsPaintText(Sender: TBaseVirtualTree;
      const TargetCanvas: TCanvas; Node: PVirtualNode; Column: TColumnIndex;
      TextType: TVSTTextType);
    procedure VTVarsGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType; var CellText: WideString);
    procedure FormDestroy(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
    _Vars : TStringList;
  public
    { Public declarations }
  end;

implementation

{$R *.dfm}

procedure TFrmParamVars.FormCreate(Sender: TObject);
begin

  _Vars := TStringList.Create;
  _Vars.BeginUpdate;
  try
    _Vars.Capacity := 11;

    _Vars.Add('%ROM%=The full path to the selected ROM.');
    _vars.Add('%ROMFILENAME%=The filename of the ROM, includes file extension.');
    _vars.Add('%ROMFILENAMENOEXT%=The filename of the ROM, with NO file extension.');
    _vars.Add('%ROMDIR%=The directory of the ROM.');
    _vars.Add('%SHORTROM%=The full path to the selected ROM in (8:3) format');
    _vars.Add('%ROMMAME%=The name (or MAME name) of the emulator');
    _vars.Add('%TOOL:toolvariable%=Launch tool specified by "toolvariable"');
    _vars.Add('%EXECFG%=Emulator/Tool configuration file.');
    _vars.Add('%EXEPATH%=Full path to associated emulator/Tool');
    _vars.Add('       - Note: MOVES POSITION OF EMULATOR CALL');
    _vars.Add('%EXEDIR%=The associated emulators/Tool directory');
  finally
    _Vars.EndUpdate();
  end;

  VTVars.RootNodeCount := _Vars.Count;

end;

procedure TFrmParamVars.FormDestroy(Sender: TObject);
begin
  FreeAndNil(_Vars);
end;

procedure TFrmParamVars.FormShow(Sender: TObject);
begin
   //position the form correctly
  Self.Top :=  TForm(Self.Owner).Top - 50;
  Self.Left := TForm(Self.Owner).Left - 50;
end;

procedure TFrmParamVars.VTVarsGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin
  if Node <> nil then
  begin

    Case column of
      0: CellText := _Vars.Names[Node.Index];
      1: CellText := _Vars.ValueFromIndex[Node.Index];
    end;

  end;
end;

procedure TFrmParamVars.VTVarsPaintText(Sender: TBaseVirtualTree;
  const TargetCanvas: TCanvas; Node: PVirtualNode; Column: TColumnIndex;
  TextType: TVSTTextType);
begin
  if Column = 0 then
    TargetCanvas.Font.Style := [fsBold];
end;

end.
