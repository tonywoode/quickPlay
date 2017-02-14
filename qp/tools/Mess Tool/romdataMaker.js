"use strict"

const 
    fs         = require(`fs`)
  , XmlStream  = require(`xml-stream`)
  , R          = require(`Ramda`)

const 
    stream     = fs.createReadStream(`inputs/mame.xml`)
  , xml        = new XmlStream(stream)
  , iniOutPath = (`outputs/mess.ini`)
  , datOutPath = (`outputs/systems.dat`)
  , spaceIsSeparator  = ` `
  , oneWord = 1


//program flow
mockSystems(function(systems){

  R.pipe(

     print

  )(systems)

})


function mockSystems(callback){
  const 
      input   = fs.readFileSync(`inputs/mockSoftlistScrape.json`)
   ,  systems = JSON.parse(input)
  
  callback(systems, callback)
}


function makeSystems(callback){
  const systems = []

  xml.collect('softwarelist')
  xml.on(`updateElement: machine`, function(machine) {
    if (machine.softwarelist 
       && machine.driver.$.emulation === `good`
         && !machine.$.cloneof //with this one, we don't want any clones....
    ) {
      const node = {}
      node.system = machine.description 
      node.call = machine.$.name
      node.cloneof = machine.$.cloneof
      node.softlist = machine.softwarelist
      systems.push(node)
    }
  })

  xml.on(`end`, function(){
    callback(systems)
  })

}


function print(systems){
// there doesn't seem to be a way to get multiple softlists in the output for a single system, and print their properties nicely against the object. So we'll do it oursleves...
const printMe = R.map( ({ system, call, cloneof, softlist }) => ({ softlist: 
  R.map( ({ $ }) => ( ({ name:$.name, status:$.status, filter:$.filter }) ), softlist )
}),  systems)
console.log(JSON.stringify(printMe, null, '\t'))
process.exit()
}
