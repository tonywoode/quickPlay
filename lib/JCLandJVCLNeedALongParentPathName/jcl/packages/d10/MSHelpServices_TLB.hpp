// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Mshelpservices_tlb.pas' rev: 10.00

#ifndef Mshelpservices_tlbHPP
#define Mshelpservices_tlbHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Activex.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mshelpservices_tlb
{
//-- type declarations -------------------------------------------------------
typedef Activex::TOleEnum HxHierarchyNodeType;

typedef Activex::TOleEnum HxHierarchyPropId;

typedef Activex::TOleEnum HxTopicGetTitleType;

typedef Activex::TOleEnum HxTopicGetTitleDefVal;

typedef Activex::TOleEnum HxQueryPropId;

typedef Activex::TOleEnum HxTopicPropId;

typedef Activex::TOleEnum HxHierarchy_PrintNode_Options;

typedef Activex::TOleEnum HxQuery_Options;

typedef Activex::TOleEnum HxCollectionPropId;

typedef Activex::TOleEnum HxRegFilterPropId;

typedef Activex::TOleEnum HxIndexPropId;

typedef Activex::TOleEnum HxSampleFileCopyOption;

typedef Activex::TOleEnum HxRegNamespacePropId;

typedef Activex::TOleEnum HxRegTitlePropId;

typedef Activex::TOleEnum HxRegPlugInPropId;

typedef Activex::TOleEnum HxRegisterSession_InterfaceType;

typedef Activex::TOleEnum HxCancelStatus;

__interface IHxSession;
typedef System::DelphiInterface<IHxSession> _di_IHxSession;
typedef IHxSession HxSession;
;

__interface IHxRegistryWalker;
typedef System::DelphiInterface<IHxRegistryWalker> _di_IHxRegistryWalker;
typedef IHxRegistryWalker HxRegistryWalker;
;

__interface IHxRegisterSession;
typedef System::DelphiInterface<IHxRegisterSession> _di_IHxRegisterSession;
typedef IHxRegisterSession HxRegisterSession;
;

__interface IHxRegisterProtocol;
typedef System::DelphiInterface<IHxRegisterProtocol> _di_IHxRegisterProtocol;
typedef IHxRegisterProtocol HxRegisterProtocol;
;

typedef GUID *PUserType1;

typedef OleVariant *POleVariant1;

__interface IHxHierarchy;
typedef System::DelphiInterface<IHxHierarchy> _di_IHxHierarchy;
__interface IHxTopic;
typedef System::DelphiInterface<IHxTopic> _di_IHxTopic;
__interface  INTERFACE_UUID("{314111B2-A502-11D2-BBCA-00C04F8EC294}") IHxHierarchy  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall GetRoot(int &GetRoot_result) = 0 ;
	virtual HRESULT __safecall GetParent(int hNode, int &GetParent_result) = 0 ;
	virtual HRESULT __safecall GetSibling(int hNode, int &GetSibling_result) = 0 ;
	virtual HRESULT __safecall GetFirstChild(int hNode, int &GetFirstChild_result) = 0 ;
	virtual HRESULT __safecall GetNextFromUrl(const WideString pURL, int &GetNextFromUrl_result) = 0 ;
	virtual HRESULT __safecall GetPrevFromUrl(const WideString pURL, int &GetPrevFromUrl_result) = 0 ;
	virtual HRESULT __safecall GetType(int hNode, Activex::TOleEnum &GetType_result) = 0 ;
	virtual HRESULT __safecall IsNew(int hNode, Word &IsNew_result) = 0 ;
	virtual HRESULT __safecall HasChild(int hNode, Word &HasChild_result) = 0 ;
	virtual HRESULT __safecall GetSyncInfo(const WideString pURL, Activex::PSafeArray &GetSyncInfo_result) = 0 ;
	virtual HRESULT __safecall GetTitle(int hNode, WideString &GetTitle_result) = 0 ;
	virtual HRESULT __safecall GetImageIndexes(int hNode, /* out */ int &pOpen, int &GetImageIndexes_result) = 0 ;
	virtual HRESULT __safecall GetURL(int hNode, WideString &GetURL_result) = 0 ;
	virtual HRESULT __safecall OnNavigation(const WideString pbstrURL, Word &OnNavigation_result) = 0 ;
	virtual HRESULT __safecall OnHierarchyNavigation(int hNode) = 0 ;
	virtual HRESULT __safecall GetProperty(Activex::TOleEnum propid, int hNode, OleVariant &GetProperty_result) = 0 ;
	virtual HRESULT __safecall GetNextFromNode(int hNode, int &GetNextFromNode_result) = 0 ;
	virtual HRESULT __safecall GetPrevFromNode(int hNode, int &GetPrevFromNode_result) = 0 ;
	virtual HRESULT __safecall GetTopic(int hNode, _di_IHxTopic &GetTopic_result) = 0 ;
	virtual HRESULT __safecall GetOpenImageIndex(int hNode, int &GetOpenImageIndex_result) = 0 ;
	virtual HRESULT __safecall GetClosedImageIndex(int hNode, int &GetClosedImageIndex_result) = 0 ;
	virtual HRESULT __safecall PrintNode(int hwnd, int hNode, Activex::TOleEnum options) = 0 ;
};

__interface IHxAttributeList;
typedef System::DelphiInterface<IHxAttributeList> _di_IHxAttributeList;
__interface  INTERFACE_UUID("{31411196-A502-11D2-BBCA-00C04F8EC294}") IHxTopic  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Title(Activex::TOleEnum optType, Activex::TOleEnum optDef, WideString &Get_Title_result) = 0 ;
	virtual HRESULT __safecall Get_URL(WideString &Get_URL_result) = 0 ;
	virtual HRESULT __safecall Get_Location(WideString &Get_Location_result) = 0 ;
	virtual HRESULT __safecall Get_Rank(int &Get_Rank_result) = 0 ;
	virtual HRESULT __safecall Get_Attributes(_di_IHxAttributeList &Get_Attributes_result) = 0 ;
	virtual HRESULT __safecall GetInfo(/* out */ WideString &pTitle, /* out */ WideString &pURL, /* out */ WideString &pLocation, /* out */ int &pRank) = 0 ;
	virtual HRESULT __safecall GetProperty(Activex::TOleEnum propid, OleVariant &GetProperty_result) = 0 ;
	virtual HRESULT __safecall SetProperty(Activex::TOleEnum propid, const OleVariant var_) = 0 ;
	virtual HRESULT __safecall HasAttribute(const WideString Name, const WideString Value, Word &HasAttribute_result) = 0 ;
	virtual HRESULT __safecall HasAttrName(const WideString Name, Word &HasAttrName_result) = 0 ;
	virtual HRESULT __safecall HighlightDocument(const _di_IDispatch pIDispatch) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Title(Activex::TOleEnum optType, Activex::TOleEnum optDef) { WideString r; HRESULT hr = Get_Title(optType, optDef, r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Title[Activex::TOleEnum optType][Activex::TOleEnum optDef] = {read=_scw_Get_Title};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_URL() { WideString r; HRESULT hr = Get_URL(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString URL = {read=_scw_Get_URL};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Location() { WideString r; HRESULT hr = Get_Location(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Location = {read=_scw_Get_Location};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Rank() { int r; HRESULT hr = Get_Rank(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Rank = {read=_scw_Get_Rank};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IHxAttributeList _scw_Get_Attributes() { _di_IHxAttributeList r; HRESULT hr = Get_Attributes(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IHxAttributeList Attributes = {read=_scw_Get_Attributes};
};

__interface IHxAttribute;
typedef System::DelphiInterface<IHxAttribute> _di_IHxAttribute;
__interface IEnumHxAttribute;
typedef System::DelphiInterface<IEnumHxAttribute> _di_IEnumHxAttribute;
__interface  INTERFACE_UUID("{314111AB-A502-11D2-BBCA-00C04F8EC294}") IHxAttributeList  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Count(int &Get_Count_result) = 0 ;
	virtual HRESULT __safecall ItemAt(int index, _di_IHxAttribute &ItemAt_result) = 0 ;
	virtual HRESULT __safecall EnumAttribute(int filter, int options, _di_IEnumHxAttribute &EnumAttribute_result) = 0 ;
	virtual HRESULT __safecall Get__NewEnum(System::_di_IInterface &Get__NewEnum_result) = 0 ;
	virtual HRESULT __safecall Item(const OleVariant index, _di_IHxAttribute &Item_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Count() { int r; HRESULT hr = Get_Count(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Count = {read=_scw_Get_Count};
	#pragma option push -w-inl
	/* safecall wrapper */ inline System::_di_IInterface _scw_Get__NewEnum() { System::_di_IInterface r; HRESULT hr = Get__NewEnum(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property System::_di_IInterface _NewEnum = {read=_scw_Get__NewEnum};
};

__interface  INTERFACE_UUID("{314111A9-A502-11D2-BBCA-00C04F8EC294}") IHxAttribute  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall GetProperty(Activex::TOleEnum propid, OleVariant &GetProperty_result) = 0 ;
	virtual HRESULT __safecall SetProperty(Activex::TOleEnum propid, const OleVariant var_) = 0 ;
	virtual HRESULT __safecall Get_Name(WideString &Get_Name_result) = 0 ;
	virtual HRESULT __safecall Get_Value(WideString &Get_Value_result) = 0 ;
	virtual HRESULT __safecall Get_DisplayName(WideString &Get_DisplayName_result) = 0 ;
	virtual HRESULT __safecall Get_DisplayValue(WideString &Get_DisplayValue_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Name() { WideString r; HRESULT hr = Get_Name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Name = {read=_scw_Get_Name};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Value() { WideString r; HRESULT hr = Get_Value(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Value = {read=_scw_Get_Value};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_DisplayName() { WideString r; HRESULT hr = Get_DisplayName(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString DisplayName = {read=_scw_Get_DisplayName};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_DisplayValue() { WideString r; HRESULT hr = Get_DisplayValue(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString DisplayValue = {read=_scw_Get_DisplayValue};
};

__interface  INTERFACE_UUID("{314111AD-A502-11D2-BBCA-00C04F8EC294}") IEnumHxAttribute  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall Next(unsigned celt, /* out */ _di_IHxAttribute &ppIHxAttribute, /* out */ unsigned &pceltFetched) = 0 ;
	virtual HRESULT __stdcall Reset(void) = 0 ;
	virtual HRESULT __stdcall Skip(unsigned celt) = 0 ;
	virtual HRESULT __stdcall Clone(/* out */ _di_IEnumHxAttribute &ppEnum) = 0 ;
};

__interface IHxRegister;
typedef System::DelphiInterface<IHxRegister> _di_IHxRegister;
__interface  INTERFACE_UUID("{314111BC-A502-11D2-BBCA-00C04F8EC294}") IHxRegister  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall RegisterNamespace(const WideString bstrNamespace, const WideString bstrCollection, const WideString bstrDescription) = 0 ;
	virtual HRESULT __safecall IsNamespace(const WideString bstrNamespace, Word &IsNamespace_result) = 0 ;
	virtual HRESULT __safecall GetCollection(const WideString bstrNamespace, WideString &GetCollection_result) = 0 ;
	virtual HRESULT __safecall GetDescription(const WideString bstrNamespace, WideString &GetDescription_result) = 0 ;
	virtual HRESULT __safecall RemoveNamespace(const WideString bstrNamespace) = 0 ;
	virtual HRESULT __safecall RegisterHelpFile(const WideString bstrNamespace, const WideString bstrId, int LangId, const WideString bstrHelpFile) = 0 ;
	virtual HRESULT __safecall RegisterMedia(const WideString bstrNamespace, const WideString bstrFriendly, const WideString bstrPath, int &RegisterMedia_result) = 0 ;
	virtual HRESULT __safecall RemoveHelpFile(const WideString bstrNamespace, const WideString bstrId, int LangId) = 0 ;
	virtual HRESULT __safecall RegisterHelpFileSet(const WideString bstrNamespace, const WideString bstrId, int LangId, const WideString bstrHxs, const WideString bstrHxi, const WideString bstrHxq, const WideString bstrHxr, int lHxsMediaId, int lHxqMediaId, int lHxrMediaId, int lSampleMediaId) = 0 ;
};

__interface IHxIndex;
typedef System::DelphiInterface<IHxIndex> _di_IHxIndex;
__interface IHxTopicList;
typedef System::DelphiInterface<IHxTopicList> _di_IHxTopicList;
__interface  INTERFACE_UUID("{314111CC-A502-11D2-BBCA-00C04F8EC294}") IHxIndex  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall GetSession(_di_IHxSession &GetSession_result) = 0 ;
	virtual HRESULT __safecall Get_Count(int &Get_Count_result) = 0 ;
	virtual HRESULT __safecall GetStringFromSlot(int iSlot, WideString &GetStringFromSlot_result) = 0 ;
	virtual HRESULT __safecall GetLevelFromSlot(int iSlot, int &GetLevelFromSlot_result) = 0 ;
	virtual HRESULT __safecall GetSlotFromString(const WideString bszLink, int &GetSlotFromString_result) = 0 ;
	virtual HRESULT __safecall GetTopicsFromSlot(int uiSlot, _di_IHxTopicList &GetTopicsFromSlot_result) = 0 ;
	virtual HRESULT __safecall GetTopicsFromString(const WideString bszLink, int options, _di_IHxTopicList &GetTopicsFromString_result) = 0 ;
	virtual HRESULT __safecall GetInfoFromSlot(int iSlot, /* out */ int &piLevel, WideString &GetInfoFromSlot_result) = 0 ;
	virtual HRESULT __safecall GetProperty(Activex::TOleEnum propid, OleVariant &GetProperty_result) = 0 ;
	virtual HRESULT __safecall GetCrossRef(int iSlot, WideString &GetCrossRef_result) = 0 ;
	virtual HRESULT __safecall GetFullStringFromSlot(int iSlot, const WideString sep, WideString &GetFullStringFromSlot_result) = 0 ;
	virtual HRESULT __safecall GetCrossRefSlot(int iSlot, int &GetCrossRefSlot_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Count() { int r; HRESULT hr = Get_Count(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Count = {read=_scw_Get_Count};
};

__interface IHxQuery;
typedef System::DelphiInterface<IHxQuery> _di_IHxQuery;
__interface IHxCollection;
typedef System::DelphiInterface<IHxCollection> _di_IHxCollection;
__interface IHxRegFilterList;
typedef System::DelphiInterface<IHxRegFilterList> _di_IHxRegFilterList;
__interface  INTERFACE_UUID("{31411192-A502-11D2-BBCA-00C04F8EC294}") IHxSession  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Initialize(const WideString NameSpace, int options) = 0 ;
	virtual HRESULT __safecall Query(const WideString keywords, const WideString NavDataMoniker, int options, const WideString FilterMoniker, _di_IHxTopicList &Query_result) = 0 ;
	virtual HRESULT __safecall QueryForTopic(const WideString keywords, const WideString NavDataMoniker, int options, const WideString FilterMoniker, _di_IHxTopic &QueryForTopic_result) = 0 ;
	virtual HRESULT __safecall QueryForUrl(const WideString keywords, const WideString NavDataMoniker, int options, const WideString FilterMoniker, WideString &QueryForUrl_result) = 0 ;
	virtual HRESULT __safecall GetNavigationInterface(const WideString NavDataMoniker, const WideString FilterMoniker, GUID &refiid, _di_IDispatch &GetNavigationInterface_result) = 0 ;
	virtual HRESULT __safecall GetNavigationObject(const WideString NavDataMoniker, const WideString FilterMoniker, _di_IDispatch &GetNavigationObject_result) = 0 ;
	virtual HRESULT __safecall GetQueryObject(const WideString NavDataMoniker, const WideString FilterMoniker, _di_IHxQuery &GetQueryObject_result) = 0 ;
	virtual HRESULT __safecall Get_Collection(_di_IHxCollection &Get_Collection_result) = 0 ;
	virtual HRESULT __safecall Get_LangId(short &Get_LangId_result) = 0 ;
	virtual HRESULT __safecall Set_LangId(short piHelpLangId) = 0 ;
	virtual HRESULT __safecall GetFilterList(_di_IHxRegFilterList &GetFilterList_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IHxCollection _scw_Get_Collection() { _di_IHxCollection r; HRESULT hr = Get_Collection(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IHxCollection Collection = {read=_scw_Get_Collection};
	#pragma option push -w-inl
	/* safecall wrapper */ inline short _scw_Get_LangId() { short r; HRESULT hr = Get_LangId(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property short LangId = {read=_scw_Get_LangId, write=Set_LangId};
};

__interface IEnumHxTopic;
typedef System::DelphiInterface<IEnumHxTopic> _di_IEnumHxTopic;
__interface  INTERFACE_UUID("{31411194-A502-11D2-BBCA-00C04F8EC294}") IHxTopicList  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Item(const OleVariant index, _di_IHxTopic &Item_result) = 0 ;
	virtual HRESULT __safecall ItemAt(int index, _di_IHxTopic &ItemAt_result) = 0 ;
	virtual HRESULT __safecall EnumTopics(int filter, int options, _di_IEnumHxTopic &EnumTopics_result) = 0 ;
	virtual HRESULT __safecall Get__NewEnum(System::_di_IInterface &Get__NewEnum_result) = 0 ;
	virtual HRESULT __safecall Get_Count(int &Get_Count_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline System::_di_IInterface _scw_Get__NewEnum() { System::_di_IInterface r; HRESULT hr = Get__NewEnum(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property System::_di_IInterface _NewEnum = {read=_scw_Get__NewEnum};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Count() { int r; HRESULT hr = Get_Count(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Count = {read=_scw_Get_Count};
};

__interface  INTERFACE_UUID("{31411195-A502-11D2-BBCA-00C04F8EC294}") IEnumHxTopic  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall Next(unsigned celt, /* out */ _di_IHxTopic &ppIHxTopic, /* out */ unsigned &pceltFetched) = 0 ;
	virtual HRESULT __stdcall Reset(void) = 0 ;
	virtual HRESULT __stdcall Skip(unsigned celt) = 0 ;
	virtual HRESULT __stdcall Clone(/* out */ _di_IEnumHxTopic &ppEnum) = 0 ;
};

__interface  INTERFACE_UUID("{31411193-A502-11D2-BBCA-00C04F8EC294}") IHxQuery  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Query(const WideString keywords, Activex::TOleEnum options, _di_IHxTopicList &Query_result) = 0 ;
	virtual HRESULT __safecall QueryForTopic(const WideString keywords, Activex::TOleEnum options, _di_IHxTopic &QueryForTopic_result) = 0 ;
	virtual HRESULT __safecall QueryForUrl(const WideString keywords, Activex::TOleEnum options, WideString &QueryForUrl_result) = 0 ;
};

__interface IHxAttrNameList;
typedef System::DelphiInterface<IHxAttrNameList> _di_IHxAttrNameList;
__interface IHxFilters;
typedef System::DelphiInterface<IHxFilters> _di_IHxFilters;
__interface  INTERFACE_UUID("{314111A1-A502-11D2-BBCA-00C04F8EC294}") IHxCollection  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall GetProperty(Activex::TOleEnum propid, OleVariant &GetProperty_result) = 0 ;
	virtual HRESULT __safecall SetProperty(Activex::TOleEnum propid, const OleVariant var_) = 0 ;
	virtual HRESULT __safecall Get_URL(WideString &Get_URL_result) = 0 ;
	virtual HRESULT __safecall Get_AttributeNames(_di_IHxAttrNameList &Get_AttributeNames_result) = 0 ;
	virtual HRESULT __safecall Get_Filters(_di_IHxFilters &Get_Filters_result) = 0 ;
	virtual HRESULT __safecall Get_Title(WideString &Get_Title_result) = 0 ;
	virtual HRESULT __safecall MergeIndex(void) = 0 ;
	virtual HRESULT __safecall GetFilterTopicCount(const WideString bstrQuery, int &GetFilterTopicCount_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_URL() { WideString r; HRESULT hr = Get_URL(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString URL = {read=_scw_Get_URL};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IHxAttrNameList _scw_Get_AttributeNames() { _di_IHxAttrNameList r; HRESULT hr = Get_AttributeNames(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IHxAttrNameList AttributeNames = {read=_scw_Get_AttributeNames};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IHxFilters _scw_Get_Filters() { _di_IHxFilters r; HRESULT hr = Get_Filters(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IHxFilters Filters = {read=_scw_Get_Filters};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Title() { WideString r; HRESULT hr = Get_Title(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Title = {read=_scw_Get_Title};
};

__interface IHxAttrName;
typedef System::DelphiInterface<IHxAttrName> _di_IHxAttrName;
__interface IEnumHxAttrName;
typedef System::DelphiInterface<IEnumHxAttrName> _di_IEnumHxAttrName;
__interface  INTERFACE_UUID("{314111CE-A502-11D2-BBCA-00C04F8EC294}") IHxAttrNameList  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Count(int &Get_Count_result) = 0 ;
	virtual HRESULT __safecall ItemAt(int index, _di_IHxAttrName &ItemAt_result) = 0 ;
	virtual HRESULT __safecall EnumAttrName(int filter, int options, _di_IEnumHxAttrName &EnumAttrName_result) = 0 ;
	virtual HRESULT __safecall Get__NewEnum(System::_di_IInterface &Get__NewEnum_result) = 0 ;
	virtual HRESULT __safecall Item(const OleVariant index, _di_IHxAttrName &Item_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Count() { int r; HRESULT hr = Get_Count(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Count = {read=_scw_Get_Count};
	#pragma option push -w-inl
	/* safecall wrapper */ inline System::_di_IInterface _scw_Get__NewEnum() { System::_di_IInterface r; HRESULT hr = Get__NewEnum(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property System::_di_IInterface _NewEnum = {read=_scw_Get__NewEnum};
};

__interface IHxAttrValueList;
typedef System::DelphiInterface<IHxAttrValueList> _di_IHxAttrValueList;
__interface  INTERFACE_UUID("{314111D2-A502-11D2-BBCA-00C04F8EC294}") IHxAttrName  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall GetProperty(Activex::TOleEnum propid, OleVariant &GetProperty_result) = 0 ;
	virtual HRESULT __safecall SetProperty(Activex::TOleEnum propid, const OleVariant var_) = 0 ;
	virtual HRESULT __safecall Get_Name(WideString &Get_Name_result) = 0 ;
	virtual HRESULT __safecall Get_DisplayName(WideString &Get_DisplayName_result) = 0 ;
	virtual HRESULT __safecall Get_Flag(int &Get_Flag_result) = 0 ;
	virtual HRESULT __safecall Get_AttributeValues(_di_IHxAttrValueList &Get_AttributeValues_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Name() { WideString r; HRESULT hr = Get_Name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Name = {read=_scw_Get_Name};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_DisplayName() { WideString r; HRESULT hr = Get_DisplayName(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString DisplayName = {read=_scw_Get_DisplayName};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Flag() { int r; HRESULT hr = Get_Flag(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Flag = {read=_scw_Get_Flag};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IHxAttrValueList _scw_Get_AttributeValues() { _di_IHxAttrValueList r; HRESULT hr = Get_AttributeValues(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IHxAttrValueList AttributeValues = {read=_scw_Get_AttributeValues};
};

__interface IHxAttrValue;
typedef System::DelphiInterface<IHxAttrValue> _di_IHxAttrValue;
__interface IEnumHxAttrValue;
typedef System::DelphiInterface<IEnumHxAttrValue> _di_IEnumHxAttrValue;
__interface  INTERFACE_UUID("{314111D4-A502-11D2-BBCA-00C04F8EC294}") IHxAttrValueList  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Count(int &Get_Count_result) = 0 ;
	virtual HRESULT __safecall ItemAt(int index, _di_IHxAttrValue &ItemAt_result) = 0 ;
	virtual HRESULT __safecall EnumAttrValue(int filter, int options, _di_IEnumHxAttrValue &EnumAttrValue_result) = 0 ;
	virtual HRESULT __safecall Get__NewEnum(System::_di_IInterface &Get__NewEnum_result) = 0 ;
	virtual HRESULT __safecall Item(const OleVariant index, _di_IHxAttrValue &Item_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Count() { int r; HRESULT hr = Get_Count(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Count = {read=_scw_Get_Count};
	#pragma option push -w-inl
	/* safecall wrapper */ inline System::_di_IInterface _scw_Get__NewEnum() { System::_di_IInterface r; HRESULT hr = Get__NewEnum(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property System::_di_IInterface _NewEnum = {read=_scw_Get__NewEnum};
};

__interface  INTERFACE_UUID("{314111D8-A502-11D2-BBCA-00C04F8EC294}") IHxAttrValue  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall GetProperty(Activex::TOleEnum propid, OleVariant &GetProperty_result) = 0 ;
	virtual HRESULT __safecall SetProperty(Activex::TOleEnum propid, const OleVariant var_) = 0 ;
	virtual HRESULT __safecall Get_Value(WideString &Get_Value_result) = 0 ;
	virtual HRESULT __safecall Get_DisplayValue(WideString &Get_DisplayValue_result) = 0 ;
	virtual HRESULT __safecall Get_Flag(int &Get_Flag_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Value() { WideString r; HRESULT hr = Get_Value(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Value = {read=_scw_Get_Value};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_DisplayValue() { WideString r; HRESULT hr = Get_DisplayValue(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString DisplayValue = {read=_scw_Get_DisplayValue};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Flag() { int r; HRESULT hr = Get_Flag(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Flag = {read=_scw_Get_Flag};
};

__interface  INTERFACE_UUID("{314111D6-A502-11D2-BBCA-00C04F8EC294}") IEnumHxAttrValue  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall Next(unsigned celt, /* out */ _di_IHxAttrValue &ppIHxAttrValue, /* out */ unsigned &pceltFetched) = 0 ;
	virtual HRESULT __stdcall Reset(void) = 0 ;
	virtual HRESULT __stdcall Skip(unsigned celt) = 0 ;
	virtual HRESULT __stdcall Clone(/* out */ _di_IEnumHxAttrValue &ppEnum) = 0 ;
};

__interface  INTERFACE_UUID("{314111D0-A502-11D2-BBCA-00C04F8EC294}") IEnumHxAttrName  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall Next(unsigned celt, /* out */ _di_IHxAttrName &ppIHxAttrName, /* out */ unsigned &pceltFetched) = 0 ;
	virtual HRESULT __stdcall Reset(void) = 0 ;
	virtual HRESULT __stdcall Skip(unsigned celt) = 0 ;
	virtual HRESULT __stdcall Clone(/* out */ _di_IEnumHxAttrName &ppEnum) = 0 ;
};

__interface  INTERFACE_UUID("{314111E3-A502-11D2-BBCA-00C04F8EC294}") IHxFilters  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Count(int &Count_result) = 0 ;
	virtual HRESULT __safecall GetFilter(int iIndex, /* out */ WideString &pbstrName, WideString &GetFilter_result) = 0 ;
	virtual HRESULT __safecall GetFilterName(int iIndex, WideString &GetFilterName_result) = 0 ;
	virtual HRESULT __safecall GetFilterQuery(int iIndex, WideString &GetFilterQuery_result) = 0 ;
	virtual HRESULT __safecall RegisterFilter(const WideString bstrName, const WideString bstrQuery) = 0 ;
	virtual HRESULT __safecall RemoveFilter(const WideString bstrName) = 0 ;
	virtual HRESULT __safecall FindFilter(const WideString bstrName, WideString &FindFilter_result) = 0 ;
	virtual HRESULT __safecall SetNamespace(const WideString bstrName) = 0 ;
	virtual HRESULT __safecall SetCollectionFiltersFlag(Word vb) = 0 ;
};

__interface IHxRegFilter;
typedef System::DelphiInterface<IHxRegFilter> _di_IHxRegFilter;
__interface IEnumHxRegFilter;
typedef System::DelphiInterface<IEnumHxRegFilter> _di_IEnumHxRegFilter;
__interface  INTERFACE_UUID("{31411212-A502-11D2-BBCA-00C04F8EC294}") IHxRegFilterList  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Item(const OleVariant index, _di_IHxRegFilter &Item_result) = 0 ;
	virtual HRESULT __safecall ItemAt(int index, _di_IHxRegFilter &ItemAt_result) = 0 ;
	virtual HRESULT __safecall EnumRegFilter(int filter, int options, _di_IEnumHxRegFilter &EnumRegFilter_result) = 0 ;
	virtual HRESULT __safecall Get__NewEnum(System::_di_IInterface &Get__NewEnum_result) = 0 ;
	virtual HRESULT __safecall Get_Count(int &Get_Count_result) = 0 ;
	virtual HRESULT __safecall FindFilter(const WideString bstrFilterName, _di_IHxRegFilter &FindFilter_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline System::_di_IInterface _scw_Get__NewEnum() { System::_di_IInterface r; HRESULT hr = Get__NewEnum(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property System::_di_IInterface _NewEnum = {read=_scw_Get__NewEnum};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Count() { int r; HRESULT hr = Get_Count(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Count = {read=_scw_Get_Count};
};

__interface  INTERFACE_UUID("{31411221-A502-11D2-BBCA-00C04F8EC294}") IHxRegFilter  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall GetProperty(Activex::TOleEnum propid, OleVariant &GetProperty_result) = 0 ;
};

__interface  INTERFACE_UUID("{3141121C-A502-11D2-BBCA-00C04F8EC294}") IEnumHxRegFilter  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall Next(unsigned celt, /* out */ _di_IHxRegFilter &ppIHxRegFilter, /* out */ unsigned &pceltFetched) = 0 ;
	virtual HRESULT __stdcall Reset(void) = 0 ;
	virtual HRESULT __stdcall Skip(unsigned celt) = 0 ;
	virtual HRESULT __stdcall Clone(/* out */ _di_IEnumHxRegFilter &ppEnum) = 0 ;
};

__interface IHxSampleCollection;
typedef System::DelphiInterface<IHxSampleCollection> _di_IHxSampleCollection;
__interface IHxSample;
typedef System::DelphiInterface<IHxSample> _di_IHxSample;
__interface  INTERFACE_UUID("{314111E6-A502-11D2-BBCA-00C04F8EC294}") IHxSampleCollection  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall GetSampleFromId(const WideString bstrTopicUrl, const WideString bstrId, const WideString bstrSFLName, _di_IHxSample &GetSampleFromId_result) = 0 ;
};

__interface  INTERFACE_UUID("{314111E8-A502-11D2-BBCA-00C04F8EC294}") IHxSample  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_SampleId(WideString &Get_SampleId_result) = 0 ;
	virtual HRESULT __safecall Get_LoadString(WideString &Get_LoadString_result) = 0 ;
	virtual HRESULT __safecall Get_DestinationDir(WideString &Get_DestinationDir_result) = 0 ;
	virtual HRESULT __safecall Get_ProjectFileExt(WideString &Get_ProjectFileExt_result) = 0 ;
	virtual HRESULT __safecall Get_FileCount(int &Get_FileCount_result) = 0 ;
	virtual HRESULT __safecall GetFileNameAtIndex(int index, WideString &GetFileNameAtIndex_result) = 0 ;
	virtual HRESULT __safecall CopyFileAtIndex(int index, const WideString bstrDest, Activex::TOleEnum option) = 0 ;
	virtual HRESULT __safecall ChooseDirectory(const WideString bstrDefaultDir, const WideString bstrTitle, WideString &ChooseDirectory_result) = 0 ;
	virtual HRESULT __safecall GetFileTextAtIndex(int index, WideString &GetFileTextAtIndex_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_SampleId() { WideString r; HRESULT hr = Get_SampleId(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString SampleId = {read=_scw_Get_SampleId};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_LoadString() { WideString r; HRESULT hr = Get_LoadString(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString LoadString = {read=_scw_Get_LoadString};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_DestinationDir() { WideString r; HRESULT hr = Get_DestinationDir(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString DestinationDir = {read=_scw_Get_DestinationDir};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_ProjectFileExt() { WideString r; HRESULT hr = Get_ProjectFileExt(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString ProjectFileExt = {read=_scw_Get_ProjectFileExt};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_FileCount() { int r; HRESULT hr = Get_FileCount(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int FileCount = {read=_scw_Get_FileCount};
};

__interface IHxRegNamespaceList;
typedef System::DelphiInterface<IHxRegNamespaceList> _di_IHxRegNamespaceList;
__interface  INTERFACE_UUID("{314111EF-A502-11D2-BBCA-00C04F8EC294}") IHxRegistryWalker  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_RegisteredNamespaceList(const WideString bstrStart, _di_IHxRegNamespaceList &Get_RegisteredNamespaceList_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IHxRegNamespaceList _scw_Get_RegisteredNamespaceList(const WideString bstrStart) { _di_IHxRegNamespaceList r; HRESULT hr = Get_RegisteredNamespaceList(bstrStart, r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IHxRegNamespaceList RegisteredNamespaceList[WideString bstrStart] = {read=_scw_Get_RegisteredNamespaceList};
};

__interface IHxRegNamespace;
typedef System::DelphiInterface<IHxRegNamespace> _di_IHxRegNamespace;
__interface IEnumHxRegNamespace;
typedef System::DelphiInterface<IEnumHxRegNamespace> _di_IEnumHxRegNamespace;
__interface  INTERFACE_UUID("{314111F3-A502-11D2-BBCA-00C04F8EC294}") IHxRegNamespaceList  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Item(const OleVariant index, _di_IHxRegNamespace &Item_result) = 0 ;
	virtual HRESULT __safecall ItemAt(int index, _di_IHxRegNamespace &ItemAt_result) = 0 ;
	virtual HRESULT __safecall EnumRegNamespace(int filter, int options, _di_IEnumHxRegNamespace &EnumRegNamespace_result) = 0 ;
	virtual HRESULT __safecall Get__NewEnum(System::_di_IInterface &Get__NewEnum_result) = 0 ;
	virtual HRESULT __safecall Get_Count(int &Get_Count_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline System::_di_IInterface _scw_Get__NewEnum() { System::_di_IInterface r; HRESULT hr = Get__NewEnum(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property System::_di_IInterface _NewEnum = {read=_scw_Get__NewEnum};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Count() { int r; HRESULT hr = Get_Count(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Count = {read=_scw_Get_Count};
};

__interface  INTERFACE_UUID("{314111F1-A502-11D2-BBCA-00C04F8EC294}") IHxRegNamespace  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Name(WideString &Get_Name_result) = 0 ;
	virtual HRESULT __safecall GetProperty(Activex::TOleEnum propid, OleVariant &GetProperty_result) = 0 ;
	virtual HRESULT __safecall IsTitle(const WideString bstrTitle, Word &IsTitle_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Name() { WideString r; HRESULT hr = Get_Name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Name = {read=_scw_Get_Name};
};

__interface  INTERFACE_UUID("{314111F5-A502-11D2-BBCA-00C04F8EC294}") IEnumHxRegNamespace  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall Next(unsigned celt, /* out */ _di_IHxRegNamespace &ppIHxRegNamespace, /* out */ unsigned &pceltFetched) = 0 ;
	virtual HRESULT __stdcall Reset(void) = 0 ;
	virtual HRESULT __stdcall Skip(unsigned celt) = 0 ;
	virtual HRESULT __stdcall Clone(/* out */ _di_IEnumHxRegNamespace &ppEnum) = 0 ;
};

__interface IHxRegTitle;
typedef System::DelphiInterface<IHxRegTitle> _di_IHxRegTitle;
__interface  INTERFACE_UUID("{31411202-A502-11D2-BBCA-00C04F8EC294}") IHxRegTitle  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall GetProperty(Activex::TOleEnum propid, OleVariant &GetProperty_result) = 0 ;
};

__interface IHxRegTitleList;
typedef System::DelphiInterface<IHxRegTitleList> _di_IHxRegTitleList;
__interface IEnumHxRegTitle;
typedef System::DelphiInterface<IEnumHxRegTitle> _di_IEnumHxRegTitle;
__interface  INTERFACE_UUID("{31411203-A502-11D2-BBCA-00C04F8EC294}") IHxRegTitleList  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Item(const OleVariant index, _di_IHxRegTitle &Item_result) = 0 ;
	virtual HRESULT __safecall ItemAt(int index, _di_IHxRegTitle &ItemAt_result) = 0 ;
	virtual HRESULT __safecall EnumRegTitle(int filter, int options, _di_IEnumHxRegTitle &EnumRegTitle_result) = 0 ;
	virtual HRESULT __safecall Get__NewEnum(System::_di_IInterface &Get__NewEnum_result) = 0 ;
	virtual HRESULT __safecall Get_Count(int &Get_Count_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline System::_di_IInterface _scw_Get__NewEnum() { System::_di_IInterface r; HRESULT hr = Get__NewEnum(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property System::_di_IInterface _NewEnum = {read=_scw_Get__NewEnum};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Count() { int r; HRESULT hr = Get_Count(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Count = {read=_scw_Get_Count};
};

__interface  INTERFACE_UUID("{31411204-A502-11D2-BBCA-00C04F8EC294}") IEnumHxRegTitle  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall Next(unsigned celt, /* out */ _di_IHxRegTitle &ppIHxRegTitle, /* out */ unsigned &pceltFetched) = 0 ;
	virtual HRESULT __stdcall Reset(void) = 0 ;
	virtual HRESULT __stdcall Skip(unsigned celt) = 0 ;
	virtual HRESULT __stdcall Clone(/* out */ _di_IEnumHxRegTitle &ppEnum) = 0 ;
};

__interface IHxRegPlugIn;
typedef System::DelphiInterface<IHxRegPlugIn> _di_IHxRegPlugIn;
__interface  INTERFACE_UUID("{3141120A-A502-11D2-BBCA-00C04F8EC294}") IHxRegPlugIn  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall GetProperty(Activex::TOleEnum propid, OleVariant &GetProperty_result) = 0 ;
};

__interface IHxRegPlugInList;
typedef System::DelphiInterface<IHxRegPlugInList> _di_IHxRegPlugInList;
__interface IEnumHxRegPlugIn;
typedef System::DelphiInterface<IEnumHxRegPlugIn> _di_IEnumHxRegPlugIn;
__interface  INTERFACE_UUID("{3141120B-A502-11D2-BBCA-00C04F8EC294}") IHxRegPlugInList  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Item(const OleVariant index, _di_IHxRegPlugIn &Item_result) = 0 ;
	virtual HRESULT __safecall ItemAt(int index, _di_IHxRegPlugIn &ItemAt_result) = 0 ;
	virtual HRESULT __safecall EnumRegPlugIn(int filter, int options, _di_IEnumHxRegPlugIn &EnumRegPlugIn_result) = 0 ;
	virtual HRESULT __safecall Get__NewEnum(System::_di_IInterface &Get__NewEnum_result) = 0 ;
	virtual HRESULT __safecall Get_Count(int &Get_Count_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline System::_di_IInterface _scw_Get__NewEnum() { System::_di_IInterface r; HRESULT hr = Get__NewEnum(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property System::_di_IInterface _NewEnum = {read=_scw_Get__NewEnum};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Count() { int r; HRESULT hr = Get_Count(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Count = {read=_scw_Get_Count};
};

__interface  INTERFACE_UUID("{3141120C-A502-11D2-BBCA-00C04F8EC294}") IEnumHxRegPlugIn  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall Next(unsigned celt, /* out */ _di_IHxRegPlugIn &ppIHxRegPlugIn, /* out */ unsigned &pceltFetched) = 0 ;
	virtual HRESULT __stdcall Reset(void) = 0 ;
	virtual HRESULT __stdcall Skip(unsigned celt) = 0 ;
	virtual HRESULT __stdcall Clone(/* out */ _di_IEnumHxRegPlugIn &ppEnum) = 0 ;
};

__interface  INTERFACE_UUID("{31411218-A502-11D2-BBCA-00C04F8EC294}") IHxRegisterSession  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall CreateTransaction(const WideString bstrInToken, WideString &CreateTransaction_result) = 0 ;
	virtual HRESULT __safecall PostponeTransaction(WideString &PostponeTransaction_result) = 0 ;
	virtual HRESULT __safecall ContinueTransaction(const WideString bstrToken) = 0 ;
	virtual HRESULT __safecall CommitTransaction(void) = 0 ;
	virtual HRESULT __safecall RevertTransaction(void) = 0 ;
	virtual HRESULT __safecall GetRegistrationObject(Activex::TOleEnum type_, _di_IDispatch &GetRegistrationObject_result) = 0 ;
};

__interface IHxPlugIn;
typedef System::DelphiInterface<IHxPlugIn> _di_IHxPlugIn;
__interface  INTERFACE_UUID("{314111DA-A502-11D2-BBCA-00C04F8EC294}") IHxPlugIn  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall RegisterHelpPlugIn(const WideString bstrProductNamespace, const WideString bstrProductHxt, const WideString bstrNamespace, const WideString bstrHxt, const WideString bstrHxa, int options) = 0 ;
	virtual HRESULT __safecall RemoveHelpPlugIn(const WideString bstrProductNamespace, const WideString bstrProductHxt, const WideString bstrNamespace, const WideString bstrHxt, const WideString bstrHxa) = 0 ;
};

__interface IHxInitialize;
typedef System::DelphiInterface<IHxInitialize> _di_IHxInitialize;
__interface  INTERFACE_UUID("{314111AE-A502-11D2-BBCA-00C04F8EC294}") IHxInitialize  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Initialize(const WideString InitString, int options) = 0 ;
	virtual HRESULT __safecall Get_filter(WideString &Get_filter_result) = 0 ;
	virtual HRESULT __safecall Set_filter(const WideString pFilterMoniker) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_filter() { WideString r; HRESULT hr = Get_filter(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString filter = {read=_scw_Get_filter, write=Set_filter};
};

__interface IHxCancel;
typedef System::DelphiInterface<IHxCancel> _di_IHxCancel;
__interface  INTERFACE_UUID("{31411225-A502-11D2-BBCA-00C04F8EC294}") IHxCancel  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Cancel(Activex::TOleEnum &Get_Cancel_result) = 0 ;
	virtual HRESULT __safecall Set_Cancel(Activex::TOleEnum pbCancel) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline Activex::TOleEnum _scw_Get_Cancel() { Activex::TOleEnum r; HRESULT hr = Get_Cancel(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Activex::TOleEnum Cancel = {read=_scw_Get_Cancel, write=Set_Cancel};
};

__interface  INTERFACE_UUID("{31411227-A502-11D2-BBCA-00C04F8EC294}") IHxRegisterProtocol  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Register(void) = 0 ;
	virtual HRESULT __safecall Unregister(void) = 0 ;
};

class DELPHICLASS CoHxSession;
class PASCALIMPLEMENTATION CoHxSession : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IHxSession __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IHxSession __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoHxSession(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoHxSession(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoHxRegistryWalker;
class PASCALIMPLEMENTATION CoHxRegistryWalker : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IHxRegistryWalker __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IHxRegistryWalker __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoHxRegistryWalker(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoHxRegistryWalker(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoHxRegisterSession;
class PASCALIMPLEMENTATION CoHxRegisterSession : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IHxRegisterSession __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IHxRegisterSession __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoHxRegisterSession(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoHxRegisterSession(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoHxRegisterProtocol;
class PASCALIMPLEMENTATION CoHxRegisterProtocol : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IHxRegisterProtocol __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IHxRegisterProtocol __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoHxRegisterProtocol(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoHxRegisterProtocol(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint MSHelpServicesMajorVersion = 0x1;
static const Shortint MSHelpServicesMinorVersion = 0x0;
extern PACKAGE GUID LIBID_MSHelpServices;
extern PACKAGE GUID IID_IHxHierarchy;
extern PACKAGE GUID IID_IHxTopic;
extern PACKAGE GUID IID_IHxAttributeList;
extern PACKAGE GUID IID_IHxAttribute;
extern PACKAGE GUID IID_IEnumHxAttribute;
extern PACKAGE GUID IID_IHxRegister;
extern PACKAGE GUID IID_IHxIndex;
extern PACKAGE GUID IID_IHxSession;
extern PACKAGE GUID IID_IHxTopicList;
extern PACKAGE GUID IID_IEnumHxTopic;
extern PACKAGE GUID IID_IHxQuery;
extern PACKAGE GUID IID_IHxCollection;
extern PACKAGE GUID IID_IHxAttrNameList;
extern PACKAGE GUID IID_IHxAttrName;
extern PACKAGE GUID IID_IHxAttrValueList;
extern PACKAGE GUID IID_IHxAttrValue;
extern PACKAGE GUID IID_IEnumHxAttrValue;
extern PACKAGE GUID IID_IEnumHxAttrName;
extern PACKAGE GUID IID_IHxFilters;
extern PACKAGE GUID IID_IHxRegFilterList;
extern PACKAGE GUID IID_IHxRegFilter;
extern PACKAGE GUID IID_IEnumHxRegFilter;
extern PACKAGE GUID IID_IHxSampleCollection;
extern PACKAGE GUID IID_IHxSample;
extern PACKAGE GUID IID_IHxRegistryWalker;
extern PACKAGE GUID IID_IHxRegNamespaceList;
extern PACKAGE GUID IID_IHxRegNamespace;
extern PACKAGE GUID IID_IEnumHxRegNamespace;
extern PACKAGE GUID IID_IHxRegTitle;
extern PACKAGE GUID IID_IHxRegTitleList;
extern PACKAGE GUID IID_IEnumHxRegTitle;
extern PACKAGE GUID IID_IHxRegPlugIn;
extern PACKAGE GUID IID_IHxRegPlugInList;
extern PACKAGE GUID IID_IEnumHxRegPlugIn;
extern PACKAGE GUID IID_IHxRegisterSession;
extern PACKAGE GUID IID_IHxPlugIn;
extern PACKAGE GUID IID_IHxInitialize;
extern PACKAGE GUID IID_IHxCancel;
extern PACKAGE GUID DIID_IHxSessionEvents;
extern PACKAGE GUID DIID_IHxRegisterSessionEvents;
extern PACKAGE GUID CLASS_HxSession;
extern PACKAGE GUID CLASS_HxRegistryWalker;
extern PACKAGE GUID CLASS_HxRegisterSession;
extern PACKAGE GUID IID_IHxRegisterProtocol;
extern PACKAGE GUID CLASS_HxRegisterProtocol;
static const Shortint HxHierarchy_Book = 0x3;
static const Shortint HxHierarchy_BookPage = 0x4;
static const Shortint HxHierarchy_Page = 0x5;
static const Shortint HxHierarchy_Unknown = 0x8;
static const Shortint HxHierarchyTocFont = 0x0;
static const Shortint HxHierarchyTocFontSize = 0x1;
static const Shortint HxHierarchyTocLangId = 0x2;
static const Shortint HxHierarchyTocCharSet = 0x3;
static const Shortint HxHierarchyTocId = 0x4;
static const Shortint HxHierarchyTocFileVer = 0x5;
static const Shortint HxHierarchyTocIconFile = 0x6;
static const Shortint HxHierarchyTocParentNodeIcon = 0x7;
static const Shortint HxHierarchyTocIcon = 0x8;
static const Shortint HxTopicGetTOCTitle = 0x0;
static const Shortint HxTopicGetRLTitle = 0x1;
static const Shortint HxTopicGetHTMTitle = 0x2;
static const Shortint HxTopicGetTitleFullURL = 0x0;
static const Shortint HxTopicGetTitleFileName = 0x1;
static const Shortint HxTopicGetTitleNoDefault = 0x2;
static const Shortint HxPropIdQueryFirst = 0x0;
static const Shortint HxTopicPropIdFirst = 0x0;
static const Shortint HxHierarchy_PrintNode_Option_Node = 0x0;
static const Shortint HxHierarchy_PrintNode_Option_Children = 0x1;
static const Shortint HxQuery_No_Option = 0x0;
static const Shortint HxQuery_FullTextSearch_Title_Only = 0x1;
static const Shortint HxQuery_FullTextSearch_Enable_Stemming = 0x2;
static const Shortint HxQuery_FullTextSearch_SearchPrevious = 0x4;
static const Shortint HxQuery_KeywordSearch_CaseSensitive = 0xa;
static const Shortint HxCollectionProp_NamespaceName = 0x1;
static const Shortint HxCollectionProp_Font = 0x2;
static const Shortint HxCollectionProp_FontSize = 0x3;
static const Shortint HxCollectionProp_LangId = 0x4;
static const Shortint HxCollectionProp_CharSet = 0x5;
static const Shortint HxCollectionProp_Id = 0x6;
static const Shortint HxCollectionProp_FileVer = 0x7;
static const Shortint HxCollectionProp_CopyRight = 0x8;
static const Shortint HxRegFilterName = 0x0;
static const Shortint HxRegFilterQuery = 0x1;
static const Shortint HxIndexFont = 0x0;
static const Shortint HxIndexFontSize = 0x1;
static const Shortint HxIndexLangId = 0x2;
static const Shortint HxIndexCharSet = 0x3;
static const Shortint HxIndexTitleStr = 0x4;
static const Shortint HxIndexIsVisible = 0x5;
static const Shortint HxIndexId = 0x6;
static const Shortint HxSampleFileCopyNoOption = 0x0;
static const Shortint HxSampleFileCopyOverwrite = 0x1;
static const Shortint HxSampleFileCopyFileOnly = 0x2;
static const Shortint HxRegNamespaceTitleList = 0x0;
static const Shortint HxRegNamespacePlugInList = 0x1;
static const Shortint HxRegNamespaceName = 0x2;
static const Shortint HxRegNamespaceCollection = 0x3;
static const Shortint HxRegNamespaceDescription = 0x4;
static const Shortint HxRegNamespaceFilterList = 0x8;
static const Shortint HxRegTitleFileName = 0x0;
static const Shortint HxRegTitleIndexName = 0x1;
static const Shortint HxRegTitleQueryName = 0x2;
static const Shortint HxRegTitleId = 0x3;
static const Shortint HxRegTitleLangId = 0x4;
static const Shortint HxRegAttrQueryName = 0x5;
static const Shortint HxRegTitleHxsMediaLoc = 0x6;
static const Shortint HxRegTitleHxqMediaLoc = 0x7;
static const Shortint HxRegTitleHxrMediaLoc = 0x8;
static const Shortint HxRegTitleSampleMediaLoc = 0x9;
static const Shortint HxRegPlugInName = 0x0;
static const Shortint HxRegisterSession_IHxRegister = 0x0;
static const Shortint HxRegisterSession_IHxFilters = 0x1;
static const Shortint HxRegisterSession_IHxPlugIn = 0x2;
static const Shortint HxCancelStatus_Continue = 0x0;
static const Shortint HxCancelStatus_Cancel = 0x1;

}	/* namespace Mshelpservices_tlb */
using namespace Mshelpservices_tlb;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Mshelpservices_tlb
