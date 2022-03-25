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
{ The Original Code is VersionControlImpl.pas                                                      }
{                                                                                                  }
{ The Initial Developer of the Original Code is Elahn Ientile.                                     }
{ Portions created by Elahn Ientile are Copyright (C) of Elahn Ientile.                            }
{                                                                                                  }
{ Contributors:                                                                                    }
{   Florent Ouchet (outchy)                                                                        }
{   Jens Fudickar  (jfudickar)                                                                     }
{   Sandeep Chandra                                                                                }
{                                                                                                  }
{**************************************************************************************************}
{                                                                                                  }
{ Last modified: $Date:: 2009-09-12 22:52:07 +0200 (sam., 12 sept. 2009)                         $ }
{ Revision:      $Rev:: 3007                                                                     $ }
{ Author:        $Author:: outchy                                                                $ }
{                                                                                                  }
{**************************************************************************************************}

unit JclVersionControl;

{$I jcl.inc}

interface

uses
  {$IFDEF UNITVERSIONING}
  JclUnitVersioning,
  {$ENDIF UNITVERSIONING}
  SysUtils, Classes,
  {$IFDEF HAS_UNIT_CONTNRS}
  Contnrs,
  {$ENDIF HAS_UNIT_CONTNRS}
  Graphics, Controls, ActnList, ImgList;

type
  TJclVersionControlActionType = (
    vcaAdd,               // add current file
    vcaAddSandbox,        // add file in the sandbox
    vcaBlame,             // detailed authors of the current file
    vcaBranch,            // branch current file
    vcaBranchSandbox,     // branch files of the sandbox
    vcaCheckOutSandbox,   // checkout a new sandbox
    vcaCommit,            // commit the current file
    vcaCommitSandbox,     // commit files of the sandbox
    vcaContextMenu,       // explorer context menu of the file
    vcaDiff,              // diff current file
    vcaExplore,           // explore folder containing current file
    vcaExploreSandbox,    // explore sandbox
    vcaGraph,             // modification graph of the current file
    vcaLog,               // log of the current file
    vcaLogSandbox,        // log of files in the sandbox
    vcaLock,              // lock current file
    vcaLockSandbox,       // lock files of the sandbox
    vcaMerge,             // merge current file
    vcaMergeSandbox,      // merge files of the sandbox
    vcaProperties,        // properties of the file
    vcaPropertiesSandbox, // properties of the sandbox
    vcaRename,            // rename current file
    vcaRenameSandbox,     // (renaming current sandbox) will not work inside Delphi
                          // because the IDE owns handles to project directories
    vcaRepoBrowser,       // repository browser
    vcaRevert,            // revert changes in the current file
    vcaRevertSandbox,     // revert changes in all files of the sandbox
    vcaStatus,            // status of current file
    vcaStatusSandbox,     // status of the sandbox
    vcaTag,               // tag the current file
    vcaTagSandBox,        // tag the current sandbox
    vcaUpdate,            // update current file
    vcaUpdateSandbox,     // update sandbox
    vcaUpdateTo,          // update current file to...
    vcaUpdateSandboxTo,   // update sandbox to...
    vcaUnlock,            // unlock current file
    vcaUnlockSandbox      // unlock sandbox
  );

  TJclVersionControlActionTypes = set of TJclVersionControlActionType;

  TJclVersionControlActionInfo = record
    Sandbox: Boolean;
    SaveFile: Boolean;
    AllPlugins: Boolean;
    Caption: PResStringRec;
    ActionName: string;
  end;

type
  TJclVersionControlPlugin = class (TObject)
  protected
    // get supported actions by the plugin
    function GetSupportedActionTypes: TJclVersionControlActionTypes; virtual;
    // get actions for the current file
    function GetFileActions(const FileName: TFileName): TJclVersionControlActionTypes; virtual;
    // get actions for the current sandbox (sandbox can be not yet initialized)
    function GetSandboxActions(const SdBxName: TFileName): TJclVersionControlActionTypes; virtual;
    // true if the plugin is supported (third-party tools present)
    function GetEnabled: Boolean; virtual;
    // friendly name of the plugin
    function GetName: string; virtual;
  public
    constructor Create; virtual;
    destructor Destroy; override;
    // returns sandbox names
    // returns true and initialized sandbox names if presents
    // returns false and all parent directories names if no sandbox is present
    function GetSandboxNames(const FileName: TFileName; SdBxNames: TStrings): Boolean; virtual;
    // execute the action of a file or on a sandbox
    function ExecuteAction(const FileName: TFileName;
      const Action: TJclVersionControlActionType): Boolean; virtual;
    property SupportedActionTypes: TJclVersionControlActionTypes read
        GetSupportedActionTypes;
    property FileActions[const FileName: TFileName]: TJclVersionControlActionTypes read GetFileActions;
    property SandboxActions[const SdBxName: TFileName]: TJclVersionControlActionTypes read GetSandboxActions;
    property Enabled: Boolean read GetEnabled;
    property Name: string read GetName;
  end;

  TJclVersionControlPluginClass = class of TJclVersionControlPlugin;

  TJclVersionControlCache = class (TObject)
  private
    FSandboxList: TList;
    FFileName: TFileName;
    FPlugin: TJclVersionControlPlugin;
    FActions: TJclVersionControlActionTypes;
    FValidityTime: TDateTime;
    FSupported: Boolean;
    function GetSandBox(Index: Integer): TFileName;
    function GetSandboxAction(Index: Integer): TJclVersionControlActionTypes;
    function GetSandboxCount: Integer;
  public
    constructor Create(APlugin: TJclVersionControlPlugin; const AFileName: TFileName);
    destructor Destroy; override;
    function GetValid(const ATime: TDateTime): Boolean;
    property Plugin: TJclVersionControlPlugin read FPlugin;
    property FileName: TFileName read FFileName;
    property Actions: TJclVersionControlActionTypes read FActions;
    property SandBoxes[Index: Integer]: TFileName read GetSandBox;
    property SandBoxActions[Index: Integer]: TJclVersionControlActionTypes read GetSandboxAction;
    property SandBoxCount: Integer read GetSandboxCount;
    property Supported: Boolean read FSupported;
    property ValidityTime: TDateTime read FValidityTime;
  end;

  TJclVersionControlSystemPlugin = class (TJclVersionControlPlugin)
  protected
    function GetSupportedActionTypes: TJclVersionControlActionTypes; override;
    function GetFileActions(const FileName: TFileName): TJclVersionControlActionTypes; override;
    function GetSandboxActions(const SdBxName: TFileName): TJclVersionControlActionTypes; override;
    function GetEnabled: Boolean; override;
    function GetName: string; override;
  public
    function GetSandboxNames(const FileName: TFileName; SdBxNames: TStrings): Boolean; override;
    function ExecuteAction(const FileName: TFileName;
      const Action: TJclVersionControlActionType): Boolean; override;
  end;

  TJclVersionControlPluginList = class (TObject)
  private
    FFileCache: TList;
    FPluginList: TObjectList;
    procedure ClearFileCache;
    function GetPlugin(Index: Integer): TJclVersionControlPlugin;
  public
    constructor Create;
    destructor Destroy; override;
    function Count: Integer;
    function GetFileCache(const FileName: TFileName;
      const Plugin: TJclVersionControlPlugin): TJclVersionControlCache;
    //1 Returns the number of enabled plugin classes, which implicit shows if there is any versioncontrol system installed
    function NumberOfEnabledPlugins: Integer;
    procedure RegisterPluginClass(const APluginClass: TJclVersionControlPluginClass);
    procedure UnregisterPluginClass(const APluginClass: TJclVersionControlPluginClass);
    property Plugins[Index: Integer]: TJclVersionControlPlugin read GetPlugin;
  end;

  TJclVersionControlActionsCache = class (TObject)
  private
    FSandbox: string;
    FActionTypes: TJclVersionControlActionTypes;
  public
    constructor Create(ASandbox: string; AActionTypes:
        TJclVersionControlActionTypes);
    property Sandbox: string read FSandbox;
    property ActionTypes: TJclVersionControlActionTypes read FActionTypes;
  end;

function VersionControlPluginList: TJclVersionControlPluginList;
procedure RegisterVersionControlPluginClass(const APluginClass: TJclVersionControlPluginClass);
procedure UnRegisterVersionControlPluginClass(const APluginClass:
    TJclVersionControlPluginClass);
function VersionControlActionInfo(ActionType : TJclVersionControlActionType):
    TJclVersionControlActionInfo;

{$IFDEF UNITVERSIONING}
const
  UnitVersioning: TUnitVersionInfo = (
    RCSfile: '$URL: https://jcl.svn.sourceforge.net/svnroot/jcl/tags/JCL-2.1-Build3536/jcl/source/vcl/JclVersionControl.pas $';
    Revision: '$Revision: 3007 $';
    Date: '$Date: 2009-09-12 22:52:07 +0200 (sam., 12 sept. 2009) $';
    LogPath: 'JCL\source\vcl';
    Extra: '';
    Data: nil
    );
{$ENDIF UNITVERSIONING}

implementation

uses
  Windows, Forms, TypInfo,
  JclVclResources, JclFileUtils, JclRegistry, JclShell, JclStrings;

//=== JclVersionControl.pas ===================================================
const
  // vcaAdd
  JclVersionCtrlAddActionName = 'JclVersionCtrlAddCommand';
  // vcaAddSandbox
  JclVersionCtrlAddSandboxActionName = 'JclVersionCtrlAddSandboxCommand';
  // vcaBlame
  JclVersionCtrlBlameActionName = 'JclVersionCtrlBlameCommand';
  // vcaBranch
  JclVersionCtrlBranchActionName = 'JclVersionCtrlBranchCommand';
  // vcaBranchSandbox
  JclVersionCtrlBranchSandboxActionName = 'JclVersionCtrlBranchSandboxCommand';
  // vcaCheckoutSandbox
  JclVersionCtrlCheckoutSandboxActionName = 'JclVersionCtrlCheckOutSandboxCommand';
  // vcaCommit
  JclVersionCtrlCommitActionName = 'JclVersionCtrlCommitCommand';
  // vcaCommitSandbox
  JclVersionCtrlCommitSandboxActionName = 'JclVersionCtrlCommitSandboxCommand';
  // vcaContextMenu
  JclVersionCtrlContextMenuActionName = 'JclVersionCtrlContextMenuCommand';
  // vcaDiff
  JclVersionCtrlDiffActionName = 'JclVersionCtrlDiffCommand';
  // vcaExplore
  JclVersionCtrlExploreActionName = 'JclVersionCtrlExploreCommand';
  // vcaExploreSandbox
  JclVersionCtrlExploreSandboxActionName = 'JclVersionCtrlExploreSandboxCommand';
  // vcaGraph
  JclVersionCtrlGraphActionName = 'JclVersionCtrlGraphCommand';
  // vcaLog
  JclVersionCtrlLogActionName = 'JclVersionCtrlLogCommand';
  // vcaLogSandbox
  JclVersionCtrlLogSandboxActionName = 'JclVersionCtrlLogSandboxCommand';
  // vcaLock
  JclVersionCtrlLockActionName = 'JclVersionCtrlLockCommand';
  // vcaLockSandbox
  JclVersionCtrlLockSandboxActionName = 'JclVersionCtrlLockSandboxCommand';
  // vcaMerge
  JclVersionCtrlMergeActionName = 'JclVersionCtrlMergeCommand';
  // vcaMergeSandbox
  JclVersionCtrlMergeSandboxActionName = 'JclVersionCtrlMergeSandboxCommand';
  // vcaProperties
  JclVersionCtrlPropertiesActionName = 'JclVersionCtrlPropertiesCommand';
  // vcaPropertiesSandbox
  JclVersionCtrlPropertiesSandboxActionName = 'JclVersionCtrlPropertiesSandboxCommand';
  // vcaRename
  JclVersionCtrlRenameActionName = 'JclVersionCtrlRenameCommand';
  // vcaRenameSandBox
  JclVersionCtrlRenameSandboxActionName = 'JclVersionCtrlRenameSandboxCommand';
  // vcaRepoBrowser
  JclVersionCtrlRepoBrowserActionName = 'JclVersionCtrlRepoBrowserCommand';
  // vcaRevert
  JclVersionCtrlRevertActionName = 'JclVersionCtrlRevertCommand';
  // vcaRevertSandbox
  JclVersionCtrlRevertSandboxActionName = 'JclVersionCtrlRevertSandboxCommand';
  // vcaStatus
  JclVersionCtrlStatusActionName = 'JclVersionCtrlStatusCommand';
  // vcaStatusSandbox
  JclVersionCtrlStatusSandboxActionName = 'JclVersionCtrlStatusSandboxCommand';
  // vcaTag
  JclVersionCtrlTagActionName = 'JclVersionCtrlTagCommand';
  // vcaTagSandBox
  JclVersionCtrlTagSandboxActionName = 'JclVersionCtrlTagSandboxCommand';
  // vcaUpdate
  JclVersionCtrlUpdateActionName = 'JclVersionCtrlUpdateCommand';
  // vcaUpdateSandbox
  JclVersionCtrlUpdateSandboxActionName = 'JclVersionCtrlUpdateSandboxCommand';
  // vcaUpdateTo
  JclVersionCtrlUpdateToActionName = 'JclVersionCtrlUpdateToCommand';
  // vcaUpdateSandboxTo
  JclVersionCtrlUpdateSandboxToActionName = 'JclVersionCtrlUpdateSandboxToCommand';
  // vcaUnlock
  JclVersionCtrlUnlockActionName = 'JclVersionCtrlUnlockCommand';
  // vcaUnlockSandbox
  JclVersionCtrlUnlockSandboxActionName = 'JclVersionCtrlUnlockSandboxCommand';

  JclVersionCtrlActOnTopSandboxName = 'ActOnTopSandbox';
  JclVersionCtrlMenuOrganizationName = 'MenuOrganization';
  JclVersionCtrlSaveConfirmationName = 'SaveConfirmation';
  JclVersionCtrlDisableActionsName = 'DisableActions';
  JclVersionCtrlHideActionsName = 'HideActions';
  JclVersionCtrlIconTypeName = 'IconType';
  JclVersionCtrlIconTypeNoIconValue = 'noicon';
  JclVersionCtrlIconTypeJclIconValue = 'jclicons';

{$G+}

const
  VersionControlActionInfos: array [TJclVersionControlActionType] of TJclVersionControlActionInfo =
   ( (SandBox: False;                          // vcaAdd
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlAddCaption;
      ActionName: JclVersionCtrlAddActionName),
     (SandBox: True;                           // vcaAddSandbox
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlAddSandboxCaption;
      ActionName: JclVersionCtrlAddSandboxActionName),
     (SandBox: False;                          // vcaBlame
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlBlameCaption;
      ActionName: JclVersionCtrlBlameActionName),
     (SandBox: False;                          // vcaBranch
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlBranchCaption;
      ActionName: JclVersionCtrlBranchActionName),
     (SandBox: True;                           // vcaBranchSandbox
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlBranchSandboxCaption;
      ActionName: JclVersionCtrlBranchSandboxActionName),
     (SandBox: True;                           // vcaCheckOutSandbox
      SaveFile: True;
      AllPlugins: True;
      Caption: @RsVersionCtrlCheckOutSandboxCaption;
      ActionName: JclVersionCtrlCheckOutSandboxActionName),
     (SandBox: False;                          // vcaCommit
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlCommitCaption;
      ActionName: JclVersionCtrlCommitActionName),
     (SandBox: True;                           // vcaCommitSandbox
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlCommitSandboxCaption;
      ActionName: JclVersionCtrlCommitSandboxActionName),
     (SandBox: False;                          // vcaContextMenu
      SaveFile: False;
      AllPlugins: True;
      Caption: @RsVersionCtrlContextMenuCaption;
      ActionName: JclVersionCtrlContextMenuActionName),
     (SandBox: False;                          // vcaDiff
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlDiffCaption;
      ActionName: JclVersionCtrlDiffActionName),
     (SandBox: False;                           // vcaExplore
      SaveFile: False;
      AllPlugins: True;
      Caption: @RsVersionCtrlExploreCaption;
      ActionName: JclVersionCtrlExploreActionName),
     (SandBox: True;                           // vcaExploreSandbox
      SaveFile: False;
      AllPlugins: True;
      Caption: @RsVersionCtrlExploreSandboxCaption;
      ActionName: JclVersionCtrlExploreSandboxActionName),
     (SandBox: False;                          // vcaGraph
      SaveFile: False;
      AllPlugins: False;
      Caption: @RsVersionCtrlGraphCaption;
      ActionName: JclVersionCtrlGraphActionName),
     (SandBox: False;                          // vcaLog
      SaveFile: False;
      AllPlugins: False;
      Caption: @RsVersionCtrlLogCaption;
      ActionName: JclVersionCtrlLogActionName),
     (SandBox: True;                           // vcaLogSandbox
      SaveFile: False;
      AllPlugins: False;
      Caption: @RsVersionCtrlLogSandboxCaption;
      ActionName: JclVersionCtrlLogSandboxActionName),
     (SandBox: False;                          // vcaLock
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlLockCaption;
      ActionName: JclVersionCtrlLockActionName),
     (SandBox: True;                           // vcaLockSandbox
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlLockSandboxCaption;
      ActionName: JclVersionCtrlLockSandboxActionName),
     (SandBox: False;                          // vcaMerge
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlMergeCaption;
      ActionName: JclVersionCtrlMergeActionName),
     (SandBox: True;                           // vcaMergeSandbox
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlMergeSandboxCaption;
      ActionName: JclVersionCtrlMergeSandboxActionName),
     (SandBox: False;                          // vcaProperties
      SaveFile: True;
      AllPlugins: True;
      Caption: @RsVersionCtrlPropertiesCaption;
      ActionName: JclVersionCtrlPropertiesActionName),
     (SandBox: True;                           // vcaPropertiesSandbox
      SaveFile: True;
      AllPlugins: True;
      Caption: @RsVersionCtrlPropertiesSandboxCaption;
      ActionName: JclVersionCtrlPropertiesSandboxActionName),
     (SandBox: False;                          // vcaRename
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlRenameCaption;
      ActionName: JclVersionCtrlRenameActionName),
     (SandBox: True;                          // vcaRenameSandbox
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlRenameSandboxCaption;
      ActionName: JclVersionCtrlRenameSandboxActionName),
     (SandBox: False;                          // vcaRepoBrowser
      SaveFile: False;
      AllPlugins: False;
      Caption: @RsVersionCtrlRepoBrowserCaption;
      ActionName: JclVersionCtrlRepoBrowserActionName),
     (SandBox: False;                          // vcaRevert
      SaveFile: False;
      AllPlugins: False;
      Caption: @RsVersionCtrlRevertCaption;
      ActionName: JclVersionCtrlRevertActionName),
     (SandBox: True;                           // vcaRevertSandbox
      SaveFile: False;
      AllPlugins: False;
      Caption: @RsVersionCtrlRevertSandboxCaption;
      ActionName: JclVersionCtrlRevertSandboxActionName),
     (SandBox: False;                          // vcaStatus
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlStatusCaption;
      ActionName: JclVersionCtrlStatusActionName),
     (SandBox: True;                           // vcaStatusSandbox
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlStatusSandboxCaption;
      ActionName: JclVersionCtrlStatusSandboxActionName),
     (SandBox: False;                          // vcaTag
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlTagCaption;
      ActionName: JclVersionCtrlTagActionName),
     (SandBox: True;                           // vcaTagSandBox
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlTagSandboxCaption;
      ActionName: JclVersionCtrlTagSandboxActionName),
     (SandBox: False;                          // vcaUpdate
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlUpdateCaption;
      ActionName: JclVersionCtrlUpdateActionName),
     (SandBox: True;                           // vcaUpdateSandbox
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlUpdateSandboxCaption;
      ActionName: JclVersionCtrlUpdateSandboxActionName),
     (SandBox: False;                          // vcaUpdateTo
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlUpdateToCaption;
      ActionName: JclVersionCtrlUpdateToActionName),
     (SandBox: True;                           // vcaUpdateSandboxTo
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlUpdateSandboxToCaption;
      ActionName: JclVersionCtrlUpdateSandboxToActionName),
     (SandBox: False;                          // vcaUnlock
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlUnlockCaption;
      ActionName: JclVersionCtrlUnlockActionName),
     (SandBox: True;                           // vcaUnlockSandbox
      SaveFile: True;
      AllPlugins: False;
      Caption: @RsVersionCtrlUnlockSandboxCaption;
      ActionName: JclVersionCtrlUnlockSandboxActionName)
   );

var
  GlobalPluginList: TJclVersionControlPluginList = nil;

function VersionControlPluginList: TJclVersionControlPluginList;
begin
  if not Assigned(GlobalPluginList) then
    GlobalPluginList := TJclVersionControlPluginList.Create;
  Result:= GlobalPluginList;
end;

procedure RegisterVersionControlPluginClass(const
    APluginClass: TJclVersionControlPluginClass);
begin
  VersionControlPluginList.RegisterPluginClass(APluginClass);
end;

procedure UnRegisterVersionControlPluginClass(const
    APluginClass: TJclVersionControlPluginClass);
begin
  VersionControlPluginList.UnregisterPluginClass(APluginClass);
end;

function VersionControlActionInfo(
  ActionType: TJclVersionControlActionType): TJclVersionControlActionInfo;
begin
  Result := VersionControlActionInfos[ActionType];
end;

//=== { TJclVersionControlPlugin } ============================================

constructor TJclVersionControlPlugin.Create;
begin
  inherited Create;
end;

destructor TJclVersionControlPlugin.Destroy;
begin
  inherited Destroy;
end;

function TJclVersionControlPlugin.ExecuteAction(const FileName: TFileName;
  const Action: TJclVersionControlActionType): Boolean;
begin
  Result := False;
end;

function TJclVersionControlPlugin.GetEnabled: Boolean;
begin
  Result := False;
end;

function TJclVersionControlPlugin.GetFileActions(
  const FileName: TFileName): TJclVersionControlActionTypes;
begin
  Result := [];
end;

function TJclVersionControlPlugin.GetSupportedActionTypes:
    TJclVersionControlActionTypes;
begin
  Result := [];
end;

function TJclVersionControlPlugin.GetName: string;
begin
  Result := '';
end;

function TJclVersionControlPlugin.GetSandboxActions(
  const SdBxName: TFileName): TJclVersionControlActionTypes;
begin
  Result := [];
end;

function TJclVersionControlPlugin.GetSandboxNames(const FileName: TFileName;
  SdBxNames: TStrings): Boolean;
var
  Index: Integer;
begin
  Result := False;
  
  SdBxNames.BeginUpdate;
  try
    SdBxNames.Clear;
    for Index := Length(FileName) downto 1 do
      if FileName[Index] = DirDelimiter then
    begin
      SdBxNames.Add(Copy(FileName, 1, Index));
    end;
  finally
    SdBxNames.EndUpdate;
  end;
end;

//=== TJclVersionControlCache ================================================

constructor TJclVersionControlCache.Create(APlugin: TJclVersionControlPlugin;
  const AFileName: TFileName);
var
  Index: Integer;
  SandboxNames: TStrings;
begin
  inherited Create;

  FSandboxList := TList.Create;
  FFileName := AFileName;
  FPlugin := APlugin;
  // TODO: cache time validity customization
  FValidityTime := Now + 5.0 / SecsPerDay;
  FActions := APlugin.FileActions[FileName];

  SandboxNames := TStringList.Create;
  try
    FSupported := APlugin.GetSandboxNames(FileName, SandboxNames);

    for Index := 0 to SandboxNames.Count - 1 do
      FSandboxList.Add(TJclVersionControlActionsCache.Create(SandboxNames.Strings[Index], APlugin.SandboxActions[SandboxNames.Strings[Index]]));
  finally
    SandboxNames.Free;
  end;
end;

destructor TJclVersionControlCache.Destroy;
var
  Index: Integer;
begin
  for Index := 0 to FSandboxList.Count - 1 do
    TJclVersionControlActionsCache(FSandboxList.Items[Index]).Free;
  FSandboxList.Free;
  
  inherited Destroy;
end;

function TJclVersionControlCache.GetSandBox(Index: Integer): TFileName;
begin
  Result := TJclVersionControlActionsCache(FSandboxList.Items[Index]).Sandbox;
end;

function TJclVersionControlCache.GetSandboxAction(
  Index: Integer): TJclVersionControlActionTypes;
begin
  Result := TJclVersionControlActionsCache(FSandboxList.Items[Index]).ActionTypes;
end;

function TJclVersionControlCache.GetSandboxCount: Integer;
begin
  Result := FSandboxList.Count;
end;

function TJclVersionControlCache.GetValid(const ATime: TDateTime): Boolean;
begin
  Result := (ATime - FValidityTime) > 0;
end;

//=== TJclVersionControlSystemPlugin =========================================

function TJclVersionControlSystemPlugin.ExecuteAction(const FileName: TFileName;
  const Action: TJclVersionControlActionType): Boolean;
begin
  case Action of
    vcaContextMenu:
      Result := DisplayContextMenu(0, FileName, Mouse.CursorPos);
    vcaExplore:
      Result := OpenFolder(PathExtractFileDirFixed(FileName), Application.Handle, True);
    vcaExploreSandbox:
      Result := OpenFolder(FileName, Application.Handle, True);
    vcaProperties,
    vcaPropertiesSandbox:
      Result := DisplayPropDialog(Application.Handle, FileName);
    else
      Result := inherited ExecuteAction(FileName, Action);
  end;
end;

function TJclVersionControlSystemPlugin.GetEnabled: Boolean;
begin
  Result := True;
end;

function TJclVersionControlSystemPlugin.GetFileActions(
  const FileName: TFileName): TJclVersionControlActionTypes;
begin
  Result := [vcaContextMenu, vcaExplore, vcaExploreSandbox, vcaProperties, vcaPropertiesSandbox];
end;

function TJclVersionControlSystemPlugin.GetName: string;
begin
  Result := 'System';
end;

function TJclVersionControlSystemPlugin.GetSandboxActions(
  const SdBxName: TFileName): TJclVersionControlActionTypes;
begin
  Result := [vcaExploreSandbox, vcaPropertiesSandbox];
end;

function TJclVersionControlSystemPlugin.GetSandboxNames(const FileName: TFileName;
  SdBxNames: TStrings): Boolean;
begin
  Result := inherited GetSandboxNames(FileName, SdBxNames);
end;

function TJclVersionControlSystemPlugin.GetSupportedActionTypes: TJclVersionControlActionTypes;
begin
  Result := [vcaContextMenu, vcaExplore, vcaExploreSandbox, vcaProperties, vcaPropertiesSandbox];
end;

constructor TJclVersionControlActionsCache.Create(ASandbox: string;
    AActionTypes: TJclVersionControlActionTypes);
begin
  inherited Create;
  FSandbox := ASandbox;
  FActionTypes := AActionTypes;
end;

constructor TJclVersionControlPluginList.Create;
begin
  inherited Create;
  FFileCache := TList.Create;
  FPluginList := TObjectList.Create(True);
end;

destructor TJclVersionControlPluginList.Destroy;
begin
  FreeAndNil(FPluginList);
  ClearFileCache;
  FreeAndNil(FFileCache);
  inherited Destroy;
end;

procedure TJclVersionControlPluginList.ClearFileCache;
var
  Index: Integer;
begin
  for Index := FFileCache.Count - 1 downto 0 do
    TJclVersionControlCache(FFileCache.Items[Index]).Free;
  FFileCache.Clear;
end;

function TJclVersionControlPluginList.Count: Integer;
begin
  Result := FPluginList.Count;
end;

function TJclVersionControlPluginList.GetFileCache(const FileName: TFileName;
    const Plugin: TJclVersionControlPlugin): TJclVersionControlCache;
var
  Index: Integer;
  AFileCache: TJclVersionControlCache;
  ATime: TDateTime;
begin
  ATime := Now;
  Result := nil;

  for Index := FFileCache.Count - 1 downto 0 do
  begin
    AFileCache := TJclVersionControlCache(FFileCache.Items[Index]);
    if AFileCache.GetValid(ATime) then
    begin
      AFileCache.Free;
      FFileCache.Delete(Index);
    end
    else
    if (AFileCache.FileName = FileName) and (AFileCache.Plugin = Plugin) then
    begin
      Result := AFileCache;
      Break;
    end;
  end;
  if not Assigned(Result) then
  begin
    Result := TJclVersionControlCache.Create(Plugin, FileName);
    FFileCache.Add(Result);
  end;
end;

function TJclVersionControlPluginList.NumberOfEnabledPlugins: Integer;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to FPluginList.Count - 1 do
    if TJclVersionControlPlugin(FPluginList.Items[i]).Enabled and
      not (TJclVersionControlPlugin(FPluginList.Items[i]) is TJclVersionControlSystemPlugin) then
      Inc(Result);
end;

function TJclVersionControlPluginList.GetPlugin(Index: Integer):
    TJclVersionControlPlugin;
begin
  Result := TJclVersionControlPlugin(FPluginList[Index]);
end;

procedure TJclVersionControlPluginList.RegisterPluginClass(
  const APluginClass: TJclVersionControlPluginClass);
begin
  FPluginList.Add(APluginClass.Create);
end;

procedure TJclVersionControlPluginList.UnregisterPluginClass(
  const APluginClass: TJclVersionControlPluginClass);
var
  Index: Integer;
  APlugin: TJclVersionControlPlugin;
  AFileCache: TJclVersionControlCache;
begin
  for Index := FFileCache.Count -1 downto 0 do
  begin
    AFileCache := TJclVersionControlCache(FFileCache.Items[Index]);
    if Assigned(AFileCache.Plugin) and (AFileCache.Plugin.ClassType = APluginClass) then
    begin
      AFileCache.Free;
      FFileCache.Delete(Index);
    end;
  end;
  for Index := FPluginList.Count - 1 downto 0 do
  begin
    APlugin := TJclVersionControlPlugin(FPluginList.Items[Index]);
    if APlugin.ClassType = APluginClass then
      FPluginList.Delete(Index);
  end;
end;


initialization
  {$IFDEF UNITVERSIONING}
  RegisterUnitVersion(HInstance, UnitVersioning);
  {$ENDIF UNITVERSIONING}

  RegisterVersionControlPluginClass(TJclVersionControlSystemPlugin);

finalization

  UnregisterVersionControlPluginClass(TJclVersionControlSystemPlugin);
  FreeAndNil(GlobalPluginList);

  {$IFDEF UNITVERSIONING}
  UnregisterUnitVersion(HInstance);
  {$ENDIF UNITVERSIONING}

end.
