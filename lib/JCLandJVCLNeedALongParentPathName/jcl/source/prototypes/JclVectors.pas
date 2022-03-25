{**************************************************************************************************}
{                                                                                                  }
{ Project JEDI Code Library (JCL)                                                                  }
{                                                                                                  }
{ The contents of this file are subject to the Mozilla Public License Version 1.1 (the "License"); }
{ you may not use this file except in compliance with the License. You may obtain a copy of the    }
{ License at http://www.mozilla.org/MPL/                                                           }
{                                                                                                  }
{ Software distributed under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF   }
{ ANY KIND, either express or implied. See the License for the specific language governing rights  }
{ and limitations under the License.                                                               }
{                                                                                                  }
{ The Original Code is Vector.pas.                                                                 }
{                                                                                                  }
{ The Initial Developer of the Original Code is Jean-Philippe BEMPEL aka RDM. Portions created by  }
{ Jean-Philippe BEMPEL are Copyright (C) Jean-Philippe BEMPEL (rdm_30 att yahoo dott com)          }
{ All rights reserved.                                                                             }
{                                                                                                  }
{ Contributors:                                                                                    }
{   Daniele Teti (dade2004)                                                                        }
{   Robert Marquardt (marquardt)                                                                   }
{   Robert Rossmair (rrossmair)                                                                    }
{   Florent Ouchet (outchy)                                                                        }
{                                                                                                  }
{**************************************************************************************************}
{                                                                                                  }
{ The Delphi Container Library                                                                     }
{                                                                                                  }
{**************************************************************************************************}
{                                                                                                  }
{ Last modified: $Date:: 2009-09-12 14:21:23 +0200 (sam., 12 sept. 2009)                         $ }
{ Revision:      $Rev:: 2997                                                                     $ }
{ Author:        $Author:: outchy                                                                $ }
{                                                                                                  }
{**************************************************************************************************}

unit JclVectors;

{$I jcl.inc}

interface

uses
  {$IFDEF UNITVERSIONING}
  JclUnitVersioning,
  {$ENDIF UNITVERSIONING}
  {$IFDEF SUPPORTS_GENERICS}
  JclAlgorithms,
  {$ENDIF SUPPORTS_GENERICS}
  Classes,
  JclBase, JclAbstractContainers, JclContainerIntf, JclSynch;
{$I containers\JclContainerCommon.imp}
{$I containers\JclVectors.imp}
{$I containers\JclVectors.int}
type
  TItrStart = (isFirst, isLast);

(*$JPPEXPANDMACRO JCLVECTORINT(TJclIntfVector,TJclIntfAbstractContainer,IJclIntfCollection,IJclIntfList,IJclIntfArray,IJclIntfIterator, IJclIntfEqualityComparer\,,
  protected
    function CreateEmptyContainer: TJclAbstractContainerBase; override;,,,const ,AInterface,IInterface,nil,TDynIInterfaceArray,GetObject,SetObject)*)

(*$JPPEXPANDMACRO JCLVECTORITRINT(TJclIntfVectorIterator,IJclIntfIterator,IJclIntfList,const ,AInterface,IInterface,GetObject,SetObject)*)

(*$JPPEXPANDMACRO JCLVECTORINT(TJclAnsiStrVector,TJclAnsiStrAbstractCollection,IJclAnsiStrCollection,IJclAnsiStrList,IJclAnsiStrArray,IJclAnsiStrIterator, IJclStrContainer\, IJclAnsiStrContainer\, IJclAnsiStrFlatContainer\, IJclAnsiStrEqualityComparer\,,
  protected
    function CreateEmptyContainer: TJclAbstractContainerBase; override;, override;,,const ,AString,AnsiString,'',TDynAnsiStringArray,GetString,SetString)*)

(*$JPPEXPANDMACRO JCLVECTORITRINT(TJclAnsiStrVectorIterator,IJclAnsiStrIterator,IJclAnsiStrList,const ,AString,AnsiString,GetString,SetString)*)

(*$JPPEXPANDMACRO JCLVECTORINT(TJclWideStrVector,TJclWideStrAbstractCollection,IJclWideStrCollection,IJclWideStrList,IJclWideStrArray,IJclWideStrIterator, IJclStrContainer\, IJclWideStrContainer\, IJclWideStrFlatContainer\, IJclWideStrEqualityComparer\,,
  protected
    function CreateEmptyContainer: TJclAbstractContainerBase; override;, override;,,const ,AString,WideString,'',TDynWideStringArray,GetString,SetString)*)

(*$JPPEXPANDMACRO JCLVECTORITRINT(TJclWideStrVectorIterator,IJclWideStrIterator,IJclWideStrList,const ,AString,WideString,GetString,SetString)*)

{$IFDEF SUPPORTS_UNICODE_STRING}
(*$JPPEXPANDMACRO JCLVECTORINT(TJclUnicodeStrVector,TJclUnicodeStrAbstractCollection,IJclUnicodeStrCollection,IJclUnicodeStrList,IJclUnicodeStrArray,IJclUnicodeStrIterator, IJclStrContainer\, IJclUnicodeStrContainer\, IJclUnicodeStrFlatContainer\, IJclUnicodeStrEqualityComparer\,,
  protected
    function CreateEmptyContainer: TJclAbstractContainerBase; override;, override;,,const ,AString,UnicodeString,'',TDynUnicodeStringArray,GetString,SetString)*)

(*$JPPEXPANDMACRO JCLVECTORITRINT(TJclUnicodeStrVectorIterator,IJclUnicodeStrIterator,IJclUnicodeStrList,const ,AString,UnicodeString,GetString,SetString)*)
{$ENDIF SUPPORTS_UNICODE_STRING}

  {$IFDEF CONTAINER_ANSISTR}
  TJclStrVector = TJclAnsiStrVector;
  {$ENDIF CONTAINER_ANSISTR}
  {$IFDEF CONTAINER_WIDESTR}
  TJclStrVector = TJclWideStrVector;
  {$ENDIF CONTAINER_WIDESTR}
  {$IFDEF CONTAINER_UNICODESTR}
  TJclStrVector = TJclUnicodeStrVector;
  {$ENDIF CONTAINER_UNICODESTR}

(*$JPPEXPANDMACRO JCLVECTORINT(TJclSingleVector,TJclSingleAbstractContainer,IJclSingleCollection,IJclSingleList,IJclSingleArray,IJclSingleIterator, IJclSingleContainer\, IJclSingleEqualityComparer\,,
  protected
    function CreateEmptyContainer: TJclAbstractContainerBase; override;,,,const ,AValue,Single,0.0,TDynSingleArray,GetValue,SetValue)*)

(*$JPPEXPANDMACRO JCLVECTORITRINT(TJclSingleVectorIterator,IJclSingleIterator,IJclSingleList,const ,AValue,Single,GetValue,SetValue)*)

(*$JPPEXPANDMACRO JCLVECTORINT(TJclDoubleVector,TJclDoubleAbstractContainer,IJclDoubleCollection,IJclDoubleList,IJclDoubleArray,IJclDoubleIterator, IJclDoubleContainer\, IJclDoubleEqualityComparer\,,
  protected
    function CreateEmptyContainer: TJclAbstractContainerBase; override;,,,const ,AValue,Double,0.0,TDynDoubleArray,GetValue,SetValue)*)

(*$JPPEXPANDMACRO JCLVECTORITRINT(TJclDoubleVectorIterator,IJclDoubleIterator,IJclDoubleList,const ,AValue,Double,GetValue,SetValue)*)

(*$JPPEXPANDMACRO JCLVECTORINT(TJclExtendedVector,TJclExtendedAbstractContainer,IJclExtendedCollection,IJclExtendedList,IJclExtendedArray,IJclExtendedIterator, IJclExtendedContainer\, IJclExtendedEqualityComparer\,,
  protected
    function CreateEmptyContainer: TJclAbstractContainerBase; override;,,,const ,AValue,Extended,0.0,TDynExtendedArray,GetValue,SetValue)*)

(*$JPPEXPANDMACRO JCLVECTORITRINT(TJclExtendedVectorIterator,IJclExtendedIterator,IJclExtendedList,const ,AValue,Extended,GetValue,SetValue)*)

  {$IFDEF MATH_EXTENDED_PRECISION}
  TJclFloatVector = TJclExtendedVector;
  {$ENDIF MATH_EXTENDED_PRECISION}
  {$IFDEF MATH_DOUBLE_PRECISION}
  TJclFloatVector = TJclDoubleVector;
  {$ENDIF MATH_DOUBLE_PRECISION}
  {$IFDEF MATH_SINGLE_PRECISION}
  TJclFloatVector = TJclSingleVector;
  {$ENDIF MATH_SINGLE_PRECISION}

(*$JPPEXPANDMACRO JCLVECTORINT(TJclIntegerVector,TJclIntegerAbstractContainer,IJclIntegerCollection,IJclIntegerList,IJclIntegerArray,IJclIntegerIterator, IJclIntegerEqualityComparer\,,
  protected
    function CreateEmptyContainer: TJclAbstractContainerBase; override;,,,,AValue,Integer,0,TDynIntegerArray,GetValue,SetValue)*)

(*$JPPEXPANDMACRO JCLVECTORITRINT(TJclIntegerVectorIterator,IJclIntegerIterator,IJclIntegerList,,AValue,Integer,GetValue,SetValue)*)

(*$JPPEXPANDMACRO JCLVECTORINT(TJclCardinalVector,TJclCardinalAbstractContainer,IJclCardinalCollection,IJclCardinalList,IJclCardinalArray,IJclCardinalIterator, IJclCardinalEqualityComparer\,,
  protected
    function CreateEmptyContainer: TJclAbstractContainerBase; override;,,,,AValue,Cardinal,0,TDynCardinalArray,GetValue,SetValue)*)

(*$JPPEXPANDMACRO JCLVECTORITRINT(TJclCardinalVectorIterator,IJclCardinalIterator,IJclCardinalList,,AValue,Cardinal,GetValue,SetValue)*)

(*$JPPEXPANDMACRO JCLVECTORINT(TJclInt64Vector,TJclInt64AbstractContainer,IJclInt64Collection,IJclInt64List,IJclInt64Array,IJclInt64Iterator, IJclInt64EqualityComparer\,,
  protected
    function CreateEmptyContainer: TJclAbstractContainerBase; override;,,,const ,AValue,Int64,0,TDynInt64Array,GetValue,SetValue)*)

(*$JPPEXPANDMACRO JCLVECTORITRINT(TJclInt64VectorIterator,IJclInt64Iterator,IJclInt64List,const ,AValue,Int64,GetValue,SetValue)*)

(*$JPPEXPANDMACRO JCLVECTORINT(TJclPtrVector,TJclPtrAbstractContainer,IJclPtrCollection,IJclPtrList,IJclPtrArray,IJclPtrIterator, IJclPtrEqualityComparer\,,
  protected
    function CreateEmptyContainer: TJclAbstractContainerBase; override;,,,,APtr,Pointer,nil,TDynPointerArray,GetPointer,SetPointer)*)

(*$JPPEXPANDMACRO JCLVECTORITRINT(TJclPtrVectorIterator,IJclPtrIterator,IJclPtrList,,APtr,Pointer,GetPointer,SetPointer)*)

(*$JPPEXPANDMACRO JCLVECTORINT(TJclVector,TJclAbstractContainer,IJclCollection,IJclList,IJclArray,IJclIterator, IJclObjectOwner\, IJclEqualityComparer\,,
  protected
    function CreateEmptyContainer: TJclAbstractContainerBase; override;,,; AOwnsObjects: Boolean,,AObject,TObject,nil,TDynObjectArray,GetObject,SetObject)*)

(*$JPPEXPANDMACRO JCLVECTORITRINT(TJclVectorIterator,IJclIterator,IJclList,,AObject,TObject,GetObject,SetObject)*)

  {$IFDEF SUPPORTS_GENERICS}
  TJclVectorIterator<T> = class;

(*$JPPEXPANDMACRO JCLVECTORINT(TJclVector<T>,TJclAbstractContainer<T>,IJclCollection<T>,IJclList<T>,IJclArray<T>,IJclIterator<T>, IJclItemOwner<T>\, IJclEqualityComparer<T>\,,
  protected
    type
      TDynArray = array of T;
      TVectorIterator = TJclVectorIterator<T>;
    procedure MoveArray(var List: TDynArray; FromIndex, ToIndex, Count: Integer);,,; AOwnsItems: Boolean,const ,AItem,T,Default(T),TDynArray,GetItem,SetItem)*)

(*$JPPEXPANDMACRO JCLVECTORITRINT(TJclVectorIterator<T>,IJclIterator<T>,IJclList<T>,const ,AItem,T,GetItem,SetItem)*)

  // E = External helper to compare items for equality (GetHashCode is not used)
  TJclVectorE<T> = class(TJclVector<T>, {$IFDEF THREADSAFE} IJclLockable, {$ENDIF THREADSAFE}
    IJclIntfCloneable, IJclCloneable, IJclPackable, IJclGrowable, IJclContainer,
    IJclCollection<T>, IJclList<T>, IJclArray<T>, IJclItemOwner<T>)
  private
    FEqualityComparer: IJclEqualityComparer<T>;
  protected
    procedure AssignPropertiesTo(Dest: TJclAbstractContainerBase); override;
    function CreateEmptyContainer: TJclAbstractContainerBase; override;
  public
    constructor Create(const AEqualityComparer: IJclEqualityComparer<T>; ACapacity: Integer; AOwnsItems: Boolean);
    { IJclEqualityComparer<T> }
    function ItemsEqual(const A, B: T): Boolean; override;
    property EqualityComparer: IJclEqualityComparer<T> read FEqualityComparer write FEqualityComparer;
  end;

  // F = Function to compare items for equality
  TJclVectorF<T> = class(TJclVector<T>, {$IFDEF THREADSAFE} IJclLockable, {$ENDIF THREADSAFE}
    IJclIntfCloneable, IJclCloneable, IJclPackable, IJclGrowable, IJclContainer,
    IJclCollection<T>, IJclList<T>, IJclArray<T>, IJclItemOwner<T>)
  protected
    function CreateEmptyContainer: TJclAbstractContainerBase; override;
  public
    constructor Create(const AEqualityCompare: TEqualityCompare<T>; ACapacity: Integer; AOwnsItems: Boolean);
  end;

  // I = Items can compare themselves to an other for equality
  TJclVectorI<T: IEquatable<T>> = class(TJclVector<T>, {$IFDEF THREADSAFE} IJclLockable, {$ENDIF THREADSAFE}
    IJclIntfCloneable, IJclCloneable, IJclPackable, IJclGrowable, IJclContainer,
    IJclCollection<T>, IJclList<T>, IJclArray<T>, IJclItemOwner<T>)
  protected
    function CreateEmptyContainer: TJclAbstractContainerBase; override;
  public
    { IJclEqualityComparer<T> }
    function ItemsEqual(const A, B: T): Boolean; override;
  end;
  {$ENDIF SUPPORTS_GENERICS}

{$IFDEF UNITVERSIONING}
const
  UnitVersioning: TUnitVersionInfo = (
    RCSfile: '$URL: https://jcl.svn.sourceforge.net/svnroot/jcl/tags/JCL-2.1-Build3536/jcl/source/prototypes/JclVectors.pas $';
    Revision: '$Revision: 2997 $';
    Date: '$Date: 2009-09-12 14:21:23 +0200 (sam., 12 sept. 2009) $';
    LogPath: 'JCL\source\common';
    Extra: '';
    Data: nil
    );
{$ENDIF UNITVERSIONING}

implementation

uses
  SysUtils;

(*$JPPEXPANDMACRO JCLVECTORIMP(TJclIntfVector,IJclIntfCollection,IJclIntfList,IJclIntfIterator,TJclIntfVectorIterator,,,const ,AInterface,IInterface,nil,GetObject,SetObject,FreeObject)*)

function TJclIntfVector.CreateEmptyContainer: TJclAbstractContainerBase;
begin
  Result := TJclIntfVector.Create(FSize);
  AssignPropertiesTo(Result);
end;

(*$JPPEXPANDMACRO JCLVECTORITRIMP(TJclIntfVectorIterator,IJclIntfIterator,IJclIntfList,const ,AInterface,IInterface,GetObject,SetObject)*)

(*$JPPEXPANDMACRO JCLVECTORIMP(TJclAnsiStrVector,IJclAnsiStrCollection,IJclAnsiStrList,IJclAnsiStrIterator,TJclAnsiStrVectorIterator,,,const ,AString,AnsiString,'',GetString,SetString,FreeString)*)

function TJclAnsiStrVector.CreateEmptyContainer: TJclAbstractContainerBase;
begin
  Result := TJclAnsiStrVector.Create(FSize);
  AssignPropertiesTo(Result);
end;

(*$JPPEXPANDMACRO JCLVECTORITRIMP(TJclAnsiStrVectorIterator,IJclAnsiStrIterator,IJclAnsiStrList,const ,AString,AnsiString,GetString,SetString)*)

(*$JPPEXPANDMACRO JCLVECTORIMP(TJclWideStrVector,IJclWideStrCollection,IJclWideStrList,IJclWideStrIterator,TJclWideStrVectorIterator,,,const ,AString,WideString,'',GetString,SetString,FreeString)*)

function TJclWideStrVector.CreateEmptyContainer: TJclAbstractContainerBase;
begin
  Result := TJclWideStrVector.Create(FSize);
  AssignPropertiesTo(Result);
end;

(*$JPPEXPANDMACRO JCLVECTORITRIMP(TJclWideStrVectorIterator,IJclWideStrIterator,IJclWideStrList,const ,AString,WideString,GetString,SetString)*)

{$IFDEF SUPPORTS_UNICODE_STRING}
(*$JPPEXPANDMACRO JCLVECTORIMP(TJclUnicodeStrVector,IJclUnicodeStrCollection,IJclUnicodeStrList,IJclUnicodeStrIterator,TJclUnicodeStrVectorIterator,,,const ,AString,UnicodeString,'',GetString,SetString,FreeString)*)

function TJclUnicodeStrVector.CreateEmptyContainer: TJclAbstractContainerBase;
begin
  Result := TJclUnicodeStrVector.Create(FSize);
  AssignPropertiesTo(Result);
end;

(*$JPPEXPANDMACRO JCLVECTORITRIMP(TJclUnicodeStrVectorIterator,IJclUnicodeStrIterator,IJclUnicodeStrList,const ,AString,UnicodeString,GetString,SetString)*)
{$ENDIF SUPPORTS_UNICODE_STRING}

(*$JPPEXPANDMACRO JCLVECTORIMP(TJclSingleVector,IJclSingleCollection,IJclSingleList,IJclSingleIterator,TJclSingleVectorIterator,,,const ,AValue,Single,0.0,GetValue,SetValue,FreeSingle)*)

function TJclSingleVector.CreateEmptyContainer: TJclAbstractContainerBase;
begin
  Result := TJclSingleVector.Create(FSize);
  AssignPropertiesTo(Result);
end;

(*$JPPEXPANDMACRO JCLVECTORITRIMP(TJclSingleVectorIterator,IJclSingleIterator,IJclSingleList,const ,AValue,Single,GetValue,SetValue)*)

(*$JPPEXPANDMACRO JCLVECTORIMP(TJclDoubleVector,IJclDoubleCollection,IJclDoubleList,IJclDoubleIterator,TJclDoubleVectorIterator,,,const ,AValue,Double,0.0,GetValue,SetValue,FreeDouble)*)

function TJclDoubleVector.CreateEmptyContainer: TJclAbstractContainerBase;
begin
  Result := TJclDoubleVector.Create(FSize);
  AssignPropertiesTo(Result);
end;

(*$JPPEXPANDMACRO JCLVECTORITRIMP(TJclDoubleVectorIterator,IJclDoubleIterator,IJclDoubleList,const ,AValue,Double,GetValue,SetValue)*)

(*$JPPEXPANDMACRO JCLVECTORIMP(TJclExtendedVector,IJclExtendedCollection,IJclExtendedList,IJclExtendedIterator,TJclExtendedVectorIterator,,,const ,AValue,Extended,0.0,GetValue,SetValue,FreeExtended)*)

function TJclExtendedVector.CreateEmptyContainer: TJclAbstractContainerBase;
begin
  Result := TJclExtendedVector.Create(FSize);
  AssignPropertiesTo(Result);
end;

(*$JPPEXPANDMACRO JCLVECTORITRIMP(TJclExtendedVectorIterator,IJclExtendedIterator,IJclExtendedList,const ,AValue,Extended,GetValue,SetValue)*)

(*$JPPEXPANDMACRO JCLVECTORIMP(TJclIntegerVector,IJclIntegerCollection,IJclIntegerList,IJclIntegerIterator,TJclIntegerVectorIterator,,,,AValue,Integer,0,GetValue,SetValue,FreeInteger)*)

function TJclIntegerVector.CreateEmptyContainer: TJclAbstractContainerBase;
begin
  Result := TJclIntegerVector.Create(FSize);
  AssignPropertiesTo(Result);
end;

(*$JPPEXPANDMACRO JCLVECTORITRIMP(TJclIntegerVectorIterator,IJclIntegerIterator,IJclIntegerList,,AValue,Integer,GetValue,SetValue)*)

(*$JPPEXPANDMACRO JCLVECTORIMP(TJclCardinalVector,IJclCardinalCollection,IJclCardinalList,IJclCardinalIterator,TJclCardinalVectorIterator,,,,AValue,Cardinal,0,GetValue,SetValue,FreeCardinal)*)

function TJclCardinalVector.CreateEmptyContainer: TJclAbstractContainerBase;
begin
  Result := TJclCardinalVector.Create(FSize);
  AssignPropertiesTo(Result);
end;

(*$JPPEXPANDMACRO JCLVECTORITRIMP(TJclCardinalVectorIterator,IJclCardinalIterator,IJclCardinalList,,AValue,Cardinal,GetValue,SetValue)*)

(*$JPPEXPANDMACRO JCLVECTORIMP(TJclInt64Vector,IJclInt64Collection,IJclInt64List,IJclInt64Iterator,TJclInt64VectorIterator,,,const ,AValue,Int64,0,GetValue,SetValue,FreeInt64)*)

function TJclInt64Vector.CreateEmptyContainer: TJclAbstractContainerBase;
begin
  Result := TJclInt64Vector.Create(FSize);
  AssignPropertiesTo(Result);
end;

(*$JPPEXPANDMACRO JCLVECTORITRIMP(TJclInt64VectorIterator,IJclInt64Iterator,IJclInt64List,const ,AValue,Int64,GetValue,SetValue)*)

(*$JPPEXPANDMACRO JCLVECTORIMP(TJclPtrVector,IJclPtrCollection,IJclPtrList,IJclPtrIterator,TJclPtrVectorIterator,,,,APtr,Pointer,nil,GetPointer,SetPointer,FreePointer)*)

function TJclPtrVector.CreateEmptyContainer: TJclAbstractContainerBase;
begin
  Result := TJclPtrVector.Create(FSize);
  AssignPropertiesTo(Result);
end;

(*$JPPEXPANDMACRO JCLVECTORITRIMP(TJclPtrVectorIterator,IJclPtrIterator,IJclPtrList,,APtr,Pointer,GetPointer,SetPointer)*)

(*$JPPEXPANDMACRO JCLVECTORIMP(TJclVector,IJclCollection,IJclList,IJclIterator,TJclVectorIterator,; AOwnsObjects: Boolean,AOwnsObjects,,AObject,TObject,nil,GetObject,SetObject,FreeObject)*)

function TJclVector.CreateEmptyContainer: TJclAbstractContainerBase;
begin
  Result := TJclVector.Create(FSize, False);
  AssignPropertiesTo(Result);
end;

(*$JPPEXPANDMACRO JCLVECTORITRIMP(TJclVectorIterator,IJclIterator,IJclList,,AObject,TObject,GetObject,SetObject)*)

{$IFDEF SUPPORTS_GENERICS}
(*$JPPEXPANDMACRO JCLVECTORIMP(TJclVector<T>,IJclCollection<T>,IJclList<T>,IJclIterator<T>,TVectorIterator,; AOwnsItems: Boolean,AOwnsItems,const ,AItem,T,Default(T),GetItem,SetItem,FreeItem)*)

(*$JPPEXPANDMACRO JCLVECTORITRIMP(TJclVectorIterator<T>,IJclIterator<T>,IJclList<T>,const ,AItem,T,GetItem,SetItem)*)

procedure TJclVector<T>.MoveArray(var List: TDynArray; FromIndex, ToIndex, Count: Integer);
var
  I: Integer;
begin
  if FromIndex < ToIndex then
  begin
    for I := Count - 1 downto 0 do
      List[ToIndex + I] := List[FromIndex + I];

    if (ToIndex - FromIndex) < Count then
      // overlapped source and target
      for I := 0 to ToIndex - FromIndex - 1 do
        List[FromIndex + I] := Default(T)
    else
      // independant
      for I := 0 to Count - 1 do
        List[FromIndex + I] := Default(T);
  end
  else
  begin
    for I := 0 to Count - 1 do
      List[ToIndex + I] := List[FromIndex + I];

    if (FromIndex - ToIndex) < Count then
      // overlapped source and target
      for I := Count - FromIndex + ToIndex to Count - 1 do
        List[FromIndex + I] := Default(T)
    else
      // independant
      for I := 0 to Count - 1 do
        List[FromIndex + I] := Default(T);
  end; 
end;

//=== { TJclVectorE<T> } =====================================================

constructor TJclVectorE<T>.Create(const AEqualityComparer: IJclEqualityComparer<T>; ACapacity: Integer;
  AOwnsItems: Boolean);
begin
  inherited Create(ACapacity, AOwnsItems);
  FEqualityComparer := AEqualityComparer;
end;

procedure TJclVectorE<T>.AssignPropertiesTo(Dest: TJclAbstractContainerBase);
begin
  inherited AssignPropertiesTo(Dest);
  if Dest is TJclVectorE<T> then
    TJclVectorE<T>(Dest).FEqualityComparer := FEqualityComparer;
end;

function TJclVectorE<T>.CreateEmptyContainer: TJclAbstractContainerBase;
begin
  Result := TJclVectorE<T>.Create(EqualityComparer, FSize, False);
  AssignPropertiesTo(Result);
end;

function TJclVectorE<T>.ItemsEqual(const A, B: T): Boolean;
begin
  if EqualityComparer <> nil then
    Result := EqualityComparer.ItemsEqual(A, B)
  else
    Result := inherited ItemsEqual(A, B);
end;

//=== { TJclVectorF<T> } =====================================================

constructor TJclVectorF<T>.Create(const AEqualityCompare: TEqualityCompare<T>; ACapacity: Integer;
  AOwnsItems: Boolean);
begin
  inherited Create(ACapacity, AOwnsItems);
  SetEqualityCompare(AEqualityCompare);
end;

function TJclVectorF<T>.CreateEmptyContainer: TJclAbstractContainerBase;
begin
  Result := TJclVectorF<T>.Create(EqualityCompare, FSize, False);
  AssignPropertiesTo(Result);
end;

//=== { TJclVectorI<T> } =====================================================

function TJclVectorI<T>.CreateEmptyContainer: TJclAbstractContainerBase;
begin
  Result := TJclVectorI<T>.Create(FSize, False);
  AssignPropertiesTo(Result);
end;

function TJclVectorI<T>.ItemsEqual(const A, B: T): Boolean;
begin
  if Assigned(FEqualityCompare) then
    Result := FEqualityCompare(A, B)
  else
  if Assigned(FCompare) then
    Result := FCompare(A, B) = 0
  else
    Result := A.Equals(B);
end;

{$ENDIF SUPPORTS_GENERICS}

{$IFDEF UNITVERSIONING}
initialization
  RegisterUnitVersion(HInstance, UnitVersioning);

finalization
  UnregisterUnitVersion(HInstance);
{$ENDIF UNITVERSIONING}

end.

