// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Jclmidi.pas' rev: 10.00

#ifndef JclmidiHPP
#define JclmidiHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Jclunitversioning.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Jclbase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Jclmidi
{
//-- type declarations -------------------------------------------------------
typedef Shortint TMIDIChannel;

typedef Shortint TMIDIDataByte;

typedef Word TMIDIDataWord;

typedef Byte TMIDIStatusByte;

typedef TMIDIDataByte TMIDIVelocity;

typedef TMIDIDataByte TMIDIKey;

typedef TMIDIDataByte TMIDINote;

typedef Set<TMIDIDataByte, 0, 127>  TMIDINotes;

#pragma pack(push,1)
struct TSingleNoteTuningData
{
	
	union
	{
		struct 
		{
			unsigned DWord;
			
		};
		struct 
		{
			TMIDIDataByte Key;
			TMIDIDataByte Frequency[3];
			
		};
		
	};
} ;
#pragma pack(pop)

class DELPHICLASS EJclMIDIError;
class PASCALIMPLEMENTATION EJclMIDIError : public Jclbase::EJclError 
{
	typedef Jclbase::EJclError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EJclMIDIError(const AnsiString Msg) : Jclbase::EJclError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EJclMIDIError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size) : Jclbase::EJclError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EJclMIDIError(int Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EJclMIDIError(int Ident, System::TVarRec const * Args, const int Args_Size)/* overload */ : Jclbase::EJclError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EJclMIDIError(const AnsiString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EJclMIDIError(const AnsiString Msg, System::TVarRec const * Args, const int Args_Size, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EJclMIDIError(int Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclMIDIError(System::PResStringRec ResStringRec, System::TVarRec const * Args, const int Args_Size, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EJclMIDIError(void) { }
	#pragma option pop
	
};


__interface IJclMIDIOut;
typedef System::DelphiInterface<IJclMIDIOut> _di_IJclMIDIOut;
__interface  INTERFACE_UUID("{A29C3EBD-EB70-4C72-BEC5-700AF57FD4C8}") IJclMIDIOut  : public IInterface 
{
	
public:
	virtual TMIDINotes __fastcall GetActiveNotes(TMIDIChannel Channel) = 0 ;
	virtual AnsiString __fastcall GetName(void) = 0 ;
	virtual TMIDIStatusByte __fastcall GetMIDIStatus(void) = 0 ;
	virtual bool __fastcall GetRunningStatusEnabled(void) = 0 ;
	virtual void __fastcall SetRunningStatusEnabled(const bool Value) = 0 ;
	virtual void __fastcall SendMessage(Byte const * Data, const int Data_Size) = 0 ;
	virtual void __fastcall SendNoteOff(TMIDIChannel Channel, TMIDIDataByte Key, TMIDIDataByte Velocity = (TMIDIDataByte)(0x40)) = 0 ;
	virtual void __fastcall SendNoteOn(TMIDIChannel Channel, TMIDIDataByte Key, TMIDIDataByte Velocity) = 0 ;
	virtual void __fastcall SendPolyphonicKeyPressure(TMIDIChannel Channel, TMIDIDataByte Key, TMIDIDataByte Value) = 0 ;
	virtual void __fastcall SendControlChange(TMIDIChannel Channel, TMIDIDataByte ControllerNum, TMIDIDataByte Value) = 0 ;
	virtual void __fastcall SendControlChangeHR(TMIDIChannel Channel, TMIDIDataByte ControllerNum, TMIDIDataWord Value) = 0 ;
	virtual void __fastcall SendSwitchChange(TMIDIChannel Channel, TMIDIDataByte ControllerNum, bool Value) = 0 ;
	virtual void __fastcall SendProgramChange(TMIDIChannel Channel, TMIDIDataByte ProgramNum) = 0 ;
	virtual void __fastcall SendChannelPressure(TMIDIChannel Channel, TMIDIDataByte Value) = 0 ;
	virtual void __fastcall SendPitchWheelChange(TMIDIChannel Channel, TMIDIDataWord Value) = 0 ;
	virtual void __fastcall SendPitchWheelPos(TMIDIChannel Channel, float Value) = 0 ;
	virtual void __fastcall SelectProgram(TMIDIChannel Channel, TMIDIDataWord BankNum, TMIDIDataByte ProgramNum) = 0 ;
	virtual void __fastcall SendModulationWheelChange(TMIDIChannel Channel, TMIDIDataByte Value) = 0 ;
	virtual void __fastcall SendBreathControlChange(TMIDIChannel Channel, TMIDIDataByte Value) = 0 ;
	virtual void __fastcall SendFootControllerChange(TMIDIChannel Channel, TMIDIDataByte Value) = 0 ;
	virtual void __fastcall SendPortamentoTimeChange(TMIDIChannel Channel, TMIDIDataByte Value) = 0 ;
	virtual void __fastcall SendDataEntry(TMIDIChannel Channel, TMIDIDataByte Value) = 0 ;
	virtual void __fastcall SendChannelVolumeChange(TMIDIChannel Channel, TMIDIDataByte Value) = 0 ;
	virtual void __fastcall SendBalanceChange(TMIDIChannel Channel, TMIDIDataByte Value) = 0 ;
	virtual void __fastcall SendPanChange(TMIDIChannel Channel, TMIDIDataByte Value) = 0 ;
	virtual void __fastcall SendExpressionChange(TMIDIChannel Channel, TMIDIDataByte Value) = 0 ;
	virtual void __fastcall SendModulationWheelChangeHR(TMIDIChannel Channel, TMIDIDataWord Value) = 0 ;
	virtual void __fastcall SendBreathControlChangeHR(TMIDIChannel Channel, TMIDIDataWord Value) = 0 ;
	virtual void __fastcall SendFootControllerChangeHR(TMIDIChannel Channel, TMIDIDataWord Value) = 0 ;
	virtual void __fastcall SendPortamentoTimeChangeHR(TMIDIChannel Channel, TMIDIDataWord Value) = 0 ;
	virtual void __fastcall SendDataEntryHR(TMIDIChannel Channel, TMIDIDataWord Value) = 0 ;
	virtual void __fastcall SendChannelVolumeChangeHR(TMIDIChannel Channel, TMIDIDataWord Value) = 0 ;
	virtual void __fastcall SendBalanceChangeHR(TMIDIChannel Channel, TMIDIDataWord Value) = 0 ;
	virtual void __fastcall SendPanChangeHR(TMIDIChannel Channel, TMIDIDataWord Value) = 0 ;
	virtual void __fastcall SendExpressionChangeHR(TMIDIChannel Channel, TMIDIDataWord Value) = 0 ;
	virtual void __fastcall SwitchSustain(TMIDIChannel Channel, bool Value) = 0 ;
	virtual void __fastcall SwitchPortamento(TMIDIChannel Channel, bool Value) = 0 ;
	virtual void __fastcall SwitchSostenuto(TMIDIChannel Channel, bool Value) = 0 ;
	virtual void __fastcall SwitchSoftPedal(TMIDIChannel Channel, bool Value) = 0 ;
	virtual void __fastcall SwitchLegato(TMIDIChannel Channel, bool Value) = 0 ;
	virtual void __fastcall SwitchHold2(TMIDIChannel Channel, bool Value) = 0 ;
	virtual void __fastcall SwitchAllSoundOff(TMIDIChannel Channel) = 0 ;
	virtual void __fastcall ResetAllControllers(TMIDIChannel Channel) = 0 ;
	virtual void __fastcall SwitchLocalControl(TMIDIChannel Channel, bool Value) = 0 ;
	virtual void __fastcall SwitchAllNotesOff(TMIDIChannel Channel) = 0 ;
	virtual void __fastcall SwitchOmniModeOff(TMIDIChannel Channel) = 0 ;
	virtual void __fastcall SwitchOmniModeOn(TMIDIChannel Channel) = 0 ;
	virtual void __fastcall SwitchMonoModeOn(TMIDIChannel Channel, int ChannelCount) = 0 ;
	virtual void __fastcall SwitchPolyModeOn(TMIDIChannel Channel) = 0 ;
	virtual void __fastcall SendSingleNoteTuningChange(const TMIDIDataByte TargetDeviceID, const TMIDIDataByte TuningProgramNum, TSingleNoteTuningData const * TuningData, const int TuningData_Size) = 0 ;
	virtual bool __fastcall NoteIsOn(TMIDIChannel Channel, TMIDIDataByte Key) = 0 ;
	virtual void __fastcall SwitchActiveNotesOff(TMIDIChannel Channel) = 0 /* overload */;
	virtual void __fastcall SwitchActiveNotesOff(void) = 0 /* overload */;
	__property TMIDINotes ActiveNotes[TMIDIChannel Channel] = {read=GetActiveNotes};
	__property AnsiString Name = {read=GetName};
	__property bool LocalControl[TMIDIChannel Channel] = {write=SwitchLocalControl};
	__property TMIDIStatusByte MIDIStatus = {read=GetMIDIStatus};
	__property bool RunningStatusEnabled = {read=GetRunningStatusEnabled, write=SetRunningStatusEnabled};
};

class DELPHICLASS TJclMIDIOut;
class PASCALIMPLEMENTATION TJclMIDIOut : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	TMIDIStatusByte FMIDIStatus;
	bool FRunningStatusEnabled;
	TMIDINotes FActiveNotes[16];
	
protected:
	bool __fastcall IsRunningStatus(TMIDIStatusByte StatusByte);
	void __fastcall SendChannelMessage(TMIDIStatusByte Msg, TMIDIChannel Channel, TMIDIDataByte Data1, TMIDIDataByte Data2);
	virtual void __fastcall DoSendMessage(Byte const * Data, const int Data_Size) = 0 ;
	
public:
	__fastcall virtual ~TJclMIDIOut(void);
	TMIDINotes __fastcall GetActiveNotes(TMIDIChannel Channel);
	virtual AnsiString __fastcall GetName(void) = 0 ;
	TMIDIStatusByte __fastcall GetMIDIStatus(void);
	bool __fastcall GetRunningStatusEnabled(void);
	void __fastcall SetRunningStatusEnabled(const bool Value);
	void __fastcall SendMessage(Byte const * Data, const int Data_Size);
	void __fastcall SendNoteOff(TMIDIChannel Channel, TMIDIDataByte Key, TMIDIDataByte Velocity = (TMIDIDataByte)(0x40));
	void __fastcall SendNoteOn(TMIDIChannel Channel, TMIDIDataByte Key, TMIDIDataByte Velocity);
	void __fastcall SendPolyphonicKeyPressure(TMIDIChannel Channel, TMIDIDataByte Key, TMIDIDataByte Value);
	void __fastcall SendControlChange(TMIDIChannel Channel, TMIDIDataByte ControllerNum, TMIDIDataByte Value);
	void __fastcall SendControlChangeHR(TMIDIChannel Channel, TMIDIDataByte ControllerNum, TMIDIDataWord Value);
	void __fastcall SendSwitchChange(TMIDIChannel Channel, TMIDIDataByte ControllerNum, bool Value);
	void __fastcall SendProgramChange(TMIDIChannel Channel, TMIDIDataByte ProgramNum);
	void __fastcall SendChannelPressure(TMIDIChannel Channel, TMIDIDataByte Value);
	void __fastcall SendPitchWheelChange(TMIDIChannel Channel, TMIDIDataWord Value);
	void __fastcall SendPitchWheelPos(TMIDIChannel Channel, float Value);
	void __fastcall SelectProgram(TMIDIChannel Channel, TMIDIDataWord BankNum, TMIDIDataByte ProgramNum);
	void __fastcall SendModulationWheelChange(TMIDIChannel Channel, TMIDIDataByte Value);
	void __fastcall SendBreathControlChange(TMIDIChannel Channel, TMIDIDataByte Value);
	void __fastcall SendFootControllerChange(TMIDIChannel Channel, TMIDIDataByte Value);
	void __fastcall SendPortamentoTimeChange(TMIDIChannel Channel, TMIDIDataByte Value);
	void __fastcall SendDataEntry(TMIDIChannel Channel, TMIDIDataByte Value);
	void __fastcall SendChannelVolumeChange(TMIDIChannel Channel, TMIDIDataByte Value);
	void __fastcall SendBalanceChange(TMIDIChannel Channel, TMIDIDataByte Value);
	void __fastcall SendPanChange(TMIDIChannel Channel, TMIDIDataByte Value);
	void __fastcall SendExpressionChange(TMIDIChannel Channel, TMIDIDataByte Value);
	void __fastcall SendModulationWheelChangeHR(TMIDIChannel Channel, TMIDIDataWord Value);
	void __fastcall SendBreathControlChangeHR(TMIDIChannel Channel, TMIDIDataWord Value);
	void __fastcall SendFootControllerChangeHR(TMIDIChannel Channel, TMIDIDataWord Value);
	void __fastcall SendPortamentoTimeChangeHR(TMIDIChannel Channel, TMIDIDataWord Value);
	void __fastcall SendDataEntryHR(TMIDIChannel Channel, TMIDIDataWord Value);
	void __fastcall SendChannelVolumeChangeHR(TMIDIChannel Channel, TMIDIDataWord Value);
	void __fastcall SendBalanceChangeHR(TMIDIChannel Channel, TMIDIDataWord Value);
	void __fastcall SendPanChangeHR(TMIDIChannel Channel, TMIDIDataWord Value);
	void __fastcall SendExpressionChangeHR(TMIDIChannel Channel, TMIDIDataWord Value);
	void __fastcall SwitchSustain(TMIDIChannel Channel, bool Value);
	void __fastcall SwitchPortamento(TMIDIChannel Channel, bool Value);
	void __fastcall SwitchSostenuto(TMIDIChannel Channel, bool Value);
	void __fastcall SwitchSoftPedal(TMIDIChannel Channel, bool Value);
	void __fastcall SwitchLegato(TMIDIChannel Channel, bool Value);
	void __fastcall SwitchHold2(TMIDIChannel Channel, bool Value);
	void __fastcall SwitchAllSoundOff(TMIDIChannel Channel);
	void __fastcall ResetAllControllers(TMIDIChannel Channel);
	void __fastcall SwitchLocalControl(TMIDIChannel Channel, bool Value);
	void __fastcall SwitchAllNotesOff(TMIDIChannel Channel);
	void __fastcall SwitchOmniModeOff(TMIDIChannel Channel);
	void __fastcall SwitchOmniModeOn(TMIDIChannel Channel);
	void __fastcall SwitchMonoModeOn(TMIDIChannel Channel, int ChannelCount);
	void __fastcall SwitchPolyModeOn(TMIDIChannel Channel);
	void __fastcall SendSingleNoteTuningChange(const TMIDIDataByte TargetDeviceID, const TMIDIDataByte TuningProgramNum, TSingleNoteTuningData const * TuningData, const int TuningData_Size);
	bool __fastcall NoteIsOn(TMIDIChannel Channel, TMIDIDataByte Key);
	void __fastcall SwitchActiveNotesOff(TMIDIChannel Channel)/* overload */;
	void __fastcall SwitchActiveNotesOff(void)/* overload */;
	__property TMIDINotes ActiveNotes[TMIDIChannel Channel] = {read=GetActiveNotes};
	__property AnsiString Name = {read=GetName};
	__property bool RunningStatusEnabled = {read=GetRunningStatusEnabled, write=SetRunningStatusEnabled, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJclMIDIOut(void) : System::TInterfacedObject() { }
	#pragma option pop
	
private:
	void *__IJclMIDIOut;	/* Jclmidi::IJclMIDIOut */
	
public:
	operator IJclMIDIOut*(void) { return (IJclMIDIOut*)&__IJclMIDIOut; }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Byte MIDIMsgNoteOff = 0x80;
static const Byte MIDIMsgNoteOn = 0x90;
static const Byte MIDIMsgPolyKeyPressure = 0xa0;
static const Byte MIDIMsgControlChange = 0xb0;
static const Byte MIDIMsgProgramChange = 0xc0;
static const Byte MIDIMsgChannelKeyPressure = 0xd0;
static const Byte MIDIMsgAftertouch = 0xd0;
static const Byte MIDIMsgPitchWheelChange = 0xe0;
static const Byte MIDIMsgSysEx = 0xf0;
static const Byte MIDIMsgMTCQtrFrame = 0xf1;
static const Byte MIDIMsgSongPositionPtr = 0xf2;
static const Byte MIDIMsgSongSelect = 0xf3;
static const Byte MIDIMsgTuneRequest = 0xf6;
static const Byte MIDIMsgEOX = 0xf7;
static const Byte MIDIMsgTimingClock = 0xf8;
static const Byte MIDIMsgStartSequence = 0xfa;
static const Byte MIDIMsgContinueSequence = 0xfb;
static const Byte MIDIMsgStopSequence = 0xfc;
static const Byte MIDIMsgActiveSensing = 0xfe;
static const Byte MIDIMsgSystemReset = 0xff;
static const Shortint MIDICCBankSelect = 0x0;
static const Shortint MIDICCModulationWheel = 0x1;
static const Shortint MIDICCBreathControl = 0x2;
static const Shortint MIDICCFootController = 0x4;
static const Shortint MIDICCPortamentoTime = 0x5;
static const Shortint MIDICCDataEntry = 0x6;
static const Shortint MIDICCChannelVolume = 0x7;
static const Shortint MIDICCMainVolume = 0x7;
static const Shortint MIDICCBalance = 0x8;
static const Shortint MIDICCPan = 0xa;
static const Shortint MIDICCExpression = 0xb;
static const Shortint MIDICCEffectControl = 0xc;
static const Shortint MIDICCEffectControl2 = 0xd;
static const Shortint MIDICCGeneralPurpose1 = 0x10;
static const Shortint MIDICCGeneralPurpose2 = 0x11;
static const Shortint MIDICCGeneralPurpose3 = 0x12;
static const Shortint MIDICCGeneralPurpose4 = 0x13;
static const Shortint MIDICCBankSelectLSB = 0x20;
static const Shortint MIDICCModulationWheelLSB = 0x21;
static const Shortint MIDICCBreathControlLSB = 0x22;
static const Shortint MIDICCFootControllerLSB = 0x24;
static const Shortint MIDICCPortamentoTimeLSB = 0x25;
static const Shortint MIDICCDataEntryLSB = 0x26;
static const Shortint MIDICCChannelVolumeLSB = 0x27;
static const Shortint MIDICCMainVolumeLSB = 0x27;
static const Shortint MIDICCBalanceLSB = 0x28;
static const Shortint MIDICCPanLSB = 0x2a;
static const Shortint MIDICCExpressionLSB = 0x2b;
static const Shortint MIDICCEffectControlLSB = 0x2c;
static const Shortint MIDICCEffectControl2LSB = 0x2d;
static const Shortint MIDICCGeneralPurpose1LSB = 0x30;
static const Shortint MIDICCGeneralPurpose2LSB = 0x31;
static const Shortint MIDICCGeneralPurpose3LSB = 0x32;
static const Shortint MIDICCGeneralPurpose4LSB = 0x33;
static const Shortint MIDICCSustain = 0x40;
static const Shortint MIDICCPortamento = 0x41;
static const Shortint MIDICCSustenuto = 0x42;
static const Shortint MIDICCSoftPedal = 0x43;
static const Shortint MIDICCLegato = 0x44;
static const Shortint MIDICCHold2 = 0x45;
static const Shortint MIDICCSound1 = 0x46;
static const Shortint MIDICCSound2 = 0x47;
static const Shortint MIDICCSound3 = 0x48;
static const Shortint MIDICCSound4 = 0x49;
static const Shortint MIDICCSound5 = 0x4a;
static const Shortint MIDICCSound6 = 0x4b;
static const Shortint MIDICCSound7 = 0x4c;
static const Shortint MIDICCSound8 = 0x4d;
static const Shortint MIDICCSound9 = 0x4e;
static const Shortint MIDICCSound10 = 0x4f;
static const Shortint MIDICCGeneralPurpose5 = 0x50;
static const Shortint MIDICCGeneralPurpose6 = 0x51;
static const Shortint MIDICCGeneralPurpose7 = 0x52;
static const Shortint MIDICCGeneralPurpose8 = 0x53;
static const Shortint MIDICCPortamentoControl = 0x54;
static const Shortint MIDICCReverbSendLevel = 0x5b;
static const Shortint MIDICCEffects2Depth = 0x5c;
static const Shortint MIDICCTremoloDepth = 0x5c;
static const Shortint MIDICCChorusSendLevel = 0x5d;
static const Shortint MIDICCEffects4Depth = 0x5e;
static const Shortint MIDICCCelesteDepth = 0x5e;
static const Shortint MIDICCEffects5Depth = 0x5f;
static const Shortint MIDICCPhaserDepth = 0x5f;
static const Shortint MIDICCDataEntryInc = 0x60;
static const Shortint MIDICCDataEntryDec = 0x61;
static const Shortint MIDICCNonRegParamNumLSB = 0x62;
static const Shortint MIDICCNonRegParamNumMSB = 0x63;
static const Shortint MIDICCRegParamNumLSB = 0x64;
static const Shortint MIDICCRegParamNumMSB = 0x65;
static const Shortint MIDICCAllSoundOff = 0x78;
static const Shortint MIDICCResetAllControllers = 0x79;
static const Shortint MIDICCLocalControl = 0x7a;
static const Shortint MIDICCAllNotesOff = 0x7b;
static const Shortint MIDICCOmniModeOff = 0x7c;
static const Shortint MIDICCOmniModeOn = 0x7d;
static const Shortint MIDICCMonoModeOn = 0x7e;
static const Shortint MIDICCPolyModeOn = 0x7f;
static const Shortint MIDIDataMask = 0x7f;
static const Word MIDIDataWordMask = 0x3fff;
static const Byte MIDIChannelMsgMask = 0xf0;
static const TMIDIStatusByte MIDIInvalidStatus = 0x0;
static const Shortint BitsPerMIDIDataByte = 0x7;
static const Shortint BitsPerMIDIDataWord = 0xe;
static const Word MIDIPitchWheelCenter = 0x2000;
extern PACKAGE Jclunitversioning::TUnitVersionInfo UnitVersioning;
extern PACKAGE _di_IJclMIDIOut __fastcall MIDIOut(unsigned DeviceID = (unsigned)(0x0));
extern PACKAGE void __fastcall GetMidiOutputs(const Classes::TStrings* List);
extern PACKAGE TSingleNoteTuningData __fastcall MIDISingleNoteTuningData(TMIDIDataByte Key, float Frequency);
extern PACKAGE AnsiString __fastcall MIDINoteToStr(TMIDIDataByte Note);

}	/* namespace Jclmidi */
using namespace Jclmidi;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Jclmidi
