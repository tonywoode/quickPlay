QUICKPLAY MULTI LOADER SCRIPT 	V1.3.1.0 	 butter100fly 2015
************************************************************************
THE README HAS OPENED, PROBABLY BECAUSE YOU HAVEN'T SET THIS TOOL UP
OR CALLED IT PROPERLY. SORRY. CLOSE THIS README TO CONTINUE
*************************************************************************

USAGE: Multiloader ["PATH TO ROM"] ["PATH TO EMU"] ["EMU PARAMETERS" {eg: "-CD"}] ["DIRECT MOUNT" {PASS IMAGE TO EMULATOR INSTEAD OF TO DEAMON TOOLS - 1 is yes, anything else is no}]

MULTILOADER is a loader script for CD and DVD images to use with QuickPlay that can also use Daemon Tools, 7Zip and Winmount to mount and run pretty much any CD/DVD compressed/uncompressed image type in any emulator. It is separate from Quickplay and this is not ideal (Quickplay will soon run the code itself), but it does give a lot of flexibility. We can now even bypass having to uncompress images (if you use Winmount and your image is in .mou format: Using a tool like winmount that can access compressed images is good because it takes ages to decompress a DVD)

Multiloader does this:
	1) Accesses almost all types of CD/DVD image formats, whether or not the image has been compressed as .7z, .zip, .rar, .mou etc
	2) Either
		2.1) Passes the image to Daemon Tools and passes your daemon tools' virtual DVD-drive's letter to the emulator (eg: drive letter  F:\) 
			OR
		2.1) Directly passes the CD/DVD image to the emulator

If you have a CD/DVD-based emulator that isn't found via QuickPlay's existing EFinds, you have to set it up as an emulator from within quickplay yourself.

If you want to decompress images you need 7zip installed
If you want to mount images to pass to an emulator you need the latest Daemon Tools installed
If You want to run compressed images you need Winmount installed

Newb advice: Whenever you load Daemon Tools with an emu, you need daemon tools and the emu you're using to agree which drive to load from - set Daemon to always use the same drive letter and then look in the emu's config for where to set which drive the emu looks to

QUICKPLAY WILL AUTOMATICALLY CONFIGURE THE MULTILOADER FOR MANY EMULATORS WHEN YOU RUN AN EFIND
-----------------------------------------------------------------------------------------------
See the "multiloader" EFind

OR, TO SETUP MANUALLY IN QUICKPLAY
----------------------------------
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

WE ALSO SHOULD TICK ALL THE BOXES FOR COMPRESSION TYPES IN THE EMULATOR SETUP - that's because we WANT Quickplay to pass compressed images to the script, and not try to decompress the image itself (QuickPlay's own decompression features are more useful for goodmerge sets than for compressed disk images)

WHERE DOES MULTILOADER EXTRACT ZIPS TO?
---------------------------------------
You can set this location in the Multiloader.ini - set TEMPDIR=
Then each fileset gets downloaded into a 'shortname' version of its own filename in that folder
If you haven't set a location, the zip will always extract to a shortname folder in the ROM directory

***********************************************
Here are some notes for advanced use:

* remember that 7zip, Deamon tools and Winmount need to be at the default install locations ie: C:\Program Files\Winmount\Winmount.exe - the functions that use the progs won't work unless they are
* some of the more "exotic" game names you might want to select "use short name (8:3) for exe's" in QP and/or call "shortrom" - this just makes the command line shorter as over a certain character limit it will refuse to work or error. This only applies to a very few systems' games
* Includes a compiled autoHK script (forciblyunmount.exe) that gets around a bug with winmount where if you have multiple explorer windows open it pulls up a prompt when you exit the game.
* works with 64-bit default install locations for the apps it uses, or 32-bit default install locations, prefers 64-bit locations
* has an ini file for standalone use where you can state the path to your emulator (just put e.g.: dolphin.exe if your running it from the emulator directory). Then you don't need quickplay - you can just drag an image file onto the script. (good for testing)
* Its just a compiled cmd script with icon and the autohk script added - see the source folder for the full soure code (you don't need this folder)
* Works with .mou compressed images - mounts them with winmount. Winmount is not free, but we can't find anything else that can do what it can do. If you're using it, Winmount needs to always use the same drive letter - I've set this to X:\ - make sure you don't already use drive X:\ for anything on your system before running this. There is a bug in winmount that you just need to solve once: if winmount starts opening the mounted file in explorer on load, you need to tick and then untick again the option in winmount that says 'open mounted file in explorer'
* Remember that the script is invisible - if QuickPlay ever becomes unresponsive its probably that the script is still running, maybe the emu crashed. In task manager you may need close QUICKPLAY MULTILOADER.exe,cmd.exe and even possibly forciblyunmount.exe to get quickplay responsive again (also if you do kill the script before its done winmount gets confused when you next run it because its drive is still mounted)
* Personally I wouldn't be happy converting my images to .mou unless a ) there was a way to do it automatically with logging and b ) there was a way to get them back to uncompressed or zipped again automatically without logging - so I made that too - have a look at 'mou my folders' in the scripts section on the forums
* There is a list in the script of filetypes for it to search in order for the appropriate thing to use - i've added .gcm and .gdi to this list for gamecube and dreamcast - bear in mind daemon tools can't mount these they need to go directly to the emulator. If you come up with any more image filetypes for the script please let me know