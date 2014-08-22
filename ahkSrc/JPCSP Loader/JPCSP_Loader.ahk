#SingleInstance Force
SetWorkingDir, %A_ScriptDir%
#NoEnv
BatText =
(
@echo off
set PATH=`%PATH`%;lib\;lib\windows-x86\
if "`%programfiles(x86)`%XXX"=="XXX" goto JAVA32
if not exist "`%programfiles(x86)`%\Java\jre6\bin" goto JAVAMISSING
echo Running Jpcsp 32bit...
"`%programfiles(x86)`%\Java\jre6\bin\java" COMMAND ROMPATH -r
goto END
:JAVA32
if not exist "`%programfiles`%\Java\jre6\bin" goto JAVAMISSING
echo Running Jpcsp 32bit...
"`%programfiles`%\Java\jre6\bin\java" COMMAND ROMPATH -r
goto END
:JAVAMISSING
echo The required version of Java has not been installed or isn't recognized.
echo Go to http://java.sun.com to install the 32bit Java JRE.
pause
:END 
)
IfExist, jpcsp.bat
{
 FileDelete, jpcsp.bat
 Loop, 50
 {
  Sleep, 50
  IfNotExist, jpcsp.bat
  Break
 }
}
StringReplace, NewText, BatText, COMMAND, %1%, A
StringReplace, NewText, NewText, ROMPATH, %2%, A
FileAppend, %NewText%, jpcsp.bat
Sleep, 50
RunWait, jpcsp.bat
ExitApp
 
