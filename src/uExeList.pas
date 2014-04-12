unit uExeList;

interface

uses SysUtils, Classes, Contnrs, Controls, Graphics;

type

  TQPExeList = class(TObjectList)
  protected
    _ExeIcons : TImageList;
    _FileName : String;
    _AllowWrite : Boolean;
    _IconThread : TThread;
  public
    constructor Create(eFile : TFileName; AllowWrite : Boolean);
    Destructor Destroy();override;
    Procedure ActivateEmuIconThread();
    procedure LoadFromFile(EnableIconThread : Boolean);virtual;abstract;
    procedure SaveToFile();virtual;abstract;
    Property ExeIcons : TImageList read _ExeIcons write _ExeIcons;
  end;

  TExeIconThread = class(TThread)
    List : TQPExeList;
    Icons : TImageList;
    constructor create(EList : TQPExeList; var IconList : TImageList);overload;
    procedure Execute; override;
  end;

implementation

uses uExe, uJFile;

{-----------------------------------------------------------------------------}
{ TExeIconThread }
{-----------------------------------------------------------------------------}

constructor TExeIconThread.create(EList : TQPExeList; var IconList : TImageList);
begin
  Self.List := EList;
  Self.Icons := IconList;
  inherited Create(True);
end;

{-----------------------------------------------------------------------------}

procedure TExeIconThread.Execute;
var
  i : Integer;
  myIcon : TIcon;
begin
  myIcon := TIcon.Create;
  try
    for i := 0 to Self.List.Count-1 do
    begin
      if Self.Terminated then
        Break;
        
      if FileExists(TQPExe(Self.List[i]).Path) then
      begin
        if ujFile.GetEXEIcon(myIcon, TQPExe(Self.List[i]).Path) then
          TQPExe(Self.List[i]).IconIndex := Icons.AddIcon(MyIcon)
      end;
    end;
  finally
    FreeAndNil(myIcon);
  end; 
end;


{-----------------------------------------------------------------------------}
{ TQPExeList }
{-----------------------------------------------------------------------------}

constructor TQPExeList.Create(eFile : TFileName; AllowWrite : Boolean);
begin
  inherited Create(true);
  _FileName := eFile;
  _AllowWrite := True;
  _ExeIcons := TImageList.Create(nil);
  _ExeIcons.Width := 24;
  _ExeIcons.Height := 24;
end;

{-----------------------------------------------------------------------------}

Destructor TQPExeList.Destroy();
begin

  if _IconThread <> nil then
  begin
    _IconThread.Terminate;
    _IconThread.WaitFor;
  end;
  FreeAndNil(_ExeIcons);
  inherited Destroy();
end;

{-----------------------------------------------------------------------------}

Procedure TQPExeList.ActivateEmuIconThread();
begin
  _ExeIcons.Clear;
  _IconThread := TExeIconThread.create(Self, _ExeIcons);
  _IconThread.Priority := tpLower;
  _IconThread.Resume;
end;

{-----------------------------------------------------------------------------}

end.
