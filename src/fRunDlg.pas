unit fRunDlg;

interface

uses
  Windows, SysUtils, StrUtils, Classes, Controls, Forms,
  Dialogs, StdCtrls, uRom, uEmu, fJWinFontForm, fParamVars, ComCtrls;

type
  TFrmRunRom = class(TJWinFontForm)
    BtnRun: TButton;
    BtnCancel: TButton;
    GrpMisc: TGroupBox;
    ChkWinKey: TCheckBox;
    chkScrSvr: TCheckBox;
    ChkMini: TCheckBox;
    ChkAutoClose: TCheckBox;
    GrpEmu: TGroupBox;
    ChkShortEXE: TCheckBox;
    ChkCompress: TCheckBox;
    TxtParam: TEdit;
    lblParam: TLabel;
    GrpROMInfo: TGroupBox;
    lblName: TLabel;
    lblEmu: TLabel;
    lblArchive: TLabel;
    lblZipStatus: TLabel;
    lblPath: TEdit;
    lblArchiveOutput: TEdit;
    lblCommand: TRichEdit;
    procedure FormDestroy(Sender: TObject);
    procedure TxtParamExit(Sender: TObject);
    procedure TxtParamEnter(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure GenericOnChange(Sender: TObject);
    procedure BtnRunClick(Sender: TObject);
    procedure lblCommandMouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
  private
    _FileExt : String;
    _FrmVar : TFrmParamVars;
    function CommandLine: String;
    function GetExtractionPath(ZipFile : TFileName) : TFileName;
    { Private declarations }
  public
    { Public declarations }
    Rom : TQPRom;
    Emu : TQPEmu;
  end;

implementation

uses fMain, uJUtilities, JCLStrings, JCLFileUtils, findFile, Clipbrd, uJFile,
  uQPConst, uJCompression, uQPMiscTypes, uQPCompObj, uJMiscResourcestrs,
  ujCompressResourceStrs;

{$R *.dfm}

{-----------------------------------------------------------------------------}

Function TFrmRunRom.CommandLine : String;
var
  RPath, EPath, OldParam, ExtrPath : String;
  EDest : TQPExtractDest;
Begin

  If (not FileExists(ROM.Path)) and
     (not DirectoryExists(ExtractFilePath(ROM.path))) then
  begin
    Result := J_FILE_NOT_EXIST;
    exit;
  end;

  //set the RPath variable.
  RPath := ROM.Path;

  //reset the zip output label.
  LblArchiveOutput.Text := COMP_ARCHIVE_NOT_EXTRACTED;

  //if this is a ROM contained in a zip collection we need the file name
  if ROM.ZipName <> '' then
  begin

    if Emu.ExtractDest = qemGeneral then
      EDest := MainFrm.Settings.RunOptions.ExtractMode
    else
      EDest := Emu.ExtractDest;

    if EDest = qemROMDir then
      ExtrPath := ExtractFilePath(ROM.Path)
    else
      ExtrPath := MainFrm.Settings.ExtractModeToPath(EDest);

    RPath := ExtrPath + ExtractFileName(ROM.ZipName);

    lblArchiveOutput.text := RPath;
  end;

  //if the emulator doesnt support zips, get the extraction path.
  If (not ChkCompress.Checked) and (fileExists(Rpath)) then
  begin
    if not (uQPCompObj.Compression.SupportsFileName(RPath, cmRead)) then
      lblArchiveOutput.text := COMP_FORMAT_UNSUPPORTED
    else
    begin
      RPath := GetExtractionPath(RPath);
      lblArchiveOutput.text := RPath;
    end;
  end;

  //if the MAMEname value is filled in, assume this is a MAME scanned ROM
  if ROM.MAMEName <> '' then
  begin
    lblArchiveOutput.Text := QP_RUNDLG_MAME_ROM;
    lblArchive.Caption := QP_RUNDLG_MAME_ROM;
  end;

  //check if the emulator exe is to be launched in short name format
  //and check if we are going to omit the emu call when we run (for multiloader - see UExe)

  OldParam := Emu.Parameters;
  try
    Emu.Parameters := TxtParam.Text;
    If ChkShortExe.Checked then
        EPath := ExtractShortPathName(Emu.path) + ' '
    else
        EPath := Emu.path + ' ';

    { Mutliloader functionality: If we've called %EXEPATH% we'll assume
      user doesn't want to call the emulator as the first arg.
      Starting a command line call with ''' ' would be a bad idea, but this
      is just for the display box }

    if AnsiContainsText(Emu.parameters, '%EXEPATH%') then
        EPath := '';

    result := Epath + Emu.DecodeParameterVariables(ROM, MainFrm.ToolList, RPath);

  finally
    Emu.Parameters := OldParam;
  end;
End;

{-----------------------------------------------------------------------------}

function TFrmRunRom.GetExtractionPath(ZipFile : TFileName) : TFileName;
var
  I, FileSize, TmpFileSize : Integer;
  UseDir, FileExt : String;
  ZList : TStrings;
  EDest : TQPExtractDest;
begin

  //this function will get the proposed file path after a zip has been extracted.
  Result := '';

  with MainFrm do
  begin

    if Emu.ExtractDest = qemGeneral then
      EDest := MainFrm.Settings.RunOptions.ExtractMode
    else
      EDest := Emu.ExtractDest;

    if EDest = qemROMDir then
      UseDir := ExtractFilePath(ROM.Path)
    else
      UseDir := MainFrm.Settings.ExtractModeToPath(EDest);

    zList := TStringList.Create;
    try

      uQPCompObj.Compression.ListContentsOfFile(zList, ZipFile);
      
      Case zList.Count of
      0 : raise EJCompressException.Create(COMP_NO_FILES_EXTRACTED);
      1 : Result := UseDir + ExtractFileName(zList[0]);
      else  //more than 1 file was extracted try to guess which is the ROM.  Probably the biggest file will be the ROM.
        begin
        
          FileSize := 0;
          For i := 0 to zList.Count-1 do
          begin
            //get rid of text-like file extensions..
            FileExt := Lowercase(ExtractFileExt(zList[i]));
            If (FileExt = '.txt') or (FileExt = '.nfo') or (FileExt = '.diz') then
              continue;

            Result := UseDir + ExtractFileName(zList[i]);
          end;

        end; //end of ELSE more than 1
    end; //end of CASE statement

    finally
      FreeAndNil(zList);
    end;

  end;//end of with MainFrm.

end;

{-----------------------------------------------------------------------------}

procedure TFrmRunRom.FormCreate(Sender: TObject);
begin
    //create the parameter variables form
  _FrmVar := TFrmParamVars.Create(self);
  _FrmVar.Hide();
end;

procedure TFrmRunRom.FormDestroy(Sender: TObject);
begin
  if _FrmVar.Visible then
    _FrmVar.Close;

  FreeAndNil(_FrmVar);
end;

procedure TFrmRunRom.FormShow(Sender: TObject);
var
  I : Integer;
begin
  With MainFrm, MainFrm.Settings do
  Begin

    lblName.Caption := Rom.name;
    LblPath.Text := ROM.Path;//JCLFileUtils.PathCompactPath(LblPath...., ROM.Path, lblPath.Width, cpCenter);
    LblEmu.Caption := Emu.name;

    If FileExists(Rom.path) then
    begin
      //now get the text for the compress check box.
      if ROM.ZipName <> '' then
        _FileExt := ujFile.GetVirtualFileExtension(ROM.ZipName)
      else
        _FileExt := ExtractFileExt(ROM.Path);

      if uQPCompObj.Compression.SupportsFileName(Rom.Path, cmRead) then
        if uQPCompObj.Compression.VerifyFile(ROM.Path) then
          lblArchive.Caption := J_YES
        else
          lblArchive.Caption := J_NO
      else
      begin
        lblArchive.Caption := COMP_FORMAT_UNSUPPORTED;
        lblArchiveOutput.Text := COMP_FORMAT_UNSUPPORTED;
        ChkCompress.Checked := True;
      end;

    end
    Else if DirectoryExists(ROM.Path) then
    begin
      lblArchive.Caption := J_FILE_IS_DIRECTORY;
      lblArchiveOutput.Text := QP_RUNDLG_MAME_ROM;
    end
    else
      lblArchive.Caption := J_FILE_NOT_EXIST;

    if _FileExt <> '' then
      ChkCompress.Caption := Format('Emulator Supports %s Files', [_FileExt]) ;

    ChkMini.Checked := MiniOnRun;


    if ROM.MAMEName <> '' then
    begin
      ChkCompress.Checked := True;
      ChkCompress.Enabled := False;
      lblArchiveOutput.Text := QP_RUNDLG_MAME_ROM;
    end
    else
    begin
      if uQPCompObj.Compression.SupportsFileName(_FileExt, cmRead) then
        ChkCompress.Checked := Emu.SupportsCompressed[_FileExt]
      else
      begin
        ChkCompress.Checked := True;
        ChkCompress.Enabled := False;
      end;
    end;
    
    ChkShortEXE.Checked := Emu.ShortExe;
    ChkScrSvr.Checked := Emu.DisableScreenSaver;
    ChkWinKey.Checked := Emu.DisableWinKey;

    if (ROM.Parameters <> '') then
    begin
      Case ROM.ParameterMode of
        ParamAfter : TxtParam.Text := Format('%s %s', [Emu.Parameters, ROM.Parameters]);
        ParamOverwrite: TxtParam.Text := ROM.Parameters;
        ParamBefore : TxtParam.Text := Format('%s %s', [ROM.Parameters, Emu.Parameters]);
        ParamAfterNoSpace : TxtParam.Text := Format('%s%s', [Emu.Parameters, ROM.Parameters]);
        ParamBeforeNoSpace : TxtParam.Text := Format('%s%s', [ROM.Parameters, Emu.Parameters]);
      end;
    end
    else
      TxtParam.Text := Emu.Parameters;

    LblCommand.Text := CommandLine();

    //set up all the events - we do this after setting up to avoid executing
    //the code everytime we change at startup!
    for i := 0 to GrpEmu.ControlCount-1 do
      TCheckBox(GrpEmu.Controls[i]).OnClick := GenericOnChange;

    TxtParam.OnChange := GenericOnChange;

  end;//end of WITH block

end;

{-----------------------------------------------------------------------------}

Procedure TFrmRunRom.GenericOnChange(Sender : TObject);
Begin
  lblCommand.Text := CommandLine;
End;

{-----------------------------------------------------------------------------}

procedure TFrmRunRom.BtnRunClick(Sender: TObject);
var
  OldMiniSetting : Boolean;
  CopyEmu : TQPEmu;
begin

  //hide the run dialog
  If ChkMini.Checked then
    Self.Visible := False;

  //change specific settings.
  OldMiniSetting := MainFrm.Settings.MiniOnRun;
  MainFrm.Settings.MiniOnRun := ChkMini.Checked;

  CopyEmu := TQPEmu.Create;
  try
    
    CopyEmu.Assign(Emu);

    //now we have a copy of the emulator object to work with
    CopyEmu.SupportsCompressed[_FileExt] := ChkCompress.Checked;
    CopyEmu.ShortExe := ChkShortExe.Checked;
    CopyEmu.DisableScreenSaver := ChkScrSvr.Checked;
    CopyEmu.DisableWinKey := ChkWinKey.Checked;
    CopyEmu.Parameters := TxtParam.Text;

    //now we have the custom settings in place, run the rom.
    MainFrm.RunROM(Rom, CopyEmu);

  finally
    MainFrm.Settings.MiniOnRun := OldMiniSetting;
    FreeAndNil(CopyEmu);
  end;

  //bring back the Run Dialog
  If ChkMini.Checked and Self.Visible = false then
    Self.Visible := True;

  If ChkAutoClose.Checked then
    //if autoclose is enabled close the form.
    ModalResult := MrOK
  else
    //we need to bring this form to the front.
    Self.BringToFront;

end;

{-----------------------------------------------------------------------------}

procedure TFrmRunRom.lblCommandMouseDown(Sender: TObject;
  Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var
  Clip : TClipBoard;
begin
  If Button = mbRight then
  begin
    lblCommand.SelectAll;
    Clip := ClipBoard;
    Clip.AsText := lblCommand.Text;
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmRunRom.TxtParamEnter(Sender: TObject);
begin
  ShowWindow(_FrmVar.Handle ,SW_SHOWNA);
  _FrmVar.Visible := True;
end;

{-----------------------------------------------------------------------------}

procedure TFrmRunRom.TxtParamExit(Sender: TObject);
begin
  _frmVar.Hide;
end;

{-----------------------------------------------------------------------------}

end.
