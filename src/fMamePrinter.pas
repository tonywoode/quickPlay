unit fMamePrinter;

interface

uses
  Windows, SysUtils, Classes, Graphics, Controls, Forms, Dialogs, StdCtrls,
  JvBrowseFolder, JvCtrls, fJWinFontForm, JvToolEdit, Mask, JvExMask;

type
  TFrmMamePrinter = class(TJWinFontForm)
    CmbMame: TComboBox;
    lblMAME: TLabel;
    BtnOK: TButton;
    BtnCancel: TButton;
    MameExtrasLabel: TLabel;
    TxtMameExtrasDirPath: TEdit;
    BtnMameExtrasDirFind: TButton;
    TxtMAMEXMLFilePath: TJvFilenameEdit;
    TxtMameFileManagerFilePath: TJvFilenameEdit;
    MameFileManagerLabel: TLabel;
    procedure BtnMameExtrasDirFindClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure BtnOKClick(Sender: TObject);

  private
    { Private declarations }
  public
    { Public declarations }
  end;

implementation

uses fMain, uQPConst, uQPMiscTypes, ujProcesses;

{$R *.dfm}

procedure TFrmMamePrinter.FormShow(Sender: TObject);
begin
  MainFrm.EmuList.EmusToStrings(CmbMame.Items, cfMameArcade);
  CmbMame.ItemIndex := CmbMame.Items.IndexOf(MainFrm.Settings.MametoolMameExePath);

  TxtMameExtrasDirPath.Text :=  MainFrm.Settings.MameExtrasDir;
  //Path to Mame XML - why don't we query the mame executatble for the xml? because
  // retroarch MAME doesn't have this ability....
  TxtMAMEXMLFilePath.Text := MainFrm.Settings.MameXMLPath;
  TxtMameFileManagerFilePath.Text := MainFrm.Settings.MameFileManagerFilePath;

end;

{-----------------------------------------------------------------------------}

procedure TFrmMamePrinter.BtnMameExtrasDirFindClick(Sender: TObject);
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

procedure TFrmMamePrinter.BtnOKClick(Sender: TObject);
var
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

  //close the form with the modal result OK
  ModalResult := MrOK;
end;

end.

