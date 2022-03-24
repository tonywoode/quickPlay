// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclshell.pas' rev: 10.00

#ifndef JclshellHPP
#define JclshellHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Shlobj.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclwin32.hpp>	// Pascal unit
#include <Jclsysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclshell
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TSHDeleteOption { doSilent, doAllowUndo, doFilesOnly };
#pragma option pop

typedef Set<TSHDeleteOption, doSilent, doFilesOnly>  TSHDeleteOptions;

#pragma option push -b-
enum TSHRenameOption { roSilent, roRenameOnCollision };
#pragma option pop

typedef Set<TSHRenameOption, roSilent, roRenameOnCollision>  TSHRenameOptions;

#pragma option push -b-
enum TSHCopyOption { coSilent, coAllowUndo, coFilesOnly, coNoConfirmation };
#pragma option pop

typedef Set<TSHCopyOption, coSilent, coNoConfirmation>  TSHCopyOptions;

#pragma option push -b-
enum TSHMoveOption { moSilent, moAllowUndo, moFilesOnly, moNoConfirmation };
#pragma option pop

typedef Set<TSHMoveOption, moSilent, moNoConfirmation>  TSHMoveOptions;

#pragma option push -b-
enum TEnumFolderFlag { efFolders, efNonFolders, efIncludeHidden };
#pragma option pop

typedef Set<TEnumFolderFlag, efFolders, efIncludeHidden>  TEnumFolderFlags;

struct TEnumFolderRec
{
	
public:
	AnsiString DisplayName;
	unsigned Attributes;
	HICON IconLarge;
	HICON IconSmall;
	_ITEMIDLIST *Item;
	_di_IEnumIDList EnumIdList;
	_di_IShellFolder Folder;
} ;

struct TShellLink;
typedef TShellLink *PShellLink;

struct TShellLink
{
	
public:
	AnsiString Arguments;
	int ShowCmd;
	AnsiString WorkingDirectory;
	_ITEMIDLIST *IdList;
	AnsiString Target;
	AnsiString Description;
	AnsiString IconLocation;
	int IconIndex;
	Word HotKey;
} ;

#pragma option push -b-
enum TJclFileExeType { etError, etMsDos, etWin16, etWin32Gui, etWin32Con };
#pragma option pop

typedef int INSTALLSTATE;

//-- var, const, procedure ---------------------------------------------------
#define MSILIB "msi.dll"
#define GetShortcutTargetName "MsiGetShortcutTargetA"
#define GetComponentPathName "MsiGetComponentPathA"
extern PACKAGE unsigned RtdlMsiLibHandle;
extern PACKAGE unsigned __stdcall (*RtdlMsiGetShortcutTarget)(char * szShortcutPath, char * szProductCode, char * szFeatureId, char * szComponentCode);
extern PACKAGE int __stdcall (*RtdlMsiGetComponentPath)(char * szProduct, char * szComponent, char * lpPathBuf, PDWORD pcchBuf);
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE bool __fastcall SHDeleteFiles(unsigned Parent, const AnsiString Files, TSHDeleteOptions Options);
extern PACKAGE bool __fastcall SHDeleteFolder(unsigned Parent, const AnsiString Folder, TSHDeleteOptions Options);
extern PACKAGE bool __fastcall SHRenameFile(const AnsiString Src, const AnsiString Dest, TSHRenameOptions Options);
extern PACKAGE bool __fastcall SHCopy(unsigned Parent, const AnsiString Src, const AnsiString Dest, TSHCopyOptions Options);
extern PACKAGE bool __fastcall SHMove(unsigned Parent, const AnsiString Src, const AnsiString Dest, TSHMoveOptions Options);
extern PACKAGE void __fastcall SHEnumFolderClose(TEnumFolderRec &F);
extern PACKAGE bool __fastcall SHEnumFolderNext(TEnumFolderRec &F);
extern PACKAGE bool __fastcall SHEnumSpecialFolderFirst(unsigned SpecialFolder, TEnumFolderFlags Flags, TEnumFolderRec &F);
extern PACKAGE bool __fastcall SHEnumFolderFirst(const AnsiString Folder, TEnumFolderFlags Flags, TEnumFolderRec &F);
extern PACKAGE AnsiString __fastcall GetSpecialFolderLocation(const int FolderID);
extern PACKAGE bool __fastcall DisplayPropDialog(const unsigned Handle, const AnsiString FileName)/* overload */;
extern PACKAGE bool __fastcall DisplayPropDialog(const unsigned Handle, Shlobj::PItemIDList Item)/* overload */;
extern PACKAGE bool __fastcall DisplayContextMenuPidl(const unsigned Handle, const _di_IShellFolder Folder, Shlobj::PItemIDList Item, const Types::TPoint &Pos);
extern PACKAGE bool __fastcall DisplayContextMenu(const unsigned Handle, const AnsiString FileName, const Types::TPoint &Pos);
extern PACKAGE bool __fastcall OpenFolder(const AnsiString Path, unsigned Parent = (unsigned)(0x0), bool Explore = false);
extern PACKAGE bool __fastcall OpenSpecialFolder(int FolderID, unsigned Parent = (unsigned)(0x0), bool Explore = false);
extern PACKAGE bool __fastcall SHAllocMem(/* out */ void * &P, int Count);
extern PACKAGE bool __fastcall SHFreeMem(void * &P);
extern PACKAGE bool __fastcall SHGetMem(void * &P, int Count);
extern PACKAGE bool __fastcall SHReallocMem(void * &P, int Count);
extern PACKAGE Shlobj::PItemIDList __fastcall DriveToPidlBind(const AnsiString DriveName, /* out */ _di_IShellFolder &Folder);
extern PACKAGE Shlobj::PItemIDList __fastcall PathToPidl(const AnsiString Path, _di_IShellFolder Folder);
extern PACKAGE Shlobj::PItemIDList __fastcall PathToPidlBind(const AnsiString FileName, /* out */ _di_IShellFolder &Folder);
extern PACKAGE bool __fastcall PidlBindToParent(Shlobj::PItemIDList IdList, /* out */ _di_IShellFolder &Folder, /* out */ Shlobj::PItemIDList &Last);
extern PACKAGE bool __fastcall PidlCompare(Shlobj::PItemIDList Pidl1, Shlobj::PItemIDList Pidl2);
extern PACKAGE bool __fastcall PidlCopy(Shlobj::PItemIDList Source, /* out */ Shlobj::PItemIDList &Dest);
extern PACKAGE bool __fastcall PidlFree(Shlobj::PItemIDList &IdList);
extern PACKAGE int __fastcall PidlGetDepth(Shlobj::PItemIDList Pidl);
extern PACKAGE int __fastcall PidlGetLength(Shlobj::PItemIDList Pidl);
extern PACKAGE Shlobj::PItemIDList __fastcall PidlGetNext(Shlobj::PItemIDList Pidl);
extern PACKAGE AnsiString __fastcall PidlToPath(Shlobj::PItemIDList IdList);
extern PACKAGE bool __fastcall StrRetFreeMem(const _STRRET &StrRet);
extern PACKAGE AnsiString __fastcall StrRetToString(Shlobj::PItemIDList IdList, const _STRRET &StrRet, bool Free);
extern PACKAGE void __fastcall ShellLinkFree(TShellLink &Link);
extern PACKAGE HRESULT __fastcall ShellLinkCreateSystem(const TShellLink &Link, const int Folder, const AnsiString FileName);
extern PACKAGE HRESULT __fastcall ShellLinkCreate(const TShellLink &Link, const AnsiString FileName);
extern PACKAGE HRESULT __fastcall ShellLinkResolve(const AnsiString FileName, /* out */ TShellLink &Link)/* overload */;
extern PACKAGE HRESULT __fastcall ShellLinkResolve(const AnsiString FileName, /* out */ TShellLink &Link, const unsigned ResolveFlags)/* overload */;
extern PACKAGE HICON __fastcall ShellLinkIcon(const TShellLink &Link)/* overload */;
extern PACKAGE HICON __fastcall ShellLinkIcon(const AnsiString FileName)/* overload */;
extern PACKAGE AnsiString __fastcall SHGetItemInfoTip(const _di_IShellFolder Folder, Shlobj::PItemIDList Item);
extern PACKAGE bool __fastcall SHDllGetVersion(const AnsiString FileName, _DLLVERSIONINFO &Version);
extern PACKAGE bool __fastcall OverlayIcon(HICON &Icon, HICON Overlay, bool Large);
extern PACKAGE bool __fastcall OverlayIconShortCut(HICON &Large, HICON &Small);
extern PACKAGE bool __fastcall OverlayIconShared(HICON &Large, HICON &Small);
extern PACKAGE HICON __fastcall GetSystemIcon(int IconIndex, unsigned Flags);
extern PACKAGE bool __fastcall ShellExecEx(const AnsiString FileName, const AnsiString Parameters = "", const AnsiString Verb = "", int CmdShow = 0x1);
extern PACKAGE bool __fastcall ShellExec(int Wnd, const AnsiString Operation, const AnsiString FileName, const AnsiString Parameters, const AnsiString Directory, int ShowCommand);
extern PACKAGE bool __fastcall ShellExecAndWait(const AnsiString FileName, const AnsiString Parameters = "", const AnsiString Verb = "", int CmdShow = 0x1, const AnsiString Directory = "");
extern PACKAGE bool __fastcall ShellOpenAs(const AnsiString FileName);
extern PACKAGE bool __fastcall ShellRasDial(const AnsiString EntryName);
extern PACKAGE bool __fastcall ShellRunControlPanel(const AnsiString NameOrFileName, int AppletNumber = 0x0);
extern PACKAGE TJclFileExeType __fastcall GetFileExeType(const AnsiString FileName);
extern PACKAGE AnsiString __fastcall ShellFindExecutable(const AnsiString FileName, const AnsiString DefaultDir);
extern PACKAGE HICON __fastcall GetFileNameIcon(const AnsiString FileName, unsigned Flags = (unsigned)(0x0));

}	/* namespace Jclshell */
using namespace Jclshell;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclshell
