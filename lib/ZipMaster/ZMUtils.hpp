// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Zmutils.pas' rev: 10.00

#ifndef ZmutilsHPP
#define ZmutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Zmutils
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TPathSlashDirection { psdExternal, psdInternal };
#pragma option pop

#pragma pack(push,1)
struct I64Rec
{
	
	union
	{
		struct 
		{
			unsigned Lo;
			unsigned Hi;
			
		};
		struct 
		{
			__int64 I;
			
		};
		
	};
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const Shortint zqbStartEXE = 0x1;
static const Shortint zqbStartLocal = 0x2;
static const Shortint zqbStartSpan = 0x4;
static const Shortint zqbStartCentral = 0x8;
static const Shortint zqbGoodComment = 0x10;
static const Shortint zqbHasLocal = 0x20;
static const Shortint zqbHasCentral = 0x40;
static const Byte zqbHasEOC = 0x80;
static const Shortint zqFileError = -7;
static const Shortint zqGeneralError = -9;
extern PACKAGE unsigned __fastcall Lo64(__int64 i);
extern PACKAGE unsigned __fastcall Hi64(__int64 i);
extern PACKAGE __int64 __fastcall FileSeek64(int Handle, const __int64 Offset, int Origin);
extern PACKAGE bool __fastcall FileNameMatch(const AnsiString pat, const AnsiString str);
extern PACKAGE bool __fastcall IsWild(const AnsiString fspec);
extern PACKAGE bool __fastcall ForceDirectory(const AnsiString Dir);
extern PACKAGE bool __fastcall DirExists(const AnsiString Fname);
extern PACKAGE AnsiString __fastcall SetSlash(const AnsiString path, TPathSlashDirection dir);
extern PACKAGE AnsiString __fastcall DelimitPath(const AnsiString path, bool sep);
extern PACKAGE AnsiString __fastcall PathConcat(const AnsiString path, const AnsiString extra);
extern PACKAGE int __fastcall EraseFile(const AnsiString Fname, bool permanent);
extern PACKAGE int __fastcall QueryZip(const AnsiString Fname);
extern PACKAGE AnsiString __fastcall GetVolumeLabel(const AnsiString drive);
extern PACKAGE bool __fastcall IsSameFile(const AnsiString Fname1, const AnsiString Fname2);
extern PACKAGE void __fastcall File_Close(int &fh);
extern PACKAGE bool __fastcall IsWinXP(void);
extern PACKAGE System::TDateTime __fastcall FileDateToLocalDateTime(int stamp);

}	/* namespace Zmutils */
using namespace Zmutils;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Zmutils
