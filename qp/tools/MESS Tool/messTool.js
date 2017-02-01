"use strict"

const 
    fs        = require('fs')
  , path      = require('path')
  , XmlStream = require('xml-stream')
  , R         = require('Ramda')
  , stream    = fs.createReadStream("inputs/mame.xml")
  , xml       = new XmlStream(stream)

//program flow
mockSystems(function(systems){
  makeSystemsList(systems, function(callback){
    printSystemsList(callback)
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


function makeSystemsList(systems, callback){
 const
    separator = " "
  , numberOfWords = 1
  
  //replacement functions
  , compRep = (oldCompany, newCompany)            => R.map( ( {company, system, call, cloneof } ) => ( {company: company.replace(oldCompany, newCompany),system, call, cloneof}))
  , systRep = (thisCompany, oldsystem, newsystem) => R.map( ( {company, system, call, cloneof } ) => ( {company, system: (company.match(thisCompany) && system.match(oldsystem))? newsystem : system, call, cloneof}))
  
  //transforms  
  , res = R.pipe(
  //general rules
   compRep(`<unknown>`, ``)
  , R.map( ( {company, system, call, cloneof } ) => ( {company, system: system.replace(new RegExp(company.split(separator, numberOfWords) + '\\W', "i"), ""), call, cloneof} )) //take company from system name if they repeat
  , R.map( ( {company, system, call, cloneof } ) => ( {company: system.match(/MSX1/)? '' : company, system: system.match(/MSX1/)? `MSX` : system, call, cloneof}))
  , R.map( ( {company, system, call, cloneof } ) => ( {company: system.match(/MSX2/)? '' : company, system: system.match(/MSX2/)? `MSX2` : system, call, cloneof})) 
  , R.map( ( {company, system, call, cloneof } ) => ( {company, system: system.replace(/(\(.*\)|\(.*\))/, ``), call, cloneof})) //now MSX has gone, every bracketed item is unnecessary

    //system specific (btw replace accepts regex or string by default (i'm trying to show what's intended), but match matches only regex
  , systRep(`Acorn`, /BBC/, `BBC`), systRep(`Acorn`, /Electron/, `Atom`)
  , compRep(/Amstrad .*/, `Amstrad`), systRep(`Amstrad`, /(CPC|GX4000)/, `CPC`)
  , compRep(`APF Electronics Inc.`, `APF`), systRep(`APF`, `M-1000`, `Imagination Machine`)
  , compRep(/Apple Computer/, `Apple`), systRep(`Apple`, /(Macintosh LC|Macintosh II.*)/, `Macintosh II (68020/68030)`)
    , systRep(`Apple`, /Macintosh (Plus|SE|Classic)/, `Macintosh (6800)`), systRep(`Apple`,/(^II.*|\]\[|\/\/c|\/\/e)/,`II`)
    , systRep(`Apple`,/\/\/\//,`III`)
  , systRep(`Atari`,/(400|^800.*|XE Game System)/, `400/600/800/1200/XE`)
  , compRep(`Bally Manufacturing`,`Bally`)
  , systRep(`Bandai`,`Super Vision 8000`, `Super Vision`) 
  , systRep(`Bondwell Holding`, /.*/, `Bondwell`), compRep(`Bondwell Holding`, ``) //change company after
  , systRep(`Casio`, `PV-1000`, `PV`)
  , compRep(`Commodore Business Machines`, `Commodore`), systRep(`Commodore`, /B500|P500/, `500/600/700`) 
    , systRep(`Commodore`, /PET .*|CBM .*/, `PET/CBM`), systRep(`Commodore`, /64|128/, `64/128`)
    , systRep(`Commodore`, `VIC-10 / Max Machine / UltiMax`, `Max/Ultimax`), systRep(`Commodore`, `VIC-1001`, `VIC-20`) 
  , compRep(`Comx World Operations Ltd`, `COMX`)
  , systRep(`EACA`,`Colour Genie EG2000`, `Colour Genie`)
  , systRep(`Elektronika`,`BK 0010`, `BK`)
  , systRep(`Emerson`, `Arcadia 2001`, `Arcadia`)
  , systRep(`Epson`, `PX-4`, `PX`)
  , compRep(`Exidy Inc`, `Exidy`)
  , systRep(`Fairchild`, `Channel F II`, `Channel F`)
  , systRep(`Fujitsu`, `FM-7`, `Micro 7`)
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
  , systRep(`International Business Machines`, `IBM PC 5150`, `PC 5150`), compRep(`International Business Machines`, `IBM`) //change company after
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

  // lastly dedupe all the dupes we just made in those transforms
  )(systems)
  
  callback(res)
}

function printSystemsList(systems){

  console.log(JSON.stringify(systems))
  
  const munge = systems =>  R.pipe(
      R.filter(( {thiscompany, system, call, cloneof } ) => !(cloneof)) //the systems list is a taxonomy
    , R.sortBy(R.prop('company'))
    , R.map(({company, system}) => ((company ==="" || system ==="")? ``:`${company}` + ` `) + `${system}`) //if there's a company name, print it first 
    , R.uniq //now we've filtered by company/system, we want to flatten to a systemes list
  )(systems)

  const flatSystems = munge(systems)
 
  const compare = (a, b) => a.localeCompare(b)

  const orderedFlatSystems = flatSystems.sort(compare)
  orderedFlatSystems.forEach(function (v){console.log(v)})
  const opPath = ("outputs/newsystems.dat")
  fs.writeFileSync(opPath, JSON.stringify(systems))
  //output.on('error', function(err) { console.log("couldn't write the file") });
  
  //systems.forEach(function(v) { output.write(v + '\n'); });
  //output.end();
}
