// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclsysinfo.pas' rev: 10.00

#ifndef JclsysinfoHPP
#define JclsysinfoHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Activex.hpp>	// Pascal unit
#include <Shlobj.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclresources.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclsysinfo
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TEnvironmentOption { eoLocalMachine, eoCurrentUser, eoAdditional };
#pragma option pop

typedef Set<TEnvironmentOption, eoLocalMachine, eoAdditional>  TEnvironmentOptions;

#pragma option push -b-
enum TAPMLineStatus { alsOffline, alsOnline, alsUnknown };
#pragma option pop

#pragma option push -b-
enum TAPMBatteryFlag { abfHigh, abfLow, abfCritical, abfCharging, abfNoBattery, abfUnknown };
#pragma option pop

typedef Set<TAPMBatteryFlag, abfHigh, abfUnknown>  TAPMBatteryFlags;

#pragma option push -b-
enum TFileSystemFlag { fsCaseSensitive, fsCasePreservedNames, fsSupportsUnicodeOnDisk, fsPersistentACLs, fsSupportsFileCompression, fsSupportsVolumeQuotas, fsSupportsSparseFiles, fsSupportsReparsePoints, fsSupportsRemoteStorage, fsVolumeIsCompressed, fsSupportsObjectIds, fsSupportsEncryption, fsSupportsNamedStreams, fsVolumeIsReadOnly };
#pragma option pop

typedef Set<TFileSystemFlag, fsCaseSensitive, fsVolumeIsReadOnly>  TFileSystemFlags;

#pragma option push -b-
enum TJclTerminateAppResult { taError, taClean, taKill };
#pragma option pop

#pragma option push -b-
enum TWindowsVersion { wvUnknown, wvWin95, wvWin95OSR2, wvWin98, wvWin98SE, wvWinME, wvWinNT31, wvWinNT35, wvWinNT351, wvWinNT4, wvWin2000, wvWinXP, wvWin2003, wvWinXP64, wvWin2003R2, wvWinVista, wvWinServer2008, wvWin7, wvWinServer2008R2 };
#pragma option pop

#pragma option push -b-
enum TWindowsEdition { weUnknown, weWinXPHome, weWinXPPro, weWinXPHomeN, weWinXPProN, weWinXPHomeK, weWinXPProK, weWinXPHomeKN, weWinXPProKN, weWinXPStarter, weWinXPMediaCenter, weWinXPTablet, weWinVistaStarter, weWinVistaHomeBasic, weWinVistaHomeBasicN, weWinVistaHomePremium, weWinVistaBusiness, weWinVistaBusinessN, weWinVistaEnterprise, weWinVistaUltimate, weWin7Starter, weWin7HomeBasic, weWin7HomePremium, weWin7Professional, weWin7Enterprise, weWin7Ultimate };
#pragma option pop

#pragma option push -b-
enum TNtProductType { ptUnknown, ptWorkStation, ptServer, ptAdvancedServer, ptPersonal, ptProfessional, ptDatacenterServer, ptEnterprise, ptWebEdition };
#pragma option pop

#pragma option push -b-
enum TProcessorArchitecture { paUnknown, pax8632, pax8664, paIA64 };
#pragma option pop

#pragma option push -b-
enum TTLBInformation { tiEntries, tiAssociativity };
#pragma option pop

#pragma option push -b-
enum TCacheInformation { ciLineSize, ciLinesPerTag, ciAssociativity, ciSize };
#pragma option pop

struct TIntelSpecific
{
	
public:
	unsigned L2Cache;
	Byte CacheDescriptors[16];
	Byte BrandID;
	Byte FlushLineSize;
	Byte APICID;
	unsigned ExFeatures;
	unsigned Ex64Features;
	unsigned Ex64Features2;
	Byte PhysicalAddressBits;
	Byte VirtualAddressBits;
} ;

struct TCyrixSpecific
{
	
public:
	Byte L1CacheInfo[4];
	Byte TLBInfo[4];
} ;

#pragma pack(push,1)
struct TAMDSpecific
{
	
public:
	unsigned ExFeatures;
	unsigned ExFeatures2;
	unsigned Features2;
	Byte BrandID;
	Byte FlushLineSize;
	Byte APICID;
	Word ExBrandID;
	Byte L1MByteInstructionTLB[2];
	Byte L1MByteDataTLB[2];
	Byte L1KByteInstructionTLB[2];
	Byte L1KByteDataTLB[2];
	Byte L1DataCache[4];
	Byte L1InstructionCache[4];
	Byte L2MByteInstructionTLB[2];
	Byte L2MByteDataTLB[2];
	Byte L2KByteDataTLB[2];
	Byte L2KByteInstructionTLB[2];
	unsigned L2Cache;
	unsigned L3Cache;
	unsigned AdvancedPowerManagement;
	Byte PhysicalAddressSize;
	Byte VirtualAddressSize;
} ;
#pragma pack(pop)

struct TVIASpecific
{
	
public:
	unsigned ExFeatures;
	Byte DataTLB[2];
	Byte InstructionTLB[2];
	Byte L1DataCache[4];
	Byte L1InstructionCache[4];
	unsigned L2DataCache;
} ;

struct TTransmetaSpecific
{
	
public:
	unsigned ExFeatures;
	Byte DataTLB[2];
	Byte CodeTLB[2];
	Byte L1DataCache[4];
	Byte L1CodeCache[4];
	unsigned L2Cache;
	unsigned RevisionABCD;
	unsigned RevisionXXXX;
	unsigned Frequency;
	unsigned CodeMorphingABCD;
	unsigned CodeMorphingXXXX;
	unsigned TransmetaFeatures;
	char TransmetaInformations[65];
	unsigned CurrentVoltage;
	unsigned CurrentFrequency;
	unsigned CurrentPerformance;
} ;

#pragma option push -b-
enum TCacheFamily { cfInstructionTLB, cfDataTLB, cfL1InstructionCache, cfL1DataCache, cfL2Cache, cfL2TLB, cfL3Cache, cfTrace, cfOther };
#pragma option pop

struct TCacheInfo
{
	
public:
	Byte D;
	TCacheFamily Family;
	unsigned Size;
	Byte WaysOfAssoc;
	Byte LineSize;
	Byte LinePerSector;
	unsigned Entries;
	System::TResStringRec *I;
} ;

struct TFreqInfo
{
	
public:
	__int64 RawFreq;
	__int64 NormFreq;
	__int64 InCycles;
	__int64 ExTicks;
} ;

#pragma option push -b-
enum TSSESupport { sse, sse2, sse3, ssse3, sse4A, sse4B, sse5, avx };
#pragma option pop

typedef Set<TSSESupport, sse, avx>  TSSESupports;

struct TCpuInfo
{
	
public:
	bool HasInstruction;
	bool MMX;
	bool ExMMX;
	bool _3DNow;
	bool Ex3DNow;
	TSSESupports SSE;
	bool IsFDIVOK;
	bool Is64Bits;
	bool DEPCapable;
	bool HasCacheInfo;
	bool HasExtendedInfo;
	Byte PType;
	Byte Family;
	Byte ExtendedFamily;
	Byte Model;
	Byte ExtendedModel;
	Byte Stepping;
	unsigned Features;
	TFreqInfo FrequencyInfo;
	char VendorIDString[12];
	char Manufacturer[10];
	char CpuName[48];
	unsigned L1DataCacheSize;
	Byte L1DataCacheLineSize;
	Byte L1DataCacheAssociativity;
	unsigned L1InstructionCacheSize;
	Byte L1InstructionCacheLineSize;
	Byte L1InstructionCacheAssociativity;
	unsigned L2CacheSize;
	Byte L2CacheLineSize;
	Byte L2CacheAssociativity;
	unsigned L3CacheSize;
	Byte L3CacheLineSize;
	Byte L3CacheAssociativity;
	Byte L3LinesPerSector;
	Byte LogicalCore;
	Byte PhysicalCore;
	bool HyperThreadingTechnology;
	Byte CpuType;
	union
	{
		struct 
		{
			TVIASpecific ViaSpecific;
			
		};
		struct 
		{
			TTransmetaSpecific TransmetaSpecific;
			
		};
		struct 
		{
			TAMDSpecific AMDSpecific;
			
		};
		struct 
		{
			TCyrixSpecific CyrixSpecific;
			
		};
		struct 
		{
			TIntelSpecific IntelSpecific;
			
		};
		
	};
} ;

#pragma option push -b-
enum TOSEnabledFeature { oefFPU, oefSSE, oefAVX };
#pragma option pop

typedef Set<TOSEnabledFeature, oefFPU, oefAVX>  TOSEnabledFeatures;

#pragma option push -b-
enum TFreeSysResKind { rtSystem, rtGdi, rtUser };
#pragma option pop

struct TFreeSystemResources
{
	
public:
	int SystemRes;
	int GdiRes;
	int UserRes;
} ;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool IsWin95;
extern PACKAGE bool IsWin95OSR2;
extern PACKAGE bool IsWin98;
extern PACKAGE bool IsWin98SE;
extern PACKAGE bool IsWinME;
extern PACKAGE bool IsWinNT;
extern PACKAGE bool IsWinNT3;
extern PACKAGE bool IsWinNT31;
extern PACKAGE bool IsWinNT35;
extern PACKAGE bool IsWinNT351;
extern PACKAGE bool IsWinNT4;
extern PACKAGE bool IsWin2K;
extern PACKAGE bool IsWinXP;
extern PACKAGE bool IsWin2003;
extern PACKAGE bool IsWinXP64;
extern PACKAGE bool IsWin2003R2;
extern PACKAGE bool IsWinVista;
extern PACKAGE bool IsWinServer2008;
extern PACKAGE bool IsWin7;
extern PACKAGE bool IsWinServer2008R2;
static const Shortint CPU_TYPE_INTEL = 0x1;
static const Shortint CPU_TYPE_CYRIX = 0x2;
static const Shortint CPU_TYPE_AMD = 0x3;
static const Shortint CPU_TYPE_TRANSMETA = 0x4;
static const Shortint CPU_TYPE_VIA = 0x5;
extern PACKAGE char VendorIDIntel[12];
extern PACKAGE char VendorIDCyrix[12];
extern PACKAGE char VendorIDAMD[12];
extern PACKAGE char VendorIDTransmeta[12];
extern PACKAGE char VendorIDVIA[12];
static const Shortint BIT_0 = 0x1;
static const Shortint BIT_1 = 0x2;
static const Shortint BIT_2 = 0x4;
static const Shortint BIT_3 = 0x8;
static const Shortint BIT_4 = 0x10;
static const Shortint BIT_5 = 0x20;
static const Shortint BIT_6 = 0x40;
static const Byte BIT_7 = 0x80;
static const Word BIT_8 = 0x100;
static const Word BIT_9 = 0x200;
static const Word BIT_10 = 0x400;
static const Word BIT_11 = 0x800;
static const Word BIT_12 = 0x1000;
static const Word BIT_13 = 0x2000;
static const Word BIT_14 = 0x4000;
static const Word BIT_15 = 0x8000;
static const int BIT_16 = 0x10000;
static const int BIT_17 = 0x20000;
static const int BIT_18 = 0x40000;
static const int BIT_19 = 0x80000;
static const int BIT_20 = 0x100000;
static const int BIT_21 = 0x200000;
static const int BIT_22 = 0x400000;
static const int BIT_23 = 0x800000;
static const int BIT_24 = 0x1000000;
static const int BIT_25 = 0x2000000;
static const int BIT_26 = 0x4000000;
static const int BIT_27 = 0x8000000;
static const int BIT_28 = 0x10000000;
static const int BIT_29 = 0x20000000;
static const int BIT_30 = 0x40000000;
static const unsigned BIT_31 = 0x80000000;
static const Shortint FPU_FLAG = 0x1;
static const Shortint VME_FLAG = 0x2;
static const Shortint DE_FLAG = 0x4;
static const Shortint PSE_FLAG = 0x8;
static const Shortint TSC_FLAG = 0x10;
static const Shortint MSR_FLAG = 0x20;
static const Shortint PAE_FLAG = 0x40;
static const Byte MCE_FLAG = 0x80;
static const Word CX8_FLAG = 0x100;
static const Word APIC_FLAG = 0x200;
static const Word BIT_10_FLAG = 0x400;
static const Word SEP_FLAG = 0x800;
static const Word MTRR_FLAG = 0x1000;
static const Word PGE_FLAG = 0x2000;
static const Word MCA_FLAG = 0x4000;
static const Word CMOV_FLAG = 0x8000;
static const int PAT_FLAG = 0x10000;
static const int PSE36_FLAG = 0x20000;
static const int PSN_FLAG = 0x40000;
static const int CLFLSH_FLAG = 0x80000;
static const int BIT_20_FLAG = 0x100000;
static const int DS_FLAG = 0x200000;
static const int ACPI_FLAG = 0x400000;
static const int MMX_FLAG = 0x800000;
static const int FXSR_FLAG = 0x1000000;
static const int SSE_FLAG = 0x2000000;
static const int SSE2_FLAG = 0x4000000;
static const int SS_FLAG = 0x8000000;
static const int HTT_FLAG = 0x10000000;
static const int TM_FLAG = 0x20000000;
static const int BIT_30_FLAG = 0x40000000;
static const unsigned PBE_FLAG = 0x80000000;
static const Shortint INTEL_FPU = 0x1;
static const Shortint INTEL_VME = 0x2;
static const Shortint INTEL_DE = 0x4;
static const Shortint INTEL_PSE = 0x8;
static const Shortint INTEL_TSC = 0x10;
static const Shortint INTEL_MSR = 0x20;
static const Shortint INTEL_PAE = 0x40;
static const Byte INTEL_MCE = 0x80;
static const Word INTEL_CX8 = 0x100;
static const Word INTEL_APIC = 0x200;
static const Word INTEL_BIT_10 = 0x400;
static const Word INTEL_SEP = 0x800;
static const Word INTEL_MTRR = 0x1000;
static const Word INTEL_PGE = 0x2000;
static const Word INTEL_MCA = 0x4000;
static const Word INTEL_CMOV = 0x8000;
static const int INTEL_PAT = 0x10000;
static const int INTEL_PSE36 = 0x20000;
static const int INTEL_PSN = 0x40000;
static const int INTEL_CLFLSH = 0x80000;
static const int INTEL_BIT_20 = 0x100000;
static const int INTEL_DS = 0x200000;
static const int INTEL_ACPI = 0x400000;
static const int INTEL_MMX = 0x800000;
static const int INTEL_FXSR = 0x1000000;
static const int INTEL_SSE = 0x2000000;
static const int INTEL_SSE2 = 0x4000000;
static const int INTEL_SS = 0x8000000;
static const int INTEL_HTT = 0x10000000;
static const int INTEL_TM = 0x20000000;
static const int INTEL_IA64 = 0x40000000;
static const unsigned INTEL_PBE = 0x80000000;
static const Shortint EINTEL_SSE3 = 0x1;
static const Shortint EINTEL_PCLMULQDQ = 0x2;
static const Shortint EINTEL_DTES64 = 0x4;
static const Shortint EINTEL_MONITOR = 0x8;
static const Shortint EINTEL_DSCPL = 0x10;
static const Shortint EINTEL_VMX = 0x20;
static const Shortint EINTEL_SMX = 0x40;
static const Byte EINTEL_EST = 0x80;
static const Word EINTEL_TM2 = 0x100;
static const Word EINTEL_SSSE3 = 0x200;
static const Word EINTEL_CNXTID = 0x400;
static const Word EINTEL_BIT_11 = 0x800;
static const Word EINTEL_FMA = 0x1000;
static const Word EINTEL_CX16 = 0x2000;
static const Word EINTEL_XTPR = 0x4000;
static const Word EINTEL_PDCM = 0x8000;
static const int EINTEL_BIT_16 = 0x10000;
static const int EINTEL_BIT_17 = 0x20000;
static const int EINTEL_DCA = 0x40000;
static const int EINTEL_SSE4_1 = 0x80000;
static const int EINTEL_SSE4_2 = 0x100000;
static const int EINTEL_X2APIC = 0x200000;
static const int EINTEL_MOVBE = 0x400000;
static const int EINTEL_POPCNT = 0x800000;
static const int EINTEL_BIT_24 = 0x1000000;
static const int EINTEL_AES = 0x2000000;
static const int EINTEL_XSAVE = 0x4000000;
static const int EINTEL_OSXSAVE = 0x8000000;
static const int EINTEL_AVX = 0x10000000;
static const int EINTEL_BIT_29 = 0x20000000;
static const int EINTEL_BIT_30 = 0x40000000;
static const unsigned EINTEL_BIT_31 = 0x80000000;
static const Shortint EINTEL64_BIT_0 = 0x1;
static const Shortint EINTEL64_BIT_1 = 0x2;
static const Shortint EINTEL64_BIT_2 = 0x4;
static const Shortint EINTEL64_BIT_3 = 0x8;
static const Shortint EINTEL64_BIT_4 = 0x10;
static const Shortint EINTEL64_BIT_5 = 0x20;
static const Shortint EINTEL64_BIT_6 = 0x40;
static const Byte EINTEL64_BIT_7 = 0x80;
static const Word EINTEL64_BIT_8 = 0x100;
static const Word EINTEL64_BIT_9 = 0x200;
static const Word EINTEL64_BIT_10 = 0x400;
static const Word EINTEL64_SYS = 0x800;
static const Word EINTEL64_BIT_12 = 0x1000;
static const Word EINTEL64_BIT_13 = 0x2000;
static const Word EINTEL64_BIT_14 = 0x4000;
static const Word EINTEL64_BIT_15 = 0x8000;
static const int EINTEL64_BIT_16 = 0x10000;
static const int EINTEL64_BIT_17 = 0x20000;
static const int EINTEL64_BIT_18 = 0x40000;
static const int EINTEL64_BIT_19 = 0x80000;
static const int EINTEL64_XD = 0x100000;
static const int EINTEL64_BIT_21 = 0x200000;
static const int EINTEL64_BIT_22 = 0x400000;
static const int EINTEL64_BIT_23 = 0x800000;
static const int EINTEL64_BIT_24 = 0x1000000;
static const int EINTEL64_BIT_25 = 0x2000000;
static const int EINTEL64_BIT_26 = 0x4000000;
static const int EINTEL64_RDTSCP = 0x8000000;
static const int EINTEL64_BIT_28 = 0x10000000;
static const int EINTEL64_EM64T = 0x20000000;
static const int EINTEL64_BIT_30 = 0x40000000;
static const unsigned EINTEL64_BIT_31 = 0x80000000;
static const Shortint EINTEL64_2_LAHF = 0x1;
static const Shortint EINTEL64_2_BIT_1 = 0x2;
static const Shortint EINTEL64_2_BIT_2 = 0x4;
static const Shortint EINTEL64_2_BIT_3 = 0x8;
static const Shortint EINTEL64_2_BIT_4 = 0x10;
static const Shortint EINTEL64_2_BIT_5 = 0x20;
static const Shortint EINTEL64_2_BIT_6 = 0x40;
static const Byte EINTEL64_2_BIT_7 = 0x80;
static const Word EINTEL64_2_BIT_8 = 0x100;
static const Word EINTEL64_2_BIT_9 = 0x200;
static const Word EINTEL64_2_BIT_10 = 0x400;
static const Word EINTEL64_2_BIT_11 = 0x800;
static const Word EINTEL64_2_BIT_12 = 0x1000;
static const Word EINTEL64_2_BIT_13 = 0x2000;
static const Word EINTEL64_2_BIT_14 = 0x4000;
static const Word EINTEL64_2_BIT_15 = 0x8000;
static const int EINTEL64_2_BIT_16 = 0x10000;
static const int EINTEL64_2_BIT_17 = 0x20000;
static const int EINTEL64_2_BIT_18 = 0x40000;
static const int EINTEL64_2_BIT_19 = 0x80000;
static const int EINTEL64_2_BIT_20 = 0x100000;
static const int EINTEL64_2_BIT_21 = 0x200000;
static const int EINTEL64_2_BIT_22 = 0x400000;
static const int EINTEL64_2_BIT_23 = 0x800000;
static const int EINTEL64_2_BIT_24 = 0x1000000;
static const int EINTEL64_2_BIT_25 = 0x2000000;
static const int EINTEL64_2_BIT_26 = 0x4000000;
static const int EINTEL64_2_BIT_27 = 0x8000000;
static const int EINTEL64_2_BIT_28 = 0x10000000;
static const int EINTEL64_2_BIT_29 = 0x20000000;
static const int EINTEL64_2_BIT_30 = 0x40000000;
static const unsigned EINTEL64_2_BIT_31 = 0x80000000;
static const Shortint AMD_FPU = 0x1;
static const Shortint AMD_VME = 0x2;
static const Shortint AMD_DE = 0x4;
static const Shortint AMD_PSE = 0x8;
static const Shortint AMD_TSC = 0x10;
static const Shortint AMD_MSR = 0x20;
static const Shortint AMD_PAE = 0x40;
static const Byte AMD_MCE = 0x80;
static const Word AMD_CX8 = 0x100;
static const Word AMD_APIC = 0x200;
static const Word AMD_BIT_10 = 0x400;
static const Word AMD_SEP_BIT = 0x800;
static const Word AMD_MTRR = 0x1000;
static const Word AMD_PGE = 0x2000;
static const Word AMD_MCA = 0x4000;
static const Word AMD_CMOV = 0x8000;
static const int AMD_PAT = 0x10000;
static const int AMD_PSE32 = 0x20000;
static const int AMD_BIT_18 = 0x40000;
static const int AMD_CLFLSH = 0x80000;
static const int AMD_BIT_20 = 0x100000;
static const int AMD_BIT_21 = 0x200000;
static const int AMD_BIT_22 = 0x400000;
static const int AMD_MMX = 0x800000;
static const int AMD_FXSR = 0x1000000;
static const int AMD_SSE = 0x2000000;
static const int AMD_SSE2 = 0x4000000;
static const int AMD_BIT_27 = 0x8000000;
static const int AMD_HTT = 0x10000000;
static const int AMD_BIT_29 = 0x20000000;
static const int AMD_BIT_30 = 0x40000000;
static const unsigned AMD_BIT_31 = 0x80000000;
static const Shortint AMD2_SSE3 = 0x1;
static const Shortint AMD2_BIT_1 = 0x2;
static const Shortint AMD2_BIT_2 = 0x4;
static const Shortint AMD2_MONITOR = 0x8;
static const Shortint AMD2_BIT_4 = 0x10;
static const Shortint AMD2_BIT_5 = 0x20;
static const Shortint AMD2_BIT_6 = 0x40;
static const Byte AMD2_BIT_7 = 0x80;
static const Word AMD2_BIT_8 = 0x100;
static const Word AMD2_SSSE3 = 0x200;
static const Word AMD2_BIT_10 = 0x400;
static const Word AMD2_BIT_11 = 0x800;
static const Word AMD2_BIT_12 = 0x1000;
static const Word AMD2_CMPXCHG16B = 0x2000;
static const Word AMD2_BIT_14 = 0x4000;
static const Word AMD2_BIT_15 = 0x8000;
static const int AMD2_BIT_16 = 0x10000;
static const int AMD2_BIT_17 = 0x20000;
static const int AMD2_BIT_18 = 0x40000;
static const int AMD2_SSE41 = 0x80000;
static const int AMD2_BIT_20 = 0x100000;
static const int AMD2_BIT_21 = 0x200000;
static const int AMD2_BIT_22 = 0x400000;
static const int AMD2_POPCNT = 0x800000;
static const int AMD2_BIT_24 = 0x1000000;
static const int AMD2_BIT_25 = 0x2000000;
static const int AMD2_BIT_26 = 0x4000000;
static const int AMD2_BIT_27 = 0x8000000;
static const int AMD2_BIT_28 = 0x10000000;
static const int AMD2_BIT_29 = 0x20000000;
static const int AMD2_BIT_30 = 0x40000000;
static const unsigned AMD2_RAZ = 0x80000000;
static const Shortint EAMD_FPU = 0x1;
static const Shortint EAMD_VME = 0x2;
static const Shortint EAMD_DE = 0x4;
static const Shortint EAMD_PSE = 0x8;
static const Shortint EAMD_TSC = 0x10;
static const Shortint EAMD_MSR = 0x20;
static const Shortint EAMD_PAE = 0x40;
static const Byte EAMD_MCE = 0x80;
static const Word EAMD_CX8 = 0x100;
static const Word EAMD_APIC = 0x200;
static const Word EAMD_BIT_10 = 0x400;
static const Word EAMD_SEP = 0x800;
static const Word EAMD_MTRR = 0x1000;
static const Word EAMD_PGE = 0x2000;
static const Word EAMD_MCA = 0x4000;
static const Word EAMD_CMOV = 0x8000;
static const int EAMD_PAT = 0x10000;
static const int EAMD_PSE2 = 0x20000;
static const int EAMD_BIT_18 = 0x40000;
static const int EAMD_BIT_19 = 0x80000;
static const int EAMD_NX = 0x100000;
static const int EAMD_BIT_21 = 0x200000;
static const int EAMD_EXMMX = 0x400000;
static const int EAMD_MMX = 0x800000;
static const int EAMD_FX = 0x1000000;
static const int EAMD_FFX = 0x2000000;
static const int EAMD_1GBPAGE = 0x4000000;
static const int EAMD_RDTSCP = 0x8000000;
static const int EAMD_BIT_28 = 0x10000000;
static const int EAMD_LONG = 0x20000000;
static const int EAMD_EX3DNOW = 0x40000000;
static const unsigned EAMD_3DNOW = 0x80000000;
static const Shortint EAMD2_LAHF = 0x1;
static const Shortint EAMD2_CMPLEGACY = 0x2;
static const Shortint EAMD2_SVM = 0x4;
static const Shortint EAMD2_EXTAPICSPACE = 0x8;
static const Shortint EAMD2_ALTMOVCR8 = 0x10;
static const Shortint EAMD2_ABM = 0x20;
static const Shortint EAMD2_SSE4A = 0x40;
static const Byte EAMD2_MISALIGNSSE = 0x80;
static const Word EAMD2_3DNOWPREFETCH = 0x100;
static const Word EAMD2_OSVW = 0x200;
static const Word EAMD2_IBS = 0x400;
static const Word EAMD2_SSE5 = 0x800;
static const Word EAMD2_SKINIT = 0x1000;
static const Word EAMD2_WDT = 0x2000;
static const Word EAMD2_BIT_14 = 0x4000;
static const Word EAMD2_BIT_15 = 0x8000;
static const int EAMD2_BIT_16 = 0x10000;
static const int EAMD2_BIT_17 = 0x20000;
static const int EAMD2_BIT_18 = 0x40000;
static const int EAMD2_BIT_19 = 0x80000;
static const int EAMD2_BIT_20 = 0x100000;
static const int EAMD2_BIT_21 = 0x200000;
static const int EAMD2_BIT_22 = 0x400000;
static const int EAMD2_BIT_23 = 0x800000;
static const int EAMD2_BIT_24 = 0x1000000;
static const int EAMD2_BIT_25 = 0x2000000;
static const int EAMD2_BIT_26 = 0x4000000;
static const int EAMD2_BIT_27 = 0x8000000;
static const int EAMD2_BIT_28 = 0x10000000;
static const int EAMD2_BIT_29 = 0x20000000;
static const int EAMD2_BIT_30 = 0x40000000;
static const unsigned EAMD2_BIT_31 = 0x80000000;
static const Shortint PAMD_TEMPSENSOR = 0x1;
static const Shortint PAMD_FREQUENCYID = 0x2;
static const Shortint PAMD_VOLTAGEID = 0x4;
static const Shortint PAMD_THERMALTRIP = 0x8;
static const Shortint PAMD_THERMALMONITOR = 0x10;
static const Shortint PAMD_SOFTTHERMCONTROL = 0x20;
static const Shortint PAMD_100MHZSTEP = 0x40;
static const Byte PAMD_HWPSTATE = 0x80;
static const Word PAMD_TSC_INVARIANT = 0x100;
static const Word PAMD_BIT_9 = 0x200;
static const Word PAMD_BIT_10 = 0x400;
static const Word PAMD_BIT_11 = 0x800;
static const Word PAMD_BIT_12 = 0x1000;
static const Word PAMD_BIT_13 = 0x2000;
static const Word PAMD_BIT_14 = 0x4000;
static const Word PAMD_BIT_15 = 0x8000;
static const int PAMD_BIT_16 = 0x10000;
static const int PAMD_BIT_17 = 0x20000;
static const int PAMD_BIT_18 = 0x40000;
static const int PAMD_BIT_19 = 0x80000;
static const int PAMD_BIT_20 = 0x100000;
static const int PAMD_BIT_21 = 0x200000;
static const int PAMD_BIT_22 = 0x400000;
static const int PAMD_BIT_23 = 0x800000;
static const int PAMD_BIT_24 = 0x1000000;
static const int PAMD_BIT_25 = 0x2000000;
static const int PAMD_BIT_26 = 0x4000000;
static const int PAMD_BIT_27 = 0x8000000;
static const int PAMD_BIT_28 = 0x10000000;
static const int PAMD_BIT_29 = 0x20000000;
static const int PAMD_BIT_30 = 0x40000000;
static const unsigned PAMD_BIT_31 = 0x80000000;
static const Shortint AMD_ASSOC_RESERVED = 0x0;
static const Shortint AMD_ASSOC_DIRECT = 0x1;
static const Byte AMD_ASSOC_FULLY = 0xff;
static const Shortint AMD_L2_ASSOC_DISABLED = 0x0;
static const Shortint AMD_L2_ASSOC_DIRECT = 0x1;
static const Shortint AMD_L2_ASSOC_2WAY = 0x2;
static const Shortint AMD_L2_ASSOC_4WAY = 0x4;
static const Shortint AMD_L2_ASSOC_8WAY = 0x6;
static const Shortint AMD_L2_ASSOC_16WAY = 0x8;
static const Shortint AMD_L2_ASSOC_FULLY = 0xf;
static const Shortint VIA_FPU = 0x1;
static const Shortint VIA_VME = 0x2;
static const Shortint VIA_DE = 0x4;
static const Shortint VIA_PSE = 0x8;
static const Shortint VIA_TSC = 0x10;
static const Shortint VIA_MSR = 0x20;
static const Shortint VIA_PAE = 0x40;
static const Byte VIA_MCE = 0x80;
static const Word VIA_CX8 = 0x100;
static const Word VIA_APIC = 0x200;
static const Word VIA_BIT_10 = 0x400;
static const Word VIA_SEP = 0x800;
static const Word VIA_MTRR = 0x1000;
static const Word VIA_PTE = 0x2000;
static const Word VIA_MCA = 0x4000;
static const Word VIA_CMOVE = 0x8000;
static const int VIA_PAT = 0x10000;
static const int VIA_PSE2 = 0x20000;
static const int VIA_SNUM = 0x40000;
static const int VIA_BIT_19 = 0x80000;
static const int VIA_BIT_20 = 0x100000;
static const int VIA_BIT_21 = 0x200000;
static const int VIA_BIT_22 = 0x400000;
static const int VIA_MMX = 0x800000;
static const int VIA_FX = 0x1000000;
static const int VIA_SSE = 0x2000000;
static const int VIA_BIT_26 = 0x4000000;
static const int VIA_BIT_27 = 0x8000000;
static const int VIA_BIT_28 = 0x10000000;
static const int VIA_BIT_29 = 0x20000000;
static const int VIA_BIT_30 = 0x40000000;
static const unsigned VIA_3DNOW = 0x80000000;
static const Shortint EVIA_AIS = 0x1;
static const Shortint EVIA_AISE = 0x2;
static const Shortint EVIA_NO_RNG = 0x4;
static const Shortint EVIA_RNGE = 0x8;
static const Shortint EVIA_MSR = 0x10;
static const Shortint EVIA_FEMMS = 0x20;
static const Shortint EVIA_NO_ACE = 0x40;
static const Byte EVIA_ACEE = 0x80;
static const Word EVIA_BIT_8 = 0x100;
static const Word EVIA_BIT_9 = 0x200;
static const Word EVIA_BIT_10 = 0x400;
static const Word EVIA_BIT_11 = 0x800;
static const Word EVIA_BIT_12 = 0x1000;
static const Word EVIA_BIT_13 = 0x2000;
static const Word EVIA_BIT_14 = 0x4000;
static const Word EVIA_BIT_15 = 0x8000;
static const int EVIA_BIT_16 = 0x10000;
static const int EVIA_BIT_17 = 0x20000;
static const int EVIA_BIT_18 = 0x40000;
static const int EVIA_BIT_19 = 0x80000;
static const int EVIA_BIT_20 = 0x100000;
static const int EVIA_BIT_21 = 0x200000;
static const int EVIA_BIT_22 = 0x400000;
static const int EVIA_BIT_23 = 0x800000;
static const int EVIA_BIT_24 = 0x1000000;
static const int EVIA_BIT_25 = 0x2000000;
static const int EVIA_BIT_26 = 0x4000000;
static const int EVIA_BIT_27 = 0x8000000;
static const int EVIA_BIT_28 = 0x10000000;
static const int EVIA_BIT_29 = 0x20000000;
static const int EVIA_BIT_30 = 0x40000000;
static const unsigned EVIA_BIT_31 = 0x80000000;
static const Shortint CYRIX_FPU = 0x1;
static const Shortint CYRIX_VME = 0x2;
static const Shortint CYRIX_DE = 0x4;
static const Shortint CYRIX_PSE = 0x8;
static const Shortint CYRIX_TSC = 0x10;
static const Shortint CYRIX_MSR = 0x20;
static const Shortint CYRIX_PAE = 0x40;
static const Byte CYRIX_MCE = 0x80;
static const Word CYRIX_CX8 = 0x100;
static const Word CYRIX_APIC = 0x200;
static const Word CYRIX_BIT_10 = 0x400;
static const Word CYRIX_BIT_11 = 0x800;
static const Word CYRIX_MTRR = 0x1000;
static const Word CYRIX_PGE = 0x2000;
static const Word CYRIX_MCA = 0x4000;
static const Word CYRIX_CMOV = 0x8000;
static const int CYRIX_BIT_16 = 0x10000;
static const int CYRIX_BIT_17 = 0x20000;
static const int CYRIX_BIT_18 = 0x40000;
static const int CYRIX_BIT_19 = 0x80000;
static const int CYRIX_BIT_20 = 0x100000;
static const int CYRIX_BIT_21 = 0x200000;
static const int CYRIX_BIT_22 = 0x400000;
static const int CYRIX_MMX = 0x800000;
static const int CYRIX_BIT_24 = 0x1000000;
static const int CYRIX_BIT_25 = 0x2000000;
static const int CYRIX_BIT_26 = 0x4000000;
static const int CYRIX_BIT_27 = 0x8000000;
static const int CYRIX_BIT_28 = 0x10000000;
static const int CYRIX_BIT_29 = 0x20000000;
static const int CYRIX_BIT_30 = 0x40000000;
static const unsigned CYRIX_BIT_31 = 0x80000000;
static const Shortint ECYRIX_FPU = 0x1;
static const Shortint ECYRIX_VME = 0x2;
static const Shortint ECYRIX_DE = 0x4;
static const Shortint ECYRIX_PSE = 0x8;
static const Shortint ECYRIX_TSC = 0x10;
static const Shortint ECYRIX_MSR = 0x20;
static const Shortint ECYRIX_PAE = 0x40;
static const Byte ECYRIX_MCE = 0x80;
static const Word ECYRIX_CX8 = 0x100;
static const Word ECYRIX_APIC = 0x200;
static const Word ECYRIX_SEP = 0x400;
static const Word ECYRIX_BIT_11 = 0x800;
static const Word ECYRIX_MTRR = 0x1000;
static const Word ECYRIX_PGE = 0x2000;
static const Word ECYRIX_MCA = 0x4000;
static const Word ECYRIX_ICMOV = 0x8000;
static const int ECYRIX_FCMOV = 0x10000;
static const int ECYRIX_BIT_17 = 0x20000;
static const int ECYRIX_BIT_18 = 0x40000;
static const int ECYRIX_BIT_19 = 0x80000;
static const int ECYRIX_BIT_20 = 0x100000;
static const int ECYRIX_BIT_21 = 0x200000;
static const int ECYRIX_BIT_22 = 0x400000;
static const int ECYRIX_MMX = 0x800000;
static const int ECYRIX_EMMX = 0x1000000;
static const int ECYRIX_BIT_25 = 0x2000000;
static const int ECYRIX_BIT_26 = 0x4000000;
static const int ECYRIX_BIT_27 = 0x8000000;
static const int ECYRIX_BIT_28 = 0x10000000;
static const int ECYRIX_BIT_29 = 0x20000000;
static const int ECYRIX_BIT_30 = 0x40000000;
static const unsigned ECYRIX_BIT_31 = 0x80000000;
static const Shortint TRANSMETA_FPU = 0x1;
static const Shortint TRANSMETA_VME = 0x2;
static const Shortint TRANSMETA_DE = 0x4;
static const Shortint TRANSMETA_PSE = 0x8;
static const Shortint TRANSMETA_TSC = 0x10;
static const Shortint TRANSMETA_MSR = 0x20;
static const Shortint TRANSMETA_BIT_6 = 0x40;
static const Byte TRANSMETA_BIT_7 = 0x80;
static const Word TRANSMETA_CX8 = 0x100;
static const Word TRANSMETA_BIT_9 = 0x200;
static const Word TRANSMETA_BIT_10 = 0x400;
static const Word TRANSMETA_SEP = 0x800;
static const Word TRANSMETA_BIT_12 = 0x1000;
static const Word TRANSMETA_BIT_13 = 0x2000;
static const Word TRANSMETA_BIT_14 = 0x4000;
static const Word TRANSMETA_CMOV = 0x8000;
static const int TRANSMETA_BIT_16 = 0x10000;
static const int TRANSMETA_BIT_17 = 0x20000;
static const int TRANSMETA_PSN = 0x40000;
static const int TRANSMETA_BIT_19 = 0x80000;
static const int TRANSMETA_BIT_20 = 0x100000;
static const int TRANSMETA_BIT_21 = 0x200000;
static const int TRANSMETA_BIT_22 = 0x400000;
static const int TRANSMETA_MMX = 0x800000;
static const int TRANSMETA_BIT_24 = 0x1000000;
static const int TRANSMETA_BIT_25 = 0x2000000;
static const int TRANSMETA_BIT_26 = 0x4000000;
static const int TRANSMETA_BIT_27 = 0x8000000;
static const int TRANSMETA_BIT_28 = 0x10000000;
static const int TRANSMETA_BIT_29 = 0x20000000;
static const int TRANSMETA_BIT_30 = 0x40000000;
static const unsigned TRANSMETA_BIT_31 = 0x80000000;
static const Shortint ETRANSMETA_FPU = 0x1;
static const Shortint ETRANSMETA_VME = 0x2;
static const Shortint ETRANSMETA_DE = 0x4;
static const Shortint ETRANSMETA_PSE = 0x8;
static const Shortint ETRANSMETA_TSC = 0x10;
static const Shortint ETRANSMETA_MSR = 0x20;
static const Shortint ETRANSMETA_BIT_6 = 0x40;
static const Byte ETRANSMETA_BIT_7 = 0x80;
static const Word ETRANSMETA_CX8 = 0x100;
static const Word ETRANSMETA_BIT_9 = 0x200;
static const Word ETRANSMETA_BIT_10 = 0x400;
static const Word ETRANSMETA_BIT_11 = 0x800;
static const Word ETRANSMETA_BIT_12 = 0x1000;
static const Word ETRANSMETA_BIT_13 = 0x2000;
static const Word ETRANSMETA_BIT_14 = 0x4000;
static const Word ETRANSMETA_CMOV = 0x8000;
static const int ETRANSMETA_FCMOV = 0x10000;
static const int ETRANSMETA_BIT_17 = 0x20000;
static const int ETRANSMETA_BIT_18 = 0x40000;
static const int ETRANSMETA_BIT_19 = 0x80000;
static const int ETRANSMETA_BIT_20 = 0x100000;
static const int ETRANSMETA_BIT_21 = 0x200000;
static const int ETRANSMETA_BIT_22 = 0x400000;
static const int ETRANSMETA_MMX = 0x800000;
static const int ETRANSMETA_BIT_24 = 0x1000000;
static const int ETRANSMETA_BIT_25 = 0x2000000;
static const int ETRANSMETA_BIT_26 = 0x4000000;
static const int ETRANSMETA_BIT_27 = 0x8000000;
static const int ETRANSMETA_BIT_28 = 0x10000000;
static const int ETRANSMETA_BIT_29 = 0x20000000;
static const int ETRANSMETA_BIT_30 = 0x40000000;
static const unsigned ETRANSMETA_BIT_31 = 0x80000000;
static const Shortint STRANSMETA_RECOVERY = 0x1;
static const Shortint STRANSMETA_LONGRUN = 0x2;
static const Shortint STRANSMETA_BIT_2 = 0x4;
static const Shortint STRANSMETA_LRTI = 0x8;
static const Shortint STRANSMETA_BIT_4 = 0x10;
static const Shortint STRANSMETA_BIT_5 = 0x20;
static const Shortint STRANSMETA_BIT_6 = 0x40;
static const Byte STRANSMETA_PTTI1 = 0x80;
static const Word STRANSMETA_PTTI2 = 0x100;
static const Word STRANSMETA_BIT_9 = 0x200;
static const Word STRANSMETA_BIT_10 = 0x400;
static const Word STRANSMETA_BIT_11 = 0x800;
static const Word STRANSMETA_BIT_12 = 0x1000;
static const Word STRANSMETA_BIT_13 = 0x2000;
static const Word STRANSMETA_BIT_14 = 0x4000;
static const Word STRANSMETA_BIT_15 = 0x8000;
static const int STRANSMETA_BIT_16 = 0x10000;
static const int STRANSMETA_BIT_17 = 0x20000;
static const int STRANSMETA_BIT_18 = 0x40000;
static const int STRANSMETA_BIT_19 = 0x80000;
static const int STRANSMETA_BIT_20 = 0x100000;
static const int STRANSMETA_BIT_21 = 0x200000;
static const int STRANSMETA_BIT_22 = 0x400000;
static const int STRANSMETA_BIT_23 = 0x800000;
static const int STRANSMETA_BIT_24 = 0x1000000;
static const int STRANSMETA_BIT_25 = 0x2000000;
static const int STRANSMETA_BIT_26 = 0x4000000;
static const int STRANSMETA_BIT_27 = 0x8000000;
static const int STRANSMETA_BIT_28 = 0x10000000;
static const int STRANSMETA_BIT_29 = 0x20000000;
static const int STRANSMETA_BIT_30 = 0x40000000;
static const unsigned STRANSMETA_BIT_31 = 0x80000000;
static const Shortint MXCSR_IE = 0x1;
static const Shortint MXCSR_DE = 0x2;
static const Shortint MXCSR_ZE = 0x4;
static const Shortint MXCSR_OE = 0x8;
static const Shortint MXCSR_UE = 0x10;
static const Shortint MXCSR_PE = 0x20;
static const Shortint MXCSR_DAZ = 0x40;
static const Byte MXCSR_IM = 0x80;
static const Word MXCSR_DM = 0x100;
static const Word MXCSR_ZM = 0x200;
static const Word MXCSR_OM = 0x400;
static const Word MXCSR_UM = 0x800;
static const Word MXCSR_PM = 0x1000;
static const Word MXCSR_RC1 = 0x2000;
static const Word MXCSR_RC2 = 0x4000;
static const Word MXCSR_RC = 0x6000;
static const Word MXCSR_FZ = 0x8000;
extern PACKAGE TCacheInfo IntelCacheDescription[88];
extern PACKAGE unsigned ProcessorCount;
extern PACKAGE unsigned AllocGranularity;
extern PACKAGE unsigned PageSize;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE bool __fastcall DelEnvironmentVar(const AnsiString Name);
extern PACKAGE bool __fastcall ExpandEnvironmentVar(AnsiString &Value);
extern PACKAGE bool __fastcall GetEnvironmentVar(const AnsiString Name, /* out */ AnsiString &Value)/* overload */;
extern PACKAGE bool __fastcall GetEnvironmentVar(const AnsiString Name, /* out */ AnsiString &Value, bool Expand)/* overload */;
extern PACKAGE bool __fastcall GetEnvironmentVars(const Classes::TStrings* Vars)/* overload */;
extern PACKAGE bool __fastcall GetEnvironmentVars(const Classes::TStrings* Vars, bool Expand)/* overload */;
extern PACKAGE bool __fastcall SetEnvironmentVar(const AnsiString Name, const AnsiString Value);
extern PACKAGE char * __fastcall CreateEnvironmentBlock(const TEnvironmentOptions Options, const Classes::TStrings* AdditionalVars);
extern PACKAGE void __fastcall DestroyEnvironmentBlock(char * &Env);
extern PACKAGE void __fastcall SetGlobalEnvironmentVariable(AnsiString VariableName, AnsiString VariableContent);
extern PACKAGE AnsiString __fastcall GetCommonFilesFolder();
extern PACKAGE AnsiString __fastcall GetCurrentFolder();
extern PACKAGE AnsiString __fastcall GetProgramFilesFolder();
extern PACKAGE AnsiString __fastcall GetWindowsFolder();
extern PACKAGE AnsiString __fastcall GetWindowsSystemFolder();
extern PACKAGE AnsiString __fastcall GetWindowsTempFolder();
extern PACKAGE AnsiString __fastcall GetDesktopFolder();
extern PACKAGE AnsiString __fastcall GetProgramsFolder();
extern PACKAGE AnsiString __fastcall GetPersonalFolder();
extern PACKAGE AnsiString __fastcall GetFavoritesFolder();
extern PACKAGE AnsiString __fastcall GetStartupFolder();
extern PACKAGE AnsiString __fastcall GetRecentFolder();
extern PACKAGE AnsiString __fastcall GetSendToFolder();
extern PACKAGE AnsiString __fastcall GetStartmenuFolder();
extern PACKAGE AnsiString __fastcall GetDesktopDirectoryFolder();
extern PACKAGE AnsiString __fastcall GetCommonDocumentsFolder();
extern PACKAGE AnsiString __fastcall GetNethoodFolder();
extern PACKAGE AnsiString __fastcall GetFontsFolder();
extern PACKAGE AnsiString __fastcall GetCommonStartmenuFolder();
extern PACKAGE AnsiString __fastcall GetCommonProgramsFolder();
extern PACKAGE AnsiString __fastcall GetCommonStartupFolder();
extern PACKAGE AnsiString __fastcall GetCommonDesktopdirectoryFolder();
extern PACKAGE AnsiString __fastcall GetCommonAppdataFolder();
extern PACKAGE AnsiString __fastcall GetAppdataFolder();
extern PACKAGE AnsiString __fastcall GetLocalAppData();
extern PACKAGE AnsiString __fastcall GetPrinthoodFolder();
extern PACKAGE AnsiString __fastcall GetCommonFavoritesFolder();
extern PACKAGE AnsiString __fastcall GetTemplatesFolder();
extern PACKAGE AnsiString __fastcall GetInternetCacheFolder();
extern PACKAGE AnsiString __fastcall GetCookiesFolder();
extern PACKAGE AnsiString __fastcall GetHistoryFolder();
extern PACKAGE AnsiString __fastcall GetProfileFolder();
extern PACKAGE AnsiString __fastcall GetVolumeName(const AnsiString Drive);
extern PACKAGE AnsiString __fastcall GetVolumeSerialNumber(const AnsiString Drive);
extern PACKAGE AnsiString __fastcall GetVolumeFileSystem(const AnsiString Drive);
extern PACKAGE TFileSystemFlags __fastcall GetVolumeFileSystemFlags(const AnsiString Volume);
extern PACKAGE AnsiString __fastcall GetIPAddress(const AnsiString HostName);
extern PACKAGE void __fastcall GetIpAddresses(Classes::TStrings* Results)/* overload */;
extern PACKAGE void __fastcall GetIpAddresses(Classes::TStrings* Results, const AnsiString HostName)/* overload */;
extern PACKAGE AnsiString __fastcall GetLocalComputerName();
extern PACKAGE AnsiString __fastcall GetLocalUserName();
extern PACKAGE AnsiString __fastcall GetRegisteredCompany();
extern PACKAGE AnsiString __fastcall GetRegisteredOwner();
extern PACKAGE AnsiString __fastcall GetUserDomainName(const AnsiString CurUser);
extern PACKAGE AnsiString __fastcall GetDomainName();
extern PACKAGE AnsiString __fastcall GetBIOSName();
extern PACKAGE AnsiString __fastcall GetBIOSCopyright();
extern PACKAGE AnsiString __fastcall GetBIOSExtendedInfo();
extern PACKAGE System::TDateTime __fastcall GetBIOSDate(void);
extern PACKAGE bool __fastcall RunningProcessesList(const Classes::TStrings* List, bool FullPath = true);
extern PACKAGE bool __fastcall LoadedModulesList(const Classes::TStrings* List, unsigned ProcessID, bool HandlesOnly = false);
extern PACKAGE bool __fastcall GetTasksList(const Classes::TStrings* List);
extern PACKAGE unsigned __fastcall ModuleFromAddr(const void * Addr);
extern PACKAGE bool __fastcall IsSystemModule(const unsigned Module);
extern PACKAGE bool __fastcall IsMainAppWindow(unsigned Wnd);
extern PACKAGE bool __fastcall IsWindowResponding(unsigned Wnd, int Timeout);
extern PACKAGE HICON __fastcall GetWindowIcon(unsigned Wnd, bool LargeIcon);
extern PACKAGE AnsiString __fastcall GetWindowCaption(unsigned Wnd);
extern PACKAGE TJclTerminateAppResult __fastcall TerminateApp(unsigned ProcessID, int Timeout);
extern PACKAGE TJclTerminateAppResult __fastcall TerminateTask(unsigned Wnd, int Timeout);
extern PACKAGE AnsiString __fastcall GetProcessNameFromWnd(unsigned Wnd);
extern PACKAGE unsigned __fastcall GetPidFromProcessName(const AnsiString ProcessName);
extern PACKAGE AnsiString __fastcall GetProcessNameFromPid(unsigned PID);
extern PACKAGE unsigned __fastcall GetMainAppWndFromPid(unsigned PID);
extern PACKAGE HWND __fastcall GetWndFromPid(unsigned PID, const AnsiString WindowClassName);
extern PACKAGE AnsiString __fastcall GetShellProcessName();
extern PACKAGE unsigned __fastcall GetShellProcessHandle(void);
extern PACKAGE TWindowsVersion __fastcall GetWindowsVersion(void);
extern PACKAGE TWindowsEdition __fastcall GetWindowsEdition(void);
extern PACKAGE TNtProductType __fastcall NtProductType(void);
extern PACKAGE AnsiString __fastcall GetWindowsVersionString();
extern PACKAGE AnsiString __fastcall GetWindowsEditionString();
extern PACKAGE AnsiString __fastcall GetWindowsProductString();
extern PACKAGE AnsiString __fastcall NtProductTypeString();
extern PACKAGE int __fastcall GetWindowsServicePackVersion(void);
extern PACKAGE AnsiString __fastcall GetWindowsServicePackVersionString();
extern PACKAGE bool __fastcall GetOpenGLVersion(const unsigned Win, /* out */ AnsiString &Version, /* out */ AnsiString &Vendor);
extern PACKAGE bool __fastcall GetNativeSystemInfo(_SYSTEM_INFO &SystemInfo);
extern PACKAGE TProcessorArchitecture __fastcall GetProcessorArchitecture(void);
extern PACKAGE bool __fastcall IsWindows64(void);
extern PACKAGE AnsiString __fastcall GetOSVersionString();
extern PACKAGE int __fastcall GetMacAddresses(const AnsiString Machine, const Classes::TStrings* Addresses);
extern PACKAGE __int64 __fastcall ReadTimeStampCounter(void);
extern PACKAGE AnsiString __fastcall GetIntelCacheDescription(const Byte D);
extern PACKAGE void __fastcall GetCpuInfo(TCpuInfo &CpuInfo);
extern PACKAGE int __fastcall RoundFrequency(const int Frequency);
extern PACKAGE bool __fastcall GetCPUSpeed(TFreqInfo &CpuSpeed);
extern PACKAGE TOSEnabledFeatures __fastcall GetOSEnabledFeatures(void);
extern PACKAGE TCpuInfo __fastcall CPUID();
extern PACKAGE bool __fastcall TestFDIVInstruction(void);
extern PACKAGE void __fastcall RoundToAllocGranularity64(__int64 &Value, bool Up);
extern PACKAGE void __fastcall RoundToAllocGranularityPtr(void * &Value, bool Up);
extern PACKAGE TAPMLineStatus __fastcall GetAPMLineStatus(void);
extern PACKAGE TAPMBatteryFlag __fastcall GetAPMBatteryFlag(void);
extern PACKAGE TAPMBatteryFlags __fastcall GetAPMBatteryFlags(void);
extern PACKAGE int __fastcall GetAPMBatteryLifePercent(void);
extern PACKAGE unsigned __fastcall GetAPMBatteryLifeTime(void);
extern PACKAGE unsigned __fastcall GetAPMBatteryFullLifeTime(void);
extern PACKAGE unsigned __fastcall GetMaxAppAddress(void);
extern PACKAGE unsigned __fastcall GetMinAppAddress(void);
extern PACKAGE Byte __fastcall GetMemoryLoad(void);
extern PACKAGE unsigned __fastcall GetSwapFileSize(void);
extern PACKAGE Byte __fastcall GetSwapFileUsage(void);
extern PACKAGE unsigned __fastcall GetTotalPhysicalMemory(void);
extern PACKAGE unsigned __fastcall GetFreePhysicalMemory(void);
extern PACKAGE unsigned __fastcall GetTotalPageFileMemory(void);
extern PACKAGE unsigned __fastcall GetFreePageFileMemory(void);
extern PACKAGE unsigned __fastcall GetTotalVirtualMemory(void);
extern PACKAGE unsigned __fastcall GetFreeVirtualMemory(void);
extern PACKAGE bool __fastcall GetKeyState(const unsigned VirtualKey);
extern PACKAGE bool __fastcall GetNumLockKeyState(void);
extern PACKAGE bool __fastcall GetScrollLockKeyState(void);
extern PACKAGE bool __fastcall GetCapsLockKeyState(void);
extern PACKAGE bool __fastcall IsSystemResourcesMeterPresent(void);
extern PACKAGE int __fastcall GetFreeSystemResources(const TFreeSysResKind ResourceType)/* overload */;
extern PACKAGE TFreeSystemResources __fastcall GetFreeSystemResources()/* overload */;
extern PACKAGE unsigned __fastcall GetBPP(void);
extern PACKAGE bool __fastcall ProgIDExists(const AnsiString ProgID);
extern PACKAGE bool __fastcall IsWordInstalled(void);
extern PACKAGE bool __fastcall IsExcelInstalled(void);
extern PACKAGE bool __fastcall IsAccessInstalled(void);
extern PACKAGE bool __fastcall IsPowerPointInstalled(void);
extern PACKAGE bool __fastcall IsFrontPageInstalled(void);
extern PACKAGE bool __fastcall IsOutlookInstalled(void);
extern PACKAGE bool __fastcall IsInternetExplorerInstalled(void);
extern PACKAGE bool __fastcall IsMSProjectInstalled(void);
extern PACKAGE bool __fastcall IsOpenOfficeInstalled(void);

}	/* namespace Jclsysinfo */
using namespace Jclsysinfo;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclsysinfo
