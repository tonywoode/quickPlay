// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Zmstructs.pas' rev: 10.00

#ifndef ZmstructsHPP
#define ZmstructsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Zmstructs
{
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct ZipLocalHeader
{
	
public:
	unsigned HeaderSig;
	Word VersionNeed;
	Word Flag;
	Word ComprMethod;
	Word ModifTime;
	Word ModifDate;
	unsigned CRC32;
	unsigned ComprSize;
	unsigned UnComprSize;
	Word FileNameLen;
	Word ExtraLen;
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct ZipCentralHeader
{
	
public:
	unsigned HeaderSig;
	Byte VersionMadeBy0;
	Byte VersionMadeBy1;
	Word VersionNeed;
	Word Flag;
	Word ComprMethod;
	Word ModifTime;
	Word ModifDate;
	unsigned CRC32;
	unsigned ComprSize;
	unsigned UnComprSize;
	Word FileNameLen;
	Word ExtraLen;
	Word FileComLen;
	Word DiskStart;
	Word IntFileAtt;
	unsigned ExtFileAtt;
	unsigned RelOffLocal;
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct ZipDataDescriptor
{
	
public:
	unsigned DataDescSig;
	unsigned CRC32;
	unsigned ComprSize;
	unsigned UnComprSize;
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct ZipEndOfCentral
{
	
public:
	unsigned HeaderSig;
	Word ThisDiskNo;
	Word CentralDiskNo;
	Word CentralEntries;
	Word TotalEntries;
	unsigned CentralSize;
	unsigned CentralOffSet;
	Word ZipCommentLen;
} ;
#pragma pack(pop)

typedef ZipEndOfCentral *pZipEndOfCentral;

typedef _IMAGE_SECTION_HEADER *pISH;

#pragma pack(push,1)
struct PEheader
{
	
public:
	unsigned signature;
	#pragma pack(push,1)
	_IMAGE_FILE_HEADER _head;
	#pragma pack(pop)
	#pragma pack(push,1)
	_IMAGE_OPTIONAL_HEADER opt_head;
	#pragma pack(pop)
	#pragma pack(push,1)
	_IMAGE_SECTION_HEADER section_header;
	#pragma pack(pop)
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct IMAGE_RESOURCE_DIR_STRING_U
{
	
public:
	Word Length;
	WideChar NameString[1];
} ;
#pragma pack(pop)

typedef IMAGE_RESOURCE_DIR_STRING_U *pIRDSU;

#pragma pack(push,1)
struct ZMStructs__1
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
struct ZMStructs__2
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
struct IMAGE_RESOURCE_DIRECTORY_ENTRY
{
	
public:
	#pragma pack(push,1)
	ZMStructs__1 un1;
	#pragma pack(pop)
	#pragma pack(push,1)
	ZMStructs__2 un2;
	#pragma pack(pop)
} ;
#pragma pack(pop)

typedef IMAGE_RESOURCE_DIRECTORY_ENTRY *pIRDirE;

typedef _IMAGE_DATA_DIRECTORY *pIDD;

#pragma pack(push,1)
struct IMAGE_RESOURCE_DIRECTORY
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

typedef IMAGE_RESOURCE_DIRECTORY *pIRD;

#pragma pack(push,1)
struct IMAGE_RESOURCE_DATA_ENTRY
{
	
public:
	unsigned OffsetToData;
	unsigned Size;
	unsigned CodePage;
	unsigned Reserved;
} ;
#pragma pack(pop)

typedef IMAGE_RESOURCE_DATA_ENTRY *pIRDatE;

//-- var, const, procedure ---------------------------------------------------
static const int LocalFileHeaderSig = 0x4034b50;
static const int CentralFileHeaderSig = 0x2014b50;
static const int EndCentralDirSig = 0x6054b50;
static const int ExtLocalSig = 0x8074b50;
static const int EndCentral64Sig = 0x6064b50;
static const int EOC64LocatorSig = 0x7064b50;

}	/* namespace Zmstructs */
using namespace Zmstructs;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Zmstructs
