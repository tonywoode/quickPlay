// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclfileutils.pas' rev: 10.00

#ifndef JclfileutilsHPP
#define JclfileutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Jclwin32.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclfileutils
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TCompactPath { cpCenter, cpEnd };
#pragma option pop

typedef bool __fastcall (*TDelTreeProgress)(const AnsiString FileName, unsigned Attr);

#pragma option push -b-
enum TFileListOption { flFullNames, flRecursive, flMaskedSubfolders };
#pragma option pop

typedef Set<TFileListOption, flFullNames, flMaskedSubfolders>  TFileListOptions;

#pragma option push -b-
enum TJclAttributeMatch { amAny, amExact, amSubSetOf, amSuperSetOf, amCustom };
#pragma option pop

typedef bool __fastcall (*TFileMatchFunc)(const int Attr, const Sysutils::TSearchRec &FileInfo);

typedef void __fastcall (__closure *TFileHandler)(const AnsiString FileName);

typedef void __fastcall (__closure *TFileHandlerEx)(const AnsiString Directory, const Sysutils::TSearchRec &FileInfo);

typedef void __fastcall (__closure *TFileInfoHandlerEx)(const Sysutils::TSearchRec &FileInfo);

#pragma option push -b-
enum TAttributeInterest { aiIgnored, aiRejected, aiRequired };
#pragma option pop

class DELPHICLASS TJclCustomFileAttrMask;
class PASCALIMPLEMENTATION TJclCustomFileAttrMask : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
public:
	TAttributeInterest operator[](int Index) { return Attribute[Index]; }
	
private:
	int FRequiredAttr;
	int FRejectedAttr;
	TAttributeInterest __fastcall GetAttr(int Index);
	void __fastcall SetAttr(int Index, const TAttributeInterest Value);
	void __fastcall ReadRequiredAttributes(Classes::TReader* Reader);
	void __fastcall ReadRejectedAttributes(Classes::TReader* Reader);
	void __fastcall WriteRequiredAttributes(Classes::TWriter* Writer);
	void __fastcall WriteRejectedAttributes(Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	__property TAttributeInterest ReadOnly = {read=GetAttr, write=SetAttr, stored=false, index=1, nodefault};
	__property TAttributeInterest Hidden = {read=GetAttr, write=SetAttr, stored=false, index=2, nodefault};
	__property TAttributeInterest System = {read=GetAttr, write=SetAttr, stored=false, index=4, nodefault};
	__property TAttributeInterest Directory = {read=GetAttr, write=SetAttr, stored=false, index=16, nodefault};
	__property TAttributeInterest SymLink = {read=GetAttr, write=SetAttr, stored=false, index=64, nodefault};
	__property TAttributeInterest Normal = {read=GetAttr, write=SetAttr, stored=false, index=128, nodefault};
	__property TAttributeInterest Archive = {read=GetAttr, write=SetAttr, stored=false, index=32, nodefault};
	__property TAttributeInterest Temporary = {read=GetAttr, write=SetAttr, stored=false, index=256, nodefault};
	__property TAttributeInterest SparseFile = {read=GetAttr, write=SetAttr, stored=false, index=512, nodefault};
	__property TAttributeInterest ReparsePoint = {read=GetAttr, write=SetAttr, stored=false, index=1024, nodefault};
	__property TAttributeInterest Compressed = {read=GetAttr, write=SetAttr, stored=false, index=2048, nodefault};
	__property TAttributeInterest OffLine = {read=GetAttr, write=SetAttr, stored=false, index=4096, nodefault};
	__property TAttributeInterest NotContentIndexed = {read=GetAttr, write=SetAttr, stored=false, index=8192, nodefault};
	__property TAttributeInterest Encrypted = {read=GetAttr, write=SetAttr, stored=false, index=16384, nodefault};
	
public:
	__fastcall TJclCustomFileAttrMask(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Clear(void);
	bool __fastcall Match(int FileAttributes)/* overload */;
	bool __fastcall Match(const Sysutils::TSearchRec &FileInfo)/* overload */;
	__property int Required = {read=FRequiredAttr, write=FRequiredAttr, nodefault};
	__property int Rejected = {read=FRejectedAttr, write=FRejectedAttr, nodefault};
	__property TAttributeInterest Attribute[int Index] = {read=GetAttr, write=SetAttr/*, default*/};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TJclCustomFileAttrMask(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclFileAttributeMask;
class PASCALIMPLEMENTATION TJclFileAttributeMask : public TJclCustomFileAttrMask 
{
	typedef TJclCustomFileAttrMask inherited;
	
private:
	void __fastcall ReadVolumeID(Classes::TReader* Reader);
	
protected:
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	
__published:
	__property ReadOnly ;
	__property Hidden ;
	__property System ;
	__property Directory ;
	__property Normal ;
	__property Archive ;
	__property Temporary ;
	__property SparseFile ;
	__property ReparsePoint ;
	__property Compressed ;
	__property OffLine ;
	__property NotContentIndexed ;
	__property Encrypted ;
public:
	#pragma option push -w-inl
	/* TJclCustomFileAttrMask.Create */ inline __fastcall TJclFileAttributeMask(void) : TJclCustomFileAttrMask() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TJclFileAttributeMask(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TFileSearchOption { fsIncludeSubDirectories, fsIncludeHiddenSubDirectories, fsLastChangeAfter, fsLastChangeBefore, fsMaxSize, fsMinSize };
#pragma option pop

typedef Set<TFileSearchOption, fsIncludeSubDirectories, fsMinSize>  TFileSearchOptions;

typedef int TFileSearchTaskID;

typedef void __fastcall (__closure *TFileSearchTerminationEvent)(const int ID, const bool Aborted);

#pragma option push -b-
enum TFileEnumeratorSyncMode { smPerFile, smPerDirectory };
#pragma option pop

__interface IJclFileEnumerator;
typedef System::DelphiInterface<IJclFileEnumerator> _di_IJclFileEnumerator;
__interface  INTERFACE_UUID("{F7E747ED-1C41-441F-B25B-BB314E00C4E9}") IJclFileEnumerator  : public IInterface 
{
	
public:
	virtual TJclFileAttributeMask* __fastcall GetAttributeMask(void) = 0 ;
	virtual bool __fastcall GetCaseSensitiveSearch(void) = 0 ;
	virtual Classes::TStrings* __fastcall GetRootDirectories(void) = 0 ;
	virtual AnsiString __fastcall GetRootDirectory(void) = 0 ;
	virtual AnsiString __fastcall GetFileMask(void) = 0 ;
	virtual Classes::TStrings* __fastcall GetFileMasks(void) = 0 ;
	virtual __int64 __fastcall GetFileSizeMax(void) = 0 ;
	virtual __int64 __fastcall GetFileSizeMin(void) = 0 ;
	virtual bool __fastcall GetIncludeSubDirectories(void) = 0 ;
	virtual bool __fastcall GetIncludeHiddenSubDirectories(void) = 0 ;
	virtual System::TDateTime __fastcall GetLastChangeAfter(void) = 0 ;
	virtual System::TDateTime __fastcall GetLastChangeBefore(void) = 0 ;
	virtual AnsiString __fastcall GetLastChangeAfterStr(void) = 0 ;
	virtual AnsiString __fastcall GetLastChangeBeforeStr(void) = 0 ;
	virtual int __fastcall GetRunningTasks(void) = 0 ;
	virtual AnsiString __fastcall GetSubDirectoryMask(void) = 0 ;
	virtual TFileEnumeratorSyncMode __fastcall GetSynchronizationMode(void) = 0 ;
	virtual TFileHandler __fastcall GetOnEnterDirectory(void) = 0 ;
	virtual TFileSearchTerminationEvent __fastcall GetOnTerminateTask(void) = 0 ;
	virtual bool __fastcall GetOption(const TFileSearchOption Option) = 0 ;
	virtual TFileSearchOptions __fastcall GetOptions(void) = 0 ;
	virtual void __fastcall SetAttributeMask(const TJclFileAttributeMask* Value) = 0 ;
	virtual void __fastcall SetCaseSensitiveSearch(const bool Value) = 0 ;
	virtual void __fastcall SetRootDirectories(const Classes::TStrings* Value) = 0 ;
	virtual void __fastcall SetRootDirectory(const AnsiString Value) = 0 ;
	virtual void __fastcall SetFileMask(const AnsiString Value) = 0 ;
	virtual void __fastcall SetFileMasks(const Classes::TStrings* Value) = 0 ;
	virtual void __fastcall SetFileSizeMax(const __int64 Value) = 0 ;
	virtual void __fastcall SetFileSizeMin(const __int64 Value) = 0 ;
	virtual void __fastcall SetIncludeSubDirectories(const bool Value) = 0 ;
	virtual void __fastcall SetIncludeHiddenSubDirectories(const bool Value) = 0 ;
	virtual void __fastcall SetLastChangeAfter(const System::TDateTime Value) = 0 ;
	virtual void __fastcall SetLastChangeBefore(const System::TDateTime Value) = 0 ;
	virtual void __fastcall SetLastChangeAfterStr(const AnsiString Value) = 0 ;
	virtual void __fastcall SetLastChangeBeforeStr(const AnsiString Value) = 0 ;
	virtual void __fastcall SetOption(const TFileSearchOption Option, const bool Value) = 0 ;
	virtual void __fastcall SetOptions(const TFileSearchOptions Value) = 0 ;
	virtual void __fastcall SetSubDirectoryMask(const AnsiString Value) = 0 ;
	virtual void __fastcall SetSynchronizationMode(const TFileEnumeratorSyncMode Value) = 0 ;
	virtual void __fastcall SetOnEnterDirectory(const TFileHandler Value) = 0 ;
	virtual void __fastcall SetOnTerminateTask(const TFileSearchTerminationEvent Value) = 0 ;
	virtual int __fastcall FillList(Classes::TStrings* List) = 0 ;
	virtual int __fastcall ForEach(TFileHandler Handler) = 0 /* overload */;
	virtual int __fastcall ForEach(TFileHandlerEx Handler) = 0 /* overload */;
	virtual void __fastcall StopTask(int ID) = 0 ;
	virtual void __fastcall StopAllTasks(bool Silently = false) = 0 ;
	__property bool CaseSensitiveSearch = {read=GetCaseSensitiveSearch, write=SetCaseSensitiveSearch};
	__property Classes::TStrings* RootDirectories = {read=GetRootDirectories, write=SetRootDirectories};
	__property AnsiString RootDirectory = {read=GetRootDirectory, write=SetRootDirectory};
	__property AnsiString FileMask = {read=GetFileMask, write=SetFileMask};
	__property AnsiString SubDirectoryMask = {read=GetSubDirectoryMask, write=SetSubDirectoryMask};
	__property TJclFileAttributeMask* AttributeMask = {read=GetAttributeMask, write=SetAttributeMask};
	__property __int64 FileSizeMin = {read=GetFileSizeMin, write=SetFileSizeMin};
	__property __int64 FileSizeMax = {read=GetFileSizeMax, write=SetFileSizeMax};
	__property System::TDateTime LastChangeAfter = {read=GetLastChangeAfter, write=SetLastChangeAfter};
	__property System::TDateTime LastChangeBefore = {read=GetLastChangeBefore, write=SetLastChangeBefore};
	__property AnsiString LastChangeAfterAsString = {read=GetLastChangeAfterStr, write=SetLastChangeAfterStr};
	__property AnsiString LastChangeBeforeAsString = {read=GetLastChangeBeforeStr, write=SetLastChangeBeforeStr};
	__property bool IncludeSubDirectories = {read=GetIncludeSubDirectories, write=SetIncludeSubDirectories};
	__property bool IncludeHiddenSubDirectories = {read=GetIncludeHiddenSubDirectories, write=SetIncludeHiddenSubDirectories};
	__property int RunningTasks = {read=GetRunningTasks};
	__property TFileEnumeratorSyncMode SynchronizationMode = {read=GetSynchronizationMode, write=SetSynchronizationMode};
	__property TFileHandler OnEnterDirectory = {read=GetOnEnterDirectory, write=SetOnEnterDirectory};
	__property TFileSearchTerminationEvent OnTerminateTask = {read=GetOnTerminateTask, write=SetOnTerminateTask};
};

class DELPHICLASS TJclFileEnumerator;
class PASCALIMPLEMENTATION TJclFileEnumerator : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	System::_di_IInterface FOwnerInterface;
	Classes::TList* FTasks;
	Classes::TStringList* FFileMasks;
	Classes::TStringList* FRootDirectories;
	AnsiString FSubDirectoryMask;
	TFileHandler FOnEnterDirectory;
	TFileSearchTerminationEvent FOnTerminateTask;
	int FNextTaskID;
	TJclFileAttributeMask* FAttributeMask;
	TFileEnumeratorSyncMode FSynchronizationMode;
	__int64 FFileSizeMin;
	__int64 FFileSizeMax;
	System::TDateTime FLastChangeBefore;
	System::TDateTime FLastChangeAfter;
	TFileSearchOptions FOptions;
	bool FCaseSensitiveSearch;
	bool __fastcall IsLastChangeAfterStored(void);
	bool __fastcall IsLastChangeBeforeStored(void);
	int __fastcall GetNextTaskID(void);
	bool __fastcall GetCaseSensitiveSearch(void);
	void __fastcall SetCaseSensitiveSearch(const bool Value);
	
protected:
	int FRefCount;
	Classes::TThread* __fastcall CreateTask(void);
	void __fastcall TaskTerminated(System::TObject* Sender);
	__property int NextTaskID = {read=GetNextTaskID, nodefault};
	
public:
	__fastcall TJclFileEnumerator(void);
	__fastcall virtual ~TJclFileEnumerator(void);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	TJclFileAttributeMask* __fastcall GetAttributeMask(void);
	Classes::TStrings* __fastcall GetRootDirectories(void);
	AnsiString __fastcall GetRootDirectory();
	AnsiString __fastcall GetFileMask();
	Classes::TStrings* __fastcall GetFileMasks(void);
	__int64 __fastcall GetFileSizeMax(void);
	__int64 __fastcall GetFileSizeMin(void);
	bool __fastcall GetIncludeSubDirectories(void);
	bool __fastcall GetIncludeHiddenSubDirectories(void);
	System::TDateTime __fastcall GetLastChangeAfter(void);
	System::TDateTime __fastcall GetLastChangeBefore(void);
	AnsiString __fastcall GetLastChangeAfterStr();
	AnsiString __fastcall GetLastChangeBeforeStr();
	bool __fastcall GetOption(const TFileSearchOption Option);
	TFileSearchOptions __fastcall GetOptions(void);
	int __fastcall GetRunningTasks(void);
	AnsiString __fastcall GetSubDirectoryMask();
	TFileEnumeratorSyncMode __fastcall GetSynchronizationMode(void);
	TFileHandler __fastcall GetOnEnterDirectory();
	TFileSearchTerminationEvent __fastcall GetOnTerminateTask();
	void __fastcall SetAttributeMask(const TJclFileAttributeMask* Value);
	void __fastcall SetRootDirectories(const Classes::TStrings* Value);
	void __fastcall SetRootDirectory(const AnsiString Value);
	void __fastcall SetFileMask(const AnsiString Value);
	void __fastcall SetFileMasks(const Classes::TStrings* Value);
	void __fastcall SetFileSizeMax(const __int64 Value);
	void __fastcall SetFileSizeMin(const __int64 Value);
	void __fastcall SetIncludeSubDirectories(const bool Value);
	void __fastcall SetIncludeHiddenSubDirectories(const bool Value);
	void __fastcall SetLastChangeAfter(const System::TDateTime Value);
	void __fastcall SetLastChangeBefore(const System::TDateTime Value);
	void __fastcall SetLastChangeAfterStr(const AnsiString Value);
	void __fastcall SetLastChangeBeforeStr(const AnsiString Value);
	void __fastcall SetOption(const TFileSearchOption Option, const bool Value);
	void __fastcall SetOptions(const TFileSearchOptions Value);
	void __fastcall SetSubDirectoryMask(const AnsiString Value);
	void __fastcall SetSynchronizationMode(const TFileEnumeratorSyncMode Value);
	void __fastcall SetOnEnterDirectory(const TFileHandler Value);
	void __fastcall SetOnTerminateTask(const TFileSearchTerminationEvent Value);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	int __fastcall FillList(Classes::TStrings* List);
	int __fastcall ForEach(TFileHandler Handler)/* overload */;
	int __fastcall ForEach(TFileHandlerEx Handler)/* overload */;
	void __fastcall StopTask(int ID);
	void __fastcall StopAllTasks(bool Silently = false);
	__property AnsiString FileMask = {read=GetFileMask, write=SetFileMask};
	__property bool IncludeSubDirectories = {read=GetIncludeSubDirectories, write=SetIncludeSubDirectories, nodefault};
	__property bool IncludeHiddenSubDirectories = {read=GetIncludeHiddenSubDirectories, write=SetIncludeHiddenSubDirectories, nodefault};
	__property bool SearchOption[TFileSearchOption Option] = {read=GetOption, write=SetOption};
	__property AnsiString LastChangeAfterAsString = {read=GetLastChangeAfterStr, write=SetLastChangeAfterStr};
	__property AnsiString LastChangeBeforeAsString = {read=GetLastChangeBeforeStr, write=SetLastChangeBeforeStr};
	
__published:
	__property bool CaseSensitiveSearch = {read=GetCaseSensitiveSearch, write=SetCaseSensitiveSearch, default=0};
	__property Classes::TStrings* FileMasks = {read=GetFileMasks, write=SetFileMasks};
	__property Classes::TStrings* RootDirectories = {read=GetRootDirectories, write=SetRootDirectories};
	__property AnsiString RootDirectory = {read=GetRootDirectory, write=SetRootDirectory};
	__property AnsiString SubDirectoryMask = {read=FSubDirectoryMask, write=FSubDirectoryMask};
	__property TJclFileAttributeMask* AttributeMask = {read=FAttributeMask, write=SetAttributeMask};
	__property __int64 FileSizeMin = {read=FFileSizeMin, write=FFileSizeMin};
	__property __int64 FileSizeMax = {read=FFileSizeMax, write=FFileSizeMax};
	__property System::TDateTime LastChangeAfter = {read=FLastChangeAfter, write=FLastChangeAfter, stored=IsLastChangeAfterStored};
	__property System::TDateTime LastChangeBefore = {read=FLastChangeBefore, write=FLastChangeBefore, stored=IsLastChangeBeforeStored};
	__property TFileSearchOptions Options = {read=FOptions, write=FOptions, default=1};
	__property int RunningTasks = {read=GetRunningTasks, nodefault};
	__property TFileEnumeratorSyncMode SynchronizationMode = {read=FSynchronizationMode, write=FSynchronizationMode, default=1};
	__property TFileHandler OnEnterDirectory = {read=FOnEnterDirectory, write=FOnEnterDirectory};
	__property TFileSearchTerminationEvent OnTerminateTask = {read=FOnTerminateTask, write=FOnTerminateTask};
private:
	void *__IJclFileEnumerator;	/* Jclfileutils::IJclFileEnumerator */
	
public:
	operator IJclFileEnumerator*(void) { return (IJclFileEnumerator*)&__IJclFileEnumerator; }
	
};


#pragma option push -b-
enum TFileFlag { ffDebug, ffInfoInferred, ffPatched, ffPreRelease, ffPrivateBuild, ffSpecialBuild };
#pragma option pop

typedef Set<TFileFlag, ffDebug, ffSpecialBuild>  TFileFlags;

struct TLangIdRec;
typedef TLangIdRec *PLangIdRec;

#pragma pack(push,1)
struct TLangIdRec
{
	
	union
	{
		struct 
		{
			unsigned Pair;
			
		};
		struct 
		{
			Word LangId;
			Word CodePage;
			
		};
		
	};
} ;
#pragma pack(pop)

class DELPHICLASS EJclFileVersionInfoError;
class PASCALIMPLEMENTATION EJclFileVersionInfoError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclFileVersionInfoError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclFileVersionInfoError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclFileVersionInfoError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclFileVersionInfoError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclFileVersionInfoError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclFileVersionInfoError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclFileVersionInfoError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclFileVersionInfoError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclFileVersionInfoError(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TLangIdRec >  JclFileUtils__6;

typedef DynamicArray<TLangIdRec >  JclFileUtils__7;

class DELPHICLASS TJclFileVersionInfo;
class PASCALIMPLEMENTATION TJclFileVersionInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FBuffer;
	tagVS_FIXEDFILEINFO *FFixedInfo;
	TFileFlags FFileFlags;
	Classes::TStringList* FItemList;
	Classes::TStringList* FItems;
	DynamicArray<TLangIdRec >  FLanguages;
	int FLanguageIndex;
	DynamicArray<TLangIdRec >  FTranslations;
	tagVS_FIXEDFILEINFO __fastcall GetFixedInfo();
	Classes::TStrings* __fastcall GetItems(void);
	int __fastcall GetLanguageCount(void);
	AnsiString __fastcall GetLanguageIds(int Index);
	AnsiString __fastcall GetLanguageNames(int Index);
	TLangIdRec __fastcall GetLanguages(int Index);
	int __fastcall GetTranslationCount(void);
	TLangIdRec __fastcall GetTranslations(int Index);
	void __fastcall SetLanguageIndex(const int Value);
	
protected:
	void __fastcall CreateItemsForLanguage(void);
	void __fastcall CheckLanguageIndex(int Value);
	void __fastcall ExtractData(void);
	void __fastcall ExtractFlags(void);
	AnsiString __fastcall GetBinFileVersion();
	AnsiString __fastcall GetBinProductVersion();
	unsigned __fastcall GetFileOS(void);
	unsigned __fastcall GetFileSubType(void);
	unsigned __fastcall GetFileType(void);
	AnsiString __fastcall GetFileVersionBuild();
	AnsiString __fastcall GetFileVersionMajor();
	AnsiString __fastcall GetFileVersionMinor();
	AnsiString __fastcall GetFileVersionRelease();
	AnsiString __fastcall GetProductVersionBuild();
	AnsiString __fastcall GetProductVersionMajor();
	AnsiString __fastcall GetProductVersionMinor();
	AnsiString __fastcall GetProductVersionRelease();
	AnsiString __fastcall GetVersionKeyValue(int Index);
	
public:
	__fastcall TJclFileVersionInfo(void * VersionInfoData, int Size);
	__fastcall TJclFileVersionInfo(const AnsiString FileName)/* overload */;
	__fastcall TJclFileVersionInfo(const HWND Window)/* overload */;
	__fastcall TJclFileVersionInfo(const unsigned Module)/* overload */;
	__fastcall virtual ~TJclFileVersionInfo(void);
	AnsiString __fastcall GetCustomFieldValue(const AnsiString FieldName);
	/*         class method */ static AnsiString __fastcall VersionLanguageId(TMetaClass* vmt, const TLangIdRec LangIdRec);
	/*         class method */ static AnsiString __fastcall VersionLanguageName(TMetaClass* vmt, const Word LangId);
	bool __fastcall TranslationMatchesLanguages(bool Exact = true);
	__property AnsiString BinFileVersion = {read=GetBinFileVersion};
	__property AnsiString BinProductVersion = {read=GetBinProductVersion};
	__property AnsiString Comments = {read=GetVersionKeyValue, index=1};
	__property AnsiString CompanyName = {read=GetVersionKeyValue, index=2};
	__property AnsiString FileDescription = {read=GetVersionKeyValue, index=3};
	__property tagVS_FIXEDFILEINFO FixedInfo = {read=GetFixedInfo};
	__property TFileFlags FileFlags = {read=FFileFlags, nodefault};
	__property unsigned FileOS = {read=GetFileOS, nodefault};
	__property unsigned FileSubType = {read=GetFileSubType, nodefault};
	__property unsigned FileType = {read=GetFileType, nodefault};
	__property AnsiString FileVersion = {read=GetVersionKeyValue, index=4};
	__property AnsiString FileVersionBuild = {read=GetFileVersionBuild};
	__property AnsiString FileVersionMajor = {read=GetFileVersionMajor};
	__property AnsiString FileVersionMinor = {read=GetFileVersionMinor};
	__property AnsiString FileVersionRelease = {read=GetFileVersionRelease};
	__property Classes::TStrings* Items = {read=GetItems};
	__property AnsiString InternalName = {read=GetVersionKeyValue, index=5};
	__property int LanguageCount = {read=GetLanguageCount, nodefault};
	__property AnsiString LanguageIds[int Index] = {read=GetLanguageIds};
	__property int LanguageIndex = {read=FLanguageIndex, write=SetLanguageIndex, nodefault};
	__property TLangIdRec Languages[int Index] = {read=GetLanguages};
	__property AnsiString LanguageNames[int Index] = {read=GetLanguageNames};
	__property AnsiString LegalCopyright = {read=GetVersionKeyValue, index=6};
	__property AnsiString LegalTradeMarks = {read=GetVersionKeyValue, index=7};
	__property AnsiString OriginalFilename = {read=GetVersionKeyValue, index=8};
	__property AnsiString PrivateBuild = {read=GetVersionKeyValue, index=12};
	__property AnsiString ProductName = {read=GetVersionKeyValue, index=9};
	__property AnsiString ProductVersion = {read=GetVersionKeyValue, index=10};
	__property AnsiString ProductVersionBuild = {read=GetProductVersionBuild};
	__property AnsiString ProductVersionMajor = {read=GetProductVersionMajor};
	__property AnsiString ProductVersionMinor = {read=GetProductVersionMinor};
	__property AnsiString ProductVersionRelease = {read=GetProductVersionRelease};
	__property AnsiString SpecialBuild = {read=GetVersionKeyValue, index=11};
	__property int TranslationCount = {read=GetTranslationCount, nodefault};
	__property TLangIdRec Translations[int Index] = {read=GetTranslations};
};


#pragma option push -b-
enum TFileVersionFormat { vfMajorMinor, vfFull };
#pragma option pop

class DELPHICLASS TJclTempFileStream;
class PASCALIMPLEMENTATION TJclTempFileStream : public Classes::THandleStream 
{
	typedef Classes::THandleStream inherited;
	
private:
	AnsiString FFileName;
	
public:
	__fastcall TJclTempFileStream(const AnsiString Prefix);
	__fastcall virtual ~TJclTempFileStream(void);
	__property AnsiString FileName = {read=FFileName};
};


class DELPHICLASS TJclFileMappingView;
class DELPHICLASS TJclCustomFileMapping;
#pragma option push -b-
enum TJclFileMappingRoundOffset { rvDown, rvUp };
#pragma option pop

class PASCALIMPLEMENTATION TJclCustomFileMapping : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	bool FExisted;
	unsigned FHandle;
	AnsiString FName;
	TJclFileMappingRoundOffset FRoundViewOffset;
	Classes::TList* FViews;
	int __fastcall GetCount(void);
	TJclFileMappingView* __fastcall GetView(int Index);
	
protected:
	void __fastcall ClearViews(void);
	void __fastcall InternalCreate(const unsigned FileHandle, const AnsiString Name, const unsigned Protect, __int64 MaximumSize, Windows::PSecurityAttributes SecAttr);
	void __fastcall InternalOpen(const AnsiString Name, const bool InheritHandle, const unsigned DesiredAccess);
	
public:
	__fastcall TJclCustomFileMapping(void);
	__fastcall TJclCustomFileMapping(const AnsiString Name, const bool InheritHandle, const unsigned DesiredAccess);
	__fastcall virtual ~TJclCustomFileMapping(void);
	int __fastcall Add(const unsigned Access, const unsigned Count, const __int64 Offset);
	int __fastcall AddAt(const unsigned Access, const unsigned Count, const __int64 Offset, const void * Address);
	void __fastcall Delete(const int Index);
	int __fastcall IndexOf(const TJclFileMappingView* View);
	__property int Count = {read=GetCount, nodefault};
	__property bool Existed = {read=FExisted, nodefault};
	__property unsigned Handle = {read=FHandle, nodefault};
	__property AnsiString Name = {read=FName};
	__property TJclFileMappingRoundOffset RoundViewOffset = {read=FRoundViewOffset, write=FRoundViewOffset, nodefault};
	__property TJclFileMappingView* Views[int index] = {read=GetView};
};


class PASCALIMPLEMENTATION TJclFileMappingView : public Classes::TCustomMemoryStream 
{
	typedef Classes::TCustomMemoryStream inherited;
	
private:
	TJclCustomFileMapping* FFileMapping;
	unsigned FOffsetHigh;
	unsigned FOffsetLow;
	int __fastcall GetIndex(void);
	__int64 __fastcall GetOffset(void);
	
public:
	__fastcall TJclFileMappingView(const TJclCustomFileMapping* FileMap, unsigned Access, unsigned Size, __int64 ViewOffset);
	__fastcall TJclFileMappingView(TJclCustomFileMapping* FileMap, unsigned Access, unsigned Size, __int64 ViewOffset, void * Address);
	__fastcall virtual ~TJclFileMappingView(void);
	bool __fastcall Flush(const unsigned Count);
	void __fastcall LoadFromStream(const Classes::TStream* Stream);
	void __fastcall LoadFromFile(const AnsiString FileName);
	virtual int __fastcall Write(const void *Buffer, int Count);
	__property int Index = {read=GetIndex, nodefault};
	__property TJclCustomFileMapping* FileMapping = {read=FFileMapping};
	__property __int64 Offset = {read=GetOffset};
};


class DELPHICLASS TJclFileMapping;
class PASCALIMPLEMENTATION TJclFileMapping : public TJclCustomFileMapping 
{
	typedef TJclCustomFileMapping inherited;
	
private:
	unsigned FFileHandle;
	
public:
	__fastcall TJclFileMapping(const AnsiString FileName, unsigned FileMode, const AnsiString Name, unsigned Protect, const __int64 MaximumSize, Windows::PSecurityAttributes SecAttr)/* overload */;
	__fastcall TJclFileMapping(const unsigned FileHandle, const AnsiString Name, unsigned Protect, const __int64 MaximumSize, Windows::PSecurityAttributes SecAttr)/* overload */;
	__fastcall virtual ~TJclFileMapping(void);
	__property unsigned FileHandle = {read=FFileHandle, nodefault};
public:
	#pragma option push -w-inl
	/* TJclCustomFileMapping.Open */ inline __fastcall TJclFileMapping(const AnsiString Name, const bool InheritHandle, const unsigned DesiredAccess) : TJclCustomFileMapping(Name, InheritHandle, DesiredAccess) { }
	#pragma option pop
	
};


class DELPHICLASS TJclSwapFileMapping;
class PASCALIMPLEMENTATION TJclSwapFileMapping : public TJclCustomFileMapping 
{
	typedef TJclCustomFileMapping inherited;
	
public:
	__fastcall TJclSwapFileMapping(const AnsiString Name, unsigned Protect, const __int64 MaximumSize, Windows::PSecurityAttributes SecAttr);
public:
	#pragma option push -w-inl
	/* TJclCustomFileMapping.Open */ inline __fastcall TJclSwapFileMapping(const AnsiString Name, const bool InheritHandle, const unsigned DesiredAccess) : TJclCustomFileMapping(Name, InheritHandle, DesiredAccess) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclCustomFileMapping.Destroy */ inline __fastcall virtual ~TJclSwapFileMapping(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclFileMappingStream;
class PASCALIMPLEMENTATION TJclFileMappingStream : public Classes::TCustomMemoryStream 
{
	typedef Classes::TCustomMemoryStream inherited;
	
private:
	unsigned FFileHandle;
	unsigned FMapping;
	
protected:
	void __fastcall Close(void);
	
public:
	__fastcall TJclFileMappingStream(const AnsiString FileName, Word FileMode);
	__fastcall virtual ~TJclFileMappingStream(void);
	virtual int __fastcall Write(const void *Buffer, int Count);
};


#pragma option push -b-
enum TJclMappedTextReaderIndex { tiNoIndex, tiFull };
#pragma option pop

typedef char *TPAnsiCharArray[1];

typedef char * *PPAnsiCharArray;

class DELPHICLASS TJclAnsiMappedTextReader;
class PASCALIMPLEMENTATION TJclAnsiMappedTextReader : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	char *FContent;
	char *FEnd;
	char * *FIndex;
	TJclMappedTextReaderIndex FIndexOption;
	bool FFreeStream;
	int FLastLineNumber;
	char *FLastPosition;
	int FLineCount;
	Classes::TCustomMemoryStream* FMemoryStream;
	char *FPosition;
	int FSize;
	AnsiString __fastcall GetAsString();
	bool __fastcall GetEof(void);
	char __fastcall GetChars(int Index);
	int __fastcall GetLineCount(void);
	AnsiString __fastcall GetLines(int LineNumber);
	int __fastcall GetPosition(void);
	int __fastcall GetPositionFromLine(int LineNumber);
	void __fastcall SetPosition(const int Value);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	void __fastcall CreateIndex(void);
	void __fastcall Init(void);
	char * __fastcall PtrFromLine(int LineNumber);
	AnsiString __fastcall StringFromPosition(char * &StartPos);
	
public:
	__fastcall TJclAnsiMappedTextReader(Classes::TCustomMemoryStream* MemoryStream, bool FreeStream, const TJclMappedTextReaderIndex AIndexOption)/* overload */;
	__fastcall TJclAnsiMappedTextReader(const AnsiString FileName, const TJclMappedTextReaderIndex AIndexOption)/* overload */;
	__fastcall virtual ~TJclAnsiMappedTextReader(void);
	void __fastcall GoBegin(void);
	char __fastcall Read(void);
	AnsiString __fastcall ReadLn();
	__property AnsiString AsString = {read=GetAsString};
	__property char Chars[int Index] = {read=GetChars};
	__property char * Content = {read=FContent};
	__property bool Eof = {read=GetEof, nodefault};
	__property TJclMappedTextReaderIndex IndexOption = {read=FIndexOption, nodefault};
	__property AnsiString Lines[int LineNumber] = {read=GetLines};
	__property int LineCount = {read=GetLineCount, nodefault};
	__property int PositionFromLine[int LineNumber] = {read=GetPositionFromLine};
	__property int Position = {read=GetPosition, write=SetPosition, nodefault};
	__property int Size = {read=FSize, nodefault};
};


typedef WideChar *TPWideCharArray[1];

typedef WideChar * *PPWideCharArray;

class DELPHICLASS TJclWideMappedTextReader;
class PASCALIMPLEMENTATION TJclWideMappedTextReader : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	WideChar *FContent;
	WideChar *FEnd;
	WideChar * *FIndex;
	TJclMappedTextReaderIndex FIndexOption;
	bool FFreeStream;
	int FLastLineNumber;
	WideChar *FLastPosition;
	int FLineCount;
	Classes::TCustomMemoryStream* FMemoryStream;
	WideChar *FPosition;
	int FSize;
	WideString __fastcall GetAsString();
	bool __fastcall GetEof(void);
	WideChar __fastcall GetChars(int Index);
	int __fastcall GetLineCount(void);
	WideString __fastcall GetLines(int LineNumber);
	int __fastcall GetPosition(void);
	int __fastcall GetPositionFromLine(int LineNumber);
	void __fastcall SetPosition(const int Value);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	void __fastcall CreateIndex(void);
	void __fastcall Init(void);
	WideChar * __fastcall PtrFromLine(int LineNumber);
	WideString __fastcall StringFromPosition(WideChar * &StartPos);
	
public:
	__fastcall TJclWideMappedTextReader(Classes::TCustomMemoryStream* MemoryStream, bool FreeStream, const TJclMappedTextReaderIndex AIndexOption)/* overload */;
	__fastcall TJclWideMappedTextReader(const AnsiString FileName, const TJclMappedTextReaderIndex AIndexOption)/* overload */;
	__fastcall virtual ~TJclWideMappedTextReader(void);
	void __fastcall GoBegin(void);
	WideChar __fastcall Read(void);
	WideString __fastcall ReadLn();
	__property WideString AsString = {read=GetAsString};
	__property WideChar Chars[int Index] = {read=GetChars};
	__property WideChar * Content = {read=FContent};
	__property bool Eof = {read=GetEof, nodefault};
	__property TJclMappedTextReaderIndex IndexOption = {read=FIndexOption, nodefault};
	__property WideString Lines[int LineNumber] = {read=GetLines};
	__property int LineCount = {read=GetLineCount, nodefault};
	__property int PositionFromLine[int LineNumber] = {read=GetPositionFromLine};
	__property int Position = {read=GetPosition, write=SetPosition, nodefault};
	__property int Size = {read=FSize, nodefault};
};


typedef DynamicArray<AnsiString >  JclFileUtils__71;

typedef DynamicArray<AnsiString >  JclFileUtils__81;

typedef DynamicArray<Byte >  JclFileUtils__91;

class DELPHICLASS TJclFileMaskComparator;
class PASCALIMPLEMENTATION TJclFileMaskComparator : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FFileMask;
	DynamicArray<AnsiString >  FExts;
	DynamicArray<AnsiString >  FNames;
	DynamicArray<Byte >  FWildChars;
	char FSeparator;
	void __fastcall CreateMultiMasks(void);
	int __fastcall GetCount(void);
	AnsiString __fastcall GetExts(int Index);
	AnsiString __fastcall GetMasks(int Index);
	AnsiString __fastcall GetNames(int Index);
	void __fastcall SetFileMask(const AnsiString Value);
	void __fastcall SetSeparator(const char Value);
	
public:
	__fastcall TJclFileMaskComparator(void);
	bool __fastcall Compare(const AnsiString NameExt);
	__property int Count = {read=GetCount, nodefault};
	__property AnsiString Exts[int Index] = {read=GetExts};
	__property AnsiString FileMask = {read=FFileMask, write=SetFileMask};
	__property AnsiString Masks[int Index] = {read=GetMasks};
	__property AnsiString Names[int Index] = {read=GetNames};
	__property char Separator = {read=FSeparator, write=SetSeparator, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclFileMaskComparator(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclPathError;
class PASCALIMPLEMENTATION EJclPathError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclPathError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclPathError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclPathError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclPathError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclPathError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclPathError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclPathError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclPathError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclPathError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclFileUtilsError;
class PASCALIMPLEMENTATION EJclFileUtilsError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclFileUtilsError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclFileUtilsError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclFileUtilsError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclFileUtilsError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclFileUtilsError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclFileUtilsError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclFileUtilsError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclFileUtilsError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclFileUtilsError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclTempFileStreamError;
class PASCALIMPLEMENTATION EJclTempFileStreamError : public Jclwin32::EJclWin32Error 
{
	typedef Jclwin32::EJclWin32Error inherited;
	
public:
	#pragma option push -w-inl
	/* EJclWin32Error.Create */ inline __fastcall EJclTempFileStreamError(const AnsiString Msg) : Jclwin32::EJclWin32Error(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* EJclWin32Error.CreateFmt */ inline __fastcall EJclTempFileStreamError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclwin32::EJclWin32Error(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* EJclWin32Error.CreateRes */ inline __fastcall EJclTempFileStreamError(int Ident)/* overload */ : Jclwin32::EJclWin32Error(Ident) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclTempFileStreamError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclwin32::EJclWin32Error(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclTempFileStreamError(const AnsiString Msg, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclTempFileStreamError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclTempFileStreamError(int Ident, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclTempFileStreamError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclTempFileStreamError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclFileMappingError;
class PASCALIMPLEMENTATION EJclFileMappingError : public Jclwin32::EJclWin32Error 
{
	typedef Jclwin32::EJclWin32Error inherited;
	
public:
	#pragma option push -w-inl
	/* EJclWin32Error.Create */ inline __fastcall EJclFileMappingError(const AnsiString Msg) : Jclwin32::EJclWin32Error(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* EJclWin32Error.CreateFmt */ inline __fastcall EJclFileMappingError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclwin32::EJclWin32Error(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* EJclWin32Error.CreateRes */ inline __fastcall EJclFileMappingError(int Ident)/* overload */ : Jclwin32::EJclWin32Error(Ident) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclFileMappingError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclwin32::EJclWin32Error(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclFileMappingError(const AnsiString Msg, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclFileMappingError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclFileMappingError(int Ident, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclFileMappingError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclFileMappingError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclFileMappingViewError;
class PASCALIMPLEMENTATION EJclFileMappingViewError : public Jclwin32::EJclWin32Error 
{
	typedef Jclwin32::EJclWin32Error inherited;
	
public:
	#pragma option push -w-inl
	/* EJclWin32Error.Create */ inline __fastcall EJclFileMappingViewError(const AnsiString Msg) : Jclwin32::EJclWin32Error(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* EJclWin32Error.CreateFmt */ inline __fastcall EJclFileMappingViewError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclwin32::EJclWin32Error(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* EJclWin32Error.CreateRes */ inline __fastcall EJclFileMappingViewError(int Ident)/* overload */ : Jclwin32::EJclWin32Error(Ident) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclFileMappingViewError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclwin32::EJclWin32Error(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclFileMappingViewError(const AnsiString Msg, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclFileMappingViewError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclFileMappingViewError(int Ident, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclFileMappingViewError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclFileMappingViewError(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define PathDevicePrefix "\\\\.\\"
static const char DirDelimiter = '\x5c';
static const char DirSeparator = '\x3b';
#define PathUncPrefix "\\\\"
static const Shortint faSymLink = 0x40;
static const Byte faNormalFile = 0x80;
static const Word faTemporary = 0x100;
static const Word faSparseFile = 0x200;
static const Word faReparsePoint = 0x400;
static const Word faCompressed = 0x800;
static const Word faOffline = 0x1000;
static const Word faNotContentIndexed = 0x2000;
static const Word faEncrypted = 0x4000;
static const Shortint faRejectedByDefault = 0x16;
static const Word faWindowsSpecific = 0x7f20;
static const Shortint faUnixSpecific = 0x40;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE bool __fastcall CharIsDriveLetter(const char C);
extern PACKAGE AnsiString __fastcall PathAddSeparator(const AnsiString Path);
extern PACKAGE AnsiString __fastcall PathAddExtension(const AnsiString Path, const AnsiString Extension);
extern PACKAGE AnsiString __fastcall PathAppend(const AnsiString Path, const AnsiString Append);
extern PACKAGE AnsiString __fastcall PathBuildRoot(const Byte Drive);
extern PACKAGE AnsiString __fastcall PathCanonicalize(const AnsiString Path);
extern PACKAGE int __fastcall PathCommonPrefix(const AnsiString Path1, const AnsiString Path2);
extern PACKAGE AnsiString __fastcall PathCompactPath(const HDC DC, const AnsiString Path, const int Width, TCompactPath CmpFmt);
extern PACKAGE void __fastcall PathExtractElements(const AnsiString Source, AnsiString &Drive, AnsiString &Path, AnsiString &FileName, AnsiString &Ext);
extern PACKAGE AnsiString __fastcall PathExtractFileDirFixed(const AnsiString S);
extern PACKAGE AnsiString __fastcall PathExtractFileNameNoExt(const AnsiString Path);
extern PACKAGE AnsiString __fastcall PathExtractPathDepth(const AnsiString Path, int Depth);
extern PACKAGE int __fastcall PathGetDepth(const AnsiString Path);
extern PACKAGE AnsiString __fastcall PathGetLongName(const AnsiString Path);
extern PACKAGE AnsiString __fastcall PathGetShortName(const AnsiString Path);
extern PACKAGE AnsiString __fastcall PathGetRelativePath(AnsiString Origin, AnsiString Destination);
extern PACKAGE AnsiString __fastcall PathGetTempPath();
extern PACKAGE bool __fastcall PathIsAbsolute(const AnsiString Path);
extern PACKAGE bool __fastcall PathIsChild(const AnsiString Path, const AnsiString Base);
extern PACKAGE bool __fastcall PathIsDiskDevice(const AnsiString Path);
extern PACKAGE bool __fastcall PathIsUNC(const AnsiString Path);
extern PACKAGE AnsiString __fastcall PathRemoveSeparator(const AnsiString Path);
extern PACKAGE AnsiString __fastcall PathRemoveExtension(const AnsiString Path);
extern PACKAGE AnsiString __fastcall PathGetPhysicalPath(const AnsiString LocalizedPath);
extern PACKAGE AnsiString __fastcall PathGetLocalizedPath(const AnsiString PhysicalPath);
extern PACKAGE bool __fastcall BuildFileList(const AnsiString Path, const int Attr, const Classes::TStrings* List);
extern PACKAGE void __fastcall CreateEmptyFile(const AnsiString FileName);
extern PACKAGE bool __fastcall CloseVolume(unsigned &Volume);
extern PACKAGE bool __fastcall DeleteDirectory(const AnsiString DirectoryName, bool MoveToRecycleBin);
extern PACKAGE bool __fastcall CopyDirectory(AnsiString ExistingDirectoryName, AnsiString NewDirectoryName);
extern PACKAGE bool __fastcall MoveDirectory(AnsiString ExistingDirectoryName, AnsiString NewDirectoryName);
extern PACKAGE bool __fastcall DelTree(const AnsiString Path);
extern PACKAGE bool __fastcall DelTreeEx(const AnsiString Path, bool AbortOnFailure, TDelTreeProgress Progress);
extern PACKAGE bool __fastcall DirectoryExists(const AnsiString Name);
extern PACKAGE bool __fastcall DiskInDrive(char Drive);
extern PACKAGE unsigned __fastcall FileCreateTemp(AnsiString &Prefix);
extern PACKAGE bool __fastcall FileBackup(const AnsiString FileName, bool Move = false);
extern PACKAGE bool __fastcall FileCopy(const AnsiString ExistingFileName, const AnsiString NewFileName, bool ReplaceExisting = false);
extern PACKAGE bool __fastcall FileDelete(const AnsiString FileName, bool MoveToRecycleBin = false);
extern PACKAGE bool __fastcall FileExists(const AnsiString FileName);
extern PACKAGE bool __fastcall FileMove(const AnsiString ExistingFileName, const AnsiString NewFileName, bool ReplaceExisting = false);
extern PACKAGE bool __fastcall FileRestore(const AnsiString FileName);
extern PACKAGE AnsiString __fastcall GetBackupFileName(const AnsiString FileName);
extern PACKAGE bool __fastcall IsBackupFileName(const AnsiString FileName);
extern PACKAGE AnsiString __fastcall FileGetDisplayName(const AnsiString FileName);
extern PACKAGE AnsiString __fastcall FileGetGroupName(const AnsiString FileName);
extern PACKAGE AnsiString __fastcall FileGetOwnerName(const AnsiString FileName);
extern PACKAGE __int64 __fastcall FileGetSize(const AnsiString FileName);
extern PACKAGE AnsiString __fastcall FileGetTempName(const AnsiString Prefix);
extern PACKAGE AnsiString __fastcall FileGetTypeName(const AnsiString FileName);
extern PACKAGE AnsiString __fastcall FindUnusedFileName(AnsiString FileName, const AnsiString FileExt, AnsiString NumberPrefix = "");
extern PACKAGE bool __fastcall ForceDirectories(AnsiString Name);
extern PACKAGE __int64 __fastcall GetDirectorySize(const AnsiString Path);
extern PACKAGE AnsiString __fastcall GetDriveTypeStr(const char Drive);
extern PACKAGE bool __fastcall GetFileAgeCoherence(const AnsiString FileName);
extern PACKAGE void __fastcall GetFileAttributeList(const Classes::TStrings* Items, const int Attr);
extern PACKAGE void __fastcall GetFileAttributeListEx(const Classes::TStrings* Items, const int Attr);
extern PACKAGE bool __fastcall GetFileInformation(const AnsiString FileName, /* out */ Sysutils::TSearchRec &FileInfo)/* overload */;
extern PACKAGE Sysutils::TSearchRec __fastcall GetFileInformation(const AnsiString FileName)/* overload */;
extern PACKAGE _FILETIME __fastcall GetFileLastWrite(const AnsiString FileName)/* overload */;
extern PACKAGE bool __fastcall GetFileLastWrite(const AnsiString FileName, /* out */ System::TDateTime &LocalTime)/* overload */;
extern PACKAGE _FILETIME __fastcall GetFileLastAccess(const AnsiString FileName)/* overload */;
extern PACKAGE bool __fastcall GetFileLastAccess(const AnsiString FileName, /* out */ System::TDateTime &LocalTime)/* overload */;
extern PACKAGE _FILETIME __fastcall GetFileCreation(const AnsiString FileName)/* overload */;
extern PACKAGE bool __fastcall GetFileCreation(const AnsiString FileName, /* out */ System::TDateTime &LocalTime)/* overload */;
extern PACKAGE AnsiString __fastcall GetModulePath(const unsigned Module);
extern PACKAGE __int64 __fastcall GetSizeOfFile(const AnsiString FileName)/* overload */;
extern PACKAGE __int64 __fastcall GetSizeOfFile(unsigned Handle)/* overload */;
extern PACKAGE __int64 __fastcall GetSizeOfFile(const Sysutils::TSearchRec &FileInfo)/* overload */;
extern PACKAGE _WIN32_FILE_ATTRIBUTE_DATA __fastcall GetStandardFileInfo(const AnsiString FileName);
extern PACKAGE bool __fastcall IsDirectory(const AnsiString FileName);
extern PACKAGE bool __fastcall IsRootDirectory(const AnsiString CanonicFileName);
extern PACKAGE bool __fastcall LockVolume(const AnsiString Volume, unsigned &Handle);
extern PACKAGE unsigned __fastcall OpenVolume(const char Drive);
extern PACKAGE bool __fastcall SetFileLastAccess(const AnsiString FileName, const System::TDateTime DateTime);
extern PACKAGE bool __fastcall SetFileLastWrite(const AnsiString FileName, const System::TDateTime DateTime);
extern PACKAGE bool __fastcall SetFileCreation(const AnsiString FileName, const System::TDateTime DateTime);
extern PACKAGE bool __fastcall SetDirLastWrite(const AnsiString DirName, const System::TDateTime DateTime);
extern PACKAGE bool __fastcall SetDirLastAccess(const AnsiString DirName, const System::TDateTime DateTime);
extern PACKAGE bool __fastcall SetDirCreation(const AnsiString DirName, const System::TDateTime DateTime);
extern PACKAGE void __fastcall ShredFile(const AnsiString FileName, int Times = 0x1);
extern PACKAGE bool __fastcall UnlockVolume(unsigned &Handle);
extern PACKAGE AnsiString __fastcall OSIdentToString(const unsigned OSIdent);
extern PACKAGE AnsiString __fastcall OSFileTypeToString(const unsigned OSFileType, const unsigned OSFileSubType = (unsigned)(0x0));
extern PACKAGE bool __fastcall VersionResourceAvailable(const AnsiString FileName);
extern PACKAGE AnsiString __fastcall FormatVersionString(const Word HiV, const Word LoV)/* overload */;
extern PACKAGE AnsiString __fastcall FormatVersionString(const Word Major, const Word Minor, const Word Build, const Word Revision)/* overload */;
extern PACKAGE AnsiString __fastcall FormatVersionString(const tagVS_FIXEDFILEINFO &FixedInfo, TFileVersionFormat VersionFormat = (TFileVersionFormat)(0x1))/* overload */;
extern PACKAGE void __fastcall VersionExtractFileInfo(const tagVS_FIXEDFILEINFO &FixedInfo, Word &Major, Word &Minor, Word &Build, Word &Revision);
extern PACKAGE void __fastcall VersionExtractProductInfo(const tagVS_FIXEDFILEINFO &FixedInfo, Word &Major, Word &Minor, Word &Build, Word &Revision);
extern PACKAGE bool __fastcall VersionFixedFileInfo(const AnsiString FileName, tagVS_FIXEDFILEINFO &FixedInfo);
extern PACKAGE AnsiString __fastcall VersionFixedFileInfoString(const AnsiString FileName, TFileVersionFormat VersionFormat = (TFileVersionFormat)(0x1), const AnsiString NotAvailableText = "");
extern PACKAGE bool __fastcall AdvBuildFileList(const AnsiString Path, const int Attr, const Classes::TStrings* Files, const TJclAttributeMatch AttributeMatch = (TJclAttributeMatch)(0x3), const TFileListOptions Options = Set<TFileListOption, flFullNames, flMaskedSubfolders> () , const AnsiString SubfoldersMask = "", const TFileMatchFunc FileMatchFunc = 0x0);
extern PACKAGE bool __fastcall VerifyFileAttributeMask(int &RejectedAttributes, int &RequiredAttributes);
extern PACKAGE bool __fastcall IsFileAttributeMatch(int FileAttributes, int RejectedAttributes, int RequiredAttributes);
extern PACKAGE AnsiString __fastcall FileAttributesStr(const Sysutils::TSearchRec &FileInfo);
extern PACKAGE bool __fastcall IsFileNameMatch(AnsiString FileName, const AnsiString Mask, const bool CaseSensitive = false);
extern PACKAGE void __fastcall EnumFiles(const AnsiString Path, TFileHandlerEx HandleFile, int RejectedAttributes = 0x16, int RequiredAttributes = 0x0, System::PBoolean Abort = (void *)(0x0))/* overload */;
extern PACKAGE void __fastcall EnumFiles(const AnsiString Path, TFileInfoHandlerEx HandleFile, int RejectedAttributes = 0x16, int RequiredAttributes = 0x0, System::PBoolean Abort = (void *)(0x0))/* overload */;
extern PACKAGE void __fastcall EnumDirectories(const AnsiString Root, const TFileHandler HandleDirectory, const bool IncludeHiddenDirectories = false, const AnsiString SubDirectoriesMask = "", System::PBoolean Abort = (void *)(0x0));
extern PACKAGE _di_IJclFileEnumerator __fastcall FileSearch();
extern PACKAGE bool __fastcall SamePath(const AnsiString Path1, const AnsiString Path2);
extern PACKAGE void __fastcall PathListAddItems(AnsiString &List, const AnsiString Items);
extern PACKAGE void __fastcall PathListIncludeItems(AnsiString &List, const AnsiString Items);
extern PACKAGE void __fastcall PathListDelItems(AnsiString &List, const AnsiString Items);
extern PACKAGE void __fastcall PathListDelItem(AnsiString &List, const int Index);
extern PACKAGE int __fastcall PathListItemCount(const AnsiString List);
extern PACKAGE AnsiString __fastcall PathListGetItem(const AnsiString List, const int Index);
extern PACKAGE void __fastcall PathListSetItem(AnsiString &List, const int Index, const AnsiString Value);
extern PACKAGE int __fastcall PathListItemIndex(const AnsiString List, const AnsiString Item);
extern PACKAGE AnsiString __fastcall ParamName(int Index, const AnsiString Separator = "=", const AnsiString AllowedPrefixCharacters = "-/", bool TrimName = true);
extern PACKAGE AnsiString __fastcall ParamValue(int Index, const AnsiString Separator = "=", bool TrimValue = true)/* overload */;
extern PACKAGE AnsiString __fastcall ParamValue(const AnsiString SearchName, const AnsiString Separator = "=", bool CaseSensitive = false, const AnsiString AllowedPrefixCharacters = "-/", bool TrimValue = true)/* overload */;
extern PACKAGE int __fastcall ParamPos(const AnsiString SearchName, const AnsiString Separator = "=", bool CaseSensitive = false, const AnsiString AllowedPrefixCharacters = "-/");

}	/* namespace Jclfileutils */
using namespace Jclfileutils;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclfileutils
