; Forcibly unmount ahk script v1.0 for QuickPlay
;  this script itself doesn't get run, it is comiled to executable and
;  the exe gets called
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
