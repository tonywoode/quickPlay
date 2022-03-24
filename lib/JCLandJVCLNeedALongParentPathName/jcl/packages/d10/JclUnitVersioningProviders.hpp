// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclunitversioningproviders.pas' rev: 10.00

#ifndef JclunitversioningprovidersHPP
#define JclunitversioningprovidersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Jclpeimage.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclunitversioningproviders
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TJclUnitVersioningList;
class PASCALIMPLEMENTATION TJclUnitVersioningList : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	Jclunitversioning::PUnitVersionInfo operator[](int AIndex) { return Items[AIndex]; }
	
private:
	Classes::TList* FItems;
	int __fastcall GetCount(void);
	Jclunitversioning::PUnitVersionInfo __fastcall GetItems(int AIndex);
	
public:
	__fastcall TJclUnitVersioningList(void);
	__fastcall virtual ~TJclUnitVersioningList(void);
	void __fastcall Add(const Jclunitversioning::TUnitVersionInfo &Info);
	void __fastcall Clear(void);
	bool __fastcall Load(unsigned AModule);
	bool __fastcall LoadFromStream(Classes::TStream* AStream);
	bool __fastcall LoadFromDefaultResource(unsigned AModule);
	bool __fastcall LoadFromDefaultSection(unsigned AModule);
	void __fastcall SaveToFile(AnsiString AFileName);
	void __fastcall SaveToStream(Classes::TStream* AStream);
	__property int Count = {read=GetCount, nodefault};
	__property Jclunitversioning::PUnitVersionInfo Items[int AIndex] = {read=GetItems/*, default*/};
};


class DELPHICLASS TJclUnitVersioningProviderModule;
class PASCALIMPLEMENTATION TJclUnitVersioningProviderModule : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TJclUnitVersioningList* FInfoList;
	unsigned FInstance;
	
public:
	__fastcall TJclUnitVersioningProviderModule(unsigned Instance);
	__fastcall virtual ~TJclUnitVersioningProviderModule(void);
	__property TJclUnitVersioningList* InfoList = {read=FInfoList};
	__property unsigned Instance = {read=FInstance, nodefault};
};


class DELPHICLASS TJclDefaultUnitVersioningProvider;
class PASCALIMPLEMENTATION TJclDefaultUnitVersioningProvider : public Jclunitversioning::TCustomUnitVersioningProvider 
{
	typedef Jclunitversioning::TCustomUnitVersioningProvider inherited;
	
private:
	Contnrs::TObjectList* FModules;
	int __fastcall IndexOfInstance(unsigned Instance);
	
public:
	__fastcall virtual TJclDefaultUnitVersioningProvider(void);
	__fastcall virtual ~TJclDefaultUnitVersioningProvider(void);
	virtual void __fastcall LoadModuleUnitVersioningInfo(unsigned Instance);
	virtual void __fastcall ReleaseModuleUnitVersioningInfo(unsigned Instance);
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall InsertUnitVersioningSection(const AnsiString ExecutableFileName, TJclUnitVersioningList* AUnitList);

}	/* namespace Jclunitversioningproviders */
using namespace Jclunitversioningproviders;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclunitversioningproviders
