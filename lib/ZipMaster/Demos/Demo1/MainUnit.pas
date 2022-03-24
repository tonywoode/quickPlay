Unit mainunit;

{$INCLUDE '..\..\ZipVers.inc'}
{$IFDEF VERD6up}
{$WARN UNIT_PLATFORM OFF}
{$WARN SYMBOL_PLATFORM OFF}
{$ENDIF}

Interface

Uses
    Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs, 
    StdCtrls, Grids, ExtCtrls, SortGrid, ZipMstr20, Menus, ShlObj, FileCtrl,
  ImgList, printers, ZipMstr;

{$IFDEF VERD2D3}                        // if not Delphi v4.xx
Type
    Int64 = Comp;                       // 64 bit integers are supported differently by Delphi 2 and 3
{$ENDIF}

Type
    TMainform = Class(TForm)
        Panel1: TPanel;
        Panel2: TPanel;
        Panel3: TPanel;
        Panel4: TPanel;
        ZipMaster1: TZipMaster;
//        StringGrid1: TSortGrid;
        OpenDialog1: TOpenDialog;
        Label1: TLabel;
        Label2: TLabel;
        Label4: TLabel;
        Bevel1: TBevel;
        Bevel2: TBevel;
        ZipFName: TLabel;
        TimeLabel: TLabel;
        FilesLabel: TLabel;
        MsgBut: TButton;
        AddBut: TButton;
        TestBut: TButton;
        CloseBut: TButton;
        DeleteBut: TButton;
        NewZipBut: TButton;
        ZipOpenBut: TButton;
        ConvertBut: TButton;
        ExtractBut: TButton;
        DeleteZipBut: TButton;
        RenameBut: TButton;
        MainMenu1: TMainMenu;
        File1: TMenuItem;
        Exit1: TMenuItem;
        Project1: TMenuItem;
        Zipcomment1: TMenuItem;
        Showlasterror1: TMenuItem;
        DLLversioninfo1: TMenuItem;
        TraceCB: TCheckBox;
        VerboseCB: TCheckBox;
        UnattendedCB: TCheckBox;
        ImageList1: TImageList;

        Procedure ZipOpenButClick(Sender: TObject);
        Procedure CloseButClick(Sender: TObject);
        Procedure NewZipButClick(Sender: TObject);
        Procedure DeleteZipButClick(Sender: TObject);
        Procedure ExtractButClick(Sender: TObject);
        Procedure ZipMaster1DirUpdate(Sender: TObject);
        Procedure FormCreate(Sender: TObject);
        Procedure FillGrid;
        Procedure AddButClick(Sender: TObject);
        Procedure ZipMaster1Message(Sender: TObject; ErrCode: Integer; Message: String);
        Procedure ZipMaster1Progress(Sender: TObject; ProgrType: ProgressType; FileName: String; FileSize: Int64);//{Integer);//}Cardinal);
        Procedure DeleteButClick(Sender: TObject);
        Procedure FormDestroy(Sender: TObject);
        Procedure TestButClick(Sender: TObject);
        Procedure MsgButClick(Sender: TObject);
        Procedure ConvertButClick(Sender: TObject);
        Procedure FormResize(Sender: TObject);
        Procedure VerboseCBClick(Sender: TObject);
        Procedure TraceCBClick(Sender: TObject);
        Procedure DLLversioninfo1Click(Sender: TObject);
        Procedure Zipcomment1Click(Sender: TObject);
        Procedure Showlasterror1Click(Sender: TObject);
        Procedure Exit1Click(Sender: TObject);
        Procedure UnattendedCBClick(Sender: TObject);
        Procedure StringGrid1GetCellFormat(Sender: TObject; Col, Row: LongInt; State: TGridDrawState; Var FormatOptions: TFormatOptions);
        Procedure StringGrid1EndSort(Sender: TObject; Col: LongInt);
        Procedure RenameButClick(Sender: TObject);
        Procedure ZipMaster1SetNewName(Sender: TObject;
            Var OldFileName: String; Var IsChanged: Boolean);
		procedure ZipMaster1Tick(Sender: TObject);

    PUBLIC
        { Public declarations } 
        StringGrid1: TSortGrid;
        DoIt: Boolean;
        TotUncomp, TotComp: Cardinal;
        TotalSize1, TotalProgress1, TotalSize2, TotalProgress2: Int64;

        Function ShowLTime(s, f: Longint): String;
        Procedure SetZipFName(aCaption: String; AssignName: Boolean);
        Function GetSpecialFolder(aFolder: Integer; Var Location: String): LongWord;
        Procedure SetZipTotals;
        Function AskDirDialog(Const FormHandle: HWND; Var DirPath: String): Boolean;
    PROTECTED
        FNewCount: integer;
    End;

Var
    Mainform: TMainform;
    ExtractDir: String;
    ExpandDirs: Boolean;
    OverWr: Boolean;
    AllFiles: Boolean;
    Canceled: Boolean;

Implementation

Uses extrunit, msgunit, addunit, sfxunit, renunit;

{$R *.DFM}
{$R ZipDemo1.Manifest.res ZipDemo1.Manifest.rc}

Procedure TMainform.FormCreate(Sender: TObject);
Begin
    StringGrid1 := TSortGrid.Create(Self);
    StringGrid1.Parent := Self;
    With StringGrid1 Do
    Begin    
      Left := 0;
      Top := 125;
      Width := 612;
      Height := 247;
      Align := alClient;
      ColCount := 6;
      DefaultRowHeight := 22;
      FixedCols := 0;
      RowCount := 8;
      Font.Charset := DEFAULT_CHARSET;
      Font.Color := clBlack;
      Font.Height := -12;
      Font.Name := 'Arial';
      Font.Style := [];
      Options := [goFixedVertLine, goFixedHorzLine, goHorzLine, goRangeSelect, goColSizing, goRowSelect, goThumbTracking];
      ColWidths[0] := 178;
      ColWidths[1] := 91;
      ColWidths[2] := 105;
      ColWidths[3] := 108;
      ColWidths[4] := 53;
      ColWidths[5] := 251;
      ParentFont := False;
      TabOrder := 1;
      CaseSensitive := False;
      AlignmentHorz := taLeftJustify;
      AlignmentVert := taTopJustify;
      ProportionalScrollBars := True;
      ExtendedKeys := False;
      SortSymbol := sgGlyph;
      SortColumn := 0;
      SortOnClick := True;
      FooterRows := 1;
      FooterFont.Charset := DEFAULT_CHARSET;
      FooterFont.Color := clWindowText;
      FooterFont.Height := -11;
      FooterFont.Name := 'MS Sans Serif';
      FooterFont.Style := [fsBold];
      PrintOptions.Orientation := poPortrait;
      PrintOptions.PageTitleMargin := 0;
      PrintOptions.PageFooter := 'date|time|page';
      PrintOptions.HeaderSize := 10;
      PrintOptions.FooterSize := 7;
      PrintOptions.DateFormat := 'd-mmm-yyyy';
      PrintOptions.TimeFormat := 'h:nn';
      PrintOptions.FromRow := 0;
      PrintOptions.ToRow := 0;
      PrintOptions.BorderStyle := bsNone;
      PrintOptions.MarginBottom := 0;
      PrintOptions.MarginLeft := 0;
      PrintOptions.MarginTop := 0;
      PrintOptions.MarginRight := 0;
      WordWrap := False;
      OnGetCellFormat := StringGrid1GetCellFormat;
      OnEndSort := StringGrid1EndSort;

      { Make sure "goColMoving" is false in object inspector. This lets the
        TSortGrid use Mouse Clicks on the col headers. }
      RowCount := 2;                  { first row is fixed, and used for column headers }
      Cells[0, 0] := 'File Name';
      Cells[1, 0] := 'Compr. Size';
      Cells[2, 0] := 'Uncmpr. Size';
      Cells[3, 0] := 'Date/Time';
      Cells[4, 0] := 'Ratio';
      Cells[5, 0] := 'Path';
    End;
    ZipMaster1.Dll_Load := true;
//    ZipMaster1.Load_Zip_Dll;
//    ZipMaster1.Load_Unz_Dll;
    { If we had args on the cmd line, then try to open the first one
      as a zip/exe file.  This is most useful in case user has an association
      to ".zip" that causes this program to run when user dble clicks on a zip
      file in Explorer. }
    If ParamCount > 0 Then
        ZipMaster1.ZipFilename := ParamStr(1);
End;

Procedure TMainform.FormResize(Sender: TObject);
Begin
    If Width - 291 > 0 Then
        ZipFName.Width := Width - 291
    Else
        ZipFName.Width := 0;
    SetZipFName(ZipMaster1.ZipFilename, False);
End;

Procedure TMainform.CloseButClick(Sender: TObject);
Begin
    Close;
End;

Procedure TMainform.FormDestroy(Sender: TObject);
Begin
  ZipMaster1.Dll_Load := false;
//    ZipMaster1.Unload_Zip_Dll;
//    ZipMaster1.Unload_Unz_Dll;
End;

Procedure TMainform.ZipOpenButClick(Sender: TObject);
Var
    FirstDir: String;
Begin
    If FirstDir = '' Then
        GetSpecialFolder(CSIDL_DESKTOPDIRECTORY, FirstDir);
    With OpenDialog1 Do
    Begin
        InitialDir := FirstDir;
        Title := 'Open Existing ZIP File';
        Filter := 'ZIP Files (*.ZIP, *.EXE)|*.zip;*.exe';
        FileName := '';
        Options := Options + [ofHideReadOnly, ofShareAware, ofPathMustExist, ofFileMustExist];
        If Execute Then
        Begin
            FirstDir := ExtractFilePath(FileName);
            { Set the caption after assigning the filename. This
              way, the filename will be null if the open failed. }
            SetZipFName(FileName, True);
        End;
    End;
End;

Procedure TMainform.NewZipButClick(Sender: TObject);
Var
    ans: Boolean;
    FirstDir: String;
Begin
    If FirstDir = '' Then
        GetSpecialFolder(CSIDL_DESKTOPDIRECTORY, FirstDir);
    With OpenDialog1 Do
    Begin
        InitialDir := FirstDir;
        FileName := '';
        Filter := 'ZIP Files (*.ZIP)|*.zip';
        DefaultExt := 'Zip';
        Title := 'Create New ZIP File';
        Options := Options + [ofHideReadOnly, ofShareAware];
        Options := Options - [ofPathMustExist, ofFileMustExist];
        If Execute Then
        Begin
            FirstDir := ExtractFilePath(FileName);
            If FileExists(FileName) Then
            Begin
                Ans := MessageDlg('Overwrite Existing File: ' + FileName + '?',
                    mtConfirmation, [mbYes, mbNo], 0) = mrYes;
                If Ans Then
                    DeleteFile(FileName)
                Else
                    Exit;               { Don't use the new name }
            End;
            SetZipFName(FileName, True);
        End;
    End;
End;

Procedure TMainform.DeleteZipButClick(Sender: TObject);
Var
    ans: Boolean;
Begin
    If FileExists(ZipMaster1.ZipFilename) Then
    Begin
        Ans := MessageDlg('Are you sure you want to delete: ' + ZipMaster1.ZipFilename
            + '?', mtConfirmation, [mbYes, mbNo], 0) = mrYes;
        If Ans Then
        Begin
            DeleteFile(ZipMaster1.ZipFilename);
            SetZipFName('', True);
        End
        Else
            Exit;                       { Don't use the new name }
    End
    Else
        ShowMessage('Zip file not found: ' + ZipMaster1.ZipFilename);
End;

Procedure TMainform.ExtractButClick(Sender: TObject);
Var
    i: Integer;
    s, f, SelRow: Longint;
    IsOne: String;
Begin
    If Not FileExists(ZipMaster1.ZipFilename) Then
    Begin
        ShowMessage('Error: file not found: ' + ZipMaster1.ZipFilename);
        Exit;
    End;
    Extract.ShowModal;
    If (ExtractDir = '') Or Canceled Then
        Exit;

    With StringGrid1 Do
    Begin
        If ZipMaster1.Count < 1 Then
        Begin
            ShowMessage('Error - no files to extract');
            Exit;
        End;
        ZipMaster1.FSpecArgs.Clear;
        { Get fspecs of selected files, unless user wants all files extracted }
        If Not AllFiles Then
        Begin
            For i := 1 To SelectedCount Do
            Begin
                SelRow := SelectedItems[i];
                If (SelRow > 0) And (SelRow <> RowCount - 1) Then
                    ZipMaster1.FSpecArgs.Add(Cells[5, SelRow] + Cells[0, SelRow]);
            End;
            If ZipMaster1.FSpecArgs.Count < 1 Then
            Begin
                ShowMessage('Error - no files selected');
                Exit;
            End;
        End;
    End;                                { end with }

    MsgForm.RichEdit1.Clear;
    MsgForm.Show;
    { Put this message into the message form's memo }
    ZipMaster1Message(self, 0, 'Beginning Extract from ' + ZipMaster1.ZipFilename);

    With ZipMaster1 Do
    Begin
        ExtrBaseDir := ExtractDir;
        ExtrOptions := [];
        If ExpandDirs Then
            ExtrOptions := ExtrOptions + [ExtrDirNames];
        If Overwr Then
            ExtrOptions := ExtrOptions + [ExtrOverwrite];
        s := GetTickCount;
        Try
            Extract;
        Except
            ShowMessage('Error in Extract; Fatal DLL Exception in mainunit');
        End;
        f := GetTickCount;
        TimeLabel.Caption := ShowLTime(s, f);
        If SuccessCnt = 1 Then
            IsOne := ' was'
        Else
            IsOne := 's were';
        ShowMessage(IntToStr(SuccessCnt) + ' file' + IsOne + ' extracted');
    End;                                { end with }
End;

Procedure TMainform.AddButClick(Sender: TObject);
Var
    s, f: LongInt;
    IsOne: String;
Begin
    If ZipMaster1.ZipFileName = '' Then
    Begin
        ShowMessage('Error - open a zip file first');
        Exit;
    End;
    AddForm.Left := Left;
    AddForm.Top := Top;
    AddForm.Width := Width;
    AddForm.Height := Height;
    Canceled := False;
    AddForm.ShowModal;                  { let user pick filenames to add }
    If Canceled Then
        Exit;
    If AddForm.SelectedList.Items.Count = 0 Then
    Begin
        ShowMessage('No files selected');
        Exit;
    End;
    MsgForm.RichEdit1.Clear;
    FNewCount := 0;
    MsgForm.Show;
    { Put this message into the message form's memo }
    ZipMaster1Message(self, 0, 'Beginning Add to ' + ZipMaster1.ZipFileName);

    With ZipMaster1 Do
    Begin
        { We want any DLL error messages to show over the top
          of the message form. }
        AddOptions := [];
        Case AddForm.ZipAction Of       // Default is plain ADD.
            2: AddOptions := AddOptions + [AddUpdate]; // Update
            3: AddOptions := AddOptions + [AddFreshen]; // Freshen
            4: AddOptions := AddOptions + [AddMove]; // Move
        End;
        If AddForm.RecurseCB.Checked Then
            AddOptions := AddOptions + [AddRecurseDirs]; { we want recursion }
        If AddForm.AtribOnlyCB.Checked Then
            AddOptions := AddOptions + [AddArchiveOnly]; { we want changed only }
        If AddForm.AtribResetCB.Checked Then
            AddOptions := AddOptions + [AddResetArchive]; { we want reset }
        If AddForm.DirnameCB.Checked Then
            AddOptions := AddOptions + [AddDirNames]; { we want dirnames }
        If AddForm.DiskSpanCB.Checked Then
            AddOptions := AddOptions + [AddDiskSpan]; { we want diskspanning }
        If AddForm.EncryptCB.Checked Then
        Begin
            AddOptions := AddOptions + [AddEncrypt]; { we want a password }
            // GetAddPassword;
            // if Password = '' then
                  { The 2 password's entered by user didn't match. }
                  { We'll give him one more try; if he still messes it
                    up, the DLL itself will prompt him one final time. }
             //   GetAddPassword;
        End;
        FSpecArgs.Clear;
        FSpecArgs.Assign(AddForm.SelectedList.Items); { specify filenames }
        AddForm.SelectedList.Clear;
        s := GetTickCount;
        Try
            Add;
        Except
            ShowMessage('Error in Add; Fatal DLL Exception in mainunit');
        End;
        f := GetTickCount;
        TimeLabel.Caption := ShowLTime(s, f);
        If SuccessCnt = 1 Then
            IsOne := ' was'
        Else
            IsOne := 's were';
        ShowMessage(IntToStr(SuccessCnt) + ' file' + IsOne + ' added');
    End;                                { end with }
End;

Procedure TMainform.DeleteButClick(Sender: TObject);
Var
    i: Integer;
    Ans: Boolean;
    s, f, SelRow: LongInt;
    IsOne: String;
Begin
    With StringGrid1 Do
    Begin
        If ZipMaster1.Count < 1 Then
        Begin
            ShowMessage('Error - no files to delete');
            Exit;
        End;
        Ans := MessageDlg('Delete selected files from: ' + ZipMaster1.ZipFileName + '?',
            mtConfirmation, [mbYes, mbNo], 0) = mrYes;
        If Not Ans Then
            Exit;

        ZipMaster1.FSpecArgs.Clear;
        For i := 1 To SelectedCount Do
        Begin
            SelRow := SelectedItems[i];
            If (SelRow > 0) And (SelRow <> RowCount - 1) Then
                ZipMaster1.FSpecArgs.Add(Cells[5, SelRow] + Cells[0, SelRow]);
        End;

        If ZipMaster1.FSpecArgs.Count < 1 Then
        Begin
            ShowMessage('Error - no files selected');
            Exit;
        End;
    End;                                { end with }

    MsgForm.RichEdit1.Clear;
    MsgForm.Show;
    { Put this message into the message form's memo }
    ZipMaster1Message(self, 0, 'Beginning delete from ' + ZipMaster1.ZipFileName);

    s := GetTickCount;
    Try
        ZipMaster1.Delete;
    Except
        ShowMessage('Fatal error trying to delete');
    End;
    f := GetTickCount;
    TimeLabel.Caption := ShowLTime(s, f);
    If ZipMaster1.SuccessCnt = 1 Then
        IsOne := ' was'
    Else
        IsOne := 's were';
    ShowMessage(IntToStr(ZipMaster1.SuccessCnt) + ' file' + IsOne + ' deleted');
End;

Procedure TMainform.TestButClick(Sender: TObject);
Var
    s, f: LongInt;
Begin
    If ZipMaster1.Count < 1 Then
    Begin
        ShowMessage('Error - nothing to Test');
        Exit;
    End;
    If Zipmaster1.Zipfilename = '' Then
        Exit;
    MsgForm.RichEdit1.Clear;
    MsgForm.Show;
    ZipMaster1Message(self, 0, 'Beginning test of ' + ZipMaster1.ZipFileName);
    With ZipMaster1 Do
    Begin
        FSpecArgs.Clear;
        ExtrOptions := ExtrOptions + [ExtrTest];
        FSpecArgs.Add('*.*');           // Test all the files in the .zip
        // IMPORTANT: In this release, you must test all files.
        s := GetTickCount;
        Extract;                        // This will really do a test
    End;
    f := GetTickCount;
    TimeLabel.Caption := ShowLTime(s, f);

    With ZipMaster1 Do
    Begin
        If SuccessCnt = DirOnlyCount + Count Then
            ShowMessage('All ' + IntToStr(DirOnlyCount + Count) + ' files tested OK')
        Else
            ShowMessage('ERROR: ' + IntToStr(DirOnlyCount + Count - SuccessCnt) +
                ' files tested as bad, or skipped!');
    End;
End;

Procedure TMainform.MsgButClick(Sender: TObject);
Begin
    MsgForm.Show;
End;

Procedure TMainform.ConvertButClick(Sender: TObject);
Var
    ConvertErr: Integer;
Begin
    If ZipMaster1.Count = 0 Then
    Begin
        ShowMessage('Error: no files in archive');
        Exit;
    End;
    { determine which conversion is to be done }
    If UpperCase(ExtractFileExt(ZipMaster1.ZipFilename)) = '.EXE' Then
    Begin
        { Convert .EXE to .ZIP }
        ConvertErr := ZipMaster1.ConvertZIP;
        If ConvertErr = 0 Then
            ShowMessage('Filename is now: ' + ZipMaster1.ZipFilename)
        Else
            ShowMessage('Error ' + IntToStr(ConvertErr) + ' occured in making .ZIP file');
    End
    Else
    Begin
        { Convert .ZIP to .EXE }
        { NOTE: If you put the ZIPSFX.BIN file into the WINDOWS
          or WINDOWS SYSTEM dir, then you don't need to set the
          SFXPath property below: }
        { ZipMaster1.SFXPath := 'c:\windows\system\zipsfx.bin'; }
        MakeSFX.ShowModal;
        If DoIt = False Then
            Exit;
        ConvertErr := ZipMaster1.ConvertSFX;
		If ConvertErr = 0 Then
			ShowMessage('Filename is now: ' + ZipMaster1.ZipFilename)
        Else
            ShowMessage('Error ' + IntToStr(ConvertErr) + ' occured in making .EXE file');
    End; 
	ZipFName.Caption := ZipMaster1.ZipFilename;
End;

Procedure TMainform.VerboseCBClick(Sender: TObject);
Begin
    ZipMaster1.Verbose := VerboseCB.Checked;
End;

Procedure TMainform.TraceCBClick(Sender: TObject);
Begin
    ZipMaster1.Trace := TraceCB.Checked;
End;

Procedure TMainform.UnattendedCBClick(Sender: TObject);
Begin
    ZipMaster1.Unattended := UnattendedCB.Checked;
End;

Procedure TMainform.Showlasterror1Click(Sender: TObject);
Begin
    If ZipMaster1.ErrCode <> 0 Then
        ShowMessage(IntToStr(ZipMaster1.ErrCode) + ' ' + ZipMaster1.Message)
    Else
        ShowMessage('No last error present');
End;

Procedure TMainform.Exit1Click(Sender: TObject);
Begin
    Close;
End;

Procedure TMainform.Zipcomment1Click(Sender: TObject);
Begin
    If ZipMaster1.ZipComment <> '' Then
    Begin
        MsgForm.RichEdit1.Clear;
        MsgForm.RichEdit1.Lines.Add(ZipMAster1.ZipComment);
        MsgForm.Show;
    End
    Else
        ShowMessage('No Zip comment in this zip file');
End;

Procedure TMainform.DLLversioninfo1Click(Sender: TObject);
Begin
    //    ShowMessage('UnZip Dll version: ' + IntToStr(ZipMaster1.UnzVers) + #10 +
    //        '  Zip Dll version: ' + IntToStr(ZipMaster1.ZipVers));
    ShowMessage(ZipMaster1.FullVersionString
        + #10 + ZipMaster1.Dll_Path);
End;

//***********************ZipMaster Event handling***************************
//---------------------------------------------------------------------------

// This is the "OnMessage" event handler

Procedure TMainform.ZipMaster1Message(Sender: TObject; ErrCode: Integer; Message: String);
Begin
    MsgForm.RichEdit1.Lines.Append(Message);
    PostMessage(MsgForm.RichEdit1.Handle, EM_SCROLLCARET, 0, 0);
    If (ErrCode > 0) And Not ZipMaster1.Unattended Then
        ShowMessage('Error Msg: ' + Message);
End;

Procedure TMainform.ZipMaster1DirUpdate(Sender: TObject);
Begin
    FillGrid;
    FilesLabel.Caption := IntToStr(ZipMaster1.Count);
    If UpperCase(ExtractFileExt(ZipMaster1.ZipFilename)) = '.EXE' Then
        ConvertBut.Caption := 'Convert to ZIP'
    Else
        ConvertBut.Caption := 'Convert to EXE';
End;

Procedure TMainform.ZipMaster1Progress(Sender: TObject; ProgrType: ProgressType; Filename: String; FileSize: Int64);//{Integer);//}Cardinal);
Var
    Step: Integer;
Begin
    Case ProgrType Of
        TotalSize2Process:
            Begin
                If Filename = '' Then
                Begin
                    MsgForm.StatusBar1.Panels.Items[0].Text := 'Total size: ' + IntToStr(FileSize Div 1024) + ' Kb';
                    MsgForm.ProgressBar2.Position := 1;
                    MsgForm.ProgressBar1.Max := 10001;
                    TotalSize2 := FileSize;
                    TotalProgress2 := 0;
                End
                Else
                Begin
                    MsgForm.FileBeingZipped.Caption := Filename;
                    MsgForm.ProgressBar1.Position := 1;
                    MsgForm.ProgressBar1.Max := FileSize;
                End;
            End;
        TotalFiles2Process:
            Begin
                // ZipMaster1Message( self, 0, 'in OnProgress type TotalFiles, files= ' + IntToStr( FileSize ) );
                If Filename = '' Then
                    MsgForm.StatusBar1.Panels.Items[1].Text := IntToStr(FileSize) + ' files';
            End;
        NewFile:
            Begin
                MsgForm.FileBeingZipped.Caption := Filename;
                MsgForm.ProgressBar1.Position := 1; // Current position of bar.
                TotalSize1 := FileSize;
                TotalProgress1 := 0;
            End;
        ProgressUpdate:
            Begin
                If Filename = '' Then
                Begin
                    // ZipMaster1Message( self, 0, 'in OnProgress type Update, size= ' + IntToStr( FileSize ) );
                    // FileSize gives now the bytes processed since the last call.
                    TotalProgress1 := TotalProgress1 + FileSize;
                    TotalProgress2 := TotalProgress2 + FileSize;
                    If TotalSize1 <> 0 Then
                    Begin
{$IFDEF VERD4+}                         // D4+   (D5 gives a compiler error when using Int64 conversion!?)
                        Step := MulDiv(TotalProgress1, 10000, TotalSize1);
{$ELSE}                                 // D2 and D3
                        Try
                            Step := Round(TotalProgress1 * 10000 / TotalSize1);
                        Except
                            Step := 2147483647;
                        End;
{$ENDIF}
                        // ZipMaster1Message( self, 0, 'Step = ' + IntToStr( Step ) );
                        MsgForm.ProgressBar1.Position := 1 + Step;
                    End
                    Else
                        MsgForm.ProgressBar1.Position := 10001;
                    If TotalSize2 <> 0 Then
                    Begin
{$IFDEF VERD4+}
                        Step := MulDiv(TotalProgress2, 10000, TotalSize2);
{$ELSE}
                        Try
                            Step := Round(TotalProgress2 * 10000 / TotalSize2);
                        Except
                            Step := 2147483647;
                        End;
{$ENDIF}
                        MsgForm.ProgressBar2.Position := 1 + Step;
                    End;
                End
                Else
                Begin                   // non file progress
                    MsgForm.ProgressBar1.Position := 1 + FileSize;
                End;
            End;
        EndOfBatch:                     // Reset the progress bar and filename.
            Begin
                // ZipMaster1Message( self, 0, 'in OnProgress type EndOfBatch' );
                MsgForm.FileBeingZipped.Caption := '';
                MsgForm.ProgressBar1.Position := 1;
                MsgForm.StatusBar1.Panels[0].Text := '';
                MsgForm.StatusBar1.Panels[1].Text := '';
                MsgForm.ProgressBar2.Position := 1;
            End;
    End;                                // EOF Case
End;

//***********************User defined functions *****************************
//---------------------------------------------------------------------------

Function TMainform.ShowLTime(s, f: Longint): String;
Var
    min, sec, {mil,} st: Integer;
    smin, ssec {,smil}: String;
Begin
    st := f - s;
    //mil := st mod 1000;
    //mil := mil mod 60;
    sec := st Div 1000;
    min := sec Div 60;
    sec := sec Mod 60;
    //if mil > 9 then smil := IntToStr( mil ) else smil := '0' + IntToStr( mil );
    If sec > 9 Then
        ssec := IntToStr(sec)
    Else
        ssec := '0' + IntToStr(sec);
    If min > 9 Then
        smin := IntToStr(min)
    Else
        smin := '0' + IntToStr(min);
    Result := smin + ':' + ssec;
End;

Procedure TMainform.SetZipFName(aCaption: String; AssignName: Boolean);
Begin
    // Assigning the filename will cause the table of contents to be read.
    // and possibly reset it to an empty string (If error found).
    If AssignName Then
        ZipMaster1.ZipFilename := aCaption;

    If ZipMaster1.ZipFilename = '' Then
        ZipFName.Caption := AnsiString('<none>')
    Else
        ZipFName.Caption := MinimizeName(ZipMaster1.ZipFilename, ZipFName.Canvas, ZipFName.Width);

    If ZipFName.Canvas.TextWidth(ZipMaster1.ZipFilename) > ZipFName.Width Then
    Begin
        ZipFName.Hint := ZipMaster1.ZipFilename;
        ZipFName.ShowHint := True;
    End
    Else
        ZipFName.ShowHint := False;
End;

//---------------------------------------------------------------------------

Procedure TMainform.SetZipTotals;
Begin
    With StringGrid1 Do
    Begin
        Cells[0, RowCount - 1] := 'Total';
        Cells[1, RowCount - 1] := IntToStr(TotComp);
        Cells[2, RowCount - 1] := IntToStr(TotUncomp);
        If TotUnComp <> 0 Then
            Cells[4, RowCount - 1] := IntToStr(Round((1 - (TotComp / TotUnComp)) * 100)) + '% '
        Else
            Cells[4, RowCount - 1] := '0 % ';
        Cells[5, RowCount - 1] := '';
    End;
End;

//---------------------------------------------------------------------------

Function TMainform.AskDirDialog(Const FormHandle: HWND; Var DirPath: String): Boolean;
Var
    pidl: PItemIDList;
    FBrowseInfo: TBrowseInfo;
    Success: Boolean;
    TitleName: String;
    Buffer: Array[0..MAX_PATH] Of Char;
Begin
    Result := False;
    ZeroMemory(@FBrowseInfo, SizeOf(FBrowseInfo));
    Try
        GetMem(FBrowseInfo.pszDisplayName, MAX_PATH);
        FBrowseInfo.hwndOwner := FormHandle;
        TitleName := 'Please specify a directory';
        FBrowseInfo.lpszTitle := PChar(TitleName);
        pidl := ShBrowseForFolder(FBrowseInfo);
        If pidl <> Nil Then
        Begin
            Success := SHGetPathFromIDList(pidl, Buffer);
            // if False then pidl not part of namespace
            If Success Then
            Begin
                DirPath := Buffer;
                If DirPath[Length(DirPath)] <> '\' Then
                    DirPath := DirPath + '\';
                Result := True;
            End;
            GlobalFreePtr(pidl);
        End;
    Finally
        If Assigned(FBrowseInfo.pszDisplayName) Then
            FreeMem(FBrowseInfo.pszDisplayName, Max_Path);
    End;
End;

//---------------------------------------------------------------------------
{* Folder types are a.o.
 *	CSIDL_DESKTOPDIRECTORY, CSIDL_STARTMENU, CSIDL_SENDTO,
 * CSIDL_PROGRAMS, CSIDL_STARTUP etc.
 *}

Function TMainform.GetSpecialFolder(aFolder: Integer; Var Location: String): LongWord;
Var
    pidl: PItemIDList;
    hRes: HRESULT;
    RealPath: Array[0..MAX_PATH] Of Char;
    Success: Boolean;
Begin
    Result := 0;
    hRes := SHGetSpecialFolderLocation(Handle, aFolder, pidl);
    If hRes = NO_ERROR Then
    Begin
        Success := SHGetPathFromIDList(pidl, RealPath);
        If Success Then
            Location := String(RealPath) + '\'
        Else
            Result := LongWord(E_UNEXPECTED);
    End
    Else
        Result := hRes;
End;

//**************************Grid functions **********************************
//---------------------------------------------------------------------------

Procedure TMainForm.FillGrid;
Const
    sorts: Array[1..6] Of TSortStyle = (ssAutomatic, ssAlphabetic, ssNumeric, ssDateTime, ssTime, ssCustom);
Var
    i: Integer;
    so: TSortOptions;
Begin
    With StringGrid1 Do
    Begin
        { remove everything from grid except col titles }
        RowCount := 2;
        Rows[1].Clear;
        If ZipMaster1.Count = 0 Then
            Exit;

        StringGrid1.RowCount := ZipMaster1.Count + 2;
        TotUnComp := 0;
        TotComp := 0;
        For i := 1 To ZipMaster1.Count Do
        Begin
            With ZipMaster1.DirEntry[i - 1]^ Do
            Begin
                Cells[0, i] := ExtractFileName(FileName);
                Cells[1, i] := IntToStr(CompressedSize);
                Cells[2, i] := IntToStr(UncompressedSize);
                Cells[3, i] := FormatDateTime('ddddd  t', FileDateToDateTime(DateTime));
                If UncompressedSize <> 0 Then
                    Cells[4, i] := IntToStr(Round((1 - (CompressedSize / UnCompressedSize)) * 100)) + '% '
                Else
                    Cells[4, i] := '0% ';
                Cells[5, i] := ExtractFilePath(FileName);
                TotUncomp := TotUnComp + Cardinal(UncompressedSize);
                Inc(TotComp, CompressedSize);
            End;                        // end with
        End;                            // end for

        so.SortDirection := sdAscending;
        so.SortStyle := {sorts[SortColumn]; //} ssAutomatic;
        so.SortCaseSensitive := False;
        SortByColumn(SortColumn, so);
        Row := 1;
    End;                                // end with
End;

Procedure TMainform.StringGrid1EndSort(Sender: TObject; Col: LongInt);
Begin
    SetZipTotals;
End;

Procedure TMainform.StringGrid1GetCellFormat(Sender: TObject; Col, Row: LongInt; State: TGridDrawState; Var FormatOptions: TFormatOptions);
Begin
    If (Row <> 0) And (Col <> 0) And (Col <> 5) Then
        FormatOptions.AlignmentHorz := taRightJustify;
End;

Procedure TMainform.RenameButClick(Sender: TObject);
Begin
    RenForm.Show();
End;

// 1.72 show some activity

Procedure TMainform.ZipMaster1SetNewName(Sender: TObject;
    Var OldFileName: String; Var IsChanged: Boolean);
Begin
    FNewCount := succ(FNewCount) And 63;
    MsgForm.StatusBar1.Panels[0].Text := IntToStr(FNewCount);
End;

// 1.72 show some activity

procedure TMainform.ZipMaster1Tick(Sender: TObject);
Begin
	FNewCount := succ(FNewCount);
	if (fNewCount and 7) = 0 then
	begin
		fNewCount := fNewCount and 127;
		MsgForm.StatusBar1.Panels[0].Text := IntToStr(FNewCount);
	end;
End;

End.

