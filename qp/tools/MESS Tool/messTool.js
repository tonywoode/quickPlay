"use strict"

const fs      = require('fs')
  , path      = require('path')
  , XmlStream = require('xml-stream')
  , R         = require('Ramda')

const stream = fs.createReadStream("inputs/mame.xml")
  , xml      = new XmlStream(stream)

//program flow
mockSystems(function(systems){
  sanitise(systems, function(callback){
    printSystemsToFile(callback)
  })
})


function mockSystems(callback){
  const input = fs.readFileSync("inputs/newsystems.dat")
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
      const node = {}
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
  //const regex = new RegExp(machines[0].company)
  const removeDupe = ( {company, system} ) => ( {company, system: system.replace(new RegExp(company + '\\W', "i"), "")} )
  const cleanedSystems = R.map(removeDupe, systems)
 callback(cleanedSystems)
}

function printSystemsToFile(systems){
  
  console.log(JSON.stringify(systems))
  systems.forEach(function (v){console.log(v.company + " " + v.system) })
  //remember we still need to sort it really
  process.exit()

  const opPath = ("outputs/newsystems.dat")
  fs.writeFileSync(opPath, JSON.stringify(systems))
  //const newsystems = systems.sort()
  //output.on('error', function(err) { console.log("couldn't write the file") });
  
  //console.log(newsystems.toString())
  //const jsonobj = JSON.stringify(systems)
  //output.write(jsonobj)
  //systems.forEach(function(v) { output.write(v + '\n'); });
  //output.end();
}
