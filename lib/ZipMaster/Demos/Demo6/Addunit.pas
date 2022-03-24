unit AddUnit;
   
{$INCLUDE ZipVers.inc}
{$IFDEF VERD6up}
{$WARN UNIT_PLATFORM OFF}
{$WARN SYMBOL_PLATFORM OFF}
{$ENDIF}

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, FileCtrl, ExtCtrls, Menus, ShlObj;

type
  TAddFile = class( TForm )
    Panel1:            TPanel;
    Panel2:            TPanel;
    Panel3:            TPanel;
    Panel4:            TPanel;
    Panel5:            TPanel;
    Panel6:            TPanel;
    Panel7:            TPanel;
    Panel8:            TPanel;
    Panel9:            TPanel;
    Bevel1:            TBevel;
    Label1:            TLabel;
    Label2:            TLabel;
    Label3:            TLabel;
    AddFileBut:        TButton;
    RemoveBut:         TButton;
    OKBut:             TButton;
    CancelBut:         TButton;
    SelectAllBut:      TButton;
    SortBut:           TButton;
    AddDirBut:         TButton;
    AddWildBttn:       TButton;
    AddWildPathBttn:   TButton;
    DirNameCB:         TCheckBox;
    RecurseCB:         TCheckBox;
    EncryptCB:         TCheckBox;
    SelectedList:      TListBox;
    WildEdit:          TEdit;
    DriveComboBox1:    TDriveComboBox;
    FileListBox1:      TFileListBox;
    DirectoryListBox1: TDirectoryListBox;

    procedure OKButClick( Sender: TObject );
    procedure CancelButClick( Sender: TObject );
    procedure AddFileButClick( Sender: TObject );
    procedure SortButClick( Sender: TObject );
    procedure RemoveButClick( Sender: TObject );
    procedure SelectAllButClick( Sender: TObject );
    procedure FormCreate( Sender: TObject );
    procedure AddDirButClick( Sender: TObject );
    procedure AddWildBttnClick( Sender: TObject );
    procedure AddWildPathBttnClick( Sender: TObject );

  public
    { Public declarations }
  end;

var
  AddFile: TAddFile;
  InMouseClick: Boolean;

implementation

uses main;

{$R *.DFM}

procedure TAddFile.OKButClick( Sender: TObject );
begin
   Main.Canceled := False;
   Close;
end;

procedure TAddFile.CancelButClick( Sender: TObject );
begin
  Main.Canceled := True;
  Close;
end;

procedure TAddFile.SortButClick( Sender: TObject );
begin
  SelectedList.Sorted := True;
  SortBut.Enabled := False;  { list will remain sorted }
end;

procedure TAddFile.RemoveButClick( Sender: TObject );
var
   i: Integer;
begin
   for i := SelectedList.Items.Count - 1 downto 0 do
   begin
      if SelectedList.Selected[i] then
         SelectedList.Items.Delete(i);
   end;
end;

procedure TAddFile.SelectAllButClick( Sender: TObject );
var
   i: Integer;
begin
   for i := 0 to FileListBox1.Items.Count - 1 do
      FileListBox1.Selected[i] := True;
end;

procedure TAddFile.FormCreate( Sender: TObject );
var
   SpecFolder: String;
begin
   SpecFolder := '';

   MainForm.GetSpecialFolder( CSIDL_DESKTOPDIRECTORY, SpecFolder );
   DriveComboBox1.Drive := ExtractFileDrive( SpecFolder )[1];
   DirectoryListBox1.Directory := ExtractFilePath( SpecFolder );
   InMouseClick := False;
end;

procedure TAddFile.AddDirButClick( Sender: TObject );
var
   i:        Integer;
   FullName: String;
begin
   Main.Canceled := True;  // default
   for i := 0 to DirectoryListBox1.Items.Count - 1 do
   begin
      if DirectoryListBox1.Selected[i] then
      begin
         // Add this file if it isn't already in listbox
         FullName := Mainform.ZipMaster1.AppendSlash( DirectoryListBox1.Directory ) + '*.*';

         if SelectedList.Items.IndexOf( FullName ) < 0 then
            SelectedList.Items.Add( FullName );
      { Never de-select dirnames from the DirectoryList! }
      {  DirectoryListBox1.Selected[i]:=False; }
      end;
   end;
   { Position the "SelectedList" listbox at the bottom }
   with SelectedList do
   begin
      Selected[Items.Count - 1] := True;
      Selected[Items.Count - 1] := False;
   end;
end;

procedure TAddFile.AddFileButClick( Sender: TObject );
var
   i:        Integer;
   FullName: String;
begin
   Main.Canceled := True;  // default
   for i := 0 to FileListBox1.Items.Count - 1 do
   begin
      if FileListBox1.Selected[i] then
      begin
         // Add this file if it isn't already in listbox
         FullName := Mainform.ZipMaster1.AppendSlash( DirectoryListBox1.Directory ) + FileListBox1.Items[i];
         if SelectedList.Items.IndexOf( FullName ) < 0 then
            SelectedList.Items.Add( FullName );
         FileListBox1.Selected[i] := False;
      end;
   end;
   { Position the "SelectedList" listbox at the bottom }
   with SelectedList do
   begin
      Selected[Items.Count - 1] := True;
      Selected[Items.Count - 1] := False;
   end;
end;

procedure TAddFile.AddWildBttnClick( Sender: TObject );
begin
   with SelectedList, SelectedList.Items do
   begin
      if (Length( WildEdit.Text ) > 0) and (IndexOf( WildEdit.Text ) < 0) then
      begin
         Add( WildEdit.Text );
         // Position the "SelectedList" listbox at the bottom.
         Selected[Count - 1] := True;
         Selected[Count - 1] := False;
      end;
   end;
end;

procedure TAddFile.AddWildPathBttnClick( Sender: TObject );
var
   FullName: String;
begin
   if Length( WildEdit.Text ) > 0 then
   begin
      FullName := MainForm.ZipMaster1.AppendSlash( DirectoryListBox1.Directory ) + WildEdit.Text;

      with SelectedList, SelectedList.Items do
      begin
         if IndexOf( FullName ) < 0 then
         begin
            Add( FullName );
            // Position the "SelectedList" listbox at the bottom.
            Selected[Count - 1] := True;
            Selected[Count - 1] := False;
         end;
      end;
   end;
end;

end.
