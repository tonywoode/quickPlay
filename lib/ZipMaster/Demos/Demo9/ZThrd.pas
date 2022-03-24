unit ZThrd;

interface

uses
  Classes, {ZipWrkr,} ZipMstr, StdCtrls, SysUtils, Messages, Main9_1;


type
  TZipThread = class(TThread)
  private
	{ Private declarations }
	zip: TZipMaster;
	ftext: string;
	fSpecs: TStrings;
	fName: String;
	fMemo: TMemo;
  err: integer;
  protected
	procedure Execute; override;
	procedure ShowText;
	procedure ZipMessage(Sender: TObject; ErrCode: integer; Message: string);
	procedure CheckTerminate(Sender: TObject; var stop: boolean);
	procedure Finished(Sender: TObject);
  public
	constructor Create(Filename: string; Specs: TStrings; Memo: TMemo; suspended: boolean);
	destructor Destroy; override;      
	procedure AfterConstruction; override;
  end;

implementation

{ Important: Methods and properties of objects in VCL or CLX can only be used
  in a method called using Synchronize, for example,

      Synchronize(UpdateCaption);

  and UpdateCaption could look like,

    procedure TZipThread.UpdateCaption;
    begin
      Form1.Caption := 'Updated in a thread';
    end; }

{ TZipThread }

// runs own thread
procedure TZipThread.Execute;
begin
  zip.Active := true;
	zip.Add;
  err := zip.ErrCode;
end;

// must run main thread ie via Synchronize
procedure TZipThread.ShowText;
begin
	fMemo.Lines.Add(fText);
end;

procedure TZipThread.ZipMessage(Sender: TObject; ErrCode: integer; Message: string);
begin
	if (ErrCode <> 0) and (ErrCode <> 767) then   // ignore skipped
	begin
		fText := '('+IntToStr(ErrCode)+') '+Message;
		Synchronize(ShowText);		// in main thread add string to memo
	end  {
	else 	// showing all messages will slow it down
	begin
		fText := Message;
		Synchronize(ShowText);		// in main thread add string to memo
	end }
	;
end;

destructor TZipThread.Destroy;
begin
	zip.Free;
    inherited Destroy;
end;

// stops calls to ProcessMessages & checks for Terminated
procedure TZipThread.CheckTerminate(Sender: TObject; var stop: boolean);
begin
	if Terminated then
		stop := true;
end;

constructor TZipThread.Create(Filename: string; Specs: TStrings; Memo: TMemo; suspended: boolean);
begin
	inherited Create(suspended);
	fName := Filename;
	fSpecs := Specs;
	fMemo := Memo;
	zip := TZipMaster.Create(nil);	// no owner, so must free
  zip.Active := false;
  zip.NotMainThread := true;
	OnTerminate := Finished;
end;

procedure TZipThread.AfterConstruction;
begin
	zip.OnCheckTerminate := CheckTerminate;
	zip.OnMessage := ZipMessage;
	zip.Unattended := true;  
	zip.ZipFileName := fName;
	zip.FSpecArgs.Assign(fSpecs);
  zip.DLLDirectory := '.\..\dll';
	inherited; 					   
end;

// runs main thread
procedure TZipThread.Finished(Sender: TObject);
begin
	Form1.ZipThread := nil;			// don't allow Cancel
	fMemo.Lines.Add( 'Added '+IntToStr(zip.SuccessCnt)+' files');
	if zip.ErrCode <> 0 then
		fMemo.Lines.Add( 'Error '+IntToStr(zip.ErrCode and $FFFF)+'  '+zip.Message);
//		fMemo.Lines.Add( 'Error '+IntToStr(err)+'  '+zip.Message);
end;


end.

