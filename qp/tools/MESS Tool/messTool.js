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
  , l1 = R.map( ( {company, system } ) => ( {company: company.replace(/<unknown>/, ``),system} ), systems)
  , l2 = R.map( ( {company, system } ) => ( {company, system: system.replace(new RegExp(company.split(separator, numberOfWords) + '\\W', "i"), "")} ), l1)
  , l3 = R.map( ( {company, system } ) => ( {company: company.replace(/Apple Computer/, `Apple`),system: system.replace(/Macintosh /, ``)} ), l2)
  , l4 = R.map( ( {company, system } ) => ( {company: company.replace(/Commodore Business Machines/, `Commodore`),system} ), l3)
  , l5 = R.map( ( {company, system } ) => ( {company: system.match(/MSX1/)? '' : company, system : system.match(/MSX1/)? `MSX1` : system}), l4 )
  , l6 = R.map( ( {company, system } ) => ( {company: system.match(/MSX2/)? '' : company, system : system.match(/MSX2/)? `MSX2` : system}), l5 )
  , llast = R.uniq(l6)

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
