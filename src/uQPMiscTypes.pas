unit uQPMiscTypes;

interface

uses uQPConst;

type

  TQPExtractDest = (qemROMDir=0, qemQPDir=1, qemSysTempDir=2, qemGeneral=3);
  TExtractDestStr = Array[TQPExtractDest] of String;
  PQPExtractDest = ^TQPExtractDest;

  TQPRunOptions = record
    GeneralPowerScheme : String;
    ExtractMode : TQPExtractDest;
    ExtractDir : String;
  end;

  //controls the jump mode on the main form
  TQPRefresh = (QPRClone, QPRNone, QPRPath, QPRZip);

  //controls which mode the MAME icons is in
  TQPMAMEIconMode = (qmiOff=0, qmiDir=1, qmiZip=2);

  TQPFolderExpandMode = (qfeFull=0, qfefirstlevel=1, qfeNone=2);

  //when scanning, controls what type of rating to give.
  TQPRatingsMode = (qprDefault = 1,
                    qprStars = 2,
                    qprNumeric = 3,
                    qprCustom = 4);
  //mode of export operations
  TQPExportMode = (emAll, emSys, emEmu, emMissing, emAllDirs);
  //format of export operations
  TQPExportFormat = (efHTML, efXML, efText);

  //when scanning decides what languages to give ROMS
  TQPLanguageMode = (lmEnglish, lmNone, lmGuess);

  TQPEmuAssignResult = (qparError, qparOK, qparOKReload);
  TQPEmuToStrings = (cfAllEmus, cfMame, cfMameArcade, cfEmuBySys, cfZinc);

  TQPEditType = (qpeEdit,         //creates a standard text edit.
                 qpeCombo,        //creates a combo, and calls DoCustomPrepare to get items
                 qpeComboEmu,     //creates combo with emulators preloaded
                 qpeComboSys,     //creates combo with systems preloaded
                 qpeComboRating,  //creates combo with ratings preloaded
                 qpeComboLang,    //creates combo with languages preloaded
                 qpeComboType,    //creates combo with game types preloaded
                 qpeComboBoolean, //creates combo with boolean values preloaded.
                 qpeCustom,      //calls DoCustomPrepare and loads whatever it finds.
                 qpeDirectoryEdit, //Creates a jvDirectoryEdit and preloads directory.
                 qpeFileEdit,    //creates a jvFileEdit and preloads filename.
                 qpeFileExeEdit, //Creates a jvFileEdit and configures it to look for apps
                 qpeROMParamMode, //creates parameter mode combo box.
                 qpePowerSchemes,  //creates combo with all power schemes listed.
                 qpeExtractDest,  //creates combo with all Emu-specific extraction destinations
                 qpePriority      //creates combo with process launch priority types
                 );

  TQPEmuOptHead = (qpesStandard = 0,
                   qpesLaunch = 1,
                   qpesCmdLine = 2,
                   qpesCmdLineOpt = 3,
                   qpesCompress = 4,
                   qpesTools = 5,
                   qpesWin = 6);
                   
  TQPEmuOptHeadStr = Array[TQPEmuOptHead] of String;

  TQPDataType = (qpString, qpStringNotNull, qpInteger, qpBoolean, qpEmuCompress, qpExtractDest, qpPriority);

  TROMParametersMode = (paramAfter=0,
                        paramOverwrite=1,
                        paramBefore=2,
                        paramAfterNoSpace=3,
                        paramBeforeNoSpace=4);
  TROMParametersModeStr = Array[TROMParametersMode] of String;

const
    ROMParametersStrings: TROMParametersModeStr = (QP_ROM_PARAM_AFTER,
                                                 QP_ROM_PARAM_OVERWRITE,
                                                 QP_ROM_PARAM_BEFORE,
                                                 QP_ROM_PARAM_AFTER_NOSPACE,
                                                 QP_ROM_PARAM_BEFORE_NOSPACE);

    ExtractDestStr: TExtractDestStr = (QP_EXTRACT_ROM_DIR,
                                       QP_EXTRACT_QP_TEMP,
                                       QP_EXTRACT_SYS_TEMP,
                                       QP_EXTRACT_GENERAL);

implementation

end.
