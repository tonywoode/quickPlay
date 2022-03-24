// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcledi.pas' rev: 10.00

#ifndef JclediHPP
#define JclediHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclresources.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jcledi
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TEDIObject;
class PASCALIMPLEMENTATION TEDIObject : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TEDIObject(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TEDIObject(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TEDIObject* >  TEDIObjectArray;

class DELPHICLASS EJclEDIError;
class PASCALIMPLEMENTATION EJclEDIError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	__fastcall EJclEDIError(unsigned ID);
	__fastcall EJclEDIError(unsigned ID, System::TVarRec const * Args, const int Args_Size);
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclEDIError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclEDIError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclEDIError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclEDIError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclEDIError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclEDIError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclEDIError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclEDIError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclEDIError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEDIDelimiters;
class PASCALIMPLEMENTATION TEDIDelimiters : public TEDIObject 
{
	typedef TEDIObject inherited;
	
private:
	AnsiString FSegmentDelimiter;
	AnsiString FElementDelimiter;
	AnsiString FSubElementSeperator;
	int FSegmentDelimiterLength;
	int FElementDelimiterLength;
	int FSubelementSeperatorLength;
	void __fastcall SetSD(const AnsiString Delimiter);
	void __fastcall SetED(const AnsiString Delimiter);
	void __fastcall SetSS(const AnsiString Delimiter);
	
public:
	__fastcall TEDIDelimiters(void)/* overload */;
	__fastcall TEDIDelimiters(const AnsiString SD, const AnsiString ED, const AnsiString SS)/* overload */;
	
__published:
	__property AnsiString SD = {read=FSegmentDelimiter, write=SetSD};
	__property AnsiString ED = {read=FElementDelimiter, write=SetED};
	__property AnsiString SS = {read=FSubElementSeperator, write=SetSS};
	__property int SDLen = {read=FSegmentDelimiterLength, nodefault};
	__property int EDLen = {read=FElementDelimiterLength, nodefault};
	__property int SSLen = {read=FSubelementSeperatorLength, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TEDIDelimiters(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TEDIDataObjectType { ediUnknown, ediElement, ediCompositeElement, ediSegment, ediLoop, ediTransactionSet, ediMessage, ediFunctionalGroup, ediInterchangeControl, ediFile, ediCustom };
#pragma option pop

#pragma option push -b-
enum TEDIDataObjectDataState { ediCreated, ediAssembled, ediDisassembled };
#pragma option pop

typedef void *TCustomData;

class DELPHICLASS TEDIDataObject;
class PASCALIMPLEMENTATION TEDIDataObject : public TEDIObject 
{
	typedef TEDIObject inherited;
	
private:
	void __fastcall SetDelimiters(const TEDIDelimiters* Delimiters);
	
protected:
	TEDIDataObjectType FEDIDOT;
	TEDIDataObjectDataState FState;
	AnsiString FData;
	int FLength;
	TEDIDataObject* FParent;
	TEDIDelimiters* FDelimiters;
	Classes::TStrings* FErrorLog;
	TEDIObject* FSpecPointer;
	void *FCustomData1;
	void *FCustomData2;
	AnsiString __fastcall GetData();
	void __fastcall SetData(const AnsiString Data);
	
public:
	__fastcall TEDIDataObject(TEDIDataObject* Parent);
	__fastcall virtual ~TEDIDataObject(void);
	virtual AnsiString __fastcall Assemble(void) = 0 ;
	virtual void __fastcall Disassemble(void) = 0 ;
	__property TEDIObject* SpecPointer = {read=FSpecPointer, write=FSpecPointer};
	__property void * CustomData1 = {read=FCustomData1, write=FCustomData1};
	__property void * CustomData2 = {read=FCustomData2, write=FCustomData2};
	
__published:
	__property TEDIDataObjectDataState State = {read=FState, nodefault};
	__property AnsiString Data = {read=GetData, write=SetData};
	__property int DataLength = {read=FLength, nodefault};
	__property TEDIDataObject* Parent = {read=FParent, write=FParent};
	__property TEDIDelimiters* Delimiters = {read=FDelimiters, write=SetDelimiters};
};


typedef DynamicArray<TEDIDataObject* >  TEDIDataObjectArray;

class DELPHICLASS TEDIDataObjectGroup;
class DELPHICLASS TEDIDataObjectList;
class DELPHICLASS TEDIObjectList;
class DELPHICLASS TEDIObjectListItem;
#pragma option push -b-
enum JclEDI__7 { loAutoUpdateIndexes };
#pragma option pop

typedef Set<JclEDI__7, loAutoUpdateIndexes, loAutoUpdateIndexes>  TEDIDataObjectListOptions;

class PASCALIMPLEMENTATION TEDIObjectList : public TEDIObject 
{
	typedef TEDIObject inherited;
	
public:
	TEDIObject* operator[](int Index) { return EDIObject[Index]; }
	
private:
	TEDIObjectListItem* __fastcall GetItem(int Index);
	
protected:
	bool FOwnsObjects;
	int FCount;
	TEDIDataObjectListOptions FOptions;
	TEDIObjectListItem* FFirstItem;
	TEDIObjectListItem* FLastItem;
	TEDIObjectListItem* FCurrentItem;
	TEDIObject* __fastcall GetEDIObject(int Index);
	void __fastcall SetEDIObject(int Index, const TEDIObject* Value);
	
public:
	__fastcall TEDIObjectList(bool OwnsObjects);
	__fastcall virtual ~TEDIObjectList(void);
	void __fastcall Add(TEDIObjectListItem* Item, AnsiString Name = "")/* overload */;
	TEDIObjectListItem* __fastcall Add(TEDIObject* EDIObject, AnsiString Name = "")/* overload */;
	virtual TEDIObjectListItem* __fastcall CreateListItem(TEDIObjectListItem* PriorItem, TEDIObject* EDIObject = (TEDIObject*)(0x0));
	TEDIObjectListItem* __fastcall Find(TEDIObjectListItem* Item)/* overload */;
	TEDIObjectListItem* __fastcall Find(TEDIObject* EDIObject)/* overload */;
	TEDIObject* __fastcall FindEDIObject(TEDIObject* EDIObject);
	virtual TEDIObjectListItem* __fastcall Extract(TEDIObjectListItem* Item)/* overload */;
	virtual TEDIObject* __fastcall Extract(TEDIObject* EDIObject)/* overload */;
	void __fastcall Remove(TEDIObjectListItem* Item)/* overload */;
	void __fastcall Remove(TEDIObject* EDIObject)/* overload */;
	TEDIObjectListItem* __fastcall Insert(TEDIObjectListItem* Item, TEDIObjectListItem* BeforeItem)/* overload */;
	TEDIObjectListItem* __fastcall Insert(TEDIObject* EDIObject, TEDIObject* BeforeEDIObject)/* overload */;
	TEDIObjectListItem* __fastcall Insert(TEDIObjectListItem* BeforeItem)/* overload */;
	TEDIObjectListItem* __fastcall Insert(TEDIObject* BeforeEDIObject)/* overload */;
	void __fastcall Clear(void);
	virtual TEDIObjectListItem* __fastcall First(int Index = 0x0);
	virtual TEDIObjectListItem* __fastcall Next(void);
	virtual TEDIObjectListItem* __fastcall Prior(void);
	virtual TEDIObjectListItem* __fastcall Last(void);
	void __fastcall UpdateCount(void);
	virtual TEDIObjectListItem* __fastcall FindItemByName(AnsiString Name, TEDIObjectListItem* StartItem = (TEDIObjectListItem*)(0x0));
	virtual TEDIObjectList* __fastcall ReturnListItemsByName(AnsiString Name);
	int __fastcall IndexOf(TEDIObjectListItem* Item)/* overload */;
	int __fastcall IndexOf(TEDIObject* EDIObject)/* overload */;
	bool __fastcall IndexIsValid(int Index);
	void __fastcall Insert(int InsertIndex, TEDIObject* EDIObject)/* overload */;
	void __fastcall Delete(int Index)/* overload */;
	void __fastcall Delete(TEDIObject* EDIObject)/* overload */;
	void __fastcall UpdateIndexes(TEDIObjectListItem* StartItem = (TEDIObjectListItem*)(0x0));
	__property TEDIObjectListItem* Item[int Index] = {read=GetItem};
	__property TEDIObject* EDIObject[int Index] = {read=GetEDIObject, write=SetEDIObject/*, default*/};
	
__published:
	__property int Count = {read=FCount, nodefault};
	__property bool OwnsObjects = {read=FOwnsObjects, write=FOwnsObjects, nodefault};
	__property TEDIDataObjectListOptions Options = {read=FOptions, write=FOptions, nodefault};
	__property TEDIObjectListItem* CurrentItem = {read=FCurrentItem};
};


class PASCALIMPLEMENTATION TEDIDataObjectList : public TEDIObjectList 
{
	typedef TEDIObjectList inherited;
	
public:
	TEDIDataObject* operator[](int Index) { return EDIDataObject[Index]; }
	
private:
	TEDIDataObject* __fastcall GetEDIDataObject(int Index);
	void __fastcall SetEDIDataObject(int Index, const TEDIDataObject* Value);
	
public:
	virtual TEDIObjectListItem* __fastcall CreateListItem(TEDIObjectListItem* PriorItem, TEDIObject* EDIObject = (TEDIObject*)(0x0));
	__property TEDIDataObject* EDIDataObject[int Index] = {read=GetEDIDataObject, write=SetEDIDataObject/*, default*/};
public:
	#pragma option push -w-inl
	/* TEDIObjectList.Create */ inline __fastcall TEDIDataObjectList(bool OwnsObjects) : TEDIObjectList(OwnsObjects) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TEDIObjectList.Destroy */ inline __fastcall virtual ~TEDIDataObjectList(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TEDIDataObjectGroup : public TEDIDataObject 
{
	typedef TEDIDataObject inherited;
	
public:
	TEDIDataObject* operator[](int Index) { return EDIDataObject[Index]; }
	
protected:
	bool FGroupIsParent;
	TEDIDataObjectList* FEDIDataObjects;
	TEDIDataObjectType FCreateObjectType;
	int __fastcall GetCount(void);
	TEDIDataObject* __fastcall GetEDIDataObject(int Index);
	void __fastcall SetEDIDataObject(int Index, TEDIDataObject* EDIDataObject);
	virtual TEDIDelimiters* __fastcall InternalAssignDelimiters(void) = 0 ;
	virtual TEDIDataObject* __fastcall InternalCreateEDIDataObject(void) = 0 ;
	
public:
	__fastcall TEDIDataObjectGroup(TEDIDataObject* Parent, int EDIDataObjectCount);
	__fastcall virtual ~TEDIDataObjectGroup(void);
	bool __fastcall IndexIsValid(int Index);
	int __fastcall AddEDIDataObject(void);
	int __fastcall AppendEDIDataObject(TEDIDataObject* EDIDataObject);
	int __fastcall InsertEDIDataObject(int InsertIndex)/* overload */;
	int __fastcall InsertEDIDataObject(int InsertIndex, TEDIDataObject* EDIDataObject)/* overload */;
	void __fastcall DeleteEDIDataObject(int Index)/* overload */;
	void __fastcall DeleteEDIDataObject(TEDIDataObject* EDIDataObject)/* overload */;
	int __fastcall AddEDIDataObjects(int Count);
	int __fastcall AppendEDIDataObjects(TEDIDataObjectArray EDIDataObjectArray);
	int __fastcall InsertEDIDataObjects(int InsertIndex, int Count)/* overload */;
	int __fastcall InsertEDIDataObjects(int InsertIndex, TEDIDataObjectArray EDIDataObjectArray)/* overload */;
	void __fastcall DeleteEDIDataObjects(void)/* overload */;
	void __fastcall DeleteEDIDataObjects(int Index, int Count)/* overload */;
	virtual int __fastcall GetIndexPositionFromParent(void);
	__property TEDIDataObject* EDIDataObject[int Index] = {read=GetEDIDataObject, write=SetEDIDataObject/*, default*/};
	__property TEDIDataObjectList* EDIDataObjects = {read=FEDIDataObjects};
	
__published:
	__property TEDIDataObjectType CreateObjectType = {read=FCreateObjectType, nodefault};
	__property int EDIDataObjectCount = {read=GetCount, nodefault};
};


typedef DynamicArray<TEDIDataObjectGroup* >  TEDIDataObjectGroupArray;

class PASCALIMPLEMENTATION TEDIObjectListItem : public TEDIObject 
{
	typedef TEDIObject inherited;
	
protected:
	TEDIObjectList* FParent;
	TEDIObjectListItem* FPriorItem;
	TEDIObjectListItem* FNextItem;
	TEDIObject* FEDIObject;
	int FItemIndex;
	AnsiString FName;
	
public:
	__fastcall TEDIObjectListItem(TEDIObjectList* Parent, TEDIObjectListItem* PriorItem, TEDIObject* EDIObject);
	__fastcall virtual ~TEDIObjectListItem(void);
	int __fastcall GetIndexPositionFromParent(void);
	void __fastcall FreeAndNilEDIDataObject(void);
	
__published:
	__property int ItemIndex = {read=FItemIndex, write=FItemIndex, nodefault};
	__property TEDIObjectListItem* PriorItem = {read=FPriorItem, write=FPriorItem};
	__property TEDIObjectListItem* NextItem = {read=FNextItem, write=FNextItem};
	__property TEDIObject* EDIObject = {read=FEDIObject, write=FEDIObject};
	__property AnsiString Name = {read=FName, write=FName};
	__property TEDIObjectList* Parent = {read=FParent, write=FParent};
};


class DELPHICLASS TEDIDataObjectListItem;
class PASCALIMPLEMENTATION TEDIDataObjectListItem : public TEDIObjectListItem 
{
	typedef TEDIObjectListItem inherited;
	
private:
	TEDIDataObject* __fastcall GetEDIDataObject(void);
	void __fastcall SetEDIDataObject(const TEDIDataObject* Value);
	
__published:
	__property TEDIDataObject* EDIDataObject = {read=GetEDIDataObject, write=SetEDIDataObject};
public:
	#pragma option push -w-inl
	/* TEDIObjectListItem.Create */ inline __fastcall TEDIDataObjectListItem(TEDIObjectList* Parent, TEDIObjectListItem* PriorItem, TEDIObject* EDIObject) : TEDIObjectListItem(Parent, PriorItem, EDIObject) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TEDIObjectListItem.Destroy */ inline __fastcall virtual ~TEDIDataObjectListItem(void) { }
	#pragma option pop
	
};


struct TEDILoopStackRecord
{
	
public:
	AnsiString SegmentId;
	int SpecStartIndex;
	AnsiString OwnerLoopId;
	AnsiString ParentLoopId;
	TEDIObject* EDIObject;
	TEDIObject* EDISpecObject;
} ;

typedef DynamicArray<TEDILoopStackRecord >  TEDILoopStackArray;

#pragma option push -b-
enum TEDILoopStackFlags { ediAltStackPointer, ediStackResized, ediLoopRepeated };
#pragma option pop

typedef Set<TEDILoopStackFlags, ediAltStackPointer, ediLoopRepeated>  TEDILoopStackFlagSet;

typedef void __fastcall (__closure *TEDILoopStackOnAddLoopEvent)(const TEDILoopStackRecord &StackRecord, AnsiString SegmentId, AnsiString OwnerLoopId, AnsiString ParentLoopId, TEDIObject* &EDIObject);

class DELPHICLASS TEDILoopStack;
class PASCALIMPLEMENTATION TEDILoopStack : public TEDIObject 
{
	typedef TEDIObject inherited;
	
private:
	int __fastcall GetSize(void);
	
protected:
	DynamicArray<TEDILoopStackRecord >  FStack;
	TEDILoopStackFlagSet FFlags;
	bool FCheckAssignedEDIObject;
	TEDILoopStackOnAddLoopEvent FOnAddLoop;
	void __fastcall DoAddLoop(const TEDILoopStackRecord &StackRecord, AnsiString SegmentId, AnsiString OwnerLoopId, AnsiString ParentLoopId, TEDIObject* &EDIObject);
	
public:
	__fastcall TEDILoopStack(void);
	__fastcall virtual ~TEDILoopStack(void);
	TEDILoopStackRecord __fastcall Peek()/* overload */;
	TEDILoopStackRecord __fastcall Peek(int Index)/* overload */;
	void __fastcall Pop(int Index);
	int __fastcall Push(AnsiString SegmentId, AnsiString OwnerLoopId, AnsiString ParentLoopId, int StartIndex, TEDIObject* EDIObject);
	int __fastcall GetSafeStackIndex(int Index);
	int __fastcall SetStackPointer(AnsiString OwnerLoopId, AnsiString ParentLoopId);
	void __fastcall UpdateStackObject(TEDIObject* EDIObject);
	void __fastcall UpdateStackData(AnsiString SegmentId, AnsiString OwnerLoopId, AnsiString ParentLoopId, int StartIndex, TEDIObject* EDIObject);
	TEDILoopStackRecord __fastcall ValidateLoopStack(AnsiString SegmentId, AnsiString OwnerLoopId, AnsiString ParentLoopId, int StartIndex, TEDIObject* EDIObject);
	AnsiString __fastcall Debug();
	__property TEDILoopStackArray Stack = {read=FStack};
	
__published:
	__property int Size = {read=GetSize, nodefault};
	__property TEDILoopStackFlagSet Flags = {read=FFlags, write=FFlags, nodefault};
	__property TEDILoopStackOnAddLoopEvent OnAddLoop = {read=FOnAddLoop, write=FOnAddLoop};
};


//-- var, const, procedure ---------------------------------------------------
#define NA_LoopId "N/A"
#define ElementSpecId_Reserved "Reserved"
static const char EDIDataType_Numeric = '\x4e';
static const char EDIDataType_Decimal = '\x52';
#define EDIDataType_Identifier "ID"
#define EDIDataType_String "AN"
#define EDIDataType_Date "DT"
#define EDIDataType_Time "TM"
static const char EDIDataType_Binary = '\x42';
extern PACKAGE System::TResStringRec *EDIErrors[58];
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE AnsiString __fastcall StringRemove(const AnsiString S, const AnsiString Pattern, Sysutils::TReplaceFlags Flags);
extern PACKAGE AnsiString __fastcall StringReplace(const AnsiString S, const AnsiString OldPattern, const AnsiString NewPattern, Sysutils::TReplaceFlags Flags);

}	/* namespace Jcledi */
using namespace Jcledi;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcledi
