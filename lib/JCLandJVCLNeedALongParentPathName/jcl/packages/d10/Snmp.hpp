// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Snmp.pas' rev: 10.00

#ifndef SnmpHPP
#define SnmpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <snmp.h>

namespace Snmp
{
//-- type declarations -------------------------------------------------------
struct TAsnOctetString;
typedef TAsnOctetString *PAsnOctetString;

struct TAsnOctetString
{
	
public:
	char *stream;
	unsigned length;
	bool dynamic_;
} ;

struct TAsnObjectIdentifier;
typedef TAsnObjectIdentifier *PAsnObjectIdentifier;

struct TAsnObjectIdentifier
{
	
public:
	unsigned idLength;
	unsigned *ids;
} ;

struct TAsnAny;
typedef TAsnAny *PAsnAny;

struct TAsnAny
{
	
public:
	Byte asnType;
	union
	{
		struct 
		{
			TAsnOctetString arbitrary;
			
		};
		struct 
		{
			unsigned ticks;
			
		};
		struct 
		{
			unsigned gauge;
			
		};
		struct 
		{
			unsigned counter;
			
		};
		struct 
		{
			TAsnOctetString address;
			
		};
		struct 
		{
			TAsnOctetString sequence;
			
		};
		struct 
		{
			TAsnObjectIdentifier object_;
			
		};
		struct 
		{
			TAsnOctetString bits;
			
		};
		struct 
		{
			TAsnOctetString string_;
			
		};
		struct 
		{
			ULARGE_INTEGER counter64;
			
		};
		struct 
		{
			unsigned unsigned32;
			
		};
		struct 
		{
			int number;
			
		};
		
	};
} ;

typedef TAsnObjectIdentifier  TAsnObjectName;

typedef TAsnAny  TAsnObjectSyntax;

struct TSnmpVarBind
{
	
public:
	TAsnObjectIdentifier name;
	TAsnAny value;
} ;

typedef TSnmpVarBind *PSnmpVarBind;

struct TSnmpVarBindList;
typedef TSnmpVarBindList *PSnmpVarBindList;

struct TSnmpVarBindList
{
	
public:
	TSnmpVarBind *list;
	unsigned len;
} ;

typedef bool __stdcall (*TSnmpExtensionInit)(unsigned dwUptimeReference, unsigned &phSubagentTrapEvent, PAsnObjectIdentifier &pFirstSupportedRegion);

typedef bool __stdcall (*TSnmpExtensionInitEx)(PAsnObjectIdentifier &pNextSupportedRegion);

typedef bool __stdcall (*TSnmpExtensionMonitor)(void * pAgentMgmtData);

typedef bool __stdcall (*TSnmpExtensionQuery)(Byte bPduType, TSnmpVarBindList &pVarBindList, int &pErrorStatus, int &pErrorIndex);

typedef bool __stdcall (*TSnmpExtensionQueryEx)(unsigned nRequestType, unsigned nTransactionId, PSnmpVarBindList &pVarBindList, PAsnOctetString &pContextInfo, int &pErrorStatus, int &pErrorIndex);

typedef bool __stdcall (*TSnmpExtensionTrap)(PAsnObjectIdentifier pEnterpriseOid, int &pGenericTrapId, int &pSpecificTrapId, unsigned &pTimeStamp, PSnmpVarBindList &pVarBindList);

typedef void __stdcall (*TSnmpExtensionClose)(void);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall SnmpExtensionLoaded(void);
extern PACKAGE bool __fastcall LoadSnmpExtension(const AnsiString LibName);
extern PACKAGE bool __fastcall UnloadSnmpExtension(void);
extern PACKAGE bool __fastcall SnmpLoaded(void);
extern PACKAGE bool __fastcall UnloadSnmp(void);
extern PACKAGE bool __fastcall LoadSnmp(void);

}	/* namespace Snmp */
using namespace Snmp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Snmp
