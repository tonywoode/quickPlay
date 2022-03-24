// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclunicode.pas' rev: 10.00

#ifndef JclunicodeHPP
#define JclunicodeHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclunicode
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TSaveFormat { sfUTF16LSB, sfUTF16MSB, sfUTF8, sfAnsi };
#pragma option pop

#pragma option push -b-
enum TCharacterCategory { ccLetterUppercase, ccLetterLowercase, ccLetterTitlecase, ccMarkNonSpacing, ccMarkSpacingCombining, ccMarkEnclosing, ccNumberDecimalDigit, ccNumberLetter, ccNumberOther, ccSeparatorSpace, ccSeparatorLine, ccSeparatorParagraph, ccOtherControl, ccOtherFormat, ccOtherSurrogate, ccOtherPrivate, ccOtherUnassigned, ccLetterModifier, ccLetterOther, ccPunctuationConnector, ccPunctuationDash, ccPunctuationOpen, ccPunctuationClose, ccPunctuationInitialQuote, ccPunctuationFinalQuote, ccPunctuationOther, ccSymbolMath, ccSymbolCurrency, ccSymbolModifier, ccSymbolOther, ccLeftToRight, ccLeftToRightEmbedding, ccLeftToRightOverride, ccRightToLeft, ccRightToLeftArabic, ccRightToLeftEmbedding, ccRightToLeftoverride, ccPopDirectionalFormat, ccEuropeanNumber, ccEuropeanNumberSeparator, ccEuropeanNumberTerminator, ccArabicNumber, ccCommonNumberSeparator, ccBoundaryNeutral, ccSegmentSeparator, ccWhiteSpace, ccOtherNeutrals, ccComposed, ccNonBreaking, ccSymmetric, ccHexDigit, ccQuotationMark, ccMirroring
	, ccSpaceOther, ccAssigned };
#pragma option pop

typedef Set<TCharacterCategory, ccLetterUppercase, ccAssigned>  TCharacterCategories;

#pragma option push -b-
enum TNormalizationForm { nfNone, nfC, nfD, nfKC, nfKD };
#pragma option pop

struct TUnicodeBlockRange
{
	
public:
	unsigned RangeStart;
	unsigned RangeEnd;
} ;

#pragma option push -b-
enum TUnicodeBlock { ubUndefined, ubBasicLatin, ubLatin1Supplement, ubLatinExtendedA, ubLatinExtendedB, ubIPAExtensions, ubSpacingModifierLetters, ubCombiningDiacriticalMarks, ubGreekandCoptic, ubCyrillic, ubCyrillicSupplement, ubArmenian, ubHebrew, ubArabic, ubSyriac, ubArabicSupplement, ubThaana, ubNKo, ubDevanagari, ubBengali, ubGurmukhi, ubGujarati, ubOriya, ubTamil, ubTelugu, ubKannada, ubMalayalam, ubSinhala, ubThai, ubLao, ubTibetan, ubMyanmar, ubGeorgian, ubHangulJamo, ubEthiopic, ubEthiopicSupplement, ubCherokee, ubUnifiedCanadianAboriginalSyllabics, ubOgham, ubRunic, ubTagalog, ubHanunoo, ubBuhid, ubTagbanwa, ubKhmer, ubMongolian, ubLimbu, ubTaiLe, ubNewTaiLue, ubKhmerSymbols, ubBuginese, ubBalinese, ubPhoneticExtensions, ubPhoneticExtensionsSupplement, ubCombiningDiacriticalMarksSupplement, ubLatinExtendedAdditional, ubGreekExtended, ubGeneralPunctuation, ubSuperscriptsandSubscripts, ubCurrencySymbols, ubCombiningDiacriticalMarksforSymbols, ubLetterlikeSymbols, ubNumberForms, ubArrows
	, ubMathematicalOperators, ubMiscellaneousTechnical, ubControlPictures, ubOpticalCharacterRecognition, ubEnclosedAlphanumerics, ubBoxDrawing, ubBlockElements, ubGeometricShapes, ubMiscellaneousSymbols, ubDingbats, ubMiscellaneousMathematicalSymbolsA, ubSupplementalArrowsA, ubBraillePatterns, ubSupplementalArrowsB, ubMiscellaneousMathematicalSymbolsB, ubSupplementalMathematicalOperators, ubMiscellaneousSymbolsandArrows, ubGlagolitic, ubLatinExtendedC, ubCoptic, ubGeorgianSupplement, ubTifinagh, ubEthiopicExtended, ubSupplementalPunctuation, ubCJKRadicalsSupplement, ubKangxiRadicals, ubIdeographicDescriptionCharacters, ubCJKSymbolsandPunctuation, ubHiragana, ubKatakana, ubBopomofo, ubHangulCompatibilityJamo, ubKanbun, ubBopomofoExtended, ubCJKStrokes, ubKatakanaPhoneticExtensions, ubEnclosedCJKLettersandMonths, ubCJKCompatibility, ubCJKUnifiedIdeographsExtensionA, ubYijingHexagramSymbols, ubCJKUnifiedIdeographs, ubYiSyllables, ubYiRadicals, ubModifierToneLetters, ubLatinExtendedD, ubSylotiNagri, ubPhagsPa, ubHangulSyllables
	, ubHighSurrogates, ubHighPrivateUseSurrogates, ubLowSurrogates, ubPrivateUseArea, ubCJKCompatibilityIdeographs, ubAlphabeticPresentationForms, ubArabicPresentationFormsA, ubVariationSelectors, ubVerticalForms, ubCombiningHalfMarks, ubCJKCompatibilityForms, ubSmallFormVariants, ubArabicPresentationFormsB, ubHalfwidthandFullwidthForms, ubSpecials, ubLinearBSyllabary, ubLinearBIdeograms, ubAegeanNumbers, ubAncientGreekNumbers, ubOldItalic, ubGothic, ubUgaritic, ubOldPersian, ubDeseret, ubShavian, ubOsmanya, ubCypriotSyllabary, ubPhoenician, ubKharoshthi, ubCuneiform, ubCuneiformNumbersAndPunctuation, ubByzantineMusicalSymbols, ubMusicalSymbols, ubAncientGreekMusicalNotation, ubTaiXuanJingSymbols, ubCountingRodNumerals, ubMathematicalAlphanumericSymbols, ubCJKUnifiedIdeographsExtensionB, ubCJKCompatibilityIdeographsSupplement, ubTags, ubVariationSelectorsSupplement, ubSupplementaryPrivateUseAreaA, ubSupplementaryPrivateUseAreaB };
#pragma option pop

struct TUnicodeBlockData
{
	
public:
	TUnicodeBlockRange Range;
	AnsiString Name;
} ;

typedef TUnicodeBlockData *PUnicodeBlockData;

typedef TUnicodeBlockData JclUnicode__1[155];

#pragma option push -b-
enum TSearchFlag { sfCaseSensitive, sfIgnoreNonSpacing, sfSpaceCompress, sfWholeWordOnly };
#pragma option pop

typedef Set<TSearchFlag, sfCaseSensitive, sfWholeWordOnly>  TSearchFlags;

class DELPHICLASS TSearchEngine;
class DELPHICLASS TWideStrings;
typedef void __fastcall (__closure *TConfirmConversionEvent)(TWideStrings* Sender, bool &Allowed);

class PASCALIMPLEMENTATION TWideStrings : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
public:
	WideString operator[](int Index) { return Strings[Index]; }
	
private:
	int FUpdateCount;
	unsigned FLanguage;
	bool FSaved;
	TNormalizationForm FNormalizationForm;
	TConfirmConversionEvent FOnConfirmConversion;
	TSaveFormat FSaveFormat;
	WideString __fastcall GetCommaText();
	WideString __fastcall GetName(int Index);
	WideString __fastcall GetValue(const WideString Name);
	void __fastcall ReadData(Classes::TReader* Reader);
	void __fastcall SetCommaText(const WideString Value);
	void __fastcall SetNormalizationForm(const TNormalizationForm Value);
	void __fastcall SetValue(const WideString Name, const WideString Value);
	void __fastcall WriteData(Classes::TWriter* Writer);
	bool __fastcall GetSaveUnicode(void);
	void __fastcall SetSaveUnicode(const bool Value);
	
protected:
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall DoConfirmConversion(bool &Allowed);
	void __fastcall Error(const AnsiString Msg, int Data);
	virtual WideString __fastcall Get(int Index) = 0 ;
	virtual int __fastcall GetCapacity(void);
	virtual int __fastcall GetCount(void) = 0 ;
	virtual System::TObject* __fastcall GetObject(int Index);
	virtual WideString __fastcall GetTextStr();
	virtual void __fastcall Put(int Index, const WideString S) = 0 ;
	virtual void __fastcall PutObject(int Index, System::TObject* AObject) = 0 ;
	virtual void __fastcall SetCapacity(int NewCapacity);
	virtual void __fastcall SetUpdateState(bool Updating);
	virtual void __fastcall SetLanguage(unsigned Value);
	
public:
	__fastcall TWideStrings(void);
	virtual int __fastcall Add(const WideString S);
	virtual int __fastcall AddObject(const WideString S, System::TObject* AObject);
	void __fastcall Append(const WideString S);
	virtual void __fastcall AddStrings(Classes::TStrings* Strings)/* overload */;
	virtual void __fastcall AddStrings(TWideStrings* Strings)/* overload */;
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	void __fastcall BeginUpdate(void);
	virtual void __fastcall Clear(void) = 0 ;
	virtual void __fastcall Delete(int Index) = 0 ;
	void __fastcall EndUpdate(void);
	bool __fastcall Equals(TWideStrings* Strings);
	virtual void __fastcall Exchange(int Index1, int Index2);
	virtual WideString __fastcall GetSeparatedText(WideString Separators);
	virtual WideChar * __fastcall GetText(void);
	virtual int __fastcall IndexOf(const WideString S);
	int __fastcall IndexOfName(const WideString Name);
	int __fastcall IndexOfObject(System::TObject* AObject);
	virtual void __fastcall Insert(int Index, const WideString S) = 0 ;
	void __fastcall InsertObject(int Index, const WideString S, System::TObject* AObject);
	virtual void __fastcall LoadFromFile(const AnsiString FileName);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	virtual void __fastcall Move(int CurIndex, int NewIndex);
	virtual void __fastcall SaveToFile(const AnsiString FileName);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream, bool WithBOM = true);
	virtual void __fastcall SetText(const WideString Value);
	__property int Capacity = {read=GetCapacity, write=SetCapacity, nodefault};
	__property WideString CommaText = {read=GetCommaText, write=SetCommaText};
	__property int Count = {read=GetCount, nodefault};
	__property unsigned Language = {read=FLanguage, write=SetLanguage, nodefault};
	__property WideString Names[int Index] = {read=GetName};
	__property TNormalizationForm NormalizationForm = {read=FNormalizationForm, write=SetNormalizationForm, default=1};
	__property System::TObject* Objects[int Index] = {read=GetObject, write=PutObject};
	__property WideString Values[WideString Name] = {read=GetValue, write=SetValue};
	__property bool Saved = {read=FSaved, nodefault};
	__property bool SaveUnicode = {read=GetSaveUnicode, write=SetSaveUnicode, default=1};
	__property TSaveFormat SaveFormat = {read=FSaveFormat, write=FSaveFormat, default=0};
	__property WideString Strings[int Index] = {read=Get, write=Put/*, default*/};
	__property WideString Text = {read=GetTextStr, write=SetText};
	__property TConfirmConversionEvent OnConfirmConversion = {read=FOnConfirmConversion, write=FOnConfirmConversion};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TWideStrings(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TSearchEngine : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* FResults;
	TWideStrings* FOwner;
	
protected:
	virtual int __fastcall GetCount(void);
	
public:
	__fastcall virtual TSearchEngine(TWideStrings* AOwner);
	__fastcall virtual ~TSearchEngine(void);
	virtual void __fastcall AddResult(int Start, int Stop);
	virtual void __fastcall Clear(void);
	virtual void __fastcall ClearResults(void);
	virtual void __fastcall DeleteResult(int Index);
	virtual void __fastcall FindPrepare(const WideString Pattern, TSearchFlags Options) = 0 /* overload */;
	virtual void __fastcall FindPrepare(WideChar * Pattern, int PatternLength, TSearchFlags Options) = 0 /* overload */;
	virtual bool __fastcall FindFirst(const WideString Text, int &Start, int &Stop) = 0 /* overload */;
	virtual bool __fastcall FindFirst(WideChar * Text, int TextLen, int &Start, int &Stop) = 0 /* overload */;
	virtual bool __fastcall FindAll(const WideString Text) = 0 /* overload */;
	virtual bool __fastcall FindAll(WideChar * Text, int TextLen) = 0 /* overload */;
	virtual void __fastcall GetResult(int Index, int &Start, int &Stop);
	__property int Count = {read=GetCount, nodefault};
};


struct TUTBMChar;
typedef TUTBMChar *PUTBMChar;

struct TUTBMChar
{
	
public:
	unsigned LoCase;
	unsigned UpCase;
	unsigned TitleCase;
} ;

struct TUTBMSkip;
typedef TUTBMSkip *PUTBMSkip;

struct TUTBMSkip
{
	
public:
	TUTBMChar *BMChar;
	int SkipValues;
} ;

class DELPHICLASS TUTBMSearch;
class PASCALIMPLEMENTATION TUTBMSearch : public TSearchEngine 
{
	typedef TSearchEngine inherited;
	
private:
	TSearchFlags FFlags;
	TUTBMChar *FPattern;
	int FPatternUsed;
	int FPatternSize;
	int FPatternLength;
	TUTBMSkip *FSkipValues;
	int FSkipsUsed;
	int FMD4;
	
protected:
	void __fastcall ClearPattern(void);
	void __fastcall Compile(WideChar * Pattern, int PatternLength, TSearchFlags Flags);
	bool __fastcall Find(WideChar * Text, int TextLen, int &MatchStart, int &MatchEnd);
	int __fastcall GetSkipValue(WideChar * TextStart, WideChar * TextEnd);
	bool __fastcall Match(WideChar * Text, WideChar * Start, WideChar * Stop, int &MatchStart, int &MatchEnd);
	
public:
	virtual void __fastcall Clear(void);
	virtual void __fastcall FindPrepare(const WideString Pattern, TSearchFlags Options)/* overload */;
	virtual void __fastcall FindPrepare(WideChar * Pattern, int PatternLength, TSearchFlags Options)/* overload */;
	virtual bool __fastcall FindFirst(const WideString Text, int &Start, int &Stop)/* overload */;
	virtual bool __fastcall FindFirst(WideChar * Text, int TextLen, int &Start, int &Stop)/* overload */;
	virtual bool __fastcall FindAll(const WideString Text)/* overload */;
	virtual bool __fastcall FindAll(WideChar * Text, int TextLen)/* overload */;
public:
	#pragma option push -w-inl
	/* TSearchEngine.Create */ inline __fastcall virtual TUTBMSearch(TWideStrings* AOwner) : TSearchEngine(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSearchEngine.Destroy */ inline __fastcall virtual ~TUTBMSearch(void) { }
	#pragma option pop
	
};


struct TUcRange;
typedef TUcRange *PUcRange;

struct TUcRange
{
	
public:
	unsigned MinCode;
	unsigned MaxCode;
} ;

typedef DynamicArray<TUcRange >  JclUnicode__4;

struct TUcCClass
{
	
public:
	DynamicArray<TUcRange >  Ranges;
	int RangesUsed;
} ;

struct TUcSymbol
{
	
public:
	unsigned Chr;
	TUcCClass CCL;
} ;

struct TUcElement
{
	
public:
	bool OnStack;
	int AType;
	int LHS;
	int RHS;
} ;

struct TUcStateList;
typedef TUcStateList *PUcStateList;

typedef DynamicArray<int >  JclUnicode__5;

struct TUcStateList
{
	
public:
	DynamicArray<int >  List;
	int ListUsed;
} ;

struct TUcSymbolTableEntry;
typedef TUcSymbolTableEntry *PUcSymbolTableEntry;

struct TUcSymbolTableEntry
{
	
public:
	int ID;
	int AType;
	TCharacterCategories Mods;
	TCharacterCategories Categories;
	TUcSymbol Symbol;
	TUcStateList States;
} ;

struct TUcState;
typedef TUcState *PUcState;

typedef DynamicArray<TUcElement >  JclUnicode__6;

struct TUcState
{
	
public:
	int ID;
	bool Accepting;
	TUcStateList StateList;
	DynamicArray<TUcElement >  Transitions;
	int TransitionsUsed;
} ;

typedef DynamicArray<TUcState >  JclUnicode__7;

struct TUcStateTable
{
	
public:
	DynamicArray<TUcState >  States;
	int StatesUsed;
} ;

struct TUcEquivalent
{
	
public:
	int Left;
	int Right;
} ;

typedef DynamicArray<TUcElement >  JclUnicode__8;

struct TUcExpressionList
{
	
public:
	DynamicArray<TUcElement >  Expressions;
	int ExpressionsUsed;
} ;

typedef DynamicArray<TUcSymbolTableEntry >  JclUnicode__9;

struct TUcSymbolTable
{
	
public:
	DynamicArray<TUcSymbolTableEntry >  Symbols;
	int SymbolsUsed;
} ;

typedef DynamicArray<TUcEquivalent >  JclUnicode__01;

struct TUcEquivalentList
{
	
public:
	DynamicArray<TUcEquivalent >  Equivalents;
	int EquivalentsUsed;
} ;

struct TUREBuffer;
typedef TUREBuffer *PUREBuffer;

struct TUREBuffer
{
	
public:
	bool Reducing;
	int Error;
	unsigned Flags;
	TUcStateList Stack;
	TUcSymbolTable SymbolTable;
	TUcExpressionList ExpressionList;
	TUcStateTable States;
	TUcEquivalentList EquivalentList;
} ;

struct TUcTransition
{
	
public:
	int Symbol;
	int NextState;
} ;

struct TDFAState;
typedef TDFAState *PDFAState;

struct TDFAState
{
	
public:
	bool Accepting;
	int NumberTransitions;
	int StartTransition;
} ;

typedef DynamicArray<TDFAState >  JclUnicode__11;

struct TDFAStates
{
	
public:
	DynamicArray<TDFAState >  States;
	int StatesUsed;
} ;

typedef DynamicArray<TUcTransition >  JclUnicode__21;

struct TUcTransitions
{
	
public:
	DynamicArray<TUcTransition >  Transitions;
	int TransitionsUsed;
} ;

struct TDFA
{
	
public:
	unsigned Flags;
	TUcSymbolTable SymbolTable;
	TDFAStates StateList;
	TUcTransitions TransitionList;
} ;

class DELPHICLASS TURESearch;
class PASCALIMPLEMENTATION TURESearch : public TSearchEngine 
{
	typedef TSearchEngine inherited;
	
private:
	TUREBuffer FUREBuffer;
	TDFA FDFA;
	
protected:
	void __fastcall AddEquivalentPair(int L, int R);
	void __fastcall AddRange(TUcCClass &CCL, const TUcRange &Range);
	int __fastcall AddState(int * NewStates, const int NewStates_Size);
	void __fastcall AddSymbolState(int Symbol, int State);
	int __fastcall BuildCharacterClass(WideChar * CP, int Limit, PUcSymbolTableEntry Symbol);
	void __fastcall ClearUREBuffer(void);
	int __fastcall CompileSymbol(WideChar * S, int Limit, PUcSymbolTableEntry Symbol);
	void __fastcall CompileURE(WideChar * RE, int RELength, bool Casefold);
	void __fastcall CollectPendingOperations(int &State);
	int __fastcall ConvertRegExpToNFA(WideChar * RE, int RELength);
	bool __fastcall ExecuteURE(unsigned Flags, WideChar * Text, int TextLen, int &MatchStart, int &MatchEnd);
	void __fastcall ClearDFA(void);
	void __fastcall HexDigitSetup(PUcSymbolTableEntry Symbol);
	int __fastcall MakeExpression(int AType, int LHS, int RHS);
	int __fastcall MakeHexNumber(WideChar * NP, int Limit, unsigned &Number);
	int __fastcall MakeSymbol(WideChar * S, int Limit, /* out */ int &Consumed);
	void __fastcall MergeEquivalents(void);
	int __fastcall ParsePropertyList(WideChar * Properties, int Limit, TCharacterCategories &Categories);
	int __fastcall Peek(void);
	int __fastcall Pop(void);
	int __fastcall PosixCCL(WideChar * CP, int Limit, PUcSymbolTableEntry Symbol);
	int __fastcall ProbeLowSurrogate(WideChar * LeftState, int Limit, unsigned &Code);
	void __fastcall Push(int V);
	void __fastcall Reduce(int Start);
	void __fastcall SpaceSetup(PUcSymbolTableEntry Symbol, const TCharacterCategories &Categories);
	bool __fastcall SymbolsAreDifferent(PUcSymbolTableEntry A, PUcSymbolTableEntry B);
	
public:
	virtual void __fastcall Clear(void);
	virtual void __fastcall FindPrepare(const WideString Pattern, TSearchFlags Options)/* overload */;
	virtual void __fastcall FindPrepare(WideChar * Pattern, int PatternLength, TSearchFlags Options)/* overload */;
	virtual bool __fastcall FindFirst(const WideString Text, int &Start, int &Stop)/* overload */;
	virtual bool __fastcall FindFirst(WideChar * Text, int TextLen, int &Start, int &Stop)/* overload */;
	virtual bool __fastcall FindAll(const WideString Text)/* overload */;
	virtual bool __fastcall FindAll(WideChar * Text, int TextLen)/* overload */;
public:
	#pragma option push -w-inl
	/* TSearchEngine.Create */ inline __fastcall virtual TURESearch(TWideStrings* AOwner) : TSearchEngine(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSearchEngine.Destroy */ inline __fastcall virtual ~TURESearch(void) { }
	#pragma option pop
	
};


struct TWideStringItem
{
	
public:
	WideChar *FString;
	System::TObject* FObject;
} ;

typedef DynamicArray<TWideStringItem >  TWideStringItemList;

class DELPHICLASS TWideStringList;
class PASCALIMPLEMENTATION TWideStringList : public TWideStrings 
{
	typedef TWideStrings inherited;
	
private:
	DynamicArray<TWideStringItem >  FList;
	int FCount;
	bool FSorted;
	Classes::TDuplicates FDuplicates;
	Classes::TNotifyEvent FOnChange;
	Classes::TNotifyEvent FOnChanging;
	void __fastcall ExchangeItems(int Index1, int Index2);
	void __fastcall Grow(void);
	void __fastcall QuickSort(int L, int R);
	void __fastcall InsertItem(int Index, const WideString S);
	void __fastcall SetSorted(bool Value);
	void __fastcall SetListString(int Index, const WideString S);
	
protected:
	virtual void __fastcall Changed(void);
	virtual void __fastcall Changing(void);
	virtual WideString __fastcall Get(int Index);
	virtual int __fastcall GetCapacity(void);
	virtual int __fastcall GetCount(void);
	virtual System::TObject* __fastcall GetObject(int Index);
	virtual void __fastcall Put(int Index, const WideString S);
	virtual void __fastcall PutObject(int Index, System::TObject* AObject);
	virtual void __fastcall SetCapacity(int NewCapacity);
	virtual void __fastcall SetUpdateState(bool Updating);
	virtual void __fastcall SetLanguage(unsigned Value);
	
public:
	__fastcall virtual ~TWideStringList(void);
	virtual int __fastcall Add(const WideString S);
	virtual void __fastcall Clear(void);
	virtual void __fastcall Delete(int Index);
	virtual void __fastcall Exchange(int Index1, int Index2);
	virtual bool __fastcall Find(const WideString S, int &Index);
	virtual int __fastcall IndexOf(const WideString S);
	virtual void __fastcall Insert(int Index, const WideString S);
	virtual void __fastcall Sort(void);
	__property Classes::TDuplicates Duplicates = {read=FDuplicates, write=FDuplicates, nodefault};
	__property bool Sorted = {read=FSorted, write=SetSorted, nodefault};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Classes::TNotifyEvent OnChanging = {read=FOnChanging, write=FOnChanging};
public:
	#pragma option push -w-inl
	/* TWideStrings.Create */ inline __fastcall TWideStringList(void) : TWideStrings() { }
	#pragma option pop
	
};


#pragma option push -b-
enum TCaseType { ctFold, ctLower, ctTitle, ctUpper };
#pragma option pop

struct TUcNumber
{
	
public:
	int Numerator;
	int Denominator;
} ;

typedef int __fastcall (*TCompareFunc)(const WideString W1, const WideString W2, unsigned Locale);

class DELPHICLASS EJclUnicodeError;
class PASCALIMPLEMENTATION EJclUnicodeError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclUnicodeError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclUnicodeError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclUnicodeError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclUnicodeError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclUnicodeError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclUnicodeError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclUnicodeError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclUnicodeError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclUnicodeError(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const WideChar WideNull = WideChar(0x0);
static const WideChar WideTabulator = WideChar(0x9);
static const WideChar WideSpace = WideChar(0x20);
static const WideChar WideLF = WideChar(0xa);
static const WideChar WideLineFeed = WideChar(0xa);
static const WideChar WideVerticalTab = WideChar(0xb);
static const WideChar WideFormFeed = WideChar(0xc);
static const WideChar WideCR = WideChar(0xd);
static const WideChar WideCarriageReturn = WideChar(0xd);
#define WideCRLF L"\r\n"
static const WideChar WideLineSeparator = WideChar(0x2028);
static const WideChar WideParagraphSeparator = WideChar(0x2029);
static const WideChar BOM_LSB_FIRST = WideChar(0xfeff);
static const WideChar BOM_MSB_FIRST = WideChar(0xfffe);
#define sfUnicodeLSB (TSaveFormat)(0)
#define sfUnicodeMSB (TSaveFormat)(1)
extern PACKAGE TUnicodeBlockData UnicodeBlockData[155];
extern PACKAGE TCompareFunc WideCompareText;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE void __fastcall LoadCharacterCategories(void);
extern PACKAGE void __fastcall LoadCaseMappingData(void);
extern PACKAGE Jclbase::TUCS4Array __fastcall UnicodeCaseFold(unsigned Code);
extern PACKAGE Jclbase::TUCS4Array __fastcall UnicodeToUpper(unsigned Code);
extern PACKAGE Jclbase::TUCS4Array __fastcall UnicodeToLower(unsigned Code);
extern PACKAGE Jclbase::TUCS4Array __fastcall UnicodeToTitle(unsigned Code);
extern PACKAGE void __fastcall LoadDecompositionData(void);
extern PACKAGE void __fastcall LoadCombiningClassData(void);
extern PACKAGE void __fastcall LoadNumberData(void);
extern PACKAGE bool __fastcall UnicodeNumberLookup(unsigned Code, TUcNumber &Number);
extern PACKAGE void __fastcall LoadCompositionData(void);
extern PACKAGE int __fastcall UnicodeCompose(unsigned const * Codes, const int Codes_Size, /* out */ unsigned &Composite);
extern PACKAGE WideString __fastcall WideAdjustLineBreaks(const WideString S);
extern PACKAGE WideString __fastcall WideQuotedStr(const WideString S, WideChar Quote);
extern PACKAGE WideString __fastcall WideExtractQuotedStr(WideChar * &Src, WideChar Quote);
extern PACKAGE WideString __fastcall WideStringOfChar(WideChar C, int Count);
extern PACKAGE WideString __fastcall WideTrim(const WideString S);
extern PACKAGE WideString __fastcall WideTrimLeft(const WideString S);
extern PACKAGE WideString __fastcall WideTrimRight(const WideString S);
extern PACKAGE int __fastcall WideCharPos(const WideString S, const WideChar Ch, const int Index);
extern PACKAGE WideString __fastcall WideCompose(const WideString S);
extern PACKAGE WideString __fastcall WideDecompose(const WideString S, bool Compatible);
extern PACKAGE WideString __fastcall WideNormalize(const WideString S, TNormalizationForm Form);
extern PACKAGE bool __fastcall WideSameText(const WideString Str1, const WideString Str2);
extern PACKAGE WideString __fastcall WideCaseConvert(WideChar C, TCaseType CaseType)/* overload */;
extern PACKAGE WideString __fastcall WideCaseConvert(const WideString S, TCaseType CaseType)/* overload */;
extern PACKAGE WideString __fastcall WideCaseFolding(WideChar C)/* overload */;
extern PACKAGE WideString __fastcall WideCaseFolding(const WideString S)/* overload */;
extern PACKAGE WideString __fastcall WideLowerCase(WideChar C)/* overload */;
extern PACKAGE WideString __fastcall WideLowerCase(const WideString S)/* overload */;
extern PACKAGE WideString __fastcall WideTitleCase(WideChar C)/* overload */;
extern PACKAGE WideString __fastcall WideTitleCase(const WideString S)/* overload */;
extern PACKAGE WideString __fastcall WideUpperCase(WideChar C)/* overload */;
extern PACKAGE WideString __fastcall WideUpperCase(const WideString S)/* overload */;
extern PACKAGE bool __fastcall UnicodeIsAlpha(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsDigit(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsAlphaNum(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsCased(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsControl(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsSpace(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsWhiteSpace(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsBlank(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsPunctuation(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsGraph(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsPrintable(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsUpper(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsLower(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsTitle(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsHexDigit(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsIsoControl(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsFormatControl(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsSymbol(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsNumber(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsNonSpacing(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsOpenPunctuation(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsClosePunctuation(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsInitialPunctuation(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsFinalPunctuation(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsComposed(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsQuotationMark(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsSymmetric(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsMirroring(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsNonBreaking(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsRightToLeft(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsLeftToRight(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsStrong(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsWeak(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsNeutral(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsSeparator(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsMark(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsModifier(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsLetterNumber(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsConnectionPunctuation(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsDash(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsMath(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsCurrency(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsModifierSymbol(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsNonSpacingMark(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsSpacingMark(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsEnclosing(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsPrivate(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsSurrogate(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsLineSeparator(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsParagraphSeparator(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsIdentifierStart(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsIdentifierPart(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsDefined(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsUndefined(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsHan(unsigned C);
extern PACKAGE bool __fastcall UnicodeIsHangul(unsigned C);
extern PACKAGE bool __fastcall GetCharSetFromLocale(unsigned Language, /* out */ Byte &FontCharSet);
extern PACKAGE Byte __fastcall CharSetFromLocale(unsigned Language);
extern PACKAGE Word __fastcall CodePageFromLocale(unsigned Language);
extern PACKAGE Word __fastcall KeyboardCodePage(void);
extern PACKAGE WideChar __fastcall KeyUnicode(char C);
extern PACKAGE TUnicodeBlockRange __fastcall CodeBlockRange(const TUnicodeBlock CB);
extern PACKAGE AnsiString __fastcall CodeBlockName(const TUnicodeBlock CB);
extern PACKAGE TUnicodeBlock __fastcall CodeBlockFromChar(const unsigned C);
extern PACKAGE WideString __fastcall StringToWideStringEx(const AnsiString S, Word CodePage);
extern PACKAGE AnsiString __fastcall WideStringToStringEx(const WideString WS, Word CodePage);
extern PACKAGE AnsiString __fastcall TranslateString(const AnsiString S, Word CP1, Word CP2);

}	/* namespace Jclunicode */
using namespace Jclunicode;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclunicode
