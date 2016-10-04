#!/usr/bin/env node
"use strict"
/* stackoverflow.com/a/33920309 - this is for ascii only, 2-digithexcodes....
 *  pass it a space as delim should you ever need space separated hexwords
 */

String.prototype.hexEncodedelim = function(delim){
  return this.split("").map(function(c){
    return ("0" + c.charCodeAt(0).toString(16)).slice(-2)
  }).join(delim || "")
}

/*
 * stackoverflow/a/57807 - 2's complement means we'll get negative numbers over a certain size
 * need to pad single numerals also
 */
function decimalToHex(d, minLength) {
  var hex = Number(d).toString(16)
  minLength = typeof (minLength) === "undefined" || minLength === null ? minLength = 2 : minLength
  while (hex.length < minLength ) {
    hex = "0" + hex
  }
  return hex
}

const
  fs = require('fs'),
  string = process.argv[2],
  //first convert to hex
  hexxed = string.hexEncodedelim().toUpperCase(),
  //but our pascal strings (and their computed length) include a CRLF on the end
  hexxedAndReturned = hexxed + "0D0A",
  lengthOf0D0A = 2 //when unhexed, that is...

let stringLength = string.length + lengthOf0D0A

const 
  digitsLength = stringLength.toString().length,
  hexnum = decimalToHex(stringLength),
  lengthOfAByte = 8,
  endPaddingNeeded = lengthOfAByte - digitsLength
  console.log("padding needed is " + endPaddingNeeded)
  while (stringLength.toString().length < lengthOfAByte) { stringLength = stringLength + "0" } 
  console.log(stringLength)

  console.log("answer is " + hexxedAndReturned)
  //return hexxed



