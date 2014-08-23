
#NoEnv
#SingleInstance Force
SetWorkingDir, %A_ScriptDir%

InitializeVars()
CreateGUIs()
Gosub, SRLV_Load
Gui, Show, Maximize, %ScriptName%
Gosub, LoadRomData
Return

InitializeVars()
{
 Global
 ScriptName = RomData Magician
 Version=.92
 ScriptIni = RomData Magician.ini
 IfNotExist, %ScriptIni%
   Gosub, CreateIni
 Loop, 100
 {
  Sleep, 50
  IfExist, %ScriptIni%
    Break
  If A_Index = 100
  {
   MsgBox, Could not find/create file:`n%A_ScriptDir%\%ScriptIni%
   ExitApp
  }
 }
 FileRead, ScriptIniContent, %ScriptIni%
 GlobalsFromSection(ScriptIniContent, "Settings")
 IllegalChars := ".,<>:;'""/|\(){}=-+!``%^&*~ "

 QPFolder := SubStr( A_ScriptDir, 1, InStr( A_ScriptDir, "\", "False", 0) -1)
 QPFolder := SubStr( QPFolder, 1, InStr( QPFolder, "\", "False", 0) -1)
 IfNotExist, %QPfolder%\data\
 {
  MsgBox, %QPfolder%\data\`ndoes not exist.
  ExitAPP
 }
 Glob(list, QPfolder . "\data\*\RomData.dat", 1,1)
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



 Glob(IniPaths, A_Scriptdir . "\GoodMerge System Ini and History Files\*\*.ini", 0,1)
 FileRead, emulatorsini, %QPFolder%\dats\emulators.ini
 FileRead, QPSystem, %Scriptini%
 SystemNames := ini_getAllSectionNames(emulatorsini)
 IniRead, RatingsMode, %QPFolder%\dats\settings.ini, Ratings, Mode, 3
 IniRead, RatingsLow, %QPFolder%\dats\settings.ini, Ratings, low, 1
 IniRead, RatingsHigh, %QPFolder%\dats\settings.ini, Ratings, high, 5
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

 OptionsToSimplify := "Controls|Developer|ESRB|Genre|Perspective|Players|Publisher|Systems|Type"
 Loop, Parse, OptionsToSimplify, |
 {
  CurrentList := A_LoopField
  FileRead, Contents, Key Lists\%A_LoopField%.txt
  Loop, Parse, Contents, `r, `n%A_Space%
  {
   IfInString, A_LoopField, ¬
   {
    Pos := InStr(A_LoopField, "¬")
    Var := SubStr(A_LoopField, 1, Pos-1)
    Loop, Parse, A_LoopField, ¬
    {
     LoopField := Varize(A_LoopField)
     %CurrentList%_%LoopField% := Var
    }
   }
   Else
   {
    LoopField := Varize(A_LoopField)
    %CurrentList%_%LoopField% := A_LoopField
   }
  }
 }

 Settings := ini_getAllValues(ini, "Settings")
}

CreateGUIs()
{
 Global
 ListViewWidth := A_ScreenWidth-5
 ListViewHeight := A_ScreenHeight-380
 Gui, 1:Default
 Gui, +OwnDialogs

;  300   200        0        0      0     200      150     70     90      70      70         0        150     50          0       0    0   0    0     0     100           0           0
;   1     2         3        4      5      6       7       8      9       10      11         12       13      14         15      16   17   18   19    20     21           22          23
; Name|Rom Name|ParentName|ZipName|path|Emulator|Company|Year|Game Type|Rating|Language|Parameters|Comment|NumPlayed|ParamMode|<IPS>|IPS1|IPS2|IPS3|</IPS>|Players|DefaultGoodMerge|System

 Gui, Add, ListView, x2 y10 w%ListViewWidth% h%ListViewHeight% vQuickPlayLV
 , Name|Rom Name|ParentName|ZipName|path|Emulator|Company|Year|Game Type|Rating|Language|Parameters|Comment|Played|ParamMode|<IPS>|IPS1|IPS2|IPS3|</IPS>|Players|DefaultGoodMerge|System|LookUpName|LookUpSystem
 ColWidth =   350,300,300,0,0,0,200,70,90,70,70,0,150,50,0,0,0,0,0,0,100,0,0,280,170
 Loop, Parse, ColWidth, `,
       Lv_ModifyCol(A_Index,A_LoopField)
 Gui, Font, Bold
 Gui, Add, GroupBox, x2 y+10 w410 h305 Section, RomData Options
 Gui, Font, Norm
 Gui, Add, CheckBox, x30 yp+30 vAdd gAllNone, Select all/none
 Gui, Add, CheckBox, Check3 x150 yp vWrite gAllNone, Select all/none
 Gui, Add, CheckBox, x270 yp-15 vResetPlayed Checked%ResetPlayed%, Reset Played to 0
 Gui, Add, CheckBox, x270 yp+25 vSimplifyData Checked%SimplifyData%, Simplify Data
 Gui, Add, CheckBox, x30 yp+25 vAddLanguage Checked%AddLanguage%, Add Language
 Gui, Add, CheckBox, Check3 x150 yp vWriteLanguage Checked%WriteLanguage%, Over Write?
 Gui, Add, CheckBox, x270 yp vLanguageFromTitle Checked%LanguageFromTitle%, Add Missing From Title?
 Gui, Add, CheckBox, x30 yp+25 vAddYear Checked%AddYear%, Add Year
 Gui, Add, CheckBox, Check3 x150 yp vWriteYear Checked%WriteYear%, Over Write?
 Gui, Add, CheckBox, x270 yp vYearFromTitle Checked%YearFromTitle%, Add Missing From Title?
 Gui, Add, CheckBox, x30 yp+25 vAddRating Checked%AddRating%, Add Rating
 Gui, Add, CheckBox, Check3 x150 yp vWriteRating Checked%WriteRating%, Over Write?
 Gui, Add, DropDownList, x270 yp-2 w126 AltSubmit vSelectedRating, %DD_ratings%
 Gui, Add, CheckBox, x30 yp+25 vAddComment Checked%AddComment%, Add Comment
 Gui, Add, CheckBox, Check3 x150 yp vWriteComment Checked%WriteComment%, Over Write?
 Gui, Add, DropDownList, x270 yp-2 w126 AltSubmit vSelectedComment, Control Type||Perspective|Other Systems|ESRB
 Gui, Add, CheckBox, x30 yp+25 vAddCompany Checked%AddCompany%, Add Company
 Gui, Add, CheckBox, Check3 x150 yp vWriteCompany Checked%WriteCompany%, Over Write?
 Gui, Add, DropDownList, x270 yp-2 w126 AltSubmit vSelectedCompany, Company / Publisher||Company|Publisher
 Gui, Add, CheckBox, x30 yp+25 vAddGameType Checked%AddGameType%, Add Game Type
 Gui, Add, CheckBox, Check3 x150 yp vWriteGameType Checked%WriteGameType%, Over Write?
 Gui, Add, CheckBox, x30 yp+25 vAddPlayers Checked%AddPlayers%, Add Player Info
 Gui, Add, CheckBox, Check3 x150 yp vWritePlayers Checked%WritePlayers%, Over Write?
 Gui, Font, Bold
 Gui, Add, Text, x10 yp+25, Current Folder
 Gui, Font, Norm
 Gui, Add, DropDownList, x30 yp+25 w220 vSelectedFolder gLoadRomData, %FolderList%
 Gui, Add, Button, x270 ys+212 h30 w126 gPreview, GO!
 Gui, Add, Button, x270 yP+40 h30 w126 gSave, Save RomData
 Gui, Add, StatusBar, x30 w324

  ;Language
 Gui, Font, Bold
 Gui, Add, GroupBox, Section xs+420 ys w380 h305, Language
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

 Menu, MyMenuBar, Add, About, ShowCredits
 Gui, Menu, MyMenuBar

 WinH = 48
 YPos := WinH
 CreditsText =
 (LTrim
 
    %ScriptName%%Version%
 
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
 Gui Add, Text, vCreditsGui x5 y%YPos%, %CreditsText%
 Gui, Font, Normal
 Gui, 1:Default
}

ShowCredits:
 Gui, 99:Default
 Gui, Show, w350 h%WinH%, RomData Magician Credits:
 Loop
 {
  YPos := WinH  ; Bottom of GUI Window
  Loop
  {
     YPos--
     GuiControl 99:Move, CreditsGui, y%YPos%
     GuiControlGet CreditsGui, Pos
     If (CreditsGuiY + CreditsGuiH < WinH)
        Break
     Sleep 50
  }
 }
Return

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

99GuiClose:
 Gui, Hide
 Gui, 1:Default
Return

GuiClose:
 Gui, 99:Hide
 GoSub, SaveIniSettings
 MsgBox, 8196,, Exit %ScriptName%?
 IfMsgBox Yes
   ExitApp
Return


 ^Q::ExitApp
 ^R::Reload


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

SaveiniSettings:
 Gui, 1:Default
 Gui, Submit, NoHide
 Keys := ini_getAllKeyNames(ScriptIniContent, "Settings")
 Loop, Parse, Keys, `,
 {
  Value := %A_LoopField%
  IniWrite, %Value%, %ScriptIni%, Settings, %A_LoopField%
 }
Return

;************************************ Preview Selected Options *************************************


Preview:
 GoSub, SaveIniSettings
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
;   1     2         3        4      5      6       7       8      9       10      11         12       13      14         15      16   17   18   19    20     21           22          23
; Name|Rom Name|ParentName|ZipName|path|Emulator|Company|Year|Game Type|Rating|Language|Parameters|Comment|NumPlayed|ParamMode|<IPS>|IPS1|IPS2|IPS3|</IPS>|Players|DefaultGoodMerge|System

 Gui, ListView, QuickPlayLV

 If ResetPlayed = 1
    LV_Modify(RowNumber, "Col14", "0")
 Loop % LV_GetCount()
 {
  RowNumber := A_Index
  LV_GetText(FullTitle, RowNumber, 1)
  LV_GetText(Title, RowNumber, 24)
  LV_GetText(System, RowNumber, 25)
  If Title =
     Continue
  Section := Varize(Title)
  vSystem := Varize(System)
  PlayersCol = 17
  While PlayersCol < 20
  {
   LV_GetText(TempText, RowNumber, PlayersCol)
   If TempText = </IPS>
      Break
   PlayersCol++
  }
  PlayersCol++
  SB_SetText("   Current Title:  " . FullTitle)
  If IniFileExists = 0
     Continue

  If AddLanguage = 1
  {
   If WriteLanguage = 1
      LV_Modify(RowNumber, "Col11", "")
   LV_GetText(TempVar, RowNumber, 11)
   If (TempVar = "") OR (WriteLanguage = 1)
   {
    NewLanguage = %vSystem%_%Section%_Language
    NewLanguage := %NewLanguage%
    If (NewLanguage = "") AND (LanguageFromTitle = 1)
    {
     StringReplace, TempVar, FullTitle, (, ¬, A
     StringReplace, TempVar, TempVar, ), ¬, A
     StringReplace, TempVar, TempVar, [, ¬, A
     StringReplace, TempVar, TempVar, ], ¬, A
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
    }
    LV_Modify(RowNumber, "Col11", NewLanguage)
   }
  }

  If AddComment = 1
  {
   If WriteComment = 1
      LV_Modify(RowNumber, "Col13", "")
   LV_GetText(TempVar, RowNumber, 13)
   If (TempVar = "") OR (WriteComment = 1)
   {
    CommentType := CommentOptions%SelectedComment%
    NewComment = %vSystem%_%Section%_%CommentType%
    NewComment := %NewComment%
    If (SimplifyData = 1) AND (NewComment <> "")
    {
     NewComment := Varize(NewComment)
     TempVar = %CommentType%_%NewComment%
     NewComment := %TempVar%
    }
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
    NewGameType = %vSystem%_%Section%_Genre
    NewGameType := %NewGameType%
    If (SimplifyData = 1) AND (NewGameType <> "")
    {
     NewGameType := Varize(NewGameType)
     TempVar = Genre_%NewGameType%
     NewGameType := %TempVar%
    }
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
    NewRating = %vSystem%_%Section%_Score
    NewRating := %NewRating%
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
    NewYear = %vSystem%_%Section%_Released
    Pos := RegExMatch(%NewYear%, "\d{4}", NewYear1)
    If (Pos = 0) AND (YearFromTitle = 1)
       Pos := RegExMatch(FullTitle, "\((\d{4})\)", NewYear)
    LV_Modify(RowNumber, "Col8", NewYear1)
   }
  }
; OptionsToSimplify := "Controls|Developer|ESRB|Genre|Perspective|Players|Publisher|Systems|Type"
  If AddCompany = 1
  {
   If WriteCompany = 1
      LV_Modify(RowNumber, "Col7", "")
   LV_GetText(TempVar, RowNumber, 7)
   If (TempVar = "") OR (WriteCompany = 1)
   {
    Developer = %vSystem%_%Section%_Developer
    Developer := %Developer%
    Publisher = %vSystem%_%Section%_Publisher
    Publisher := %Publisher%
    If (SimplifyData = 1) AND (Developer <> "")
    {
     Developer := Varize(Developer)
     TempVar = Developer_%Developer%
     Developer := %TempVar%
    }
    If (SimplifyData = 1) AND (Publisher <> "")
    {
     Publisher := Varize(Publisher)
     TempVar = Publisher_%Publisher%
     Publisher := %TempVar%
    }
    NewCompany := Publisher
    If SelectedCompany = 1
    {
     StringReplace, Developer, Developer, /, `,, A
     StringReplace, Publisher, Publisher , /, `,, A
     If (Developer <> "") AND (Publisher <> "")
         NewCompany := Developer " / " Publisher
     Else
     {
      If Publisher =
         NewCompany := Developer
     }
    }
    Else If SelectedCompany = 2
    {
     NewCompany := Developer
    }
    Else NewCompany := Publisher

    LV_Modify(RowNumber, "Col7", NewCompany)
   }
  }

  If AddPlayers = 1
  {
   If WritePlayers = 1
      LV_Modify(RowNumber, "Col"PlayersCol, "")
   LV_GetText(TempVar, RowNumber, PlayersCol)
   If (TempVar = "") OR (WritePlayers = 1)
   {
    NewPlayers = %vSystem%_%Section%_Players
    NewPlayers := %NewPlayers%
    If (SimplifyData = 1) AND (NewPlayers <> "")
    {
     NewPlayers := Varize(NewPlayers)
     TempVar = Players_%NewPlayers%
     NewPlayers := %TempVar%
    }
    LV_Modify(RowNumber, "Col"PlayersCol, NewPlayers)
   }
  }
 }

 If SelectedRating = 3
    LV_ModifyCol(10,"Float")
 Else
    LV_ModifyCol(10,"Text Left")
 GuiControl, +Redraw, QuickPlayLV
 SB_SetText("   Ready.")
 SoundPlay, *64
Return

;****************************** Load Romdata Into QuickPlay ListView *******************************
;  300   200        0        0      0     200      150     70     90      70      70         0        150     50          0       0    0   0    0     0     100        0              0
;   1     2         3        4      5      6       7       8      9       10      11         12       13      14         15      16   17   18   19    20     21           22          23
; Name|Rom Name|ParentName|ZipName|path|Emulator|Company|Year|Game Type|Rating|Language|Parameters|Comment|NumPlayed|ParamMode|<IPS>|IPS1|IPS2|IPS3|</IPS>|Players|DefaultGoodMerge|System

LoadRomData:
 Gui, Submit, NoHide
 Gui, ListView, QuickPlayLV
 LV_Delete()
 GuiControl, -Redraw, QuickPlayLV
 FileRead, RomDataDat, %QPfolder%\data\%SelectedFolder%
 RowNumber =
 ROMDataFileVersion =
 Loop, Parse, RomDataDat, `n, `r
 {
  If A_LoopField =
     Continue
  IfNotInString, A_LoopField , ¬
  {
   ROMDataFileVersion .= A_LoopField "`n"
   Continue
  }
  RowNumber ++
  StringSplit, Data, A_LoopField, ¬

  Emulator := Data6
  vEmulator := Varize(Emulator)
  If %vEmulator% =
  {
   SB_SetText("   Finding Ini File Path For " . Emulator)
   Ini_Read(System, emulatorsini, Emulator, "system")
   Ini_Read(GoodName, QpSystem, "QP system to Ini", System)
   %vEmulator% := System
   vSystem := Varize(System)

   If (System <> "ERROR") AND (System <> "")
   {
    Loop, Parse, IniPaths, `n
    {
     SplitPath, A_LoopField,,,, OutFileName
     If GoodName <> Error
     {
      StringSplit, OutFileName, OutFileName, _
      If GoodName = %OutFileName1%
      {

       %vSystem%IniPath := A_LoopField
       Break
      }
     }
     Else
     {
      If Emulator = %OutFileName%
      {
       %vSystem%IniPath := A_LoopField
       Break
      }
     }
    }
   }
   If System Not In %SystemList%
   {
    SystemList := SystemList = "" ? System : "," System
    SB_SetText("   Reading Data For " . System)
    FileRead, FileContent, % %vSystem%IniPath
    IniFileExists := !ErrorLevel
    %vSystem%_Sections := getAllSectionNames(FileContent)
    globalsFromIni(FileContent, vSystem)
   }
  }
  SB_SetText("   Loading " Emulator " RomData.dat " A_LoopField)
  If A_LoopField Not Contains [bios],%A_Space%bios%A_Space%,Mame Win32
  {
   LookUpName := Data1
   TempVar = %vsystem%_Sections
   TempVar := %TempVar%
   StringReplace, Data, Data1, `,, ¬, A
   If Data Not In %TempVar%

      LookUpName := RegExReplace(Data1, "[({[].+?[)}\]]")
   LookUpName = %LookUpName%
  }

  LV_Add("",Data1,Data2,Data3,Data4,Data5,Data6,Data7,Data8,Data9,Data10,Data11,Data12,Data13
          ,Data14,Data15, "<IPS>", "", "", "", "</IPS>", Data21, Data22, Data23, LookupName, %vEmulator%)

  IPS_Index = 17
  While IPS_Index < 20
  {
   If Data%IPS_Index% = </IPS>
      Break
   LV_Modify(RowNumber,"Col"IPS_Index,Data%IPS_Index%)
   IPS_Index++
  }
 }
 GuiControl, +Redraw, QuickPlayLV
 SB_SetText("   Ready.")
 SoundPlay, *64
Return

;*************************************** Save Romdata File *****************************************
;  300   200        0        0      0     200      150     70     90      70      70         0        150     50          0       0    0   0    0     0     100        0              0
;   1     2         3        4      5      6       7       8      9       10      11         12       13      14         15      16   17   18   19    20     21           22          23
; Name|Rom Name|ParentName|ZipName|path|Emulator|Company|Year|Game Type|Rating|Language|Parameters|Comment|NumPlayed|ParamMode|<IPS>|IPS1|IPS2|IPS3|</IPS>|Players|DefaultGoodMerge|System





Save:
 Gui, Submit, NoHide
 Gui, ListView, QuickPlayLV

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
 Splitpath, SelectedFolder,, Dir
 FileMove, %QPfolder%\data\%Dir%\Romdata.dat, %QPfolder%\data\%Dir%\%A_Now%_Romdata.dat
 Sleep, 500
 FileAppend, %NewRomData%, %QPfolder%\data\%Dir%\Romdata.dat
 MsgBox, %QPfolder%\data\%Dir%\Romdata.dat`nHas been saved.
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

Varize(Text)
{
 Global IllegalChars
 Loop, Parse,  IllegalChars
    StringReplace, Text, Text, %A_LoopField%, #, A
 Return Text
}

;***************************************** Write Ini File ******************************************

CreateINI:
FileAppend,
(
[General]
Languages=C|Chinese,HK|Chinese,China|Chinese,H|Dutch,NL|Dutch,Dutch|Dutch,Netherlands|Dutch,En|English,FN|Finnish,Finland|Finnish,Fr|French,F|French,FC|French,France|French,G|German,Germany|German,GR|Greek,It|Italian,Italy|Italian,1|Japanese,J|Japanese,Japan|Japanese,K|Korean,Korea|Korean,Brazil|Portuguese,Es|Spanish,S|Spanish,Spain|Spanish,Sv|Svenska,SW|Swedish,Sweden|Swedish,NTSC-J|Japanese

[Settings]
ResetPlayed=0
SimplifyData=1
AddLanguage=1
WriteLanguage=1
LanguageFromTitle=1
AddRating=1
WriteRating=1
AddYear=1
WriteYear=1
YearFromTitle=1
AddComment=1
WriteComment=1
AddCompany=1
WriteCompany=1
AddGameType=1
WriteGameType=1
AddPlayers=1
WritePlayers=1

[QP system to Ini]
Amstrad CPC=GoodCPC
Atari 2600=Good2600
Atari 5200=Good5200
Atari 7800=Good7800
Atari Lynx=GoodLYNX
Atari Jaguar=GoodJag
Channel F=GoodCHAF
Fairchild Channel F=GoodCHAF
Colecovision=GoodCOL
Coleco Colecovision=GoodCOL
Commodore 64/128=GoodGB64
Commodore 64=GoodGB64
GameBoy=GoodGBx
Nintendo GameBoy=GoodGBx
GameBoy Advance=GoodGBA
Nintendo GameBoy Advance=GoodGBA
Intellivision=GoodINTV
Mattel Intellivision=GoodINTV
MSX=GoodMSX
MSX2=GoodMSX2
Neo Geo Pocket=GoodNGPx
SNK Neo Geo Pocket=GoodNGPx
NES=GoodNES
Nintendo NES=GoodNES
Nintendo 64=GoodN64
Nintendo N64=GoodN64
Nintendo DS=Nintendo DS
Oric=GoodOric
Tangerine Oric=GoodOric
PC Engine\TurboGrafx-16=GoodPCE
NEC PC Engine\TurboGrafx-16=GoodPCE
Sam Coupe=GoodSamC
Sega GameGear=GoodGG
Sega Genesis=GoodGen
Sega Genesis/32X=GoodGen
Sega Master System=GoodSMS
Sega Pico=GoodPico
Super Nintendo=GoodSNES
Nintendo SNES=GoodSNES
Tandy CoCo Colour Computer=GoodCoCO
Tandy TRS-80=GoodCoCO
Thompson MO5=GoodMo5
Tiger Game.com=GoodGCOM
Vectrex=GoodVECT
GCE Vectrex=GoodVECT
Virtual Boy=GoodVBOY
Nintendo Virtual Boy=GoodVBOY
Watara Supervision=GoodSV
WonderSwan=GoodWSx
Bandai WonderSwan=GoodWSx
),%ScriptIni%
Return

;*********************************** Basic ini string functions ************************************
;*********************************** Copyright (c) 2010, Tuncay ************************************
;************************ http://www.autohotkey.com/forum/topic46226.html **************************
































































ini_getValue(ByRef _Content, _Section, _Key, _PreserveSpace = False)
{
    If (_Section = "")
        _Section = (?:\[.*])?
    Else
    {
         _Section = \[\s*?\Q%_Section%\E\s*?]
    }

    RegEx = `aiU)(?:\R|^)\s*%_Section%\s*(?:\R\s*|\R\s*.+\s*=\s*.*?\s*(?=\R)|\R\s*[;#].*?(?=\R))*\R\s*\Q%_Key%\E\s*=(.*)(?=\R|$)

    If RegExMatch(_Content, RegEx, Value)
    {
        If Not _PreserveSpace
        {
            Value1 = %Value1%
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





ini_getKey(ByRef _Content, _Section, _Key)
{
    If (_Section = "")
        _Section = (?:\[.*])?
    Else
         _Section = \[\s*?\Q%_Section%\E\s*?]


    RegEx = `aiU)(?:\R|^)\s*%_Section%\s*(?:\R\s*|\R\s*.+\s*=\s*.*?\s*(?=\R)|\R\s*[;#].*?(?=\R))*\R(\s*\Q%_Key%\E\s*=.*)(?=\R|$)
    If RegExMatch(_Content, RegEx, Value)
        ErrorLevel = 0
    Else
    {
        ErrorLevel = 1
        Value1 =
    }
    Return Value1
}





ini_getSection(ByRef _Content, _Section)
{
    If (_Section = "")
        _Section = (?:\[.*])?
    Else
         _Section = \[\s*?\Q%_Section%\E\s*?]
    RegEx = `aisUS)^.*(%_Section%\s*\R?.*)(?:\R*\s*(?:\[.*?|\R))?$
    If RegExMatch(_Content, RegEx, Value)
        ErrorLevel = 0
    Else
    {
        ErrorLevel = 1
        Value1 =
    }
    Return Value1
}





ini_getAllValues(ByRef _Content, _Section = "", ByRef _count = "")
{
    RegEx = `aisUmS)^(?=.*)(?:\s*\[\s*?.*\s*?]\s*|\s*?.+\s*?=(.*))(?=.*)$
    If (_Section != "")
        Values := RegExReplace(ini_getSection(_Content, _Section), RegEx, "$1`n", Match)
    Else
        Values := RegExReplace(_Content, RegEx, "$1`n", Match)
    If Match
    {
        Values := RegExReplace(Values, "`aS)\R+", "`n")

        Values := RegExReplace(Values, "`aS)\[.*?]\R+|\R+$|\R+ +$", "")
        StringReplace, Values, Values, `n, `n, UseErrorLevel
        _count := ErrorLevel ? ErrorLevel : 0
        StringTrimLeft, Values, Values, 1
        ErrorLevel = 0
    }
    Else
    {
        ErrorLevel = 1
        _count = 0
        Values =
    }
    Return Values
}





ini_getAllKeyNames(ByRef _Content, _Section = "", ByRef _count = "")
{
    RegEx = `aisUmS)^.*(?:\s*\[\s*?.*\s*?]\s*|\s*?(.+)\s*?=.*).*$
    If (_Section != "")
        KeyNames := RegExReplace(ini_getSection(_Content, _Section), RegEx, "$1", Match)
    Else
        KeyNames := RegExReplace(_Content, RegEx, "$1", Match)
    If Match
    {
        KeyNames := RegExReplace(KeyNames, "S)\R+", ",")

        KeyNames := RegExReplace(KeyNames, "S)\[.*?],+|,+$|,+ +", "")
        StringReplace, KeyNames, KeyNames, `,, `,, UseErrorLevel
        _count := ErrorLevel ? ErrorLevel : 0
        StringTrimLeft, KeyNames, KeyNames, 1
        ErrorLevel = 0
    }
    Else
    {
        ErrorLevel = 1
        _count = 0
        KeyNames =
    }
    Return KeyNames
}





ini_getAllSectionNames(ByRef _Content, ByRef _count = "")
{
    RegEx = `aisUmS)^.*(?:\s*\[\s*?(.*)\s*?]\s*|.+=.*).*$
    SectionNames := RegExReplace(_Content, RegEx, "$1", MatchNum)
    If MatchNum
    {
        SectionNames := RegExReplace(SectionNames, "S)\R+", ",", _count)

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











ini_replaceValue(ByRef _Content, _Section, _Key, _Replacement = "", _PreserveSpace = False)
{
    If (_Section = "")
        _Section = (?:\[.*])?
    Else
         _Section = \[\s*?\Q%_Section%\E\s*?]
    If Not _PreserveSpace
    {
        _Replacement = %_Replacement%
        FirstChar := SubStr(_Replacement, 1, 1)
        If (FirstChar = """" AND SubStr(_Replacement, 0, 1)= """"
            OR FirstChar = "'" AND SubStr(_Replacement, 0, 1)= "'")
        {
            StringTrimLeft, _Replacement, _Replacement, 1
            StringTrimRight, _Replacement, _Replacement, 1
        }
    }

    RegEx = `aiU)((?:\R|^)\s*%_Section%\s*(?:\R\s*|\R\s*.+\s*=\s*.*?\s*(?=\R)|\R\s*[;#].*?(?=\R))*\R\s*\Q%_Key%\E\s*=).*((?=\R|$))
    _Content := RegExReplace(_Content, RegEx, "$1" . _Replacement . "$2", isReplaced, 1)
    If isReplaced
        ErrorLevel = 0
    Else
        ErrorLevel = 1
    Return isReplaced
}





ini_replaceKey(ByRef _Content, _Section, _Key, _Replacement = "")
{
    If (_Section = "")
        _Section = (?:\[.*])?
    Else
         _Section = \[\s*?\Q%_Section%\E\s*?]
    If _Replacement !=
    {
        _Replacement = %_Replacement%
        _Replacement = `n%_Replacement%
    }

    RegEx = `aiU)((?:\R|^)\s*%_Section%\s*(?:\R\s*|\R\s*.+\s*=\s*.*?\s*(?=\R)|\R\s*[;#].*?(?=\R))*)\R\s*\Q%_Key%\E\s*=.*((?=\R|$))
    _Content := RegExReplace(_Content, RegEx, "$1" . _Replacement . "$2", isReplaced, 1)
    If isReplaced
        ErrorLevel = 0
    Else
        ErrorLevel = 1
    Return isReplaced
}




ini_replaceSection(ByRef _Content, _Section, _Replacement = "")
{
    If (_Section = "")
        _Section = (?:\[.*])?
    Else
         _Section = \[\s*?\Q%_Section%\E\s*?]
    RegEx = `aisU)^(\s*?.*)%_Section%\s*\R?.*(\R*\s*(?:\[.*|\R))?$
    _Content := RegExReplace(_Content, RegEx, "$1" . _Replacement . "$2", isReplaced, 1)
    If isReplaced
        ErrorLevel = 0
    Else
        ErrorLevel = 1
    Return isReplaced
}











ini_insertValue(ByRef _Content, _Section, _Key, _Value, _PreserveSpace = False)
{
    If (_Section = "")
        _Section = (?:\[.*])?
    Else
         _Section = \[\s*?\Q%_Section%\E\s*?]
    If Not _PreserveSpace
    {
        _Value = %_Value%
        FirstChar := SubStr(_Value, 1, 1)
        If (FirstChar = """" AND SubStr(_Value, 0, 1)= """"
            OR FirstChar = "'" AND SubStr(_Value, 0, 1)= "'")
        {
            StringTrimLeft, _Value, _Value, 1
            StringTrimRight, _Value, _Value, 1
        }
    }

    RegEx = S`aiU)((?:\R|^)\s*%_Section%\s*(?:\R\s*|\R\s*.+\s*=\s*.*?\s*(?=\R)|\R\s*[;#].*?(?=\R))*\R\s*\Q%_Key%\E\s*=.*?)((?=\R|$))
    _Content := RegExReplace(_Content, RegEx, "$1" . _Value . "$2", isInserted, 1)
    If isInserted
        ErrorLevel = 0
    Else
        ErrorLevel = 1
    Return isInserted
}






ini_insertKey(ByRef _Content, _Section, _Key)
{
    StringLeft, K, _Key, % InStr(_Key, "=") - 1
    sectionCopy := ini_getSection(_Content, _Section)
    keyList := ini_getAllKeyNames(sectionCopy)
    isInserted = 0
    If K Not In %keyList%
    {
        sectionCopy .= "`n" . _Key
        isInserted = 1
    }
    If isInserted
    {
        ini_replaceSection(_Content, _Section, sectionCopy)
        ErrorLevel = 0
    }
    Else
    {
        ErrorLevel = 1
    }
    Return isInserted
}




ini_insertSection(ByRef _Content, _Section, _Keys = "")
{
    RegEx = `aisU)^.*\R*\[\s*?\Q%_Section%\E\s*?]\s*\R+.*$
    If Not RegExMatch(_Content, RegEx)
    {
        _Content = %_Content%`n[%_Section%]`n%_Keys%
        isInserted = 1
        ErrorLevel = 0
    }
    Else
    {
        isInserted = 0
        ErrorLevel = 1
    }
    Return isInserted
}

















ini_load(ByRef _Content, _Path = "", _convertNewLine = false)
{
    ini_buildPath(_Path)
    error := true
    Loop, %_Path%, 0, 0
    {
        _Path := A_LoopFileLongPath
        error := false
        Break
    }
    If (error = false)
    {
        FileRead, _Content, %_Path%
        If (ErrorLevel)
        {
            error := true
        }
        Else
        {
            FileGetSize, fileSize, %_Path%
            If (fileSize != StrLen(_Content))
            {
                error := true
            }
        }
    }
    If (error)
    {
        _Content := ""
    }
    Else If (_convertNewLine)
    {
        StringReplace, _Content, _Content, `r`n, `n, All
    }
    ErrorLevel := error
    Return _Path
}






ini_save(ByRef _Content, _Path = "", _convertNewLine = true, _overwrite = true)
{
    ini_buildPath(_Path)
    error := false
    If (_overwrite)
    {
        Loop, %_Path%, 0, 0
        {
            _Path := A_LoopFileLongPath
            Break
        }
        If FileExist(_Path)
        {
            FileDelete, %_Path%
            If (ErrorLevel)
            {
                error := true
            }
        }
    }
    Else If FileExist(_Path)
    {
        error := true
    }
    If (error = false)
    {
        If (_convertNewLine)
        {
            StringReplace, _Content, _Content, `r`n, `n, All
            StringReplace, _Content, _Content, `n, `r`n, All
            FileAppend, %_Content%, %_Path%
        }
        Else
        {
            FileAppend, %_Content%, *%_Path%
        }
        If (ErrorLevel)
        {
            error := true
        }
    }
    ErrorLevel := error
    Return _Path
}


ini_buildPath(ByRef _path)
{

    If (_Path = "")
    {
        _Path := RegExReplace(A_ScriptFullPath, "S)\..*?$") . ".ini"
    }
    Else If (SubStr(_Path, 0, 1) = "\")
    {
        _Path .= RegExReplace(A_ScriptName, "S)\..*?$") . ".ini"
    }
    Else
    {
        If (InStr(FileExist(_Path), "D"))
        {

            _Path .= "\" . RegExReplace(A_ScriptName, "S)\..*?$") . ".ini"
        }
        Else
        {

            SplitPath, _Path,, fileDir, fileExtension, fileNameNoExt
            If (fileDir = "")
            {
                fileDir := A_WorkingDir
            }
            If (fileExtension = "")
            {
                fileExtension := "ini"
            }
            If (fileNameNoExt = "")
            {
                fileNameNoExt := RegExReplace(A_ScriptName, "S)\..*?$")
            }
            _Path := fileDir . "\" . fileNameNoExt . "." . fileExtension
        }
    }
    Return 0
}















ini_repair(_Content, _PreserveSpace = False, _CommentSymbols = ";#", _LineDelim = "`n")
{
    If (_CommentSymbols != "")
    {
        regex = `aiUSm)(?:\R\s*|(s*|\t*))[%_CommentSymbols%].*?(?=\R)
        _Content := RegExReplace(_Content, regex, "$1")
    }
    Loop, Parse, _Content, `n, `r
    {
        If (RegExMatch(A_LoopField, "`aiSm)\[\s*(.+?)\s*]", Match))
        {
            newIni .= _LineDelim . "[" . Match1 . "]"
            section := Match1
            KeyList := ""
        }
        Else If (RegExMatch(A_LoopField, "`aiSm)\s*(\b(?:.+?|\s?)\b)\s*=(.*)", Match))
        {
            If (_PreserveSpace = false)
            {
                Match2 = %Match2%
            }
            If Match1 Not in %KeyList%
            {
                KeyList .= "," . Match1
            }
            Else
            {


                ini_replaceKey(newIni, section, Match1, "")
            }
            newIni .= _LineDelim . Match1 . "=" . Match2
        }
    }
    StringReplace, newIni, newIni, %_LineDelim%
    If (newIni != "")
    {
        ErrorLevel := 0
    }
    Else
    {
        ErrorLevel := 1
    }
    Return newIni
}












ini_mergeKeys(ByRef _Content, ByRef _source, _updateMode = 1)
{
    steps := 0
    laststep := 0
    destSectionNames := ini_getAllSectionNames(_Content), sourceSectionNames := ini_getAllSectionNames(_source)
    Loop, Parse, sourceSectionNames, `,
    {
        sectionName := A_LoopField
        sourceSection := ini_getSection(_source, sectionName)
        If sectionName Not In %destSectionNames%
        {
            _Content .= "`n" . sourceSection
            steps++
            Continue
        }
        Else
        {
            destSection := ini_getSection(_Content, sectionName), destKeyNames := ini_getAllKeyNames(destSection), sourceKeyNames := ini_getAllKeyNames(sourceSection)
            Loop, Parse, sourceKeyNames, `,
            {
                keyName := A_LoopField
                If keyName Not In %destKeyNames%
                {
                    destSection .= "`n" . ini_getKey(sourceSection, sectionName, keyName)
                    steps++
                    Continue
                }
                Else If (_updateMode = 1)
                {
                    ini_replaceValue(destSection, sectionName, keyName, ini_getValue(sourceSection, sectionName, keyName))
                    steps++
                }
                Else If (_updateMode = 2)
                {
                    ini_replaceValue(destSection, sectionName, keyName, ini_getValue(destSection, sectionName, keyName) . ini_getValue(sourceSection, sectionName, keyName))
                    steps++
                }
                Else If (_updateMode = 3)
                {
                    If ((sourceValue := ini_getValue(sourceSection, sectionName, keyName)) > ini_getValue(destSection, sectionName, keyName))
                    {
                        ini_replaceValue(destSection, sectionName, keyName, sourceValue)
                        steps++
                    }
                }
                Else If (_updateMode = 4)
                {
                    ini_replaceKey(destSection, sectionName, keyName, "")
                    steps++
                }
            }
            If (laststep != steps)
            {
                laststep := steps
                ini_replaceSection(_Content, sectionName, destSection)
            }
        }
    }
    If (steps > 0)
    {
        ErrorLevel := 0
    }
    Else
    {
        ErrorLevel := 1
    }
    Return steps
}




















ini_exportToGlobals(ByRef _Content, _CreateIndexVars = false, _Prefix = "ini", _Seperator = "_", _SectionSpaces = "", _PreserveSpace = False)
{
    Global
    Local secCount := 0, keyCount := 0, i := 0, Section, Section1, currSection, Pair, Pair1, Pair2, FirstChar
    If (_Prefix != "")
    {
        _Prefix .= _Seperator
    }
    Loop, Parse, _Content, `n, `r
    {
        If (Not RegExMatch(A_LoopField, "`aiSm)\[\s*(.+?)\s*]", Section))
        {
            If (RegExMatch(A_LoopField, "`aiSm)\s*(\b(?:.+?|\s?)\b)\s*=(.*)", Pair))
            {
                If (!_PreserveSpace)
                {
                    StringReplace, Pair1, Pair1, %A_Space%, , All
                    Pair2 = %Pair2%
                    FirstChar := SubStr(Pair2, 1, 1)
                    If (FirstChar = """" AND SubStr(Pair2, 0, 1)= """"
                        OR FirstChar = "'" AND SubStr(Pair2, 0, 1)= "'")
                    {
                        StringTrimLeft, Pair2, Pair2, 1
                        StringTrimRight, Pair2, Pair2, 1
                    }
                }
                StringReplace, currSection, currSection, %A_Space%, %_SectionSpaces%, All
                %_Prefix%%currSection%%_Seperator%%Pair1% := Pair2
                keyCount++
                If (_CreateIndexVars)
                {
                    %_Prefix%%currSection%0++
                    i := %_Prefix%%currSection%0
                    %_Prefix%%currSection%%i% := Pair1
                }
            }
        }
        Else
        {
            currSection := Section1
            If (_CreateIndexVars)
            {
                StringReplace, currSection, currSection, %A_Space%, %_SectionSpaces%, All
                secCount++
                %_Prefix%%secCount% := currSection
            }
        }
    }
    If (_CreateIndexVars)
    {
        %_Prefix%0 := secCount
    }
    If (secCount = 0 AND keyCount = 0)
    {
        ErrorLevel = 1
    }
    Else
    {
        ErrorLevel = 0
    }
    Return keyCount
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








Ini_Write(_Value, ByRef _Content, _Section, _Key)
{
    If (_Section = "")
    {
        ErrorLevel = 1
    }
    Else
    {
        ini_replaceValue(_Content, _Section, _Key, _Value)
    }
    Return
}








Ini_Delete(ByRef _Content, _Section, _Key = "")
{
    If (_Section = "")
    {
        ErrorLevel = 1
    }
    Else
    {
        If (_Key != "")
        {
            ini_replaceKey(_Content, _Section, _Key, "")
        }
        Else
        {
            ini_replaceSection(_Content, _Section, "")
        }
    }
    Return
}
; #Include C:\Program Files (x86)\AutoHotkey\Lib\ini_Tuncay.ahk




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

globalsFromSection(FileContent, Section)
{
 Global
 Local CurrentPrefix, CurrentVarName, CurrentVarContent, DelimPos, SectionFound
 SectionFound =
 Loop, Parse, FileContent, `n, `r%A_Tab%%A_Space%
 {
  If A_LoopField Is Not Space
  {
   If (SectionFound = 1)
   {
    DelimPos := InStr(A_LoopField, "=")
    If DelimPos = 0
       Break
    StringLeft, CurrentVarName, A_LoopField, % DelimPos - 1
    StringTrimLeft, CurrentVarContent, A_LoopField, %DelimPos%
    %CurrentVarName% = %CurrentVarContent%
   }
   Else
   {
    If (A_LoopField = "[" Section "]")
       SectionFound = 1
   }
  }
 }
}

getAllSectionNames(ByRef _Content, ByRef _count = "")
{
    StringReplace, SectionNames, _Content, `, , ¬, A
    RegEx = `aisUmS)^.*(?:\s*\[\s*?(.*)\s*?]\s*|.+=.*).*$
    SectionNames := RegExReplace(SectionNames, RegEx, "$1", MatchNum)
    If MatchNum
    {
        SectionNames := RegExReplace(SectionNames, "S)\R+", ",", _count)

        SectionNames := RegExReplace(SectionNames, "S),+ +", "")
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
