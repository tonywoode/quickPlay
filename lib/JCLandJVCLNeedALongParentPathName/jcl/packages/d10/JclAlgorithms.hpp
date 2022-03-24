// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclalgorithms.pas' rev: 10.00

#ifndef JclalgorithmsHPP
#define JclalgorithmsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclcontainerintf.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclalgorithms
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclcontainerintf::TIntfSortProc IntfSortProc;
extern PACKAGE Jclcontainerintf::TAnsiStrSortProc AnsiStrSortProc;
extern PACKAGE Jclcontainerintf::TWideStrSortProc WideStrSortProc;
extern PACKAGE Jclcontainerintf::TSingleSortProc SingleSortProc;
extern PACKAGE Jclcontainerintf::TDoubleSortProc DoubleSortProc;
extern PACKAGE Jclcontainerintf::TExtendedSortProc ExtendedSortProc;
extern PACKAGE Jclcontainerintf::TIntegerSortProc IntegerSortProc;
extern PACKAGE Jclcontainerintf::TCardinalSortProc CardinalSortProc;
extern PACKAGE Jclcontainerintf::TInt64SortProc Int64SortProc;
extern PACKAGE Jclcontainerintf::TPtrSortProc PtrSortProc;
extern PACKAGE Jclcontainerintf::TSortProc SortProc;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE int __fastcall IntfSimpleCompare(const System::_di_IInterface Obj1, const System::_di_IInterface Obj2);
extern PACKAGE int __fastcall AnsiStrSimpleCompare(const AnsiString Obj1, const AnsiString Obj2);
extern PACKAGE int __fastcall WideStrSimpleCompare(const WideString Obj1, const WideString Obj2);
extern PACKAGE int __fastcall StrSimpleCompare(const AnsiString Obj1, const AnsiString Obj2);
extern PACKAGE int __fastcall SingleSimpleCompare(const float Obj1, const float Obj2);
extern PACKAGE int __fastcall DoubleSimpleCompare(const double Obj1, const double Obj2);
extern PACKAGE int __fastcall ExtendedSimpleCompare(const Extended Obj1, const Extended Obj2);
extern PACKAGE int __fastcall FloatSimpleCompare(const Extended Obj1, const Extended Obj2);
extern PACKAGE int __fastcall IntegerSimpleCompare(int Obj1, int Obj2);
extern PACKAGE int __fastcall CardinalSimpleCompare(unsigned Obj1, unsigned Obj2);
extern PACKAGE int __fastcall Int64SimpleCompare(const __int64 Obj1, const __int64 Obj2);
extern PACKAGE int __fastcall PtrSimpleCompare(void * Obj1, void * Obj2);
extern PACKAGE int __fastcall SimpleCompare(System::TObject* Obj1, System::TObject* Obj2);
extern PACKAGE int __fastcall IntegerCompare(System::TObject* Obj1, System::TObject* Obj2);
extern PACKAGE bool __fastcall IntfSimpleEqualityCompare(const System::_di_IInterface Obj1, const System::_di_IInterface Obj2);
extern PACKAGE bool __fastcall AnsiStrSimpleEqualityCompare(const AnsiString Obj1, const AnsiString Obj2);
extern PACKAGE bool __fastcall WideStrSimpleEqualityCompare(const WideString Obj1, const WideString Obj2);
extern PACKAGE bool __fastcall StrSimpleEqualityCompare(const AnsiString Obj1, const AnsiString Obj2);
extern PACKAGE bool __fastcall SingleSimpleEqualityCompare(const float Obj1, const float Obj2);
extern PACKAGE bool __fastcall DoubleSimpleEqualityCompare(const double Obj1, const double Obj2);
extern PACKAGE bool __fastcall ExtendedSimpleEqualityCompare(const Extended Obj1, const Extended Obj2);
extern PACKAGE bool __fastcall FloatSimpleEqualityCompare(const Extended Obj1, const Extended Obj2);
extern PACKAGE bool __fastcall IntegerSimpleEqualityCompare(int Obj1, int Obj2);
extern PACKAGE bool __fastcall CardinalSimpleEqualityCompare(unsigned Obj1, unsigned Obj2);
extern PACKAGE bool __fastcall Int64SimpleEqualityCompare(const __int64 Obj1, const __int64 Obj2);
extern PACKAGE bool __fastcall PtrSimpleEqualityCompare(void * Obj1, void * Obj2);
extern PACKAGE bool __fastcall SimpleEqualityCompare(System::TObject* Obj1, System::TObject* Obj2);
extern PACKAGE void __fastcall Apply(const Jclcontainerintf::_di_IJclIntfIterator First, int Count, Jclcontainerintf::TIntfApplyFunction F)/* overload */;
extern PACKAGE void __fastcall Apply(const Jclcontainerintf::_di_IJclAnsiStrIterator First, int Count, Jclcontainerintf::TAnsiStrApplyFunction F)/* overload */;
extern PACKAGE void __fastcall Apply(const Jclcontainerintf::_di_IJclWideStrIterator First, int Count, Jclcontainerintf::TWideStrApplyFunction F)/* overload */;
extern PACKAGE void __fastcall Apply(const Jclcontainerintf::_di_IJclSingleIterator First, int Count, Jclcontainerintf::TSingleApplyFunction F)/* overload */;
extern PACKAGE void __fastcall Apply(const Jclcontainerintf::_di_IJclDoubleIterator First, int Count, Jclcontainerintf::TDoubleApplyFunction F)/* overload */;
extern PACKAGE void __fastcall Apply(const Jclcontainerintf::_di_IJclExtendedIterator First, int Count, Jclcontainerintf::TExtendedApplyFunction F)/* overload */;
extern PACKAGE void __fastcall Apply(const Jclcontainerintf::_di_IJclIntegerIterator First, int Count, Jclcontainerintf::TIntegerApplyFunction F)/* overload */;
extern PACKAGE void __fastcall Apply(const Jclcontainerintf::_di_IJclCardinalIterator First, int Count, Jclcontainerintf::TCardinalApplyFunction F)/* overload */;
extern PACKAGE void __fastcall Apply(const Jclcontainerintf::_di_IJclInt64Iterator First, int Count, Jclcontainerintf::TInt64ApplyFunction F)/* overload */;
extern PACKAGE void __fastcall Apply(const Jclcontainerintf::_di_IJclPtrIterator First, int Count, Jclcontainerintf::TPtrApplyFunction F)/* overload */;
extern PACKAGE void __fastcall Apply(const Jclcontainerintf::_di_IJclIterator First, int Count, Jclcontainerintf::TApplyFunction F)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclIntfIterator __fastcall Find(const Jclcontainerintf::_di_IJclIntfIterator First, int Count, const System::_di_IInterface AInterface, Jclcontainerintf::TIntfCompare AComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclIntfIterator __fastcall Find(const Jclcontainerintf::_di_IJclIntfIterator First, int Count, const System::_di_IInterface AInterface, Jclcontainerintf::TIntfEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclAnsiStrIterator __fastcall Find(const Jclcontainerintf::_di_IJclAnsiStrIterator First, int Count, const AnsiString AString, Jclcontainerintf::TAnsiStrCompare AComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclAnsiStrIterator __fastcall Find(const Jclcontainerintf::_di_IJclAnsiStrIterator First, int Count, const AnsiString AString, Jclcontainerintf::TAnsiStrEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclWideStrIterator __fastcall Find(const Jclcontainerintf::_di_IJclWideStrIterator First, int Count, const WideString AString, Jclcontainerintf::TWideStrCompare AComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclWideStrIterator __fastcall Find(const Jclcontainerintf::_di_IJclWideStrIterator First, int Count, const WideString AString, Jclcontainerintf::TWideStrEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclSingleIterator __fastcall Find(const Jclcontainerintf::_di_IJclSingleIterator First, int Count, const float AValue, Jclcontainerintf::TSingleCompare AComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclSingleIterator __fastcall Find(const Jclcontainerintf::_di_IJclSingleIterator First, int Count, const float AValue, Jclcontainerintf::TSingleEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclDoubleIterator __fastcall Find(const Jclcontainerintf::_di_IJclDoubleIterator First, int Count, const double AValue, Jclcontainerintf::TDoubleCompare AComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclDoubleIterator __fastcall Find(const Jclcontainerintf::_di_IJclDoubleIterator First, int Count, const double AValue, Jclcontainerintf::TDoubleEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclExtendedIterator __fastcall Find(const Jclcontainerintf::_di_IJclExtendedIterator First, int Count, const Extended AValue, Jclcontainerintf::TExtendedCompare AComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclExtendedIterator __fastcall Find(const Jclcontainerintf::_di_IJclExtendedIterator First, int Count, const Extended AValue, Jclcontainerintf::TExtendedEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclIntegerIterator __fastcall Find(const Jclcontainerintf::_di_IJclIntegerIterator First, int Count, int AValue, Jclcontainerintf::TIntegerCompare AComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclIntegerIterator __fastcall Find(const Jclcontainerintf::_di_IJclIntegerIterator First, int Count, int AValue, Jclcontainerintf::TIntegerEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclCardinalIterator __fastcall Find(const Jclcontainerintf::_di_IJclCardinalIterator First, int Count, unsigned AValue, Jclcontainerintf::TCardinalCompare AComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclCardinalIterator __fastcall Find(const Jclcontainerintf::_di_IJclCardinalIterator First, int Count, unsigned AValue, Jclcontainerintf::TCardinalEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclInt64Iterator __fastcall Find(const Jclcontainerintf::_di_IJclInt64Iterator First, int Count, const __int64 AValue, Jclcontainerintf::TInt64Compare AComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclInt64Iterator __fastcall Find(const Jclcontainerintf::_di_IJclInt64Iterator First, int Count, const __int64 AValue, Jclcontainerintf::TInt64EqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclPtrIterator __fastcall Find(const Jclcontainerintf::_di_IJclPtrIterator First, int Count, void * APtr, Jclcontainerintf::TPtrCompare AComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclPtrIterator __fastcall Find(const Jclcontainerintf::_di_IJclPtrIterator First, int Count, void * APtr, Jclcontainerintf::TPtrEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclIterator __fastcall Find(const Jclcontainerintf::_di_IJclIterator First, int Count, System::TObject* AObject, Jclcontainerintf::TCompare AComparator)/* overload */;
extern PACKAGE Jclcontainerintf::_di_IJclIterator __fastcall Find(const Jclcontainerintf::_di_IJclIterator First, int Count, System::TObject* AObject, Jclcontainerintf::TEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclIntfIterator First, int Count, const System::_di_IInterface AInterface, Jclcontainerintf::TIntfCompare AComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclIntfIterator First, int Count, const System::_di_IInterface AInterface, Jclcontainerintf::TIntfEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclAnsiStrIterator First, int Count, const AnsiString AString, Jclcontainerintf::TAnsiStrCompare AComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclAnsiStrIterator First, int Count, const AnsiString AString, Jclcontainerintf::TAnsiStrEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclWideStrIterator First, int Count, const WideString AString, Jclcontainerintf::TWideStrCompare AComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclWideStrIterator First, int Count, const WideString AString, Jclcontainerintf::TWideStrEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclSingleIterator First, int Count, const float AValue, Jclcontainerintf::TSingleCompare AComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclSingleIterator First, int Count, const float AValue, Jclcontainerintf::TSingleEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclDoubleIterator First, int Count, const double AValue, Jclcontainerintf::TDoubleCompare AComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclDoubleIterator First, int Count, const double AValue, Jclcontainerintf::TDoubleEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclExtendedIterator First, int Count, const Extended AValue, Jclcontainerintf::TExtendedCompare AComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclExtendedIterator First, int Count, const Extended AValue, Jclcontainerintf::TExtendedEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclIntegerIterator First, int Count, int AValue, Jclcontainerintf::TIntegerCompare AComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclIntegerIterator First, int Count, int AValue, Jclcontainerintf::TIntegerEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclCardinalIterator First, int Count, unsigned AValue, Jclcontainerintf::TCardinalCompare AComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclCardinalIterator First, int Count, unsigned AValue, Jclcontainerintf::TCardinalEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclInt64Iterator First, int Count, const __int64 AValue, Jclcontainerintf::TInt64Compare AComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclInt64Iterator First, int Count, const __int64 AValue, Jclcontainerintf::TInt64EqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclPtrIterator First, int Count, void * APtr, Jclcontainerintf::TPtrCompare AComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclPtrIterator First, int Count, void * APtr, Jclcontainerintf::TPtrEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclIterator First, int Count, System::TObject* AObject, Jclcontainerintf::TCompare AComparator)/* overload */;
extern PACKAGE int __fastcall CountObject(const Jclcontainerintf::_di_IJclIterator First, int Count, System::TObject* AObject, Jclcontainerintf::TEqualityCompare AEqualityComparator)/* overload */;
extern PACKAGE void __fastcall Copy(const Jclcontainerintf::_di_IJclIntfIterator First, int Count, const Jclcontainerintf::_di_IJclIntfIterator Output)/* overload */;
extern PACKAGE void __fastcall Copy(const Jclcontainerintf::_di_IJclAnsiStrIterator First, int Count, const Jclcontainerintf::_di_IJclAnsiStrIterator Output)/* overload */;
extern PACKAGE void __fastcall Copy(const Jclcontainerintf::_di_IJclWideStrIterator First, int Count, const Jclcontainerintf::_di_IJclWideStrIterator Output)/* overload */;
extern PACKAGE void __fastcall Copy(const Jclcontainerintf::_di_IJclSingleIterator First, int Count, const Jclcontainerintf::_di_IJclSingleIterator Output)/* overload */;
extern PACKAGE void __fastcall Copy(const Jclcontainerintf::_di_IJclDoubleIterator First, int Count, const Jclcontainerintf::_di_IJclDoubleIterator Output)/* overload */;
extern PACKAGE void __fastcall Copy(const Jclcontainerintf::_di_IJclExtendedIterator First, int Count, const Jclcontainerintf::_di_IJclExtendedIterator Output)/* overload */;
extern PACKAGE void __fastcall Copy(const Jclcontainerintf::_di_IJclIntegerIterator First, int Count, const Jclcontainerintf::_di_IJclIntegerIterator Output)/* overload */;
extern PACKAGE void __fastcall Copy(const Jclcontainerintf::_di_IJclCardinalIterator First, int Count, const Jclcontainerintf::_di_IJclCardinalIterator Output)/* overload */;
extern PACKAGE void __fastcall Copy(const Jclcontainerintf::_di_IJclInt64Iterator First, int Count, const Jclcontainerintf::_di_IJclInt64Iterator Output)/* overload */;
extern PACKAGE void __fastcall Copy(const Jclcontainerintf::_di_IJclPtrIterator First, int Count, const Jclcontainerintf::_di_IJclPtrIterator Output)/* overload */;
extern PACKAGE void __fastcall Copy(const Jclcontainerintf::_di_IJclIterator First, int Count, const Jclcontainerintf::_di_IJclIterator Output)/* overload */;
extern PACKAGE void __fastcall Generate(const Jclcontainerintf::_di_IJclIntfList List, int Count, const System::_di_IInterface AInterface)/* overload */;
extern PACKAGE void __fastcall Generate(const Jclcontainerintf::_di_IJclAnsiStrList List, int Count, const AnsiString AString)/* overload */;
extern PACKAGE void __fastcall Generate(const Jclcontainerintf::_di_IJclWideStrList List, int Count, const WideString AString)/* overload */;
extern PACKAGE void __fastcall Generate(const Jclcontainerintf::_di_IJclSingleList List, int Count, const float AValue)/* overload */;
extern PACKAGE void __fastcall Generate(const Jclcontainerintf::_di_IJclDoubleList List, int Count, const double AValue)/* overload */;
extern PACKAGE void __fastcall Generate(const Jclcontainerintf::_di_IJclExtendedList List, int Count, const Extended AValue)/* overload */;
extern PACKAGE void __fastcall Generate(const Jclcontainerintf::_di_IJclIntegerList List, int Count, int AValue)/* overload */;
extern PACKAGE void __fastcall Generate(const Jclcontainerintf::_di_IJclCardinalList List, int Count, unsigned AValue)/* overload */;
extern PACKAGE void __fastcall Generate(const Jclcontainerintf::_di_IJclInt64List List, int Count, const __int64 AValue)/* overload */;
extern PACKAGE void __fastcall Generate(const Jclcontainerintf::_di_IJclPtrList List, int Count, void * APtr)/* overload */;
extern PACKAGE void __fastcall Generate(const Jclcontainerintf::_di_IJclList List, int Count, System::TObject* AObject)/* overload */;
extern PACKAGE void __fastcall Fill(const Jclcontainerintf::_di_IJclIntfIterator First, int Count, const System::_di_IInterface AInterface)/* overload */;
extern PACKAGE void __fastcall Fill(const Jclcontainerintf::_di_IJclAnsiStrIterator First, int Count, const AnsiString AString)/* overload */;
extern PACKAGE void __fastcall Fill(const Jclcontainerintf::_di_IJclWideStrIterator First, int Count, const WideString AString)/* overload */;
extern PACKAGE void __fastcall Fill(const Jclcontainerintf::_di_IJclSingleIterator First, int Count, const float AValue)/* overload */;
extern PACKAGE void __fastcall Fill(const Jclcontainerintf::_di_IJclDoubleIterator First, int Count, const double AValue)/* overload */;
extern PACKAGE void __fastcall Fill(const Jclcontainerintf::_di_IJclExtendedIterator First, int Count, const Extended AValue)/* overload */;
extern PACKAGE void __fastcall Fill(const Jclcontainerintf::_di_IJclIntegerIterator First, int Count, int AValue)/* overload */;
extern PACKAGE void __fastcall Fill(const Jclcontainerintf::_di_IJclCardinalIterator First, int Count, unsigned AValue)/* overload */;
extern PACKAGE void __fastcall Fill(const Jclcontainerintf::_di_IJclInt64Iterator First, int Count, const __int64 AValue)/* overload */;
extern PACKAGE void __fastcall Fill(const Jclcontainerintf::_di_IJclPtrIterator First, int Count, void * APtr)/* overload */;
extern PACKAGE void __fastcall Fill(const Jclcontainerintf::_di_IJclIterator First, int Count, System::TObject* AObject)/* overload */;
extern PACKAGE void __fastcall Reverse(const Jclcontainerintf::_di_IJclIntfIterator First, const Jclcontainerintf::_di_IJclIntfIterator Last)/* overload */;
extern PACKAGE void __fastcall Reverse(const Jclcontainerintf::_di_IJclAnsiStrIterator First, const Jclcontainerintf::_di_IJclAnsiStrIterator Last)/* overload */;
extern PACKAGE void __fastcall Reverse(const Jclcontainerintf::_di_IJclWideStrIterator First, const Jclcontainerintf::_di_IJclWideStrIterator Last)/* overload */;
extern PACKAGE void __fastcall Reverse(const Jclcontainerintf::_di_IJclSingleIterator First, const Jclcontainerintf::_di_IJclSingleIterator Last)/* overload */;
extern PACKAGE void __fastcall Reverse(const Jclcontainerintf::_di_IJclDoubleIterator First, const Jclcontainerintf::_di_IJclDoubleIterator Last)/* overload */;
extern PACKAGE void __fastcall Reverse(const Jclcontainerintf::_di_IJclExtendedIterator First, const Jclcontainerintf::_di_IJclExtendedIterator Last)/* overload */;
extern PACKAGE void __fastcall Reverse(const Jclcontainerintf::_di_IJclIntegerIterator First, const Jclcontainerintf::_di_IJclIntegerIterator Last)/* overload */;
extern PACKAGE void __fastcall Reverse(const Jclcontainerintf::_di_IJclCardinalIterator First, const Jclcontainerintf::_di_IJclCardinalIterator Last)/* overload */;
extern PACKAGE void __fastcall Reverse(const Jclcontainerintf::_di_IJclInt64Iterator First, const Jclcontainerintf::_di_IJclInt64Iterator Last)/* overload */;
extern PACKAGE void __fastcall Reverse(const Jclcontainerintf::_di_IJclPtrIterator First, const Jclcontainerintf::_di_IJclPtrIterator Last)/* overload */;
extern PACKAGE void __fastcall Reverse(const Jclcontainerintf::_di_IJclIterator First, const Jclcontainerintf::_di_IJclIterator Last)/* overload */;
extern PACKAGE void __fastcall QuickSort(const Jclcontainerintf::_di_IJclIntfList AList, int L, int R, Jclcontainerintf::TIntfCompare AComparator)/* overload */;
extern PACKAGE void __fastcall QuickSort(const Jclcontainerintf::_di_IJclAnsiStrList AList, int L, int R, Jclcontainerintf::TAnsiStrCompare AComparator)/* overload */;
extern PACKAGE void __fastcall QuickSort(const Jclcontainerintf::_di_IJclWideStrList AList, int L, int R, Jclcontainerintf::TWideStrCompare AComparator)/* overload */;
extern PACKAGE void __fastcall QuickSort(const Jclcontainerintf::_di_IJclSingleList AList, int L, int R, Jclcontainerintf::TSingleCompare AComparator)/* overload */;
extern PACKAGE void __fastcall QuickSort(const Jclcontainerintf::_di_IJclDoubleList AList, int L, int R, Jclcontainerintf::TDoubleCompare AComparator)/* overload */;
extern PACKAGE void __fastcall QuickSort(const Jclcontainerintf::_di_IJclExtendedList AList, int L, int R, Jclcontainerintf::TExtendedCompare AComparator)/* overload */;
extern PACKAGE void __fastcall QuickSort(const Jclcontainerintf::_di_IJclIntegerList AList, int L, int R, Jclcontainerintf::TIntegerCompare AComparator)/* overload */;
extern PACKAGE void __fastcall QuickSort(const Jclcontainerintf::_di_IJclCardinalList AList, int L, int R, Jclcontainerintf::TCardinalCompare AComparator)/* overload */;
extern PACKAGE void __fastcall QuickSort(const Jclcontainerintf::_di_IJclInt64List AList, int L, int R, Jclcontainerintf::TInt64Compare AComparator)/* overload */;
extern PACKAGE void __fastcall QuickSort(const Jclcontainerintf::_di_IJclPtrList AList, int L, int R, Jclcontainerintf::TPtrCompare AComparator)/* overload */;
extern PACKAGE void __fastcall QuickSort(const Jclcontainerintf::_di_IJclList AList, int L, int R, Jclcontainerintf::TCompare AComparator)/* overload */;
extern PACKAGE void __fastcall Sort(const Jclcontainerintf::_di_IJclIntfList AList, int First, int Last, Jclcontainerintf::TIntfCompare AComparator)/* overload */;
extern PACKAGE void __fastcall Sort(const Jclcontainerintf::_di_IJclAnsiStrList AList, int First, int Last, Jclcontainerintf::TAnsiStrCompare AComparator)/* overload */;
extern PACKAGE void __fastcall Sort(const Jclcontainerintf::_di_IJclWideStrList AList, int First, int Last, Jclcontainerintf::TWideStrCompare AComparator)/* overload */;
extern PACKAGE void __fastcall Sort(const Jclcontainerintf::_di_IJclSingleList AList, int First, int Last, Jclcontainerintf::TSingleCompare AComparator)/* overload */;
extern PACKAGE void __fastcall Sort(const Jclcontainerintf::_di_IJclDoubleList AList, int First, int Last, Jclcontainerintf::TDoubleCompare AComparator)/* overload */;
extern PACKAGE void __fastcall Sort(const Jclcontainerintf::_di_IJclExtendedList AList, int First, int Last, Jclcontainerintf::TExtendedCompare AComparator)/* overload */;
extern PACKAGE void __fastcall Sort(const Jclcontainerintf::_di_IJclIntegerList AList, int First, int Last, Jclcontainerintf::TIntegerCompare AComparator)/* overload */;
extern PACKAGE void __fastcall Sort(const Jclcontainerintf::_di_IJclCardinalList AList, int First, int Last, Jclcontainerintf::TCardinalCompare AComparator)/* overload */;
extern PACKAGE void __fastcall Sort(const Jclcontainerintf::_di_IJclInt64List AList, int First, int Last, Jclcontainerintf::TInt64Compare AComparator)/* overload */;
extern PACKAGE void __fastcall Sort(const Jclcontainerintf::_di_IJclPtrList AList, int First, int Last, Jclcontainerintf::TPtrCompare AComparator)/* overload */;
extern PACKAGE void __fastcall Sort(const Jclcontainerintf::_di_IJclList AList, int First, int Last, Jclcontainerintf::TCompare AComparator)/* overload */;

}	/* namespace Jclalgorithms */
using namespace Jclalgorithms;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclalgorithms
