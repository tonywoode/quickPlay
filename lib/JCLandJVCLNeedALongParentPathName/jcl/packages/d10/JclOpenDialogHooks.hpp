// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclopendialoghooks.pas' rev: 10.00

#ifndef JclopendialoghooksHPP
#define JclopendialoghooksHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Extctrls.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclpeimage.hpp>	// Pascal unit
#include <Jclwin32.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclopendialoghooks
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TJclOpenDialogHook;
class PASCALIMPLEMENTATION TJclOpenDialogHook : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	bool FDisableHelpButton;
	bool FDisablePlacesBar;
	Jclpeimage::TJclPeMapImgHooks* FHooks;
	bool FIsOpenPictureDialog;
	void *FParentWndInstance;
	void *FOldParentWndInstance;
	AnsiString FPictureDialogLastFolder;
	void *FWndInstance;
	void *FOldWndInstance;
	Classes::TNotifyEvent FOnClose;
	Classes::TNotifyEvent FOnShow;
	AnsiString __fastcall GetCurrentFolder();
	HWND __fastcall GetFileNameEditWnd(void);
	void __fastcall SetCurrentFolder(const AnsiString Value);
	
protected:
	HWND FHandle;
	HWND FParentWnd;
	virtual void __fastcall AdjustControlPos(void);
	virtual void __fastcall DialogFolderChange(void);
	virtual void __fastcall DialogShow(void);
	void __fastcall DoClose(void);
	void __fastcall DoShow(void);
	virtual void __fastcall ParentWndProc(Messages::TMessage &Message);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	__property HWND FileNameEditWnd = {read=GetFileNameEditWnd, nodefault};
	
public:
	__fastcall virtual TJclOpenDialogHook(void);
	__fastcall virtual ~TJclOpenDialogHook(void);
	void __fastcall HookDialogs(void);
	void __fastcall UnhookDialogs(void);
	__property AnsiString CurrentFolder = {read=GetCurrentFolder, write=SetCurrentFolder};
	__property bool DisableHelpButton = {read=FDisableHelpButton, write=FDisableHelpButton, nodefault};
	__property bool DisablePlacesBar = {read=FDisablePlacesBar, write=FDisablePlacesBar, nodefault};
	__property bool IsOpenPictureDialog = {read=FIsOpenPictureDialog, nodefault};
	__property AnsiString PictureDialogLastFolder = {read=FPictureDialogLastFolder, write=FPictureDialogLastFolder};
	__property Classes::TNotifyEvent OnClose = {read=FOnClose, write=FOnClose};
	__property Classes::TNotifyEvent OnShow = {read=FOnShow, write=FOnShow};
};


typedef TMetaClass* TJclOpenDialogHookClass;

class DELPHICLASS EJclOpenDialogHookError;
class PASCALIMPLEMENTATION EJclOpenDialogHookError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclOpenDialogHookError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclOpenDialogHookError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclOpenDialogHookError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclOpenDialogHookError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclOpenDialogHookError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclOpenDialogHookError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclOpenDialogHookError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclOpenDialogHookError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclOpenDialogHookError(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE TJclOpenDialogHook* __fastcall InitializeOpenDialogHook(TMetaClass* OpenDialogHookClass);
extern PACKAGE void __fastcall FinalizeOpenDialogHook(void);

}	/* namespace Jclopendialoghooks */
using namespace Jclopendialoghooks;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclopendialoghooks
