// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Pcre.pas' rev: 10.00

#ifndef PcreHPP
#define PcreHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include "pcre.h"

namespace Pcre
{
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct real_pcre
{
	
} ;
#pragma pack(pop)

typedef real_pcre  TPCRE;

typedef real_pcre *PPCRE;

#pragma pack(push,1)
struct real_pcre_extra
{
	
public:
	unsigned flags;
	void *study_data;
	unsigned match_limit;
	void *callout_data;
	char *tables;
	unsigned match_limit_recursion;
} ;
#pragma pack(pop)

typedef real_pcre_extra  TPCREExtra;

typedef real_pcre_extra *PPCREExtra;

#pragma pack(push,1)
struct pcre_callout_block
{
	
public:
	int version;
	int callout_number;
	int *offset_vector;
	char *subject;
	int subject_length;
	int start_match;
	int current_position;
	int capture_top;
	int capture_last;
	void *callout_data;
	int pattern_position;
	int next_item_length;
} ;
#pragma pack(pop)

typedef void __fastcall (*TPCRELibNotLoadedHandler)(void);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TPCRELibNotLoadedHandler LibNotLoadedHandler;
extern PACKAGE bool __fastcall IsPCRELoaded(void);
extern PACKAGE bool __fastcall LoadPCRE(void);
extern PACKAGE void __fastcall UnloadPCRE(void);

}	/* namespace Pcre */
using namespace Pcre;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Pcre
