--------------------------------------------------------------------------------

JEDI Code Library
Release 2.1
Build 3536
05-November-2009

--------------------------------------------------------------------------------

Content of this file
About this release
Supported tools
Installation notes
Manual installation
Distribution content
Giving your feedback
Reporting bugs
Downloads of stable sources
Development sources
Getting involved in JCL development

--------------------------------------------------------------------------------

About this release
JCL release 2.0 provides improved support for RAD Studio 2010 (including
Delphi 2010 and C++Builder 2010) an updated support for all targets.

This new version of the JCL is mainly a bugfix release. Multiple bugs have been
fixed; for detailed change logs, use the facilities of our Subversion repository
at Sourceforge.net http://sourceforge.net/projects/jcl/, see below.

Head changes:
 - fix major issues in JclAnsiStrings: wrong index arithmetics in StrSearch,
   flawed implementation of TJclAnsiStrings...
 - fix issue in JclRegistry: wrong exceptions were raised under some rare
   circumstances;
 - experts: the compilation of projects with type library was not possible,
   fixed wrong MAP file name computations...
 - debug information from MAP file: better handling of the MAP files generated
   by C++Builder;
 - all resources are now loaded using LoadResString;
 - streams: TJclBufferedStream wipes data on append;
 - open and save dialog hooks: moved to runtime code (they can now be added to
   any application);
 - compression: new 7z 9.7.0 compression classes.


Important:

 - As of JCL 2.0, the library does not support Delphi 5, C++Builder 5, Kylix 3
   and Delphi.net anymore;

(Windows only) Installation options:

  Packages compiled by the JCL installer don't contain any debug informations to
keep their size as small as possible.

  The JEDI Code Library packages are required by some 3rd party packages
(including the JEDI Visual Component Library - JVCL), the installer generates
them if the "Packages" node is checked.

  The installer can generate MAP informations for each package. These
informations can be linked into binaries to become JCL debug data or be
converted to .jdbg files. Once linked MAP files could be deleted. These options
are subnodes of the "Packages" node.

  For BDS 2006, RAD Studio 2007, RAD Studio 2009 and RAD Studio 2010, the
compiler introduced a new option to make the same packages available in C++,
by checking the "Dual packages" option of the "Packages" node, you will be able
to call functions of the JCL from C++ code.

--------------------------------------------------------------------------------

Supported Tools
The JCL can be compiled and installed in the following environments

Only runtime support:
 - FreePascal (tested with 2.2.2 and 2.2.4).

Only design-time support (only experts):
 - C#Builder 1 (cf Installation notes);
 - Delphi 8.net (cf Installation notes).

Both supports (run time and design time):
 - Delphi 6, Delphi 7 and Delphi 2005;
 - C++Builder 6;
 - Delphi 2005 (without unit versioning support);
 - Borland Developer Studio 2006 (Delphi for Win32, C++Builder for Win32,
   Delphi.net and C#Builder personalities);
 - Turbo Delphi (explorer and professional - cf Installation notes);
 - CodeGear RAD Studio 2007 (Delphi for Win32 and C++Builder for Win32
   personalities);
 - CodeGear Delphi 2009 and C++Builder 2009;
 - CodeGear Delphi 2010 and C++Builder 2010.

--------------------------------------------------------------------------------

Installation notes

 - Free Pascal (http://www.freepascal.org/) support has been updated for
   this release; most units fromsource/common work with FP 2.2.

Installation for Turbo Delphi

The JEDI Code Library can be compiled targetting Turbo Delphi Explorer and Turbo
Delphi Professional. Turbo Delphi Professional is recognized as BDS 2006, you
have to download its command line compiler from CodeGear website at
http://www.codegear.com/Default.aspx?tabid=160  to install the full JCL on this
tool.

To install the JCL targetting Turbo Delphi Explorer, consider the following
checks:

 - If you have an other supported version of Delphi/C++Builder on this computer,
   it should automatically be detected and the installer will process as usual.
 - If you only have Turbo Delphi Explorer (and no other tools) on the computer,
   the installer cannot becompiled. You have to use the Turbo Explorer flavor of
   the JCL that contains a precompiled installer. However, you will not be able
   to install any experts.

Installation on C#Builder 1 and Delphi 8:

 - These products cannot be used to build the JCL installer, you need an other
   supported product to install JCL experts on these products.
 - These products are not able to use the JCL library as a runtime library. You
   cannot write managed applications and managed packages based on the JCL.
 - These products are not shipped with their native compilers, you have to
   download it from codecentral (http://cc.codegear.com/). The item
   (http://codecentral.codegear.com/Download.aspx?id=21333) contains the native
   compiler to be installed in Delphi 8. The item
   (http://codecentral.codegear.com/Download.aspx?id=21334) contains the native
   compiler to be installed in C#Builder 1. These zip files have to be extracted
   in the products directory using the standard pattern:
		   Executable files (exe and dll)      - BDS\X.0\bin
		   Compiler files (dcp and dcu)        - BDS\X.0\lib
		   Toolsapi source files               - BDS\X.0\source\ToolsAPI

Default installation

For all others versions of Delphi, C++Builder and BDS, simply launch Install.bat
and the installer window will let you configure options and install the library.

--------------------------------------------------------------------------------

Manual Installation
Although it is not recommended, a manual installation is possible. You will have
to manually configure options for the library. That is done by modifying an
included file.

For each tool you want to install the JCL in, repeat the following steps:

1. Open and edit included file to customize options:
 - For C++Builder 6: source\include\jclc6.inc
 - For Delphi 6: source\include\jcld6.inc
 - For Delphi 7: source\include\jcld7.inc
 - For Delphi 2005: source\include\jcld9.inc
 - For Delphi.net 2005: source\include\jcld9.net.inc
 - For BDS 2006 (Delphi and C++Builder): source\include\jcld10.inc
 - For Delphi.net 2006: source\include\jcld10.net.inc
 - For CodeGear Delphi 2007 for Win32 and C++Builder 2007: source\include\jcld11.inc
 - For Delphi.net 2007: source\include\jcld11.net.inc
 - For Delphi 2009 and C++Builder 2009: source\include\include\jcld12.inc
 - For Delphi 2010 and C++Builder 2010: source\include\include\jcld14.inc
 - For FreePascal: source\include\jclfpc.inc

2. In the IDE, open and compile package Jcl.dpk (or Jcl.bpk for C++Builder)
located in a subdirectory of the "packages" directory matching your version of
the IDE. This package doesn't have to be installed since it doesn't provide any
components.

3. If you want to install experts, open package JclBaseExpert.dpk and compile
it, then you can install all the experts you want (packages are located in the
same directory).

--------------------------------------------------------------------------------

Distribution content
Install.bat                   - Compile and run VCL version of the JCL Installer (Win32)
QInstall.bat                  - Compile and run CLX version of JCL Installer (Win32)
install.sh                    - Compile and run JCL Installer (Linux)
bin                           - Common place for sample application EXE files
lib                           - Common place for compiled units.
docs                          - Readme (this file) and other documents
docs\Readme.html              - This file
docs\Experts.html             - Readme file about the experts
docs\MPL-1.1.txt              - The Mozilla Public Licence (MPL) version 1.1
docs\MPL FAQ.html             - Frequently Asked Questions about the MPL
docs\cps.html                 - Cross Platform Strategy
experts                       - JCL IDE experts source code
experts\debug                 - JCL Debug IDE expert for using JclDebug unit
experts\debug\dialog          - Application exception dialog replacement
experts\debug\simdview        - Low-level debug window for XMM registers
experts\debug\threadnames     - IDE expert showing class names for debugged threads
experts\debug\tools           - Tools for creating files with JCL debug information
experts\favfolders            - Favorite folders combobox in IDE open/save file dialogs
experts\projectanalyzer       - Project Analyzer IDE expert
experts\repository            - Repository expert
experts\stacktraceviewer      - stack trace expert
experts\useswizard            - JCL uses wizard
experts\versioncontrol        - Integration of TortoiseCVS and TortoiseSVN in the IDE
examples                      - JCL example applications
examples\common               - CLX and Win32 example applications in Delphi
examples\dotnet               - JCL example applications for Delphi.net
examples\windows              - JCL example applications for Delphi.Win32
examples\windows\delphitools  - Collection of system tools using JCL
help                          - Help file (distributed in a separate archive)
install                       - Installer source code
packages                      - JCL package sources
source                        - JCL source code

--------------------------------------------------------------------------------

Giving your feedback

If you have any comments or suggestions we would appreciate it if you drop us a
note. There are several ways to get in contact with us:
 - Newsgroup is the recommended way to contact other JCL users and the team
   itself. They are hosted at news://forums.talkto.net/jedi.jcl.
 - Write to jcl@delphi-jedi.org  or to jcl-testing@delphi-jedi.org  This email
   account should not be used for support requests. If you need support please
   use either the newsgroups or the mailing list.
 - If you want to keep up to date about JCL then you can join the JCL mailing
   list by going to http://tech.groups.yahoo.com/group/JEDI-JCL/You can also use
   this list to voice your opinion, comments or suggestions.

--------------------------------------------------------------------------------

Reporting bugs

The general rule is: If you want to get a bug fixed you need to log it!

An issue tracking tool can be accessed via ('Code Library' category):
http://issuetracker.delphi-jedi.org/

Please be aware that you are allowed there to enter feature request and code
donations as well.

The JEDI issue tracker is based up on the Mantis BugTracker Open Source project.
More background information about it is available on its homepage
http://mantisbt.sourceforge.net

--------------------------------------------------------------------------------

Downloads of stable sources

These sources are official JCL releases and file status can be considered as
stable for use in final applications. During the past years, there have been
around 2 or 3 releases per year.

JEDI Code Library: File List on SourceForge:
http://sourceforge.net/project/showfiles.php?group_id=47514

--------------------------------------------------------------------------------

Development sources

These files are under active development and may cause some incompatibilities
and some conflicts with existing code. You should not use these files in final
applications. The JCL development team provides these files for testing and
feedback from users.

You can download snapshots of the Subversion repository updated every day in the
JCL daily page  http://jcl.sourceforge.net/daily/

To always have access to the most recent changes in the JCL, you should install
a Subversion client (we recommend TortoiseSVN http://tortoisesvn.tigris.org/and
RapidSVN http://rapidsvn.tigris.org/) and download the SVN repository files to
your computer as explained in the repository page of the JEDI Wiki at
http://wiki.delphi-jedi.org/index.php?title=Repository With the SVN
client, you can update your local repository at any time. You can also view the
repository online via the web interface at http://jcl.svn.sourceforge.net/

--------------------------------------------------------------------------------

Getting involved in JCL development

If you want to help out making JCL better or bigger or just plain cooler, there
are several ways in which you can help out. Here are some of the things we need
your help on:
 - Donate source code
 - Donate time writing help
 - Donate time writing demos
 - Donate time fixing bugs
 - Share your experience by helping users in newsgroups and mailing lists

  JCL accepts donations from developers as long as the source fullfills the
requirements set up by the JEDI and JCL teams. To read more about these
requirements, visit the page http://jcl.delphi-jedi.org/

  You can also donate your time by writing help for the source already in JCL.
We currently use Doc-o-Matic to create the finished help files but the actual
help sources are plain text files in a simple to understand format. We can
provide you with auto-generated templates with all classes, properties,
types etc already inserted. The "only" thing left to do is fill in the actual
help text for the help items. If you are interested in writing help, contact us.

If you want to help fix bugs in JCL, go to Mantis and check the bug report
there. You can post replies as well as fixes directly in the bug report. One of
the JCL developers will pick up the report/fix and update the Subversion
repository if the fi is satisfactory. If you report and fix a lot of bugs, you
might even get developer access to SVN so you can update the JCL files directly.

