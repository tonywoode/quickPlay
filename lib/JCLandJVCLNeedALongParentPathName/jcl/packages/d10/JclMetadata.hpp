// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclmetadata.pas' rev: 10.00

#ifndef JclmetadataHPP
#define JclmetadataHPP

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
#include <Jclbase.hpp>	// Pascal unit
#include <Jclclr.hpp>	// Pascal unit
#include <Jclfileutils.hpp>	// Pascal unit
#include <Jclsysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclmetadata
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TJclClrElementType { etEnd, etVoid, etBoolean, etChar, etI1, etU1, etI2, etU2, etI4, etU4, etI8, etU8, etR4, etR8, etString, etPtr, etByRef, etValueType, etClass, etArray, etTypedByRef, etI, etU, etFnPtr, etObject, etSzArray, etCModReqd, etCModOpt, etInternal, etMax, etModifier, etSentinel, etPinned };
#pragma option pop

class DELPHICLASS TJclClrTableModuleRow;
class PASCALIMPLEMENTATION TJclClrTableModuleRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	Word FGeneration;
	unsigned FNameOffset;
	unsigned FMvidIdx;
	unsigned FEncIdIdx;
	unsigned FEncBaseIdIdx;
	GUID __fastcall GetMvid();
	WideString __fastcall GetName();
	GUID __fastcall GetEncBaseId();
	GUID __fastcall GetEncId();
	
public:
	__fastcall virtual TJclClrTableModuleRow(const Jclclr::TJclClrTable* ATable);
	virtual AnsiString __fastcall DumpIL();
	bool __fastcall HasEncId(void);
	bool __fastcall HasEncBaseId(void);
	__property Word Generation = {read=FGeneration, nodefault};
	__property unsigned NameOffset = {read=FNameOffset, nodefault};
	__property unsigned MvidIdx = {read=FMvidIdx, nodefault};
	__property unsigned EncIdIdx = {read=FEncIdIdx, nodefault};
	__property unsigned EncBaseIdIdx = {read=FEncBaseIdIdx, nodefault};
	__property WideString Name = {read=GetName};
	__property GUID Mvid = {read=GetMvid};
	__property GUID EncId = {read=GetEncId};
	__property GUID EncBaseId = {read=GetEncBaseId};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableModuleRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableModule;
class PASCALIMPLEMENTATION TJclClrTableModule : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableModuleRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableModuleRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableModule)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableModuleRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableModule(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableModule(void) { }
	#pragma option pop
	
private:
	void *__ITableCanDumpIL;	/* Jclclr::ITableCanDumpIL */
	
public:
	operator ITableCanDumpIL*(void) { return (ITableCanDumpIL*)&__ITableCanDumpIL; }
	
};


class DELPHICLASS TJclClrTableModuleRefRow;
class PASCALIMPLEMENTATION TJclClrTableModuleRefRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FNameOffset;
	WideString __fastcall GetName();
	
public:
	__fastcall virtual TJclClrTableModuleRefRow(const Jclclr::TJclClrTable* ATable);
	virtual AnsiString __fastcall DumpIL();
	__property unsigned NameOffset = {read=FNameOffset, nodefault};
	__property WideString Name = {read=GetName};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableModuleRefRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableModuleRef;
class PASCALIMPLEMENTATION TJclClrTableModuleRef : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableModuleRefRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableModuleRefRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableModuleRef)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableModuleRefRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableModuleRef(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableModuleRef(void) { }
	#pragma option pop
	
private:
	void *__ITableCanDumpIL;	/* Jclclr::ITableCanDumpIL */
	
public:
	operator ITableCanDumpIL*(void) { return (ITableCanDumpIL*)&__ITableCanDumpIL; }
	
};


#pragma option push -b-
enum TJclClrAssemblyFlag { cafPublicKey, cafCompatibilityMask, cafSideBySideCompatible, cafNonSideBySideAppDomain, cafNonSideBySideProcess, cafNonSideBySideMachine, cafEnableJITcompileTracking, cafDisableJITcompileOptimizer };
#pragma option pop

typedef Set<TJclClrAssemblyFlag, cafPublicKey, cafDisableJITcompileOptimizer>  TJclClrAssemblyFlags;

class DELPHICLASS TJclClrTableAssemblyRow;
class PASCALIMPLEMENTATION TJclClrTableAssemblyRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FCultureOffset;
	unsigned FPublicKeyOffset;
	unsigned FHashAlgId;
	unsigned FNameOffset;
	Word FMajorVersion;
	Word FBuildNumber;
	Word FRevisionNumber;
	Word FMinorVersion;
	unsigned FFlagMask;
	WideString __fastcall GetCulture();
	WideString __fastcall GetName();
	Jclclr::TJclClrBlobRecord* __fastcall GetPublicKey(void);
	AnsiString __fastcall GetVersion();
	TJclClrAssemblyFlags __fastcall GetFlags(void);
	
public:
	__fastcall virtual TJclClrTableAssemblyRow(const Jclclr::TJclClrTable* ATable);
	virtual AnsiString __fastcall DumpIL();
	/*         class method */ static unsigned __fastcall AssemblyFlags(TMetaClass* vmt, const TJclClrAssemblyFlags Flags)/* overload */;
	/*         class method */ static TJclClrAssemblyFlags __fastcall AssemblyFlags(TMetaClass* vmt, const unsigned Flags)/* overload */;
	__property unsigned HashAlgId = {read=FHashAlgId, nodefault};
	__property Word MajorVersion = {read=FMajorVersion, nodefault};
	__property Word MinorVersion = {read=FMinorVersion, nodefault};
	__property Word BuildNumber = {read=FBuildNumber, nodefault};
	__property Word RevisionNumber = {read=FRevisionNumber, nodefault};
	__property unsigned FlagMask = {read=FFlagMask, nodefault};
	__property unsigned PublicKeyOffset = {read=FPublicKeyOffset, nodefault};
	__property unsigned NameOffset = {read=FNameOffset, nodefault};
	__property unsigned CultureOffset = {read=FCultureOffset, nodefault};
	__property Jclclr::TJclClrBlobRecord* PublicKey = {read=GetPublicKey};
	__property WideString Name = {read=GetName};
	__property WideString Culture = {read=GetCulture};
	__property AnsiString Version = {read=GetVersion};
	__property TJclClrAssemblyFlags Flags = {read=GetFlags, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableAssemblyRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableAssembly;
class PASCALIMPLEMENTATION TJclClrTableAssembly : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableAssemblyRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableAssemblyRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableAssembly)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableAssemblyRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableAssembly(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableAssembly(void) { }
	#pragma option pop
	
private:
	void *__ITableCanDumpIL;	/* Jclclr::ITableCanDumpIL */
	
public:
	operator ITableCanDumpIL*(void) { return (ITableCanDumpIL*)&__ITableCanDumpIL; }
	
};


class DELPHICLASS TJclClrTableAssemblyOSRow;
class PASCALIMPLEMENTATION TJclClrTableAssemblyOSRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FPlatformID;
	unsigned FMajorVersion;
	unsigned FMinorVersion;
	AnsiString __fastcall GetVersion();
	
public:
	__fastcall virtual TJclClrTableAssemblyOSRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned PlatformID = {read=FPlatformID, nodefault};
	__property unsigned MajorVersion = {read=FMajorVersion, nodefault};
	__property unsigned MinorVersion = {read=FMinorVersion, nodefault};
	__property AnsiString Version = {read=GetVersion};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableAssemblyOSRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableAssemblyOS;
class PASCALIMPLEMENTATION TJclClrTableAssemblyOS : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableAssemblyOSRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableAssemblyOSRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableAssemblyOS)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableAssemblyOSRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableAssemblyOS(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableAssemblyOS(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableAssemblyProcessorRow;
class PASCALIMPLEMENTATION TJclClrTableAssemblyProcessorRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FProcessor;
	
public:
	__fastcall virtual TJclClrTableAssemblyProcessorRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned Processor = {read=FProcessor, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableAssemblyProcessorRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableAssemblyProcessor;
class PASCALIMPLEMENTATION TJclClrTableAssemblyProcessor : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableAssemblyProcessorRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableAssemblyProcessorRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableAssemblyProcessor)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableAssemblyProcessorRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableAssemblyProcessor(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableAssemblyProcessor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableAssemblyRefRow;
class PASCALIMPLEMENTATION TJclClrTableAssemblyRefRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FCultureOffset;
	unsigned FNameOffset;
	unsigned FPublicKeyOrTokenOffset;
	unsigned FHashValueOffset;
	Word FMajorVersion;
	Word FRevisionNumber;
	Word FBuildNumber;
	Word FMinorVersion;
	unsigned FFlagMask;
	WideString __fastcall GetCulture();
	Jclclr::TJclClrBlobRecord* __fastcall GetHashValue(void);
	WideString __fastcall GetName();
	Jclclr::TJclClrBlobRecord* __fastcall GetPublicKeyOrToken(void);
	AnsiString __fastcall GetVersion();
	TJclClrAssemblyFlags __fastcall GetFlags(void);
	
public:
	__fastcall virtual TJclClrTableAssemblyRefRow(const Jclclr::TJclClrTable* ATable);
	virtual AnsiString __fastcall DumpIL();
	__property Word MajorVersion = {read=FMajorVersion, nodefault};
	__property Word MinorVersion = {read=FMinorVersion, nodefault};
	__property Word BuildNumber = {read=FBuildNumber, nodefault};
	__property Word RevisionNumber = {read=FRevisionNumber, nodefault};
	__property unsigned FlagMask = {read=FFlagMask, nodefault};
	__property unsigned PublicKeyOrTokenOffset = {read=FPublicKeyOrTokenOffset, nodefault};
	__property unsigned NameOffset = {read=FNameOffset, nodefault};
	__property unsigned CultureOffset = {read=FCultureOffset, nodefault};
	__property unsigned HashValueOffset = {read=FHashValueOffset, nodefault};
	__property Jclclr::TJclClrBlobRecord* PublicKeyOrToken = {read=GetPublicKeyOrToken};
	__property WideString Name = {read=GetName};
	__property WideString Culture = {read=GetCulture};
	__property AnsiString Version = {read=GetVersion};
	__property Jclclr::TJclClrBlobRecord* HashValue = {read=GetHashValue};
	__property TJclClrAssemblyFlags Flags = {read=GetFlags, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableAssemblyRefRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableAssemblyRef;
class PASCALIMPLEMENTATION TJclClrTableAssemblyRef : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableAssemblyRefRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableAssemblyRefRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableAssemblyRef)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableAssemblyRefRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableAssemblyRef(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableAssemblyRef(void) { }
	#pragma option pop
	
private:
	void *__ITableCanDumpIL;	/* Jclclr::ITableCanDumpIL */
	
public:
	operator ITableCanDumpIL*(void) { return (ITableCanDumpIL*)&__ITableCanDumpIL; }
	
};


class DELPHICLASS TJclClrTableAssemblyRefOSRow;
class PASCALIMPLEMENTATION TJclClrTableAssemblyRefOSRow : public TJclClrTableAssemblyOSRow 
{
	typedef TJclClrTableAssemblyOSRow inherited;
	
private:
	unsigned FAssemblyRefIdx;
	TJclClrTableAssemblyRefRow* __fastcall GetAssemblyRef(void);
	
public:
	__fastcall virtual TJclClrTableAssemblyRefOSRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned AssemblyRefIdx = {read=FAssemblyRefIdx, nodefault};
	__property TJclClrTableAssemblyRefRow* AssemblyRef = {read=GetAssemblyRef};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableAssemblyRefOSRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableAssemblyRefOS;
class PASCALIMPLEMENTATION TJclClrTableAssemblyRefOS : public TJclClrTableAssemblyOS 
{
	typedef TJclClrTableAssemblyOS inherited;
	
public:
	TJclClrTableAssemblyRefOSRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableAssemblyRefOSRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableAssemblyRefOS)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableAssemblyRefOSRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableAssemblyRefOS(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : TJclClrTableAssemblyOS(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableAssemblyRefOS(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableAssemblyRefProcessorRow;
class PASCALIMPLEMENTATION TJclClrTableAssemblyRefProcessorRow : public TJclClrTableAssemblyProcessorRow 
{
	typedef TJclClrTableAssemblyProcessorRow inherited;
	
private:
	unsigned FAssemblyRefIdx;
	TJclClrTableAssemblyRefRow* __fastcall GetAssemblyRef(void);
	
public:
	__fastcall virtual TJclClrTableAssemblyRefProcessorRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned AssemblyRefIdx = {read=FAssemblyRefIdx, nodefault};
	__property TJclClrTableAssemblyRefRow* AssemblyRef = {read=GetAssemblyRef};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableAssemblyRefProcessorRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableAssemblyRefProcessor;
class PASCALIMPLEMENTATION TJclClrTableAssemblyRefProcessor : public TJclClrTableAssemblyProcessor 
{
	typedef TJclClrTableAssemblyProcessor inherited;
	
public:
	TJclClrTableAssemblyRefProcessorRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableAssemblyRefProcessorRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableAssemblyRefProcessor)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableAssemblyRefProcessorRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableAssemblyRefProcessor(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : TJclClrTableAssemblyProcessor(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableAssemblyRefProcessor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableClassLayoutRow;
class PASCALIMPLEMENTATION TJclClrTableClassLayoutRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FClassSize;
	unsigned FParentIdx;
	Word FPackingSize;
	
public:
	__fastcall virtual TJclClrTableClassLayoutRow(const Jclclr::TJclClrTable* ATable);
	__property Word PackingSize = {read=FPackingSize, nodefault};
	__property unsigned ClassSize = {read=FClassSize, nodefault};
	__property unsigned ParentIdx = {read=FParentIdx, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableClassLayoutRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableClassLayout;
class PASCALIMPLEMENTATION TJclClrTableClassLayout : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableClassLayoutRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableClassLayoutRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableClassLayout)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableClassLayoutRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableClassLayout(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableClassLayout(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableConstantRow;
class PASCALIMPLEMENTATION TJclClrTableConstantRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	Byte FKind;
	unsigned FParentIdx;
	unsigned FValueOffset;
	TJclClrElementType __fastcall GetElementType(void);
	Jclclr::TJclClrTableRow* __fastcall GetParent(void);
	Jclclr::TJclClrBlobRecord* __fastcall GetValue(void);
	
public:
	__fastcall virtual TJclClrTableConstantRow(const Jclclr::TJclClrTable* ATable);
	virtual AnsiString __fastcall DumpIL();
	__property Byte Kind = {read=FKind, nodefault};
	__property unsigned ParentIdx = {read=FParentIdx, nodefault};
	__property unsigned ValueOffset = {read=FValueOffset, nodefault};
	__property TJclClrElementType ElementType = {read=GetElementType, nodefault};
	__property Jclclr::TJclClrTableRow* Parent = {read=GetParent};
	__property Jclclr::TJclClrBlobRecord* Value = {read=GetValue};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableConstantRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableConstant;
class PASCALIMPLEMENTATION TJclClrTableConstant : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableConstantRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableConstantRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableConstant)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableConstantRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableConstant(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableConstant(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableCustomAttributeRow;
class PASCALIMPLEMENTATION TJclClrTableCustomAttributeRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FParentIdx;
	unsigned FTypeIdx;
	unsigned FValueOffset;
	Jclclr::TJclClrBlobRecord* __fastcall GetValue(void);
	Jclclr::TJclClrTableRow* __fastcall GetParent(void);
	Jclclr::TJclClrTableRow* __fastcall GetMethod(void);
	
public:
	__fastcall virtual TJclClrTableCustomAttributeRow(const Jclclr::TJclClrTable* ATable);
	virtual AnsiString __fastcall DumpIL();
	__property unsigned ParentIdx = {read=FParentIdx, nodefault};
	__property unsigned TypeIdx = {read=FTypeIdx, nodefault};
	__property unsigned ValueOffset = {read=FValueOffset, nodefault};
	__property Jclclr::TJclClrTableRow* Parent = {read=GetParent};
	__property Jclclr::TJclClrTableRow* Method = {read=GetMethod};
	__property Jclclr::TJclClrBlobRecord* Value = {read=GetValue};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableCustomAttributeRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableCustomAttribute;
class PASCALIMPLEMENTATION TJclClrTableCustomAttribute : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableCustomAttributeRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableCustomAttributeRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableCustomAttribute)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableCustomAttributeRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableCustomAttribute(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableCustomAttribute(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableDeclSecurityRow;
class PASCALIMPLEMENTATION TJclClrTableDeclSecurityRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FPermissionSetOffset;
	unsigned FParentIdx;
	Word FAction;
	
public:
	__fastcall virtual TJclClrTableDeclSecurityRow(const Jclclr::TJclClrTable* ATable);
	__property Word Action = {read=FAction, nodefault};
	__property unsigned ParentIdx = {read=FParentIdx, nodefault};
	__property unsigned PermissionSetOffset = {read=FPermissionSetOffset, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableDeclSecurityRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableDeclSecurity;
class PASCALIMPLEMENTATION TJclClrTableDeclSecurity : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableDeclSecurityRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableDeclSecurityRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableDeclSecurity)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableDeclSecurityRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableDeclSecurity(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableDeclSecurity(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableEventMapRow;
class PASCALIMPLEMENTATION TJclClrTableEventMapRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FEventListIdx;
	unsigned FParentIdx;
	
public:
	__fastcall virtual TJclClrTableEventMapRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned ParentIdx = {read=FParentIdx, nodefault};
	__property unsigned EventListIdx = {read=FEventListIdx, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableEventMapRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableEventMap;
class PASCALIMPLEMENTATION TJclClrTableEventMap : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableEventMapRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableEventMapRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableEventMap)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableEventMapRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableEventMap(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableEventMap(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TJclClrTableEventFlag { efSpecialName, efRTSpecialName };
#pragma option pop

typedef Set<TJclClrTableEventFlag, efSpecialName, efRTSpecialName>  TJclClrTableEventFlags;

class DELPHICLASS TJclClrTableEventDefRow;
class PASCALIMPLEMENTATION TJclClrTableEventDefRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FNameOffset;
	unsigned FEventTypeIdx;
	Word FEventFlags;
	WideString __fastcall GetName();
	
public:
	__fastcall virtual TJclClrTableEventDefRow(const Jclclr::TJclClrTable* ATable);
	__property Word EventFlags = {read=FEventFlags, nodefault};
	__property unsigned NameOffset = {read=FNameOffset, nodefault};
	__property unsigned EventTypeIdx = {read=FEventTypeIdx, nodefault};
	__property WideString Name = {read=GetName};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableEventDefRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableEventDef;
class PASCALIMPLEMENTATION TJclClrTableEventDef : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableEventDefRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableEventDefRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableEventDef)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableEventDefRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableEventDef(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableEventDef(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableExportedTypeRow;
class PASCALIMPLEMENTATION TJclClrTableExportedTypeRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FTypeDefIdx;
	unsigned FFlags;
	unsigned FImplementationIdx;
	unsigned FTypeNamespaceOffset;
	unsigned FTypeNameOffset;
	WideString __fastcall GetTypeName();
	WideString __fastcall GetTypeNamespace();
	
public:
	__fastcall virtual TJclClrTableExportedTypeRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned Flags = {read=FFlags, nodefault};
	__property unsigned TypeDefIdx = {read=FTypeDefIdx, nodefault};
	__property unsigned TypeNameOffset = {read=FTypeNameOffset, nodefault};
	__property unsigned TypeNamespaceOffset = {read=FTypeNamespaceOffset, nodefault};
	__property unsigned ImplementationIdx = {read=FImplementationIdx, nodefault};
	__property WideString TypeName = {read=GetTypeName};
	__property WideString TypeNamespace = {read=GetTypeNamespace};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableExportedTypeRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableEventPtrRow;
class PASCALIMPLEMENTATION TJclClrTableEventPtrRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FEventIdx;
	TJclClrTableEventDefRow* __fastcall GetEvent(void);
	
public:
	__fastcall virtual TJclClrTableEventPtrRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned EventIdx = {read=FEventIdx, nodefault};
	__property TJclClrTableEventDefRow* Event = {read=GetEvent};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableEventPtrRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableEventPtr;
class PASCALIMPLEMENTATION TJclClrTableEventPtr : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableEventPtrRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableEventPtrRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableEventPtr)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableEventPtrRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableEventPtr(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableEventPtr(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableExportedType;
class PASCALIMPLEMENTATION TJclClrTableExportedType : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableExportedTypeRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableExportedTypeRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableExportedType)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableExportedTypeRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableExportedType(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableExportedType(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TJclClrTableFieldDefVisibility { fvPrivateScope, fvPrivate, fvFamANDAssem, fvAssembly, fvFamily, fvFamORAssem, fvPublic };
#pragma option pop

#pragma option push -b-
enum TJclClrTableFieldDefFlag { ffStatic, ffInitOnly, ffLiteral, ffNotSerialized, ffSpecialName, ffPinvokeImpl, ffRTSpecialName, ffHasFieldMarshal, ffHasDefault, ffHasFieldRVA };
#pragma option pop

typedef Set<TJclClrTableFieldDefFlag, ffStatic, ffHasFieldRVA>  TJclClrTableFieldDefFlags;

class DELPHICLASS TJclClrTableFieldDefRow;
class DELPHICLASS TJclClrTableTypeDefRow;
class DELPHICLASS TJclClrTableMethodDefRow;
#pragma option push -b-
enum TJclClrTypeAttribute { taAbstract, taSealed, taSpecialName, taImport, taSerializable, taBeforeFieldInit, taRTSpecialName, taHasSecurity };
#pragma option pop

typedef Set<TJclClrTypeAttribute, taAbstract, taHasSecurity>  TJclClrTypeAttributes;

#pragma option push -b-
enum TJclClrClassLayout { clAuto, clSequential, clExplicit };
#pragma option pop

#pragma option push -b-
enum TJclClrClassSemantics { csClass, csInterface };
#pragma option pop

#pragma option push -b-
enum TJclClrStringFormatting { sfAnsi, sfUnicode, sfAutoChar };
#pragma option pop

#pragma option push -b-
enum TJclClrTypeVisibility { tvNotPublic, tvPublic, tvNestedPublic, tvNestedPrivate, tvNestedFamily, tvNestedAssembly, tvNestedFamANDAssem, tvNestedFamORAssem };
#pragma option pop

class PASCALIMPLEMENTATION TJclClrTableTypeDefRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FNamespaceOffset;
	unsigned FNameOffset;
	unsigned FFlags;
	unsigned FExtendsIdx;
	unsigned FFieldListIdx;
	unsigned FMethodListIdx;
	Classes::TList* FFields;
	Classes::TList* FMethods;
	WideString __fastcall GetName();
	WideString __fastcall GetNamespace();
	TJclClrTableFieldDefRow* __fastcall GetField(const int Idx);
	int __fastcall GetFieldCount(void);
	TJclClrTableMethodDefRow* __fastcall GetMethod(const int Idx);
	int __fastcall GetMethodCount(void);
	void __fastcall UpdateFields(void);
	void __fastcall UpdateMethods(void);
	WideString __fastcall GetFullName();
	TJclClrTypeAttributes __fastcall GetAttributes(void);
	TJclClrClassLayout __fastcall GetClassLayout(void);
	TJclClrClassSemantics __fastcall GetClassSemantics(void);
	TJclClrStringFormatting __fastcall GetStringFormatting(void);
	TJclClrTypeVisibility __fastcall GetVisibility(void);
	Jclclr::TJclClrTableRow* __fastcall GetExtends(void);
	
protected:
	virtual void __fastcall Update(void);
	
public:
	__fastcall virtual TJclClrTableTypeDefRow(const Jclclr::TJclClrTable* ATable);
	__fastcall virtual ~TJclClrTableTypeDefRow(void);
	virtual AnsiString __fastcall DumpIL();
	bool __fastcall HasField(void);
	bool __fastcall HasMethod(void);
	__property unsigned Flags = {read=FFlags, nodefault};
	__property unsigned NameOffset = {read=FNameOffset, nodefault};
	__property unsigned NamespaceOffset = {read=FNamespaceOffset, nodefault};
	__property unsigned ExtendsIdx = {read=FExtendsIdx, nodefault};
	__property unsigned FieldListIdx = {read=FFieldListIdx, nodefault};
	__property unsigned MethodListIdx = {read=FMethodListIdx, nodefault};
	__property WideString Name = {read=GetName};
	__property WideString Namespace = {read=GetNamespace};
	__property WideString FullName = {read=GetFullName};
	__property Jclclr::TJclClrTableRow* Extends = {read=GetExtends};
	__property TJclClrTypeAttributes Attributes = {read=GetAttributes, nodefault};
	__property TJclClrTypeVisibility Visibility = {read=GetVisibility, nodefault};
	__property TJclClrClassLayout ClassLayout = {read=GetClassLayout, nodefault};
	__property TJclClrClassSemantics ClassSemantics = {read=GetClassSemantics, nodefault};
	__property TJclClrStringFormatting StringFormatting = {read=GetStringFormatting, nodefault};
	__property TJclClrTableFieldDefRow* Fields[int Idx] = {read=GetField};
	__property int FieldCount = {read=GetFieldCount, nodefault};
	__property TJclClrTableMethodDefRow* Methods[int Idx] = {read=GetMethod};
	__property int MethodCount = {read=GetMethodCount, nodefault};
};


class PASCALIMPLEMENTATION TJclClrTableFieldDefRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	Word FFlags;
	unsigned FNameOffset;
	unsigned FSignatureOffset;
	TJclClrTableTypeDefRow* FParentToken;
	WideString __fastcall GetName();
	Jclclr::TJclClrBlobRecord* __fastcall GetSignature(void);
	TJclClrTableFieldDefFlags __fastcall GetFlag(void);
	TJclClrTableFieldDefVisibility __fastcall GetVisibility(void);
	
protected:
	void __fastcall SetParentToken(const TJclClrTableTypeDefRow* ARow);
	
public:
	__fastcall virtual TJclClrTableFieldDefRow(const Jclclr::TJclClrTable* ATable);
	virtual AnsiString __fastcall DumpIL();
	__property Word RawFlags = {read=FFlags, nodefault};
	__property unsigned NameOffset = {read=FNameOffset, nodefault};
	__property unsigned SignatureOffset = {read=FSignatureOffset, nodefault};
	__property WideString Name = {read=GetName};
	__property Jclclr::TJclClrBlobRecord* Signature = {read=GetSignature};
	__property TJclClrTableTypeDefRow* ParentToken = {read=FParentToken};
	__property TJclClrTableFieldDefVisibility Visibility = {read=GetVisibility, nodefault};
	__property TJclClrTableFieldDefFlags Flags = {read=GetFlag, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableFieldDefRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableFieldDef;
class PASCALIMPLEMENTATION TJclClrTableFieldDef : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableFieldDefRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableFieldDefRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableFieldDef)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableFieldDefRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableFieldDef(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableFieldDef(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableFieldPtrRow;
class PASCALIMPLEMENTATION TJclClrTableFieldPtrRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FFieldIdx;
	TJclClrTableFieldDefRow* __fastcall GetField(void);
	
public:
	__fastcall virtual TJclClrTableFieldPtrRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned FieldIdx = {read=FFieldIdx, nodefault};
	__property TJclClrTableFieldDefRow* Field = {read=GetField};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableFieldPtrRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableFieldPtr;
class PASCALIMPLEMENTATION TJclClrTableFieldPtr : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableFieldPtrRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableFieldPtrRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableFieldPtr)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableFieldPtrRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableFieldPtr(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableFieldPtr(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableFieldLayoutRow;
class PASCALIMPLEMENTATION TJclClrTableFieldLayoutRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FOffset;
	unsigned FFieldIdx;
	
public:
	__fastcall virtual TJclClrTableFieldLayoutRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned Offset = {read=FOffset, nodefault};
	__property unsigned FieldIdx = {read=FFieldIdx, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableFieldLayoutRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableFieldLayout;
class PASCALIMPLEMENTATION TJclClrTableFieldLayout : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableFieldLayoutRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableFieldLayoutRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableFieldLayout)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableFieldLayoutRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableFieldLayout(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableFieldLayout(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableFieldMarshalRow;
class PASCALIMPLEMENTATION TJclClrTableFieldMarshalRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FParentIdx;
	unsigned FNativeTypeOffset;
	
public:
	__fastcall virtual TJclClrTableFieldMarshalRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned ParentIdx = {read=FParentIdx, nodefault};
	__property unsigned NativeTypeOffset = {read=FNativeTypeOffset, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableFieldMarshalRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableFieldMarshal;
class PASCALIMPLEMENTATION TJclClrTableFieldMarshal : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableFieldMarshalRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableFieldMarshalRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableFieldMarshal)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableFieldMarshalRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableFieldMarshal(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableFieldMarshal(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableFieldRVARow;
class PASCALIMPLEMENTATION TJclClrTableFieldRVARow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FRVA;
	unsigned FFieldIdx;
	
public:
	__fastcall virtual TJclClrTableFieldRVARow(const Jclclr::TJclClrTable* ATable);
	__property unsigned RVA = {read=FRVA, nodefault};
	__property unsigned FieldIdx = {read=FFieldIdx, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableFieldRVARow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableFieldRVA;
class PASCALIMPLEMENTATION TJclClrTableFieldRVA : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableFieldRVARow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableFieldRVARow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableFieldRVA)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableFieldRVARow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableFieldRVA(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableFieldRVA(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableFileRow;
class PASCALIMPLEMENTATION TJclClrTableFileRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FHashValueOffset;
	unsigned FNameOffset;
	unsigned FFlags;
	WideString __fastcall GetName();
	Jclclr::TJclClrBlobRecord* __fastcall GetHashValue(void);
	bool __fastcall GetContainsMetadata(void);
	
public:
	__fastcall virtual TJclClrTableFileRow(const Jclclr::TJclClrTable* ATable);
	virtual AnsiString __fastcall DumpIL();
	__property unsigned Flags = {read=FFlags, nodefault};
	__property unsigned NameOffset = {read=FNameOffset, nodefault};
	__property unsigned HashValueOffset = {read=FHashValueOffset, nodefault};
	__property WideString Name = {read=GetName};
	__property Jclclr::TJclClrBlobRecord* HashValue = {read=GetHashValue};
	__property bool ContainsMetadata = {read=GetContainsMetadata, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableFileRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableFile;
class PASCALIMPLEMENTATION TJclClrTableFile : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableFileRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableFileRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableFile)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableFileRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableFile(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableFile(void) { }
	#pragma option pop
	
private:
	void *__ITableCanDumpIL;	/* Jclclr::ITableCanDumpIL */
	
public:
	operator ITableCanDumpIL*(void) { return (ITableCanDumpIL*)&__ITableCanDumpIL; }
	
};


class DELPHICLASS TJclClrTableImplMapRow;
class PASCALIMPLEMENTATION TJclClrTableImplMapRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FImportNameOffset;
	unsigned FMemberForwardedIdx;
	unsigned FImportScopeIdx;
	Word FMappingFlags;
	WideString __fastcall GetImportName();
	
public:
	__fastcall virtual TJclClrTableImplMapRow(const Jclclr::TJclClrTable* ATable);
	__property Word MappingFlags = {read=FMappingFlags, nodefault};
	__property unsigned MemberForwardedIdx = {read=FMemberForwardedIdx, nodefault};
	__property unsigned ImportNameOffset = {read=FImportNameOffset, nodefault};
	__property unsigned ImportScopeIdx = {read=FImportScopeIdx, nodefault};
	__property WideString ImportName = {read=GetImportName};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableImplMapRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableImplMap;
class PASCALIMPLEMENTATION TJclClrTableImplMap : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableImplMapRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableImplMapRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableImplMap)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableImplMapRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableImplMap(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableImplMap(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableInterfaceImplRow;
class PASCALIMPLEMENTATION TJclClrTableInterfaceImplRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FInterfaceIdx;
	unsigned FClassIdx;
	Jclclr::TJclClrTableRow* __fastcall GetImplClass(void);
	Jclclr::TJclClrTableRow* __fastcall GetImplInterface(void);
	
public:
	__fastcall virtual TJclClrTableInterfaceImplRow(const Jclclr::TJclClrTable* ATable);
	virtual AnsiString __fastcall DumpIL();
	__property unsigned ClassIdx = {read=FClassIdx, nodefault};
	__property unsigned InterfaceIdx = {read=FInterfaceIdx, nodefault};
	__property Jclclr::TJclClrTableRow* ImplClass = {read=GetImplClass};
	__property Jclclr::TJclClrTableRow* ImplInterface = {read=GetImplInterface};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableInterfaceImplRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableInterfaceImpl;
class PASCALIMPLEMENTATION TJclClrTableInterfaceImpl : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableInterfaceImplRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableInterfaceImplRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableInterfaceImpl)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableInterfaceImplRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableInterfaceImpl(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableInterfaceImpl(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TJclClrTableManifestResourceVisibility { rvPublic, rvPrivate };
#pragma option pop

class DELPHICLASS TJclClrTableManifestResourceRow;
class PASCALIMPLEMENTATION TJclClrTableManifestResourceRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FOffset;
	unsigned FFlags;
	unsigned FImplementationIdx;
	unsigned FNameOffset;
	WideString __fastcall GetName();
	TJclClrTableManifestResourceVisibility __fastcall GetVisibility(void);
	Jclclr::TJclClrTableRow* __fastcall GetImplementationRow(void);
	
public:
	__fastcall virtual TJclClrTableManifestResourceRow(const Jclclr::TJclClrTable* ATable);
	virtual AnsiString __fastcall DumpIL();
	__property unsigned Offset = {read=FOffset, nodefault};
	__property unsigned Flags = {read=FFlags, nodefault};
	__property unsigned NameOffset = {read=FNameOffset, nodefault};
	__property unsigned ImplementationIdx = {read=FImplementationIdx, nodefault};
	__property WideString Name = {read=GetName};
	__property TJclClrTableManifestResourceVisibility Visibility = {read=GetVisibility, nodefault};
	__property Jclclr::TJclClrTableRow* ImplementationRow = {read=GetImplementationRow};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableManifestResourceRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableManifestResource;
class PASCALIMPLEMENTATION TJclClrTableManifestResource : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableManifestResourceRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableManifestResourceRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableManifestResource)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableManifestResourceRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableManifestResource(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableManifestResource(void) { }
	#pragma option pop
	
private:
	void *__ITableCanDumpIL;	/* Jclclr::ITableCanDumpIL */
	
public:
	operator ITableCanDumpIL*(void) { return (ITableCanDumpIL*)&__ITableCanDumpIL; }
	
};


class DELPHICLASS TJclClrTableMemberRefRow;
class PASCALIMPLEMENTATION TJclClrTableMemberRefRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FClassIdx;
	unsigned FNameOffset;
	unsigned FSignatureOffset;
	WideString __fastcall GetName();
	Jclclr::TJclClrBlobRecord* __fastcall GetSignature(void);
	Jclclr::TJclClrTableRow* __fastcall GetParentClass(void);
	WideString __fastcall GetFullName();
	
public:
	__fastcall virtual TJclClrTableMemberRefRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned ClassIdx = {read=FClassIdx, nodefault};
	__property unsigned NameOffset = {read=FNameOffset, nodefault};
	__property unsigned SignatureOffset = {read=FSignatureOffset, nodefault};
	__property WideString Name = {read=GetName};
	__property WideString FullName = {read=GetFullName};
	__property Jclclr::TJclClrBlobRecord* Signature = {read=GetSignature};
	__property Jclclr::TJclClrTableRow* ParentClass = {read=GetParentClass};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableMemberRefRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableMemberRef;
class PASCALIMPLEMENTATION TJclClrTableMemberRef : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableMemberRefRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableMemberRefRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableMemberRef)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableMemberRefRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableMemberRef(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableMemberRef(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TJclClrParamKind { pkIn, pkOut, pkOptional, pkHasDefault, pkHasFieldMarshal };
#pragma option pop

typedef Set<TJclClrParamKind, pkIn, pkHasFieldMarshal>  TJclClrParamKinds;

class DELPHICLASS TJclClrTableParamDefRow;
class PASCALIMPLEMENTATION TJclClrTableParamDefRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	Word FFlagMask;
	Word FSequence;
	unsigned FNameOffset;
	TJclClrTableMethodDefRow* FMethod;
	TJclClrParamKinds FFlags;
	WideString __fastcall GetName();
	
protected:
	void __fastcall SetMethod(const TJclClrTableMethodDefRow* AMethod);
	
public:
	__fastcall virtual TJclClrTableParamDefRow(const Jclclr::TJclClrTable* ATable);
	virtual AnsiString __fastcall DumpIL();
	/*         class method */ static Word __fastcall ParamFlags(TMetaClass* vmt, const TJclClrParamKinds AFlags)/* overload */;
	/*         class method */ static TJclClrParamKinds __fastcall ParamFlags(TMetaClass* vmt, const Word AFlags)/* overload */;
	__property Word FlagMask = {read=FFlagMask, nodefault};
	__property Word Sequence = {read=FSequence, nodefault};
	__property unsigned NameOffset = {read=FNameOffset, nodefault};
	__property WideString Name = {read=GetName};
	__property TJclClrTableMethodDefRow* Method = {read=FMethod};
	__property TJclClrParamKinds Flags = {read=FFlags, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableParamDefRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableParamDef;
class PASCALIMPLEMENTATION TJclClrTableParamDef : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableParamDefRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableParamDefRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableParamDef)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableParamDefRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableParamDef(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableParamDef(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableParamPtrRow;
class PASCALIMPLEMENTATION TJclClrTableParamPtrRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FParamIdx;
	TJclClrTableParamDefRow* __fastcall GetParam(void);
	
public:
	__fastcall virtual TJclClrTableParamPtrRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned ParamIdx = {read=FParamIdx, nodefault};
	__property TJclClrTableParamDefRow* Param = {read=GetParam};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableParamPtrRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableParamPtr;
class PASCALIMPLEMENTATION TJclClrTableParamPtr : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableParamPtrRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableParamPtrRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableParamPtr)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableParamPtrRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableParamPtr(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableParamPtr(void) { }
	#pragma option pop
	
};


#pragma pack(push,1)
struct IMAGE_COR_ILMETHOD_TINY
{
	
public:
	Byte Flags_CodeSize;
} ;
#pragma pack(pop)

typedef IMAGE_COR_ILMETHOD_TINY  TImageCorILMethodTiny;

typedef IMAGE_COR_ILMETHOD_TINY *PImageCorILMethodTiny;

#pragma pack(push,1)
struct IMAGE_COR_ILMETHOD_FAT
{
	
public:
	Word Flags_Size;
	Word MaxStack;
	unsigned CodeSize;
	unsigned LocalVarSigTok;
} ;
#pragma pack(pop)

typedef IMAGE_COR_ILMETHOD_FAT  TImageCorILMethodFat;

typedef IMAGE_COR_ILMETHOD_FAT *PImageCorILMethodFat;

#pragma pack(push,1)
struct TImageCorILMethodHeader
{
	
	union
	{
		struct 
		{
			IMAGE_COR_ILMETHOD_FAT Fat;
			
		};
		struct 
		{
			IMAGE_COR_ILMETHOD_TINY Tiny;
			
		};
		
	};
} ;
#pragma pack(pop)

typedef TImageCorILMethodHeader *PImageCorILMethodHeader;

#pragma pack(push,1)
struct IMAGE_COR_ILMETHOD_SECT_SMALL
{
	
public:
	Byte Kind;
	Byte Datasize;
	Word Padding;
} ;
#pragma pack(pop)

typedef IMAGE_COR_ILMETHOD_SECT_SMALL  TImageCorILMethodSectSmall;

typedef IMAGE_COR_ILMETHOD_SECT_SMALL *PImageCorILMethodSectSmall;

#pragma pack(push,1)
struct IMAGE_COR_ILMETHOD_SECT_FAT
{
	
public:
	unsigned Kind_DataSize;
} ;
#pragma pack(pop)

typedef IMAGE_COR_ILMETHOD_SECT_FAT  TImageCorILMethodSectFat;

typedef IMAGE_COR_ILMETHOD_SECT_FAT *PImageCorILMethodSectFat;

#pragma pack(push,1)
struct TImageCorILMethodSectHeader
{
	
	union
	{
		struct 
		{
			IMAGE_COR_ILMETHOD_SECT_FAT Fat;
			
		};
		struct 
		{
			IMAGE_COR_ILMETHOD_SECT_SMALL Small;
			
		};
		
	};
} ;
#pragma pack(pop)

typedef TImageCorILMethodSectHeader *PImageCorILMethodSectHeader;

#pragma pack(push,1)
struct IMAGE_COR_ILMETHOD_SECT_EH_CLAUSE_FAT
{
	
public:
	unsigned Flags;
	unsigned TryOffset;
	unsigned TryLength;
	unsigned HandlerOffset;
	unsigned HandlerLength;
	union
	{
		struct 
		{
			unsigned FilterOffset;
			
		};
		struct 
		{
			unsigned ClassToken;
			
		};
		
	};
} ;
#pragma pack(pop)

typedef IMAGE_COR_ILMETHOD_SECT_EH_CLAUSE_FAT  TImageCorILMethodSectEHClauseFat;

typedef IMAGE_COR_ILMETHOD_SECT_EH_CLAUSE_FAT *PImageCorILMethodSectEHClauseFat;

#pragma pack(push,1)
struct IMAGE_COR_ILMETHOD_SECT_EH_FAT
{
	
public:
	#pragma pack(push,1)
	IMAGE_COR_ILMETHOD_SECT_FAT SectFat;
	#pragma pack(pop)
	IMAGE_COR_ILMETHOD_SECT_EH_CLAUSE_FAT Clauses[65535];
} ;
#pragma pack(pop)

typedef IMAGE_COR_ILMETHOD_SECT_EH_FAT  TImageCorILMethodSectEHFat;

typedef IMAGE_COR_ILMETHOD_SECT_EH_FAT *PImageCorILMethodSectEHFat;

#pragma pack(push,1)
struct IMAGE_COR_ILMETHOD_SECT_EH_CLAUSE_SMALL
{
	
public:
	Word Flags;
	Word TryOffset;
	Byte TryLength;
	Word HandlerOffset;
	Byte HandlerLength;
	union
	{
		struct 
		{
			unsigned FilterOffset;
			
		};
		struct 
		{
			unsigned ClassToken;
			
		};
		
	};
} ;
#pragma pack(pop)

typedef IMAGE_COR_ILMETHOD_SECT_EH_CLAUSE_SMALL  TImageCorILMethodSectEHClauseSmall;

typedef IMAGE_COR_ILMETHOD_SECT_EH_CLAUSE_SMALL *PImageCorILMethodSectEHClauseSmall;

#pragma pack(push,1)
struct IMAGE_COR_ILMETHOD_SECT_EH_SMALL
{
	
public:
	#pragma pack(push,1)
	IMAGE_COR_ILMETHOD_SECT_SMALL SectSmall;
	#pragma pack(pop)
	IMAGE_COR_ILMETHOD_SECT_EH_CLAUSE_SMALL Clauses[65535];
} ;
#pragma pack(pop)

typedef IMAGE_COR_ILMETHOD_SECT_EH_SMALL  TImageCorILMethodSectEHSmall;

typedef IMAGE_COR_ILMETHOD_SECT_EH_SMALL *PImageCorILMethodSectEHSmall;

#pragma pack(push,1)
struct IMAGE_COR_ILMETHOD_SECT_EH
{
	
	union
	{
		struct 
		{
			IMAGE_COR_ILMETHOD_SECT_EH_FAT Fat;
			
		};
		struct 
		{
			IMAGE_COR_ILMETHOD_SECT_EH_SMALL Small;
			
		};
		
	};
} ;
#pragma pack(pop)

typedef IMAGE_COR_ILMETHOD_SECT_EH  TImageCorILMethodSectEH;

typedef IMAGE_COR_ILMETHOD_SECT_EH *PImageCorILMethodSectEH;

struct TJclClrCodeBlock
{
	
public:
	unsigned Offset;
	unsigned Length;
} ;

#pragma option push -b-
enum TJclClrExceptionClauseFlag { cfException, cfFilter, cfFinally, cfFault };
#pragma option pop

typedef Set<TJclClrExceptionClauseFlag, cfException, cfFault>  TJclClrExceptionClauseFlags;

class DELPHICLASS TJclClrExceptionHandler;
class PASCALIMPLEMENTATION TJclClrExceptionHandler : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	unsigned FFlags;
	unsigned FFilterOffset;
	TJclClrCodeBlock FTryBlock;
	TJclClrCodeBlock FHandlerBlock;
	unsigned FClassToken;
	TJclClrExceptionClauseFlags __fastcall GetFlags(void);
	
public:
	__fastcall TJclClrExceptionHandler(const IMAGE_COR_ILMETHOD_SECT_EH_CLAUSE_SMALL &EHClause)/* overload */;
	__fastcall TJclClrExceptionHandler(const IMAGE_COR_ILMETHOD_SECT_EH_CLAUSE_FAT &EHClause)/* overload */;
	__property unsigned EHFlags = {read=FFlags, nodefault};
	__property TJclClrExceptionClauseFlags Flags = {read=GetFlags, nodefault};
	__property TJclClrCodeBlock TryBlock = {read=FTryBlock};
	__property TJclClrCodeBlock HandlerBlock = {read=FHandlerBlock};
	__property unsigned ClassToken = {read=FClassToken, nodefault};
	__property unsigned FilterOffset = {read=FFilterOffset, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrExceptionHandler(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrSignature;
class PASCALIMPLEMENTATION TJclClrSignature : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Jclclr::TJclClrBlobRecord* FBlob;
	
protected:
	bool __fastcall IsModifierType(const TJclClrElementType AElementType);
	bool __fastcall IsPrimitiveType(const TJclClrElementType AElementType);
	System::PByte __fastcall Inc(Jclbase::PJclByteArray &DataPtr, unsigned Step = (unsigned)(0x1));
	int __fastcall UncompressedDataSize(Jclbase::PJclByteArray DataPtr);
	int __fastcall UncompressData(Jclbase::PJclByteArray DataPtr, /* out */ unsigned &Value);
	int __fastcall UncompressToken(Jclbase::PJclByteArray DataPtr, /* out */ unsigned &Token);
	Byte __fastcall UncompressCallingConv(Jclbase::PJclByteArray DataPtr);
	int __fastcall UncompressSignedInt(Jclbase::PJclByteArray DataPtr, /* out */ int &Value);
	TJclClrElementType __fastcall UncompressElementType(Jclbase::PJclByteArray DataPtr);
	AnsiString __fastcall UncompressTypeSignature(Jclbase::PJclByteArray DataPtr);
	
public:
	__fastcall TJclClrSignature(const Jclclr::TJclClrBlobRecord* ABlob);
	AnsiString __fastcall UncompressFieldSignature();
	unsigned __fastcall ReadValue(void);
	Byte __fastcall ReadByte(void);
	int __fastcall ReadInteger(void);
	unsigned __fastcall ReadToken(void);
	TJclClrElementType __fastcall ReadElementType(void);
	__property Jclclr::TJclClrBlobRecord* Blob = {read=FBlob};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrSignature(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TJclClrArrayData { adSize, adLowBound };
#pragma option pop

typedef int TJclClrArraySignBound[2];

typedef DynamicArray<int >  TJclClrArraySignBounds;

class DELPHICLASS TJclClrArraySign;
class PASCALIMPLEMENTATION TJclClrArraySign : public TJclClrSignature 
{
	typedef TJclClrSignature inherited;
	
private:
	DynamicArray<int >  FBounds;
	
public:
	__fastcall TJclClrArraySign(const Jclclr::TJclClrBlobRecord* ABlob);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrArraySign(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TJclClrLocalVarFlag { lvfPinned, lvfByRef };
#pragma option pop

typedef Set<TJclClrLocalVarFlag, lvfPinned, lvfByRef>  TJclClrLocalVarFlags;

class DELPHICLASS TJclClrLocalVar;
class PASCALIMPLEMENTATION TJclClrLocalVar : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TJclClrElementType FElementType;
	TJclClrLocalVarFlags FFlags;
	unsigned FToken;
	WideString __fastcall GetName();
	
public:
	__property TJclClrElementType ElementType = {read=FElementType, write=FElementType, nodefault};
	__property WideString Name = {read=GetName};
	__property TJclClrLocalVarFlags Flags = {read=FFlags, write=FFlags, nodefault};
	__property unsigned Token = {read=FToken, write=FToken, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclClrLocalVar(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrLocalVar(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrLocalVarSign;
class PASCALIMPLEMENTATION TJclClrLocalVarSign : public TJclClrSignature 
{
	typedef TJclClrSignature inherited;
	
private:
	Contnrs::TObjectList* FLocalVars;
	TJclClrLocalVar* __fastcall GetLocalVar(const int Idx);
	int __fastcall GetLocalVarCount(void);
	
public:
	__fastcall TJclClrLocalVarSign(const Jclclr::TJclClrBlobRecord* ABlob);
	__fastcall virtual ~TJclClrLocalVarSign(void);
	__property TJclClrLocalVar* LocalVars[int Idx] = {read=GetLocalVar};
	__property int LocalVarCount = {read=GetLocalVarCount, nodefault};
};


class DELPHICLASS TJclClrMethodBody;
class PASCALIMPLEMENTATION TJclClrMethodBody : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TJclClrTableMethodDefRow* FMethod;
	unsigned FSize;
	void *FCode;
	unsigned FMaxStack;
	unsigned FLocalVarSignToken;
	TJclClrLocalVarSign* FLocalVarSign;
	Contnrs::TObjectList* FEHTable;
	void __fastcall AddEHTable(PImageCorILMethodSectEH EHTable);
	void __fastcall AddOptILTable(void * OptILTable, int Size);
	void __fastcall ParseMoreSections(PImageCorILMethodSectHeader SectHeader);
	TJclClrExceptionHandler* __fastcall GetExceptionHandler(const int Idx);
	int __fastcall GetExceptionHandlerCount(void);
	TJclClrLocalVarSign* __fastcall GetLocalVarSign(void);
	Jclclr::TJclClrBlobRecord* __fastcall GetLocalVarSignData(void);
	
public:
	__fastcall TJclClrMethodBody(const TJclClrTableMethodDefRow* AMethod);
	__fastcall virtual ~TJclClrMethodBody(void);
	__property TJclClrTableMethodDefRow* Method = {read=FMethod};
	__property unsigned Size = {read=FSize, nodefault};
	__property void * Code = {read=FCode};
	__property unsigned MaxStack = {read=FMaxStack, nodefault};
	__property unsigned LocalVarSignToken = {read=FLocalVarSignToken, nodefault};
	__property Jclclr::TJclClrBlobRecord* LocalVarSignData = {read=GetLocalVarSignData};
	__property TJclClrLocalVarSign* LocalVarSign = {read=GetLocalVarSign};
	__property TJclClrExceptionHandler* ExceptionHandlers[int Idx] = {read=GetExceptionHandler};
	__property int ExceptionHandlerCount = {read=GetExceptionHandlerCount, nodefault};
};


class DELPHICLASS TJclClrCustomModifierSign;
class PASCALIMPLEMENTATION TJclClrCustomModifierSign : public TJclClrSignature 
{
	typedef TJclClrSignature inherited;
	
private:
	bool FRequired;
	unsigned FToken;
	
public:
	__fastcall TJclClrCustomModifierSign(const Jclclr::TJclClrBlobRecord* ABlob);
	__property bool Required = {read=FRequired, nodefault};
	__property unsigned Token = {read=FToken, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrCustomModifierSign(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrMethodParam;
class DELPHICLASS TJclClrMethodSign;
#pragma option push -b-
enum TJclClrMethodSignFlag { mfHasThis, mfExplicitThis, mfDefault, mfVarArg };
#pragma option pop

typedef Set<TJclClrMethodSignFlag, mfHasThis, mfVarArg>  TJclClrMethodSignFlags;

class DELPHICLASS TJclClrMethodRetType;
class PASCALIMPLEMENTATION TJclClrMethodParam : public TJclClrSignature 
{
	typedef TJclClrSignature inherited;
	
private:
	Contnrs::TObjectList* FCustomMods;
	bool FByRef;
	TJclClrElementType FElementType;
	unsigned FToken;
	TJclClrMethodSign* FMethodSign;
	TJclClrArraySign* FArraySign;
	TJclClrCustomModifierSign* __fastcall GetCustomModifier(const int Idx);
	int __fastcall GetCustomModifierCount(void);
	
public:
	__fastcall TJclClrMethodParam(const Jclclr::TJclClrBlobRecord* ABlob);
	__fastcall virtual ~TJclClrMethodParam(void);
	__property TJclClrCustomModifierSign* CustomModifiers[int Idx] = {read=GetCustomModifier};
	__property int CustomModifierCount = {read=GetCustomModifierCount, nodefault};
	__property TJclClrElementType ElementType = {read=FElementType, nodefault};
	__property bool ByRef = {read=FByRef, nodefault};
	__property unsigned Token = {read=FToken, nodefault};
	__property TJclClrMethodSign* MethodSign = {read=FMethodSign};
	__property TJclClrArraySign* ArraySign = {read=FArraySign};
};


class PASCALIMPLEMENTATION TJclClrMethodRetType : public TJclClrMethodParam 
{
	typedef TJclClrMethodParam inherited;
	
public:
	#pragma option push -w-inl
	/* TJclClrMethodParam.Create */ inline __fastcall TJclClrMethodRetType(const Jclclr::TJclClrBlobRecord* ABlob) : TJclClrMethodParam(ABlob) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrMethodParam.Destroy */ inline __fastcall virtual ~TJclClrMethodRetType(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TJclClrMethodSign : public TJclClrSignature 
{
	typedef TJclClrSignature inherited;
	
private:
	TJclClrMethodSignFlags FFlags;
	Contnrs::TObjectList* FParams;
	TJclClrMethodRetType* FRetType;
	TJclClrMethodParam* __fastcall GetParam(const int Idx);
	int __fastcall GetParamCount(void);
	
public:
	__fastcall TJclClrMethodSign(const Jclclr::TJclClrBlobRecord* ABlob);
	__fastcall virtual ~TJclClrMethodSign(void);
	__property TJclClrMethodSignFlags Flags = {read=FFlags, nodefault};
	__property TJclClrMethodParam* Params[int Idx] = {read=GetParam};
	__property int ParamCount = {read=GetParamCount, nodefault};
	__property TJclClrMethodRetType* RetType = {read=FRetType};
};



#pragma option push -b-
enum TJclClrMemberAccess { maCompilercontrolled, maPrivate, maFamilyAndAssembly, maAssembly, maFamily, maFamilyOrAssembly, maPublic };
#pragma option pop

#pragma option push -b-
enum TJclClrMethodFlag { mfStatic, mfFinal, mfVirtual, mfHideBySig, mfCheckAccessOnOverride, mfAbstract, mfSpecialName, mfPInvokeImpl, mfUnmanagedExport, mfRTSpcialName, mfHasSecurity, mfRequireSecObject };
#pragma option pop

typedef Set<TJclClrMethodFlag, mfStatic, mfRequireSecObject>  TJclClrMethodFlags;

#pragma option push -b-
enum TJclClrMethodCodeType { ctIL, ctNative, ctOptIL, ctRuntime };
#pragma option pop

#pragma option push -b-
enum TJclClrMethodImplFlag { mifForwardRef, mifPreserveSig, mifInternalCall, mifSynchronized, mifNoInlining };
#pragma option pop

typedef Set<TJclClrMethodImplFlag, mifForwardRef, mifNoInlining>  TJclClrMethodImplFlags;

class PASCALIMPLEMENTATION TJclClrTableMethodDefRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FRVA;
	Word FImplFlags;
	Word FFlags;
	unsigned FNameOffset;
	unsigned FSignatureOffset;
	unsigned FParamListIdx;
	TJclClrTableTypeDefRow* FParentToken;
	Classes::TList* FParams;
	TJclClrMethodBody* FMethodBody;
	TJclClrMethodSign* FSignature;
	WideString __fastcall GetName();
	Jclclr::TJclClrBlobRecord* __fastcall GetSignatureData(void);
	TJclClrTableParamDefRow* __fastcall GetParam(const int Idx);
	int __fastcall GetParamCount(void);
	bool __fastcall GetHasParam(void);
	void __fastcall UpdateParams(void);
	WideString __fastcall GetFullName();
	TJclClrMethodSign* __fastcall GetSignature(void);
	TJclClrMemberAccess __fastcall GetMemberAccess(void);
	TJclClrMethodFlags __fastcall GetMethodFlags(void);
	bool __fastcall GetNewSlot(void);
	TJclClrMethodCodeType __fastcall GetCodeType(void);
	bool __fastcall GetManaged(void);
	TJclClrMethodImplFlags __fastcall GetMethodImplFlags(void);
	
protected:
	virtual void __fastcall Update(void);
	void __fastcall SetParentToken(const TJclClrTableTypeDefRow* ARow);
	
public:
	__fastcall virtual TJclClrTableMethodDefRow(const Jclclr::TJclClrTable* ATable);
	virtual AnsiString __fastcall DumpIL();
	__fastcall virtual ~TJclClrTableMethodDefRow(void);
	__property unsigned RVA = {read=FRVA, nodefault};
	__property Word ImplFlags = {read=FImplFlags, nodefault};
	__property Word Flags = {read=FFlags, nodefault};
	__property unsigned NameOffset = {read=FNameOffset, nodefault};
	__property unsigned SignatureOffset = {read=FSignatureOffset, nodefault};
	__property unsigned ParamListIdx = {read=FParamListIdx, nodefault};
	__property WideString Name = {read=GetName};
	__property WideString FullName = {read=GetFullName};
	__property TJclClrMethodFlags MethodFlags = {read=GetMethodFlags, nodefault};
	__property TJclClrMethodImplFlags MethodImplFlags = {read=GetMethodImplFlags, nodefault};
	__property TJclClrMemberAccess MemberAccess = {read=GetMemberAccess, nodefault};
	__property bool NewSlot = {read=GetNewSlot, nodefault};
	__property TJclClrMethodCodeType CodeType = {read=GetCodeType, nodefault};
	__property bool Managed = {read=GetManaged, nodefault};
	__property TJclClrMethodSign* Signature = {read=GetSignature};
	__property Jclclr::TJclClrBlobRecord* SignatureData = {read=GetSignatureData};
	__property TJclClrTableTypeDefRow* ParentToken = {read=FParentToken};
	__property bool HasParam = {read=GetHasParam, nodefault};
	__property TJclClrTableParamDefRow* Params[int Idx] = {read=GetParam};
	__property int ParamCount = {read=GetParamCount, nodefault};
	__property TJclClrMethodBody* MethodBody = {read=FMethodBody};
};


class DELPHICLASS TJclClrTableMethodDef;
class PASCALIMPLEMENTATION TJclClrTableMethodDef : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableMethodDefRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableMethodDefRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableMethodDef)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableMethodDefRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableMethodDef(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableMethodDef(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableMethodPtrRow;
class PASCALIMPLEMENTATION TJclClrTableMethodPtrRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FMethodIdx;
	TJclClrTableMethodDefRow* __fastcall GetMethod(void);
	
public:
	__fastcall virtual TJclClrTableMethodPtrRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned MethodIdx = {read=FMethodIdx, nodefault};
	__property TJclClrTableMethodDefRow* Method = {read=GetMethod};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableMethodPtrRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableMethodPtr;
class PASCALIMPLEMENTATION TJclClrTableMethodPtr : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableMethodPtrRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableMethodPtrRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableMethodPtr)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableMethodPtrRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableMethodPtr(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableMethodPtr(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableMethodImplRow;
class PASCALIMPLEMENTATION TJclClrTableMethodImplRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FClassIdx;
	unsigned FMethodBodyIdx;
	unsigned FMethodDeclarationIdx;
	
public:
	__fastcall virtual TJclClrTableMethodImplRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned ClassIdx = {read=FClassIdx, nodefault};
	__property unsigned MethodBodyIdx = {read=FMethodBodyIdx, nodefault};
	__property unsigned MethodDeclarationIdx = {read=FMethodDeclarationIdx, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableMethodImplRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableMethodImpl;
class PASCALIMPLEMENTATION TJclClrTableMethodImpl : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableMethodImplRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableMethodImplRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableMethodImpl)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableMethodImplRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableMethodImpl(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableMethodImpl(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableMethodSemanticsRow;
class PASCALIMPLEMENTATION TJclClrTableMethodSemanticsRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	Word FSemantics;
	unsigned FMethodIdx;
	unsigned FAssociationIdx;
	
public:
	__fastcall virtual TJclClrTableMethodSemanticsRow(const Jclclr::TJclClrTable* ATable);
	__property Word Semantics = {read=FSemantics, nodefault};
	__property unsigned MethodIdx = {read=FMethodIdx, nodefault};
	__property unsigned AssociationIdx = {read=FAssociationIdx, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableMethodSemanticsRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableMethodSemantics;
class PASCALIMPLEMENTATION TJclClrTableMethodSemantics : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableMethodSemanticsRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableMethodSemanticsRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableMethodSemantics)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableMethodSemanticsRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableMethodSemantics(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableMethodSemantics(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableMethodSpecRow;
class PASCALIMPLEMENTATION TJclClrTableMethodSpecRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FMethodIdx;
	unsigned FInstantiationOffset;
	Jclclr::TJclClrBlobRecord* __fastcall GetInstantiation(void);
	Jclclr::TJclClrTableRow* __fastcall GetMethod(void);
	
public:
	__fastcall virtual TJclClrTableMethodSpecRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned MethodIdx = {read=FMethodIdx, nodefault};
	__property unsigned InstantiationOffset = {read=FInstantiationOffset, nodefault};
	__property Jclclr::TJclClrTableRow* Method = {read=GetMethod};
	__property Jclclr::TJclClrBlobRecord* Instantiation = {read=GetInstantiation};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableMethodSpecRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableMethodSpec;
class PASCALIMPLEMENTATION TJclClrTableMethodSpec : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableMethodSpecRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableMethodSpecRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableMethodSpec)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableMethodSpecRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableMethodSpec(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableMethodSpec(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableNestedClassRow;
class PASCALIMPLEMENTATION TJclClrTableNestedClassRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FEnclosingClassIdx;
	unsigned FNestedClassIdx;
	
public:
	__fastcall virtual TJclClrTableNestedClassRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned NestedClassIdx = {read=FNestedClassIdx, nodefault};
	__property unsigned EnclosingClassIdx = {read=FEnclosingClassIdx, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableNestedClassRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableNestedClass;
class PASCALIMPLEMENTATION TJclClrTableNestedClass : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableNestedClassRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableNestedClassRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableNestedClass)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableNestedClassRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableNestedClass(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableNestedClass(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TJclClrTablePropertyFlag { pfSpecialName, pfRTSpecialName, pfHasDefault };
#pragma option pop

typedef Set<TJclClrTablePropertyFlag, pfSpecialName, pfHasDefault>  TJclClrTablePropertyFlags;

class DELPHICLASS TJclClrTablePropertyDefRow;
class PASCALIMPLEMENTATION TJclClrTablePropertyDefRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FKindIdx;
	unsigned FNameOffset;
	Word FFlags;
	WideString __fastcall GetName();
	TJclClrTablePropertyFlags __fastcall GetFlags(void);
	
public:
	__fastcall virtual TJclClrTablePropertyDefRow(const Jclclr::TJclClrTable* ATable);
	virtual AnsiString __fastcall DumpIL();
	__property Word RawFlags = {read=FFlags, nodefault};
	__property unsigned NameOffset = {read=FNameOffset, nodefault};
	__property unsigned KindIdx = {read=FKindIdx, nodefault};
	__property WideString Name = {read=GetName};
	__property TJclClrTablePropertyFlags Flags = {read=GetFlags, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTablePropertyDefRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTablePropertyDef;
class PASCALIMPLEMENTATION TJclClrTablePropertyDef : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTablePropertyDefRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTablePropertyDefRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTablePropertyDef)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTablePropertyDefRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTablePropertyDef(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTablePropertyDef(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTablePropertyPtrRow;
class PASCALIMPLEMENTATION TJclClrTablePropertyPtrRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FPropertyIdx;
	TJclClrTablePropertyDefRow* __fastcall GetProperty(void);
	
public:
	__fastcall virtual TJclClrTablePropertyPtrRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned PropertyIdx = {read=FPropertyIdx, nodefault};
	__property TJclClrTablePropertyDefRow* _Property = {read=GetProperty};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTablePropertyPtrRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTablePropertyPtr;
class PASCALIMPLEMENTATION TJclClrTablePropertyPtr : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTablePropertyPtrRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTablePropertyPtrRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTablePropertyPtr)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTablePropertyPtrRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTablePropertyPtr(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTablePropertyPtr(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTablePropertyMapRow;
class PASCALIMPLEMENTATION TJclClrTablePropertyMapRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FParentIdx;
	unsigned FPropertyListIdx;
	Classes::TList* FProperties;
	TJclClrTableTypeDefRow* __fastcall GetParent(void);
	TJclClrTablePropertyDefRow* __fastcall GetProperty(const int Idx);
	int __fastcall GetPropertyCount(void);
	
protected:
	int __fastcall Add(const TJclClrTablePropertyDefRow* ARow);
	
public:
	__fastcall virtual TJclClrTablePropertyMapRow(const Jclclr::TJclClrTable* ATable);
	__fastcall virtual ~TJclClrTablePropertyMapRow(void);
	__property unsigned ParentIdx = {read=FParentIdx, nodefault};
	__property unsigned PropertyListIdx = {read=FPropertyListIdx, nodefault};
	__property TJclClrTableTypeDefRow* Parent = {read=GetParent};
	__property TJclClrTablePropertyDefRow* Properties[int Idx] = {read=GetProperty};
	__property int PropertyCount = {read=GetPropertyCount, nodefault};
};


class DELPHICLASS TJclClrTablePropertyMap;
class PASCALIMPLEMENTATION TJclClrTablePropertyMap : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTablePropertyMapRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTablePropertyMapRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTablePropertyMap)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	virtual void __fastcall Update(void);
	
public:
	__property TJclClrTablePropertyMapRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTablePropertyMap(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTablePropertyMap(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableStandAloneSigRow;
class PASCALIMPLEMENTATION TJclClrTableStandAloneSigRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FSignatureOffset;
	Jclclr::TJclClrBlobRecord* __fastcall GetSignature(void);
	
public:
	__fastcall virtual TJclClrTableStandAloneSigRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned SignatureOffset = {read=FSignatureOffset, nodefault};
	__property Jclclr::TJclClrBlobRecord* Signature = {read=GetSignature};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableStandAloneSigRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableStandAloneSig;
class PASCALIMPLEMENTATION TJclClrTableStandAloneSig : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableStandAloneSigRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableStandAloneSigRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableStandAloneSig)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableStandAloneSigRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableStandAloneSig(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableStandAloneSig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableTypeDef;
class PASCALIMPLEMENTATION TJclClrTableTypeDef : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableTypeDefRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableTypeDefRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableTypeDef)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableTypeDefRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableTypeDef(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableTypeDef(void) { }
	#pragma option pop
	
private:
	void *__ITableCanDumpIL;	/* Jclclr::ITableCanDumpIL */
	
public:
	operator ITableCanDumpIL*(void) { return (ITableCanDumpIL*)&__ITableCanDumpIL; }
	
};


class DELPHICLASS TJclClrTableTypeRefRow;
class PASCALIMPLEMENTATION TJclClrTableTypeRefRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FResolutionScopeIdx;
	unsigned FNamespaceOffset;
	unsigned FNameOffset;
	WideString __fastcall GetName();
	WideString __fastcall GetNamespace();
	Jclclr::TJclClrTableRow* __fastcall GetResolutionScope(void);
	AnsiString __fastcall GetResolutionScopeName();
	WideString __fastcall GetFullName();
	
public:
	__fastcall virtual TJclClrTableTypeRefRow(const Jclclr::TJclClrTable* ATable);
	virtual AnsiString __fastcall DumpIL();
	__property unsigned ResolutionScopeIdx = {read=FResolutionScopeIdx, nodefault};
	__property unsigned NameOffset = {read=FNameOffset, nodefault};
	__property unsigned NamespaceOffset = {read=FNamespaceOffset, nodefault};
	__property Jclclr::TJclClrTableRow* ResolutionScope = {read=GetResolutionScope};
	__property AnsiString ResolutionScopeName = {read=GetResolutionScopeName};
	__property WideString Name = {read=GetName};
	__property WideString Namespace = {read=GetNamespace};
	__property WideString FullName = {read=GetFullName};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableTypeRefRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableTypeRef;
class PASCALIMPLEMENTATION TJclClrTableTypeRef : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableTypeRefRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableTypeRefRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableTypeRef)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableTypeRefRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableTypeRef(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableTypeRef(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableTypeSpecRow;
class PASCALIMPLEMENTATION TJclClrTableTypeSpecRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FSignatureOffset;
	Jclclr::TJclClrBlobRecord* __fastcall GetSignature(void);
	
public:
	__fastcall virtual TJclClrTableTypeSpecRow(const Jclclr::TJclClrTable* ATable);
	__property unsigned SignatureOffset = {read=FSignatureOffset, nodefault};
	__property Jclclr::TJclClrBlobRecord* Signature = {read=GetSignature};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableTypeSpecRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableTypeSpec;
class PASCALIMPLEMENTATION TJclClrTableTypeSpec : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableTypeSpecRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableTypeSpecRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableTypeSpec)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableTypeSpecRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableTypeSpec(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableTypeSpec(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableENCMapRow;
class PASCALIMPLEMENTATION TJclClrTableENCMapRow : public Jclclr::TJclClrTableRow 
{
	typedef Jclclr::TJclClrTableRow inherited;
	
private:
	unsigned FToken;
	unsigned FFuncCode;
	
protected:
	__property unsigned FuncCode = {read=FFuncCode, nodefault};
	
public:
	__fastcall virtual TJclClrTableENCMapRow(const Jclclr::TJclClrTable* ATable);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableENCMapRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableENCMap;
class PASCALIMPLEMENTATION TJclClrTableENCMap : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableENCMapRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableENCMapRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableENCMap)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableENCMapRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableENCMap(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableENCMap(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableENCLogRow;
class PASCALIMPLEMENTATION TJclClrTableENCLogRow : public TJclClrTableENCMapRow 
{
	typedef TJclClrTableENCMapRow inherited;
	
private:
	unsigned FFuncCode;
	
protected:
	__property unsigned FuncCode = {read=FFuncCode, nodefault};
	
public:
	__fastcall virtual TJclClrTableENCLogRow(const Jclclr::TJclClrTable* ATable);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClrTableENCLogRow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclClrTableENCLog;
class PASCALIMPLEMENTATION TJclClrTableENCLog : public Jclclr::TJclClrTable 
{
	typedef Jclclr::TJclClrTable inherited;
	
public:
	TJclClrTableENCLogRow* operator[](int Idx) { return Rows[Idx]; }
	
private:
	HIDESBASE TJclClrTableENCLogRow* __fastcall GetRow(const int Idx);
	
protected:
	#pragma option push -w-inl
	/* virtual class method */ virtual TMetaClass* __fastcall TableRowClass() { return TableRowClass(__classid(TJclClrTableENCLog)); }
	#pragma option pop
	/*         class method */ static TMetaClass* __fastcall TableRowClass(TMetaClass* vmt);
	
public:
	__property TJclClrTableENCLogRow* Rows[int Idx] = {read=GetRow/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclClrTable.Create */ inline __fastcall virtual TJclClrTableENCLog(const Jclclr::TJclClrTableStream* AStream, const void * Ptr, const int ARowCount) : Jclclr::TJclClrTable(AStream, Ptr, ARowCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclClrTable.Destroy */ inline __fastcall virtual ~TJclClrTableENCLog(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclMetadataError;
class PASCALIMPLEMENTATION EJclMetadataError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclMetadataError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclMetadataError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclMetadataError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclMetadataError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclMetadataError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclMetadataError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclMetadataError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclMetadataError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclMetadataError(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jclmetadata */
using namespace Jclmetadata;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclmetadata
