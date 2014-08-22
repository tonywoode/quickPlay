#SingleInstance Force
SetWorkingDir, %A_ScriptDir%
FileRead, Keywords, List.txt
StringReplace, VarNames, Keywords, %A_Space%,,A
StringReplace, VarNames, VarNames, -,,A
StringSplit, VarNames, Varnames, `,
;VarNames1 = Addon
Loop, E:\AHK\My AHK\Emulator Ini Project\ButterFly's Attachments\Mess\hash\*.xml
{
 Tooltip, %A_loopFileName%
 CheckData = 0
 FileRead, Text, %A_LoopFileFullPath%
 Loop, Parse, Text, `r, `n%A_Space%%A_Tab%
 {
  IfInString, A_LoopField, area name=
    Checkdata = 0
  If A_LoopField = 
     Checkdata = 0
  If CheckData = 1
  {
   If A_LoopField Contains %KeyWords%
   {
    LoopField := A_LoopField
    Loop, Parse, Keywords, `,
    {
     IfInstring, LoopField, %A_LoopField%
     {
      VarName :=  VarNames%A_Index%
      %VarName% .= LoopField "`n"
     }
    }
   }
  }
  IfInString, A_LoopField, <description>
    Checkdata = 1
 }
}
Loop, Parse, Keywords, `,
{
 VarName := VarNames%A_Index%
 Data := %VarName%
 Sort, Data, U
 MsgBox,260,, % "Save " A_loopfield "`n`n" Data
 IfMsgBox Yes
 {
  FileDelete, data\%A_LoopField%.txt
  FileAppend, %Data%, Data\%A_LoopField%.txt
 }
}
MsgBox, Done.
ExitApp


^Q::ExitAPP