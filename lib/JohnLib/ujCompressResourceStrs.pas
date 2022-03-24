unit ujCompressResourceStrs;

interface

ResourceString

// Resource Strings by section/unit

// COMPRESSION strings
COMP_FORMAT_UNSUPPORTED = 'Unsupported compression format';
COMP_NO_CFG_DIR = 'Configuration directory not valid';
COMP_INVALID_DIR = 'Unable to find directory containing file';
COMP_NO_READING = ' does not support reading archives';
COMP_NO_WRITING = ' does not support writing archives';
COMP_VERIFY_FAILED = 'This is an invalid archive';
COMP_ARCHIVE_NOT_EXTRACTED = 'Archive not extracted';
COMP_NO_FILES_EXTRACTED = 'No files extracted and no errors occurred, is archive empty?';
COMP_NO_READ_SUPPORT = 'No compression support found for reading archives';
COMP_WRITE_ERROR = 'Error writing to archive';
COMP_READ_ERROR = 'Error reading archive';
COMP_MORE_THAN_ONE_FILE = 'Archive contained more than 1 file';
COMP_RENAME_ERROR = 'Error renaming file to - ';
COMP_ARCHIVE_EMPTY = 'Compressed file is empty';

// ACE Compression Strings.
ACE_UNKNOWN_ERROR = 'An unknown error occurred';
ACE_NO_MEMORY = 'Not Enough memory';
ACE_NETWORK_DRIVE = 'Could not detect available space on network drive';
ACE_INVALID_AV = 'AV of archive is invalid';
ACE_OPEN_ERROR = 'Could not open archive for reading';
ACE_READ_ERROR = 'Error reading from archive';
ACE_BROKEN_ERROR = 'Archive is broken';
ACE_FILE_NOT_ACE = 'File is not an ACE archive';
ACE_WRONG_DLL_VERSION = 'This Dll version is not able to handle the archive';
ACE_ERROR_DIR_NAME = 'Could not extract archive: name used by directory';
ACE_ERROR_WRITE = 'Error writing Archive';
ACE_ERROR_OPEN_WRITE = 'Error opening archive for writing';
ACE_ERROR_SPACE = 'Not enough space to extract archive';
ACE_ERROR_CREATE_FAILED = 'Creation of archive failed (write-protection?)';
ACE_VOLUME_CHANGE = 'Archive is requesting to change volumes, QuickPlay does not support spanned archives.';

implementation

end.
