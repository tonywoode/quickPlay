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
{ The Original Code is JclOtaConsts.pas.                                                           }
{                                                                                                  }
{ The Initial Developer of the Original Code is Petr Vones.                                        }
{ Portions created by Petr Vones are Copyright (C) of Petr Vones.                                  }
{                                                                                                  }
{ Contributors:                                                                                    }
{   Florent Ouchet (outchy)                                                                        }
{   Uwe Schuster (uschuster)                                                                       }
{                                                                                                  }
{**************************************************************************************************}
{                                                                                                  }
{ Last modified: $Date:: 2009-09-23 00:01:46 +0200 (mer., 23 sept. 2009)                         $ }
{ Revision:      $Rev:: 3020                                                                     $ }
{ Author:        $Author:: outchy                                                                $ }
{                                                                                                  }
{**************************************************************************************************}

unit JclOtaConsts;

interface

{$I jcl.inc}

uses
  {$IFDEF UNITVERSIONING}
  JclUnitVersioning,
  {$ENDIF UNITVERSIONING}
  ToolsAPI;

const
  DelphiRootDirKeyValue = 'RootDir';
  RegJclKey             = 'Jedi\JCL\';
  RegJclIDEKey          = RegJclKey + 'IDE\';
  DelphiEnvironmentVar  = 'DELPHI';
  EnvironmentVarsKey    = 'Environment Variables';

  //=== Various constants shared by different experts ========================
  JclLeft   = 'Left';
  JclTop    = 'Top';
  JclWidth  = 'Right';
  JclHeight = 'Height';

  JclDesignerAny = dAny;
  JclDesignerVcl = dVcl;
  JclDelphiPersonality = {$IFDEF BDS} sDelphiPersonality {$ELSE BDS} '' {$ENDIF BDS};
  JclCBuilderPersonality = {$IFDEF BDS} sCBuilderPersonality {$ELSE BDS} '' {$ENDIF BDS};
  MapFileOptionDetailed = 3;
  MapFileOptionDetailedSegments = 'DetailedSegments';

  //=== Configuration ========================================================
  JclConfigurationSettings = 'JclExpertConfigurationForm';
  JclActionSettings = 'Actions';

  //=== Configuration form ===================================================
  JclPanelTreeWidth      = 'PanelTreeWidth';
  JclConfigureActionName = 'JCLConfigureCommand';
  JclConfigureMenuName   = 'JCLConfigureMenu';

  //=== Debug Expert =========================================================
  JclDebugExpertRegKey          = 'JclDebugExpert';
  JclDebugEnabledRegValue       = 'JclDebugEnabled';
  JclDebugGenerateJdbgRegValue  = 'JclDebugGenerateJdbg';
  JclDebugInsertJdbgRegValue    = 'JclDebugInsertJdbg';
  JclDebugDeleteMapFileRegValue = 'JclDebugDeleteMapFile';
  MapFileOptionName             = 'MapFile';
  DccMapFileOptionName          = 'DCC_MapFile';
  ILinkMapFileTypeOptionName    = 'ILINK_MapFileType';
  OutputDirOptionName           = 'OutputDir';
  FinalOutputDirOptionName      = 'FinalOutputDir';
  RuntimeOnlyOptionName         = 'RuntimeOnly';
  PkgDllDirOptionName           = 'PkgDllDir';
  BPLOutputDirOptionName        = 'PackageDPLOutput';
  LIBPREFIXOptionName           = 'SOPrefix';
  LIBSUFFIXOptionName           = 'SOSuffix';
  ColumnRegName                 = 'Column%d';
  JclDebugMessagePrefix         = 'Jcl Debug Expert';
  JclDebugExpertActionName      = 'JCLDebugExpertCommand';
  JclDebugExpertMenuName        = 'JCLDebugExpertMenu';
  JclDebugExpertProjMenuName    = 'JCLDebugExpertProjMenu';
  JclGenerateJdbgActionName     = 'JCLGenerateJdbgCommand';
  JclGenerateJdbgMenuName       = 'JCLGenerateJdbgMenu';
  JclGenerateJdbgProjMenuName   = 'JCLGenerateJdbgProjMenu';
  JclInsertJdbgActionName       = 'JCLInsertJdbgCommand';
  JclInsertJdbgMenuName         = 'JCLInsertJdbgMenu';
  JclInsertJdbgProjMenuName     = 'JCLInsertJdbgProjMenu';
  JclDeleteMapFileActionName    = 'JCLDeleteMapFileCommand';
  JclDeleteMapFileMenuName      = 'JCLDeleteMapFileMenu';
  JclDeleteMapFileProjMenuName  = 'JCLDeleteMapFileProjMenu';
  JclDebugGenerateJdbgSetting   = 'JCL_DEBUG_EXPERT_GENERATEJDBG';
  JclDebugInsertJdbgSetting     = 'JCL_DEBUG_EXPERT_INSERTJDBG';
  JclDebugDeleteMapfileSetting  = 'JCL_DEBUG_EXPERT_DELETEMAPFILE';

  //=== Favorite Folders Expert ==============================================
  JclFavoritesExpertName     = 'JclFavoriteFoldersExpert';
  JclFavoritesListSubKey     = 'Favorites';
  PictDialogFolderItemName   = 'PictureDialogPath';
  BorlandImagesPath          = 'Borland Shared\Images';

  //=== Threads Expert =======================================================
  JclThreadsExpertName = 'JclThreadsExpert';

  //=== SIMD Expert ==========================================================
  JclSIMDExpertName = 'JclSIMDExpert';
  JclSIMDActionName = 'JCLSIMDCommand';
  JclSIMDMenuName   = 'JCLSIMDMenu';

  //=== Uses Expert ==========================================================
  JclUsesExpertName   = 'JclUsesExpert';
  SIniIdentifierLists = 'IdentifierLists';
  SRegDebugLibPath    = 'Debug Library';
  SRegLibPath         = 'Library';
  SRegWizardActive    = 'Uses Wizard Active';
  SRegWizardConfirm   = 'Uses Wizard Confirm';
  SRegWizardIniFile   = 'Configuration File';
  JclRootDirValueName = 'RootDir';
  JclIniFileLocation  = 'experts\useswizard\JediUsesWizard.ini';

  //=== Project analyser =====================================================
  JclProjectAnalyzerExpertName = 'JclProjectAnalyzerExpert';
  AnalyzerViewName             = 'AnalyzerView';
  AnalyzerShowPackagesName     = 'ShowPackages';
  JclProjectAnalyzeActionName  = 'JCLProjectAnalyseCommand';
  JclProjectAnalyzeMenuName    = 'JCLProjectAnalyseMenu';

  //=== Repository Expert ====================================================
  JclRepositoryCategoryDelphiFiles = {$IFDEF BDS} sCategoryDelphiNewFiles {$ELSE BDS} '' {$ENDIF BDS};
  JclRepositoryCategoryCBuilderFiles = {$IFDEF BDS} sCategoryCBuilderNewFiles {$ELSE BDS} '' {$ENDIF BDS};
  JclRepositoryModuleTypeForm = omtForm;  

  //=== Version Control Expert ===============================================
  JclVersionCtrlMenuName = 'JclVersionCtrlMenu';
  JclVersionCtrlActOnTopSandboxName = 'ActOnTopSandbox';
  JclVersionCtrlMenuOrganizationName = 'MenuOrganization';
  JclVersionCtrlSaveConfirmationName = 'SaveConfirmation';
  JclVersionCtrlDisableActionsName = 'DisableActions';
  JclVersionCtrlHideActionsName = 'HideActions';
  JclVersionCtrlIconTypeName = 'IconType';
  JclVersionCtrlIconTypeAutoValue = 'auto';
  JclVersionCtrlIconTypeNoIconValue = 'noicon';
  JclVersionCtrlIconTypeJclIconValue = 'jclicons';

  //=== Stack Trace Viewer Expert ============================================
  JclStackTraceViewerExpertName        = 'JclStackTraceViewerExpert';
  JclStackTraceViewerActionName        = 'JCLStackTraceViewerCommand';
  JclStackTraceViewerMenuName          = 'JCLStackTraceViewerMenu';
  JclStackTraceViewerDesktopIniSection = 'JclStackTraceViewer';

{$IFDEF UNITVERSIONING}
const
  UnitVersioning: TUnitVersionInfo = (
    RCSfile: '$URL: https://jcl.svn.sourceforge.net/svnroot/jcl/tags/JCL-2.1-Build3536/jcl/experts/common/JclOtaConsts.pas $';
    Revision: '$Revision: 3020 $';
    Date: '$Date: 2009-09-23 00:01:46 +0200 (mer., 23 sept. 2009) $';
    LogPath: 'JCL\experts\common';
    Extra: '';
    Data: nil
    );
{$ENDIF UNITVERSIONING}

implementation

{$IFDEF UNITVERSIONING}
initialization
  RegisterUnitVersion(HInstance, UnitVersioning);

finalization
  UnregisterUnitVersion(HInstance);
{$ENDIF UNITVERSIONING}

end.
