QUICKPLAY MULTI LOADER SCRIPT 	V1.2.0.3 	 butter100fly 2012

************************************************************************
THIS README HAS OPENED, PROBABLY BECAUSE YOU HAVEN'T SET THIS TOOL UP YET
YOU NEED TO MANUALLY SET IT UP. SORRY. CLOSE THIS README TO CONTINUE
*************************************************************************

QUICKPLAY MULTILOADER is a loader script for CD and DVD images to use with QuickPlay. It is separate from Quickplay: This is not ideal (quickplay should run the code itself), but it does give a lot of flexibility to the tool. It means you have to set it up as an emulator from within quickplay yourself.

It does this:
	1) Accesses almost all types of CD/DVD image formats, whether or not the image has been compressed as .7z, .zip, .rar, .mou etc
	2) Either:
		2.1) Passes the image to Daemon Tools and passes your daemon tools' virtual DVD-drive's letter to the emulator (eg: drive letter  F:\) 
			OR
		2.1) Directly passes the CD/DVD image to the emulator

This way I reckon we can pass almost any CD/DVD image to almost any emulator. Sometimes we can even bypass having to uncompress the image (if you use Winmount and your image is in .mou format: Using a tool like winmount that can access compressed images is good because it takes ages to decompress a DVD)

YOU NEED AT LEAST THE LATEST DAEMON TOOLS LITE VERSION, AND YOU NEED 7ZIP INSTALLED, if you want to decompress images and open with Daemon Tools.

Newb advice: Whenever you load Daemon Tools with an emu, you need daemon tools and the emu you're using to agree which drive to load from - set Daemon to always use the same drive letter and then look in the emu's config for where to set which drive the emu looks to

We configure the Multiloader from within Quickplay

TO USE FROM QUICKPLAY
---------------------
Imagine I have setup the PC Engine-CD emulator emulator Mednafen and I find that I have zipped .bin and .cue image files for my CD games. I want a way to extract a game, pass it directly to mednafen, and start mednafen, all in one click using Quickplay.

We will setup a new emulator in QuickPlay for the system we wish to load (in this case NEC PC-Engine) like we usually do, but instead of calling the emulator, we will call QUICKPLAY MULTILOADER.exe (the exe is in the tools folder in the Quickplay install folder). That means we probably want to name the emulator "Mednafen PC-Engine CD Multiloader"

PLEASE LOOK AT QPmultiloaderSetup.PNG in Tools/Quickplay Multiloader for an example of how to set the multiloader up. The example is for another PC-Engine CD emulator. Note usage for the command line paramters me need to setup in the Quickplay Emulator setup:

USAGE: "QUICKPLAY MULTILOADER" "PATH TO ROM" ["VALID PATH TO AN EMU"] ["EMU PARAMETERS" {eg: "-CD"}] ["DIRECT MOUNT" {PASS IMAGE TO EMULATOR INSTEAD OF TO DEAMON TOOLS - 1 is yes, anything else is no}]

Please encase all 4 parameters in "quotation marks"

So command line parameters for Mednafen are: "%ROM%" "C:\Emulators\Mednafen\Mednafen.exe" (that's all, we don't need direct mount and there are no options)
But if we needed to pass the image to daemon tools, and if we did need to pass a parameter to the emulator, we would set it up like the screenshot, which shows how to setup Magic Engine for loading from CD instead:"%ROM%" "C:\Emulators\Magic Engine\pce.exe" "-cd" "1" (you would include empty emulator options ie: "" if you need to set direct mount after)

PLEASE NOTE, AS IN THE SCREENSHOT, WE MUST TICK ALL THE BOXES FOR COMPRESSION TYPES IN THE EMULATOR SETUP - that's because we WANT Quickplay to pass the compressed images to the script, and not try to decompress the image itself.

Here are some notes for advanced use:

* remember that 7zip, Deamon tools and Winmount need to be at the default install locations ie: C:\Program Files\Winmount\Winmount.exe - the functions that use the progs won't work unless they are
* some of the more "exotic" game names you might want to select "use short name (8:3) for exe's" in QP or call "shortrom" - this just makes the command line shorter as over a certain character limit it will refuse to work or error. This only applies to a very few systems' games
* Includes a compiled autoHK script (forciblyunmount.exe) that gets around a problem with winmount where if you have multiple explorer windows open it pulls up a prompt when you exit the game.
* works with 64-bit default install locations for the apps it uses, or 32-bit default install locations, prefers 64-bit locations
* has an ini file for standalone use where you can state the path to your emulator (just put e.g.: dolphin.exe if your running it from the emulator directory). Then you don't need quickplay - you can just drag an image file onto the script. (good for testing)
* its just a compiled cmd script with icon and the autohk script added - see the source folder for the full soure code (you don't need this folder)
* Works with .mou compressed images - mounts them with winmount. Winmount is not free, but we can't find anything else that can do what it can do. If you're using it, Winmount needs to always use the same drive letter - I've set this to X:\ - make sure you don't already use drive X:\ for anything on your system before running this. There is a bug in winmount that you just need to solve once: if winmount starts opening the mounted file in explorer on load, you need to tick and then untick again the option in winmount that says 'open mounted file in explorer'
* Remember that the script is invisible - if QuickPlay ever becomes unresponsive its probably that the script is still running, maybe the emu crashed. In task manager you may need close QUICKPLAY MULTILOADER.exe,cmd.exe and even possibly forciblyunmount.exe to get quickplay responsive again (also if you do kill the script before its done winmount gets confused when you next run it because its drive is still mounted)
* Personally I wouldn't be happy converting my images to .mou unless a ) there was a way to do it automatically with logging and b ) there was a way to get them back to uncompressed or zipped again automatically without logging - so I made that too - have a look at 'mou my folders' in the scripts section on the forums
* There is a list in the script of filetypes for it to search in order for the appropriate thing to use - i've added .gcm and .gdi to this list for gamecube and dreamcast - bear in mind daemon tools can't mount these they need to go directly to the emulator. If you come up with any more image filetypes for the script please let me know


One day this will work within QP


