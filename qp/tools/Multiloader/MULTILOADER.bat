:: This script calls the uncompiled multiloader code in the same folder. Its uses Bat2Exe by Faith Kodak
:: Hence the custom variable
SETLOCAL

if (%b2eprogrampathname%)==() (set _SCRIPTDIR="%~dp0") else (set _SCRIPTDIR=%b2eprogrampathname%)
pushd %_SCRIPTDIR%
%_SCRIPTDIR%MULTILOADER_imp.bat %*
popd