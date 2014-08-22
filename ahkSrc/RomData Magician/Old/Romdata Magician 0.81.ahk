#NoEnv
#SingleInstance Force
SetWorkingDir, %A_ScriptDir%
;SetTitleMatchMode, 2
InitializeVars() 
CreateGUIs()
Gui, Show, Maximize, %ScriptName%
Gosub, LoadRomData
Gosub, SRLV_Load
Return

InitializeVars()
{
 Global
 ScriptName = RomData Magician
 ScriptIni = RomData Magician.ini
 IfNotExist, %ScriptIni%
   Gosub, CreateIni
 IllegalChars := ".,<>:;'""/|\(){}=-+!`%^&*~ "
 IniRead, QPFolder, %ScriptIni%, General, QPath, Error
 If (QPFolder = "Error") OR (QPFolder = "")
    Gosub, GetQPFolder
 Glob(list, QPfolder . "\data\*\RomData.dat", 1,1)  ; Get List of Romdata Folders
 Loop, Parse, List, `n
 {
  Pos := InStr(A_LoopField, "\Data\") + 6
  Folder := SubStr(A_LoopField, Pos)
  FolderList .= Folder . "|"
 }
 If FolderList =
 {
  MsgBox, I can't seem to find any romdata.dat files.`nThis program will exit.
  ExitApp
 }
 StringReplace, FolderList, FolderList, |, ||
 
 ; Get List of Systems / Emulators
 IniRead, SystemIniFilePath, %ScriptIni%, General, SystemIniFilePath, Error
 If (SystemIniFilePath = "Error") OR (SystemIniFilePath = "")
    Gosub, GetIniFilePath
 Glob(IniPaths, SystemIniFilePath . "\*\*.ini", 0,1)
 FileRead, EmulatorsIni, %QPFolder%\dats\emulators.ini
 SystemNames := ini_getAllSectionNames(EmulatorsIni)
 Loop, Parse, SystemNames, `,
 {
  Emulator := A_LoopField
  Ini_Read(System, EmulatorsIni, Emulator, "system")
  IniRead, GoodName, %ScriptIni%, QP system to Ini, %System%, Error
  If (System <> "ERROR") AND (System <> "")
  {
   Loop, Parse, IllegalChars
     StringReplace, Emulator, Emulator, %A_LoopField%,, A
   Loop, Parse, IllegalChars
     StringReplace, System, System, %A_LoopField%,, A
   %Emulator% := System
;   MsgBox, %Emulator% - %System%
   If GoodName <> Error
   {
    Loop, Parse, IniPaths, `n
    {
     IfInString, A_LoopField, %GoodName%
        %System%IniPath := A_LoopField
    }
   }
  }
 }
 IniRead, RatingsMode, %QPFolder%\dats\settings.ini, Ratings, Mode
 IniRead, RatingsLow, %QPFolder%\dats\settings.ini, Ratings, low
 IniRead, RatingsHigh, %QPFolder%\dats\settings.ini, Ratings, high
 IniRead, RatingsCustom, %QPFolder%\dats\settings.ini, Ratings, Custom
 DefaultRatings := " - Crap, - Poor, - Average, - Good, - Excellent" 
 StringSplit, DefaultRatings, DefaultRatings, `,
 TempVar := "1-5 with Text,Stars (1-5),Numeric Range,Custom"
 Loop, Parse, TempVar, `,
 {
  If A_Index = %RatingsMode%
     DD_Ratings .= A_LoopField "||"
  Else DD_Ratings .= A_LoopField "|"
 }
 RomDataOptions := "Language,Rating,Year,Comment,Company,GameType,Players"
 CommentOptions := "Controls|Perspective|Systems|ESRB"
 StringSplit, CommentOptions, CommentOptions, |
}

GetQPFolder:
 Loop
 {
  FileSelectFolder, QPFolder, *%QPFolder%, 0, Browse to your QuickPlay Folder.
  IfNotExist %QPFolder%\Efind
    MsgBox, Unable to verify Quick Play folder location`n Press {CTRL} Q to exit.
  Else Break
 }
 IniWrite, %QPFolder%, %ScriptIni%, General, QPath
Return

GetIniFilePath:
  FileSelectFolder, SystemIniFilePath, *c:\, 0, Browse to your System Ini Files
  IniWrite, %SystemIniFilePath%, %ScriptIni%, General, SystemIniFilePath
Return

CreateGUIs()
{
 Global
 ListViewWidth := A_ScreenWidth-5
 ListViewHeight := A_ScreenHeight-380
 Gui, 1:Default ; Main Gui
 Gui, +OwnDialogs

;  300   200        0        0      0     200      150     70     90      70      70         0        150     50          0       0    0   0    0     0     100        0              0
;   1     2         3        4      5      6       7       8      9       10      11         12       13      14         15      16                       IPSPos+1   IPSpos+2       IPSpos+3
; Name|Ini Name|ParentName|ZipName|path|Emulator|Company|Year|Game Type|Rating|Language|Parameters|Comment|NumPlayed|ParamMode|<IPS>|IPS1|IPS2|IPS3|</IPS>|Players|DefaultGoodMerge|System
                                                       
 Gui, Add, ListView, x2 y10 w%ListViewWidth% h%ListViewHeight% vQuickPlayLV
 , Name|Ini Name|ParentName|ZipName|path|Emulator|Company|Year|Game Type|Rating|Language|Parameters|Comment|Played|ParamMode|<IPS>|IPS1|IPS2|IPS3|</IPS>|Players|DefaultGoodMerge|System
 ColWidth =   300,200,0,0,0,200,150,70,90,70,70,0,150,50,0,0,0,0,0,0,100,0,0
 Loop, Parse, ColWidth, `,
       Lv_ModifyCol(A_Index,A_LoopField)
 Gui, Font, Bold
 Gui, Add, GroupBox, x2 y+10 w385 h305 Section, RomData Options
 Gui, Font, Norm
 Gui, Add, CheckBox, x30 yp+25 vAdd gAllNone, Select all/none
 Gui, Add, CheckBox, x150 yp check3 vWrite gAllNone, Select all/none
 Gui, Add, CheckBox, x270 yp vResetPlayed, Reset Played to 0
 Gui, Add, CheckBox, x30 yp+35 vAddLanguage, Add Language
 Gui, Add, CheckBox, x150 yp check3 vWriteLanguage, Over Write?
 Gui, Add, CheckBox, x30 yp+25 vAddRating, Add Rating
 Gui, Add, CheckBox, x150 yp check3 vWriteRating, Over Write?
 Gui, Add, DropDownList, x270 yp-3 w100 AltSubmit vSelectedRating, %DD_ratings%
 Gui, Add, CheckBox, x30 yp+25 vAddYear, Add Year
 Gui, Add, CheckBox, x150 yp check3 vWriteYear, Over Write?
 Gui, Add, CheckBox, x30 yp+25 vAddComment, Add Comment
 Gui, Add, CheckBox, x150 yp check3 vWriteComment, Over Write?
 Gui, Add, DropDownList, x270 yp-3 w100 AltSubmit vSelectedOption, Control Type||Perspective|Other Systems|ESRB
 Gui, Add, CheckBox, x30 yp+28 vAddCompany, Add Company
 Gui, Add, CheckBox, x150 yp check3 vWriteCompany, Over Write?
 Gui, Add, CheckBox, x30 yp+25 vAddGameType, Add Game Type
 Gui, Add, CheckBox, x150 yp check3 vWriteGameType, Over Write?
 Gui, Add, CheckBox, x30 yp+25 vAddPlayers, Add Player Info
 Gui, Add, CheckBox, x150 yp check3 vWritePlayers, Over Write?
 Gui, Font, Bold
 Gui, Add, Text, x10 yp+28, Current Folder
 Gui, Font, Norm
 Gui, Add, DropDownList, x30 yp+25 w220 vSelectedFolder gLoadRomData, %FolderList%
 Gui, Add, Button, x270 ys+212 h30 w100, Preview
 Gui, Add, Button, x270 yP+40 h30 w100, Save
 Gui, Add, StatusBar, x30 w324
 
  ;Language
 Gui, Font, Bold
 Gui, Add, GroupBox, Section xs+400 ys w390 h305, Language
 Gui, Font, Norm
 Gui, Add, ListView, xp+20 yp+25 w244 r14 AltSubmit gSRLV vSRLV, Code|Language
 LV_ModifyCol(1, 65)
 LV_ModifyCol(2, 175)
 Gui, Add, Text, x+16 yp, Code:
 Gui, Add, Edit, xp y+3 w85 r1 vNewCode
 Gui, Add, Text, xp y+3, Language:
 Gui, Add, Edit, xp y+3 w85 r1 vNewLanguage
 Gui, Add, Button, xp y+14 w85 gSRLV_Add, Add New
 Gui, Add, Button, xp y+14 w85 gSRLV_Replace, Replace   
 Gui, Add, Button, xp y+14 w85 gSRLV_Remove, Delete
 Gui, Add, Button, xp y+14 w85 gSRLV_Clear, Delete All
 Gui, Add, Button, xp y+14 w38 gSRLV_Up, /\
 Gui, Add, Button, x+10 yp w38 gSRLV_Down, \/
 
 Menu, FileMenu, Add, QuickPlay Folder, GetQPFolder
 Menu, FileMenu, Add, Ini Files  Folder, GetIniFilePath
 Menu, MyMenuBar, Add, &File, :FileMenu
 Menu, CreditsMenu, Add, Credits, ShowCredits
 Menu, MyMenuBar, Add, About, :CreditsMenu
 Gui, Menu, MyMenuBar
}

ShowCredits:
WinH = 48          ; Height of GUI
YPos := WinH   ; Bottom of GUI Window
TestText =
(LTrim
   Author:`t Matt McLemore Aka 'Tempest'
   
   
   
   Beta Tester:`t Butter100Fly
   
   
   Functions:
   
   Basic ini string functions by Tuncay
   http://www.autohotkey.com/forum/topic46226.html
   
   
   
   Globals From Ini by Tuncay
   http://www.autohotkey.com/forum/topic27928.html
    
  
   
   
)
Gui, 99:Default
Gui +ToolWindow +AlwaysOnTop
Gui Margin, 0, 0
Gui, Font, Bold s10
Gui Add, Text, vText x5 y%YPos%, %TestText%
Gui, Font, Normal
Gui Show, w350 h%WinH%, Credits:
Loop
{
 YPos := WinH  ; Bottom of GUI Window
 Loop
 {
    YPos--
    GuiControl Move, Text, y%YPos%
    GuiControlGet Text, Pos
    If (textY + textH < WinH)
       Break
    Sleep 50
 }
; Sleep 50
}

;Gui, Destroy
;Gui, 1:Default
;Return
;**************************** String Replacement ListView Labels/Subs ******************************

SRLV:
 Gui, 1:ListView, SRLV
 If A_GuiEvent = Normal
 {
  EditRow := A_EventInfo
  LV_GetText( text, A_EventInfo, 1) 
  GuiControl,, Newcode, %Text%
  LV_GetText( text, A_EventInfo, 2)
  GuiControl,, NewLanguage, %Text%
 }
Return

SRLV_Replace:
 Gui, ListView, SRLV
 If EditRow <>
 {
  GuiControlGet, NewLanguage
  GuiControlGet, Newcode
  LV_Modify(EditRow, "", NewCode, NewLanguage)
  GuiControl,, Newcode
  GuiControl,, NewLanguage
  EditRow =
 }
Return

SRLV_Add:
 Gui, ListView, SRLV
 GuiControlGet, NewLanguage
 GuiControlGet, Newcode
 If (NewLanguage <> "") AND (NewCode <> "")
 {
  LV_ADD("", NewCode, NewLanguage)
  GuiControl,, Newcode
  GuiControl,, NewLanguage
 }
Return

SRLV_Remove:
 Gui, ListView, SRLV
 RowNumber := LV_GetNext(0)
 IF RowNumber <> 0
 {
  LV_Delete(RowNumber)
  If (LV_GetCount()<18)
  {
   LV_ModifyCol(1, 65)
   LV_ModifyCol(2, 175)
  }
 }
Return

SRLV_Clear:
 Gui, ListView, SRLV
 LV_Delete()
 LV_ModifyCol(1, 65)
 LV_ModifyCol(2, 175)
Return

SRLV_Up:
 Gui, ListView, SRLV
 LV_MoveRow()
Return

SRLV_Down:
 Gui, ListView, SRLV
 LV_MoveRow(false)
Return

LV_MoveRow(moveup = true) 
{
 Loop, % (allr := LV_GetCount("Selected"))
    max := LV_GetNext(max)
 Loop, %allr% 
 {
  cur := LV_GetNext(cur)
  If ((cur = 1 && moveup) || (max = LV_GetCount() && !moveup))
     Return
  Loop, % (ccnt := LV_GetCount("Col"))
     LV_GetText(col_%A_Index%, cur, A_Index)
  LV_Delete(cur), cur := moveup ? cur-1 : cur+1
  LV_Insert(cur, "Select Focus", col_1)
  Loop, %ccnt%
     LV_Modify(cur, "Vis Col" A_Index, col_%A_Index%), col_%A_Index% := ""
 }
}

SRLV_Load:
 Gui, 1:ListView, SRLV
 GuiControl, -Redraw, SRLV
 IniRead, Languages, %ScriptIni%, General, Languages
 Loop, Parse, Languages, `,
 {
  StringSplit, TempVar, A_LoopField, |
  LV_Add("", TempVar1, TempVar2)
 }
 If LV_GetCount()>17
 {
  LV_ModifyCol(1, 56)
  LV_ModifyCol(2, 166)
 }
 GuiControl, +Redraw, SRLV
Return

SRLV_Save:
 Gui, ListView, SRLV
 Loop % LV_GetCount()
 {
  LV_GetText( Region, A_Index, 1)
  LV_GetText( Language, A_Index, 2)
  If A_Index = 1
     Languages := Region "|" Language
  Else
     Languages .= "," Region "|" Language
 }
 IniWrite, %Languages%, %ScriptIni%, General, Languages
Return

;************************************* Minor Subs / Functions **************************************

GuiClose:
 Gui, 99:Destroy
 MsgBox, 8196,, Exit %ScriptName%?
 IfMsgBox Yes
   ExitApp
Return

#IfWinActive, RomData Magician
 ^Q::ExitApp 
 ^R::Reload
#IfWinActive 

AllNone:
 Gui, Submit, NoHide
 Value := %A_GuiControl%
 Loop, Parse, RomDataOptions, `,
    GuiControl,, %A_GuiControl%%A_LoopField%, %Value%
Return

Glob(ByRef list, Pattern, IncludeDirs=0, Recurse=0)
{
    if (i:=RegExMatch(Pattern,"[*?]")) && (i:=InStr(Pattern,"\",1,i+1))
        Loop, % SubStr(Pattern, 1, i-1), 2, %Recurse%
            Glob(list, A_LoopFileLongPath . SubStr(Pattern,i), IncludeDirs)
    else
        Loop, %Pattern%, %IncludeDirs%
            list .= (list="" ? "" : "`n") . A_LoopFileLongPath
}

;************************************ Preview Selected Options *************************************

ButtonPreview:
 Gui, Submit, NoHide
 Gosub, SRLV_Save
 If ResetPlayed  = 1
 {
  MsgBox, 4,, Reset the number of times played to zero?
  IfMsgBox No
  {
   ResetPlayed = 0
   GuiControl,, ResetPlayed, 0
  }
 }
 If (AddRating = 1) AND (SelectedRating = 4)
 {
  StringReplace, RatingsCustom, RatingsCustom, 0D0A, ¬, All
  Loop, Parse, RatingsCustom, ¬
  {
   If A_LoopField <>
   {
    CustomRatings0 := A_Index
    CustomRatings%CustomRatings0%=
    LoopField := A_LoopField
    Loop
    {
     Hex := "0x" . SubStr(LoopField, (A_Index *2 -1), 2)
     If Hex = 0x
        Break
     Hex+= 0
    CustomRatings%CustomRatings0% .= Chr(Hex)
    }
   }
  }
 }
 If AddLanguage = 1
 {
  Gui, ListView, SRLV
  Loop % LV_GetCount()
  {
   LV_GetText( Region%A_Index%, A_Index, 1)
   LV_GetText( Language%A_Index%, A_Index, 2)
   Language0 := A_Index
  }
 }

;  300   200        0        0      0     200      150     70     90      70      70         0        150     50          0       0    0   0    0     0     100        0              0
;   1     2         3        4      5      6       7       8      9       10      11         12       13      14         15      16                       IPSPos+1   IPSpos+2       IPSpos+3
; Name|Ini Name|ParentName|ZipName|path|Emulator|Company|Year|Game Type|Rating|Language|Parameters|Comment|NumPlayed|ParamMode|<IPS>|IPS1|IPS2|IPS3|</IPS>|Players|DefaultGoodMerge|System

 Gui, ListView, QuickPlayLV
; GuiControl, -Redraw, QuickPlayLV
 Loop % LV_GetCount()
 {
  RowNumber := A_Index
  LV_GetText(FullTitle, RowNumber, 1)
  LV_GetText(Title, RowNumber, 2)
  If Title =
     Continue
  PlayersCol = 17
  While PlayersCol < 20
  {
   LV_GetText(TempText, RowNumber, PlayersCol)
   If TempText = </IPS>
      Break
   PlayersCol++
  }
  PlayersCol++
;  SystemCol := PlayersCol+2 ;Previously used this for Col Below. Not sure why? 
  Section := Varize(Title)
 ; MsgBox, %RowNumber%`,%SystemCol%
  LV_GetText(Emulator, RowNumber, 6)
  System := %Emulator%
  If System Not in %SystemList%
  {
   SystemList := SystemList = "" ? System : "," System
   SB_SetText("   Reading Data For " . System)
   FileRead, FileContent, % %System%IniPath
   IniFileExists := !ErrorLevel
   System := Varize(System)
   globalsFromIni(FileContent, System)
  }
  Else System := Varize(System)
  SB_SetText("   Current Title:  " . FullTitle)

  If ResetPlayed = 1
     LV_Modify(RowNumber, "Col14", "0")
     
  If AddLanguage = 1
  {
   If WriteLanguage = 1
      LV_Modify(RowNumber, "Col11", "")
   LV_GetText(TempVar, RowNumber, 11)
   If (TempVar = "") OR (WriteLanguage = 1)
   {
    StringReplace, TempVar, FullTitle, (, ¬, A
    StringReplace, TempVar, TempVar, ), ¬, A
    StringReplace, TempVar, TempVar, `,, ¬, A
    StringReplace, TempVar, TempVar, %A_Space%,, A
    NewLanguage := "English"
    Loop, %Language0%
    {
     IfInString, TempVar, % "¬" . Region%A_Index% . "¬"
     {
      NewLanguage := Language%A_Index%
      Break
     }
    }
    LV_Modify(RowNumber, "Col11", NewLanguage)  
   }
  }
  If IniFileExists = 0
     Continue
     
  If AddComment = 1
  {
   If WriteComment = 1
      LV_Modify(RowNumber, "Col13", "")
   LV_GetText(TempVar, RowNumber, 13)
   If (TempVar = "") OR (WriteComment = 1)
   {
    Comment := CommentOptions%SelectedOption%
    NewComment = %System%_%Section%_%Comment%
    NewComment := %NewComment%
    StringReplace, NewComment, NewComment, |, %A_Space%/%A_Space%, A
    LV_Modify(RowNumber, "Col13", NewComment)
   }
  }

  If AddGameType = 1
  {
   If WriteGameType = 1
      LV_Modify(RowNumber, "Col9", "")
   LV_GetText(TempVar, RowNumber, 9)
   If (TempVar = "") OR (WriteGameType = 1)
   {
    NewGameType = %System%_%Section%_Genre
    NewGameType := %NewGameType%
    StringReplace, NewGameType, NewGameType, |, %A_Space%/%A_Space%, A
    LV_Modify(RowNumber, "Col9", NewGameType)
   }   
  }

  If AddRating = 1
  {
   If WriteRating = 1
      LV_Modify(RowNumber, "Col10", "")
   LV_GetText(TempVar, RowNumber, 10)
   If (TempVar = "") OR (WriteRating <> 0)
   {
    NewRating = %System%_%Section%_Score
    If NewRating <> ...
    {
     If SelectedRating = 1
     {
      Rating := Round(NewRating)
      NewRating := Rating . DefaultRatings%Rating%
     }
     Else If SelectedRating = 2
     {
      Rating := Round(NewRating)
      NewRating := SubStr("*****", 1, Rating)
     }
     Else If SelectedRating = 3
     {
      Diff := RatingsHigh - RatingsLow + (1 * RatingsLow)
      Rating := Round(NewRating * Diff / 5)
      NewRating := Rating
      If Rating < %RatingsLow%
         Rating = 0
     } 
     Else If SelectedRating = 4
     {
      Rating := Round(NewRating * CustomRatings0 / 5)
      NewRating := CustomRatings%Rating%
     }
     If Rating <> 0
        LV_Modify(RowNumber, "Col10", NewRating)
    }
   }
  }

  If AddYear = 1
  {
   If WriteYear = 1
      LV_Modify(RowNumber, "Col8", "")
   LV_GetText(TempVar, RowNumber, 8)
   If (TempVar = "") OR (WriteYear = 1)
   {
    NewYear = %System%_%Section%_Released
    Pos := RegExMatch(%NewYear%, "\d{4}", NewYear1)
    If Pos = 0
       Pos := RegExMatch(FullTitle, "\((\d{4})\)", NewYear)
    LV_Modify(RowNumber, "Col8", NewYear1)
   }   
  }

  If AddCompany = 1
  {
   If WriteCompany = 1
      LV_Modify(RowNumber, "Col7", "")
   LV_GetText(TempVar, RowNumber, 7)
   If (TempVar = "") OR (WriteCompany = 1)
   {
    NewCompany = %System%_%Section%_Publisher
    LV_Modify(RowNumber, "Col7", %NewCompany%)
   }     
  }

  If AddPlayers = 1
  {
   If WritePlayers = 1
      LV_Modify(RowNumber, "Col"PlayersCol, "")
   LV_GetText(TempVar, RowNumber, PlayersCol)
   If (TempVar = "") OR (WritePlayers = 1)
   {
    NewPlayers = %System%_%Section%_Players
    LV_Modify(RowNumber, "Col"PlayersCol, %NewPlayers%)
   }
  }
 }

 If SelectedRating = 3
    LV_ModifyCol(10,"Float")
 Else
    LV_ModifyCol(10,"Text Left")
 GuiControl, +Redraw, QuickPlayLV
 SB_SetText("   Operation Completed.")
 SoundPlay, *64
Return

;****************************** Load Romdata Into QuickPlay ListView *******************************
;  300   200        0        0      0     200      150     70     90      70      70         0        150     50          0       0    0   0    0     0     100        0              0
;   1     2         3        4      5      6       7       8      9       10      11         12       13      14         15      16                       IPSPos+1   IPSpos+2       IPSpos+3
; Name|Ini Name|ParentName|ZipName|path|Emulator|Company|Year|Game Type|Rating|Language|Parameters|Comment|NumPlayed|ParamMode|<IPS>|IPS1|IPS2|IPS3|</IPS>|Players|DefaultGoodMerge|System

LoadRomData:
 Gui, Submit, NoHide
 Gui, ListView, QuickPlayLV
 LV_Delete()
 GuiControl, -Redraw, QuickPlayLV
 FileRead, RomDataDat, %QPfolder%\data\%SelectedFolder%
 PrevData6 =
 RowNumber =
 ROMDataFileVersion =
 Loop, Parse, RomDataDat, `n, `r
 {
  If A_LoopField =
     Continue
  IfNotInString, A_LoopField , ¬
  {
   If A_LoopField <>
      ROMDataFileVersion .= A_LoopField "`n"
   Continue
  }
  RowNumber ++
  StringSplit, Data, A_LoopField, ¬
  If A_LoopField Not Contains [bios],%A_Space%bios%A_Space%,Mame Win32
  {
   Data2 := RegExReplace(Data1, "[({[].+?[)}\]]")
   Data2 = %Data2%
  }
  If Data6 <> %PrevData6%
  {
   PrevData6 := Data6
   Loop, Parse, IllegalChars
     StringReplace, Data6, Data6, %A_LoopField%,, A
   System := %Data6%
  }
  IPS_Start = 16
  IPS_End = 16
  IPS_Index = 17
  While IPS_End < 20
  {
   IPS_End++
   If Data%IPS_End% = </IPS>
      Break

  }
  LV_Add("",Data1,Data2,Data3,Data4,Data5,Data6,Data7,Data8,Data9,Data10,Data11,Data12,Data13,Data14,Data15,Data16)
  Loop, % IPS_End - IPS_Start - 1
  {

   LV_Modify(RowNumber,"Col"IPS_Index,Data%IPS_Index%)
   IPS_Index++
  }
  IPS_Index := IPS_Index - IPS_End +20
  IPS_End_1 := IPS_End+1
  IPS_End_2 := IPS_End+2
  LV_Modify(Rownumber,"Col"IPS_Index, Data%IPS_End%, Data%IPS_End_1%, Data%IPS_End_2%, System)
 }
 GuiControl, +Redraw, QuickPlayLV
Return

;*************************************** Save Romdata File *****************************************
;  300   200        0        0      0     200      150     70     90      70      70         0        150     50          0       0    0   0    0     0     100        0              0
;   1     2         3        4      5      6       7       8      9       10      11         12       13      14         15      16                       IPSPos+1   IPSpos+2       IPSpos+3
; Name|Ini Name|ParentName|ZipName|path|Emulator|Company|Year|Game Type|Rating|Language|Parameters|Comment|NumPlayed|ParamMode|<IPS>|IPS1|IPS2|IPS3|</IPS>|Players|DefaultGoodMerge|System

ButtonSave:
 Gui, ListView, QuickPlayLV
; LV_ModifyCol(4, "Sort")
 NewRomData := ROMDataFileVersion
 Loop % LV_GetCount()
 {
  RowNumber := A_Index
  Loop, 16
  {
   LV_GetText(Text, RowNumber, A_Index)
   NewRomData .= Text "¬"
  }
  Loop, 3
  {
   LV_GetText(Text, RowNumber, A_Index+16)
   If Text <>
      NewRomData .= Text "¬"
  }
  Loop, 3
  {
   LV_GetText(Text, RowNumber, A_Index+19)
   NewRomData .= Text "¬"
  }
  NewRomData .= "`n"
 }
 FileMove, %QPfolder%\data\%SelectedFolder%\Romdata.dat, %QPfolder%\data\%SelectedFolder%\%A_Now%_Romdata.dat
 FileAppend, %NewRomData%, %QPfolder%\data\%SelectedFolder%\Romdata.dat
 MsgBox, %QPfolder%\data\%SelectedFolder%\Romdata.dat`nHas been saved.
Return

;****************************************** GetFileName ********************************************

GetFileName(Item,File,Ext)
{
 Global
 FileSelectFile, %File%Path,, %QPDatFolder%\%File%.%Ext%, Browse to your %File%.%Ext% file, *.%Ext%
 SplitPath, %File%Path, %File%Name, QPDatFolder
 If (Errorlevel <> 0)  OR (%File%Name <>  File . "." . Ext)
 {
  MsgBox, %Item% information will not be added
  %File%Name =
  QPDatFolder =
  GuiControl,, %Item%, 0
 }
 Return
}

;**************************** Change Name to Compatible Variable Name ******************************

Varize(Name)
{
 SetFormat, Integer, hex
 Loop, Parse, Name
 {
  If A_LoopField is alnum
     NewName .= A_LoopField
  Else
  {
   Num := Asc(A_LoopField)
   Num += 0
   NewName .= "¬" Num
  }
 }
 SetFormat, Integer, d
 Return NewName
}

;***************************************** Write Ini File ******************************************

CreateINI:
FileAppend,
(
[General]
Languages=C|Chinese,HK|Chinese,China|Chinese,H|Dutch,NL|Dutch,Dutch|Dutch,Netherlands|Dutch,En|English,FN|Finnish,Finland|Finnish,Fr|French,F|French,FC|French,France|French,G|German,Germany|German,GR|Greek,It|Italian,Italy|Italian,1|Japanese,J|Japanese,Japan|Japanese,K|Korean,Korea|Korean,Brazil|Portuguese,Es|Spanish,S|Spanish,Spain|Spanish,Sv|Svenska,SW|Swedish,Sweden|Swedish
QPath=
SystemIniFilePath=

[QP system to Ini]
Amstrad CPC=GoodCPC
Arcade=Arcade
Emerson Arcadia
Atari 2600=Good2600
Atari 5200=Good5200
Atari 7800=Good7800
Atari Lynx=GoodLYNX
Atari Jaguar=GoodJag
Channel F=GoodCHAF
Colecovision=GoodCOL
Commodore 64=GoodGB64
GameBoy=GoodGBx
GameBoy Advance=GoodGBA
Intellivision=GoodINTV
MSX=GoodMSX
MSX2=GoodMSX2
Neo Geo Pocket=GoodNGPx
NES=GoodNES
Nintendo 64=GoodN64
Nintendo DS=Nintendo DS
Oric=GoodOric
PC Engine\TurboGrafx-16=GoodPCE
PC Engine FX=GoodPCE
Sam Coupe=GoodSamC
Sega GameGear=GoodGG
Sega Genesis=GoodGen
Sega Master System=GoodSMS
Sega Pico=GoodPico
Super Nintendo=GoodSNES
Tandy CoCo Colour Computer=GoodCoCO
Tandy TRS-80=GoodCoCO
Thompson MO5=GoodMo5
Tiger Game.com=GoodGCOM
Vectrex=GoodVECT
Virtual Boy=GoodVBOY
Watara Supervision=GoodSV
WonderSwan=GoodWSx
),%ScriptIni%
Return

;*********************************** Basic ini string functions ************************************
;*********************************** Copyright (c) 2010, Tuncay ************************************
;************************ http://www.autohotkey.com/forum/topic46226.html **************************

ini_getAllSectionNames(ByRef _Content, ByRef _count = "")
{
    RegEx = `aisUmS)^.*(?:\s*\[\s*?(.*)\s*?]\s*|.+=.*).*$
    SectionNames := RegExReplace(_Content, RegEx, "$1", MatchNum)
    If MatchNum
    {
        SectionNames := RegExReplace(SectionNames, "S)\R+", ",", _count)
        ; Workaround, whitespaces only should be eliminated.
        SectionNames := RegExReplace(SectionNames, "S),+ +", "") 
        StringReplace, SectionNames, SectionNames, `,, `,, UseErrorLevel
        _count := ErrorLevel ? ErrorLevel : 0
        _count := _count ? _count : 0
        StringTrimRight, SectionNames, SectionNames, 1
        ErrorLevel = 0
    }
    Else
    {
        ErrorLevel = 1
        _count = 0
        SectionNames =
    }
    Return SectionNames
}

Ini_Read(ByRef _OutputVar, ByRef _Content, _Section, _Key, _Default = "ERROR")
{
    If (_Section != "")
    {
        BackupErrorLevel := ErrorLevel
        _OutputVar := ini_getValue(_Content, _Section, _Key)
        If ErrorLevel
        {
            _OutputVar := _Default
        }
        ErrorLevel := BackupErrorLevel
    }
    Else
    {
        _OutputVar := _Default
    }
    Return 
}

ini_getValue(ByRef _Content, _Section, _Key, _PreserveSpace = False)
{
    If (_Section = "")
        _Section = (?:\[.*])?
    Else
    {
         _Section = \[\s*?\Q%_Section%\E\s*?]
    }
    ; Note: The regex of this function was rewritten by Mystiq.
    RegEx = `aiU)(?:\R|^)\s*%_Section%\s*(?:\R\s*|\R\s*.+\s*=\s*.*?\s*(?=\R)|\R\s*[;#].*?(?=\R))*\R\s*\Q%_Key%\E\s*=(.*)(?=\R|$)
    If RegExMatch(_Content, RegEx, Value)
    {
        If Not _PreserveSpace
        {
            Value1 = %Value1% ; Trim spaces.
            FirstChar := SubStr(Value1, 1, 1)
            If (FirstChar = """" AND SubStr(Value1, 0, 1)= """"
                OR FirstChar = "'" AND SubStr(Value1, 0, 1)= "'")
            {
                StringTrimLeft, Value1, Value1, 1
                StringTrimRight, Value1, Value1, 1
            }
        }
        ErrorLevel = 0
    }
    Else
    {
        ErrorLevel = 1
        Value1 =
    }
    Return Value1
}

;*********************************** Globals from Ini By Tuncay ************************************
;************************ http://www.autohotkey.com/forum/topic27928.html **************************

globalsFromIni( FileContent, CurrentSystem, _VarPrefixDelim = "_")
{
    Global
    Local CurrentPrefix, CurrentVarName, CurrentVarContent, DelimPos
    Loop, Parse, FileContent, `n, `r%A_Tab%%A_Space%
    {
        If A_LoopField Is Not Space
        {
            If (SubStr(A_LoopField, 1, 1) = "[")
            {
                StringTrimLeft, CurrentPrefix, A_LoopField, 1
                StringTrimRight, CurrentPrefix, CurrentPrefix, 1
                CurrentPrefix := CurrentSystem _VarPrefixDelim Varize(CurrentPrefix)
            }
            Else
            {
                DelimPos := InStr(A_LoopField, "=")
                StringLeft, CurrentVarName, A_LoopField, % DelimPos - 1
                CurrentVarName := Varize(CurrentVarName)
                StringTrimLeft, CurrentVarContent, A_LoopField, %DelimPos%
                %CurrentPrefix%%_VarPrefixDelim%%CurrentVarName% = %CurrentVarContent%
            }
        }
    }
}