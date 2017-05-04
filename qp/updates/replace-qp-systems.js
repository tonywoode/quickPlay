const fs      = require('fs')
const replace = require('replace-in-file')
const rootDir = '../'

const changesToMake = [
  
  { oldName : "Aamber Pegasus",                      newName : "Technosys Aamber Pegasus"},
  { oldName : "Applied Technologies Microbee",       newName : "Applied Technology Microbee"},
  { oldName : "BBC",                                 newName : "Acorn BBC"},
  { oldName : "Bally Professinal Arcade",            newName : "Bally Professional Arcade"},
  { oldName : "Bandai Wonderswan",                   newName : "Bandai WonderSwan"},
  { oldName : "Commodore Max/UltiMax",               newName : "Commodore Max/Ultimax"},
  { oldName : "GameBoy",                             newName : "Game Boy"}, //will also catch eg: "Gameboy Advance, GameBoy Light, GameBoy Color
  { oldName : "Interton VC4000",                     newName : "Interton VC 4000"},
  { oldName : "Mattel Juicebox",                     newName : "Mattel Juice Box"},
  { oldName : "Megaduck/Cougar Boy",                 newName : "Mega Duck/Cougar Boy"}, //MESS puts a space around slashes like this but i decided not to? TODO: correct this?
  { oldName : "NEC PC Engine\\\\TurboGrafx-16",      newName : "NEC PC Engine/TurboGrafx-16"}, //Everything else is forward slash. This is very silly, despite String.raw later, we still need to quadruple escape a single escape....
  { oldName : "Osborne-1",                           newName : "Osbourne 1"},
  { oldName : "Osbourne-1",                          newName : "Osbourne 1"},//these should be a single regex
  { oldName : "PBNO Bashkiria",                      newName : "BNPO Bashkiria"},
  { oldName : "Sega GameGear",                       newName : "Sega Game Gear"},
  { oldName : "Tatung Einstein TC-01",               newName : "Tatung Einstein"}, //mess has TC-01 too, but there aren’t any other tatung einsteins
  { oldName : "Texas Instruments TI-99 Calculators", newName : "Texas Instruments Calculators"},
  { oldName : "Texas Instruments TI-99 TI",          newName : "Texas Instruments TI"}, //this is an issue with replacement strings, if they can't be regexs themselves we lose power
  { oldName : "Texas Instruments",                   newName : "Texas Instruments TI-99"}, //same principle but there ARE other Texas Instruments - this is going to mess up other TI names, however so
  { oldName : "Thompson MO5",       				 newName : "Thomson MO5"},
  { oldName : "Thompson MO6",       				 newName : "Thomson MO6"},
  { oldName : "Thompson TO7/TO9",       			 newName : "Thomson TO7/TO9"},
  { oldName : "Thompson TO8",       				 newName : "Thomson TO8"},
  { oldName : "Video Technology Creativision",       newName : "Video Technology CreatiVision"}
 
]

/*
 * Replace systems in these ini files - you'll find them in emulators.ini twice – once in the title so anything between [], and once in the system= 
 *   it would be BAD to change it in the path to the emulator or paths in media panel
 *   some of these file match onee rule, emulators.ini matches them all
 */
const iniFiles = ({oldName, newName}) => {

  return {
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
}

/*
 * everything that follows the romdata.dat form, be careful not to change any file paths
 */
const dats = ({oldName, newName}) => {

  return {
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
}

/*
 * Replace in the plain text systems list
 */
const systemsDat = ({oldName, newName}) => {

  return {
    files: `${rootDir}/dats/systems.dat`,
    
    from: new RegExp(String.raw`(.*)${oldName}`, `g`),
    
    to: `$1${newName}`
  }
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

//R.map(change => transform(iniFiles(change)), changesToMake) //but its not really a map, we aren't returning anything...
changesToMake.map(iniFiles).forEach(transform)
changesToMake.map(dats).forEach(transform)
changesToMake.map(systemsDat).forEach(transform)
