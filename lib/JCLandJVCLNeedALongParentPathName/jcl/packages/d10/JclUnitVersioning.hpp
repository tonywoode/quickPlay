// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclunitversioning.pas' rev: 10.00

#ifndef JclunitversioningHPP
#define JclunitversioningHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclunitversioning
{
//-- type declarations -------------------------------------------------------
struct TUnitVersionInfo;
typedef TUnitVersionInfo *PUnitVersionInfo;

struct TUnitVersionInfo
{
	
public:
	AnsiString RCSfile;
	AnsiString Revision;
	AnsiString Date;
	AnsiString LogPath;
	AnsiString Extra;
	void *Data;
} ;

class DELPHICLASS TUnitVersion;
class PASCALIMPLEMENTATION TUnitVersion : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TUnitVersionInfo *FInfo;
	
public:
	__fastcall TUnitVersion(PUnitVersionInfo AInfo);
	AnsiString __fastcall RCSfile();
	AnsiString __fastcall Revision();
	AnsiString __fastcall Date();
	AnsiString __fastcall Extra();
	AnsiString __fastcall LogPath();
	void * __fastcall Data(void);
	System::TDateTime __fastcall DateTime(void);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TUnitVersion(void) { }
	#pragma option pop
	
};


class DELPHICLASS TUnitVersioningModule;
class PASCALIMPLEMENTATION TUnitVersioningModule : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TUnitVersion* operator[](int Index) { return Items[Index]; }
	
private:
	unsigned FInstance;
	Contnrs::TObjectList* FItems;
	TUnitVersion* __fastcall GetItems(int Index);
	int __fastcall GetCount(void);
	void __fastcall Add(PUnitVersionInfo Info);
	int __fastcall IndexOfInfo(PUnitVersionInfo Info);
	
public:
	__fastcall TUnitVersioningModule(unsigned AInstance);
	__fastcall virtual ~TUnitVersioningModule(void);
	int __fastcall IndexOf(const AnsiString RCSfile, const AnsiString LogPath = "*");
	TUnitVersion* __fastcall FindUnit(const AnsiString RCSfile, const AnsiString LogPath = "*");
	__property unsigned Instance = {read=FInstance, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property TUnitVersion* Items[int Index] = {read=GetItems/*, default*/};
};


class DELPHICLASS TCustomUnitVersioningProvider;
class PASCALIMPLEMENTATION TCustomUnitVersioningProvider : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	__fastcall virtual TCustomUnitVersioningProvider(void);
	virtual void __fastcall LoadModuleUnitVersioningInfo(unsigned Instance);
	virtual void __fastcall ReleaseModuleUnitVersioningInfo(unsigned Instance);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TCustomUnitVersioningProvider(void) { }
	#pragma option pop
	
};


typedef TMetaClass* TUnitVersioningProviderClass;

class DELPHICLASS TUnitVersioning;
class PASCALIMPLEMENTATION TUnitVersioning : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TUnitVersion* operator[](int Index) { return Items[Index]; }
	
private:
	Contnrs::TObjectList* FModules;
	Contnrs::TObjectList* FProviders;
	TUnitVersion* __fastcall GetItems(int Index);
	int __fastcall GetCount(void);
	int __fastcall GetModuleCount(void);
	TUnitVersioningModule* __fastcall GetModules(int Index);
	void __fastcall UnregisterModule(TUnitVersioningModule* Module)/* overload */;
	void __fastcall ValidateModules(void);
	virtual void __fastcall Add(unsigned Instance, PUnitVersionInfo Info);
	virtual void __fastcall UnregisterModule(unsigned Instance)/* overload */;
	
public:
	__fastcall TUnitVersioning(void);
	__fastcall virtual ~TUnitVersioning(void);
	void __fastcall RegisterProvider(TMetaClass* AProviderClass);
	void __fastcall LoadModuleUnitVersioningInfo(unsigned Instance);
	int __fastcall IndexOf(const AnsiString RCSfile, const AnsiString LogPath = "*");
	TUnitVersion* __fastcall FindUnit(const AnsiString RCSfile, const AnsiString LogPath = "*");
	__property int ModuleCount = {read=GetModuleCount, nodefault};
	__property TUnitVersioningModule* Modules[int Index] = {read=GetModules};
	__property int Count = {read=GetCount, nodefault};
	__property TUnitVersion* Items[int Index] = {read=GetItems/*, default*/};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TUnitVersioning* __fastcall GetUnitVersioning(void);
extern PACKAGE void __fastcall RegisterUnitVersion(unsigned Instance, const TUnitVersionInfo &Info);
extern PACKAGE void __fastcall UnregisterUnitVersion(unsigned Instance);

}	/* namespace Jclunitversioning */
using namespace Jclunitversioning;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclunitversioning
