// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Zlibh.pas' rev: 10.00

#ifndef ZlibhHPP
#define ZlibhHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#define ZEXPORT __fastcall
#define ZEXPORTVA __cdecl
#define __MACTYPES__
#include <zutil.h>

namespace Zlibh
{
//-- type declarations -------------------------------------------------------
typedef void * __fastcall (*TFNAllocFunc)(void * opaque, unsigned items, unsigned size);

typedef void __fastcall (*TFNFreeFunc)(void * opaque, void * address);

typedef internal_state  TInternalState;

typedef internal_state *PInternalState;

typedef z_stream_s  TZStreamRec;

typedef z_stream_s *PZStreamRec;

typedef unsigned __fastcall (*TFNInFunc)(void * p1, System::PByte p2);

typedef int __fastcall (*TFNOutFunc)(void * p1, System::PByte p2, unsigned p3);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall IsZLibLoaded(void);
extern PACKAGE bool __fastcall LoadZLib(void);
extern PACKAGE void __fastcall UnloadZLib(void);

}	/* namespace Zlibh */
using namespace Zlibh;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Zlibh
