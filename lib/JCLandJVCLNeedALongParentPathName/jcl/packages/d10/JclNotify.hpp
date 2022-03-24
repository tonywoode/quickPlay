// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclnotify.pas' rev: 10.00

#ifndef JclnotifyHPP
#define JclnotifyHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclsynch.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclnotify
{
//-- type declarations -------------------------------------------------------
__interface IJclListener;
typedef System::DelphiInterface<IJclListener> _di_IJclListener;
__interface IJclNotificationMessage;
typedef System::DelphiInterface<IJclNotificationMessage> _di_IJclNotificationMessage;
__interface  INTERFACE_UUID("{26A52ECC-4C22-4B71-BC88-D0EB98AF4ED5}") IJclListener  : public IInterface 
{
	
public:
	virtual void __stdcall Notification(_di_IJclNotificationMessage msg) = 0 ;
};

__interface  INTERFACE_UUID("{2618CCC6-0C7D-47EE-9A91-7A7F5264385D}") IJclNotificationMessage  : public IInterface 
{
	
};

__interface IJclNotifier;
typedef System::DelphiInterface<IJclNotifier> _di_IJclNotifier;
__interface  INTERFACE_UUID("{CAAD7814-DD04-497C-91AC-558C2D5BFF81}") IJclNotifier  : public IInterface 
{
	
public:
	virtual void __stdcall Add(_di_IJclListener listener) = 0 ;
	virtual void __stdcall Remove(_di_IJclListener listener) = 0 ;
	virtual void __stdcall Notify(_di_IJclNotificationMessage msg) = 0 ;
};

class DELPHICLASS TJclBaseListener;
class PASCALIMPLEMENTATION TJclBaseListener : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	virtual void __stdcall Notification(_di_IJclNotificationMessage msg);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclBaseListener(void) : System::TInterfacedObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclBaseListener(void) { }
	#pragma option pop
	
private:
	void *__IJclListener;	/* Jclnotify::IJclListener */
	
public:
	operator IJclListener*(void) { return (IJclListener*)&__IJclListener; }
	
};


class DELPHICLASS TJclBaseNotificationMessage;
class PASCALIMPLEMENTATION TJclBaseNotificationMessage : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclBaseNotificationMessage(void) : System::TInterfacedObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclBaseNotificationMessage(void) { }
	#pragma option pop
	
private:
	void *__IJclNotificationMessage;	/* Jclnotify::IJclNotificationMessage */
	
public:
	operator IJclNotificationMessage*(void) { return (IJclNotificationMessage*)&__IJclNotificationMessage; }
	
};


class DELPHICLASS TJclBaseNotifier;
class PASCALIMPLEMENTATION TJclBaseNotifier : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	__fastcall TJclBaseNotifier(void);
	__fastcall virtual ~TJclBaseNotifier(void);
	
private:
	Classes::TInterfaceList* FListeners;
	Jclsynch::TJclMultiReadExclusiveWrite* FSynchronizer;
	
public:
	void __stdcall Add(_di_IJclListener listener);
	void __stdcall Notify(_di_IJclNotificationMessage msg);
	void __stdcall Remove(_di_IJclListener listener);
private:
	void *__IJclNotifier;	/* Jclnotify::IJclNotifier */
	
public:
	operator IJclNotifier*(void) { return (IJclNotifier*)&__IJclNotifier; }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Jclnotify */
using namespace Jclnotify;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclnotify
