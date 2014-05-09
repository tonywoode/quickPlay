unit fMameRename;

interface

uses
  Windows, SysUtils, Classes, Controls, Forms, Dialogs,
  StdCtrls, ComCtrls, Buttons, ExtCtrls, VirtualTrees, uEmuList,
  fJWinFontForm;

type
  TDatReader = class(TJWinFontForm)
    ScanGroup: TGroupBox;
    RadSel: TRadioButton;
    RadAll: TRadioButton;
    GroupProgress: TGroupBox;
    GroupEmu: TGroupBox;
    BtnStart: TButton;
    BtnClose: TButton;
    VTmame: TVirtualStringTree;
    Label4: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    ProgTotal: TProgressBar;
    ProgCompare: TProgressBar;
    procedure BtnStartClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure VTmameGetText(Sender: TBaseVirtualTree; Node: PVirtualNode;
      Column: TColumnIndex; TextType: TVSTTextType;
      var CellText: WideString);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);

  private
    MameEmus : TQPEmuList;
    procedure RenamingStart();
  end;

implementation

uses Inifiles, FindFile, shellAPI, fMain, uJUtilities, uRomList, uEmu,
  uRomUtils, uQPConst;


{$R *.DFM}

{-----------------------------------------------------------------------------}

procedure TDatReader.BtnStartClick(Sender: TObject);
begin

  //first of all make sure that an emulator has been selected.
  if VTmame.SelectedCount = 1 then

    // call the main renaming function.
    RenamingStart()
    
  else
  begin
    MessageDlg(QP_EMU_SELECT_ONE, mtError, [mbOK], 0);
    ModalResult := MrNone;
  end;

end;

{-----------------------------------------------------------------------------}

procedure TDatReader.FormShow(Sender: TObject);
var
  i : integer;
begin

  MameEmus := TQPEmuList.Create('', False);

  If MainFrm.VTdir.FocusedNode = nil then
  begin
    radsel.enabled := false;
    radAll.checked := true;
  end
  ELSE
  begin
    radsel.enabled := true;
    radsel.checked := true;
  end;

  ProgCompare.Position := 0;
  ProgTotal.Position := 0;

  //iterate through all the emulators and find MAME ones.
  with MainFrm do
  begin
  
    for i := 0 to EmuList.Count-1 do
      if EmuList[i].IsMame then
      begin
        MameEmus.Add(TQPEmu.Create());
        MameEmus.last.Assign(EmuList[i]);
      end;

  end;

  //load the compatible emulators into the VT
  If MameEmus.Count > 0 then
    VTmame.RootNodeCount := MameEmus.Count;
end;

{-----------------------------------------------------------------------------}

procedure TDatReader.VTmameGetText(Sender: TBaseVirtualTree;
  Node: PVirtualNode; Column: TColumnIndex; TextType: TVSTTextType;
  var CellText: WideString);
begin
  Case Column of
    0: CellText := MameEmus[Node.Index].name;
    1: CellText := MameEmus[Node.Index].path;
  end;
end;


{-----------------------------------------------------------------------------}
{                              Private Routines                                }
{-----------------------------------------------------------------------------}

procedure TDatReader.RenamingStart();
var
  OldCursor : TCursor;
  IniName : String;
  tmpList : TQPROMlist;
  ini : TMemIniFile;
  i : Integer;
  ProcessList, IniCheckList : TStringList;
Begin

  // this procedure starts off the MAME game renaming code

  // first of all change the cursor - this may take a while!
  OldCursor := Screen.Cursor;
  Screen.Cursor := crHourGlass;
  try
                                                      
  //the first step is to make sure that a valid QP MAME dat file is available.

    // so get the name of the INI file if it existed
    IniName := MainFrm.Settings.Paths.CfgDir + MameEmus[VTmame.FocusedNode.Index].name + '.ini';

    //now check if this file exists
    if not FileExists(IniName) then
    begin
      try
        MameEmus[VTmame.GetFirstSelected.Index].MameCreateDataFile(MainFrm.Settings.Paths.CfgDir);
      except
        on E: EJException do MessageDlg(E.Message, mtError, [mbOK], 0);
      end;
    end;

    //by this stage we should now have a valid INI file containing names and whatever
    //time to start comparing the names of our ROMS against our INI

    // check if we are doing ALL the ROMS or the selected folder.
    // any files we are processing goes into the processlist variable.
    ProcessList := TStringList.Create;
    try

      If RadSel.Checked then
        //we are only working with the current directory
        ProcessList.Add(MainFrm.GetSelectedTxt)
      else
      begin
        //we need all the ROM files, so do a search and add them all
        uROMUtils.GetAllROMFiles(ProcessList);
      end;

      // by now we have a process list, and a valid ini file, time to run the
      // name renaming
      ini := TMemIniFile.Create(IniName);
      try

        // Bug fix: 0000036 - Ini file is actually empty and so renaming fails.
        IniCheckList := TStringList.Create;
        try
          Ini.ReadSections(IniCheckList);
          if IniCheckList.Count < 2 then //in the bug the actual emulator section existed..
          begin
            //the file is effectively blank, recreate it.
            try
              MameEmus[VTmame.GetFirstSelected.Index].MameCreateDataFile(MainFrm.Settings.Paths.CfgDir);
              //the file on disk has changed, it needs to be reloaded into the
              // in-memory copy of the ini file.
              Ini.Clear;
              IniCheckList.Clear;
              IniCheckList.LoadFromFile(IniName);
              Ini.SetStrings(IniCheckList);

            except
              on E: EJException do MessageDlg(E.Message, mtError, [mbOK], 0);
            end;


          end;
        finally
          FreeAndNil(IniCheckList);
        end;


        tmpList := TQPROMlist.Create(MainFrm.Settings.AllowWrite);

         // set up the total progress bar with the amount of files to scan
        ProgTotal.Max := ProcessList.Count;
        ProgTotal.Position := 0;

        //its time to loop through any ROMS file in the processlist
        For i := 0 to ProcessList.Count-1 do
        Begin

          // check the file exists
          If not FileExists(ProcessList.Strings[i]) then
          begin
            ProgTotal.StepIt;
            continue;
          end;

          //load the designated file into the ROMs array
          TmpList.LoadFromFile(ProcessList.Strings[i]);
          TmpList.MameCompareNames(Ini, ProgCompare);

          // we have finished comparing a file so step the overall progress
          ProgTotal.StepIt;

        end; //end of file loading FOR loop

      finally
        FreeAndNil(ini);
        FreeAndNil(TmpList);
      end;

    // we have finished with our processlist - free it.
    finally
      FreeAndNil(ProcessList);
    end;

  //now we have finished, return the cursor to normal
  finally
    Screen.Cursor := OldCursor;
  end;

End;

procedure TDatReader.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  //free up the list containing the MAME Emus
  FreeAndNil(MameEmus);
end;

end.
