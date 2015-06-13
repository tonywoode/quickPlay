@ECHO. OFF & SETLOCAL
::SET git tags from and to (to capture commits in that period)
:VARIABLES
::-------------------------------------------------------------------------------
:: Get Version info from settings file*******
::-------------------------------------------------------------------------------
SET VERSIONFILE=Version.txt
IF NOT EXIST %VERSIONFILE% (ECHO. "There's no version file, I should probably generate one FOR you" && GOTO EXIT)
FOR /f "tokens=2* delims==" %%H IN ('FIND "THISVERSION=" ^< %VERSIONFILE%') DO (SET THISVERSION=%%H)
FOR /f "tokens=2* delims==" %%H IN ('FIND "LASTVERSION=" ^< %VERSIONFILE%') DO (SET LASTVERSION=%%H)
::If we haven't read the version info, bomb
IF (%THISVERSION%)==() (ECHO. "You need to set version names in the config file" && goto EXIT)
IF (%LASTVERSION%)==() (ECHO. "You need to set version names in the config file" && goto EXIT)

SET NOTEPADPLUSPLUS="C:\Program Files (x86)\Notepad++\notepad++.exe"
SET SEVENZIP="C:\Program Files\7-Zip\7z.exe"
::todo need to make it so this could be quoted - needs param expansion ~
SET RELEASEDIR=..\Release

:MIRROR
ECHO..-------------------------------------------------------------------------------
ECHO.. QUICKPLAY RELEASE TOOL
ECHO.. Mirror QP to %RELEASEDIR%?
ECHO..-------------------------------------------------------------------------------
SET /P Select=Type 'y' FOR Yes Or 'n' FOR No:
IF /i %Select%==y (SET GO=yes) ELSE SET GO=no

IF (%GO%)==(no) (EXIT)
IF NOT EXIST %RELEASEDIR% (MKDIR %RELEASEDIR%)
ROBOCOPY /mir qp\ %RELEASEDIR%\qp\

DIR %RELEASEDIR%\qp || (ECHO.. EXITING - UNSAFE && EXIT)

:DELETE
ECHO..Really Delete the relevant QuickPlay directories IN %RELEASEDIR%?
CHOICE
IF NOT ERRORLEVEL 2 IF ERRORLEVEL 1 GOTO CARRYON
EXIT

:CARRYON
ECHO..OK let's delete this data && PAUSE
ECHO..Cleaning Up QP Directory FOR Release
RD /S /Q %RELEASEDIR%\qp\data
RD /S /Q %RELEASEDIR%\qp\dats
RD /S /Q %RELEASEDIR%\qp\search
RD /S /Q %RELEASEDIR%\qp\temp

ECHO..Cleaning up possible ini files (you may have run up some of the tools)
DEL "%RELEASEDIR%\qp\tools\Romdata Magician\RomData Magician.ini"

ECHO..Cleaning up possible EFIND files
DEL "%RELEASEDIR%\qp\EFIND\Custom.ini"
DEL "%RELEASEDIR%\qp\EFIND\Gamebase.ini"

ECHO..Cleaning up the old exe
DEL "%RELEASEDIR%\qp\qp384.exe"

ECHO..Cleaned Up Files, time to make the release notes
PAUSE
:CHANGELOG
ECHO.. Generating a nix line-ending changelog
git log --oneline --no-decorate --no-merges --pretty=tFORmat:"* %%s"  %LASTVERSION%..HEAD > %RELEASEDIR%\changelogLF

ECHO..Change that changelog at this point please - its in %RELEASEDIR% called changelogLF
IF EXIST %NOTEPADPLUSPLUS% (%NOTEPADPLUSPLUS% %RELEASEDIR%\changelogLF)
PAUSE

ECHO.. appending that list to the changelog
ECHO.. Quickplay %THISVERSION% > %RELEASEDIR%\changewin.txt
ECHO.. >> %RELEASEDIR%\changeWin.txt
:: http://stackoverflow.com/questions/3110031/batch-file-convert-lf-to-crlf
TYPE %RELEASEDIR%\changelogLF | FIND "" /V >> %RELEASEDIR%\changewin.txt
ECHO.. >> %RELEASEDIR%\changewin.txt

::concat the text files, new changes on top
COPY %RELEASEDIR%\qp\changelog.txt %RELEASEDIR%\changelog.txt
ECHO.. lets cat the changelog to the dev and release directories
PAUSE
COPY /b %RELEASEDIR%\changewin.txt+%RELEASEDIR%\changelog.txt qp\changelog.txt
COPY qp\changelog.txt %RELEASEDIR%\qp\changelog.txt
DEL %RELEASEDIR%\changelog.txt
DEL %RELEASEDIR%\changeWin.txt
ECHO.. made the changelog in the release dir

:ZIPUP
ECHO.. IF that all looks ok, I'll zip it up
PAUSE
%SEVENZIP% a %RELEASEDIR%\QP-%THISVERSION%.zip -r %RELEASEDIR%\qp 2<&1
::	Check that the archiving went ok. Otherwise report
SET error=%ERRORLEVEL%
IF %ERROR% NEQ 0 GOTO PROBLEM
:: 	Now test archive - note I've specified recursive testing of folders inside the archive,
::	and output error and stdout to log -don't think either make any difference
ECHO..Made ZIP, now testing... 
%SEVENZIP% t -r %RELEASEDIR%\QP-%THISVERSION%.zip 2>&1
SET error=%ERRORLEVEL%
IF %ERROR% EQU 0 ECHO..all OK
IF %ERROR% NEQ 0 GOTO PROBLEM
ECHO..ARCHIVE FOLDER CHECKS OK - DELETING SOURCE
PAUSE
rd /s /q %RELEASEDIR%\qp 2>&1
SET error=%ERRORLEVEL%
IF %ERROR% EQU 0 ECHO.. DELETED QP Folder as zip tested fine
IF %ERROR% NEQ 0 GOTO PROBLEM
GOTO END

:PROBLEM
ECHO.. Sorry bud, something went wrong zipping
PAUSE

:END
ECHO..done - upload me!
ECHO..(if you did make a mistake though don't FORget the release notes in the dev dir)
PAUSE
