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


const
  fs = require('fs'),
  stream = process.argv[2],
  //first convert to hex
  hexxed = stream.hexEncodedelim().toUpperCase(),
  //then add a CRLF
  hexxedAndReturned = hexxed + "0D0A",
  //next get the number of characters in the string you just made, rem length is a prop not function§
  numChars = hexxedAndReturned.length
  console.log(numChars)

  console.log("answer is " + hexxedAndReturned)
  //return hexxed



