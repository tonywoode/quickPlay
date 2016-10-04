#!/usr/bin/env node
// stackoverflow.com/a/33920309 - this is for ascii only, 2-digithexcodes....
String.prototype.hexEncodedelim = function(delim){
    return this.split("").map(function(c){
      return ("0" + c.charCodeAt(0).toString(16)).slice(-2)
    }).join(delim || "")
}


const
  fs = require('fs')
  stream = process.argv[2]
  answer = stream.hexEncodedelim()
  console.log("answer is " + answer)
  return answer



