// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclmsdossys.pas' rev: 10.00

#ifndef JclmsdossysHPP
#define JclmsdossysHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclmsdossys
{
//-- type declarations -------------------------------------------------------
__interface IJclMsdosSys;
typedef System::DelphiInterface<IJclMsdosSys> _di_IJclMsdosSys;
__interface  INTERFACE_UUID("{3E1C7E48-49E5-408B-86D2-9924D223B5C5}") IJclMsdosSys  : public IInterface 
{
	
public:
	virtual bool __fastcall GetAutoScan(void) = 0 ;
	virtual unsigned __fastcall GetBootDelay(void) = 0 ;
	virtual bool __fastcall GetBootGUI(void) = 0 ;
	virtual bool __fastcall GetBootKeys(void) = 0 ;
	virtual bool __fastcall GetBootMenu(void) = 0 ;
	virtual unsigned __fastcall GetBootMenuDefault(void) = 0 ;
	virtual unsigned __fastcall GetBootMenuDelay(void) = 0 ;
	virtual bool __fastcall GetBootMulti(void) = 0 ;
	virtual bool __fastcall GetBootSafe(void) = 0 ;
	virtual bool __fastcall GetBootWarn(void) = 0 ;
	virtual bool __fastcall GetBootWin(void) = 0 ;
	virtual bool __fastcall GetDBLSpace(void) = 0 ;
	virtual bool __fastcall GetDoubleBuffer(void) = 0 ;
	virtual bool __fastcall GetDRVSpace(void) = 0 ;
	virtual char __fastcall GetHostWinBootDrv(void) = 0 ;
	virtual bool __fastcall GetLoadTop(void) = 0 ;
	virtual bool __fastcall GetLogo(void) = 0 ;
	virtual bool __fastcall GetNetwork(void) = 0 ;
	virtual char __fastcall GetUninstallDir(void) = 0 ;
	virtual AnsiString __fastcall GetWinBootDir(void) = 0 ;
	virtual AnsiString __fastcall GetWinDir(void) = 0 ;
	virtual AnsiString __fastcall GetWinVer(void) = 0 ;
	virtual void __fastcall SetUninstallDir(char AUninstallDir) = 0 ;
	virtual void __fastcall SetWinDir(AnsiString AWinDir) = 0 ;
	virtual void __fastcall SetWinBootDir(AnsiString AWinBootDir) = 0 ;
	virtual void __fastcall SetHostWinBootDrv(char AHostWinBootDrv) = 0 ;
	virtual void __fastcall SetAutoScan(bool AAutoScan) = 0 ;
	virtual void __fastcall SetBootDelay(unsigned ABootDelay) = 0 ;
	virtual void __fastcall SetBootGUI(bool ABootGUI) = 0 ;
	virtual void __fastcall SetBootKeys(bool ABootKeys) = 0 ;
	virtual void __fastcall SetBootMenu(bool ABootMenu) = 0 ;
	virtual void __fastcall SetBootMenuDefault(unsigned ABootMenuDefault) = 0 ;
	virtual void __fastcall SetBootMenuDelay(unsigned ABootMenuDelay) = 0 ;
	virtual void __fastcall SetBootMulti(bool ABootMulti) = 0 ;
	virtual void __fastcall SetBootSafe(bool ABootSafe) = 0 ;
	virtual void __fastcall SetBootWarn(bool ABootWarn) = 0 ;
	virtual void __fastcall SetBootWin(bool ABootWin) = 0 ;
	virtual void __fastcall SetDBLSpace(bool ADBLSpace) = 0 ;
	virtual void __fastcall SetDRVSpace(bool ADRVSpace) = 0 ;
	virtual void __fastcall SetDoubleBuffer(bool ADoubleBuffer) = 0 ;
	virtual void __fastcall SetLoadTop(bool ALoadTop) = 0 ;
	virtual void __fastcall SetLogo(bool ALogo) = 0 ;
	virtual void __fastcall SetNetwork(bool ANetwork) = 0 ;
	virtual void __fastcall SetWinVer(AnsiString AWinVer) = 0 ;
	virtual void __fastcall SetBool(bool &ANew, bool AOld) = 0 ;
	virtual void __fastcall SetString(AnsiString &ANew, AnsiString AOld) = 0 ;
	__property char UninstallDir = {read=GetUninstallDir, write=SetUninstallDir};
	__property AnsiString WinDir = {read=GetWinDir, write=SetWinDir};
	__property AnsiString WinBootDir = {read=GetWinBootDir, write=SetWinBootDir};
	__property char HostWinBootDrv = {read=GetHostWinBootDrv, write=SetHostWinBootDrv};
	__property bool AutoScan = {read=GetAutoScan, write=SetAutoScan};
	__property unsigned BootDelay = {read=GetBootDelay, write=SetBootDelay};
	__property bool BootGUI = {read=GetBootGUI, write=SetBootGUI};
	__property bool BootKeys = {read=GetBootKeys, write=SetBootKeys};
	__property bool BootMenu = {read=GetBootMenu, write=SetBootMenu};
	__property unsigned BootMenuDefault = {read=GetBootMenuDefault, write=SetBootMenuDefault};
	__property unsigned BootMenuDelay = {read=GetBootMenuDelay, write=SetBootMenuDelay};
	__property bool BootMulti = {read=GetBootMulti, write=SetBootMulti};
	__property bool BootSafe = {read=GetBootSafe, write=SetBootSafe};
	__property bool BootWarn = {read=GetBootWarn, write=SetBootWarn};
	__property bool BootWin = {read=GetBootWin, write=SetBootWin};
	__property bool DBLSpace = {read=GetDBLSpace, write=SetDBLSpace};
	__property bool DRVSpace = {read=GetDRVSpace, write=SetDRVSpace};
	__property bool DoubleBuffer = {read=GetDoubleBuffer, write=SetDoubleBuffer};
	__property bool LoadTop = {read=GetLoadTop, write=SetLoadTop};
	__property bool Logo = {read=GetLogo, write=SetLogo};
	__property bool Network = {read=GetNetwork, write=SetNetwork};
	__property AnsiString WinVer = {read=GetWinVer, write=SetWinVer};
};

class DELPHICLASS TJclMsdosSys;
class PASCALIMPLEMENTATION TJclMsdosSys : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	char FUninstallDir;
	AnsiString FWinDir;
	AnsiString FWinBootDir;
	char FHostWinBootDrv;
	bool FAutoScan;
	unsigned FBootDelay;
	bool FBootGUI;
	bool FBootKeys;
	bool FBootMenu;
	unsigned FBootMenuDefault;
	unsigned FBootMenuDelay;
	bool FBootMulti;
	bool FBootSafe;
	bool FBootWarn;
	bool FBootWin;
	bool FDBLSpace;
	bool FDRVSpace;
	bool FDoubleBuffer;
	bool FLoadTop;
	bool FLogo;
	bool FNetwork;
	AnsiString FWinVer;
	
public:
	__fastcall TJclMsdosSys(void);
	__fastcall virtual ~TJclMsdosSys(void);
	bool __fastcall GetAutoScan(void);
	unsigned __fastcall GetBootDelay(void);
	bool __fastcall GetBootGUI(void);
	bool __fastcall GetBootKeys(void);
	bool __fastcall GetBootMenu(void);
	unsigned __fastcall GetBootMenuDefault(void);
	unsigned __fastcall GetBootMenuDelay(void);
	bool __fastcall GetBootMulti(void);
	bool __fastcall GetBootSafe(void);
	bool __fastcall GetBootWarn(void);
	bool __fastcall GetBootWin(void);
	bool __fastcall GetDBLSpace(void);
	bool __fastcall GetDoubleBuffer(void);
	bool __fastcall GetDRVSpace(void);
	char __fastcall GetHostWinBootDrv(void);
	bool __fastcall GetLoadTop(void);
	bool __fastcall GetLogo(void);
	bool __fastcall GetNetwork(void);
	char __fastcall GetUninstallDir(void);
	AnsiString __fastcall GetWinBootDir();
	AnsiString __fastcall GetWinDir();
	AnsiString __fastcall GetWinVer();
	void __fastcall SetUninstallDir(char AUninstallDir);
	void __fastcall SetWinDir(AnsiString AWinDir);
	void __fastcall SetWinBootDir(AnsiString AWinBootDir);
	void __fastcall SetHostWinBootDrv(char AHostWinBootDrv);
	void __fastcall SetAutoScan(bool AAutoScan);
	void __fastcall SetBootDelay(unsigned ABootDelay);
	void __fastcall SetBootGUI(bool ABootGUI);
	void __fastcall SetBootKeys(bool ABootKeys);
	void __fastcall SetBootMenu(bool ABootMenu);
	void __fastcall SetBootMenuDefault(unsigned ABootMenuDefault);
	void __fastcall SetBootMenuDelay(unsigned ABootMenuDelay);
	void __fastcall SetBootMulti(bool ABootMulti);
	void __fastcall SetBootSafe(bool ABootSafe);
	void __fastcall SetBootWarn(bool ABootWarn);
	void __fastcall SetBootWin(bool ABootWin);
	void __fastcall SetDBLSpace(bool ADBLSpace);
	void __fastcall SetDRVSpace(bool ADRVSpace);
	void __fastcall SetDoubleBuffer(bool ADoubleBuffer);
	void __fastcall SetLoadTop(bool ALoadTop);
	void __fastcall SetLogo(bool ALogo);
	void __fastcall SetNetwork(bool ANetwork);
	void __fastcall SetWinVer(AnsiString AWinVer);
	void __fastcall SetBool(bool &ANew, bool AOld);
	void __fastcall SetString(AnsiString &ANew, AnsiString AOld);
	void __fastcall ReadMsdosSys(void);
	void __fastcall WriteMsdosSys(void);
	__property char UninstallDir = {read=GetUninstallDir, write=SetUninstallDir, nodefault};
	__property AnsiString WinDir = {read=GetWinDir, write=SetWinDir};
	__property AnsiString WinBootDir = {read=GetWinBootDir, write=SetWinBootDir};
	__property char HostWinBootDrv = {read=GetHostWinBootDrv, write=SetHostWinBootDrv, nodefault};
	__property bool AutoScan = {read=GetAutoScan, write=SetAutoScan, nodefault};
	__property unsigned BootDelay = {read=GetBootDelay, write=SetBootDelay, nodefault};
	__property bool BootGUI = {read=GetBootGUI, write=SetBootGUI, nodefault};
	__property bool BootKeys = {read=GetBootKeys, write=SetBootKeys, nodefault};
	__property bool BootMenu = {read=GetBootMenu, write=SetBootMenu, nodefault};
	__property unsigned BootMenuDefault = {read=GetBootMenuDefault, write=SetBootMenuDefault, nodefault};
	__property unsigned BootMenuDelay = {read=GetBootMenuDelay, write=SetBootMenuDelay, nodefault};
	__property bool BootMulti = {read=GetBootMulti, write=SetBootMulti, nodefault};
	__property bool BootSafe = {read=GetBootSafe, write=SetBootSafe, nodefault};
	__property bool BootWarn = {read=GetBootWarn, write=SetBootWarn, nodefault};
	__property bool BootWin = {read=GetBootWin, write=SetBootWin, nodefault};
	__property bool DBLSpace = {read=GetDBLSpace, write=SetDBLSpace, nodefault};
	__property bool DRVSpace = {read=GetDRVSpace, write=SetDRVSpace, nodefault};
	__property bool DoubleBuffer = {read=GetDoubleBuffer, write=SetDoubleBuffer, nodefault};
	__property bool LoadTop = {read=GetLoadTop, write=SetLoadTop, nodefault};
	__property bool Logo = {read=GetLogo, write=SetLogo, nodefault};
	__property bool Network = {read=GetNetwork, write=SetNetwork, nodefault};
	__property AnsiString WinVer = {read=GetWinVer, write=SetWinVer};
private:
	void *__IJclMsdosSys;	/* Jclmsdossys::IJclMsdosSys */
	
public:
	operator IJclMsdosSys*(void) { return (IJclMsdosSys*)&__IJclMsdosSys; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE _di_IJclMsdosSys __fastcall GetMsdosSys();

}	/* namespace Jclmsdossys */
using namespace Jclmsdossys;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclmsdossys
