// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclstringlists.pas' rev: 10.00

#ifndef JclstringlistsHPP
#define JclstringlistsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclpcre.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclstringlists
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TJclStringListObjectsMode { omNone, omObjects, omVariants, omInterfaces };
#pragma option pop

__interface IJclStringList;
typedef System::DelphiInterface<IJclStringList> _di_IJclStringList;
typedef int __fastcall (*TJclStringListSortCompare)(_di_IJclStringList List, int Index1, int Index2);

__interface  INTERFACE_UUID("{8DC5B71C-4756-404D-8636-7872CD299796}") IJclStringList  : public IInterface 
{
	
public:
	AnsiString operator[](int Index) { return Strings[Index]; }
	
public:
	virtual int __fastcall Add(const AnsiString S) = 0 /* overload */;
	virtual int __fastcall AddObject(const AnsiString S, System::TObject* AObject) = 0 ;
	virtual AnsiString __fastcall Get(int Index) = 0 ;
	virtual int __fastcall GetCapacity(void) = 0 ;
	virtual int __fastcall GetCount(void) = 0 ;
	virtual System::TObject* __fastcall GetObjects(int Index) = 0 ;
	virtual AnsiString __fastcall GetTextStr(void) = 0 ;
	virtual AnsiString __fastcall GetValue(const AnsiString Name) = 0 ;
	virtual bool __fastcall Find(const AnsiString S, int &Index) = 0 ;
	virtual int __fastcall IndexOf(const AnsiString S) = 0 ;
	virtual bool __fastcall GetCaseSensitive(void) = 0 ;
	virtual Classes::TDuplicates __fastcall GetDuplicates(void) = 0 ;
	virtual Classes::TNotifyEvent __fastcall GetOnChange(void) = 0 ;
	virtual Classes::TNotifyEvent __fastcall GetOnChanging(void) = 0 ;
	virtual bool __fastcall GetSorted(void) = 0 ;
	virtual bool __fastcall Equals(Classes::TStrings* Strings) = 0 ;
	virtual int __fastcall IndexOfName(const AnsiString Name) = 0 ;
	virtual int __fastcall IndexOfObject(System::TObject* AObject) = 0 ;
	virtual _di_IJclStringList __fastcall LoadFromFile(const AnsiString FileName) = 0 ;
	virtual _di_IJclStringList __fastcall LoadFromStream(Classes::TStream* Stream) = 0 ;
	virtual _di_IJclStringList __fastcall SaveToFile(const AnsiString FileName) = 0 ;
	virtual _di_IJclStringList __fastcall SaveToStream(Classes::TStream* Stream) = 0 ;
	virtual AnsiString __fastcall GetCommaText(void) = 0 ;
	virtual AnsiString __fastcall GetDelimitedText(void) = 0 ;
	virtual char __fastcall GetDelimiter(void) = 0 ;
	virtual AnsiString __fastcall GetName(int Index) = 0 ;
	virtual char __fastcall GetNameValueSeparator(void) = 0 ;
	virtual AnsiString __fastcall GetValueFromIndex(int Index) = 0 ;
	virtual char __fastcall GetQuoteChar(void) = 0 ;
	virtual void __fastcall SetCommaText(const AnsiString Value) = 0 ;
	virtual void __fastcall SetDelimitedText(const AnsiString Value) = 0 ;
	virtual void __fastcall SetDelimiter(const char Value) = 0 ;
	virtual void __fastcall SetNameValueSeparator(const char Value) = 0 ;
	virtual void __fastcall SetValueFromIndex(int Index, const AnsiString Value) = 0 ;
	virtual void __fastcall SetQuoteChar(const char Value) = 0 ;
	virtual void __fastcall AddStrings(Classes::TStrings* Strings) = 0 /* overload */;
	virtual void __fastcall SetObjects(int Index, const System::TObject* Value) = 0 ;
	virtual void __fastcall Put(int Index, const AnsiString S) = 0 ;
	virtual void __fastcall SetCapacity(int NewCapacity) = 0 ;
	virtual void __fastcall SetTextStr(const AnsiString Value) = 0 ;
	virtual void __fastcall SetValue(const AnsiString Name, const AnsiString Value) = 0 ;
	virtual void __fastcall SetCaseSensitive(const bool Value) = 0 ;
	virtual void __fastcall SetDuplicates(const Classes::TDuplicates Value) = 0 ;
	virtual void __fastcall SetOnChange(const Classes::TNotifyEvent Value) = 0 ;
	virtual void __fastcall SetOnChanging(const Classes::TNotifyEvent Value) = 0 ;
	virtual void __fastcall SetSorted(const bool Value) = 0 ;
	__property int Count = {read=GetCount};
	__property AnsiString Strings[int Index] = {read=Get, write=Put/*, default*/};
	__property AnsiString Text = {read=GetTextStr, write=SetTextStr};
	__property System::TObject* Objects[int Index] = {read=GetObjects, write=SetObjects};
	__property int Capacity = {read=GetCapacity, write=SetCapacity};
	__property AnsiString Values[AnsiString Name] = {read=GetValue, write=SetValue};
	__property Classes::TDuplicates Duplicates = {read=GetDuplicates, write=SetDuplicates};
	__property bool Sorted = {read=GetSorted, write=SetSorted};
	__property bool CaseSensitive = {read=GetCaseSensitive, write=SetCaseSensitive};
	__property Classes::TNotifyEvent OnChange = {read=GetOnChange, write=SetOnChange};
	__property Classes::TNotifyEvent OnChanging = {read=GetOnChanging, write=SetOnChanging};
	__property AnsiString DelimitedText = {read=GetDelimitedText, write=SetDelimitedText};
	__property char Delimiter = {read=GetDelimiter, write=SetDelimiter};
	__property AnsiString Names[int Index] = {read=GetName};
	__property char QuoteChar = {read=GetQuoteChar, write=SetQuoteChar};
	__property AnsiString CommaText = {read=GetCommaText, write=SetCommaText};
	__property AnsiString ValueFromIndex[int Index] = {read=GetValueFromIndex, write=SetValueFromIndex};
	__property char NameValueSeparator = {read=GetNameValueSeparator, write=SetNameValueSeparator};
	virtual _di_IJclStringList __fastcall Assign(Classes::TPersistent* Source) = 0 ;
	virtual _di_IJclStringList __fastcall LoadExeParams(void) = 0 ;
	virtual bool __fastcall Exists(const AnsiString S) = 0 ;
	virtual bool __fastcall ExistsName(const AnsiString S) = 0 ;
	virtual _di_IJclStringList __fastcall DeleteBlanks(void) = 0 ;
	virtual _di_IJclStringList __fastcall KeepIntegers(void) = 0 ;
	virtual _di_IJclStringList __fastcall DeleteIntegers(void) = 0 ;
	virtual _di_IJclStringList __fastcall ReleaseInterfaces(void) = 0 ;
	virtual _di_IJclStringList __fastcall FreeObjects(bool AFreeAndNil = false) = 0 ;
	virtual _di_IJclStringList __fastcall Clone(void) = 0 ;
	virtual _di_IJclStringList __fastcall Insert(int Index, const AnsiString S) = 0 ;
	virtual _di_IJclStringList __fastcall InsertObject(int Index, const AnsiString S, System::TObject* AObject) = 0 ;
	virtual _di_IJclStringList __fastcall Sort(TJclStringListSortCompare ACompareFunction = 0x0) = 0 ;
	virtual _di_IJclStringList __fastcall SortAsInteger(void) = 0 ;
	virtual _di_IJclStringList __fastcall SortByName(void) = 0 ;
	virtual _di_IJclStringList __fastcall Delete(int AIndex) = 0 /* overload */;
	virtual _di_IJclStringList __fastcall Delete(const AnsiString AString) = 0 /* overload */;
	virtual _di_IJclStringList __fastcall Exchange(int Index1, int Index2) = 0 ;
	virtual _di_IJclStringList __fastcall Add(System::TVarRec const * A, const int A_Size) = 0 /* overload */;
	virtual _di_IJclStringList __fastcall AddStrings(AnsiString const * A, const int A_Size) = 0 /* overload */;
	virtual _di_IJclStringList __fastcall BeginUpdate(void) = 0 ;
	virtual _di_IJclStringList __fastcall EndUpdate(void) = 0 ;
	virtual _di_IJclStringList __fastcall Trim(void) = 0 ;
	virtual AnsiString __fastcall Join(const AnsiString ASeparator = "") = 0 ;
	virtual _di_IJclStringList __fastcall Split(const AnsiString AText, const AnsiString ASeparator, bool AClearBeforeAdd = true) = 0 ;
	virtual _di_IJclStringList __fastcall ExtractWords(const AnsiString AText, const Jclbase::TSetOfAnsiChar &ADelims = (Set<char, 0, 255> () << '\x0' << '\x1' << '\x2' << '\x3' << '\x4' << '\x5' << '\x6' << '\x7' << '\x8' << '\x9' << '\xa' << '\xb' << '\xc' << '\xd' << '\xe' << '\xf' << '\x10' << '\x11' << '\x12' << '\x13' << '\x14' << '\x15' << '\x16' << '\x17' << '\x18' << '\x19' << '\x1a' << '\x1b' << '\x1c' << '\x1d' << '\x1e' << '\x1f' << '\x20' << '\x21' << '\x22' << '\x23' << '\x24' << '\x25' << '\x26' << '\x27' << '\x28' << '\x29' << '\x2a' << '\x2b' << '\x2c' << '\x2d' << '\x2e' << '\x2f' << '\x30' << '\x31' << '\x32' << '\x33' << '\x34' << '\x35' << '\x36' << '\x37' << '\x38' << '\x39' << '\x3a' << '\x3b' << '\x3c' << '\x3d' << '\x3e' << '\x3f' << '\x40' << '\x41' << '\x42' << '\x43' << '\x44' << '\x45' << '\x46' << '\x47' << '\x48' << '\x49' << '\x4a' << '\x4b' << '\x4c' << '\x4d' << '\x4e' << '\x4f' << '\x50' << '\x51' << '\x52' << '\x53' << '\x54' << '\x55' << '\x56' << '\x57' << '\x58' << '\x59' \
		<< '\x5a' << '\x5b' << '\x5c' << '\x5d' << '\x5e' << '\x5f' << '\x60' << '\x61' << '\x62' << '\x63' << '\x64' << '\x65' << '\x66' << '\x67' << '\x68' << '\x69' << '\x6a' << '\x6b' << '\x6c' << '\x6d' << '\x6e' << '\x6f' << '\x70' << '\x71' << '\x72' << '\x73' << '\x74' << '\x75' << '\x76' << '\x77' << '\x78' << '\x79' << '\x7a' << '\x7b' << '\x7c' << '\x7d' << '\x7e' << '\x7f' << '\x80' << '\x81' << '\x82' << '\x83' << '\x84' << '\x85' << '\x86' << '\x87' << '\x88' << '\x89' << '\x8a' << '\x8b' << '\x8c' << '\x8d' << '\x8e' << '\x8f' << '\x90' << '\x91' << '\x92' << '\x93' << '\x94' << '\x95' << '\x96' << '\x97' << '\x98' << '\x99' << '\x9a' << '\x9b' << '\x9c' << '\x9d' << '\x9e' << '\x9f' << '\xa0' << '\xa1' << '\xa2' << '\xa3' << '\xa4' << '\xa5' << '\xa6' << '\xa7' << '\xa8' << '\xa9' << '\xaa' << '\xab' << '\xac' << '\xad' << '\xae' << '\xaf' << '\xb0' << '\xb1' << '\xb2' << '\xb3' << '\xb4' << '\xb5' << '\xb6' << '\xb7' << '\xb8' << '\xb9' << '\xba' << '\xbb' << '\xbc' << '\xbd' << '\xbe' << '\xbf' << '\xc0' \
		<< '\xc1' << '\xc2' << '\xc3' << '\xc4' << '\xc5' << '\xc6' << '\xc7' << '\xc8' << '\xc9' << '\xca' << '\xcb' << '\xcc' << '\xcd' << '\xce' << '\xcf' << '\xd0' << '\xd1' << '\xd2' << '\xd3' << '\xd4' << '\xd5' << '\xd6' << '\xd7' << '\xd8' << '\xd9' << '\xda' << '\xdb' << '\xdc' << '\xdd' << '\xde' << '\xdf' << '\xe0' << '\xe1' << '\xe2' << '\xe3' << '\xe4' << '\xe5' << '\xe6' << '\xe7' << '\xe8' << '\xe9' << '\xea' << '\xeb' << '\xec' << '\xed' << '\xee' << '\xef' << '\xf0' << '\xf1' << '\xf2' << '\xf3' << '\xf4' << '\xf5' << '\xf6' << '\xf7' << '\xf8' << '\xf9' << '\xfa' << '\xfb' << '\xfc' << '\xfd' << '\xfe' << '\xff' ), bool AClearBeforeAdd = true) = 0 ;
	virtual AnsiString __fastcall Last(void) = 0 ;
	virtual AnsiString __fastcall First(void) = 0 ;
	virtual int __fastcall LastIndex(void) = 0 ;
	virtual _di_IJclStringList __fastcall Clear(void) = 0 ;
	virtual _di_IJclStringList __fastcall DeleteRegEx(const AnsiString APattern) = 0 ;
	virtual _di_IJclStringList __fastcall KeepRegEx(const AnsiString APattern) = 0 ;
	virtual _di_IJclStringList __fastcall Files(const AnsiString APattern = "*", bool ARecursive = false, const AnsiString ARegExPattern = "") = 0 ;
	virtual _di_IJclStringList __fastcall Directories(const AnsiString APattern = "*", bool ARecursive = false, const AnsiString ARegExPattern = "") = 0 ;
	virtual Classes::TStrings* __fastcall GetStringsRef(void) = 0 ;
	virtual _di_IJclStringList __fastcall ConfigAsSet(void) = 0 ;
	virtual _di_IJclStringList __fastcall Delimit(const AnsiString ADelimiter) = 0 ;
	virtual System::_di_IInterface __fastcall GetInterfaceByIndex(int Index) = 0 ;
	virtual _di_IJclStringList __fastcall GetLists(int Index) = 0 ;
	virtual Variant __fastcall GetVariants(int AIndex) = 0 ;
	virtual System::_di_IInterface __fastcall GetKeyInterface(const AnsiString AKey) = 0 ;
	virtual System::TObject* __fastcall GetKeyObject(const AnsiString AKey) = 0 ;
	virtual Variant __fastcall GetKeyVariant(const AnsiString AKey) = 0 ;
	virtual _di_IJclStringList __fastcall GetKeyList(const AnsiString AKey) = 0 ;
	virtual TJclStringListObjectsMode __fastcall GetObjectsMode(void) = 0 ;
	virtual void __fastcall SetInterfaceByIndex(int Index, const System::_di_IInterface Value) = 0 ;
	virtual void __fastcall SetLists(int Index, const _di_IJclStringList Value) = 0 ;
	virtual void __fastcall SetVariants(int Index, const Variant &Value) = 0 ;
	virtual void __fastcall SetKeyInterface(const AnsiString AKey, const System::_di_IInterface Value) = 0 ;
	virtual void __fastcall SetKeyObject(const AnsiString AKey, const System::TObject* Value) = 0 ;
	virtual void __fastcall SetKeyVariant(const AnsiString AKey, const Variant &Value) = 0 ;
	virtual void __fastcall SetKeyList(const AnsiString AKey, const _di_IJclStringList Value) = 0 ;
	__property System::_di_IInterface Interfaces[int Index] = {read=GetInterfaceByIndex, write=SetInterfaceByIndex};
	__property _di_IJclStringList Lists[int Index] = {read=GetLists, write=SetLists};
	__property Variant Variants[int Index] = {read=GetVariants, write=SetVariants};
	__property _di_IJclStringList KeyList[AnsiString AKey] = {read=GetKeyList, write=SetKeyList};
	__property System::TObject* KeyObject[AnsiString AKey] = {read=GetKeyObject, write=SetKeyObject};
	__property System::_di_IInterface KeyInterface[AnsiString AKey] = {read=GetKeyInterface, write=SetKeyInterface};
	__property Variant KeyVariant[AnsiString AKey] = {read=GetKeyVariant, write=SetKeyVariant};
	__property TJclStringListObjectsMode ObjectsMode = {read=GetObjectsMode};
};

class DELPHICLASS TJclUpdateControl;
class PASCALIMPLEMENTATION TJclUpdateControl : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TStrings* FStrings;
	
public:
	__fastcall TJclUpdateControl(Classes::TStrings* AStrings);
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclUpdateControl(void) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclStringList;
class PASCALIMPLEMENTATION TJclStringList : public Classes::TStringList 
{
	typedef Classes::TStringList inherited;
	
public:
	AnsiString operator[](int Index) { return Strings[Index]; }
	
private:
	TJclStringListObjectsMode FObjectsMode;
	_di_IJclStringList FSelfAsInterface;
	AnsiString FLastRegExPattern;
	Jclpcre::TJclRegEx* FRegEx;
	TJclUpdateControl* FUpdateControl;
	TJclStringListSortCompare FCompareFunction;
	System::_di_IInterface __fastcall AutoUpdateControl();
	bool __fastcall CanFreeObjects(void);
	bool __fastcall MatchRegEx(const AnsiString S, const AnsiString APattern);
	void __fastcall EnsureObjectsMode(TJclStringListObjectsMode AMode);
	
protected:
	int FRefCount;
	
public:
	__fastcall TJclStringList(void);
	__fastcall virtual ~TJclStringList(void);
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	System::TObject* __fastcall GetObjects(int Index);
	HIDESBASE AnsiString __fastcall GetValue(const AnsiString Name);
	bool __fastcall GetCaseSensitive(void);
	Classes::TDuplicates __fastcall GetDuplicates(void);
	Classes::TNotifyEvent __fastcall GetOnChange();
	Classes::TNotifyEvent __fastcall GetOnChanging();
	bool __fastcall GetSorted(void);
	HIDESBASE _di_IJclStringList __fastcall LoadFromFile(const AnsiString FileName);
	HIDESBASE _di_IJclStringList __fastcall LoadFromStream(Classes::TStream* Stream);
	HIDESBASE _di_IJclStringList __fastcall SaveToFile(const AnsiString FileName);
	HIDESBASE _di_IJclStringList __fastcall SaveToStream(Classes::TStream* Stream);
	HIDESBASE AnsiString __fastcall GetCommaText();
	HIDESBASE AnsiString __fastcall GetDelimitedText();
	HIDESBASE char __fastcall GetDelimiter(void);
	HIDESBASE AnsiString __fastcall GetName(int Index);
	HIDESBASE char __fastcall GetNameValueSeparator(void);
	HIDESBASE AnsiString __fastcall GetValueFromIndex(int Index);
	HIDESBASE char __fastcall GetQuoteChar(void);
	HIDESBASE void __fastcall SetCommaText(const AnsiString Value);
	HIDESBASE void __fastcall SetDelimitedText(const AnsiString Value);
	HIDESBASE void __fastcall SetDelimiter(const char Value);
	HIDESBASE void __fastcall SetNameValueSeparator(const char Value);
	HIDESBASE void __fastcall SetValueFromIndex(int Index, const AnsiString Value);
	HIDESBASE void __fastcall SetQuoteChar(const char Value);
	void __fastcall SetObjects(int Index, const System::TObject* Value);
	HIDESBASE void __fastcall SetValue(const AnsiString Name, const AnsiString Value);
	HIDESBASE void __fastcall SetCaseSensitive(const bool Value);
	void __fastcall SetDuplicates(const Classes::TDuplicates Value);
	void __fastcall SetOnChange(const Classes::TNotifyEvent Value);
	void __fastcall SetOnChanging(const Classes::TNotifyEvent Value);
	HIDESBASE void __fastcall SetSorted(const bool Value);
	__property int Count = {read=GetCount, nodefault};
	__property AnsiString Strings[int Index] = {read=Get, write=Put/*, default*/};
	__property AnsiString Text = {read=GetTextStr, write=SetTextStr};
	__property System::TObject* Objects[int Index] = {read=GetObjects, write=SetObjects};
	__property int Capacity = {read=GetCapacity, write=SetCapacity, nodefault};
	__property AnsiString Values[AnsiString Name] = {read=GetValue, write=SetValue};
	__property Classes::TDuplicates Duplicates = {read=GetDuplicates, write=SetDuplicates, nodefault};
	__property bool Sorted = {read=GetSorted, write=SetSorted, nodefault};
	__property bool CaseSensitive = {read=GetCaseSensitive, write=SetCaseSensitive, nodefault};
	__property Classes::TNotifyEvent OnChange = {read=GetOnChange, write=SetOnChange};
	__property Classes::TNotifyEvent OnChanging = {read=GetOnChanging, write=SetOnChanging};
	__property AnsiString DelimitedText = {read=GetDelimitedText, write=SetDelimitedText};
	__property char Delimiter = {read=GetDelimiter, write=SetDelimiter, nodefault};
	__property AnsiString Names[int Index] = {read=GetName};
	__property char QuoteChar = {read=GetQuoteChar, write=SetQuoteChar, nodefault};
	__property AnsiString CommaText = {read=GetCommaText, write=SetCommaText};
	__property AnsiString ValueFromIndex[int Index] = {read=GetValueFromIndex, write=SetValueFromIndex};
	__property char NameValueSeparator = {read=GetNameValueSeparator, write=SetNameValueSeparator, nodefault};
	HIDESBASE _di_IJclStringList __fastcall Assign(Classes::TPersistent* Source);
	_di_IJclStringList __fastcall LoadExeParams();
	bool __fastcall Exists(const AnsiString S);
	bool __fastcall ExistsName(const AnsiString S);
	_di_IJclStringList __fastcall DeleteBlanks();
	_di_IJclStringList __fastcall KeepIntegers();
	_di_IJclStringList __fastcall DeleteIntegers();
	_di_IJclStringList __fastcall ReleaseInterfaces();
	_di_IJclStringList __fastcall FreeObjects(bool AFreeAndNil = false);
	_di_IJclStringList __fastcall Clone();
	HIDESBASE _di_IJclStringList __fastcall Insert(int Index, const AnsiString S);
	HIDESBASE _di_IJclStringList __fastcall InsertObject(int Index, const AnsiString S, System::TObject* AObject);
	HIDESBASE _di_IJclStringList __fastcall Sort(TJclStringListSortCompare ACompareFunction = 0x0);
	_di_IJclStringList __fastcall SortAsInteger();
	_di_IJclStringList __fastcall SortByName();
	HIDESBASE _di_IJclStringList __fastcall Delete(int AIndex)/* overload */;
	HIDESBASE _di_IJclStringList __fastcall Delete(const AnsiString AString)/* overload */;
	HIDESBASE _di_IJclStringList __fastcall Exchange(int Index1, int Index2);
	HIDESBASE _di_IJclStringList __fastcall Add(System::TVarRec const * A, const int A_Size)/* overload */;
	HIDESBASE _di_IJclStringList __fastcall AddStrings(AnsiString const * A, const int A_Size)/* overload */;
	HIDESBASE _di_IJclStringList __fastcall BeginUpdate();
	HIDESBASE _di_IJclStringList __fastcall EndUpdate();
	_di_IJclStringList __fastcall Trim();
	AnsiString __fastcall Join(const AnsiString ASeparator = "");
	_di_IJclStringList __fastcall Split(const AnsiString AText, const AnsiString ASeparator, bool AClearBeforeAdd = true);
	_di_IJclStringList __fastcall ExtractWords(const AnsiString AText, const Jclbase::TSetOfAnsiChar &ADelims = (Set<char, 0, 255> () << '\x0' << '\x1' << '\x2' << '\x3' << '\x4' << '\x5' << '\x6' << '\x7' << '\x8' << '\x9' << '\xa' << '\xb' << '\xc' << '\xd' << '\xe' << '\xf' << '\x10' << '\x11' << '\x12' << '\x13' << '\x14' << '\x15' << '\x16' << '\x17' << '\x18' << '\x19' << '\x1a' << '\x1b' << '\x1c' << '\x1d' << '\x1e' << '\x1f' << '\x20' << '\x21' << '\x22' << '\x23' << '\x24' << '\x25' << '\x26' << '\x27' << '\x28' << '\x29' << '\x2a' << '\x2b' << '\x2c' << '\x2d' << '\x2e' << '\x2f' << '\x30' << '\x31' << '\x32' << '\x33' << '\x34' << '\x35' << '\x36' << '\x37' << '\x38' << '\x39' << '\x3a' << '\x3b' << '\x3c' << '\x3d' << '\x3e' << '\x3f' << '\x40' << '\x41' << '\x42' << '\x43' << '\x44' << '\x45' << '\x46' << '\x47' << '\x48' << '\x49' << '\x4a' << '\x4b' << '\x4c' << '\x4d' << '\x4e' << '\x4f' << '\x50' << '\x51' << '\x52' << '\x53' << '\x54' << '\x55' << '\x56' << '\x57' << '\x58' << '\x59' \
		<< '\x5a' << '\x5b' << '\x5c' << '\x5d' << '\x5e' << '\x5f' << '\x60' << '\x61' << '\x62' << '\x63' << '\x64' << '\x65' << '\x66' << '\x67' << '\x68' << '\x69' << '\x6a' << '\x6b' << '\x6c' << '\x6d' << '\x6e' << '\x6f' << '\x70' << '\x71' << '\x72' << '\x73' << '\x74' << '\x75' << '\x76' << '\x77' << '\x78' << '\x79' << '\x7a' << '\x7b' << '\x7c' << '\x7d' << '\x7e' << '\x7f' << '\x80' << '\x81' << '\x82' << '\x83' << '\x84' << '\x85' << '\x86' << '\x87' << '\x88' << '\x89' << '\x8a' << '\x8b' << '\x8c' << '\x8d' << '\x8e' << '\x8f' << '\x90' << '\x91' << '\x92' << '\x93' << '\x94' << '\x95' << '\x96' << '\x97' << '\x98' << '\x99' << '\x9a' << '\x9b' << '\x9c' << '\x9d' << '\x9e' << '\x9f' << '\xa0' << '\xa1' << '\xa2' << '\xa3' << '\xa4' << '\xa5' << '\xa6' << '\xa7' << '\xa8' << '\xa9' << '\xaa' << '\xab' << '\xac' << '\xad' << '\xae' << '\xaf' << '\xb0' << '\xb1' << '\xb2' << '\xb3' << '\xb4' << '\xb5' << '\xb6' << '\xb7' << '\xb8' << '\xb9' << '\xba' << '\xbb' << '\xbc' << '\xbd' << '\xbe' << '\xbf' << '\xc0' \
		<< '\xc1' << '\xc2' << '\xc3' << '\xc4' << '\xc5' << '\xc6' << '\xc7' << '\xc8' << '\xc9' << '\xca' << '\xcb' << '\xcc' << '\xcd' << '\xce' << '\xcf' << '\xd0' << '\xd1' << '\xd2' << '\xd3' << '\xd4' << '\xd5' << '\xd6' << '\xd7' << '\xd8' << '\xd9' << '\xda' << '\xdb' << '\xdc' << '\xdd' << '\xde' << '\xdf' << '\xe0' << '\xe1' << '\xe2' << '\xe3' << '\xe4' << '\xe5' << '\xe6' << '\xe7' << '\xe8' << '\xe9' << '\xea' << '\xeb' << '\xec' << '\xed' << '\xee' << '\xef' << '\xf0' << '\xf1' << '\xf2' << '\xf3' << '\xf4' << '\xf5' << '\xf6' << '\xf7' << '\xf8' << '\xf9' << '\xfa' << '\xfb' << '\xfc' << '\xfd' << '\xfe' << '\xff' ), bool AClearBeforeAdd = true);
	AnsiString __fastcall Last();
	AnsiString __fastcall First();
	int __fastcall LastIndex(void);
	HIDESBASE _di_IJclStringList __fastcall Clear();
	_di_IJclStringList __fastcall DeleteRegEx(const AnsiString APattern);
	_di_IJclStringList __fastcall KeepRegEx(const AnsiString APattern);
	_di_IJclStringList __fastcall Files(const AnsiString APattern = "*", bool ARecursive = false, const AnsiString ARegExPattern = "");
	_di_IJclStringList __fastcall Directories(const AnsiString APattern = "*", bool ARecursive = false, const AnsiString ARegExPattern = "");
	Classes::TStrings* __fastcall GetStringsRef(void);
	_di_IJclStringList __fastcall ConfigAsSet();
	_di_IJclStringList __fastcall Delimit(const AnsiString ADelimiter);
	System::_di_IInterface __fastcall GetInterfaceByIndex(int Index);
	_di_IJclStringList __fastcall GetLists(int Index);
	Variant __fastcall GetVariants(int AIndex);
	System::_di_IInterface __fastcall GetKeyInterface(const AnsiString AKey);
	System::TObject* __fastcall GetKeyObject(const AnsiString AKey);
	Variant __fastcall GetKeyVariant(const AnsiString AKey);
	_di_IJclStringList __fastcall GetKeyList(const AnsiString AKey);
	TJclStringListObjectsMode __fastcall GetObjectsMode(void);
	void __fastcall SetInterfaceByIndex(int Index, const System::_di_IInterface Value);
	void __fastcall SetLists(int Index, const _di_IJclStringList Value);
	void __fastcall SetVariants(int Index, const Variant &Value);
	void __fastcall SetKeyInterface(const AnsiString AKey, const System::_di_IInterface Value);
	void __fastcall SetKeyObject(const AnsiString AKey, const System::TObject* Value);
	void __fastcall SetKeyVariant(const AnsiString AKey, const Variant &Value);
	void __fastcall SetKeyList(const AnsiString AKey, const _di_IJclStringList Value);
	__property System::_di_IInterface Interfaces[int Index] = {read=GetInterfaceByIndex, write=SetInterfaceByIndex};
	__property _di_IJclStringList Lists[int Index] = {read=GetLists, write=SetLists};
	__property Variant Variants[int Index] = {read=GetVariants, write=SetVariants};
	__property _di_IJclStringList KeyList[AnsiString AKey] = {read=GetKeyList, write=SetKeyList};
	__property System::TObject* KeyObject[AnsiString AKey] = {read=GetKeyObject, write=SetKeyObject};
	__property System::_di_IInterface KeyInterface[AnsiString AKey] = {read=GetKeyInterface, write=SetKeyInterface};
	__property Variant KeyVariant[AnsiString AKey] = {read=GetKeyVariant, write=SetKeyVariant};
	__property TJclStringListObjectsMode ObjectsMode = {read=GetObjectsMode, nodefault};
private:
	void *__IJclStringList;	/* Jclstringlists::IJclStringList */
	
public:
	operator IJclStringList*(void) { return (IJclStringList*)&__IJclStringList; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE _di_IJclStringList __fastcall JclStringList()/* overload */;
extern PACKAGE _di_IJclStringList __fastcall JclStringList(const AnsiString AText)/* overload */;
extern PACKAGE _di_IJclStringList __fastcall JclStringListStrings(Classes::TStrings* AStrings)/* overload */;
extern PACKAGE _di_IJclStringList __fastcall JclStringListStrings(AnsiString const * A, const int A_Size)/* overload */;
extern PACKAGE _di_IJclStringList __fastcall JclStringList(System::TVarRec const * A, const int A_Size)/* overload */;

}	/* namespace Jclstringlists */
using namespace Jclstringlists;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclstringlists
