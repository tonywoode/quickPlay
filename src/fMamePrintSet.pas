unit fMamePrintSet;

interface

uses
  Windows, SysUtils, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, JvBaseDlg, JvSelectDirectory, JvBrowseFolder, Buttons,
  uRomList, JvComponent, JvExStdCtrls, JvButton, JvCtrls, ExtCtrls,
  JvComponentBase, fJWinFontForm, Mask, JvExMask, JvToolEdit;

type
  TFrmMamePrintSet = class(TJWinFontForm)
    CmbMame: TComboBox;
    lblMAME: TLabel;
    BtnOK: TButton;
    BtnCancel: TButton;
    lblDir: TLabel;
    jvBrowse: TJvBrowseForFolderDialog;
    ListDirs: TListBox;
    BtnAdd: TJvImgBtn;
    BtnDel: TJvImgBtn;
    MameExtrasLabel: TLabel;
    TxtMameExtrasDirPath: TEdit;
    BtnMameExtrasDirFind: TButton;
    TxtMAMEXMLFilePath: TJvFilenameEdit;
    TxtMameFileManagerFilePath: TJvFilenameEdit;
    MameFileManagerLabel: TLabel;
    procedure CmbMameChange(Sender: TObject);
    procedure BtnMameExtrasDirFindClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure BtnOKClick(Sender: TObject);
    procedure BtnAddClick(Sender: TObject);
    procedure BtnDelClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

implementation

uses fMain, uJUtilities, StrUtils, JCLstrings, IniFiles, uRom, uEmuList, uQPConst,
  uEmu, uQPMiscTypes, ujProcesses;

{$R *.dfm}


procedure TFrmMamePrintSet.FormShow(Sender: TObject);
var
  Ini : TMemIniFile;
  Dirs : TStringList;
  I : Integer;
begin
  MainFrm.EmuList.EmusToStrings(CmbMame.Items, cfMameArcade);
  CmbMame.ItemIndex := CmbMame.Items.IndexOf(MainFrm.Settings.MametoolMameExePath);

  Ini := TMemIniFile.Create(MainFrm.Settings.Paths.SettingsFile);
  TxtMameExtrasDirPath.Text :=  MainFrm.Settings.MameExtrasDir;
  //Path to Mame XML - why don't we query the mame executatble for the xml? because
  // retroarch MAME doesn't have this ability....
  TxtMAMEXMLFilePath.Text := MainFrm.Settings.MameXMLPath;
  TxtMameFileManagerFilePath.Text := MainFrm.Settings.MameFileManagerFilePath;


  Try

    //Load in the Directories.
    Dirs := TStringList.Create;
    try
      StrTokenToStrings(Ini.ReadString('MAMEScan', 'Dirs', ''),';', Dirs);
      For i := 0 to Dirs.Count-1 do
        ListDirs.Items.Add(Dirs.Strings[i])
    Finally
      FreeAndNil(Dirs);
    end;

  Finally
    FreeAndNil(Ini);
  end;

end;

{-----------------------------------------------------------------------------}

procedure TFrmMamePrintSet.BtnMameExtrasDirFindClick(Sender: TObject);
var
  jvBrowse: TJvBrowseForFolderDialog;
begin
  jvBrowse := TJvBrowseForFolderDialog.Create(self);

  try

   if DirectoryExists(MainFrm.Settings.MameExtrasDir) then
      jvBrowse.Directory := MainFrm.Settings.MameExtrasDir;
      if (jvBrowse.execute) and (DirectoryExists(jvBrowse.Directory)) then
        begin
         if DirectoryExists(jvBrowse.Directory + '/icons/') then
             TxtMameExtrasDirPath.Text := jvBrowse.Directory
           else
             MessageDlg(QP_MAMEOPT_BAD_DIR, mtError, [mbOK], 0);
         end;
  finally
    FreeAndNil(jvBrowse);
  end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmMamePrintSet.BtnOKClick(Sender: TObject);
var
  DirOutput : String;
  i  : Integer;
  Ini : TMemIniFile;
  Emu : TQPEmu;
  Clear : boolean;
  Executable : String;
  RomdataFolder: String;
  MameExecutablePath: String;
  MameExtrasDir: String;
  MameXMLPath: String;
  MameFileManagerFilePath: String;
  Flags : String;

begin

   if CmbMame.ItemIndex <>-1 then
        MainFrm.Settings.MametoolMameExePath := CmbMame.Items.Strings[CmbMame.ItemIndex];

        MainFrm.Settings.MameExtrasDir := TxtMameExtrasDirPath.Text;
        MainFrm.Settings.MameXMLPath := TxtMAMEXMLFilePath.Text;
        MainFrm.Settings.MameFileManagerFilePath := TxtMameFileManagerFilePath.Text;
        MainFrm.Settings.SaveAllSettings();

   Executable := 'P:\QUICKPLAY\QuickPlayFrontend\devTools\testTools\EchoWhatYouSay.exe';

   //now lets compose our mametool flags. we need to know what romdata directory the user is sitting in
   if (MainFrm.RomList.Count > 0) then
     if (MessageDlg(QP_MAMEOPT_ROMS_EXIST_IN_SRC_DIR, mtInformation, [mbYes, mbNo], 0) = mrYes) then
   begin
   RomdataFolder := '"' + StringReplace(MainFrm.RomList.FileName, '\ROMData.dat','', [rfIgnoreCase]) + '"';
   MameExecutablePath := '"' + MainFrm.Settings.MametoolMameExePath + '"';
   MameExtrasDir := '"' + MainFrm.Settings.MameExtrasDir + '"';
   MameXMLPath := '"' + MainFrm.Settings.MameXMLPath + '"';
   MameFileManagerFilePath := '"' + MainFrm.Settings.MameFileManagerFilePath + '"';


   Flags := RomdataFolder + ' ' + MameExecutablePath + '' + MameExtrasDir + ' ' + MameXMLPath + ' ' + MameFileManagerFilePath;

   RunProcess('cmd.exe /c ' + Executable + ' ' + Flags, True, '',SW_SHOWMINIMIZED);

   //hoping we got a good return code, we need to refresh at the very least the roms view, and folders sidebar
   //  why not do this in the return in main? Remember there's a subsequent cancel options if roms are empty, we'd have to capture it
   //the below causes index out of bounds but so does Refresh() from main form generally
   MainFrm.ActRefreshExecute(Sender);
    end;

 // If (CmbMame.ItemIndex = -1) or (ListDirs.Count = 0) then
 // begin
 //   MessageDlg(QP_MAMEM_BAD_DATA, mtError, [mbOK], 0);
 //   exit;
 // end;

 // Emu := MainFrm.EmuList[MainFrm.EmuList.IndexOfName(CmbMAME.Text)];

  //now we need to reload the ROMs list.
 //   MainFrm.ClearROMIcons();
 //   MainFrm.ROMlist.LoadFromFile(MainFrm.GetSelectedTxt);

  //now save the users input data.
 // Ini := TMemIniFile.Create(MainFrm.Settings.Paths.SettingsFile);
//  Try

 //   For i := 0 to ListDirs.Count-1 do
  //    If DirectoryExists(ListDirs.Items.Strings[i]) then
  //      DirOutput := DirOutput + ListDirs.Items.Strings[i] + ';';

 //   Ini.WriteString('MAMEScan', 'Dirs', DirOutput);
 //   Ini.WriteString('MAMEScan', 'MAME', CmbMAME.Text);

//    if MainFrm.Settings.AllowWrite then
 //     Ini.UpdateFile;

 // Finally
 // FreeAndNil(Ini);
 // end;

  //close the form with the modal result OK
  ModalResult := MrOK;
end;

procedure TFrmMamePrintSet.CmbMameChange(Sender: TObject);
begin

end;

{-----------------------------------------------------------------------------}

procedure TFrmMamePrintSet.BtnAddClick(Sender: TObject);
begin
  if (jvBrowse.execute) and (jvBrowse.Directory <> '') then
    ListDirs.Items.Add(jvBrowse.Directory);
end;

{-----------------------------------------------------------------------------}

procedure TFrmMamePrintSet.BtnDelClick(Sender: TObject);
begin
  ListDirs.DeleteSelected;
end;


end.

