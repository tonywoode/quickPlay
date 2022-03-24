// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclrtti.pas' rev: 10.00

#ifndef JclrttiHPP
#define JclrttiHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Typinfo.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclrtti
{
//-- type declarations -------------------------------------------------------
__interface IJclInfoWriter;
typedef System::DelphiInterface<IJclInfoWriter> _di_IJclInfoWriter;
__interface  INTERFACE_UUID("{7DAD522D-46EA-11D5-B0C0-4854E825F345}") IJclInfoWriter  : public IInterface 
{
	
public:
	virtual int __fastcall GetWrap(void) = 0 ;
	virtual void __fastcall SetWrap(const int Value) = 0 ;
	virtual void __fastcall Write(const AnsiString S) = 0 ;
	virtual void __fastcall Writeln(const AnsiString S = "") = 0 ;
	virtual void __fastcall Indent(void) = 0 ;
	virtual void __fastcall Outdent(void) = 0 ;
	__property int Wrap = {read=GetWrap, write=SetWrap};
};

class DELPHICLASS TJclInfoWriter;
class PASCALIMPLEMENTATION TJclInfoWriter : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	AnsiString FCurLine;
	int FIndentLevel;
	int FWrap;
	
protected:
	void __fastcall DoWrap(void);
	void __fastcall DoWriteCompleteLines(void);
	virtual void __fastcall PrimWrite(const AnsiString S) = 0 ;
	__property AnsiString CurLine = {read=FCurLine, write=FCurLine};
	__property int IndentLevel = {read=FIndentLevel, write=FIndentLevel, nodefault};
	
public:
	__fastcall TJclInfoWriter(const int AWrap);
	__fastcall virtual ~TJclInfoWriter(void);
	int __fastcall GetWrap(void);
	void __fastcall SetWrap(const int Value);
	void __fastcall Write(const AnsiString S);
	void __fastcall Writeln(const AnsiString S = "");
	void __fastcall Indent(void);
	void __fastcall Outdent(void);
	__property int Wrap = {read=GetWrap, write=SetWrap, nodefault};
private:
	void *__IJclInfoWriter;	/* Jclrtti::IJclInfoWriter */
	
public:
	operator IJclInfoWriter*(void) { return (IJclInfoWriter*)&__IJclInfoWriter; }
	
};


class DELPHICLASS TJclInfoStringsWriter;
class PASCALIMPLEMENTATION TJclInfoStringsWriter : public TJclInfoWriter 
{
	typedef TJclInfoWriter inherited;
	
private:
	Classes::TStrings* FStrings;
	
protected:
	virtual void __fastcall PrimWrite(const AnsiString S);
	
public:
	__fastcall TJclInfoStringsWriter(const Classes::TStrings* AStrings, const int AWrap);
	__property Classes::TStrings* Strings = {read=FStrings};
public:
	#pragma option push -w-inl
	/* TJclInfoWriter.Destroy */ inline __fastcall virtual ~TJclInfoStringsWriter(void) { }
	#pragma option pop
	
};


__interface IJclBaseInfo;
typedef System::DelphiInterface<IJclBaseInfo> _di_IJclBaseInfo;
__interface IJclBaseInfo  : public IInterface 
{
	
public:
	virtual void __fastcall WriteTo(const _di_IJclInfoWriter Dest) = 0 ;
	virtual void __fastcall DeclarationTo(const _di_IJclInfoWriter Dest) = 0 ;
};

__interface IJclTypeInfo;
typedef System::DelphiInterface<IJclTypeInfo> _di_IJclTypeInfo;
__interface  INTERFACE_UUID("{7DAD5220-46EA-11D5-B0C0-4854E825F345}") IJclTypeInfo  : public IJclBaseInfo 
{
	
public:
	virtual AnsiString __fastcall GetName(void) = 0 ;
	virtual Typinfo::PTypeData __fastcall GetTypeData(void) = 0 ;
	virtual Typinfo::PTypeInfo __fastcall GetTypeInfo(void) = 0 ;
	virtual Typinfo::TTypeKind __fastcall GetTypeKind(void) = 0 ;
	__property AnsiString Name = {read=GetName};
	__property Typinfo::PTypeData TypeData = {read=GetTypeData};
	__property Typinfo::PTypeInfo TypeInfo = {read=GetTypeInfo};
	__property Typinfo::TTypeKind TypeKind = {read=GetTypeKind};
};

class DELPHICLASS TJclTypeInfo;
class PASCALIMPLEMENTATION TJclTypeInfo : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Typinfo::TTypeData *FTypeData;
	Typinfo::TTypeInfo *FTypeInfo;
	
protected:
	virtual void __fastcall WriteTo(const _di_IJclInfoWriter Dest);
	virtual void __fastcall DeclarationTo(const _di_IJclInfoWriter Dest);
	
public:
	__fastcall TJclTypeInfo(Typinfo::PTypeInfo ATypeInfo);
	AnsiString __fastcall GetName();
	Typinfo::PTypeData __fastcall GetTypeData(void);
	Typinfo::PTypeInfo __fastcall GetTypeInfo(void);
	Typinfo::TTypeKind __fastcall GetTypeKind(void);
	__property AnsiString Name = {read=GetName};
	__property Typinfo::PTypeData TypeData = {read=GetTypeData};
	__property Typinfo::PTypeInfo TypeInfo = {read=GetTypeInfo};
	__property Typinfo::TTypeKind TypeKind = {read=GetTypeKind, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTypeInfo(void) { }
	#pragma option pop
	
private:
	void *__IJclTypeInfo;	/* Jclrtti::IJclTypeInfo */
	
public:
	operator IJclTypeInfo*(void) { return (IJclTypeInfo*)&__IJclTypeInfo; }
	
};


__interface IJclOrdinalTypeInfo;
typedef System::DelphiInterface<IJclOrdinalTypeInfo> _di_IJclOrdinalTypeInfo;
__interface  INTERFACE_UUID("{7DAD5221-46EA-11D5-B0C0-4854E825F345}") IJclOrdinalTypeInfo  : public IJclTypeInfo 
{
	
public:
	virtual Typinfo::TOrdType __fastcall GetOrdinalType(void) = 0 ;
	__property Typinfo::TOrdType OrdinalType = {read=GetOrdinalType};
};

class DELPHICLASS TJclOrdinalTypeInfo;
class PASCALIMPLEMENTATION TJclOrdinalTypeInfo : public TJclTypeInfo 
{
	typedef TJclTypeInfo inherited;
	
protected:
	virtual void __fastcall WriteTo(const _di_IJclInfoWriter Dest);
	
public:
	Typinfo::TOrdType __fastcall GetOrdinalType(void);
	__property Typinfo::TOrdType OrdinalType = {read=GetOrdinalType, nodefault};
public:
	#pragma option push -w-inl
	/* TJclTypeInfo.Create */ inline __fastcall TJclOrdinalTypeInfo(Typinfo::PTypeInfo ATypeInfo) : TJclTypeInfo(ATypeInfo) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclOrdinalTypeInfo(void) { }
	#pragma option pop
	
private:
	void *__IJclOrdinalTypeInfo;	/* Jclrtti::IJclOrdinalTypeInfo */
	
public:
	operator IJclOrdinalTypeInfo*(void) { return (IJclOrdinalTypeInfo*)&__IJclOrdinalTypeInfo; }
	
};


__interface IJclOrdinalRangeTypeInfo;
typedef System::DelphiInterface<IJclOrdinalRangeTypeInfo> _di_IJclOrdinalRangeTypeInfo;
__interface  INTERFACE_UUID("{7DAD5222-46EA-11D5-B0C0-4854E825F345}") IJclOrdinalRangeTypeInfo  : public IJclOrdinalTypeInfo 
{
	
public:
	virtual __int64 __fastcall GetMinValue(void) = 0 ;
	virtual __int64 __fastcall GetMaxValue(void) = 0 ;
	__property __int64 MinValue = {read=GetMinValue};
	__property __int64 MaxValue = {read=GetMaxValue};
};

class DELPHICLASS TJclOrdinalRangeTypeInfo;
class PASCALIMPLEMENTATION TJclOrdinalRangeTypeInfo : public TJclOrdinalTypeInfo 
{
	typedef TJclOrdinalTypeInfo inherited;
	
protected:
	virtual void __fastcall WriteTo(const _di_IJclInfoWriter Dest);
	virtual void __fastcall DeclarationTo(const _di_IJclInfoWriter Dest);
	
public:
	__int64 __fastcall GetMinValue(void);
	__int64 __fastcall GetMaxValue(void);
	__property __int64 MinValue = {read=GetMinValue};
	__property __int64 MaxValue = {read=GetMaxValue};
public:
	#pragma option push -w-inl
	/* TJclTypeInfo.Create */ inline __fastcall TJclOrdinalRangeTypeInfo(Typinfo::PTypeInfo ATypeInfo) : TJclOrdinalTypeInfo(ATypeInfo) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclOrdinalRangeTypeInfo(void) { }
	#pragma option pop
	
private:
	void *__IJclOrdinalRangeTypeInfo;	/* Jclrtti::IJclOrdinalRangeTypeInfo */
	
public:
	operator IJclOrdinalRangeTypeInfo*(void) { return (IJclOrdinalRangeTypeInfo*)&__IJclOrdinalRangeTypeInfo; }
	
};


__interface IJclEnumerationTypeInfo;
typedef System::DelphiInterface<IJclEnumerationTypeInfo> _di_IJclEnumerationTypeInfo;
__interface  INTERFACE_UUID("{7DAD5223-46EA-11D5-B0C0-4854E825F345}") IJclEnumerationTypeInfo  : public IJclOrdinalRangeTypeInfo 
{
	
public:
	AnsiString operator[](int I) { return Names[I]; }
	
public:
	virtual _di_IJclEnumerationTypeInfo __fastcall GetBaseType(void) = 0 ;
	virtual AnsiString __fastcall GetNames(const int I) = 0 ;
	virtual AnsiString __fastcall GetUnitName(void) = 0 ;
	virtual int __fastcall IndexOfName(const AnsiString Name) = 0 ;
	__property _di_IJclEnumerationTypeInfo BaseType = {read=GetBaseType};
	__property AnsiString Names[int I] = {read=GetNames/*, default*/};
	__property AnsiString UnitName = {read=GetUnitName};
};

class DELPHICLASS TJclEnumerationTypeInfo;
class PASCALIMPLEMENTATION TJclEnumerationTypeInfo : public TJclOrdinalRangeTypeInfo 
{
	typedef TJclOrdinalRangeTypeInfo inherited;
	
public:
	AnsiString operator[](int I) { return Names[I]; }
	
protected:
	virtual void __fastcall WriteTo(const _di_IJclInfoWriter Dest);
	virtual void __fastcall DeclarationTo(const _di_IJclInfoWriter Dest);
	
public:
	_di_IJclEnumerationTypeInfo __fastcall GetBaseType();
	AnsiString __fastcall GetNames(const int I);
	AnsiString __fastcall GetUnitName();
	int __fastcall IndexOfName(const AnsiString Name);
	__property _di_IJclEnumerationTypeInfo BaseType = {read=GetBaseType};
	__property AnsiString Names[int I] = {read=GetNames/*, default*/};
public:
	#pragma option push -w-inl
	/* TJclTypeInfo.Create */ inline __fastcall TJclEnumerationTypeInfo(Typinfo::PTypeInfo ATypeInfo) : TJclOrdinalRangeTypeInfo(ATypeInfo) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclEnumerationTypeInfo(void) { }
	#pragma option pop
	
private:
	void *__IJclEnumerationTypeInfo;	/* Jclrtti::IJclEnumerationTypeInfo */
	
public:
	operator IJclEnumerationTypeInfo*(void) { return (IJclEnumerationTypeInfo*)&__IJclEnumerationTypeInfo; }
	
};


__interface IJclSetTypeInfo;
typedef System::DelphiInterface<IJclSetTypeInfo> _di_IJclSetTypeInfo;
__interface  INTERFACE_UUID("{7DAD5224-46EA-11D5-B0C0-4854E825F345}") IJclSetTypeInfo  : public IJclOrdinalTypeInfo 
{
	
public:
	virtual _di_IJclOrdinalTypeInfo __fastcall GetBaseType(void) = 0 ;
	virtual void __fastcall GetAsList(const void *Value, const bool WantRanges, const Classes::TStrings* Strings) = 0 ;
	virtual void __fastcall SetAsList(/* out */ void *Value, const Classes::TStrings* Strings) = 0 ;
	__property _di_IJclOrdinalTypeInfo BaseType = {read=GetBaseType};
};

class DELPHICLASS TJclSetTypeInfo;
class PASCALIMPLEMENTATION TJclSetTypeInfo : public TJclOrdinalTypeInfo 
{
	typedef TJclOrdinalTypeInfo inherited;
	
protected:
	virtual void __fastcall WriteTo(const _di_IJclInfoWriter Dest);
	virtual void __fastcall DeclarationTo(const _di_IJclInfoWriter Dest);
	
public:
	_di_IJclOrdinalTypeInfo __fastcall GetBaseType();
	void __fastcall GetAsList(const void *Value, const bool WantRanges, const Classes::TStrings* Strings);
	void __fastcall SetAsList(/* out */ void *Value, const Classes::TStrings* Strings);
	__property _di_IJclOrdinalTypeInfo BaseType = {read=GetBaseType};
public:
	#pragma option push -w-inl
	/* TJclTypeInfo.Create */ inline __fastcall TJclSetTypeInfo(Typinfo::PTypeInfo ATypeInfo) : TJclOrdinalTypeInfo(ATypeInfo) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclSetTypeInfo(void) { }
	#pragma option pop
	
private:
	void *__IJclSetTypeInfo;	/* Jclrtti::IJclSetTypeInfo */
	
public:
	operator IJclSetTypeInfo*(void) { return (IJclSetTypeInfo*)&__IJclSetTypeInfo; }
	
};


__interface IJclFloatTypeInfo;
typedef System::DelphiInterface<IJclFloatTypeInfo> _di_IJclFloatTypeInfo;
__interface  INTERFACE_UUID("{7DAD5225-46EA-11D5-B0C0-4854E825F345}") IJclFloatTypeInfo  : public IJclTypeInfo 
{
	
public:
	virtual Typinfo::TFloatType __fastcall GetFloatType(void) = 0 ;
	__property Typinfo::TFloatType FloatType = {read=GetFloatType};
};

class DELPHICLASS TJclFloatTypeInfo;
class PASCALIMPLEMENTATION TJclFloatTypeInfo : public TJclTypeInfo 
{
	typedef TJclTypeInfo inherited;
	
protected:
	virtual void __fastcall WriteTo(const _di_IJclInfoWriter Dest);
	virtual void __fastcall DeclarationTo(const _di_IJclInfoWriter Dest);
	
public:
	Typinfo::TFloatType __fastcall GetFloatType(void);
	__property Typinfo::TFloatType FloatType = {read=GetFloatType, nodefault};
public:
	#pragma option push -w-inl
	/* TJclTypeInfo.Create */ inline __fastcall TJclFloatTypeInfo(Typinfo::PTypeInfo ATypeInfo) : TJclTypeInfo(ATypeInfo) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclFloatTypeInfo(void) { }
	#pragma option pop
	
private:
	void *__IJclFloatTypeInfo;	/* Jclrtti::IJclFloatTypeInfo */
	
public:
	operator IJclFloatTypeInfo*(void) { return (IJclFloatTypeInfo*)&__IJclFloatTypeInfo; }
	
};


__interface IJclStringTypeInfo;
typedef System::DelphiInterface<IJclStringTypeInfo> _di_IJclStringTypeInfo;
__interface  INTERFACE_UUID("{7DAD5226-46EA-11D5-B0C0-4854E825F345}") IJclStringTypeInfo  : public IJclTypeInfo 
{
	
public:
	virtual int __fastcall GetMaxLength(void) = 0 ;
	__property int MaxLength = {read=GetMaxLength};
};

class DELPHICLASS TJclStringTypeInfo;
class PASCALIMPLEMENTATION TJclStringTypeInfo : public TJclTypeInfo 
{
	typedef TJclTypeInfo inherited;
	
protected:
	virtual void __fastcall WriteTo(const _di_IJclInfoWriter Dest);
	virtual void __fastcall DeclarationTo(const _di_IJclInfoWriter Dest);
	
public:
	int __fastcall GetMaxLength(void);
	__property int MaxLength = {read=GetMaxLength, nodefault};
public:
	#pragma option push -w-inl
	/* TJclTypeInfo.Create */ inline __fastcall TJclStringTypeInfo(Typinfo::PTypeInfo ATypeInfo) : TJclTypeInfo(ATypeInfo) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclStringTypeInfo(void) { }
	#pragma option pop
	
private:
	void *__IJclStringTypeInfo;	/* Jclrtti::IJclStringTypeInfo */
	
public:
	operator IJclStringTypeInfo*(void) { return (IJclStringTypeInfo*)&__IJclStringTypeInfo; }
	
};


#pragma option push -b-
enum TJclPropSpecKind { pskNone, pskStaticMethod, pskVirtualMethod, pskField, pskConstant };
#pragma option pop

__interface IJclPropInfo;
typedef System::DelphiInterface<IJclPropInfo> _di_IJclPropInfo;
__interface  INTERFACE_UUID("{7DAD5227-46EA-11D5-B0C0-4854E825F345}") IJclPropInfo  : public IInterface 
{
	
public:
	virtual Typinfo::PPropInfo __fastcall GetPropInfo(void) = 0 ;
	virtual _di_IJclTypeInfo __fastcall GetPropType(void) = 0 ;
	virtual void * __fastcall GetReader(void) = 0 ;
	virtual void * __fastcall GetWriter(void) = 0 ;
	virtual void * __fastcall GetStoredProc(void) = 0 ;
	virtual int __fastcall GetIndex(void) = 0 ;
	virtual int __fastcall GetDefault(void) = 0 ;
	virtual short __fastcall GetNameIndex(void) = 0 ;
	virtual AnsiString __fastcall GetName(void) = 0 ;
	virtual TJclPropSpecKind __fastcall GetReaderType(void) = 0 ;
	virtual TJclPropSpecKind __fastcall GetWriterType(void) = 0 ;
	virtual TJclPropSpecKind __fastcall GetStoredType(void) = 0 ;
	virtual unsigned __fastcall GetReaderValue(void) = 0 ;
	virtual unsigned __fastcall GetWriterValue(void) = 0 ;
	virtual unsigned __fastcall GetStoredValue(void) = 0 ;
	virtual bool __fastcall IsStored(const System::TObject* AInstance) = 0 ;
	virtual bool __fastcall HasDefault(void) = 0 ;
	virtual bool __fastcall HasIndex(void) = 0 ;
	__property Typinfo::PPropInfo PropInfo = {read=GetPropInfo};
	__property _di_IJclTypeInfo PropType = {read=GetPropType};
	__property void * Reader = {read=GetReader};
	__property void * Writer = {read=GetWriter};
	__property void * StoredProc = {read=GetStoredProc};
	__property TJclPropSpecKind ReaderType = {read=GetReaderType};
	__property TJclPropSpecKind WriterType = {read=GetWriterType};
	__property TJclPropSpecKind StoredType = {read=GetStoredType};
	__property unsigned ReaderValue = {read=GetReaderValue};
	__property unsigned WriterValue = {read=GetWriterValue};
	__property unsigned StoredValue = {read=GetStoredValue};
	__property int Index = {read=GetIndex};
	__property int Default = {read=GetDefault};
	__property short NameIndex = {read=GetNameIndex};
	__property AnsiString Name = {read=GetName};
};

class DELPHICLASS TJclPropInfo;
class PASCALIMPLEMENTATION TJclPropInfo : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Typinfo::TPropInfo *FPropInfo;
	
public:
	__fastcall TJclPropInfo(const Typinfo::PPropInfo APropInfo);
	Typinfo::PPropInfo __fastcall GetPropInfo(void);
	_di_IJclTypeInfo __fastcall GetPropType();
	void * __fastcall GetReader(void);
	void * __fastcall GetWriter(void);
	void * __fastcall GetStoredProc(void);
	int __fastcall GetIndex(void);
	int __fastcall GetDefault(void);
	short __fastcall GetNameIndex(void);
	AnsiString __fastcall GetName();
	TJclPropSpecKind __fastcall GetSpecKind(const unsigned Value);
	unsigned __fastcall GetSpecValue(const unsigned Value);
	TJclPropSpecKind __fastcall GetReaderType(void);
	TJclPropSpecKind __fastcall GetWriterType(void);
	TJclPropSpecKind __fastcall GetStoredType(void);
	unsigned __fastcall GetReaderValue(void);
	unsigned __fastcall GetWriterValue(void);
	unsigned __fastcall GetStoredValue(void);
	bool __fastcall IsStored(const System::TObject* AInstance);
	bool __fastcall HasDefault(void);
	bool __fastcall HasIndex(void);
	__property Typinfo::PPropInfo PropInfo = {read=GetPropInfo};
	__property _di_IJclTypeInfo PropType = {read=GetPropType};
	__property void * Reader = {read=GetReader};
	__property void * Writer = {read=GetWriter};
	__property void * StoredProc = {read=GetStoredProc};
	__property TJclPropSpecKind ReaderType = {read=GetReaderType, nodefault};
	__property TJclPropSpecKind WriterType = {read=GetWriterType, nodefault};
	__property TJclPropSpecKind StoredType = {read=GetStoredType, nodefault};
	__property unsigned ReaderValue = {read=GetReaderValue, nodefault};
	__property unsigned WriterValue = {read=GetWriterValue, nodefault};
	__property unsigned StoredValue = {read=GetStoredValue, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property int Default = {read=GetDefault, nodefault};
	__property short NameIndex = {read=GetNameIndex, nodefault};
	__property AnsiString Name = {read=GetName};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclPropInfo(void) { }
	#pragma option pop
	
private:
	void *__IJclPropInfo;	/* Jclrtti::IJclPropInfo */
	
public:
	operator IJclPropInfo*(void) { return (IJclPropInfo*)&__IJclPropInfo; }
	
};


__interface IJclClassTypeInfo;
typedef System::DelphiInterface<IJclClassTypeInfo> _di_IJclClassTypeInfo;
__interface  INTERFACE_UUID("{7DAD5228-46EA-11D5-B0C0-4854E825F345}") IJclClassTypeInfo  : public IJclTypeInfo 
{
	
public:
	virtual TMetaClass* __fastcall GetClassRef(void) = 0 ;
	virtual _di_IJclClassTypeInfo __fastcall GetParent(void) = 0 ;
	virtual int __fastcall GetTotalPropertyCount(void) = 0 ;
	virtual int __fastcall GetPropertyCount(void) = 0 ;
	virtual _di_IJclPropInfo __fastcall GetProperties(const int PropIdx) = 0 ;
	virtual _di_IJclPropInfo __fastcall GetPropNames(const AnsiString Name) = 0 ;
	virtual AnsiString __fastcall GetUnitName(void) = 0 ;
	__property TMetaClass* ClassRef = {read=GetClassRef};
	__property _di_IJclClassTypeInfo Parent = {read=GetParent};
	__property int TotalPropertyCount = {read=GetTotalPropertyCount};
	__property int PropertyCount = {read=GetPropertyCount};
	__property _di_IJclPropInfo Properties[int PropIdx] = {read=GetProperties};
	__property _di_IJclPropInfo PropNames[AnsiString Name] = {read=GetPropNames};
	__property AnsiString UnitName = {read=GetUnitName};
};

class DELPHICLASS TJclClassTypeInfo;
class PASCALIMPLEMENTATION TJclClassTypeInfo : public TJclTypeInfo 
{
	typedef TJclTypeInfo inherited;
	
protected:
	virtual void __fastcall WriteTo(const _di_IJclInfoWriter Dest);
	virtual void __fastcall DeclarationTo(const _di_IJclInfoWriter Dest);
	
public:
	TMetaClass* __fastcall GetClassRef(void);
	_di_IJclClassTypeInfo __fastcall GetParent();
	int __fastcall GetTotalPropertyCount(void);
	int __fastcall GetPropertyCount(void);
	_di_IJclPropInfo __fastcall GetProperties(const int PropIdx);
	_di_IJclPropInfo __fastcall GetPropNames(const AnsiString Name);
	AnsiString __fastcall GetUnitName();
	__property TMetaClass* ClassRef = {read=GetClassRef};
	__property _di_IJclClassTypeInfo Parent = {read=GetParent};
	__property int TotalPropertyCount = {read=GetTotalPropertyCount, nodefault};
	__property int PropertyCount = {read=GetPropertyCount, nodefault};
	__property _di_IJclPropInfo Properties[int PropIdx] = {read=GetProperties};
	__property _di_IJclPropInfo PropNames[AnsiString Name] = {read=GetPropNames};
public:
	#pragma option push -w-inl
	/* TJclTypeInfo.Create */ inline __fastcall TJclClassTypeInfo(Typinfo::PTypeInfo ATypeInfo) : TJclTypeInfo(ATypeInfo) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclClassTypeInfo(void) { }
	#pragma option pop
	
private:
	void *__IJclClassTypeInfo;	/* Jclrtti::IJclClassTypeInfo */
	
public:
	operator IJclClassTypeInfo*(void) { return (IJclClassTypeInfo*)&__IJclClassTypeInfo; }
	
};


__interface IJclEventParamInfo;
typedef System::DelphiInterface<IJclEventParamInfo> _di_IJclEventParamInfo;
__interface  INTERFACE_UUID("{7DAD5229-46EA-11D5-B0C0-4854E825F345}") IJclEventParamInfo  : public IInterface 
{
	
public:
	virtual Typinfo::TParamFlags __fastcall GetFlags(void) = 0 ;
	virtual AnsiString __fastcall GetName(void) = 0 ;
	virtual int __fastcall GetRecSize(void) = 0 ;
	virtual AnsiString __fastcall GetTypeName(void) = 0 ;
	virtual void * __fastcall GetParam(void) = 0 ;
	__property Typinfo::TParamFlags Flags = {read=GetFlags};
	__property AnsiString Name = {read=GetName};
	__property int RecSize = {read=GetRecSize};
	__property AnsiString TypeName = {read=GetTypeName};
	__property void * Param = {read=GetParam};
};

class DELPHICLASS TJclEventParamInfo;
class PASCALIMPLEMENTATION TJclEventParamInfo : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	void *FParam;
	
public:
	__fastcall TJclEventParamInfo(const void * AParam);
	Typinfo::TParamFlags __fastcall GetFlags(void);
	AnsiString __fastcall GetName();
	int __fastcall GetRecSize(void);
	AnsiString __fastcall GetTypeName();
	void * __fastcall GetParam(void);
	__property Typinfo::TParamFlags Flags = {read=GetFlags, nodefault};
	__property AnsiString Name = {read=GetName};
	__property int RecSize = {read=GetRecSize, nodefault};
	__property AnsiString TypeName = {read=GetTypeName};
	__property void * Param = {read=GetParam};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclEventParamInfo(void) { }
	#pragma option pop
	
private:
	void *__IJclEventParamInfo;	/* Jclrtti::IJclEventParamInfo */
	
public:
	operator IJclEventParamInfo*(void) { return (IJclEventParamInfo*)&__IJclEventParamInfo; }
	
};


__interface IJclEventTypeInfo;
typedef System::DelphiInterface<IJclEventTypeInfo> _di_IJclEventTypeInfo;
__interface  INTERFACE_UUID("{7DAD522A-46EA-11D5-B0C0-4854E825F345}") IJclEventTypeInfo  : public IJclTypeInfo 
{
	
public:
	virtual Typinfo::TMethodKind __fastcall GetMethodKind(void) = 0 ;
	virtual int __fastcall GetParameterCount(void) = 0 ;
	virtual _di_IJclEventParamInfo __fastcall GetParameters(const int ParamIdx) = 0 ;
	virtual AnsiString __fastcall GetResultTypeName(void) = 0 ;
	__property Typinfo::TMethodKind MethodKind = {read=GetMethodKind};
	__property int ParameterCount = {read=GetParameterCount};
	__property _di_IJclEventParamInfo Parameters[int ParamIdx] = {read=GetParameters};
	__property AnsiString ResultTypeName = {read=GetResultTypeName};
};

class DELPHICLASS TJclEventTypeInfo;
class PASCALIMPLEMENTATION TJclEventTypeInfo : public TJclTypeInfo 
{
	typedef TJclTypeInfo inherited;
	
protected:
	virtual void __fastcall WriteTo(const _di_IJclInfoWriter Dest);
	virtual void __fastcall DeclarationTo(const _di_IJclInfoWriter Dest);
	
public:
	Typinfo::TMethodKind __fastcall GetMethodKind(void);
	int __fastcall GetParameterCount(void);
	_di_IJclEventParamInfo __fastcall GetParameters(const int ParamIdx);
	AnsiString __fastcall GetResultTypeName();
	__property Typinfo::TMethodKind MethodKind = {read=GetMethodKind, nodefault};
	__property int ParameterCount = {read=GetParameterCount, nodefault};
	__property _di_IJclEventParamInfo Parameters[int ParamIdx] = {read=GetParameters};
	__property AnsiString ResultTypeName = {read=GetResultTypeName};
public:
	#pragma option push -w-inl
	/* TJclTypeInfo.Create */ inline __fastcall TJclEventTypeInfo(Typinfo::PTypeInfo ATypeInfo) : TJclTypeInfo(ATypeInfo) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclEventTypeInfo(void) { }
	#pragma option pop
	
private:
	void *__IJclEventTypeInfo;	/* Jclrtti::IJclEventTypeInfo */
	
public:
	operator IJclEventTypeInfo*(void) { return (IJclEventTypeInfo*)&__IJclEventTypeInfo; }
	
};


__interface IJclInterfaceTypeInfo;
typedef System::DelphiInterface<IJclInterfaceTypeInfo> _di_IJclInterfaceTypeInfo;
__interface  INTERFACE_UUID("{7DAD522B-46EA-11D5-B0C0-4854E825F345}") IJclInterfaceTypeInfo  : public IJclTypeInfo 
{
	
public:
	virtual _di_IJclInterfaceTypeInfo __fastcall GetParent(void) = 0 ;
	virtual TIntfFlagsBase __fastcall GetFlags(void) = 0 ;
	virtual GUID __fastcall GetGUID(void) = 0 ;
	virtual int __fastcall GetPropertyCount(void) = 0 ;
	virtual AnsiString __fastcall GetUnitName(void) = 0 ;
	__property _di_IJclInterfaceTypeInfo Parent = {read=GetParent};
	__property TIntfFlagsBase Flags = {read=GetFlags};
	__property GUID GUID = {read=GetGUID};
	__property int PropertyCount = {read=GetPropertyCount};
	__property AnsiString UnitName = {read=GetUnitName};
};

class DELPHICLASS TJclInterfaceTypeInfo;
class PASCALIMPLEMENTATION TJclInterfaceTypeInfo : public TJclTypeInfo 
{
	typedef TJclTypeInfo inherited;
	
protected:
	virtual void __fastcall WriteTo(const _di_IJclInfoWriter Dest);
	virtual void __fastcall DeclarationTo(const _di_IJclInfoWriter Dest);
	
public:
	_di_IJclInterfaceTypeInfo __fastcall GetParent();
	TIntfFlagsBase __fastcall GetFlags(void);
	GUID __fastcall GetGUID();
	int __fastcall GetPropertyCount(void);
	AnsiString __fastcall GetUnitName();
	__property _di_IJclInterfaceTypeInfo Parent = {read=GetParent};
	__property TIntfFlagsBase Flags = {read=GetFlags, nodefault};
	__property GUID GUID = {read=GetGUID};
	__property int PropertyCount = {read=GetPropertyCount, nodefault};
public:
	#pragma option push -w-inl
	/* TJclTypeInfo.Create */ inline __fastcall TJclInterfaceTypeInfo(Typinfo::PTypeInfo ATypeInfo) : TJclTypeInfo(ATypeInfo) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclInterfaceTypeInfo(void) { }
	#pragma option pop
	
private:
	void *__IJclInterfaceTypeInfo;	/* Jclrtti::IJclInterfaceTypeInfo */
	
public:
	operator IJclInterfaceTypeInfo*(void) { return (IJclInterfaceTypeInfo*)&__IJclInterfaceTypeInfo; }
	
};


__interface IJclInt64TypeInfo;
typedef System::DelphiInterface<IJclInt64TypeInfo> _di_IJclInt64TypeInfo;
__interface  INTERFACE_UUID("{7DAD522C-46EA-11D5-B0C0-4854E825F345}") IJclInt64TypeInfo  : public IJclTypeInfo 
{
	
public:
	virtual __int64 __fastcall GetMinValue(void) = 0 ;
	virtual __int64 __fastcall GetMaxValue(void) = 0 ;
	__property __int64 MinValue = {read=GetMinValue};
	__property __int64 MaxValue = {read=GetMaxValue};
};

class DELPHICLASS TJclInt64TypeInfo;
class PASCALIMPLEMENTATION TJclInt64TypeInfo : public TJclTypeInfo 
{
	typedef TJclTypeInfo inherited;
	
protected:
	virtual void __fastcall WriteTo(const _di_IJclInfoWriter Dest);
	virtual void __fastcall DeclarationTo(const _di_IJclInfoWriter Dest);
	
public:
	__int64 __fastcall GetMinValue(void);
	__int64 __fastcall GetMaxValue(void);
	__property __int64 MinValue = {read=GetMinValue};
	__property __int64 MaxValue = {read=GetMaxValue};
public:
	#pragma option push -w-inl
	/* TJclTypeInfo.Create */ inline __fastcall TJclInt64TypeInfo(Typinfo::PTypeInfo ATypeInfo) : TJclTypeInfo(ATypeInfo) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclInt64TypeInfo(void) { }
	#pragma option pop
	
private:
	void *__IJclInt64TypeInfo;	/* Jclrtti::IJclInt64TypeInfo */
	
public:
	operator IJclInt64TypeInfo*(void) { return (IJclInt64TypeInfo*)&__IJclInt64TypeInfo; }
	
};


__interface IJclDynArrayTypeInfo;
typedef System::DelphiInterface<IJclDynArrayTypeInfo> _di_IJclDynArrayTypeInfo;
__interface  INTERFACE_UUID("{7DAD522E-46EA-11D5-B0C0-4854E825F345}") IJclDynArrayTypeInfo  : public IJclTypeInfo 
{
	
public:
	virtual int __fastcall GetElementSize(void) = 0 ;
	virtual _di_IJclTypeInfo __fastcall GetElementType(void) = 0 ;
	virtual bool __fastcall GetElementsNeedCleanup(void) = 0 ;
	virtual int __fastcall GetVarType(void) = 0 ;
	virtual AnsiString __fastcall GetUnitName(void) = 0 ;
	__property int ElementSize = {read=GetElementSize};
	__property _di_IJclTypeInfo ElementType = {read=GetElementType};
	__property bool ElementsNeedCleanup = {read=GetElementsNeedCleanup};
	__property int VarType = {read=GetVarType};
	__property AnsiString UnitName = {read=GetUnitName};
};

class DELPHICLASS TJclDynArrayTypeInfo;
class PASCALIMPLEMENTATION TJclDynArrayTypeInfo : public TJclTypeInfo 
{
	typedef TJclTypeInfo inherited;
	
protected:
	virtual void __fastcall WriteTo(const _di_IJclInfoWriter Dest);
	virtual void __fastcall DeclarationTo(const _di_IJclInfoWriter Dest);
	
public:
	int __fastcall GetElementSize(void);
	_di_IJclTypeInfo __fastcall GetElementType();
	bool __fastcall GetElementsNeedCleanup(void);
	int __fastcall GetVarType(void);
	AnsiString __fastcall GetUnitName();
	__property int ElementSize = {read=GetElementSize, nodefault};
	__property _di_IJclTypeInfo ElementType = {read=GetElementType};
	__property bool ElementsNeedCleanup = {read=GetElementsNeedCleanup, nodefault};
	__property int VarType = {read=GetVarType, nodefault};
public:
	#pragma option push -w-inl
	/* TJclTypeInfo.Create */ inline __fastcall TJclDynArrayTypeInfo(Typinfo::PTypeInfo ATypeInfo) : TJclTypeInfo(ATypeInfo) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclDynArrayTypeInfo(void) { }
	#pragma option pop
	
private:
	void *__IJclDynArrayTypeInfo;	/* Jclrtti::IJclDynArrayTypeInfo */
	
public:
	operator IJclDynArrayTypeInfo*(void) { return (IJclDynArrayTypeInfo*)&__IJclDynArrayTypeInfo; }
	
};


class DELPHICLASS EJclRTTIError;
class PASCALIMPLEMENTATION EJclRTTIError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclRTTIError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclRTTIError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclRTTIError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclRTTIError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclRTTIError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclRTTIError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclRTTIError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclRTTIError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclRTTIError(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Byte PREFIX_CUT_LOWERCASE = 0xff;
static const Byte PREFIX_CUT_EQUAL = 0xfe;
static const Byte MaxPrefixCut = 0xfa;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE _di_IJclTypeInfo __fastcall JclTypeInfo(Typinfo::PTypeInfo ATypeInfo);
extern PACKAGE void __fastcall RemoveTypeInfo(Typinfo::PTypeInfo TypeInfo);
extern PACKAGE AnsiString __fastcall JclEnumValueToIdent(Typinfo::PTypeInfo TypeInfo, const void *Value);
extern PACKAGE Typinfo::PTypeInfo __fastcall JclGenerateEnumType(const System::ShortString &TypeName, AnsiString const * Literals, const int Literals_Size);
extern PACKAGE Typinfo::PTypeInfo __fastcall JclGenerateEnumTypeBasedOn(const System::ShortString &TypeName, Typinfo::PTypeInfo BaseType, const Byte PrefixCut);
extern PACKAGE Typinfo::PTypeInfo __fastcall JclGenerateSubRange(Typinfo::PTypeInfo BaseType, const AnsiString TypeName, const int MinValue, const int MaxValue);
extern PACKAGE int __fastcall JclStrToTypedInt(AnsiString Value, Typinfo::PTypeInfo TypeInfo);
extern PACKAGE AnsiString __fastcall JclTypedIntToStr(int Value, Typinfo::PTypeInfo TypeInfo);
extern PACKAGE AnsiString __fastcall JclSetToList(Typinfo::PTypeInfo TypeInfo, const void *Value, const bool WantBrackets, const bool WantRanges, const Classes::TStrings* Strings);
extern PACKAGE AnsiString __fastcall JclSetToStr(Typinfo::PTypeInfo TypeInfo, const void *Value, const bool WantBrackets = false, const bool WantRanges = false);
extern PACKAGE void __fastcall JclStrToSet(Typinfo::PTypeInfo TypeInfo, void *SetVar, const AnsiString Value);
extern PACKAGE void __fastcall JclIntToSet(Typinfo::PTypeInfo TypeInfo, void *SetVar, const int Value);
extern PACKAGE int __fastcall JclSetToInt(Typinfo::PTypeInfo TypeInfo, const void *SetVar);
extern PACKAGE Typinfo::PTypeInfo __fastcall JclGenerateSetType(Typinfo::PTypeInfo BaseType, const System::ShortString &TypeName);
extern PACKAGE bool __fastcall JclIsClass(const System::TObject* AnObj, const TMetaClass* AClass);
extern PACKAGE bool __fastcall JclIsClassByName(const System::TObject* AnObj, const TMetaClass* AClass);

}	/* namespace Jclrtti */
using namespace Jclrtti;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclrtti
