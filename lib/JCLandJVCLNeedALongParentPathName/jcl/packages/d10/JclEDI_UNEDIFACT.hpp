// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcledi_unedifact.pas' rev: 10.00

#ifndef Jcledi_unedifactHPP
#define Jcledi_unedifactHPP

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
#include <Jcledi.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jcledi_unedifact
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

class DELPHICLASS TEDICompositeElement;
class PASCALIMPLEMENTATION TEDICompositeElement : public Jcledi::TEDIDataObjectGroup 
{
	typedef Jcledi::TEDIDataObjectGroup inherited;
	
public:
	TEDIElement* operator[](int Index) { return Element[Index]; }
	
private:
	TEDIElement* __fastcall GetElement(int Index);
	void __fastcall SetElement(int Index, TEDIElement* Element);
	
protected:
	virtual TEDIElement* __fastcall InternalCreateElement(void);
	virtual Jcledi::TEDIDelimiters* __fastcall InternalAssignDelimiters(void);
	virtual Jcledi::TEDIDataObject* __fastcall InternalCreateEDIDataObject(void);
	
public:
	__fastcall TEDICompositeElement(Jcledi::TEDIDataObject* Parent, int ElementCount);
	__fastcall virtual ~TEDICompositeElement(void);
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
};


typedef DynamicArray<TEDICompositeElement* >  TEDICompositeElementArray;

class DELPHICLASS TEDISegment;
class PASCALIMPLEMENTATION TEDISegment : public Jcledi::TEDIDataObjectGroup 
{
	typedef Jcledi::TEDIDataObjectGroup inherited;
	
private:
	AnsiString FSegmentID;
	
protected:
	virtual TEDIElement* __fastcall InternalCreateElement(void);
	virtual TEDICompositeElement* __fastcall InternalCreateCompositeElement(void);
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
	int __fastcall AddCompositeElement(void);
	int __fastcall AppendCompositeElement(TEDICompositeElement* CompositeElement);
	int __fastcall InsertCompositeElement(int InsertIndex)/* overload */;
	int __fastcall InsertCompositeElement(int InsertIndex, TEDICompositeElement* CompositeElement)/* overload */;
	int __fastcall AddCompositeElements(int Count);
	int __fastcall AppendCompositeElements(TEDICompositeElementArray CompositeElementArray);
	int __fastcall InsertCompositeElements(int InsertIndex, int Count)/* overload */;
	int __fastcall InsertCompositeElements(int InsertIndex, TEDICompositeElementArray CompositeElementArray)/* overload */;
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	
__published:
	__property AnsiString SegmentID = {read=FSegmentID, write=FSegmentID};
	__property int ElementCount = {read=GetCount, nodefault};
};


typedef DynamicArray<TEDISegment* >  TEDISegmentArray;

class DELPHICLASS TEDIMessageSegment;
class PASCALIMPLEMENTATION TEDIMessageSegment : public TEDISegment 
{
	typedef TEDISegment inherited;
	
protected:
	virtual Jcledi::TEDIDelimiters* __fastcall InternalAssignDelimiters(void);
	
public:
	__fastcall TEDIMessageSegment(Jcledi::TEDIDataObject* Parent, int ElementCount);
public:
	#pragma option push -w-inl
	/* TEDISegment.Destroy */ inline __fastcall virtual ~TEDIMessageSegment(void) { }
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


class DELPHICLASS TEDIMessageLoop;
class DELPHICLASS TEDIMessage;
class PASCALIMPLEMENTATION TEDIMessage : public Jcledi::TEDIDataObjectGroup 
{
	typedef Jcledi::TEDIDataObjectGroup inherited;
	
public:
	TEDISegment* operator[](int Index) { return Segment[Index]; }
	
private:
	TEDIMessageSegment* FUNHSegment;
	TEDIMessageSegment* FUNTSegment;
	TEDISegment* __fastcall GetSegment(int Index);
	void __fastcall SetSegment(int Index, TEDISegment* Segment);
	void __fastcall SetUNHSegment(const TEDIMessageSegment* UNHSegment);
	void __fastcall SetUNTSegment(const TEDIMessageSegment* UNTSegment);
	
protected:
	virtual void __fastcall InternalCreateHeaderTrailerSegments(void);
	virtual TEDISegment* __fastcall InternalCreateSegment(void);
	virtual Jcledi::TEDIDelimiters* __fastcall InternalAssignDelimiters(void);
	virtual Jcledi::TEDIDataObject* __fastcall InternalCreateEDIDataObject(void);
	
public:
	__fastcall TEDIMessage(Jcledi::TEDIDataObject* Parent, int SegmentCount);
	__fastcall virtual ~TEDIMessage(void);
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
	__property TEDIMessageSegment* SegmentUNH = {read=FUNHSegment, write=SetUNHSegment};
	__property TEDIMessageSegment* SegmentUNT = {read=FUNTSegment, write=SetUNTSegment};
	__property int SegmentCount = {read=GetCount, nodefault};
};


class PASCALIMPLEMENTATION TEDIMessageLoop : public Jcledi::TEDIDataObjectGroup 
{
	typedef Jcledi::TEDIDataObjectGroup inherited;
	
protected:
	AnsiString FOwnerLoopId;
	AnsiString FParentLoopId;
	TEDIMessage* FParentMessage;
	virtual Jcledi::TEDIDelimiters* __fastcall InternalAssignDelimiters(void);
	virtual Jcledi::TEDIDataObject* __fastcall InternalCreateEDIDataObject(void);
	
public:
	__fastcall TEDIMessageLoop(Jcledi::TEDIDataObject* Parent);
	__fastcall virtual ~TEDIMessageLoop(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	TEDIMessageLoop* __fastcall FindLoop(AnsiString LoopId, int &StartIndex);
	TEDISegment* __fastcall FindSegment(AnsiString SegmentId, int &StartIndex)/* overload */;
	TEDISegment* __fastcall FindSegment(AnsiString SegmentId, int &StartIndex, Classes::TStrings* ElementConditions)/* overload */;
	int __fastcall AddLoop(AnsiString OwnerLoopId, AnsiString ParentLoopId);
	void __fastcall AppendSegment(TEDISegment* Segment);
	HIDESBASE void __fastcall DeleteEDIDataObjects(void);
	
__published:
	__property AnsiString OwnerLoopId = {read=FOwnerLoopId, write=FOwnerLoopId};
	__property AnsiString ParentLoopId = {read=FParentLoopId, write=FParentLoopId};
	__property TEDIMessage* ParentMessage = {read=FParentMessage, write=FParentMessage};
};


typedef DynamicArray<TEDIMessage* >  TEDIMessageArray;

class DELPHICLASS TEDIFunctionalGroup;
class PASCALIMPLEMENTATION TEDIFunctionalGroup : public Jcledi::TEDIDataObjectGroup 
{
	typedef Jcledi::TEDIDataObjectGroup inherited;
	
public:
	TEDIMessage* operator[](int Index) { return Message[Index]; }
	
private:
	TEDIFunctionalGroupSegment* FUNGSegment;
	TEDIFunctionalGroupSegment* FUNESegment;
	TEDIMessage* __fastcall GetMessage(int Index);
	void __fastcall SetMessage(int Index, TEDIMessage* Message);
	void __fastcall SetUNGSegment(const TEDIFunctionalGroupSegment* UNGSegment);
	void __fastcall SetUNESegment(const TEDIFunctionalGroupSegment* UNESegment);
	
protected:
	virtual void __fastcall InternalCreateHeaderTrailerSegments(void);
	virtual TEDIMessage* __fastcall InternalCreateMessage(void);
	virtual Jcledi::TEDIDelimiters* __fastcall InternalAssignDelimiters(void);
	virtual Jcledi::TEDIDataObject* __fastcall InternalCreateEDIDataObject(void);
	
public:
	__fastcall TEDIFunctionalGroup(Jcledi::TEDIDataObject* Parent, int MessageCount);
	__fastcall virtual ~TEDIFunctionalGroup(void);
	int __fastcall AddMessage(void);
	int __fastcall AppendMessage(TEDIMessage* Message);
	int __fastcall InsertMessage(int InsertIndex)/* overload */;
	int __fastcall InsertMessage(int InsertIndex, TEDIMessage* Message)/* overload */;
	void __fastcall DeleteMessage(int Index)/* overload */;
	void __fastcall DeleteMessage(TEDIMessage* Message)/* overload */;
	int __fastcall AddMessages(int Count);
	int __fastcall AppendMessages(TEDIMessageArray MessageArray);
	int __fastcall InsertMessages(int InsertIndex, int Count)/* overload */;
	int __fastcall InsertMessages(int InsertIndex, TEDIMessageArray MessageArray)/* overload */;
	void __fastcall DeleteMessages(void)/* overload */;
	void __fastcall DeleteMessages(int Index, int Count)/* overload */;
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	__property TEDIMessage* Message[int Index] = {read=GetMessage, write=SetMessage/*, default*/};
	__property Jcledi::TEDIDataObjectList* Messages = {read=FEDIDataObjects};
	
__published:
	__property TEDIFunctionalGroupSegment* SegmentUNG = {read=FUNGSegment, write=SetUNGSegment};
	__property TEDIFunctionalGroupSegment* SegmentUNE = {read=FUNESegment, write=SetUNESegment};
	__property int MessageCount = {read=GetCount, nodefault};
};


typedef DynamicArray<TEDIFunctionalGroup* >  TEDIFunctionalGroupArray;

class DELPHICLASS TEDIInterchangeControl;
class PASCALIMPLEMENTATION TEDIInterchangeControl : public Jcledi::TEDIDataObjectGroup 
{
	typedef Jcledi::TEDIDataObjectGroup inherited;
	
private:
	TEDIInterchangeControlSegment* FUNASegment;
	TEDIInterchangeControlSegment* FUNBSegment;
	TEDIInterchangeControlSegment* FUNZSegment;
	void __fastcall SetUNBSegment(const TEDIInterchangeControlSegment* UNBSegment);
	void __fastcall SetUNZSegment(const TEDIInterchangeControlSegment* UNZSegment);
	
protected:
	Jcledi::TEDIDataObjectType FCreateObjectType;
	virtual void __fastcall InternalCreateHeaderTrailerSegments(void);
	virtual TEDIFunctionalGroup* __fastcall InternalCreateFunctionalGroup(void);
	virtual TEDIMessage* __fastcall InternalCreateMessage(void);
	virtual Jcledi::TEDIDelimiters* __fastcall InternalAssignDelimiters(void);
	virtual Jcledi::TEDIDataObject* __fastcall InternalCreateEDIDataObject(void);
	
public:
	__fastcall TEDIInterchangeControl(Jcledi::TEDIDataObject* Parent, int FunctionalGroupCount);
	__fastcall virtual ~TEDIInterchangeControl(void);
	int __fastcall AddFunctionalGroup(void);
	int __fastcall AppendFunctionalGroup(TEDIFunctionalGroup* FunctionalGroup);
	int __fastcall InsertFunctionalGroup(int InsertIndex)/* overload */;
	int __fastcall InsertFunctionalGroup(int InsertIndex, TEDIFunctionalGroup* FunctionalGroup)/* overload */;
	int __fastcall AddFunctionalGroups(int Count);
	int __fastcall AppendFunctionalGroups(TEDIFunctionalGroupArray FunctionalGroupArray);
	int __fastcall InsertFunctionalGroups(int InsertIndex, int Count)/* overload */;
	int __fastcall InsertFunctionalGroups(int InsertIndex, TEDIFunctionalGroupArray FunctionalGroupArray)/* overload */;
	int __fastcall AddMessage(void);
	int __fastcall AppendMessage(TEDIMessage* Message);
	int __fastcall InsertMessage(int InsertIndex)/* overload */;
	int __fastcall InsertMessage(int InsertIndex, TEDIMessage* Message)/* overload */;
	int __fastcall AddMessages(int Count);
	int __fastcall AppendMessages(TEDIMessageArray MessageArray);
	int __fastcall InsertMessages(int InsertIndex, int Count)/* overload */;
	int __fastcall InsertMessages(int InsertIndex, TEDIMessageArray MessageArray)/* overload */;
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	
__published:
	__property TEDIInterchangeControlSegment* SegmentUNA = {read=FUNASegment};
	__property TEDIInterchangeControlSegment* SegmentUNB = {read=FUNBSegment, write=SetUNBSegment};
	__property TEDIInterchangeControlSegment* SegmentUNZ = {read=FUNZSegment, write=SetUNZSegment};
};


typedef DynamicArray<TEDIInterchangeControl* >  TEDIInterchangeControlArray;

#pragma option push -b-
enum JclEDI_UNEDIFACT__11 { foVariableDelimiterDetection, foRemoveCrLf, foRemoveCr, foRemoveLf, foIgnoreGarbageAtEndOfFile };
#pragma option pop

typedef Set<JclEDI_UNEDIFACT__11, foVariableDelimiterDetection, foIgnoreGarbageAtEndOfFile>  TEDIFileOptions;

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

//-- var, const, procedure ---------------------------------------------------
#define UNASegmentId "UNA"
#define UNBSegmentId "UNB"
#define UNZSegmentId "UNZ"
#define UNGSegmentId "UNG"
#define UNESegmentId "UNE"
#define UNHSegmentId "UNH"
#define UNTSegmentId "UNT"
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jcledi_unedifact */
using namespace Jcledi_unedifact;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcledi_unedifact
