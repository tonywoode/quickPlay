Unit uJVirtualTree;

interface

uses SysUtils, VirtualTrees, Graphics, IniFiles;

  procedure SetObject(Tree: TBaseVirtualTree; Node: PVirtualNode; Obj: TObject);
  function GetObject(Tree: TBaseVirtualTree; Node: PVirtualNode): TObject;

  //used in Incremental Search.
  function VTMin(const A, B: Integer): Integer;

type

  PVirtualStringTree = ^TVirtualStringTree;

  TJVTConfig = class(Tobject)
  protected
    _Caption : String;
    _VT : PVirtualStringTree;
    _Font : TFont;
    _ColourFocus : TColor;
    _ColourUnfocus : TColor;
    _ColourHotTrack : TColor;
    _ColourBackground : TColor;
    _bShowGridlines : Boolean;
    _bRowSelect : Boolean;
    _bHotTrack : Boolean;
    _bShowHints : Boolean;
    _bEnableBGImage : Boolean;
    _BGImage : PString;
    _iSelectionCurve : Integer;
    Function GetBGImage() : String;
    procedure SetBGImage(value : String);

  public
    constructor Create();overload;
    constructor Create(Tree : PVirtualStringTree; Cap : String; TmpWallPaper : PString);overload;
    destructor Destroy();override;
    Procedure Configure();
    Procedure LoadFromIni(var Ini : TMemIniFile);
    Procedure LoadFromTree();
    Procedure SaveToIni(var Ini : TMemIniFile);

    Property Caption : String Read _Caption write _Caption;
    Property VT : PVirtualStringTree read _VT write _VT;
    Property VTFont : TFont read _font write _font;
    Property ColourFocus : TColor read _ColourFocus write _ColourFocus;
    Property ColourUnfocus : TColor read _ColourUnfocus write _ColourUnfocus;
    Property ColourHotTrack : TColor read _ColourHotTrack write _ColourHotTrack;
    Property ColourBackground : TColor read _ColourBackground write _ColourBackground;
    Property ShowGridlines : Boolean read _bShowGridlines write _bShowGridlines;
    Property RowSelect : Boolean read _bRowSelect write _bRowSelect;
    Property HotTrack : Boolean read _bHotTrack write _bHotTrack;
    Property ShowHints : Boolean read _bShowHints write _bShowHints;
    Property EnableBGImage : Boolean read _bEnableBGImage write _bEnableBGImage;
    Property PBGImage : PString read _BGImage write _BGimage;
    Property BGImageValue : String read GetBGImage write SetBGImage;
    Property SelectionCurve : Integer read _iSelectionCurve write _iSelectionCurve;
  end;

implementation

{$I Compilers.inc}

uses ujWindowsMisc;

{-----------------------------------------------------------------------------}

// these 2 functions are written by Werner Lehmann and come from the
// VT support newsgroup.
procedure SetObject(Tree: TBaseVirtualTree; Node: PVirtualNode; Obj: TObject);
var
  Data: pointer;
begin
  assert(Node <> nil);
  Data := Tree.GetNodeData(Node);
  assert(Data <> nil);
  TObject(Data^) := Obj;
end;

//------------------------------------------------------------------------------

function GetObject(Tree: TBaseVirtualTree; Node: PVirtualNode): TObject;
var
  Data: pointer;
begin
  if (Node <> nil) then
  begin
    Data := Tree.GetNodeData(Node);
    if Data = nil then
      Result := nil
    else
      Result := TObject(Data^);
  end
  else
    Result := nil
end;

{-----------------------------------------------------------------------------}

function VTMin(const A, B: Integer): Integer;  {save us linking in math.pas}
begin
  if A < B then
    Result := A
  else
    Result := B;
end;

{-----------------------------------------------------------------------------}

{TJVTConfig code}

{-----------------------------------------------------------------------------}

constructor TJVTConfig.Create();
begin
  inherited Create;
  _Font := TFont.Create;
end;

{-----------------------------------------------------------------------------}

constructor TJVTConfig.Create(Tree : PVirtualStringTree; Cap : String; TmpWallPaper : PString);
begin
  inherited Create();
  _Caption := Cap;
  _VT := Tree;
  _Font := TFont.Create;
  _BGImage := TmpWallPaper;
end;

{-----------------------------------------------------------------------------}

destructor TJVTConfig.Destroy();
begin
  FreeAndNil(_Font);
  inherited Destroy();
end;

{-----------------------------------------------------------------------------}

Function TJVTConfig.GetBGImage() : String;
begin
  Result := _BGImage^;
end;

{-----------------------------------------------------------------------------}

procedure TJVTConfig.SetBGImage(value : String);
begin
  _BGImage^ := Value;
end;

{-----------------------------------------------------------------------------}

Procedure TJVTConfig.Configure();
begin
  _VT^.Font.Assign(_Font);
  _VT^.Colors.FocusedSelectionColor := _ColourFocus;
  _VT^.Colors.FocusedSelectionBorderColor := _ColourFocus;
  _VT^.Colors.UnfocusedSelectionColor := _ColourUnfocus;
  _VT^.Colors.UnfocusedSelectionBorderColor := _ColourUnfocus;
  _VT^.Colors.HotColor := _ColourHotTrack;
  _VT^.Color := _ColourBackground;

  with _VT^.TreeOptions do
  begin
    if _bShowGridlines then
      PaintOptions := (PaintOptions + [toShowHorzGridLines, toShowVertGridLines])
    else
      PaintOptions := (PaintOptions - [toShowHorzGridLines, toShowVertGridLines]);

    if _bRowSelect then
      SelectionOptions := (SelectionOptions + [toFullRowSelect])
    else
      SelectionOptions := (SelectionOptions - [toFullRowSelect]);

    if _bHotTrack then
      PaintOptions := PaintOptions+[TohotTrack]
    else
      PaintOptions := PaintOptions-[TohotTrack];

    if _bEnableBGImage then
      PaintOptions := PaintOptions + [toShowBackground]
    else
      PaintOptions := PaintOptions - [toShowBackground]

  end; //end of WITH block

  _VT^.ShowHint := _bShowHints;
  _VT^.SelectionCurveRadius := _iSelectionCurve;

//  _VT^.Header.Style := HSThickButtons;
  //hsXPStyle
  //hsFlatButtons
  //hsplates
  //hsThickButtons

end;

{-----------------------------------------------------------------------------}

Procedure TJVTConfig.LoadFromIni(var Ini : TMemIniFile);
var
  tmpFont : TFont;
begin
  _bShowGridlines := Ini.ReadBool(_VT^.Name, 'ShowGridlines', False);
  _bRowSelect := Ini.ReadBool(_VT^.Name, 'RowSelect', True);
  _bHotTrack := Ini.ReadBool(_VT^.Name, 'HotTrack', False);
  _bShowHints := Ini.ReadBool(_VT^.Name, 'ShowHints', False);
  _bEnableBGImage := Ini.ReadBool(_VT^.Name, 'EnableBGImage', False);
  if (_BGImage <> nil) and (_BGImage^ = '') then
    _BGImage^ := Ini.ReadString(_VT^.Name, 'BGImage', '');

  _iSelectionCurve := Ini.ReadInteger(_VT^.Name, 'SelectionCurve', 10);

  _ColourFocus := StringToColor( Ini.ReadString(_VT^.Name, 'ColourFocus', 'clHighLight') );
  _ColourUnFocus := StringToColor( Ini.ReadString(_VT^.Name, 'ColourUnFocus', 'clBtnFace') );
  _ColourHotTrack := StringToColor( Ini.ReadString(_VT^.Name, 'ColourHotTrack', 'clBlue') );
  _ColourBackground := StringToColor( Ini.ReadString(_VT^.Name, 'ColourBackground', 'clWindow') );

  tmpFont := TFont.Create;
  try
    ujWindowsMisc.GetWindowsFont(tmpFont, jwfMessage);
   // _Font.Assign(tmpFont);

    _Font.Name := ini.ReadString(_VT^.Name,'FontName', tmpFont.Name);
    if Ini.ValueExists(_VT^.Name,'FontColour') then
      _Font.Color := StringToColor( ini.ReadString(_VT^.Name,'FontColour', 'clBlack') )
    else
      _Font.Color := tmpFont.Color;

    _Font.Size := ini.ReadInteger(_VT^.Name,'FontSize', tmpFont.Size);

    if ini.ReadBool(_VT^.Name, 'FontBold', (fsbold in tmpFont.Style) ) then
      _Font.Style := _Font.Style + [fsBold];
    if ini.ReadBool(_VT^.Name, 'FontItalic', (fsItalic in TmpFont.Style)) then
      _Font.Style := _Font.Style + [fsItalic];
    if ini.ReadBool(_VT^.Name, 'FontUnderline', (fsUnderline in TmpFont.Style)) then
      _Font.Style := _Font.Style + [fsUnderline];
    if ini.ReadBool(_VT^.Name, 'FontStrike', (fsStrikeout in TmpFont.Style)) then
      _Font.Style := _Font.Style + [fsStrikeOut];
    
  finally
    FreeAndNil(tmpFont);
  end;
end;

{-----------------------------------------------------------------------------}

Procedure TJVTConfig.LoadFromTree();
begin

  //check there is a caption
  if _Caption = '' then
    _Caption := _VT^.Name;

  _Font.Assign(_VT^.Font);
  _ColourFocus := _VT^.Colors.FocusedSelectionColor;
  _ColourUnfocus := _VT^.Colors.UnfocusedSelectionColor;
  _ColourHotTrack := _VT^.Colors.HotColor;
  _ColourBackground := _VT^.Color;

  _bShowGridlines := (toShowHorzGridLines in _VT^.TreeOptions.PaintOptions);
  _bRowSelect := (toFullRowSelect in _VT^.TreeOptions.SelectionOptions);
  _bHotTrack := (toHotTrack in _VT^.TreeOptions.PaintOptions);
  _bShowHints := _VT^.ShowHint;
  _bEnableBGImage := (toShowBackground in _VT^.TreeOptions.PaintOptions);
  _iSelectionCurve := _VT^.SelectionCurveRadius;

end;

{-----------------------------------------------------------------------------}

Procedure TJVTConfig.SaveToIni(var Ini : TMemIniFile);
begin
  Ini.WriteBool(_VT^.Name, 'ShowGridlines', _bShowGridlines);
  Ini.WriteBool(_VT^.Name, 'RowSelect', _bRowSelect);
  Ini.WriteBool(_VT^.Name, 'HotTrack', _bHotTrack);
  Ini.WriteBool(_VT^.Name, 'ShowHints', _bShowHints);
  Ini.WriteBool(_VT^.Name, 'EnableBGImage', _bEnableBGImage);
  if _BGImage <> nil then
    Ini.WriteString(_VT^.Name, 'BGImage', _BGImage^);

  Ini.WriteString(_VT^.Name, 'ColourFocus', ColorToString(_ColourFocus));
  Ini.WriteString(_VT^.Name, 'ColourUnFocus', ColorToString(_ColourUnfocus));
  Ini.WriteString(_VT^.Name, 'ColourHotTrack', ColorToString(_ColourHotTrack));
  Ini.WriteString(_VT^.Name, 'ColourBackground', ColorToString(_ColourBackground));

  ini.WriteString(_VT^.Name,'FontName', _font.Name);
  ini.WriteString(_VT^.Name,'FontColour', ColorToString(_Font.Color));
  ini.writeInteger(_VT^.Name,'FontSize', _Font.Size);

  ini.WriteBool(_VT^.Name, 'FontBold', (fsbold in _font.Style));
  ini.WriteBool(_VT^.Name, 'FontItalic', (fsItalic in _font.Style));
  ini.WriteBool(_VT^.Name, 'FontUnderline', (fsUnderLine in _font.Style));
  ini.WriteBool(_VT^.Name, 'FontStrike', (fsStrikeOut in _font.Style));

  ini.WriteInteger(_VT^.Name, 'SelectionCurve', _iSelectionCurve);
end;

{-----------------------------------------------------------------------------}


end.
