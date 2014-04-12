unit uQPDir;

interface

type

  TQPDir = class
  protected
    FFullPath : String;
    FDisplay : String;
    FUseCustomIcon : boolean;
    FNormalIcon : Integer;
    FSelIcon : Integer;
  public
    Property FullPath : String Read FFullPath Write FFullPath;
    Property DisplayText : String Read FDisplay Write FDisplay;
    Property CustomIcon : boolean Read FUseCustomIcon Write FUseCustomIcon;
    Property NormalIcon : Integer Read FNormalIcon Write FNormalIcon;
    Property SelIcon : Integer Read FSelIcon Write FSelIcon;
    constructor Create();overload;
    constructor Create(Display, Path : String; CustomIcon : Boolean; NIcon, SIcon : Integer);overload;
  end;

implementation

{-----------------------------------------------------------------------------}
{ TQPDir }
{-----------------------------------------------------------------------------}

constructor TQPDir.Create;
begin
  inherited Create();
  FDisplay := '';
  FFullPath := '';
  FUseCustomIcon := False;
  FNormalIcon := -1;
  FSelIcon := -1;
end;

constructor TQPDir.Create(Display, Path: String; CustomIcon: Boolean; NIcon,
  SIcon: Integer);
begin
  FDisplay := Display;
  FFullPath := Path;
  FUseCustomIcon := CustomIcon;
  FNormalIcon := NIcon;
  FSelIcon := SIcon;
end;


end.
 