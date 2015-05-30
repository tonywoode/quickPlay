set LASTVERSION=v4.1.0
set THISVERSION=v4.1.1
git log --oneline --no-decorate --no-merges --pretty=tformat:"* %%s"  %LASTVERSION%..%THISVERSION% > changelogLF
echo Quickplay %THISVERSION% > changewin.txt
echo. >> changeWin.txt
type changelogLF | FIND "" /V >> changeWin.txt
echo. >> changeWin.txt