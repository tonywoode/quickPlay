@ECHO OFF & SETLOCAL ENABLEDELAYEDEXPANSION
::SET git tags from and to (to capture commits in that period)
:VARIABLES
::-------------------------------------------------------------------------------
:: Get Version info from settings file*******
::-------------------------------------------------------------------------------
SET VERSIONFILE=..\Release\Version.txt
::get the last two git tags (note %% not % below to pass through cmd)
git for-each-ref refs/tags --sort=-taggerdate --format=%%(refname)%%0d%%0a --count=2 > %VERSIONFILE%
ECHO.Top line is current Quickplay version, the previous version is the line above >> %VERSIONFILE%
IF NOT EXIST %VERSIONFILE% (ECHO. "There's no version file, git for-each-ref was supposed to make one" && GOTO EXIT)
::Get the version numbers of the latest revisions
SET X=0
FOR /F "tokens=3* delims=/" %%I in (%VERSIONFILE%) do (
    SET /A X=!X! + 1
    SET VAR!X!=%%I
	::We want a current and a previous version only
	IF !X! GTR 2 GOTO ENDLOOP
)
:ENDLOOP
SET THISVERSION=%var1%
SET LASTVERSION=%var2%
IF (%THISVERSION%)==() (ECHO. "somethings gone wrong" && goto EXIT)
IF (%LASTVERSION%)==() (ECHO. "Somethings gone wrong" && goto EXIT)

SET NOTEPADPLUSPLUS="C:\Program Files\Notepad++\notepad++.exe"
SET SEVENZIP="C:\Program Files\7-Zip\7z.exe"
::todo need to make it so this could be quoted - needs param expansion ~
SET RELEASEDIR=..\Release

:MIRROR
ECHO.-------------------------------------------------------------------------------
ECHO. QUICKPLAY RELEASE TOOL
ECHO. Let's prepare the release from %LASTVERSION% to %THISVERSION%
ECHO. We'll being by mirroring QP to %RELEASEDIR% - ok?
ECHO.-------------------------------------------------------------------------------
SET /P Select=Type 'y' FOR Yes Or 'n' FOR No:
IF /i %Select%==y (SET GO=yes) ELSE SET GO=no

IF (%GO%)==(no) (EXIT)
IF NOT EXIST %RELEASEDIR% (MKDIR %RELEASEDIR%)
ROBOCOPY /mir qp\ %RELEASEDIR%\qp\

DIR %RELEASEDIR%\qp || (ECHO. EXITING - UNSAFE && EXIT)

:DELETE
ECHO.Ok copied. Now its safe to delete the relevant QuickPlay directories IN %RELEASEDIR%\qp, right?
CHOICE
IF NOT ERRORLEVEL 2 IF ERRORLEVEL 1 GOTO CARRYON
EXIT

:CARRYON
ECHO.OK let's delete this data
ECHO.Cleaning Up QP Directory FOR Release
RD /S /Q %RELEASEDIR%\qp\data
RD /S /Q %RELEASEDIR%\qp\data_PREV
RD /S /Q %RELEASEDIR%\qp\data_REAL
RD /S /Q %RELEASEDIR%\qp\data_FAKE
RD /S /Q %RELEASEDIR%\qp\dats
RD /S /Q %RELEASEDIR%\qp\search
RD /S /Q %RELEASEDIR%\qp\temp

ECHO.Cleaning up possible ini files (you may have run up some of the tools)
DEL "%RELEASEDIR%\qp\tools\Romdata Magician\RomData Magician.ini"

ECHO.Cleaning up a node modules dir in updates/src
RD /S /Q  "%RELEASEDIR%\qp\updates\src\node_modules"

ECHO.Cleaning up possible EFIND files
DEL "%RELEASEDIR%\qp\EFIND\Custom.ini"
DEL "%RELEASEDIR%\qp\EFIND\Gamebase.ini"

ECHO.Cleaning up the old exe
DEL "%RELEASEDIR%\qp\qp384.exe"

ECHO.Cleaning up the Mametool logfile
DEL "%RELEASEDIR%\qp\mametool_logfile.txt"

ECHO.Cleaning up other detrius
DEL "%RELEASEDIR%\qp\._.DS_Store"
DEL "%RELEASEDIR%\qp\.DS_Store"


ECHO.Cleaned Up Files, time to make the release notes
PAUSE
:CHANGELOG
ECHO.Generating a nix line-ending changelog
git log --oneline --no-decorate --no-merges --pretty=tformat:"* %%s"  %LASTVERSION%..HEAD > %RELEASEDIR%\changelogLF

ECHO.Change that changelog at this point please - its in %RELEASEDIR% called changelogLF
IF EXIST %NOTEPADPLUSPLUS% (%NOTEPADPLUSPLUS% %RELEASEDIR%\changelogLF)
PAUSE

ECHO. appending that list to the changelog
ECHO.Quickplay %THISVERSION% > %RELEASEDIR%\changewin.txt
ECHO. >> %RELEASEDIR%\changeWin.txt
:: http://stackoverflow.com/questions/3110031/batch-file-convert-lf-to-crlf
TYPE %RELEASEDIR%\changelogLF | FIND "" /V >> %RELEASEDIR%\changewin.txt
ECHO. >> %RELEASEDIR%\changewin.txt

::concat the text files, new changes on top
COPY %RELEASEDIR%\qp\changelog.txt %RELEASEDIR%\changelog.txt
ECHO. lets cat the changelog to the dev and release directories
PAUSE
COPY /b %RELEASEDIR%\changewin.txt+%RELEASEDIR%\changelog.txt qp\changelog.txt
COPY qp\changelog.txt %RELEASEDIR%\qp\changelog.txt
DEL %RELEASEDIR%\changelog.txt
DEL %RELEASEDIR%\changeWin.txt
ECHO. made the changelog in the release dir

:ZIPUP
ECHO. IF that all looks ok, I'll zip it up
PAUSE
%SEVENZIP% a %RELEASEDIR%\QP-%THISVERSION%.zip -r %RELEASEDIR%\qp 2<&1
::	Check that the archiving went ok. Otherwise report
SET error=%ERRORLEVEL%
IF %ERROR% NEQ 0 GOTO PROBLEM
:: 	Now test archive - note I've specified recursive testing of folders inside the archive,
::	and output error and stdout to log -don't think either make any difference
ECHO.Made ZIP, now testing... 
%SEVENZIP% t -r %RELEASEDIR%\QP-%THISVERSION%.zip 2>&1
SET error=%ERRORLEVEL%
IF %ERROR% EQU 0 ECHO.all OK
IF %ERROR% NEQ 0 GOTO PROBLEM
ECHO.ARCHIVE FOLDER CHECKS OK - DELETING SOURCE
PAUSE
rd /s /q %RELEASEDIR%\qp 2>&1
SET error=%ERRORLEVEL%
IF %ERROR% EQU 0 ECHO. DELETED QP Folder as zip tested fine
IF %ERROR% NEQ 0 GOTO PROBLEM
GOTO END

:PROBLEM
ECHO. Sorry bud, something went wrong zipping
PAUSE

:END
ECHO.done - upload me!
ECHO.(if you did make a mistake though delete the top off the release notes in the dev dir)
PAUSE
