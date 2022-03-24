// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Sfxstructs.pas' rev: 10.00

#ifndef SfxstructsHPP
#define SfxstructsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Sfxstructs
{
//-- type declarations -------------------------------------------------------
struct TZipLocalHeader;
typedef TZipLocalHeader *PZipLocalHeader;

#pragma pack(push,1)
struct TZipLocalHeader
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

typedef TZipLocalHeader  ZipLocalHeader;

struct TZipCentralHeader;
typedef TZipCentralHeader *PZipCentralHeader;

#pragma pack(push,1)
struct TZipCentralHeader
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

typedef TZipCentralHeader  ZipCentralHeader;

struct TZipEndOfCentral;
typedef TZipEndOfCentral *PZipEndOfCentral;

#pragma pack(push,1)
struct TZipEndOfCentral
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

typedef TZipEndOfCentral  ZipEndOfCentral;

struct TZipExtLocalHeader;
typedef TZipExtLocalHeader *PZipExtLocalHeader;

#pragma pack(push,1)
struct TZipExtLocalHeader
{
	
public:
	unsigned DataDescSig;
	unsigned CRC32;
	unsigned ComprSize;
	unsigned UnComprSize;
} ;
#pragma pack(pop)

typedef TZipExtLocalHeader  ZipExtLocalHeader;

typedef TZipExtLocalHeader  ZipDataDescriptor;

typedef Byte TSFXBuffer[8192];

typedef Byte *PSFXBuffer;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE unsigned ZipLocalHeaderSig;
extern PACKAGE unsigned ZipCentralHeaderSig;
extern PACKAGE unsigned ZipEndOfCentralSig;
extern PACKAGE unsigned ZipExtLocalHeaderSig;
static const Word SFXBufSize = 0x2000;

}	/* namespace Sfxstructs */
using namespace Sfxstructs;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Sfxstructs
