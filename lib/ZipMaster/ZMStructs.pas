unit ZMStructs;

(*
  MStructs.pas - Zip file internal structures
  TZipMaster VCL by Chris Vleghert and Eric W. Engler
  v1.79
  Copyright (C) 2005  Russell Peters


  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License (licence.txt) for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  contact: problems AT delphizip DOT org
  updates: http://www.delphizip.org

  modified 2005-11-23
---------------------------------------------------------------------------*)

interface

{$ifdef UNICODE}
uses Windows;
{$else}
uses WinTypes;
{$endif}

{$I ZIPVERS.INC}
{$IFDEF VERD2D3}
type
  LongWord = Cardinal;
{$ENDIF}

type
  ZipLocalHeader = packed record
    HeaderSig: LongWord;
    VersionNeed: Word;
    Flag: Word;
    ComprMethod: Word;
    ModifTime: Word;
    ModifDate: Word;
    CRC32: LongWord;
    ComprSize: LongWord;
    UnComprSize: LongWord;
    FileNameLen: Word;
    ExtraLen: Word;
  end;

// An entry in the central dir:
type
  ZipCentralHeader = packed record    //fixed part size : 42 bytes
    HeaderSig: LongWord;            // hex: 02014B50(4)
    VersionMadeBy0: Byte;           //version made by(1)
    VersionMadeBy1: Byte;           //host number(1)
    VersionNeed: Word;              // version needed to extract(2)
    Flag: Word;                     //generalPurpose bitflag(2)
    ComprMethod: Word;              //compression method(2)
    ModifTime: Word;                // modification time(2)
    ModifDate: Word;                // modification date(2)
    CRC32: LongWord;                //Cycling redundancy check (4)
    ComprSize: LongWord;            //compressed file size  (4)
    UnComprSize: LongWord;          //uncompressed file size (4)
    FileNameLen: Word;              //(2)
    ExtraLen: Word;                 //(2)
    FileComLen: Word;               //(2)
    DiskStart: Word;                //starts on disk number xx(2)
    IntFileAtt: Word;               //internal file attributes(2)
    ExtFileAtt: LongWord;           //external file attributes(4)
    RelOffLocal: LongWord;          //relative offset of local file header(4)
    // not used as part of this record structure:
    // filename, extra data, file comment
  end;

type
  ZipDataDescriptor = packed record
    DataDescSig: LongWord;          // Should be 0x08074B50
    CRC32: LongWord;
    ComprSize: LongWord;
    UnComprSize: LongWord;
  end;

type
  ZipEndOfCentral = packed record       //Fixed part size : 22 bytes
    HeaderSig: LongWord;                //(4)  hex=06054B50
    ThisDiskNo: Word;                   //(2)This disk's number
    CentralDiskNo: Word;                //(2)Disk number central dir start
    CentralEntries: Word;               //(2)Number of central dir entries on this disk
    TotalEntries: Word;                 //(2)Number of entries in central dir
    CentralSize: LongWord;              //(4)Size of central directory
    CentralOffSet: LongWord;            //(4)offsett of central dir on 1st disk
    ZipCommentLen: Word;                //(2)
    // not used as part of this record structure:
    // ZipComment
  end;
  pZipEndOfCentral = ^ZipEndOfCentral;
             (*
type
                        Zip64EOCLocator = packed record
                                    LocSig: LongWord;    // Should be 0x07064B50
                                    DiskStt:            LongWord;
                                    RelOfs: Int64;
                                    NumberDisks: LongWord;
                        end; *)

const                      { these are stored in reverse order }
  LocalFileHeaderSig = $04034B50;    { 'PK'34  (in file: 504b0304) }
  CentralFileHeaderSig = $02014B50;    { 'PK'12 }
  EndCentralDirSig = $06054B50;    { 'PK'56 }
  ExtLocalSig     = $08074B50;        { 'PK'78 }
  EndCentral64Sig = $06064B50;    { 'PK'66 }
  EOC64LocatorSig = $07064B50;    { 'PK'67 }

//----------------Icon resource info  needed SFX -----------------------------------
            {$IFDEF VERD2D3}
const
  IMAGE_DIRECTORY_ENTRY_RESOURCE = 2;
  IMAGE_NUMBEROF_DIRECTORY_ENTRIES = 16;
  IMAGE_SIZEOF_SHORT_NAME = 8;
  IMAGE_DOS_SIGNATURE     = $5A4D;
  IMAGE_NT_SIGNATURE      = $00004550;

type
  pIMAGE_DOS_HEADER = ^IMAGE_DOS_HEADER;

  IMAGE_DOS_HEADER = packed record      { DOS .EXE header }
    e_magic: WORD;                      { Magic number }
    e_cblp: WORD;                       { Bytes on last page of file }
    e_cp: WORD;                         { Pages in file }
    e_crlc: WORD;                       { Relocations }
    e_cparhdr: WORD;                    { Size of header in paragraphs }
    e_minalloc: WORD;                   { Minimum extra paragraphs needed }
    e_maxalloc: WORD;                   { Maximum extra paragraphs needed }
    e_ss: WORD;                         { Initial (relative) SS value }
    e_sp: WORD;                         { Initial SP value }
    e_csum: WORD;                       { Checksum }
    e_ip: WORD;                         { Initial IP value }
    e_cs: WORD;                         { Initial (relative) CS value }
    e_lfarlc: WORD;                     { File address of relocation table }
    e_ovno: WORD;                       { Overlay number }
    e_res: packed array[0..3] of WORD;  { Reserved words }
    e_oemid: WORD;                      { OEM identifier (for e_oeminfo) }
    e_oeminfo: WORD;                    { OEM information; e_oemid specific }
    e_res2: packed array[0..9] of WORD; { Reserved words }
    _lfanew: Longint;                   { File address of new exe header }
  end;

type
  pImageDataDirectory = ^IMAGE_DATA_DIRECTORY;

  _IMAGE_DATA_DIRECTORY = record
    VirtualAddress: DWORD;
    Size: DWORD;
  end;
  IMAGE_DATA_DIRECTORY = _IMAGE_DATA_DIRECTORY;

type
  pImageFileHeader = ^IMAGE_FILE_HEADER;

  _IMAGE_FILE_HEADER = packed record
    Machine: Word;
    NumberOfSections: Word;
    TimeDateStamp: DWORD;
    PointerToSymbolTable: DWORD;
    NumberOfSymbols: DWORD;
    SizeOfOptionalHeader: Word;
    Characteristics: Word;
  end;
  IMAGE_FILE_HEADER = _IMAGE_FILE_HEADER;

type
  pImageOptionalHeader = ^IMAGE_OPTIONAL_HEADER;

  _IMAGE_OPTIONAL_HEADER = packed record
    { Standard fields. }
    Magic: Word;
    MajorLinkerVersion: Byte;
    MinorLinkerVersion: Byte;
    SizeOfCode: DWORD;
    SizeOfInitializedData: DWORD;
    SizeOfUninitializedData: DWORD;
    AddressOfEntryPoint: DWORD;
    BaseOfCode: DWORD;
    BaseOfData: DWORD;
    { NT additional fields. }
    ImageBase: DWORD;
    SectionAlignment: DWORD;
    FileAlignment: DWORD;
    MajorOperatingSystemVersion: Word;
    MinorOperatingSystemVersion: Word;
    MajorImageVersion: Word;
    MinorImageVersion: Word;
    MajorSubsystemVersion: Word;
    MinorSubsystemVersion: Word;
    Win32VersionValue: DWORD;
    SizeOfImage: DWORD;
    SizeOfHeaders: DWORD;
    CheckSum: DWORD;
    Subsystem: Word;
    DllCharacteristics: Word;
    SizeOfStackReserve: DWORD;
    SizeOfStackCommit: DWORD;
    SizeOfHeapReserve: DWORD;
    SizeOfHeapCommit: DWORD;
    LoaderFlags: DWORD;
    NumberOfRvaAndSizes: DWORD;
    DataDirectory: packed array[0..IMAGE_NUMBEROF_DIRECTORY_ENTRIES - 1] of
    IMAGE_DATA_DIRECTORY;
  end;
  IMAGE_OPTIONAL_HEADER = _IMAGE_OPTIONAL_HEADER;

type
  TISHMisc = packed record
    case Integer of
      0: (PhysicalAddress: DWORD);
      1: (VirtualSize: DWORD);
  end;

  pImageSectionHeader = ^IMAGE_SECTION_HEADER;

  _IMAGE_SECTION_HEADER = packed record
    Name: packed array[0..IMAGE_SIZEOF_SHORT_NAME - 1] of Byte;
    Misc: TISHMisc;
    VirtualAddress: DWORD;
    SizeOfRawData: DWORD;
    PointerToRawData: DWORD;
    PointerToRelocations: DWORD;
    PointerToLinenumbers: DWORD;
    NumberOfRelocations: Word;
    NumberOfLinenumbers: Word;
    Characteristics: DWORD;
  end;
  IMAGE_SECTION_HEADER = _IMAGE_SECTION_HEADER;
            {$ENDIF}

type
  pISH = ^IMAGE_SECTION_HEADER;

  PEheader = packed record
    signature: DWord;
    _head: IMAGE_FILE_HEADER;
    opt_head: IMAGE_OPTIONAL_HEADER;
    section_header: IMAGE_SECTION_HEADER;
  end;

  IMAGE_RESOURCE_DIR_STRING_U = packed record
    Length: Word;
    NameString: array[0..0] of WChar;
  end;
  pIRDSU = ^IMAGE_RESOURCE_DIR_STRING_U;

  IMAGE_RESOURCE_DIRECTORY_ENTRY = packed record
    un1: record
      case Integer of
        1: (NameIsString: DWord); // Bit 32
        2: (NameOffset: DWord);   // Bits 31..0
        3: (Name: DWord);
        4: (Id: Word);
    end;
    un2: record
      case Integer of
        1: (OffsetToData: DWord);
        2: (DataIsDirectory: Dword);   // Bit 32
        3: (OffsetToDirectory: DWord); // Bits 31..0
    end;
  end;
  pIRDirE = ^IMAGE_RESOURCE_DIRECTORY_ENTRY;

  pIDD = ^IMAGE_DATA_DIRECTORY;

  IMAGE_RESOURCE_DIRECTORY = packed record
    Characteristics: DWord;
    TimeDateStamp: DWord;
    MajorVersion: Word;
    MinorVersion: Word;
    NumberOfNamedEntries: Word;
    NumberOfIdEntries: Word;
  end;
  pIRD = ^IMAGE_RESOURCE_DIRECTORY;

  IMAGE_RESOURCE_DATA_ENTRY = packed record
    OffsetToData: DWord;
    Size: DWord;
    CodePage: DWord;
    Reserved: DWord;
  end;
  pIRDatE = ^IMAGE_RESOURCE_DATA_ENTRY;
 // ---- end SFX needed 
 // ---- ===== ----- =====  end of implementation data ===== ----- ===== -----

implementation

end.
