const fs = require('fs')
const replace = require('replace-in-file')
const rootDir = '/Users/twoode/Desktop/qp copy'

const changesToMake = {
  
  "Aamber Pegasus" : "Technosys Aamber Pegasus",
  "Bandai Wonderswan" : "Bandai WonderSwan",
  "BBC" : "Acorn BBC",
  "GameBoy" : "Game Boy", //will also catch eg: "Gameboy Advance, GameBoy Light, GameBoy Color
  "VC4000" : "VC 4000",
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

const oldName = `GameBoy`
const newName = `Game Boy`



/*
 * Replace systems in these ini files - you'll find them in emulators.ini twice – once in the title so anything between [], and once in the system= 
 *   it would be BAD to change it in the path to the emulator or paths in media panel
 *   some of these file match onee rule, emulators.ini matches them all
 */
const iniFiles = {

 files: [
    `${rootDir}/dats/emulators.ini`,
    `${rootDir}/dats/MediaPanelCfg.ini`,
    `${rootDir}/dats/SystemFileExts.ini`,
    `${rootDir}/EFind/*.ini`
  ],

  from: [
    //this first form here needs only replace MESS and Retroarch system names - note that we specifically look for those names later in 'dats'
    //(helps us out: otherwise we'd need a truly ugly regex to capture a romdata.dat's emulator column, and not the file paths too)
    new RegExp(String.raw`(\[.*)${oldName}`, `g`), //using es6 tagged templates in these  to avoid double-escaping 
    new RegExp(String.raw`(\[RetroArch )${oldName}`, `g`), //sometimes we have a double like "RetroArch GameBoy/GameBoy Color"
    new RegExp(String.raw`(system=.*)${oldName}`, `g`) //remember these replace sequentially in the 'to', but we don't acutally need it here
  ],

  to: `$1${newName}`

}

/*
 * everything that follows the romdata.dat form, be careful not to change any file paths
 */
const dats = {

  files: [
    `${rootDir}/data/**/*.dat`,
    `${rootDir}/dats/favs.dat`,
    `${rootDir}/search/*.tmp`
  ],

  from: [
    //since there are only emulators mentioned in a romdata.dat, no systems, we only need to change these:
    new RegExp(String.raw`\¬(MESS.*)${oldName}`, `g`),
    new RegExp(String.raw`\¬(RetroArch.*)${oldName}`, `g`)
  ],

  to: `\¬$1${newName}`,

  encoding: `latin1` //the less-than character's code point in win-1252 isnt happy as utf8

}

/*
 * Replace in the plain text systems list
 */
const systemsDat = {

  files: `${rootDir}/dats/systems.dat`,
  
  from: new RegExp(String.raw`(.*)${oldName}`, `g`),
  
  to: `$1${newName}`

}


const transform = (options) => {

  try {
    let changedFiles = replace.sync(options)
    console.log(`replaced content in ${options.files}` )
  }
  catch (error) {
    console.error(`Error occurred:`, error)
  }

}

transform(iniFiles)
transform(dats)
transform(systemsDat)
