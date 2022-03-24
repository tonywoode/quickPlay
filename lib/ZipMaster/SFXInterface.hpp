// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Sfxinterface.pas' rev: 10.00

#ifndef SfxinterfaceHPP
#define SfxinterfaceHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Sfxinterface
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TSFXOverwriteMode { somOverwrite, somSkip, somAsk };
#pragma option pop

#pragma option push -b-
enum TSFXOption { soAskCmdLine, soAskFiles, soHideOverWriteBox, soAutoRun, soNoSuccessMsg, soExpandVariables, soInitiallyHideFiles, soForceHideFiles, soCheckAutoRunFileName, soCanBeCancelled, soDetached, soCreateEmptyDirs };
#pragma option pop

typedef Set<TSFXOption, soAskCmdLine, soCreateEmptyDirs>  TSFXOptions;

struct TSFXFileHeader;
typedef TSFXFileHeader *PSFXFileHeader;

#pragma pack(push,1)
struct TSFXFileHeader
{
	
public:
	unsigned Signature;
	Word Size;
	TSFXOptions Options;
	TSFXOverwriteMode DefOVW;
	Byte CaptionSize;
	Byte PathSize;
	Byte CmdLineSize;
	Byte RegFailPathSize;
	Byte StartMsgSize;
	unsigned StartMsgType;
} ;
#pragma pack(pop)

struct TSFXFileEndOfHeader;
typedef TSFXFileEndOfHeader *PSFXFileEndOfHeader;

#pragma pack(push,1)
struct TSFXFileEndOfHeader
{
	
public:
	unsigned Signature;
	unsigned HeaderSize;
} ;
#pragma pack(pop)

struct TSFXDetachedHeader;
typedef TSFXDetachedHeader *PSFXDetachedHeader;

#pragma pack(push,1)
struct TSFXDetachedHeader
{
	
public:
	unsigned Signature;
	unsigned NameLen;
	unsigned ExtLen;
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const int SFX_HEADER_SIG = 0x1005a44;
static const int SFX_HEADER_END_SIG = 0x10a5a44;
static const int SFX_DETACHED_HEADER_SIG = 0x1145a44;
static const int SFX_DETACHED_HEADER_END_SIG = 0x2145a44;

}	/* namespace Sfxinterface */
using namespace Sfxinterface;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Sfxinterface
