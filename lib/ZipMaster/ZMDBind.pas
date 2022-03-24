unit ZMDBind;
 
(*
  ZMDBind.pas - Dynamically bind DLL to component
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

  modified 2005-26-12
---------------------------------------------------------------------------*)

interface

uses
  Classes, Windows, ZipMstr, ZMCore, ZMDelZip;

type
  TZMDynamicBind = class(TZMCore)
  private
    AbortFunc: TAbortOperationFunc;
    FDllDirectory: string;
    fKillTemp: Boolean;
    FPath: String;
    fVer: Integer;
    hndl: HWND;
    loadLevel: Integer; 
    PathFunc: TDllPathFunc;
    Priv: Integer;
    PrivFunc: TDllPrivVersionFunc;
    TmpFileName: String;
    UnzExecFunc: TUnzExecFunc;
    VersFunc: TDllVersionFunc;
    ZipExecFunc: TZipExecFunc;
    function GetDll_Build: Integer;
    function GetDll_Load: Boolean;
    function GetPath: String;
    function GetResDllPath: String;
    function GetVersion: string;
    function LoadDll(level: Integer): Integer;
    function LoadLib(FullPath: String; MustExist: Boolean): Integer;
    procedure ReleaseLib;
    procedure RemoveTempDll;
    procedure SetDllDirectory(const Value: string);
    procedure SetDll_Load(const Value: Boolean);
    function UnloadDll(level: Integer): Integer;
  protected
    fDllOperKey: Cardinal;
    procedure CheckExec(RetVal: integer);
    function DoDllLoad: Integer;
    procedure DoDllUnload;
    function DoUnzExec(Rec: pUnZipParms): Integer;
    function DoZipExec(Rec: pZipParms): Integer;
    procedure Empty;
  public
    constructor Create(AMaster: TCustomZipMaster);
    destructor Destroy; override;
    procedure AbortDll;
    procedure Clear; override;
    property DllDirectory: string read FDllDirectory write SetDllDirectory;
    property Dll_Build: Integer read GetDll_Build;
    property Dll_Load: Boolean read GetDll_Load write SetDll_Load;
    property Dll_Path: String read GetPath;
    property Dll_Version: string read GetVersion;
  end;

implementation

uses  forms,
  ZMXcpt, ZipMsg, ZMExtrLZ77, ZMUtils, ZMStructs, SysUtils, ZMMsgStr;
        
const
  zldTemp = 1;
  zldAuto = 2;
  zldFixed = 4;

 {TZMDynamicBind}

constructor TZMDynamicBind.Create(AMaster: TCustomZipMaster);
begin
  inherited;
  fDllOperKey := 0;   
  FDLLDirectory := '';
  fKillTemp := false;
  Empty;
  loadLevel := 0;
  FPath := DelZipDll_Name;
  TmpFileName := '';
end;

destructor TZMDynamicBind.Destroy;
begin
  if hndl <> 0 then
    FreeLibrary(hndl);
  hndl := 0;
  RemoveTempDll;
  inherited;
end;

procedure TZMDynamicBind.AbortDll;
begin
  Cancel := True;
  if hndl <> 0 then           
    AbortFunc(fDllOperKey);
end;

procedure TZMDynamicBind.CheckExec(RetVal: integer); 
var
  x: Integer; 
begin
  if retval < 0 then
  begin 
    case retval of  
      CRITICAL_CANCELLED:  // -1
        x := GE_DLLCancel;
      CRITICAL_ABORT:      // -2
        x := GE_DLLAbort;
      CRITICAL_CALLBACK:   // -3
        x := GE_DLLEvent;
      CRITICAL_MEMORY:     // -4
        x := GE_DLLMem;
      CRITICAL_STRUCT:     // -5
        x := GE_DLLStruct;
    else
      raise EZipMaster.CreateResFmt( GE_DLLCritical, [retval]);
    end;
    raise EZipMaster.CreateResDisp( x, True);
  end;
end;

procedure TZMDynamicBind.Clear;
begin
  ReleaseLib;
  inherited;
end;

function TZMDynamicBind.DoDllLoad: Integer;
begin
  Result := 0;
    LoadDll(zldAuto);
  if hndl <> 0 then
    Result := fVer;
  if fVer < DELZIPVERSION then
  begin
    UnloadDll(zldFixed + zldAuto + zldTemp);
    raise EZipMaster.CreateResDrive( LD_BadDll, FPath);
  end;
end;

procedure TZMDynamicBind.DoDllUnload;
begin
    UnloadDll(zldAuto);
end;

function TZMDynamicBind.DoUnzExec(Rec: pUnZipParms): Integer;
begin
  try
    LoadDll(zldTemp);
    try
      Result := UnzExecFunc(Rec);
    except
      Result := -7;
    end;
  finally
    fDllOperKey := 0;
    UnloadDll(zldTemp);
  end;
  CheckExec(Result);
end;

function TZMDynamicBind.DoZipExec(Rec: pZipParms): Integer;
begin
  try
    LoadDll(zldTemp);
    try
      Result := ZipExecFunc(Rec);
    except
      Result := -7;
    end;
  finally
    fDllOperKey := 0;
    UnloadDll(zldTemp);
  end;
  CheckExec(Result); 
end;

procedure TZMDynamicBind.Empty;
begin
  hndl := 0;
  ZipExecFunc := NIL;
  UnzExecFunc := NIL;
  VersFunc := NIL;
  PrivFunc := NIL;
  AbortFunc := NIL;
  PathFunc := NIL;
  fVer := 0;
  Priv := 0;
end;

function TZMDynamicBind.GetDll_Build: Integer;
begin
  LoadDll(zldTemp);
  Result := Priv;
  UnloadDll(zldTemp);
end;

function TZMDynamicBind.GetDll_Load: Boolean;
begin 
  Result := hndl <> 0;
end;

function TZMDynamicBind.GetPath: String;
begin
  LoadDll(zldTemp);
  Result := FPath;
  UnloadDll(zldTemp);
end;

function TZMDynamicBind.GetResDllPath: String;
var
  fs:  TFileStream;
  rs:  TResourceStream;
  done: Boolean;
  tmp: String;
  ver: Integer;
  w: word;
begin
  done := False;
  fs := NIL;
  rs := Nil;
  tmp := LoadStr(RDLL_Ver);
  ver := StrToIntDef(copy(tmp, 1, 7), 0);
  if ver > 1790000 then
  begin
    TmpFileName := MakeTempFileName('DZ_', '.dll');
    try
      rs := TResourceStream.CreateFromID(HInstance, RDLL_Dll, RT_RCDATA);
      if assigned(rs) and (rs.Size > 50000) then
      begin
        rs.ReadBuffer(w, sizeof(word));
        rs.Position := 0;
        fs := TFileStream.Create(TmpFileName, fmCreate);
        if w = IMAGE_DOS_SIGNATURE then
          done := fs.CopyFrom(rs, rs.Size) = rs.size
        else
          done := LZ77Extract(fs, rs, rs.Size) = 0;  
        if ({Verbose or} Trace) and done then
        begin
          tmp := Format('extracted resource dll %s %d',[TmpFileName, ver]);
          Report(zacMessage, 0, tmp, 0);
        end;
      end;
    finally
      FreeAndNil(fs);
      FreeAndNil(rs);
      if (not done) and FileExists(TmpFileName) then
        DeleteFile(TmpFileName);
      if not FileExists(TmpFileName) then
        TmpFileName := '';
    end;
  end
  else
    if Trace then
      Report(zacMessage, 0, 'No dll in resource', 0);
  Result := TmpFileName;
end;

function TZMDynamicBind.GetVersion: string;
var
  v: integer;
  fc: string;
begin
  fc := ' %d.%2.2d.%2.2d.%2.2d ';
  v := Priv;
  if fVer = 0 then  
  begin
    LoadDll(zldTemp);
    fc := '[%d.%2.2d.%2.2d.%2.2d]';
    v := Priv;
    UnloadDll(zldTemp);
  end;
  Result := Format(fc,[v div 1000000, (v div 10000) mod 100,
                     (v div 100) mod 100, v mod 100 ]);
end;

function TZMDynamicBind.LoadDll(level: Integer): Integer;
var
  FullPath: String;
  RVer: Integer;
  RVrs: String;
begin
  loadLevel := (loadLevel or level) and 7;
  if hndl = 0 then
  begin
    try
      StartWaitCursor;
      fVer := 0;
      fullpath := ''; 
      if TmpFileName <> '' then
        fullpath := TmpFileName
      else
        if DllDirectory = '><' then
          fullpath := GetResDllPath;
      if fullpath = '' then
        if DllDirectory <> '' then
        begin
          fullpath := PathConcat(DllDirectory, DelZipDll_Name);
          if DllDirectory[1] = '.' then
            fullpath := PathConcat(ExtractFilePath(ParamStr(0)), fullpath);
          if not FileExists(fullpath) then
            fullpath := '';
        end;
      if fullpath = '' then
        fullpath := DelZipDll_Name; // Let Windows search the std dirs
      RVrs := LoadStr(RDLL_Ver);
      RVer := StrToIntDef(copy(RVrs, 1, 7), 0);
      if RVer > LoadLib(fullPath, RVer < 1790000) then
        if LoadLib(GetResDllPath, False) < 1790000 then
          LoadLib(fullPath, True);
      if Verbose then
        Report(zacMessage, 0, ZipFmtLoadStr(LD_DllLoaded,[FPath]), 0);
    finally
      StopWaitCursor;
    end;
  end;
  Result := fVer;
end;

function TZMDynamicBind.LoadLib(FullPath: String; MustExist: Boolean): Integer;
var
  oldMode: Cardinal;
  tmp: string;
  err: integer;
begin
  if hndl > 0 then
    FreeLibrary(hndl);
  Empty;
  oldMode := SetErrorMode(SEM_FAILCRITICALERRORS or SEM_NOGPFAULTERRORBOX);
  try
    hndl := LoadLibrary(PChar(Fullpath));
    if hndl > HInstance_Error then
    begin
      @UnzExecFunc := GetProcAddress(hndl, DelZipDll_Unzfunc);
      if (@UnzExecFunc <> NIL) then
        @ZipExecFunc := GetProcAddress(hndl, DelZipDll_Zipfunc);
      if (@ZipExecFunc <> NIL) then
        @VersFunc := GetProcAddress(hndl, DelZipDll_Versfunc);
      if (@VersFunc <> NIL) then
        @PrivFunc := GetProcAddress(hndl, DelZipDll_Privfunc);
      if (@PrivFunc <> NIL) then
        @AbortFunc := GetProcAddress(hndl, DelZipDll_Abortfunc);
      if (@AbortFunc <> NIL) then
        @PathFunc := GetProcAddress(hndl, DelZipDll_Pathfunc); 
    end//;
    else
    if Verbose or Trace then
    begin
      err := GetLastError;
      tmp := Format('Error [%d %s] loading %s',[err, SysErrorMessage(err), FullPath]);
      Report(zacMessage, 0, tmp, 0);
//      Application.MessageBox(PChar(tmp), 'ZipMaster 179', MB_OK + MB_ICONSTOP);
    end;
  finally
    SetErrorMode(oldMode);
  end;
  if hndl <= HInstance_Error then
  begin
    Empty;
    if MustExist then
    begin          
      LoadLevel := 0;
      raise EZipMaster.CreateResDrive( LD_NoDll, fullpath);
    end;
    Result := 0;
    exit;
  end;
  if (@PathFunc <> NIL) then
  begin         
    Priv := PrivFunc;
    fVer := VersFunc;
    FPath := String(PathFunc);
  end;
  if (fVer < DELZIPVERSION) or (fVer > 300) then
  begin
    fullpath := FPath;
    FreeLibrary(hndl);
    Empty;
    if MustExist then
    begin
      LoadLevel := 0;
      raise EZipMaster.CreateResDrive( LD_BadDll, fullpath);
    end;
  end;
  Result := Priv;
end;

procedure TZMDynamicBind.ReleaseLib;
begin
  if hndl <> 0  then
  begin
    if Verbose then
      Report(zacMessage, 0, ZipFmtLoadStr(LD_DllUnloaded,[FPath]), 0);
    FreeLibrary(hndl);
    hndl := 0;
  end;
  if hndl = 0 then
  begin
    Empty;
    FPath := '';
    LoadLevel := 0;
    if fKillTemp then
      RemoveTempDll;     
//    TmpFileName := '';
  end;
end;

procedure TZMDynamicBind.RemoveTempDll;
var
  t: string;
begin
  t := TmpFileName;
  TmpFileName := '';   
  fKillTemp := false;
  if (t <> '') and FileExists(t) then
    SysUtils.DeleteFile(t);
end;

procedure TZMDynamicBind.SetDllDirectory(const Value: string); 
var
  ValLen: Integer;
begin
  if Value <> FDLLDirectory then
  begin                   
    FDLLDirectory := Value;
    ValLen := Length(FDLLDirectory);
    // if there is a trailing \ in dirname, cut it off:
    if (ValLen > 0) and (FDLLDirectory[ValLen] = '\') then
        SetLength(FDLLDirectory, ValLen - 1);       // shorten the dirname by one
    if (hndl <> 0) and (TmpFileName <> '') then
      fKillTemp := true
    else
      RemoveTempDll;
  end; 
end;

procedure TZMDynamicBind.SetDll_Load(const Value: Boolean);
begin
  if Value <> Dll_Load then
  begin
    if Value then
      LoadDll(zldFixed)
    else
      UnloadDll(zldFixed);
  end;
end;

function TZMDynamicBind.UnloadDll(level: Integer): Integer;
begin
  loadLevel := (loadLevel and (not level)) and 7;
  if loadLevel = 0 then
    ReleaseLib;
  Result := fVer;
end;

end.

