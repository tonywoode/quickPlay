QP_MAME_ROMDATA_EXTRAS-V1.4 - PERL SCRIPT BY ORFAX - README BY BUTTER100FLY


***This is not a GUI-based tool - you have to do some work*******
*******************This just opens this readme*********************
***The script can be found in QP's TOOLS folder in the "MAME PERL Script\QP_MAME_ROMDATA_SCRIPT" folder*******

-----CLOSE THIS WINDOW TO CONTINUE BACK TO QP--------

The below text can be found in much MUCH nicer format with all the pics in the right places at:

http://quickplay.sourceforge.net/wiki/index.php/MAME


So please go there and follow instructions for setting up MAME in QuickPlay. Or follow what's below here looking at the pictures in the Pics folder.

______________________________________________________________________

[updated July 2014]
MAME has got to be the trickiest thing to setup in QuickPlay - so I've threatened for a long time to do a walkthrough. This guide is for using Qrfax's Perl script with all the correct things done in the right order to make everything work (if you're using my pre-made Mame romdata.dat then you can pretty much skip stages 3 to 6). We want everything in QP to be easy, and most things are, but in the case of MAME I think this full guide is necessary

So, I installed activperl from HERE (www.activestate.com/activeperl/downloads) and followed Orfax's (orfax.awardspace.com/?page_id=64) method for creating my own MAME QuickPlay romdata. All worked great, but over time Orfax hasn't updated his script. So I have, doing things like making sure it works with 7zip roms, and it works with a fully merged set. You need to install ActivePerl to run Orfax's script (its about 60 meg and there really is nothing to do except install - just accept any defaults and leave it sitting there or you can uninstall it after doing this if you want). If you want the CHD's to work they must be in correctly named folders in your Mame Roms directory ie: make sure you've datted your set properly in CLRMAMEpro. Basically MAME / MAMEUI has to know where everything is and work before you do this, because all QP does is pass the MAME name to MAME/MAMEUI (QP calls this %ROMMAME% an example is: 1941)

The main script is in the Quickplay_Mame_Romdata_Script folder. Again you NEED to install ActivePerl to run it. The script can EITHER work only on roms you have scanned in your QuickPLay romdata, or it can output everything in the MAME XML you give it. You are given a choice. If you have a FULLY MERGED Mame set you have no choice but to run the latter. Go for all if you're unsure which to run, then the output will be just like looking at 'all' in MAMEUI or similar. 
 - full instructions written by Orfax are with the script - including how to generate the Mame XML. But please also consider that you'll eventually probably want to massage your "all" XML using this method: http://www.quickplayfrontend.com/index.php?showtopic=474&st=0&p=1954&#entry1954

And here is a pic list of instructions to doing this yourself - and my end result which I'm very happy with...
[attachment=212:1_E-FIND_MAME.png]
Make sure you're using the latest available EFind posted in the Efind download section. To install it just overwrite the EFind folder in the QP folder, also overwrite system.ini in the Dats folder. Make sure the Efind is looking in the right location for MAME, tick any MAME or MAMEUI exe's it finds and select to add the emulator(s) to QP (select overwrite if you want to nuke all your QP emulators and find them again (I just tick everything and do this every time personally- if you're worried I can confirm QP doesn't use windows registry at all so just copy the entire QP folder before you start changing emu's and use the alternaive if something goes wrong, or copy it back where it was - its tiny...
[attachment=213:2_MAKE_FOLDER1.png]
In order to get MAME roms in the ROMS window you first need a QP 'folder' for MAME. You can right click in the left pane or do it from the menu
[attachment=214:2_MAKE_FOLDER2.png]
Great you have a folder for mame. If you're going to just use the ROMdata posted here just put that file in eg: C:\EMU\Quickplay\data\mame (this is the windows location of the folder you've just setup) and skip to step 7. If you want to make the romdata yourself, your new folder means you can right click in the roms pane and 'scan for ROMs' -but first:
[attachment=216:4_SCAN_ROMS_DIR_WITH_SUBFOLDERS_AND_CHD.png]
Scan for ROMS in the ROMS pane - set it up like this..you'll then see a whole load of ROMS in the roms pane, but they are called after the filename. Ignore it for now.
[attachment=226:7_Copy_hitsory_and_info_from_MAME_folder__get_catver_and_nplayers_from_net.png]
see the two files catver.ini and nplayers.ini here? They are two easily findable MAME support files from the NET - HERE (catlist.mameworld.info/) and HERE (nplayers.arcadebelgium.be/) - I also recently added support for Mame Languages.ini (from www.progrettosnaps.net/languages/) - get the latest and put them in this location in the QP folder (where there are two versions of these files - you want the non-32 ones i.e.: the ones NOT for Mame itself - so the ones JUST called catver.ini , nplayers.ini and languages.ini). Then select 'scan current folder with catver.ini' and 'scan current folder with nplayers.ini' from the Arcade menu in QP - this will fill in version and player info in the ROMDATA (you'll see them appear for games in the roms window there). It's important to do this now because Orfax's script wants this info to make a full set of info for each game (If you're going to use a pre-made ROMdata file like I've posted here you can ignore all this, its already in there). Then "scan current folder with languages.ini" - this will take a lot longer because the source file is not so simple....be patient.
[attachment=217:5_MAKE_MAME_XML.png]
Ok so here we have the perl script - So QP's 'rename MAME ROMS' menu item just leads you to that script. This is why you need activePerl. Just exit QP and go to the folder you just setup (its in QP's data folder so C:\EMUS\QP\DATA\MAME) and copy out the romdata.dat -copy it to the folder with Orfax's script in it, and follow Orfax's readme to get the Mame.xml in that folder too). Quick tip for Windows 7 - if you 're in a folder and you want to run command line window from there, hold shift when no file is selected and right click: one of the options is 'open command line here' - do it and type that in (replace the MAME.exe text with whatever your MAME.exe is called). The XML file will be produced - put that in the folder with Orfax's script and Romdata, or you can follow the other advice at http://www.quickplayfrontend.com/index.php?showtopic=474&st=0&p=1954&#entry1954 to get useless Roms out of your Mame XML (personally I prefer to do both and have both "full" and "selection" QP folders for Mame, but its up to you.
[attachment=218:5_RUN_PERL_SCRIPT.png]
rename the source ROMDATA file as in the screen and then run the perl script like this (you did install ActivePerl right?)
[attachment=219:6_PUT_ROMDATA_BACK_IN_FOLDER.png]
Depending on which option you chose, the script may have made a subdir in its own folder called empty roms. If you want ALL the games in Mame, or if you have a fully-merged set, please move this folder to your Mame/Roms directory, and begin the scanning process in Quickplay from scratch again to get back to this point. That will give you ALL the games.
[attachment=215:3_PUT_EMPTY_ROMS_IN_MAME_FOLDER.png]
The script creates ROMdat.dat - when you're ready, put that back in the QP MAME folder you setup.Now you have ROMS and ROM info
[attachment=248:7_link_to_history_and_info.png]
QP needs history.dat and mameinfo.dat usually in MAMEUI's main directory, or available via here (www.arcade-history.com/) and here (www.mameworld.info/mameinfo/)  so link to the folder containg them in the arcade section in Media Panel - now you can get the MAME text. (note these have to be unzipped at the minute - we are looking at getting the zip support working for these files).
[attachment=220:7_ADD_MEDIA.png]
To start seeing the extra stuff you need to go into the QP media panel and start pointing to things in the 'arcade' section
[attachment=222:9_ADD_ICONS_PATH_IN_FOLDER_OPTIONS.png]
Although in QP you setup the majority of extras in the media panel, ICONS are a per-folder thing. Get Mamu's Mame Icons - download and extract his ICON's (http://icons.mameworld.info/) and tick that box in the last tab of folder options (right click on the folder to get the folder options) and point to where the ICONS are (I'd recommend extracting his ICONS instead of pointing to the Zip as its a bit faster)
[attachment=223:10_FINISHED.png]
The result is very good - well worth the effort! This WILL work in QuickPlay itself very soon without the need for the Perl script.