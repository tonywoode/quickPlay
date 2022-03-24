// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcledixml.pas' rev: 10.00

#ifndef JcledixmlHPP
#define JcledixmlHPP

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
#include <Jcledi.hpp>	// Pascal unit
#include <Jcledi_ansix12.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jcledixml
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TEDIXMLObject;
class PASCALIMPLEMENTATION TEDIXMLObject : public Jcledi::TEDIObject 
{
	typedef Jcledi::TEDIObject inherited;
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TEDIXMLObject(void) : Jcledi::TEDIObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TEDIXMLObject(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEDIXMLDelimiters;
class PASCALIMPLEMENTATION TEDIXMLDelimiters : public TEDIXMLObject 
{
	typedef TEDIXMLObject inherited;
	
private:
	AnsiString FBeginTagDelimiter;
	AnsiString FEndTagDelimiter;
	int FBeginTagLength;
	int FEndTagLength;
	AnsiString FBeginCDataDelimiter;
	AnsiString FEndCDataDelimiter;
	int FBeginCDataLength;
	int FEndCDataLength;
	AnsiString FBeginOfEndTagDelimiter;
	int FBeginOfEndTagLength;
	AnsiString FSpaceDelimiter;
	AnsiString FAssignmentDelimiter;
	AnsiString FSingleQuote;
	AnsiString FDoubleQuote;
	void __fastcall SetBeginTagDelimiter(const AnsiString Value);
	void __fastcall SetEndTagDelimiter(const AnsiString Value);
	void __fastcall SetBeginCDataDelimiter(const AnsiString Value);
	void __fastcall SetEndCDataDelimiter(const AnsiString Value);
	void __fastcall SetBeginOfEndTagDelimiter(const AnsiString Value);
	
public:
	__fastcall TEDIXMLDelimiters(void);
	
__published:
	__property AnsiString BTD = {read=FBeginTagDelimiter, write=SetBeginTagDelimiter};
	__property AnsiString ETD = {read=FEndTagDelimiter, write=SetEndTagDelimiter};
	__property int BTDLength = {read=FBeginTagLength, nodefault};
	__property int ETDLength = {read=FEndTagLength, nodefault};
	__property AnsiString BOfETD = {read=FBeginOfEndTagDelimiter, write=SetBeginOfEndTagDelimiter};
	__property int BOfETDLength = {read=FBeginOfEndTagLength, nodefault};
	__property AnsiString BCDataD = {read=FBeginCDataDelimiter, write=SetBeginCDataDelimiter};
	__property AnsiString ECDataD = {read=FEndCDataDelimiter, write=SetEndCDataDelimiter};
	__property int BCDataLength = {read=FBeginCDataLength, nodefault};
	__property int ECDataLength = {read=FEndCDataLength, nodefault};
	__property AnsiString SpaceDelimiter = {read=FSpaceDelimiter, write=FSpaceDelimiter};
	__property AnsiString AssignmentDelimiter = {read=FAssignmentDelimiter, write=FAssignmentDelimiter};
	__property AnsiString SingleQuote = {read=FSingleQuote, write=FSingleQuote};
	__property AnsiString DoubleQuote = {read=FDoubleQuote, write=FDoubleQuote};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TEDIXMLDelimiters(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEDIXMLAttributes;
class PASCALIMPLEMENTATION TEDIXMLAttributes : public TEDIXMLObject 
{
	typedef TEDIXMLObject inherited;
	
private:
	Classes::TStringList* FAttributes;
	TEDIXMLDelimiters* FDelimiters;
	
public:
	__fastcall TEDIXMLAttributes(void);
	__fastcall virtual ~TEDIXMLAttributes(void);
	void __fastcall ParseAttributes(AnsiString XMLStartTag);
	AnsiString __fastcall CombineAttributes();
	void __fastcall SetAttribute(AnsiString Name, AnsiString Value);
	int __fastcall CheckAttribute(AnsiString Name, AnsiString Value);
	AnsiString __fastcall GetAttributeValue(AnsiString Name);
	AnsiString __fastcall GetAttributeString(AnsiString Name);
};


typedef DynamicArray<TEDIXMLObject* >  TEDIXMLObjectArray;

class DELPHICLASS TEDIXMLDataObject;
class PASCALIMPLEMENTATION TEDIXMLDataObject : public TEDIXMLObject 
{
	typedef TEDIXMLObject inherited;
	
private:
	void __fastcall SetDelimiters(const TEDIXMLDelimiters* Delimiters);
	
protected:
	Jcledi::TEDIDataObjectType FEDIDOT;
	Jcledi::TEDIDataObjectDataState FState;
	AnsiString FData;
	int FLength;
	TEDIXMLDataObject* FParent;
	TEDIXMLDelimiters* FDelimiters;
	TEDIXMLAttributes* FAttributes;
	Classes::TStrings* FErrorLog;
	Jcledi::TEDIObject* FSpecPointer;
	void *FCustomData1;
	void *FCustomData2;
	AnsiString __fastcall GetData();
	void __fastcall SetData(const AnsiString Data);
	virtual AnsiString __fastcall Assemble(void) = 0 ;
	virtual void __fastcall Disassemble(void) = 0 ;
	
public:
	__fastcall TEDIXMLDataObject(TEDIXMLDataObject* Parent);
	__fastcall virtual ~TEDIXMLDataObject(void);
	__property Jcledi::TEDIObject* SpecPointer = {read=FSpecPointer, write=FSpecPointer};
	__property void * CustomData1 = {read=FCustomData1, write=FCustomData1};
	__property void * CustomData2 = {read=FCustomData2, write=FCustomData2};
	
__published:
	__property Jcledi::TEDIDataObjectDataState State = {read=FState, nodefault};
	__property AnsiString Data = {read=GetData, write=SetData};
	__property int DataLength = {read=FLength, nodefault};
	__property TEDIXMLDataObject* Parent = {read=FParent, write=FParent};
	__property TEDIXMLDelimiters* Delimiters = {read=FDelimiters, write=SetDelimiters};
	__property TEDIXMLAttributes* Attributes = {read=FAttributes, write=FAttributes};
};


typedef DynamicArray<TEDIXMLDataObject* >  TEDIXMLDataObjectArray;

class DELPHICLASS TEDIXMLElement;
class PASCALIMPLEMENTATION TEDIXMLElement : public TEDIXMLDataObject 
{
	typedef TEDIXMLDataObject inherited;
	
private:
	bool FCData;
	
protected:
	virtual TEDIXMLDelimiters* __fastcall InternalAssignDelimiters(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	
public:
	__fastcall TEDIXMLElement(TEDIXMLDataObject* Parent);
	int __fastcall GetIndexPositionFromParent(void);
	
__published:
	__property bool CData = {read=FCData, write=FCData, nodefault};
public:
	#pragma option push -w-inl
	/* TEDIXMLDataObject.Destroy */ inline __fastcall virtual ~TEDIXMLElement(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TEDIXMLElement* >  TEDIXMLElementArray;

class DELPHICLASS TEDIXMLDataObjectGroup;
class PASCALIMPLEMENTATION TEDIXMLDataObjectGroup : public TEDIXMLDataObject 
{
	typedef TEDIXMLDataObject inherited;
	
public:
	TEDIXMLDataObject* operator[](int Index) { return EDIDataObject[Index]; }
	
protected:
	DynamicArray<TEDIXMLDataObject* >  FEDIDataObjects;
	TEDIXMLDataObject* __fastcall GetEDIDataObject(int Index);
	void __fastcall SetEDIDataObject(int Index, TEDIXMLDataObject* EDIDataObject);
	virtual TEDIXMLDelimiters* __fastcall InternalAssignDelimiters(void) = 0 ;
	virtual TEDIXMLDataObjectGroup* __fastcall InternalCreateDataObjectGroup(void) = 0 ;
	int __fastcall SearchForSegmentInDataString(AnsiString Id, int StartPos);
	
public:
	__fastcall TEDIXMLDataObjectGroup(TEDIXMLDataObject* Parent);
	__fastcall virtual ~TEDIXMLDataObjectGroup(void);
	int __fastcall AppendEDIDataObject(TEDIXMLDataObject* EDIDataObject);
	int __fastcall InsertEDIDataObject(int InsertIndex, TEDIXMLDataObject* EDIDataObject);
	void __fastcall DeleteEDIDataObject(int Index)/* overload */;
	void __fastcall DeleteEDIDataObject(TEDIXMLDataObject* EDIDataObject)/* overload */;
	int __fastcall AddSegment(void);
	int __fastcall InsertSegment(int InsertIndex);
	virtual int __fastcall AddGroup(void);
	virtual int __fastcall InsertGroup(int InsertIndex);
	void __fastcall DeleteEDIDataObjects(void);
	__property TEDIXMLDataObject* EDIDataObject[int Index] = {read=GetEDIDataObject, write=SetEDIDataObject/*, default*/};
	__property TEDIXMLDataObjectArray EDIDataObjects = {read=FEDIDataObjects, write=FEDIDataObjects};
};


class DELPHICLASS TEDIXMLSegment;
class PASCALIMPLEMENTATION TEDIXMLSegment : public TEDIXMLDataObject 
{
	typedef TEDIXMLDataObject inherited;
	
public:
	TEDIXMLElement* operator[](int Index) { return Element[Index]; }
	
private:
	AnsiString FSegmentID;
	DynamicArray<TEDIXMLElement* >  FElements;
	TEDIXMLElement* __fastcall GetElement(int Index);
	void __fastcall SetElement(int Index, TEDIXMLElement* Element);
	
protected:
	virtual TEDIXMLDelimiters* __fastcall InternalAssignDelimiters(void);
	virtual TEDIXMLElement* __fastcall InternalCreateElement(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	
public:
	__fastcall TEDIXMLSegment(TEDIXMLDataObject* Parent)/* overload */;
	__fastcall TEDIXMLSegment(TEDIXMLDataObject* Parent, int ElementCount)/* overload */;
	__fastcall virtual ~TEDIXMLSegment(void);
	int __fastcall AddElement(void);
	int __fastcall AppendElement(TEDIXMLElement* Element);
	int __fastcall InsertElement(int InsertIndex)/* overload */;
	int __fastcall InsertElement(int InsertIndex, TEDIXMLElement* Element)/* overload */;
	void __fastcall DeleteElement(int Index)/* overload */;
	void __fastcall DeleteElement(TEDIXMLElement* Element)/* overload */;
	int __fastcall AddElements(int Count);
	int __fastcall AppendElements(TEDIXMLElementArray ElementArray);
	int __fastcall InsertElements(int InsertIndex, int Count)/* overload */;
	int __fastcall InsertElements(int InsertIndex, TEDIXMLElementArray ElementArray)/* overload */;
	void __fastcall DeleteElements(void)/* overload */;
	void __fastcall DeleteElements(int Index, int Count)/* overload */;
	int __fastcall GetIndexPositionFromParent(void);
	__property TEDIXMLElement* Element[int Index] = {read=GetElement, write=SetElement/*, default*/};
	__property TEDIXMLElementArray Elements = {read=FElements, write=FElements};
	
__published:
	__property AnsiString SegmentID = {read=FSegmentID, write=FSegmentID};
};


typedef DynamicArray<TEDIXMLSegment* >  TEDIXMLSegmentArray;

class DELPHICLASS TEDIXMLTransactionSetSegment;
class PASCALIMPLEMENTATION TEDIXMLTransactionSetSegment : public TEDIXMLSegment 
{
	typedef TEDIXMLSegment inherited;
	
protected:
	virtual TEDIXMLDelimiters* __fastcall InternalAssignDelimiters(void);
	
public:
	__fastcall TEDIXMLTransactionSetSegment(TEDIXMLDataObject* Parent)/* overload */;
	__fastcall TEDIXMLTransactionSetSegment(TEDIXMLDataObject* Parent, int ElementCount)/* overload */;
public:
	#pragma option push -w-inl
	/* TEDIXMLSegment.Destroy */ inline __fastcall virtual ~TEDIXMLTransactionSetSegment(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEDIXMLFunctionalGroupSegment;
class PASCALIMPLEMENTATION TEDIXMLFunctionalGroupSegment : public TEDIXMLSegment 
{
	typedef TEDIXMLSegment inherited;
	
protected:
	virtual TEDIXMLDelimiters* __fastcall InternalAssignDelimiters(void);
	
public:
	__fastcall TEDIXMLFunctionalGroupSegment(TEDIXMLDataObject* Parent)/* overload */;
	__fastcall TEDIXMLFunctionalGroupSegment(TEDIXMLDataObject* Parent, int ElementCount)/* overload */;
public:
	#pragma option push -w-inl
	/* TEDIXMLSegment.Destroy */ inline __fastcall virtual ~TEDIXMLFunctionalGroupSegment(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEDIXMLInterchangeControlSegment;
class PASCALIMPLEMENTATION TEDIXMLInterchangeControlSegment : public TEDIXMLSegment 
{
	typedef TEDIXMLSegment inherited;
	
protected:
	virtual TEDIXMLDelimiters* __fastcall InternalAssignDelimiters(void);
	
public:
	__fastcall TEDIXMLInterchangeControlSegment(TEDIXMLDataObject* Parent)/* overload */;
	__fastcall TEDIXMLInterchangeControlSegment(TEDIXMLDataObject* Parent, int ElementCount)/* overload */;
public:
	#pragma option push -w-inl
	/* TEDIXMLSegment.Destroy */ inline __fastcall virtual ~TEDIXMLInterchangeControlSegment(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEDIXMLTransactionSetLoop;
class DELPHICLASS TEDIXMLTransactionSet;
class PASCALIMPLEMENTATION TEDIXMLTransactionSetLoop : public TEDIXMLDataObjectGroup 
{
	typedef TEDIXMLDataObjectGroup inherited;
	
private:
	TEDIXMLTransactionSet* FParentTransactionSet;
	
protected:
	virtual TEDIXMLDelimiters* __fastcall InternalAssignDelimiters(void);
	virtual TEDIXMLDataObjectGroup* __fastcall InternalCreateDataObjectGroup(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	
public:
	__fastcall TEDIXMLTransactionSetLoop(TEDIXMLDataObject* Parent);
	__fastcall virtual ~TEDIXMLTransactionSetLoop(void);
	
__published:
	__property TEDIXMLTransactionSet* ParentTransactionSet = {read=FParentTransactionSet, write=FParentTransactionSet};
};


class PASCALIMPLEMENTATION TEDIXMLTransactionSet : public TEDIXMLTransactionSetLoop 
{
	typedef TEDIXMLTransactionSetLoop inherited;
	
private:
	TEDIXMLSegment* FSTSegment;
	TEDIXMLSegment* FSESegment;
	
protected:
	virtual TEDIXMLDelimiters* __fastcall InternalAssignDelimiters(void);
	virtual TEDIXMLDataObjectGroup* __fastcall InternalCreateDataObjectGroup(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	
public:
	__fastcall TEDIXMLTransactionSet(TEDIXMLDataObject* Parent);
	__fastcall virtual ~TEDIXMLTransactionSet(void);
	
__published:
	__property TEDIXMLSegment* SegmentST = {read=FSTSegment, write=FSTSegment};
	__property TEDIXMLSegment* SegmentSE = {read=FSESegment, write=FSESegment};
};



class DELPHICLASS TEDIXMLFunctionalGroup;
class PASCALIMPLEMENTATION TEDIXMLFunctionalGroup : public TEDIXMLDataObjectGroup 
{
	typedef TEDIXMLDataObjectGroup inherited;
	
private:
	TEDIXMLSegment* FGSSegment;
	TEDIXMLSegment* FGESegment;
	
protected:
	virtual TEDIXMLDelimiters* __fastcall InternalAssignDelimiters(void);
	virtual TEDIXMLDataObjectGroup* __fastcall InternalCreateDataObjectGroup(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	
public:
	__fastcall TEDIXMLFunctionalGroup(TEDIXMLDataObject* Parent);
	__fastcall virtual ~TEDIXMLFunctionalGroup(void);
	
__published:
	__property TEDIXMLSegment* SegmentGS = {read=FGSSegment, write=FGSSegment};
	__property TEDIXMLSegment* SegmentGE = {read=FGESegment, write=FGESegment};
};


class DELPHICLASS TEDIXMLInterchangeControl;
class PASCALIMPLEMENTATION TEDIXMLInterchangeControl : public TEDIXMLDataObjectGroup 
{
	typedef TEDIXMLDataObjectGroup inherited;
	
private:
	TEDIXMLSegment* FISASegment;
	TEDIXMLSegment* FIEASegment;
	
protected:
	virtual TEDIXMLDelimiters* __fastcall InternalAssignDelimiters(void);
	virtual TEDIXMLDataObjectGroup* __fastcall InternalCreateDataObjectGroup(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	
public:
	__fastcall TEDIXMLInterchangeControl(TEDIXMLDataObject* Parent);
	__fastcall virtual ~TEDIXMLInterchangeControl(void);
	
__published:
	__property TEDIXMLSegment* SegmentISA = {read=FISASegment, write=FISASegment};
	__property TEDIXMLSegment* SegmentIEA = {read=FIEASegment, write=FIEASegment};
};


#pragma option push -b-
enum TEDIXMLNameSpaceOption { nsNone, nsDefault, nsQualified };
#pragma option pop

class DELPHICLASS TEDIXMLFileHeader;
class PASCALIMPLEMENTATION TEDIXMLFileHeader : public TEDIXMLObject 
{
	typedef TEDIXMLObject inherited;
	
private:
	TEDIXMLDelimiters* FDelimiters;
	TEDIXMLAttributes* FAttributes;
	TEDIXMLNameSpaceOption FXMLNameSpaceOption;
	
protected:
	virtual AnsiString __fastcall OutputAdditionalXMLHeaderAttributes();
	
public:
	__fastcall TEDIXMLFileHeader(void);
	__fastcall virtual ~TEDIXMLFileHeader(void);
	void __fastcall ParseXMLHeader(AnsiString XMLHeader);
	AnsiString __fastcall OutputXMLHeader();
	
__published:
	__property TEDIXMLDelimiters* Delimiters = {read=FDelimiters};
	__property TEDIXMLAttributes* Attributes = {read=FAttributes};
	__property TEDIXMLNameSpaceOption XMLNameSpaceOption = {read=FXMLNameSpaceOption, write=FXMLNameSpaceOption, nodefault};
};


class DELPHICLASS TEDIXMLFile;
class PASCALIMPLEMENTATION TEDIXMLFile : public TEDIXMLDataObjectGroup 
{
	typedef TEDIXMLDataObjectGroup inherited;
	
private:
	int FFileID;
	AnsiString FFileName;
	TEDIXMLFileHeader* FEDIXMLFileHeader;
	void __fastcall InternalLoadFromFile(void);
	
protected:
	virtual TEDIXMLDelimiters* __fastcall InternalAssignDelimiters(void);
	virtual TEDIXMLDataObjectGroup* __fastcall InternalCreateDataObjectGroup(void);
	virtual AnsiString __fastcall Assemble();
	virtual void __fastcall Disassemble(void);
	
public:
	__fastcall TEDIXMLFile(TEDIXMLDataObject* Parent);
	__fastcall virtual ~TEDIXMLFile(void);
	void __fastcall LoadFromFile(const AnsiString FileName);
	void __fastcall ReLoadFromFile(void);
	void __fastcall SaveToFile(void);
	void __fastcall SaveAsToFile(const AnsiString FileName);
	
__published:
	__property int FileID = {read=FFileID, write=FFileID, nodefault};
	__property AnsiString FileName = {read=FFileName, write=FFileName};
	__property TEDIXMLFileHeader* XMLFileHeader = {read=FEDIXMLFileHeader};
};


class DELPHICLASS TEDIXMLANSIX12FormatTranslator;
class PASCALIMPLEMENTATION TEDIXMLANSIX12FormatTranslator : public Jcledi::TEDIObject 
{
	typedef Jcledi::TEDIObject inherited;
	
private:
	void __fastcall ConvertTransactionSetLoopToXML(Jcledi_ansix12::TEDITransactionSetLoop* EDILoop, TEDIXMLTransactionSetLoop* XMLLoop);
	void __fastcall ConvertTransactionSetLoopToEDI(Jcledi_ansix12::TEDITransactionSet* EDITransactionSet, TEDIXMLTransactionSetLoop* XMLLoop);
	
public:
	__fastcall TEDIXMLANSIX12FormatTranslator(void);
	__fastcall virtual ~TEDIXMLANSIX12FormatTranslator(void);
	TEDIXMLSegment* __fastcall ConvertToXMLSegment(Jcledi_ansix12::TEDISegment* EDISegment);
	TEDIXMLTransactionSet* __fastcall ConvertToXMLTransaction(Jcledi_ansix12::TEDITransactionSet* EDITransactionSet)/* overload */;
	TEDIXMLTransactionSet* __fastcall ConvertToXMLTransaction(Jcledi_ansix12::TEDITransactionSet* EDITransactionSet, Jcledi_ansix12::TEDITransactionSetSpec* EDITransactionSetSpec)/* overload */;
	Jcledi_ansix12::TEDISegment* __fastcall ConvertToEDISegment(TEDIXMLSegment* XMLSegment);
	Jcledi_ansix12::TEDITransactionSet* __fastcall ConvertToEDITransaction(TEDIXMLTransactionSet* XMLTransactionSet);
};


class DELPHICLASS EJclEDIXMLError;
class PASCALIMPLEMENTATION EJclEDIXMLError : public Jcledi::EJclEDIError 
{
	typedef Jcledi::EJclEDIError inherited;
	
public:
	__fastcall EJclEDIXMLError(unsigned ID);
	__fastcall EJclEDIXMLError(unsigned ID, System::TVarRec const * Args, const int Args_Size);
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclEDIXMLError(const AnsiString Msg) : Jcledi::EJclEDIError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclEDIXMLError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jcledi::EJclEDIError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclEDIXMLError(int Ident)/* overload */ : Jcledi::EJclEDIError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclEDIXMLError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jcledi::EJclEDIError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclEDIXMLError(const AnsiString Msg, int AHelpContext) : Jcledi::EJclEDIError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclEDIXMLError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jcledi::EJclEDIError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclEDIXMLError(int Ident, int AHelpContext)/* overload */ : Jcledi::EJclEDIError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclEDIXMLError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jcledi::EJclEDIError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclEDIXMLError(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define XMLTag_Element "Element"
#define XMLTag_Segment "Segment"
#define XMLTag_TransactionSetLoop "Loop"
#define XMLTag_TransactionSet "TransactionSet"
#define XMLTag_FunctionalGroup "FunctionalGroup"
#define XMLTag_InterchangeControl "InterchangeControl"
#define XMLTag_EDIFile "EDIFile"
#define XMLTag_ICHSegmentId "ISA"
#define XMLTag_ICTSegmentId "IEA"
#define XMLTag_FGHSegmentId "GS"
#define XMLTag_FGTSegmentId "GE"
#define XMLTag_TSHSegmentId "ST"
#define XMLTag_TSTSegmentId "SE"
#define XMLAttribute_Id "Id"
#define XMLAttribute_Position "Position"
#define XMLAttribute_Description "Description"
#define XMLAttribute_RequirementDesignator "RequirementDesignator"
#define XMLAttribute_Type "Type"
#define XMLAttribute_MinimumLength "MinimumLength"
#define XMLAttribute_MaximumLength "MaximumLength"
#define XMLAttribute_Section "Section"
#define XMLAttribute_MaximumUsage "MaximumUsage"
#define XMLAttribute_OwnerLoopId "OwnerLoopId"
#define XMLAttribute_ParentLoopId "ParentLoopId"
extern PACKAGE System::TResStringRec *EDIXMLErrors[62];
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jcledixml */
using namespace Jcledixml;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcledixml
