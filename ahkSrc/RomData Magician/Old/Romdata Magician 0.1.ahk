#NoEnv
#SingleInstance Force
SetWorkingDir, %A_ScriptDir%
;SetTitleMatchMode, 2
InitializeVars() 
CreateGUIs()
Return

InitializeVars()
{
 Global
 ScriptName = RomData Magician
 ScriptIni = RomData Magician.ini
 IniRead, QPFolder, %ScriptIni%, General, QPath, Error
 If QPFolder = Error
 {
  Loop,
  {
   FileSelectFolder, QPFolder, *%QPFolder%, 0, Browse to your QuickPlay Folder.
   IfNotExist %QPFolder%\Efind
     MsgBox, Unable to verify Quick Play folder location`n Press {CTRL} Q to exit.
   Else Break
  }
  IniWrite, %QPFolder%, %ScriptIni%, General, QPath
 }
 ; Get List of Romdata Folders
 Glob(list, QPfolder . "\data\*\RomData.dat")
 Loop, Parse, List, `n
 {
  Pos := InStr(A_LoopField, "\", "", 0) + 1
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
 IllegalChars = .,<>:;'"/|\(){}=-+!`%^&*~
 IllegalChars .= A_Space
 FileRead, EmulatorsIni, %QPFolder%\dats\emulators.ini
 Sections := ini_getAllSectionNames(EmulatorsIni)
 Loop, Parse, Sections, `,
 {
  Emulator := A_LoopField
  Ini_Read(System, EmulatorsIni, Emulator, "system")
  If System <> ERROR
  {
   Loop, Parse, IllegalChars
     StringReplace, Emulator, Emulator, %A_LoopField%,, A
   %Emulator% := System
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
 IniRead, SelectedLanguage, %ScriptIni%, General, PreferredLanguage, English
 IniRead, Languages, %ScriptIni%, General, Languages
 Loop, Parse, Languages, `,
 {
  Region0 := A_Index
  StringSplit, TempVar, A_LoopField, |
  Region%A_Index% := TempVar1
  LanguageOptions .= TempVar2 "|"
  Language%A_Index% := TempVar2
 }
 Sort, LanguageOptions, U D|
 StringReplace, LanguageOptions, LanguageOptions, %SelectedLanguage%, %SelectedLanguage%|
 RomDataOptions := "Language,Rating,Year,Comment,Company,GameType,Players"
 CommentOptions := "Controls|Perspective|Systems|ESRB"
 StringSplit, CommentOptions, CommentOptions, |
}

CreateGUIs()
{
 Global
 ListViewWidth := A_ScreenWidth-5
 ListViewHeight := A_ScreenHeight-380
 Gui, 1:Default ; Main Gui
 Gui, +OwnDialogs
 Gui, Add, ListView, x2 y10 w%ListViewWidth% h%ListViewHeight% vQuickPlayLV, Rom Name|Ini Name|Emulator|System|Game Type|Played|Language|Rating|Year|Comment|Company|Players
 ColWidth = 300,200,200,90,90,50,70,70,70,150,150,100
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
 Gui, Add, DropDownList, x270 yp-3 w100 vSelectedLanguage gSaveLanguage, %LanguageOptions%
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
 Gui, Add, DropDownList, x30 yp+25 w200 vSelectedFolder gLoadRomData, %FolderList%
 Gui, Add, Button, x270 ys+215 h30 w100, Preview
 Gui, Add, Button, x270 yP+40 h30 w100, Save
 Gui, Add, StatusBar, x30 w324
 Gosub, LoadRomData
 Gui, Show, Maximize, %ScriptName%
}


/*
6-Pak (USA)¬6-Pak¬¬¬D:\Emulators\Sega Genesis\Roms\6-Pak (USA).zip¬Gens+¬¬¬Unknown¬¬¬¬¬0¬0¬<IPS>¬</IPS>¬¬¬
     1      2        3        4      5        6       7       8     9     10      11     12
Rom Name|Ini Name|Emulator|System|Game Type|Played|Language|Rating|Year|Comment|Company|Players
1  RomString := _Name + '¬'; (1)
2  RomString := RomString + _MAMEname + '¬'; needs added (2)
3  RomString := RomString + _ParentName + '¬'; needs added
4  RomString := RomString + _ZipName + '¬'; needs added
5  RomString := RomString + _path + '¬';
6  RomString := RomString + _emulator + '¬'; 
7  RomString := RomString + _Company + '¬'; needs added (11)
8  RomString := RomString + _Year + '¬'; needs added (9)
9  RomString := RomString + _GameType + '¬'; (5)
10 RomString := RomString + _Rating + '¬'; needs added (8)
11 RomString := RomString + _Language + '¬'; needs added (7)
12 RomString := RomString + _Parameters + '¬'; needs added
13 RomString := RomString + Comment + '¬'; needs added (10)
14 RomString := RomString + IntToStr(_NumPlay) + '¬'; (6)
15 RomString := RomString + IntToStr(Integer(_ParamMode)) + '¬';
16 RomString := RomString + '<IPS;' + '¬';
?? RomString := RomString + '</IPS;';
?? RomString := RomString + '¬' + _Multiplayer := SplitList[IPSpos + 1]; (12)
?? RomString := RomString + '¬' + _DefaultGoodMerge := SplitList[IPSPos + 2]
*/

ButtonSave:
 NewRomData =
 RowNumber = 0
 LV_ModifyCol(4, "Sort")
 Loop, Parse, RomDataDat, `n, `r
 {
  LoopField := A_LoopField
  If LoopField Not Contains [bios],%A_Space%bios%A_Space%
  {
   IfInString, LoopField , ¬
   {
    RowNumber++
    POS := RegexMatch(LoopField, "<IPS>.*</IPS>", IPS)
    StringSplit, OldData, LoopField, ¬
    LV_GetText(_Name, RowNumber, 1)
    If OldData1 <> %_Name%
    {
     MsgBox, Out of sync. Unable to save.
     Return
    }
    LoopField =
    OldData0--
    LV_GetText(_MAMEname, RowNumber, 2)
    LV_GetText(_GameType, RowNumber, 5)
    LV_GetText(_NumPlay, RowNumber, 6)
    LV_GetText(_Language, RowNumber, 7)
    LV_GetText(_Rating, RowNumber, 8)
    LV_GetText(_Year, RowNumber, 9)
    LV_GetText(_Comment, RowNumber, 10)
    LV_GetText(_Company, RowNumber, 11)
    LV_GetText(_Multiplayer, RowNumber, 12)
    LoopField .= _Name "¬" 
    . _MAMEname "¬"
    . OldData3 "¬"
    . OldData4 "¬"
    . OldData5 "¬"
    . OldData6 "¬"
    . _Company "¬"
    . _Year "¬"
    . _GameType "¬"
    . _Rating "¬"
    . _Language "¬"
    . OldData12 "¬"
    . _Comment "¬"
    . _NumPlay "¬"
    . OldData15 "¬"
    . IPS "¬"
    . _Multiplayer "¬"
    . OldData%OldData0% "¬"
   }
  }
  NewRomData .= LoopField "`n"
 }
FileDelete, TestRomdata.dat
FileAppend, %NewRomData%, TestRomdata.dat
MsgBox, Done

Return

GuiClose:
 MsgBox, 4,, Exit %ScriptName%?
 IfMsgBox Yes
   ExitApp
Return

^Q::ExitApp
^R::Reload

SaveLanguage:
 GuiControlGet, SelectedLanguage
 IniWrite, %SelectedLanguage%, %ScriptIni%, General, PreferredLanguage
Return

AllNone:
 Gui, Submit, NoHide
 Value := %A_GuiControl%
 Loop, Parse, RomDataOptions, `,
    GuiControl,, %A_GuiControl%%A_LoopField%, %Value%
Return

ButtonPreview:
 Gui, Submit, NoHide
 Gui, ListView, QuickPlayLV
 GuiControl, -Redraw, QuickPlayLV
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
;     1      2        3        4      5        6       7       8     9     10      11     12
;Rom Name|Ini Name|Emulator|System|Game Type|Played|Language|Rating|Year|Comment|Company|Players

 Loop % LV_GetCount()
 {
  RowNumber := A_Index
  LV_GetText(FullTitle, RowNumber, 1)
  Title := RegExReplace(FullTitle, "[({[].+?[)}\]]")
  Title = %Title%
  LV_Modify(RowNumber, "Col2", Title)
  Section := Varize(Title)
  LV_GetText(System, RowNumber, 4)
  If System <> %PrevSystem%
  {
   SB_SetText("   Reading Data For " . System)
   IniRead, IniFile, %ScriptIni%, QP system to Ini, %system%
   FileRead, FileContent, %QPFolder%\dats\System Ini Files\%IniFile%.ini
   IniFileExists := ErrorLevel
   globalsFromIni(FileContent, IniFile)
   PrevSystem := System
  }
  SB_SetText("   Current Title:  " . FullTitle)

  If ResetPlayed = 1
     LV_Modify(RowNumber, "Col6", "0")
     
  If AddLanguage = 1
  {
   If WriteLanguage = 1
      LV_Modify(RowNumber, "Col7", "")
   LV_GetText(TempVar, RowNumber, 7)
   If (TempVar = "") OR (WriteLanguage = 1)
   {
    NewLanguage := "English"
    Loop, %Region0%
    {
     StringReplace, FullTitle, FullTitle, (, ¬, A
     StringReplace, FullTitle, FullTitle, ), ¬, A
     StringReplace, FullTitle, FullTitle, `,, ¬, A
     StringReplace, FullTitle, FullTitle, %A_Space%,, A
     IfInString, FullTitle, % "¬" . Region%A_Index% . "¬"
     {
      CurrentLanguage := Language%A_Index%
      If NewLanguage = English
         NewLanguage := CurrentLanguage
      If CurrentLanguage = %SelectedLanguage%
      {
       NewLanguage := CurrentLanguage
       Break
      }
     }
    }
    LV_Modify(RowNumber, "Col7", NewLanguage)  
   }
  }
  If IniFileExists = 1
     Continue
     
  If AddComment = 1
  {
   If WriteComment = 1
      LV_Modify(RowNumber, "Col10", "")
   LV_GetText(TempVar, RowNumber, 10)
   If (TempVar = "") OR (WriteComment = 1)
   {
    NewComment := Section . "_" . CommentOptions%SelectedOption%
    NewComment := %NewComment%
    StringReplace, NewComment, NewComment, |, %A_Space%/%A_Space%, A
    LV_Modify(RowNumber, "Col10", NewComment) 
   }
  }

  If AddGameType = 1
  {
   If WriteGameType = 1
      LV_Modify(RowNumber, "Col5", "")
   LV_GetText(TempVar, RowNumber, 5)
   If (TempVar = "") OR (WriteGameType = 1)
   {
    NewGameType = %Section%_Genre
    LV_Modify(RowNumber, "Col5", %NewGameType%)
   }   
  }

  If AddRating = 1
  {
   If WriteRating = 1
      LV_Modify(RowNumber, "Col8", "")
   LV_GetText(TempVar, RowNumber, 8)
   If (TempVar = "") OR (WriteRating <> 0)
   {
    NewRating = %Section%_Score
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
        LV_Modify(RowNumber, "Col8", NewRating)
    }
   }
  }

  If AddYear = 1
  {
   If WriteYear = 1
      LV_Modify(RowNumber, "Col9", "")
   LV_GetText(TempVar, RowNumber, 9)
   If (TempVar = "") OR (WriteYear = 1)
   {
    NewYear = %Section%_Released
    LV_Modify(RowNumber, "Col9", %NewYear%)
   }   
  }

  If AddCompany = 1
  {
   If WriteCompany = 1
      LV_Modify(RowNumber, "Col11", "")
   LV_GetText(TempVar, RowNumber, 11)
   If (TempVar = "") OR (WriteCompany = 1)
   {
    NewCompany = %Section%_Publisher
    LV_Modify(RowNumber, "Col11", %NewCompany%)
   }     
  }

  If AddPlayers = 1
  {
   If WritePlayers = 1
      LV_Modify(RowNumber, "Col12", "")
   LV_GetText(TempVar, RowNumber, 12)
   If (TempVar = "") OR (WritePlayers = 1)
   {
    NewPlayers = %Section%_Players
    LV_Modify(RowNumber, "Col12", %NewPlayers%)
   }
  }
 }

 If SelectedRating = 3
 LV_ModifyCol(8,"Float")
 Else
    LV_ModifyCol(8,"Text Left")
 GuiControl, +Redraw, QuickPlayLV
 SB_SetText("   Operation Completed.")
 SoundPlay, *64
Return

LoadRomData:
 Gui, Submit, NoHide
 Gui, ListView, QuickPlayLV
 GuiControl, -Redraw, QuickPlayLV
 LV_Delete()
 FileRead, RomDataDat, %QPfolder%\data\%SelectedFolder%\Romdata.dat
 PrevData6 = 
 Loop, Parse, RomDataDat, `n, `r
 {
  If A_Index > 1
  {
   StringSplit, Data, A_LoopField, ¬
   If Data1 Not Contains [bios],%A_Space%bios%A_Space%
   {
    If Data6 <> %PrevData6%
    {
     PrevData6 := Data6
     Loop, Parse, IllegalChars
       StringReplace, Data6, Data6, %A_LoopField%,, A
     System := %Data6%
    }
    Index = 17
    While Index < 21
    {
     If Data%Index% = </IPS>
        Break
     Index++
    }
    Index++
    LV_Add("",Data1,"",Data6,System,Data9,Data14,Data11,Data10,Data8,Data13,Data7,Data%Index%)
   }
  }
 }
 GuiControl, +Redraw, QuickPlayLV
Return

;********************************** Get list of Romdata Folders ************************************

Glob(ByRef list, Pattern, IncludeDirs=0)
{
    if (i:=RegExMatch(Pattern,"[*?]")) && (i:=InStr(Pattern,"\",1,i+1))
        Loop, % SubStr(Pattern, 1, i-1), 2
            Glob(list, A_LoopFileLongPath . SubStr(Pattern,i), IncludeDirs)
    else
        Loop, %Pattern%, %IncludeDirs%
            list .= (list="" ? "" : "`n") . A_LoopFileDir
}

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

;***************************************** Ini Functions *******************************************

Varize(Name)
{
 Name = %Name%
 SetFormat, Integer, hex
 Loop, Parse, Name,
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

;***************************************************************************************************
/*
Title: Basic ini string functions
    Operate on variables instead of files. An easy to use ini parser.
    
About: License
    New BSD License

Copyright (c) 2010, Tuncay
All rights reserved.

http://www.autohotkey.com/forum/topic46226.html
*/

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
                MsgBox, %CurrentPrefix%%_VarPrefixDelim%%CurrentVarName% = %CurrentVarContent%
            }
        }
    }
}