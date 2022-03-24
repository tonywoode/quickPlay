//=============================================================================
//=====================---  Part 1: different structures ---===================
//=============================================================================

  //---------------------------------------------------------------------------
  //
  // Here in different structures used at callback functions and
  // ACE.DLL functions are declared.
  //
  //---------------------------------------------------------------------------
  //
  // Contents:
  //   Part 1.1: structures used in callback structures
  //   Part 1.2: structures used in function structures
  //
  //---------------------------------------------------------------------------


  //===========================================================================
  //========---  Part 1.1: structures used in callback structures  ---=========
  //===========================================================================

    //=======================  comment buffer structure  ======================
    // Used in tACEGlobalDataStruc. Application has to specify where the
    // comment is or should be stored.
    //-------------------------------------------------------------------------

type pACECommentStruc=^tACECommentStruc;
         tACECommentStruc=packed record
          Buf:pchar;                  // area where the comments are stored
                                      // by the application or by the Dll
                                      // comments must be zero-terminated
          BufSize,                    // size of this area
          State:DWORD;                // state of comment - see ACE_COMMENT
         end;                         // constants below
         


      //-----------------------------------------------------------------------
      // Defines for the tACECommentStruc.State field, which tells about
      // the result of the last comment extraction.
      //-----------------------------------------------------------------------

const
                ACE_COMMENT_OK=         0;   // comment extraction went fine

                ACE_COMMENT_SMALLBUF=   1;   // comment buffer too small to
                                             // store the whole comment in

                ACE_COMMENT_NONE=       255; // No comment present


    //=======================  global data structure  =========================
    // This structure contains information for the Dll being interesting for
    // nearly all functions. The Dll has to be initialized with this
    // structure passed to tACEInitDll(). This structure is also passed
    // by the callback functions.
    //-------------------------------------------------------------------------

              //---------------------------------------------------------------
              // Forward declarations of callback function parameters
              // used in this structure.
              //---------------------------------------------------------------

type pACEGlobalDataStruc=^tACEGlobalDataStruc;
     tACEGlobalDataStruc=packed record
        //------------------------ fields for ACE and UnACE -------------------

          Obj:pointer;          // ---- reserved for application! ----
                                // thought to be used as a pointer to
                                // an object; when a callback-function is
                                // called, the object pointer can be used to
                                // handle the callback in a specific way;
                                // the pointer has to be initialized by
                                // ACEInitDll()

          MaxArchiveTestBytes:DWORD;

                                // how many bytes of a file should be
                                // looked upon at archive header search?

          MaxFileBufSize:DWORD;

                                // maximum buffer size for buffered
                                // I/O operations

          Comment:              // used to exchange comment data
           tACECommentStruc;    // between application and Dll
                                // using callback functions

          DecryptPassword:pchar;

                                // the DecryptPassword specified at
                                // ACEInitDll() is overwritten by the
                                // DecryptPassword field of tACEAddStruc and
                                // other function-specific structures;
                                // but this field can be used to change the
                                // password at callback function calls

          UseVBStructures:BOOL; //  passes structures to callback functions
                                //  much better suited for Visual Basic


          Reserved1:array[0..59]
                      of char;  // has to be filled with zeros	  

        //--------------------------- fields for ACE only ---------------------

          EncryptPassword:pchar;

                                // things stated at the description of the
                                // DecryptPassword field apply here as well


          TempDir:pchar;        // directory to save temporary archive

        //-------- registration (ACE DLLs only, but not used at ACL) ----------

          KeyPath:pchar;        // necessary for reading and writing key file

          UserAV:pchar;         // Dll returns the AV string (if registered)
                                // in this field

          IsGeneralKey:pchar;   // DLL returns the key, if it is a general key

          OwnerWindow:hwnd;     // specifies the applications window to be
                                // parent of the registration reminder dialog

        //--------------------------- fields for ACE only ---------------------

          CompressionLevel:DWORD;
                                // contains the currently used compression
                                // level - may be changed during compression
                                // operation

          Reserved2:array[0..55]
                      of char;  // has to be filled with zeros


        //----------------------  callback functions (ACE and UnACE) ----------

          InfoCallbackProc:tfarproc;

                                //  Informs application about details like the
                                //  creation of a temporary archive.
                                //  See ACE_CALLBACK_INFO definitions for
                                //  more information.

          ErrorCallbackProc:tfarproc;

                                //  Called to let the application know about
                                //  errors. The Code field of Error will
                                //  contain an ACE_CALLBACK_ERROR value.

          RequestCallbackProc:tfarproc;

                                //  Called to let the application know about
                                //  requests for data. Code will contain an
                                //  ACE_CALLBACK_REQUEST value.

          StateCallbackProc:tfarproc;

                                //  Called to let the application know about
                                //  the progress of operations.


        //-------------------------- different new fields ---------------------
          Reserved3:array[0..63]
                      of char;  // has to be filled with zeros
	end;


    //=======================  archive data structure  ========================
    // Informs the callback functions about the current archive, its volume
    // number, the archive-flags (see ACE_FLAG constants), the creation host
    // system (see ACE_HOST constants) and the AV if present in archive.
    // Also used at ACEReadArchiveData().
    //-------------------------------------------------------------------------

type pACEArchiveDataStruc=^tACEArchiveDataStruc;
     tACEArchiveDataStruc=packed record
          ArchiveName:pchar;
          VolumeNumber,
          Flags,                // see ACE_ARCFLAG defines below
          HostCreated,          // see ACE_HOST defines below
          TimeCreated,          // in MS-DOS format
          VersionCreated,
          VersionExtract:DWORD; // version needed to extract files
          AV:pchar;             // not used in ACL
          Reserved:array[0..63]
                     of char;   // filled with zeros
        end;


      //-----------------------------------------------------------------------
      // Flag constants for tACEArchiveDataStruc.Flags field.
      //-----------------------------------------------------------------------
const
        ACE_ARCFLAG_MAINCOMMENT=         2;
        ACE_ARCFLAG_SFX=                 512;
        ACE_ARCFLAG_LIMITSFXJR=          1024;        // is an SFX archive
                                                      // that supports 256k
                                                      // dictionary only
        ACE_ARCFLAG_MULTIVOLUME=         2048;
        ACE_ARCFLAG_AV=                  4096;        // not used in ACL
        ACE_ARCFLAG_RECOVERYREC=         8192;
        ACE_ARCFLAG_LOCK=                16384;
        ACE_ARCFLAG_SOLID=               32768;


      //-----------------------------------------------------------------------
      // Host system used to create an archive. Used at
      // tACEArchiveDataStruc.HostCreated field.
      //-----------------------------------------------------------------------

        ACE_HOST_MSDOS=                  0;     // archive created by
                                                // MSDOS ACE archiver
        ACE_HOST_OS2=                    1;     // created by OS2 ACE
        ACE_HOST_WIN32=                  2;     // created by Win32 ACE


    //========================  file data structure  ==========================
    // Contains information about an archived file.
    //-------------------------------------------------------------------------

type pACEFileDataStruc=^tACEFileDataStruc;
     tACEFileDataStruc=packed record
          SourceFileName:pchar;      // relative file name
          DestinationFileName:pchar; // absolute file name;
                                     // valid for add and extract only!
          Flags,                     // see ACE_FILEFLAG defines below
          CRC32,
          Method,                    // 0=stored, 1=LZ77, 2=V20Compression
          Dictionary:DWORD;          // DictionarySize = 2^Dictionary
          CompressedSize,
          Size:QWORD;
          Time,
          Attributes:DWORD;
          Reserved:array[0..63]
                     of char;        // filled with zeros
        end;

      //-----------------------------------------------------------------------
      // Flag constants for the tACEFileData.Flags field.
      //-----------------------------------------------------------------------
const
        ACE_FILEFLAG_FILECOMMENT=        2;     // file has comment
        ACE_FILEFLAG_SPLITBEFORE=        4096;  // continued from
                                                // previous volume
        ACE_FILEFLAG_SPLITAFTER=         8192;  // continued on
                                                // next volume
        ACE_FILEFLAG_PASSWORD=           16384; // is encrypted
        ACE_FILEFLAG_SOLID=              32768; // uses data of previous
                                                // files (solid mode)


    //========================  copy info structure  ==========================
    // Is passed to ACEInfoCallbackProc with ACE_CALLBACK_INFO_COPY as code.
    // Informs application about the progress of copying either an archive to
    // a temporary archive, or a temporary archive back to a normal archive.
    //-------------------------------------------------------------------------

type pACECopyInfoStruc=^tACECopyInfoStruc;
     tACECopyInfoStruc=packed record
          SourceFileName,            // source file
          DestinationFileName:pchar; // the file copying the source to

          CopiedBytes,               // bytes already copied
          FileSize:QWORD;             // source file size
          Reserved:array[0..63]
                     of char;        // filled with zeros
        end;

    //====================  operation progress structure  =====================
    // Used to state the progress of the current operation.
    //-------------------------------------------------------------------------

type pACEProgressDataStruc=^tACEProgressDataStruc;
     tACEProgressDataStruc=packed record
          Addr:pchar;               // address of uncompressed data block
          Size:dword;               // size of uncompressed data block
          TotalProcessedSize:QWORD;  // counted by Dll:
                                    // total uncompressed bytes processed
          TotalCompressedSize:QWORD; // total compressed bytes processed
          TotalSize:QWORD;           // total uncompressed bytes to process
                                    // (sum of all original file sizes)
          FileProcessedSize:QWORD;   // uncompr. bytes of file processed
          FileCompressedSize:QWORD;  // compr. bytes of file processed
          FileSize:QWORD;            // uncompressed file size
        end;


  //===========================================================================
  //========---  Part 1.2: structures used in function structures  ---=========
  //===========================================================================

    //=========================  file list structure  =========================
    // This structure is used in the function specific structures.
    // The application has to use this structure to indicate which files
    // have to be processed by the DLL.
    //-------------------------------------------------------------------------

type pACEFilesStruc=^tACEFilesStruc;
     tACEFilesStruc=packed record
          SourceDir:pchar;            // maybe a real or an archive directory
          FileList:pchar;             // pointer to list of files to process;
                                      // zero-terminated; files have to be
                                      // separated by carriage-return (0xd);
                                      // FileList may/will be modified by the
                                      // Dll; if nothing is specified, "*"
                                      // will be used
                                      // (attention at ACEDelete!!)
          ExcludeList:pchar;          // list of files to exclude from process
          FullMatch:BOOL;             // specifications must fully match
                                      // (no files with the same name in
				      //  subdirs are processed)
          RecurseSubDirs:BOOL;        // recurse subdirectories
           			      // (valid for add operations only)
          Reserved:array[0..59]
                     of char;         // has to be filled with zeros
                                      // for future: possibly in-/excluding
                                      // file attributes and date/time range
        end;

    //=====================  V2.0 compression structure =======================
    // Specifies whether to use v2.0 compression or not. If you use v2.0
    // compression you can also specify which v2.0 compression techniques
    // you want to use. (ACE only)
    //-------------------------------------------------------------------------

type pACEV20CompressionStruc=^tACEV20CompressionStruc;
     tACEV20CompressionStruc=packed record
          DoUse,                // if DoUse=1 and all other fields are
          DoUseDelta,           // zero, then all v2.0 compression
          DoUseExe,             // techniques will be used
          DoUsePic,
          DoUseSound:BOOL;
          Reserved:array[0..63] of char;  // has to be filled with zeros
        end;

    //===================  compression parameter structure  ===================
    // Used in tACEAddStruc and tACEDeleteStruc. (ACE only)
    //-------------------------------------------------------------------------

type pACECompressParamsStruc=^tACECompressParamsStruc;
     tACECompressParamsStruc=packed record
          Level,                      // see ACE_LEVEL constants below
          Dictionary:DWORD;           // 15(32k)..22(4Mb)

          V20Compression:             // indicates if (or which) v2.0
            tACEV20CompressionStruc;  // compression techniques shall be used

          TestAfter:BOOL;             // make a test for CRC check errors
                                      // after compression
          Reserved:array[0..63]
                     of char;         // has to be filled with zeros
        end;

      //-----------------------------------------------------------------------
      // Tells the Dll which compression level to use. (ACE only)
      //-----------------------------------------------------------------------
const
        ACE_LEVEL_STORE=     0; // save file only; do not compress
        ACE_LEVEL_FASTEST=   1; // compress very fast
        ACE_LEVEL_FAST=      2; // compress fast
        ACE_LEVEL_NORMAL=    3; // good compromise between speed and
                                      // compression rate
        ACE_LEVEL_GOOD=      4; // achieves good compression
        ACE_LEVEL_BEST=      5; // best compression; bit slow

