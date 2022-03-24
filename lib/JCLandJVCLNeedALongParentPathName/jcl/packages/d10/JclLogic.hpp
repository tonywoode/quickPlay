// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jcllogic.pas' rev: 10.00

#ifndef JcllogicHPP
#define JcllogicHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jcllogic
{
//-- type declarations -------------------------------------------------------
typedef Byte TBitRange;

typedef DynamicArray<bool >  TBooleanArray;

//-- var, const, procedure ---------------------------------------------------
static const Shortint BitsPerNibble = 0x4;
static const Shortint BitsPerByte = 0x8;
static const Shortint BitsPerShortint = 0x8;
static const Shortint BitsPerSmallint = 0x10;
static const Shortint BitsPerWord = 0x10;
static const Shortint BitsPerInteger = 0x20;
static const Shortint BitsPerCardinal = 0x20;
static const Shortint BitsPerInt64 = 0x40;
static const Shortint NibblesPerByte = 0x2;
static const Shortint NibblesPerShortint = 0x2;
static const Shortint NibblesPerSmallint = 0x4;
static const Shortint NibblesPerWord = 0x4;
static const Shortint NibblesPerInteger = 0x8;
static const Shortint NibblesPerCardinal = 0x8;
static const Shortint NibblesPerInt64 = 0x10;
static const Shortint NibbleMask = 0xf;
static const Byte ByteMask = 0xff;
static const Shortint ShortintMask = -1;
static const short SmallintMask = -1;
static const Word WordMask = 0xffff;
static const int IntegerMask = -1;
static const unsigned CardinalMask = 0xffffffff;
static const __int64 Int64Mask = 0xffffffff;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE AnsiString __fastcall OrdToBinary(Byte Value)/* overload */;
extern PACKAGE AnsiString __fastcall OrdToBinary(Shortint Value)/* overload */;
extern PACKAGE AnsiString __fastcall OrdToBinary(short Value)/* overload */;
extern PACKAGE AnsiString __fastcall OrdToBinary(Word Value)/* overload */;
extern PACKAGE AnsiString __fastcall OrdToBinary(int Value)/* overload */;
extern PACKAGE AnsiString __fastcall OrdToBinary(unsigned Value)/* overload */;
extern PACKAGE AnsiString __fastcall OrdToBinary(__int64 Value)/* overload */;
extern PACKAGE int __fastcall BitsHighest(unsigned X)/* overload */;
extern PACKAGE int __fastcall BitsHighest(int X)/* overload */;
extern PACKAGE int __fastcall BitsHighest(Byte X)/* overload */;
extern PACKAGE int __fastcall BitsHighest(Word X)/* overload */;
extern PACKAGE int __fastcall BitsHighest(short X)/* overload */;
extern PACKAGE int __fastcall BitsHighest(Shortint X)/* overload */;
extern PACKAGE int __fastcall BitsHighest(__int64 X)/* overload */;
extern PACKAGE int __fastcall BitsLowest(unsigned X)/* overload */;
extern PACKAGE int __fastcall BitsLowest(int X)/* overload */;
extern PACKAGE int __fastcall BitsLowest(Byte X)/* overload */;
extern PACKAGE int __fastcall BitsLowest(Shortint X)/* overload */;
extern PACKAGE int __fastcall BitsLowest(short X)/* overload */;
extern PACKAGE int __fastcall BitsLowest(Word X)/* overload */;
extern PACKAGE int __fastcall BitsLowest(__int64 X)/* overload */;
extern PACKAGE Byte __fastcall ClearBit(const Byte Value, const Byte Bit)/* overload */;
extern PACKAGE Shortint __fastcall ClearBit(const Shortint Value, const Byte Bit)/* overload */;
extern PACKAGE short __fastcall ClearBit(const short Value, const Byte Bit)/* overload */;
extern PACKAGE Word __fastcall ClearBit(const Word Value, const Byte Bit)/* overload */;
extern PACKAGE unsigned __fastcall ClearBit(const unsigned Value, const Byte Bit)/* overload */;
extern PACKAGE int __fastcall ClearBit(const int Value, const Byte Bit)/* overload */;
extern PACKAGE __int64 __fastcall ClearBit(const __int64 Value, const Byte Bit)/* overload */;
extern PACKAGE void __fastcall ClearBitBuffer(void *Value, const unsigned Bit)/* overload */;
extern PACKAGE int __fastcall CountBitsSet(unsigned X)/* overload */;
extern PACKAGE int __fastcall CountBitsSet(Byte X)/* overload */;
extern PACKAGE int __fastcall CountBitsSet(Word X)/* overload */;
extern PACKAGE int __fastcall CountBitsSet(short X)/* overload */;
extern PACKAGE int __fastcall CountBitsSet(Shortint X)/* overload */;
extern PACKAGE int __fastcall CountBitsSet(int X)/* overload */;
extern PACKAGE unsigned __fastcall CountBitsSet(void * P, unsigned Count)/* overload */;
extern PACKAGE int __fastcall CountBitsSet(__int64 X)/* overload */;
extern PACKAGE int __fastcall CountBitsCleared(Byte X)/* overload */;
extern PACKAGE int __fastcall CountBitsCleared(Shortint X)/* overload */;
extern PACKAGE int __fastcall CountBitsCleared(short X)/* overload */;
extern PACKAGE int __fastcall CountBitsCleared(Word X)/* overload */;
extern PACKAGE int __fastcall CountBitsCleared(int X)/* overload */;
extern PACKAGE int __fastcall CountBitsCleared(unsigned X)/* overload */;
extern PACKAGE int __fastcall CountBitsCleared(__int64 X)/* overload */;
extern PACKAGE unsigned __fastcall CountBitsCleared(void * P, unsigned Count)/* overload */;
extern PACKAGE Byte __fastcall LRot(const Byte Value, const Byte Count)/* overload */;
extern PACKAGE Word __fastcall LRot(const Word Value, const Byte Count)/* overload */;
extern PACKAGE int __fastcall LRot(const int Value, const Byte Count)/* overload */;
extern PACKAGE Byte __fastcall ReverseBits(Byte Value)/* overload */;
extern PACKAGE Shortint __fastcall ReverseBits(Shortint Value)/* overload */;
extern PACKAGE short __fastcall ReverseBits(short Value)/* overload */;
extern PACKAGE Word __fastcall ReverseBits(Word Value)/* overload */;
extern PACKAGE int __fastcall ReverseBits(int Value)/* overload */;
extern PACKAGE unsigned __fastcall ReverseBits(unsigned Value)/* overload */;
extern PACKAGE __int64 __fastcall ReverseBits(__int64 Value)/* overload */;
extern PACKAGE void * __fastcall ReverseBits(void * P, int Count)/* overload */;
extern PACKAGE Byte __fastcall RRot(const Byte Value, const Byte Count)/* overload */;
extern PACKAGE Word __fastcall RRot(const Word Value, const Byte Count)/* overload */;
extern PACKAGE int __fastcall RRot(const int Value, const Byte Count)/* overload */;
extern PACKAGE Shortint __fastcall Sar(const Shortint Value, const Byte Count)/* overload */;
extern PACKAGE short __fastcall Sar(const short Value, const Byte Count)/* overload */;
extern PACKAGE int __fastcall Sar(const int Value, const Byte Count)/* overload */;
extern PACKAGE Byte __fastcall SetBit(const Byte Value, const Byte Bit)/* overload */;
extern PACKAGE Shortint __fastcall SetBit(const Shortint Value, const Byte Bit)/* overload */;
extern PACKAGE short __fastcall SetBit(const short Value, const Byte Bit)/* overload */;
extern PACKAGE Word __fastcall SetBit(const Word Value, const Byte Bit)/* overload */;
extern PACKAGE unsigned __fastcall SetBit(const unsigned Value, const Byte Bit)/* overload */;
extern PACKAGE int __fastcall SetBit(const int Value, const Byte Bit)/* overload */;
extern PACKAGE __int64 __fastcall SetBit(const __int64 Value, const Byte Bit)/* overload */;
extern PACKAGE void __fastcall SetBitBuffer(void *Value, const unsigned Bit)/* overload */;
extern PACKAGE bool __fastcall TestBit(const Byte Value, const Byte Bit)/* overload */;
extern PACKAGE bool __fastcall TestBit(const Shortint Value, const Byte Bit)/* overload */;
extern PACKAGE bool __fastcall TestBit(const short Value, const Byte Bit)/* overload */;
extern PACKAGE bool __fastcall TestBit(const Word Value, const Byte Bit)/* overload */;
extern PACKAGE bool __fastcall TestBit(const unsigned Value, const Byte Bit)/* overload */;
extern PACKAGE bool __fastcall TestBit(const int Value, const Byte Bit)/* overload */;
extern PACKAGE bool __fastcall TestBit(const __int64 Value, const Byte Bit)/* overload */;
extern PACKAGE bool __fastcall TestBitBuffer(const void *Value, const unsigned Bit)/* overload */;
extern PACKAGE bool __fastcall TestBits(const Byte Value, const Byte Mask)/* overload */;
extern PACKAGE bool __fastcall TestBits(const Shortint Value, const Shortint Mask)/* overload */;
extern PACKAGE bool __fastcall TestBits(const short Value, const short Mask)/* overload */;
extern PACKAGE bool __fastcall TestBits(const Word Value, const Word Mask)/* overload */;
extern PACKAGE bool __fastcall TestBits(const unsigned Value, const unsigned Mask)/* overload */;
extern PACKAGE bool __fastcall TestBits(const int Value, const int Mask)/* overload */;
extern PACKAGE bool __fastcall TestBits(const __int64 Value, const __int64 Mask)/* overload */;
extern PACKAGE Byte __fastcall ToggleBit(const Byte Value, const Byte Bit)/* overload */;
extern PACKAGE Shortint __fastcall ToggleBit(const Shortint Value, const Byte Bit)/* overload */;
extern PACKAGE short __fastcall ToggleBit(const short Value, const Byte Bit)/* overload */;
extern PACKAGE Word __fastcall ToggleBit(const Word Value, const Byte Bit)/* overload */;
extern PACKAGE unsigned __fastcall ToggleBit(const unsigned Value, const Byte Bit)/* overload */;
extern PACKAGE int __fastcall ToggleBit(const int Value, const Byte Bit)/* overload */;
extern PACKAGE __int64 __fastcall ToggleBit(const __int64 Value, const Byte Bit)/* overload */;
extern PACKAGE void __fastcall ToggleBitBuffer(void *Value, const unsigned Bit)/* overload */;
extern PACKAGE void __fastcall BooleansToBits(Byte &Dest, const TBooleanArray B)/* overload */;
extern PACKAGE void __fastcall BooleansToBits(Word &Dest, const TBooleanArray B)/* overload */;
extern PACKAGE void __fastcall BooleansToBits(int &Dest, const TBooleanArray B)/* overload */;
extern PACKAGE void __fastcall BooleansToBits(__int64 &Dest, const TBooleanArray B)/* overload */;
extern PACKAGE void __fastcall BitsToBooleans(const Byte Bits, TBooleanArray &B, bool AllBits = false)/* overload */;
extern PACKAGE void __fastcall BitsToBooleans(const Word Bits, TBooleanArray &B, bool AllBits = false)/* overload */;
extern PACKAGE void __fastcall BitsToBooleans(const int Bits, TBooleanArray &B, bool AllBits = false)/* overload */;
extern PACKAGE void __fastcall BitsToBooleans(const __int64 Bits, TBooleanArray &B, bool AllBits = false)/* overload */;
extern PACKAGE int __fastcall Digits(const unsigned X);
extern PACKAGE int __fastcall BitsNeeded(const Byte X)/* overload */;
extern PACKAGE int __fastcall BitsNeeded(const Word X)/* overload */;
extern PACKAGE int __fastcall BitsNeeded(const int X)/* overload */;
extern PACKAGE int __fastcall BitsNeeded(const __int64 X)/* overload */;
extern PACKAGE Word __fastcall ReverseBytes(Word Value)/* overload */;
extern PACKAGE short __fastcall ReverseBytes(short Value)/* overload */;
extern PACKAGE int __fastcall ReverseBytes(int Value)/* overload */;
extern PACKAGE unsigned __fastcall ReverseBytes(unsigned Value)/* overload */;
extern PACKAGE __int64 __fastcall ReverseBytes(__int64 Value)/* overload */;
extern PACKAGE void * __fastcall ReverseBytes(void * P, int Count)/* overload */;
extern PACKAGE void __fastcall SwapOrd(Byte &I, Byte &J)/* overload */;
extern PACKAGE void __fastcall SwapOrd(unsigned &I, unsigned &J)/* overload */;
extern PACKAGE void __fastcall SwapOrd(int &I, int &J)/* overload */;
extern PACKAGE void __fastcall SwapOrd(__int64 &I, __int64 &J)/* overload */;
extern PACKAGE void __fastcall SwapOrd(Shortint &I, Shortint &J)/* overload */;
extern PACKAGE void __fastcall SwapOrd(short &I, short &J)/* overload */;
extern PACKAGE void __fastcall SwapOrd(Word &I, Word &J)/* overload */;
extern PACKAGE Byte __fastcall IncLimit(Byte &B, const Byte Limit, const Byte Incr = (Byte)(0x1))/* overload */;
extern PACKAGE Shortint __fastcall IncLimit(Shortint &B, const Shortint Limit, const Shortint Incr = (Shortint)(0x1))/* overload */;
extern PACKAGE short __fastcall IncLimit(short &B, const short Limit, const short Incr = (short)(0x1))/* overload */;
extern PACKAGE Word __fastcall IncLimit(Word &B, const Word Limit, const Word Incr = (Word)(0x1))/* overload */;
extern PACKAGE int __fastcall IncLimit(int &B, const int Limit, const int Incr = 0x1)/* overload */;
extern PACKAGE unsigned __fastcall IncLimit(unsigned &B, const unsigned Limit, const unsigned Incr = (unsigned)(0x1))/* overload */;
extern PACKAGE __int64 __fastcall IncLimit(__int64 &B, const __int64 Limit, const __int64 Incr = 0x000000001)/* overload */;
extern PACKAGE Byte __fastcall DecLimit(Byte &B, const Byte Limit, const Byte Decr = (Byte)(0x1))/* overload */;
extern PACKAGE Shortint __fastcall DecLimit(Shortint &B, const Shortint Limit, const Shortint Decr = (Shortint)(0x1))/* overload */;
extern PACKAGE short __fastcall DecLimit(short &B, const short Limit, const short Decr = (short)(0x1))/* overload */;
extern PACKAGE Word __fastcall DecLimit(Word &B, const Word Limit, const Word Decr = (Word)(0x1))/* overload */;
extern PACKAGE int __fastcall DecLimit(int &B, const int Limit, const int Decr = 0x1)/* overload */;
extern PACKAGE unsigned __fastcall DecLimit(unsigned &B, const unsigned Limit, const unsigned Decr = (unsigned)(0x1))/* overload */;
extern PACKAGE __int64 __fastcall DecLimit(__int64 &B, const __int64 Limit, const __int64 Decr = 0x000000001)/* overload */;
extern PACKAGE Byte __fastcall IncLimitClamp(Byte &B, const Byte Limit, const Byte Incr = (Byte)(0x1))/* overload */;
extern PACKAGE Shortint __fastcall IncLimitClamp(Shortint &B, const Shortint Limit, const Shortint Incr = (Shortint)(0x1))/* overload */;
extern PACKAGE short __fastcall IncLimitClamp(short &B, const short Limit, const short Incr = (short)(0x1))/* overload */;
extern PACKAGE Word __fastcall IncLimitClamp(Word &B, const Word Limit, const Word Incr = (Word)(0x1))/* overload */;
extern PACKAGE int __fastcall IncLimitClamp(int &B, const int Limit, const int Incr = 0x1)/* overload */;
extern PACKAGE unsigned __fastcall IncLimitClamp(unsigned &B, const unsigned Limit, const unsigned Incr = (unsigned)(0x1))/* overload */;
extern PACKAGE __int64 __fastcall IncLimitClamp(__int64 &B, const __int64 Limit, const __int64 Incr = 0x000000001)/* overload */;
extern PACKAGE Byte __fastcall DecLimitClamp(Byte &B, const Byte Limit, const Byte Decr = (Byte)(0x1))/* overload */;
extern PACKAGE Shortint __fastcall DecLimitClamp(Shortint &B, const Shortint Limit, const Shortint Decr = (Shortint)(0x1))/* overload */;
extern PACKAGE short __fastcall DecLimitClamp(short &B, const short Limit, const short Decr = (short)(0x1))/* overload */;
extern PACKAGE Word __fastcall DecLimitClamp(Word &B, const Word Limit, const Word Decr = (Word)(0x1))/* overload */;
extern PACKAGE int __fastcall DecLimitClamp(int &B, const int Limit, const int Decr = 0x1)/* overload */;
extern PACKAGE unsigned __fastcall DecLimitClamp(unsigned &B, const unsigned Limit, const unsigned Decr = (unsigned)(0x1))/* overload */;
extern PACKAGE __int64 __fastcall DecLimitClamp(__int64 &B, const __int64 Limit, const __int64 Decr = 0x000000001)/* overload */;
extern PACKAGE Byte __fastcall Max(const Byte B1, const Byte B2)/* overload */;
extern PACKAGE Byte __fastcall Min(const Byte B1, const Byte B2)/* overload */;
extern PACKAGE Shortint __fastcall Max(const Shortint B1, const Shortint B2)/* overload */;
extern PACKAGE short __fastcall Max(const short B1, const short B2)/* overload */;
extern PACKAGE Shortint __fastcall Min(const Shortint B1, const Shortint B2)/* overload */;
extern PACKAGE short __fastcall Min(const short B1, const short B2)/* overload */;
extern PACKAGE Word __fastcall Max(const Word B1, const Word B2)/* overload */;
extern PACKAGE __int64 __fastcall Max(const __int64 B1, const __int64 B2)/* overload */;
extern PACKAGE Word __fastcall Min(const Word B1, const Word B2)/* overload */;
extern PACKAGE int __fastcall Max(const int B1, const int B2)/* overload */;
extern PACKAGE int __fastcall Min(const int B1, const int B2)/* overload */;
extern PACKAGE unsigned __fastcall Max(const unsigned B1, const unsigned B2)/* overload */;
extern PACKAGE unsigned __fastcall Min(const unsigned B1, const unsigned B2)/* overload */;
extern PACKAGE __int64 __fastcall Min(const __int64 B1, const __int64 B2)/* overload */;

}	/* namespace Jcllogic */
using namespace Jcllogic;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jcllogic
