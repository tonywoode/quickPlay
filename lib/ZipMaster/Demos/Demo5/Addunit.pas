unit Addunit;
 
{$INCLUDE ZipVers.inc}
{$IFDEF VERD6up}
{$WARN UNIT_PLATFORM OFF}
{$WARN SYMBOL_PLATFORM OFF}
{$ENDIF}

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, FileCtrl, ExtCtrls;

type
  TAddForm = class( TForm )
    Panel1:            TPanel;
    Panel2:            TPanel;
    Panel3:            TPanel;
    Panel4:            TPanel;
    Panel5:            TPanel;
    Panel6:            TPanel;
    Panel7:            TPanel;
    Panel8:            TPanel;
    Label1:            TLabel;
    OKBut:             TButton;
    SortBut:           TButton;
    AddDirBut:         TButton;
    RemoveBut:         TButton;
    CancelBut:         TButton;
    AddFileBut:        TButton;
    SelectedList:      TListBox;
    SelectAllBut:      TButton;
    FileListBox1:      TFileListBox;
    DriveComboBox1:    TDriveComboBox;
    DirectoryListBox1: TDirectoryListBox;

    procedure OKButClick( Sender: TObject );
    procedure CancelButClick( Sender: TObject );
    procedure AddFileButClick( Sender: TObject );
    procedure SortButClick( Sender: TObject );
    procedure RemoveButClick( Sender: TObject );
    procedure SelectAllButClick( Sender: TObject );
    procedure FormCreate( Sender: TObject );
    procedure AddDirButClick( Sender: TObject );
    function  AppendSlash( const sDir : String ): String;
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  AddForm: TAddForm;
  InMouseClick: Boolean;

implementation

uses mainunit;

{$R *.DFM}

procedure TAddForm.OKButClick( Sender: TObject );
begin
   MainUnit.Cancelled := False;
   Close;
end;

procedure TAddForm.CancelButClick( Sender: TObject );
begin
  MainUnit.Cancelled := True;
  Close;
end;

procedure TAddForm.SortButClick( Sender: TObject );
begin
  SelectedList.Sorted := True;
  SortBut.Enabled     := False;  { list will remain sorted }
end;

procedure TAddForm.RemoveButClick( Sender: TObject );
var
   i: Integer;
begin
   for i := SelectedList.Items.Count - 1 downto 0 do
   begin
      if SelectedList.Selected[i] then
         SelectedList.Items.Delete( i );
   end;
end;

procedure TAddForm.SelectAllButClick( Sender: TObject );
var
   i: Integer;
begin
   for i := 0 to FileListBox1.Items.Count - 1 do
      FileListBox1.Selected[i] := True;
end;

function TAddForm.AppendSlash( const sDir: String ): String;
begin
  Result := sDir;
  if (Length( sDir ) > 0) and (sDir[Length( sDir )] <> '\') then
     Result := Result + '\';
end;

procedure TAddForm.FormCreate( Sender: TObject );
begin
   InMouseClick := False;
end;

procedure TAddForm.AddDirButClick( Sender: TObject );
var
   i:        Integer;
   FullName: String;
begin
   MainUnit.Cancelled := True;  // default
   for i := 0 to DirectoryListBox1.Items.Count - 1 do
   begin
      if DirectoryListBox1.Selected[i] then
      begin
         // Add this file if it isn't already in listbox
         FullName := AppendSlash( DirectoryListBox1.Directory ) + '*.*';

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

procedure TAddForm.AddFileButClick( Sender: TObject );
var
   i:        Integer;
   FullName: String;
begin
   MainUnit.Cancelled := True;  // default
   for i := 0 to FileListBox1.Items.Count - 1 do
   begin
      if FileListBox1.Selected[i] then
      begin
         // Add this file if it isn't already in listbox
         FullName := AppendSlash( DirectoryListBox1.Directory ) + FileListBox1.Items[i];
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

end.
