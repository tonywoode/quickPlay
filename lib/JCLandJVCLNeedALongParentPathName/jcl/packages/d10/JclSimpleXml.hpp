// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclsimplexml.pas' rev: 10.00

#ifndef JclsimplexmlHPP
#define JclsimplexmlHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Inifiles.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclstreams.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclsimplexml
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EJclSimpleXMLError;
class PASCALIMPLEMENTATION EJclSimpleXMLError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclSimpleXMLError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclSimpleXMLError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclSimpleXMLError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclSimpleXMLError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclSimpleXMLError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclSimpleXMLError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclSimpleXMLError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclSimpleXMLError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclSimpleXMLError(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TJclOnSimpleXMLParsed)(System::TObject* Sender, const AnsiString Name);

typedef void __fastcall (__closure *TJclOnValueParsed)(System::TObject* Sender, const AnsiString Name, const AnsiString Value);

typedef void __fastcall (__closure *TJclOnSimpleProgress)(System::TObject* Sender, const int Position, const int Total);

#pragma option push -b-
enum TJclHashKind { hkList, hkDirect };
#pragma option pop

struct TJclHashElem;
typedef TJclHashElem *PJclHashElem;

#pragma pack(push,1)
struct TJclHashElem
{
	
public:
	TJclHashElem *Next;
	System::TObject* Obj;
} ;
#pragma pack(pop)

struct TJclHashRecord;
typedef TJclHashRecord *PJclHashRecord;

typedef TJclHashRecord *TJclHashList[26];

typedef PJclHashRecord *PJclHashList;

#pragma pack(push,1)
struct TJclHashRecord
{
	
public:
	Byte Count;
	TJclHashKind Kind;
	union
	{
		struct 
		{
			TJclHashElem *FirstElem;
			
		};
		struct 
		{
			PJclHashRecord *List;
			
		};
		
	};
} ;
#pragma pack(pop)

class DELPHICLASS TJclSimpleXMLProp;
class DELPHICLASS TJclSimpleXMLProps;
class DELPHICLASS TJclSimpleXMLElem;
class DELPHICLASS TJclSimpleXMLElems;
class DELPHICLASS TJclSimpleXMLNamedElems;
typedef int __fastcall (__closure *TJclSimpleXMLElemCompare)(TJclSimpleXMLElems* Elems, int Index1, int Index2);

class DELPHICLASS TJclSimpleXMLElemClassic;
class DELPHICLASS TJclSimpleXMLElemComment;
class DELPHICLASS TJclSimpleXMLElemCData;
class DELPHICLASS TJclSimpleXMLElemText;
class DELPHICLASS TJclSimpleXML;
class PASCALIMPLEMENTATION TJclSimpleXMLElems : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TJclSimpleXMLElem* operator[](int Index) { return Item[Index]; }
	
private:
	TJclSimpleXMLElem* FParent;
	int __fastcall GetCount(void);
	TJclSimpleXMLElem* __fastcall GetItemNamedDefault(const AnsiString Name, const AnsiString Default);
	TJclSimpleXMLElem* __fastcall GetItemNamed(const AnsiString Name);
	TJclSimpleXMLNamedElems* __fastcall GetNamedElems(const AnsiString Name);
	
protected:
	Inifiles::THashedStringList* FElems;
	TJclSimpleXMLElemCompare FCompare;
	Inifiles::THashedStringList* FNamedElems;
	TJclSimpleXMLElem* __fastcall GetItem(const int Index);
	void __fastcall AddChild(const TJclSimpleXMLElem* Value);
	void __fastcall AddChildFirst(const TJclSimpleXMLElem* Value);
	void __fastcall InsertChild(const TJclSimpleXMLElem* Value, int Index);
	void __fastcall DoItemRename(TJclSimpleXMLElem* Value, const AnsiString Name);
	void __fastcall CreateElems(void);
	
public:
	__fastcall TJclSimpleXMLElems(const TJclSimpleXMLElem* AOwner);
	__fastcall virtual ~TJclSimpleXMLElems(void);
	void __fastcall Notify(TJclSimpleXMLElem* Value, Classes::TOperation Operation);
	TJclSimpleXMLElemClassic* __fastcall Add(const AnsiString Name)/* overload */;
	TJclSimpleXMLElemClassic* __fastcall Add(const AnsiString Name, const AnsiString Value)/* overload */;
	TJclSimpleXMLElemClassic* __fastcall Add(const AnsiString Name, const __int64 Value)/* overload */;
	TJclSimpleXMLElemClassic* __fastcall Add(const AnsiString Name, const bool Value)/* overload */;
	TJclSimpleXMLElemClassic* __fastcall Add(const AnsiString Name, Classes::TStream* Value)/* overload */;
	TJclSimpleXMLElem* __fastcall Add(TJclSimpleXMLElem* Value)/* overload */;
	TJclSimpleXMLElem* __fastcall AddFirst(TJclSimpleXMLElem* Value)/* overload */;
	TJclSimpleXMLElemClassic* __fastcall AddFirst(const AnsiString Name)/* overload */;
	TJclSimpleXMLElemComment* __fastcall AddComment(const AnsiString Name, const AnsiString Value);
	TJclSimpleXMLElemCData* __fastcall AddCData(const AnsiString Name, const AnsiString Value);
	TJclSimpleXMLElemText* __fastcall AddText(const AnsiString Name, const AnsiString Value);
	TJclSimpleXMLElem* __fastcall Insert(TJclSimpleXMLElem* Value, int Index)/* overload */;
	TJclSimpleXMLElemClassic* __fastcall Insert(const AnsiString Name, int Index)/* overload */;
	virtual void __fastcall Clear(void);
	void __fastcall Delete(const int Index)/* overload */;
	void __fastcall Delete(const AnsiString Name)/* overload */;
	int __fastcall Remove(TJclSimpleXMLElem* Value);
	void __fastcall Move(const int CurIndex, const int NewIndex);
	int __fastcall IndexOf(const TJclSimpleXMLElem* Value)/* overload */;
	int __fastcall IndexOf(const AnsiString Name)/* overload */;
	AnsiString __fastcall Value(const AnsiString Name, const AnsiString Default = "");
	__int64 __fastcall IntValue(const AnsiString Name, const __int64 Default = 0xffffffffffffffff);
	Extended __fastcall FloatValue(const AnsiString Name, const Extended Default = 0.000000E+00);
	bool __fastcall BoolValue(const AnsiString Name, bool Default = true);
	void __fastcall BinaryValue(const AnsiString Name, Classes::TStream* Stream);
	void __fastcall LoadFromStringStream(Jclstreams::TJclStringStream* StringStream, TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
	void __fastcall SaveToStringStream(Jclstreams::TJclStringStream* StringStream, const AnsiString Level = "", TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
	void __fastcall Sort(void);
	void __fastcall CustomSort(TJclSimpleXMLElemCompare AFunction);
	__property TJclSimpleXMLElem* Parent = {read=FParent, write=FParent};
	__property TJclSimpleXMLElem* Item[int Index] = {read=GetItem/*, default*/};
	__property TJclSimpleXMLElem* ItemNamed[AnsiString Name] = {read=GetItemNamed};
	__property int Count = {read=GetCount, nodefault};
	__property TJclSimpleXMLNamedElems* NamedElems[AnsiString Name] = {read=GetNamedElems};
};


class PASCALIMPLEMENTATION TJclSimpleXMLElem : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FName;
	TJclSimpleXMLElem* FParent;
	TJclSimpleXMLElems* FItems;
	TJclSimpleXMLProps* FProps;
	AnsiString FValue;
	AnsiString FNameSpace;
	void *FData;
	TJclSimpleXML* FSimpleXML;
	TJclSimpleXMLElems* FContainer;
	Extended __fastcall GetFloatValue(void);
	void __fastcall SetFloatValue(const Extended Value);
	AnsiString __fastcall GetAnsiValue();
	void __fastcall SetAnsiValue(const AnsiString Value);
	
protected:
	TJclSimpleXML* __fastcall GetSimpleXML(void);
	__int64 __fastcall GetIntValue(void);
	bool __fastcall GetBoolValue(void);
	int __fastcall GetChildsCount(void);
	TJclSimpleXMLProps* __fastcall GetProps(void);
	void __fastcall SetBoolValue(const bool Value);
	void __fastcall SetName(const AnsiString Value);
	void __fastcall SetIntValue(const __int64 Value);
	TJclSimpleXMLElems* __fastcall GetItems(void);
	void __fastcall Error(const AnsiString S);
	void __fastcall FmtError(const AnsiString S, System::TVarRec const * Args, const int Args_Size);
	
public:
	__fastcall virtual TJclSimpleXMLElem(const TJclSimpleXMLElem* AOwner);
	__fastcall virtual ~TJclSimpleXMLElem(void);
	virtual void __fastcall Assign(TJclSimpleXMLElem* Value);
	virtual void __fastcall Clear(void);
	virtual void __fastcall LoadFromStringStream(Jclstreams::TJclStringStream* StringStream, TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0)) = 0 ;
	virtual void __fastcall SaveToStringStream(Jclstreams::TJclStringStream* StringStream, const AnsiString Level = "", TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0)) = 0 ;
	void __fastcall LoadFromString(const AnsiString Value);
	AnsiString __fastcall SaveToString();
	void __fastcall GetBinaryValue(Classes::TStream* Stream);
	__property void * Data = {read=FData, write=FData};
	int __fastcall GetChildIndex(const TJclSimpleXMLElem* AChild);
	int __fastcall GetNamedIndex(const TJclSimpleXMLElem* AChild);
	__property TJclSimpleXML* SimpleXML = {read=GetSimpleXML};
	__property TJclSimpleXMLElems* Container = {read=FContainer, write=FContainer};
	
__published:
	virtual AnsiString __fastcall FullName();
	__property AnsiString Name = {read=FName, write=SetName};
	__property TJclSimpleXMLElem* Parent = {read=FParent, write=FParent};
	__property AnsiString NameSpace = {read=FNameSpace, write=FNameSpace};
	__property int ChildsCount = {read=GetChildsCount, nodefault};
	__property TJclSimpleXMLElems* Items = {read=GetItems};
	__property TJclSimpleXMLProps* Properties = {read=GetProps};
	__property __int64 IntValue = {read=GetIntValue, write=SetIntValue};
	__property bool BoolValue = {read=GetBoolValue, write=SetBoolValue, nodefault};
	__property Extended FloatValue = {read=GetFloatValue, write=SetFloatValue};
	__property AnsiString Value = {read=FValue, write=FValue};
	__property AnsiString AnsiValue = {read=GetAnsiValue, write=SetAnsiValue};
};


class PASCALIMPLEMENTATION TJclSimpleXMLProps : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TJclSimpleXMLProp* operator[](int Index) { return Item[Index]; }
	
private:
	Inifiles::THashedStringList* FProperties;
	TJclSimpleXMLElem* FParent;
	int __fastcall GetCount(void);
	TJclSimpleXMLProp* __fastcall GetItemNamedDefault(const AnsiString Name, const AnsiString Default);
	TJclSimpleXMLProp* __fastcall GetItemNamed(const AnsiString Name);
	
protected:
	TJclSimpleXML* __fastcall GetSimpleXML(void);
	TJclSimpleXMLProp* __fastcall GetItem(const int Index);
	void __fastcall DoItemRename(TJclSimpleXMLProp* Value, const AnsiString Name);
	void __fastcall Error(const AnsiString S);
	void __fastcall FmtError(const AnsiString S, System::TVarRec const * Args, const int Args_Size);
	
public:
	__fastcall TJclSimpleXMLProps(TJclSimpleXMLElem* Parent);
	__fastcall virtual ~TJclSimpleXMLProps(void);
	TJclSimpleXMLProp* __fastcall Add(const AnsiString Name, const AnsiString Value)/* overload */;
	TJclSimpleXMLProp* __fastcall Add(const AnsiString Name, const __int64 Value)/* overload */;
	TJclSimpleXMLProp* __fastcall Add(const AnsiString Name, const bool Value)/* overload */;
	TJclSimpleXMLProp* __fastcall Insert(const int Index, const AnsiString Name, const AnsiString Value)/* overload */;
	TJclSimpleXMLProp* __fastcall Insert(const int Index, const AnsiString Name, const __int64 Value)/* overload */;
	TJclSimpleXMLProp* __fastcall Insert(const int Index, const AnsiString Name, const bool Value)/* overload */;
	virtual void __fastcall Clear(void);
	void __fastcall Delete(const int Index)/* overload */;
	void __fastcall Delete(const AnsiString Name)/* overload */;
	AnsiString __fastcall Value(const AnsiString Name, const AnsiString Default = "");
	__int64 __fastcall IntValue(const AnsiString Name, const __int64 Default = 0xffffffffffffffff);
	bool __fastcall BoolValue(const AnsiString Name, bool Default = true);
	Extended __fastcall FloatValue(const AnsiString Name, const Extended Default = 0.000000E+00);
	void __fastcall LoadFromStringStream(Jclstreams::TJclStringStream* StringStream);
	void __fastcall SaveToStringStream(Jclstreams::TJclStringStream* StringStream);
	__property TJclSimpleXMLProp* Item[int Index] = {read=GetItem/*, default*/};
	__property TJclSimpleXMLProp* ItemNamed[AnsiString Name] = {read=GetItemNamed};
	__property int Count = {read=GetCount, nodefault};
};


class PASCALIMPLEMENTATION TJclSimpleXMLProp : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FName;
	AnsiString FValue;
	TJclSimpleXMLProps* FParent;
	AnsiString FNameSpace;
	void *FData;
	bool __fastcall GetBoolValue(void);
	void __fastcall SetBoolValue(const bool Value);
	void __fastcall SetName(const AnsiString Value);
	Extended __fastcall GetFloatValue(void);
	void __fastcall SetFloatValue(const Extended Value);
	AnsiString __fastcall GetAnsiValue();
	void __fastcall SetAnsiValue(const AnsiString Value);
	
protected:
	__int64 __fastcall GetIntValue(void);
	void __fastcall SetIntValue(const __int64 Value);
	
public:
	TJclSimpleXML* __fastcall GetSimpleXML(void);
	void __fastcall SaveToStringStream(Jclstreams::TJclStringStream* StringStream);
	AnsiString __fastcall FullName();
	__property TJclSimpleXMLProps* Parent = {read=FParent, write=FParent};
	__property AnsiString Name = {read=FName, write=SetName};
	__property AnsiString Value = {read=FValue, write=FValue};
	__property AnsiString AnsiValue = {read=GetAnsiValue, write=SetAnsiValue};
	__property __int64 IntValue = {read=GetIntValue, write=SetIntValue};
	__property bool BoolValue = {read=GetBoolValue, write=SetBoolValue, nodefault};
	__property Extended FloatValue = {read=GetFloatValue, write=SetFloatValue};
	__property AnsiString NameSpace = {read=FNameSpace, write=FNameSpace};
	__property void * Data = {read=FData, write=FData};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclSimpleXMLProp(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclSimpleXMLProp(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclSimpleXMLElemsProlog;
class DELPHICLASS TJclSimpleXMLElemDocType;
class DELPHICLASS TJclSimpleXMLElemSheet;
class DELPHICLASS TJclSimpleXMLElemMSOApplication;
class PASCALIMPLEMENTATION TJclSimpleXMLElemsProlog : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TJclSimpleXMLElem* operator[](int Index) { return Item[Index]; }
	
private:
	Inifiles::THashedStringList* FElems;
	int __fastcall GetCount(void);
	TJclSimpleXMLElem* __fastcall GetItem(const int Index);
	AnsiString __fastcall GetEncoding();
	bool __fastcall GetStandAlone(void);
	AnsiString __fastcall GetVersion();
	void __fastcall SetEncoding(const AnsiString Value);
	void __fastcall SetStandAlone(const bool Value);
	void __fastcall SetVersion(const AnsiString Value);
	
protected:
	TJclSimpleXMLElem* __fastcall FindHeader(void);
	void __fastcall Error(const AnsiString S);
	void __fastcall FmtError(const AnsiString S, System::TVarRec const * Args, const int Args_Size);
	
public:
	__fastcall TJclSimpleXMLElemsProlog(void);
	__fastcall virtual ~TJclSimpleXMLElemsProlog(void);
	TJclSimpleXMLElemComment* __fastcall AddComment(const AnsiString AValue);
	TJclSimpleXMLElemDocType* __fastcall AddDocType(const AnsiString AValue);
	void __fastcall Clear(void);
	TJclSimpleXMLElemSheet* __fastcall AddStyleSheet(const AnsiString AType, const AnsiString AHRef);
	TJclSimpleXMLElemMSOApplication* __fastcall AddMSOApplication(const AnsiString AProgId);
	void __fastcall LoadFromStringStream(Jclstreams::TJclStringStream* StringStream, TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
	void __fastcall SaveToStringStream(Jclstreams::TJclStringStream* StringStream, TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
	__property TJclSimpleXMLElem* Item[int Index] = {read=GetItem/*, default*/};
	__property int Count = {read=GetCount, nodefault};
	__property AnsiString Encoding = {read=GetEncoding, write=SetEncoding};
	__property bool StandAlone = {read=GetStandAlone, write=SetStandAlone, nodefault};
	__property AnsiString Version = {read=GetVersion, write=SetVersion};
};


class PASCALIMPLEMENTATION TJclSimpleXMLNamedElems : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TJclSimpleXMLElem* operator[](int Index) { return Item[Index]; }
	
private:
	TJclSimpleXMLElems* FElems;
	AnsiString FName;
	int __fastcall GetCount(void);
	
protected:
	Classes::TList* FItems;
	TJclSimpleXMLElem* __fastcall GetItem(const int Index);
	
public:
	__fastcall TJclSimpleXMLNamedElems(const TJclSimpleXMLElems* AOwner, const AnsiString AName);
	__fastcall virtual ~TJclSimpleXMLNamedElems(void);
	TJclSimpleXMLElemClassic* __fastcall Add(void)/* overload */;
	TJclSimpleXMLElemClassic* __fastcall Add(const AnsiString Value)/* overload */;
	TJclSimpleXMLElemClassic* __fastcall Add(const __int64 Value)/* overload */;
	TJclSimpleXMLElemClassic* __fastcall Add(const bool Value)/* overload */;
	TJclSimpleXMLElemClassic* __fastcall Add(Classes::TStream* Value)/* overload */;
	TJclSimpleXMLElemClassic* __fastcall AddFirst(void);
	TJclSimpleXMLElemComment* __fastcall AddComment(const AnsiString Value);
	TJclSimpleXMLElemCData* __fastcall AddCData(const AnsiString Value);
	TJclSimpleXMLElemText* __fastcall AddText(const AnsiString Value);
	virtual void __fastcall Clear(void);
	void __fastcall Delete(const int Index);
	void __fastcall Move(const int CurIndex, const int NewIndex);
	int __fastcall IndexOf(const TJclSimpleXMLElem* Value)/* overload */;
	int __fastcall IndexOf(const AnsiString Value)/* overload */;
	__property TJclSimpleXMLElems* Elems = {read=FElems};
	__property TJclSimpleXMLElem* Item[int Index] = {read=GetItem/*, default*/};
	__property int Count = {read=GetCount, nodefault};
	__property AnsiString Name = {read=FName};
};


typedef TMetaClass* TJclSimpleXMLElemClass;

class PASCALIMPLEMENTATION TJclSimpleXMLElemComment : public TJclSimpleXMLElem 
{
	typedef TJclSimpleXMLElem inherited;
	
public:
	virtual void __fastcall LoadFromStringStream(Jclstreams::TJclStringStream* StringStream, TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
	virtual void __fastcall SaveToStringStream(Jclstreams::TJclStringStream* StringStream, const AnsiString Level = "", TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
public:
	#pragma option push -w-inl
	/* TJclSimpleXMLElem.Create */ inline __fastcall virtual TJclSimpleXMLElemComment(const TJclSimpleXMLElem* AOwner) : TJclSimpleXMLElem(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclSimpleXMLElem.Destroy */ inline __fastcall virtual ~TJclSimpleXMLElemComment(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TJclSimpleXMLElemClassic : public TJclSimpleXMLElem 
{
	typedef TJclSimpleXMLElem inherited;
	
public:
	virtual void __fastcall LoadFromStringStream(Jclstreams::TJclStringStream* StringStream, TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
	virtual void __fastcall SaveToStringStream(Jclstreams::TJclStringStream* StringStream, const AnsiString Level = "", TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
public:
	#pragma option push -w-inl
	/* TJclSimpleXMLElem.Create */ inline __fastcall virtual TJclSimpleXMLElemClassic(const TJclSimpleXMLElem* AOwner) : TJclSimpleXMLElem(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclSimpleXMLElem.Destroy */ inline __fastcall virtual ~TJclSimpleXMLElemClassic(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TJclSimpleXMLElemCData : public TJclSimpleXMLElem 
{
	typedef TJclSimpleXMLElem inherited;
	
public:
	virtual void __fastcall LoadFromStringStream(Jclstreams::TJclStringStream* StringStream, TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
	virtual void __fastcall SaveToStringStream(Jclstreams::TJclStringStream* StringStream, const AnsiString Level = "", TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
public:
	#pragma option push -w-inl
	/* TJclSimpleXMLElem.Create */ inline __fastcall virtual TJclSimpleXMLElemCData(const TJclSimpleXMLElem* AOwner) : TJclSimpleXMLElem(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclSimpleXMLElem.Destroy */ inline __fastcall virtual ~TJclSimpleXMLElemCData(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TJclSimpleXMLElemText : public TJclSimpleXMLElem 
{
	typedef TJclSimpleXMLElem inherited;
	
public:
	virtual void __fastcall LoadFromStringStream(Jclstreams::TJclStringStream* StringStream, TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
	virtual void __fastcall SaveToStringStream(Jclstreams::TJclStringStream* StringStream, const AnsiString Level = "", TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
public:
	#pragma option push -w-inl
	/* TJclSimpleXMLElem.Create */ inline __fastcall virtual TJclSimpleXMLElemText(const TJclSimpleXMLElem* AOwner) : TJclSimpleXMLElem(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclSimpleXMLElem.Destroy */ inline __fastcall virtual ~TJclSimpleXMLElemText(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclSimpleXMLElemHeader;
class PASCALIMPLEMENTATION TJclSimpleXMLElemHeader : public TJclSimpleXMLElem 
{
	typedef TJclSimpleXMLElem inherited;
	
private:
	bool FStandalone;
	AnsiString FEncoding;
	AnsiString FVersion;
	
public:
	virtual void __fastcall Assign(TJclSimpleXMLElem* Value);
	virtual void __fastcall LoadFromStringStream(Jclstreams::TJclStringStream* StringStream, TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
	virtual void __fastcall SaveToStringStream(Jclstreams::TJclStringStream* StringStream, const AnsiString Level = "", TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
	__property AnsiString Version = {read=FVersion, write=FVersion};
	__property bool StandAlone = {read=FStandalone, write=FStandalone, nodefault};
	__property AnsiString Encoding = {read=FEncoding, write=FEncoding};
	__fastcall virtual TJclSimpleXMLElemHeader(const TJclSimpleXMLElem* AOwner);
public:
	#pragma option push -w-inl
	/* TJclSimpleXMLElem.Destroy */ inline __fastcall virtual ~TJclSimpleXMLElemHeader(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TJclSimpleXMLElemDocType : public TJclSimpleXMLElem 
{
	typedef TJclSimpleXMLElem inherited;
	
public:
	virtual void __fastcall LoadFromStringStream(Jclstreams::TJclStringStream* StringStream, TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
	virtual void __fastcall SaveToStringStream(Jclstreams::TJclStringStream* StringStream, const AnsiString Level = "", TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
public:
	#pragma option push -w-inl
	/* TJclSimpleXMLElem.Create */ inline __fastcall virtual TJclSimpleXMLElemDocType(const TJclSimpleXMLElem* AOwner) : TJclSimpleXMLElem(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclSimpleXMLElem.Destroy */ inline __fastcall virtual ~TJclSimpleXMLElemDocType(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TJclSimpleXMLElemSheet : public TJclSimpleXMLElem 
{
	typedef TJclSimpleXMLElem inherited;
	
public:
	virtual void __fastcall LoadFromStringStream(Jclstreams::TJclStringStream* StringStream, TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
	virtual void __fastcall SaveToStringStream(Jclstreams::TJclStringStream* StringStream, const AnsiString Level = "", TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
public:
	#pragma option push -w-inl
	/* TJclSimpleXMLElem.Create */ inline __fastcall virtual TJclSimpleXMLElemSheet(const TJclSimpleXMLElem* AOwner) : TJclSimpleXMLElem(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclSimpleXMLElem.Destroy */ inline __fastcall virtual ~TJclSimpleXMLElemSheet(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TJclSimpleXMLElemMSOApplication : public TJclSimpleXMLElem 
{
	typedef TJclSimpleXMLElem inherited;
	
public:
	virtual void __fastcall LoadFromStringStream(Jclstreams::TJclStringStream* StringStream, TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
	virtual void __fastcall SaveToStringStream(Jclstreams::TJclStringStream* StringStream, const AnsiString Level = "", TJclSimpleXML* AParent = (TJclSimpleXML*)(0x0));
public:
	#pragma option push -w-inl
	/* TJclSimpleXMLElem.Create */ inline __fastcall virtual TJclSimpleXMLElemMSOApplication(const TJclSimpleXMLElem* AOwner) : TJclSimpleXMLElem(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclSimpleXMLElem.Destroy */ inline __fastcall virtual ~TJclSimpleXMLElemMSOApplication(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum JclSimpleXml__61 { sxoAutoCreate, sxoAutoIndent, sxoAutoEncodeValue, sxoAutoEncodeEntity, sxoDoNotSaveProlog, sxoTrimPrecedingTextWhitespace };
#pragma option pop

typedef Set<JclSimpleXml__61, sxoAutoCreate, sxoTrimPrecedingTextWhitespace>  TJclSimpleXMLOptions;

typedef void __fastcall (__closure *TJclSimpleXMLEncodeEvent)(System::TObject* Sender, AnsiString &Value);

typedef void __fastcall (__closure *TJclSimpleXMLEncodeStreamEvent)(System::TObject* Sender, Classes::TStream* InStream, Classes::TStream* OutStream);

class PASCALIMPLEMENTATION TJclSimpleXML : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	Jclstreams::TJclStringEncoding FEncoding;
	Word FCodePage;
	AnsiString FFileName;
	TJclSimpleXMLOptions FOptions;
	TJclSimpleXMLElemClassic* FRoot;
	TJclOnSimpleXMLParsed FOnTagParsed;
	TJclOnValueParsed FOnValue;
	TJclOnSimpleProgress FOnLoadProg;
	TJclOnSimpleProgress FOnSaveProg;
	TJclSimpleXMLElemsProlog* FProlog;
	int FSaveCount;
	int FSaveCurrent;
	AnsiString FIndentString;
	TJclSimpleXMLEncodeEvent FOnEncodeValue;
	TJclSimpleXMLEncodeEvent FOnDecodeValue;
	TJclSimpleXMLEncodeStreamEvent FOnDecodeStream;
	TJclSimpleXMLEncodeStreamEvent FOnEncodeStream;
	void __fastcall SetIndentString(const AnsiString Value);
	void __fastcall SetRoot(const TJclSimpleXMLElemClassic* Value);
	void __fastcall SetFileName(const AnsiString Value);
	void __fastcall DoLoadProgress(const int APosition, const int ATotal);
	void __fastcall DoSaveProgress(void);
	void __fastcall DoTagParsed(const AnsiString AName);
	void __fastcall DoValueParsed(const AnsiString AName, const AnsiString AValue);
	virtual void __fastcall DoEncodeValue(AnsiString &Value);
	virtual void __fastcall DoDecodeValue(AnsiString &Value);
	
public:
	__fastcall TJclSimpleXML(void);
	__fastcall virtual ~TJclSimpleXML(void);
	void __fastcall LoadFromString(const AnsiString Value);
	void __fastcall LoadFromFile(const AnsiString FileName, Jclstreams::TJclStringEncoding Encoding = (Jclstreams::TJclStringEncoding)(0x3), Word CodePage = (Word)(0x0));
	void __fastcall LoadFromStream(Classes::TStream* Stream, Jclstreams::TJclStringEncoding Encoding = (Jclstreams::TJclStringEncoding)(0x3), Word CodePage = (Word)(0x0));
	void __fastcall LoadFromStringStream(Jclstreams::TJclStringStream* StringStream);
	void __fastcall LoadFromResourceName(unsigned Instance, const AnsiString ResName, Jclstreams::TJclStringEncoding Encoding = (Jclstreams::TJclStringEncoding)(0x3), Word CodePage = (Word)(0x0));
	void __fastcall SaveToFile(const AnsiString FileName, Jclstreams::TJclStringEncoding Encoding = (Jclstreams::TJclStringEncoding)(0x3), Word CodePage = (Word)(0x0));
	void __fastcall SaveToStream(Classes::TStream* Stream, Jclstreams::TJclStringEncoding Encoding = (Jclstreams::TJclStringEncoding)(0x3), Word CodePage = (Word)(0x0));
	void __fastcall SaveToStringStream(Jclstreams::TJclStringStream* StringStream);
	AnsiString __fastcall SaveToString();
	__property TJclSimpleXMLElemsProlog* Prolog = {read=FProlog, write=FProlog};
	__property TJclSimpleXMLElemClassic* Root = {read=FRoot, write=SetRoot};
	__property AnsiString XMLData = {read=SaveToString, write=LoadFromString};
	__property AnsiString FileName = {read=FFileName, write=SetFileName};
	__property AnsiString IndentString = {read=FIndentString, write=SetIndentString};
	__property TJclSimpleXMLOptions Options = {read=FOptions, write=FOptions, nodefault};
	__property TJclOnSimpleProgress OnSaveProgress = {read=FOnSaveProg, write=FOnSaveProg};
	__property TJclOnSimpleProgress OnLoadProgress = {read=FOnLoadProg, write=FOnLoadProg};
	__property TJclOnSimpleXMLParsed OnTagParsed = {read=FOnTagParsed, write=FOnTagParsed};
	__property TJclOnValueParsed OnValueParsed = {read=FOnValue, write=FOnValue};
	__property TJclSimpleXMLEncodeEvent OnEncodeValue = {read=FOnEncodeValue, write=FOnEncodeValue};
	__property TJclSimpleXMLEncodeEvent OnDecodeValue = {read=FOnDecodeValue, write=FOnDecodeValue};
	__property TJclSimpleXMLEncodeStreamEvent OnEncodeStream = {read=FOnEncodeStream, write=FOnEncodeStream};
	__property TJclSimpleXMLEncodeStreamEvent OnDecodeStream = {read=FOnDecodeStream, write=FOnDecodeStream};
};


class DELPHICLASS TXMLVariant;
class PASCALIMPLEMENTATION TXMLVariant : public Variants::TInvokeableVariantType 
{
	typedef Variants::TInvokeableVariantType inherited;
	
public:
	virtual void __fastcall Clear(TVarData &V);
	virtual bool __fastcall IsClear(const TVarData &V);
	virtual void __fastcall Copy(TVarData &Dest, const TVarData &Source, const bool Indirect);
	virtual void __fastcall CastTo(TVarData &Dest, const TVarData &Source, const Word AVarType);
	virtual bool __fastcall DoFunction(TVarData &Dest, const TVarData &V, const AnsiString Name, const Variants::TVarDataArray Arguments);
	virtual bool __fastcall GetProperty(TVarData &Dest, const TVarData &V, const AnsiString Name);
	virtual bool __fastcall SetProperty(const TVarData &V, const AnsiString Name, const TVarData &Value);
public:
	#pragma option push -w-inl
	/* TCustomVariantType.Create */ inline __fastcall TXMLVariant(void)/* overload */ : Variants::TInvokeableVariantType() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomVariantType.Destroy */ inline __fastcall virtual ~TXMLVariant(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE AnsiString __fastcall EntityEncode(const AnsiString S);
extern PACKAGE AnsiString __fastcall EntityDecode(const AnsiString S);
extern PACKAGE AnsiString __fastcall SimpleXMLEncode(const AnsiString S);
extern PACKAGE void __fastcall SimpleXMLDecode(AnsiString &S, bool TrimBlanks);
extern PACKAGE AnsiString __fastcall XMLEncode(const AnsiString S);
extern PACKAGE AnsiString __fastcall XMLDecode(const AnsiString S);
extern PACKAGE Word __fastcall VarXML(void);
extern PACKAGE void __fastcall XMLCreateInto(Variant &ADest, const TJclSimpleXMLElem* AXML);
extern PACKAGE Variant __fastcall XMLCreate(const TJclSimpleXMLElem* AXML)/* overload */;
extern PACKAGE Variant __fastcall XMLCreate()/* overload */;

}	/* namespace Jclsimplexml */
using namespace Jclsimplexml;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclsimplexml
