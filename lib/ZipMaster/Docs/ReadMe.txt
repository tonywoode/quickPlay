
			Welcome to the Delphi Zip v1.79
                   This is the Delphi Edition for version 4 and later only
					August 20, 2007
					Updated April 12, 2009 
				
D2009
	It is best to install into a different folder to any other versions.
	I would suggest <Public Documents>\RadStudio\6.0\ZM179 {or Zipmaster179 if you prefer being verbose}
	By default (on Vista) the bpl store is at <Public Documents>\RadStudio\6.0
		 
Major Changes
  The installer will now fully compile and install the component.

Delphi versions supported
 	not before 4

Directory Structure
   ...\    
  ZipMaster and  ZipSFX files
  res - Application resource files
  Delphi - design- and run-time page files
  Dll - dll
  DLL\Source - Source code for dll 
  Help - help files
  Docs - where this file resides
  Lang - Language files
  Tools - updaters for language resource strings

Configuration
  In ZipConfig.inc 
   { $DEFINE NO_SPAN}  // uncomment to remove support for multi-part zip files 
   { $DEFINE INTERNAL_SFX}  // define to include TZipSFX as part of ZipMaster 
   { $DEFINE USE_COMPRESSED_STRINGS}  // define to use compressed strings instead of 'ResourceString's. 
  

The required Delphi source files (files marked with '+' are written by ZipResMaker.exe)
    ...\
            ZipMstr.pas		 - main component source
            ZipMstr.res		 - components version resource 
            ZipVers.inc		 - required defines for Delphi versions (only 4..10 supported)
            ZipConfig.inc	 - sets compile options 
	    ZMCompat.pas	 - common types and functions used by earlier compilers
            ZMCore.pas		 - basic support functions and event triggering
            ZMDBind.pas		 - dynamically loads and binds the dll 
            ZMMsgStr.pas	 - handles message string storage and language selection
            ZMSBind.pas		 - statically binds the dll
            ZMWrkr.pas		 - does the work
            ZMHash.pas           - hash list for dir entries
            ZMXcpt.pas		 - EZipMaster definitions
            ZMDlg.pas		 - dialog box support
            ZMCtx.pas		 - Dialog box help context values
            ZMDelZip.pas	 - dll interface definitions
            ZMExtrLZ77.pas	 - extractor for LZ77 compressed streams
            ZipStructs.pas	 - definition of internal zip structures 
+           ZMDefMsgs.pas	 - default message strings and tables
+           ZipMsg.pas		 - message values
            ZMUtils.pas		 - some functions to make life easier

            ZipSFX.pas		 - component to handle SFX operations (modified version of TZipSFX)  
            SFXInterface.pas	 - types used by component
            SFXStructs.pas	 - SFX and zip internal structures
            missing_types.inc	 - types missing from various Delphi versions
            DelVer.inc		 - required defines for Delphi versions
	        DZUtils.pas		 -  (modified) utility functions for ZipSFX
            Lang2.inc		 - defines for linked language

            ZipFix.pas		 - (optional) component to repair damaged zip files
            ZipFix.res		 - 
            ZipFix.hlp		 - 
 

    ...\RES\
+          ZMRes.rc		 - resource script for compressed languages and dll
+          ZMRes.res		 - compiled resource for applications using ZipMaster (link to application)
+          *.bin		 - resource files required by ZMRes.rc	
            dzsfx_all.res	 - SFX stub resources for all languages
            dzsfx*.res		 - SFX stub resource for individual language (* is language)

    ...\Delphi\ 
            ZipMaster179D?.bpk  - design and run-time package (? is compiler version)

    ...\Design\  
            ZipMstr.dcr		 - decoration
            ZipSFX.dcr		 - decoration  

    ...\DLL\
            DelZip179.dll	 - required dll
            DelZip179.lib	 - library file for static binding the dll

    ...\DOCS\
            licence.txt		 - a copy of the licence
	        ReadMe.txt
	        Install.txt
	        Debug.txt


    ...\DLL\SOURCE\		 - C source files for the dlls (BCB 6)

    ...\TOOLS\			 - some tools for building/updating
    ...\TOOLS\RCUPD\		 - language string updater by Xavier Mor-Mur
    ...\TOOLS\ZIPRESMAKER\	 - resource maker for ZipMaster
    ...\TOOLS\SAVER\		 - zips the files into distribution packages

    ...\LANGS\
            ZipMsg.h		 - master message identifier header file
            ZipMsgUS.rc		 - master message script
            ZipMsg??.rc		 - resource language script files
            ZipMsg??.res	 - compiled language resource file
            SFX??.txt		 - language files for sfx

    ...\HELP\
            ZipMaster.hlp	 - compiled help file (Delphi 7)
            ZipMaster.chm	 - compile html file
            dzsfx.chm		 - SFX help file

    ...\HELP\SOURCE\		 - source files for help

    ...\DEMOS\DEMO1\		 - zip adder/extractor

    ...\DEMOS\DEMO2\		 - quick add/extract and dll test

    ...\DEMOS\DEMO3\		 - another add/extract example

    ...\DEMOS\DEMO4\		 - simple self installer

    ...\DEMOS\DEMO5\		 - make exe file (sfx)

    ...\DEMOS\DEMO6\		 - span multiple disks

    ...\DEMOS\DEMO7\		 - extract from stream

    ...\DEMOS\DEMO9\		 - use in thread

    ...\DEMOS\SORTGRID\
	       (Optional, used in Demos but does not need to be installed into IDE)
            SortGrid.pas	 - sort grid component 
            SortGrid.res	 - 
            SortGrid.dcr	 - 
            SortGridreg.pas	 - 
            SortGridPreview.pas	 - 
            SortGridPreview.dfm	 - 
            SortGrid.dcr	 - decoration
            SortGridD?.bpk	 - grid design and run-time package (if you want to install it)
      
     
                      Licenses
                               
	This component is subject to the 
      "GNU LESSER GENERAL PUBLIC LICENSE Version 2.1, February 1999"
     as explained in full in the Help file and in licence.txt.

 
                     DLL Source Code in C 
            
        The DLL source code is distributed separately due to it's
     size, and the fact that most Delphi users of this package
     probably don't want the C source for the DLL's.  The DLL 
     source is also freeware, and will remain that way. 
     The DLL source code needs Borland C++ Builder v5 - v6.
     
     
                     Problem Reports or Suggestions
     
     We DO want to hear your ideas!  If you find a problem with
     any part of this project, or if you just have an idea for
     us to consider, send us e-mail!
     
     But, please make sure that your bug has not already been
     reported.  Check the "official" web site often:
     
     http://www.delphizip.org/index.html
     
     Problems
     please report any to 
     problems@delphizip.org
     
     Amended and updated by
     R.Peters 
     
