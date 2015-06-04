@ECHO OFF & SETLOCAL
::SET git tags from and to (to capture commits in that period)
:VARIABLES
SET LASTVERSION=v4.1.0
SET THISVERSION=v4.1.1
SET NOTEPADPLUSPLUS="C:\Program Files (x86)\Notepad++\notepad++.exe"
SET SEVENZIP="C:\Program Files\7-Zip\7z.exe"
::todo need to make it so this could be quoted - needs param expansion ~
SET RELEASEDIR=..\Release

:MIRROR
ECHO.-------------------------------------------------------------------------------
ECHO. QUICKPLAY RELEASE TOOL
ECHO. Mirror QP to %RELEASEDIR%?
ECHO.-------------------------------------------------------------------------------
SET /P Select=Type 'y' for Yes Or 'n' for No:
IF /i %Select%==y (SET GO=yes) ELSE SET GO=no

IF (%GO%)==(no) (exit)
IF NOT EXIST %RELEASEDIR% (mkdir %RELEASEDIR%)
roboCOPY /mir qp\ %RELEASEDIR%\qp\

DIR %RELEASEDIR%\qp || (ECHO. EXITING - UNSAFE && exit)

:DELETE
ECHO.Really Delete the relevant QuickPlay directories IN %RELEASEDIR%?
choice
IF NOT ERRORLEVEL 2 IF ERRORLEVEL 1 GOTO CARRYON
exit

:CARRYON
ECHO.OK let's delete this data && PAUSE
ECHO.Cleaning Up QP Directory for Release
rd /S /Q %RELEASEDIR%\qp\data
rd /S /Q %RELEASEDIR%\qp\dats
rd /S /Q %RELEASEDIR%\qp\search
rd /S /Q %RELEASEDIR%\qp\temp

ECHO.Cleaning up possible ini files (you may have run up some of the tools)
DEL "%RELEASEDIR%\qp\tools\Romdata Magician\RomData Magician.ini"

ECHO.Cleaning up possible EFind files
DEL "%RELEASEDIR%\qp\EFind\Custom.ini"
DEL "%RELEASEDIR%\qp\EFind\Gamebase.ini"

ECHO.Cleaning up the old exe
DEL "%RELEASEDIR%\qp\qp384.exe"

ECHO.Cleaned Up Files, time to make the release notes...
PAUSE
:CHANGELOG
ECHO. Generating a nix line-ending changelog
git log --oneline --no-decorate --no-merges --pretty=tformat:"* %%s"  %LASTVERSION%..HEAD > %RELEASEDIR%\changelogLF

ECHO.Change that changelog at this point please - its in %RELEASEDIR% called changelogLF
IF EXIST %NOTEPADPLUSPLUS% (%NOTEPADPLUSPLUS% %RELEASEDIR%\changelogLF)
PAUSE

ECHO. appending that list to the changelog
ECHO. Quickplay %THISVERSION% > %RELEASEDIR%\changewin.txt
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
SET error=%errorlevel%
IF %error% NEQ 0 GOTO PROBLEM
:: 	Now test archive - note I've specified recursive testing of folders inside the archive,
::	and output error and stdout to log -don't think either make any difference
ECHO.Made ZIP, now testing... 
%SEVENZIP% t -r %RELEASEDIR%\QP-%THISVERSION%.zip 2>&1
SET error=%errorlevel%
IF %error% EQU 0 ECHO.all OK
IF %error% NEQ 0 GOTO PROBLEM
ECHO.ARCHIVE FOLDER CHECKS OK - DELETING SOURCE....
PAUSE
rd /s /q %RELEASEDIR%\qp 2>&1
SET error=%errorlevel%
IF %error% EQU 0 ECHO. DELETED QP Folder as zip tested fine
IF %error% NEQ 0 GOTO PROBLEM
GOTO END

:PROBLEM
ECHO. Sorry bud, something went wrong zipping....
PAUSE

:END
ECHO.done - upload me!
PAUSE
