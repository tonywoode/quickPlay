// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclcompression.pas' rev: 10.00

#ifndef JclcompressionHPP
#define JclcompressionHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sevenzip.hpp>	// Pascal unit
#include <Activex.hpp>	// Pascal unit
#include <Jclwidestrings.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Zlibh.hpp>	// Pascal unit
#include <Bzip2.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit
#include <Jclstreams.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclcompression
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TJclCompressionStream;
class PASCALIMPLEMENTATION TJclCompressionStream : public Jclstreams::TJclStream 
{
	typedef Jclstreams::TJclStream inherited;
	
private:
	Classes::TNotifyEvent FOnProgress;
	void *FBuffer;
	unsigned FBufferSize;
	Classes::TStream* FStream;
	
protected:
	virtual unsigned __fastcall SetBufferSize(unsigned Size);
	DYNAMIC void __fastcall Progress(System::TObject* Sender);
	__property Classes::TNotifyEvent OnProgress = {read=FOnProgress, write=FOnProgress};
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall StreamName() { return StreamName(__classid(TJclCompressionStream)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall StreamName(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall StreamExtensions() { return StreamExtensions(__classid(TJclCompressionStream)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall StreamExtensions(TMetaClass* vmt);
	__fastcall TJclCompressionStream(Classes::TStream* AStream);
	__fastcall virtual ~TJclCompressionStream(void);
	virtual int __fastcall Read(void *Buffer, int Count);
	virtual int __fastcall Write(const void *Buffer, int Count);
	virtual __int64 __fastcall Seek(const __int64 Offset, Classes::TSeekOrigin Origin)/* overload */;
	virtual void __fastcall Reset(void);
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Seek(int Offset, Word Origin){ return TJclStream::Seek(Offset, Origin); }
	
};


typedef TMetaClass* TJclCompressionStreamClass;

class DELPHICLASS TJclCompressStream;
class PASCALIMPLEMENTATION TJclCompressStream : public TJclCompressionStream 
{
	typedef TJclCompressionStream inherited;
	
public:
	DYNAMIC int __fastcall Flush(void) = 0 ;
	__fastcall TJclCompressStream(Classes::TStream* Destination);
public:
	#pragma option push -w-inl
	/* TJclCompressionStream.Destroy */ inline __fastcall virtual ~TJclCompressStream(void) { }
	#pragma option pop
	
};


typedef TMetaClass* TJclCompressStreamClass;

class DELPHICLASS TJclDecompressStream;
class PASCALIMPLEMENTATION TJclDecompressStream : public TJclCompressionStream 
{
	typedef TJclCompressionStream inherited;
	
private:
	bool FOwnsStream;
	
public:
	__fastcall TJclDecompressStream(Classes::TStream* Source, bool AOwnsStream);
	__fastcall virtual ~TJclDecompressStream(void);
};


typedef TMetaClass* TJclDecompressStreamClass;

class DELPHICLASS TJclCompressionStreamFormats;
class PASCALIMPLEMENTATION TJclCompressionStreamFormats : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* FCompressFormats;
	Classes::TList* FDecompressFormats;
	
protected:
	int __fastcall GetCompressFormatCount(void);
	TMetaClass* __fastcall GetCompressFormat(int Index);
	int __fastcall GetDecompressFormatCount(void);
	TMetaClass* __fastcall GetDecompressFormat(int Index);
	
public:
	__fastcall TJclCompressionStreamFormats(void);
	__fastcall virtual ~TJclCompressionStreamFormats(void);
	void __fastcall RegisterFormat(TMetaClass* AClass);
	void __fastcall UnregisterFormat(TMetaClass* AClass);
	TMetaClass* __fastcall FindCompressFormat(const AnsiString AFileName);
	TMetaClass* __fastcall FindDecompressFormat(const AnsiString AFileName);
	__property int CompressFormatCount = {read=GetCompressFormatCount, nodefault};
	__property TMetaClass* CompressFormats[int Index] = {read=GetCompressFormat};
	__property int DecompressFormatCount = {read=GetDecompressFormatCount, nodefault};
	__property TMetaClass* DecompressFormats[int Index] = {read=GetDecompressFormat};
};


typedef int TJclCompressionLevel;

class DELPHICLASS TJclZLibCompressStream;
class PASCALIMPLEMENTATION TJclZLibCompressStream : public TJclCompressStream 
{
	typedef TJclCompressStream inherited;
	
private:
	int FWindowBits;
	int FMemLevel;
	int FMethod;
	int FStrategy;
	bool FDeflateInitialized;
	int FCompressionLevel;
	
protected:
	#pragma pack(push,1)
	z_stream_s ZLibRecord;
	#pragma pack(pop)
	void __fastcall SetCompressionLevel(int Value);
	void __fastcall SetStrategy(int Value);
	void __fastcall SetMemLevel(int Value);
	void __fastcall SetMethod(int Value);
	void __fastcall SetWindowBits(int Value);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall StreamName() { return StreamName(__classid(TJclZLibCompressStream)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall StreamName(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall StreamExtensions() { return StreamExtensions(__classid(TJclZLibCompressStream)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall StreamExtensions(TMetaClass* vmt);
	__fastcall TJclZLibCompressStream(Classes::TStream* Destination, int CompressionLevel);
	__fastcall virtual ~TJclZLibCompressStream(void);
	DYNAMIC int __fastcall Flush(void);
	virtual void __fastcall Reset(void);
	virtual __int64 __fastcall Seek(const __int64 Offset, Classes::TSeekOrigin Origin)/* overload */;
	virtual int __fastcall Write(const void *Buffer, int Count);
	__property int WindowBits = {read=FWindowBits, write=SetWindowBits, nodefault};
	__property int MemLevel = {read=FMemLevel, write=SetMemLevel, nodefault};
	__property int Method = {read=FMethod, write=SetMethod, nodefault};
	__property int Strategy = {read=FStrategy, write=SetStrategy, nodefault};
	__property int CompressionLevel = {read=FCompressionLevel, write=SetCompressionLevel, nodefault};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Seek(int Offset, Word Origin){ return TJclStream::Seek(Offset, Origin); }
	
};


class DELPHICLASS TJclZLibDecompressStream;
class PASCALIMPLEMENTATION TJclZLibDecompressStream : public TJclDecompressStream 
{
	typedef TJclDecompressStream inherited;
	
private:
	int FWindowBits;
	bool FInflateInitialized;
	
protected:
	#pragma pack(push,1)
	z_stream_s ZLibRecord;
	#pragma pack(pop)
	void __fastcall SetWindowBits(int Value);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall StreamName() { return StreamName(__classid(TJclZLibDecompressStream)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall StreamName(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall StreamExtensions() { return StreamExtensions(__classid(TJclZLibDecompressStream)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall StreamExtensions(TMetaClass* vmt);
	__fastcall TJclZLibDecompressStream(Classes::TStream* Source, int WindowBits, bool AOwnsStream);
	__fastcall virtual ~TJclZLibDecompressStream(void);
	virtual int __fastcall Read(void *Buffer, int Count);
	virtual __int64 __fastcall Seek(const __int64 Offset, Classes::TSeekOrigin Origin)/* overload */;
	__property int WindowBits = {read=FWindowBits, write=SetWindowBits, nodefault};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Seek(int Offset, Word Origin){ return TJclStream::Seek(Offset, Origin); }
	
};


#pragma pack(push,1)
struct TJclGZIPHeader
{
	
public:
	Byte ID1;
	Byte ID2;
	Byte CompressionMethod;
	Byte Flags;
	unsigned ModifiedTime;
	Byte ExtraFlags;
	Byte OS;
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct TJclGZIPFooter
{
	
public:
	unsigned DataCRC32;
	unsigned DataSize;
} ;
#pragma pack(pop)

#pragma pack(push,1)
struct TJclGZIPSubFieldHeader
{
	
public:
	Byte SI1;
	Byte SI2;
	Word Len;
} ;
#pragma pack(pop)

#pragma option push -b-
enum TJclGZIPFlag { gfDataIsText, gfHeaderCRC16, gfExtraField, gfOriginalFileName, gfComment };
#pragma option pop

typedef Set<TJclGZIPFlag, gfDataIsText, gfComment>  TJclGZIPFlags;

#pragma option push -b-
enum TJclGZIPFatSystem { gfsFat, gfsAmiga, gfsVMS, gfsUnix, gfsVM, gfsAtari, gfsHPFS, gfsMac, gfsZ, gfsCPM, gfsTOPS, gfsNTFS, gfsQDOS, gfsAcorn, gfsOther, gfsUnknown };
#pragma option pop

class DELPHICLASS TJclGZIPCompressionStream;
class PASCALIMPLEMENTATION TJclGZIPCompressionStream : public TJclCompressStream 
{
	typedef TJclCompressStream inherited;
	
private:
	TJclGZIPFlags FFlags;
	unsigned FUnixTime;
	bool FAutoSetTime;
	int FCompressionLevel;
	TJclGZIPFatSystem FFatSystem;
	AnsiString FExtraField;
	AnsiString FOriginalFileName;
	AnsiString FComment;
	TJclZLibCompressStream* FZLibStream;
	unsigned FOriginalSize;
	unsigned FDataCRC32;
	bool FHeaderWritten;
	bool FFooterWritten;
	void __fastcall WriteHeader(void);
	System::TDateTime __fastcall GetDosTime(void);
	unsigned __fastcall GetUnixTime(void);
	void __fastcall SetDosTime(const System::TDateTime Value);
	void __fastcall SetUnixTime(unsigned Value);
	void __fastcall ZLibStreamProgress(System::TObject* Sender);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall StreamName() { return StreamName(__classid(TJclGZIPCompressionStream)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall StreamName(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall StreamExtensions() { return StreamExtensions(__classid(TJclGZIPCompressionStream)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall StreamExtensions(TMetaClass* vmt);
	__fastcall TJclGZIPCompressionStream(Classes::TStream* Destination, int CompressionLevel);
	__fastcall virtual ~TJclGZIPCompressionStream(void);
	virtual int __fastcall Write(const void *Buffer, int Count);
	virtual void __fastcall Reset(void);
	DYNAMIC int __fastcall Flush(void);
	__property TJclGZIPFlags Flags = {read=FFlags, write=FFlags, nodefault};
	__property System::TDateTime DosTime = {read=GetDosTime, write=SetDosTime};
	__property unsigned UnixTime = {read=GetUnixTime, write=SetUnixTime, nodefault};
	__property bool AutoSetTime = {read=FAutoSetTime, write=FAutoSetTime, nodefault};
	__property TJclGZIPFatSystem FatSystem = {read=FFatSystem, write=FFatSystem, nodefault};
	__property AnsiString ExtraField = {read=FExtraField, write=FExtraField};
	__property AnsiString OriginalFileName = {read=FOriginalFileName, write=FOriginalFileName};
	__property AnsiString Comment = {read=FComment, write=FComment};
};


class DELPHICLASS TJclGZIPDecompressionStream;
class PASCALIMPLEMENTATION TJclGZIPDecompressionStream : public TJclDecompressStream 
{
	typedef TJclDecompressStream inherited;
	
private:
	#pragma pack(push,1)
	TJclGZIPHeader FHeader;
	#pragma pack(pop)
	#pragma pack(push,1)
	TJclGZIPFooter FFooter;
	#pragma pack(pop)
	Jclstreams::TJclDelegatedStream* FCompressedDataStream;
	TJclZLibDecompressStream* FZLibStream;
	AnsiString FOriginalFileName;
	AnsiString FComment;
	AnsiString FExtraField;
	Word FComputedHeaderCRC16;
	Word FStoredHeaderCRC16;
	unsigned FComputedDataCRC32;
	__int64 FCompressedDataSize;
	__int64 FDataSize;
	bool FDataStarted;
	bool FDataEnded;
	bool FAutoCheckDataCRC32;
	__int64 __fastcall GetCompressedDataSize(void);
	unsigned __fastcall GetComputedDataCRC32(void);
	System::TDateTime __fastcall GetDosTime(void);
	TJclGZIPFatSystem __fastcall GetFatSystem(void);
	TJclGZIPFlags __fastcall GetFlags(void);
	unsigned __fastcall GetOriginalDataSize(void);
	unsigned __fastcall GetStoredDataCRC32(void);
	int __fastcall ReadCompressedData(System::TObject* Sender, void *Buffer, int Count);
	void __fastcall ZLibStreamProgress(System::TObject* Sender);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall StreamName() { return StreamName(__classid(TJclGZIPDecompressionStream)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall StreamName(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall StreamExtensions() { return StreamExtensions(__classid(TJclGZIPDecompressionStream)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall StreamExtensions(TMetaClass* vmt);
	__fastcall TJclGZIPDecompressionStream(Classes::TStream* Source, bool CheckHeaderCRC, bool AOwnsStream);
	__fastcall virtual ~TJclGZIPDecompressionStream(void);
	virtual int __fastcall Read(void *Buffer, int Count);
	__property Word ComputedHeaderCRC16 = {read=FComputedHeaderCRC16, nodefault};
	__property Word StoredHeaderCRC16 = {read=FStoredHeaderCRC16, nodefault};
	__property AnsiString ExtraField = {read=FExtraField};
	__property AnsiString OriginalFileName = {read=FOriginalFileName};
	__property AnsiString Comment = {read=FComment};
	__property TJclGZIPFlags Flags = {read=GetFlags, nodefault};
	__property Byte CompressionLevel = {read=FHeader.ExtraFlags, nodefault};
	__property TJclGZIPFatSystem FatSystem = {read=GetFatSystem, nodefault};
	__property unsigned UnixTime = {read=FHeader.ModifiedTime, nodefault};
	__property System::TDateTime DosTime = {read=GetDosTime};
	__property unsigned ComputedDataCRC32 = {read=GetComputedDataCRC32, nodefault};
	__property unsigned StoredDataCRC32 = {read=GetStoredDataCRC32, nodefault};
	__property bool AutoCheckDataCRC32 = {read=FAutoCheckDataCRC32, write=FAutoCheckDataCRC32, nodefault};
	__property __int64 CompressedDataSize = {read=GetCompressedDataSize};
	__property unsigned OriginalDataSize = {read=GetOriginalDataSize, nodefault};
};


class DELPHICLASS TJclBZIP2CompressionStream;
class PASCALIMPLEMENTATION TJclBZIP2CompressionStream : public TJclCompressStream 
{
	typedef TJclCompressStream inherited;
	
private:
	bool FDeflateInitialized;
	int FCompressionLevel;
	
protected:
	Bzip2::bz_stream BZLibRecord;
	void __fastcall SetCompressionLevel(const int Value);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall StreamName() { return StreamName(__classid(TJclBZIP2CompressionStream)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall StreamName(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall StreamExtensions() { return StreamExtensions(__classid(TJclBZIP2CompressionStream)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall StreamExtensions(TMetaClass* vmt);
	__fastcall TJclBZIP2CompressionStream(Classes::TStream* Destination, int ACompressionLevel);
	__fastcall virtual ~TJclBZIP2CompressionStream(void);
	DYNAMIC int __fastcall Flush(void);
	virtual __int64 __fastcall Seek(const __int64 Offset, Classes::TSeekOrigin Origin)/* overload */;
	virtual int __fastcall Write(const void *Buffer, int Count);
	__property int CompressionLevel = {read=FCompressionLevel, write=SetCompressionLevel, nodefault};
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Seek(int Offset, Word Origin){ return TJclStream::Seek(Offset, Origin); }
	
};


class DELPHICLASS TJclBZIP2DecompressionStream;
class PASCALIMPLEMENTATION TJclBZIP2DecompressionStream : public TJclDecompressStream 
{
	typedef TJclDecompressStream inherited;
	
private:
	bool FInflateInitialized;
	
protected:
	Bzip2::bz_stream BZLibRecord;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall StreamName() { return StreamName(__classid(TJclBZIP2DecompressionStream)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall StreamName(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall StreamExtensions() { return StreamExtensions(__classid(TJclBZIP2DecompressionStream)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall StreamExtensions(TMetaClass* vmt);
	__fastcall TJclBZIP2DecompressionStream(Classes::TStream* Source, bool AOwnsStream)/* overload */;
	__fastcall virtual ~TJclBZIP2DecompressionStream(void);
	virtual int __fastcall Read(void *Buffer, int Count);
	virtual __int64 __fastcall Seek(const __int64 Offset, Classes::TSeekOrigin Origin)/* overload */;
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Seek(int Offset, Word Origin){ return TJclStream::Seek(Offset, Origin); }
	
};


class DELPHICLASS EJclCompressionError;
class PASCALIMPLEMENTATION EJclCompressionError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclCompressionError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclCompressionError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclCompressionError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclCompressionError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclCompressionError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclCompressionError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclCompressionError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclCompressionError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclCompressionError(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TJclCompressStreamProgressCallback)(__int64 FileSize, __int64 Position, void * UserData);

typedef void __fastcall (__closure *TJclCompressionVolumeEvent)(System::TObject* Sender, int Index, AnsiString &AFileName, Classes::TStream* &AStream, bool &AOwnsStream);

typedef void __fastcall (__closure *TJclCompressionVolumeMaxSizeEvent)(System::TObject* Sender, int Index, __int64 &AVolumeMaxSize);

typedef void __fastcall (__closure *TJclCompressionProgressEvent)(System::TObject* Sender, const __int64 Value, const __int64 MaxValue);

#pragma option push -b-
enum TJclCompressionItemProperty { ipPackedName, ipPackedSize, ipPackedExtension, ipFileSize, ipFileName, ipAttributes, ipCreationTime, ipLastAccessTime, ipLastWriteTime, ipComment, ipHostOS, ipHostFS, ipUser, ipGroup, ipCRC, ipStream, ipMethod, ipEncrypted };
#pragma option pop

typedef Set<TJclCompressionItemProperty, ipPackedName, ipEncrypted>  TJclCompressionItemProperties;

#pragma option push -b-
enum TJclCompressionItemKind { ikFile, ikDirectory };
#pragma option pop

#pragma option push -b-
enum TJclCompressionOperationSuccess { osNoOperation, osOK, osUnsupportedMethod, osDataError, osCRCError, osUnknownError };
#pragma option pop

#pragma option push -b-
enum TJclCompressionDuplicateCheck { dcNone, dcExisting, dcAll };
#pragma option pop

#pragma option push -b-
enum TJclCompressionDuplicateAction { daOverwrite, daError, daSkip };
#pragma option pop

class DELPHICLASS TJclCompressionItem;
class DELPHICLASS TJclCompressionArchive;
class DELPHICLASS TJclCompressionVolume;
typedef TMetaClass* TJclCompressionItemClass;

#pragma option push -b-
enum TJclStreamAccess { saCreate, saReadOnly, saReadOnlyDenyNone, saWriteOnly, saReadWrite };
#pragma option pop

class PASCALIMPLEMENTATION TJclCompressionArchive : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TJclCompressionProgressEvent FOnProgress;
	TJclCompressionVolumeEvent FOnVolume;
	TJclCompressionVolumeMaxSizeEvent FOnVolumeMaxSize;
	WideString FPassword;
	int FVolumeIndex;
	int FVolumeIndexOffset;
	__int64 FVolumeMaxSize;
	AnsiString FVolumeFileNameMask;
	__int64 FProgressMax;
	int __fastcall GetItemCount(void);
	TJclCompressionItem* __fastcall GetItem(int Index);
	int __fastcall GetVolumeCount(void);
	TJclCompressionVolume* __fastcall GetVolume(int Index);
	
protected:
	Contnrs::TObjectList* FVolumes;
	Contnrs::TObjectList* FItems;
	virtual void __fastcall InitializeArchiveProperties(void);
	Classes::TStream* __fastcall InternalOpenStream(const AnsiString FileName);
	WideString __fastcall TranslateItemPath(const WideString ItemPath, const WideString OldBase, const WideString NewBase);
	void __fastcall DoProgress(const __int64 Value, const __int64 MaxValue);
	Classes::TStream* __fastcall NeedStream(int Index);
	__int64 __fastcall NeedStreamMaxSize(int Index);
	void __fastcall ReleaseVolumes(void);
	virtual TMetaClass* __fastcall GetItemClass(void) = 0 ;
	
public:
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclCompressionArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual TJclStreamAccess __fastcall VolumeAccess() { return VolumeAccess(__classid(TJclCompressionArchive)); }
	#pragma option pop
	/*         class method */ static TJclStreamAccess __fastcall VolumeAccess(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual TJclStreamAccess __fastcall ItemAccess() { return ItemAccess(__classid(TJclCompressionArchive)); }
	#pragma option pop
	/*         class method */ static TJclStreamAccess __fastcall ItemAccess(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclCompressionArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclCompressionArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
	__fastcall virtual TJclCompressionArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */;
	__fastcall virtual TJclCompressionArchive(const AnsiString VolumeFileName, __int64 AVolumeMaxSize, bool VolumeMask)/* overload */;
	__fastcall virtual ~TJclCompressionArchive(void);
	virtual int __fastcall AddVolume(const AnsiString VolumeFileName, __int64 AVolumeMaxSize = 0x000000000)/* overload */;
	virtual int __fastcall AddVolume(const AnsiString VolumeFileName, const AnsiString TmpVolumeFileName, __int64 AVolumeMaxSize = 0x000000000)/* overload */;
	virtual int __fastcall AddVolume(Classes::TStream* VolumeStream, __int64 AVolumeMaxSize = 0x000000000, bool AOwnsStream = false)/* overload */;
	virtual int __fastcall AddVolume(Classes::TStream* VolumeStream, Classes::TStream* TmpVolumeStream, __int64 AVolumeMaxSize = 0x000000000, bool AOwnsStream = false, bool AOwnsTmpStream = false)/* overload */;
	void __fastcall ClearVolumes(void);
	void __fastcall ClearItems(void);
	void __fastcall CheckOperationSuccess(void);
	void __fastcall ClearOperationSuccess(void);
	void __fastcall SelectAll(void);
	void __fastcall UnselectAll(void);
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TJclCompressionItem* Items[int Index] = {read=GetItem};
	__property int VolumeCount = {read=GetVolumeCount, nodefault};
	__property TJclCompressionVolume* Volumes[int Index] = {read=GetVolume};
	__property __int64 VolumeMaxSize = {read=FVolumeMaxSize};
	__property AnsiString VolumeFileNameMask = {read=FVolumeFileNameMask};
	__property int VolumeIndexOffset = {read=FVolumeIndexOffset, write=FVolumeIndexOffset, nodefault};
	__property TJclCompressionProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
	__property TJclCompressionVolumeEvent OnVolume = {read=FOnVolume, write=FOnVolume};
	__property TJclCompressionVolumeMaxSizeEvent OnVolumeMaxSize = {read=FOnVolumeMaxSize, write=FOnVolumeMaxSize};
	__property WideString Password = {read=FPassword, write=FPassword};
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class PASCALIMPLEMENTATION TJclCompressionItem : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TJclCompressionArchive* FArchive;
	AnsiString FFileName;
	Classes::TStream* FStream;
	bool FOwnsStream;
	TJclCompressionItemProperties FValidProperties;
	TJclCompressionItemProperties FModifiedProperties;
	unsigned FPackedIndex;
	bool FSelected;
	TJclCompressionOperationSuccess FOperationSuccess;
	WideString FPackedName;
	__int64 FPackedSize;
	__int64 FFileSize;
	unsigned FAttributes;
	WideString FPackedExtension;
	_FILETIME FCreationTime;
	_FILETIME FLastAccessTime;
	_FILETIME FLastWriteTime;
	WideString FComment;
	WideString FHostOS;
	WideString FHostFS;
	WideString FUser;
	WideString FGroup;
	unsigned FCRC;
	WideString FMethod;
	bool FEncrypted;
	
protected:
	virtual void __fastcall CheckGetProperty(TJclCompressionItemProperty AProperty) = 0 ;
	virtual void __fastcall CheckSetProperty(TJclCompressionItemProperty AProperty) = 0 ;
	virtual bool __fastcall ValidateExtraction(int Index);
	bool __fastcall DeleteOutputFile(void);
	bool __fastcall UpdateFileTimes(void);
	unsigned __fastcall GetAttributes(void);
	WideString __fastcall GetComment();
	unsigned __fastcall GetCRC(void);
	_FILETIME __fastcall GetCreationTime();
	bool __fastcall GetEncrypted(void);
	AnsiString __fastcall GetFileName();
	__int64 __fastcall GetFileSize(void);
	WideString __fastcall GetGroup();
	WideString __fastcall GetHostFS();
	WideString __fastcall GetHostOS();
	TJclCompressionItemKind __fastcall GetItemKind(void);
	_FILETIME __fastcall GetLastAccessTime();
	_FILETIME __fastcall GetLastWriteTime();
	WideString __fastcall GetMethod();
	WideString __fastcall GetPackedExtension();
	WideString __fastcall GetPackedName();
	__int64 __fastcall GetPackedSize(void);
	Classes::TStream* __fastcall GetStream(void);
	WideString __fastcall GetUser();
	void __fastcall SetAttributes(unsigned Value);
	void __fastcall SetComment(const WideString Value);
	void __fastcall SetCRC(unsigned Value);
	void __fastcall SetCreationTime(const _FILETIME &Value);
	void __fastcall SetEncrypted(const bool Value);
	void __fastcall SetFileName(const AnsiString Value);
	void __fastcall SetFileSize(const __int64 Value);
	void __fastcall SetGroup(const WideString Value);
	void __fastcall SetHostFS(const WideString Value);
	void __fastcall SetHostOS(const WideString Value);
	void __fastcall SetLastAccessTime(const _FILETIME &Value);
	void __fastcall SetLastWriteTime(const _FILETIME &Value);
	void __fastcall SetMethod(const WideString Value);
	void __fastcall SetPackedExtension(const WideString Value);
	void __fastcall SetPackedName(const WideString Value);
	void __fastcall SetPackedSize(const __int64 Value);
	void __fastcall SetStream(const Classes::TStream* Value);
	void __fastcall SetUser(const WideString Value);
	
public:
	__fastcall TJclCompressionItem(TJclCompressionArchive* AArchive);
	__fastcall virtual ~TJclCompressionItem(void);
	void __fastcall ReleaseStream(void);
	__property unsigned Attributes = {read=GetAttributes, write=SetAttributes, nodefault};
	__property WideString Comment = {read=GetComment, write=SetComment};
	__property unsigned CRC = {read=GetCRC, write=SetCRC, nodefault};
	__property _FILETIME CreationTime = {read=GetCreationTime, write=SetCreationTime};
	__property bool Encrypted = {read=GetEncrypted, write=SetEncrypted, nodefault};
	__property __int64 FileSize = {read=GetFileSize, write=SetFileSize};
	__property WideString Group = {read=GetGroup, write=SetGroup};
	__property WideString HostOS = {read=GetHostOS, write=SetHostOS};
	__property WideString HostFS = {read=GetHostFS, write=SetHostFS};
	__property TJclCompressionItemKind Kind = {read=GetItemKind, nodefault};
	__property _FILETIME LastAccessTime = {read=GetLastAccessTime, write=SetLastAccessTime};
	__property _FILETIME LastWriteTime = {read=GetLastWriteTime, write=SetLastWriteTime};
	__property WideString Method = {read=GetMethod, write=SetMethod};
	__property WideString PackedExtension = {read=GetPackedExtension, write=SetPackedExtension};
	__property WideString PackedName = {read=GetPackedName, write=SetPackedName};
	__property __int64 PackedSize = {read=GetPackedSize, write=SetPackedSize};
	__property WideString User = {read=GetUser, write=SetUser};
	__property AnsiString FileName = {read=GetFileName, write=SetFileName};
	__property bool OwnsStream = {read=FOwnsStream, write=FOwnsStream, nodefault};
	__property Classes::TStream* Stream = {read=GetStream, write=SetStream};
	__property TJclCompressionArchive* Archive = {read=FArchive};
	__property TJclCompressionOperationSuccess OperationSuccess = {read=FOperationSuccess, write=FOperationSuccess, nodefault};
	__property TJclCompressionItemProperties ValidProperties = {read=FValidProperties, nodefault};
	__property TJclCompressionItemProperties ModifiedProperties = {read=FModifiedProperties, write=FModifiedProperties, nodefault};
	__property unsigned PackedIndex = {read=FPackedIndex, nodefault};
	__property bool Selected = {read=FSelected, write=FSelected, nodefault};
};


class PASCALIMPLEMENTATION TJclCompressionVolume : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	AnsiString FFileName;
	AnsiString FTmpFileName;
	Classes::TStream* FStream;
	Classes::TStream* FTmpStream;
	bool FOwnsStream;
	bool FOwnsTmpStream;
	__int64 FVolumeMaxSize;
	
public:
	__fastcall TJclCompressionVolume(Classes::TStream* AStream, Classes::TStream* ATmpStream, bool AOwnsStream, bool AOwnsTmpStream, AnsiString AFileName, AnsiString ATmpFileName, __int64 AVolumeMaxSize);
	__fastcall virtual ~TJclCompressionVolume(void);
	void __fastcall ReleaseStreams(void);
	__property AnsiString FileName = {read=FFileName};
	__property AnsiString TmpFileName = {read=FTmpFileName};
	__property Classes::TStream* Stream = {read=FStream};
	__property Classes::TStream* TmpStream = {read=FTmpStream};
	__property bool OwnsStream = {read=FOwnsStream, nodefault};
	__property bool OwnsTmpStream = {read=FOwnsTmpStream, nodefault};
	__property __int64 VolumeMaxSize = {read=FVolumeMaxSize};
};


typedef TMetaClass* TJclCompressionArchiveClass;

__interface IJclArchiveNumberOfThreads;
typedef System::DelphiInterface<IJclArchiveNumberOfThreads> _di_IJclArchiveNumberOfThreads;
__interface  INTERFACE_UUID("{9CFAB801-E68E-4A51-AC49-277B297F1141}") IJclArchiveNumberOfThreads  : public IInterface 
{
	
public:
	virtual unsigned __fastcall GetNumberOfThreads(void) = 0 ;
	virtual void __fastcall SetNumberOfThreads(unsigned Value) = 0 ;
	__property unsigned NumberOfThreads = {read=GetNumberOfThreads, write=SetNumberOfThreads};
};

__interface IJclArchiveCompressionLevel;
typedef System::DelphiInterface<IJclArchiveCompressionLevel> _di_IJclArchiveCompressionLevel;
__interface  INTERFACE_UUID("{A6A2F55F-2860-4E44-BC20-8C5D3E322AB6}") IJclArchiveCompressionLevel  : public IInterface 
{
	
public:
	virtual unsigned __fastcall GetCompressionLevel(void) = 0 ;
	virtual unsigned __fastcall GetCompressionLevelMax(void) = 0 ;
	virtual unsigned __fastcall GetCompressionLevelMin(void) = 0 ;
	virtual void __fastcall SetCompressionLevel(unsigned Value) = 0 ;
	__property unsigned CompressionLevel = {read=GetCompressionLevel, write=SetCompressionLevel};
	__property unsigned CompressionLevelMax = {read=GetCompressionLevelMax};
	__property unsigned CompressionLevelMin = {read=GetCompressionLevelMin};
};

#pragma option push -b-
enum TJclCompressionMethod { cmCopy, cmDeflate, cmDeflate64, cmBZip2, cmLZMA, cmLZMA2, cmPPMd };
#pragma option pop

typedef Set<TJclCompressionMethod, cmCopy, cmPPMd>  TJclCompressionMethods;

__interface IJclArchiveCompressionMethod;
typedef System::DelphiInterface<IJclArchiveCompressionMethod> _di_IJclArchiveCompressionMethod;
__interface  INTERFACE_UUID("{2818F8E8-7D5F-4C8C-865E-9BA4512BB766}") IJclArchiveCompressionMethod  : public IInterface 
{
	
public:
	virtual TJclCompressionMethod __fastcall GetCompressionMethod(void) = 0 ;
	virtual TJclCompressionMethods __fastcall GetSupportedCompressionMethods(void) = 0 ;
	virtual void __fastcall SetCompressionMethod(TJclCompressionMethod Value) = 0 ;
	__property TJclCompressionMethod CompressionMethod = {read=GetCompressionMethod, write=SetCompressionMethod};
	__property TJclCompressionMethods SupportedCompressionMethods = {read=GetSupportedCompressionMethods};
};

#pragma option push -b-
enum TJclEncryptionMethod { emNone, emAES128, emAES192, emAES256, emZipCrypto };
#pragma option pop

typedef Set<TJclEncryptionMethod, emNone, emZipCrypto>  TJclEncryptionMethods;

__interface IJclArchiveEncryptionMethod;
typedef System::DelphiInterface<IJclArchiveEncryptionMethod> _di_IJclArchiveEncryptionMethod;
__interface  INTERFACE_UUID("{643485B6-66A1-41C9-A13B-0A8453E9D0C9}") IJclArchiveEncryptionMethod  : public IInterface 
{
	
public:
	virtual TJclEncryptionMethod __fastcall GetEncryptionMethod(void) = 0 ;
	virtual TJclEncryptionMethods __fastcall GetSupportedEncryptionMethods(void) = 0 ;
	virtual void __fastcall SetEncryptionMethod(TJclEncryptionMethod Value) = 0 ;
	__property TJclEncryptionMethod EncryptionMethod = {read=GetEncryptionMethod, write=SetEncryptionMethod};
	__property TJclEncryptionMethods SupportedEncryptionMethods = {read=GetSupportedEncryptionMethods};
};

__interface IJclArchiveDictionarySize;
typedef System::DelphiInterface<IJclArchiveDictionarySize> _di_IJclArchiveDictionarySize;
__interface  INTERFACE_UUID("{D3949834-9F3B-49BC-8403-FE3CE5FDCF35}") IJclArchiveDictionarySize  : public IInterface 
{
	
public:
	virtual unsigned __fastcall GetDictionarySize(void) = 0 ;
	virtual void __fastcall SetDictionarySize(unsigned Value) = 0 ;
	__property unsigned DictionarySize = {read=GetDictionarySize, write=SetDictionarySize};
};

__interface IJclArchiveNumberOfPasses;
typedef System::DelphiInterface<IJclArchiveNumberOfPasses> _di_IJclArchiveNumberOfPasses;
__interface  INTERFACE_UUID("{C61B2814-50CE-4C3C-84A5-BACF8A57E3BC}") IJclArchiveNumberOfPasses  : public IInterface 
{
	
public:
	virtual unsigned __fastcall GetNumberOfPasses(void) = 0 ;
	virtual void __fastcall SetNumberOfPasses(unsigned Value) = 0 ;
	__property unsigned NumberOfPasses = {read=GetNumberOfPasses, write=SetNumberOfPasses};
};

__interface IJclArchiveRemoveSfxBlock;
typedef System::DelphiInterface<IJclArchiveRemoveSfxBlock> _di_IJclArchiveRemoveSfxBlock;
__interface  INTERFACE_UUID("{852D050D-734E-4610-902A-8FB845DB32A9}") IJclArchiveRemoveSfxBlock  : public IInterface 
{
	
public:
	virtual bool __fastcall GetRemoveSfxBlock(void) = 0 ;
	virtual void __fastcall SetRemoveSfxBlock(bool Value) = 0 ;
	__property bool RemoveSfxBlock = {read=GetRemoveSfxBlock, write=SetRemoveSfxBlock};
};

__interface IJclArchiveCompressHeader;
typedef System::DelphiInterface<IJclArchiveCompressHeader> _di_IJclArchiveCompressHeader;
__interface  INTERFACE_UUID("{22C62A3B-A58E-4F88-9D3F-08586B542639}") IJclArchiveCompressHeader  : public IInterface 
{
	
public:
	virtual bool __fastcall GetCompressHeader(void) = 0 ;
	virtual bool __fastcall GetCompressHeaderFull(void) = 0 ;
	virtual void __fastcall SetCompressHeader(bool Value) = 0 ;
	virtual void __fastcall SetCompressHeaderFull(bool Value) = 0 ;
	__property bool CompressHeader = {read=GetCompressHeader, write=SetCompressHeader};
	__property bool CompressHeaderFull = {read=GetCompressHeaderFull, write=SetCompressHeaderFull};
};

__interface IJclArchiveEncryptHeader;
typedef System::DelphiInterface<IJclArchiveEncryptHeader> _di_IJclArchiveEncryptHeader;
__interface  INTERFACE_UUID("{7DBA20A8-48A1-4CA2-B9AC-41C219A09A4A}") IJclArchiveEncryptHeader  : public IInterface 
{
	
public:
	virtual bool __fastcall GetEncryptHeader(void) = 0 ;
	virtual void __fastcall SetEncryptHeader(bool Value) = 0 ;
	__property bool EncryptHeader = {read=GetEncryptHeader, write=SetEncryptHeader};
};

__interface IJclArchiveSaveCreationDateTime;
typedef System::DelphiInterface<IJclArchiveSaveCreationDateTime> _di_IJclArchiveSaveCreationDateTime;
__interface  INTERFACE_UUID("{8B212BF9-C13F-4582-A4FA-A40E538EFF65}") IJclArchiveSaveCreationDateTime  : public IInterface 
{
	
public:
	virtual bool __fastcall GetSaveCreationDateTime(void) = 0 ;
	virtual void __fastcall SetSaveCreationDateTime(bool Value) = 0 ;
	__property bool SaveCreationDateTime = {read=GetSaveCreationDateTime, write=SetSaveCreationDateTime};
};

__interface IJclArchiveSaveLastAccessDateTime;
typedef System::DelphiInterface<IJclArchiveSaveLastAccessDateTime> _di_IJclArchiveSaveLastAccessDateTime;
__interface  INTERFACE_UUID("{1A4B2906-9DD2-4584-B7A3-3639DA92AFC5}") IJclArchiveSaveLastAccessDateTime  : public IInterface 
{
	
public:
	virtual bool __fastcall GetSaveLastAccessDateTime(void) = 0 ;
	virtual void __fastcall SetSaveLastAccessDateTime(bool Value) = 0 ;
	__property bool SaveLastAccessDateTime = {read=GetSaveLastAccessDateTime, write=SetSaveLastAccessDateTime};
};

__interface IJclArchiveSaveLastWriteDateTime;
typedef System::DelphiInterface<IJclArchiveSaveLastWriteDateTime> _di_IJclArchiveSaveLastWriteDateTime;
__interface  INTERFACE_UUID("{0C1729DC-35E8-43D4-8ECA-54F20CDFF87A}") IJclArchiveSaveLastWriteDateTime  : public IInterface 
{
	
public:
	virtual bool __fastcall GetSaveLastWriteDateTime(void) = 0 ;
	virtual void __fastcall SetSaveLastWriteDateTime(bool Value) = 0 ;
	__property bool SaveLastWriteDateTime = {read=GetSaveLastWriteDateTime, write=SetSaveLastWriteDateTime};
};

__interface IJclArchiveAlgorithm;
typedef System::DelphiInterface<IJclArchiveAlgorithm> _di_IJclArchiveAlgorithm;
__interface  INTERFACE_UUID("{53965F1F-24CC-4548-B9E8-5AE2EB7F142D}") IJclArchiveAlgorithm  : public IInterface 
{
	
public:
	virtual unsigned __fastcall GetAlgorithm(void) = 0 ;
	virtual Jclbase::TDynCardinalArray __fastcall GetSupportedAlgorithms(void) = 0 ;
	virtual void __fastcall SetAlgorithm(unsigned Value) = 0 ;
	__property unsigned Algorithm = {read=GetAlgorithm, write=SetAlgorithm};
	__property Jclbase::TDynCardinalArray SupportedAlgorithms = {read=GetSupportedAlgorithms};
};

__interface IJclArchiveSolid;
typedef System::DelphiInterface<IJclArchiveSolid> _di_IJclArchiveSolid;
__interface  INTERFACE_UUID("{6902C54C-1577-422C-B18B-E27953A28661}") IJclArchiveSolid  : public IInterface 
{
	
public:
	virtual __int64 __fastcall GetSolidBlockSize(void) = 0 ;
	virtual bool __fastcall GetSolidExtension(void) = 0 ;
	virtual void __fastcall SetSolidBlockSize(const __int64 Value) = 0 ;
	virtual void __fastcall SetSolidExtension(bool Value) = 0 ;
	__property __int64 SolidBlockSize = {read=GetSolidBlockSize, write=SetSolidBlockSize};
	__property bool SolidExtension = {read=GetSolidExtension, write=SetSolidExtension};
};

class DELPHICLASS TJclCompressItem;
class PASCALIMPLEMENTATION TJclCompressItem : public TJclCompressionItem 
{
	typedef TJclCompressionItem inherited;
	
protected:
	virtual void __fastcall CheckGetProperty(TJclCompressionItemProperty AProperty);
	virtual void __fastcall CheckSetProperty(TJclCompressionItemProperty AProperty);
public:
	#pragma option push -w-inl
	/* TJclCompressionItem.Create */ inline __fastcall TJclCompressItem(TJclCompressionArchive* AArchive) : TJclCompressionItem(AArchive) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclCompressionItem.Destroy */ inline __fastcall virtual ~TJclCompressItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclCompressArchive;
class PASCALIMPLEMENTATION TJclCompressArchive : public TJclCompressionArchive 
{
	typedef TJclCompressionArchive inherited;
	
private:
	WideString FBaseRelName;
	AnsiString FBaseDirName;
	bool FAddFilesInDir;
	TJclCompressionDuplicateAction FDuplicateAction;
	TJclCompressionDuplicateCheck FDuplicateCheck;
	void __fastcall InternalAddFile(const AnsiString Directory, const Sysutils::TSearchRec &FileInfo);
	void __fastcall InternalAddDirectory(const AnsiString Directory);
	
protected:
	bool FCompressing;
	Jclwidestrings::TJclWideStringList* FPackedNames;
	void __fastcall CheckNotCompressing(void);
	int __fastcall AddFileCheckDuplicate(TJclCompressionItem* NewItem);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual TJclStreamAccess __fastcall VolumeAccess() { return VolumeAccess(__classid(TJclCompressArchive)); }
	#pragma option pop
	/*         class method */ static TJclStreamAccess __fastcall VolumeAccess(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual TJclStreamAccess __fastcall ItemAccess() { return ItemAccess(__classid(TJclCompressArchive)); }
	#pragma option pop
	/*         class method */ static TJclStreamAccess __fastcall ItemAccess(TMetaClass* vmt);
	virtual int __fastcall AddDirectory(const WideString PackedName, const AnsiString DirName = "", bool RecurseIntoDir = false, bool AddFilesInDir = false)/* overload */;
	virtual int __fastcall AddFile(const WideString PackedName, const AnsiString FileName)/* overload */;
	virtual int __fastcall AddFile(const WideString PackedName, Classes::TStream* AStream, bool AOwnsStream = false)/* overload */;
	virtual void __fastcall Compress(void);
	__property TJclCompressionDuplicateCheck DuplicateCheck = {read=FDuplicateCheck, write=FDuplicateCheck, nodefault};
	__property TJclCompressionDuplicateAction DuplicateAction = {read=FDuplicateAction, write=FDuplicateAction, nodefault};
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclCompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclCompressionArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclCompressionArchive.Destroy */ inline __fastcall virtual ~TJclCompressArchive(void) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


typedef TMetaClass* TJclCompressArchiveClass;

class DELPHICLASS TJclDecompressItem;
class PASCALIMPLEMENTATION TJclDecompressItem : public TJclCompressionItem 
{
	typedef TJclCompressionItem inherited;
	
protected:
	virtual void __fastcall CheckGetProperty(TJclCompressionItemProperty AProperty);
	virtual void __fastcall CheckSetProperty(TJclCompressionItemProperty AProperty);
	virtual bool __fastcall ValidateExtraction(int Index);
public:
	#pragma option push -w-inl
	/* TJclCompressionItem.Create */ inline __fastcall TJclDecompressItem(TJclCompressionArchive* AArchive) : TJclCompressionItem(AArchive) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclCompressionItem.Destroy */ inline __fastcall virtual ~TJclDecompressItem(void) { }
	#pragma option pop
	
};


typedef bool __fastcall (__closure *TJclCompressionExtractEvent)(System::TObject* Sender, int Index, AnsiString &FileName, Classes::TStream* &Stream, bool &AOwnsStream);

class DELPHICLASS TJclDecompressArchive;
class PASCALIMPLEMENTATION TJclDecompressArchive : public TJclCompressionArchive 
{
	typedef TJclCompressionArchive inherited;
	
private:
	TJclCompressionExtractEvent FOnExtract;
	bool FAutoCreateSubDir;
	
protected:
	bool FDecompressing;
	bool FListing;
	AnsiString FDestinationDir;
	int FExtractingAllIndex;
	void __fastcall CheckNotDecompressing(void);
	void __fastcall CheckListing(void);
	virtual bool __fastcall ValidateExtraction(int Index, AnsiString &FileName, Classes::TStream* &AStream, bool &AOwnsStream);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual TJclStreamAccess __fastcall VolumeAccess() { return VolumeAccess(__classid(TJclDecompressArchive)); }
	#pragma option pop
	/*         class method */ static TJclStreamAccess __fastcall VolumeAccess(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual TJclStreamAccess __fastcall ItemAccess() { return ItemAccess(__classid(TJclDecompressArchive)); }
	#pragma option pop
	/*         class method */ static TJclStreamAccess __fastcall ItemAccess(TMetaClass* vmt);
	virtual void __fastcall ListFiles(void) = 0 ;
	virtual void __fastcall ExtractSelected(const AnsiString ADestinationDir = "", bool AAutoCreateSubDir = true);
	virtual void __fastcall ExtractAll(const AnsiString ADestinationDir = "", bool AAutoCreateSubDir = true);
	__property TJclCompressionExtractEvent OnExtract = {read=FOnExtract, write=FOnExtract};
	__property AnsiString DestinationDir = {read=FDestinationDir};
	__property bool AutoCreateSubDir = {read=FAutoCreateSubDir, nodefault};
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclCompressionArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclCompressionArchive.Destroy */ inline __fastcall virtual ~TJclDecompressArchive(void) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


typedef TMetaClass* TJclDecompressArchiveClass;

class DELPHICLASS TJclUpdateItem;
class PASCALIMPLEMENTATION TJclUpdateItem : public TJclCompressionItem 
{
	typedef TJclCompressionItem inherited;
	
protected:
	virtual void __fastcall CheckGetProperty(TJclCompressionItemProperty AProperty);
	virtual void __fastcall CheckSetProperty(TJclCompressionItemProperty AProperty);
	virtual bool __fastcall ValidateExtraction(int Index);
public:
	#pragma option push -w-inl
	/* TJclCompressionItem.Create */ inline __fastcall TJclUpdateItem(TJclCompressionArchive* AArchive) : TJclCompressionItem(AArchive) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TJclCompressionItem.Destroy */ inline __fastcall virtual ~TJclUpdateItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclUpdateArchive;
class PASCALIMPLEMENTATION TJclUpdateArchive : public TJclCompressArchive 
{
	typedef TJclCompressArchive inherited;
	
private:
	TJclCompressionExtractEvent FOnExtract;
	bool FAutoCreateSubDir;
	
protected:
	bool FDecompressing;
	bool FListing;
	AnsiString FDestinationDir;
	int FExtractingAllIndex;
	void __fastcall CheckNotDecompressing(void);
	void __fastcall CheckListing(void);
	virtual bool __fastcall ValidateExtraction(int Index, AnsiString &FileName, Classes::TStream* &AStream, bool &AOwnsStream);
	
public:
	__fastcall virtual TJclUpdateArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */;
	__fastcall virtual TJclUpdateArchive(const AnsiString VolumeFileName, __int64 AVolumeMaxSize, bool VolumeMask)/* overload */;
	#pragma option push -w-inl
	/* virtual class method */ virtual TJclStreamAccess __fastcall VolumeAccess() { return VolumeAccess(__classid(TJclUpdateArchive)); }
	#pragma option pop
	/*         class method */ static TJclStreamAccess __fastcall VolumeAccess(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual TJclStreamAccess __fastcall ItemAccess() { return ItemAccess(__classid(TJclUpdateArchive)); }
	#pragma option pop
	/*         class method */ static TJclStreamAccess __fastcall ItemAccess(TMetaClass* vmt);
	virtual void __fastcall ListFiles(void) = 0 ;
	virtual void __fastcall ExtractSelected(const AnsiString ADestinationDir = "", bool AAutoCreateSubDir = true);
	virtual void __fastcall ExtractAll(const AnsiString ADestinationDir = "", bool AAutoCreateSubDir = true);
	virtual void __fastcall DeleteItem(int Index) = 0 ;
	virtual void __fastcall RemoveItem(const WideString PackedName) = 0 ;
	__property TJclCompressionExtractEvent OnExtract = {read=FOnExtract, write=FOnExtract};
	__property AnsiString DestinationDir = {read=FDestinationDir};
	__property bool AutoCreateSubDir = {read=FAutoCreateSubDir, nodefault};
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Destroy */ inline __fastcall virtual ~TJclUpdateArchive(void) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclInPlaceUpdateArchive;
class PASCALIMPLEMENTATION TJclInPlaceUpdateArchive : public TJclUpdateArchive 
{
	typedef TJclUpdateArchive inherited;
	
public:
	#pragma option push -w-inl
	/* TJclUpdateArchive.Create */ inline __fastcall virtual TJclInPlaceUpdateArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclUpdateArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Destroy */ inline __fastcall virtual ~TJclInPlaceUpdateArchive(void) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


typedef bool __fastcall (*TJclCompressionReplaceEvent)(System::TObject* Sender, const AnsiString SrcFileName, const AnsiString DestFileName, Classes::TStream* &SrcStream, Classes::TStream* &DestStream, bool &OwnsSrcStream, bool &OwnsDestStream);

class DELPHICLASS TJclOutOfPlaceUpdateArchive;
class PASCALIMPLEMENTATION TJclOutOfPlaceUpdateArchive : public TJclUpdateArchive 
{
	typedef TJclUpdateArchive inherited;
	
private:
	bool FReplaceVolumes;
	int FTmpVolumeIndex;
	TJclCompressionReplaceEvent FOnReplace;
	TJclCompressionVolumeEvent FOnTmpVolume;
	
protected:
	Classes::TStream* __fastcall NeedTmpStream(int Index);
	Classes::TStream* __fastcall InternalOpenTmpStream(const AnsiString FileName);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual TJclStreamAccess __fastcall TmpVolumeAccess() { return TmpVolumeAccess(__classid(TJclOutOfPlaceUpdateArchive)); }
	#pragma option pop
	/*         class method */ static TJclStreamAccess __fastcall TmpVolumeAccess(TMetaClass* vmt);
	__fastcall virtual TJclOutOfPlaceUpdateArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */;
	__fastcall virtual TJclOutOfPlaceUpdateArchive(const AnsiString VolumeFileName, __int64 AVolumeMaxSize, bool VolumeMask)/* overload */;
	virtual void __fastcall Compress(void);
	__property bool ReplaceVolumes = {read=FReplaceVolumes, write=FReplaceVolumes, nodefault};
	__property TJclCompressionReplaceEvent OnReplace = {read=FOnReplace, write=FOnReplace};
	__property TJclCompressionVolumeEvent OnTmpVolume = {read=FOnTmpVolume, write=FOnTmpVolume};
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Destroy */ inline __fastcall virtual ~TJclOutOfPlaceUpdateArchive(void) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


typedef TMetaClass* TJclUpdateArchiveClass;

class DELPHICLASS TJclCompressionArchiveFormats;
class PASCALIMPLEMENTATION TJclCompressionArchiveFormats : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* FCompressFormats;
	Classes::TList* FDecompressFormats;
	Classes::TList* FUpdateFormats;
	
protected:
	int __fastcall GetCompressFormatCount(void);
	TMetaClass* __fastcall GetCompressFormat(int Index);
	int __fastcall GetDecompressFormatCount(void);
	TMetaClass* __fastcall GetDecompressFormat(int Index);
	int __fastcall GetUpdateFormatCount(void);
	TMetaClass* __fastcall GetUpdateFormat(int Index);
	
public:
	__fastcall TJclCompressionArchiveFormats(void);
	__fastcall virtual ~TJclCompressionArchiveFormats(void);
	void __fastcall RegisterFormat(TMetaClass* AClass);
	void __fastcall UnregisterFormat(TMetaClass* AClass);
	TMetaClass* __fastcall FindCompressFormat(const AnsiString AFileName);
	TMetaClass* __fastcall FindDecompressFormat(const AnsiString AFileName);
	TMetaClass* __fastcall FindUpdateFormat(const AnsiString AFileName);
	__property int CompressFormatCount = {read=GetCompressFormatCount, nodefault};
	__property TMetaClass* CompressFormats[int Index] = {read=GetCompressFormat};
	__property int DecompressFormatCount = {read=GetDecompressFormatCount, nodefault};
	__property TMetaClass* DecompressFormats[int Index] = {read=GetDecompressFormat};
	__property int UpdateFormatCount = {read=GetUpdateFormatCount, nodefault};
	__property TMetaClass* UpdateFormats[int Index] = {read=GetUpdateFormat};
};


class DELPHICLASS TJclSevenzipCompressArchive;
class PASCALIMPLEMENTATION TJclSevenzipCompressArchive : public TJclCompressArchive 
{
	typedef TJclCompressArchive inherited;
	
private:
	Sevenzip::_di_IOutArchive FOutArchive;
	
protected:
	virtual GUID __fastcall GetCLSID(void) = 0 ;
	virtual TMetaClass* __fastcall GetItemClass(void);
	Sevenzip::_di_IOutArchive __fastcall GetOutArchive();
	
public:
	__fastcall virtual ~TJclSevenzipCompressArchive(void);
	virtual void __fastcall Compress(void);
	__property Sevenzip::_di_IOutArchive OutArchive = {read=GetOutArchive};
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclSevenzipCompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclCompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclZipCompressArchive;
class PASCALIMPLEMENTATION TJclZipCompressArchive : public TJclSevenzipCompressArchive 
{
	typedef TJclSevenzipCompressArchive inherited;
	
private:
	unsigned FNumberOfThreads;
	TJclEncryptionMethod FEncryptionMethod;
	unsigned FDictionarySize;
	unsigned FCompressionLevel;
	TJclCompressionMethod FCompressionMethod;
	unsigned FNumberOfPasses;
	unsigned FAlgorithm;
	
protected:
	virtual GUID __fastcall GetCLSID();
	virtual void __fastcall InitializeArchiveProperties(void);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclZipCompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclZipCompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclZipCompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
	unsigned __fastcall GetNumberOfThreads(void);
	void __fastcall SetNumberOfThreads(unsigned Value);
	TJclEncryptionMethod __fastcall GetEncryptionMethod(void);
	TJclEncryptionMethods __fastcall GetSupportedEncryptionMethods(void);
	void __fastcall SetEncryptionMethod(TJclEncryptionMethod Value);
	unsigned __fastcall GetDictionarySize(void);
	void __fastcall SetDictionarySize(unsigned Value);
	unsigned __fastcall GetCompressionLevel(void);
	unsigned __fastcall GetCompressionLevelMax(void);
	unsigned __fastcall GetCompressionLevelMin(void);
	void __fastcall SetCompressionLevel(unsigned Value);
	TJclCompressionMethod __fastcall GetCompressionMethod(void);
	TJclCompressionMethods __fastcall GetSupportedCompressionMethods(void);
	void __fastcall SetCompressionMethod(TJclCompressionMethod Value);
	unsigned __fastcall GetNumberOfPasses(void);
	void __fastcall SetNumberOfPasses(unsigned Value);
	unsigned __fastcall GetAlgorithm(void);
	Jclbase::TDynCardinalArray __fastcall GetSupportedAlgorithms();
	void __fastcall SetAlgorithm(unsigned Value);
public:
	#pragma option push -w-inl
	/* TJclSevenzipCompressArchive.Destroy */ inline __fastcall virtual ~TJclZipCompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclZipCompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipCompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IJclArchiveCompressionLevel;	/* Jclcompression::IJclArchiveCompressionLevel */
	void *__IJclArchiveCompressionMethod;	/* Jclcompression::IJclArchiveCompressionMethod */
	void *__IJclArchiveEncryptionMethod;	/* Jclcompression::IJclArchiveEncryptionMethod */
	void *__IJclArchiveDictionarySize;	/* Jclcompression::IJclArchiveDictionarySize */
	void *__IJclArchiveNumberOfPasses;	/* Jclcompression::IJclArchiveNumberOfPasses */
	void *__IJclArchiveNumberOfThreads;	/* Jclcompression::IJclArchiveNumberOfThreads */
	void *__IJclArchiveAlgorithm;	/* Jclcompression::IJclArchiveAlgorithm */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IJclArchiveAlgorithm; }
	operator IJclArchiveAlgorithm*(void) { return (IJclArchiveAlgorithm*)&__IJclArchiveAlgorithm; }
	operator IJclArchiveNumberOfThreads*(void) { return (IJclArchiveNumberOfThreads*)&__IJclArchiveNumberOfThreads; }
	operator IJclArchiveNumberOfPasses*(void) { return (IJclArchiveNumberOfPasses*)&__IJclArchiveNumberOfPasses; }
	operator IJclArchiveDictionarySize*(void) { return (IJclArchiveDictionarySize*)&__IJclArchiveDictionarySize; }
	operator IJclArchiveEncryptionMethod*(void) { return (IJclArchiveEncryptionMethod*)&__IJclArchiveEncryptionMethod; }
	operator IJclArchiveCompressionMethod*(void) { return (IJclArchiveCompressionMethod*)&__IJclArchiveCompressionMethod; }
	operator IJclArchiveCompressionLevel*(void) { return (IJclArchiveCompressionLevel*)&__IJclArchiveCompressionLevel; }
	
};


class DELPHICLASS TJclBZ2CompressArchive;
class PASCALIMPLEMENTATION TJclBZ2CompressArchive : public TJclSevenzipCompressArchive 
{
	typedef TJclSevenzipCompressArchive inherited;
	
private:
	unsigned FNumberOfThreads;
	unsigned FDictionarySize;
	unsigned FCompressionLevel;
	unsigned FNumberOfPasses;
	
protected:
	virtual GUID __fastcall GetCLSID();
	virtual void __fastcall InitializeArchiveProperties(void);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclBZ2CompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclBZ2CompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
	unsigned __fastcall GetNumberOfThreads(void);
	void __fastcall SetNumberOfThreads(unsigned Value);
	unsigned __fastcall GetDictionarySize(void);
	void __fastcall SetDictionarySize(unsigned Value);
	unsigned __fastcall GetCompressionLevel(void);
	unsigned __fastcall GetCompressionLevelMax(void);
	unsigned __fastcall GetCompressionLevelMin(void);
	void __fastcall SetCompressionLevel(unsigned Value);
	unsigned __fastcall GetNumberOfPasses(void);
	void __fastcall SetNumberOfPasses(unsigned Value);
public:
	#pragma option push -w-inl
	/* TJclSevenzipCompressArchive.Destroy */ inline __fastcall virtual ~TJclBZ2CompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclBZ2CompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipCompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IJclArchiveCompressionLevel;	/* Jclcompression::IJclArchiveCompressionLevel */
	void *__IJclArchiveDictionarySize;	/* Jclcompression::IJclArchiveDictionarySize */
	void *__IJclArchiveNumberOfPasses;	/* Jclcompression::IJclArchiveNumberOfPasses */
	void *__IJclArchiveNumberOfThreads;	/* Jclcompression::IJclArchiveNumberOfThreads */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IJclArchiveNumberOfThreads; }
	operator IJclArchiveNumberOfThreads*(void) { return (IJclArchiveNumberOfThreads*)&__IJclArchiveNumberOfThreads; }
	operator IJclArchiveNumberOfPasses*(void) { return (IJclArchiveNumberOfPasses*)&__IJclArchiveNumberOfPasses; }
	operator IJclArchiveDictionarySize*(void) { return (IJclArchiveDictionarySize*)&__IJclArchiveDictionarySize; }
	operator IJclArchiveCompressionLevel*(void) { return (IJclArchiveCompressionLevel*)&__IJclArchiveCompressionLevel; }
	
};


class DELPHICLASS TJcl7zCompressArchive;
class PASCALIMPLEMENTATION TJcl7zCompressArchive : public TJclSevenzipCompressArchive 
{
	typedef TJclSevenzipCompressArchive inherited;
	
private:
	unsigned FNumberOfThreads;
	bool FEncryptHeader;
	bool FRemoveSfxBlock;
	unsigned FDictionarySize;
	unsigned FCompressionLevel;
	bool FCompressHeader;
	bool FCompressHeaderFull;
	bool FSaveLastAccessDateTime;
	bool FSaveCreationDateTime;
	bool FSaveLastWriteDateTime;
	__int64 FSolidBlockSize;
	bool FSolidExtension;
	
protected:
	virtual GUID __fastcall GetCLSID();
	virtual void __fastcall InitializeArchiveProperties(void);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJcl7zCompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJcl7zCompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJcl7zCompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
	unsigned __fastcall GetNumberOfThreads(void);
	void __fastcall SetNumberOfThreads(unsigned Value);
	bool __fastcall GetEncryptHeader(void);
	void __fastcall SetEncryptHeader(bool Value);
	bool __fastcall GetRemoveSfxBlock(void);
	void __fastcall SetRemoveSfxBlock(bool Value);
	unsigned __fastcall GetDictionarySize(void);
	void __fastcall SetDictionarySize(unsigned Value);
	unsigned __fastcall GetCompressionLevel(void);
	unsigned __fastcall GetCompressionLevelMax(void);
	unsigned __fastcall GetCompressionLevelMin(void);
	void __fastcall SetCompressionLevel(unsigned Value);
	bool __fastcall GetCompressHeader(void);
	bool __fastcall GetCompressHeaderFull(void);
	void __fastcall SetCompressHeader(bool Value);
	void __fastcall SetCompressHeaderFull(bool Value);
	bool __fastcall GetSaveLastAccessDateTime(void);
	void __fastcall SetSaveLastAccessDateTime(bool Value);
	bool __fastcall GetSaveCreationDateTime(void);
	void __fastcall SetSaveCreationDateTime(bool Value);
	bool __fastcall GetSaveLastWriteDateTime(void);
	void __fastcall SetSaveLastWriteDateTime(bool Value);
	__int64 __fastcall GetSolidBlockSize(void);
	bool __fastcall GetSolidExtension(void);
	void __fastcall SetSolidBlockSize(const __int64 Value);
	void __fastcall SetSolidExtension(bool Value);
public:
	#pragma option push -w-inl
	/* TJclSevenzipCompressArchive.Destroy */ inline __fastcall virtual ~TJcl7zCompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJcl7zCompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipCompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IJclArchiveCompressionLevel;	/* Jclcompression::IJclArchiveCompressionLevel */
	void *__IJclArchiveDictionarySize;	/* Jclcompression::IJclArchiveDictionarySize */
	void *__IJclArchiveNumberOfThreads;	/* Jclcompression::IJclArchiveNumberOfThreads */
	void *__IJclArchiveRemoveSfxBlock;	/* Jclcompression::IJclArchiveRemoveSfxBlock */
	void *__IJclArchiveCompressHeader;	/* Jclcompression::IJclArchiveCompressHeader */
	void *__IJclArchiveEncryptHeader;	/* Jclcompression::IJclArchiveEncryptHeader */
	void *__IJclArchiveSaveCreationDateTime;	/* Jclcompression::IJclArchiveSaveCreationDateTime */
	void *__IJclArchiveSaveLastAccessDateTime;	/* Jclcompression::IJclArchiveSaveLastAccessDateTime */
	void *__IJclArchiveSaveLastWriteDateTime;	/* Jclcompression::IJclArchiveSaveLastWriteDateTime */
	void *__IJclArchiveSolid;	/* Jclcompression::IJclArchiveSolid */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IJclArchiveSolid; }
	operator IJclArchiveSolid*(void) { return (IJclArchiveSolid*)&__IJclArchiveSolid; }
	operator IJclArchiveSaveLastWriteDateTime*(void) { return (IJclArchiveSaveLastWriteDateTime*)&__IJclArchiveSaveLastWriteDateTime; }
	operator IJclArchiveSaveLastAccessDateTime*(void) { return (IJclArchiveSaveLastAccessDateTime*)&__IJclArchiveSaveLastAccessDateTime; }
	operator IJclArchiveSaveCreationDateTime*(void) { return (IJclArchiveSaveCreationDateTime*)&__IJclArchiveSaveCreationDateTime; }
	operator IJclArchiveEncryptHeader*(void) { return (IJclArchiveEncryptHeader*)&__IJclArchiveEncryptHeader; }
	operator IJclArchiveCompressHeader*(void) { return (IJclArchiveCompressHeader*)&__IJclArchiveCompressHeader; }
	operator IJclArchiveRemoveSfxBlock*(void) { return (IJclArchiveRemoveSfxBlock*)&__IJclArchiveRemoveSfxBlock; }
	operator IJclArchiveNumberOfThreads*(void) { return (IJclArchiveNumberOfThreads*)&__IJclArchiveNumberOfThreads; }
	operator IJclArchiveDictionarySize*(void) { return (IJclArchiveDictionarySize*)&__IJclArchiveDictionarySize; }
	operator IJclArchiveCompressionLevel*(void) { return (IJclArchiveCompressionLevel*)&__IJclArchiveCompressionLevel; }
	
};


class DELPHICLASS TJclTarCompressArchive;
class PASCALIMPLEMENTATION TJclTarCompressArchive : public TJclSevenzipCompressArchive 
{
	typedef TJclSevenzipCompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclTarCompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclTarCompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclTarCompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipCompressArchive.Destroy */ inline __fastcall virtual ~TJclTarCompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclTarCompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipCompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclGZipCompressArchive;
class PASCALIMPLEMENTATION TJclGZipCompressArchive : public TJclSevenzipCompressArchive 
{
	typedef TJclSevenzipCompressArchive inherited;
	
private:
	unsigned FCompressionLevel;
	unsigned FNumberOfPasses;
	unsigned FAlgorithm;
	
protected:
	virtual GUID __fastcall GetCLSID();
	virtual void __fastcall InitializeArchiveProperties(void);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclGZipCompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclGZipCompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
	unsigned __fastcall GetCompressionLevel(void);
	unsigned __fastcall GetCompressionLevelMax(void);
	unsigned __fastcall GetCompressionLevelMin(void);
	void __fastcall SetCompressionLevel(unsigned Value);
	unsigned __fastcall GetNumberOfPasses(void);
	void __fastcall SetNumberOfPasses(unsigned Value);
	unsigned __fastcall GetAlgorithm(void);
	Jclbase::TDynCardinalArray __fastcall GetSupportedAlgorithms();
	void __fastcall SetAlgorithm(unsigned Value);
public:
	#pragma option push -w-inl
	/* TJclSevenzipCompressArchive.Destroy */ inline __fastcall virtual ~TJclGZipCompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclGZipCompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipCompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IJclArchiveCompressionLevel;	/* Jclcompression::IJclArchiveCompressionLevel */
	void *__IJclArchiveNumberOfPasses;	/* Jclcompression::IJclArchiveNumberOfPasses */
	void *__IJclArchiveAlgorithm;	/* Jclcompression::IJclArchiveAlgorithm */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IJclArchiveAlgorithm; }
	operator IJclArchiveAlgorithm*(void) { return (IJclArchiveAlgorithm*)&__IJclArchiveAlgorithm; }
	operator IJclArchiveNumberOfPasses*(void) { return (IJclArchiveNumberOfPasses*)&__IJclArchiveNumberOfPasses; }
	operator IJclArchiveCompressionLevel*(void) { return (IJclArchiveCompressionLevel*)&__IJclArchiveCompressionLevel; }
	
};


class DELPHICLASS TJclXzCompressArchive;
class PASCALIMPLEMENTATION TJclXzCompressArchive : public TJclSevenzipCompressArchive 
{
	typedef TJclSevenzipCompressArchive inherited;
	
private:
	TJclCompressionMethod FCompressionMethod;
	
protected:
	virtual GUID __fastcall GetCLSID();
	virtual void __fastcall InitializeArchiveProperties(void);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclXzCompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclXzCompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
	TJclCompressionMethod __fastcall GetCompressionMethod(void);
	TJclCompressionMethods __fastcall GetSupportedCompressionMethods(void);
	void __fastcall SetCompressionMethod(TJclCompressionMethod Value);
public:
	#pragma option push -w-inl
	/* TJclSevenzipCompressArchive.Destroy */ inline __fastcall virtual ~TJclXzCompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclXzCompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipCompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IJclArchiveCompressionMethod;	/* Jclcompression::IJclArchiveCompressionMethod */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IJclArchiveCompressionMethod; }
	operator IJclArchiveCompressionMethod*(void) { return (IJclArchiveCompressionMethod*)&__IJclArchiveCompressionMethod; }
	
};


class DELPHICLASS TJclSwfcCompressArchive;
class PASCALIMPLEMENTATION TJclSwfcCompressArchive : public TJclSevenzipCompressArchive 
{
	typedef TJclSevenzipCompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclSwfcCompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclSwfcCompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipCompressArchive.Destroy */ inline __fastcall virtual ~TJclSwfcCompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclSwfcCompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipCompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclSevenzipDecompressArchive;
class PASCALIMPLEMENTATION TJclSevenzipDecompressArchive : public TJclDecompressArchive 
{
	typedef TJclDecompressArchive inherited;
	
private:
	Sevenzip::_di_IInArchive FInArchive;
	bool FOpened;
	
protected:
	void __fastcall OpenArchive(void);
	virtual GUID __fastcall GetCLSID(void) = 0 ;
	Sevenzip::_di_IInArchive __fastcall GetInArchive();
	virtual TMetaClass* __fastcall GetItemClass(void);
	
public:
	__fastcall virtual ~TJclSevenzipDecompressArchive(void);
	virtual void __fastcall ListFiles(void);
	virtual void __fastcall ExtractSelected(const AnsiString ADestinationDir = "", bool AAutoCreateSubDir = true);
	virtual void __fastcall ExtractAll(const AnsiString ADestinationDir = "", bool AAutoCreateSubDir = true);
	__property Sevenzip::_di_IInArchive InArchive = {read=GetInArchive};
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclSevenzipDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclZipDecompressArchive;
class PASCALIMPLEMENTATION TJclZipDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
private:
	unsigned FNumberOfThreads;
	
protected:
	virtual GUID __fastcall GetCLSID();
	virtual void __fastcall InitializeArchiveProperties(void);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclZipDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclZipDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclZipDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
	unsigned __fastcall GetNumberOfThreads(void);
	void __fastcall SetNumberOfThreads(unsigned Value);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclZipDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclZipDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IJclArchiveNumberOfThreads;	/* Jclcompression::IJclArchiveNumberOfThreads */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IJclArchiveNumberOfThreads; }
	operator IJclArchiveNumberOfThreads*(void) { return (IJclArchiveNumberOfThreads*)&__IJclArchiveNumberOfThreads; }
	
};


class DELPHICLASS TJclBZ2DecompressArchive;
class PASCALIMPLEMENTATION TJclBZ2DecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
private:
	unsigned FNumberOfThreads;
	
protected:
	virtual GUID __fastcall GetCLSID();
	virtual void __fastcall InitializeArchiveProperties(void);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclBZ2DecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclBZ2DecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
	unsigned __fastcall GetNumberOfThreads(void);
	void __fastcall SetNumberOfThreads(unsigned Value);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclBZ2DecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclBZ2DecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IJclArchiveNumberOfThreads;	/* Jclcompression::IJclArchiveNumberOfThreads */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IJclArchiveNumberOfThreads; }
	operator IJclArchiveNumberOfThreads*(void) { return (IJclArchiveNumberOfThreads*)&__IJclArchiveNumberOfThreads; }
	
};


class DELPHICLASS TJclRarDecompressArchive;
class PASCALIMPLEMENTATION TJclRarDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclRarDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclRarDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclRarDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclRarDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclRarDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclArjDecompressArchive;
class PASCALIMPLEMENTATION TJclArjDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclArjDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclArjDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclArjDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclArjDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclArjDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclZDecompressArchive;
class PASCALIMPLEMENTATION TJclZDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclZDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclZDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclZDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclZDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclZDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclLzhDecompressArchive;
class PASCALIMPLEMENTATION TJclLzhDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclLzhDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclLzhDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclLzhDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclLzhDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclLzhDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJcl7zDecompressArchive;
class PASCALIMPLEMENTATION TJcl7zDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
private:
	unsigned FNumberOfThreads;
	
protected:
	virtual GUID __fastcall GetCLSID();
	virtual void __fastcall InitializeArchiveProperties(void);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJcl7zDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJcl7zDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJcl7zDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
	unsigned __fastcall GetNumberOfThreads(void);
	void __fastcall SetNumberOfThreads(unsigned Value);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJcl7zDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJcl7zDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IJclArchiveNumberOfThreads;	/* Jclcompression::IJclArchiveNumberOfThreads */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IJclArchiveNumberOfThreads; }
	operator IJclArchiveNumberOfThreads*(void) { return (IJclArchiveNumberOfThreads*)&__IJclArchiveNumberOfThreads; }
	
};


class DELPHICLASS TJclCabDecompressArchive;
class PASCALIMPLEMENTATION TJclCabDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclCabDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclCabDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclCabDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclCabDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclCabDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclNsisDecompressArchive;
class PASCALIMPLEMENTATION TJclNsisDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclNsisDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclNsisDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclNsisDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclNsisDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclNsisDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclLzmaDecompressArchive;
class PASCALIMPLEMENTATION TJclLzmaDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclLzmaDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclLzmaDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclLzmaDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclLzmaDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclLzmaDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclLzma86DecompressArchive;
class PASCALIMPLEMENTATION TJclLzma86DecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclLzma86DecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclLzma86DecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclLzma86DecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclLzma86DecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclLzma86DecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclPeDecompressArchive;
class PASCALIMPLEMENTATION TJclPeDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclPeDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclPeDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclPeDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclPeDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclPeDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclElfDecompressArchive;
class PASCALIMPLEMENTATION TJclElfDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclElfDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclElfDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclElfDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclElfDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclElfDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclMachoDecompressArchive;
class PASCALIMPLEMENTATION TJclMachoDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclMachoDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclMachoDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclMachoDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclMachoDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclMachoDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclUdfDecompressArchive;
class PASCALIMPLEMENTATION TJclUdfDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclUdfDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclUdfDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclUdfDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclUdfDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclUdfDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclXarDecompressArchive;
class PASCALIMPLEMENTATION TJclXarDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclXarDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclXarDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclXarDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclXarDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclXarDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclMubDecompressArchive;
class PASCALIMPLEMENTATION TJclMubDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclMubDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclMubDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclMubDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclMubDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclMubDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclHfsDecompressArchive;
class PASCALIMPLEMENTATION TJclHfsDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclHfsDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclHfsDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclHfsDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclHfsDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclHfsDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclDmgDecompressArchive;
class PASCALIMPLEMENTATION TJclDmgDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclDmgDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclDmgDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclDmgDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclDmgDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclDmgDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclCompoundDecompressArchive;
class PASCALIMPLEMENTATION TJclCompoundDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclCompoundDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclCompoundDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclCompoundDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclCompoundDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclCompoundDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclWimDecompressArchive;
class PASCALIMPLEMENTATION TJclWimDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclWimDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclWimDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclWimDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclWimDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclWimDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclIsoDecompressArchive;
class PASCALIMPLEMENTATION TJclIsoDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclIsoDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclIsoDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclIsoDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclIsoDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclIsoDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclChmDecompressArchive;
class PASCALIMPLEMENTATION TJclChmDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclChmDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclChmDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclChmDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclChmDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclChmDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclSplitDecompressArchive;
class PASCALIMPLEMENTATION TJclSplitDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclSplitDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclSplitDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclSplitDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclSplitDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclRpmDecompressArchive;
class PASCALIMPLEMENTATION TJclRpmDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclRpmDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclRpmDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclRpmDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclRpmDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclRpmDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclDebDecompressArchive;
class PASCALIMPLEMENTATION TJclDebDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclDebDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclDebDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclDebDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclDebDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclDebDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclCpioDecompressArchive;
class PASCALIMPLEMENTATION TJclCpioDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclCpioDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclCpioDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclCpioDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclCpioDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclCpioDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclTarDecompressArchive;
class PASCALIMPLEMENTATION TJclTarDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclTarDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclTarDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclTarDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclTarDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclTarDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclGZipDecompressArchive;
class PASCALIMPLEMENTATION TJclGZipDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclGZipDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclGZipDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclGZipDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclGZipDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclXzDecompressArchive;
class PASCALIMPLEMENTATION TJclXzDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclXzDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclXzDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclXzDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclXzDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclNtfsDecompressArchive;
class PASCALIMPLEMENTATION TJclNtfsDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclNtfsDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclNtfsDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclNtfsDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclNtfsDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclNtfsDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclFatDecompressArchive;
class PASCALIMPLEMENTATION TJclFatDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclFatDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclFatDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclFatDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclFatDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclFatDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclMbrDecompressArchive;
class PASCALIMPLEMENTATION TJclMbrDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclMbrDecompressArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclMbrDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclMbrDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclMbrDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclMbrDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclVhdDecompressArchive;
class PASCALIMPLEMENTATION TJclVhdDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclVhdDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclVhdDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclVhdDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclVhdDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclMslzDecompressArchive;
class PASCALIMPLEMENTATION TJclMslzDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclMslzDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclMslzDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclMslzDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclMslzDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclFlvDecompressArchive;
class PASCALIMPLEMENTATION TJclFlvDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclFlvDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclFlvDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclFlvDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclFlvDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclSwfDecompressArchive;
class PASCALIMPLEMENTATION TJclSwfDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclSwfDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclSwfDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclSwfDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclSwfDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclSwfcDecompressArchive;
class PASCALIMPLEMENTATION TJclSwfcDecompressArchive : public TJclSevenzipDecompressArchive 
{
	typedef TJclSevenzipDecompressArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclSwfcDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclSwfcDecompressArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipDecompressArchive.Destroy */ inline __fastcall virtual ~TJclSwfcDecompressArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclCompressionArchive.Create */ inline __fastcall virtual TJclSwfcDecompressArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipDecompressArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclSevenzipUpdateArchive;
class PASCALIMPLEMENTATION TJclSevenzipUpdateArchive : public TJclOutOfPlaceUpdateArchive 
{
	typedef TJclOutOfPlaceUpdateArchive inherited;
	
private:
	Sevenzip::_di_IInArchive FInArchive;
	Sevenzip::_di_IOutArchive FOutArchive;
	bool FOpened;
	
protected:
	void __fastcall OpenArchive(void);
	virtual GUID __fastcall GetCLSID(void) = 0 ;
	Sevenzip::_di_IInArchive __fastcall GetInArchive();
	virtual TMetaClass* __fastcall GetItemClass(void);
	Sevenzip::_di_IOutArchive __fastcall GetOutArchive();
	
public:
	__fastcall virtual ~TJclSevenzipUpdateArchive(void);
	virtual void __fastcall ListFiles(void);
	virtual void __fastcall ExtractSelected(const AnsiString ADestinationDir = "", bool AAutoCreateSubDir = true);
	virtual void __fastcall ExtractAll(const AnsiString ADestinationDir = "", bool AAutoCreateSubDir = true);
	virtual void __fastcall Compress(void);
	virtual void __fastcall DeleteItem(int Index);
	virtual void __fastcall RemoveItem(const WideString PackedName);
	__property Sevenzip::_di_IInArchive InArchive = {read=GetInArchive};
	__property Sevenzip::_di_IOutArchive OutArchive = {read=GetOutArchive};
public:
	#pragma option push -w-inl
	/* TJclOutOfPlaceUpdateArchive.Create */ inline __fastcall virtual TJclSevenzipUpdateArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclOutOfPlaceUpdateArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclZipUpdateArchive;
class PASCALIMPLEMENTATION TJclZipUpdateArchive : public TJclSevenzipUpdateArchive 
{
	typedef TJclSevenzipUpdateArchive inherited;
	
private:
	unsigned FNumberOfThreads;
	TJclEncryptionMethod FEncryptionMethod;
	unsigned FDictionarySize;
	unsigned FCompressionLevel;
	TJclCompressionMethod FCompressionMethod;
	unsigned FNumberOfPasses;
	unsigned FAlgorithm;
	
protected:
	virtual GUID __fastcall GetCLSID();
	virtual void __fastcall InitializeArchiveProperties(void);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclZipUpdateArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclZipUpdateArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclZipUpdateArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
	unsigned __fastcall GetNumberOfThreads(void);
	void __fastcall SetNumberOfThreads(unsigned Value);
	TJclEncryptionMethod __fastcall GetEncryptionMethod(void);
	TJclEncryptionMethods __fastcall GetSupportedEncryptionMethods(void);
	void __fastcall SetEncryptionMethod(TJclEncryptionMethod Value);
	unsigned __fastcall GetDictionarySize(void);
	void __fastcall SetDictionarySize(unsigned Value);
	unsigned __fastcall GetCompressionLevel(void);
	unsigned __fastcall GetCompressionLevelMax(void);
	unsigned __fastcall GetCompressionLevelMin(void);
	void __fastcall SetCompressionLevel(unsigned Value);
	TJclCompressionMethod __fastcall GetCompressionMethod(void);
	TJclCompressionMethods __fastcall GetSupportedCompressionMethods(void);
	void __fastcall SetCompressionMethod(TJclCompressionMethod Value);
	unsigned __fastcall GetNumberOfPasses(void);
	void __fastcall SetNumberOfPasses(unsigned Value);
	unsigned __fastcall GetAlgorithm(void);
	Jclbase::TDynCardinalArray __fastcall GetSupportedAlgorithms();
	void __fastcall SetAlgorithm(unsigned Value);
public:
	#pragma option push -w-inl
	/* TJclSevenzipUpdateArchive.Destroy */ inline __fastcall virtual ~TJclZipUpdateArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclOutOfPlaceUpdateArchive.Create */ inline __fastcall virtual TJclZipUpdateArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipUpdateArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IJclArchiveCompressionLevel;	/* Jclcompression::IJclArchiveCompressionLevel */
	void *__IJclArchiveCompressionMethod;	/* Jclcompression::IJclArchiveCompressionMethod */
	void *__IJclArchiveEncryptionMethod;	/* Jclcompression::IJclArchiveEncryptionMethod */
	void *__IJclArchiveDictionarySize;	/* Jclcompression::IJclArchiveDictionarySize */
	void *__IJclArchiveNumberOfPasses;	/* Jclcompression::IJclArchiveNumberOfPasses */
	void *__IJclArchiveNumberOfThreads;	/* Jclcompression::IJclArchiveNumberOfThreads */
	void *__IJclArchiveAlgorithm;	/* Jclcompression::IJclArchiveAlgorithm */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IJclArchiveAlgorithm; }
	operator IJclArchiveAlgorithm*(void) { return (IJclArchiveAlgorithm*)&__IJclArchiveAlgorithm; }
	operator IJclArchiveNumberOfThreads*(void) { return (IJclArchiveNumberOfThreads*)&__IJclArchiveNumberOfThreads; }
	operator IJclArchiveNumberOfPasses*(void) { return (IJclArchiveNumberOfPasses*)&__IJclArchiveNumberOfPasses; }
	operator IJclArchiveDictionarySize*(void) { return (IJclArchiveDictionarySize*)&__IJclArchiveDictionarySize; }
	operator IJclArchiveEncryptionMethod*(void) { return (IJclArchiveEncryptionMethod*)&__IJclArchiveEncryptionMethod; }
	operator IJclArchiveCompressionMethod*(void) { return (IJclArchiveCompressionMethod*)&__IJclArchiveCompressionMethod; }
	operator IJclArchiveCompressionLevel*(void) { return (IJclArchiveCompressionLevel*)&__IJclArchiveCompressionLevel; }
	
};


class DELPHICLASS TJclBZ2UpdateArchive;
class PASCALIMPLEMENTATION TJclBZ2UpdateArchive : public TJclSevenzipUpdateArchive 
{
	typedef TJclSevenzipUpdateArchive inherited;
	
private:
	unsigned FNumberOfThreads;
	unsigned FDictionarySize;
	unsigned FCompressionLevel;
	unsigned FNumberOfPasses;
	
protected:
	virtual GUID __fastcall GetCLSID();
	virtual void __fastcall InitializeArchiveProperties(void);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclBZ2UpdateArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclBZ2UpdateArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
	unsigned __fastcall GetNumberOfThreads(void);
	void __fastcall SetNumberOfThreads(unsigned Value);
	unsigned __fastcall GetDictionarySize(void);
	void __fastcall SetDictionarySize(unsigned Value);
	unsigned __fastcall GetCompressionLevel(void);
	unsigned __fastcall GetCompressionLevelMax(void);
	unsigned __fastcall GetCompressionLevelMin(void);
	void __fastcall SetCompressionLevel(unsigned Value);
	unsigned __fastcall GetNumberOfPasses(void);
	void __fastcall SetNumberOfPasses(unsigned Value);
public:
	#pragma option push -w-inl
	/* TJclSevenzipUpdateArchive.Destroy */ inline __fastcall virtual ~TJclBZ2UpdateArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclOutOfPlaceUpdateArchive.Create */ inline __fastcall virtual TJclBZ2UpdateArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipUpdateArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IJclArchiveCompressionLevel;	/* Jclcompression::IJclArchiveCompressionLevel */
	void *__IJclArchiveDictionarySize;	/* Jclcompression::IJclArchiveDictionarySize */
	void *__IJclArchiveNumberOfPasses;	/* Jclcompression::IJclArchiveNumberOfPasses */
	void *__IJclArchiveNumberOfThreads;	/* Jclcompression::IJclArchiveNumberOfThreads */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IJclArchiveNumberOfThreads; }
	operator IJclArchiveNumberOfThreads*(void) { return (IJclArchiveNumberOfThreads*)&__IJclArchiveNumberOfThreads; }
	operator IJclArchiveNumberOfPasses*(void) { return (IJclArchiveNumberOfPasses*)&__IJclArchiveNumberOfPasses; }
	operator IJclArchiveDictionarySize*(void) { return (IJclArchiveDictionarySize*)&__IJclArchiveDictionarySize; }
	operator IJclArchiveCompressionLevel*(void) { return (IJclArchiveCompressionLevel*)&__IJclArchiveCompressionLevel; }
	
};


class DELPHICLASS TJcl7zUpdateArchive;
class PASCALIMPLEMENTATION TJcl7zUpdateArchive : public TJclSevenzipUpdateArchive 
{
	typedef TJclSevenzipUpdateArchive inherited;
	
private:
	unsigned FNumberOfThreads;
	bool FEncryptHeader;
	bool FRemoveSfxBlock;
	unsigned FDictionarySize;
	unsigned FCompressionLevel;
	bool FCompressHeader;
	bool FCompressHeaderFull;
	bool FSaveLastAccessDateTime;
	bool FSaveCreationDateTime;
	bool FSaveLastWriteDateTime;
	
protected:
	virtual GUID __fastcall GetCLSID();
	virtual void __fastcall InitializeArchiveProperties(void);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJcl7zUpdateArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJcl7zUpdateArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJcl7zUpdateArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
	unsigned __fastcall GetNumberOfThreads(void);
	void __fastcall SetNumberOfThreads(unsigned Value);
	bool __fastcall GetEncryptHeader(void);
	void __fastcall SetEncryptHeader(bool Value);
	bool __fastcall GetRemoveSfxBlock(void);
	void __fastcall SetRemoveSfxBlock(bool Value);
	unsigned __fastcall GetDictionarySize(void);
	void __fastcall SetDictionarySize(unsigned Value);
	unsigned __fastcall GetCompressionLevel(void);
	unsigned __fastcall GetCompressionLevelMax(void);
	unsigned __fastcall GetCompressionLevelMin(void);
	void __fastcall SetCompressionLevel(unsigned Value);
	bool __fastcall GetCompressHeader(void);
	bool __fastcall GetCompressHeaderFull(void);
	void __fastcall SetCompressHeader(bool Value);
	void __fastcall SetCompressHeaderFull(bool Value);
	bool __fastcall GetSaveLastAccessDateTime(void);
	void __fastcall SetSaveLastAccessDateTime(bool Value);
	bool __fastcall GetSaveCreationDateTime(void);
	void __fastcall SetSaveCreationDateTime(bool Value);
	bool __fastcall GetSaveLastWriteDateTime(void);
	void __fastcall SetSaveLastWriteDateTime(bool Value);
public:
	#pragma option push -w-inl
	/* TJclSevenzipUpdateArchive.Destroy */ inline __fastcall virtual ~TJcl7zUpdateArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclOutOfPlaceUpdateArchive.Create */ inline __fastcall virtual TJcl7zUpdateArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipUpdateArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IJclArchiveCompressionLevel;	/* Jclcompression::IJclArchiveCompressionLevel */
	void *__IJclArchiveDictionarySize;	/* Jclcompression::IJclArchiveDictionarySize */
	void *__IJclArchiveNumberOfThreads;	/* Jclcompression::IJclArchiveNumberOfThreads */
	void *__IJclArchiveRemoveSfxBlock;	/* Jclcompression::IJclArchiveRemoveSfxBlock */
	void *__IJclArchiveCompressHeader;	/* Jclcompression::IJclArchiveCompressHeader */
	void *__IJclArchiveEncryptHeader;	/* Jclcompression::IJclArchiveEncryptHeader */
	void *__IJclArchiveSaveCreationDateTime;	/* Jclcompression::IJclArchiveSaveCreationDateTime */
	void *__IJclArchiveSaveLastAccessDateTime;	/* Jclcompression::IJclArchiveSaveLastAccessDateTime */
	void *__IJclArchiveSaveLastWriteDateTime;	/* Jclcompression::IJclArchiveSaveLastWriteDateTime */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IJclArchiveSaveLastWriteDateTime; }
	operator IJclArchiveSaveLastWriteDateTime*(void) { return (IJclArchiveSaveLastWriteDateTime*)&__IJclArchiveSaveLastWriteDateTime; }
	operator IJclArchiveSaveLastAccessDateTime*(void) { return (IJclArchiveSaveLastAccessDateTime*)&__IJclArchiveSaveLastAccessDateTime; }
	operator IJclArchiveSaveCreationDateTime*(void) { return (IJclArchiveSaveCreationDateTime*)&__IJclArchiveSaveCreationDateTime; }
	operator IJclArchiveEncryptHeader*(void) { return (IJclArchiveEncryptHeader*)&__IJclArchiveEncryptHeader; }
	operator IJclArchiveCompressHeader*(void) { return (IJclArchiveCompressHeader*)&__IJclArchiveCompressHeader; }
	operator IJclArchiveRemoveSfxBlock*(void) { return (IJclArchiveRemoveSfxBlock*)&__IJclArchiveRemoveSfxBlock; }
	operator IJclArchiveNumberOfThreads*(void) { return (IJclArchiveNumberOfThreads*)&__IJclArchiveNumberOfThreads; }
	operator IJclArchiveDictionarySize*(void) { return (IJclArchiveDictionarySize*)&__IJclArchiveDictionarySize; }
	operator IJclArchiveCompressionLevel*(void) { return (IJclArchiveCompressionLevel*)&__IJclArchiveCompressionLevel; }
	
};


class DELPHICLASS TJclTarUpdateArchive;
class PASCALIMPLEMENTATION TJclTarUpdateArchive : public TJclSevenzipUpdateArchive 
{
	typedef TJclSevenzipUpdateArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual bool __fastcall MultipleItemContainer() { return MultipleItemContainer(__classid(TJclTarUpdateArchive)); }
	#pragma option pop
	/*         class method */ static bool __fastcall MultipleItemContainer(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclTarUpdateArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclTarUpdateArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipUpdateArchive.Destroy */ inline __fastcall virtual ~TJclTarUpdateArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclOutOfPlaceUpdateArchive.Create */ inline __fastcall virtual TJclTarUpdateArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipUpdateArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclGZipUpdateArchive;
class PASCALIMPLEMENTATION TJclGZipUpdateArchive : public TJclSevenzipUpdateArchive 
{
	typedef TJclSevenzipUpdateArchive inherited;
	
private:
	unsigned FCompressionLevel;
	unsigned FNumberOfPasses;
	unsigned FAlgorithm;
	
protected:
	virtual GUID __fastcall GetCLSID();
	virtual void __fastcall InitializeArchiveProperties(void);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclGZipUpdateArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclGZipUpdateArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
	unsigned __fastcall GetCompressionLevel(void);
	unsigned __fastcall GetCompressionLevelMax(void);
	unsigned __fastcall GetCompressionLevelMin(void);
	void __fastcall SetCompressionLevel(unsigned Value);
	unsigned __fastcall GetNumberOfPasses(void);
	void __fastcall SetNumberOfPasses(unsigned Value);
	unsigned __fastcall GetAlgorithm(void);
	Jclbase::TDynCardinalArray __fastcall GetSupportedAlgorithms();
	void __fastcall SetAlgorithm(unsigned Value);
public:
	#pragma option push -w-inl
	/* TJclSevenzipUpdateArchive.Destroy */ inline __fastcall virtual ~TJclGZipUpdateArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclOutOfPlaceUpdateArchive.Create */ inline __fastcall virtual TJclGZipUpdateArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipUpdateArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IJclArchiveCompressionLevel;	/* Jclcompression::IJclArchiveCompressionLevel */
	void *__IJclArchiveNumberOfPasses;	/* Jclcompression::IJclArchiveNumberOfPasses */
	void *__IJclArchiveAlgorithm;	/* Jclcompression::IJclArchiveAlgorithm */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IJclArchiveAlgorithm; }
	operator IJclArchiveAlgorithm*(void) { return (IJclArchiveAlgorithm*)&__IJclArchiveAlgorithm; }
	operator IJclArchiveNumberOfPasses*(void) { return (IJclArchiveNumberOfPasses*)&__IJclArchiveNumberOfPasses; }
	operator IJclArchiveCompressionLevel*(void) { return (IJclArchiveCompressionLevel*)&__IJclArchiveCompressionLevel; }
	
};


class DELPHICLASS TJclXzUpdateArchive;
class PASCALIMPLEMENTATION TJclXzUpdateArchive : public TJclSevenzipUpdateArchive 
{
	typedef TJclSevenzipUpdateArchive inherited;
	
private:
	TJclCompressionMethod FCompressionMethod;
	
protected:
	virtual GUID __fastcall GetCLSID();
	virtual void __fastcall InitializeArchiveProperties(void);
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclXzUpdateArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclXzUpdateArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
	TJclCompressionMethod __fastcall GetCompressionMethod(void);
	TJclCompressionMethods __fastcall GetSupportedCompressionMethods(void);
	void __fastcall SetCompressionMethod(TJclCompressionMethod Value);
public:
	#pragma option push -w-inl
	/* TJclSevenzipUpdateArchive.Destroy */ inline __fastcall virtual ~TJclXzUpdateArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclOutOfPlaceUpdateArchive.Create */ inline __fastcall virtual TJclXzUpdateArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipUpdateArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IJclArchiveCompressionMethod;	/* Jclcompression::IJclArchiveCompressionMethod */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IJclArchiveCompressionMethod; }
	operator IJclArchiveCompressionMethod*(void) { return (IJclArchiveCompressionMethod*)&__IJclArchiveCompressionMethod; }
	
};


class DELPHICLASS TJclSwfcUpdateArchive;
class PASCALIMPLEMENTATION TJclSwfcUpdateArchive : public TJclSevenzipUpdateArchive 
{
	typedef TJclSevenzipUpdateArchive inherited;
	
protected:
	virtual GUID __fastcall GetCLSID();
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveExtensions() { return ArchiveExtensions(__classid(TJclSwfcUpdateArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveExtensions(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall ArchiveName() { return ArchiveName(__classid(TJclSwfcUpdateArchive)); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall ArchiveName(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TJclSevenzipUpdateArchive.Destroy */ inline __fastcall virtual ~TJclSwfcUpdateArchive(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TJclOutOfPlaceUpdateArchive.Create */ inline __fastcall virtual TJclSwfcUpdateArchive(Classes::TStream* Volume0, __int64 AVolumeMaxSize, bool AOwnVolume)/* overload */ : TJclSevenzipUpdateArchive(Volume0, AVolumeMaxSize, AOwnVolume) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TJclSevenzipOutStream;
class PASCALIMPLEMENTATION TJclSevenzipOutStream : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	TJclCompressionArchive* FArchive;
	int FItemIndex;
	Classes::TStream* FStream;
	bool FOwnsStream;
	bool FTruncateOnRelease;
	__int64 FMaximumPosition;
	void __fastcall NeedStream(void);
	void __fastcall ReleaseStream(void);
	
public:
	__fastcall TJclSevenzipOutStream(TJclCompressionArchive* AArchive, int AItemIndex)/* overload */;
	__fastcall TJclSevenzipOutStream(Classes::TStream* AStream, bool AOwnsStream, bool ATruncateOnRelease)/* overload */;
	__fastcall virtual ~TJclSevenzipOutStream(void);
	HRESULT __stdcall Write(void * Data, unsigned Size, Jclbase::PCardinal ProcessedSize);
	HRESULT __stdcall Seek(__int64 Offset, unsigned SeekOrigin, Jclbase::PInt64 NewPosition);
	HRESULT __stdcall SetSize(__int64 NewSize);
private:
	void *__IOutStream;	/* Sevenzip::IOutStream */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IOutStream; }
	operator IOutStream*(void) { return (IOutStream*)&__IOutStream; }
	operator ISequentialOutStream*(void) { return (ISequentialOutStream*)&__IOutStream; }
	
};


class DELPHICLASS TJclSevenzipInStream;
class PASCALIMPLEMENTATION TJclSevenzipInStream : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	TJclCompressionArchive* FArchive;
	int FItemIndex;
	Classes::TStream* FStream;
	bool FOwnsStream;
	void __fastcall NeedStream(void);
	void __fastcall ReleaseStream(void);
	
public:
	__fastcall TJclSevenzipInStream(TJclCompressionArchive* AArchive, int AItemIndex)/* overload */;
	__fastcall TJclSevenzipInStream(Classes::TStream* AStream, bool AOwnsStream)/* overload */;
	__fastcall virtual ~TJclSevenzipInStream(void);
	HRESULT __stdcall Read(void * Data, unsigned Size, Jclbase::PCardinal ProcessedSize);
	HRESULT __stdcall Seek(__int64 Offset, unsigned SeekOrigin, Jclbase::PInt64 NewPosition);
	HRESULT __stdcall GetSize(Jclbase::PInt64 Size);
private:
	void *__IInStream;	/* Sevenzip::IInStream */
	void *__IStreamGetSize;	/* Sevenzip::IStreamGetSize */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IStreamGetSize; }
	operator IStreamGetSize*(void) { return (IStreamGetSize*)&__IStreamGetSize; }
	operator IInStream*(void) { return (IInStream*)&__IInStream; }
	operator ISequentialInStream*(void) { return (ISequentialInStream*)&__IInStream; }
	
};


class DELPHICLASS TJclSevenzipOpenCallback;
class PASCALIMPLEMENTATION TJclSevenzipOpenCallback : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	TJclCompressionArchive* FArchive;
	
public:
	__fastcall TJclSevenzipOpenCallback(TJclCompressionArchive* AArchive);
	HRESULT __stdcall SetCompleted(Jclbase::PInt64 Files, Jclbase::PInt64 Bytes);
	HRESULT __stdcall SetTotal(Jclbase::PInt64 Files, Jclbase::PInt64 Bytes);
	HRESULT __stdcall CryptoGetTextPassword(Activex::PBStr password);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclSevenzipOpenCallback(void) { }
	#pragma option pop
	
private:
	void *__IArchiveOpenCallback;	/* Sevenzip::IArchiveOpenCallback */
	void *__ICryptoGetTextPassword;	/* Sevenzip::ICryptoGetTextPassword */
	
public:
	operator IInterface*(void) { return (IInterface*)&__ICryptoGetTextPassword; }
	operator ICryptoGetTextPassword*(void) { return (ICryptoGetTextPassword*)&__ICryptoGetTextPassword; }
	operator IArchiveOpenCallback*(void) { return (IArchiveOpenCallback*)&__IArchiveOpenCallback; }
	
};


class DELPHICLASS TJclSevenzipExtractCallback;
class PASCALIMPLEMENTATION TJclSevenzipExtractCallback : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	TJclCompressionArchive* FArchive;
	unsigned FLastStream;
	
public:
	__fastcall TJclSevenzipExtractCallback(TJclCompressionArchive* AArchive);
	HRESULT __stdcall GetStream(unsigned Index, /* out */ Sevenzip::_di_ISequentialOutStream &OutStream, unsigned askExtractMode);
	HRESULT __stdcall PrepareOperation(unsigned askExtractMode);
	HRESULT __stdcall SetOperationResult(int resultEOperationResult);
	HRESULT __stdcall SetCompleted(Jclbase::PInt64 CompleteValue);
	HRESULT __stdcall SetTotal(__int64 Total);
	HRESULT __stdcall CryptoGetTextPassword(Activex::PBStr password);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclSevenzipExtractCallback(void) { }
	#pragma option pop
	
private:
	void *__IArchiveExtractCallback;	/* Sevenzip::IArchiveExtractCallback */
	void *__ICryptoGetTextPassword;	/* Sevenzip::ICryptoGetTextPassword */
	
public:
	operator ICryptoGetTextPassword*(void) { return (ICryptoGetTextPassword*)&__ICryptoGetTextPassword; }
	operator IArchiveExtractCallback*(void) { return (IArchiveExtractCallback*)&__IArchiveExtractCallback; }
	operator IProgress*(void) { return (IProgress*)&__IArchiveExtractCallback; }
	operator IInterface*(void) { return (IInterface*)&__ICryptoGetTextPassword; }
	
};


class DELPHICLASS TJclSevenzipUpdateCallback;
class PASCALIMPLEMENTATION TJclSevenzipUpdateCallback : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	TJclCompressionArchive* FArchive;
	unsigned FLastStream;
	
public:
	__fastcall TJclSevenzipUpdateCallback(TJclCompressionArchive* AArchive);
	HRESULT __stdcall SetCompleted(Jclbase::PInt64 CompleteValue);
	HRESULT __stdcall SetTotal(__int64 Total);
	HRESULT __stdcall GetProperty(unsigned Index, unsigned PropID, /* out */ tagPROPVARIANT &Value);
	HRESULT __stdcall GetStream(unsigned Index, /* out */ Sevenzip::_di_ISequentialInStream &InStream);
	HRESULT __stdcall GetUpdateItemInfo(unsigned Index, System::PInteger NewData, System::PInteger NewProperties, Jclbase::PCardinal IndexInArchive);
	HRESULT __stdcall SetOperationResult(int OperationResult);
	HRESULT __stdcall GetVolumeSize(unsigned Index, Jclbase::PInt64 Size);
	HRESULT __stdcall GetVolumeStream(unsigned Index, /* out */ Sevenzip::_di_ISequentialOutStream &VolumeStream);
	HRESULT __stdcall CryptoGetTextPassword2(System::PInteger PasswordIsDefined, Activex::PBStr Password);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclSevenzipUpdateCallback(void) { }
	#pragma option pop
	
private:
	void *__IArchiveUpdateCallback2;	/* Sevenzip::IArchiveUpdateCallback2 */
	void *__ICryptoGetTextPassword2;	/* Sevenzip::ICryptoGetTextPassword2 */
	
public:
	operator ICryptoGetTextPassword2*(void) { return (ICryptoGetTextPassword2*)&__ICryptoGetTextPassword2; }
	operator IArchiveUpdateCallback2*(void) { return (IArchiveUpdateCallback2*)&__IArchiveUpdateCallback2; }
	operator IArchiveUpdateCallback*(void) { return (IArchiveUpdateCallback*)&__IArchiveUpdateCallback2; }
	operator IProgress*(void) { return (IProgress*)&__IArchiveUpdateCallback2; }
	operator IInterface*(void) { return (IInterface*)&__ICryptoGetTextPassword2; }
	
};


typedef void __fastcall (__closure *TWideStringSetter)(const WideString Value);

typedef void __fastcall (__closure *TCardinalSetter)(unsigned Value);

typedef void __fastcall (__closure *TInt64Setter)(const __int64 Value);

typedef void __fastcall (__closure *TFileTimeSetter)(const _FILETIME &Value);

typedef void __fastcall (__closure *TBoolSetter)(const bool Value);

//-- var, const, procedure ---------------------------------------------------
static const Shortint JCL_GZIP_ID1 = 0x1f;
static const Byte JCL_GZIP_ID2 = 0x8b;
static const Shortint JCL_GZIP_CM_DEFLATE = 0x8;
static const Shortint JCL_GZIP_FLAG_TEXT = 0x1;
static const Shortint JCL_GZIP_FLAG_CRC = 0x2;
static const Shortint JCL_GZIP_FLAG_EXTRA = 0x4;
static const Shortint JCL_GZIP_FLAG_NAME = 0x8;
static const Shortint JCL_GZIP_FLAG_COMMENT = 0x10;
static const Shortint JCL_GZIP_EFLAG_MAX = 0x2;
static const Shortint JCL_GZIP_EFLAG_FAST = 0x4;
static const Shortint JCL_GZIP_OS_FAT = 0x0;
static const Shortint JCL_GZIP_OS_AMIGA = 0x1;
static const Shortint JCL_GZIP_OS_VMS = 0x2;
static const Shortint JCL_GZIP_OS_UNIX = 0x3;
static const Shortint JCL_GZIP_OS_VM = 0x4;
static const Shortint JCL_GZIP_OS_ATARI = 0x5;
static const Shortint JCL_GZIP_OS_HPFS = 0x6;
static const Shortint JCL_GZIP_OS_MAC = 0x7;
static const Shortint JCL_GZIP_OS_Z = 0x8;
static const Shortint JCL_GZIP_OS_CPM = 0x9;
static const Shortint JCL_GZIP_OS_TOPS = 0xa;
static const Shortint JCL_GZIP_OS_NTFS = 0xb;
static const Shortint JCL_GZIP_OS_QDOS = 0xc;
static const Shortint JCL_GZIP_OS_ACORN = 0xd;
static const Byte JCL_GZIP_OS_UNKNOWN = 0xff;
static const Shortint JCL_GZIP_X_AC1 = 0x41;
static const Shortint JCL_GZIP_X_AC2 = 0x43;
static const Shortint JCL_GZIP_X_Ap1 = 0x41;
static const Shortint JCL_GZIP_X_Ap2 = 0x70;
static const Shortint JCL_GZIP_X_cp1 = 0x63;
static const Shortint JCL_GZIP_X_cp2 = 0x70;
static const Shortint JCL_GZIP_X_GS1 = 0x1d;
static const Shortint JCL_GZIP_X_GS2 = 0x53;
static const Shortint JCL_GZIP_X_KN1 = 0x4b;
static const Shortint JCL_GZIP_X_KN2 = 0x4e;
static const Shortint JCL_GZIP_X_Mc1 = 0x4d;
static const Shortint JCL_GZIP_X_Mc2 = 0x63;
static const Shortint JCL_GZIP_X_RO1 = 0x52;
static const Shortint JCL_GZIP_X_RO2 = 0x4f;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE TJclCompressionStreamFormats* __fastcall GetStreamFormats(void);
extern PACKAGE bool __fastcall GZipFile(AnsiString SourceFile, AnsiString DestinationFile, int CompressionLevel = 0xffffffff, TJclCompressStreamProgressCallback ProgressCallback = 0x0, void * UserData = (void *)(0x0));
extern PACKAGE bool __fastcall UnGZipFile(AnsiString SourceFile, AnsiString DestinationFile, TJclCompressStreamProgressCallback ProgressCallback = 0x0, void * UserData = (void *)(0x0));
extern PACKAGE void __fastcall GZipStream(Classes::TStream* SourceStream, Classes::TStream* DestinationStream, int CompressionLevel = 0xffffffff, TJclCompressStreamProgressCallback ProgressCallback = 0x0, void * UserData = (void *)(0x0));
extern PACKAGE void __fastcall UnGZipStream(Classes::TStream* SourceStream, Classes::TStream* DestinationStream, TJclCompressStreamProgressCallback ProgressCallback = 0x0, void * UserData = (void *)(0x0));
extern PACKAGE bool __fastcall BZip2File(AnsiString SourceFile, AnsiString DestinationFile, int CompressionLevel = 0x5, TJclCompressStreamProgressCallback ProgressCallback = 0x0, void * UserData = (void *)(0x0));
extern PACKAGE bool __fastcall UnBZip2File(AnsiString SourceFile, AnsiString DestinationFile, TJclCompressStreamProgressCallback ProgressCallback = 0x0, void * UserData = (void *)(0x0));
extern PACKAGE void __fastcall BZip2Stream(Classes::TStream* SourceStream, Classes::TStream* DestinationStream, int CompressionLevel = 0x5, TJclCompressStreamProgressCallback ProgressCallback = 0x0, void * UserData = (void *)(0x0));
extern PACKAGE void __fastcall UnBZip2Stream(Classes::TStream* SourceStream, Classes::TStream* DestinationStream, TJclCompressStreamProgressCallback ProgressCallback = 0x0, void * UserData = (void *)(0x0));
extern PACKAGE TJclCompressionArchiveFormats* __fastcall GetArchiveFormats(void);
extern PACKAGE void __fastcall SevenzipCheck(HRESULT Value);
extern PACKAGE bool __fastcall Get7zWideStringProp(const Sevenzip::_di_IInArchive AArchive, int ItemIndex, unsigned PropID, const TWideStringSetter Setter);
extern PACKAGE bool __fastcall Get7zCardinalProp(const Sevenzip::_di_IInArchive AArchive, int ItemIndex, unsigned PropID, const TCardinalSetter Setter);
extern PACKAGE bool __fastcall Get7zInt64Prop(const Sevenzip::_di_IInArchive AArchive, int ItemIndex, unsigned PropID, const TInt64Setter Setter);
extern PACKAGE bool __fastcall Get7zFileTimeProp(const Sevenzip::_di_IInArchive AArchive, int ItemIndex, unsigned PropID, const TFileTimeSetter Setter);
extern PACKAGE bool __fastcall Get7zBoolProp(const Sevenzip::_di_IInArchive AArchive, int ItemIndex, unsigned PropID, const TBoolSetter Setter);
extern PACKAGE void __fastcall Load7zFileAttribute(Sevenzip::_di_IInArchive AInArchive, int ItemIndex, TJclCompressionItem* AItem);
extern PACKAGE void __fastcall GetSevenzipArchiveCompressionProperties(System::_di_IInterface AJclArchive, System::_di_IInterface ASevenzipArchive);
extern PACKAGE void __fastcall SetSevenzipArchiveCompressionProperties(System::_di_IInterface AJclArchive, System::_di_IInterface ASevenzipArchive);

}	/* namespace Jclcompression */
using namespace Jclcompression;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclcompression
