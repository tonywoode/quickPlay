// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclcil.pas' rev: 10.00

#ifndef JclcilHPP
#define JclcilHPP

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
#include <Jclsysutils.hpp>	// Pascal unit
#include <Jclmetadata.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclcil
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TJclOpCode { opNop, opBreak, opLdArg_0, opLdArg_1, opLdArg_2, opLdArg_3, opLdLoc_0, opLdLoc_1, opLdLoc_2, opLdLoc_3, opStLoc_0, opStLoc_1, opStLoc_2, opStLoc_3, opldArg_s, opLdArga_s, opStArg_s, opLdLoc_s, opLdLoca_s, opStLoc_s, opLdNull, opLdc_I4_M1, opLdc_I4_0, opLdc_I4_1, opLdc_I4_2, opLdc_I4_3, opLdc_I4_4, opLdc_I4_5, opLdc_I4_6, opLdc_I4_7, opLdc_I4_8, opLdc_I4_s, opLdc_i4, opLdc_i8, opLdc_r4, opLdc_r8, opUnused49, opDup, opPop, opJmp, opCall, opCalli, opRet, opBr_s, opBrFalse_s, opBrTrue_s, opBeq_s, opBge_s, opBgt_s, opBle_s, opBlt_s, opBne_un_s, opBge_un_s, opBgt_un_s, opBle_un_s, opBlt_un_s, opBr, opBrFalse, opBrTrue, opBeq, opBge, opBgt, opBle, opBlt, opBne_un, opBge_un, opBgt_un, opBle_un, opBlt_un, opSwitch, opLdInd_i1, opLdInd_i2, opLdInd_u1, opLdInd_u2, opLdInd_i4, opLdInd_u4, opLdInd_i8, opLdInd_i, opLdInd_r4, opLdInd_r8, opLdInd_ref, opStInd_ref, opStInd_i1, opStInd_i2, opStInd_i4, opStInd_i8, opStInd_r4, opStInd_r8, opAdd, opSub, opMul, opDiv, opDiv_un, opRem, opRem_un, opAnd, opOr
	, opXor, opShl, opShr, opShr_un, opNeg, opNot, opConv_i1, opConv_i2, opConv_i4, opConv_i8, opConv_r4, opConv_r8, opConv_u4, opConv_u8, opCallVirt, opCpObj, opLdObj, opLdStr, opNewObj, opCastClass, opIsInst, opConv_r_un, opUnused58, opUnused1, opUnbox, opThrow, opLdFld, opLdFlda, opStFld, opLdsFld, opLdsFlda, opStsFld, opStObj, opConv_ovf_i1_un, opConv_ovf_i2_un, opConv_ovf_i4_un, opConv_ovf_i8_un, opConv_ovf_u1_un, opConv_ovf_u2_un, opConv_ovf_u4_un, opConv_ovf_u8_un, opConv_ovf_i_un, opConv_ovf_u_un, opBox, opNewArr, opLdLen, opLdElema, opLdElem_i1, opLdElem_u1, opLdElem_i2, opLdElem_u2, opLdElem_i4, opLdElem_u4, opLdElem_i8, opLdElem_i, opLdElem_r4, opLdElem_r8, opLdElem_ref, opStElem_i, opStElem_i1, opStElem_i2, opStElem_i4, opStElem_i8, opStElem_r4, opStElem_r8, opStElem_ref, opUnused2, opUnused3, opUnused4, opUnused5, opUnused6, opUnused7, opUnused8, opUnused9, opUnused10, opUnused11, opUnused12, opUnused13, opUnused14, opUnused15, opUnused16, opUnused17, opConv_ovf_i1, opConv_ovf_u1, opConv_ovf_i2
	, opConv_ovf_u2, opConv_ovf_i4, opConv_ovf_u4, opConv_ovf_i8, opConv_ovf_u8, opUnused50, opUnused18, opUnused19, opUnused20, opUnused21, opUnused22, opUnused23, opRefAnyVal, opCkFinite, opUnused24, opUnused25, opMkRefAny, opUnused59, opUnused60, opUnused61, opUnused62, opUnused63, opUnused64, opUnused65, opUnused66, opUnused67, opLdToken, opConv_u2, opConv_u1, opConv_i, opConv_ovf_i, opConv_ovf_u, opAdd_ovf, opAdd_ovf_un, opMul_ovf, opMul_ovf_un, opSub_ovf, opSub_ovf_un, opEndFinally, opLeave, opLeave_s, opStInd_i, opConv_u, opUnused26, opUnused27, opUnused28, opUnused29, opUnused30, opUnused31, opUnused32, opUnused33, opUnused34, opUnused35, opUnused36, opUnused37, opUnused38, opUnused39, opUnused40, opUnused41, opUnused42, opUnused43, opUnused44, opUnused45, opUnused46, opUnused47, opUnused48, opPrefix7, opPrefix6, opPrefix5, opPrefix4, opPrefix3, opPrefix2, opPrefix1, opPrefixRef, opArgLlist, opCeq, opCgt, opCgt_un, opClt, opClt_un, opLdFtn, opLdVirtFtn, optUnused56, opLdArg, opLdArga, opStArg, opLdLoc, opLdLoca
	, opStLoc, opLocalLoc, opUnused57, opEndFilter, opUnaligned, opVolatile, opTail, opInitObj, opUnused68, opCpBlk, opInitBlk, opUnused69, opRethrow, opUnused51, opSizeOf, opRefAnyType, opUnused52, opUnused53, opUnused54, opUnused55, opUnused70 };
#pragma option pop

#pragma option push -b-
enum TJclInstructionDumpILOption { doLineNo, doRawBytes, doIL, doTokenValue, doComment };
#pragma option pop

typedef Set<TJclInstructionDumpILOption, doLineNo, doComment>  TJclInstructionDumpILOptions;

#pragma option push -b-
enum TJclInstructionParamType { ptVoid, ptI1, ptI2, ptI4, ptI8, ptU1, ptU2, ptU4, ptU8, ptR4, ptR8, ptToken, ptSOff, ptLOff, ptArray };
#pragma option pop

class DELPHICLASS TJclInstruction;
class DELPHICLASS TJclClrILGenerator;
class PASCALIMPLEMENTATION TJclClrILGenerator : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Jclmetadata::TJclClrMethodBody* FMethod;
	Contnrs::TObjectList* FInstructions;
	int __fastcall GetInstructionCount(void);
	TJclInstruction* __fastcall GetInstruction(const int Idx);
	
public:
	__fastcall TJclClrILGenerator(Jclmetadata::TJclClrMethodBody* AMethod);
	__fastcall virtual ~TJclClrILGenerator(void);
	AnsiString __fastcall DumpIL(TJclInstructionDumpILOptions Options);
	__property Jclmetadata::TJclClrMethodBody* Method = {read=FMethod};
	__property TJclInstruction* Instructions[int Idx] = {read=GetInstruction};
	__property int InstructionCount = {read=GetInstructionCount, nodefault};
};


class PASCALIMPLEMENTATION TJclInstruction : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TJclOpCode FOpCode;
	unsigned FOffset;
	Variant FParam;
	TJclClrILGenerator* FOwner;
	bool __fastcall GetWideOpCode(void);
	Byte __fastcall GetRealOpCode(void);
	AnsiString __fastcall GetName();
	AnsiString __fastcall GetFullName();
	AnsiString __fastcall GetDescription();
	TJclInstructionParamType __fastcall GetParamType(void);
	AnsiString __fastcall FormatLabel(int Offset);
	
protected:
	virtual unsigned __fastcall GetSize(void);
	virtual AnsiString __fastcall DumpILOption(TJclInstructionDumpILOption Option);
	
public:
	__fastcall TJclInstruction(TJclClrILGenerator* AOwner, TJclOpCode AOpCode);
	virtual void __fastcall Load(Classes::TStream* Stream);
	virtual void __fastcall Save(Classes::TStream* Stream);
	AnsiString __fastcall DumpIL(TJclInstructionDumpILOptions Options = (Set<TJclInstructionDumpILOption, doLineNo, doComment> () << TJclInstructionDumpILOption(2) ));
	__property TJclClrILGenerator* Owner = {read=FOwner};
	__property TJclOpCode OpCode = {read=FOpCode, nodefault};
	__property bool WideOpCode = {read=GetWideOpCode, nodefault};
	__property Byte RealOpCode = {read=GetRealOpCode, nodefault};
	__property Variant Param = {read=FParam, write=FParam};
	__property TJclInstructionParamType ParamType = {read=GetParamType, nodefault};
	__property AnsiString Name = {read=GetName};
	__property AnsiString FullName = {read=GetFullName};
	__property AnsiString Description = {read=GetDescription};
	__property unsigned Size = {read=GetSize, nodefault};
	__property unsigned Offset = {read=FOffset, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclInstruction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclUnaryInstruction;
class PASCALIMPLEMENTATION TJclUnaryInstruction : public TJclInstruction 
{
	typedef TJclInstruction inherited;
	
public:
	#pragma option push -w-inl
	/* TJclInstruction.Create */ inline __fastcall TJclUnaryInstruction(TJclClrILGenerator* AOwner, TJclOpCode AOpCode) : TJclInstruction(AOwner, AOpCode) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclUnaryInstruction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TJclBinaryInstruction;
class PASCALIMPLEMENTATION TJclBinaryInstruction : public TJclInstruction 
{
	typedef TJclInstruction inherited;
	
public:
	#pragma option push -w-inl
	/* TJclInstruction.Create */ inline __fastcall TJclBinaryInstruction(TJclClrILGenerator* AOwner, TJclOpCode AOpCode) : TJclInstruction(AOwner, AOpCode) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TJclBinaryInstruction(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclCliInstructionError;
class PASCALIMPLEMENTATION EJclCliInstructionError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclCliInstructionError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclCliInstructionError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclCliInstructionError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclCliInstructionError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclCliInstructionError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclCliInstructionError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclCliInstructionError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclCliInstructionError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclCliInstructionError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EJclCliInstructionStreamInvalid;
class PASCALIMPLEMENTATION EJclCliInstructionStreamInvalid : public EJclCliInstructionError 
{
	typedef EJclCliInstructionError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclCliInstructionStreamInvalid(const AnsiString Msg) : EJclCliInstructionError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclCliInstructionStreamInvalid(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : EJclCliInstructionError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclCliInstructionStreamInvalid(int Ident)/* overload */ : EJclCliInstructionError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclCliInstructionStreamInvalid(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : EJclCliInstructionError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclCliInstructionStreamInvalid(const AnsiString Msg, int AHelpContext) : EJclCliInstructionError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclCliInstructionStreamInvalid(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : EJclCliInstructionError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclCliInstructionStreamInvalid(int Ident, int AHelpContext)/* overload */ : EJclCliInstructionError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclCliInstructionStreamInvalid(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : EJclCliInstructionError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclCliInstructionStreamInvalid(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define InstructionDumpILAllOption (Set<TJclInstructionDumpILOption, doLineNo, doComment> () << TJclInstructionDumpILOption(0) << TJclInstructionDumpILOption(1) << TJclInstructionDumpILOption(2) << TJclInstructionDumpILOption(3) << TJclInstructionDumpILOption(4) )
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;

}	/* namespace Jclcil */
using namespace Jclcil;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclcil
