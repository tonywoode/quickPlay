// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Dzutils.pas' rev: 10.00

#ifndef DzutilsHPP
#define DzutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Zipmsg.hpp>	// Pascal unit
#include <Sfxstructs.hpp>	// Pascal unit
#include <Shellapi.hpp>	// Pascal unit
#include <Zmxcpt.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dzutils
{
//-- type declarations -------------------------------------------------------
typedef EZipMaster EDelphiZip;
;

#pragma option push -b-
enum THowToDeleteFile { htdFinal, htdAllowUndo };
#pragma option pop

typedef THowToDeleteFile TDeleteOpts;

struct _IMAGE_RESOURCE_DIRECTORY;
typedef _IMAGE_RESOURCE_DIRECTORY *PImageResourceDirectory;

#pragma pack(push,1)
struct _IMAGE_RESOURCE_DIRECTORY
{
	
public:
	unsigned Characteristics;
	unsigned TimeDateStamp;
	Word MajorVersion;
	Word MinorVersion;
	Word NumberOfNamedEntries;
	Word NumberOfIdEntries;
} ;
#pragma pack(pop)

typedef _IMAGE_RESOURCE_DIRECTORY  TImageResourceDirectory;

struct _IMAGE_RESOURCE_DIRECTORY_ENTRY;
typedef _IMAGE_RESOURCE_DIRECTORY_ENTRY *PImageResourceDirectoryEntry;

#pragma pack(push,1)
struct DZUtils__1
{
	
	union
	{
		struct 
		{
			Word Id;
			
		};
		struct 
		{
			unsigned Name;
			
		};
		struct 
		{
			unsigned NameOffset;
			
		};
		struct 
		{
			unsigned NameIsString;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct DZUtils__2
{
	
	union
	{
		struct 
		{
			unsigned OffsetToDirectory;
			
		};
		struct 
		{
			unsigned DataIsDirectory;
			
		};
		struct 
		{
			unsigned OffsetToData;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct _IMAGE_RESOURCE_DIRECTORY_ENTRY
{
	
public:
	#pragma pack(push,1)
	DZUtils__1 un1;
	#pragma pack(pop)
	#pragma pack(push,1)
	DZUtils__2 un2;
	#pragma pack(pop)
} ;
#pragma pack(pop)

typedef _IMAGE_RESOURCE_DIRECTORY_ENTRY  TImageResourceDirectoryEntry;

struct _IMAGE_RESOURCE_DATA_ENTRY;
typedef _IMAGE_RESOURCE_DATA_ENTRY *PImageResourceDataEntry;

#pragma pack(push,1)
struct _IMAGE_RESOURCE_DATA_ENTRY
{
	
public:
	unsigned OffsetToData;
	unsigned Size;
	unsigned CodePage;
	unsigned Reserved;
} ;
#pragma pack(pop)

typedef _IMAGE_RESOURCE_DATA_ENTRY  TImageResourceDataEntry;

struct ICONDIR;
typedef ICONDIR *PIconDir;

#pragma pack(push,1)
struct ICONDIR
{
	
public:
	Word Reserved;
	Word ResType;
	Word ResCount;
} ;
#pragma pack(pop)

typedef ICONDIR  TIconDir;

struct ICONDIRENTRY;
typedef ICONDIRENTRY *PIconDirEntry;

#pragma pack(push,1)
struct ICONDIRENTRY
{
	
public:
	Byte bWidth;
	Byte bHeight;
	Byte bColorCount;
	Byte bReserved;
	Word wPlanes;
	Word wBitCount;
	unsigned dwBytesInRes;
	unsigned dwImageOffset;
} ;
#pragma pack(pop)

typedef ICONDIRENTRY  TIconDirEntry;

//-- var, const, procedure ---------------------------------------------------
static const unsigned IMAGE_RESOURCE_DATA_IS_DIRECTORY = 0x80000000;
extern PACKAGE void __fastcall StartWaitCursor(void);
extern PACKAGE void __fastcall StopWaitCursor(void);
extern PACKAGE void __fastcall EraseFile(const AnsiString sFile, const THowToDeleteFile HowTo);
extern PACKAGE void __fastcall ReplaceIcon(Classes::TStream* str, Graphics::TIcon* oIcon);
extern PACKAGE void __fastcall FileReplaceIcon(const AnsiString sFile, Graphics::TIcon* oIcon);
extern PACKAGE void __fastcall CopyAndAdjustCentralStructures(Classes::TStream* strIn, Classes::TStream* strOut, const int iNumEntries, const int iOffsetDelta, const int iThisDisk);
extern PACKAGE void __fastcall CopyStrippedCentralStructures(Classes::TStream* strIn, Classes::TStream* strOut, const int iNumEntries, const int iOffsetDelta, const int iThisDisk);
extern PACKAGE int __fastcall ReadEndOfCentral(Classes::TStream* str, Sfxstructs::TZipEndOfCentral &recEOC);
extern PACKAGE int __fastcall FindStartOfZipData(Classes::TStream* str);

}	/* namespace Dzutils */
using namespace Dzutils;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dzutils
