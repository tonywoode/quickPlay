// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcldebugserialization.pas' rev: 10.00

#ifndef JcldebugserializationHPP
#define JcldebugserializationHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Jcldebug.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jcldebugserialization
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TJclCustomSimpleSerializer;
class PASCALIMPLEMENTATION TJclCustomSimpleSerializer : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TJclCustomSimpleSerializer* operator[](int AIndex) { return Items[AIndex]; }
	
protected:
	Contnrs::TObjectList* FItems;
	AnsiString FName;
	Classes::TStringList* FValues;
	int __fastcall GetCount(void);
	TJclCustomSimpleSerializer* __fastcall GetItems(int AIndex);
	
public:
	__fastcall TJclCustomSimpleSerializer(const AnsiString AName);
	__fastcall virtual ~TJclCustomSimpleSerializer(void);
	TJclCustomSimpleSerializer* __fastcall AddChild(System::TObject* ASender, const AnsiString AName);
	void __fastcall Clear(void);
	AnsiString __fastcall ReadString(System::TObject* ASender, const AnsiString AName);
	void __fastcall WriteString(System::TObject* ASender, const AnsiString AName, const AnsiString AValue);
	__property int Count = {read=GetCount, nodefault};
	__property TJclCustomSimpleSerializer* Items[int AIndex] = {read=GetItems/*, default*/};
	__property AnsiString Name = {read=FName};
	__property Classes::TStringList* Values = {read=FValues};
};


class DELPHICLASS TJclSerializableLocationInfo;
class PASCALIMPLEMENTATION TJclSerializableLocationInfo : public Jcldebug::TJclLocationInfoEx 
{
	typedef Jcldebug::TJclLocationInfoEx inherited;
	
public:
	void __fastcall Deserialize(TJclCustomSimpleSerializer* ASerializer);
	void __fastcall Serialize(TJclCustomSimpleSerializer* ASerializer);
public:
	#pragma option push -w-inl
	/* TJclLocationInfoEx.Create */ inline __fastcall TJclSerializableLocationInfo(Jcldebug::TJclCustomLocationInfoList* AParent, void * Address) : Jcldebug::TJclLocationInfoEx(AParent, Address) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TJclSerializableLocationInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclSerializableLocationInfoList;
class PASCALIMPLEMENTATION TJclSerializableLocationInfoList : public Jcldebug::TJclCustomLocationInfoList 
{
	typedef Jcldebug::TJclCustomLocationInfoList inherited;
	
public:
	TJclSerializableLocationInfo* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	TJclSerializableLocationInfo* __fastcall GetItems(int AIndex);
	
public:
	__fastcall virtual TJclSerializableLocationInfoList(void);
	TJclSerializableLocationInfo* __fastcall Add(void * Addr);
	void __fastcall Deserialize(TJclCustomSimpleSerializer* ASerializer);
	void __fastcall Serialize(TJclCustomSimpleSerializer* ASerializer);
	__property TJclSerializableLocationInfo* Items[int AIndex] = {read=GetItems/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclCustomLocationInfoList.Destroy */ inline __fastcall virtual ~TJclSerializableLocationInfoList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclSerializableThreadInfo;
class PASCALIMPLEMENTATION TJclSerializableThreadInfo : public Jcldebug::TJclCustomThreadInfo 
{
	typedef Jcldebug::TJclCustomThreadInfo inherited;
	
private:
	TJclSerializableLocationInfoList* __fastcall GetStack(const int AIndex);
	
protected:
	virtual TMetaClass* __fastcall GetStackClass(void);
	
public:
	__fastcall TJclSerializableThreadInfo(void);
	__fastcall virtual ~TJclSerializableThreadInfo(void);
	void __fastcall Deserialize(TJclCustomSimpleSerializer* ASerializer);
	void __fastcall Serialize(TJclCustomSimpleSerializer* ASerializer);
	__property TJclSerializableLocationInfoList* CreationStack = {read=GetStack, index=1};
	__property TJclSerializableLocationInfoList* Stack = {read=GetStack, index=2};
};


class DELPHICLASS TJclSerializableThreadInfoList;
class PASCALIMPLEMENTATION TJclSerializableThreadInfoList : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
public:
	TJclSerializableThreadInfo* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	Contnrs::TObjectList* FItems;
	TJclSerializableThreadInfo* __fastcall GetItems(int AIndex);
	int __fastcall GetCount(void);
	
public:
	__fastcall TJclSerializableThreadInfoList(void);
	__fastcall virtual ~TJclSerializableThreadInfoList(void);
	TJclSerializableThreadInfo* __fastcall Add(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Clear(void);
	void __fastcall Deserialize(TJclCustomSimpleSerializer* ASerializer);
	void __fastcall Serialize(TJclCustomSimpleSerializer* ASerializer);
	__property int Count = {read=GetCount, nodefault};
	__property TJclSerializableThreadInfo* Items[int AIndex] = {read=GetItems/*, default*/};
};


class DELPHICLASS TJclSerializableException;
class PASCALIMPLEMENTATION TJclSerializableException : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	AnsiString FExceptionClassName;
	AnsiString FExceptionMessage;
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	void __fastcall Clear(void);
	void __fastcall Deserialize(TJclCustomSimpleSerializer* ASerializer);
	void __fastcall Serialize(TJclCustomSimpleSerializer* ASerializer);
	__property AnsiString ExceptionClassName = {read=FExceptionClassName, write=FExceptionClassName};
	__property AnsiString ExceptionMessage = {read=FExceptionMessage, write=FExceptionMessage};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TJclSerializableException(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclSerializableException(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


class DELPHICLASS TJclSerializableModuleInfo;
class PASCALIMPLEMENTATION TJclSerializableModuleInfo : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	AnsiString FStartStr;
	AnsiString FEndStr;
	AnsiString FSystemModuleStr;
	AnsiString FModuleName;
	AnsiString FBinFileVersion;
	AnsiString FFileVersion;
	AnsiString FFileDescription;
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	void __fastcall Deserialize(TJclCustomSimpleSerializer* ASerializer);
	void __fastcall Serialize(TJclCustomSimpleSerializer* ASerializer);
	__property AnsiString StartStr = {read=FStartStr, write=FStartStr};
	__property AnsiString EndStr = {read=FEndStr, write=FEndStr};
	__property AnsiString SystemModuleStr = {read=FSystemModuleStr, write=FSystemModuleStr};
	__property AnsiString ModuleName = {read=FModuleName, write=FModuleName};
	__property AnsiString BinFileVersion = {read=FBinFileVersion, write=FBinFileVersion};
	__property AnsiString FileVersion = {read=FFileVersion, write=FFileVersion};
	__property AnsiString FileDescription = {read=FFileDescription, write=FFileDescription};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TJclSerializableModuleInfo(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclSerializableModuleInfo(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


class DELPHICLASS TJclSerializableModuleInfoList;
class PASCALIMPLEMENTATION TJclSerializableModuleInfoList : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
public:
	TJclSerializableModuleInfo* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	Contnrs::TObjectList* FItems;
	int __fastcall GetCount(void);
	TJclSerializableModuleInfo* __fastcall GetItems(int AIndex);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	__fastcall TJclSerializableModuleInfoList(void);
	__fastcall virtual ~TJclSerializableModuleInfoList(void);
	TJclSerializableModuleInfo* __fastcall Add(void);
	void __fastcall Clear(void);
	void __fastcall Deserialize(TJclCustomSimpleSerializer* ASerializer);
	void __fastcall Serialize(TJclCustomSimpleSerializer* ASerializer);
	__property int Count = {read=GetCount, nodefault};
	__property TJclSerializableModuleInfo* Items[int AIndex] = {read=GetItems/*, default*/};
};


class DELPHICLASS TJclSerializableExceptionInfo;
class PASCALIMPLEMENTATION TJclSerializableExceptionInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TJclSerializableException* FException;
	TJclSerializableThreadInfoList* FThreadInfoList;
	TJclSerializableModuleInfoList* FModules;
	
public:
	__fastcall TJclSerializableExceptionInfo(void);
	__fastcall virtual ~TJclSerializableExceptionInfo(void);
	void __fastcall Deserialize(TJclCustomSimpleSerializer* ASerializer);
	void __fastcall Serialize(TJclCustomSimpleSerializer* ASerializer);
	__property TJclSerializableThreadInfoList* ThreadInfoList = {read=FThreadInfoList};
	__property TJclSerializableException* Exception = {read=FException};
	__property TJclSerializableModuleInfoList* Modules = {read=FModules};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jcldebugserialization */
using namespace Jcldebugserialization;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcldebugserialization
