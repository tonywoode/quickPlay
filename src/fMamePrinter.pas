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
    Label2: TLabel;
    MamePrintDescLabel1: TLabel;
    MameXMLLinkLabel: TLabel;
    GrpSubfolder: TGroupBox;
    GrpFilter: TGroupBox;
    ChkBios: TCheckBox;
    ChkCasino: TCheckBox;
    ChkClones: TCheckBox;
    ChkMature: TCheckBox;
    ChkMechanical: TCheckBox;
    ChkMess: TCheckBox;
    ChkPreliminary: TCheckBox;
    ChkPrintClub: TCheckBox;
    ChkSimulator: TCheckBox;
    ChkTableTop: TCheckBox;
    ChkQuiz: TCheckBox;
    ChkUtilities: TCheckBox;
    ChkCompanySplit: TCheckBox;
    ChkGenreSplit: TCheckBox;
    ChkNPlayersSplit: TCheckBox;
    ChkRatingSplit: TCheckBox;
    ChkSeriesSplit: TCheckBox;
    ChkVersionSplit: TCheckBox;
    ChkYearSplit: TCheckBox;
    MamePrintDescLabel2: TLabel;
    MamePrintDescLabel3: TLabel;
    procedure MameXMLLinkLabelClick(Sender: TObject);
    procedure BtnMameExtrasDirFindClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure BtnOKClick(Sender: TObject);

  private
    { Private declarations }
  public
    { Public declarations }
  end;

implementation

uses fMain, uQPConst, ShellAPI, uQPMiscTypes, ujProcesses, uSettings;

{$R *.dfm}

procedure TFrmMamePrinter.FormShow(Sender: TObject);
begin



  With MainFrm do
  begin
    EmuList.EmusToStrings(CmbMame.Items, cfMameArcade);
    CmbMame.ItemIndex := CmbMame.Items.IndexOf(Settings.MametoolMameExePath);
    TxtMameExtrasDirPath.Text :=  Settings.MameExtrasDir;
    //Path to Mame XML - why don't we query the mame executatble for the xml? because
    // retroarch MAME doesn't have this ability....
    TxtMAMEXMLFilePath.Text := Settings.MameXMLPath;
    //and here's all the checkboxes
    ChkBios.Checked          := Settings.MameOptBios;
    ChkCasino.Checked        := Settings.MameOptCasino;
    ChkClones.Checked        := Settings.MameOptClones;
    ChkMature.Checked        := Settings.MameOptMature;
    ChkMechanical.Checked    := Settings.MameOptMechanical;
    ChkMess.Checked          := Settings.MameOptMess;
    ChkPreliminary.Checked   := Settings.MameOptPreliminary;
    ChkPrintClub.Checked     := Settings.MameOptPrintClub;
    ChkSimulator.Checked     := Settings.MameOptSimulator;
    ChkTableTop.Checked      := Settings.MameOptTableTop;
    ChkQuiz.Checked          := Settings.MameOptQuiz;
    ChkUtilities.Checked     := Settings.MameOptUtilities;
    ChkCompanySplit.Checked  := Settings.MameOptCompany;
    ChkGenreSplit.Checked    := Settings.MameOptGenre;
    ChkNPlayersSplit.Checked := Settings.MameOptNPlayers;
    ChkRatingSplit.Checked   := Settings.MameOptRating;
    ChkSeriesSplit.Checked   := Settings.MameOptSeries;
    ChkVersionSplit.Checked  := Settings.MameOptVersion;
    ChkYearSplit.Checked     := Settings.MameOptYear;
  end;

end;

procedure TFrmMamePrinter.MameXMLLinkLabelClick(Sender: TObject);
begin
  ShellExecute(Handle, 'open', PChar(MameXMLLinkLabel.Caption), '', '', sw_Show);
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
  Flags : String;

begin

   if CmbMame.ItemIndex <>-1 then

        With MainFrm do
        begin
          Settings.MametoolMameExePath := CmbMame.Items.Strings[CmbMame.ItemIndex];
          Settings.MameExtrasDir := TxtMameExtrasDirPath.Text;
          Settings.MameXMLPath := TxtMAMEXMLFilePath.Text;
          //and here's all the checkbox settings
          Settings.MameOptBios        := ChkBios.Checked;
          Settings.MameOptCasino      := ChkCasino.Checked;
          Settings.MameOptClones      := ChkClones.Checked;
          Settings.MameOptMature      := ChkMature.Checked;
          Settings.MameOptMechanical  := ChkMechanical.Checked;
          Settings.MameOptMess        := ChkMess.Checked;
          Settings.MameOptPreliminary := ChkPreliminary.Checked;
          Settings.MameOptPrintClub   := ChkPrintClub.Checked;
          Settings.MameOptSimulator   := ChkSimulator.Checked;
          Settings.MameOptTableTop    := ChkTableTop.Checked;
          Settings.MameOptQuiz        := ChkQuiz.Checked;
          Settings.MameOptUtilities   := ChkUtilities.Checked;
          Settings.MameOptCompany     := ChkCompanySplit.Checked;
          Settings.MameOptGenre       := ChkGenreSplit.Checked;
          Settings.MameOptNPlayers    := ChkNPlayersSplit.Checked;
          Settings.MameOptRating      := ChkRatingSplit.Checked;
          Settings.MameOptSeries      := ChkSeriesSplit.Checked;
          Settings.MameOptVersion     := ChkVersionSplit.Checked;
          Settings.MameOptYear        := ChkYearSplit.Checked;
          Settings.SaveAllSettings();
        end;

   Executable := 'P:\QUICKPLAY\QuickPlayFrontend\devTools\testTools\EchoWhatYouSay.exe';

   //now lets compose our mametool flags. we need to know what romdata directory the user is sitting in
   if (MainFrm.RomList.Count > 0) then
     if (MessageDlg(QP_MAMEOPT_ROMS_EXIST_IN_SRC_DIR, mtInformation, [mbYes, mbNo], 0) = mrYes) then
   begin
   RomdataFolder := '"' + StringReplace(MainFrm.RomList.FileName, '\ROMData.dat','', [rfIgnoreCase]) + '"';
   MameExecutablePath := '"' + MainFrm.Settings.MametoolMameExePath + '"';
   MameExtrasDir := '"' + MainFrm.Settings.MameExtrasDir + '"';
   MameXMLPath := '"' + MainFrm.Settings.MameXMLPath + '"';


   Flags := RomdataFolder + ' ' + MameExecutablePath + '' + MameExtrasDir + ' ' + MameXMLPath;

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

