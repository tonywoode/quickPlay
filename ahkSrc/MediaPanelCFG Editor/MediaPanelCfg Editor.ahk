#SingleInstance Force
SetWorkingDir, %A_ScriptDir%
SetTitleMatchMode, 1
OnExit, Exit
ScriptName = Media Panel Cfg Editor
ScriptIni = MP Cfg Editor.ini

Gui, 1:Default
Gui, Destroy
Gui, +AlwaysOnTop
Menu, FileMenu, Add, &Open%A_Tab%Ctrl+O, OpenFile
Menu, FileMenu, Add, &Save%A_Tab%Ctrl+S, SaveFile
;Menu, FileMenu, Add, &Save As%A_Tab%F12, SaveAs
Menu, MenuBar, Add, &File, :FileMenu
Menu, FileMenu, Disable, &Save%A_Tab%Ctrl+S
;Menu, FileMenu, Disable, &Save As%A_Tab%F12
Gui, Menu, MenuBar

Gui, Add, Text, x20 y20, Hex:
Gui, Add, Edit, x20 xp+5 w759 h234 ReadOnly veHex gConvertFromHex
Gui, Add, Text, x20 y+20, Text:
Gui, Add, Edit, x20 xp+5 w759 h234 veText gConvertFromText

Gui, 2:Default
Gui, -Caption +Owner1
Gui, Add, Text,,Select a system
Gui, Add, ListBox, w200 h500 vSystem gGetSelection

Gui, 1:Default
GuiControl, Focus, eText
Gui, Show
Return

ConvertFromHex:
 GuiControlGet, Hex, 1:, eHex
 SetFormat, Integer, d
 Text =
 Loop, Parse, Hex
 {
  Index := A_Index * 2 - 1
  Char := "0x" SubStr(Hex,Index,2) 
  If StrLen(Char) < 4 
     Break
  Char +=0
  Text .= Chr(Char)
 }
 SetFormat, Integer, hex
 GuiControl, 1:, eText, %Text%
Return

ConvertFromText:
 GuiControlGet, Text, 1:, eText
 SetFormat, Integer, hex
 Hex =
 Loop, Parse, Text
 {
  Char := Asc(A_LoopField)
  Char += 0
  TempVar := SubStr(Char,3,2)
  TempVar := StrLen(TempVar) = 1 ? "0" TempVar : TempVar
  If TempVar in 0A,0D
     TempVar := "0A0D"
  Hex.= TempVar
 }
 SetFormat, Integer, d
 StringUpper, Hex, Hex
 GuiControl, 1:, eHex, %Hex%
Return

OpenFile:
 Save= 0
 Gui +OwnDialogs
 FileSelectFile, CurrentFile,,, Open 'QP\dats\MediaPanelCfg.ini' or any text file, *.ini;*.txt
 If CurrentFile =
 {
  MsgBox, Press {Ctrl}Q to exit.
  Goto, OpenFile
 }
 Menu, FileMenu, Enable, &Save%A_Tab%Ctrl+S
; Menu, FileMenu, Enable, &Save As%A_Tab%F12
 FileRead, FileContents, %CurrentFile%
 SplitPath, CurrentFile,,,CurrentExt
 If CurrentExt = ini
    GetSystem()
 Else
 {
  GuiControl, 1:, eText, %FileContents%
  Gosub, ConvertFromText
  Gui, 1:Show,, %CurrentFile%
 }
Return

SaveFile:
 Save = 1
 If CurrentExt <> ini
 {
  Gui +OwnDialogs
  FileSelectFile, CurrentFile,,, Browse to your QP\dats\MediaPanelCfg.ini, *.ini
  If CurrentFile =
  {
   MsgBox, Press {Ctrl}Q to exit.
   Goto, SaveFile
  }
  FileRead, FileContents, %CurrentFile%
  System := GetSystem()
 }

 Gui, +OwnDialogs
 GuiControlGet, Hex, 1:, eHex
 Hex .= (SubStr(Hex,-3) = "0D0A") ? "" : "0D0A"  ;Do this when saving.
 IniWrite, %Hex%, %CurrentFile%, %System%-CFG, AddInfo
 MsgBox, Saved %System%-CFG in %CurrentFile%
Return

GetSystem()
{
 Global
 List =
 Loop, Parse, FileContents, `r, `n
 {
  IfInString, A_LoopField, -CFG]
  {
   Pos := RegExMatch( A_LoopField, "\[(.+?)-CFG]", Match)
   IniRead, TempVar, %CurrentFile%, %Match1%-CFG, AddInfo, Error
   If (TempVar <> "Error") OR (Save = 1)
      List .= List = "" ? "|" : Match1 "|"
  }
 }
 Sort, List, D| U
 If (List = "") And (Save = 0)
    MsgBox, There are currently no systems with a description.
 Else
 {
  Gui, 1: +Disabled
  Gui, 2:Default
  GuiControl, 2:, System, %List%
  Gui, 2:Show
 }
}

GetSelection:
 GuiControlGet, System
 Gui, 2:Hide
 Gui, 1:Default
 Gui, 1:-Disabled
 If Save = 0
 {
  IniRead, Hex, %CurrentFile%, %System%-CFG, AddInfo, Error
  Hex := Hex = "Error" ? "" : Hex
  GuiControl, 1:, eHex, %Hex%
  Gosub, ConvertFromHex
  Title := CurrentFile "\" System "-CFG"
 }
 Else
 Gui, 1:Show,, %Title%
Return

#IfWinActive ahk_class AutoHotkeyGUI, Hex:

 ^O::Gosub, OpenFile
 
 ^S::Gosub, SaveFile
 
; F12::Gosub, SaveAs

#IfWinActive

^Q:: ExitApp
Exit:
ExitApp