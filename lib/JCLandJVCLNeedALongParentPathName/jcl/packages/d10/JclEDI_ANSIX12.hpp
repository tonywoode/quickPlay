// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcledi_ansix12.pas' rev: 10.00

#ifndef Jcledi_ansix12HPP
#define Jcledi_ansix12HPP

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
#include <Jcledi.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jcledi_ansix12
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TEDIElement;
class PASCALIMPLEMENTATION TEDIElement : public Jcledi::TEDIDataObject 
{
	typedef Jcledi::TEDIDataObject inherited;
	
public:
	__fastcall TEDIElement(Jcledi::TEDIDataObject* Parent);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	int __fastcall GetIndexPositionFromParent(void);
public:
	#pragma option push -w-inl
	/* TEDIDataObject.Destroy */ inline __fastcall virtual ~TEDIElement(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TEDIElement* >  TEDIElementArray;

class DELPHICLASS TEDIElementSpec;
class PASCALIMPLEMENTATION TEDIElementSpec : public TEDIElement 
{
	typedef TEDIElement inherited;
	
private:
	Classes::TStringList* FReservedData;
	AnsiString FElementId;
	int FPosition;
	AnsiString FDescription;
	AnsiString FNotes;
	AnsiString FRequirementDesignator;
	AnsiString FType;
	int FMinimumLength;
	int FMaximumLength;
	Classes::TStrings* __fastcall GetReservedData(void);
	
public:
	__fastcall TEDIElementSpec(Jcledi::TEDIDataObject* Parent);
	__fastcall virtual ~TEDIElementSpec(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	
__published:
	__property Classes::TStrings* ReservedData = {read=GetReservedData};
	__property AnsiString Id = {read=FElementId, write=FElementId};
	__property AnsiString ElementId = {read=FElementId, write=FElementId};
	__property int Position = {read=FPosition, write=FPosition, nodefault};
	__property AnsiString Description = {read=FDescription, write=FDescription};
	__property AnsiString Notes = {read=FNotes, write=FNotes};
	__property AnsiString RequirementDesignator = {read=FRequirementDesignator, write=FRequirementDesignator};
	__property AnsiString ElementType = {read=FType, write=FType};
	__property int MinimumLength = {read=FMinimumLength, write=FMinimumLength, nodefault};
	__property int MaximumLength = {read=FMaximumLength, write=FMaximumLength, nodefault};
};


class DELPHICLASS TEDISegment;
class PASCALIMPLEMENTATION TEDISegment : public Jcledi::TEDIDataObjectGroup 
{
	typedef Jcledi::TEDIDataObjectGroup inherited;
	
public:
	TEDIElement* operator[](int Index) { return Element[Index]; }
	
private:
	TEDIElement* __fastcall GetElement(int Index);
	void __fastcall SetElement(int Index, TEDIElement* Element);
	
protected:
	AnsiString FSegmentId;
	virtual TEDIElement* __fastcall InternalCreateElement(void);
	virtual Jcledi::TEDIDelimiters* __fastcall InternalAssignDelimiters(void);
	virtual Jcledi::TEDIDataObject* __fastcall InternalCreateEDIDataObject(void);
	
public:
	__fastcall TEDISegment(Jcledi::TEDIDataObject* Parent, int ElementCount);
	__fastcall virtual ~TEDISegment(void);
	int __fastcall AddElement(void);
	int __fastcall AppendElement(TEDIElement* Element);
	int __fastcall InsertElement(int InsertIndex)/* overload */;
	int __fastcall InsertElement(int InsertIndex, TEDIElement* Element)/* overload */;
	void __fastcall DeleteElement(int Index)/* overload */;
	void __fastcall DeleteElement(TEDIElement* Element)/* overload */;
	int __fastcall AddElements(int Count);
	int __fastcall AppendElements(TEDIElementArray ElementArray);
	int __fastcall InsertElements(int InsertIndex, int Count)/* overload */;
	int __fastcall InsertElements(int InsertIndex, TEDIElementArray ElementArray)/* overload */;
	void __fastcall DeleteElements(void)/* overload */;
	void __fastcall DeleteElements(int Index, int Count)/* overload */;
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	__property TEDIElement* Element[int Index] = {read=GetElement, write=SetElement/*, default*/};
	__property Jcledi::TEDIDataObjectList* Elements = {read=FEDIDataObjects};
	
__published:
	__property AnsiString SegmentId = {read=FSegmentId, write=FSegmentId};
	__property int ElementCount = {read=GetCount, nodefault};
};


typedef DynamicArray<TEDISegment* >  TEDISegmentArray;

class DELPHICLASS TEDITransactionSetSegment;
class PASCALIMPLEMENTATION TEDITransactionSetSegment : public TEDISegment 
{
	typedef TEDISegment inherited;
	
protected:
	virtual Jcledi::TEDIDelimiters* __fastcall InternalAssignDelimiters(void);
	
public:
	__fastcall TEDITransactionSetSegment(Jcledi::TEDIDataObject* Parent, int ElementCount);
public:
	#pragma option push -w-inl
	/* TEDISegment.Destroy */ inline __fastcall virtual ~TEDITransactionSetSegment(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEDIFunctionalGroupSegment;
class PASCALIMPLEMENTATION TEDIFunctionalGroupSegment : public TEDISegment 
{
	typedef TEDISegment inherited;
	
protected:
	virtual Jcledi::TEDIDelimiters* __fastcall InternalAssignDelimiters(void);
	
public:
	__fastcall TEDIFunctionalGroupSegment(Jcledi::TEDIDataObject* Parent, int ElementCount);
public:
	#pragma option push -w-inl
	/* TEDISegment.Destroy */ inline __fastcall virtual ~TEDIFunctionalGroupSegment(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEDIInterchangeControlSegment;
class PASCALIMPLEMENTATION TEDIInterchangeControlSegment : public TEDISegment 
{
	typedef TEDISegment inherited;
	
protected:
	virtual Jcledi::TEDIDelimiters* __fastcall InternalAssignDelimiters(void);
	
public:
	__fastcall TEDIInterchangeControlSegment(Jcledi::TEDIDataObject* Parent, int ElementCount);
public:
	#pragma option push -w-inl
	/* TEDISegment.Destroy */ inline __fastcall virtual ~TEDIInterchangeControlSegment(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEDISegmentSpec;
class PASCALIMPLEMENTATION TEDISegmentSpec : public TEDISegment 
{
	typedef TEDISegment inherited;
	
private:
	Classes::TStringList* FReservedData;
	int FPosition;
	AnsiString FDescription;
	AnsiString FNotes;
	AnsiString FSection;
	AnsiString FRequirementDesignator;
	int FMaximumUsage;
	AnsiString FOwnerLoopId;
	AnsiString FParentLoopId;
	Classes::TStrings* __fastcall GetReservedData(void);
	
protected:
	virtual TEDIElement* __fastcall InternalCreateElement(void);
	
public:
	__fastcall TEDISegmentSpec(Jcledi::TEDIDataObject* Parent, int ElementCount);
	__fastcall virtual ~TEDISegmentSpec(void);
	virtual void __fastcall AssembleReservedData(Classes::TStrings* ReservedData);
	virtual void __fastcall DisassembleReservedData(Classes::TStrings* ReservedData);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	void __fastcall ValidateElementIndexPositions(void);
	
__published:
	__property Classes::TStrings* ReservedData = {read=GetReservedData};
	__property AnsiString Id = {read=FSegmentId, write=FSegmentId};
	__property int Position = {read=FPosition, write=FPosition, nodefault};
	__property AnsiString Description = {read=FDescription, write=FDescription};
	__property AnsiString Notes = {read=FNotes, write=FNotes};
	__property AnsiString Section = {read=FSection, write=FSection};
	__property AnsiString RequirementDesignator = {read=FRequirementDesignator, write=FRequirementDesignator};
	__property int MaximumUsage = {read=FMaximumUsage, write=FMaximumUsage, nodefault};
	__property AnsiString OwnerLoopId = {read=FOwnerLoopId, write=FOwnerLoopId};
	__property AnsiString ParentLoopId = {read=FParentLoopId, write=FParentLoopId};
};


class DELPHICLASS TEDITransactionSetSegmentSpec;
class PASCALIMPLEMENTATION TEDITransactionSetSegmentSpec : public TEDISegmentSpec 
{
	typedef TEDISegmentSpec inherited;
	
protected:
	virtual Jcledi::TEDIDelimiters* __fastcall InternalAssignDelimiters(void);
	
public:
	__fastcall TEDITransactionSetSegmentSpec(Jcledi::TEDIDataObject* Parent, int ElementCount);
public:
	#pragma option push -w-inl
	/* TEDISegmentSpec.Destroy */ inline __fastcall virtual ~TEDITransactionSetSegmentSpec(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEDITransactionSetSegmentSTSpec;
class PASCALIMPLEMENTATION TEDITransactionSetSegmentSTSpec : public TEDITransactionSetSegmentSpec 
{
	typedef TEDITransactionSetSegmentSpec inherited;
	
public:
	__fastcall TEDITransactionSetSegmentSTSpec(Jcledi::TEDIDataObject* Parent, int ElementCount);
	virtual void __fastcall AssembleReservedData(Classes::TStrings* ReservedData);
	virtual void __fastcall DisassembleReservedData(Classes::TStrings* ReservedData);
public:
	#pragma option push -w-inl
	/* TEDISegmentSpec.Destroy */ inline __fastcall virtual ~TEDITransactionSetSegmentSTSpec(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEDIFunctionalGroupSegmentSpec;
class PASCALIMPLEMENTATION TEDIFunctionalGroupSegmentSpec : public TEDISegmentSpec 
{
	typedef TEDISegmentSpec inherited;
	
protected:
	virtual Jcledi::TEDIDelimiters* __fastcall InternalAssignDelimiters(void);
	
public:
	__fastcall TEDIFunctionalGroupSegmentSpec(Jcledi::TEDIDataObject* Parent, int ElementCount);
public:
	#pragma option push -w-inl
	/* TEDISegmentSpec.Destroy */ inline __fastcall virtual ~TEDIFunctionalGroupSegmentSpec(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEDIFunctionalGroupSegmentGSSpec;
class PASCALIMPLEMENTATION TEDIFunctionalGroupSegmentGSSpec : public TEDIFunctionalGroupSegmentSpec 
{
	typedef TEDIFunctionalGroupSegmentSpec inherited;
	
public:
	__fastcall TEDIFunctionalGroupSegmentGSSpec(Jcledi::TEDIDataObject* Parent, int ElementCount);
	virtual void __fastcall AssembleReservedData(Classes::TStrings* ReservedData);
	virtual void __fastcall DisassembleReservedData(Classes::TStrings* ReservedData);
public:
	#pragma option push -w-inl
	/* TEDISegmentSpec.Destroy */ inline __fastcall virtual ~TEDIFunctionalGroupSegmentGSSpec(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEDIInterchangeControlSegmentSpec;
class PASCALIMPLEMENTATION TEDIInterchangeControlSegmentSpec : public TEDISegmentSpec 
{
	typedef TEDISegmentSpec inherited;
	
protected:
	virtual Jcledi::TEDIDelimiters* __fastcall InternalAssignDelimiters(void);
	
public:
	__fastcall TEDIInterchangeControlSegmentSpec(Jcledi::TEDIDataObject* Parent, int ElementCount);
public:
	#pragma option push -w-inl
	/* TEDISegmentSpec.Destroy */ inline __fastcall virtual ~TEDIInterchangeControlSegmentSpec(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEDIInterchangeControlSegmentISASpec;
class PASCALIMPLEMENTATION TEDIInterchangeControlSegmentISASpec : public TEDIInterchangeControlSegmentSpec 
{
	typedef TEDIInterchangeControlSegmentSpec inherited;
	
public:
	__fastcall TEDIInterchangeControlSegmentISASpec(Jcledi::TEDIDataObject* Parent, int ElementCount);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	virtual void __fastcall AssembleReservedData(Classes::TStrings* ReservedData);
	virtual void __fastcall DisassembleReservedData(Classes::TStrings* ReservedData);
public:
	#pragma option push -w-inl
	/* TEDISegmentSpec.Destroy */ inline __fastcall virtual ~TEDIInterchangeControlSegmentISASpec(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEDITransactionSet;
class PASCALIMPLEMENTATION TEDITransactionSet : public Jcledi::TEDIDataObjectGroup 
{
	typedef Jcledi::TEDIDataObjectGroup inherited;
	
public:
	TEDISegment* operator[](int Index) { return Segment[Index]; }
	
private:
	TEDISegment* FSTSegment;
	TEDISegment* FSESegment;
	TEDISegment* __fastcall GetSegment(int Index);
	void __fastcall SetSegment(int Index, TEDISegment* Segment);
	void __fastcall SetSTSegment(TEDISegment* STSegment);
	void __fastcall SetSESegment(TEDISegment* SESegment);
	
protected:
	virtual void __fastcall InternalCreateHeaderTrailerSegments(void);
	virtual TEDISegment* __fastcall InternalCreateSegment(void);
	virtual Jcledi::TEDIDelimiters* __fastcall InternalAssignDelimiters(void);
	virtual Jcledi::TEDIDataObject* __fastcall InternalCreateEDIDataObject(void);
	
public:
	__fastcall TEDITransactionSet(Jcledi::TEDIDataObject* Parent, int SegmentCount);
	__fastcall virtual ~TEDITransactionSet(void);
	int __fastcall AddSegment(void);
	int __fastcall AppendSegment(TEDISegment* Segment);
	int __fastcall InsertSegment(int InsertIndex)/* overload */;
	int __fastcall InsertSegment(int InsertIndex, TEDISegment* Segment)/* overload */;
	void __fastcall DeleteSegment(int Index)/* overload */;
	void __fastcall DeleteSegment(TEDISegment* Segment)/* overload */;
	int __fastcall AddSegments(int Count);
	int __fastcall AppendSegments(TEDISegmentArray SegmentArray);
	int __fastcall InsertSegments(int InsertIndex, int Count)/* overload */;
	int __fastcall InsertSegments(int InsertIndex, TEDISegmentArray SegmentArray)/* overload */;
	void __fastcall DeleteSegments(void)/* overload */;
	void __fastcall DeleteSegments(int Index, int Count)/* overload */;
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	__property TEDISegment* Segment[int Index] = {read=GetSegment, write=SetSegment/*, default*/};
	__property Jcledi::TEDIDataObjectList* Segments = {read=FEDIDataObjects};
	
__published:
	__property TEDISegment* SegmentST = {read=FSTSegment, write=SetSTSegment};
	__property TEDISegment* SegmentSE = {read=FSESegment, write=SetSESegment};
	__property int SegmentCount = {read=GetCount, nodefault};
};


typedef DynamicArray<TEDITransactionSet* >  TEDITransactionSetArray;

class DELPHICLASS TEDITransactionSetSpec;
class PASCALIMPLEMENTATION TEDITransactionSetSpec : public TEDITransactionSet 
{
	typedef TEDITransactionSet inherited;
	
private:
	AnsiString FTransactionSetId;
	AnsiString FTSDescription;
	
protected:
	virtual void __fastcall InternalCreateHeaderTrailerSegments(void);
	virtual TEDISegment* __fastcall InternalCreateSegment(void);
	
public:
	void __fastcall ValidateSegmentIndexPositions(void);
	
__published:
	__property AnsiString Id = {read=FTransactionSetId, write=FTransactionSetId};
	__property AnsiString TransactionSetId = {read=FTransactionSetId, write=FTransactionSetId};
	__property AnsiString TSDescription = {read=FTSDescription, write=FTSDescription};
public:
	#pragma option push -w-inl
	/* TEDITransactionSet.Create */ inline __fastcall TEDITransactionSetSpec(Jcledi::TEDIDataObject* Parent, int SegmentCount) : TEDITransactionSet(Parent, SegmentCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TEDITransactionSet.Destroy */ inline __fastcall virtual ~TEDITransactionSetSpec(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEDITransactionSetLoop;
class PASCALIMPLEMENTATION TEDITransactionSetLoop : public Jcledi::TEDIDataObjectGroup 
{
	typedef Jcledi::TEDIDataObjectGroup inherited;
	
protected:
	AnsiString FOwnerLoopId;
	AnsiString FParentLoopId;
	TEDITransactionSet* FParentTransactionSet;
	virtual Jcledi::TEDIDelimiters* __fastcall InternalAssignDelimiters(void);
	virtual Jcledi::TEDIDataObject* __fastcall InternalCreateEDIDataObject(void);
	
public:
	__fastcall TEDITransactionSetLoop(Jcledi::TEDIDataObject* Parent);
	__fastcall virtual ~TEDITransactionSetLoop(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	TEDITransactionSetLoop* __fastcall FindLoop(AnsiString LoopId, int &StartIndex);
	TEDISegment* __fastcall FindSegment(AnsiString SegmentId, int &StartIndex)/* overload */;
	TEDISegment* __fastcall FindSegment(AnsiString SegmentId, int &StartIndex, Classes::TStrings* ElementConditions)/* overload */;
	int __fastcall AddLoop(AnsiString OwnerLoopId, AnsiString ParentLoopId);
	void __fastcall AppendSegment(TEDISegment* Segment);
	HIDESBASE void __fastcall DeleteEDIDataObjects(void);
	
__published:
	__property AnsiString OwnerLoopId = {read=FOwnerLoopId, write=FOwnerLoopId};
	__property AnsiString ParentLoopId = {read=FParentLoopId, write=FParentLoopId};
	__property TEDITransactionSet* ParentTransactionSet = {read=FParentTransactionSet, write=FParentTransactionSet};
};


#pragma option push -b-
enum JclEDI_ANSIX12__71 { doLinkSpecToDataObject };
#pragma option pop

typedef Set<JclEDI_ANSIX12__71, doLinkSpecToDataObject, doLinkSpecToDataObject>  TEDITransactionSetDocumentOptions;

class DELPHICLASS TEDITransactionSetDocument;
class PASCALIMPLEMENTATION TEDITransactionSetDocument : public TEDITransactionSetLoop 
{
	typedef TEDITransactionSetLoop inherited;
	
protected:
	bool FErrorOccured;
	TEDITransactionSetDocumentOptions FEDITSDOptions;
	Jcledi::TEDILoopStack* FEDILoopStack;
	TEDITransactionSet* FEDITransactionSet;
	TEDITransactionSetSpec* FEDITransactionSetSpec;
	int __fastcall ValidateSegSpecIndex(AnsiString DataSegmentId, int SpecStartIndex);
	int __fastcall AdvanceSegSpecIndex(int DataIndex, int SpecStartIndex, int SpecEndIndex);
	void __fastcall AddLoopToDoc(const Jcledi::TEDILoopStackRecord &StackRecord, AnsiString SegmentId, AnsiString OwnerLoopId, AnsiString ParentLoopId, Jcledi::TEDIObject* &EDIObject);
	void __fastcall SetSpecificationPointers(TEDISegment* DataSegment, TEDISegment* SpecSegment);
	virtual void __fastcall ValidateData(TEDITransactionSetDocument* TSDocument, Jcledi::TEDILoopStack* LoopStack, TEDISegment* DataSegment, TEDISegment* SpecSegment, int &DataIndex, int &SpecIndex, bool &ErrorOccured);
	
public:
	__fastcall TEDITransactionSetDocument(Jcledi::TEDIDataObject* Parent, TEDITransactionSet* EDITransactionSet, TEDITransactionSetSpec* EDITransactionSetSpec);
	__fastcall virtual ~TEDITransactionSetDocument(void);
	virtual void __fastcall FormatDocument(void);
	
__published:
	__property TEDITransactionSetDocumentOptions EDITSDOptions = {read=FEDITSDOptions, write=FEDITSDOptions, nodefault};
	__property bool ErrorOccured = {read=FErrorOccured, nodefault};
};


typedef DynamicArray<TEDITransactionSetDocument* >  TEDITransactionSetDocumentArray;

class DELPHICLASS TEDIFunctionalGroup;
class PASCALIMPLEMENTATION TEDIFunctionalGroup : public Jcledi::TEDIDataObjectGroup 
{
	typedef Jcledi::TEDIDataObjectGroup inherited;
	
public:
	TEDITransactionSet* operator[](int Index) { return TransactionSet[Index]; }
	
private:
	TEDISegment* FGSSegment;
	TEDISegment* FGESegment;
	TEDITransactionSet* __fastcall GetTransactionSet(int Index);
	void __fastcall SetTransactionSet(int Index, TEDITransactionSet* TransactionSet);
	void __fastcall SetGSSegment(const TEDISegment* GSSegment);
	void __fastcall SetGESegment(const TEDISegment* GESegment);
	
protected:
	virtual void __fastcall InternalCreateHeaderTrailerSegments(void);
	virtual TEDITransactionSet* __fastcall InternalCreateTransactionSet(void);
	virtual Jcledi::TEDIDelimiters* __fastcall InternalAssignDelimiters(void);
	virtual Jcledi::TEDIDataObject* __fastcall InternalCreateEDIDataObject(void);
	
public:
	__fastcall TEDIFunctionalGroup(Jcledi::TEDIDataObject* Parent, int TransactionSetCount);
	__fastcall virtual ~TEDIFunctionalGroup(void);
	int __fastcall AddTransactionSet(void);
	int __fastcall AppendTransactionSet(TEDITransactionSet* TransactionSet);
	int __fastcall InsertTransactionSet(int InsertIndex)/* overload */;
	int __fastcall InsertTransactionSet(int InsertIndex, TEDITransactionSet* TransactionSet)/* overload */;
	void __fastcall DeleteTransactionSet(int Index)/* overload */;
	void __fastcall DeleteTransactionSet(TEDITransactionSet* TransactionSet)/* overload */;
	int __fastcall AddTransactionSets(int Count);
	int __fastcall AppendTransactionSets(TEDITransactionSetArray TransactionSetArray);
	int __fastcall InsertTransactionSets(int InsertIndex, int Count)/* overload */;
	int __fastcall InsertTransactionSets(int InsertIndex, TEDITransactionSetArray TransactionSetArray)/* overload */;
	void __fastcall DeleteTransactionSets(void)/* overload */;
	void __fastcall DeleteTransactionSets(int Index, int Count)/* overload */;
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	__property TEDITransactionSet* TransactionSet[int Index] = {read=GetTransactionSet, write=SetTransactionSet/*, default*/};
	__property Jcledi::TEDIDataObjectList* TransactionSets = {read=FEDIDataObjects};
	
__published:
	__property TEDISegment* SegmentGS = {read=FGSSegment, write=SetGSSegment};
	__property TEDISegment* SegmentGE = {read=FGESegment, write=SetGESegment};
	__property int TransactionSetCount = {read=GetCount, nodefault};
};


typedef DynamicArray<TEDIFunctionalGroup* >  TEDIFunctionalGroupArray;

class DELPHICLASS TEDIFunctionalGroupSpec;
class PASCALIMPLEMENTATION TEDIFunctionalGroupSpec : public TEDIFunctionalGroup 
{
	typedef TEDIFunctionalGroup inherited;
	
private:
	AnsiString FFunctionalGroupId;
	AnsiString FFGDescription;
	AnsiString FAgencyCodeId;
	AnsiString FVersionReleaseId;
	
protected:
	virtual void __fastcall InternalCreateHeaderTrailerSegments(void);
	virtual TEDITransactionSet* __fastcall InternalCreateTransactionSet(void);
	
public:
	TEDITransactionSetSpec* __fastcall FindTransactionSetSpec(AnsiString TransactionSetId);
	
__published:
	__property AnsiString Id = {read=FFunctionalGroupId, write=FFunctionalGroupId};
	__property AnsiString FunctionalGroupId = {read=FFunctionalGroupId, write=FFunctionalGroupId};
	__property AnsiString FGDescription = {read=FFGDescription, write=FFGDescription};
	__property AnsiString AgencyCodeId = {read=FAgencyCodeId, write=FAgencyCodeId};
	__property AnsiString VersionReleaseId = {read=FVersionReleaseId, write=FVersionReleaseId};
public:
	#pragma option push -w-inl
	/* TEDIFunctionalGroup.Create */ inline __fastcall TEDIFunctionalGroupSpec(Jcledi::TEDIDataObject* Parent, int TransactionSetCount) : TEDIFunctionalGroup(Parent, TransactionSetCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TEDIFunctionalGroup.Destroy */ inline __fastcall virtual ~TEDIFunctionalGroupSpec(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEDIInterchangeControl;
class PASCALIMPLEMENTATION TEDIInterchangeControl : public Jcledi::TEDIDataObjectGroup 
{
	typedef Jcledi::TEDIDataObjectGroup inherited;
	
public:
	TEDIFunctionalGroup* operator[](int Index) { return FunctionalGroup[Index]; }
	
private:
	TEDISegment* FISASegment;
	TEDISegment* FIEASegment;
	Jcledi::TEDIObjectList* FTA1Segments;
	TEDIFunctionalGroup* __fastcall GetFunctionalGroup(int Index);
	void __fastcall SetFunctionalGroup(int Index, TEDIFunctionalGroup* FunctionalGroup);
	void __fastcall SetISASegment(const TEDISegment* ISASegment);
	void __fastcall SetIEASegment(const TEDISegment* IEASegment);
	
protected:
	virtual void __fastcall InternalCreateHeaderTrailerSegments(void);
	virtual TEDIFunctionalGroup* __fastcall InternalCreateFunctionalGroup(void);
	virtual Jcledi::TEDIDelimiters* __fastcall InternalAssignDelimiters(void);
	virtual Jcledi::TEDIDataObject* __fastcall InternalCreateEDIDataObject(void);
	
public:
	__fastcall TEDIInterchangeControl(Jcledi::TEDIDataObject* Parent, int FunctionalGroupCount);
	__fastcall virtual ~TEDIInterchangeControl(void);
	int __fastcall AddFunctionalGroup(void);
	int __fastcall AppendFunctionalGroup(TEDIFunctionalGroup* FunctionalGroup);
	int __fastcall InsertFunctionalGroup(int InsertIndex)/* overload */;
	int __fastcall InsertFunctionalGroup(int InsertIndex, TEDIFunctionalGroup* FunctionalGroup)/* overload */;
	void __fastcall DeleteFunctionalGroup(int Index)/* overload */;
	void __fastcall DeleteFunctionalGroup(TEDIFunctionalGroup* FunctionalGroup)/* overload */;
	int __fastcall AddFunctionalGroups(int Count);
	int __fastcall AppendFunctionalGroups(TEDIFunctionalGroupArray FunctionalGroupArray);
	int __fastcall InsertFunctionalGroups(int InsertIndex, int Count)/* overload */;
	int __fastcall InsertFunctionalGroups(int InsertIndex, TEDIFunctionalGroupArray FunctionalGroupArray)/* overload */;
	void __fastcall DeleteFunctionalGroups(void)/* overload */;
	void __fastcall DeleteFunctionalGroups(int Index, int Count)/* overload */;
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	__property TEDIFunctionalGroup* FunctionalGroup[int Index] = {read=GetFunctionalGroup, write=SetFunctionalGroup/*, default*/};
	__property Jcledi::TEDIDataObjectList* FunctionalGroups = {read=FEDIDataObjects};
	
__published:
	__property TEDISegment* SegmentISA = {read=FISASegment, write=SetISASegment};
	__property TEDISegment* SegmentIEA = {read=FIEASegment, write=SetIEASegment};
	__property Jcledi::TEDIObjectList* TA1Segments = {read=FTA1Segments};
	__property int FunctionalGroupCount = {read=GetCount, nodefault};
};


typedef DynamicArray<TEDIInterchangeControl* >  TEDIInterchangeControlArray;

class DELPHICLASS TEDIInterchangeControlSpec;
class PASCALIMPLEMENTATION TEDIInterchangeControlSpec : public TEDIInterchangeControl 
{
	typedef TEDIInterchangeControl inherited;
	
private:
	AnsiString FStandardId;
	AnsiString FVersionId;
	AnsiString FICDescription;
	
protected:
	virtual void __fastcall InternalCreateHeaderTrailerSegments(void);
	virtual TEDIFunctionalGroup* __fastcall InternalCreateFunctionalGroup(void);
	
public:
	TEDIFunctionalGroupSpec* __fastcall FindFunctionalGroupSpec(AnsiString FunctionalGroupId, AnsiString AgencyCodeId, AnsiString VersionReleaseId);
	TEDITransactionSetSpec* __fastcall FindTransactionSetSpec(AnsiString FunctionalGroupId, AnsiString AgencyCodeId, AnsiString VersionReleaseId, AnsiString TransactionSetId);
	
__published:
	__property AnsiString StandardId = {read=FStandardId, write=FStandardId};
	__property AnsiString VersionId = {read=FVersionId, write=FVersionId};
	__property AnsiString ICDescription = {read=FICDescription, write=FICDescription};
public:
	#pragma option push -w-inl
	/* TEDIInterchangeControl.Create */ inline __fastcall TEDIInterchangeControlSpec(Jcledi::TEDIDataObject* Parent, int FunctionalGroupCount) : TEDIInterchangeControl(Parent, FunctionalGroupCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TEDIInterchangeControl.Destroy */ inline __fastcall virtual ~TEDIInterchangeControlSpec(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum JclEDI_ANSIX12__32 { foVariableDelimiterDetection, foUseAltDelimiterDetection, foRemoveCrLf, foRemoveCr, foRemoveLf, foIgnoreGarbageAtEndOfFile };
#pragma option pop

typedef Set<JclEDI_ANSIX12__32, foVariableDelimiterDetection, foIgnoreGarbageAtEndOfFile>  TEDIFileOptions;

class DELPHICLASS TEDIFile;
class PASCALIMPLEMENTATION TEDIFile : public Jcledi::TEDIDataObjectGroup 
{
	typedef Jcledi::TEDIDataObjectGroup inherited;
	
public:
	TEDIInterchangeControl* operator[](int Index) { return Interchange[Index]; }
	
private:
	int FFileID;
	AnsiString FFileName;
	TEDIFileOptions FEDIFileOptions;
	TEDIInterchangeControl* __fastcall GetInterchangeControl(int Index);
	void __fastcall SetInterchangeControl(int Index, TEDIInterchangeControl* Interchange);
	void __fastcall InternalLoadFromFile(void);
	
protected:
	virtual void __fastcall InternalDelimitersDetection(int StartPos);
	void __fastcall InternalAlternateDelimitersDetection(int StartPos);
	virtual TEDIInterchangeControl* __fastcall InternalCreateInterchangeControl(void);
	virtual Jcledi::TEDIDelimiters* __fastcall InternalAssignDelimiters(void);
	virtual Jcledi::TEDIDataObject* __fastcall InternalCreateEDIDataObject(void);
	
public:
	__fastcall TEDIFile(Jcledi::TEDIDataObject* Parent, int InterchangeCount);
	__fastcall virtual ~TEDIFile(void);
	void __fastcall LoadFromFile(const AnsiString FileName);
	void __fastcall ReLoadFromFile(void);
	void __fastcall SaveToFile(void);
	void __fastcall SaveAsToFile(const AnsiString FileName);
	int __fastcall AddInterchange(void);
	int __fastcall AppendInterchange(TEDIInterchangeControl* Interchange);
	int __fastcall InsertInterchange(int InsertIndex)/* overload */;
	int __fastcall InsertInterchange(int InsertIndex, TEDIInterchangeControl* Interchange)/* overload */;
	void __fastcall DeleteInterchange(int Index)/* overload */;
	void __fastcall DeleteInterchange(TEDIInterchangeControl* Interchange)/* overload */;
	int __fastcall AddInterchanges(int Count);
	int __fastcall AppendInterchanges(TEDIInterchangeControlArray InterchangeControlArray);
	int __fastcall InsertInterchanges(int InsertIndex, int Count)/* overload */;
	int __fastcall InsertInterchanges(int InsertIndex, TEDIInterchangeControlArray InterchangeControlArray)/* overload */;
	void __fastcall DeleteInterchanges(void)/* overload */;
	void __fastcall DeleteInterchanges(int Index, int Count)/* overload */;
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	__property TEDIInterchangeControl* Interchange[int Index] = {read=GetInterchangeControl, write=SetInterchangeControl/*, default*/};
	__property Jcledi::TEDIDataObjectList* Interchanges = {read=FEDIDataObjects};
	
__published:
	__property int FileID = {read=FFileID, write=FFileID, nodefault};
	__property AnsiString FileName = {read=FFileName, write=FFileName};
	__property TEDIFileOptions Options = {read=FEDIFileOptions, write=FEDIFileOptions, nodefault};
	__property int InterchangeControlCount = {read=GetCount, nodefault};
};


typedef DynamicArray<TEDIFile* >  TEDIFileArray;

class DELPHICLASS TEDIFileSpec;
class PASCALIMPLEMENTATION TEDIFileSpec : public TEDIFile 
{
	typedef TEDIFile inherited;
	
protected:
	virtual void __fastcall InternalDelimitersDetection(int StartPos);
	virtual TEDIInterchangeControl* __fastcall InternalCreateInterchangeControl(void);
	
public:
	__fastcall TEDIFileSpec(Jcledi::TEDIDataObject* Parent, int InterchangeCount);
	TEDITransactionSetSpec* __fastcall FindTransactionSetSpec(AnsiString StandardId, AnsiString VersionId, AnsiString FunctionalGroupId, AnsiString AgencyCodeId, AnsiString VersionReleaseId, AnsiString TransactionSetId);
	TEDIFunctionalGroupSpec* __fastcall FindFunctionalGroupSpec(AnsiString StandardId, AnsiString VersionId, AnsiString FunctionalGroupId, AnsiString AgencyCodeId, AnsiString VersionReleaseId);
	TEDIInterchangeControlSpec* __fastcall FindInterchangeControlSpec(AnsiString StandardId, AnsiString VersionId);
public:
	#pragma option push -w-inl
	/* TEDIFile.Destroy */ inline __fastcall virtual ~TEDIFileSpec(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define ICHSegmentId "ISA"
#define ICTSegmentId "IEA"
#define FGHSegmentId "GS"
#define FGTSegmentId "GE"
#define TSHSegmentId "ST"
#define TSTSegmentId "SE"
#define TA1SegmentId "TA1"
#define RDFN_Id "Id"
#define RDFN_Position "Position"
#define RDFN_Description "Description"
#define RDFN_Notes "Notes"
#define RDFN_Section "Section"
#define RDFN_RequirementDesignator "RequirementDesignator"
#define RDFN_MaximumUsage "MaximumUsage"
#define RDFN_OwnerLoopId "OwnerLoopId"
#define RDFN_ParentLoopId "ParentLoopId"
#define RDFN_MaximumLoopRepeat "MaximumLoopRepeat"
#define RDFN_Type "Type"
#define RDFN_MinimumLength "MinimumLength"
#define RDFN_MaximumLength "MaximumLength"
#define RDFN_TransSetId "TransSetId"
#define RDFN_TransSetDesc "TransSetDesc"
#define RDFN_FunctionalGroupId "FunctionalGroupId"
#define RDFN_FGDescription "FGDescription"
#define RDFN_AgencyCodeId "AgencyCodeId"
#define RDFN_VersionReleaseId "VersionReleaseId"
#define RDFN_StandardId "StandardId"
#define RDFN_VersionId "VersionId"
#define RDFN_ICDescription "ICDescription"
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jcledi_ansix12 */
using namespace Jcledi_ansix12;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcledi_ansix12
