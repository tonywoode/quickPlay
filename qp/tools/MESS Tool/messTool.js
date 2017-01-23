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
      //don't want systems with two manufacturers names eg atari atari 2600
      const 
          company = machine.manufacturer
        , systemName = machine.description
        , node = {}
      
      node.company = company
      node.system = systemName
      systems.push(node)
      //systems[company] = systemName
     // console.log(systems)
      //  , separator = " "
      //  ,  numberOfWords = 1
      //  ,  firstWordOfCompany = company.split(separator, numberOfWords)
     // if (systemName.indexOf(firstWordOfCompany) === 0 || company === "<unknown>") { system = systemName}
     //   , system = company + " " + machine.description
     // systems.push(system)
     // console.log(system + " aka " + attr + " has at least one softlist, its a good system, and its not a clone")
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
  , l2 = R.map( ( {company, system } ) => ( {company: company.replace(/Commodore Business Machines/, `Commodore`),system} ), l1)
  , l3 = R.map( ( {company, system } ) => ( {company: company.replace(/Apple Computer/, `Apple`),system: system.replace(/Macintosh /, ``)} ), l2)
  , l4 = R.filter( ( {company, system} ) => !system.match( /.*\(MSX..*\)/ ) , l3) //careful here - we must now put back a generic MSX1 and MSX2
  , l5 = R.append( {"company":"","system":"MSX1"}, l4 )
  , lz = R.append( {"company":"","system":"MSX2"}, l5 )
  , llast = R.map( ( {company, system} ) => ( {company, system: system.replace(new RegExp(company.split(separator, numberOfWords) + '\\W', "i"), "")} ), lz)

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
