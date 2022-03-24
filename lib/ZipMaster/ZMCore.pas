unit ZMCore;

(*
  ZMCore.pas - event triggering
  TZipMaster VCL by Chris Vleghert and Eric W. Engler
  v1.79
  Copyright (C) 2005  Russell Peters


  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License (licence.txt) for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  contact: problems AT delphizip DOT org
  updates: http://www.delphizip.org

  modified 2005-11-05
---------------------------------------------------------------------------*)

interface

{$INCLUDE ZipConfig.inc}  
{$INCLUDE '.\ZipVers.inc'}
 {.$DEFINE DEBUG_PROGRESS}

uses
  Classes, SysUtils, Controls, Forms, Dialogs,
    ZipMstr, ZMMsgStr, ZMXcpt, ZMDelZip;

const
  RESOURCE_ERROR: String =
    'ZMRes.res is probably not linked to the executable' + #10 +
    'Missing String ID is: %d ';

type 
  TZipEventsRec = packed record
    OnCheckTerminate: TCheckTerminateEvent;
    OnItemProgress: TItemProgressEvent;
    OnMessage: TMessageEvent;
    OnProgress: TProgressEvent;
    OnProgressDetails: TProgressDetailsEvent;
    OnTick: TTickEvent;
    OnTotalProgress: TTotalProgressEvent;
    OnZipDialog: TZipDialogEvent;
    OnCopyZipOverwrite: TCopyZipOverwriteEvent;
    OnCRC32Error: TCRC32ErrorEvent;
    OnDirUpdate: TNotifyEvent;
    OnExtractOverwrite: TExtractOverwriteEvent;
    OnExtractSkipped: TExtractSkippedEvent;
    OnFileComment: TFileCommentEvent;
    OnFileExtra: TFileExtraEvent;
    OnNewName: TNewNameEvent;
    OnPasswordError: TPasswordErrorEvent;
    OnSetAddName: TSetAddNameEvent;
    OnSetExtName: TSetExtNameEvent;
    OnSetNewName: TSetNewNameEvent;
{$IFNDEF NO_SPAN}
    OnGetNextDisk: TGetNextDiskEvent;
    OnStatusDisk: TStatusDiskEvent;                     
{$ENDIF}
  end;      
  pZipEventsRec = ^TZipEventsRec;
    

const
  zprFile     = 0;
  zprArchive  = 1;
  zprCopyTemp = 2;
  zprSFX      = 3;
  zprHeader   = 4;
  zprFinish   = 5;
  zprCompressed = 6;
  zprCentral  = 7;
  zprChecking = 8;
  zprLoading  = 9;
  zprJoining  = 10;
  zprSplitting = 11;
      (*
type 
  ActionCodes = (zacTick, zacItem, zacProgress, zacEndOfBatch, zacMessage,
    zacCount, zacSize, zacNewName, zacPassword, zacCRCError, zacOverwrite,
    zacSkipped, zacComment, zacStream, zacData, zacXItem, zacXProgress,
    zacExtName, zacNone);
   *)
type
  TZipDelayedItems = (zdiList, zdiComment);
  TZipDelays = set of TZipDelayedItems;

  TZipShowProgress = (zspNone, zspFull, zspExtra);

  TZipAllwaysItems = (zaaYesOvrwrt);//, zyaDummy);
  TZipAnswerAlls = set of TZipAllwaysItems;

type
  TProgDetails = class(TProgressDetails)
  public
    procedure Advance(adv: Cardinal);
    procedure AdvanceXtra(adv: Cardinal);
    procedure Clear;
    procedure SetCount(Count: Cardinal);
    procedure SetEnd;
    procedure SetItem(const fname: String; fsize: Cardinal);
    procedure SetItemXtra( const xmsg: String; fsize: Cardinal);
    procedure SetSize(FullSize: Int64);
    procedure Written(bytes: Int64);
  end;

type
  TZMCore = class(TObject)//TZipInfos)
  private
    FCurWaitCount: Integer;
    FEvents: TZipEventsRec;
    FSaveCursor: TCursor;
    function GetEventsRec: pZipEventsRec;
    function GetMessage: String;
    procedure SetEventsRec(const Value: pZipEventsRec);
    procedure SetTempDir(const Value: String);
  protected
    FActive: Boolean;
    FAnswerAll: TZipAnswerAlls;
    FBusy: Boolean;
    fCancel: Boolean; 
    FErrCode: Integer;
    FEventErr: String;
    fFullErrCode: Integer;
    fIsDestructing: Boolean;
    FMaster: TCustomZipMaster;
    FMessage: String;
    FNotMainTask: Boolean;
    FProgDetails: TProgressDetails;
    FReenter: Boolean;
    FTempDir: String;
    fTrace: Boolean;
    FUnattended: Boolean;
    fVerbose: Boolean;
    function Call_back(ActionCode: ActionCodes; ErrorCode: Integer; Msg: String;
        FileSize: Cardinal): Boolean; virtual;
    procedure Done; virtual;
    function GetTotalSizeToProcess: Int64;
    procedure SetCancel(Value: Boolean); virtual;
    procedure Starting; virtual;
    function ZipMessageDialog(const title: String; var msg: String; context:
        Integer; btns: TMsgDlgButtons): TModalResult;
    procedure ZipMessageDlg(const msg: String; context: Integer); overload;
    function ZipMessageDlgEx(const title, msg: String; context: Integer; btns:
        TMsgDlgButtons): TModalResult; overload;     
    property Events: TZipEventsRec read FEvents;// write FEvents;
  public
    constructor Create(AMaster: TCustomZipMaster);
    destructor Destroy; override;
    procedure Attacked(AnObject: TObject);
    procedure Clear; virtual;
    function MakeTempFileName(Prefix, Extension: String): String;
    procedure Report(ActionCode: ActionCodes; ErrorCode: Integer; Msg: String;
        FileSize: Int64); overload; 
    procedure ShowExceptionError(const ZMExcept: EZipMaster);
    procedure ShowZipFmtMessage(Id: Integer; const Args: array of const);
    procedure ShowZipMessage(Ident: Integer; const UserStr: String);
    procedure StartWaitCursor;
    procedure StopWaitCursor; 
//    property PrefLang: TZipInfoLanguages read GetPrefLang write SetPrefLang;
    property Busy: Boolean read FBusy write fBusy;
    property Cancel: Boolean read fCancel write SetCancel;
    property ErrCode: Integer read fErrCode write fErrCode;
    property EventsRec: pZipEventsRec read GetEventsRec write SetEventsRec;
    property FullErrCode: Integer read FFullErrCode;
    property Master: TCustomZipMaster read fMaster write fMaster;
    property Message: String read GetMessage write fMessage;
    property NotMainTask: Boolean read fNotMainTask write fNotMainTask;
    property Reentry: Boolean read FReenter write FReenter;
    property TempDir: String read FTempDir write SetTempDir;
    property Trace: Boolean read FTrace write FTrace;
    property Unattended: Boolean read FUnattended write FUnattended;
    property Verbose: Boolean read FVerbose write FVerbose;
  end;

implementation
 

uses Windows, ZMUtils, ZMDlg, ZipMsg, ZMCtx;

//const
//  RESOURCE_ERROR: String =
//    'ZipMsgXX.res is probably not linked to the executable' + #10 +
//    'Missing String ID is: %d ';

  {TProgDetails}
procedure TProgDetails.Advance(adv: Cardinal);
begin
  Inc(FTotalPosition, adv);
  Inc(FItemPosition, adv);
  FProgType := ProgressUpdate;
end;

procedure TProgDetails.AdvanceXtra(adv: Cardinal);
begin
  Inc(FItemPosition, adv);
  FProgType := ExtraUpdate;
end;

procedure TProgDetails.Clear;
begin
  FProgType     := EndOfBatch;
  FItemCount    := 0;
  FWritten      := 0;
  FTotalSize    := 0;
  FTotalPosition := 0;
  FItemSize     := 0;
  FItemPosition := 0;
  FItemName     := '';
  FItemNumber   := 0;
end;

procedure TProgDetails.SetCount(Count: Cardinal);
begin
  Clear;
  FItemCount  := Count;
  FItemNumber := 0;
  FProgType   := TotalFiles2Process;
end;

procedure TProgDetails.SetEnd;
begin
  FItemName := '';
  FItemSize := 0;
  FProgType := EndOfBatch;
end;

procedure TProgDetails.SetItem(const fname: String; fsize: Cardinal);
begin
  Inc(FItemNumber);
  FItemName     := fname;
  FItemSize     := fsize;
  FItemPosition := 0;
  FProgType     := NewFile;
end;

procedure TProgDetails.SetItemXtra(const xmsg: String; fsize: Cardinal);
begin
  FItemName     := xmsg;
  FItemSize     := fsize;
  FItemPosition := 0;
  FProgType     := NewExtra;
end;

procedure TProgDetails.SetSize(FullSize: Int64);
begin
  FTotalSize := FullSize;
  FTotalPosition := 0;
  FItemName := '';
  FItemSize := 0;
  FItemPosition := 0;
  FProgType := TotalSize2Process;
  FWritten := 0;
end;

procedure TProgDetails.Written(bytes: Int64);
begin
  FWritten := bytes;
end;

 {TZMCore}
procedure TZMCore.Attacked(AnObject: TObject);
begin
  fReenter := True;
  if Verbose then
    Report(zacMessage, 0, 'Re-entry', 0);
end;

(*? TZMCore.Call_Back
  return true if handled
*)
function TZMCore.Call_back(ActionCode: ActionCodes; ErrorCode: Integer;
  Msg: String; FileSize: Cardinal): Boolean;
begin
  Result := False;
end;

procedure TZMCore.Clear;
begin
  SetZipMsgLanguage('');
//  RestoreDefault;  // clear languages
  FReenter := False;
  FMessage := '';
  fCancel := False;
  FErrCode := 0;
  fFullErrCode := 0;
  FUnattended := False;
  fVerbose := False;
  fTrace := False;
  TProgDetails(FProgDetails).Clear;
  FEventErr      := '';
  fIsDestructing := False;
end;

constructor TZMCore.Create(AMaster: TCustomZipMaster);
begin
  inherited Create;
  FMaster  := AMaster;
  FActive  := False;
  FProgDetails := TProgDetails.Create;
  FMessage := '';
  FErrCode := -1;
  FUnattended := True;                      // during construction
  FCurWaitCount := 0;
  FVerbose := False;
  FTrace   := False;
  FTempDir := '';
  FNotMainTask := False;
end;

destructor TZMCore.Destroy;
begin
  FreeAndNil(FProgDetails);
  inherited;
end;

procedure TZMCore.Done;
begin
  fBusy := False;
  if ( not fNotMainTask) and (FCurWaitCount > 0) then
  begin
    FCurWaitCount := 0;
    Screen.Cursor := FSaveCursor;
  end;
end;

function TZMCore.GetEventsRec: pZipEventsRec;
begin
  Result := @FEvents;
end;

(*? TZMCore.GetMessage
1.73 13 July 2003 RP only return message if error
*)
function TZMCore.GetMessage: String;
begin
  Result := '';
  if FErrCode <> 0 then
  begin
    Result := fMessage;
    if Result = '' then
      Result := ZipLoadStr(FErrCode);
    if Result = '' then
      Result := ZipFmtLoadStr(GE_Unknown, [FErrCode]);
  end;
end;
//? TZMCore.GetMessage

function TZMCore.GetTotalSizeToProcess: Int64;
begin
  Result := TProgDetails(FProgDetails).TotalSize;
end;

(*? TZMCore.MakeTempFileName
  Make a temporary filename like: C:\...\zipxxxx.zip
  Prefix and extension are default: 'zip' and '.zip'
*)
function TZMCore.MakeTempFileName(Prefix, Extension: String): String;
var
  Buffer: Pchar;
  len:    DWORD;
begin
  Buffer := NIL;
  if Prefix = '' then
    Prefix := 'zip';
  if Extension = '' then
    Extension := '.zip';
  try
    if Length(FTempDir) = 0 then            // Get the system temp dir
    begin
      // 1. The path specified by the TMP environment variable.
      // 2. The path specified by the TEMP environment variable, if TMP is not defined.
      // 3. The current directory, if both TMP and TEMP are not defined.
      len := GetTempPath(0, Buffer);
      GetMem(Buffer, (len + 12) * sizeof(Char));
      GetTempPath(len, Buffer);
    end
    else                                    // Use Temp dir provided by ZipMaster
    begin
      FTempDir := DelimitPath(FTempDir, True); 
      GetMem(Buffer, (Length(FTempDir) + 13) * sizeof(Char));
      StrPLCopy(Buffer, FTempDir, Length(FTempDir) + 1);
    end;
    if GetTempFileName(Buffer, PChar(Prefix), 0, Buffer) <> 0 then
    begin
      DeleteFile(Buffer); // Needed because GetTempFileName creates the file also.
      Result := ChangeFileExt(Buffer, Extension); // And finally change the extension.
    end;
  finally
    FreeMem(Buffer);
  end;
end;
//? TZMCore.MakeTempFileName

(*? TZMCore.Report
1.77.2.0 14 September 2004 - RP fix setting ErrCode caused re-entry
1.77.2.0 14 September 2004 - RP alter thread support & OnCheckTerminate
1.77 16 July 2004 - RP preserve last errors message
1.76 24 April 2004 - only handle 'progress' and information
*)
procedure TZMCore.Report(ActionCode: ActionCodes; ErrorCode: Integer;
  Msg: String; FileSize: Int64);
var
  DoStop:  Boolean;
  Details: TProgDetails;
  Erm:     String;
  tmpTick: TTickEvent;
  tmpProgress: TProgressEvent;
  tmpProgressDetails: TProgressDetailsEvent;
  tmpItemProgress: TItemProgressEvent;
  tmpTotalProgress: TTotalProgressEvent;
  tmpMessage: TMessageEvent;
  tmpCheckTerminate: TCheckTerminateEvent;
begin
  if fIsDestructing then
    exit;
  if ActionCode <> zacNone then
  begin
    Details := FProgDetails as TProgDetails;
    case ActionCode of
      zacTick: { 'Tick' Just checking / processing messages}
      begin
        tmpTick := Events.OnTick;
        if assigned(tmpTick) then
          tmpTick(Master);
      end;
      zacItem: { progress type 1 = starting any ZIP operation on a new file }
      begin
        tmpProgress := Events.OnProgress;
{$IFDEF ALLOW_2G}
        if Assigned(tmpProgress) then
          tmpProgress(Master, NewFile, Msg, FileSize);
{$ELSE}                             
        if Assigned(tmpProgress) then
          tmpProgress(Master, NewFile, Msg, Lo64(FileSize));
{$ENDIF}
        Details.SetItem(Msg, Lo64(FileSize));//FileSize);
{$IFDEF DEBUG_PROGRESS}
        if Verbose then
          with Details do
            Report(zacMessage, 0, Format('#Item - "%s" %d', [ItemName, ItemSize]), 0);
{$ENDIF}
        tmpProgressDetails := Events.OnProgressDetails;
        if Assigned(tmpProgressDetails) then
          tmpProgressDetails(Master, Details);   
        tmpItemProgress := Events.OnItemProgress;
        if Assigned(tmpItemProgress) then
          tmpItemProgress(Master, Details.ItemName, FileSize, 0);
      end;
      zacProgress:           { progress type 2 = increment bar }
      begin          
        tmpProgress := Events.OnProgress;
{$IFDEF ALLOW_2G}
        if Assigned(tmpProgress) then
          tmpProgress(Master, ProgressUpdate, '', FileSize);
{$ELSE}
        if Assigned(tmpProgress) then
          tmpProgress(Master, ProgressUpdate, '', Lo64(FileSize));
{$ENDIF}
        Details.Advance(Lo64(FileSize));//FileSize);
{$IFDEF DEBUG_PROGRESS}
        if Verbose then
          with Details do
            Report(zacMessage, 0,
              Format('#Progress - [inc:%d] ipos:%d isiz:%d, tpos:%d tsiz:%d',
              [FileSize, ItemPosition, ItemSize, TotalPosition, TotalSize]), 0);
{$ENDIF}                            
        tmpProgressDetails := Events.OnProgressDetails;
        if Assigned(tmpProgressDetails) then
          tmpProgressDetails(Master, Details);   
        tmpItemProgress := Events.OnItemProgress;
        if Assigned(tmpItemProgress) then
          tmpItemProgress(Master, Details.ItemName, Details.ItemPosition,
            Details.ItemPerCent);
        tmpTotalProgress := Events.OnTotalProgress;
        if Assigned(tmpTotalProgress) then
          tmpTotalProgress(Master, Details.TotalSize, Details.TotalPerCent);
      end;
      zacEndOfBatch:          { end of a batch of 1 or more files }
      begin                     
        tmpProgress := Events.OnProgress;
        if Assigned(tmpProgress) then
          tmpProgress(Master, EndOfBatch, '', 0);
        Details.SetEnd;
{$IFDEF DEBUG_PROGRESS}
        if Verbose then
          Report(zacMessage, 0, '#End Of Batch', 0);
{$ENDIF}                          
        tmpProgressDetails := Events.OnProgressDetails;
        if Assigned(tmpProgressDetails) then
          tmpProgressDetails(Master, Details);
        tmpItemProgress := Events.OnItemProgress;
        if Assigned(tmpItemProgress) then
          tmpItemProgress(Master, Details.ItemName, 0, 101);
        tmpTotalProgress := Events.OnTotalProgress;
        if Assigned(tmpTotalProgress) then
          tmpTotalProgress(Master, 0, 101);
      end;
      zacMessage:              { a routine status message }
      begin
        Erm := Msg;
        if ErrorCode <> 0 then      // W'll always keep the last ErrorCode
        begin
          FMessage := Msg;
          FErrCode := Integer(ShortInt(ErrorCode and $FF));
          if (FErrCode = 9) and (fEventErr <> '') then // user cancel
          begin
            FMessage := ZipFmtLoadStr(GE_EventEx, [fEventErr]);
            Erm      := FMessage;
          end;
          fFullErrCode := ErrorCode;
        end;
        tmpMessage := Events.OnMessage;
        if Assigned(tmpMessage) then
          tmpMessage(Master, ErrorCode, Erm);
      end;

      zacCount:              { total number of files to process }
      begin
        Details.SetCount(FileSize);
{$IFDEF DEBUG_PROGRESS}
        if Verbose then
          Report(zacMessage, 0, Format('#Count - %d', [Details.TotalCount]), 0);
{$ENDIF}                                       
        tmpProgressDetails := Events.OnProgressDetails;
        if Assigned(tmpProgressDetails) then
          tmpProgressDetails(Master, Details);
        tmpProgress := Events.OnProgress;
{$IFDEF ALLOW_2G}    
        if Assigned(tmpProgress) then
          tmpProgress(Master, TotalFiles2Process, '', FileSize);
{$ELSE}              
        if Assigned(tmpProgress) then
          tmpProgress(Master, TotalFiles2Process, '', Lo64(FileSize));
{$ENDIF}
      end;
      zacSize:           { total size of all files to be processed }
      begin
        Details.SetSize(FileSize);
{$IFDEF DEBUG_PROGRESS}
        if Verbose then
          Report(zacMessage, 0, Format('#Size - %d', [Details.TotalSize]), 0);
{$ENDIF}                                     
        tmpProgressDetails := Events.OnProgressDetails;
        if Assigned(tmpProgressDetails) then
          tmpProgressDetails(Master, Details);
        tmpProgress := Events.OnProgress;
{$IFDEF ALLOW_2G}   
        if Assigned(tmpProgress) then
          tmpProgress(Master, TotalSize2Process, '', FileSize);
{$ELSE}            
        if Assigned(tmpProgress) then
          tmpProgress(Master, TotalSize2Process, '', Lo64(FileSize));
{$ENDIF}
      end;

      zacXItem:   { progress type 15 = starting new extra operation }
      begin      
        tmpProgress := Events.OnProgress;
{$IFDEF ALLOW_2G}   
        if Assigned(tmpProgress) then
          tmpProgress(Master, NewExtra, Msg, FileSize);
{$ELSE}           
        if Assigned(tmpProgress) then
          tmpProgress(Master, NewExtra, Msg, Lo64(FileSize));
{$ENDIF}
        Details.SetItemXtra(ZipLoadStr(PR_Progress + ErrorCode), FileSize);
{$IFDEF DEBUG_PROGRESS}
        if Verbose then
          Report(zacMessage, 0, Format('#XItem - %s size = %d',
            [Details.ItemName, FileSize]), 0);
{$ENDIF}                                   
        tmpProgressDetails := Events.OnProgressDetails;
        if Assigned(tmpProgressDetails) then
          tmpProgressDetails(Master, Details);   
        tmpItemProgress := Events.OnItemProgress;
        if Assigned(tmpItemProgress) then
          tmpItemProgress(Master, Details.ItemName, FileSize, 0);
      end;

      zacXProgress: { progress type 16 = increment bar for extra operation}
      begin    
        tmpProgress := Events.OnProgress;
{$IFDEF ALLOW_2G} 
        if Assigned(tmpProgress) then
          tmpProgress(Master, ExtraUpdate, Details.ItemName, FileSize);
{$ELSE}           
        if Assigned(tmpProgress) then
          tmpProgress(Master, ExtraUpdate, Details.ItemName, Lo64(FileSize));
{$ENDIF}
        Details.AdvanceXtra(FileSize);
{$IFDEF DEBUG_PROGRESS}
        if Verbose then
          Report(zacMessage, 0, Format('#XProgress - [inc:%d] pos:%d siz:%d',
            [FileSize, Details.ItemPosition, Details.ItemSize]), 0);
{$ENDIF}                                    
        tmpProgressDetails := Events.OnProgressDetails;
        if Assigned(tmpProgressDetails) then
          tmpProgressDetails(Master, Details);
        tmpItemProgress := Events.OnItemProgress;
        if Assigned(tmpItemProgress) then
          tmpItemProgress(Master, Details.ItemName, Details.ItemSize,
            Details.ItemPerCent);
      end;

      else                                    {unhandled event}
        Call_Back(ActionCode, ErrorCode, Msg, FileSize);
    end;                                    {end case }
  end;
  tmpCheckTerminate := Events.OnCheckTerminate;
  if assigned(tmpCheckTerminate) then
  begin
    DoStop := Cancel;
    tmpCheckTerminate(Master, DoStop);
    if DoStop then
      Cancel := True;
  end
  else
  if not fNotMainTask then
    Application.ProcessMessages;
end;
//? TZMCore.Report

procedure TZMCore.SetCancel(Value: Boolean);
begin
  fCancel := Value;
end;

procedure TZMCore.SetEventsRec(const Value: pZipEventsRec);
begin
  // not permitted
end;

procedure TZMCore.SetTempDir(const Value: String);
var
  drt: Integer;
  Drive: string;
begin
  if FTempDir <> Value then
  begin
    if Value <> '' then
    begin
      Drive := ExtractFileDrive(value) + '\';
      drt := GetDriveType(pChar(Drive));
      // only fixed drive or ramdisk is fast enough to be used as tempdir
      if((drt <> DRIVE_FIXED) and (drt <> DRIVE_RAMDISK)) then
        raise EZipMaster.createResDrive( DS_NotChangeable, Value);
    end;
    FTempDir := Value;
  end;
end;

(*? TZMCore.ShowExceptionError
1.80 strings already formatted
// Somewhat different from ShowZipMessage() because the loading of the resource
// string is already done in the constructor of the exception class.
*)
procedure TZMCore.ShowExceptionError(const ZMExcept: EZipMaster);
var
  tmpMessage: TMessageEvent;
begin
  FErrCode := ZMExcept.ResId;
  FMessage := ZMExcept.Message;

  if ZMExcept.FDisplayMsg and not FUnattended then  
    ZipMessageDlg(FMessage, zmtError + DHC_ExMessage);

  tmpMessage := Events.OnMessage;
  if Assigned(tmpMessage) then
    tmpMessage(Master, FErrCode {0}, FMessage);
end;
//? TZMCore.ShowExceptionError

(*? TZMCore.ShowZipFmtMessage
1.79 added
*)
procedure TZMCore.ShowZipFmtMessage(Id: Integer; const Args: array of const);
var
  tmpMessage: TMessageEvent;
begin
  tmpMessage := Events.OnMessage;
  if (not FUnattended) or Assigned(tmpMessage) then
  begin
    FMessage := ZipFmtLoadStr(Id, Args);
    ErrCode  := Id;

    if not FUnattended then
      ZipMessageDlg(FMessage, zmtInformation + DHC_ZipMessage);

    if Assigned(tmpMessage) then
      tmpMessage(Master, FErrCode, FMessage);
  end;
end;
//? TZMCore.ShowZipFmtMessage

(*? TZMCore.ShowZipMessage
*)
procedure TZMCore.ShowZipMessage(Ident: Integer; const UserStr: String);
var
  Msg: String;
  tmpMessage: TMessageEvent;
begin
  tmpMessage := Events.OnMessage;
  if (not FUnattended) or Assigned(tmpMessage) then
  begin
    Msg := ZipLoadStr(Ident);
    if Msg = '' then
      Msg := Format(RESOURCE_ERROR, [Ident]);
    Msg := Msg + UserStr;
    FMessage := Msg;
    ErrCode  := Ident;

    if not FUnattended then
      ZipMessageDlg(Msg, zmtInformation + DHC_ZipMessage);

    if Assigned(tmpMessage) then
      tmpMessage(Master, FErrCode, Msg);
  end;
end;
//? TZMCore.ShowZipMessage

(*? TZMCore.Starting
*)
procedure TZMCore.Starting;
begin
  fReenter := False;
  fBusy    := True;
  FAnswerAll := [];
  if GetCurrentThreadID <> MainThreadID then
    NotMainTask := true;
end;
//? TZMCore.Starting

(*? TZMCore.StartWaitCursor
1.75.0.5 10 March 2004 only set wait if forground task
*)
procedure TZMCore.StartWaitCursor;
begin
  if not fNotMainTask then
  begin
    if FCurWaitCount = 0 then
    begin
      FSaveCursor   := Screen.Cursor;
      Screen.Cursor := crHourglass;
    end;
    Inc(FCurWaitCount);
  end;
end;
//? TZMCore.StartWaitCursor

(*? TZMCore.StopWaitCursor
1.75.0.5 10 March 2004 only set wait if forground task
*)
procedure TZMCore.StopWaitCursor;
begin
  if ( not fNotMainTask) and (FCurWaitCount > 0) then
  begin
    Dec(FCurWaitCount);
    if (FCurWaitCount = 0) then
      Screen.Cursor := FSaveCursor;
  end;
end;
//? TZMCore.StopWaitCursor

function TZMCore.ZipMessageDialog(const title: String; var msg: String;
  context: Integer; btns: TMsgDlgButtons): TModalResult;
var
  dlg: TZipDialogBox;
  t, s:   String;
  ctx: Integer;
  tmpZipDialog: TZipDialogEvent;
begin
  t := title;
  if title = '' then
    t := Application.Title;
  if Verbose then
    t := Format('%s   (%d)',[t, context and $FFFF]);
  tmpZipDialog := Events.OnZipDialog;
  if assigned(tmpZipDialog) then
  begin
    s   := msg;
    ctx := context;
    tmpZipDialog(Master, t, s, ctx, btns);
    if (ctx > 0) and (ctx <= Ord(mrYesToAll)) then
    begin
      msg := s;
      Result := TModalResult(ctx);
      exit;
    end;
  end;
  dlg := TZipDialogBox.CreateNew2(Application,  context);
  try
    dlg.Build(t, msg, btns);
    dlg.ShowModal();
    Result := dlg.ModalResult; 
    if dlg.DlgType = zmtPassword then
    begin
      if (Result = mrOk) then
        Msg := dlg.Pwrd
      else
        Msg := '';
    end;
  finally
    FreeAndNil(dlg);
  end;
end;

procedure TZMCore.ZipMessageDlg(const msg: String;
  context: Integer);
begin
  ZipMessageDlgEx('', msg, context, [mbOk]);
end;

function TZMCore.ZipMessageDlgEx(const title, msg: String; context: Integer;
  btns: TMsgDlgButtons): TModalResult;
var
  m: String;
begin
  m      := msg;
  Result := ZipMessageDialog(title, m, context, btns);
end;

end.

