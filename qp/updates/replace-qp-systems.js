const fs      = require('fs')
const replace = require('replace-in-file')
const R       = require(`Ramda`)
const rootDir = '/Users/twoode/Desktop/qp copy'

const changesToMake = [
  
  { oldName : "Aamber Pegasus", newName : "Technosys Aamber Pegasus"},
  { oldName : "Bandai Wonderswan", newName : "Bandai WonderSwan"},
  { oldName : "BBC", newName : "Acorn BBC"},
  { oldName : "GameBoy", newName : "Game Boy"}, //will also catch eg: "Gameboy Advance, GameBoy Light, GameBoy Color
  { oldName : "VC4000", newName : "VC 4000"},
  { oldName : "Osbourne-1", newName : "Osbourne 1"},
  { oldName : "Mattel Juicebox", newName : "Mattel Juice Box"},
  { oldName : "Megaduck/Cougar Boy", newName : "Mega Duck / Cougar Boy"}, //What do we do about my lack of spaces around the / eh)
  { oldName : "PBNO Bashkiria", newName :  "BNPO Bashkiria"},
  { oldName : "NEC PC Engine\TurboGrafx-16", newName : "NEC PC Engine/TurboGrafx-16"}, //not sure if its mess but everything else is forward slash
  { oldName : "Osbourne-1", newName : "Osbourne 1"},
  { oldName : "SEGA GameGear", newName : "SEGA Game Gear"},
  { oldName : "Tatung Einstein TC-01", newName : "Tatung Einstein"}, //Actually mess has TC-01 too, but shouldn’t you lose the TC-01? There aren’t any other tatung einsteins
  { oldName : "Texas Instruments", newName : "Texas instruments TI-99"}, //yeah that flies in the face of what I just said, but you try changing the company of just this system and leaving the other texas insturments calculators etc with the company name still….
  { oldName : "Video Technology Creativision", newName : "Video Technology CreatiVision"},
  { oldName : "Bally Professinal Arcade", newName : "Bally Professional Arcade"}

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
//const dats = {
//
//  files: [
//    `${rootDir}/data/**/*.dat`,
//    `${rootDir}/dats/favs.dat`,
//    `${rootDir}/search/*.tmp`
//  ],
//
//  from: [
//    //since there are only emulators mentioned in a romdata.dat, no systems, we only need to change these:
//    new RegExp(String.raw`\¬(MESS.*)${oldName}`, `g`),
//    new RegExp(String.raw`\¬(RetroArch.*)${oldName}`, `g`)
//  ],
//
//  to: `\¬$1${newName}`,
//
//  encoding: `latin1` //the less-than character's code point in win-1252 isnt happy as utf8
//}
//
///*
// * Replace in the plain text systems list
// */
//const systemsDat = {
//
//  files: `${rootDir}/dats/systems.dat`,
//  
//  from: new RegExp(String.raw`(.*)${oldName}`, `g`),
//  
//  to: `$1${newName}`
//}
//

const transform = (options) => {

  try {
    let changedFiles = replace.sync(options)
    console.log(`replaced content in ${options.files}` )
  }
  catch (error) {
    console.error(`Error occurred:`, error)
  }

}

R.map(transform(iniFiles({oldName, newName}), changesToMake ))
//transform(iniFiles)
//transform(dats)
//transform(systemsDat)
