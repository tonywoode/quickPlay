// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Mscoree_tlb.pas' rev: 10.00

#ifndef Mscoree_tlbHPP
#define Mscoree_tlbHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Activex.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <winnt.h>

namespace Mscoree_tlb
{
//-- type declarations -------------------------------------------------------
__interface IMarshal;
typedef System::DelphiInterface<IMarshal> _di_IMarshal;
typedef IMarshal ComCallUnmarshal;
;

__interface ICorRuntimeHost;
typedef System::DelphiInterface<ICorRuntimeHost> _di_ICorRuntimeHost;
typedef ICorRuntimeHost CorRuntimeHost;
;

typedef GUID *PUserType1;

__interface ISequentialStream;
typedef System::DelphiInterface<ISequentialStream> _di_ISequentialStream;
typedef _di_ISequentialStream *PPUserType1;

typedef Byte *PByte1;

typedef unsigned *PUINT1;

#pragma pack(push,1)
struct _LARGE_INTEGER
{
	
public:
	__int64 QuadPart;
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct _ULARGE_INTEGER
{
	
public:
	__int64 QuadPart;
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct _COR_GC_STATS
{
	
public:
	unsigned Flags;
	unsigned ExplicitGCCount;
	unsigned GenCollectionsTaken[3];
	unsigned CommittedKBytes;
	unsigned ReservedKBytes;
	unsigned Gen0HeapSizeKBytes;
	unsigned Gen1HeapSizeKBytes;
	unsigned Gen2HeapSizeKBytes;
	unsigned LargeObjectHeapSizeKBytes;
	unsigned KBytesPromotedFromGen0;
	unsigned KBytesPromotedFromGen1;
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct _COR_GC_THREAD_STATS
{
	
public:
	__int64 PerThreadAllocation;
	unsigned Flags;
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct tag_VerError
{
	
public:
	unsigned Flags;
	unsigned opcode;
	unsigned uOffset;
	unsigned Token;
	unsigned item1_flags;
	int *item1_data;
	unsigned item2_flags;
	int *item2_data;
} ;
#pragma pack(pop)

__interface IApartmentCallback;
typedef System::DelphiInterface<IApartmentCallback> _di_IApartmentCallback;
__interface  INTERFACE_UUID("{178E5337-1528-4591-B1C9-1C6E484686D8}") IApartmentCallback  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall DoCallback(unsigned pFunc, unsigned pData) = 0 ;
};

__interface IManagedObject;
typedef System::DelphiInterface<IManagedObject> _di_IManagedObject;
__interface  INTERFACE_UUID("{C3FCC19E-A970-11D2-8B5A-00A0C9B7C9C4}") IManagedObject  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall GetSerializedBuffer(/* out */ WideString &pBSTR) = 0 ;
	virtual HRESULT __stdcall GetObjectIdentity(/* out */ WideString &pBSTRGUID, /* out */ int &AppDomainID, /* out */ int &pCCW) = 0 ;
};

__interface ICatalogServices;
typedef System::DelphiInterface<ICatalogServices> _di_ICatalogServices;
__interface  INTERFACE_UUID("{04C6BE1E-1DB1-4058-AB7A-700CCCFBF254}") ICatalogServices  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall Autodone(void) = 0 ;
	virtual HRESULT __stdcall NotAutodone(void) = 0 ;
};

__interface  INTERFACE_UUID("{00000003-0000-0000-C000-000000000046}") IMarshal  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall GetUnmarshalClass(GUID &riid, void * &pv, unsigned dwDestContext, void * &pvDestContext, unsigned mshlflags, /* out */ GUID &pCid) = 0 ;
	virtual HRESULT __stdcall GetMarshalSizeMax(GUID &riid, void * &pv, unsigned dwDestContext, void * &pvDestContext, unsigned mshlflags, /* out */ unsigned &pSize) = 0 ;
	virtual HRESULT __stdcall MarshalInterface(_di_ISequentialStream &pstm, GUID &riid, void * &pv, unsigned dwDestContext, void * &pvDestContext, unsigned mshlflags) = 0 ;
	virtual HRESULT __stdcall UnmarshalInterface(const _di_ISequentialStream pstm, GUID &riid, /* out */ void * &ppv) = 0 ;
	virtual HRESULT __stdcall ReleaseMarshalData(const _di_ISequentialStream pstm) = 0 ;
	virtual HRESULT __stdcall DisconnectObject(unsigned dwReserved) = 0 ;
};

__interface  INTERFACE_UUID("{0C733A30-2A1C-11CE-ADE5-00AA0044773D}") ISequentialStream  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall Read(/* out */ void * &pv, unsigned cb, /* out */ unsigned &pcbRead) = 0 ;
	virtual HRESULT __stdcall RemoteRead(/* out */ Byte &pv, unsigned cb, /* out */ unsigned &pcbRead) = 0 ;
	virtual HRESULT __stdcall Write(void * &pv, unsigned cb, /* out */ unsigned &pcbWritten) = 0 ;
	virtual HRESULT __stdcall RemoteWrite(Byte &pv, unsigned cb, /* out */ unsigned &pcbWritten) = 0 ;
};

__interface ICorConfiguration;
typedef System::DelphiInterface<ICorConfiguration> _di_ICorConfiguration;
__interface  INTERFACE_UUID("{CB2F6722-AB3A-11D2-9C40-00C04FA30A3E}") ICorRuntimeHost  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall CreateLogicalThreadState(void) = 0 ;
	virtual HRESULT __stdcall DeleteLogicalThreadState(void) = 0 ;
	virtual HRESULT __stdcall SwitchInLogicalThreadState(unsigned &pFiberCookie) = 0 ;
	virtual HRESULT __stdcall SwitchOutLogicalThreadState(/* out */ PUINT1 &pFiberCookie) = 0 ;
	virtual HRESULT __stdcall LocksHeldByLogicalThread(/* out */ unsigned &pCount) = 0 ;
	virtual HRESULT __stdcall MapFile(void * &hFile, /* out */ void * &hMapAddress) = 0 ;
	virtual HRESULT __stdcall GetConfiguration(/* out */ _di_ICorConfiguration &pConfiguration) = 0 ;
	virtual HRESULT __stdcall Start(void) = 0 ;
	virtual HRESULT __stdcall Stop(void) = 0 ;
	virtual HRESULT __stdcall CreateDomain(WideChar * pwzFriendlyName, const System::_di_IInterface pIdentityArray, /* out */ System::_di_IInterface &pAppDomain) = 0 ;
	virtual HRESULT __stdcall GetDefaultDomain(/* out */ System::_di_IInterface &pAppDomain) = 0 ;
	virtual HRESULT __stdcall EnumDomains(/* out */ void * &hEnum) = 0 ;
	virtual HRESULT __stdcall NextDomain(void * hEnum, /* out */ System::_di_IInterface &pAppDomain) = 0 ;
	virtual HRESULT __stdcall CloseEnum(void * hEnum) = 0 ;
	virtual HRESULT __stdcall CreateDomainEx(WideChar * pwzFriendlyName, const System::_di_IInterface pSetup, const System::_di_IInterface pEvidence, /* out */ System::_di_IInterface &pAppDomain) = 0 ;
	virtual HRESULT __stdcall CreateDomainSetup(/* out */ System::_di_IInterface &pAppDomainSetup) = 0 ;
	virtual HRESULT __stdcall CreateEvidence(/* out */ System::_di_IInterface &pEvidence) = 0 ;
	virtual HRESULT __stdcall UnloadDomain(const System::_di_IInterface pAppDomain) = 0 ;
	virtual HRESULT __stdcall CurrentDomain(/* out */ System::_di_IInterface &pAppDomain) = 0 ;
};

__interface IGCHost;
typedef System::DelphiInterface<IGCHost> _di_IGCHost;
__interface  INTERFACE_UUID("{FAC34F6E-0DCD-47B5-8021-531BC5ECCA63}") IGCHost  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall SetGCStartupLimits(unsigned SegmentSize, unsigned MaxGen0Size) = 0 ;
	virtual HRESULT __stdcall Collect(int Generation) = 0 ;
	virtual HRESULT __stdcall GetStats(_COR_GC_STATS &pStats) = 0 ;
	virtual HRESULT __stdcall GetThreadStats(unsigned &pFiberCookie, _COR_GC_THREAD_STATS &pStats) = 0 ;
	virtual HRESULT __stdcall SetVirtualMemLimit(unsigned sztMaxVirtualMemMB) = 0 ;
};

__interface IGCThreadControl;
typedef System::DelphiInterface<IGCThreadControl> _di_IGCThreadControl;
__interface IGCHostControl;
typedef System::DelphiInterface<IGCHostControl> _di_IGCHostControl;
__interface IDebuggerThreadControl;
typedef System::DelphiInterface<IDebuggerThreadControl> _di_IDebuggerThreadControl;
__interface  INTERFACE_UUID("{5C2B07A5-1E98-11D3-872F-00C04F79ED0D}") ICorConfiguration  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall SetGCThreadControl(const _di_IGCThreadControl pGCThreadControl) = 0 ;
	virtual HRESULT __stdcall SetGCHostControl(const _di_IGCHostControl pGCHostControl) = 0 ;
	virtual HRESULT __stdcall SetDebuggerThreadControl(const _di_IDebuggerThreadControl pDebuggerThreadControl) = 0 ;
	virtual HRESULT __stdcall AddDebuggerSpecialThread(unsigned dwSpecialThreadId) = 0 ;
};

__interface  INTERFACE_UUID("{F31D1788-C397-4725-87A5-6AF3472C2791}") IGCThreadControl  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall ThreadIsBlockingForSuspension(void) = 0 ;
	virtual HRESULT __stdcall SuspensionStarting(void) = 0 ;
	virtual HRESULT __stdcall SuspensionEnding(unsigned Generation) = 0 ;
};

__interface  INTERFACE_UUID("{5513D564-8374-4CB9-AED9-0083F4160A1D}") IGCHostControl  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall RequestVirtualMemLimit(unsigned sztMaxVirtualMemMB, unsigned &psztNewMaxVirtualMemMB) = 0 ;
};

__interface  INTERFACE_UUID("{23D86786-0BB5-4774-8FB5-E3522ADD6246}") IDebuggerThreadControl  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall ThreadIsBlockingForDebugger(void) = 0 ;
	virtual HRESULT __stdcall ReleaseAllRuntimeThreads(void) = 0 ;
	virtual HRESULT __stdcall StartBlockingForDebugger(unsigned dwUnused) = 0 ;
};

__interface IValidator;
typedef System::DelphiInterface<IValidator> _di_IValidator;
__interface IVEHandler;
typedef System::DelphiInterface<IVEHandler> _di_IVEHandler;
__interface  INTERFACE_UUID("{63DF8730-DC81-4062-84A2-1FF943F59FAC}") IValidator  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall Validate(const _di_IVEHandler veh, const System::_di_IInterface pAppDomain, unsigned ulFlags, unsigned ulMaxError, unsigned Token, WideChar * fileName, Byte &pe, unsigned ulSize) = 0 ;
	virtual HRESULT __stdcall FormatEventInfo(HRESULT hVECode, const tag_VerError Context, WideChar * msg, unsigned ulMaxLength, Activex::PSafeArray psa) = 0 ;
};

__interface IDebuggerInfo;
typedef System::DelphiInterface<IDebuggerInfo> _di_IDebuggerInfo;
__interface  INTERFACE_UUID("{BF24142D-A47D-4D24-A66D-8C2141944E44}") IDebuggerInfo  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall IsDebuggerAttached(/* out */ int &pbAttached) = 0 ;
};

__interface  INTERFACE_UUID("{856CA1B2-7DAB-11D3-ACEC-00C04F86C309}") IVEHandler  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall VEHandler(HRESULT VECode, const tag_VerError Context, Activex::PSafeArray psa) = 0 ;
	virtual HRESULT __stdcall SetReporterFtn(__int64 lFnPtr) = 0 ;
};

class DELPHICLASS CoComCallUnmarshal;
class PASCALIMPLEMENTATION CoComCallUnmarshal : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IMarshal __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IMarshal __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoComCallUnmarshal(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoComCallUnmarshal(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoCorRuntimeHost;
class PASCALIMPLEMENTATION CoCorRuntimeHost : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_ICorRuntimeHost __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_ICorRuntimeHost __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoCorRuntimeHost(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoCorRuntimeHost(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint mscoreeMajorVersion = 0x1;
static const Shortint mscoreeMinorVersion = 0x1;
extern PACKAGE GUID LIBID_mscoree;
extern PACKAGE GUID IID_IApartmentCallback;
extern PACKAGE GUID IID_IManagedObject;
extern PACKAGE GUID IID_ICatalogServices;
extern PACKAGE GUID IID_IMarshal;
extern PACKAGE GUID CLASS_ComCallUnmarshal;
extern PACKAGE GUID IID_ISequentialStream;
extern PACKAGE GUID IID_IStream;
extern PACKAGE GUID IID_ICorRuntimeHost;
extern PACKAGE GUID IID_IGCHost;
extern PACKAGE GUID IID_ICorConfiguration;
extern PACKAGE GUID IID_IGCThreadControl;
extern PACKAGE GUID IID_IGCHostControl;
extern PACKAGE GUID IID_IDebuggerThreadControl;
extern PACKAGE GUID IID_IValidator;
extern PACKAGE GUID IID_IDebuggerInfo;
extern PACKAGE GUID IID_IVEHandler;
extern PACKAGE GUID CLASS_CorRuntimeHost;

}	/* namespace Mscoree_tlb */
using namespace Mscoree_tlb;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Mscoree_tlb
