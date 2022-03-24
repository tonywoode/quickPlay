// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclborlandtools.pas' rev: 10.00

#ifndef JclborlandtoolsHPP
#define JclborlandtoolsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Shlobj.hpp>	// Pascal unit
#include <Mshelpservices_tlb.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Inifiles.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclsysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclborlandtools
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EJclBorRADException;
class PASCALIMPLEMENTATION EJclBorRADException : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclBorRADException(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclBorRADException(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclBorRADException(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclBorRADException(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclBorRADException(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclBorRADException(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclBorRADException(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclBorRADException(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclBorRADException(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TJclBorRADToolKind { brDelphi, brCppBuilder, brBorlandDevStudio };
#pragma option pop

#pragma option push -b-
enum TJclBorRADToolEdition { deSTD, dePRO, deCSS, deARC };
#pragma option pop

typedef AnsiString TJclBorRADToolPath;

#pragma option push -b-
enum TJclBorPersonality { bpDelphi32, bpDelphi64, bpBCBuilder32, bpBCBuilder64, bpDelphiNet32, bpDelphiNet64, bpCSBuilder32, bpCSBuilder64, bpVisualBasic32, bpVisualBasic64, bpDesign, bpUnknown };
#pragma option pop

typedef Set<TJclBorPersonality, bpDelphi32, bpUnknown>  TJclBorPersonalities;

#pragma option push -b-
enum TJclBorDesigner { bdVCL, bdCLX };
#pragma option pop

typedef Set<TJclBorDesigner, bdVCL, bdCLX>  TJclBorDesigners;

#pragma option push -b-
enum TJclBorPlatform { bp32bit, bp64bit };
#pragma option pop

typedef AnsiString JclBorlandTools__2[12];

typedef AnsiString JclBorlandTools__3[2];

typedef AnsiString JclBorlandTools__4[2];

class DELPHICLASS TJclBorRADToolInstallationObject;
class DELPHICLASS TJclBorRADToolInstallation;
class DELPHICLASS TJclBCC32;
class DELPHICLASS TJclBorlandCommandLineTool;
class PASCALIMPLEMENTATION TJclBorRADToolInstallationObject : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	TJclBorRADToolInstallation* FInstallation;
	
public:
	__fastcall TJclBorRADToolInstallationObject(TJclBorRADToolInstallation* AInstallation);
	__property TJclBorRADToolInstallation* Installation = {read=FInstallation};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclBorRADToolInstallationObject(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TJclBorlandCommandLineToolEvent)(TJclBorlandCommandLineTool* Sender);

class PASCALIMPLEMENTATION TJclBorlandCommandLineTool : public TJclBorRADToolInstallationObject 
{
	typedef TJclBorRADToolInstallationObject inherited;
	
private:
	Classes::TStringList* FOptions;
	Jclsysutils::TTextHandler FOutputCallback;
	AnsiString FOutput;
	TJclBorlandCommandLineToolEvent FOnAfterExecute;
	TJclBorlandCommandLineToolEvent FOnBeforeExecute;
	void __fastcall OemTextHandler(const AnsiString Text);
	
protected:
	void __fastcall CheckOutputValid(void);
	AnsiString __fastcall GetFileName();
	bool __fastcall InternalExecute(const AnsiString CommandLine);
	
public:
	__fastcall virtual TJclBorlandCommandLineTool(TJclBorRADToolInstallation* AInstallation);
	__fastcall virtual ~TJclBorlandCommandLineTool(void);
	virtual AnsiString __fastcall GetExeName();
	Classes::TStrings* __fastcall GetOptions(void);
	AnsiString __fastcall GetOutput();
	Jclsysutils::TTextHandler __fastcall GetOutputCallback();
	void __fastcall AddPathOption(const AnsiString Option, const AnsiString Path);
	virtual bool __fastcall Execute(const AnsiString CommandLine);
	void __fastcall SetOutputCallback(const Jclsysutils::TTextHandler CallbackMethod);
	__property AnsiString ExeName = {read=GetExeName};
	__property Classes::TStrings* Options = {read=GetOptions};
	__property Jclsysutils::TTextHandler OutputCallback = {write=SetOutputCallback};
	__property AnsiString Output = {read=GetOutput};
	__property AnsiString FileName = {read=GetFileName};
	__property TJclBorlandCommandLineToolEvent OnAfterExecute = {read=FOnAfterExecute, write=FOnAfterExecute};
	__property TJclBorlandCommandLineToolEvent OnBeforeExecute = {read=FOnBeforeExecute, write=FOnBeforeExecute};
private:
	void *__IJclCommandLineTool;	/* Jclsysutils::IJclCommandLineTool */
	
public:
	operator IJclCommandLineTool*(void) { return (IJclCommandLineTool*)&__IJclCommandLineTool; }
	
};


class PASCALIMPLEMENTATION TJclBCC32 : public TJclBorlandCommandLineTool 
{
	typedef TJclBorlandCommandLineTool inherited;
	
public:
	__fastcall virtual TJclBCC32(TJclBorRADToolInstallation* AInstallation);
	virtual AnsiString __fastcall GetExeName();
public:
	#pragma option push -w-inl
	/* TJclBorlandCommandLineTool.Destroy */ inline __fastcall virtual ~TJclBCC32(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclDCC32;
struct TProjectOptions;
class PASCALIMPLEMENTATION TJclDCC32 : public TJclBorlandCommandLineTool 
{
	typedef TJclBorlandCommandLineTool inherited;
	
protected:
	void __fastcall AddProjectOptions(const AnsiString ProjectFileName, const AnsiString DCPPath);
	bool __fastcall Compile(const AnsiString ProjectFileName);
	
public:
	__fastcall virtual TJclDCC32(TJclBorRADToolInstallation* AInstallation);
	virtual AnsiString __fastcall GetExeName();
	virtual bool __fastcall Execute(const AnsiString CommandLine);
	bool __fastcall MakePackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath, AnsiString ExtraOptions = "");
	bool __fastcall MakeProject(const AnsiString ProjectName, const AnsiString OutputDir, const AnsiString DcpSearchPath, AnsiString ExtraOptions = "");
	virtual void __fastcall SetDefaultOptions(void);
	bool __fastcall AddBDSProjOptions(const AnsiString ProjectFileName, TProjectOptions &ProjectOptions);
	bool __fastcall AddDOFOptions(const AnsiString ProjectFileName, TProjectOptions &ProjectOptions);
	bool __fastcall AddDProjOptions(const AnsiString ProjectFileName, TProjectOptions &ProjectOptions);
public:
	#pragma option push -w-inl
	/* TJclBorlandCommandLineTool.Destroy */ inline __fastcall virtual ~TJclDCC32(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclBpr2Mak;
class PASCALIMPLEMENTATION TJclBpr2Mak : public TJclBorlandCommandLineTool 
{
	typedef TJclBorlandCommandLineTool inherited;
	
public:
	virtual AnsiString __fastcall GetExeName();
public:
	#pragma option push -w-inl
	/* TJclBorlandCommandLineTool.Create */ inline __fastcall virtual TJclBpr2Mak(TJclBorRADToolInstallation* AInstallation) : TJclBorlandCommandLineTool(AInstallation) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclBorlandCommandLineTool.Destroy */ inline __fastcall virtual ~TJclBpr2Mak(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclBorRADToolIdePackages;
class PASCALIMPLEMENTATION TJclBorRADToolIdePackages : public TJclBorRADToolInstallationObject 
{
	typedef TJclBorRADToolInstallationObject inherited;
	
private:
	Classes::TStringList* FDisabledPackages;
	Classes::TStringList* FKnownPackages;
	Classes::TStringList* FKnownIDEPackages;
	Classes::TStringList* FExperts;
	int __fastcall GetCount(void);
	int __fastcall GetIDECount(void);
	int __fastcall GetExpertCount(void);
	AnsiString __fastcall GetPackageDescriptions(int Index);
	AnsiString __fastcall GetIDEPackageDescriptions(int Index);
	AnsiString __fastcall GetExpertDescriptions(int Index);
	bool __fastcall GetPackageDisabled(int Index);
	AnsiString __fastcall GetPackageFileNames(int Index);
	AnsiString __fastcall GetIDEPackageFileNames(int Index);
	AnsiString __fastcall GetExpertFileNames(int Index);
	
protected:
	AnsiString __fastcall PackageEntryToFileName(const AnsiString Entry);
	void __fastcall ReadPackages(void);
	void __fastcall RemoveDisabled(const AnsiString FileName);
	
public:
	__fastcall TJclBorRADToolIdePackages(TJclBorRADToolInstallation* AInstallation);
	__fastcall virtual ~TJclBorRADToolIdePackages(void);
	bool __fastcall AddPackage(const AnsiString FileName, const AnsiString Description);
	bool __fastcall AddIDEPackage(const AnsiString FileName, const AnsiString Description);
	bool __fastcall AddExpert(const AnsiString FileName, const AnsiString Description);
	bool __fastcall RemovePackage(const AnsiString FileName);
	bool __fastcall RemoveIDEPackage(const AnsiString FileName);
	bool __fastcall RemoveExpert(const AnsiString FileName);
	__property int Count = {read=GetCount, nodefault};
	__property int IDECount = {read=GetIDECount, nodefault};
	__property int ExpertCount = {read=GetExpertCount, nodefault};
	__property AnsiString PackageDescriptions[int Index] = {read=GetPackageDescriptions};
	__property AnsiString IDEPackageDescriptions[int Index] = {read=GetIDEPackageDescriptions};
	__property AnsiString ExpertDescriptions[int Index] = {read=GetExpertDescriptions};
	__property AnsiString PackageFileNames[int Index] = {read=GetPackageFileNames};
	__property AnsiString IDEPackageFileNames[int Index] = {read=GetIDEPackageFileNames};
	__property AnsiString ExpertFileNames[int Index] = {read=GetExpertFileNames};
	__property bool PackageDisabled[int Index] = {read=GetPackageDisabled};
};


class DELPHICLASS TJclBorRADToolIdeTool;
class PASCALIMPLEMENTATION TJclBorRADToolIdeTool : public TJclBorRADToolInstallationObject 
{
	typedef TJclBorRADToolInstallationObject inherited;
	
private:
	AnsiString FKey;
	int __fastcall GetCount(void);
	AnsiString __fastcall GetParameters(int Index);
	AnsiString __fastcall GetPath(int Index);
	AnsiString __fastcall GetTitle(int Index);
	AnsiString __fastcall GetWorkingDir(int Index);
	void __fastcall SetCount(const int Value);
	void __fastcall SetParameters(int Index, const AnsiString Value);
	void __fastcall SetPath(int Index, const AnsiString Value);
	void __fastcall SetTitle(int Index, const AnsiString Value);
	void __fastcall SetWorkingDir(int Index, const AnsiString Value);
	
protected:
	void __fastcall CheckIndex(int Index);
	
public:
	__fastcall TJclBorRADToolIdeTool(TJclBorRADToolInstallation* AInstallation);
	__property int Count = {read=GetCount, write=SetCount, nodefault};
	int __fastcall IndexOfPath(const AnsiString Value);
	int __fastcall IndexOfTitle(const AnsiString Value);
	void __fastcall RemoveIndex(const int Index);
	__property AnsiString Key = {read=FKey};
	__property AnsiString Title[int Index] = {read=GetTitle, write=SetTitle};
	__property AnsiString Path[int Index] = {read=GetPath, write=SetPath};
	__property AnsiString Parameters[int Index] = {read=GetParameters, write=SetParameters};
	__property AnsiString WorkingDir[int Index] = {read=GetWorkingDir, write=SetWorkingDir};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclBorRADToolIdeTool(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclBorlandOpenHelp;
class PASCALIMPLEMENTATION TJclBorlandOpenHelp : public TJclBorRADToolInstallationObject 
{
	typedef TJclBorRADToolInstallationObject inherited;
	
private:
	AnsiString __fastcall GetContentFileName();
	AnsiString __fastcall GetIndexFileName();
	AnsiString __fastcall GetLinkFileName();
	AnsiString __fastcall GetGidFileName();
	AnsiString __fastcall GetProjectFileName();
	AnsiString __fastcall ReadFileName(const AnsiString FormatName);
	
public:
	bool __fastcall AddHelpFile(const AnsiString HelpFileName, const AnsiString IndexName);
	bool __fastcall RemoveHelpFile(const AnsiString HelpFileName, const AnsiString IndexName);
	__property AnsiString ContentFileName = {read=GetContentFileName};
	__property AnsiString GidFileName = {read=GetGidFileName};
	__property AnsiString IndexFileName = {read=GetIndexFileName};
	__property AnsiString LinkFileName = {read=GetLinkFileName};
	__property AnsiString ProjectFileName = {read=GetProjectFileName};
public:
	#pragma option push -w-inl
	/* TJclBorRADToolInstallationObject.Create */ inline __fastcall TJclBorlandOpenHelp(TJclBorRADToolInstallation* AInstallation) : TJclBorRADToolInstallationObject(AInstallation) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclBorlandOpenHelp(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclBorRADToolPalette;
class PASCALIMPLEMENTATION TJclBorRADToolPalette : public TJclBorRADToolInstallationObject 
{
	typedef TJclBorRADToolInstallationObject inherited;
	
private:
	AnsiString FKey;
	Classes::TStringList* FTabNames;
	AnsiString __fastcall GetComponentsOnTab(int Index);
	AnsiString __fastcall GetHiddenComponentsOnTab(int Index);
	int __fastcall GetTabNameCount(void);
	AnsiString __fastcall GetTabNames(int Index);
	void __fastcall ReadTabNames(void);
	
public:
	__fastcall TJclBorRADToolPalette(TJclBorRADToolInstallation* AInstallation);
	__fastcall virtual ~TJclBorRADToolPalette(void);
	void __fastcall ComponentsOnTabToStrings(int Index, Classes::TStrings* Strings, bool IncludeUnitName = false, bool IncludeHiddenComponents = true);
	bool __fastcall DeleteTabName(const AnsiString TabName);
	bool __fastcall TabNameExists(const AnsiString TabName);
	__property AnsiString ComponentsOnTab[int Index] = {read=GetComponentsOnTab};
	__property AnsiString HiddenComponentsOnTab[int Index] = {read=GetHiddenComponentsOnTab};
	__property AnsiString Key = {read=FKey};
	__property AnsiString TabNames[int Index] = {read=GetTabNames};
	__property int TabNameCount = {read=GetTabNameCount, nodefault};
};


class DELPHICLASS TJclBorRADToolRepository;
class PASCALIMPLEMENTATION TJclBorRADToolRepository : public TJclBorRADToolInstallationObject 
{
	typedef TJclBorRADToolInstallationObject inherited;
	
private:
	Inifiles::TIniFile* FIniFile;
	AnsiString FFileName;
	Classes::TStringList* FPages;
	Inifiles::TIniFile* __fastcall GetIniFile(void);
	Classes::TStrings* __fastcall GetPages(void);
	
public:
	__fastcall TJclBorRADToolRepository(TJclBorRADToolInstallation* AInstallation);
	__fastcall virtual ~TJclBorRADToolRepository(void);
	void __fastcall AddObject(const AnsiString FileName, const AnsiString ObjectType, const AnsiString PageName, const AnsiString ObjectName, const AnsiString IconFileName, const AnsiString Description, const AnsiString Author, const AnsiString Designer, const AnsiString Ancestor = "");
	void __fastcall CloseIniFile(void);
	AnsiString __fastcall FindPage(const AnsiString Name, int OptionalIndex);
	void __fastcall RemoveObjects(const AnsiString PartialPath, const AnsiString FileName, const AnsiString ObjectType);
	__property AnsiString FileName = {read=FFileName};
	__property Inifiles::TIniFile* IniFile = {read=GetIniFile};
	__property Classes::TStrings* Pages = {read=GetPages};
};


#pragma option push -b-
enum TCommandLineTool { clAsm, clBcc32, clDcc32, clDccIL, clMake, clProj2Mak };
#pragma option pop

typedef Set<TCommandLineTool, clAsm, clProj2Mak>  TCommandLineTools;

class PASCALIMPLEMENTATION TJclBorRADToolInstallation : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Inifiles::TCustomIniFile* FConfigData;
	AnsiString FConfigDataLocation;
	unsigned FRootKey;
	Classes::TStringList* FGlobals;
	AnsiString FRootDir;
	AnsiString FBinFolderName;
	TJclBCC32* FBCC32;
	TJclDCC32* FDCC32;
	TJclBpr2Mak* FBpr2Mak;
	Jclsysutils::_di_IJclCommandLineTool FMake;
	AnsiString FEditionStr;
	TJclBorRADToolEdition FEdition;
	Classes::TStringList* FEnvironmentVariables;
	TJclBorRADToolIdePackages* FIdePackages;
	TJclBorRADToolIdeTool* FIdeTools;
	int FInstalledUpdatePack;
	TJclBorlandOpenHelp* FOpenHelp;
	TJclBorRADToolPalette* FPalette;
	TJclBorRADToolRepository* FRepository;
	int FVersionNumber;
	AnsiString FVersionNumberStr;
	int FIDEVersionNumber;
	AnsiString FIDEVersionNumberStr;
	bool FMapCreate;
	bool FJdbgCreate;
	bool FJdbgInsert;
	bool FMapDelete;
	TCommandLineTools FCommandLineTools;
	TJclBorPersonalities FPersonalities;
	Jclsysutils::TTextHandler FOutputCallback;
	bool __fastcall GetSupportsLibSuffix(void);
	TJclBCC32* __fastcall GetBCC32(void);
	TJclDCC32* __fastcall GetDCC32(void);
	TJclBpr2Mak* __fastcall GetBpr2Mak(void);
	Jclsysutils::_di_IJclCommandLineTool __fastcall GetMake();
	AnsiString __fastcall GetDescription();
	AnsiString __fastcall GetEditionAsText();
	AnsiString __fastcall GetIdeExeFileName();
	Classes::TStrings* __fastcall GetGlobals(void);
	AnsiString __fastcall GetIdeExeBuildNumber();
	TJclBorRADToolIdePackages* __fastcall GetIdePackages(void);
	bool __fastcall GetIsTurboExplorer(void);
	int __fastcall GetLatestUpdatePack(void);
	TJclBorRADToolPalette* __fastcall GetPalette(void);
	TJclBorRADToolRepository* __fastcall GetRepository(void);
	bool __fastcall GetUpdateNeeded(void);
	AnsiString __fastcall GetDefaultBDSCommonDir();
	
protected:
	bool __fastcall ProcessMapFile(const AnsiString BinaryFileName);
	virtual bool __fastcall CompileDelphiPackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath)/* overload */;
	virtual bool __fastcall CompileDelphiPackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath, const AnsiString ExtraOptions)/* overload */;
	virtual bool __fastcall CompileDelphiProject(const AnsiString ProjectName, const AnsiString OutputDir, const AnsiString DcpSearchPath);
	virtual bool __fastcall CompileBCBPackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath);
	virtual bool __fastcall CompileBCBProject(const AnsiString ProjectName, const AnsiString OutputDir, const AnsiString DcpSearchPath);
	virtual bool __fastcall InstallDelphiPackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath);
	virtual bool __fastcall UninstallDelphiPackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath);
	virtual bool __fastcall InstallBCBPackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath);
	virtual bool __fastcall UninstallBCBPackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath);
	virtual bool __fastcall InstallDelphiIdePackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath);
	virtual bool __fastcall UninstallDelphiIdePackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath);
	virtual bool __fastcall InstallBCBIdePackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath);
	virtual bool __fastcall UninstallBCBIdePackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath);
	virtual bool __fastcall InstallDelphiExpert(const AnsiString ProjectName, const AnsiString OutputDir, const AnsiString DcpSearchPath);
	virtual bool __fastcall UninstallDelphiExpert(const AnsiString ProjectName, const AnsiString OutputDir);
	virtual bool __fastcall InstallBCBExpert(const AnsiString ProjectName, const AnsiString OutputDir, const AnsiString DcpSearchPath);
	virtual bool __fastcall UninstallBCBExpert(const AnsiString ProjectName, const AnsiString OutputDir);
	void __fastcall ReadInformation(void);
	bool __fastcall RemoveFromPath(AnsiString &Path, const AnsiString ItemsToRemove);
	virtual AnsiString __fastcall GetDCPOutputPath();
	virtual AnsiString __fastcall GetBPLOutputPath();
	virtual Classes::TStrings* __fastcall GetEnvironmentVariables(void);
	virtual AnsiString __fastcall GetVclIncludeDir();
	virtual AnsiString __fastcall GetName();
	void __fastcall OutputString(const AnsiString AText);
	bool __fastcall OutputFileDelete(const AnsiString FileName);
	virtual void __fastcall SetOutputCallback(const Jclsysutils::TTextHandler Value);
	virtual AnsiString __fastcall GetDebugDCUPath();
	virtual void __fastcall SetDebugDCUPath(const AnsiString Value);
	virtual AnsiString __fastcall GetLibrarySearchPath();
	virtual void __fastcall SetLibrarySearchPath(const AnsiString Value);
	virtual AnsiString __fastcall GetLibraryBrowsingPath();
	virtual void __fastcall SetLibraryBrowsingPath(const AnsiString Value);
	virtual bool __fastcall GetValid(void);
	
public:
	__fastcall virtual TJclBorRADToolInstallation(const AnsiString AConfigDataLocation, unsigned ARootKey);
	__fastcall virtual ~TJclBorRADToolInstallation(void);
	/*         class method */ static void __fastcall ExtractPaths(TMetaClass* vmt, const AnsiString Path, Classes::TStrings* List);
	#pragma option push -w-inl
	/* virtual class method */ virtual int __fastcall GetLatestUpdatePackForVersion(int Version) { return GetLatestUpdatePackForVersion(__classid(TJclBorRADToolInstallation), Version); }
	#pragma option pop
	/*         class method */ static int __fastcall GetLatestUpdatePackForVersion(TMetaClass* vmt, int Version);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall PackageSourceFileExtension() { return PackageSourceFileExtension(__classid(TJclBorRADToolInstallation)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall PackageSourceFileExtension(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ProjectSourceFileExtension() { return ProjectSourceFileExtension(__classid(TJclBorRADToolInstallation)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ProjectSourceFileExtension(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual TJclBorRADToolKind __fastcall RadToolKind() { return RadToolKind(__classid(TJclBorRADToolInstallation)); }
	#pragma option pop
	/*         class method */ static TJclBorRADToolKind __fastcall RadToolKind(TMetaClass* vmt);
	virtual AnsiString __fastcall RadToolName();
	bool __fastcall AnyInstanceRunning(void);
	bool __fastcall AddToDebugDCUPath(const AnsiString Path);
	bool __fastcall AddToLibrarySearchPath(const AnsiString Path);
	bool __fastcall AddToLibraryBrowsingPath(const AnsiString Path);
	int __fastcall FindFolderInPath(AnsiString Folder, Classes::TStrings* List);
	virtual bool __fastcall CompilePackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath);
	virtual bool __fastcall InstallPackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath);
	virtual bool __fastcall UninstallPackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath);
	virtual bool __fastcall InstallIDEPackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath);
	virtual bool __fastcall UninstallIDEPackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath);
	virtual bool __fastcall CompileProject(const AnsiString ProjectName, const AnsiString OutputDir, const AnsiString DcpSearchPath);
	virtual bool __fastcall InstallExpert(const AnsiString ProjectName, const AnsiString OutputDir, const AnsiString DcpSearchPath);
	virtual bool __fastcall UninstallExpert(const AnsiString ProjectName, const AnsiString OutputDir);
	virtual bool __fastcall RegisterPackage(const AnsiString BinaryFileName, const AnsiString Description)/* overload */;
	virtual bool __fastcall RegisterPackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString Description)/* overload */;
	virtual bool __fastcall UnregisterPackage(const AnsiString BinaryFileName)/* overload */;
	virtual bool __fastcall UnregisterPackage(const AnsiString PackageName, const AnsiString BPLPath)/* overload */;
	virtual bool __fastcall RegisterIDEPackage(const AnsiString BinaryFileName, const AnsiString Description)/* overload */;
	virtual bool __fastcall RegisterIDEPackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString Description)/* overload */;
	virtual bool __fastcall UnregisterIDEPackage(const AnsiString BinaryFileName)/* overload */;
	virtual bool __fastcall UnregisterIDEPackage(const AnsiString PackageName, const AnsiString BPLPath)/* overload */;
	virtual bool __fastcall RegisterExpert(const AnsiString BinaryFileName, const AnsiString Description)/* overload */;
	virtual bool __fastcall RegisterExpert(const AnsiString ProjectName, const AnsiString OutputDir, const AnsiString Description)/* overload */;
	virtual bool __fastcall UnregisterExpert(const AnsiString BinaryFileName)/* overload */;
	virtual bool __fastcall UnregisterExpert(const AnsiString ProjectName, const AnsiString OutputDir)/* overload */;
	virtual AnsiString __fastcall GetDefaultProjectsDir();
	virtual AnsiString __fastcall GetCommonProjectsDir();
	bool __fastcall RemoveFromDebugDCUPath(const AnsiString Path);
	bool __fastcall RemoveFromLibrarySearchPath(const AnsiString Path);
	bool __fastcall RemoveFromLibraryBrowsingPath(const AnsiString Path);
	AnsiString __fastcall SubstitutePath(const AnsiString Path);
	bool __fastcall SupportsVisualCLX(void);
	bool __fastcall SupportsVCL(void);
	AnsiString __fastcall LibFolderName();
	AnsiString __fastcall ObjFolderName();
	AnsiString __fastcall LibDebugFolderName();
	__property TCommandLineTools CommandLineTools = {read=FCommandLineTools, nodefault};
	__property TJclBCC32* BCC32 = {read=GetBCC32};
	__property TJclDCC32* DCC32 = {read=GetDCC32};
	__property TJclBpr2Mak* Bpr2Mak = {read=GetBpr2Mak};
	__property Jclsysutils::_di_IJclCommandLineTool Make = {read=GetMake};
	__property AnsiString BinFolderName = {read=FBinFolderName};
	__property AnsiString BPLOutputPath = {read=GetBPLOutputPath};
	__property AnsiString DebugDCUPath = {read=GetDebugDCUPath, write=SetDebugDCUPath};
	__property AnsiString DCPOutputPath = {read=GetDCPOutputPath};
	__property AnsiString DefaultProjectsDir = {read=GetDefaultProjectsDir};
	__property AnsiString CommonProjectsDir = {read=GetCommonProjectsDir};
	__property AnsiString Description = {read=GetDescription};
	__property TJclBorRADToolEdition Edition = {read=FEdition, nodefault};
	__property AnsiString EditionAsText = {read=GetEditionAsText};
	__property Classes::TStrings* EnvironmentVariables = {read=GetEnvironmentVariables};
	__property TJclBorRADToolIdePackages* IdePackages = {read=GetIdePackages};
	__property TJclBorRADToolIdeTool* IdeTools = {read=FIdeTools};
	__property AnsiString IdeExeBuildNumber = {read=GetIdeExeBuildNumber};
	__property AnsiString IdeExeFileName = {read=GetIdeExeFileName};
	__property int InstalledUpdatePack = {read=FInstalledUpdatePack, nodefault};
	__property int LatestUpdatePack = {read=GetLatestUpdatePack, nodefault};
	__property AnsiString LibrarySearchPath = {read=GetLibrarySearchPath, write=SetLibrarySearchPath};
	__property AnsiString LibraryBrowsingPath = {read=GetLibraryBrowsingPath, write=SetLibraryBrowsingPath};
	__property TJclBorlandOpenHelp* OpenHelp = {read=FOpenHelp};
	__property bool MapCreate = {read=FMapCreate, write=FMapCreate, nodefault};
	__property bool JdbgCreate = {read=FJdbgCreate, write=FJdbgCreate, nodefault};
	__property bool JdbgInsert = {read=FJdbgInsert, write=FJdbgInsert, nodefault};
	__property bool MapDelete = {read=FMapDelete, write=FMapDelete, nodefault};
	__property Inifiles::TCustomIniFile* ConfigData = {read=FConfigData};
	__property AnsiString ConfigDataLocation = {read=FConfigDataLocation};
	__property Classes::TStrings* Globals = {read=GetGlobals};
	__property AnsiString Name = {read=GetName};
	__property TJclBorRADToolPalette* Palette = {read=GetPalette};
	__property TJclBorRADToolRepository* Repository = {read=GetRepository};
	__property AnsiString RootDir = {read=FRootDir};
	__property bool UpdateNeeded = {read=GetUpdateNeeded, nodefault};
	__property bool Valid = {read=GetValid, nodefault};
	__property AnsiString VclIncludeDir = {read=GetVclIncludeDir};
	__property int IDEVersionNumber = {read=FIDEVersionNumber, nodefault};
	__property AnsiString IDEVersionNumberStr = {read=FIDEVersionNumberStr};
	__property int VersionNumber = {read=FVersionNumber, nodefault};
	__property AnsiString VersionNumberStr = {read=FVersionNumberStr};
	__property TJclBorPersonalities Personalities = {read=FPersonalities, nodefault};
	__property bool SupportsLibSuffix = {read=GetSupportsLibSuffix, nodefault};
	__property Jclsysutils::TTextHandler OutputCallback = {read=FOutputCallback, write=SetOutputCallback};
	__property bool IsTurboExplorer = {read=GetIsTurboExplorer, nodefault};
	__property unsigned RootKey = {read=FRootKey, nodefault};
};



#pragma option push -b-
enum TJclHelp2Object { hoRegisterSession, hoRegister, hoPlugin };
#pragma option pop

typedef Set<TJclHelp2Object, hoRegisterSession, hoPlugin>  TJclHelp2Objects;

class DELPHICLASS TJclHelp2Manager;
class PASCALIMPLEMENTATION TJclHelp2Manager : public TJclBorRADToolInstallationObject 
{
	typedef TJclBorRADToolInstallationObject inherited;
	
private:
	Mshelpservices_tlb::_di_IHxRegisterSession FHxRegisterSession;
	Mshelpservices_tlb::_di_IHxRegister FHxRegister;
	Mshelpservices_tlb::_di_IHxPlugIn FHxPlugin;
	WideString FIdeNameSpace;
	bool __fastcall RequireObject(TJclHelp2Objects HelpObjects);
	Mshelpservices_tlb::_di_IHxPlugIn __fastcall GetHxPlugin();
	Mshelpservices_tlb::_di_IHxRegister __fastcall GetHxRegister();
	Mshelpservices_tlb::_di_IHxRegisterSession __fastcall GetHxRegisterSession();
	
public:
	__fastcall TJclHelp2Manager(void)/* overload */;
	__fastcall TJclHelp2Manager(TJclBorRADToolInstallation* AInstallation)/* overload */;
	__fastcall virtual ~TJclHelp2Manager(void);
	bool __fastcall CreateTransaction(void);
	bool __fastcall CommitTransaction(void);
	bool __fastcall RegisterNameSpace(const WideString Name, const WideString Collection, const WideString Description);
	bool __fastcall UnregisterNameSpace(const WideString Name);
	bool __fastcall RegisterHelpFile(const WideString NameSpace, const WideString Identifier, const int LangId, const WideString HxSFile, const WideString HxIFile);
	bool __fastcall UnregisterHelpFile(const WideString NameSpace, const WideString Identifier, const int LangId);
	bool __fastcall PlugNameSpaceIn(const WideString SourceNameSpace, const WideString TargetNameSpace);
	bool __fastcall UnPlugNameSpace(const WideString SourceNameSpace, const WideString TargetNameSpace);
	bool __fastcall PlugNameSpaceInBorlandHelp(const WideString NameSpace);
	bool __fastcall UnPlugNameSpaceFromBorlandHelp(const WideString NameSpace);
	__property Mshelpservices_tlb::_di_IHxRegisterSession HxRegisterSession = {read=GetHxRegisterSession};
	__property Mshelpservices_tlb::_di_IHxRegister HxRegister = {read=GetHxRegister};
	__property Mshelpservices_tlb::_di_IHxPlugIn HxPlugin = {read=GetHxPlugin};
	__property WideString IdeNamespace = {read=FIdeNameSpace};
};


struct TProjectOptions
{
	
public:
	bool UsePackages;
	AnsiString UnitOutputDir;
	AnsiString SearchPath;
	AnsiString DynamicPackages;
	AnsiString SearchDcpPath;
	AnsiString Conditionals;
} ;

class DELPHICLASS TJclBorlandMake;
class PASCALIMPLEMENTATION TJclBorlandMake : public TJclBorlandCommandLineTool 
{
	typedef TJclBorlandCommandLineTool inherited;
	
public:
	virtual AnsiString __fastcall GetExeName();
public:
	#pragma option push -w-inl
	/* TJclBorlandCommandLineTool.Create */ inline __fastcall virtual TJclBorlandMake(TJclBorRADToolInstallation* AInstallation) : TJclBorlandCommandLineTool(AInstallation) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclBorlandCommandLineTool.Destroy */ inline __fastcall virtual ~TJclBorlandMake(void) { }
	#pragma option pop
	
};


typedef TMetaClass* TJclBorRADToolInstallationClass;

class DELPHICLASS TJclBCBInstallation;
class PASCALIMPLEMENTATION TJclBCBInstallation : public TJclBorRADToolInstallation 
{
	typedef TJclBorRADToolInstallation inherited;
	
protected:
	virtual Classes::TStrings* __fastcall GetEnvironmentVariables(void);
	
public:
	__fastcall virtual TJclBCBInstallation(const AnsiString AConfigDataLocation, unsigned ARootKey);
	__fastcall virtual ~TJclBCBInstallation(void);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall PackageSourceFileExtension() { return PackageSourceFileExtension(__classid(TJclBCBInstallation)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall PackageSourceFileExtension(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ProjectSourceFileExtension() { return ProjectSourceFileExtension(__classid(TJclBCBInstallation)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ProjectSourceFileExtension(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual TJclBorRADToolKind __fastcall RadToolKind() { return RadToolKind(__classid(TJclBCBInstallation)); }
	#pragma option pop
	/*         class method */ static TJclBorRADToolKind __fastcall RadToolKind(TMetaClass* vmt);
	virtual AnsiString __fastcall RadToolName();
	#pragma option push -w-inl
	/* virtual class method */ virtual int __fastcall GetLatestUpdatePackForVersion(int Version) { return GetLatestUpdatePackForVersion(__classid(TJclBCBInstallation), Version); }
	#pragma option pop
	/*         class method */ static int __fastcall GetLatestUpdatePackForVersion(TMetaClass* vmt, int Version);
};


class DELPHICLASS TJclDelphiInstallation;
class PASCALIMPLEMENTATION TJclDelphiInstallation : public TJclBorRADToolInstallation 
{
	typedef TJclBorRADToolInstallation inherited;
	
protected:
	virtual Classes::TStrings* __fastcall GetEnvironmentVariables(void);
	
public:
	__fastcall virtual TJclDelphiInstallation(const AnsiString AConfigDataLocation, unsigned ARootKey);
	__fastcall virtual ~TJclDelphiInstallation(void);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall PackageSourceFileExtension() { return PackageSourceFileExtension(__classid(TJclDelphiInstallation)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall PackageSourceFileExtension(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ProjectSourceFileExtension() { return ProjectSourceFileExtension(__classid(TJclDelphiInstallation)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ProjectSourceFileExtension(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual TJclBorRADToolKind __fastcall RadToolKind() { return RadToolKind(__classid(TJclDelphiInstallation)); }
	#pragma option pop
	/*         class method */ static TJclBorRADToolKind __fastcall RadToolKind(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual int __fastcall GetLatestUpdatePackForVersion(int Version) { return GetLatestUpdatePackForVersion(__classid(TJclDelphiInstallation), Version); }
	#pragma option pop
	/*         class method */ static int __fastcall GetLatestUpdatePackForVersion(TMetaClass* vmt, int Version);
	HIDESBASE bool __fastcall InstallPackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath);
	virtual AnsiString __fastcall RadToolName();
};


class DELPHICLASS TJclDCCIL;
class PASCALIMPLEMENTATION TJclDCCIL : public TJclDCC32 
{
	typedef TJclDCC32 inherited;
	
private:
	AnsiString FMaxCLRVersion;
	
protected:
	AnsiString __fastcall GetMaxCLRVersion();
	
public:
	virtual AnsiString __fastcall GetExeName();
	HIDESBASE bool __fastcall MakeProject(const AnsiString ProjectName, const AnsiString OutputDir, const AnsiString ExtraOptions);
	virtual void __fastcall SetDefaultOptions(void);
	__property AnsiString MaxCLRVersion = {read=GetMaxCLRVersion};
public:
	#pragma option push -w-inl
	/* TJclDCC32.Create */ inline __fastcall virtual TJclDCCIL(TJclBorRADToolInstallation* AInstallation) : TJclDCC32(AInstallation) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclBorlandCommandLineTool.Destroy */ inline __fastcall virtual ~TJclDCCIL(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclBDSInstallation;
class PASCALIMPLEMENTATION TJclBDSInstallation : public TJclBorRADToolInstallation 
{
	typedef TJclBorRADToolInstallation inherited;
	
private:
	bool FDualPackageInstallation;
	TJclHelp2Manager* FHelp2Manager;
	TJclDCCIL* FDCCIL;
	bool FPdbCreate;
	void __fastcall SetDualPackageInstallation(const bool Value);
	AnsiString __fastcall GetCppPathsKeyName();
	AnsiString __fastcall GetCppBrowsingPath();
	AnsiString __fastcall GetCppSearchPath();
	AnsiString __fastcall GetCppLibraryPath();
	AnsiString __fastcall GetCppIncludePath();
	void __fastcall SetCppBrowsingPath(const AnsiString Value);
	void __fastcall SetCppSearchPath(const AnsiString Value);
	void __fastcall SetCppLibraryPath(const AnsiString Value);
	void __fastcall SetCppIncludePath(const AnsiString Value);
	AnsiString __fastcall GetMaxDelphiCLRVersion();
	TJclDCCIL* __fastcall GetDCCIL(void);
	AnsiString __fastcall GetMsBuildEnvOptionsFileName();
	AnsiString __fastcall GetMsBuildEnvOption(const AnsiString OptionName);
	void __fastcall SetMsBuildEnvOption(const AnsiString OptionName, const AnsiString Value);
	
protected:
	virtual AnsiString __fastcall GetDCPOutputPath();
	virtual AnsiString __fastcall GetBPLOutputPath();
	virtual Classes::TStrings* __fastcall GetEnvironmentVariables(void);
	virtual bool __fastcall CompileDelphiPackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath, const AnsiString ExtraOptions)/* overload */;
	virtual bool __fastcall CompileDelphiProject(const AnsiString ProjectName, const AnsiString OutputDir, const AnsiString DcpSearchPath);
	virtual AnsiString __fastcall GetVclIncludeDir();
	virtual AnsiString __fastcall GetName();
	virtual void __fastcall SetOutputCallback(const Jclsysutils::TTextHandler Value);
	virtual AnsiString __fastcall GetDebugDCUPath();
	virtual void __fastcall SetDebugDCUPath(const AnsiString Value);
	virtual AnsiString __fastcall GetLibrarySearchPath();
	virtual void __fastcall SetLibrarySearchPath(const AnsiString Value);
	virtual AnsiString __fastcall GetLibraryBrowsingPath();
	virtual void __fastcall SetLibraryBrowsingPath(const AnsiString Value);
	virtual bool __fastcall GetValid(void);
	
public:
	__fastcall virtual TJclBDSInstallation(const AnsiString AConfigDataLocation, unsigned ARootKey);
	__fastcall virtual ~TJclBDSInstallation(void);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall PackageSourceFileExtension() { return PackageSourceFileExtension(__classid(TJclBDSInstallation)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall PackageSourceFileExtension(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ProjectSourceFileExtension() { return ProjectSourceFileExtension(__classid(TJclBDSInstallation)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ProjectSourceFileExtension(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual TJclBorRADToolKind __fastcall RadToolKind() { return RadToolKind(__classid(TJclBDSInstallation)); }
	#pragma option pop
	/*         class method */ static TJclBorRADToolKind __fastcall RadToolKind(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual int __fastcall GetLatestUpdatePackForVersion(int Version) { return GetLatestUpdatePackForVersion(__classid(TJclBDSInstallation), Version); }
	#pragma option pop
	/*         class method */ static int __fastcall GetLatestUpdatePackForVersion(TMetaClass* vmt, int Version);
	virtual AnsiString __fastcall GetDefaultProjectsDir();
	virtual AnsiString __fastcall GetCommonProjectsDir();
	/*         class method */ static AnsiString __fastcall GetDefaultProjectsDirectory(TMetaClass* vmt, const AnsiString RootDir, int IDEVersionNumber);
	/*         class method */ static AnsiString __fastcall GetCommonProjectsDirectory(TMetaClass* vmt, const AnsiString RootDir, int IDEVersionNumber);
	virtual AnsiString __fastcall RadToolName();
	bool __fastcall AddToCppSearchPath(const AnsiString Path);
	bool __fastcall AddToCppBrowsingPath(const AnsiString Path);
	bool __fastcall AddToCppLibraryPath(const AnsiString Path);
	bool __fastcall AddToCppIncludePath(const AnsiString Path);
	bool __fastcall RemoveFromCppSearchPath(const AnsiString Path);
	bool __fastcall RemoveFromCppBrowsingPath(const AnsiString Path);
	bool __fastcall RemoveFromCppLibraryPath(const AnsiString Path);
	bool __fastcall RemoveFromCppIncludePath(const AnsiString Path);
	__property AnsiString CppSearchPath = {read=GetCppSearchPath, write=SetCppSearchPath};
	__property AnsiString CppBrowsingPath = {read=GetCppBrowsingPath, write=SetCppBrowsingPath};
	__property AnsiString CppLibraryPath = {read=GetCppLibraryPath, write=SetCppLibraryPath};
	__property AnsiString CppIncludePath = {read=GetCppIncludePath, write=SetCppIncludePath};
	virtual bool __fastcall RegisterPackage(const AnsiString BinaryFileName, const AnsiString Description)/* overload */;
	virtual bool __fastcall UnregisterPackage(const AnsiString BinaryFileName)/* overload */;
	bool __fastcall CleanPackageCache(const AnsiString BinaryFileName);
	bool __fastcall CompileDelphiDotNetProject(const AnsiString ProjectName, const AnsiString OutputDir, TJclBorPlatform PEFormat = (TJclBorPlatform)(0x0), const AnsiString ExtraOptions = "");
	__property bool DualPackageInstallation = {read=FDualPackageInstallation, write=SetDualPackageInstallation, nodefault};
	__property TJclHelp2Manager* Help2Manager = {read=FHelp2Manager};
	__property TJclDCCIL* DCCIL = {read=GetDCCIL};
	__property AnsiString MaxDelphiCLRVersion = {read=GetMaxDelphiCLRVersion};
	__property bool PdbCreate = {read=FPdbCreate, write=FPdbCreate, nodefault};
	
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CompileDelphiPackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString DCPPath){ return TJclBorRADToolInstallation::CompileDelphiPackage(PackageName, BPLPath, DCPPath); }
	
public:
	inline bool __fastcall  RegisterPackage(const AnsiString PackageName, const AnsiString BPLPath, const AnsiString Description){ return TJclBorRADToolInstallation::RegisterPackage(PackageName, BPLPath, Description); }
	inline bool __fastcall  UnregisterPackage(const AnsiString PackageName, const AnsiString BPLPath){ return TJclBorRADToolInstallation::UnregisterPackage(PackageName, BPLPath); }
	
};


typedef bool __fastcall (__closure *TTraverseMethod)(TJclBorRADToolInstallation* Installation);

class DELPHICLASS TJclBorRADToolInstallations;
class PASCALIMPLEMENTATION TJclBorRADToolInstallations : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TJclBorRADToolInstallation* operator[](int Index) { return Installations[Index]; }
	
private:
	Contnrs::TObjectList* FList;
	TJclBorRADToolInstallation* __fastcall GetBDSInstallationFromVersion(int VersionNumber);
	bool __fastcall GetBDSVersionInstalled(int VersionNumber);
	int __fastcall GetCount(void);
	TJclBorRADToolInstallation* __fastcall GetInstallations(int Index);
	bool __fastcall GetBCBVersionInstalled(int VersionNumber);
	bool __fastcall GetDelphiVersionInstalled(int VersionNumber);
	TJclBorRADToolInstallation* __fastcall GetBCBInstallationFromVersion(int VersionNumber);
	TJclBorRADToolInstallation* __fastcall GetDelphiInstallationFromVersion(int VersionNumber);
	
protected:
	void __fastcall ReadInstallations(void);
	
public:
	__fastcall TJclBorRADToolInstallations(void);
	__fastcall virtual ~TJclBorRADToolInstallations(void);
	bool __fastcall AnyInstanceRunning(void);
	bool __fastcall AnyUpdatePackNeeded(AnsiString &Text);
	bool __fastcall Iterate(TTraverseMethod TraverseMethod);
	__property int Count = {read=GetCount, nodefault};
	__property TJclBorRADToolInstallation* Installations[int Index] = {read=GetInstallations/*, default*/};
	__property TJclBorRADToolInstallation* BCBInstallationFromVersion[int VersionNumber] = {read=GetBCBInstallationFromVersion};
	__property TJclBorRADToolInstallation* DelphiInstallationFromVersion[int VersionNumber] = {read=GetDelphiInstallationFromVersion};
	__property TJclBorRADToolInstallation* BDSInstallationFromVersion[int VersionNumber] = {read=GetBDSInstallationFromVersion};
	__property bool BCBVersionInstalled[int VersionNumber] = {read=GetBCBVersionInstalled};
	__property bool DelphiVersionInstalled[int VersionNumber] = {read=GetDelphiVersionInstalled};
	__property bool BDSVersionInstalled[int VersionNumber] = {read=GetBDSVersionInstalled};
};


//-- var, const, procedure ---------------------------------------------------
#define SupportedDelphiVersions (Set<Byte, 0, 255> () << 0x5 << 0x6 << 0x7 << 0x8 << 0x9 << 0xa << 0xb << 0xc << 0xe )
#define SupportedBCBVersions (Set<Byte, 0, 255> () << 0x5 << 0x6 << 0xa << 0xb << 0xc << 0xe )
#define SupportedBDSVersions (Set<Byte, 0, 255> () << 0x1 << 0x2 << 0x3 << 0x4 << 0x5 << 0x6 << 0x7 )
#define BorRADToolRepositoryPagesSection "Repository Pages"
#define BorRADToolRepositoryDialogsPage "Dialogs"
#define BorRADToolRepositoryFormsPage "Forms"
#define BorRADToolRepositoryProjectsPage "Projects"
#define BorRADToolRepositoryDataModulesPage "Data Modules"
#define BorRADToolRepositoryObjectType "Type"
#define BorRADToolRepositoryFormTemplate "FormTemplate"
#define BorRADToolRepositoryProjectTemplate "ProjectTemplate"
#define BorRADToolRepositoryObjectName "Name"
#define BorRADToolRepositoryObjectPage "Page"
#define BorRADToolRepositoryObjectIcon "Icon"
#define BorRADToolRepositoryObjectDescr "Description"
#define BorRADToolRepositoryObjectAuthor "Author"
#define BorRADToolRepositoryObjectAncestor "Ancestor"
#define BorRADToolRepositoryObjectDesigner "Designer"
#define BorRADToolRepositoryDesignerDfm "dfm"
#define BorRADToolRepositoryDesignerXfm "xfm"
#define BorRADToolRepositoryObjectNewForm "DefaultNewForm"
#define BorRADToolRepositoryObjectMainForm "DefaultMainForm"
#define SourceExtensionDelphiPackage ".dpk"
#define SourceExtensionBCBPackage ".bpk"
#define SourceExtensionDelphiProject ".dpr"
#define SourceExtensionBCBProject ".bpr"
#define SourceExtensionBDSProject ".bdsproj"
#define SourceExtensionDProject ".dproj"
#define BinaryExtensionPackage ".bpl"
#define BinaryExtensionLibrary ".dll"
#define BinaryExtensionExecutable ".exe"
#define CompilerExtensionDCP ".dcp"
#define CompilerExtensionBPI ".bpi"
#define CompilerExtensionLIB ".lib"
#define CompilerExtensionTDS ".tds"
#define CompilerExtensionMAP ".map"
#define CompilerExtensionDRC ".drc"
#define CompilerExtensionDEF ".def"
#define SourceExtensionCPP ".cpp"
#define SourceExtensionH ".h"
#define SourceExtensionPAS ".pas"
#define SourceExtensionDFM ".dfm"
#define SourceExtensionXFM ".xfm"
#define SourceDescriptionPAS "Pascal source file"
#define SourceDescriptionCPP "C++ source file"
#define DesignerVCL "VCL"
#define DesignerCLX "CLX"
#define ProjectTypePackage "package"
#define ProjectTypeLibrary "library"
#define ProjectTypeProgram "program"
#define Personality32Bit "32 bit"
#define Personality64Bit "64 bit"
#define PersonalityDelphi "Delphi"
#define PersonalityDelphiDotNet "Delphi.net"
#define PersonalityBCB "C++Builder"
#define PersonalityCSB "C#Builder"
#define PersonalityVB "Visual Basic"
#define PersonalityDesign "Design"
#define PersonalityUnknown "Unknown personality"
#define PersonalityBDS "Borland Developer Studio"
#define DOFDirectoriesSection "Directories"
#define DOFUnitOutputDirKey "UnitOutputDir"
#define DOFSearchPathName "SearchPath"
#define DOFConditionals "Conditionals"
#define DOFLinkerSection "Linker"
#define DOFPackagesKey "Packages"
#define DOFCompilerSection "Compiler"
#define DOFPackageNoLinkKey "PackageNoLink"
#define DOFAdditionalSection "Additional"
#define DOFOptionsKey "Options"
extern PACKAGE char *BorRADToolEditionIDs[4];
extern PACKAGE AnsiString JclBorPersonalityDescription[12];
extern PACKAGE AnsiString JclBorDesignerDescription[2];
extern PACKAGE AnsiString JclBorDesignerFormExtension[2];
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE void __fastcall GetDPRFileInfo(const AnsiString DPRFileName, /* out */ AnsiString &BinaryExtension, const System::PAnsiString LibSuffix = (void *)(0x0));
extern PACKAGE void __fastcall GetBPRFileInfo(const AnsiString BPRFileName, /* out */ AnsiString &BinaryFileName, const System::PAnsiString Description = (void *)(0x0));
extern PACKAGE void __fastcall GetDPKFileInfo(const AnsiString DPKFileName, /* out */ bool &RunOnly, const System::PAnsiString LibSuffix = (void *)(0x0), const System::PAnsiString Description = (void *)(0x0));
extern PACKAGE void __fastcall GetBPKFileInfo(const AnsiString BPKFileName, /* out */ bool &RunOnly, const System::PAnsiString BinaryFileName = (void *)(0x0), const System::PAnsiString Description = (void *)(0x0));
extern PACKAGE AnsiString __fastcall BinaryFileName(const AnsiString OutputPath, const AnsiString ProjectFileName);
extern PACKAGE bool __fastcall IsDelphiPackage(const AnsiString FileName);
extern PACKAGE bool __fastcall IsDelphiProject(const AnsiString FileName);
extern PACKAGE bool __fastcall IsBCBPackage(const AnsiString FileName);
extern PACKAGE bool __fastcall IsBCBProject(const AnsiString FileName);

}	/* namespace Jclborlandtools */
using namespace Jclborlandtools;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclborlandtools
