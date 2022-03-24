// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclsvcctrl.pas' rev: 10.00

#ifndef JclsvcctrlHPP
#define JclsvcctrlHPP

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
#include <Contnrs.hpp>	// Pascal unit
#include <Winsvc.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclsysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclsvcctrl
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TJclServiceType { stKernelDriver, stFileSystemDriver, stAdapter, stRecognizerDriver, stWin32OwnProcess, stWin32ShareProcess, stInteractiveProcess };
#pragma option pop

typedef Set<TJclServiceType, stKernelDriver, stInteractiveProcess>  TJclServiceTypes;

#pragma option push -b-
enum TJclServiceState { ssUnknown, ssStopped, ssStartPending, ssStopPending, ssRunning, ssContinuePending, ssPausePending, ssPaused };
#pragma option pop

typedef Set<TJclServiceState, ssUnknown, ssPaused>  TJclServiceStates;

#pragma option push -b-
enum TJclServiceStartType { sstBoot, sstSystem, sstAuto, sstDemand, sstDisabled };
#pragma option pop

#pragma option push -b-
enum TJclServiceErrorControlType { ectIgnore, ectNormal, ectSevere, ectCritical };
#pragma option pop

#pragma option push -b-
enum TJclServiceControlAccepted { caStop, caPauseContinue, caShutdown };
#pragma option pop

typedef Set<TJclServiceControlAccepted, caStop, caShutdown>  TJclServiceControlAccepteds;

#pragma option push -b-
enum TJclServiceSortOrderType { sotServiceName, sotDisplayName, sotDescription, sotFileName, sotServiceState, sotStartType, sotErrorControlType, sotLoadOrderGroup, sotWin32ExitCode };
#pragma option pop

typedef SERVICE_DESCRIPTIONA  TServiceDescriptionA;

typedef SERVICE_DESCRIPTIONA *PServiceDescriptionA;

typedef BOOL __stdcall (*TQueryServiceConfig2A)(unsigned hService, unsigned dwInfoLevel, System::PByte lpBuffer, unsigned cbBufSize, unsigned &pcbBytesNeeded);

class DELPHICLASS TJclNtService;
class DELPHICLASS TJclSCManager;
class DELPHICLASS TJclServiceGroup;
class PASCALIMPLEMENTATION TJclSCManager : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FMachineName;
	AnsiString FDatabaseName;
	unsigned FDesiredAccess;
	unsigned FHandle;
	void *FLock;
	Contnrs::TObjectList* FServices;
	Contnrs::TObjectList* FGroups;
	unsigned FAdvApi32Handle;
	TQueryServiceConfig2A FQueryServiceConfig2A;
	bool __fastcall GetActive(void);
	void __fastcall SetActive(const bool Value);
	TJclNtService* __fastcall GetService(const int Idx);
	int __fastcall GetServiceCount(void);
	TJclServiceGroup* __fastcall GetGroup(const int Idx);
	int __fastcall GetGroupCount(void);
	void __fastcall SetOrderAsc(const bool Value);
	void __fastcall SetOrderType(const TJclServiceSortOrderType Value);
	unsigned __fastcall GetAdvApi32Handle(void);
	TQueryServiceConfig2A __fastcall GetQueryServiceConfig2A(void);
	
protected:
	TJclServiceSortOrderType FOrderType;
	bool FOrderAsc;
	void __fastcall Open(void);
	void __fastcall Close(void);
	int __fastcall AddService(const TJclNtService* AService);
	int __fastcall AddGroup(const TJclServiceGroup* AGroup);
	Winsvc::PQueryServiceLockStatusA __fastcall GetServiceLockStatus(void);
	__property unsigned AdvApi32Handle = {read=GetAdvApi32Handle, nodefault};
	__property TQueryServiceConfig2A QueryServiceConfig2A = {read=GetQueryServiceConfig2A};
	
public:
	__fastcall TJclSCManager(const AnsiString AMachineName, const unsigned ADesiredAccess, const AnsiString ADatabaseName);
	__fastcall virtual ~TJclSCManager(void);
	void __fastcall Clear(void);
	void __fastcall Refresh(const bool RefreshAll = false);
	TJclNtService* __fastcall Install(const AnsiString ServiceName, const AnsiString DisplayName, const AnsiString ImageName, const AnsiString Description = "", TJclServiceTypes ServiceTypes = (Set<TJclServiceType, stKernelDriver, stInteractiveProcess> () << TJclServiceType(4) ), TJclServiceStartType StartType = (TJclServiceStartType)(0x3), TJclServiceErrorControlType ErrorControlType = (TJclServiceErrorControlType)(0x1), unsigned DesiredAccess = (unsigned)(0xf01ff), const TJclServiceGroup* LoadOrderGroup = (TJclServiceGroup*)(0x0), const char * Dependencies = (void *)(0x0), const char * Account = (void *)(0x0), const char * Password = (void *)(0x0));
	void __fastcall Sort(const TJclServiceSortOrderType AOrderType, const bool AOrderAsc = true);
	bool __fastcall FindService(const AnsiString SvcName, /* out */ TJclNtService* &NtSvc);
	bool __fastcall FindGroup(const AnsiString GrpName, /* out */ TJclServiceGroup* &SvcGrp, const bool AutoAdd = true);
	void __fastcall Lock(void);
	void __fastcall Unlock(void);
	bool __fastcall IsLocked(void);
	AnsiString __fastcall LockOwner();
	unsigned __fastcall LockDuration(void);
	/*         class method */ static unsigned __fastcall ServiceType(TMetaClass* vmt, const TJclServiceTypes SvcType)/* overload */;
	/*         class method */ static TJclServiceTypes __fastcall ServiceType(TMetaClass* vmt, const unsigned SvcType)/* overload */;
	/*         class method */ static unsigned __fastcall ControlAccepted(TMetaClass* vmt, const TJclServiceControlAccepteds CtrlAccepted)/* overload */;
	/*         class method */ static TJclServiceControlAccepteds __fastcall ControlAccepted(TMetaClass* vmt, const unsigned CtrlAccepted)/* overload */;
	__property AnsiString MachineName = {read=FMachineName};
	__property AnsiString DatabaseName = {read=FDatabaseName};
	__property unsigned DesiredAccess = {read=FDesiredAccess, nodefault};
	__property bool Active = {read=GetActive, write=SetActive, nodefault};
	__property unsigned Handle = {read=FHandle, nodefault};
	__property TJclNtService* Services[int Idx] = {read=GetService};
	__property int ServiceCount = {read=GetServiceCount, nodefault};
	__property TJclServiceGroup* Groups[int Idx] = {read=GetGroup};
	__property int GroupCount = {read=GetGroupCount, nodefault};
	__property TJclServiceSortOrderType OrderType = {read=FOrderType, write=SetOrderType, nodefault};
	__property bool OrderAsc = {read=FOrderAsc, write=SetOrderAsc, nodefault};
};


class PASCALIMPLEMENTATION TJclNtService : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TJclSCManager* FSCManager;
	unsigned FHandle;
	unsigned FDesiredAccess;
	AnsiString FServiceName;
	AnsiString FDisplayName;
	AnsiString FDescription;
	AnsiString FFileName;
	AnsiString FServiceStartName;
	Classes::TList* FDependentServices;
	Classes::TList* FDependentGroups;
	Classes::TList* FDependentByServices;
	TJclServiceTypes FServiceTypes;
	TJclServiceState FServiceState;
	TJclServiceStartType FStartType;
	TJclServiceErrorControlType FErrorControlType;
	unsigned FWin32ExitCode;
	TJclServiceGroup* FGroup;
	TJclServiceControlAccepteds FControlsAccepted;
	bool FCommitNeeded;
	bool __fastcall GetActive(void);
	void __fastcall SetActive(const bool Value);
	TJclNtService* __fastcall GetDependentService(const int Idx);
	int __fastcall GetDependentServiceCount(void);
	TJclServiceGroup* __fastcall GetDependentGroup(const int Idx);
	int __fastcall GetDependentGroupCount(void);
	TJclNtService* __fastcall GetDependentByService(const int Idx);
	int __fastcall GetDependentByServiceCount(void);
	
protected:
	void __fastcall Open(const unsigned ADesiredAccess = (unsigned)(0xf01ff));
	void __fastcall Close(void);
	_SERVICE_STATUS __fastcall GetServiceStatus();
	void __fastcall UpdateDescription(void);
	void __fastcall UpdateDependents(void);
	void __fastcall UpdateStatus(const _SERVICE_STATUS &SvcStatus);
	void __fastcall UpdateConfig(const _QUERY_SERVICE_CONFIGA &SvcConfig);
	void __fastcall CommitConfig(_QUERY_SERVICE_CONFIGA &SvcConfig);
	void __fastcall SetStartType(TJclServiceStartType AStartType);
	
public:
	__fastcall TJclNtService(const TJclSCManager* ASCManager, const _ENUM_SERVICE_STATUSA &SvcStatus);
	__fastcall virtual ~TJclNtService(void);
	void __fastcall Refresh(void);
	void __fastcall Commit(void);
	void __fastcall Delete(void);
	_SERVICE_STATUS __fastcall Controls(const unsigned ControlType, const unsigned ADesiredAccess = (unsigned)(0xf01ff));
	void __fastcall Start(AnsiString const * Args, const int Args_Size, const bool Sync = true)/* overload */;
	void __fastcall Start(const bool Sync = true)/* overload */;
	void __fastcall Stop(const bool Sync = true);
	void __fastcall Pause(const bool Sync = true);
	void __fastcall Continue(const bool Sync = true);
	bool __fastcall WaitFor(const TJclServiceState State, const unsigned TimeOut = (unsigned)(0xffffffff));
	__property TJclSCManager* SCManager = {read=FSCManager};
	__property bool Active = {read=GetActive, write=SetActive, nodefault};
	__property unsigned Handle = {read=FHandle, nodefault};
	__property AnsiString ServiceName = {read=FServiceName};
	__property AnsiString DisplayName = {read=FDisplayName};
	__property unsigned DesiredAccess = {read=FDesiredAccess, nodefault};
	__property AnsiString Description = {read=FDescription};
	__property AnsiString FileName = {read=FFileName};
	__property AnsiString ServiceStartName = {read=FServiceStartName};
	__property TJclNtService* DependentServices[int Idx] = {read=GetDependentService};
	__property int DependentServiceCount = {read=GetDependentServiceCount, nodefault};
	__property TJclServiceGroup* DependentGroups[int Idx] = {read=GetDependentGroup};
	__property int DependentGroupCount = {read=GetDependentGroupCount, nodefault};
	__property TJclNtService* DependentByServices[int Idx] = {read=GetDependentByService};
	__property int DependentByServiceCount = {read=GetDependentByServiceCount, nodefault};
	__property TJclServiceTypes ServiceTypes = {read=FServiceTypes, nodefault};
	__property TJclServiceState ServiceState = {read=FServiceState, nodefault};
	__property TJclServiceStartType StartType = {read=FStartType, write=SetStartType, nodefault};
	__property TJclServiceErrorControlType ErrorControlType = {read=FErrorControlType, nodefault};
	__property unsigned Win32ExitCode = {read=FWin32ExitCode, nodefault};
	__property TJclServiceGroup* Group = {read=FGroup};
	__property TJclServiceControlAccepteds ControlsAccepted = {read=FControlsAccepted, nodefault};
};


class PASCALIMPLEMENTATION TJclServiceGroup : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TJclSCManager* FSCManager;
	AnsiString FName;
	int FOrder;
	Classes::TList* FServices;
	TJclNtService* __fastcall GetService(const int Idx);
	int __fastcall GetServiceCount(void);
	
protected:
	int __fastcall Add(const TJclNtService* AService);
	int __fastcall Remove(const TJclNtService* AService);
	
public:
	__fastcall TJclServiceGroup(const TJclSCManager* ASCManager, const AnsiString AName, const int AOrder);
	__fastcall virtual ~TJclServiceGroup(void);
	__property TJclSCManager* SCManager = {read=FSCManager};
	__property AnsiString Name = {read=FName};
	__property int Order = {read=FOrder, nodefault};
	__property TJclNtService* Services[int Idx] = {read=GetService};
	__property int ServiceCount = {read=GetServiceCount, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
#define stDriverService (Set<TJclServiceType, stKernelDriver, stInteractiveProcess> () << TJclServiceType(0) << TJclServiceType(1) << TJclServiceType(3) )
#define stWin32Service (Set<TJclServiceType, stKernelDriver, stInteractiveProcess> () << TJclServiceType(4) << TJclServiceType(5) )
#define stAllTypeService (Set<TJclServiceType, stKernelDriver, stInteractiveProcess> () << TJclServiceType(0) << TJclServiceType(1) << TJclServiceType(2) << TJclServiceType(3) << TJclServiceType(4) << TJclServiceType(5) << TJclServiceType(6) )
#define ssPendingStates (Set<TJclServiceState, ssUnknown, ssPaused> () << TJclServiceState(2) << TJclServiceState(3) << TJclServiceState(5) << TJclServiceState(6) )
static const int EveryoneSCMDesiredAccess = 0x20015;
static const int LocalSystemSCMDesiredAccess = 0x20035;
static const int AdministratorsSCMDesiredAccess = 0xf003f;
static const int DefaultSCMDesiredAccess = 0x20015;
static const int DefaultSvcDesiredAccess = 0xf01ff;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE TJclServiceState __fastcall GetServiceStatusByName(const AnsiString AServer, const AnsiString AServiceName);
extern PACKAGE bool __fastcall StartServiceByName(const AnsiString AServer, const AnsiString AServiceName);
extern PACKAGE bool __fastcall StopServiceByName(const AnsiString AServer, const AnsiString AServiceName);
extern PACKAGE unsigned __fastcall GetServiceStatus(unsigned ServiceHandle);
extern PACKAGE unsigned __fastcall GetServiceStatusWaitingIfPending(unsigned ServiceHandle);

}	/* namespace Jclsvcctrl */
using namespace Jclsvcctrl;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclsvcctrl
