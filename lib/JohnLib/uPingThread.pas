unit uPingThread;

interface

uses SysUtils, Classes, StdCtrls;

type

  TPingOneThread = class(TThread)
    PC : String;
    Lst : TListBox;
    NumPing : Integer;
    Msg : String;
    procedure AddToBox();
    constructor create(PC : String; NumberOfPings : Integer; Box : TListBox);overload;
    procedure Execute; override;
  end;

implementation

uses IdIcmpClient, IdBaseComponent, IdComponent, IdRawBase, IdRawClient;

{---------------------------------------------------------------------------}

procedure TPingOneThread.AddToBox();
begin
  Lst.Items.Add(Msg);
  Lst.Selected[Lst.Count-1] := True;
end;

{---------------------------------------------------------------------------}

constructor TPingOneThread.create(PC : String; NumberOfPings : Integer; Box : TListBox);
begin
  Self.PC := PC;
  Self.NumPing := NumberOfPings;
  Self.Lst := Box;
  FreeOnTerminate := True;
  inherited Create(False);
end;

{---------------------------------------------------------------------------}

procedure TPingOneThread.Execute;
var
  ICMP : TidICMPClient;
  i : Integer;
  sTime : String;
begin
  ICMP := TidICMPClient.Create(nil);
  try

    ICMP.Host := PC;
    ICMP.ReceiveTimeout := 1000;

    for i := 0 to NumPing-1 do
    begin

      if Self.Terminated then
        Exit;

      ICMP.Ping();
      case ICMP.ReplyStatus.ReplyStatusType of
        rsEcho:
          Begin
            if (ICMP.ReplyStatus.MsRoundTripTime = 0) then
              sTime := '<1'
            else
              sTime := '=';

            Msg := Format('Reply From %s: bytes=%d time%s%d ms TTL=%d ',
              [ICMP.ReplyStatus.FromIpAddress,
              ICMP.ReplyStatus.BytesReceived,
              sTime,
              ICMP.ReplyStatus.MsRoundTripTime,
              ICMP.ReplyStatus.TimeToLive]);
          end;

        rsError : Msg := 'Error Occurred';
        rsTimeOut : Msg := 'Timed Out';
        rsErrorUnreachable : Msg := 'Destination Unreachable';
        rsErrorTTLExceeded : Msg := 'Error TTL Expired in Transit';

      end; //end of Case statement

      if Self.Terminated then
        Exit;

      Synchronize(AddToBox);

    end;

  finally
    FreeAndNil(ICMP);
  end;
end;

{---------------------------------------------------------------------------}

end.
