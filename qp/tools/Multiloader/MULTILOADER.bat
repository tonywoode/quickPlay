:: This script calls the uncompiled multiloader code in the same folder. Its uses Bat2Exe by Faith Kodak
::   hence the custom variables. Its purpose in life is to be compliled to multiloader.exe, so that quickplay
::   can find an exe instead of a bat, but to ensure that we still have a bat for users to amend themselves

:: b2e converter, since v2.4.5 passed the executable name of itself as %1 by default, you can't SHIFT it,
:: so the new variable %b2eargs% performs the behaviour that %* used to
:: The advantage of later versions of b2e is that they better pass variables that include ampersands
SETLOCAL

if (%b2eprogrampathname%)==() (set _SCRIPTDIR="%~dp0") else (set _SCRIPTDIR=%b2eprogrampathname%)
pushd %_SCRIPTDIR%
%_SCRIPTDIR%MULTILOADER_imp.bat %b2eargs%
popd
