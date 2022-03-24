Program zipdemo1;

Uses
    Forms,
    msgunit In 'msgunit.pas' {Msgform},
    extrunit In 'extrunit.pas' {Extract},
    Addunit In 'Addunit.pas' {AddForm},
    sfxunit In 'sfxunit.pas' {MakeSFX},
    mainunit In 'mainunit.pas' {Mainform},
    renunit In 'renunit.pas' {RenForm};

{$R *.RES} 
{$R 'Res\ZMRes.res'}
{$R 'Res\dzsfxUS.res'}

Begin
    Application.Initialize;
    Application.Title := 'Zip Demo 1';
    Application.CreateForm(TMainform, Mainform);
    Application.CreateForm(TMsgform, Msgform);
    Application.CreateForm(TExtract, Extract);
    Application.CreateForm(TAddForm, AddForm);
    Application.CreateForm(TMakeSFX, MakeSFX);
    Application.CreateForm(TRenForm, RenForm);
    Application.Run;
End.

