"use strict"

const fs      = require('fs')
  , path      = require('path')
  , XmlStream = require('xml-stream')

const stream = fs.createReadStream("inputs/mame.xml")
  , xml      = new XmlStream(stream)

//program flow
makeArray(function(array){
  sanitise(array, function(callback){
    printArrayToFile(callback)
  })
})


function makeArray(callback){

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
      //  , separator = " "
      //  ,  numberOfWords = 1
      //  ,  firstWordOfCompany = company.split(separator, numberOfWords)
     // if (systemName.indexOf(firstWordOfCompany) === 0 || company === "<unknown>") { system = systemName}
        , system = company + " " + machine.description
      systems.push(system)
     // console.log(system + " aka " + attr + " has at least one softlist, its a good system, and its not a clone")
      prev = attr
    }
  })

  xml.on("end", function(){
    callback(systems,callback)
  })
}

function sanitise(array, callback){
 const cleanedArray = array
 callback(cleanedArray)
}

function printArrayToFile(array){
  const opPath = ("outputs/newsystems.dat")
  const output = fs.createWriteStream(opPath)
  const newsystems = array.sort()
  output.on('error', function(err) { console.log("couldn't write the file") });
  
  //console.log(newsystems.toString());
  newsystems.forEach(function(v) { output.write(v + '\n'); });
  output.end();
}
