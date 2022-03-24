// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclversioncontrol.pas' rev: 10.00

#ifndef JclversioncontrolHPP
#define JclversioncontrolHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Actnlist.hpp>	// Pascal unit
#include <Imglist.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclversioncontrol
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TJclVersionControlActionType { vcaAdd, vcaAddSandbox, vcaBlame, vcaBranch, vcaBranchSandbox, vcaCheckOutSandbox, vcaCommit, vcaCommitSandbox, vcaContextMenu, vcaDiff, vcaExplore, vcaExploreSandbox, vcaGraph, vcaLog, vcaLogSandbox, vcaLock, vcaLockSandbox, vcaMerge, vcaMergeSandbox, vcaProperties, vcaPropertiesSandbox, vcaRename, vcaRenameSandbox, vcaRepoBrowser, vcaRevert, vcaRevertSandbox, vcaStatus, vcaStatusSandbox, vcaTag, vcaTagSandBox, vcaUpdate, vcaUpdateSandbox, vcaUpdateTo, vcaUpdateSandboxTo, vcaUnlock, vcaUnlockSandbox };
#pragma option pop

typedef Set<TJclVersionControlActionType, vcaAdd, vcaUnlockSandbox>  TJclVersionControlActionTypes;

struct TJclVersionControlActionInfo
{
	
public:
	bool Sandbox;
	bool SaveFile;
	bool AllPlugins;
	System::TResStringRec *Caption;
	AnsiString ActionName;
} ;

class DELPHICLASS TJclVersionControlPlugin;
class PASCALIMPLEMENTATION TJclVersionControlPlugin : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	virtual TJclVersionControlActionTypes __fastcall GetSupportedActionTypes();
	virtual TJclVersionControlActionTypes __fastcall GetFileActions(const AnsiString FileName);
	virtual TJclVersionControlActionTypes __fastcall GetSandboxActions(const AnsiString SdBxName);
	virtual bool __fastcall GetEnabled(void);
	virtual AnsiString __fastcall GetName();
	
public:
	__fastcall virtual TJclVersionControlPlugin(void);
	__fastcall virtual ~TJclVersionControlPlugin(void);
	virtual bool __fastcall GetSandboxNames(const AnsiString FileName, Classes::TStrings* SdBxNames);
	virtual bool __fastcall ExecuteAction(const AnsiString FileName, const TJclVersionControlActionType Action);
	__property TJclVersionControlActionTypes SupportedActionTypes = {read=GetSupportedActionTypes};
	__property TJclVersionControlActionTypes FileActions[AnsiString FileName] = {read=GetFileActions};
	__property TJclVersionControlActionTypes SandboxActions[AnsiString SdBxName] = {read=GetSandboxActions};
	__property bool Enabled = {read=GetEnabled, nodefault};
	__property AnsiString Name = {read=GetName};
};


typedef TMetaClass* TJclVersionControlPluginClass;

class DELPHICLASS TJclVersionControlCache;
class PASCALIMPLEMENTATION TJclVersionControlCache : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* FSandboxList;
	AnsiString FFileName;
	TJclVersionControlPlugin* FPlugin;
	TJclVersionControlActionTypes FActions;
	System::TDateTime FValidityTime;
	bool FSupported;
	AnsiString __fastcall GetSandBox(int Index);
	TJclVersionControlActionTypes __fastcall GetSandboxAction(int Index);
	int __fastcall GetSandboxCount(void);
	
public:
	__fastcall TJclVersionControlCache(TJclVersionControlPlugin* APlugin, const AnsiString AFileName);
	__fastcall virtual ~TJclVersionControlCache(void);
	bool __fastcall GetValid(const System::TDateTime ATime);
	__property TJclVersionControlPlugin* Plugin = {read=FPlugin};
	__property AnsiString FileName = {read=FFileName};
	__property TJclVersionControlActionTypes Actions = {read=FActions};
	__property AnsiString SandBoxes[int Index] = {read=GetSandBox};
	__property TJclVersionControlActionTypes SandBoxActions[int Index] = {read=GetSandboxAction};
	__property int SandBoxCount = {read=GetSandboxCount, nodefault};
	__property bool Supported = {read=FSupported, nodefault};
	__property System::TDateTime ValidityTime = {read=FValidityTime};
};


class DELPHICLASS TJclVersionControlSystemPlugin;
class PASCALIMPLEMENTATION TJclVersionControlSystemPlugin : public TJclVersionControlPlugin 
{
	typedef TJclVersionControlPlugin inherited;
	
protected:
	virtual TJclVersionControlActionTypes __fastcall GetSupportedActionTypes();
	virtual TJclVersionControlActionTypes __fastcall GetFileActions(const AnsiString FileName);
	virtual TJclVersionControlActionTypes __fastcall GetSandboxActions(const AnsiString SdBxName);
	virtual bool __fastcall GetEnabled(void);
	virtual AnsiString __fastcall GetName();
	
public:
	virtual bool __fastcall GetSandboxNames(const AnsiString FileName, Classes::TStrings* SdBxNames);
	virtual bool __fastcall ExecuteAction(const AnsiString FileName, const TJclVersionControlActionType Action);
public:
	#pragma option push -w-inl
	/* TJclVersionControlPlugin.Create */ inline __fastcall virtual TJclVersionControlSystemPlugin(void) : TJclVersionControlPlugin() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclVersionControlPlugin.Destroy */ inline __fastcall virtual ~TJclVersionControlSystemPlugin(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclVersionControlPluginList;
class PASCALIMPLEMENTATION TJclVersionControlPluginList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* FFileCache;
	Contnrs::TObjectList* FPluginList;
	void __fastcall ClearFileCache(void);
	TJclVersionControlPlugin* __fastcall GetPlugin(int Index);
	
public:
	__fastcall TJclVersionControlPluginList(void);
	__fastcall virtual ~TJclVersionControlPluginList(void);
	int __fastcall Count(void);
	TJclVersionControlCache* __fastcall GetFileCache(const AnsiString FileName, const TJclVersionControlPlugin* Plugin);
	int __fastcall NumberOfEnabledPlugins(void);
	void __fastcall RegisterPluginClass(const TMetaClass* APluginClass);
	void __fastcall UnregisterPluginClass(const TMetaClass* APluginClass);
	__property TJclVersionControlPlugin* Plugins[int Index] = {read=GetPlugin};
};


class DELPHICLASS TJclVersionControlActionsCache;
class PASCALIMPLEMENTATION TJclVersionControlActionsCache : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FSandbox;
	TJclVersionControlActionTypes FActionTypes;
	
public:
	__fastcall TJclVersionControlActionsCache(AnsiString ASandbox, const TJclVersionControlActionTypes &AActionTypes);
	__property AnsiString Sandbox = {read=FSandbox};
	__property TJclVersionControlActionTypes ActionTypes = {read=FActionTypes};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclVersionControlActionsCache(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE TJclVersionControlPluginList* __fastcall VersionControlPluginList(void);
extern PACKAGE void __fastcall RegisterVersionControlPluginClass(const TMetaClass* APluginClass);
extern PACKAGE void __fastcall UnRegisterVersionControlPluginClass(const TMetaClass* APluginClass);
extern PACKAGE TJclVersionControlActionInfo __fastcall VersionControlActionInfo(TJclVersionControlActionType ActionType);

}	/* namespace Jclversioncontrol */
using namespace Jclversioncontrol;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclversioncontrol
