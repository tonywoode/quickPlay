unit ZMSBind;

(*
  ZMSBind.pas - Statically bind DLL to component
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

  modified 2005-12-24
---------------------------------------------------------------------------*)

{$INCLUDE ZipConfig.inc} 
{$INCLUDE '.\ZipVers.inc'}

interface
       
{$IFDEF STATIC_LOAD_DELZIP_DLL}
uses
  Classes, ZipMstr, ZMCore, ZMDelZip;

type
  TZMStaticBind = class(TZMCore)
  private
    function GetDllDirectory: string;       
    function GetDll_Build: Integer;
    function GetDll_Load: Boolean;
    function GetDllPath: string;
    procedure SetDllDirectory(const Value: string);
    procedure SetDll_Load(const Value: Boolean);
  protected
    fDllOperKey: Cardinal;
    procedure CheckExec(RetVal: integer);
    function DoDllLoad: Integer;
    procedure DoDllUnload;
    function GetDLLVersion: string;
    function DoUnzExec(Rec: pUnZipParms): Integer;
    function DoZipExec(Rec: pZipParms): Integer;
  public
    constructor Create(AMaster: TCustomZipMaster);
    procedure AbortDll;
    property DllDirectory: string read GetDllDirectory write SetDllDirectory;
    property Dll_Build: Integer read GetDll_Build;
    property Dll_Load: Boolean read GetDll_Load write SetDll_Load;
    property Dll_Path: String read GetDLLPath;
    property Dll_Version: string read GetDLLVersion;
  end;
          
{$ENDIF}
implementation
                 
{$IFDEF STATIC_LOAD_DELZIP_DLL}
uses
  Windows, SysUtils, ZipMsg, ZMXcpt;

// 'static' loaded dll functions
function DZ_UnzExec(C: pUnZipParms): Integer; STDCALL; EXTERNAL DelZipDll_Name;
function DZ_ZipExec(C: pZipParms): Integer; STDCALL; EXTERNAL DelZipDll_Name;
function DZ_Abort(C: Cardinal): Integer; STDCALL; EXTERNAL DelZipDll_Name;
function DZ_Version: Integer; STDCALL; EXTERNAL DelZipDll_Name;
function DZ_PrivVersion: Integer; STDCALL; EXTERNAL DelZipDll_Name;
function DZ_Path: PAnsiChar; STDCALL; EXTERNAL DelZipDll_Name;
                           
 {TZMStaticBind}
constructor TZMStaticBind.Create(AMaster: TCustomZipMaster);
begin
  fDllOperKey := 0;
  inherited;
end;

procedure TZMStaticBind.AbortDll;
begin
  Cancel := True;
  if fDllOperKey <> 0  then
    DZ_Abort(fDllOperKey);
end;

function TZMStaticBind.GetDll_Build: Integer;
begin
  Result := DZ_PrivVersion;
end;
     
function TZMStaticBind.GetDll_Load: Boolean;
begin
    Result := True;
end;

function TZMStaticBind.DoDllLoad: Integer;
begin
    Result := DZ_PrivVersion;
end;

function TZMStaticBind.GetDllPath: string;
begin
  Result := DZ_Path;
end;

procedure TZMStaticBind.DoDllUnload;
begin
  // do nothing
end;

function TZMStaticBind.GetDLLVersion: string;
var
  b: integer;
begin
  b := DZ_PrivVersion;
  Result := Format('<%d.%2.2d.%2.2d.%2.2d>',[b div 1000000,
     (b div 10000) mod 100, (b div 100) mod 100, b mod 100 ]);
end;

function TZMStaticBind.DoUnzExec(Rec: pUnZipParms): Integer;
begin
  try
    Result := DZ_UnzExec(Rec);
  except
    Result := -7;
    fDllOperKey := 0;
  end;
  CheckExec(Result);
end;

function TZMStaticBind.DoZipExec(Rec: pZipParms): Integer;
begin
  try
    Result := DZ_ZipExec(Rec);
  except
    Result := -7;
    fDllOperKey := 0;
  end;
  CheckExec(Result);
end;

procedure TZMStaticBind.CheckExec(RetVal: integer); 
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
      raise EZipMaster.CreateResFmt(GE_DLLCritical, [retval]);
    end;
    raise EZipMaster.CreateResDisp(x, True);
  end;
end;

function TZMStaticBind.GetDllDirectory: string;
begin
  Result := '';
end;

procedure TZMStaticBind.SetDllDirectory(const Value: string);
begin
  // do nothing
end;

procedure TZMStaticBind.SetDll_Load(const Value: Boolean);
begin
  // do nothing
end;

   
{$ENDIF}
end.

