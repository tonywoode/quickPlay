// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcllanman.pas' rev: 10.00

#ifndef JcllanmanHPP
#define JcllanmanHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jcllanman
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TNetUserFlag { ufAccountDisable, ufHomedirRequired, ufLockout, ufPasswordNotRequired, ufPasswordCantChange, ufDontExpirePassword, ufMNSLogonAccount };
#pragma option pop

typedef Set<TNetUserFlag, ufAccountDisable, ufMNSLogonAccount>  TNetUserFlags;

#pragma option push -b-
enum TNetUserInfoFlag { uifScript, uifTempDuplicateAccount, uifNormalAccount, uifInterdomainTrustAccount, uifWorkstationTrustAccount, uifServerTrustAccount };
#pragma option pop

typedef Set<TNetUserInfoFlag, uifScript, uifServerTrustAccount>  TNetUserInfoFlags;

#pragma option push -b-
enum TNetUserPriv { upUnknown, upGuest, upUser, upAdmin };
#pragma option pop

#pragma option push -b-
enum TNetUserAuthFlag { afOpPrint, afOpComm, afOpServer, afOpAccounts };
#pragma option pop

typedef Set<TNetUserAuthFlag, afOpPrint, afOpAccounts>  TNetUserAuthFlags;

#pragma option push -b-
enum TNetWellKnownRID { wkrAdmins, wkrUsers, wkrGuests, wkrPowerUsers, wkrBackupOPs, wkrReplicator, wkrEveryone };
#pragma option pop

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE bool __fastcall CreateAccount(const AnsiString Server, const AnsiString Username, const AnsiString Fullname, const AnsiString Password, const AnsiString Description, const AnsiString Homedir, const AnsiString Script, const bool PasswordNeverExpires = true);
extern PACKAGE bool __fastcall CreateLocalAccount(const AnsiString Username, const AnsiString Fullname, const AnsiString Password, const AnsiString Description, const AnsiString Homedir, const AnsiString Script, const bool PasswordNeverExpires = true);
extern PACKAGE bool __fastcall DeleteAccount(const AnsiString Servername, const AnsiString Username);
extern PACKAGE bool __fastcall DeleteLocalAccount(AnsiString Username);
extern PACKAGE bool __fastcall CreateGlobalGroup(const AnsiString Server, const AnsiString Groupname, const AnsiString Description);
extern PACKAGE bool __fastcall CreateLocalGroup(const AnsiString Server, const AnsiString Groupname, const AnsiString Description);
extern PACKAGE bool __fastcall DeleteLocalGroup(const AnsiString Server, const AnsiString Groupname);
extern PACKAGE bool __fastcall GetLocalGroups(const AnsiString Server, const Classes::TStrings* Groups);
extern PACKAGE bool __fastcall GetGlobalGroups(const AnsiString Server, const Classes::TStrings* Groups);
extern PACKAGE bool __fastcall LocalGroupExists(const AnsiString Group);
extern PACKAGE bool __fastcall GlobalGroupExists(const AnsiString Server, const AnsiString Group);
extern PACKAGE bool __fastcall AddAccountToLocalGroup(const AnsiString Accountname, const AnsiString Groupname);
extern PACKAGE AnsiString __fastcall LookupGroupName(const AnsiString Server, const TNetWellKnownRID RID);
extern PACKAGE void __fastcall ParseAccountName(const AnsiString QualifiedName, /* out */ AnsiString &Domain, /* out */ AnsiString &UserName);
extern PACKAGE bool __fastcall IsLocalAccount(const AnsiString AccountName);

}	/* namespace Jcllanman */
using namespace Jcllanman;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcllanman
