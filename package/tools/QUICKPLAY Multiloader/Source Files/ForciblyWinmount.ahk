; Forcibly unmount ahk script for QuickPlay v1.0 - butter100fly 082012
#NoEnv
#SingleInstance force
#NoTrayIcon
DetectHiddenWindows, on
setWinDelay, 0
IfWinExist, Prompt
{
	winhide
	WinActivate
	ControlClick, Button1
}
SetTitleMatchMode, 1
IfWinExist, Quickplay - Phoenix
{
	Winactivate
}
ExitApp
