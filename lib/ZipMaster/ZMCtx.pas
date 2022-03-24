unit ZMCtx;

(*
  ZMCtx.pas - DialogBox help context values
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

const
  DHCBase = 10000;
  DHC_ZipMessage = DHCBase;
  DHC_ExMessage = DHCBase + 1;
  DHC_Password = DHCBase + 2; // just GetPassword default password
  DHC_ExtrPwrd = DHCBase + 3;
  DHC_AddPwrd1 = DHCBase + 4;
  DHC_AddPwrd2 = DHCBase + 5;
  DHC_WrtSpnDel = DHCBase + 6;
  DHC_ExSFX2EXE = DHCBase + 7;
  DHC_ExSFX2Zip = DHCBase + 8;
  DHC_SpanNxtW = DHCBase + 9;
  DHC_SpanNxtR = DHCBase + 10;  
  DHC_SpanOvr = DHCBase + 11;
  DHC_SpanNoOut = DHCBase + 12;
  DHC_SpanSpace = DHCBase + 13;
  DHC_CpyZipOvr = DHCBase + 14;
  DHC_FormErase = DHCBase + 15;
  DHC_ExSFXNew = DHCBase + 16;
  
implementation

end.
