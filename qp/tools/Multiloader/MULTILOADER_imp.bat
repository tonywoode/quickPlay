ECHO OFF & SETLOCAL
:: CD/DVD MULTILOADER SCRIPT v1.4 - butter100fly 2015
:: Pass an image to me, I work out if its compressed or not, if it is I work out which prog to extract it with 
:: and mount in Daemon Tools, if its not I just mount it, Launch emu with params, and clear up after
:: For V1.3 I made it so you could say where to extract zips in the ini
:: For V1.4 I made it compatible with Daemon Tools 5, and also zips can now open directly in daemon tools

:: There are command line parameters you can call when calling the script. You must call them in this order: 
:: First "PATH TO ROM"  
:: Secondly "EMULATOR EXECUTABLE" 
:: Thirdly "OPTIONS TO PASS TO EMULATOR (eg.:-CD)"
:: Fourthly "Direct Mount" - PASS IMAGE TO EMULATOR INSTEAD OF TO DEAMON TOOLS - 1 is yes, anything else is no
:: Please encase all 4 in "quotation marks" and include empty emulator options ie: "" if you need to set direct mount after
::
:: So in QuickPLay you would call, for example: 
::		"%ROM%" "P:\Mednafen\Mednafen.exe"
:: (we don't need direct mount and there are no options)
:: Or 
::		"%ROM%" "P:\Magic Engine\pce.exe" "" "1"
:: (we need the "" because we need direct mounting after)
:: Actually we can improve that one to pass -cd to Magic Engine:
:: 		"%ROM%" "P:\Magic Engine\pce.exe" "-cd" "1"
::-------------------------------------------------------------------------------

:: Get script dir (may need to run forciblyunmount.exe from it later). B2E converter by Faith Kodak is great, but will lose $0. the 'CD' trick doesn't work in his compiled exes either
:: So, in order to get the script dir, we EITHER use a little trick from faith, or if that variable doesn't exist, we assume you're running from the bat and that $0 is the actual script dir
if (%b2eprogrampathname%)==() (set _SCRIPTDIR="%~dp0") else (set _SCRIPTDIR=%b2eprogrampathname%)
IF EXIST %_SCRIPTDIR%Multiloader.ini (set _INIFILE=%_SCRIPTDIR%Multiloader.ini)

:: You must set these in the ini file: where to extract to, which drive letter for daemon tools ,and which for daemon's zip support
for /f "tokens=2* delims==" %%H in ('find "TEMPDIR=" ^< %_INIFILE%') do (set TEMPDIR=%%H)
if (%TEMPDIR%)==() (for /D %%I IN (%1) DO SET _TEMPDIR=%%~dpnsN\) else (for /D %%I IN (%1) DO SET _TEMPDIR=%TEMPDIR%)
for /f "tokens=2* delims==" %%J in ('find "DAEMON_DRIVE=" ^< %_INIFILE%') do (set DAEMON_DRIVE=%%J)
if (%DAEMON_DRIVE%)==() (SET _DAEMON_DRIVE=K) else (SET _DAEMON_DRIVE=%DAEMON_DRIVE%)
for /f "tokens=2* delims==" %%N in ('find "CLEANTEMP=" ^< %_INIFILE%') do (set _CLEANTEMP=%%N)

::-------------------------------------------------------------------------------------
:: You can set Emu and Options from MULTILOADER.INI if you want to hard-code the loader
:: (Most users will just want to launch from QuickPlay so won't need this)
::-------------------------------------------------------------------------------------
IF NOT (%1)==() goto CMD_LINE_EMU
for /f "tokens=2* delims==" %%L in ('find "EMU=" ^< %_INIFILE%') do (set EMU=%%L)
:: IF there's no EMU set in the ini, also ignore options and nomount setting
IF (%EMU%)==() goto CMD_LINE_EMU
for /f "tokens=2* delims==" %%M in ('find "OPTIONS=" ^< %_INIFILE%') do (set OPTIONS=%%M)
for /f "tokens=2* delims==" %%N in ('find "NOMOUNT=" ^< %_INIFILE%') do (set NOMOUNT=%%N)

:CMD_LINE_EMU
if exist %2 set EMU=%2 & set OPTIONS=%~3 & set NOMOUNT=%~4

:CHECK_EMU
:: If there isn't an emu, we have an error that will hang the script, bomb out instead
IF EXIST %EMU% GOTO START_PROCESSING
IF EXIST ".\README.txt" (notepad.exe ".\README.txt" & EXIT)
EXIT

:START_PROCESSING
:: set a temp directory for rom, either in rom dir or in the dir the user set. use shortname (in case we need it for unzip) then CD to EMU directory
cd /d %EMU%\..
set _ROMNAME="%~s1"

::don't try moving files that we've already got cached
:: Batch can't set variables to output like nix, says set /p can read from a file here http://stackoverflow.com/a/19024533,
::  but that didn't work for me, instead we use the nix-style backtick of for /f

for /f "usebackq delims=" %%i in (`dir /B %1`) do (
	if EXIST "%_TEMPDIR%\%%i" (set SOURCEZIP=%_TEMPDIR%\%%i && GOTO CHECK_ARCHIVE_TYPE)
)


:MOVEIT
:: If its a symlink we'll assume the file is on slow storage somewhere far away, so we'll move the compressed file locally first to unzip it
:: http://stackoverflow.com/questions/18883892/batch-file-windows-cmd-exe-test-if-a-directory-is-a-link-symlink
:: todo: its claimed in that link that this might not work on non-english language windows!?!
dir %1 | find "<SYMLINK>" && (
  :: Copy zip to scratch dir. A problem we have is we often pass in 8:3 names just to shorten filename, as some game names
  ::  are notoriously long, so we need to use dir /B in order to get the long name - http://stackoverflow.com/a/34473971 for both
  ::  robocopy and the list function of 7zip

  for /f "usebackq delims=" %%i in (`dir /B %1`) do (
	:: must check for existing file else we'll robocopy the whole dir
	if exist %1 (
		robocopy %~dp1 "%_TEMPDIR%" "%%i" /Z /J /COPY:D /DCOPY:D /ETA /R:3 /W:2
	)
  )
  set SOURCEZIP=%_TEMPDIR%\%~nx1
  goto CHECK_ARCHIVE_TYPE
)
set SOURCEZIP=%1

:CHECK_ARCHIVE_TYPE
if /I (%~x1)==(.zip) goto UNZIP
if /I (%~x1)==(.rar) goto UNZIP
if /I (%~x1)==(.ace) goto UNZIP
if /I (%~x1)==(.7z) goto UNZIP
:: if you have winmount we can run the compressed image
if /I (%~x1)==(.mou) goto WINMOUNT


:LOAD
:: if we want to pass direct to emu we look for 1 in the ini, just pass romname to emu, and goto exit after
if (%NOMOUNT%)==(1) %EMU% %OPTIONS% %_ROMNAME% & goto WINUNMOUNT
:: Mount daemon tools, load emu and passes full rom path to it. After emu exits, unmounts daemon and deletes temp files, temp folder, and temp variables
if exist "C:\Program Files\DAEMON Tools Lite\DTAgent.exe" set _DT="C:\Program Files\DAEMON Tools Lite\DTAgent.exe"
if exist "C:\Program Files (x86)\DAEMON Tools Lite\DTAgent.exe" set _DT="C:\Program Files (x86)\DAEMON Tools Lite\DTAgent.exe"
if (%_DT%)==() set ERROR_MESSAGE="Please ensure the Daemon Tools command line executer ""DTAgent.exe"" is installed to its default location in Windows' Program Files Folder" && goto ERROR_POPUP
%_DT% -mount SCSI, %_DAEMON_DRIVE%, %_ROMNAME%
%EMU% %OPTIONS%
%_DT% -unmount %_DAEMON_DRIVE%

:WINUNMOUNT
if (%_WINMOUNTING%)==() goto FINISH
%_WM% -unmountall
if exist "%_SCRIPTDIR%ForciblyWinmount.exe" start "" "%_SCRIPTDIR%ForciblyWinmount.exe"
goto FINISH

:WINMOUNT
:: Pass arguments to winmount. If winmount wasn't already running, it was hanging the script. So start it and don't wait as the loop does the waiting for it
:: set flags first to tell script later that we are doing winmount, note the user must have drive X free
if exist x:\nul set ERROR_MESSAGE="Winmount needs to use drive X, but a drive X is already mounted. Try to unmount it. Sorry!" && goto ERROR_POPUP
set _WINMOUNTING=YES
set _TEMPDIR=x:\
if exist "C:\Program Files\WinMount\winmount.exe" set _WM="C:\Program Files\WinMount\winmount.exe"
if exist "C:\Program Files (x86)\WinMount\winmount.exe" set _WM="C:\Program Files (x86)\Winmount\Winmount.exe"
if (%_WM%)==() set ERROR_MESSAGE="Please ensure the Winmount executable ""winmount.exe"" is installed to its default location in Windows' Program Files Folder" && goto ERROR_POPUP
start "" %_WM% -m "%SOURCEZIP%" -drv:x:\

:WATCH
IF EXIST x:\*.* goto carryon
goto watch

:CARRYON
FOR /R %_TEMPDIR% %%Y IN (*.pdi *.isz *.bwt *.b6t *.b5t *.nrg *.iso *.img *.cdi *.mdx *.mds *.ccd *.bin *.cue *.gcm *.gdi) DO set _ROMNAME="%%~sY"
goto LOAD

:UNZIP
if exist "C:\Program Files\7-Zip\7z.exe" set _7Z="C:\Program Files\7-Zip\7z.exe"
if exist "C:\Program Files (x86)\7-Zip\7z.exe" set _7Z="C:\Program Files (x86)\7-Zip\7z.exe"
if (%_7Z%)==() set ERROR_MESSAGE="Please ensure the 7Zip executable ""7z.exe"" is installed to its default location in Windows' Program Files Folder" && goto ERROR_POPUP
:: y causes us to confirm any prompt, aos causes us to not overwrite existing files, which will cause a problem if a corrupted bin got made from a failed extract previously
%_7Z% e "%SOURCEZIP%" -o"%_TEMPDIR%" -y -aos
goto MOUNT

:MOUNT
:: we make (once) a list of files in the archive. 7z list command doesn't like short names (a bug with 7z)
:: We need to use the same for-loop-backtick form to capture a variable as used above with robocopy
 for /f "usebackq delims=" %%i in (`dir /B %1`) do (
	%_7Z% l "%_TEMPDIR%/%%i" > %_TEMPDIR%\list.txt
 )

:: probe for favourite mountable filetype (reverse order of the list makes sure eg: cue is mounted in preference to bin or iso
:: after, we get the line from find that corresponds to the found cueing file (skip=2 won't evaluate the first output line of find)

FOR %%Y IN (.pdi .isz .bwt .b6t .b5t .nrg .iso .img .cdi .mdx .mds .ccd .bin .cue .gcm .gdi) DO (
	FOR /F "usebackq skip=2 delims=" %%v in (`FIND \i  %_TEMPDIR%\list.txt "%%Y"`) do set ROMFOUND=%%v
)
:: pick out the filename from that line of FIND
(FOR /F "tokens=6* eol=" %%t in ("%ROMFOUND%") do set _CUE=%%t %%u) || set ERROR_MESSAGE="Didn't pick up a file to mount" && goto ERROR_POPUP
del %_TEMPDIR%\list.txt
:: make valid uri
set _ROMNAME="%_TEMPDIR%\%_CUE%"

goto LOAD


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

:FINISH
:: if you have specified a tempdir and you do want to police it, wipe it recursively
if (%_CLEANTEMP%)==(YES) ( 
	if NOT (%TEMPDIR%)==() (
		 if exist "%_TEMPDIR%" rd /s /q "%_TEMPDIR%"
	)
)

FOR %%Z IN (EMU OPTIONS _TEMPDIR _CLEANTEMP _INIFILE _ROMNAME _DT _7Z _WM _CUE _WINMOUNTING ERRORMESSAGE NOMOUNT) DO SET %%Z=
exit
