::@ECHO OFF & 
::don't use delayed expansion until necessary or your exclamation marks are toast
SETLOCAL DISABLEDELAYEDEXPANSION

:: Quickplay Multiloader by butter100fly - needs you to install 7zip and daemon tools
::
:: We may get quoted or unquoted 8:3 as input, or fullnames: general principle: cast if possible, 
::  and always quote when setting vars and never when using vars. 
:: Unit test will test fullnames and shortnames, and roms that include ampersands and exclamation marks

set _SCRIPTDIR="%~dp0"
if exist %_SCRIPTDIR%Multiloader.ini (set _INIFILE=%_SCRIPTDIR%Multiloader.ini)

:: You must set these in the ini file: where to extract to, which drive letter for daemon tools ,and which for daemon's zip support
for /f "tokens=2* delims==" %%H in ('find "TEMPDIR=" ^< %_INIFILE%') do (set TEMPDIR=%%H)
if (%TEMPDIR%)==() (for /D %%I IN (%1) do set _TEMPDIR=%%~dpnsN\) else (for /D %%I IN (%1) do set _TEMPDIR=%TEMPDIR%)
for /f "tokens=2* delims==" %%J in ('find "DAEMON_DRIVE=" ^< %_INIFILE%') do (set DAEMON_DRIVE=%%J)
if (%DAEMON_DRIVE%)==() (set _DAEMON_DRIVE=K) else (SET _DAEMON_DRIVE=%DAEMON_DRIVE%)
for /f "tokens=2* delims==" %%N in ('find "CLEANTEMP=" ^< %_INIFILE%') do (set _CLEANTEMP=%%N)

:: Parameters you pass to me - don't put a space before the ampersands or the var string gets a space
set _ROMNAME=%1& set EMU=%2& set OPTIONS=%~3& set NOMOUNT=%~4& set OVERRIDE=%~5

:: CD to EMU dir - If there isn't an emu, we have an error that will hang the script
:CHECK_EMU
if exist %EMU% (cd /d %EMU%\.. && goto START_ME)
:BLOW UP
if exist ".\README.txt" (notepad.exe ".\README.txt" & EXIT)
exit /b

:START_ME
Set "longname=undefined"
call :SHORT_TO_LONG_NAME %_ROMNAME% longname
set _ROMNAME = "%longname%"

call :SPLITNAMEANDPATH %_ROMNAME%
echo %rompath%
echo %filename%

:: here's the order we'll look for filetypes in (reverse) unless you override
:MAKELIST
set typeList=(.pdi .isz .bwt .b6t .b5t .nrg .iso .img .cdi .mdx .mds .ccd .bin .cue .gcm .gdi)
set typeListWithWildcards=(*.pdi *.isz *.bwt *.b6t *.b5t *.nrg *.iso *.img *.cdi *.mdx *.mds *.ccd *.bin *.cue *.gcm *.gdi)

:: don't try moving files that we've already got cached
:: Do test zips previously cached, and recopy them if they appear corrupt
:CLASSIFY_ZIP
:: we won't get far in windows emulation without 7zip
call :CHECK_7Z
if /I (%~x1)==(.gcz) set ARCHIVE_TYPE=proprietary
if /I (%~x1)==(.cso) set ARCHIVE_TYPE=proprietary
if /I (%~x1)==(.zip) set ARCHIVE_TYPE=zip
if /I (%~x1)==(.rar) set ARCHIVE_TYPE=zip
if /I (%~x1)==(.ace) set ARCHIVE_TYPE=zip
if /I (%~x1)==(.7z)  set ARCHIVE_TYPE=zip

:: Daemon tools can mount archives, but only zips right now
if /I (%~x1)==(.zip) set ZIP_MOUNTABLE=yes

:CACHE
::  A problem we have is we often pass in 8:3 names just to shorten filename, as some game names
::   are notoriously long, so we get the long name for both robocopy and the list function of 7zip with dir /B
::  http://stackoverflow.com/a/34473971. Batch can't set variables to output like nix, says set /p can read from a file http://stackoverflow.com/a/19024533,
::     but that didn't work for me, instead we use the nix-style backtick of for /f
::   TODO: non 7zip/7z will never try to RE-copy from source, so delete corrupt one's manually

for /f "usebackq delims=" %%i in (`dir /B %1`) do (
	if exist "%_TEMPDIR%\%%i" (
		set _ROMNAME="%_TEMPDIR%\%%i"
		if [%ARCHIVE_TYPE%]==[zip] (
			%_7z% l "%_TEMPDIR%\%%i") || (
					echo *****Problem with zip in cache - retrying*****
					goto MOVEIT
			)
		goto CHECK_ARCHIVE_TYPE
		)
	)
)
:: If its a symlink we'll assume the file is on slow storage somewhere far away, so we'll move the compressed file locally first to unzip it
:: http://stackoverflow.com/questions/18883892/batch-file-windows-cmd-exe-test-if-a-directory-is-a-link-symlink
:: todo: its claimed in that link that this might not work on non-english language windows!?!
:MOVEIT
dir %1 | find "<SYMLINK>" && (
rem Copy zip to scratch dir. 
	for /f "usebackq delims=" %%i in (`dir /B %1`) do (
	rem must check for existing file else we'll robocopy the whole dir
		if exist %1 (
			rem todo - more care needed here - main danger is zipping up the whole of the cachedir or romdir
			rem convert drive and path to shortname to standardise things as robocopy blows up on quoted shortnames
			robocopy %ROMPATH% "%_TEMPDIR%" %FILENAME% /Z /J /COPY:D /DCOPY:D /ETA /R:3 /W:2
		)
	set _ROMNAME="%_TEMPDIR%\%%i"
    )
  goto CHECK_ARCHIVE_TYPE
)


:: daemon can mount zips, but it can't then mount the bin/cue/iso in that zip, so we have to pass it to emu in that case
:CHECK_ARCHIVE_TYPE
if /I (%ARCHIVE_TYPE%)==(proprietary) goto LOAD
if /I (%ZIP_MOUNTABLE%)==(yes) (
	if [%NOMOUNT%]==[1] goto ZIPMOUNT
)
if /I (%ARCHIVE_TYPE%)==(zip) goto UNZIP

:: Mount the image or the zip
:LOAD
call :CHECK_EXCEPTIONS
if (%NOMOUNT%)==(1) (%EMU% %OPTIONS% %_ROMNAME% & goto unmount)
:: Mount daemon tools, load emu and passes full rom path to it
call :CHECK_DT
%_DT% -mount_to %_DAEMON_DRIVE%, %_ROMNAME%
%EMU% %OPTIONS%
:UNMOUNT
%_DT% -unmount %_DAEMON_DRIVE%
goto finish

:: mount zips
:ZIPMOUNT
call :CHECK_DT
%_DT% -mount_to %_DAEMON_DRIVE%, %_ROMNAME%
set _ZIPMOUNTING=YES
::we need a string with brackets, so don't enclose the assignment in brackets
if NOT [%OVERRIDE%]==[] set typeListWithWildcards=(*.%OVERRIDE%)
for /R %_DAEMON_DRIVE%:\ %%Y IN %typeListWithWildcards% DO set _ROMNAME="%%~sY"

goto LOAD

:UNZIP
:: y causes us to confirm any prompt, aos causes us to not overwrite existing files, which will cause a problem if a corrupted bin got made from a failed extract previously
%_7Z% e %_ROMNAME% -o"%_TEMPDIR%" -y -aos
goto MOUNT

::we have to know where the runnable disc image is 
:MOUNT
:: we make (once) a list of files in the archive. 7z list command doesn't like short names (a bug with 7z)
:: We need to use the same for-loop-backtick form to capture a variable as used above with robocopy
%_7Z% l %_ROMNAME% > %_TEMPDIR%\archive.txt

:: Probe for favourite mountable filetype (reverse order of the list makes sure eg: cue is mounted in preference to bin or iso
:: after, we get the line from find that corresponds to the found cueing file (skip=2 won't evaluate the first output line of find)
if NOT [%OVERRIDE%]==[] set typeList=(.%OVERRIDE%)
for %%Y in %typeList% do (
	for /F "usebackq skip=2 delims=" %%v in (`FIND \i  %_TEMPDIR%\archive.txt "%%Y"`) do set ROMFOUND=%%v
)

:: Pick out the filename from that line of 7zip output - note that sometimes the date and time
:: are filled in, sometimes not, and the name is unquoted. 
:GETNAME
::I decided in the end to try to do a standard for loop in batch: iterating to the right
::  searching for a substring match to a file name in the extraction directory (which serves the
::  dual purpose of making sure the file has actually been extracted)
::To get the string length for the loop is in itself not trivial 
:: http://stackoverflow.com/questions/30143520/how-to-reverse-strings-in-a-batch-file
:: http://stackoverflow.com/questions/10672885/how-to-count-the-characters-in-a-string-with-batch

set STR="%ROMFOUND%"
echo %STR%> %_TEMPDIR%\archive.txt
for %%? IN (%_TEMPDIR%\archive.txt) do ( set /A strlength=%%~z? - 2 )
SETLOCAL ENABLEDELAYEDEXPANSION
set /a result=!strlength!
echo %result%

for /L %%i in (0,1,!RESULT!) do (
 set num=%%i
	set NEW_STR=!STR:~%%i!
	echo !NEW_STR!
	if [!NEW_STR!]==[] ( echo string is empty now) else (
	rem we need to put quotes around our variable (eg: &) so we need to look for romname without the last "
	echo looking for "%_TEMPDIR%\!NEW_STR:~0, -1!"
		if exist "%_TEMPDIR%\!NEW_STR:~0, -1!" (
		echo FOUND ROM
		set _ROMNAME="%_TEMPDIR%\!NEW_STR:~0, -1!"
		SETLOCAL DISABLEDELAYEDEXPANSION
		del %_TEMPDIR%\archive.txt
		goto LOAD
		exit /b
		rem batch needs to loop all iterations, you'll have to wait...
		)
	)
)
echo ***** EXITING - DIDN'T FIND THE ROM *****
goto FINISH

:ERROR_POPUP
:: http://stackoverflow.com/questions/774175/how-can-i-open-a-message-box-in-a-windows-batch-file
echo X=MSGBOX (%ERROR_MESSAGE%,0+48,"QuickPlay Multiloader Error") > %temp%\TEMPmessage.vbs
call %temp%\TEMPmessage.vbs
del %temp%\TEMPmessage.vbs /f /q
:: echo X=MsgBox("Message Description",0+16,"Title") >msg.vbs
:: –you can write any numbers from 0,1,2,3,4 instead of 0 (before the ‘+’ symbol) & here is the meaning of each number:
:: 0 = Ok Button, 1 = Ok/Cancel Button, 2 = Abort/Retry/Ignore button, 3 = Yes/No/Cancel, 4 = Yes/No  
:: –you can write any numbers from 16,32,48,64 instead of 16 (after the ‘+’ symbol) & here is the meaning of each number:
:: 16 – Critical Icon, 32 – Warning Icon, 48 – Warning Message Icon, 64 – Information Icon  
exit /b

:FINISH
:: if you have specified a tempdir and you do want to police it, wipe it recursively
if [%_CLEANTEMP%]==[YES] (
	if not ["%_TEMPDIR%"]==[""] (
		if exist "%_TEMPDIR%" (
			rd /s /q "%_TEMPDIR%"
		)
	) 
)	
for %%Z in (EMU OPTIONS _TEMPDIR _CLEANTEMP _INIFILE _ROMNAME _DT _7Z _WM _CUE _ZIPMOUNTING ERRORMESSAGE NOMOUNT) do set %%Z=
exit /b


::UTILITY FUNCTIONS

:CHECK_7Z
if exist "C:\Program Files (x86)\7-Zip\7z.exe" set _7Z="C:\Program Files (x86)\7-Zip\7z.exe"
if exist "C:\Program Files\7-Zip\7z.exe" set _7Z="C:\Program Files\7-Zip\7z.exe"
if (%_7Z%)==() set ERROR_MESSAGE="Please ensure the 7Zip executable ""7z.exe"" is installed to its default location in Windows' Program Files Folder" && goto ERROR_POPUP
exit /b

:CHECK_DT
if exist "C:\Program Files (x86)\DAEMON Tools Lite\DTAgent.exe" set _DT="C:\Program Files (x86)\DAEMON Tools Lite\DTAgent.exe"
if exist "C:\Program Files\DAEMON Tools Lite\DTAgent.exe" set _DT="C:\Program Files\DAEMON Tools Lite\DTAgent.exe"
if (%_DT%)==() set ERROR_MESSAGE="Please ensure the Daemon Tools command line executer ""DTAgent.exe"" is installed to its default location in Windows' Program Files Folder" && goto ERROR_POPUP
exit /b

:CHECK_EXCEPTIONS
for /f "tokens=* delims==" %%N in ('echo %EMU% ^| findstr nullDC') do (set NULLDC=YES)
if (%NOMOUNT%)==(1) ( 
	if [%NULLDC%]==[YES] ( 
		%EMU% -config nullDC_GUI:Fullscreen=1 -config ImageReader:LoadDefaultImage=1 -config ImageReader:DefaultImage=%_ROMNAME% & goto unmount
	)
)
exit /b


:: Callers might use shortname for rom, However 7zip+robocopy hate quoted 8:3 names, but everything else hates
::   you to pass unquoted *:3 names around (they might well contain !,^,&)
::   the only bure batch solution in the world lies here: http://stackoverflow.com/a/34473971/3536094
:SHORT_TO_LONG_NAME
:: Validate path
set "test=%~1"
if "%test:**=%" neq "%test%" goto err
if "%test:?=%"  neq "%test%" goto err
if not exist "%test%"  goto err

:: Initialize
set "returnPath="
set "sourcePath=%~f1"

:: Resolve file name, if present
if not exist "%~1\*" (
  for /f "eol=: delims=" %%F in ('dir /b "%~1"') do set "returnPath=%%~nxF"
  set "sourcePath=%~f1\.."
)

:resolvePath :: one folder at a time
for %%F in ("%sourcePath%") do (
  if "%%~nxF" equ "" (
    for %%P in ("%%~fF%returnPath%") do set "%~2=%%~P"
    exit /b 0
  )
  for %%P in ("%sourcePath%\..") do (
    for /f "delims=> tokens=2" %%A in (
      'dir /ad /x "%%~fP"^|findstr /c:">          %%~nxF "'
    ) do for /f "tokens=1*" %%B in ("%%A") do set "returnPath=%%C\%returnPath%"
  ) || set "returnPath=%%~nxF\%returnPath%"
  set "sourcePath=%%~dpF."
)
goto resolvePath

:err
>&2 echo Path not found
exit /b 1

::the dot is so robocopy wont blow up due to trailing slash
:SPLITNAMEANDPATH 
set rompath="%~dp1."
set filename="%~nx1"
exit /b


