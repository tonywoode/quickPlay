// VER80 = Delphi 1 but DelZip is not made for it.

(*{$IfDef VER90}
   {$Define KNOWNCOMPILER}
   {$Define DELPHI}
   {$Define VERD2D3} 
   {$DEFINE VERD5-}
{$EndIf}
{$IfDef VER93}
   {$DEFINE KNOWNCOMPILER}
   {$DEFINE CBUILDER}
   {$DEFINE CBUILDER1}  
   {$DEFINE VERD5-}
{$EndIf}
{$IfDef VER100}
   {$DEFINE KNOWNCOMPILER}
   {$DEFINE DELPHI}
   {$DEFINE DELPHI3}
   {$Define VERD2D3}  
   {$DEFINE VERD5-}
{$EndIf}
{$IfDef VER110}
   {$DEFINE KNOWNCOMPILER}
   {$DEFINE CBUILDER}
   {$ObjExportAll On}
   {$DEFINE CBUILDER3} 
   {$DEFINE VERD5-}
{$EndIf}*)
{$IfDef VER120}
   {$DEFINE KNOWNCOMPILER}
   {$DEFINE DELPHI}
   {$DEFINE DELPHI4}
   {$Define VERD4+} 
   {$DEFINE VERD5-}
{$EndIf}
{$IfDef VER125}
   {$DEFINE KNOWNCOMPILER}
   {$DEFINE CBUILDER}
   {$DEFINE CBUILDER4}
   {$ObjExportAll On}
   {$DEFINE VERD4+}  
   {$DEFINE VERD5-}
{$EndIf}
{$IfDef VER130}
 {$IfNDef BCB}   
   {$DEFINE KNOWNCOMPILER}
   {$DEFINE DELPHI}
   {$DEFINE DELPHI5}
   {$Define VERD4+} 
   {$DEFINE VERD5-}
 {$EndIf}
{$EndIf}
{$IfDef VER130}
 {$IfDef BCB}
   {$DEFINE KNOWNCOMPILER}
   {$DEFINE CBUILDER}
   {$DEFINE CBUILDER5}
   {$ObjExportAll On}
   {$DEFINE VERD4+}
   {$DEFINE VERD5-}
 {$EndIf}
{$EndIf}
{$IfDef VER140}  // EWE: Support Delphi 6 and BCB 6
 {$IfNDef BCB}
	 {$DEFINE KNOWNCOMPILER}
	 {$DEFINE DELPHI}
	 {$DEFINE DELPHI6}
   {$Define VERD6up}
	 {$Define VERD4+}
 {$EndIf}
{$EndIf}
{$IfDef VER140}
 {$IfDef BCB}
	 {$DEFINE KNOWNCOMPILER}
	 {$DEFINE CBUILDER}
	 {$DEFINE CBUILDER6}
	 {$ObjExportAll On}
	 {$DEFINE VERD4+}  
   {$Define VERD6up}
 {$EndIf}
{$EndIf}
{$IfDef VER150}  // RP: ?? Support Delphi 7 and BCB 7?
 {$IfNDef BCB}
	 {$DEFINE KNOWNCOMPILER}
	 {$DEFINE DELPHI}
	 {$DEFINE DELPHI7}
	 {$Define VERD4+}
   {$Define VERD6up}
 {$EndIf}
{$EndIf}
{$IfDef VER150}
 {$IfDef BCB}
	 {$DEFINE KNOWNCOMPILER}
	 {$DEFINE CBUILDER}
	 {$DEFINE CBUILDER7}
	 {$ObjExportAll On}
	 {$DEFINE VERD4+}   
   {$Define VERD6up}
 {$EndIf}
{$EndIf}      
{$IfDef VER160}  // RP: ?? Support Delphi 8
 {$IfNDef BCB}
	 {$DEFINE KNOWNCOMPILER}
	 {$DEFINE DELPHI}
	 {$DEFINE DELPHI8}
	 {$Define VERD4+}
   {$Define VERD6up}
 {$EndIf}
{$EndIf}
{$IfDef VER170}  // RP: Support Delphi 2005
 {$IfNDef BCB}
	 {$DEFINE KNOWNCOMPILER}
	 {$DEFINE DELPHI}
	 {$DEFINE DELPHI9}
	 {$Define VERD4+}
   {$Define VERD6up}
   {$Define VERD9up}
 {$EndIf}
{$EndIf}    
{$IfDef VER180}  // RP: Support Delphi 2006
 {$IfNDef BCB}
	 {$DEFINE KNOWNCOMPILER}
	 {$DEFINE DELPHI}
	 {$DEFINE DELPHI10}
	 {$Define VERD4+}
   {$Define VERD6up}  
   {$Define VERD9up}
   {$Define VERD10up}
 {$EndIf}
{$EndIf}
{$IfDef VER185}  // RP: Support Delphi 2007
 {$IfNDef BCB}
	 {$DEFINE KNOWNCOMPILER}
	 {$DEFINE DELPHI}
	 {$DEFINE DELPHI10}
	 {$Define VERD4+}
   {$Define VERD6up}  
   {$Define VERD9up}
   {$Define VERD10up}
   {$Define VERD11up}
 {$EndIf}
{$EndIf}
{$IfDef VER200}  // RP: Support Delphi 2009
	 {$DEFINE KNOWNCOMPILER}
	 {$DEFINE DELPHI}
	 {$DEFINE DELPHI10}
	 {$Define VERD4+}
   {$Define VERD6up}
   {$Define VERD9up}
   {$Define VERD10up}
   {$Define VERD11up}
   {$Define VERD12up}
{$EndIf}
{$IfDef VER210}  // RP: Support Delphi 2010
	 {$DEFINE KNOWNCOMPILER}
	 {$DEFINE DELPHI}
	 {$DEFINE DELPHI10}
	 {$Define VERD4+}
   {$Define VERD6up}
   {$Define VERD9up}
   {$Define VERD10up}
   {$Define VERD11up}
   {$Define VERD12up}
   {$Define VERD13up}
{$EndIf}


{$IfNDef KNOWNCOMPILER}
 {$DEFINE KNOWNCOMPILER}
 {$IfNDef BCB}
	 {$DEFINE CBUILDER}
	 {$DEFINE CBUILDER6}
	 {$ObjExportAll On}
 {$Endif}
 {$DEFINE VERD4+}
{$EndIf}

{$IfNDef KNOWNCOMPILER}
YOU ARE USING A COMPILER FOR WHICH THIS PACKAGE IS NOT YET DESIGNED!

YOU SHOULD ADD A COMPILER DEFINITION FIRST TO THE FILE ZipVers.inc

YOU CAN REMOVE THIS ERROR MESSAGE BY REMOVING THE DOT (.) ON THE LINE
"{.$DEFINE KNOWNCOMPILER}"  ABOVE

YOU HAVE BEEN WARNED !!!

{$EndIf}

{$IFNDEF VERD4+}
  {$Message 'before Delphi 4 no longer supported - does not support Int64, dynamic arrays (plus others)'}
  xxxxxxx // error
{$ENDIF}
{$IFDEF VERD6up}
{$WARN UNIT_PLATFORM OFF}
{$WARN SYMBOL_PLATFORM OFF}
{$ENDIF}
