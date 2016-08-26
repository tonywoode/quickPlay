QUICKPLAY MULTI LOADER SCRIPT 	V1.4.0.0 	 butter100fly 2016
************************************************************************
THE README HAS OPENED, PROBABLY BECAUSE YOU HAVEN'T SET THIS TOOL UP
OR CALLED IT PROPERLY. SORRY. CLOSE THIS README TO CONTINUE
*************************************************************************

USAGE: Multiloader ["PATH TO ROM"] ["PATH TO EMU"] ["EMU PARAMETERS" {eg: "-CD"}] ["DIRECT MOUNT" {0=ALWAYS TRY TO MOUNT ISO/BIN/CUE IN DAMEON TOOLS, 1=ALWAYS TRY TO PASS ISO/BIN/CUE TO EMU]
 

::-------------------------------------------------------------------------------

MULTILOADER is a loader script for CD and DVD images to use with QuickPlay that can also use Daemon Tools and 7Zip to mount and run pretty much any CD/DVD compressed/uncompressed image type in any emulator. It is separate from Quickplay and this is not ideal

Multiloader does this:
	1) Accesses almost all types of CD/DVD image formats, whether or not the image has been compressed as .7z, .zip, .rar, or proprietary formats such as those used by dolphin or psp emulators
	2) Guesses whether you want to process the file from its current location, or whether you're trying to use a remote image (this bit is convention over configuration: if you tell it to load a symlink we guess you want to move the image locally and use a cache to download the archive locally
	3) Unzips and passes the image to Daemon Tools and passes your daemon tools' virtual DVD-drive's letter to the emu (eg: drive letter  K:\)
			OR
	4) Mounts the zip in dameon tools and passes the BIN/ISO/CUE to the emu

If you want to decompress images you need 7zip installed
If you want to mount images or zips to pass to an emulator, you need the latest Daemon Tools installed

Newb advice: Whenever you load Daemon Tools with an emu, you need daemon tools and the emu you're using to agree which drive to load from - set Daemon to always add the same drive letter every time you boot and then look in the emu's config for where to set which drive the emu looks to

QUICKPLAY WILL AUTOMATICALLY CONFIGURE THE MULTILOADER FOR MANY EMULATORS WHEN YOU RUN AN EFIND
-----------------------------------------------------------------------------------------------
See the "multiloader" EFind. Or, If you have a CD/DVD-based emulator that isn't found via QuickPlay's existing EFinds, you can also set it up as an emulator from within quickplay yourself.

TO SETUP MANUALLY IN QUICKPLAY
----------------------------------
 There are command line parameters you can call when calling the script. You must call them in this order: 
 First "PATH TO ROM"  
 Secondly "EMULATOR EXECUTABLE" 
 Thirdly "OPTIONS TO PASS TO EMULATOR (eg.:-CD)"
 Fourthly "Direct Mount" - 0=TRY TO PASS ISO/BIN/CUE TO DAEMON TOOLS AFTER EXTRACTING, 1=TRY TO PASS ISO/BIN/CUE TO EMULATOR
 Please encase all 4 in "quotation marks" and include empty emulator options ie: "" if you need to set direct mount after

 So in QuickPLay you would call, for example: 
		"%ROM%" "P:\Mednafen\Mednafen.exe"
 (we don't need direct mount and there are no options)
 Or 
		"%ROM%" "P:\Magic Engine\pce.exe" "" "1"
 (we need the "" because we need direct mounting after)
 Actually we can improve that one to pass -cd to Magic Engine:
 		"%ROM%" "P:\Magic Engine\pce.exe" "-cd" "1"
Imagine I have setup the PC-Engine CD emulator emulator Mednafen and I find that I have zipped .bin and .cue image files for my CD games. When I select it in Quickplay, I want a way to extract a game, pass it directly to mednafen, and start mednafen.

We will setup a new emulator in Quickplay for the system we wish to load (say, NEC PC-Engine). That means we probably want to name the emulator "Mednafen PC-Engine Multiloader". We setup the emulator as if we are setting up Mednafen - we provide the path to mednafen.exe.
Then we do this in the Command Line Parameters section:  In the command to run we fill in this:

%Tool:MULTILOADER% "%ROM%" "%EXEPATH%" "-cd"

NOTE THE QUOTATION MARKS. This will 
*launch the Mutliloader tool setup by default in Quickplay
*pass the Rom filepath to it so it can work out what to do with it
*next passing "%EXEPATH%" passes the path you just setup to Mednafen
*and then lastly passing the -cd parameter passes that parameter to Mednafen itself. The script will uncompress your image for you and pass it to Daemon tools. 

If, instead, Mednafen could take the uncompressed image file directly, so we didn't need Daemon Tools to mount it, we would tell Multiloader to 'Directly Mount' with a 1 at the end, like so:

%Tool:MULTILOADER% "%EXEPATH%" "" "1"

Note how we need the "" even with no parameters, and we need the 1 in quote marks also

WE ALSO SHOULD TICK ALL THE BOXES FOR COMPRESSION TYPES IN THE EMULATOR SETUP - that's because we WANT Quickplay to pass compressed images to the script, and not try to decompress the image itself (QuickPlay's own decompression features are for goodmerge sets, this Multiloader is for compressed disk images)

WHERE DOES MULTILOADER EXTRACT ZIPS TO?
---------------------------------------
You can set this location in the Multiloader.ini - set TEMPDIR=
This is recommended if you want to cache remote archives locally
If you haven't set a location, the zip will always extract to a shortname folder in the ROM directory

***********************************************
Here are some notes for advanced use:

* remember that 7zip and Deamon tools need to be at the default install locations ie: C:\Program Files\7zip\7zip.exe - the functions that use the progs won't work unless they are
* some of the more "exotic" game names you might want to select "use short name (8:3) for exe's" in QP and/or call "shortrom" - this just makes the command line shorter as over a certain character limit it will refuse to work or error. This only applies to a very few systems' games
* YOU CAN CHANGE THE BATCH CODE YOURSELF (mostly useful because daemon tools love changing their command line every minor revision) - alter multiolader_imp.bat
* Any problems? In task manager close QUICKPLAY MULTILOADER.exe,cmd.exe to get quickplay responsive again
* There is a list in the script of filetypes for it to search in order for the appropriate thing to use - i've added .gcm and .gdi to this list for gamecube and dreamcast - bear in mind daemon tools can't mount these they need to go directly to the emulator. If you come up with any more image filetypes for the script please let me know