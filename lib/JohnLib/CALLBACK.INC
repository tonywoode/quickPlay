//=============================================================================
//================---  Part 2: ACE.DLL callback declarations ---===============
//=============================================================================

  //---------------------------------------------------------------------------
  //
  // ACE.DLL makes use of four callback functions to exchange data
  // with the application:
  //
  //   1) InfoCallbackProc   (pACEInfoCallbackProcStruc    Info)
  //   2) ErrorCallbackProc  (pACEErrorCallbackProcStruc   Error)
  //   3) RequestCallbackProc(pACERequestCallbackProcStruc Request)
  //   4) StateCallbackProc  (pACEStateCallbackProcStruc   State)
  //
  // Meaning of different callback types:
  //   Info    - lets the application know about actions that take some
  //             time but are not essential
  //             (Code is one of ACE_CALLBACK_INFO constants)
  //   Error   - an error occured; if the reason for this error can
  //             be solved by the application then the Dll can continue
  //             the current operation, otherwise the operation has to
  //             be canceled
  //             (Code is one of ACE_CALLBACK_ERROR constants)
  //   Request - the Dll needs some user input
  //             for ex.: "Overwrite file? (yes/no/cancel)"
  //             (Code is one of ACE_CALLBACK_REQUEST constants)
  //   State   - Dll informs application about the progress of an operation
  //             (Code is one of ACE_CALLBACK_STATE constants)
  //
  // The pointers to the callback functions has to be set by the application
  // when calling ACEInitDll(). If the application does not install
  // a callback function, is has set the corresponding pointer to NULL.
  // If the ACE.DLL has to call the Error or Request callback function
  // and they are not installed, the ACE.DLL will cancel the operation.
  //
  // The application has the possibility to cancel the current operation
  // at each callback function call. So if the user clicks on a Cancel-button,
  // the application should return ACE_CALLBACK_RETURN_CANCEL at the next
  // callback function call.
  //
  // All callback function parameters are declared as unions.
  // The StructureType field contains he type of the structure which is used.
  // When the application knows which type of structure it has to use,
  // it will have to interpret the Code field to get to know the reason
  // for the callback function call.
  //
  //---------------------------------------------------------------------------
  //
  // Contents:
  //   Part 2.1: operation types
  //   Part 2.2: callback function return codes
  //   Part 2.3: callback structure types
  //   Part 2.4: callback structures
  //   Part 2.5: info callback function
  //   Part 2.6: error callback function
  //   Part 2.7: request callback function
  //   Part 2.8: state callback function
  //
  //---------------------------------------------------------------------------


  //===========================================================================
  //=====================---  Part 2.1: operation codes  ---===================
  //===========================================================================
  // Passed to callback functions indicating the current operation.
  //-------------------------------------------------------------------------
const
        ACE_CALLBACK_OPERATION_LIST=         0;
        ACE_CALLBACK_OPERATION_TEST=         1;
        ACE_CALLBACK_OPERATION_ANALYZE=      2;
        ACE_CALLBACK_OPERATION_EXTRACT=      3;
        ACE_CALLBACK_OPERATION_ADD=          4;
        ACE_CALLBACK_OPERATION_REPACK=       5;
        ACE_CALLBACK_OPERATION_DELETE=       6;
        ACE_CALLBACK_OPERATION_REPAIR=       7;    // repair without
                                                   // recovery record
        ACE_CALLBACK_OPERATION_SETCMT=       8;
        ACE_CALLBACK_OPERATION_ENCRYPT=      9;
        ACE_CALLBACK_OPERATION_KEEP=         10;   // file is to be
                                                   // taken along
                                                   // without recompress
        ACE_CALLBACK_OPERATION_RECOVER=      11;   // begin of
                                                   // recovering archive
                                                   // by recovery record
        ACE_CALLBACK_OPERATION_HEADSEARCH=   12;   // begin of searching
                                                   // for file headers
        ACE_CALLBACK_OPERATION_RECRECSEARCH= 13;   // begin of searching
                                                   // for recovery record
        ACE_CALLBACK_OPERATION_ADDSFX=       14;
        ACE_CALLBACK_OPERATION_LOCK=         15;
        ACE_CALLBACK_OPERATION_ADDAV=        16;   // not used in ACL
        ACE_CALLBACK_OPERATION_ADDRECOVREC=  17;
        ACE_CALLBACK_OPERATION_REGISTER=     18;   // not used in ACL


  //===========================================================================
  //=============---  Part 2.2: callback function return codes  ---============
  //===========================================================================
  // One of these result codes has to be returned by the application-based
  // callback functions.
  //---------------------------------------------------------------------------

        ACE_CALLBACK_RETURN_OK=              0;    // also "yes" at
                                                   // requests
        ACE_CALLBACK_RETURN_NO=              1;    // no, do not/
                                                   // do not retry
        ACE_CALLBACK_RETURN_CANCEL=          2;    // abort operation


  //===========================================================================
  //================---  Part 2.3: callback structure types  ---===============
  //===========================================================================
  // States of which type the passed structure is when a callback function
  // is called. The type is written to the StructureType field.
  //---------------------------------------------------------------------------

        ACE_CALLBACK_TYPE_GLOBAL=                $0;

                // type of structure is
                // tACECallbackGlobalStruc
                //-------------------------------------------------------------
                // callback function   | codes using this structure
                // --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
                // InfoCallbackProc    | ACE_CALLBACK_INFO_GENERALKEY      // not used in ACL
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // ErrorCallbackProc   | ACE_CALLBACK_ERROR_MEMORY // fr ManyFilesError und ExtractMem andere Codes verwenden!?
                //                     | ACE_CALLBACK_ERROR_REGISTER       // not used in ACL
                //                     | ACE_CALLBACK_ERROR_READKEY        // not used in ACL
                //                     | ACE_CALLBACK_ERROR_WRITEKEY       // not used in ACL
                //                     | ACE_CALLBACK_ERROR_NOWINACEKEY    // not used in ACL
                //                     | ACE_CALLBACK_ERROR_NOACTIVEACEKEY // not used in ACL
                //                     | ACE_CALLBACK_ERROR_UNCSPACE       // wird noch nicht verwendet!
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // RequestCallbackProc | ACE_CALLBACK_REQUEST_REGISTER     // not used in ACL
                //


        ACE_CALLBACK_TYPE_ARCHIVE=               $1;

                // type of structure is
                // tACECallbackArchiveStruc
                //-------------------------------------------------------------
                // callback function   | codes using this structure
                // --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
                // InfoCallbackProc    | ACE_CALLBACK_INFO_TMPARCCREATE
                //                     | ACE_CALLBACK_INFO_TMPARCCREATEEND
                //                     | ACE_CALLBACK_INFO_ADDRECREC
                //                     | ACE_CALLBACK_INFO_ADDRECRECEND
                //                     | ACE_CALLBACK_INFO_RECREC
                //                     | ACE_CALLBACK_INFO_NORECREC
                //                     | ACE_CALLBACK_INFO_RECOVERED
                //                     | ACE_CALLBACK_INFO_NODAMAGE
                //                     | ACE_CALLBACK_INFO_FNDMAINHEAD
                //                     | ACE_CALLBACK_INFO_FILELISTCREATE
                //                     | ACE_CALLBACK_INFO_FILELISTCREATEEND
                //                     | ACE_CALLBACK_INFO_FILESORT
                //                     | ACE_CALLBACK_INFO_FILESORTEND
                //                     | ACE_CALLBACK_INFO_COPYEND
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // ErrorCallbackProc   | ACE_CALLBACK_ERROR_MODIFYVOLUME
                //                     | ACE_CALLBACK_ERROR_MODIFYLOCKEDARCHIVE
                //                     | ACE_CALLBACK_ERROR_AV                  // not used in ACL
                //                     | ACE_CALLBACK_ERROR_TOODAMAGED
                //                     | ACE_CALLBACK_ERROR_ARCHIVEEXISTS
                //                     | ACE_CALLBACK_ERROR_OPENREPAIRARCHIVE
                //                     | ACE_CALLBACK_ERROR_OPENARCHIVEREAD
                //                     | ACE_CALLBACK_ERROR_OPENARCHIVEWRITE
                //                     | ACE_CALLBACK_ERROR_READARCHIVE
                //                     | ACE_CALLBACK_ERROR_WRITEARCHIVE
                //                     | ACE_CALLBACK_ERROR_ALREADYSFX
                //                     | ACE_CALLBACK_ERROR_ADDSFXTOVOLUME
                //                     | ACE_CALLBACK_ERROR_ARCHIVEBROKEN
                //                     | ACE_CALLBACK_ERROR_ARCHIVESAVE
                //                     | ACE_CALLBACK_ERROR_NOFILES
                //                     | ACE_CALLBACK_ERROR_ISNOTANARCHIVE
                //                     | ACE_CALLBACK_ERROR_TEMPDIRCREATE
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // RequestCallbackProc | ACE_CALLBACK_REQUEST_MARKASSOLID
                //                     | ACE_CALLBACK_REQUEST_CHANGEVOLUME
                //                     | ACE_CALLBACK_REQUEST_ARCHIVEEXISTS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // StateCallbackProc   | ACE_CALLBACK_STATE_STARTARCHIVE
                //


        ACE_CALLBACK_TYPE_ARCHIVEDFILE=          $2;

                // type of structure is
                // tACECallbackArchivedFileStruc
                //-------------------------------------------------------------
                // callback function   | codes using this structure
                // --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
                // InfoCallbackProc    | ACE_CALLBACK_INFO_TMPARCCREATE
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // ErrorCallbackProc   | ACE_CALLBACK_ERROR_CREATIONNAMEINUSE
                //                     | ACE_CALLBACK_ERROR_HIGHERVERSION
                //                     | ACE_CALLBACK_ERROR_ENCRYPTIONCRC
                //                     | ACE_CALLBACK_ERROR_WRITE
                //                     | ACE_CALLBACK_ERROR_READ
                //                     | ACE_CALLBACK_ERROR_OPENREAD
                //                     | ACE_CALLBACK_ERROR_OPENWRITE //wird noch gar nich benutzt?? sollte aber - bei extract!
                //                     | ACE_CALLBACK_ERROR_FILENAMETOOLONG
                //                     | ACE_CALLBACK_ERROR_REPACKCRC
                //                     | ACE_CALLBACK_ERROR_EXCLUDEPATH
                //                     | ACE_CALLBACK_ERROR_METHOD
                //                     | ACE_CALLBACK_ERROR_EXTRACTSPACE
                //                     | ACE_CALLBACK_ERROR_CREATION
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // RequestCallbackProc | ACE_CALLBACK_REQUEST_OVERWRITE
                //                     | ACE_CALLBACK_REQUEST_DELETEARCHIVEDSYSFILE
                //                     | ACE_CALLBACK_REQUEST_ADDBROKENFILE
                //                     | ACE_CALLBACK_REQUEST_PASSWORD
                //                     | ACE_CALLBACK_REQUEST_OVERWRITESYSFILE
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // StateCallbackProc   | ACE_CALLBACK_STATE_STARTFILE
                //                     | ACE_CALLBACK_STATE_ENDNOCRCCHECK
                //


        ACE_CALLBACK_TYPE_REALFILE=              $3;

                // type of structure is
                // tACECallbackRealFileStruc
                //-------------------------------------------------------------
                // callback function   | codes using this structure
                // --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
                // InfoCallbackProc    | ACE_CALLBACK_INFO_FILELISTADD
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // ErrorCallbackProc   | ACE_CALLBACK_ERROR_MOVEDELETE
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // RequestCallbackProc | ACE_CALLBACK_REQUEST_MOVEDELETEREALSYSFILE
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // StateCallbackProc   | ACE_CALLBACK_STATE_STARTFILE
                //


        ACE_CALLBACK_TYPE_SPACE=                 $4;

                // type of structure is
                // tACECallbackSpaceStruc
                //-------------------------------------------------------------
                // callback function   | codes using this structure
                // --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
                // ErrorCallbackProc   | ACE_CALLBACK_ERROR_TEMPDIRSPACE
                //                     | ACE_CALLBACK_ERROR_ARCHIVESPACE
                //


        ACE_CALLBACK_TYPE_SFXFILE=               $5;

                // type of structure is
                // tACECallbackSFXFileStruc
                //-------------------------------------------------------------
                // callback function   | codes using this structure
                // --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
                // ErrorCallbackProc   | ACE_CALLBACK_ERROR_READINGSFXFILE
                //


        ACE_CALLBACK_TYPE_COPY=                  $6;

                // type of structure is
                // tACECallbackCopyStruc
                //-------------------------------------------------------------
                // callback function   | codes using this structure
                // --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
                // InfoCallbackProc    | ACE_CALLBACK_INFO_COPY
                //


        ACE_CALLBACK_TYPE_PROGRESS=              $7;

                // type of structure is
                // tACECallbackProgressStruc
                //-------------------------------------------------------------
                // callback function   | codes using this structure
                // --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
                // StateCallbackProc   | ACE_CALLBACK_STATE_PROGRESS
                //


        ACE_CALLBACK_TYPE_CRCCHECK=              $8;

                // type of structure is
                // tACECallbackCRCCheckStruc
                //-------------------------------------------------------------
                // callback function   | codes using this structure
                // --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
                // StateCallbackProc   | ACE_CALLBACK_STATE_ENDCRCCHECK
                //


  //===========================================================================
  //==============---  Part 2.4: different callback structures  ---============
  //===========================================================================
  // These are the declarations of the different structures used in the
  // unions passed by the callback functions.
  //---------------------------------------------------------------------------

      //-----------------------------------------------------------------------
      // Only the Dll GlobalData is passed to the application.
      //-----------------------------------------------------------------------

type pACECallbackGlobalStruc=^tACECallbackGlobalStruc;
     tACECallbackGlobalStruc=packed record
          StructureType:DWORD;           // is ACE_CALLBACK_TYPE_GLOBAL
          Code:DWORD;                    // see definition of
                                         // ACE_CALLBACK_TYPE_GLOBAL
          Operation:DWORD;               // ACE_CALLBACK_OPERATION constant

          GlobalData:pACEGlobalDataStruc;// see tACEGlobalDataStruc
        end;

      //-----------------------------------------------------------------------
      // The Dll GlobalData and the ArchiveData are passed.
      //-----------------------------------------------------------------------

type pACECallbackArchiveStruc=^tACECallbackArchiveStruc;
     tACECallbackArchiveStruc=packed record
          StructureType:DWORD;          // is ACE_CALLBACK_TYPE_ARCHIVE
          Code:DWORD;                   // see definition of
                                        // ACE_CALLBACK_TYPE_ARCHIVE
          Operation:DWORD;              // ACE_CALLBACK_OPERATION constant

          GlobalData:pACEGlobalDataStruc;       // see tACEGlobalDataStruc
          ArchiveData:pACEArchiveDataStruc;     // see tACEArchiveDataStruc
        end;

      //-----------------------------------------------------------------------
      // GlobalData, ArchiveData and FileData are passed.
      //-----------------------------------------------------------------------

type pACECallbackArchivedFileStruc=^tACECallbackArchivedFileStruc;
     tACECallbackArchivedFileStruc=packed record
          StructureType:DWORD;          // is ACE_CALLBACK_TYPE_ARCHIVEDFILE
          Code:DWORD;                   // see definition of
                                        // ACE_CALLBACK_TYPE_ARCHIVEDFILE
          Operation:DWORD;              // ACE_CALLBACK_OPERATION constant

          GlobalData:pACEGlobalDataStruc;       // see tACEGlobalDataStruc
          ArchiveData:pACEArchiveDataStruc;     // see tACEArchiveDataStruc
          FileData:pACEFileDataStruc;           // see tACEFileDataStruc
        end;

      //-----------------------------------------------------------------------
      // GlobalData, ArchiveData and a FileName are passed.
      //-----------------------------------------------------------------------

type pACECallbackRealFileStruc=^tACECallbackRealFileStruc;
     tACECallbackRealFileStruc=packed record
          StructureType:DWORD;          // is ACE_CALLBACK_TYPE_REALFILE
          Code:DWORD;                   // see definition of
                                        // ACE_CALLBACK_TYPE_REALFILE
          Operation:DWORD;              // ACE_CALLBACK_OPERATION constant

          GlobalData:pACEGlobalDataStruc;       // see tACEGlobalDataStruc
          ArchiveData:pACEArchiveDataStruc;     // see tACEArchiveDataStruc
          FileName:pchar;                       // name of file
        end;

      //-----------------------------------------------------------------------
      // GlobalData, ArchiveData, the path of temp directory and the
      // bytes required in temp directory (archive size) are passed.
      //-----------------------------------------------------------------------

type pACECallbackSpaceStruc=^tACECallbackSpaceStruc;
     tACECallbackSpaceStruc=packed record
          StructureType:DWORD;          // is ACE_CALLBACK_TYPE_SPACE
          Code:DWORD;                   // see definition of
                                        // ACE_CALLBACK_TYPE_SPACE
          Operation:DWORD;

          GlobalData:pACEGlobalDataStruc;       // see tACEGlobalDataStruc
          ArchiveData:pACEArchiveDataStruc;     // see tACEArchiveDataStruc
          Directory:pchar;                      // path of directory
          ArchiveSize:QWORD;                    // bytes required in temp dir
        end;

      //-----------------------------------------------------------------------
      // GlobalData, ArchiveData and SFXFileName are passed.
      //-----------------------------------------------------------------------

type pACECallbackSFXFileStruc=^tACECallbackSFXFileStruc;
     tACECallbackSFXFileStruc=packed record
          StructureType:DWORD;          // is ACE_CALLBACK_TYPE_SFXFILE
          Code:DWORD;                   // see definition of
                                        // ACE_CALLBACK_TYPE_SFXFILE
          Operation:DWORD;              // ACE_CALLBACK_OPERATION constant

          GlobalData:pACEGlobalDataStruc;       // see tACEGlobalDataStruc
          ArchiveData:pACEArchiveDataStruc;     // see tACEArchiveDataStruc
          SFXFileName:pchar;                    // name of SFX
        end;

      //-----------------------------------------------------------------------
      // GlobalData, ArchiveData and CopyData are passed.
      //-----------------------------------------------------------------------

type pACECallbackCopyStruc=^tACECallbackCopyStruc;
     tACECallbackCopyStruc=packed record
          StructureType:DWORD;          // is ACE_CALLBACK_TYPE_COPY
          Code:DWORD;                   // see definition of
                                        // ACE_CALLBACK_TYPE_COPY
          Operation:DWORD;              // ACE_CALLBACK_OPERATION constant

          GlobalData:pACEGlobalDataStruc;       // see tACEGlobalDataStruc
          ArchiveData:pACEArchiveDataStruc;     // see tACEArchiveDataStruc
          CopyData:pACECopyInfoStruc;           // see tACECopyInfoStruc
        end;

      //-----------------------------------------------------------------------
      // GlobalData, ArchiveData, FileData and ProgressData are passed.
      //-----------------------------------------------------------------------

type pACECallbackProgressStruc=^tACECallbackProgressStruc;
     tACECallbackProgressStruc=packed record
          StructureType:DWORD;          // is ACE_CALLBACK_TYPE_PROGRESS
          Code:DWORD;                   // see definition of
                                        // ACE_CALLBACK_TYPE_PROGRESS
          Operation:DWORD;              // ACE_CALLBACK_OPERATION constant

          GlobalData:pACEGlobalDataStruc;       // see tACEGlobalDataStruc
          ArchiveData:pACEArchiveDataStruc;     // see tACEArchiveDataStruc
          FileData:pACEFileDataStruc;       // see tACEFileDataStruc
          ProgressData:pACEProgressDataStruc;   // see tACEProgressDataStruc
        end;

      //-----------------------------------------------------------------------
      // GlobalData, ArchiveData, FileData and CRC-check result are passed.
      //-----------------------------------------------------------------------

type pACECallbackCRCCheckStruc=^tACECallbackCRCCheckStruc;
     tACECallbackCRCCheckStruc=packed record
          StructureType:DWORD;          // is ACE_CALLBACK_TYPE_CRCCHECK
          Code:DWORD;                   // see definition of
                                        // ACE_CALLBACK_TYPE_CRCCHECK
          Operation:DWORD;              // ACE_CALLBACK_OPERATION constant

          GlobalData:pACEGlobalDataStruc;       // see tACEGlobalDataStruc
          ArchiveData:pACEArchiveDataStruc;     // see tACEArchiveDataStruc
          FileData:pACEFileDataStruc;           // see tACEFileDataStruc
          CRCOk:BOOL;                           // CRC-check result
        end;

  //===========================================================================
  //=================---  Part 2.5: info callback function  ---================
  //===========================================================================
  // Declaration of ACEInfoCallbackProc() parameter and explanation of
  // callback info codes.
  //---------------------------------------------------------------------------

      //-----------------------------------------------------------------------
      // Union parameter used at ACEInfoCallbackProc().
      //-----------------------------------------------------------------------

type pACEInfoCallbackProcStruc=^tACEInfoCallbackProcStruc;
     tACEInfoCallbackProcStruc=packed record
          case integer of
          0:(StructureType:DWord;);             // indicates which of the fol-
                                                // lowing structures is used
          1:(Global:tACECallbackGlobalStruc;);
          2:(Archive:tACECallbackArchiveStruc;);
          3:(RealFile:tACECallbackRealFileStruc;);
          4:(Copy:tACECallbackCopyStruc;);
        end;

      //-----------------------------------------------------------------------
      // These values are passed to the ACEInfoCallbackProc callback function
      // to inform the application about actions (smaller parts of operations)
      // which may take some time or other things that might be of interest.
      //-----------------------------------------------------------------------
const
        ACE_CALLBACK_INFO_GENERALKEY=            $100;

                                // key is a general one (no own AV; own key
                                // is obtainable for a special price!?)
                                // not used in ACL
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_GLOBAL
                                // operations:
                                //   ACERegister

        ACE_CALLBACK_INFO_TMPARCCREATE=          $110;

                                // creating temporary archive for changes
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACELock
                                //   ACEAddAV
                                //   ACERepair


        ACE_CALLBACK_INFO_TMPARCCREATEEND=       $111;

                                // finished creating temporary archive
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACELock
                                //   ACEAddAV
                                //   ACERepair


        ACE_CALLBACK_INFO_ADDRECREC=             $112;

                                // adding recovery record
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACELock
                                //   ACEAddAV
                                //   ACEAddRecoveryRecord
                                //   ACERepair


        ACE_CALLBACK_INFO_ADDRECRECEND=          $113;

                                // finished adding recovery record
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACELock
                                //   ACEAddAV
                                //   ACEAddRecoveryRecord
                                //   ACERepair


        ACE_CALLBACK_INFO_RECREC=                $114;

                                // trying to recover files by recovery
                                // record; end indicated by
                                // ACE_CALLBACK_INFO_RECOVERED or
                                // ACE_CALLBACK_INFO_NODAMAGE
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACERepair


        ACE_CALLBACK_INFO_NORECREC=              $115;

                                // found no recovery record
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACERepair


        ACE_CALLBACK_INFO_RECOVERED=             $116;

                                // archive has been fully recovered
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACERepair


        ACE_CALLBACK_INFO_NODAMAGE=              $117;

                                // ACERepair detected by recovery record that
                                // the archive is not damaged
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACERepair


        ACE_CALLBACK_INFO_FNDMAINHEAD=           $118;

                                // found archive header
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACERepair


        ACE_CALLBACK_INFO_FILELISTCREATE=        $119;

                                // creating a file list of specified files
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEList
                                //   ACEDelete
                                //   ACETest
                                //   ACEExtract
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles


        ACE_CALLBACK_INFO_FILELISTCREATEEND=     $11a;

                                // sent when creating the list of files
                                // is finished
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEList
                                //   ACEDelete
                                //   ACETest
                                //   ACEExtract
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles


        ACE_CALLBACK_INFO_FILESORT=              $11b;

                                // sorting files (for solid compression)
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEAdd


        ACE_CALLBACK_INFO_FILESORTEND=           $11c;

                                // sorting files (for solid compression)
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEAdd


        ACE_CALLBACK_INFO_COPYEND=               $11d;

                                // copying a file finished
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACELock
                                //   ACEAddAV
                                //   ACERepair


        ACE_CALLBACK_INFO_FILELISTADD=           $140;

                                // called at creation of file list; the name
	                        // of the file just added to file list is
                                // passed in tACECallbackRealFileStruc
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_REALFILE
                                // operations:
                                //   ACEList
                                //   ACEDelete
                                //   ACETest
                                //   ACEExtract
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles


        ACE_CALLBACK_INFO_COPY=                  $150;

                                // copying a file; file name, file size and
                                // copied bytes are passed via
                                // tACECallbackCopyStruc
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_COPY
                                // operations:
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACELock
                                //   ACEAddAV
                                //   ACERepair


  //===========================================================================
  //=================---  Part 2.6: error callback function  ---===============
  //===========================================================================
  // Declaration of ACEErrorCallbackProc() parameter and explanation of
  // callback error codes.
  //---------------------------------------------------------------------------

      //-----------------------------------------------------------------------
      // Union parameter used at ACEErrorCallbackProc().
      //-----------------------------------------------------------------------

type pACEErrorCallbackProcStruc=^tACEErrorCallbackProcStruc;
     tACEErrorCallbackProcStruc=packed record
          case integer of
          0:(StructureType:DWORD;);             // indicates which of the fol-
                                                // lowing structures is used
          1:(Global:tACECallbackGlobalStruc;);
          2:(Archive:tACECallbackArchiveStruc;);
          3:(ArchivedFile:tACECallbackArchivedFileStruc;);
          4:(RealFile:tACECallbackRealFileStruc;);
          5:(Space:tACECallbackSpaceStruc;);
          6:(SFXFile:tACECallbackSFXFileStruc;);
      end;

      //-----------------------------------------------------------------------
      // This structure is used by the ACEErrorCallback function to inform
      // the application about errors. The Code field of the used structure
      // contains an ACE_CALLBACK_ERROR value. At most problems modifications
      // to the passed structure can be made to fix it. Other problems can not
      // be solved and cause an operation abort immediately.
      // ErrorCallbackProc() has to return either ACE_CALLBACK_RETURN_OK or
      // ACE_CALLBACK_RETURN_CANCEL.
      //-----------------------------------------------------------------------
const
        ACE_CALLBACK_ERROR_MEMORY=               $200;

                                // not enough memory to perform operation
                                // (dictionary too large?)
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_GLOBAL
                                // operations:
                                //   all


        ACE_CALLBACK_ERROR_REGISTER=             $201;

                                // registration key is invalid (or wrong
                                // format?); not used in ACL
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_GLOBAL
                                // operations:
                                //   ACERegister


        ACE_CALLBACK_ERROR_READKEY=              $202;

                                // key could not be read (does not exist or
                                // is invalid); not used in ACL
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_GLOBAL
                                // operations:
                                //   ACEInitDll


        ACE_CALLBACK_ERROR_WRITEKEY=             $203;

                                // could not write key; not used in ACL
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_GLOBAL
                                // operations:
                                //   ACERegister


        ACE_CALLBACK_ERROR_NOWINACEKEY=          $204;

                                // key not valid for WinACE; not used in ACL
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_GLOBAL
                                // operations:
                                //   ACERegister


        ACE_CALLBACK_ERROR_NOACTIVEACEKEY=       $205;

                                // key not valid for ActiveACE; not used in ACL
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_GLOBAL
                                // operations:
                                //   ACERegister


        ACE_CALLBACK_ERROR_UNCSPACE=             $206;

                                // Win95_OSR1-bug: it is impossible to
                                // get available space of network drives by
                                // an UNC name; ACE will not stop but
                                // assumes there are 4Gb free
                                // --> the operation might fail if free
                                // disk space is low
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_GLOBAL
                                // operations:
                                //   all


        ACE_CALLBACK_ERROR_MODIFYVOLUME=         $220;

                                // modification of volumes not possible
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACELock
                                //   ACEAddAV
                                //   ACEAddRecoveryRecord


        ACE_CALLBACK_ERROR_MODIFYLOCKEDARCHIVE=  $221;

                                // modification of locked archive not possible
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACELock
                                //   ACEAddAV
                                //   ACEAddRecoveryRecord


        ACE_CALLBACK_ERROR_AV=                   $222;

                                // AV of archive is NOT ok or does not match
                                // to the users AV (not used in ACL)
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEReadArchiveData
                                //   ACEList
                                //   ACEDelete
                                //   ACETest
                                //   ACEExtract
                                //   ACEAdd
                                //   ACERepair
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACEAddAV
                                //   ACELock
                                //   ACEAddRecoveryRecord


        ACE_CALLBACK_ERROR_TOODAMAGED=           $223;

                                // can not repair by recovery record but
                                // can continue with normal repair
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACERepair


        ACE_CALLBACK_ERROR_ARCHIVEEXISTS=        $224;

                                // destination file name already used;
                                // may occur if at
                                // ACE_CALLBACK_ERROR_ARCHIVESPACE a
                                // direcory is specified where a file
                                // with the same name as the current archive
                                // already exists
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEAdd


        ACE_CALLBACK_ERROR_OPENREPAIRARCHIVE=    $225;

                                // could not create archive for repairing
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACERepair


        ACE_CALLBACK_ERROR_OPENARCHIVEREAD=      $226;

                                // could not open archive/volume for reading
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEReadArchiveData
                                //   ACEList
                                //   ACETest
                                //   ACEExtract
                                //   ACERepair


        ACE_CALLBACK_ERROR_OPENARCHIVEWRITE=     $227;

                                // could not open archive/volume for writing
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEDelete
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACELock
                                //   ACEAddAV
                                //   ACEAddRecoveryRecord
                                //   ACERepair


        ACE_CALLBACK_ERROR_READARCHIVE=          $228;

                                // error reading from archive
                                // (source disk removed?)
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEReadArchiveData
                                //   ACEList
                                //   ACEDelete
                                //   ACETest
                                //   ACEExtract
                                //   ACEAdd
                                //   ACERepair
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACEAddAV
                                //   ACELock
                                //   ACEAddRecoveryRecord


        ACE_CALLBACK_ERROR_WRITEARCHIVE=         $229;

                                // error writing to archive
                                // (destination disk removed?)
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEDelete
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACELock
                                //   ACEAddAV
                                //   ACEAddRecoveryRecord
                                //   ACERepair


        ACE_CALLBACK_ERROR_ALREADYSFX=           $22a;

                                // ca not make to SFX: is already SFX
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEAddSFX


        ACE_CALLBACK_ERROR_ADDSFXTOVOLUME=       $22b;

                                // adding SFX to volumes not possible
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEAddSFX


        ACE_CALLBACK_ERROR_ARCHIVEBROKEN=        $22c;

                                // archive is broken (damaged)
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEReadArchiveData
                                //   ACEList
                                //   ACEDelete
                                //   ACETest
                                //   ACEExtract
                                //   ACEAdd
                                //   ACERepair
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACEAddAV
                                //   ACELock
                                //   ACEAddRecoveryRecord

        ACE_CALLBACK_ERROR_ARCHIVESAVE=          $22d;

                                // not enough space to save archive;
                                // but normally
                                // ACE_CALLBACK_ERROR_ARCHIVESPACE
                                // should allow to change destination
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACELock
                                //   ACEAddAV
                                //   ACEAddRecoveryRecord
                                //   ACERepair


        ACE_CALLBACK_ERROR_NOFILES=              $22e;

                                // no files specified/could not find files
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEList
                                //   ACEDelete
                                //   ACETest
                                //   ACEExtract
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles


        ACE_CALLBACK_ERROR_ISNOTANARCHIVE=       $22f;

                                // specified archive file is not an
                                // ACE archive
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEReadArchiveData
                                //   ACEList
                                //   ACEDelete
                                //   ACETest
                                //   ACEExtract
                                //   ACEAdd
                                //   ACERepair
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACEAddAV
                                //   ACELock
                                //   ACEAddRecoveryRecord


        ACE_CALLBACK_ERROR_TEMPDIRCREATE=        $230;

                                // could not create file in temp directory
                                // (write protected or directory does
                                //  not exist)
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACELock
                                //   ACEAddAV
                                //   ACEAddRecoveryRecord
                                //   ACERepair


        ACE_CALLBACK_ERROR_HIGHERVERSION=        $231;

                                // this Dll version is not able to handle
                                // the archive
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACELock
                                //   ACEAddAV
                                //   ACEAddRecoveryRecord


        ACE_CALLBACK_ERROR_CREATIONNAMEINUSE=    $240;

                                // name used by directory
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEExtract


        ACE_CALLBACK_ERROR_ENCRYPTIONCRC=        $242;

                                // encryption failed because of CRC-Error at
                                // decompression
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEEncryptFiles


        ACE_CALLBACK_ERROR_READ=                 $243;

                                // error reading file to be added
                                // (source disk removed?)
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEAdd


        ACE_CALLBACK_ERROR_WRITE=                $244;

                                // error at extraction
                                // (destination disk removed?)
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEExtract


        ACE_CALLBACK_ERROR_OPENREAD=             $245;

                                // error opening file for reading
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEAdd


        ACE_CALLBACK_ERROR_OPENWRITE=            $246;

                                // error opening file for writing
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEExtract


        ACE_CALLBACK_ERROR_FILENAMETOOLONG=      $247;

                                // resulting file name too long
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEAdd


        ACE_CALLBACK_ERROR_REPACKCRC=            $248;

                                // CRC-check error at recompression
                                // (archive broken or wrong password)
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEDelete
                                //   ACEAdd


        ACE_CALLBACK_ERROR_EXCLUDEPATH=          $249;

                                // could not exclude path of file names; two
                                // or more files would have the same name
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEAdd


        ACE_CALLBACK_ERROR_METHOD=               $24a;

                                // compression method not known to this
                                // Dll version
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEDelete
                                //   ACETest
                                //   ACEExtract
                                //   ACEAdd
                                //   ACEEncryptFiles


        ACE_CALLBACK_ERROR_EXTRACTSPACE=         $24b;

                                // not enough space to extract file
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEExtract


        ACE_CALLBACK_ERROR_CREATION=             $24c;

                                // creation failed (write-protection?)
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEExtract


        ACE_CALLBACK_ERROR_OVERWRITEDELETE=      $24d;

                                // could not overwrite because deletion of
                                // file failed
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEExtract


        ACE_CALLBACK_ERROR_MOVEDELETE=           $260;

                                // deletion of file or directory failed
                                // (move operation)
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_REALFILE
                                // operations:
                                //   ACEAdd

        ACE_CALLBACK_ERROR_TEMPDIRSPACE=         $270;

                                // not enough space at current temp directory
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_SPACE
                                // operations:
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACEAddAV


        ACE_CALLBACK_ERROR_ARCHIVESPACE=         $271;

                                // not enough space to save archive
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_SPACE
                                // operations:
                                //   ACEDelete
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACELock
                                //   ACEAddAV
                                //   ACEAddRecoveryRecord
                                //   ACERepair


        ACE_CALLBACK_ERROR_READINGSFXFILE=       $280;

                                // error reading SFX file:
                                // is no SFX file,
                                // file does not exist or could not be opened
                                // for reading
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_SFXFILE
                                // operations:
                                //   ACEAdd
                                //   ACEAddSFX


  //===========================================================================
  //================---  Part 2.7: request callback function  ---==============
  //===========================================================================
  // Declaration of ACERequestCallbackProc() parameter and explanation of
  // callback request codes.
  //---------------------------------------------------------------------------

      //-----------------------------------------------------------------------
      // Union parameter used at ACERequestCallbackProc().
      //-----------------------------------------------------------------------

type pACERequestCallbackProcStruc=^tACERequestCallbackProcStruc;
     tACERequestCallbackProcStruc=packed record
          case integer of
          0:(StructureType:DWORD;);                 // indicates which of the fol-
                                                // lowing structures is used
          1:(Global:tACECallbackGlobalStruc;);
          2:(Archive:tACECallbackArchiveStruc;);
          3:(ArchivedFile:tACECallbackArchivedFileStruc;);
          4:(RealFile:tACECallbackRealFileStruc;);
       end;

      //-----------------------------------------------------------------------
      // Question constants are passed to the RequestCallbackProc callback
      // function to request further data.
      // RequestCallbackProc may return ACE_CALLBACK_RETURN_OK,
      // ACE_CALLBACK_RETURN_NO or ACE_CALLBACK_RETURN_CANCEL.
      //-----------------------------------------------------------------------
const
        ACE_CALLBACK_REQUEST_REGISTER=           $300;

                                // Global.UserAV has to be set
                                // to continue registration process;
                                // not used in ACL
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_GLOBAL
                                // operations:
                                //   ACERegister


        ACE_CALLBACK_REQUEST_MARKASSOLID=        $320;

                                // ArchiveHeader damaged,
                                // set solid flag for the new archive?
                                // (in case of doubt return yes!)
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACERepair


        ACE_CALLBACK_REQUEST_CHANGEVOLUME=       $321;
                                // Asks for permission to process next volume.
                                // If operation is ACE_CALLBACK_OPERATION_ADD
                                // then a new volume will be created.
                                // The application may change the name
                                // of the archive by modifying
                                // ArchiveData->ArchiveName
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEDelete
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEList
                                //   ACETest
                                //   ACEExtract


        ACE_CALLBACK_REQUEST_ARCHIVEEXISTS=      $322;
                                // Asks whether to overwrite a file with
                                // the same name as the archive.
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEDelete
                                //   ACEAdd
                                //   ACESetComments
                                //   ACEEncryptFiles


        ACE_CALLBACK_REQUEST_OVERWRITE=          $340;

                                // Overwrite existing file?
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEAdd
                                //   ACEExtract


        ACE_CALLBACK_REQUEST_DELARCHIVEDSYSFILE= $341;

                                // Delete rdonly/hidden/system file
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEDelete


        ACE_CALLBACK_REQUEST_ADDBROKENFILE=      $342;

                                // repair function found file with
                                // broken header, add file?
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACERepair


        ACE_CALLBACK_REQUEST_PASSWORD=           $343;

                                // password required; attention: may be
                                // decryption _and_ encryption; but  passwords
                                // can be different --> better changing
                                // passwords at StateCallbackProc
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEDelete
                                //   ACETest
                                //   ACEExtract
                                //   ACEAdd
                                //   ACEEncryptFiles


        ACE_CALLBACK_REQUEST_OVERWRITESYSFILE=   $344;

                                // Overwrite rdonly/hidden/system file
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEAdd
                                //   ACEExtract


        ACE_CALLBACK_REQUEST_MOVEDELREALSYSFILE= $360;

                                // Delete rdonly/hidden/system file
                                // (move to archive operation)
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_REALFILE
                                // operations:
                                //   ACEAdd


  //===========================================================================
  //=================---  Part 2.8: state callback function  ---===============
  //===========================================================================
  // Declaration of ACEStateCallbackProc() parameter and explanation of
  // callback state codes.
  //---------------------------------------------------------------------------

      //-----------------------------------------------------------------------
      // Union parameter used at ACEStateCallbackProc().
      //-----------------------------------------------------------------------

type pACEStateCallbackProcStruc=^tACEStateCallbackProcStruc;
     tACEStateCallbackProcStruc=record
          case integer of
          0:(StructureType:DWORD;);                  // indicates which of the fol-
                                                // lowing structures is used
          1:(Archive:tACECallbackArchiveStruc;);
          2:(ArchivedFile:tACECallbackArchivedFileStruc;);
          3:(RealFile:tACECallbackRealFileStruc;);
          4:(Progress:tACECallbackProgressStruc;);
          5:(CRCCheck:tACECallbackCRCCheckStruc;);
        end;

      //-----------------------------------------------------------------------
      // Calls to (*StateCallbackProc)() with ACE_CALLBACK_STATE values in the
      // Code field are made to enable the application to show the progress of
      // an operation.
      //-----------------------------------------------------------------------
const
        ACE_CALLBACK_STATE_STARTARCHIVE=         $400;

                                // procession of archive is about to begin
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVE
                                // operations:
                                //   ACEList
                                //   ACEDelete
                                //   ACETest
                                //   ACEExtract
                                //   ACEAdd
                                //   ACERepair
                                //   ACESetComments
                                //   ACEEncryptFiles
                                //   ACEAddSFX
                                //   ACEAddAV
                                //   ACELock
                                //   ACEAddRecoveryRecord


        ACE_CALLBACK_STATE_STARTFILE=            $410;

                                // procession of file is about to begin
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEList
                                //   ACEDelete
                                //   ACETest
                                //   ACEExtract
                                //   ACEAdd
                                //   ACERepair
                                //   ACESetComments
                                //   ACEEncryptFiles


        ACE_CALLBACK_STATE_ENDNOCRCCHECK=        $411;

                                // end of file procession
                                // (no CRC chceck for this operation)
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_ARCHIVEDFILE
                                // operations:
                                //   ACEList
                                //   ACEDelete
                                //   ACEAdd
                                //   ACERepair
                                //   ACESetComments
                                //   ACEEncryptFiles


        ACE_CALLBACK_STATE_PROGRESS=             $420;

                                // informs about the progress of a file
                                // operation
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_PROGRESS
                                // operations:
                                //   ACEDelete
                                //   ACETest
                                //   ACEExtract
                                //   ACEAdd
                                //   ACERepair
                                //   ACEEncryptFiles


        ACE_CALLBACK_STATE_ENDCRCCHECK=          $430;

                                // end of file procession, CRC-check
                                // result is passed
                                //---------------------------------------------
                                // structure type:
                                //   ACE_CALLBACK_TYPE_CRCCHECK
                                // operations:
                                //   ACETest
                                //   ACEExtract
                                //   ACEDelete
                                //   ACEAdd


