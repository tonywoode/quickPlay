// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Zmdlg.pas' rev: 10.00

#ifndef ZmdlgHPP
#define ZmdlgHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Zmdlg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TZipDialogBox;
#pragma pack(push,1)
class PASCALIMPLEMENTATION TZipDialogBox : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
private:
	#pragma pack(push,1)
	Types::TPoint AvDlgUnits;
	#pragma pack(pop)
	int BeepID;
	int ctx;
	Stdctrls::TLabel* DxText;
	char *IconID;
	Stdctrls::TEdit* PwdEdit;
	int __fastcall GetDlgType(void);
	AnsiString __fastcall GetPWrd();
	void __fastcall SetPwrd(const AnsiString Value);
	
public:
	__fastcall virtual TZipDialogBox(Classes::TComponent* Owner, int context);
	void __fastcall Build(AnsiString title, AnsiString msg, Dialogs::TMsgDlgButtons btns);
	virtual int __fastcall ShowModal(void);
	__property int DlgType = {read=GetDlgType, nodefault};
	__property AnsiString PWrd = {read=GetPWrd, write=SetPwrd};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TZipDialogBox(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TZipDialogBox(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TZipDialogBox(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TZipDialogBox(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const int zmtWarning = 0x100000;
static const int zmtError = 0x110000;
static const int zmtInformation = 0x120000;
static const int zmtConfirmation = 0x130000;
static const int zmtPassword = 0x140000;

}	/* namespace Zmdlg */
using namespace Zmdlg;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Zmdlg
