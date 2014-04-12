@echo off
echo.Cleaning Up Package Directory for Release
cd package
rd /S /Q data
rd /S /Q dats
rd /S /Q search
rd /S /Q temp
pause