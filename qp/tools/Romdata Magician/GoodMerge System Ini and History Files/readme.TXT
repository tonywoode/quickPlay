[size="5"]GOODMERGE SETS SYSTEM INI FILES, HISTORY FILES AND ROMDATA MAGICIAN[/size]
[attachment=288:INI_AND_HISTORY_n64.png][attachment=289:INI_AND_HISTORY_Genesis.png][attachment=290:INI_AND_HISTORY_C64.png][attachment=291:INI_AND_HISTORY_nes.png][attachment=292:INI_AND_HISTORY_genesis2.png]
by Tempest and Butter100fly

[b]What ON EARTH is this?[/b]
This is the Goodmerge branch of Tempest's larger system INI project running at over at EmuMovies [url="http://emumovies.com/forums/index.php?/topic/3489-system-ini-files-project/"]here[/url]

We're very excited about it

These files are for almost every GoodMerge set - both computer and console systems. The idea is that when you've set the goodmerge set up in QuickPlay for a system (just as you would normally do), you can then use Romdata Magician and the files to
* Fill in game details in QuickPlay - so that's all the fields in QuickPlay's rom window - Company, Year, Game Type, Number of Players, Language, Comment
* Show a description for each game in your media tab - it looks at lot like MAMEUI's history

and you can do this quickly and easily. You can then obvioulsy filter by any of the fields and so on - want to play all WonderSwan games you have from 1999? There you go....

These files should superceed any of the previous romdata files in the ROMDATA section for console and computer GoodMerge sets - because we've used them to make this

[b]So this is just for the GoodMerge sets?[/b]
Yes that's the whole point. QuickPlay was built for the goodmerge sets so we're posting the Goodmerge ini files here. I recently posted updated GoodMerge screenshosts here also - the end result of this is you have GoodMerge roms is that QuickPlay functions a lot like MAMEUI does, but for GoodMerge.

And the same applies with the ini files as for the screenshots - its important to use the LATEST Goodsets and to have the LATEST GoodMerge sets (with the latest XMDB's) - the names of the sections in the ini match the latest goodsets as of October 2011

[b]Will it work with any other sets?[/b]
You can use Romdata Magician for other of Tempest's ini files too (go see over at Emumovies) but this all works by matching the name of ROMS to sections of the files, so your mileage may vary. Similarly if you use these with Un-merged Goodsets you'll find similar - these files are made predominantly for the GoodMERGE sets - both computer and console systems, and work very well

[b]How do I use these?[/b]
[attachment=293:Romdata Magician.png]
When you've uncompressed the files, you'll see inside each system folder ther is 
* an ini file - Romdata Magician is going to use these on your QuickPlay romdata files, and
* a history file: you are going to point QuickPlay's media panel to these, a system at a time

When you've unpacked RomData magicican you'll see it has an ini file and a readme. Please read the readme and in particular make sure you set the QP and Ini file paths BEFORE opening RomData magicican for the first time. Then its just a case of creating each Romdata.dat file in the right place which RomData Magician automatically takes care of for you

Next you point QuickPlay to the history files for each system. Note these have to be called history.dat. You do this by going into Tools > Media Panel Options > Path Configuration Tab and then ticking that you want 
a MAME History tab for your system, then browsing for the folder with the correct history.dat in. Like this:
[attachment=294:History_Setup.PNG]


[b]What else to think about?[/b]
* For completeness it would be good if you can replace the language and type files in QP's DATS folder with the ones I've included here - its not too necessary but it does ensure that the dropdown boxes in quickplay match the ones we've set for this project - its fair to say I had a 'long hard think' about type/genre for console/computer and arcade sets and I reckon my categories make a good standard

* we still have a problem to solve in QuickPlay for the history/descriptions to work properly - currently anything with a comma in the game name isn't going to be able to show its description. WE NEED A DELPHI PROGRAMMER TO HELP US CARRY ON THE QUICKPLAY PROJECT

* Tempest has also made an Ini File Editor prog (IFE) to make it easy to help to complete the Ini files - so its easy and you don't have to do it by hand - please contact him about this

* The 'source' files in each folder are for information for those who want to help us out with this project - they show which good/xmdb/have/miss files that were used to create the ini names. you don't need them in order to make the ini's