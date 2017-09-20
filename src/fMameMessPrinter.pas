unit fMameMessPrinter;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ShellAPI;

type
  TFrmMameMessPrinter = class(TForm)
    RadSoftlistMameChoice: TRadioButton;
    RadSoftlistRetroarchChoice: TRadioButton;
    BtnOK: TButton;
    BtnCancel: TButton;
    MameMessPrinterDescLabel1: TLabel;
    MameSoftlistChoiceLabel: TLabel;
    MameMessPrinterDescLabel2: TLabel;
    procedure BtnOKClick(Sender: TObject);
  private
    MameType : String;
  public
    { Public declarations }
  end;

implementation

uses fMain, uJFile, uQPConst;

{$R *.dfm}

procedure TFrmMameMessPrinter.BtnOKClick(Sender: TObject);
var
 RomdataFolder, binDir, softlistRootDirPath : String;
 Process: Boolean;

begin
  Process := True;
  if (RadSoftlistMameChoice.Checked) then MameType := 'Mame Softlists';
  if (RadSoftlistRetroarchChoice.Checked) then MameType := 'RetroArch Softlists';


  //for the other Mame Printers, we check whether the folder the user chose was empty
  // but the root of the romdatas is a folder not a romdata.dat, so it won't overwrite anything but an existing set
  //instead, if the selected dir is one in from the root, check the user wants this in root (which is likely)
  if (MainFrm.VTDir.GetNodeLevel(MainFrm.VTDir.FocusedNode) = 0) and
    (MessageDlg(QP_MAINFRM_NEWFOL, mtConfirmation, [mbYes, mbNo], 0) = mrYes) then
    RomdataFolder := MainFrm.Settings.Paths.ROMsDir
  else
    RomdataFolder := MainFrm.GetSelectedFolder;
  //todo: if user cancels out of that dialog at this point, they're going to get the copy into the selected roms folder

  //if the folder exists, check that's the intention
  //take a bit of care here as the logic that follows expects these names to be folder names of SUBFOLDERS in the src, so
  //bot src and dest folders must be the same name
  if (DirectoryExists(RomdataFolder + MameType)) and
      (MessageDlg(QP_MAME_SOFTLISTS_EXIST_IN_SRC_DIR, mtConfirmation, [mbYes, mbNo], 0) = mrNo) then Process := False;

  //check that Dir is actually equal to something!
  if RomdataFolder = '' then Process := False;

  if (Process = True) then
  begin
      //the bin directory (source)
      binDir := MainFrm.Settings.Paths.BinDir;
      //the softlist dirs are crudely sitting in the root of the bindir
      softlistRootDirPath := binDir + MameType;
      //we need to warn the user if the directory isn't empty (slightly less important this time)
      DirCopy( softlistRootDirPath, RomdataFolder, True);
      MainFrm.ActRefreshExecute(Sender);
    end;
    //close the form with the modal result OK
    ModalResult := MrOK;
end;

end.
