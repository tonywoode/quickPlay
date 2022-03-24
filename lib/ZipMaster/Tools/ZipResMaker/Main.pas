unit Main;

(*
  Main.pas - main form
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

  modified 2007-06-23
---------------------------------------------------------------------------*)

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, CheckLst, ComCtrls, Menus, ExtCtrls;

type
  ZPaths = (zphRoot, zphDest, zphDll, zphLang, zphVCL, zphUPX);

type
  ZRCParts = (zrpDLLs, zrpLangs);
  ZParts = set of ZRCParts;
         {
type
  TLangs = record
    s: String;
    p: Integer;
  end;  }

type
  TForm1 = class (TForm)
    A1: TMenuItem;
    btnAllLang: TButton;
    btnBrowsDest: TButton;
    btnBrowseDll: TButton;
    btnBrowseLang: TButton;
    btnBrowseRoot: TButton;
    btnBrowseUPX: TButton;
    btnBrowseVCL: TButton;
    btnBuildRes: TButton;
    btnMakeUnits: TButton;
    btnNoneLang: TButton;
    btnRefreshLang: TButton;
    Build1: TMenuItem;
    cbDlls: TCheckBox;
    cbUseUPX: TCheckBox;
    DefTags: TMenuItem;
    edDest: TEdit;
    edDll: TEdit;
    edDllVer: TEdit;
    edLang: TEdit;
    edRoot: TEdit;
    edUPX: TEdit;
    edVCL: TEdit;
    Exit1: TMenuItem;
    File1: TMenuItem;
    Help1: TMenuItem;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    lbLangs: TCheckListBox;
    MainMenu1: TMainMenu;
    Memo1: TMemo;
    N1: TMenuItem;
    Pages: TPageControl;
    Panel1: TPanel;
    Panel2: TPanel;
    pnlDllUPX: TPanel;
    Resources1: TMenuItem;
    Script1: TMenuItem;
    StaticText1: TStaticText;
    StaticText10: TStaticText;
    StaticText11: TStaticText;
    StaticText2: TStaticText;
    StaticText3: TStaticText;
    StaticText4: TStaticText;
    StaticText5: TStaticText;
    StaticText6: TStaticText;
    StaticText7: TStaticText;
    StaticText8: TStaticText;
    StaticText9: TStaticText;
    TabSheet1: TTabSheet;
    TabSheet2: TTabSheet;
    TabSheet4: TTabSheet;
    TabSheet5: TTabSheet;
    TabSheet6: TTabSheet;
    procedure A1Click(Sender: TObject);
    procedure btnAllLangClick(Sender: TObject);
    procedure btnBrowsDestClick(Sender: TObject);
    procedure btnBrowseDllClick(Sender: TObject);
    procedure btnBrowseLangClick(Sender: TObject);
    procedure btnBrowseRootClick(Sender: TObject);
    procedure btnBrowseUPXClick(Sender: TObject);
    procedure btnBrowseVCLClick(Sender: TObject);
    procedure btnBuildResClick(Sender: TObject);
    procedure btnMakeUnitsClick(Sender: TObject);
    procedure btnNoneLangClick(Sender: TObject);
    procedure btnRefreshLangClick(Sender: TObject);
    procedure cbCompressClick(Sender: TObject);
    procedure DefTagsClick(Sender: TObject);
    procedure edDestChange(Sender: TObject);
    procedure edDllChange(Sender: TObject);
    procedure edLangChange(Sender: TObject);
    procedure edRootChange(Sender: TObject);
    procedure edUPXChange(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormCreate(Sender: TObject);
    procedure PagesChange(Sender: TObject);
  private
    fBusy: Boolean; 
    procedure BrowseClick(p: ZPaths; const title: String);
    function GetBuild(const pth: String): Integer;
    { Private declarations }
    function GetZipBuild: Integer;
    function HasFile(Sender: TObject; const f: String): Boolean;
    procedure SetBusy(const Value: Boolean);
  protected
    function BrowsePath(const ForWhat: String; const def: String): String;
    function CompileStrings(src: TStrings; dest: TStream): Integer;
    function CompStreams(strm1, strm2: TStream): Integer;
    function IsUPXFile(const fn: String): Boolean;
    function MakeDllBin: Boolean;
    function CheckLang(const lbl: string): Boolean;
    function MakeLanguageBin: Boolean;
    function PathEdit(p: ZPaths): TEdit;
    function RunProcess(const ExecCmd: String): Cardinal;
    procedure SetChecks(lb: TCheckListBox; state: Boolean);
    procedure SetPaths;
    procedure UpdateList({lids: array of TLangs;} const fs: String);
    function WriteRC(const fn: String; what: ZParts): Boolean;
  public
    function FullPath(p: ZPaths; const fn: String): String; 
    function RunBRCC(const rc, res, opts: String): Boolean;
    procedure Show(const s: String);
    { Public declarations }
    function WantDlls: Boolean;
    function WantLangs: Boolean;
    property Busy: Boolean read fBusy write SetBusy; 
    property DllBuild: Integer read GetZipBuild;
  end;

var
  Form1: TForm1;
                        
function LIdOfRes(const fn: String): Word;

implementation

{$R *.dfm}
//{$R '..\..\Res\zmres.res' '..\..\Res\zmres.rc'}

{$INCLUDE '..\..\ZipVers.inc'}
//{$IFNDEF VERD4+}
//  No longer supported - does not support Int64 (plus others)
//{$ENDIF}
{$IFDEF VERD6up}
{$WARN UNIT_PLATFORM OFF}
{$WARN SYMBOL_PLATFORM OFF}
{$ENDIF}

uses ZipMstr, ZipMsg, ShellApi, ZipCompLZ77, ZMUtils, FileCtrl, Registry,
  Idents, IniFiles, UWriter, ZMDelZip, ZMExtrLZ77, ABOUT;

{ TForm1 }
     
type
  TResBlock = array of Word;

const
//  defPaths: array [zphRoot..zphVCL] of String = (
//    '', 'RES', 'DLL', 'Lang', '', 'Source');
//  PathNames: array [zphRoot..zphVCL] of String = (
//    'Root', 'Dest', 'Dll', 'Lang', 'UPX', 'Source');
  defPaths: array [zphRoot..zphUPX] of String = (
    '', 'RES', 'DLL', 'Lang', ''{'Source'}, '');
  PathNames: array [zphRoot..zphUPX] of String = (
    'Root', 'Dest', 'Dll', 'Lang', 'Source', 'UPX');
  DllBinName = 'DZ_Dll.bin';

type
  TLangs = record
    s: String;
    p: Integer;
  end;

const
  std = 1252;
  Langs: array [0..26] of TLangs = (
    (s: 'BR: Brazilian'; p: std),
    (s: 'CT: Catalan'; p: std),
    (s: 'DK: Danish'; p: std),
    (s: 'NL: Dutch'; p: std), //0413
    (s: 'FI: Finnish'; p: std),
    (s: 'FR: French'; p: std),
    (s: 'DE: German'; p: std),
    (s: 'HU: Hungarian'; p: 1250),
    (s: 'NO: Norwegian'; p: std),
    (s: 'PO: Polish'; p: 1250),
    (s: 'SW: Swedish'; p: std),
    (s: 'S1: Spanish'; p: std),
    (s: 'ES: Spanish'; p: std),
    (s: 'US: default US'; p: std),
    (s: 'SI: Slovenian'; p: 1250),
    (s: 'SL: Slovenian'; p: 1250),//0424
    (s: 'CN: Chinese'; p: 936),
    (s: 'CZ: Czech'; p: 1250),
    (s: 'GR: Greek'; p: 1253),
    (s: 'IT: Italian'; p: std),
    (s: 'JP: Japanese'; p: 932),
    (s: 'MY: Malaysian'; p: 874),
    (s: 'RO: Romanian'; p: std),
    (s: 'RU: Russian'; p: 1251),
    (s: 'YU: Serbian'; p: 1250),
    (s: 'TW: Taiwanese'; p: 950),
    (s: 'KO: Korean'; p: 949)
    );

  SFXs: array [0..11] of TLangs = (
    (s: 'BR: Brazilian Portuguese'; p: std),
    (s: 'CAT: Catalan'; p: std),
    (s: 'DK: Danish'; p: std),
    (s: 'NL: Dutch'; p: std),
    (s: 'FR: French'; p: std),
    (s: 'DE: German'; p: std),
    (s: 'HU: Hungarian'; p: 1250),
    (s: 'IT: Italian'; p: std),
    (s: 'KO: Korean'; p: 949),
    (s: 'PL: Polish'; p: 1250),
    (s: 'ES: Spanish'; p: std),
    (s: 'US: US English'; p: std));

//type
//  TZipTagLanguages = (ztlDefault, ztlDutch, ztlSlovenian);
//
//const
//  TagLangNames: array [ztlDefault .. ztlSlovenian] of Pchar =
//    ('', 'NL', 'SI');

function Find_Lang(tbl: array of TLangs; const sid: String): Integer;
var
  u, s: String;
  p:    Integer;
begin
  if sid <> '' then
  begin
    u := Uppercase(sid);
    for Result := 0 to high(tbl) do
    begin
      s := tbl[Result].s;
      p := AnsiPos(':', s);
      if p > 1 then
        s := copy(s, 1, p - 1);
      if s = u then
        exit;
    end;
  end;
  Result := -1;
end;
         
function FindRes(const blk: TResBlock; id: Integer): String;
var
  fid, rid: Integer;
  DatSiz, HedSiz: Cardinal;
  sz:  Cardinal;
  l:   Cardinal;
  bp, hp: Integer;
  ws:  Widestring;
begin
  Result := '';
  fid := id div 16;
  try
    bp := 0;
    while (bp + 9) < HIGH(Blk)  do
    begin
      bp := (bp + 1) and $7fffE;  // dword align
      DatSiz := (blk[bp+1] shl 16) + blk[bp];
      HedSiz := (blk[bp+3] shl 16) + blk[bp+2];
//      DatSiz := pCardinal(@blk[bp])^;
//      HedSiz := pCardinal(@blk[bp + 2])^;
      if (HedSiz + DatSiz) < 8 then
        break;
//      Assert((HedSiz + DatSiz) >= 8, 'header error');
      sz := (HedSiz + DatSiz) - 8;
      hp := bp + 4;
      inc(bp, 4 + (sz div 2));
      if blk[hp] <> $ffff then
        continue;  // bad res type
      if blk[hp + 1] <> 6 then
        continue;      // not string table
      if blk[hp + 2] <> $ffff then
        continue;
      rid := pred(blk[hp + 3]);
      if fid <> rid then
        continue;
      rid := rid * 16;
      inc(hp, (HedSiz - 8) div 2);
      ws := '';
      while rid < id do
      begin
        l := blk[hp];
        inc(hp, l + 1);
        inc(rid);
      end;
      l := blk[hp];
      if l <> 0 then
      begin
        SetLength(ws, l);
        move(blk[hp + 1], ws[1], l * sizeof(Widechar));
        Result := ws;
        Result := StringReplace(Result, #10, #13#10, [rfReplaceAll]);
        break;
      end;
      break;
    end;
  except
    Result := '';
  end;
end;

function LangOfRes(const fname: String): String;
var
  fs: TFileStream;
  blk: TResBlock;
  szw: Integer;
begin
  blk := nil;
  fs := nil;
  if not FileExists(fname) then
    exit;
  try
    fs := TFileStream.Create(fname, fmOpenRead);    
    if (assigned(fs)) and (fs.Size < 50000) then
    begin
      szw := (Integer(fs.Size) + (sizeof(Word) - 1)) div sizeof(Word);
      SetLength(blk, szw + 1);
      fs.Position := 0;
      if fs.Read(blk[0], fs.Size) = fs.Size then
      begin
        blk[szw] := Word(-1);
        Result := findRes(blk, DT_Language);
      end
      else
        blk := nil;
    end;
  finally
    FreeAndNil(fs);
    blk := nil;
  end;
end;

procedure TForm1.A1Click(Sender: TObject);
begin
  AboutBox.ShowModal;
end;

procedure TForm1.BrowseClick(p: ZPaths; const title: String);
var
  ed: TEdit;
begin
  ed := PathEdit(p);
  ed.Text := BrowsePath(title, PathConcat(edRoot.Text, defPaths[p]));
  ed.SetFocus;
end;

function TForm1.BrowsePath(const ForWhat, def: String): String;
begin
  if not SelectDirectory(ForWhat, '', Result) then
    Result := '';
  if Result = '' then
    Result := def
  else
    Result := DelimitPath(Result, True);
end;

procedure TForm1.btnAllLangClick(Sender: TObject);
begin
  SetChecks(lbLangs, True);
end;

procedure TForm1.btnBrowsDestClick(Sender: TObject);
begin
  edDest.Text := BrowsePath('Destination',    PathConcat(edRoot.Text,
    defPaths[zphDest]));
  edDest.SetFocus;
end;

procedure TForm1.btnBrowseDllClick(Sender: TObject);
begin
  BrowseClick(zphDll, 'Dll');
end;

procedure TForm1.btnBrowseLangClick(Sender: TObject);
begin
  BrowseClick(zphLang, 'Languages');
end;

procedure TForm1.btnBrowseRootClick(Sender: TObject);
begin
  edRoot.Text := BrowsePath('Root',
    ExpandFileName(PathConcat(ExtractFilePath(Application.ExeName),
    defPaths[zphRoot])));
  edRoot.SetFocus;
  SetPaths;
end;

procedure TForm1.btnBrowseUPXClick(Sender: TObject);
begin
  edUPX.Text := BrowsePath('UPX', '');
  edUPX.SetFocus;
end;

procedure TForm1.btnBrowseVCLClick(Sender: TObject);
begin
  BrowseClick(zphVCL, 'Source');
end;

procedure TForm1.btnBuildResClick(Sender: TObject);
var
  pts: ZParts;
  error: Boolean; 
begin
  if not Busy then
    try
      Busy := True;
      // do something
      error := False;
      pts := [];
      if WantLangs then
        if MakeLanguageBin then
          pts := [zrpLangs]
        else
        begin
          Show('failed to make langs.bin');
          error := True;
        end;
      if WantDlls then
        if MakeDllBin then
          pts := pts + [zrpDlls]
        else
        begin
          Show('failed to make delzip.bin');
          error := True;
        end;
      if (not error) and WriteRC('ZMRes', pts) then
      begin
        RunBRCC(FullPath(zphDest, 'ZMRes.rc'),
          FullPath(zphDest, 'ZMRes.res'), '');
        Show('done');
      end;
    finally
      Busy := False;
    end;
end;

procedure TForm1.btnMakeUnitsClick(Sender: TObject);
var
  w: TUnitWriter;
  i: Integer;
  f: String;
begin
  w := Nil;
  try
    Show('Reading default strings and identifiers');
    w := TUnitWriter.Create;
    i := w.Prepare;
    if i = 0 then
    begin
      f := FullPath(zphVCL, 'ZipMsg.pas');
      Show('writing ' + f);
      i := w.WriteZipMsg(f);
      if i <> 0 then
        Show('failed ' + intToStr(i))
      else
      begin
        f := FullPath(zphVCL, 'ZMDefMsgs.pas');
        Show('writing ' + f);
        i := w.WriteDefMsgs(f);
        if i <> 0 then
          Show('failed ' + intToStr(i))
        else
          Show('ok');
      end;
    end
    else
      Show('failed ' + intToStr(i))
  finally
    FreeAndNil(w);
  end;
end;

procedure TForm1.btnNoneLangClick(Sender: TObject);
begin
  SetChecks(lbLangs, False);
end;

procedure TForm1.btnRefreshLangClick(Sender: TObject);
begin
  UpdateList({Langs,} FullPath(zphLang, 'ZipMsg*.res'));
end;

procedure TForm1.cbCompressClick(Sender: TObject);
begin

end;

// each resource entry is of format
// lang_id: word
// comp_size: word
// name_size: word
// name[name_size]: byte
// data[comp_size]: byte  (res file)
function TForm1.CompileStrings(src: TStrings; dest: TStream): Integer;
var
  idx, p, i: Integer;
  lbl, fn, s: String;
  cb:  TMemoryStream;
  c:   Char;
  lrf: Word;
  lids: array of Word;  // avoid duplicates
begin
  Result := -1;
  if (not assigned(src)) or (src.Count < 1) or (not assigned(dest)) then
    exit;
  Inc(Result);
  SetLength(lids,64);
  for idx := 0 to pred(src.Count) do
  begin
    s := Trim(src[idx]);
    if s = '' then
      continue;
    lbl := '';
    for p := 1 to length(s) do
    begin
      c := s[p];
      if not (AnsiChar(c) in ['A'..'Z', 'a'..'z', '_', '0'..'9']) then
        break;
      lbl := lbl + c;
    end;
    lbl := Uppercase(lbl);
    if (lbl = '') or (lbl = 'US') then
      continue;  // don't add US
    lbl := Uppercase(lbl);
    fn := FullPath(zphLang, 'ZipMsg' + lbl + '.res');
    if {(not FileExists(fn)) and} not CheckLang(lbl) then
      continue;
    lrf := LIdOfRes(fn);
    if (lrf = $FFFF) or (lrf = 0) then
      continue;
    i := pred(Result);
    while i >= 0 do
      if lrf <> lids[i] then
        dec(i)
      else
        break;
    if  (i >= 0) or (lrf = $0409) then
    begin
      Show(Format('Cannot add %s language %x already included',[fn, lrf]));
      continue;
    end;
    cb := Nil;
    Show('Compressing ' + s + '   ' + fn);
    try
      try
        cb := TMemoryStream.Create;
        if CompressRes(cb, fn, lbl) > 6 then
        begin
          cb.Position := 0;
          dest.CopyFrom(cb, cb.Size);               // data
          if HIGH(lids) <= (Result + 1) then
            SetLength(lids, Result + 16);
          lids[Result] := lrf;
          inc(Result);
        end
        else
          Show('Compression error');
      except
        on e: Exception do
        begin
          Show('String compiler exception: ' + e.Message);
          raise;
        end;
      end;
    finally
      FreeAndNil(cb); 
    end;
  end;
end;

function TForm1.CompStreams(strm1, strm2: TStream): Integer;
const
  BiteSize = 256;
var
  bytesDone, size1, size2: Cardinal;
  buf1, buf2: array[0..BiteSize - 1] of AnsiChar;
  bytes, i: Cardinal;
begin
  Result := -1;
  bytesDone := 0;
  size1 := Cardinal(strm1.Size);
  size2 := Cardinal(strm2.Size);
  if Size1 <> size2 then
    exit;
  Strm1.Position := 0;
  Strm2.Position := 0;
  Result := 0;
  while bytesDone < size1 do
  begin
    bytes := strm1.Read(buf1[0], BiteSize);
    if bytes < 1 then
    begin
      Result := -2;
      break;
    end;
    strm2.ReadBuffer(buf2[0], bytes);
    for i := 0 to pred(bytes) do
      if buf1[i] <> buf2[i] then
      begin
        inc(Result);
        Show(Format('%6d %6X %2x %2x', [Result, Cardinal(
          (BytesDone + i) and $FFFF), Integer(buf1[i]), Integer(buf2[i])]));
      end;
    inc(BytesDone, bytes);
  end;
end;

procedure TForm1.DefTagsClick(Sender: TObject);
begin
  TabSheet6.TabVisible := True;
  Pages.ActivePageIndex := 3;//4;
end;

procedure TForm1.edDestChange(Sender: TObject);
begin
  if DirExists(edDest.Text) then
    edDest.Font.Style := []
  else
    edDest.Font.Style := [fsItalic];

end;

procedure TForm1.edDllChange(Sender: TObject);
var
  DVer: Integer;

  function VerStr(v: Integer): String;
  var
    old: String;
  begin
    if v < 1790000 then
      old := 'Too old!'
    else
      old := 'ok';
    result := Format('%d.%d.%2.2d.%2.2d %s',      [v div 1000000,
      (v mod 1000000) div 10000, (v mod 10000) div      100, v mod 100, old]);
  end;

begin
  if not FileExists(FullPath(zphDLL, DelZipDll_Name)) then
  begin
    DVer := 0;
    edDllVer.Text := 'none';
    edDll.Font.Style := [fsItalic];
  end
  else
  begin
    DVer := DllBuild;
    edDllVer.Text := VerStr(DVer);
    edDll.Font.Style := [];
  end;
  cbDlls.Checked := (DVer >= 1790000);
  cbDlls.Enabled := (DVer >= 1790000);
  Label7.Caption := DelZipDll_Name + ' version';
end;

procedure TForm1.edLangChange(Sender: TObject);
begin
  HasFile(Sender, 'zipmsgUS.res');
  btnRefreshLangClick(Sender);
end;

procedure TForm1.edRootChange(Sender: TObject);
begin
  if DirExists(edRoot.Text) then
    SetPaths;
end;

procedure TForm1.edUPXChange(Sender: TObject);
begin
  pnlDllUPX.Visible := HasFile(edUPX, 'upx.exe');
  if not pnlDllUPX.Visible then
    cbUseUPX.Checked := false;
end;

procedure TForm1.FormClose(Sender: TObject; var Action: TCloseAction);
var
  Ini: TIniFile;
  zp:  ZPaths;
  i: Integer;
  n: String;
begin     
	if GetAsyncKeyState(VK_CONTROL) < 0 then
    exit;
  Ini := TIniFile.Create(ChangeFileExt(Application.ExeName, '.INI'));
  try
    for zp := zphRoot to zphUPX do
      ini.WriteString('Paths', PathNames[zp], PathEdit(zp).Text);
    ini.WriteBool('Dlls', 'Include', cbDlls.Checked);
    ini.WriteBool('Dlls', 'UPX', cbUseUPX.Checked);
    ini.EraseSection('Languages');
    ini.WriteInteger('Languages', 'KnownCount', lbLangs.Count);
    for i := 0 to pred(lbLangs.Count) do
    begin
      if lbLangs.Checked[i] then
        n := '+'
      else
        n := '-';
      n := n + lbLangs.Items[i];
      ini.WriteString('Languages', 'Item' + IntToStr(i), n);
    end; 
  finally
    Ini.Free;
  end;
end;

procedure TForm1.FormCreate(Sender: TObject);
  function GetRegistryValue(KeyName, Name: String): String;
  var
    Registry: TRegistry;
  begin
    Registry := TRegistry.Create(KEY_READ);
    try
      Registry.RootKey := HKEY_CURRENT_USER;
  // False because we do not want to create it if it doesn't exist
      Registry.OpenKey(KeyName, False);
      Result := Registry.ReadString(Name);
    finally
      Registry.Free;
    end;
  end;

var
  fini, s, rs, t: String;
  zp:  ZPaths;
  ini: TIniFile;
  i, k, x: Integer;
  ks: short;
begin 
  Pages.ActivePageIndex := 0;
  TabSheet6.TabVisible := False;
  pnlDllUPX.Visible := False;
  s := ExpandFileName(ExtractFilePath(Application.ExeName) + '..\..\');
  fini := ChangeFileExt(Application.ExeName, '.ini');
	ks := GetAsyncKeyState(VK_CONTROL);
  if FileExists(fini) and (ks >= 0) then
  begin
    ini := TIniFile.Create(fini);
    try
      // must set before setting paths
      lbLangs.Clear;
      k := ini.ReadInteger('Languages', 'KnownCount', 0);
      for i := 0 to pred(k) do
      begin
        t := ini.ReadString('Languages', 'Item' + IntToStr(i), '');
        if length(t) < 2 then
          continue;
        x := lbLangs.Items.Add(copy(t, 2, length(t) - 1));
        lbLangs.Checked[x] := t[1] = '+';
        lbLangs.ItemEnabled[x] := False;
      end;
      cbDlls.Checked := ini.ReadBool('DLLs', 'Include', True);
      cbUseUPX.Checked := ini.ReadBool('DLLs', 'UPX', False);
      // will cause Languages to update
      for zp := zphRoot to zphUPX do
        PathEdit(zp).Text :=
          ini.ReadString('Paths', PathNames[zp],
          DelimitPath(PathConcat(s, defPaths[zp]), True));
      pnlDllUPX.Visible := HasFile(edUPX, 'upx.exe');
    finally
      ini.Free;
    end;
  end
  else
  begin       
    if  ks >= 0  then
    rs := GetRegistryValue('Software\DelphiZip\ZipMaster', 'InstallPath');
    if rs <> '' then
      edRoot.Text := rs
    else
      edRoot.Text := s;
    SetPaths;
  end;
end;

function TForm1.FullPath(p: ZPaths; const fn: String): String;
var
  ed:  TEdit;
  t:   String;
begin
  ed := PathEdit(p);
  t := ed.Text;
  if t = '' then
  begin
    t := defPaths[p];
    if p <> zphRoot then
      t := PathConcat(edRoot.Text, t)
    else
      t := PathConcat(ExtractFilePath(Application.ExeName), t);
    t := ExpandFileName(DelimitPath(t, True));
    ed.Text := t;
  end;
  if fn <> '' then
    Result := PathConcat(t, fn)
  else
    Result := t;
end;

function TForm1.GetBuild(const pth: String): Integer;
var
  hndl:  HWND;
  fspec: String;
  PrivFunc:

  function: DWord; stdcall;
  OldMode: Cardinal;
begin
  Result := 0;
  fspec := pth;
  if not FileExists(fspec) then  // must exist where stated
    exit;
  oldMode := SetErrorMode(SEM_FAILCRITICALERRORS or SEM_NOGPFAULTERRORBOX);
  try
    hndl := LoadLibrary(Pchar(fspec));
    if hndl > HInstance_Error then
    begin
      @PrivFunc := GetProcAddress(hndl, Pchar(DelZipDll_Privfunc));
      if @PrivFunc <> Nil then
        Result := PrivFunc;
      FreeLibrary(hndl);
    end;
  finally
    SetErrorMode(oldMode);
  end;
end;

function TForm1.GetZipBuild: Integer;
begin
  Result := GetBuild(FullPath(zphDll, DelZipDll_Name));
end;

function TForm1.HasFile(Sender: TObject; const f: String): Boolean;
var
  fs:  TFontStyles;
  ed:  TEdit;
begin
  Result := False;
  if Sender is TEdit then
  begin
    ed := TEdit(Sender);
    if FileExists(PathConcat(ed.Text, f)) then
    begin
      fs := [];
      Result := True;
    end
    else
      fs := [fsItalic];
    ed.Font.Style := fs;
  end;
end;

function TForm1.IsUPXFile(const fn: String): Boolean;
type
  PEheader = packed record
    signature: DWord;
    _head: IMAGE_FILE_HEADER;
    opt_head: IMAGE_OPTIONAL_HEADER;
    section_header: IMAGE_SECTION_HEADER;
  end;

  pIMAGE_DOS_HEADER = ^IMAGE_DOS_HEADER;
  pPEHeader = ^PEHeader;
  pIMAGE_SECTION_HEADER = ^IMAGE_SECTION_HEADER;
var
  fs:  TFileStream;
  buf: array of Byte;

  procedure CheckSections;
  var
    section: Integer;
    DOSHead: pIMAGE_DOS_HEADER;
    Header:  pPEheader;
    SectionHeader: pIMAGE_SECTION_HEADER;
  begin
    // look if file has already been UPX'd
    // Read and check the file for an UPX0 section
    DOSHead := pIMAGE_DOS_HEADER(@Buf[0]);
    if DOSHead^.e_magic <> IMAGE_DOS_SIGNATURE then
      exit;
    Header := pPEHeader(@Buf[DOSHead._lfanew]);
    if Header^.signature <> IMAGE_NT_SIGNATURE then
      exit;
    SectionHeader := @Header^.section_header;
    for section := 0 to pred(Header^._head.NumberOfSections) do
    begin
      // check for name = 'UPX0'#0#0#0#0
      if pInt64(@SectionHeader.Name)^ = $30585055 then
      begin
        Result := True;   // upx section found
        exit;
      end;
      inc(SectionHeader);
    end;
    // section not found
  end;

begin
  Result := False;
  if not FileExists(fn) then
    exit;
  fs := TFileStream.Create(fn, fmOpenRead);
  try
    SetLength(Buf, fs.size);
    fs.Read(buf[0], fs.Size);
    CheckSections;
  finally
    FreeAndNil(fs);
    Buf := Nil;
  end;
end;

function TForm1.MakeDllBin: Boolean;
var
  DVer, zv: Integer;
  src, dst, tmp, cmd: String;
  r:   Integer;
  fs, fo: TFileStream;
  fm:  TMemoryStream;

  function fCopy(const ffrom, fto: String): Integer;
    //  var
    //    fs, fo: TFileStream;
  begin
{$Hints off}
    Result := -1;
    fo := Nil;
    fs := Nil;
    try
      fs := TFileStream.Create(ffrom, fmOpenRead);
      fo := TFileStream.Create(fto, fmCreate);
      fo.CopyFrom(fs, fs.Size);
      Result := 0;
      Show('copied ' + ffrom + ' to ' + fto);
    finally
      FreeAndNil(fs);
      FreeAndNil(fo);
    end;
  end;

begin
  Result := False;
  DVer := DllBuild;
  Show( Format('%s = %d.%d.%2.2d.%2.2d', [DelZipDll_Name, DVer div 1000000,
       (DVer mod 1000000) div 10000, (DVer mod 10000) div 100, DVer mod 100]));
  if DVer < 179000 then
  begin
    Show(DelZipDll_Name + 'is too old!');
    exit;
  end;
  src := FullPath(zphDll, DelZipDll_Name);
  dst := FullPath(zphDest, DLLBinName);
  if FileExists(FullPath(zphUPX, 'upx.exe')) and cbUseUPX.Checked then
  begin
    tmp := FullPath(zphDest, DelZipDll_Name);
    if fcopy(src, tmp) <> 0 then
    begin
      Show(' could not copy to ' + tmp);
      exit;
    end;
    zv := DVer;
    cmd := '"' + FullPath(zphUPX, 'UPX.EXE') + '" --best "' + tmp + '"';
    Show('running ' + cmd);
    if RunProcess(cmd) <> 0 then
    begin
      Show('failed');
      exit;
    end;
    if FileExists(dst) then
      DeleteFile(dst);
    Result := RenameFile(tmp, dst);
    if Result then
      try
        fs := TFileStream.Create(dst, fmOpenRead);
        Show(dst + ' = ' + IntToStr(fs.Size));
      finally
        FreeAndNil(fs);
      end;
    exit;
  end;
  // make compressed copy
  fo := Nil;
  fs := Nil;
  fm := Nil;
  try
    fs := TFileStream.Create(src, fmOpenRead);
    Show(src + ' = ' + IntToStr(fs.Size));
    fo := TFileStream.Create(dst, fmCreate);
    r := LZ77Compress(fo, fs);
    if (r <> 0) or (fo.Size >= fs.Size) then
      Show('Compression failed')
    else
    begin
      Show(dst + ' = ' + IntToStr(fo.Size));
      //verify compression
      fo.Position := 0;
      fm := TMemoryStream.Create;
      r := LZ77Extract(fm, fo, fo.Size);
      if r = 0 then
      begin
        r := CompStreams(fm, fs);
        if r <> 0 then
          Show('files do not match')
        else
        begin
          Result := True;
          Show('verified');
        end;
      end
      else
        Show('could not expand file');
    end;
  finally
    FreeAndNil(fs);
    FreeAndNil(fo);
    FreeAndNil(fm);
  end;
  if (not Result) and FileExists(dst) then
  begin
    DeleteFile(dst);
    Show('Removed bad file');
  end;
end;

function TForm1.CheckLang(const lbl: string): Boolean;
var
  idx: integer;
  frc, fres: string;
  Orc, Ores: TDateTime;
  opt: string;
begin
  Result := false;
  fres := FullPath(zphLang, 'ZipMsg' + lbl + '.res');
  frc := FullPath(zphLang, 'ZipMsg' + lbl + '.rc');
  Orc := 0;
  if FileExists(frc) then
    FileAge(frc, Orc);
  Ores := 0;
  if FileExists(fres) then
    FileAge(fres, Ores);
  if (Orc = 0) and  (Ores = 0) then
  begin
    Show(' could not find ' + frc);
    exit;
  end;
  Result := true;
  if Orc > Ores then
  begin
    Show(' compile ' + frc);
    idx := Find_Lang(Langs, lbl);
    opt := '';
    if idx >= 0 then
      opt := '-c' + IntToStr(Langs[idx].p);
    RunBRCC(frc, fres, opt);
    Result := FileExists(fres);
  end;
end;

function TForm1.MakeLanguageBin: Boolean;
var
  LLangs: TStringList;
  ms:  TFileStream;
  i:   Integer;
  s:   String;
begin
  Result := False;
  ms := Nil;
  LLangs := TStringList.Create;
  try
    for i := 0 to pred(lbLangs.Count) do
      if lbLangs.ItemEnabled[i] and lbLangs.Checked[i] then
      begin
        s := lbLangs.Items[i];
        LLangs.Add(s);
      end;
    if LLangs.Count > 0 then
    begin
      ms := TFileStream.Create(FullPath(zphDest, 'langs.bin'), fmCreate);
      i := CompileStrings(LLangs, ms);
      Show(' compiled ' + IntToStr(i) + ' languages');
      Result := True;
    end
    else
      Show('no valid languages selected');
  finally
    FreeAndNil(LLangs);
    FreeAndNil(ms);
  end;
end;

procedure TForm1.PagesChange(Sender: TObject);
begin
  if Busy and (Pages.TabIndex <> pred(Pages.PageCount)) then
    Pages.TabIndex := pred(Pages.PageCount);
end;

function TForm1.PathEdit(p: ZPaths): TEdit;
begin
  case p of
    zphRoot:
      Result := edRoot;
    zphDest:
      Result := edDest;
    zphDll:
      Result := edDll;
    zphLang:
      Result := edLang;
    zphUPX:
      Result := edUPX;
    else
      Result := edVCL;
  end;
end;

function TForm1.RunBRCC(const rc, res, opts: String): Boolean;
begin
  Result := RunProcess('BRCC32.exe -32  ' + opts + ' -fo "' + res + '" "' + rc+ '"') = 0;
  if not Result then
    Show('BRCC32.exe failed');
end;

function TForm1.RunProcess(const ExecCmd: String): Cardinal;
const
  CR = #$0D;
  LF = #$0A;
  TerminationWaitTime = 5000;
var
  si:  TStartupInfo;
  pi:  TProcessInformation;
  sa:  TSecurityAttributes;
  sd:  TSecurityDescriptor;
  lpsa: PSecurityAttributes;

  TempHandle,
  WriteHandle,
  ReadHandle: THandle;
  ReadBuf: array[0..$100] of AnsiChar;
  BytesRead: Cardinal;
  LineBuf: array[0..$100] of AnsiChar;
  LineBufPtr: Integer;
  Newline: Boolean;
  i:   Integer;

  procedure OutputLine;
  begin
    LineBuf[LineBufPtr] := #0;
    Show('|  ' + LineBuf);
    Newline := False;
    LineBufPtr := 0;
  end;

begin
  //  cmd := 'BRCC32.exe -32 -v ' + opts + ' -fo ' + res + ' ' + rc;
  //  cmd := 'BRCC32.exe -32  ' + opts + ' -fo ' + res + ' ' + rc;
  lpsa := Nil;
  FillChar(si, SizeOf(TStartupInfo), 0);
  FillChar(ReadBuf, SizeOf(ReadBuf), 0);
  FillChar(sa, SizeOf(TSecurityAttributes), 0);
  LineBufPtr := 0;
  Newline := True;
  if Win32Platform = VER_PLATFORM_WIN32_NT then
  begin
    InitializeSecurityDescriptor(@sd, SECURITY_DESCRIPTOR_REVISION);
    SetSecurityDescriptorDacl(@sd, True, Nil, False);
    sa.nLength := sizeof(TSecurityAttributes);
    sa.bInheritHandle := True;
    sa.lpSecurityDescriptor := @sd;
    lpsa := @sa;
  end;
  CreatePipe(ReadHandle, WriteHandle, lpsa, 0);
  {create a pipe to act as StdOut for the child. The write end will need
   to be inherited by the child process}

  try
    {Read end should not be inherited by child process}
    if Win32Platform = VER_PLATFORM_WIN32_NT then
    begin
      if not SetHandleInformation(ReadHandle, HANDLE_FLAG_INHERIT, 0) then
      begin
        RaiseLastOSError;
        exit;
      end;
    end
    else
    begin
      {SetHandleInformation does not work under Window95, so we
      have to make a copy then close the original}
      if not DuplicateHandle(GetCurrentProcess, ReadHandle,
        GetCurrentProcess, @TempHandle, 0, True, DUPLICATE_SAME_ACCESS) then
      begin
        RaiseLastOSError;
        exit;
      end;
      CloseHandle(ReadHandle);
      ReadHandle := TempHandle;
    end;

    with si do
    begin
      cb := SizeOf(TStartupInfo);
      dwFlags := STARTF_USESTDHANDLES or STARTF_USESHOWWINDOW;
      wShowWindow := SW_HIDE;
      hStdOutput := WriteHandle;
    end;

    if not CreateProcess(Nil, Pchar(ExecCmd), Nil, Nil, True,
      {inherit kernel object handles from parent}
      NORMAL_PRIORITY_CLASS or CREATE_NO_WINDOW,
               {DETACHED_PROCESS relevant for Console parent only
               No need to create an output window - it would be
               blank anyway}
      Nil, Nil, si, pi) then
    begin
      RaiseLastOSError;
      exit;
    end;

    CloseHandle(pi.hThread);
    {not interested in threadhandle - close it}

    CloseHandle(WriteHandle);
    {close our copy of Write handle - Child has its own copy now.}

    try
      while ReadFile(ReadHandle, ReadBuf, SizeOf(ReadBuf), BytesRead, Nil) do
        for  i := 0 to BytesRead - 1 do
          if (ReadBuf[i] = LF) then
            Newline := True
          else
          if (ReadBuf[i] = CR) then
            OutputLine
          else
          begin
            LineBuf[LineBufPtr] := ReadBuf[i];
            Inc(LineBufPtr);
            if LineBufPtr >= (SizeOf(LineBuf) - 1) then
            begin   {line too long - force a break}
              Newline := True;
              OutputLine;
            end;
          end{There are much more efficient ways of doing this: we don't really
        need two buffers, but we do need to scan for CR & LF &&&};
      WaitForSingleObject(pi.hProcess, TerminationWaitTime);
      GetExitCodeProcess(pi.hProcess, Result);
      OutputLine; {flush the line buffer}
      if Result <> 0 then
        Show('RunProcess returned ' + IntToStr(Result));
    finally
      CloseHandle(pi.hProcess)
    end
  finally
    CloseHandle(ReadHandle);
  end;
end;

procedure TForm1.SetBusy(const Value: Boolean);
begin
  if fBusy <> Value then
    fBusy := Value;
end;

procedure TForm1.SetChecks(lb: TCheckListBox; state: Boolean);
var
  i: Integer;
begin
  for i := 0 to pred(lb.Count) do
    if lb.ItemEnabled[i] then
      lb.Checked[i] := state;
end;

procedure TForm1.SetPaths;
var
  s: String;
  p: ZPaths;
begin
  s := ExpandFileName(edRoot.Text);

  for p := zphDest to zphVCL do
    PathEdit(p).Text := DelimitPath(PathConcat(s, defPaths[p]), True);
  PathEdit(zphUPX).Text := '';
end;

procedure TForm1.Show(const s: String);
begin
  Pages.ActivePageIndex := pred(Pages.PageCount);
  Memo1.Lines.Add(s);
end;

procedure TForm1.UpdateList({lids: array of TLangs;} const fs: String);
var
  lst: TCheckListBox;
  idx, ii: Integer;
  f, l, p:   String;
  sr:  TSearchRec;
  lid: Integer;

  function InTbl(const x: String): Integer;
  var
    ii, cp: Integer;
    ss: String;
  begin
    Result := -1;
    for ii := 0 to pred(lst.Count) do
    begin
      ss := lst.Items[ii];
      cp := AnsiPos(':', ss);
      if cp > 0 then
        ss := copy(ss, 1, cp - 1);
      if Uppercase(ss) = x then
      begin
        Result := ii;
        break;
      end;
    end;
  end;

begin
  lst := lbLangs;
  for ii := 0 to pred(lst.Count) do
    lst.ItemEnabled[ii] := False;
  p := ExtractFilePath(fs);
  if FindFirst(fs, faReadOnly + faArchive, sr) = 0 then
  begin
    repeat
      if (sr.Attr and faDirectory) <> 0 then
        continue;
      if sr.Name[1] = '.' then
        continue;
      f := Uppercase(copy(sr.Name, 7, length(sr.Name) - (6 + 4)));
      if (f = '') or (f = 'US') then  // ignore empty, hidden, default
        continue;
      idx := InTbl(f);
      if idx < 0 then
      begin
        l := LangOfRes(p + sr.Name);
        if l <> '' then
          f := l
        else
          f := f + ': ???';
//        lid := Find_Lang(lids, f);
//        if lid >= 0 then
//          f := lids[lid].s;
        idx := lst.Items.Add(f);
        lst.Checked[idx] := True;
      end;         
      if idx >= 0 then
        lst.ItemEnabled[idx] := True;
    until FindNext(sr) <> 0;
    FindClose(sr);
  end;
end;

function TForm1.WantDlls: Boolean;
begin
  Result := cbDlls.Enabled and cbDlls.Checked;
end;

function TForm1.WantLangs: Boolean;
var
  i: Integer;
begin
  Result := True;
  for i := 0 to pred(lbLangs.Count) do
    if lbLangs.ItemEnabled[i] and lbLangs.Checked[i] then
      exit;
  Result := False;
end;

function TForm1.WriteRC(const fn: String; what: ZParts): Boolean;
var
  ustrs: TStringList;
  u, z:  Integer;
  where: String;
begin
  ustrs := Nil;
  where := FullPath(zphDest, fn + '.rc');
  result := False;
  u := 0;
  z := 0;
  try
    ustrs := TStringList.Create;
    ustrs.Add('/* ' + fn + '.rc ');
    ustrs.Add('    machine generated ');
    ustrs.Add('      by ZipResMaker (c) ');
    ustrs.Add('     Do NOT edit ');
    ustrs.Add('  ' + fn + '.rc - resource script');
    ustrs.Add('  TZipMaster VCL by Chris Vleghert and Eric W. Engler');
    ustrs.Add(' ');
    ustrs.Add('  v1.79');
    ustrs.Add('      Copyright (C) 2005  Russell Peters');
    ustrs.Add(' ');
    ustrs.Add('  This library is free software; you can redistribute it and/or');
    ustrs.Add('  modify it under the terms of the GNU Lesser General Public');
    ustrs.Add('  License as published by the Free Software Foundation; either');
    ustrs.Add('  version 2.1 of the License, or (at your option) any later version.');
    ustrs.Add(' ');
    ustrs.Add('  This library is distributed in the hope that it will be useful,');
    ustrs.Add('  but WITHOUT ANY WARRANTY; without even the implied warranty of');
    ustrs.Add('  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU');
    ustrs.Add('  Lesser General Public License (licence.txt) for more details.');
    ustrs.Add(' ');
    ustrs.Add('  You should have received a copy of the GNU Lesser General Public');
    ustrs.Add('   License along with this library; if not, write to the Free Software ');
    ustrs.Add('  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA'
      );
    ustrs.Add(' ');
    ustrs.Add('  contact: zipmaster AT delphizip DOT net');
    ustrs.Add('  updates: http://www.delphizip.net ');
    ustrs.Add(' ');
    ustrs.Add('  modified ' + DateTimeToStr(Now));
    ustrs.Add('---------------------------------------------------------------------------*/');
    ustrs.Add(' ');
    ustrs.Add('/* ZipMaster 1.79.00.05       */');
    ustrs.Add('/* Copyright (c) 2005         */');
    ustrs.Add(' ');
    ustrs.Add('#define  RDLL_Dll  11613');
    ustrs.Add('#define  RDLL_Ver 11612');
    ustrs.Add('#define  DZRES_Str 11610');
    ustrs.Add(' ');
    if zrpLangs in what then
    begin
      ustrs.Add('DZRES_Str RCDATA LOADONCALL MOVEABLE DISCARDABLE "langs.bin"');
      ustrs.Add(' ');
      ustrs.Add(' ');
    end;
    if zrpDlls in what then
    begin
      z := DllBuild;
      if z > 1790000 then
      begin
        ustrs.Add('RDLL_Dll RCDATA LOADONCALL MOVEABLE DISCARDABLE "'          +
          DLLBinName + '"');
        ustrs.Add(' ');
        ustrs.Add('STRINGTABLE {');
        ustrs.Add('	RDLL_Ver, "' + IntToStr(z) + '"');
        ustrs.Add('}');
      end;
    end;
    BackupFile(where);
    ustrs.SaveToFile(where);
    Result := True;
  finally
    FreeAndNil(ustrs);
  end;
end;

function LIdOfRes(const fn: String): Word;
var
  fs: TFileStream;
  blk: array of Word;
  rid: Integer;
  DatSiz, HedSiz: Cardinal;
  sz: Cardinal;
  bp, hp: Integer;
begin
  Result := $FFFF;
  if not FileExists(fn) then
    exit;
  try
    fs := TFileStream.Create(fn, fmOpenRead);
    if fs.Size > 40000 then
      exit;
    SetLength(blk, Cardinal(fs.Size));
    fs.ReadBuffer(blk[0], fs.Size);
    bp := 0;
    while (bp + 8) < HIGH(Blk) do
    begin
      bp := (bp + 1) and $7fffE;  // dword align
      DatSiz := (blk[bp+1] shl 16) + blk[bp];
      HedSiz := (blk[bp+3] shl 16) + blk[bp+2];
//      DatSiz := pCardinal(@blk[bp])^;
//      HedSiz := pCardinal(@blk[bp+2])^;
      sz := HedSiz + DatSiz - 8;
      hp := bp + 4;
      inc(bp, 4 + (sz div 2));
      if blk[hp] <> $ffff then
        continue;  // bad res type
      if blk[hp+1] <> 6 then
        continue;      // not string table
      if blk[hp+2] <> $ffff then
        continue;      // not numbered
      rid := pred(blk[hp + 3]);
      if (rid < (GE_FatalZip div 16)) or (rid > (TM_SystemError div 16)) then
        continue;
      Result := blk[hp+7];  // language id
      break;
    end;
  finally
    FreeAndNil(fs);
    blk := nil;
  end;
end;

end.

