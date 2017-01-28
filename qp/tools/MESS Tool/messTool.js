"use strict"

const 
    fs      = require('fs')
  , path      = require('path')
  , XmlStream = require('xml-stream')
  , R         = require('Ramda')
  , stream = fs.createReadStream("inputs/mame.xml")
  , xml      = new XmlStream(stream)

//program flow
mockSystems(function(systems){
  sanitise(systems, function(callback){
    printSystemsToFile(callback)
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
  let prev

  xml.on("updateElement: machine", function(machine) {
    const attr = machine.$.name
    if (machine.softwarelist 
       && attr !== prev 
       && machine.driver.$.emulation === "good"
       && !machine.$.cloneof
    ) {
      const 
          company = machine.manufacturer
        , systemName = machine.description
        , node = {}
      
      node.company = company
      node.system = systemName
      systems.push(node)
      prev = attr
    }
  })

  xml.on("end", function(){
    callback(systems,callback)
  })
}


function sanitise(systems, callback){
 const
    separator = " "
  , numberOfWords = 1
  
  //replacement functions
  , companyReplace = (oldCompany, newCompany)            => R.map( ( {company, system } ) => ( {company: company.replace(oldCompany, newCompany),system}))
  , systemReplace  = (thisCompany, oldsystem, newsystem) => R.map( ( {company, system } ) => ( {company, system: (company.match(thisCompany) && system.match(oldsystem))? newsystem : system}))

  //transforms  
  , res = R.pipe(
  //general rules
    companyReplace(`<unknown>`, ``)
  , R.map( ( {company, system } ) => ( {company, system: system.replace(new RegExp(company.split(separator, numberOfWords) + '\\W', "i"), "")} )) //take company from system name if they repeat
  , R.map( ( {company, system } ) => ( {company: system.match(/MSX1/)? '' : company, system: system.match(/MSX1/)? `MSX1` : system}))
  , R.map( ( {company, system } ) => ( {company: system.match(/MSX2/)? '' : company, system: system.match(/MSX2/)? `MSX2` : system})) 
  , R.map( ( {company, system } ) => ( {company, system: system.replace(/(\(.*\)|\(.*\))/, ``)})) //now MSX has gone, every bracketed item is unnecessary

    //system specific (btw replace accepts regex or string by default, but i'm trying to show what's intended as a string and what's a regex)
  , systemReplace(`Acorn`, /BBC/, `BBC`), systemReplace(`Acorn`, /Electron/, `Atom`)
  , companyReplace(/Amstrad .*/, `Amstrad`), systemReplace(`Amstrad`, /(CPC|GX4000)/, `CPC`)
  , companyReplace(/Apple Computer/, `Apple`), systemReplace(`Apple`, /Macintosh /, ``), systemReplace(`Apple`,/II.*/,`II`) 
  , systemReplace(`Atari`,/(400|^800.*|XE Game System)/, `400/600/800/1200/XE`)
  , companyReplace("Bally Manufacturing","Bally")
  , systemReplace(`Bandai`,`Super Vision 8000`, `Super Vision`) 
  , systemReplace(`Bondwell Holding`, `.*`, `Bondwell`), companyReplace(`Bondwell Holding`, ``)
  , companyReplace(`Commodore Business Machines`, `Commodore`), systemReplace(`Commodore`, /B500|P500/, `500/600/700`) 
    , systemReplace(`Commodore`, /PET .*|CBM .*/, `PET/CBM`), systemReplace(`Commodore`, /64|128/, `64/128`)
    , systemReplace(`Commodore`, `VIC-10 / Max Machine / UltiMax`, `Max/Ultimax`) 
  , systemReplace(`EACA`,`Colour Genie EG2000`, `Colour Genie`)
  , systemReplace(`Elektronika`,`BK 0010`, `BK`)
  , systemReplace(`Emerson`, `Arcadia 2001`, `Arcadia`)
  , systemReplace(`Epson`, `PX-4`, `PX`)
  , companyReplace(`Exidy Inc`, `Exidy`)
  , systemReplace(`Fairchild`, `Channel F II`, `Channel F`)
  , systemReplace(`Fujitsu`, `FM-7`, `Micro 7`)
  , companyReplace(`General Consumer Electronics`, `GCE`)
  , companyReplace(`Interton Electronic`, `Interton`)
  , companyReplace(`Jupiter Cantab`, `Jupiter`)
  , systemReplace(`Kyosei`, `Kyotronic 85`, `Kyotronic`)

  , R.map( ( {company, system } ) => ( {company: company.replace(`Luxor Datorer AB`, `Luxor`),system:  (company.match(`Luxor`) && system.match(/ABC.*/))? `ABC`: system}))

  , R.map( ( {company, system } ) => ( {company: company.replace(`Matra & Hachette`, `Tandy Radio Shack`), system: (company.match(`Matra & Hachette`) && system.match(`Alice 32`))? `MC-10` : system}))

  , R.map( ( {company, system } ) => ( {company: company.replace(`Memotech Ltd`, `Memotech`), system: (company.match(`Memotech`) && system.match(`MTX .*`))? `MTX` : system}))

  , R.map( ( {company, system } ) => ( {company, system:  (company.match(`Mikroelektronica`) && system.match(`Pyldin-601`))? `Pyldin`: system}))

  , R.map( ( {company, system } ) => ( {company: company.replace(`Nascom Microcomputers`, ``), system: (company.match(``) && system.match(/^2$/)? `Nascom` : system)}))

  , R.map( ( {company, system } ) => ( {company, system:  (company.match(`Nintendo`) && system.match(`Entertainment System / Famicom`))? `NES`: system}))

  , R.map( ( {company, system } ) => ( {company, system:  (company.match(`Nintendo`) && system.match(`Game Boy Color`))? `Game Boy`: system}))

  , R.map( ( {company, system } ) => ( {company, system:  (company.match(`Nintendo`) && system.match(`Super Entertainment System / Super Famicom `))? `SNES`: system}))

  , R.map( ( {company, system } ) => ( {company: company.replace(`Nippon Electronic Company`, `NEC`), system: system.match(`PC Engine`)? `PC Engine\\TurboGrafx-16` : system}))

  // lastly dedupe all the dupes we just made in those transforms
  , R.uniq //so in anything above, we can duplicate to become unique....
  )(systems)
  callback(res)
}

function printSystemsToFile(systems){

  const munge = systems =>  R.pipe(
      R.sortBy(R.prop('company'))
    , R.map(({company, system}) => ((company ==="" || system ==="")? ``:`${company}` + ` `) + `${system}`) //if there's a company name, print it first 
  )(systems)

  const flatSystems = munge(systems)
 
  const compare = (a, b) => a.localeCompare(b)

  const orderedFlatSystems = flatSystems.sort(compare)
  orderedFlatSystems.forEach(function (v){console.log(v)})
  process.exit()
  const opPath = ("outputs/newsystems.dat")
  fs.writeFileSync(opPath, JSON.stringify(systems))
  //output.on('error', function(err) { console.log("couldn't write the file") });
  
  //systems.forEach(function(v) { output.write(v + '\n'); });
  //output.end();
}
