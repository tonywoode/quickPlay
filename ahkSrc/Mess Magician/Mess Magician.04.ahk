#SingleInstance, force
SetWorkingDir, %A_ScriptDir%
#NoEnv
OnExit, ExitLabel
#Include C:\Program Files (x86)\AutoHotkey\Lib\Robert's INI library Basic.ahk
SelectedRomdataPath = RomData.dat
SelectedXmlPath = E:\AHK\My AHK\Emulator Ini Project\ButterFly's Attachments\Mess\hash\megadriv.xml
Space := "       "
ScriptName := "Mess Magician"
ScriptIni := "Mess Magician.ini"
IfNotExist, %ScriptIni%
{
 FileAppend, 
 (
 [General]
 RomDataPath=
 XMLPath=
 EmuIniPath=
 RemoveExtraInfo=0
 AddCloneInfo=1
 AddParentInfo=1
 AddYear=1
 AddPublisher=1
 ), %ScriptIni%
}
IniKeys := "RomDataPath,XMLPath,EmuIniPath,RemoveExtraInfo,AddCloneInfo,AddParentInfo,AddYear,AddPublisher"
Loop, Parse, IniKeys, `,
   IniRead, %A_LoopField%, %ScriptIni%, General, %A_LoopField%, 0
   
ErrorCodes = 1|INI format is wrong
,2|Sec not found
,3|Key not found
,4|Invalid optional paramater
,5|Sec already exists
,6|Key already exists
,9|Reference number is already set
,10|Reference number is invalid
,11|Unable to read ini file
,12|Unable to write ini file
,13|Unable to delete existing ini file
,14|Unable to rename temp ini file
,15|Ini already exists
Loop, Parse, ErrorCodes, `,
{
 Stringsplit, TempVar, A_LoopField, |
 Errorcode%TempVar1% := TempVar2
}

Gui, +OwnDialogs
Gui, Add, Text, x10 y34 w70, Romdata File
Gui, Add, Edit, ReadOnly x90 y30 w360 r1 vRomDataPath, %RomDataPath%
Gui, Add, Button, x470 y29 w30 gGetRomDataPath, ...
Gui, Add, Text, x10 y84 w130, %Space%XML File
Gui, Add, Edit, ReadOnly x90 y80 w360 r1 vXmlPath, %XmlPath%
Gui, Add, Button, x470 y79 w30 gGetXmlPath, ...
Gui, Add, Text, x10 y134 w130, Emulators.ini file
Gui, Add, Edit, ReadOnly x90 y130 w360 r1 vEmuIniPath, %EmuIniPath%
Gui, Add, Button, x470 y129 w30 gGetEmuIniPath, ...
;Gui, Add, CheckBox, x90 y130 checked%RemoveExtraInfo% vRemoveExtraInfo, Remove (???) Information From Description
Gui, Add, GroupBox, x10 y180 w280 h105, Add XML Info
Gui, Add, CheckBox, x20 y205 checked%AddCloneInfo% vAddCloneInfo, Add Clone Information
Gui, Add, CheckBox, x20 y+5 checked%AddParentInfo% vAddParentInfo, Add Parent Information
Gui, Add, CheckBox, x20 y+5 checked%AddYear% vAddYear, Add Year
Gui, Add, CheckBox, x20 y+5 checked%AddPublisher% vAddPublisher, Add Publisher Information
Gui, Add, Button, x175 yp-15 w100 h30 gAddXmlData, Add XML Info
Gui, Add, Button, x400 yp w100 h30 gFixParameters, Fix Parameters
Gui, Add, Progress, x10 y+20 w490 h20 cGray BackgroundSilver vMyProgress

;If RemoveExtraInfo = 0
;   GuiControl, Hide, RemoveExtraInfo
Gui, Show, AutoSize, %ScriptName% by Matt Mclemore AKA 'Tempest'
Return

;***************************************************************************************************

^Q::
GuiClose:
ExitLabel:
 WriteIni()
ExitApp
 
GetRomDataPath:
 Gui +OwnDialogs
 GuiControlGet, RomDataPath
 SplitPath, RomDataPath,, RomDataDir
 FileSelectFile, SelectedRomDataPath,, %RomDataDir%, Select Romdata.dat file, ROMData.dat
 If SelectedRomDataPath <>
    GuiControl,, RomDataPath, %SelectedRomDataPath%
Return

GetXmlPath:
 Gui +OwnDialogs
 GuiControlGet, XMLPath
 SplitPath, XMLPath,, XMLDir
 FileSelectFile, SelectedXmlPath,, %XmlDir%, Select .xml file, *.xml
 If SelectedXmlPath <>
    GuiControl,, XmlPath, %SelectedXmlPath%
Return

GetEmuIniPath:
 Gui +OwnDialogs
 GuiControlGet, EmuIniPath
 SplitPath, EmuIniPath,, EmuIniDir
 FileSelectFile, SelectedEmuIniPath,, %EmuIniDir%, Select emulators.ini file, emulators.ini
 If SelectedEmuIniPath <>
    GuiControl,, EmuIniPath, %SelectedEmuIniPath%
Return

;   1     2         3        4      5      6       7       8      9       10      11         12       13      14         15      16   17   18   19    20     21           22          23
; Name|Rom Name|ParentName|ZipName|path|Emulator|Company|Year|Game Type|Rating|Language|Parameters|Comment|NumPlayed|ParamMode|<IPS>|IPS1|IPS2|IPS3|</IPS>|Players|DefaultGoodMerge|System

AddXmlData:
Gui, Submit, NoHide
Gui, +OwnDialogs
SplitPath, RomDataPath,, RomDataDir
FileRead, Xml, %XmlPath%
FileRead, Romdata, %RomDataPath%
StringReplace, RomData, RomData, `n, `n, UseErrorLevel
GuiControl, +Range0-%ErrorLevel%, MyProgress
NewRomData =
Loop, Parse, RomData, `r, `n
{
 GuiControl,, MyProgress, +1
 LoopField := A_LoopField
 Pos := InStr( A_LoopField, "¬")
 Rom := SubStr( A_LoopField, 1, Pos-1)
 Pos := RegexMatch(XML, "<software name=""" Rom """", Title)
 If Pos > 0
 {
  StringSplit, TempVar, LoopField, ¬
  EndPos := InStr(XML, "</software>","False",Pos)

  Pos1 := RegexMatch(XML, "<description>(.+?)</description>", Title, Pos)
  If (Pos1 > 0) AND (Pos1 < EndPos)
  {
   TempVar1 := UnHtm(Title1)
   TempVar1 := UTF82Ansi(TempVar1)
   If RemoveExtraInfo = 1
   {
    StringSplit, TempVar1, TempVar1, (
    TempVar1 := TempVar11
   }
  }
  
  If AddCloneInfo = 1
     TempVar2 := Rom
  If AddParentInfo = 1
  {
   EndPos := InStr(XML, "</software>","False",Pos)
   Pos1 := RegexMatch(XML, "cloneof=""(.+?)""", Parent, Pos)
   If (Pos1 > 0) AND (Pos1 < EndPos)
      TempVar3 := Parent1
  }
  If AddYear = 1
  {
   Pos1:= RegexMatch(XML, "<year>(.+?)</year>", Year, Pos)
   If (Pos1 > 0) AND (Pos1 < EndPos)
      TempVar8 := Year1
  }
  If AddPublisher = 1
  {
   Pos1:= RegexMatch(XML, "<publisher>(.+?)</publisher>", Publisher, Pos)
   If (Pos1 > 0) AND (Pos1 < EndPos)
      TempVar := UnHtm(Publisher1)
   IfNotInString, TempVar, <
      TempVar7 := TempVar
  }
  Pos1 := RegexMatch(XML, "\R\R\t+(.+?)\R\t+<software name=""" Rom """", ExtraInfo)
  If ExtraInfo1 <> 
     TempVar13 := ExtraInfo1
  LoopField =
  Loop, %TempVar0%
    LoopField .= Tempvar%A_Index% "¬"
  StringTrimRight, LoopField, LoopField, 1
 }
  NewRomData .= LoopField "`n"
}
StringTrimRight, NewRomData, NewRomData, 1
GuiControl,, MyProgress, 0
FileMove, %RomDataDir%\Romdata.dat, %RomDataDir%\%A_Now%_Romdata.dat
Sleep, 500
FileAppend, %NewRomData%, %RomDataDir%\Romdata.dat
MsgBox, File has been saved
Return

;***************************************************************************************************

FixParameters:
Gui, Submit, NoHide
Gui, +OwnDialogs
SplitPath, RomDataPath,, RomDataDir
SplitPath, EmuIniPath,, EmuIniDir
;RIni_Read(RVar,File,Correct_Errors=1,Remove_Inline_Key_Comments=0,Remove_Lone_Line_Comments=0,Remove_Inline_Section_Comments=0,Treat_Duplicate_Sections=1,Treat_Duplicate_Keys=1,Read_Blank_Sections=1,Read_Blank_Keys=1,Trim_Spaces_From_Values=0)
Error := RIni_Read(1, EmuIniPath, 1,0,1,1,1,1,0,0,0)
If (Error <> "") AND (Error <> "-9")
{
 StringTrimLeft, Error, Error, 1
 MsgBox, % ErrorCode%Error%
 Return
}
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
  TempVar := RIni_GetKeyValue(1,TempVar6,"parameters")
;  IniRead, TempVar99, %EmuIniPath%, %TempVar6%, parameters, Error
;    MsgBox, %TempVar%`n%Tempvar6%`n%TempVar99%
  If TempVar <>
  {
   StringReplace, TempVar12, TempVar, `%ROM`%, `%ROMMAME`%
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
 Loop, Parse, IniKeys, `,
 {
  Value := %A_LoopField%
  IniWrite, %Value%, %ScriptIni%, General, %A_LoopField%
 }
}

;***************************************************************************************************

UnHTM( HTM ) {   ; Remove HTML formatting / Convert to ordinary text   by SKAN 19-Nov-2009
 Static HT,C=";" ; Forum Topic: www.autohotkey.com/forum/topic51342.html  Mod: 16-Sep-2010
 IfEqual,HT,,   SetEnv,HT, % "&aacuteá&acircâ&acute´&aeligæ&agraveà&amp&aringå&atildeã&au"
 . "mlä&bdquo„&brvbar¦&bull•&ccedilç&cedil¸&cent¢&circˆ&copy©&curren¤&dagger†&dagger‡&deg"
 . "°&divide÷&eacuteé&ecircê&egraveè&ethð&eumlë&euro€&fnofƒ&frac12½&frac14¼&frac34¾&gt>&h"
 . "ellip…&iacuteí&icircî&iexcl¡&igraveì&iquest¿&iumlï&laquo«&ldquo“&lsaquo‹&lsquo‘&lt<&m"
 . "acr¯&mdash—&microµ&middot·&nbsp &ndash–&not¬&ntildeñ&oacuteó&ocircô&oeligœ&ograveò&or"
 . "dfª&ordmº&oslashø&otildeõ&oumlö&para¶&permil‰&plusmn±&pound£&quot""&raquo»&rdquo”&reg"
 . "®&rsaquo›&rsquo’&sbquo‚&scaronš&sect§&shy &sup1¹&sup2²&sup3³&szligß&thornþ&tilde˜&tim"
 . "es×&trade™&uacuteú&ucircû&ugraveù&uml¨&uumlü&yacuteý&yen¥&yumlÿ"
 $ := RegExReplace( HTM,"<[^>]+>" )               ; Remove all tags between  "<" and ">"
 Loop, Parse, $, &`;                              ; Create a list of special characters
   L := "&" A_LoopField C, R .= (!(A_Index&1)) ? ( (!InStr(R,L,1)) ? L:"" ) : ""
 StringTrimRight, R, R, 1
 Loop, Parse, R , %C%                               ; Parse Special Characters
  If F := InStr( HT, L := A_LoopField )             ; Lookup HT Data
    StringReplace, $,$, %L%%C%, % SubStr( HT,F+StrLen(L), 1 ), All
  Else If ( SubStr( L,2,1)="#" )
    StringReplace, $, $, %L%%C%, % Chr(((SubStr(L,3,1)="x") ? "0" : "" ) SubStr(L,3)), All
Return RegExReplace( $, "(^\s*|\s*$)")            ; Remove leading/trailing white spaces
}

Ansi2Oem(sString)
{
   Ansi2Unicode(sString, wString, 0)
   Unicode2Ansi(wString, zString, 1)
   Return zString
}

Oem2Ansi(zString)
{
   Ansi2Unicode(zString, wString, 1)
   Unicode2Ansi(wString, sString, 0)
   Return sString
}

Ansi2UTF8(sString)
{
   Ansi2Unicode(sString, wString, 0)
   Unicode2Ansi(wString, zString, 65001)
   Return zString
}

UTF82Ansi(zString)
{
   Ansi2Unicode(zString, wString, 65001)
   Unicode2Ansi(wString, sString, 0)
   Return sString
}

Ansi2Unicode(ByRef sString, ByRef wString, CP = 0)
{
     nSize := DllCall("MultiByteToWideChar"
      , "Uint", CP
      , "Uint", 0
      , "Uint", &sString
      , "int",  -1
      , "Uint", 0
      , "int",  0)

   VarSetCapacity(wString, nSize * 2)

   DllCall("MultiByteToWideChar"
      , "Uint", CP
      , "Uint", 0
      , "Uint", &sString
      , "int",  -1
      , "Uint", &wString
      , "int",  nSize)
}

Unicode2Ansi(ByRef wString, ByRef sString, CP = 0)
{
     nSize := DllCall("WideCharToMultiByte"
      , "Uint", CP
      , "Uint", 0
      , "Uint", &wString
      , "int",  -1
      , "Uint", 0
      , "int",  0
      , "Uint", 0
      , "Uint", 0)

   VarSetCapacity(sString, nSize)

   DllCall("WideCharToMultiByte"
      , "Uint", CP
      , "Uint", 0
      , "Uint", &wString
      , "int",  -1
      , "str",  sString
      , "int",  nSize
      , "Uint", 0
      , "Uint", 0)
}