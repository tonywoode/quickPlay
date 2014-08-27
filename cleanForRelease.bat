@echo off
echo.Really Delete all these QuickPlay directories?
choice
IF NOT ERRORLEVEL 2 IF ERRORLEVEL 1 goto CARRYON
exit

:CARRYON
echo.OK let's delete this data && pause
echo.Cleaning Up QP Directory for Release
cd qp
rd /S /Q data
rd /S /Q dats
rd /S /Q search
rd /S /Q temp

echo.Cleaning up possible ini files (you may have run up some of the tools)
del "tools\Romdata Magician\RomData Magician.ini"

echo.Cleaning up possible EFind files
del "EFind\Custom.ini"
del "EFind\Gamebase.ini"

pause