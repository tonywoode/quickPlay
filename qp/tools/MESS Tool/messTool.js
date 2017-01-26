"use strict"

const 
    fs      = require('fs')
  , path      = require('path')
  , XmlStream = require('xml-stream')
  , R         = require('Ramda')
  , stream = fs.createReadStream("inputs/mame.xml")
  , xml      = new XmlStream(stream)

//program flow
mockSystems(function(systems){
  sanitise(systems, function(callback){
    printSystemsToFile(callback)
  })
})


function mockSystems(callback){
  const 
       input = fs.readFileSync("inputs/newsystems.dat")
    ,  systems = JSON.parse(input)
  
  callback(systems,callback)
}

function makeSystems(callback){
  const systems = []
  let prev

  xml.on("updateElement: machine", function(machine) {
    const attr = machine.$.name
    if (machine.softwarelist 
       && attr !== prev 
       && machine.driver.$.emulation === "good"
       && !machine.$.cloneof
    ) {
      const 
          company = machine.manufacturer
        , systemName = machine.description
        , node = {}
      
      node.company = company
      node.system = systemName
      systems.push(node)
      prev = attr
    }
  })

  xml.on("end", function(){
    callback(systems,callback)
  })
}

function sanitise(systems, callback){
 const
    separator = " "
  , numberOfWords = 1

  //general rules
  , l1 = R.map( ( {company, system } ) => ( {company: company.replace(`<unknown>`, ``),system} ), systems)
  , l2 = R.map( ( {company, system } ) => ( {company, system: system.replace(new RegExp(company.split(separator, numberOfWords) + '\\W', "i"), "")} ), l1) //take company from system name if they repeat
  , l3 = R.map( ( {company, system } ) => ( {company: system.match(/MSX1/)? '' : company, system: system.match(/MSX1/)? `MSX1` : system}), l2 )
  , l4 = R.map( ( {company, system } ) => ( {company: system.match(/MSX2/)? '' : company, system: system.match(/MSX2/)? `MSX2` : system}), l3 ) 
  , l5 = R.map( ( {company, system } ) => ( {company, system: system.replace(/(\(.*\)|\(.*\))/, ``)}), l4 ) //now MSX has gone, every bracketed item is unnecessary

  //system specific
  , la = R.map( ( {company, system } ) => ( {company, system: (company.match(`Acorn`) && system.match(/BBC/))? `BBC` : system}), l5 )
  , lb = R.map( ( {company, system } ) => ( {company, system: (company.match(`Acorn`) && system.match(/Electron/))? `Atom` : system}), la )
  , lc = R.map( ( {company, system } ) => ( {company: company.replace(/Amstrad .*/, `Amstrad`), system: (company.match(`Amstrad`) && ( system.match(/(CPC|GX4000)/)) )? `CPC` : system}), lb )
  , ld = R.map( ( {company, system } ) => ( {company: company.replace(/Apple Computer/, `Apple`),system: system.replace(/Macintosh /, ``)}), lc)
  , le = R.map( ( {company, system } ) => ( {company, system: (company.match(`Apple`) && system.match(/II.*/))? `II` : system}), ld)
  , lf = R.map( ( {company, system } ) => ( {company, system: (company.match(`Atari`) && system.match(/(400|^800.*|XE Game System)/))? `400/600/800/1200/XE` : system}), le)
  , lg = R.map( ( {company, system } ) => ( {company: company.replace(`Bally Manufacturing`, `Bally`),system}), lf)
  , lh = R.map( ( {company, system } ) => ( {company, system:  (company.match(`Bandai`) && system.match(`Super Vision 8000`))? `Super Vision` : system}), lg)
  , li = R.map( ( {company, system } ) => ( {company: company.replace(`Bondwell Holding`, ``), system: (company.match(`Bondwell`))? system=`Bondwell` : system}), lh)
  , lj = R.map( ( {company, system } ) => ( {company: company.replace(`Commodore Business Machines`, `Commodore`),system}), li)
  , lk = R.map( ( {company, system } ) => ( {company, system:  (company.match(`Commodore`) && system.match(/B500|P500/))? `500/600/700` : system}),  lj)
  , ll = R.map( ( {company, system } ) => ( {company, system:  (company.match(`Commodore`) && system.match(/PET .*|CBM .*/))? `PET/CBM` : system}),  lk)
  , lm = R.map( ( {company, system } ) => ( {company, system:  (company.match(`Commodore`) && system.match(/64|128/))? `64/128` : system}),  ll)
  , ln = R.map( ( {company, system } ) => ( {company, system:  (company.match(`Commodore`) && system.match(`VIC-10 / Max Machine / UltiMax`))? `Max/Ultimax`: system}),  lm)
  , lo = R.map( ( {company, system } ) => ( {company, system:  (company.match(`EACA`) && system.match(`Colour Genie EG2000`))? `Colour Genie`: system}),  ln)
  , lp = R.map( ( {company, system } ) => ( {company, system:  (company.match(`Elektronika`) && system.match(`BK 0010`))? `BK`: system}),  lo)
  , lq = R.map( ( {company, system } ) => ( {company, system:  (company.match(`Emerson`) && system.match(`Arcadia 2001`))? `Arcadia`: system}),  lp)
  , lr = R.map( ( {company, system } ) => ( {company, system:  (company.match(`Epson`) && system.match(`PX-4`))? `PX`: system}),  lq)
  , ls = R.map( ( {company, system } ) => ( {company: company.replace(`Exidy Inc`, `Exidy`),system}), lr)
  , lt = R.map( ( {company, system } ) => ( {company, system:  (company.match(`Fairchild`) && system.match(`Channel F II`))? `Channel F`: system}),  ls)
  , lu = R.map( ( {company, system } ) => ( {company, system:  (company.match(`Fujitsu`) && system.match(`FM-7`))? `Micro 7`: system}),  lt)
  , lv = R.map( ( {company, system } ) => ( {company: company.replace(`General Consumer Electronics`, `GCE`),system}), lu)
  , lw = R.map( ( {company, system } ) => ( {company: company.replace(`Interton Electronic`, `Interton`), system: (company.match(`Interton`) && system.match(`VC 4000`))? `VC4000` : system}), lv)
  , lx = R.map( ( {company, system } ) => ( {company: company.replace(`Jupiter Cantab`, `Jupiter`),system}), lw)
  , ly = R.map( ( {company, system } ) => ( {company, system: (company.match(`Kyosei`) && system.match(`Kyotronic 85`))? `Kyotronic` : system}), lx)
  , lz = R.map( ( {company, system } ) => ( {company: company.replace(/Luxor/, `problem`),system}), ly)//this one isn't working
  , laa = R.map( ( {company, system } ) => ( {company: company.replace(`Matra & Hachette`, `Tandy Radio Shack`), system: (company.match(`Matra & Hachette`) && system.match(`Alice 32`))? `MC-10` : system}), lz)
  , lab = R.map( ( {company, system } ) => ( {company: company.replace(`Memotech Ltd`, `Memotech`), system: (company.match(`Memotech`) && system.match(`MTX .*`))? `MTX` : system}), laa)
  , lac = R.map( ( {company, system } ) => ( {company, system:  (company.match(`Mikroelektronica`) && system.match(`Pyldin-601`))? `Pyldin`: system}),  la)
  , lad = R.map( ( {company, system } ) => ( {company: company.replace(`Nascom Microcomputers`, ``), system: (company.match(``) && system.match(/^2$/)? `Nascom` : system)}),  lac)
  , lae = R.map( ( {company, system } ) => ( {company, system:  (company.match(`Nintendo`) && system.match(`Entertainment System / Famicom`))? `NES`: system}),  lad)
  , laf = R.map( ( {company, system } ) => ( {company, system:  (company.match(`Nintendo`) && system.match(`Game Boy Color`))? `Game Boy`: system}),  lae)
  , lag = R.map( ( {company, system } ) => ( {company, system:  (company.match(`Nintendo`) && system.match(`Super Entertainment System / Super Famicom `))? `SNES`: system}),  laf)
  , lzz = R.map( ( {company, system } ) => ( {company: company.replace(`Nippon Electronic Company`, `NEC`), system: system.match(`PC Engine`)? `PC Engine\\TurboGrafx-16` : system}), lag)
  , llast = R.uniq(lzz) //so in anything above, we can duplicate to become unique....

  callback(llast)
}

function printSystemsToFile(systems){

  const munge = systems =>  R.pipe(
      R.sortBy(R.prop('company'))
    , R.map(({company, system}) => ((company ==="" || system ==="")? ``:`${company}` + ` `) + `${system}`) //if there's a company name, print it first 
  )(systems)

  const flatSystems = munge(systems)
 
  const compare = (a, b) => a.localeCompare(b)

  const orderedFlatSystems = flatSystems.sort(compare)
  orderedFlatSystems.forEach(function (v){console.log(v)})
  process.exit()
  const opPath = ("outputs/newsystems.dat")
  fs.writeFileSync(opPath, JSON.stringify(systems))
  //output.on('error', function(err) { console.log("couldn't write the file") });
  
  //systems.forEach(function(v) { output.write(v + '\n'); });
  //output.end();
}
