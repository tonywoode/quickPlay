// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclconsole.pas' rev: 10.00

#ifndef JclconsoleHPP
#define JclconsoleHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
namespace JclConsole
{
__interface IJclScreenTextAttribute;
}
using namespace JclConsole;


namespace Jclconsole
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TJclConsole;
class DELPHICLASS TJclInputBuffer;
#pragma option push -b-
enum TJclConsoleInputMode { imLine, imEcho, imProcessed, imWindow, imMouse };
#pragma option pop

typedef Set<TJclConsoleInputMode, imLine, imMouse>  TJclConsoleInputModes;

#pragma option push -b-
enum TJclInputCtrlEvent { ceCtrlC, ceCtrlBreak, ceCtrlClose, ceCtrlLogOff, ceCtrlShutdown };
#pragma option pop

typedef DynamicArray<_INPUT_RECORD >  TJclInputRecordArray;

class PASCALIMPLEMENTATION TJclInputBuffer : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TJclConsole* FConsole;
	unsigned FHandle;
	TJclConsoleInputModes __fastcall GetMode(void);
	void __fastcall SetMode(const TJclConsoleInputModes Value);
	unsigned __fastcall GetEventCount(void);
	
public:
	__fastcall TJclInputBuffer(const TJclConsole* AConsole);
	__fastcall virtual ~TJclInputBuffer(void);
	void __fastcall Clear(void);
	void __fastcall RaiseCtrlEvent(const TJclInputCtrlEvent AEvent, const unsigned ProcessGroupId = (unsigned)(0x0));
	bool __fastcall WaitEvent(const unsigned TimeOut = (unsigned)(0xffffffff));
	unsigned __fastcall GetEvents(TJclInputRecordArray &Events)/* overload */;
	TJclInputRecordArray __fastcall GetEvents(const int Count)/* overload */;
	unsigned __fastcall PeekEvents(TJclInputRecordArray &Events)/* overload */;
	TJclInputRecordArray __fastcall PeekEvents(const int Count)/* overload */;
	unsigned __fastcall PutEvents(const TJclInputRecordArray Events)/* overload */;
	_INPUT_RECORD __fastcall GetEvent();
	_INPUT_RECORD __fastcall PeekEvent();
	bool __fastcall PutEvent(const _INPUT_RECORD &Event);
	__property TJclConsole* Console = {read=FConsole};
	__property unsigned Handle = {read=FHandle, nodefault};
	__property TJclConsoleInputModes Mode = {read=GetMode, write=SetMode, nodefault};
	__property unsigned EventCount = {read=GetEventCount, nodefault};
};


class DELPHICLASS TJclScreenBuffer;
class PASCALIMPLEMENTATION TJclConsole : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Contnrs::TObjectList* FScreens;
	unsigned FActiveScreenIndex;
	TJclInputBuffer* FInput;
	Classes::TNotifyEvent FOnCtrlC;
	Classes::TNotifyEvent FOnCtrlBreak;
	Classes::TNotifyEvent FOnClose;
	Classes::TNotifyEvent FOnLogOff;
	Classes::TNotifyEvent FOnShutdown;
	TJclScreenBuffer* __fastcall GetScreen(const unsigned Idx);
	unsigned __fastcall GetScreenCount(void);
	TJclScreenBuffer* __fastcall GetActiveScreen(void);
	void __fastcall SetActiveScreen(const TJclScreenBuffer* Value);
	void __fastcall SetActiveScreenIndex(const unsigned Value);
	AnsiString __fastcall GetTitle();
	void __fastcall SetTitle(const AnsiString Value);
	unsigned __fastcall GetInputCodePage(void);
	unsigned __fastcall GetOutputCodePage(void);
	void __fastcall SetInputCodePage(const unsigned Value);
	void __fastcall SetOutputCodePage(const unsigned Value);
	
public:
	__fastcall TJclConsole(void);
	__fastcall virtual ~TJclConsole(void);
	/*         class method */ static TJclConsole* __fastcall Default(TMetaClass* vmt);
	/*         class method */ static void __fastcall Shutdown(TMetaClass* vmt);
	/*         class method */ static bool __fastcall IsConsole(TMetaClass* vmt, const unsigned Module)/* overload */;
	/*         class method */ static bool __fastcall IsConsole(TMetaClass* vmt, const AnsiString FileName)/* overload */;
	/*         class method */ static unsigned __fastcall MouseButtonCount(TMetaClass* vmt);
	/*         class method */ static void __fastcall Alloc(TMetaClass* vmt);
	/*         class method */ static void __fastcall Free(TMetaClass* vmt);
	TJclScreenBuffer* __fastcall Add(short AWidth = (short)(0x0), short AHeight = (short)(0x0));
	unsigned __fastcall Remove(const TJclScreenBuffer* ScrBuf);
	void __fastcall Delete(const unsigned Idx);
	__property AnsiString Title = {read=GetTitle, write=SetTitle};
	__property unsigned InputCodePage = {read=GetInputCodePage, write=SetInputCodePage, nodefault};
	__property unsigned OutputCodePage = {read=GetOutputCodePage, write=SetOutputCodePage, nodefault};
	__property TJclInputBuffer* Input = {read=FInput};
	__property TJclScreenBuffer* Screens[unsigned Idx] = {read=GetScreen};
	__property unsigned ScreenCount = {read=GetScreenCount, nodefault};
	__property unsigned ActiveScreenIndex = {read=FActiveScreenIndex, write=SetActiveScreenIndex, nodefault};
	__property TJclScreenBuffer* ActiveScreen = {read=GetActiveScreen, write=SetActiveScreen};
	__property Classes::TNotifyEvent OnCtrlC = {read=FOnCtrlC, write=FOnCtrlC};
	__property Classes::TNotifyEvent OnCtrlBreak = {read=FOnCtrlBreak, write=FOnCtrlBreak};
	__property Classes::TNotifyEvent OnClose = {read=FOnClose, write=FOnClose};
	__property Classes::TNotifyEvent OnLogOff = {read=FOnLogOff, write=FOnLogOff};
	__property Classes::TNotifyEvent OnShutdown = {read=FOnShutdown, write=FOnShutdown};
};


#pragma option push -b-
enum TJclConsoleOutputMode { omProcessed, omWrapAtEol };
#pragma option pop

typedef Set<TJclConsoleOutputMode, omProcessed, omWrapAtEol>  TJclConsoleOutputModes;

typedef void __fastcall (__closure *TJclScreenBufferBeforeResizeEvent)(System::TObject* Sender, const _COORD NewSize, bool &CanResize);

typedef void __fastcall (__closure *TJclScreenBufferAfterResizeEvent)(System::TObject* Sender);

#pragma option push -b-
enum TJclScreenBufferTextHorizontalAlign { thaCurrent, thaLeft, thaCenter, thaRight };
#pragma option pop

#pragma option push -b-
enum TJclScreenBufferTextVerticalAlign { tvaCurrent, tvaTop, tvaCenter, tvaBottom };
#pragma option pop

class DELPHICLASS TJclScreenFont;
class DELPHICLASS TJclScreenCustomTextAttribute;
#pragma option push -b-
enum TJclScreenFontColor { fclBlack, fclBlue, fclGreen, fclRed, fclCyan, fclMagenta, fclYellow, fclWhite };
#pragma option pop

#pragma option push -b-
enum TJclScreenBackColor { bclBlack, bclBlue, bclGreen, bclRed, bclCyan, bclMagenta, bclYellow, bclWhite };
#pragma option pop

#pragma option push -b-
enum TJclScreenFontStyle { fsLeadingByte, fsTrailingByte, fsGridHorizontal, fsGridLeftVertical, fsGridRightVertical, fsReverseVideo, fsUnderscore, fsSbcsDbcs };
#pragma option pop

typedef Set<TJclScreenFontStyle, fsLeadingByte, fsSbcsDbcs>  TJclScreenFontStyles;

class PASCALIMPLEMENTATION TJclScreenCustomTextAttribute : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	__fastcall TJclScreenCustomTextAttribute(const TJclScreenCustomTextAttribute* Attr)/* overload */;
	void __fastcall Clear(void);
	virtual Word __fastcall GetTextAttribute(void) = 0 ;
	virtual void __fastcall SetTextAttribute(const Word Value) = 0 ;
	__property Word TextAttribute = {read=GetTextAttribute, write=SetTextAttribute, nodefault};
	TJclScreenFontColor __fastcall GetColor(void);
	void __fastcall SetColor(const TJclScreenFontColor Value);
	TJclScreenBackColor __fastcall GetBgColor(void);
	void __fastcall SetBgColor(const TJclScreenBackColor Value);
	bool __fastcall GetHighlight(void);
	void __fastcall SetHighlight(const bool Value);
	bool __fastcall GetBgHighlight(void);
	void __fastcall SetBgHighlight(const bool Value);
	TJclScreenFontStyles __fastcall GetStyle(void);
	void __fastcall SetStyle(const TJclScreenFontStyles Value);
	__property TJclScreenFontColor Color = {read=GetColor, write=SetColor, nodefault};
	__property TJclScreenBackColor BgColor = {read=GetBgColor, write=SetBgColor, nodefault};
	__property bool Highlight = {read=GetHighlight, write=SetHighlight, nodefault};
	__property bool BgHighlight = {read=GetBgHighlight, write=SetBgHighlight, nodefault};
	__property TJclScreenFontStyles Style = {read=GetStyle, write=SetStyle, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclScreenCustomTextAttribute(void) { }
	#pragma option pop
	
private:
	void *__IJclScreenTextAttribute;	/* Jclconsole::IJclScreenTextAttribute */
	
public:
	operator IJclScreenTextAttribute*(void) { return (IJclScreenTextAttribute*)&__IJclScreenTextAttribute; }
	
};


class PASCALIMPLEMENTATION TJclScreenFont : public TJclScreenCustomTextAttribute 
{
	typedef TJclScreenCustomTextAttribute inherited;
	
private:
	TJclScreenBuffer* FScreenBuffer;
	
public:
	__fastcall TJclScreenFont(const TJclScreenBuffer* AScrBuf);
	__property TJclScreenBuffer* ScreenBuffer = {read=FScreenBuffer};
	virtual Word __fastcall GetTextAttribute(void);
	virtual void __fastcall SetTextAttribute(const Word Value);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclScreenFont(void) { }
	#pragma option pop
	
private:
	void *__IJclScreenTextAttribute;	/* Jclconsole::IJclScreenTextAttribute */
	
public:
	operator IJclScreenTextAttribute*(void) { return (IJclScreenTextAttribute*)&__IJclScreenTextAttribute; }
	
};


class DELPHICLASS TJclScreenCursor;
typedef Shortint TJclScreenCursorSize;

class PASCALIMPLEMENTATION TJclScreenCursor : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TJclScreenBuffer* FScreenBuffer;
	_CONSOLE_CURSOR_INFO __fastcall GetInfo();
	void __fastcall SetInfo(const _CONSOLE_CURSOR_INFO &Value);
	_COORD __fastcall GetPosition(void);
	void __fastcall SetPosition(const _COORD Value);
	TJclScreenCursorSize __fastcall GetSize(void);
	void __fastcall SetSize(const TJclScreenCursorSize Value);
	bool __fastcall GetVisible(void);
	void __fastcall SetVisible(const bool Value);
	
protected:
	__property _CONSOLE_CURSOR_INFO Info = {read=GetInfo, write=SetInfo};
	
public:
	__fastcall TJclScreenCursor(const TJclScreenBuffer* AScrBuf);
	__property TJclScreenBuffer* ScreenBuffer = {read=FScreenBuffer};
	void __fastcall MoveTo(const _COORD DestPos)/* overload */;
	void __fastcall MoveTo(const short x, const short y)/* overload */;
	void __fastcall MoveBy(const _COORD Delta)/* overload */;
	void __fastcall MoveBy(const short cx, const short cy)/* overload */;
	__property _COORD Position = {read=GetPosition, write=SetPosition};
	__property TJclScreenCursorSize Size = {read=GetSize, write=SetSize, nodefault};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclScreenCursor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclScreenWindow;
class PASCALIMPLEMENTATION TJclScreenWindow : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TJclScreenBuffer* FScreenBuffer;
	_COORD __fastcall GetMaxConsoleWindowSize(void);
	_COORD __fastcall GetMaxWindow(void);
	short __fastcall GetLeft(void);
	short __fastcall GetTop(void);
	short __fastcall GetWidth(void);
	short __fastcall GetHeight(void);
	_COORD __fastcall GetPosition(void);
	_COORD __fastcall GetSize(void);
	short __fastcall GetBottom(void);
	short __fastcall GetRight(void);
	void __fastcall SetLeft(const short Value);
	void __fastcall SetTop(const short Value);
	void __fastcall SetWidth(const short Value);
	void __fastcall SetHeight(const short Value);
	void __fastcall SetPosition(const _COORD Value);
	void __fastcall SetSize(const _COORD Value);
	void __fastcall SetBottom(const short Value);
	void __fastcall SetRight(const short Value);
	void __fastcall InternalSetPosition(const short X, const short Y);
	void __fastcall InternalSetSize(const short X, const short Y);
	
protected:
	void __fastcall DoResize(const _SMALL_RECT &NewRect, bool bAbsolute = true);
	
public:
	__fastcall TJclScreenWindow(const TJclScreenBuffer* AScrBuf);
	void __fastcall Scroll(const short cx, const short cy);
	__property TJclScreenBuffer* ScreenBuffer = {read=FScreenBuffer};
	__property _COORD MaxConsoleWindowSize = {read=GetMaxConsoleWindowSize};
	__property _COORD MaxWindow = {read=GetMaxWindow};
	__property _COORD Position = {read=GetPosition, write=SetPosition};
	__property _COORD Size = {read=GetSize, write=SetSize};
	__property short Left = {read=GetLeft, write=SetLeft, nodefault};
	__property short Right = {read=GetRight, write=SetRight, nodefault};
	__property short Top = {read=GetTop, write=SetTop, nodefault};
	__property short Bottom = {read=GetBottom, write=SetBottom, nodefault};
	__property short Width = {read=GetWidth, write=SetWidth, nodefault};
	__property short Height = {read=GetHeight, write=SetHeight, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclScreenWindow(void) { }
	#pragma option pop
	
};


__interface IJclScreenTextAttribute;
typedef System::DelphiInterface<IJclScreenTextAttribute> _di_IJclScreenTextAttribute;
class PASCALIMPLEMENTATION TJclScreenBuffer : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	unsigned FHandle;
	TJclScreenFont* FFont;
	TJclScreenCursor* FCursor;
	TJclScreenWindow* FWindow;
	Contnrs::TObjectList* FCharList;
	TJclScreenBufferAfterResizeEvent FOnAfterResize;
	TJclScreenBufferBeforeResizeEvent FOnBeforeResize;
	_CONSOLE_SCREEN_BUFFER_INFO __fastcall GetInfo();
	_COORD __fastcall GetSize(void);
	void __fastcall SetSize(const _COORD Value);
	short __fastcall GetHeight(void);
	short __fastcall GetWidth(void);
	void __fastcall SetHeight(const short Value);
	void __fastcall SetWidth(const short Value);
	TJclConsoleOutputModes __fastcall GetMode(void);
	void __fastcall SetMode(const TJclConsoleOutputModes Value);
	
protected:
	void __fastcall Init(void);
	void __fastcall DoResize(const _COORD NewSize)/* overload */;
	void __fastcall DoResize(const short NewWidth, const short NewHeight)/* overload */;
	__property _CONSOLE_SCREEN_BUFFER_INFO Info = {read=GetInfo};
	
public:
	__fastcall TJclScreenBuffer(void)/* overload */;
	__fastcall TJclScreenBuffer(const unsigned AHandle)/* overload */;
	__fastcall TJclScreenBuffer(const short AWidth, const short AHeight)/* overload */;
	__fastcall virtual ~TJclScreenBuffer(void);
	unsigned __fastcall Write(const AnsiString Text, const _di_IJclScreenTextAttribute ATextAttribute = (void *)(0x0))/* overload */;
	unsigned __fastcall Writeln(const AnsiString Text = "", const _di_IJclScreenTextAttribute ATextAttribute = (void *)(0x0))/* overload */;
	unsigned __fastcall Write(const AnsiString Text, const short X, const short Y, const _di_IJclScreenTextAttribute ATextAttribute = (void *)(0x0))/* overload */;
	unsigned __fastcall Write(const AnsiString Text, const short X, const short Y, PWORD pAttrs)/* overload */;
	unsigned __fastcall Write(const AnsiString Text, const TJclScreenBufferTextHorizontalAlign HorizontalAlign, const TJclScreenBufferTextVerticalAlign VerticalAlign = (TJclScreenBufferTextVerticalAlign)(0x0), const _di_IJclScreenTextAttribute ATextAttribute = (void *)(0x0))/* overload */;
	AnsiString __fastcall Read(const int Count)/* overload */;
	AnsiString __fastcall Read(short X, short Y, const int Count)/* overload */;
	AnsiString __fastcall Readln()/* overload */;
	AnsiString __fastcall Readln(short X, short Y)/* overload */;
	void __fastcall Fill(const char ch, const _di_IJclScreenTextAttribute ATextAttribute = (void *)(0x0));
	void __fastcall Clear(void);
	__property unsigned Handle = {read=FHandle, nodefault};
	__property TJclScreenFont* Font = {read=FFont};
	__property TJclScreenCursor* Cursor = {read=FCursor};
	__property TJclScreenWindow* Window = {read=FWindow};
	__property _COORD Size = {read=GetSize, write=SetSize};
	__property short Width = {read=GetWidth, write=SetWidth, nodefault};
	__property short Height = {read=GetHeight, write=SetHeight, nodefault};
	__property TJclConsoleOutputModes Mode = {read=GetMode, write=SetMode, nodefault};
	__property TJclScreenBufferBeforeResizeEvent OnBeforeResize = {read=FOnBeforeResize, write=FOnBeforeResize};
	__property TJclScreenBufferAfterResizeEvent OnAfterResize = {read=FOnAfterResize, write=FOnAfterResize};
};


__interface  INTERFACE_UUID("{B880B1AC-9F1A-4F42-9D44-EA482B4F3510}") IJclScreenTextAttribute  : public IInterface 
{
	
public:
	virtual Word __fastcall GetTextAttribute(void) = 0 ;
	virtual void __fastcall SetTextAttribute(const Word Value) = 0 ;
	__property Word TextAttribute = {read=GetTextAttribute, write=SetTextAttribute};
	virtual TJclScreenFontColor __fastcall GetColor(void) = 0 ;
	virtual void __fastcall SetColor(const TJclScreenFontColor Value) = 0 ;
	virtual TJclScreenBackColor __fastcall GetBgColor(void) = 0 ;
	virtual void __fastcall SetBgColor(const TJclScreenBackColor Value) = 0 ;
	virtual bool __fastcall GetHighlight(void) = 0 ;
	virtual void __fastcall SetHighlight(const bool Value) = 0 ;
	virtual bool __fastcall GetBgHighlight(void) = 0 ;
	virtual void __fastcall SetBgHighlight(const bool Value) = 0 ;
	virtual TJclScreenFontStyles __fastcall GetStyle(void) = 0 ;
	virtual void __fastcall SetStyle(const TJclScreenFontStyles Value) = 0 ;
	__property TJclScreenFontColor Color = {read=GetColor, write=SetColor};
	__property TJclScreenBackColor BgColor = {read=GetBgColor, write=SetBgColor};
	__property bool Highlight = {read=GetHighlight, write=SetHighlight};
	__property bool BgHighlight = {read=GetBgHighlight, write=SetBgHighlight};
	__property TJclScreenFontStyles Style = {read=GetStyle, write=SetStyle};
};

class DELPHICLASS TJclScreenTextAttribute;
class PASCALIMPLEMENTATION TJclScreenTextAttribute : public TJclScreenCustomTextAttribute 
{
	typedef TJclScreenCustomTextAttribute inherited;
	
private:
	Word FAttribute;
	
public:
	__fastcall TJclScreenTextAttribute(const Word Attribute)/* overload */;
	__fastcall TJclScreenTextAttribute(const TJclScreenFontColor AColor, const TJclScreenBackColor ABgColor, const bool AHighLight, const bool ABgHighLight, const TJclScreenFontStyles AStyle)/* overload */;
	virtual Word __fastcall GetTextAttribute(void);
	virtual void __fastcall SetTextAttribute(const Word Value);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclScreenTextAttribute(void) { }
	#pragma option pop
	
private:
	void *__IJclScreenTextAttribute;	/* Jclconsole::IJclScreenTextAttribute */
	
public:
	operator IJclScreenTextAttribute*(void) { return (IJclScreenTextAttribute*)&__IJclScreenTextAttribute; }
	
};


class DELPHICLASS TJclScreenCharacter;
class PASCALIMPLEMENTATION TJclScreenCharacter : public TJclScreenCustomTextAttribute 
{
	typedef TJclScreenCustomTextAttribute inherited;
	
private:
	_CHAR_INFO FCharInfo;
	char __fastcall GetCharacter(void);
	void __fastcall SetCharacter(const char Value);
	
public:
	__fastcall TJclScreenCharacter(const _CHAR_INFO CharInfo);
	__property _CHAR_INFO Info = {read=FCharInfo, write=FCharInfo};
	__property char Character = {read=GetCharacter, write=SetCharacter, nodefault};
	virtual Word __fastcall GetTextAttribute(void);
	virtual void __fastcall SetTextAttribute(const Word Value);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclScreenCharacter(void) { }
	#pragma option pop
	
private:
	void *__IJclScreenTextAttribute;	/* Jclconsole::IJclScreenTextAttribute */
	
public:
	operator IJclScreenTextAttribute*(void) { return (IJclScreenTextAttribute*)&__IJclScreenTextAttribute; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jclconsole */
using namespace Jclconsole;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclconsole
