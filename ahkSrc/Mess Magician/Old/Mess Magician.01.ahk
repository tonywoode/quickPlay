#SingleInstance, force
SetWorkingDir, %A_ScriptDir%
#NoEnv
OnExit, ExitLabel
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
 RemoveExtraInfo=0
 AddCloneInfo=1
 AddParentInfo=1
 AddYear=1
 AddPublisher=1
 ), %ScriptIni%
}
IniKeys := "RomDataPath,XMLPath,RemoveExtraInfo,AddCloneInfo,AddParentInfo,AddYear,AddPublisher"
Loop, Parse, IniKeys, `,
   IniRead, %A_LoopField%, %ScriptIni%, General, %A_LoopField%, 0
Gui, +OwnDialogs
Gui, Add, Text, x10 y34 w70, Romdata File
Gui, Add, Edit, ReadOnly x90 y30 w360 r1 vRomDataPath, %RomDataPath%
Gui, Add, Button, x470 y29 w30 gGetRomDataPath, ...
Gui, Add, Text, x10 y84 w130, %Space%XML File
Gui, Add, Edit, ReadOnly x90 y80 w360 r1 vXmlPath, %XmlPath%
Gui, Add, Button, x470 y79 w30 gGetXmlPath, ...
;Gui, Add, CheckBox, x90 y130 checked%RemoveExtraInfo% vRemoveExtraInfo, Remove (???) Information From Description
Gui, Add, CheckBox, x90 y130 checked%AddCloneInfo% vAddCloneInfo, Add Clone Information
Gui, Add, CheckBox, x90 y+5 checked%AddParentInfo% vAddParentInfo, Add Parent Information
Gui, Add, CheckBox, x90 y+5 checked%AddYear% vAddYear, Add Year
Gui, Add, CheckBox, x90 y+5 checked%AddPublisher% vAddPublisher, Add Publisher Information
Gui, Add, Button, x400 yp-15 w100 h30 Default gButtonGo, GO!
Gui, Add, Progress, x10 y+15 w490 h20 cGray BackgroundSilver vMyProgress

;If RemoveExtraInfo = 0
;   GuiControl, Hide, RemoveExtraInfo
Gui, Show, AutoSize, %ScriptName% by Matt Mclemore AKA 'Tempest'
Return

^Q::
GuiClose:
ExitLabel:
 WriteIni()
ExitApp
 
GetRomDataPath:
 Gui +OwnDialogs
 FileSelectFile, SelectedRomDataPath,, %RomDataDir%, Select Romdata.dat file, ROMData.dat
 If SelectedRomDataPath <>
 {
  SplitPath, SelectedRomDataPath,, RomDataDir
  GuiControl,, RomDataPath, %SelectedRomDataPath%
 }
Return

GetXmlPath:
 Gui +OwnDialogs
 FileSelectFile, SelectedXmlPath,, %XmlDir%, Select .xml file, *.xml
 If SelectedXmlPath <>
 {
  SplitPath, SelectedXmlPath,, XmlDir
  GuiControl,, XmlPath, %SelectedXmlPath%
 }
Return

ButtonGo:
Gui, Submit, NoHide
Gui, +OwnDialogs
FileRead, Xml, %SelectedXmlPath%
FileRead, Romdata, %SelectedRomDataPath%
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
  LoopField =
  Loop, %TempVar0%
    LoopField .= Tempvar%A_Index% "¬"
  StringTrimRight, LoopField, LoopField, 1
 }
  NewRomData .= LoopField "`n"
}
StringTrimRight, NewRomData, NewRomData, 1
GuiControl,, MyProgress, 0
FileSelectFile, SaveLocation, s, %SaveDir%, Save RomData file as:, *.dat
If (SaveLocation <> "") AND (ErrorLevel = 0)
{
 MsgBox, %SaveLocation%
 SplitPath, SaveLocation,, SaveDir
 IfExist, %SaveLocation%
 {
  FileDelete, %SaveLocation%
  Loop
  {
   IfNotExist, %SaveLocation%
     Break
  }
 }
 FileAppend, %NewRomData%, %SaveLocation%
 MsgBox, File has been saved
}
Else
 MsgBox, File has not been saved.
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