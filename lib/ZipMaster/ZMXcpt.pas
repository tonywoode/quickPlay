unit ZMXcpt;

(*
  ZMXcpt.pas - Exception class for ZipMaster
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

  modified 2009-11-04
---------------------------------------------------------------------------*)

interface

uses
  SysUtils, ZMMsgStr;

type
  EZipMaster = class(Exception)
  public
    FDisplayMsg: Boolean; // We do not always want to see a message after an exception.
    // We also save the Resource ID in case the resource is not linked in the application.
    FResIdent: Integer;

    constructor Create(const msg: String);
    constructor CreateDisp(const Message: String; const Display: Boolean);

    constructor CreateResFmt(Ident: Integer; const Args: array of const);
    constructor CreateResDisp(Ident: Integer; const Display: Boolean);
    constructor CreateResDisk(Ident: Integer; const DiskNo: Shortint);
    constructor CreateResDrive(Ident: Integer; const Drive: String);
    constructor CreateResFile(Ident: Integer; const File1, File2: String);
    constructor CreateResMsgOS(Ident: Integer; const Msg: string; err: Integer);

    property ResId: Integer Read FResIdent write FResIdent;
  end;
             
function WinErr(err: Integer): string;

implementation

uses
  ZipMsg, Windows;

const
//  RESOURCE_ERROR1: String =
//    #10 + 'ZipMsgXX.res is probably not linked to the executable';
  ERRORMSG: String = 'Failed to Locate string';

constructor EZipMaster.Create(const msg: String);
begin
  inherited Create(msg);
  FDisplayMsg := True;
  FResIdent   := DS_UnknownError;
end;

constructor EZipMaster.CreateDisp(const Message: String; const Display: Boolean);
begin
  inherited Create(Message);
  FDisplayMsg := Display;
end;

constructor EZipMaster.CreateResFmt(Ident: Integer; const Args: array of const);
begin
  inherited Create(ERRORMSG);
  Message := ZipFmtLoadStr(Ident, Args);
//  if Message = '' then  // should not happen
//    Message := Format('id = %d %s', [ident, RESOURCE_ERROR1])
//  else
  Message := Format(Message, Args);
  FDisplayMsg := True;
  FResIdent := Ident;
end; 

constructor EZipMaster.CreateResDisp(Ident: Integer; const Display: Boolean);
begin
  inherited Create(ERRORMSG);
  Message := ZipLoadStr(Ident);
//  if Message = '' then
//    Message := Format('id = %d %s', [ident, RESOURCE_ERROR1]);
  FDisplayMsg := Display;
  FResIdent := Ident;
end;

constructor EZipMaster.CreateResDisk(Ident: Integer; const DiskNo: Shortint);
begin                           
  inherited Create(ERRORMSG);
  Message := ZipLoadStr(Ident);
  Message := Format(Message, [DiskNo]);
  FDisplayMsg := True;
  FResIdent := Ident;
end;

constructor EZipMaster.CreateResDrive(Ident: Integer; const Drive: String);
begin
  inherited Create(ERRORMSG);
  Message := ZipLoadStr(Ident);
  Message := Format(Message, [Drive]);
  FDisplayMsg := True;
  FResIdent := Ident;
end;

constructor EZipMaster.CreateResFile(Ident: Integer; const File1, File2: String);
begin
  inherited Create(ERRORMSG);
  Message := ZipLoadStr(Ident);
//  if Message = '' then
//    Message := Format('id = %d [files = %s, %s]%s', [ident, File1,
//      File2, RESOURCE_ERROR1])
//  else
  Message := Format(Message, [File1, File2]);
  FDisplayMsg := True;
  FResIdent := Ident;
end;

constructor EZipMaster.CreateResMsgOS(Ident: Integer; const Msg: string; err:
    Integer);
//var
//  e: integer;
begin
//  e := err;
//  if err = 0 then
//    e := GetLastError(); // get it before Create clears it
  inherited Create(ERRORMSG);
  Message := ZipLoadStr(Ident) + '%s';
  Message := Format(Message, [Msg, WinErr(err)]);
  FDisplayMsg := True;
  FResIdent := Ident;
end;

function WinErr(err: Integer): string;
begin
//  if err = 0 then
//    err := GetLastError();
  if err > 0 then
    Result := Format(' <%X:%s>', [err, SysErrorMessage(err)])
  else
    Result := '';
end;

end.
