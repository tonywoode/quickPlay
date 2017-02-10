"use strict"

const 
    fs        = require('fs')
  , path      = require('path')
  , XmlStream = require('xml-stream')
  , R         = require('Ramda')
  , stream    = fs.createReadStream("inputs/mame.xml")
  , xml       = new XmlStream(stream)
  , separator = " "
  , numberOfWords = 1
//program flow
mockSystems(function(systems){
  mungeCompanyAndSytemsNames(systems, function(callback){
    mungeCompanyForType(callback)
  //  makeSystemsList(callback)
    makeFinalSystemTypes(callback)
    
  })
})


function mockSystems(callback){
  const 
       input = fs.readFileSync("inputs/newsystems.dat")
    ,  systems = JSON.parse(input)
  
  callback(systems,callback)
}

function makeSystems(callback){
  const systems = []

  xml.on("updateElement: machine", function(machine) {
    if (machine.softwarelist 
       && machine.driver.$.emulation === "good"
    ) {
      const node = {}
      //make an array of these objects: { company, system, call, cloneof }
      node.company = machine.manufacturer
      node.system = machine.description 
      node.call = machine.$.name
      node.cloneof = machine.$.cloneof
      systems.push(node)
    }
  })

  xml.on("end", function(){
    callback(systems,callback)
  })
}


function mungeCompanyAndSytemsNames(systems, callback){
 const
  //first create+populate 2 new properties for munging
    systemsAugmented = R.map( ({company, system, call, cloneof }) => ({company, system, call, cloneof, mungedCompany: company, mungedSystem: system }), systems )

   // These are the main replacement functions to munge MESS' company name and system name
  , compRep = (oldCompany, newCompany)            => R.map( ( {company, system, call, cloneof, mungedCompany, mungedSystem } ) => ( {company, system, call, cloneof, mungedCompany: mungedCompany.replace(oldCompany, newCompany), mungedSystem}))
  , systRep = (thisCompany, oldsystem, newsystem) => R.map( ( {company, system, call, cloneof, mungedCompany, mungedSystem } ) => ( {company, system, call, cloneof, mungedCompany, mungedSystem: (mungedCompany.match(thisCompany) && mungedSystem.match(oldsystem))? newsystem : mungedSystem}))


  //transforms  
  , mungedSystems = R.pipe(
   R.map( ( {company, system, call, cloneof, mungedCompany, mungedSystem } ) => ( {company, system, call, cloneof, mungedCompany, mungedSystem: mungedSystem.replace(new RegExp(mungedCompany.split(separator, numberOfWords) + '\\W', "i"), "")} )) //take company from system name if they repeat

  , compRep(/(<unknown>|<generic>)/, ``)
      //system specific (btw replace accepts regex or string by default (i'm trying to show what's intended), but match matches only regex
  , systRep(`Acorn`, /BBC/, `BBC`), systRep(`Acorn`, /Electron/, `Atom`)
  , compRep(/Amstrad .*/, `Amstrad`), systRep(`Amstrad`, /(CPC|GX4000)/, `CPC`)
  , compRep(`APF Electronics Inc.`, `APF`), systRep(`APF`, `M-1000`, `Imagination Machine`)
  , compRep(/Apple Computer/, `Apple`), systRep(`Apple`, /(Macintosh LC|Macintosh II.*)/, `Macintosh II (68020/68030)`)
    , systRep(`Apple`, /Macintosh (Plus|SE|Classic)/, `Macintosh (6800)`), systRep(`Apple`,/(^II.*|\]\[|\/\/c|\/\/e)/,`II`)
    , systRep(`Apple`,/\/\/\//,`III`)
  , systRep(`Atari`,/(400|800.*|XE Game System)/, `400/600/800/1200/XE`)
  , compRep(`Bally Manufacturing`,`Bally`)
  , systRep(`Bandai`,`Super Vision 8000`, `Super Vision`) 
  , systRep(`Bondwell Holding`, /.*/, `Bondwell`), compRep(`Bondwell Holding`, ``) //change company after
  , systRep(`Casio`, `PV-1000`, `PV`)
  , compRep(`Commodore Business Machines`, `Commodore`), systRep(`Commodore`, /(B500|P500)/, `500/600/700`) 
  , systRep(`Commodore`, /PET .*|CBM .*/, `PET/CBM`), systRep(`Commodore`, /\b(64|128)/, `64/128`)
  , systRep(`Commodore`, `VIC-10 / Max Machine / UltiMax`, `Max/Ultimax`), systRep(`Commodore`, `VIC-1001`, `VIC-20`), systRep(`Commodore`, `264`, `+4/C16`) 
  , compRep(`Comx World Operations Ltd`, `COMX`)
  , systRep(`EACA`,`Colour Genie EG2000`, `Colour Genie`)
  , systRep(`Elektronika`,`BK 0010`, `BK`)
  , systRep(`Emerson`, `Arcadia 2001`, `Arcadia`)
  , systRep(`Epson`, `PX-4`, `PX`)
  , compRep(`Exidy Inc`, `Exidy`)
  , systRep(`Fairchild`, `Channel F II`, `Channel F`)
  , systRep(`Fujitsu`, `FM-7`, `Micro 7`)
  , compRep(`Franklin Computer`, `Franklin`)
  , compRep(`General Consumer Electronics`, `GCE`)
  , compRep(`Interton Electronic`, `Interton`)
  , compRep(`Jupiter Cantab`, `Jupiter`)
  , systRep(`Kyosei`, `Kyotronic 85`, `Kyotronic`)
  , compRep(`Luxor Datorer AB`, `Luxor`), systRep(`Luxor`, /ABC.*/, `ABC`)
  , systRep(`Matra & Hachette`, `Alice 32`, `MC-10`), compRep(`Matra & Hachette`, `Tandy Radio Shack`) //change company after
  , compRep(`Memotech Ltd`, `Memotech`), systRep(`Memotech`, `MTX .*`, `MTX`) 
  , systRep(`Mikroelektronika`, `Pyldin-601`, `Pyldin`)
  , systRep(`Nascom Microcomputers`, `2`, `Nascom`), compRep(`Nascom Microcomputers`, ``) //change company after
  , systRep(`Nintendo`, `Entertainment System / Famicom`, `NES`)
  , systRep(`Nintendo`, `Game Boy Color`, `Game Boy`)
  , systRep(`Nintendo`, `Super Entertainment System / Super Famicom `, `SNES`)
  , compRep(`Nippon Electronic Company`, `NEC`), systRep(`NEC`, `PC Engine`, `PC Engine/TurboGrafx-16`)
  , systRep(`Non Linear Systems`, `Kaypro II - 2/83`, `Kaypro`)
  , compRep(`Data Applications International`, `DAI`), systRep(`DAI`, `DAI Personal Computer`, `Personal Computer`)
  , compRep(`Elektronika inzenjering` , ``)
  , systRep(`International Business Machines`, `IBM PC 5150`, `PC`), compRep(`International Business Machines`, `IBM`) //change company after
  , systRep(`Interton`, `Electronic VC 4000` , `VC 4000`)
  , systRep(``, `Orion128` , `Orion`) //note these assume youve transformed <unknown> already
  , systRep(``, `PK8020Korvet` , `Korvet PK`)
  , compRep(`Jungle Soft / KenSingTon / Chintendo / Siatronics`, '')
  , systRep(/Welback Holdings .*/ , `Mega Duck / Cougar Boy`, `Mega Duck/Couger Boy`), compRep(/Welback Holdings .*/, ``) //change company after
  , compRep(`Miles Gordon Technology plc`, `MGT`)
  , compRep(`Processor Technology Corporation`, `PTC`), systRep(`PTC`, `SOL-20`, `Sol`)
  , systRep(``, `Radio86RK` , `Radio-86RK`) //seems MESS made the mistake here...
  , systRep(`Sanyo`, `MBC-55x`, `MBC`)
  , systRep(`SNK`, /(Neo-Geo$|Neo-Geo AES)/, `Neo Geo`), systRep(`SNK`, `Neo-Geo CDZ`, `Neo Geo CD`) //wikipedia says MESS is wrong
    , systRep(`SNK`, `NeoGeo Pocket`, `Neo Geo Pocket`) //MESS says MESS is wrong....
  , systRep(`Sega`, `Genesis`, `Genesis/32X`), systRep(`Sega`, `Master System II`, `Master System`)
     , systRep(`Sega`, /(SC-3000|SG-1000)/, `SG-1000/SC-3000/SF-7000`)
  , systRep(`Sharp`, /MZ.*/, `MZ`)
  , compRep(`Sinclair Research Ltd`, `Sinclair`), systRep(`Sinclair`, /ZX Spectrum .*/, `ZX Spectrum`)
  , systRep(`Sord`, `m.5`, `M5`)
  , systRep(`Spectravideo`, `SVI-318`, `SVI`)
  , systRep(`Tandy Radio Shack`, /(TRS-80 .*|Color Computer)/, `TRS-80 CoCo`)
  , systRep(`Texas Instruments`, /TI-99.*/, 'TI-99')
  , systRep(`Thomson`, `MO5 NR`, `MO5`), systRep(`Thomson`, /(TO7.*|TO9.*)/, `TO7/TO9`)
  , compRep(`V. I. Lenin`, `Lenin`), systRep(`Lenin`, `PK-01 Lviv`, `Lviv`)
  , systRep(`Video Technology`, /Laser.*/, `Laser Mk1`)
  , compRep(`Visual Technology Inc` , `Visual`)
  , systRep(`Watara`, `Super Vision`, `Supervision`) //again MESS seems to be wrong
  )(systemsAugmented)
    
  callback(mungedSystems)
}


function mungeCompanyForType(systems){
 const 
   systemsWithDisplayComp = R.pipe(
      R.map( ( {company, system, call, cloneof, mungedCompany, mungedSystem } ) => ( {company, system, call, cloneof, mungedCompany, displayCompany: mungedCompany, mungedSystem})) //we need a new field to capture the name to display rather than munge to system type
    , R.map( ( {company, system, call, cloneof, mungedCompany, displayCompany, mungedSystem } ) => ( {company, system, call, cloneof, mungedCompany: mungedSystem.match(/MSX1/)? '' : mungedCompany, displayCompany, mungedSystem: mungedSystem.match(/MSX1/)? `MSX` : mungedSystem}))
    , R.map( ( {company, system, call, cloneof, mungedCompany, displayCompany, mungedSystem } ) => ( {company, system, call, cloneof, mungedCompany: mungedSystem.match(/MSX2/)? '' : mungedCompany, displayCompany, mungedSystem: mungedSystem.match(/MSX2/)? `MSX2` : mungedSystem}))   
    , R.map( ( {company, system, call, cloneof, mungedCompany, displayCompany, mungedSystem } ) => ( {company, system, call, cloneof, mungedCompany, mungedSystem: mungedSystem.replace(/\W\(.*\)/, ``), displayCompany})) //now MSX has gone, every bracketed item is unnecessary
     )(systems)

  makeFinalSystemTypes(systemsWithDisplayComp)
}


function makeSystemsList(systems){

 const munge = systems =>  R.pipe(
      R.filter(( {thiscompany, system, call, cloneof } ) => !(cloneof)) //the systems list is a taxonomy
    , R.map( ( {company, system, call, cloneof, mungedCompany, mungedSystem } ) => ( (mungedCompany ==="" || mungedSystem ==="")? ``:`${mungedCompany}` + ` `) + `${mungedSystem}`) //if there's a company name, print it first 
    , R.uniq // lastly dedupe all the dupes we made in all those transforms
    , R.sortBy(R.prop('mungedCompany'))
  )(systems)

  const flatSystems = munge(systems)
 
  const compare = (a, b) => a.localeCompare(b)

  const orderedFlatSystems = flatSystems.sort(compare)
  //orderedFlatSystems.forEach((v) => console.log(v) )

  const opPath = ("outputs/newsystems.dat")
  fs.writeFileSync(opPath, orderedFlatSystems.join('\n'))
  //output.on('error', function(err) { console.log("couldn't write the file") });
  
  //systems.forEach(function(v) { output.write(v + '\n'); });
  //output.end();
}


function makeFinalSystemTypes(systems){

  const
     lookupCall = (cloneof, call) =>  {
      const referredSystem = R.find(R.propEq(`call`, cloneof))(systemsWithType)
      return referredSystem === undefined ? console.log(`PROBLEM: ${call} says its a (working) cloneof ${cloneof} but ${cloneof} is emulated badly?`) : referredSystem.systemType
    }
  //before we replace the clone systems with the system type they are cloned from, we need to get our type property together
  , systemsWithType = R.map( ({company, system, call, cloneof, mungedCompany, displayCompany, mungedSystem }) => ({company, system, call, cloneof, mungedCompany, displayCompany, mungedSystem, systemType: (mungedCompany ==="" || mungedSystem ==="")? `${mungedSystem}`:`${mungedCompany} ${mungedSystem}`}), systems )

  //next we'd like to change the munged system of every machine that has a cloneof property to be the system that points to
  , systemsDeCloned = R.map( ({company, system, call, cloneof, mungedCompany, displayCompany, mungedSystem, systemType }) => ({company, system, call, cloneof, mungedCompany, displayCompany, mungedSystem, systemType: cloneof? lookupCall(cloneof, call) : systemType }), systemsWithType ) // this step belongs at the end
  
 // console.log(JSON.stringify(systemsDeCloned, null, '\t'))
  print(systemsDeCloned)

}

/*
 * A subtlty here is that we want to print the munged COMPANY name (to avoid xx Computer Electronics Holding Ltd AB etc), but we want to largely keep 
 *   MESS' original system name to capture what makes each system different. However there are some considerations that also apply to system munging 
 *   that need re-application, along with some new concerns regarding the output format
 */
function print(systems){

   const efinder = R.pipe(
      R.map( ( {system, call, displayCompany, systemType } ) => ( {call, displayCompany, displaySystem: displayCompany == ``? system : system.replace(new RegExp(displayCompany.split(separator, numberOfWords) + `\\W`, `i`), ``), systemType} )) //take company from system name if they repeat
    , R.map( ( {call, displayCompany, displaySystem, systemType } ) => ( {call, displayCompany, displaySystem: displaySystem.replace(/\]\[/, `II`), systemType}))
    , R.map( ( {call, displayCompany, displaySystem, systemType } ) => ( {call, displayMachine: displayCompany == `` ? `${displaySystem}` : `${displayCompany} ${displaySystem}`, systemType }))
)(systems)
    const efinderToPrint = R.map ( ( {call, displayMachine, systemType } ) => (
`[Retroarch MESS ${displayMachine}]
Exe Name=retroarch.exe
Config Name=retroarch
System=${systemType} 
HomePage=http://wiki.libretro.com/index.php
param=${call}
isWin32=1
CmdLine=1
ShellEx=0
Verify=0
ShortExe=0
DisWinKey=1
DisScrSvr=1
Compression=2E7A69703D300D0A2E7261723D300D0A2E6163653D300D0A2E377A3D300D0A
`
    ), efinder )


  const opPath = ("outputs/mess.ini")
  fs.writeFileSync(opPath, efinderToPrint.join('\n'))
  madeDat(efinder)
}

function madeDat(systems){
 const lister = systems =>  R.pipe(
    R.map( ({call, displayMachine, systemType }) => (`${systemType}`))
  , R.uniq
   )(systems)
 const flatShit = lister(systems)
   const opPath = ("outputs/ooohsystems.dat")

 const compare = (a, b) => a.localeCompare(b)

  const ordered = flatShit.sort(compare)

  fs.writeFileSync(opPath, ordered.join('\n'))
  process.exit()

}

