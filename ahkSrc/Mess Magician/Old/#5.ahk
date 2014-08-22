#SingleInstance, force
SetWorkingDir, %A_ScriptDir%
#NoEnv
OnExit, ExitLabel
ScriptName := "#5"
ScriptIni := "#5.ini"
IfNotExist, %ScriptIni%
{
 FileAppend, 
 (
 [General]
 RomDataPath=
 EmuIniPath=
 ), %ScriptIni%
}
IniRead, RomDataPath, %ScriptIni%, General, RomDataPath,
IniRead, EmuIniPath, %ScriptIni%, General, EmuIniPath,
Gui, +OwnDialogs
Gui, Add, Text, x10 y34 w70, Romdata File
Gui, Add, Edit, ReadOnly x90 y30 w360 r1 vRomDataPath, %RomDataPath%
Gui, Add, Button, x470 y29 w30 gGetRomDataPath, ...
Gui, Add, Text, x10 y84 w130, Emulators.ini file
Gui, Add, Edit, ReadOnly x90 y80 w360 r1 vEmuIniPath, %EmuIniPath%
Gui, Add, Button, x470 y79 w30 gGetEmuIniPath, ...
Gui, Add, Button, x400 y+15 w100 h30 Default gButtonGo, GO!
Gui, Add, Progress, x10 y+15 w490 h20 cGray BackgroundSilver vMyProgress
Gui, Show, AutoSize, %ScriptName% by Matt Mclemore AKA 'Tempest'
Return

^Q::
GuiClose:
ExitLabel:
 WriteIni()
ExitApp

 
GetRomDataPath:
 Gui +OwnDialogs
 FileSelectFile, RomDataPath,, %RomDataDir%, Select Romdata.dat file, ROMData.dat
 If RomDataPath <>
    GuiControl,, RomDataPath, %RomDataPath%
Return

GetEmuIniPath:
 Gui +OwnDialogs
 FileSelectFile, EmuIniPath,, %EmuIniDir%, Select emulators.ini file, emulators.ini
 If EmuIniPath <>
    GuiControl,, EmuIniPath, %EmuIniPath%
Return

;   1     2         3        4      5      6       7       8      9       10      11         12       13      14         15      16   17   18   19    20     21           22          23
; Name|Rom Name|ParentName|ZipName|path|Emulator|Company|Year|Game Type|Rating|Language|Parameters|Comment|NumPlayed|ParamMode|<IPS>|IPS1|IPS2|IPS3|</IPS>|Players|DefaultGoodMerge|System
  
ButtonGo:
Gui, Submit, NoHide
Gui, +OwnDialogs
SplitPath, RomDataPath,, RomDataDir
SplitPath, RomDataPath,, EmuIniDir
FileRead, EmuIni, %EmuIniPath%
FileRead, Romdata, %RomDataPath%
StringReplace, RomData, RomData, `n, `n, UseErrorLevel
GuiControl, +Range0-%ErrorLevel%, MyProgress
NewRomData =
Loop, Parse, RomData, `r, `n
{
 LoopField := A_LoopField
 IfInString, LoopField, ¬
 {
  GuiControl,, MyProgress, +1
  StringSplit, TempVar, LoopField, ¬
  IniRead, TempVar, %EmuIniPath%, %TempVar6%, parameters, Error
  If TempVar <> Error
  {
   StringReplace, TempVar12, TempVar, `%ROM`%, `%ROMNAME`%
   TempVar15 = 1
  }
  LoopField =
  Loop, %TempVar0%
    LoopField .= Tempvar%A_Index% "¬"
 }
 NewRomData .= LoopField "`n"
}
StringTrimRight, NewRomData, NewRomData, 1
GuiControl,, MyProgress, 0
FileMove, %RomDataDir%\Romdata.dat, %RomDataDir%\%A_Now%_Romdata.dat
Loop
{
 IfNotexist, %RomDataDir%\Romdata.dat
 Break
 Sleep, 100
}
FileAppend, %NewRomData%, %RomDataDir%\Romdata.dat
MsgBox, File has been saved
Return

;***************************************************************************************************

WriteIni()
{
 Global
 Gui, SubMit, NoHide
 IniWrite, %RomDataPath%, %ScriptIni%, General, RomDataPath
 IniWrite, %EmuIniPath%, %ScriptIni%, General, EmuIniPath
}
