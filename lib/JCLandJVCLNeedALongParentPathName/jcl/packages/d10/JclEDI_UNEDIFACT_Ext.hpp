// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcledi_unedifact_ext.pas' rev: 10.00

#ifndef Jcledi_unedifact_extHPP
#define Jcledi_unedifact_extHPP

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
#include <Jclresources.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Jcledi.hpp>	// Pascal unit
#include <Jcledi_unedifact.hpp>	// Pascal unit
#include <Jcledisef.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jcledi_unedifact_ext
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum JclEDI_UNEDIFACT_Ext__1 { doLinkSpecToDataObject };
#pragma option pop

typedef Set<JclEDI_UNEDIFACT_Ext__1, doLinkSpecToDataObject, doLinkSpecToDataObject>  TEDIMessageDocumentOptions;

class DELPHICLASS TEDI_UNEDIFACT_Document;
class PASCALIMPLEMENTATION TEDI_UNEDIFACT_Document : public Jcledi_unedifact::TEDIMessageLoop 
{
	typedef Jcledi_unedifact::TEDIMessageLoop inherited;
	
private:
	Jcledisef::TEDISEFSet* FEDISEFSet;
	
protected:
	bool FErrorOccured;
	TEDIMessageDocumentOptions FEDITSDOptions;
	Jcledi::TEDILoopStack* FEDILoopStack;
	Jcledi_unedifact::TEDIMessage* FEDIMessage;
	Contnrs::TObjectList* FEDIMessageSpec;
	int __fastcall ValidateSegSpecIndex(AnsiString DataSegmentId, int SpecStartIndex);
	int __fastcall AdvanceSegSpecIndex(int DataIndex, int SpecStartIndex, int SpecEndIndex);
	void __fastcall AddLoopToDoc(const Jcledi::TEDILoopStackRecord &StackRecord, AnsiString SegmentId, AnsiString OwnerLoopId, AnsiString ParentLoopId, Jcledi::TEDIObject* &EDIObject);
	void __fastcall SetSpecificationPointers(Jcledi_unedifact::TEDISegment* DataSegment, Jcledisef::TEDISEFSegment* SpecSegment);
	virtual void __fastcall ValidateData(TEDI_UNEDIFACT_Document* TSDocument, Jcledi::TEDILoopStack* LoopStack, Jcledi_unedifact::TEDISegment* DataSegment, Jcledisef::TEDISEFSegment* SpecSegment, int &DataIndex, int &SpecIndex, bool &ErrorOccured);
	
public:
	__fastcall TEDI_UNEDIFACT_Document(Jcledi::TEDIDataObject* Parent, Jcledi_unedifact::TEDIMessage* AEDIMessage, Jcledisef::TEDISEFSet* SEFSet);
	__fastcall virtual ~TEDI_UNEDIFACT_Document(void);
	virtual void __fastcall FormatDocument(void);
	
__published:
	__property TEDIMessageDocumentOptions EDITSDOptions = {read=FEDITSDOptions, write=FEDITSDOptions, nodefault};
	__property bool ErrorOccured = {read=FErrorOccured, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jcledi_unedifact_ext */
using namespace Jcledi_unedifact_ext;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcledi_unedifact_ext
