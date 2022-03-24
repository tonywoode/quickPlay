// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcledisef.pas' rev: 10.00

#ifndef JcledisefHPP
#define JcledisefHPP

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
#include <Jclbase.hpp>	// Pascal unit
#include <Jcledi.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jcledisef
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TEDISEFComsUserAttributes { caPeriod, caExclamationPoint, caDollarSign, caHyphen, caAmpersand };
#pragma option pop

class DELPHICLASS TEDISEFObject;
class PASCALIMPLEMENTATION TEDISEFObject : public Jcledi::TEDIObject 
{
	typedef Jcledi::TEDIObject inherited;
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TEDISEFObject(void) : Jcledi::TEDIObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TEDISEFObject(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TEDISEFObjectParentType { sefNil, sefList, sefElement, sefCompositeElement, sefSegment };
#pragma option pop

class DELPHICLASS TEDISEFDataObject;
class DELPHICLASS TEDISEFFile;
class DELPHICLASS TEDISEFDataObjectListItem;
class PASCALIMPLEMENTATION TEDISEFDataObjectListItem : public Jcledi::TEDIObjectListItem 
{
	typedef Jcledi::TEDIObjectListItem inherited;
	
private:
	TEDISEFDataObject* __fastcall GetEDISEFDataObject(void);
	void __fastcall SetEDISEFDataObject(const TEDISEFDataObject* Value);
	
public:
	void __fastcall LinkToObject(void);
	void __fastcall UpdateName(void);
	HIDESBASE TEDISEFDataObjectListItem* __fastcall NextItem(void);
	HIDESBASE TEDISEFDataObjectListItem* __fastcall PriorItem(void);
	
__published:
	__property TEDISEFDataObject* EDISEFDataObject = {read=GetEDISEFDataObject, write=SetEDISEFDataObject};
public:
	#pragma option push -w-inl
	/* TEDIObjectListItem.Create */ inline __fastcall TEDISEFDataObjectListItem(Jcledi::TEDIObjectList* Parent, Jcledi::TEDIObjectListItem* PriorItem, Jcledi::TEDIObject* EDIObject) : Jcledi::TEDIObjectListItem(Parent, PriorItem, EDIObject) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TEDIObjectListItem.Destroy */ inline __fastcall virtual ~TEDISEFDataObjectListItem(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TEDISEFDataObject : public TEDISEFObject 
{
	typedef TEDISEFObject inherited;
	
private:
	void __fastcall SetId(const AnsiString Value);
	
protected:
	Jcledi::TEDIDataObjectDataState FState;
	AnsiString FId;
	AnsiString FData;
	int FLength;
	TEDISEFDataObject* FParent;
	TEDISEFFile* FSEFFile;
	Classes::TStrings* FErrorLog;
	TEDISEFDataObjectListItem* FOwnerItemRef;
	AnsiString __fastcall GetData();
	void __fastcall SetData(const AnsiString Data);
	virtual void __fastcall SetParent(const TEDISEFDataObject* Value);
	__property TEDISEFDataObjectListItem* OwnerItemRef = {read=FOwnerItemRef, write=FOwnerItemRef};
	virtual TEDISEFDataObject* __fastcall CloneDataObject(TEDISEFDataObject* NewParent) = 0 ;
	
public:
	__fastcall TEDISEFDataObject(TEDISEFDataObject* Parent);
	__fastcall virtual ~TEDISEFDataObject(void);
	virtual AnsiString __fastcall Assemble(void) = 0 ;
	virtual void __fastcall Disassemble(void) = 0 ;
	void __fastcall UpdateOwnerItemName(void);
	TEDISEFDataObject* __fastcall Clone(TEDISEFDataObject* NewParent);
	
__published:
	__property Jcledi::TEDIDataObjectDataState State = {read=FState, nodefault};
	__property AnsiString Id = {read=FId, write=SetId};
	__property AnsiString Data = {read=GetData, write=SetData};
	__property int DataLength = {read=FLength, nodefault};
	__property TEDISEFDataObject* Parent = {read=FParent, write=SetParent};
	__property TEDISEFFile* SEFFile = {read=FSEFFile, write=FSEFFile};
};


class DELPHICLASS TEDISEFTextSets;
class PASCALIMPLEMENTATION TEDISEFTextSets : public Jcledi::TEDIObjectList 
{
	typedef Jcledi::TEDIObjectList inherited;
	
public:
	AnsiString __fastcall GetText(AnsiString Code);
	void __fastcall SetText(TEDISEFFile* EDISEFFile, AnsiString Location, AnsiString Code, AnsiString Text);
public:
	#pragma option push -w-inl
	/* TEDIObjectList.Create */ inline __fastcall TEDISEFTextSets(bool OwnsObjects) : Jcledi::TEDIObjectList(OwnsObjects) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TEDIObjectList.Destroy */ inline __fastcall virtual ~TEDISEFTextSets(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEDISEFDataObjectList;
class PASCALIMPLEMENTATION TEDISEFDataObjectList : public Jcledi::TEDIObjectList 
{
	typedef Jcledi::TEDIObjectList inherited;
	
public:
	TEDISEFDataObject* operator[](int Index) { return EDISEFDataObject[Index]; }
	
private:
	TEDISEFDataObject* __fastcall GetEDISEFDataObject(int Index);
	void __fastcall SetEDISEFDataObject(int Index, const TEDISEFDataObject* Value);
	
public:
	virtual Jcledi::TEDIObjectListItem* __fastcall CreateListItem(Jcledi::TEDIObjectListItem* PriorItem, Jcledi::TEDIObject* EDIObject = (Jcledi::TEDIObject*)(0x0));
	HIDESBASE TEDISEFDataObjectListItem* __fastcall First(int Index = 0x0);
	HIDESBASE TEDISEFDataObjectListItem* __fastcall Next(void);
	HIDESBASE TEDISEFDataObjectListItem* __fastcall Prior(void);
	HIDESBASE TEDISEFDataObjectListItem* __fastcall Last(void);
	HIDESBASE TEDISEFDataObjectListItem* __fastcall Add(TEDISEFDataObject* EDISEFDataObject, AnsiString Name = "")/* overload */;
	HIDESBASE TEDISEFDataObjectListItem* __fastcall Insert(TEDISEFDataObject* EDISEFDataObject, TEDISEFDataObject* BeforeEDISEFDataObject)/* overload */;
	HIDESBASE TEDISEFDataObjectListItem* __fastcall FindItemByName(AnsiString Name, Jcledi::TEDIObjectListItem* StartItem = (Jcledi::TEDIObjectListItem*)(0x0));
	TEDISEFDataObject* __fastcall GetObjectByItemByName(AnsiString Name);
	__property TEDISEFDataObject* EDISEFDataObject[int Index] = {read=GetEDISEFDataObject, write=SetEDISEFDataObject/*, default*/};
public:
	#pragma option push -w-inl
	/* TEDIObjectList.Create */ inline __fastcall TEDISEFDataObjectList(bool OwnsObjects) : Jcledi::TEDIObjectList(OwnsObjects) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TEDIObjectList.Destroy */ inline __fastcall virtual ~TEDISEFDataObjectList(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Add(Jcledi::TEDIObjectListItem* Item, AnsiString Name = ""){ TEDIObjectList::Add(Item, Name); }
	inline Jcledi::TEDIObjectListItem* __fastcall  Add(Jcledi::TEDIObject* EDIObject, AnsiString Name = ""){ return TEDIObjectList::Add(EDIObject, Name); }
	inline Jcledi::TEDIObjectListItem* __fastcall  Insert(Jcledi::TEDIObjectListItem* Item, Jcledi::TEDIObjectListItem* BeforeItem){ return TEDIObjectList::Insert(Item, BeforeItem); }
	inline Jcledi::TEDIObjectListItem* __fastcall  Insert(Jcledi::TEDIObject* EDIObject, Jcledi::TEDIObject* BeforeEDIObject){ return TEDIObjectList::Insert(EDIObject, BeforeEDIObject); }
	inline Jcledi::TEDIObjectListItem* __fastcall  Insert(Jcledi::TEDIObjectListItem* BeforeItem){ return TEDIObjectList::Insert(BeforeItem); }
	inline Jcledi::TEDIObjectListItem* __fastcall  Insert(Jcledi::TEDIObject* BeforeEDIObject){ return TEDIObjectList::Insert(BeforeEDIObject); }
	inline void __fastcall  Insert(int InsertIndex, Jcledi::TEDIObject* EDIObject){ TEDIObjectList::Insert(InsertIndex, EDIObject); }
	
};


class PASCALIMPLEMENTATION TEDISEFFile : public TEDISEFDataObject 
{
	typedef TEDISEFDataObject inherited;
	
private:
	AnsiString FFileName;
	TEDISEFTextSets* FEDISEFTextSets;
	Classes::TStringList* FEDISEFCodesList;
	TEDISEFDataObjectList* FEDISEFElms;
	TEDISEFDataObjectList* FEDISEFComs;
	TEDISEFDataObjectList* FEDISEFSegs;
	TEDISEFDataObjectList* FEDISEFSets;
	Classes::TStringList* FEDISEFStd;
	Classes::TStringList* FEDISEFIni;
	AnsiString FEDISEFVer;
	void __fastcall ParseTextSets(void);
	void __fastcall ParseCodes(void);
	void __fastcall ParseELMS(void);
	void __fastcall ParseCOMS(void);
	void __fastcall ParseSEGS(void);
	void __fastcall ParseSETS(void);
	void __fastcall ParseSTD(void);
	void __fastcall ParseINI(void);
	void __fastcall ParseVER(void);
	Classes::TStrings* __fastcall GetEDISEFCodesList(void);
	Classes::TStrings* __fastcall GetEDISEFStd(void);
	Classes::TStrings* __fastcall GetEDISEFIni(void);
	
protected:
	virtual TEDISEFDataObject* __fastcall CloneDataObject(TEDISEFDataObject* NewParent);
	
public:
	__fastcall TEDISEFFile(TEDISEFDataObject* Parent);
	__fastcall virtual ~TEDISEFFile(void);
	void __fastcall LoadFromFile(void)/* overload */;
	void __fastcall LoadFromFile(const AnsiString FileName)/* overload */;
	void __fastcall SaveToFile(void)/* overload */;
	void __fastcall SaveToFile(const AnsiString FileName)/* overload */;
	void __fastcall Unload(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	HIDESBASE TEDISEFFile* __fastcall Clone(TEDISEFDataObject* NewParent);
	
__published:
	__property AnsiString FileName = {read=FFileName, write=FFileName};
	__property Classes::TStrings* Codes = {read=GetEDISEFCodesList};
	__property TEDISEFDataObjectList* ELMS = {read=FEDISEFElms};
	__property TEDISEFDataObjectList* COMS = {read=FEDISEFComs};
	__property TEDISEFDataObjectList* SEGS = {read=FEDISEFSegs};
	__property TEDISEFDataObjectList* SETS = {read=FEDISEFSets};
	__property Classes::TStrings* STD = {read=GetEDISEFStd};
	__property Classes::TStrings* INI = {read=GetEDISEFIni};
	__property AnsiString VER = {read=FEDISEFVer, write=FEDISEFVer};
	__property TEDISEFTextSets* TEXTSETS = {read=FEDISEFTextSets};
};



typedef TMetaClass* TEDISEFDataObjectClass;

class DELPHICLASS TEDISEFDataObjectGroup;
class PASCALIMPLEMENTATION TEDISEFDataObjectGroup : public TEDISEFDataObject 
{
	typedef TEDISEFDataObject inherited;
	
public:
	TEDISEFDataObject* operator[](int Index) { return EDISEFDataObject[Index]; }
	
private:
	TEDISEFDataObject* __fastcall GetEDISEFDataObject(int Index);
	int __fastcall GetCount(void);
	
protected:
	TEDISEFDataObjectList* FEDISEFDataObjects;
	
public:
	__fastcall TEDISEFDataObjectGroup(TEDISEFDataObject* Parent);
	__fastcall virtual ~TEDISEFDataObjectGroup(void);
	__property TEDISEFDataObject* EDISEFDataObject[int Index] = {read=GetEDISEFDataObject/*, default*/};
	
__published:
	__property TEDISEFDataObjectList* EDISEFDataObjects = {read=FEDISEFDataObjects};
	__property int EDISEFDataObjectCount = {read=GetCount, nodefault};
};


class DELPHICLASS TEDISEFRepeatingPattern;
class PASCALIMPLEMENTATION TEDISEFRepeatingPattern : public TEDISEFDataObjectGroup 
{
	typedef TEDISEFDataObjectGroup inherited;
	
private:
	TEDISEFDataObject* FBaseParent;
	int FRepeatCount;
	
protected:
	virtual void __fastcall SetParent(const TEDISEFDataObject* Value);
	virtual TEDISEFDataObject* __fastcall CloneDataObject(TEDISEFDataObject* NewParent);
	
public:
	__fastcall TEDISEFRepeatingPattern(TEDISEFDataObject* Parent);
	__fastcall virtual ~TEDISEFRepeatingPattern(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	HIDESBASE TEDISEFRepeatingPattern* __fastcall Clone(TEDISEFDataObject* NewParent);
	TEDISEFRepeatingPattern* __fastcall AddRepeatingPattern(void);
	TEDISEFRepeatingPattern* __fastcall AppendRepeatingPattern(TEDISEFRepeatingPattern* RepeatingPattern);
	TEDISEFRepeatingPattern* __fastcall ExtractRepeatingPattern(TEDISEFRepeatingPattern* RepeatingPattern);
	void __fastcall DeleteRepeatingPattern(TEDISEFRepeatingPattern* RepeatingPattern);
	TEDISEFRepeatingPattern* __fastcall InsertRepeatingPattern(TEDISEFDataObject* BeforeObject)/* overload */;
	TEDISEFRepeatingPattern* __fastcall InsertRepeatingPattern(TEDISEFRepeatingPattern* RepeatingPattern, TEDISEFDataObject* BeforeObject)/* overload */;
	
__published:
	__property TEDISEFDataObject* BaseParent = {read=FBaseParent};
	__property int RepeatCount = {read=FRepeatCount, write=FRepeatCount, nodefault};
};


#pragma option push -b-
enum TEDISEFWhereType { twUnknown, twSet, twSegment, twElementOrCompositeElement, twSubElement };
#pragma option pop

class DELPHICLASS TEDISEFText;
class PASCALIMPLEMENTATION TEDISEFText : public Jcledi::TEDIObject 
{
	typedef Jcledi::TEDIObject inherited;
	
private:
	Classes::TStringList* FWhereLocation;
	AnsiString __fastcall GetText();
	void __fastcall SetText(const AnsiString Value);
	AnsiString __fastcall GetDescription();
	Classes::TStrings* __fastcall GetWhereLocation(void);
	
protected:
	AnsiString FData;
	TEDISEFWhereType FEDISEFWhereType;
	AnsiString FWhere;
	AnsiString FWhat;
	AnsiString FText;
	AnsiString __fastcall GetData();
	void __fastcall SetData(const AnsiString Value);
	
public:
	__fastcall TEDISEFText(void);
	__fastcall virtual ~TEDISEFText(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	
__published:
	__property AnsiString Data = {read=GetData, write=SetData};
	__property Classes::TStrings* WhereLocation = {read=GetWhereLocation};
	__property AnsiString Where = {read=FWhere};
	__property AnsiString What = {read=FWhat};
	__property AnsiString Text = {read=GetText, write=SetText};
	__property AnsiString Description = {read=GetDescription};
};


class DELPHICLASS TEDISEFTextSet;
class PASCALIMPLEMENTATION TEDISEFTextSet : public TEDISEFText 
{
	typedef TEDISEFText inherited;
	
private:
	AnsiString FWhereSet;
	int FWhereSegment;
	int FWhereElement;
	int FWhereSubElement;
	
public:
	__fastcall TEDISEFTextSet(void);
	__fastcall virtual ~TEDISEFTextSet(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
};


class DELPHICLASS TEDISEFElement;
class DELPHICLASS TEDISEFSubElement;
class PASCALIMPLEMENTATION TEDISEFElement : public TEDISEFDataObject 
{
	typedef TEDISEFDataObject inherited;
	
protected:
	AnsiString FUserAttribute;
	int FOrdinal;
	bool FOutOfSequenceOrdinal;
	AnsiString FElementType;
	int FMinimumLength;
	int FMaximumLength;
	AnsiString FRequirementDesignator;
	int FRepeatCount;
	TEDISEFTextSets* FEDISEFTextSets;
	virtual TEDISEFDataObject* __fastcall CloneDataObject(TEDISEFDataObject* NewParent);
	
public:
	__fastcall TEDISEFElement(TEDISEFDataObject* Parent);
	__fastcall virtual ~TEDISEFElement(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	void __fastcall Assign(TEDISEFElement* EDISEFElement);
	HIDESBASE TEDISEFElement* __fastcall Clone(TEDISEFDataObject* NewParent);
	TEDISEFSubElement* __fastcall CloneAsSubElement(TEDISEFDataObject* NewParent);
	AnsiString __fastcall GetTextSetsLocation();
	void __fastcall BindTextSets(TEDISEFTextSets* TEXTSETS);
	
__published:
	__property AnsiString UserAttribute = {read=FUserAttribute, write=FUserAttribute};
	__property int Ordinal = {read=FOrdinal, write=FOrdinal, nodefault};
	__property bool OutOfSequenceOrdinal = {read=FOutOfSequenceOrdinal, write=FOutOfSequenceOrdinal, nodefault};
	__property AnsiString ElementId = {read=FId, write=FId};
	__property AnsiString ElementType = {read=FElementType, write=FElementType};
	__property int MinimumLength = {read=FMinimumLength, write=FMinimumLength, nodefault};
	__property int MaximumLength = {read=FMaximumLength, write=FMaximumLength, nodefault};
	__property AnsiString RequirementDesignator = {read=FRequirementDesignator, write=FRequirementDesignator};
	__property int RepeatCount = {read=FRepeatCount, write=FRepeatCount, nodefault};
	__property AnsiString TextSetsLocation = {read=GetTextSetsLocation};
	__property TEDISEFTextSets* TEXTSETS = {read=FEDISEFTextSets};
};


class PASCALIMPLEMENTATION TEDISEFSubElement : public TEDISEFElement 
{
	typedef TEDISEFElement inherited;
	
protected:
	virtual TEDISEFDataObject* __fastcall CloneDataObject(TEDISEFDataObject* NewParent);
	
public:
	__fastcall TEDISEFSubElement(TEDISEFDataObject* Parent);
	__fastcall virtual ~TEDISEFSubElement(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	HIDESBASE TEDISEFSubElement* __fastcall Clone(TEDISEFDataObject* NewParent);
};


class DELPHICLASS TEDISEFCompositeElement;
class PASCALIMPLEMENTATION TEDISEFCompositeElement : public TEDISEFDataObjectGroup 
{
	typedef TEDISEFDataObjectGroup inherited;
	
private:
	AnsiString FUserAttribute;
	int FOrdinal;
	bool FOutOfSequenceOrdinal;
	AnsiString FRequirementDesignator;
	int FRepeatCount;
	AnsiString FExtendedData;
	TEDISEFTextSets* FEDISEFTextSets;
	
protected:
	virtual TEDISEFDataObject* __fastcall CloneDataObject(TEDISEFDataObject* NewParent);
	
public:
	__fastcall TEDISEFCompositeElement(TEDISEFDataObject* Parent);
	__fastcall virtual ~TEDISEFCompositeElement(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	void __fastcall Assign(TEDISEFCompositeElement* CompositeElement);
	HIDESBASE TEDISEFCompositeElement* __fastcall Clone(TEDISEFDataObject* NewParent);
	Contnrs::TObjectList* __fastcall GetElementObjectList(void);
	void __fastcall AssignElementOrdinals(void);
	AnsiString __fastcall GetTextSetsLocation();
	void __fastcall BindTextSets(TEDISEFTextSets* TEXTSETS);
	TEDISEFSubElement* __fastcall AddSubElement(void);
	TEDISEFSubElement* __fastcall AppendSubElement(TEDISEFSubElement* SubElement);
	TEDISEFSubElement* __fastcall ExtractSubElement(TEDISEFSubElement* SubElement);
	void __fastcall DeleteSubElement(TEDISEFSubElement* SubElement);
	TEDISEFSubElement* __fastcall InsertSubElement(TEDISEFDataObject* BeforeObject)/* overload */;
	TEDISEFSubElement* __fastcall InsertSubElement(TEDISEFSubElement* SubElement, TEDISEFDataObject* BeforeObject)/* overload */;
	TEDISEFRepeatingPattern* __fastcall AddRepeatingPattern(void);
	TEDISEFRepeatingPattern* __fastcall AppendRepeatingPattern(TEDISEFRepeatingPattern* RepeatingPattern);
	TEDISEFRepeatingPattern* __fastcall ExtractRepeatingPattern(TEDISEFRepeatingPattern* RepeatingPattern);
	void __fastcall DeleteRepeatingPattern(TEDISEFRepeatingPattern* RepeatingPattern);
	TEDISEFRepeatingPattern* __fastcall InsertRepeatingPattern(TEDISEFDataObject* BeforeObject)/* overload */;
	TEDISEFRepeatingPattern* __fastcall InsertRepeatingPattern(TEDISEFRepeatingPattern* RepeatingPattern, TEDISEFDataObject* BeforeObject)/* overload */;
	
__published:
	__property AnsiString UserAttribute = {read=FUserAttribute, write=FUserAttribute};
	__property int Ordinal = {read=FOrdinal, write=FOrdinal, nodefault};
	__property bool OutOfSequenceOrdinal = {read=FOutOfSequenceOrdinal, write=FOutOfSequenceOrdinal, nodefault};
	__property AnsiString CompositeElementId = {read=FId, write=FId};
	__property AnsiString RequirementDesignator = {read=FRequirementDesignator, write=FRequirementDesignator};
	__property int RepeatCount = {read=FRepeatCount, write=FRepeatCount, nodefault};
	__property TEDISEFDataObjectList* Elements = {read=FEDISEFDataObjects};
	__property AnsiString TextSetsLocation = {read=GetTextSetsLocation};
	__property TEDISEFTextSets* TEXTSETS = {read=FEDISEFTextSets};
};


class DELPHICLASS TEDISEFSegment;
class DELPHICLASS TEDISEFSet;
class DELPHICLASS TEDISEFTable;
class DELPHICLASS TEDISEFLoop;
class PASCALIMPLEMENTATION TEDISEFSet : public TEDISEFDataObjectGroup 
{
	typedef TEDISEFDataObjectGroup inherited;
	
private:
	TEDISEFTextSets* FEDISEFTextSets;
	TEDISEFTable* __fastcall GetEDISEFTable(int Index);
	void __fastcall BuildSegmentObjectListFromLoop(Contnrs::TObjectList* ObjectList, TEDISEFLoop* Loop);
	
protected:
	virtual TEDISEFDataObject* __fastcall CloneDataObject(TEDISEFDataObject* NewParent);
	
public:
	__fastcall TEDISEFSet(TEDISEFDataObject* Parent);
	__fastcall virtual ~TEDISEFSet(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	HIDESBASE TEDISEFSet* __fastcall Clone(TEDISEFDataObject* NewParent);
	Contnrs::TObjectList* __fastcall GetSegmentObjectList(void);
	void __fastcall AssignSegmentOrdinals(void);
	void __fastcall AssignSegmentPositions(void);
	void __fastcall BindSegmentTextSets(void);
	AnsiString __fastcall GetTextSetsLocation();
	void __fastcall BindTextSets(TEDISEFTextSets* TEXTSETS);
	TEDISEFTable* __fastcall AddTable(void);
	TEDISEFTable* __fastcall AppendTable(TEDISEFTable* Table);
	TEDISEFTable* __fastcall ExtractTable(TEDISEFTable* Table);
	void __fastcall DeleteTable(TEDISEFTable* Table);
	TEDISEFTable* __fastcall InsertTable(TEDISEFTable* BeforeTable)/* overload */;
	TEDISEFTable* __fastcall InsertTable(TEDISEFTable* Table, TEDISEFTable* BeforeTable)/* overload */;
	__property TEDISEFTable* Table[int Index] = {read=GetEDISEFTable};
	
__published:
	__property TEDISEFDataObjectList* Tables = {read=FEDISEFDataObjects};
	__property AnsiString TextSetsLocation = {read=GetTextSetsLocation};
	__property TEDISEFTextSets* TEXTSETS = {read=FEDISEFTextSets};
};


class PASCALIMPLEMENTATION TEDISEFSegment : public TEDISEFDataObjectGroup 
{
	typedef TEDISEFDataObjectGroup inherited;
	
private:
	AnsiString FUserAttribute;
	int FPosition;
	int FPositionIncrement;
	bool FResetPositionInc;
	int FOrdinal;
	bool FOutOfSequenceOrdinal;
	AnsiString FRequirementDesignator;
	int FMaximumUse;
	AnsiString FOwnerLoopId;
	AnsiString FParentLoopId;
	TEDISEFSet* FParentSet;
	TEDISEFTable* FParentTable;
	TEDISEFTextSets* FEDISEFTextSets;
	int FMaskNumber;
	bool FMaskNumberSpecified;
	AnsiString FExtendedData;
	AnsiString __fastcall GetOwnerLoopId();
	AnsiString __fastcall GetParentLoopId();
	
protected:
	virtual TEDISEFDataObject* __fastcall CloneDataObject(TEDISEFDataObject* NewParent);
	
public:
	__fastcall TEDISEFSegment(TEDISEFDataObject* Parent);
	__fastcall virtual ~TEDISEFSegment(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	void __fastcall Assign(TEDISEFSegment* Segment);
	HIDESBASE TEDISEFSegment* __fastcall Clone(TEDISEFDataObject* NewParent);
	Contnrs::TObjectList* __fastcall GetElementObjectList(void);
	void __fastcall AssignElementOrdinals(void);
	void __fastcall BindElementTextSets(void);
	AnsiString __fastcall GetTextSetsLocation();
	void __fastcall BindTextSets(TEDISEFTextSets* TEXTSETS);
	TEDISEFElement* __fastcall AddElement(void);
	TEDISEFElement* __fastcall AppendElement(TEDISEFElement* Element);
	TEDISEFElement* __fastcall ExtractElement(TEDISEFElement* Element);
	void __fastcall DeleteElement(TEDISEFElement* Element);
	TEDISEFElement* __fastcall InsertElement(TEDISEFDataObject* BeforeObject)/* overload */;
	TEDISEFElement* __fastcall InsertElement(TEDISEFElement* Element, TEDISEFDataObject* BeforeObject)/* overload */;
	TEDISEFCompositeElement* __fastcall AddCompositeElement(void);
	TEDISEFCompositeElement* __fastcall AppendCompositeElement(TEDISEFCompositeElement* CompositeElement);
	TEDISEFCompositeElement* __fastcall ExtractCompositeElement(TEDISEFCompositeElement* CompositeElement);
	void __fastcall DeleteCompositeElement(TEDISEFCompositeElement* CompositeElement);
	TEDISEFCompositeElement* __fastcall InsertCompositeElement(TEDISEFDataObject* BeforeObject)/* overload */;
	TEDISEFCompositeElement* __fastcall InsertCompositeElement(TEDISEFCompositeElement* CompositeElement, TEDISEFDataObject* BeforeObject)/* overload */;
	TEDISEFRepeatingPattern* __fastcall AddRepeatingPattern(void);
	TEDISEFRepeatingPattern* __fastcall AppendRepeatingPattern(TEDISEFRepeatingPattern* RepeatingPattern);
	TEDISEFRepeatingPattern* __fastcall ExtractRepeatingPattern(TEDISEFRepeatingPattern* RepeatingPattern);
	void __fastcall DeleteRepeatingPattern(TEDISEFRepeatingPattern* RepeatingPattern);
	TEDISEFRepeatingPattern* __fastcall InsertRepeatingPattern(TEDISEFDataObject* BeforeObject)/* overload */;
	TEDISEFRepeatingPattern* __fastcall InsertRepeatingPattern(TEDISEFRepeatingPattern* RepeatingPattern, TEDISEFDataObject* BeforeObject)/* overload */;
	
__published:
	__property AnsiString UserAttribute = {read=FUserAttribute, write=FUserAttribute};
	__property int Position = {read=FPosition, write=FPosition, nodefault};
	__property int PositionIncrement = {read=FPositionIncrement, write=FPositionIncrement, nodefault};
	__property bool ResetPositionInc = {read=FResetPositionInc, write=FResetPositionInc, nodefault};
	__property int Ordinal = {read=FOrdinal, write=FOrdinal, nodefault};
	__property bool OutOfSequenceOrdinal = {read=FOutOfSequenceOrdinal, write=FOutOfSequenceOrdinal, nodefault};
	__property AnsiString SegmentId = {read=FId, write=FId};
	__property AnsiString RequirementDesignator = {read=FRequirementDesignator, write=FRequirementDesignator};
	__property int MaximumUse = {read=FMaximumUse, write=FMaximumUse, nodefault};
	__property TEDISEFDataObjectList* Elements = {read=FEDISEFDataObjects};
	__property AnsiString OwnerLoopId = {read=GetOwnerLoopId};
	__property AnsiString ParentLoopId = {read=GetParentLoopId};
	__property AnsiString TextSetsLocation = {read=GetTextSetsLocation};
	__property TEDISEFSet* ParentSet = {read=FParentSet};
	__property TEDISEFTable* ParentTable = {read=FParentTable};
	__property TEDISEFTextSets* TEXTSETS = {read=FEDISEFTextSets};
};


class PASCALIMPLEMENTATION TEDISEFLoop : public TEDISEFDataObjectGroup 
{
	typedef TEDISEFDataObjectGroup inherited;
	
private:
	int FMaximumRepeat;
	AnsiString __fastcall GetParentLoopId();
	TEDISEFSet* __fastcall GetParentSet(void);
	TEDISEFTable* __fastcall GetParentTable(void);
	
protected:
	virtual TEDISEFDataObject* __fastcall CloneDataObject(TEDISEFDataObject* NewParent);
	
public:
	__fastcall TEDISEFLoop(TEDISEFDataObject* Parent);
	__fastcall virtual ~TEDISEFLoop(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	HIDESBASE TEDISEFLoop* __fastcall Clone(TEDISEFDataObject* NewParent);
	TEDISEFSegment* __fastcall AddSegment(void);
	TEDISEFSegment* __fastcall AppendSegment(TEDISEFSegment* Segment);
	TEDISEFSegment* __fastcall ExtractSegment(TEDISEFSegment* Segment);
	void __fastcall DeleteSegment(TEDISEFSegment* Segment);
	TEDISEFSegment* __fastcall InsertSegment(TEDISEFDataObject* BeforeObject)/* overload */;
	TEDISEFSegment* __fastcall InsertSegment(TEDISEFSegment* Segment, TEDISEFDataObject* BeforeObject)/* overload */;
	TEDISEFLoop* __fastcall AddLoop(void);
	TEDISEFLoop* __fastcall AppendLoop(TEDISEFLoop* Loop);
	TEDISEFLoop* __fastcall ExtractLoop(TEDISEFLoop* Loop);
	void __fastcall DeleteLoop(TEDISEFLoop* Loop);
	TEDISEFLoop* __fastcall InsertLoop(TEDISEFDataObject* BeforeObject)/* overload */;
	TEDISEFLoop* __fastcall InsertLoop(TEDISEFLoop* Loop, TEDISEFDataObject* BeforeObject)/* overload */;
	
__published:
	__property AnsiString LoopId = {read=FId, write=FId};
	__property int MaximumRepeat = {read=FMaximumRepeat, write=FMaximumRepeat, nodefault};
	__property AnsiString ParentLoopId = {read=GetParentLoopId};
	__property TEDISEFSet* ParentSet = {read=GetParentSet};
	__property TEDISEFTable* ParentTable = {read=GetParentTable};
};


class PASCALIMPLEMENTATION TEDISEFTable : public TEDISEFDataObjectGroup 
{
	typedef TEDISEFDataObjectGroup inherited;
	
private:
	TEDISEFSet* __fastcall GetSEFSet(void);
	
protected:
	virtual TEDISEFDataObject* __fastcall CloneDataObject(TEDISEFDataObject* NewParent);
	
public:
	__fastcall TEDISEFTable(TEDISEFDataObject* Parent);
	__fastcall virtual ~TEDISEFTable(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	HIDESBASE TEDISEFTable* __fastcall Clone(TEDISEFDataObject* NewParent);
	TEDISEFSegment* __fastcall AddSegment(void);
	TEDISEFSegment* __fastcall AppendSegment(TEDISEFSegment* Segment);
	TEDISEFSegment* __fastcall ExtractSegment(TEDISEFSegment* Segment);
	void __fastcall DeleteSegment(TEDISEFSegment* Segment);
	TEDISEFSegment* __fastcall InsertSegment(TEDISEFDataObject* BeforeObject)/* overload */;
	TEDISEFSegment* __fastcall InsertSegment(TEDISEFSegment* Segment, TEDISEFDataObject* BeforeObject)/* overload */;
	TEDISEFLoop* __fastcall AddLoop(void);
	TEDISEFLoop* __fastcall AppendLoop(TEDISEFLoop* Loop);
	TEDISEFLoop* __fastcall ExtractLoop(TEDISEFLoop* Loop);
	void __fastcall DeleteLoop(TEDISEFLoop* Loop);
	TEDISEFLoop* __fastcall InsertLoop(TEDISEFDataObject* BeforeObject)/* overload */;
	TEDISEFLoop* __fastcall InsertLoop(TEDISEFLoop* Loop, TEDISEFDataObject* BeforeObject)/* overload */;
	
__published:
	__property TEDISEFSet* SEFSet = {read=GetSEFSet};
};


//-- var, const, procedure ---------------------------------------------------
#define SectionTag_VER ".VER"
#define SectionTag_INI ".INI"
#define SectionTag_PRIVATE ""
#define SectionTag_PUBLIC ""
#define SectionTag_STD ".STD"
#define SectionTag_SETS ".SETS"
#define SectionTag_SEGS ".SEGS"
#define SectionTag_COMS ".COMS"
#define SectionTag_ELMS ".ELMS"
#define SectionTag_CODES ".CODES"
#define SectionTag_VALLISTS ""
#define SectionTag_OBJVARS ""
#define SectionTag_SEMREFS ""
#define SectionTag_TEXT ""
#define SectionTag_TEXTSETS ".TEXT,SETS"
#define SectionTag_ ""
#define SectionTag_JCL_SETSEXT ".SETSEXT"
#define SectionTag_JCL_SEGSEXT ".SEGSEXT"
#define SectionTag_JCL_COMSEXT ".COMSEXT"
#define SectionTag_JCL_ELMSEXT ".ELMSEXT"
static const int Value_UndefinedMaximum = 2147483647;
static const char EDISEFUserAttributePeriod = '\x2e';
static const char EDISEFUserAttributeExclamationPoint = '\x21';
static const char EDISEFUserAttributeDollarSign = '\x24';
static const char EDISEFUserAttributeHyphen = '\x2d';
static const char EDISEFUserAttributeAmpersand = '\x26';
#define EDISEFUserAttributePeriodDesc "Not Used"
#define EDISEFUserAttributeExclamationPointDesc "Mandatory"
#define EDISEFUserAttributeDollarSignDesc "Recommended"
#define EDISEFUserAttributeHyphenDesc "Not Recommended"
#define EDISEFUserAttributeAmpersandDesc "Dependent"
#define SEFTextCR "\\r"
#define SEFTextLF "\\n"
#define SEFTextCRLF "\\r\\n"
static const char SEFTextSetsCode_Set0 = '\x30';
static const char SEFTextSetsCode_Set1 = '\x31';
static const char SEFTextSetsCode_Set2 = '\x32';
static const char SEFTextSetsCode_Set3 = '\x33';
static const char SEFTextSetsCode_Set4 = '\x34';
static const char SEFTextSetsCode_Set5 = '\x35';
static const char SEFTextSetsCode_Seg0 = '\x30';
static const char SEFTextSetsCode_Seg1 = '\x31';
static const char SEFTextSetsCode_Seg2 = '\x32';
static const char SEFTextSetsCode_Seg3 = '\x33';
static const char SEFTextSetsCode_Seg4 = '\x34';
static const char SEFTextSetsCode_Seg5 = '\x35';
static const char SEFTextSetsCode_Seg6 = '\x36';
static const char SEFTextSetsCode_Seg7 = '\x37';
static const char SEFTextSetsCode_Elm0 = '\x30';
static const char SEFTextSetsCode_Elm1 = '\x31';
static const char SEFTextSetsCode_Elm2 = '\x32';
static const char SEFTextSetsCode_Elm4 = '\x34';
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE bool __fastcall CharIsUserAttribute(const char C);
extern PACKAGE AnsiString __fastcall GetEDISEFUserAttributeDescription(TEDISEFComsUserAttributes Attribute)/* overload */;
extern PACKAGE AnsiString __fastcall GetEDISEFUserAttributeDescription(AnsiString Attribute)/* overload */;
extern PACKAGE void __fastcall ParseELMSDataOfELMSDefinition(AnsiString Data, TEDISEFElement* Element);
extern PACKAGE AnsiString __fastcall CombineELMSDataOfELMSDefinition(TEDISEFElement* Element);
extern PACKAGE void __fastcall ParseELMSDataOfCOMSDefinition(AnsiString Data, TEDISEFElement* Element, TEDISEFDataObjectList* ELMSList);
extern PACKAGE AnsiString __fastcall CombineELMSDataOfCOMSorSEGSDefinition(TEDISEFElement* Element, TEDISEFDataObjectList* ELMSList);
extern PACKAGE void __fastcall ParseELMSDataOfSEGSDefinition(AnsiString Data, TEDISEFElement* Element, TEDISEFDataObjectList* ELMSList);
extern PACKAGE void __fastcall ParseCOMSDataOfCOMSDefinition(AnsiString Data, TEDISEFCompositeElement* CompositeElement, TEDISEFDataObjectList* ELMSList);
extern PACKAGE AnsiString __fastcall CombineCOMSDataOfCOMSDefinition(TEDISEFCompositeElement* CompositeElement);
extern PACKAGE void __fastcall ParseCOMSDataOfSEGSDefinition(AnsiString Data, TEDISEFCompositeElement* CompositeElement, TEDISEFDataObjectList* COMSList);
extern PACKAGE AnsiString __fastcall CombineCOMSDataOfSEGSDefinition(TEDISEFCompositeElement* CompositeElement);
extern PACKAGE void __fastcall ParseSEGSDataOfSEGSDefinition(AnsiString Data, TEDISEFSegment* Segment, TEDISEFFile* SEFFile);
extern PACKAGE AnsiString __fastcall CombineSEGSDataOfSEGSDefinition(TEDISEFSegment* Segment);
extern PACKAGE void __fastcall ParseSEGSDataOfSETSDefinition(AnsiString Data, TEDISEFSegment* Segment, TEDISEFFile* SEFFile);
extern PACKAGE AnsiString __fastcall CombineSEGSDataOfSETSDefinition(TEDISEFSegment* Segment);
extern PACKAGE void __fastcall ParseLoopDataOfSETSDefinition(AnsiString Data, TEDISEFLoop* Loop, TEDISEFFile* SEFFile);
extern PACKAGE void __fastcall ParseTableDataOfSETSDefinition(AnsiString Data, TEDISEFTable* Table, TEDISEFFile* SEFFile);
extern PACKAGE void __fastcall ParseSetsDataOfSETSDefinition(AnsiString Data, TEDISEFSet* ASet, TEDISEFFile* SEFFile);
extern PACKAGE void __fastcall ExtractFromDataObjectGroup(TMetaClass* DataObjectClass, TEDISEFDataObjectGroup* DataObjectGroup, Contnrs::TObjectList* ObjectList)/* overload */;
extern PACKAGE void __fastcall ExtractFromDataObjectGroup(TMetaClass* * DataObjectClasses, const int DataObjectClasses_Size, TEDISEFDataObjectGroup* DataObjectGroup, Contnrs::TObjectList* ObjectList)/* overload */;
extern PACKAGE TEDISEFSubElement* __fastcall AddSubElementTo(TEDISEFDataObjectGroup* DataObjectGroup);
extern PACKAGE TEDISEFSubElement* __fastcall AppendSubElementTo(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFSubElement* SubElement);
extern PACKAGE TEDISEFSubElement* __fastcall ExtractSubElementFrom(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFSubElement* SubElement);
extern PACKAGE void __fastcall DeleteSubElementFrom(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFSubElement* SubElement);
extern PACKAGE TEDISEFSubElement* __fastcall InsertSubElementInto(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFDataObject* BeforeObject)/* overload */;
extern PACKAGE TEDISEFSubElement* __fastcall InsertSubElementInto(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFSubElement* SubElement, TEDISEFDataObject* BeforeObject)/* overload */;
extern PACKAGE TEDISEFElement* __fastcall AddElementTo(TEDISEFDataObjectGroup* DataObjectGroup);
extern PACKAGE TEDISEFElement* __fastcall AppendElementTo(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFElement* Element);
extern PACKAGE TEDISEFElement* __fastcall ExtractElementFrom(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFElement* Element);
extern PACKAGE void __fastcall DeleteElementFrom(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFElement* Element);
extern PACKAGE TEDISEFElement* __fastcall InsertElementInto(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFDataObject* BeforeObject)/* overload */;
extern PACKAGE TEDISEFElement* __fastcall InsertElementInto(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFElement* Element, TEDISEFDataObject* BeforeObject)/* overload */;
extern PACKAGE TEDISEFRepeatingPattern* __fastcall AddRepeatingPatternTo(TEDISEFDataObjectGroup* DataObjectGroup);
extern PACKAGE TEDISEFRepeatingPattern* __fastcall AppendRepeatingPatternTo(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFRepeatingPattern* RepeatingPattern);
extern PACKAGE TEDISEFRepeatingPattern* __fastcall ExtractRepeatingPatternFrom(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFRepeatingPattern* RepeatingPattern);
extern PACKAGE void __fastcall DeleteRepeatingPatternFrom(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFRepeatingPattern* RepeatingPattern);
extern PACKAGE TEDISEFRepeatingPattern* __fastcall InsertRepeatingPatternInto(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFDataObject* BeforeObject)/* overload */;
extern PACKAGE TEDISEFRepeatingPattern* __fastcall InsertRepeatingPatternInto(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFRepeatingPattern* RepeatingPattern, TEDISEFDataObject* BeforeObject)/* overload */;
extern PACKAGE TEDISEFCompositeElement* __fastcall AddCompositeElementTo(TEDISEFDataObjectGroup* DataObjectGroup);
extern PACKAGE TEDISEFCompositeElement* __fastcall AppendCompositeElementTo(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFCompositeElement* CompositeElement);
extern PACKAGE TEDISEFCompositeElement* __fastcall ExtractCompositeElementFrom(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFCompositeElement* CompositeElement);
extern PACKAGE void __fastcall DeleteCompositeElementFrom(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFCompositeElement* CompositeElement);
extern PACKAGE TEDISEFCompositeElement* __fastcall InsertCompositeElementInto(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFDataObject* BeforeObject)/* overload */;
extern PACKAGE TEDISEFCompositeElement* __fastcall InsertCompositeElementInto(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFCompositeElement* CompositeElement, TEDISEFDataObject* BeforeObject)/* overload */;
extern PACKAGE TEDISEFSegment* __fastcall AddSegmentTo(TEDISEFDataObjectGroup* DataObjectGroup);
extern PACKAGE TEDISEFSegment* __fastcall AppendSegmentTo(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFSegment* Segment);
extern PACKAGE TEDISEFSegment* __fastcall ExtractSegmentFrom(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFSegment* Segment);
extern PACKAGE void __fastcall DeleteSegmentFrom(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFSegment* Segment);
extern PACKAGE TEDISEFSegment* __fastcall InsertSegmentInto(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFDataObject* BeforeObject)/* overload */;
extern PACKAGE TEDISEFSegment* __fastcall InsertSegmentInto(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFSegment* Segment, TEDISEFDataObject* BeforeObject)/* overload */;
extern PACKAGE TEDISEFLoop* __fastcall AddLoopTo(TEDISEFDataObjectGroup* DataObjectGroup);
extern PACKAGE TEDISEFLoop* __fastcall AppendLoopTo(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFLoop* Loop);
extern PACKAGE TEDISEFLoop* __fastcall ExtractLoopFrom(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFLoop* Loop);
extern PACKAGE void __fastcall DeleteLoopFrom(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFLoop* Loop);
extern PACKAGE TEDISEFLoop* __fastcall InsertLoopInto(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFDataObject* BeforeObject)/* overload */;
extern PACKAGE TEDISEFLoop* __fastcall InsertLoopInto(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFLoop* Loop, TEDISEFDataObject* BeforeObject)/* overload */;
extern PACKAGE TEDISEFTable* __fastcall AddTableTo(TEDISEFDataObjectGroup* DataObjectGroup);
extern PACKAGE TEDISEFTable* __fastcall AppendTableTo(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFTable* Table);
extern PACKAGE TEDISEFTable* __fastcall ExtractTableFrom(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFTable* Table);
extern PACKAGE void __fastcall DeleteTableFrom(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFTable* Table);
extern PACKAGE TEDISEFTable* __fastcall InsertTableInto(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFDataObject* BeforeObject)/* overload */;
extern PACKAGE TEDISEFTable* __fastcall InsertTableInto(TEDISEFDataObjectGroup* DataObjectGroup, TEDISEFTable* Table, TEDISEFDataObject* BeforeObject)/* overload */;

}	/* namespace Jcledisef */
using namespace Jcledisef;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcledisef
