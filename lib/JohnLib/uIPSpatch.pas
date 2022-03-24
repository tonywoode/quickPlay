unit uIPSpatch;

interface

uses SysUtils, Classes;

type

  TIPSPatcher = class
  private
    _IPSPatchFileName : String;
    _FileToPatchFileName : String;
  public
    property IPSPatchFilename : String read _IPSPatchFileName write _IPSPatchFileName;
    property FileToPatch : String read _FileToPatchFileName write _FileToPatchFileName;
    constructor Create(pIPSPatch, pFileToPatch : String);overload;
    procedure Execute();
  end;

implementation

uses uQPConst;

{ TIPSPatcher }

constructor TIPSPatcher.Create(pIPSPatch, pFileToPatch: String);
begin
  _IPSPatchFileName := pIPSPatch;
  _FileToPatchFileName := pFileToPatch;
end;

procedure TIPSPatcher.Execute();
var
  Header : Array [0..4] of Char;
  EOF : Array [0..2] of Char;
  TempPosition : Int64;
  Offset : Longint;
  DSize : Word;
  OffsetArr : Array [0..2] of Byte;
  BytesToPatch : Array of Byte;
  RLEVal : Byte;
  IPSStream, ROMStream : TMemoryStream;
  i : Integer;
begin

  IPSStream := TMemoryStream.Create();
  try
    ROMStream := TMemoryStream.Create();

    IPSStream.LoadFromFile(_IPSPatchFilename);
    ROMStream.LoadFromFile(_FileToPatchFileName);

    ROMStream.Position := 0;
    IPSStream.Position := 0;

    IPSStream.Read(Header,5);

    if Header <> 'PATCH' then
      raise Exception.Create(QP_IPS_NOT_VALID);

    While(IPSStream.Position < IPSStream.Size) do
    begin
      //check for the end of the file.
      TempPosition := IPSStream.Position;
      IPSStream.Read(EOF,3);
      if EOF = 'EOF' then
        break;
      IPSStream.Position := TempPosition;

      IPSStream.Read(OffsetArr,3);

      Offset := StrToInt('$' + IntToHex(OffsetArr[0],2) +
        IntToHex(OffsetArr[1],2) +
          IntToHex(OffsetArr[2],2));

      DSize := 0;

      IPSStream.Read(DSize,2);

      DSize := Swap(DSize);

      if DSize > 0 then
      begin
      
        SetLength(BytesToPatch, DSize + 1);
        IPSStream.Read(BytesToPatch[0],DSize);
        ROMStream.Seek(Offset,soFromBeginning);
        RomStream.Write(BytesToPatch[0], DSize);
      end
      else
      begin
        IPSStream.Read(DSize,2);
        DSIze := swap(DSize);
        IPSStream.Read(RLEVal,1);
        ROMStream.Seek(Offset,soFromBeginning);
        for i := 0 to DSize -1 do
          RomStream.Write(RLEVal, 1);
      end;
    end;

    ROMStream.SaveToFile(_FileToPatchFileName);

  finally
    FreeAndNil(IPSStream);
    FreeAndNil(ROMStream);
  end;
end;

end.
