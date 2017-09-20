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
    procedure RadSoftlistMameChoiceClick(Sender: TObject);
  private
    MameType : String;
  public
    { Public declarations }
  end;

implementation

uses fMain, uJFile, uQPConst;

{$R *.dfm}


procedure TFrmMameMessPrinter.RadSoftlistMameChoiceClick(Sender: TObject);
begin
  //if (RadSoftlistMameChoice.Checked) then MameType := 'Mame Softlists';
  //if (RadSoftlistRetroarchChoice.Checked) then MameType := 'RetroArch Softlists';
end;


procedure TFrmMameMessPrinter.BtnOKClick(Sender: TObject);
var
 currentFolder, binDir, softlistRootDirPath : String;
 Process : Boolean;

begin
  Process := True;
  if (RadSoftlistMameChoice.Checked) then MameType := 'Mame Softlists';
  if (RadSoftlistRetroarchChoice.Checked) then MameType := 'RetroArch Softlists';
 //we need to know what romdata directory the user is sitting in, and if its not empty that may
   // indicate they don't know it'll get overwritten
   if (MainFrm.RomList.Count > 0) then
     if (MessageDlg(QP_MAMEOPT_ROMS_EXIST_IN_SRC_DIR, mtInformation, [mbYes, mbNo], 0) = mrNo) then Process := False;

     if (Process = True) then
      begin
      //the romdata folde the user is in
      currentFolder := StringReplace(MainFrm.RomList.FileName, '\ROMData.dat','', [rfIgnoreCase]);
      //the bin directory (source)
      binDir := MainFrm.Settings.Paths.BinDir;
      //the softlist dirs are crudely sitting in the root of the bindir
      softlistRootDirPath := binDir + MameType;
      //we need to warn the user if the directory isn't empty (slightly less important this time)
      DirCopy( softlistRootDirPath, currentFolder, True);
      MainFrm.ActRefreshExecute(Sender);
    end;
end;

//TODO: I found this usable dircopy fn at http://www.delphigroups.info/2/7a/117984.html
// obv it needs ShellAPI to be in uses above. but then i found that john has a dir copy method in his own package
// (see it in action in uSettings
function CopyFolder(const SrcFolder
                    , DestFolder: String
                    ; iFileOp: Integer
                    ; OverWrite: Boolean
                    ; ShowDialog: Boolean): Boolean;
{
     Copies or moves ...\SrcFolder to ...\DestFolder\SrcFolder\*.*

     Example:
       Copy C:\AFolder\SubFolder and it's contents to
            C:\AnotherFolder\SubFolder
            and prompt to replace existing files.

       CopyFolder('C:\AFolder\SubFolder', 'C:\AnotherFolder', FOF_COPY, 
true);

}
var
   // declare structure
   MyFOStruct: TSHFileOpStruct;
   Src,
   Dest:       String;
   ResultVal:  Integer;
begin
   result := false;

   Src := SrcFolder;
   Dest := DestFolder;

   if (Src = '') or
      ( (iFileOp <> FO_DELETE) and (Dest = '') ) or
      (CompareText(Src, Dest) = 0) then
        exit;

   if Src[Length(Src)] = '\' then
     SetLength( Src, Length(Src) -1 );
   Src := Src +#0#0;

   if (Dest <> '') and (Dest[Length(Dest)] = '\') then
     SetLength( Dest, Length(Dest) -1 );
   Dest := Dest + #0#0;

   // zero structure
   // ! Mandatory in XP
   FillChar( MyFOStruct, SizeOf(MyFOStruct), 0 );

   // Fill in structure
   with MyFOStruct do begin
     Wnd := 0;

     // specify a copy operation
     wFunc := iFileOp;
     pFrom := @Src[1];
     pTo := @Dest[1];

     // set the flags
     fFlags := FOF_ALLOWUNDO or FOF_NOCONFIRMMKDIR;

     if not OverWrite then fFlags := fFlags or FOF_RENAMEONCOLLISION;
     if not ShowDialog then fFlags := fFlags or FOF_SILENT;
   end;

   Screen.Cursor := crHourGlass;
   try
     MyFOStruct.fAnyOperationsAborted := False;
     MyFOStruct.hNameMappings := nil;
     Resultval := ShFileOperation(MyFOStruct);
     Result := (ResultVal = 0);
   finally
     Screen.Cursor := crDefault;
   end;

end;

end.
