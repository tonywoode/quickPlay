{******************************************************************

                       JEDI-VCL Demo

 Copyright (C) 2002 Project JEDI

 Original author:

 Contributor(s):

 You may retrieve the latest version of this file at the JEDI-JVCL
 home page, located at http://jvcl.delphi-jedi.org

 The contents of this file are used with permission, subject to
 the Mozilla Public License Version 1.1 (the "License"); you may
 not use this file except in compliance with the License. You may
 obtain a copy of the License at
 http://www.mozilla.org/MPL/MPL-1_1Final.html

 Software distributed under the License is distributed on an
 "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 implied. See the License for the specific language governing
 rights and limitations under the License.

******************************************************************}

unit fThread;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, JvThread, JvComponent, JvThreadDialog, ComCtrls, //JvThreadGifDialog,
  JvExControls, JvAnimatedImage, JvGIFCtrl, JvProgressBar, JvExComCtrls,
  JvComponentBase, ActnList, ExtCtrls;

type
  TForm1 = class(TForm)
    Label1: TLabel;
    JvThread1: TJvThread;
    JvThread2: TJvThread;
    Button1: TButton;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Button2: TButton;
    JvThreadSimpleDialog1: TJvThreadSimpleDialog;
    JvThreadAnimateDialog1: TJvThreadAnimateDialog;
    Button3: TButton;
    Button4: TButton;
    procedure JvThread1Execute(Sender: TObject; params: Pointer);
    procedure Button1Click(Sender: TObject);
    procedure JvThread2Execute(Sender: TObject; params: Pointer);
    procedure Button2Click(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
  private
  public
    Value: Integer;
    Value2: Integer;
    procedure Stats1;
    procedure Stats2;
  end;

var
  Form1: TForm1;

implementation

uses
  JvDynControlEngineDevExpcx;

{$R *.dfm}

procedure TForm1.JvThread1Execute(Sender: TObject; params: Pointer);
var
  i, j, k: Integer;
begin
  //Do the job here
  k := 0;
  for i := 0 to 100 do
    for j := 0 to 500 do
    begin
      Inc(k);

      //To use global variable/objects, you have to synchronize (to avoid conflicts)
      TForm1(params).Value := k;
      JvThread1.Synchronize(TForm1(params).Stats1);

      if JvThread1.Terminated then
        Exit;
    end;
end;

procedure TForm1.JvThread2Execute(Sender: TObject; params: Pointer);
var
  i, j, k: Integer;
begin
  //Do the job here
  k := 0;
  for i := 0 to 100 do
    for j := 0 to 10 do
    begin
      Inc(k,5); //This is the only difference with the other thread
      sleep(13);
      //To use global variable/objects, you have to synchronize (to avoid conflicts)
      TForm1(params).Value2 := k;
      JvThread2.Synchronize(TForm1(params).Stats2);

      if JvThread2.Terminated then
        Exit;
    end;

end;

procedure TForm1.Button1Click(Sender: TObject);
begin
  JvThread1.ThreadDialog := Nil;
  JvThread1.Execute(Self);
  (Sender as TButton).Enabled := False;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  JvThread2.ThreadDialog := Nil;
  JvThread2.Execute(Self);
  (Sender as TButton).Enabled := False;
end;

procedure TForm1.Stats1;
begin
  Label2.Caption := IntToStr(Value);
end;

procedure TForm1.Stats2;
begin
  Label4.Caption := IntToStr(Value2);
end;

procedure TForm1.FormDestroy(Sender: TObject);
begin
  if not JvThread1.Terminated then
    JvThread1.Terminate;
  if not JvThread2.Terminated then
    JvThread2.Terminate;
  while not (JvThread1.Terminated or JvThread2.Terminated) do
  begin
    Sleep(100);
    Application.ProcessMessages;
  end;

end;

procedure TForm1.Button4Click(Sender: TObject);
begin
  JvThread2.ThreadDialog := JvThreadAnimateDialog1;
  JvThread2.Execute(Self);
  //(Sender as TButton).Enabled := False;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
  JvThread1.ThreadDialog := JvThreadSimpleDialog1;
  JvThread1.Execute(Self);
  //(Sender as TButton).Enabled := False;
end;

end.