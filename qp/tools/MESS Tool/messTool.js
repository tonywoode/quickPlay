var fs        = require('fs')
  , path      = require('path')
  , XmlStream = require('xml-stream')

var stream = fs.createReadStream("inputs/mame.xml"),
    xml = new XmlStream(stream),
    attr,
    prev,
    name,
    system


xml.on("updateElement: machine", function(machine) {
  attr = machine.$.name
  if (machine.softwarelist 
     && attr !== prev 
     && machine.driver.$.emulation === "good"
     && !machine.$.cloneof
  ) {
    //don't want systems with two manufacturers names eg atari atari 2600
    const company = machine.manufacturer
    const systemName = machine.description
    const separator = " "
    const numberOfWords = 1
    const firstWordOfCompany = company.split(separator, numberOfWords)
    if (systemName.indexOf(firstWordOfCompany) === 0) { system = systemName}
    else { system = company + " " + machine.description }
    //const pattern = '^' + company + '.*'
    //pattern.test(system)
    //if (result) { console.log("yeah") }
    console.log(system + " aka " + attr + " has at least one softlist, its a good system, and its not a clone")
    prev = attr
  }
});

