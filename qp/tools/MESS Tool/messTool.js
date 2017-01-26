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

  //general rules
  , l1 = R.map( ( {company, system } ) => ( {company: company.replace(/<unknown>/, ``),system} ), systems)
  , l2 = R.map( ( {company, system } ) => ( {company, system: system.replace(new RegExp(company.split(separator, numberOfWords) + '\\W', "i"), "")} ), l1) //take company from system name if they repeat
  , l3 = R.map( ( {company, system } ) => ( {company, system: system.replace(/(\(NTSC\)|\(PAL\))/, ``)}), l2 )

  //system specific
  , la = R.map( ( {company, system } ) => ( {company, system: (company.match(`Acorn`) && system.match(/BBC/))? `BBC` : system}), l3 )
  , lb = R.map( ( {company, system } ) => ( {company, system: (company.match(`Acorn`) && system.match(/Electron/))? `Atom` : system}), la )
  , lc = R.map( ( {company, system } ) => ( {company: company.replace(/Amstrad .*/, `Amstrad`), system: (company.match(`Amstrad`) && ( system.match(/(CPC|GX4000)/)) )? `CPC` : system}), lb )
  , ld = R.map( ( {company, system } ) => ( {company: company.replace(/Apple Computer/, `Apple`),system: system.replace(/Macintosh /, ``)}), lc)
  , le = R.map( ( {company, system } ) => ( {company, system: (company.match(`Apple`) && system.match(/II.*/))? `II` : system}), ld)
  , lx = R.map( ( {company, system } ) => ( {company: company.replace(/Commodore Business Machines/, `Commodore`),system}), le)
  , ly = R.map( ( {company, system } ) => ( {company: system.match(/MSX1/)? '' : company, system: system.match(/MSX1/)? `MSX1` : system}), lx )
  , lz = R.map( ( {company, system } ) => ( {company: system.match(/MSX2/)? '' : company, system: system.match(/MSX2/)? `MSX2` : system}), ly )
  , llast = R.uniq(lz) //so in anything above, we can duplicate to become unique....

  callback(llast)
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
