@ECHO OFF & SETLOCAL
::set git tags from and to (to capture commits in that period)
:VARIABLES
set LASTVERSION=v4.1.0
set THISVERSION=v4.1.1
set NOTEPADPLUSPLUS="C:\Program Files (x86)\Notepad++\notepad++.exe"
set ReleaseDir=..\Release

:MIRROR
ECHO.-------------------------------------------------------------------------------
ECHO. QUICKPLAY RELEASE TOOL
ECHO. Mirror QP to %ReleaseDir%?
ECHO.-------------------------------------------------------------------------------
SET /P Select=Type 'y' for Yes Or 'n' for No:
IF /i %Select%==y (set GO=yes) else set GO=no

IF (%GO%)==(no) (exit)
IF NOT EXIST %ReleaseDir% (mkdir %ReleaseDir%)
robocopy /mir qp\ %ReleaseDir%\qp\

dir %ReleaseDir%\qp || (ECHO. EXITING - UNSAFE && exit)

:DELETE
ECHO.Really Delete the relevant QuickPlay directories IN %ReleaseDir%?
choice
IF NOT ERRORLEVEL 2 IF ERRORLEVEL 1 goto CARRYON
exit

:CARRYON
ECHO.OK let's delete this data && pause
ECHO.Cleaning Up QP Directory for Release
rd /S /Q %ReleaseDir%\qp\data
rd /S /Q %ReleaseDir%\qp\dats
rd /S /Q %ReleaseDir%\qp\search
rd /S /Q %ReleaseDir%\qp\temp

ECHO.Cleaning up possible ini files (you may have run up some of the tools)
del "%ReleaseDir%\qp\tools\Romdata Magician\RomData Magician.ini"

ECHO.Cleaning up possible EFind files
del "%ReleaseDir%\qp\EFind\Custom.ini"
del "%ReleaseDir%\qp\EFind\Gamebase.ini"

ECHO.Cleaned Up Files, time to make the release notes...
pause
:CHANGELOG
ECHO. Generating a nix line-ending changelog
git log --oneline --no-decorate --no-merges --pretty=tformat:"* %%s"  %LASTVERSION%..HEAD > %ReleaseDir%\changelogLF

ECHO.Change that changelog at this point please - its in %ReleaseDir% called changelogLF
if exist %NOTEPADPLUSPLUS% (%NOTEPADPLUSPLUS% %ReleaseDir%\changelogLF)
pause

ECHO. appending that list to the changelog
ECHO. Quickplay %THISVERSION% > %ReleaseDir%\changewin.txt
ECHO. >> %ReleaseDir%\changeWin.txt
:: http://stackoverflow.com/questions/3110031/batch-file-convert-lf-to-crlf
type %ReleaseDir%\changelogLF | FIND "" /V >> %ReleaseDir%\changewin.txt
ECHO. >> %ReleaseDir%\changewin.txt

::concat the text files, new changes on top
copy %ReleaseDir%\qp\changelog.txt %ReleaseDir%\changelog.txt
ECHO. lets cat the changelog to the dev and release directories
pause
copy /b %ReleaseDir%\changewin.txt+%ReleaseDir%\changelog.txt qp\changelog.txt
copy qp\changelog.txt %ReleaseDir%\qp\changelog.txt
del %ReleaseDir%\changelog.txt
del %ReleaseDir%\changeWin.txt
ECHO. made the changelog in the release dir

:ZIPUP
ECHO. If that all looks ok, I'll zip it up

