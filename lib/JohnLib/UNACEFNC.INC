//================================================================================
//=============---  Part 3: Functions supported by UNAceV2.Dll ---================
//================================================================================

  //---------------------------------------------------------------------------
  //
  // UnAceV2.Dll supports the following functions:
  //
  //   ACEInitDll
  //   ACEReadArchiveData
  //   ACEList
  //   ACETest
  //   ACEExtract
  //
  // First of all - before any other function is called - the Dll has to be
  // initialized by ACEInitDll(). Using this function the application has
  // to set temporary directory, key file path, comment buffer and
  // callback function pointers.
  // (callback function pointers can be set to NULL for first-try-runs)
  //
  // See description of each function for details about their task, input and
  // output. Return codes of those functions are listed in part 3.1.
  //
  //---------------------------------------------------------------------------
  //
  // Contents:
  //   Part 3.1: ACE.DLL function return codes
  //   Part 3.2: functions and parameter structures
  //
  //---------------------------------------------------------------------------


  //===========================================================================
  //=============---  Part 3.1: ACE.DLL function return codes  ---=============
  //===========================================================================

      //-----------------------------------------------------------------------
      // These error codes are returned by the ACE.DLL-functions. The meanings
      // of the codes are the same, as they are for the exit codes of ACE.EXE.
      //-----------------------------------------------------------------------
const
        ACE_ERROR_NOERROR=       0;   // no error; operation succesful
        ACE_ERROR_MEM=           1;   // insufficient memory
        ACE_ERROR_FILES=         2;   // no files specified
        ACE_ERROR_FOUND=         3;   // specified archive not found
        ACE_ERROR_FULL=          4;   // disk full
        ACE_ERROR_OPEN=          5;   // could not open file
        ACE_ERROR_READ=          6;   // read error
        ACE_ERROR_WRITE=         7;   // write error
        ACE_ERROR_CLINE=         8;   // invalid command line
        ACE_ERROR_CRC=           9;   // CRC error
        ACE_ERROR_OTHER=         10;  // other error
        ACE_ERROR_EXISTS=        11;  // file already exists
        ACE_ERROR_USER=          255; // user break (application
                                            // returned cancel code at
                                            // callback function)


      //-----------------------------------------------------------------------
      // These error codes are returned by the ACE.DLL-functions. They are not
      // used by ACE.EXE yet.
      //-----------------------------------------------------------------------

        ACE_ERROR_PARAM=       128; // might be used later


  //===========================================================================
  //============---  Part 3.2: functions and parameter structures ---==========
  //===========================================================================

    //===========================  ACEInitDll  ================================
    // Initializes ACE dynamic link library. Has to be called before any
    // other function call. May be called more than one time.
    //-------------------------------------------------------------------------
    // Input :
    // Output:
    //-------------------------------------------------------------------------

      //-----------------------------------------------------------------------
      // ACEInitDll() parameter structure.
      //-----------------------------------------------------------------------

type pACEInitDllStruc=^tACEInitDllStruc;
     tACEInitDllStruc=record
          GlobalData:tACEGlobalDataStruc;
          Reserved:array[0..63] of char;         // has to be filled with zeroes
     end;

      //-----------------------------------------------------------------------
      // ACEInitDll() function declaration.
      //-----------------------------------------------------------------------

     tACEInitDll=function(DllData:pACEInitDllStruc):integer; stdcall;


    //=======================  ACEReadArchiveData  ============================
    // Tests a file whether it is an archive or not and reads out the archive
    // data.
    //-------------------------------------------------------------------------

      //-----------------------------------------------------------------------
      // ACEReadArchiveData() parameter structure.
      //-----------------------------------------------------------------------

type pACEReadArchiveDataStruc=^tACEReadArchiveDataStruc;
     tACEReadArchiveDataStruc=record
          ArchiveData:                // if this pointer is NULL, the
            pACEArchiveDataStruc;     // file passed to ACEReadArchiveData
                                      // is no archive; otherwise it points
                                      // to a tACEArchiveDataStruc structure
                                      // that contains information about the
                                      // archive
          Reserved:array[0..63] of char; // has to be filled with zeroes
      end;

      //-----------------------------------------------------------------------
      // ACEReadArchiveData() function declaration.
      //-----------------------------------------------------------------------

     tACEReadArchiveData=function(ArchiveName:pchar;
       ArchiveData:pACEReadArchiveDataStruc):integer; stdcall;


    //============================  ACEList  ==================================
    // Passes the specified files in the archive to StateCallbackProc().
    //-------------------------------------------------------------------------

      //-----------------------------------------------------------------------
      // ACEList() parameter structure.
      //-----------------------------------------------------------------------

type pACEListStruc=^tACEListStruc;
     tACEListStruc=record
          Files:                        // specifies files to be listed;
            tACEFilesStruc;             // see tACEFilesStruc structure
          Reserved:array[0..63] of char;// has to be filled with zeroes
        end;

      //-----------------------------------------------------------------------
      // ACEList() function declaration.
      //-----------------------------------------------------------------------

      tACEList=function(ArchiveName:pchar;List:pACEListStruc):integer; stdcall;


    //============================  ACETest  ==================================
    // Tests specified files in archive.
    //-------------------------------------------------------------------------

      //-----------------------------------------------------------------------
      // ACETest() parameter structure.
      //-----------------------------------------------------------------------

type pACETestStruc=^tACETestStruc;
     tACETestStruc=packed record
          Files:                         // specifies files to test;
            tACEFilesStruc;              // see tACEFilesStruc structure
          DecryptPassword:pchar;         // zero-terminated string,
                                         // case-sensitive (maxlen=56)
          Reserved:array[0..63] of char; // has to be filled with zeroes
       end;

      //-----------------------------------------------------------------------
      // ACETest() function declaration.
      //-----------------------------------------------------------------------

      tACETest=function(ArchiveName:pchar;Test:pACETestStruc):integer; stdcall;


    //===========================  ACEExtract  ================================
    // Extracts specified  files.
    //-------------------------------------------------------------------------

      //-----------------------------------------------------------------------
      // ACEExtract() parameter structure.
      //-----------------------------------------------------------------------

type pACEExtractStruc=^tACEExtractStruc;
     tACEExtractStruc=packed record
          Files:                        // specifies files to extract;
            tACEFilesStruc;             // see tACEFilesStruc structure
          DestinationDir:pchar;         // directory to extract files to
          ExcludePath:BOOL;             // extract files without path
          DecryptPassword:pchar;        // password for decryption (if files
                                        // are encrypted);
                                        // zero-terminated string,
                                        // case-sensitive (maxlen=56)
          Reserved:array[0..63] of char;// has to be filled with zeroes
        end;

      //-----------------------------------------------------------------------
      // ACEExtract() function declaration.
      //-----------------------------------------------------------------------

      tACEExtract=function(ArchiveName:pchar;Extract:pACEExtractStruc):integer; stdcall;

