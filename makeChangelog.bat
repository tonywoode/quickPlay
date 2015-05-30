set LASTVERSION=v4.1.0
set THISVERSION=v4.1.1

copy qp\changelog.txt changelog.txt

git log --oneline --no-decorate --no-merges --pretty=tformat:"* %%s"  %LASTVERSION%..HEAD > changelogLF
echo."Change the changelog at this point please - its in this scripts dir called changelogLF"
pause
echo Quickplay %THISVERSION% > changewin.txt
echo. >> changeWin.txt
type changelogLF | FIND "" /V >> changewin.txt
echo. >> changewin.txt

copy /b changewin.txt+changelog.txt qp\changelog.txt
del changelog.txt
del changeWin.txt
