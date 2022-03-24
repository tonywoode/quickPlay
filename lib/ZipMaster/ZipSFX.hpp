// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Zipsfx.pas' rev: 10.00

#ifndef ZipsfxHPP
#define ZipsfxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Sfxinterface.hpp>	// Pascal unit
#include <Zipmsg.hpp>	// Pascal unit
#include <Dzutils.hpp>	// Pascal unit
#include <Sfxstructs.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Zipsfx
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomZipSFX;
#pragma pack(push,1)
class PASCALIMPLEMENTATION TCustomZipSFX : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	unsigned FMessageFlags;
	AnsiString FSFXLanguage;
	AnsiString FCommandLine;
	AnsiString FDialogTitle;
	AnsiString FMessage;
	AnsiString FFallbackExtractPath;
	AnsiString FDefaultExtractPath;
	AnsiString FSourceFile;
	AnsiString FTargetFile;
	AnsiString FSFXPath;
	Sfxinterface::TSFXOptions FOptions;
	Sfxinterface::TSFXOverwriteMode FOverwriteMode;
	Graphics::TIcon* FIcon;
	Dzutils::THowToDeleteFile FHowToDelete;
	void __fastcall SetIcon(const Graphics::TIcon* Value);
	AnsiString __fastcall GetVersion();
	void __fastcall SetVersion(const AnsiString Value);
	void __fastcall SetSFXLanguage(const AnsiString Value);
	AnsiString __fastcall GetSFXLanguage();
	
protected:
	__property AnsiString SFXPath = {read=FSFXPath, write=FSFXPath};
	__property Sfxinterface::TSFXOptions Options = {read=FOptions, write=FOptions, default=0};
	__property Sfxinterface::TSFXOverwriteMode OverwriteMode = {read=FOverwriteMode, write=FOverwriteMode, default=2};
	__property AnsiString Message = {read=FMessage, write=FMessage};
	__property unsigned MessageFlags = {read=FMessageFlags, write=FMessageFlags, nodefault};
	__property AnsiString DefaultExtractPath = {read=FDefaultExtractPath, write=FDefaultExtractPath};
	__property AnsiString DialogTitle = {read=FDialogTitle, write=FDialogTitle};
	__property AnsiString CommandLine = {read=FCommandLine, write=FCommandLine};
	__property AnsiString FallbackExtractPath = {read=FFallbackExtractPath, write=FFallbackExtractPath};
	__property AnsiString SourceFile = {read=FSourceFile, write=FSourceFile};
	__property AnsiString TargetFile = {read=FTargetFile, write=FTargetFile};
	__property Graphics::TIcon* Icon = {read=FIcon, write=SetIcon};
	__property Dzutils::THowToDeleteFile HowToDelete = {read=FHowToDelete, write=FHowToDelete, default=1};
	__property AnsiString SFXLanguage = {read=GetSFXLanguage, write=SetSFXLanguage};
	__property AnsiString Version = {read=GetVersion, write=SetVersion, stored=false};
	void __fastcall DoExecuteToSFX(const bool bCreateNew);
	
public:
	__fastcall virtual TCustomZipSFX(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomZipSFX(void);
	/*         class method */ static AnsiString __fastcall GetSupportedSFXLanguages(TMetaClass* vmt);
	void __fastcall ConvertToSFX(void);
	void __fastcall ConvertToZip(void);
	void __fastcall Convert(void);
	void __fastcall CreateNewSFX(void);
	void __fastcall LoadFromFile(const AnsiString sFile);
	void __fastcall SaveToFile(const AnsiString sFile);
};

#pragma pack(pop)

class DELPHICLASS TZipSFX;
#pragma pack(push,1)
class PASCALIMPLEMENTATION TZipSFX : public TCustomZipSFX 
{
	typedef TCustomZipSFX inherited;
	
__published:
	__property SFXPath ;
	__property Options  = {default=0};
	__property OverwriteMode  = {default=2};
	__property Message ;
	__property MessageFlags ;
	__property DefaultExtractPath ;
	__property DialogTitle ;
	__property CommandLine ;
	__property FallbackExtractPath ;
	__property SourceFile ;
	__property TargetFile ;
	__property Icon ;
	__property Version ;
	__property SFXLanguage ;
public:
	#pragma option push -w-inl
	/* TCustomZipSFX.Create */ inline __fastcall virtual TZipSFX(Classes::TComponent* AOwner) : TCustomZipSFX(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomZipSFX.Destroy */ inline __fastcall virtual ~TZipSFX(void) { }
	#pragma option pop
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define SFX_RELEASE "09-19-2005"
extern PACKAGE AnsiString DZSFX_LANG;
extern PACKAGE void __fastcall Register(void);

}	/* namespace Zipsfx */
using namespace Zipsfx;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Zipsfx
