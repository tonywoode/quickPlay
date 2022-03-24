// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclstructstorage.pas' rev: 10.00

#ifndef JclstructstorageHPP
#define JclstructstorageHPP

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
#include <Activex.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclstructstorage
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EJclStructStorageError;
class PASCALIMPLEMENTATION EJclStructStorageError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclStructStorageError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclStructStorageError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclStructStorageError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclStructStorageError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclStructStorageError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclStructStorageError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclStructStorageError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclStructStorageError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclStructStorageError(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TJclStructStorageAccessMode { smOpenRead, smOpenWrite, smCreate, smShareDenyRead, smShareDenyWrite, smTransacted };
#pragma option pop

typedef Set<TJclStructStorageAccessMode, smOpenRead, smTransacted>  TJclStructStorageAccessModes;

class DELPHICLASS TJclStructStorageFolder;
class PASCALIMPLEMENTATION TJclStructStorageFolder : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	AnsiString __fastcall GetName();
	
protected:
	_di_IStorage FStorage;
	HRESULT FLastError;
	AnsiString FFileName;
	TJclStructStorageAccessModes FAccessMode;
	unsigned FConvertedMode;
	void __fastcall Check(void);
	bool __fastcall CheckResult(HRESULT HR);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	/*         class method */ static HRESULT __fastcall IsStructured(TMetaClass* vmt, const AnsiString FileName);
	/*         class method */ static HRESULT __fastcall Convert(TMetaClass* vmt, const AnsiString FileName);
	bool __fastcall CopyTo(const AnsiString OldName, const AnsiString NewName, TJclStructStorageFolder* Dest);
	bool __fastcall MoveTo(const AnsiString OldName, const AnsiString NewName, TJclStructStorageFolder* Dest);
	bool __fastcall Commit(void);
	bool __fastcall Revert(void);
	__fastcall virtual TJclStructStorageFolder(const AnsiString FileName, TJclStructStorageAccessModes AccessMode, bool OpenDirect);
	__fastcall virtual ~TJclStructStorageFolder(void);
	bool __fastcall GetStats(/* out */ tagSTATSTG &Stat, bool IncludeName);
	void __fastcall FreeStats(tagSTATSTG &Stat);
	bool __fastcall GetSubItems(Classes::TStrings* Strings, bool Folders);
	bool __fastcall Add(const AnsiString Name, bool IsFolder);
	bool __fastcall Delete(const AnsiString Name);
	bool __fastcall Rename(const AnsiString OldName, const AnsiString NewName);
	bool __fastcall GetFolder(const AnsiString Name, /* out */ TJclStructStorageFolder* &Storage);
	bool __fastcall GetFileStream(const AnsiString Name, /* out */ Classes::TStream* &Stream);
	bool __fastcall SetElementTimes(const AnsiString Name, const tagSTATSTG &Stat);
	__property AnsiString Name = {read=GetName};
	__property _di_IStorage Intf = {read=FStorage};
	__property HRESULT LastError = {read=FLastError, nodefault};
};


class DELPHICLASS TJclStructStorageStream;
class PASCALIMPLEMENTATION TJclStructStorageStream : public Classes::TStream 
{
	typedef Classes::TStream inherited;
	
private:
	AnsiString __fastcall GetName();
	
protected:
	_di_IStream FStream;
	AnsiString FName;
	HRESULT FLastError;
	void __fastcall Check(void);
	bool __fastcall CheckResult(HRESULT HR);
	virtual void __fastcall SetSize(int NewSize)/* overload */;
	
public:
	__fastcall virtual ~TJclStructStorageStream(void);
	bool __fastcall GetStats(/* out */ tagSTATSTG &Stat, bool IncludeName);
	void __fastcall FreeStats(tagSTATSTG &Stat);
	TJclStructStorageStream* __fastcall Clone(void);
	bool __fastcall CopyTo(TJclStructStorageStream* Stream, __int64 Size);
	virtual int __fastcall Read(void *Buffer, int Count);
	virtual int __fastcall Write(const void *Buffer, int Count);
	virtual int __fastcall Seek(int Offset, Word Origin)/* overload */;
	__property AnsiString Name = {read=GetName};
	__property _di_IStream Intf = {read=FStream};
	__property HRESULT LastError = {read=FLastError, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclStructStorageStream(void) : Classes::TStream() { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetSize(const __int64 NewSize){ TStream::SetSize(NewSize); }
	
public:
	inline __int64 __fastcall  Seek(const __int64 Offset, Classes::TSeekOrigin Origin){ return TStream::Seek(Offset, Origin); }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE void __fastcall CoMallocFree(void * P);

}	/* namespace Jclstructstorage */
using namespace Jclstructstorage;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclstructstorage
