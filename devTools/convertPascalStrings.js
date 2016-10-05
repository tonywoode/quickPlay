#!/usr/bin/env node
"use strict"

const fs = require('fs')

/* stackoverflow.com/a/33920309 - this is for ascii only, 2-digithexcodes....
 *  pass it a space as delim should you ever need space separated hexwords
 */

String.prototype.showAsHex = function(delim){
  return this.split("").map(function(c){
    return ("0" + c.charCodeAt(0).toString(16)).slice(-2)
  }).join(delim || "")
}

/*
 * stackoverflow/a/57807 - 2's complement so we'll get negative numbers over a 
 * certain size, but since these are file paths its irrelevant
 * need to pad single numerals also
 */
function ensureNumberHasMinLength(d, minLen) {
  minLen =  (
    typeof (minLen) === "undefined" || minLen === null ? 
      minLen = 2 : minLen
  )
  return (d.length === minLen ? 
      d.toUpperCase() : ensureNumberHasMinLength('0' + d, minLen))
}

/*
 * Equally this wouldn't cope with an absurdly large path
 */
function makeZerosAtEndOfString(str, len) {
  return (str.length === len ? str : makeZerosAtEndOfString(str + '0', len))
}

// main code

// first convert the string to hex and end with win-style termination
const
  string = process.argv[2],
  hexxed = string.showAsHex().toUpperCase(),
  terminator = '0D0A',  ///our pascal strings (and their computed length) include a CRLF on the end
  lengthOf0D0A = 2, //when unhexed (length here means of the string representations)
  hexxedAndReturned = hexxed + terminator,

// then encode the string length as a byte of hex
  stringSize = string.length + lengthOf0D0A,
  hexnum = Number(stringSize).toString(16),
  hexnumTwoDigit = ensureNumberHasMinLength(hexnum),
  lengthOfAByte = 8,
  paddedHexNum = makeZerosAtEndOfString(hexnumTwoDigit, lengthOfAByte),

// a pascal string has the length in hex first, followed by the string in hex  
  pascalified = paddedHexNum + hexxedAndReturned
 
  console.log(pascalified)
  return pascalified

