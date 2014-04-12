unit uVersionCheckThread;

interface

uses SysUtils, Classes, Windows, Messages;

type

  TVersionCheckThread = class(TThread)
  protected
    _Hnd : HWND;
    _CurrentVer : String;
  public
    Constructor Create(Hnd : HWND; CurrentVer : String);
    procedure Execute();override;
  end;

const
  WM_UPDATE_AVAILABLE = WM_APP + 1020;
  WM_NO_UPDATE = WM_APP + 1021;
  WM_UPDATE_ERROR = WM_APP + 1022;
  VERSION_URL = 'http://quickplay.sourceforge.net/currentversion.php';
  
implementation

uses IdHTTP,
     JCLStrings;

{ TVersionCheckThread }

constructor TVersionCheckThread.Create(Hnd: HWND; CurrentVer: String);
begin
  Self._Hnd := Hnd;
  Self._CurrentVer := CurrentVer;
  inherited Create(False);
end;

procedure TVersionCheckThread.Execute;
var
  Tmp : TMemoryStream;
  verURL : STring;
  VerSTr : TStringList;
  idHTTP : TIdHTTP;
begin
  Tmp := TMemoryStream.Create;
  try

    VerURL := '';
    idHTTP := TIdHTTP.Create(nil);
    try

      idHTTP.HandleRedirects := True;
      idHTTP.AllowCookies := False;
      idHTTP.Request.Accept := 'text/plain';

      try
        idHTTP.Get(VERSION_URL, Tmp);

        VerStr := TStringList.Create;
        try
          Tmp.Position := 0;
          VerStr.LoadFromStream(Tmp);

          if JCLStrings.StrCompare(Trim(VerStr[0]), _CurrentVer) = 0 then
          begin
            PostMessage(_Hnd, WM_NO_UPDATE, 0, 0);
          end
          else
          begin
            PostMessage(_Hnd, WM_UPDATE_AVAILABLE, 0, 0);
          end;

        finally
          FreeAndNil(VerStr);
        end;

      except
        //send a message back to the main form informing that an error occurred.
        PostMessage(_Hnd, WM_UPDATE_ERROR, 0, 0);
      end;

    finally
      FreeAndNil(idHTTP);
    end;

  finally
    FreeAndNil(Tmp);
  end;


end;


end.
