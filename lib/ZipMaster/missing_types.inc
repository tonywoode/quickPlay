// stuff not defined in delphi 2
{$IFNDEF DELPHI3UP} // may be incorrect (DELPHI4UP?)
const
  IMAGE_NUMBEROF_DIRECTORY_ENTRIES        = 16;
  IMAGE_SIZEOF_SHORT_NAME                 =  8;
  IMAGE_DOS_SIGNATURE                     = $5A4D;      { MZ }
  IMAGE_NT_SIGNATURE                      = $00004550;  { PE00 }
  IMAGE_DIRECTORY_ENTRY_RESOURCE          = 2;  { Resource Directory }
  ICON_BIG                                = 1;

type
  LongWord = Cardinal;

  PImageDosHeader = ^TImageDosHeader;
  TImageDosHeader = packed record      { DOS .EXE header                  }
      e_magic: Word;                     { Magic number                     }
      e_cblp: Word;                      { Bytes on last page of file       }
      e_cp: Word;                        { Pages in file                    }
      e_crlc: Word;                      { Relocations                      }
      e_cparhdr: Word;                   { Size of header in paragraphs     }
      e_minalloc: Word;                  { Minimum extra paragraphs needed  }
      e_maxalloc: Word;                  { Maximum extra paragraphs needed  }
      e_ss: Word;                        { Initial (relative) SS value      }
      e_sp: Word;                        { Initial SP value                 }
      e_csum: Word;                      { Checksum                         }
      e_ip: Word;                        { Initial IP value                 }
      e_cs: Word;                        { Initial (relative) CS value      }
      e_lfarlc: Word;                    { File address of relocation table }
      e_ovno: Word;                      { Overlay number                   }
      e_res: array [0..3] of Word;       { Reserved words                   }
      e_oemid: Word;                     { OEM identifier (for e_oeminfo)   }
      e_oeminfo: Word;                   { OEM information; e_oemid specific}
      e_res2: array [0..9] of Word;      { Reserved words                   }
      _lfanew: LongInt;                  { File address of new exe header   }
  end;

  PImageFileHeader = ^TImageFileHeader;
  TImageFileHeader = packed record
    Machine: Word;
    NumberOfSections: Word;
    TimeDateStamp: DWORD;
    PointerToSymbolTable: DWORD;
    NumberOfSymbols: DWORD;
    SizeOfOptionalHeader: Word;
    Characteristics: Word;
  end;

  PImageDataDirectory = ^TImageDataDirectory;
  TImageDataDirectory = record
    VirtualAddress: DWORD;
    Size: DWORD;
  end;

  PImageOptionalHeader = ^TImageOptionalHeader;
  TImageOptionalHeader = packed record
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
    DataDirectory: packed array[0..IMAGE_NUMBEROF_DIRECTORY_ENTRIES-1] of TImageDataDirectory;
  end;

  TISHMisc = packed record
    case Integer of
      0: (PhysicalAddress: DWORD);
      1: (VirtualSize: DWORD);
  end;

  PImageSectionHeader = ^TImageSectionHeader;
  TImageSectionHeader = packed record
    Name: packed array[0..IMAGE_SIZEOF_SHORT_NAME-1] of Byte;
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

  PImageNtHeaders = ^TImageNtHeaders;
  TImageNtHeaders = packed record
    Signature: DWORD;
    FileHeader: TImageFileHeader;
    OptionalHeader: TImageOptionalHeader;
  end;
{$ENDIF}
