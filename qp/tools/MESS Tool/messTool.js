"use strict"

const fs        = require('fs')
  , path      = require('path')
  , XmlStream = require('xml-stream')

const stream = fs.createReadStream("inputs/mame.xml"),
    xml = new XmlStream(stream)

let prev,
    system


xml.on("updateElement: machine", function(machine) {
  const attr = machine.$.name
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
    if (systemName.indexOf(firstWordOfCompany) === 0 || company === "<unknown>") { system = systemName}
    else { system = company + " " + machine.description }

    console.log(system + " aka " + attr + " has at least one softlist, its a good system, and its not a clone")
    prev = attr
  }
});

