@ECHO OFF & SETLOCAL
::set git tags from and to (to capture commits in that period)
set LASTVERSION=v4.1.0
set THISVERSION=v4.1.1
set NOTEPADPLUSPLUS="C:\Program Files (x86)\Notepad++\notepad++.exe"

ECHO Generating a nix line-ending changelog
git log --oneline --no-decorate --no-merges --pretty=tformat:"* %%s"  %LASTVERSION%..HEAD > changelogLF

echo."Change that changelog at this point please - its in this scripts dir called changelogLF"
if exist %NOTEPADPLUSPLUS% (%NOTEPADPLUSPLUS% changelogLF)
pause

ECHO appending that list to the changelog
echo Quickplay %THISVERSION% > changewin.txt
echo. >> changeWin.txt
:: http://stackoverflow.com/questions/3110031/batch-file-convert-lf-to-crlf
type changelogLF | FIND "" /V >> changewin.txt
echo. >> changewin.txt

::concat the text files, new changes on top
copy qp\changelog.txt changelog.txt
copy /b changewin.txt+changelog.txt qp\changelog.txt
del changelog.txt
del changeWin.txt
ECHO made the changelog
pause