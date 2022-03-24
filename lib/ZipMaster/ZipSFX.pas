(*

  @author((C)2003-2005 markus stephany, delphizip@mirkes.de, all rights reserved.)
  @abstract(this unit contains the TZipSFX component which is used to create and convert self extracting zip archives)
  @lastmod(09-19-2005)

*)


unit ZipSFX;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics,
{$ifdef UNICODE}
  AnsiStrings,
{$endif}
  SFXInterface, ZipMsg, DZUtils, SFXStructs;
                  
//{$R 'res\dzsfx_all.res'}
{$IFNDEF PASDOC}
{$I DELVER.INC}
{$I SFXVER.INC}
{$ENDIF}
{$I LANG2.INC}

type
  // implementation of the sfx<->zip converter
  TCustomZipSFX = class(TComponent)
  private
    FMessageFlags: Cardinal;
    FSFXLanguage: string;
    FCommandLine: string;
    FDialogTitle: string;
    FMessage: string;
    FFallbackExtractPath: string;
    FDefaultExtractPath: string;
    FSourceFile: TFileName;
    FTargetFile: TFileName;
    FSFXPath: TFileName;
    FOptions: TSFXOptions;
    FOverwriteMode: TSFXOverwriteMode;
    FIcon: TIcon;
    FHowToDelete: THowToDeleteFile;
    procedure SetIcon(const Value: TIcon);
    function GetVersion: string;
    procedure SetVersion(const Value: string);
    procedure SetSFXLanguage(const Value: string);
    function GetSFXLanguage: string;
  protected
    (* This is the path of the binary SFX stub "DZSFX[LANG].BIN". This stub is needed to convert ZIP archives to
       self extracting EXE archives and also to create a new SFX.<br><br>
       There are at least three options to handle this stub:<br>
       1) Place the file dzsfx[lang].bin in your application directory and set the SFXPath property to
          "dzsfx[lang].bin".<br><br>
       2) Place the stub in your windows system directory and set the SFXPath property accordingly (or just
          also to "dzsfx[lang].bin").<br><br>
       3) It is also possible to compile this binary sfx stub into your application, so you don't have
          to care about the path of the dzsfx[lang].bin file anymore. Just place a {$R DZSFX[lang].RES} somewhere in
          your delphi project and forget about the SFXPath property...<br><br>
       4) To compile all available sfx language modules to your application, just add a line {$R DZSFX_ALL.RES}
          to your project.<br><br>
       <u>Notes:</u><br><br>
       the [lang] placeholder stands for the desired language of the sfx stub. currently the are sfx's in english,
       german and italian. you can change the language at runtime by setting the @link(SFXLanguage) property
       to a different language identifier (currently 'US', 'IT' and 'DE'). you may also link more than one
       dzsfx[lang].res file to your application to use this feature (and also all available sfx language modules
       at once {$R DZSFX_ALL.RES})<br><br><br><br>
    *)
    property SFXPath: TFileName read FSFXPath write FSFXPath;
    (* options which control the behaviour of the generated sfx:<br><br>
       -<u>soAskCmdLine</u>:<br>
       This is used if the SFX should execute an application or document after extraction. If this flag is set, a
       checkbox will appear on the SFX main window describing the command to execute. If the user unchecks that
       control, no command will be executed after extraction.<br><br>

       - <u>soAskFiles</u>:<br>
       If this flag is set, the user can choose which files to extract.<br><br>

       - <u>soHideOverwriteBox</u>:<br>
       If this flag is set, the user cannot change the default overwrite mode.<br><br>

       - <u>soAutoRun</u>:<br>
       If this flag is set, the SFX will automatically start extraction of its archived files at startup.<br><br>

       - <u>soNuSuccessMsg</u>:<br>
       If set, no message ("All files have been extracted") will be displayed after successful extraction.<br><br>

       - <u>soExpandVariables</u>:<br>
       If set, all string properties (Default extraction path, Commandline etc.) of the SFX can contain variables
       (like %windir% or %temp%). At runtime of the SFX those variables will be substituted by their
       actual values.<br><br>

       - <u>soInitiallyHideFiles</u>:<br>
       If set, the list showing the files to extract will not be displayed at startup of the SFX. The user will
       have to click the "Files..." button to show them.<br><br>

       - <u>soForceHideFiles</u>:<br>
       If this flag and soInitiallyHideFiles are set,  the button to display the files list will be removed from
       the SFX window, so the list cannot be shown.<br><br>

       - <u>soCheckAutoRunFileName</u>:<br>
       If this flag is set, an autorun SFX (soAutoRun flag set) will automatically extract its contents only
       if the filename of the SFX is either "setup.exe" or prefixed by an exclamation mark ("!").<br><br>

       - <u>soCanBeCancelled</u>:<br>
       If this flag is set, the user can interrupt the extraction process by either clicking the "Close" button
       or the "x" button on the title bar.<br><br>

       - <u>soDetached</u>:<br>
       If this flag is set, the sfx stub is created in a different file (to support multivolume or disk spanning
       archives).<br><br>

       - <u>soCreateEmptyDirs</u>:<br>
       If this flag is set, the files list additionally displays directory entries contained in the archive,
       so they are "extracted" (i.e. empty directories stored in the archive are generated).<br><br><br><br>
    *)
    property Options: TSFXOptions read FOptions write FOptions default [];
    (* This value controls the behaviour of the SFX when a file to be extracted would overwrite an existing
       file on disk:<br><br>
       - <u>somOverwrite</u>:<br> Always overwrite existing files<br><br>
       - <u>somSkip</u>:<br> Never overwrite existing files<br><br>
       - <u>somAsk</u>:<br> Let the user confirm overwriting.<br><br><br><br>
    *)
    property OverwriteMode: TSFXOverwriteMode read FOverwriteMode write FOverwriteMode default somAsk;
    (* This string will be stored in the created self extracting archive (SFX).<br>
       The SFX can display a message at startup. This property contains the text of this message. To avoid
       showing a message at SFX startup, leave this string empty. (see also @link(MessageFlags))<br><br>

       <u>Notes</u>:<br><br>
       - This string must not exceed 255 characters.<br><br><br><br>
    *)
    property Message: string read FMessage write FMessage;
    (* This value will be stored in the created self extracting archive (SFX).<br>
       This value controls the behaviour of the SFX startup message. It's used as the uType member of the
       MessageBox API call. (see also the @link(Message) property)<br><br>

       <u>Samples</u>:<br><br>
       - Simple information dialog showing an OK button: MB_OK or MB_ICONINFORMATION = 64<br><br>
       - Question dialog showing YES and NO buttons: MB_YESNO or MB_ICONQUESTION = 36<br><br><br><br>
    *)
    property MessageFlags: Cardinal read FMessageFlags write FMessageFlags;
    (* This string will be stored in the created self extracting archive (SFX).<br>
       The SFX will read its default extraction path from this string's content and show it up in the
       "Extract to" edit box.<br><br>

       <u>Notes</u>:<br><br>
       - This string must not exceed 255 characters.<br><br>

       - Each occurrence of &gt;&lt; (greater than + less than characters) in this string will be replaced by the
         actual value of the temporary directory at runtime of the SFX.<br><br>

       - Also environment variables can be used if soExpandVariables is set in the @link(Options) property<br><br>

       - If soExpandVariables is set, a special environment variable %TICKS% is supported, it returns the current
         internal timer counter, so rather unique extraction paths can be created.<br><br>

       - A special value &ltVOLATILE&gt; is also supported. if this "path" is being used as default extraction path,
         it'll be expanded to a unique directory under the temp path. if files have been extracted to this unique
         directory AND a command line has been successfully executed, this directory will be deleted recursively next time
         the computer gets rebooted (maybe useful for setup programs).<br><br>

       - Also reading the path from registry is possible:<br>
         If this string starts with "HK", then it's real value will be read from the registry on
         the target computer. The path describing the registry key must consist of a root key
         value (either HKLM/HKEY_LOCAL_MACHINE, HKU/HKEY_USERS or HKCU/HKEY_CURRENT_USER), a backslash and a
         subkey of this rootkey again followed by a backslash. If you want to specify the name of a value to read,
         add this value without a trailing backslash. You are also able to create a subdirectory in the path read
         from the registry, just put a pipe ("|") character after the registry path and then the name of the
         subdirectory to create (please also look at the samples section below..)<br>
         If reading the path from registry fails, you can specify a fallback path in the @link(FallbackExtractPath)
         property.<br><br>

       <u>Samples</u>:<br><br>
       "&gt;&lt;\a" => target computer's temporary directory + subdirectory "a"<br><br>

       "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\ProgramFilesDir|MyNewDir" => will read the path from the value
       "ProgramFilesDir" in the registry key HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion and add
       the value MyNewDir to this path from registry (e.g. "c:\Program Files\MyNewDir").<br><br>

       To extract to a (rather) unique path in the temporary directory, set soExpandVariables in the @link(Options)
       property and use the value "%temp%\%ticks%" as DefaultExtractPath.<br><br>

       To extract to a temporary directory that should recursively be deleted after next reboot, use the special
       value "&lt;VOLATILE&gt;".<br><br><br><br>
    *)
    property DefaultExtractPath: string read FDefaultExtractPath write FDefaultExtractPath;
    (* This string will be stored in the created self extracting archive (SFX).<br>
       It is used as the title/caption of the SFX's dialog window.<br><br>

       <u>Notes</u>:<br><br>

       - This string must not exceed 255 characters.<br><br><br><br>
    *)
    property DialogTitle: string read FDialogTitle write FDialogTitle;
    (* This string will be stored in the created self extracting archive (SFX).<br>
       After the SFX has extracted its archived files, the content of this string will be executed.<br><br>

       <u>Notes:</u><br><br>
       - This string must not exceed 255 characters.<br>
       - This string may consist of two parts separated by a pipe ("|") character. Then the part in front
         of the pipe is the application to execute, the second part is the command line argument to this
         application.<br>
       - Each occurrence of &gt;&lt; (greater than + less than characters) in this string will be replaced by
         the actual value of the extraction path at runtime of the SFX.<br>
       - Rather than executing an application, also the Installation of an .inf file is supported.<br>
       - Also environment variables can be used if soExpandVariables is set in the @link(Options) property<br><br>

       <u>Samples:</u><br><br>
       ($extractpath means the actual extraction path on the target computer)<br>
       "&gt;&lt;setup.exe|&gt;&lt;install.txt" will execute $extractpath\setup.exe with arguments
       $extractpath\install.txt.<br><br>

       "notepad.exe|&gt;&lt;readme.txt" will execute notepad.exe (it must be somewhere in the %path%) with
       arguments $extractpath\readme.txt<br><br>

       "&gt;&lt;setup.inf" will run the [DefaultInstall] section of $extractpath\setup.inf.<br><br>

       "&gt;&lt;setup.inf|.ntx86" will run the [DefaultInstall] section if Win95 (98?), but [DefaultInstall.ntx86]
       section if WinNT.<br><br>

       "%comspec% /c|&gt;&lt;startup.bat" will open the command prompt (usually command.com or cmd.exe), run the
       batch file $extractpath\startup.bat and after this close the command prompt again. (This sample only works
       if soExpandVariables is set in the @link(Options) property)<br><br><br><br>
    *)
    property CommandLine: string read FCommandLine write FCommandLine;
    (* This string will be stored in the created self extracting archive (SFX).<br>
       If you specified a registry key name in the @link(DefaultExtractPath) property and at runtime of the
       SFX this value can not be read from registry, then FallBackExtractPath will be used instead.<br><br>

       <u>Notes</u>:<br><br>

       - This string must not exceed 255 characters.<br><br><br><br>
    *)
    property FallbackExtractPath: string read FFallbackExtractPath write FFallbackExtractPath;
    (* On conversion of ZIP<->SFX EXE archives, this is the name of the file that is to be converted. *)
    property SourceFile: TFileName read FSourceFile write FSourceFile;
    (* On conversion of ZIP<->SFX EXE archives, this is the name of the target file. It is also the name of
    the new empty SFX when using the @link(CreateNewSFX) method. *)
    property TargetFile: TFileName read FTargetFile write FTargetFile;
    (* This icon will be stored in the created self extracting archive (SFX).<br>
       You can load a custom icon and replace the SFX's icon by this one.<br><br>

       <u>Notes</u>:<br><br>

       - This replacement icon must match the size of the SFX's original icon.<br><br><br><br>
    *)
    property Icon: TIcon read FIcon write SetIcon;
    (* If the file in TargetFile already exists on converting, the existing file will be deleted.
       This Option specifies how the deletion will be done:<br><br>

       -<u>htdFinal</u>: The file will be removed, this can not simply be undone.<br><br>
       -<u>htdAllowUndo</u>: The file will be moved to the Recycle Bin (if possible).<br><br><br><br>
    *)
    property HowToDelete: THowToDeleteFile read FHowToDelete write FHowToDelete default htdAllowUndo;
    (* language of the generated/read sfx ('US', 'DE', 'IT'...)<br>
       you may also use native language names if they are compiled into your app in resource form (
       so if dzsfxit.res, dzsfxes.res and dzsfxus.res are compiled into the program,
       also 'italiano', 'español' and 'english' are valid language identifiers. 
     *)
    property SFXLanguage: string read GetSFXLanguage write SetSFXLanguage;
    (* Shows the release/version of the TZipSFX component. *)
    property Version : string read GetVersion write SetVersion stored False;
    // @exclude()
    procedure DoExecuteToSFX(const bCreateNew: Boolean);
  public
    // @exclude()
    constructor Create(AOwner: TComponent); override;
    // @exclude()
    destructor Destroy; override;
    (* get short id's of all sfx language modules compiled into the application *)
    class function GetSupportedSFXLanguages: string;
    (* According to the other SFX related properties, the zip archive in SourceFile will be converted to a self
       extracting EXE archive whose filename is set in TargetFile.
    *)
    procedure ConvertToSFX;
    (* The self extracting EXE archive in SourceFile will be converted back to a regular ZIP archive whose
       filename is set in TargetFile.
    *)
    procedure ConvertToZip;
    (* Based on the extensions of the SourceFile and TargetFile properties, either one of the
       @link(ConvertToSFX) or @link(ConvertToZip) methods will be called.<br><br>
       - SourceFile = 'xyz.zip' and TargetFile = 'xyz.exe' => ConvertToSFX<br><br>
       - SourceFile = 'xyz.exe' and TargetFile = 'xyz.zip' => ConvertToZip<br><br>
       In all other cases an EDelphiZip will be raised.<br><br><br><br>
    *)
    procedure Convert;
    (* According to the other SFX related properties, an empty self extracting archive (which contains no zipped
       files) will be created, it's filename is read from TargetFile.
    *)
    procedure CreateNewSFX;
    (* The SFX properties, source and target filename can be reload from a file previously saved
       via @link(SaveToFile).<br><br>

       Some properties can also be read back from existing self extracting archives (only Delphi Zip SFX
       archives are supported)
    *)
    procedure LoadFromFile(const sFile: TFileName);
    (* You can save all current SFX properties, source and target filename of a TCustomZipSFX class into a special
       file. Later those settings can be reload using the @link(LoadFromFile) method.
    *)
    procedure SaveToFile(const sFile: TFileName);
  end;

  // published sfx<->zip converter
  TZipSFX = class(TCustomZipSFX)
  published
    { Published-Deklarationen }
    // see inherited @inherited
    property SFXPath;
    // see inherited @inherited
    property Options;
    // see inherited @inherited
    property OverwriteMode;
    // see inherited @inherited
    property Message;
    // see inherited @inherited
    property MessageFlags;
    // see inherited @inherited
    property DefaultExtractPath;
    // see inherited @inherited
    property DialogTitle;
    // see inherited @inherited
    property CommandLine;
    // see inherited @inherited
    property FallbackExtractPath;
    // see inherited @inherited
    property SourceFile;
    // see inherited @inherited
    property TargetFile;
    // see inherited @inherited
    property Icon;
    // see inherited @inherited
    property Version;
    // see inherited @inherited
    property SFXLanguage;
  end;

// @exclude()
procedure Register;

implementation
uses
  ShellApi;

const
 {File Extensions}
  ExtZip = 'zip';
  DotExtZip = '.'+ExtZip;
  ExtExe = 'exe';
  DotExtExe = '.'+ExtExe;
  ExtBin = 'bin';
  DotExtBin = '.'+ExtBin;
 {Identifiers}
  DzSfxID = 'DZSFX';
  DzSfxSemicolonID = DzSfxID+';';
  BinID = '_BIN';
  BinLangID = BinID + '_LANG';
  BinSizeID = BinID + '_SIZE';

 type
  // locate and load DZSFX.BIN in a stream
  TSFXBinStream = class(TMemoryStream)
  private
    FSFXPath: TFileName;
  public
    constructor Create(sPathToSFX: TFileName; SLanguage: string);
    property SFXPath : TFileName read FSFXPath;
  end;

  // stream which controls correction of central structures when writing to another stream
  TZipArchiveStream = class(TStream)
  private
    FEOC: TZipEndOfCentral;
    FFile: TFileStream;
    FPosition: Integer;
    FFilename: TFileName;
  public
    constructor CreateNew;
    constructor CreateFromFile(const sArchive: string);
    destructor Destroy; override;
    function Seek(Offset: Longint; Origin: Word): Longint; override;
    procedure GotoZipData;
    function Read(var Buffer; Count: Longint): Longint; override;
    function Write(const Buffer; Count: Longint): Longint; override;
    // copy local headers, data and central structures to the stream
    procedure CopyTo(str: TStream);
    // copy a stripped version of the central structures (no ext data and comments)
    // to the stream
    procedure CopyStrippedCentralDirTo(str: TStream);
  end;

  // create a valid TSFXFileHeader and store it in a stream
  // or read sfx options from the given stream
  TSFXHeaderStream = class(TMemoryStream)
  private
    FZipSFX: TCustomZipSFX;
    FStream: TStream;
  private
    procedure ExtractFirstIcon(const sFile: string);
  protected
    function GetNewHeaderProperties: Boolean; virtual;
    function GetOldHeaderProperties: Boolean; virtual;
  public
    constructor Create(oZipSFX: TCustomZipSFX);
    constructor CreateFromZipStream(str: TZipArchiveStream; oZipSFX: TCustomZipSFX);
    constructor CreateFromFile(const sFile: TFileName; oZipSFX: TCustomZipSFX);
    procedure WriteDetachedHeader(str: TStream; const FileName: string);
  end;



procedure Register;
begin
  RegisterComponents('Delphi Zip', [TZipSFX]);
end;


type
  TFileNameIs = (fiExe, fiZip, fiOther, fiEmpty);


var
  // languages compiled into the application
  _INCLUDED_LANGUAGES: TStrings;


// get the kind of filename
function GetFileNameKind(const sFile: TFileName): TFileNameIs;
var
  sExt: string;
begin
  if sFile = ''
  then
    Result := fiEmpty
  else
  begin
    sExt := LowerCase(ExtractFileExt(sFile));
    if sExt = DotExtZip
    then
      Result := fiZip
    else
      if sExt = DotExtExe
      then
        Result := fiExe
        else
          Result := fiOther;
  end;
end;

{ TCustomZipSFX }

constructor TCustomZipSFX.Create(AOwner: TComponent);
begin
  inherited;
  FIcon := TIcon.Create;
  FOptions := [];
  FOverwriteMode := somAsk;
  FSFXLanguage := AnsiUpperCase(DZSFX_LANG); // set at compile time when using make -DLANG=<lg> vcl
  FSFXPath := DzSfxID+FSFXLanguage+DotExtBin;
  FHowToDelete := htdAllowUndo;
end;

procedure TCustomZipSFX.Convert;
var
  fiSrc, fiTrg: TFileNameIs;
begin
  // check source and target filename
  fiSRC := GetFileNameKind(FSourceFile);
  fiTrg := GetFilenameKind(FTargetFile);
  if (fiSrc in [fiEmpty, fiOther]) or (fiTrg in [fiEmpty, fiOther])
  then
    raise EDelphiZip.CreateResDisp(GE_NoZipSpecified, True);

  if (fiSrc = fiZip) and (fiTrg = fiExe)
  then
    ConvertToSFX
  else
    if (fiSrc = fiExe) and (fiTrg = fiZip)
    then
      ConvertToZip
    else
    raise EDelphiZip.CreateResDisp(CZ_WrongConvert, True);
end;

procedure TCustomZipSFX.ConvertToSFX;
begin
  DoExecuteToSFX(False);
end;

procedure TCustomZipSFX.ConvertToZip;
var
  strIn: TZipArchiveStream; // automatically adjust central offsets
  strOut: TFileStream; // output file
  strHdr: TSFXHeaderStream; // read back sfx options
begin
  if not FileExists(FSourceFile)
  then
    raise EDelphiZip.CreateResDisp(GE_NoZipSpecified, True);

  if FileExists(FTargetFile)
  then
    EraseFile(FTargetFile, FHowToDelete);

  strIn := TZipArchiveStream.CreateFromFile(FSourceFile);
  try
    strOut := TFileStream.Create(FTargetFile, fmCreate);
    try
      strIn.GotoZipData;
      strIn.CopyTo(strOut);
      strHdr := TSFXHeaderStream.CreateFromZipStream(strIn, self);
      try
      finally
        strHdr.Free;
      end;
    finally
      strOut.Free;
    end;
  finally
    strIn.Free;
  end;
end;

procedure TCustomZipSFX.CreateNewSFX;
begin
  DoExecuteToSFX(True);
end;

destructor TCustomZipSFX.Destroy;
begin
  FIcon.Free;
  inherited;
end;

procedure TCustomZipSFX.SetIcon(const Value: TIcon);
begin
  FIcon.Assign(Value);
end;

procedure TCustomZipSFX.DoExecuteToSFX(const bCreateNew: Boolean);
var
  strSFX: TSFXBinStream;  // either loaded from resource or from file
  strZip: TZipArchiveStream; // automatically adjust central offsets
  strOut: TFileStream; // output file
  strHdr: TSFXHeaderStream;
begin
  // try to get the sfx header
  // spanning is not supported when no zip file is specified
  if not FileExists(FSourceFile) and ((not bCreateNew) or (soDetached in Options))
  then
    raise EDelphiZip.CreateResDisp(GE_NoZipSpecified, True);

  strSFX := TSFXBinStream.Create(FSFXPath, FSFXLanguage);
  FSFXPath := strSFX.SFXPath;

  try
    if FileExists(FTargetFile)
    then
      EraseFile(FTargetFile, FHowToDelete);

    strOut := TFileStream.Create(FTargetFile, fmCreate);
    try
      // copy the dzsfx.bin
      strOut.CopyFrom(strSFX, strSFX.Size);

      // create the header
      strHdr := TSFXHeaderStream.Create(self);
      try
        strOut.CopyFrom(strHdr, strHdr.Size);

        // if separate sfx, create an additional header
        if soDetached in Options then
          strHdr.WriteDetachedHeader(strOut, UpperCase(ExtractFileName(FSourceFile)));

      finally
        strHdr.Free;
      end;

      if bCreateNew
      then
        strZip := TZipArchiveStream.CreateNew
      else
        strZip := TZipArchiveStream.CreateFromFile(FSourceFile);
      try
        if soDetached in Options then
          strZip.CopyStrippedCentralDirTo(strOut)
        else
          strZip.CopyTo(strOut);

        if Assigned(FIcon) and (not FIcon.Empty)
        then
          ReplaceIcon(strOut, FIcon);

      finally
        strZip.Free;
      end;

    finally
      strOut.Free;
    end;

  finally
    strSFX.Free;
  end;
end;

const
  _SIG_ = Cardinal($abcdef88);

type
  TZipSFXFileHeader = packed record
    Sig: Cardinal;
    iLenSrc,
    iLenTrg,
    iLenIco: Integer;
    fHowToDelete: THowToDeleteFile;
  end;

procedure TCustomZipSFX.LoadFromFile(const sFile: TFileName);
var
  strHdr: TSFXHeaderStream;
  rec: TZipSFXFileHeader;
  strIn: TFileStream;
  strMem: TMemoryStream;
  hMod: THandle;
  szBuf: array[0..MAX_PATH] of Char;
  srID: string;
begin
  strHdr := TSFXHeaderStream.CreateFromFile(sFile, self);
  strHdr.Free;
  strIn := TFileStream.Create(sFile, fmOpenRead or fmShareDenyNone);
  try
    rec.Sig := 0;
    strIn.Read(rec, sizeof(rec));
    if rec.Sig = _SIG_ then
    begin
      SetLength(FSourceFile, rec.iLenSrc);
      if rec.iLenSrc > 0
      then
        strIn.Read(FSourceFile[1], rec.iLenSrc);
      SetLength(FTargetFile, rec.iLenTrg);
      if rec.iLenTrg > 0
      then
        strIn.Read(FTargetFile[1], rec.iLenTrg);
      FHowToDelete := rec.fHowToDelete;

      if rec.iLenIco > 0 then
      begin
        strMem := TMemoryStream.Create;
        try
          strMem.CopyFrom(strIn, rec.iLenIco);
          strMem.Position := 0;
          FIcon.LoadFromStream(strMem);
        finally
          strMem.Free;
        end;
      end;
    end
  finally
    strIn.Free;
  end;

  // try to get the language from the sfx
  hMod := LoadLibraryEx(PChar(sFile), 0, DONT_RESOLVE_DLL_REFERENCES or LOAD_LIBRARY_AS_DATAFILE);
  if hMod <> 0
  then
    try
      FillChar(szBuf, sizeof(szBuf), #0);
      if LoadString(hMod, 1024 (* ID of the dzsfx.bin identifier string *), szBuf, sizeof(szBuf)) <> 0 then

      begin
        SetString(srID, szBuf, StrLen(szBuf));
        srID := AnsiUpperCase(srID);
        if Pos(DzSfxSemicolonID, srID) = 1 then
        begin
          Delete(srID, 1, Length(DzSfxSemicolonID));
          if Pos(';', srID) > 1 then
          begin
            Delete(srID, Pos(';', srID), MaxInt);
            FSFXLanguage := srID;
          end;
        end;
      end;
    finally
      FreeLibrary(hMod);
    end;
end;

procedure TCustomZipSFX.SaveToFile(const sFile: TFileName);
var
  strIco: TMemoryStream;
  strHdr: TSFXHeaderStream;
  strOut: TFileStream;
  rec: TZipSFXFileHeader;
  strEOC: TZipArchiveStream;
begin
  rec.Sig := _SIG_;
  rec.iLenSrc := Length(FSourceFile);
  rec.iLenTrg := Length(FTargetFile);
  rec.fHowToDelete := FHowToDelete;
  strIco := TMemoryStream.Create;
  try
    try
      FIcon.SaveToStream(strIco);
      rec.iLenIco := strIco.Size;
    except
      rec.iLenIco := 0;
    end;

    strOut := TFileStream.Create(sFile, fmCreate);
    try
      strOut.Write(rec, sizeof(rec));
      if rec.iLenSrc > 0
      then
        strOut.Write(FSourceFile[1], rec.iLenSrc);
      if rec.iLenTrg > 0
      then
        strOut.Write(FTargetFile[1], rec.iLenTrg);
      if rec.iLenIco > 0 then
      begin
        strIco.Position := 0;
        strOut.CopyFrom(strIco, strIco.Size);
      end;

      strHdr := TSFXHeaderStream.Create(self);
      try
        strOut.CopyFrom(strHdr, strHdr.Size);
      finally
        strHdr.Free;
      end;

      strEOC := TZipArchiveStream.CreateNew;
      try
        strEOC.GotoZipData;
        strEOC.CopyTo(strOut);
      finally
        strEOC.Free;
      end;

    finally
      strOut.Free;
    end;
  finally
    strIco.Free;
  end;

end;

function TCustomZipSFX.GetVersion: string;
begin
  Result := SFX_RELEASE;
end;

procedure TCustomZipSFX.SetVersion(const Value: string);
begin
  //
end;


procedure TCustomZipSFX.SetSFXLanguage(const Value: string);
begin
  if AnsiUpperCase(FSFXLanguage) <> AnsiUpperCase(Value) then
  begin
    FSFXLanguage := AnsiUpperCase(Value);
    with _INCLUDED_LANGUAGES
    do
      if IndexOfName(FSFXLanguage) > -1
      then
        FSFXLanguage := Values[Names[IndexOfName(FSFXLanguage)]];
    FSFXPath := DzSfxID+FSFXLanguage+DotExtBin;
  end;
end;

class function TCustomZipSFX.GetSupportedSFXLanguages: string;
var
  LIntLoop: Integer;
begin
  Result := '';
  with _INCLUDED_LANGUAGES
  do
    if Bool(Count)
    then
      for LIntLoop := 0 to Pred(Count)
      do
        Result := Result+Names[LIntLoop]+#13#10;
end;

function TCustomZipSFX.GetSFXLanguage: string;
var
  LIntLoop: Integer;
begin
  Result := AnsiUpperCase(FSFXLanguage);
  with _INCLUDED_LANGUAGES
  do
    if Bool(Count)
    then
      for LIntLoop := 0 to Pred(Count)
      do
        if Values[Names[LIntLoop]] = FSFXLanguage then
        begin
          Result := Names[LIntLoop];
          Break;
        end;
end;

{ TSFXBinStream }

constructor TSFXBinStream.Create(sPathToSFX: TFileName; SLanguage: string);
var
  inst: cardinal;
  hRes,
  hFindSFX,
  hFindSize: THandle;
  pData: Pointer;
  cSize: Cardinal;
  pSearch: array[0..MAX_PATH] of Char;
  bOK: Boolean;
begin
  inherited Create;
  // load it either from resource (if dzsfx##.res has been linked to the executable)
  // or by loading from file in SFXPath
  bOk := False;
  pData := nil;

  inst := HInstance;
  hFindSFX := FindResource(inst, PChar(DzSfxID+SLanguage+BinID), RT_RCDATA);
  if (HFindSFX = 0) and ModuleIsLib then
  begin
    inst := MainInstance;     
    hFindSFX := FindResource(inst, PChar(DzSfxID+SLanguage+BinID), RT_RCDATA);
  end;
//  hFindSFX := FindResource(HInstance, PChar(DzSfxID+SLanguage+BinID), RT_RCDATA);
  if hFindSFX <> 0 then
  begin
    hFindSize := FindResource(inst{HInstance}, PChar(DzSfxID+SLanguage+BinSizeID), RT_RCDATA);
    if (hFindSize <> 0) and (SizeOfResource(inst{HInstance}, hFindSize) >= sizeof(Cardinal)) then
    begin
      hRes := LoadResource(inst{HInstance}, hFindSize);
      if hRes <> 0 then
      begin
        pData := LockResource(hRes);
        if pData <> nil then
        begin
          cSize := PCardinal(pData)^;
          if (cSize > 0) and (SizeOfResource(inst{HInstance}, hFindSFX) >= cSize) then
          begin
            hRes := LoadResource(inst{HInstance}, hFindSFX);
            if hRes <> 0 then
            begin
              pData := LockResource(hRes);
              if pData <> nil then
              begin
                Write(pData^, cSize);
                Seek(0, soFromBeginning);
                bOK := True;
              end;
            end;
          end;
        end;
      end;
    end;
  end;

  // not found in exe image, so try to load it from file
  if not bOK then
  begin

    (*RP here FSFXPath has not been set - so added next line *)
    FSFXPath := sPathToSFX;
    // to make easier to use - just need to specify path
    if (FSFXPath='') or (FSFXPath[length(FSFXPath)]='\')  then
      FSFXPath := FSFXPath + DzSfxID+SLanguage+DotExtBin;
    (*RP  end of change  *)

    if not FileExists(FSFXPath) then
    begin
      SetString(FSFXPath, pSearch, SearchPath(nil,
        PChar(DzSfxID+SLanguage+DotExtBin), nil, sizeof(pSearch), pSearch, PChar(pData)));
    end;
    if not FileExists(FSFXPath) then
    begin
      SetString(FSFXPath, pSearch, SearchPath(nil,
        PChar(DzSfxID+DZSFX_LANG+DotExtBin), nil, sizeof(pSearch), pSearch, PChar(pData)));
    end;
    if not FileExists(FSFXPath)
    then
      raise EDelphiZip.CreateResFmt( SF_NoZipSFXBin, [DzSfxID+SLanguage]);
//      raise EDelphiZip.CreateResDisp(SF_NoZipSFXBin, True);

    LoadFromFile(FSFXPath);
    Seek(0, soFromBeginning);
  end;
end;


{ TSFXHeaderStream }

constructor TSFXHeaderStream.Create(oZipSFX: TCustomZipSFX);
var
  iSize: Integer;
  p: PAnsiChar;
begin
  inherited Create;

  FStream := nil;
  FZipSFX := oZipSFX;

  // check sizes of the strings
  with oZipSFX do
  begin
//    if (Length(FMessage) > 255) or
//       (Length(FDefaultExtractPath) > 255) or
//       (Length(FDialogTitle) > 255) or
//       (Length(FCommandLine) > 255) or
//       (Length(FFallbackExtractPath) > 255)
//    then
//      raise EDelphiZip.CreateResDisp(SF_StringToLong, True);

    if (Length(FMessage) > 255) then
      raise EDelphiZip.CreateResDisp(SF_MsgTooLong, True);
    if (Length(FDefaultExtractPath) > 255) then
      raise EDelphiZip.CreateResDisp(SF_DefPathTooLong, True);
    if (Length(FDialogTitle) > 255) then
      raise EDelphiZip.CreateResDisp(SF_DlgTitleTooLong, True);
    if (Length(FCommandLine) > 255) then
      raise EDelphiZip.CreateResDisp(SF_CmdLineTooLong, True);
    if (Length(FFallbackExtractPath) > 255) then
      raise EDelphiZip.CreateResDisp(SF_FBkPathTooLong, True);

    iSize := sizeof(TSFXFileHeader) + Length(FMessage) + Length(FDefaultExtractPath) +
             Length(FDialogTitle) + Length(FCommandLine) + Length(FFallbackExtractPath);

    while ((iSize mod 4) <> 0) do Inc(iSize);

    // set correct header size
    {$IFNDEF DELPHI3UP}
    SetSize(iSize + sizeof(TSFXFileEndOfHeader));
    {$ELSE}
    Size := iSize + sizeof(TSFXFileEndOfHeader);
    {$ENDIF}
    with PSFXFileHeader(Memory)^ do
    begin
      Signature := SFX_HEADER_SIG;
      Size := iSize;
      Options := FOptions;
      DefOVW := FOverwriteMode;
      CaptionSize := Length(FDialogTitle);
      PathSize := Length(FDefaultExtractPath);
      CmdLineSize := Length(FCommandLine);
      RegFailPathSize := Length(FFallbackExtractPath);
      StartMsgSize := Length(FMessage);
      StartMsgType := FMessageFlags;

      p := PAnsiChar(Memory) + sizeof(TSFXFileHeader);
      if CaptionSize > 0 then
      begin
        StrPCopy(p, AnsiString(FDialogTitle));
        p := p + CaptionSize;
      end;
      if PathSize > 0 then
      begin
        StrPCopy(p, AnsiString(FDefaultExtractPath));
        p := p + PathSize;
      end;
      if CmdLineSize > 0 then
      begin
        StrPCopy(p, AnsiString(FCommandLine));
        p := p + CmdLineSize;
      end;
      if RegFailPathSize > 0 then
      begin
        StrPCopy(p, AnsiString(FFallbackExtractPath));
        p := p + RegFailPathSize;
      end;
      if StartMsgSize > 0
      then
        StrPCopy(p, AnsiString(FMessage));

      with PSFXFileEndOfHeader(PAnsiChar(Memory)+iSize)^ do
      begin
        Signature := SFX_HEADER_END_SIG;
        HeaderSize := iSize;
      end;
    end;
  end;
  Seek(0, soFromBeginning);
end;

constructor TSFXHeaderStream.CreateFromFile(const sFile: TFileName;
  oZipSFX: TCustomZipSFX);
begin
  inherited Create;

  FStream := TFileStream.Create(sFile, fmOpenRead or fmShareDenyNone);
  try
    FZipSFX := oZipSFX;

    try
      FStream.Seek(FindStartOfZipData(FStream), soFromBeginning);
    except
      FStream.Seek(0, soFromEnd);
    end;

    if not (GetNewHeaderProperties or GetOldHeaderProperties) then
      raise EDelphiZip.CreateResDrive(CZ_UnknownHeader, sFile);

    ExtractFirstIcon(sFile);

  finally
    FStream.Free;
    FStream := nil;
  end;
end;

constructor TSFXHeaderStream.CreateFromZipStream(str: TZipArchiveStream; oZipSFX: TCustomZipSFX);
begin
  inherited Create;

  FStream := str;
  FZipSFX := oZipSFX;

  str.GotoZipData;
  if str.Position > (sizeof(TSFXFileHeader) + sizeof(TSFXFileEndOfHeader)) then
  begin
    // try to find an new sfx header
    if not GetNewHeaderProperties
    then
      GetOldHeaderProperties;

    ExtractFirstIcon(str.FFilename);
  end;
end;

procedure TSFXHeaderStream.ExtractFirstIcon(const sFile: string);
var
  hIco: HICON;
begin
  hIco := ExtractIcon(HInstance, PChar(sFile),0);
  if hIco > 1
  then
    FZipSFX.FIcon.Handle := hIco;
end;

function TSFXHeaderStream.GetNewHeaderProperties: Boolean;
var
  recEnd: TSFXFileEndOfHeader;
  recDEnd: TSFXDetachedHeader;
  recSFX: TSFXFileHeader;
  iPos: Integer;
begin
  iPos := FStream.Position;
  try
    Result := False;
    // check if a detached header
    FStream.Seek(-sizeof(recDEnd), soFromCurrent);
    if (FStream.Read(recDEnd, sizeof(recDEnd)) = sizeof(recDEnd)) and
      (recDEnd.Signature = SFX_DETACHED_HEADER_END_SIG) then
      FStream.Seek(-((sizeof(recDEnd)*2)+(recDEnd.NameLen+recDEnd.ExtLen)), soFromCurrent);



    FStream.Seek(- sizeof(recEnd), soFromCurrent);
    if (FStream.Read(recEnd, sizeof(recEnd)) <> sizeof(recEnd)) or
       (recEnd.Signature <> SFX_HEADER_END_SIG) or
       (FStream.Seek(-sizeof(recEnd)-recEnd.HeaderSize, soFromCurrent) = -1) or

       (FStream.Read(recSFX, sizeof(recSFX)) <> sizeof(recSFX)) or
       (recSFX.Signature <> SFX_HEADER_SIG) then
      Exit;

    Result := True;

    with FZipSFX, recSFX do
    begin
      FOverwriteMode := DefOVW;
      FOptions := Options;
      FMessageFlags := StartMsgType;

      if CaptionSize > 0 then
      begin
        SetLength(FDialogTitle, CaptionSize);
        if FStream.Read(FDialogTitle[1], CaptionSize) <> CaptionSize
        then
          raise EDelphiZip.CreateResDisp(CZ_SFXTypeUnknown, True);
      end
      else
        FDialogTitle := '';


      if PathSize > 0 then
      begin
        SetLength(FDefaultExtractPath, PathSize);
        if FStream.Read(FDefaultExtractPath[1], PathSize) <> PathSize
        then
          raise EDelphiZip.CreateResDisp(CZ_SFXTypeUnknown, True);
      end
      else
        FDefaultExtractPath := '';

      if CmdLineSize > 0 then
      begin
        SetLength(FCommandLine, CmdLineSize);
        if FStream.Read(FCommandLine[1], CmdLineSize) <> CmdLineSize
        then
          raise EDelphiZip.CreateResDisp(CZ_SFXTypeUnknown, True);
      end
      else
        FCommandLine := '';

      if RegFailPathSize > 0 then
      begin
        SetLength(FFallbackExtractPath, RegFailPathSize);
        if FStream.Read(FFallbackExtractPath[1], RegFailPathSize) <> RegFailPathSize
        then
          raise EDelphiZip.CreateResDisp(CZ_SFXTypeUnknown, True);
      end
      else
        FFallbackExtractPath := '';

      if StartMsgSize > 0 then
      begin
        SetLength(FMessage, StartMsgSize);
        if FStream.Read(FMessage[1], StartMsgSize) <> StartMsgSize
        then
          raise EDelphiZip.CreateResDisp(CZ_SFXTypeUnknown, True);
      end
      else
        FMessage := '';
    end;

  finally
    FStream.Position := iPos;
  end;
end;

function TSFXHeaderStream.GetOldHeaderProperties: Boolean;
var
  iPos: Integer;
  pData: PAnsiChar;
  iMax, i: Integer;
  bFlags: Byte;
  pLoop: PAnsiChar; // loop pchar
begin
  Result := False;
  iPos := FStream.Position;
  try
    iMax := 1032; // taken from zimstr.pas, hope it's enough for old headers ;-)
    if iMax > iPos
    then
      iMax := iPos;

    GetMem(pData, iMax+1);
    try

      // go to iMaxPos - iMax and read a complete buffer
      FStream.Seek(-iMax, soFromCurrent);
      if FStream.Read(pData^, iMax) <> iMax
      then
        raise EDelphiZip.CreateResDisp(DS_NoValidZip, True);

      for i := 0 to iMax - 3 do
      begin
        if (pData[i] = 'M') and (pData[i + 1] = 'P') and ((pData[i + 2] = 'U') or (pData[i + 2] = 'V'))
        then
          with FZipSFX do
            begin
              Result := True;
              // read back the original values from the MPU/V block.
              FOptions := [soCheckAutoRunFileName]; // compatibility
              FOverwriteMode := somAsk;
              bFlags := Byte( pData[i + 3] );
              if (bFlags and  1) > 0 then Include(FOptions, soAskCmdLine);
              if (bFlags and  2) > 0 then Include(FOptions, soAskFiles);
              if (bFlags and  4) > 0 then Include(FOptions, soHideOverWriteBox);
              if (bFlags and  8) > 0 then FOverwriteMode := somOverwrite;
              if (bFlags and 16) > 0 then FOverwriteMode := somSkip;
              //if not (bFlags and 32 > 0) then SFXOptions := SFXOptions + [SFXCheckSize];
              if (bFlags and 64) > 0 then Include(FOptions, soAutoRun);

              if pData[i + 2] = 'U' then
              begin
                SetString( FDialogTitle, pData + i + 7, Integer( pData[i + 4] ) );
                SetString( FDefaultExtractPath, pData + i + Integer( pData[i + 4] ) + 7, Integer( pData[i + 5] ) );
                SetString( FCommandLine, pData + i + Integer( pData[i + 4] ) + Integer( pData[i + 5] ) + 7, Integer( pData[i + 6] ) );

                FMessage:='';
                FFallbackExtractPath:= '';
              end
              else
              begin
                if (bFlags and 128) > 0 then Include(FOptions, soNoSuccessMsg);
                pLoop := pData + i + 8;
                SetString( FDialogTitle, pLoop + 1, Integer( pLoop[0] ) );
                pLoop := pLoop + Integer( pLoop[0] ) + 1;
                SetString( FDefaultExtractPath, pLoop + 1, Integer( pLoop[0] ) );

                pLoop := pLoop + Integer( pLoop[0] ) + 1;
                SetString( FCommandLine, pLoop + 1, Integer( pLoop[0] ) );
                pLoop := pLoop + Integer( pLoop[0] ) + 1;
                SetString( FMessage, pLoop + 1, Integer( pLoop[0] ) );
                FFallbackExtractPath:= '';
                if (FMessage <> '') then
                  case FMessage[1] of
                    #1:
                      begin
                        FMessageFlags := MB_OKCANCEL or MB_ICONINFORMATION;
                        Delete(FMessage, 1,1);
                      end;
                    #2:
                      begin
                        FMessageFlags := MB_YESNO or MB_ICONQUESTION;
                        Delete(FMessage, 1,1);
                      end;
                  else
                    FMessageFlags := MB_OK;
                  end
                else
                  FMessageFlags := MB_OK;
              end;
              Break;
            end;
      end;
    finally
      FreeMem(pData);
    end;

  finally
    FStream.Position := iPos;
  end;
end;

procedure TSFXHeaderStream.WriteDetachedHeader(str: TStream;
  const FileName: string);
var
  recDetached: TSFXDetachedHeader;
  sName,
  sExt: string;
begin
  sName := ChangeFileExt(ExtractFileName(FileName),'');
  sExt := ExtractFileExt(FileName);
  if Copy(sExt,1,1) = '.' then
    Delete(sExt,1,1);
  // write a detached_header into the sfx "archive"
  recDetached.Signature := SFX_DETACHED_HEADER_SIG;
  recDetached.NameLen := Length(sName);
  recDetached.ExtLen := Length(sExt);
  str.WriteBuffer(recDetached, sizeof(recDetached));
  if Length(sName) <> 0 then
    str.WriteBuffer(sName[1], Length(sName));
  if Length(sExt) <> 0 then
    str.WriteBuffer(sExt[1], Length(sExt));

  // write an end header for backward searching
  recDetached.Signature := SFX_DETACHED_HEADER_END_SIG;
  str.WriteBuffer(recDetached, sizeof(recDetached));
end;

{ TZipArchiveStream }

constructor TZipArchiveStream.CreateFromFile(const sArchive: string);
begin
  inherited Create;
  FFileName := sArchive;
  FFile := TFileStream.Create(sArchive, fmOpenRead or fmShareDenyNone);
  Position := 0;
end;

constructor TZipArchiveStream.CreateNew;
begin
  inherited Create;
  FFile := nil;
  FFileName := '';
  FillChar(FEOC, sizeof(FEOC), #0);
  FEOC.HeaderSig := ZipEndOfCentralSig;
  Position := 0;
end;

destructor TZipArchiveStream.Destroy;
begin
  if Assigned(FFile)
  then
    FFile.Free;
  FFile := nil;
  inherited;
end;

procedure TZipArchiveStream.CopyTo(str: TStream);
var
  iPosOFEOC,
    iNewSize,
    iDelta,
    iSize,
    iPos: Integer;
begin
  // adjust the offsets according to str's size
  iNewSize := str.Size;
  iPos := Position;
  if not Assigned(FFile) then
  begin
    FEOC.CentralOffSet := iNewSize;
    str.CopyFrom(self, sizeof(FEOC)-iPos);
  end
  else
  begin
    iPosOfEOC := ReadEndOfCentral(self, FEOC);
    Position := iPos;
    iDelta := iPosOfEOC - Integer(FEOC.CentralOffset + FEOC.CentralSize);
    iSize := (Integer(FEOC.CentralOffSet) + iDelta) -iPos;
    // copy local data
    if  iSize > 0
    then
      str.CopyFrom(self, iSize);
    // copy and adjust central structures
    CopyAndAdjustCentralStructures(self, str, FEOC.CentralEntries,
      iDelta + iNewSize -iPos, FEOC.ThisDiskNo)
  end;
end;

procedure TZipArchiveStream.CopyStrippedCentralDirTo(str: TStream);
var
  iPosOFEOC,
    iNewSize,
    iDelta,
    iSize,
    iPos: Integer;
begin
  // adjust the offsets according to str's size
  iNewSize := str.Size;
  iPos := Position;
  if not Assigned(FFile) then
  begin
    FEOC.CentralOffSet := iNewSize;
    str.CopyFrom(self, sizeof(FEOC)-iPos);
  end
  else
  begin
    iPosOfEOC := ReadEndOfCentral(self, FEOC);
    Position := iPos;
    iDelta := iPosOfEOC - Integer(FEOC.CentralOffset + FEOC.CentralSize);
    iSize := (Integer(FEOC.CentralOffSet) + iDelta) -iPos;
    Seek(iSize, soFromCurrent);
    // does not belong to this archive (iThisDisk=65535), strip file comments
    CopyStrippedCentralStructures(self, str, FEOC.CentralEntries, 0, 65535);
  end;
end;



procedure TZipArchiveStream.GotoZipData;
begin
 if not Assigned(FFile)
 then
   Seek(0, soFromBeginning)
 else
   Seek(FindStartOfZipData(self), soFromBeginning);
end;

function TZipArchiveStream.Read(var Buffer; Count: LongInt): Longint;
begin
  if not Assigned(FFile) then
  begin
    Result := 0;
    if FPosition < Size then
    begin
      Result := Count;
      if Result > (sizeof(FEOC) - FPosition)
      then
        Result := (sizeof(FEOC) - FPosition);
      Move((PAnsiChar(@FEOC)+FPosition)^, Buffer, Result);
      Inc(FPosition, Result);
    end;
  end
  else
    Result := FFile.Read(Buffer, Count)
end;

function TZipArchiveStream.Seek(Offset: LongInt; Origin: Word): Longint;
begin
  if Assigned(FFile)
  then
    FPosition := FFile.Seek(Offset, Origin)
  else
  begin
    case Origin of
      soFromBeginning: FPosition := Offset;
      soFromCurrent: Inc(FPosition, Offset);
      soFromEnd: FPosition := sizeof(FEOC) + Offset;



    end;
    if FPosition < 0
    then
      FPosition := 0;
    if FPosition > sizeof(FEOC)
    then
      FPosition := sizeof(FEOC);
  end;
  Result := FPosition;
end;

function TZipArchiveStream.Write(const Buffer; Count: LongInt): Longint;
begin
  Result := 0;
end;

// enum sfx resources
function ResEnumFunc( hMod: THandle; szType, szName: PChar; lParam: TStrings ): BOOL; stdcall;


  function MakeLCID(wLang, wSort: Word): DWORD;
  begin
    Result := (wSort shl 16) or wLang;
  end;

var
  sr: string;
  sr1: String;
  h1,h2: THandle;
  pw: PWord;
  szBuf: array[0..255] of Char;
begin
  Result := True;
  SetString(sr, szName, StrLen(szName)+1);
  sr := AnsiUpperCase(sr);
  if Pos(DzSfxID, sr) = 1 then
  begin
    if Pos(BinLangID+#0, sr) > 0 then
    begin
      sr1 := '';
      // found resource, now read language id
      h1 := FindResource(hMod, szName, RT_RCDATA);
      if h1 <> 0 then
      begin
        h2 := LoadResource(hMod, h1);
        if h2 <> 0 then
        begin
          pw := LockResource(h2);
          if pw <> nil then
          begin
            // get locale info
            SetString(sr1, szBuf, GetLocaleInfo(MakeLCID(pw^, SORT_DEFAULT), LOCALE_SNATIVELANGNAME, szBuf, sizeof(szBuf)));

            UnlockResource(h2);
          end;
          FreeResource(h2);
        end;
      end;
      sr := Copy(sr, Pos(DzSfxID, sr)+5, MaxInt);
      Delete(sr, Pos(BinLangID, sr), MaxInt);
      if sr1 = '' then
        sr1 := sr+'='+AnsiUpperCase(sr)
      else
        sr1 := sr1+'='+AnsiUpperCase(sr);
      if sr1 <> '' then
      begin
        if lParam.IndexOf(sr1) = -1
        then
          lParam.Add(sr1);
      end;
    end;
  end;
end;

initialization
  // load all compiled languages
  _INCLUDED_LANGUAGES := TStringList.Create;
  EnumResourceNames(0, RT_RCDATA, @ResEnumFunc, Integer(_INCLUDED_LANGUAGES));

finalization
  // free list of supported languages
  _INCLUDED_LANGUAGES.Free;

end.
