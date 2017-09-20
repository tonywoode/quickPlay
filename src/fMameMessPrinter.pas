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
    procedure RadSoftlistMameChoiceClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  FrmMameMessPrinter: TFrmMameMessPrinter;

implementation

{$R *.dfm}

procedure TFrmMameMessPrinter.RadSoftlistMameChoiceClick(Sender: TObject);
var
  MameType : String;

begin
  if (RadSoftlistMameChoice.Checked) then MameType := 'mame';
  if (RadSoftlistRetroarchChoice.Checked) then MameType := 'retroarch';

  //we'll be needing the currently selected romdata folder

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
