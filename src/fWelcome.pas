unit fWelcome;

interface

uses
  Windows, SysUtils, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ComCtrls, Buttons, fJWinFontForm;

type
  TFrmWelcome = class(TJWinFontForm)
    BtnExit: TButton;
    PCWelcome: TPageControl;
    TabWelcome: TTabSheet;
    TabEmus: TTabSheet;
    lblEmus: TLabel;
    BtnNext: TButton;
    TabROMS: TTabSheet;
    lblROMs: TLabel;
    BtnEFind: TBitBtn;
    BtnEmuMan: TBitBtn;
    lblemutext: TLabel;
    lblROMText: TLabel;
    BtnMultiDir: TBitBtn;
    TabDone: TTabSheet;
    lblDone: TLabel;
    lblComplete: TLabel;
    lblbigWelcome: TLabel;
    BtnPrevious: TButton;
    lblIntro: TLabel;
    procedure BtnPreviousClick(Sender: TObject);
    procedure BtnNextClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure BtnMultiDirClick(Sender: TObject);
    procedure BtnEFindClick(Sender: TObject);
    procedure BtnEmuManClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

implementation

uses fMain, fScanRecursive, fEmuFind, fEmulators, uEmuUtils;

{$R *.dfm}

{-----------------------------------------------------------------------------}

procedure TFrmWelcome.BtnPreviousClick(Sender: TObject);
begin
  PCWelcome.ActivePage := PCWelcome.FindNextPage(PCWelcome.ActivePage, false, false);
  BtnPrevious.Enabled := (PCWelcome.ActivePage <> TabWelcome);
  BtnNext.Enabled := (PCWelcome.ActivePage <> TabDone);
end;

{-----------------------------------------------------------------------------}

procedure TFrmWelcome.BtnNextClick(Sender: TObject);
begin
  PCWelcome.ActivePage := PCWelcome.FindNextPage(PCWelcome.ActivePage, true, false);
  BtnPrevious.Enabled := (PCWelcome.ActivePage <> TabWelcome);
  BtnNext.Enabled := (PCWelcome.ActivePage <> TabDone);
end;

{-----------------------------------------------------------------------------}

procedure TFrmWelcome.FormCreate(Sender: TObject);
var
  I : Integer;
begin
  For i := 0 to PCWelcome.PageCount-1 do
    PCWelcome.Pages[i].TabVisible := False;

  PCWelcome.ActivePage := TabWelcome;
end;

{-----------------------------------------------------------------------------}

procedure TFrmWelcome.BtnMultiDirClick(Sender: TObject);
var
  multi : TRecursiveFrm;
begin
  Multi := TRecursiveFrm.Create(Self);
  try

    Multi.AddToDir := MainFrm.Settings.Paths.ROMsDir;
    if Multi.ShowModal = mrOK then
      BtnNext.Click;
    
  finally
    FreeAndNil(Multi);
  end;
  
end;

{-----------------------------------------------------------------------------}

procedure TFrmWelcome.BtnEFindClick(Sender: TObject);
var
  EFind : TEmuFinder;
begin
    EFind := TEmuFinder.create(self);
    try
      If Efind.ShowModal = mrok then
        BtnNext.Click;
    finally
      FreeAndNil(Efind);
    end;
end;

{-----------------------------------------------------------------------------}

procedure TFrmWelcome.BtnEmuManClick(Sender: TObject);
var
  Emu : TFrmEmuDlg;
begin
    Emu := TFrmEmuDlg.create(self);
    try

      //put a copy of the emulist into a temporary list
      Emu.EmuCopy.Assign(MainFrm.EmuList);

      If Emu.ShowModal = mrOk then
      begin
        MainFrm.EmuList.CopyFrom(Emu.EmuCopy, MainFrm.Settings.AutoDelRoms);
        BtnNext.Click;
      end;

    finally
      FreeAndNil(Emu);
    end;
end;

{-----------------------------------------------------------------------------}

end.
