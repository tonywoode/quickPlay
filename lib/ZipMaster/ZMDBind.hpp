// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Zmdbind.pas' rev: 10.00

#ifndef ZmdbindHPP
#define ZmdbindHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Zipmstr.hpp>	// Pascal unit
#include <Zmcore.hpp>	// Pascal unit
#include <Zmdelzip.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Zmdbind
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TZMDynamicBind;
#pragma pack(push,1)
class PASCALIMPLEMENTATION TZMDynamicBind : public Zmcore::TZMCore 
{
	typedef Zmcore::TZMCore inherited;
	
private:
	Zmdelzip::TAbortOperationFunc AbortFunc;
	AnsiString FDllDirectory;
	bool fKillTemp;
	AnsiString FPath;
	int fVer;
	HWND hndl;
	int loadLevel;
	Zmdelzip::TDllPathFunc PathFunc;
	int Priv;
	Zmdelzip::TDllPrivVersionFunc PrivFunc;
	AnsiString TmpFileName;
	Zmdelzip::TUnzExecFunc UnzExecFunc;
	Zmdelzip::TDllVersionFunc VersFunc;
	Zmdelzip::TZipExecFunc ZipExecFunc;
	int __fastcall GetDll_Build(void);
	bool __fastcall GetDll_Load(void);
	AnsiString __fastcall GetPath();
	AnsiString __fastcall GetResDllPath();
	AnsiString __fastcall GetVersion();
	int __fastcall LoadDll(int level);
	int __fastcall LoadLib(AnsiString FullPath, bool MustExist);
	void __fastcall ReleaseLib(void);
	void __fastcall RemoveTempDll(void);
	void __fastcall SetDllDirectory(const AnsiString Value);
	void __fastcall SetDll_Load(const bool Value);
	int __fastcall UnloadDll(int level);
	
protected:
	unsigned fDllOperKey;
	void __fastcall CheckExec(int RetVal);
	int __fastcall DoDllLoad(void);
	void __fastcall DoDllUnload(void);
	int __fastcall DoUnzExec(Zmdelzip::pUnZipParms Rec);
	int __fastcall DoZipExec(Zmdelzip::pZipParms Rec);
	void __fastcall Empty(void);
	
public:
	__fastcall TZMDynamicBind(Zipmstr::TCustomZipMaster* AMaster);
	__fastcall virtual ~TZMDynamicBind(void);
	void __fastcall AbortDll(void);
	virtual void __fastcall Clear(void);
	__property AnsiString DllDirectory = {read=FDllDirectory, write=SetDllDirectory};
	__property int Dll_Build = {read=GetDll_Build, nodefault};
	__property bool Dll_Load = {read=GetDll_Load, write=SetDll_Load, nodefault};
	__property AnsiString Dll_Path = {read=GetPath};
	__property AnsiString Dll_Version = {read=GetVersion};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Zmdbind */
using namespace Zmdbind;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Zmdbind
