program ZipResMaker;

(*
  ZipResMaker.pas - project file
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

  contact: zipmaster AT delphizip DOT net
  updates: http://www.delphizip.net

  modified 2005-11-08
---------------------------------------------------------------------------*)

//{$R 'Res\ZMRes.res' 'Res\ZMRes.rc'}
//{$R 'Res\ZMRes.res'}

uses
  Forms,
  Main in 'Main.pas' {Form1},
  Idents in 'Idents.pas',
  ZMUtils in '..\..\ZMUtils.pas',
  ZipCompLZ77 in 'ZipCompLZ77.pas',
  ZMExtrLZ77 in '..\..\ZMExtrLZ77.pas',
  UWriter in 'UWriter.pas',
  About in 'About.pas' {AboutBox},
  zipmsg in '..\..\zipmsg.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.Title := 'ZipMaster Resource Maker';
  Application.CreateForm(TForm1, Form1);
  Application.CreateForm(TAboutBox, AboutBox);
  Application.Run;
end.
