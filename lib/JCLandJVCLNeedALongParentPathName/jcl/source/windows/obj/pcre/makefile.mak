#
# makefile to make pcre .obj files using Borland's C++ compiler bcc32
# derived from a makefile generated by BCB6' bpr2mak
#
# if pcre source directory is different from $(JCL)\source\pcre-7.9, use
# "make -Dpcresrc=<path to pcre sources>" to tell make where to find the 
# source files
#
# Make.exe needs to reside in the same directory as bcc32.exe.
# For example, if you have Borlands free C++ v. 5.5 compiler (available from
# http://www.borland.com/products/downloads/download_cbuilder.html#) installed:
#
# >C:\Program Files\Borland\BCC55\Bin\make
#
# or, if you want to use C++ Builder 6:
#
# >C:\Program Files\Borland\CBuilder6\Bin\make
#
# or, if you want to use Borland Developer Studio 2006:
#
# >C:\Program files\Borland\BDS\4.0\bin\make
#
# To choose the target CPU, pass "-DCPU=n" as option to make, with n being a
# number between 3 and 6, with the following meanings:
#
#   n   Target CPU (or compatible)
# --------------------------------
#   3   80386
#   4   80486
#   5   Pentium (default)
#   6   Pentium Pro
#
# Robert Rossmair, 2004-10-16
#

CallingConvention = -pr

!if !$d(BCB)
BCB = $(MAKEDIR)\..
!endif

BCC = $(BCB)

!if !$d(pcresrc)
pcresrc = ..\..\..\pcre-7.9
!endif

!if !$d(CPU)
CPU = 5         # Pentium
!endif

# ---------------------------------------------------------------------------
# IDE SECTION
# ---------------------------------------------------------------------------
# The following section of the project makefile is managed by the BCB IDE.
# It is recommended to use the IDE to change any of the values in this
# section.
# ---------------------------------------------------------------------------

VERSION = BCB.06.00
# ---------------------------------------------------------------------------
OBJFILES = .\pcre_compile.obj .\pcre_config.obj .\pcre_dfa_exec.obj \
  .\pcre_exec.obj .\pcre_fullinfo.obj .\pcre_get.obj .\pcre_globals.obj \
  .\pcre_info.obj .\pcre_maketables.obj .\pcre_newline.obj \
  .\pcre_ord2utf8.obj .\pcre_refcount.obj .\pcre_study.obj .\pcre_tables.obj \
  .\pcre_try_flipped.obj .\pcre_ucd.obj .\pcre_valid_utf8.obj \
  .\pcre_version.obj .\pcre_xclass.obj .\pcre_default_tables.obj

# ---------------------------------------------------------------------------
DEBUGLIBPATH = $(BCB)\lib\debug
RELEASELIBPATH = $(BCB)\lib\release
USERDEFINES = SUPPORT_UTF8;SUPPORT_UCP
SYSDEFINES = NO_STRICT;_NO_VCL;_RTLDLL
INCLUDEPATH = $(pcresrc);$(BCC)\include;$(BCB)\include\vcl
LIBPATH = $(BCB)\lib\obj;$(BCB)\lib
# LIBPATH = $(pcresrc)
WARNINGS= -wpar -w-aus
PATHC = .;$(pcresrc)
# PATHOBJ = .;$(LIBPATH)
ALLLIB = import32.lib cw32i.lib
# ---------------------------------------------------------------------------
CFLAG1 = -O2 -Ve -X- -a8 -$(CPU) -b -d -k- -vi -tWM- -DHAVE_CONFIG_H

LFLAGS = -D"" -ap -Tpe -x -Gn
# ---------------------------------------------------------------------------
# MAKE SECTION
# ---------------------------------------------------------------------------
# This section of the project file is not used by the BCB IDE.  It is for
# the benefit of building from the command-line using the MAKE utility.
# ---------------------------------------------------------------------------

.autodepend
# ---------------------------------------------------------------------------

!if !$d(BCC32)
BCC32 = bcc32
!endif

!if !$d(LINKER)
LINKER = ilink32
!endif

# ---------------------------------------------------------------------------
!if $d(PATHC)
.PATH.C   = $(PATHC)
!endif

# ---------------------------------------------------------------------------
pcre: includes tables $(OBJFILES)

# ---------------------------------------------------------------------------
.c.obj:
    $(BCC)\BIN\$(BCC32) -c $(CFLAG1) $(CallingConvention) $(WARNINGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) -n$(@D) {$< }

includes:
    copy /Y $(pcresrc)\pcre.h.generic $(pcresrc)\pcre.h
    copy /Y $(pcresrc)\config.h.generic $(pcresrc)\config.h

tables:
    $(BCC)\BIN\$(BCC32) -c -tWC $(CFLAG1) $(WARNINGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) -n.\ $(pcresrc)\dftables.c
    $(BCC)\BIN\$(LINKER) $(LFLAGS) -L$(LIBPATH) c0x32.obj .\dftables.obj, .\dftables.exe,, $(ALLLIB),,
    del dftables.tds
    del dftables.obj
    dftables.exe pcre_default_tables.c
    del dftables.exe
# ---------------------------------------------------------------------------




