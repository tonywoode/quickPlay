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
  , res = R.pipe(
  //general rules
    R.map( ( {company, system } ) => ( {company: company.replace(`<unknown>`, ``),system} ))
  , R.map( ( {company, system } ) => ( {company, system: system.replace(new RegExp(company.split(separator, numberOfWords) + '\\W', "i"), "")} )) //take company from system name if they repeat
  , R.map( ( {company, system } ) => ( {company: system.match(/MSX1/)? '' : company, system: system.match(/MSX1/)? `MSX1` : system}))
  , R.map( ( {company, system } ) => ( {company: system.match(/MSX2/)? '' : company, system: system.match(/MSX2/)? `MSX2` : system})) 
  , R.map( ( {company, system } ) => ( {company, system: system.replace(/(\(.*\)|\(.*\))/, ``)})) //now MSX has gone, every bracketed item is unnecessary

    //system specific
  , R.map( ( {company, system } ) => ( {company, system: (company.match(`Acorn`) && system.match(/BBC/))? `BBC` : system}))
  , R.map( ( {company, system } ) => ( {company, system: (company.match(`Acorn`) && system.match(/Electron/))? `Atom` : system}))
  , R.map( ( {company, system } ) => ( {company: company.replace(/Amstrad .*/, `Amstrad`), system: (company.match(`Amstrad`) && ( system.match(/(CPC|GX4000)/)) )? `CPC` : system}))
  , R.map( ( {company, system } ) => ( {company: company.replace(/Apple Computer/, `Apple`),system: system.replace(/Macintosh /, ``)}))
  , R.map( ( {company, system } ) => ( {company, system: (company.match(`Apple`) && system.match(/II.*/))? `II` : system}))
  , R.map( ( {company, system } ) => ( {company, system: (company.match(`Atari`) && system.match(/(400|^800.*|XE Game System)/))? `400/600/800/1200/XE` : system}))
  , R.map( ( {company, system } ) => ( {company: company.replace(`Bally Manufacturing`, `Bally`),system}))
  , R.map( ( {company, system } ) => ( {company, system:  (company.match(`Bandai`) && system.match(`Super Vision 8000`))? `Super Vision` : system}))
  , R.map( ( {company, system } ) => ( {company: company.replace(`Bondwell Holding`, ``), system: (company.match(`Bondwell`))? system=`Bondwell` : system}))
  , R.map( ( {company, system } ) => ( {company: company.replace(`Commodore Business Machines`, `Commodore`),system}))
  , R.map( ( {company, system } ) => ( {company, system:  (company.match(`Commodore`) && system.match(/B500|P500/))? `500/600/700` : system}))
  , R.map( ( {company, system } ) => ( {company, system:  (company.match(`Commodore`) && system.match(/PET .*|CBM .*/))? `PET/CBM` : system}))
  , R.map( ( {company, system } ) => ( {company, system:  (company.match(`Commodore`) && system.match(/64|128/))? `64/128` : system}))
  , R.map( ( {company, system } ) => ( {company, system:  (company.match(`Commodore`) && system.match(`VIC-10 / Max Machine / UltiMax`))? `Max/Ultimax`: system}))
  , R.map( ( {company, system } ) => ( {company, system:  (company.match(`EACA`) && system.match(`Colour Genie EG2000`))? `Colour Genie`: system}))
  , R.map( ( {company, system } ) => ( {company, system:  (company.match(`Elektronika`) && system.match(`BK 0010`))? `BK`: system}))
  , R.map( ( {company, system } ) => ( {company, system:  (company.match(`Emerson`) && system.match(`Arcadia 2001`))? `Arcadia`: system}))
  , R.map( ( {company, system } ) => ( {company, system:  (company.match(`Epson`) && system.match(`PX-4`))? `PX`: system}))
  , R.map( ( {company, system } ) => ( {company: company.replace(`Exidy Inc`, `Exidy`),system}))
  , R.map( ( {company, system } ) => ( {company, system:  (company.match(`Fairchild`) && system.match(`Channel F II`))? `Channel F`: system}))
  , R.map( ( {company, system } ) => ( {company, system:  (company.match(`Fujitsu`) && system.match(`FM-7`))? `Micro 7`: system}))
  , R.map( ( {company, system } ) => ( {company: company.replace(`General Consumer Electronics`, `GCE`),system}))
  , R.map( ( {company, system } ) => ( {company: company.replace(`Interton Electronic`, `Interton`), system: (company.match(`Interton`) && system.match(`VC 4000`))? `VC4000` : system}))
  , R.map( ( {company, system } ) => ( {company: company.replace(`Jupiter Cantab`, `Jupiter`),system}))
  , R.map( ( {company, system } ) => ( {company, system: (company.match(`Kyosei`) && system.match(`Kyotronic 85`))? `Kyotronic` : system}))
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
