// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclmapi.pas' rev: 10.00

#ifndef JclmapiHPP
#define JclmapiHPP

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
#include <Contnrs.hpp>	// Pascal unit
#include <Mapi.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclansistrings.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclmapi
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EJclMapiError;
class PASCALIMPLEMENTATION EJclMapiError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
private:
	unsigned FErrorCode;
	
public:
	__property unsigned ErrorCode = {read=FErrorCode, nodefault};
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclMapiError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclMapiError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclMapiError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclMapiError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclMapiError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclMapiError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclMapiError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclMapiError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclMapiError(void) { }
	#pragma option pop
	
};


struct TJclMapiClient
{
	
public:
	AnsiString ClientName;
	AnsiString ClientPath;
	AnsiString RegKeyName;
	bool Valid;
} ;

#pragma option push -b-
enum TJclMapiClientConnect { ctAutomatic, ctMapi, ctDirect };
#pragma option pop

typedef DynamicArray<TJclMapiClient >  JclMapi__3;

typedef DynamicArray<AnsiString >  JclMapi__4;

class DELPHICLASS TJclSimpleMapi;
class PASCALIMPLEMENTATION TJclSimpleMapi : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TJclMapiClient operator[](int Index) { return Clients[Index]; }
	
private:
	bool FAnyClientInstalled;
	Classes::TNotifyEvent FBeforeUnloadClient;
	DynamicArray<TJclMapiClient >  FClients;
	TJclMapiClientConnect FClientConnectKind;
	unsigned FClientLibHandle;
	int FDefaultClientIndex;
	AnsiString FDefaultProfileName;
	void * *FFunctions[12];
	bool FMapiInstalled;
	AnsiString FMapiVersion;
	DynamicArray<AnsiString >  FProfiles;
	int FSelectedClientIndex;
	bool FSimpleMapiInstalled;
	Mapi::TFNMapiAddress FMapiAddress;
	Mapi::TFNMapiDeleteMail FMapiDeleteMail;
	Mapi::TFNMapiDetails FMapiDetails;
	Mapi::TFNMapiFindNext FMapiFindNext;
	Mapi::TFNMapiFreeBuffer FMapiFreeBuffer;
	Mapi::TFNMapiLogOff FMapiLogOff;
	Mapi::TFNMapiLogOn FMapiLogOn;
	Mapi::TFNMapiReadMail FMapiReadMail;
	Mapi::TFNMapiResolveName FMapiResolveName;
	Mapi::TFNMapiSaveMail FMapiSaveMail;
	Mapi::TFNMapiSendDocuments FMapiSendDocuments;
	Mapi::TFNMapiSendMail FMapiSendMail;
	int __fastcall GetClientCount(void);
	TJclMapiClient __fastcall GetClients(int Index);
	AnsiString __fastcall GetCurrentClientName();
	int __fastcall GetProfileCount(void);
	AnsiString __fastcall GetProfiles(int Index);
	void __fastcall SetSelectedClientIndex(const int Value);
	void __fastcall SetClientConnectKind(const TJclMapiClientConnect Value);
	bool __fastcall UseMapi(void);
	
protected:
	DYNAMIC void __fastcall BeforeUnloadClientLib(void);
	void __fastcall CheckListIndex(int I, int ArrayLength);
	AnsiString __fastcall GetClientLibName();
	/*         class method */ static AnsiString __fastcall ProfilesRegKey(TMetaClass* vmt);
	void __fastcall ReadMapiSettings(void);
	
public:
	__fastcall TJclSimpleMapi(void);
	__fastcall virtual ~TJclSimpleMapi(void);
	bool __fastcall ClientLibLoaded(void);
	void __fastcall LoadClientLib(void);
	void __fastcall UnloadClientLib(void);
	__property bool AnyClientInstalled = {read=FAnyClientInstalled, nodefault};
	__property TJclMapiClientConnect ClientConnectKind = {read=FClientConnectKind, write=SetClientConnectKind, nodefault};
	__property int ClientCount = {read=GetClientCount, nodefault};
	__property TJclMapiClient Clients[int Index] = {read=GetClients/*, default*/};
	__property AnsiString CurrentClientName = {read=GetCurrentClientName};
	__property int DefaultClientIndex = {read=FDefaultClientIndex, nodefault};
	__property AnsiString DefaultProfileName = {read=FDefaultProfileName};
	__property bool MapiInstalled = {read=FMapiInstalled, nodefault};
	__property AnsiString MapiVersion = {read=FMapiVersion};
	__property int ProfileCount = {read=GetProfileCount, nodefault};
	__property AnsiString Profiles[int Index] = {read=GetProfiles};
	__property int SelectedClientIndex = {read=FSelectedClientIndex, write=SetSelectedClientIndex, nodefault};
	__property bool SimpleMapiInstalled = {read=FSimpleMapiInstalled, nodefault};
	__property Classes::TNotifyEvent BeforeUnloadClient = {read=FBeforeUnloadClient, write=FBeforeUnloadClient};
	__property Mapi::TFNMapiAddress MapiAddress = {read=FMapiAddress};
	__property Mapi::TFNMapiDeleteMail MapiDeleteMail = {read=FMapiDeleteMail};
	__property Mapi::TFNMapiDetails MapiDetails = {read=FMapiDetails};
	__property Mapi::TFNMapiFindNext MapiFindNext = {read=FMapiFindNext};
	__property Mapi::TFNMapiFreeBuffer MapiFreeBuffer = {read=FMapiFreeBuffer};
	__property Mapi::TFNMapiLogOff MapiLogOff = {read=FMapiLogOff};
	__property Mapi::TFNMapiLogOn MapiLogOn = {read=FMapiLogOn};
	__property Mapi::TFNMapiReadMail MapiReadMail = {read=FMapiReadMail};
	__property Mapi::TFNMapiResolveName MapiResolveName = {read=FMapiResolveName};
	__property Mapi::TFNMapiSaveMail MapiSaveMail = {read=FMapiSaveMail};
	__property Mapi::TFNMapiSendDocuments MapiSendDocuments = {read=FMapiSendDocuments};
	__property Mapi::TFNMapiSendMail MapiSendMail = {read=FMapiSendMail};
};


#pragma option push -b-
enum TJclEmailRecipKind { rkOriginator, rkTO, rkCC, rkBCC };
#pragma option pop

class DELPHICLASS TJclEmailRecip;
class PASCALIMPLEMENTATION TJclEmailRecip : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FAddress;
	AnsiString FAddressType;
	TJclEmailRecipKind FKind;
	AnsiString FName;
	void __fastcall SetAddress(AnsiString Value);
	
protected:
	AnsiString __fastcall SortingName();
	
public:
	AnsiString __fastcall AddressAndName();
	/*         class method */ static AnsiString __fastcall RecipKindToString(TMetaClass* vmt, const TJclEmailRecipKind AKind);
	__property AnsiString AddressType = {read=FAddressType, write=FAddressType};
	__property AnsiString Address = {read=FAddress, write=SetAddress};
	__property TJclEmailRecipKind Kind = {read=FKind, write=FKind, nodefault};
	__property AnsiString Name = {read=FName, write=FName};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclEmailRecip(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclEmailRecip(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclEmailRecips;
class PASCALIMPLEMENTATION TJclEmailRecips : public Contnrs::TObjectList 
{
	typedef Contnrs::TObjectList inherited;
	
public:
	TJclEmailRecip* operator[](int Index) { return Items[Index]; }
	
private:
	AnsiString FAddressesType;
	TJclEmailRecip* __fastcall GetItems(int Index);
	TJclEmailRecip* __fastcall GetOriginator(void);
	
public:
	HIDESBASE int __fastcall Add(const AnsiString Address, const AnsiString Name = "", const TJclEmailRecipKind Kind = (TJclEmailRecipKind)(0x1), const AnsiString AddressType = "");
	void __fastcall SortRecips(void);
	__property AnsiString AddressesType = {read=FAddressesType, write=FAddressesType};
	__property TJclEmailRecip* Items[int Index] = {read=GetItems/*, default*/};
	__property TJclEmailRecip* Originator = {read=GetOriginator};
public:
	#pragma option push -w-inl
	/* TObjectList.Create */ inline __fastcall TJclEmailRecips(void)/* overload */ : Contnrs::TObjectList() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TJclEmailRecips(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TJclEmailFindOption { foFifo, foUnreadOnly };
#pragma option pop

#pragma option push -b-
enum TJclEmailLogonOption { loLogonUI, loNewSession, loForceDownload };
#pragma option pop

#pragma option push -b-
enum TJclEmailReadOption { roAttachments, roHeaderOnly, roMarkAsRead };
#pragma option pop

typedef Set<TJclEmailFindOption, foFifo, foUnreadOnly>  TJclEmailFindOptions;

typedef Set<TJclEmailLogonOption, loLogonUI, loForceDownload>  TJclEmailLogonOptions;

typedef Set<TJclEmailReadOption, roAttachments, roMarkAsRead>  TJclEmailReadOptions;

struct TJclEmailReadMsg
{
	
public:
	AnsiString ConversationID;
	System::TDateTime DateReceived;
	AnsiString MessageType;
	unsigned Flags;
} ;

typedef DynamicArray<unsigned >  TJclTaskWindowsList;

class DELPHICLASS TJclEmail;
class PASCALIMPLEMENTATION TJclEmail : public TJclSimpleMapi 
{
	typedef TJclSimpleMapi inherited;
	
private:
	Classes::TStringList* FAttachments;
	AnsiString FBody;
	TJclEmailFindOptions FFindOptions;
	bool FHtmlBody;
	TJclEmailLogonOptions FLogonOptions;
	unsigned FParentWnd;
	bool FParentWndValid;
	TJclEmailReadMsg FReadMsg;
	TJclEmailRecips* FRecipients;
	AnsiString FSeedMessageID;
	unsigned FSessionHandle;
	AnsiString FSubject;
	DynamicArray<unsigned >  FTaskWindowList;
	Classes::TStringList* FAttachmentFiles;
	Classes::TStrings* __fastcall GetAttachments(void);
	Classes::TStrings* __fastcall GetAttachmentFiles(void);
	unsigned __fastcall GetParentWnd(void);
	bool __fastcall GetUserLogged(void);
	void __fastcall SetBody(const AnsiString Value);
	void __fastcall SetParentWnd(const unsigned Value);
	
protected:
	DYNAMIC void __fastcall BeforeUnloadClientLib(void);
	void __fastcall DecodeRecips(Mapi::PMapiRecipDesc RecipDesc, int Count);
	bool __fastcall InternalSendOrSave(bool Save, bool ShowDialog);
	unsigned __fastcall LogonOptionsToFlags(bool ShowDialog);
	
public:
	__fastcall TJclEmail(void);
	__fastcall virtual ~TJclEmail(void);
	bool __fastcall Address(const AnsiString Caption = "", int EditFields = 0x3);
	void __fastcall Clear(void);
	bool __fastcall Delete(const AnsiString MessageID);
	bool __fastcall FindFirstMessage(void);
	bool __fastcall FindNextMessage(void);
	void __fastcall LogOff(void);
	void __fastcall LogOn(const AnsiString ProfileName = "", const AnsiString Password = "");
	int __fastcall MessageReport(Classes::TStrings* Strings, int MaxWidth = 0x50, bool IncludeAddresses = false);
	bool __fastcall Read(const TJclEmailReadOptions Options = Set<TJclEmailReadOption, roAttachments, roMarkAsRead> () );
	bool __fastcall ResolveName(AnsiString &Name, AnsiString &Address, bool ShowDialog = false);
	void __fastcall RestoreTaskWindows(void);
	bool __fastcall Save(void);
	void __fastcall SaveTaskWindows(void);
	bool __fastcall Send(bool ShowDialog = true);
	void __fastcall SortAttachments(void);
	__property Classes::TStrings* Attachments = {read=GetAttachments};
	__property Classes::TStrings* AttachmentFiles = {read=GetAttachmentFiles};
	__property AnsiString Body = {read=FBody, write=SetBody};
	__property TJclEmailFindOptions FindOptions = {read=FFindOptions, write=FFindOptions, nodefault};
	__property bool HtmlBody = {read=FHtmlBody, write=FHtmlBody, nodefault};
	__property TJclEmailLogonOptions LogonOptions = {read=FLogonOptions, write=FLogonOptions, nodefault};
	__property unsigned ParentWnd = {read=GetParentWnd, write=SetParentWnd, nodefault};
	__property TJclEmailReadMsg ReadMsg = {read=FReadMsg};
	__property TJclEmailRecips* Recipients = {read=FRecipients};
	__property AnsiString SeedMessageID = {read=FSeedMessageID, write=FSeedMessageID};
	__property unsigned SessionHandle = {read=FSessionHandle, nodefault};
	__property AnsiString Subject = {read=FSubject, write=FSubject};
	__property bool UserLogged = {read=GetUserLogged, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
#define MapiAddressTypeSMTP "SMTP"
#define MapiAddressTypeFAX "FAX"
#define MapiAddressTypeTLX "TLX"
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE unsigned __fastcall MapiCheck(const unsigned Res, bool IgnoreUserAbort = true);
extern PACKAGE AnsiString __fastcall MapiErrorMessage(const unsigned ErrorCode);
extern PACKAGE bool __fastcall JclSimpleSendMail(const AnsiString Recipient, const AnsiString Name, const AnsiString Subject, const AnsiString Body, const AnsiString Attachment = "", bool ShowDialog = true, unsigned ParentWND = (unsigned)(0x0), const AnsiString ProfileName = "", const AnsiString Password = "");
extern PACKAGE bool __fastcall JclSimpleSendFax(const AnsiString Recipient, const AnsiString Name, const AnsiString Subject, const AnsiString Body, const AnsiString Attachment = "", bool ShowDialog = true, unsigned ParentWND = (unsigned)(0x0), const AnsiString ProfileName = "", const AnsiString Password = "");
extern PACKAGE bool __fastcall JclSimpleBringUpSendMailDialog(const AnsiString Subject, const AnsiString Body, const AnsiString Attachment = "", unsigned ParentWND = (unsigned)(0x0), const AnsiString ProfileName = "", const AnsiString Password = "");

}	/* namespace Jclmapi */
using namespace Jclmapi;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclmapi
