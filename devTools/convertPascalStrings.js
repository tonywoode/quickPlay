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
function decimalToHex(d, minLength) {
  let  hex = Number(d).toString(16)
  minLength =  (
    typeof (minLength) === "undefined" || minLength === null ? 
      minLength = 2 : minLength
  )
  while (hex.length < minLength ) {
    hex = "0" + hex
  }
  return hex.toUpperCase()
}

// first convert the string to hex and end with win-style termination
const
  string = process.argv[2],
  hexxed = string.showAsHex().toUpperCase(),
  terminator = '0D0A',  ///our pascal strings (and their computed length) include a CRLF on the end
  lengthOf0D0A = 2, //when unhexed (length here always means of the string representations)
  hexxedAndReturned = hexxed + terminator

// now we need to convert the string length to hex and pad it to fit a byte
//   so when we compute length here, we're talking about the number of chars the hex takes up
const stringSize = string.length + lengthOf0D0A

let 
  hexnum = decimalToHex(stringSize)

const 
  lengthOfAByte = 8,
  digitsLength = hexnum.toString().length,
  endPaddingNeeded = lengthOfAByte - digitsLength
  while (hexnum.toString().length < lengthOfAByte) { 
    hexnum = hexnum + "0" 
  } 
  
//a pascal string has the length in hex first, followed by the string in hex  
const
  pascalified = hexnum + hexxedAndReturned

  console.log(pascalified)
  return pascalified

