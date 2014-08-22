#NoEnv
#SingleInstance Force
SetWorkingDir, %A_ScriptDir%
;SetTitleMatchMode, 2
InitializeVars() 
CreateGUIs()
Gosub, SRLV_Load
Gui, Show, Maximize, %ScriptName%
Gosub, LoadRomData
;Gosub, ButtonPreview
Return

InitializeVars()
{
 Global
 ScriptName = RomData Magician
 ScriptIni = RomData Magician.ini
 FileRead, ScriptIniContent, %ScriptIni%
 GlobalsFromSection(ScriptIniContent, "Settings")
 IllegalChars := ".,<>:;'""/|\(){}=-+!``%^&*~ "
 IfNotExist, %ScriptIni%
   Gosub, CreateIni
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
; Process, Priority,, High
; StartTime := A_TickCount
 IniRead, SystemIniFilePath, %ScriptIni%, General, SystemIniFilePath, Error
 If (SystemIniFilePath = "Error") OR (SystemIniFilePath = "")
    Gosub, GetIniFilePath
 Glob(IniPaths, SystemIniFilePath . "\*\*.ini", 0,1)
 FileRead, emulatorsini, %QPFolder%\dats\emulators.ini
 FileRead, QPSystem, %Scriptini%
 SystemNames := ini_getAllSectionNames(emulatorsini)


; Process, Priority,, Normal
; ElapsedTime := (A_TickCount - StartTime)/1000
; dt = 20000101000000
; dt += ElapsedTime, seconds
; FormatTime, ElapsedTime, %dt%, H:mm:ss
 
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
  FileSelectFolder, SystemIniFilePath, *%SystemIniFilePath%, 0, Browse to your System Ini Files
  IniWrite, %SystemIniFilePath%, %ScriptIni%, General, SystemIniFilePath
Return

CreateGUIs()
{
 Global
 ListViewWidth := A_ScreenWidth-5
 ListViewHeight := A_ScreenHeight-380
 Gui, 1:Default ; Main Gui
 Gui, +OwnDialogs

;  300   200        0        0      0     200      150     70     90      70      70         0        150     50          0       0    0   0    0     0     100           0           0
;   1     2         3        4      5      6       7       8      9       10      11         12       13      14         15      16   17   18   19    20     21           22          23
; Name|Ini Name|ParentName|ZipName|path|Emulator|Company|Year|Game Type|Rating|Language|Parameters|Comment|NumPlayed|ParamMode|<IPS>|IPS1|IPS2|IPS3|</IPS>|Players|DefaultGoodMerge|System
                                                       
 Gui, Add, ListView, x2 y10 w%ListViewWidth% h%ListViewHeight% vQuickPlayLV
 , Name|Ini Name|ParentName|ZipName|path|Emulator|Company|Year|Game Type|Rating|Language|Parameters|Comment|Played|ParamMode|<IPS>|IPS1|IPS2|IPS3|</IPS>|Players|DefaultGoodMerge|System|LookUpName|LookUpSystem
 ColWidth =   300,0,0,0,0,200,150,70,90,70,70,0,150,50,0,0,0,0,0,0,100,0,0,230,70
 Loop, Parse, ColWidth, `,
       Lv_ModifyCol(A_Index,A_LoopField)
 Gui, Font, Bold
 Gui, Add, GroupBox, x2 y+10 w385 h305 Section, RomData Options
 Gui, Font, Norm
 Gui, Add, CheckBox, x30 yp+25 vAdd gAllNone, Select all/none
 Gui, Add, CheckBox, Check3 x150 yp vWrite gAllNone, Select all/none
 Gui, Add, CheckBox, x270 yp vResetPlayed Checked%ResetPlayed%, Reset Played to 0
 Gui, Add, CheckBox, x30 yp+35 vAddLanguage Checked%AddLanguage%, Add Language
 Gui, Add, CheckBox, Check3 x150 yp vWriteLanguage Checked%WriteLanguage%, Over Write?
 Gui, Add, CheckBox, x270 yp-15 vSimplifyData Checked%SimplifyData%, Simplify Data
 Gui, Add, CheckBox, x30 yp+40 vAddYear Checked%AddYear%, Add Year
 Gui, Add, CheckBox, Check3 x150 yp vWriteYear Checked%WriteYear%, Over Write?
 Gui, Add, CheckBox, x270 yp vYearFromTitle Checked%YearFromTitle%, Missing From Title?
 Gui, Add, CheckBox, x30 yp+25 vAddRating Checked%AddRating%, Add Rating
 Gui, Add, CheckBox, Check3 x150 yp vWriteRating Checked%WriteRating%, Over Write?
 Gui, Add, DropDownList, x270 yp-3 w100 AltSubmit vSelectedRating, %DD_ratings%
 Gui, Add, CheckBox, x30 yp+25 vAddComment Checked%AddComment%, Add Comment
 Gui, Add, CheckBox, Check3 x150 yp vWriteComment Checked%WriteComment%, Over Write?
 Gui, Add, DropDownList, x270 yp-3 w100 AltSubmit vSelectedOption, Control Type||Perspective|Other Systems|ESRB
 Gui, Add, CheckBox, x30 yp+28 vAddCompany Checked%AddCompany%, Add Company
 Gui, Add, CheckBox, Check3 x150 yp vWriteCompany Checked%WriteCompany%, Over Write?
 Gui, Add, CheckBox, x30 yp+25 vAddGameType Checked%AddGameType%, Add Game Type
 Gui, Add, CheckBox, Check3 x150 yp vWriteGameType Checked%WriteGameType%, Over Write?
 Gui, Add, CheckBox, x30 yp+25 vAddPlayers Checked%AddPlayers%, Add Player Info
 Gui, Add, CheckBox, Check3 x150 yp vWritePlayers Checked%WritePlayers%, Over Write?
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
 Menu, FileMenu, Add, Ini Files Folder, GetIniFilePath
 Menu, MyMenuBar, Add, &File, :FileMenu
 Menu, CreditsMenu, Add, Credits, ShowCredits
 Menu, MyMenuBar, Add, About, :CreditsMenu
 Gui, Menu, MyMenuBar
 ;Credits
 WinH = 48          ; Height of GUI
 YPos := WinH   ; Bottom of GUI Window
 CreditsText =
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
 MsgBox, 8196,, Exit %ScriptName%?
 IfMsgBox Yes
   ExitApp
Return

;#IfWinActive, RomData Magician
 ^Q::ExitApp 
 ^R::Reload
;#IfWinActive 

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
 Gui, Submit, NoHide
 Keys := ini_getAllKeyNames(ScriptIniContent, "Settings")
 Loop, Parse, Keys, `,
 {
  Value := %A_LoopField%
  IniWrite, %Value%, %ScriptIni%, Settings, %A_LoopField%
 }
Return

;************************************ Preview Selected Options *************************************

ButtonPreview:
 Gui, Submit, NoHide
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
; Name|Ini Name|ParentName|ZipName|path|Emulator|Company|Year|Game Type|Rating|Language|Parameters|Comment|NumPlayed|ParamMode|<IPS>|IPS1|IPS2|IPS3|</IPS>|Players|DefaultGoodMerge|System

 Gui, ListView, QuickPlayLV
; GuiControl, -Redraw, QuickPlayLV
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
    CommentType := CommentOptions%SelectedOption%
    NewComment = %vSystem%_%Section%_%CommentType%  ;%CurrentPrefix%%_VarPrefixDelim%%CurrentVarName% = %CurrentVarContent%
    NewComment := %NewComment%
    If (SimplifyData = 1) AND (NewComment <> "")
    {
     NewComment := Varize(NewComment)
     TempVar = %CommentType%_%NewComment% ;%CurrentList%_%LoopField% := Var (ESRB_ao=Adults Only)
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
    NewCompany = %vSystem%_%Section%_Publisher
    NewCompany := %NewCompany%
    If (SimplifyData = 1) AND (NewCompany <> "")
    {
     NewCompany := Varize(NewCompany)
     TempVar = Publisher_%NewCompany%
     NewCompany := %TempVar%   
    }
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
; Name|Ini Name|ParentName|ZipName|path|Emulator|Company|Year|Game Type|Rating|Language|Parameters|Comment|NumPlayed|ParamMode|<IPS>|IPS1|IPS2|IPS3|</IPS>|Players|DefaultGoodMerge|System

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
  ;%Emulator% := System  (Ini File Name)
  Emulator := Data6
  vEmulator := Varize(Emulator)
  If %vEmulator% =
  {
   SB_SetText("   Finding Ini File Path For " . Emulator)
   Ini_Read(System, emulatorsini, Emulator, "system")
   Ini_Read(GoodName, QpSystem, "QP system to Ini", System)
   If (System <> "ERROR") AND (System <> "")
   {
    %vEmulator% := System
    vSystem := Varize(System)
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
;   MsgBox, 0, %ScriptName%, %Data1%`n%TempVar%
      LookUpName := RegExReplace(Data1, "[({[].+?[)}\]]")
   LookUpName = %LookUpName%
  }

  LV_Add("",Data1,Data2,Data3,Data4,Data5,Data6,Data7,Data8,Data9,Data10,Data11,Data12,Data13
          ,Data14,Data15, "<IPS>", "", "", "", "</IPS>", Data21, Data22, Data23, LookupName, System)
  
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
; Name|Ini Name|ParentName|ZipName|path|Emulator|Company|Year|Game Type|Rating|Language|Parameters|Comment|NumPlayed|ParamMode|<IPS>|IPS1|IPS2|IPS3|</IPS>|Players|DefaultGoodMerge|System

ButtonSave:
 Gui, Submit, NoHide
 
 Gui, ListView, QuickPlayLV
; LV_ModifyCol(4, "Sort")
 NewRomData := ROMDataFileVersion "`n"
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
   LV_GetText(Text, RowNumber, A_Index+16) ;Does <IPS> and </IPS> need to be Added?
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
Languages=C|Chinese,HK|Chinese,China|Chinese,H|Dutch,NL|Dutch,Dutch|Dutch,Netherlands|Dutch,En|English,FN|Finnish,Finland|Finnish,Fr|French,F|French,FC|French,France|French,G|German,Germany|German,GR|Greek,It|Italian,Italy|Italian,1|Japanese,J|Japanese,Japan|Japanese,K|Korean,Korea|Korean,Brazil|Portuguese,Es|Spanish,S|Spanish,Spain|Spanish,Sv|Svenska,SW|Swedish,Sweden|Swedish

[Settings]
YearFromTitle=0
ResetPlayed=0
SimplifyData=0
AddLanguage=0
WriteLanguage=0
AddRating=0
WriteRating=0
AddYear=0
WriteYear=0
AddComment=0
WriteComment=0
AddCompany=0
WriteCompany=0
AddGameType=0
WriteGameType=0
AddPlayers=0
WritePlayers=0

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

#Include C:\Program Files (x86)\AutoHotkey\Lib\ini_Tuncay.ahk

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
        ; Workaround, whitespaces only should be eliminated.
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