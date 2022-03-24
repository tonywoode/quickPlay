// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclpeimage.pas' rev: 10.00

#ifndef JclpeimageHPP
#define JclpeimageHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Typinfo.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jcldatetime.hpp>	// Pascal unit
#include <Jclfileutils.hpp>	// Pascal unit
#include <Jclsysinfo.hpp>	// Pascal unit
#include <Jclwin32.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclpeimage
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TJclSmartCompOption { scSimpleCompare, scIgnoreCase };
#pragma option pop

typedef Set<TJclSmartCompOption, scSimpleCompare, scIgnoreCase>  TJclSmartCompOptions;

class DELPHICLASS EJclPeImageError;
class PASCALIMPLEMENTATION EJclPeImageError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclPeImageError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclPeImageError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclPeImageError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclPeImageError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclPeImageError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclPeImageError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclPeImageError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclPeImageError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclPeImageError(void) { }
	#pragma option pop
	
};


typedef TMetaClass* TJclPeImageClass;

class DELPHICLASS TJclPeImageBaseList;
class DELPHICLASS TJclPeImage;
class DELPHICLASS TJclPeCertificateList;
class PASCALIMPLEMENTATION TJclPeImageBaseList : public Contnrs::TObjectList 
{
	typedef Contnrs::TObjectList inherited;
	
private:
	TJclPeImage* FImage;
	
public:
	__fastcall TJclPeImageBaseList(TJclPeImage* AImage);
	__property TJclPeImage* Image = {read=FImage};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TJclPeImageBaseList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclPeCertificate;
class PASCALIMPLEMENTATION TJclPeCertificateList : public TJclPeImageBaseList 
{
	typedef TJclPeImageBaseList inherited;
	
public:
	TJclPeCertificate* operator[](int Index) { return Items[Index]; }
	
private:
	TJclPeCertificate* __fastcall GetItems(int Index);
	
protected:
	void __fastcall CreateList(void);
	
public:
	__fastcall TJclPeCertificateList(TJclPeImage* AImage);
	__property TJclPeCertificate* Items[int Index] = {read=GetItems/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TJclPeCertificateList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclPeCLRHeader;
class PASCALIMPLEMENTATION TJclPeCLRHeader : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Jclwin32::IMAGE_COR20_HEADER FHeader;
	TJclPeImage* FImage;
	AnsiString __fastcall GetVersionString();
	bool __fastcall GetHasMetadata(void);
	
protected:
	void __fastcall ReadHeader(void);
	
public:
	__fastcall TJclPeCLRHeader(TJclPeImage* AImage);
	__property bool HasMetadata = {read=GetHasMetadata, nodefault};
	__property Jclwin32::IMAGE_COR20_HEADER Header = {read=FHeader};
	__property AnsiString VersionString = {read=GetVersionString};
	__property TJclPeImage* Image = {read=FImage};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclPeCLRHeader(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclPeDebugList;
class PASCALIMPLEMENTATION TJclPeDebugList : public TJclPeImageBaseList 
{
	typedef TJclPeImageBaseList inherited;
	
public:
	_IMAGE_DEBUG_DIRECTORY operator[](int Index) { return Items[Index]; }
	
private:
	_IMAGE_DEBUG_DIRECTORY __fastcall GetItems(int Index);
	
protected:
	void __fastcall CreateList(void);
	
public:
	__fastcall TJclPeDebugList(TJclPeImage* AImage);
	__property _IMAGE_DEBUG_DIRECTORY Items[int Index] = {read=GetItems/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TJclPeDebugList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclPeExportFuncList;
#pragma option push -b-
enum TJclPeExportSort { esName, esOrdinal, esHint, esAddress, esForwarded, esAddrOrFwd, esSection };
#pragma option pop

#pragma option push -b-
enum TJclPeResolveCheck { icNotChecked, icResolved, icUnresolved };
#pragma option pop

class DELPHICLASS TJclPeExportFuncItem;
class DELPHICLASS TJclPeImagesCache;
class PASCALIMPLEMENTATION TJclPeExportFuncList : public TJclPeImageBaseList 
{
	typedef TJclPeImageBaseList inherited;
	
public:
	TJclPeExportFuncItem* operator[](int Index) { return Items[Index]; }
	
private:
	bool FAnyForwards;
	unsigned FBase;
	_IMAGE_EXPORT_DIRECTORY *FExportDir;
	Classes::TStringList* FForwardedLibsList;
	unsigned FFunctionCount;
	TJclPeExportSort FLastSortType;
	bool FLastSortDescending;
	bool FSorted;
	TJclPeResolveCheck FTotalResolveCheck;
	Classes::TStrings* __fastcall GetForwardedLibsList(void);
	TJclPeExportFuncItem* __fastcall GetItems(int Index);
	TJclPeExportFuncItem* __fastcall GetItemFromAddress(unsigned Address);
	TJclPeExportFuncItem* __fastcall GetItemFromOrdinal(unsigned Ordinal);
	TJclPeExportFuncItem* __fastcall GetItemFromName(const AnsiString Name);
	AnsiString __fastcall GetName();
	
protected:
	bool __fastcall CanPerformFastNameSearch(void);
	void __fastcall CreateList(void);
	__property TJclPeExportSort LastSortType = {read=FLastSortType, nodefault};
	__property bool LastSortDescending = {read=FLastSortDescending, nodefault};
	__property bool Sorted = {read=FSorted, nodefault};
	
public:
	__fastcall TJclPeExportFuncList(TJclPeImage* AImage);
	__fastcall virtual ~TJclPeExportFuncList(void);
	void __fastcall CheckForwards(TJclPeImagesCache* PeImageCache = (TJclPeImagesCache*)(0x0));
	/*         class method */ static AnsiString __fastcall ItemName(TMetaClass* vmt, TJclPeExportFuncItem* Item);
	bool __fastcall OrdinalValid(unsigned Ordinal);
	void __fastcall PrepareForFastNameSearch(void);
	TJclPeExportFuncItem* __fastcall SmartFindName(const AnsiString CompareName, TJclSmartCompOptions Options = Set<TJclSmartCompOption, scSimpleCompare, scIgnoreCase> () );
	void __fastcall SortList(TJclPeExportSort SortType, bool Descending = false);
	__property bool AnyForwards = {read=FAnyForwards, nodefault};
	__property unsigned Base = {read=FBase, nodefault};
	__property PIMAGE_EXPORT_DIRECTORY ExportDir = {read=FExportDir};
	__property Classes::TStrings* ForwardedLibsList = {read=GetForwardedLibsList};
	__property unsigned FunctionCount = {read=FFunctionCount, nodefault};
	__property TJclPeExportFuncItem* Items[int Index] = {read=GetItems/*, default*/};
	__property TJclPeExportFuncItem* ItemFromAddress[unsigned Address] = {read=GetItemFromAddress};
	__property TJclPeExportFuncItem* ItemFromName[AnsiString Name] = {read=GetItemFromName};
	__property TJclPeExportFuncItem* ItemFromOrdinal[unsigned Ordinal] = {read=GetItemFromOrdinal};
	__property AnsiString Name = {read=GetName};
	__property TJclPeResolveCheck TotalResolveCheck = {read=FTotalResolveCheck, nodefault};
};


class DELPHICLASS TJclPeImportList;
#pragma option push -b-
enum TJclPeImportSort { isName, isOrdinal, isHint, isLibImport };
#pragma option pop

#pragma option push -b-
enum TJclPeLinkerProducer { lrBorland, lrMicrosoft };
#pragma option pop

class DELPHICLASS TJclPeImportFuncItem;
class DELPHICLASS TJclPeImportLibItem;
#pragma option push -b-
enum TJclPeImportLibSort { ilName, ilIndex };
#pragma option pop

class PASCALIMPLEMENTATION TJclPeImportList : public TJclPeImageBaseList 
{
	typedef TJclPeImageBaseList inherited;
	
public:
	TJclPeImportLibItem* operator[](int Index) { return Items[Index]; }
	
private:
	Classes::TList* FAllItemsList;
	AnsiString FFilterModuleName;
	TJclPeImportSort FLastAllSortType;
	bool FLastAllSortDescending;
	TJclPeLinkerProducer FLinkerProducer;
	DynamicArray<void * >  FParallelImportTable;
	Classes::TStringList* FUniqueNamesList;
	int __fastcall GetAllItemCount(void);
	TJclPeImportFuncItem* __fastcall GetAllItems(int Index);
	TJclPeImportLibItem* __fastcall GetItems(int Index);
	int __fastcall GetUniqueLibItemCount(void);
	TJclPeImportLibItem* __fastcall GetUniqueLibItems(int Index);
	AnsiString __fastcall GetUniqueLibNames(int Index);
	TJclPeImportLibItem* __fastcall GetUniqueLibItemFromName(const AnsiString Name);
	void __fastcall SetFilterModuleName(const AnsiString Value);
	
protected:
	void __fastcall CreateList(void);
	void __fastcall RefreshAllItems(void);
	
public:
	__fastcall TJclPeImportList(TJclPeImage* AImage);
	__fastcall virtual ~TJclPeImportList(void);
	void __fastcall CheckImports(TJclPeImagesCache* PeImageCache = (TJclPeImagesCache*)(0x0));
	bool __fastcall MakeBorlandImportTableForMappedImage(void);
	TJclPeImportFuncItem* __fastcall SmartFindName(const AnsiString CompareName, const AnsiString LibName, TJclSmartCompOptions Options = Set<TJclSmartCompOption, scSimpleCompare, scIgnoreCase> () );
	void __fastcall SortAllItemsList(TJclPeImportSort SortType, bool Descending = false);
	void __fastcall SortList(TJclPeImportLibSort SortType);
	void __fastcall TryGetNamesForOrdinalImports(void);
	__property TJclPeImportFuncItem* AllItems[int Index] = {read=GetAllItems};
	__property int AllItemCount = {read=GetAllItemCount, nodefault};
	__property AnsiString FilterModuleName = {read=FFilterModuleName, write=SetFilterModuleName};
	__property TJclPeImportLibItem* Items[int Index] = {read=GetItems/*, default*/};
	__property TJclPeLinkerProducer LinkerProducer = {read=FLinkerProducer, nodefault};
	__property int UniqueLibItemCount = {read=GetUniqueLibItemCount, nodefault};
	__property TJclPeImportLibItem* UniqueLibItemFromName[AnsiString Name] = {read=GetUniqueLibItemFromName};
	__property TJclPeImportLibItem* UniqueLibItems[int Index] = {read=GetUniqueLibItems};
	__property AnsiString UniqueLibNames[int Index] = {read=GetUniqueLibNames};
};


class DELPHICLASS TJclPeRelocList;
class DELPHICLASS TJclPeRelocEntry;
struct TJclPeRelocation;
class PASCALIMPLEMENTATION TJclPeRelocList : public TJclPeImageBaseList 
{
	typedef TJclPeImageBaseList inherited;
	
public:
	TJclPeRelocEntry* operator[](int Index) { return Items[Index]; }
	
private:
	int FAllItemCount;
	TJclPeRelocEntry* __fastcall GetItems(int Index);
	TJclPeRelocation __fastcall GetAllItems(int Index);
	
protected:
	void __fastcall CreateList(void);
	
public:
	__fastcall TJclPeRelocList(TJclPeImage* AImage);
	__property TJclPeRelocation AllItems[int Index] = {read=GetAllItems};
	__property int AllItemCount = {read=FAllItemCount, nodefault};
	__property TJclPeRelocEntry* Items[int Index] = {read=GetItems/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TJclPeRelocList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclPeRootResourceList;
class DELPHICLASS TJclPeResourceList;
class DELPHICLASS TJclPeResourceItem;
#pragma option push -b-
enum TJclPeResourceKind { rtUnknown0, rtCursorEntry, rtBitmap, rtIconEntry, rtMenu, rtDialog, rtString, rtFontDir, rtFont, rtAccelerators, rtRCData, rtMessageTable, rtCursor, rtUnknown13, rtIcon, rtUnknown15, rtVersion, rtDlgInclude, rtUnknown18, rtPlugPlay, rtVxd, rtAniCursor, rtAniIcon, rtHmtl, rtManifest, rtUserDefined };
#pragma option pop

class PASCALIMPLEMENTATION TJclPeResourceItem : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	_IMAGE_RESOURCE_DIRECTORY_ENTRY *FEntry;
	TJclPeImage* FImage;
	TJclPeResourceList* FList;
	Byte FLevel;
	TJclPeResourceItem* FParentItem;
	AnsiString FNameCache;
	PIMAGE_RESOURCE_DATA_ENTRY __fastcall GetDataEntry(void);
	bool __fastcall GetIsDirectory(void);
	bool __fastcall GetIsName(void);
	Word __fastcall GetLangID(void);
	TJclPeResourceList* __fastcall GetList(void);
	AnsiString __fastcall GetName();
	AnsiString __fastcall GetParameterName();
	void * __fastcall GetRawEntryData(void);
	int __fastcall GetRawEntryDataSize(void);
	TJclPeResourceKind __fastcall GetResourceType(void);
	AnsiString __fastcall GetResourceTypeStr();
	
protected:
	unsigned __fastcall OffsetToRawData(unsigned Ofs);
	TJclPeResourceItem* __fastcall Level1Item(void);
	PIMAGE_RESOURCE_DIRECTORY __fastcall SubDirData(void);
	
public:
	__fastcall TJclPeResourceItem(TJclPeImage* AImage, TJclPeResourceItem* AParentItem, PIMAGE_RESOURCE_DIRECTORY_ENTRY AEntry);
	__fastcall virtual ~TJclPeResourceItem(void);
	bool __fastcall CompareName(char * AName);
	__property PIMAGE_RESOURCE_DATA_ENTRY DataEntry = {read=GetDataEntry};
	__property PIMAGE_RESOURCE_DIRECTORY_ENTRY Entry = {read=FEntry};
	__property TJclPeImage* Image = {read=FImage};
	__property bool IsDirectory = {read=GetIsDirectory, nodefault};
	__property bool IsName = {read=GetIsName, nodefault};
	__property Word LangID = {read=GetLangID, nodefault};
	__property TJclPeResourceList* List = {read=GetList};
	__property Byte Level = {read=FLevel, nodefault};
	__property AnsiString Name = {read=GetName};
	__property AnsiString ParameterName = {read=GetParameterName};
	__property TJclPeResourceItem* ParentItem = {read=FParentItem};
	__property void * RawEntryData = {read=GetRawEntryData};
	__property int RawEntryDataSize = {read=GetRawEntryDataSize, nodefault};
	__property TJclPeResourceKind ResourceType = {read=GetResourceType, nodefault};
	__property AnsiString ResourceTypeStr = {read=GetResourceTypeStr};
};


class PASCALIMPLEMENTATION TJclPeResourceList : public TJclPeImageBaseList 
{
	typedef TJclPeImageBaseList inherited;
	
public:
	TJclPeResourceItem* operator[](int Index) { return Items[Index]; }
	
private:
	_IMAGE_RESOURCE_DIRECTORY *FDirectory;
	TJclPeResourceItem* FParentItem;
	TJclPeResourceItem* __fastcall GetItems(int Index);
	
protected:
	void __fastcall CreateList(TJclPeResourceItem* AParentItem);
	
public:
	__fastcall TJclPeResourceList(TJclPeImage* AImage, TJclPeResourceItem* AParentItem, PIMAGE_RESOURCE_DIRECTORY ADirectory);
	TJclPeResourceItem* __fastcall FindName(const AnsiString Name);
	__property PIMAGE_RESOURCE_DIRECTORY Directory = {read=FDirectory};
	__property TJclPeResourceItem* Items[int Index] = {read=GetItems/*, default*/};
	__property TJclPeResourceItem* ParentItem = {read=FParentItem};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TJclPeResourceList(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TJclPeRootResourceList : public TJclPeResourceList 
{
	typedef TJclPeResourceList inherited;
	
private:
	Classes::TStringList* FManifestContent;
	Classes::TStrings* __fastcall GetManifestContent(void);
	
public:
	__fastcall virtual ~TJclPeRootResourceList(void);
	TJclPeResourceItem* __fastcall FindResource(TJclPeResourceKind ResourceType, const AnsiString ResourceName = "")/* overload */;
	TJclPeResourceItem* __fastcall FindResource(const char * ResourceType, const char * ResourceName = (void *)(0x0))/* overload */;
	bool __fastcall ListResourceNames(TJclPeResourceKind ResourceType, const Classes::TStrings* Strings);
	__property Classes::TStrings* ManifestContent = {read=GetManifestContent};
public:
	#pragma option push -w-inl
	/* TJclPeResourceList.Create */ inline __fastcall TJclPeRootResourceList(TJclPeImage* AImage, TJclPeResourceItem* AParentItem, PIMAGE_RESOURCE_DIRECTORY ADirectory) : TJclPeResourceList(AImage, AParentItem, ADirectory) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TJclPeImageStatus { stNotLoaded, stOk, stNotPE, stNotSupported, stNotFound, stError };
#pragma option pop

#pragma option push -b-
enum TJclPeTarget { taUnknown, taWin32, taWin64 };
#pragma option pop

struct TJclPeFileProperties;
#pragma option push -b-
enum TJclPeHeader { JclPeHeader_Signature, JclPeHeader_Machine, JclPeHeader_NumberOfSections, JclPeHeader_TimeDateStamp, JclPeHeader_PointerToSymbolTable, JclPeHeader_NumberOfSymbols, JclPeHeader_SizeOfOptionalHeader, JclPeHeader_Characteristics, JclPeHeader_Magic, JclPeHeader_LinkerVersion, JclPeHeader_SizeOfCode, JclPeHeader_SizeOfInitializedData, JclPeHeader_SizeOfUninitializedData, JclPeHeader_AddressOfEntryPoint, JclPeHeader_BaseOfCode, JclPeHeader_BaseOfData, JclPeHeader_ImageBase, JclPeHeader_SectionAlignment, JclPeHeader_FileAlignment, JclPeHeader_OperatingSystemVersion, JclPeHeader_ImageVersion, JclPeHeader_SubsystemVersion, JclPeHeader_Win32VersionValue, JclPeHeader_SizeOfImage, JclPeHeader_SizeOfHeaders, JclPeHeader_CheckSum, JclPeHeader_Subsystem, JclPeHeader_DllCharacteristics, JclPeHeader_SizeOfStackReserve, JclPeHeader_SizeOfStackCommit, JclPeHeader_SizeOfHeapReserve, JclPeHeader_SizeOfHeapCommit, JclPeHeader_LoaderFlags, JclPeHeader_NumberOfRvaAndSizes };
#pragma option pop

#pragma option push -b-
enum TJclLoadConfig { JclLoadConfig_Characteristics, JclLoadConfig_TimeDateStamp, JclLoadConfig_Version, JclLoadConfig_GlobalFlagsClear, JclLoadConfig_GlobalFlagsSet, JclLoadConfig_CriticalSectionDefaultTimeout, JclLoadConfig_DeCommitFreeBlockThreshold, JclLoadConfig_DeCommitTotalFreeThreshold, JclLoadConfig_LockPrefixTable, JclLoadConfig_MaximumAllocationSize, JclLoadConfig_VirtualMemoryThreshold, JclLoadConfig_ProcessHeapFlags, JclLoadConfig_ProcessAffinityMask, JclLoadConfig_CSDVersion, JclLoadConfig_Reserved1, JclLoadConfig_EditList, JclLoadConfig_Reserved };
#pragma option pop

class PASCALIMPLEMENTATION TJclPeImage : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	bool FAttachedImage;
	TJclPeCertificateList* FCertificateList;
	TJclPeCLRHeader* FCLRHeader;
	TJclPeDebugList* FDebugList;
	AnsiString FFileName;
	Classes::TStringList* FImageSections;
	_LOADED_IMAGE FLoadedImage;
	TJclPeExportFuncList* FExportList;
	TJclPeImportList* FImportList;
	bool FNoExceptions;
	bool FReadOnlyAccess;
	TJclPeRelocList* FRelocationList;
	TJclPeRootResourceList* FResourceList;
	unsigned FResourceVA;
	TJclPeImageStatus FStatus;
	TJclPeTarget FTarget;
	Jclfileutils::TJclFileVersionInfo* FVersionInfo;
	TJclPeCertificateList* __fastcall GetCertificateList(void);
	TJclPeCLRHeader* __fastcall GetCLRHeader(void);
	TJclPeDebugList* __fastcall GetDebugList(void);
	AnsiString __fastcall GetDescription();
	_IMAGE_DATA_DIRECTORY __fastcall GetDirectories(Word Directory);
	bool __fastcall GetDirectoryExists(Word Directory);
	TJclPeExportFuncList* __fastcall GetExportList(void);
	TJclPeFileProperties __fastcall GetFileProperties();
	int __fastcall GetImageSectionCount(void);
	_IMAGE_SECTION_HEADER __fastcall GetImageSectionHeaders(int Index);
	AnsiString __fastcall GetImageSectionNames(int Index);
	AnsiString __fastcall GetImageSectionNameFromRva(const unsigned Rva);
	TJclPeImportList* __fastcall GetImportList(void);
	AnsiString __fastcall GetHeaderValues(TJclPeHeader Index);
	AnsiString __fastcall GetLoadConfigValues(TJclLoadConfig Index);
	unsigned __fastcall GetMappedAddress(void);
	_IMAGE_OPTIONAL_HEADER __fastcall GetOptionalHeader32();
	_IMAGE_OPTIONAL_HEADER64 __fastcall GetOptionalHeader64();
	TJclPeRelocList* __fastcall GetRelocationList(void);
	TJclPeRootResourceList* __fastcall GetResourceList(void);
	_IMAGE_DATA_DIRECTORY __fastcall GetUnusedHeaderBytes();
	Jclfileutils::TJclFileVersionInfo* __fastcall GetVersionInfo(void);
	bool __fastcall GetVersionInfoAvailable(void);
	void __fastcall ReadImageSections(void);
	void __fastcall SetFileName(const AnsiString Value);
	
protected:
	DYNAMIC void __fastcall AfterOpen(void);
	void __fastcall CheckNotAttached(void);
	DYNAMIC void __fastcall Clear(void);
	AnsiString __fastcall ExpandModuleName(const AnsiString ModuleName);
	void __fastcall RaiseStatusException(void);
	virtual TJclPeResourceItem* __fastcall ResourceItemCreate(PIMAGE_RESOURCE_DIRECTORY_ENTRY AEntry, TJclPeResourceItem* AParentItem);
	virtual TJclPeResourceList* __fastcall ResourceListCreate(PIMAGE_RESOURCE_DIRECTORY ADirectory, TJclPeResourceItem* AParentItem);
	__property bool NoExceptions = {read=FNoExceptions, nodefault};
	
public:
	__fastcall virtual TJclPeImage(bool ANoExceptions);
	__fastcall virtual ~TJclPeImage(void);
	void __fastcall AttachLoadedModule(const unsigned Handle);
	unsigned __fastcall CalculateCheckSum(void);
	void * __fastcall DirectoryEntryToData(Word Directory);
	bool __fastcall GetSectionHeader(const AnsiString SectionName, /* out */ Windows::PImageSectionHeader &Header);
	AnsiString __fastcall GetSectionName(Windows::PImageSectionHeader Header);
	bool __fastcall IsBrokenFormat(void);
	bool __fastcall IsCLR(void);
	bool __fastcall IsSystemImage(void);
	void * __fastcall RawToVa(unsigned Raw)/* overload */;
	Windows::PImageSectionHeader __fastcall RvaToSection(unsigned Rva)/* overload */;
	void * __fastcall RvaToVa(unsigned Rva)/* overload */;
	void * __fastcall RvaToVaEx(unsigned Rva)/* overload */;
	bool __fastcall StatusOK(void);
	void __fastcall TryGetNamesForOrdinalImports(void);
	bool __fastcall VerifyCheckSum(void);
	/*         class method */ static AnsiString __fastcall DebugTypeNames(TMetaClass* vmt, unsigned DebugType);
	/*         class method */ static AnsiString __fastcall DirectoryNames(TMetaClass* vmt, Word Directory);
	/*         class method */ static AnsiString __fastcall ExpandBySearchPath(TMetaClass* vmt, const AnsiString ModuleName, const AnsiString BasePath);
	/*         class method */ static AnsiString __fastcall HeaderNames(TMetaClass* vmt, TJclPeHeader Index);
	/*         class method */ static AnsiString __fastcall LoadConfigNames(TMetaClass* vmt, TJclLoadConfig Index);
	/*         class method */ static AnsiString __fastcall ShortSectionInfo(TMetaClass* vmt, unsigned Characteristics);
	/*         class method */ static unsigned __fastcall DateTimeToStamp(TMetaClass* vmt, const System::TDateTime DateTime);
	/*         class method */ static System::TDateTime __fastcall StampToDateTime(TMetaClass* vmt, unsigned TimeDateStamp);
	__property bool AttachedImage = {read=FAttachedImage, nodefault};
	__property TJclPeCertificateList* CertificateList = {read=GetCertificateList};
	__property TJclPeCLRHeader* CLRHeader = {read=GetCLRHeader};
	__property TJclPeDebugList* DebugList = {read=GetDebugList};
	__property AnsiString Description = {read=GetDescription};
	__property _IMAGE_DATA_DIRECTORY Directories[Word Directory] = {read=GetDirectories};
	__property bool DirectoryExists[Word Directory] = {read=GetDirectoryExists};
	__property TJclPeExportFuncList* ExportList = {read=GetExportList};
	__property AnsiString FileName = {read=FFileName, write=SetFileName};
	__property TJclPeFileProperties FileProperties = {read=GetFileProperties};
	__property AnsiString HeaderValues[TJclPeHeader Index] = {read=GetHeaderValues};
	__property int ImageSectionCount = {read=GetImageSectionCount, nodefault};
	__property _IMAGE_SECTION_HEADER ImageSectionHeaders[int Index] = {read=GetImageSectionHeaders};
	__property AnsiString ImageSectionNames[int Index] = {read=GetImageSectionNames};
	__property AnsiString ImageSectionNameFromRva[unsigned Rva] = {read=GetImageSectionNameFromRva};
	__property TJclPeImportList* ImportList = {read=GetImportList};
	__property AnsiString LoadConfigValues[TJclLoadConfig Index] = {read=GetLoadConfigValues};
	__property _LOADED_IMAGE LoadedImage = {read=FLoadedImage};
	__property unsigned MappedAddress = {read=GetMappedAddress, nodefault};
	__property _IMAGE_OPTIONAL_HEADER OptionalHeader32 = {read=GetOptionalHeader32};
	__property _IMAGE_OPTIONAL_HEADER64 OptionalHeader64 = {read=GetOptionalHeader64};
	__property bool ReadOnlyAccess = {read=FReadOnlyAccess, write=FReadOnlyAccess, nodefault};
	__property TJclPeRelocList* RelocationList = {read=GetRelocationList};
	__property unsigned ResourceVA = {read=FResourceVA, nodefault};
	__property TJclPeRootResourceList* ResourceList = {read=GetResourceList};
	__property TJclPeImageStatus Status = {read=FStatus, nodefault};
	__property TJclPeTarget Target = {read=FTarget, nodefault};
	__property _IMAGE_DATA_DIRECTORY UnusedHeaderBytes = {read=GetUnusedHeaderBytes};
	__property Jclfileutils::TJclFileVersionInfo* VersionInfo = {read=GetVersionInfo};
	__property bool VersionInfoAvailable = {read=GetVersionInfoAvailable, nodefault};
};



class PASCALIMPLEMENTATION TJclPeImagesCache : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TJclPeImage* operator[](AnsiString FileName) { return Images[FileName]; }
	
private:
	Classes::TStringList* FList;
	int __fastcall GetCount(void);
	TJclPeImage* __fastcall GetImages(const AnsiString FileName);
	
protected:
	virtual TMetaClass* __fastcall GetPeImageClass(void);
	
public:
	__fastcall TJclPeImagesCache(void);
	__fastcall virtual ~TJclPeImagesCache(void);
	void __fastcall Clear(void);
	__property TJclPeImage* Images[AnsiString FileName] = {read=GetImages/*, default*/};
	__property int Count = {read=GetCount, nodefault};
};


#pragma option push -b-
enum TJclPeImportKind { ikImport, ikDelayImport, ikBoundImport };
#pragma option pop

class PASCALIMPLEMENTATION TJclPeImportFuncItem : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Word FOrdinal;
	Word FHint;
	TJclPeImportLibItem* FImportLib;
	bool FIndirectImportName;
	AnsiString FName;
	TJclPeResolveCheck FResolveCheck;
	bool __fastcall GetIsByOrdinal(void);
	
protected:
	void __fastcall SetName(const AnsiString Value);
	void __fastcall SetIndirectImportName(const AnsiString Value);
	void __fastcall SetResolveCheck(TJclPeResolveCheck Value);
	
public:
	__fastcall TJclPeImportFuncItem(TJclPeImportLibItem* AImportLib, Word AOrdinal, Word AHint, const AnsiString AName);
	__property Word Ordinal = {read=FOrdinal, nodefault};
	__property Word Hint = {read=FHint, nodefault};
	__property TJclPeImportLibItem* ImportLib = {read=FImportLib};
	__property bool IndirectImportName = {read=FIndirectImportName, nodefault};
	__property bool IsByOrdinal = {read=GetIsByOrdinal, nodefault};
	__property AnsiString Name = {read=FName};
	__property TJclPeResolveCheck ResolveCheck = {read=FResolveCheck, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclPeImportFuncItem(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TJclPeImportLibItem : public TJclPeImageBaseList 
{
	typedef TJclPeImageBaseList inherited;
	
public:
	TJclPeImportFuncItem* operator[](int Index) { return Items[Index]; }
	
private:
	void *FImportDescriptor;
	int FImportDirectoryIndex;
	TJclPeImportKind FImportKind;
	TJclPeImportSort FLastSortType;
	bool FLastSortDescending;
	AnsiString FName;
	bool FSorted;
	TJclPeResolveCheck FTotalResolveCheck;
	void *FThunk;
	void *FThunkData;
	int __fastcall GetCount(void);
	AnsiString __fastcall GetFileName();
	TJclPeImportFuncItem* __fastcall GetItems(int Index);
	AnsiString __fastcall GetName();
	PIMAGE_THUNK_DATA32 __fastcall GetThunkData32(void);
	PIMAGE_THUNK_DATA64 __fastcall GetThunkData64(void);
	
protected:
	void __fastcall CheckImports(TJclPeImage* ExportImage);
	void __fastcall CreateList(void);
	void __fastcall SetImportDirectoryIndex(int Value);
	void __fastcall SetImportKind(TJclPeImportKind Value);
	void __fastcall SetSorted(bool Value);
	void __fastcall SetThunk(void * Value);
	
public:
	__fastcall TJclPeImportLibItem(TJclPeImage* AImage, void * AImportDescriptor, TJclPeImportKind AImportKind, const AnsiString AName, void * AThunk);
	void __fastcall SortList(TJclPeImportSort SortType, bool Descending = false);
	__property int Count = {read=GetCount, nodefault};
	__property AnsiString FileName = {read=GetFileName};
	__property void * ImportDescriptor = {read=FImportDescriptor};
	__property int ImportDirectoryIndex = {read=FImportDirectoryIndex, nodefault};
	__property TJclPeImportKind ImportKind = {read=FImportKind, nodefault};
	__property TJclPeImportFuncItem* Items[int Index] = {read=GetItems/*, default*/};
	__property AnsiString Name = {read=GetName};
	__property AnsiString OriginalName = {read=FName};
	__property PIMAGE_THUNK_DATA32 ThunkData32 = {read=GetThunkData32};
	__property PIMAGE_THUNK_DATA64 ThunkData64 = {read=GetThunkData64};
	__property TJclPeResolveCheck TotalResolveCheck = {read=FTotalResolveCheck, nodefault};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TJclPeImportLibItem(void) { }
	#pragma option pop
	
};


typedef DynamicArray<void * >  JclPeImage__7;

class PASCALIMPLEMENTATION TJclPeExportFuncItem : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	unsigned FAddress;
	TJclPeExportFuncList* FExportList;
	AnsiString FForwardedName;
	AnsiString FForwardedDotPos;
	Word FHint;
	AnsiString FName;
	Word FOrdinal;
	TJclPeResolveCheck FResolveCheck;
	AnsiString __fastcall GetAddressOrForwardStr();
	AnsiString __fastcall GetForwardedFuncName();
	AnsiString __fastcall GetForwardedLibName();
	unsigned __fastcall GetForwardedFuncOrdinal(void);
	bool __fastcall GetIsExportedVariable(void);
	bool __fastcall GetIsForwarded(void);
	AnsiString __fastcall GetSectionName();
	void * __fastcall GetMappedAddress(void);
	
protected:
	void __fastcall SetResolveCheck(TJclPeResolveCheck Value);
	
public:
	__fastcall TJclPeExportFuncItem(TJclPeExportFuncList* AExportList, const AnsiString AName, const AnsiString AForwardedName, unsigned AAddress, Word AHint, Word AOrdinal, TJclPeResolveCheck AResolveCheck);
	__property unsigned Address = {read=FAddress, nodefault};
	__property AnsiString AddressOrForwardStr = {read=GetAddressOrForwardStr};
	__property bool IsExportedVariable = {read=GetIsExportedVariable, nodefault};
	__property bool IsForwarded = {read=GetIsForwarded, nodefault};
	__property AnsiString ForwardedName = {read=FForwardedName};
	__property AnsiString ForwardedLibName = {read=GetForwardedLibName};
	__property unsigned ForwardedFuncOrdinal = {read=GetForwardedFuncOrdinal, nodefault};
	__property AnsiString ForwardedFuncName = {read=GetForwardedFuncName};
	__property Word Hint = {read=FHint, nodefault};
	__property void * MappedAddress = {read=GetMappedAddress};
	__property AnsiString Name = {read=FName};
	__property Word Ordinal = {read=FOrdinal, nodefault};
	__property TJclPeResolveCheck ResolveCheck = {read=FResolveCheck, nodefault};
	__property AnsiString SectionName = {read=GetSectionName};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclPeExportFuncItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclPeResourceRawStream;
class PASCALIMPLEMENTATION TJclPeResourceRawStream : public Classes::TCustomMemoryStream 
{
	typedef Classes::TCustomMemoryStream inherited;
	
public:
	__fastcall TJclPeResourceRawStream(TJclPeResourceItem* AResourceItem);
	virtual int __fastcall Write(const void *Buffer, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclPeResourceRawStream(void) { }
	#pragma option pop
	
};


struct TJclPeRelocation
{
	
public:
	Word Address;
	Byte RelocType;
	unsigned VirtualAddress;
} ;

class PASCALIMPLEMENTATION TJclPeRelocEntry : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TJclPeRelocation operator[](int Index) { return Relocations[Index]; }
	
private:
	_IMAGE_BASE_RELOCATION *FChunk;
	int FCount;
	TJclPeRelocation __fastcall GetRelocations(int Index);
	unsigned __fastcall GetSize(void);
	unsigned __fastcall GetVirtualAddress(void);
	
public:
	__fastcall TJclPeRelocEntry(PIMAGE_BASE_RELOCATION AChunk, int ACount);
	__property int Count = {read=FCount, nodefault};
	__property TJclPeRelocation Relocations[int Index] = {read=GetRelocations/*, default*/};
	__property unsigned Size = {read=GetSize, nodefault};
	__property unsigned VirtualAddress = {read=GetVirtualAddress, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclPeRelocEntry(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TJclPeCertificate : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	void *FData;
	#pragma pack(push,1)
	_WIN_CERTIFICATE FHeader;
	#pragma pack(pop)
	
public:
	__fastcall TJclPeCertificate(const _WIN_CERTIFICATE &AHeader, void * AData);
	__property void * Data = {read=FData};
	__property _WIN_CERTIFICATE Header = {read=FHeader};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclPeCertificate(void) { }
	#pragma option pop
	
};


struct TJclPeFileProperties
{
	
public:
	unsigned Size;
	System::TDateTime CreationTime;
	System::TDateTime LastAccessTime;
	System::TDateTime LastWriteTime;
	int Attributes;
} ;

class DELPHICLASS TJclPeBorImagesCache;
class DELPHICLASS TJclPeBorImage;
class PASCALIMPLEMENTATION TJclPeBorImagesCache : public TJclPeImagesCache 
{
	typedef TJclPeImagesCache inherited;
	
public:
	TJclPeBorImage* operator[](AnsiString FileName) { return Images[FileName]; }
	
private:
	HIDESBASE TJclPeBorImage* __fastcall GetImages(const AnsiString FileName);
	
protected:
	virtual TMetaClass* __fastcall GetPeImageClass(void);
	
public:
	__property TJclPeBorImage* Images[AnsiString FileName] = {read=GetImages/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclPeImagesCache.Create */ inline __fastcall TJclPeBorImagesCache(void) : TJclPeImagesCache() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclPeImagesCache.Destroy */ inline __fastcall virtual ~TJclPeBorImagesCache(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclPePackageInfo;
class PASCALIMPLEMENTATION TJclPePackageInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	bool FAvailable;
	Classes::TStringList* FContains;
	AnsiString FDcpName;
	Classes::TStringList* FRequires;
	int FFlags;
	AnsiString FDescription;
	bool FEnsureExtension;
	bool FSorted;
	Classes::TStrings* __fastcall GetContains(void);
	int __fastcall GetContainsCount(void);
	Byte __fastcall GetContainsFlags(int Index);
	AnsiString __fastcall GetContainsNames(int Index);
	Classes::TStrings* __fastcall GetRequires(void);
	int __fastcall GetRequiresCount(void);
	AnsiString __fastcall GetRequiresNames(int Index);
	
protected:
	void __fastcall ReadPackageInfo(unsigned ALibHandle);
	void __fastcall SetDcpName(const AnsiString Value);
	
public:
	__fastcall TJclPePackageInfo(unsigned ALibHandle);
	__fastcall virtual ~TJclPePackageInfo(void);
	/*         class method */ static AnsiString __fastcall PackageModuleTypeToString(TMetaClass* vmt, unsigned Flags);
	/*         class method */ static AnsiString __fastcall PackageOptionsToString(TMetaClass* vmt, unsigned Flags);
	/*         class method */ static AnsiString __fastcall ProducerToString(TMetaClass* vmt, unsigned Flags);
	/*         class method */ static AnsiString __fastcall UnitInfoFlagsToString(TMetaClass* vmt, Byte UnitFlags);
	__property bool Available = {read=FAvailable, nodefault};
	__property Classes::TStrings* Contains = {read=GetContains};
	__property int ContainsCount = {read=GetContainsCount, nodefault};
	__property AnsiString ContainsNames[int Index] = {read=GetContainsNames};
	__property Byte ContainsFlags[int Index] = {read=GetContainsFlags};
	__property AnsiString Description = {read=FDescription};
	__property AnsiString DcpName = {read=FDcpName};
	__property bool EnsureExtension = {read=FEnsureExtension, write=FEnsureExtension, nodefault};
	__property int Flags = {read=FFlags, nodefault};
	__property Classes::TStrings* Requires = {read=GetRequires};
	__property int RequiresCount = {read=GetRequiresCount, nodefault};
	__property AnsiString RequiresNames[int Index] = {read=GetRequiresNames};
	__property bool Sorted = {read=FSorted, write=FSorted, nodefault};
};


class DELPHICLASS TJclPeBorForm;
class PASCALIMPLEMENTATION TJclPeBorForm : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TFilerFlags FFormFlags;
	AnsiString FFormClassName;
	AnsiString FFormObjectName;
	int FFormPosition;
	TJclPeResourceItem* FResItem;
	AnsiString __fastcall GetDisplayName();
	
public:
	__fastcall TJclPeBorForm(TJclPeResourceItem* AResItem, Classes::TFilerFlags AFormFlags, int AFormPosition, const AnsiString AFormClassName, const AnsiString AFormObjectName);
	void __fastcall ConvertFormToText(const Classes::TStream* Stream)/* overload */;
	void __fastcall ConvertFormToText(const Classes::TStrings* Strings)/* overload */;
	__property AnsiString FormClassName = {read=FFormClassName};
	__property Classes::TFilerFlags FormFlags = {read=FFormFlags, nodefault};
	__property AnsiString FormObjectName = {read=FFormObjectName};
	__property int FormPosition = {read=FFormPosition, nodefault};
	__property AnsiString DisplayName = {read=GetDisplayName};
	__property TJclPeResourceItem* ResItem = {read=FResItem};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclPeBorForm(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TJclPeBorImage : public TJclPeImage 
{
	typedef TJclPeImage inherited;
	
private:
	Contnrs::TObjectList* FForms;
	bool FIsPackage;
	bool FIsBorlandImage;
	unsigned FLibHandle;
	TJclPePackageInfo* FPackageInfo;
	bool FPackageInfoSorted;
	int FPackageCompilerVersion;
	int __fastcall GetFormCount(void);
	TJclPeBorForm* __fastcall GetForms(int Index);
	TJclPeBorForm* __fastcall GetFormFromName(const AnsiString FormClassName);
	unsigned __fastcall GetLibHandle(void);
	int __fastcall GetPackageCompilerVersion(void);
	TJclPePackageInfo* __fastcall GetPackageInfo(void);
	
protected:
	DYNAMIC void __fastcall AfterOpen(void);
	DYNAMIC void __fastcall Clear(void);
	void __fastcall CreateFormsList(void);
	
public:
	__fastcall virtual TJclPeBorImage(bool ANoExceptions);
	__fastcall virtual ~TJclPeBorImage(void);
	bool __fastcall DependedPackages(Classes::TStrings* List, bool FullPathName, bool Descriptions);
	bool __fastcall FreeLibHandle(void);
	__property TJclPeBorForm* Forms[int Index] = {read=GetForms};
	__property int FormCount = {read=GetFormCount, nodefault};
	__property TJclPeBorForm* FormFromName[AnsiString FormClassName] = {read=GetFormFromName};
	__property bool IsBorlandImage = {read=FIsBorlandImage, nodefault};
	__property bool IsPackage = {read=FIsPackage, nodefault};
	__property unsigned LibHandle = {read=GetLibHandle, nodefault};
	__property int PackageCompilerVersion = {read=GetPackageCompilerVersion, nodefault};
	__property TJclPePackageInfo* PackageInfo = {read=GetPackageInfo};
	__property bool PackageInfoSorted = {read=FPackageInfoSorted, write=FPackageInfoSorted, nodefault};
};


#pragma option push -b-
enum TJclPeNameSearchOption { seImports, seDelayImports, seBoundImports, seExports };
#pragma option pop

typedef Set<TJclPeNameSearchOption, seImports, seExports>  TJclPeNameSearchOptions;

typedef void __fastcall (__closure *TJclPeNameSearchNotifyEvent)(System::TObject* Sender, TJclPeImage* PeImage, bool &Process);

typedef void __fastcall (__closure *TJclPeNameSearchFoundEvent)(System::TObject* Sender, const AnsiString FileName, const AnsiString FunctionName, TJclPeNameSearchOption Option);

class DELPHICLASS TJclPeNameSearch;
class PASCALIMPLEMENTATION TJclPeNameSearch : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
private:
	AnsiString F_FileName;
	AnsiString F_FunctionName;
	TJclPeNameSearchOption F_Option;
	bool F_Process;
	AnsiString FFunctionName;
	TJclPeNameSearchOptions FOptions;
	AnsiString FPath;
	TJclPeImage* FPeImage;
	TJclPeNameSearchFoundEvent FOnFound;
	TJclPeNameSearchNotifyEvent FOnProcessFile;
	
protected:
	virtual bool __fastcall CompareName(const AnsiString FunctionName, const AnsiString ComparedName);
	void __fastcall DoFound(void);
	void __fastcall DoProcessFile(void);
	virtual void __fastcall Execute(void);
	
public:
	__fastcall TJclPeNameSearch(const AnsiString FunctionName, const AnsiString Path, TJclPeNameSearchOptions Options);
	void __fastcall Start(void);
	__property TJclPeNameSearchFoundEvent OnFound = {read=FOnFound, write=FOnFound};
	__property TJclPeNameSearchNotifyEvent OnProcessFile = {read=FOnProcessFile, write=FOnProcessFile};
public:
	#pragma option push -w-inl
	/* TThread.Destroy */ inline __fastcall virtual ~TJclPeNameSearch(void) { }
	#pragma option pop
	
};


struct TJclRebaseImageInfo32
{
	
public:
	unsigned OldImageSize;
	unsigned OldImageBase;
	unsigned NewImageSize;
	unsigned NewImageBase;
} ;

struct TJclRebaseImageInfo64
{
	
public:
	unsigned OldImageSize;
	__int64 OldImageBase;
	unsigned NewImageSize;
	__int64 NewImageBase;
} ;

class DELPHICLASS TJclPeSectionStream;
class PASCALIMPLEMENTATION TJclPeSectionStream : public Classes::TCustomMemoryStream 
{
	typedef Classes::TCustomMemoryStream inherited;
	
private:
	unsigned FInstance;
	#pragma pack(push,1)
	_IMAGE_SECTION_HEADER FSectionHeader;
	#pragma pack(pop)
	void __fastcall Initialize(unsigned Instance, const AnsiString ASectionName);
	
public:
	__fastcall TJclPeSectionStream(unsigned Instance, const AnsiString ASectionName);
	virtual int __fastcall Write(const void *Buffer, int Count);
	__property unsigned Instance = {read=FInstance, nodefault};
	__property _IMAGE_SECTION_HEADER SectionHeader = {read=FSectionHeader};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclPeSectionStream(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclPeMapImgHookItem;
class PASCALIMPLEMENTATION TJclPeMapImgHookItem : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	void *FBaseAddress;
	AnsiString FFunctionName;
	AnsiString FModuleName;
	void *FNewAddress;
	void *FOriginalAddress;
	Contnrs::TObjectList* FList;
	
protected:
	bool __fastcall InternalUnhook(void);
	
public:
	__fastcall TJclPeMapImgHookItem(Contnrs::TObjectList* AList, const AnsiString AFunctionName, const AnsiString AModuleName, void * ABaseAddress, void * ANewAddress, void * AOriginalAddress);
	__fastcall virtual ~TJclPeMapImgHookItem(void);
	bool __fastcall Unhook(void);
	__property void * BaseAddress = {read=FBaseAddress};
	__property AnsiString FunctionName = {read=FFunctionName};
	__property AnsiString ModuleName = {read=FModuleName};
	__property void * NewAddress = {read=FNewAddress};
	__property void * OriginalAddress = {read=FOriginalAddress};
};


class DELPHICLASS TJclPeMapImgHooks;
class PASCALIMPLEMENTATION TJclPeMapImgHooks : public Contnrs::TObjectList 
{
	typedef Contnrs::TObjectList inherited;
	
public:
	TJclPeMapImgHookItem* operator[](int Index) { return Items[Index]; }
	
private:
	TJclPeMapImgHookItem* __fastcall GetItems(int Index);
	TJclPeMapImgHookItem* __fastcall GetItemFromOriginalAddress(void * OriginalAddress);
	TJclPeMapImgHookItem* __fastcall GetItemFromNewAddress(void * NewAddress);
	
public:
	bool __fastcall HookImport(void * Base, const AnsiString ModuleName, const AnsiString FunctionName, void * NewAddress, void * &OriginalAddress);
	/*         class method */ static bool __fastcall IsWin9xDebugThunk(TMetaClass* vmt, void * P);
	/*         class method */ static bool __fastcall ReplaceImport(TMetaClass* vmt, void * Base, const AnsiString ModuleName, void * FromProc, void * ToProc);
	/*         class method */ static void * __fastcall SystemBase(TMetaClass* vmt);
	void __fastcall UnhookAll(void);
	bool __fastcall UnhookByNewAddress(void * NewAddress);
	void __fastcall UnhookByBaseAddress(void * BaseAddress);
	__property TJclPeMapImgHookItem* Items[int Index] = {read=GetItems/*, default*/};
	__property TJclPeMapImgHookItem* ItemFromOriginalAddress[void * OriginalAddress] = {read=GetItemFromOriginalAddress};
	__property TJclPeMapImgHookItem* ItemFromNewAddress[void * NewAddress] = {read=GetItemFromNewAddress};
public:
	#pragma option push -w-inl
	/* TObjectList.Create */ inline __fastcall TJclPeMapImgHooks(void)/* overload */ : Contnrs::TObjectList() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TJclPeMapImgHooks(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TJclBorUmSymbolKind { skData, skFunction, skConstructor, skDestructor, skRTTI, skVTable };
#pragma option pop

#pragma option push -b-
enum TJclBorUmSymbolModifier { smQualified, smLinkProc };
#pragma option pop

typedef Set<TJclBorUmSymbolModifier, smQualified, smLinkProc>  TJclBorUmSymbolModifiers;

struct TJclBorUmDescription
{
	
public:
	TJclBorUmSymbolKind Kind;
	TJclBorUmSymbolModifiers Modifiers;
} ;

#pragma option push -b-
enum TJclBorUmResult { urOk, urNotMangled, urMicrosoft, urError };
#pragma option pop

#pragma option push -b-
enum TJclPeUmResult { umNotMangled, umBorland, umMicrosoft };
#pragma option pop

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE AnsiString __fastcall PeStripFunctionAW(const AnsiString FunctionName);
extern PACKAGE bool __fastcall PeSmartFunctionNameSame(const AnsiString ComparedName, const AnsiString FunctionName, TJclSmartCompOptions Options = Set<TJclSmartCompOption, scSimpleCompare, scIgnoreCase> () );
extern PACKAGE bool __fastcall IsValidPeFile(const AnsiString FileName);
extern PACKAGE bool __fastcall PeGetNtHeaders32(const AnsiString FileName, /* out */ _IMAGE_NT_HEADERS &NtHeaders);
extern PACKAGE bool __fastcall PeGetNtHeaders64(const AnsiString FileName, /* out */ _IMAGE_NT_HEADERS64 &NtHeaders);
extern PACKAGE bool __fastcall PeCreateNameHintTable(const AnsiString FileName);
extern PACKAGE TJclRebaseImageInfo32 __fastcall PeRebaseImage32(const AnsiString ImageName, unsigned NewBase = (unsigned)(0x0), unsigned TimeStamp = (unsigned)(0x0), unsigned MaxNewSize = (unsigned)(0x0));
extern PACKAGE TJclRebaseImageInfo64 __fastcall PeRebaseImage64(const AnsiString ImageName, __int64 NewBase = 0x000000000, unsigned TimeStamp = (unsigned)(0x0), unsigned MaxNewSize = (unsigned)(0x0));
extern PACKAGE bool __fastcall PeUpdateLinkerTimeStamp(const AnsiString FileName, const System::TDateTime Time);
extern PACKAGE System::TDateTime __fastcall PeReadLinkerTimeStamp(const AnsiString FileName);
extern PACKAGE bool __fastcall PeInsertSection(const AnsiString FileName, Classes::TStream* SectionStream, AnsiString SectionName);
extern PACKAGE bool __fastcall PeVerifyCheckSum(const AnsiString FileName);
extern PACKAGE bool __fastcall PeClearCheckSum(const AnsiString FileName);
extern PACKAGE bool __fastcall PeUpdateCheckSum(const AnsiString FileName);
extern PACKAGE bool __fastcall PeDoesExportFunction(const AnsiString FileName, const AnsiString FunctionName, TJclSmartCompOptions Options = Set<TJclSmartCompOption, scSimpleCompare, scIgnoreCase> () );
extern PACKAGE bool __fastcall PeIsExportFunctionForwardedEx(const AnsiString FileName, const AnsiString FunctionName, /* out */ AnsiString &ForwardedName, TJclSmartCompOptions Options = Set<TJclSmartCompOption, scSimpleCompare, scIgnoreCase> () );
extern PACKAGE bool __fastcall PeIsExportFunctionForwarded(const AnsiString FileName, const AnsiString FunctionName, TJclSmartCompOptions Options = Set<TJclSmartCompOption, scSimpleCompare, scIgnoreCase> () );
extern PACKAGE bool __fastcall PeDoesImportFunction(const AnsiString FileName, const AnsiString FunctionName, const AnsiString LibraryName = "", TJclSmartCompOptions Options = Set<TJclSmartCompOption, scSimpleCompare, scIgnoreCase> () );
extern PACKAGE bool __fastcall PeDoesImportLibrary(const AnsiString FileName, const AnsiString LibraryName, bool Recursive = false);
extern PACKAGE bool __fastcall PeImportedLibraries(const AnsiString FileName, const Classes::TStrings* LibrariesList, bool Recursive = false, bool FullPathName = false);
extern PACKAGE bool __fastcall PeImportedFunctions(const AnsiString FileName, const Classes::TStrings* FunctionsList, const AnsiString LibraryName = "", bool IncludeLibNames = false);
extern PACKAGE bool __fastcall PeExportedFunctions(const AnsiString FileName, const Classes::TStrings* FunctionsList);
extern PACKAGE bool __fastcall PeExportedNames(const AnsiString FileName, const Classes::TStrings* FunctionsList);
extern PACKAGE bool __fastcall PeExportedVariables(const AnsiString FileName, const Classes::TStrings* FunctionsList);
extern PACKAGE bool __fastcall PeResourceKindNames(const AnsiString FileName, TJclPeResourceKind ResourceType, const Classes::TStrings* NamesList);
extern PACKAGE bool __fastcall PeBorFormNames(const AnsiString FileName, const Classes::TStrings* NamesList);
extern PACKAGE bool __fastcall PeBorDependedPackages(const AnsiString FileName, Classes::TStrings* PackagesList, bool FullPathName, bool Descriptions);
extern PACKAGE bool __fastcall PeFindMissingImports(const AnsiString FileName, Classes::TStrings* MissingImportsList)/* overload */;
extern PACKAGE bool __fastcall PeFindMissingImports(Classes::TStrings* RequiredImportsList, Classes::TStrings* MissingImportsList)/* overload */;
extern PACKAGE bool __fastcall PeCreateRequiredImportList(const AnsiString FileName, Classes::TStrings* RequiredImportsList);
extern PACKAGE PIMAGE_NT_HEADERS32 __fastcall PeMapImgNtHeaders32(const void * BaseAddress);
extern PACKAGE PIMAGE_NT_HEADERS64 __fastcall PeMapImgNtHeaders64(const void * BaseAddress);
extern PACKAGE unsigned __fastcall PeMapImgSize(const void * BaseAddress);
extern PACKAGE AnsiString __fastcall PeMapImgLibraryName(const void * BaseAddress);
extern PACKAGE TJclPeTarget __fastcall PeMapImgTarget(const void * BaseAddress);
extern PACKAGE Windows::PImageSectionHeader __fastcall PeMapImgSections32(PIMAGE_NT_HEADERS32 NtHeaders);
extern PACKAGE Windows::PImageSectionHeader __fastcall PeMapImgSections64(PIMAGE_NT_HEADERS64 NtHeaders);
extern PACKAGE Windows::PImageSectionHeader __fastcall PeMapImgFindSection32(PIMAGE_NT_HEADERS32 NtHeaders, const AnsiString SectionName);
extern PACKAGE Windows::PImageSectionHeader __fastcall PeMapImgFindSection64(PIMAGE_NT_HEADERS64 NtHeaders, const AnsiString SectionName);
extern PACKAGE Windows::PImageSectionHeader __fastcall PeMapImgFindSectionFromModule(const void * BaseAddress, const AnsiString SectionName);
extern PACKAGE bool __fastcall PeMapImgExportedVariables(const unsigned Module, const Classes::TStrings* VariablesList);
extern PACKAGE void * __fastcall PeMapImgResolvePackageThunk(void * Address);
extern PACKAGE void * __fastcall PeMapFindResource(const unsigned Module, const char * ResourceType, const AnsiString ResourceName);
extern PACKAGE bool __fastcall PeDbgImgNtHeaders32(unsigned ProcessHandle, unsigned BaseAddress, _IMAGE_NT_HEADERS &NtHeaders);
extern PACKAGE bool __fastcall PeDbgImgLibraryName32(unsigned ProcessHandle, unsigned BaseAddress, AnsiString &Name);
extern PACKAGE TJclBorUmResult __fastcall PeBorUnmangleName(const AnsiString Name, /* out */ AnsiString &Unmangled, /* out */ TJclBorUmDescription &Description, /* out */ int &BasePos)/* overload */;
extern PACKAGE TJclBorUmResult __fastcall PeBorUnmangleName(const AnsiString Name, /* out */ AnsiString &Unmangled, /* out */ TJclBorUmDescription &Description)/* overload */;
extern PACKAGE TJclBorUmResult __fastcall PeBorUnmangleName(const AnsiString Name, /* out */ AnsiString &Unmangled)/* overload */;
extern PACKAGE AnsiString __fastcall PeBorUnmangleName(const AnsiString Name)/* overload */;
extern PACKAGE TJclPeUmResult __fastcall PeIsNameMangled(const AnsiString Name);
extern PACKAGE bool __fastcall UndecorateSymbolName(const AnsiString DecoratedName, /* out */ AnsiString &UnMangled, unsigned Flags);
extern PACKAGE TJclPeUmResult __fastcall PeUnmangleName(const AnsiString Name, /* out */ AnsiString &Unmangled);

}	/* namespace Jclpeimage */
using namespace Jclpeimage;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclpeimage
