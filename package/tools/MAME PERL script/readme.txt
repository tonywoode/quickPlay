QP_MAME_ROMDATA_EXTRAS-V1.0 - PERL SCRIPT BY ORFAX - README BY BUTTER100FLY


***This is not a GUI-based tool - you have to do some work*******
*******************This just opens this readme*********************
***Look in QP's TOOLS folder in the "MAME PERL Script" folder*******

-----CLOSE THIS WINDOW TO CONTINUE BACK TO QP--------



The below text can currently be found in much MUCH nicer format with all the pics in the right places at:

http://www.quickplayfrontend.com/index.php?showtopic=48


So please go there and follow instructions for setting up MAME in QuickPlay


______________________________________________________________________

[updated march 2011]
MAME has got to be the trickiest thing to setup in QuickPlay if you want to do it 'properly' - so I've threatened for a long time to do a walkthrough. I also wanted to post up-to-date tools. Here's both together, so this guide is for using Qrfax's script with all the correct things done in the right order to make everything work (if you're using his or my romdatas then you can pretty much skip stages 3 to 6). We want everything in QP to be easy, and most things are, but in the case of MAME I think this full guide is necessary

So, I installed activperl from HERE (www.activestate.com/activeperl/downloads) and followed Orfax's (orfax.awardspace.com/?page_id=64) method for creating my own MAME database. All worked great. You need to install ActivePerl to run Orfax's script (its about 60 meg and there really is nothing to do except install - just accept any defaults and leave it sitting there or you can uninstall it after doing this if you want). If you want the CHD's to work they must be in correctly named folders in your Mame Roms directory ie: make sure you've datted your set properly in CLRMAMEpro. Basically MAMEUI has to know where everything is and work before you do this, becuase all QP does is pass the MAME name to MAME/MAMEUI (QP calls this %ROMMAME% an example is: 1941)

I've posted my full ROMDATA here, but its for MAME 0.138 - there are more recent ones at Orfax's site. Having said that there don't seem to have been many working games added or renaming binges that have gone on in MAME since this

Find also posted here a number of things in MAME Extras v1 - namely:
1) Quickplay Mame Romdata Script - these are two versions Orfax made for his script - one spits out ALL roms from the MAME XML whether you have them in your ROMset or not, the other only spits out ones that you have. Go for all if you're unsure which to run, then the output will be just like looking at 'all' in MAMEUI. Once again: You need to install perl to run orfax's script - full instructions written by Orfax are with the script here
2) MAMU ICON's clone script - many clone ROMs in MAME haven't yet been icon-ed (did I just invent a word?) by MAMU_ yet - so I just used the very latest MAME XML and MAMU's (141 and 140u1) latest set to make this missing copy list. Just download and extract his ICON's (icons.mameworld.info/) and then run the script in the main extracted folder
3) EMPTY ROMS - one problem with using MAME in many frontends with a split-merged set is that a few games don't have their own physical files - the files needed are all in other sets. So before you scan your ROMs folder for Orfax's script, if you put the empty ROMs folder in your ROMS folder - the QP search will find everything. If you're not generating your own perl output then I guess you may need to find and point file locations to these in the QP romdata if you really want them (ten mins I guess - this isn't strictly necessary there aren't many of them)

And here is a pic list of instructions to doing this yourself - and my end result which I'm very happy with...
Feel free to ask questions if you're stuck on any of this (but can you make that post in the HELP section of the forum rather than in this downloads section please)
[attachment=212:1_E-FIND_MAME.png]
Use the latest EFind posted in the Efind download section. To install it just overwrite the EFind folder in the QP folder, also overwrite system.ini in the Dats folder. Make sure the Efind is looking in the right location for MAME, tick any MAME or MAMEUI exe's it finds and select to add the emulator(s) to QP (select overwrite if you want to nuke all your QP emulators and find them again (I just tick everything and do this every time personally- if you're worried I can confirm QP doesn't use windows registry at all so just copy the entire QP folder before you start changing emu's and use the alternaive if something goes wrong, or copy it back where it was - its tiny...(thanks Delphi)
[attachment=213:2_MAKE_FOLDER1.png]
In order to get MAME roms in the ROMS window you first need a QP 'folder' for MAME. You can right click in the left pane or do it from the menu
[attachment=214:2_MAKE_FOLDER2.png]
Great you have a folder for mame. If you're going to just use the ROMdata posted here or the one from Orfax's site then just put that file in eg: C:\EMU\Quickplay\data\mame (this is the windows location of the folder you've just setup) and skip to step 7. If you want to make the romdata yourself, your new folder means you can right click in the roms pane and 'scan for ROMs' -but first:
[attachment=215:3_PUT_EMPTY_ROMS_IN_MAME_FOLDER.png]
as described above if you want these 80-90 clone games then stick the empty roms folder in with yourr MAME roms
[attachment=216:4_SCAN_ROMS_DIR_WITH_SUBFOLDERS_AND_CHD.png]
Scan for ROMS in the ROMS pane - set it up like this (I'm not sure if the CHD bit is totally necessary actually, but it didn't hurt)..you'll then see a whole load of ROMS in the roms pane, but they are called after the filename. Ignore it for now.
[attachment=226:7_Copy_hitsory_and_info_from_MAME_folder__get_catver_and_nplayers_from_net.png]
see the two files catver.ini and nplayers.ini here? They are two easily findable MAME support files from the NET - HERE (catlist.mameworld.info/) and HERE (nplayers.arcadebelgium.be/) - get the latest and put them in this location in the QP folder (there are two versions of nplayers - you want the non 32 one I think ie: not for MAMEUI). Then select 'scan current folder with catver.ini' and 'scan current folder with nplayers.ini' from the Arcade menu in QP - this will fill in version and player info in the ROMDATA (you'll see them appear for games in the roms window there). It's important to do this now because Orfax's script wants this info to make a full set of info for each game (If you're going to use a pre-made ROMdata file like I've posted here you can ignore all this, its already in there)
[attachment=217:5_MAKE_MAME_XML.png]
Ok so here QP 'breaks' a bit (hello does anyone know Delphi?) so we have to make this outside QP as it needs updating - don't bother with QP's 'rename MAME ROMS' menu item - it doesn't work properly atm. This is why you need activePerl. Just exit QP and go to the folder you just setup (its in QP's data folder so C:\EMUS\QP\DATA\MAME) and copy out the romdata.dat -copy it to a new folder and get Orfax script in there
Quick tip for Windows 7 - if you 're in a folder and you want to run command line window from there, hold shift when no file is selected and right click: one of the options is 'open command line here' - do it and type that in (replace the MAME.exe text with whatever your MAME.exe is called). The file will be produced - put that in the folder with Orfax's script and Romdata  
[attachment=218:5_RUN_PERL_SCRIPT.png]
rename the ROMDATA file asin the screen and then run the perl script like this (you did install ActivePerl right?)
[attachment=219:6_PUT_ROMDATA_BACK_IN_FOLDER.png]
The script creates ROMdat.dat - put that back in the QP MAME folder you setup.Now you have ROMS and ROM info
[attachment=248:7_link_to_history_and_info.png]
QP needs history.dat and mameinfo.dat usually in MAMEUI's main directory, or available via here (www.arcade-history.com/) and here (www.mameworld.info/mameinfo/)  so link to the folder containg them in the arcade section in Media Panel - now you can get the MAME text. (note these have to be unzipped at the minute - we are looking at getting the zip support working for these files). Also you may wish to use Tempest's 'Fit History to Tab' on copies of these two files to transform them into versions that fit your QP Media Panel window - get it from HERE (www.quickplayfrontend.com/index.php?showtopic=242&view=findpost&p=1075) and point it to history.dat and mameinfo.dat in turn
[attachment=220:7_ADD_MEDIA.png]
To start seeing the extra stuff you need to go into the QP media panel and start pointing to things in the 'arcade' section
[attachment=221:8_RUN_SCRIPT_IN_MAMU_ICONS_DIR.png]
as decribed above and with the script. Run this to copy Parent rom names as clone rom names in these great icons
[attachment=222:9_ADD_ICONS_PATH_IN_FOLDER_OPTIONS.png]
Although in QP you setup the majority of extras in the media panel, ICONS are a per-folder thing - so you need to tick that box in the last tab of folder options (right click on the folder to get the folder options) and point to where the ICONS are
[attachment=223:10_FINISHED.png]
Now I can search and run games on a tiny low-powered portable netbook almost instantly, without it taking several minutes for MAMEUI to even start (thanks Delphi)....that's good....and now you can setup other Arcade EMU's in minutes that work better for portable machines, with filters and other stuff, and piggy back off all those MAME resources when searching for something to play in QuickPlay...go directly back to QuickPlayFrontend's ROMDATA downloads section (www.quickplayfrontend.com/index.php?showforum=16)....I like FBA myself (joypad support aside)...MAME is the daddy of course....