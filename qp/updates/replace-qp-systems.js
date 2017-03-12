#!/usr/bin/env node

const fs = require('fs')
const replace = require('replace-in-file')
const filenamePassed = process.argv.slice(2).toString()
const inputFile = fs.readFileSync(filenamePassed, "utf8")

const changesToMake = {
  
  "Aamber Pegasus" : "Technosys Aamber Pegasus",
  "Bandai Wonderswan" : "Bandai WonderSwan",
  "BBC" : "Acorn BBC",
  "Gameboy" : "Game Boy",
  "Gameboy Advance" : "Game Boy Advance",
  "VC4000" : "VC 4000 ",
  "Osbourne-1" : "Osbourne 1",
  "Mattel Juicebox" : "Mattel Juice Box",
  "Megaduck/Cougar Boy" : "Mega Duck / Cougar Boy", //What do we do about my lack of spaces around the / eh)
  "PBNO Bashkiria" :  "BNPO Bashkiria",
  "NEC PC Engine\TurboGrafx-16" : "NEC PC Engine/TurboGrafx-16", //not sure if its mess but everything else is forward slash
  "Osbourne-1" : "Osbourne 1",
  "SEGA GameGear" : "SEGA Game Gear",
  "Tatung Einstein TC-01" : "Tatung Einstein", //Actually mess has TC-01 too, but shouldn’t you lose the TC-01? There aren’t any other tatung einsteins
  "Texas Instruments" : "Texas instruments TI-99", //yeah that flies in the face of what I just said, but you try changing the company of just this system and leaving the other texas insturments calculators etc with the company name still….
  "Video Technology Creativision" : "Video Technology CreatiVision",
  "Bally Professinal Arcade" : "Bally Professional Arcade"

}

const romdataDats = {
  //every romdata.dat, be careful not to change any file paths
  //but also these other file types can go in because they match one of the rules and def do not match the other
  files: [
    `../data/**/*.dat`,
    `../dats/favs.dat`,
    `../search/*.tmp`
  ],
  from: `¬.*${key}`,//we need capturing groups here
  to: `¬${value}¬`
}

const emulatorsIni = {
  //in each object twice – once in the title so anything between [], and once in the system=, it would be BAD to change it in the path to the emulator (that applies to the media panel replacements also)
  //but also these other file types can go in because they match one of the rules and def do not match the other
  files: [
    `../dats/emulators.ini`,
    `../dats/MediaPanelCfg.ini`,
    `../dats/SystemFileExts.ini`,
    `../EFind/*.ini`
  ],
  from: /[.*`${key}`.*]/, //we have to use capture groups here 
  to: `${value}`,
  from: /system=.*${key}/,
  to: /system=ummmm...../
}

const systemsDat = {
  files: `../dats/systems.dat`,
  from: /.*${key}/, //same issue...
  to: `${value}`
}


const transform = (options) => {
  //we're going to merge this files property into the options object to DRY it
  const file = { files: filenamePassed }

  try {
    let changedFiles = replace.sync(Object.assign(options, file))
    console.log(`replaced content in ${options.files}` )
  }
  catch (error) {
    console.error(`Error occurred:`, error)
  }

}

transform(romdataDats)
transform(emulatorsIni)
transform(systemsDat)
