@echo off & SETLOCAL
:: CD/DVD MULTILOADER SCRIPT v1.2 - butter100fly 2012
:: Pass an image to me, I work out if its compressed or not, if it is I work out which prog to extract it with and mount in Daemon Tools
:: if its not I just mount it, Launches emu with params, clears up after
:: For V1.2 I added command line parameters you can call when calling the script. 
:: It will prioritise anything after "%ROM%" in the command line over what's in the ini, or you don't have to have the ini
:: You must call them in this order: 
:: First "PATH TO ROM"  
:: Secondly "EMULATOR EXECUTABLE" 
:: Thirdly "OPTIONS TO PASS TO EMULATOR (eg.:-CD)"
:: Fourthly "Direct Mount" - PASS IMAGE TO EMULATOR INSTEAD OF TO DEAMON TOOLS - 1 is yes, anything else is no
:: Please encase all 4 in "quotation marks" and include empty emulator options ie: "" if you need to set direct mount after
::
:: So in QuickPLay you would call, for example: "%ROM%" "C:\Emulators\Mednafen\Mednafen.exe"
:: (we don't need direct mount and there are no options)
:: Or "%ROM%" "C:\Emulators\Magic Engine\pce.exe" "" "1"
:: (we need the "" because we need direct mounting after)
:: Actually we can improve that one to pass -cd to Magic Engine:
:: "%ROM%" "C:\Emulators\Magic Engine\pce.exe" "-cd" "1"
::-------------------------------------------------------------------------------





 :: Get script dir as we may need to run forciblyunmount.exe from it later
for /f "delims=" %%G in ('CD') do (set _SCRIPTDIR=%%G\)
::-------------------------------------------------------------------------------
:: Get Emu and Options from ini file*******PLEASE SET YOUR EMU AND OPTIONS IN MULTILOADER.INI******
::-------------------------------------------------------------------------------
IF NOT EXIST multiloader.ini goto CMD_LINE_EMU
for /f "tokens=2* delims==" %%H in ('find "EMU=" ^< multiloader.ini') do (set EMU=%%H)
::IF there's no EMU set in the ini, also ignore options and nomount setting
IF (%EMU%)==() goto CMD_LINE_EMU
for /f "tokens=2* delims==" %%I in ('find "OPTIONS=" ^< multiloader.ini') do (set OPTIONS=%%I)
for /f "tokens=2* delims==" %%J in ('find "NOMOUNT=" ^< multiloader.ini') do (set NOMOUNT=%%J)


:CMD_LINE_EMU
if exist %2 set EMU=%2 & set OPTIONS=%~3 & set NOMOUNT=%~4



::If there isn't an emu, we have an error that will hang the script, bomb out instead
IF EXIST %EMU% GOTO CARRYON
IF EXIST ".\QUICKPLAY MULTILOADER README.txt" (notepad.exe ".\QUICKPLAY MULTILOADER README.txt" & EXIT)
EXIT

:CARRYON
::set a temp directory for rom in rom dir, Using shortname (in case we need it for unzip) then CD to EMU directory
for /D %%X IN (%1) DO SET _TEMPDIR="%%~dpnsX\"
cd /d %EMU%\..

set _ROMNAME=%1

if (%~x1)==(.zip) goto UNZIP
if (%~x1)==(.rar) goto UNZIP
if (%~x1)==(.ace) goto UNZIP
if (%~x1)==(.7z) goto UNZIP
if (%~x1)==(.mou) goto WINMOUNT


:LOAD
:: if we want to pass direct to emu we look for 1 in the ini, just pass romname to emu, and goto exit after
if (%NOMOUNT%)==(1) %EMU% %OPTIONS% %_ROMNAME% & goto WINUNMOUNT
:: mount daemon tools, load emu and passes full rom path to it
:: After emu exits, unmounts daemon and deletes temp files, temp folder, and temp variables

if exist "C:\Program Files\DAEMON Tools Lite\DTLite.exe" set _DT="C:\Program Files\DAEMON Tools Lite\DTLite.exe"
if exist "C:\Program Files (x86)\DAEMON Tools Lite\DTLite.exe" set _DT="C:\Program Files (x86)\DAEMON Tools Lite\DTLite.exe"
if (%_DT%)==() echo. You don't seem to have Deamon Tools installed, this isn't going to work
%_DT% -mount SCSI, 0, %_ROMNAME%
%EMU% %OPTIONS%
%_DT% -unmount SCSI, 0
:WINUNMOUNT
if (%_WINMOUNTING%)==() goto FINISH
"C:\Program Files\WinMount\winmount" -unmountall
if exist "%_SCRIPTDIR%ForciblyWinmount.exe" start "" "%_SCRIPTDIR%ForciblyWinmount.exe"
goto FINISH

:WINMOUNT
::Pass arguements to winmount
::If winmount wasn't already running, it was hanging the script. So start it and don't wait as the loop does the waiting for it
::set flags first to tell script later that we are doing winmount
set _WINMOUNTING=YES
set _TEMPDIR="x:\"
if exist "C:\Program Files\WinMount\winmount.exe" set _WM="C:\Program Files\WinMount\winmount.exe"
if exist "C:\Program Files (x86)\WinMount\winmount.exe" set _WM="C:\Program Files (x86)\Winmount\Winmount.exe"
if (%_WM%)==() echo. You don't seem to have Winmount installed, this isn't going to work
start "" %_WM% -m %1 -drv:x:\
:watch
IF EXIST x:\*.* goto mount
goto watch


:UNZIP
:: 7zip uncompresses image files and names its folder in rom dir after archive file 
"C:\Program Files\7-Zip\7z.exe" e %1 -o%_TEMPDIR%
goto MOUNT


:MOUNT
:: then we probe for which type of file we have and go to the appropriate section
:: The reverse order of the list makes sure eg: cue is mounted in preference to bin or iso
:: search is recursive, so image can be in subfolder
FOR /R %_TEMPDIR% %%Y IN (*.pdi *.isz *.bwt *.b6t *.b5t *.nrg *.iso *.img *.cdi *.mdx *.mds *.ccd *.bin *.cue *.gcm *.gdi) DO set _ROMNAME="%%Y"
goto LOAD


:FINISH
if exist %_TEMPDIR% rd /s /q %_TEMPDIR%
FOR %%Z IN (EMU OPTIONS _TEMPDIR _ROMNAME _DT _WM _WINMOUNTING NOMOUNT) DO SET %%Z=
exit
