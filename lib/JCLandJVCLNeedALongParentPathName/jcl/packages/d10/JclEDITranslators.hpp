// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcleditranslators.pas' rev: 10.00

#ifndef JcleditranslatorsHPP
#define JcleditranslatorsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Jcledi.hpp>	// Pascal unit
#include <Jcledi_ansix12.hpp>	// Pascal unit
#include <Jcledisef.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jcleditranslators
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TEDISpecToSEFTranslator;
class PASCALIMPLEMENTATION TEDISpecToSEFTranslator : public Jcledi::TEDIObject 
{
	typedef Jcledi::TEDIObject inherited;
	
public:
	__fastcall TEDISpecToSEFTranslator(void);
	__fastcall virtual ~TEDISpecToSEFTranslator(void);
	Jcledisef::TEDISEFElement* __fastcall TranslateToSEFElement(Jcledi_ansix12::TEDIElementSpec* ElementSpec, Jcledisef::TEDISEFFile* Parent)/* overload */;
	Jcledisef::TEDISEFElement* __fastcall TranslateToSEFElement(Jcledi_ansix12::TEDIElementSpec* ElementSpec, Jcledisef::TEDISEFSegment* Parent)/* overload */;
	void __fastcall TranslateToSEFElementTEXTSETS(Jcledi_ansix12::TEDIElementSpec* ElementSpec, Jcledisef::TEDISEFElement* SEFElement);
	Jcledisef::TEDISEFSegment* __fastcall TranslateToSEFSegment(Jcledi_ansix12::TEDISegmentSpec* SegmentSpec, Jcledisef::TEDISEFFile* Parent)/* overload */;
	Jcledisef::TEDISEFSegment* __fastcall TranslateToSEFSegment(Jcledi_ansix12::TEDISegmentSpec* SegmentSpec, Jcledisef::TEDISEFTable* Parent)/* overload */;
	Jcledisef::TEDISEFSegment* __fastcall TranslateToSEFSegment(Jcledi_ansix12::TEDISegmentSpec* SegmentSpec, Jcledisef::TEDISEFLoop* Parent)/* overload */;
	void __fastcall TranslateToSEFSegmentTEXTSETS(Jcledi_ansix12::TEDISegmentSpec* SegmentSpec, Jcledisef::TEDISEFSegment* SEFSegment);
	Jcledisef::TEDISEFSet* __fastcall TranslateToSEFSet(Jcledi_ansix12::TEDITransactionSetSpec* TransactionSetSpec, Jcledisef::TEDISEFFile* Parent);
	void __fastcall TranslateLoopToSEFSet(const Jcledi::TEDILoopStackRecord &StackRecord, AnsiString SegmentId, AnsiString OwnerLoopId, AnsiString ParentLoopId, Jcledi::TEDIObject* &EDIObject);
	Jcledisef::TEDISEFFile* __fastcall TranslateToSEFFile(Jcledi_ansix12::TEDIInterchangeControlSpec* ICSpec);
};


class DELPHICLASS TEDISEFToSpecTranslator;
class PASCALIMPLEMENTATION TEDISEFToSpecTranslator : public Jcledi::TEDIObject 
{
	typedef Jcledi::TEDIObject inherited;
	
public:
	__fastcall TEDISEFToSpecTranslator(void);
	__fastcall virtual ~TEDISEFToSpecTranslator(void);
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jcleditranslators */
using namespace Jcleditranslators;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcleditranslators
