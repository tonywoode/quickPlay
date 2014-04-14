MESS MAGICIAN BY TEMPEST AKA Matt McLemore 2012
Concept and Testing by Butter100fly

This text but much more readable here with some setup shots: http://www.quickplayfrontend.com/index.php?showtopic=460


What's this about?
This Is about MESS' SOFTLISTS working with QuickPlay - these were introduced not long ago and the idea is that the MESS team collect ROMS and publish lists of them, and if you call MESS, the right system, and the romname, then it will simply load and you play it. Very much the spirit of QuickPlay!

Learn about softists here (mamedev.emulab.it/etabeta/?p=188)

Why is this better than Goodmerge?
Its not really, but its based on the Good sets and the main reason for wanting it is it covers all sorts of odd and obscure systems Cowering has never covered - its really for those of you who like playing and collecting nonsense games from all types of systems - your number of systems in QP can go up by a huge number if you set this up, and mostly its one click and you're playing

But why QP, why now?
Well, the progretto snaps guys started publishing assets for the SOFTLISTS (www.progettosnaps.net/mess/softwaresnaps.html) so suddenly we have our screenshots AND our games which play in one click, so its very useful for what we want to accomplish in QuickPlay. Also you will find it difficult to find another easy frontend to do this on.


How do I use this?
I was hoping you'd ask that. There are two parts to this. Firstly we need to make QuickPlay's INDIVIDUAL romdata files for these systems by setting the roms up as we would any system in Quickplay, AND we need the MESS softlist XML's for those roms (you can use MESS to make these individually by calling the system and then -listsoftware (see here (www.emulab.it/forum/index.php?topic=300.0) ) or you can make one massive xml file from MESS for all systems, but then each lookup will take ages so you better have a nice pc! Alternatively you can create them individually from here (www.progettoemma.net/mess/) -  or far more easily the XML's  always get posted with any SOFTLIST roms. Included are the softlist xml's for MESS 0.144 (but that's just an example - you want the ones from YOUR set)

What the XML's will do is allow MESS MAGICIAN to populate our favourite fields in each romdata you've made: game name/year/company/comments etc with the data from the softlists. THEN we run the right hand bit: the 'Fix Parameters'. What this does is add and overwrite the 'command to run' for each game within the QuickPlay ROMdata you're doing so that it calls MESS directly with the name of the game for the system ie: it tells MESS to run "Boulderdash" for the "ColecoVision" just as if MESS were MAME (which it kind of is). What I mean is that its quite different from the way we usually run things in QP - instead of calling a file path to an emulator we call a "MAMENAME" as if this were an arcade set. (We do this because a very few MESS systems seem to need this for the games to run ok. Not sure why: most of them you can just call - emulator filepath as normal - but if you want everything down to the very last computer game to work use this).

You then make things look nice: link each system up the Progretto guys' snaps, use MESS' ICONs for the systems (you'll have to copy these into QP's ICONS folder for now) and MESS' System Shots and there you have it: easy gaming heaven just like we do for the goodmerge sets....even for many of the computer systems, MESS works out how to autostart...and it will only get better over time

OK, but TECHNICALLY, how do I use this?
1) Have MESS installed. Have some SOFTLIST roms. Have the SOFTLIST XML's for those Roms, have the Progretto assets packs for MESS softlists (www.progettosnaps.net/mess/softwaresnaps.html), have MESS System Shots and ICONS (the assets are optional but highly recommended)
2) Have the latest QP, and the latest EFIND (currently 1.4 from the EFIND download section here). Run it. Find MESS emulators, so many MESS emulators.
3) Setup individual MESS SOFTLIST systems (I make a new folder for these in QP, so in Atari 2600 I have a main folder with goodmerge roms in, and then make a folder under this called 'softlist'. But its up to you
[attachment=330:example.PNG]
4) Find the softlist roms as you always do: find the roms in QP and assign them to an emulator so you have some roms in the roms window and this creates a ROMdata.dat in your corresponding QuickPlay data folder in windows eg: "C:\\Windows\Emulators\QuickPlay\data\atari2600\Softlist\ROMdata.dat"
5) Quit out of QP. Run up MESS MAGICIAN. Point to that ROMDATA file, point to the 2600 Softlist XML, lastly point to your emulators.ini (its in QP's dats folder)
6) Leave the default settings on MESS MAGICIAN as they are, hit the left button to do the ROMDATA renaming. Hit ok. Then hit the right button to include the CALL stuff in the romdata. First time you run the right hand it takes a few seconds to scan your emulators.ini. Be patient. The right hand side can be run at any point you like really, but at first you just want to run both to setup your softlist romdata. Any problems your old ROMdata has just been renamed and is still in the folder with the new one.
7) You're done, make sure you have those nice assets - move the MESS system icon's into your QP ICONs folder, link to the MESS system shots, link to the Progretto SOFTLIST game pictures in QP's Media Panel for each system (go to the system - click on screenshots, click on 'images/thumbnails' and find the images for 2600 (for this bit it kind of helps if you have a list of which MESS name equals which system, but it also easy to just load MESS and 'select new system' and type in the system name - it tells you which system name corresponds to which, mostly its obvious though eg: '2600') - I keep the progretto screenshots in their subfolders in MESS' snaps folder
8) Move onto the next system

WHAT? Does that mean I have to run the tool on each folder in turn? There are loads of SOFTLISTS?
Do you want every game ever or what? Yeah, you have to. Will only take an hour or so. Jesus we had to make all this from nothing! and John's dead we couldn't exactly ask him to help! Tempest had to code all this from scratch, with his bear hands..... :rolleyes:

Anything else to think about?
The idea is you use MESS emulators to run these games. You can use another emulator tho of course, but then don't run 'FIX PARAMETERS' else QP wil run that emu with the MESS call....really these are MESS softlists that have been made for you to run these games with MESS (which is quite a unique experience like when you have the bezels turned on)

There are some subtle things. For instance if you have a system like Atari 2600 that has PAL and NTSC roms, you should set the right PAL or NTSC MESS emulator for the rom (do the renaming of the rom entry first to actually see which ones are PAL and which NTSC) then filter in QP by (PAL) and you can then change the MESS emulator to the right version for the results and then quit and run 'Fix Parameters' on the romdata again (remember to close QP first, actually you probably need to close Mess magician and open again too) and then QP will launch the right emulator for each individal PAL or NTSC rom. That's quite cool, there are a couple of sytems that hugely benefit from this....doesn't hurt to run this tool on a ROMdata its already been run on btw...

Some of the SOFTLISTS for some systems are not games, they are entirely applications and not much fun - so you might want to take a look at what you're going to get before you go to the trouble of setting things up for an individual system

You CAN have romdatas with more than one system in, just make sure you run it through MESS MAGICIAN each time for each systems' XML and that you are calling the correct emulator for each game BEFORE choosing to "Fix Parameters". Prob easiest to setup multiple romdatas for those systems that have CART and DISK and CASSETTE roms and then drag the roms into one romdata when you're done.

Japanese characters are a problem for about 4 of the systems' game names. If you're Japanese this might not be the solution for you

Lastly remember to hit Tempest's like button when you use this and see how cool it is!