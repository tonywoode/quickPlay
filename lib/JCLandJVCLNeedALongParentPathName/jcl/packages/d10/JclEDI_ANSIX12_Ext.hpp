// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcledi_ansix12_ext.pas' rev: 10.00

#ifndef Jcledi_ansix12_extHPP
#define Jcledi_ansix12_extHPP

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
#include <Jcledi_ansix12.hpp>	// Pascal unit
#include <Jcledisef.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jcledi_ansix12_ext
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TEDI_ANSIX12_Document;
class PASCALIMPLEMENTATION TEDI_ANSIX12_Document : public Jcledi_ansix12::TEDITransactionSetLoop 
{
	typedef Jcledi_ansix12::TEDITransactionSetLoop inherited;
	
private:
	Jcledisef::TEDISEFSet* FEDISEFSet;
	
protected:
	bool FErrorOccured;
	Jcledi_ansix12::TEDITransactionSetDocumentOptions FEDITSDOptions;
	Jcledi::TEDILoopStack* FEDILoopStack;
	Jcledi_ansix12::TEDITransactionSet* FEDITransactionSet;
	Contnrs::TObjectList* FEDITransactionSetSpec;
	int __fastcall ValidateSegSpecIndex(AnsiString DataSegmentId, int SpecStartIndex);
	int __fastcall AdvanceSegSpecIndex(int DataIndex, int SpecStartIndex, int SpecEndIndex);
	void __fastcall AddLoopToDoc(const Jcledi::TEDILoopStackRecord &StackRecord, AnsiString SegmentId, AnsiString OwnerLoopId, AnsiString ParentLoopId, Jcledi::TEDIObject* &EDIObject);
	void __fastcall SetSpecificationPointers(Jcledi_ansix12::TEDISegment* DataSegment, Jcledisef::TEDISEFSegment* SpecSegment);
	virtual void __fastcall ValidateData(TEDI_ANSIX12_Document* TSDocument, Jcledi::TEDILoopStack* LoopStack, Jcledi_ansix12::TEDISegment* DataSegment, Jcledisef::TEDISEFSegment* SpecSegment, int &DataIndex, int &SpecIndex, bool &ErrorOccured);
	
public:
	__fastcall TEDI_ANSIX12_Document(Jcledi::TEDIDataObject* Parent, Jcledi_ansix12::TEDITransactionSet* TransactionSet, Jcledisef::TEDISEFSet* SEFSet);
	__fastcall virtual ~TEDI_ANSIX12_Document(void);
	virtual void __fastcall FormatDocument(void);
	
__published:
	__property Jcledi_ansix12::TEDITransactionSetDocumentOptions EDITSDOptions = {read=FEDITSDOptions, write=FEDITSDOptions, nodefault};
	__property bool ErrorOccured = {read=FErrorOccured, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jcledi_ansix12_ext */
using namespace Jcledi_ansix12_ext;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcledi_ansix12_ext
