unit uQPConst;

interface

ResourceString

// Resource Strings by section/unit

//Random words
QP_UNKNOWN = 'Unknown';
QP_ROMS = 'ROMs';
QP_MATCHES = 'Matches';
QP_EMU = 'Emulators';
QP_FAV = 'Favourites';
QP_UNCHANGED = 'Unchanged';

//utilties
QP_RUN_PROCESS_EMPTY = 'Empty string was passed to Run Process function';
QP_RUN_PROCESS_FAIL = 'The process could not be started, please check the application exists';

QP_ROMS_DATA_FILES_NOT_FOUND = 'There are no ROM datafiles found';
QP_ROMS_DATA_DIR_NOT_FOUND = 'The data directories were not found - they will be now be created';
QP_DRIVE_READ_ONLY = 'QuickPlay has detected that the drive you are running the program from is READ ONLY, therefore saving functionality has been disabled.';


//Emulator related
QP_EMULATOR_NOT_FOUND = 'Emulator Not Found';
QP_DELETE_ALL_LINKED_ROMS = 'Delete All roms linked to this emulator?';
QP_MAME_INI_NOT_FOUND = 'MAME.ini file not found, do you QuickPlay to create the default file?';
QP_MAME_GENERATE_DATA_ERR = 'Error generating data file.';
QP_EMU_DOESNT_SUPPORT_CMD = 'The emulator used to run this ROM does not support Command-lines, please change this ROM so that it points to an emulator that supports command-lines.';
QP_GET_ROM_PATH_FAILED = 'QuickPlay tried to generate a ROM path and failed.';
QP_GENERIC_RUN_FAILED = 'Running the ROM failed, please recheck ROM properties';
QP_CHANGE_RENAME_1 = '" has been renamed to "';
QP_CHANGE_RENAME_2 = '", update linked ROMs?';
QP_CHANGE_DELETED = '" has been deleted, delete all linked ROMs?';
QP_EMU_DELETE_ALL = 'Are you sure you wish to delete all your emulators?';
QP_EMU_DELETE_BY_SYS = 'Are you sure you want to delete all emulators linked to this system?';
QP_EMU_SELECT_ONE = 'Please select an emulator';

//TQPEmu property descriptions
QP_EMU_NAME = 'Name';
QP_EMU_VERSION = 'Version';
QP_EMU_PATH = 'Path';
QP_EMU_CFG = 'Config File';
QP_EMU_SYS = 'System';
QP_EMU_WWW = 'Home Page';
QP_EMU_PARAM = 'Parameters';
QP_EMU_CMDLINE = 'Supports Command Lines';
QP_EMU_SHELL = 'Integrates into Shell';
QP_EMU_LAUNCHER = 'Use External Launcher Application';
QP_EMU_COMPRESS = 'Emulator Supports Compressed Files';
QP_EMU_VERIFY = 'Verify compressed files before launch';
QP_EMU_EXE_SHORT = 'Use Short Name (8:3) For EXEs';
QP_EMU_SCREENSAVER = 'Disable Screensaver on Launch';
QP_EMU_WINKEY = 'Disable Window Key on Launch';
QP_EMU_PWRSCHEME = 'Change Power Scheme on Launch';
QP_EMU_PRELAUNCH = 'Command to run before launching ROMs';
QP_EMU_PRELAUNCH_WAIT = 'Wait for this command?';
QP_EMU_AFTERLAUNCH = 'Command to run after launching ROMs';
QP_EMU_AFTERLAUNCH_WAIT = 'Wait for this command?';
QP_EMU_EXTRACT_DESTINATION = 'Select destination for extracted ROMs';
QP_EMU_LAUNCH_PRIORITY = 'Run Emulator with custom Priority';

//TQPROM property descriptions
QP_ROM_NAME = 'Rom Name';
QP_ROM_NAME_SHORT = 'Name';
QP_ROM_FILENAME = 'FileName';
QP_ROM_PATH = 'Path';
QP_ROM_EMU  = 'Emulator';
QP_ROM_TYPE = 'Type';
QP_ROM_LANG = 'Language';
QP_ROM_RATING = 'Rating';
QP_ROM_YEAR = 'Year';
QP_ROM_PLAYERS = 'Players';
QP_ROM_COMMENT = 'Comment';
QP_ROM_COMPANY = 'Company';
QP_ROM_NUM_PLAY = 'Number of Times Played';
QP_ROM_PARAM = 'Parameters';
QP_ROM_OVERRIDE_PARAM = 'Parameters Mode';

//TROMParametersModeStr
QP_ROM_PARAM_AFTER = 'After Emulators';
QP_ROM_PARAM_OVERWRITE = 'Overwrite Emulators';
QP_ROM_PARAM_BEFORE = 'Before Emulators';
QP_ROM_PARAM_AFTER_NOSPACE = 'After Emulators with no space';
QP_ROM_PARAM_BEFORE_NOSPACE = 'Before Emulators with no space';

//TQPEmuOptHeadStr
QP_EMUOPT_GENERAL = 'General Options';
QP_EMUOPT_LAUNCH = 'Emulator Launching Options';
QP_EMUOPT_CMDLINE = 'Command Line Parameters';
QP_EMUOPT_CMDLINEOPT = 'Command Line Options';
QP_EMUOPT_COMPRESSION = 'Compression Support';
QP_EMUOPT_TOOLS = 'Run Command before/after Emulator Launch';
QP_EMUOPT_WIN = 'Windows Settings';

//ROM Related
QP_ROM_NOT_FOUND = 'ROM file not found';
QP_IPS_NOT_FOUND = 'IPS file not found.';
QP_IPS_NONE_IN_COMPRESSED = 'Compressed file does not contain any IPS files';
QP_IPS_NOT_VALID = 'Specified IPS file is not a valid patch';
QP_TOTAL_INVALID_REMOVED = ' invalid ROMs were removed';
QP_RANDOM_RUN_FAILURE = 'QuickPlay failed to pick a random ROM.';
QP_MIRROR_NOT_ENABLED = 'Mirroring is not enabled for the currently selected directory';
QP_MIRROR_NO_DIRECTORIES = 'No Directories have been specified to mirror.';
QP_NO_CATVER = 'Catver.ini file does not exist - please check the file is in the DATs Directory';
QP_NO_LANGUAGESINI = 'Languages.ini file does not exist - please check the file is in the DATs Directory';
QP_NO_NPLAYERS = 'nplayers.ini file does not exist - please check the file is in the DATs Directory';
QP_LINKED_EMU_NOT_FOUND = 'The emulator linked to this ROM was not found.';
QP_SELECT_ROM = 'Please Select The Rom';
QP_GM_CHOICE_ERROR = 'Unable to determine which ROM to launch, fatal error!';

//ratings
QP_RATING_5 = '5 - Excellent';
QP_RATING_4 = '4 - Good';
QP_RATING_3 = '3 - Average';
QP_RATING_2 = '2 - Poor';
QP_RATING_1 = '1 - Crap';

//query match type
QP_QUERY_CONTAIN = 'contains';
QP_QUERY_NOT_CONTAIN = 'does not contain';
QP_QUERY_EQUAL = 'equals';
QP_QUERY_NOT_EQUAL = 'does not equal';
QP_QUERY_NO_MATCHES = 'No Matches Found.';

//Main Form Strings
QP_MAINFRM_VIRTUAL = 'Virtual Folders';
QP_MAINFRM_NO_ROMS = 'No ROMs Found';
QP_MAINFRM_FILTER_1 = ' ROMs with ';
QP_MAINFRM_FILTER_2 = ' Filtered out';
QP_MAINFRM_NEW_FOL = 'New Folder';
QP_MAINFRM_ERROR_CLEARING = 'Error while Clearing ROMS';
QP_MAINFRM_RENAME_1 = 'Rename ';
QP_MAINFRM_RENAME_2 = 'Input new name for ';
QP_MAINFRM_DBLCLICK = 'Double-click to run';
QP_MAINFRM_NEWFOL = 'Add as new ROOT node?';
QP_MAINFRM_GMMERGE_CHILD_PROP = 'You cannot view properties of this item.';

//Backup Form Text
QP_BACKUP_MAKE_SELECTION = 'You need to select either Backup or Restore';
QP_BACKUP_CHOOSE_DIFF_FILE = 'I want to choose a different file';
QP_BACKUP_CHOOSE = 'CHOOSE';
QP_BACKUP_NO_RESTORE = 'No restore files are selected';

//custom ROM data form
QP_CUSTOM_EXPORT = 'Export Custom Data to File';
QP_CUSTOM_IMPORT = 'Import Custom Data';
QP_CUSTOM_SELECT = 'Please Select to import or export your data';
QP_CUSTOM_IMPORT_COMPLETE = 'Import Complete';
QP_CUSTOM_EXPORT_COMPLETE = 'Export Complete';
QP_CUSTOM_BAD_DIR = 'You tried to save the data file into a directory that does not exist.';

//Edit EmuFinder Data file Form
QP_EDITEFIND_BAD_NAME = 'No name supplied, record will not be saved, do you want to fix this error?';
QP_EDITEFIND_BAD_EXE = 'No EXE name, record will not be saved, do you want to fix this error?';
QP_EDITEFIND_BAD_SYS = 'No system supplied, record will not be saved, do you want to fix this error?';

//Emu Finder form
QP_EFIND_NO_FILES = 'No Emu-Finder data files were found, please check they exist - they should be located in a directory called EFIND in the main QuickPlay directory';
QP_EFIND_NO_DIR = 'EFIND Directory does not exist, please reinstall QuickPlay to obtain the Emu-Finder data files';

//Emulators form
QP_EMUFRM_NO_SYS = 'No current system found, please click a node on the Systems tree.';
QP_EMUFRM_NOT_EMPTY = ' cannot be empty';
QP_EMUFRM_NO_NAME_WARNING = 'Emulator(s) detected with no Name or Path.  This emulator will be deleted if you continue. '+#13+#10+'Do you wish to continue?';

//Find Form
QP_FINDFRM_VIRTUAL_NAME = 'Enter Virtual Search Name';
QP_FINDFRM_VIRTUAL_NAME_LONG = 'Please enter a name for your virtual folder';
QP_FINDFRM_NAME_TAKEN = 'This name is already taken.  Try again';
QP_FINDFRM_NAME_BLANK = 'You entered a blank string for the name.  Please try again.';
QP_FINDFRM_NO_RESULTS = 'There are no search results, you cannot save this query';

//Folder Options Form
QP_FOLOPTFRM_BAD_ICONS = 'These files are not valid icons'+#13#10#13#10;
QP_FOLOPTFRM_FILE_EXT = 'File Extension Filter';
QP_FOLOPTFRM_FILE_EXT_1 = 'Add New Filter, in format "*.xxx"';

//MAMEmerge form
QP_MAMEM_BAD_DATA =  'Either no valid directory was given, or no emulator was selected';

//MameOptions Form
QP_MAMEOPT_BAD_DIR =  'The selected directory is not a valid MAME Extras folder (needs dats, folders, icons)';
QP_MAMEOPT_ROMS_EXIST_IN_SRC_DIR = 'ROM folder not empty. Making a MAME set here erases the existing list and may replace subfolders. Its advised you make a new empty folder for a a MAME scan. Continue?';
QP_MAME_SOFTLISTS_EXIST_IN_SRC_DIR = 'Selected folder already contains a root directory called after the softlist, overwrite?';

//Migrate Form
QP_MIGRATE_MIRROR = 'Mirror Paths';
QP_MIGRATE_MEDIA = 'Media Panel Paths';
QP_MIGRATE_MISC = 'Folder Options';
QP_MIGRATE_IPS = 'IPS Paths';

//rom properties form
QP_ROMPROP_TOP = 'Your at the top/bottom of the ROM list';

//run dialog
QP_RUNDLG_MAME_ROM = 'This is a MAME scanned ROM.';

//Scan roms form
QP_SCAN_NO_FILTER = 'There is no filter, please enter one eg *.zip';

//for power schemes.
QP_USE_GENERAL_SETTING = 'Use General Power Scheme Setting';
QP_DONT_CHANGE = 'Do not change power scheme';

//Extract Mode Strings
QP_EXTRACT_GENERAL = 'Use General Extraction Setting';
QP_EXTRACT_ROM_DIR = 'Extract to ROMs Directory';
QP_EXTRACT_QP_TEMP = 'Extract to QuickPlays Temp Directory';
QP_EXTRACT_SYS_TEMP = 'Extract to Windows Temp Directory';

implementation

end.
