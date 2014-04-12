{

This form is used when you want to add one single ROM to a folder.
I can't say I use this form very often, its often easier to just
drag and drop a single ROM in, but there is always a choice!

Uses the ROM class extensively.

Also saves the last directory that was used to add a ROM

}

unit fAddaRom;

interface

uses
  Windows, SysUtils, Classes, Controls, Forms, Dialogs,
  StdCtrls, Buttons, Mask, JvExMask, JvToolEdit, fjWinFontForm;

type
  TAddRomForm = class(TjWinFontForm)
    CmbEmu: TComboBox;
    lblPath: TLabel;
    lblEmu: TLabel;
    BtnOK: TButton;
    BtnCancel: TButton;
    ChkScanArchive: TCheckBox;
    TxtPath: TJvFilenameEdit;
    procedure TxtPathBeforeDialog(Sender: TObject; var AName: string;
      var AAction: Boolean);
    procedure BtnOKClick(Sender: TObject);
    procedure FormShow(Sender: TObject);

  private
  public
  end;

implementation

uses fMain, uJUtilities, uRom, uROMList, Inifiles, JCLStrings, uEmuList, uQPConst,
  uJCompression, uQPMiscTypes, uQPCompObj, ujCompressResourceStrs, ujMiscResourceStrs,
  uEmuUtils;

{$R *.DFM}

{-----------------------------------------------------------------------------}

procedure TAddRomForm.BtnOKClick(Sender: TObject);
var
  NewROM : TQPROM;
  ini : TMemIniFile;
begin

  if fileexists(TxtPath.text) AND (CmbEmu.text <> '') then
  begin

    //save the selected path.
    Ini := TMemIniFile.Create(MainFrm.Settings.Paths.SettingsFile);
    Try
      Ini.WriteString('Scan','LastAddDir', extractfilepath(TxtPath.Text));
      if MainFrm.Settings.AllowWrite then
        Ini.UpdateFile;
    finally
      FreeAndNil(Ini);
    end;
    
    With MainFrm do
    Begin

      If (ChkScanArchive.Checked) then
      begin

        //the user wants to scan the archive.

        //check that it IS an archive
        if not uQPCompObj.Compression.SupportsFileName(TxtPath.Text, cmRead) then
        begin
          MessageDlg(COMP_FORMAT_UNSUPPORTED, mtError, [mbOK], 0);
          modalresult := mrNone;
          exit;
        end
        else
          RomList.AddFromArchive(TxtPath.Text, CmbEmu.Text, '', lmNone, False);

      end 
      else
      begin
        //just add the rom specified.
        ROMlist.Add(TQProm.create);

        NewROM := ROMlist.Last();

        NewROM.name := ChangeFileExt(ExtractFileName(TxtPath.text),'');
        NewROM.path := TxtPath.text;
        NewROM.emulator := CmbEmu.Text;

        ROMlist.SaveToFile();
      end;

      MainFrm.fillroms(MainFrm.GetSelectedTxt);

    end;

  end
  ELSE
  begin
    MessageDlg(J_ENTER_ALL_DATA, mtWarning, [mbOK], 0);
    modalresult := mrNone;
  end;
  
end;

{-----------------------------------------------------------------------------}

procedure TAddRomForm.FormShow(Sender: TObject);
var
  Ini : TMemIniFile;
begin
  TxtPath.text := '';
  MainFrm.EmuList.EmusToStrings(CmbEmu.Items, cfAllEmus);
  CmbEmu.itemindex := 0;

  Ini := TMemIniFile.Create(MainFrm.Settings.Paths.SettingsFile);
  Try
    if Ini.ValueExists('Scan','LastDir') then
      TxtPath.InitialDir := Ini.ReadString('Scan','LastAddDir','')
    else
      TxtPath.InitialDir := '';
  finally
    FreeAndNil(Ini);
  end;
end;

procedure TAddRomForm.TxtPathBeforeDialog(Sender: TObject; var AName: string;
  var AAction: Boolean);
var
  MyFilter : String;
  Tmp : String;
  Sys : String;
begin

  if CmbEmu.Text <> '' then
  begin
    Sys := MainFrm.EmuList[MainFrm.EmuList.IndexOfName(CmbEmu.Text)].System;
    Tmp := uEmuUtils.FileExtsForSystem(Sys);
    MyFilter := Format('All Supported Formats|%s', [Tmp, Tmp]);
  end
  else
    MyFilter := uQPCompObj.Compression.SupportedFileExtsForOpenDlg('', True);

  TxtPath.Filter := MyFilter;
end;

end.
