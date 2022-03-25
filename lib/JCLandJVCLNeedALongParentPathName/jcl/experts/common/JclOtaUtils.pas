{**************************************************************************************************}
{                                                                                                  }
{ Project JEDI Code Library (JCL)                                                                  }
{                                                                                                  }
{ The contents of this file are subject to the Mozilla Public License Version 1.1 (the "License"); }
{ you may not use this file except in compliance with the License. You may obtain a copy of the    }
{ License at http://www.mozilla.org/MPL/                                                           }
{                                                                                                  }
{ Software distributed under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF   }
{ ANY KIND, either express or implied. See the License for the specific language governing rights  }
{ and limitations under the License.                                                               }
{                                                                                                  }
{ The Original Code is JclOtaUtils.pas.                                                            }
{                                                                                                  }
{ The Initial Developer of the Original Code is Petr Vones.                                        }
{ Portions created by Petr Vones are Copyright (C) of Petr Vones.                                  }
{                                                                                                  }
{ Contributors:                                                                                    }
{   Florent Ouchet (outchy)                                                                        }
{                                                                                                  }
{**************************************************************************************************}
{                                                                                                  }
{ Last modified: $Date:: 2009-10-16 19:11:39 +0200 (ven., 16 oct. 2009)                          $ }
{ Revision:      $Rev:: 3044                                                                     $ }
{ Author:        $Author:: outchy                                                                $ }
{                                                                                                  }
{**************************************************************************************************}
unit JclOtaUtils;

interface

{$I jcl.inc}
{$I crossplatform.inc}

uses
  SysUtils, Classes, Windows,
  Controls, ComCtrls, ActnList, Menus,
  {$IFNDEF COMPILER8_UP}
  Idemenuaction, // dependency walker reports a class TPopupAction in
  // unit Idemenuaction in designide.bpl used by the IDE to display tool buttons
  // with a drop down menu, this class seems to have the same interface
  // as TControlAction defined in Controls.pas for newer versions of Delphi
  {$ENDIF COMPILER8_UP}
  JclBase,
  {$IFDEF UNITVERSIONING}
  JclUnitVersioning,
  {$ENDIF UNITVERSIONING}
  {$IFDEF MSWINDOWS}
  JclDebug,
  {$ENDIF MSWINDOWS}
  JclBorlandTools,
  ToolsAPI;

type
  // class of actions with a drop down menu on tool bars
  {$IFDEF COMPILER8_UP}
  TDropDownAction = TControlAction;
  {$ELSE COMPILER8_UP}
  TDropDownAction = TPopupAction;
  {$ENDIF COMPILER8_UP}

// note to developers
// to avoid JCL exceptions to be reported as Borland's exceptions in automatic
// bug reports, all entry points should be protected with this code model:
// uses
//   JclOtaUtils;
// try
//   <code to execute here>
// except
//   on ExceptionObj: TObject do
//   begin
//     JclExpertShowExceptionDialog(ExceptionObj);
//   end;
// end;
// entry points for experts are usually:
//  - initialization sections
//  - finalization sections
//  - Register procedures
//  - expert entry point
//  - Action update events
//  - Action execute events
//  - notifier callback functions
//  - ... (non exhaustive list)

  EJclExpertException = class (Exception)
  {$IFDEF MSWINDOWS}
  private
    FStackInfo: TJclStackInfoList;
  public
    destructor Destroy; override;
    procedure AfterConstruction; override;
    property StackInfo: TJclStackInfoList read FStackInfo;
  {$ENDIF MSWINDOWS}
  end;

  TJclOTASettings = class (TObject)
  private
    FKeyName: string;
    FBaseKeyName: string;
  public
    constructor Create(ExpertName: string);
    function LoadBool(Name: string; Def: Boolean): Boolean;
    function LoadString(Name: string; Def: string): string;
    function LoadInteger(Name: string; Def: Integer): Integer;
    procedure LoadStrings(Name: string; List: TStrings);
    procedure SaveBool(Name: string; Value: Boolean);
    procedure SaveString(Name: string; Value: string);
    procedure SaveInteger(Name: string; Value: Integer);
    procedure SaveStrings(Name: string; List: TStrings);
    property KeyName: string read FKeyName;
    property BaseKeyName: string read FBaseKeyName;
  end;

  // Note: we MUST use an interface as the type of the Expert parameter
  // and not an object to avoid a bug in C++ Builder 5 compiler. If we 
  // used an object, the compiler would crash or give internal error GH4148
  // being obviously lost trying to resolve almost circular references 
  // between this unit and the JclOtaConfigurationForm unit.
  IJclOTAOptionsCallback = interface;

  TJclOTAAddPageFunc = procedure (AControl: TControl; PageName: string;
    Expert: IJclOTAOptionsCallback) of object;

  IJclOTAOptionsCallback = interface
    procedure AddConfigurationPages(AddPageFunc: TJclOTAAddPageFunc);
    procedure ConfigurationClosed(AControl: TControl; SaveChanges: Boolean);
  end;

  TJclOTAExpertBase = class(TInterfacedObject, IJclOTAOptionsCallback)
  private
    FEnvVariables: TStringList;
    FRootDir: string;
    FSettings: TJclOTASettings;
    function GetModuleHInstance: Cardinal;
    function GetRootDir: string;
    procedure ReadEnvVariables;
    procedure ConfigurationActionUpdate(Sender: TObject);
    procedure ConfigurationActionExecute(Sender: TObject);
    function GetActivePersonality: TJclBorPersonality;
    function GetDesigner: string;
  public
    class function GetNTAServices: INTAServices;
    class function GetOTAServices: IOTAServices;
    class function GetOTADebuggerServices: IOTADebuggerServices;
    class function GetOTAModuleServices: IOTAModuleServices;
    class function GetOTAPackageServices: IOTAPackageServices;
    {$IFDEF BDS}
    class function GetOTAPersonalityServices: IOTAPersonalityServices;
    class function GetOTAGalleryCategoryManager: IOTAGalleryCategoryManager;
    {$ENDIF BDS}
    {$IFDEF BDS4_UP}
    class function GetOTAProjectManager: IOTAProjectManager;
    {$ENDIF BDS4_UP}
    class function GetOTAMessageServices: IOTAMessageServices;
    class function GetOTAWizardServices: IOTAWizardServices;
    class function GetActiveProject: IOTAProject;
    class function GetProjectGroup: IOTAProjectGroup;
    class function IsPersonalityLoaded(const PersonalityName: string): Boolean;
    class procedure AddExpert(AExpert: TJclOTAExpertBase);
    class procedure RemoveExpert(AExpert: TJclOTAExpertBase);
    class function GetExpertCount: Integer;
    class function GetExpert(Index: Integer): TJclOTAExpertBase;
    class function ConfigurationDialog(StartName: string = ''): Boolean;
    class procedure CheckToolBarButton(AToolBar: TToolBar; AAction: TCustomAction);
    class function GetActionCount: Integer;
    class function GetAction(Index: Integer): TAction;
    class function ActionSettings: TJclOtaSettings;
  public
    constructor Create(AName: string); virtual;
    destructor Destroy; override;
    procedure AfterConstruction; override;
    procedure BeforeDestruction; override;
    
    function FindExecutableName(const MapFileName: TFileName; const OutputDirectory: string;
      var ExecutableFileName: TFileName): Boolean;
    function GetDrcFileName(const Project: IOTAProject): TFileName;
    function GetMapFileName(const Project: IOTAProject): TFileName;
    function GetOutputDirectory(const Project: IOTAProject): string;
    function IsInstalledPackage(const Project: IOTAProject): Boolean;
    function IsPackage(const Project: IOTAProject): Boolean;
    function SubstitutePath(const Path: string): string;

    { IJclOTAOptionsCallback }
    procedure AddConfigurationPages(AddPageFunc: TJclOTAAddPageFunc); virtual;
    procedure ConfigurationClosed(AControl: TControl; SaveChanges: Boolean); virtual;

    procedure RegisterCommands; virtual;
    procedure UnregisterCommands; virtual;
    procedure RegisterAction(Action: TCustomAction);
    procedure UnregisterAction(Action: TCustomAction);

    property Settings: TJclOTASettings read FSettings;
    property RootDir: string read GetRootDir;
    property ActivePersonality: TJclBorPersonality read GetActivePersonality;
    property Designer: string read GetDesigner;

    property ModuleHInstance: Cardinal read GetModuleHInstance;
  end;

  TJclOTAExpert = class(TJclOTAExpertBase, IOTAWizard, IOTANotifier)
  public
    { IOTANotifier }
    procedure AfterSave; virtual;
    procedure BeforeSave; virtual;
    procedure Destroyed; virtual;
    procedure Modified; virtual;
    { IOTAWizard }
    procedure Execute; virtual;
    function GetIDString: string; virtual;
    function GetName: string; virtual;
    function GetState: TWizardState; virtual;
  end;

  {$IFDEF BDS7_UP}
  TJclOTALocalMenu = class(TInterfacedObject, IOTANotifier, IOTALocalMenu)
  private
    FCaption: string;
    FChecked: Boolean;
    FEnabled: Boolean;
    FHelpContext: Integer;
    FName: string;
    FParent: string;
    FPosition: Integer;
    FVerb: string;
  public
    { IOTANotifier }
    procedure AfterSave;
    procedure BeforeSave;
    procedure Destroyed;
    procedure Modified;
  public
    { IOTALocalMenu }
    function GetCaption: string;
    function GetChecked: Boolean;
    function GetEnabled: Boolean;
    function GetHelpContext: Integer;
    function GetName: string;
    function GetParent: string;
    function GetPosition: Integer;
    function GetVerb: string;
    procedure SetCaption(const Value: string);
    procedure SetChecked(Value: Boolean);
    procedure SetEnabled(Value: Boolean);
    procedure SetHelpContext(Value: Integer);
    procedure SetName(const Value: string);
    procedure SetParent(const Value: string);
    procedure SetPosition(Value: Integer);
    procedure SetVerb(const Value: string);
    property Caption: string read GetCaption write SetCaption;
    property Checked: Boolean read GetChecked write SetChecked;
    property Enabled: Boolean read GetEnabled write SetEnabled;
    property HelpContext: Integer read GetHelpContext write SetHelpContext;
    property Name: string read GetName write SetName;
    property Parent: string read GetParent write SetParent;
    property Position: Integer read GetPosition write SetPosition;
    property Verb: string read GetVerb write SetVerb;
  end;

  TJclProjectManagerMenuExecuteEvent = procedure (const MenuContextList: IInterfaceList) of object;

  TJclOTAProjectManagerMenu = class(TJclOTALocalMenu, IOTANotifier, IOTALocalMenu, IOTAProjectManagerMenu)
  private
    FIsMultiSelectable: Boolean;
    FOnExecute: TJclProjectManagerMenuExecuteEvent;
  public
    { IOTAProjectManagerMenu }
    function GetIsMultiSelectable: Boolean;
    procedure SetIsMultiSelectable(Value: Boolean);
    procedure Execute(const MenuContextList: IInterfaceList); overload;
    function PreExecute(const MenuContextList: IInterfaceList): Boolean;
    function PostExecute(const MenuContextList: IInterfaceList): Boolean;
    property IsMultiSelectable: Boolean read GetIsMultiSelectable write SetIsMultiSelectable;
    property OnExecute: TJclProjectManagerMenuExecuteEvent read FOnExecute write FOnExecute;
  end;
  {$ENDIF BDS7_UP}

// procedure SaveOptions(const Options: IOTAOptions; const FileName: string);
function JclExpertShowExceptionDialog(AExceptionObj: TObject): Boolean;
{$IFDEF BDS}
function PersonalityTextToId(const PersonalityText: string): TJclBorPersonality;
{$ENDIF BDS}

{$IFDEF BDS}
procedure RegisterSplashScreen;
procedure RegisterAboutBox;
{$ENDIF BDS}

// properties are stored as "// PropID PropValue" in project file
// they have to be placed before any identifiers and after comments at the beginning of the file
function GetProjectProperties(const AProject: IOTAProject; const PropIDs: TDynAnsiStringArray): TDynAnsiStringArray;
function SetProjectProperties(const AProject: IOTAProject; const PropIDs, PropValues: TDynAnsiStringArray): Integer;

// set to true to temporary disable experts that alter compiled files after they were compiled
var
  JclDisablePostCompilationProcess: Boolean = False;

{$IFDEF UNITVERSIONING}
const
  UnitVersioning: TUnitVersionInfo = (
    RCSfile: '$URL: https://jcl.svn.sourceforge.net/svnroot/jcl/tags/JCL-2.1-Build3536/jcl/experts/common/JclOtaUtils.pas $';
    Revision: '$Revision: 3044 $';
    Date: '$Date: 2009-10-16 19:11:39 +0200 (ven., 16 oct. 2009) $';
    LogPath: 'JCL\experts\common';
    Extra: '';
    Data: nil
    );
{$ENDIF UNITVERSIONING}

implementation

uses
  {$IFDEF HAS_UNIT_VARIANTS}
  Variants,
  {$ENDIF HAS_UNIT_VARIANTS}
  Forms, Graphics, Dialogs, ActiveX,
  {$IFDEF MSWINDOWS}
  ImageHlp, JclRegistry,
  {$ENDIF MSWINDOWS}
  JclFileUtils, JclStrings, JclSysInfo, JclSimpleXml,
  JclOtaConsts, JclOtaResources, JclOtaExceptionForm, JclOtaConfigurationForm,
  JclOtaActionConfigureSheet, JclOtaUnitVersioningSheet,
  JclOtaWizardForm, JclOtaWizardFrame;

{$R 'JclImages.res'}

var
  GlobalActionList: TList = nil;
  GlobalActionSettings: TJclOtaSettings = nil;
  GlobalExpertList: TList = nil;
  ConfigurationAction: TAction = nil;
  ConfigurationMenuItem: TMenuItem = nil;
  ActionConfigureSheet: TJclOtaActionConfigureFrame = nil;
  UnitVersioningSheet: TJclOtaUnitVersioningFrame = nil;

function FindActions(const Name: string): TComponent;
var
  Index: Integer;
  TestAction: TCustomAction;
begin
  Result := nil;
  try
    if Assigned(GlobalActionList) then
      for Index := 0 to GlobalActionList.Count-1 do
      begin
        TestAction := TCustomAction(GlobalActionList.Items[Index]);
        if (CompareText(Name,TestAction.Name) = 0) then
          Result := TestAction;
      end;
  except
    on ExceptionObj: TObject do
    begin
      JclExpertShowExceptionDialog(ExceptionObj);
    end;
  end;
end;

function JclExpertShowExceptionDialog(AExceptionObj: TObject): Boolean;
var
  AJclExpertExceptionForm: TJclExpertExceptionForm;
begin
  AJclExpertExceptionForm := TJclExpertExceptionForm.Create(Application);
  try
    AJclExpertExceptionForm.ShowException(AExceptionObj);
    Result := AJclExpertExceptionForm.Execute;
  finally
    AJclExpertExceptionForm.Free;
  end;
end;

{$IFDEF BDS}
function PersonalityTextToId(const PersonalityText: string): TJclBorPersonality;
begin
  if SameText(PersonalityText, sDelphiPersonality) then
    Result := bpDelphi32
  else if SameText(PersonalityText, sDelphiDotNetPersonality) then
    Result := bpDelphiNet32
  else if SameText(PersonalityText, sCBuilderPersonality) then
    Result := bpBCBuilder32
  else if SameText(PersonalityText, sCSharpPersonality) then
    Result := bpCSBuilder32
  else if SameText(PersonalityText, sVBPersonality) then
    Result := bpVisualBasic32
  {$IFDEF COMPILER10_UP}
  else if SameText(PersonalityText, sDesignPersonality) then
    Result := bpDesign
  {$ENDIF COMPILER10_UP}
  else
    Result := bpUnknown;
end;
{$ENDIF BDS}

// result[] > 0: the property was found, result is the position of the first char of the property value
// result[] <= 0: the property was not found, -result is the position where the property could be inserted
function InternalLocateProperties(const AReader: IOTAEditReader; const PropIDs: TDynAnsiStringArray): TDynIntegerArray;
const
  BufferSize = 4096;
var
  Buffer, Line: AnsiString;
  BufferStart, BufferCount, BufferPosition, LineStart, Position, PropIndex, PropCount, PropMatches: Integer;
  InsideLineComment, InsideComment, InsideBrace: Boolean;
  procedure LoadNextBuffer;
  begin
    BufferStart := Position;
    BufferCount := AReader.GetText(BufferStart, PAnsiChar(Buffer), BufferSize);
    BufferPosition := Position - BufferStart;
  end;
begin
  BufferStart := 0;
  BufferCount := 0;
  LineStart := 0;
  Position := 0;
  PropMatches := 0;
  InsideLineComment := False;
  InsideComment := False;
  InsideBrace := False;
  PropCount := Length(PropIDs);
  SetLength(Result, PropCount);
  for PropIndex := 0 to PropCount - 1 do
    Result[PropIndex] := -1;

  SetLength(Buffer, BufferSize);
  repeat
    BufferPosition := Position - BufferStart;

    if BufferPosition >= BufferCount then
      LoadNextBuffer;

    case Buffer[BufferPosition + 1] of
      NativeLineFeed,
      NativeCarriageReturn:
        begin
          if InsideLineComment and not (InsideComment or InsideBrace) then
          begin
            // process line
            InsideLineComment := False;
            if (LineStart - BufferStart) < 0 then
              raise EJclExpertException.CreateRes(@RsELineTooLong);
            Line := Copy(Buffer, LineStart - BufferStart + 1, Position - LineStart);
            for PropIndex := 0 to PropCount - 1 do
              if Pos(PropIDs[PropIndex], Line) = 4 then
            begin
              Result[PropIndex] := LineStart + Length(PropIDs[PropIndex]) + 4;
              Inc(PropMatches);
            end;
          end;
          LineStart := Position + 1;
        end;
      '/':
        begin
          if BufferPosition >= BufferCount then
            LoadNextBuffer;
          if (BufferPosition + 1) < BufferCount then
          begin
            if not (InsideLineComment or InsideComment or InsideBrace) then
            begin
              if (Buffer[BufferPosition + 2] = '/') then
              begin
                Inc(Position);
                InsideLineComment := True;
              end
              else
                // end of comments
                Break;
            end;
          end
          else
            // end of file
            Break;
        end;
      '(':
        begin
          if BufferPosition >= BufferCount then
            LoadNextBuffer;
          if (BufferPosition + 1) < BufferCount then
          begin
            if not (InsideLineComment or InsideComment or InsideBrace) then
            begin
              if (Buffer[BufferPosition + 2] = '*') then
              begin
                Inc(Position);
                InsideComment := True;
              end
              else
                // end of comments
                Break;
            end;
          end
          else
            // end of file
            Break;
        end;
      '*':
        begin
          if BufferPosition >= BufferCount then
            LoadNextBuffer;
          if (BufferPosition + 1) < BufferCount then
          begin
            if InsideComment then
            begin
              if (Buffer[BufferPosition + 2] = ')') then
              begin
                Inc(Position);
                InsideComment := False;
              end;
            end
            else
            if not (InsideLineComment or InsideBrace) then
              // end of comments
              Break;
          end
          else
            // end of file
            Break;
        end;
      '{':
        if not (InsideLineComment or InsideComment or InsideBrace) then
          InsideBrace := True;
      '}':
        if InsideBrace then
          InsideBrace := False
        else
        if not (InsideLineComment or InsideComment) then
          // end of comments
          Break;
    else
      if not CharIsWhiteSpace(Char(Buffer[BufferPosition + 1])) and not InsideLineComment
        and not InsideComment and not InsideBrace then
        // end of comments
        Break;
    end;
    Inc(Position);
  until (BufferCount = 0) or (PropMatches = PropCount);
  if InsideLineComment or InsideComment or InsideBrace then
    raise EJclExpertException.CreateRes(@RsEUnterminatedComment);
  for PropIndex := 0 to PropCount - 1 do
    if Result[PropIndex] = -1 then
      Result[PropIndex] := -Position;
end;

function GetProjectProperties(const AProject: IOTAProject; const PropIDs: TDynAnsiStringArray): TDynAnsiStringArray;
const
  BufferSize = 4096;
var
  FileIndex, PropCount, PropIndex, BufferIndex: Integer;
  AEditor: IOTAEditor;
  FileExtension: string;
  PropLocations: TDynIntegerArray;
  AReader: IOTAEditReader;
begin
  PropCount := Length(PropIDs);
  SetLength(Result, PropCount);
  SetLength(PropLocations, 0);
  for FileIndex := 0 to AProject.GetModuleFileCount - 1 do
  begin
    AEditor := AProject.GetModuleFileEditor(FileIndex);
    FileExtension := ExtractFileExt(AEditor.FileName);
    if AnsiSameText(FileExtension, '.dpr') or AnsiSameText(FileExtension, '.dpk')
      or AnsiSameText(FileExtension, '.bpf') or AnsiSameText(FileExtension, '.cpp') then
    begin
      AReader := (AEditor as IOTASourceEditor).CreateReader;
      try
        PropLocations := InternalLocateProperties(AReader, PropIDs);
        for PropIndex := 0 to PropCount - 1 do
          if PropLocations[PropIndex] > 0 then
        begin
          SetLength(Result[PropIndex], BufferSize);
          SetLength(Result[PropIndex], AReader.GetText(PropLocations[PropIndex], PAnsiChar(Result[PropIndex]), BufferSize));
          for BufferIndex := 1 to Length(Result[PropIndex]) do
            if CharIsWhiteSpace(Char(Result[PropIndex][BufferIndex])) then
          begin
            SetLength(Result[PropIndex], BufferIndex - 1);
            Break;
          end;
        end;
      finally
        AReader := nil;
      end;
      Break;
    end;
  end;
end;

function SetProjectProperties(const AProject: IOTAProject; const PropIDs, PropValues: TDynAnsiStringArray): Integer;
const
  BufferSize = 4096;
var
  FileIndex, PropCount, PropIndex, BufferIndex, PropSize: Integer;
  AEditor: IOTAEditor;
  ASourceEditor: IOTASourceEditor;
  FileExtension: string;
  Buffer: AnsiString;
  PropLocations: TDynIntegerArray;
  AReader: IOTAEditReader;
  AWriter: IOTAEditWriter;
  S: AnsiString;
  ABuffer: IOTAEditBuffer;
begin
  PropCount := Length(PropIDs);
  Result := 0;
  for FileIndex := 0 to AProject.GetModuleFileCount - 1 do
  begin
    AEditor := AProject.GetModuleFileEditor(FileIndex);
    FileExtension := ExtractFileExt(AEditor.FileName);
    if AnsiSameText(FileExtension, '.dpr') or AnsiSameText(FileExtension, '.dpk')
      or AnsiSameText(FileExtension, '.bpf') or AnsiSameText(FileExtension, '.cpp') then
    begin
      ASourceEditor := AEditor as IOTASourceEditor;
      ABuffer := ASourceEditor as IOTAEditBuffer;
      if not ABuffer.IsReadOnly then
      begin
        for PropIndex := 0 to PropCount - 1 do
        begin
          SetLength(PropLocations, 0);
          PropSize := 0;
          AReader := ASourceEditor.CreateReader;
          try
            PropLocations := InternalLocateProperties(AReader, Copy(PropIDs, PropIndex, 1));
            if PropLocations[0] > 0 then
            begin
              SetLength(Buffer, BufferSize);
              SetLength(Buffer, AReader.GetText(PropLocations[0], PAnsiChar(Buffer), BufferSize));
              for BufferIndex := 1 to Length(Buffer) do
                if CharIsWhiteSpace(Char(Buffer[BufferIndex])) then
              begin
                PropSize := BufferIndex - 1;
                Break;
              end;
            end;
          finally
            // release the reader before allocating the writer
            AReader := nil;
          end;

          AWriter := ASourceEditor.CreateUndoableWriter;
          try
            if PropLocations[0] > 0 then
            begin
              AWriter.CopyTo(PropLocations[0]);
              AWriter.DeleteTo(PropLocations[0] + PropSize);
              AWriter.Insert(PAnsiChar(PropValues[PropIndex]));
            end
            else
            begin
              AWriter.CopyTo(-PropLocations[0]);
              S := AnsiString(Format('// %s %s%s', [PropIDs[PropIndex], PropValues[PropIndex], NativeLineBreak]));
              AWriter.Insert(PAnsiChar(S));
            end;
          finally
            // release the writter before allocating the reader
            AWriter := nil;
          end;
          Inc(Result);
        end;
      end;
      Break;
    end;
  end;
end;

//=== { EJclExpertException } ================================================

{$IFDEF MSWINDOWS}
procedure EJclExpertException.AfterConstruction;
begin
  inherited AfterConstruction;
  FStackInfo := JclCreateStackList(True, 0, nil, False);
end;

destructor EJclExpertException.Destroy;
begin
  FreeAndNil(FStackInfo);
  inherited Destroy;
end;
{$ENDIF MSWINDOWS}

//=== { TJclOTASettings } ====================================================

constructor TJclOTASettings.Create(ExpertName: string);
var
  OTAServices: IOTAServices;
begin
  inherited Create;

  Supports(BorlandIDEServices,IOTAServices,OTAServices);
  if not Assigned(OTAServices) then
    raise EJclExpertException.CreateRes(@RsENoOTAServices);

  FBaseKeyName := StrEnsureSuffix(NativeBackSlash, OTAServices.GetBaseRegistryKey);
  
  FKeyName := BaseKeyName + RegJclIDEKey + ExpertName;
end;

function TJclOTASettings.LoadBool(Name: string; Def: Boolean): Boolean;
begin
  {$IFDEF MSWINDOWS}
  Result := RegReadBoolDef(HKCU, KeyName, Name, Def);
  {$ELSE MSWINDOWS}
  Result := Def;
  {$ENDIF MSWINDOWS}
end;

function TJclOTASettings.LoadInteger(Name: string; Def: Integer): Integer;
begin
  {$IFDEF MSWINDOWS}

  Result := RegReadIntegerDef(HKCU, KeyName, Name, Def);
  {$ELSE MSWINDOWS}
  Result := Def;
  {$ENDIF MSWINDOWS}
end;

function TJclOTASettings.LoadString(Name, Def: string): string;
begin
  {$IFDEF MSWINDOWS}
  Result := RegReadStringDef(HKCU, KeyName, Name, Def);
  {$ELSE MSWINDOWS}
  Result := Def;
  {$ENDIF MSWINDOWS}
end;

procedure TJclOTASettings.LoadStrings(Name: string; List: TStrings);
begin
  {$IFDEF MSWINDOWS}
  RegLoadList(HKCU, KeyName, Name, List);
  {$ELSE MSWINDOWS}
  List.Clear;
  {$ENDIF MSWINDOWS}
end;

procedure TJclOTASettings.SaveBool(Name: string; Value: Boolean);
begin
  {$IFDEF MSWINDOWS}
  RegWriteBool(HKCU, KeyName, Name, Value);
  {$ENDIF MSWINDOWS}
end;

procedure TJclOTASettings.SaveInteger(Name: string; Value: Integer);
begin
  {$IFDEF MSWINDOWS}
  RegWriteInteger(HKCU, KeyName, Name, Value);
  {$ENDIF MSWINDOWS}
end;

procedure TJclOTASettings.SaveString(Name, Value: string);
begin
  {$IFDEF MSWINDOWS}
  RegWriteString(HKCU, KeyName, Name, Value);
  {$ENDIF MSWINDOWS}
end;

procedure TJclOTASettings.SaveStrings(Name: string; List: TStrings);
begin
  {$IFDEF MSWINDOWS}
  RegSaveList(HKCU, KeyName, Name, List);
  {$ENDIF MSWINDOWS}
end;

//=== { TJclOTAExpertBase } ==================================================

class function TJclOTAExpertBase.ConfigurationDialog(
  StartName: string): Boolean;
var
  OptionsForm: TJclOtaOptionsForm;
  Index: Integer;
begin
  OptionsForm := TJclOtaOptionsForm.Create(nil);
  try
    for Index := 0 to GetExpertCount - 1 do
      GetExpert(Index).AddConfigurationPages(OptionsForm.AddPage);
    Result := OptionsForm.Execute(StartName);
  finally
    OptionsForm.Free;
  end;
end;

class function TJclOTAExpertBase.GetExpert(Index: Integer): TJclOTAExpertBase;
begin
  if Assigned(GlobalExpertList) then
    Result := TJclOTAExpertBase(GlobalExpertList.Items[Index])
  else
    Result := nil;
end;

class function TJclOTAExpertBase.GetExpertCount: Integer;
begin
  if Assigned(GlobalExpertList) then
    Result := GlobalExpertList.Count
  else
    Result := 0;
end;

class procedure TJclOTAExpertBase.AddExpert(AExpert: TJclOTAExpertBase);
begin
  if not Assigned(GlobalExpertList) then
    GlobalExpertList := TList.Create;
  GlobalExpertList.Add(AExpert);
end;

procedure TJclOTAExpertBase.AfterConstruction;
begin
  inherited AfterConstruction;

  RegisterCommands;
  AddExpert(Self);
end;

procedure TJclOTAExpertBase.BeforeDestruction;
begin
  RemoveExpert(Self);
  UnregisterCommands;

  inherited BeforeDestruction;
end;

class procedure TJclOTAExpertBase.RemoveExpert(AExpert: TJclOTAExpertBase);
begin
  if Assigned(GlobalExpertList) then
    GlobalExpertList.Remove(AExpert);
end;

class function TJclOTAExpertBase.GetAction(Index: Integer): TAction;
begin
  if Assigned(GlobalActionList) then
    Result := TAction(GlobalActionList.Items[Index])
  else
    Result := nil;
end;

class function TJclOTAExpertBase.GetActionCount: Integer;
begin
  if Assigned(GlobalActionList) then
    Result := GlobalActionList.Count
  else
    Result := 0;
end;

type
  TAccessToolButton = class(TToolButton);

class procedure TJclOTAExpertBase.CheckToolBarButton(AToolBar: TToolBar; AAction: TCustomAction);
var
  Index: Integer;
  AButton: TAccessToolButton;
begin
  if Assigned(AToolBar) then
    for Index := AToolBar.ButtonCount - 1 downto 0 do
    begin
      AButton := TAccessToolButton(AToolBar.Buttons[Index]);
      if AButton.Action = AAction then
      begin
        AButton.SetToolBar(nil);
        AButton.Free;
      end;
    end;
end;

class function TJclOTAExpertBase.ActionSettings: TJclOtaSettings;
begin
  if not Assigned(GlobalActionSettings) then
    GlobalActionSettings := TJclOTASettings.Create(JclActionSettings);
  Result := GlobalActionSettings;
end;

procedure TJclOTAExpertBase.ConfigurationActionExecute(Sender: TObject);
begin
  try
    ConfigurationDialog('');
  except
    on ExceptionObj: TObject do
    begin
      JclExpertShowExceptionDialog(ExceptionObj);
    end;
  end;
end;

procedure TJclOTAExpertBase.ConfigurationActionUpdate(Sender: TObject);
begin
  try
    (Sender as TAction).Enabled := True;
  except
    on ExceptionObj: TObject do
    begin
      JclExpertShowExceptionDialog(ExceptionObj);
    end;
  end;
end;

procedure TJclOTAExpertBase.AddConfigurationPages(  
  AddPageFunc: TJclOTAAddPageFunc);
begin
  // AddPageFunc uses '\' as a separator in PageName to build a tree
  if not Assigned(ActionConfigureSheet) then
  begin
    ActionConfigureSheet := TJclOtaActionConfigureFrame.Create(Application);
    AddPageFunc(ActionConfigureSheet, LoadResString(@RsActionSheet), Self);
  end;
  if not Assigned(UnitVersioningSheet) then
  begin
    UnitVersioningSheet := TJclOtaUnitVersioningFrame.Create(Application);
    AddPageFunc(UnitVersioningSheet, LoadResString(@RsUnitVersioningSheet), Self);
  end;
  // override to customize
end;

procedure TJclOTAExpertBase.ConfigurationClosed(AControl: TControl;
  SaveChanges: Boolean);
begin
  if Assigned(AControl) and (AControl = ActionConfigureSheet) then
  begin
    if SaveChanges then
      ActionConfigureSheet.SaveChanges;
    FreeAndNil(ActionConfigureSheet);
  end
  else
  if Assigned(AControl) and (AControl = UnitVersioningSheet) then
    FreeAndNil(UnitVersioningSheet)
  else
    AControl.Free;
  // override to customize
end;

constructor TJclOTAExpertBase.Create(AName: string);
begin
  inherited Create;

  {$IFDEF BDS}
  RegisterSplashScreen;
  RegisterAboutBox;
  {$ENDIF BDS}

  FEnvVariables := TStringList.Create;
  FSettings := TJclOTASettings.Create(AName);
end;

destructor TJclOTAExpertBase.Destroy;
begin
  FreeAndNil(FSettings);
  FreeAndNil(FEnvVariables);

  inherited Destroy;
end;

function TJclOTAExpertBase.FindExecutableName(const MapFileName: TFileName;
  const OutputDirectory: string; var ExecutableFileName: TFileName): Boolean;
var
  Se: TSearchRec;
  Res: Integer;
  LatestTime: Integer;
  FileName: TFileName;
  {$IFDEF MSWINDOWS}
  LI: LoadedImage;
  {$ENDIF MSWINDOWS}
begin
  LatestTime := 0;
  ExecutableFileName := '';
  // the latest executable file is very likely our file
  Res := SysUtils.FindFirst(ChangeFileExt(MapFileName, '.*'), faArchive, Se);
  while Res = 0 do
  begin
    FileName := PathAddSeparator(OutputDirectory) + Se.Name;
    {$IFDEF MSWINDOWS}
    // possible loss of data
    if MapAndLoad(PAnsiChar(AnsiString(FileName)), nil, @LI, False, True) then
    begin
      if (not LI.fDOSImage) and (Se.Time > LatestTime) then
      begin
        ExecutableFileName := FileName;
        LatestTime := Se.Time;
      end;
      UnMapAndLoad(@LI);
    end;
    {$ELSE}
    if Se.Time > LatestTime then
    begin
      ExecutableFileName := FileName;
      LatestTime := Se.Time;
    end;
    {$ENDIF MSWINDOWS}
    Res := SysUtils.FindNext(Se);
  end;
  SysUtils.FindClose(Se);
  Result := (ExecutableFileName <> '');
end;

class function TJclOTAExpertBase.GetActiveProject: IOTAProject;
var
  ProjectGroup: IOTAProjectGroup;
  OTAModuleServices: IOTAModuleServices;
  Index: Integer;
begin
  Result := nil;
  ProjectGroup := GetProjectGroup;
  OTAModuleServices := GetOTAModuleServices;

  if Assigned(ProjectGroup) then
    Result := ProjectGroup.ActiveProject
  else
    for Index := 0 to OTAModuleServices.ModuleCount - 1 do
      if Supports(OTAModuleServices.Modules[Index], IOTAProject, Result) then
        Exit;
end;

function TJclOTAExpertBase.GetDesigner: string;
begin
  Result := GetOTAServices.GetActiveDesignerType;
end;

function TJclOTAExpertBase.GetDrcFileName(const Project: IOTAProject): TFileName;
begin
  if not Assigned(Project) then
    raise EJclExpertException.CreateRes(@RsENoActiveProject);
    
  Result := ChangeFileExt(Project.FileName, CompilerExtensionDRC);
end;

function TJclOTAExpertBase.GetMapFileName(const Project: IOTAProject): TFileName;
var
  ProjectFileName: TFileName;
  OutputDirectory, LibPrefix, LibSuffix: string;
begin
  if not Assigned(Project) then
    raise EJclExpertException.CreateRes(@RsENoActiveProject);

  ProjectFileName := Project.FileName;
  OutputDirectory := GetOutputDirectory(Project);
  if not Assigned(Project.ProjectOptions) then
    raise EJclExpertException.CreateRes(@RsENoProjectOptions);
  LibPrefix := Trim(VarToStr(Project.ProjectOptions.Values[LIBPREFIXOptionName]));
  LibSuffix := Trim(VarToStr(Project.ProjectOptions.Values[LIBSUFFIXOptionName]));
  {$IFDEF BDS}
  if Project.Personality = JclCBuilderPersonality then
  begin
    // C++Builder 2007 does not support lib prefix and lib suffix
    LibPrefix := '';
    LibSuffix := '';
  end;
  {$ENDIF BDS}
  Result := PathAddSeparator(OutputDirectory) + LibPrefix +
    PathExtractFileNameNoExt(ProjectFileName) + LibSuffix + CompilerExtensionMAP;
end;

function TJclOTAExpertBase.GetModuleHInstance: Cardinal;
begin
  Result := FindClassHInstance(ClassType);
  if Result = 0 then
    raise EJclExpertException.CreateRes(@RsBadModuleHInstance);
end;

class function TJclOTAExpertBase.GetNTAServices: INTAServices;
begin
  Supports(BorlandIDEServices, INTAServices, Result);
  if not Assigned(Result) then
    raise EJclExpertException.CreateRes(@RsENoNTAServices);
end;

{$IFDEF BDS}
class function TJclOTAExpertBase.GetOTAGalleryCategoryManager: IOTAGalleryCategoryManager;
begin
  Supports(BorlandIDEServices, IOTAGalleryCategoryManager, Result);
  if not Assigned(Result) then
    raise EJclExpertException.CreateRes(@RsENoOTAGalleryCategoryManager);
end;
{$ENDIF BDS}

class function TJclOTAExpertBase.GetOTADebuggerServices: IOTADebuggerServices;
begin
  Supports(BorlandIDEServices, IOTADebuggerServices, Result);
  if not Assigned(Result) then
    raise EJclExpertException.CreateRes(@RsENoDebuggerServices);
end;

class function TJclOTAExpertBase.GetOTAMessageServices: IOTAMessageServices;
begin
  Supports(BorlandIDEServices, IOTAMessageServices, Result);
  if not Assigned(Result) then
    raise EJclExpertException.CreateRes(@RsENoOTAMessageServices);
end;

class function TJclOTAExpertBase.GetOTAModuleServices: IOTAModuleServices;
begin
  Supports(BorlandIDEServices, IOTAModuleServices, Result);
  if not Assigned(Result) then
    raise EJclExpertException.CreateRes(@RsENoOTAModuleServices);
end;

class function TJclOTAExpertBase.GetOTAPackageServices: IOTAPackageServices;
begin
  Supports(BorlandIDEServices, IOTAPackageServices, Result);
  if not Assigned(Result) then
    raise EJclExpertException.CreateRes(@RsENoOTAPackageServices);
end;

{$IFDEF BDS}
class function TJclOTAExpertBase.GetOTAPersonalityServices: IOTAPersonalityServices;
begin
  Supports(BorlandIDEServices, IOTAPersonalityServices, Result);
  if not Assigned(Result) then
    raise EJclExpertException.CreateRes(@RsENoOTAPersonalityServices);
end;
{$ENDIF BDS}

{$IFDEF BDS4_UP}
class function TJclOTAExpertBase.GetOTAProjectManager: IOTAProjectManager;
begin
  Supports(BorlandIDEServices, IOTAProjectManager, Result);
  if not Assigned(Result) then
    raise EJclExpertException.CreateRes(@RsENoOTAProjectManager);
end;
{$ENDIF BDS4_UP}

class function TJclOTAExpertBase.GetOTAServices: IOTAServices;
begin
  Supports(BorlandIDEServices, IOTAServices, Result);
  if not Assigned(Result) then
    raise EJclExpertException.CreateRes(@RsENoOTAServices);
end;

class function TJclOTAExpertBase.GetOTAWizardServices: IOTAWizardServices;
begin
  Supports(BorlandIDEServices, IOTAWizardServices, Result);
  if not Assigned(Result) then
    raise EJclExpertException.CreateRes(@RsENoOTAWizardServices);
end;

function TJclOTAExpertBase.GetOutputDirectory(const Project: IOTAProject): string;
var
  EnvironmentOptions: IOTAEnvironmentOptions;
  OptionValue: Variant;
begin
  if not Assigned(Project) then
    raise EJclExpertException.CreateRes(@RsENoActiveProject);
  if not Assigned(Project.ProjectOptions) then
      raise EJclExpertException.CreateRes(@RsENoProjectOptions);

  Result := '';

  if IsPackage(Project) then
  begin
    OptionValue := Project.ProjectOptions.Values[PkgDllDirOptionName];

    if VarIsStr(OptionValue) then
      Result := VarToStr(OptionValue);

    {$IFDEF BDS5}
    if (Project.Personality = JclCBuilderPersonality) and (Result = 'false') then
      Result := '';
    {$ENDIF BDS5}

    if Result = '' then
    begin
      EnvironmentOptions := GetOTAServices.GetEnvironmentOptions;
      if not Assigned(EnvironmentOptions) then
        raise EJclExpertException.CreateRes(@RsENoEnvironmentOptions);
      OptionValue := EnvironmentOptions.Values[BPLOutputDirOptionName];
      if VarIsStr(OptionValue) then
        Result := VarToStr(OptionValue);
    end;
  end
  else
  begin
    OptionValue := Project.ProjectOptions.Values[OutputDirOptionName];

    if VarIsStr(OptionValue) then
      Result := VarToStr(OptionValue);

    {$IFDEF BDS5}
    if (Project.Personality = JclCBuilderPersonality) and (Result = 'false') then
      Result := '';
    {$ENDIF BDS5}

    if Result = '' then
    begin
      OptionValue := Project.ProjectOptions.Values[FinalOutputDirOptionName];
      if VarIsStr(OptionValue) then
        Result := VarToStr(OptionValue);
    end;
  end;

  {$IFDEF BDS5}
  if (Project.Personality = JclCBuilderPersonality) and (Result = 'false') then
    Result := '';
  {$ENDIF BDS5}

  Result := SubstitutePath(Trim(Result));
  if Result = '' then
    Result := ExtractFilePath(Project.FileName)
  else
  if not PathIsAbsolute(Result) then
    Result := PathGetRelativePath(ExtractFilePath(Project.FileName), Result);
end;

function TJclOTAExpertBase.GetActivePersonality: TJclBorPersonality;
{$IFDEF BDS}
var
  PersonalityText: string;
  OTAPersonalityServices: IOTAPersonalityServices;
  {$IFDEF COMPILER9_UP}
  ActiveProject: IOTAProject;
  {$ENDIF COMPILER9_UP}
begin
  {$IFDEF COMPILER9_UP}
  ActiveProject := ActiveProject;
  if Assigned(ActiveProject) then
    PersonalityText := ActiveProject.Personality
  else
  {$ENDIF COMPILER9_UP}
  OTAPersonalityServices := GetOTAPersonalityServices;
  PersonalityText := OTAPersonalityServices.CurrentPersonality;
  Result := PersonalityTextToId(PersonalityText);
end;
{$ELSE BDS}
begin
  {$IFDEF DELPHI}
  Result := bpDelphi32;
  {$ENDIF DELPHI}
  {$IFDEF BCB}
  Result := bpBCBuilder32;
  {$ENDIF BCB}
end;
{$ENDIF BDS}

class function TJclOTAExpertBase.GetProjectGroup: IOTAProjectGroup;
var
  OTAModuleServices: IOTAModuleServices;
  AModule: IOTAModule;
  I: Integer;
begin
  OTAModuleServices := GetOTAModuleServices;
  for I := 0 to OTAModuleServices.ModuleCount - 1 do
  begin
    AModule := OTAModuleServices.Modules[I];
    if not Assigned(AModule) then
      raise EJclExpertException.CreateRes(@RsENoModule);
    if AModule.QueryInterface(IOTAProjectGroup, Result) = S_OK then
      Exit;
  end;
  Result := nil;
end;

function TJclOTAExpertBase.GetRootDir: string;
begin
  if FRootDir = '' then
  begin
    //(usc) another possibility for D7 or higher is to use IOTAServices.GetRootDirectory
    {$IFDEF MSWINDOWS}
    FRootDir := RegReadStringDef(HKEY_LOCAL_MACHINE, Settings.BaseKeyName, DelphiRootDirKeyValue, '');
    // (rom) bugfix if using -r switch of D9 by Dan Miser
    if FRootDir = '' then
      FRootDir := RegReadStringDef(HKEY_CURRENT_USER, Settings.BaseKeyName, DelphiRootDirKeyValue, '');
    {$ENDIF MSWINDOWS}
    if FRootDir = '' then
      raise EJclExpertException.CreateRes(@RsENoRootDir);
  end;
  Result := FRootDir;
end;

function TJclOTAExpertBase.IsInstalledPackage(const Project: IOTAProject): Boolean;
var
  PackageFileName, ExecutableNameNoExt: TFileName;
  OTAPackageServices: IOTAPackageServices;
  I: Integer;
begin
  if not Assigned(Project) then
    raise EJclExpertException.CreateRes(@RsENoActiveProject);

  Result := IsPackage(Project);
  if Result then
  begin
    Result := False;

    if not Assigned(Project.ProjectOptions) then
      raise EJclExpertException.CreateRes(@RsENoProjectOptions);

    if not Project.ProjectOptions.Values[RuntimeOnlyOptionName] then
    begin
      ExecutableNameNoExt := ChangeFileExt(GetMapFileName(Project), '');
      OTAPackageServices := GetOTAPackageServices;

      for I := 0 to OTAPackageServices.PackageCount - 1 do
      begin
        PackageFileName := ChangeFileExt(OTAPackageServices.PackageNames[I], BinaryExtensionPackage);
        PackageFileName := GetModulePath(GetModuleHandle(PChar(PackageFileName)));
        if AnsiSameText(ChangeFileExt(PackageFileName, ''), ExecutableNameNoExt) then
        begin
          Result := True;
          Break;
        end;
      end;
    end;
  end;
end;

function TJclOTAExpertBase.IsPackage(const Project: IOTAProject): Boolean;
var
  FileName: TFileName;
  FileExtension: string;
  Index: Integer;
  ProjectFile: TJclSimpleXML;
  PersonalityNode, SourceNode, ProjectExtensions, ProjectTypeNode: TJclSimpleXMLElem;
  NameProp: TJclSimpleXMLProp;
begin
  if not Assigned(Project) then
    raise EJclExpertException.CreateRes(@RsENoActiveProject);

  FileName := Project.FileName;
  FileExtension := ExtractFileExt(FileName);

  if AnsiSameText(FileExtension, SourceExtensionDProject) and FileExists(FileName) then
  begin
    Result := False;
    ProjectFile := TJclSimpleXML.Create;
    try
      ProjectFile.Options := ProjectFile.Options - [sxoAutoCreate];
      ProjectFile.LoadFromFile(FileName);
      ProjectExtensions := ProjectFile.Root.Items.ItemNamed['ProjectExtensions'];
      if Assigned(ProjectExtensions) then
      begin
        ProjectTypeNode := ProjectExtensions.Items.ItemNamed['Borland.ProjectType'];
        if Assigned(ProjectTypeNode) then
          Result := AnsiSameText(ProjectTypeNode.Value, 'Package');
      end;
    finally
      ProjectFile.Free;
    end;
  end
  else
  if AnsiSameText(FileExtension, SourceExtensionBDSProject) and FileExists(FileName) then
  begin
    Result := False;
    ProjectFile := TJclSimpleXML.Create;
    try
      ProjectFile.Options := ProjectFile.Options - [sxoAutoCreate];
      ProjectFile.LoadFromFile(FileName);
      PersonalityNode := ProjectFile.Root.Items.ItemNamed['Delphi.Personality'];
      if not Assigned(PersonalityNode) then
        PersonalityNode := ProjectFile.Root.Items.ItemNamed['CPlusPlusBuilder.Personality'];

      if Assigned(PersonalityNode) then
      begin
        SourceNode := PersonalityNode.Items.ItemNamed['Source'];
        if Assigned(SourceNode) then
        begin
          for Index := 0 to SourceNode.Items.Count - 1 do
            if AnsiSameText(SourceNode.Items.Item[0].Name, 'Source') then
          begin
            NameProp := SourceNode.Items.Item[0].Properties.ItemNamed['Name'];
            if Assigned(NameProp) and AnsiSameText(NameProp.Value, 'MainSource') then
            begin
              Result := AnsiSameText(ExtractFileExt(SourceNode.Items.Item[0].Value), SourceExtensionDelphiPackage);
              Break;
            end;
          end;
        end;
      end;
    finally
      ProjectFile.Free;
    end;
  end
  else
    Result := AnsiSameText(FileExtension, SourceExtensionDelphiPackage);
end;

class function TJclOTAExpertBase.IsPersonalityLoaded(
  const PersonalityName: string): Boolean;
{$IFDEF BDS}
var
  OTAPersonalityServices: IOTAPersonalityServices;
  Index: Integer;
begin
  OTAPersonalityServices := GetOTAPersonalityServices;
  Result := False;

  for Index := 0 to OTAPersonalityServices.PersonalityCount - 1 do
    if SameText(OTAPersonalityServices.Personalities[Index], PersonalityName) then
  begin
    Result := True;
    Break;
  end;
end;
{$ELSE BDS}
begin
  Result := True;
end;
{$ENDIF BDS}

procedure TJclOTAExpertBase.ReadEnvVariables;
var
  I: Integer;
  EnvNames: TStringList;
  {$IFDEF MSWINDOWS}
  EnvVarKeyName: string;
  {$ENDIF MSWINDOWS}
begin
  FEnvVariables.Clear;

  // read user and system environment variables
  GetEnvironmentVars(FEnvVariables, False);

  // read Delphi environment variables
  EnvNames := TStringList.Create;
  try
    {$IFDEF MSWINDOWS}
    EnvVarKeyName := Settings.BaseKeyName + EnvironmentVarsKey;
    if RegKeyExists(HKEY_CURRENT_USER, EnvVarKeyName) and
      RegGetValueNames(HKEY_CURRENT_USER, EnvVarKeyName, EnvNames) then
      for I := 0 to EnvNames.Count - 1 do
        FEnvVariables.Values[EnvNames[I]] :=
          RegReadStringDef(HKEY_CURRENT_USER, EnvVarKeyName, EnvNames[I], '');
    {$ENDIF MSWINDOWS}
  finally
    EnvNames.Free;
  end;

  // add the Delphi directory
  FEnvVariables.Values[DelphiEnvironmentVar] := RootDir;
end;

function TJclOTAExpertBase.SubstitutePath(const Path: string): string;
var
  I: Integer;
  Name: string;
begin
  if FEnvVariables.Count = 0 then
    ReadEnvVariables;
  Result := Path;
  while Pos('$(', Result) > 0 do
    for I := 0 to FEnvVariables.Count - 1 do
    begin
      Name := FEnvVariables.Names[I];
      Result := StringReplace(Result, Format('$(%s)', [Name]),
        FEnvVariables.Values[Name], [rfReplaceAll, rfIgnoreCase]);
    end;
  While Pos('\\', Result) > 0 do
    Result := StringReplace(Result, '\\', DirDelimiter, [rfReplaceAll]);
end;

procedure TJclOTAExpertBase.RegisterAction(Action: TCustomAction);
begin
  if Action.Name <> '' then
  begin
    Action.Tag := Action.ShortCut;  // to restore settings
    Action.ShortCut := ActionSettings.LoadInteger(Action.Name, Action.ShortCut);
  end;

  if not Assigned(GlobalActionList) then
  begin
    GlobalActionList := TList.Create;
    RegisterFindGlobalComponentProc(FindActions);
  end;

  GlobalActionList.Add(Action);
end;

procedure TJclOTAExpertBase.UnregisterAction(Action: TCustomAction);
var
  NTAServices: INTAServices;
begin
  if Action.Name <> '' then
    ActionSettings.SaveInteger(Action.Name, Action.ShortCut);

  if Assigned(GlobalActionList) then
  begin
    GlobalActionList.Remove(Action);
    if (GlobalActionList.Count = 0) then
    begin
      FreeAndNil(GlobalActionList);
      UnRegisterFindGlobalComponentProc(FindActions);
    end;
  end;

  NTAServices := GetNTAServices;
  // remove action from toolbar to avoid crash when recompile package inside the IDE.
  CheckToolBarButton(NTAServices.ToolBar[sCustomToolBar], Action);
  CheckToolBarButton(NTAServices.ToolBar[sStandardToolBar], Action);
  CheckToolBarButton(NTAServices.ToolBar[sDebugToolBar], Action);
  CheckToolBarButton(NTAServices.ToolBar[sViewToolBar], Action);
  CheckToolBarButton(NTAServices.ToolBar[sDesktopToolBar], Action);
  {$IFDEF COMPILER7_UP}
  CheckToolBarButton(NTAServices.ToolBar[sInternetToolBar], Action);
  CheckToolBarButton(NTAServices.ToolBar[sCORBAToolBar], Action);
  {$ENDIF COMPILER7_UP}
end;

procedure TJclOTAExpertBase.RegisterCommands;
var
  JclIcon: TIcon;
  Category: string;
  Index: Integer;
  IDEMenuItem, ToolsMenuItem: TMenuItem;
  NTAServices: INTAServices;
begin
  NTAServices := GetNTAServices;
  
  if not Assigned(ConfigurationAction) then
  begin
    Category := '';
    for Index := 0 to NTAServices.ActionList.ActionCount - 1 do
      if CompareText(NTAServices.ActionList.Actions[Index].Name, 'ToolsOptionsCommand') = 0 then
        Category := NTAServices.ActionList.Actions[Index].Category;

    ConfigurationAction := TAction.Create(nil);
    JclIcon := TIcon.Create;
    try
      // not ModuleHInstance because the resource is in JclBaseExpert.bpl                                                                  
      JclIcon.Handle := LoadIcon(HInstance, 'JCLCONFIGURE');
      ConfigurationAction.ImageIndex := NTAServices.ImageList.AddIcon(JclIcon);
    finally
      JclIcon.Free;
    end;
    ConfigurationAction.Caption := LoadResString(@RsJCLOptions);
    ConfigurationAction.Name := JclConfigureActionName;
    ConfigurationAction.Category := Category;
    ConfigurationAction.Visible := True;
    ConfigurationAction.OnUpdate := ConfigurationActionUpdate;
    ConfigurationAction.OnExecute := ConfigurationActionExecute;

    ConfigurationAction.ActionList := NTAServices.ActionList;
    RegisterAction(ConfigurationAction);
  end;
  
  if not Assigned(ConfigurationMenuItem) then
  begin
    IDEMenuItem := NTAServices.MainMenu.Items;
    if not Assigned(IDEMenuItem) then
      raise EJclExpertException.CreateRes(@RsENoIDEMenu);

    ToolsMenuItem := nil;
    for Index := 0 to IDEMenuItem.Count - 1 do
      if CompareText(IDEMenuItem.Items[Index].Name, 'ToolsMenu') = 0 then
        ToolsMenuItem := IDEMenuItem.Items[Index];
    if not Assigned(ToolsMenuItem) then
      raise EJclExpertException.CreateRes(@RsENoToolsMenu);

    ConfigurationMenuItem := TMenuItem.Create(nil);
    ConfigurationMenuItem.Name := JclConfigureMenuName;
    ConfigurationMenuItem.Action := ConfigurationAction;

    ToolsMenuItem.Insert(0, ConfigurationMenuItem);
  end;

  // override to add actions and menu items
end;

procedure TJclOTAExpertBase.UnregisterCommands;
begin
  if GetExpertCount = 0 then
  begin
    UnregisterAction(ConfigurationAction);
    FreeAndNil(ConfigurationAction);
    FreeAndNil(ConfigurationMenuItem);
  end;

  // override to remove actions and menu items
end;

//=== { TJclOTAExpert } ======================================================

procedure TJclOTAExpert.AfterSave;
begin
end;

procedure TJclOTAExpert.BeforeSave;
begin
end;

procedure TJclOTAExpert.Destroyed;
begin
end;

procedure TJclOTAExpert.Execute;
begin
end;

function TJclOTAExpert.GetIDString: string;
begin
  Result := 'Jedi.' + ClassName;
end;

function TJclOTAExpert.GetName: string;
begin
  Result := ClassName;
end;

function TJclOTAExpert.GetState: TWizardState;
begin
  Result := [];
end;

procedure TJclOTAExpert.Modified;
begin

end;

{$IFDEF BDS7_UP}

//=== { TJclOTALocalMenu } ===================================================

procedure TJclOTALocalMenu.AfterSave;
begin

end;

procedure TJclOTALocalMenu.BeforeSave;
begin

end;

procedure TJclOTALocalMenu.Destroyed;
begin

end;

procedure TJclOTALocalMenu.Modified;
begin

end;

function TJclOTALocalMenu.GetCaption: string;
begin
  Result := FCaption;
end;

function TJclOTALocalMenu.GetChecked: Boolean;
begin
  Result := FChecked;
end;

function TJclOTALocalMenu.GetEnabled: Boolean;
begin
  Result := FEnabled;
end;

function TJclOTALocalMenu.GetHelpContext: Integer;
begin
  Result := FHelpContext;
end;

function TJclOTALocalMenu.GetName: string;
begin
  Result := FName;
end;

function TJclOTALocalMenu.GetParent: string;
begin
  Result := FParent;
end;

function TJclOTALocalMenu.GetPosition: Integer;
begin
  Result := FPosition;
end;

function TJclOTALocalMenu.GetVerb: string;
begin
  Result := FVerb;
end;

procedure TJclOTALocalMenu.SetCaption(const Value: string);
begin
  FCaption := Value;
end;

procedure TJclOTALocalMenu.SetChecked(Value: Boolean);
begin
  FChecked := Value;
end;

procedure TJclOTALocalMenu.SetEnabled(Value: Boolean);
begin
  FEnabled := Value;
end;

procedure TJclOTALocalMenu.SetHelpContext(Value: Integer);
begin
  FHelpContext := Value;
end;

procedure TJclOTALocalMenu.SetName(const Value: string);
begin
  FName := Value;
end;

procedure TJclOTALocalMenu.SetParent(const Value: string);
begin
  FParent := Value;
end;

procedure TJclOTALocalMenu.SetPosition(Value: Integer);
begin
  FPosition := Value;
end;

procedure TJclOTALocalMenu.SetVerb(const Value: string);
begin
  FVerb := Value;
end;

//=== { TJclOTAProjectManagerMenu } ==========================================

function TJclOTAProjectManagerMenu.GetIsMultiSelectable: Boolean;
begin
  Result := FIsMultiSelectable;
end;

procedure TJclOTAProjectManagerMenu.SetIsMultiSelectable(Value: Boolean);
begin
  FIsMultiSelectable := Value;
end;

procedure TJclOTAProjectManagerMenu.Execute(const MenuContextList: IInterfaceList);
begin
  if Assigned(FOnExecute) then
    FOnExecute(MenuContextList);
end;

function TJclOTAProjectManagerMenu.PreExecute(const MenuContextList: IInterfaceList): Boolean;
begin
  Result := True;
end;

function TJclOTAProjectManagerMenu.PostExecute(const MenuContextList: IInterfaceList): Boolean;
begin
  Result := True;
end;

{$ENDIF BDS7_UP}

{$IFDEF BDS}
var
  AboutBoxServices: IOTAAboutBoxServices = nil;
  AboutBoxIndex: Integer = -1;
  SplashScreenInitialized: Boolean = False;

procedure RegisterAboutBox;
var
  ProductImage: HBITMAP;
begin
  if AboutBoxIndex = -1 then
  begin
    Supports(BorlandIDEServices,IOTAAboutBoxServices, AboutBoxServices);
    if not Assigned(AboutBoxServices) then
      raise EJclExpertException.CreateRes(@RsENoOTAAboutServices);
    ProductImage := LoadBitmap(FindResourceHInstance(HInstance), 'JCLSPLASH');
    if ProductImage = 0 then
      raise EJclExpertException.CreateRes(@RsENoBitmapResources);
    AboutBoxIndex := AboutBoxServices.AddPluginInfo(LoadResString(@RsAboutTitle), LoadResString(@RsAboutDescription),
      ProductImage, False, LoadResString(@RsAboutLicenceStatus));
  end;
end;

procedure UnregisterAboutBox;
begin
  if (AboutBoxIndex <> -1) and Assigned(AboutBoxServices) then
  begin
    AboutBoxServices.RemovePluginInfo(AboutBoxIndex);
    AboutBoxIndex := -1;
    AboutBoxServices := nil;
  end;
end;

procedure RegisterSplashScreen;
var
  ProductImage: HBITMAP;
begin
  if Assigned(SplashScreenServices) and not SplashScreenInitialized then
  begin
    ProductImage := LoadBitmap(FindResourceHInstance(HInstance), 'JCLSPLASH');
    if ProductImage = 0 then
      raise EJclExpertException.CreateRes(@RsENoBitmapResources);
    SplashScreenServices.AddPluginBitmap(LoadResString(@RsAboutDialogTitle), ProductImage,
      False, LoadResString(@RsAboutLicenceStatus));
    SplashScreenInitialized := True;
  end;
end;

{$ENDIF BDS}

initialization

try
  {$IFDEF UNITVERSIONING}
  RegisterUnitVersion(HInstance, UnitVersioning);
  {$ENDIF UNITVERSIONING}
  Classes.RegisterClass(TJclWizardForm);
  Classes.RegisterClass(TJclWizardFrame);
except
  on ExceptionObj: TObject do
  begin
    JclExpertShowExceptionDialog(ExceptionObj);
  end;
end;

finalization

try
  {$IFDEF UNITVERSIONING}
  UnregisterUnitVersion(HInstance);
  {$ENDIF UNITVERSIONING}
  {$IFDEF BDS}
  UnregisterAboutBox;
  {$ENDIF BDS}
  FreeAndNil(GlobalActionList);
  FreeAndNil(GlobalActionSettings);
  FreeAndNil(GlobalExpertList);
except
  on ExceptionObj: TObject do
  begin
    JclExpertShowExceptionDialog(ExceptionObj);
  end;
end;

end.
