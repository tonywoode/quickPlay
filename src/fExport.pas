unit fExport;

interface

uses
  Windows, SysUtils, Classes, Controls, Forms, Dialogs,
  StdCtrls, Buttons, VirtualTrees, uRomList, uQPMiscTypes,
  fjWinFontForm;

type

  TROMexport = class(TJWinFontForm)
    SaveDialog: TSaveDialog;
    GroupOutput: TGroupBox;
    RadSelDir: TRadioButton;
    RadAllDir: TRadioButton;
    RadEmu: TRadioButton;
    RadMissMame: TRadioButton;
    CboEmu: TComboBox;
    GrpROMinfo: TGroupBox;
    ChkName: TCheckBox;
    ChkPath: TCheckBox;
    ChkEmu: TCheckBox;
    RadSys: TRadioButton;
    CboSys: TComboBox;
    CboMame: TComboBox;
    BtnOutput: TButton;
    BtnClose: TButton;
    ChkEmuLinks: TCheckBox;
    chkYear: TCheckBox;
    chkType: TCheckBox;
    chkLanguage: TCheckBox;
    chkRating: TCheckBox;
    grpOtherOptions: TGroupBox;
    ChkClose: TCheckBox;
    ChkLaunch: TCheckBox;
    GrpFormat: TGroupBox;
    radhtml: TRadioButton;
    RadXML: TRadioButton;
    RadText: TRadioButton;
    ChkPlayers: TCheckBox;
    procedure RadEmuClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure BtnOutputClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure ChkEmuClick(Sender: TObject);
    procedure radhtmlClick(Sender: TObject);
    procedure RadXMLClick(Sender: TObject);
    procedure RadTextClick(Sender: TObject);
  private
    { Private declarations }
    Code : TStringList;
    procedure LoadOldSettings();
    Function OutputMissingMameRoms(Format : TQPExportFormat): integer;
    function HTMLWrite(TotalString : string):string;
    function TxtWrite():string;
    function XMLWrite():string;
  public
    { Public declarations }
  end;

implementation

uses ShellAPI, Inifiles, fMain, uJUtilities,
     JCLStrings, JCLFileUtils, uEmuList, uEmu, uRom, uRomUtils, uQPConst;

{$R *.DFM}

{-----------------------------------------------------------------------------}

procedure TROMexport.RadEmuClick(Sender: TObject);
begin
  cboemu.enabled := RadEmu.Checked;
  CboSys.enabled := RadSys.checked;
  CboMame.Enabled := RadMissMame.Checked;

  chkname.Enabled := not RadMissMame.checked;
  chkpath.enabled := not RadMissMame.checked;
  chkemu.enabled := not RadMissMame.checked;
  chkEmuLinks.Enabled := not RadMissMame.checked;
  chkYear.Enabled := not RadMissMame.checked;
  chkRating.Enabled := not RadMissMame.checked;
  chkLanguage.Enabled := not RadMissMame.checked;
  chkType.Enabled := not RadMissMame.checked;
end;

{-----------------------------------------------------------------------------}

procedure TROMexport.FormClose(Sender: TObject; var Action: TCloseAction);
var
  Ini : TMemIniFile;

  Procedure SaveChk(Chkbox : TCheckBox);
  begin
    case ChkBox.checked of
      false : Ini.WriteInteger('HTML', ChkBox.Name, 0);
      true : Ini.WriteInteger('HTML', ChkBox.name, 1);
    end;
  end;

begin

  Ini := TMemIniFile.create(MainFrm.Settings.Paths.SettingsFile);
  try

    SaveChk(ChkName);
    SaveChk(ChkPath);
    SaveChk(ChkEmu);
    SaveChk(ChkEmuLinks);
    SaveChk(chkRating);
    SaveChk(chkLanguage);
    SaveChk(chkType);
    SaveChk(chkYear);
    SaveChk(ChkLaunch);
    SaveChk(ChkClose);

    If Savedialog.Filename <> '' then
      Ini.WriteString('HTML', 'LastDir', ExtractFilePath(SaveDialog.filename));

    Ini.UpdateFile;

  finally
    FreeAndNil(Ini);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TROMexport.FormShow(Sender: TObject);
begin
  With MainFrm do
  Begin
    EmuList.EmusToStrings(cboemu.Items, cfAllEmus);
    EmuList.EmusToStrings(CboMame.Items, cfMame);
    CboSys.Items.LoadFromFile(Settings.Paths.SystemsFile);
    LoadOldSettings;
    SaveDialog.FileName := 'Output';
  end;                           
end;

{-----------------------------------------------------------------------------}

procedure TROMexport.BtnOutputClick(Sender: TObject);
var
  OldStyle : TCursor;
  i, total : integer;
  output : String;
  zFileName: array[0..255] of Char;
  Format : TQPExportFormat;
  Opt : TQPExportOpt;
  Mode : TQPExportMode;
  HeaderString, OutputFile, Filter : String;
  RomFiles : TStringList;
  TmpList : TQPROMList;
begin

  //Set up the Dialog box with the appropriate options.
  If SaveDialog.Execute = true then
    if SaveDialog.filename <> '' then
      output := SaveDialog.FileName
    else
      exit
  else
    exit;

  //Change the mouse to the hourglass.
  OldStyle := screen.cursor;
  Screen.cursor := crHourGlass;
  try
    total := 0;

    ROMFiles := TStringList.Create;
    try
      uROMUtils.GetAllROMFiles(ROMFiles);

    //get the format type we need to use
    If RadHTML.Checked then
      Format := efHTML
    else if RadText.Checked then
      Format := efText
    else if RadXML.Checked then
      Format := efXML
    else
      Format := efHTML; //somethign went wrong, default to HTML

    //determine the output mode.

    Filter := '';
    
    if RadAllDir.Checked then
      Mode := emAllDirs
    else if RadSelDir.Checked then
    begin
      Mode := emAll;
      ROMFiles.Clear;
      ROMFiles.Add(MainFrm.GetSelectedTxt);
    end
    else if RadEmu.Checked then
    begin
      Mode := emEmu;
      Filter := cboEmu.Text;
    end
    else if RadSys.Checked then
    begin
      Mode := emSys;
      Filter := cboSys.Text;
    end
    else if RadMissMame.Checked then
    begin
      Mode := emMissing;
      Filter := cboMame.Text;
    end
    else
      Mode := emAllDirs; //something went wrong, default to output all directories.

    //create the Export Options record.
    Opt.AddName := ChkName.Checked;
    Opt.AddPath := ChkPath.Checked;
    Opt.AddEmu := ChkEmu.Checked;
    Opt.AddWWW := ChkEmuLinks.Checked;
    Opt.AddYear := ChkYear.Checked;
    Opt.AddType := ChkRating.Checked;
    Opt.AddLanguage := ChkLanguage.Checked;
    Opt.AddRating := ChkRating.Checked;
    Opt.AddPlayers := ChkPlayers.Checked;

    //create a code stringlist to hold our roms
    code := TStringList.Create;

    if Mode = emMissing then
    begin
      total := OutputMissingMameRoms(Format);
    end
    else
    begin
      TmpList := TQPROMList.Create(False);
      try
        for i := 0 to ROMFiles.Count-1 do
        begin
          TmpList.LoadFromFile(RomFiles[i]);
          Total := Total + TmpList.ExportRoms(Code, Format, Opt, MainFrm.EmuList, Mode, Filter);
        end;
      finally
        FreeAndNil(TmpList);
      end;
    end;

    finally
      FreeAndNil(RomFiles);
    end;

    HeaderString := IntToStr(Total) + ' ' + QP_ROMS;

    case Format of
      efHTML : OutputFile := HTMLwrite(HeaderString);
      efText  : OutputFile := TxtWrite();
      efXML   : OutputFile := XMLWrite();
    end;

  finally
    Screen.cursor := oldstyle;
  end;

  //If Auto-Launch is checked then load the HTML file
  If ChkLaunch.Checked then
  begin
    StrPCopy(zFileName, OutputFile);
    ShellExecute(Handle, 'open', zFileName,nil,nil,SW_SHOWNORMAL);
  end;

  //If auto-close is checked then close the form on completion
  IF ChkClose.Checked then
    ModalResult := MrOk
  Else
    ModalResult := MrNone;

end;

{-----------------------------------------------------------------------------}

procedure TROMexport.ChkEmuClick(Sender: TObject);
begin
  chkEmuLinks.Enabled := chkemu.Checked;
end;

{-----------------------------------------------------------------------------}

procedure TROMexport.radhtmlClick(Sender: TObject);
begin
  SaveDialog.Filter := 'Html File (*.html, *.htm)|*.htm;*.html';
end;

procedure TROMexport.RadXMLClick(Sender: TObject);
begin
  SaveDialog.Filter := 'XML File (*.xml)|*.xml';
end;

procedure TROMexport.RadTextClick(Sender: TObject);
begin
  SaveDialog.Filter := 'Text File (*.txt)|*.txt';
end;

{-----------------------------------------------------------------------------}
{                              Private Routines                               }
{-----------------------------------------------------------------------------}

Function TROMexport.OutputMissingMameRoms(Format : TQPExportFormat) : integer;
var
  i, f, r, c, total: integer;
  tempFile, tempfile2, MameName, game : string;
  IniName : String[8];
  mameList, ROMFiles : TStringList;
  IniObj : TMemIniFile;
  TmpList : TQPROMList;
  Emu : TQPEmu;
begin
  tempFile := extractshortpathname(MainFrm.Settings.Paths.CfgDir)+ 'mame.tmp';
  tempFile2 := extractshortpathname(MainFrm.Settings.Paths.CfgDir)+ 'gmame.tmp';
  MameName := extractshortPathName(MainFrm.Settings.Paths.CfgDir) + cboMame.Text + '.ini';
  total := 0;

  With MainFrm do
  Begin

    //find the emulator we need to use.
    i := EmuList.IndexOfName(cboMame.text);
    if i <> -1 then
    begin
      Emu := EmuList[i];

      //Create the Mame DAT file if it doesnt already exist
      if not FileExists(MameName) then
      begin
        try
          Emu.MameCreateDataFile(Settings.Paths.CfgDir);
        except
          on E: EJException do MessageDlg(E.Message, mtError, [mbOK], 0);
        end;
      end;

      IniObj := TMemIniFile.Create(MameName);
      try
        mameList := TStringlist.create;
        try
          IniObj.ReadSections(MameList);
          MameList.Delete(0);

          TmpList := TQPROMlist.Create(MainFrm.Settings.AllowWrite);
          try
            ROMFiles := TStringList.Create;
            uROMUtils.GetAllROMFiles(ROMFiles);

            //Load all the datafiles in one at a time and compare them.
            for f := 0 to ROMFiles.Count-1 do
            begin
              TmpList.LoadFromFile(ROMFiles[f]);

              //Carry out this loop for all the roms
              for r := 0 to TmpList.Count-1 do
              begin
                If TmpList[r].MAMEname <> '' then
                  game := TmpList[r].MAMEname
                else
                begin
                  game := extractfilename(TmpList[r].path);
                  Game := lowercase(ChangeFileExt(game, ''));
                end;
                //Check the roms array to what is in the DAT file.
                c:= MameList.IndexOf(Game);
                If c <> -1 then
                  MameList.Delete(C);

              end;  //end of FOR loop
            end;   //end of FOR Loop

          finally
            TmpList.Clear;
            FreeAndNil(TmpList);
            FreeAndNil(RomFiles);
          end;

          //convert the remaining array entries into code.
          f:= 0;
          while f <= mamelist.count-1 do
          begin
            IniName := mamelist[f];
            case Format of
              efHTML : begin
                        code.add('<div class="ROM">');
                        code.add('<div class="name">'+ IniObj.ReadString(mamelist.Strings[f], 'name', '') +'</div>');
                        code.add('<div class="info">'+IniName+'</a></div>');
                        code.add('</div>');
                      end;
              efXML   : begin
                        code.Add('<rom>');
                        code.Add('<name>' + IniName + '</name>');
                        code.add('<fullname>'+IniObj.ReadString(mamelist.Strings[f], 'name', '')+'</fullname>');
                        code.Add('</rom>')
                      end;
              efText  : begin
                        code.Add(IniName+','+IniObj.ReadString(mamelist.Strings[f], 'name', '')+',');
                      end;
            end;

            inc(total);
            inc(f);
          end;

        finally
          FreeAndNil(mamelist);
        end;
      finally
        FreeAndNil(IniObj);
      end;
    end;

  end; //end of WITH block
  result := total;
end;

{-----------------------------------------------------------------------------}

function TROMexport.HTMLWrite(TotalString : string):string;
var
  HTML : TStringList;
begin
  HTML := TStringList.Create;
  try

    //Add the headers of the HTML file.
    HTML.add('<?xml version="1.0" encoding="utf-8" standalone="no"?>');
    HTML.add('<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">');
    HTML.add('<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">');
    HTML.add('  <head>');
    HTML.add('    <title>');
    HTML.add('      QuickPlay Output File');
    HTML.add('    </title>');
    HTML.add('	<style type="text/css">');
    HTML.add('      body {');
    HTML.add('        background : #99CCFF none;');
    HTML.add('        color : Black;');
    HTML.add('        font-family : Tahoma, Arial,Sans-Serif;');
    HTML.add('        font-size : 1em;');
    HTML.add('      }');
    HTML.add('	  h1{');
    HTML.add('	    font-size : 1.8em;');
    HTML.add('		font-weight : bolder;');
    HTML.add('		width : 100%;');
    HTML.add('		background : white none;');
    HTML.add('		color : Black;');
    HTML.add('		text-align : center;');
    HTML.add('	  }');
    HTML.add('	  a{');
    HTML.add('	    color : #3399CC;');
    HTML.add('	    background : transparent none;');
    HTML.add('	  }');
    HTML.add('	  h2{');
    HTML.add('	        font-size : 1.1em;');
    HTML.add('		width : 100%;');
    HTML.add('		background : white none;');
    HTML.add('		color : black;');
    HTML.add('	  }');
    HTML.add('	  div.ROM{');
    HTML.add('		background : white none;');
    HTML.add('		color : black;');
    HTML.add('		padding : 0.2em;');
    HTML.add('		border : thin solid Black;');
    HTML.add('		margin : 0.1em;');
    HTML.add('	  }');
    HTML.add('	  div.name{');
    HTML.add('		background : transparent none;');
    HTML.add('		color : black;');
    HTML.add('		font-weight : bolder;');
    HTML.add('	  }');
    HTML.add('	  div.info{              ');
    HTML.add('          padding : 0.1em;');
    HTML.add('          font-size : 0.9em;');
    HTML.add('	  }                   ');
    HTML.add('	  div.footer{');
    HTML.add('	        background : white none;');
    HTML.add('		color : black;');
    HTML.add('		padding : 0.2em;');
    HTML.add('		font-size : 0.8em;');
    HTML.add('	  }');
    HTML.add('    </style>');
    HTML.add('  </head>');
    HTML.add('  <body>');
    HTML.add('    <h1>QuickPlay</h1>');

    //now add in the total string
    HTML.add('    <h2>' + TotalString + '</h2>');

    //now add the custom content - the roms
    HTML.AddStrings(Code);

    //now add the footer.
    HTML.add('      <div class="footer"> ');
    HTML.add('    <a href="http://quickplay.sf.net">http://quickplay.sf.net</a>');
    HTML.add('  </div>');
    HTML.add('</body>');
    HTML.add('</html>');

    HTML.SaveToFile(ChangeFileExt(SaveDialog.FileName, '.html'));
    Result := ChangeFileExt(SaveDialog.FileName, '.html');

  Finally
    FreeAndNil(HTML);
    FreeAndNil(code);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TROMexport.LoadOldSettings();
var
  Ini : TMemIniFile;

    procedure Check(ChkBox: TCheckBox);
    begin
      if Ini.ValueExists('HTML', ChkBox.name) then
        case (Ini.ReadInteger('HTML', ChkBox.name, 0)) of
          0: Chkbox.checked := false;
          1: Chkbox.Checked := true;
        end;
    end;

begin
  Ini := TMemIniFile.create(MainFrm.Settings.Paths.SettingsFile);
  try
      check(chkname);
      check(ChkPath);
      check(ChkEmu);
      ChkEmuLinks.Enabled := ChkEmu.Checked;
      check(ChkEmuLinks);
      check(chkRating);
      check(chkLanguage);
      check(chkType);
      check(chkYear);
      Check(ChkClose);
      Check(ChkLaunch);
    If Ini.ValueExists('HTML', 'LastDir') then
      SaveDialog.InitialDir := Ini.ReadString('HTML', 'LastDir', '')
    else
      SaveDialog.InitialDir := MainFrm.Settings.Paths.AppDir;
  finally
    FreeAndNil(Ini);
  end;

end;

{-----------------------------------------------------------------------------}

//procedure to output a file containing the roms in text format.
function TROMexport.TxtWrite():string;
begin

  Code.SaveToFile(ChangeFileExt(SaveDialog.FileName, '.txt'));
  Result := ChangeFileExt(SaveDialog.FileName, '.txt');
  FreeAndNil(Code);

end;

{-----------------------------------------------------------------------------}

//procedure to output the ROMs in an XML format.
function TROMexport.XMLWrite() : string;
var
  XMLfile : TStringList;
begin

  XMLfile := TStringList.Create;
  try

    XmlFile.Add('<?xml version="1.0" encoding="UTF-8"?>');
    XmlFile.Add('<roms>');

    XmlFile.AddStrings(Code);

    XmlFile.Add('</roms>');
    XmlFile.SaveToFile(ChangeFileExt(SaveDialog.FileName, '.xml'));
    Result := ChangeFileExt(SaveDialog.FileName, '.xml');

  finally
    FreeAndNil(XMLfile);
  end;

end;

{-----------------------------------------------------------------------------}



end.
