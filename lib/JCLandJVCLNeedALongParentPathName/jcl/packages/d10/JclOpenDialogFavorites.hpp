// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclopendialogfavorites.pas' rev: 10.00

#ifndef JclopendialogfavoritesHPP
#define JclopendialogfavoritesHPP

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
#include <Jclpeimage.hpp>	// Pascal unit
#include <Jclwin32.hpp>	// Pascal unit
#include <Jclopendialoghooks.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclopendialogfavorites
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TJclOpenDialogFavoritesHook;
class PASCALIMPLEMENTATION TJclOpenDialogFavoritesHook : public Jclopendialoghooks::TJclOpenDialogHook 
{
	typedef Jclopendialoghooks::TJclOpenDialogHook inherited;
	
private:
	Stdctrls::TButton* FAddButton;
	bool FDeleteMode;
	Stdctrls::TComboBox* FFavoriteComboBox;
	Classes::TStrings* FFavoriteFolders;
	Extctrls::TPanel* FFavoritePanel;
	void __fastcall AddButtonClick(System::TObject* Sender);
	void __fastcall FavoriteComboBoxClick(System::TObject* Sender);
	void __fastcall SetDeleteMode(const bool Value);
	
protected:
	virtual void __fastcall AdjustControlPos(void);
	virtual void __fastcall DialogFolderChange(void);
	virtual void __fastcall DialogShow(void);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	__property bool DeleteMode = {read=FDeleteMode, write=SetDeleteMode, nodefault};
	
public:
	__fastcall virtual TJclOpenDialogFavoritesHook(void);
	__fastcall virtual ~TJclOpenDialogFavoritesHook(void);
	void __fastcall LoadFavorites(const AnsiString FileName);
	__property Classes::TStrings* FavoriteFolders = {read=FFavoriteFolders};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE TJclOpenDialogFavoritesHook* __fastcall InitializeOpenDialogFavorites(void);
extern PACKAGE void __fastcall FinalizeOpenDialogFavorites(void);

}	/* namespace Jclopendialogfavorites */
using namespace Jclopendialogfavorites;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclopendialogfavorites
